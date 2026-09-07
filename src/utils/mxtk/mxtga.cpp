// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxtga.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004C4170
// Name: bool mxTgaWrite(char const __near *,class mxImage __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl mxTgaWrite(_iobuf *filename, mxImage *image)
{
  int v2; // edi
  _iobuf *v4; // eax
  _iobuf *v5; // esi
  int height; // eax
  int width; // ecx
  int v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // edi
  unsigned __int8 *data; // [esp+8h] [ebp-Ch]
  int y; // [esp+Ch] [ebp-8h]
  int w; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  if ( image == nullptr || image->bpp != 24 )
    return 0;
  v4 = fopen(file: filename, mode: "wb");
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  fputc(ch: 0, str: v4);
  fputc(ch: 0, str: v5);
  fputc(ch: 2, str: v5);
  w = 0;
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  fputc(ch: 0, str: v5);
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  w = LOWORD(image->width);
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  w = LOWORD(image->height);
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  fputc(ch: 24, str: v5);
  fputc(ch: 0, str: v5);
  data = (unsigned __int8 *)image->data;
  height = image->height;
  y = 0;
  if ( height > 0 )
  {
    width = image->width;
    do
    {
      v8 = width * (height - v2 - 1);
      v9 = 0;
      if ( width > 0 )
      {
        v10 = &data[2 * v8 + 1 + v8];
        do
        {
          fputc(ch: v10[1], str: v5);
          fputc(ch: *v10, str: v5);
          fputc(ch: *(v10 - 1), str: v5);
          width = image->width;
          ++v9;
          v10 += 3;
        }
        while ( v9 < width );
        v2 = y;
      }
      height = image->height;
      y = ++v2;
    }
    while ( v2 < height );
  }
  fclose(stream: v5);
  return 1;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056F910
// Name: bool mxTgaWrite(char const __near *,class mxImage __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl mxTgaWrite(const char *filename, mxImage *image)
{
  int v2; // edi
  _iobuf *v4; // eax
  _iobuf *v5; // esi
  int height; // eax
  int width; // ecx
  int v8; // eax
  int v9; // ebx
  unsigned __int8 *v10; // edi
  unsigned __int8 *data; // [esp+8h] [ebp-Ch]
  int y; // [esp+Ch] [ebp-8h]
  int w; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  if ( image == nullptr || image->bpp != 24 )
    return 0;
  v4 = fopen(file: filename, mode: "wb");
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  fputc(ch: 0, str: v4);
  fputc(ch: 0, str: v5);
  fputc(ch: 2, str: v5);
  w = 0;
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  fputc(ch: 0, str: v5);
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  w = LOWORD(image->width);
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  w = LOWORD(image->height);
  fwrite(buffer: &w, size: 2u, count: 1u, stream: v5);
  fputc(ch: 24, str: v5);
  fputc(ch: 0, str: v5);
  data = (unsigned __int8 *)image->data;
  height = image->height;
  y = 0;
  if ( height > 0 )
  {
    width = image->width;
    do
    {
      v8 = width * (height - v2 - 1);
      v9 = 0;
      if ( width > 0 )
      {
        v10 = &data[2 * v8 + 1 + v8];
        do
        {
          fputc(ch: v10[1], str: v5);
          fputc(ch: *v10, str: v5);
          fputc(ch: *(v10 - 1), str: v5);
          width = image->width;
          ++v9;
          v10 += 3;
        }
        while ( v9 < width );
        v2 = y;
      }
      height = image->height;
      y = ++v2;
    }
    while ( v2 < height );
  }
  fclose(stream: v5);
  return 1;
}

} // namespace hlmv
