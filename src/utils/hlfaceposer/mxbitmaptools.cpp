// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/mxbitmaptools.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004650D0
// Name: bool LoadBitmapFromFile(char const __near *,struct mxbitmapdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LoadBitmapFromFile(const char *relative, mxbitmapdata_t *bitmap)
{
  mxbitmapdata_t *v2; // ebx
  HBITMAP ImageA; // esi
  HDC DC; // eax
  HDC v5; // edi
  HBITMAP__ *CompatibleBitmap; // eax
  HDC CompatibleDC; // ebx
  HMODULE ModuleHandleA; // eax
  HMODULE v10; // eax
  int biHeight; // edx
  char filename[512]; // [esp+Ch] [ebp-238h] BYREF
  tagBITMAPINFO bmi; // [esp+20Ch] [ebp-38h] BYREF
  HBITMAP__ *oldbm; // [esp+238h] [ebp-Ch]
  HBITMAP__ *oldmembm; // [esp+23Ch] [ebp-8h]
  HBITMAP__ *bm; // [esp+240h] [ebp-4h]

  v2 = bitmap;
  ImageA = nullptr;
  bitmap->valid = false;
  bitmap->image = nullptr;
  bitmap->width = -1;
  bitmap->height = -1;
  DC = GetDC(hWnd: nullptr);
  v5 = DC;
  if ( DC == nullptr )
    return false;
  CompatibleBitmap = CreateCompatibleBitmap(hdc: DC, cx: 100, cy: 100);
  bm = CompatibleBitmap;
  if ( CompatibleBitmap != nullptr )
  {
    oldbm = (HBITMAP__ *)SelectObject(hdc: v5, h: CompatibleBitmap);
    CompatibleDC = CreateCompatibleDC(hdc: v5);
    if ( CompatibleDC != nullptr )
    {
      filesystem->RelativePathToFullPath(
        this: filesystem,
        a2: relative,
        a3: "MOD",
        a4: filename,
        a5: 512,
        a6: (PathTypeFilter_t)0,
        a7: nullptr);
      ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
      ImageA = (HBITMAP)LoadImageA(hInst: ModuleHandleA, name: filename, type: 0, cx: 0, cy: 0, fuLoad: 0x50u);
      if ( ImageA != nullptr
        || (filesystem->RelativePathToFullPath(
              this: filesystem,
              a2: relative,
              a3: "GAME",
              a4: filename,
              a5: 512,
              a6: (PathTypeFilter_t)0,
              a7: nullptr),
            v10 = GetModuleHandleA(lpModuleName: nullptr),
            (ImageA = (HBITMAP)LoadImageA(hInst: v10, name: filename, type: 0, cx: 0, cy: 0, fuLoad: 0x50u)) != nullptr) )
      {
        oldmembm = (HBITMAP__ *)SelectObject(hdc: CompatibleDC, h: ImageA);
        memset(dst: (unsigned __int8 *)&bmi, value: 0, count: sizeof(bmi));
        bmi.bmiHeader.biSize = 40;
        if ( GetDIBits(hdc: CompatibleDC, hbm: ImageA, start: 0, cLines: 0, lpvBits: nullptr, lpbmi: &bmi, usage: 0) != 0 )
        {
          biHeight = bmi.bmiHeader.biHeight;
          bitmap->width = bmi.bmiHeader.biWidth;
          bitmap->height = biHeight;
        }
        SelectObject(hdc: CompatibleDC, h: oldmembm);
      }
      DeleteDC(hdc: CompatibleDC);
    }
    SelectObject(hdc: v5, h: oldbm);
    DeleteObject(ho: bm);
    v2 = bitmap;
  }
  ReleaseDC(hWnd: nullptr, hDC: v5);
  if ( ImageA != nullptr && v2->width != -1 && v2->height != -1 )
  {
    v2->image = ImageA;
    v2->valid = true;
  }
  return v2->valid;
}

//------------------------------------------------------------------------------
// Address: 0x00465270
// Name: void DrawBitmapToDC(void __near *,int,int,int,int,struct mxbitmapdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawBitmapToDC(HDC hdc, int x, int y, int w, int h, mxbitmapdata_t *bitmap)
{
  HDC CompatibleDC; // esi
  HBITMAP__ *oldmembm; // [esp+4h] [ebp-4h]
  int oldmode; // [esp+24h] [ebp+1Ch]

  if ( bitmap->valid )
  {
    CompatibleDC = CreateCompatibleDC(hdc);
    oldmembm = (HBITMAP__ *)SelectObject(hdc: CompatibleDC, h: bitmap->image);
    oldmode = SetStretchBltMode(hdc, mode: 3);
    StretchBlt(
      hdcDest: hdc,
      xDest: x,
      yDest: y,
      wDest: w,
      hDest: h,
      hdcSrc: CompatibleDC,
      xSrc: 0,
      ySrc: 0,
      wSrc: bitmap->width,
      hSrc: bitmap->height,
      rop: 0xCC0020u);
    SetStretchBltMode(hdc, mode: oldmode);
    SelectObject(hdc: CompatibleDC, h: oldmembm);
    DeleteDC(hdc: CompatibleDC);
  }
}
