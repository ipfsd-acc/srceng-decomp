// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: avi/avi.cpp
// Functions: 40
// ============================================================

#include "avi\avi.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: private: void CAviFile::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAviFile::Reset(CAviFile *this)
{
  _V_memset(dest: &this->m_wFormat, fill: 0, count: 18);
  _V_memset(dest: &this->m_bi, fill: 0, count: 44);
  this->m_bih = &this->m_bi.bmiHeader;
  this->m_bValid = false;
  this->m_nWidth = 0;
  this->m_nHeight = 0;
  this->m_pAVIFile = nullptr;
  this->m_nFrameRate = 0;
  this->m_pAudioStream = nullptr;
  this->m_pVideoStream = nullptr;
  this->m_pCompressedStream = nullptr;
  this->m_nFrame = 0;
  this->m_nSample = 0;
  this->m_memdc = nullptr;
  this->m_DIBSection = nullptr;
  this->m_nFrameScale = 1;
  this->m_bi.bmiHeader.biSize = 40;
  this->m_bih->biPlanes = 1;
  this->m_bih->biBitCount = 24;
  this->m_bih->biCompression = 0;
  this->m_bih->biXPelsPerMeter = 10000;
  this->m_bih->biYPelsPerMeter = 10000;
  this->m_bih->biClrUsed = 0;
  this->m_bih->biClrImportant = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100010A0
// Name: public: void CAviFile::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAviFile::Shutdown(CAviFile *this)
{
  if ( this->m_pAudioStream != nullptr )
  {
    AVIStreamRelease(pavi: this->m_pAudioStream);
    this->m_pAudioStream = nullptr;
  }
  if ( this->m_pVideoStream != nullptr )
  {
    AVIStreamRelease(pavi: this->m_pVideoStream);
    this->m_pVideoStream = nullptr;
  }
  if ( this->m_pCompressedStream != nullptr )
  {
    AVIStreamRelease(pavi: this->m_pCompressedStream);
    this->m_pCompressedStream = nullptr;
  }
  if ( this->m_pAVIFile != nullptr )
  {
    AVIFileRelease(pfile: this->m_pAVIFile);
    this->m_pAVIFile = nullptr;
  }
  if ( this->m_DIBSection != nullptr )
    DeleteObject(ho: this->m_DIBSection);
  if ( this->m_memdc != nullptr )
    DeleteDC(hdc: this->m_memdc);
  CAviFile::Reset(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001110
// Name: FormatAviMessage
// Source: json
//------------------------------------------------------------------------------
int __usercall FormatAviMessage@<eax>(HRESULT code@<eax>, char *buf, unsigned int len)
{
  char *v3; // esi
  int v4; // ebx
  unsigned int v5; // edi

  v3 = "unknown avi result code";
  if ( code > -2147205019 )
  {
    if ( code <= 0 )
    {
      if ( code != 0 )
      {
        switch ( code )
        {
          case -2147205018:
            v3 = "AVIERR_BADFORMAT: corrupt file or unrecognized format";
            break;
          case -2147205017:
            v3 = "AVIERR_MEMORY: insufficient memory";
            break;
          case -2147205016:
            v3 = "AVIERR_INTERNAL: internal error";
            break;
          case -2147205015:
            v3 = "AVIERR_BADFLAGS";
            break;
          case -2147205014:
            v3 = "AVIERR_BADPARAM";
            break;
          case -2147205013:
            v3 = "AVIERR_BADSIZE";
            break;
          case -2147205012:
            v3 = "AVIERR_BADHANDLE";
            break;
          case -2147205011:
            v3 = "AVIERR_FILEREAD: disk error while reading file";
            break;
          case -2147205010:
            v3 = "AVIERR_FILEWRITE: disk error while writing file";
            break;
          case -2147205009:
            v3 = "AVIERR_FILEOPEN: disk error while opening file";
            break;
          case -2147205008:
            v3 = "AVIERR_COMPRESSOR";
            break;
          case -2147205007:
            v3 = "AVIERR_NOCOMPRESSOR: a suitable compressor could not be found";
            break;
          case -2147205006:
            v3 = "AVIERR_READONLY: file is read-only";
            break;
          case -2147205005:
            v3 = "AVIERR_READONLY";
            break;
          case -2147205004:
            v3 = "AVIERR_BUFFERTOOSMALL";
            break;
          case -2147205003:
            v3 = "AVIERR_CANTCOMPRESS";
            break;
          case -2147204922:
            v3 = "AVIERR_USERABORT";
            break;
          case -2147204921:
            v3 = "AVIERR_ERROR";
            break;
          default:
            break;
        }
      }
      else
      {
        v3 = "Success";
      }
    }
  }
  else if ( code == -2147205019 )
  {
    v3 = "AVIERR_UNSUPPORTED: compression is not supported for this type of data";
  }
  else if ( code == -2147221164 )
  {
    v3 = "REGDB_E_CLASSNOTREG: file type not recognised";
  }
  v4 = _V_strlen(str: v3);
  if ( buf != nullptr && len != 0 )
  {
    v5 = v4;
    if ( v4 + 1 > len )
      v5 = len - 1;
    strncpy(dest: (unsigned __int8 *)buf, source: (unsigned __int8 *)v3, count: v5);
    buf[v5] = 0;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100012E0
// Name: ReportError
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReportError(HRESULT hr)
{
  char buf[512]; // [esp+0h] [ebp-200h] BYREF

  FormatAviMessage(code: hr, buf, len: 0x200u);
  _Warning(a1: "%s\n", buf);
}

//------------------------------------------------------------------------------
// Address: 0x10001320
// Name: private: void CAviFile::CreateVideoStreams(struct AVIParams_t const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAviFile::CreateVideoStreams(CAviFile *this, const AVIParams_t *params, HWND hWnd)
{
  unsigned int m_nFrameScale; // ecx
  int m_nWidth; // edx
  HRESULT v6; // eax
  HWND DesktopWindow; // eax
  HDC DC; // ebx
  HWND v9; // eax
  HBITMAP__ *v10; // eax
  HRESULT v11; // eax
  int m_nHeight; // [esp-4h] [ebp-324h]
  char buf[512]; // [esp+Ch] [ebp-314h] BYREF
  tagDIBSECTION dibs; // [esp+20Ch] [ebp-114h] BYREF
  _AVISTREAMINFOA streaminfo; // [esp+260h] [ebp-C0h] BYREF
  AVICOMPRESSOPTIONS compression; // [esp+2ECh] [ebp-34h] BYREF
  void *bits; // [esp+318h] [ebp-8h] BYREF
  AVICOMPRESSOPTIONS *aopts[1]; // [esp+31Ch] [ebp-4h] BYREF

  _V_memset(dest: &streaminfo, fill: 0, count: 140);
  m_nFrameScale = params->m_nFrameScale;
  streaminfo.dwRate = params->m_nFrameRate;
  m_nWidth = params->m_nWidth;
  streaminfo.dwScale = m_nFrameScale;
  m_nHeight = params->m_nHeight;
  streaminfo.fccType = 1935960438;
  streaminfo.fccHandler = 0;
  streaminfo.dwSuggestedBufferSize = 3 * m_nHeight * m_nWidth;
  SetRect(lprc: &streaminfo.rcFrame, xLeft: 0, yTop: 0, xRight: m_nWidth, yBottom: m_nHeight);
  v6 = AVIFileCreateStreamA(pfile: this->m_pAVIFile, ppavi: &this->m_pVideoStream, psi: &streaminfo);
  if ( v6 != 0 )
    goto LABEL_2;
  _V_memset(dest: &compression, fill: 0, count: 44);
  aopts[0] = &compression;
  _Warning(a1: "FIXME:  DIVX only for now\n");
  if ( params->m_bGetCodecFromUser )
  {
    if ( AVISaveOptions(hwnd: hWnd, uiFlags: 0, nStreams: 1, ppavi: &this->m_pVideoStream, plpOptions: aopts) == 0 )
    {
      this->m_bValid = false;
      return;
    }
    g_dwLastValidCodec = compression.fccHandler;
  }
  else
  {
    compression.fccHandler = g_dwLastValidCodec;
    if ( g_dwLastValidCodec == 0 )
      compression.fccHandler = 543320420;
  }
  v6 = AVIMakeCompressedStream(
         ppsCompressed: &this->m_pCompressedStream,
         ppsSource: this->m_pVideoStream,
         lpOptions: &compression,
         pclsidHandler: nullptr);
  if ( v6 != 0 )
  {
LABEL_2:
    this->m_bValid = false;
    FormatAviMessage(code: v6, buf, len: 0x200u);
    _Warning(a1: "%s\n", buf);
    return;
  }
  DesktopWindow = GetDesktopWindow();
  DC = GetDC(hWnd: DesktopWindow);
  this->m_memdc = CreateCompatibleDC(hdc: DC);
  v9 = GetDesktopWindow();
  ReleaseDC(hWnd: v9, hDC: DC);
  this->m_bih->biWidth = params->m_nWidth;
  this->m_bih->biHeight = params->m_nHeight;
  this->m_bih->biSizeImage = this->m_bih->biHeight
                           * ((this->m_bih->biWidth * this->m_bih->biBitCount / 8 + 3) & 0xFFFFFFFC);
  v10 = CreateDIBSection(
          hdc: this->m_memdc,
          pbmi: (const BITMAPINFO *)this->m_bih,
          usage: 0,
          ppvBits: &bits,
          hSection: nullptr,
          offset: 0);
  this->m_DIBSection = v10;
  GetObjectA(h: v10, c: 84, pv: &dibs);
  v11 = AVIStreamSetFormat(
          pavi: this->m_pCompressedStream,
          lPos: 0,
          lpFormat: &dibs.dsBmih,
          cbFormat: dibs.dsBmih.biSize + 4 * dibs.dsBmih.biClrUsed);
  if ( v11 != 0 )
  {
    this->m_bValid = false;
    ReportError(hr: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001570
// Name: private: void CAviFile::CreateAudioStream(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAviFile::CreateAudioStream(CAviFile *this)
{
  unsigned int nBlockAlign; // eax
  unsigned int v3; // ecx
  HRESULT v4; // eax
  IAVIFile *m_pAVIFile; // [esp-Ch] [ebp-2A0h]
  char buf[512]; // [esp+8h] [ebp-28Ch] BYREF
  _AVISTREAMINFOA audiostream; // [esp+208h] [ebp-8Ch] BYREF

  _V_memset(dest: &audiostream, fill: 0, count: 140);
  nBlockAlign = this->m_wFormat.nBlockAlign;
  v3 = nBlockAlign * this->m_wFormat.nSamplesPerSec;
  audiostream.dwScale = nBlockAlign;
  audiostream.dwSampleSize = nBlockAlign;
  m_pAVIFile = this->m_pAVIFile;
  audiostream.fccType = 1935963489;
  audiostream.dwRate = v3;
  audiostream.dwQuality = -1;
  v4 = AVIFileCreateStreamA(pfile: m_pAVIFile, ppavi: &this->m_pAudioStream, psi: &audiostream);
  if ( v4 != 0
    || (v4 = AVIStreamSetFormat(pavi: this->m_pAudioStream, lPos: 0, lpFormat: &this->m_wFormat, cbFormat: 18)) != 0 )
  {
    this->m_bValid = false;
    FormatAviMessage(code: v4, buf, len: 0x200u);
    _Warning(a1: "%s\n", buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001650
// Name: public: void CAviFile::AppendMovieSound(short __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAviFile::AppendMovieSound(CAviFile *this, __int16 *buf, unsigned int bufsize)
{
  HRESULT v4; // eax
  char v5[512]; // [esp+4h] [ebp-200h] BYREF

  if ( this->m_bValid )
  {
    v4 = AVIStreamWrite(
           pavi: this->m_pAudioStream,
           lStart: this->m_nSample,
           lSamples: bufsize >> 1,
           lpBuffer: buf,
           cbBuffer: bufsize,
           dwFlags: 0,
           plSampWritten: nullptr,
           plBytesWritten: nullptr);
    if ( v4 != 0 )
    {
      this->m_bValid = false;
      FormatAviMessage(code: v4, buf: v5, len: 0x200u);
      _Warning(a1: "%s\n", v5);
    }
    else
    {
      this->m_nSample += bufsize >> 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100016D0
// Name: public: void CAviFile::AppendMovieFrame(struct BGR888_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAviFile::AppendMovieFrame(CAviFile *this, const BGR888_t *pRGBData)
{
  void (__stdcall *v3)(HDC, HGDIOBJ); // ebx
  int v4; // edi
  int ObjectA; // eax
  HRESULT v7; // edi
  char buf[512]; // [esp+4h] [ebp-25Ch] BYREF
  tagDIBSECTION dibs; // [esp+204h] [ebp-5Ch] BYREF
  void *hOldObject; // [esp+258h] [ebp-8h]
  int scanlines; // [esp+25Ch] [ebp-4h]

  if ( this->m_bValid )
  {
    v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
    v4 = 0;
    hOldObject = SelectObject(hdc: this->m_memdc, h: this->m_DIBSection);
    scanlines = 0;
    if ( this->m_nHeight > 0 )
    {
      do
      {
        scanlines += SetDIBits(
                       hdc: this->m_memdc,
                       hbm: this->m_DIBSection,
                       start: this->m_nHeight - v4++ - 1,
                       cLines: 1u,
                       lpBits: pRGBData,
                       lpbmi: (const BITMAPINFO *)this->m_bih,
                       ColorUse: 0);
        pRGBData = (const BGR888_t *)((char *)pRGBData + 2 * this->m_nWidth + this->m_nWidth);
      }
      while ( v4 < this->m_nHeight );
      v3 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
    }
    ObjectA = GetObjectA(h: this->m_DIBSection, c: 84, pv: &dibs);
    if ( scanlines == this->m_nHeight && ObjectA == 84 )
    {
      v7 = AVIStreamWrite(
             pavi: this->m_pCompressedStream,
             lStart: this->m_nFrame,
             lSamples: 1,
             lpBuffer: dibs.dsBm.bmBits,
             cbBuffer: dibs.dsBmih.biSizeImage,
             dwFlags: 0x10u,
             plSampWritten: nullptr,
             plBytesWritten: nullptr);
      v3(hdc: this->m_memdc, h: hOldObject);
      if ( v7 != 0 )
      {
        this->m_bValid = false;
        FormatAviMessage(code: v7, buf, len: 0x200u);
        _Warning(a1: "%s\n", buf);
      }
      else
      {
        ++this->m_nFrame;
      }
    }
    else
    {
      v3(hdc: this->m_memdc, h: hOldObject);
      this->m_bValid = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100017E0
// Name: public: virtual class IVTFTexture __near * ITextureRegenerator::GetPreallocatedScratchTexture(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ITextureRegenerator::GetPreallocatedScratchTexture(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100017F0
// Name: public: void CAVIMaterial::GetTexCoordRange(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAVIMaterial::GetTexCoordRange(CAVIMaterial *this, float *pMaxU, float *pMaxV)
{
  ITexture *m_pTexture; // ecx
  int v5; // edi
  int v6; // eax
  float v7; // xmm0_4

  m_pTexture = this->m_Texture.m_pTexture;
  if ( m_pTexture != nullptr )
  {
    v5 = m_pTexture->GetActualWidth(this: m_pTexture);
    v6 = this->m_Texture.m_pTexture->GetActualHeight(this: this->m_Texture.m_pTexture);
    v7 = 0.0;
    if ( v5 != 0 )
      *pMaxU = (float)this->m_nAVIWidth / (float)v5;
    else
      *pMaxU = 0.0;
    if ( v6 != 0 )
      v7 = (float)this->m_nAVIHeight / (float)v6;
    *pMaxV = v7;
  }
  else
  {
    *pMaxV = 1.0;
    *pMaxU = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: private: void CAVIMaterial::CreateProceduralTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAVIMaterial::CreateProceduralTexture(CAVIMaterial *this, const char *pTextureName)
{
  int m_nAVIWidth; // eax
  int i; // ecx
  int m_nAVIHeight; // edx
  int j; // eax

  m_nAVIWidth = this->m_nAVIWidth;
  for ( i = 1; i < m_nAVIWidth; i *= 2 )
    ;
  m_nAVIHeight = this->m_nAVIHeight;
  for ( j = 1; j < m_nAVIHeight; j *= 2 )
    ;
  CTextureReference::InitProceduralTexture(
    this: &this->m_Texture,
    pTextureName,
    pTextureGroupName: "avi",
    w: i,
    h: j,
    fmt: IMAGE_FORMAT_RGBA8888,
    nFlags: 264460);
  this->m_Texture.m_pTexture->SetTextureRegenerator(this: this->m_Texture.m_pTexture, a2: this, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x100018F0
// Name: private: void CAVIMaterial::CreateProceduralMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAVIMaterial::CreateProceduralMaterial(CAVIMaterial *this, const char *pMaterialName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IBaseFileSystem *v5; // eax
  const char *v6; // eax
  char vmtfilename[512]; // [esp+Ch] [ebp-200h] BYREF

  _V_strcpy(dest: vmtfilename, src: pMaterialName);
  V_SetExtension(path: vmtfilename, extension: ".vmt", pathStringLength: 512);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "UnlitGeneric");
  else
    v4 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v4,
          filesystem: v5,
          resourceName: vmtfilename,
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr) )
  {
    v6 = this->m_Texture.m_pTexture->GetName(this: this->m_Texture.m_pTexture);
    KeyValues::SetString(this: v4, keyName: "$basetexture", value: v6);
    KeyValues::SetInt(this: v4, keyName: "$nofog", value: 1);
    KeyValues::SetInt(this: v4, keyName: "$spriteorientation", value: 3);
    KeyValues::SetInt(this: v4, keyName: "$translucent", value: 1);
  }
  CMaterialReference::Init(this: &this->m_Material, pMaterialName, pVMTKeyValues: v4);
  this->m_Material.m_pMaterial->Refresh(this: this->m_Material.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x100019D0
// Name: private: void CAVIMaterial::CreateVideoStream(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAVIMaterial::CreateVideoStream(CAVIMaterial *this)
{
  IAVIStream **p_m_pAVIStream; // ebx
  HRESULT Stream; // eax
  HWND DesktopWindow; // eax
  HDC DC; // edi
  HWND v6; // eax
  HBITMAP__ *v7; // eax
  char buf[512]; // [esp+8h] [ebp-258h] BYREF
  tagDIBSECTION dibs; // [esp+208h] [ebp-58h] BYREF
  void *bits; // [esp+25Ch] [ebp-4h] BYREF

  p_m_pAVIStream = &this->m_pAVIStream;
  Stream = AVIFileGetStream(pfile: this->m_pAVIFile, ppavi: &this->m_pAVIStream, fccType: 0x73646976u, lParam: 0);
  if ( Stream != 0 )
  {
    FormatAviMessage(code: Stream, buf, len: 0x200u);
    _Warning(a1: "%s\n", buf);
  }
  else
  {
    this->m_nCurrentSample = AVIStreamStart(pavi: *p_m_pAVIStream);
    DesktopWindow = GetDesktopWindow();
    DC = GetDC(hWnd: DesktopWindow);
    this->m_memdc = CreateCompatibleDC(hdc: DC);
    v6 = GetDesktopWindow();
    ReleaseDC(hWnd: v6, hDC: DC);
    this->m_bih = &this->m_bi.bmiHeader;
    this->m_bi.bmiHeader.biSize = 40;
    this->m_bih->biWidth = this->m_nAVIWidth;
    this->m_bih->biHeight = this->m_nAVIHeight;
    this->m_bih->biPlanes = 1;
    this->m_bih->biBitCount = 32;
    this->m_bih->biCompression = 0;
    this->m_bih->biSizeImage = this->m_bih->biHeight
                             * ((this->m_bih->biWidth * this->m_bih->biBitCount / 8 + 3) & 0xFFFFFFFC);
    this->m_bih->biXPelsPerMeter = 10000;
    this->m_bih->biYPelsPerMeter = 10000;
    this->m_bih->biClrUsed = 0;
    this->m_bih->biClrImportant = 0;
    v7 = CreateDIBSection(
           hdc: this->m_memdc,
           pbmi: (const BITMAPINFO *)this->m_bih,
           usage: 0,
           ppvBits: &bits,
           hSection: nullptr,
           offset: 0);
    this->m_DIBSection = v7;
    GetObjectA(h: v7, c: 84, pv: &dibs);
    this->m_pGetFrame = AVIStreamGetFrameOpen(pavi: *p_m_pAVIStream, lpbiWanted: &dibs.dsBmih);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B20
// Name: public: virtual void __near * CAvi::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAvi *__thiscall CAvi::QueryInterface(CAvi *this, const char *pInterfaceName)
{
  int v3; // eax

  v3 = _V_strlen(str: "VAvi001");
  return V_strncmp(s1: pInterfaceName, s2: "VAvi001", count: v3 + 1) == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001B50
// Name: public: virtual void CAvi::SetMainWindow(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::SetMainWindow(CAvi *this, HWND__ *hWnd)
{
  this->m_hWnd = hWnd;
}

//------------------------------------------------------------------------------
// Address: 0x10001B60
// Name: public: void CAviFile::Init(struct AVIParams_t const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAviFile::Init(CAviFile *this, const AVIParams_t *params, HWND hWnd)
{
  unsigned __int16 v4; // ax
  char avifilename[512]; // [esp+Ch] [ebp-400h] BYREF
  char fullavifilename[512]; // [esp+20Ch] [ebp-200h] BYREF

  CAviFile::Reset(this);
  V_snprintf(pDest: avifilename, maxLen: 512, pFormat: "%s", params->m_pFileName);
  V_SetExtension(path: avifilename, extension: ".avi", pathStringLength: 512);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: avifilename,
    a3: params->m_pPathID,
    a4: fullavifilename,
    a5: 512,
    a6: FILTER_NONE,
    a7: nullptr);
  if ( g_pFullFileSystem->FileExists(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: fullavifilename,
         a3: params->m_pPathID) )
  {
    g_pFullFileSystem->RemoveFile(this: g_pFullFileSystem, a2: fullavifilename, a3: params->m_pPathID);
  }
  if ( AVIFileOpenA(ppfile: &this->m_pAVIFile, szFile: fullavifilename, uMode: 0x1001u, lpHandler: nullptr) == 0 )
  {
    this->m_wFormat.cbSize = 18;
    this->m_wFormat.wFormatTag = 1;
    this->m_wFormat.nChannels = params->m_nNumChannels;
    this->m_wFormat.nSamplesPerSec = params->m_nSampleRate;
    v4 = LOWORD(params->m_nNumChannels) * ((params->m_nSampleBits != 8) + 1);
    this->m_wFormat.nBlockAlign = v4;
    this->m_wFormat.nAvgBytesPerSec = params->m_nSampleRate * v4;
    this->m_wFormat.wBitsPerSample = params->m_nSampleBits;
    this->m_nFrameRate = params->m_nFrameRate;
    this->m_nFrameScale = params->m_nFrameScale;
    this->m_bValid = true;
    this->m_nHeight = params->m_nHeight;
    this->m_nWidth = params->m_nWidth;
    CAviFile::CreateVideoStreams(this, params, hWnd);
    CAviFile::CreateAudioStream(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001CC0
// Name: public: bool CAVIMaterial::Init(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAVIMaterial::Init(
        CAVIMaterial *this,
        const char *pMaterialName,
        const char *pFileName,
        const char *pPathID)
{
  double dwRate; // st7
  unsigned int dwHeight; // eax
  LONG v8; // eax
  ITexture *m_pTexture; // ecx
  char pFullAVIFileName[512]; // [esp+8h] [ebp-46Ch] BYREF
  char pAVIFileName[512]; // [esp+208h] [ebp-26Ch] BYREF
  _AVIFILEINFOA info; // [esp+408h] [ebp-6Ch] BYREF

  V_snprintf(pDest: pAVIFileName, maxLen: 512, pFormat: "%s", pFileName);
  V_DefaultExtension(path: pAVIFileName, extension: ".avi", pathStringLength: 512);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: pAVIFileName,
    a3: pPathID,
    a4: pFullAVIFileName,
    a5: 512,
    a6: FILTER_NONE,
    a7: nullptr);
  if ( AVIFileOpenA(ppfile: &this->m_pAVIFile, szFile: pFullAVIFileName, uMode: 0, lpHandler: nullptr) != 0 )
  {
    _Warning(a1: "AVI '%s' not found\n", pFullAVIFileName);
    this->m_nAVIWidth = 64;
    this->m_nAVIHeight = 64;
    this->m_nFrameRate = 1;
    this->m_nFrameCount = 1;
    CMaterialReference::Init(
      this: &this->m_Material,
      pMaterialName: "debug/debugempty",
      pTextureGroupName: "Other textures",
      bComplain: true);
    return 0;
  }
  else
  {
    AVIFileInfoA(pfile: this->m_pAVIFile, pfi: &info, lSize: 108);
    dwRate = (double)info.dwRate;
    dwHeight = info.dwHeight;
    this->m_nAVIWidth = info.dwWidth;
    this->m_nAVIHeight = dwHeight;
    this->m_nFrameRate = (int)(dwRate / (double)info.dwScale + 0.5);
    CAVIMaterial::CreateProceduralTexture(this, pTextureName: pMaterialName);
    CAVIMaterial::CreateProceduralMaterial(this, pMaterialName);
    CAVIMaterial::CreateVideoStream(this);
    if ( AVIStreamLength(pavi: this->m_pAVIStream) >= 0 )
      v8 = AVIStreamLength(pavi: this->m_pAVIStream);
    else
      v8 = 0;
    m_pTexture = this->m_Texture.m_pTexture;
    this->m_nFrameCount = v8;
    m_pTexture->Download(this: m_pTexture, a2: nullptr, a3: 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E30
// Name: public: void CAVIMaterial::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAVIMaterial::Shutdown(CAVIMaterial *this)
{
  ITexture *m_pTexture; // ecx

  if ( this->m_pGetFrame != nullptr )
  {
    AVIStreamGetFrameClose(pg: this->m_pGetFrame);
    this->m_pGetFrame = nullptr;
  }
  if ( this->m_DIBSection != nullptr )
  {
    DeleteObject(ho: this->m_DIBSection);
    this->m_DIBSection = nullptr;
  }
  if ( this->m_memdc != nullptr )
  {
    DeleteDC(hdc: this->m_memdc);
    this->m_memdc = nullptr;
  }
  if ( this->m_pAVIStream != nullptr )
  {
    AVIStreamRelease(pavi: this->m_pAVIStream);
    this->m_pAVIStream = nullptr;
  }
  CMaterialReference::Shutdown(this: &this->m_Material, bDeleteIfUnreferenced: false);
  m_pTexture = this->m_Texture.m_pTexture;
  if ( m_pTexture != nullptr )
  {
    m_pTexture->SetTextureRegenerator(this: m_pTexture, a2: nullptr, a3: true);
    CTextureReference::Shutdown(this: &this->m_Texture, bDeleteIfUnReferenced: false);
  }
  if ( this->m_pAVIFile != nullptr )
  {
    AVIFileRelease(pfile: this->m_pAVIFile);
    this->m_pAVIFile = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001EB0
// Name: public: virtual void CAVIMaterial::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAVIMaterial::RegenerateTextureBits(
        CAVIMaterial *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  __int16 v6; // bx
  char v7; // al
  int v8; // eax
  int biWidth; // ecx
  int v10; // esi
  int biBitCount; // edx
  unsigned __int8 *v12; // eax
  int v13; // edi
  unsigned int v14; // edx
  unsigned int v15; // edx
  int v16; // eax
  __int64 v17; // rax
  unsigned int v18; // edx
  unsigned int v19; // edx
  int v20; // eax
  __int64 v21; // rax
  unsigned __int8 *v22; // eax
  unsigned int v23; // [esp-4h] [ebp-5Ch]
  unsigned __int8 *pixelWriter; // [esp+Ch] [ebp-4Ch]
  int pixelWriter_4; // [esp+10h] [ebp-48h]
  int pixelWriter_4a; // [esp+10h] [ebp-48h]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-42h]
  int pixelWriter_12; // [esp+18h] [ebp-40h]
  int pixelWriter_16; // [esp+1Ch] [ebp-3Ch]
  char pixelWriter_20; // [esp+20h] [ebp-38h]
  char pixelWriter_24; // [esp+24h] [ebp-34h]
  char pixelWriter_28; // [esp+28h] [ebp-30h]
  unsigned __int8 pixelWriter_32; // [esp+2Ch] [ebp-2Ch]
  unsigned int nStride; // [esp+38h] [ebp-20h]
  unsigned __int16 v35; // [esp+3Ch] [ebp-1Ch]
  int i; // [esp+3Ch] [ebp-1Ch]
  int v37; // [esp+3Ch] [ebp-1Ch]
  int x; // [esp+40h] [ebp-18h]
  int xa; // [esp+40h] [ebp-18h]
  int xb; // [esp+40h] [ebp-18h]
  int v41; // [esp+44h] [ebp-14h]
  int v42; // [esp+44h] [ebp-14h]
  int y; // [esp+48h] [ebp-10h]
  int ya; // [esp+48h] [ebp-10h]
  int yb; // [esp+48h] [ebp-10h]
  unsigned __int8 *v46; // [esp+4Ch] [ebp-Ch]
  unsigned __int8 *v47; // [esp+4Ch] [ebp-Ch]
  tagBITMAPINFOHEADER *lpbih; // [esp+50h] [ebp-8h]
  unsigned __int8 *pDatac; // [esp+64h] [ebp+Ch]
  unsigned __int8 *pData; // [esp+64h] [ebp+Ch]
  unsigned __int8 *pDataa; // [esp+64h] [ebp+Ch]
  unsigned __int8 *pDatab; // [esp+64h] [ebp+Ch]

  if ( this->m_pAVIStream != nullptr
    && this->m_pGetFrame != nullptr
    && pVTFTexture->FrameCount(this: pVTFTexture) <= 1
    && pVTFTexture->FaceCount(this: pVTFTexture) <= 1
    && pVTFTexture->MipCount(this: pVTFTexture) <= 1
    && pVTFTexture->Depth(this: pVTFTexture) <= 1
    && (lpbih = (tagBITMAPINFOHEADER *)AVIStreamGetFrame(pg: this->m_pGetFrame, lPos: this->m_nCurrentSample)) != nullptr )
  {
    v35 = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
    pixelWriter = pVTFTexture->ImageData_3(this: pVTFTexture);
    switch ( pVTFTexture->Format(this: pVTFTexture) )
    {
      case IMAGE_FORMAT_RGBA8888:
      case IMAGE_FORMAT_UVWQ8888:
        pixelWriter_10 = 4;
        pixelWriter_12 = 0x80000;
        v6 = 16;
        pixelWriter_16 = 1572880;
        pixelWriter_20 = -1;
        pixelWriter_24 = -1;
        pixelWriter_28 = -1;
        pixelWriter_32 = -1;
        goto LABEL_28;
      case IMAGE_FORMAT_BGR888:
        v6 = 0;
        pixelWriter_10 = 3;
        pixelWriter_12 = 524304;
        pixelWriter_16 = 0;
        pixelWriter_20 = -1;
        pixelWriter_24 = -1;
        pixelWriter_28 = -1;
        pixelWriter_32 = 0;
        goto LABEL_28;
      case IMAGE_FORMAT_I8:
        pixelWriter_10 = 1;
        goto LABEL_23;
      case IMAGE_FORMAT_A8:
        v7 = 0;
        v6 = 0;
        pixelWriter_10 = 1;
        pixelWriter_12 = 0;
        pixelWriter_16 = 0;
        pixelWriter_20 = 0;
        pixelWriter_32 = -1;
        goto LABEL_26;
      case IMAGE_FORMAT_BGRA8888:
        pixelWriter_10 = 4;
        pixelWriter_12 = 524304;
        v6 = 0;
        pixelWriter_16 = 1572864;
        pixelWriter_20 = -1;
        pixelWriter_24 = -1;
        pixelWriter_28 = -1;
        pixelWriter_32 = -1;
        goto LABEL_28;
      case IMAGE_FORMAT_BGRX8888:
        v6 = 0;
        pixelWriter_10 = 4;
        pixelWriter_12 = 524304;
        pixelWriter_16 = 1572864;
        pixelWriter_20 = -1;
        pixelWriter_24 = -1;
        pixelWriter_28 = -1;
        pixelWriter_32 = 0;
        goto LABEL_28;
      case IMAGE_FORMAT_BGR565:
        v7 = -8;
        pixelWriter_10 = 2;
        pixelWriter_12 = 196616;
        v6 = -3;
        pixelWriter_16 = 65533;
        pixelWriter_20 = -8;
        pixelWriter_24 = -4;
        pixelWriter_32 = 0;
        goto LABEL_27;
      case IMAGE_FORMAT_BGRX5551:
      case IMAGE_FORMAT_BGRA5551:
        v7 = -8;
        pixelWriter_10 = 2;
        pixelWriter_12 = 131079;
        v6 = -3;
        pixelWriter_16 = 589821;
        pixelWriter_20 = -8;
        pixelWriter_32 = 0x80;
        goto LABEL_26;
      case IMAGE_FORMAT_BGRA4444:
        v7 = -16;
        pixelWriter_10 = 2;
        pixelWriter_12 = 4;
        v6 = -4;
        pixelWriter_16 = 589820;
        pixelWriter_20 = -16;
        goto LABEL_25;
      case IMAGE_FORMAT_RGBA16161616F:
      case IMAGE_FORMAT_RGBA16161616:
        v7 = -1;
        pixelWriter_10 = 8;
        pixelWriter_12 = 0x100000;
        v6 = 32;
        pixelWriter_16 = 3145760;
        pixelWriter_20 = -1;
        goto LABEL_25;
      case IMAGE_FORMAT_R32F:
        pixelWriter_10 = 4;
        pixelWriter_20 = -1;
        goto LABEL_24;
      case IMAGE_FORMAT_RGBA32323232F:
        pixelWriter_10 = 16;
        pixelWriter_12 = 0x200000;
        v6 = 64;
        pixelWriter_16 = 6291520;
        pixelWriter_20 = -1;
        pixelWriter_24 = -1;
        pixelWriter_28 = -1;
        pixelWriter_32 = -1;
        goto LABEL_28;
      case IMAGE_FORMAT_BGRA1010102:
        v7 = -1;
        pixelWriter_10 = 4;
        pixelWriter_12 = 655380;
        v6 = 0;
        pixelWriter_16 = 1966080;
        pixelWriter_20 = -1;
        pixelWriter_32 = 3;
        goto LABEL_26;
      default:
        pixelWriter_10 = 0;
LABEL_23:
        pixelWriter_20 = -1;
LABEL_24:
        v7 = 0;
        v6 = 0;
        pixelWriter_12 = 0;
        pixelWriter_16 = 0;
LABEL_25:
        pixelWriter_32 = v7;
LABEL_26:
        pixelWriter_24 = v7;
LABEL_27:
        pixelWriter_28 = v7;
LABEL_28:
        pDatac = (unsigned __int8 *)pVTFTexture->Width(this: pVTFTexture);
        v8 = pVTFTexture->Height(this: pVTFTexture);
        biWidth = lpbih->biWidth;
        x = lpbih->biHeight;
        v10 = abs32(x);
        if ( biWidth > (int)pDatac || v10 > v8 )
          goto AVIMaterialError;
        biBitCount = lpbih->biBitCount;
        v12 = (unsigned __int8 *)lpbih + lpbih->biSize;
        pData = v12;
        if ( biBitCount == 8 )
        {
          v12 += 1024;
          pData = v12;
        }
        if ( (biBitCount == 16 || biBitCount == 32) && lpbih->biCompression == 3 )
          pData = v12 + 12;
        nStride = (biWidth * (unsigned __int16)biBitCount / 8 + 3) & 0xFFFFFFFC;
        if ( x <= 0 )
        {
          y = 0;
          v13 = 1;
        }
        else
        {
          y = v10 - 1;
          v13 = -1;
        }
        if ( (_WORD)biBitCount == 24 )
        {
          if ( v10 > 0 )
          {
            v41 = v13 * v35;
            v46 = pData + 2;
            ya = (int)&pixelWriter[y * v35];
            for ( i = v10; i != 0; --i )
            {
              pixelWriter_4 = ya;
              xa = 0;
              if ( biWidth > 0 )
              {
                pDataa = v46;
                do
                {
                  if ( pixelWriter_10 != 0 )
                  {
                    if ( pixelWriter_10 >= 5u )
                    {
                      if ( v6 <= 0 )
                        v17 = (__int64)(unsigned __int8)(*(pDataa - 2) & pixelWriter_28) >> -(char)v6;
                      else
                        v17 = (unsigned __int64)(unsigned __int8)(*(pDataa - 2) & pixelWriter_28) << v6;
                      if ( pixelWriter_10 == 8 )
                        *(_QWORD *)pixelWriter_4 = v17
                                                 | ((unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16))
                                                 | ((unsigned __int64)(unsigned __int8)(*(pDataa - 1) & pixelWriter_24) << SBYTE2(pixelWriter_12))
                                                 | ((unsigned __int64)(unsigned __int8)(*pDataa & pixelWriter_20) << pixelWriter_12);
                    }
                    else
                    {
                      v14 = (unsigned __int8)(*(pDataa - 2) & pixelWriter_28);
                      if ( v6 <= 0 )
                        v15 = v14 >> -(char)pixelWriter_16;
                      else
                        v15 = v14 << pixelWriter_16;
                      v16 = v15
                          | (pixelWriter_32 << SBYTE2(pixelWriter_16))
                          | ((unsigned __int8)(*(pDataa - 1) & pixelWriter_24) << SBYTE2(pixelWriter_12))
                          | ((unsigned __int8)(*pDataa & pixelWriter_20) << pixelWriter_12);
                      switch ( pixelWriter_10 )
                      {
                        case 1u:
                          *(_BYTE *)pixelWriter_4 = v16;
                          break;
                        case 2u:
                          *(_WORD *)pixelWriter_4 = v16;
                          break;
                        case 3u:
                          *(_WORD *)pixelWriter_4 = v16;
                          *(_BYTE *)(pixelWriter_4 + 2) = BYTE2(v16);
                          break;
                        case 4u:
                          *(_DWORD *)pixelWriter_4 = v16;
                          break;
                      }
                    }
                  }
                  pixelWriter_4 += pixelWriter_10;
                  biWidth = lpbih->biWidth;
                  pDataa += 3;
                  ++xa;
                }
                while ( xa < biWidth );
              }
              v46 += nStride;
              ya += v41;
            }
          }
        }
        else if ( (_WORD)biBitCount == 32 && v10 > 0 )
        {
          v42 = v13 * v35;
          v47 = pData + 1;
          yb = (int)&pixelWriter[y * v35];
          for ( xb = v10; xb != 0; --xb )
          {
            pixelWriter_4a = yb;
            v37 = 0;
            if ( biWidth > 0 )
            {
              pDatab = v47;
              do
              {
                if ( pixelWriter_10 != 0 )
                {
                  if ( pixelWriter_10 >= 5u )
                  {
                    if ( v6 <= 0 )
                      v21 = (__int64)(unsigned __int8)(*(pDatab - 1) & pixelWriter_28) >> -(char)v6;
                    else
                      v21 = (unsigned __int64)(unsigned __int8)(*(pDatab - 1) & pixelWriter_28) << v6;
                    if ( pixelWriter_10 == 8 )
                      *(_QWORD *)pixelWriter_4a = v21
                                                | ((unsigned __int64)(unsigned __int8)(pDatab[2] & pixelWriter_32) << SBYTE2(pixelWriter_16))
                                                | ((unsigned __int64)(unsigned __int8)(*pDatab & pixelWriter_24) << SBYTE2(pixelWriter_12))
                                                | ((unsigned __int64)(unsigned __int8)(pDatab[1] & pixelWriter_20) << pixelWriter_12);
                  }
                  else
                  {
                    v18 = (unsigned __int8)(*(pDatab - 1) & pixelWriter_28);
                    if ( v6 <= 0 )
                      v19 = v18 >> -(char)pixelWriter_16;
                    else
                      v19 = v18 << pixelWriter_16;
                    v20 = v19
                        | ((unsigned __int8)(pDatab[2] & pixelWriter_32) << SBYTE2(pixelWriter_16))
                        | ((unsigned __int8)(*pDatab & pixelWriter_24) << SBYTE2(pixelWriter_12))
                        | ((unsigned __int8)(pDatab[1] & pixelWriter_20) << pixelWriter_12);
                    switch ( pixelWriter_10 )
                    {
                      case 1u:
                        *(_BYTE *)pixelWriter_4a = v20;
                        break;
                      case 2u:
                        *(_WORD *)pixelWriter_4a = v20;
                        break;
                      case 3u:
                        *(_WORD *)pixelWriter_4a = v20;
                        *(_BYTE *)(pixelWriter_4a + 2) = BYTE2(v20);
                        break;
                      case 4u:
                        *(_DWORD *)pixelWriter_4a = v20;
                        break;
                    }
                  }
                }
                biWidth = lpbih->biWidth;
                pixelWriter_4a += pixelWriter_10;
                pDatab += 4;
                ++v37;
              }
              while ( v37 < biWidth );
            }
            v47 += nStride;
            yb += v42;
          }
        }
        break;
    }
  }
  else
  {
AVIMaterialError:
    v23 = pVTFTexture->ComputeTotalSize(this: pVTFTexture);
    v22 = pVTFTexture->ImageData_3(this: pVTFTexture);
    memset(dst: v22, value: 0xFFu, count: v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002720
// Name: public: virtual void CAvi::AppendMovieSound(unsigned short,short __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::AppendMovieSound(CAvi *this, unsigned __int16 h, __int16 *buf, unsigned int bufsize)
{
  if ( h != 0xFFFF )
    CAviFile::AppendMovieSound(this: &this->m_AVIFiles.m_Memory.m_pMemory[h].m_Element, buf, bufsize);
}

//------------------------------------------------------------------------------
// Address: 0x10002750
// Name: public: virtual void CAvi::AppendMovieFrame(unsigned short,struct BGR888_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::AppendMovieFrame(CAvi *this, unsigned __int16 h, const BGR888_t *pRGBData)
{
  if ( h != 0xFFFF )
    CAviFile::AppendMovieFrame(this: &this->m_AVIFiles.m_Memory.m_pMemory[h].m_Element, pRGBData);
}

//------------------------------------------------------------------------------
// Address: 0x10002780
// Name: public: virtual void CAvi::SetTime(unsigned short,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::SetTime(CAvi *this, unsigned __int16 h, float flTime)
{
  CAVIMaterial *m_Element; // eax
  float v4; // xmm0_4

  if ( h != 0xFFFF )
  {
    m_Element = this->m_AVIMaterials.m_Memory.m_pMemory[h].m_Element;
    if ( m_Element->m_pAVIStream != nullptr )
    {
      v4 = (float)((float)m_Element->m_nFrameRate * flTime) + 0.5;
      if ( m_Element->m_nCurrentSample != (int)v4 )
      {
        m_Element->m_nCurrentSample = (int)v4;
        m_Element->m_Texture.m_pTexture->Download(this: m_Element->m_Texture.m_pTexture, a2: nullptr, a3: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100027E0
// Name: public: virtual class IMaterial __near * CAvi::GetMaterial(unsigned short)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CAvi::GetMaterial(CAvi *this, unsigned __int16 h)
{
  if ( h == 0xFFFF )
    return nullptr;
  else
    return this->m_AVIMaterials.m_Memory.m_pMemory[h].m_Element->m_Material.m_pMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x10002810
// Name: public: virtual void CAvi::GetTexCoordRange(unsigned short,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::GetTexCoordRange(CAvi *this, unsigned __int16 h, float *pMaxU, float *pMaxV)
{
  if ( h == 0xFFFF )
  {
    *pMaxV = 1.0;
    *pMaxU = 1.0;
  }
  else
  {
    CAVIMaterial::GetTexCoordRange(this: this->m_AVIMaterials.m_Memory.m_pMemory[h].m_Element, pMaxU, pMaxV);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002860
// Name: public: virtual void CAvi::GetFrameSize(unsigned short,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::GetFrameSize(CAvi *this, unsigned __int16 h, int *pWidth, int *pHeight)
{
  if ( h == 0xFFFF )
  {
    *pHeight = 1;
    *pWidth = 1;
  }
  else
  {
    *(UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *)pWidth = *(UtlLinkedListElem_t<CAVIMaterial *,unsigned short> *)&this->m_AVIMaterials.m_Memory.m_pMemory[h].m_Element->m_nAVIWidth;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100028B0
// Name: public: virtual int CAvi::GetFrameRate(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAvi::GetFrameRate(CAvi *this, unsigned __int16 h)
{
  if ( h == 0xFFFF )
    return 1;
  else
    return this->m_AVIMaterials.m_Memory.m_pMemory[h].m_Element->m_nFrameRate;
}

//------------------------------------------------------------------------------
// Address: 0x100028E0
// Name: public: virtual int CAvi::GetFrameCount(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAvi::GetFrameCount(CAvi *this, unsigned __int16 h)
{
  if ( h == 0xFFFF )
    return 1;
  else
    return this->m_AVIMaterials.m_Memory.m_pMemory[h].m_Element->m_nFrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x10002910
// Name: public: virtual void CAvi::SetFrame(unsigned short,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::SetFrame(CAvi *this, unsigned __int16 h, float flFrame)
{
  CAVIMaterial *m_Element; // eax
  int v4; // ecx

  if ( h != 0xFFFF )
  {
    m_Element = this->m_AVIMaterials.m_Memory.m_pMemory[h].m_Element;
    if ( m_Element->m_pAVIStream != nullptr )
    {
      v4 = (int)(float)(flFrame + 0.5);
      if ( m_Element->m_nCurrentSample != v4 )
      {
        m_Element->m_nCurrentSample = v4;
        m_Element->m_Texture.m_pTexture->Download(this: m_Element->m_Texture.m_pTexture, a2: nullptr, a3: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002C60
// Name: public: virtual enum InitReturnVal_t CAvi::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAvi::Init(CAvi *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  AVIFileInit();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002C80
// Name: public: virtual void CAvi::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::Shutdown(CAvi *this)
{
  AVIFileExit();
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10002E30
// Name: public: virtual bool CAvi::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAvi::Connect(CAvi *this, void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v3)(const char *, int *); // [esp+0h] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+4h] [ebp-4h] BYREF

  v3 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  CBIKMaterialYTextureRegenerator::Release(pFactoryList: &v3, nFactoryCount: 1);
  if ( g_pFullFileSystem == nullptr || materials == nullptr )
    _Msg(a1: "Avi failed to connect to a required system\n");
  return g_pFullFileSystem != nullptr && materials != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002FC0
// Name: public: CAvi::~CAvi(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::~CAvi(CAvi *this)
{
  CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_AVIMaterials);
  if ( this->m_AVIMaterials.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_AVIMaterials.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AVIMaterials.m_Memory.m_pMemory);
      this->m_AVIMaterials.m_Memory.m_pMemory = nullptr;
    }
    this->m_AVIMaterials.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_AVIFiles);
  if ( this->m_AVIFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_AVIFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AVIFiles.m_Memory.m_pMemory);
      this->m_AVIFiles.m_Memory.m_pMemory = nullptr;
    }
    this->m_AVIFiles.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003030
// Name: public: virtual enum AppSystemTier_t CTier3AppSystem<class IAvi,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier3AppSystem<IAvi,0>::GetTier(CTier3AppSystem<IAvi,0> *this)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10003040
// Name: public: virtual void CTier3AppSystem<class IAvi,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10003050
// Name: public: virtual void CAvi::FinishAVI(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::FinishAVI(CAvi *this, unsigned __int16 h)
{
  int v2; // edi
  CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short> > *p_m_AVIFiles; // esi

  if ( h != 0xFFFF )
  {
    v2 = h;
    p_m_AVIFiles = &this->m_AVIFiles;
    CAviFile::Shutdown(this: &this->m_AVIFiles.m_Memory.m_pMemory[v2].m_Element);
    CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::Unlink(
      this: p_m_AVIFiles,
      elem: h);
    p_m_AVIFiles->m_Memory.m_pMemory[v2].m_Next = p_m_AVIFiles->m_FirstFree;
    p_m_AVIFiles->m_FirstFree = h;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100030A0
// Name: public: virtual void CAvi::DestroyAVIMaterial(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAvi::DestroyAVIMaterial(CAvi *this, unsigned __int16 h)
{
  CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *p_m_AVIMaterials; // edi
  unsigned int v3; // esi
  CAVIMaterial *m_Element; // ebx

  if ( h != 0xFFFF )
  {
    p_m_AVIMaterials = &this->m_AVIMaterials;
    v3 = h;
    CAVIMaterial::Shutdown(this: this->m_AVIMaterials.m_Memory.m_pMemory[v3].m_Element);
    m_Element = p_m_AVIMaterials->m_Memory.m_pMemory[v3].m_Element;
    if ( m_Element != nullptr )
    {
      CTextureReference::~CTextureReference(this: &m_Element->m_Texture);
      CMaterialReference::~CMaterialReference(this: &m_Element->m_Material);
      free(pMem: m_Element);
    }
    CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::Unlink(
      this: p_m_AVIMaterials,
      elem: h);
    p_m_AVIMaterials->m_Memory.m_pMemory[v3].m_Next = p_m_AVIMaterials->m_FirstFree;
    p_m_AVIMaterials->m_FirstFree = h;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003110
// Name: public: CAvi::CAvi(void)
// Source: json
//------------------------------------------------------------------------------
CAvi *__thiscall CAvi::CAvi(CAvi *this)
{
  this->__vftable = (CAvi_vtbl *)&CAvi::`vftable';
  this->m_AVIFiles.m_Memory.m_pMemory = nullptr;
  this->m_AVIFiles.m_Memory.m_nAllocationCount = 0;
  this->m_AVIFiles.m_Memory.m_nGrowSize = 0;
  this->m_AVIFiles.m_LastAlloc.index = -1;
  this->m_AVIFiles.m_Head = -1;
  this->m_AVIFiles.m_Tail = -1;
  this->m_AVIFiles.m_FirstFree = -1;
  this->m_AVIFiles.m_ElementCount = 0;
  this->m_AVIFiles.m_NumAlloced = 0;
  this->m_AVIFiles.m_pElements = this->m_AVIFiles.m_Memory.m_pMemory;
  this->m_AVIMaterials.m_Memory.m_pMemory = nullptr;
  this->m_AVIMaterials.m_Memory.m_nAllocationCount = 0;
  this->m_AVIMaterials.m_Memory.m_nGrowSize = 0;
  this->m_AVIMaterials.m_LastAlloc.index = -1;
  this->m_AVIMaterials.m_Head = -1;
  this->m_AVIMaterials.m_Tail = -1;
  this->m_AVIMaterials.m_FirstFree = -1;
  this->m_AVIMaterials.m_ElementCount = 0;
  this->m_AVIMaterials.m_NumAlloced = 0;
  this->m_AVIMaterials.m_pElements = this->m_AVIMaterials.m_Memory.m_pMemory;
  this->m_hWnd = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003180
// Name: public: virtual unsigned short CAvi::StartAVI(struct AVIParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CAvi::StartAVI(CAvi *this, const AVIParams_t *params)
{
  unsigned __int16 v3; // ax
  int v4; // esi
  UtlLinkedListElem_t<CAviFile,unsigned short> *v5; // ecx

  v3 = CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_AVIFiles,
         multilist: false);
  v4 = v3;
  if ( v3 == 0xFFFF )
  {
    LOWORD(v4) = -1;
  }
  else
  {
    CUtlLinkedList<CAviFile,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAviFile,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_AVIFiles,
      before: 0xFFFFu,
      elem: v3);
    v5 = &this->m_AVIFiles.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
      CAviFile::Reset(this: &v5->m_Element);
  }
  CAviFile::Init(this: &this->m_AVIFiles.m_Memory.m_pMemory[(unsigned __int16)v4].m_Element, params, hWnd: this->m_hWnd);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100031E0
// Name: public: virtual unsigned short CAvi::CreateAVIMaterial(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CAvi::CreateAVIMaterial(
        CAvi *this,
        const char *pMaterialName,
        const char *pFileName,
        const char *pPathID)
{
  CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short> > *p_m_AVIMaterials; // edi
  unsigned __int16 v5; // si
  unsigned __int16 v6; // bx
  CMaterialReference *v7; // eax
  CTextureReference *v8; // esi
  int v9; // eax

  p_m_AVIMaterials = &this->m_AVIMaterials;
  v5 = CUtlLinkedList<CAVIMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAVIMaterial *,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_AVIMaterials,
         multilist: false);
  if ( v5 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CBIKMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBIKMaterial *,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_AVIMaterials,
      before: 0xFFFFu,
      elem: v5);
    v6 = v5;
  }
  v7 = (CMaterialReference *)operator new(nSize: 0x64u);
  v8 = (CTextureReference *)v7;
  if ( v7 != nullptr )
  {
    v7->m_pMaterial = (IMaterial *)&CAVIMaterial::`vftable';
    CMaterialReference::CMaterialReference(
      this: v7 + 1,
      pMaterialName: nullptr,
      pTextureGroupName: nullptr,
      bComplain: true);
    CTextureReference::CTextureReference(this: v8 + 2);
    _V_memset(dest: &v8[13], fill: 0, count: 44);
    v8[11].m_pTexture = nullptr;
    v8[12].m_pTexture = nullptr;
    v8[4].m_pTexture = nullptr;
    v8[3].m_pTexture = nullptr;
    v8[5].m_pTexture = nullptr;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = v6;
  p_m_AVIMaterials->m_Memory.m_pMemory[v9].m_Element = (CAVIMaterial *)v8;
  CAVIMaterial::Init(this: p_m_AVIMaterials->m_Memory.m_pMemory[v9].m_Element, pMaterialName, pFileName, pPathID);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10001B10
// Name: __CreateCAviIAvi_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAvi *__cdecl _CreateCAviIAvi_interface()
{
  return &g_AVI;
}
