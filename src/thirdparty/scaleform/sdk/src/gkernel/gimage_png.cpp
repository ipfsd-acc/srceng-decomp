// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gimage_png.cpp
// Functions: 114
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gimage_png.h"

//------------------------------------------------------------------------------
// Address: 0x100FA5D0
// Name: png_read_data
// Source: json
//------------------------------------------------------------------------------
void *__thiscall png_read_data(void *png_ptr, int a2, unsigned __int8 *data, void *length)
{
  void *result; // eax

  result = (void *)(*(int (__thiscall **)(_DWORD, unsigned __int8 *, void *))(**(_DWORD **)(a2 + 84) + 40))(
                     a1: *(_DWORD *)(a2 + 84),
                     a2: data,
                     a3: length);
  if ( (int)result < 0 || result != length )
    return (void *)png_error(a1: a2, a2: "Read Error.");
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FA610
// Name: png_error_handler
// Source: json
//------------------------------------------------------------------------------
void __thiscall __noreturn png_error_handler(CMatRenderContextBase *png_ptr, __int128 msg)
{
  unsigned int v2; // edi
  int error_ptr; // eax
  int v4; // esi

  v2 = strlen((const char *)DWORD1(msg));
  error_ptr = png_get_error_ptr(a1: msg);
  v4 = error_ptr;
  if ( v2 >= 0x64 )
  {
    strncpy_s(_Dst: (char *)(error_ptr + 28), _SizeInBytes: 0x64u, _Src: (const char *)DWORD1(msg), _Count: 0x63u);
    *(_BYTE *)(v4 + 127) = 0;
  }
  else
  {
    strcpy_s(_Dst: (char *)(error_ptr + 28), _SizeInBytes: 0x64u, _Src: (const char *)DWORD1(msg));
  }
  longjmp(Buf: (int *__attribute__((__org_typedef(jmp_buf))))msg, Value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100FA680
// Name: GFxPngReadInfo
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFxPngReadInfo(const IRefCounted *result)
{
  const IRefCounted *v3; // ebx
  double dGamma; // [esp+1Ch] [ebp-8h] BYREF

  if ( _setjmp3(a1: result->__vftable, a2: 0) != 0 )
    return 0;
  png_set_sig_bytes(a1: result->__vftable, a2: 8);
  png_read_info(nSize: (unsigned int)result->__vftable, a2: (int)result[1].__vftable);
  v3 = result + 5;
  png_get_IHDR(
    a1: result->__vftable,
    a2: result[1].__vftable,
    a3: &result[2],
    a4: &result[3],
    a5: &result[4],
    a6: &result[5],
    a7: 0,
    a8: 0,
    a9: 0);
  if ( result[4].__vftable == (IRefCounted_vtbl *)16 )
    png_set_strip_16(a1: result->__vftable);
  if ( v3->__vftable == (IRefCounted_vtbl *)3 )
    png_set_palette_to_rgb(a1: result->__vftable);
  if ( (int)result[4].__vftable < 8 )
    png_set_palette_to_rgb(a1: result->__vftable);
  if ( png_get_valid(a1: result->__vftable, a2: result[1].__vftable, a3: 16) != 0 )
    png_set_tRNS_to_alpha(a1: result->__vftable);
  if ( v3->__vftable == nullptr || v3->__vftable == (IRefCounted_vtbl *)4 )
    png_set_gray_to_rgb(a1: result->__vftable);
  if ( png_get_gAMA(a1: result->__vftable, a2: result[1].__vftable, a3: &dGamma) != 0 )
    png_set_gamma(a1: (int)result->__vftable, a2: 2.2, a3: dGamma);
  png_read_update_info(a1: result->__vftable, a2: result[1].__vftable);
  png_get_IHDR(
    a1: result->__vftable,
    a2: result[1].__vftable,
    a3: &result[2],
    a4: &result[3],
    a5: &result[4],
    a6: &result[5],
    a7: 0,
    a8: 0,
    a9: 0);
  result[6].__vftable = (IRefCounted_vtbl *)png_get_rowbytes(a1: result->__vftable, a2: result[1].__vftable);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FA7D0
// Name: GFxPngReadData
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFxPngReadData(char **a1, int a2)
{
  if ( _setjmp3(a1: *a1, a2: 0) != 0 )
    return 0;
  png_read_image(a1: *a1, a2);
  png_read_end(endptr: *a1, a2: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FA820
// Name: public: static class GImage __near * GImage::ReadPng(class GFile __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
static struct GImage *__stdcall GImage::ReadPng(struct GFile *a1, struct GMemoryHeap *a2)
{
  int v2; // ebx
  const char *v3; // eax
  int v4; // eax
  int v5; // eax
  unsigned int v6; // ebx
  GImage *Image; // eax
  GRefCountNTSImpl *v8; // esi
  _DWORD *v9; // edi
  unsigned int v10; // eax
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v13; // [esp-8h] [ebp-1A8h]
  int v14; // [esp+Ch] [ebp-194h] BYREF
  unsigned __int8 *pbImageData; // [esp+10h] [ebp-190h]
  unsigned __int8 context[384]; // [esp+14h] [ebp-18Ch] OVERLAPPED BYREF
  _BYTE v17[8]; // [esp+194h] [ebp-Ch] BYREF

  v2 = 0;
  if ( a1 == nullptr )
    return nullptr;
  if ( !a1->IsValid(this: a1) )
    return nullptr;
  memset(dst: context, value: 0, count: sizeof(context));
  v3 = a1->GetFilePath(this: a1);
  strcpy_s(_Dst: (char *)&context[128], _SizeInBytes: 0x100u, _Src: v3);
  if ( a1->Read(this: a1, a2: v17, a3: 8) != 8 )
    return nullptr;
  if ( png_check_sig(a1: v17, a2: 8) == 0 )
    return nullptr;
  v4 = png_create_read_struct(a1: "1.2.18", a2: context, a3: png_error_handler, a4: 0);
  *(_DWORD *)context = v4;
  if ( v4 == 0 )
    return nullptr;
  *(_DWORD *)&context[4] = png_create_info_struct(a1: v4);
  if ( *(_DWORD *)&context[4] == 0 )
  {
    v13 = nullptr;
LABEL_28:
    png_destroy_read_struct(a1: context, a2: v13, a3: 0);
    return nullptr;
  }
  png_set_read_fn(a1: *(_DWORD *)context, a2: a1, a3: png_read_data);
  if ( GFxPngReadInfo(result: (const IRefCounted *)context) != 0 )
  {
    if ( *(_DWORD *)&context[20] == 2 )
    {
      v5 = 2;
      v2 = 3 * *(_DWORD *)&context[8];
    }
    else if ( *(_DWORD *)&context[20] == 6 )
    {
      v5 = 1;
      v2 = 4 * *(_DWORD *)&context[8];
    }
    else
    {
      v5 = 0;
    }
    if ( *(_DWORD *)&context[24] != 0 )
      v2 = *(_DWORD *)&context[24];
    v6 = (v2 + 3) & 0xFFFFFFFC;
    if ( v5 == 0
      || (Image = GImage::CreateImage(
                    result: (ICachedPerFrameMeshData *)v5,
                    width: *(unsigned int *)&context[8],
                    height: *(unsigned int *)&context[12],
                    a4: (int)a2),
          v8 = Image,
          Image == nullptr) )
    {
      v13 = &context[4];
      goto LABEL_28;
    }
    pbImageData = Image->pData;
    v14 = 2;
    v9 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * *(_DWORD *)&context[12], a3: &v14);
    if ( v9 != nullptr )
    {
      v10 = 0;
      if ( *(_DWORD *)&context[12] != 0 )
      {
        v11 = pbImageData;
        do
        {
          v9[v10++] = v11;
          v11 += v6;
        }
        while ( v10 < *(_DWORD *)&context[12] );
      }
      if ( GFxPngReadData(a1: (char **)context, a2: (int)v9) != 0 )
      {
        png_destroy_read_struct(a1: context, a2: &context[4], a3: 0);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
        ++v8->RefCount;
        GRefCountNTSImpl::Release(this: v8);
        return (struct GImage *)v8;
      }
      png_destroy_read_struct(a1: context, a2: &context[4], a3: 0);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
      GRefCountNTSImpl::Release(this: v8);
    }
    else
    {
      png_destroy_read_struct(a1: context, a2: &context[4], a3: 0);
      GRefCountNTSImpl::Release(this: v8);
    }
  }
  else
  {
    png_destroy_read_struct(a1: context, a2: &context[4], a3: 0);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101BB050
// Name: _png_read_data
// Source: json
//------------------------------------------------------------------------------
int __cdecl png_read_data(int a1)
{
  int (*v1)(void); // eax

  v1 = *(int (**)(void))(a1 + 80);
  if ( v1 != nullptr )
    return v1();
  else
    return png_error(a1, a2: "Call to NULL read function");
}

//------------------------------------------------------------------------------
// Address: 0x101BB070
// Name: _png_default_read_data
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_default_read_data(int a1, void *buffer, unsigned int count)
{
  if ( a1 != 0 && fread(buffer, elementSize: 1u, count, stream: *(_iobuf **)(a1 + 84)) != count )
    png_error(a1, a2: "Read Error");
}

//------------------------------------------------------------------------------
// Address: 0x101BB0B0
// Name: _png_set_read_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_set_read_fn(_DWORD *a1, int a2, int a3)
{
  int result; // eax

  if ( a1 != nullptr )
  {
    a1[21] = a2;
    result = a3;
    if ( a3 != 0 )
      a1[20] = a3;
    else
      a1[20] = png_default_read_data;
    if ( a1[19] != 0 )
    {
      a1[19] = 0;
      png_warning(a1, a2: "It's an error to set both read_data_fn and write_data_fn in the ");
      result = png_warning(a1, a2: "same structure.  Resetting write_data_fn to NULL.");
    }
    a1[83] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BB110
// Name: _png_set_bKGD
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_bKGD(int a1, int a2, int a3)
{
  __int16 v3; // cx

  if ( a1 != 0 && a2 != 0 )
  {
    *(_DWORD *)(a2 + 90) = *(_DWORD *)a3;
    *(_DWORD *)(a2 + 94) = *(_DWORD *)(a3 + 4);
    v3 = *(_WORD *)(a3 + 8);
    *(_DWORD *)(a2 + 8) |= 0x20u;
    *(_WORD *)(a2 + 98) = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB140
// Name: _png_set_cHRM
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_cHRM(
        int a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( a1 != 0 && a2 != 0 )
  {
    if ( a3 < 0.0 || a4 < 0.0 || a5 < 0.0 || a6 < 0.0 || a7 < 0.0 || a8 < 0.0 || a9 < 0.0 || a10 < 0.0 )
    {
      png_warning(a1, a2: "Ignoring attempt to set negative chromaticity value");
    }
    else if ( a3 > 21474.83
           || a4 > 21474.83
           || a5 > 21474.83
           || a6 > 21474.83
           || a7 > 21474.83
           || a8 > 21474.83
           || a9 > 21474.83
           || a10 > 21474.83 )
    {
      png_warning(a1, a2: "Ignoring attempt to set chromaticity value exceeding 21474.83");
    }
    else
    {
      *(float *)(a2 + 128) = a3;
      *(float *)(a2 + 132) = a4;
      *(float *)(a2 + 136) = a5;
      *(float *)(a2 + 140) = a6;
      *(float *)(a2 + 144) = a7;
      *(float *)(a2 + 148) = a8;
      *(float *)(a2 + 152) = a9;
      *(float *)(a2 + 156) = a10;
      *(_DWORD *)(a2 + 256) = (int)(a3 * 100000.0 + 0.5);
      *(_DWORD *)(a2 + 260) = (int)(a4 * 100000.0 + 0.5);
      *(_DWORD *)(a2 + 264) = (int)(a5 * 100000.0 + 0.5);
      *(_DWORD *)(a2 + 268) = (int)(a6 * 100000.0 + 0.5);
      *(_DWORD *)(a2 + 272) = (int)(a7 * 100000.0 + 0.5);
      *(_DWORD *)(a2 + 276) = (int)(a8 * 100000.0 + 0.5);
      *(_DWORD *)(a2 + 280) = (int)(a9 * 100000.0 + 0.5);
      *(_DWORD *)(a2 + 8) |= 4u;
      *(_DWORD *)(a2 + 284) = (int)(100000.0 * a10 + 0.5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB480
// Name: _png_set_cHRM_fixed
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_set_cHRM_fixed(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  double v10; // st7
  double v11; // st5
  double v12; // st4
  double v13; // st3
  double v14; // st2
  double v15; // st1
  double v16; // st6
  int result; // eax
  double v18; // [esp+0h] [ebp-8h]

  if ( a1 != 0 && a2 != 0 )
  {
    if ( a3 < 0 || a4 < 0 || a5 < 0 || a6 < 0 || a7 < 0 || a8 < 0 || a9 < 0 || a10 < 0 )
    {
      return png_warning(a1, a2: "Ignoring attempt to set negative chromaticity value");
    }
    else
    {
      v10 = (double)a3;
      if ( v10 > 2147483647.0 )
        return png_warning(a1, a2: "Ignoring attempt to set chromaticity value exceeding 21474.83");
      v18 = (double)a4;
      if ( v18 > 2147483647.0 )
        return png_warning(a1, a2: "Ignoring attempt to set chromaticity value exceeding 21474.83");
      v11 = (double)a5;
      if ( v11 > 2147483647.0 )
        return png_warning(a1, a2: "Ignoring attempt to set chromaticity value exceeding 21474.83");
      v12 = (double)a6;
      if ( v12 > 2147483647.0 )
        return png_warning(a1, a2: "Ignoring attempt to set chromaticity value exceeding 21474.83");
      v13 = (double)a7;
      if ( v13 > 2147483647.0 )
        return png_warning(a1, a2: "Ignoring attempt to set chromaticity value exceeding 21474.83");
      v14 = (double)a8;
      if ( v14 > 2147483647.0 )
        return png_warning(a1, a2: "Ignoring attempt to set chromaticity value exceeding 21474.83");
      v15 = (double)a9;
      if ( v15 > 2147483647.0 )
        return png_warning(a1, a2: "Ignoring attempt to set chromaticity value exceeding 21474.83");
      v16 = (double)a10;
      if ( v16 > 2147483647.0 )
      {
        return png_warning(a1, a2: "Ignoring attempt to set chromaticity value exceeding 21474.83");
      }
      else
      {
        *(_DWORD *)(a2 + 8) |= 4u;
        *(_DWORD *)(a2 + 256) = a3;
        *(_DWORD *)(a2 + 276) = a8;
        *(_DWORD *)(a2 + 280) = a9;
        *(_DWORD *)(a2 + 260) = a4;
        *(_DWORD *)(a2 + 268) = a6;
        *(_DWORD *)(a2 + 272) = a7;
        *(_DWORD *)(a2 + 264) = a5;
        *(_DWORD *)(a2 + 284) = a10;
        *(float *)(a2 + 128) = v10 / 100000.0;
        *(float *)(a2 + 132) = v18 / 100000.0;
        *(float *)(a2 + 136) = v11 / 100000.0;
        *(float *)(a2 + 140) = v12 / 100000.0;
        *(float *)(a2 + 144) = v13 / 100000.0;
        *(float *)(a2 + 148) = v14 / 100000.0;
        *(float *)(a2 + 152) = v15 / 100000.0;
        *(float *)(a2 + 156) = v16 / 100000.0;
        return a5;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BB670
// Name: _png_set_gAMA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_gAMA(int a1, int a2, double a3)
{
  double v3; // st7

  if ( a1 != 0 && a2 != 0 )
  {
    v3 = a3;
    if ( a3 > 21474.83 )
    {
      png_warning(a1, a2: "Limiting gamma to 21474.83");
      v3 = 21474.83;
    }
    *(float *)(a2 + 40) = v3;
    *(_DWORD *)(a2 + 8) |= 1u;
    *(_DWORD *)(a2 + 252) = (int)(100000.0 * v3 + 0.5);
    if ( 0.0 == v3 )
      png_warning(a1, a2: "Setting gamma=0");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB6F0
// Name: _png_set_gAMA_fixed
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_gAMA_fixed(int a1, int a2, int a3)
{
  int v3; // eax

  if ( a1 != 0 && a2 != 0 )
  {
    v3 = a3;
    if ( a3 < 0 )
    {
      png_warning(a1, a2: "Setting negative gamma to zero");
      v3 = 0;
    }
    *(_DWORD *)(a2 + 8) |= 1u;
    *(_DWORD *)(a2 + 252) = v3;
    *(float *)(a2 + 40) = (double)v3 / 100000.0;
    if ( v3 == 0 )
      png_warning(a1, a2: "Setting gamma=0");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB770
// Name: _png_set_hIST
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_hIST(int a1, int a2, int a3)
{
  unsigned __int16 v3; // ax
  int v4; // eax
  int v5; // eax
  int v6; // eax

  if ( a1 != 0 && a2 != 0 )
  {
    v3 = *(_WORD *)(a2 + 20);
    if ( v3 != 0 && v3 <= 0x100u )
    {
      png_free_data(a1, a2, a3: 8, a4: 0);
      v4 = png_malloc_warn(a1, nSize: 0x200u);
      *(_DWORD *)(a1 + 500) = v4;
      if ( v4 != 0 )
      {
        v5 = 0;
        if ( *(_WORD *)(a2 + 20) != 0 )
        {
          do
          {
            *(_WORD *)(*(_DWORD *)(a1 + 500) + 2 * v5) = *(_WORD *)(a3 + 2 * v5);
            ++v5;
          }
          while ( v5 < *(unsigned __int16 *)(a2 + 20) );
        }
        v6 = *(_DWORD *)(a1 + 500);
        *(_DWORD *)(a2 + 8) |= 0x40u;
        *(_DWORD *)(a2 + 184) |= 8u;
        *(_DWORD *)(a2 + 124) = v6;
      }
      else
      {
        png_warning(a1, a2: "Insufficient memory for hIST chunk data.");
      }
    }
    else
    {
      png_warning(a1, a2: "Invalid palette size, hIST allocation skipped.");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB830
// Name: _png_set_IHDR
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_IHDR(_DWORD *a1, int a2, unsigned int a3, unsigned int a4, int a5, int a6, int a7, int a8, int a9)
{
  unsigned __int8 v9; // al

  if ( a1 == nullptr || a2 == 0 )
    return;
  if ( a3 == 0 || a4 == 0 )
    png_error(a1, a2: "Image width or height is zero in IHDR");
  if ( a3 > a1[152] || a4 > a1[153] )
    png_error(a1, a2: "image size exceeds user limits in IHDR");
  if ( a3 > 0x7FFFFFFF || a4 > 0x7FFFFFFF )
    png_error(a1, a2: "Invalid image size in IHDR");
  if ( a3 > 0x1FFFFF7E )
    png_warning(a1, a2: "Width is too large for libpng to process pixels");
  if ( a5 != 1 && a5 != 2 && a5 != 4 && a5 != 8 && a5 != 16 )
    png_error(a1, a2: "Invalid bit depth in IHDR");
  if ( a6 < 0 || a6 == 1 || a6 == 5 || a6 > 6 )
    png_error(a1, a2: "Invalid color type in IHDR");
  if ( a6 == 3 )
  {
    if ( a5 <= 8 )
      goto LABEL_33;
  }
  else if ( a6 != 2 && a6 != 4 && a6 != 6 || a5 >= 8 )
  {
    goto LABEL_33;
  }
  png_error(a1, a2: "Invalid color type/bit depth combination in IHDR");
LABEL_33:
  if ( a7 >= 2 )
    png_error(a1, a2: "Unknown interlace method in IHDR");
  if ( a8 != 0 )
    png_error(a1, a2: "Unknown compression method in IHDR");
  if ( (a1[26] & 0x1000) != 0 && a1[140] != 0 )
    png_warning(a1, a2: "MNG features are not allowed in a PNG datastream");
  if ( a9 != 0 )
  {
    if ( (a1[140] & 4) == 0 || a9 != 64 || (a1[26] & 0x1000) != 0 || a6 != 2 && a6 != 6 )
      png_error(a1, a2: "Unknown filter method in IHDR");
    if ( (a1[26] & 0x1000) != 0 )
      png_warning(a1, a2: "Invalid filter method in IHDR");
  }
  *(_DWORD *)(a2 + 4) = a4;
  *(_BYTE *)(a2 + 26) = a8;
  *(_BYTE *)(a2 + 27) = a9;
  *(_DWORD *)a2 = a3;
  *(_BYTE *)(a2 + 24) = a5;
  *(_BYTE *)(a2 + 25) = a6;
  *(_BYTE *)(a2 + 28) = a7;
  if ( (_BYTE)a6 == 3 || (a6 & 2) == 0 )
    *(_BYTE *)(a2 + 29) = 1;
  else
    *(_BYTE *)(a2 + 29) = 3;
  if ( (a6 & 4) != 0 )
    ++*(_BYTE *)(a2 + 29);
  v9 = a5 * *(_BYTE *)(a2 + 29);
  *(_BYTE *)(a2 + 30) = v9;
  if ( a3 <= 0x1FFFFF7E )
  {
    if ( v9 < 8u )
      *(_DWORD *)(a2 + 12) = (a3 * v9 + 7) >> 3;
    else
      *(_DWORD *)(a2 + 12) = a3 * (v9 >> 3);
  }
  else
  {
    *(_DWORD *)(a2 + 12) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBA60
// Name: _png_set_oFFs
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_oFFs(int a1, int a2, int a3, int a4, char a5)
{
  if ( a1 != 0 && a2 != 0 )
  {
    *(_DWORD *)(a2 + 8) |= 0x100u;
    *(_DWORD *)(a2 + 100) = a3;
    *(_DWORD *)(a2 + 104) = a4;
    *(_BYTE *)(a2 + 108) = a5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBA90
// Name: _png_set_pCAL
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_pCAL(
        int a1,
        int a2,
        unsigned __int8 *src,
        int a4,
        int a5,
        char a6,
        int a7,
        unsigned __int8 *a8,
        int a9)
{
  unsigned int v9; // kr00_4
  unsigned __int8 *v10; // eax
  unsigned int v11; // kr04_4
  unsigned __int8 *v12; // eax
  int v13; // eax
  int v14; // esi
  unsigned int v15; // kr08_4
  unsigned __int8 **v16; // eax

  if ( a1 != 0 && a2 != 0 )
  {
    v9 = strlen((const char *)src);
    v10 = (unsigned __int8 *)png_malloc_warn(a1, nSize: v9 + 1);
    *(_DWORD *)(a2 + 160) = v10;
    if ( v10 != nullptr )
    {
      memcpy(dst: v10, src, count: v9 + 1);
      *(_DWORD *)(a2 + 164) = a4;
      *(_BYTE *)(a2 + 181) = a7;
      *(_DWORD *)(a2 + 168) = a5;
      *(_BYTE *)(a2 + 180) = a6;
      v11 = strlen((const char *)a8);
      v12 = (unsigned __int8 *)png_malloc_warn(a1, nSize: v11 + 1);
      *(_DWORD *)(a2 + 172) = v12;
      if ( v12 != nullptr )
      {
        memcpy(dst: v12, src: a8, count: v11 + 1);
        v13 = png_malloc_warn(a1, nSize: 4 * a7 + 4);
        *(_DWORD *)(a2 + 176) = v13;
        if ( v13 != 0 )
        {
          v14 = 0;
          *(_DWORD *)(v13 + 4 * a7) = 0;
          if ( a7 <= 0 )
          {
LABEL_12:
            *(_DWORD *)(a2 + 8) |= 0x400u;
            *(_DWORD *)(a2 + 184) |= 0x80u;
          }
          else
          {
            while ( 1 )
            {
              v15 = strlen(*(const char **)(a9 + 4 * v14));
              *(_DWORD *)(*(_DWORD *)(a2 + 176) + 4 * v14) = png_malloc_warn(a1, nSize: v15 + 1);
              v16 = (unsigned __int8 **)(*(_DWORD *)(a2 + 176) + 4 * v14);
              if ( *v16 == nullptr )
                break;
              memcpy(dst: *v16, src: *(unsigned __int8 **)(a9 + 4 * v14++), count: v15 + 1);
              if ( v14 >= a7 )
                goto LABEL_12;
            }
            png_warning(a1, a2: "Insufficient memory for pCAL parameter.");
          }
        }
        else
        {
          png_warning(a1, a2: "Insufficient memory for pCAL params.");
        }
      }
      else
      {
        png_warning(a1, a2: "Insufficient memory for pCAL units.");
      }
    }
    else
    {
      png_warning(a1, a2: "Insufficient memory for pCAL purpose.");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBC30
// Name: _png_set_sCAL
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_sCAL(int a1, int a2, char a3, double a4, double a5)
{
  if ( a1 != 0 && a2 != 0 )
  {
    *(_DWORD *)(a2 + 8) |= 0x4000u;
    *(double *)(a2 + 224) = a4;
    *(_BYTE *)(a2 + 220) = a3;
    *(double *)(a2 + 232) = a5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBC70
// Name: _png_set_pHYs
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_pHYs(int a1, int a2, int a3, int a4, char a5)
{
  if ( a1 != 0 && a2 != 0 )
  {
    *(_DWORD *)(a2 + 8) |= 0x80u;
    *(_DWORD *)(a2 + 112) = a3;
    *(_DWORD *)(a2 + 116) = a4;
    *(_BYTE *)(a2 + 120) = a5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBCA0
// Name: _png_set_PLTE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_PLTE(int a1, int a2, unsigned __int8 *src, unsigned int a4)
{
  unsigned __int8 *v4; // eax

  if ( a1 != 0 && a2 != 0 )
  {
    if ( a4 <= 0x100 )
    {
LABEL_6:
      png_free_data(a1, a2, a3: 4096, a4: 0);
      v4 = (unsigned __int8 *)png_malloc(a1, nSize: 0x300u);
      *(_DWORD *)(a1 + 276) = v4;
      memset(dst: v4, value: 0, count: 0x300u);
      memcpy(dst: *(unsigned __int8 **)(a1 + 276), src, count: 3 * a4);
      *(_DWORD *)(a2 + 16) = *(_DWORD *)(a1 + 276);
      *(_WORD *)(a1 + 280) = a4;
      *(_DWORD *)(a2 + 184) |= 0x1000u;
      *(_DWORD *)(a2 + 8) |= 8u;
      *(_WORD *)(a2 + 20) = a4;
      return;
    }
    if ( *(_BYTE *)(a2 + 25) == 3 )
    {
      png_error(a1, a2: "Invalid palette length");
      goto LABEL_6;
    }
    png_warning(a1, a2: "Invalid palette length");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBD60
// Name: _png_set_sBIT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_sBIT(int a1, int a2, int a3)
{
  char v3; // cl

  if ( a1 != 0 && a2 != 0 )
  {
    *(_DWORD *)(a2 + 68) = *(_DWORD *)a3;
    v3 = *(_BYTE *)(a3 + 4);
    *(_DWORD *)(a2 + 8) |= 2u;
    *(_BYTE *)(a2 + 72) = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBD90
// Name: _png_set_sRGB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __spoils<> png_set_sRGB(int a1, int a2, char a3)
{
  if ( a1 != 0 && a2 != 0 )
  {
    *(_DWORD *)(a2 + 8) |= 0x800u;
    *(_BYTE *)(a2 + 44) = a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBDB0
// Name: _png_set_sRGB_gAMA_and_cHRM
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_sRGB_gAMA_and_cHRM(int a1, int a2, char a3)
{
  if ( a1 != 0 && a2 != 0 )
  {
    png_set_sRGB(a1, a2, a3);
    png_set_gAMA(a1, a2, a3: 0.4545499980449677);
    png_set_gAMA_fixed(a1, a2, a3: 45455);
    png_set_cHRM_fixed(a1, a2, a3: 31270, a4: 32900, a5: 64000, a6: 33000, a7: 30000, a8: 60000, a9: 15000, a10: 6000);
    png_set_cHRM(
      a1,
      a2,
      a3: 0.3127000033855438,
      a4: 0.3289999961853027,
      a5: 0.6399999856948853,
      a6: 0.3300000131130219,
      a7: 0.300000011920929,
      a8: 0.6000000238418579,
      a9: 0.1500000059604645,
      a10: 0.05999999865889549);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBE90
// Name: _png_set_iCCP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_iCCP(int a1, int a2, const char *a3, char a4, unsigned __int8 *src, unsigned int count)
{
  char *v6; // ebp
  unsigned __int8 *v7; // edi

  if ( a1 != 0 && a2 != 0 && a3 != nullptr && src != nullptr )
  {
    v6 = (char *)png_malloc_warn(a1, nSize: strlen(a3) + 1);
    if ( v6 != nullptr )
    {
      strcpy(v6, a3);
      v7 = (unsigned __int8 *)png_malloc_warn(a1, nSize: count);
      if ( v7 != nullptr )
      {
        memcpy(dst: v7, src, count);
        png_free_data(a1, a2, a3: 16, a4: 0);
        *(_DWORD *)(a2 + 184) |= 0x10u;
        *(_DWORD *)(a2 + 8) |= 0x1000u;
        *(_DWORD *)(a2 + 196) = v6;
        *(_DWORD *)(a2 + 204) = count;
        *(_DWORD *)(a2 + 200) = v7;
        *(_BYTE *)(a2 + 208) = a4;
      }
      else
      {
        png_free(a1, pMem: v6);
        png_warning(a1, a2: "Insufficient memory to process iCCP profile.");
      }
    }
    else
    {
      png_warning(a1, a2: "Insufficient memory to process iCCP chunk.");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBF90
// Name: _png_set_text_2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_set_text_2(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // edi
  int v5; // esi
  int v6; // eax
  void *v7; // ebx
  int v8; // eax
  unsigned __int8 *v9; // eax
  int v11; // eax
  const char **v12; // edx
  const char *v13; // eax
  int *v14; // esi
  unsigned int v15; // ebx
  int v16; // ecx
  const char *v17; // edi
  unsigned int v18; // edi
  unsigned __int8 *v19; // eax
  unsigned __int8 *v20; // ebx
  bool v21; // cc
  unsigned __int8 **v22; // [esp+8h] [ebp-8h]
  int v23; // [esp+Ch] [ebp-4h]

  v4 = a1;
  if ( a1 == 0 || a2 == nullptr || a4 == 0 )
    return 0;
  v5 = a2[13];
  v6 = a4 + a2[12];
  if ( v6 > v5 )
  {
    v7 = (void *)a2[14];
    if ( v7 != nullptr )
    {
      v8 = v6 + 8;
      a2[13] = v8;
      v9 = (unsigned __int8 *)png_malloc_warn(a1, nSize: 16 * v8);
      a2[14] = v9;
      if ( v9 == nullptr )
      {
        png_free(a1, pMem: v7);
        return 1;
      }
      memcpy(dst: v9, src: (unsigned __int8 *)v7, count: 16 * v5);
      png_free(a1, pMem: v7);
    }
    else
    {
      a2[13] = a4 + 8;
      a2[12] = 0;
      v11 = png_malloc_warn(a1, nSize: 16 * (a4 + 8));
      a2[14] = v11;
      if ( v11 == 0 )
        return 1;
      a2[46] |= 0x4000u;
    }
  }
  v23 = 0;
  if ( a4 > 0 )
  {
    v12 = (const char **)(a3 + 8);
    v22 = (unsigned __int8 **)(a3 + 8);
    do
    {
      v13 = *(v12 - 1);
      v14 = (int *)(a2[14] + 16 * a2[12]);
      if ( v13 != nullptr )
      {
        v15 = strlen(v13);
        v16 = (int)*(v12 - 2);
        if ( v16 > 0 )
        {
          png_warning(a1: v4, a2: "iTXt chunk not supported.");
        }
        else
        {
          v17 = *v12;
          if ( *v12 != nullptr && *v17 != 0 )
          {
            v18 = strlen(v17);
            *v14 = v16;
          }
          else
          {
            v18 = 0;
            *v14 = -1;
          }
          v19 = (unsigned __int8 *)png_malloc_warn(a1, nSize: v18 + v15 + 4);
          v14[1] = (int)v19;
          if ( v19 == nullptr )
            return 1;
          memcpy(dst: v19, src: *(v22 - 1), count: v15);
          *(_BYTE *)(v15 + v14[1]) = 0;
          v20 = (unsigned __int8 *)(v15 + v14[1] + 1);
          v14[2] = (int)v20;
          if ( v18 != 0 )
            memcpy(dst: v20, src: *v22, count: v18);
          *(_BYTE *)(v18 + v14[2]) = 0;
          v14[3] = v18;
          ++a2[12];
          v4 = a1;
        }
        v12 = (const char **)v22;
      }
      v12 += 4;
      v21 = ++v23 < a4;
      v22 = (unsigned __int8 **)v12;
    }
    while ( v21 );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101BC160
// Name: _png_set_tIME
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_tIME(int a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // ecx

  if ( a1 != 0 && a2 != nullptr && (*(_DWORD *)(a1 + 104) & 0x200) == 0 )
  {
    a2[15] = *a3;
    v3 = a3[1];
    a2[2] |= 0x200u;
    a2[16] = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC190
// Name: _png_set_tRNS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_tRNS(int a1, int a2, unsigned __int8 *src, int count, int a5)
{
  __int16 v5; // bx
  int v6; // eax

  if ( a1 != 0 && a2 != 0 )
  {
    v5 = count;
    if ( src != nullptr )
    {
      png_free_data(a1, a2, a3: 0x2000, a4: 0);
      v6 = png_malloc(a1, nSize: 0x100u);
      *(_DWORD *)(a2 + 76) = v6;
      *(_DWORD *)(a1 + 392) = v6;
      if ( count <= 256 )
        memcpy(dst: *(unsigned __int8 **)(a2 + 76), src, count);
      *(_DWORD *)(a2 + 184) |= 0x2000u;
    }
    if ( a5 != 0 )
    {
      *(_DWORD *)(a2 + 80) = *(_DWORD *)a5;
      *(_DWORD *)(a2 + 84) = *(_DWORD *)(a5 + 4);
      *(_WORD *)(a2 + 88) = *(_WORD *)(a5 + 8);
      if ( count == 0 )
        v5 = 1;
    }
    *(_DWORD *)(a2 + 8) |= 0x10u;
    *(_WORD *)(a2 + 22) = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC230
// Name: _png_set_sPLT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_sPLT(int a1, int a2, int a3, int a4)
{
  int v4; // edi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // esi
  int v7; // ebx
  unsigned __int8 *v9; // edi
  int v10; // eax
  const char *v11; // ecx
  _BYTE *v12; // edx
  char v13; // al
  unsigned __int8 *v14; // eax
  unsigned __int8 v15; // cl
  unsigned __int8 *v16; // [esp+4h] [ebp-4h]

  if ( a1 != 0 && a2 != 0 )
  {
    v4 = a4;
    v5 = (unsigned __int8 *)png_malloc_warn(a1, nSize: 16 * (a4 + *(_DWORD *)(a2 + 216)));
    v6 = v5;
    v16 = v5;
    if ( v5 != nullptr )
    {
      memcpy(dst: v5, src: *(unsigned __int8 **)(a2 + 212), count: 16 * *(_DWORD *)(a2 + 216));
      png_free(a1, pMem: *(void **)(a2 + 212));
      v7 = 0;
      *(_DWORD *)(a2 + 212) = 0;
      if ( a4 > 0 )
      {
        do
        {
          v9 = &v16[16 * v7 + 16 * *(_DWORD *)(a2 + 216)];
          v10 = png_malloc(a1, nSize: *(_DWORD *)a3 + strlen(*(const char **)a3) + 1 - *(_DWORD *)a3);
          *(_DWORD *)v9 = v10;
          v11 = *(const char **)a3;
          v12 = (_BYTE *)v10;
          do
          {
            v13 = *v11;
            *v12++ = *v11++;
          }
          while ( v13 != 0 );
          v14 = (unsigned __int8 *)png_malloc(a1, nSize: 10 * *(_DWORD *)(a3 + 12));
          *((_DWORD *)v9 + 2) = v14;
          memcpy(dst: v14, src: *(unsigned __int8 **)(a3 + 8), count: 10 * *(_DWORD *)(a3 + 12));
          *((_DWORD *)v9 + 3) = *(_DWORD *)(a3 + 12);
          v15 = *(_BYTE *)(a3 + 4);
          ++v7;
          a3 += 16;
          v9[4] = v15;
        }
        while ( v7 < a4 );
        v4 = a4;
        v6 = v16;
      }
      *(_DWORD *)(a2 + 216) += v4;
      *(_DWORD *)(a2 + 8) |= 0x2000u;
      *(_DWORD *)(a2 + 184) |= 0x20u;
      *(_DWORD *)(a2 + 212) = v6;
    }
    else
    {
      png_warning(a1, a2: "No memory for sPLT palettes.");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC380
// Name: _png_set_unknown_chunks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_unknown_chunks(int a1, int a2, int a3, int a4)
{
  int v4; // edi
  unsigned __int8 *v5; // esi
  int v6; // ebp
  unsigned int *v7; // edi
  unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // [esp+4h] [ebp-4h]

  if ( a1 != 0 && a2 != 0 )
  {
    v4 = a4;
    if ( a4 != 0 )
    {
      v5 = (unsigned __int8 *)png_malloc_warn(a1, nSize: 20 * (a4 + *(_DWORD *)(a2 + 192)));
      v10 = v5;
      if ( v5 != nullptr )
      {
        memcpy(dst: v5, src: *(unsigned __int8 **)(a2 + 188), count: 20 * *(_DWORD *)(a2 + 192));
        png_free(a1, pMem: *(void **)(a2 + 188));
        v6 = 0;
        *(_DWORD *)(a2 + 188) = 0;
        if ( a4 > 0 )
        {
          v7 = (unsigned int *)(a3 + 12);
          do
          {
            v8 = &v5[20 * v6 + 20 * *(_DWORD *)(a2 + 192)];
            strncpy(dest: v8, source: (unsigned __int8 *)v7 - 12, count: 5u);
            v9 = (unsigned __int8 *)png_malloc_warn(a1, nSize: *v7);
            *((_DWORD *)v8 + 2) = v9;
            if ( v9 != nullptr )
            {
              memcpy(dst: v9, src: (unsigned __int8 *)*(v7 - 1), count: *v7);
              *((_DWORD *)v8 + 3) = *v7;
              v8[16] = *(_BYTE *)(a1 + 104);
            }
            else
            {
              png_warning(a1, a2: "Out of memory processing unknown chunk.");
            }
            v5 = v10;
            ++v6;
            v7 += 5;
          }
          while ( v6 < a4 );
          v4 = a4;
        }
        *(_DWORD *)(a2 + 192) += v4;
        *(_DWORD *)(a2 + 184) |= 0x200u;
        *(_DWORD *)(a2 + 188) = v5;
      }
      else
      {
        png_warning(a1, a2: "Out of memory while processing unknown chunk.");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC4C0
// Name: _png_create_struct_2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl png_create_struct_2(int a1, int (__cdecl *a2)(char *, unsigned int), int a3)
{
  unsigned int v3; // esi
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // edi
  char v7[576]; // [esp+4h] [ebp-280h] BYREF
  int v8; // [esp+244h] [ebp-40h]

  if ( a1 == 2 )
  {
    v3 = 288;
  }
  else
  {
    if ( a1 != 1 )
      return nullptr;
    v3 = 636;
  }
  if ( a2 != nullptr )
  {
    v8 = a3;
    v4 = (unsigned __int8 *)a2(a1: v7, a2: v3);
  }
  else
  {
    v4 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v3);
  }
  v5 = v4;
  if ( v4 != nullptr )
    memset(dst: v4, value: 0, count: v3);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101BC570
// Name: _png_destroy_struct_2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_destroy_struct_2(void *pMem, void (__cdecl *a2)(_BYTE *, void *), int a3)
{
  _BYTE v3[576]; // [esp+0h] [ebp-280h] BYREF
  int v4; // [esp+240h] [ebp-40h]

  if ( pMem != nullptr )
  {
    if ( a2 != nullptr )
    {
      v4 = a3;
      a2(a1: v3, a2: pMem);
    }
    else
    {
      free(pMem);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC5F0
// Name: _png_malloc_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl png_malloc_default(int a1, unsigned int nSize)
{
  if ( a1 != 0 && nSize != 0 )
    return MemAlloc_Alloc(nSize);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101BC610
// Name: _png_free_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_free_default(int a1, void *pMem)
{
  if ( a1 != 0 && pMem != nullptr )
    free(pMem);
}

//------------------------------------------------------------------------------
// Address: 0x101BC630
// Name: _png_memcpy_check
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_memcpy_check(int a1, unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  memcpy(dst, src, count);
}

//------------------------------------------------------------------------------
// Address: 0x101BC650
// Name: _png_memset_check
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_memset_check(int a1, unsigned __int8 *dst, unsigned __int8 value, unsigned int count)
{
  memset(dst, value, count);
}

//------------------------------------------------------------------------------
// Address: 0x101BC670
// Name: _png_set_mem_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl png_set_mem_fn(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *result; // eax

  result = a1;
  if ( a1 != nullptr )
  {
    a1[144] = a2;
    a1[145] = a3;
    a1[146] = a4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BC6A0
// Name: _png_create_struct
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn png_create_struct(int a1)
{
  png_create_struct_2(a1, a2: nullptr, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101BC6C0
// Name: _png_destroy_struct
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn png_destroy_struct(void *pMem)
{
  png_destroy_struct_2(pMem, a2: nullptr, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101BC6E0
// Name: _png_malloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl png_malloc(int a1, unsigned int nSize)
{
  int (__cdecl *v2)(int, unsigned int); // eax
  void *v3; // eax
  void *v4; // edi

  if ( a1 == 0 || nSize == 0 )
    return nullptr;
  v2 = *(int (__cdecl **)(int, unsigned int))(a1 + 580);
  if ( v2 != nullptr )
    v3 = (void *)v2(a1, a2: nSize);
  else
    v3 = png_malloc_default(a1, nSize);
  v4 = v3;
  if ( v3 == nullptr && (*(_DWORD *)(a1 + 108) & 0x100000) == 0 )
    png_error(a1, a2: "Out of Memory!");
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101BC730
// Name: _png_free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_free(int a1, void *pMem)
{
  void (*v2)(void); // eax

  if ( a1 != 0 && pMem != nullptr )
  {
    v2 = *(void (**)(void))(a1 + 584);
    if ( v2 != nullptr )
      v2();
    else
      png_free_default(a1, pMem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC760
// Name: _png_malloc_warn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl png_malloc_warn(int a1, unsigned int nSize)
{
  void *result; // eax
  int v3; // edi

  if ( a1 == 0 )
    return nullptr;
  v3 = *(_DWORD *)(a1 + 108);
  *(_DWORD *)(a1 + 108) = v3 | 0x100000;
  result = png_malloc(a1, nSize);
  *(_DWORD *)(a1 + 108) = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BC790
// Name: _png_get_uint_32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_get_uint_32(unsigned __int8 *a1)
{
  return a1[3] + ((a1[2] + ((a1[1] + (*a1 << 8)) << 8)) << 8);
}

//------------------------------------------------------------------------------
// Address: 0x101BC7C0
// Name: _png_get_uint_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl png_get_uint_16(unsigned __int8 *a1)
{
  return a1[1] + (*a1 << 8);
}

//------------------------------------------------------------------------------
// Address: 0x101BC7E0
// Name: _png_crc_read
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_crc_read(int a1, int a2, int a3)
{
  int result; // eax

  if ( a1 != 0 )
  {
    png_read_data(a1);
    return png_calculate_crc(a1, a2, a3);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BC810
// Name: _png_crc_error
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl png_crc_error(int a1)
{
  int v1; // edi
  int v2; // esi

  v1 = a1;
  v2 = 1;
  if ( (*(_BYTE *)(a1 + 284) & 0x20) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 108) & 0x300) != 0x300 )
      goto LABEL_6;
  }
  else if ( (*(_DWORD *)(a1 + 108) & 0x800) == 0 )
  {
    goto LABEL_6;
  }
  v2 = 0;
LABEL_6:
  png_read_data(a1);
  return v2 != 0 && png_get_uint_32((unsigned __int8 *)&a1) != *(_DWORD *)(v1 + 272);
}

//------------------------------------------------------------------------------
// Address: 0x101BC880
// Name: _png_decompress_chunk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl png_decompress_chunk(int a1, int a2, char *a3, int a4, unsigned int a5, unsigned int *a6)
{
  int v6; // ecx
  int v7; // eax
  unsigned int v8; // ebp
  unsigned __int8 *v9; // edi
  unsigned int v10; // eax
  int v11; // ecx
  int v12; // edx
  unsigned int v14; // [esp+Ch] [ebp-44h]
  unsigned __int8 *v15; // [esp+10h] [ebp-40h]
  char string[52]; // [esp+18h] [ebp-38h] BYREF

  if ( a2 == 0 )
  {
    v6 = *(_DWORD *)(a1 + 176);
    *(_DWORD *)(a1 + 120) = a4 - a5;
    v7 = *(_DWORD *)(a1 + 172);
    v8 = 0;
    *(_DWORD *)(a1 + 116) = &a3[a5];
    *(_DWORD *)(a1 + 128) = v7;
    *(_DWORD *)(a1 + 132) = v6;
    v9 = nullptr;
    if ( a4 != a5 )
    {
      while ( 1 )
      {
        v10 = inflate(a1: a1 + 116, a2: 1);
        v14 = v10;
        if ( v10 > 1 )
          break;
        v11 = *(_DWORD *)(a1 + 132);
        if ( v11 == 0 || v10 == 1 )
        {
          if ( v9 != nullptr )
          {
            v15 = v9;
            v9 = (unsigned __int8 *)png_malloc_warn(a1, nSize: v8 - v11 + *(_DWORD *)(a1 + 176) + 1);
            if ( v9 == nullptr )
            {
              png_free(a1, pMem: v15);
              png_free(a1, pMem: a3);
              png_error(a1, a2: "Not enough memory to decompress chunk..");
            }
            memcpy(dst: v9, src: v15, count: v8);
            png_free(a1, pMem: v15);
            memcpy(
              dst: &v9[v8],
              src: *(unsigned __int8 **)(a1 + 172),
              count: *(_DWORD *)(a1 + 176) - *(_DWORD *)(a1 + 132));
            v8 += *(_DWORD *)(a1 + 176) - *(_DWORD *)(a1 + 132);
          }
          else
          {
            v8 = *(_DWORD *)(a1 + 176) + a5 - v11;
            v9 = (unsigned __int8 *)png_malloc_warn(a1, nSize: v8 + 1);
            if ( v9 == nullptr )
            {
              png_free(a1, pMem: a3);
              png_error(a1, a2: "Not enough memory to decompress chunk.");
            }
            memcpy(dst: &v9[a5], src: *(unsigned __int8 **)(a1 + 172), count: v8 - a5);
            memcpy(dst: v9, src: (unsigned __int8 *)a3, count: a5);
          }
          v9[v8] = 0;
          if ( v14 == 1 )
            goto LABEL_38;
          v12 = *(_DWORD *)(a1 + 176);
          v10 = v14;
          *(_DWORD *)(a1 + 128) = *(_DWORD *)(a1 + 172);
          *(_DWORD *)(a1 + 132) = v12;
        }
        if ( *(_DWORD *)(a1 + 120) == 0 )
          goto LABEL_27;
      }
      if ( *(_DWORD *)(a1 + 140) != 0 )
        png_warning(a1, a2: *(_DWORD *)(a1 + 140));
      else
        png_warning(a1, a2: "Error decoding compressed text");
      inflateReset(a1: a1 + 116);
      *(_DWORD *)(a1 + 120) = 0;
      if ( v9 == nullptr )
      {
        v8 = a5 + 32;
        v9 = (unsigned __int8 *)png_malloc_warn(a1, nSize: a5 + 32);
        if ( v9 == nullptr )
        {
          png_free(a1, pMem: a3);
          png_error(a1, a2: "Not enough memory to decompress chunk");
        }
        memcpy(dst: v9, src: (unsigned __int8 *)a3, count: a5);
      }
      v9[v8 - 1] = 0;
      v8 = a3 - (char *)v9 + a4 - 1;
      if ( v8 >= 0x1F )
        v8 = 31;
      memcpy(dst: &v9[a5], src: "Error decoding compressed text", count: v8 + 1);
      v10 = v14;
LABEL_27:
      switch ( v10 )
      {
        case 1u:
          goto LABEL_38;
        case 0xFFFFFFFB:
          sprintf(string, format: "Buffer error in compressed datastream in %s chunk", a1 + 284);
LABEL_33:
          png_warning(a1, a2: string);
          v8 = a5;
          if ( v9 == nullptr )
          {
            v9 = (unsigned __int8 *)png_malloc_warn(a1, nSize: a5 + 1);
            if ( v9 == nullptr )
            {
              png_free(a1, pMem: a3);
              png_error(a1, a2: "Not enough memory for text.");
            }
            memcpy(dst: v9, src: (unsigned __int8 *)a3, count: a5);
          }
          v9[a5] = 0;
LABEL_38:
          inflateReset(a1: a1 + 116);
          *(_DWORD *)(a1 + 120) = 0;
          png_free(a1, pMem: a3);
          *a6 = v8;
          return v9;
        case 0xFFFFFFFD:
          sprintf(string, format: "Data error in compressed datastream in %s chunk", a1 + 284);
          goto LABEL_33;
        default:
          break;
      }
    }
    sprintf(string, format: "Incomplete compressed datastream in %s chunk", a1 + 284);
    goto LABEL_33;
  }
  sprintf(string, format: "Unknown zTXt compression type %d", a2);
  png_warning(a1, a2: string);
  a3[a5] = 0;
  *a6 = a5;
  return (unsigned __int8 *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x101BCC10
// Name: _png_check_chunk_name
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl png_check_chunk_name(int a1, unsigned __int8 *a2)
{
  unsigned __int8 v2; // al
  unsigned __int8 v3; // al
  unsigned __int8 v4; // al
  unsigned __int8 result; // al

  v2 = *a2;
  if ( *a2 < 0x41u || v2 > 0x7Au || v2 > 0x5Au && v2 < 0x61u )
    return png_chunk_error(a1, a2: "invalid chunk type");
  v3 = a2[1];
  if ( v3 < 0x41u || v3 > 0x7Au || v3 > 0x5Au && v3 < 0x61u )
    return png_chunk_error(a1, a2: "invalid chunk type");
  v4 = a2[2];
  if ( v4 < 0x41u || v4 > 0x7Au || v4 > 0x5Au && v4 < 0x61u )
    return png_chunk_error(a1, a2: "invalid chunk type");
  result = a2[3];
  if ( result < 0x41u || result > 0x7Au || result > 0x5Au && result < 0x61u )
    return png_chunk_error(a1, a2: "invalid chunk type");
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BCC70
// Name: _png_combine_row
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_combine_row(int a1, unsigned __int8 *dst, int a3)
{
  unsigned __int8 v3; // al
  int v4; // eax
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // ebp
  unsigned int v8; // edi
  unsigned __int8 v9; // bl
  unsigned __int8 *v10; // edi
  int v11; // ebp
  int v12; // edx
  unsigned __int8 *v13; // edi
  int v14; // ebp
  int v15; // edx
  unsigned __int8 *v16; // edi
  int v17; // ebp
  int v18; // edx
  int v19; // [esp+0h] [ebp-10h]
  int v20; // [esp+0h] [ebp-10h]
  int v21; // [esp+0h] [ebp-10h]
  int v22; // [esp+0h] [ebp-10h]
  int v23; // [esp+4h] [ebp-Ch]
  int v24; // [esp+4h] [ebp-Ch]
  int v25; // [esp+4h] [ebp-Ch]
  int v26; // [esp+8h] [ebp-8h]
  int v27; // [esp+8h] [ebp-8h]
  int v28; // [esp+8h] [ebp-8h]
  int v29; // [esp+Ch] [ebp-4h]
  int v30; // [esp+Ch] [ebp-4h]
  int v31; // [esp+Ch] [ebp-4h]

  if ( a3 == 255 )
  {
    v3 = *(_BYTE *)(a1 + 267);
    if ( v3 < 8u )
      v4 = (*(_DWORD *)(a1 + 200) * (unsigned int)v3 + 7) >> 3;
    else
      v4 = *(_DWORD *)(a1 + 200) * (v3 >> 3);
    memcpy(dst, src: (unsigned __int8 *)(*(_DWORD *)(a1 + 236) + 1), count: v4);
  }
  else
  {
    v5 = *(unsigned __int8 *)(a1 + 267);
    v6 = (unsigned __int8 *)(*(_DWORD *)(a1 + 236) + 1);
    switch ( v5 )
    {
      case 1u:
        v16 = dst;
        v22 = 128;
        if ( (*(_DWORD *)(a1 + 112) & 0x10000) != 0 )
        {
          v17 = 0;
          v31 = 7;
          v28 = 1;
        }
        else
        {
          v17 = 7;
          v31 = 0;
          v28 = -1;
        }
        v18 = v17;
        if ( *(_DWORD *)(a1 + 200) != 0 )
        {
          v25 = *(_DWORD *)(a1 + 200);
          do
          {
            if ( (a3 & v22) != 0 )
              *v16 = (((*v6 >> v18) & 1) << v18) | *v16 & (32639 >> (7 - v18));
            if ( v18 == v31 )
            {
              ++v6;
              v18 = v17;
              ++v16;
            }
            else
            {
              v18 += v28;
            }
            if ( v22 == 1 )
              v22 = 128;
            else
              v22 >>= 1;
            --v25;
          }
          while ( v25 != 0 );
        }
        break;
      case 2u:
        v13 = dst;
        v21 = 128;
        if ( (*(_DWORD *)(a1 + 112) & 0x10000) != 0 )
        {
          v14 = 0;
          v30 = 6;
          v27 = 2;
        }
        else
        {
          v14 = 6;
          v30 = 0;
          v27 = -2;
        }
        v15 = v14;
        if ( *(_DWORD *)(a1 + 200) != 0 )
        {
          v24 = *(_DWORD *)(a1 + 200);
          do
          {
            if ( (a3 & v21) != 0 )
              *v13 = (((*v6 >> v15) & 3) << v15) | *v13 & (16191 >> (6 - v15));
            if ( v15 == v30 )
            {
              ++v6;
              v15 = v14;
              ++v13;
            }
            else
            {
              v15 += v27;
            }
            if ( v21 == 1 )
              v21 = 128;
            else
              v21 >>= 1;
            --v24;
          }
          while ( v24 != 0 );
        }
        break;
      case 4u:
        v10 = dst;
        v20 = 128;
        if ( (*(_DWORD *)(a1 + 112) & 0x10000) != 0 )
        {
          v11 = 0;
          v23 = 4;
          v26 = 4;
        }
        else
        {
          v11 = 4;
          v23 = 0;
          v26 = -4;
        }
        v12 = v11;
        if ( *(_DWORD *)(a1 + 200) != 0 )
        {
          v29 = *(_DWORD *)(a1 + 200);
          do
          {
            if ( (a3 & v20) != 0 )
              *v10 = (((*v6 >> v12) & 0xF) << v12) | *v10 & (3855 >> (4 - v12));
            if ( v12 == v23 )
            {
              ++v6;
              v12 = v11;
              ++v10;
            }
            else
            {
              v12 += v26;
            }
            if ( v20 == 1 )
              v20 = 128;
            else
              v20 >>= 1;
            --v29;
          }
          while ( v29 != 0 );
        }
        break;
      default:
        v7 = dst;
        v8 = v5 >> 3;
        v9 = 0x80;
        if ( *(_DWORD *)(a1 + 200) != 0 )
        {
          v19 = *(_DWORD *)(a1 + 200);
          do
          {
            if ( (v9 & (unsigned __int8)a3) != 0 )
              memcpy(dst: v7, src: v6, count: v8);
            v6 += v8;
            v7 += v8;
            if ( v9 == 1 )
              v9 = 0x80;
            else
              v9 >>= 1;
            --v19;
          }
          while ( v19 != 0 );
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BCF70
// Name: _png_do_read_interlace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl png_do_read_interlace(unsigned int a1)
{
  unsigned int result; // eax
  int v2; // ecx
  bool v3; // zf
  int v4; // ecx
  int v5; // ebx
  int v6; // eax
  unsigned int v7; // esi
  int v8; // ebp
  unsigned int v9; // edi
  unsigned int v10; // esi
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // edi
  int j; // ebp
  _BYTE *v14; // edi
  int v15; // edx
  int v16; // esi
  int v17; // ebp
  char v18; // al
  _BYTE *v19; // edi
  int v20; // edx
  int v21; // esi
  char v22; // al
  _BYTE *v23; // edi
  int v24; // edx
  int v25; // esi
  int v26; // ebp
  char v27; // al
  bool v28; // cf
  unsigned __int8 v29; // al
  char v30; // [esp+Bh] [ebp-2Dh]
  char v31; // [esp+Bh] [ebp-2Dh]
  int v32; // [esp+Ch] [ebp-2Ch]
  _BYTE *v33; // [esp+Ch] [ebp-2Ch]
  int v34; // [esp+Ch] [ebp-2Ch]
  unsigned int v35; // [esp+10h] [ebp-28h]
  int v36; // [esp+10h] [ebp-28h]
  unsigned int v37; // [esp+10h] [ebp-28h]
  int v38; // [esp+10h] [ebp-28h]
  _BYTE *v39; // [esp+14h] [ebp-24h]
  int v40; // [esp+14h] [ebp-24h]
  _BYTE *v41; // [esp+14h] [ebp-24h]
  int v42; // [esp+18h] [ebp-20h]
  int v43; // [esp+18h] [ebp-20h]
  int v44; // [esp+18h] [ebp-20h]
  int v45; // [esp+1Ch] [ebp-1Ch]
  int v46; // [esp+1Ch] [ebp-1Ch]
  unsigned int v47; // [esp+20h] [ebp-18h]
  int v48; // [esp+20h] [ebp-18h]
  int i; // [esp+20h] [ebp-18h]
  int *v50; // [esp+24h] [ebp-14h]
  int v51; // [esp+28h] [ebp-10h]
  unsigned __int8 dst[8]; // [esp+2Ch] [ebp-Ch] BYREF

  result = a1;
  v2 = *(_DWORD *)(a1 + 236);
  v3 = v2 == -1;
  v4 = v2 + 1;
  v5 = *(_DWORD *)(a1 + 112);
  v50 = (int *)(a1 + 256);
  if ( v3 || a1 == -256 )
    return result;
  v6 = *(_DWORD *)(a1 + 256);
  v7 = *(unsigned __int8 *)(a1 + 267);
  v8 = png_pass_inc[*(unsigned __int8 *)(a1 + 292)] * v6;
  v51 = png_pass_inc[*(unsigned __int8 *)(a1 + 292)];
  v45 = v8;
  v9 = v8 - 1;
  switch ( v7 )
  {
    case 1u:
      v23 = (_BYTE *)(v4 + (v9 >> 3));
      v41 = (_BYTE *)(v4 + ((unsigned int)(v6 - 1) >> 3));
      if ( (v5 & 0x10000) != 0 )
      {
        v24 = ((_BYTE)v6 - 1) & 7;
        v25 = ((_BYTE)v8 - 1) & 7;
        v44 = 7;
        v26 = 0;
        v38 = -1;
      }
      else
      {
        v24 = 7 - (((_BYTE)v6 - 1) & 7);
        v25 = 7 - (((_BYTE)v8 - 1) & 7);
        v44 = 0;
        v26 = 7;
        v38 = 1;
      }
      v34 = v24;
      *(_DWORD *)dst = 0;
      if ( v6 != 0 )
      {
        do
        {
          v27 = (*v41 >> v24) & 1;
          if ( v51 > 0 )
          {
            for ( i = v51; i != 0; --i )
            {
              *v23 = (v27 << v25) | *v23 & (32639 >> (7 - v25));
              if ( v25 == v26 )
              {
                v25 = v44;
                --v23;
              }
              else
              {
                v25 += v38;
              }
            }
            v24 = v34;
          }
          if ( v24 == v26 )
          {
            v24 = v44;
            --v41;
          }
          else
          {
            v24 += v38;
          }
          v28 = *(_DWORD *)dst + 1 < (unsigned int)*v50;
          v34 = v24;
          ++*(_DWORD *)dst;
        }
        while ( v28 );
      }
      break;
    case 2u:
      v19 = (_BYTE *)(v4 + (v9 >> 2));
      v33 = (_BYTE *)(v4 + ((unsigned int)(v6 - 1) >> 2));
      if ( (v5 & 0x10000) != 0 )
      {
        v20 = (2 * (_BYTE)v6 - 1) & 6;
        v21 = (2 * (_BYTE)v8 - 1) & 6;
        v40 = 6;
        v43 = 0;
        v46 = -2;
      }
      else
      {
        v20 = 2 * (3 - (((_BYTE)v6 - 1) & 3));
        v21 = 2 * (3 - (((_BYTE)v8 - 1) & 3));
        v40 = 0;
        v43 = 6;
        v46 = 2;
      }
      v37 = 0;
      if ( v6 != 0 )
      {
        do
        {
          v22 = (*v33 >> v20) & 3;
          v31 = v22;
          if ( v51 > 0 )
          {
            v48 = v51;
            while ( 1 )
            {
              *v19 = (v22 << v21) | *v19 & (16191 >> (6 - v21));
              if ( v21 == v43 )
              {
                v21 = v40;
                --v19;
              }
              else
              {
                v21 += v46;
              }
              if ( --v48 == 0 )
                break;
              v22 = v31;
            }
          }
          if ( v20 == v43 )
          {
            v20 = v40;
            --v33;
          }
          else
          {
            v20 += v46;
          }
          ++v37;
        }
        while ( v37 < *v50 );
      }
      goto LABEL_61;
    case 4u:
      v14 = (_BYTE *)(v4 + (v9 >> 1));
      v39 = (_BYTE *)(v4 + ((unsigned int)(v6 - 1) >> 1));
      if ( (v5 & 0x10000) != 0 )
      {
        v15 = (-1 - 4 * (_BYTE)v6) & 4;
        v16 = (-1 - 4 * (_BYTE)v8) & 4;
        v32 = 4;
        v17 = 0;
        v42 = -4;
      }
      else
      {
        v15 = 4 - 4 * (((_BYTE)v6 - 1) & 1);
        v16 = 4 - 4 * (((_BYTE)v8 - 1) & 1);
        v17 = 4;
        v32 = 0;
        v42 = 4;
      }
      v47 = 0;
      if ( v6 != 0 )
      {
        do
        {
          v18 = (*v39 >> v15) & 0xF;
          v30 = v18;
          if ( v51 > 0 )
          {
            v36 = v51;
            while ( 1 )
            {
              *v14 = (v18 << v16) | *v14 & (3855 >> (4 - v16));
              if ( v16 == v17 )
              {
                v16 = v32;
                --v14;
              }
              else
              {
                v16 += v42;
              }
              if ( --v36 == 0 )
                break;
              v18 = v30;
            }
          }
          if ( v15 == v17 )
          {
            v15 = v32;
            --v39;
          }
          else
          {
            v15 += v42;
          }
          ++v47;
        }
        while ( v47 < *v50 );
      }
      break;
    default:
      v10 = v7 >> 3;
      v11 = (unsigned __int8 *)(v4 + v10 * (v6 - 1));
      v12 = (unsigned __int8 *)(v4 + v10 * v9);
      v35 = 0;
      if ( v6 != 0 )
      {
        do
        {
          memcpy(dst, src: v11, count: v10);
          if ( v51 > 0 )
          {
            for ( j = v51; j != 0; --j )
            {
              memcpy(dst: v12, src: dst, count: v10);
              v12 -= v10;
            }
            v8 = v45;
          }
          v11 -= v10;
          ++v35;
        }
        while ( v35 < *v50 );
      }
      goto LABEL_61;
  }
  v8 = v45;
LABEL_61:
  v29 = *(_BYTE *)(a1 + 267);
  *v50 = v8;
  if ( v29 < 8u )
    result = (v8 * (unsigned int)v29 + 7) >> 3;
  else
    result = v8 * (v29 >> 3);
  *(_DWORD *)(a1 + 260) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BD3A0
// Name: _png_read_filter_row
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_read_filter_row(int a1, int a2, _BYTE *a3, _BYTE *a4, int a5)
{
  unsigned int v5; // eax
  unsigned int v6; // esi
  _BYTE *v7; // ecx
  _BYTE *v8; // edx
  unsigned int v9; // esi
  unsigned int v10; // esi
  unsigned int i; // ecx
  _BYTE *v12; // ecx
  _BYTE *v13; // esi
  unsigned int v14; // edx
  unsigned __int8 *v15; // edi
  int v16; // ebp
  unsigned int j; // ebx
  unsigned __int8 *v18; // esi
  _BYTE *v19; // edi
  unsigned __int8 *v20; // edx
  unsigned int v21; // ecx
  unsigned __int8 *v22; // ebp
  int v23; // edi
  unsigned int v24; // ebx
  unsigned int v25; // edx
  int v26; // ecx
  int v27; // ebp
  int v28; // eax
  bool v29; // zf
  int v31; // [esp+10h] [ebp-10h]
  unsigned int v32; // [esp+14h] [ebp-Ch]
  unsigned __int8 *v33; // [esp+18h] [ebp-8h]
  unsigned __int8 *v34; // [esp+1Ch] [ebp-4h]
  _BYTE *v35; // [esp+34h] [ebp+14h]

  LOBYTE(v5) = a5;
  switch ( a5 )
  {
    case 0:
      return v5;
    case 1:
      v6 = *(_DWORD *)(a2 + 4);
      v5 = (*(unsigned __int8 *)(a2 + 11) + 7) >> 3;
      v7 = &a3[v5];
      if ( v5 < v6 )
      {
        v8 = a3;
        v9 = v6 - v5;
        do
        {
          LOBYTE(v5) = *v8;
          *v7++ += *v8++;
          --v9;
        }
        while ( v9 != 0 );
      }
      break;
    case 2:
      v10 = *(_DWORD *)(a2 + 4);
      v5 = (unsigned int)a3;
      for ( i = 0; i < v10; ++v5 )
        *(_BYTE *)v5 += a4[i++];
      break;
    case 3:
      v12 = a3;
      v13 = a4;
      v5 = (*(unsigned __int8 *)(a2 + 11) + 7) >> 3;
      v14 = *(_DWORD *)(a2 + 4) - v5;
      v15 = a3;
      if ( v5 != 0 )
      {
        v16 = (*(unsigned __int8 *)(a2 + 11) + 7) >> 3;
        do
        {
          LOBYTE(v5) = *v13 >> 1;
          *v12 += v5;
          ++v13;
          ++v12;
          --v16;
        }
        while ( v16 != 0 );
      }
      if ( v14 != 0 )
      {
        for ( j = v14; j != 0; --j )
        {
          v5 = ((unsigned __int8)*v13 + *v15) / 2;
          *v12 += v5;
          ++v15;
          ++v13;
          ++v12;
        }
      }
      break;
    case 4:
      v18 = a4;
      v19 = a3;
      v35 = a3;
      v20 = a3;
      v5 = (*(unsigned __int8 *)(a2 + 11) + 7) >> 3;
      v21 = *(_DWORD *)(a2 + 4) - v5;
      v22 = a4;
      if ( v5 != 0 )
      {
        do
        {
          *v19++ += *v18++;
          --v5;
        }
        while ( v5 != 0 );
        v35 = v19;
      }
      if ( v21 != 0 )
      {
        v32 = v21;
        while ( 1 )
        {
          v23 = *v20;
          v24 = *v18;
          v33 = v20 + 1;
          v25 = *v22;
          ++v18;
          v26 = v23 - v25;
          v34 = v22 + 1;
          if ( v24 >= v25 )
            v31 = v24 - v25;
          else
            v31 = v25 - v24;
          v27 = v23 - v25;
          if ( v26 < 0 )
            v27 = v25 - v23;
          v28 = v26 + v24 - v25;
          if ( v28 < 0 )
            v28 = -v28;
          if ( v31 > v27 || v31 > v28 )
          {
            if ( v27 <= v28 )
              LOBYTE(v25) = v24;
          }
          else
          {
            LOBYTE(v25) = v23;
          }
          *v35 += v25;
          LOBYTE(v5) = (_BYTE)v35 + 1;
          v29 = v32-- == 1;
          ++v35;
          if ( v29 )
            break;
          v20 = v33;
          v22 = v34;
        }
      }
      break;
    default:
      LOBYTE(v5) = png_warning(a1, a2: "Ignoring bad adaptive filter type");
      *a3 = 0;
      break;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101BD5A0
// Name: _png_read_start_row
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_read_start_row(int a1)
{
  int v1; // ebp
  unsigned int v2; // ecx
  unsigned int v3; // eax
  unsigned __int8 v4; // cl
  unsigned int v5; // ecx
  int v6; // ecx
  int v7; // eax
  int v8; // ebx
  char v9; // cl
  char v10; // cl
  int v11; // ecx
  char v12; // cl
  int v13; // edx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  char *v16; // eax
  bool v17; // cc
  unsigned __int8 *v18; // eax
  unsigned int v19; // [esp-Ch] [ebp-14h]

  *(_DWORD *)(a1 + 120) = 0;
  png_init_read_transformations(a1);
  if ( *(_BYTE *)(a1 + 291) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 112) & 2) != 0 )
      *(_DWORD *)(a1 + 208) = *(_DWORD *)(a1 + 204);
    else
      *(_DWORD *)(a1 + 208) = (*(_DWORD *)(a1 + 204) + 7) / 8u;
    v1 = *(_DWORD *)(a1 + 200);
    v2 = png_pass_inc[*(unsigned __int8 *)(a1 + 292)];
    v3 = (v1 - png_pass_start[*(unsigned __int8 *)(a1 + 292)] + v2 - 1) / v2;
    v4 = *(_BYTE *)(a1 + 297);
    *(_DWORD *)(a1 + 224) = v3;
    if ( v4 < 8u )
      v5 = (v3 * v4 + 7) >> 3;
    else
      v5 = v3 * (v4 >> 3);
    *(_DWORD *)(a1 + 220) = v5 + 1;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 216);
    v1 = *(_DWORD *)(a1 + 200);
    *(_DWORD *)(a1 + 208) = *(_DWORD *)(a1 + 204);
    *(_DWORD *)(a1 + 224) = v1;
    *(_DWORD *)(a1 + 220) = v6 + 1;
  }
  v7 = *(unsigned __int8 *)(a1 + 297);
  v8 = *(_DWORD *)(a1 + 112);
  if ( (v8 & 4) != 0 && *(_BYTE *)(a1 + 295) < 8u )
    v7 = 8;
  if ( (v8 & 0x1000) != 0 )
  {
    v9 = *(_BYTE *)(a1 + 294);
    if ( v9 == 3 )
    {
      v7 = 8 * (*(_WORD *)(a1 + 282) != 0) + 24;
    }
    else if ( v9 != 0 )
    {
      if ( v9 == 2 && *(_WORD *)(a1 + 282) != 0 )
        v7 = 4 * v7 / 3;
    }
    else
    {
      if ( v7 < 8 )
        v7 = 8;
      if ( *(_WORD *)(a1 + 282) != 0 )
        v7 *= 2;
    }
  }
  if ( (v8 & 0x8000) != 0 )
  {
    v10 = *(_BYTE *)(a1 + 294);
    if ( v10 == 3 )
    {
      v7 = 32;
      goto LABEL_32;
    }
    if ( v10 != 0 )
    {
      if ( v10 != 2 )
        goto LABEL_32;
      v11 = v7 > 32 ? 64 : 32;
    }
    else
    {
      v11 = v7 > 8 ? 32 : 16;
    }
    v7 = v11;
  }
LABEL_32:
  if ( (v8 & 0x4000) != 0 )
  {
    if ( *(_WORD *)(a1 + 282) != 0 && (v8 & 0x1000) != 0 || (v8 & 0x8000) != 0 || (v12 = *(_BYTE *)(a1 + 294)) == 4 )
    {
      v7 = v7 > 16 ? 64 : 32;
    }
    else if ( v7 > 8 )
    {
      v7 = v12 != 6 ? 48 : 64;
    }
    else
    {
      v7 = 8 * (v12 == 6) + 24;
    }
  }
  if ( (v8 & 0x100000) != 0 )
  {
    v13 = *(unsigned __int8 *)(a1 + 100);
    if ( v13 * *(unsigned __int8 *)(a1 + 101) > v7 )
      v7 = v13 * *(unsigned __int8 *)(a1 + 101);
  }
  v14 = (v1 + 7) & 0xFFFFFFF8;
  if ( v7 < 8 )
    v15 = (v14 * v7 + 7) >> 3;
  else
    v15 = v14 * ((unsigned int)v7 >> 3);
  v16 = (char *)png_malloc(a1, nSize: ((v7 + 7) >> 3) + v15 + 65);
  *(_DWORD *)(a1 + 588) = v16;
  v17 = *(_DWORD *)(a1 + 216) != -1;
  *(_DWORD *)(a1 + 236) = v16 + 32;
  if ( !v17 )
    png_error(a1, a2: "Row has too many bytes to allocate in memory.");
  v18 = (unsigned __int8 *)png_malloc(a1, nSize: *(_DWORD *)(a1 + 216) + 1);
  v19 = *(_DWORD *)(a1 + 216) + 1;
  *(_DWORD *)(a1 + 232) = v18;
  png_memset_check(a1, dst: v18, value: 0, count: v19);
  *(_DWORD *)(a1 + 108) |= 0x40u;
}

//------------------------------------------------------------------------------
// Address: 0x101BD860
// Name: _png_get_uint_31
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl png_get_uint_31(int a1, unsigned __int8 *a2)
{
  unsigned int result; // eax
  unsigned int v3; // esi

  result = png_get_uint_32(a1: a2);
  v3 = result;
  if ( result > 0x7FFFFFFF )
  {
    png_error(a1, a2: "PNG unsigned integer out of range.");
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BD890
// Name: _png_crc_finish
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_crc_finish(int a1, unsigned int a2)
{
  unsigned int v2; // ebx
  unsigned int i; // edi

  v2 = *(_DWORD *)(a1 + 176);
  for ( i = a2; i > v2; i -= v2 )
    png_crc_read(a1, a2: *(_DWORD *)(a1 + 172), a3: *(_DWORD *)(a1 + 176));
  if ( i != 0 )
    png_crc_read(a1, a2: *(_DWORD *)(a1 + 172), a3: i);
  if ( !png_crc_error(a1) )
    return 0;
  if ( ((*(_BYTE *)(a1 + 284) & 0x20) == 0 || (*(_DWORD *)(a1 + 108) & 0x200) != 0)
    && ((*(_BYTE *)(a1 + 284) & 0x20) != 0 || (*(_DWORD *)(a1 + 108) & 0x400) == 0) )
  {
    png_chunk_error(a1, a2: "CRC error");
    return 1;
  }
  else
  {
    png_chunk_warning(a1, a2: "CRC error");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BD950
// Name: _png_handle_IHDR
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_IHDR(int a1, int a2, int a3)
{
  unsigned int uint_31; // edi
  unsigned int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ebx
  unsigned int v8; // ebp
  unsigned __int8 v9; // al
  unsigned int v10; // eax
  int v11; // [esp+10h] [ebp-20h]
  int v12; // [esp+14h] [ebp-1Ch]
  unsigned __int8 v13[4]; // [esp+1Ch] [ebp-14h] BYREF
  unsigned __int8 v14[8]; // [esp+20h] [ebp-10h] BYREF
  unsigned __int8 v15; // [esp+28h] [ebp-8h]

  if ( (*(_BYTE *)(a1 + 104) & 1) != 0 )
    png_error(a1, a2: "Out of place IHDR");
  if ( a3 != 13 )
    png_error(a1, a2: "Invalid IHDR chunk");
  *(_DWORD *)(a1 + 104) |= 1u;
  png_crc_read(a1, a2: (int)v13, a3: 13);
  png_crc_finish(a1, a2: 0);
  uint_31 = png_get_uint_31(a1, a2: v13);
  v4 = png_get_uint_31(a1, a2: v14);
  v5 = v14[5];
  v6 = v14[4];
  v7 = v14[6];
  v8 = v4;
  v11 = v14[7];
  v12 = v15;
  *(_BYTE *)(a1 + 291) = v15;
  *(_BYTE *)(a1 + 568) = v11;
  *(_DWORD *)(a1 + 200) = uint_31;
  *(_DWORD *)(a1 + 204) = v4;
  *(_BYTE *)(a1 + 295) = v6;
  *(_BYTE *)(a1 + 294) = v5;
  *(_BYTE *)(a1 + 604) = v7;
  switch ( (char)v5 )
  {
    case 0:
    case 3:
      *(_BYTE *)(a1 + 298) = 1;
      break;
    case 2:
      *(_BYTE *)(a1 + 298) = 3;
      break;
    case 4:
      *(_BYTE *)(a1 + 298) = 2;
      break;
    case 6:
      *(_BYTE *)(a1 + 298) = 4;
      break;
    default:
      break;
  }
  v9 = v6 * *(_BYTE *)(a1 + 298);
  *(_BYTE *)(a1 + 297) = v9;
  if ( v9 < 8u )
    v10 = (uint_31 * v9 + 7) >> 3;
  else
    v10 = uint_31 * (v9 >> 3);
  *(_DWORD *)(a1 + 216) = v10;
  png_set_IHDR((_DWORD *)a1, a2, a3: uint_31, a4: v8, a5: v6, a6: v5, a7: v12, a8: v7, a9: v11);
}

//------------------------------------------------------------------------------
// Address: 0x101BDAD0
// Name: _png_handle_PLTE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_PLTE(int a1, int a2, signed int a3)
{
  int v3; // eax
  char v4; // cl
  unsigned int v5; // ebx
  char *v6; // edi
  int v7; // ebp
  char v8; // al
  char v9; // cl
  _BYTE v10[4]; // [esp+4h] [ebp-304h] BYREF
  unsigned __int8 src[2]; // [esp+8h] [ebp-300h] BYREF
  char v12; // [esp+Ah] [ebp-2FEh] BYREF

  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 1) != 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid PLTE after IDAT");
      png_crc_finish(a1, a2: a3);
      return;
    }
    if ( (v3 & 2) != 0 )
      png_error(a1, a2: "Duplicate PLTE chunk");
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before PLTE");
  }
  v4 = *(_BYTE *)(a1 + 294);
  *(_DWORD *)(a1 + 104) |= 2u;
  if ( (v4 & 2) == 0 )
  {
    png_warning(a1, a2: "Ignoring PLTE chunk in grayscale PNG");
    png_crc_finish(a1, a2: a3);
    return;
  }
  if ( (unsigned int)a3 > 0x300 || a3 % 3u != 0 )
  {
    if ( v4 != 3 )
    {
      png_warning(a1, a2: "Invalid palette chunk");
      png_crc_finish(a1, a2: a3);
      return;
    }
    png_error(a1, a2: "Invalid palette chunk");
  }
  v5 = a3 / 3;
  if ( a3 / 3 > 0 )
  {
    v6 = &v12;
    v7 = a3 / 3;
    do
    {
      png_crc_read(a1, a2: (int)v10, a3: 3);
      v8 = v10[1];
      v9 = v10[2];
      *(v6 - 2) = v10[0];
      *(v6 - 1) = v8;
      *v6 = v9;
      v6 += 3;
      --v7;
    }
    while ( v7 != 0 );
  }
  png_crc_finish(a1, a2: 0);
  png_set_PLTE(a1, a2, src, a4: v5);
  if ( *(_BYTE *)(a1 + 294) == 3 && a2 != 0 && (*(_BYTE *)(a2 + 8) & 0x10) != 0 )
  {
    if ( *(_WORD *)(a1 + 282) > (unsigned __int16)v5 )
    {
      png_warning(a1, a2: "Truncating incorrect tRNS chunk length");
      *(_WORD *)(a1 + 282) = v5;
    }
    if ( *(_WORD *)(a2 + 22) > (unsigned __int16)v5 )
    {
      png_warning(a1, a2: "Truncating incorrect info tRNS chunk length");
      *(_WORD *)(a2 + 22) = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BDC60
// Name: _png_handle_IEND
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_handle_IEND(int a1, int a2, unsigned int a3)
{
  int v3; // eax

  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 1) == 0 || (v3 & 4) == 0 )
    png_error(a1, a2: "No image in file");
  *(_DWORD *)(a1 + 104) |= 0x18u;
  if ( a3 != 0 )
    png_warning(a1, a2: "Incorrect IEND chunk length");
  return png_crc_finish(a1, a2: a3);
}

//------------------------------------------------------------------------------
// Address: 0x101BDCB0
// Name: _png_handle_gAMA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_gAMA(int a1, int a2, unsigned int a3)
{
  int v3; // esi
  int v4; // eax
  int v5; // edi
  int v6; // eax
  unsigned int v7; // ebx
  int uint_32; // eax
  int v9; // ebx
  _iobuf *v10; // eax
  float v11; // [esp+14h] [ebp-4h]

  v3 = a1;
  v4 = *(_DWORD *)(a1 + 104);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid gAMA after IDAT");
      png_crc_finish(a1: v3, a2: a3);
      return;
    }
    if ( (v4 & 2) != 0 )
      png_warning(a1, a2: "Out of place gAMA chunk");
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before gAMA");
  }
  v5 = a2;
  if ( a2 != 0 && ((v6 = *(_DWORD *)(a2 + 8)) & 1) != 0 && (v6 & 0x800) == 0 )
  {
    png_warning(a1: v3, a2: "Duplicate gAMA chunk");
    png_crc_finish(a1: v3, a2: a3);
  }
  else
  {
    v7 = a3;
    if ( a3 == 4 )
    {
      png_crc_read(a1: v3, a2: (int)&a1, a3: 4);
      if ( png_crc_finish(a1: v3, a2: 0) == 0 )
      {
        uint_32 = png_get_uint_32((unsigned __int8 *)&a1);
        v9 = uint_32;
        if ( uint_32 != 0 )
        {
          if ( v5 != 0 && (*(_DWORD *)(v5 + 8) & 0x800) != 0 && (uint_32 < 45000 || uint_32 > 46000) )
          {
            png_warning(a1: v3, a2: "Ignoring incorrect gAMA value when sRGB is also present");
            v10 = __iob_func();
            fprintf(str: v10 + 2, format: "gamma = (%d/100000)\n", v9);
          }
          else
          {
            v11 = (double)uint_32 / 100000.0;
            *(float *)(v3 + 348) = v11;
            png_set_gAMA(a1: v3, a2: v5, a3: v11);
            png_set_gAMA_fixed(a1: v3, a2: v5, a3: v9);
          }
        }
        else
        {
          png_warning(a1: v3, a2: "Ignoring gAMA chunk with gamma=0");
        }
      }
    }
    else
    {
      png_warning(a1: v3, a2: "Incorrect gAMA chunk length");
      png_crc_finish(a1: v3, a2: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BDE20
// Name: _png_handle_sBIT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_sBIT(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  int v4; // eax
  _BYTE *v5; // eax
  char v6; // dl
  char v7; // cl
  char v8; // dl
  char v9; // cl
  char v10; // [esp+8h] [ebp-4h] BYREF
  char v11; // [esp+9h] [ebp-3h]
  char v12; // [esp+Ah] [ebp-2h]
  char v13; // [esp+Bh] [ebp-1h]

  v3 = *(_DWORD *)(a1 + 104);
  v13 = 0;
  v12 = 0;
  v11 = 0;
  v10 = 0;
  if ( (v3 & 1) != 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid sBIT after IDAT");
      png_crc_finish(a1, a2: a3);
      return;
    }
    if ( (v3 & 2) != 0 )
      png_warning(a1, a2: "Out of place sBIT chunk");
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before sBIT");
  }
  if ( a2 != 0 && (*(_BYTE *)(a2 + 8) & 2) != 0 )
  {
    png_warning(a1, a2: "Duplicate sBIT chunk");
    png_crc_finish(a1, a2: a3);
  }
  else
  {
    v4 = 3;
    if ( *(_BYTE *)(a1 + 294) != 3 )
      v4 = *(unsigned __int8 *)(a1 + 298);
    if ( a3 == v4 && a3 <= 4 )
    {
      png_crc_read(a1, a2: (int)&v10, a3: v4);
      if ( png_crc_finish(a1, a2: 0) == 0 )
      {
        v5 = (_BYTE *)(a1 + 380);
        if ( (*(_BYTE *)(a1 + 294) & 2) != 0 )
        {
          v6 = v11;
          *v5 = v10;
          v7 = v12;
          *(_BYTE *)(a1 + 381) = v6;
          v8 = v13;
          *(_BYTE *)(a1 + 382) = v7;
          *(_BYTE *)(a1 + 384) = v8;
        }
        else
        {
          v9 = v10;
          *(_BYTE *)(a1 + 383) = v10;
          *v5 = v9;
          *(_BYTE *)(a1 + 381) = v9;
          *(_BYTE *)(a1 + 382) = v9;
          *(_BYTE *)(a1 + 384) = v11;
        }
        png_set_sBIT(a1, a2, a3: a1 + 380);
      }
    }
    else
    {
      png_warning(a1, a2: "Incorrect sBIT chunk length");
      png_crc_finish(a1, a2: a3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BDFA0
// Name: _png_handle_cHRM
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_handle_cHRM(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  int v5; // eax
  unsigned int uint_32; // edi
  unsigned int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // edi
  int v13; // ebx
  _iobuf *v14; // eax
  _iobuf *v15; // eax
  double v16; // [esp+20h] [ebp-A0h]
  double v17; // [esp+20h] [ebp-A0h]
  double v18; // [esp+28h] [ebp-98h]
  double v19; // [esp+28h] [ebp-98h]
  double v20; // [esp+30h] [ebp-90h]
  double v21; // [esp+30h] [ebp-90h]
  double v22; // [esp+38h] [ebp-88h]
  double v23; // [esp+38h] [ebp-88h]
  unsigned __int8 v24[4]; // [esp+84h] [ebp-3Ch] BYREF
  int v25; // [esp+88h] [ebp-38h]
  int v26; // [esp+8Ch] [ebp-34h]
  int v27; // [esp+90h] [ebp-30h]
  int v28; // [esp+94h] [ebp-2Ch]
  unsigned int v29; // [esp+98h] [ebp-28h]
  unsigned int v30; // [esp+9Ch] [ebp-24h]
  float v31; // [esp+A0h] [ebp-20h]
  float v32; // [esp+A4h] [ebp-1Ch]
  float v33; // [esp+A8h] [ebp-18h]
  float v34; // [esp+ACh] [ebp-14h]
  float v35; // [esp+B0h] [ebp-10h]
  float v36; // [esp+B4h] [ebp-Ch]
  float v37; // [esp+B8h] [ebp-8h]
  float v38; // [esp+BCh] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 1) != 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid cHRM after IDAT");
      return png_crc_finish(a1, a2: a3);
    }
    if ( (v3 & 2) != 0 )
      png_warning(a1, a2: "Missing PLTE before cHRM");
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before cHRM");
  }
  if ( a2 != 0 && ((v5 = *(_DWORD *)(a2 + 8)) & 4) != 0 && (v5 & 0x800) == 0 )
  {
    png_warning(a1, a2: "Duplicate cHRM chunk");
    return png_crc_finish(a1, a2: a3);
  }
  else if ( a3 == 32 )
  {
    png_crc_read(a1, a2: (int)v24, a3: 4);
    uint_32 = png_get_uint_32(a1: v24);
    png_crc_read(a1, a2: (int)v24, a3: 4);
    v7 = png_get_uint_32(a1: v24);
    if ( uint_32 > 0x13880 || v7 > 0x13880 || v7 + uint_32 > 0x186A0 )
    {
      png_warning(a1, a2: "Invalid cHRM white point");
      return png_crc_finish(a1, a2: 0x18u);
    }
    else
    {
      v30 = uint_32;
      v29 = v7;
      png_crc_read(a1, a2: (int)v24, a3: 4);
      v8 = png_get_uint_32(a1: v24);
      png_crc_read(a1, a2: (int)v24, a3: 4);
      v9 = png_get_uint_32(a1: v24);
      if ( (unsigned int)(v9 + v8) <= 0x186A0 )
      {
        v28 = v8;
        v27 = v9;
        png_crc_read(a1, a2: (int)v24, a3: 4);
        v10 = png_get_uint_32(a1: v24);
        png_crc_read(a1, a2: (int)v24, a3: 4);
        v11 = png_get_uint_32(a1: v24);
        if ( (unsigned int)(v11 + v10) <= 0x186A0 )
        {
          v26 = v10;
          v25 = v11;
          png_crc_read(a1, a2: (int)v24, a3: 4);
          v12 = png_get_uint_32(a1: v24);
          v32 = *(float *)&v12;
          png_crc_read(a1, a2: (int)v24, a3: 4);
          v13 = png_get_uint_32(a1: v24);
          v31 = *(float *)&v13;
          if ( (unsigned int)(v13 + v12) <= 0x186A0 )
          {
            v38 = (double)(int)v30 / 100000.0;
            v37 = (double)(int)v29 / 100000.0;
            v36 = (double)v28 / 100000.0;
            v35 = (double)v27 / 100000.0;
            v34 = (double)v26 / 100000.0;
            v33 = (double)v25 / 100000.0;
            v32 = (double)SLODWORD(v32) / 100000.0;
            v31 = (double)SLODWORD(v31) / 100000.0;
            if ( a2 != 0 && (*(_DWORD *)(a2 + 8) & 0x800) != 0 )
            {
              if ( v30 - 30270 > 0x7D0
                || v29 - 31900 > 0x7D0
                || (unsigned int)(v28 - 63000) > 0x7D0
                || (unsigned int)(v27 - 32000) > 0x7D0
                || (unsigned int)(v26 - 29000) > 0x7D0
                || (unsigned int)(v25 - 59000) > 0x7D0
                || v12 < 14000
                || v12 > 16000
                || v13 < 5000
                || v13 > 7000 )
              {
                png_warning(a1, a2: "Ignoring incorrect cHRM value when sRGB is also present");
                v22 = v35;
                v20 = v36;
                v18 = v37;
                v16 = v38;
                v14 = __iob_func();
                fprintf(str: v14 + 2, format: "wx=%f, wy=%f, rx=%f, ry=%f\n", v16, v18, v20, v22);
                v23 = v31;
                v21 = v32;
                v19 = v33;
                v17 = v34;
                v15 = __iob_func();
                fprintf(str: v15 + 2, format: "gx=%f, gy=%f, bx=%f, by=%f\n", v17, v19, v21, v23);
              }
              return png_crc_finish(a1, a2: 0);
            }
            else
            {
              png_set_cHRM(a1, a2, a3: v38, a4: v37, a5: v36, a6: v35, a7: v34, a8: v33, a9: v32, a10: v31);
              png_set_cHRM_fixed(a1, a2, a3: v30, a4: v29, a5: v28, a6: v27, a7: v26, a8: v25, a9: v12, a10: v13);
              return png_crc_finish(a1, a2: 0);
            }
          }
          else
          {
            png_warning(a1, a2: "Invalid cHRM blue point");
            return png_crc_finish(a1, a2: 0);
          }
        }
        else
        {
          png_warning(a1, a2: "Invalid cHRM green point");
          return png_crc_finish(a1, a2: 8u);
        }
      }
      else
      {
        png_warning(a1, a2: "Invalid cHRM red point");
        return png_crc_finish(a1, a2: 0x10u);
      }
    }
  }
  else
  {
    png_warning(a1, a2: "Incorrect cHRM chunk length");
    return png_crc_finish(a1, a2: a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BE450
// Name: _png_handle_sRGB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_sRGB(int a1, int a2, unsigned int a3)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  unsigned int v6; // ebx
  char v7; // bl
  int v8; // eax
  _iobuf *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // [esp-Ch] [ebp-10h]

  v3 = a1;
  v4 = *(_DWORD *)(a1 + 104);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid sRGB after IDAT");
      png_crc_finish(a1: v3, a2: a3);
      return;
    }
    if ( (v4 & 2) != 0 )
      png_warning(a1, a2: "Out of place sRGB chunk");
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before sRGB");
  }
  v5 = a2;
  if ( a2 != 0 && (*(_DWORD *)(a2 + 8) & 0x800) != 0 )
  {
    png_warning(a1: v3, a2: "Duplicate sRGB chunk");
    png_crc_finish(a1: v3, a2: a3);
  }
  else
  {
    v6 = a3;
    if ( a3 == 1 )
    {
      png_crc_read(a1: v3, a2: (int)&a1, a3: 1);
      if ( png_crc_finish(a1: v3, a2: 0) == 0 )
      {
        v7 = a1;
        if ( (unsigned __int8)a1 < 4u )
        {
          if ( v5 != 0 )
          {
            if ( (*(_BYTE *)(v5 + 8) & 1) != 0 )
            {
              v8 = *(_DWORD *)(v5 + 252);
              if ( v8 < 45000 || v8 > 46000 )
              {
                png_warning(a1: v3, a2: "Ignoring incorrect gAMA value when sRGB is also present");
                v18 = *(_DWORD *)(v3 + 564);
                v9 = __iob_func();
                fprintf(str: v9 + 2, format: "incorrect gamma=(%d/100000)\n", v18);
              }
            }
            if ( (*(_BYTE *)(v5 + 8) & 4) != 0 )
            {
              v10 = *(_DWORD *)(v5 + 256);
              if ( v10 < 30270
                || v10 > 32270
                || (v11 = *(_DWORD *)(v5 + 260)) < 31900
                || v11 > 33900
                || (v12 = *(_DWORD *)(v5 + 264)) < 63000
                || v12 > 65000
                || (v13 = *(_DWORD *)(v5 + 268)) < 32000
                || v13 > 34000
                || (v14 = *(_DWORD *)(v5 + 272)) < 29000
                || v14 > 31000
                || (v15 = *(_DWORD *)(v5 + 276)) < 59000
                || v15 > 61000
                || (v16 = *(_DWORD *)(v5 + 280)) < 14000
                || v16 > 16000
                || (v17 = *(_DWORD *)(v5 + 284)) < 5000
                || v17 > 7000 )
              {
                png_warning(a1: v3, a2: "Ignoring incorrect cHRM value when sRGB is also present");
              }
            }
          }
          png_set_sRGB_gAMA_and_cHRM(a1: v3, a2: v5, a3: v7);
        }
        else
        {
          png_warning(a1: v3, a2: "Unknown sRGB intent");
        }
      }
    }
    else
    {
      png_warning(a1: v3, a2: "Incorrect sRGB chunk length");
      png_crc_finish(a1: v3, a2: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BE650
// Name: _png_handle_iCCP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_iCCP(unsigned int a1, int a2, unsigned int a3)
{
  int v3; // edi
  int v4; // eax
  int v5; // ebp
  char *v6; // ebx
  _BYTE *i; // esi
  unsigned __int8 *v8; // esi
  unsigned __int8 v9; // al
  _BYTE *v10; // esi
  unsigned int v11; // esi
  unsigned __int8 *v12; // ebp
  unsigned int v13; // eax
  unsigned __int16 v14; // dx
  unsigned int v15; // edx
  char v16; // [esp+4h] [ebp-4h]

  v3 = a1;
  v4 = *(_DWORD *)(a1 + 104);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid iCCP after IDAT");
      png_crc_finish(a1: v3, a2: a3);
      return;
    }
    if ( (v4 & 2) != 0 )
      png_warning(a1, a2: "Out of place iCCP chunk");
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before iCCP");
  }
  if ( a2 != 0 && (*(_DWORD *)(a2 + 8) & 0x1000) != 0 )
  {
    png_warning(a1: v3, a2: "Duplicate iCCP chunk");
    png_crc_finish(a1: v3, a2: a3);
    return;
  }
  v5 = a3;
  v6 = (char *)png_malloc(a1: v3, nSize: a3 + 1);
  png_crc_read(a1: v3, a2: (int)v6, a3: v5);
  if ( png_crc_finish(a1: v3, a2: 0) != 0 )
  {
    png_free(a1: v3, pMem: v6);
    return;
  }
  v6[v5] = 0;
  for ( i = v6; *i != 0; ++i )
    ;
  v8 = i + 1;
  if ( v8 >= (unsigned __int8 *)&v6[v5] )
  {
    png_free(a1: v3, pMem: v6);
    png_warning(a1: v3, a2: "Malformed iCCP chunk");
    return;
  }
  v9 = *v8;
  v10 = v8 + 1;
  if ( v9 != 0 )
  {
    png_warning(a1: v3, a2: "Ignoring nonzero compression type in iCCP chunk");
    v9 = 0;
  }
  v11 = v10 - v6;
  v16 = v9;
  v12 = png_decompress_chunk(a1: v3, a2: v9, a3: v6, a4: v5, a5: v11, a6: &a1);
  v13 = a1 - v11;
  if ( v11 > a1 || v13 < 4 )
  {
    png_free(a1: v3, pMem: v12);
    png_warning(a1: v3, a2: "Profile size field missing from iCCP chunk");
  }
  else
  {
    HIBYTE(v14) = v12[v11];
    LOBYTE(v14) = v12[v11 + 1];
    v15 = v12[v11 + 3] | ((v12[v11 + 2] | (v14 << 8)) << 8);
    if ( v15 < v13 )
    {
      v13 = v15;
LABEL_22:
      png_set_iCCP(a1: v3, a2, a3: (const char *)v12, a4: v16, src: &v12[v11], count: v13);
      png_free(a1: v3, pMem: v12);
      return;
    }
    if ( v15 <= v13 )
      goto LABEL_22;
    png_free(a1: v3, pMem: v12);
    png_warning(a1: v3, a2: "Ignoring truncated iCCP profile.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BE800
// Name: _png_handle_sPLT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_sPLT(int a1, int a2, unsigned int a3)
{
  int v3; // ebx
  int v4; // eax
  char *v5; // ebp
  _BYTE *i; // esi
  char *v7; // esi
  char v8; // al
  unsigned __int8 *v9; // esi
  int v10; // ecx
  unsigned int v11; // eax
  char *v12; // eax
  int v13; // edi
  int v14; // ebx
  char *v15; // edx
  __int16 v16; // ax
  unsigned __int8 *v17; // esi
  __int16 v18; // cx
  __int16 v19; // ax
  unsigned __int8 *v20; // esi
  __int16 uint_16; // ax
  unsigned __int8 *v22; // esi
  __int16 *v23; // edx
  __int16 v24; // ax
  int v25; // edx
  __int16 v26; // ax
  int v27; // edx
  __int16 v28; // ax
  int v29; // edx
  __int16 v30; // ax
  int v31; // edx
  char *v32; // [esp+4h] [ebp-10h] BYREF
  char v33; // [esp+8h] [ebp-Ch]
  void *pMem; // [esp+Ch] [ebp-8h]
  int v35; // [esp+10h] [ebp-4h]

  v3 = a1;
  v4 = *(_DWORD *)(a1 + 104);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid sPLT after IDAT");
      png_crc_finish(a1, a2: a3);
      return;
    }
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before sPLT");
  }
  v5 = (char *)png_malloc(a1, nSize: a3 + 1);
  png_crc_read(a1, a2: (int)v5, a3);
  if ( png_crc_finish(a1, a2: 0) != 0 )
  {
    png_free(a1, pMem: v5);
  }
  else
  {
    v5[a3] = 0;
    for ( i = v5; *i != 0; ++i )
      ;
    v7 = i + 1;
    if ( v7 <= &v5[a3] )
    {
      v8 = *v7;
      v9 = (unsigned __int8 *)(v7 + 1);
      v33 = v8;
      v10 = 4 * (v8 != 8) + 6;
      v11 = (int)(a3 + v5 - (char *)v9) / v10;
      if ( (int)(a3 + v5 - (char *)v9) % v10 != 0 )
      {
        png_free(a1, pMem: v5);
        png_warning(a1, a2: "sPLT chunk has bad length");
      }
      else
      {
        v35 = (int)(a3 + v5 - (char *)v9) / v10;
        if ( v11 <= 0x19999999 )
        {
          v12 = (char *)png_malloc_warn(a1, nSize: 10 * v11);
          pMem = v12;
          if ( v12 != nullptr )
          {
            v13 = 0;
            if ( v35 > 0 )
            {
              v14 = 0;
              while ( 1 )
              {
                v15 = &v12[v14];
                if ( v33 == 8 )
                {
                  v16 = *v9;
                  v17 = v9 + 1;
                  *(_WORD *)v15 = v16;
                  v18 = *v17++;
                  *((_WORD *)v15 + 1) = v18;
                  v19 = *v17++;
                  *((_WORD *)v15 + 2) = v19;
                  *((_WORD *)v15 + 3) = *v17;
                  v20 = v17 + 1;
                }
                else
                {
                  uint_16 = png_get_uint_16(a1: v9);
                  v22 = v9 + 2;
                  *v23 = uint_16;
                  v24 = png_get_uint_16(a1: v22);
                  v22 += 2;
                  *(_WORD *)(v25 + 2) = v24;
                  v26 = png_get_uint_16(a1: v22);
                  v22 += 2;
                  *(_WORD *)(v27 + 4) = v26;
                  v28 = png_get_uint_16(a1: v22);
                  *(_WORD *)(v29 + 6) = v28;
                  v20 = v22 + 2;
                }
                v30 = png_get_uint_16(a1: v20);
                ++v13;
                *(_WORD *)(v31 + 8) = v30;
                v9 = v20 + 2;
                v14 += 10;
                if ( v13 >= v35 )
                  break;
                v12 = (char *)pMem;
              }
              v3 = a1;
            }
            v32 = v5;
            png_set_sPLT(a1: v3, a2, a3: (int)&v32, a4: 1);
            png_free(a1: v3, pMem: v5);
            png_free(a1: v3, pMem);
          }
          else
          {
            png_warning(a1, a2: "sPLT chunk requires too much memory");
          }
        }
        else
        {
          png_warning(a1, a2: "sPLT chunk too long");
        }
      }
    }
    else
    {
      png_free(a1, pMem: v5);
      png_warning(a1, a2: "malformed sPLT chunk");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BEA20
// Name: _png_handle_tRNS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_tRNS(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  char v4; // al
  unsigned int v5; // edi
  unsigned __int8 v6[4]; // [esp+8h] [ebp-110h] BYREF
  unsigned __int8 v7[2]; // [esp+Ch] [ebp-10Ch] BYREF
  unsigned __int8 v8[2]; // [esp+Eh] [ebp-10Ah] BYREF
  unsigned __int8 v9[4]; // [esp+10h] [ebp-108h] BYREF
  unsigned __int8 src[256]; // [esp+14h] [ebp-104h] BYREF

  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 1) != 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid tRNS after IDAT");
      png_crc_finish(a1, a2: a3);
      return;
    }
    if ( a2 != 0 && (*(_BYTE *)(a2 + 8) & 0x10) != 0 )
    {
      png_warning(a1, a2: "Duplicate tRNS chunk");
      png_crc_finish(a1, a2: a3);
      return;
    }
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before tRNS");
  }
  v4 = *(_BYTE *)(a1 + 294);
  if ( v4 != 0 )
  {
    if ( v4 == 2 )
    {
      v5 = a3;
      if ( a3 != 6 )
        goto LABEL_5;
      png_crc_read(a1, a2: (int)v7, a3: 6);
      *(_WORD *)(a1 + 282) = 1;
      *(_WORD *)(a1 + 398) = png_get_uint_16(a1: v7);
      *(_WORD *)(a1 + 400) = png_get_uint_16(a1: v8);
      *(_WORD *)(a1 + 402) = png_get_uint_16(a1: v9);
    }
    else
    {
      if ( v4 != 3 )
      {
        png_warning(a1, a2: "tRNS chunk not allowed with alpha channel");
        png_crc_finish(a1, a2: a3);
        return;
      }
      if ( (*(_BYTE *)(a1 + 104) & 2) == 0 )
        png_warning(a1, a2: "Missing PLTE before tRNS");
      v5 = a3;
      if ( a3 > *(unsigned __int16 *)(a1 + 280) || a3 > 0x100 )
        goto LABEL_5;
      if ( a3 == 0 )
      {
        png_warning(a1, a2: "Zero length tRNS chunk");
        png_crc_finish(a1, a2: 0);
        return;
      }
      png_crc_read(a1, a2: (int)src, a3);
      *(_WORD *)(a1 + 282) = a3;
    }
  }
  else
  {
    v5 = a3;
    if ( a3 != 2 )
    {
LABEL_5:
      png_warning(a1, a2: "Incorrect tRNS chunk length");
      png_crc_finish(a1, a2: v5);
      return;
    }
    png_crc_read(a1, a2: (int)v6, a3: 2);
    *(_WORD *)(a1 + 282) = 1;
    *(_WORD *)(a1 + 404) = png_get_uint_16(a1: v6);
  }
  if ( png_crc_finish(a1, a2: 0) != 0 )
    *(_WORD *)(a1 + 282) = 0;
  else
    png_set_tRNS(a1, a2, src, count: *(unsigned __int16 *)(a1 + 282), a5: a1 + 396);
}

//------------------------------------------------------------------------------
// Address: 0x101BEC90
// Name: _png_handle_bKGD
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_bKGD(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  char v4; // al
  int v5; // eax
  char v6; // al
  unsigned __int8 v7; // cl
  unsigned __int16 v8; // ax
  int v9; // eax
  int v10; // ecx
  __int16 v11; // dx
  int v12; // eax
  __int16 uint_16; // ax
  unsigned __int8 v14[2]; // [esp+8h] [ebp-Ch] BYREF
  unsigned __int8 v15[2]; // [esp+Ah] [ebp-Ah] BYREF
  unsigned __int8 v16[4]; // [esp+Ch] [ebp-8h] BYREF

  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 1) != 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid bKGD after IDAT");
      png_crc_finish(a1, a2: a3);
      return;
    }
    if ( *(_BYTE *)(a1 + 294) == 3 && (v3 & 2) == 0 )
    {
      png_warning(a1, a2: "Missing PLTE before bKGD");
      png_crc_finish(a1, a2: a3);
      return;
    }
    if ( a2 != 0 && (*(_BYTE *)(a2 + 8) & 0x20) != 0 )
    {
      png_warning(a1, a2: "Duplicate bKGD chunk");
      png_crc_finish(a1, a2: a3);
      return;
    }
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before bKGD");
  }
  v4 = *(_BYTE *)(a1 + 294);
  if ( v4 == 3 )
    v5 = 1;
  else
    v5 = 2 * (v4 & 2 | 1);
  if ( a3 != v5 )
  {
    png_warning(a1, a2: "Incorrect bKGD chunk length");
    png_crc_finish(a1, a2: a3);
    return;
  }
  png_crc_read(a1, a2: (int)v14, a3: v5);
  if ( png_crc_finish(a1, a2: 0) == 0 )
  {
    v6 = *(_BYTE *)(a1 + 294);
    if ( v6 == 3 )
    {
      v7 = v14[0];
      *(_BYTE *)(a1 + 312) = v14[0];
      v8 = *(_WORD *)(a2 + 20);
      if ( v8 != 0 )
      {
        if ( v7 > v8 )
        {
          png_warning(a1, a2: "Incorrect bKGD chunk index value");
          return;
        }
        v9 = v7;
        v10 = *(_DWORD *)(a1 + 276);
        v9 *= 3;
        v11 = *(unsigned __int8 *)(v9 + v10);
        v12 = v10 + v9;
        *(_WORD *)(a1 + 314) = v11;
        *(_WORD *)(a1 + 316) = *(unsigned __int8 *)(v12 + 1);
        *(_WORD *)(a1 + 318) = *(unsigned __int8 *)(v12 + 2);
      }
    }
    else
    {
      if ( (v6 & 2) != 0 )
      {
        *(_WORD *)(a1 + 314) = png_get_uint_16(a1: v14);
        *(_WORD *)(a1 + 316) = png_get_uint_16(a1: v15);
        uint_16 = png_get_uint_16(a1: v16);
      }
      else
      {
        uint_16 = png_get_uint_16(a1: v14);
        *(_WORD *)(a1 + 320) = uint_16;
        *(_WORD *)(a1 + 316) = uint_16;
        *(_WORD *)(a1 + 314) = uint_16;
      }
      *(_WORD *)(a1 + 318) = uint_16;
    }
    png_set_bKGD(a1, a2, a3: a1 + 312);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BEED0
// Name: _png_handle_hIST
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_hIST(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  unsigned int v4; // ebx
  unsigned int i; // edi
  unsigned __int8 v6[4]; // [esp+8h] [ebp-208h] BYREF
  _WORD v7[256]; // [esp+Ch] [ebp-204h] BYREF

  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 1) != 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid hIST after IDAT");
      png_crc_finish(a1, a2: a3);
      return;
    }
    if ( (v3 & 2) == 0 )
    {
      png_warning(a1, a2: "Missing PLTE before hIST");
      png_crc_finish(a1, a2: a3);
      return;
    }
    if ( a2 != 0 && (*(_BYTE *)(a2 + 8) & 0x40) != 0 )
    {
      png_warning(a1, a2: "Duplicate hIST chunk");
      png_crc_finish(a1, a2: a3);
      return;
    }
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before hIST");
  }
  v4 = a3 >> 1;
  if ( a3 >> 1 == *(unsigned __int16 *)(a1 + 280) && v4 <= 0x100 )
  {
    for ( i = 0; i < v4; ++i )
    {
      png_crc_read(a1, a2: (int)v6, a3: 2);
      v7[i] = png_get_uint_16(a1: v6);
    }
    if ( png_crc_finish(a1, a2: 0) == 0 )
      png_set_hIST(a1, a2, a3: (int)v7);
  }
  else
  {
    png_warning(a1, a2: "Incorrect hIST chunk length");
    png_crc_finish(a1, a2: a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF070
// Name: _png_handle_pHYs
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_pHYs(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  int v4; // eax
  int uint_32; // [esp-Ch] [ebp-24h]
  char v6; // [esp-8h] [ebp-20h]
  unsigned __int8 v7[4]; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 v8[8]; // [esp+Ch] [ebp-Ch] BYREF

  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 1) != 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid pHYs after IDAT");
      png_crc_finish(a1, a2: a3);
      return;
    }
    if ( a2 != 0 && *(char *)(a2 + 8) < 0 )
    {
      png_warning(a1, a2: "Duplicate pHYs chunk");
      png_crc_finish(a1, a2: a3);
      return;
    }
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before pHYs");
  }
  if ( a3 == 9 )
  {
    png_crc_read(a1, a2: (int)v7, a3: 9);
    if ( png_crc_finish(a1, a2: 0) == 0 )
    {
      v6 = v8[4];
      uint_32 = png_get_uint_32(a1: v8);
      v4 = png_get_uint_32(a1: v7);
      png_set_pHYs(a1, a2, a3: v4, a4: uint_32, a5: v6);
    }
  }
  else
  {
    png_warning(a1, a2: "Incorrect pHYs chunk length");
    png_crc_finish(a1, a2: a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF190
// Name: _png_handle_oFFs
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_oFFs(int a1, int a2, unsigned int a3)
{
  int v3; // eax
  int v4; // eax
  int uint_32; // [esp-Ch] [ebp-24h]
  char v6; // [esp-8h] [ebp-20h]
  unsigned __int8 v7[4]; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 v8[8]; // [esp+Ch] [ebp-Ch] BYREF

  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 1) != 0 )
  {
    if ( (v3 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid oFFs after IDAT");
      png_crc_finish(a1, a2: a3);
      return;
    }
    if ( a2 != 0 && (*(_DWORD *)(a2 + 8) & 0x100) != 0 )
    {
      png_warning(a1, a2: "Duplicate oFFs chunk");
      png_crc_finish(a1, a2: a3);
      return;
    }
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before oFFs");
  }
  if ( a3 == 9 )
  {
    png_crc_read(a1, a2: (int)v7, a3: 9);
    if ( png_crc_finish(a1, a2: 0) == 0 )
    {
      v6 = v8[4];
      uint_32 = png_get_uint_32(a1: v8);
      v4 = png_get_uint_32(a1: v7);
      png_set_oFFs(a1, a2, a3: v4, a4: uint_32, a5: v6);
    }
  }
  else
  {
    png_warning(a1, a2: "Incorrect oFFs chunk length");
    png_crc_finish(a1, a2: a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF2C0
// Name: _png_handle_pCAL
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_pCAL(int a1, int a2, unsigned int a3)
{
  int v4; // eax
  char *v5; // eax
  char *v6; // ebx
  unsigned __int8 *v7; // esi
  int v8; // eax
  unsigned __int8 v9; // cl
  char v10; // al
  unsigned __int8 *v11; // esi
  void *v12; // ebp
  int v13; // eax
  char v14; // [esp+7h] [ebp-11h]
  unsigned __int8 *v15; // [esp+8h] [ebp-10h]
  unsigned __int8 *v16; // [esp+Ch] [ebp-Ch]
  int v17; // [esp+10h] [ebp-8h]
  int uint_32; // [esp+14h] [ebp-4h]
  unsigned __int8 v19; // [esp+1Ch] [ebp+4h]
  int v20; // [esp+1Ch] [ebp+4h]

  v4 = *(_DWORD *)(a1 + 104);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      png_warning(a1, a2: "Invalid pCAL after IDAT");
      png_crc_finish(a1, a2: a3);
      return;
    }
    if ( a2 != 0 && (*(_DWORD *)(a2 + 8) & 0x400) != 0 )
    {
      png_warning(a1, a2: "Duplicate pCAL chunk");
      png_crc_finish(a1, a2: a3);
      return;
    }
  }
  else
  {
    png_error(a1, a2: "Missing IHDR before pCAL");
  }
  v5 = (char *)png_malloc_warn(a1, nSize: a3 + 1);
  v6 = v5;
  if ( v5 == nullptr )
  {
    png_warning(a1, a2: "No memory for pCAL purpose.");
    return;
  }
  png_crc_read(a1, a2: (int)v5, a3);
  if ( png_crc_finish(a1, a2: 0) != 0 )
  {
    png_free(a1, pMem: v6);
    return;
  }
  v6[a3] = 0;
  v15 = (unsigned __int8 *)&v6[a3];
  v7 = (unsigned __int8 *)v6;
  if ( *v6 != 0 )
  {
    do
      ++v7;
    while ( *v7 != 0 );
  }
  if ( &v6[a3] <= (char *)v7 + 12 )
  {
    png_warning(a1, a2: "Invalid pCAL data");
LABEL_28:
    png_free(a1, pMem: v6);
    return;
  }
  uint_32 = png_get_uint_32(a1: v7 + 1);
  v8 = png_get_uint_32(a1: v7 + 5);
  v9 = v7[10];
  v17 = v8;
  v10 = v7[9];
  v11 = v7 + 11;
  v14 = v10;
  v19 = v9;
  v16 = v11;
  switch ( v10 )
  {
    case 0:
      if ( v9 == 2 )
        break;
LABEL_27:
      png_warning(a1, a2: "Invalid pCAL parameters for equation type");
      goto LABEL_28;
    case 1:
      if ( v9 != 3 )
        goto LABEL_27;
      break;
    case 2:
      if ( v9 != 3 )
        goto LABEL_27;
      break;
    case 3:
      if ( v9 == 4 )
        break;
      goto LABEL_27;
    default:
      png_warning(a1, a2: "Unrecognized equation type for pCAL chunk");
      v9 = v19;
      break;
  }
  while ( *v11 != 0 )
    ++v11;
  v20 = v9;
  v12 = png_malloc_warn(a1, nSize: 4 * v9);
  if ( v12 != nullptr )
  {
    v13 = 0;
    if ( v20 <= 0 )
    {
LABEL_40:
      png_set_pCAL(a1, a2, src: (unsigned __int8 *)v6, a4: uint_32, a5: v17, a6: v14, a7: v20, a8: v16, a9: (int)v12);
      png_free(a1, pMem: v6);
      png_free(a1, pMem: v12);
    }
    else
    {
      while ( 1 )
      {
        *((_DWORD *)v12 + v13) = ++v11;
        if ( *v11 != 0 )
          break;
LABEL_38:
        if ( v11 > v15 )
          goto LABEL_41;
        if ( ++v13 >= v20 )
          goto LABEL_40;
      }
      while ( v11 <= v15 )
      {
        if ( *++v11 == 0 )
          goto LABEL_38;
      }
LABEL_41:
      png_warning(a1, a2: "Invalid pCAL data");
      png_free(a1, pMem: v6);
      png_free(a1, pMem: v12);
    }
  }
  else
  {
    png_free(a1, pMem: v6);
    png_warning(a1, a2: "No memory for pCAL params.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF520
// Name: _png_handle_sCAL
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_sCAL(char *endptr, int a2, unsigned int a3)
{
  char *v3; // edi
  int v4; // eax
  int v5; // ebx
  char *v6; // esi
  char *v7; // ebp
  char *i; // ebx
  const char *v9; // ebx
  double v10; // st7
  double v11; // [esp+20h] [ebp-8h]

  v3 = endptr;
  v4 = *((_DWORD *)endptr + 26);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      png_warning(a1: endptr, a2: "Invalid sCAL after IDAT");
      png_crc_finish(a1: (int)v3, a2: a3);
      return;
    }
    if ( a2 != 0 && (*(_DWORD *)(a2 + 8) & 0x4000) != 0 )
    {
      png_warning(a1: endptr, a2: "Duplicate sCAL chunk");
      png_crc_finish(a1: (int)v3, a2: a3);
      return;
    }
  }
  else
  {
    png_error(a1: endptr, a2: "Missing IHDR before sCAL");
  }
  v5 = a3;
  v6 = (char *)png_malloc_warn(a1: (int)v3, nSize: a3 + 1);
  if ( v6 != nullptr )
  {
    png_crc_read(a1: (int)v3, a2: (int)v6, a3: v5);
    if ( png_crc_finish(a1: (int)v3, a2: 0) != 0 )
    {
      png_free(a1: (int)v3, pMem: v6);
    }
    else
    {
      v7 = &v6[v5];
      v6[v5] = 0;
      v11 = strtod(nptr: v6 + 1, &endptr);
      if ( *endptr != 0 )
      {
        png_warning(a1: v3, a2: "malformed width string in sCAL chunk");
      }
      else
      {
        for ( i = v6; *i != 0; ++i )
          ;
        v9 = i + 1;
        v10 = strtod(nptr: v9, &endptr);
        if ( *endptr != 0 )
        {
          png_warning(a1: v3, a2: "malformed height string in sCAL chunk");
        }
        else if ( v7 < v9 || v11 <= 0.0 || v10 <= 0.0 )
        {
          png_warning(a1: v3, a2: "Invalid sCAL data");
          png_free(a1: (int)v3, pMem: v6);
        }
        else
        {
          png_set_sCAL(a1: (int)v3, a2, a3: *v6, a4: v11, a5: v10);
          png_free(a1: (int)v3, pMem: v6);
        }
      }
    }
  }
  else
  {
    png_warning(a1: v3, a2: "Out of memory while processing sCAL chunk");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF6D0
// Name: _png_handle_tIME
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_tIME(int a1, _DWORD *a2, unsigned int a3)
{
  int v3; // eax
  __int16 uint_16; // [esp+8h] [ebp-14h] BYREF
  unsigned __int8 v5; // [esp+Ah] [ebp-12h]
  __int16 v6; // [esp+Bh] [ebp-11h]
  char v7; // [esp+Dh] [ebp-Fh]
  char v8; // [esp+Eh] [ebp-Eh]
  unsigned __int8 v9[3]; // [esp+10h] [ebp-Ch] BYREF
  __int16 v10; // [esp+13h] [ebp-9h]
  char v11; // [esp+15h] [ebp-7h]
  char v12; // [esp+16h] [ebp-6h]

  if ( (*(_BYTE *)(a1 + 104) & 1) != 0 )
  {
    if ( a2 != nullptr && (a2[2] & 0x200) != 0 )
    {
      png_warning(a1, a2: "Duplicate tIME chunk");
      png_crc_finish(a1, a2: a3);
      return;
    }
  }
  else
  {
    png_error(a1, a2: "Out of place tIME chunk");
  }
  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 4) != 0 )
    *(_DWORD *)(a1 + 104) = v3 | 8;
  if ( a3 == 7 )
  {
    png_crc_read(a1, a2: (int)v9, a3: 7);
    if ( png_crc_finish(a1, a2: 0) == 0 )
    {
      v7 = v11;
      v8 = v12;
      v6 = v10;
      v5 = v9[2];
      uint_16 = png_get_uint_16(a1: v9);
      png_set_tIME(a1, a2, a3: &uint_16);
    }
  }
  else
  {
    png_warning(a1, a2: "Incorrect tIME chunk length");
    png_crc_finish(a1, a2: a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF7F0
// Name: _png_handle_tEXt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_tEXt(int a1, _DWORD *a2, int a3)
{
  int v3; // eax
  char *v4; // eax
  char *v5; // ebx
  const char *i; // ebp
  _DWORD *v7; // esi
  int v8; // ebp

  if ( (*(_BYTE *)(a1 + 104) & 1) == 0 )
    png_error(a1, a2: "Missing IHDR before tEXt");
  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 4) != 0 )
    *(_DWORD *)(a1 + 104) = v3 | 8;
  v4 = (char *)png_malloc_warn(a1, nSize: a3 + 1);
  v5 = v4;
  if ( v4 != nullptr )
  {
    png_crc_read(a1, a2: (int)v4, a3);
    if ( png_crc_finish(a1, a2: 0) != 0 )
    {
      png_free(a1, pMem: v5);
    }
    else
    {
      v5[a3] = 0;
      for ( i = v5; *i != 0; ++i )
        ;
      if ( i != &v5[a3] )
        ++i;
      v7 = png_malloc_warn(a1, nSize: 0x10u);
      if ( v7 != nullptr )
      {
        *v7 = -1;
        v7[1] = v5;
        v7[2] = i;
        v7[3] = strlen(i);
        v8 = png_set_text_2(a1, a2, a3: (int)v7, a4: 1);
        png_free(a1, pMem: v5);
        png_free(a1, pMem: v7);
        if ( v8 != 0 )
          png_warning(a1, a2: "Insufficient memory to process text chunk.");
      }
      else
      {
        png_warning(a1, a2: "Not enough memory to process text chunk.");
        png_free(a1, pMem: v5);
      }
    }
  }
  else
  {
    png_warning(a1, a2: "No memory to process text chunk.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BF910
// Name: _png_handle_zTXt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_handle_zTXt(int a1, _DWORD *a2, int a3)
{
  int v4; // eax
  int v5; // esi
  char *v6; // eax
  char *v7; // ebx
  char *v8; // eax
  char *i; // esi
  int v10; // ebp
  _BYTE *v11; // esi
  unsigned __int8 *v12; // ebx
  _DWORD *v13; // eax
  void *v14; // esi
  int v15; // ecx
  int v16; // ebp
  int v17; // [esp+10h] [ebp+4h]

  if ( (*(_BYTE *)(a1 + 104) & 1) == 0 )
    png_error(a1, a2: "Missing IHDR before zTXt");
  v4 = *(_DWORD *)(a1 + 104);
  if ( (v4 & 4) != 0 )
    *(_DWORD *)(a1 + 104) = v4 | 8;
  v5 = a3;
  v6 = (char *)png_malloc_warn(a1, nSize: a3 + 1);
  v7 = v6;
  if ( v6 != nullptr )
  {
    png_crc_read(a1, a2: (int)v6, a3: v5);
    if ( png_crc_finish(a1, a2: 0) != 0 )
    {
      png_free(a1, pMem: v7);
    }
    else
    {
      v8 = &v7[v5];
      v7[v5] = 0;
      for ( i = v7; *i != 0; ++i )
        ;
      if ( i == v8 )
      {
        v10 = -1;
        png_warning(a1, a2: "Zero length zTXt chunk");
      }
      else
      {
        v10 = i[1];
        v11 = i + 1;
        if ( v10 != 0 )
        {
          png_warning(a1, a2: "Unknown compression type in zTXt chunk");
          v10 = 0;
        }
        i = v11 + 1;
      }
      v17 = i - v7;
      v12 = png_decompress_chunk(a1, a2: v10, a3: v7, a4: a3, a5: i - v7, a6: (unsigned int *)&a3);
      v13 = png_malloc_warn(a1, nSize: 0x10u);
      v14 = v13;
      if ( v13 != nullptr )
      {
        v15 = a3;
        *v13 = v10;
        v13[1] = v12;
        v13[2] = &v12[v17];
        v13[3] = v15;
        v16 = png_set_text_2(a1, a2, a3: (int)v13, a4: 1);
        png_free(a1, pMem: v14);
        png_free(a1, pMem: v12);
        if ( v16 != 0 )
          png_error(a1, a2: "Insufficient memory to store zTXt chunk.");
      }
      else
      {
        png_warning(a1, a2: "Not enough memory to process zTXt chunk.");
        png_free(a1, pMem: v12);
      }
    }
  }
  else
  {
    png_warning(a1, a2: "Out of memory processing zTXt chunk.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BFA70
// Name: _png_handle_unknown
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_handle_unknown(int a1, int a2, unsigned int nSize)
{
  int v3; // ebx
  char *v5; // eax
  char v6; // cl
  void *v7; // eax
  int (__cdecl *v8)(int, int); // eax
  int v9; // ebx
  bool v10; // zf

  v3 = *(_DWORD *)(a1 + 104);
  if ( (v3 & 4) != 0 && memcmp((const void *)(a1 + 284), "IDAT", 4u) != 0 )
    *(_DWORD *)(a1 + 104) = v3 | 8;
  png_check_chunk_name(a1, a2: (unsigned __int8 *)(a1 + 284));
  if ( (*(_BYTE *)(a1 + 284) & 0x20) == 0 && png_handle_as_unknown(a1, a2: a1 + 284) != 3 && *(_DWORD *)(a1 + 540) == 0 )
    png_chunk_error(a1, a2: "unknown critical chunk");
  if ( (*(_DWORD *)(a1 + 108) & 0x8000) == 0 && *(_DWORD *)(a1 + 540) == 0 )
    return png_crc_finish(a1, a2: nSize);
  v5 = (char *)(a1 + 284);
  do
  {
    v6 = *v5;
    v5[332] = *v5;
    ++v5;
  }
  while ( v6 != 0 );
  v7 = png_malloc(a1, nSize);
  *(_DWORD *)(a1 + 624) = v7;
  *(_DWORD *)(a1 + 628) = nSize;
  png_crc_read(a1, a2: (int)v7, a3: nSize);
  v8 = *(int (__cdecl **)(int, int))(a1 + 540);
  if ( v8 != nullptr )
  {
    v9 = v8(a1, a2: a1 + 616);
    v10 = v9 == 0;
    if ( v9 < 0 )
    {
      png_chunk_error(a1, a2: "error in user chunk");
      v10 = v9 == 0;
    }
    if ( v10 )
    {
      if ( (*(_BYTE *)(a1 + 284) & 0x20) == 0 && png_handle_as_unknown(a1, a2: a1 + 284) != 3 )
        png_chunk_error(a1, a2: "unknown critical chunk");
      png_set_unknown_chunks(a1, a2, a3: a1 + 616, a4: 1);
    }
  }
  png_free(a1, pMem: *(void **)(a1 + 624));
  *(_DWORD *)(a1 + 624) = 0;
  return png_crc_finish(a1, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101BFC50
// Name: _png_read_finish_row
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl png_read_finish_row(int a1)
{
  int v1; // esi
  unsigned int result; // eax
  unsigned __int8 v3; // bl
  unsigned __int8 v4; // cl
  unsigned int v5; // ecx
  bool v6; // zf
  int v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // ecx
  int v10; // edx
  int v11; // eax
  const char *v12; // eax
  unsigned __int8 *v13; // [esp-14h] [ebp-20h]
  unsigned int v14; // [esp-Ch] [ebp-18h]
  unsigned __int8 v15[4]; // [esp+8h] [ebp-4h] BYREF

  v1 = a1;
  ++*(_DWORD *)(a1 + 228);
  result = *(_DWORD *)(v1 + 228);
  if ( result >= *(_DWORD *)(v1 + 208) )
  {
    if ( *(_BYTE *)(v1 + 291) != 0 )
    {
      v14 = *(_DWORD *)(v1 + 216) + 1;
      v13 = *(unsigned __int8 **)(v1 + 232);
      *(_DWORD *)(v1 + 228) = 0;
      png_memset_check(a1: v1, dst: v13, value: 0, count: v14);
      while ( 1 )
      {
        v3 = ++*(_BYTE *)(v1 + 292);
        if ( v3 >= 7u )
          break;
        result = (*(_DWORD *)(v1 + 200) - png_pass_start[v3] + png_pass_inc[v3] - 1) / (unsigned int)png_pass_inc[v3];
        v4 = *(_BYTE *)(v1 + 297);
        *(_DWORD *)(v1 + 224) = result;
        if ( v4 < 8u )
          v5 = (result * v4 + 7) >> 3;
        else
          v5 = result * (v4 >> 3);
        v6 = (*(_BYTE *)(v1 + 112) & 2) == 0;
        *(_DWORD *)(v1 + 220) = v5 + 1;
        if ( v6 )
        {
          result = (*(_DWORD *)(v1 + 204) - png_pass_ystart[v3] + png_pass_yinc[v3] - 1)
                 / (unsigned int)png_pass_yinc[v3];
          v6 = *(_DWORD *)(v1 + 224) == 0;
          *(_DWORD *)(v1 + 208) = result;
          if ( v6 )
            continue;
        }
        return result;
      }
    }
    if ( (*(_BYTE *)(v1 + 108) & 0x20) == 0 )
    {
      *(_DWORD *)(v1 + 128) = &a1;
      *(_DWORD *)(v1 + 132) = 1;
      v7 = v1 + 116;
      while ( 1 )
      {
        if ( *(_DWORD *)(v1 + 120) == 0 )
        {
          while ( *(_DWORD *)(v1 + 268) == 0 )
          {
            png_crc_finish(a1: v1, a2: 0);
            png_read_data(a1: v1);
            *(_DWORD *)(v1 + 268) = png_get_uint_31(a1: v1, a2: v15);
            png_reset_crc(a1: v1);
            png_crc_read(a1: v1, a2: v1 + 284, a3: 4);
            if ( memcmp((const void *)(v1 + 284), "IDAT", 4u) != 0 )
              png_error(a1: v1, a2: "Not enough image data");
          }
          v8 = *(_DWORD *)(v1 + 176);
          v9 = *(_DWORD *)(v1 + 268);
          v10 = *(_DWORD *)(v1 + 172);
          v7 = v1 + 116;
          *(_DWORD *)(v1 + 120) = v8;
          *(_DWORD *)(v1 + 116) = v10;
          if ( v8 > v9 )
            *(_DWORD *)(v1 + 120) = v9;
          png_crc_read(a1: v1, a2: v10, a3: *(_DWORD *)(v1 + 120));
          *(_DWORD *)(v1 + 268) -= *(_DWORD *)(v1 + 120);
        }
        v11 = inflate(a1: v7, a2: 1);
        if ( v11 == 1 )
          break;
        if ( v11 != 0 )
        {
          v12 = *(const char **)(v1 + 140);
          if ( v12 == nullptr )
            v12 = "Decompression Error";
          png_error(a1: v1, a2: v12);
        }
        if ( *(_DWORD *)(v1 + 132) == 0 )
        {
          png_warning(a1: v1, a2: "Extra compressed data.");
          goto LABEL_28;
        }
      }
      if ( *(_DWORD *)(v1 + 132) == 0 || *(_DWORD *)(v1 + 120) != 0 || *(_DWORD *)(v1 + 268) != 0 )
        png_warning(a1: v1, a2: "Extra compressed data");
LABEL_28:
      *(_DWORD *)(v1 + 104) |= 8u;
      *(_DWORD *)(v1 + 108) |= 0x20u;
      *(_DWORD *)(v1 + 132) = 0;
    }
    if ( *(_DWORD *)(v1 + 268) != 0 || *(_DWORD *)(v1 + 120) != 0 )
      png_warning(a1: v1, a2: "Extra compression data");
    result = inflateReset(a1: v1 + 116);
    *(_DWORD *)(v1 + 104) |= 8u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BFF60
// Name: _png_set_interlace_handling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_set_interlace_handling(int a1)
{
  if ( a1 == 0 || *(_BYTE *)(a1 + 291) == 0 )
    return 1;
  *(_DWORD *)(a1 + 112) |= 2u;
  return 7;
}

//------------------------------------------------------------------------------
// Address: 0x101BFF90
// Name: _png_do_invert
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_do_invert(int a1, _BYTE *a2)
{
  _BYTE *i; // eax
  int v3; // ecx
  int v4; // ecx
  unsigned int v5; // ecx
  int v6; // ecx
  unsigned int v7; // ecx

  LOBYTE(i) = *(_BYTE *)(a1 + 8);
  if ( (_BYTE)i != 0 )
  {
    if ( (_BYTE)i == 4 )
    {
      if ( *(_BYTE *)(a1 + 9) == 8 )
      {
        v4 = *(_DWORD *)(a1 + 4);
        i = a2;
        if ( v4 != 0 )
        {
          v5 = ((unsigned int)(v4 - 1) >> 1) + 1;
          do
          {
            *i = ~*i;
            i += 2;
            --v5;
          }
          while ( v5 != 0 );
        }
      }
      else if ( *(_BYTE *)(a1 + 9) == 16 )
      {
        v6 = *(_DWORD *)(a1 + 4);
        if ( v6 != 0 )
        {
          i = a2 + 1;
          v7 = ((unsigned int)(v6 - 1) >> 2) + 1;
          do
          {
            *(i - 1) = ~*(i - 1);
            *i = ~*i;
            i += 4;
            --v7;
          }
          while ( v7 != 0 );
        }
      }
    }
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 4);
    for ( i = a2; v3 != 0; --v3 )
    {
      *i = ~*i;
      ++i;
    }
  }
  return (char)i;
}

//------------------------------------------------------------------------------
// Address: 0x101C0020
// Name: _png_do_swap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_do_swap(int a1, char *a2)
{
  int v3; // esi
  char v4; // cl

  if ( *(_BYTE *)(a1 + 9) == 16 && *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10) != 0 )
  {
    v3 = *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10);
    do
    {
      v4 = *a2;
      *a2 = a2[1];
      a2[1] = v4;
      a2 += 2;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0060
// Name: _png_do_packswap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__cdecl png_do_packswap(int a1, _BYTE *a2)
{
  _BYTE *result; // eax
  unsigned __int8 v3; // dl
  unsigned int v4; // ecx
  _BYTE *v5; // esi

  result = (_BYTE *)a1;
  v3 = *(_BYTE *)(a1 + 9);
  if ( v3 < 8u )
  {
    result = a2;
    v4 = (unsigned int)&a2[*(_DWORD *)(a1 + 4)];
    switch ( v3 )
    {
      case 1u:
        v5 = &unk_102B1460;
        break;
      case 2u:
        v5 = &unk_102B1560;
        break;
      case 4u:
        v5 = &unk_102B1660;
        break;
      default:
        return result;
    }
    if ( (unsigned int)a2 < v4 )
    {
      do
      {
        *result = v5[(unsigned __int8)*result];
        ++result;
      }
      while ( (unsigned int)result < v4 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C00C0
// Name: _png_do_strip_filler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_do_strip_filler(int a1, _BYTE *a2, int a3)
{
  int v3; // ebx
  char v4; // dl
  unsigned int v5; // edi
  int result; // eax
  _BYTE *v7; // ecx
  _BYTE *v8; // edx
  _BYTE *v9; // eax
  unsigned int v10; // esi
  char v11; // cl
  _BYTE *v12; // eax
  _BYTE *v13; // edx
  unsigned int v14; // esi
  char v15; // dl
  int v16; // eax
  char v17; // dl
  _BYTE *v18; // ecx
  _BYTE *v19; // edx
  _BYTE *v20; // eax
  unsigned int v21; // esi
  char v22; // cl
  _BYTE *v23; // edx
  char v24; // cl
  _BYTE *v25; // eax
  char v26; // cl
  char v27; // cl
  unsigned int v28; // esi
  int v29; // eax
  char v30; // dl
  char v31; // dl
  _BYTE *v32; // ecx
  char v33; // dl
  char v34; // dl
  unsigned int v35; // esi
  unsigned int v36; // esi
  _BYTE *v37; // edx
  _BYTE *v38; // eax
  unsigned int v39; // esi
  _BYTE *v40; // eax
  unsigned int v41; // esi
  char v42; // dl
  int v43; // eax
  _BYTE *v44; // ecx

  v3 = a3;
  v4 = *(_BYTE *)(a1 + 8);
  v5 = *(_DWORD *)a1;
  result = (int)a2;
  v7 = a2;
  if ( (v4 == 2 || v4 == 6 && (a3 & 0x400000) != 0) && *(_BYTE *)(a1 + 10) == 4 )
  {
    if ( *(_BYTE *)(a1 + 9) != 8 )
    {
      if ( (a3 & 0x80u) == 0 )
      {
        if ( v5 != 0 )
        {
          v28 = *(_DWORD *)a1;
          do
          {
            *v7 = *(_BYTE *)(result + 2);
            v29 = result + 2;
            v30 = *(_BYTE *)++v29;
            v7[1] = v30;
            v31 = *(_BYTE *)(v29 + 1);
            v32 = v7 + 1;
            ++v29;
            v32[1] = v31;
            v33 = *(_BYTE *)++v29;
            v32 += 2;
            *v32 = v33;
            v34 = *(_BYTE *)++v29;
            *++v32 = v34;
            *++v32 = *(_BYTE *)(v29 + 1);
            v7 = v32 + 1;
            result = v29 + 2;
            --v28;
          }
          while ( v28 != 0 );
        }
      }
      else
      {
        v19 = a2 + 8;
        v20 = a2 + 6;
        if ( v5 > 1 )
        {
          v21 = v5 - 1;
          do
          {
            *v20 = *v19;
            v22 = v19[1];
            v23 = v19 + 1;
            v20[1] = v22;
            v24 = v23[1];
            v25 = v20 + 1;
            ++v23;
            v25[1] = v24;
            v26 = *++v23;
            v25 += 2;
            *v25 = v26;
            v27 = *++v23;
            *++v25 = v27;
            *++v25 = v23[1];
            v20 = v25 + 1;
            v19 = v23 + 4;
            --v21;
          }
          while ( v21 != 0 );
        }
      }
      result = 6 * v5;
      *(_BYTE *)(a1 + 11) = 48;
      *(_DWORD *)(a1 + 4) = 6 * v5;
      *(_BYTE *)(a1 + 10) = 3;
      goto LABEL_49;
    }
    if ( (a3 & 0x80u) == 0 )
    {
      if ( v5 != 0 )
      {
        v14 = *(_DWORD *)a1;
        do
        {
          v15 = *(_BYTE *)(result + 1);
          v16 = result + 1;
          *v7 = v15;
          v17 = *(_BYTE *)++v16;
          v18 = v7 + 1;
          *v18++ = v17;
          *v18 = *(_BYTE *)(v16 + 1);
          v7 = v18 + 1;
          result = v16 + 2;
          --v14;
        }
        while ( v14 != 0 );
      }
    }
    else
    {
      v8 = a2 + 3;
      v9 = a2 + 4;
      if ( v5 > 1 )
      {
        v10 = v5 - 1;
        do
        {
          *v8 = *v9;
          v11 = v9[1];
          v12 = v9 + 1;
          v13 = v8 + 1;
          *v13++ = v11;
          *v13 = v12[1];
          v8 = v13 + 1;
          v9 = v12 + 3;
          --v10;
        }
        while ( v10 != 0 );
        result = 3 * v5;
        *(_BYTE *)(a1 + 11) = 24;
        *(_DWORD *)(a1 + 4) = 3 * v5;
        *(_BYTE *)(a1 + 10) = 3;
        goto LABEL_49;
      }
    }
    result = 3 * v5;
    *(_BYTE *)(a1 + 11) = 24;
    *(_DWORD *)(a1 + 4) = 3 * v5;
    *(_BYTE *)(a1 + 10) = 3;
    goto LABEL_49;
  }
  if ( v4 != 0 )
  {
    if ( v4 != 4 )
      goto LABEL_49;
    if ( (a3 & 0x400000) == 0 )
      return result;
  }
  if ( *(_BYTE *)(a1 + 10) == 2 )
  {
    if ( *(_BYTE *)(a1 + 9) != 8 )
    {
      if ( (a3 & 0x80u) == 0 )
      {
        if ( v5 != 0 )
        {
          v41 = *(_DWORD *)a1;
          do
          {
            v42 = *(_BYTE *)(result + 2);
            v43 = result + 2;
            *v7 = v42;
            v44 = v7 + 1;
            *v44 = *(_BYTE *)(v43 + 1);
            v7 = v44 + 1;
            result = v43 + 2;
            --v41;
          }
          while ( v41 != 0 );
        }
      }
      else
      {
        v37 = a2 + 4;
        v38 = a2 + 2;
        if ( v5 > 1 )
        {
          v39 = v5 - 1;
          do
          {
            *v38 = *v37;
            v40 = v38 + 1;
            *v40 = v37[1];
            v38 = v40 + 1;
            v37 += 4;
            --v39;
          }
          while ( v39 != 0 );
        }
      }
      result = 2 * v5;
      *(_BYTE *)(a1 + 11) = 16;
      *(_DWORD *)(a1 + 4) = 2 * v5;
      goto LABEL_48;
    }
    if ( (a3 & 0x80u) == 0 )
    {
      if ( v5 != 0 )
      {
        v36 = *(_DWORD *)a1;
        do
        {
          *v7++ = *(_BYTE *)(result + 1);
          result += 2;
          --v36;
        }
        while ( v36 != 0 );
        v3 = a3;
      }
    }
    else if ( v5 != 0 )
    {
      v35 = *(_DWORD *)a1;
      do
      {
        *v7++ = *(_BYTE *)result;
        result += 2;
        --v35;
      }
      while ( v35 != 0 );
      v3 = a3;
      *(_BYTE *)(a1 + 11) = 8;
      *(_DWORD *)(a1 + 4) = v5;
      goto LABEL_48;
    }
    *(_BYTE *)(a1 + 11) = 8;
    *(_DWORD *)(a1 + 4) = v5;
LABEL_48:
    *(_BYTE *)(a1 + 10) = 1;
  }
LABEL_49:
  if ( (v3 & 0x400000) != 0 )
    *(_BYTE *)(a1 + 8) &= ~4u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C0370
// Name: _png_do_bgr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_do_bgr(int *a1, char *a2)
{
  char *v2; // eax
  char v3; // dl
  int v4; // ecx
  int v5; // esi
  char v6; // cl
  int v7; // esi
  char v8; // cl
  int v9; // esi
  char v10; // cl
  char v11; // dl
  char v12; // cl
  int v13; // esi
  char v14; // cl
  char v15; // dl
  char v16; // cl

  LOBYTE(v2) = (_BYTE)a1;
  v3 = *((_BYTE *)a1 + 8);
  if ( (v3 & 2) != 0 )
  {
    v4 = *a1;
    LOBYTE(v2) = *((_BYTE *)a1 + 9);
    if ( (_BYTE)v2 == 8 )
    {
      if ( v3 == 2 )
      {
        v2 = a2;
        if ( v4 != 0 )
        {
          v5 = *a1;
          do
          {
            v6 = *v2;
            *v2 = v2[2];
            v2[2] = v6;
            v2 += 3;
            --v5;
          }
          while ( v5 != 0 );
        }
      }
      else if ( v3 == 6 )
      {
        v2 = a2;
        if ( v4 != 0 )
        {
          v7 = *a1;
          do
          {
            v8 = *v2;
            *v2 = v2[2];
            v2[2] = v8;
            v2 += 4;
            --v7;
          }
          while ( v7 != 0 );
        }
      }
    }
    else if ( (_BYTE)v2 == 16 )
    {
      if ( v3 == 2 )
      {
        if ( v4 != 0 )
        {
          v2 = a2 + 1;
          v9 = *a1;
          do
          {
            v10 = *(v2 - 1);
            *(v2 - 1) = v2[3];
            v11 = v2[4];
            v2[3] = v10;
            v12 = *v2;
            *v2 = v11;
            v2[4] = v12;
            v2 += 6;
            --v9;
          }
          while ( v9 != 0 );
        }
      }
      else if ( v3 == 6 && v4 != 0 )
      {
        v2 = a2 + 1;
        v13 = *a1;
        do
        {
          v14 = *(v2 - 1);
          *(v2 - 1) = v2[3];
          v15 = v2[4];
          v2[3] = v14;
          v16 = *v2;
          *v2 = v15;
          v2[4] = v16;
          v2 += 8;
          --v13;
        }
        while ( v13 != 0 );
      }
    }
  }
  return (char)v2;
}

//------------------------------------------------------------------------------
// Address: 0x101C0456
// Name: D3DXCompileShader(x,x,x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXCompileShader(
        void *a1,
        unsigned int a2,
        struct _D3DXMACRO *a3,
        struct ID3DXInclude *a4,
        char *a5,
        char *a6,
        int a7,
        struct ID3DXBuffer **a8,
        struct ID3DXBuffer **a9,
        struct ID3DXConstantTable **a10)
{
  _BYTE v12[24]; // [esp+Ch] [ebp-370h] BYREF
  _BYTE v13[664]; // [esp+24h] [ebp-358h] BYREF
  _BYTE v14[184]; // [esp+2BCh] [ebp-C0h] BYREF
  struct ID3DXConstantTable *v15; // [esp+374h] [ebp-8h] BYREF
  struct ID3DXBuffer *v16; // [esp+378h] [ebp-4h] BYREF
  int v17; // [esp+3A0h] [ebp+24h]

  v16 = nullptr;
  v15 = nullptr;
  D3DXShader::CPreProcessor::CPreProcessor(this: (D3DXShader::CPreProcessor *)v12);
  if ( a8 != nullptr )
    *a8 = nullptr;
  if ( a10 != nullptr )
    *a10 = nullptr;
  if ( (a7 & 0xFFFFF9C0) != 0 )
  {
    v17 = -2005530516;
  }
  else
  {
    v17 = D3DXShader::CPreProcessor::InitializeFromMemory(
            this: (D3DXShader::CPreProcessor *)v12,
            a2: a1,
            a3: a2,
            a4: a3,
            a5: a4);
    if ( v17 >= 0 )
    {
      D3DXShader::CCompiler::CCompiler(this: (D3DXShader::CCompiler *)v14);
      v17 = D3DXShader::CCompiler::Compile(
              this: (D3DXShader::CCompiler *)v14,
              a2: (struct D3DXShader::CPreProcessor *)v12,
              a3: nullptr,
              a4: a5,
              a5: 0,
              a6,
              a7: a7 | 0x100,
              a8: &v16,
              a9: &v15);
      if ( v17 >= 0 )
      {
        D3DXShader::CCompiler::~CCompiler(this: (D3DXShader::CCompiler *)v14);
        if ( D3DXShader::CTErrors::GetErrorCount(this: (D3DXShader::CTErrors *)v13) != 0 )
        {
          v17 = -2005529767;
        }
        else
        {
          if ( a8 != nullptr )
          {
            *a8 = v16;
            v16 = nullptr;
          }
          if ( a10 != nullptr )
          {
            *a10 = v15;
            v15 = nullptr;
          }
        }
      }
      else
      {
        D3DXShader::CCompiler::~CCompiler(this: (D3DXShader::CCompiler *)v14);
      }
    }
  }
  if ( a9 != nullptr )
    D3DXShader::CTErrors::GetErrorBuffer(this: (D3DXShader::CTErrors *)v13, a2: a9);
  if ( v15 != nullptr )
  {
    ((void (__cdecl *)(struct ID3DXConstantTable *))v15->Release)(a1: v15);
    v15 = nullptr;
  }
  if ( v16 != nullptr )
  {
    ((void (__cdecl *)(struct ID3DXBuffer *))v16->Release)(a1: v16);
    v16 = nullptr;
  }
  D3DXShader::CPreProcessor::~CPreProcessor(this: (D3DXShader::CPreProcessor *)v12);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x101C0588
// Name: D3DXFindShaderComment(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXFindShaderComment(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v4; // ebx
  unsigned int v6; // eax
  unsigned int *i; // ecx
  unsigned int v8; // eax
  int v9; // esi
  unsigned int v10; // eax

  if ( a3 != nullptr )
    *a3 = 0;
  v4 = a4;
  if ( a4 != nullptr )
    *a4 = 0;
  if ( a1 == nullptr )
    return -2005530516;
  v6 = *a1 & 0xFFFF0000;
  if ( v6 != 1180172288 && v6 != 1415053312 && v6 != 2147352576 && v6 != 2147418112 && v6 != -131072 && v6 != -65536 )
    return -2005529767;
  for ( i = a1 + 1; ; ++i )
  {
    v8 = *i;
    if ( (*i & 0x80000000) == 0 )
    {
      v9 = (unsigned __int16)*i;
      if ( v9 == 0xFFFF )
        return 1;
      if ( v9 == 65534 )
        break;
      if ( (unsigned __int16)*a1 >= 0x200u )
      {
        v10 = HIBYTE(v8) & 0xF;
LABEL_28:
        i += v10;
        goto LABEL_31;
      }
      if ( v9 == 81 )
        i += 5;
    }
LABEL_31:
    v4 = a4;
  }
  v10 = HIWORD(v8) & 0x7FFF;
  if ( v10 <= 1 || a2 != i[1] )
    goto LABEL_28;
  if ( a3 != nullptr )
    *a3 = i + 2;
  if ( v4 != nullptr )
    *v4 = 4 * v10 - 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C0690
// Name: D3DXGetTargetDescByName(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXGetTargetDescByName(const char *a1, int a2, _DWORD *a3)
{
  unsigned int v3; // edx
  int v5; // eax
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // [esp+0h] [ebp-4h]

  v3 = 0;
  if ( a1 == nullptr )
    return -2005530516;
  v5 = 44;
  v9 = 44;
  while ( 1 )
  {
    v6 = (v3 + v5) >> 1;
    v7 = strcmp((&off_102B1760)[3 * v6], a1);
    if ( v7 == 0 )
      break;
    if ( v7 >= 0 )
      v9 = v6;
    else
      v3 = v6 + 1;
    v5 = v9;
    if ( v3 >= v9 )
      return -2147467259;
  }
  v8 = 3 * v6;
  if ( (a2 & dword_102B1768[v8]) != a2 )
    return -2147467259;
  if ( a3 != nullptr )
  {
    *a3 = (&off_102B1760)[v8];
    a3[1] = (&off_102B1760)[v8 + 1];
    a3[2] = (&off_102B1760)[v8 + 2];
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C072E
// Name: D3DXGetTargetDescByVersion(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXGetTargetDescByVersion(int a1, int a2, _DWORD *a3)
{
  int v3; // ecx
  const char *v4; // eax
  int v5; // edx
  char **v7; // esi

  v3 = 44;
  v4 = "vs_3_0";
  while ( 1 )
  {
    v5 = *((_DWORD *)v4 - 4);
    v4 -= 12;
    --v3;
    if ( v5 == a1 && (a2 & *(_DWORD *)v4) == a2 )
      break;
    if ( v4 <= (const char *)dword_102B1768 )
      return -2147467259;
  }
  if ( a3 != nullptr )
  {
    v7 = &(&off_102B1760)[3 * v3];
    *a3 = *v7++;
    a3[1] = *v7;
    a3[2] = v7[1];
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C077D
// Name: D3DXGetShaderConstantTable(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXGetShaderConstantTable(unsigned int *a1, D3DXShader::CConstantTable **a2)
{
  D3DXShader::CConstantTable *v2; // esi
  unsigned int v4; // eax
  D3DXShader::CConstantTable *v5; // eax
  int v6; // edi

  v2 = nullptr;
  if ( a2 != nullptr )
    *a2 = nullptr;
  if ( a1 == nullptr || a2 == nullptr )
    return -2005530516;
  v4 = *a1 & 0xFFFF0000;
  if ( v4 != -131072 && v4 != -65536 )
    goto LABEL_14;
  v5 = (D3DXShader::CConstantTable *)MemAlloc_Alloc(nSize: 0x20u);
  if ( v5 != nullptr )
    v2 = D3DXShader::CConstantTable::CConstantTable(this: v5);
  if ( v2 == nullptr )
    return -2147024882;
  v6 = D3DXShader::CConstantTable::Initialize(this: v2, a2: a1, a3: nullptr);
  if ( v6 < 0 )
  {
    D3DXShader::CConstantTable::`scalar deleting destructor'(this: v2, a2: 1);
    return v6;
  }
  else
  {
LABEL_14:
    *a2 = v2;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C07FE
// Name: void D3DXShader::Enter(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void D3DXShader::Enter()
{
  while ( InterlockedCompareExchange(Destination: &D3DXShader::g_SpinLock, Exchange: 1, Comperand: 0) == 1 )
    Sleep(dwMilliseconds: 1u);
  if ( D3DXShader::g_NumContenders == 0 )
    InitializeCriticalSection(lpCriticalSection: &D3DXShader::g_CriticalSection);
  ++D3DXShader::g_NumContenders;
  InterlockedExchange(Target: &D3DXShader::g_SpinLock, Value: 0);
  EnterCriticalSection(lpCriticalSection: &D3DXShader::g_CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101C0853
// Name: void D3DXShader::Leave(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void D3DXShader::Leave()
{
  LeaveCriticalSection(lpCriticalSection: &D3DXShader::g_CriticalSection);
  while ( InterlockedCompareExchange(Destination: &D3DXShader::g_SpinLock, Exchange: 1, Comperand: 0) == 1 )
    Sleep(dwMilliseconds: 1u);
  if ( --D3DXShader::g_NumContenders == 0 )
    DeleteCriticalSection(lpCriticalSection: &D3DXShader::g_CriticalSection);
  InterlockedExchange(Target: &D3DXShader::g_SpinLock, Value: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101C08A4
// Name: public: D3DXShader::CPPDefine::CPPDefine(char const __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPPDefine *__thiscall D3DXShader::CPPDefine::CPPDefine(
        D3DXShader::CPPDefine *this,
        const char *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4)
{
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C08C8
// Name: public: D3DXShader::CPPConditional::CPPConditional(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPPConditional *__thiscall D3DXShader::CPPConditional::CPPConditional(
        D3DXShader::CPPConditional *this,
        int a2,
        int a3)
{
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C0907
// Name: public: D3DXShader::CPPInclude::CPPInclude(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPPInclude *__thiscall D3DXShader::CPPInclude::CPPInclude(D3DXShader::CPPInclude *this)
{
  D3DXShader::CTokenize::CTokenize(this);
  D3DXCore::CFile::CFile(this: (D3DXShader::CPPInclude *)((char *)this + 60));
  D3DXCore::CResource::CResource(this: (D3DXShader::CPPInclude *)((char *)this + 76));
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 27) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C093C
// Name: public: D3DXShader::CPPInclude::~CPPInclude(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPPInclude::~CPPInclude(D3DXShader::CPPInclude *this)
{
  D3DXShader::CPPDefine *v2; // ecx
  void *v3; // edi

  v2 = *((D3DXShader::CPPDefine **)this + 14);
  if ( v2 != nullptr )
    D3DXShader::CPPDefine::`scalar deleting destructor'(this: v2, a2: 1);
  v3 = *((void **)this + 27);
  if ( v3 != nullptr )
  {
    D3DXShader::CPPInclude::~CPPInclude(this: *((D3DXShader::CPPInclude **)this + 27));
    free(pMem: v3);
  }
  if ( *((_DWORD *)this + 22) != 0 && *((_DWORD *)this + 25) != 0 )
    (*(void (__stdcall **)(_DWORD, _DWORD))(**((_DWORD **)this + 22) + 4))(
      a1: *((_DWORD *)this + 22),
      a2: *((_DWORD *)this + 25));
  D3DXCore::CResource::~CResource(this: (HGDIOBJ *)this + 19);
  D3DXCore::CFile::~CFile(this: (D3DXShader::CPPInclude *)((char *)this + 60));
  D3DXShader::CNodeState::Print(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C09B6
// Name: public: long D3DXShader::CPPInclude::InitializeFromFile(void const __near *,int,class D3DXCore::CAlloc __near *,struct D3DXShader::D3DXTOKEN __near *,class D3DXShader::CTErrors __near *,struct ID3DXInclude __near *,enum _D3DXINCLUDE_TYPE,void const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPPInclude::InitializeFromFile(
        D3DXShader::CPPInclude *this,
        const char *lpWideCharStr,
        int a3,
        struct D3DXCore::CAlloc *a4,
        struct D3DXShader::D3DXTOKEN *a5,
        struct D3DXShader::CTErrors *a6,
        struct ID3DXInclude *a7,
        enum _D3DXINCLUDE_TYPE a8,
        const void *a9)
{
  unsigned int v10; // kr00_4
  unsigned __int8 *v11; // eax
  unsigned int *v12; // edi
  const void **v13; // esi
  int result; // eax
  DWORD FullPathNameA; // esi
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // eax
  unsigned int v18; // ecx
  int v19; // esi
  LPSTR FilePart; // [esp+Ch] [ebp-120h] BYREF
  struct D3DXShader::D3DXTOKEN *v21; // [esp+10h] [ebp-11Ch]
  struct D3DXShader::CTErrors *v22; // [esp+14h] [ebp-118h]
  struct D3DXCore::CAlloc *v23; // [esp+18h] [ebp-114h]
  unsigned int v24; // [esp+1Ch] [ebp-110h]
  LPCSTR lpFileName; // [esp+20h] [ebp-10Ch]
  char MultiByteStr[260]; // [esp+24h] [ebp-108h] BYREF

  v23 = a4;
  v21 = a5;
  v22 = a6;
  lpFileName = lpWideCharStr;
  v24 = (unsigned int)a9;
  *((_DWORD *)this + 22) = a7;
  if ( a3 != 0 )
  {
    WideCharToMultiByte(
      CodePage: 0xFDE9u,
      dwFlags: 0,
      (LPCWCH)lpWideCharStr,
      cchWideChar: -1,
      lpMultiByteStr: MultiByteStr,
      cbMultiByte: 260,
      lpDefaultChar: nullptr,
      lpUsedDefaultChar: nullptr);
    lpFileName = MultiByteStr;
  }
  if ( a7 != nullptr )
  {
    v10 = strlen(lpFileName);
    v11 = D3DXCore::CAlloc::Alloc(this: v23, a2: v10 + 1, dwSize: 1u);
    *((_DWORD *)this + 23) = v11;
    if ( v11 != nullptr )
    {
      qmemcpy(v11, lpFileName, v10 + 1);
      v12 = (unsigned int *)((char *)this + 104);
      v13 = (const void **)((char *)this + 100);
      v24 = (***((int (__stdcall ****)(_DWORD, enum _D3DXINCLUDE_TYPE, _DWORD, unsigned int, char *, char *))this + 22))(
              a1: *((_DWORD *)this + 22),
              a2: a8,
              a3: *((_DWORD *)this + 23),
              a4: v24,
              a5: (char *)this + 100,
              a6: (char *)this + 104);
      if ( (v24 & 0x80000000) != 0 )
      {
        D3DXShader::CTErrors::Error(
          this: v22,
          a2: v21,
          a3: 0x5E3u,
          format: "failed to open source file: '%s'",
          lpFileName);
        return v24;
      }
      goto LABEL_15;
    }
    return -2147024882;
  }
  FullPathNameA = GetFullPathNameA(lpFileName, nBufferLength: 0, lpBuffer: nullptr, lpFilePart: nullptr);
  v24 = FullPathNameA + 1;
  v16 = D3DXCore::CAlloc::Alloc(this: v23, a2: FullPathNameA + 1, dwSize: 1u);
  *((_DWORD *)this + 24) = v16;
  if ( v16 == nullptr )
    return -2147024882;
  v17 = D3DXCore::CAlloc::Alloc(this: v23, a2: v24, dwSize: 1u);
  *((_DWORD *)this + 23) = v17;
  if ( v17 == nullptr )
    return -2147024882;
  GetFullPathNameA(lpFileName, nBufferLength: FullPathNameA, lpBuffer: *((LPSTR *)this + 24), lpFilePart: &FilePart);
  v18 = v24;
  *(_BYTE *)(FullPathNameA + *((_DWORD *)this + 24)) = 0;
  qmemcpy(*((void **)this + 23), *((const void **)this + 24), v18);
  if ( FilePart != nullptr )
    *FilePart = 0;
  v19 = D3DXCore::CFile::Open(this: (HANDLE *)this + 15, lpWideCharStr: *((LPCWCH *)this + 23), a3: 0);
  if ( v19 < 0 )
  {
    D3DXShader::CTErrors::Error(this: v22, a2: v21, a3: 0x5E3u, format: "failed to open source file: '%s'", lpFileName);
    return v19;
  }
  v13 = (const void **)((char *)this + 100);
  *((_DWORD *)this + 25) = *((_DWORD *)this + 17);
  v12 = (unsigned int *)((char *)this + 104);
  *((_DWORD *)this + 26) = *((_DWORD *)this + 18);
LABEL_15:
  result = D3DXShader::CTokenize::Initialize(
             this,
             a2: *v13,
             a3: *v12,
             a4: *((const char **)this + 23),
             a5: 1u,
             a6: v23,
             a7: v22);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C0BEA
// Name: public: long D3DXShader::CPPInclude::InitializeFromMemory(void const __near *,unsigned int,class D3DXCore::CAlloc __near *,class D3DXShader::CTErrors __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPPInclude::InitializeFromMemory(
        D3DXShader::CPPInclude *this,
        void *a2,
        unsigned int a3,
        struct D3DXCore::CAlloc *a4,
        struct D3DXShader::CTErrors *a5)
{
  int result; // eax

  if ( a3 != 0 && a2 == nullptr )
    return -2005530516;
  *((_DWORD *)this + 25) = a2;
  *((_DWORD *)this + 26) = a3;
  result = D3DXShader::CTokenize::Initialize(this, a2, a3, a4: nullptr, a5: 1u, a6: a4, a7: a5);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C0C25
// Name: public: D3DXShader::CPPBlock::CPPBlock(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPPBlock *__thiscall D3DXShader::CPPBlock::CPPBlock(D3DXShader::CPPBlock *this, unsigned int a2)
{
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 2) = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C0C40
// Name: public: D3DXShader::CPPBlock::~CPPBlock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPPBlock::~CPPBlock(D3DXShader::CPPBlock *this)
{
  void *v1; // esi

  v1 = *((void **)this + 1);
  if ( v1 != nullptr )
  {
    D3DXShader::CPPBlock::~CPPBlock(this: *((D3DXShader::CPPBlock **)this + 1));
    free(pMem: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0C7B
// Name: public: D3DXShader::CPPPragmaDef::~CPPPragmaDef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPPPragmaDef::~CPPPragmaDef(D3DXShader::CPPPragmaDef *this)
{
  void *v1; // esi

  v1 = *((void **)this + 10);
  if ( v1 != nullptr )
  {
    D3DXShader::CPPPragmaDef::~CPPPragmaDef(this: *((D3DXShader::CPPPragmaDef **)this + 10));
    free(pMem: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0CB6
// Name: public: long D3DXShader::CPreProcessor::Begin(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::Begin(D3DXShader::CPreProcessor *this, unsigned int a2)
{
  D3DXShader::CPPBlock *v3; // eax
  unsigned int v4; // edx
  D3DXShader::CPPBlock *v5; // eax

  v3 = (D3DXShader::CPPBlock *)MemAlloc_Alloc(nSize: 0xCu);
  v4 = a2;
  if ( v3 != nullptr )
    v5 = D3DXShader::CPPBlock::CPPBlock(this: v3, a2);
  else
    v5 = nullptr;
  if ( v5 == nullptr )
    return -2147024882;
  *((_DWORD *)v5 + 1) = *((_DWORD *)this + 26);
  *((_DWORD *)this + 26) = v5;
  *((_DWORD *)this + 166) = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C0CFA
// Name: public: long D3DXShader::CPreProcessor::GetFileLine(char const __near * __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::GetFileLine(
        D3DXShader::CPreProcessor *this,
        const char **a2,
        unsigned int *a3)
{
  if ( a2 != nullptr )
    *a2 = *(const char **)(*((_DWORD *)this + 155) + 24);
  if ( a3 != nullptr )
    *a3 = *(_DWORD *)(*((_DWORD *)this + 155) + 28);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C0D29
// Name: public: long D3DXShader::CPreProcessor::GetBufferPointer(char const __near * __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::GetBufferPointer(
        D3DXShader::CPreProcessor *this,
        const char **a2,
        unsigned int *a3)
{
  int i; // eax
  unsigned int v4; // ecx
  const char *v5; // eax

  for ( i = *((_DWORD *)this + 154); *(_DWORD *)(i + 108) != 0; i = *(_DWORD *)(i + 108) )
    ;
  if ( a2 != nullptr )
    *a2 = *(const char **)i;
  if ( a3 != nullptr )
  {
    v4 = *(_DWORD *)(i + 4);
    v5 = *(const char **)i;
    if ( v4 < (unsigned int)v5 )
      *a3 = 0;
    else
      *a3 = v4 - (_DWORD)v5;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C0D69
// Name: protected: void D3DXShader::CPreProcessor::Error(char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void D3DXShader::CPreProcessor::Error(D3DXShader::CPreProcessor *this, char *format, ...)
{
  bool v2; // zf
  char string[256]; // [esp+4h] [ebp-104h] BYREF
  va_list ap; // [esp+118h] [ebp+10h] BYREF

  va_start(ap, format);
  v2 = *((_DWORD *)this + 20) == 0;
  *((_DWORD *)this + 17) = 1;
  if ( !v2 )
  {
    if ( strcmp(format, "syntax error") == 0 )
    {
      if ( *((_DWORD *)this + 19) != 0 && *((_DWORD *)this + 158) == 9 )
        D3DXShader::CTErrors::Error(
          this: (D3DXShader::CPreProcessor *)((char *)this + 24),
          a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
          a3: 0x5E0u,
          format: "invalid preprocessor command '%s'",
          *((const char **)this + 160));
      else
        D3DXShader::CTErrors::SyntaxError(
          this: (D3DXShader::CPreProcessor *)((char *)this + 24),
          a2: 0x5DCu,
          a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
    }
    else
    {
      _vsnprintf(string, count: 0x100u, format, ap);
      string[255] = 0;
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CPreProcessor *)((char *)this + 24),
        a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
        a3: 0,
        format: "%s",
        string);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C0E33
// Name: protected: long D3DXShader::CPreProcessor::DoLine(unsigned int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoLine(D3DXShader::CPreProcessor *this, unsigned int a2, const char *a3)
{
  *(_DWORD *)(*((_DWORD *)this + 155) + 28) = a2;
  if ( *((_DWORD *)this + 158) != 12 )
    --*(_DWORD *)(*((_DWORD *)this + 155) + 28);
  if ( a3 != nullptr )
    *(_DWORD *)(*((_DWORD *)this + 155) + 24) = a3;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C0E6C
// Name: protected: long D3DXShader::CPreProcessor::DoInclude(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
enum _D3DXINCLUDE_TYPE __thiscall D3DXShader::CPreProcessor::DoInclude(D3DXShader::CPreProcessor *this)
{
  _DWORD *v2; // edi
  enum _D3DXINCLUDE_TYPE result; // eax
  unsigned int v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // eax
  D3DXShader::CPPInclude *v8; // eax
  D3DXShader::CPPInclude *v9; // edi
  LPSTR FilePart; // [esp+8h] [ebp-21Ch] BYREF
  void *v11; // [esp+Ch] [ebp-218h]
  enum _D3DXINCLUDE_TYPE v12; // [esp+10h] [ebp-214h]
  LPCSTR lpFileName; // [esp+14h] [ebp-210h]
  char string[260]; // [esp+18h] [ebp-20Ch] BYREF
  char Buffer[260]; // [esp+11Ch] [ebp-108h] BYREF

  v2 = (_DWORD *)((char *)this + 632);
  result = D3DXShader::CTokenize::GetToken(
             this: *((D3DXShader::CTokenize **)this + 155),
             a2: *((_DWORD *)this + 166) | 0xC,
             a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
  v4 = 0;
  if ( result >= D3DXINC_LOCAL )
  {
    if ( *v2 == 10 )
    {
      v12 = D3DXINC_LOCAL;
    }
    else
    {
      if ( *v2 != 11 )
      {
        D3DXShader::CPreProcessor::Error(this, format: "syntax error");
        return -2147467259;
      }
      v12 = D3DXINC_SYSTEM;
    }
    v5 = *((_DWORD *)this + 156);
    lpFileName = *((LPCSTR *)this + 160);
    if ( v5 == 0 && *(_DWORD *)(*((_DWORD *)this + 155) + 24) == 0 )
    {
      D3DXShader::CTErrors::Error(
        this: (D3DXShader::CPreProcessor *)((char *)this + 24),
        a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
        a3: 0x5E1u,
        format: "include interface required to support #include from resource or memory");
LABEL_15:
      *((_DWORD *)this + 18) = 1;
      *((_DWORD *)this + 17) = 1;
      return -2147467259;
    }
    v6 = *((_DWORD *)this + 154);
    if ( v6 != 0 )
    {
      do
      {
        v6 = *(_DWORD *)(v6 + 108);
        ++v4;
      }
      while ( v6 != 0 );
      if ( v4 >= 0x20 )
      {
        D3DXShader::CTErrors::Error(
          this: (D3DXShader::CPreProcessor *)((char *)this + 24),
          a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
          a3: 0x5E2u,
          format: "too many nested #includes");
        goto LABEL_15;
      }
    }
    if ( v5 == 0 )
    {
      GetFullPathNameA(lpFileName, nBufferLength: 0x104u, lpBuffer: Buffer, lpFilePart: &FilePart);
      if ( strcmp(lpFileName, Buffer) != 0 )
      {
        _snprintf(string, count: 0x104u, format: "%s%s", *(const char **)(*((_DWORD *)this + 154) + 96), lpFileName);
        GetFullPathNameA(lpFileName: string, nBufferLength: 0x104u, lpBuffer: Buffer, lpFilePart: &FilePart);
      }
      lpFileName = Buffer;
    }
    v7 = *((_DWORD *)this + 154);
    if ( v7 != 0 && *(_DWORD *)(v7 + 88) != 0 )
      v11 = *(void **)(v7 + 100);
    else
      v11 = nullptr;
    v8 = (D3DXShader::CPPInclude *)MemAlloc_Alloc(nSize: 0x70u);
    if ( v8 != nullptr )
      v9 = D3DXShader::CPPInclude::CPPInclude(this: v8);
    else
      v9 = nullptr;
    if ( v9 != nullptr )
    {
      v12 = D3DXShader::CPPInclude::InitializeFromFile(
              this: v9,
              lpWideCharStr: lpFileName,
              a3: 0,
              a4: this,
              a5: (D3DXShader::CPreProcessor *)((char *)this + 632),
              a6: (D3DXShader::CPreProcessor *)((char *)this + 24),
              a7: *((struct ID3DXInclude **)this + 156),
              a8: v12,
              a9: v11);
      if ( v12 >= D3DXINC_LOCAL )
      {
        *((_DWORD *)v9 + 27) = *((_DWORD *)this + 154);
        *((_DWORD *)this + 154) = v9;
        return D3DXINC_LOCAL;
      }
      else
      {
        *((_DWORD *)this + 18) = 1;
        *((_DWORD *)this + 17) = 1;
        D3DXShader::CPPInclude::`scalar deleting destructor'(this: v9, a2: 1);
        return v12;
      }
    }
    else
    {
      return -2147024882;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C10A8
// Name: protected: long D3DXShader::CPreProcessor::DoError(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoError(D3DXShader::CPreProcessor *this)
{
  D3DXShader::CTokenize *v2; // ecx
  char *v3; // esi
  _BYTE *v4; // edx
  _BYTE *v5; // eax
  unsigned int v6; // ebx
  char v7; // cl
  unsigned int v8; // ebx
  unsigned int v10; // [esp+8h] [ebp-108h]
  char v11[256]; // [esp+Ch] [ebp-104h] BYREF

  v2 = *((D3DXShader::CTokenize **)this + 155);
  v3 = *(char **)v2;
  D3DXShader::CTokenize::SkipToEOL(this: v2);
  if ( *((_DWORD *)this + 20) != 0 )
  {
    while ( (unsigned int)v3 < **((_DWORD **)this + 155) && (*v3 == 32 || *v3 == 9) )
      ++v3;
    v10 = 0;
    v4 = v3 + 2;
    v5 = v3 + 1;
    while ( 1 )
    {
      v6 = **((_DWORD **)this + 155);
      if ( (unsigned int)v3 >= v6 )
      {
LABEL_21:
        v11[v10] = 0;
        D3DXShader::CTErrors::Error(
          this: (D3DXShader::CPreProcessor *)((char *)this + 24),
          a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
          a3: 0,
          format: "error: %s",
          v11);
        *((_DWORD *)this + 18) = 1;
        *((_DWORD *)this + 17) = 1;
        return 0;
      }
      v7 = *v3;
      if ( *v3 != 92 )
        break;
      if ( (unsigned int)v5 < v6 && *v5 == 10 )
      {
        v3 += 2;
        v5 += 2;
        v4 += 2;
      }
      else
      {
        if ( (unsigned int)v4 >= v6 || *v5 != 13 || *v4 != 10 )
          break;
        v3 += 3;
        v5 += 3;
        v4 += 3;
      }
LABEL_20:
      if ( v10 >= 0xFF )
        goto LABEL_21;
    }
    if ( v7 != 13 )
    {
      v8 = v10++;
      v11[v8] = v7;
    }
    ++v3;
    ++v5;
    ++v4;
    goto LABEL_20;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C11AB
// Name: protected: long D3DXShader::CPreProcessor::DoIf(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoIf(D3DXShader::CPreProcessor *this, int a2)
{
  D3DXShader::CPPConditional *v3; // eax
  D3DXShader::CPPConditional *v4; // eax
  BOOL v6; // eax

  v3 = (D3DXShader::CPPConditional *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v3 != nullptr )
    v4 = D3DXShader::CPPConditional::CPPConditional(this: v3, a2, a3: *((_DWORD *)this + 20));
  else
    v4 = nullptr;
  if ( v4 == nullptr )
    return -2147024882;
  *((_DWORD *)v4 + 3) = *(_DWORD *)(*((_DWORD *)this + 154) + 56);
  *(_DWORD *)(*((_DWORD *)this + 154) + 56) = v4;
  v6 = *((_DWORD *)this + 20) != 0 && a2 != 0;
  *((_DWORD *)this + 21) = v6;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C120B
// Name: protected: long D3DXShader::CPreProcessor::DoElif(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoElif(D3DXShader::CPreProcessor *this, int a2)
{
  _DWORD *v3; // eax
  BOOL v5; // ecx

  v3 = *(_DWORD **)(*((_DWORD *)this + 154) + 56);
  if ( v3 == nullptr )
  {
    D3DXShader::CTErrors::Error(
      this: (D3DXShader::CPreProcessor *)((char *)this + 24),
      a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
      a3: 0x5E4u,
      format: "unexpected #elif");
LABEL_5:
    *((_DWORD *)this + 17) = 1;
    return -2147467259;
  }
  if ( v3[2] != 0 )
  {
    D3DXShader::CTErrors::Error(
      this: (D3DXShader::CPreProcessor *)((char *)this + 24),
      a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
      a3: 0x5E9u,
      format: "unexpected #elif following #else");
    goto LABEL_5;
  }
  v5 = a2 != 0 && *v3 == 0 && v3[1] != 0;
  *((_DWORD *)this + 21) = v5;
  if ( a2 != 0 )
    *v3 = 1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C1288
// Name: protected: long D3DXShader::CPreProcessor::DoElse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoElse(D3DXShader::CPreProcessor *this)
{
  _DWORD *v2; // eax
  BOOL v3; // edx

  v2 = *(_DWORD **)(*((_DWORD *)this + 154) + 56);
  v3 = false;
  if ( v2 == nullptr )
  {
    D3DXShader::CTErrors::Error(
      this: (D3DXShader::CPreProcessor *)((char *)this + 24),
      a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
      a3: 0x5E5u,
      format: "unexpected #else");
LABEL_5:
    *((_DWORD *)this + 17) = 1;
    return -2147467259;
  }
  if ( v2[2] != 0 )
  {
    D3DXShader::CTErrors::Error(
      this: (D3DXShader::CPreProcessor *)((char *)this + 24),
      a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
      a3: 0x5EAu,
      format: "unexpected #else following #else");
    goto LABEL_5;
  }
  if ( *v2 == 0 )
    v3 = v2[1] != 0;
  *((_DWORD *)this + 21) = v3;
  *v2 = 1;
  v2[2] = 1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C12F2
// Name: protected: long D3DXShader::CPreProcessor::DoEndif(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoEndif(D3DXShader::CPreProcessor *this)
{
  int v2; // eax
  D3DXShader::CPPDefine *v3; // ecx

  v2 = *((_DWORD *)this + 154);
  v3 = *(D3DXShader::CPPDefine **)(v2 + 56);
  if ( v3 != nullptr )
  {
    *((_DWORD *)this + 21) = *((_DWORD *)v3 + 1);
    *(_DWORD *)(v2 + 56) = *((_DWORD *)v3 + 3);
    *((_DWORD *)v3 + 3) = 0;
    D3DXShader::CPPDefine::`scalar deleting destructor'(this: v3, a2: 1);
    return 0;
  }
  else
  {
    D3DXShader::CTErrors::Error(
      this: (D3DXShader::CPreProcessor *)((char *)this + 24),
      a2: (D3DXShader::CPreProcessor *)((char *)this + 632),
      a3: 0x5E6u,
      format: "unexpected #endif");
    *((_DWORD *)this + 17) = 1;
    return -2147467259;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C134A
// Name: protected: long D3DXShader::CPreProcessor::DoPragmaPackMatrix(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoPragmaPackMatrix(D3DXShader::CPreProcessor *this)
{
  int *v2; // esi
  int result; // eax
  int v4; // eax
  int *v5; // esi
  int *v6; // esi
  const char *v7; // [esp+8h] [ebp-4h]

  v2 = (int *)((char *)this + 632);
  result = D3DXShader::CTokenize::GetToken(
             this: *((D3DXShader::CTokenize **)this + 155),
             a2: *((_DWORD *)this + 166),
             a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
  if ( result >= 0 )
  {
    v4 = *v2;
    if ( *v2 != 1 || strcmp((const char *)this + 640, "(") != 0 )
      goto LABEL_20;
    v5 = (int *)((char *)this + 632);
    result = D3DXShader::CTokenize::GetToken(
               this: *((D3DXShader::CTokenize **)this + 155),
               a2: *((_DWORD *)this + 166),
               a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
    if ( result >= 0 )
    {
      if ( *v5 == 9 )
      {
        v7 = *((const char **)this + 160);
        result = D3DXShader::CTokenize::GetToken(
                   this: *((D3DXShader::CTokenize **)this + 155),
                   a2: *((_DWORD *)this + 166),
                   a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
        if ( result < 0 )
          goto LABEL_24;
      }
      else
      {
        v7 = nullptr;
      }
      v4 = *v5;
      if ( *v5 != 1 || strcmp((const char *)this + 640, ")") != 0 )
        goto LABEL_20;
      v6 = (int *)((char *)this + 632);
      result = D3DXShader::CTokenize::GetToken(
                 this: *((D3DXShader::CTokenize **)this + 155),
                 a2: *((_DWORD *)this + 166),
                 a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
      if ( result >= 0 )
      {
        v4 = *v6;
        if ( *v6 == 12 || v4 == 13 )
        {
          if ( v7 == nullptr )
          {
            *((_DWORD *)this + 14) = 0;
LABEL_23:
            result = 0;
            goto LABEL_24;
          }
          if ( strcmp(v7, "row_major") == 0 )
          {
            *((_DWORD *)this + 14) = 1024;
            goto LABEL_23;
          }
          if ( strcmp(v7, "column_major") == 0 )
          {
            *((_DWORD *)this + 14) = 2048;
            goto LABEL_23;
          }
        }
LABEL_20:
        if ( v4 != 12 && v4 != 13 )
          D3DXShader::CTokenize::SkipToEOL(this: *((D3DXShader::CTokenize **)this + 155));
        goto LABEL_23;
      }
    }
  }
LABEL_24:
  *((_DWORD *)this + 16) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C1489
// Name: protected: long D3DXShader::CPreProcessor::DoPragmaWarning(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoPragmaWarning(D3DXShader::CPreProcessor *this)
{
  _DWORD *v2; // edi
  int Token; // esi
  int v4; // eax
  unsigned int v5; // eax
  int v6; // eax
  unsigned int v7; // esi
  int v8; // eax
  void *v9; // edi
  int v10; // eax
  unsigned int *v11; // edi
  int v12; // eax
  int v14; // edi
  unsigned int *v15; // edi
  int i; // eax
  unsigned int v17; // [esp+Ch] [ebp-18h]
  unsigned int v18; // [esp+10h] [ebp-14h]
  int v19; // [esp+14h] [ebp-10h]
  unsigned int *v20; // [esp+18h] [ebp-Ch]
  _BYTE *pMem; // [esp+1Ch] [ebp-8h]
  unsigned int v22; // [esp+20h] [ebp-4h]

  pMem = nullptr;
  v20 = nullptr;
  v2 = (_DWORD *)((char *)this + 632);
  Token = D3DXShader::CTokenize::GetToken(
            this: *((D3DXShader::CTokenize **)this + 155),
            a2: *((_DWORD *)this + 166),
            a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
  if ( Token < 0 )
    goto LABEL_52;
  if ( *v2 != 1 || strcmp((const char *)this + 640, "(") != 0 )
    goto LABEL_48;
  Token = D3DXShader::CTokenize::GetToken(
            this: *((D3DXShader::CTokenize **)this + 155),
            a2: *((_DWORD *)this + 166),
            a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
  if ( Token < 0 )
    goto LABEL_52;
  v22 = 0;
LABEL_6:
  v4 = *((_DWORD *)this + 158);
  if ( v4 == 1 && strcmp((const char *)this + 640, ")") == 0 )
  {
    Token = D3DXShader::CTokenize::GetToken(
              this: *((D3DXShader::CTokenize **)this + 155),
              a2: *((_DWORD *)this + 166),
              a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
    if ( Token < 0 )
      goto LABEL_52;
    v14 = *((_DWORD *)this + 158);
    if ( v14 != 12 && v14 != 13 )
      goto LABEL_48;
    v18 = 0;
    if ( v22 == 0 )
    {
LABEL_51:
      Token = 0;
      goto LABEL_52;
    }
    v15 = v20;
    for ( i = pMem - (_BYTE *)v20; ; i = pMem - (_BYTE *)v20 )
    {
      Token = D3DXShader::CTErrors::SetWarningSpecifier(
                this: (D3DXShader::CPreProcessor *)((char *)this + 24),
                a2: *v15,
                a3: *(unsigned int *)((char *)v15 + i));
      if ( Token < 0 )
        break;
      ++v18;
      ++v15;
      if ( v18 >= v22 )
        goto LABEL_51;
    }
    goto LABEL_52;
  }
  if ( v4 == 9 )
  {
    if ( strcmp(*((const char **)this + 160), "once") == 0 )
    {
      v19 = 16;
    }
    else if ( strcmp(*((const char **)this + 160), "error") == 0 )
    {
      v19 = 15;
    }
    else if ( strcmp(*((const char **)this + 160), "disable") == 0 )
    {
      v19 = 0;
    }
    else
    {
      if ( strcmp(*((const char **)this + 160), "default") != 0 )
        goto LABEL_48;
      v19 = 255;
    }
  }
  else
  {
    if ( v4 != 2 && v4 != 3 && v4 != 4 )
      goto LABEL_48;
    v5 = *((_DWORD *)this + 160);
    if ( v5 == 0 || v5 > 4 )
      goto LABEL_48;
    v19 = *((_DWORD *)this + 160);
  }
  Token = D3DXShader::CTokenize::GetToken(
            this: *((D3DXShader::CTokenize **)this + 155),
            a2: *((_DWORD *)this + 166),
            a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
  if ( Token < 0 )
    goto LABEL_52;
  if ( *((_DWORD *)this + 158) != 1 || strcmp((const char *)this + 640, ":") != 0 )
  {
LABEL_48:
    v12 = *((_DWORD *)this + 158);
    if ( v12 != 12 && v12 != 13 )
      D3DXShader::CTokenize::SkipToEOL(this: *((D3DXShader::CTokenize **)this + 155));
    goto LABEL_51;
  }
  Token = D3DXShader::CTokenize::GetToken(
            this: *((D3DXShader::CTokenize **)this + 155),
            a2: *((_DWORD *)this + 166),
            a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
  if ( Token >= 0 )
  {
    while ( 1 )
    {
      v6 = *((_DWORD *)this + 158);
      if ( v6 != 2 && v6 != 3 && v6 != 4 )
        goto LABEL_48;
      v7 = v22;
      v17 = *((_DWORD *)this + 160);
      if ( v22 == (v22 & -v22) )
      {
        if ( v22 != 0 )
          v8 = 2 * v22;
        else
          v8 = 1;
        v9 = MemAlloc_Alloc(nSize: 4 * v8);
        if ( v9 == nullptr
          || ((qmemcpy(v9, pMem, 4 * v22), free(pMem), pMem = v9, v22 == 0) ? (v10 = 1) : (v10 = 2 * v22),
              (v11 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * v10)) == nullptr) )
        {
          Token = -2147024882;
          break;
        }
        qmemcpy(v11, v20, 4 * v22);
        free(pMem: v20);
        v7 = v22;
        v20 = v11;
      }
      v20[v7] = v17;
      *(_DWORD *)&pMem[4 * v7] = v19;
      v22 = v7 + 1;
      Token = D3DXShader::CTokenize::GetToken(
                this: *((D3DXShader::CTokenize **)this + 155),
                a2: *((_DWORD *)this + 166),
                a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
      if ( Token < 0 )
        break;
      if ( *((_DWORD *)this + 158) == 1
        && (strcmp((const char *)this + 640, ";") == 0 || strcmp((const char *)this + 640, ")") == 0) )
      {
        if ( strcmp((const char *)this + 640, ";") != 0 )
          goto LABEL_6;
        Token = D3DXShader::CTokenize::GetToken(
                  this: *((D3DXShader::CTokenize **)this + 155),
                  a2: *((_DWORD *)this + 166),
                  a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
        if ( Token < 0 )
          break;
        if ( *((_DWORD *)this + 158) != 1 || strcmp((const char *)this + 640, ")") != 0 )
          goto LABEL_6;
        goto LABEL_48;
      }
    }
  }
LABEL_52:
  free(pMem);
  free(pMem: v20);
  free(pMem: nullptr);
  *((_DWORD *)this + 16) = 1;
  return Token;
}

//------------------------------------------------------------------------------
// Address: 0x101C1871
// Name: protected: long D3DXShader::CPreProcessor::DoPragmaDef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::DoPragmaDef(D3DXShader::CPreProcessor *this)
{
  _DWORD *v2; // esi
  int result; // eax
  D3DXShader::CTokenize *v4; // ecx
  int v5; // eax
  D3DXShader::CTokenize *v6; // ecx
  D3DXShader::CTokenize *v7; // ecx
  int v8; // eax
  double v9; // st7
  double *v10; // eax
  bool v11; // zf
  int v12; // esi
  char *v13; // eax
  _DWORD *v14; // esi
  int v15; // ecx
  int v16; // eax
  unsigned int v17; // [esp-Ch] [ebp-48h]
  _QWORD v18[4]; // [esp+8h] [ebp-34h] BYREF
  int v19; // [esp+2Ch] [ebp-10h]
  int v20; // [esp+30h] [ebp-Ch]
  int v21; // [esp+34h] [ebp-8h]
  unsigned int v22; // [esp+38h] [ebp-4h]

  v2 = (_DWORD *)((char *)this + 632);
  result = D3DXShader::CTokenize::GetToken(
             this: *((D3DXShader::CTokenize **)this + 155),
             a2: *((_DWORD *)this + 166),
             a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
  if ( result >= 0 )
  {
    if ( *v2 == 1 && strcmp((const char *)this + 640, "(") == 0 )
    {
      result = D3DXShader::CTokenize::GetToken(
                 this: *((D3DXShader::CTokenize **)this + 155),
                 a2: *((_DWORD *)this + 166),
                 a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
      if ( result < 0 )
        goto LABEL_52;
      if ( *((_DWORD *)this + 158) == 9 )
      {
        v4 = *((D3DXShader::CTokenize **)this + 155);
        v17 = *((_DWORD *)this + 166);
        v20 = *((_DWORD *)this + 160);
        result = D3DXShader::CTokenize::GetToken(
                   this: v4,
                   a2: v17,
                   a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
        if ( result < 0 )
          goto LABEL_52;
        if ( *((_DWORD *)this + 158) == 1 && strcmp((const char *)this + 640, ",") == 0 )
        {
          result = D3DXShader::CTokenize::GetToken(
                     this: *((D3DXShader::CTokenize **)this + 155),
                     a2: *((_DWORD *)this + 166),
                     a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
          if ( result < 0 )
            goto LABEL_52;
          if ( *((_DWORD *)this + 158) == 9 )
          {
            v5 = *((_DWORD *)this + 160);
            v22 = 0;
            v19 = v5;
            while ( 1 )
            {
              v6 = *((D3DXShader::CTokenize **)this + 155);
              v21 = 0;
              result = D3DXShader::CTokenize::GetToken(
                         this: v6,
                         a2: *((_DWORD *)this + 166),
                         a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
              if ( result < 0 )
                goto LABEL_52;
              if ( *((_DWORD *)this + 158) != 1 || strcmp((const char *)this + 640, ",") != 0 )
                goto LABEL_48;
              result = D3DXShader::CTokenize::GetToken(
                         this: *((D3DXShader::CTokenize **)this + 155),
                         a2: *((_DWORD *)this + 166),
                         a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
              if ( result < 0 )
                goto LABEL_52;
              if ( *((_DWORD *)this + 158) == 1 && strcmp((const char *)this + 640, "-") == 0 )
              {
                v7 = *((D3DXShader::CTokenize **)this + 155);
                v21 = 1;
                result = D3DXShader::CTokenize::GetToken(
                           this: v7,
                           a2: *((_DWORD *)this + 166),
                           a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
                if ( result < 0 )
                  goto LABEL_52;
              }
              v8 = *((_DWORD *)this + 158);
              if ( v8 == 2 )
                goto LABEL_26;
              if ( v8 != 3 )
                break;
              v9 = (double)*((int *)this + 160);
              v10 = (double *)&v18[v22];
LABEL_27:
              v11 = v21 == 0;
              *v10 = v9;
              if ( !v11 )
                *v10 = -*v10;
              if ( ++v22 >= 4 )
              {
                result = D3DXShader::CTokenize::GetToken(
                           this: *((D3DXShader::CTokenize **)this + 155),
                           a2: *((_DWORD *)this + 166),
                           a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
                if ( result < 0 )
                  goto LABEL_52;
                if ( *((_DWORD *)this + 158) != 1 || strcmp((const char *)this + 640, ")") != 0 )
                  goto LABEL_48;
                result = D3DXShader::CTokenize::GetToken(
                           this: *((D3DXShader::CTokenize **)this + 155),
                           a2: *((_DWORD *)this + 166),
                           a3: (D3DXShader::CPreProcessor *)((char *)this + 632));
                if ( result < 0 )
                  goto LABEL_52;
                v12 = *((_DWORD *)this + 158);
                if ( v12 != 12 && v12 != 13 )
                  goto LABEL_48;
                v13 = (char *)MemAlloc_Alloc(nSize: 0x30u);
                if ( v13 != nullptr )
                {
                  *((_DWORD *)v13 + 10) = 0;
                  v22 = (unsigned int)v13;
                }
                else
                {
                  v22 = 0;
                  v13 = nullptr;
                }
                if ( v13 == nullptr )
                {
                  result = -2147024882;
                  goto LABEL_52;
                }
                *(_DWORD *)v13 = v20;
                *((_DWORD *)v13 + 1) = v19;
                qmemcpy(v13 + 8, v18, 32);
                v14 = (_DWORD *)((char *)this + 60);
                v15 = *((_DWORD *)this + 15);
                if ( v15 != 0 )
                {
                  while ( _stricmp(dst: *(const char **)(v15 + 4), src: *((const char **)v13 + 1)) < 0 )
                  {
                    v14 = (_DWORD *)(*v14 + 40);
                    v15 = *v14;
                    if ( *v14 == 0 )
                      break;
                    v13 = (char *)v22;
                  }
                  v13 = (char *)v22;
                }
                *((_DWORD *)v13 + 10) = *v14;
                *v14 = v13;
                goto LABEL_51;
              }
            }
            if ( v8 != 4 )
            {
              if ( v8 <= 4 || v8 > 8 )
                goto LABEL_48;
              v9 = *((double *)this + 80);
              v10 = (double *)&v18[v22];
              goto LABEL_27;
            }
LABEL_26:
            v9 = (double)*((unsigned int *)this + 160);
            v10 = (double *)&v18[v22];
            goto LABEL_27;
          }
        }
      }
    }
LABEL_48:
    v16 = *((_DWORD *)this + 158);
    if ( v16 != 12 && v16 != 13 )
      D3DXShader::CTokenize::SkipToEOL(this: *((D3DXShader::CTokenize **)this + 155));
LABEL_51:
    result = 0;
  }
LABEL_52:
  *((_DWORD *)this + 16) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C1B8A
// Name: protected: unsigned int D3DXShader::CPreProcessor::Hash(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CPreProcessor::Hash(D3DXShader::CPreProcessor *this, const char *a2)
{
  const char *v2; // edx
  unsigned int v3; // eax
  char v4; // cl

  v2 = a2;
  v3 = 103995407;
  if ( a2 == nullptr )
    return 0;
  v4 = *a2;
  if ( *a2 == 0 )
    return 0;
  do
  {
    v3 = v4 + 19 * v3;
    v4 = *++v2;
  }
  while ( *v2 != 0 );
  return v3 % 0x7F;
}

//------------------------------------------------------------------------------
// Address: 0x101C1BC1
// Name: protected: int D3DXShader::CPreProcessor::AreDefinesIdentical(class D3DXShader::CPPDefine __near *,class D3DXShader::CPPDefine __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CPreProcessor::AreDefinesIdentical(
        D3DXShader::CPreProcessor *this,
        const char **a2,
        const char **a3)
{
  const char *v3; // eax
  const char *v4; // ecx
  const char *v5; // edx
  struct D3DXShader::CPPDefine *i; // ecx
  int v7; // eax
  BOOL v8; // eax
  _BYTE *v10; // esi
  _BYTE *v11; // eax
  bool v12; // cf
  unsigned __int8 v13; // bl
  int v14; // eax
  const char *v15; // edi
  const char *j; // edi
  int v17; // eax
  _BYTE *v18; // esi
  _BYTE *v19; // eax
  unsigned __int8 v20; // bl
  const char *v21; // [esp+Ch] [ebp-Ch]
  const char *v22; // [esp+10h] [ebp-8h]
  int v23; // [esp+14h] [ebp-4h]
  int v24; // [esp+20h] [ebp+8h]
  struct D3DXShader::CPPDefine *v25; // [esp+24h] [ebp+Ch]

  if ( strcmp(*a2, *a3) != 0 )
    return false;
  v3 = a2[1];
  v4 = a3[1];
  v22 = v3;
  v21 = v4;
  if ( v3 != nullptr )
  {
    do
    {
      if ( v4 == nullptr )
        break;
      v3 = *((const char **)v3 + 3);
      v4 = *((const char **)v4 + 3);
    }
    while ( v3 != nullptr );
    if ( v3 != nullptr )
      return false;
  }
  if ( v4 != nullptr )
    return false;
  v5 = a2[2];
  for ( i = (struct D3DXShader::CPPDefine *)a3[2]; ; i = *((struct D3DXShader::CPPDefine **)i + 3) )
  {
    v25 = i;
    if ( v5 == nullptr )
      break;
    if ( i == nullptr )
      return false;
    v7 = *((_DWORD *)v5 + 4);
    if ( v7 != *((_DWORD *)i + 4) )
      return false;
    if ( v7 > 8 )
    {
      if ( v7 == 9 )
      {
        v15 = v22;
        v23 = 0;
        v24 = 1;
        if ( v22 != nullptr )
        {
          while ( strcmp(*((const char **)v5 + 6), *((const char **)v15 + 6)) != 0 )
          {
            v15 = *((const char **)v15 + 3);
            ++v24;
            if ( v15 == nullptr )
              goto LABEL_38;
          }
          v23 = 1;
        }
LABEL_38:
        for ( j = v21; ; j = *((const char **)j + 3) )
        {
          --v24;
          if ( j == nullptr )
            break;
          v17 = strcmp(*((const char **)i + 6), *((const char **)j + 6));
          i = v25;
          if ( v17 == 0 )
          {
            v23 = 1;
            break;
          }
        }
        if ( v23 != 0 )
        {
          v8 = v24 == 0;
          goto LABEL_54;
        }
        v18 = *((_BYTE **)i + 6);
        v19 = *((_BYTE **)v5 + 6);
        while ( 1 )
        {
          v12 = *v19 < *v18;
          if ( *v19 != *v18 )
            break;
          if ( *v19 != 0 )
          {
            v20 = v19[1];
            v12 = v20 < v18[1];
            if ( v20 != v18[1] )
              break;
            v19 += 2;
            v18 += 2;
            if ( v20 != 0 )
              continue;
          }
LABEL_32:
          v14 = 0;
          goto LABEL_53;
        }
      }
      else
      {
        if ( v7 > 11 )
          goto LABEL_55;
        v10 = *((_BYTE **)i + 6);
        v11 = *((_BYTE **)v5 + 6);
        while ( 1 )
        {
          v12 = *v11 < *v10;
          if ( *v11 != *v10 )
            break;
          if ( *v11 == 0 )
            goto LABEL_32;
          v13 = v11[1];
          v12 = v13 < v10[1];
          if ( v13 != v10[1] )
            break;
          v11 += 2;
          v10 += 2;
          if ( v13 == 0 )
            goto LABEL_32;
        }
      }
      v14 = -v12 - (v12 - 1);
LABEL_53:
      v8 = v14 == 0;
      i = v25;
LABEL_54:
      if ( !v8 )
        return false;
      goto LABEL_55;
    }
    if ( v7 >= 5 )
    {
      if ( *((double *)v5 + 3) != *((double *)i + 3) )
        return false;
      goto LABEL_55;
    }
    if ( v7 == 0 )
      goto LABEL_15;
    if ( v7 != 1 )
    {
      if ( v7 <= 1 )
        goto LABEL_55;
LABEL_15:
      v8 = *((_DWORD *)i + 6) == *((_DWORD *)v5 + 6);
      goto LABEL_54;
    }
    if ( v5[24] != *((_BYTE *)i + 24)
      || v5[25] != *((_BYTE *)i + 25)
      || v5[26] != *((_BYTE *)i + 26)
      || v5[27] != *((_BYTE *)i + 27) )
    {
      return false;
    }
LABEL_55:
    v5 = *((const char **)v5 + 3);
  }
  return i == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101C1E2D
// Name: protected: int D3DXShader::CPreProcessor::IsDefineRecursive(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CPreProcessor::IsDefineRecursive(D3DXShader::CPreProcessor *this, char *a2)
{
  int i; // esi
  int v4; // eax
  int v6; // edi

  for ( i = *((_DWORD *)this + D3DXShader::CPreProcessor::Hash(this, a2) + 27); ; i = *(_DWORD *)(i + 12) )
  {
    if ( i == 0 )
      return false;
    v4 = strcmp(a2, *(const char **)i);
    if ( v4 < 0 )
      return false;
    if ( v4 == 0 )
      break;
  }
  if ( *(_DWORD *)(i + 16) != 0 )
    return true;
  v6 = *(_DWORD *)(i + 8);
  *(_DWORD *)(i + 16) = 1;
  while ( v6 != 0
       && (*(_DWORD *)(v6 + 16) != 9
        || D3DXShader::CPreProcessor::IsDefineRecursive(this, a2: *(const char **)(v6 + 24)) == 0) )
    v6 = *(_DWORD *)(v6 + 12);
  *(_DWORD *)(i + 16) = 0;
  return v6 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C1EC6
// Name: protected: int D3DXShader::CPreProcessor::FindDefine(char const __near *,class D3DXShader::CNode __near * __near *,class D3DXShader::CNode __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPreProcessor::FindDefine(
        D3DXShader::CPreProcessor *this,
        char *a2,
        struct D3DXShader::CNode **a3,
        struct D3DXShader::CNode **a4)
{
  int i; // esi
  int v7; // eax

  if ( D3DXShader::CPreProcessor::IsDefineRecursive(this, a2) )
    return 0;
  for ( i = *((_DWORD *)this + D3DXShader::CPreProcessor::Hash(this, a2) + 27); ; i = *(_DWORD *)(i + 12) )
  {
    if ( i == 0 )
      return 0;
    v7 = strcmp(a2, *(const char **)i);
    if ( v7 < 0 )
      return 0;
    if ( v7 == 0 )
      break;
  }
  if ( a3 != nullptr )
    *a3 = *(struct D3DXShader::CNode **)(i + 4);
  if ( a4 != nullptr )
    *a4 = *(struct D3DXShader::CNode **)(i + 8);
  return 1;
}
