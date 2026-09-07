// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sys_getmodes.cpp
// Functions: 50
// ============================================================

#include "engine\sys_getmodes.h"

//------------------------------------------------------------------------------
// Address: 0x101E9F50
// Name: PFMWrite
// Source: json
//------------------------------------------------------------------------------
void __usercall PFMWrite(const char *pFilename@<edx>, int height@<eax>, float *pFloatImage, int width)
{
  void *v5; // edi
  int v6; // esi
  float *v7; // ebx

  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename, a3: "wb", a4: 0);
  g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "PF\n%d %d\n-1.000000\n", width, height);
  v6 = height - 1;
  if ( v6 >= 0 )
  {
    v7 = &pFloatImage[3 * width * v6];
    do
    {
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v7, a3: 12 * width, a4: v5);
      v7 -= 3 * width;
      --v6;
    }
    while ( v6 >= 0 );
  }
  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101EA000
// Name: public: virtual bool CVideoMode_Common::IsWindowedMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVideoMode_Common::IsWindowedMode(CVideoMode_Common *this)
{
  return this->m_bWindowed;
}

//------------------------------------------------------------------------------
// Address: 0x101EA010
// Name: public: virtual bool CVideoMode_Common::NoWindowBorder(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVideoMode_Common::NoWindowBorder(CVideoMode_Common *this)
{
  return this->m_bNoWindowBorder;
}

//------------------------------------------------------------------------------
// Address: 0x101EA020
// Name: public: virtual int CVideoMode_Common::GetModeWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVideoMode_Common::GetModeWidth(CVideoMode_Common *this)
{
  return this->m_nModeWidth;
}

//------------------------------------------------------------------------------
// Address: 0x101EA030
// Name: public: virtual int CVideoMode_Common::GetModeHeight(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVideoMode_Common::GetModeHeight(CVideoMode_Common *this)
{
  return this->m_nModeHeight;
}

//------------------------------------------------------------------------------
// Address: 0x101EA040
// Name: public: virtual struct vmode_s __near * CVideoMode_Common::GetMode(int)
// Source: json
//------------------------------------------------------------------------------
vmode_s *__thiscall CVideoMode_Common::GetMode(CVideoMode_Common *this, int num)
{
  if ( num < 0 )
    return &this->m_rgModeList[-num + 511];
  if ( num < this->m_nNumModes )
    return &this->m_rgModeList[num];
  return this->m_nCustomModeList;
}

//------------------------------------------------------------------------------
// Address: 0x101EA080
// Name: VideoModeCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl VideoModeCompare(_DWORD *arg1, _DWORD *arg2)
{
  int v3; // eax
  int v4; // ecx

  if ( *arg1 < *arg2 )
    return -1;
  if ( *arg1 != *arg2 )
    return 1;
  v3 = arg1[1];
  v4 = arg2[1];
  if ( v3 < v4 )
    return -1;
  return v3 > v4;
}

//------------------------------------------------------------------------------
// Address: 0x101EA0C0
// Name: protected: int CVideoMode_Common::FindVideoMode(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVideoMode_Common::FindVideoMode(
        CVideoMode_Common *this,
        int nDesiredWidth,
        int nDesiredHeight,
        bool bWindowed)
{
  int result; // eax
  int m_nNumModes; // edx
  int v6; // esi
  int *p_height; // ecx

  if ( nDesiredWidth == this->m_nCustomModeList[0].width && nDesiredHeight == this->m_nCustomModeList[0].height )
    return -1;
  if ( bWindowed
    && nDesiredWidth == this->m_nCustomModeList[1].width
    && nDesiredHeight == this->m_nCustomModeList[1].height )
  {
    return -2;
  }
  m_nNumModes = this->m_nNumModes;
  v6 = -1;
  result = 0;
  if ( m_nNumModes > 0 )
  {
    p_height = &this->m_rgModeList[0].height;
    do
    {
      if ( *(p_height - 1) == nDesiredWidth )
      {
        v6 = result;
        if ( *p_height == nDesiredHeight )
          break;
      }
      ++result;
      p_height += 4;
    }
    while ( result < m_nNumModes );
  }
  if ( result >= m_nNumModes )
    return v6 != -1 ? v6 : 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EA140
// Name: protected: void CVideoMode_Common::ResetCurrentModeForNewResolution(int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::ResetCurrentModeForNewResolution(
        CVideoMode_Common *this,
        int nWidth,
        int nHeight,
        bool bWindowed,
        bool bNoWindowBorder)
{
  int VideoMode; // edi
  vmode_s *v7; // eax
  int width; // ecx
  int height; // edx

  VideoMode = CVideoMode_Common::FindVideoMode(this, nDesiredWidth: nWidth, nDesiredHeight: nHeight, bWindowed);
  v7 = this->GetMode(this, a2: VideoMode);
  width = v7->width;
  height = v7->height;
  if ( bWindowed && VideoMode == 0 && (width != nWidth || height != nHeight) )
  {
    height = nHeight;
    width = nWidth;
  }
  this->m_nModeWidth = width;
  this->m_bWindowed = bWindowed;
  this->m_nModeHeight = height;
  this->m_bNoWindowBorder = bNoWindowBorder;
}

//------------------------------------------------------------------------------
// Address: 0x101EA1C0
// Name: private: class IVTFTexture __near * CVideoMode_Common::LoadVTF(class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IVTFTexture *__thiscall CVideoMode_Common::LoadVTF(CVideoMode_Common *this, CUtlBuffer *temp, const char *szFileName)
{
  IVTFTexture *VTFTexture; // esi

  if ( !g_pFileSystem->ReadFile(
          this: &g_pFileSystem->IBaseFileSystem,
          a2: szFileName,
          a3: nullptr,
          a4: temp,
          a5: 0,
          a6: 0,
          a7: nullptr) )
    return nullptr;
  VTFTexture = CreateVTFTexture();
  if ( VTFTexture->Unserialize(this: VTFTexture, a2: temp, a3: false, a4: 0) )
  {
    VTFTexture->ConvertImageFormat(this: VTFTexture, a2: IMAGE_FORMAT_RGBA8888, a3: false, a4: false);
    return VTFTexture;
  }
  else
  {
    _Error(a1: "Invalid or corrupt background texture %s\n", szFileName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EA240
// Name: protected: void CVideoMode_Common::DrawStartupVideo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::DrawStartupVideo(CVideoMode_Common *this)
{
  if ( !this->m_bPlayedStartupVideo && g_pHammer == nullptr )
  {
    game->PlayStartupVideos(this: game);
    this->m_bPlayedStartupVideo = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EA270
// Name: public: virtual void CVideoMode_Common::InvalidateWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::InvalidateWindow(CVideoMode_Common *this)
{
  int v1; // eax
  HWND v2; // eax

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-noshaderapi") != 0 )
  {
    v2 = (HWND)game->GetMainWindow(this: game);
    InvalidateRect(hWnd: v2, lpRect: nullptr, bErase: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EA2B0
// Name: public: virtual void CVideoMode_Common::DrawNullBackground(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::DrawNullBackground(CVideoMode_Common *this, HDC hHDC, int w, int h)
{
  int v4; // eax
  HFONT FontA; // ebx
  const char *v7; // eax
  tagRECT rc; // [esp+0h] [ebp-20h] BYREF
  HBRUSH__ *br; // [esp+10h] [ebp-10h]
  HFONT__ *oldFont; // [esp+14h] [ebp-Ch]
  int oldBkMode; // [esp+18h] [ebp-8h]
  HBRUSH__ *oldBr; // [esp+1Ch] [ebp-4h]
  unsigned int oldFgColor; // [esp+28h] [ebp+8h]

  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-noshaderapi") != 0 )
  {
    FontA = CreateFontA(
              cHeight: -12,
              cWidth: 0,
              cEscapement: 0,
              cOrientation: 0,
              cWeight: 400,
              bItalic: 0,
              bUnderline: 0,
              bStrikeOut: 0,
              iCharSet: 0,
              iOutPrecision: 4u,
              iClipPrecision: 0,
              iQuality: 4u,
              iPitchAndFamily: 0,
              pszFaceName: "Arial");
    oldFont = (HFONT__ *)SelectObject(hdc: hHDC, h: FontA);
    oldBkMode = SetBkMode(hdc: hHDC, mode: 1);
    oldFgColor = SetTextColor(hdc: hHDC, color: 0xFFFFFFu);
    br = CreateSolidBrush(color: 0);
    oldBr = (HBRUSH__ *)SelectObject(hdc: hHDC, h: br);
    Rectangle(hdc: hHDC, left: 0, top: 0, right: w, bottom: h);
    rc.left = 0;
    rc.top = 0;
    rc.right = w;
    rc.bottom = h;
    DrawTextA(hdc: hHDC, lpchText: "Running with -noshaderapi", cchText: -1, lprc: &rc, format: 0x825u);
    rc.top = rc.bottom - 30;
    if ( host_state.worldmodel != nullptr )
    {
      rc.left += 10;
      v7 = modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
      DrawTextA(hdc: hHDC, lpchText: v7, cchText: -1, lprc: &rc, format: 0x824u);
    }
    SetTextColor(hdc: hHDC, color: oldFgColor);
    SelectObject(hdc: hHDC, h: oldBr);
    SetBkMode(hdc: hHDC, mode: oldBkMode);
    SelectObject(hdc: hHDC, h: oldFont);
    DeleteObject(ho: br);
    DeleteObject(ho: FontA);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EA3F0
// Name: public: virtual void CVideoMode_Common::UpdateWindowPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::UpdateWindowPosition(CVideoMode_Common *this)
{
  int x; // [esp+0h] [ebp-10h] BYREF
  int y; // [esp+4h] [ebp-Ch] BYREF
  int w; // [esp+8h] [ebp-8h] BYREF
  int h; // [esp+Ch] [ebp-4h] BYREF

  game->GetWindowRect(this: game, a2: &x, a3: &y, a4: &w, a5: &h);
}

//------------------------------------------------------------------------------
// Address: 0x101EA420
// Name: public: virtual void CVideoMode_Common::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::Shutdown(CVideoMode_Common *this)
{
  this->ReleaseFullScreen(this);
  game->DestroyGameWindow(this: game);
  if ( this->m_bInitialized )
    this->m_bInitialized = false;
}

//------------------------------------------------------------------------------
// Address: 0x101EA450
// Name: public: virtual void CVideoMode_Common::SetClientViewRect(struct vrect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::SetClientViewRect(CVideoMode_Common *this, const vrect_t *viewRect)
{
  this->m_ClientViewRect = *viewRect;
}

//------------------------------------------------------------------------------
// Address: 0x101EA490
// Name: public: virtual void CVideoMode_Common::MarkClientViewRectDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::MarkClientViewRectDirty(CVideoMode_Common *this)
{
  this->m_bClientViewRectDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x101EA4A0
// Name: private: void CVideoMode_Common::CenterEngineWindow(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::CenterEngineWindow(CVideoMode_Common *this, HWND hWndCenter, int width, int height)
{
  int SystemMetrics; // ecx
  int v5; // kr00_4
  int v6; // kr04_4
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // edi
  int refreshRate; // [esp+Ch] [ebp-Ch] BYREF
  int cyScreen; // [esp+10h] [ebp-8h] BYREF
  int cxScreen; // [esp+14h] [ebp-4h] BYREF

  cxScreen = 0;
  cyScreen = 0;
  refreshRate = 0;
  if ( (GetWindowLongA(hWnd: hWndCenter, nIndex: -20) & 8) == 0 )
    game->GetDesktopInfo(this: game, a2: &cxScreen, a3: &cyScreen, a4: &refreshRate);
  if ( cxScreen == 0 || (SystemMetrics = cyScreen, cyScreen == 0) )
  {
    cxScreen = GetSystemMetrics(nIndex: 0);
    SystemMetrics = GetSystemMetrics(nIndex: 1);
  }
  v5 = cxScreen - width;
  v6 = SystemMetrics - height;
  v7 = _CommandLine();
  v8 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v7 + 28))(
         a1: v7,
         a2: "-x",
         a3: v5 / 2 < 0 ? 0 : v5 / 2);
  v9 = _CommandLine();
  v10 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 28))(
          a1: v9,
          a2: "-y",
          a3: v6 / 2 < 0 ? 0 : v6 / 2);
  game->SetWindowXY(this: game, a2: v8, a3: v10);
  SetWindowPos(hWnd: hWndCenter, hWndInsertAfter: nullptr, X: v8, Y: v10, cx: 0, cy: 0, uFlags: 0x65u);
}

//------------------------------------------------------------------------------
// Address: 0x101EA580
// Name: private: virtual void CVideoMode_Common::ReadScreenPixels(int,int,int,int,void __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::ReadScreenPixels(
        CVideoMode_Common *this,
        int x,
        int y,
        int w,
        int h,
        unsigned __int8 *pBuffer,
        ImageFormat format)
{
  unsigned int MemRequired; // eax

  MemRequired = ImageLoader::GetMemRequired(
                  width: w,
                  height: h,
                  depth: 1,
                  imageFormat: format,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  memset(dst: pBuffer, value: 0, count: MemRequired);
}

//------------------------------------------------------------------------------
// Address: 0x101EA5B0
// Name: void GetCubemapOffset(enum CubeMapFaceIndex_t,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetCubemapOffset(CubeMapFaceIndex_t faceIndex, int *x, int *y, int *faceDim)
{
  int v4; // eax
  int fbHeight; // [esp+4h] [ebp-8h] BYREF
  int fbWidth; // [esp+8h] [ebp-4h] BYREF

  materials->GetBackBufferDimensions(this: materials, a2: &fbWidth, a3: &fbHeight);
  if ( 4 * fbWidth <= 3 * fbHeight )
    v4 = fbWidth / 4;
  else
    v4 = fbHeight / 3;
  *faceDim = v4;
  switch ( faceIndex )
  {
    case CUBEMAP_FACE_RIGHT:
      *x = 2;
      *y = 1;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
    case CUBEMAP_FACE_LEFT:
      *x = 0;
      *y = 1;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
    case CUBEMAP_FACE_BACK:
      *x = 1;
      *y = 1;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
    case CUBEMAP_FACE_FRONT:
      *x = 3;
      *y = 1;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
    case CUBEMAP_FACE_UP:
      *x = 2;
      *y = 0;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
    case CUBEMAP_FACE_DOWN:
      *x = 2;
      *y = 2;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EA710
// Name: init_destination
// Source: json
//------------------------------------------------------------------------------
void __cdecl init_destination(jpeg_common_struct *cinfo)
{
  jpeg_destination_mgr *err; // esi
  int v2; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 4096);
  err[1].free_in_buffer = v2;
  err->next_output_byte = (unsigned __int8 *)v2;
  err->free_in_buffer = 4096;
}

//------------------------------------------------------------------------------
// Address: 0x101EA740
// Name: empty_output_buffer
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl empty_output_buffer(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // esi

  dest = cinfo->dest;
  CUtlBuffer::Put(
    this: (CUtlBuffer *)dest[1].next_output_byte,
    pMem: (unsigned __int8 *)dest[1].free_in_buffer,
    size: 4096);
  dest->next_output_byte = (unsigned __int8 *)dest[1].free_in_buffer;
  dest->free_in_buffer = 4096;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EA770
// Name: term_destination
// Source: json
//------------------------------------------------------------------------------
void __cdecl term_destination(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // eax

  dest = cinfo->dest;
  if ( dest->free_in_buffer != 4096 )
    CUtlBuffer::Put(
      this: (CUtlBuffer *)dest[1].next_output_byte,
      pMem: (unsigned __int8 *)dest[1].free_in_buffer,
      size: 4096 - dest->free_in_buffer);
}

//------------------------------------------------------------------------------
// Address: 0x101EA7A0
// Name: VideoMode_AdjustForModeChange
// Source: json
//------------------------------------------------------------------------------
int VideoMode_AdjustForModeChange()
{
  return ((int (__thiscall *)(IVideoMode *))videomode->__vftable[1].DrawStartupGraphic)(a1: videomode);
}

//------------------------------------------------------------------------------
// Address: 0x101EA7B0
// Name: public: virtual bool CVideoMode_MaterialSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVideoMode_MaterialSystem::Init(CVideoMode_MaterialSystem *this)
{
  int v2; // eax
  int v3; // edi
  int (__thiscall *GetModeCount)(IMaterialSystem *, int); // eax
  int v5; // eax
  void (__thiscall *GetDesktopInfo)(IGame *, int *, int *, int *); // edx
  int v7; // ebx
  int m_nNumModes; // edx
  int v9; // eax
  int *p_height; // ecx
  signed int v11; // eax
  int *p_refreshRate; // ecx
  MaterialVideoMode_t info; // [esp+4h] [ebp-2Ch] BYREF
  int nDesktopWidth; // [esp+14h] [ebp-1Ch] BYREF
  int nDesktopHeight; // [esp+18h] [ebp-18h] BYREF
  int nModeCount; // [esp+1Ch] [ebp-14h]
  int nDesktopRefresh; // [esp+20h] [ebp-10h] BYREF
  int nAdapter; // [esp+24h] [ebp-Ch]
  int i; // [esp+28h] [ebp-8h]
  bool bAllowSmallModes; // [esp+2Fh] [ebp-1h]

  this->m_bSetModeOnce = false;
  this->m_bPlayedStartupVideo = false;
  v2 = _CommandLine();
  bAllowSmallModes = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-small") != 0;
  v3 = materials->GetCurrentAdapter(this: materials);
  GetModeCount = materials->GetModeCount;
  nAdapter = v3;
  v5 = GetModeCount(this: materials, a2: v3);
  GetDesktopInfo = game->GetDesktopInfo;
  v7 = v5;
  nModeCount = v5;
  GetDesktopInfo(this: game, a2: &nDesktopWidth, a3: &nDesktopHeight, a4: &nDesktopRefresh);
  i = 0;
  if ( v7 > 0 )
  {
    while ( 1 )
    {
      materials->GetModeInfo(this: materials, a2: v3, a3: i, a4: &info);
      if ( info.m_Width >= 640 && info.m_Height >= 480 || bAllowSmallModes )
      {
        m_nNumModes = this->m_nNumModes;
        v9 = 0;
        if ( m_nNumModes <= 0 )
        {
LABEL_12:
          this->m_rgModeList[m_nNumModes].width = info.m_Width;
          this->m_rgModeList[this->m_nNumModes].height = info.m_Height;
          this->m_rgModeList[this->m_nNumModes].bpp = 32;
          this->m_rgModeList[this->m_nNumModes++].refreshRate = info.m_RefreshRate;
          if ( this->m_nNumModes >= 512 )
            break;
        }
        else
        {
          p_height = &this->m_rgModeList[0].height;
          while ( info.m_Width != *(p_height - 1) || info.m_Height != *p_height )
          {
            ++v9;
            p_height += 4;
            if ( v9 >= m_nNumModes )
              goto LABEL_12;
          }
          if ( info.m_RefreshRate <= nDesktopRefresh )
          {
            p_refreshRate = &this->m_rgModeList[v9].refreshRate;
            if ( *p_refreshRate > nDesktopRefresh || *p_refreshRate < info.m_RefreshRate )
              *p_refreshRate = info.m_RefreshRate;
          }
        }
      }
      if ( ++i >= nModeCount )
        break;
      v3 = nAdapter;
    }
  }
  v11 = this->m_nNumModes;
  if ( v11 > 1 )
    qsort(base: this->m_rgModeList, num: v11, width: 0x10u, comp: VideoModeCompare);
  materials->AddModeChangeCallBack(this: materials, a2: (void (__cdecl *)())VideoMode_AdjustForModeChange);
  this->m_bInitialized = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EA940
// Name: public: virtual void CVideoMode_MaterialSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_MaterialSystem::Shutdown(CVideoMode_MaterialSystem *this)
{
  materials->RemoveModeChangeCallBack(this: materials, a2: (void (__cdecl *)())VideoMode_AdjustForModeChange);
  this->ReleaseFullScreen(this);
  game->DestroyGameWindow(this: game);
  if ( this->m_bInitialized )
    this->m_bInitialized = false;
}

//------------------------------------------------------------------------------
// Address: 0x101EA980
// Name: public: virtual bool CVideoMode_MaterialSystem::SetMode(int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVideoMode_MaterialSystem::SetMode(
        CVideoMode_MaterialSystem *this,
        int nWidth,
        int nHeight,
        bool bWindowed,
        bool bNoWindowBorder)
{
  int v6; // esi
  vmode_s *v7; // eax
  int width; // edx
  int bpp; // ecx
  int refreshRate; // eax
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // edi
  int v15; // eax
  IMaterialSystem_vtbl *v16; // esi
  int v17; // eax
  char result; // al
  vgui::PropertyPage *v19; // ecx
  MaterialSystem_Config_t config; // [esp+Ch] [ebp-74h] BYREF
  vmode_s videoMode; // [esp+70h] [ebp-10h]

  S_ClearBuffer();
  v6 = CVideoMode_Common::FindVideoMode(this, nDesiredWidth: nWidth, nDesiredHeight: nHeight, bWindowed);
  v7 = this->GetMode(this, a2: v6);
  width = v7->width;
  videoMode.height = v7->height;
  bpp = v7->bpp;
  refreshRate = v7->refreshRate;
  videoMode.bpp = bpp;
  videoMode.refreshRate = refreshRate;
  if ( bWindowed && v6 == 0 && (width != nWidth || videoMode.height != nHeight) )
  {
    width = nWidth;
    videoMode.height = nHeight;
  }
  config = *g_pMaterialSystemConfig;
  config.m_VideoMode.m_Width = width;
  config.m_VideoMode.m_Height = videoMode.height;
  v11 = _CommandLine();
  v12 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v11 + 28))(
          a1: v11,
          a2: "-freq",
          a3: videoMode.refreshRate);
  v13 = _CommandLine();
  v14 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v13 + 28))(a1: v13, a2: "-refresh", a3: v12);
  v15 = _CommandLine();
  config.m_VideoMode.m_RefreshRate = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 28))(
                                       a1: v15,
                                       a2: "-refreshrate",
                                       a3: v14);
  if ( bWindowed )
    config.m_Flags |= 1u;
  else
    config.m_Flags &= ~1u;
  if ( bNoWindowBorder )
    config.m_Flags |= 0x20000u;
  else
    config.m_Flags &= ~0x20000u;
  if ( this->m_bSetModeOnce )
  {
    OverrideMaterialSystemConfig(&config);
    return 1;
  }
  else
  {
    v16 = materials->__vftable;
    v17 = ((int (__thiscall *)(IGame *, MaterialSystem_Config_t *))game->GetMainWindow)(a1: game, a2: &config);
    result = ((int (__thiscall *)(IMaterialSystem *, int))v16->SetMode)(a1: materials, a2: v17);
    if ( result != 0 )
    {
      this->m_bSetModeOnce = true;
      CColorBalanceUIPanel::Init(this: v19);
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EAAD0
// Name: public: virtual void CVideoMode_MaterialSystem::SetGameWindow(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_MaterialSystem::SetGameWindow(CVideoMode_MaterialSystem *this, void *hWnd)
{
  int m_Height; // ecx
  IMaterialSystem_vtbl *v4; // esi
  void *v5; // eax
  MaterialVideoMode_t mode; // [esp+4h] [ebp-10h] BYREF

  if ( hWnd != nullptr )
  {
    game->SetGameWindow(this: game, a2: hWnd);
    materials->GetDisplayMode(this: materials, a2: &mode);
    m_Height = mode.m_Height;
    this->m_nModeWidth = mode.m_Width;
    this->m_nModeHeight = m_Height;
    *(_WORD *)&this->m_bWindowed = 1;
    v4 = materials->__vftable;
    v5 = game->GetMainWindow(this: game);
    v4->SetView(this: materials, a2: v5);
  }
  else
  {
    materials->SetView(this: materials, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EAB60
// Name: public: virtual void CVideoMode_MaterialSystem::ReleaseVideo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_MaterialSystem::ReleaseVideo(CVideoMode_MaterialSystem *this)
{
  if ( !this->IsWindowedMode(this) )
    this->ReleaseFullScreen(this);
}

//------------------------------------------------------------------------------
// Address: 0x101EAB80
// Name: private: virtual void CVideoMode_MaterialSystem::ReleaseFullScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_MaterialSystem::ReleaseFullScreen(CVideoMode_MaterialSystem *this)
{
  HWND v1; // eax

  if ( !this->IsWindowedMode(this) )
  {
    ChangeDisplaySettingsA(lpDevMode: nullptr, dwFlags: 0);
    v1 = (HWND)game->GetMainWindow(this: game);
    ShowWindow(hWnd: v1, nCmdShow: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EABB0
// Name: private: virtual void CVideoMode_MaterialSystem::ChangeDisplaySettingsToFullscreen(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_MaterialSystem::ChangeDisplaySettingsToFullscreen(
        CVideoMode_MaterialSystem *this,
        unsigned int nWidth,
        unsigned int nHeight,
        unsigned int nBPP)
{
  _devicemodeA dm; // [esp+0h] [ebp-9Ch] BYREF

  if ( !this->IsWindowedMode(this) )
  {
    memset(dst: dm.dmDeviceName, value: 0, count: sizeof(dm));
    dm.dmSize = 156;
    dm.dmPelsWidth = nWidth;
    dm.dmPelsHeight = nHeight;
    dm.dmFields = 1835008;
    dm.dmBitsPerPel = nBPP;
    if ( g_pMaterialSystemConfig->m_VideoMode.m_RefreshRate >= 60 )
    {
      dm.dmDisplayFrequency = g_pMaterialSystemConfig->m_VideoMode.m_RefreshRate;
      dm.dmFields = 6029312;
    }
    ChangeDisplaySettingsA(lpDevMode: &dm, dwFlags: 4u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EAC30
// Name: void VideoMode_Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VideoMode_Destroy()
{
  if ( videomode != nullptr )
  {
    ((void (__thiscall *)(IVideoMode *, int))videomode->dtr_IVideoMode)(a1: videomode, a2: 1);
    videomode = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EAC50
// Name: public: CVideoMode_Common::CVideoMode_Common(void)
// Source: json
//------------------------------------------------------------------------------
CVideoMode_Common *__thiscall CVideoMode_Common::CVideoMode_Common(CVideoMode_Common *this)
{
  this->__vftable = (CVideoMode_Common_vtbl *)&CVideoMode_Common::`vftable';
  this->m_nNumModes = 0;
  this->m_bInitialized = false;
  this->m_nCustomModeList[0].width = 640;
  this->m_nCustomModeList[0].height = 480;
  this->m_nCustomModeList[0].bpp = 32;
  this->m_nCustomModeList[0].refreshRate = 0;
  this->m_nCustomModeList[1].width = -1;
  this->m_nCustomModeList[1].height = -1;
  this->m_nCustomModeList[1].bpp = 32;
  this->m_nCustomModeList[1].refreshRate = 0;
  this->m_bClientViewRectDirty = false;
  this->m_pBackgroundTexture = nullptr;
  this->m_pLoadingTexture = nullptr;
  this->m_bWindowed = false;
  this->m_nModeWidth = 1024;
  this->m_nModeHeight = 768;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EAD10
// Name: protected: void CVideoMode_Common::AdjustWindow(int,int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVideoMode_Common::AdjustWindow(
        CVideoMode_Common *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int nWidth,
        int nHeight,
        unsigned int nBPP,
        bool bWindowed,
        bool bNoWindowBorder)
{
  HWND v9; // eax
  LONG WindowLongA; // edi
  HWND v11; // eax
  int v12; // eax
  DWORD v13; // edi
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  int v18; // [esp-Ch] [ebp-20h]
  int v19; // [esp-8h] [ebp-1Ch]
  int v20; // [esp-8h] [ebp-1Ch]
  int v21; // [esp-4h] [ebp-18h]
  tagRECT WindowRect; // [esp+4h] [ebp-10h] BYREF
  LONG exStyle; // [esp+24h] [ebp+10h]

  if ( !g_bTextMode )
  {
    ((void (__thiscall *)(CVideoMode_Common *, int, int, unsigned int, int))this->ChangeDisplaySettingsToFullscreen)(
      a1: this,
      a2: nWidth,
      a3: nHeight,
      a4: nBPP,
      a5: a3);
    WindowRect.top = 0;
    WindowRect.left = 0;
    WindowRect.right = nWidth;
    WindowRect.bottom = nHeight;
    v9 = (HWND)((int (__thiscall *)(IGame *, int))game->GetMainWindow)(a1: game, a2: -16);
    WindowLongA = GetWindowLongA(hWnd: v9, nIndex: a2);
    v11 = (HWND)game->GetMainWindow(this: game);
    exStyle = GetWindowLongA(hWnd: v11, nIndex: -20);
    if ( bWindowed )
    {
      v12 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 40))(a1: v12, a2: "-noborder") != 0
        || bNoWindowBorder )
      {
        v13 = WindowLongA & 0xFF30FFFF;
      }
      else
      {
        v13 = WindowLongA | 0xCA0000;
      }
      exStyle &= ~8u;
      v14 = (HWND)game->GetMainWindow(this: game);
      SetWindowLongA(hWnd: v14, nIndex: -20, dwNewLong: exStyle);
    }
    else
    {
      v13 = WindowLongA & 0xFF30FFFF;
    }
    v15 = (HWND)game->GetMainWindow(this: game);
    SetWindowLongA(hWnd: v15, nIndex: -16, dwNewLong: v13);
    AdjustWindowRectEx(lpRect: &WindowRect, dwStyle: v13, bMenu: false, dwExStyle: exStyle);
    v19 = WindowRect.bottom - WindowRect.top;
    v18 = WindowRect.right - WindowRect.left;
    v16 = (HWND)game->GetMainWindow(this: game);
    SetWindowPos(hWnd: v16, hWndInsertAfter: (HWND)(!bWindowed - 2), X: 0, Y: 0, cx: v18, cy: v19, uFlags: 0x28u);
    v21 = WindowRect.bottom - WindowRect.top;
    v20 = WindowRect.right - WindowRect.left;
    v17 = (HWND)game->GetMainWindow(this: game);
    CVideoMode_Common::CenterEngineWindow(this, hWndCenter: v17, width: v20, height: v21);
    ((void (__thiscall *)(IGame *, int))game->SetWindowSize)(a1: game, a2: nWidth);
    this->UpdateWindowPosition(this);
    this->MarkClientViewRectDirty(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EAE90
// Name: public: virtual bool CVideoMode_Common::TakeSnapshotJPEGToBuffer(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVideoMode_Common::TakeSnapshotJPEGToBuffer(CVideoMode_Common *this, CUtlBuffer *buf, int quality)
{
  int v6; // edi
  int v7; // eax
  char *v8; // eax
  char *v9; // ebx
  int v10; // edi
  int v11; // eax
  CVideoMode_Common_vtbl *v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  jpeg_destination_mgr *dest; // eax
  unsigned int v17; // eax
  CVideoMode_Common_vtbl *v18; // edx
  unsigned int i; // eax
  jpeg_error_mgr jerr; // [esp+4h] [ebp-1F0h] BYREF
  jpeg_compress_struct cinfo; // [esp+88h] [ebp-16Ch] BYREF
  unsigned __int8 *row_pointer[1]; // [esp+1F0h] [ebp-4h] BYREF
  int qualitya; // [esp+200h] [ebp+Ch]

  if ( g_LostVideoMemory )
    return 0;
  if ( quality >= 1 )
  {
    qualitya = 100;
    if ( quality <= 100 )
      qualitya = quality;
  }
  else
  {
    qualitya = 1;
  }
  v6 = this->GetModeHeight(this);
  v7 = this->GetModeWidth(this);
  v8 = (char *)MemAlloc_Alloc(nSize: 3 * v7 * v6);
  v9 = v8;
  if ( v8 != nullptr )
  {
    v12 = this->__vftable;
    v13 = ((int (__thiscall *)(CVideoMode_Common *, char *, int))this->GetModeHeight)(a1: this, a2: v8, a3: 2);
    v14 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v13);
    ((void (__thiscall *)(CVideoMode_Common *, _DWORD, _DWORD, int))v12->ReadScreenPixels)(
      a1: this,
      a2: 0,
      a3: 0,
      a4: v14);
    v15 = 3 * this->GetModeWidth(this);
    cinfo.err = jpeg_std_error(err: &jerr);
    jpeg_CreateCompress(&cinfo, version: 62, structsize: 0x168u);
    dest = cinfo.dest;
    if ( cinfo.dest == nullptr )
    {
      dest = (jpeg_destination_mgr *)cinfo.mem->alloc_small(a1: (jpeg_common_struct *)&cinfo, a2: 0, a3: 28);
      cinfo.dest = dest;
    }
    dest[1].next_output_byte = (unsigned __int8 *)buf;
    dest->init_destination = init_destination;
    dest->empty_output_buffer = empty_output_buffer;
    dest->term_destination = term_destination;
    v17 = this->GetModeWidth(this);
    v18 = this->__vftable;
    cinfo.image_width = v17;
    cinfo.image_height = v18->GetModeHeight(this);
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;
    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality: qualitya, force_baseline: 1u);
    jpeg_start_compress(&cinfo, write_all_tables: 1u);
    for ( i = cinfo.next_scanline; cinfo.next_scanline < cinfo.image_height; i = cinfo.next_scanline )
    {
      row_pointer[0] = (unsigned __int8 *)&v9[v15 * i];
      jpeg_write_scanlines(&cinfo, scanlines: row_pointer, num_lines: 1u);
    }
    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);
    free(pMem: v9);
    return 1;
  }
  else
  {
    v10 = this->GetModeHeight(this);
    v11 = this->GetModeWidth(this);
    _Msg(a1: "Unable to allocate %i bytes for image\n", 3 * v11 * v10);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB090
// Name: public: virtual void CVideoMode_MaterialSystem::RestoreVideo(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVideoMode_MaterialSystem::RestoreVideo(
        CVideoMode_MaterialSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  HWND v4; // eax
  int v5; // eax
  int v6; // [esp-10h] [ebp-14h]
  bool v7; // [esp-8h] [ebp-Ch]
  bool v8; // [esp-4h] [ebp-8h]

  if ( !this->IsWindowedMode(this) )
  {
    v4 = (HWND)game->GetMainWindow(this: game);
    ShowWindow(hWnd: v4, nCmdShow: 1);
    v8 = this->NoWindowBorder(this);
    v7 = this->IsWindowedMode(this);
    v6 = this->GetModeHeight(this);
    v5 = this->GetModeWidth(this);
    CVideoMode_Common::AdjustWindow(
      this,
      a2,
      a3,
      nWidth: v5,
      nHeight: v6,
      nBPP: 0x20u,
      bWindowed: v7,
      bNoWindowBorder: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB0F0
// Name: void VideoMode_Create(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VideoMode_Create()
{
  CVideoMode_Common *v0; // eax
  IVideoMode *v1; // esi

  v0 = (CVideoMode_Common *)MemAlloc_Alloc(nSize: 0x2058u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CVideoMode_Common::CVideoMode_Common(this: v0);
    v1->__vftable = (IVideoMode_vtbl *)&CVideoMode_MaterialSystem::`vftable';
    videomode = v1;
  }
  else
  {
    videomode = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB130
// Name: public: virtual bool CVideoMode_Common::CreateGameWindow(int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVideoMode_Common::CreateGameWindow(
        CVideoMode_Common *this,
        int nWidth,
        int nHeight,
        bool bWindowed,
        bool bNoWindowBorder)
{
  int v7; // eax
  CVideoMode_Common_vtbl *v8; // ebx
  bool v9; // al
  unsigned __int8 v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // [esp-10h] [ebp-1Ch]
  bool v14; // [esp-8h] [ebp-14h]
  bool v15; // [esp-4h] [ebp-10h]

  _COM_TimestampedLog(a1: "CVideoMode_Common::Init  CreateGameWindow");
  if ( bWindowed && nWidth != 0 && nHeight != 0 )
  {
    this->m_nCustomModeList[1].width = nWidth;
    this->m_nCustomModeList[1].height = nHeight;
  }
  if ( g_pHammer == nullptr )
  {
    CVideoMode_Common::ResetCurrentModeForNewResolution(this, nWidth, nHeight, bWindowed, bNoWindowBorder);
    _COM_TimestampedLog(a1: "CreateGameWindow - Start");
    if ( !game->CreateGameWindow(this: game) )
      return 0;
    _COM_TimestampedLog(a1: "CreateGameWindow - Finish");
    v15 = this->NoWindowBorder(this);
    v14 = this->IsWindowedMode(this);
    v13 = this->GetModeHeight(this);
    v7 = this->GetModeWidth(this);
    CVideoMode_Common::AdjustWindow(this, nWidth: v7, nHeight: v13, nBPP: 32, bWindowed: v14, bNoWindowBorder: v15);
    _COM_TimestampedLog(a1: "SetMode - Start");
    v8 = this->__vftable;
    v9 = this->NoWindowBorder(this);
    v10 = ((int (__thiscall *)(CVideoMode_Common *, bool))this->IsWindowedMode)(a1: this, a2: v9);
    v11 = ((int (__thiscall *)(CVideoMode_Common *, _DWORD))this->GetModeHeight)(a1: this, a2: v10);
    v12 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v11);
    if ( ((unsigned __int8 (__thiscall *)(CVideoMode_Common *, int))v8->SetMode)(a1: this, a2: v12) == 0 )
      return 0;
    _COM_TimestampedLog(a1: "SetMode - Finish");
    CVideoMode_Common::DrawStartupVideo(this);
    _COM_TimestampedLog(a1: "DrawStartupGraphic - Start");
    this->DrawStartupGraphic(this);
    _COM_TimestampedLog(a1: "DrawStartupGraphic - Finish");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EB270
// Name: private: void CVideoMode_Common::RecomputeClientViewRect(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVideoMode_Common::RecomputeClientViewRect(CVideoMode_Common *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  int nHeight; // [esp+4h] [ebp-8h]
  int nWidth; // [esp+8h] [ebp-4h] BYREF

  if ( g_pHammer != nullptr || this->m_bClientViewRectDirty )
  {
    this->m_bClientViewRectDirty = false;
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, int *))(*(_DWORD *)v3 + 32))(a1: v3, a2: &nWidth);
    v4 = nWidth;
    this->m_ClientViewRect.width = nWidth;
    this->m_ClientViewRect.height = nHeight;
    this->m_ClientViewRect.x = 0;
    this->m_ClientViewRect.y = 0;
    if ( v4 == 0 || nHeight == 0 )
      this->m_bClientViewRectDirty = true;
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB320
// Name: private: void CVideoMode_Common::TakeSnapshotPFMRect(char const __near *,int,int,int,int,int,int,enum CubeMapFaceIndex_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVideoMode_Common::TakeSnapshotPFMRect(
        CVideoMode_Common *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        char *pFilename,
        int x,
        float *y,
        unsigned __int8 *w,
        int h,
        int resampleWidth,
        int resampleHeight,
        CubeMapFaceIndex_t faceIndex)
{
  const ImageFormatInfo_t *v12; // eax
  int v13; // edi
  int v14; // ebx
  const ImageFormatInfo_t *v15; // eax
  unsigned __int8 *v16; // eax
  IMaterialSystem_vtbl *v17; // edx
  int v18; // eax
  int v19; // esi
  int v20; // eax
  IMaterialSystem_vtbl *v21; // edx
  int v22; // eax
  int v23; // eax
  const ImageFormatInfo_t *v24; // eax
  unsigned __int8 *v25; // eax
  int v26; // edi
  int v27; // ebx
  ImageLoader::ResampleInfo_t v30; // [esp+24h] [ebp-64h] BYREF
  int v31; // [esp+78h] [ebp-10h]
  CVideoMode_Common *v32; // [esp+7Ch] [ebp-Ch]
  int v33; // [esp+80h] [ebp-8h] BYREF
  int v34; // [esp+84h] [ebp-4h] BYREF

  v32 = this;
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
  {
    v12 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA16161616F);
    v13 = (int)w;
    v14 = h;
    h = ((int (__thiscall *)(IMemAlloc *, int, int, int, int))_g_pMemAlloc->Alloc_2)(
          a1: _g_pMemAlloc,
          a2: h * (_DWORD)w * v12->m_nNumBytes,
          a3,
          a4,
          a5: a2);
    v15 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGB323232F);
    v16 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v14 * v13 * v15->m_nNumBytes);
    v17 = materials->__vftable;
    w = v16;
    v18 = (int)v17->GetRenderContext(this: materials);
    v19 = v18;
    if ( v18 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v18 + 8))(a1: v18);
    v20 = (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 28))(a1: v19);
    v21 = materials->__vftable;
    v31 = v20;
    v22 = (int)v21->FindTexture(this: materials, a2: "_rt_FullFrameFB", a3: "RenderTargets", a4: true, a5: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v19 + 24))(a1: v19, a2: v22);
    v32->ReadScreenPixels(this: v32, a2: x, a3: (int)y, a4: v13, a5: v14, a6: (void *)h, a7: IMAGE_FORMAT_RGBA16161616F);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v19 + 24))(a1: v19, a2: 0);
    (*(void (__thiscall **)(int, int *, int *))(*(_DWORD *)v19 + 32))(a1: v19, a2: &v33, a3: &v34);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int, int))(*(_DWORD *)v19 + 152))(
      a1: v19,
      a2: 0,
      a3: 0,
      a4: v33,
      a5: v34);
    GetCubemapOffset(faceIndex, x: (int *)&faceIndex, y: &x, faceDim: (int *)&y);
    v32 = (CVideoMode_Common *)(*(_DWORD *)v19 + 420);
    v23 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))materials->FindMaterial)(
            a1: materials,
            a2: "dev/copyfullframefb",
            a3: defaultValue,
            a4: 1,
            a5: 0,
            a6: faceIndex,
            a7: x,
            a8: y,
            a9: y,
            a10: 0.0,
            a11: 0.0,
            a12: (float)(v13 - 1),
            a13: (float)(v14 - 1),
            a14: v33,
            a15: v34,
            a16: 0,
            a17: 1,
            a18: 1);
    ((void (__thiscall *)(int, int))v32->__vftable)(a1: v19, a2: v23);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v19 + 24))(a1: v19, a2: v31);
    ImageLoader::ConvertImageFormat(
      src: (const unsigned __int8 *)h,
      srcImageFormat: IMAGE_FORMAT_RGBA16161616F,
      dst: w,
      dstImageFormat: IMAGE_FORMAT_RGB323232F,
      width: v13,
      height: v14,
      srcStride: 0,
      dstStride: 0);
    v24 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGB323232F);
    v25 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                               this: _g_pMemAlloc,
                               a2: resampleHeight * resampleWidth * v24->m_nNumBytes);
    v30.m_nSrcDepth = 1;
    v30.m_nDestDepth = 1;
    v30.m_nSrcWidth = v13;
    v26 = resampleWidth;
    v30.m_nSrcHeight = v14;
    v27 = resampleHeight;
    v30.m_flAlphaThreshhold = 0.40000001;
    v30.m_flAlphaHiFreqThreshhold = 0.40000001;
    y = (float *)v25;
    v30.m_nFlags = 0;
    v30.m_flColorScale[0] = 1.0;
    v30.m_flColorScale[1] = 1.0;
    v30.m_flColorScale[2] = 1.0;
    v30.m_flColorScale[3] = 1.0;
    memset(v30.m_flColorGoal, 0, sizeof(v30.m_flColorGoal));
    v30.m_pSrc = w;
    v30.m_pDest = v25;
    v30.m_nDestWidth = resampleWidth;
    v30.m_nDestHeight = resampleHeight;
    v30.m_flSrcGamma = 1.0;
    v30.m_flDestGamma = 1.0;
    if ( !ImageLoader::ResampleRGB323232F(info: &v30) )
      Sys_Error(error: "Can't resample\n");
    PFMWrite(pFloatImage: y, pFilename, width: v26, height: v27);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: w);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)h);
    ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
    (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 12))(a1: v19);
    (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 4))(a1: v19);
  }
  else
  {
    _Warning(a1: "Unable to take PFM screenshots if HDR isn't enabled!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB620
// Name: public: virtual void CVideoMode_MaterialSystem::AdjustForModeChange(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVideoMode_MaterialSystem::AdjustForModeChange(
        CVideoMode_MaterialSystem *this@<ecx>,
        char a2@<bl>,
        int a3@<edi>)
{
  char v4; // bl
  int v5; // eax
  int v6; // edi
  HWND v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  unsigned int v13; // [esp-8h] [ebp-24h]
  bool v14; // [esp-4h] [ebp-20h]
  bool v15; // [esp+0h] [ebp-1Ch]
  int nOldWidth; // [esp+4h] [ebp-18h]
  int nOldHeight; // [esp+8h] [ebp-14h]
  int nNewWidth; // [esp+Ch] [ebp-10h]
  int nNewHeight; // [esp+10h] [ebp-Ch]
  bool bNoWindowBorder; // [esp+18h] [ebp-4h]

  if ( g_pHammer == nullptr )
  {
    nOldWidth = ((int (__thiscall *)(CVideoMode_MaterialSystem *, int, char))this->GetModeWidth)(
                  a1: this,
                  a2: a3,
                  a3: a2);
    nOldHeight = this->GetModeHeight(this);
    nNewWidth = g_pMaterialSystemConfig->m_VideoMode.m_Width;
    nNewHeight = g_pMaterialSystemConfig->m_VideoMode.m_Height;
    bNoWindowBorder = (g_pMaterialSystemConfig->m_Flags & 0x20000) != 0;
    v4 = g_pMaterialSystemConfig->m_Flags & 1;
    v5 = ((int (*)(void))materials->GetRenderContext)();
    v6 = v5;
    if ( v5 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    if ( !this->IsWindowedMode(this) && v4 != 0 )
    {
      this->ReleaseFullScreen(this);
      v7 = (HWND)game->GetMainWindow(this: game);
      ShowWindow(hWnd: v7, nCmdShow: 1);
    }
    CVideoMode_Common::ResetCurrentModeForNewResolution(
      this,
      nWidth: nNewWidth,
      nHeight: nNewHeight,
      bWindowed: v4,
      bNoWindowBorder);
    v14 = this->NoWindowBorder(this);
    v13 = this->IsWindowedMode(this);
    v8 = this->GetModeHeight(this);
    v9 = ((int (__thiscall *)(CVideoMode_MaterialSystem *, int))this->GetModeWidth)(a1: this, a2: v8);
    CVideoMode_Common::AdjustWindow(
      this,
      a2: v4,
      a3: v6,
      nWidth: v9,
      nHeight: 32,
      nBPP: v13,
      bWindowed: v14,
      bNoWindowBorder: v15);
    this->MarkClientViewRectDirty(this);
    v10 = *(_DWORD *)v6;
    v11 = this->GetModeHeight(this);
    v12 = ((int (__thiscall *)(CVideoMode_MaterialSystem *, int))this->GetModeWidth)(a1: this, a2: v11);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int))(v10 + 152))(a1: v6, a2: 0, a3: 0, a4: v12);
    g_pVGuiSurface->OnScreenSizeChanged(this: g_pVGuiSurface, a2: nOldWidth, a3: nOldHeight);
    game->OnScreenSizeChanged(this: game, a2: nOldWidth, a3: nOldHeight);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB780
// Name: public: virtual void CVideoMode_MaterialSystem::ReadScreenPixels(int,int,int,int,void __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVideoMode_MaterialSystem::ReadScreenPixels(
        CVideoMode_MaterialSystem *this@<ecx>,
        int a2@<esi>,
        int x,
        int y,
        int w,
        int h,
        unsigned __int8 *pBuffer,
        ImageFormat format)
{
  int v8; // esi
  const ImageFormatInfo_t *v9; // eax
  unsigned int MemRequired; // eax
  Rect_t rect; // [esp+0h] [ebp-14h] BYREF
  bool bReadPixelsFromFrontBuffer; // [esp+13h] [ebp-1h]

  if ( g_LostVideoMemory )
  {
    MemRequired = ImageLoader::GetMemRequired(
                    width: w,
                    height: h,
                    depth: 1,
                    imageFormat: format,
                    mipmap: false,
                    pAdjustedHeight: nullptr);
    memset(dst: pBuffer, value: 0, count: MemRequired);
  }
  else
  {
    bReadPixelsFromFrontBuffer = g_pMaterialSystemHardwareConfig->ReadPixelsFromFrontBuffer(this: g_pMaterialSystemHardwareConfig);
    if ( bReadPixelsFromFrontBuffer )
      Shader_SwapBuffers();
    v8 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v8 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
    rect.x = x;
    rect.y = y;
    rect.width = w;
    rect.height = h;
    v9 = ImageLoader::ImageFormatInfo(fmt: format);
    (*(void (__thiscall **)(int, Rect_t *, Rect_t *, unsigned __int8 *, ImageFormat, int))(*(_DWORD *)v8 + 412))(
      a1: v8,
      a2: &rect,
      a3: &rect,
      a4: pBuffer,
      a5: format,
      a6: w * v9->m_nNumBytes);
    if ( bReadPixelsFromFrontBuffer )
      Shader_SwapBuffers();
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v8 + 12))(
      a1: v8,
      a2: rect.x,
      a3: rect.y,
      a4: rect.width,
      a5: rect.height);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB870
// Name: public: virtual struct vrect_t const __near & CVideoMode_Common::GetClientViewRect(void)const
// Source: json
//------------------------------------------------------------------------------
const vrect_t *__thiscall CVideoMode_Common::GetClientViewRect(CVideoMode_Common *this)
{
  CVideoMode_Common::RecomputeClientViewRect(this);
  return &this->m_ClientViewRect;
}

//------------------------------------------------------------------------------
// Address: 0x101EB880
// Name: public: virtual void CVideoMode_Common::TakeSnapshotTGA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::TakeSnapshotTGA(CVideoMode_Common *this, const char *pFilename)
{
  int v3; // edi
  int v4; // eax
  unsigned __int8 *v5; // eax
  CVideoMode_Common_vtbl *v6; // edi
  unsigned __int8 *v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // [esp-Ch] [ebp-48h]
  int v14; // [esp-8h] [ebp-44h]
  const char *v15; // [esp-4h] [ebp-40h]
  CUtlBuffer outBuf; // [esp+Ch] [ebp-30h] BYREF

  v3 = this->GetModeHeight(this);
  v4 = this->GetModeWidth(this);
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 3 * v4 * v3);
  v6 = this->__vftable;
  v7 = v5;
  v8 = ((int (__thiscall *)(CVideoMode_Common *, unsigned __int8 *, int))this->GetModeHeight)(a1: this, a2: v5, a3: 2);
  v9 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v8);
  ((void (__thiscall *)(CVideoMode_Common *, _DWORD, _DWORD, int))v6->ReadScreenPixels)(a1: this, a2: 0, a3: 0, a4: v9);
  CUtlBuffer::CUtlBuffer(this: &outBuf, growSize: 0, initSize: 0, nFlags: 0);
  v13 = this->GetModeHeight(this);
  v10 = this->GetModeWidth(this);
  if ( TGAWriter::WriteToBuffer(
         pImageData: v7,
         buffer: &outBuf,
         width: v10,
         height: v13,
         srcFormat: IMAGE_FORMAT_RGB888,
         dstFormat: IMAGE_FORMAT_RGB888) )
  {
    if ( g_pFileSystem->WriteFile(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr, a4: &outBuf) )
    {
      v11 = ((int (__thiscall *)(CVideoMode_Common *, const char *))this->GetModeHeight)(a1: this, a2: pFilename);
      v12 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v11);
      DevMsg(a1: "Screenshot: %dx%d saved to '%s'.\n", v12, v14, v15);
    }
    else
    {
      _Warning(a1: "Couldn't write bitmap data snapshot to file %s.\n", pFilename);
    }
  }
  free(pMem: v7);
  if ( outBuf.m_Memory.m_nGrowSize >= 0 && outBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101EB990
// Name: public: virtual void CVideoMode_Common::TakeSnapshotTGARect(char const __near *,int,int,int,int,int,int,bool,enum CubeMapFaceIndex_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::TakeSnapshotTGARect(
        CVideoMode_Common *this,
        const char *pFilename,
        int x,
        int y,
        int w,
        int h,
        int resampleWidth,
        int resampleHeight,
        bool bPFM,
        CubeMapFaceIndex_t faceIndex)
{
  unsigned __int8 *v10; // ebx
  CUtlBuffer outBuf; // [esp+0h] [ebp-88h] BYREF
  ImageLoader::ResampleInfo_t info; // [esp+30h] [ebp-58h] BYREF
  CVideoMode_Common *v13; // [esp+84h] [ebp-4h]
  unsigned __int8 *pImage1; // [esp+ACh] [ebp+24h]

  v13 = this;
  if ( bPFM )
  {
    CVideoMode_Common::TakeSnapshotPFMRect(this, pFilename, x, y, w, h, resampleWidth, resampleHeight, faceIndex);
  }
  else
  {
    v10 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 4 * h * w);
    pImage1 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 4 * resampleHeight * resampleWidth);
    v13->ReadScreenPixels(this: v13, a2: x, a3: y, a4: w, a5: h, a6: v10, a7: IMAGE_FORMAT_RGBA8888);
    info.m_nSrcDepth = 1;
    info.m_nDestDepth = 1;
    info.m_pDest = pImage1;
    info.m_flAlphaThreshhold = 0.40000001;
    info.m_flAlphaHiFreqThreshhold = 0.40000001;
    info.m_nFlags = 0;
    info.m_flColorScale[0] = 1.0;
    info.m_flColorScale[1] = 1.0;
    info.m_flColorScale[2] = 1.0;
    info.m_flColorScale[3] = 1.0;
    memset(info.m_flColorGoal, 0, sizeof(info.m_flColorGoal));
    info.m_pSrc = v10;
    info.m_nSrcWidth = w;
    info.m_nSrcHeight = h;
    info.m_nDestWidth = resampleWidth;
    info.m_nDestHeight = resampleHeight;
    info.m_flSrcGamma = 1.0;
    info.m_flDestGamma = 1.0;
    if ( !ImageLoader::ResampleRGBA8888(&info) )
      Sys_Error(error: "Can't resample\n");
    CUtlBuffer::CUtlBuffer(this: &outBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( TGAWriter::WriteToBuffer(
           pImageData: pImage1,
           buffer: &outBuf,
           width: resampleWidth,
           height: resampleHeight,
           srcFormat: IMAGE_FORMAT_RGBA8888,
           dstFormat: IMAGE_FORMAT_RGBA8888) )
    {
      if ( g_pFileSystem->WriteFile(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr, a4: &outBuf) )
        DevMsg(a1: "Screenshot: %dx%d saved to '%s'.\n", w, h, pFilename);
      else
        _Error(a1: "Couldn't write bitmap data snapshot to file %s.\n", pFilename);
    }
    free(pMem: pImage1);
    free(pMem: v10);
    materials->SwapBuffers(this: materials);
    if ( outBuf.m_Memory.m_nGrowSize >= 0 && outBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outBuf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBB80
// Name: VID_ProcessMovieFrame
// Source: json
//------------------------------------------------------------------------------
void __usercall VID_ProcessMovieFrame(
        const char *filename@<esi>,
        const MovieInfo_t *info,
        bool jpeg,
        int width,
        int height,
        unsigned __int8 *data)
{
  bool v6; // al
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t TraceType; // eax
  CUtlBuffer outBuf; // [esp+0h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &outBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( jpeg )
    v6 = videomode->TakeSnapshotJPEGToBuffer(this: videomode, a2: &outBuf, a3: info->jpeg_quality);
  else
    v6 = TGAWriter::WriteToBuffer(
           pImageData: data,
           buffer: &outBuf,
           width,
           height,
           srcFormat: IMAGE_FORMAT_BGR888,
           dstFormat: IMAGE_FORMAT_RGB888);
  if ( v6 && !g_pFileSystem->WriteFile(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: nullptr, a4: &outBuf) )
  {
    _Warning(a1: "Couldn't write movie snapshot to file %s.\n", filename);
    TraceType = CTraceFilter::GetTraceType(this: v7);
    Cbuf_AddText(eTarget: TraceType, pText: "endmovie\n", nTickDelay: 0);
  }
  if ( outBuf.m_Memory.m_nGrowSize >= 0 && outBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101EBC40
// Name: public: virtual void CVideoMode_Common::WriteMovieFrame(struct MovieInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVideoMode_Common::WriteMovieFrame(
        CVideoMode_Common *this@<ecx>,
        int a2@<esi>,
        const MovieInfo_t *info)
{
  ECommandTarget_t TraceType; // eax
  int v6; // esi
  int v7; // eax
  BGR888_t *v8; // esi
  int v9; // eax
  int v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // [esp-10h] [ebp-20h]
  int v14; // [esp-10h] [ebp-20h]
  int v15; // [esp-Ch] [ebp-1Ch]
  int v16; // [esp-Ch] [ebp-1Ch]
  CVideoMode_Common_vtbl *v17; // [esp+8h] [ebp-8h]
  int nMovieFrame; // [esp+18h] [ebp+8h]

  nMovieFrame = info->movieframe;
  if ( !g_LostVideoMemory )
  {
    if ( info->moviename[0] != 0 )
    {
      v6 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeHeight)(a1: this, a2);
      v7 = this->GetModeWidth(this);
      v8 = (BGR888_t *)MemAlloc_Alloc(nSize: (3 * (unsigned __int64)(unsigned int)(v6 * v7)) >> 32 != 0 ? -1 : 3 * v6 * v7);
      if ( v8 == nullptr )
        Sys_Error(error: "Couldn't allocate bitmap header to snapshot.\n");
      v17 = this->__vftable;
      v9 = ((int (__thiscall *)(CVideoMode_Common *, BGR888_t *))this->GetModeHeight)(a1: this, a2: v8);
      v10 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v9);
      ((void (__thiscall *)(CVideoMode_Common *, _DWORD, _DWORD, int))v17->ReadScreenPixels)(
        a1: this,
        a2: 0,
        a3: 0,
        a4: v10);
      if ( (info->type & 1) != 0 )
      {
        v15 = this->GetModeHeight(this);
        v13 = this->GetModeWidth(this);
        v11 = va(format: "%s%04d.tga", info->moviename, nMovieFrame);
        VID_ProcessMovieFrame(info, jpeg: false, filename: v11, width: v13, height: v15, data: &v8->b);
      }
      if ( (info->type & 0x10) != 0 )
      {
        v16 = this->GetModeHeight(this);
        v14 = this->GetModeWidth(this);
        v12 = va(format: "%s%04d.jpg", info->moviename, nMovieFrame);
        VID_ProcessMovieFrame(info, jpeg: true, filename: v12, width: v14, height: v16, data: &v8->b);
      }
      if ( (info->type & 2) != 0 )
        avi->AppendMovieFrame(this: avi, a2: g_hCurrentAVI, a3: v8);
      free(pMem: v8);
    }
    else
    {
      TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
      Cbuf_AddText(eTarget: TraceType, pText: "endmovie\n", nTickDelay: 0);
      ConMsg(a1: "Tried to write movie buffer with no filename set!\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBDC0
// Name: public: virtual void CVideoMode_Common::TakeSnapshotJPEG(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CVideoMode_Common::TakeSnapshotJPEG(CVideoMode_Common *this, const char *pFilename, int quality)
{
  int v4; // ebx
  void *v5; // edi
  int v6; // edi
  int v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp+4h] [ebp-C8h]
  int v13; // [esp+8h] [ebp-C4h]
  const char *v14; // [esp+Ch] [ebp-C0h]
  char pDest[28]; // [esp+1Ch] [ebp-B0h] BYREF
  char orig[64]; // [esp+54h] [ebp-78h] BYREF
  _BYTE final_8[20]; // [esp+9Ch] [ebp-30h] OVERLAPPED BYREF

  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)final_8, growSize: 0, initSize: 0, nFlags: 0);
  this->TakeSnapshotJPEGToBuffer(this, a2: (CUtlBuffer *)final_8, a3: quality);
  v4 = 0;
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename, a3: "wb", a4: 0);
  if ( v5 != nullptr )
  {
    g_pFileSystem->Write(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: *(const void **)final_8,
      a3: *(_DWORD *)&final_8[16],
      a4: v5);
    v4 = g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
  }
  v6 = this->GetModeHeight(this);
  v7 = this->GetModeWidth(this);
  v8 = V_pretifymem(value: (float)(3 * v7 * v6), digitsafterdecimal: 2, usebinaryonek: false);
  V_strncpy(pDest, pSrc: v8, maxLen: 64);
  v9 = V_pretifymem(value: (float)v4, digitsafterdecimal: 2, usebinaryonek: false);
  V_strncpy(pDest: &orig[8], pSrc: v9, maxLen: 64);
  v10 = ((int (__thiscall *)(CVideoMode_Common *, int, char *))this->GetModeHeight)(a1: this, a2: quality, a3: &orig[8]);
  v11 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v10);
  _Msg(a1: "Wrote '%s':  %s (%dx%d) compresssed (quality %i) to %s\n", pFilename, pDest, v11, v12, v13, v14);
  if ( *(int *)&final_8[8] >= 0 && *(_DWORD *)final_8 != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)final_8);
}

//------------------------------------------------------------------------------
// Address: 0x101EBF20
// Name: private: bool CVideoMode_Common::SetupStartupGraphic(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVideoMode_Common::SetupStartupGraphic(CVideoMode_Common *this)
{
  IVTFTexture *v2; // eax
  IVTFTexture *v4; // eax
  char pOutBuffer[260]; // [esp+8h] [ebp-238h] BYREF
  char startupName[260]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer buf; // [esp+210h] [ebp-30h] BYREF

  _COM_TimestampedLog(a1: "CVideoMode_Common::Init  SetupStartupGraphic");
  CL_GetStartupImage(pOutBuffer, nOutBufferSize: 260);
  V_snprintf(pDest: startupName, maxLen: 260, pFormat: "materials/%s.vtf", pOutBuffer);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  v2 = CVideoMode_Common::LoadVTF(this, temp: &buf, szFileName: startupName);
  this->m_pBackgroundTexture = v2;
  if ( v2 != nullptr )
  {
    memset(&buf.m_Get, 0, 9);
    buf.m_nOffset = 0;
    buf.m_nMaxPut = -1;
    CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
    v4 = CVideoMode_Common::LoadVTF(this, temp: &buf, szFileName: "materials/console/startup_loading.vtf");
    this->m_pLoadingTexture = v4;
    if ( v4 != nullptr )
    {
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 1;
    }
    else
    {
      _Error(a1: "Can't find background image %s\n", "materials/console/startup_loading.vtf");
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    _Error(a1: "Can't find background image '%s'\n", startupName);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC060
// Name: public: virtual void CVideoMode_Common::DrawStartupGraphic(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVideoMode_Common::DrawStartupGraphic(CVideoMode_Common *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  CVideoMode_Common *v3; // edi
  int v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  KeyValues *v7; // eax
  KeyValues *v8; // ebx
  IMaterial *v9; // eax
  CVideoMode_Common_vtbl *v10; // edx
  int v11; // eax
  CVideoMode_Common_vtbl *v12; // edx
  int v13; // eax
  IVTFTexture *m_pBackgroundTexture; // ecx
  IVTFTexture_vtbl *v15; // edx
  int v16; // eax
  IVTFTexture *v17; // ecx
  IVTFTexture_vtbl *v18; // edx
  int v19; // eax
  IVTFTexture *m_pLoadingTexture; // ecx
  IVTFTexture_vtbl *v21; // edx
  int v22; // eax
  IVTFTexture *v23; // ecx
  IVTFTexture_vtbl *v24; // edx
  int v25; // ebx
  int v26; // eax
  void (__thiscall *v27)(int, int *); // edx
  int v28; // edi
  IMaterial *v29; // ebx
  void (__thiscall *v30)(int, int *); // edx
  int v31; // ecx
  int v32; // [esp-4h] [ebp-284h]
  float v33; // [esp+Ch] [ebp-274h]
  int v34; // [esp+14h] [ebp-26Ch]
  IVTFTexture *v35; // [esp+20h] [ebp-260h]
  char pDest[10]; // [esp+34h] [ebp-24Ch] BYREF
  char value[58]; // [esp+3Eh] [ebp-242h] BYREF
  char pStartupGraphicName[260]; // [esp+ACh] [ebp-1D4h] BYREF
  float v40; // [esp+23Ch] [ebp-44h]
  int v41; // [esp+240h] [ebp-40h]
  float v42; // [esp+244h] [ebp-3Ch]
  float v43; // [esp+248h] [ebp-38h]
  CVideoMode_Common *v44; // [esp+24Ch] [ebp-34h]
  float v45; // [esp+250h] [ebp-30h]
  int v46; // [esp+254h] [ebp-2Ch] BYREF
  int v47; // [esp+258h] [ebp-28h]
  int v48; // [esp+25Ch] [ebp-24h]
  IMaterial *v49; // [esp+260h] [ebp-20h]
  int nSrcTextureHeight; // [esp+264h] [ebp-1Ch]
  int v51; // [esp+268h] [ebp-18h]
  IMaterial *v52; // [esp+26Ch] [ebp-14h]
  int nSrcTextureWidth; // [esp+270h] [ebp-10h]
  int v54; // [esp+274h] [ebp-Ch]
  int nHeight; // [esp+278h] [ebp-8h]
  int nWidth; // [esp+27Ch] [ebp-4h]

  v3 = this;
  v44 = this;
  if ( CVideoMode_Common::SetupStartupGraphic(this) )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    CL_GetStartupImage(pOutBuffer: &pStartupGraphicName[140], nOutBufferSize: 260);
    V_snprintf(pDest, maxLen: 260, pFormat: "materials/%s.vtf", &pStartupGraphicName[140]);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "UnlitGeneric");
    else
      v6 = nullptr;
    KeyValues::SetString(this: v6, keyName: "$basetexture", value);
    KeyValues::SetInt(this: v6, keyName: "$ignorez", value: 1);
    KeyValues::SetInt(this: v6, keyName: "$nofog", value: 1);
    KeyValues::SetInt(this: v6, keyName: "$no_fullbright", value: 1);
    KeyValues::SetInt(this: v6, keyName: "$nocull", value: 1);
    v49 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int))g_pMaterialSystem->CreateMaterial)(
                         a1: g_pMaterialSystem,
                         a2: "__background",
                         a3: v6,
                         a4: a2);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "UnlitGeneric");
    else
      v8 = nullptr;
    KeyValues::SetString(this: v8, keyName: "$basetexture", value: "console/startup_loading.vtf");
    KeyValues::SetInt(this: v8, keyName: "$translucent", value: 1);
    KeyValues::SetInt(this: v8, keyName: "$ignorez", value: 1);
    KeyValues::SetInt(this: v8, keyName: "$nofog", value: 1);
    KeyValues::SetInt(this: v8, keyName: "$no_fullbright", value: 1);
    KeyValues::SetInt(this: v8, keyName: "$nocull", value: 1);
    v9 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "__loading", a3: v8);
    v10 = v3->__vftable;
    v52 = v9;
    v11 = v10->GetModeWidth(this: v3);
    v12 = v3->__vftable;
    nWidth = v11;
    v13 = v12->GetModeHeight(this: v3);
    m_pBackgroundTexture = v3->m_pBackgroundTexture;
    v15 = m_pBackgroundTexture->__vftable;
    nHeight = v13;
    v16 = v15->Width(this: m_pBackgroundTexture);
    v17 = v3->m_pBackgroundTexture;
    v18 = v17->__vftable;
    nSrcTextureWidth = v16;
    v19 = v18->Height(this: v17);
    m_pLoadingTexture = v3->m_pLoadingTexture;
    v21 = m_pLoadingTexture->__vftable;
    nSrcTextureHeight = v19;
    v22 = v21->Width(this: m_pLoadingTexture);
    v23 = v3->m_pLoadingTexture;
    v24 = v23->__vftable;
    v51 = v22;
    v25 = v24->Height(this: v23);
    v26 = _CommandLine();
    if ( (*(unsigned __int8 (__thiscall **)(int, const char *))(*(_DWORD *)v26 + 40))(
           a1: v26,
           a2: "-debugstartupscreen") != 0 )
    {
      v45 = (float)(nSrcTextureHeight - 1);
      v42 = (float)(nSrcTextureWidth - 1);
      v43 = (float)(v25 - 1);
      v54 = 0;
      v40 = (float)(v51 - 1);
      v41 = nWidth - v51;
      do
      {
        (*(void (__thiscall **)(int, _DWORD, _DWORD, int, int))(*(_DWORD *)v4 + 152))(
          a1: v4,
          a2: 0,
          a3: 0,
          a4: nWidth,
          a5: nHeight);
        (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 44))(a1: v4, a2: 0.0, a3: 1.0);
        (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 292))(
          a1: v4,
          a2: 0,
          a3: (unsigned __int8)(8 * (v54 & 7)),
          a4: 0);
        (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v4 + 48))(a1: v4, a2: 1, a3: 1, a4: 1);
        v27 = *(void (__thiscall **)(int, int *))(*(_DWORD *)v4 + 576);
        v46 = 1065353216;
        v47 = 1065353216;
        v48 = 1065353216;
        v27(a1: v4, a2: &v46);
        v28 = v54 % 200;
        if ( v54 % 200 > 100 )
          v28 = 200 - v28;
        DrawScreenSpaceRectangle(
          pMaterial: v49,
          nDestX: 0,
          nDestY: v28,
          nWidth,
          nHeight: nHeight - 50,
          flSrcTextureX0: 0.0,
          flSrcTextureY0: 0.0,
          flSrcTextureX1: v42,
          flSrcTextureY1: v45,
          nSrcTextureWidth,
          nSrcTextureHeight,
          pClientRenderable: nullptr,
          nXDice: 1,
          nYDice: 1,
          fDepth: 0.55000001);
        DrawScreenSpaceRectangle(
          pMaterial: v52,
          nDestX: v41,
          nDestY: nHeight + v28 / 2 - v25,
          nWidth: v51,
          nHeight: v25,
          flSrcTextureX0: 0.0,
          flSrcTextureY0: 0.0,
          flSrcTextureX1: v40,
          flSrcTextureY1: v43,
          nSrcTextureWidth: v51,
          nSrcTextureHeight: v25,
          pClientRenderable: nullptr,
          nXDice: 1,
          nYDice: 1,
          fDepth: 0.45000002);
        g_pMaterialSystem->SwapBuffers(this: g_pMaterialSystem);
        ++v54;
      }
      while ( v54 < 1000 );
      v3 = v44;
      v29 = v52;
    }
    else
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, int, int))(*(_DWORD *)v4 + 152))(
        a1: v4,
        a2: 0,
        a3: 0,
        a4: nWidth,
        a5: nHeight);
      (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 44))(a1: v4, a2: 0.0, a3: 1.0);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 292))(a1: v4, a2: 0, a3: 0, a4: 0);
      (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v4 + 48))(a1: v4, a2: 1, a3: 1, a4: 1);
      v30 = *(void (__thiscall **)(int, int *))(*(_DWORD *)v4 + 576);
      v46 = 1065353216;
      v47 = 1065353216;
      v48 = 1065353216;
      v30(a1: v4, a2: &v46);
      DrawScreenSpaceRectangle(
        pMaterial: v49,
        nDestX: 0,
        nDestY: 0,
        nWidth,
        nHeight,
        flSrcTextureX0: 0.0,
        flSrcTextureY0: 0.0,
        flSrcTextureX1: (float)(nSrcTextureWidth - 1),
        flSrcTextureY1: (float)(nSrcTextureHeight - 1),
        nSrcTextureWidth,
        nSrcTextureHeight,
        pClientRenderable: nullptr,
        nXDice: 1,
        nYDice: 1,
        fDepth: 0.5);
      v34 = v25;
      v33 = (float)(v25 - 1);
      v32 = v25;
      v31 = nHeight - v25;
      v29 = v52;
      DrawScreenSpaceRectangle(
        pMaterial: v52,
        nDestX: nWidth - v51,
        nDestY: v31,
        nWidth: v51,
        nHeight: v32,
        flSrcTextureX0: 0.0,
        flSrcTextureY0: 0.0,
        flSrcTextureX1: (float)(v51 - 1),
        flSrcTextureY1: v33,
        nSrcTextureWidth: v51,
        nSrcTextureHeight: v34,
        pClientRenderable: nullptr,
        nXDice: 1,
        nYDice: 1,
        fDepth: 0.5);
      g_pMaterialSystem->SwapBuffers(this: g_pMaterialSystem);
    }
    v49->DecrementReferenceCount(this: v49);
    v29->DecrementReferenceCount(this: v29);
    DestroyVTFTexture(pTexture: v3->m_pBackgroundTexture);
    v35 = v3->m_pLoadingTexture;
    v3->m_pBackgroundTexture = nullptr;
    DestroyVTFTexture(pTexture: v35);
    v3->m_pLoadingTexture = nullptr;
    if ( v4 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101EA230
// Name: PFMWrite
// Source: json
//------------------------------------------------------------------------------
void __usercall PFMWrite(const char *pFilename@<edx>, int height@<eax>, float *pFloatImage, int width)
{
  void *v5; // edi
  int v6; // esi
  float *v7; // ebx

  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename, a3: "wb", a4: 0);
  g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v5, a3: "PF\n%d %d\n-1.000000\n", width, height);
  v6 = height - 1;
  if ( v6 >= 0 )
  {
    v7 = &pFloatImage[3 * width * v6];
    do
    {
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v7, a3: 12 * width, a4: v5);
      v7 -= 3 * width;
      --v6;
    }
    while ( v6 >= 0 );
  }
  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101EA2E0
// Name: public: virtual bool CVideoMode_Common::IsWindowedMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVideoMode_Common::IsWindowedMode(CVideoMode_Common *this)
{
  return this->m_bWindowed;
}

//------------------------------------------------------------------------------
// Address: 0x101EA2F0
// Name: public: virtual bool CVideoMode_Common::NoWindowBorder(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVideoMode_Common::NoWindowBorder(CVideoMode_Common *this)
{
  return this->m_bNoWindowBorder;
}

//------------------------------------------------------------------------------
// Address: 0x101EA300
// Name: public: virtual int CVideoMode_Common::GetModeWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVideoMode_Common::GetModeWidth(CVideoMode_Common *this)
{
  return this->m_nModeWidth;
}

//------------------------------------------------------------------------------
// Address: 0x101EA310
// Name: public: virtual int CVideoMode_Common::GetModeHeight(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVideoMode_Common::GetModeHeight(CVideoMode_Common *this)
{
  return this->m_nModeHeight;
}

//------------------------------------------------------------------------------
// Address: 0x101EA320
// Name: public: virtual struct vmode_s __near * CVideoMode_Common::GetMode(int)
// Source: json
//------------------------------------------------------------------------------
vmode_s *__thiscall CVideoMode_Common::GetMode(CVideoMode_Common *this, int num)
{
  if ( num < 0 )
    return &this->m_rgModeList[-num + 511];
  if ( num < this->m_nNumModes )
    return &this->m_rgModeList[num];
  return this->m_nCustomModeList;
}

//------------------------------------------------------------------------------
// Address: 0x101EA360
// Name: VideoModeCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl VideoModeCompare(_DWORD *arg1, _DWORD *arg2)
{
  int v3; // eax
  int v4; // ecx

  if ( *arg1 < *arg2 )
    return -1;
  if ( *arg1 != *arg2 )
    return 1;
  v3 = arg1[1];
  v4 = arg2[1];
  if ( v3 < v4 )
    return -1;
  return v3 > v4;
}

//------------------------------------------------------------------------------
// Address: 0x101EA3A0
// Name: protected: int CVideoMode_Common::FindVideoMode(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVideoMode_Common::FindVideoMode(
        CVideoMode_Common *this,
        int nDesiredWidth,
        int nDesiredHeight,
        bool bWindowed)
{
  int result; // eax
  int m_nNumModes; // edx
  int v6; // esi
  int *p_height; // ecx

  if ( nDesiredWidth == this->m_nCustomModeList[0].width && nDesiredHeight == this->m_nCustomModeList[0].height )
    return -1;
  if ( bWindowed
    && nDesiredWidth == this->m_nCustomModeList[1].width
    && nDesiredHeight == this->m_nCustomModeList[1].height )
  {
    return -2;
  }
  m_nNumModes = this->m_nNumModes;
  v6 = -1;
  result = 0;
  if ( m_nNumModes > 0 )
  {
    p_height = &this->m_rgModeList[0].height;
    do
    {
      if ( *(p_height - 1) == nDesiredWidth )
      {
        v6 = result;
        if ( *p_height == nDesiredHeight )
          break;
      }
      ++result;
      p_height += 4;
    }
    while ( result < m_nNumModes );
  }
  if ( result >= m_nNumModes )
    return v6 != -1 ? v6 : 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EA520
// Name: protected: void CVideoMode_Common::DrawStartupVideo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::DrawStartupVideo(CVideoMode_Common *this)
{
  if ( !this->m_bPlayedStartupVideo && g_pHammer == nullptr )
  {
    game->PlayStartupVideos(this: game);
    this->m_bPlayedStartupVideo = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EA550
// Name: public: virtual void CVideoMode_Common::InvalidateWindow(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101EA590
// Name: public: virtual void CVideoMode_Common::DrawNullBackground(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::DrawNullBackground(CVideoMode_Common *this, HDC hHDC, int w, int h)
{
  int v4; // eax
  HFONT FontA; // ebx
  const char *v7; // eax
  tagRECT rc; // [esp+0h] [ebp-20h] BYREF
  HBRUSH__ *br; // [esp+10h] [ebp-10h]
  HFONT__ *oldFont; // [esp+14h] [ebp-Ch]
  int oldBkMode; // [esp+18h] [ebp-8h]
  HBRUSH__ *oldBr; // [esp+1Ch] [ebp-4h]
  unsigned int oldFgColor; // [esp+28h] [ebp+8h]

  v4 = _CommandLine(a1: rc.left);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-noshaderapi") != 0 )
  {
    FontA = CreateFontA(
              cHeight: -12,
              cWidth: 0,
              cEscapement: 0,
              cOrientation: 0,
              cWeight: 400,
              bItalic: 0,
              bUnderline: 0,
              bStrikeOut: 0,
              iCharSet: 0,
              iOutPrecision: 4u,
              iClipPrecision: 0,
              iQuality: 4u,
              iPitchAndFamily: 0,
              pszFaceName: "Arial");
    oldFont = (HFONT__ *)SelectObject(hdc: hHDC, h: FontA);
    oldBkMode = SetBkMode(hdc: hHDC, mode: 1);
    oldFgColor = SetTextColor(hdc: hHDC, color: 0xFFFFFFu);
    br = CreateSolidBrush(color: 0);
    oldBr = (HBRUSH__ *)SelectObject(hdc: hHDC, h: br);
    Rectangle(hdc: hHDC, left: 0, top: 0, right: w, bottom: h);
    rc.left = 0;
    rc.top = 0;
    rc.right = w;
    rc.bottom = h;
    DrawTextA(hdc: hHDC, lpchText: "Running with -noshaderapi", cchText: -1, lprc: &rc, format: 0x825u);
    rc.top = rc.bottom - 30;
    if ( host_state.worldmodel != nullptr )
    {
      rc.left += 10;
      v7 = modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
      DrawTextA(hdc: hHDC, lpchText: v7, cchText: -1, lprc: &rc, format: 0x824u);
    }
    SetTextColor(hdc: hHDC, color: oldFgColor);
    SelectObject(hdc: hHDC, h: oldBr);
    SetBkMode(hdc: hHDC, mode: oldBkMode);
    SelectObject(hdc: hHDC, h: oldFont);
    DeleteObject(ho: br);
    DeleteObject(ho: FontA);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EA6D0
// Name: public: virtual void CVideoMode_Common::UpdateWindowPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::UpdateWindowPosition(CVideoMode_Common *this)
{
  int x; // [esp+0h] [ebp-10h] BYREF
  int y; // [esp+4h] [ebp-Ch] BYREF
  int w; // [esp+8h] [ebp-8h] BYREF
  int h; // [esp+Ch] [ebp-4h] BYREF

  game->GetWindowRect(this: game, a2: &x, a3: &y, a4: &w, a5: &h);
}

//------------------------------------------------------------------------------
// Address: 0x101EA700
// Name: public: virtual void CVideoMode_Common::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::Shutdown(CVideoMode_Common *this)
{
  this->ReleaseFullScreen(this);
  game->DestroyGameWindow(this: game);
  if ( this->m_bInitialized )
    this->m_bInitialized = false;
}

//------------------------------------------------------------------------------
// Address: 0x101EA730
// Name: public: virtual void CVideoMode_Common::SetClientViewRect(struct vrect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::SetClientViewRect(CVideoMode_Common *this, const vrect_t *viewRect)
{
  this->m_ClientViewRect = *viewRect;
}

//------------------------------------------------------------------------------
// Address: 0x101EA780
// Name: private: void CVideoMode_Common::CenterEngineWindow(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::CenterEngineWindow(CVideoMode_Common *this, HWND hWndCenter, int width, int height)
{
  int SystemMetrics; // ecx
  int v5; // kr00_4
  int v6; // kr04_4
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // edi
  int v11; // [esp+0h] [ebp-18h]
  int v12; // [esp+0h] [ebp-18h]
  int refreshRate; // [esp+Ch] [ebp-Ch] BYREF
  int cyScreen; // [esp+10h] [ebp-8h] BYREF
  int cxScreen; // [esp+14h] [ebp-4h] BYREF

  cxScreen = 0;
  cyScreen = 0;
  refreshRate = 0;
  if ( (GetWindowLongA(hWnd: hWndCenter, nIndex: -20) & 8) == 0 )
    game->GetDesktopInfo(this: game, a2: &cxScreen, a3: &cyScreen, a4: &refreshRate);
  if ( cxScreen == 0 || (SystemMetrics = cyScreen, cyScreen == 0) )
  {
    cxScreen = GetSystemMetrics(nIndex: 0);
    SystemMetrics = GetSystemMetrics(nIndex: 1);
  }
  v5 = cxScreen - width;
  v6 = SystemMetrics - height;
  v7 = _CommandLine(a1: v11);
  v8 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v7 + 28))(
         a1: v7,
         a2: "-x",
         a3: v5 / 2 < 0 ? 0 : v5 / 2);
  v9 = _CommandLine(a1: v12);
  v10 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v9 + 28))(
          a1: v9,
          a2: "-y",
          a3: v6 / 2 < 0 ? 0 : v6 / 2);
  game->SetWindowXY(this: game, a2: v8, a3: v10);
  SetWindowPos(hWnd: hWndCenter, hWndInsertAfter: nullptr, X: v8, Y: v10, cx: 0, cy: 0, uFlags: 0x65u);
}

//------------------------------------------------------------------------------
// Address: 0x101EA860
// Name: private: virtual void CVideoMode_Common::ReadScreenPixels(int,int,int,int,void __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::ReadScreenPixels(
        CVideoMode_Common *this,
        int x,
        int y,
        int w,
        int h,
        unsigned __int8 *pBuffer,
        ImageFormat format)
{
  unsigned int MemRequired; // eax

  MemRequired = ImageLoader::GetMemRequired(
                  width: w,
                  height: h,
                  depth: 1,
                  imageFormat: format,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  memset(dst: pBuffer, value: 0, count: MemRequired);
}

//------------------------------------------------------------------------------
// Address: 0x101EA890
// Name: void GetCubemapOffset(enum CubeMapFaceIndex_t,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetCubemapOffset(CubeMapFaceIndex_t faceIndex, int *x, int *y, int *faceDim)
{
  int v4; // eax
  int fbHeight; // [esp+4h] [ebp-8h] BYREF
  int fbWidth; // [esp+8h] [ebp-4h] BYREF

  materials->GetBackBufferDimensions(this: materials, a2: &fbWidth, a3: &fbHeight);
  if ( 4 * fbWidth <= 3 * fbHeight )
    v4 = fbWidth / 4;
  else
    v4 = fbHeight / 3;
  *faceDim = v4;
  switch ( faceIndex )
  {
    case CUBEMAP_FACE_RIGHT:
      *x = 2;
      *y = 1;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
    case CUBEMAP_FACE_LEFT:
      *x = 0;
      *y = 1;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
    case CUBEMAP_FACE_BACK:
      *x = 1;
      *y = 1;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
    case CUBEMAP_FACE_FRONT:
      *x = 3;
      *y = 1;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
    case CUBEMAP_FACE_UP:
      *x = 2;
      *y = 0;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
    case CUBEMAP_FACE_DOWN:
      *x = 2;
      *y = 2;
      *x *= *faceDim;
      *y *= *faceDim;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EA9F0
// Name: init_destination
// Source: json
//------------------------------------------------------------------------------
void __cdecl init_destination(jpeg_common_struct *cinfo)
{
  jpeg_destination_mgr *err; // esi
  int v2; // eax

  err = (jpeg_destination_mgr *)cinfo[1].err;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 4096);
  err[1].free_in_buffer = v2;
  err->next_output_byte = (unsigned __int8 *)v2;
  err->free_in_buffer = 4096;
}

//------------------------------------------------------------------------------
// Address: 0x101EAA20
// Name: empty_output_buffer
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl empty_output_buffer(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // esi

  dest = cinfo->dest;
  CUtlBuffer::Put(this: (CUtlBuffer *)dest[1].next_output_byte, pMem: (const void *)dest[1].free_in_buffer, size: 4096);
  dest->next_output_byte = (unsigned __int8 *)dest[1].free_in_buffer;
  dest->free_in_buffer = 4096;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EAA50
// Name: term_destination
// Source: json
//------------------------------------------------------------------------------
void __cdecl term_destination(jpeg_compress_struct *cinfo)
{
  jpeg_destination_mgr *dest; // eax

  dest = cinfo->dest;
  if ( dest->free_in_buffer != 4096 )
    CUtlBuffer::Put(
      this: (CUtlBuffer *)dest[1].next_output_byte,
      pMem: (const void *)dest[1].free_in_buffer,
      size: 4096 - dest->free_in_buffer);
}

//------------------------------------------------------------------------------
// Address: 0x101EAA80
// Name: VideoMode_AdjustForModeChange
// Source: json
//------------------------------------------------------------------------------
int VideoMode_AdjustForModeChange()
{
  return ((int (__thiscall *)(IVideoMode *))videomode->__vftable[1].DrawStartupGraphic)(a1: videomode);
}

//------------------------------------------------------------------------------
// Address: 0x101EAA90
// Name: public: virtual bool CVideoMode_MaterialSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVideoMode_MaterialSystem::Init(CVideoMode_MaterialSystem *this)
{
  int v2; // eax
  int v3; // edi
  int (__thiscall *GetModeCount)(IMaterialSystem *, int); // eax
  int v5; // eax
  void (__thiscall *GetDesktopInfo)(IGame *, int *, int *, int *); // edx
  int v7; // ebx
  int m_nNumModes; // edx
  int v9; // eax
  int *p_height; // ecx
  signed int v11; // eax
  int *p_refreshRate; // ecx
  int v14; // [esp+0h] [ebp-30h]
  MaterialVideoMode_t info; // [esp+4h] [ebp-2Ch] BYREF
  int nDesktopWidth; // [esp+14h] [ebp-1Ch] BYREF
  int nDesktopHeight; // [esp+18h] [ebp-18h] BYREF
  int nModeCount; // [esp+1Ch] [ebp-14h]
  int nDesktopRefresh; // [esp+20h] [ebp-10h] BYREF
  int nAdapter; // [esp+24h] [ebp-Ch]
  int i; // [esp+28h] [ebp-8h]
  bool bAllowSmallModes; // [esp+2Fh] [ebp-1h]

  this->m_bSetModeOnce = false;
  this->m_bPlayedStartupVideo = false;
  v2 = _CommandLine(a1: v14);
  bAllowSmallModes = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-small") != 0;
  v3 = materials->GetCurrentAdapter(this: materials);
  GetModeCount = materials->GetModeCount;
  nAdapter = v3;
  v5 = GetModeCount(this: materials, a2: v3);
  GetDesktopInfo = game->GetDesktopInfo;
  v7 = v5;
  nModeCount = v5;
  GetDesktopInfo(this: game, a2: &nDesktopWidth, a3: &nDesktopHeight, a4: &nDesktopRefresh);
  i = 0;
  if ( v7 > 0 )
  {
    while ( 1 )
    {
      materials->GetModeInfo(this: materials, a2: v3, a3: i, a4: &info);
      if ( info.m_Width >= 640 && info.m_Height >= 480 || bAllowSmallModes )
      {
        m_nNumModes = this->m_nNumModes;
        v9 = 0;
        if ( m_nNumModes <= 0 )
        {
LABEL_12:
          this->m_rgModeList[m_nNumModes].width = info.m_Width;
          this->m_rgModeList[this->m_nNumModes].height = info.m_Height;
          this->m_rgModeList[this->m_nNumModes].bpp = 32;
          this->m_rgModeList[this->m_nNumModes++].refreshRate = info.m_RefreshRate;
          if ( this->m_nNumModes >= 512 )
            break;
        }
        else
        {
          p_height = &this->m_rgModeList[0].height;
          while ( info.m_Width != *(p_height - 1) || info.m_Height != *p_height )
          {
            ++v9;
            p_height += 4;
            if ( v9 >= m_nNumModes )
              goto LABEL_12;
          }
          if ( info.m_RefreshRate <= nDesktopRefresh )
          {
            p_refreshRate = &this->m_rgModeList[v9].refreshRate;
            if ( *p_refreshRate > nDesktopRefresh || *p_refreshRate < info.m_RefreshRate )
              *p_refreshRate = info.m_RefreshRate;
          }
        }
      }
      if ( ++i >= nModeCount )
        break;
      v3 = nAdapter;
    }
  }
  v11 = this->m_nNumModes;
  if ( v11 > 1 )
    qsort(
      base: this->m_rgModeList,
      num: v11,
      width: 0x10u,
      comp: (int (__cdecl *)(const void *, const void *))VideoModeCompare);
  materials->AddModeChangeCallBack(this: materials, a2: (void (__cdecl *)())VideoMode_AdjustForModeChange);
  this->m_bInitialized = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EAC20
// Name: public: virtual void CVideoMode_MaterialSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_MaterialSystem::Shutdown(CVideoMode_MaterialSystem *this)
{
  materials->RemoveModeChangeCallBack(this: materials, a2: (void (__cdecl *)())VideoMode_AdjustForModeChange);
  this->ReleaseFullScreen(this);
  game->DestroyGameWindow(this: game);
  if ( this->m_bInitialized )
    this->m_bInitialized = false;
}

//------------------------------------------------------------------------------
// Address: 0x101EAC60
// Name: public: virtual bool CVideoMode_MaterialSystem::SetMode(int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVideoMode_MaterialSystem::SetMode(
        CVideoMode_MaterialSystem *this,
        int nWidth,
        int nHeight,
        bool bWindowed,
        bool bNoWindowBorder)
{
  int v6; // esi
  vmode_s *v7; // eax
  int width; // edx
  int bpp; // ecx
  int refreshRate; // eax
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // edi
  int v15; // eax
  IMaterialSystem_vtbl *v16; // esi
  int v17; // eax
  char result; // al
  vgui::PropertyPage *v19; // ecx
  int v20; // [esp+0h] [ebp-80h]
  int v21; // [esp+0h] [ebp-80h]
  int v22; // [esp+0h] [ebp-80h]
  MaterialSystem_Config_t config; // [esp+Ch] [ebp-74h] BYREF
  vmode_s videoMode; // [esp+70h] [ebp-10h]

  S_ClearBuffer();
  v6 = CVideoMode_Common::FindVideoMode(this, nDesiredWidth: nWidth, nDesiredHeight: nHeight, bWindowed);
  v7 = this->GetMode(this, a2: v6);
  width = v7->width;
  videoMode.height = v7->height;
  bpp = v7->bpp;
  refreshRate = v7->refreshRate;
  videoMode.bpp = bpp;
  videoMode.refreshRate = refreshRate;
  if ( bWindowed && v6 == 0 && (width != nWidth || videoMode.height != nHeight) )
  {
    width = nWidth;
    videoMode.height = nHeight;
  }
  config = *g_pMaterialSystemConfig;
  config.m_VideoMode.m_Width = width;
  config.m_VideoMode.m_Height = videoMode.height;
  v11 = _CommandLine(a1: v20);
  v12 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v11 + 28))(
          a1: v11,
          a2: "-freq",
          a3: videoMode.refreshRate);
  v13 = _CommandLine(a1: v21);
  v14 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v13 + 28))(a1: v13, a2: "-refresh", a3: v12);
  v15 = _CommandLine(a1: v22);
  config.m_VideoMode.m_RefreshRate = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 28))(
                                       a1: v15,
                                       a2: "-refreshrate",
                                       a3: v14);
  if ( bWindowed )
    config.m_Flags |= 1u;
  else
    config.m_Flags &= ~1u;
  if ( bNoWindowBorder )
    config.m_Flags |= 0x20000u;
  else
    config.m_Flags &= ~0x20000u;
  if ( this->m_bSetModeOnce )
  {
    OverrideMaterialSystemConfig(&config);
    return 1;
  }
  else
  {
    v16 = materials->__vftable;
    v17 = ((int (__thiscall *)(IGame *, MaterialSystem_Config_t *))game->GetMainWindow)(a1: game, a2: &config);
    result = ((int (__thiscall *)(IMaterialSystem *, int))v16->SetMode)(a1: materials, a2: v17);
    if ( result != 0 )
    {
      this->m_bSetModeOnce = true;
      CColorBalanceUIPanel::Init(this: v19);
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EADB0
// Name: public: virtual void CVideoMode_MaterialSystem::SetGameWindow(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_MaterialSystem::SetGameWindow(CVideoMode_MaterialSystem *this, void *hWnd)
{
  int m_Height; // ecx
  IMaterialSystem_vtbl *v4; // esi
  void *v5; // eax
  MaterialVideoMode_t mode; // [esp+4h] [ebp-10h] BYREF

  if ( hWnd != nullptr )
  {
    game->SetGameWindow(this: game, a2: hWnd);
    materials->GetDisplayMode(this: materials, a2: &mode);
    m_Height = mode.m_Height;
    this->m_nModeWidth = mode.m_Width;
    this->m_nModeHeight = m_Height;
    *(_WORD *)&this->m_bWindowed = 1;
    v4 = materials->__vftable;
    v5 = game->GetMainWindow(this: game);
    v4->SetView(this: materials, a2: v5);
  }
  else
  {
    materials->SetView(this: materials, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EAE40
// Name: public: virtual void CVideoMode_MaterialSystem::ReleaseVideo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_MaterialSystem::ReleaseVideo(CVideoMode_MaterialSystem *this)
{
  if ( !this->IsWindowedMode(this) )
    this->ReleaseFullScreen(this);
}

//------------------------------------------------------------------------------
// Address: 0x101EAE60
// Name: private: virtual void CVideoMode_MaterialSystem::ReleaseFullScreen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_MaterialSystem::ReleaseFullScreen(CVideoMode_MaterialSystem *this)
{
  HWND v1; // eax

  if ( !this->IsWindowedMode(this) )
  {
    ChangeDisplaySettingsA(lpDevMode: nullptr, dwFlags: 0);
    v1 = (HWND)game->GetMainWindow(this: game);
    ShowWindow(hWnd: v1, nCmdShow: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EAF10
// Name: void VideoMode_Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VideoMode_Destroy()
{
  if ( videomode != nullptr )
  {
    ((void (__thiscall *)(IVideoMode *, int))videomode->dtr_IVideoMode)(a1: videomode, a2: 1);
    videomode = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EAF30
// Name: public: CVideoMode_Common::CVideoMode_Common(void)
// Source: json
//------------------------------------------------------------------------------
CVideoMode_Common *__thiscall CVideoMode_Common::CVideoMode_Common(CVideoMode_Common *this)
{
  this->__vftable = (CVideoMode_Common_vtbl *)&CVideoMode_Common::`vftable';
  this->m_nNumModes = 0;
  this->m_bInitialized = false;
  this->m_nCustomModeList[0].width = 640;
  this->m_nCustomModeList[0].height = 480;
  this->m_nCustomModeList[0].bpp = 32;
  this->m_nCustomModeList[0].refreshRate = 0;
  this->m_nCustomModeList[1].width = -1;
  this->m_nCustomModeList[1].height = -1;
  this->m_nCustomModeList[1].bpp = 32;
  this->m_nCustomModeList[1].refreshRate = 0;
  this->m_bClientViewRectDirty = false;
  this->m_pBackgroundTexture = nullptr;
  this->m_pLoadingTexture = nullptr;
  this->m_bWindowed = false;
  this->m_nModeWidth = 1024;
  this->m_nModeHeight = 768;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EAFF0
// Name: protected: void CVideoMode_Common::AdjustWindow(int,int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVideoMode_Common::AdjustWindow(
        CVideoMode_Common *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int nWidth,
        int nHeight,
        unsigned int nBPP,
        bool bWindowed,
        bool bNoWindowBorder)
{
  HWND v9; // eax
  LONG WindowLongA; // edi
  HWND v11; // eax
  int v12; // eax
  DWORD v13; // edi
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  int v18; // [esp-Ch] [ebp-20h]
  int v19; // [esp-8h] [ebp-1Ch]
  int v20; // [esp-8h] [ebp-1Ch]
  int v21; // [esp-4h] [ebp-18h]
  int v22; // [esp+0h] [ebp-14h]
  tagRECT WindowRect; // [esp+4h] [ebp-10h] BYREF
  LONG exStyle; // [esp+24h] [ebp+10h]

  if ( !g_bTextMode )
  {
    ((void (__thiscall *)(CVideoMode_Common *, int, int, unsigned int, int))this->ChangeDisplaySettingsToFullscreen)(
      a1: this,
      a2: nWidth,
      a3: nHeight,
      a4: nBPP,
      a5: a3);
    WindowRect.top = 0;
    WindowRect.left = 0;
    WindowRect.right = nWidth;
    WindowRect.bottom = nHeight;
    v9 = (HWND)((int (__thiscall *)(IGame *, int))game->GetMainWindow)(a1: game, a2: -16);
    WindowLongA = GetWindowLongA(hWnd: v9, nIndex: a2);
    v11 = (HWND)game->GetMainWindow(this: game);
    exStyle = GetWindowLongA(hWnd: v11, nIndex: -20);
    if ( bWindowed )
    {
      v12 = _CommandLine(a1: v22);
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 40))(a1: v12, a2: "-noborder") != 0
        || bNoWindowBorder )
      {
        v13 = WindowLongA & 0xFF30FFFF;
      }
      else
      {
        v13 = WindowLongA | 0xCA0000;
      }
      exStyle &= ~8u;
      v14 = (HWND)game->GetMainWindow(this: game);
      SetWindowLongA(hWnd: v14, nIndex: -20, dwNewLong: exStyle);
    }
    else
    {
      v13 = WindowLongA & 0xFF30FFFF;
    }
    v15 = (HWND)game->GetMainWindow(this: game);
    SetWindowLongA(hWnd: v15, nIndex: -16, dwNewLong: v13);
    AdjustWindowRectEx(lpRect: &WindowRect, dwStyle: v13, bMenu: false, dwExStyle: exStyle);
    v19 = WindowRect.bottom - WindowRect.top;
    v18 = WindowRect.right - WindowRect.left;
    v16 = (HWND)game->GetMainWindow(this: game);
    SetWindowPos(hWnd: v16, hWndInsertAfter: (HWND)(!bWindowed - 2), X: 0, Y: 0, cx: v18, cy: v19, uFlags: 0x28u);
    v21 = WindowRect.bottom - WindowRect.top;
    v20 = WindowRect.right - WindowRect.left;
    v17 = (HWND)game->GetMainWindow(this: game);
    CVideoMode_Common::CenterEngineWindow(this, hWndCenter: v17, width: v20, height: v21);
    ((void (__thiscall *)(IGame *, int))game->SetWindowSize)(a1: game, a2: nWidth);
    this->UpdateWindowPosition(this);
    this->MarkClientViewRectDirty(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB170
// Name: public: virtual bool CVideoMode_Common::TakeSnapshotJPEGToBuffer(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVideoMode_Common::TakeSnapshotJPEGToBuffer(CVideoMode_Common *this, CUtlBuffer *buf, int quality)
{
  int v6; // edi
  int v7; // eax
  char *v8; // eax
  char *v9; // ebx
  int v10; // edi
  int v11; // eax
  CVideoMode_Common_vtbl *v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  jpeg_destination_mgr *dest; // eax
  unsigned int v17; // eax
  CVideoMode_Common_vtbl *v18; // edx
  unsigned int i; // eax
  jpeg_error_mgr jerr; // [esp+4h] [ebp-1F0h] BYREF
  jpeg_compress_struct cinfo; // [esp+88h] [ebp-16Ch] BYREF
  unsigned __int8 *row_pointer[1]; // [esp+1F0h] [ebp-4h] BYREF
  int qualitya; // [esp+200h] [ebp+Ch]

  if ( g_LostVideoMemory )
    return 0;
  if ( quality >= 1 )
  {
    qualitya = 100;
    if ( quality <= 100 )
      qualitya = quality;
  }
  else
  {
    qualitya = 1;
  }
  v6 = this->GetModeHeight(this);
  v7 = this->GetModeWidth(this);
  v8 = (char *)MemAlloc_Alloc(nSize: 3 * v7 * v6);
  v9 = v8;
  if ( v8 != nullptr )
  {
    v12 = this->__vftable;
    v13 = ((int (__thiscall *)(CVideoMode_Common *, char *, int))this->GetModeHeight)(a1: this, a2: v8, a3: 2);
    v14 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v13);
    ((void (__thiscall *)(CVideoMode_Common *, _DWORD, _DWORD, int))v12->ReadScreenPixels)(
      a1: this,
      a2: 0,
      a3: 0,
      a4: v14);
    v15 = 3 * this->GetModeWidth(this);
    cinfo.err = jpeg_std_error(err: &jerr);
    jpeg_CreateCompress(&cinfo, version: 62, structsize: 0x168u);
    dest = cinfo.dest;
    if ( cinfo.dest == nullptr )
    {
      dest = (jpeg_destination_mgr *)cinfo.mem->alloc_small(a1: (jpeg_common_struct *)&cinfo, a2: 0, a3: 28);
      cinfo.dest = dest;
    }
    dest[1].next_output_byte = (unsigned __int8 *)buf;
    dest->init_destination = (void (__cdecl *)(jpeg_compress_struct *))init_destination;
    dest->empty_output_buffer = empty_output_buffer;
    dest->term_destination = term_destination;
    v17 = this->GetModeWidth(this);
    v18 = this->__vftable;
    cinfo.image_width = v17;
    cinfo.image_height = v18->GetModeHeight(this);
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;
    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality: qualitya, force_baseline: 1u);
    jpeg_start_compress(&cinfo, write_all_tables: 1u);
    for ( i = cinfo.next_scanline; cinfo.next_scanline < cinfo.image_height; i = cinfo.next_scanline )
    {
      row_pointer[0] = (unsigned __int8 *)&v9[v15 * i];
      jpeg_write_scanlines(&cinfo, scanlines: row_pointer, num_lines: 1u);
    }
    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);
    free(pMem: v9);
    return 1;
  }
  else
  {
    v10 = this->GetModeHeight(this);
    v11 = this->GetModeWidth(this);
    _Msg(a1: "Unable to allocate %i bytes for image\n", 3 * v11 * v10);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB370
// Name: public: virtual void CVideoMode_MaterialSystem::RestoreVideo(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVideoMode_MaterialSystem::RestoreVideo(
        CVideoMode_MaterialSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  HWND v4; // eax
  int v5; // eax
  int v6; // [esp-10h] [ebp-14h]
  bool v7; // [esp-8h] [ebp-Ch]
  bool v8; // [esp-4h] [ebp-8h]

  if ( !this->IsWindowedMode(this) )
  {
    v4 = (HWND)game->GetMainWindow(this: game);
    ShowWindow(hWnd: v4, nCmdShow: 1);
    v8 = this->NoWindowBorder(this);
    v7 = this->IsWindowedMode(this);
    v6 = this->GetModeHeight(this);
    v5 = this->GetModeWidth(this);
    CVideoMode_Common::AdjustWindow(
      this,
      a2,
      a3,
      nWidth: v5,
      nHeight: v6,
      nBPP: 0x20u,
      bWindowed: v7,
      bNoWindowBorder: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB3D0
// Name: void VideoMode_Create(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VideoMode_Create()
{
  CVideoMode_Common *v0; // eax
  IVideoMode *v1; // esi

  v0 = (CVideoMode_Common *)MemAlloc_Alloc(nSize: 0x2058u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CVideoMode_Common::CVideoMode_Common(this: v0);
    v1->__vftable = (IVideoMode_vtbl *)&CVideoMode_MaterialSystem::`vftable';
    videomode = v1;
  }
  else
  {
    videomode = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB410
// Name: public: virtual bool CVideoMode_Common::CreateGameWindow(int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVideoMode_Common::CreateGameWindow(
        CVideoMode_Common *this,
        int nWidth,
        int nHeight,
        bool bWindowed,
        int bNoWindowBorder)
{
  int v7; // eax
  CVideoMode_Common_vtbl *v8; // ebx
  bool v9; // al
  unsigned __int8 v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // [esp-10h] [ebp-1Ch]
  bool v14; // [esp-8h] [ebp-14h]
  bool v15; // [esp-4h] [ebp-10h]

  _COM_TimestampedLog(a1: "CVideoMode_Common::Init  CreateGameWindow");
  if ( bWindowed && nWidth != 0 && nHeight != 0 )
  {
    this->m_nCustomModeList[1].width = nWidth;
    this->m_nCustomModeList[1].height = nHeight;
  }
  if ( g_pHammer == nullptr )
  {
    CVideoMode_Common::ResetCurrentModeForNewResolution(this, nWidth, nHeight, bWindowed, bNoWindowBorder);
    _COM_TimestampedLog(a1: "CreateGameWindow - Start");
    if ( !game->CreateGameWindow(this: game) )
      return 0;
    _COM_TimestampedLog(a1: "CreateGameWindow - Finish");
    v15 = this->NoWindowBorder(this);
    v14 = this->IsWindowedMode(this);
    v13 = this->GetModeHeight(this);
    v7 = this->GetModeWidth(this);
    CVideoMode_Common::AdjustWindow(
      this,
      a2: bNoWindowBorder,
      a3: (int)_COM_TimestampedLog,
      nWidth: v7,
      nHeight: v13,
      nBPP: 0x20u,
      bWindowed: v14,
      bNoWindowBorder: v15);
    _COM_TimestampedLog(a1: "SetMode - Start");
    v8 = this->__vftable;
    v9 = this->NoWindowBorder(this);
    v10 = ((int (__thiscall *)(CVideoMode_Common *, bool))this->IsWindowedMode)(a1: this, a2: v9);
    v11 = ((int (__thiscall *)(CVideoMode_Common *, _DWORD))this->GetModeHeight)(a1: this, a2: v10);
    v12 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v11);
    if ( ((unsigned __int8 (__thiscall *)(CVideoMode_Common *, int))v8->SetMode)(a1: this, a2: v12) == 0 )
      return 0;
    _COM_TimestampedLog(a1: "SetMode - Finish");
    CVideoMode_Common::DrawStartupVideo(this);
    _COM_TimestampedLog(a1: "DrawStartupGraphic - Start");
    this->DrawStartupGraphic(this);
    _COM_TimestampedLog(a1: "DrawStartupGraphic - Finish");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EB550
// Name: private: void CVideoMode_Common::RecomputeClientViewRect(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVideoMode_Common::RecomputeClientViewRect(CVideoMode_Common *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  int nHeight; // [esp+4h] [ebp-8h]
  int nWidth; // [esp+8h] [ebp-4h] BYREF

  if ( g_pHammer != nullptr || this->m_bClientViewRectDirty )
  {
    this->m_bClientViewRectDirty = false;
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, int *))(*(_DWORD *)v3 + 32))(a1: v3, a2: &nWidth);
    v4 = nWidth;
    this->m_ClientViewRect.width = nWidth;
    this->m_ClientViewRect.height = nHeight;
    this->m_ClientViewRect.x = 0;
    this->m_ClientViewRect.y = 0;
    if ( v4 == 0 || nHeight == 0 )
      this->m_bClientViewRectDirty = true;
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB600
// Name: private: void CVideoMode_Common::TakeSnapshotPFMRect(char const __near *,int,int,int,int,int,int,enum CubeMapFaceIndex_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVideoMode_Common::TakeSnapshotPFMRect(
        CVideoMode_Common *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        char *pFilename,
        int x,
        float *y,
        unsigned __int8 *w,
        int h,
        int resampleWidth,
        int resampleHeight,
        CubeMapFaceIndex_t faceIndex)
{
  const ImageFormatInfo_t *v12; // eax
  int v13; // edi
  int v14; // ebx
  const ImageFormatInfo_t *v15; // eax
  unsigned __int8 *v16; // eax
  IMaterialSystem_vtbl *v17; // edx
  int v18; // eax
  int v19; // esi
  int v20; // eax
  IMaterialSystem_vtbl *v21; // edx
  int v22; // eax
  int v23; // eax
  const ImageFormatInfo_t *v24; // eax
  unsigned __int8 *v25; // eax
  int v26; // edi
  int v27; // ebx
  ImageLoader::ResampleInfo_t v30; // [esp+24h] [ebp-64h] BYREF
  int v31; // [esp+78h] [ebp-10h]
  CVideoMode_Common *v32; // [esp+7Ch] [ebp-Ch]
  int v33; // [esp+80h] [ebp-8h] BYREF
  int v34; // [esp+84h] [ebp-4h] BYREF

  v32 = this;
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
  {
    v12 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA16161616F);
    v13 = (int)w;
    v14 = h;
    h = ((int (__thiscall *)(IMemAlloc *, int, int, int, int))_g_pMemAlloc->Alloc_2)(
          a1: _g_pMemAlloc,
          a2: h * (_DWORD)w * v12->m_nNumBytes,
          a3,
          a4,
          a5: a2);
    v15 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGB323232F);
    v16 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v14 * v13 * v15->m_nNumBytes);
    v17 = materials->__vftable;
    w = v16;
    v18 = (int)v17->GetRenderContext(this: materials);
    v19 = v18;
    if ( v18 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v18 + 8))(a1: v18);
    v20 = (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 28))(a1: v19);
    v21 = materials->__vftable;
    v31 = v20;
    v22 = (int)v21->FindTexture(this: materials, a2: "_rt_FullFrameFB", a3: "RenderTargets", a4: true, a5: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v19 + 24))(a1: v19, a2: v22);
    v32->ReadScreenPixels(this: v32, a2: x, a3: (int)y, a4: v13, a5: v14, a6: (void *)h, a7: IMAGE_FORMAT_RGBA16161616F);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v19 + 24))(a1: v19, a2: 0);
    (*(void (__thiscall **)(int, int *, int *))(*(_DWORD *)v19 + 32))(a1: v19, a2: &v33, a3: &v34);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int, int))(*(_DWORD *)v19 + 152))(
      a1: v19,
      a2: 0,
      a3: 0,
      a4: v33,
      a5: v34);
    GetCubemapOffset(faceIndex, x: (int *)&faceIndex, y: &x, faceDim: (int *)&y);
    v32 = (CVideoMode_Common *)(*(_DWORD *)v19 + 420);
    v23 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))materials->FindMaterial)(
            a1: materials,
            a2: "dev/copyfullframefb",
            a3: defaultValue,
            a4: 1,
            a5: 0,
            a6: faceIndex,
            a7: x,
            a8: y,
            a9: y,
            a10: 0.0,
            a11: 0.0,
            a12: (float)(v13 - 1),
            a13: (float)(v14 - 1),
            a14: v33,
            a15: v34,
            a16: 0,
            a17: 1,
            a18: 1);
    ((void (__thiscall *)(int, int))v32->__vftable)(a1: v19, a2: v23);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v19 + 24))(a1: v19, a2: v31);
    ImageLoader::ConvertImageFormat(
      src: (const unsigned __int8 *)h,
      srcImageFormat: IMAGE_FORMAT_RGBA16161616F,
      dst: w,
      dstImageFormat: IMAGE_FORMAT_RGB323232F,
      width: v13,
      height: v14,
      srcStride: 0,
      dstStride: 0);
    v24 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGB323232F);
    v25 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                               this: _g_pMemAlloc,
                               a2: resampleHeight * resampleWidth * v24->m_nNumBytes);
    v30.m_nSrcDepth = 1;
    v30.m_nDestDepth = 1;
    v30.m_nSrcWidth = v13;
    v26 = resampleWidth;
    v30.m_nSrcHeight = v14;
    v27 = resampleHeight;
    v30.m_flAlphaThreshhold = 0.40000001;
    v30.m_flAlphaHiFreqThreshhold = 0.40000001;
    y = (float *)v25;
    v30.m_nFlags = 0;
    v30.m_flColorScale[0] = 1.0;
    v30.m_flColorScale[1] = 1.0;
    v30.m_flColorScale[2] = 1.0;
    v30.m_flColorScale[3] = 1.0;
    memset(v30.m_flColorGoal, 0, sizeof(v30.m_flColorGoal));
    v30.m_pSrc = w;
    v30.m_pDest = v25;
    v30.m_nDestWidth = resampleWidth;
    v30.m_nDestHeight = resampleHeight;
    v30.m_flSrcGamma = 1.0;
    v30.m_flDestGamma = 1.0;
    if ( !ImageLoader::ResampleRGB323232F(info: &v30) )
      Sys_Error(error: "Can't resample\n");
    PFMWrite(pFilename, height: v27, pFloatImage: y, width: v26);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: w);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)h);
    ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
    (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 12))(a1: v19);
    (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 4))(a1: v19);
  }
  else
  {
    _Warning(a1: "Unable to take PFM screenshots if HDR isn't enabled!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB900
// Name: public: virtual void CVideoMode_MaterialSystem::AdjustForModeChange(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVideoMode_MaterialSystem::AdjustForModeChange(
        CVideoMode_MaterialSystem *this@<ecx>,
        char a2@<bl>,
        int a3@<edi>)
{
  char v4; // bl
  int v5; // eax
  int v6; // edi
  HWND v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  unsigned int v13; // [esp-8h] [ebp-24h]
  bool v14; // [esp-4h] [ebp-20h]
  bool v15; // [esp+0h] [ebp-1Ch]
  int nOldWidth; // [esp+4h] [ebp-18h]
  int nOldHeight; // [esp+8h] [ebp-14h]
  int nNewWidth; // [esp+Ch] [ebp-10h]
  int nNewHeight; // [esp+10h] [ebp-Ch]
  bool bNoWindowBorder; // [esp+18h] [ebp-4h]

  if ( g_pHammer == nullptr )
  {
    nOldWidth = ((int (__thiscall *)(CVideoMode_MaterialSystem *, int, char))this->GetModeWidth)(
                  a1: this,
                  a2: a3,
                  a3: a2);
    nOldHeight = this->GetModeHeight(this);
    nNewWidth = g_pMaterialSystemConfig->m_VideoMode.m_Width;
    nNewHeight = g_pMaterialSystemConfig->m_VideoMode.m_Height;
    bNoWindowBorder = (g_pMaterialSystemConfig->m_Flags & 0x20000) != 0;
    v4 = g_pMaterialSystemConfig->m_Flags & 1;
    v5 = ((int (*)(void))materials->GetRenderContext)();
    v6 = v5;
    if ( v5 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    if ( !this->IsWindowedMode(this) && v4 != 0 )
    {
      this->ReleaseFullScreen(this);
      v7 = (HWND)game->GetMainWindow(this: game);
      ShowWindow(hWnd: v7, nCmdShow: 1);
    }
    CVideoMode_Common::ResetCurrentModeForNewResolution(
      this,
      nWidth: nNewWidth,
      nHeight: nNewHeight,
      bWindowed: v4,
      bNoWindowBorder);
    v14 = this->NoWindowBorder(this);
    v13 = this->IsWindowedMode(this);
    v8 = this->GetModeHeight(this);
    v9 = ((int (__thiscall *)(CVideoMode_MaterialSystem *, int))this->GetModeWidth)(a1: this, a2: v8);
    CVideoMode_Common::AdjustWindow(
      this,
      a2: v4,
      a3: v6,
      nWidth: v9,
      nHeight: 32,
      nBPP: v13,
      bWindowed: v14,
      bNoWindowBorder: v15);
    this->MarkClientViewRectDirty(this);
    v10 = *(_DWORD *)v6;
    v11 = this->GetModeHeight(this);
    v12 = ((int (__thiscall *)(CVideoMode_MaterialSystem *, int))this->GetModeWidth)(a1: this, a2: v11);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int))(v10 + 152))(a1: v6, a2: 0, a3: 0, a4: v12);
    g_pVGuiSurface->OnScreenSizeChanged(this: g_pVGuiSurface, a2: nOldWidth, a3: nOldHeight);
    game->OnScreenSizeChanged(this: game, a2: nOldWidth, a3: nOldHeight);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBA60
// Name: public: virtual void CVideoMode_MaterialSystem::ReadScreenPixels(int,int,int,int,void __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVideoMode_MaterialSystem::ReadScreenPixels(
        CVideoMode_MaterialSystem *this@<ecx>,
        int a2@<esi>,
        int x,
        int y,
        int w,
        int h,
        unsigned __int8 *pBuffer,
        ImageFormat format)
{
  int v8; // esi
  const ImageFormatInfo_t *v9; // eax
  unsigned int MemRequired; // eax
  Rect_t rect; // [esp+0h] [ebp-14h] BYREF
  bool bReadPixelsFromFrontBuffer; // [esp+13h] [ebp-1h]

  if ( g_LostVideoMemory )
  {
    MemRequired = ImageLoader::GetMemRequired(
                    width: w,
                    height: h,
                    depth: 1,
                    imageFormat: format,
                    mipmap: false,
                    pAdjustedHeight: nullptr);
    memset(dst: pBuffer, value: 0, count: MemRequired);
  }
  else
  {
    bReadPixelsFromFrontBuffer = g_pMaterialSystemHardwareConfig->ReadPixelsFromFrontBuffer(this: g_pMaterialSystemHardwareConfig);
    if ( bReadPixelsFromFrontBuffer )
      Shader_SwapBuffers();
    v8 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v8 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
    rect.x = x;
    rect.y = y;
    rect.width = w;
    rect.height = h;
    v9 = ImageLoader::ImageFormatInfo(fmt: format);
    (*(void (__thiscall **)(int, Rect_t *, Rect_t *, unsigned __int8 *, ImageFormat, int))(*(_DWORD *)v8 + 412))(
      a1: v8,
      a2: &rect,
      a3: &rect,
      a4: pBuffer,
      a5: format,
      a6: w * v9->m_nNumBytes);
    if ( bReadPixelsFromFrontBuffer )
      Shader_SwapBuffers();
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)v8 + 12))(
      a1: v8,
      a2: rect.x,
      a3: rect.y,
      a4: rect.width,
      a5: rect.height);
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBB50
// Name: public: virtual struct vrect_t const __near & CVideoMode_Common::GetClientViewRect(void)const
// Source: json
//------------------------------------------------------------------------------
const vrect_t *__usercall CVideoMode_Common::GetClientViewRect@<eax>(CVideoMode_Common *this@<ecx>, int a2@<edi>)
{
  CVideoMode_Common::RecomputeClientViewRect(this, a2);
  return &this->m_ClientViewRect;
}

//------------------------------------------------------------------------------
// Address: 0x101EBB60
// Name: public: virtual void CVideoMode_Common::TakeSnapshotTGA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVideoMode_Common::TakeSnapshotTGA(CVideoMode_Common *this, const char *pFilename)
{
  int v3; // edi
  int v4; // eax
  unsigned __int8 *v5; // eax
  CVideoMode_Common_vtbl *v6; // edi
  unsigned __int8 *v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // [esp-Ch] [ebp-48h]
  int v14; // [esp-8h] [ebp-44h]
  const char *v15; // [esp-4h] [ebp-40h]
  CUtlBuffer outBuf; // [esp+Ch] [ebp-30h] BYREF

  v3 = this->GetModeHeight(this);
  v4 = this->GetModeWidth(this);
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 3 * v4 * v3);
  v6 = this->__vftable;
  v7 = v5;
  v8 = ((int (__thiscall *)(CVideoMode_Common *, unsigned __int8 *, int))this->GetModeHeight)(a1: this, a2: v5, a3: 2);
  v9 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v8);
  ((void (__thiscall *)(CVideoMode_Common *, _DWORD, _DWORD, int))v6->ReadScreenPixels)(a1: this, a2: 0, a3: 0, a4: v9);
  CUtlBuffer::CUtlBuffer(this: &outBuf, growSize: 0, initSize: 0, nFlags: 0);
  v13 = this->GetModeHeight(this);
  v10 = this->GetModeWidth(this);
  if ( TGAWriter::WriteToBuffer(
         pImageData: v7,
         buffer: &outBuf,
         width: v10,
         height: v13,
         srcFormat: IMAGE_FORMAT_RGB888,
         dstFormat: IMAGE_FORMAT_RGB888) )
  {
    if ( g_pFileSystem->WriteFile(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr, a4: &outBuf) )
    {
      v11 = ((int (__thiscall *)(CVideoMode_Common *, const char *))this->GetModeHeight)(a1: this, a2: pFilename);
      v12 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v11);
      DevMsg(a1: "Screenshot: %dx%d saved to '%s'.\n", v12, v14, v15);
    }
    else
    {
      _Warning(a1: "Couldn't write bitmap data snapshot to file %s.\n", pFilename);
    }
  }
  free(pMem: v7);
  if ( outBuf.m_Memory.m_nGrowSize >= 0 && outBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101EBC70
// Name: public: virtual void CVideoMode_Common::TakeSnapshotTGARect(char const __near *,int,int,int,int,int,int,bool,enum CubeMapFaceIndex_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVideoMode_Common::TakeSnapshotTGARect(
        CVideoMode_Common *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        char *pFilename,
        int x,
        float *y,
        int w,
        int h,
        int resampleWidth,
        int resampleHeight,
        bool bPFM,
        CubeMapFaceIndex_t faceIndex)
{
  unsigned __int8 *v13; // ebx
  CUtlBuffer outBuf; // [esp+0h] [ebp-88h] BYREF
  ImageLoader::ResampleInfo_t info; // [esp+30h] [ebp-58h] BYREF
  CVideoMode_Common *v16; // [esp+84h] [ebp-4h]
  unsigned __int8 *pImage1; // [esp+ACh] [ebp+24h]

  v16 = this;
  if ( bPFM )
  {
    CVideoMode_Common::TakeSnapshotPFMRect(
      this,
      a2,
      a3,
      a4,
      pFilename,
      x,
      y,
      (unsigned __int8 *)w,
      h,
      resampleWidth,
      resampleHeight,
      faceIndex);
  }
  else
  {
    v13 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 4 * h * w);
    pImage1 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 4 * resampleHeight * resampleWidth);
    v16->ReadScreenPixels(this: v16, a2: x, a3: (int)y, a4: w, a5: h, a6: v13, a7: IMAGE_FORMAT_RGBA8888);
    info.m_nSrcDepth = 1;
    info.m_nDestDepth = 1;
    info.m_pDest = pImage1;
    info.m_flAlphaThreshhold = 0.40000001;
    info.m_flAlphaHiFreqThreshhold = 0.40000001;
    info.m_nFlags = 0;
    info.m_flColorScale[0] = 1.0;
    info.m_flColorScale[1] = 1.0;
    info.m_flColorScale[2] = 1.0;
    info.m_flColorScale[3] = 1.0;
    memset(info.m_flColorGoal, 0, sizeof(info.m_flColorGoal));
    info.m_pSrc = v13;
    info.m_nSrcWidth = w;
    info.m_nSrcHeight = h;
    info.m_nDestWidth = resampleWidth;
    info.m_nDestHeight = resampleHeight;
    info.m_flSrcGamma = 1.0;
    info.m_flDestGamma = 1.0;
    if ( !ImageLoader::ResampleRGBA8888(&info) )
      Sys_Error(error: "Can't resample\n");
    CUtlBuffer::CUtlBuffer(this: &outBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( TGAWriter::WriteToBuffer(
           pImageData: pImage1,
           buffer: &outBuf,
           width: resampleWidth,
           height: resampleHeight,
           srcFormat: IMAGE_FORMAT_RGBA8888,
           dstFormat: IMAGE_FORMAT_RGBA8888) )
    {
      if ( g_pFileSystem->WriteFile(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr, a4: &outBuf) )
        DevMsg(a1: "Screenshot: %dx%d saved to '%s'.\n", w, h, pFilename);
      else
        _Error(a1: "Couldn't write bitmap data snapshot to file %s.\n", pFilename);
    }
    free(pMem: pImage1);
    free(pMem: v13);
    materials->SwapBuffers(this: materials);
    if ( outBuf.m_Memory.m_nGrowSize >= 0 && outBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outBuf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBE60
// Name: VID_ProcessMovieFrame
// Source: json
//------------------------------------------------------------------------------
void __usercall VID_ProcessMovieFrame(
        const char *filename@<esi>,
        const MovieInfo_t *info,
        bool jpeg,
        int width,
        int height,
        unsigned __int8 *data)
{
  bool v6; // al
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t TraceType; // eax
  CUtlBuffer outBuf; // [esp+0h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &outBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( jpeg )
    v6 = videomode->TakeSnapshotJPEGToBuffer(this: videomode, a2: &outBuf, a3: info->jpeg_quality);
  else
    v6 = TGAWriter::WriteToBuffer(
           pImageData: data,
           buffer: &outBuf,
           width,
           height,
           srcFormat: IMAGE_FORMAT_BGR888,
           dstFormat: IMAGE_FORMAT_RGB888);
  if ( v6 && !g_pFileSystem->WriteFile(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: nullptr, a4: &outBuf) )
  {
    _Warning(a1: "Couldn't write movie snapshot to file %s.\n", filename);
    TraceType = CTraceFilter::GetTraceType(this: v7);
    Cbuf_AddText(eTarget: TraceType, pText: "endmovie\n", nTickDelay: 0);
  }
  if ( outBuf.m_Memory.m_nGrowSize >= 0 && outBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101EC0A0
// Name: public: virtual void CVideoMode_Common::TakeSnapshotJPEG(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CVideoMode_Common::TakeSnapshotJPEG(CVideoMode_Common *this, const char *pFilename, int quality)
{
  int v4; // ebx
  void *v5; // edi
  int v6; // edi
  int v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp+4h] [ebp-C8h]
  int v13; // [esp+8h] [ebp-C4h]
  const char *v14; // [esp+Ch] [ebp-C0h]
  char pDest[28]; // [esp+1Ch] [ebp-B0h] BYREF
  char orig[64]; // [esp+54h] [ebp-78h] BYREF
  _BYTE final_8[20]; // [esp+9Ch] [ebp-30h] OVERLAPPED BYREF

  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)final_8, growSize: 0, initSize: 0, nFlags: 0);
  this->TakeSnapshotJPEGToBuffer(this, a2: (CUtlBuffer *)final_8, a3: quality);
  v4 = 0;
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename, a3: "wb", a4: 0);
  if ( v5 != nullptr )
  {
    g_pFileSystem->Write(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: *(const void **)final_8,
      a3: *(_DWORD *)&final_8[16],
      a4: v5);
    v4 = g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
  }
  v6 = this->GetModeHeight(this);
  v7 = this->GetModeWidth(this);
  v8 = V_pretifymem(value: (float)(3 * v7 * v6), digitsafterdecimal: 2, usebinaryonek: false);
  V_strncpy(pDest, pSrc: v8, maxLen: 64);
  v9 = V_pretifymem(value: (float)v4, digitsafterdecimal: 2, usebinaryonek: false);
  V_strncpy(pDest: &orig[8], pSrc: v9, maxLen: 64);
  v10 = ((int (__thiscall *)(CVideoMode_Common *, int, char *))this->GetModeHeight)(a1: this, a2: quality, a3: &orig[8]);
  v11 = ((int (__thiscall *)(CVideoMode_Common *, int))this->GetModeWidth)(a1: this, a2: v10);
  _Msg(a1: "Wrote '%s':  %s (%dx%d) compresssed (quality %i) to %s\n", pFilename, pDest, v11, v12, v13, v14);
  if ( *(int *)&final_8[8] >= 0 && *(_DWORD *)final_8 != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)final_8);
}

//------------------------------------------------------------------------------
// Address: 0x101EC200
// Name: private: bool CVideoMode_Common::SetupStartupGraphic(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVideoMode_Common::SetupStartupGraphic(CVideoMode_Common *this)
{
  IVTFTexture *v2; // eax
  IVTFTexture *v4; // eax
  char pOutBuffer[260]; // [esp+8h] [ebp-238h] BYREF
  char startupName[260]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer buf; // [esp+210h] [ebp-30h] BYREF

  _COM_TimestampedLog(a1: "CVideoMode_Common::Init  SetupStartupGraphic");
  CL_GetStartupImage(pOutBuffer, nOutBufferSize: 260);
  V_snprintf(pDest: startupName, maxLen: 260, pFormat: "materials/%s.vtf", pOutBuffer);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  v2 = CVideoMode_Common::LoadVTF(this, temp: &buf, szFileName: startupName);
  this->m_pBackgroundTexture = v2;
  if ( v2 != nullptr )
  {
    memset(&buf.m_Get, 0, 9);
    buf.m_nOffset = 0;
    buf.m_nMaxPut = -1;
    CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
    v4 = CVideoMode_Common::LoadVTF(this, temp: &buf, szFileName: "materials/console/startup_loading.vtf");
    this->m_pLoadingTexture = v4;
    if ( v4 != nullptr )
    {
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 1;
    }
    else
    {
      _Error(a1: "Can't find background image %s\n", "materials/console/startup_loading.vtf");
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    _Error(a1: "Can't find background image '%s'\n", startupName);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC340
// Name: public: virtual void CVideoMode_Common::DrawStartupGraphic(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVideoMode_Common::DrawStartupGraphic(CVideoMode_Common *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  CVideoMode_Common *v3; // edi
  int v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  KeyValues *v7; // eax
  KeyValues *v8; // ebx
  IMaterial *v9; // eax
  CVideoMode_Common_vtbl *v10; // edx
  int v11; // eax
  CVideoMode_Common_vtbl *v12; // edx
  int v13; // eax
  IVTFTexture *m_pBackgroundTexture; // ecx
  IVTFTexture_vtbl *v15; // edx
  int v16; // eax
  IVTFTexture *v17; // ecx
  IVTFTexture_vtbl *v18; // edx
  int v19; // eax
  IVTFTexture *m_pLoadingTexture; // ecx
  IVTFTexture_vtbl *v21; // edx
  int v22; // eax
  IVTFTexture *v23; // ecx
  IVTFTexture_vtbl *v24; // edx
  int v25; // ebx
  int v26; // eax
  void (__thiscall *v27)(int, int *); // edx
  int v28; // edi
  IMaterial *v29; // ebx
  void (__thiscall *v30)(int, int *); // edx
  int v31; // ecx
  int v32; // [esp-4h] [ebp-284h]
  float v33; // [esp+Ch] [ebp-274h]
  int v34; // [esp+14h] [ebp-26Ch]
  IVTFTexture *v35; // [esp+20h] [ebp-260h]
  char pDest[10]; // [esp+34h] [ebp-24Ch] BYREF
  char value[58]; // [esp+3Eh] [ebp-242h] BYREF
  char pStartupGraphicName[260]; // [esp+ACh] [ebp-1D4h] BYREF
  float v40; // [esp+23Ch] [ebp-44h]
  int v41; // [esp+240h] [ebp-40h]
  float v42; // [esp+244h] [ebp-3Ch]
  float v43; // [esp+248h] [ebp-38h]
  CVideoMode_Common *v44; // [esp+24Ch] [ebp-34h]
  float v45; // [esp+250h] [ebp-30h]
  int v46; // [esp+254h] [ebp-2Ch] BYREF
  int v47; // [esp+258h] [ebp-28h]
  int v48; // [esp+25Ch] [ebp-24h]
  IMaterial *v49; // [esp+260h] [ebp-20h]
  int nSrcTextureHeight; // [esp+264h] [ebp-1Ch]
  int v51; // [esp+268h] [ebp-18h]
  IMaterial *v52; // [esp+26Ch] [ebp-14h]
  int nSrcTextureWidth; // [esp+270h] [ebp-10h]
  int v54; // [esp+274h] [ebp-Ch]
  int nHeight; // [esp+278h] [ebp-8h]
  int nWidth; // [esp+27Ch] [ebp-4h]

  v3 = this;
  v44 = this;
  if ( CVideoMode_Common::SetupStartupGraphic(this) != 0 )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a3);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    CL_GetStartupImage(pOutBuffer: &pStartupGraphicName[140], nOutBufferSize: 260);
    V_snprintf(pDest, maxLen: 260, pFormat: "materials/%s.vtf", &pStartupGraphicName[140]);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "UnlitGeneric");
    else
      v6 = nullptr;
    KeyValues::SetString(this: v6, keyName: "$basetexture", value);
    KeyValues::SetInt(this: v6, keyName: "$ignorez", value: 1);
    KeyValues::SetInt(this: v6, keyName: "$nofog", value: 1);
    KeyValues::SetInt(this: v6, keyName: "$no_fullbright", value: 1);
    KeyValues::SetInt(this: v6, keyName: "$nocull", value: 1);
    v49 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, KeyValues *, int))g_pMaterialSystem->CreateMaterial)(
                         a1: g_pMaterialSystem,
                         a2: "__background",
                         a3: v6,
                         a4: a2);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "UnlitGeneric");
    else
      v8 = nullptr;
    KeyValues::SetString(this: v8, keyName: "$basetexture", value: "console/startup_loading.vtf");
    KeyValues::SetInt(this: v8, keyName: "$translucent", value: 1);
    KeyValues::SetInt(this: v8, keyName: "$ignorez", value: 1);
    KeyValues::SetInt(this: v8, keyName: "$nofog", value: 1);
    KeyValues::SetInt(this: v8, keyName: "$no_fullbright", value: 1);
    KeyValues::SetInt(this: v8, keyName: "$nocull", value: 1);
    v9 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *))g_pMaterialSystem->CreateMaterial)(a1: g_pMaterialSystem);
    v10 = v3->__vftable;
    v52 = v9;
    v11 = v10->GetModeWidth(this: v3);
    v12 = v3->__vftable;
    nWidth = v11;
    v13 = v12->GetModeHeight(this: v3);
    m_pBackgroundTexture = v3->m_pBackgroundTexture;
    v15 = m_pBackgroundTexture->__vftable;
    nHeight = v13;
    v16 = v15->Width(this: m_pBackgroundTexture);
    v17 = v3->m_pBackgroundTexture;
    v18 = v17->__vftable;
    nSrcTextureWidth = v16;
    v19 = v18->Height(this: v17);
    m_pLoadingTexture = v3->m_pLoadingTexture;
    v21 = m_pLoadingTexture->__vftable;
    nSrcTextureHeight = v19;
    v22 = v21->Width(this: m_pLoadingTexture);
    v23 = v3->m_pLoadingTexture;
    v24 = v23->__vftable;
    v51 = v22;
    v25 = v24->Height(this: v23);
    v26 = _CommandLine(a1: "__loading");
    if ( (*(unsigned __int8 (__thiscall **)(int, const char *))(*(_DWORD *)v26 + 40))(
           a1: v26,
           a2: "-debugstartupscreen") != 0 )
    {
      v45 = (float)(nSrcTextureHeight - 1);
      v42 = (float)(nSrcTextureWidth - 1);
      v43 = (float)(v25 - 1);
      v54 = 0;
      v40 = (float)(v51 - 1);
      v41 = nWidth - v51;
      do
      {
        (*(void (__thiscall **)(int, _DWORD, _DWORD, int, int))(*(_DWORD *)v4 + 152))(
          a1: v4,
          a2: 0,
          a3: 0,
          a4: nWidth,
          a5: nHeight);
        (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 44))(a1: v4, a2: 0.0, a3: 1.0);
        (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 292))(
          a1: v4,
          a2: 0,
          a3: (unsigned __int8)(8 * (v54 & 7)),
          a4: 0);
        (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v4 + 48))(a1: v4, a2: 1, a3: 1, a4: 1);
        v27 = *(void (__thiscall **)(int, int *))(*(_DWORD *)v4 + 576);
        v46 = 1065353216;
        v47 = 1065353216;
        v48 = 1065353216;
        v27(a1: v4, a2: &v46);
        v28 = v54 % 200;
        if ( v54 % 200 > 100 )
          v28 = 200 - v28;
        DrawScreenSpaceRectangle(
          pMaterial: v49,
          nDestX: 0,
          nDestY: v28,
          nWidth,
          nHeight: nHeight - 50,
          flSrcTextureX0: 0.0,
          flSrcTextureY0: 0.0,
          flSrcTextureX1: v42,
          flSrcTextureY1: v45,
          nSrcTextureWidth,
          nSrcTextureHeight,
          pClientRenderable: nullptr,
          nXDice: 1,
          nYDice: 1,
          fDepth: 0.55000001);
        DrawScreenSpaceRectangle(
          pMaterial: v52,
          nDestX: v41,
          nDestY: nHeight + v28 / 2 - v25,
          nWidth: v51,
          nHeight: v25,
          flSrcTextureX0: 0.0,
          flSrcTextureY0: 0.0,
          flSrcTextureX1: v40,
          flSrcTextureY1: v43,
          nSrcTextureWidth: v51,
          nSrcTextureHeight: v25,
          pClientRenderable: nullptr,
          nXDice: 1,
          nYDice: 1,
          fDepth: 0.45000002);
        g_pMaterialSystem->SwapBuffers(this: g_pMaterialSystem);
        ++v54;
      }
      while ( v54 < 1000 );
      v3 = v44;
      v29 = v52;
    }
    else
    {
      (*(void (__thiscall **)(int, _DWORD, _DWORD, int, int))(*(_DWORD *)v4 + 152))(
        a1: v4,
        a2: 0,
        a3: 0,
        a4: nWidth,
        a5: nHeight);
      (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 44))(a1: v4, a2: 0.0, a3: 1.0);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 292))(a1: v4, a2: 0, a3: 0, a4: 0);
      (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v4 + 48))(a1: v4, a2: 1, a3: 1, a4: 1);
      v30 = *(void (__thiscall **)(int, int *))(*(_DWORD *)v4 + 576);
      v46 = 1065353216;
      v47 = 1065353216;
      v48 = 1065353216;
      v30(a1: v4, a2: &v46);
      DrawScreenSpaceRectangle(
        pMaterial: v49,
        nDestX: 0,
        nDestY: 0,
        nWidth,
        nHeight,
        flSrcTextureX0: 0.0,
        flSrcTextureY0: 0.0,
        flSrcTextureX1: (float)(nSrcTextureWidth - 1),
        flSrcTextureY1: (float)(nSrcTextureHeight - 1),
        nSrcTextureWidth,
        nSrcTextureHeight,
        pClientRenderable: nullptr,
        nXDice: 1,
        nYDice: 1,
        fDepth: 0.5);
      v34 = v25;
      v33 = (float)(v25 - 1);
      v32 = v25;
      v31 = nHeight - v25;
      v29 = v52;
      DrawScreenSpaceRectangle(
        pMaterial: v52,
        nDestX: nWidth - v51,
        nDestY: v31,
        nWidth: v51,
        nHeight: v32,
        flSrcTextureX0: 0.0,
        flSrcTextureY0: 0.0,
        flSrcTextureX1: (float)(v51 - 1),
        flSrcTextureY1: v33,
        nSrcTextureWidth: v51,
        nSrcTextureHeight: v34,
        pClientRenderable: nullptr,
        nXDice: 1,
        nYDice: 1,
        fDepth: 0.5);
      g_pMaterialSystem->SwapBuffers(this: g_pMaterialSystem);
    }
    v49->DecrementReferenceCount(this: v49);
    v29->DecrementReferenceCount(this: v29);
    DestroyVTFTexture(pTexture: v3->m_pBackgroundTexture);
    v35 = v3->m_pLoadingTexture;
    v3->m_pBackgroundTexture = nullptr;
    DestroyVTFTexture(pTexture: v35);
    v3->m_pLoadingTexture = nullptr;
    if ( v4 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
    }
  }
}

} // namespace engine_xlsp
