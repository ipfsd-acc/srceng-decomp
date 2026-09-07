// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/imagebyteswap.cpp
// Functions: 2
// ============================================================

#include "bitmap\imagebyteswap.h"

//------------------------------------------------------------------------------
// Address: 0x0055C8E0
// Name: bool ImageLoader::IsFormatValidForConversion(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ImageLoader::IsFormatValidForConversion(ImageFormat fmt)
{
  bool result; // al

  switch ( fmt )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_ABGR8888:
    case IMAGE_FORMAT_RGB888:
    case IMAGE_FORMAT_BGR888:
    case IMAGE_FORMAT_ARGB8888:
    case IMAGE_FORMAT_BGRA8888:
    case IMAGE_FORMAT_DXT1:
    case IMAGE_FORMAT_DXT3:
    case IMAGE_FORMAT_DXT5:
    case IMAGE_FORMAT_BGRX8888:
    case IMAGE_FORMAT_DXT1_ONEBITALPHA:
    case IMAGE_FORMAT_UV88:
    case IMAGE_FORMAT_UVWQ8888:
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
    case IMAGE_FORMAT_UVLX8888:
      result = true;
      break;
    default:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0055C930
// Name: void ImageLoader::PostConvertSwapImageData(unsigned char __near *,int,enum ImageFormat,enum VtfConsoleFormatType_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ImageLoader::PostConvertSwapImageData(
        unsigned __int8 *pImageData,
        int nImageSize,
        ImageFormat imageFormat,
        VtfConsoleFormatType_t targetConsole,
        unsigned int width,
        int stride)
{
  XGENDIANTYPE v6; // edi
  unsigned __int8 *v7; // esi
  ImageFormat imageFormata; // [esp+10h] [ebp+10h]

  switch ( imageFormat )
  {
    case IMAGE_FORMAT_BGRA8888:
    case IMAGE_FORMAT_BGRX8888:
    case IMAGE_FORMAT_UVWQ8888:
    case IMAGE_FORMAT_UVLX8888:
      v6 = XGENDIAN_8IN32;
      goto LABEL_6;
    case IMAGE_FORMAT_DXT1:
    case IMAGE_FORMAT_DXT3:
    case IMAGE_FORMAT_DXT5:
    case IMAGE_FORMAT_DXT1_ONEBITALPHA:
    case IMAGE_FORMAT_UV88:
    case IMAGE_FORMAT_ATI2N:
    case IMAGE_FORMAT_ATI1N:
      if ( targetConsole == VTF_CONSOLE_PS3 )
        return;
      v6 = XGENDIAN_8IN16;
LABEL_6:
      if ( stride != 0 )
      {
        if ( nImageSize / stride > 0 )
        {
          v7 = pImageData;
          imageFormata = nImageSize / stride;
          do
          {
            XGEndianSwapMemory(
              pDestination: v7,
              pSource: v7,
              SwapType: v6,
              Stride: (unsigned int)v6 >> 16,
              Count: width);
            v7 += stride;
            --imageFormata;
          }
          while ( imageFormata != IMAGE_FORMAT_RGBA8888 );
        }
      }
      else
      {
        XGEndianSwapMemory(
          pDestination: pImageData,
          pSource: pImageData,
          SwapType: v6,
          Stride: (unsigned int)v6 >> 16,
          Count: nImageSize / (int)((unsigned int)v6 >> 16));
      }
      return;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      v6 = XGENDIAN_8IN16;
      goto LABEL_6;
    default:
      return;
  }
}
