// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vtex/vtex.cpp
// Functions: 243
// ============================================================

#include "utils\vtex\vtex.h"

//------------------------------------------------------------------------------
// Address: 0x10003620
// Name: bool StringHasPrefix(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl StringHasPrefix(const char *str, const char *prefix)
{
  return StringAfterPrefix(str, prefix) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003640
// Name: public: void Bitmap_t::Init(int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Bitmap_t::Init(Bitmap_t *this, int nWidth, int nHeight, ImageFormat imageFormat)
{
  const ImageFormatInfo_t *v5; // eax

  if ( this->m_pBits != nullptr )
  {
    free(pMem: this->m_pBits);
    this->m_pBits = nullptr;
  }
  this->m_nWidth = nWidth;
  this->m_nHeight = nHeight;
  this->m_ImageFormat = imageFormat;
  v5 = ImageLoader::ImageFormatInfo(fmt: imageFormat);
  this->m_pBits = (unsigned __int8 *)MemAlloc_Alloc(nSize: nHeight * nWidth * v5->m_nNumBytes);
}

//------------------------------------------------------------------------------
// Address: 0x100036A0
// Name: public: class CDmaString __near & CDmaString::operator=(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmaString *__thiscall CDmaString::operator=(CDmaString *this, const char *src)
{
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&src, a3: src);
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: this->m_pAttribute, value: (const CUtlSymbolLarge *)&src);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100036E0
// Name: VTexError
// Source: json
//------------------------------------------------------------------------------
void VTexError(char *pFormat, ...)
{
  int v1; // eax
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest, maxLen: 4096, pFormat, params);
  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-crcvalidate") != 0 )
  {
    v2 = __iob_func();
    fprintf(str: v2 + 2, format: "ERROR: %s", pDest);
  }
  else
  {
    if ( !g_bUseStandardError )
    {
      v3 = __iob_func();
      fprintf(str: v3 + 2, format: "ERROR: %s", pDest);
      if ( !g_NoPause )
      {
        printf(format: "\nHit a key to continue\n");
        getch();
      }
      exit(code: 1);
    }
    _Error(a1: "ERROR: %s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100037B0
// Name: VTexWarning
// Source: json
//------------------------------------------------------------------------------
void VTexWarning(char *pFormat, ...)
{
  _iobuf *v1; // eax
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest, maxLen: 4096, pFormat, params);
  if ( g_bWarningsAsErrors )
  {
    VTexError(pFormat: "%s", pDest);
  }
  else
  {
    v1 = __iob_func();
    fprintf(str: v1 + 2, format: "WARNING: %s", pDest);
    if ( !g_NoPause )
    {
      printf(format: "\nHit a key to continue\n");
      getch();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003840
// Name: VTexWarningNoPause
// Source: json
//------------------------------------------------------------------------------
void VTexWarningNoPause(char *pFormat, ...)
{
  _iobuf *v1; // eax
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest, maxLen: 4096, pFormat, params);
  if ( g_bWarningsAsErrors )
  {
    VTexError(pFormat: "%s", pDest);
  }
  else
  {
    v1 = __iob_func();
    fprintf(str: v1 + 2, format: "WARNING: %s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100038B0
// Name: VTexMsg
// Source: json
//------------------------------------------------------------------------------
void VTexMsg(char *pFormat, ...)
{
  _iobuf *v1; // eax
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest, maxLen: 4096, pFormat, params);
  v1 = __iob_func();
  fprintf(str: v1 + 1, format: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10003900
// Name: VTexMsgEx
// Source: json
//------------------------------------------------------------------------------
void VTexMsgEx(_iobuf *fout, char *pFormat, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+10h] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest, maxLen: 4096, pFormat, params);
  fprintf(str: fout, format: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10003950
// Name: public: VTexConfigInfo_t::VTexConfigInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
VTexConfigInfo_t *__thiscall VTexConfigInfo_t::VTexConfigInfo_t(VTexConfigInfo_t *this)
{
  this->m_nFlags = 0;
  *(_DWORD *)&this->m_bNormalToDuDv = 0;
  this->m_flBumpScale = 1.0;
  this->m_bDuDv = false;
  this->m_pfmscale = 1.0;
  *(_DWORD *)&this->m_bStripAlphaChannel = 0;
  this->m_SrcName[0] = 0;
  this->m_bAlphaToDistance = false;
  this->m_flDistanceSpread = 1.0;
  *(_DWORD *)&this->m_bIsCroppedSkyBox = 0;
  this->m_nStartFrame = -1;
  this->m_nEndFrame = -1;
  this->m_flAlphaThreshhold = -1.0;
  this->m_flAlphaHiFreqThreshhold = -1.0;
  this->m_numChannelsMax = 4;
  this->m_nMaxDimensionX = -1;
  this->m_nMaxDimensionX_360 = -1;
  this->m_nMaxDimensionY = -1;
  this->m_nMaxDimensionY_360 = -1;
  this->m_nVolumeTextureDepth = 1;
  this->m_nReduceX = 1;
  this->m_nReduceY = 1;
  this->m_exSettings0 = 0;
  *(_QWORD *)&this->m_vtfProcOptions.cbSize = 0;
  *(_QWORD *)this->m_vtfProcOptions.clrDecayGoal = 0;
  *(_QWORD *)this->m_vtfProcOptions.fDecayExponentBase = 0;
  *(_QWORD *)&this->m_vtfProcOptions.fDecayExponentBase[2] = 0;
  *(_DWORD *)&this->m_vtfProcOptions.fullAlphaAtMipLevel = 0;
  this->m_vtfProcOptions.flags0 |= 0x400u;
  this->m_vtfProcOptions.cbSize = 36;
  CRC32_Init(pulCRC: &this->m_uiInputHash);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003A00
// Name: public: bool VTexConfigInfo_t::IsSettings0Valid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VTexConfigInfo_t::IsSettings0Valid(VTexConfigInfo_t *this)
{
  return *(_DWORD *)&this->m_exSettings0 != 0
      && (this->m_exSettings0.m_flags0 != 0
       || this->m_exSettings0.m_flags1 != 0
       || this->m_exSettings0.m_flags2 != 0
       || this->m_exSettings0.m_flags3 != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10003A60
// Name: ComputeDesiredImageFormat
// Source: json
//------------------------------------------------------------------------------
ImageFormat __usercall ComputeDesiredImageFormat@<eax>(
        IVTFTexture *pTexture@<esi>,
        VTexConfigInfo_t *info@<edi>,
        int a3@<ebx>)
{
  bool m_bNormalToDuDv; // al
  __int16 v4; // ax
  __int16 v5; // bx
  bool bCopyAlphaToLuminance; // [esp+0h] [ebp-2h]
  bool bDUDVTarget; // [esp+1h] [ebp-1h]

  m_bNormalToDuDv = info->m_bNormalToDuDv;
  if ( m_bNormalToDuDv || (bDUDVTarget = false, info->m_bDuDv) )
    bDUDVTarget = true;
  if ( !m_bNormalToDuDv || (bCopyAlphaToLuminance = true, !info->m_bAlphaToLuminance) )
    bCopyAlphaToLuminance = false;
  v4 = ((int (__thiscall *)(IVTFTexture *, int))pTexture->Flags)(a1: pTexture, a2: a3);
  v5 = v4;
  if ( info->m_bStripAlphaChannel )
    v5 = v4 & 0xCFFF;
  if ( (info->m_vtfProcOptions.flags0 & 0x8000) != 0 )
    return IMAGE_FORMAT_DXT5;
  if ( pTexture->Format(this: pTexture) == IMAGE_FORMAT_RGB323232F )
  {
    if ( !g_bUsedAsLaunchableDLL || (info->m_vtfProcOptions.flags0 & 0x100) != 0 )
      return IMAGE_FORMAT_RGBA16161616F;
    else
      return IMAGE_FORMAT_BGRA8888;
  }
  else if ( pTexture->Format(this: pTexture) == IMAGE_FORMAT_R32F
         || pTexture->Format(this: pTexture) == IMAGE_FORMAT_RGBA32323232F )
  {
    return pTexture->Format(this: pTexture);
  }
  else if ( bDUDVTarget )
  {
    if ( bCopyAlphaToLuminance && (v5 & 0x3000) != 0 )
      return IMAGE_FORMAT_UVLX8888;
    else
      return IMAGE_FORMAT_UV88;
  }
  else if ( info->m_bStripColorChannel )
  {
    return IMAGE_FORMAT_A8;
  }
  else if ( (v5 & 0x800) != 0
         || (info->m_vtfProcOptions.flags0 & 0x100) != 0
         || pTexture->Width(this: pTexture) < 4
         || pTexture->Height(this: pTexture) < 4 )
  {
    return (v5 & 0x3000) != 0 ? 12 : 3;
  }
  else
  {
    if ( (v5 & 0x20) != 0 || (v5 & 0x2000) != 0 )
      return IMAGE_FORMAT_DXT5;
    return (v5 & 0x1000 | 0x6800u) >> 11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003BC0
// Name: void VTFGetLowResImageInfo(int,int,int __near *,int __near *,enum ImageFormat __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VTFGetLowResImageInfo(
        int cacheWidth,
        int cacheHeight,
        int *lowResImageWidth,
        int *lowResImageHeight,
        ImageFormat *imageFormat)
{
  int *v5; // ecx
  int *v6; // esi

  if ( cacheWidth <= cacheHeight )
  {
    if ( cacheHeight / 16 > 0 )
    {
      v6 = lowResImageHeight;
      v5 = lowResImageWidth;
      *lowResImageHeight = 16;
      *lowResImageWidth = cacheWidth / (cacheHeight / 16);
      goto LABEL_8;
    }
    v5 = lowResImageWidth;
  }
  else
  {
    v5 = lowResImageWidth;
    if ( cacheWidth / 16 > 0 )
    {
      v6 = lowResImageHeight;
      *lowResImageWidth = 16;
      *lowResImageHeight = cacheHeight / (cacheWidth / 16);
      goto LABEL_8;
    }
  }
  v6 = lowResImageHeight;
  *v5 = cacheWidth;
  *lowResImageHeight = cacheHeight;
LABEL_8:
  if ( *v5 < 1 )
    *v5 = 1;
  if ( *v6 < 1 )
    *v6 = 1;
  *imageFormat = IMAGE_FORMAT_DXT1;
}

//------------------------------------------------------------------------------
// Address: 0x10003C60
// Name: CreateLowResImage
// Source: json
//------------------------------------------------------------------------------
void __usercall CreateLowResImage(IVTFTexture *pVTFTexture@<esi>)
{
  int v1; // eax
  ImageFormat v2; // edi
  const char *m_pName; // edi
  ImageFormat v4; // eax
  const ImageFormatInfo_t *v5; // eax
  int v6; // [esp-10h] [ebp-20h]
  int iWidth; // [esp+4h] [ebp-Ch] BYREF
  int iHeight; // [esp+8h] [ebp-8h] BYREF
  ImageFormat imageFormat; // [esp+Ch] [ebp-4h] BYREF

  v6 = pVTFTexture->Height(this: pVTFTexture);
  v1 = pVTFTexture->Width(this: pVTFTexture);
  VTFGetLowResImageInfo(
    cacheWidth: v1,
    cacheHeight: v6,
    lowResImageWidth: &iWidth,
    lowResImageHeight: &iHeight,
    &imageFormat);
  v2 = imageFormat;
  pVTFTexture->InitLowResImage(this: pVTFTexture, a2: iWidth, a3: iHeight, a4: imageFormat);
  if ( !pVTFTexture->ConstructLowResImage(this: pVTFTexture) )
  {
    m_pName = ImageLoader::ImageFormatInfo(fmt: v2)->m_pName;
    v4 = pVTFTexture->Format(this: pVTFTexture);
    v5 = ImageLoader::ImageFormatInfo(fmt: v4);
    VTexError(pFormat: "Can't convert image from %s to %s in CalcLowResImage\n", v5->m_pName, m_pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003CF0
// Name: void MakeSrcFileName(struct VTexConfigInfo_t __near &,char const __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeSrcFileName(
        VTexConfigInfo_t *info,
        char *pFullNameWithoutExtension,
        int frameID,
        int faceID,
        int mipLevel,
        int z)
{
  bool v6; // bl
  char *v7; // edi
  char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  char normalTempBuf[512]; // [esp+Ch] [ebp-410h] BYREF
  char mipTempBuf[512]; // [esp+20Ch] [ebp-210h] BYREF
  char right[16]; // [esp+40Ch] [ebp-10h] BYREF

  v6 = info->m_nStartFrame != -1 && info->m_nEndFrame != -1;
  v7 = pFullNameWithoutExtension;
  if ( info->m_bNormalToDuDv && V_stristr(pStr: pFullNameWithoutExtension, pSearch: "_dudv") != nullptr )
  {
    V_strncpy(pDest: normalTempBuf, pSrc: pFullNameWithoutExtension, maxLen: 512);
    v8 = V_stristr(pStr: normalTempBuf, pSearch: "_dudv");
    _V_strcpy(dest: v8, src: "_normal");
    v7 = normalTempBuf;
  }
  if ( mipLevel > 0 )
  {
    V_strncpy(pDest: mipTempBuf, pSrc: v7, maxLen: 512);
    V_StrRight(pStr: mipTempBuf, nChars: 5, pOut: right, outSize: 16);
    if ( _V_strstr(s1: right, search: "_mip0") == nullptr )
    {
      if ( g_eMode != BITMAP_FILE_TYPE_PSD )
      {
        if ( g_eMode == BITMAP_FILE_TYPE_PFM )
          v9 = ".pfm";
        else
          v9 = ".tga";
      }
      else
      {
        v9 = ".psd";
      }
      VTexError(
        pFormat: "Invalid texture name (%s%s) for 'manualmip' - the top mip file should end in '_mip0'\n",
        v7,
        v9);
    }
    normalTempBuf[strlen(mipTempBuf) + 511] = 0;
    sprintf(string: right, format: "%d", mipLevel);
    V_strncat(pDest: mipTempBuf, pSrc: right, destBufferSize: 0x200u, max_chars_to_copy: -1);
    v7 = mipTempBuf;
  }
  if ( v6 )
  {
    if ( info->m_bIsCubeMap && g_bOldCubemapPath )
    {
      if ( g_eMode != BITMAP_FILE_TYPE_PSD )
      {
        if ( g_eMode == BITMAP_FILE_TYPE_PFM )
          v10 = ".pfm";
        else
          v10 = ".tga";
      }
      else
      {
        v10 = ".psd";
      }
      V_snprintf(
        pDest: info->m_SrcName,
        maxLen: 260,
        pFormat: "%s%s%03d%s",
        v7,
        g_CubemapFacingNames[faceID],
        frameID + info->m_nStartFrame,
        v10);
    }
    else if ( z == -1 )
    {
      if ( g_eMode != BITMAP_FILE_TYPE_PSD )
      {
        if ( g_eMode == BITMAP_FILE_TYPE_PFM )
          V_snprintf(
            pDest: info->m_SrcName,
            maxLen: 260,
            pFormat: "%s%03d%s",
            v7,
            frameID + info->m_nStartFrame,
            ".pfm");
        else
          V_snprintf(
            pDest: info->m_SrcName,
            maxLen: 260,
            pFormat: "%s%03d%s",
            v7,
            frameID + info->m_nStartFrame,
            ".tga");
      }
      else
      {
        V_snprintf(pDest: info->m_SrcName, maxLen: 260, pFormat: "%s%03d%s", v7, frameID + info->m_nStartFrame, ".psd");
      }
    }
    else
    {
      if ( g_eMode != BITMAP_FILE_TYPE_PSD )
      {
        if ( g_eMode == BITMAP_FILE_TYPE_PFM )
          v11 = ".pfm";
        else
          v11 = ".tga";
      }
      else
      {
        v11 = ".psd";
      }
      V_snprintf(
        pDest: info->m_SrcName,
        maxLen: 260,
        pFormat: "%s%03d_z%03d%s",
        v7,
        z,
        frameID + info->m_nStartFrame,
        v11);
    }
  }
  else if ( info->m_bIsCubeMap && g_bOldCubemapPath )
  {
    if ( g_eMode != BITMAP_FILE_TYPE_PSD )
    {
      if ( g_eMode == BITMAP_FILE_TYPE_PFM )
        v12 = ".pfm";
      else
        v12 = ".tga";
    }
    else
    {
      v12 = ".psd";
    }
    V_snprintf(pDest: info->m_SrcName, maxLen: 260, pFormat: "%s%s%s", v7, g_CubemapFacingNames[faceID], v12);
  }
  else if ( z == -1 )
  {
    if ( g_eMode != BITMAP_FILE_TYPE_PSD )
    {
      if ( g_eMode == BITMAP_FILE_TYPE_PFM )
        v13 = ".pfm";
      else
        v13 = ".tga";
    }
    else
    {
      v13 = ".psd";
    }
    V_snprintf(pDest: info->m_SrcName, maxLen: 260, pFormat: "%s%s", v7, v13);
  }
  else
  {
    if ( g_eMode != BITMAP_FILE_TYPE_PSD )
    {
      if ( g_eMode == BITMAP_FILE_TYPE_PFM )
        v14 = ".pfm";
      else
        v14 = ".tga";
    }
    else
    {
      v14 = ".psd";
    }
    V_snprintf(pDest: info->m_SrcName, maxLen: 260, pFormat: "%s_z%03d%s", v7, z, v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003FF0
// Name: bool ImageGetInfo(enum BitmapFileType_t,class CUtlBuffer __near &,int __near &,int __near &,enum ImageFormat __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ImageGetInfo(
        BitmapFileType_t nMode,
        CUtlBuffer *fileBuffer,
        int *nWidth,
        int *nHeight,
        ImageFormat *imageFormat)
{
  switch ( nMode )
  {
    case BITMAP_FILE_TYPE_PSD:
      return PSDGetInfo(
               buf: fileBuffer,
               pWidth: nWidth,
               pHeight: nHeight,
               pImageFormat: imageFormat,
               pSourceGamma: (float *)&nMode);
    case BITMAP_FILE_TYPE_TGA:
      return TGALoader::GetInfo(
               buf: fileBuffer,
               width: nWidth,
               height: nHeight,
               imageFormat,
               sourceGamma: (float *)&nMode);
    case BITMAP_FILE_TYPE_PFM:
      return PFMGetInfo_AndAdvanceToTextureBits(pfmBuffer: fileBuffer, nWidth, nHeight, imageFormat);
    default:
      break;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10004060
// Name: void AdjustResForCubemap(struct VTexConfigInfo_t const __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AdjustResForCubemap(const VTexConfigInfo_t *info, int *nWidth, int *nHeight)
{
  if ( info->m_bIsCubeMap && !g_bOldCubemapPath )
  {
    if ( *nWidth % 4 != 0 || *nHeight % 3 != 0 )
      _Error(
        a1: "TGA is wrong size for cubemap - [%d,%d] after 'reduce' - should be 4x3 grid of squares\n",
        *nWidth,
        *nHeight);
    *nWidth /= 4;
    *nHeight /= 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100040E0
// Name: InitializeSrcTexture
// Source: json
//------------------------------------------------------------------------------
void __usercall InitializeSrcTexture(
        IVTFTexture *pTexture@<edi>,
        const VTexConfigInfo_t *info@<esi>,
        const char *pInputFileName,
        CUtlBuffer *fileBuffer,
        int nDepth,
        int nFrameCount)
{
  ImageFormat v6; // eax
  ImageFormat sourceFormat; // [esp+4h] [ebp-Ch] BYREF
  int nWidth; // [esp+8h] [ebp-8h] BYREF
  int nHeight; // [esp+Ch] [ebp-4h] BYREF

  if ( !ImageGetInfo(nMode: g_eMode, fileBuffer, &nWidth, &nHeight, imageFormat: &sourceFormat) )
    _Error(a1: "Cannot read texture %s\n", pInputFileName);
  nWidth /= info->m_nReduceX;
  nHeight /= info->m_nReduceY;
  AdjustResForCubemap(info, &nWidth, &nHeight);
  if ( g_eMode == BITMAP_FILE_TYPE_PFM )
  {
    if ( info->m_bDisplacementMap )
      v6 = 2 * info->m_bDisplacementWrinkleMap + 27;
    else
      v6 = IMAGE_FORMAT_RGB323232F;
  }
  else
  {
    v6 = IMAGE_FORMAT_RGBA8888;
  }
  if ( !pTexture->Init(
          this: pTexture,
          a2: nWidth,
          a3: nHeight,
          a4: nDepth,
          a5: v6,
          a6: info->m_nFlags,
          a7: nFrameCount,
          a8: -1) )
    _Error(a1: "Cannot initialize texture %s\n", pInputFileName);
}

//------------------------------------------------------------------------------
// Address: 0x100041A0
// Name: void ConvertAlphaToDistance(class IVTFTexture __near *,struct VTexConfigInfo_t const __near &,struct Bitmap_t const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertAlphaToDistance(
        IVTFTexture *pTexture,
        const VTexConfigInfo_t *info,
        const Bitmap_t *source,
        unsigned __int8 *pDest)
{
  ImageFormat v4; // eax
  int m_nReduceX; // eax
  int v6; // esi
  const Bitmap_t *v7; // ebx
  int v8; // esi
  int v9; // eax
  unsigned __int8 *m_pBits; // edx
  float v11; // xmm0_4
  int v12; // ecx
  int v13; // eax
  bool v14; // cf
  bool v15; // zf
  int v16; // eax
  int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  unsigned __int8 *v26; // esi
  float flMaxRad; // [esp+1Ch] [ebp-3Ch]
  int nOrig_y; // [esp+20h] [ebp-38h]
  int nOrig_x; // [esp+24h] [ebp-34h]
  unsigned __int8 *v30; // [esp+28h] [ebp-30h]
  int v31; // [esp+2Ch] [ebp-2Ch]
  float v32; // [esp+30h] [ebp-28h]
  int m_nWidth; // [esp+34h] [ebp-24h]
  int v34; // [esp+38h] [ebp-20h]
  int v35; // [esp+3Ch] [ebp-1Ch]
  float flOutDist; // [esp+40h] [ebp-18h]
  int iy; // [esp+44h] [ebp-14h]
  int x; // [esp+48h] [ebp-10h]
  int nSearchRad; // [esp+4Ch] [ebp-Ch]
  int y; // [esp+50h] [ebp-8h]
  bool bWarnEdges; // [esp+56h] [ebp-2h]
  bool bInOrOut; // [esp+57h] [ebp-1h]

  if ( info->m_bAlphaToDistance )
  {
    v4 = pTexture->Format(this: pTexture);
    if ( (unsigned __int8)*(_DWORD *)&ImageLoader::ImageFormatInfo(fmt: v4)->m_nNumAlphaBits != 0 )
    {
      m_nReduceX = info->m_nReduceX;
      if ( m_nReduceX <= info->m_nReduceY )
        m_nReduceX = info->m_nReduceY;
      flMaxRad = (float)(info->m_flDistanceSpread * 2.0) * (double)m_nReduceX;
      nSearchRad = (int)ceil(X: flMaxRad);
      v6 = 0;
      bWarnEdges = false;
      x = 0;
      if ( pTexture->Width(this: pTexture) > 0 )
      {
        v7 = source;
        do
        {
          y = 0;
          if ( pTexture->Height(this: pTexture) > 0 )
          {
            v32 = (float)v6;
            v35 = -nSearchRad;
            do
            {
              v8 = (int)(float)((float)((float)(v7->m_nWidth - 1) * v32) / (float)(pTexture->Width(this: pTexture) - 1));
              nOrig_x = v8;
              v9 = pTexture->Height(this: pTexture);
              m_pBits = v7->m_pBits;
              v31 = v7->m_nHeight - 1;
              v11 = 9.9999998e22;
              m_nWidth = v7->m_nWidth;
              v12 = (int)(float)((float)((float)v31 * (float)y) / (float)(v9 - 1));
              v13 = v8 + v12 * v7->m_nWidth;
              v14 = m_pBits[4 * v13 + 3] < 0xAu;
              v15 = m_pBits[4 * v13 + 3] == 10;
              v16 = -nSearchRad;
              bInOrOut = !v14 && !v15;
              nOrig_y = v12;
              v30 = m_pBits;
              iy = -nSearchRad;
              if ( v35 <= nSearchRad )
              {
                do
                {
                  v17 = -nSearchRad;
                  if ( v35 <= nSearchRad )
                  {
                    v34 = v12 + v16;
                    v18 = v8 - nSearchRad;
                    do
                    {
                      v19 = m_nWidth - 1;
                      v20 = m_nWidth - 1;
                      if ( m_nWidth - 1 >= v18 )
                        v20 = v18;
                      if ( v20 >= 0 )
                      {
                        if ( v19 >= v18 )
                          v19 = v18;
                      }
                      else
                      {
                        v19 = 0;
                      }
                      v21 = v34;
                      if ( v31 < v34 )
                        v21 = v31;
                      if ( v21 >= 0 )
                      {
                        v22 = v34;
                        if ( v31 < v34 )
                          v22 = v31;
                      }
                      else
                      {
                        v22 = 0;
                      }
                      v15 = bInOrOut == v30[4 * v19 + 3 + 4 * v22 * m_nWidth] > 0xAu;
                      v16 = iy;
                      if ( !v15 )
                      {
                        v23 = fsqrt((float)(iy * iy + v17 * v17));
                        if ( v23 <= v11 )
                          v11 = v23;
                      }
                      ++v17;
                      ++v18;
                    }
                    while ( v17 <= nSearchRad );
                    v7 = source;
                    v8 = nOrig_x;
                    v12 = nOrig_y;
                  }
                  iy = ++v16;
                }
                while ( v16 <= nSearchRad );
              }
              v24 = (float)(v11 * 0.5) / flMaxRad;
              if ( v24 > 0.5 )
                v24 = 0.5;
              flOutDist = v24;
              if ( !bInOrOut )
                flOutDist = -v24;
              v25 = (float)(flOutDist + 0.5) * 255.0;
              v26 = &pDest[4 * x + 3 + 4 * y * pTexture->Width(this: pTexture)];
              if ( v25 > 255.0 )
                v25 = 255.0;
              *v26 = (int)v25;
              if ( (unsigned __int8)(int)v25 != 0
                && (x == 0
                 || y == 0
                 || x == pTexture->Width(this: pTexture) - 1
                 || y == pTexture->Height(this: pTexture) - 1) )
              {
                bWarnEdges = true;
                *v26 = 0;
              }
              ++y;
            }
            while ( y < pTexture->Height(this: pTexture) );
            v6 = x;
          }
          x = ++v6;
        }
        while ( v6 < pTexture->Width(this: pTexture) );
        if ( bWarnEdges )
          VTexWarning(
            pFormat: "%s: There are non-zero distance pixels along the image edge. You may need to reduce your distance spread or "
            "reduce the image less or add a border to the image.\n",
            info->m_SrcName);
      }
    }
    else
    {
      VTexWarning(pFormat: "%s: alpha to distance asked for but no alpha channel.\n", info->m_SrcName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100044C0
// Name: void ExtractFaceSubrect(struct Bitmap_t __near &,struct Bitmap_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExtractFaceSubrect(Bitmap_t *srcBitmap, Bitmap_t *pDstBitmap, unsigned int nFace)
{
  int v3; // edi
  int v4; // esi
  int m_nNumBytes; // eax
  unsigned __int8 *v6; // eax
  const ImageFormatInfo_t *v7; // eax
  Rect_t faceRects[6]; // [esp+0h] [ebp-6Ch] BYREF
  Rect_t *srcRect; // [esp+60h] [ebp-Ch]
  unsigned int count; // [esp+64h] [ebp-8h]
  int v11; // [esp+68h] [ebp-4h]
  int y; // [esp+7Ch] [ebp+10h]

  if ( nFace <= 5 )
  {
    v3 = srcBitmap->m_nWidth / 4;
    v4 = srcBitmap->m_nHeight / 3;
    srcRect = &faceRects[nFace];
    faceRects[0].x = 3 * v3;
    faceRects[2].x = 2 * v3;
    faceRects[4].x = 3 * v3;
    faceRects[5].x = 3 * v3;
    faceRects[0].y = v4;
    faceRects[0].width = v3;
    faceRects[0].height = v4;
    faceRects[1].x = v3;
    faceRects[1].y = v4;
    faceRects[1].width = v3;
    faceRects[1].height = v4;
    faceRects[2].y = v4;
    faceRects[2].width = v3;
    faceRects[2].height = v4;
    faceRects[3].x = 0;
    faceRects[3].y = v4;
    faceRects[3].width = v3;
    faceRects[3].height = v4;
    faceRects[4].y = 0;
    faceRects[4].width = v3;
    faceRects[4].height = v4;
    faceRects[5].y = 2 * v4;
    faceRects[5].width = v3;
    faceRects[5].height = v4;
    if ( srcBitmap != pDstBitmap )
      Bitmap_t::Init(this: pDstBitmap, nWidth: v3, nHeight: v4, imageFormat: srcBitmap->m_ImageFormat);
    m_nNumBytes = ImageLoader::ImageFormatInfo(fmt: srcBitmap->m_ImageFormat)->m_nNumBytes;
    y = 0;
    if ( v4 > 0 )
    {
      count = v3 * m_nNumBytes;
      v11 = 0;
      do
      {
        if ( srcBitmap->m_pBits != nullptr )
        {
          v7 = ImageLoader::ImageFormatInfo(fmt: srcBitmap->m_ImageFormat);
          v6 = &srcBitmap->m_pBits[v7->m_nNumBytes * (srcRect->x + srcBitmap->m_nWidth * (y + srcRect->y))];
        }
        else
        {
          v6 = nullptr;
        }
        memcpy(dst: &pDstBitmap->m_pBits[v11], src: v6, count);
        v11 += count;
        ++y;
      }
      while ( y < v4 );
    }
    if ( srcBitmap == pDstBitmap )
    {
      pDstBitmap->m_nWidth = v3;
      pDstBitmap->m_nHeight = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100045F0
// Name: bool TGAReadFileRGBA8888(class CUtlBuffer __near &,struct Bitmap_t __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TGAReadFileRGBA8888(CUtlBuffer *fileBuffer, Bitmap_t *bitmap, float flGamma)
{
  bool result; // al
  int v4; // ebx
  unsigned __int8 *m_pBits; // eax
  int v6; // edi
  const ImageFormatInfo_t *v7; // eax
  ImageFormat sourceFormat; // [esp+14h] [ebp-10h] BYREF
  float flSrcGamma; // [esp+18h] [ebp-Ch] BYREF
  int nWidth; // [esp+1Ch] [ebp-8h] BYREF
  int nHeight; // [esp+20h] [ebp-4h] BYREF

  result = TGALoader::GetInfo(
             buf: fileBuffer,
             width: &nWidth,
             height: &nHeight,
             imageFormat: &sourceFormat,
             sourceGamma: &flSrcGamma);
  if ( result )
  {
    v4 = nWidth;
    m_pBits = bitmap->m_pBits;
    v6 = nHeight;
    if ( m_pBits != nullptr )
    {
      free(pMem: m_pBits);
      bitmap->m_pBits = nullptr;
    }
    bitmap->m_nWidth = v4;
    bitmap->m_nHeight = v6;
    bitmap->m_ImageFormat = IMAGE_FORMAT_RGBA8888;
    v7 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
    bitmap->m_pBits = (unsigned __int8 *)MemAlloc_Alloc(nSize: v6 * v4 * v7->m_nNumBytes);
    CUtlBuffer::SeekGet(this: fileBuffer, type: SEEK_HEAD, offset: 0);
    return TGALoader::Load(
             pOutputImage: bitmap->m_pBits,
             buf: fileBuffer,
             width: nWidth,
             height: nHeight,
             imageFormat: IMAGE_FORMAT_RGBA8888,
             targetGamma: flGamma,
             mipmap: false);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100046A0
// Name: void NormalInvertGreen(class IVTFTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NormalInvertGreen(IVTFTexture *pTexture)
{
  int i; // ebx
  int j; // edi
  unsigned __int8 *v4; // eax
  int v5; // ecx
  _BYTE *v6; // eax
  int nDepth; // [esp+4h] [ebp-Ch] BYREF
  int nHeight; // [esp+8h] [ebp-8h] BYREF
  int nWidth; // [esp+Ch] [ebp-4h] BYREF
  int iFrame; // [esp+18h] [ebp+8h]

  if ( pTexture->Format(this: pTexture) != IMAGE_FORMAT_RGBA8888 )
    VTexError(pFormat: "Cannot 'invert green', normal map in unexpected format\n");
  if ( pTexture->Depth(this: pTexture) > 1 )
    VTexError(pFormat: "Cannot 'invert green', normal map is a volume texture?!\n");
  for ( iFrame = 0; iFrame < pTexture->FrameCount(this: pTexture); ++iFrame )
  {
    for ( i = 0; i < pTexture->FaceCount(this: pTexture); ++i )
    {
      for ( j = 0; j < pTexture->MipCount(this: pTexture); ++j )
      {
        pTexture->ComputeMipLevelDimensions(this: pTexture, a2: j, a3: &nWidth, a4: &nHeight, a5: &nDepth);
        v4 = pTexture->ImageData_2(this: pTexture, a2: iFrame, a3: i, a4: j);
        v5 = 0;
        if ( nDepth * nHeight * nWidth > 0 )
        {
          v6 = v4 + 1;
          do
          {
            ++v5;
            *v6 = -1 - *v6;
            v6 += 4;
          }
          while ( v5 < nDepth * nHeight * nWidth );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100047C0
// Name: void PreprocessSkyBox(char __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PreprocessSkyBox(char *pFullNameWithoutExtension, int *iSkyboxFace)
{
  const char *v2; // edx
  int v3; // eax
  const char *v4; // edi
  int v5; // esi

  v2 = pFullNameWithoutExtension;
  v3 = strlen(pFullNameWithoutExtension);
  if ( v3 >= 3 )
  {
    v4 = &pFullNameWithoutExtension[v3 - 2];
    *iSkyboxFace = -1;
    v5 = 0;
    while ( _V_stricmp(s1: v4, s2: g_CubemapFacingNames[v5]) != 0 )
    {
      if ( (unsigned int)++v5 >= 7 )
        goto LABEL_7;
    }
    *iSkyboxFace = v5;
LABEL_7:
    if ( *iSkyboxFace != -1 )
    {
      *v4 = 0;
      return;
    }
    v2 = pFullNameWithoutExtension;
  }
  _Error(a1: "PreprocessSkyBox: filename %s doesn't have a proper extension (bk, dn, rt, etc..)\n", v2);
}

//------------------------------------------------------------------------------
// Address: 0x10004840
// Name: void MakeDirHier(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeDirHier(const char *pPath)
{
  unsigned int i; // esi
  char v2; // al
  char temp[1028]; // [esp+4h] [ebp-404h] BYREF

  V_strncpy(pDest: temp, pSrc: pPath, maxLen: 1024);
  for ( i = 0; i < strlen(temp); ++i )
  {
    v2 = temp[i];
    if ( v2 == 47 || v2 == 92 )
    {
      temp[i] = 0;
      mkdir(path: temp);
      temp[i] = 92;
    }
  }
  mkdir(path: temp);
}

//------------------------------------------------------------------------------
// Address: 0x100048E0
// Name: SetTextureLodData
// Source: json
//------------------------------------------------------------------------------
void __usercall SetTextureLodData(
        IVTFTexture *pTexture@<edi>,
        const VTexConfigInfo_t *info@<esi>,
        TextureLODControlSettings_t a3@<ecx>)
{
  int m_nMaxDimensionX; // eax
  unsigned __int8 i; // cl
  int m_nMaxDimensionY; // eax
  unsigned __int8 j; // cl
  int m_nMaxDimensionX_360; // eax
  unsigned __int8 k; // cl
  int m_nMaxDimensionY_360; // eax
  unsigned __int8 m; // cl
  TextureLODControlSettings_t lodChunk; // [esp+0h] [ebp-4h] BYREF

  lodChunk = a3;
  if ( info->m_nMaxDimensionX > 0
    && info->m_nMaxDimensionX < ((int (__thiscall *)(_DWORD, _DWORD))pTexture->Width)(a1: pTexture, a2: lodChunk)
    || info->m_nMaxDimensionY > 0 && info->m_nMaxDimensionY < pTexture->Height(this: pTexture)
    || info->m_nMaxDimensionX_360 > 0 && info->m_nMaxDimensionX_360 < pTexture->Width(this: pTexture)
    || info->m_nMaxDimensionY_360 > 0 && info->m_nMaxDimensionY_360 < pTexture->Height(this: pTexture) )
  {
    m_nMaxDimensionX = info->m_nMaxDimensionX;
    lodChunk = 0;
    if ( m_nMaxDimensionX > 0 )
    {
      for ( i = 0; m_nMaxDimensionX > 1; ++i )
        m_nMaxDimensionX >>= 1;
      lodChunk.m_ResolutionClampX = i;
    }
    else
    {
      lodChunk.m_ResolutionClampX = 30;
    }
    m_nMaxDimensionY = info->m_nMaxDimensionY;
    if ( m_nMaxDimensionY > 0 )
    {
      for ( j = 0; m_nMaxDimensionY > 1; ++j )
        m_nMaxDimensionY >>= 1;
      lodChunk.m_ResolutionClampY = j;
    }
    else
    {
      lodChunk.m_ResolutionClampY = 30;
    }
    m_nMaxDimensionX_360 = info->m_nMaxDimensionX_360;
    if ( m_nMaxDimensionX_360 > 0 )
    {
      for ( k = 0; m_nMaxDimensionX_360 > 1; ++k )
        m_nMaxDimensionX_360 >>= 1;
      lodChunk.m_ResolutionClampX_360 = k;
    }
    else
    {
      lodChunk.m_ResolutionClampX_360 = 30;
    }
    m_nMaxDimensionY_360 = info->m_nMaxDimensionY_360;
    if ( m_nMaxDimensionY_360 > 0 )
    {
      for ( m = 0; m_nMaxDimensionY_360 > 1; ++m )
        m_nMaxDimensionY_360 >>= 1;
      lodChunk.m_ResolutionClampY_360 = m;
    }
    else
    {
      lodChunk.m_ResolutionClampY_360 = 30;
    }
    pTexture->SetResourceData(this: pTexture, a2: 4476748u, a3: &lodChunk, a4: 4u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100049E0
// Name: char const __near * GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetPossiblyQuotedWord(char *pInBuf, char *pOutbuf)
{
  int v2; // eax
  unsigned __int8 *v3; // esi
  const char *v4; // eax
  const char *v5; // edi
  const char *v6; // eax
  const char *v7; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v3 = (unsigned __int8 *)&pInBuf[v2];
  bQuote_3 = 0;
  if ( *v3 == 34 )
  {
    strchr(string: ++v3, chr: 0x22u);
    v5 = v4;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v3, chr: 0x20u);
    v5 = v6;
    if ( v6 != nullptr )
      goto LABEL_7;
    strchr(string: v3, chr: 9u);
    v5 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    v5 = (const char *)&v3[strlen((const char *)v3)];
  }
  if ( v5 == nullptr )
    return nullptr;
LABEL_7:
  if ( v5 == (const char *)v3 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v3, count: v5 - (const char *)v3);
  pOutbuf[v5 - (const char *)v3] = 0;
  result = v5;
  if ( bQuote_3 != 0 )
    return v5 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004A90
// Name: GetKeyValueFromBuffer
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetKeyValueFromBuffer(CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v3; // ebx
  _BYTE *v4; // eax
  _BYTE *v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // esi
  bool v8; // zf
  char *v9; // eax
  char *v10; // edi
  char *v11; // eax
  char *v12; // eax
  char buf[2051]; // [esp+Ch] [ebp-804h] BYREF
  char v15; // [esp+80Fh] [ebp-1h]

  v3 = buffer;
  if ( buffer->m_nMaxPut == buffer->m_Get )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v3, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v4 != nullptr )
      *v4 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v5 != nullptr )
      *v5 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v7 = (unsigned __int8 *)&buf[v6];
    v8 = buf[v6] == 34;
    v15 = 0;
    if ( v8 )
    {
      strchr(string: ++v7, chr: 0x22u);
      v10 = v9;
      v15 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v6], chr: 0x20u);
    v10 = v11;
    if ( v11 != nullptr )
      break;
    strchr(string: v7, chr: 9u);
    v10 = v12;
    if ( v12 != nullptr )
      break;
    v10 = (char *)&v7[strlen((const char *)v7)];
LABEL_11:
    if ( v10 != nullptr )
      break;
LABEL_17:
    if ( v3->m_nMaxPut == v3->m_Get )
      goto LABEL_18;
  }
  if ( v10 == (char *)v7 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v7, count: v10 - (char *)v7);
  v8 = v15 == 0;
  key[v10 - (char *)v7] = 0;
  if ( !v8 )
    ++v10;
  if ( v10 == nullptr )
  {
    v3 = buffer;
    goto LABEL_17;
  }
  if ( GetPossiblyQuotedWord(pInBuf: v10, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004BE0
// Name: bool HasSuffix(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HasSuffix(const char *pFileName, const char *pSuffix)
{
  int v2; // esi
  int v3; // eax

  if ( pFileName == nullptr || *pFileName == 0 || pSuffix == nullptr || *pSuffix == 0 )
    return false;
  v2 = _V_strlen(str: pFileName);
  v3 = _V_strlen(str: pSuffix);
  return v2 > v3 && V_strnicmp(s1: &pFileName[v2 - v3], s2: pSuffix, n: v3) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004C40
// Name: bool GetOutputDir(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetOutputDir(const char *inputName, char *outputDir)
{
  char *v2; // ebx
  char *v3; // eax
  char buf[260]; // [esp+4h] [ebp-104h] BYREF

  if ( g_ForcedOutputDir[0] != 0 )
  {
    v2 = strcpy(outputDir, g_ForcedOutputDir);
  }
  else
  {
    V_MakeAbsolutePath(pOut: buf, outLen: 260, pPath: inputName, pStartingDir: nullptr);
    V_FixSlashes(pname: buf, separator: 92);
    v3 = V_stristr(pStr: buf, pSearch: "materialsrc\\");
    if ( v3 == nullptr )
      return 0;
    v2 = strcpy(outputDir, gamedir);
    strcat(v2, "materials/");
    strcat(v2, v3 + 12);
    V_StripFilename(path: v2);
  }
  if ( !g_Quiet )
    VTexMsg(pFormat: "Output directory: %s\n", v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004D50
// Name: bool IsCubeFromFileNames(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsCubeFromFileNames(const char *inputBaseName)
{
  const char *v1; // esi
  const char *v2; // eax
  _stat64i32 buf; // [esp+8h] [ebp-134h] BYREF
  char fileName[260]; // [esp+38h] [ebp-104h] BYREF

  V_StripExtension(in: inputBaseName, out: fileName, outSize: 260);
  v1 = &inputBaseName[_V_strlen(str: fileName)];
  V_strncat(pDest: fileName, pSrc: "rt", destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_strncat(pDest: fileName, pSrc: v1, destBufferSize: 0x104u, max_chars_to_copy: -1);
  if ( g_eMode != BITMAP_FILE_TYPE_PSD )
  {
    if ( g_eMode == BITMAP_FILE_TYPE_PFM )
      v2 = ".pfm";
    else
      v2 = ".tga";
  }
  else
  {
    v2 = ".psd";
  }
  V_strncat(pDest: fileName, pSrc: v2, destBufferSize: 0x104u, max_chars_to_copy: -1);
  return _stat64i32(name: fileName, &buf) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10004E10
// Name: int Find_Files(struct _WIN32_FIND_DATAA __near &,void __near * __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __cdecl Find_Files(_WIN32_FIND_DATAA *wfd, void **hResult, const char *basedir, const char *extension)
{
  HANDLE v4; // eax
  _WIN32_FIND_DATAA *v5; // esi
  HANDLE FirstFileA; // eax
  char subdir[260]; // [esp+Ch] [ebp-510h] BYREF
  char texturename[260]; // [esp+110h] [ebp-40Ch] BYREF
  char fname[256]; // [esp+214h] [ebp-308h] BYREF
  char filename[260]; // [esp+314h] [ebp-208h] BYREF
  char ext[260]; // [esp+418h] [ebp-104h] OVERLAPPED BYREF

  memset(filename, 0, sizeof(filename));
  v4 = *hResult;
  if ( *hResult == nullptr || v4 == (HANDLE)-1 )
  {
    v5 = wfd;
    memset(dst: (unsigned __int8 *)wfd, value: 0, count: sizeof(_WIN32_FIND_DATAA));
    memset(ext, 0, sizeof(ext));
    sprintf(string: ext, format: "%s\\*.*", basedir);
    FirstFileA = FindFirstFileA(lpFileName: ext, lpFindFileData: wfd);
    *hResult = FirstFileA;
    if ( FirstFileA == (HANDLE)-1 )
      return 0;
  }
  else
  {
    v5 = wfd;
    if ( !FindNextFileA(hFindFile: v4, lpFindFileData: wfd) )
    {
      FindClose(hFindFile: *hResult);
      *hResult = (void *)-1;
      return 0;
    }
  }
  if ( v5->cFileName[0] == 46 )
    return 2;
  if ( (v5->dwFileAttributes & 0x10) != 0 )
  {
    sprintf(string: subdir, format: "%s\\%s", basedir, v5->cFileName);
    return 2;
  }
  memset(fname, 0, sizeof(fname));
  memset(&ext[4], 0, 256);
  _splitpath(path: v5->cFileName, drive: nullptr, dir: nullptr, fname, ext: &ext[4]);
  if ( _V_stricmp(s1: &ext[4], s2: extension) != 0 )
    return 3;
  sprintf(string: filename, format: "%s\\%s.vmt", basedir, fname);
  if ( access(path: filename, amode: 0) != 0 )
  {
    memset(texturename, 0, sizeof(texturename));
    sprintf(string: texturename, format: "%s\\%s", basedir, fname);
    strlwr(string: texturename);
    strlwr(string: filename);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005010
// Name: char const __near * GetBareFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetBareFileName(const char *pszPathName)
{
  const char *i; // eax

  for ( i = &pszPathName[strlen(pszPathName) - 1]; i >= pszPathName; --i )
  {
    if ( *i == 92 )
      break;
    if ( *i == 47 )
      break;
  }
  return i + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005050
// Name: public: virtual void CVTexLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVTexLoggingListener::Log(
        CVTexLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  VTexMsg(pFormat: "%s", pMessage);
  if ( pContext->m_Severity == LS_ERROR && !g_NoPause )
  {
    printf(format: "\nHit a key to continue\n");
    getch();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100050C0
// Name: public: void CDmElement::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElement::SetName(CDmElement *this, const char *pName)
{
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pName, a3: pName);
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: this->m_Name.m_pAttribute, value: (const CUtlSymbolLarge *)&pName);
}

//------------------------------------------------------------------------------
// Address: 0x100050F0
// Name: public: void VTexConfigInfo_t::ParseOptionKey(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VTexConfigInfo_t::ParseOptionKey(VTexConfigInfo_t *this, const char *pKeyName, char *pKeyValue)
{
  int v4; // ebx
  bool v5; // zf
  int v6; // eax
  long double v7; // st7
  int v8; // edi
  const char *v9; // ebx
  int v10; // ecx
  unsigned __int8 *clrDecayGoal; // eax
  int i; // edx
  char *v13; // edi
  const char *v14; // eax
  int v15; // ebx
  int v16; // edx
  int v17; // eax
  unsigned __int8 nSteps; // [esp+20h] [ebp+8h]

  v4 = atoi(nptr: pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "skybox") == 0 )
  {
    v5 = !g_Quiet;
    this->m_bIsSkyBox = v4 != 0;
    this->m_bIsCubeMap = v4 != 0;
    if ( v5 && v4 != 0 )
      _Msg(a1: "'skybox' detected. Treating skybox like a cubemap for edge-matching purposes.\n");
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "skyboxcropped") == 0 )
  {
    this->m_bIsCroppedSkyBox = v4 != 0;
    if ( !g_Quiet && v4 != 0 )
      _Msg(a1: "'skyboxcropped' detected. Will output half-height front/back/left/right images and a 4x4 'down' image.\n");
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    this->m_bIsCubeMap = v4 != 0;
    if ( !g_Quiet && v4 != 0 )
      _Msg(a1: "'cubemap' detected.\n");
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    this->m_nStartFrame = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    this->m_nEndFrame = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    this->m_nVolumeTextureDepth = atoi(nptr: pKeyValue);
    this->m_vtfProcOptions.flags0 = this->m_vtfProcOptions.flags0 & 0xFFFFFAFF | 0x100;
    this->m_bManualMip = false;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "bumpscale") == 0 )
  {
    this->m_flBumpScale = atof(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 1u;
    else
      this->m_nFlags &= ~1u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 2u;
    else
      this->m_nFlags &= ~2u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 4u;
    else
      this->m_nFlags &= ~4u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 8u;
    else
      this->m_nFlags &= ~8u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x2000000u;
    else
      this->m_nFlags &= ~0x2000000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "border") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x20000000u;
    else
      this->m_nFlags &= ~0x20000000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x10u;
    else
      this->m_nFlags &= ~0x10u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x20u;
    else
      this->m_nFlags &= ~0x20u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    if ( v4 != 0 )
      this->m_vtfProcOptions.flags0 |= 0x100u;
    else
      this->m_vtfProcOptions.flags0 &= ~0x100u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "normal") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x80u;
    else
      this->m_nFlags &= ~0x80u;
    this->m_bManualMip = false;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "normalga") == 0 )
  {
    this->m_bNormalToDXT5GA = v4 != 0;
    if ( v4 != 0 )
      this->m_vtfProcOptions.flags0 |= 0x8000u;
    else
      this->m_vtfProcOptions.flags0 &= ~0x8000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "invertgreen") == 0 )
  {
    v5 = !g_Quiet;
    this->m_bNormalInvertGreen = v4 != 0;
    if ( v5 && v4 != 0 )
      _Msg(a1: "'invertgreen' detected, assuming this is a normal map authored in Zbrush, Modo, Crazybump, etc.\n");
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "ssbump") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x8000000u;
    else
      this->m_nFlags &= ~0x8000000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x100u;
    else
      this->m_nFlags &= ~0x100u;
    this->m_bManualMip = false;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "allmips") == 0 )
  {
    if ( v4 == 0 )
    {
      this->m_nFlags &= ~0x400u;
      return;
    }
LABEL_188:
    this->m_nFlags |= 0x400u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "mostmips") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x10000000u;
    else
      this->m_nFlags &= ~0x10000000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    if ( v4 != 0 )
      this->m_vtfProcOptions.flags0 &= ~0x400u;
    else
      this->m_vtfProcOptions.flags0 |= 0x400u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x200u;
    else
      this->m_nFlags &= ~0x200u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "procedural") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x800u;
    else
      this->m_nFlags &= ~0x800u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    if ( v4 != 0 )
      this->m_vtfProcOptions.flags0 |= 0x4000u;
    else
      this->m_vtfProcOptions.flags0 &= ~0x4000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphaThreshhold = atof(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphaHiFreqThreshhold = atof(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "rendertarget") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x8000u;
    else
      this->m_nFlags &= ~0x8000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    this->m_numChannelsMax = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x20000u;
    else
      this->m_nFlags &= ~0x20000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "singlecopy") == 0 )
  {
    if ( v4 != 0 )
      this->m_nFlags |= 0x40000u;
    else
      this->m_nFlags &= ~0x40000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "oneovermiplevelinalpha") == 0 )
  {
    if ( v4 != 0 )
      this->m_vtfProcOptions.flags0 |= 0x1000u;
    else
      this->m_vtfProcOptions.flags0 &= ~0x1000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "premultalphabymiplevelfraction") == 0 )
  {
    if ( v4 != 0 )
      this->m_vtfProcOptions.flags0 |= 0x10000u;
    else
      this->m_vtfProcOptions.flags0 &= ~0x10000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "premultalphabymiplevelfraction_maxalphamiplevel") == 0 )
  {
    this->m_vtfProcOptions.fullAlphaAtMipLevel = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "premultalphabymiplevelfraction_minalphaperpixel") == 0 )
  {
    this->m_vtfProcOptions.minAlpha = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "premultcolorbyoneovermiplevel") == 0 )
  {
    if ( v4 != 0 )
      this->m_vtfProcOptions.flags0 |= 0x2000u;
    else
      this->m_vtfProcOptions.flags0 &= ~0x2000u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "normaltodudv") == 0 )
  {
    this->m_bNormalToDuDv = v4 != 0;
    if ( v4 != 0 )
      this->m_vtfProcOptions.flags0 |= 0x200u;
    else
      this->m_vtfProcOptions.flags0 &= ~0x200u;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "stripalphachannel") == 0 )
  {
    this->m_bStripAlphaChannel = v4 != 0;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "stripcolorchannel") == 0 )
  {
    this->m_bStripColorChannel = v4 != 0;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "normalalphatodudvluminance") == 0 )
  {
    this->m_bAlphaToLuminance = v4 != 0;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dudv") == 0 )
  {
    this->m_bDuDv = v4 != 0;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "reduce") == 0 )
  {
    v6 = atoi(nptr: pKeyValue);
    this->m_nReduceX = v6;
    this->m_nReduceY = v6;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "reducex") == 0 )
  {
    this->m_nReduceX = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "reducey") == 0 )
  {
    this->m_nReduceY = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "maxwidth") == 0 )
  {
    this->m_nMaxDimensionX = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "maxwidth_360") == 0 )
  {
    this->m_nMaxDimensionX_360 = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "maxheight") == 0 )
  {
    this->m_nMaxDimensionY = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "maxheight_360") == 0 )
  {
    this->m_nMaxDimensionY_360 = atoi(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatodistance") == 0 )
  {
    this->m_bAlphaToDistance = v4 != 0;
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "distancespread") == 0 )
  {
    this->m_flDistanceSpread = atof(nptr: pKeyValue);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pfmscale") == 0 )
  {
    v7 = atof(nptr: pKeyValue);
    this->m_pfmscale = v7;
    VTexMsg(pFormat: "pfmscale = %.2f\n", (double)v7);
    return;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pfm") != 0 )
  {
    if ( _V_stricmp(s1: pKeyName, s2: "displacementwrinkle") == 0 )
    {
      this->m_bDisplacementWrinkleMap = true;
      return;
    }
    if ( _V_stricmp(s1: pKeyName, s2: "specvar") == 0 )
    {
      v8 = -1;
      if ( _V_stricmp(s1: pKeyValue, s2: "red") == 0 || _V_stricmp(s1: pKeyValue, s2: "r") == 0 )
        v8 = 0;
      if ( _V_stricmp(s1: pKeyValue, s2: "green") == 0 || _V_stricmp(s1: pKeyValue, s2: "g") == 0 )
        v8 = 1;
      if ( _V_stricmp(s1: pKeyValue, s2: "blue") == 0 || _V_stricmp(s1: pKeyValue, s2: "b") == 0 )
        v8 = 2;
      if ( _V_stricmp(s1: pKeyValue, s2: "alpha") != 0 && _V_stricmp(s1: pKeyValue, s2: "a") != 0 )
      {
        if ( v8 < 0 )
          return;
      }
      else
      {
        v8 = 3;
      }
      this->m_vtfProcOptions.flags0 |= 17 << v8;
      this->m_vtfProcOptions.numNotDecayMips[v8] = 0;
      this->m_vtfProcOptions.clrDecayGoal[v8] = 0;
      this->m_vtfProcOptions.fDecayExponentBase[v8] = 0.75;
      this->m_bManualMip = false;
      goto LABEL_188;
    }
    if ( _V_stricmp(s1: pKeyName, s2: "manualmip") != 0 )
    {
      if ( _V_stricmp(s1: pKeyName, s2: "mipblend") != 0 )
      {
        if ( _V_stricmp(s1: pKeyName, s2: "srgb") != 0 )
          VTexError(pFormat: "unrecognized option in text file - %s\n", pKeyName);
      }
      else
      {
        v9 = pKeyValue;
        this->m_nFlags |= 0x400u;
        if ( _V_stricmp(s1: pKeyValue, s2: "detail") != 0 )
        {
          nSteps = 0;
          v13 = pKeyValue;
          if ( pKeyValue != nullptr )
          {
            while ( 1 )
            {
              v14 = StringAfterPrefix(str: v13, prefix: "skip=");
              if ( v14 != nullptr )
              {
                v13 = (char *)v14;
                nSteps = atoi(nptr: v14);
              }
              else if ( StringHasPrefix(str: v13, prefix: "r=")
                     || StringHasPrefix(str: v13, prefix: "g=")
                     || StringHasPrefix(str: v13, prefix: "b=")
                     || StringHasPrefix(str: v13, prefix: "a=") )
              {
                v15 = 0;
                switch ( *v13 )
                {
                  case 'A':
                  case 'a':
                    v15 = 3;
                    break;
                  case 'B':
                  case 'b':
                    v15 = 2;
                    break;
                  case 'G':
                  case 'g':
                    v15 = 1;
                    break;
                  default:
                    break;
                }
                v13 += 2;
                this->m_vtfProcOptions.flags0 = ~(16 << v15) & (this->m_vtfProcOptions.flags0 | (1 << v15));
                this->m_vtfProcOptions.numNotDecayMips[v15] = nSteps;
                this->m_vtfProcOptions.clrDecayGoal[v15] = atoi(nptr: v13);
                if ( isdigit(c: *v13) != 0 )
                {
                  do
                    v16 = *++v13;
                  while ( isdigit(c: v16) != 0 );
                }
                if ( (*v13 == 101 || *v13 == 69) && v13[1] == 46 )
                {
                  this->m_vtfProcOptions.flags0 |= 16 << v15;
                  this->m_vtfProcOptions.fDecayExponentBase[v15] = atof(nptr: v13 + 1);
                }
              }
              else
              {
                VTexWarning(pFormat: "invalid mipblend setting \"%s\"\n", v9);
              }
              strchr(string: (unsigned __int8 *)v13, chr: 0x3Au);
              if ( v17 == 0 )
                break;
              v13 = (char *)(v17 + 1);
              if ( v17 == -1 )
                break;
              v9 = pKeyValue;
            }
          }
        }
        else
        {
          v10 = 1;
          clrDecayGoal = this->m_vtfProcOptions.clrDecayGoal;
          for ( i = 3; i != 0; --i )
          {
            this->m_vtfProcOptions.flags0 |= v10;
            clrDecayGoal[4] = 2;
            *clrDecayGoal++ = 0x80;
            v10 = __ROL4__(v10, 1);
          }
        }
      }
    }
    else if ( this->m_nVolumeTextureDepth == 1 && (this->m_nFlags & 0x180) == 0 )
    {
      this->m_bManualMip = true;
    }
  }
  else if ( v4 != 0 )
  {
    g_eMode = BITMAP_FILE_TYPE_PFM;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005F00
// Name: public: static bool CSuggestGameDirHelper::SuggestFn(class CFSSteamSetupInfo const __near *,char __near *,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CSuggestGameDirHelper::SuggestFn(
        const CFSSteamSetupInfo *pFsSteamSetupInfo,
        char *pchPathBuffer,
        int nBufferLength,
        bool *pbBubbleDirectories)
{
  if ( g_suggestGameDirHelper.m_numInputFiles == 0 || g_suggestGameDirHelper.m_pszInputFiles == nullptr )
    return 0;
  if ( pbBubbleDirectories != nullptr )
    *pbBubbleDirectories = true;
  if ( g_suggestGameDirHelper.m_numInputFiles == 0 )
    return 0;
  V_MakeAbsolutePath(
    pOut: pchPathBuffer,
    outLen: nBufferLength,
    pPath: *g_suggestGameDirHelper.m_pszInputFiles,
    pStartingDir: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005F50
// Name: public: virtual int CVTex::main(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVTex::main(CVTex *this, int argc, char **argv)
{
  int v3; // eax

  v3 = *((_DWORD *)this - 1);
  g_bUsedAsLaunchableDLL = true;
  return (*(int (__thiscall **)(char *, int, char **))(v3 + 4))(a1: (char *)this - 4, a2: argc, a3: argv);
}

//------------------------------------------------------------------------------
// Address: 0x10005F70
// Name: public: virtual int CVTex::VTex(void __near * (*)(char const __near *,int __near *),char const __near *,int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVTex::VTex(
        CVTex *this,
        void *(__cdecl *fsFactory)(const char *, int *),
        const char *pGameDir,
        int argc,
        char **argv)
{
  IFileSystem *v6; // eax

  v6 = (IFileSystem *)fsFactory(a1: "VFileSystem017", a2: nullptr);
  g_pFullFileSystem = v6;
  if ( v6 == nullptr )
  {
    g_pFileSystem = nullptr;
    goto LABEL_3;
  }
  g_pFileSystem = &v6->IBaseFileSystem;
  if ( v6 == (IFileSystem *)-4 )
  {
LABEL_3:
    _Error(a1: "IVTex3::VTex - fsFactory can't get '%s' interface.", "VFileSystem017");
    return 0;
  }
  V_strncpy(pDest: gamedir, pSrc: pGameDir, maxLen: 1024);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
  return this->VTex_2(this, a2: argc, a3: argv);
}

//------------------------------------------------------------------------------
// Address: 0x10006080
// Name: public: void CUtlMemory<struct OutputTexture_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OutputTexture_t,int>::Grow(CUtlMemory<OutputTexture_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  OutputTexture_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 264 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OutputTexture_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (OutputTexture_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006120
// Name: public: char const __near * CDmElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmElement::GetName(CDmElement *this)
{
  const char *result; // eax

  result = this->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006130
// Name: ComputeDesiredImageFormat_0
// Source: json
//------------------------------------------------------------------------------
ImageFormat __usercall ComputeDesiredImageFormat_0@<eax>(
        CDmePrecompiledTexture *pPrecompiledTexture@<edi>,
        CDmeTexture *pTexture@<esi>)
{
  ImageFormat v2; // eax
  bool v3; // bl

  v2 = CDmeTexture::Format(this: pTexture);
  v3 = ImageLoader::ImageFormatInfo(fmt: v2)->m_nNumAlphaBits != 0;
  if ( CDmeTexture::Format(this: pTexture) == IMAGE_FORMAT_RGB323232F )
  {
    if ( !g_bUsedAsLaunchableDLL || pPrecompiledTexture->m_bNoCompression.m_Storage )
      return IMAGE_FORMAT_RGBA16161616F;
    else
      return IMAGE_FORMAT_BGRA8888;
  }
  else if ( CDmeTexture::Format(this: pTexture) == IMAGE_FORMAT_R32F
         || CDmeTexture::Format(this: pTexture) == IMAGE_FORMAT_RGBA32323232F
         || CDmeTexture::Format(this: pTexture) == IMAGE_FORMAT_UV88
         || CDmeTexture::Format(this: pTexture) == IMAGE_FORMAT_UVLX8888
         || CDmeTexture::Format(this: pTexture) == IMAGE_FORMAT_UVWQ8888 )
  {
    return CDmeTexture::Format(this: pTexture);
  }
  else if ( pPrecompiledTexture->m_bNoCompression.m_Storage
         || CDmeTexture::Width(this: pTexture) < 4
         || CDmeTexture::Height(this: pTexture) < 4 )
  {
    return 4 * !v3 + 12;
  }
  else if ( pPrecompiledTexture->m_bHintDxt5Compression.m_Storage )
  {
    return IMAGE_FORMAT_DXT5;
  }
  else
  {
    return 2 * v3 + 13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006210
// Name: void MakeSrcFileName(class CDmePrecompiledTexture __near *,char const __near *,int,int,int,int,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeSrcFileName(
        CDmePrecompiledTexture *pTexture,
        const char *pSrcName,
        int nFrameID,
        int nFaceID,
        int nMipLevel,
        int z,
        char *pFullPath,
        unsigned int nBufLen)
{
  const char *FileExtension; // ebx
  char pFullNameWithoutExtension[260]; // [esp+8h] [ebp-114h] BYREF
  char pRight[16]; // [esp+10Ch] [ebp-10h] BYREF
  char bAnimated_3; // [esp+127h] [ebp+Bh]

  FileExtension = V_GetFileExtension(path: pSrcName);
  V_StripExtension(in: pSrcName, out: pFullNameWithoutExtension, outSize: 260);
  if ( pTexture->m_nStartFrame.m_Storage == -1 || (bAnimated_3 = 1, pTexture->m_nEndFrame.m_Storage == -1) )
    bAnimated_3 = 0;
  if ( nMipLevel > 0 )
  {
    pFullNameWithoutExtension[_V_strlen(str: pFullNameWithoutExtension) - 1] = 0;
    V_snprintf(pDest: pRight, maxLen: 16, pFormat: "%d", nMipLevel);
    V_strncat(pDest: pFullNameWithoutExtension, pSrc: pRight, destBufferSize: 0x104u, max_chars_to_copy: -1);
  }
  if ( bAnimated_3 != 0 )
  {
    if ( z == -1 )
      V_snprintf(
        pDest: pFullPath,
        maxLen: nBufLen,
        pFormat: "%s%03d.%s",
        pFullNameWithoutExtension,
        nFrameID + pTexture->m_nStartFrame.m_Storage,
        FileExtension);
    else
      V_snprintf(
        pDest: pFullPath,
        maxLen: nBufLen,
        pFormat: "%s%03d_z%03d.%s",
        pFullNameWithoutExtension,
        z,
        nFrameID + pTexture->m_nStartFrame.m_Storage,
        FileExtension);
  }
  else if ( z == -1 )
  {
    V_snprintf(pDest: pFullPath, maxLen: nBufLen, pFormat: "%s.%s", pFullNameWithoutExtension, FileExtension);
  }
  else
  {
    V_snprintf(pDest: pFullPath, maxLen: nBufLen, pFormat: "%s_z%03d.%s", pFullNameWithoutExtension, z, FileExtension);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006340
// Name: public: virtual void CBaseAppSystem<class IResourceCompiler>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IResourceCompiler>::Reconnect(
        CBaseAppSystem<IDmSerializers> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x100063C0
// Name: public: CP4AutoEditFile::CP4AutoEditFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CP4AutoEditFile *__thiscall CP4AutoEditFile::CP4AutoEditFile(CP4AutoEditFile *this, const char *szFilename)
{
  CP4File *v3; // eax

  v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename);
  this->m_spImpl.m_p = v3;
  v3->Edit(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100063F0
// Name: public: CP4AutoAddFile::CP4AutoAddFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CP4AutoAddFile *__thiscall CP4AutoAddFile::CP4AutoAddFile(CP4AutoAddFile *this, const char *szFilename)
{
  CP4File *v3; // eax

  v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename);
  this->m_spImpl.m_p = v3;
  v3->Add(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006420
// Name: LoadFaceFromFile
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadFaceFromFile@<al>(
        IVTFTexture *pTexture@<esi>,
        CUtlBuffer *fileBuffer@<eax>,
        int z,
        int nFrame,
        int nFace,
        int nMipLevel,
        float flGamma,
        const VTexConfigInfo_t *info)
{
  bool v10; // al
  unsigned __int8 *v12; // eax
  bool v13; // zf
  unsigned __int8 *v14; // edi
  ImageFormat v15; // eax
  int m_nNumBytes; // ecx
  int (__thiscall *Height)(IVTFTexture *); // eax
  int v18; // edi
  int v19; // eax
  unsigned int v20; // edi
  unsigned __int8 *v21; // edi
  IVTFTexture_vtbl *v22; // edx
  int (__thiscall *Width)(IVTFTexture *); // eax
  int v24; // eax
  IVTFTexture_vtbl *v25; // edx
  int v26; // eax
  ImageFormat v27; // eax
  int m_nWidth; // [esp-Ch] [ebp-9Ch]
  int v29; // [esp-Ch] [ebp-9Ch]
  int m_nHeight; // [esp-8h] [ebp-98h]
  int v31; // [esp-8h] [ebp-98h]
  float pfmScale; // [esp+0h] [ebp-90h]
  int nMipLevelDepth; // [esp+18h] [ebp-78h] BYREF
  ImageLoader::ResampleInfo_t resInfo; // [esp+1Ch] [ebp-74h] BYREF
  int nMipLevelHeight; // [esp+70h] [ebp-20h] BYREF
  int texelSize; // [esp+74h] [ebp-1Ch]
  int nMipLevelWidth; // [esp+78h] [ebp-18h] BYREF
  unsigned __int8 *pDestBits; // [esp+7Ch] [ebp-14h]
  Bitmap_t bitmap; // [esp+80h] [ebp-10h] BYREF
  ImageFormat bitmapFormat; // [esp+ACh] [ebp+1Ch]

  bitmap.m_nWidth = 0;
  bitmap.m_nHeight = 0;
  bitmap.m_ImageFormat = IMAGE_FORMAT_UNKNOWN;
  bitmap.m_pBits = nullptr;
  if ( g_eMode == BITMAP_FILE_TYPE_PFM )
  {
    if ( info->m_bDisplacementMap )
      bitmapFormat = 2 * info->m_bDisplacementWrinkleMap + 27;
    else
      bitmapFormat = IMAGE_FORMAT_RGB323232F;
  }
  else
  {
    bitmapFormat = IMAGE_FORMAT_RGBA8888;
  }
  CUtlBuffer::SeekGet(this: fileBuffer, type: SEEK_HEAD, offset: 0);
  if ( g_eMode != BITMAP_FILE_TYPE_PSD )
  {
    if ( g_eMode == BITMAP_FILE_TYPE_TGA )
    {
      v10 = TGAReadFileRGBA8888(fileBuffer, &bitmap, flGamma);
    }
    else
    {
      if ( g_eMode != BITMAP_FILE_TYPE_PFM )
      {
LABEL_17:
        if ( bitmap.m_pBits != nullptr )
          free(pMem: bitmap.m_pBits);
        return 0;
      }
      pfmScale = info->m_pfmscale;
      if ( info->m_bDisplacementMap )
      {
        if ( info->m_bDisplacementWrinkleMap )
          v10 = PFMReadFileRGBA32323232F(fileBuffer, &bitmap, pfmScale);
        else
          v10 = PFMReadFileR32F(fileBuffer, &bitmap, pfmScale);
      }
      else
      {
        v10 = PFMReadFileRGB323232F(fileBuffer, &bitmap, pfmScale);
      }
    }
  }
  else
  {
    v10 = PSDReadFileRGBA8888(buf: fileBuffer, &bitmap);
  }
  if ( !v10 )
    goto LABEL_17;
  if ( info->m_bIsCubeMap && !g_bOldCubemapPath )
    ExtractFaceSubrect(srcBitmap: &bitmap, pDstBitmap: &bitmap, nFace);
  pTexture->ComputeMipLevelDimensions(
    this: pTexture,
    a2: nMipLevel,
    a3: &nMipLevelWidth,
    a4: &nMipLevelHeight,
    a5: &nMipLevelDepth);
  if ( bitmap.m_nWidth != nMipLevelWidth * info->m_nReduceX || bitmap.m_nHeight != nMipLevelHeight * info->m_nReduceY )
    VTexError(pFormat: "'manualmip' source image wrong size for mip %d! (%s)\n", nMipLevel, info->m_SrcName);
  v12 = pTexture->ImageData(this: pTexture, a2: nFrame, a3: nFace, a4: nMipLevel, a5: 0, a6: 0, a7: z);
  v13 = !info->m_bAlphaToDistance;
  v14 = v12;
  pDestBits = v12;
  if ( v13 && info->m_nReduceX == 1 && info->m_nReduceY == 1 )
  {
    m_nHeight = bitmap.m_nHeight;
    m_nWidth = bitmap.m_nWidth;
    v15 = pTexture->Format(this: pTexture);
    ImageLoader::ConvertImageFormat(
      src: bitmap.m_pBits,
      srcImageFormat: bitmapFormat,
      dst: v14,
      dstImageFormat: v15,
      width: m_nWidth,
      height: m_nHeight,
      srcStride: 0,
      dstStride: 0);
  }
  else
  {
    m_nNumBytes = ImageLoader::ImageFormatInfo(fmt: bitmap.m_ImageFormat)->m_nNumBytes;
    Height = pTexture->Height;
    texelSize = m_nNumBytes;
    v18 = Height(this: pTexture);
    v19 = pTexture->Width(this: pTexture);
    v20 = texelSize * v19 * v18;
    if ( v20 != 0 )
      v21 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v20);
    else
      v21 = nullptr;
    resInfo.m_nSrcDepth = 1;
    resInfo.m_nDestDepth = 1;
    resInfo.m_flAlphaThreshhold = 0.40000001;
    resInfo.m_flAlphaHiFreqThreshhold = 0.40000001;
    resInfo.m_nSrcWidth = bitmap.m_nWidth;
    v22 = pTexture->__vftable;
    resInfo.m_flColorScale[0] = 1.0;
    resInfo.m_flColorScale[1] = 1.0;
    resInfo.m_flColorScale[2] = 1.0;
    resInfo.m_flColorScale[3] = 1.0;
    resInfo.m_pSrc = bitmap.m_pBits;
    resInfo.m_nSrcHeight = bitmap.m_nHeight;
    Width = v22->Width;
    resInfo.m_nFlags = 0;
    memset(resInfo.m_flColorGoal, 0, sizeof(resInfo.m_flColorGoal));
    resInfo.m_pDest = v21;
    v24 = Width(this: pTexture);
    v25 = pTexture->__vftable;
    resInfo.m_nDestWidth = v24;
    v26 = v25->Height(this: pTexture);
    v13 = (info->m_vtfProcOptions.flags0 & 0x400) == 0;
    resInfo.m_nDestHeight = v26;
    resInfo.m_flSrcGamma = flGamma;
    resInfo.m_flDestGamma = flGamma;
    if ( !v13 )
      resInfo.m_nFlags |= 4u;
    if ( bitmapFormat != IMAGE_FORMAT_RGBA8888 )
    {
      if ( bitmapFormat == IMAGE_FORMAT_RGB323232F )
        ImageLoader::ResampleRGB323232F(info: &resInfo);
    }
    else
    {
      ImageLoader::ResampleRGBA8888(info: &resInfo);
    }
    ConvertAlphaToDistance(pTexture, info, source: &bitmap, pDest: v21);
    v31 = pTexture->Height(this: pTexture);
    v29 = pTexture->Width(this: pTexture);
    v27 = pTexture->Format(this: pTexture);
    ImageLoader::ConvertImageFormat(
      src: v21,
      srcImageFormat: bitmapFormat,
      dst: pDestBits,
      dstImageFormat: v27,
      width: v29,
      height: v31,
      srcStride: 0,
      dstStride: 0);
    if ( v21 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
  }
  if ( bitmap.m_pBits != nullptr )
    free(pMem: bitmap.m_pBits);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006760
// Name: LoadFace
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadFace@<al>(
        int nFace@<ecx>,
        int a2@<eax>,
        float a3@<xmm0>,
        IVTFTexture *pTexture,
        CUtlBuffer *tgaBuffer,
        int z,
        int nFrame,
        const VTexConfigInfo_t *info)
{
  char result; // al
  int m_numChannelsMax; // eax
  ImageFormat v11; // eax
  ImageFormat v12; // eax
  const ImageFormatInfo_t *v13; // eax
  int v14; // eax
  unsigned __int8 *v15; // edi
  int v16; // eax
  int v17; // ecx
  unsigned int v18; // esi
  unsigned __int8 *v19; // edi
  int v20; // ebx
  int v21; // [esp+4h] [ebp-18h]
  int nWidth; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  result = LoadFaceFromFile(pTexture, fileBuffer: tgaBuffer, z, nFrame, nFace, nMipLevel: a2, flGamma: a3, info);
  if ( result == 0 )
    return result;
  m_numChannelsMax = info->m_numChannelsMax;
  if ( m_numChannelsMax < 1 || m_numChannelsMax > 4 )
  {
    VTexWarning(
      pFormat: "%s: Invalid setting restricting number of channels to %d, discarded!\n",
      info->m_SrcName,
      info->m_numChannelsMax);
    return 1;
  }
  if ( m_numChannelsMax >= 4 )
    return 1;
  v11 = pTexture->Format(this: pTexture);
  if ( ImageLoader::ImageFormatInfo(fmt: v11)->m_nNumBytes != 4 )
  {
    v12 = pTexture->Format(this: pTexture);
    v13 = ImageLoader::ImageFormatInfo(fmt: v12);
    v14 = ((int (__thiscall *)(IVTFTexture *, _DWORD))pTexture->Format)(a1: pTexture, a2: v13->m_nNumBytes);
    VTexWarning(
      pFormat: "%s: Channels restricted to %d, but cannot fill white because pixel format is %d (size in bytes %d)! Proceeding wit"
      "h unmodified channels.\n",
      info->m_SrcName,
      info->m_numChannelsMax,
      v14,
      v21);
    return 1;
  }
  v15 = pTexture->ImageData(this: pTexture, a2: nFrame, a3: nFace, a4: 0, a5: 0, a6: 0, a7: z);
  nWidth = pTexture->Width(this: pTexture);
  v16 = pTexture->Height(this: pTexture);
  v17 = info->m_numChannelsMax;
  v18 = 4 - v17;
  v19 = &v15[v17];
  if ( v16 <= 0 )
    return 1;
  for ( i = v16; i != 0; --i )
  {
    v20 = nWidth;
    if ( nWidth > 0 )
    {
      do
      {
        memset(dst: v19, value: 0xFFu, count: v18);
        v19 += 4;
        --v20;
      }
      while ( v20 != 0 );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100068A0
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100068D0
// Name: InitializeImageArray
// Source: json
//------------------------------------------------------------------------------
CDmePrecompiledTexture *__usercall InitializeImageArray@<eax>(
        Bitmap_t *pBitmap@<eax>,
        CDmePrecompiledTexture *pPrecompiledTexture)
{
  Bitmap_t *v2; // esi
  int m_nWidth; // edx
  CDmePrecompiledTexture *v4; // eax
  bool v5; // zf
  int m_nHeight; // edi
  int m_Storage; // ecx
  float v8; // xmm0_4
  signed int v9; // edi
  Bitmap_t *v10; // ebx
  DmElementHandle_t v11; // eax
  CDmElement *v12; // eax
  DmElementHandle_t v13; // eax
  CDmElement *v14; // eax
  CDmeImage *v15; // edi
  int v16; // edi
  int *v17; // esi
  void *v18; // eax
  int v20; // ebx
  unsigned __int8 *m_pMemory; // eax
  const void **v22; // edi
  unsigned __int8 *v23; // esi
  int v24; // edi
  int *p_j; // esi
  void *v26; // eax
  Bitmap_t cubeBitmaps[6]; // [esp+3Ch] [ebp-88h] BYREF
  int v28; // [esp+9Ch] [ebp-28h]
  ImageFormat fmt; // [esp+A0h] [ebp-24h]
  float flGamma; // [esp+A4h] [ebp-20h]
  int j; // [esp+A8h] [ebp-1Ch] BYREF
  int i; // [esp+ACh] [ebp-18h]
  int nHeight; // [esp+B0h] [ebp-14h]
  unsigned __int8 **p_m_pBits; // [esp+B4h] [ebp-10h]
  int nWidth; // [esp+B8h] [ebp-Ch]
  int nDepth; // [esp+BCh] [ebp-8h]
  int nFaceCount; // [esp+C0h] [ebp-4h]
  CDmePrecompiledTexture *pPrecompiledTexturea; // [esp+CCh] [ebp+8h]

  v2 = pBitmap;
  m_nWidth = pBitmap->m_nWidth;
  fmt = pBitmap->m_ImageFormat;
  v4 = pPrecompiledTexture;
  v5 = !pPrecompiledTexture->m_bNormalMap.m_Storage;
  m_nHeight = v2->m_nHeight;
  nFaceCount = pPrecompiledTexture->m_nTextureArraySize.m_Storage;
  m_Storage = pPrecompiledTexture->m_nVolumeTextureDepth.m_Storage;
  nWidth = m_nWidth;
  nHeight = m_nHeight;
  nDepth = m_Storage;
  if ( v5 )
    v8 = 2.2;
  else
    v8 = 1.0;
  v5 = pPrecompiledTexture->m_nTextureType.m_Storage == 1;
  cubeBitmaps[0].m_ImageFormat = IMAGE_FORMAT_UNKNOWN;
  cubeBitmaps[1].m_ImageFormat = IMAGE_FORMAT_UNKNOWN;
  cubeBitmaps[2].m_ImageFormat = IMAGE_FORMAT_UNKNOWN;
  cubeBitmaps[3].m_ImageFormat = IMAGE_FORMAT_UNKNOWN;
  cubeBitmaps[4].m_ImageFormat = IMAGE_FORMAT_UNKNOWN;
  cubeBitmaps[5].m_ImageFormat = IMAGE_FORMAT_UNKNOWN;
  flGamma = v8;
  cubeBitmaps[0].m_nWidth = 0;
  cubeBitmaps[0].m_nHeight = 0;
  cubeBitmaps[0].m_pBits = nullptr;
  cubeBitmaps[1].m_nWidth = 0;
  cubeBitmaps[1].m_nHeight = 0;
  cubeBitmaps[1].m_pBits = nullptr;
  cubeBitmaps[2].m_nWidth = 0;
  cubeBitmaps[2].m_nHeight = 0;
  cubeBitmaps[2].m_pBits = nullptr;
  cubeBitmaps[3].m_nWidth = 0;
  cubeBitmaps[3].m_nHeight = 0;
  cubeBitmaps[3].m_pBits = nullptr;
  cubeBitmaps[4].m_nWidth = 0;
  cubeBitmaps[4].m_nHeight = 0;
  cubeBitmaps[4].m_pBits = nullptr;
  cubeBitmaps[5].m_nWidth = 0;
  cubeBitmaps[5].m_nHeight = 0;
  cubeBitmaps[5].m_pBits = nullptr;
  if ( !v5 )
    goto LABEL_10;
  if ( m_nWidth % 4 == 0 )
  {
    if ( m_nHeight % 3 == 0 )
    {
      nWidth /= 4;
      nHeight = m_nHeight / 3;
      v9 = 0;
      v10 = cubeBitmaps;
      do
        ExtractFaceSubrect(srcBitmap: v2, pDstBitmap: v10++, nFace: v9++);
      while ( v9 < 6 );
      v4 = pPrecompiledTexture;
      nFaceCount = 6;
      v2 = cubeBitmaps;
LABEL_10:
      v11 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
              a1: g_pDataModel,
              a2: (CUtlSymbolLarge)CDmeImageArray::m_classType.u.m_Id,
              a3: "mip",
              a4: v4->m_fileId,
              a5: nullptr);
      v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: v11);
      if ( v12 == nullptr
        || (pPrecompiledTexturea = (CDmePrecompiledTexture *)v12, !v12->IsA(this: v12, a2: CDmeImageArray::m_classType)) )
      {
        pPrecompiledTexturea = nullptr;
      }
      if ( nFaceCount > 0 )
      {
        v28 = 16 * nDepth;
        p_m_pBits = &v2->m_pBits;
        for ( i = nFaceCount; i != 0; --i )
        {
          v13 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
                  a1: g_pDataModel,
                  a2: (CUtlSymbolLarge)CDmeImage::m_classType.u.m_Id,
                  a3: "image",
                  a4: pPrecompiledTexturea->m_fileId,
                  a5: nullptr);
          v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: v13);
          v15 = (CDmeImage *)v14;
          if ( v14 != nullptr && v14->IsA(this: v14, a2: CDmeImage::m_classType) )
          {
            nFaceCount = (int)v15;
          }
          else
          {
            nFaceCount = 0;
            v15 = nullptr;
          }
          CDmeImage::Init(this: v15, nWidth, nHeight, nDepth, fmt, flGamma);
          v20 = CDmeImage::ZSliceSizeInBytes(this: v15);
          m_pMemory = CDmeImage::BeginModification(this: v15)->m_Memory.m_pMemory;
          if ( nDepth > 0 )
          {
            v22 = (const void **)p_m_pBits;
            v23 = m_pMemory;
            p_m_pBits = (unsigned __int8 **)((char *)p_m_pBits + v28);
            for ( j = nDepth; j != 0; --j )
            {
              _V_memcpy(dest: v23, src: *v22, count: v20);
              v23 += v20;
              v22 += 4;
            }
            v15 = (CDmeImage *)nFaceCount;
          }
          CDmeImage::EndModification(this: v15);
          CDmeImageArray::AddImage(this: (CDmeImageArray *)pPrecompiledTexturea, pImage: v15);
        }
      }
      v24 = 5;
      p_j = &j;
      do
      {
        v26 = (void *)*(p_j - 4);
        p_j -= 4;
        if ( v26 != nullptr )
        {
          free(pMem: v26);
          *p_j = 0;
        }
        --v24;
      }
      while ( v24 >= 0 );
      return pPrecompiledTexturea;
    }
    m_nWidth = nWidth;
  }
  VTexError(pFormat: "TGA is wrong size for cubemap - [%d,%d] - should be 4x3 grid of squares!\n", m_nWidth, m_nHeight);
  v16 = 5;
  v17 = &j;
  do
  {
    v18 = (void *)*(v17 - 4);
    v17 -= 4;
    if ( v18 != nullptr )
    {
      free(pMem: v18);
      *v17 = 0;
    }
    --v16;
  }
  while ( v16 >= 0 );
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006BC0
// Name: public: CP4AutoAddFile::~CP4AutoAddFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4AutoAddFile::~CP4AutoAddFile(CP4AutoEditFile *this)
{
  CP4File *m_p; // ecx

  m_p = this->m_spImpl.m_p;
  this->m_spImpl.m_p = nullptr;
  if ( m_p != nullptr )
    ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10006BE0
// Name: SetTextureStateFromPrecompiledTexture
// Source: json
//------------------------------------------------------------------------------
void __usercall SetTextureStateFromPrecompiledTexture(
        CDmePrecompiledTexture *pPrecompiledTexture@<eax>,
        CDmeTexture *pTexture@<esi>)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmAttribute::SetValue<bool>(this: pTexture->m_bClampS.m_pAttribute, value: &pPrecompiledTexture->m_bClampS.m_Storage);
  CDmAttribute::SetValue<bool>(this: pTexture->m_bClampT.m_pAttribute, value: &pPrecompiledTexture->m_bClampT.m_Storage);
  CDmAttribute::SetValue<bool>(this: pTexture->m_bClampU.m_pAttribute, value: &pPrecompiledTexture->m_bClampU.m_Storage);
  CDmAttribute::SetValue<bool>(
    this: pTexture->m_bNoDebugOverride.m_pAttribute,
    value: &pPrecompiledTexture->m_bNoDebugOverride.m_Storage);
  CDmAttribute::SetValue<bool>(this: pTexture->m_bNoLod.m_pAttribute, value: &pPrecompiledTexture->m_bNoLod.m_Storage);
  CDmAttribute::SetValue<bool>(
    this: pTexture->m_bNormalMap.m_pAttribute,
    value: &pPrecompiledTexture->m_bNormalMap.m_Storage);
  m_pAttribute = pTexture->m_nFilterType.m_pAttribute;
  value = pPrecompiledTexture->m_nFilterType.m_Storage;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
  CDmAttribute::SetValue<float>(
    this: pTexture->m_flBumpScale.m_pAttribute,
    value: &pPrecompiledTexture->m_flBumpScale.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x10006C70
// Name: public: class CDmeTP_ComputeMipmaps __near * CDmePrecompiledTexture::AddProcessor<class CDmeTP_ComputeMipmaps>(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CDmePrecompiledTexture::AddProcessor<CDmeTP_ComputeMipmaps>(
        CDmePrecompiledTexture *this,
        int pName)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CVTFTexture *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTP_ComputeMipmaps::m_classType.u.m_Id,
         a3: (const char *)pName,
         a4: this->m_fileId,
         a5: nullptr);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = (CVTFTexture *)v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeTP_ComputeMipmaps::m_classType) )
  {
    pName = CVTFTexture::MipCount(this: v5);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Processors,
      src: (const DmElementHandle_t *)&pName);
    return v5;
  }
  else
  {
    pName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Processors,
      src: (const DmElementHandle_t *)&pName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006D00
// Name: public: void CDmeTexture::ForEachImage<void,enum ImageFormat,enum ImageFormat>(void (CDmeImage::*)(enum ImageFormat),enum ImageFormat const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::ForEachImage<void,enum ImageFormat,enum ImageFormat>(
        CDmeTexture *this,
        void (__thiscall *pfnProxied)(CDmeImage *this, ImageFormat),
        ImageFormat *arg1)
{
  CDmeTexture *v3; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  CVTFTexture *v6; // esi
  int v7; // eax
  int v8; // ecx
  CVTFTexture *MipLevel; // eax
  CDmeImageArray *v10; // edi
  int v11; // ebx
  int i; // esi
  CDmeImage *Image; // eax
  int nFrameCount; // [esp+Ch] [ebp-18h]
  int nMipCount; // [esp+14h] [ebp-10h]
  int f; // [esp+18h] [ebp-Ch]
  int m; // [esp+1Ch] [ebp-8h]
  CDmElement *v19; // [esp+20h] [ebp-4h]

  v3 = this;
  v4 = 0;
  nFrameCount = this->m_Frames.m_Storage.m_Size;
  f = 0;
  if ( nFrameCount > 0 )
  {
    do
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Frames.m_Storage.m_Memory.m_pMemory[v4]);
      v6 = (CVTFTexture *)v5;
      v19 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTextureFrame::m_classType) )
      {
        v7 = CVTFTexture::LowResWidth(this: v6);
        v8 = 0;
        nMipCount = v7;
        m = 0;
        if ( v7 > 0 )
        {
          do
          {
            MipLevel = (CVTFTexture *)CDmeTextureFrame::GetMipLevel(this: (CDmeTextureFrame *)v6, nIndex: v8);
            v10 = (CDmeImageArray *)MipLevel;
            if ( MipLevel != nullptr )
            {
              v11 = CVTFTexture::LowResWidth(this: MipLevel);
              for ( i = 0; i < v11; ++i )
              {
                Image = CDmeImageArray::GetImage(this: v10, nIndex: i);
                if ( Image != nullptr )
                  pfnProxied(this: Image, a2: *arg1);
              }
              v6 = (CVTFTexture *)v19;
            }
            v8 = m + 1;
            m = v8;
          }
          while ( v8 < nMipCount );
          v4 = f;
          v3 = this;
        }
      }
      f = ++v4;
    }
    while ( v4 < nFrameCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006DF0
// Name: public: int CUtlVector<struct OutputTexture_t,class CUtlMemory<struct OutputTexture_t,int>>::InsertBefore(int,struct OutputTexture_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<OutputTexture_t,CUtlMemory<OutputTexture_t,int>>::InsertBefore(
        CUtlVector<OutputTexture_t,CUtlMemory<OutputTexture_t,int> > *this,
        int elem,
        const OutputTexture_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  OutputTexture_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<OutputTexture_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 264 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006E70
// Name: LoadFile
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadFile@<al>(CUtlBuffer *buf@<edi>, const char *pFileName, bool bFailOnError, unsigned int *puiHash)
{
  _iobuf *v4; // eax
  _iobuf *v5; // esi
  int v7; // ebx
  int v8; // ebx
  CP4File *v9; // esi

  v4 = fopen(file: pFileName, mode: "rb");
  v5 = v4;
  if ( v4 != nullptr )
  {
    fseek(stream: v4, offset: 0, whence: 2);
    v7 = ftell(stream: v5);
    fseek(stream: v5, offset: 0, whence: 0);
    CUtlBuffer::EnsureCapacity(this: buf, num: v7);
    v8 = fread(buffer: buf->m_Memory.m_pMemory, elementSize: 1u, count: v7, stream: v5);
    fclose(stream: v5);
    CUtlBuffer::SeekPut(this: buf, type: SEEK_HEAD, offset: v8);
    v9 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pFileName);
    v9->Add(this: v9);
    ((void (__thiscall *)(CP4File *, int))v9->dtr_CP4File)(a1: v9, a2: 1);
    if ( puiHash != nullptr )
      CRC32_ProcessBuffer(pulCRC: puiHash, pBuffer: buf->m_Memory.m_pMemory, nBuffer: v8);
    return 1;
  }
  else
  {
    if ( bFailOnError )
      VTexError(pFormat: "Can't open: \"%s\"\n", pFileName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006F30
// Name: LoadSourceImages
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadSourceImages(IVTFTexture *pTexture, char *pFullNameWithoutExtension, VTexConfigInfo_t *info)
{
  unsigned int v4; // eax
  const char *v5; // ecx
  void *v6; // esp
  const char *v7; // eax
  const char *v8; // esi
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  int m_nEndFrame; // eax
  int m_nVolumeTextureDepth; // eax
  int v14; // edx
  int v15; // esi
  int v16; // ecx
  int v17; // eax
  unsigned int *p_m_uiInputHash; // eax
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v20; // ecx
  char v22; // [esp-1h] [ebp-61h] BYREF
  char v23[12]; // [esp+0h] [ebp-60h] BYREF
  CUtlBuffer fileBuffer; // [esp+Ch] [ebp-54h] BYREF
  int nFaceCount; // [esp+3Ch] [ebp-24h]
  char *pInputFileName; // [esp+40h] [ebp-20h]
  BOOL bFailOnError; // [esp+44h] [ebp-1Ch]
  int nMipCount; // [esp+48h] [ebp-18h]
  int nFrameCount; // [esp+4Ch] [ebp-14h]
  int iFrame; // [esp+50h] [ebp-10h]
  int iFace; // [esp+54h] [ebp-Ch]
  int iMip; // [esp+58h] [ebp-8h]
  int z; // [esp+5Ch] [ebp-4h]
  bool bIsVolumeTexture_3; // [esp+73h] [ebp+13h]

  v4 = strlen(pFullNameWithoutExtension);
  if ( g_eMode != BITMAP_FILE_TYPE_PSD )
  {
    if ( g_eMode == BITMAP_FILE_TYPE_PFM )
      v5 = ".pfm";
    else
      v5 = ".tga";
  }
  else
  {
    v5 = ".psd";
  }
  v6 = alloca(strlen(v5) + v4 + 1);
  pInputFileName = v23;
  strcpy(v23, pFullNameWithoutExtension);
  if ( g_eMode != BITMAP_FILE_TYPE_PSD )
  {
    if ( g_eMode == BITMAP_FILE_TYPE_PFM )
      v7 = ".pfm";
    else
      v7 = ".tga";
  }
  else
  {
    v7 = ".psd";
  }
  v8 = v7;
  v9 = strlen(v7) + 1;
  v10 = &v22;
  do
    v11 = *++v10;
  while ( v11 != 0 );
  qmemcpy(v10, v8, v9);
  if ( info->m_nStartFrame == -1 || (m_nEndFrame = info->m_nEndFrame) == -1 )
    nFrameCount = 1;
  else
    nFrameCount = m_nEndFrame - info->m_nStartFrame + 1;
  m_nVolumeTextureDepth = info->m_nVolumeTextureDepth;
  bIsVolumeTexture_3 = m_nVolumeTextureDepth > 1;
  v14 = info->m_bIsCubeMap ? 6 : 1;
  v15 = 1;
  nFaceCount = v14;
  nMipCount = 1;
  iFrame = 0;
  if ( nFrameCount <= 0 )
    return 1;
  while ( 1 )
  {
    iFace = 0;
    if ( v14 > 0 )
      break;
LABEL_47:
    if ( ++iFrame >= nFrameCount )
      return 1;
  }
  while ( 1 )
  {
    v16 = 0;
    iMip = 0;
    if ( v15 > 0 )
      break;
LABEL_46:
    if ( ++iFace >= v14 )
      goto LABEL_47;
  }
  while ( 1 )
  {
    z = 0;
    if ( m_nVolumeTextureDepth > 0 )
      break;
LABEL_45:
    iMip = ++v16;
    if ( v16 >= v15 )
      goto LABEL_46;
  }
  LOBYTE(bFailOnError) = v16 == 0;
  while ( 1 )
  {
    if ( bIsVolumeTexture_3 )
      v17 = z;
    else
      v17 = -1;
    MakeSrcFileName(info, pFullNameWithoutExtension, frameID: iFrame, faceID: iFace, mipLevel: v16, z: v17);
    CUtlBuffer::CUtlBuffer(this: &fileBuffer, growSize: 0, initSize: 0, nFlags: 0);
    if ( g_eMode != BITMAP_FILE_TYPE_PSD )
      p_m_uiInputHash = &info->m_uiInputHash;
    else
      p_m_uiInputHash = nullptr;
    if ( LoadFile(buf: &fileBuffer, pFileName: info->m_SrcName, bFailOnError, puiHash: p_m_uiInputHash) != 0 )
    {
      if ( pTexture->ImageData_3(this: pTexture) == nullptr )
      {
        InitializeSrcTexture(
          pTexture,
          info,
          pInputFileName: info->m_SrcName,
          &fileBuffer,
          nDepth: info->m_nVolumeTextureDepth,
          nFrameCount);
        if ( info->m_bManualMip )
          nMipCount = pTexture->MipCount(this: pTexture);
        else
          nMipCount = 1;
      }
      if ( LoadFace(nFace: iFace, a2: iMip, a3: 2.2, pTexture, tgaBuffer: &fileBuffer, z, nFrame: iFrame, info) == 0 )
        _Error(a1: "Cannot load texture %s\n", pInputFileName);
      if ( fileBuffer.m_Memory.m_nGrowSize < 0 )
        goto LABEL_43;
      m_pMemory = fileBuffer.m_Memory.m_pMemory;
      if ( fileBuffer.m_Memory.m_pMemory == nullptr )
        goto LABEL_43;
      v20 = _g_pMemAlloc;
      goto LABEL_42;
    }
    if ( bFailOnError )
      break;
    if ( fileBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = fileBuffer.m_Memory.m_pMemory;
      if ( fileBuffer.m_Memory.m_pMemory == nullptr )
        goto LABEL_43;
      v20 = _g_pMemAlloc;
LABEL_42:
      v20->Free_2(this: v20, a2: m_pMemory);
    }
LABEL_43:
    m_nVolumeTextureDepth = info->m_nVolumeTextureDepth;
    ++z;
    v16 = iMip;
    if ( z >= m_nVolumeTextureDepth )
    {
      v14 = nFaceCount;
      v15 = nMipCount;
      goto LABEL_45;
    }
  }
  if ( fileBuffer.m_Memory.m_nGrowSize >= 0 && fileBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007220
// Name: LoadBitmaps
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadBitmaps(
        CDmePrecompiledTexture *pPrecompiledTexture,
        const char *pFullPath,
        int mode,
        int nFrame,
        Bitmap_t *nMip,
        Bitmap_t *pBitmaps)
{
  int m_Storage; // eax
  int v8; // ecx
  Bitmap_t *v10; // esi
  int v11; // eax
  char pSrcFile[260]; // [esp+Ch] [ebp-148h] BYREF
  CUtlBuffer fileBuffer; // [esp+110h] [ebp-44h] BYREF
  int nFaceCount; // [esp+140h] [ebp-14h]
  BOOL bFailOnError; // [esp+144h] [ebp-10h]
  int iFace; // [esp+148h] [ebp-Ch]
  int z; // [esp+14Ch] [ebp-8h]
  int nBitmapIndex; // [esp+150h] [ebp-4h]
  bool bIsVolumeTexture_3; // [esp+15Fh] [ebp+Bh]

  m_Storage = pPrecompiledTexture->m_nVolumeTextureDepth.m_Storage;
  v8 = pPrecompiledTexture->m_nTextureArraySize.m_Storage;
  bIsVolumeTexture_3 = m_Storage > 1;
  nFaceCount = v8;
  nBitmapIndex = 0;
  iFace = 0;
  if ( v8 <= 0 )
    return 1;
  while ( 1 )
  {
    z = 0;
    if ( m_Storage > 0 )
      break;
LABEL_22:
    if ( ++iFace >= v8 )
      return 1;
  }
  LOBYTE(bFailOnError) = nFrame == 0;
  v10 = &nMip[nBitmapIndex];
  while ( 1 )
  {
    if ( bIsVolumeTexture_3 )
      v11 = z;
    else
      v11 = -1;
    MakeSrcFileName(
      pTexture: pPrecompiledTexture,
      pSrcName: pFullPath,
      nFrameID: mode,
      nFaceID: iFace,
      nMipLevel: nFrame,
      z: v11,
      pFullPath: pSrcFile,
      nBufLen: 0x104u);
    CUtlBuffer::CUtlBuffer(this: &fileBuffer, growSize: 0, initSize: 0, nFlags: 0);
    if ( LoadFile(buf: &fileBuffer, pFileName: pSrcFile, bFailOnError, puiHash: (unsigned int *)pBitmaps) == 0 )
    {
      if ( bFailOnError )
        goto LABEL_29;
      goto LABEL_17;
    }
    if ( LoadBitmapFile(buf: &fileBuffer, pBitmap: v10) == BITMAP_FILE_TYPE_UNKNOWN )
      break;
    if ( nBitmapIndex > 0
      && (nMip->m_nWidth != v10->m_nWidth
       || nMip->m_nHeight != v10->m_nHeight
       || nMip->m_ImageFormat != v10->m_ImageFormat) )
    {
      VTexError(pFormat: "Found inconsistent sizes or color formats in texture faces\\z slices!\n");
LABEL_29:
      if ( fileBuffer.m_Memory.m_nGrowSize >= 0 && fileBuffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
      return 0;
    }
    ++nBitmapIndex;
    ++v10;
LABEL_17:
    if ( fileBuffer.m_Memory.m_nGrowSize >= 0 && fileBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
    m_Storage = pPrecompiledTexture->m_nVolumeTextureDepth.m_Storage;
    if ( ++z >= m_Storage )
    {
      v8 = nFaceCount;
      goto LABEL_22;
    }
  }
  VTexError(pFormat: "Cannot load texture %s\n", pSrcFile);
  if ( fileBuffer.m_Memory.m_nGrowSize >= 0 && fileBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100073F0
// Name: LoadSourceImages_0
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadSourceImages_0@<al>(
        const char *pFullDir@<edx>,
        CDmePrecompiledTexture *pPrecompiledTexture@<edi>,
        Bitmap_t *mode)
{
  const char *m_pAsString; // eax
  int m_Storage; // ecx
  int v5; // eax
  int v6; // esi
  void *v7; // esp
  CDmeTexture *v8; // eax
  CDmePrecompiledTexture *v9; // esi
  int v10; // eax
  int v12; // [esp-8h] [ebp-12Ch]
  int v13; // [esp-4h] [ebp-128h]
  unsigned __int8 v14[8]; // [esp+0h] [ebp-124h] BYREF
  char pFullPath[260]; // [esp+8h] [ebp-11Ch] BYREF
  CDmeTextureFrame *pFrame; // [esp+10Ch] [ebp-18h]
  int iMip; // [esp+110h] [ebp-14h]
  int nMipCount; // [esp+114h] [ebp-10h]
  int nFrameCount; // [esp+118h] [ebp-Ch]
  int iFrame; // [esp+11Ch] [ebp-8h]
  bool bComputedMipCount; // [esp+123h] [ebp-1h]

  m_pAsString = pPrecompiledTexture->m_ImageFileName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  V_ComposeFileName(path: pFullDir, filename: m_pAsString, dest: pFullPath, destSize: 260);
  m_Storage = pPrecompiledTexture->m_nStartFrame.m_Storage;
  if ( m_Storage == -1 || (v5 = pPrecompiledTexture->m_nEndFrame.m_Storage) == -1 )
    nFrameCount = 1;
  else
    nFrameCount = v5 - m_Storage + 1;
  v6 = 16 * pPrecompiledTexture->m_nTextureArraySize.m_Storage * pPrecompiledTexture->m_nVolumeTextureDepth.m_Storage;
  bComputedMipCount = false;
  nMipCount = 1;
  v7 = alloca(v6);
  memset(dst: v14, value: 0, count: v6);
  iFrame = 0;
  if ( nFrameCount <= 0 )
    return 1;
  while ( 1 )
  {
    v8 = (CDmeTexture *)g_pDataModel->GetElement(
                          this: g_pDataModel,
                          a2: pPrecompiledTexture->m_pSourceTexture.m_Storage.m_Handle);
    pFrame = CDmeTexture::AddFrame(this: v8);
    iMip = 0;
    if ( nMipCount > 0 )
      break;
LABEL_14:
    if ( ++iFrame >= nFrameCount )
      return 1;
  }
  while ( LoadBitmaps(pPrecompiledTexture, pFullPath, mode: iFrame, nFrame: iMip, nMip: (Bitmap_t *)v14, pBitmaps: mode) != 0 )
  {
    v9 = InitializeImageArray(pBitmap: (Bitmap_t *)v14, pPrecompiledTexture);
    CDmeTextureFrame::AddMipLevel(this: pFrame, pImages: (CDmeImageArray *)v9);
    if ( !bComputedMipCount && pPrecompiledTexture->m_bLoadMipLevels.m_Storage )
    {
      v13 = CDmeImageArray::Depth(this: (CDmeImageArray *)v9);
      v12 = CDmeImageArray::Height(this: (CDmeImageArray *)v9);
      v10 = CDmeImageArray::Width(this: (CDmeImageArray *)v9);
      nMipCount = ImageLoader::GetNumMipMapLevels(width: v10, height: v12, depth: v13);
      bComputedMipCount = true;
    }
    if ( ++iMip >= nMipCount )
      goto LABEL_14;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007550
// Name: AttachShtFile
// Source: json
//------------------------------------------------------------------------------
void __usercall AttachShtFile(
        const char *pFullNameWithoutExtension@<eax>,
        IVTFTexture *pTexture@<esi>,
        unsigned int *puiHash)
{
  char shtName[260]; // [esp+0h] [ebp-134h] BYREF
  CUtlBuffer buf; // [esp+104h] [ebp-30h] BYREF

  V_strncpy(pDest: shtName, pSrc: pFullNameWithoutExtension, maxLen: 260);
  V_SetExtension(path: shtName, extension: ".sht", pathStringLength: 260);
  if ( access(path: shtName, amode: 0) == 0 )
  {
    VTexMsg(pFormat: "Attaching .sht file %s.\n", shtName);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    if ( LoadFile(&buf, pFileName: shtName, bFailOnError: false, puiHash) != 0 )
      pTexture->SetResourceData(this: pTexture, a2: 16u, a3: buf.m_Memory.m_pMemory, a4: buf.m_Put);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007610
// Name: LoadConfigFromPSD
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadConfigFromPSD@<al>(
        const char *pFileName@<esi>,
        CUtlBuffer *buf,
        bool bMissingConfigOk,
        unsigned int *pCRC)
{
  CUtlBuffer bufFile; // [esp+8h] [ebp-5Ch] BYREF
  PSDImageResources::ResElement v6; // [esp+38h] [ebp-2Ch] BYREF
  PSDResFileInfo resFileInfo; // [esp+44h] [ebp-20h] BYREF
  PSDResFileInfo::ResFileInfoElement descr; // [esp+50h] [ebp-14h] BYREF
  PSDImageResources imgres; // [esp+5Ch] [ebp-8h] BYREF

  CUtlBuffer::CUtlBuffer(this: &bufFile, growSize: 0, initSize: 0, nFlags: 0);
  if ( LoadFile(buf: &bufFile, pFileName, bFailOnError: false, puiHash: pCRC) == 0 )
  {
    VTexError(pFormat: "VTex: \"%s\" is not a valid PSD file!\n", pFileName);
    if ( bufFile.m_Memory.m_nGrowSize >= 0 && bufFile.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufFile.m_Memory.m_pMemory);
    return 0;
  }
  VTexMsg(pFormat: "config file %s\n", pFileName);
  if ( !IsPSDFile(buf: &bufFile) )
  {
    VTexError(pFormat: "VTex: \"%s\" is not a valid PSD file!\n", pFileName);
    if ( bufFile.m_Memory.m_nGrowSize >= 0 && bufFile.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufFile.m_Memory.m_pMemory);
      return 1;
    }
    return 1;
  }
  PSDGetImageResources(result: &imgres, buf: &bufFile);
  resFileInfo = (PSDResFileInfo)*PSDImageResources::FindElement(this: &imgres, result: &v6, eType: eResFileInfo);
  PSDResFileInfo::FindElement(this: &resFileInfo, result: &descr, eType: eDescription);
  if ( descr.m_pvData != nullptr )
  {
    CUtlBuffer::EnsureCapacity(this: buf, num: descr.m_numBytes);
    CUtlBuffer::Put(this: buf, pMem: descr.m_pvData, size: descr.m_numBytes);
    if ( bufFile.m_Memory.m_nGrowSize >= 0 && bufFile.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufFile.m_Memory.m_pMemory);
    return 1;
  }
  if ( !bMissingConfigOk )
    VTexError(pFormat: "VTex: \"%s\" does not contain vtex configuration info!\n", pFileName);
  CUtlBuffer::~CUtlBuffer(this: &bufFile);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007770
// Name: LoadConfigFile
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadConfigFile(char *pFileBaseName, VTexConfigInfo_t *info)
{
  unsigned int v2; // ebx
  void *v3; // esp
  const char *v4; // esi
  int v5; // eax
  bool v7; // al
  int v8; // eax
  bool v9; // al
  VTexConfigInfo_t *v10; // esi
  const char *v11; // ecx
  const char *v12; // eax
  _iobuf *v13; // eax
  _iobuf *v14; // eax
  _iobuf *v15; // eax
  _iobuf *v16; // eax
  _iobuf *v17; // eax
  _iobuf *v18; // eax
  char v19[12]; // [esp+0h] [ebp-1040h] BYREF
  char key[2048]; // [esp+Ch] [ebp-1034h] BYREF
  char val[2048]; // [esp+80Ch] [ebp-834h] BYREF
  CUtlBuffer buf; // [esp+100Ch] [ebp-34h] BYREF
  bool v23; // [esp+103Eh] [ebp-2h]
  char v24; // [esp+103Fh] [ebp-1h]

  v24 = 0;
  v2 = strlen(pFileBaseName);
  v3 = alloca(v2 + 5);
  v4 = strcpy(v19, pFileBaseName);
  strcpy(&v19[v2], ".tga");
  v5 = access(path: v19, amode: 0);
  v23 = v5 == 0;
  if ( v5 == 0 )
  {
    if ( g_bNoTga )
      goto LABEL_15;
    strcpy(&v19[v2], ".txt");
    g_eMode = BITMAP_FILE_TYPE_TGA;
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    v24 = LoadFile(&buf, pFileName: v19, bFailOnError: false, puiHash: &info->m_uiInputHash);
    if ( v24 != 0 )
    {
      VTexMsg(pFormat: "Config file %s\n", v19);
      while ( GetKeyValueFromBuffer(buffer: &buf, key, val) != 0 )
        VTexConfigInfo_t::ParseOptionKey(this: info, pKeyName: key, pKeyValue: val);
      if ( val[0] != 0 )
        goto LABEL_7;
      if ( g_eMode == BITMAP_FILE_TYPE_PFM )
        VTexWarning(pFormat: "%s specifies PFM, but TGA with same name also exists - possible ambiguity?\n", v19);
    }
    else
    {
      strcpy(&v19[v2], ".tga");
      v24 = 1;
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  if ( g_bNoTga )
  {
LABEL_15:
    if ( v23 )
      VTexWarningNoPause(pFormat: "-notga disables \"%s\"\n", v19);
  }
  strcpy(&v19[v2], ".psd");
  v7 = access(path: v19, amode: 0) == 0;
  if ( v24 != 0 )
    goto LABEL_27;
  if ( !v7 )
    goto LABEL_32;
  if ( g_bNoPsd || g_bUsePfm )
  {
LABEL_27:
    if ( v7 && !g_bUsePfm )
    {
      if ( v24 != 0 )
      {
        VTexWarningNoPause(
          pFormat: "psd file \"%s\" exists, but not used, delete tga and txt files to use psd file directly\n",
          v19);
      }
      else if ( g_bNoPsd )
      {
        VTexWarningNoPause(pFormat: "-nopsd disables \"%s\"\n", v19);
      }
    }
  }
  else
  {
    g_eMode = BITMAP_FILE_TYPE_PSD;
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    v24 = LoadConfigFromPSD(pFileName: v4, &buf, bMissingConfigOk: true, pCRC: &info->m_uiInputHash);
    if ( buf.m_nMaxPut > 0 )
    {
      while ( GetKeyValueFromBuffer(buffer: &buf, key, val) != 0 )
        VTexConfigInfo_t::ParseOptionKey(this: info, pKeyName: key, pKeyValue: val);
      if ( val[0] != 0 )
        goto LABEL_7;
    }
    CUtlBuffer::~CUtlBuffer(this: &buf);
  }
LABEL_32:
  strcpy(&v19[v2], ".pfm");
  v8 = access(path: v19, amode: 0);
  strcpy(&v19[v2], ".txt");
  v23 = v8 == 0;
  v9 = access(path: v19, amode: 0) == 0;
  if ( v24 == 0 && v9 )
  {
    g_eMode = v23 + 1;
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    v24 = LoadFile(&buf, pFileName: v19, bFailOnError: false, puiHash: &info->m_uiInputHash);
    if ( v24 != 0 )
    {
      VTexMsg(pFormat: "Config file %s\n", v19);
      while ( GetKeyValueFromBuffer(buffer: &buf, key, val) != 0 )
        VTexConfigInfo_t::ParseOptionKey(this: info, pKeyName: key, pKeyValue: val);
      if ( val[0] != 0 )
      {
LABEL_7:
        VTexError(pFormat: "%s: %s\n", v19, val);
        CUtlBuffer::~CUtlBuffer(this: &buf);
        return 0;
      }
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  if ( g_eMode == BITMAP_FILE_TYPE_PFM )
  {
    v10 = info;
    if ( g_bUsedAsLaunchableDLL )
    {
      if ( (info->m_vtfProcOptions.flags0 & 0x100) == 0 )
        info->m_nFlags |= 0x100u;
      if ( !HasSuffix(pFileName: pFileBaseName, pSuffix: "_hdr")
        && !HasSuffix(pFileName: pFileBaseName, pSuffix: "_disp") )
      {
        VTexWarning(pFormat: "PFM files should be suffixed with '_hdr' or '_disp'\n");
      }
    }
  }
  else
  {
    if ( g_bUsedAsLaunchableDLL && HasSuffix(pFileName: pFileBaseName, pSuffix: "hdr") )
      VTexWarning(pFormat: "Only HDR images (.PFM files) should be suffixed with 'hdr'\n");
    v10 = info;
  }
  if ( v24 != 0 )
  {
    if ( (v10->m_bNormalToDuDv || (v10->m_vtfProcOptions.flags0 & 0x200) != 0)
      && (v10->m_vtfProcOptions.flags0 & 0x2000) == 0 )
    {
      VTexMsg(pFormat: "Implicitly setting premultcolorbyoneovermiplevel since you are generating a dudv map\n");
      v10->m_vtfProcOptions.flags0 |= 0x2000u;
    }
    if ( v10->m_bNormalToDuDv || (v10->m_vtfProcOptions.flags0 & 0x200) != 0 )
    {
      VTexMsg(pFormat: "Implicitly setting trilinear since you are generating a dudv map\n");
      v10->m_nFlags |= 2u;
    }
    if ( V_stristr(pStr: pFileBaseName, pSearch: "_normal") != nullptr && SLOBYTE(v10->m_nFlags) >= 0 )
    {
      if ( !g_Quiet )
      {
        v13 = __iob_func();
        VTexMsgEx(
          fout: v13 + 2,
          pFormat: "Implicitly setting:\n\t\"normal\" \"1\"\nsince filename ends in \"_normal\"\n");
      }
      v10->m_nFlags |= 0x80u;
    }
    if ( V_stristr(pStr: pFileBaseName, pSearch: "ssbump") != nullptr && (v10->m_nFlags & 0x8000000) == 0 )
    {
      if ( !g_Quiet )
      {
        v14 = __iob_func();
        VTexMsgEx(
          fout: v14 + 2,
          pFormat: "Implicitly setting:\n\t\"ssbump\" \"1\"\nsince filename includes \"ssbump\"\n");
      }
      v10->m_nFlags |= 0x8000000u;
    }
    if ( V_stristr(pStr: pFileBaseName, pSearch: "_dudv") != nullptr && !v10->m_bNormalToDuDv && !v10->m_bDuDv )
    {
      if ( !g_Quiet )
      {
        v15 = __iob_func();
        VTexMsgEx(
          fout: v15 + 2,
          pFormat: "Implicitly setting:\n"
          "\t\"dudv\" \"1\"\n"
          "since filename ends in \"_dudv\"\n"
          "If you are trying to convert from a normal map to a dudv map, put \"normaltodudv\" \"1\" in description.\n");
      }
      v10->m_bDuDv = true;
    }
    if ( V_stristr(pStr: pFileBaseName, pSearch: "_disp") != nullptr && !v10->m_bDisplacementMap )
    {
      v10->m_bDisplacementMap = true;
      if ( (v10->m_vtfProcOptions.flags0 & 0x400) != 0 && !g_Quiet )
      {
        v16 = __iob_func();
        VTexMsgEx(fout: v16 + 2, pFormat: "Implicitly disabling nice filtering\n");
      }
      v10->m_vtfProcOptions.flags0 &= ~0x400u;
      if ( (v10->m_nFlags & 0x100) == 0 && !g_Quiet )
      {
        v17 = __iob_func();
        VTexMsgEx(fout: v17 + 2, pFormat: "Implicitly disabling mip map generation\n");
      }
      v10->m_nFlags &= ~0x100u;
    }
    if ( SLOBYTE(v10->m_nFlags) < 0 || v10->m_bIsCubeMap )
    {
      if ( (v10->m_vtfProcOptions.flags0 & 0x400) != 0 && !g_Quiet )
      {
        v18 = __iob_func();
        VTexMsgEx(fout: v18 + 2, pFormat: "Implicitly disabling nice filtering\n");
      }
      v10->m_vtfProcOptions.flags0 &= ~0x400u;
    }
    return 1;
  }
  else
  {
    v11 = defaultValue;
    if ( !g_bNoTga )
      v11 = "TGA or ";
    v12 = defaultValue;
    if ( !g_bNoPsd )
      v12 = "PSD or ";
    VTexWarning(pFormat: " \"%s\" does not specify valid %s%sPFM+TXT files!\n", pFileBaseName, v12, v11);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007E20
// Name: LoadConfigFile_0
// Source: json
//------------------------------------------------------------------------------
CDmePrecompiledTexture *__usercall LoadConfigFile_0@<eax>(
        int a1@<edi>,
        char *pFullPath,
        BitmapFileType_t *pMode,
        unsigned int *pInputHash)
{
  char *v4; // esi
  const char *FileExtension; // eax
  const char *v6; // ebx
  CDmePrecompiledTexture *v8; // edi
  const char *v9; // eax
  unsigned __int8 *m_pMemory; // eax
  bool v11; // zf
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *m_pAsString; // eax
  CDmaString *p_m_ImageFileName; // ebx
  const char *m_Id; // eax
  const char *v19; // eax
  int v20; // ebx
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // ebx
  int v24; // esi
  const char *v25; // eax
  const char *v26; // eax
  char pTextureName[260]; // [esp+8h] [ebp-698h] BYREF
  char pTestFileTest[260]; // [esp+10Ch] [ebp-594h] BYREF
  char pTempPath[260]; // [esp+210h] [ebp-490h] BYREF
  char pTestFile[260]; // [esp+314h] [ebp-38Ch] BYREF
  char pFileBase[260]; // [esp+418h] [ebp-288h] BYREF
  char pTexFile[260]; // [esp+51Ch] [ebp-184h] BYREF
  CUtlBuffer buf; // [esp+620h] [ebp-80h] BYREF
  CUtlBuffer v35; // [esp+650h] [ebp-50h] BYREF
  char *pTestExt[3]; // [esp+680h] [ebp-20h]
  DmElementHandle_t v37; // [esp+68Ch] [ebp-14h] BYREF
  DmElementHandle_t hElement; // [esp+690h] [ebp-10h]
  const char *pOrigFullPath; // [esp+694h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+698h] [ebp-8h] BYREF
  bool bIsImportedFile; // [esp+69Eh] [ebp-2h]
  bool bConfigFileSpecified; // [esp+69Fh] [ebp-1h]

  v4 = pFullPath;
  FileExtension = V_GetFileExtension(path: pFullPath);
  v6 = FileExtension;
  if ( FileExtension == nullptr )
  {
    VTexError(pFormat: "VTex: Bogus file name \"%s\"!\n", pFullPath);
    return nullptr;
  }
  pOrigFullPath = pFullPath;
  if ( _V_stricmp(s1: FileExtension, s2: "txt") == 0
    || (bConfigFileSpecified = false, _V_stricmp(s1: v6, s2: "tex") == 0) )
  {
    bConfigFileSpecified = true;
  }
  v8 = nullptr;
  *pMode = BITMAP_FILE_TYPE_UNKNOWN;
  if ( _V_stricmp(s1: v6, s2: "tga") == 0 || _V_stricmp(s1: v6, s2: "pfm") == 0 )
  {
    *pMode = (_V_stricmp(s1: v6, s2: "tga") != 0) + 1;
    V_strncpy(pDest: pTexFile, pSrc: pFullPath, maxLen: 260);
    V_SetExtension(path: pTexFile, extension: "tex", pathStringLength: 260);
    if ( access(path: pTexFile, amode: 0) != 0 )
    {
      V_SetExtension(path: pTexFile, extension: "txt", pathStringLength: 260);
      if ( access(path: pTexFile, amode: 0) != 0 )
      {
        v8 = CreateElement<CDmePrecompiledTexture>(pObjectName: "root", fileid: DMFILEID_INVALID, pObjectID: nullptr);
        v9 = V_UnqualifiedFileName(in: pFullPath);
        g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: v9);
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v8->m_ImageFileName.m_pAttribute, &value);
        CDmePrecompiledTexture::AddProcessor<CDmeTP_ComputeMipmaps>(this: v8, pName: (int)"computeMipmaps");
      }
      else
      {
        pFullPath = pTexFile;
        v6 = "txt";
        v4 = pTexFile;
      }
    }
    else
    {
      pFullPath = pTexFile;
      v6 = "tex";
      v4 = pTexFile;
    }
  }
  if ( _V_stricmp(s1: v6, s2: "psd") == 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    if ( LoadConfigFromPSD(pFileName: v4, &buf, bMissingConfigOk: false, pCRC: pInputHash) == 0 )
    {
      if ( buf.m_Memory.m_nGrowSize >= 0 )
      {
        m_pMemory = buf.m_Memory.m_pMemory;
        goto LABEL_28;
      }
      return nullptr;
    }
    if ( buf.m_nMaxPut == 0 )
      goto LABEL_21;
    V_strncpy(pDest: pTempPath, pSrc: pFullPath, maxLen: 260);
    V_SetExtension(path: pTempPath, extension: "__psdtxt", pathStringLength: 260);
    v11 = ((unsigned __int8 (__thiscall *)(IDataModel *, CUtlBuffer *, int))g_pDataModel->IsDMXFormat)(
            a1: g_pDataModel,
            a2: &buf,
            a3: a1) == 0;
    v12 = "keyvalues2";
    if ( v11 )
      v12 = "tex_source1";
    if ( ((unsigned __int8 (__thiscall *)(IDataModel *, CUtlBuffer *, const char *, const char *, _DWORD, char *, int))g_pDataModel->Unserialize)(
           a1: g_pDataModel,
           a2: &buf,
           a3: v12,
           a4: "tex",
           a5: 0,
           a6: pTempPath,
           a7: 3) == 0 )
    {
LABEL_21:
      CUtlBuffer::~CUtlBuffer(this: &buf);
      return nullptr;
    }
    v8 = GetElement<CDmePrecompiledTexture>(hElement);
    v13 = V_UnqualifiedFileName(in: pFullPath);
    CDmaString::operator=(this: &v8->m_ImageFileName, src: v13);
    *pMode = BITMAP_FILE_TYPE_PSD;
    CUtlBuffer::~CUtlBuffer(this: &buf);
    v4 = pFullPath;
  }
  bIsImportedFile = _V_stricmp(s1: v6, s2: "txt") == 0;
  if ( _V_stricmp(s1: v6, s2: "tex") != 0 && !bIsImportedFile )
    goto LABEL_71;
  CUtlBuffer::CUtlBuffer(this: &v35, growSize: 0, initSize: 0, nFlags: 1);
  if ( LoadFile(buf: &v35, pFileName: v4, bFailOnError: false, puiHash: pInputHash) == 0 )
  {
    if ( v35.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = v35.m_Memory.m_pMemory;
LABEL_28:
      if ( m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
    return nullptr;
  }
  v14 = "keyvalues2";
  if ( bIsImportedFile )
    v14 = "tex_source1";
  if ( !g_pDataModel->Unserialize(
          this: g_pDataModel,
          a2: &v35,
          a3: v14,
          a4: "tex",
          a5: nullptr,
          a6: v4,
          a7: CR_FORCE_COPY,
          a8: &v37) )
    goto LABEL_63;
  v8 = GetElement<CDmePrecompiledTexture>(hElement: v37);
  v15 = V_UnqualifiedFileName(in: pOrigFullPath);
  V_strncpy(pDest: pFileBase, pSrc: v15, maxLen: 260);
  m_pAsString = v8->m_ImageFileName.m_Storage.u.m_pAsString;
  p_m_ImageFileName = &v8->m_ImageFileName;
  value.u.m_Id = (int)&v8->m_ImageFileName;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  if ( _V_stricmp(s1: m_pAsString, s2: "__unspecified_texture") != 0 )
  {
    if ( !bConfigFileSpecified )
    {
      m_Id = (const char *)p_m_ImageFileName->m_Storage.u.m_Id;
      if ( p_m_ImageFileName->m_Storage.u.m_Id == -1 )
        m_Id = defaultValue;
      if ( _V_stricmp(s1: m_Id, s2: pFileBase) != 0 )
      {
        v19 = (const char *)p_m_ImageFileName->m_Storage.u.m_Id;
        if ( p_m_ImageFileName->m_Storage.u.m_Id == -1 )
          v19 = defaultValue;
        _Warning(
          a1: ".tex specified a different file name (\"%s\") than the command-line did (\"%s\")!\n",
          v19,
          pFileBase);
        CUtlBuffer::~CUtlBuffer(this: &v35);
        return nullptr;
      }
    }
  }
  else
  {
    if ( bConfigFileSpecified )
    {
      pTestExt[0] = ".tga";
      pTestExt[1] = ".pfm";
      pTestExt[2] = ".psd";
      V_strncpy(pDest: pTestFile, pSrc: v4, maxLen: 260);
      v20 = 0;
      while ( 1 )
      {
        V_SetExtension(path: pTestFile, extension: pTestExt[v20], pathStringLength: 260);
        MakeSrcFileName(
          pTexture: v8,
          pSrcName: pTestFile,
          nFrameID: 0,
          nFaceID: 0,
          nMipLevel: 0,
          z: (v8->m_nVolumeTextureDepth.m_Storage > 1) - 1,
          pFullPath: pTestFileTest,
          nBufLen: 0x104u);
        if ( access(path: pTestFileTest, amode: 0) == 0 )
          break;
        if ( ++v20 >= 3 )
          goto LABEL_50;
      }
      v21 = V_UnqualifiedFileName(in: pTestFile);
      V_strncpy(pDest: pFileBase, pSrc: v21, maxLen: 260);
LABEL_50:
      if ( v20 == 3 )
      {
        _Warning(a1: "Unable to find image file associated with file \"%s\"!\n", v4);
        CUtlBuffer::~CUtlBuffer(this: &v35);
        return nullptr;
      }
      p_m_ImageFileName = (CDmaString *)value.u.m_Id;
    }
    CDmaString::operator=(this: p_m_ImageFileName, src: pFileBase);
  }
  v22 = (const char *)p_m_ImageFileName->m_Storage.u.m_Id;
  if ( p_m_ImageFileName->m_Storage.u.m_Id == -1 )
    v22 = defaultValue;
  v23 = V_GetFileExtension(path: v22);
  v24 = -1;
  if ( _V_stricmp(s1: v23, s2: "tga") == 0 )
  {
    v24 = 1;
    goto LABEL_58;
  }
  if ( _V_stricmp(s1: v23, s2: "pfm") == 0 )
  {
    v24 = 2;
    goto LABEL_58;
  }
  if ( v23 == nullptr )
  {
LABEL_58:
    if ( *pMode != BITMAP_FILE_TYPE_UNKNOWN && *pMode != v24 )
    {
      v25 = *(const char **)value.u.m_pAsString;
      if ( *(_DWORD *)value.u.m_Id == -1 )
        v25 = defaultValue;
      VTexError(
        pFormat: "VTex: Specified to build file \"%s\", but file \"%s\" is specified in the associated .tex file!\n",
        pFullPath,
        v25);
LABEL_63:
      CUtlBuffer::~CUtlBuffer(this: &v35);
      return nullptr;
    }
    CUtlBuffer::~CUtlBuffer(this: &v35);
    v4 = pFullPath;
LABEL_71:
    GenerateResourceName(pFileName: v4, pSubResourceName: nullptr, pResourceName: pTextureName, pBufLen: 0x104u);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pOrigFullPath, a3: pTextureName);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: v8->m_Name.m_pAttribute,
      value: (const CUtlSymbolLarge *)&pOrigFullPath);
    return v8;
  }
  v26 = *(const char **)value.u.m_pAsString;
  if ( *(_DWORD *)value.u.m_Id == -1 )
    v26 = defaultValue;
  VTexError(pFormat: "VTex: Bogus texture file name encountered \"%s\"!\n", v26);
  CUtlBuffer::~CUtlBuffer(this: &v35);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10008420
// Name: public: virtual enum InitReturnVal_t CVTexCompiler::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CVTexCompiler::Init(CVTexCompiler *this)
{
  InitReturnVal_t result; // eax

  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  result = InitDataModel();
  if ( result == INIT_OK )
  {
    MathLib_Init(
      gamma: 2.2,
      texGamma: 2.2,
      brightness: 0.0,
      overbright: 1,
      bAllow3DNow: false,
      bAllowSSE: false,
      bAllowSSE2: false,
      bAllowMMX: false);
    InstallDmElementFactories();
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    g_Quiet = true;
    g_NoPause = true;
    g_bWarningsAsErrors = false;
    g_CreateDir = true;
    g_UseGameDir = false;
    g_bSupportsXBox360 = true;
    return INIT_OK;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100084C0
// Name: private: class CDmeTexture __near * CVTexCompiler::CompileResource(class CDmePrecompiledTexture __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTexture *__thiscall CVTexCompiler::CompileResource(
        CVTexCompiler *this,
        CDmePrecompiledTexture *pPrecompiledResource)
{
  CDmePrecompiledTexture *v2; // edi
  CDmElement *v3; // ebx
  IThreadPool *NewThreadPool; // eax
  const char *m_pAsString; // eax
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // eax
  CDmElement *v10; // edi
  CDmElement *v11; // ecx
  CDmePrecompiledTexture *v12; // edi
  const char *v13; // eax
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmeTexture *v16; // esi
  ThreadPoolStartParams_t startParams; // [esp+Ch] [ebp-120h] BYREF
  int nCount; // [esp+120h] [ebp-Ch]
  IThreadPool *pVTexThreadPool; // [esp+124h] [ebp-8h]
  int i; // [esp+128h] [ebp-4h]

  v2 = pPrecompiledResource;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: pPrecompiledResource->m_pSourceTexture.m_Storage.m_Handle);
  SetTextureStateFromPrecompiledTexture(pPrecompiledTexture: v2, pTexture: (CDmeTexture *)v3);
  NewThreadPool = (IThreadPool *)_CreateNewThreadPool();
  startParams.nThreads = -1;
  startParams.nStackSize = -1;
  pVTexThreadPool = NewThreadPool;
  startParams.iThreadPriority = -32768;
  *((_BYTE *)&startParams + 272) &= 0xFCu;
  if ( (*((_BYTE *)&startParams + 272) & 2) != 0 )
  {
    qmemcpy(startParams.iAffinityTable, nullptr, sizeof(startParams.iAffinityTable));
    v2 = pPrecompiledResource;
  }
  startParams.fDistribute = TRS_TRUE;
  NewThreadPool->Start_2(this: NewThreadPool, a2: &startParams);
  FloatBitMap_t::SetThreadPool(pPool: pVTexThreadPool);
  nCount = v2->m_Processors.m_Storage.m_Size;
  for ( i = 0; i < nCount; ++i )
  {
    m_pAsString = v3->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    v6 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeTexture::m_classType.u.m_Id,
           a3: m_pAsString,
           a4: v3->m_fileId,
           a5: nullptr);
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeTexture::m_classType) )
      v8 = nullptr;
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_Processors.m_Storage.m_Memory.m_pMemory[i]);
    v10 = v9;
    if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeTextureProcessor::m_classType) )
      v11 = v10;
    else
      v11 = nullptr;
    ((void (__thiscall *)(CDmElement *, CDmElement *, CDmElement *))v11->__vftable[1].OnAttributeChanged)(
      a1: v11,
      a2: v3,
      a3: v8);
    DestroyElement(pElement: v3, depth: TD_DEEP);
    v2 = pPrecompiledResource;
    v3 = v8;
  }
  v12 = (CDmePrecompiledTexture *)ComputeDesiredImageFormat_0(pPrecompiledTexture: v2, pTexture: (CDmeTexture *)v3);
  pPrecompiledResource = v12;
  if ( (*((_BYTE *)ImageLoader::ImageFormatInfo(fmt: (ImageFormat)v12) + 11) & 1) != 0 )
  {
    v13 = v3->m_Name.m_Storage.u.m_pAsString;
    if ( v13 == (const char *)-1 )
      v13 = defaultValue;
    v14 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
            a1: g_pDataModel,
            a2: (CUtlSymbolLarge)CDmeTexture::m_classType.u.m_Id,
            a3: v13,
            a4: v3->m_fileId,
            a5: nullptr);
    v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
    v16 = (CDmeTexture *)v15;
    if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmeTexture::m_classType) )
      v16 = nullptr;
    CDmeTexture::CompressTexture(this: v16, pSrcTexture: (CDmeTexture *)v3, fmt: (ImageFormat)v12);
    DestroyElement(pElement: v3, depth: TD_DEEP);
    v3 = v16;
  }
  else
  {
    CDmeTexture::ForEachImage<void,enum ImageFormat,enum ImageFormat>(
      this: (CDmeTexture *)v3,
      pfnProxied: CDmeImage::ConvertFormat,
      arg1: (ImageFormat *)&pPrecompiledResource);
  }
  FloatBitMap_t::SetThreadPool(pPool: nullptr);
  _DestroyThreadPool(a1: pVTexThreadPool);
  return (CDmeTexture *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100086F0
// Name: private: bool CVTexCompiler::CompileResource(class CDmElement __near *,char const __near *,class IResourceCompilerRegistry __near *,class CResourceStream __near *,class CResourceStream __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVTexCompiler::CompileResource(
        CVTexCompiler *this,
        CDmePrecompiledTexture *pElement,
        const char *pElementFileName,
        IResourceCompilerRegistry *pRegistry,
        CResourceStream *pPermanentStream,
        CResourceStream *pDataStream)
{
  CDmeTexture *v8; // ebx
  const char *m_pAsString; // eax
  unsigned int v10; // eax
  CResourceStream *v11; // edi
  unsigned int m_nUsed; // ecx
  unsigned int v13; // edx
  _QWORD *Bytes; // esi
  CDmElement *v15; // eax
  CDmeTextureFrame *v16; // esi
  CDmeImageArray *MipLevel; // esi
  int v18; // edi
  CDmeImage *Image; // esi
  int v20; // ebx
  void (__thiscall *RegisterResource)(IResourceCompilerRegistry *, const RegisterResourceInfo_t *); // edx
  RegisterResourceInfo_t info; // [esp+Ch] [ebp-3Ch] BYREF
  unsigned int nStart; // [esp+30h] [ebp-18h]
  int nFrameCount; // [esp+34h] [ebp-14h]
  CDmeTexture *pTexture; // [esp+38h] [ebp-10h]
  int nImageCount; // [esp+3Ch] [ebp-Ch]
  void *pDest; // [esp+40h] [ebp-8h]
  CDmeImageArray *pMipLevel; // [esp+44h] [ebp-4h]
  int f; // [esp+50h] [ebp+8h]
  int m; // [esp+5Ch] [ebp+14h]

  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmePrecompiledTexture::m_classType.u.m_Id) )
  {
    return 0;
  }
  v8 = CVTexCompiler::CompileResource(this, pPrecompiledResource: pElement);
  m_pAsString = pElement->m_Name.m_Storage.u.m_pAsString;
  pTexture = v8;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  info.m_nType = 0;
  v10 = ComputeResourceIdHash(pResourceName: m_pAsString);
  v11 = pDataStream;
  m_nUsed = pDataStream->m_nUsed;
  info.m_nCompressionType = RESOURCE_COMPRESSION_NONE;
  info.m_nFlags = 0;
  v13 = pPermanentStream->m_nUsed;
  info.m_nDataOffset = m_nUsed;
  info.m_nId = v10;
  info.m_nPermanentDataOffset = v13;
  info.m_nPermanentDataSize = 28;
  CResourceStream::Align(this: pPermanentStream, nAlignment: 4u, nOffset: 0);
  Bytes = CResourceStream::AllocateBytes(this: pPermanentStream, numBytes: 0x1Cu);
  *Bytes = 0;
  Bytes[1] = 0;
  Bytes[2] = 0;
  *((_DWORD *)Bytes + 6) = 0;
  *(_WORD *)Bytes = CDmeTexture::Width(this: v8);
  *((_WORD *)Bytes + 1) = CDmeTexture::Height(this: v8);
  *((_BYTE *)Bytes + 7) = CDmeTexture::MipLevelCount(this: v8);
  *((_WORD *)Bytes + 2) = CDmeTexture::Depth(this: v8);
  *((_BYTE *)Bytes + 6) = CDmeTexture::Format(this: v8);
  *((_WORD *)Bytes + 5) = 0;
  if ( v8->m_bClampS.m_Storage )
    *((_WORD *)Bytes + 5) = 16;
  if ( v8->m_bClampT.m_Storage )
    *((_WORD *)Bytes + 5) |= 0x20u;
  if ( v8->m_bClampU.m_Storage )
    *((_WORD *)Bytes + 5) |= 0x40u;
  if ( v8->m_bNoLod.m_Storage )
    *((_WORD *)Bytes + 5) |= 0x80u;
  *((_WORD *)Bytes + 4) = 0;
  *((_DWORD *)Bytes + 3) = 1065353216;
  *((_DWORD *)Bytes + 4) = 1065353216;
  *((_DWORD *)Bytes + 5) = 1065353216;
  *((_DWORD *)Bytes + 6) = 1065353216;
  CResourceStream::Align(this: pDataStream, nAlignment: 0x10u, nOffset: 0);
  nStart = pDataStream->m_nUsed;
  for ( m = CDmeTexture::MipLevelCount(this: v8) - 1; m >= 0; --m )
  {
    nFrameCount = v8->m_Frames.m_Storage.m_Size;
    f = 0;
    if ( nFrameCount > 0 )
    {
      do
      {
        v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8->m_Frames.m_Storage.m_Memory.m_pMemory[f]);
        v16 = (CDmeTextureFrame *)v15;
        if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmeTextureFrame::m_classType) )
          v16 = nullptr;
        MipLevel = CDmeTextureFrame::GetMipLevel(this: v16, nIndex: m);
        pMipLevel = MipLevel;
        v18 = 0;
        nImageCount = CVTFTexture::LowResWidth(this: (CVTFTexture *)MipLevel);
        if ( nImageCount > 0 )
        {
          while ( 1 )
          {
            Image = CDmeImageArray::GetImage(this: MipLevel, nIndex: v18);
            v20 = CDmeImage::SizeInBytes(this: Image);
            pDest = CResourceStream::AllocateBytes(this: pDataStream, numBytes: v20);
            CDmeImage::SetFloatBitmapStorageMode(this: Image, bFloatBitmap: false, bDiscardContents: false);
            _V_memcpy(dest: pDest, src: Image->m_Bits.m_Storage.m_Memory.m_pMemory, count: v20);
            if ( ++v18 >= nImageCount )
              break;
            MipLevel = pMipLevel;
          }
          v8 = pTexture;
        }
        ++f;
      }
      while ( f < nFrameCount );
      v11 = pDataStream;
    }
  }
  RegisterResource = pRegistry->RegisterResource;
  info.m_nDataSize = v11->m_nUsed - nStart;
  info.m_nUncompressedDataSize = info.m_nDataSize;
  RegisterResource(this: pRegistry, a2: &info);
  pRegistry->RegisterUsedType_2(this: pRegistry, a2: "TextureBits_t", a3: false);
  pRegistry->RegisterUsedType_2(this: pRegistry, a2: "TextureHeader_t", a3: true);
  DestroyElement(pElement: v8, depth: TD_DEEP);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008990
// Name: void PostProcessSkyBox(class SmartIVTFTexture __near &,char const __near *,char const __near *,char const __near *,struct VTexConfigInfo_t const __near &,class CUtlVector<struct OutputTexture_t,class CUtlMemory<struct OutputTexture_t,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PostProcessSkyBox(
        SmartIVTFTexture *pSrcTexture,
        const char *pDstFileName,
        const char *pOutputDir,
        const char *pBaseName,
        const VTexConfigInfo_t *info,
        CUtlVector<OutputTexture_t,CUtlMemory<OutputTexture_t,int> > *outputTextures,
        int iSkyboxFace)
{
  int v7; // edi
  int v8; // ebx
  SmartIVTFTexture *v9; // esi
  int v10; // eax
  IVTFTexture *m_p; // ecx
  int v12; // ebx
  int (__thiscall *Height)(IVTFTexture *); // edx
  int v14; // eax
  bool v15; // zf
  IVTFTexture *VTFTexture; // eax
  IVTFTexture *v17; // ebx
  IVTFTexture *v18; // edi
  int (__thiscall *FrameCount)(IVTFTexture *); // eax
  IVTFTexture_vtbl *v20; // esi
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // esi
  int v25; // eax
  int i; // esi
  unsigned __int8 *v27; // eax
  const char *v28; // ecx
  const char *v29; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  OutputTexture_t *m_pMemory; // ecx
  int v33; // eax
  OutputTexture_t *v34; // ebx
  OutputTexture_t outputTexture; // [esp+Ch] [ebp-120h] BYREF
  int nMips; // [esp+114h] [ebp-18h]
  int v37; // [esp+118h] [ebp-14h]
  int nFlags; // [esp+11Ch] [ebp-10h]
  int dstMipSize; // [esp+120h] [ebp-Ch]
  unsigned __int8 *pDst; // [esp+124h] [ebp-8h]
  int iFace; // [esp+128h] [ebp-4h]

  v7 = 0;
  v8 = 6;
  if ( g_bOldCubemapPath )
  {
    v7 = iSkyboxFace;
    v8 = 1;
  }
  v9 = pSrcTexture;
  nFlags = pSrcTexture->m_p->Flags(this: pSrcTexture->m_p) & 0xFFFFBFFF;
  iFace = v7;
  v37 = v8 + v7;
  if ( v7 < v8 + v7 )
  {
    while ( 1 )
    {
      v10 = v9->m_p->Width(this: v9->m_p);
      m_p = v9->m_p;
      v12 = v10;
      Height = v9->m_p->Height;
      dstMipSize = v10;
      v14 = Height(this: m_p);
      v15 = !info->m_bIsCroppedSkyBox;
      pDst = (unsigned __int8 *)v14;
      if ( !v15 && v7 != 4 )
      {
        if ( v7 == 5 )
        {
          if ( v12 > 4 )
            dstMipSize = 4;
          if ( v14 > 4 )
            pDst = (unsigned __int8 *)4;
        }
        else
        {
          pDst = (unsigned __int8 *)((v14 + 1) / 2);
        }
      }
      VTFTexture = CreateVTFTexture();
      v17 = v9->m_p;
      v18 = VTFTexture;
      FrameCount = v9->m_p->FrameCount;
      v20 = v18->__vftable;
      v21 = ((int (__thiscall *)(IVTFTexture *, int))FrameCount)(a1: v17, a2: -1);
      v22 = ((int (__thiscall *)(IVTFTexture *, int, int))v17->Format)(a1: v17, a2: nFlags, a3: v21);
      if ( ((unsigned __int8 (__thiscall *)(IVTFTexture *, int, unsigned __int8 *, int, int))v20->Init)(
             a1: v18,
             a2: dstMipSize,
             a3: pDst,
             a4: 1,
             a5: v22) == 0 )
        _Error(a1: "PostProcessSkyBox: IVTFTexture::Init() failed.\n");
      v23 = 0;
      nMips = v18->MipCount(this: v18);
      if ( nMips > 0 )
      {
        do
        {
          v24 = pSrcTexture->m_p->ComputeMipSize(this: pSrcTexture->m_p, a2: v23);
          v25 = v18->ComputeMipSize(this: v18, a2: v23);
          dstMipSize = v25;
          if ( v24 != v25 && (v24 < v25 || v24 != 2 * v25 && iFace != 5) )
            _Error(
              a1: "PostProcessSkyBox: src/dest mipmap size mismatch during skybox cropping (src=%d, dest=%d)\n",
              v24,
              v25);
          for ( i = 0; i < pSrcTexture->m_p->FrameCount(this: pSrcTexture->m_p); ++i )
          {
            pDst = v18->ImageData_2(this: v18, a2: i, a3: 0, a4: v23);
            v27 = pSrcTexture->m_p->ImageData_2(this: pSrcTexture->m_p, a2: i, a3: iFace, a4: v23);
            memcpy(dst: pDst, src: v27, count: dstMipSize);
          }
          ++v23;
        }
        while ( v23 < nMips );
      }
      outputTexture.pTexture = v18;
      if ( g_bOldCubemapPath )
        v28 = defaultValue;
      else
        v28 = g_CubemapFacingNames[iFace];
      v29 = ".pwl";
      if ( (info->m_vtfProcOptions.flags0 & 0x800) == 0 )
        v29 = defaultValue;
      V_snprintf(
        pDest: outputTexture.dstFileName,
        maxLen: 260,
        pFormat: "%s/%s%s%s.vtf",
        pOutputDir,
        pBaseName,
        v28,
        v29);
      m_Size = outputTextures->m_Size;
      m_nAllocationCount = outputTextures->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<OutputTexture_t,int>::Grow(this: &outputTextures->m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++outputTextures->m_Size;
      m_pMemory = outputTextures->m_Memory.m_pMemory;
      v33 = outputTextures->m_Size - m_Size - 1;
      outputTextures->m_pElements = outputTextures->m_Memory.m_pMemory;
      if ( v33 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 264 * v33);
      v34 = &outputTextures->m_Memory.m_pMemory[m_Size];
      if ( v34 != nullptr )
        *v34 = outputTexture;
      v9 = pSrcTexture;
      if ( ++iFace >= v37 )
        break;
      v7 = iFace;
    }
  }
  DestroyVTFTexture(pTexture: v9->m_p);
  v9->m_p = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10008C30
// Name: bool ProcessFiles(char const __near *,char const __near *,char const __near *,struct VTexConfigInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ProcessFiles(
        char *pFullNameWithoutExtension,
        const char *pOutputDir,
        const char *pBaseName,
        VTexConfigInfo_t *info)
{
  VTexConfigInfo_t *v4; // edi
  IVTFTexture *VTFTexture; // eax
  bool v6; // zf
  IVTFTexture *v7; // ebx
  char *v8; // esi
  unsigned int *p_m_uiInputHash; // edi
  unsigned int v11; // ecx
  VTexConfigInfo_t *v12; // edi
  const char *v13; // eax
  int v14; // eax
  _iobuf *v15; // eax
  IVTFTexture *v16; // edi
  _iobuf *v17; // eax
  _DWORD *v18; // eax
  _iobuf *v19; // eax
  _iobuf *v20; // eax
  _iobuf *v21; // eax
  int v22; // eax
  IVTFTexture *v23; // edi
  _DWORD *v24; // eax
  int v25; // eax
  TextureLODControlSettings_t v26; // ecx
  VTexConfigInfo_t *v27; // edi
  void (__thiscall *SetPostProcessingSettings)(IVTFTexture *, const VtfProcessingOptions *); // edx
  ImageFormat v29; // eax
  ImageFormat v30; // esi
  int v31; // eax
  int v32; // eax
  int v33; // eax
  char *v34; // ebx
  CP4File *v35; // esi
  _iobuf *v36; // edi
  int v37; // eax
  char pCmdLine[1024]; // [esp+3Ch] [ebp-B5Ch] BYREF
  char fullNameTemp[512]; // [esp+43Ch] [ebp-75Ch] BYREF
  char dstFileName[1024]; // [esp+63Ch] [ebp-55Ch] BYREF
  OutputTexture_t singleOutput; // [esp+A3Ch] [ebp-15Ch] BYREF
  CUtlBuffer outputBuf; // [esp+B44h] [ebp-54h] BYREF
  CUtlVector<OutputTexture_t,CUtlMemory<OutputTexture_t,int> > outputTextures; // [esp+B74h] [ebp-24h] BYREF
  unsigned int crcWritten; // [esp+B88h] [ebp-10h]
  SmartIVTFTexture pVTFTexture; // [esp+B8Ch] [ebp-Ch] BYREF
  ImageFormat vtfImageFormat; // [esp+B90h] [ebp-8h] BYREF
  int iSkyboxFace; // [esp+B94h] [ebp-4h] BYREF

  v4 = info;
  if ( info->m_bIsCubeMap )
    info->m_nFlags |= 0x400Cu;
  VTFTexture = CreateVTFTexture();
  v6 = !v4->m_bIsSkyBox;
  v7 = VTFTexture;
  pVTFTexture.m_p = VTFTexture;
  iSkyboxFace = 0;
  if ( v6 || !g_bOldCubemapPath )
  {
    v8 = pFullNameWithoutExtension;
  }
  else
  {
    V_strncpy(pDest: fullNameTemp, pSrc: pFullNameWithoutExtension, maxLen: 512);
    v8 = fullNameTemp;
    pFullNameWithoutExtension = fullNameTemp;
    PreprocessSkyBox(pFullNameWithoutExtension: fullNameTemp, &iSkyboxFace);
  }
  if ( LoadSourceImages(pTexture: v7, pFullNameWithoutExtension: v8, info: v4) != 0 )
  {
    p_m_uiInputHash = &v4->m_uiInputHash;
    AttachShtFile(pFullNameWithoutExtension, pTexture: v7, puiHash: p_m_uiInputHash);
    CRC32_Final(pulCRC: p_m_uiInputHash);
    v7->SetResourceData(this: v7, a2: 4411971u, a3: p_m_uiInputHash, a4: 4u);
    v11 = *p_m_uiInputHash;
    v12 = info;
    v6 = (info->m_vtfProcOptions.flags0 & 0x800) == 0;
    crcWritten = v11;
    v13 = ".pwl";
    if ( v6 )
      v13 = defaultValue;
    V_snprintf(pDest: dstFileName, maxLen: 1024, pFormat: "%s/%s%s%s.vtf", pOutputDir, pBaseName, defaultValue, v13);
    v14 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-crcvalidate") != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &outputBuf, growSize: 0, initSize: 0, nFlags: 0);
      if ( LoadFile(buf: &outputBuf, pFileName: dstFileName, bFailOnError: false, puiHash: nullptr) != 0 )
      {
        v16 = CreateVTFTexture();
        if ( v16->Unserialize(this: v16, a2: &outputBuf, a3: false, a4: 0) )
        {
          v18 = v16->GetResourceData(this: v16, a2: 4411971u, a3: (unsigned int *)&info);
          if ( v18 != nullptr && info == (VTexConfigInfo_t *)4 )
          {
            if ( *v18 == crcWritten )
            {
              v20 = __iob_func();
              VTexMsgEx(fout: v20 + 2, pFormat: "OK: %s\n", dstFileName);
              DestroyVTFTexture(pTexture: v16);
              CUtlBuffer::~CUtlBuffer(this: &outputBuf);
              DestroyVTFTexture(pTexture: v7);
              return 1;
            }
            else
            {
              v19 = __iob_func();
              VTexMsgEx(fout: v19 + 2, pFormat: "CRC MISMATCH: %s\n", dstFileName);
              DestroyVTFTexture(pTexture: v16);
              CUtlBuffer::~CUtlBuffer(this: &outputBuf);
              DestroyVTFTexture(pTexture: v7);
              return 0;
            }
          }
          else
          {
            v21 = __iob_func();
            VTexMsgEx(fout: v21 + 2, pFormat: "OLD TEXTURE FORMAT: %s\n", dstFileName);
            DestroyVTFTexture(pTexture: v16);
            CUtlBuffer::~CUtlBuffer(this: &outputBuf);
            DestroyVTFTexture(pTexture: v7);
            return 0;
          }
        }
        else
        {
          v17 = __iob_func();
          VTexMsgEx(fout: v17 + 2, pFormat: "UNSERIALIZE ERROR: %s\n", dstFileName);
          DestroyVTFTexture(pTexture: v16);
          CUtlBuffer::~CUtlBuffer(this: &outputBuf);
          DestroyVTFTexture(pTexture: v7);
          return 0;
        }
      }
      else
      {
        v15 = __iob_func();
        VTexMsgEx(fout: v15 + 2, pFormat: "LOAD ERROR: %s\n", dstFileName);
        if ( outputBuf.m_Memory.m_nGrowSize >= 0 )
        {
          if ( outputBuf.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputBuf.m_Memory.m_pMemory);
            outputBuf.m_Memory.m_pMemory = nullptr;
          }
          outputBuf.m_Memory.m_nAllocationCount = 0;
        }
        DestroyVTFTexture(pTexture: v7);
        return 0;
      }
    }
    else
    {
      v22 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v22 + 40))(a1: v22, a2: "-crcforce") == 0 )
      {
        CUtlBuffer::CUtlBuffer(this: &outputBuf, growSize: 0, initSize: 0, nFlags: 0);
        if ( LoadFile(buf: &outputBuf, pFileName: dstFileName, bFailOnError: false, puiHash: nullptr) != 0 )
        {
          v23 = CreateVTFTexture();
          if ( v23->Unserialize(this: v23, a2: &outputBuf, a3: false, a4: 0) )
          {
            v24 = v23->GetResourceData(this: v23, a2: 4411971u, a3: (unsigned int *)&vtfImageFormat);
            if ( v24 != nullptr && vtfImageFormat == IMAGE_FORMAT_RGB565 && *v24 == crcWritten )
            {
              if ( !g_Quiet )
                VTexMsg(pFormat: "SUCCESS: %s is up-to-date\n", dstFileName);
              v25 = _CommandLine();
              if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v25 + 40))(a1: v25, a2: "-crcforce") == 0 )
              {
                DestroyVTFTexture(pTexture: v23);
                CUtlBuffer::~CUtlBuffer(this: &outputBuf);
                DestroyVTFTexture(pTexture: v7);
                return 1;
              }
            }
          }
          DestroyVTFTexture(pTexture: v23);
        }
        if ( outputBuf.m_Memory.m_nGrowSize >= 0 && outputBuf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputBuf.m_Memory.m_pMemory);
        v12 = info;
      }
      ((void (__thiscall *)(IVTFTexture *, _DWORD))v7->SetBumpScale)(a1: v7, a2: LODWORD(v12->m_flBumpScale));
      ((void (__thiscall *)(IVTFTexture *, _DWORD, _DWORD))v7->SetAlphaTestThreshholds)(
        a1: v7,
        a2: LODWORD(v12->m_flAlphaThreshhold),
        a3: LODWORD(v12->m_flAlphaHiFreqThreshhold));
      SetTextureLodData(pTexture: v7, info: v12, a3: v26);
      v27 = info;
      SetPostProcessingSettings = v7->SetPostProcessingSettings;
      LOBYTE(vtfImageFormat) = !info->m_bIsSkyBox;
      SetPostProcessingSettings(this: v7, a2: &info->m_vtfProcOptions);
      v7->PostProcess(this: v7, a2: false, a3: LOOK_DOWN_Z, a4: vtfImageFormat, a5: v27->m_bManualMip);
      v29 = ComputeDesiredImageFormat(pTexture: v7, info: v27, a3: (int)v7);
      v6 = !v27->m_bIsCubeMap;
      v30 = v29;
      vtfImageFormat = v29;
      if ( v6 )
      {
        v31 = v7->Width(this: v7);
        if ( ((v31 - 1) & v31) != 0
          || (((v32 = v7->Height(this: v7)) - 1) & v32) != 0
          || (((v33 = v7->Depth(this: v7)) - 1) & v33) != 0 )
        {
          VTexError(pFormat: "Cannot create low-res image for non-power of two texture (did you forget to set 'cubemap 1'"
                             " or 'skybox 1'?)\n");
        }
        CreateLowResImage(pVTFTexture: v7);
        v30 = vtfImageFormat;
      }
      else
      {
        v7->MatchCubeMapBorders(this: v7, a2: 1, a3: v29, a4: v27->m_bIsSkyBox);
      }
      if ( v27->m_bNormalInvertGreen )
      {
        if ( (v7->Flags(this: v7) & 0x80u) == 0 )
          VTexWarning(pFormat: "'invertgreen' specified for texture which is not being processed as a normal map!\n");
        else
          NormalInvertGreen(pTexture: v7);
      }
      if ( v27->m_bNormalToDXT5GA )
        v7->ConvertImageFormat(this: v7, a2: IMAGE_FORMAT_BGRA8888, a3: false, a4: false);
      v7->ConvertImageFormat(this: v7, a2: v30, a3: v27->m_bNormalToDuDv, a4: v27->m_bNormalToDXT5GA);
      v7->MatchCubeMapBorders(this: v7, a2: 2, a3: v30, a4: v27->m_bIsSkyBox);
      v6 = !v27->m_bIsSkyBox;
      memset(&outputTextures, 0, sizeof(outputTextures));
      if ( v6 )
      {
        singleOutput.pTexture = v7;
        strncpy(
          dest: (unsigned __int8 *)singleOutput.dstFileName,
          source: (unsigned __int8 *)dstFileName,
          count: 0x104u);
        CUtlVector<OutputTexture_t,CUtlMemory<OutputTexture_t,int>>::InsertBefore(
          this: &outputTextures,
          elem: 0,
          src: &singleOutput);
        pVTFTexture.m_p = nullptr;
      }
      else
      {
        PostProcessSkyBox(
          pSrcTexture: &pVTFTexture,
          pDstFileName: dstFileName,
          pOutputDir,
          pBaseName,
          info: v27,
          &outputTextures,
          iSkyboxFace);
      }
      if ( outputTextures.m_Size > 0 )
      {
        v34 = outputTextures.m_Memory.m_pMemory->dstFileName;
        iSkyboxFace = outputTextures.m_Size;
        while ( 1 )
        {
          if ( VTexConfigInfo_t::IsSettings0Valid(this: v27) )
            (*(void (__thiscall **)(_DWORD, int, TextureSettingsEx_t *, int))(**((_DWORD **)v34 - 1) + 20))(
              a1: *((_DWORD *)v34 - 1),
              a2: 3167060,
              a3: &v27->m_exSettings0,
              a4: 4);
          if ( g_CreateDir )
            MakeDirHier(pPath: pOutputDir);
          CUtlBuffer::CUtlBuffer(this: &outputBuf, growSize: 0, initSize: 0, nFlags: 0);
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD, CUtlBuffer *))(**((_DWORD **)v34 - 1) + 40))(
                 a1: *((_DWORD *)v34 - 1),
                 a2: &outputBuf) == 0 )
            VTexError(pFormat: "\"%s\": Unable to serialize the VTF file!\n", dstFileName);
          v35 = CP4Factory::AccessFile(this: g_p4factory, szFilename: v34);
          v35->Edit(this: v35);
          v36 = fopen(file: v34, mode: "wb");
          if ( v36 == nullptr )
            VTexError(pFormat: "Can't open: %s\n", v34);
          fwrite(buffer: outputBuf.m_Memory.m_pMemory, size: 1u, count: outputBuf.m_Put, stream: v36);
          fclose(stream: v36);
          v37 = _CommandLine();
          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v37 + 40))(a1: v37, a2: "-source2") != 0 )
          {
            V_snprintf(pDest: pCmdLine, maxLen: 1024, pFormat: "resourcecompiler.exe -i %s\n", v34);
            system(command: pCmdLine);
          }
          v35->Add(this: v35);
          ((void (__thiscall *)(CP4File *, int))v35->dtr_CP4File)(a1: v35, a2: 1);
          if ( outputBuf.m_Memory.m_nGrowSize >= 0 && outputBuf.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputBuf.m_Memory.m_pMemory);
          v34 += 264;
          if ( --iSkyboxFace == 0 )
            break;
          v27 = info;
        }
      }
      VTexMsg(pFormat: "SUCCESS: Vtf file created\n");
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outputTextures);
      if ( pVTFTexture.m_p != nullptr )
        DestroyVTFTexture(pTexture: pVTFTexture.m_p);
      return 1;
    }
  }
  else
  {
    VTexError(pFormat: "Can't load source images for \"%s\"\n", v8);
    if ( v7 != nullptr )
      DestroyVTFTexture(pTexture: v7);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009350
// Name: bool Process_File_Internal(char __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Process_File_Internal(
        char *pInputBaseName,
        int maxlen,
        bool bOutputPwlColorConversion,
        bool bConvertTo360PwlSrgb)
{
  char *v4; // ebx
  int (*v5)(void); // esi
  int v6; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // edi
  const char *BareFileName; // eax
  int v14; // eax
  IVTFTexture *VTFTexture; // esi
  _iobuf *v16; // esi
  int v17; // eax
  IVTFTexture *v18; // esi
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  bool v23; // zf
  const char *v24; // eax
  int v25; // eax
  float v26; // ecx
  ImageFormat v27; // eax
  int v28; // ebx
  _iobuf *v29; // edi
  int v30; // eax
  int v31; // eax
  int v32; // eax
  const char *v33; // esi
  char *v34; // ebx
  _iobuf *v35; // edi
  _iobuf *v36; // eax
  _iobuf *v37; // edi
  _iobuf *v38; // eax
  int i; // esi
  char command[2048]; // [esp+3Ch] [ebp-21D0h] BYREF
  char path[2048]; // [esp+83Ch] [ebp-19D0h] BYREF
  char file[1024]; // [esp+103Ch] [ebp-11D0h] BYREF
  char pDest[1024]; // [esp+143Ch] [ebp-DD0h] BYREF
  char v44[512]; // [esp+183Ch] [ebp-9D0h] BYREF
  char string[252]; // [esp+1A3Ch] [ebp-7D0h] BYREF
  char szFilename[260]; // [esp+1B38h] [ebp-6D4h] BYREF
  char pnbuf[1024]; // [esp+1C3Ch] [ebp-5D0h] BYREF
  VTexConfigInfo_t info; // [esp+203Ch] [ebp-1D0h] BYREF
  __int64 v49; // [esp+21C0h] [ebp-4Ch]
  float v50; // [esp+21C8h] [ebp-44h]
  CUtlBuffer buf; // [esp+21CCh] [ebp-40h] BYREF
  unsigned __int8 *str1; // [esp+21FCh] [ebp-10h]
  CP4AutoAddFile v53; // [esp+2200h] [ebp-Ch] BYREF
  CP4AutoAddFile v54; // [esp+2204h] [ebp-8h] BYREF
  char v55; // [esp+220Bh] [ebp-1h]

  v4 = pInputBaseName;
  V_FixSlashes(pname: pInputBaseName, separator: 47);
  V_strncpy(pDest, pSrc: pInputBaseName, maxLen: maxlen);
  V_StripExtension(in: v4, out: v4, outSize: maxlen);
  v5 = _CommandLine;
  v6 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-deducepath") != 0 )
  {
    strcpy(pnbuf, pInputBaseName);
    if ( *pInputBaseName != 47 && pInputBaseName[1] != 58 )
    {
      _getcwd(pnbuf, maxlen: 1024);
      V_FixSlashes(pname: pnbuf, separator: 47);
      V_strncat(pDest: pnbuf, pSrc: "/", destBufferSize: 0x400u, max_chars_to_copy: -1);
      V_strncat(pDest: pnbuf, pSrc: pInputBaseName, destBufferSize: 0x400u, max_chars_to_copy: -1);
    }
    strstr(str1: (unsigned __int8 *)pnbuf, str2: "/game/");
    v8 = v7;
    strstr(str1: (unsigned __int8 *)pnbuf, str2: "/materials/");
    v10 = v9;
    if ( v8 != nullptr && v9 != 0 && (unsigned int)v8 < v9 )
    {
      memmove(
        dst: (unsigned __int8 *)&pnbuf[v9 - (_DWORD)pnbuf + 16],
        src: (unsigned __int8 *)&pnbuf[v9 - (_DWORD)pnbuf + 11],
        count: strlen(pnbuf) - (v9 - (_DWORD)pnbuf + 11) + 1);
      v11 = v10 - (_DWORD)v8 - 5;
      memmove(dst: v8 + 8, src: v8 + 5, count: v11);
      memmove(dst: v8, src: "/content", count: 8u);
      memmove(dst: &v8[v11 + 8], src: "/materialsrc/", count: 0xDu);
      v4 = pInputBaseName;
    }
    V_strncpy(pDest: v4, pSrc: pnbuf, maxLen: maxlen);
    v5 = _CommandLine;
  }
  if ( !g_Quiet )
    VTexMsg(pFormat: "\nInput file: %s\n", v4);
  if ( g_UseGameDir )
  {
    if ( GetOutputDir(inputName: v4, outputDir: pnbuf) == 0 )
    {
      VTexError(pFormat: "Problem figuring out outputdir for %s\n", v4);
      return 0;
    }
    BareFileName = GetBareFileName(pszPathName: v4);
    sprintf(string: pDest, format: "%s/%s.vtf", pnbuf, BareFileName);
  }
  else
  {
    strcpy(pnbuf, v4);
    sprintf(string: pDest, format: "%s.vtf", pnbuf);
    V_StripFilename(path: pnbuf);
  }
  v14 = v5();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-quickconvert") != 0 )
  {
    VTexMsg(pFormat: "Quick convert of '%s'...\n", v4);
    sprintf(string, format: "%s.vtf", v4);
    VTFTexture = CreateVTFTexture();
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    LoadFile(&buf, pFileName: string, bFailOnError: true, puiHash: nullptr);
    if ( !VTFTexture->Unserialize(this: VTFTexture, a2: &buf, a3: false, a4: 0) )
      VTexError(pFormat: "Failed to read '%s'!\n", string);
    AttachShtFile(pFullNameWithoutExtension: v4, pTexture: VTFTexture, puiHash: nullptr);
    VTFTexture->SetResourceData(this: VTFTexture, a2: 4411971u, a3: nullptr, a4: 0);
    memset(&buf.m_Get, 0, 9);
    buf.m_nOffset = 0;
    buf.m_nMaxPut = -1;
    CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
    if ( !VTFTexture->Serialize(this: VTFTexture, a2: &buf) )
      VTexError(pFormat: "Failed to write '%s'!\n", string);
    DestroyVTFTexture(pTexture: VTFTexture);
    v16 = fopen(file: string, mode: "wb");
    if ( v16 != nullptr )
    {
      fwrite(buffer: buf.m_Memory.m_pMemory, size: 1u, count: buf.m_Put, stream: v16);
      fclose(stream: v16);
    }
    else
    {
      VTexError(pFormat: "Failed to open '%s' for writing!\n", string);
    }
    VTexMsg(pFormat: "... succeeded.\n");
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return 1;
    }
    return 1;
  }
  VTexConfigInfo_t::VTexConfigInfo_t(this: &info);
  v55 = LoadConfigFile(pFileBaseName: v4, &info);
  v17 = v5();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v17 + 40))(a1: v17, a2: "-extractsrc") == 0
    || bConvertTo360PwlSrgb )
  {
LABEL_95:
    v32 = v5();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v32 + 40))(a1: v32, a2: "-dontbuild") != 0 )
      return 1;
    if ( v55 == 0 && LoadConfigFile(pFileBaseName: v4, &info) == 0 )
      return 0;
    if ( g_bOldCubemapPath || g_bUsePfm )
    {
      if ( !info.m_bIsCubeMap )
        info.m_bIsCubeMap = IsCubeFromFileNames(inputBaseName: v4);
    }
    else if ( IsCubeFromFileNames(inputBaseName: v4) )
    {
      VTexError(pFormat: "File is old-style cubemap. Convert to new-style cubemap (single 'T-shape' image) or use old pat"
                         "h with '-oldcubepath'");
    }
    if ( bConvertTo360PwlSrgb )
      info.m_vtfProcOptions.flags0 |= 0x800u;
    if ( info.m_nStartFrame == -1 )
    {
      if ( info.m_nEndFrame == -1 )
        goto LABEL_110;
    }
    else if ( info.m_nEndFrame != -1 )
    {
LABEL_110:
      v33 = GetBareFileName(pszPathName: v4);
      if ( ProcessFiles(pFullNameWithoutExtension: v4, pOutputDir: pnbuf, pBaseName: v33, &info) == 0 )
        return 0;
      if ( g_ShaderName != nullptr )
      {
        sprintf(string: v44, format: "%s/%s.vmt", pnbuf, v33);
        v34 = V_stristr(pStr: pnbuf, pSearch: "materials");
        if ( v34 != nullptr )
        {
          v35 = fopen(file: v44, mode: "r");
          if ( v35 != nullptr )
          {
            if ( !g_Quiet )
            {
              v36 = __iob_func();
              VTexMsgEx(fout: v36 + 2, pFormat: "vmt file \"%s\" already exists\n", v44);
            }
            fclose(stream: v35);
            return 1;
          }
          else
          {
            v37 = fopen(file: v44, mode: "w");
            if ( v37 != nullptr )
            {
              if ( !g_Quiet )
              {
                v38 = __iob_func();
                VTexMsgEx(fout: v38 + 2, pFormat: "Creating vmt file: %s/%s\n", v34, v33);
              }
              fprintf(str: v37, format: "\"%s\"\n", g_ShaderName);
              fprintf(str: v37, format: "{\n");
              fprintf(str: v37, format: "\t\"$baseTexture\" \"%s/%s\"\n", v34 + 10, v33);
              for ( i = 0; i < g_NumVMTParams; ++i )
                fprintf(str: v37, format: "\t\"%s\" \"%s\"\n", g_VMTParams[i].m_szParam, g_VMTParams[i].m_szValue);
              fprintf(str: v37, format: "}\n");
              fclose(stream: v37);
              CP4AutoAddFile::CP4AutoAddFile(this: &v53, szFilename: v44);
              CP4AutoAddFile::~CP4AutoAddFile(this: (CP4AutoEditFile *)&v53);
              return 1;
            }
            else
            {
              VTexWarning(pFormat: "Couldn't open \"%s\" for writing\n", v44);
              return 1;
            }
          }
        }
        VTexWarning(pFormat: "Couldn't find \"materials/\" in output path\n", v44);
      }
      return 1;
    }
    VTexError(pFormat: "%s: If you use startframe, you must use endframe, and vice versa.\n", v4);
    return 0;
  }
  VTexMsg(pFormat: "Extracting from vtf '%s'.\n", pDest);
  VTexMsg(pFormat: "Saving extracted src as '%s'.\n", v4);
  V_snprintf(pDest: path, maxLen: 1024, pFormat: "if not exist %s mkdir %s", v4, v4);
  V_StripFilename(path);
  V_FixSlashes(pname: path, separator: 92);
  system(command: path);
  v18 = CreateVTFTexture();
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  LoadFile(&buf, pFileName: pDest, bFailOnError: true, puiHash: nullptr);
  if ( !v18->Unserialize(this: v18, a2: &buf, a3: false, a4: 0) )
  {
    VTexError(pFormat: "Failed to read '%s'!\n", pDest);
    goto LABEL_33;
  }
  v19 = v18->Width(this: v18);
  _Msg(a1: "vtf width: %d\n", v19);
  v20 = v18->Height(this: v18);
  _Msg(a1: "vtf height: %d\n", v20);
  v21 = v18->FrameCount(this: v18);
  _Msg(a1: "vtf numFrames: %d\n", v21);
  v22 = v18->FaceCount(this: v18);
  _Msg(a1: "vtf numFaces: %d\n", v22);
  v23 = !v18->IsCubeMap(this: v18);
  v24 = "true";
  if ( v23 )
    v24 = "false";
  _Msg(a1: "vtf cubemap: %s\n", v24);
  v25 = (int)v18->Reflectivity(this: v18);
  v26 = *(float *)(v25 + 8);
  v49 = *(_QWORD *)v25;
  v50 = v26;
  _Msg(a1: "vtf reflectivity: %f %f %f\n", *(float *)&v49, *((float *)&v49 + 1), v26);
  v27 = v18->Format(this: v18);
  str1 = (unsigned __int8 *)ImageLoader::ImageFormatInfo(fmt: v27)->m_pName;
  _Msg(a1: "vtf format: %s\n", (const char *)str1);
  if ( v18->FrameCount(this: v18) > 1 )
  {
    VTexError(pFormat: "Vtf source extraction is not implemented for multiple frames!\n");
    goto LABEL_33;
  }
  if ( v18->FaceCount(this: v18) <= 1 && !v18->IsCubeMap(this: v18) )
  {
    VTexMsg(pFormat: "Extracting image data '%s.tga'...\n", v4);
    V_snprintf(pDest: command, maxLen: 2047, pFormat: "vtf2tga.exe -i %s -o %s.tga", pDest, v4);
    if ( system(command) != 0 )
    {
      VTexError(pFormat: "Failed to extract image data!\n");
      goto LABEL_33;
    }
    sprintf(string: szFilename, format: "%s.tga", pInputBaseName);
    CP4AutoAddFile::CP4AutoAddFile(this: &v54, szFilename);
    CP4AutoAddFile::~CP4AutoAddFile(this: (CP4AutoEditFile *)&v54);
    V_snprintf(pDest: file, maxLen: 1023, pFormat: "%s.txt", pInputBaseName);
    VTexMsg(pFormat: "Saving text data '%s.txt'...\n", pInputBaseName);
    v28 = 0;
    while ( 1 )
    {
      v29 = nullptr;
      if ( v28 == 1 )
      {
        v29 = fopen(file, mode: "wt");
        if ( v29 == nullptr )
        {
          CP4AutoEditFile::CP4AutoEditFile(this: (CP4AutoEditFile *)&v54, szFilename: file);
          v29 = fopen(file, mode: "wt");
          if ( v29 == nullptr )
          {
            VTexError(pFormat: "Failed to create '%s'!\n", file);
            CP4AutoAddFile::~CP4AutoAddFile(this: (CP4AutoEditFile *)&v54);
            goto LABEL_33;
          }
          CP4AutoAddFile::~CP4AutoAddFile(this: (CP4AutoEditFile *)&v54);
        }
      }
      strstr(str1, str2: "BGR");
      if ( v30 != 0 || (strstr(str1, str2: "RGB"), v31 != 0) )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "nocompress 1\n");
      }
      if ( (v18->Flags(this: v18) & 0x100) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "nomip 1\n");
      }
      if ( (v18->Flags(this: v18) & 0x200) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "nolod 1\n");
      }
      if ( (v18->Flags(this: v18) & 4) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "clamps 1\n");
      }
      if ( (v18->Flags(this: v18) & 8) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "clampt 1\n");
      }
      if ( (v18->Flags(this: v18) & 0x2000000) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "clampu 1\n");
      }
      if ( (v18->Flags(this: v18) & 0x800) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "procedural 1\n");
      }
      if ( (v18->Flags(this: v18) & 2) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "trilinear 1\n");
      }
      if ( (v18->Flags(this: v18) & 1) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "pointsample 1\n");
      }
      if ( (v18->Flags(this: v18) & 0x10) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "anisotropic 1\n");
      }
      if ( (v18->Flags(this: v18) & 0x20) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "dxt5 1\n");
      }
      if ( (v18->Flags(this: v18) & 0x80u) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "normal 1\n");
      }
      if ( (v18->Flags(this: v18) & 0x400) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "allmips 1\n");
      }
      if ( (v18->Flags(this: v18) & 0x10000000) != 0 )
      {
        if ( v28 == 0 )
          goto LABEL_93;
        fprintf(str: v29, format: "mostmips 1\n");
      }
      if ( v28 == 1 )
      {
        fclose(stream: v29);
        CP4AutoAddFile::CP4AutoAddFile(this: &v53, szFilename: file);
        CP4AutoAddFile::~CP4AutoAddFile(this: (CP4AutoEditFile *)&v53);
      }
      else if ( v28 == 0 )
      {
        goto LABEL_94;
      }
LABEL_93:
      if ( ++v28 >= 2 )
      {
LABEL_94:
        VTexMsg(pFormat: "'%s' extracted.\n", pInputBaseName);
        CUtlBuffer::~CUtlBuffer(this: &buf);
        DestroyVTFTexture(pTexture: v18);
        v4 = pInputBaseName;
        v5 = _CommandLine;
        goto LABEL_95;
      }
    }
  }
  VTexError(pFormat: "Vtf source extraction is not implemented for cubemaps!\n");
LABEL_33:
  CUtlBuffer::~CUtlBuffer(this: &buf);
  DestroyVTFTexture(pTexture: v18);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009F70
// Name: public: virtual bool CVTexCompiler::CompileResource(char const __near *,class IResourceCompilerRegistry __near *,class CResourceStream __near *,class CResourceStream __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVTexCompiler::CompileResource@<al>(
        CVTexCompiler *this@<ecx>,
        int a2@<edi>,
        BitmapFileType_t pFullPath,
        IResourceCompilerRegistry *pRegistry,
        CResourceStream *pPermanentStream,
        CResourceStream *pDataStream)
{
  const char *v6; // ebx
  CDmePrecompiledTexture *v7; // edi
  char result; // al
  const char *m_pAsString; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CVTFTexture *v13; // ecx
  char v14; // bl
  char pFullDir[260]; // [esp+Ch] [ebp-10Ch] BYREF
  CVTexCompiler *v16; // [esp+110h] [ebp-8h]
  unsigned int nInputHash; // [esp+114h] [ebp-4h] BYREF

  v16 = this;
  CRC32_Init(pulCRC: &nInputHash);
  v6 = (const char *)pFullPath;
  v7 = LoadConfigFile_0(a1: a2, (char *)pFullPath, pMode: &pFullPath, pInputHash: &nInputHash);
  result = CDmePrecompiledTexture::ValidateValues(this: v7);
  if ( result != 0 )
  {
    m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    v10 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
            a1: g_pDataModel,
            a2: (CUtlSymbolLarge)CDmeTexture::m_classType.u.m_Id,
            a3: m_pAsString,
            a4: DMFILEID_INVALID,
            a5: nullptr);
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
    v12 = v11;
    if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeTexture::m_classType) )
      v13 = (CVTFTexture *)v12;
    else
      v13 = nullptr;
    if ( v13 != nullptr )
      pFullPath = CVTFTexture::MipCount(this: v13);
    else
      pFullPath = BITMAP_FILE_TYPE_UNKNOWN;
    CDmAttribute::SetValue<enum DmElementHandle_t>(
      this: v7->m_pSourceTexture.m_pAttribute,
      value: (const DmElementHandle_t *)&pFullPath);
    V_strncpy(pDest: pFullDir, pSrc: v6, maxLen: 260);
    V_StripFilename(path: pFullDir);
    LoadSourceImages_0(pFullDir, pPrecompiledTexture: v7, mode: (Bitmap_t *)&nInputHash);
    CRC32_Final(pulCRC: &nInputHash);
    v14 = CVTexCompiler::CompileResource(
            this: v16,
            pElement: v7,
            pElementFileName: v6,
            pRegistry,
            pPermanentStream,
            pDataStream);
    g_pDataModel->RemoveFileId(this: g_pDataModel, a2: v7->m_fileId);
    return v14;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A0A0
// Name: public: virtual bool CVTexCompiler::CompileResource(class CUtlBuffer __near &,char const __near *,class IResourceCompilerRegistry __near *,class CResourceStream __near *,class CResourceStream __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVTexCompiler::CompileResource(
        CVTexCompiler *this,
        CUtlBuffer *buf,
        const char *pFullPath,
        IResourceCompilerRegistry *pRegistry,
        CResourceStream *pPermanentStream,
        CResourceStream *pDataStream)
{
  const char *v6; // ebx
  char result; // al
  CDmElement *v9; // eax
  CDmePrecompiledTexture *v10; // esi
  char v11; // bl

  v6 = pFullPath;
  result = g_pDataModel->Unserialize(
             this: g_pDataModel,
             a2: buf,
             a3: nullptr,
             a4: nullptr,
             a5: nullptr,
             a6: pFullPath,
             a7: CR_FORCE_COPY,
             a8: (DmElementHandle_t *)&pFullPath);
  if ( result != 0 )
  {
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: pFullPath);
    v10 = (CDmePrecompiledTexture *)v9;
    if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmElement::m_classType) )
      v10 = nullptr;
    v11 = CVTexCompiler::CompileResource(
            this,
            pElement: v10,
            pElementFileName: v6,
            pRegistry,
            pPermanentStream,
            pDataStream);
    g_pDataModel->RemoveFileId(this: g_pDataModel, a2: v10->m_fileId);
    return v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A140
// Name: bool Process_File(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Process_File(char *pInputBaseName, int maxlen)
{
  const char *FileExtension; // eax
  char result; // al

  FileExtension = V_GetFileExtension(path: pInputBaseName);
  if ( FileExtension != nullptr && _V_stricmp(s1: FileExtension, s2: "pfm") == 0 )
  {
    g_bNoTga = true;
    g_bNoPsd = true;
    g_bUsePfm = true;
  }
  result = Process_File_Internal(pInputBaseName, maxlen, bOutputPwlColorConversion: false, bConvertTo360PwlSrgb: false);
  if ( result != 0 && g_bSupportsXBox360 )
    return Process_File_Internal(pInputBaseName, maxlen, bOutputPwlColorConversion: true, bConvertTo360PwlSrgb: true);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A1C0
// Name: public: virtual int CVTex::VTex(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVTex::VTex(CVTex *this, int argc, int argv)
{
  void (__thiscall ***v3)(_DWORD, int, int); // eax
  char **v4; // edi
  int v5; // ebx
  int v6; // esi
  char *v7; // ecx
  char *v8; // edx
  char v9; // al
  int v10; // ecx
  int v11; // eax
  const char *v12; // ebx
  VTexVMTParam_t *v13; // edx
  bool v14; // cc
  const char **p_m_szValue; // eax
  _iobuf *v16; // eax
  _iobuf *v17; // eax
  const char *const *v18; // edi
  KeyValues *v19; // eax
  KeyValues *v20; // edi
  IFileSystem *v21; // ecx
  bool v22; // bl
  int v23; // eax
  struct CSysModule *Module; // eax
  struct CSysModule *v25; // edi
  void *(__cdecl *Factory)(const char *, int *); // eax
  IP4 *v28; // eax
  char **v29; // ebx
  const char *v30; // eax
  IP4_vtbl *v31; // edi
  void *(__cdecl *v32)(const char *, int *); // eax
  int i; // edi
  const char *FileExtension; // eax
  const char *m_szParam; // [esp+20h] [ebp-55Ch]
  const char *v36; // [esp+24h] [ebp-558h]
  char ext[256]; // [esp+34h] [ebp-548h] BYREF
  _WIN32_FIND_DATAA wfd; // [esp+134h] [ebp-448h] BYREF
  char filename[256]; // [esp+274h] [ebp-308h] BYREF
  char pInputBaseName[260]; // [esp+374h] [ebp-208h] BYREF
  char basedir[260]; // [esp+478h] [ebp-104h] BYREF

  v3 = (void (__thiscall ***)(_DWORD, int, int))_CommandLine(a1: this);
  v4 = (char **)argv;
  v5 = argc;
  (**v3)(a1: v3, a2: argc, a3: argv);
  if ( g_bUsedAsLaunchableDLL )
  {
    _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
    _LoggingSystem_RegisterLoggingListener(a1: &g_VTexLoggingListener);
  }
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 1,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  if ( argc < 2 )
    VTexError(pFormat: "\n"
                       "  Usage: vtex [-outdir dir] [-nopause] [-mkdir] [-shader ShaderName] [-vmtparam Param Value] tex1"
                       ".txt tex2.txt ...\n"
                       "\n"
                       "  -quiet            : don't print anything out, don't pause for input\n"
                       "  -warningsaserrors : treat warnings as errors\n"
                       "  -nopause          : don't pause for input\n"
                       "  -nomkdir          : don't create destination folder if it doesn't exist\n"
                       "  -shader           : make a .vmt for this texture, using this shader (e.g. \"vtex -shader UnlitG"
                       "eneric blah.tga\")\n"
                       "  -vmtparam         : adds parameter and value to the .vmt file\n"
                       "  -outdir <dir>     : write output to the specified dir regardless of source filename and vprojec"
                       "t\n"
                       "  -deducepath       : deduce path of sources by target file names\n"
                       "  -extractsrc       : extract approximate src art out of a vtf\n"
                       "  -dontbuild        : don't build the input files into VTFs (usually used with extractsrc)\n"
                       "  -quickconvert     : use with \"-nop4 -dontusegamedir -quickconvert\" to upgrade old .vmt files\n"
                       "  -dontusegamedir   : output files in same folder as inputs (for use with -extractsrc and -quickc"
                       "onvert)\n"
                       "  -crcvalidate      : validate .vmt against the sources\n"
                       "  -crcforce         : generate a new .vmt even if sources crc matches\n"
                       "  -nop4             : don't check files out in Perforce\n"
                       "  -nopsd            : skip .psd files (e.g. use this with \"vtex *.*\")\n"
                       "  -notga            : skip .tga files (e.g. use this with \"vtex *.*\")\n"
                       "  -oldcubepath      : old cubemap method, expects 6 input files, suffixed: 'up', 'dn', 'lf', 'rt'"
                       ", 'ft', 'bk'\n"
                       "\n"
                       "\teg: -vmtparam $ignorez 1 -vmtparam $translucent 1\n"
                       "\n"
                       "  Note that you can use wildcards and that you can also chain them\n"
                       "  e.g. materialsrc/monster1/*.tga materialsrc/monster2/*.tga\n");
  v6 = 1;
  g_UseGameDir = true;
  if ( argc > 1 )
  {
    while ( _V_stricmp(s1: v4[v6], s2: "-quiet") != 0 )
    {
      if ( _V_stricmp(s1: v4[v6], s2: "-nopause") == 0 )
      {
        g_NoPause = true;
        goto LABEL_48;
      }
      if ( _V_stricmp(s1: v4[v6], s2: "-WarningsAsErrors") == 0 )
      {
        g_bWarningsAsErrors = true;
        goto LABEL_48;
      }
      if ( _V_stricmp(s1: v4[v6], s2: "-UseStandardError") == 0 )
      {
        g_bUseStandardError = true;
        goto LABEL_48;
      }
      if ( _V_stricmp(s1: v4[v6], s2: "-nopsd") == 0 )
      {
        g_bNoPsd = true;
        goto LABEL_48;
      }
      if ( _V_stricmp(s1: v4[v6], s2: "-notga") == 0 )
      {
        g_bNoTga = true;
        goto LABEL_48;
      }
      if ( _V_stricmp(s1: v4[v6], s2: "-nomkdir") == 0 )
      {
        g_CreateDir = false;
        goto LABEL_48;
      }
      if ( _V_stricmp(s1: v4[v6], s2: "-mkdir") == 0 )
      {
        g_CreateDir = true;
        goto LABEL_48;
      }
      if ( _V_stricmp(s1: v4[v6], s2: "-game") != 0 )
      {
        if ( _V_stricmp(s1: v4[v6], s2: "-outdir") == 0 )
        {
          v7 = v4[v6 + 1];
          v8 = g_ForcedOutputDir;
          do
          {
            v9 = *v7;
            *v8++ = *v7++;
          }
          while ( v9 != 0 );
          v6 += 2;
          goto LABEL_49;
        }
        if ( _V_stricmp(s1: v4[v6], s2: "-dontusegamedir") == 0 )
        {
          g_UseGameDir = false;
          goto LABEL_48;
        }
        if ( _V_stricmp(s1: v4[v6], s2: "-shader") == 0 )
        {
          if ( ++v6 >= v5 )
            goto LABEL_50;
          g_ShaderName = v4[v6];
          goto LABEL_48;
        }
        if ( _V_stricmp(s1: v4[v6], s2: "-vproject") != 0 )
        {
          if ( _V_stricmp(s1: v4[v6], s2: "-vmtparam") == 0 )
          {
            v10 = g_NumVMTParams;
            if ( g_NumVMTParams >= 16 )
            {
              v17 = __iob_func();
              VTexMsgEx(fout: v17 + 2, pFormat: "Exceeded max number of vmt parameters, extra ignored ( max %d )\n", 16);
            }
            else
            {
              ++v6;
              v11 = v5 - 1;
              if ( v6 < v5 - 1 )
              {
                v12 = v4[v6++];
                v13 = &g_VMTParams[g_NumVMTParams];
                v14 = v6 < v11;
                v13->m_szParam = v12;
                p_m_szValue = &g_VMTParams[v10].m_szValue;
                if ( v14 )
                  *p_m_szValue = v4[v6++];
                else
                  *p_m_szValue = defaultValue;
                if ( !g_Quiet )
                {
                  v36 = *p_m_szValue;
                  m_szParam = v13->m_szParam;
                  v16 = __iob_func();
                  VTexMsgEx(fout: v16 + 2, pFormat: "Adding .vmt parameter: \"%s\"\t\"%s\"\n", m_szParam, v36);
                  v10 = g_NumVMTParams;
                }
                v5 = argc;
                g_NumVMTParams = v10 + 1;
              }
            }
            goto LABEL_49;
          }
          if ( _V_stricmp(s1: v4[v6], s2: "-oldcubepath") != 0 )
          {
            if ( *v4[v6] != 45 )
              goto LABEL_50;
          }
          else
          {
            VTexMsg(pFormat: "Using old cubemap method. Expecting 6 input files, suffixed: 'up', 'dn', 'lf', 'rt', 'ft', 'bk'\n");
            g_bOldCubemapPath = true;
          }
          goto LABEL_48;
        }
        v6 += 2;
      }
      else
      {
        v6 += 2;
      }
LABEL_49:
      if ( v6 >= v5 )
        goto LABEL_50;
    }
    g_Quiet = true;
    g_NoPause = true;
LABEL_48:
    ++v6;
    goto LABEL_49;
  }
LABEL_50:
  v18 = (const char *const *)&v4[v6];
  g_suggestGameDirHelper.m_pszInputFiles = v18;
  g_suggestGameDirHelper.m_numInputFiles = v5 - v6;
  SetSuggestGameInfoDirFn(pfnNewFn: (bool (__cdecl *)(const CFSSteamSetupInfo *, char *, int, bool *))CSuggestGameDirHelper::SuggestFn);
  if ( g_UseGameDir && g_pFileSystem == nullptr )
  {
    FileSystem_Init(pBSPFilename: *v18, maxMemoryUsage: 0, initType: FS_INIT_FULL, bOnlyUseFilename: false);
    V_FixSlashes(pname: gamedir, separator: 47);
  }
  v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v19 != nullptr )
  {
    v20 = KeyValues::KeyValues(this: v19, setName: "gameinfo.txt");
    if ( v20 != nullptr )
    {
      if ( g_pFileSystem != nullptr
        && KeyValues::LoadFromFile(
             this: v20,
             filesystem: g_pFileSystem,
             resourceName: "gameinfo.txt",
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        g_bSupportsXBox360 = KeyValues::GetInt(this: v20, keyName: "SupportsXBox360", defaultValue: 0) != 0;
      }
      KeyValues::deleteThis(this: v20);
    }
  }
  v21 = g_pFullFileSystem;
  v22 = false;
  if ( g_pFullFileSystem != nullptr )
    v22 = g_pFullFileSystem->FileExists(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: "p4lib.dll",
            a3: "EXECUTABLE_PATH");
  if ( g_bUsedAsLaunchableDLL )
  {
    v23 = _CommandLine(a1: v21);
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v23 + 40))(a1: v23, a2: "-nop4") == 0 && v22 )
    {
      Module = Sys_LoadModule(pModuleName: "p4lib.dll");
      v25 = Module;
      if ( Module == nullptr )
      {
        VTexMsg(pFormat: "Can't load %s.\n", "p4lib.dll");
        return -1;
      }
      Factory = Sys_GetFactory(pModule: Module);
      if ( Factory == nullptr )
      {
        VTexMsg(pFormat: "Can't get factory from %s.\n", "p4lib.dll");
        Sys_UnloadModule(pModule: v25);
        return -1;
      }
      v28 = (IP4 *)Factory(a1: "VP4002", a2: nullptr);
      p4 = v28;
      if ( v28 != nullptr )
      {
        v31 = v28->__vftable;
        v32 = FileSystem_GetFactory();
        v31->Connect(this: p4, a2: v32);
        p4->Init(this: p4);
        goto LABEL_71;
      }
      VTexMsg(pFormat: "Can't get IP4 interface from %s, proceeding with -nop4.\n", "p4lib.dll");
    }
  }
  CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: true);
LABEL_71:
  CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "VTex Auto Checkout");
  if ( v6 < argc )
  {
    v29 = (char **)argv;
    do
    {
      v30 = v29[v6];
      if ( *v30 != 45 )
      {
        V_strncpy(pDest: pInputBaseName, pSrc: v30, maxLen: 260);
        if ( _V_strstr(s1: pInputBaseName, search: "*.") != nullptr )
        {
          _splitpath(path: pInputBaseName, drive: nullptr, dir: nullptr, fname: nullptr, ext);
          if ( !V_ExtractFilePath(path: pInputBaseName, dest: basedir, destSize: 260) )
            strcpy(basedir, ".\\");
          argv = -1;
          for ( i = Find_Files(&wfd, hResult: (void **)&argv, basedir, extension: ext);
                i != 0;
                i = Find_Files(&wfd, hResult: (void **)&argv, basedir, extension: ext) )
          {
            sprintf(string: filename, format: "%s%s", basedir, wfd.cFileName);
            if ( wfd.cFileName[0] != 46 && i == 1 )
            {
              FileExtension = V_GetFileExtension(path: filename);
              if ( FileExtension != nullptr && _V_stricmp(s1: FileExtension, s2: "pfm") == 0 )
              {
                g_bNoTga = true;
                g_bNoPsd = true;
                g_bUsePfm = true;
              }
              if ( Process_File_Internal(
                     pInputBaseName: filename,
                     maxlen: 256,
                     bOutputPwlColorConversion: false,
                     bConvertTo360PwlSrgb: false) != 0
                && g_bSupportsXBox360 )
              {
                Process_File_Internal(
                  pInputBaseName: filename,
                  maxlen: 256,
                  bOutputPwlColorConversion: true,
                  bConvertTo360PwlSrgb: true);
              }
            }
          }
        }
        else
        {
          Process_File(pInputBaseName, maxlen: 260);
        }
      }
      ++v6;
    }
    while ( v6 < argc );
  }
  if ( g_bUsedAsLaunchableDLL && p4 != nullptr )
  {
    p4->Shutdown(this: p4);
    p4->Disconnect(this: p4);
  }
  if ( !g_NoPause )
  {
    printf(format: "\nHit a key to continue\n");
    getch();
  }
  if ( g_bUsedAsLaunchableDLL )
    _LoggingSystem_PopLoggingState(a1: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000A900
// Name: public: virtual bool CTier2DmAppSystem<class IResourceCompiler,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier2DmAppSystem<IResourceCompiler,0>::Connect(
        CTier2DmAppSystem<IResourceCompiler,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // esi
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+4h] [ebp-4h] BYREF

  v2 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  ConnectDataModel(factory: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A940
// Name: public: virtual void CTier2DmAppSystem<class IResourceCompiler,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2DmAppSystem<IResourceCompiler,0>::Shutdown(CTier2DmAppSystem<IResourceCompiler,0> *this)
{
  ShutdownDataModel();
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x1000A960
// Name: public: virtual void CTier2DmAppSystem<class IResourceCompiler,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2DmAppSystem<IResourceCompiler,0>::Disconnect(CTier2DmAppSystem<IResourceCompiler,0> *this)
{
  DisconnectDataModel();
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x1003B080
// Name: public: int CUtlVector<struct ElementPathItem_t,class CUtlMemory<struct ElementPathItem_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ElementPathItem_t,CUtlMemory<ElementPathItem_t,int>>::InsertBefore(
        CUtlVector<ElementPathItem_t,CUtlMemory<ElementPathItem_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ElementPathItem_t *m_pMemory; // ecx
  int v6; // eax
  ElementPathItem_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->hElement = DMELEMENT_HANDLE_INVALID;
    v7->hAttribute = DMATTRIBUTE_HANDLE_INVALID;
    v7->nIndex = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1003E880
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::Find(enum DmElementHandle_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::Find(
        CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *this,
        const DmElementHandle_t *src)
{
  int m_Size; // edx
  int result; // eax
  DmElementHandle_t *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003EBF0
// Name: public: void CUtlMemory<class IDmFormatUpdater __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<IDmFormatUpdater *,int>::Grow(CUtlMemory<S3RGBA,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  S3RGBA *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EC80
// Name: public: void CUtlMemory<class Quaternion,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<Quaternion,int>::Grow(CUtlMemory<CUtlBinaryBlock,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlBinaryBlock *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlBinaryBlock *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlBinaryBlock *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003ED10
// Name: public: void CUtlMemory<class VMatrix,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<VMatrix,int>::Grow(CUtlMemory<VMatrix,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  VMatrix *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F690
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int num)
{
  DmeTime_t *m_pMemory; // edx
  unsigned int v4; // eax
  DmeTime_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 4 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (DmeTime_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (DmeTime_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F6F0
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int num)
{
  bool *m_pMemory; // eax
  bool *v4; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      v4 = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      v4 = (bool *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F750
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int num)
{
  Vector2D *m_pMemory; // edx
  unsigned int v4; // eax
  Vector2D *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 8 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (Vector2D *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (Vector2D *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F7B0
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int num)
{
  CUtlBinaryBlock *m_pMemory; // edx
  unsigned int v4; // eax
  CUtlBinaryBlock *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 16 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CUtlBinaryBlock *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (CUtlBinaryBlock *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F810
// Name: public: void CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::EnsureCapacity(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int num)
{
  VMatrix *m_pMemory; // edx
  unsigned int v4; // eax
  VMatrix *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = num << 6;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F870
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(int,enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
        CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *this,
        int elem,
        DmElementHandle_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmElementHandle_t *m_pMemory; // ecx
  int v7; // eax
  DmElementHandle_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1003F8E0
// Name: public: int CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbolLarge *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlSymbolLarge *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->u.m_Id = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1003FE20
// Name: public: void CUtlVector<class CDmeHandle<class CDmElement,2>,class CUtlMemory<class CDmeHandle<class CDmElement,2>,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmeHandle<CDmElement,2>,CUtlMemory<CDmeHandle<CDmElement,2>,int>>::Purge(
        CUtlVector<CDmeHandle<CDmElement,2>,CUtlMemory<CDmeHandle<CDmElement,2>,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CDmeHandle<CDmElement,2> *m_pMemory; // ecx

  for ( i = this->m_Size - 1; i >= 0; --i )
  {
    if ( g_pDataModel != nullptr )
      CDmeElementRefHelper::Unref(
        this: &this->m_Memory.m_pMemory[i],
        hElement: this->m_Memory.m_pMemory[i].m_handle,
        handleType: HT_UNDO);
  }
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FE90
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v6; // eax
  CUtlBinaryBlock *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v7, growSize: 0, initSize: 0);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10046360
// Name: public: int CUtlVector<float,class CUtlMemory<float,int>>::InsertBefore(int,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float,CUtlMemory<float,int>>::InsertBefore(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        int elem,
        float *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  float *m_pMemory; // ecx
  int v7; // eax
  float *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100463D0
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  S3RGBA *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10046440
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertBefore(int,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        bool *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v7; // eax
  bool *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100464A0
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertMultipleBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10046510
// Name: public: int CUtlVector<class Color,class CUtlMemory<class Color,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::InsertMultipleBefore(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Color *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  Color *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = 0;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100465A0
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertBefore(int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        const Vector2D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  Vector2D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10046610
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        const CVTFTexture::ResourceMemorySection *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v7; // eax
  CVTFTexture::ResourceMemorySection *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10046690
// Name: public: int CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10046710
// Name: public: int CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::InsertBefore(int,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        int elem,
        const Vector4D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector4D *m_pMemory; // ecx
  int v7; // eax
  Vector4D *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10046790
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10046800
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertBefore(int,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        const Quaternion *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v7; // eax
  Quaternion *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10046880
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertBefore(int,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        const VMatrix *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<VMatrix,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy((void *)&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100468F0
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<VMatrix,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + num], src: &m_pMemory[elem], count: v9 << 6);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10046960
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int,class CUtlBinaryBlock const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        const CUtlBinaryBlock *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  CUtlBinaryBlock *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100469D0
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertMultipleBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlBinaryBlock *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 16 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlBinaryBlock::CUtlBinaryBlock(this: v12, growSize: 0, initSize: 0);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10046A70
// Name: public: int CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertMultipleBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  DmeTime_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_tms = 0x80000000;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10054220
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlBinaryBlock *v3; // esi
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_nActualLength = 0;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v4;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BE50
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::FastRemove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf
  int m_Size; // eax
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  __int64 v8; // xmm0_8
  CUtlBinaryBlock *v9; // eax

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v7 = m_Size;
      v8 = *(_QWORD *)&this->m_Memory.m_pMemory[v7 - 1].m_Memory.m_pMemory;
      v9 = &this->m_Memory.m_pMemory[v7 - 1];
      *(_QWORD *)&m_pMemory[elem].m_Memory.m_pMemory = v8;
      *(_QWORD *)&m_pMemory[elem].m_Memory.m_nGrowSize = *(_QWORD *)&v9->m_Memory.m_nGrowSize;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BED0
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::Remove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 16 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1005BF40
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveMultiple(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int *v9; // esi
  bool v10; // sf
  bool v11; // zf
  int v12; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]
  int elema; // [esp+18h] [ebp+8h]

  v5 = num;
  v6 = elem + num;
  v7 = elem + num - 1;
  v12 = elem + num;
  if ( v7 >= elem )
  {
    v8 = 16 * v7;
    elema = 16 * v7;
    v13 = num;
    do
    {
      v9 = (int *)((char *)this->m_Memory.m_pMemory + v8);
      v10 = v9[2] < 0;
      v9[3] = 0;
      if ( !v10 )
      {
        if ( *v9 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*v9);
          v6 = v12;
          v8 = elema;
          *v9 = 0;
        }
        v9[1] = 0;
      }
      v8 -= 16;
      v11 = v13-- == 1;
      elema = v8;
    }
    while ( !v11 );
    v5 = num;
  }
  if ( this->m_Size - elem - v5 > 0 && v5 > 0 )
  {
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[v6],
      count: 16 * (this->m_Size - elem - v5));
    v5 = num;
  }
  this->m_Size -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x10060E40
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::CopyArray(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::CopyArray(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        const float *pArray,
        int size)
{
  int v3; // ebx
  int v4; // edi
  const float *v6; // ecx
  const float *v7; // eax
  int v8; // edx
  unsigned int v9; // ecx
  char *v10; // edx
  int v11; // ebx
  double v12; // st7
  char *v13; // edx
  int v14; // [esp+14h] [ebp-4h]

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)this,
    elem: 0,
    num: size);
  v6 = pArray;
  if ( size >= 4 )
  {
    v7 = pArray + 2;
    v8 = -8 - (_DWORD)pArray;
    v9 = ((unsigned int)(size - 4) >> 2) + 1;
    v14 = 8;
    v4 = 4 * v9;
    while ( 1 )
    {
      v10 = (char *)v7 + v8;
      *(float *)&v10[(unsigned int)this->m_Memory.m_pMemory] = *(v7 - 2);
      *(float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 4] = *(v7 - 1);
      v11 = v14;
      v14 += 16;
      *(float *)((char *)this->m_Memory.m_pMemory + v11) = *v7;
      v12 = v7[1];
      v13 = (char *)v7 + 4 - (_DWORD)pArray;
      v7 += 4;
      *(float *)&v13[(unsigned int)this->m_Memory.m_pMemory] = v12;
      if ( --v9 == 0 )
        break;
      v8 = -8 - (_DWORD)pArray;
    }
    v3 = size;
    v6 = pArray;
  }
  for ( ; v4 < v3; ++v4 )
    this->m_Memory.m_pMemory[v4] = v6[v4];
}

//------------------------------------------------------------------------------
// Address: 0x10060EF0
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::CopyArray(bool const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::CopyArray(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        const bool *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x10060F60
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::CopyArray(class Vector2D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::CopyArray(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        const Vector2D *pArray,
        int size)
{
  int v3; // edi
  signed int v6; // edx
  int v7; // edx
  unsigned int v8; // edi
  float *p_y; // eax
  Vector2D *m_pMemory; // ecx
  char *v11; // edx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  Vector2D *v16; // eax
  unsigned int v17; // ecx
  double x; // st7
  int i; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+14h] [ebp-4h]
  const Vector2D *pArraya; // [esp+20h] [ebp+8h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
    (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)this,
    elem: 0,
    num: size);
  v6 = 0;
  if ( size >= 4 )
  {
    v21 = -4 - (_DWORD)pArray;
    v7 = -20 - (_DWORD)pArray;
    v8 = ((unsigned int)(size - 4) >> 2) + 1;
    v20 = 4 - (_DWORD)pArray;
    p_y = &pArray[2].y;
    pArraya = (const Vector2D *)(-20 - (_DWORD)pArray);
    i = 4 * v8;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v11 = (char *)p_y + v7;
      *(float *)&v11[(_DWORD)m_pMemory] = *(p_y - 5);
      *(float *)&v11[(_DWORD)m_pMemory + 4] = *(p_y - 4);
      v12 = (float *)&v11[(unsigned int)this->m_Memory.m_pMemory + 8];
      *v12 = *(p_y - 3);
      v12[1] = *(p_y - 2);
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v21);
      *v13 = *(p_y - 1);
      v13[1] = *p_y;
      v14 = p_y[1];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v20);
      p_y += 8;
      --v8;
      *v15 = v14;
      v15[1] = *(p_y - 6);
      if ( v8 == 0 )
        break;
      v7 = (int)pArraya;
    }
    v3 = size;
    v6 = i;
  }
  for ( ; v6 < v3; v16[v17].y = pArray[v17].y )
  {
    v16 = this->m_Memory.m_pMemory;
    v17 = v6;
    x = pArray[v6++].x;
    v16[v17].x = x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061050
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CopyArray(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        const QAngle *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  QAngle *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  double v13; // st7
  float *v14; // ecx
  float *v15; // ecx
  int v16; // edi
  double v17; // st7
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -20 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 5);
      *(float *)&v10[(_DWORD)m_pMemory + 4] = *(p_z - 4);
      *(float *)&v10[(_DWORD)m_pMemory + 8] = *(p_z - 3);
      v11 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 12];
      *v11 = *(p_z - 2);
      v11[1] = *(p_z - 1);
      v11[2] = *p_z;
      v12 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 4 - (_DWORD)pArray);
      *v12 = p_z[1];
      v12[1] = p_z[2];
      v12[2] = p_z[3];
      v13 = p_z[4];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 16 - (_DWORD)pArray);
      p_z += 12;
      --v7;
      *v14 = v13;
      v14[1] = *(p_z - 7);
      v14[2] = *(p_z - 6);
      if ( v7 == 0 )
        break;
      v6 = -20 - (_DWORD)pArray;
    }
    v5 = i;
    v3 = size;
  }
  if ( v5 < v3 )
  {
    v15 = &pArray[v5].z;
    v16 = v3 - v5;
    do
    {
      v17 = *(v15 - 2);
      v18 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)v15 - 8 - (_DWORD)pArray);
      v15 += 3;
      --v16;
      *v18 = v17;
      v18[1] = *(v15 - 4);
      v18[2] = *(v15 - 3);
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061160
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::CopyArray(class Vector4D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::CopyArray(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        const Vector4D *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  Vector4D *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  float *v16; // ecx
  int v17; // edi
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
    (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this,
    elem: 0,
    num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -24 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 6);
      v11 = (float *)((int)&m_pMemory->x + (_DWORD)v10);
      v11[1] = *(p_z - 5);
      v11[2] = *(p_z - 4);
      v11[3] = *(p_z - 3);
      v12 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 16];
      *v12 = *(p_z - 2);
      v12[1] = *(p_z - 1);
      v12[2] = *p_z;
      v12[3] = p_z[1];
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 8 - (_DWORD)pArray);
      *v13 = p_z[2];
      v13[1] = p_z[3];
      v13[2] = p_z[4];
      v13[3] = p_z[5];
      v14 = p_z[6];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 24 - (_DWORD)pArray);
      p_z += 16;
      --v7;
      *v15 = v14;
      v15[1] = *(p_z - 9);
      v15[2] = *(p_z - 8);
      v15[3] = *(p_z - 7);
      if ( v7 == 0 )
        break;
      v6 = -24 - (_DWORD)pArray;
    }
    v3 = size;
    v5 = i;
  }
  if ( v5 < v3 )
  {
    v16 = &pArray[v5].z;
    v17 = v3 - v5;
    do
    {
      v18 = (float *)((char *)v16 + (unsigned int)this->m_Memory.m_pMemory - 8 - (_DWORD)pArray);
      *v18 = *(v16 - 2);
      v16 += 4;
      --v17;
      v18[1] = *(v16 - 5);
      v18[2] = *(v16 - 4);
      v18[3] = *(v16 - 3);
    }
    while ( v17 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061290
// Name: public: CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::~CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  bool v2; // sf
  CUtlBinaryBlock *m_pMemory; // eax

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062CA0
// Name: public: class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x13 )
    return (CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10062D00
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(class CUtlVector<float,class CUtlMemory<float,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this,
        const CUtlVector<float,CUtlMemory<float,int> > *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10062D20
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *defaultValue)
{
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x100642F0
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0xF )
    return (CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10064360
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmAttribute::GetValue<class CUtlVector<int,class CUtlMemory<int,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x10 )
    return (CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x100643C0
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10064420
// Name: public: class CUtlVector<bool,class CUtlMemory<bool,int>> const __near & CDmAttribute::GetValue<class CUtlVector<bool,class CUtlMemory<bool,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x12 )
    return (CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10064480
// Name: public: class CUtlVector<class Color,class CUtlMemory<class Color,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Color,class CUtlMemory<class Color,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x16 )
    return (CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x100644E0
// Name: public: class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x17 )
    return (CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10064540
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x18 )
    return (CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x100645A0
// Name: public: class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x19 )
    return (CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10064600
// Name: public: class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1A )
    return (CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10064660
// Name: public: class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1B )
    return (CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x100646C0
// Name: public: class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1C )
    return (CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10064720
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10064830
// Name: public: class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage);
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x14 )
    return (CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10066E90
// Name: public: void CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::Sort(int (*)(class CUtlSymbolLarge const __near *,class CUtlSymbolLarge const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::Sort(
        CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  CUtlSymbolLarge::<unnamed_type_u> v6; // ecx
  CUtlSymbolLarge *v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6.m_Id = (int)this->m_Memory.m_pMemory[j - 1].u;
            v7 = &this->m_Memory.m_pMemory[j];
            v7[-1].u.m_Id = v7->u.m_Id;
            v7->u.m_Id = v6.m_Id;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100678A0
// Name: public: void CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::FastRemove(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  CDataModel::ElementIdHandlePair_t *m_pMemory; // edx
  int v4; // eax
  __int64 v5; // xmm0_8
  CDataModel::ElementIdHandlePair_t *v6; // eax
  CDataModel::ElementIdHandlePair_t *v7; // edx

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v4 = m_Size;
      v5 = *(_QWORD *)this->m_Memory.m_pMemory[v4 - 1].m_id.m_Value;
      v6 = &this->m_Memory.m_pMemory[v4 - 1];
      *(_QWORD *)m_pMemory[elem].m_id.m_Value = v5;
      v7 = &m_pMemory[elem];
      *(_QWORD *)&v7->m_id.m_Value[8] = *(_QWORD *)&v6->m_id.m_Value[8];
      v7->m_ref = v6->m_ref;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A160
// Name: public: int CUtlVector<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<CDmAttribute,21>::EntryType_t,CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<FileElementSet_t,20>::EntryType_t,CUtlMemory<CUtlHandleTable<FileElementSet_t,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<FileElementSet_t,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<FileElementSet_t,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1006A1D0
// Name: public: int CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(int,struct CDataModel::ElementIdHandlePair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem,
        const CDataModel::ElementIdHandlePair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDataModel::ElementIdHandlePair_t *m_pMemory; // ecx
  int v7; // eax
  CDataModel::ElementIdHandlePair_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDataModel::ElementIdHandlePair_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CDataModel::ElementIdHandlePair_t::ElementIdHandlePair_t(this: v8, that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1006ED30
// Name: public: class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> __near & CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *__thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(
        CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *this,
        const CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *other)
{
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v2; // esi
  int m_Size; // edi
  int v4; // eax
  int v5; // edi
  _DWORD *v6; // ebx
  CUtlMemory<S3RGBA,int> *v7; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v10; // eax
  int i; // eax
  bool v12; // zf
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v2 = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this;
  m_Size = other->m_Size;
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll((CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this);
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(
    this: v2,
    elem: v2->m_Size,
    num: m_Size);
  if ( m_Size <= 0 )
    return (CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *)v2;
  v4 = 0;
  v16 = 0;
  v15 = m_Size;
  while ( 1 )
  {
    v5 = *(int *)((char *)&other->m_Memory.m_pMemory->m_Size + v4);
    v6 = (DmElementHandle_t **)((char *)&other->m_Memory.m_pMemory->m_Memory.m_pMemory + v4);
    v7 = (CUtlMemory<S3RGBA,int> *)((char *)v2->m_Memory.m_pMemory + v4);
    v7[1].m_pMemory = nullptr;
    if ( v5 != 0 )
    {
      m_nAllocationCount = v7->m_nAllocationCount;
      if ( v5 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v7, num: v5 - m_nAllocationCount);
      v7[1].m_pMemory = (S3RGBA *)((char *)v7[1].m_pMemory + v5);
      m_pMemory = v7->m_pMemory;
      v10 = (int)v7[1].m_pMemory - v5;
      v7[1].m_nAllocationCount = (int)v7->m_pMemory;
      if ( v10 > 0 && v5 > 0 )
        _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: 4 * v10);
    }
    for ( i = 0; i < v5; ++i )
      v7->m_pMemory[i] = *(S3RGBA *)(*v6 + 4 * i);
    v4 = v16 + 20;
    v12 = v15-- == 1;
    v16 += 20;
    if ( v12 )
      break;
    v2 = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10070180
// Name: public: virtual class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near & CDmElementFramework::GetSortedOperators(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *__thiscall CDmElementFramework::GetSortedOperators(
        CDmElementFramework *this)
{
  return &this->m_dependencyGraph.m_operators;
}

//------------------------------------------------------------------------------
// Address: 0x100706B0
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbol *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100707C0
// Name: public: bool CUtlVector<class IDmNotify __near *,class CUtlMemory<class IDmNotify __near *,int>>::FindAndRemove(class IDmNotify __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
        CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *this,
        IDmNotify **src)
{
  int m_Size; // edx
  int v4; // eax
  IDmNotify **m_pMemory; // ebx
  IDmNotify **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10070A00
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this)
{
  bool v2; // sf
  CVTFTexture::ResourceMemorySection *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10073570
// Name: public: CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>>::CUtlVector<class CDmElement __near *,class CUtlMemory<class CDmElement __near *,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *__thiscall CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int>>::CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int>>(
        CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *this,
        int growSize,
        int initSize)
{
  CDmElement **m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (CDmElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10077D40
// Name: public: void CUtlVector<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,class CUtlMemory<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077DE0
// Name: public: CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078C80
// Name: public: void CUtlMemory<class CUtlVector<class CAttributeNode __near *,class CUtlMemory<class CAttributeNode __near *,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CDmElement *,int> *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: m_pMemory,
                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CDmElement *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079840
// Name: public: int CUtlVector<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,class CUtlMemory<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1007A650
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class CDmAttribute __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AFA0
// Name: public: int CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(int,struct CDmElementDictionary::DmIdPair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(
        CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *this,
        int elem,
        const CDmElementDictionary::DmIdPair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmElementDictionary::DmIdPair_t *m_pMemory; // ecx
  int v7; // eax
  CDmElementDictionary::DmIdPair_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DmIdPair_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1007BCD0
// Name: public: int CUtlVector<struct CDmElementDictionary::AttributeInfo_t,class CUtlMemory<struct CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(
        CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmElementDictionary::AttributeInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1007BD30
// Name: public: int CUtlVector<struct CDmElementDictionary::DeletionInfo_t,class CUtlMemory<struct CDmElementDictionary::DeletionInfo_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::AddToTail(
        CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmElementDictionary::DeletionInfo_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1007E610
// Name: public: class CDmAttribute __near * CDmElement::AddAttributeElementArray<class CDmElement>(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::AddAttributeElementArray<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v4 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v4 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_ARRAY_TYPE);
  if ( v4 == nullptr )
    return nullptr;
  CDmAttribute::SetElementTypeSymbol(this: v4, typeSymbol: CDmElement::m_classType);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1007E710
// Name: public: class CDmAttribute __near * CDmElement::SetValue<char const>(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue,
        char bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( bCreateIfNotFound == 0 && !CDmElement::HasAttribute(this, pAttributeName, type: AT_STRING) )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&bCreateIfNotFound, a3: pValue);
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&bCreateIfNotFound);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x1007E790
// Name: public: class CDmAttribute __near * CDmElement::InitValue<char const>(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::InitValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue)
{
  CDmAttribute *result; // eax
  CDmAttribute *Attribute; // esi

  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pValue, a3: pValue);
  result = CDmElement::FindAttribute(this, pAttributeName);
  if ( result == nullptr )
  {
    Attribute = CDmElement::FindAttribute(this, pAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pValue);
      return Attribute;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007EB00
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class CDmElement>(char const __near *,class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<CDmElement>(
        CDmElement *this,
        const char *pAttributeName,
        DmElementHandle_t pElement,
        bool bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( pElement != 0 )
    pElement = CVTFTexture::MipCount(this: (CVTFTexture *)pElement);
  else
    pElement = DMELEMENT_HANDLE_INVALID;
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    if ( !bCreateIfNotFound )
      return nullptr;
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_VALUE_TYPE);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: &pElement);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x1007F820
// Name: public: class CDmElement __near * CDmElement::GetValueElement<class CDmElement>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmElement::GetValueElement<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  DmElementHandle_t *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_10153FA8 = -1;
    dword_10153FAC = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = (DmElementHandle_t *)CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = (DmElementHandle_t *)&`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmElement::m_classType) )
    return v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007F8B0
// Name: public: class Vector const __near & CDmElement::GetValue<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmElement::GetValue<Vector>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return (CDmaVar<Vector> *)CDmAttribute::GetValue<Vector>(this: Attribute);
  else
    return &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x1007F910
// Name: public: class Quaternion const __near & CDmElement::GetValue<class Quaternion>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmElement::GetValue<Quaternion>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return (CDmaVar<Quaternion> *)CDmAttribute::GetValue<Quaternion>(this: Attribute);
  else
    return &`CDmElement::GetValue<Quaternion>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x1007F9D0
// Name: public: class Color const __near & CDmElement::GetValue<class Color>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CDmElement::GetValue<Color>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Color>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Color>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Color>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Color>'::`2'::defaultVal.m_Storage = (Color)-16777216;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return (CDmaVar<Color> *)CDmAttribute::GetValue<Color>(this: Attribute);
  else
    return &`CDmElement::GetValue<Color>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10086390
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmElement::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(this: Attribute);
  else
    return &`CDmElement::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x10086490
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmElement::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(char const __near *,class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmElement *this,
        const char *pAttributeName,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *defaultVal)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
           this: Attribute,
           defaultValue: &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x10086500
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmElement::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(char const __near *,class CUtlVector<float,class CUtlMemory<float,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmElement *this,
        const char *pAttributeName,
        const CUtlVector<float,CUtlMemory<float,int> > *defaultVal)
{
  CDmAttribute *Attribute; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
    return defaultVal;
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
           this: Attribute,
           defaultValue: &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x10086F00
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmElement::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  if ( (`CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
           this,
           pAttributeName,
           defaultVal: &`CDmElement::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x10086F60
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmElement::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmElement *this,
        const char *pAttributeName)
{
  if ( (`CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  return CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
           this,
           pAttributeName,
           defaultVal: &`CDmElement::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x1008D2C0
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090F30
// Name: public: virtual void __near * CBaseAppSystem<class IResourceCompiler>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAppSystem<IResourceCompiler>::QueryInterface(
        CImportCommentary *this,
        KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10094F80
// Name: public: void CDmeTexture::ProcessTexture<class CImageProcessorMemberFunctor<class CDmeTP_ChangeColorChannels>>(class CDmeTexture __near *,class CImageProcessorMemberFunctor<class CDmeTP_ChangeColorChannels> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::ProcessTexture<CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels>>(
        CDmeTexture *this,
        CDmeTexture *pSrcTexture,
        CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels> *func)
{
  CDmeTexture *v3; // esi
  CDmeTexture *v4; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  int v7; // esi
  CVTFTexture *MipLevel; // ebx
  int v9; // edi
  CDmeImage *Image; // esi
  CDmeImage *v11; // eax
  int nFrameCount; // [esp+Ch] [ebp-24h]
  int nMipCount; // [esp+14h] [ebp-1Ch]
  int nImageCount; // [esp+18h] [ebp-18h]
  CDmeImageArray *pDstImageArray; // [esp+1Ch] [ebp-14h]
  CDmeTextureFrame *pDstFrame; // [esp+20h] [ebp-10h]
  int f; // [esp+24h] [ebp-Ch]
  int m; // [esp+28h] [ebp-8h]
  CVTFTexture *v20; // [esp+2Ch] [ebp-4h]

  v3 = pSrcTexture;
  v4 = this;
  CDmElement::CopyAttributesTo(this: pSrcTexture, pCopy: this, depth: TD_NONE);
  CDmeTexture::RemoveAllFrames(this: v4);
  v5 = 0;
  nFrameCount = pSrcTexture->m_Frames.m_Storage.m_Size;
  f = 0;
  if ( nFrameCount > 0 )
  {
    while ( 1 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Frames.m_Storage.m_Memory.m_pMemory[v5]);
      if ( v6 == nullptr || (v20 = (CVTFTexture *)v6, !v6->IsA(this: v6, a2: CDmeTextureFrame::m_classType)) )
        v20 = nullptr;
      pDstFrame = CDmeTexture::AddFrame(this: v4);
      v7 = 0;
      nMipCount = CVTFTexture::LowResWidth(this: v20);
      m = 0;
      if ( nMipCount > 0 )
      {
        do
        {
          MipLevel = (CVTFTexture *)CDmeTextureFrame::GetMipLevel(this: (CDmeTextureFrame *)v20, nIndex: v7);
          pDstImageArray = CDmeTextureFrame::AddMipLevel(this: pDstFrame);
          if ( MipLevel != nullptr )
          {
            v9 = 0;
            nImageCount = CVTFTexture::LowResWidth(this: MipLevel);
            if ( nImageCount > 0 )
            {
              do
              {
                Image = CDmeImageArray::GetImage(this: (CDmeImageArray *)MipLevel, nIndex: v9);
                v11 = CDmeImageArray::AddImage(this: pDstImageArray);
                if ( Image != nullptr )
                  func->m_pMemberFunc(this: func->m_pObject, a2: v11, a3: Image);
                ++v9;
              }
              while ( v9 < nImageCount );
              v7 = m;
            }
          }
          m = ++v7;
        }
        while ( v7 < nMipCount );
        v4 = this;
        v5 = f;
      }
      f = ++v5;
      if ( v5 >= nFrameCount )
        break;
      v3 = pSrcTexture;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5830
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int num)
{
  CVTFTexture::ResourceMemorySection *m_pMemory; // edx
  unsigned int v4; // eax
  CVTFTexture::ResourceMemorySection *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                                         this: _g_pMemAlloc,
                                                                         a2: m_pMemory,
                                                                         a3: v4);
      goto LABEL_5;
    }
    v5 = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A58A0
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResourceEntryInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100A5910
// Name: public: int CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CVTFTexture::ResourceMemorySection *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        *(_QWORD *)&v11->m_nDataAllocSize = 0;
        v11->m_pData = nullptr;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100C3FA0
// Name: _dynamic_initializer_for__CDmElement::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmElement::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmElement::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmElement pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmElement::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4B00
// Name: _dynamic_initializer_for__CDmeTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTexture::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTexture::s_Allocator,
    blockSize: 204,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTexture pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTexture::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4C20
// Name: _dynamic_initializer_for__CDmePrecompiledTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePrecompiledTexture::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePrecompiledTexture::s_Allocator,
    blockSize: 284,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePrecompiledTexture pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePrecompiledTexture::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4F70
// Name: _dynamic_atexit_destructor_for__CDmElement::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmElement::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmElement::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C5300
// Name: _dynamic_atexit_destructor_for__CDmeTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C5370
// Name: _dynamic_atexit_destructor_for__CDmePrecompiledTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePrecompiledTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePrecompiledTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x10005090
// Name: __CreateCVTexIVTex_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVTex *__cdecl _CreateCVTexIVTex_interface()
{
  return &g_VTex;
}

//------------------------------------------------------------------------------
// Address: 0x100050A0
// Name: __CreateCVTexILaunchableDLL_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ILaunchableDLL *__cdecl _CreateCVTexILaunchableDLL_interface()
{
  return &g_VTex.ILaunchableDLL;
}

//------------------------------------------------------------------------------
// Address: 0x100050B0
// Name: __CreateCVTexCompilerIResourceCompiler_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVTexCompiler *__cdecl _CreateCVTexCompilerIResourceCompiler_interface()
{
  return &s_VTexCompiler;
}

//------------------------------------------------------------------------------
// Address: 0x10006000
// Name: class CDmePrecompiledTexture __near * GetElement<class CDmePrecompiledTexture>(enum DmElementHandle_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePrecompiledTexture *__cdecl GetElement<CDmePrecompiledTexture>(DmElementHandle_t hElement)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: hElement);
  v2 = v1;
  if ( v1 != nullptr && v1->IsA(this: v1, a2: CDmePrecompiledTexture::m_classType) )
    return (CDmePrecompiledTexture *)v2;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006040
// Name: class CDmElement __near * GetElement<class CDmElement>(enum DmElementHandle_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl GetElement<CDmElement>(DmElementHandle_t hElement)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: hElement);
  v2 = v1;
  if ( v1 != nullptr && v1->IsA(this: v1, a2: CDmElement::m_classType) )
    return v2;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006360
// Name: class CDmePrecompiledTexture __near * CreateElement<class CDmePrecompiledTexture>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePrecompiledTexture *__cdecl CreateElement<CDmePrecompiledTexture>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmePrecompiledTexture::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmePrecompiledTexture::m_classType) )
    return (CDmePrecompiledTexture *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100C3FD0
// Name: _dynamic_initializer_for__g_CDmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmElement_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmElement_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C3FE0
// Name: _dynamic_initializer_for__g_CDmElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmElement_Helper,
           classname: "DmElement",
           pFactory: &g_CDmElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x100C4000
// Name: _dynamic_initializer_for__g_CDmeElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeElement_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeElement_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4010
// Name: _dynamic_initializer_for__g_CDmeElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeElement_Helper,
           classname: "DmeElement",
           pFactory: &g_CDmeElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x100C4030
// Name: _dynamic_initializer_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataAlloc4__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_DataAlloc4,
    blockSize: 4,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "4-byte data pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_DataAlloc4__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4060
// Name: _dynamic_initializer_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataAlloc8__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_DataAlloc8,
    blockSize: 8,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "8-byte data pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_DataAlloc8__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4090
// Name: _dynamic_initializer_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrAlloc__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_AttrAlloc,
    blockSize: 24,
    numElements: 4096,
    growMode: 2,
    pszAllocOwner: "CDmAttribute pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_AttrAlloc__);
}

//------------------------------------------------------------------------------
// Address: 0x100C40C0
// Name: _dynamic_initializer_for____s_AttrDmUnknownAttribute_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmUnknownAttribute_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<DmUnknownAttribute_t>::`vftable';
    s_pAttrInfo[0] = result;
  }
  else
  {
    s_pAttrInfo[0] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C40F0
// Name: _dynamic_initializer_for____s_Attrint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrint__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<int>::`vftable';
    s_pAttrInfo[2] = result;
  }
  else
  {
    s_pAttrInfo[2] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4120
// Name: _dynamic_initializer_for____s_AttrArrayint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayint__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<int>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[16] = result;
  }
  else
  {
    s_pAttrInfo[16] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4150
// Name: _dynamic_initializer_for____s_Attrfloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrfloat__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<float>::`vftable';
    s_pAttrInfo[3] = result;
  }
  else
  {
    s_pAttrInfo[3] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4180
// Name: _dynamic_initializer_for____s_AttrArrayfloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayfloat__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<float>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[17] = result;
  }
  else
  {
    s_pAttrInfo[17] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C41B0
// Name: _dynamic_initializer_for____s_Attrbool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrbool__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<bool>::`vftable';
    s_pAttrInfo[4] = result;
  }
  else
  {
    s_pAttrInfo[4] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C41E0
// Name: _dynamic_initializer_for____s_AttrArraybool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArraybool__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<bool>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[18] = result;
  }
  else
  {
    s_pAttrInfo[18] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4210
// Name: _dynamic_initializer_for____s_AttrColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrColor__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Color>::`vftable';
    s_pAttrInfo[8] = result;
  }
  else
  {
    s_pAttrInfo[8] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4240
// Name: _dynamic_initializer_for____s_AttrArrayColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayColor__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Color>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[22] = result;
  }
  else
  {
    s_pAttrInfo[22] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4270
// Name: _dynamic_initializer_for____s_AttrVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector2D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector2D>::`vftable';
    s_pAttrInfo[9] = result;
  }
  else
  {
    s_pAttrInfo[9] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C42A0
// Name: _dynamic_initializer_for____s_AttrArrayVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector2D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector2D>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[23] = result;
  }
  else
  {
    s_pAttrInfo[23] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C42D0
// Name: _dynamic_initializer_for____s_AttrVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector>::`vftable';
    s_pAttrInfo[10] = result;
  }
  else
  {
    s_pAttrInfo[10] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4300
// Name: _dynamic_initializer_for____s_AttrArrayVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[24] = result;
  }
  else
  {
    s_pAttrInfo[24] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4330
// Name: _dynamic_initializer_for____s_AttrVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector4D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector4D>::`vftable';
    s_pAttrInfo[11] = result;
  }
  else
  {
    s_pAttrInfo[11] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4360
// Name: _dynamic_initializer_for____s_AttrArrayVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector4D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector4D>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[25] = result;
  }
  else
  {
    s_pAttrInfo[25] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4390
// Name: _dynamic_initializer_for____s_AttrQAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrQAngle__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<QAngle>::`vftable';
    s_pAttrInfo[12] = result;
  }
  else
  {
    s_pAttrInfo[12] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C43C0
// Name: _dynamic_initializer_for____s_AttrArrayQAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayQAngle__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<QAngle>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[26] = result;
  }
  else
  {
    s_pAttrInfo[26] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C43F0
// Name: _dynamic_initializer_for____s_AttrQuaternion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrQuaternion__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Quaternion>::`vftable';
    s_pAttrInfo[13] = result;
  }
  else
  {
    s_pAttrInfo[13] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4420
// Name: _dynamic_initializer_for____s_AttrArrayQuaternion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayQuaternion__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Quaternion>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[27] = result;
  }
  else
  {
    s_pAttrInfo[27] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4450
// Name: _dynamic_initializer_for____s_AttrVMatrix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVMatrix__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<VMatrix>::`vftable';
    s_pAttrInfo[14] = result;
  }
  else
  {
    s_pAttrInfo[14] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4480
// Name: _dynamic_initializer_for____s_AttrArrayVMatrix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVMatrix__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<VMatrix>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[28] = result;
  }
  else
  {
    s_pAttrInfo[28] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C44B0
// Name: _dynamic_initializer_for____s_AttrCUtlSymbolLarge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrCUtlSymbolLarge__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<CUtlSymbolLarge>::`vftable';
    s_pAttrInfo[5] = result;
  }
  else
  {
    s_pAttrInfo[5] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C44E0
// Name: _dynamic_initializer_for____s_AttrArrayCUtlSymbolLarge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayCUtlSymbolLarge__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<CUtlSymbolLarge>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[19] = result;
  }
  else
  {
    s_pAttrInfo[19] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4510
// Name: _dynamic_initializer_for____s_AttrCUtlBinaryBlock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrCUtlBinaryBlock__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<CUtlBinaryBlock>::`vftable';
    s_pAttrInfo[6] = result;
  }
  else
  {
    s_pAttrInfo[6] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4540
// Name: _dynamic_initializer_for____s_AttrArrayCUtlBinaryBlock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayCUtlBinaryBlock__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<CUtlBinaryBlock>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[20] = result;
  }
  else
  {
    s_pAttrInfo[20] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4570
// Name: _dynamic_initializer_for____s_AttrDmeTime_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmeTime_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<DmeTime_t>::`vftable';
    s_pAttrInfo[7] = result;
  }
  else
  {
    s_pAttrInfo[7] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C45A0
// Name: _dynamic_initializer_for____s_AttrArrayDmeTime_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayDmeTime_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<DmeTime_t>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[21] = result;
  }
  else
  {
    s_pAttrInfo[21] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C45D0
// Name: _dynamic_initializer_for____s_AttrDmElementHandle_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmElementHandle_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<enum DmElementHandle_t>::`vftable';
    s_pAttrInfo[1] = result;
  }
  else
  {
    s_pAttrInfo[1] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4600
// Name: _dynamic_initializer_for____s_AttrArrayDmElementHandle_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayDmElementHandle_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<enum DmElementHandle_t>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[15] = result;
  }
  else
  {
    s_pAttrInfo[15] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4630
// Name: _dynamic_initializer_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataModel__()
{
  CDataModel::CDataModel(this: &g_DataModel);
  return atexit(func: dynamic_atexit_destructor_for__g_DataModel__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4650
// Name: _dynamic_initializer_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DmElementFramework__()
{
  CDependencyGraph::CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = nullptr;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nAllocationCount = 256;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nGrowSize = 128;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = (DmElementHandle_t *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: 1024);
  g_DmElementFramework.m_dirtyElements.m_Size = 0;
  g_DmElementFramework.m_dirtyElements.m_pElements = g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory;
  g_DmElementFramework.m_phase = PH_EDIT;
  return atexit(func: dynamic_atexit_destructor_for__g_DmElementFramework__);
}

//------------------------------------------------------------------------------
// Address: 0x100C46C0
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C4700
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2.m_ElementDict);
  s_DMSerializerKeyValues2.m_bFlatMode = false;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4720
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2Flat__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2Flat.m_ElementDict);
  s_DMSerializerKeyValues2Flat.m_bFlatMode = true;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4740
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4750
// Name: _dynamic_initializer_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrNodePool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_AttrNodePool,
    blockSize: 28,
    numElements: 1000,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_AttrNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4780
// Name: _dynamic_initializer_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_OperatorNodePool,
    blockSize: 32,
    numElements: 1000,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_OperatorNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x100C47B0
// Name: _dynamic_initializer_for__s_ImportSFMV9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV9__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV9, formatName: "sfm_v9", nextFormatName: "sfm_v10");
  s_ImportSFMV9.__vftable = (CImportSFMV9_vtbl *)&CImportSFMV9::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C47D0
// Name: _dynamic_initializer_for__s_ImportSFMV8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV8__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV8, formatName: "sfm_v8", nextFormatName: "sfm_v9");
  s_ImportSFMV8.__vftable = (CImportSFMV8_vtbl *)&CImportSFMV8::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C47F0
// Name: _dynamic_initializer_for__s_ImportSFMV7__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV7__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV7, formatName: "sfm_v7", nextFormatName: "sfm_v8");
  s_ImportSFMV7.__vftable = (CImportSFMV7_vtbl *)&CImportSFMV7::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4810
// Name: _dynamic_initializer_for__s_ImportSFMV6__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV6__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV6, formatName: "sfm_v6", nextFormatName: "sfm_v7");
  s_ImportSFMV6.__vftable = (CImportSFMV6_vtbl *)&CImportSFMV6::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4830
// Name: _dynamic_initializer_for__s_ImportSFMV5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV5__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV5, formatName: "sfm_v5", nextFormatName: "sfm_v6");
  s_ImportSFMV5.__vftable = (CImportSFMV5_vtbl *)&CImportSFMV5::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4850
// Name: _dynamic_initializer_for__s_ImportSFMV4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV4__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV4, formatName: "sfm_v4", nextFormatName: "sfm_v5");
  s_ImportSFMV4.__vftable = (CImportSFMV4_vtbl *)&CImportSFMV4::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4870
// Name: _dynamic_initializer_for__s_ImportSFMV3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV3__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV3, formatName: "sfm_v3", nextFormatName: "sfm_v4");
  s_ImportSFMV3.__vftable = (CImportSFMV3_vtbl *)&CImportSFMV3::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4890
// Name: _dynamic_initializer_for__s_ImportSFMV2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV2__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV2, formatName: "sfm_v2", nextFormatName: "sfm_v3");
  s_ImportSFMV2.__vftable = (CImportSFMV2_vtbl *)&CImportSFMV2::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C48B0
// Name: _dynamic_initializer_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ImportDmxV1__()
{
  CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportDmxV1, formatName: "sfm_v1", nextFormatName: "sfm_v2");
  s_ImportDmxV1.__vftable = (CImportSFMV1_vtbl *)&CImportSFMV1::`vftable';
  s_ImportDmxV1.m_fixedElements.m_Elements.m_pMemory = nullptr;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nAllocationCount = 0;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nGrowSize = 0;
  s_ImportDmxV1.m_fixedElements.m_Root = -1;
  s_ImportDmxV1.m_fixedElements.m_NumElements = 0;
  s_ImportDmxV1.m_fixedElements.m_FirstFree = -1;
  s_ImportDmxV1.m_fixedElements.m_LastAlloc.index = -1;
  s_ImportDmxV1.m_fixedElements.m_pElements = nullptr;
  s_ImportDmxV1.m_fixedElements.m_LessFunc = CDefOps<CDmAttribute *>::LessFunc;
  return atexit(func: dynamic_atexit_destructor_for__s_ImportDmxV1__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4B30
// Name: _dynamic_initializer_for__g_CDmeTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4B40
// Name: _dynamic_initializer_for__g_CDmeTexture_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTexture_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTexture_Helper,
           classname: "DmeTexture",
           pFactory: &g_CDmeTexture_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C4C50
// Name: _dynamic_initializer_for__g_CDmePrecompiledTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePrecompiledTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4C60
// Name: _dynamic_initializer_for__g_CDmePrecompiledTexture_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePrecompiledTexture_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePrecompiledTexture_Helper,
           classname: "DmePrecompiledTexture",
           pFactory: &g_CDmePrecompiledTexture_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C4F80
// Name: _dynamic_atexit_destructor_for__g_CDmeElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeElement_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeElement_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x100C4F90
// Name: _dynamic_atexit_destructor_for__g_CDmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmElement_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmElement_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x100C4FA0
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x100C4FB0
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x100C4FC0
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x100C5310
// Name: _dynamic_atexit_destructor_for__g_CDmeTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTexture_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTexture_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x100C5320
// Name: _dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTextureFrame_Factory.m_CallBackList);
}
