// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialobjects/dmeprecompiledtexture.cpp
// Functions: 98
// ============================================================

#include "materialobjects\dmeprecompiledtexture.h"

//------------------------------------------------------------------------------
// Address: 0x004BC7C0
// Name: ComputeDestFormat
// Source: json
//------------------------------------------------------------------------------
ImageFormat __usercall ComputeDestFormat@<eax>(ImageFormat fmt@<ecx>, int nChannelCount@<eax>)
{
  switch ( fmt )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_ABGR8888:
    case IMAGE_FORMAT_ARGB8888:
    case IMAGE_FORMAT_BGRA8888:
      return nChannelCount != 3 ? 5 : 2;
    case IMAGE_FORMAT_RGB888:
    case IMAGE_FORMAT_BGR888:
    case IMAGE_FORMAT_IA88:
    case IMAGE_FORMAT_BGRX8888:
    case IMAGE_FORMAT_RGBX8888:
      return IMAGE_FORMAT_I8;
    case IMAGE_FORMAT_DXT5:
      return IMAGE_FORMAT_DXT1;
    case IMAGE_FORMAT_RGBA16161616F:
      if ( nChannelCount != 2 )
        return IMAGE_FORMAT_R16F;
      return IMAGE_FORMAT_RG1616F;
    case IMAGE_FORMAT_RGB323232F:
      goto $LN8_14;
    case IMAGE_FORMAT_RGBA32323232F:
      if ( nChannelCount == 3 )
        return IMAGE_FORMAT_RGB323232F;
$LN8_14:
      if ( nChannelCount == 2 )
        return IMAGE_FORMAT_RG3232F;
      else
        return IMAGE_FORMAT_R32F;
    case IMAGE_FORMAT_RG1616F:
      return IMAGE_FORMAT_R16F;
    case IMAGE_FORMAT_RG3232F:
      return IMAGE_FORMAT_R32F;
    default:
      return fmt;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BC870
// Name: protected: void CDmeTP_ComputeMipmaps::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::OnConstruction(CDmeTP_ComputeMipmaps *this)
{
  this->m_bNoNiceFiltering.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noNiceFiltering",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoNiceFiltering);
  this->m_bAlphaTestDownsampling.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "alphaTestDownsampling",
                                                  type: AT_BOOL,
                                                  pMemory: &this->m_bAlphaTestDownsampling);
  this->m_flAlphaTestDownsampleThreshhold.m_pAttribute = CDmElement::AddExternalAttribute(
                                                           this,
                                                           pAttributeName: "alphaTestDownsampleThreshhold",
                                                           type: AT_FLOAT,
                                                           pMemory: &this->m_flAlphaTestDownsampleThreshhold);
  this->m_flAlphaTestDownsampleHiFreqThreshhold.m_pAttribute = CDmElement::AddExternalAttribute(
                                                                 this,
                                                                 pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                                                                 type: AT_FLOAT,
                                                                 pMemory: &this->m_flAlphaTestDownsampleHiFreqThreshhold);
}

//------------------------------------------------------------------------------
// Address: 0x004BC8D0
// Name: protected: void CDmePrecompiledTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePrecompiledTexture::OnConstruction(CDmePrecompiledTexture *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  this->m_ImageFileName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "imageFileName",
                                         type: AT_STRING,
                                         pMemory: &this->m_ImageFileName);
  this->m_Processors.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "processors",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Processors);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_Processors.m_pAttribute,
    typeSymbol: CDmeTextureProcessor::m_classType);
  this->m_pSourceTexture.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "sourceTexture",
                                          type: AT_FIRST_VALUE_TYPE,
                                          pMemory: &this->m_pSourceTexture);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pSourceTexture.m_pAttribute, typeSymbol: CDmeTexture::m_classType);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "startFrame", type: AT_INT, pMemory: &this->m_nStartFrame);
  this->m_nStartFrame.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = -1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "endFrame", type: AT_INT, pMemory: &this->m_nEndFrame);
  this->m_nEndFrame.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  value = 1;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "volumeTextureDepth",
         type: AT_INT,
         pMemory: &this->m_nVolumeTextureDepth);
  this->m_nVolumeTextureDepth.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  value = 1;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "textureArraySize",
         type: AT_INT,
         pMemory: &this->m_nTextureArraySize);
  this->m_nTextureArraySize.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, &value);
  this->m_nTextureType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "textureType",
                                        type: AT_INT,
                                        pMemory: &this->m_nTextureType);
  value = 1065353216;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "bumpScale",
         type: AT_FLOAT,
         pMemory: &this->m_flBumpScale);
  this->m_flBumpScale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, (const float *)&value);
  value = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "pfmScale", type: AT_FLOAT, pMemory: &this->m_flPFMScale);
  this->m_flPFMScale.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, (const float *)&value);
  this->m_nFilterType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "filterType",
                                       type: AT_INT,
                                       pMemory: &this->m_nFilterType);
  this->m_bClampS.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clamps",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampS);
  this->m_bClampT.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampt",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampT);
  this->m_bClampU.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampu",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampU);
  this->m_bLoadMipLevels.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "loadMipLevels",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bLoadMipLevels);
  this->m_bBorder.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "border",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bBorder);
  this->m_bNormalMap.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "normalMap",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bNormalMap);
  this->m_bSSBump.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "ssBump",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bSSBump);
  this->m_bNoMip.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noMip",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoMip);
  this->m_bAllMips.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "allMips",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bAllMips);
  this->m_bNoLod.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noLod",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoLod);
  this->m_bNoDebugOverride.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noDebugOverride",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoDebugOverride);
  this->m_bNoCompression.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "noCompression",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bNoCompression);
  this->m_bHintDxt5Compression.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "hintDxt5Compression",
                                                type: AT_BOOL,
                                                pMemory: &this->m_bHintDxt5Compression);
}

//------------------------------------------------------------------------------
// Address: 0x004BCBB0
// Name: public: void CDmeTP_ChangeColorChannels::ProcessImage(class CDmeImage __near *,class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::ProcessImage(
        CDmeTP_ChangeColorChannels *this,
        CDmeImage *pDstImage,
        vgui::Panel *pSrcImage)
{
  vgui::IBorder *ListAttr; // esi
  const ImageFormatInfo_t *v5; // eax
  int v6; // ecx
  int m_Storage; // eax

  ListAttr = CDmeBoneFlexDriverList::GetListAttr(this: pSrcImage);
  v5 = ImageLoader::ImageFormatInfo(fmt: (ImageFormat)ListAttr);
  v6 = v5->m_nNumRedBits != 0;
  if ( v5->m_nNumGreenBits != 0 )
    ++v6;
  if ( v5->m_nNumBlueBits != 0 )
    ++v6;
  if ( v5->m_nNumAlphaBits != 0 )
    ++v6;
  m_Storage = this->m_nMaxChannels.m_Storage;
  if ( v6 > m_Storage )
    ListAttr = (vgui::IBorder *)ComputeDestFormat(fmt: (ImageFormat)ListAttr, nChannelCount: m_Storage);
  CDmeImage::CopyFrom(this: pDstImage, (CDmeImage *)pSrcImage, fmt: (ImageFormat)ListAttr);
}

//------------------------------------------------------------------------------
// Address: 0x004BCC10
// Name: public: virtual void CDmeTP_ComputeMipmaps::ProcessTexture(class CDmeTexture __near *,class CDmeTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::ProcessTexture(
        CDmeTP_ComputeMipmaps *this,
        CDmeTexture *pSrcTexture,
        CDmeTexture *pDstTexture)
{
  CDmeTexture *v3; // esi
  int NumMipMapLevels; // edi
  bool v6; // zf
  void *v7; // esp
  void *v8; // esp
  int v9; // eax
  CDmeTextureFrame *v10; // ebx
  char v11; // al
  int j; // ebx
  int v13; // ebx
  int v14; // esi
  int v15; // ebx
  CDmeImageArray *MipLevel; // eax
  CDmeImage *v17; // edi
  CDmeTextureFrame_vtbl *v18; // esi
  CDmeTextureFrame *v19; // eax
  int v20; // eax
  CDmeImage *v21; // edi
  vgui::IBorder *ListAttr; // eax
  float flGamma; // [esp+8h] [ebp-60h]
  _BYTE v24[12]; // [esp+Ch] [ebp-5Ch] BYREF
  DownsampleInfo_t info; // [esp+18h] [ebp-50h] BYREF
  int nImageCount; // [esp+24h] [ebp-44h]
  CDmeTP_ComputeMipmaps *v27; // [esp+28h] [ebp-40h]
  int k; // [esp+2Ch] [ebp-3Ch]
  int nDepth; // [esp+30h] [ebp-38h]
  int nWidth; // [esp+34h] [ebp-34h]
  int nFrameCount; // [esp+38h] [ebp-30h]
  int i; // [esp+3Ch] [ebp-2Ch]
  CDmeImage **ppDstImages; // [esp+40h] [ebp-28h]
  CDmeTextureFrame *pDstFrame; // [esp+44h] [ebp-24h]
  int nHeight; // [esp+48h] [ebp-20h]
  CDmeImage **ppSrcImages; // [esp+4Ch] [ebp-1Ch]
  int nTotalMipCount; // [esp+50h] [ebp-18h]
  int f; // [esp+54h] [ebp-14h]
  CDmeTextureFrame *v39; // [esp+58h] [ebp-10h]
  int nMipWidth; // [esp+5Ch] [ebp-Ch]
  int nMipDepth; // [esp+60h] [ebp-8h]
  int nMipHeight; // [esp+64h] [ebp-4h]

  v3 = pSrcTexture;
  v27 = this;
  nWidth = CDmeTexture::Width(this: pSrcTexture);
  nHeight = CDmeTexture::Height(this: pSrcTexture);
  nDepth = CDmeTexture::Depth(this: pSrcTexture);
  NumMipMapLevels = ImageLoader::GetNumMipMapLevels(width: nWidth, height: nHeight, depth: nDepth);
  nTotalMipCount = NumMipMapLevels;
  CDmElement::CopyAttributesTo(this: pSrcTexture, pCopy: pDstTexture, depth: TD_NONE);
  CDmeTexture::RemoveAllFrames(this: pDstTexture);
  v6 = !pSrcTexture->m_bClampS.m_Storage;
  info.m_flAlphaThreshhold = this->m_flAlphaTestDownsampleThreshhold.m_Storage;
  info.m_flAlphaHiFreqThreshhold = this->m_flAlphaTestDownsampleHiFreqThreshhold.m_Storage;
  info.m_nFlags = !v6;
  if ( pSrcTexture->m_bClampT.m_Storage )
    info.m_nFlags |= 2u;
  if ( pSrcTexture->m_bClampU.m_Storage )
    info.m_nFlags |= 4u;
  if ( this->m_bAlphaTestDownsampling.m_Storage )
    info.m_nFlags |= 0x10u;
  nFrameCount = pSrcTexture->m_Frames.m_Storage.m_Size;
  v7 = alloca(4 * NumMipMapLevels);
  ppSrcImages = (CDmeImage **)v24;
  v8 = alloca(4 * NumMipMapLevels);
  ppDstImages = (CDmeImage **)v24;
  for ( f = 0; f < nFrameCount; ++f )
  {
    v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v3->m_Frames.m_Storage.m_Memory.m_pMemory[f]);
    v10 = (CDmeTextureFrame *)v9;
    if ( v9 == 0
      || (v11 = (*(int (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                  a1: v9,
                  a2: CDmeTextureFrame::m_classType.u),
          v39 = v10,
          v11 == 0) )
    {
      v39 = nullptr;
    }
    pDstFrame = (CDmeTextureFrame *)CDmeTexture::AddFrame(this: pDstTexture);
    if ( CDmeTextureFrame::GetMipLevel(this: v39, nIndex: 0) != nullptr )
    {
      if ( NumMipMapLevels > 0 )
      {
        for ( j = NumMipMapLevels; j != 0; --j )
          CDmeTextureFrame::AddMipLevel(this: pDstFrame);
      }
      v13 = 0;
      nImageCount = (int)CDmeTextureFrame::ImageCount(this: v39);
      i = 0;
      if ( nImageCount > 0 )
      {
        do
        {
          CDmeTexture::GetImages(this: v3, nFrame: f, nImageIndex: v13, ppImages: ppSrcImages, nSize: NumMipMapLevels);
          if ( *ppSrcImages != nullptr )
          {
            nMipWidth = nWidth;
            nMipHeight = nHeight;
            nMipDepth = nDepth;
            if ( NumMipMapLevels > 0 )
            {
              v14 = (char *)ppSrcImages - (char *)ppDstImages;
              v15 = -3;
              v39 = (CDmeTextureFrame *)ppDstImages;
              for ( k = (char *)ppSrcImages - (char *)ppDstImages; ; v14 = k )
              {
                MipLevel = CDmeTextureFrame::GetMipLevel(this: pDstFrame, nIndex: v15 + 3);
                v17 = *(CDmeImage **)((char *)&v39->__vftable + v14);
                v18 = (CDmeTextureFrame_vtbl *)CDmeImageArray::AddImage(this: MipLevel);
                v19 = v39;
                v39->__vftable = v18;
                if ( v17 != nullptr )
                {
                  CDmeImage::CopyFrom(this: (CDmeImage *)v18, pSrcImage: v17, fmt: IMAGE_FORMAT_UNKNOWN);
                }
                else if ( v27->m_bNoNiceFiltering.m_Storage )
                {
                  CDmeImage::QuarterSize(this: (CDmeImage *)v18, pSrcImage: *(float *)&v19[-1].m_MipLevels.m_pAttribute);
                }
                else
                {
                  if ( v15 >= 0 )
                  {
                    v20 = nTotalMipCount;
                    if ( v15 <= nTotalMipCount )
                      v20 = v15;
                  }
                  else
                  {
                    v20 = 0;
                  }
                  v21 = ppDstImages[v20];
                  flGamma = v21->m_flGamma.m_Storage;
                  ListAttr = CDmeBoneFlexDriverList::GetListAttr(this: (vgui::Panel *)v21);
                  CDmeImage::Init(
                    this: (CDmeImage *)v18,
                    nWidth: nMipWidth,
                    nHeight: nMipHeight,
                    nDepth: nMipDepth,
                    fmt: (ImageFormat)ListAttr,
                    flGamma);
                  CDmeImage::DownsampleNiceFiltered(this: (CDmeImage *)v18, &info, pSrcImage: *(float *)&v21);
                }
                nMipHeight >>= 1;
                nMipDepth >>= 1;
                nMipWidth >>= 1;
                if ( nMipWidth < 1 )
                  nMipWidth = 1;
                if ( nMipHeight < 1 )
                  nMipHeight = 1;
                if ( nMipDepth < 1 )
                  nMipDepth = 1;
                v39 = (CDmeTextureFrame *)((char *)v39 + 4);
                if ( ++v15 + 3 >= nTotalMipCount )
                  break;
              }
              v3 = pSrcTexture;
              NumMipMapLevels = nTotalMipCount;
              v13 = i;
            }
          }
          i = ++v13;
        }
        while ( v13 < nImageCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BCEC0
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
  int v6; // eax
  int v7; // esi
  CDmeTransform *MipLevel; // ebx
  int v9; // edi
  CDmeImage *Image; // esi
  CDmeImage *v11; // eax
  int nFrameCount; // [esp+Ch] [ebp-24h]
  CDmAttribute *nMipCount; // [esp+14h] [ebp-1Ch]
  CDmAttribute *nImageCount; // [esp+18h] [ebp-18h]
  CDmeImageArray *pDstImageArray; // [esp+1Ch] [ebp-14h]
  CDmeTextureFrame *pDstFrame; // [esp+20h] [ebp-10h]
  int f; // [esp+24h] [ebp-Ch]
  int m; // [esp+28h] [ebp-8h]
  CDmeTransform *v20; // [esp+2Ch] [ebp-4h]

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
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v3->m_Frames.m_Storage.m_Memory.m_pMemory[v5]);
      if ( v6 == 0
        || (v20 = (CDmeTransform *)v6,
            (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
              a1: v6,
              a2: CDmeTextureFrame::m_classType.u) == 0) )
      {
        v20 = nullptr;
      }
      pDstFrame = (CDmeTextureFrame *)CDmeTexture::AddFrame(this: v4);
      v7 = 0;
      nMipCount = CDmeTrack::GetClipCount(this: v20);
      m = 0;
      if ( (int)nMipCount > 0 )
      {
        do
        {
          MipLevel = (CDmeTransform *)CDmeTextureFrame::GetMipLevel(this: (CDmeTextureFrame *)v20, nIndex: v7);
          pDstImageArray = (CDmeImageArray *)CDmeTextureFrame::AddMipLevel(this: pDstFrame);
          if ( MipLevel != nullptr )
          {
            v9 = 0;
            nImageCount = CDmeTrack::GetClipCount(this: MipLevel);
            if ( (int)nImageCount > 0 )
            {
              do
              {
                Image = CDmeImageArray::GetImage(this: (CDmeImageArray *)MipLevel, nIndex: v9);
                v11 = CDmeImageArray::AddImage(this: pDstImageArray);
                if ( Image != nullptr )
                  func->m_pMemberFunc(this: func->m_pObject, a2: v11, a3: Image);
                ++v9;
              }
              while ( v9 < (int)nImageCount );
              v7 = m;
            }
          }
          m = ++v7;
        }
        while ( v7 < (int)nMipCount );
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
// Address: 0x004BCFE0
// Name: public: virtual void CDmeTP_ChangeColorChannels::ProcessTexture(class CDmeTexture __near *,class CDmeTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::ProcessTexture(
        CDmeTP_ChangeColorChannels *this,
        CDmeTexture *pSrcTexture,
        CDmeTexture *pDstTexture)
{
  CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels> func; // [esp+0h] [ebp-8h] BYREF

  func.m_pObject = this;
  func.m_pMemberFunc = (void (__thiscall *)(CDmeTP_ChangeColorChannels *, CDmeImage *, CDmeImage *))CDmeTP_ChangeColorChannels::ProcessImage;
  CDmeTexture::ProcessTexture<CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels>>(
    this: pDstTexture,
    pSrcTexture,
    &func);
}

//------------------------------------------------------------------------------
// Address: 0x004BD100
// Name: public: virtual bool CDmeTextureProcessor::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTextureProcessor::IsA(CDmeTextureProcessor *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD130
// Name: public: virtual int CDmeTextureProcessor::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureProcessor::GetInheritanceDepth(CDmeTextureProcessor *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD1A0
// Name: public: virtual bool CDmeTP_ComputeMipmaps::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTP_ComputeMipmaps::IsA(CDmeTP_ComputeMipmaps *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTP_ComputeMipmaps::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD1D0
// Name: public: virtual int CDmeTP_ComputeMipmaps::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ComputeMipmaps::GetInheritanceDepth(CDmeTP_ComputeMipmaps *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTP_ComputeMipmaps::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD290
// Name: protected: virtual void CDmeTP_ComputeMipmaps::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::PerformConstruction(CDmeTP_ComputeMipmaps *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTP_ComputeMipmaps::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004BD330
// Name: public: virtual bool CDmeTP_ChangeColorChannels::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTP_ChangeColorChannels::IsA(CDmeTP_ChangeColorChannels *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTP_ChangeColorChannels::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD360
// Name: public: virtual int CDmeTP_ChangeColorChannels::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ChangeColorChannels::GetInheritanceDepth(
        CDmeTP_ChangeColorChannels *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTP_ChangeColorChannels::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD410
// Name: protected: virtual void CDmeTP_ChangeColorChannels::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::PerformConstruction(CDmeTP_ChangeColorChannels *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_nMaxChannels.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "maxChannels",
                                        type: AT_INT,
                                        pMemory: &this->m_nMaxChannels);
}

//------------------------------------------------------------------------------
// Address: 0x004BD440
// Name: protected: CDmePrecompiledTexture::CDmePrecompiledTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePrecompiledTexture *__thiscall CDmePrecompiledTexture::CDmePrecompiledTexture(
        CDmePrecompiledTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmePrecompiledTexture_vtbl *)&CDmePrecompiledTexture::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Processors);
  this->m_pSourceTexture.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_pSourceTexture.m_pAttribute = nullptr;
  this->m_pSourceTexture.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ImageFileName.m_pAttribute = nullptr;
  this->m_ImageFileName.m_Storage.u.m_Id = -1;
  this->m_nStartFrame.m_pAttribute = nullptr;
  this->m_nStartFrame.m_Storage = 0;
  this->m_nEndFrame.m_pAttribute = nullptr;
  this->m_nEndFrame.m_Storage = 0;
  this->m_nTextureArraySize.m_pAttribute = nullptr;
  this->m_nTextureArraySize.m_Storage = 0;
  this->m_nVolumeTextureDepth.m_pAttribute = nullptr;
  this->m_nVolumeTextureDepth.m_Storage = 0;
  this->m_nTextureType.m_pAttribute = nullptr;
  this->m_nTextureType.m_Storage = 0;
  this->m_flBumpScale = 0;
  this->m_flPFMScale = 0;
  this->m_nFilterType.m_pAttribute = nullptr;
  this->m_nFilterType.m_Storage = 0;
  this->m_bClampS.m_pAttribute = nullptr;
  this->m_bClampS.m_Storage = false;
  this->m_bClampT.m_pAttribute = nullptr;
  this->m_bClampT.m_Storage = false;
  this->m_bClampU.m_pAttribute = nullptr;
  this->m_bClampU.m_Storage = false;
  this->m_bLoadMipLevels.m_pAttribute = nullptr;
  this->m_bLoadMipLevels.m_Storage = false;
  this->m_bBorder.m_pAttribute = nullptr;
  this->m_bBorder.m_Storage = false;
  this->m_bNormalMap.m_pAttribute = nullptr;
  this->m_bNormalMap.m_Storage = false;
  this->m_bSSBump.m_pAttribute = nullptr;
  this->m_bSSBump.m_Storage = false;
  this->m_bNoMip.m_pAttribute = nullptr;
  this->m_bNoMip.m_Storage = false;
  this->m_bAllMips.m_pAttribute = nullptr;
  this->m_bAllMips.m_Storage = false;
  this->m_bNoLod.m_pAttribute = nullptr;
  this->m_bNoLod.m_Storage = false;
  this->m_bNoDebugOverride.m_pAttribute = nullptr;
  this->m_bNoDebugOverride.m_Storage = false;
  this->m_bNoCompression.m_pAttribute = nullptr;
  this->m_bNoCompression.m_Storage = false;
  this->m_bHintDxt5Compression.m_pAttribute = nullptr;
  this->m_bHintDxt5Compression.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BD590
// Name: public: virtual bool CDmePrecompiledTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePrecompiledTexture::IsA(CDmePrecompiledTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePrecompiledTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD5C0
// Name: public: virtual int CDmePrecompiledTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePrecompiledTexture::GetInheritanceDepth(CDmePrecompiledTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePrecompiledTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BD600
// Name: protected: virtual void CDmePrecompiledTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePrecompiledTexture::PerformConstruction(CDmePrecompiledTexture *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmePrecompiledTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AC1F0
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
// Address: 0x006AC310
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
// Address: 0x006AC370
// Name: _dynamic_initializer_for__CDmeTextureProcessor::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTextureProcessor::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTextureProcessor::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTextureProcessor pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3990
// Name: _dynamic_atexit_destructor_for__CDmeTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3A00
// Name: _dynamic_atexit_destructor_for__CDmePrecompiledTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePrecompiledTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePrecompiledTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3A10
// Name: _dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTextureProcessor::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AC220
// Name: _dynamic_initializer_for__g_CDmeTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC230
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
// Address: 0x006AC340
// Name: _dynamic_initializer_for__g_CDmePrecompiledTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePrecompiledTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC350
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
// Address: 0x006AC3A0
// Name: _dynamic_initializer_for__CDmeTP_ComputeMipmaps::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTP_ComputeMipmaps::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTP_ComputeMipmaps::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTP_ComputeMipmaps pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC3D0
// Name: _dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC3E0
// Name: _dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTP_ComputeMipmaps_Helper,
           classname: "DmeTP_ComputeMipmaps",
           pFactory: &g_CDmeTP_ComputeMipmaps_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006AC400
// Name: _dynamic_initializer_for__CDmeTP_ChangeColorChannels::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTP_ChangeColorChannels::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTP_ChangeColorChannels::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTP_ChangeColorChannels pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC430
// Name: _dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC440
// Name: _dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTP_ChangeColorChannels_Helper,
           classname: "DmeTP_ChangeColorChannels",
           pFactory: &g_CDmeTP_ChangeColorChannels_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006AC460
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC490
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC4C0
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC4E0
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC530
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC540
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x006AC550
// Name: _dynamic_initializer_for__g_CMDLPanel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_CMDLPanel_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_CMDLPanel_Helper,
           className: "CMDLPanel",
           func: Create_CMDLPanel);
}

//------------------------------------------------------------------------------
// Address: 0x006AC570
// Name: _dynamic_initializer_for__r_showenvcubemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_showenvcubemap__()
{
  ConVar::ConVar(this: &r_showenvcubemap, pName: "r_showenvcubemap", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_showenvcubemap__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC5A0
// Name: _dynamic_initializer_for__r_eyegloss__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyegloss__()
{
  ConVar::ConVar(this: &r_eyegloss, pName: "r_eyegloss", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyegloss__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC5D0
// Name: _dynamic_initializer_for__r_eyemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyemove__()
{
  ConVar::ConVar(this: &r_eyemove, pName: "r_eyemove", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyemove__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC600
// Name: _dynamic_initializer_for__r_eyeshift_x__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyeshift_x__()
{
  ConVar::ConVar(this: &r_eyeshift_x, pName: "r_eyeshift_x", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyeshift_x__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC630
// Name: _dynamic_initializer_for__r_eyeshift_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyeshift_y__()
{
  ConVar::ConVar(this: &r_eyeshift_y, pName: "r_eyeshift_y", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyeshift_y__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC660
// Name: _dynamic_initializer_for__r_eyeshift_z__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyeshift_z__()
{
  ConVar::ConVar(this: &r_eyeshift_z, pName: "r_eyeshift_z", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyeshift_z__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC690
// Name: _dynamic_initializer_for__r_eyesize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyesize__()
{
  ConVar::ConVar(this: &r_eyesize, pName: "r_eyesize", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__r_eyesize__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC6C0
// Name: _dynamic_initializer_for__mat_softwareskin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_softwareskin__()
{
  ConVar::ConVar(this: &mat_softwareskin, pName: "mat_softwareskin", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_softwareskin__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC6F0
// Name: _dynamic_initializer_for__r_nohw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_nohw__()
{
  ConVar::ConVar(this: &r_nohw, pName: "r_nohw", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_nohw__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC720
// Name: _dynamic_initializer_for__r_nosw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_nosw__()
{
  ConVar::ConVar(this: &r_nosw, pName: "r_nosw", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_nosw__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC750
// Name: _dynamic_initializer_for__r_teeth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_teeth__()
{
  ConVar::ConVar(this: &r_teeth, pName: "r_teeth", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_teeth__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC780
// Name: _dynamic_initializer_for__r_drawentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawentities__()
{
  ConVar::ConVar(this: &r_drawentities, pName: "r_drawentities", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawentities__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC7B0
// Name: _dynamic_initializer_for__r_flex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flex__()
{
  ConVar::ConVar(this: &r_flex, pName: "r_flex", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flex__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC7E0
// Name: _dynamic_initializer_for__r_eyes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyes__()
{
  ConVar::ConVar(this: &r_eyes, pName: "r_eyes", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_eyes__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC810
// Name: _dynamic_initializer_for__r_skin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_skin__()
{
  ConVar::ConVar(this: &r_skin, pName: "r_skin", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_skin__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC840
// Name: _dynamic_initializer_for__r_maxmodeldecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_maxmodeldecal__()
{
  ConVar::ConVar(this: &r_maxmodeldecal, pName: "r_maxmodeldecal", pDefaultValue: "50", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_maxmodeldecal__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC870
// Name: _dynamic_initializer_for__r_modelwireframedecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_modelwireframedecal__()
{
  ConVar::ConVar(this: &r_modelwireframedecal, pName: "r_modelwireframedecal", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_modelwireframedecal__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC8A0
// Name: _dynamic_initializer_for__mat_normals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_normals__()
{
  ConVar::ConVar(this: &mat_normals, pName: "mat_normals", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_normals__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC8D0
// Name: _dynamic_initializer_for__r_eyeglintlodpixels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_eyeglintlodpixels__()
{
  ConVar::ConVar(this: &r_eyeglintlodpixels, pName: "r_eyeglintlodpixels", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_eyeglintlodpixels__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC900
// Name: _dynamic_initializer_for__r_rootlod__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_rootlod__()
{
  ConVar::ConVar(this: &r_rootlod, pName: "r_rootlod", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_rootlod__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC930
// Name: _dynamic_initializer_for__s_AssetCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_AssetCache__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_AssetCache__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC940
// Name: _dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__()
{
  CTextureReference::CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture_SheetSeq);
  return atexit(func: dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__);
}

//------------------------------------------------------------------------------
// Address: 0x006B39A0
// Name: _dynamic_atexit_destructor_for__g_CDmeTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTexture_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTexture_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B39B0
// Name: _dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTextureFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3A20
// Name: _dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTP_ComputeMipmaps::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3A30
// Name: _dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTP_ChangeColorChannels::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3A40
// Name: _dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTP_ComputeMipmaps_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3A50
// Name: _dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTP_ChangeColorChannels_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3A60
// Name: _dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePrecompiledTexture_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3A70
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x006B3A80
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x006B3A90
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x006B3AA0
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x006B3AB0
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

//------------------------------------------------------------------------------
// Address: 0x006B3B30
// Name: _dynamic_atexit_destructor_for__r_showenvcubemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_showenvcubemap__()
{
  ConVar::~ConVar(this: &r_showenvcubemap);
}

//------------------------------------------------------------------------------
// Address: 0x006B3B40
// Name: _dynamic_atexit_destructor_for__r_eyegloss__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyegloss__()
{
  ConVar::~ConVar(this: &r_eyegloss);
}

//------------------------------------------------------------------------------
// Address: 0x006B3B50
// Name: _dynamic_atexit_destructor_for__r_eyemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyemove__()
{
  ConVar::~ConVar(this: &r_eyemove);
}

//------------------------------------------------------------------------------
// Address: 0x006B3B60
// Name: _dynamic_atexit_destructor_for__r_eyeshift_x__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_x__()
{
  ConVar::~ConVar(this: &r_eyeshift_x);
}

//------------------------------------------------------------------------------
// Address: 0x006B3B70
// Name: _dynamic_atexit_destructor_for__r_eyeshift_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_y__()
{
  ConVar::~ConVar(this: &r_eyeshift_y);
}

//------------------------------------------------------------------------------
// Address: 0x006B3B80
// Name: _dynamic_atexit_destructor_for__r_eyeshift_z__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_z__()
{
  ConVar::~ConVar(this: &r_eyeshift_z);
}

//------------------------------------------------------------------------------
// Address: 0x006B3B90
// Name: _dynamic_atexit_destructor_for__r_eyesize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyesize__()
{
  ConVar::~ConVar(this: &r_eyesize);
}

//------------------------------------------------------------------------------
// Address: 0x006B3BA0
// Name: _dynamic_atexit_destructor_for__mat_softwareskin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_softwareskin__()
{
  ConVar::~ConVar(this: &mat_softwareskin);
}

//------------------------------------------------------------------------------
// Address: 0x006B3BB0
// Name: _dynamic_atexit_destructor_for__r_nohw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_nohw__()
{
  ConVar::~ConVar(this: &r_nohw);
}

//------------------------------------------------------------------------------
// Address: 0x006B3BC0
// Name: _dynamic_atexit_destructor_for__r_nosw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_nosw__()
{
  ConVar::~ConVar(this: &r_nosw);
}

//------------------------------------------------------------------------------
// Address: 0x006B3BD0
// Name: _dynamic_atexit_destructor_for__r_teeth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_teeth__()
{
  ConVar::~ConVar(this: &r_teeth);
}

//------------------------------------------------------------------------------
// Address: 0x006B3BE0
// Name: _dynamic_atexit_destructor_for__r_drawentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawentities__()
{
  ConVar::~ConVar(this: &r_drawentities);
}

//------------------------------------------------------------------------------
// Address: 0x006B3BF0
// Name: _dynamic_atexit_destructor_for__r_flex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flex__()
{
  ConVar::~ConVar(this: &r_flex);
}

//------------------------------------------------------------------------------
// Address: 0x006B3C00
// Name: _dynamic_atexit_destructor_for__r_eyes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyes__()
{
  ConVar::~ConVar(this: &r_eyes);
}

//------------------------------------------------------------------------------
// Address: 0x006B3C10
// Name: _dynamic_atexit_destructor_for__r_skin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_skin__()
{
  ConVar::~ConVar(this: &r_skin);
}

//------------------------------------------------------------------------------
// Address: 0x006B3C20
// Name: _dynamic_atexit_destructor_for__r_maxmodeldecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_maxmodeldecal__()
{
  ConVar::~ConVar(this: &r_maxmodeldecal);
}

//------------------------------------------------------------------------------
// Address: 0x006B3C30
// Name: _dynamic_atexit_destructor_for__r_modelwireframedecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_modelwireframedecal__()
{
  ConVar::~ConVar(this: &r_modelwireframedecal);
}

//------------------------------------------------------------------------------
// Address: 0x006B3C40
// Name: _dynamic_atexit_destructor_for__mat_normals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_normals__()
{
  ConVar::~ConVar(this: &mat_normals);
}

//------------------------------------------------------------------------------
// Address: 0x006B3C50
// Name: _dynamic_atexit_destructor_for__r_eyeglintlodpixels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeglintlodpixels__()
{
  ConVar::~ConVar(this: &r_eyeglintlodpixels);
}

//------------------------------------------------------------------------------
// Address: 0x006B3C60
// Name: _dynamic_atexit_destructor_for__r_rootlod__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_rootlod__()
{
  ConVar::~ConVar(this: &r_rootlod);
}

//------------------------------------------------------------------------------
// Address: 0x006B3C70
// Name: _dynamic_atexit_destructor_for__s_AssetCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_AssetCache__()
{
  CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::~CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>(this: &s_AssetCache.m_CachedAssets);
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::~CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>(this: &s_AssetCache.m_usedAssets);
  CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::~CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>(this: &s_AssetCache.m_ModList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3C90
// Name: _dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__()
{
  CTextureReference::~CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture_SheetSeq);
}

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0042F250
// Name: ComputeDestFormat
// Source: json
//------------------------------------------------------------------------------
ImageFormat __usercall ComputeDestFormat@<eax>(ImageFormat fmt@<ecx>, int nChannelCount@<eax>)
{
  switch ( fmt )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_ABGR8888:
    case IMAGE_FORMAT_ARGB8888:
    case IMAGE_FORMAT_BGRA8888:
      return nChannelCount != 3 ? 5 : 2;
    case IMAGE_FORMAT_RGB888:
    case IMAGE_FORMAT_BGR888:
    case IMAGE_FORMAT_IA88:
    case IMAGE_FORMAT_BGRX8888:
    case IMAGE_FORMAT_RGBX8888:
      return IMAGE_FORMAT_I8;
    case IMAGE_FORMAT_DXT5:
      return IMAGE_FORMAT_DXT1;
    case IMAGE_FORMAT_RGBA16161616F:
      if ( nChannelCount != 2 )
        return IMAGE_FORMAT_R16F;
      return IMAGE_FORMAT_RG1616F;
    case IMAGE_FORMAT_RGB323232F:
      goto $LN8_3;
    case IMAGE_FORMAT_RGBA32323232F:
      if ( nChannelCount == 3 )
        return IMAGE_FORMAT_RGB323232F;
$LN8_3:
      if ( nChannelCount == 2 )
        return IMAGE_FORMAT_RG3232F;
      else
        return IMAGE_FORMAT_R32F;
    case IMAGE_FORMAT_RG1616F:
      return IMAGE_FORMAT_R16F;
    case IMAGE_FORMAT_RG3232F:
      return IMAGE_FORMAT_R32F;
    default:
      return fmt;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F300
// Name: protected: void CDmeTP_ComputeMipmaps::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::OnConstruction(CDmeTP_ComputeMipmaps *this)
{
  this->m_bNoNiceFiltering.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noNiceFiltering",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoNiceFiltering);
  this->m_bAlphaTestDownsampling.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "alphaTestDownsampling",
                                                  type: AT_BOOL,
                                                  pMemory: &this->m_bAlphaTestDownsampling);
  this->m_flAlphaTestDownsampleThreshhold.m_pAttribute = CDmElement::AddExternalAttribute(
                                                           this,
                                                           pAttributeName: "alphaTestDownsampleThreshhold",
                                                           type: AT_FLOAT,
                                                           pMemory: &this->m_flAlphaTestDownsampleThreshhold);
  this->m_flAlphaTestDownsampleHiFreqThreshhold.m_pAttribute = CDmElement::AddExternalAttribute(
                                                                 this,
                                                                 pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                                                                 type: AT_FLOAT,
                                                                 pMemory: &this->m_flAlphaTestDownsampleHiFreqThreshhold);
}

//------------------------------------------------------------------------------
// Address: 0x0042F360
// Name: protected: void CDmePrecompiledTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePrecompiledTexture::OnConstruction(CDmePrecompiledTexture *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  this->m_ImageFileName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "imageFileName",
                                         type: AT_STRING,
                                         pMemory: &this->m_ImageFileName);
  this->m_Processors.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "processors",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Processors);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_Processors.m_pAttribute,
    typeSymbol: CDmeTextureProcessor::m_classType);
  this->m_pSourceTexture.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "sourceTexture",
                                          type: AT_FIRST_VALUE_TYPE,
                                          pMemory: &this->m_pSourceTexture);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pSourceTexture.m_pAttribute, typeSymbol: CDmeTexture::m_classType);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "startFrame", type: AT_INT, pMemory: &this->m_nStartFrame);
  this->m_nStartFrame.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = -1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "endFrame", type: AT_INT, pMemory: &this->m_nEndFrame);
  this->m_nEndFrame.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  value = 1;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "volumeTextureDepth",
         type: AT_INT,
         pMemory: &this->m_nVolumeTextureDepth);
  this->m_nVolumeTextureDepth.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  value = 1;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "textureArraySize",
         type: AT_INT,
         pMemory: &this->m_nTextureArraySize);
  this->m_nTextureArraySize.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, &value);
  this->m_nTextureType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "textureType",
                                        type: AT_INT,
                                        pMemory: &this->m_nTextureType);
  value = 1065353216;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "bumpScale",
         type: AT_FLOAT,
         pMemory: &this->m_flBumpScale);
  this->m_flBumpScale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, (const float *)&value);
  value = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "pfmScale", type: AT_FLOAT, pMemory: &this->m_flPFMScale);
  this->m_flPFMScale.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, (const float *)&value);
  this->m_nFilterType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "filterType",
                                       type: AT_INT,
                                       pMemory: &this->m_nFilterType);
  this->m_bClampS.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clamps",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampS);
  this->m_bClampT.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampt",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampT);
  this->m_bClampU.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampu",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampU);
  this->m_bLoadMipLevels.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "loadMipLevels",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bLoadMipLevels);
  this->m_bBorder.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "border",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bBorder);
  this->m_bNormalMap.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "normalMap",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bNormalMap);
  this->m_bSSBump.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "ssBump",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bSSBump);
  this->m_bNoMip.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noMip",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoMip);
  this->m_bAllMips.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "allMips",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bAllMips);
  this->m_bNoLod.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noLod",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoLod);
  this->m_bNoDebugOverride.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noDebugOverride",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoDebugOverride);
  this->m_bNoCompression.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "noCompression",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bNoCompression);
  this->m_bHintDxt5Compression.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "hintDxt5Compression",
                                                type: AT_BOOL,
                                                pMemory: &this->m_bHintDxt5Compression);
}

//------------------------------------------------------------------------------
// Address: 0x0042F650
// Name: public: void CDmeTP_ChangeColorChannels::ProcessImage(class CDmeImage __near *,class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::ProcessImage(
        CDmeTP_ChangeColorChannels *this,
        CDmeImage *pDstImage,
        vgui::Panel *pSrcImage)
{
  vgui::IBorder *RequestedKeyFocus; // esi
  const ImageFormatInfo_t *v5; // eax
  int v6; // ecx
  int m_Storage; // eax

  RequestedKeyFocus = CGameUISystemMgr::GetRequestedKeyFocus(this: pSrcImage);
  v5 = ImageLoader::ImageFormatInfo(fmt: (ImageFormat)RequestedKeyFocus);
  v6 = v5->m_nNumRedBits != 0;
  if ( v5->m_nNumGreenBits != 0 )
    ++v6;
  if ( v5->m_nNumBlueBits != 0 )
    ++v6;
  if ( v5->m_nNumAlphaBits != 0 )
    ++v6;
  m_Storage = this->m_nMaxChannels.m_Storage;
  if ( v6 > m_Storage )
    RequestedKeyFocus = (vgui::IBorder *)ComputeDestFormat(
                                           fmt: (ImageFormat)RequestedKeyFocus,
                                           nChannelCount: m_Storage);
  CDmeImage::CopyFrom(this: pDstImage, (CDmeImage *)pSrcImage, fmt: (ImageFormat)RequestedKeyFocus);
}

//------------------------------------------------------------------------------
// Address: 0x0042F6C0
// Name: public: virtual void CDmeTP_ComputeMipmaps::ProcessTexture(class CDmeTexture __near *,class CDmeTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::ProcessTexture(
        CDmeTP_ComputeMipmaps *this,
        CDmeTexture *pSrcTexture,
        CDmeTexture *pDstTexture)
{
  CDmeTexture *v3; // esi
  int NumMipMapLevels; // edi
  bool v6; // zf
  void *v7; // esp
  void *v8; // esp
  CDmElement *v9; // eax
  CDmeTextureFrame *v10; // ebx
  bool v11; // al
  int j; // ebx
  int v13; // ebx
  int v14; // esi
  int v15; // ebx
  CDmeImageArray *MipLevel; // eax
  CDmeImage *v17; // edi
  CDmeTextureFrame_vtbl *v18; // esi
  CDmeTextureFrame *v19; // eax
  int v20; // eax
  CDmeImage *v21; // edi
  vgui::IBorder *RequestedKeyFocus; // eax
  float flGamma; // [esp+8h] [ebp-60h]
  _BYTE v24[12]; // [esp+Ch] [ebp-5Ch] BYREF
  DownsampleInfo_t info; // [esp+18h] [ebp-50h] BYREF
  int nImageCount; // [esp+24h] [ebp-44h]
  CDmeTP_ComputeMipmaps *v27; // [esp+28h] [ebp-40h]
  int k; // [esp+2Ch] [ebp-3Ch]
  int nDepth; // [esp+30h] [ebp-38h]
  int nWidth; // [esp+34h] [ebp-34h]
  int nFrameCount; // [esp+38h] [ebp-30h]
  int i; // [esp+3Ch] [ebp-2Ch]
  CDmeImage **ppDstImages; // [esp+40h] [ebp-28h]
  CDmeTextureFrame *pDstFrame; // [esp+44h] [ebp-24h]
  int nHeight; // [esp+48h] [ebp-20h]
  CDmeImage **ppSrcImages; // [esp+4Ch] [ebp-1Ch]
  int nTotalMipCount; // [esp+50h] [ebp-18h]
  int f; // [esp+54h] [ebp-14h]
  CDmeTextureFrame *v39; // [esp+58h] [ebp-10h]
  int nMipWidth; // [esp+5Ch] [ebp-Ch]
  int nMipDepth; // [esp+60h] [ebp-8h]
  int nMipHeight; // [esp+64h] [ebp-4h]

  v3 = pSrcTexture;
  v27 = this;
  nWidth = (int)CDmeTexture::Width(this: pSrcTexture);
  nHeight = CDmeTexture::Height(this: pSrcTexture);
  nDepth = CDmeTexture::Depth(this: pSrcTexture);
  NumMipMapLevels = ImageLoader::GetNumMipMapLevels(width: nWidth, height: nHeight, depth: nDepth);
  nTotalMipCount = NumMipMapLevels;
  CDmElement::CopyAttributesTo(this: pSrcTexture, pCopy: pDstTexture, depth: TD_NONE);
  CDmeTexture::RemoveAllFrames(this: pDstTexture);
  v6 = !pSrcTexture->m_bClampS.m_Storage;
  info.m_flAlphaThreshhold = this->m_flAlphaTestDownsampleThreshhold.m_Storage;
  info.m_flAlphaHiFreqThreshhold = this->m_flAlphaTestDownsampleHiFreqThreshhold.m_Storage;
  info.m_nFlags = !v6;
  if ( pSrcTexture->m_bClampT.m_Storage )
    info.m_nFlags |= 2u;
  if ( pSrcTexture->m_bClampU.m_Storage )
    info.m_nFlags |= 4u;
  if ( this->m_bAlphaTestDownsampling.m_Storage )
    info.m_nFlags |= 0x10u;
  nFrameCount = pSrcTexture->m_Frames.m_Storage.m_Size;
  v7 = alloca(4 * NumMipMapLevels);
  ppSrcImages = (CDmeImage **)v24;
  v8 = alloca(4 * NumMipMapLevels);
  ppDstImages = (CDmeImage **)v24;
  for ( f = 0; f < nFrameCount; ++f )
  {
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Frames.m_Storage.m_Memory.m_pMemory[f]);
    v10 = (CDmeTextureFrame *)v9;
    if ( v9 == nullptr || (v11 = v9->IsA(this: v9, a2: CDmeTextureFrame::m_classType), v39 = v10, !v11) )
      v39 = nullptr;
    pDstFrame = (CDmeTextureFrame *)CDmeTexture::AddFrame(this: pDstTexture);
    if ( CDmeTextureFrame::GetMipLevel(this: v39, nIndex: 0) != nullptr )
    {
      if ( NumMipMapLevels > 0 )
      {
        for ( j = NumMipMapLevels; j != 0; --j )
          CDmeTextureFrame::AddMipLevel(this: pDstFrame);
      }
      v13 = 0;
      nImageCount = CDmeTextureFrame::ImageCount(this: v39);
      i = 0;
      if ( nImageCount > 0 )
      {
        do
        {
          CDmeTexture::GetImages(this: v3, nFrame: f, nImageIndex: v13, ppImages: ppSrcImages, nSize: NumMipMapLevels);
          if ( *ppSrcImages != nullptr )
          {
            nMipWidth = nWidth;
            nMipHeight = nHeight;
            nMipDepth = nDepth;
            if ( NumMipMapLevels > 0 )
            {
              v14 = (char *)ppSrcImages - (char *)ppDstImages;
              v15 = -3;
              v39 = (CDmeTextureFrame *)ppDstImages;
              for ( k = (char *)ppSrcImages - (char *)ppDstImages; ; v14 = k )
              {
                MipLevel = CDmeTextureFrame::GetMipLevel(this: pDstFrame, nIndex: v15 + 3);
                v17 = *(CDmeImage **)((char *)&v39->__vftable + v14);
                v18 = (CDmeTextureFrame_vtbl *)CDmeImageArray::AddImage(this: MipLevel);
                v19 = v39;
                v39->__vftable = v18;
                if ( v17 != nullptr )
                {
                  CDmeImage::CopyFrom(this: (CDmeImage *)v18, pSrcImage: v17, fmt: IMAGE_FORMAT_UNKNOWN);
                }
                else if ( v27->m_bNoNiceFiltering.m_Storage )
                {
                  CDmeImage::QuarterSize(this: (CDmeImage *)v18, pSrcImage: *(float *)&v19[-1].m_MipLevels.m_pAttribute);
                }
                else
                {
                  v20 = nTotalMipCount;
                  if ( v15 <= nTotalMipCount )
                    v20 = v15 < 0 ? 0 : v15;
                  v21 = ppDstImages[v20];
                  flGamma = v21->m_flGamma.m_Storage;
                  RequestedKeyFocus = CGameUISystemMgr::GetRequestedKeyFocus(this: (vgui::Panel *)v21);
                  CDmeImage::Init(
                    this: (CDmeImage *)v18,
                    nWidth: nMipWidth,
                    nHeight: nMipHeight,
                    nDepth: nMipDepth,
                    fmt: (ImageFormat)RequestedKeyFocus,
                    flGamma);
                  CDmeImage::DownsampleNiceFiltered(this: (CDmeImage *)v18, &info, pSrcImage: *(float *)&v21);
                }
                nMipHeight >>= 1;
                nMipDepth >>= 1;
                nMipWidth >>= 1;
                if ( nMipWidth < 1 )
                  nMipWidth = 1;
                if ( nMipHeight < 1 )
                  nMipHeight = 1;
                if ( nMipDepth < 1 )
                  nMipDepth = 1;
                v39 = (CDmeTextureFrame *)((char *)v39 + 4);
                if ( ++v15 + 3 >= nTotalMipCount )
                  break;
              }
              v3 = pSrcTexture;
              NumMipMapLevels = nTotalMipCount;
              v13 = i;
            }
          }
          i = ++v13;
        }
        while ( v13 < nImageCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F980
// Name: public: void CDmeTexture::ProcessTexture<class CImageProcessorMemberFunctor<class CDmeTP_ChangeColorChannels>>(class CDmeTexture __near *,class CImageProcessorMemberFunctor<class CDmeTP_ChangeColorChannels> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::ProcessTexture<CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels>>(
        CDmeTexture *this,
        CDmeTexture *pSrcTexture,
        CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels> *func)
{
  CDmeTexture *v3; // ebp
  CDmeTexture *v4; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  int v7; // esi
  CVTFTexture *MipLevel; // ebx
  CDmeImageArray *v9; // ebp
  int v10; // edi
  CDmeImage *Image; // esi
  CDmeImage *v12; // eax
  CVTFTexture *m; // [esp+10h] [ebp-20h]
  int f; // [esp+14h] [ebp-1Ch]
  CDmeTextureFrame *pDstFrame; // [esp+18h] [ebp-18h]
  CDmeTextureFrame *nImageCount; // [esp+1Ch] [ebp-14h]
  int nMipCount; // [esp+20h] [ebp-10h]
  int v18; // [esp+24h] [ebp-Ch]
  int m_Size; // [esp+2Ch] [ebp-4h]

  v3 = pSrcTexture;
  v4 = this;
  CDmElement::CopyAttributesTo(this: pSrcTexture, pCopy: this, depth: TD_NONE);
  CDmeTexture::RemoveAllFrames(this: v4);
  v5 = 0;
  m_Size = pSrcTexture->m_Frames.m_Storage.m_Size;
  pDstFrame = nullptr;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Frames.m_Storage.m_Memory.m_pMemory[v5]);
      if ( v6 == nullptr || (m = (CVTFTexture *)v6, !v6->IsA(this: v6, a2: CDmeTextureFrame::m_classType)) )
        m = nullptr;
      nImageCount = (CDmeTextureFrame *)CDmeTexture::AddFrame(this: v4);
      v7 = 0;
      v18 = CVTFTexture::LowResWidth(this: m);
      f = 0;
      if ( v18 > 0 )
      {
        do
        {
          MipLevel = (CVTFTexture *)CDmeTextureFrame::GetMipLevel(this: (CDmeTextureFrame *)m, nIndex: v7);
          v9 = (CDmeImageArray *)CDmeTextureFrame::AddMipLevel(this: nImageCount);
          if ( MipLevel != nullptr )
          {
            v10 = 0;
            nMipCount = CVTFTexture::LowResWidth(this: MipLevel);
            if ( nMipCount > 0 )
            {
              do
              {
                Image = CDmeImageArray::GetImage(this: (CDmeImageArray *)MipLevel, nIndex: v10);
                v12 = CDmeImageArray::AddImage(this: v9);
                if ( Image != nullptr )
                  func->m_pMemberFunc(this: func->m_pObject, a2: v12, a3: Image);
                ++v10;
              }
              while ( v10 < nMipCount );
              v7 = f;
            }
          }
          f = ++v7;
        }
        while ( v7 < v18 );
        v5 = (int)pDstFrame;
        v3 = pSrcTexture;
        v4 = this;
      }
      pDstFrame = (CDmeTextureFrame *)++v5;
    }
    while ( v5 < m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FAC0
// Name: public: virtual void CDmeTP_ChangeColorChannels::ProcessTexture(class CDmeTexture __near *,class CDmeTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::ProcessTexture(
        CDmeTP_ChangeColorChannels *this,
        CDmeTexture *pSrcTexture,
        CDmeTexture *pDstTexture)
{
  CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels> func; // [esp+0h] [ebp-8h] BYREF

  func.m_pObject = this;
  func.m_pMemberFunc = (void (__thiscall *)(CDmeTP_ChangeColorChannels *, CDmeImage *, CDmeImage *))CDmeTP_ChangeColorChannels::ProcessImage;
  CDmeTexture::ProcessTexture<CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels>>(
    this: pDstTexture,
    pSrcTexture,
    &func);
}

//------------------------------------------------------------------------------
// Address: 0x0042FBA0
// Name: public: virtual bool CDmeTextureProcessor::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTextureProcessor::IsA(CDmeTextureProcessor *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042FBD0
// Name: public: virtual int CDmeTextureProcessor::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureProcessor::GetInheritanceDepth(CDmeTextureProcessor *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042FC40
// Name: public: virtual bool CDmeTP_ComputeMipmaps::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTP_ComputeMipmaps::IsA(CDmeTP_ComputeMipmaps *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTP_ComputeMipmaps::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042FC70
// Name: public: virtual int CDmeTP_ComputeMipmaps::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ComputeMipmaps::GetInheritanceDepth(CDmeTP_ComputeMipmaps *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTP_ComputeMipmaps::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042FCB0
// Name: protected: virtual int CDmeTP_ComputeMipmaps::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ComputeMipmaps::AllocatedSize(CDmeTP_ComputeMipmaps *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x0042FD30
// Name: protected: virtual void CDmeTP_ComputeMipmaps::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::PerformConstruction(CDmeTP_ComputeMipmaps *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  CDmeTP_ComputeMipmaps::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042FDB0
// Name: public: virtual bool CDmeTP_ChangeColorChannels::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTP_ChangeColorChannels::IsA(CDmeTP_ChangeColorChannels *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTP_ChangeColorChannels::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042FDE0
// Name: public: virtual int CDmeTP_ChangeColorChannels::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ChangeColorChannels::GetInheritanceDepth(
        CDmeTP_ChangeColorChannels *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTP_ChangeColorChannels::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042FE20
// Name: protected: virtual int CDmeTP_ChangeColorChannels::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ChangeColorChannels::AllocatedSize(CDmeTP_ChangeColorChannels *this)
{
  return 76;
}

//------------------------------------------------------------------------------
// Address: 0x0042FE90
// Name: protected: virtual void CDmeTP_ChangeColorChannels::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::PerformConstruction(CDmeTP_ChangeColorChannels *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  this->m_nMaxChannels.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "maxChannels",
                                        type: AT_INT,
                                        pMemory: &this->m_nMaxChannels);
}

//------------------------------------------------------------------------------
// Address: 0x0042FEC0
// Name: protected: CDmePrecompiledTexture::CDmePrecompiledTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePrecompiledTexture *__thiscall CDmePrecompiledTexture::CDmePrecompiledTexture(
        CDmePrecompiledTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmePrecompiledTexture_vtbl *)&CDmePrecompiledTexture::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Processors);
  this->m_pSourceTexture.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_pSourceTexture.m_pAttribute = nullptr;
  this->m_pSourceTexture.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ImageFileName.m_pAttribute = nullptr;
  this->m_ImageFileName.m_Storage.u.m_Id = -1;
  this->m_nStartFrame.m_pAttribute = nullptr;
  this->m_nStartFrame.m_Storage = 0;
  this->m_nEndFrame.m_pAttribute = nullptr;
  this->m_nEndFrame.m_Storage = 0;
  this->m_nTextureArraySize.m_pAttribute = nullptr;
  this->m_nTextureArraySize.m_Storage = 0;
  this->m_nVolumeTextureDepth.m_pAttribute = nullptr;
  this->m_nVolumeTextureDepth.m_Storage = 0;
  this->m_nTextureType.m_pAttribute = nullptr;
  this->m_nTextureType.m_Storage = 0;
  this->m_flBumpScale = 0;
  this->m_flPFMScale = 0;
  this->m_nFilterType.m_pAttribute = nullptr;
  this->m_nFilterType.m_Storage = 0;
  this->m_bClampS.m_pAttribute = nullptr;
  this->m_bClampS.m_Storage = false;
  this->m_bClampT.m_pAttribute = nullptr;
  this->m_bClampT.m_Storage = false;
  this->m_bClampU.m_pAttribute = nullptr;
  this->m_bClampU.m_Storage = false;
  this->m_bLoadMipLevels.m_pAttribute = nullptr;
  this->m_bLoadMipLevels.m_Storage = false;
  this->m_bBorder.m_pAttribute = nullptr;
  this->m_bBorder.m_Storage = false;
  this->m_bNormalMap.m_pAttribute = nullptr;
  this->m_bNormalMap.m_Storage = false;
  this->m_bSSBump.m_pAttribute = nullptr;
  this->m_bSSBump.m_Storage = false;
  this->m_bNoMip.m_pAttribute = nullptr;
  this->m_bNoMip.m_Storage = false;
  this->m_bAllMips.m_pAttribute = nullptr;
  this->m_bAllMips.m_Storage = false;
  this->m_bNoLod.m_pAttribute = nullptr;
  this->m_bNoLod.m_Storage = false;
  this->m_bNoDebugOverride.m_pAttribute = nullptr;
  this->m_bNoDebugOverride.m_Storage = false;
  this->m_bNoCompression.m_pAttribute = nullptr;
  this->m_bNoCompression.m_Storage = false;
  this->m_bHintDxt5Compression.m_pAttribute = nullptr;
  this->m_bHintDxt5Compression.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00430010
// Name: public: virtual bool CDmePrecompiledTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePrecompiledTexture::IsA(CDmePrecompiledTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePrecompiledTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00430040
// Name: public: virtual int CDmePrecompiledTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePrecompiledTexture::GetInheritanceDepth(CDmePrecompiledTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePrecompiledTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00430070
// Name: protected: virtual int CDmePrecompiledTexture::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePrecompiledTexture::AllocatedSize(CDmePrecompiledTexture *this)
{
  return 284;
}

//------------------------------------------------------------------------------
// Address: 0x00430080
// Name: protected: virtual void CDmePrecompiledTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePrecompiledTexture::PerformConstruction(CDmePrecompiledTexture *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  CDmePrecompiledTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00533940
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
// Address: 0x00533A60
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
// Address: 0x00533AC0
// Name: _dynamic_initializer_for__CDmeTextureProcessor::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTextureProcessor::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTextureProcessor::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTextureProcessor pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00535200
// Name: _dynamic_atexit_destructor_for__CDmeTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00535270
// Name: _dynamic_atexit_destructor_for__CDmePrecompiledTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePrecompiledTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePrecompiledTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00535280
// Name: _dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTextureProcessor::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00533970
// Name: _dynamic_initializer_for__g_CDmeTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00533980
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
// Address: 0x00533A90
// Name: _dynamic_initializer_for__g_CDmePrecompiledTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePrecompiledTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00533AA0
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
// Address: 0x00533AF0
// Name: _dynamic_initializer_for__CDmeTP_ComputeMipmaps::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTP_ComputeMipmaps::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTP_ComputeMipmaps::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTP_ComputeMipmaps pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00533B20
// Name: _dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00533B30
// Name: _dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTP_ComputeMipmaps_Helper,
           classname: "DmeTP_ComputeMipmaps",
           pFactory: &g_CDmeTP_ComputeMipmaps_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x00533B50
// Name: _dynamic_initializer_for__CDmeTP_ChangeColorChannels::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTP_ChangeColorChannels::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTP_ChangeColorChannels::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTP_ChangeColorChannels pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00533B80
// Name: _dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00533B90
// Name: _dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTP_ChangeColorChannels_Helper,
           classname: "DmeTP_ChangeColorChannels",
           pFactory: &g_CDmeTP_ChangeColorChannels_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x00533BB0
// Name: sub_533BB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_533BB0()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dword_5D8244 = SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x00533BD0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00533C30
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00533C60
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00533C70
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  s_EmptyConVar.m_Value.m_StringLength = strlen("0") + 1;
  s_EmptyConVar.m_Value.m_pszString = (char *)MemAlloc_Alloc(nSize: s_EmptyConVar.m_Value.m_StringLength);
  memcpy(
    dst: (unsigned __int8 *)s_EmptyConVar.m_Value.m_pszString,
    src: (unsigned __int8 *)s_EmptyConVar.m_pszDefaultValue,
    count: s_EmptyConVar.m_Value.m_StringLength);
  if ( !ConVar::InternalSetColorFromString(this: &s_EmptyConVar, value: s_EmptyConVar.m_Value.m_pszString) )
  {
    s_EmptyConVar.m_Value.m_fValue = atof(nptr: s_EmptyConVar.m_Value.m_pszString);
    if ( (LODWORD(s_EmptyConVar.m_Value.m_fValue) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(
        a1: "ConVar(%s) defined with infinite float value (%s)\n",
        defaultValue,
        s_EmptyConVar.m_Value.m_pszString);
      s_EmptyConVar.m_Value.m_fValue = 3.4028235e38;
    }
    s_EmptyConVar.m_Value.m_nValue = (int)s_EmptyConVar.m_Value.m_fValue;
  }
  s_EmptyConVar.m_bRegistered = false;
  s_EmptyConVar.m_pszName = defaultValue;
  s_EmptyConVar.m_pszHelpString = empty_string;
  s_EmptyConVar.m_nFlags = 0;
  s_EmptyConVar.m_pNext = ConCommandBase::s_pConCommandBases;
  ConCommandBase::s_pConCommandBases = &s_EmptyConVar;
  if ( ConCommandBase::s_pAccessor != nullptr )
    s_EmptyConVar.Init(this: &s_EmptyConVar);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&CEmptyConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&CEmptyConVar::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x00533DA0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CTextureReference::CTextureReference(this: (CTextureReference *)&g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x00533DC0
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00535210
// Name: _dynamic_atexit_destructor_for__g_CDmeTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTexture_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTexture_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00535220
// Name: _dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTextureFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00535290
// Name: _dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTP_ComputeMipmaps::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005352A0
// Name: _dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTP_ChangeColorChannels::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005352B0
// Name: _dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTP_ComputeMipmaps_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005352C0
// Name: _dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTP_ChangeColorChannels_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005352D0
// Name: _dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePrecompiledTexture_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005352E0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00535320
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00535370
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x00535380
// Name: _dynamic_atexit_destructor_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ButtonSoundNames);
}

//------------------------------------------------------------------------------
// Address: 0x00535390
// Name: _dynamic_atexit_destructor_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_OverridenColorSymbols);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x005691F0
// Name: ComputeDestFormat
// Source: json
//------------------------------------------------------------------------------
ImageFormat __usercall ComputeDestFormat@<eax>(ImageFormat fmt@<ecx>, int nChannelCount@<eax>)
{
  switch ( fmt )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_ABGR8888:
    case IMAGE_FORMAT_ARGB8888:
    case IMAGE_FORMAT_BGRA8888:
      return nChannelCount != 3 ? 5 : 2;
    case IMAGE_FORMAT_RGB888:
    case IMAGE_FORMAT_BGR888:
    case IMAGE_FORMAT_IA88:
    case IMAGE_FORMAT_BGRX8888:
    case IMAGE_FORMAT_RGBX8888:
      return IMAGE_FORMAT_I8;
    case IMAGE_FORMAT_DXT5:
      return IMAGE_FORMAT_DXT1;
    case IMAGE_FORMAT_RGBA16161616F:
      if ( nChannelCount != 2 )
        return IMAGE_FORMAT_R16F;
      return IMAGE_FORMAT_RG1616F;
    case IMAGE_FORMAT_RGB323232F:
      goto $LN8_10;
    case IMAGE_FORMAT_RGBA32323232F:
      if ( nChannelCount == 3 )
        return IMAGE_FORMAT_RGB323232F;
$LN8_10:
      if ( nChannelCount == 2 )
        return IMAGE_FORMAT_RG3232F;
      else
        return IMAGE_FORMAT_R32F;
    case IMAGE_FORMAT_RG1616F:
      return IMAGE_FORMAT_R16F;
    case IMAGE_FORMAT_RG3232F:
      return IMAGE_FORMAT_R32F;
    default:
      return fmt;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005692A0
// Name: protected: void CDmeTP_ComputeMipmaps::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::OnConstruction(CDmeTP_ComputeMipmaps *this)
{
  this->m_bNoNiceFiltering.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noNiceFiltering",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoNiceFiltering);
  this->m_bAlphaTestDownsampling.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "alphaTestDownsampling",
                                                  type: AT_BOOL,
                                                  pMemory: &this->m_bAlphaTestDownsampling);
  this->m_flAlphaTestDownsampleThreshhold.m_pAttribute = CDmElement::AddExternalAttribute(
                                                           this,
                                                           pAttributeName: "alphaTestDownsampleThreshhold",
                                                           type: AT_FLOAT,
                                                           pMemory: &this->m_flAlphaTestDownsampleThreshhold);
  this->m_flAlphaTestDownsampleHiFreqThreshhold.m_pAttribute = CDmElement::AddExternalAttribute(
                                                                 this,
                                                                 pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                                                                 type: AT_FLOAT,
                                                                 pMemory: &this->m_flAlphaTestDownsampleHiFreqThreshhold);
}

//------------------------------------------------------------------------------
// Address: 0x00569300
// Name: protected: void CDmePrecompiledTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePrecompiledTexture::OnConstruction(CDmePrecompiledTexture *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  this->m_ImageFileName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "imageFileName",
                                         type: AT_STRING,
                                         pMemory: &this->m_ImageFileName);
  this->m_Processors.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "processors",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Processors);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_Processors.m_pAttribute,
    typeSymbol: CDmeTextureProcessor::m_classType);
  this->m_pSourceTexture.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "sourceTexture",
                                          type: AT_FIRST_VALUE_TYPE,
                                          pMemory: &this->m_pSourceTexture);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pSourceTexture.m_pAttribute, typeSymbol: CDmeTexture::m_classType);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "startFrame", type: AT_INT, pMemory: &this->m_nStartFrame);
  this->m_nStartFrame.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = -1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "endFrame", type: AT_INT, pMemory: &this->m_nEndFrame);
  this->m_nEndFrame.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  value = 1;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "volumeTextureDepth",
         type: AT_INT,
         pMemory: &this->m_nVolumeTextureDepth);
  this->m_nVolumeTextureDepth.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  value = 1;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "textureArraySize",
         type: AT_INT,
         pMemory: &this->m_nTextureArraySize);
  this->m_nTextureArraySize.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, &value);
  this->m_nTextureType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "textureType",
                                        type: AT_INT,
                                        pMemory: &this->m_nTextureType);
  value = 1065353216;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "bumpScale",
         type: AT_FLOAT,
         pMemory: &this->m_flBumpScale);
  this->m_flBumpScale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, (float *)&value);
  value = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "pfmScale", type: AT_FLOAT, pMemory: &this->m_flPFMScale);
  this->m_flPFMScale.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, (float *)&value);
  this->m_nFilterType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "filterType",
                                       type: AT_INT,
                                       pMemory: &this->m_nFilterType);
  this->m_bClampS.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clamps",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampS);
  this->m_bClampT.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampt",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampT);
  this->m_bClampU.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampu",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampU);
  this->m_bLoadMipLevels.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "loadMipLevels",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bLoadMipLevels);
  this->m_bBorder.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "border",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bBorder);
  this->m_bNormalMap.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "normalMap",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bNormalMap);
  this->m_bSSBump.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "ssBump",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bSSBump);
  this->m_bNoMip.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noMip",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoMip);
  this->m_bAllMips.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "allMips",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bAllMips);
  this->m_bNoLod.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noLod",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoLod);
  this->m_bNoDebugOverride.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noDebugOverride",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoDebugOverride);
  this->m_bNoCompression.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "noCompression",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bNoCompression);
  this->m_bHintDxt5Compression.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "hintDxt5Compression",
                                                type: AT_BOOL,
                                                pMemory: &this->m_bHintDxt5Compression);
}

//------------------------------------------------------------------------------
// Address: 0x005695E0
// Name: public: void CDmeTP_ChangeColorChannels::ProcessImage(class CDmeImage __near *,class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::ProcessImage(
        CDmeTP_ChangeColorChannels *this,
        CDmeImage *pDstImage,
        CDmeLogLayer *pSrcImage)
{
  ImageFormat KeyCount; // esi
  const ImageFormatInfo_t *v5; // eax
  int v6; // ecx
  int m_Storage; // eax

  KeyCount = CDmeLogLayer::GetKeyCount(this: pSrcImage);
  v5 = ImageLoader::ImageFormatInfo(fmt: KeyCount);
  v6 = v5->m_nNumRedBits != 0;
  if ( v5->m_nNumGreenBits != 0 )
    ++v6;
  if ( v5->m_nNumBlueBits != 0 )
    ++v6;
  if ( v5->m_nNumAlphaBits != 0 )
    ++v6;
  m_Storage = this->m_nMaxChannels.m_Storage;
  if ( v6 > m_Storage )
    KeyCount = ComputeDestFormat(fmt: KeyCount, nChannelCount: m_Storage);
  CDmeImage::CopyFrom(this: pDstImage, (CDmeImage *)pSrcImage, fmt: KeyCount);
}

//------------------------------------------------------------------------------
// Address: 0x00569640
// Name: public: virtual void CDmeTP_ComputeMipmaps::ProcessTexture(class CDmeTexture __near *,class CDmeTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::ProcessTexture(
        CDmeTP_ComputeMipmaps *this,
        CDmeTexture *pSrcTexture,
        CDmeTexture *pDstTexture)
{
  CDmeTexture *v3; // esi
  int NumMipMapLevels; // edi
  bool v6; // zf
  void *v7; // esp
  void *v8; // esp
  CDmElement *v9; // eax
  CDmeTextureFrame *v10; // ebx
  bool v11; // al
  int j; // ebx
  int v13; // ebx
  int v14; // esi
  int v15; // ebx
  CDmeImageArray *MipLevel; // eax
  CDmeImage *v17; // edi
  CDmeTextureFrame_vtbl *v18; // esi
  CDmeTextureFrame *v19; // eax
  int v20; // eax
  CDmeImage *v21; // edi
  ImageFormat KeyCount; // eax
  float flGamma; // [esp+8h] [ebp-60h]
  _BYTE v24[12]; // [esp+Ch] [ebp-5Ch] BYREF
  DownsampleInfo_t info; // [esp+18h] [ebp-50h] BYREF
  int nImageCount; // [esp+24h] [ebp-44h]
  CDmeTP_ComputeMipmaps *v27; // [esp+28h] [ebp-40h]
  int k; // [esp+2Ch] [ebp-3Ch]
  int nDepth; // [esp+30h] [ebp-38h]
  int nWidth; // [esp+34h] [ebp-34h]
  int nFrameCount; // [esp+38h] [ebp-30h]
  int i; // [esp+3Ch] [ebp-2Ch]
  CDmeImage **ppDstImages; // [esp+40h] [ebp-28h]
  CDmeTextureFrame *pDstFrame; // [esp+44h] [ebp-24h]
  int nHeight; // [esp+48h] [ebp-20h]
  CDmeImage **ppSrcImages; // [esp+4Ch] [ebp-1Ch]
  int nTotalMipCount; // [esp+50h] [ebp-18h]
  int f; // [esp+54h] [ebp-14h]
  CDmeTextureFrame *v39; // [esp+58h] [ebp-10h]
  int nMipWidth; // [esp+5Ch] [ebp-Ch]
  int nMipDepth; // [esp+60h] [ebp-8h]
  int nMipHeight; // [esp+64h] [ebp-4h]

  v3 = pSrcTexture;
  v27 = this;
  nWidth = CDmeTexture::Width(this: pSrcTexture);
  nHeight = CDmeTexture::Height(this: pSrcTexture);
  nDepth = CDmeTexture::Depth(this: pSrcTexture);
  NumMipMapLevels = ImageLoader::GetNumMipMapLevels(width: nWidth, height: nHeight, depth: nDepth);
  nTotalMipCount = NumMipMapLevels;
  CDmElement::CopyAttributesTo(this: pSrcTexture, pCopy: pDstTexture, depth: TD_NONE);
  CDmeTexture::RemoveAllFrames(this: pDstTexture);
  v6 = !pSrcTexture->m_bClampS.m_Storage;
  info.m_flAlphaThreshhold = this->m_flAlphaTestDownsampleThreshhold.m_Storage;
  info.m_flAlphaHiFreqThreshhold = this->m_flAlphaTestDownsampleHiFreqThreshhold.m_Storage;
  info.m_nFlags = !v6;
  if ( pSrcTexture->m_bClampT.m_Storage )
    info.m_nFlags |= 2u;
  if ( pSrcTexture->m_bClampU.m_Storage )
    info.m_nFlags |= 4u;
  if ( this->m_bAlphaTestDownsampling.m_Storage )
    info.m_nFlags |= 0x10u;
  nFrameCount = pSrcTexture->m_Frames.m_Storage.m_Size;
  v7 = alloca(4 * NumMipMapLevels);
  ppSrcImages = (CDmeImage **)v24;
  v8 = alloca(4 * NumMipMapLevels);
  ppDstImages = (CDmeImage **)v24;
  for ( f = 0; f < nFrameCount; ++f )
  {
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Frames.m_Storage.m_Memory.m_pMemory[f]);
    v10 = (CDmeTextureFrame *)v9;
    if ( v9 == nullptr || (v11 = v9->IsA(this: v9, a2: CDmeTextureFrame::m_classType), v39 = v10, !v11) )
      v39 = nullptr;
    pDstFrame = (CDmeTextureFrame *)CDmeTexture::AddFrame(this: pDstTexture);
    if ( CDmeTextureFrame::GetMipLevel(this: v39, nIndex: 0) != nullptr )
    {
      if ( NumMipMapLevels > 0 )
      {
        for ( j = NumMipMapLevels; j != 0; --j )
          CDmeTextureFrame::AddMipLevel(this: pDstFrame);
      }
      v13 = 0;
      nImageCount = CDmeTextureFrame::ImageCount(this: v39);
      i = 0;
      if ( nImageCount > 0 )
      {
        do
        {
          CDmeTexture::GetImages(this: v3, nFrame: f, nImageIndex: v13, ppImages: ppSrcImages, nSize: NumMipMapLevels);
          if ( *ppSrcImages != nullptr )
          {
            nMipWidth = nWidth;
            nMipHeight = nHeight;
            nMipDepth = nDepth;
            if ( NumMipMapLevels > 0 )
            {
              v14 = (char *)ppSrcImages - (char *)ppDstImages;
              v15 = -3;
              v39 = (CDmeTextureFrame *)ppDstImages;
              for ( k = (char *)ppSrcImages - (char *)ppDstImages; ; v14 = k )
              {
                MipLevel = CDmeTextureFrame::GetMipLevel(this: pDstFrame, nIndex: v15 + 3);
                v17 = *(CDmeImage **)((char *)&v39->__vftable + v14);
                v18 = (CDmeTextureFrame_vtbl *)CDmeImageArray::AddImage(this: MipLevel);
                v19 = v39;
                v39->__vftable = v18;
                if ( v17 != nullptr )
                {
                  CDmeImage::CopyFrom(this: (CDmeImage *)v18, pSrcImage: v17, fmt: IMAGE_FORMAT_UNKNOWN);
                }
                else if ( v27->m_bNoNiceFiltering.m_Storage )
                {
                  CDmeImage::QuarterSize(this: (CDmeImage *)v18, pSrcImage: *(float *)&v19[-1].m_MipLevels.m_pAttribute);
                }
                else
                {
                  if ( v15 >= 0 )
                  {
                    v20 = nTotalMipCount;
                    if ( v15 <= nTotalMipCount )
                      v20 = v15;
                  }
                  else
                  {
                    v20 = 0;
                  }
                  v21 = ppDstImages[v20];
                  flGamma = v21->m_flGamma.m_Storage;
                  KeyCount = CDmeLogLayer::GetKeyCount(this: (CDmeLogLayer *)v21);
                  CDmeImage::Init(
                    this: (CDmeImage *)v18,
                    nWidth: nMipWidth,
                    nHeight: nMipHeight,
                    nDepth: nMipDepth,
                    fmt: KeyCount,
                    flGamma);
                  CDmeImage::DownsampleNiceFiltered(this: (CDmeImage *)v18, &info, pSrcImage: *(float *)&v21);
                }
                nMipHeight >>= 1;
                nMipDepth >>= 1;
                nMipWidth >>= 1;
                if ( nMipWidth < 1 )
                  nMipWidth = 1;
                if ( nMipHeight < 1 )
                  nMipHeight = 1;
                if ( nMipDepth < 1 )
                  nMipDepth = 1;
                v39 = (CDmeTextureFrame *)((char *)v39 + 4);
                if ( ++v15 + 3 >= nTotalMipCount )
                  break;
              }
              v3 = pSrcTexture;
              NumMipMapLevels = nTotalMipCount;
              v13 = i;
            }
          }
          i = ++v13;
        }
        while ( v13 < nImageCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005698F0
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
      pDstFrame = (CDmeTextureFrame *)CDmeTexture::AddFrame(this: v4);
      v7 = 0;
      nMipCount = CDmeTrack::GetClipCount(this: v20);
      m = 0;
      if ( nMipCount > 0 )
      {
        do
        {
          MipLevel = (CVTFTexture *)CDmeTextureFrame::GetMipLevel(this: (CDmeTextureFrame *)v20, nIndex: v7);
          pDstImageArray = (CDmeImageArray *)CDmeTextureFrame::AddMipLevel(this: pDstFrame);
          if ( MipLevel != nullptr )
          {
            v9 = 0;
            nImageCount = CDmeTrack::GetClipCount(this: MipLevel);
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
// Address: 0x00569A10
// Name: public: virtual void CDmeTP_ChangeColorChannels::ProcessTexture(class CDmeTexture __near *,class CDmeTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::ProcessTexture(
        CDmeTP_ChangeColorChannels *this,
        CDmeTexture *pSrcTexture,
        CDmeTexture *pDstTexture)
{
  CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels> func; // [esp+0h] [ebp-8h] BYREF

  func.m_pObject = this;
  func.m_pMemberFunc = (void (__thiscall *)(CDmeTP_ChangeColorChannels *, CDmeImage *, CDmeImage *))CDmeTP_ChangeColorChannels::ProcessImage;
  CDmeTexture::ProcessTexture<CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels>>(
    this: pDstTexture,
    pSrcTexture,
    &func);
}

//------------------------------------------------------------------------------
// Address: 0x00569B30
// Name: public: virtual bool CDmeTextureProcessor::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTextureProcessor::IsA(CDmeTextureProcessor *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00569B60
// Name: public: virtual int CDmeTextureProcessor::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureProcessor::GetInheritanceDepth(CDmeTextureProcessor *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00569BF0
// Name: public: virtual bool CDmeTP_ComputeMipmaps::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTP_ComputeMipmaps::IsA(CDmeTP_ComputeMipmaps *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTP_ComputeMipmaps::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00569C20
// Name: public: virtual int CDmeTP_ComputeMipmaps::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ComputeMipmaps::GetInheritanceDepth(CDmeTP_ComputeMipmaps *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTP_ComputeMipmaps::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00569CE0
// Name: protected: virtual void CDmeTP_ComputeMipmaps::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::PerformConstruction(CDmeTP_ComputeMipmaps *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTP_ComputeMipmaps::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00569D80
// Name: public: virtual bool CDmeTP_ChangeColorChannels::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTP_ChangeColorChannels::IsA(CDmeTP_ChangeColorChannels *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTP_ChangeColorChannels::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00569DB0
// Name: public: virtual int CDmeTP_ChangeColorChannels::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ChangeColorChannels::GetInheritanceDepth(
        CDmeTP_ChangeColorChannels *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTP_ChangeColorChannels::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00569E70
// Name: protected: virtual void CDmeTP_ChangeColorChannels::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::PerformConstruction(CDmeTP_ChangeColorChannels *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_nMaxChannels.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "maxChannels",
                                        type: AT_INT,
                                        pMemory: &this->m_nMaxChannels);
}

//------------------------------------------------------------------------------
// Address: 0x00569EA0
// Name: protected: CDmePrecompiledTexture::CDmePrecompiledTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePrecompiledTexture *__thiscall CDmePrecompiledTexture::CDmePrecompiledTexture(
        CDmePrecompiledTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmePrecompiledTexture_vtbl *)&CDmePrecompiledTexture::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Processors);
  this->m_pSourceTexture.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_pSourceTexture.m_pAttribute = nullptr;
  this->m_pSourceTexture.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ImageFileName.m_pAttribute = nullptr;
  this->m_ImageFileName.m_Storage.u.m_Id = -1;
  this->m_nStartFrame.m_pAttribute = nullptr;
  this->m_nStartFrame.m_Storage = 0;
  this->m_nEndFrame.m_pAttribute = nullptr;
  this->m_nEndFrame.m_Storage = 0;
  this->m_nTextureArraySize.m_pAttribute = nullptr;
  this->m_nTextureArraySize.m_Storage = 0;
  this->m_nVolumeTextureDepth.m_pAttribute = nullptr;
  this->m_nVolumeTextureDepth.m_Storage = 0;
  this->m_nTextureType.m_pAttribute = nullptr;
  this->m_nTextureType.m_Storage = 0;
  this->m_flBumpScale = 0;
  this->m_flPFMScale = 0;
  this->m_nFilterType.m_pAttribute = nullptr;
  this->m_nFilterType.m_Storage = 0;
  this->m_bClampS.m_pAttribute = nullptr;
  this->m_bClampS.m_Storage = false;
  this->m_bClampT.m_pAttribute = nullptr;
  this->m_bClampT.m_Storage = false;
  this->m_bClampU.m_pAttribute = nullptr;
  this->m_bClampU.m_Storage = false;
  this->m_bLoadMipLevels.m_pAttribute = nullptr;
  this->m_bLoadMipLevels.m_Storage = false;
  this->m_bBorder.m_pAttribute = nullptr;
  this->m_bBorder.m_Storage = false;
  this->m_bNormalMap.m_pAttribute = nullptr;
  this->m_bNormalMap.m_Storage = false;
  this->m_bSSBump.m_pAttribute = nullptr;
  this->m_bSSBump.m_Storage = false;
  this->m_bNoMip.m_pAttribute = nullptr;
  this->m_bNoMip.m_Storage = false;
  this->m_bAllMips.m_pAttribute = nullptr;
  this->m_bAllMips.m_Storage = false;
  this->m_bNoLod.m_pAttribute = nullptr;
  this->m_bNoLod.m_Storage = false;
  this->m_bNoDebugOverride.m_pAttribute = nullptr;
  this->m_bNoDebugOverride.m_Storage = false;
  this->m_bNoCompression.m_pAttribute = nullptr;
  this->m_bNoCompression.m_Storage = false;
  this->m_bHintDxt5Compression.m_pAttribute = nullptr;
  this->m_bHintDxt5Compression.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00569FF0
// Name: public: virtual bool CDmePrecompiledTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePrecompiledTexture::IsA(CDmePrecompiledTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePrecompiledTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056A020
// Name: public: virtual int CDmePrecompiledTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePrecompiledTexture::GetInheritanceDepth(CDmePrecompiledTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePrecompiledTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056A070
// Name: protected: virtual void CDmePrecompiledTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePrecompiledTexture::PerformConstruction(CDmePrecompiledTexture *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmePrecompiledTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00640A70
// Name: protected: virtual int CDmeTP_ComputeMipmaps::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ComputeMipmaps::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x006B6FC0
// Name: _dynamic_initializer_for__CDmeTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTexture::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTexture::s_Allocator,
    blockSize: 0xCCu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTexture pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTexture::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B70E0
// Name: _dynamic_initializer_for__CDmePrecompiledTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePrecompiledTexture::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePrecompiledTexture::s_Allocator,
    blockSize: 0x11Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePrecompiledTexture pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePrecompiledTexture::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7140
// Name: _dynamic_initializer_for__CDmeTextureProcessor::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTextureProcessor::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTextureProcessor::s_Allocator,
    blockSize: 0x44u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTextureProcessor pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC480
// Name: _dynamic_atexit_destructor_for__CDmeTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC4F0
// Name: _dynamic_atexit_destructor_for__CDmePrecompiledTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePrecompiledTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePrecompiledTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC500
// Name: _dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTextureProcessor::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B6FF0
// Name: _dynamic_initializer_for__g_CDmeTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7000
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
// Address: 0x006B7110
// Name: _dynamic_initializer_for__g_CDmePrecompiledTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePrecompiledTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7120
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
// Address: 0x006B7170
// Name: _dynamic_initializer_for__CDmeTP_ComputeMipmaps::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTP_ComputeMipmaps::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTP_ComputeMipmaps::s_Allocator,
    blockSize: 0x64u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTP_ComputeMipmaps pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B71A0
// Name: _dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B71B0
// Name: _dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTP_ComputeMipmaps_Helper,
           classname: "DmeTP_ComputeMipmaps",
           pFactory: &g_CDmeTP_ComputeMipmaps_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B71D0
// Name: _dynamic_initializer_for__CDmeTP_ChangeColorChannels::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTP_ChangeColorChannels::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTP_ChangeColorChannels::s_Allocator,
    blockSize: 0x4Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTP_ChangeColorChannels pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7200
// Name: _dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7210
// Name: _dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTP_ChangeColorChannels_Helper,
           classname: "DmeTP_ChangeColorChannels",
           pFactory: &g_CDmeTP_ChangeColorChannels_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BC490
// Name: _dynamic_atexit_destructor_for__g_CDmeTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTexture_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTexture_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC4A0
// Name: _dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTextureFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC510
// Name: _dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTP_ComputeMipmaps::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC520
// Name: _dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTP_ChangeColorChannels::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC530
// Name: _dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTP_ComputeMipmaps_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC540
// Name: _dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTP_ChangeColorChannels_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC550
// Name: _dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePrecompiledTexture_Factory.m_CallBackList);
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x100947A0
// Name: ComputeDestFormat
// Source: json
//------------------------------------------------------------------------------
ImageFormat __usercall ComputeDestFormat@<eax>(ImageFormat fmt@<ecx>, int nChannelCount@<eax>)
{
  switch ( fmt )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_ABGR8888:
    case IMAGE_FORMAT_ARGB8888:
    case IMAGE_FORMAT_BGRA8888:
      return nChannelCount != 3 ? 5 : 2;
    case IMAGE_FORMAT_RGB888:
    case IMAGE_FORMAT_BGR888:
    case IMAGE_FORMAT_IA88:
    case IMAGE_FORMAT_BGRX8888:
    case IMAGE_FORMAT_RGBX8888:
      return IMAGE_FORMAT_I8;
    case IMAGE_FORMAT_DXT5:
      return IMAGE_FORMAT_DXT1;
    case IMAGE_FORMAT_RGBA16161616F:
      if ( nChannelCount != 2 )
        return IMAGE_FORMAT_R16F;
      return IMAGE_FORMAT_RG1616F;
    case IMAGE_FORMAT_RGB323232F:
      goto $LN8_9;
    case IMAGE_FORMAT_RGBA32323232F:
      if ( nChannelCount == 3 )
        return IMAGE_FORMAT_RGB323232F;
$LN8_9:
      if ( nChannelCount == 2 )
        return IMAGE_FORMAT_RG3232F;
      else
        return IMAGE_FORMAT_R32F;
    case IMAGE_FORMAT_RG1616F:
      return IMAGE_FORMAT_R16F;
    case IMAGE_FORMAT_RG3232F:
      return IMAGE_FORMAT_R32F;
    default:
      return fmt;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094850
// Name: protected: void CDmeTP_ComputeMipmaps::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::OnConstruction(CDmeTP_ComputeMipmaps *this)
{
  this->m_bNoNiceFiltering.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noNiceFiltering",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoNiceFiltering);
  this->m_bAlphaTestDownsampling.m_pAttribute = CDmElement::AddExternalAttribute(
                                                  this,
                                                  pAttributeName: "alphaTestDownsampling",
                                                  type: AT_BOOL,
                                                  pMemory: &this->m_bAlphaTestDownsampling);
  this->m_flAlphaTestDownsampleThreshhold.m_pAttribute = CDmElement::AddExternalAttribute(
                                                           this,
                                                           pAttributeName: "alphaTestDownsampleThreshhold",
                                                           type: AT_FLOAT,
                                                           pMemory: &this->m_flAlphaTestDownsampleThreshhold);
  this->m_flAlphaTestDownsampleHiFreqThreshhold.m_pAttribute = CDmElement::AddExternalAttribute(
                                                                 this,
                                                                 pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                                                                 type: AT_FLOAT,
                                                                 pMemory: &this->m_flAlphaTestDownsampleHiFreqThreshhold);
}

//------------------------------------------------------------------------------
// Address: 0x100948B0
// Name: protected: void CDmePrecompiledTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePrecompiledTexture::OnConstruction(CDmePrecompiledTexture *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  this->m_ImageFileName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "imageFileName",
                                         type: AT_STRING,
                                         pMemory: &this->m_ImageFileName);
  this->m_Processors.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "processors",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_Processors);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_Processors.m_pAttribute,
    typeSymbol: CDmeTextureProcessor::m_classType);
  this->m_pSourceTexture.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "sourceTexture",
                                          type: AT_FIRST_VALUE_TYPE,
                                          pMemory: &this->m_pSourceTexture);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pSourceTexture.m_pAttribute, typeSymbol: CDmeTexture::m_classType);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "startFrame", type: AT_INT, pMemory: &this->m_nStartFrame);
  this->m_nStartFrame.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = -1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "endFrame", type: AT_INT, pMemory: &this->m_nEndFrame);
  this->m_nEndFrame.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  value = 1;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "volumeTextureDepth",
         type: AT_INT,
         pMemory: &this->m_nVolumeTextureDepth);
  this->m_nVolumeTextureDepth.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  value = 1;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "textureArraySize",
         type: AT_INT,
         pMemory: &this->m_nTextureArraySize);
  this->m_nTextureArraySize.m_pAttribute = v5;
  CDmAttribute::SetValue<int>(this: v5, &value);
  this->m_nTextureType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "textureType",
                                        type: AT_INT,
                                        pMemory: &this->m_nTextureType);
  value = 1065353216;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "bumpScale",
         type: AT_FLOAT,
         pMemory: &this->m_flBumpScale);
  this->m_flBumpScale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, (float *)&value);
  value = 1065353216;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "pfmScale", type: AT_FLOAT, pMemory: &this->m_flPFMScale);
  this->m_flPFMScale.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, (float *)&value);
  this->m_nFilterType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "filterType",
                                       type: AT_INT,
                                       pMemory: &this->m_nFilterType);
  this->m_bClampS.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clamps",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampS);
  this->m_bClampT.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampt",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampT);
  this->m_bClampU.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampu",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampU);
  this->m_bLoadMipLevels.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "loadMipLevels",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bLoadMipLevels);
  this->m_bBorder.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "border",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bBorder);
  this->m_bNormalMap.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "normalMap",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bNormalMap);
  this->m_bSSBump.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "ssBump",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bSSBump);
  this->m_bNoMip.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noMip",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoMip);
  this->m_bAllMips.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "allMips",
                                    type: AT_BOOL,
                                    pMemory: &this->m_bAllMips);
  this->m_bNoLod.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noLod",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoLod);
  this->m_bNoDebugOverride.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noDebugOverride",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoDebugOverride);
  this->m_bNoCompression.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "noCompression",
                                          type: AT_BOOL,
                                          pMemory: &this->m_bNoCompression);
  this->m_bHintDxt5Compression.m_pAttribute = CDmElement::AddExternalAttribute(
                                                this,
                                                pAttributeName: "hintDxt5Compression",
                                                type: AT_BOOL,
                                                pMemory: &this->m_bHintDxt5Compression);
}

//------------------------------------------------------------------------------
// Address: 0x10094B90
// Name: public: bool CDmePrecompiledTexture::ValidateValues(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePrecompiledTexture::ValidateValues(CDmePrecompiledTexture *this)
{
  const char *m_pAsString; // eax
  const char *v4; // esi
  char pBaseName[260]; // [esp+8h] [ebp-114h] BYREF
  char pRight[16]; // [esp+10Ch] [ebp-10h] BYREF

  if ( this->m_nTextureType.m_Storage != 1 || this->m_nTextureArraySize.m_Storage == 1 )
  {
    if ( this->m_nVolumeTextureDepth.m_Storage <= 1 || this->m_nTextureArraySize.m_Storage == 1 )
    {
      if ( this->m_bLoadMipLevels.m_Storage )
      {
        m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        V_FileBase(in: m_pAsString, out: pBaseName, maxlen: 260);
        V_StrRight(pStr: pBaseName, nChars: 5, pOut: pRight, outSize: 16);
        if ( V_stristr(pStr: pRight, pSearch: "_mip0") == nullptr )
        {
          v4 = this->m_Name.m_Storage.u.m_pAsString;
          if ( v4 == (const char *)-1 )
            v4 = defaultValue;
          _Warning(
            a1: "Invalid texture name (\"%s\") for explicitly loading mip levels - the top mip file should end in '_mip0'\n",
            v4);
        }
      }
      return 1;
    }
    else
    {
      _Warning(a1: "Specified a volume texture with a texture array size != 1!\n");
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Specified a cubemap with a texture array size != 1!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094C70
// Name: public: void CDmeTP_ChangeColorChannels::ProcessImage(class CDmeImage __near *,class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::ProcessImage(
        CDmeTP_ChangeColorChannels *this,
        CDmeImage *pDstImage,
        CDmeImage *pSrcImage)
{
  ImageFormat v4; // esi
  const ImageFormatInfo_t *v5; // eax
  int v6; // ecx
  int m_Storage; // eax

  v4 = CDmeImage::Format(this: pSrcImage);
  v5 = ImageLoader::ImageFormatInfo(fmt: v4);
  v6 = v5->m_nNumRedBits != 0;
  if ( v5->m_nNumGreenBits != 0 )
    ++v6;
  if ( v5->m_nNumBlueBits != 0 )
    ++v6;
  if ( v5->m_nNumAlphaBits != 0 )
    ++v6;
  m_Storage = this->m_nMaxChannels.m_Storage;
  if ( v6 > m_Storage )
    v4 = ComputeDestFormat(fmt: v4, nChannelCount: m_Storage);
  CDmeImage::CopyFrom(this: pDstImage, pSrcImage, fmt: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10094CD0
// Name: public: virtual void CDmeTP_ComputeMipmaps::ProcessTexture(class CDmeTexture __near *,class CDmeTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::ProcessTexture(
        CDmeTP_ComputeMipmaps *this,
        CDmeTexture *pSrcTexture,
        CDmeTexture *pDstTexture)
{
  CDmeTexture *v3; // esi
  int NumMipMapLevels; // edi
  bool v6; // zf
  void *v7; // esp
  void *v8; // esp
  CDmElement *v9; // eax
  CDmeTextureFrame *v10; // ebx
  bool v11; // al
  int j; // ebx
  int v13; // ebx
  int v14; // esi
  int v15; // ebx
  CDmeImageArray *MipLevel; // eax
  CDmeImage *v17; // edi
  CDmeTextureFrame_vtbl *v18; // esi
  CDmeTextureFrame *v19; // eax
  int v20; // eax
  CDmeImage *v21; // edi
  ImageFormat v22; // eax
  float flGamma; // [esp+8h] [ebp-60h]
  _BYTE v24[12]; // [esp+Ch] [ebp-5Ch] BYREF
  DownsampleInfo_t info; // [esp+18h] [ebp-50h] BYREF
  int nImageCount; // [esp+24h] [ebp-44h]
  CDmeTP_ComputeMipmaps *v27; // [esp+28h] [ebp-40h]
  int k; // [esp+2Ch] [ebp-3Ch]
  int nDepth; // [esp+30h] [ebp-38h]
  int nWidth; // [esp+34h] [ebp-34h]
  int nFrameCount; // [esp+38h] [ebp-30h]
  int i; // [esp+3Ch] [ebp-2Ch]
  CDmeImage **ppDstImages; // [esp+40h] [ebp-28h]
  CDmeTextureFrame *pDstFrame; // [esp+44h] [ebp-24h]
  int nHeight; // [esp+48h] [ebp-20h]
  CDmeImage **ppSrcImages; // [esp+4Ch] [ebp-1Ch]
  int nTotalMipCount; // [esp+50h] [ebp-18h]
  int f; // [esp+54h] [ebp-14h]
  CDmeTextureFrame *v39; // [esp+58h] [ebp-10h]
  int nMipWidth; // [esp+5Ch] [ebp-Ch]
  int nMipDepth; // [esp+60h] [ebp-8h]
  int nMipHeight; // [esp+64h] [ebp-4h]

  v3 = pSrcTexture;
  v27 = this;
  nWidth = (int)CDmeTexture::Width(this: pSrcTexture);
  nHeight = CDmeTexture::Height(this: pSrcTexture);
  nDepth = CDmeTexture::Depth(this: pSrcTexture);
  NumMipMapLevels = ImageLoader::GetNumMipMapLevels(width: nWidth, height: nHeight, depth: nDepth);
  nTotalMipCount = NumMipMapLevels;
  CDmElement::CopyAttributesTo(this: pSrcTexture, pCopy: pDstTexture, depth: TD_NONE);
  CDmeTexture::RemoveAllFrames(this: pDstTexture);
  v6 = !pSrcTexture->m_bClampS.m_Storage;
  info.m_flAlphaThreshhold = this->m_flAlphaTestDownsampleThreshhold.m_Storage;
  info.m_flAlphaHiFreqThreshhold = this->m_flAlphaTestDownsampleHiFreqThreshhold.m_Storage;
  info.m_nFlags = !v6;
  if ( pSrcTexture->m_bClampT.m_Storage )
    info.m_nFlags |= 2u;
  if ( pSrcTexture->m_bClampU.m_Storage )
    info.m_nFlags |= 4u;
  if ( this->m_bAlphaTestDownsampling.m_Storage )
    info.m_nFlags |= 0x10u;
  nFrameCount = pSrcTexture->m_Frames.m_Storage.m_Size;
  v7 = alloca(4 * NumMipMapLevels);
  ppSrcImages = (CDmeImage **)v24;
  v8 = alloca(4 * NumMipMapLevels);
  ppDstImages = (CDmeImage **)v24;
  for ( f = 0; f < nFrameCount; ++f )
  {
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_Frames.m_Storage.m_Memory.m_pMemory[f]);
    v10 = (CDmeTextureFrame *)v9;
    if ( v9 == nullptr || (v11 = v9->IsA(this: v9, a2: CDmeTextureFrame::m_classType), v39 = v10, !v11) )
      v39 = nullptr;
    pDstFrame = (CDmeTextureFrame *)CDmeTexture::AddFrame(this: pDstTexture);
    if ( CDmeTextureFrame::GetMipLevel(this: v39, nIndex: 0) != nullptr )
    {
      if ( NumMipMapLevels > 0 )
      {
        for ( j = NumMipMapLevels; j != 0; --j )
          CDmeTextureFrame::AddMipLevel(this: pDstFrame);
      }
      v13 = 0;
      nImageCount = CDmeTextureFrame::ImageCount(this: v39);
      i = 0;
      if ( nImageCount > 0 )
      {
        do
        {
          CDmeTexture::GetImages(this: v3, nFrame: f, nImageIndex: v13, ppImages: ppSrcImages, nSize: NumMipMapLevels);
          if ( *ppSrcImages != nullptr )
          {
            nMipWidth = nWidth;
            nMipHeight = nHeight;
            nMipDepth = nDepth;
            if ( NumMipMapLevels > 0 )
            {
              v14 = (char *)ppSrcImages - (char *)ppDstImages;
              v15 = -3;
              v39 = (CDmeTextureFrame *)ppDstImages;
              for ( k = (char *)ppSrcImages - (char *)ppDstImages; ; v14 = k )
              {
                MipLevel = CDmeTextureFrame::GetMipLevel(this: pDstFrame, nIndex: v15 + 3);
                v17 = *(CDmeImage **)((char *)&v39->__vftable + v14);
                v18 = (CDmeTextureFrame_vtbl *)CDmeImageArray::AddImage(this: MipLevel);
                v19 = v39;
                v39->__vftable = v18;
                if ( v17 != nullptr )
                {
                  CDmeImage::CopyFrom(this: (CDmeImage *)v18, pSrcImage: v17, fmt: IMAGE_FORMAT_UNKNOWN);
                }
                else if ( v27->m_bNoNiceFiltering.m_Storage )
                {
                  CDmeImage::QuarterSize(this: (CDmeImage *)v18, pSrcImage: *(float *)&v19[-1].m_MipLevels.m_pAttribute);
                }
                else
                {
                  if ( v15 >= 0 )
                  {
                    v20 = nTotalMipCount;
                    if ( v15 <= nTotalMipCount )
                      v20 = v15;
                  }
                  else
                  {
                    v20 = 0;
                  }
                  v21 = ppDstImages[v20];
                  flGamma = v21->m_flGamma.m_Storage;
                  v22 = CDmeImage::Format(this: v21);
                  CDmeImage::Init(
                    this: (CDmeImage *)v18,
                    nWidth: nMipWidth,
                    nHeight: nMipHeight,
                    nDepth: nMipDepth,
                    fmt: v22,
                    flGamma);
                  CDmeImage::DownsampleNiceFiltered(this: (CDmeImage *)v18, &info, pSrcImage: *(float *)&v21);
                }
                nMipHeight >>= 1;
                nMipDepth >>= 1;
                nMipWidth >>= 1;
                if ( nMipWidth < 1 )
                  nMipWidth = 1;
                if ( nMipHeight < 1 )
                  nMipHeight = 1;
                if ( nMipDepth < 1 )
                  nMipDepth = 1;
                v39 = (CDmeTextureFrame *)((char *)v39 + 4);
                if ( ++v15 + 3 >= nTotalMipCount )
                  break;
              }
              v3 = pSrcTexture;
              NumMipMapLevels = nTotalMipCount;
              v13 = i;
            }
          }
          i = ++v13;
        }
        while ( v13 < nImageCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100950A0
// Name: public: virtual void CDmeTP_ChangeColorChannels::ProcessTexture(class CDmeTexture __near *,class CDmeTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::ProcessTexture(
        CDmeTP_ChangeColorChannels *this,
        CDmeTexture *pSrcTexture,
        CDmeTexture *pDstTexture)
{
  CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels> func; // [esp+0h] [ebp-8h] BYREF

  func.m_pObject = this;
  func.m_pMemberFunc = CDmeTP_ChangeColorChannels::ProcessImage;
  CDmeTexture::ProcessTexture<CImageProcessorMemberFunctor<CDmeTP_ChangeColorChannels>>(
    this: pDstTexture,
    pSrcTexture,
    &func);
}

//------------------------------------------------------------------------------
// Address: 0x100951F0
// Name: public: virtual bool CDmeTextureProcessor::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTextureProcessor::IsA(CDmeTextureProcessor *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10095220
// Name: public: virtual int CDmeTextureProcessor::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureProcessor::GetInheritanceDepth(CDmeTextureProcessor *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10095290
// Name: public: virtual bool CDmeTP_ComputeMipmaps::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTP_ComputeMipmaps::IsA(CDmeTP_ComputeMipmaps *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTP_ComputeMipmaps::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x100952C0
// Name: public: virtual int CDmeTP_ComputeMipmaps::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ComputeMipmaps::GetInheritanceDepth(CDmeTP_ComputeMipmaps *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTP_ComputeMipmaps::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10095310
// Name: protected: virtual int CDmeTP_ComputeMipmaps::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ComputeMipmaps::AllocatedSize(CDmeTP_ComputeMipmaps *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x10095390
// Name: protected: virtual void CDmeTP_ComputeMipmaps::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ComputeMipmaps::PerformConstruction(CDmeTP_ComputeMipmaps *this)
{
  CDmElementFramework::Disconnect((CDmeTexture *)this);
  CDmeTP_ComputeMipmaps::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x10095430
// Name: public: virtual bool CDmeTP_ChangeColorChannels::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTP_ChangeColorChannels::IsA(CDmeTP_ChangeColorChannels *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTP_ChangeColorChannels::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10095460
// Name: public: virtual int CDmeTP_ChangeColorChannels::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ChangeColorChannels::GetInheritanceDepth(
        CDmeTP_ChangeColorChannels *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTP_ChangeColorChannels::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeTextureProcessor::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100954B0
// Name: protected: virtual int CDmeTP_ChangeColorChannels::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTP_ChangeColorChannels::AllocatedSize(CDmeTP_ChangeColorChannels *this)
{
  return 76;
}

//------------------------------------------------------------------------------
// Address: 0x10095520
// Name: protected: virtual void CDmeTP_ChangeColorChannels::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTP_ChangeColorChannels::PerformConstruction(CDmeTP_ChangeColorChannels *this)
{
  CDmElementFramework::Disconnect((CDmeTexture *)this);
  this->m_nMaxChannels.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "maxChannels",
                                        type: AT_INT,
                                        pMemory: &this->m_nMaxChannels);
}

//------------------------------------------------------------------------------
// Address: 0x10095550
// Name: protected: CDmePrecompiledTexture::CDmePrecompiledTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmePrecompiledTexture *__thiscall CDmePrecompiledTexture::CDmePrecompiledTexture(
        CDmePrecompiledTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmePrecompiledTexture_vtbl *)&CDmePrecompiledTexture::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Processors);
  this->m_pSourceTexture.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_pSourceTexture.m_pAttribute = nullptr;
  this->m_pSourceTexture.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ImageFileName.m_pAttribute = nullptr;
  this->m_ImageFileName.m_Storage.u.m_Id = -1;
  this->m_nStartFrame.m_pAttribute = nullptr;
  this->m_nStartFrame.m_Storage = 0;
  this->m_nEndFrame.m_pAttribute = nullptr;
  this->m_nEndFrame.m_Storage = 0;
  this->m_nTextureArraySize.m_pAttribute = nullptr;
  this->m_nTextureArraySize.m_Storage = 0;
  this->m_nVolumeTextureDepth.m_pAttribute = nullptr;
  this->m_nVolumeTextureDepth.m_Storage = 0;
  this->m_nTextureType.m_pAttribute = nullptr;
  this->m_nTextureType.m_Storage = 0;
  this->m_flBumpScale = 0;
  this->m_flPFMScale = 0;
  this->m_nFilterType.m_pAttribute = nullptr;
  this->m_nFilterType.m_Storage = 0;
  this->m_bClampS.m_pAttribute = nullptr;
  this->m_bClampS.m_Storage = false;
  this->m_bClampT.m_pAttribute = nullptr;
  this->m_bClampT.m_Storage = false;
  this->m_bClampU.m_pAttribute = nullptr;
  this->m_bClampU.m_Storage = false;
  this->m_bLoadMipLevels.m_pAttribute = nullptr;
  this->m_bLoadMipLevels.m_Storage = false;
  this->m_bBorder.m_pAttribute = nullptr;
  this->m_bBorder.m_Storage = false;
  this->m_bNormalMap.m_pAttribute = nullptr;
  this->m_bNormalMap.m_Storage = false;
  this->m_bSSBump.m_pAttribute = nullptr;
  this->m_bSSBump.m_Storage = false;
  this->m_bNoMip.m_pAttribute = nullptr;
  this->m_bNoMip.m_Storage = false;
  this->m_bAllMips.m_pAttribute = nullptr;
  this->m_bAllMips.m_Storage = false;
  this->m_bNoLod.m_pAttribute = nullptr;
  this->m_bNoLod.m_Storage = false;
  this->m_bNoDebugOverride.m_pAttribute = nullptr;
  this->m_bNoDebugOverride.m_Storage = false;
  this->m_bNoCompression.m_pAttribute = nullptr;
  this->m_bNoCompression.m_Storage = false;
  this->m_bHintDxt5Compression.m_pAttribute = nullptr;
  this->m_bHintDxt5Compression.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100956A0
// Name: public: virtual bool CDmePrecompiledTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePrecompiledTexture::IsA(CDmePrecompiledTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePrecompiledTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x100956D0
// Name: public: virtual int CDmePrecompiledTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePrecompiledTexture::GetInheritanceDepth(CDmePrecompiledTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePrecompiledTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10095710
// Name: protected: virtual int CDmePrecompiledTexture::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePrecompiledTexture::AllocatedSize(CDmePrecompiledTexture *this)
{
  return 284;
}

//------------------------------------------------------------------------------
// Address: 0x10095720
// Name: protected: virtual void CDmePrecompiledTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePrecompiledTexture::PerformConstruction(CDmePrecompiledTexture *this)
{
  CDmElementFramework::Disconnect((CDmeTexture *)this);
  CDmePrecompiledTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C4C80
// Name: _dynamic_initializer_for__CDmeTextureProcessor::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTextureProcessor::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTextureProcessor::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTextureProcessor pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C5380
// Name: _dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTextureProcessor::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTextureProcessor::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C4CB0
// Name: _dynamic_initializer_for__CDmeTP_ComputeMipmaps::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTP_ComputeMipmaps::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTP_ComputeMipmaps::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTP_ComputeMipmaps pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4CE0
// Name: _dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4CF0
// Name: _dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTP_ComputeMipmaps_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTP_ComputeMipmaps_Helper,
           classname: "DmeTP_ComputeMipmaps",
           pFactory: &g_CDmeTP_ComputeMipmaps_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C4D10
// Name: _dynamic_initializer_for__CDmeTP_ChangeColorChannels::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTP_ChangeColorChannels::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTP_ChangeColorChannels::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTP_ChangeColorChannels pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4D40
// Name: _dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4D50
// Name: _dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTP_ChangeColorChannels_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTP_ChangeColorChannels_Helper,
           classname: "DmeTP_ChangeColorChannels",
           pFactory: &g_CDmeTP_ChangeColorChannels_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C4D70
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4D90
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C4DA0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4E00
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4E30
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4E50
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4E60
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C5390
// Name: _dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTP_ComputeMipmaps::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTP_ComputeMipmaps::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C53A0
// Name: _dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTP_ChangeColorChannels::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTP_ChangeColorChannels::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C53B0
// Name: _dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTP_ComputeMipmaps_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTP_ComputeMipmaps_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x100C53C0
// Name: _dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTP_ChangeColorChannels_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTP_ChangeColorChannels_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x100C53D0
// Name: _dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePrecompiledTexture_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePrecompiledTexture_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x100C53E0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x100C53F0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100C5440
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100C5480
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100C5490
// Name: _DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x100C54A0
// Name: _DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x100C54B0
// Name: _DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

//------------------------------------------------------------------------------
// Address: 0x100C54C0
// Name: _DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

//------------------------------------------------------------------------------
// Address: 0x100C54D0
// Name: _DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x100C54E0
// Name: _DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_4);
}

//------------------------------------------------------------------------------
// Address: 0x100C54F0
// Name: _DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_5);
}

} // namespace vtex_dll
