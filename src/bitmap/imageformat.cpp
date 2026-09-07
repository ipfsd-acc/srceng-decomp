// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/imageformat.cpp
// Functions: 4
// ============================================================

#include "bitmap\imageformat.h"

//------------------------------------------------------------------------------
// Address: 0x10219540
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10219560
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x10219590
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10219600
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x10227120
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10227140
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x10227170
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102271E0
// Name: enum ImageFormat ImageLoader::D3DFormatToImageFormat(enum _D3DFORMAT)
// Source: json
//------------------------------------------------------------------------------
ImageFormat __cdecl ImageLoader::D3DFormatToImageFormat(_D3DFORMAT format)
{
  ImageFormat result; // eax

  if ( format > 826889281 )
  {
    if ( format > D3DFMT_DXT3 )
    {
      if ( format == D3DFMT_DXT5 )
        return IMAGE_FORMAT_DXT5;
      if ( format == 1280070990 )
        return IMAGE_FORMAT_NULL;
    }
    else
    {
      switch ( format )
      {
        case 861165636:
          return IMAGE_FORMAT_DXT3;
        case 827611204:
          return IMAGE_FORMAT_DXT1;
        case 843666497:
          return IMAGE_FORMAT_ATI2N;
        default:
          break;
      }
    }
    return IMAGE_FORMAT_UNKNOWN;
  }
  if ( format == 826889281 )
    return IMAGE_FORMAT_ATI1N;
  switch ( format )
  {
    case D3DFMT_R8G8B8:
      result = IMAGE_FORMAT_BGR888;
      break;
    case D3DFMT_A8R8G8B8:
      result = IMAGE_FORMAT_BGRA8888;
      break;
    case D3DFMT_X8R8G8B8:
      result = IMAGE_FORMAT_BGRX8888;
      break;
    case D3DFMT_R5G6B5:
      result = IMAGE_FORMAT_BGR565;
      break;
    case D3DFMT_X1R5G5B5:
      result = IMAGE_FORMAT_BGRX5551;
      break;
    case D3DFMT_A1R5G5B5:
      result = IMAGE_FORMAT_BGRA5551;
      break;
    case D3DFMT_A4R4G4B4:
      result = IMAGE_FORMAT_BGRA4444;
      break;
    case D3DFMT_A8:
      result = IMAGE_FORMAT_A8;
      break;
    case D3DFMT_A2B10G10R10:
      result = IMAGE_FORMAT_RGBA1010102;
      break;
    case D3DFMT_A8B8G8R8:
      result = IMAGE_FORMAT_RGBA8888;
      break;
    case D3DFMT_X8B8G8R8:
      result = IMAGE_FORMAT_RGBX8888;
      break;
    case D3DFMT_A2R10G10B10:
      result = IMAGE_FORMAT_BGRA1010102;
      break;
    case D3DFMT_A16B16G16R16:
      result = IMAGE_FORMAT_RGBA16161616;
      break;
    case D3DFMT_P8:
      result = IMAGE_FORMAT_P8;
      break;
    case D3DFMT_L8:
      result = IMAGE_FORMAT_I8;
      break;
    case D3DFMT_A8L8:
      result = IMAGE_FORMAT_IA88;
      break;
    case D3DFMT_V8U8:
      result = IMAGE_FORMAT_UV88;
      break;
    case D3DFMT_X8L8V8U8:
      result = IMAGE_FORMAT_UVLX8888;
      break;
    case D3DFMT_Q8W8V8U8:
      result = IMAGE_FORMAT_UVWQ8888;
      break;
    case D3DFMT_D32:
      result = IMAGE_FORMAT_D32;
      break;
    case D3DFMT_D15S1:
      result = IMAGE_FORMAT_D15S1;
      break;
    case D3DFMT_D24S8:
      result = IMAGE_FORMAT_D24S8;
      break;
    case D3DFMT_D24X8:
      result = IMAGE_FORMAT_D24X8;
      break;
    case D3DFMT_D24X4S4:
      result = IMAGE_FORMAT_D24X4S4;
      break;
    case D3DFMT_D16:
      result = IMAGE_FORMAT_D16;
      break;
    case D3DFMT_D24FS8:
      result = IMAGE_FORMAT_D24FS8;
      break;
    case D3DFMT_R16F:
      result = IMAGE_FORMAT_R16F;
      break;
    case D3DFMT_G16R16F:
      result = IMAGE_FORMAT_RG1616F;
      break;
    case D3DFMT_A16B16G16R16F:
      result = IMAGE_FORMAT_RGBA16161616F;
      break;
    case D3DFMT_R32F:
      result = IMAGE_FORMAT_R32F;
      break;
    case D3DFMT_G32R32F:
      result = IMAGE_FORMAT_RG3232F;
      break;
    case D3DFMT_A32B32G32R32F:
      result = IMAGE_FORMAT_RGBA32323232F;
      break;
    default:
      return IMAGE_FORMAT_UNKNOWN;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10227440
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace MaterialSystem

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x10032050
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10032070
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x100320A0
// Name: enum ImageFormat ImageLoader::D3DFormatToImageFormat(enum _D3DFORMAT)
// Source: json
//------------------------------------------------------------------------------
ImageFormat __cdecl ImageLoader::D3DFormatToImageFormat(_D3DFORMAT format)
{
  ImageFormat result; // eax

  if ( format > 826889281 )
  {
    if ( format > D3DFMT_DXT3 )
    {
      if ( format == D3DFMT_DXT5 )
        return IMAGE_FORMAT_DXT5;
      if ( format == 1280070990 )
        return IMAGE_FORMAT_NULL;
    }
    else
    {
      switch ( format )
      {
        case 861165636:
          return IMAGE_FORMAT_DXT3;
        case 827611204:
          return IMAGE_FORMAT_DXT1;
        case 843666497:
          return IMAGE_FORMAT_ATI2N;
        default:
          break;
      }
    }
    return IMAGE_FORMAT_UNKNOWN;
  }
  if ( format == 826889281 )
    return IMAGE_FORMAT_ATI1N;
  switch ( format )
  {
    case D3DFMT_R8G8B8:
      result = IMAGE_FORMAT_BGR888;
      break;
    case D3DFMT_A8R8G8B8:
      result = IMAGE_FORMAT_BGRA8888;
      break;
    case D3DFMT_X8R8G8B8:
      result = IMAGE_FORMAT_BGRX8888;
      break;
    case D3DFMT_R5G6B5:
      result = IMAGE_FORMAT_BGR565;
      break;
    case D3DFMT_X1R5G5B5:
      result = IMAGE_FORMAT_BGRX5551;
      break;
    case D3DFMT_A1R5G5B5:
      result = IMAGE_FORMAT_BGRA5551;
      break;
    case D3DFMT_A4R4G4B4:
      result = IMAGE_FORMAT_BGRA4444;
      break;
    case D3DFMT_A8:
      result = IMAGE_FORMAT_A8;
      break;
    case D3DFMT_A2B10G10R10:
      result = IMAGE_FORMAT_RGBA1010102;
      break;
    case D3DFMT_A8B8G8R8:
      result = IMAGE_FORMAT_RGBA8888;
      break;
    case D3DFMT_X8B8G8R8:
      result = IMAGE_FORMAT_RGBX8888;
      break;
    case D3DFMT_A2R10G10B10:
      result = IMAGE_FORMAT_BGRA1010102;
      break;
    case D3DFMT_A16B16G16R16:
      result = IMAGE_FORMAT_RGBA16161616;
      break;
    case D3DFMT_P8:
      result = IMAGE_FORMAT_P8;
      break;
    case D3DFMT_L8:
      result = IMAGE_FORMAT_I8;
      break;
    case D3DFMT_A8L8:
      result = IMAGE_FORMAT_IA88;
      break;
    case D3DFMT_V8U8:
      result = IMAGE_FORMAT_UV88;
      break;
    case D3DFMT_X8L8V8U8:
      result = IMAGE_FORMAT_UVLX8888;
      break;
    case D3DFMT_Q8W8V8U8:
      result = IMAGE_FORMAT_UVWQ8888;
      break;
    case D3DFMT_D32:
      result = IMAGE_FORMAT_D32;
      break;
    case D3DFMT_D15S1:
      result = IMAGE_FORMAT_D15S1;
      break;
    case D3DFMT_D24S8:
      result = IMAGE_FORMAT_D24S8;
      break;
    case D3DFMT_D24X8:
      result = IMAGE_FORMAT_D24X8;
      break;
    case D3DFMT_D24X4S4:
      result = IMAGE_FORMAT_D24X4S4;
      break;
    case D3DFMT_D16:
      result = IMAGE_FORMAT_D16;
      break;
    case D3DFMT_D24FS8:
      result = IMAGE_FORMAT_D24FS8;
      break;
    case D3DFMT_R16F:
      result = IMAGE_FORMAT_R16F;
      break;
    case D3DFMT_G16R16F:
      result = IMAGE_FORMAT_RG1616F;
      break;
    case D3DFMT_A16B16G16R16F:
      result = IMAGE_FORMAT_RGBA16161616F;
      break;
    case D3DFMT_R32F:
      result = IMAGE_FORMAT_R32F;
      break;
    case D3DFMT_G32R32F:
      result = IMAGE_FORMAT_RG3232F;
      break;
    case D3DFMT_A32B32G32R32F:
      result = IMAGE_FORMAT_RGBA32323232F;
      break;
    default:
      return IMAGE_FORMAT_UNKNOWN;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032300
// Name: enum _D3DFORMAT ImageLoader::ImageFormatToD3DFormat(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
_D3DFORMAT __cdecl ImageLoader::ImageFormatToD3DFormat(ImageFormat format)
{
  return s_pD3DFormats[format + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10032310
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032480
// Name: unsigned long GetProcessorCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl GetProcessorCount()
{
  struct _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  return SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x100328A0
// Name: public: CATICompressThreadData::CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::CATICompressThreadData(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100328B0
// Name: public: CATICompressThreadData::~CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::~CATICompressThreadData(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*this;
  if ( v2 != nullptr )
  {
    (**v2)(a1: v2, a2: 1);
    *this = 0;
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*(this + 1);
  if ( v3 != nullptr )
  {
    (**v3)(a1: v3, a2: 1);
    *(this + 1) = 0;
  }
  v4 = (void (__thiscall ***)(_DWORD, int))*(this + 2);
  if ( v4 != nullptr )
  {
    (**v4)(a1: v4, a2: 1);
    *(this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032900
// Name: unsigned long ThreadedCompressProc(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall ThreadedCompressProc(_DWORD *a1)
{
  unsigned int v1; // esi
  int v2; // edi

  v1 = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0x8001Fu, mask: 0x8001Fu);
  v2 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*a1 + 32))(
         a1: *a1,
         a2: a1[1],
         a3: a1[2],
         a4: a1[3],
         a5: a1[4],
         a6: a1[5]);
  _controlfp(newctrl: v1, mask: 0x8001Fu);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10033460
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x100337A0
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033810
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10033920
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x100339E0
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace shaderapidx9

// ============================================================
// Overlay from Dist2alpha (Missing functions)
// ============================================================
namespace Dist2alpha {

//------------------------------------------------------------------------------
// Address: 0x00404810
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x00404830
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x00404860
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace Dist2alpha

// ============================================================
// Overlay from dumpworld (Missing functions)
// ============================================================
namespace dumpworld {

//------------------------------------------------------------------------------
// Address: 0x00406C10
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

} // namespace dumpworld

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004D0AD0
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x004D0AF0
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x004D0B20
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10219710
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10219730
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x10219760
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102197D0
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from height2normal (Missing functions)
// ============================================================
namespace height2normal {

//------------------------------------------------------------------------------
// Address: 0x00408B90
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x00408BB0
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x00408BE0
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408D30
// Name: unsigned long GetProcessorCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl GetProcessorCount()
{
  struct _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  return SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x00409150
// Name: public: CATICompressThreadData::CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::CATICompressThreadData(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409160
// Name: public: CATICompressThreadData::~CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::~CATICompressThreadData(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*this;
  if ( v2 != nullptr )
  {
    (**v2)(a1: v2, a2: 1);
    *this = 0;
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*(this + 1);
  if ( v3 != nullptr )
  {
    (**v3)(a1: v3, a2: 1);
    *(this + 1) = 0;
  }
  v4 = (void (__thiscall ***)(_DWORD, int))*(this + 2);
  if ( v4 != nullptr )
  {
    (**v4)(a1: v4, a2: 1);
    *(this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004091B0
// Name: unsigned long ThreadedCompressProc(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall ThreadedCompressProc(_DWORD *lpThreadParameter)
{
  unsigned int v1; // esi
  int v2; // edi

  v1 = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0x8001Fu, mask: 0x8001Fu);
  v2 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*lpThreadParameter + 32))(
         a1: *lpThreadParameter,
         a2: lpThreadParameter[1],
         a3: lpThreadParameter[2],
         a4: lpThreadParameter[3],
         a5: lpThreadParameter[4],
         a6: lpThreadParameter[5]);
  _controlfp(newctrl: v1, mask: 0x8001Fu);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00409CA0
// Name: void S3TCencode(struct _DDSURFACEDESC __near *,struct tagPALETTEENTRY __near *,struct _DDSURFACEDESC __near *,void __near *,unsigned int,float __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl S3TCencode(
        struct _DDSURFACEDESC *a1,
        struct tagPALETTEENTRY *a2,
        struct _DDSURFACEDESC *a3,
        void *a4,
        unsigned int a5,
        float *a6)
{
  unsigned int v6; // ebx
  struct _DDSURFACEDESC *v7; // esi
  int v8; // ecx
  unsigned int v9; // eax
  int i; // edx
  unsigned int dwRGBAlphaBitMask; // edx
  int v12; // ecx
  unsigned int j; // eax
  signed int dwHeight; // eax
  signed int dwWidth; // edx
  int k; // eax
  int v17; // ebx
  _DWORD *v18; // edi
  int v19; // esi
  int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // edx
  double v23; // st7
  int v24; // esi
  int v25; // edi
  int v26; // eax
  _BYTE *v27; // edi
  int jj; // eax
  unsigned int v29; // edi
  _DWORD *v30; // esi
  int v31; // edx
  int v32; // eax
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // ecx
  _DWORD *v38; // esi
  char v39; // di
  int v40; // ecx
  int v41; // eax
  int v42; // eax
  unsigned int v43; // eax
  __int64 v44; // rax
  int v45; // ecx
  int v46; // edi
  unsigned __int8 *v47; // esi
  int v48; // eax
  struct tagPALETTEENTRY *v49; // eax
  unsigned int v50; // ecx
  double *v51; // ecx
  bool v52; // cc
  int v53; // edi
  int v54; // eax
  int nn; // edx
  int v56; // eax
  struct tagPALETTEENTRY *v57; // ecx
  double *v58; // eax
  int v59; // edi
  int v60; // ecx
  unsigned int *v61; // edx
  int v62; // eax
  unsigned int v63; // esi
  double *v64; // edx
  int v65; // eax
  double v66; // st7
  unsigned int v67; // ebx
  unsigned int v68; // eax
  double *v69; // esi
  int v70; // ebx
  int i1; // edx
  int v72; // ecx
  unsigned int v73; // edi
  char *v74; // esi
  int v75; // eax
  int v76; // edx
  int v77; // ecx
  unsigned int v78; // edi
  double *v79; // esi
  int i2; // edx
  unsigned int v81; // eax
  int v82; // ecx
  _DWORD *v83; // eax
  int i3; // ecx
  int v85; // ecx
  char *v86; // eax
  __int16 v87; // dx
  unsigned __int16 v88; // dx
  unsigned __int16 v89; // cx
  bool v90; // cf
  int v91; // eax
  __int16 v92; // ax
  int v93; // ebx
  _DWORD *v94; // esi
  int *v95; // edx
  int v96; // eax
  int i4; // edi
  int lPitch; // edx
  int v99; // [esp+18h] [ebp-888h]
  int v100; // [esp+18h] [ebp-888h]
  int m; // [esp+18h] [ebp-888h]
  int v102; // [esp+18h] [ebp-888h]
  int v103; // [esp+18h] [ebp-888h]
  int v104; // [esp+18h] [ebp-888h]
  int v105; // [esp+18h] [ebp-888h]
  int v106; // [esp+18h] [ebp-888h]
  int v107; // [esp+1Ch] [ebp-884h]
  int kk; // [esp+1Ch] [ebp-884h]
  int n; // [esp+1Ch] [ebp-884h]
  int mm; // [esp+1Ch] [ebp-884h]
  int v111; // [esp+1Ch] [ebp-884h]
  int v112; // [esp+1Ch] [ebp-884h]
  int v113; // [esp+1Ch] [ebp-884h]
  int *v114; // [esp+1Ch] [ebp-884h]
  int ii; // [esp+20h] [ebp-880h]
  int v116; // [esp+20h] [ebp-880h]
  int v117; // [esp+20h] [ebp-880h]
  int v118; // [esp+20h] [ebp-880h]
  int v119; // [esp+20h] [ebp-880h]
  int v120; // [esp+20h] [ebp-880h]
  int v121; // [esp+20h] [ebp-880h]
  int v122; // [esp+20h] [ebp-880h]
  int v123; // [esp+24h] [ebp-87Ch]
  int v124; // [esp+24h] [ebp-87Ch]
  int v125; // [esp+24h] [ebp-87Ch]
  int v126; // [esp+28h] [ebp-878h]
  unsigned int *v127; // [esp+28h] [ebp-878h]
  unsigned int v128; // [esp+2Ch] [ebp-874h]
  _WORD *v129; // [esp+30h] [ebp-870h]
  int v130; // [esp+34h] [ebp-86Ch]
  int v131; // [esp+38h] [ebp-868h]
  int v132; // [esp+3Ch] [ebp-864h]
  _DWORD *v133; // [esp+40h] [ebp-860h]
  int v134; // [esp+44h] [ebp-85Ch]
  int v135; // [esp+48h] [ebp-858h]
  int v136; // [esp+4Ch] [ebp-854h]
  int v137; // [esp+50h] [ebp-850h]
  char *lpSurface; // [esp+54h] [ebp-84Ch]
  signed int v139; // [esp+58h] [ebp-848h]
  _DWORD v140[3]; // [esp+5Ch] [ebp-844h] BYREF
  int v141; // [esp+68h] [ebp-838h]
  unsigned int v142; // [esp+6Ch] [ebp-834h]
  unsigned int v143; // [esp+70h] [ebp-830h]
  unsigned int v144; // [esp+74h] [ebp-82Ch]
  __int64 v145; // [esp+78h] [ebp-828h]
  __int64 v146; // [esp+80h] [ebp-820h]
  __int64 v147; // [esp+88h] [ebp-818h]
  __int64 v148; // [esp+90h] [ebp-810h]
  __int64 v149; // [esp+98h] [ebp-808h]
  __int64 v150; // [esp+A0h] [ebp-800h]
  __int64 v151; // [esp+A8h] [ebp-7F8h]
  __int64 v152; // [esp+B0h] [ebp-7F0h]
  __int64 v153; // [esp+B8h] [ebp-7E8h]
  __int64 v154; // [esp+C0h] [ebp-7E0h]
  _DWORD v155[48]; // [esp+C8h] [ebp-7D8h] BYREF
  float v156[51]; // [esp+188h] [ebp-718h] BYREF
  int v157; // [esp+254h] [ebp-64Ch]
  int v158; // [esp+258h] [ebp-648h]
  int v159; // [esp+25Ch] [ebp-644h]
  _DWORD v160[48]; // [esp+260h] [ebp-640h]
  double v161[176]; // [esp+320h] [ebp-580h] BYREF

  v6 = a5 & 0xFF00;
  v143 = v6;
  if ( (a5 & 0xFF00) != 0 )
  {
    if ( v6 == 256 || v6 == 512 )
      bS3TCForce4 = true;
  }
  else
  {
    bS3TCForce4 = false;
  }
  v7 = a1;
  a3->dwFlags = 6150;
  a3->dwWidth = a1->dwWidth;
  a3->dwHeight = a1->dwHeight;
  a3->lpSurface = a4;
  a3->ddpfPixelFormat.dwSize = 32;
  a3->ddpfPixelFormat.dwFlags = 4;
  a3->ddpfPixelFormat.dwRGBBitCount = a5;
  a3->ddpfPixelFormat.dwFourCC = 305419896;
  v128 = (a1->ddpfPixelFormat.dwRGBBitCount + 7) >> 3;
  v8 = 0;
  v135 = (char *)&a1->ddpfPixelFormat.___u4 - (char *)v140;
  do
  {
    v9 = *(_DWORD *)((char *)&v140[v8] + (char *)&a1->ddpfPixelFormat.___u4 - (char *)v140);
    for ( i = 0; (v9 & 1) == 0; ++i )
      v9 >>= 1;
    v140[v8++] = i;
  }
  while ( v8 < 3 );
  if ( (a5 & 0xFF00) != 0 )
  {
    dwRGBAlphaBitMask = a1->ddpfPixelFormat.dwRGBAlphaBitMask;
    v12 = 0;
    for ( j = dwRGBAlphaBitMask; (j & 1) == 0; ++v12 )
      j >>= 1;
    v137 = v12;
    v144 = (dword_49EDD4 * (dwRGBAlphaBitMask >> v12) / 0xFF) << v12;
  }
  lpSurface = (char *)a1->lpSurface;
  dwHeight = a1->dwHeight;
  v129 = a4;
  v136 = 0;
  if ( dwHeight > 0 )
  {
    while ( 1 )
    {
      v131 = dwHeight - v136;
      if ( (unsigned int)(dwHeight - v136) >= 4 )
        v131 = 4;
      v139 = 0;
      v133 = lpSurface;
      dwWidth = v7->dwWidth;
      if ( dwWidth > 0 )
        break;
LABEL_171:
      lPitch = a1->lPitch;
      dwHeight = a1->dwHeight;
      v52 = v136 + 4 < dwHeight;
      v136 += 4;
      lpSurface += 4 * lPitch;
      if ( !v52 )
        return;
      v7 = a1;
    }
    v141 = (unsigned __int8)a5;
    while ( 1 )
    {
      memset(v161, 0, sizeof(v161));
      memset(v155, 0xFFu, sizeof(v155));
      for ( k = 0; k < 3; v161[k + 144] = a6[k - 1] )
        ++k;
      v130 = dwWidth - v139;
      if ( dwWidth - v139 >= (unsigned int)S3TC_BLOCK_WIDTH )
        v130 = S3TC_BLOCK_WIDTH;
      v17 = 0;
      LODWORD(v161[0]) = 0;
      if ( v143 == 256 )
      {
        v38 = v133;
        v39 = v137;
        v40 = S3TC_BLOCK_WIDTH;
        v41 = 0;
        for ( m = 0; m < 4; v41 = m )
        {
          if ( v41 >= v131 )
          {
            *v129 = 0;
          }
          else
          {
            v42 = 0;
            for ( n = 0; v42 < v40; n = v42 )
            {
              if ( v42 >= v130 )
              {
                LOWORD(v134) = (unsigned __int16)v134 >> 4;
              }
              else
              {
                v43 = a1->ddpfPixelFormat.dwRGBAlphaBitMask >> v39;
                v152 = (*v38 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) >> v39;
                v148 = v43;
                v44 = (__int64)floor(X: (double)v152 / (double)v43 * 15.0 + 0.5);
                v17 = LODWORD(v161[0]);
                LOWORD(v45) = (unsigned __int16)v134 >> 4;
                LODWORD(v44) = v45 | ((_DWORD)v44 << 12);
                v40 = S3TC_BLOCK_WIDTH;
                v134 = v44;
                v42 = n;
              }
              ++v42;
              v38 = (_DWORD *)((char *)v38 + v128);
            }
            *v129 = v134;
          }
          ++v129;
          v40 = S3TC_BLOCK_WIDTH;
          ++m;
          v38 = (_DWORD *)((char *)v38 + a1->lPitch - v128 * S3TC_BLOCK_WIDTH);
        }
        goto LABEL_82;
      }
      if ( v143 != 512 )
        goto LABEL_82;
      v18 = v133;
      v19 = 0;
      v20 = a1->lPitch - v128 * S3TC_BLOCK_WIDTH;
      v156[0] = 0.0;
      v99 = 0;
      v107 = v20;
      do
      {
        for ( ii = 0; ii < S3TC_BLOCK_WIDTH; ++ii )
        {
          if ( ii >= v130 || v99 >= v131 )
          {
            v155[v19++] = -1;
          }
          else
          {
            v21 = (*v18 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) >> v137;
            v22 = a1->ddpfPixelFormat.dwRGBAlphaBitMask >> v137;
            v155[v19++] = LODWORD(v156[0]);
            if ( v21 == v22 )
            {
              v23 = 1.0;
            }
            else
            {
              v150 = v21;
              v151 = v22;
              v23 = (double)v21 / (double)v22;
            }
            v156[++LODWORD(v156[0])] = v23;
          }
          v18 = (_DWORD *)((char *)v18 + v128);
        }
        v18 = (_DWORD *)((char *)v18 + v107);
        ++v99;
      }
      while ( v99 < 4 );
      v24 = 0;
      v156[49] = 0.0;
      v156[50] = 0.0;
      if ( LODWORD(v156[0]) != 0 )
      {
        CodeAlphaBlock(a1: v156);
        v24 = v158;
        v25 = v159;
        v17 = LODWORD(v161[0]);
        if ( v158 != v159 )
          goto LABEL_45;
      }
      else
      {
        v25 = 0;
        v158 = 0;
      }
      ++v25;
      v26 = 0;
      v159 = v25;
      if ( SLODWORD(v156[0]) > 0 )
      {
        do
          v160[v26++] = 0;
        while ( v26 < SLODWORD(v156[0]) );
        v24 = v158;
        v25 = v159;
      }
      v157 = 6;
LABEL_45:
      if ( v24 > v25 == (v157 == 6) )
      {
        v158 = v25;
        v159 = v24;
        v116 = 1;
      }
      else
      {
        v116 = 0;
      }
      v27 = v129;
      for ( jj = 0; jj < 2; ++jj )
        *v27++ = *((_BYTE *)&v158 + 4 * jj);
      v129 = v27;
      v123 = 0;
      v126 = 0;
      memset(v27, 0, 6 * (S3TC_BLOCK_WIDTH / 4));
      v29 = 0;
      if ( S3TC_BLOCK_WIDTH / 4 > 0 )
      {
        v30 = v129;
        while ( 1 )
        {
          v31 = v123;
          v100 = 0;
          do
          {
            for ( kk = 4; kk != 0; --kk )
            {
              v32 = v155[v31];
              v29 >>= 3;
              if ( v32 < 0 )
                goto LABEL_66;
              v33 = v160[v32];
              if ( v116 != 0 )
              {
                if ( v157 == 8 )
                {
                  if ( v33 > 1 )
                  {
                    v34 = 9 - v33;
LABEL_64:
                    v33 = v34;
                    goto LABEL_65;
                  }
                }
                else
                {
                  if ( v157 != 6 || v33 > 5 )
                    goto LABEL_65;
                  if ( v33 > 1 )
                  {
                    v34 = 7 - v33;
                    goto LABEL_64;
                  }
                }
                v34 = v33 == 0;
                goto LABEL_64;
              }
LABEL_65:
              v29 |= v33 << 21;
LABEL_66:
              ++v31;
            }
            v35 = v100;
            if ( (v100 & 1) != 0 )
            {
              v36 = *v30;
              v30 = (_DWORD *)((char *)v30 + 3);
              v37 = v29 | v36;
              v29 = 0;
              *(_DWORD *)((char *)v30 - 3) = v37;
            }
            ++v100;
          }
          while ( v35 + 1 < 4 );
          v123 = v31;
          if ( ++v126 >= S3TC_BLOCK_WIDTH / 4 )
          {
            v129 = v30;
            break;
          }
        }
      }
LABEL_82:
      v46 = 0;
      if ( a2 != nullptr )
      {
        v47 = (unsigned __int8 *)v133;
        if ( v141 != 0 )
        {
          if ( v141 == 1 )
          {
            v102 = 0;
            v117 = a1->lPitch;
            do
            {
              v48 = 0;
              for ( mm = 0; mm < 4; ++mm )
              {
                if ( v48 >= v130
                  || v102 >= v131
                  || (v49 = &a2[*v47], (v50 = *(_DWORD *)v49 & 0xFFFFFF) >= a1->ddckCKSrcBlt.dwColorSpaceLowValue)
                  && v50 <= a1->ddckCKSrcBlt.dwColorSpaceHighValue )
                {
                  v155[v46++] = -1;
                }
                else
                {
                  v155[v46++] = v17;
                  LODWORD(v161[0]) = v17 + 1;
                  v51 = &v161[3 * v17 + 2];
                  *(v51 - 1) = (double)v49->peRed * 0.00392156862745098;
                  *v51 = (double)v49->peGreen * 0.00392156862745098;
                  v51[1] = (double)v49->peBlue * 0.00392156862745098;
                  v17 = LODWORD(v161[0]);
                }
                v48 = mm + 1;
                ++v47;
              }
              v52 = ++v102 < 4;
              v47 = &v47[v117 - 4];
            }
            while ( v52 );
          }
        }
        else
        {
          v53 = 0;
          v54 = 0;
          v103 = 0;
          v118 = a1->lPitch;
          do
          {
            for ( nn = 0; nn < 4; ++nn )
            {
              if ( nn >= v130 || v54 >= v131 )
              {
                v155[v53++] = -1;
              }
              else
              {
                v56 = *v47;
                v155[v53++] = v17;
                v57 = &a2[v56];
                LODWORD(v161[0]) = v17 + 1;
                v58 = &v161[3 * v17 + 2];
                *(v58 - 1) = (double)v57->peRed * 0.00392156862745098;
                *v58 = (double)v57->peGreen * 0.00392156862745098;
                v58[1] = (double)v57->peBlue * 0.00392156862745098;
                v17 = LODWORD(v161[0]);
                v54 = v103;
              }
              ++v47;
            }
            v103 = ++v54;
            v47 = &v47[v118 - 4];
          }
          while ( v54 < 4 );
        }
      }
      else
      {
        v127 = v133;
        if ( v141 != 0 )
        {
          if ( v141 == 1 )
          {
            v124 = 0;
            v105 = 0;
            v112 = a1->lPitch - 4 * v128;
            do
            {
              v120 = 0;
              do
              {
                if ( v120 >= v130
                  || v105 >= v131
                  || (v68 = *v127, v142 = v68, v68 >= a1->ddckCKSrcBlt.dwColorSpaceLowValue)
                  && v68 <= a1->ddckCKSrcBlt.dwColorSpaceHighValue )
                {
                  v155[v124++] = -1;
                }
                else
                {
                  v155[v124] = v17;
                  v69 = &v161[3 * v17 + 1];
                  LODWORD(v161[0]) = v17 + 1;
                  v70 = v135;
                  ++v124;
                  for ( i1 = 0; i1 < 3; ++i1 )
                  {
                    v72 = v140[i1];
                    ++v69;
                    v73 = (v142 & *(_DWORD *)((char *)&v140[i1] + v70)) >> v72;
                    v146 = (unsigned int)(*(_DWORD *)((char *)&v140[i1] + v70) >> v72);
                    v153 = v73;
                    *(v69 - 1) = (double)v73 / (double)v146;
                  }
                  v17 = LODWORD(v161[0]);
                }
                v74 = (char *)v127 + v128;
                v52 = ++v120 < 4;
                v127 = (unsigned int *)((char *)v127 + v128);
              }
              while ( v52 );
              v52 = ++v105 < 4;
              v127 = (unsigned int *)&v74[v112];
            }
            while ( v52 );
          }
          else if ( v141 == 2 )
          {
            v59 = 0;
            v60 = 0;
            v104 = 0;
            v111 = a1->lPitch - 4 * v128;
            do
            {
              v61 = v127;
              v62 = 0;
              v119 = 0;
              do
              {
                if ( v62 >= v130 || v60 >= v131 || (v63 = *v61, (*v61 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) <= v144) )
                {
                  v155[v59++] = -1;
                }
                else
                {
                  v155[v59++] = v17;
                  LODWORD(v161[0]) = v17 + 1;
                  v64 = &v161[3 * v17 + 1];
                  v65 = 0;
                  v154 = *(&a1->ddpfPixelFormat.dwRBitMask + v59) >> v140[v59];
                  v66 = (double)v154;
                  do
                  {
                    ++v64;
                    v67 = (v63 & *(_DWORD *)((char *)&v140[v65] + v135)) >> v140[v65];
                    ++v65;
                    v145 = v67;
                    *(v64 - 1) = (double)v67 / v66;
                  }
                  while ( v65 < 3 );
                  v17 = LODWORD(v161[0]);
                  v62 = v119;
                  v60 = v104;
                }
                ++v62;
                v61 = (unsigned int *)((char *)v127 + v128);
                v119 = v62;
                v127 = (unsigned int *)((char *)v127 + v128);
              }
              while ( v62 < 4 );
              v104 = ++v60;
              v127 = (unsigned int *)((char *)v61 + v111);
            }
            while ( v60 < 4 );
          }
        }
        else
        {
          v75 = 0;
          v76 = a1->lPitch - v128 * S3TC_BLOCK_WIDTH;
          v106 = 0;
          v113 = v76;
          do
          {
            v77 = 0;
            v121 = 0;
            if ( S3TC_BLOCK_WIDTH > 0 )
            {
              do
              {
                if ( v77 >= v130 || v46 >= v131 )
                {
                  v155[v75++] = -1;
                }
                else
                {
                  v155[v75] = v17;
                  v78 = *v127;
                  v79 = &v161[3 * v17 + 1];
                  v125 = v75 + 1;
                  LODWORD(v161[0]) = v17 + 1;
                  for ( i2 = 0; i2 < 3; ++i2 )
                  {
                    ++v79;
                    v81 = *(_DWORD *)((char *)&v140[i2] + v135);
                    v82 = v140[i2];
                    v147 = (v81 & v78) >> v82;
                    v149 = v81 >> v82;
                    *(v79 - 1) = (double)v147 / (double)v149;
                  }
                  v17 = LODWORD(v161[0]);
                  v75 = v125;
                  v77 = v121;
                  v46 = v106;
                }
                ++v77;
                v127 = (unsigned int *)((char *)v127 + v128);
                v121 = v77;
              }
              while ( v77 < S3TC_BLOCK_WIDTH );
              v76 = v113;
            }
            v106 = ++v46;
            v127 = (unsigned int *)((char *)v127 + v76);
          }
          while ( v46 < 4 );
        }
      }
      LODWORD(v161[148]) = (v17 >= v131 * v130) + 3;
      if ( v17 != 0 )
      {
        CodeRGBBlock(a1: v161);
      }
      else
      {
        v83 = (_DWORD *)&v161[149] + 1;
        for ( i3 = 2; i3 != 0; --i3 )
        {
          v83[1] = 0;
          *v83 = 0;
          *(v83 - 1) = 0;
          v83 += 3;
        }
      }
      v85 = 0;
      v86 = (char *)&v161[149] + 4;
      do
      {
        v87 = *((_WORD *)v86 - 2);
        v86 += 12;
        *((_WORD *)&v131 + ++v85 + 1) = *((_WORD *)v86 - 4) | (32 * (*((_WORD *)v86 - 6) | (v87 << 6)));
      }
      while ( v85 < 2 );
      v89 = HIWORD(v132);
      v88 = v132;
      v90 = HIWORD(v132) < (unsigned __int16)v132;
      if ( HIWORD(v132) == (_WORD)v132 )
      {
        v89 = HIWORD(v132) + 1;
        v91 = 0;
        ++HIWORD(v132);
        if ( SLODWORD(v161[0]) > 0 )
        {
          do
            *((_DWORD *)&v161[152] + v91++) = 0;
          while ( v91 < SLODWORD(v161[0]) );
        }
        HIDWORD(v161[148]) = 3;
        v90 = v89 < v88;
      }
      if ( v90 == (HIDWORD(v161[148]) == 3) )
      {
        v92 = v132;
        LOWORD(v132) = v89;
        HIWORD(v132) = v92;
        v122 = 1;
      }
      else
      {
        v122 = 0;
      }
      v93 = 0;
      *(_DWORD *)v129 = v132;
      v94 = v129 + 2;
      v129 += 2;
      if ( S3TC_BLOCK_WIDTH / 4 > 0 )
      {
        v114 = &v155[15];
        do
        {
          v95 = v114;
          v96 = 0;
          for ( i4 = 16; i4 != 0; --i4 )
          {
            v96 *= 4;
            if ( *v95 >= 0 )
            {
              v96 |= *((_DWORD *)&v161[152] + *v95);
              if ( v122 != 0 )
              {
                if ( HIDWORD(v161[148]) == 4 )
                  v96 ^= 1u;
                else
                  v96 ^= (~v96 & 2) != 0;
              }
            }
            else
            {
              LOBYTE(v96) = v96 | 3;
            }
            --v95;
          }
          *v94 = v96;
          v114 += 16;
          ++v94;
          ++v93;
        }
        while ( v93 < S3TC_BLOCK_WIDTH / 4 );
        v129 = v94;
      }
      v133 += v128;
      v139 += 4;
      dwWidth = a1->dwWidth;
      if ( v139 >= dwWidth )
        goto LABEL_171;
    }
  }
}

} // namespace height2normal

// ============================================================
// Overlay from height2ssbump (Missing functions)
// ============================================================
namespace height2ssbump {

//------------------------------------------------------------------------------
// Address: 0x00405F40
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x00405F60
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x00405F90
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace height2ssbump

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1016C2E0
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x1016C300
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x1016C330
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x0055C6B0
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x0055C6D0
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x0055C700
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0055C770
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace makegamedata

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x10034FE0
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10035000
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x10035030
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace missionchooser

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00469720
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x00469740
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x00469770
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace mksheet

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004DF040
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x004DF060
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x004DF090
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DF100
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace sceneviewer

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10045B00
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10045B10
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x10045B40
// Name: enum ImageFormat ImageLoader::D3DFormatToImageFormat(enum _D3DFORMAT)
// Source: json
//------------------------------------------------------------------------------
ImageFormat __cdecl ImageLoader::D3DFormatToImageFormat(_D3DFORMAT format)
{
  ImageFormat result; // eax

  if ( format > 826889281 )
  {
    if ( format > D3DFMT_DXT3 )
    {
      if ( format == D3DFMT_DXT5 )
        return IMAGE_FORMAT_DXT5;
      if ( format == 1280070990 )
        return IMAGE_FORMAT_NULL;
    }
    else
    {
      switch ( format )
      {
        case 861165636:
          return IMAGE_FORMAT_DXT3;
        case 827611204:
          return IMAGE_FORMAT_DXT1;
        case 843666497:
          return IMAGE_FORMAT_ATI2N;
        default:
          break;
      }
    }
    return IMAGE_FORMAT_UNKNOWN;
  }
  if ( format == 826889281 )
    return IMAGE_FORMAT_ATI1N;
  switch ( format )
  {
    case D3DFMT_R8G8B8:
      result = IMAGE_FORMAT_BGR888;
      break;
    case D3DFMT_A8R8G8B8:
      result = IMAGE_FORMAT_BGRA8888;
      break;
    case D3DFMT_X8R8G8B8:
      result = IMAGE_FORMAT_BGRX8888;
      break;
    case D3DFMT_R5G6B5:
      result = IMAGE_FORMAT_BGR565;
      break;
    case D3DFMT_X1R5G5B5:
      result = IMAGE_FORMAT_BGRX5551;
      break;
    case D3DFMT_A1R5G5B5:
      result = IMAGE_FORMAT_BGRA5551;
      break;
    case D3DFMT_A4R4G4B4:
      result = IMAGE_FORMAT_BGRA4444;
      break;
    case D3DFMT_A8:
      result = IMAGE_FORMAT_A8;
      break;
    case D3DFMT_A2B10G10R10:
      result = IMAGE_FORMAT_RGBA1010102;
      break;
    case D3DFMT_A8B8G8R8:
      result = IMAGE_FORMAT_RGBA8888;
      break;
    case D3DFMT_X8B8G8R8:
      result = IMAGE_FORMAT_RGBX8888;
      break;
    case D3DFMT_A2R10G10B10:
      result = IMAGE_FORMAT_BGRA1010102;
      break;
    case D3DFMT_A16B16G16R16:
      result = IMAGE_FORMAT_RGBA16161616;
      break;
    case D3DFMT_P8:
      result = IMAGE_FORMAT_P8;
      break;
    case D3DFMT_L8:
      result = IMAGE_FORMAT_I8;
      break;
    case D3DFMT_A8L8:
      result = IMAGE_FORMAT_IA88;
      break;
    case D3DFMT_V8U8:
      result = IMAGE_FORMAT_UV88;
      break;
    case D3DFMT_X8L8V8U8:
      result = IMAGE_FORMAT_UVLX8888;
      break;
    case D3DFMT_Q8W8V8U8:
      result = IMAGE_FORMAT_UVWQ8888;
      break;
    case D3DFMT_D32:
      result = IMAGE_FORMAT_D32;
      break;
    case D3DFMT_D15S1:
      result = IMAGE_FORMAT_D15S1;
      break;
    case D3DFMT_D24S8:
      result = IMAGE_FORMAT_D24S8;
      break;
    case D3DFMT_D24X8:
      result = IMAGE_FORMAT_D24X8;
      break;
    case D3DFMT_D24X4S4:
      result = IMAGE_FORMAT_D24X4S4;
      break;
    case D3DFMT_D16:
      result = IMAGE_FORMAT_D16;
      break;
    case D3DFMT_D24FS8:
      result = IMAGE_FORMAT_D24FS8;
      break;
    case D3DFMT_R16F:
      result = IMAGE_FORMAT_R16F;
      break;
    case D3DFMT_G16R16F:
      result = IMAGE_FORMAT_RG1616F;
      break;
    case D3DFMT_A16B16G16R16F:
      result = IMAGE_FORMAT_RGBA16161616F;
      break;
    case D3DFMT_R32F:
      result = IMAGE_FORMAT_R32F;
      break;
    case D3DFMT_G32R32F:
      result = IMAGE_FORMAT_RG3232F;
      break;
    case D3DFMT_A32B32G32R32F:
      result = IMAGE_FORMAT_RGBA32323232F;
      break;
    default:
      return IMAGE_FORMAT_UNKNOWN;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045D80
// Name: enum _D3DFORMAT ImageLoader::ImageFormatToD3DFormat(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
_D3DFORMAT __cdecl ImageLoader::ImageFormatToD3DFormat(ImageFormat format)
{
  return s_pD3DFormats[format + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10045D90
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebp
  int v13; // ebx
  int v14; // esi

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    v12 = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v13 = height;
    v14 = width;
    do
    {
      v12 += ImageLoader::GetMemRequired(
               width: v14,
               height: v13,
               depth: v6,
               nMipmapCount: 1,
               imageFormat,
               pAdjustedHeight: nullptr);
      if ( v14 == 1 && v13 == 1 && v6 == 1 )
        break;
      v14 >>= 1;
      v13 >>= 1;
      v6 >>= 1;
      if ( v14 < 1 )
        v14 = 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045EE0
// Name: unsigned long GetProcessorCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl GetProcessorCount()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  return SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x10046300
// Name: public: CATICompressThreadData::CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::CATICompressThreadData(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10046310
// Name: public: CATICompressThreadData::~CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::~CATICompressThreadData(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*this;
  if ( v2 != nullptr )
  {
    (**v2)(a1: v2, a2: 1);
    *this = 0;
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*(this + 1);
  if ( v3 != nullptr )
  {
    (**v3)(a1: v3, a2: 1);
    *(this + 1) = 0;
  }
  v4 = (void (__thiscall ***)(_DWORD, int))*(this + 2);
  if ( v4 != nullptr )
  {
    (**v4)(a1: v4, a2: 1);
    *(this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046360
// Name: unsigned long ThreadedCompressProc(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall ThreadedCompressProc(_DWORD *a1)
{
  unsigned int v1; // esi
  int v2; // edi

  v1 = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0x8001Fu, mask: 0x8001Fu);
  v2 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*a1 + 32))(
         a1: *a1,
         a2: a1[1],
         a3: a1[2],
         a4: a1[3],
         a5: a1[4],
         a6: a1[5]);
  _controlfp(newctrl: v1, mask: 0x8001Fu);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10046EC0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x10047200
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10047270
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10047380
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x10047430
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace shaderapidx10

// ============================================================
// Overlay from tgadiff (Missing functions)
// ============================================================
namespace tgadiff {

//------------------------------------------------------------------------------
// Address: 0x004016A0
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x004016C0
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x004016F0
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace tgadiff

// ============================================================
// Overlay from tgamse (Missing functions)
// ============================================================
namespace tgamse {

//------------------------------------------------------------------------------
// Address: 0x00401690
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x004016B0
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x004016E0
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace tgamse

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0047D680
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x0047D6A0
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x0047D6D0
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047D740
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047C210
// Name: _$I10_OUTPUT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _I10_OUTPUT(_LDOUBLE ld, int ndigits, char output_flags, _FloatOutStruct *fos)
{
  unsigned __int16 v4; // dx
  int v6; // eax
  int v7; // eax
  __int16 v8; // ax
  int v9; // ebx
  bool v10; // zf
  char v11; // cl
  int v12; // ecx
  _LDBL12 *p_tmp12; // eax
  unsigned __int8 *v14; // esi
  __int16 v15; // cx
  unsigned __int16 v16; // di
  _WORD *v17; // esi
  unsigned int v18; // edx
  unsigned int v19; // ecx
  unsigned int v20; // eax
  __int16 v21; // di
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  unsigned int v25; // ecx
  int v26; // esi
  int v27; // ecx
  unsigned __int16 v28; // si
  int v29; // eax
  _WORD *v30; // edi
  unsigned __int8 *v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  __int16 v35; // si
  unsigned int v36; // ecx
  unsigned int v37; // edx
  int v38; // eax
  unsigned int v39; // ecx
  int v40; // edi
  int v41; // ecx
  int v42; // edi
  int v43; // esi
  unsigned int v44; // eax
  int v45; // ebx
  int v46; // eax
  int v47; // esi
  int v48; // eax
  int v49; // ebx
  int v50; // eax
  char *man; // ebx
  unsigned int v52; // edx
  unsigned int v53; // edi
  unsigned int v54; // ecx
  int v55; // esi
  int v56; // ecx
  unsigned int v57; // esi
  unsigned int v58; // edi
  int v59; // edx
  unsigned int v60; // edx
  char v61; // al
  char *v62; // ebx
  _FloatOutStruct *v63; // eax
  char v64; // bl
  unsigned __int8 *v65; // [esp+10h] [ebp-70h]
  unsigned __int8 *v66; // [esp+14h] [ebp-6Ch]
  _LDBL12 *v67; // [esp+18h] [ebp-68h]
  __int16 sign; // [esp+20h] [ebp-60h]
  int v69; // [esp+24h] [ebp-5Ch]
  __int16 v70; // [esp+24h] [ebp-5Ch]
  __int16 v71; // [esp+28h] [ebp-58h]
  unsigned __int8 *v72; // [esp+28h] [ebp-58h]
  int v73; // [esp+2Ch] [ebp-54h]
  int v74; // [esp+2Ch] [ebp-54h]
  int v75; // [esp+30h] [ebp-50h]
  int v76; // [esp+30h] [ebp-50h]
  __int16 digcount; // [esp+34h] [ebp-4Ch]
  int digcounta; // [esp+34h] [ebp-4Ch]
  int v79; // [esp+38h] [ebp-48h]
  int v80; // [esp+38h] [ebp-48h]
  _LDBL12 *v81; // [esp+3Ch] [ebp-44h]
  int v82; // [esp+3Ch] [ebp-44h]
  int v83; // [esp+3Ch] [ebp-44h]
  unsigned int v84; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  char *v87; // [esp+40h] [ebp-40h]
  _LDBL12 tmp12; // [esp+44h] [ebp-3Ch] BYREF
  _LDBL12 ld12_one_tenth; // [esp+50h] [ebp-30h] BYREF
  _LDBL12 ld12; // [esp+60h] [ebp-20h] BYREF
  _BYTE v91[12]; // [esp+70h] [ebp-10h] BYREF

  sign = *(_WORD *)&ld.ld[8] & 0x8000;
  v4 = *(_WORD *)&ld.ld[8] & 0x7FFF;
  memset(&ld12_one_tenth, 204, 8);
  *(_DWORD *)&ld12_one_tenth.ld12[8] = 1073466572;
  if ( *(__int16 *)&ld.ld[8] >= 0 )
    fos->sign = 32;
  else
    fos->sign = 45;
  if ( v4 != 0 )
  {
    if ( v4 != 0x7FFF )
      goto LABEL_28;
    fos->exp = 1;
    if ( (*(_DWORD *)&ld.ld[4] != 0x80000000 || *(_DWORD *)ld.ld != 0) && (*(_DWORD *)&ld.ld[4] & 0x40000000) == 0 )
    {
      v6 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#SNAN");
      goto LABEL_25;
    }
    if ( sign != 0 && *(_DWORD *)&ld.ld[4] == -1073741824 )
    {
      if ( *(_DWORD *)ld.ld == 0 )
      {
        v7 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#IND");
        goto LABEL_22;
      }
    }
    else if ( *(_DWORD *)&ld.ld[4] == 0x80000000 && *(_DWORD *)ld.ld == 0 )
    {
      v7 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#INF");
LABEL_22:
      if ( v7 == 0 )
      {
        fos->ManLen = 5;
        return 0;
      }
LABEL_14:
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    }
    v6 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#QNAN");
LABEL_25:
    if ( v6 == 0 )
    {
      fos->ManLen = 6;
      return 0;
    }
    goto LABEL_14;
  }
  if ( *(_DWORD *)&ld.ld[4] == 0 && *(_DWORD *)ld.ld == 0 )
  {
    fos->exp = 0;
    fos->sign = sign != -32768 ? 32 : 45;
    *(_WORD *)&fos->ManLen = 12289;
    fos->man[1] = 0;
    return 1;
  }
LABEL_28:
  v8 = (77 * (HIBYTE(v4) + 2 * ld.ld[7]) + 19728 * (unsigned int)v4 - 323162868) >> 16;
  *(_WORD *)ld12.ld12 = 0;
  v9 = -v8;
  digcount = v8;
  *(_WORD *)&ld12.ld12[10] = *(_WORD *)&ld.ld[8] & 0x7FFF;
  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&ld.ld[4];
  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)ld.ld;
  v67 = &_pow10pos[-8];
  if ( v8 != 0 )
  {
    v10 = v8 == 0;
    if ( v8 > 0 )
    {
      v9 = v8;
      v67 = &_pow10neg[-8];
      v10 = v8 == 0;
    }
    if ( !v10 )
    {
      do
      {
        v67 += 7;
        v11 = v9;
        v9 >>= 3;
        v12 = v11 & 7;
        if ( v12 != 0 )
        {
          p_tmp12 = &v67[v12];
          v81 = p_tmp12;
          if ( *(_WORD *)p_tmp12->ld12 >= 0x8000u )
          {
            *(_DWORD *)tmp12.ld12 = *(_DWORD *)p_tmp12->ld12;
            *(_DWORD *)&tmp12.ld12[4] = *(_DWORD *)&p_tmp12->ld12[4];
            v14 = &p_tmp12->ld12[8];
            p_tmp12 = &tmp12;
            *(_DWORD *)&tmp12.ld12[8] = *(_DWORD *)v14;
            --*(_DWORD *)&tmp12.ld12[2];
            v81 = &tmp12;
          }
          v79 = 0;
          memset(v91, 0, sizeof(v91));
          v71 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&p_tmp12->ld12[10]) & 0x8000;
          v15 = *(_WORD *)&p_tmp12->ld12[10] & 0x7FFF;
          v16 = v15 + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
          if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
            || (*(_WORD *)&p_tmp12->ld12[10] & 0x7FFF) == 0x7FFF
            || v16 > 0xBFFDu )
          {
            *(_DWORD *)&ld12.ld12[8] = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&p_tmp12->ld12[10]) & 0x8000u) == 0
                                     ? 2147450880
                                     : -32768;
          }
          else
          {
            if ( v16 > 0x3FBFu )
            {
              if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
              {
                ++v16;
                if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
                  && *(_DWORD *)&ld12.ld12[4] == 0
                  && *(_DWORD *)ld12.ld12 == 0 )
                {
                  *(_WORD *)&ld12.ld12[10] = 0;
                  continue;
                }
              }
              if ( v15 != 0
                || (++v16, (*(_DWORD *)&p_tmp12->ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&p_tmp12->ld12[4] != 0
                || *(_DWORD *)p_tmp12->ld12 != 0 )
              {
                v73 = 0;
                v17 = &v91[4];
                for ( i = 5; i > 0; --i )
                {
                  v75 = i;
                  v65 = &ld12.ld12[2 * v73];
                  v66 = &p_tmp12->ld12[8];
                  do
                  {
                    v18 = *((_DWORD *)v17 - 1);
                    v19 = *(unsigned __int16 *)v66 * *(unsigned __int16 *)v65;
                    v69 = 0;
                    v20 = v18 + v19;
                    if ( v18 + v19 < v18 || v20 < v19 )
                      v69 = 1;
                    *((_DWORD *)v17 - 1) = v20;
                    if ( v69 != 0 )
                      ++*v17;
                    v65 += 2;
                    v66 -= 2;
                    --v75;
                  }
                  while ( v75 > 0 );
                  p_tmp12 = v81;
                  ++v17;
                  ++v73;
                }
                v21 = v16 - 16382;
                if ( v21 <= 0 )
                  goto LABEL_172;
                do
                {
                  if ( *(int *)&v91[8] < 0 )
                    break;
                  v22 = *(_DWORD *)v91;
                  *(_DWORD *)v91 *= 2;
                  v23 = *(_DWORD *)&v91[4];
                  *(_DWORD *)&v91[4] = (v22 >> 31) | (2 * *(_DWORD *)&v91[4]);
                  --v21;
                  *(_DWORD *)&v91[8] = (v23 >> 31) | (2 * *(_DWORD *)&v91[8]);
                }
                while ( v21 > 0 );
                if ( v21 <= 0 )
                {
LABEL_172:
                  if ( --v21 < 0 )
                  {
                    v24 = (unsigned __int16)-v21;
                    v21 = 0;
                    do
                    {
                      if ( (v91[0] & 1) != 0 )
                        ++v79;
                      v25 = *(_DWORD *)&v91[8];
                      *(_DWORD *)&v91[8] >>= 1;
                      v26 = __SPAIR64__(v25, *(unsigned int *)&v91[4]) >> 1;
                      v27 = *(__int64 *)v91 >> 1;
                      --v24;
                      *(_DWORD *)&v91[4] = v26;
                      *(_DWORD *)v91 = v27;
                    }
                    while ( v24 != 0 );
                    if ( v79 != 0 )
                      *(_WORD *)v91 |= 1u;
                  }
                }
                if ( *(_WORD *)v91 > 0x8000u || (*(_DWORD *)v91 & 0x1FFFF) == 0x18000 )
                {
                  if ( *(_DWORD *)&v91[2] == -1 )
                  {
                    *(_DWORD *)&v91[2] = 0;
                    if ( *(_DWORD *)&v91[6] == -1 )
                    {
                      *(_DWORD *)&v91[6] = 0;
                      if ( *(_WORD *)&v91[10] == 0xFFFF )
                      {
                        *(_WORD *)&v91[10] = 0x8000;
                        ++v21;
                      }
                      else
                      {
                        ++*(_WORD *)&v91[10];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v91[6];
                    }
                  }
                  else
                  {
                    ++*(_DWORD *)&v91[2];
                  }
                }
                if ( (unsigned __int16)v21 < 0x7FFFu )
                {
                  *(_WORD *)ld12.ld12 = *(_WORD *)&v91[2];
                  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v91[4];
                  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v91[8];
                  *(_WORD *)&ld12.ld12[10] = v71 | v21;
                }
                else
                {
                  *(_DWORD *)&ld12.ld12[4] = 0;
                  *(_DWORD *)ld12.ld12 = 0;
                  *(_DWORD *)&ld12.ld12[8] = v71 == 0 ? 2147450880 : -32768;
                }
                continue;
              }
            }
            *(_DWORD *)&ld12.ld12[8] = 0;
          }
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
        }
      }
      while ( v9 != 0 );
    }
  }
  if ( *(_WORD *)&ld12.ld12[10] < 0x3FFFu )
    goto LABEL_134;
  ++digcount;
  v76 = 0;
  memset(v91, 0, sizeof(v91));
  v70 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000;
  v28 = (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
  if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
    || (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) == 0x7FFF
    || v28 > 0xBFFDu )
  {
    *(_DWORD *)&ld12.ld12[4] = 0;
    v29 = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000u) == 0 ? 2147450880 : -32768;
    *(_DWORD *)ld12.ld12 = 0;
  }
  else
  {
    if ( v28 > 0x3FBFu )
    {
      v29 = 0;
      if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
      {
        ++v28;
        if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0 && *(_DWORD *)&ld12.ld12[4] == 0 && *(_DWORD *)ld12.ld12 == 0 )
        {
          *(_WORD *)&ld12.ld12[10] = 0;
          goto LABEL_134;
        }
      }
      if ( (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) != 0
        || (++v28, (*(_DWORD *)&ld12_one_tenth.ld12[8] & 0x7FFFFFFF) != 0)
        || *(_DWORD *)&ld12_one_tenth.ld12[4] != 0
        || *(_DWORD *)ld12_one_tenth.ld12 != 0 )
      {
        v74 = 0;
        v30 = &v91[4];
        for ( j = 5; j > 0; --j )
        {
          v80 = j;
          v72 = &ld12_one_tenth.ld12[8];
          v31 = &ld12.ld12[2 * v74];
          do
          {
            v82 = 0;
            v32 = *(unsigned __int16 *)v31 * *(unsigned __int16 *)v72;
            v33 = *((_DWORD *)v30 - 1);
            v34 = v33 + v32;
            if ( v33 + v32 < v33 || v34 < v32 )
              v82 = 1;
            *((_DWORD *)v30 - 1) = v34;
            if ( v82 != 0 )
              ++*v30;
            v72 -= 2;
            v31 += 2;
            --v80;
          }
          while ( v80 > 0 );
          ++v30;
          ++v74;
        }
        v35 = v28 - 16382;
        if ( v35 <= 0 )
          goto LABEL_173;
        do
        {
          if ( *(int *)&v91[8] < 0 )
            break;
          v36 = *(_DWORD *)v91;
          *(_DWORD *)v91 *= 2;
          v37 = *(_DWORD *)&v91[4];
          *(_DWORD *)&v91[4] = (v36 >> 31) | (2 * *(_DWORD *)&v91[4]);
          --v35;
          *(_DWORD *)&v91[8] = (v37 >> 31) | (2 * *(_DWORD *)&v91[8]);
        }
        while ( v35 > 0 );
        if ( v35 <= 0 )
        {
LABEL_173:
          if ( --v35 < 0 )
          {
            v38 = (unsigned __int16)-v35;
            v35 = 0;
            do
            {
              if ( (v91[0] & 1) != 0 )
                ++v76;
              v39 = *(_DWORD *)&v91[8];
              *(_DWORD *)&v91[8] >>= 1;
              v40 = __SPAIR64__(v39, *(unsigned int *)&v91[4]) >> 1;
              v41 = *(__int64 *)v91 >> 1;
              --v38;
              *(_DWORD *)&v91[4] = v40;
              *(_DWORD *)v91 = v41;
            }
            while ( v38 != 0 );
            if ( v76 != 0 )
              *(_WORD *)v91 |= 1u;
          }
        }
        if ( *(_WORD *)v91 > 0x8000u || (*(_DWORD *)v91 & 0x1FFFF) == 0x18000 )
        {
          if ( *(_DWORD *)&v91[2] == -1 )
          {
            *(_DWORD *)&v91[2] = 0;
            if ( *(_DWORD *)&v91[6] == -1 )
            {
              *(_DWORD *)&v91[6] = 0;
              if ( *(_WORD *)&v91[10] == 0xFFFF )
              {
                *(_WORD *)&v91[10] = 0x8000;
                ++v35;
              }
              else
              {
                ++*(_WORD *)&v91[10];
              }
            }
            else
            {
              ++*(_DWORD *)&v91[6];
            }
          }
          else
          {
            ++*(_DWORD *)&v91[2];
          }
        }
        if ( (unsigned __int16)v35 < 0x7FFFu )
        {
          *(_WORD *)ld12.ld12 = *(_WORD *)&v91[2];
          *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v91[4];
          *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v91[8];
          *(_WORD *)&ld12.ld12[10] = v70 | v35;
        }
        else
        {
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
          *(_DWORD *)&ld12.ld12[8] = v70 == 0 ? 2147450880 : -32768;
        }
        goto LABEL_134;
      }
    }
    else
    {
      v29 = 0;
    }
    *(_DWORD *)&ld12.ld12[4] = 0;
    *(_DWORD *)ld12.ld12 = 0;
  }
  *(_DWORD *)&ld12.ld12[8] = v29;
LABEL_134:
  v42 = ndigits;
  fos->exp = digcount;
  if ( (output_flags & 1) != 0 )
  {
    v42 = digcount + ndigits;
    if ( v42 <= 0 )
    {
      fos->exp = 0;
      *(_WORD *)&fos->ManLen = 12289;
      fos->sign = sign != -32768 ? 32 : 45;
      fos->man[1] = 0;
      return 1;
    }
  }
  if ( v42 > 21 )
    v42 = 21;
  v43 = *(unsigned __int16 *)&ld12.ld12[10] - 16382;
  *(_WORD *)&ld12.ld12[10] = 0;
  v83 = 8;
  do
  {
    v44 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v45 = (v44 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v46 = *(__int64 *)&ld12.ld12[4] >> 31;
    v10 = v83-- == 1;
    *(_DWORD *)&ld12.ld12[4] = v45;
    *(_DWORD *)&ld12.ld12[8] = v46;
  }
  while ( !v10 );
  if ( v43 < 0 )
  {
    v47 = (unsigned __int8)-(char)v43;
    if ( v47 != 0 )
    {
      do
      {
        v48 = *(_DWORD *)&ld12.ld12[8];
        *(_DWORD *)&ld12.ld12[8] >>= 1;
        v49 = (v48 << 31) | (*(_DWORD *)&ld12.ld12[4] >> 1);
        v50 = *(__int64 *)ld12.ld12 >> 1;
        --v47;
        *(_DWORD *)&ld12.ld12[4] = v49;
        *(_DWORD *)ld12.ld12 = v50;
      }
      while ( v47 > 0 );
    }
  }
  man = fos->man;
  v87 = fos->man;
  for ( digcounta = v42 + 1; digcounta > 0; ld12.ld12[11] = 0 )
  {
    v52 = *(_DWORD *)ld12.ld12;
    tmp12 = ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v53 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v54 = (v52 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v55 = 2 * v54;
    v56 = (v54 >> 31) | (2 * (*(__int64 *)&ld12.ld12[4] >> 31));
    v57 = (v53 >> 31) | v55;
    v58 = *(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12;
    if ( (unsigned int)(*(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12) < *(_DWORD *)ld12.ld12
      || v58 < *(_DWORD *)tmp12.ld12 )
    {
      v59 = 0;
      if ( v57 + 1 < v57 || v57 == -1 )
        v59 = 1;
      ++v57;
      if ( v59 != 0 )
        ++v56;
    }
    v60 = *(_DWORD *)&tmp12.ld12[4] + v57;
    v84 = *(_DWORD *)&tmp12.ld12[4] + v57;
    if ( *(_DWORD *)&tmp12.ld12[4] + v57 < v57 || v60 < *(_DWORD *)&tmp12.ld12[4] )
      ++v56;
    *(_DWORD *)ld12.ld12 = 2 * v58;
    *(_DWORD *)&ld12.ld12[8] = (v60 >> 31) | (2 * (*(_DWORD *)&tmp12.ld12[8] + v56));
    *man++ = ld12.ld12[11] + 48;
    --digcounta;
    *(_DWORD *)&ld12.ld12[4] = (v58 >> 31) | (2 * v84);
  }
  v61 = *(man - 1);
  v62 = man - 2;
  if ( v61 >= 53 )
  {
    while ( v62 >= v87 && *v62 == 57 )
      *v62-- = 48;
    v63 = fos;
    if ( v62 < v87 )
    {
      ++v62;
      ++fos->exp;
    }
    ++*v62;
  }
  else
  {
    while ( v62 >= v87 && *v62 == 48 )
      --v62;
    v63 = fos;
    if ( v62 < v87 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != -32768 ? 32 : 45;
      *v87 = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  v64 = (_BYTE)v62 - (_BYTE)v63 - 3;
  v63->ManLen = v64;
  v63->man[v64] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047CB08
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (abstr & 0x30000) != 0 )
  {
    if ( (abstr & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047CB96
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  void *v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = (void *)((unsigned int)&unk_3000000 & abstr);
  if ( v4 == &unk_1000000 )
  {
    result |= 0x8040u;
  }
  else if ( v4 == &unk_2000000 )
  {
    result |= 0x40u;
  }
  else if ( v4 == &unk_3000000 )
  {
    result |= 0x8000u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047CC36
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // cx
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  unsigned int v23; // [esp+14h] [ebp-Ch]
  __int16 oldCw; // [esp+1Ch] [ebp-4h]
  unsigned int newabs; // [esp+2Ch] [ebp+Ch]

  v2 = 0;
  if ( (oldCw & 1) != 0 )
    v2 = 16;
  if ( (oldCw & 4) != 0 )
    v2 |= 8u;
  if ( (oldCw & 8) != 0 )
    v2 |= 4u;
  if ( (oldCw & 0x10) != 0 )
    v2 |= 2u;
  if ( (oldCw & 0x20) != 0 )
    v2 |= 1u;
  if ( (oldCw & 2) != 0 )
    v2 |= 0x80000u;
  v3 = oldCw & 0xC00;
  if ( (oldCw & 0xC00) != 0 )
  {
    switch ( v3 )
    {
      case 1024:
        v2 |= 0x100u;
        break;
      case 2048:
        v2 |= 0x200u;
        break;
      case 3072:
        v2 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (oldCw & 0x300) != 0 )
  {
    if ( (oldCw & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (oldCw & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  newabs = result;
  if ( result != v2 )
  {
    v6 = hw_cw(abstr: result);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    newabs = v8;
    result = v8;
  }
  v10 = 0;
  if ( __sse2_available != 0 )
  {
    v11 = _mm_getcsr();
    if ( (v11 & 0x80u) != 0 )
      v10 = 16;
    if ( (v11 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v10 |= 0x80000u;
    v12 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v12 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v13 = (v11 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
          v10 |= (unsigned int)&unk_1000000;
      }
      else
      {
        v10 |= (unsigned int)&unk_3000000;
      }
    }
    else
    {
      v10 |= (unsigned int)&unk_2000000;
    }
    v15 = newctrl & (unsigned int)&unk_308031F & mask | v10 & ~((unsigned int)&unk_308031F & mask);
    if ( v15 == v10 )
    {
      v16 = v10;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v18 = 0;
      if ( (v17 & 0x80u) != 0 )
        v18 = 16;
      if ( (v17 & 0x200) != 0 )
        v18 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v18 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v18 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v18 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v18 |= 0x80000u;
      v19 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v19 )
        {
          case 8192:
            v18 |= 0x100u;
            break;
          case 16384:
            v18 |= 0x200u;
            break;
          case 24576:
            v18 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v20 = (v17 & 0x8040) - 64;
      if ( v20 != 0 )
      {
        v21 = v20 - 32704;
        if ( v21 != 0 )
        {
          if ( v21 == 64 )
            v18 |= (unsigned int)&unk_1000000;
        }
        else
        {
          v18 |= (unsigned int)&unk_3000000;
        }
      }
      else
      {
        v18 |= (unsigned int)&unk_2000000;
      }
      v16 = v18;
    }
    v22 = newabs ^ v16;
    result = newabs | v16;
    if ( (v22 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047CF48
// Name: __controlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _controlfp(unsigned int newctrl, unsigned int mask)
{
  unsigned int v2; // edi
  int v3; // edx
  unsigned int v4; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // dx
  int v18; // ecx
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  unsigned int v22; // [esp+10h] [ebp-10h]
  unsigned int v23; // [esp+18h] [ebp-8h]

  v2 = mask & 0xFFF7FFFF;
  v3 = 0;
  if ( (mask & 1) != 0 )
    v3 = 16;
  if ( (mask & 4) != 0 )
    v3 |= 8u;
  if ( (mask & 8) != 0 )
    v3 |= 4u;
  if ( (mask & 0x10) != 0 )
    v3 |= 2u;
  if ( (mask & 0x20) != 0 )
    v3 |= 1u;
  if ( (mask & 2) != 0 )
    v3 |= 0x80000u;
  v4 = mask & 0xC00;
  if ( (mask & 0xC00) != 0 )
  {
    switch ( v4 )
    {
      case 0x400u:
        v3 |= 0x100u;
        break;
      case 0x800u:
        v3 |= 0x200u;
        break;
      case 0xC00u:
        v3 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (mask & 0x300) != 0 )
  {
    if ( (mask & 0x300) == 0x200 )
      v3 |= 0x10000u;
  }
  else
  {
    v3 |= 0x20000u;
  }
  if ( (mask & 0x1000) != 0 )
    v3 |= 0x40000u;
  result = newctrl & v2 | v3 & ~v2;
  v22 = result;
  if ( result != v3 )
  {
    v6 = hw_cw(abstr: newctrl & v2 | v3 & ~v2);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    result = v8;
    v22 = v8;
  }
  v10 = 0;
  if ( __sse2_available != 0 )
  {
    v11 = _mm_getcsr();
    if ( (v11 & 0x80u) != 0 )
      v10 = 16;
    if ( (v11 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v10 |= 0x80000u;
    v12 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v12 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v13 = (v11 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
          v10 |= (unsigned int)&unk_1000000;
      }
      else
      {
        v10 |= (unsigned int)&unk_3000000;
      }
    }
    else
    {
      v10 |= (unsigned int)&unk_2000000;
    }
    v15 = newctrl & (unsigned int)&unk_308031F & v2 | v10 & ~((unsigned int)&unk_308031F & v2);
    if ( v15 == v10 )
    {
      v16 = v10;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v16 = 0;
      if ( (v17 & 0x80u) != 0 )
        v16 = 16;
      if ( (v17 & 0x200) != 0 )
        v16 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v16 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v16 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v16 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v16 |= 0x80000u;
      v18 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v18 )
        {
          case 8192:
            v16 |= 0x100u;
            break;
          case 16384:
            v16 |= 0x200u;
            break;
          case 24576:
            v16 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v19 = (v17 & 0x8040) - 64;
      if ( v19 != 0 )
      {
        v20 = v19 - 32704;
        if ( v20 != 0 )
        {
          if ( v20 == 64 )
            v16 |= (unsigned int)&unk_1000000;
        }
        else
        {
          v16 |= (unsigned int)&unk_3000000;
        }
      }
      else
      {
        v16 |= (unsigned int)&unk_2000000;
      }
    }
    v21 = v22 ^ v16;
    result = v22 | v16;
    if ( (v21 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047D25D
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp_l(char *dst, char *src, unsigned int count, localeinfo_struct *plocinfo)
{
  char *v4; // esi
  int v5; // edi
  int v6; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  if ( count != 0 )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( dst != nullptr && (v4 = src, src != nullptr) )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
        {
          do
          {
            v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
            v6 = _tolower_l(c: (unsigned __int8)*v4++, plocinfo: &_loc_update.localeinfo);
            --count;
          }
          while ( count != 0 && v5 != 0 && v5 == v6 );
        }
        else
        {
          __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
        }
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
      else
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D33F
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp(char *dst, char *src, unsigned int count)
{
  if ( __locale_changed != 0 )
  {
    _strnicmp_l(dst, src, count, plocinfo: nullptr);
  }
  else if ( dst != nullptr && src != nullptr && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D392
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconout()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONOUT$",
             dwDesiredAccess: 0x40000000u,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _confh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047D3B1
// Name: ___termconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconout()
{
  HANDLE result; // eax

  result = _confh;
  if ( _confh != (HANDLE)-1 && _confh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _confh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047D3C8
// Name: ___crtCompareStringW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringW(
        LCID Locale,
        DWORD dwCmpFlags,
        const wchar_t *lpString1,
        int cchCount1,
        const wchar_t *lpString2,
        int cchCount2)
{
  int v6; // esi
  int v7; // eax

  v6 = cchCount1;
  if ( cchCount1 > 0 )
    v6 = wcsnlen(wcs: lpString1, maxsize: cchCount1);
  v7 = cchCount2;
  if ( cchCount2 > 0 )
    v7 = wcsnlen(wcs: lpString2, maxsize: cchCount2);
  if ( v6 != 0 && v7 != 0 )
    return CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1: v6, lpString2, cchCount2: v7);
  if ( v6 == v7 )
    return 2;
  return 2 * (v6 - v7 >= 0) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047D42B
// Name: __mbsnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsnicmp_l(char *s1, char *s2, unsigned int n, localeinfo_struct *plocinfo)
{
  char *v4; // edi
  char *v5; // ebx
  int v6; // ecx
  bool v7; // zf
  int v8; // ecx
  __int16 v9; // si
  char *v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  char *v14; // ecx
  int v15; // ecx
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  int c1; // [esp+10h] [ebp-4h]

  if ( n == 0 )
    return;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    _strnicmp(dst: s1, src: s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v4 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v5 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  while ( 1 )
  {
    v6 = (unsigned __int8)*v4;
    --n;
    ++v4;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) == 0;
    c1 = v6;
    if ( v7 )
    {
      v10 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v10[29] & 0x10) != 0 )
        v11 = (unsigned __int8)v10[285];
      else
        v11 = (unsigned __int16)c1;
      c1 = v11;
      goto LABEL_26;
    }
    if ( *v4 == 0 )
    {
      c1 = 0;
LABEL_26:
      v9 = c1;
      goto LABEL_27;
    }
    v8 = (unsigned __int16)((unsigned __int8)*v4 | (unsigned __int16)((_WORD)v6 << 8));
    v9 = v8;
    ++v4;
    c1 = v8;
    if ( (unsigned __int16)v8 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v8 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v8 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v8 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v8;
      }
    }
    else
    {
      v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v8;
    }
LABEL_27:
    v12 = (unsigned __int8)*v5++;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v12 + 1] & 4) == 0;
    c1 = v12;
    if ( v7 )
    {
      v14 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v14[29] & 0x10) != 0 )
        v15 = (unsigned __int8)v14[285];
      else
        v15 = (unsigned __int16)c1;
      c1 = v15;
      goto LABEL_40;
    }
    if ( *v5 == 0 )
    {
      c1 = 0;
LABEL_40:
      LOWORD(v13) = c1;
      goto LABEL_41;
    }
    v13 = (unsigned __int16)((unsigned __int8)*v5++ | (unsigned __int16)((_WORD)v12 << 8));
    c1 = v13;
    if ( (unsigned __int16)v13 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v13 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v13 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v13 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        LOWORD(v13) = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v13;
      }
    }
    else
    {
      LOWORD(v13) = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v13;
    }
LABEL_41:
    if ( (_WORD)v13 != v9 )
      break;
    if ( v9 == 0 || n == 0 )
    {
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x0047D5F6
// Name: __mbsnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsnicmp(char *s1, char *s2, unsigned int n)
{
  _mbsnicmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0047D610
// Name: ___ascii_strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __ascii_strnicmp(unsigned __int8 *first, unsigned __int8 *last, unsigned int count)
{
  unsigned int i; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al

  for ( i = count; i != 0; --i )
  {
    v6 = *first;
    v7 = *last;
    if ( *first == 0 || v7 == 0 )
      break;
    ++first;
    ++last;
    if ( v6 >= 0x41u && v6 <= 0x5Au )
      v6 += 32;
    if ( v7 >= 0x41u && v7 <= 0x5Au )
      v7 += 32;
    if ( v6 != v7 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D672
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

} // namespace vbsp

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10019480
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x100194A0
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x100194D0
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00436E00
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return (const ImageFormatInfo_t *)(12 * fmt + 6012492);
}

//------------------------------------------------------------------------------
// Address: 0x00436E10
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x00436E40
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00436EB0
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebp
  int v13; // ebx
  int v14; // esi

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    v12 = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v13 = height;
    v14 = width;
    do
    {
      v12 += ImageLoader::GetMemRequired(
               width: v14,
               height: v13,
               depth: v6,
               nMipmapCount: 1,
               imageFormat,
               pAdjustedHeight: nullptr);
      if ( v14 == 1 && v13 == 1 && v6 == 1 )
        break;
      v14 >>= 1;
      v13 >>= 1;
      v6 >>= 1;
      if ( v14 < 1 )
        v14 = 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return v12;
  }
  return result;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00459040
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x00459060
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x00459090
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459100
// Name: enum _D3DFORMAT ImageLoader::ImageFormatToD3DFormat(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
_D3DFORMAT __cdecl ImageLoader::ImageFormatToD3DFormat(ImageFormat format)
{
  return s_pD3DFormats[format + 1];
}

//------------------------------------------------------------------------------
// Address: 0x00459110
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459272
// Name: Direct3DCreate9(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
IDirect3D9 *__stdcall Direct3DCreate9(UINT SDKVersion)
{
  return __imp__Direct3DCreate9@4(SDKVersion);
}

//------------------------------------------------------------------------------
// Address: 0x00459278
// Name: struct _D3DXFORMAT_INFO const __near * D3DXTex::GetFormatInfo(enum _D3DFORMAT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct _D3DXFORMAT_INFO *__stdcall D3DXTex::GetFormatInfo(D3DXTex *this, enum _D3DFORMAT a2)
{
  const struct _D3DXFORMAT_INFO *result; // eax

  result = (const struct _D3DXFORMAT_INFO *)&unk_6C85F8;
  if ( off_769290 <= &unk_6C85F8 )
    return (const struct _D3DXFORMAT_INFO *)&unk_6C85D0;
  while ( this != *(D3DXTex **)result )
  {
    result = (const struct _D3DXFORMAT_INFO *)((char *)result + 36);
    if ( result >= (const struct _D3DXFORMAT_INFO *)off_769290 )
      return (const struct _D3DXFORMAT_INFO *)&unk_6C85D0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004592A3
// Name: sub_4592A3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall sub_4592A3(int a1, int a2)
{
  unsigned int result; // eax
  unsigned int *v3; // esi
  int v4; // edi
  int i; // ebx
  unsigned int v6; // ecx
  unsigned int v7; // edx
  int v8; // [esp+4h] [ebp-4h]

  result = 0;
  if ( dword_6C8E00[5 * *(_DWORD *)(a1 + 4) + *(_DWORD *)(a2 + 4)] == 0 )
    return -1;
  v8 = 0;
  v3 = (unsigned int *)(a1 + 12);
  v4 = a2 - a1;
  for ( i = 5; i != 0; --i )
  {
    v6 = *v3;
    if ( *v3 != 0 )
      ++v8;
    v7 = *(unsigned int *)((char *)v3 + v4);
    if ( v6 >= v7 )
    {
      if ( v6 > v7 )
      {
        if ( v7 != 0 )
          result += (v6 - v7) << 16;
        else
          result += 0x1000000;
      }
    }
    else if ( v6 != 0 )
    {
      result += v7 - v6;
    }
    else
    {
      result += 256;
    }
    ++v3;
  }
  if ( v8 == HIBYTE(result) )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045931A
// Name: enum _D3DFORMAT D3DXTex::FindClosestFormat(enum _D3DFORMAT const __near *,struct tagPALETTEENTRY const __near *,struct _D3DXFORMAT_INFO const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
enum _D3DFORMAT __stdcall D3DXTex::FindClosestFormat(
        D3DXTex **this,
        const enum _D3DFORMAT *a2,
        const struct tagPALETTEENTRY *a3,
        const struct _D3DXFORMAT_INFO *a4)
{
  D3DXTex **v4; // eax
  unsigned int v5; // ebx
  const struct _D3DXFORMAT_INFO *v6; // edi
  const struct _D3DXFORMAT_INFO *FormatInfo; // esi
  unsigned int v8; // eax
  D3DXTex *v9; // eax
  enum _D3DFORMAT v11; // [esp+0h] [ebp-Ch]

  v4 = this;
  v5 = -1;
  v6 = (const struct _D3DXFORMAT_INFO *)&unk_6C85D0;
  while ( 1 )
  {
    v9 = *v4;
    if ( v9 == nullptr )
      return *(_DWORD *)v6;
    FormatInfo = D3DXTex::GetFormatInfo(this: v9, a2: v11);
    if ( *(_DWORD *)FormatInfo != 0 && (*((_DWORD *)FormatInfo + 1) != 1 || a2 != nullptr) )
      break;
LABEL_11:
    v4 = ++this;
  }
  if ( *a3 != *(_DWORD *)FormatInfo )
  {
    v8 = sub_4592A3(a1: (int)a3, a2: (int)FormatInfo);
    if ( v8 != -1 && v8 <= v5 && (v8 != v5 || *((_DWORD *)FormatInfo + 2) < *((_DWORD *)v6 + 2)) )
    {
      v5 = v8;
      v6 = FormatInfo;
    }
    goto LABEL_11;
  }
  return (enum _D3DFORMAT)*a3;
}

//------------------------------------------------------------------------------
// Address: 0x0045938B
// Name: enum _D3DFORMAT D3DXTex::FindClosestDeviceFormat(struct IDirect3DDevice9 __near *,unsigned long,enum _D3DRESOURCETYPE,struct _D3DXFORMAT_INFO const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
enum _D3DFORMAT __stdcall D3DXTex::FindClosestDeviceFormat(
        D3DXTex *this,
        unsigned int a2,
        unsigned int a3,
        _DWORD *a4,
        const struct _D3DXFORMAT_INFO *a5)
{
  unsigned int v5; // ebx
  _DWORD *v6; // edi
  _DWORD *v7; // esi
  unsigned int v8; // eax
  _DWORD v10[76]; // [esp+Ch] [ebp-154h] BYREF
  _BYTE v11[12]; // [esp+13Ch] [ebp-24h] BYREF
  int v12; // [esp+148h] [ebp-18h]
  _BYTE v13[16]; // [esp+14Ch] [ebp-14h] BYREF
  int v14; // [esp+15Ch] [ebp-4h] BYREF

  v14 = 0;
  D3DXDebugMuteInt(a1: 1);
  if ( this != nullptr )
  {
    (*(void (__stdcall **)(D3DXTex *, int *))(*(_DWORD *)this + 24))(a1: this, a2: &v14);
    (*(void (__stdcall **)(D3DXTex *, _DWORD *))(*(_DWORD *)this + 28))(a1: this, a2: v10);
    (*(void (__stdcall **)(D3DXTex *, _DWORD, _BYTE *))(*(_DWORD *)this + 32))(a1: this, a2: 0, a3: v11);
    if ( (a2 & 0x100000) != 0 )
    {
      (*(void (__stdcall **)(D3DXTex *, _BYTE *))(*(_DWORD *)this + 36))(a1: this, a2: v13);
      if ( (v13[12] & 0x20) != 0 )
        a2 |= 0x10u;
    }
  }
  v5 = -1;
  v6 = &unk_6C85D0;
  v7 = &unk_6C85F8;
  if ( off_769290 > &unk_6C85F8 )
  {
    do
    {
      if ( *v7 != 0
        && (v14 == 0
         || (*(int (__stdcall **)(int, _DWORD, _DWORD, int, unsigned int, unsigned int, _DWORD))(*(_DWORD *)v14 + 40))(
              a1: v14,
              a2: v10[1],
              a3: v10[0],
              a4: v12,
              a5: a2,
              a6: a3,
              a7: *v7) >= 0) )
      {
        if ( *a4 == *v7 )
        {
          v6 = v7;
          break;
        }
        if ( v7[8] != 0 )
        {
          v8 = sub_4592A3(a1: (int)a4, a2: (int)v7);
          if ( v8 != -1 && v8 <= v5 && (v8 != v5 || v7[2] < v6[2]) )
          {
            v5 = v8;
            v6 = v7;
          }
        }
      }
      v7 += 9;
    }
    while ( v7 < (_DWORD *)off_769290 );
  }
  if ( v14 != 0 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v14 + 8))(a1: v14);
    v14 = 0;
  }
  D3DXDebugMuteInt(a1: 0);
  return *v6;
}

//------------------------------------------------------------------------------
// Address: 0x00459489
// Name: enum _D3DFORMAT D3DXTex::FindClosestExternalFormat(enum _D3DFORMAT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
enum _D3DFORMAT __stdcall D3DXTex::FindClosestExternalFormat(D3DXTex *this, enum _D3DFORMAT a2)
{
  enum _D3DFORMAT result; // eax

  result = (enum _D3DFORMAT)this;
  if ( this == (D3DXTex *)909200449 )
    return D3DFMT_A8L8;
  if ( this != (D3DXTex *)909201952 )
    return result;
  return D3DFMT_A16B16G16R16;
}

//------------------------------------------------------------------------------
// Address: 0x004594AA
// Name: D3DXLoadSurfaceFromMemory(x,x,x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXLoadSurfaceFromMemory(
        struct IDirect3DSurface9 *a1,
        const struct tagPALETTEENTRY *a2,
        struct tagRECT *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        _DWORD *a8,
        unsigned int a9,
        int a10)
{
  int v10; // ebx
  int v11; // eax
  _BYTE v13[72]; // [esp+4h] [ebp-C8h] BYREF
  int v14; // [esp+4Ch] [ebp-80h]
  _BYTE v15[20]; // [esp+58h] [ebp-74h] BYREF
  _DWORD v16[4]; // [esp+6Ch] [ebp-60h] BYREF
  _DWORD v17[17]; // [esp+7Ch] [ebp-50h]
  _BYTE v18[12]; // [esp+C0h] [ebp-Ch] BYREF

  D3DXTex::CBlt::CBlt(this: (D3DXTex::CBlt *)v18);
  D3DXTex::CLockSurface::CLockSurface(a1: v15);
  v10 = 0;
  if ( a1 != nullptr )
  {
    if ( a4 != 0 && a8 != nullptr )
    {
      if ( a9 == -1 )
        a9 = 524292;
      v11 = D3DXTex::CLockSurface::Lock(
              this: (D3DXTex::CLockSurface *)v15,
              a2: (struct D3DX_BLT *)v13,
              a3: a1,
              a4: a2,
              a5: a3,
              a6: 0,
              a7: 0);
      if ( v11 < 0 )
        goto LABEL_10;
      v16[1] = a5;
      v16[2] = a6;
      v16[0] = a4;
      v16[3] = 0;
      v17[0] = *a8;
      v17[1] = a8[1];
      v17[2] = a8[2];
      v17[3] = a8[3];
      v17[4] = 0;
      v17[5] = 1;
      qmemcpy(&v17[6], v17, 24);
      v17[14] = v14;
      v17[15] = a10;
      v17[16] = a7;
      v11 = D3DXTex::CBlt::Blt(
              this: (D3DXTex::CBlt *)v18,
              a2: (struct D3DX_BLT *)v13,
              a3: (struct D3DX_BLT *)v16,
              a4: a9);
      if ( v11 < 0 )
LABEL_10:
        v10 = v11;
    }
    else
    {
      v10 = -2005530516;
    }
  }
  else
  {
    v10 = -2005530516;
  }
  D3DXTex::CLockSurface::~CLockSurface(a1: v15);
  D3DXTex::CBlt::~CBlt(this: (D3DXTex::CBlt *)v18);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00459592
// Name: D3DXLoadVolumeFromMemory(x,x,x,x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXLoadVolumeFromMemory(
        struct IDirect3DVolume9 *a1,
        const struct tagPALETTEENTRY *a2,
        struct _D3DBOX *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        const void *a9,
        unsigned int a10,
        int a11)
{
  int v11; // esi
  int v12; // eax
  _BYTE v14[72]; // [esp+4h] [ebp-B8h] BYREF
  int v15; // [esp+4Ch] [ebp-70h]
  _DWORD v16[4]; // [esp+58h] [ebp-64h] BYREF
  _BYTE v17[24]; // [esp+68h] [ebp-54h] BYREF
  _DWORD v18[11]; // [esp+80h] [ebp-3Ch] BYREF
  _BYTE v19[12]; // [esp+ACh] [ebp-10h] BYREF
  _BYTE v20[4]; // [esp+B8h] [ebp-4h] BYREF

  D3DXTex::CBlt::CBlt(this: (D3DXTex::CBlt *)v19);
  D3DXTex::CLockVolume::CLockVolume(a1: v20);
  if ( a1 != nullptr && a4 != 0 && a9 != nullptr )
  {
    if ( a10 == -1 )
      a10 = 524292;
    v12 = D3DXTex::CLockVolume::Lock(
            this: (D3DXTex::CLockVolume *)v20,
            a2: (struct D3DX_BLT *)v14,
            a3: a1,
            a4: a2,
            a5: a3,
            a6: 0,
            a7: 0);
    if ( v12 < 0 )
      goto LABEL_8;
    v16[1] = a5;
    v16[2] = a6;
    v16[3] = a7;
    v16[0] = a4;
    qmemcpy(v17, a9, sizeof(v17));
    qmemcpy(v18, a9, 0x18u);
    v18[8] = v15;
    v18[9] = a11;
    v18[10] = a8;
    v12 = D3DXTex::CBlt::Blt(
            this: (D3DXTex::CBlt *)v19,
            a2: (struct D3DX_BLT *)v14,
            a3: (struct D3DX_BLT *)v16,
            a4: a10);
    if ( v12 < 0 )
LABEL_8:
      v11 = v12;
    else
      v11 = 0;
  }
  else
  {
    v11 = -2005530516;
  }
  D3DXTex::CLockVolume::~CLockVolume(a1: v20);
  D3DXTex::CBlt::~CBlt(this: (D3DXTex::CBlt *)v19);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x0045966E
// Name: sub_45966E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_45966E@<eax>(
        D3DXTex *a1@<edx>,
        enum _D3DFORMAT a2@<esi>,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        int *a6,
        unsigned int a7,
        D3DXTex **a8,
        unsigned int a9,
        unsigned int a10)
{
  const struct _D3DXFORMAT_INFO *FormatInfo; // eax
  int v13; // edx
  unsigned int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  bool v18; // cc
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // edi
  int v23; // eax
  int v24; // ecx
  unsigned int v25; // esi
  unsigned int i; // eax
  unsigned int v27; // ecx
  unsigned int j; // eax
  unsigned int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // eax
  const struct _D3DXFORMAT_INFO *v32; // [esp-4h] [ebp-150h]
  char v33[60]; // [esp+8h] [ebp-144h] BYREF
  int v34; // [esp+44h] [ebp-108h]
  unsigned int v35; // [esp+60h] [ebp-ECh]
  unsigned int v36; // [esp+64h] [ebp-E8h]
  unsigned int v37; // [esp+68h] [ebp-E4h]
  int v38; // [esp+70h] [ebp-DCh]
  unsigned int v39; // [esp+138h] [ebp-14h]
  D3DXTex *ClosestDeviceFormat; // [esp+13Ch] [ebp-10h]
  unsigned int v41; // [esp+140h] [ebp-Ch]
  unsigned int v42; // [esp+144h] [ebp-8h]
  unsigned int v43; // [esp+148h] [ebp-4h]

  if ( a1 == nullptr )
    return -2005530516;
  if ( a7 == -1 )
    a7 = 0;
  if ( (a7 & 0xFFE039EC) != 0 || a9 >= 4 )
    return -2005530516;
  if ( a8 != nullptr )
    ClosestDeviceFormat = *a8;
  else
    ClosestDeviceFormat = nullptr;
  if ( a9 == 3 )
  {
    if ( ClosestDeviceFormat == nullptr )
      ClosestDeviceFormat = (D3DXTex *)21;
  }
  else
  {
    FormatInfo = D3DXTex::GetFormatInfo(this: ClosestDeviceFormat, a2);
    ClosestDeviceFormat = (D3DXTex *)D3DXTex::FindClosestDeviceFormat(
                                       this: a1,
                                       a2: a7,
                                       a3: a10,
                                       a4: FormatInfo,
                                       a5: v32);
    if ( ClosestDeviceFormat == nullptr )
      return -2005530518;
  }
  if ( a3 != nullptr )
    v42 = *a3;
  else
    v42 = -1;
  if ( a4 != nullptr )
    v43 = *a4;
  else
    v43 = -1;
  if ( a5 != nullptr )
    v41 = *a5;
  else
    v41 = -1;
  if ( a6 != nullptr )
    v39 = *a6;
  else
    v39 = -1;
  if ( v42 == -1 )
  {
    if ( v43 == -1 )
    {
      v43 = 256;
      v42 = 256;
      goto LABEL_38;
    }
    v42 = v43;
  }
  else if ( v43 == -1 )
  {
    v43 = v42;
  }
  if ( v42 == 0 )
    v42 = 1;
  if ( v43 == 0 )
    v43 = 1;
LABEL_38:
  if ( a10 == 5 )
  {
    if ( v42 > v43 )
      v43 = v42;
    v42 = v43;
  }
  if ( v41 == -1 || v41 == 0 )
    v41 = 1;
  if ( a9 != 3 )
  {
    (*(void (__stdcall **)(D3DXTex *, char *))(*(_DWORD *)a1 + 28))(a1, a2: v33);
    v13 = v34;
    if ( a10 == 4 )
    {
      v14 = v37;
      if ( v41 > v37 )
        v41 = v37;
      if ( v42 > v37 )
        v42 = v37;
    }
    else
    {
      if ( v42 > v35 )
        v42 = v35;
      if ( v43 > v36 )
        v43 = v36;
      if ( a10 != 3 )
        goto LABEL_65;
      v15 = (v34 & 0x20) != 0 ? 1 : v38;
      if ( v15 == 0 )
        goto LABEL_65;
      if ( v42 > v43 * v15 )
        v42 = v43 * v15;
      v14 = v42 * v15;
    }
    if ( v43 > v14 )
      v43 = v14;
LABEL_65:
    switch ( a10 )
    {
      case 3u:
        v16 = 2;
        break;
      case 4u:
        v16 = 0x40000;
        break;
      case 5u:
        v16 = 0x20000;
        break;
      default:
        v16 = a10;
        break;
    }
    if ( v39 == 1
      && (v34 & 0x100) != 0
      && ClosestDeviceFormat != (D3DXTex *)827611204
      && ClosestDeviceFormat != (D3DXTex *)844388420
      && ClosestDeviceFormat != (D3DXTex *)861165636
      && ClosestDeviceFormat != (D3DXTex *)877942852
      && ClosestDeviceFormat != (D3DXTex *)894720068 )
    {
      v16 = 0;
    }
    if ( (v16 & v34) != 0 )
    {
      v17 = v42;
      v18 = v42 <= 1;
      v42 = 1;
      if ( !v18 )
      {
        do
          v42 *= 2;
        while ( v42 < v17 );
      }
      v19 = v43;
      v18 = v43 <= 1;
      v43 = 1;
      if ( !v18 )
      {
        do
          v43 *= 2;
        while ( v43 < v19 );
      }
      v20 = v41;
      v18 = v41 <= 1;
      v41 = 1;
      if ( !v18 )
      {
        do
          v41 *= 2;
        while ( v41 < v20 );
      }
    }
    goto LABEL_89;
  }
  v13 = v34;
LABEL_89:
  if ( ClosestDeviceFormat == (D3DXTex *)827611204
    || ClosestDeviceFormat == (D3DXTex *)844388420
    || ClosestDeviceFormat == (D3DXTex *)861165636
    || ClosestDeviceFormat == (D3DXTex *)877942852
    || ClosestDeviceFormat == (D3DXTex *)894720068 )
  {
    v21 = (v42 + 3) & 0xFFFFFFFC;
    v22 = (v43 + 3) & 0xFFFFFFFC;
    v42 = v21;
    v43 = v22;
  }
  else
  {
    v21 = v42;
    v22 = v43;
  }
  switch ( a10 )
  {
    case 3u:
      v23 = 0x4000;
      break;
    case 4u:
      v23 = 0x8000;
      break;
    case 5u:
      v23 = 0x10000;
      break;
    default:
      v23 = a10;
      break;
  }
  if ( a9 != 3
    && ((v23 & v13) == 0
     || (v13 & 0x100) != 0 && (((v21 - 1) & v21) != 0 || ((v22 - 1) & v22) != 0 || ((v41 - 1) & v41) != 0)) )
  {
    v39 = 1;
    v24 = 1;
  }
  else
  {
    v25 = 0;
    for ( i = v21; i != 0; ++v25 )
      i >>= 1;
    v27 = 0;
    for ( j = v22; j != 0; ++v27 )
      j >>= 1;
    v29 = v41;
    v30 = 0;
    while ( v29 != 0 )
    {
      v29 >>= 1;
      ++v30;
    }
    v31 = v25;
    if ( v25 <= v27 )
      v31 = v27;
    if ( a10 == 4 && v30 > v31 )
      v31 = v30;
    v24 = v39;
    if ( v39 > v31 || v39 == 0 )
      v24 = v31;
    if ( v24 != 1 && (a7 & 0x400) != 0 )
      v24 = 0;
  }
  if ( a3 != nullptr )
    *a3 = v42;
  if ( a4 != nullptr )
    *a4 = v43;
  if ( a5 != nullptr )
    *a5 = v41;
  if ( a6 != nullptr )
    *a6 = v24;
  if ( a8 != nullptr )
    *a8 = ClosestDeviceFormat;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00459A23
// Name: D3DXLoadSurfaceFromSurface(x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXLoadSurfaceFromSurface@<eax>(
        int a1@<edi>,
        struct IDirect3DSurface9 *a2,
        const struct tagPALETTEENTRY *a3,
        struct tagRECT *a4,
        struct IDirect3DSurface9 *a5,
        const struct tagPALETTEENTRY *a6,
        struct tagRECT *a7,
        unsigned int a8,
        int a9)
{
  int v9; // esi
  struct IDirect3DSurface9 *v10; // ebx
  int right; // edx
  int bottom; // esi
  int v13; // ecx
  int v14; // eax
  int v15; // esi
  int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  int v19; // esi
  int v22[10]; // [esp+4h] [ebp-C8h] BYREF
  int v23[11]; // [esp+2Ch] [ebp-A0h] BYREF
  _BYTE v24[20]; // [esp+58h] [ebp-74h] BYREF
  _BYTE v25[12]; // [esp+6Ch] [ebp-60h] BYREF
  int v26; // [esp+78h] [ebp-54h]
  int v27; // [esp+84h] [ebp-48h]
  int v28; // [esp+88h] [ebp-44h]
  char v29; // [esp+8Ch] [ebp-40h] BYREF
  int v30; // [esp+98h] [ebp-34h]
  int v31; // [esp+A4h] [ebp-28h]
  int v32; // [esp+A8h] [ebp-24h]
  struct tagRECT v33; // [esp+ACh] [ebp-20h] BYREF
  struct tagRECT v34; // [esp+BCh] [ebp-10h] BYREF

  D3DXTex::CLockSurface::CLockSurface(a1: v24);
  if ( a2 != nullptr )
  {
    v10 = a5;
    if ( a5 == nullptr )
    {
      v9 = -2005530516;
      goto LABEL_36;
    }
    a2->GetDesc(this: a2, a2: (_D3DSURFACE_DESC *)v25);
    v10->GetDesc(this: v10, a2: (_D3DSURFACE_DESC *)&v29);
    if ( (unsigned __int16)a8 == 5
      || a9 != 0
      || a3 != a6 && (a3 == nullptr || a6 == nullptr || memcmp(a3, a6, 0x400u) != 0) )
    {
      goto LABEL_26;
    }
    if ( a4 != nullptr )
    {
      v34 = *a4;
      bottom = v34.bottom;
      right = v34.right;
    }
    else
    {
      right = v27;
      bottom = v28;
      v34.left = 0;
      v34.top = 0;
      v34.right = v27;
      v34.bottom = v28;
    }
    if ( a7 != nullptr )
    {
      v33 = *a7;
      v13 = v33.bottom;
      v14 = v33.right;
      bottom = v34.bottom;
    }
    else
    {
      v13 = v32;
      v33.left = 0;
      v33.top = 0;
      v14 = v31;
      v33.right = v31;
      v33.bottom = v32;
    }
    if ( right - v34.left != v14 - v33.left || bottom - v34.top != v13 - v33.top )
    {
LABEL_26:
      v17 = 1;
      if ( a2 == v10 )
        v17 = 65537;
      v18 = D3DXTex::CLockSurface::Lock(
              this: (D3DXTex::CLockSurface *)v24,
              a2: (struct D3DX_BLT *)v22,
              a3: v10,
              a4: a6,
              a5: a7,
              a6: 0,
              a7: v17);
      if ( v18 < 0
        || (v18 = D3DXLoadSurfaceFromMemory(
                    a1: a2,
                    a2: a3,
                    a3: a4,
                    a4: v22[0],
                    a5: v22[1],
                    a6: v22[2],
                    a7: (int)a6,
                    a8: v23,
                    a9: a8,
                    a10: a9)) < 0 )
      {
        v9 = v18;
        goto LABEL_36;
      }
      if ( v30 == 0 && v26 != 0 )
      {
        v10->GetDevice(this: v10, (IDirect3DDevice9 **)&a2);
        v19 = ((int (__stdcall *)(struct IDirect3DSurface9 *))a2->GetDevice)(a1: a2);
        a2->Release(this: a2);
        if ( v19 != 0 )
        {
          v9 = -2005530520;
          goto LABEL_36;
        }
      }
LABEL_35:
      v9 = 0;
      goto LABEL_36;
    }
    ((void (__stdcall *)(struct IDirect3DSurface9 *, struct IDirect3DSurface9 **, int))v10->GetDevice)(
      a1: v10,
      a2: &a5,
      a3: a1);
    D3DXDebugMuteInt(a1: 1);
    v15 = -2147467259;
    if ( v26 == 0 )
    {
      if ( v30 != 0 )
      {
        if ( v30 != 2 )
          goto LABEL_25;
        v16 = ((int (__stdcall *)(struct IDirect3DSurface9 *, struct IDirect3DSurface9 *, struct tagRECT *, struct IDirect3DSurface9 *, struct tagRECT *))a5->__vftable[1].LockRect)(
                a1: a5,
                a2: v10,
                a3: &v33,
                a4: a2,
                a5: &v34);
      }
      else
      {
        v16 = ((int (__stdcall *)(struct IDirect3DSurface9 *, struct IDirect3DSurface9 *, struct tagRECT *, struct IDirect3DSurface9 *, struct tagRECT *, _DWORD))a5->__vftable[2].QueryInterface)(
                a1: a5,
                a2: v10,
                a3: &v33,
                a4: a2,
                a5: &v34,
                a6: 0);
      }
      v15 = v16;
    }
LABEL_25:
    D3DXDebugMuteInt(a1: 0);
    ((void (__cdecl *)(struct IDirect3DSurface9 *))a5->Release)(a1: a5);
    if ( v15 >= 0 )
      goto LABEL_35;
    goto LABEL_26;
  }
  v9 = -2005530516;
LABEL_36:
  D3DXTex::CLockSurface::~CLockSurface(a1: v24);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00459C37
// Name: D3DXLoadVolumeFromVolume(x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXLoadVolumeFromVolume(
        struct IDirect3DVolume9 *a1,
        const struct tagPALETTEENTRY *a2,
        struct _D3DBOX *a3,
        struct IDirect3DVolume9 *a4,
        const struct tagPALETTEENTRY *a5,
        struct _D3DBOX *a6,
        unsigned int a7,
        int a8)
{
  int v8; // esi
  unsigned int v9; // eax
  int v10; // eax
  int v12[10]; // [esp+4h] [ebp-58h] BYREF
  int v13[11]; // [esp+2Ch] [ebp-30h] BYREF
  _BYTE v14[4]; // [esp+58h] [ebp-4h] BYREF

  D3DXTex::CLockVolume::CLockVolume(a1: v14);
  v8 = 0;
  if ( a1 != nullptr && a4 != nullptr )
  {
    v9 = 1;
    if ( a1 == a4 )
      v9 = 65537;
    v10 = D3DXTex::CLockVolume::Lock(
            this: (D3DXTex::CLockVolume *)v14,
            a2: (struct D3DX_BLT *)v12,
            a3: a4,
            a4: a5,
            a5: a6,
            a6: 0,
            a7: v9);
    if ( v10 < 0
      || (v10 = D3DXLoadVolumeFromMemory(
                  a1,
                  a2,
                  a3,
                  a4: v12[0],
                  a5: v12[1],
                  a6: v12[2],
                  a7: v12[3],
                  a8: (int)a5,
                  a9: v13,
                  a10: a7,
                  a11: a8)) < 0 )
    {
      v8 = v10;
    }
  }
  else
  {
    v8 = -2005530516;
  }
  D3DXTex::CLockVolume::~CLockVolume(a1: v14);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00459D5B
// Name: D3DXFilterTexture(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXFilterTexture(
        struct IDirect3DSurface9 *a1,
        const struct tagPALETTEENTRY *a2,
        unsigned int a3,
        unsigned int a4)
{
  struct IDirect3DSurface9 *v4; // esi
  int v6; // eax
  unsigned int v7; // eax
  int v8; // esi
  int v9; // eax
  struct IDirect3DVolume9 **v10; // edx
  int v11; // edi
  int v12; // eax
  void *v13; // edx
  int v14; // eax
  _BYTE v15[24]; // [esp+8h] [ebp-60h] BYREF
  int v16; // [esp+20h] [ebp-48h]
  int v17; // [esp+24h] [ebp-44h]
  char v18; // [esp+28h] [ebp-40h] BYREF
  int v19; // [esp+38h] [ebp-30h]
  int v20; // [esp+3Ch] [ebp-2Ch]
  int v21; // [esp+40h] [ebp-28h]
  unsigned int v22; // [esp+44h] [ebp-24h]
  unsigned int v23; // [esp+48h] [ebp-20h]
  int v24; // [esp+4Ch] [ebp-1Ch]
  struct IDirect3DSurface9 *v25; // [esp+50h] [ebp-18h]
  unsigned int v26; // [esp+54h] [ebp-14h]
  _D3DRESOURCETYPE v27; // [esp+58h] [ebp-10h]
  struct IDirect3DVolume9 *v28; // [esp+5Ch] [ebp-Ch] BYREF
  struct IDirect3DVolume9 *v29; // [esp+60h] [ebp-8h] BYREF
  struct IDirect3DSurface9 *v30; // [esp+64h] [ebp-4h] BYREF

  v4 = a1;
  if ( a1 == nullptr )
    return -2005530516;
  v27 = a1->GetType(this: a1);
  if ( v27 != D3DRTYPE_TEXTURE && (unsigned int)(v27 - 4) >= 2 )
    return -2005530516;
  v25 = v4;
  if ( a4 != -1 )
    goto LABEL_15;
  if ( v27 == D3DRTYPE_TEXTURE )
  {
    v25->__vftable[1].QueryInterface(this: v25, a2: nullptr, a3: (void **)v15);
    if ( ((v16 - 1) & v16) != 0 || ((v17 - 1) & v17) != 0 )
    {
      a4 = 0;
      goto LABEL_14;
    }
    goto LABEL_22;
  }
  if ( v27 == D3DRTYPE_VOLUMETEXTURE )
  {
    v25->__vftable[1].QueryInterface(this: v25, a2: nullptr, a3: (void **)&v18);
    if ( ((v19 - 1) & v19) != 0 || ((v20 - 1) & v20) != 0 )
      goto LABEL_14;
    v6 = v21;
LABEL_13:
    if ( ((v6 - 1) & v6) != 0 )
      goto LABEL_14;
LABEL_22:
    a4 = 5;
    goto LABEL_15;
  }
  v25->__vftable[1].QueryInterface(this: v25, a2: nullptr, a3: (void **)v15);
  if ( ((v16 - 1) & v16) == 0 )
  {
    v6 = v17;
    goto LABEL_13;
  }
LABEL_14:
  a4 = 524292;
LABEL_15:
  if ( v27 == D3DRTYPE_CUBETEXTURE )
    BYTE2(a4) |= 7u;
  if ( (a4 & 0x400000) != 0 )
    BYTE2(a4) |= 0x60u;
  else
    BYTE2(a4) &= 0x9Fu;
  v7 = ((int (__stdcall *)(struct IDirect3DSurface9 *))v4->LockRect)(a1: v4);
  v23 = v7;
  if ( a3 == -1 )
    a3 = 0;
  if ( a3 >= v7 )
    return -2005530516;
  a1 = nullptr;
  v29 = nullptr;
  v30 = nullptr;
  v28 = nullptr;
  v22 = v27 != D3DRTYPE_CUBETEXTURE ? 1 : 6;
  if ( (unsigned __int8)a4 == 2 || (v24 = 0, (unsigned __int8)a4 == 5) )
    v24 = 1;
  v26 = 0;
  v8 = a4;
  do
  {
    switch ( v27 )
    {
      case D3DRTYPE_TEXTURE:
        v10 = (struct IDirect3DVolume9 **)&a1;
        goto LABEL_38;
      case D3DRTYPE_VOLUMETEXTURE:
        v10 = &v29;
LABEL_38:
        v9 = ((int (__stdcall *)(struct IDirect3DSurface9 *, unsigned int, struct IDirect3DVolume9 **))v25->__vftable[1].AddRef)(
               a1: v25,
               a2: a3,
               a3: v10);
        goto LABEL_39;
      case D3DRTYPE_CUBETEXTURE:
        v9 = ((int (__stdcall *)(struct IDirect3DSurface9 *, unsigned int, unsigned int, struct IDirect3DSurface9 **))v25->__vftable[1].AddRef)(
               a1: v25,
               a2: v26,
               a3,
               a4: &a1);
LABEL_39:
        v8 = v9;
        break;
      default:
        break;
    }
    if ( v8 < 0 )
      goto LABEL_76;
    v11 = a3;
    while ( ++v11 < v23 )
    {
      switch ( v27 )
      {
        case D3DRTYPE_TEXTURE:
          v13 = &v30;
          goto LABEL_48;
        case D3DRTYPE_VOLUMETEXTURE:
          v13 = &v28;
LABEL_48:
          v12 = ((int (__stdcall *)(struct IDirect3DSurface9 *, int, void *))v25->__vftable[1].AddRef)(
                  a1: v25,
                  a2: v11,
                  a3: v13);
          goto LABEL_49;
        case D3DRTYPE_CUBETEXTURE:
          v12 = ((int (__stdcall *)(struct IDirect3DSurface9 *, unsigned int, int, struct IDirect3DSurface9 **))v25->__vftable[1].AddRef)(
                  a1: v25,
                  a2: v26,
                  a3: v11,
                  a4: &v30);
LABEL_49:
          v8 = v12;
          break;
        default:
          break;
      }
      if ( v8 < 0 )
        goto LABEL_76;
      switch ( v27 )
      {
        case D3DRTYPE_TEXTURE:
LABEL_54:
          v14 = D3DXLoadSurfaceFromSurface(
                  a1: v11,
                  a2: v30,
                  a3: a2,
                  a4: nullptr,
                  a5: a1,
                  a6: a2,
                  a7: nullptr,
                  a8: a4,
                  a9: 0);
LABEL_55:
          v8 = v14;
          break;
        case D3DRTYPE_VOLUMETEXTURE:
          v14 = D3DXLoadVolumeFromVolume(a1: v28, a2, a3: nullptr, a4: v29, a5: a2, a6: nullptr, a7: a4, a8: 0);
          goto LABEL_55;
        case D3DRTYPE_CUBETEXTURE:
          goto LABEL_54;
        default:
          break;
      }
      if ( v8 < 0 )
        goto LABEL_76;
      if ( v24 != 0 )
      {
        if ( a1 != nullptr )
        {
          a1->Release(this: a1);
          a1 = nullptr;
        }
        if ( v29 != nullptr )
          v29->Release(this: v29);
        a1 = v30;
        v30 = nullptr;
        v29 = v28;
LABEL_68:
        v28 = nullptr;
      }
      else
      {
        if ( v30 != nullptr )
        {
          v30->Release(this: v30);
          v30 = nullptr;
        }
        if ( v28 != nullptr )
        {
          v28->Release(this: v28);
          goto LABEL_68;
        }
      }
    }
    if ( a1 != nullptr )
    {
      a1->Release(this: a1);
      a1 = nullptr;
    }
    if ( v29 != nullptr )
    {
      v29->Release(this: v29);
      v29 = nullptr;
    }
    ++v26;
  }
  while ( v26 < v22 );
  v8 = 0;
LABEL_76:
  if ( a1 != nullptr )
  {
    a1->Release(this: a1);
    a1 = nullptr;
  }
  if ( v29 != nullptr )
  {
    v29->Release(this: v29);
    v29 = nullptr;
  }
  if ( v30 != nullptr )
  {
    v30->Release(this: v30);
    v30 = nullptr;
  }
  if ( v28 != nullptr )
    v28->Release(this: v28);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0045A04D
// Name: sub_45A04D
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_45A04D@<eax>(
        enum _D3DFORMAT a1@<ebx>,
        D3DXTex *a2,
        void *a3,
        unsigned int a4,
        enum _D3DFORMAT a5,
        unsigned int i,
        unsigned int j,
        unsigned int a8,
        struct IDirect3DDevice9 *a9,
        unsigned int a10,
        unsigned int a11,
        unsigned int a12,
        unsigned int a13,
        int a14,
        struct IDirect3DSurface9 *a15,
        const struct tagPALETTEENTRY *a16,
        unsigned int a17,
        struct IDirect3DSurface9 **a18)
{
  struct IDirect3DSurface9 *v18; // esi
  enum _D3DFORMAT v19; // edi
  int v20; // edi
  int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // ecx
  int v26; // edx
  unsigned int k; // eax
  unsigned int m; // eax
  D3DXTex *ClosestDeviceFormat; // esi
  const struct _D3DXFORMAT_INFO *FormatInfo; // eax
  D3DXTex *ClosestExternalFormat; // eax
  bool v32; // zf
  int v33; // eax
  enum _D3DFORMAT v34; // esi
  unsigned int v35; // ebx
  unsigned int v36; // ebx
  int v37; // eax
  int v38; // eax
  struct IDirect3DSurface9 *v39; // ebx
  int *v40; // esi
  int v41; // eax
  void *v42; // ecx
  int v43; // eax
  int v44; // eax
  void *v45; // ecx
  int v46; // eax
  struct IDirect3DSurface9 *v47; // ecx
  const struct _D3DXFORMAT_INFO *v49; // [esp-4h] [ebp-4E4h]
  struct tagPALETTEENTRY v50[256]; // [esp+8h] [ebp-4D8h] BYREF
  char v51; // [esp+408h] [ebp-D8h] BYREF
  D3DXTex *v52[2]; // [esp+424h] [ebp-BCh] BYREF
  int v53; // [esp+42Ch] [ebp-B4h]
  int v54; // [esp+430h] [ebp-B0h]
  int v55; // [esp+434h] [ebp-ACh]
  int v56; // [esp+438h] [ebp-A8h]
  int v57; // [esp+470h] [ebp-70h]
  int v58; // [esp+474h] [ebp-6Ch]
  _DWORD v59[4]; // [esp+478h] [ebp-68h]
  enum _D3DRESOURCETYPE v60[9]; // [esp+488h] [ebp-58h] BYREF
  BOOL v61; // [esp+4ACh] [ebp-34h]
  unsigned int v62; // [esp+4B0h] [ebp-30h]
  BOOL v63; // [esp+4B4h] [ebp-2Ch]
  unsigned int v64; // [esp+4B8h] [ebp-28h]
  BOOL v65; // [esp+4BCh] [ebp-24h]
  D3DXTex *v66; // [esp+4C0h] [ebp-20h]
  BOOL v67; // [esp+4C4h] [ebp-1Ch]
  BOOL v68; // [esp+4C8h] [ebp-18h]
  BOOL v69; // [esp+4CCh] [ebp-14h]
  int v70; // [esp+4D0h] [ebp-10h]
  struct IDirect3DSurface9 *v71; // [esp+4D4h] [ebp-Ch] BYREF
  struct IDirect3DSurface9 *v72; // [esp+4D8h] [ebp-8h] BYREF
  struct IDirect3DVolume9 *v73; // [esp+4DCh] [ebp-4h] BYREF
  enum _D3DFORMAT v74; // [esp+4ECh] [ebp+Ch]
  unsigned int v75; // [esp+4F0h] [ebp+10h]

  v18 = a15;
  v19 = a5;
  D3DXTex::CImage::CImage(this: (D3DXTex::CImage *)v52);
  v73 = nullptr;
  a15 = nullptr;
  v72 = nullptr;
  v71 = nullptr;
  if ( a2 == nullptr || a3 == nullptr || a4 == 0 || a18 == nullptr )
  {
    v20 = -2005530516;
    goto LABEL_196;
  }
  v49 = (const struct _D3DXFORMAT_INFO *)a1;
  v61 = v19 == -3;
  v65 = i == -3;
  v67 = j == -3;
  v63 = a8 == -3;
  v68 = a10 == -3;
  if ( v18 == nullptr && a17 == -1 )
    v18 = (struct IDirect3DSurface9 *)&v51;
  v21 = D3DXTex::CImage::Load(this: (D3DXTex::CImage *)v52, a2: a3, a3: a4, a4: (struct _D3DXIMAGE_INFO *)v18, a5: 1);
  if ( v21 < 0 )
  {
    v20 = v21;
    goto LABEL_196;
  }
  if ( a17 == -1 )
    a17 = (unsigned int)v18[5].__vftable;
  v22 = v57;
  v75 = 1;
  while ( v22 != 0 )
  {
    ++v75;
    v22 = *(_DWORD *)(v22 + 76);
  }
  v74 = 1;
  if ( a17 == 5 )
  {
    v23 = v58;
    if ( v58 == 0 )
      goto LABEL_20;
    do
    {
      v23 = *(_DWORD *)(v23 + 80);
      ++v74;
    }
    while ( v23 != 0 );
    if ( v74 != 6 )
    {
LABEL_20:
      v20 = -2147467259;
      goto LABEL_196;
    }
  }
  if ( a8 == -3 )
    a8 = v75;
  if ( v19 == -2 || v19 == -3 || v54 < 0 )
  {
    a5 = v54;
  }
  else if ( v19 == D3DFMT_UNKNOWN || v19 == (D3DFMT_FORCE_DWORD|0x80000000) )
  {
    a5 = 1;
    if ( (unsigned int)v54 > 1 )
    {
      do
        a5 *= 2;
      while ( a5 < (unsigned int)v54 );
    }
  }
  if ( i == -2 || i == -3 || v55 < 0 )
  {
    i = v55;
  }
  else if ( i == 0 || i == -1 )
  {
    for ( i = 1; i < v55; i *= 2 )
      ;
  }
  if ( j == -2 || j == -3 || v56 < 0 )
  {
    j = v56;
  }
  else if ( j == 0 || j == -1 )
  {
    for ( j = 1; j < v56; j *= 2 )
      ;
  }
  if ( a12 == -1 )
    a12 = 524292;
  if ( a13 == -1 )
    a13 = 5;
  if ( a17 == 5 )
  {
    a12 |= 0x70000u;
    a13 |= 0x70000u;
  }
  v69 = (_BYTE)a12 == 1 || (unsigned __int8)a13 == 2 || (unsigned __int8)a13 == 5;
  if ( v53 != 0 )
  {
    v24 = a14 & 0xFF00FF00 | ((unsigned __int8)a14 << 16) | BYTE2(a14);
    v25 = 0;
    v26 = v53 - (_DWORD)v50;
    do
    {
      v50[v25] = v24 != *(_DWORD *)((char *)&v50[v25] + v26) ? *(struct tagPALETTEENTRY *)((char *)&v50[v25] + v26) : 0;
      ++v25;
    }
    while ( v25 < 0x100 );
    a14 = 0;
    if ( a10 != 41 && v52[0] == (D3DXTex *)41 )
    {
      for ( k = 0; k < 0x100; ++k )
      {
        if ( *(_DWORD *)&v50[k] != (k | ((k | ((k | 0xFFFFFF00) << 8)) << 8)) )
          break;
      }
      if ( k == 256 )
      {
        v52[0] = (D3DXTex *)50;
      }
      else
      {
        v59[3] = 255;
        v60[8] = 255;
        v59[0] = 0;
        v59[1] = 85;
        v59[2] = 170;
        v60[1] = 0;
        v60[2] = 36;
        v60[3] = 73;
        v60[4] = 109;
        v60[5] = 146;
        v60[6] = 182;
        v60[7] = 219;
        for ( m = 0; m < 0x100; ++m )
        {
          if ( *(_DWORD *)&v50[m] != (v60[(m >> 5) + 1]
                                    | ((v60[((m >> 2) & 7) + 1] | ((v59[m & 3] | 0xFFFFFF00) << 8)) << 8)) )
            break;
        }
        if ( m == 256 )
          v52[0] = (D3DXTex *)27;
      }
    }
  }
  else
  {
    memset((void *)v50, 0xFFu, sizeof(v50));
  }
  if ( a10 == 0 || a10 == -3 )
  {
    ClosestDeviceFormat = v52[0];
    if ( a14 != 0 )
    {
      FormatInfo = D3DXTex::GetFormatInfo(this: v52[0], a2: a1);
      if ( *((_DWORD *)FormatInfo + 1) <= 2u && *((_DWORD *)FormatInfo + 4) == 0 )
      {
        qmemcpy(v60, FormatInfo, sizeof(v60));
        v60[0] = 0;
        v60[4] = D3DRTYPE_SURFACE;
        ClosestDeviceFormat = (D3DXTex *)D3DXTex::FindClosestDeviceFormat(
                                           this: nullptr,
                                           a2: (unsigned int)a9,
                                           a3: a17,
                                           a4: v60,
                                           a5: v49);
        if ( ClosestDeviceFormat == nullptr )
          ClosestDeviceFormat = v52[0];
      }
    }
    ClosestExternalFormat = (D3DXTex *)D3DXTex::FindClosestExternalFormat(
                                         this: ClosestDeviceFormat,
                                         a2: (enum _D3DFORMAT)v49);
    a10 = (unsigned int)ClosestExternalFormat;
    if ( a11 != 3 && ClosestExternalFormat == (D3DXTex *)20 )
      a10 = 22;
  }
  if ( a16 != nullptr )
  {
    v32 = v53 == 0;
    qmemcpy((void *)a16, v50, 1024);
    if ( !v32 )
      goto LABEL_100;
  }
  if ( !v68 || a10 != 40 && a10 != 41 )
  {
    if ( a10 == 40 )
    {
LABEL_99:
      a10 = 21;
      goto LABEL_100;
    }
    if ( a10 == 41 )
    {
      a10 = 22;
      v33 = 0;
      while ( v50[v33].peFlags == 0xFF )
      {
        if ( (unsigned int)++v33 >= 0x100 )
          goto LABEL_100;
      }
      goto LABEL_99;
    }
LABEL_100:
    if ( a11 != 0 || (v70 = 1, (BYTE1(a9) & 2) != 0) )
      v70 = 0;
    v34 = a5;
    v35 = i;
    v62 = j;
    v64 = a8;
    v66 = (D3DXTex *)a10;
    v20 = sub_45966E(
            a1: a2,
            a2: a5,
            a3: (unsigned int *)&a5,
            a4: &i,
            a5: &j,
            a6: (int *)&a8,
            a7: (unsigned int)a9,
            a8: (D3DXTex **)&a10,
            a9: a11,
            a10: a17);
    if ( v20 < 0 )
      goto LABEL_188;
    if ( v61 && v34 != a5
      || v65 && v35 != i
      || v67 && v62 != j
      || v63 && v64 != a8
      || (v36 = a10, v68) && v66 != (D3DXTex *)a10 )
    {
      v20 = -2005530518;
      goto LABEL_188;
    }
    switch ( a17 )
    {
      case 3u:
        v37 = (*(int (__stdcall **)(D3DXTex *, enum _D3DFORMAT, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, struct IDirect3DSurface9 **, _DWORD))(*(_DWORD *)a2 + 92))(
                a1: a2,
                a2: a5,
                a3: i,
                a4: a8,
                a5: (unsigned int)a9 & 0xFFE07FFF,
                a6: a10,
                a7: a11,
                a8: &v72,
                a9: 0);
        break;
      case 4u:
        v37 = (*(int (__stdcall **)(D3DXTex *, enum _D3DFORMAT, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, struct IDirect3DSurface9 **, _DWORD))(*(_DWORD *)a2 + 96))(
                a1: a2,
                a2: a5,
                a3: i,
                a4: j,
                a5: a8,
                a6: (unsigned int)a9 & 0xFFE07FFF,
                a7: a10,
                a8: a11,
                a9: &v72,
                a10: 0);
        break;
      case 5u:
        v37 = (*(int (__stdcall **)(D3DXTex *, enum _D3DFORMAT, unsigned int, unsigned int, unsigned int, unsigned int, struct IDirect3DSurface9 **, _DWORD))(*(_DWORD *)a2 + 100))(
                a1: a2,
                a2: a5,
                a3: a8,
                a4: (unsigned int)a9 & 0xFFE07FFF,
                a5: a10,
                a6: a11,
                a7: &v72,
                a8: 0);
        break;
      default:
        goto LABEL_122;
    }
    v20 = v37;
LABEL_122:
    if ( v20 < 0 )
      goto LABEL_188;
    if ( v70 == 0 )
    {
      v39 = v72;
      goto LABEL_134;
    }
    switch ( a17 )
    {
      case 3u:
        v38 = (*(int (__stdcall **)(D3DXTex *, enum _D3DFORMAT, unsigned int, unsigned int, _DWORD, unsigned int, int, struct IDirect3DSurface9 **, _DWORD))(*(_DWORD *)a2 + 92))(
                a1: a2,
                a2: a5,
                a3: i,
                a4: a8,
                a5: 0,
                a6: v36,
                a7: 2,
                a8: &v71,
                a9: 0);
        break;
      case 4u:
        v38 = (*(int (__stdcall **)(D3DXTex *, enum _D3DFORMAT, unsigned int, unsigned int, unsigned int, _DWORD, unsigned int, int, struct IDirect3DSurface9 **, _DWORD))(*(_DWORD *)a2 + 96))(
                a1: a2,
                a2: a5,
                a3: i,
                a4: j,
                a5: a8,
                a6: 0,
                a7: v36,
                a8: 2,
                a9: &v71,
                a10: 0);
        break;
      case 5u:
        v38 = (*(int (__stdcall **)(D3DXTex *, enum _D3DFORMAT, unsigned int, _DWORD, unsigned int, int, struct IDirect3DSurface9 **, _DWORD))(*(_DWORD *)a2 + 100))(
                a1: a2,
                a2: a5,
                a3: a8,
                a4: 0,
                a5: v36,
                a6: 2,
                a7: &v71,
                a8: 0);
        break;
      default:
LABEL_131:
        if ( v20 < 0 )
          goto LABEL_188;
        v39 = v71;
LABEL_134:
        a5 = D3DFMT_UNKNOWN;
        v40 = (int *)v52;
        i = (unsigned int)v52;
        while ( 1 )
        {
          a10 = 0;
          if ( v75 != 0 )
          {
            while ( 1 )
            {
              if ( a10 >= a8 )
                goto LABEL_159;
              if ( a17 == 3 )
                break;
              if ( a17 == 4 )
              {
                v42 = &v73;
LABEL_143:
                v41 = ((int (__stdcall *)(struct IDirect3DSurface9 *, unsigned int, void *))v39->__vftable[1].AddRef)(
                        a1: v39,
                        a2: a10,
                        a3: v42);
                goto LABEL_144;
              }
              if ( a17 == 5 )
              {
                v41 = ((int (__stdcall *)(struct IDirect3DSurface9 *, enum _D3DFORMAT, unsigned int, struct IDirect3DSurface9 **))v39->__vftable[1].AddRef)(
                        a1: v39,
                        a2: a5,
                        a3: a10,
                        a4: &a15);
LABEL_144:
                v20 = v41;
              }
              if ( v20 < 0 )
                goto LABEL_188;
              if ( a17 != 3 )
              {
                if ( a17 == 4 )
                {
                  v43 = D3DXLoadVolumeFromMemory(
                          a1: v73,
                          a2: a16,
                          a3: nullptr,
                          a4: v40[1],
                          a5: *v40,
                          a6: v40[12],
                          a7: v40[13],
                          a8: (int)v50,
                          a9: v40 + 6,
                          a10: a12,
                          a11: a14);
                  goto LABEL_150;
                }
                if ( a17 != 5 )
                  goto LABEL_151;
              }
              v43 = D3DXLoadSurfaceFromMemory(
                      a1: a15,
                      a2: a16,
                      a3: nullptr,
                      a4: v40[1],
                      a5: *v40,
                      a6: v40[12],
                      a7: (int)v50,
                      a8: v40 + 6,
                      a9: a12,
                      a10: a14);
LABEL_150:
              v20 = v43;
LABEL_151:
              if ( v20 < 0 )
                goto LABEL_188;
              if ( v73 != nullptr )
              {
                v73->Release(this: v73);
                v73 = nullptr;
              }
              if ( a15 != nullptr )
              {
                a15->Release(this: a15);
                a15 = nullptr;
              }
              if ( ++a10 >= v75 )
                goto LABEL_159;
              v40 = (int *)v40[19];
            }
            v42 = &a15;
            goto LABEL_143;
          }
LABEL_159:
          if ( !v69 && a10 < a8 )
            break;
LABEL_181:
          v40 = *(int **)(i + 80);
          ++a5;
          i = (unsigned int)v40;
          if ( a5 >= (unsigned int)v74 )
          {
            if ( (!v69 || v75 >= a8 || (v20 = D3DXFilterTexture(a1: v39, a2: v50, a3: v75 - 1, a4: a13)) >= 0)
              && (v70 == 0
               || (v20 = (*(int (__stdcall **)(D3DXTex *, struct IDirect3DSurface9 *, struct IDirect3DSurface9 *))(*(_DWORD *)a2 + 124))(
                           a1: a2,
                           a2: v71,
                           a3: v72)) >= 0) )
            {
              v47 = v72;
              v72 = nullptr;
              *a18 = v47;
              v20 = 0;
            }
            goto LABEL_188;
          }
        }
        while ( a17 != 3 )
        {
          if ( a17 == 4 )
          {
            v45 = &v73;
LABEL_167:
            v44 = ((int (__stdcall *)(struct IDirect3DSurface9 *, unsigned int, void *))v39->__vftable[1].AddRef)(
                    a1: v39,
                    a2: a10,
                    a3: v45);
            goto LABEL_168;
          }
          if ( a17 == 5 )
          {
            v44 = ((int (__stdcall *)(struct IDirect3DSurface9 *, enum _D3DFORMAT, unsigned int, struct IDirect3DSurface9 **))v39->__vftable[1].AddRef)(
                    a1: v39,
                    a2: a5,
                    a3: a10,
                    a4: &a15);
LABEL_168:
            v20 = v44;
          }
          if ( v20 < 0 )
            goto LABEL_188;
          switch ( a17 )
          {
            case 3u:
LABEL_173:
              v46 = D3DXLoadSurfaceFromMemory(
                      a1: a15,
                      a2: a16,
                      a3: nullptr,
                      a4: v40[1],
                      a5: *v40,
                      a6: v40[12],
                      a7: (int)v50,
                      a8: v40 + 6,
                      a9: a12,
                      a10: a14);
LABEL_174:
              v20 = v46;
              break;
            case 4u:
              v46 = D3DXLoadVolumeFromMemory(
                      a1: v73,
                      a2: a16,
                      a3: nullptr,
                      a4: v40[1],
                      a5: *v40,
                      a6: v40[12],
                      a7: v40[13],
                      a8: (int)v50,
                      a9: v40 + 6,
                      a10: a12,
                      a11: a14);
              goto LABEL_174;
            case 5u:
              goto LABEL_173;
            default:
              break;
          }
          if ( v20 < 0 )
            goto LABEL_188;
          if ( v73 != nullptr )
          {
            v73->Release(this: v73);
            v73 = nullptr;
          }
          if ( a15 != nullptr )
          {
            a15->Release(this: a15);
            a15 = nullptr;
          }
          if ( ++a10 >= a8 )
            goto LABEL_181;
        }
        v45 = &a15;
        goto LABEL_167;
    }
    v20 = v38;
    goto LABEL_131;
  }
  v20 = -2005530516;
LABEL_188:
  if ( v73 != nullptr )
  {
    v73->Release(this: v73);
    v73 = nullptr;
  }
  if ( a15 != nullptr )
  {
    a15->Release(this: a15);
    a15 = nullptr;
  }
  if ( v72 != nullptr )
  {
    v72->Release(this: v72);
    v72 = nullptr;
  }
  if ( v71 != nullptr )
  {
    v71->Release(this: v71);
    v71 = nullptr;
  }
LABEL_196:
  D3DXTex::CImage::~CImage(this: (D3DXTex::CImage *)v52);
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x0045A8C2
// Name: D3DXCreateTextureFromFileInMemoryEx(x,x,x,x,x,x,x,x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXCreateTextureFromFileInMemoryEx@<eax>(
        enum _D3DFORMAT a1@<ebx>,
        D3DXTex *a2,
        void *a3,
        unsigned int a4,
        enum _D3DFORMAT a5,
        unsigned int a6,
        unsigned int a7,
        struct IDirect3DDevice9 *a8,
        unsigned int a9,
        unsigned int a10,
        unsigned int a11,
        unsigned int a12,
        int a13,
        struct IDirect3DSurface9 *a14,
        const struct tagPALETTEENTRY *a15,
        struct IDirect3DSurface9 **a16)
{
  return sub_45A04D(
           a1,
           a2,
           a3,
           a4,
           a5,
           i: a6,
           j: 1u,
           a8: a7,
           a9: a8,
           a10: a9,
           a11: a10,
           a12: a11,
           a13: a12,
           a14: a13,
           a15: a14,
           a16: a15,
           a17: 3u,
           a18: a16);
}

//------------------------------------------------------------------------------
// Address: 0x0045A901
// Name: sub_45A901
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_45A901(
        void *a1,
        enum _D3DXIMAGE_FILEFORMAT a2,
        int a3,
        const struct tagPALETTEENTRY *a4,
        unsigned int a5)
{
  int v5; // esi
  int v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // ebx
  unsigned int *v13; // eax
  D3DXTex::CLockSurface *v14; // esi
  unsigned int *v15; // eax
  D3DXTex::CLockVolume *v16; // esi
  void *v17; // eax
  unsigned int v18; // ecx
  void *v19; // edi
  void *v20; // eax
  int v21; // edi
  D3DXTex::CImage *v22; // eax
  D3DXTex::CImage *v23; // eax
  int v24; // esi
  D3DXTex::CImage *v25; // eax
  D3DXTex::CImage *v26; // eax
  int v27; // esi
  int v28; // eax
  void *v29; // edx
  int v30; // eax
  unsigned int v31; // esi
  _DWORD *v32; // edi
  unsigned int v33; // esi
  _DWORD *v34; // edi
  _BYTE v36[84]; // [esp+8h] [ebp-11Ch] BYREF
  _BYTE v37[84]; // [esp+5Ch] [ebp-C8h] BYREF
  char v38[12]; // [esp+B0h] [ebp-74h] BYREF
  int v39; // [esp+BCh] [ebp-68h]
  char v40[12]; // [esp+CCh] [ebp-58h] BYREF
  int v41; // [esp+D8h] [ebp-4Ch]
  int v42; // [esp+ECh] [ebp-38h]
  int v43; // [esp+F0h] [ebp-34h]
  int v44; // [esp+F4h] [ebp-30h]
  D3DXTex::CImage *v45; // [esp+F8h] [ebp-2Ch]
  D3DXTex::CImage *v46; // [esp+FCh] [ebp-28h]
  unsigned int v47; // [esp+100h] [ebp-24h]
  D3DXTex::CLockSurface *v48; // [esp+104h] [ebp-20h]
  unsigned int v49; // [esp+108h] [ebp-1Ch]
  int v50; // [esp+10Ch] [ebp-18h]
  D3DXTex::CLockVolume *v51; // [esp+110h] [ebp-14h]
  unsigned int v52; // [esp+114h] [ebp-10h]
  void *v53; // [esp+118h] [ebp-Ch]
  int v54; // [esp+11Ch] [ebp-8h]
  void *pMem; // [esp+120h] [ebp-4h]

  D3DXTex::CImage::CImage(this: (D3DXTex::CImage *)v37);
  if ( a1 == nullptr )
  {
    v5 = -2005530516;
    goto LABEL_80;
  }
  v6 = a3;
  if ( a3 == 0 )
  {
LABEL_4:
    v5 = -2005530516;
    goto LABEL_80;
  }
  v7 = (*(int (__stdcall **)(int))(*(_DWORD *)a3 + 40))(a1: a3);
  v42 = v7;
  if ( v7 == 3 )
    goto LABEL_8;
  if ( v7 != 4 )
  {
    if ( v7 != 5 )
      goto LABEL_4;
LABEL_8:
    v8 = *(_DWORD *)v6;
    v50 = v6;
    (*(void (__stdcall **)(int, _DWORD, char *))(v8 + 68))(a1: v6, a2: 0, a3: v40);
    v9 = v41;
    goto LABEL_9;
  }
  v11 = *(_DWORD *)v6;
  v50 = v6;
  (*(void (__stdcall **)(int, _DWORD, char *))(v11 + 68))(a1: v6, a2: 0, a3: v38);
  v9 = v39;
LABEL_9:
  v44 = v9;
  if ( a2 == D3DXIFF_DDS )
  {
    v47 = v7 != 5 ? 1 : 6;
    v10 = (*(int (__stdcall **)(int))(*(_DWORD *)v6 + 52))(a1: v6);
  }
  else
  {
    v10 = 1;
    v47 = 1;
  }
  v12 = v47 * v10;
  v49 = v10;
  pMem = nullptr;
  v53 = nullptr;
  v48 = nullptr;
  v51 = nullptr;
  if ( v7 != 4 )
  {
    v13 = (unsigned int *)MemAlloc_Alloc(nSize: 20 * v12 + 4);
    if ( v13 != nullptr )
    {
      v14 = (D3DXTex::CLockSurface *)(v13 + 1);
      *v13 = v12;
      `vector constructor iterator'(__t: v13 + 1, __s: 0x14u, __n: v12, __f: D3DXTex::CLockSurface::CLockSurface);
      v48 = v14;
    }
    else
    {
      v48 = nullptr;
    }
    if ( v48 != nullptr )
    {
      v20 = MemAlloc_Alloc(nSize: 4 * v12);
      pMem = v20;
      if ( v20 != nullptr )
      {
        v18 = 4 * v12;
        v19 = v20;
        goto LABEL_26;
      }
    }
LABEL_82:
    a3 = -2147024882;
    goto LABEL_63;
  }
  v15 = (unsigned int *)MemAlloc_Alloc(nSize: 4 * v12 + 4);
  if ( v15 != nullptr )
  {
    v16 = (D3DXTex::CLockVolume *)(v15 + 1);
    *v15 = v12;
    `vector constructor iterator'(__t: v15 + 1, __s: 4u, __n: v12, __f: D3DXTex::CLockVolume::CLockVolume);
    v51 = v16;
  }
  else
  {
    v51 = nullptr;
  }
  if ( v51 == nullptr )
    goto LABEL_82;
  v17 = MemAlloc_Alloc(nSize: 4 * v12);
  v53 = v17;
  if ( v17 == nullptr )
    goto LABEL_82;
  v18 = 4 * v12;
  v19 = v17;
LABEL_26:
  memset(v19, 0, v18);
  v21 = a3;
  v46 = (D3DXTex::CImage *)v37;
  v52 = 0;
  if ( v47 != 0 )
  {
    v43 = 0;
    do
    {
      if ( v52 != 0 )
      {
        v22 = (D3DXTex::CImage *)MemAlloc_Alloc(nSize: 0x54u);
        if ( v22 != nullptr )
          v23 = (D3DXTex::CImage *)D3DXTex::CImage::CImage(this: v22);
        else
          v23 = nullptr;
        if ( v23 == nullptr )
          goto LABEL_82;
        *((_DWORD *)v46 + 20) = v23;
        v46 = v23;
      }
      v54 = 0;
      v45 = v46;
      if ( v49 != 0 )
      {
        while ( 1 )
        {
          v24 = v54;
          if ( v54 != 0 )
          {
            v25 = (D3DXTex::CImage *)MemAlloc_Alloc(nSize: 0x54u);
            if ( v25 != nullptr )
              v26 = (D3DXTex::CImage *)D3DXTex::CImage::CImage(this: v25);
            else
              v26 = nullptr;
            if ( v26 == nullptr )
              goto LABEL_82;
            *((_DWORD *)v45 + 19) = v26;
            v45 = v26;
          }
          v27 = v43 + v24;
          if ( v42 == 3 )
            break;
          if ( v42 == 4 )
          {
            v29 = v53;
LABEL_47:
            v28 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v50 + 72))(a1: v50, a2: v54, a3: (int)v29 + 4 * v27);
            goto LABEL_48;
          }
          if ( v42 == 5 )
          {
            v28 = (*(int (__stdcall **)(int, unsigned int, int, char *))(*(_DWORD *)v50 + 72))(
                    a1: v50,
                    a2: v52,
                    a3: v54,
                    a4: (char *)pMem + 4 * v27);
LABEL_48:
            a3 = v28;
          }
          if ( a3 < 0 )
            goto LABEL_63;
          switch ( v42 )
          {
            case 3:
LABEL_53:
              v30 = D3DXTex::CLockSurface::Lock(
                      this: (D3DXTex::CLockSurface *)((char *)v48 + 20 * v27),
                      a2: (struct D3DX_BLT *)v36,
                      a3: *((struct IDirect3DSurface9 **)pMem + v27),
                      a4,
                      a5: nullptr,
                      a6: 0,
                      a7: 1u);
LABEL_54:
              a3 = v30;
              break;
            case 4:
              v30 = D3DXTex::CLockVolume::Lock(
                      this: (D3DXTex::CLockVolume *)((char *)v51 + 4 * v27),
                      a2: (struct D3DX_BLT *)v36,
                      a3: *((struct IDirect3DVolume9 **)v53 + v27),
                      a4,
                      a5: nullptr,
                      a6: 0,
                      a7: 1u);
              goto LABEL_54;
            case 5:
              goto LABEL_53;
            default:
              break;
          }
          if ( a3 < 0 )
            goto LABEL_63;
          a3 = D3DXTex::CImage::Initialize(this: v45, a2: (struct D3DX_BLT *)v36);
          if ( a3 < 0 )
            goto LABEL_63;
          if ( ++v54 >= v49 )
            goto LABEL_58;
        }
        v29 = pMem;
        goto LABEL_47;
      }
LABEL_58:
      ++v52;
      v43 += v49;
    }
    while ( v52 < v47 );
  }
  a3 = D3DXTex::CImage::Save(this: (D3DXTex::CImage *)v37, a2: a1, a3: a2, a4: a5);
  if ( a3 >= 0 )
  {
    if ( v44 == 0 )
    {
      (*(void (__stdcall **)(int, int *))(*(_DWORD *)v21 + 12))(a1: v21, a2: &a3);
      (*(void (__stdcall **)(int))(*(_DWORD *)a3 + 12))(a1: a3);
      (*(void (__stdcall **)(int))(*(_DWORD *)a3 + 8))(a1: a3);
    }
    a3 = 0;
  }
LABEL_63:
  v31 = 0;
  if ( v48 != nullptr )
    D3DXTex::CLockSurface::`vector deleting destructor'(this: v48, a2: 3);
  if ( v51 != nullptr )
    D3DXTex::CLockVolume::`vector deleting destructor'(this: v51, a2: 3);
  if ( pMem != nullptr )
  {
    if ( v12 != 0 )
    {
      do
      {
        v32 = (char *)pMem + 4 * v31;
        if ( *v32 != 0 )
        {
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v32 + 8))(a1: *v32);
          *v32 = 0;
        }
        ++v31;
      }
      while ( v31 < v12 );
    }
    free(pMem);
  }
  v33 = 0;
  if ( v53 != nullptr )
  {
    if ( v12 != 0 )
    {
      do
      {
        v34 = (char *)v53 + 4 * v33;
        if ( *v34 != 0 )
        {
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v34 + 8))(a1: *v34);
          *v34 = 0;
        }
        ++v33;
      }
      while ( v33 < v12 );
    }
    free(pMem: v53);
  }
  v5 = a3;
LABEL_80:
  D3DXTex::CImage::~CImage(this: (D3DXTex::CImage *)v37);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0045ACD4
// Name: D3DXSaveTextureToFileInMemory(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXSaveTextureToFileInMemory(
        void *a1,
        enum _D3DXIMAGE_FILEFORMAT a2,
        int a3,
        const struct tagPALETTEENTRY *a4)
{
  return sub_45A901(a1, a2, a3, a4, a5: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x0045ACF0
// Name: D3DXCreateTextureFromFileExA(x,x,x,x,x,x,x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXCreateTextureFromFileExA@<eax>(
        enum _D3DFORMAT a1@<ebx>,
        D3DXTex *a2,
        LPCWCH lpWideCharStr,
        enum _D3DFORMAT a4,
        unsigned int a5,
        unsigned int a6,
        struct IDirect3DDevice9 *a7,
        unsigned int a8,
        unsigned int a9,
        unsigned int a10,
        unsigned int a11,
        int a12,
        struct IDirect3DSurface9 *a13,
        const struct tagPALETTEENTRY *a14,
        struct IDirect3DSurface9 **a15)
{
  int v15; // eax
  int v16; // esi
  _BYTE v18[8]; // [esp+4h] [ebp-10h] BYREF
  void *v19; // [esp+Ch] [ebp-8h]
  unsigned int v20; // [esp+10h] [ebp-4h]

  D3DXCore::CFile::CFile(this: (D3DXCore::CFile *)v18);
  v15 = D3DXCore::CFile::Open(this: (D3DXCore::CFile *)v18, lpWideCharStr, a3: 0);
  if ( v15 >= 0 )
    v15 = D3DXCreateTextureFromFileInMemoryEx(
            a1,
            a2,
            a3: v19,
            a4: v20,
            a5: a4,
            a6: a5,
            a7: a6,
            a8: a7,
            a9: a8,
            a10: a9,
            a11: a10,
            a12: a11,
            a13: a12,
            a14: a13,
            a15: a14,
            a16: a15);
  v16 = v15;
  D3DXCore::CFile::~CFile(this: (D3DXCore::CFile *)v18);
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x0045AD55
// Name: D3DXCreateTextureFromFileInMemory(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXCreateTextureFromFileInMemory@<eax>(
        enum _D3DFORMAT a1@<ebx>,
        D3DXTex *a2,
        void *a3,
        unsigned int a4,
        struct IDirect3DSurface9 **a5)
{
  return sub_45A04D(
           a1,
           a2,
           a3,
           a4,
           a5: D3DFMT_FORCE_DWORD|0x80000000,
           i: 0xFFFFFFFF,
           j: 1u,
           a8: 0xFFFFFFFF,
           a9: nullptr,
           a10: 0,
           a11: 1u,
           a12: 0xFFFFFFFF,
           a13: 0xFFFFFFFF,
           a14: 0,
           a15: nullptr,
           a16: nullptr,
           a17: 3u,
           a18: a5);
}

//------------------------------------------------------------------------------
// Address: 0x0045AD84
// Name: D3DXCreateTextureFromFileA(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXCreateTextureFromFileA@<eax>(
        enum _D3DFORMAT a1@<ebx>,
        D3DXTex *a2,
        LPCWCH lpWideCharStr,
        struct IDirect3DSurface9 **a4)
{
  return D3DXCreateTextureFromFileExA(
           a1,
           a2,
           lpWideCharStr,
           a4: D3DFMT_FORCE_DWORD|0x80000000,
           a5: 0xFFFFFFFF,
           a6: 0xFFFFFFFF,
           a7: nullptr,
           a8: 0,
           a9: 1u,
           a10: 0xFFFFFFFF,
           a11: 0xFFFFFFFF,
           a12: 0,
           a13: nullptr,
           a14: nullptr,
           a15: a4);
}

//------------------------------------------------------------------------------
// Address: 0x0045ADAC
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
// Address: 0x0045AEDE
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
// Address: 0x0045AFE6
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
    v7 = strcmp((&off_6C8E78)[3 * v6], a1);
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
  if ( (a2 & dword_6C8E80[v8]) != a2 )
    return -2147467259;
  if ( a3 != nullptr )
  {
    *a3 = (&off_6C8E78)[v8];
    a3[1] = (&off_6C8E78)[v8 + 1];
    a3[2] = (&off_6C8E78)[v8 + 2];
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045B084
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
  v4 = "vs_2_x";
  while ( 1 )
  {
    v5 = *((_DWORD *)v4 - 4);
    v4 -= 12;
    --v3;
    if ( v5 == a1 && (a2 & *(_DWORD *)v4) == a2 )
      break;
    if ( v4 <= (const char *)dword_6C8E80 )
      return -2147467259;
  }
  if ( a3 != nullptr )
  {
    v7 = &(&off_6C8E78)[3 * v3];
    *a3 = *v7++;
    a3[1] = *v7;
    a3[2] = v7[1];
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045B0D3
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
    v2 = (D3DXShader::CConstantTable *)D3DXShader::CConstantTable::CConstantTable(this: v5);
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
// Address: 0x0045B154
// Name: sub_45B154
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall sub_45B154(unsigned __int8 *a1, LPCSTR lpValueName, unsigned __int8 *Type, unsigned int cbData)
{
  LSTATUS v4; // esi
  BOOL result; // eax
  HKEY__ *phkResult; // [esp+0h] [ebp-4h] BYREF

  phkResult = nullptr;
  result = false;
  if ( RegOpenKeyA(hKey: HKEY_LOCAL_MACHINE, lpSubKey: "Software\\Microsoft\\Direct3D", &phkResult) == 0 )
  {
    v4 = RegQueryValueExA(
           hKey: phkResult,
           lpValueName,
           lpReserved: nullptr,
           lpType: (LPDWORD)&Type,
           lpData: Type,
           lpcbData: &cbData);
    RegCloseKey(hKey: phkResult);
    if ( v4 == 0 && Type == a1 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045B1B3
// Name: int D3DXDebugMuteInt(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXDebugMuteInt(int a1)
{
  HMODULE LibraryA; // eax
  HMODULE v2; // eax
  int v4; // [esp+0h] [ebp-4h]

  v4 = dword_742B0A8;
  dword_742B0A8 = a1;
  if ( DebugSetMute == nullptr && DebugSetMute_0 == nullptr )
  {
    if ( GetModuleHandleA(lpModuleName: "d3d9.dll") != nullptr )
    {
      LibraryA = LoadLibraryA(lpLibFileName: "d3d9.dll");
      if ( LibraryA != nullptr )
        DebugSetMute = (int (__cdecl *)(_DWORD))GetProcAddress(hModule: LibraryA, lpProcName: "DebugSetMute");
    }
    if ( GetModuleHandleA(lpModuleName: "d3d9d.dll") != nullptr )
    {
      v2 = LoadLibraryA(lpLibFileName: "d3d9d.dll");
      if ( v2 != nullptr )
        DebugSetMute_0 = (int (__cdecl *)(_DWORD))GetProcAddress(hModule: v2, lpProcName: "DebugSetMute");
    }
  }
  if ( dword_769294 != -1 )
  {
LABEL_14:
    if ( dword_769294 != 0 )
      return v4;
    goto LABEL_15;
  }
  if ( !sub_45B154(
          a1: (unsigned __int8 *)4,
          lpValueName: "D3DXDoNotMute",
          Type: (unsigned __int8 *)&dword_769294,
          cbData: 4u) )
    dword_769294 = 0;
  if ( dword_769294 != 0 )
  {
    dword_769294 = 1;
    goto LABEL_14;
  }
LABEL_15:
  if ( DebugSetMute != nullptr )
    DebugSetMute(a1);
  if ( DebugSetMute_0 != nullptr )
    DebugSetMute_0(a1);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0045B29C
// Name: void D3DXCheckNewDelete(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall D3DXCheckNewDelete()
{
  void *v0; // edi
  void *v1; // eax
  void *v2; // ebx
  int v3; // [esp+4h] [ebp-4h]

  if ( dword_742B0B4 == 0 )
  {
    dword_742B0B4 = 1;
    v3 = 0;
    v0 = MemAlloc_Alloc(nSize: 0);
    v1 = MemAlloc_Alloc(nSize: 0);
    v2 = v1;
    if ( v0 == nullptr || v1 == nullptr || v0 == v1 )
      v3 = 1;
    if ( v0 != nullptr )
      free(pMem: v0);
    if ( v2 != nullptr && v2 != v0 )
      free(pMem: v2);
    free(pMem: nullptr);
    if ( v3 != 0 )
    {
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) Overloaded ::new and ::delete operators do not conform to C++ standards:\r\n");
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) An allocation of zero bytes should return a unique non-null pointer to at\r\n");
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) least zero bytes. Deletion of a null pointer should quietly do nothing.\r\n");
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) D3DX relies upon this behavior.\r\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B32B
// Name: public: D3DXTex::CDataCollector::CDataCollector(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXTex::CDataCollector *__thiscall D3DXTex::CDataCollector::CDataCollector(D3DXTex::CDataCollector *this)
{
  D3DXCore::CFile::CFile(this);
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045B34A
// Name: public: long D3DXTex::CDataCollector::Setup(void const __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CDataCollector::Setup(
        D3DXTex::CDataCollector *this,
        struct D3DXCore::CBuffer **lpWideCharStr,
        unsigned int a3)
{
  int v3; // ebx
  int result; // eax
  void *v6; // eax

  v3 = 1;
  if ( a3 >= 2 )
  {
    v3 = 2;
    if ( a3 != 2 )
      return -2147467259;
    result = D3DXCore::CBuffer::Create(a1: 0x400u, a2: lpWideCharStr);
    if ( result < 0 )
      return result;
    *((_DWORD *)this + 5) = *lpWideCharStr;
LABEL_9:
    *((_DWORD *)this + 4) = v3;
    return 0;
  }
  v6 = MemAlloc_Alloc(nSize: 0x10000u);
  *((_DWORD *)this + 6) = v6;
  if ( v6 == nullptr )
    return -2147024882;
  result = D3DXCore::CFile::Create(this, (LPCWCH)lpWideCharStr, a3: a3 == 1);
  if ( result >= 0 )
    goto LABEL_9;
  return result;
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10054760
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10054780
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x100547B0
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10054820
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10054990
// Name: unsigned long GetProcessorCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl GetProcessorCount()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  return SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x10054DB0
// Name: public: CATICompressThreadData::CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::CATICompressThreadData(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10054DC0
// Name: public: CATICompressThreadData::~CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::~CATICompressThreadData(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*this;
  if ( v2 != nullptr )
  {
    (**v2)(a1: v2, a2: 1);
    *this = 0;
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*(this + 1);
  if ( v3 != nullptr )
  {
    (**v3)(a1: v3, a2: 1);
    *(this + 1) = 0;
  }
  v4 = (void (__thiscall ***)(_DWORD, int))*(this + 2);
  if ( v4 != nullptr )
  {
    (**v4)(a1: v4, a2: 1);
    *(this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054E10
// Name: unsigned long ThreadedCompressProc(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall ThreadedCompressProc(_DWORD *a1)
{
  unsigned int v1; // esi
  int v2; // edi

  v1 = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0x8001Fu, mask: 0x8001Fu);
  v2 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*a1 + 32))(
         a1: *a1,
         a2: a1[1],
         a3: a1[2],
         a4: a1[3],
         a5: a1[4],
         a6: a1[5]);
  _controlfp(newctrl: v1, mask: 0x8001Fu);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10055900
// Name: void S3TCencode(struct _DDSURFACEDESC __near *,struct tagPALETTEENTRY __near *,struct _DDSURFACEDESC __near *,void __near *,unsigned int,float __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl S3TCencode(
        struct _DDSURFACEDESC *a1,
        struct tagPALETTEENTRY *a2,
        struct _DDSURFACEDESC *a3,
        void *a4,
        unsigned int a5,
        float *a6)
{
  unsigned int v6; // ebx
  struct _DDSURFACEDESC *v7; // esi
  int v8; // ecx
  unsigned int v9; // eax
  int i; // edx
  unsigned int dwRGBAlphaBitMask; // edx
  int v12; // ecx
  unsigned int j; // eax
  signed int dwHeight; // eax
  signed int dwWidth; // edx
  int k; // eax
  int v17; // ebx
  _DWORD *v18; // edi
  int v19; // esi
  int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // edx
  double v23; // st7
  int v24; // esi
  int v25; // edi
  int v26; // eax
  _BYTE *v27; // edi
  int jj; // eax
  unsigned int v29; // edi
  _DWORD *v30; // esi
  int v31; // edx
  int v32; // eax
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // ecx
  _DWORD *v38; // esi
  char v39; // di
  int v40; // ecx
  int v41; // eax
  int v42; // eax
  unsigned int v43; // eax
  __int64 v44; // rax
  int v45; // ecx
  int v46; // edi
  unsigned __int8 *v47; // esi
  int v48; // eax
  struct tagPALETTEENTRY *v49; // eax
  unsigned int v50; // ecx
  double *v51; // ecx
  bool v52; // cc
  int v53; // edi
  int v54; // eax
  int nn; // edx
  int v56; // eax
  struct tagPALETTEENTRY *v57; // ecx
  double *v58; // eax
  int v59; // edi
  int v60; // ecx
  unsigned int *v61; // edx
  int v62; // eax
  unsigned int v63; // esi
  double *v64; // edx
  int v65; // eax
  double v66; // st7
  unsigned int v67; // ebx
  unsigned int v68; // eax
  double *v69; // esi
  int v70; // ebx
  int i1; // edx
  int v72; // ecx
  unsigned int v73; // edi
  char *v74; // esi
  int v75; // eax
  int v76; // edx
  int v77; // ecx
  unsigned int v78; // edi
  double *v79; // esi
  int i2; // edx
  unsigned int v81; // eax
  int v82; // ecx
  _DWORD *v83; // eax
  int i3; // ecx
  int v85; // ecx
  char *v86; // eax
  __int16 v87; // dx
  unsigned __int16 v88; // dx
  unsigned __int16 v89; // cx
  bool v90; // cf
  int v91; // eax
  __int16 v92; // ax
  int v93; // ebx
  _DWORD *v94; // esi
  int *v95; // edx
  int v96; // eax
  int i4; // edi
  int lPitch; // edx
  int v99; // [esp+18h] [ebp-888h]
  int v100; // [esp+18h] [ebp-888h]
  int m; // [esp+18h] [ebp-888h]
  int v102; // [esp+18h] [ebp-888h]
  int v103; // [esp+18h] [ebp-888h]
  int v104; // [esp+18h] [ebp-888h]
  int v105; // [esp+18h] [ebp-888h]
  int v106; // [esp+18h] [ebp-888h]
  int v107; // [esp+1Ch] [ebp-884h]
  int kk; // [esp+1Ch] [ebp-884h]
  int n; // [esp+1Ch] [ebp-884h]
  int mm; // [esp+1Ch] [ebp-884h]
  int v111; // [esp+1Ch] [ebp-884h]
  int v112; // [esp+1Ch] [ebp-884h]
  int v113; // [esp+1Ch] [ebp-884h]
  int *v114; // [esp+1Ch] [ebp-884h]
  int ii; // [esp+20h] [ebp-880h]
  int v116; // [esp+20h] [ebp-880h]
  int v117; // [esp+20h] [ebp-880h]
  int v118; // [esp+20h] [ebp-880h]
  int v119; // [esp+20h] [ebp-880h]
  int v120; // [esp+20h] [ebp-880h]
  int v121; // [esp+20h] [ebp-880h]
  int v122; // [esp+20h] [ebp-880h]
  int v123; // [esp+24h] [ebp-87Ch]
  int v124; // [esp+24h] [ebp-87Ch]
  int v125; // [esp+24h] [ebp-87Ch]
  int v126; // [esp+28h] [ebp-878h]
  unsigned int *v127; // [esp+28h] [ebp-878h]
  unsigned int v128; // [esp+2Ch] [ebp-874h]
  _WORD *v129; // [esp+30h] [ebp-870h]
  int v130; // [esp+34h] [ebp-86Ch]
  int v131; // [esp+38h] [ebp-868h]
  int v132; // [esp+3Ch] [ebp-864h]
  _DWORD *v133; // [esp+40h] [ebp-860h]
  int v134; // [esp+44h] [ebp-85Ch]
  int v135; // [esp+48h] [ebp-858h]
  int v136; // [esp+4Ch] [ebp-854h]
  int v137; // [esp+50h] [ebp-850h]
  char *lpSurface; // [esp+54h] [ebp-84Ch]
  signed int v139; // [esp+58h] [ebp-848h]
  _DWORD v140[3]; // [esp+5Ch] [ebp-844h] BYREF
  int v141; // [esp+68h] [ebp-838h]
  unsigned int v142; // [esp+6Ch] [ebp-834h]
  unsigned int v143; // [esp+70h] [ebp-830h]
  unsigned int v144; // [esp+74h] [ebp-82Ch]
  __int64 v145; // [esp+78h] [ebp-828h]
  __int64 v146; // [esp+80h] [ebp-820h]
  __int64 v147; // [esp+88h] [ebp-818h]
  __int64 v148; // [esp+90h] [ebp-810h]
  __int64 v149; // [esp+98h] [ebp-808h]
  __int64 v150; // [esp+A0h] [ebp-800h]
  __int64 v151; // [esp+A8h] [ebp-7F8h]
  __int64 v152; // [esp+B0h] [ebp-7F0h]
  __int64 v153; // [esp+B8h] [ebp-7E8h]
  __int64 v154; // [esp+C0h] [ebp-7E0h]
  _DWORD v155[48]; // [esp+C8h] [ebp-7D8h] BYREF
  float v156[51]; // [esp+188h] [ebp-718h] BYREF
  int v157; // [esp+254h] [ebp-64Ch]
  int v158; // [esp+258h] [ebp-648h]
  int v159; // [esp+25Ch] [ebp-644h]
  _DWORD v160[48]; // [esp+260h] [ebp-640h]
  double v161[176]; // [esp+320h] [ebp-580h] BYREF

  v6 = a5 & 0xFF00;
  v143 = v6;
  if ( (a5 & 0xFF00) != 0 )
  {
    if ( v6 == 256 || v6 == 512 )
      bS3TCForce4 = true;
  }
  else
  {
    bS3TCForce4 = false;
  }
  v7 = a1;
  a3->dwFlags = 6150;
  a3->dwWidth = a1->dwWidth;
  a3->dwHeight = a1->dwHeight;
  a3->lpSurface = a4;
  a3->ddpfPixelFormat.dwSize = 32;
  a3->ddpfPixelFormat.dwFlags = 4;
  a3->ddpfPixelFormat.dwRGBBitCount = a5;
  a3->ddpfPixelFormat.dwFourCC = 305419896;
  v128 = (a1->ddpfPixelFormat.dwRGBBitCount + 7) >> 3;
  v8 = 0;
  v135 = (char *)&a1->ddpfPixelFormat.___u4 - (char *)v140;
  do
  {
    v9 = *(_DWORD *)((char *)&v140[v8] + (char *)&a1->ddpfPixelFormat.___u4 - (char *)v140);
    for ( i = 0; (v9 & 1) == 0; ++i )
      v9 >>= 1;
    v140[v8++] = i;
  }
  while ( v8 < 3 );
  if ( (a5 & 0xFF00) != 0 )
  {
    dwRGBAlphaBitMask = a1->ddpfPixelFormat.dwRGBAlphaBitMask;
    v12 = 0;
    for ( j = dwRGBAlphaBitMask; (j & 1) == 0; ++v12 )
      j >>= 1;
    v137 = v12;
    v144 = (dword_1525EBAC * (dwRGBAlphaBitMask >> v12) / 0xFF) << v12;
  }
  lpSurface = (char *)a1->lpSurface;
  dwHeight = a1->dwHeight;
  v129 = a4;
  v136 = 0;
  if ( dwHeight > 0 )
  {
    while ( 1 )
    {
      v131 = dwHeight - v136;
      if ( (unsigned int)(dwHeight - v136) >= 4 )
        v131 = 4;
      v139 = 0;
      v133 = lpSurface;
      dwWidth = v7->dwWidth;
      if ( dwWidth > 0 )
        break;
LABEL_171:
      lPitch = a1->lPitch;
      dwHeight = a1->dwHeight;
      v52 = v136 + 4 < dwHeight;
      v136 += 4;
      lpSurface += 4 * lPitch;
      if ( !v52 )
        return;
      v7 = a1;
    }
    v141 = (unsigned __int8)a5;
    while ( 1 )
    {
      memset(v161, 0, sizeof(v161));
      memset(v155, 0xFFu, sizeof(v155));
      for ( k = 0; k < 3; v161[k + 144] = a6[k - 1] )
        ++k;
      v130 = dwWidth - v139;
      if ( dwWidth - v139 >= (unsigned int)S3TC_BLOCK_WIDTH )
        v130 = S3TC_BLOCK_WIDTH;
      v17 = 0;
      LODWORD(v161[0]) = 0;
      if ( v143 == 256 )
      {
        v38 = v133;
        v39 = v137;
        v40 = S3TC_BLOCK_WIDTH;
        v41 = 0;
        for ( m = 0; m < 4; v41 = m )
        {
          if ( v41 >= v131 )
          {
            *v129 = 0;
          }
          else
          {
            v42 = 0;
            for ( n = 0; v42 < v40; n = v42 )
            {
              if ( v42 >= v130 )
              {
                LOWORD(v134) = (unsigned __int16)v134 >> 4;
              }
              else
              {
                v43 = a1->ddpfPixelFormat.dwRGBAlphaBitMask >> v39;
                v152 = (*v38 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) >> v39;
                v148 = v43;
                v44 = (__int64)floor(X: (double)v152 / (double)v43 * 15.0 + 0.5);
                v17 = LODWORD(v161[0]);
                LOWORD(v45) = (unsigned __int16)v134 >> 4;
                LODWORD(v44) = v45 | ((_DWORD)v44 << 12);
                v40 = S3TC_BLOCK_WIDTH;
                v134 = v44;
                v42 = n;
              }
              ++v42;
              v38 = (_DWORD *)((char *)v38 + v128);
            }
            *v129 = v134;
          }
          ++v129;
          v40 = S3TC_BLOCK_WIDTH;
          ++m;
          v38 = (_DWORD *)((char *)v38 + a1->lPitch - v128 * S3TC_BLOCK_WIDTH);
        }
        goto LABEL_82;
      }
      if ( v143 != 512 )
        goto LABEL_82;
      v18 = v133;
      v19 = 0;
      v20 = a1->lPitch - v128 * S3TC_BLOCK_WIDTH;
      v156[0] = 0.0;
      v99 = 0;
      v107 = v20;
      do
      {
        for ( ii = 0; ii < S3TC_BLOCK_WIDTH; ++ii )
        {
          if ( ii >= v130 || v99 >= v131 )
          {
            v155[v19++] = -1;
          }
          else
          {
            v21 = (*v18 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) >> v137;
            v22 = a1->ddpfPixelFormat.dwRGBAlphaBitMask >> v137;
            v155[v19++] = LODWORD(v156[0]);
            if ( v21 == v22 )
            {
              v23 = 1.0;
            }
            else
            {
              v150 = v21;
              v151 = v22;
              v23 = (double)v21 / (double)v22;
            }
            v156[++LODWORD(v156[0])] = v23;
          }
          v18 = (_DWORD *)((char *)v18 + v128);
        }
        v18 = (_DWORD *)((char *)v18 + v107);
        ++v99;
      }
      while ( v99 < 4 );
      v24 = 0;
      v156[49] = 0.0;
      v156[50] = 0.0;
      if ( LODWORD(v156[0]) != 0 )
      {
        CodeAlphaBlock(a1: v156);
        v24 = v158;
        v25 = v159;
        v17 = LODWORD(v161[0]);
        if ( v158 != v159 )
          goto LABEL_45;
      }
      else
      {
        v25 = 0;
        v158 = 0;
      }
      ++v25;
      v26 = 0;
      v159 = v25;
      if ( SLODWORD(v156[0]) > 0 )
      {
        do
          v160[v26++] = 0;
        while ( v26 < SLODWORD(v156[0]) );
        v24 = v158;
        v25 = v159;
      }
      v157 = 6;
LABEL_45:
      if ( v24 > v25 == (v157 == 6) )
      {
        v158 = v25;
        v159 = v24;
        v116 = 1;
      }
      else
      {
        v116 = 0;
      }
      v27 = v129;
      for ( jj = 0; jj < 2; ++jj )
        *v27++ = *((_BYTE *)&v158 + 4 * jj);
      v129 = v27;
      v123 = 0;
      v126 = 0;
      memset(v27, 0, 6 * (S3TC_BLOCK_WIDTH / 4));
      v29 = 0;
      if ( S3TC_BLOCK_WIDTH / 4 > 0 )
      {
        v30 = v129;
        while ( 1 )
        {
          v31 = v123;
          v100 = 0;
          do
          {
            for ( kk = 4; kk != 0; --kk )
            {
              v32 = v155[v31];
              v29 >>= 3;
              if ( v32 < 0 )
                goto LABEL_66;
              v33 = v160[v32];
              if ( v116 != 0 )
              {
                if ( v157 == 8 )
                {
                  if ( v33 > 1 )
                  {
                    v34 = 9 - v33;
LABEL_64:
                    v33 = v34;
                    goto LABEL_65;
                  }
                }
                else
                {
                  if ( v157 != 6 || v33 > 5 )
                    goto LABEL_65;
                  if ( v33 > 1 )
                  {
                    v34 = 7 - v33;
                    goto LABEL_64;
                  }
                }
                v34 = v33 == 0;
                goto LABEL_64;
              }
LABEL_65:
              v29 |= v33 << 21;
LABEL_66:
              ++v31;
            }
            v35 = v100;
            if ( (v100 & 1) != 0 )
            {
              v36 = *v30;
              v30 = (_DWORD *)((char *)v30 + 3);
              v37 = v29 | v36;
              v29 = 0;
              *(_DWORD *)((char *)v30 - 3) = v37;
            }
            ++v100;
          }
          while ( v35 + 1 < 4 );
          v123 = v31;
          if ( ++v126 >= S3TC_BLOCK_WIDTH / 4 )
          {
            v129 = v30;
            break;
          }
        }
      }
LABEL_82:
      v46 = 0;
      if ( a2 != nullptr )
      {
        v47 = (unsigned __int8 *)v133;
        if ( v141 != 0 )
        {
          if ( v141 == 1 )
          {
            v102 = 0;
            v117 = a1->lPitch;
            do
            {
              v48 = 0;
              for ( mm = 0; mm < 4; ++mm )
              {
                if ( v48 >= v130
                  || v102 >= v131
                  || (v49 = &a2[*v47], (v50 = *(_DWORD *)v49 & 0xFFFFFF) >= a1->ddckCKSrcBlt.dwColorSpaceLowValue)
                  && v50 <= a1->ddckCKSrcBlt.dwColorSpaceHighValue )
                {
                  v155[v46++] = -1;
                }
                else
                {
                  v155[v46++] = v17;
                  LODWORD(v161[0]) = v17 + 1;
                  v51 = &v161[3 * v17 + 2];
                  *(v51 - 1) = (double)v49->peRed * 0.00392156862745098;
                  *v51 = (double)v49->peGreen * 0.00392156862745098;
                  v51[1] = (double)v49->peBlue * 0.00392156862745098;
                  v17 = LODWORD(v161[0]);
                }
                v48 = mm + 1;
                ++v47;
              }
              v52 = ++v102 < 4;
              v47 = &v47[v117 - 4];
            }
            while ( v52 );
          }
        }
        else
        {
          v53 = 0;
          v54 = 0;
          v103 = 0;
          v118 = a1->lPitch;
          do
          {
            for ( nn = 0; nn < 4; ++nn )
            {
              if ( nn >= v130 || v54 >= v131 )
              {
                v155[v53++] = -1;
              }
              else
              {
                v56 = *v47;
                v155[v53++] = v17;
                v57 = &a2[v56];
                LODWORD(v161[0]) = v17 + 1;
                v58 = &v161[3 * v17 + 2];
                *(v58 - 1) = (double)v57->peRed * 0.00392156862745098;
                *v58 = (double)v57->peGreen * 0.00392156862745098;
                v58[1] = (double)v57->peBlue * 0.00392156862745098;
                v17 = LODWORD(v161[0]);
                v54 = v103;
              }
              ++v47;
            }
            v103 = ++v54;
            v47 = &v47[v118 - 4];
          }
          while ( v54 < 4 );
        }
      }
      else
      {
        v127 = v133;
        if ( v141 != 0 )
        {
          if ( v141 == 1 )
          {
            v124 = 0;
            v105 = 0;
            v112 = a1->lPitch - 4 * v128;
            do
            {
              v120 = 0;
              do
              {
                if ( v120 >= v130
                  || v105 >= v131
                  || (v68 = *v127, v142 = v68, v68 >= a1->ddckCKSrcBlt.dwColorSpaceLowValue)
                  && v68 <= a1->ddckCKSrcBlt.dwColorSpaceHighValue )
                {
                  v155[v124++] = -1;
                }
                else
                {
                  v155[v124] = v17;
                  v69 = &v161[3 * v17 + 1];
                  LODWORD(v161[0]) = v17 + 1;
                  v70 = v135;
                  ++v124;
                  for ( i1 = 0; i1 < 3; ++i1 )
                  {
                    v72 = v140[i1];
                    ++v69;
                    v73 = (v142 & *(_DWORD *)((char *)&v140[i1] + v70)) >> v72;
                    v146 = (unsigned int)(*(_DWORD *)((char *)&v140[i1] + v70) >> v72);
                    v153 = v73;
                    *(v69 - 1) = (double)v73 / (double)v146;
                  }
                  v17 = LODWORD(v161[0]);
                }
                v74 = (char *)v127 + v128;
                v52 = ++v120 < 4;
                v127 = (unsigned int *)((char *)v127 + v128);
              }
              while ( v52 );
              v52 = ++v105 < 4;
              v127 = (unsigned int *)&v74[v112];
            }
            while ( v52 );
          }
          else if ( v141 == 2 )
          {
            v59 = 0;
            v60 = 0;
            v104 = 0;
            v111 = a1->lPitch - 4 * v128;
            do
            {
              v61 = v127;
              v62 = 0;
              v119 = 0;
              do
              {
                if ( v62 >= v130 || v60 >= v131 || (v63 = *v61, (*v61 & a1->ddpfPixelFormat.dwRGBAlphaBitMask) <= v144) )
                {
                  v155[v59++] = -1;
                }
                else
                {
                  v155[v59++] = v17;
                  LODWORD(v161[0]) = v17 + 1;
                  v64 = &v161[3 * v17 + 1];
                  v65 = 0;
                  v154 = *(&a1->ddpfPixelFormat.dwRBitMask + v59) >> v140[v59];
                  v66 = (double)v154;
                  do
                  {
                    ++v64;
                    v67 = (v63 & *(_DWORD *)((char *)&v140[v65] + v135)) >> v140[v65];
                    ++v65;
                    v145 = v67;
                    *(v64 - 1) = (double)v67 / v66;
                  }
                  while ( v65 < 3 );
                  v17 = LODWORD(v161[0]);
                  v62 = v119;
                  v60 = v104;
                }
                ++v62;
                v61 = (unsigned int *)((char *)v127 + v128);
                v119 = v62;
                v127 = (unsigned int *)((char *)v127 + v128);
              }
              while ( v62 < 4 );
              v104 = ++v60;
              v127 = (unsigned int *)((char *)v61 + v111);
            }
            while ( v60 < 4 );
          }
        }
        else
        {
          v75 = 0;
          v76 = a1->lPitch - v128 * S3TC_BLOCK_WIDTH;
          v106 = 0;
          v113 = v76;
          do
          {
            v77 = 0;
            v121 = 0;
            if ( S3TC_BLOCK_WIDTH > 0 )
            {
              do
              {
                if ( v77 >= v130 || v46 >= v131 )
                {
                  v155[v75++] = -1;
                }
                else
                {
                  v155[v75] = v17;
                  v78 = *v127;
                  v79 = &v161[3 * v17 + 1];
                  v125 = v75 + 1;
                  LODWORD(v161[0]) = v17 + 1;
                  for ( i2 = 0; i2 < 3; ++i2 )
                  {
                    ++v79;
                    v81 = *(_DWORD *)((char *)&v140[i2] + v135);
                    v82 = v140[i2];
                    v147 = (v81 & v78) >> v82;
                    v149 = v81 >> v82;
                    *(v79 - 1) = (double)v147 / (double)v149;
                  }
                  v17 = LODWORD(v161[0]);
                  v75 = v125;
                  v77 = v121;
                  v46 = v106;
                }
                ++v77;
                v127 = (unsigned int *)((char *)v127 + v128);
                v121 = v77;
              }
              while ( v77 < S3TC_BLOCK_WIDTH );
              v76 = v113;
            }
            v106 = ++v46;
            v127 = (unsigned int *)((char *)v127 + v76);
          }
          while ( v46 < 4 );
        }
      }
      LODWORD(v161[148]) = (v17 >= v131 * v130) + 3;
      if ( v17 != 0 )
      {
        CodeRGBBlock(a1: v161);
      }
      else
      {
        v83 = (_DWORD *)&v161[149] + 1;
        for ( i3 = 2; i3 != 0; --i3 )
        {
          v83[1] = 0;
          *v83 = 0;
          *(v83 - 1) = 0;
          v83 += 3;
        }
      }
      v85 = 0;
      v86 = (char *)&v161[149] + 4;
      do
      {
        v87 = *((_WORD *)v86 - 2);
        v86 += 12;
        *((_WORD *)&v131 + ++v85 + 1) = *((_WORD *)v86 - 4) | (32 * (*((_WORD *)v86 - 6) | (v87 << 6)));
      }
      while ( v85 < 2 );
      v89 = HIWORD(v132);
      v88 = v132;
      v90 = HIWORD(v132) < (unsigned __int16)v132;
      if ( HIWORD(v132) == (_WORD)v132 )
      {
        v89 = HIWORD(v132) + 1;
        v91 = 0;
        ++HIWORD(v132);
        if ( SLODWORD(v161[0]) > 0 )
        {
          do
            *((_DWORD *)&v161[152] + v91++) = 0;
          while ( v91 < SLODWORD(v161[0]) );
        }
        HIDWORD(v161[148]) = 3;
        v90 = v89 < v88;
      }
      if ( v90 == (HIDWORD(v161[148]) == 3) )
      {
        v92 = v132;
        LOWORD(v132) = v89;
        HIWORD(v132) = v92;
        v122 = 1;
      }
      else
      {
        v122 = 0;
      }
      v93 = 0;
      *(_DWORD *)v129 = v132;
      v94 = v129 + 2;
      v129 += 2;
      if ( S3TC_BLOCK_WIDTH / 4 > 0 )
      {
        v114 = &v155[15];
        do
        {
          v95 = v114;
          v96 = 0;
          for ( i4 = 16; i4 != 0; --i4 )
          {
            v96 *= 4;
            if ( *v95 >= 0 )
            {
              v96 |= *((_DWORD *)&v161[152] + *v95);
              if ( v122 != 0 )
              {
                if ( HIDWORD(v161[148]) == 4 )
                  v96 ^= 1u;
                else
                  v96 ^= (~v96 & 2) != 0;
              }
            }
            else
            {
              LOBYTE(v96) = v96 | 3;
            }
            --v95;
          }
          *v94 = v96;
          v114 += 16;
          ++v94;
          ++v93;
        }
        while ( v93 < S3TC_BLOCK_WIDTH / 4 );
        v129 = v94;
      }
      v133 += v128;
      v139 += 4;
      dwWidth = a1->dwWidth;
      if ( v139 >= dwWidth )
        goto LABEL_171;
    }
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1000A970
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x1000A990
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x1000A9C0
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA30
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace vtex_dll

// ============================================================
// Overlay from vtf2tga (Missing functions)
// ============================================================
namespace vtf2tga {

//------------------------------------------------------------------------------
// Address: 0x00401C60
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x00401C80
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x00401CB0
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401D20
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace vtf2tga

// ============================================================
// Overlay from vtfdiff (Missing functions)
// ============================================================
namespace vtfdiff {

//------------------------------------------------------------------------------
// Address: 0x004037D0
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x004037F0
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x00403820
// Name: int ImageLoader::GetNumMipMapLevels(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetNumMipMapLevels(int width, int height, int depth)
{
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax

  v3 = depth;
  if ( depth <= 0 )
    v3 = 1;
  v4 = width;
  if ( width < 1 )
    return 0;
  v5 = height;
  if ( height < 1 || v3 < 1 )
    return 0;
  result = 1;
  while ( v4 != 1 || v5 != 1 || v3 != 1 )
  {
    v4 >>= 1;
    v5 >>= 1;
    v3 >>= 1;
    if ( v4 < 1 )
      v4 = 1;
    if ( v5 < 1 )
      v5 = 1;
    if ( v3 < 1 )
      v3 = 1;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403890
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace vtfdiff

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1027E200
// Name: struct ImageFormatInfo_t const __near & ImageLoader::ImageFormatInfo(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
const ImageFormatInfo_t *__cdecl ImageLoader::ImageFormatInfo(ImageFormat fmt)
{
  return &g_ImageFormatInfo[fmt + 1];
}

//------------------------------------------------------------------------------
// Address: 0x1027E220
// Name: int ImageLoader::GetMemRequired(int,int,int,enum ImageFormat,bool,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        ImageFormat imageFormat,
        bool mipmap,
        int *pAdjustedHeight)
{
  return ImageLoader::GetMemRequired(width, height, depth, nMipmapCount: !mipmap, imageFormat, pAdjustedHeight);
}

//------------------------------------------------------------------------------
// Address: 0x1027E250
// Name: int ImageLoader::GetMemRequired(int,int,int,int,enum ImageFormat,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::GetMemRequired(
        int width,
        int height,
        int depth,
        int nMipmapCount,
        ImageFormat imageFormat,
        int *pAdjustedHeight)
{
  int v6; // edi
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // esi
  int memSize; // [esp+1Ch] [ebp+10h]

  v6 = depth;
  if ( depth < 1 )
    v6 = 1;
  result = 0;
  if ( nMipmapCount == 1 )
  {
    if ( (*((_BYTE *)&g_ImageFormatInfo[imageFormat + 1] + 11) & 1) != 0 )
    {
      v8 = width;
      if ( (unsigned int)(width - 1) <= 2 )
        v8 = 4;
      v9 = height;
      if ( (unsigned int)(height - 1) <= 2 )
        v9 = 4;
      if ( (unsigned int)(v6 - 2) <= 1 )
        v6 = 4;
      v10 = v9 >> 2;
      v11 = v6 * v10 * (v8 >> 2);
      switch ( imageFormat )
      {
        case IMAGE_FORMAT_DXT1:
        case IMAGE_FORMAT_ATI1N:
        case IMAGE_FORMAT_LINEAR_DXT1:
          result = 8 * v11;
          break;
        case IMAGE_FORMAT_DXT3:
        case IMAGE_FORMAT_DXT5:
        case IMAGE_FORMAT_ATI2N:
        case IMAGE_FORMAT_LINEAR_DXT3:
        case IMAGE_FORMAT_LINEAR_DXT5:
          result = 16 * v11;
          break;
        default:
          break;
      }
    }
    else
    {
      v10 = height;
      result = v6 * height * width * g_ImageFormatInfo[imageFormat + 1].m_nNumBytes;
    }
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = v10;
  }
  else
  {
    memSize = 0;
    if ( pAdjustedHeight != nullptr )
      *pAdjustedHeight = 0;
    v12 = height;
    v13 = width;
    do
    {
      memSize += ImageLoader::GetMemRequired(
                   width: v13,
                   height: v12,
                   depth: v6,
                   nMipmapCount: 1,
                   imageFormat,
                   pAdjustedHeight: nullptr);
      if ( v13 == 1 && v12 == 1 && v6 == 1 )
        break;
      v13 >>= 1;
      v12 >>= 1;
      v6 >>= 1;
      if ( v13 < 1 )
        v13 = 1;
      if ( v12 < 1 )
        v12 = 1;
      if ( v6 < 1 )
        v6 = 1;
    }
    while ( nMipmapCount == 0 || --nMipmapCount != 0 );
    return memSize;
  }
  return result;
}

} // namespace client
