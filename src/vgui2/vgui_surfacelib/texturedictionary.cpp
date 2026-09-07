// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_surfacelib/texturedictionary.cpp
// Functions: 64
// ============================================================

#include "vgui2\vgui_surfacelib\texturedictionary.h"

//------------------------------------------------------------------------------
// Address: 0x10007030
// Name: public: virtual class IMaterial2 __near * CTextureDictionary::GetTextureMaterial2(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CTextureDictionary::GetTextureMaterial2(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10011480
// Name: public: void CFontTextureRegen::UpdateBackingBits(struct Rect_t __near &,unsigned char const __near *,struct Rect_t __near &,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureRegen::UpdateBackingBits(
        CFontTextureRegen *this,
        Rect_t *subRect,
        const unsigned __int8 *pBits,
        Rect_t *uploadRect,
        ImageFormat format)
{
  int MemRequired; // edi
  int i; // ebx
  int v8; // edx
  int width; // eax
  int v10; // ecx
  int v11; // eax

  MemRequired = ImageLoader::GetMemRequired(
                  width: this->m_nWidth,
                  height: this->m_nHeight,
                  depth: 1,
                  imageFormat: this->m_nFormat,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( this->m_pTextureBits != nullptr )
  {
    if ( ImageLoader::ImageFormatInfo(fmt: this->m_nFormat)->m_nNumBytes == 4 )
    {
      for ( i = 0; i < subRect->height; ++i )
      {
        v8 = i + subRect->y;
        width = uploadRect->width;
        v10 = subRect->width;
        if ( v10 == width )
          v11 = i * width;
        else
          v11 = subRect->x + v8 * width;
        ImageLoader::ConvertImageFormat(
          src: &pBits[4 * v11],
          srcImageFormat: format,
          dst: &this->m_pTextureBits[4 * subRect->x + 4 * v8 * this->m_nWidth],
          dstImageFormat: this->m_nFormat,
          width: v10,
          height: 1,
          srcStride: 0,
          dstStride: 0);
      }
    }
    else if ( subRect->width == this->m_nWidth && subRect->height == this->m_nHeight )
    {
      _V_memcpy(dest: this->m_pTextureBits, src: pBits, count: MemRequired);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011570
// Name: public: void CMatSystemTexture::SetSubTextureRGBAEx(int,int,unsigned char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::SetSubTextureRGBAEx(
        CMatSystemTexture *this,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall,
        ImageFormat format)
{
  ITexture *m_pTexture; // esi
  int v8; // eax
  int v9; // eax
  CFontTextureRegen *m_pRegen; // ecx
  Rect_t textureSize; // [esp+0h] [ebp-20h] BYREF
  Rect_t subRect; // [esp+10h] [ebp-10h] BYREF

  if ( this->m_pMaterial != nullptr )
  {
    m_pTexture = this->m_pTexture;
    if ( m_pTexture != nullptr && (this->m_Flags & 1) != 0 )
    {
      v8 = this->m_iWide - drawX;
      subRect.x = drawX;
      subRect.y = drawY;
      subRect.width = subTextureWide;
      if ( subTextureWide >= v8 )
        subRect.width = v8;
      v9 = this->m_iTall - drawY;
      subRect.height = subTextureTall;
      if ( subTextureTall >= v9 )
        subRect.height = v9;
      m_pRegen = this->m_pRegen;
      textureSize.height = subTextureTall;
      textureSize.x = 0;
      textureSize.y = 0;
      textureSize.width = subTextureWide;
      CFontTextureRegen::UpdateBackingBits(this: m_pRegen, &subRect, pBits: rgba, uploadRect: &textureSize, format);
      m_pTexture->Download(this: m_pTexture, a2: &subRect, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011600
// Name: public: void CMatSystemTexture::UpdateSubTextureRGBA(int,int,unsigned char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::UpdateSubTextureRGBA(
        CMatSystemTexture *this,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall,
        ImageFormat imageFormat)
{
  ITexture *m_pTexture; // esi
  int m_iInputWide; // eax
  int m_iInputTall; // edx
  CFontTextureRegen *m_pRegen; // ecx
  Rect_t textureSize; // [esp+0h] [ebp-20h] BYREF
  Rect_t subRect; // [esp+10h] [ebp-10h] BYREF

  if ( this->m_pMaterial != nullptr )
  {
    m_pTexture = this->m_pTexture;
    if ( m_pTexture != nullptr && (this->m_Flags & 1) != 0 )
    {
      subRect.x = drawX;
      subRect.y = drawY;
      subRect.width = subTextureWide;
      m_iInputWide = this->m_iInputWide;
      subRect.height = subTextureTall;
      m_iInputTall = this->m_iInputTall;
      m_pRegen = this->m_pRegen;
      textureSize.width = m_iInputWide;
      textureSize.height = m_iInputTall;
      textureSize.x = 0;
      textureSize.y = 0;
      CFontTextureRegen::UpdateBackingBits(
        this: m_pRegen,
        &subRect,
        pBits: rgba,
        uploadRect: &textureSize,
        format: imageFormat);
      m_pTexture->Download(this: m_pTexture, a2: &subRect, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011680
// Name: class ITextureDictionary __near * TextureDictionary(void)
// Source: json
//------------------------------------------------------------------------------
CTextureDictionary *__cdecl TextureDictionary()
{
  return &s_TextureDictionary;
}

//------------------------------------------------------------------------------
// Address: 0x10011690
// Name: public: virtual void CTextureDictionary::SetTextureRGBA(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::SetTextureRGBA(
        CTextureDictionary *this,
        int id,
        const char *rgba,
        int wide,
        int tall)
{
  this->SetTextureRGBAEx(
    this,
    a2: id,
    a3: rgba,
    a4: wide,
    a5: tall,
    a6: IMAGE_FORMAT_RGBA8888,
    a7: k_ETextureScalingPointSample);
}

//------------------------------------------------------------------------------
// Address: 0x100116C0
// Name: public: virtual void CTextureDictionary::SetSubTextureRGBA(int,int,int,unsigned char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::SetSubTextureRGBA(
        CTextureDictionary *this,
        int id,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall)
{
  this->SetSubTextureRGBAEx(
    this,
    a2: id,
    a3: drawX,
    a4: drawY,
    a5: rgba,
    a6: subTextureWide,
    a7: subTextureTall,
    a8: IMAGE_FORMAT_RGBA8888);
}

//------------------------------------------------------------------------------
// Address: 0x100116F0
// Name: public: CFontTextureRegen::CFontTextureRegen(int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
CFontTextureRegen *__thiscall CFontTextureRegen::CFontTextureRegen(
        CFontTextureRegen *this,
        __int16 nWidth,
        __int16 nHeight,
        ImageFormat format)
{
  unsigned int MemRequired; // edi
  unsigned __int8 *v6; // eax

  this->m_nFormat = format;
  this->m_nWidth = nWidth;
  this->__vftable = (CFontTextureRegen_vtbl *)&CFontTextureRegen::`vftable';
  this->m_nHeight = nHeight;
  MemRequired = ImageLoader::GetMemRequired(
                  width: nWidth,
                  height: nHeight,
                  depth: 1,
                  imageFormat: format,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  v6 = (unsigned __int8 *)operator new(nSize: MemRequired);
  this->m_pTextureBits = v6;
  memset(dst: (int)v6, value: nullptr, count: MemRequired);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011750
// Name: public: virtual void CFontTextureRegen::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureRegen::RegenerateTextureBits(
        CFontTextureRegen *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pSubRect)
{
  int v6; // edi
  int MemRequired; // eax
  unsigned __int16 v8; // di
  int v9; // eax
  __int16 v10; // bx
  Rect_t *v11; // ecx
  int v12; // esi
  int v13; // edi
  int x; // eax
  unsigned __int8 *v15; // ecx
  int v16; // edi
  int v17; // esi
  int v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // edx
  int v21; // eax
  __int64 v22; // rax
  bool v23; // zf
  int m_nWidth; // ecx
  int m_nHeight; // eax
  unsigned __int8 *v26; // eax
  unsigned __int8 *m_pTextureBits; // [esp-8h] [ebp-58h]
  int v28; // [esp-4h] [ebp-54h]
  unsigned __int8 *pixelWriter; // [esp+4h] [ebp-4Ch]
  unsigned __int8 *pixelWriter_4; // [esp+8h] [ebp-48h]
  unsigned __int8 pixelWriter_10; // [esp+Eh] [ebp-42h]
  int pixelWriter_12; // [esp+10h] [ebp-40h]
  int pixelWriter_16; // [esp+14h] [ebp-3Ch]
  int pixelWriter_20; // [esp+18h] [ebp-38h]
  int pixelWriter_24; // [esp+1Ch] [ebp-34h]
  int pixelWriter_28; // [esp+20h] [ebp-30h]
  char pixelWriter_32; // [esp+24h] [ebp-2Ch]
  int v38; // [esp+30h] [ebp-20h]
  int v39; // [esp+34h] [ebp-1Ch]
  int xmax; // [esp+38h] [ebp-18h]
  int ymax; // [esp+40h] [ebp-10h]
  int ymaxa; // [esp+40h] [ebp-10h]
  int y; // [esp+44h] [ebp-Ch]
  int v45; // [esp+48h] [ebp-8h]
  unsigned __int8 *rgbaa; // [esp+5Ch] [ebp+Ch]
  unsigned __int8 *rgba; // [esp+5Ch] [ebp+Ch]

  if ( this->m_pTextureBits != nullptr )
  {
    if ( ImageLoader::ImageFormatInfo(fmt: this->m_nFormat)->m_nNumBytes == 4 )
    {
      if ( this->m_nFormat == pVTFTexture->Format(this: pVTFTexture) )
      {
        v6 = pSubRect->y;
        for ( ymax = v6 + pSubRect->height; v6 < ymax; ++v6 )
        {
          rgbaa = &pVTFTexture->ImageData(this: pVTFTexture, a2: 0, a3: 0, a4: 0, a5: 0, a6: v6, a7: 0)[4 * pSubRect->x];
          MemRequired = ImageLoader::GetMemRequired(
                          width: pSubRect->width,
                          height: 1,
                          depth: 1,
                          imageFormat: this->m_nFormat,
                          mipmap: false,
                          pAdjustedHeight: nullptr);
          _V_memcpy(
            dest: rgbaa,
            src: &this->m_pTextureBits[4 * pSubRect->x + 4 * v6 * this->m_nWidth],
            count: MemRequired);
        }
      }
      else
      {
        v8 = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
        pixelWriter = pVTFTexture->ImageData_2(this: pVTFTexture, a2: 0, a3: 0, a4: 0);
        switch ( pVTFTexture->Format(this: pVTFTexture) )
        {
          case IMAGE_FORMAT_RGBA8888:
          case IMAGE_FORMAT_UVWQ8888:
            v9 = 255;
            pixelWriter_10 = 4;
            pixelWriter_12 = 0x80000;
            v10 = 16;
            pixelWriter_16 = 1572880;
            pixelWriter_20 = 255;
            goto LABEL_24;
          case IMAGE_FORMAT_BGR888:
            v10 = 0;
            v9 = 255;
            pixelWriter_10 = 3;
            pixelWriter_12 = 524304;
            pixelWriter_16 = 0;
            pixelWriter_20 = 255;
            pixelWriter_32 = 0;
            goto LABEL_25;
          case IMAGE_FORMAT_I8:
            pixelWriter_10 = 1;
            goto LABEL_22;
          case IMAGE_FORMAT_A8:
            v10 = 0;
            v9 = 0;
            pixelWriter_10 = 1;
            pixelWriter_12 = 0;
            pixelWriter_16 = 0;
            pixelWriter_20 = 0;
            pixelWriter_32 = -1;
            goto LABEL_25;
          case IMAGE_FORMAT_BGRA8888:
            v9 = 255;
            pixelWriter_10 = 4;
            pixelWriter_12 = 524304;
            v10 = 0;
            pixelWriter_16 = 1572864;
            pixelWriter_20 = 255;
            goto LABEL_24;
          case IMAGE_FORMAT_BGRX8888:
            v10 = 0;
            v9 = 255;
            pixelWriter_10 = 4;
            pixelWriter_12 = 524304;
            pixelWriter_16 = 1572864;
            pixelWriter_20 = 255;
            pixelWriter_32 = 0;
            goto LABEL_25;
          case IMAGE_FORMAT_BGR565:
            v9 = 248;
            pixelWriter_10 = 2;
            pixelWriter_12 = 196616;
            v10 = -3;
            pixelWriter_16 = 65533;
            pixelWriter_20 = 248;
            pixelWriter_24 = 252;
            pixelWriter_32 = 0;
            goto LABEL_26;
          case IMAGE_FORMAT_BGRX5551:
          case IMAGE_FORMAT_BGRA5551:
            v9 = 248;
            pixelWriter_10 = 2;
            pixelWriter_12 = 131079;
            v10 = -3;
            pixelWriter_16 = 589821;
            pixelWriter_20 = 248;
            pixelWriter_32 = 0x80;
            goto LABEL_25;
          case IMAGE_FORMAT_BGRA4444:
            v9 = 240;
            pixelWriter_10 = 2;
            pixelWriter_12 = 4;
            v10 = -4;
            pixelWriter_16 = 589820;
            pixelWriter_20 = 240;
            goto LABEL_24;
          case IMAGE_FORMAT_RGBA16161616F:
          case IMAGE_FORMAT_RGBA16161616:
            v9 = 0xFFFF;
            pixelWriter_10 = 8;
            pixelWriter_12 = 0x100000;
            v10 = 32;
            pixelWriter_16 = 3145760;
            pixelWriter_20 = 0xFFFF;
            goto LABEL_24;
          case IMAGE_FORMAT_R32F:
            pixelWriter_10 = 4;
            pixelWriter_20 = -1;
            goto LABEL_23;
          case IMAGE_FORMAT_RGBA32323232F:
            v9 = -1;
            pixelWriter_10 = 16;
            pixelWriter_12 = 0x200000;
            v10 = 64;
            pixelWriter_16 = 6291520;
            pixelWriter_20 = -1;
            goto LABEL_24;
          case IMAGE_FORMAT_BGRA1010102:
            v9 = 1023;
            pixelWriter_10 = 4;
            pixelWriter_12 = 655380;
            v10 = 0;
            pixelWriter_16 = 1966080;
            pixelWriter_20 = 1023;
            pixelWriter_32 = 3;
            goto LABEL_25;
          default:
            pixelWriter_10 = 0;
LABEL_22:
            pixelWriter_20 = 255;
LABEL_23:
            v10 = 0;
            pixelWriter_12 = 0;
            pixelWriter_16 = 0;
            v9 = 0;
LABEL_24:
            pixelWriter_32 = v9;
LABEL_25:
            pixelWriter_24 = v9;
LABEL_26:
            v11 = pSubRect;
            pixelWriter_28 = v9;
            xmax = pSubRect->x + pSubRect->width;
            v12 = pSubRect->y;
            v38 = v12 + pSubRect->height;
            y = v12;
            if ( v12 < v38 )
            {
              v39 = v8;
              v13 = v12 * v8;
              ymaxa = v13;
              do
              {
                x = v11->x;
                pixelWriter_4 = &pixelWriter[v13 + v11->x * pixelWriter_10];
                v15 = &this->m_pTextureBits[4 * v11->x + 4 * v12 * this->m_nWidth];
                rgba = v15;
                if ( x < xmax )
                {
                  v45 = xmax - x;
                  do
                  {
                    v16 = v15[2];
                    v17 = v15[1];
                    v18 = *v15;
                    if ( pixelWriter_10 != 0 )
                    {
                      if ( pixelWriter_10 >= 5u )
                      {
                        if ( v10 <= 0 )
                          v22 = (__int64)(unsigned __int8)(rgba[2] & pixelWriter_28) >> -(char)v10;
                        else
                          v22 = (unsigned __int64)(unsigned __int8)(rgba[2] & pixelWriter_28) << v10;
                        if ( pixelWriter_10 == 8 )
                          *(_QWORD *)pixelWriter_4 = v22
                                                   | ((unsigned __int64)(unsigned __int8)(rgba[3] & pixelWriter_32) << SBYTE2(pixelWriter_16))
                                                   | ((unsigned __int64)(unsigned __int8)(rgba[1] & pixelWriter_24) << SBYTE2(pixelWriter_12))
                                                   | ((unsigned __int64)(v18 & (unsigned int)pixelWriter_20) << pixelWriter_12);
                      }
                      else
                      {
                        v19 = v16 & pixelWriter_28;
                        if ( v10 <= 0 )
                          v20 = v19 >> -(char)pixelWriter_16;
                        else
                          v20 = v19 << pixelWriter_16;
                        v21 = v20
                            | ((unsigned __int8)(rgba[3] & pixelWriter_32) << SBYTE2(pixelWriter_16))
                            | ((v17 & pixelWriter_24) << SBYTE2(pixelWriter_12))
                            | ((v18 & pixelWriter_20) << pixelWriter_12);
                        switch ( pixelWriter_10 )
                        {
                          case 1u:
                            *pixelWriter_4 = v21;
                            break;
                          case 2u:
                            *(_WORD *)pixelWriter_4 = v21;
                            break;
                          case 3u:
                            *(_WORD *)pixelWriter_4 = v21;
                            pixelWriter_4[2] = BYTE2(v21);
                            break;
                          case 4u:
                            *(_DWORD *)pixelWriter_4 = v21;
                            break;
                        }
                      }
                    }
                    pixelWriter_4 += pixelWriter_10;
                    v15 = rgba + 4;
                    v23 = v45-- == 1;
                    rgba += 4;
                  }
                  while ( !v23 );
                  v13 = ymaxa;
                  v12 = y;
                }
                v13 += v39;
                v11 = pSubRect;
                y = ++v12;
                ymaxa = v13;
              }
              while ( v12 < v38 );
            }
            break;
        }
      }
    }
    else
    {
      m_nWidth = this->m_nWidth;
      if ( pSubRect->width == m_nWidth )
      {
        m_nHeight = this->m_nHeight;
        if ( pSubRect->height == m_nHeight )
        {
          v28 = ImageLoader::GetMemRequired(
                  width: m_nWidth,
                  height: m_nHeight,
                  depth: 1,
                  imageFormat: this->m_nFormat,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
          m_pTextureBits = this->m_pTextureBits;
          v26 = pVTFTexture->ImageData_2(this: pVTFTexture, a2: 0, a3: 0, a4: 0);
          _V_memcpy(dest: v26, src: m_pTextureBits, count: v28);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011CE0
// Name: public: virtual void CFontTextureRegen::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureRegen::Release(CFontTextureRegen *this)
{
  if ( this->m_pTextureBits != nullptr )
  {
    free(pMem: this->m_pTextureBits);
    this->m_pTextureBits = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011D00
// Name: private: void CMatSystemTexture::CreateRegen(int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::CreateRegen(
        CMatSystemTexture *this,
        __int16 nWidth,
        __int16 nHeight,
        ImageFormat format)
{
  CFontTextureRegen *v5; // eax

  if ( this->m_pRegen == nullptr )
  {
    v5 = (CFontTextureRegen *)operator new(nSize: 0x10u);
    if ( v5 != nullptr )
      this->m_pRegen = CFontTextureRegen::CFontTextureRegen(this: v5, nWidth, nHeight, format);
    else
      this->m_pRegen = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011D40
// Name: public: void CMatSystemTexture::SetSubTextureRGBA(class IRenderDevice __near *,int,int,unsigned char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::SetSubTextureRGBA(
        CMatSystemTexture *this,
        IRenderDevice *pRenderDevice,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall)
{
  IRenderContext *v8; // esi
  const ResourceBinding_t<CTextureBits> *m_pBinding; // ecx
  Rect_t myRect; // [esp+Ch] [ebp-10h] BYREF

  v8 = pRenderDevice->GetRenderContext(this: pRenderDevice);
  v8->BindRenderTargets(this: v8, a2: (RenderTargetBinding_t__ *)-1);
  myRect.x = drawX;
  myRect.width = subTextureWide;
  myRect.y = drawY;
  m_pBinding = this->m_Texture2.m_pBinding;
  myRect.height = subTextureTall;
  m_pBinding->m_nLastBindFrame = g_nResourceFrameCount;
  v8->SetTextureData(
    this: v8,
    a2: this->m_Texture2.m_pBinding,
    a3: nullptr,
    a4: rgba,
    a5: 4 * subTextureTall * subTextureWide,
    a6: false,
    a7: 0,
    a8: &myRect);
  v8->Submit(this: v8);
  pRenderDevice->ReleaseRenderContext(this: pRenderDevice, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10011E80
// Name: public: virtual void CTextureDictionary::SetSubTextureRGBAEx(int,int,int,unsigned char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::SetSubTextureRGBAEx(
        CTextureDictionary *this,
        int id,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall,
        ImageFormat format)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v9; // ecx

  if ( this->IsValidId(this, a2: id) )
  {
    v9 = &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id];
    if ( g_pMaterialSystem != nullptr )
      CMatSystemTexture::SetSubTextureRGBAEx(
        this: &v9->m_Element,
        drawX,
        drawY,
        rgba,
        subTextureWide,
        subTextureTall,
        format);
    else
      CMatSystemTexture::SetSubTextureRGBA(
        this: &v9->m_Element,
        pRenderDevice: g_pRenderDevice,
        drawX,
        drawY,
        rgba,
        subTextureWide,
        subTextureTall);
  }
  else
  {
    _Msg(a1: "SetSubTextureRGBA: Invalid texture id %i\n", id);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011F10
// Name: public: virtual void CTextureDictionary::UpdateSubTextureRGBA(int,int,int,unsigned char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::UpdateSubTextureRGBA(
        CTextureDictionary *this,
        int id,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall,
        ImageFormat imageFormat)
{
  if ( this->IsValidId(this, a2: id) )
    CMatSystemTexture::UpdateSubTextureRGBA(
      this: &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id].m_Element,
      drawX,
      drawY,
      rgba,
      subTextureWide,
      subTextureTall,
      imageFormat);
  else
    _Msg(a1: "UpdateSubTextureRGBA: Invalid texture id %i\n", id);
}

//------------------------------------------------------------------------------
// Address: 0x10011F70
// Name: public: virtual class IMaterial __near * CTextureDictionary::GetTextureMaterial(int)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CTextureDictionary::GetTextureMaterial(CTextureDictionary *this, int id)
{
  if ( this->IsValidId(this, a2: id) )
    return this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id].m_Element.m_pMaterial;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10011FB0
// Name: public: virtual struct ResourceBinding_t<class CTextureBits> const __near * CTextureDictionary::GetTextureHandle(int)
// Source: json
//------------------------------------------------------------------------------
const ResourceBinding_t<CTextureBits> *__thiscall CTextureDictionary::GetTextureHandle(
        CTextureDictionary *this,
        int id)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *m_pMemory; // ecx
  int v5; // eax

  if ( !this->IsValidId(this, a2: id) )
    return nullptr;
  m_pMemory = this->m_Textures.m_Memory.m_pMemory;
  v5 = (unsigned __int16)id << 6;
  (*(const ResourceBinding_t<CTextureBits> **)((char *)&m_pMemory->m_Element.m_Texture2.m_pBinding + v5))->m_nLastBindFrame = g_nResourceFrameCount;
  return *(const ResourceBinding_t<CTextureBits> **)((char *)&m_pMemory->m_Element.m_Texture2.m_pBinding + v5);
}

//------------------------------------------------------------------------------
// Address: 0x10011FF0
// Name: public: virtual void CTextureDictionary::GetTextureSize(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::GetTextureSize(CTextureDictionary *this, int id, int *iWide, int *iTall)
{
  int v5; // eax

  if ( this->IsValidId(this, a2: id) )
  {
    v5 = (unsigned __int16)id << 6;
    *iWide = *(int *)((char *)&this->m_Textures.m_Memory.m_pMemory->m_Element.m_iWide + v5);
    *iTall = *(int *)((char *)&this->m_Textures.m_Memory.m_pMemory->m_Element.m_iTall + v5);
  }
  else
  {
    *iTall = 0;
    *iWide = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012050
// Name: public: virtual void CTextureDictionary::GetTextureTexCoords(int,float __near &,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::GetTextureTexCoords(
        CTextureDictionary *this,
        int id,
        float *s0,
        float *t0,
        float *s1,
        float *t1)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v7; // eax

  if ( this->IsValidId(this, a2: id) )
  {
    v7 = &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id];
    *s0 = v7->m_Element.m_s0;
    *t0 = v7->m_Element.m_t0;
    *s1 = v7->m_Element.m_s1;
    *t1 = v7->m_Element.m_t1;
  }
  else
  {
    *t0 = 0.0;
    *s0 = 0.0;
    *t1 = 1.0;
    *s1 = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100120C0
// Name: public: void CUtlLinkedList<class CMatSystemTexture,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMatSystemTexture,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012150
// Name: protected: unsigned short CUtlLinkedList<class CMatSystemTexture,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  int v9; // ecx
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *m_pMemory; // edx
  char *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result << 6;
    if ( multilist )
    {
      v11 = (char *)this->m_Memory.m_pMemory + v9;
      *((_WORD *)v11 + 31) = -1;
      *((_WORD *)v11 + 30) = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Next + v9) = result;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Previous + v9) = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100122D0
// Name: private: void CMatSystemTexture::CleanUpMaterial(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::CleanUpMaterial(CMatSystemTexture *this)
{
  IMaterial *m_pMaterial; // ecx
  ITexture *m_pTexture; // ecx
  CFontTextureRegen *m_pRegen; // edi
  unsigned __int8 *m_pTextureBits; // eax

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr )
  {
    m_pTexture->SetTextureRegenerator(this: m_pTexture, a2: nullptr, a3: true);
    this->m_pTexture->DecrementReferenceCount(this: this->m_pTexture);
    this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
  m_pRegen = this->m_pRegen;
  if ( m_pRegen != nullptr )
  {
    if ( (this->m_Flags & 2) == 0 )
    {
      m_pTextureBits = m_pRegen->m_pTextureBits;
      m_pRegen->__vftable = (CFontTextureRegen_vtbl *)&CFontTextureRegen::`vftable';
      if ( m_pTextureBits != nullptr )
      {
        free(pMem: m_pTextureBits);
        m_pRegen->m_pTextureBits = nullptr;
      }
      free(pMem: m_pRegen);
    }
    this->m_pRegen = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012360
// Name: public: void CMatSystemTexture::SetMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::SetMaterial(CMatSystemTexture *this, IMaterial *pMaterial)
{
  IMaterial *v3; // ecx
  int v4; // eax
  IMaterial *m_pMaterial; // ecx
  int v6; // eax
  float v7; // xmm0_4
  float m_iWide; // xmm2_4
  float v9; // xmm1_4
  bool v10; // zf
  IMaterialVar *v11; // eax
  IMaterialVar *v12; // edi
  ITexture *v13; // eax
  ImageFormat v14; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    CMatSystemTexture::CleanUpMaterial(this);
    v3 = pMaterial;
    this->m_pMaterial = pMaterial;
    if ( v3 != nullptr )
    {
      v3->IncrementReferenceCount(this: v3);
      v4 = this->m_pMaterial->GetMappingWidth(this: this->m_pMaterial);
      m_pMaterial = this->m_pMaterial;
      this->m_iWide = v4;
      v6 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v7 = 0.0;
      m_iWide = (float)this->m_iWide;
      this->m_iTall = v6;
      v9 = 0.0;
      if ( m_iWide > 0.0 && (float)v6 > 0.0 )
      {
        v7 = 0.5 / m_iWide;
        v9 = 0.5 / (float)v6;
      }
      v10 = (this->m_Flags & 1) == 0;
      this->m_s0 = v7;
      this->m_t0 = v9;
      this->m_s1 = 1.0 - v7;
      this->m_t1 = 1.0 - v9;
      if ( !v10 )
      {
        v11 = this->m_pMaterial->FindVar(this: this->m_pMaterial, a2: "$baseTexture", a3: (char *)&pMaterial + 3, a4: 1);
        v12 = v11;
        if ( HIBYTE(pMaterial) != 0 && v11->IsDefined(this: v11) )
        {
          v13 = (ITexture *)v12->GetTextureValue(this: v12);
          this->m_pTexture = v13;
          if ( v13 != nullptr )
          {
            v13->IncrementReferenceCount(this: v13);
            v14 = this->m_pTexture->GetImageFormat(this: this->m_pTexture);
            CMatSystemTexture::CreateRegen(this, nWidth: this->m_iWide, nHeight: this->m_iTall, format: v14);
            this->m_pTexture->SetTextureRegenerator(this: this->m_pTexture, a2: this->m_pRegen, a3: true);
          }
        }
      }
    }
    else
    {
      this->m_t0 = 0.0;
      this->m_s0 = 0.0;
      this->m_iTall = 0;
      this->m_iWide = 0;
      this->m_t1 = 1.0;
      this->m_s1 = 1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100124A0
// Name: public: void CMatSystemTexture::ReferenceOtherProcedural(class CMatSystemTexture __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::ReferenceOtherProcedural(
        CMatSystemTexture *this,
        CMatSystemTexture *pTexture,
        IMaterial *pMaterial)
{
  IMaterialVar *v4; // eax
  ITexture *v5; // eax
  bool bFound; // [esp+7h] [ebp-1h] BYREF

  CMatSystemTexture::CleanUpMaterial(this);
  this->m_Flags |= 2u;
  this->m_pMaterial = pMaterial;
  if ( pMaterial != nullptr )
  {
    this->m_iWide = pTexture->m_iWide;
    this->m_iTall = pTexture->m_iTall;
    this->m_s0 = pTexture->m_s0;
    this->m_t0 = pTexture->m_t0;
    this->m_s1 = pTexture->m_s1;
    this->m_t1 = pTexture->m_t1;
    pMaterial->IncrementReferenceCount(this: pMaterial);
    v4 = this->m_pMaterial->FindVar(this: this->m_pMaterial, a2: "$baseTexture", a3: &bFound, a4: 1);
    if ( bFound )
    {
      v5 = (ITexture *)v4->GetTextureValue(this: v4);
      this->m_pTexture = v5;
      if ( v5 != nullptr )
      {
        v5->IncrementReferenceCount(this: v5);
        this->m_pRegen = pTexture->m_pRegen;
      }
    }
  }
  else
  {
    this->m_t0 = 0.0;
    this->m_s0 = 0.0;
    this->m_iTall = 0;
    this->m_iWide = 0;
    this->m_t1 = 1.0;
    this->m_s1 = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012560
// Name: public: void CMatSystemTexture::SetMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::SetMaterial(CMatSystemTexture *this, const char *pFileName)
{
  IMaterial *v3; // esi

  v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: pFileName, a3: "VGUI textures", a4: 1, a5: 0);
  if ( v3 == nullptr || v3->IsErrorMaterial(this: v3) )
    _Msg(a1: "--- Missing Vgui material %s\n", pFileName);
  CMatSystemTexture::SetMaterial(this, pMaterial: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100125C0
// Name: public: virtual bool CTextureDictionary::IsValidId(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTextureDictionary::IsValidId(CTextureDictionary *this, int id)
{
  bool result; // al
  int m_nAllocationCount; // edi
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v4; // ecx
  unsigned __int16 m_Previous; // si

  if ( id == 0 )
    return false;
  m_nAllocationCount = this->m_Textures.m_Memory.m_nAllocationCount;
  result = (unsigned __int16)id < m_nAllocationCount
        && (unsigned __int16)id <= this->m_Textures.m_LastAlloc.index
        && ((v4 = &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id], (m_Previous = v4->m_Previous) != (_WORD)id)
         || v4->m_Next == (_WORD)id)
        && (unsigned __int16)id < m_nAllocationCount
        && m_Previous != (_WORD)id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012630
// Name: public: virtual void CTextureDictionary::BindTextureToFile(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::BindTextureToFile(CTextureDictionary *this, int id, const char *pFileName)
{
  unsigned __int16 v3; // si
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v5; // esi
  const char *v6; // edi

  v3 = id;
  if ( this->IsValidId(this, a2: id) )
  {
    v5 = &this->m_Textures.m_Memory.m_pMemory[v3];
    CRC32_Init(pulCRC: (unsigned int *)&id);
    v6 = pFileName;
    CRC32_ProcessBuffer(pulCRC: (unsigned int *)&id, pBuffer: pFileName, nBuffer: strlen(pFileName));
    CRC32_Final(pulCRC: (unsigned int *)&id);
    if ( v5->m_Element.m_pMaterial == nullptr || id != v5->m_Element.m_crcFile )
    {
      v5->m_Element.m_crcFile = id;
      CMatSystemTexture::SetMaterial(this: &v5->m_Element, pFileName: v6);
    }
  }
  else
  {
    _Msg(a1: "BindTextureToFile: Invalid texture id for file %s\n", pFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100126C0
// Name: public: virtual void CTextureDictionary::BindTextureToMaterial(int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::BindTextureToMaterial(CTextureDictionary *this, int id, IMaterial *pMaterial)
{
  if ( this->IsValidId(this, a2: id) )
    CMatSystemTexture::SetMaterial(
      this: &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id].m_Element,
      pMaterial);
  else
    _Msg(a1: "BindTextureToFile: Invalid texture id %d\n", id);
}

//------------------------------------------------------------------------------
// Address: 0x10012710
// Name: public: virtual void CTextureDictionary::BindTextureToMaterialReference(int,int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::BindTextureToMaterialReference(
        CTextureDictionary *this,
        int id,
        int referenceId,
        IMaterial *pMaterial)
{
  if ( this->IsValidId(this, a2: id) && this->IsValidId(this, a2: referenceId) )
    CMatSystemTexture::ReferenceOtherProcedural(
      this: &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id].m_Element,
      pTexture: &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)referenceId].m_Element,
      pMaterial);
  else
    _Msg(a1: "BindTextureToFile: Invalid texture ids %d %d\n", id, referenceId);
}

//------------------------------------------------------------------------------
// Address: 0x10012780
// Name: public: virtual int CTextureDictionary::FindTextureIdForTextureFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureDictionary::FindTextureIdForTextureFile(CTextureDictionary *this, const char *pFileName)
{
  int m_Head; // edi
  int v4; // esi
  char *v5; // eax
  int (__thiscall ***v6)(_DWORD); // eax
  const char *v7; // eax

  m_Head = this->m_Textures.m_Head;
  if ( m_Head == 0xFFFF )
    return -1;
  while ( 1 )
  {
    v4 = (unsigned __int16)m_Head << 6;
    v5 = (char *)this->m_Textures.m_Memory.m_pMemory + v4;
    if ( v5 != nullptr )
    {
      v6 = *((int (__thiscall ****)(_DWORD))v5 + 5);
      if ( v6 != nullptr )
      {
        v7 = (const char *)(**v6)(a1: v6);
        if ( _V_stricmp(s1: v7, s2: pFileName) == 0 )
          break;
      }
    }
    m_Head = *(unsigned __int16 *)((char *)&this->m_Textures.m_Memory.m_pMemory->m_Next + v4);
    if ( m_Head == 0xFFFF )
      return -1;
  }
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x100127F0
// Name: public: void CUtlLinkedList<class CMatSystemTexture,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMatSystemTexture,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *m_pMemory; // ebx
  int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem << 6;
  *(unsigned __int16 *)((char *)&this->m_Memory.m_pMemory->m_Next + v5) = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Previous + v5) = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before << 6;
    m_Tail = *(unsigned __int16 *)((char *)&m_pMemory->m_Previous + v7);
    *(unsigned __int16 *)((char *)&m_pMemory->m_Previous + v5) = m_Tail;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Previous + v7) = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012880
// Name: public: void CMatSystemTexture::SetTextureRGBA(char const __near *,int,int,enum ImageFormat,enum ETextureScaling)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMatSystemTexture::SetTextureRGBA(
        CMatSystemTexture *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const char *rgba,
        int wide,
        int tall,
        ImageFormat format,
        ETextureScaling eScaling)
{
  int v9; // eax
  int v10; // ebx
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  IMaterial *v13; // esi
  char pTextureName[64]; // [esp+4h] [ebp-40h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    if ( this->m_pMaterial == nullptr )
    {
      V_snprintf(pDest: pTextureName, maxLen: 64, pFormat: "__vgui_texture_%d", s_nTextureId);
      ++s_nTextureId;
      v9 = 789260;
      if ( eScaling == k_ETextureScalingPointSample )
        v9 = 789261;
      v10 = ((int (__thiscall *)(IMaterialSystem *, char *, const char *, int, int, ImageFormat, int, int, int))g_pMaterialSystem->CreateProceduralTexture)(
              a1: g_pMaterialSystem,
              a2: pTextureName,
              a3: "VGUI textures",
              a4: wide,
              a5: tall,
              a6: format,
              a7: v9,
              a8: a3,
              a9: a2);
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v11 != nullptr )
        v12 = KeyValues::KeyValues(this: v11, setName: "UnlitGeneric");
      else
        v12 = nullptr;
      KeyValues::SetInt(this: v12, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v12, keyName: "$vertexalpha", value: 1);
      KeyValues::SetInt(this: v12, keyName: "$ignorez", value: 1);
      KeyValues::SetInt(this: v12, keyName: "$no_fullbright", value: 1);
      KeyValues::SetInt(this: v12, keyName: "$translucent", value: 1);
      KeyValues::SetString(this: v12, keyName: "$basetexture", value: pTextureName);
      v13 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: pTextureName, a3: v12);
      v13->Refresh(this: v13);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 44))(a1: v10);
      CMatSystemTexture::SetMaterial(this, pMaterial: v13);
      this->m_iInputTall = tall;
      this->m_iInputWide = wide;
      v13->DecrementReferenceCount(this: v13);
    }
    CMatSystemTexture::SetSubTextureRGBAEx(
      this,
      drawX: 0,
      drawY: 0,
      (const unsigned __int8 *)rgba,
      subTextureWide: wide,
      subTextureTall: tall,
      format);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100129E0
// Name: public: void CMatSystemTexture::SetTextureRGBA(class IRenderDevice __near *,char const __near *,int,int,enum ImageFormat,enum ETextureScaling)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::SetTextureRGBA(
        CMatSystemTexture *this,
        IRenderDevice *pRenderDevice,
        const char *rgba,
        int width,
        int height,
        ImageFormat format,
        ETextureScaling eScaling)
{
  const ResourceBinding_t<CTextureBits> *v8; // eax
  const ResourceBinding_t<CTextureBits> *m_pBinding; // ecx
  TextureHeader_t spec; // [esp+Ch] [ebp-2Ch] BYREF
  char pResourceName[16]; // [esp+28h] [ebp-10h] BYREF

  if ( this->m_Texture2.m_pBinding == nullptr )
  {
    spec.m_nWidth = width;
    memset(&spec.m_nMultisampleType, 0, 20);
    spec.m_nHeight = height;
    *(_DWORD *)&spec.m_nDepth = 16777217;
    V_snprintf(pDest: pResourceName, maxLen: 16, pFormat: "%d", s_UniqueID);
    v8 = pRenderDevice->FindOrCreateTexture(this: pRenderDevice, a2: "matsystemtexture", a3: pResourceName, a4: &spec);
    m_pBinding = this->m_Texture2.m_pBinding;
    if ( m_pBinding != nullptr )
    {
      _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
      this->m_Texture2.m_pBinding = nullptr;
    }
    this->m_Texture2.m_pBinding = v8;
    if ( v8 != nullptr )
      _InterlockedExchangeAdd(&v8->m_nRefCount.m_value, 1u);
    ++s_UniqueID;
  }
  this->m_iWide = width;
  this->m_iTall = height;
  CMatSystemTexture::SetSubTextureRGBA(
    this,
    pRenderDevice,
    drawX: 0,
    drawY: 0,
    (const unsigned __int8 *)rgba,
    subTextureWide: width,
    subTextureTall: height);
}

//------------------------------------------------------------------------------
// Address: 0x10012AB0
// Name: public: virtual void CTextureDictionary::SetTextureRGBAEx(int,char const __near *,int,int,enum ImageFormat,enum ETextureScaling)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTextureDictionary::SetTextureRGBAEx(
        CTextureDictionary *this@<ecx>,
        int a2@<ebx>,
        int id,
        const char *rgba,
        int wide,
        int tall,
        ImageFormat format,
        ETextureScaling eScaling)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v9; // ecx

  if ( this->IsValidId(this, a2: id) )
  {
    v9 = &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id];
    if ( g_pMaterialSystem != nullptr )
      CMatSystemTexture::SetTextureRGBA(this: &v9->m_Element, a2, a3: (int)this, rgba, wide, tall, format, eScaling);
    else
      CMatSystemTexture::SetTextureRGBA(
        this: &v9->m_Element,
        pRenderDevice: g_pRenderDevice,
        rgba,
        width: wide,
        height: tall,
        format,
        eScaling);
  }
  else
  {
    _Msg(a1: "SetTextureRGBA: Invalid texture id %i\n", id);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012B40
// Name: class CMatSystemTexture __near * Construct<class CMatSystemTexture>(class CMatSystemTexture __near *)
// Source: json
//------------------------------------------------------------------------------
CMatSystemTexture *__cdecl Construct<CMatSystemTexture>(CMatSystemTexture *pMemory)
{
  CMatSystemTexture *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->m_Texture2.m_pBinding = nullptr;
  pMemory->m_Texture2.m_pBinding = nullptr;
  pMemory->m_t0 = 0.0;
  pMemory->m_s0 = 0.0;
  pMemory->m_pMaterial = nullptr;
  pMemory->m_pTexture = nullptr;
  pMemory->m_crcFile = 0;
  pMemory->m_iTall = 0;
  pMemory->m_iWide = 0;
  pMemory->m_t1 = 1.0;
  pMemory->m_s1 = 1.0;
  pMemory->m_Flags = 0;
  pMemory->m_pRegen = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012BB0
// Name: public: void CUtlLinkedList<class CMatSystemTexture,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMatSystemTexture,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *m_pMemory; // ecx
  int v3; // esi
  unsigned __int16 v4; // di
  CMatSystemTexture *v5; // esi
  const ResourceBinding_t<CTextureBits> *m_pBinding; // eax
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v8; // ax
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *v9; // [esp+0h] [ebp-4h]

  v9 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head << 6;
        v4 = *(unsigned __int16 *)((char *)&m_pMemory->m_Next + v3);
        v5 = (CMatSystemTexture *)((char *)&m_pMemory->m_Element + v3);
        CMatSystemTexture::CleanUpMaterial(this: v5);
        m_pBinding = v5->m_Texture2.m_pBinding;
        if ( m_pBinding != nullptr )
        {
          _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
          v5->m_Texture2.m_pBinding = nullptr;
        }
        LOWORD(v5[1].m_s0) = m_Head;
        if ( v4 == 0xFFFF )
          m_FirstFree = v9->m_FirstFree;
        else
          m_FirstFree = v4;
        this = v9;
        HIWORD(v5[1].m_s0) = m_FirstFree;
        m_Head = v4;
      }
      while ( v4 != 0xFFFF );
    }
    v8 = this->m_Head;
    if ( v8 != 0xFFFF )
      this->m_FirstFree = v8;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012C60
// Name: public: virtual int CTextureDictionary::CreateTexture(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureDictionary::CreateTexture(CTextureDictionary *this, bool procedural)
{
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *p_m_Textures; // esi
  int v3; // edi
  int result; // eax
  int v5; // ecx

  p_m_Textures = &this->m_Textures;
  v3 = (unsigned __int16)CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal(
                           this: &this->m_Textures,
                           multilist: false);
  LOWORD(result) = -1;
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_Textures,
      before: 0xFFFFu,
      elem: v3);
    Construct<CMatSystemTexture>(pMemory: &p_m_Textures->m_Memory.m_pMemory[v3].m_Element);
    LOWORD(result) = v3;
  }
  result = (unsigned __int16)result;
  v5 = (int)&p_m_Textures->m_Memory.m_pMemory[(unsigned __int16)result];
  *(_DWORD *)(v5 + 48) = (unsigned __int16)result;
  if ( procedural )
    *(_DWORD *)(v5 + 52) |= 1u;
  else
    *(_DWORD *)(v5 + 52) &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012CC0
// Name: public: virtual void CTextureDictionary::DestroyAllTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::DestroyAllTextures(CTextureDictionary *this)
{
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *p_m_Textures; // esi
  unsigned __int16 v2; // ax
  int v3; // edi

  p_m_Textures = &this->m_Textures;
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Textures);
  v2 = CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal(
         this: p_m_Textures,
         multilist: false);
  v3 = v2;
  if ( v2 != 0xFFFF )
  {
    CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_Textures,
      before: 0xFFFFu,
      elem: v2);
    Construct<CMatSystemTexture>(pMemory: &p_m_Textures->m_Memory.m_pMemory[v3].m_Element);
  }
  p_m_Textures->m_Memory.m_pMemory->m_Element.m_ID = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012D20
// Name: public: CTextureDictionary::CTextureDictionary(void)
// Source: json
//------------------------------------------------------------------------------
CTextureDictionary *__thiscall CTextureDictionary::CTextureDictionary(CTextureDictionary *this)
{
  unsigned __int16 v2; // ax
  int v3; // ebx

  this->__vftable = (CTextureDictionary_vtbl *)&CTextureDictionary::`vftable';
  this->m_Textures.m_Memory.m_pMemory = nullptr;
  this->m_Textures.m_Memory.m_nAllocationCount = 0;
  this->m_Textures.m_Memory.m_nGrowSize = 0;
  this->m_Textures.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Textures.m_FirstFree = 0xFFFF;
  this->m_Textures.m_pElements = this->m_Textures.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Textures.m_Head = -1;
  this->m_Textures.m_NumAlloced = 0;
  this->m_TextureIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_TextureIDs.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_TextureIDs.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_TextureIDs.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_TextureIDs.m_Elements.m_Tree.m_Root = -1;
  this->m_TextureIDs.m_Elements.m_Tree.m_NumElements = 0;
  this->m_TextureIDs.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_TextureIDs.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_TextureIDs.m_Elements.m_Tree.m_pElements = this->m_TextureIDs.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_TextureIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_TextureIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  v2 = CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_Textures,
         multilist: false);
  v3 = v2;
  if ( v2 != 0xFFFF )
  {
    CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_Textures,
      before: 0xFFFFu,
      elem: v2);
    Construct<CMatSystemTexture>(pMemory: &this->m_Textures.m_Memory.m_pMemory[v3].m_Element);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012DC0
// Name: public: virtual void CTextureDictionary::DestroyTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::DestroyTexture(CTextureDictionary *this, int id)
{
  unsigned __int16 v2; // bx
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *p_m_Textures; // edi
  bool v4; // zf
  CMatSystemTexture *v5; // esi
  const ResourceBinding_t<CTextureBits> *m_pBinding; // eax
  int ida; // [esp+Ch] [ebp+8h]

  v2 = id;
  if ( id != -1 )
  {
    p_m_Textures = &this->m_Textures;
    if ( (unsigned __int16)id < this->m_Textures.m_Memory.m_nAllocationCount
      && (unsigned __int16)id <= this->m_Textures.m_LastAlloc.index )
    {
      v4 = p_m_Textures->m_Memory.m_pMemory[(unsigned __int16)id].m_Previous == (unsigned __int16)id;
      ida = (unsigned __int16)id << 6;
      if ( !v4 )
      {
        CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::Unlink(
          this: p_m_Textures,
          elem: v2);
        v5 = (CMatSystemTexture *)((char *)&p_m_Textures->m_Memory.m_pMemory->m_Element + ida);
        CMatSystemTexture::CleanUpMaterial(this: v5);
        m_pBinding = v5->m_Texture2.m_pBinding;
        if ( m_pBinding != nullptr )
        {
          _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
          v5->m_Texture2.m_pBinding = nullptr;
        }
        HIWORD(v5[1].m_s0) = p_m_Textures->m_FirstFree;
        p_m_Textures->m_FirstFree = v2;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C980
// Name: public: virtual bool ITextureRegenerator::HasPreallocatedScratchTexture(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ITextureRegenerator::HasPreallocatedScratchTexture(vgui::ToggleButton *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10068C50
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006BE10
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1006BF80
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x1006E2A0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E320
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E940
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F750
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006F7C0
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006FC60
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071070
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x10072840
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073DF0
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x10074430
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x10076AD0
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10088730
// Name: public: virtual void CTextureDictionary::BindTextureToMaterial2Reference(int,int,class IMaterial2 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::BindTextureToMaterial2Reference(vgui::TreeView *this, int itemIndex, int x, int y)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10089F90
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x1008A3E0
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D7F0
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x1009D920
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB700
// Name: _GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_0.m_PanelMessageMapPool);
  CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::RemoveAll(this: &dictionary_0.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_0.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100BB740
// Name: _GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CClassMemoryPool<PanelAnimationMap>::Clear(this: &dictionary_1.m_PanelAnimationMapPool);
  CUtlDict<CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::RemoveAll(this: &dictionary_1.m_AnimationMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_1.m_AnimationMaps.m_Elements.m_Tree);
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_1.m_PanelAnimationMapPool);
}

//------------------------------------------------------------------------------
// Address: 0x100BB720
// Name: _dynamic_atexit_destructor_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KBMgr__()
{
  CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>(this: &g_KBMgr.m_Bindings);
}

//------------------------------------------------------------------------------
// Address: 0x100BB730
// Name: _dynamic_atexit_destructor_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ScriptSymbols);
}

//------------------------------------------------------------------------------
// Address: 0x100BB770
// Name: _dynamic_atexit_destructor_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ButtonSoundNames);
}

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004241A0
// Name: public: virtual class IMaterial2 __near * CTextureDictionary::GetTextureMaterial2(int)
// Source: json
//------------------------------------------------------------------------------
struct IMaterial2 *__thiscall CTextureDictionary::GetTextureMaterial2(CTextureDictionary *this, int id)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004A2810
// Name: public: virtual void CTextureDictionary::BindTextureToMaterial2(int,class IMaterial2 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::BindTextureToMaterial2(
        CTextureDictionary *this,
        int id,
        struct IMaterial2 *pMaterial)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004BD280
// Name: public: void CFontTextureRegen::UpdateBackingBits(struct Rect_t __near &,unsigned char const __near *,struct Rect_t __near &,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureRegen::UpdateBackingBits(
        CFontTextureRegen *this,
        Rect_t *subRect,
        const unsigned __int8 *pBits,
        Rect_t *uploadRect,
        ImageFormat format)
{
  int MemRequired; // edi
  int i; // ebx
  int v8; // edx
  int width; // eax
  int v10; // ecx
  int v11; // eax

  MemRequired = ImageLoader::GetMemRequired(
                  width: this->m_nWidth,
                  height: this->m_nHeight,
                  depth: 1,
                  imageFormat: this->m_nFormat,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  if ( this->m_pTextureBits != nullptr )
  {
    if ( ImageLoader::ImageFormatInfo(fmt: this->m_nFormat)->m_nNumBytes == 4 )
    {
      for ( i = 0; i < subRect->height; ++i )
      {
        v8 = subRect->y + i;
        width = uploadRect->width;
        v10 = subRect->width;
        if ( v10 == width )
          v11 = i * width;
        else
          v11 = subRect->x + v8 * width;
        ImageLoader::ConvertImageFormat(
          src: &pBits[4 * v11],
          srcImageFormat: format,
          dst: &this->m_pTextureBits[4 * subRect->x + 4 * v8 * this->m_nWidth],
          dstImageFormat: this->m_nFormat,
          width: v10,
          height: 1,
          srcStride: 0,
          dstStride: 0);
      }
    }
    else if ( subRect->width == this->m_nWidth && subRect->height == this->m_nHeight )
    {
      _V_memcpy(dest: this->m_pTextureBits, src: pBits, count: MemRequired);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BD370
// Name: public: void CMatSystemTexture::SetSubTextureRGBAEx(int,int,unsigned char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::SetSubTextureRGBAEx(
        CMatSystemTexture *this,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall,
        ImageFormat format)
{
  ITexture *m_pTexture; // esi
  int v8; // eax
  int v9; // eax
  CFontTextureRegen *m_pRegen; // ecx
  Rect_t subRect; // [esp+0h] [ebp-24h] BYREF
  Rect_t textureSize; // [esp+10h] [ebp-14h] BYREF
  int v13; // [esp+20h] [ebp-4h]

  if ( this->m_pMaterial != nullptr )
  {
    m_pTexture = this->m_pTexture;
    if ( m_pTexture != nullptr && (this->m_Flags & 1) != 0 )
    {
      v8 = this->m_iWide - drawX;
      subRect.y = drawX;
      subRect.width = drawY;
      subRect.height = subTextureWide;
      if ( subTextureWide >= v8 )
        subRect.height = v8;
      v9 = this->m_iTall - drawY;
      textureSize.x = subTextureTall;
      if ( subTextureTall >= v9 )
        textureSize.x = v9;
      m_pRegen = this->m_pRegen;
      v13 = subTextureTall;
      textureSize.y = 0;
      textureSize.width = 0;
      textureSize.height = subTextureWide;
      CFontTextureRegen::UpdateBackingBits(
        this: m_pRegen,
        subRect: (Rect_t *)&subRect.y,
        pBits: rgba,
        uploadRect: (Rect_t *)&textureSize.y,
        format);
      m_pTexture->Download(this: m_pTexture, a2: (Rect_t *)&subRect.y, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BD420
// Name: public: void CMatSystemTexture::UpdateSubTextureRGBA(int,int,unsigned char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::UpdateSubTextureRGBA(
        CMatSystemTexture *this,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall,
        ImageFormat imageFormat)
{
  ITexture *m_pTexture; // esi
  int m_iInputWide; // eax
  int m_iInputTall; // edx
  CFontTextureRegen *m_pRegen; // ecx
  Rect_t subRect; // [esp+0h] [ebp-24h] BYREF
  Rect_t textureSize; // [esp+10h] [ebp-14h] BYREF
  int v13; // [esp+20h] [ebp-4h]

  if ( this->m_pMaterial != nullptr )
  {
    m_pTexture = this->m_pTexture;
    if ( m_pTexture != nullptr && (this->m_Flags & 1) != 0 )
    {
      subRect.y = drawX;
      subRect.width = drawY;
      subRect.height = subTextureWide;
      m_iInputWide = this->m_iInputWide;
      textureSize.x = subTextureTall;
      m_iInputTall = this->m_iInputTall;
      m_pRegen = this->m_pRegen;
      textureSize.height = m_iInputWide;
      v13 = m_iInputTall;
      textureSize.y = 0;
      textureSize.width = 0;
      CFontTextureRegen::UpdateBackingBits(
        this: m_pRegen,
        subRect: (Rect_t *)&subRect.y,
        pBits: rgba,
        uploadRect: (Rect_t *)&textureSize.y,
        format: imageFormat);
      m_pTexture->Download(this: m_pTexture, a2: (Rect_t *)&subRect.y, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BD4B0
// Name: class ITextureDictionary __near * TextureDictionary(void)
// Source: json
//------------------------------------------------------------------------------
CTextureDictionary *__cdecl TextureDictionary()
{
  return &s_TextureDictionary;
}

//------------------------------------------------------------------------------
// Address: 0x004BD4C0
// Name: public: virtual void CTextureDictionary::SetTextureRGBA(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::SetTextureRGBA(
        CTextureDictionary *this,
        int id,
        const char *rgba,
        int wide,
        int tall)
{
  this->SetTextureRGBAEx(this, a2: id, a3: rgba, a4: wide, a5: tall, a6: IMAGE_FORMAT_RGBA8888);
}

//------------------------------------------------------------------------------
// Address: 0x004BD4E0
// Name: public: virtual void CTextureDictionary::SetSubTextureRGBA(int,int,int,unsigned char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::SetSubTextureRGBA(
        CTextureDictionary *this,
        int id,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall)
{
  this->SetSubTextureRGBAEx(
    this,
    a2: id,
    a3: drawX,
    a4: drawY,
    a5: rgba,
    a6: subTextureWide,
    a7: subTextureTall,
    a8: IMAGE_FORMAT_RGBA8888);
}

//------------------------------------------------------------------------------
// Address: 0x004BD510
// Name: public: CFontTextureRegen::CFontTextureRegen(int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
CFontTextureRegen *__thiscall CFontTextureRegen::CFontTextureRegen(
        CFontTextureRegen *this,
        __int16 nWidth,
        __int16 nHeight,
        ImageFormat format)
{
  unsigned int MemRequired; // edi
  unsigned __int8 *v6; // eax

  this->m_nFormat = format;
  this->m_nWidth = nWidth;
  this->__vftable = (CFontTextureRegen_vtbl *)&CFontTextureRegen::`vftable';
  this->m_nHeight = nHeight;
  MemRequired = ImageLoader::GetMemRequired(
                  width: nWidth,
                  height: nHeight,
                  depth: 1,
                  imageFormat: format,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
  v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: MemRequired);
  this->m_pTextureBits = v6;
  memset(dst: (int)v6, value: nullptr, count: MemRequired);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BD570
// Name: public: virtual void CFontTextureRegen::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureRegen::RegenerateTextureBits(
        CFontTextureRegen *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pSubRect)
{
  int v6; // ebx
  int MemRequired; // eax
  unsigned __int16 v8; // bx
  ImageFormat v9; // eax
  ImageFormat v10; // esi
  __int16 v11; // bp
  char v12; // al
  Rect_t *v13; // ecx
  int v14; // edx
  int v15; // ebx
  unsigned __int8 *v16; // esi
  unsigned __int8 *v17; // edi
  unsigned int v18; // edx
  unsigned int v19; // edx
  int v20; // eax
  unsigned __int64 v21; // rdi
  __int64 v22; // rax
  unsigned __int64 v23; // rdi
  bool v24; // zf
  int m_nWidth; // ecx
  int m_nHeight; // eax
  unsigned __int8 *v27; // eax
  unsigned __int8 *m_pTextureBits; // [esp+0h] [ebp-60h]
  int v29; // [esp+4h] [ebp-5Ch]
  int y; // [esp+14h] [ebp-4Ch]
  int ymax; // [esp+18h] [ebp-48h]
  int i; // [esp+1Ch] [ebp-44h]
  int v33; // [esp+1Ch] [ebp-44h]
  unsigned __int8 *v34; // [esp+20h] [ebp-40h]
  int v36; // [esp+28h] [ebp-38h]
  int v37; // [esp+2Ch] [ebp-34h]
  int v38; // [esp+30h] [ebp-30h]
  unsigned __int64 *pixelWriter_8; // [esp+40h] [ebp-20h]
  unsigned __int8 pixelWriter_14; // [esp+46h] [ebp-1Ah]
  char pixelWriter_16; // [esp+48h] [ebp-18h]
  char pixelWriter_18; // [esp+4Ah] [ebp-16h]
  char pixelWriter_22; // [esp+4Eh] [ebp-12h]
  char pixelWriter_24; // [esp+50h] [ebp-10h]
  char pixelWriter_28; // [esp+54h] [ebp-Ch]
  char pixelWriter_32; // [esp+58h] [ebp-8h]
  char v47; // [esp+5Ch] [ebp-4h]
  unsigned __int8 *rgbaa; // [esp+68h] [ebp+8h]
  unsigned __int8 *rgba; // [esp+68h] [ebp+8h]

  if ( this->m_pTextureBits != nullptr )
  {
    if ( ImageLoader::ImageFormatInfo(fmt: this->m_nFormat)->m_nNumBytes == 4 )
    {
      if ( this->m_nFormat == pVTFTexture->Format(this: pVTFTexture) )
      {
        v6 = pSubRect->y;
        for ( i = v6 + pSubRect->height; v6 < i; ++v6 )
        {
          rgbaa = &pVTFTexture->ImageData(this: pVTFTexture, a2: 0, a3: 0, a4: 0, a5: 0, a6: v6, a7: 0)[4 * pSubRect->x];
          MemRequired = ImageLoader::GetMemRequired(
                          width: pSubRect->width,
                          height: 1,
                          depth: 1,
                          imageFormat: this->m_nFormat,
                          mipmap: false,
                          pAdjustedHeight: nullptr);
          _V_memcpy(
            dest: rgbaa,
            src: &this->m_pTextureBits[4 * pSubRect->x + 4 * v6 * this->m_nWidth],
            count: MemRequired);
        }
      }
      else
      {
        v8 = pVTFTexture->RowSizeInBytes(this: pVTFTexture, a2: 0);
        v34 = pVTFTexture->ImageData_2(this: pVTFTexture, a2: 0, a3: 0, a4: 0);
        v9 = pVTFTexture->Format(this: pVTFTexture);
        v10 = v9;
        switch ( v9 )
        {
          case IMAGE_FORMAT_RGBA8888:
          case IMAGE_FORMAT_UVWQ8888:
            pixelWriter_14 = 4;
            pixelWriter_18 = 8;
            v11 = 16;
            pixelWriter_22 = 24;
            goto LABEL_10;
          case IMAGE_FORMAT_BGR888:
            pixelWriter_14 = 3;
            pixelWriter_22 = 0;
            goto LABEL_16;
          case IMAGE_FORMAT_I8:
            pixelWriter_14 = 1;
            goto LABEL_26;
          case IMAGE_FORMAT_A8:
            pixelWriter_14 = 1;
            pixelWriter_24 = 0;
            v47 = -1;
            goto LABEL_28;
          case IMAGE_FORMAT_BGRA8888:
            pixelWriter_14 = 4;
            pixelWriter_16 = 16;
            pixelWriter_18 = 8;
            v11 = 0;
            pixelWriter_22 = 24;
            v12 = -1;
            goto LABEL_14;
          case IMAGE_FORMAT_BGRX8888:
            pixelWriter_14 = 4;
            pixelWriter_22 = 24;
LABEL_16:
            v11 = 0;
            pixelWriter_18 = 8;
            pixelWriter_16 = 16;
            pixelWriter_28 = -1;
            pixelWriter_24 = -1;
            pixelWriter_32 = -1;
            v47 = 0;
            goto LABEL_30;
          case IMAGE_FORMAT_BGR565:
            pixelWriter_14 = 2;
            pixelWriter_16 = 8;
            pixelWriter_18 = 3;
            v11 = -3;
            pixelWriter_22 = 0;
            pixelWriter_28 = -4;
            pixelWriter_24 = -8;
            pixelWriter_32 = -8;
            v47 = 0;
            goto LABEL_30;
          case IMAGE_FORMAT_BGRX5551:
          case IMAGE_FORMAT_BGRA5551:
            pixelWriter_14 = 2;
            pixelWriter_16 = 7;
            pixelWriter_18 = 2;
            v11 = -3;
            pixelWriter_22 = 8;
            pixelWriter_24 = -8;
            pixelWriter_28 = -8;
            pixelWriter_32 = -8;
            v47 = 0x80;
            goto LABEL_30;
          case IMAGE_FORMAT_BGRA4444:
            pixelWriter_14 = 2;
            pixelWriter_16 = 4;
            pixelWriter_18 = 0;
            v11 = -4;
            pixelWriter_22 = 8;
            v12 = -16;
LABEL_14:
            pixelWriter_24 = v12;
            pixelWriter_28 = v12;
            pixelWriter_32 = v12;
            v47 = v12;
            goto LABEL_30;
          case IMAGE_FORMAT_RGBA16161616F:
          case IMAGE_FORMAT_RGBA16161616:
            pixelWriter_14 = 8;
            pixelWriter_18 = 16;
            v11 = 32;
            pixelWriter_22 = 48;
            goto LABEL_10;
          case IMAGE_FORMAT_R32F:
            pixelWriter_14 = 4;
            pixelWriter_24 = -1;
            goto LABEL_27;
          case IMAGE_FORMAT_RGBA32323232F:
            pixelWriter_14 = 16;
            pixelWriter_18 = 32;
            v11 = 64;
            pixelWriter_22 = 96;
LABEL_10:
            pixelWriter_24 = -1;
            pixelWriter_28 = -1;
            pixelWriter_32 = -1;
            v47 = -1;
            break;
          default:
            if ( `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v9] == 0 )
            {
              _Msg(a1: "CPixelWriter::SetPixelMemory:  Unsupported image format %i\n", v9);
              `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v10] = 1;
            }
            pixelWriter_14 = 0;
LABEL_26:
            pixelWriter_24 = -1;
LABEL_27:
            v47 = 0;
LABEL_28:
            v11 = 0;
            pixelWriter_32 = 0;
            pixelWriter_28 = 0;
            pixelWriter_22 = 0;
            pixelWriter_18 = 0;
            break;
        }
        pixelWriter_16 = 0;
LABEL_30:
        v13 = pSubRect;
        v36 = pSubRect->x + pSubRect->width;
        v14 = pSubRect->y;
        v38 = v14 + pSubRect->height;
        ymax = v14;
        if ( v14 < v38 )
        {
          v37 = v8;
          v15 = v14 * v8;
          v33 = v15;
          while ( 1 )
          {
            v16 = &v34[v15 + v13->x * pixelWriter_14];
            v17 = &this->m_pTextureBits[4 * v13->x + 4 * v14 * this->m_nWidth];
            pixelWriter_8 = (unsigned __int64 *)v16;
            rgba = v17;
            if ( v13->x < v36 )
            {
              y = v36 - v13->x;
              do
              {
                if ( pixelWriter_14 != 0 )
                {
                  if ( pixelWriter_14 >= 5u )
                  {
                    v21 = ((unsigned __int64)(unsigned __int8)(v17[1] & pixelWriter_28) << pixelWriter_18)
                        | ((unsigned __int64)(unsigned __int8)(*v17 & pixelWriter_24) << pixelWriter_16);
                    if ( v11 <= 0 )
                      v22 = (__int64)(unsigned __int8)(rgba[2] & pixelWriter_32) >> -(char)v11;
                    else
                      v22 = (unsigned __int64)(unsigned __int8)(rgba[2] & pixelWriter_32) << v11;
                    v23 = v22 | ((unsigned __int64)(unsigned __int8)(rgba[3] & v47) << pixelWriter_22) | v21;
                    if ( pixelWriter_14 == 8 )
                      *pixelWriter_8 = v23;
                    v17 = rgba;
                    v16 = (unsigned __int8 *)pixelWriter_8;
                  }
                  else
                  {
                    v18 = (unsigned __int8)(v17[2] & pixelWriter_32);
                    if ( v11 <= 0 )
                      v19 = v18 >> -(char)v11;
                    else
                      v19 = v18 << v11;
                    v20 = v19
                        | ((unsigned __int8)(v17[3] & v47) << pixelWriter_22)
                        | ((unsigned __int8)(v17[1] & pixelWriter_28) << pixelWriter_18)
                        | ((unsigned __int8)(*v17 & pixelWriter_24) << pixelWriter_16);
                    switch ( pixelWriter_14 )
                    {
                      case 1u:
                        *v16 = v20;
                        break;
                      case 2u:
                        *(_WORD *)v16 = v20;
                        break;
                      case 3u:
                        *(_WORD *)v16 = v20;
                        v16[2] = BYTE2(v20);
                        break;
                      case 4u:
                        *(_DWORD *)v16 = v20;
                        break;
                    }
                  }
                }
                v16 += pixelWriter_14;
                v17 += 4;
                v24 = y-- == 1;
                pixelWriter_8 = (unsigned __int64 *)v16;
                rgba = v17;
              }
              while ( !v24 );
              v14 = ymax;
              v15 = v33;
            }
            v15 += v37;
            ymax = ++v14;
            v33 = v15;
            if ( v14 >= v38 )
              break;
            v13 = pSubRect;
          }
        }
      }
    }
    else
    {
      m_nWidth = this->m_nWidth;
      if ( pSubRect->width == m_nWidth )
      {
        m_nHeight = this->m_nHeight;
        if ( pSubRect->height == m_nHeight )
        {
          v29 = ImageLoader::GetMemRequired(
                  width: m_nWidth,
                  height: m_nHeight,
                  depth: 1,
                  imageFormat: this->m_nFormat,
                  mipmap: false,
                  pAdjustedHeight: nullptr);
          m_pTextureBits = this->m_pTextureBits;
          v27 = pVTFTexture->ImageData_2(this: pVTFTexture, a2: 0, a3: 0, a4: 0);
          _V_memcpy(dest: v27, src: m_pTextureBits, count: v29);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BDB60
// Name: public: virtual void CFontTextureRegen::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFontTextureRegen::Release(CFontTextureRegen *this)
{
  if ( this->m_pTextureBits != nullptr )
  {
    free(pMem: this->m_pTextureBits);
    this->m_pTextureBits = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BDB80
// Name: private: void CMatSystemTexture::CreateRegen(int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::CreateRegen(
        CMatSystemTexture *this,
        __int16 nWidth,
        __int16 nHeight,
        ImageFormat format)
{
  CFontTextureRegen *v5; // eax

  if ( this->m_pRegen == nullptr )
  {
    v5 = (CFontTextureRegen *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v5 != nullptr )
      this->m_pRegen = CFontTextureRegen::CFontTextureRegen(this: v5, nWidth, nHeight, format);
    else
      this->m_pRegen = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BDBC0
// Name: public: void CMatSystemTexture::SetSubTextureRGBA(class IRenderDevice __near *,int,int,unsigned char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::SetSubTextureRGBA(
        CMatSystemTexture *this,
        IRenderDevice *pRenderDevice,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall)
{
  IRenderContext *v8; // esi
  const ResourceBinding_t<CTextureBits> *m_pBinding; // edx
  Rect_t myRect; // [esp+Ch] [ebp-14h] BYREF
  int v11; // [esp+1Ch] [ebp-4h]

  v8 = pRenderDevice->GetRenderContext(this: pRenderDevice);
  v8->BindRenderTargets(this: v8, a2: (RenderTargetBinding_t__ *)-1);
  m_pBinding = this->m_Texture2.m_pBinding;
  myRect.y = drawX;
  myRect.width = drawY;
  myRect.height = subTextureWide;
  v11 = subTextureTall;
  m_pBinding->m_nLastBindFrame = g_nResourceFrameCount;
  v8->SetTextureData(
    this: v8,
    a2: this->m_Texture2.m_pBinding,
    a3: nullptr,
    a4: rgba,
    a5: 4 * subTextureTall * subTextureWide,
    a6: false,
    a7: 0,
    a8: (const Rect_t *)&myRect.y);
  v8->Submit(this: v8);
  pRenderDevice->ReleaseRenderContext(this: pRenderDevice, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x004BDD00
// Name: public: virtual void CTextureDictionary::SetSubTextureRGBAEx(int,int,int,unsigned char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::SetSubTextureRGBAEx(
        CTextureDictionary *this,
        int id,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall,
        ImageFormat format)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v9; // ecx

  if ( this->IsValidId(this, a2: id) )
  {
    v9 = &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id];
    if ( g_pMaterialSystem != nullptr )
      CMatSystemTexture::SetSubTextureRGBAEx(
        this: &v9->m_Element,
        drawX,
        drawY,
        rgba,
        subTextureWide,
        subTextureTall,
        format);
    else
      CMatSystemTexture::SetSubTextureRGBA(
        this: &v9->m_Element,
        pRenderDevice: g_pRenderDevice,
        drawX,
        drawY,
        rgba,
        subTextureWide,
        subTextureTall);
  }
  else
  {
    _Msg(a1: "SetSubTextureRGBA: Invalid texture id %i\n", id);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BDD90
// Name: public: virtual void CTextureDictionary::UpdateSubTextureRGBA(int,int,int,unsigned char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::UpdateSubTextureRGBA(
        CTextureDictionary *this,
        int id,
        int drawX,
        int drawY,
        const unsigned __int8 *rgba,
        int subTextureWide,
        int subTextureTall,
        ImageFormat imageFormat)
{
  if ( this->IsValidId(this, a2: id) )
    CMatSystemTexture::UpdateSubTextureRGBA(
      this: &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id].m_Element,
      drawX,
      drawY,
      rgba,
      subTextureWide,
      subTextureTall,
      imageFormat);
  else
    _Msg(a1: "UpdateSubTextureRGBA: Invalid texture id %i\n", id);
}

//------------------------------------------------------------------------------
// Address: 0x004BDDF0
// Name: public: virtual bool CTextureDictionary::IsValidId(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTextureDictionary::IsValidId(CTextureDictionary *this, int id)
{
  bool result; // al
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v3; // eax

  result = false;
  if ( id != 0
    && (unsigned __int16)id < this->m_Textures.m_Memory.m_nAllocationCount
    && (unsigned __int16)id <= this->m_Textures.m_LastAlloc.index )
  {
    v3 = &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id];
    if ( v3->m_Previous != (_WORD)id || v3->m_Next == (_WORD)id )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BDE30
// Name: public: virtual class IMaterial __near * CTextureDictionary::GetTextureMaterial(int)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CTextureDictionary::GetTextureMaterial(CTextureDictionary *this, int id)
{
  if ( this->IsValidId(this, a2: id) )
    return this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id].m_Element.m_pMaterial;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004BDE60
// Name: public: virtual struct ResourceBinding_t<class CTextureBits> const __near * CTextureDictionary::GetTextureHandle(int)
// Source: rtti_class
//------------------------------------------------------------------------------
const ResourceBinding_t<CTextureBits> *__thiscall CTextureDictionary::GetTextureHandle(
        CTextureDictionary *this,
        int id)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *m_pMemory; // ecx
  int v5; // eax

  if ( !this->IsValidId(this, a2: id) )
    return nullptr;
  m_pMemory = this->m_Textures.m_Memory.m_pMemory;
  v5 = (unsigned __int16)id << 6;
  (*(const ResourceBinding_t<CTextureBits> **)((char *)&m_pMemory->m_Element.m_Texture2.m_pBinding + v5))->m_nLastBindFrame = g_nResourceFrameCount;
  return *(const ResourceBinding_t<CTextureBits> **)((char *)&m_pMemory->m_Element.m_Texture2.m_pBinding + v5);
}

//------------------------------------------------------------------------------
// Address: 0x004BDEA0
// Name: public: virtual void CTextureDictionary::GetTextureSize(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::GetTextureSize(CTextureDictionary *this, int id, int *iWide, int *iTall)
{
  int v5; // eax

  if ( this->IsValidId(this, a2: id) )
  {
    v5 = (unsigned __int16)id << 6;
    *iWide = *(int *)((char *)&this->m_Textures.m_Memory.m_pMemory->m_Element.m_iWide + v5);
    *iTall = *(int *)((char *)&this->m_Textures.m_Memory.m_pMemory->m_Element.m_iTall + v5);
  }
  else
  {
    *iTall = 0;
    *iWide = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BDF00
// Name: public: virtual void CTextureDictionary::GetTextureTexCoords(int,float __near &,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::GetTextureTexCoords(
        CTextureDictionary *this,
        int id,
        float *s0,
        float *t0,
        float *s1,
        float *t1)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v7; // eax

  if ( this->IsValidId(this, a2: id) )
  {
    v7 = &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id];
    *s0 = v7->m_Element.m_s0;
    *t0 = v7->m_Element.m_t0;
    *s1 = v7->m_Element.m_s1;
    *t1 = v7->m_Element.m_t1;
  }
  else
  {
    *t0 = 0.0;
    *s0 = 0.0;
    *t1 = 1.0;
    *s1 = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BE0F0
// Name: private: void CMatSystemTexture::CleanUpMaterial(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::CleanUpMaterial(CMatSystemTexture *this)
{
  IMaterial *m_pMaterial; // ecx
  ITexture *m_pTexture; // ecx
  CFontTextureRegen *m_pRegen; // edi
  unsigned __int8 *m_pTextureBits; // eax

  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr )
  {
    m_pMaterial->DecrementReferenceCount(this: m_pMaterial);
    this->m_pMaterial->DeleteIfUnreferenced(this: this->m_pMaterial);
    this->m_pMaterial = nullptr;
  }
  m_pTexture = this->m_pTexture;
  if ( m_pTexture != nullptr )
  {
    m_pTexture->SetTextureRegenerator(this: m_pTexture, a2: nullptr, a3: true);
    this->m_pTexture->DecrementReferenceCount(this: this->m_pTexture);
    this->m_pTexture->DeleteIfUnreferenced(this: this->m_pTexture);
    this->m_pTexture = nullptr;
  }
  m_pRegen = this->m_pRegen;
  if ( m_pRegen != nullptr )
  {
    if ( (this->m_Flags & 2) == 0 )
    {
      m_pTextureBits = m_pRegen->m_pTextureBits;
      m_pRegen->__vftable = (CFontTextureRegen_vtbl *)&CFontTextureRegen::`vftable';
      if ( m_pTextureBits != nullptr )
      {
        free(pMem: m_pTextureBits);
        m_pRegen->m_pTextureBits = nullptr;
      }
      free(pMem: m_pRegen);
    }
    this->m_pRegen = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BE180
// Name: public: void CMatSystemTexture::SetMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::SetMaterial(CMatSystemTexture *this, IMaterial *pMaterial)
{
  IMaterial *v3; // ecx
  bool v4; // zf
  int v5; // eax
  IMaterial *m_pMaterial; // ecx
  int v7; // eax
  float v8; // xmm0_4
  float m_iWide; // xmm2_4
  float v10; // xmm1_4
  IMaterialVar *v11; // eax
  IMaterialVar *v12; // edi
  ITexture *v13; // eax
  ImageFormat v14; // eax

  if ( g_pMaterialSystem != nullptr )
  {
    CMatSystemTexture::CleanUpMaterial(this);
    v3 = pMaterial;
    v4 = pMaterial == nullptr;
    this->m_pMaterial = pMaterial;
    if ( v4 )
    {
      this->m_t0 = 0.0;
      this->m_s0 = 0.0;
      this->m_iTall = (int)v3;
      this->m_iWide = (int)v3;
      this->m_t1 = 1.0;
      this->m_s1 = 1.0;
    }
    else
    {
      v3->IncrementReferenceCount(this: v3);
      v5 = this->m_pMaterial->GetMappingWidth(this: this->m_pMaterial);
      m_pMaterial = this->m_pMaterial;
      this->m_iWide = v5;
      v7 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v8 = 0.0;
      m_iWide = (float)this->m_iWide;
      this->m_iTall = v7;
      v10 = 0.0;
      if ( m_iWide > 0.0 && (float)v7 > 0.0 )
      {
        v8 = 0.5 / m_iWide;
        v10 = 0.5 / (float)v7;
      }
      v4 = (this->m_Flags & 1) == 0;
      this->m_s0 = v8;
      this->m_t0 = v10;
      this->m_s1 = 1.0 - v8;
      this->m_t1 = 1.0 - v10;
      if ( !v4 )
      {
        v11 = this->m_pMaterial->FindVar(this: this->m_pMaterial, a2: "$baseTexture", a3: &pMaterial, a4: 1);
        v12 = v11;
        if ( (_BYTE)pMaterial != 0 && v11->IsDefined(this: v11) )
        {
          v13 = (ITexture *)v12->GetTextureValue(this: v12);
          this->m_pTexture = v13;
          if ( v13 != nullptr )
          {
            v13->IncrementReferenceCount(this: v13);
            v14 = this->m_pTexture->GetImageFormat(this: this->m_pTexture);
            CMatSystemTexture::CreateRegen(this, nWidth: this->m_iWide, nHeight: this->m_iTall, format: v14);
            this->m_pTexture->SetTextureRegenerator(this: this->m_pTexture, a2: this->m_pRegen, a3: true);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BE2C0
// Name: public: void CMatSystemTexture::ReferenceOtherProcedural(class CMatSystemTexture __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::ReferenceOtherProcedural(
        CMatSystemTexture *this,
        CMatSystemTexture *pTexture,
        IMaterial *pMaterial)
{
  IMaterialVar *v4; // eax
  ITexture *v5; // eax
  char v6; // [esp+Dh] [ebp-1h] BYREF

  CMatSystemTexture::CleanUpMaterial(this);
  this->m_Flags |= 2u;
  this->m_pMaterial = pMaterial;
  if ( pMaterial != nullptr )
  {
    this->m_iWide = pTexture->m_iWide;
    this->m_iTall = pTexture->m_iTall;
    this->m_s0 = pTexture->m_s0;
    this->m_t0 = pTexture->m_t0;
    this->m_s1 = pTexture->m_s1;
    this->m_t1 = pTexture->m_t1;
    pMaterial->IncrementReferenceCount(this: pMaterial);
    v4 = this->m_pMaterial->FindVar(this: this->m_pMaterial, a2: "$baseTexture", a3: &v6, a4: 1);
    if ( v6 != 0 )
    {
      v5 = (ITexture *)v4->GetTextureValue(this: v4);
      this->m_pTexture = v5;
      if ( v5 != nullptr )
      {
        v5->IncrementReferenceCount(this: v5);
        this->m_pRegen = pTexture->m_pRegen;
      }
    }
  }
  else
  {
    this->m_t0 = 0.0;
    this->m_s0 = 0.0;
    this->m_iTall = 0;
    this->m_iWide = 0;
    this->m_t1 = 1.0;
    this->m_s1 = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BE370
// Name: public: void CMatSystemTexture::SetMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::SetMaterial(CMatSystemTexture *this, const char *pFileName)
{
  IMaterial *v3; // esi

  v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: pFileName, a3: "VGUI textures", a4: 1, a5: 0);
  if ( v3 == nullptr || v3->IsErrorMaterial(this: v3) )
    _Msg(a1: "--- Missing Vgui material %s\n", pFileName);
  CMatSystemTexture::SetMaterial(this, pMaterial: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004BE3D0
// Name: public: virtual void CTextureDictionary::BindTextureToFile(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::BindTextureToFile(CTextureDictionary *this, int id, const char *pFileName)
{
  unsigned __int16 v3; // si
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v5; // esi
  const char *v6; // edi

  v3 = id;
  if ( this->IsValidId(this, a2: id) )
  {
    v5 = &this->m_Textures.m_Memory.m_pMemory[v3];
    CRC32_Init(pulCRC: (unsigned int *)&id);
    v6 = pFileName;
    CRC32_ProcessBuffer(pulCRC: (unsigned int *)&id, pBuffer: pFileName, nBuffer: strlen(pFileName));
    CRC32_Final(pulCRC: (unsigned int *)&id);
    if ( v5->m_Element.m_pMaterial == nullptr || id != v5->m_Element.m_crcFile )
    {
      v5->m_Element.m_crcFile = id;
      CMatSystemTexture::SetMaterial(this: &v5->m_Element, pFileName: v6);
    }
  }
  else
  {
    _Msg(a1: "BindTextureToFile: Invalid texture id for file %s\n", pFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BE470
// Name: public: virtual void CTextureDictionary::BindTextureToMaterial(int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::BindTextureToMaterial(CTextureDictionary *this, int id, IMaterial *pMaterial)
{
  if ( this->IsValidId(this, a2: id) )
    CMatSystemTexture::SetMaterial(
      this: &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id].m_Element,
      pMaterial);
  else
    _Msg(a1: "BindTextureToFile: Invalid texture id %d\n", id);
}

//------------------------------------------------------------------------------
// Address: 0x004BE4B0
// Name: public: virtual void CTextureDictionary::BindTextureToMaterialReference(int,int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::BindTextureToMaterialReference(
        CTextureDictionary *this,
        int id,
        int referenceId,
        IMaterial *pMaterial)
{
  if ( this->IsValidId(this, a2: id) && this->IsValidId(this, a2: referenceId) )
    CMatSystemTexture::ReferenceOtherProcedural(
      this: &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id].m_Element,
      pTexture: &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)referenceId].m_Element,
      pMaterial);
  else
    _Msg(a1: "BindTextureToFile: Invalid texture ids %d %d\n", id, referenceId);
}

//------------------------------------------------------------------------------
// Address: 0x004BE520
// Name: public: virtual int CTextureDictionary::FindTextureIdForTextureFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureDictionary::FindTextureIdForTextureFile(CTextureDictionary *this, const char *pFileName)
{
  int m_Head; // edi
  int v4; // esi
  char *v5; // eax
  int (__thiscall ***v6)(_DWORD); // eax
  const char *v7; // eax

  m_Head = this->m_Textures.m_Head;
  if ( m_Head == 0xFFFF )
    return -1;
  while ( 1 )
  {
    v4 = (unsigned __int16)m_Head << 6;
    v5 = (char *)this->m_Textures.m_Memory.m_pMemory + v4;
    if ( v5 != nullptr )
    {
      v6 = *((int (__thiscall ****)(_DWORD))v5 + 5);
      if ( v6 != nullptr )
      {
        v7 = (const char *)(**v6)(a1: v6);
        if ( _V_stricmp(s1: v7, s2: pFileName) == 0 )
          break;
      }
    }
    m_Head = *(unsigned __int16 *)((char *)&this->m_Textures.m_Memory.m_pMemory->m_Next + v4);
    if ( m_Head == 0xFFFF )
      return -1;
  }
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x004BE620
// Name: public: void CMatSystemTexture::SetTextureRGBA(char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMatSystemTexture::SetTextureRGBA(
        CMatSystemTexture *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const char *rgba,
        int wide,
        int tall,
        ImageFormat format)
{
  ITexture *(__thiscall *CreateProceduralTexture)(IMaterialSystem *, const char *, const char *, int, int, ImageFormat, int); // edx
  int v9; // ebx
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  IMaterial *v12; // esi
  char pTextureName[68]; // [esp+14h] [ebp-44h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    if ( this->m_pMaterial == nullptr )
    {
      V_snprintf(pDest: &pTextureName[4], maxLen: 64, pFormat: "__vgui_texture_%d", nTextureId);
      CreateProceduralTexture = g_pMaterialSystem->CreateProceduralTexture;
      ++nTextureId;
      v9 = ((int (__thiscall *)(IMaterialSystem *, char *, const char *, int, int, ImageFormat, int, int, int))CreateProceduralTexture)(
             a1: g_pMaterialSystem,
             a2: &pTextureName[4],
             a3: "VGUI textures",
             a4: wide,
             a5: tall,
             a6: format,
             a7: 789261,
             a8: a3,
             a9: a2);
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
        v11 = KeyValues::KeyValues(this: v10, setName: "UnlitGeneric");
      else
        v11 = nullptr;
      KeyValues::SetInt(this: v11, keyName: "$vertexcolor", value: 1);
      KeyValues::SetInt(this: v11, keyName: "$vertexalpha", value: 1);
      KeyValues::SetInt(this: v11, keyName: "$ignorez", value: 1);
      KeyValues::SetInt(this: v11, keyName: "$no_fullbright", value: 1);
      KeyValues::SetInt(this: v11, keyName: "$translucent", value: 1);
      KeyValues::SetString(this: v11, keyName: "$basetexture", value: &pTextureName[12]);
      v12 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: &pTextureName[12], a3: v11);
      v12->Refresh(this: v12);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 44))(a1: v9);
      CMatSystemTexture::SetMaterial(this, pMaterial: v12);
      this->m_iInputWide = wide;
      this->m_iInputTall = tall;
      v12->DecrementReferenceCount(this: v12);
    }
    CMatSystemTexture::SetSubTextureRGBAEx(
      this,
      drawX: 0,
      drawY: 0,
      (const unsigned __int8 *)rgba,
      subTextureWide: wide,
      subTextureTall: tall,
      format);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BE780
// Name: public: void CMatSystemTexture::SetTextureRGBA(class IRenderDevice __near *,char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatSystemTexture::SetTextureRGBA(
        CMatSystemTexture *this,
        IRenderDevice *pRenderDevice,
        const char *rgba,
        int width,
        int height,
        ImageFormat format)
{
  const ResourceBinding_t<CTextureBits> *v7; // eax
  const ResourceBinding_t<CTextureBits> *m_pBinding; // ecx
  char pResourceName[16]; // [esp+Ch] [ebp-30h] BYREF
  TextureHeader_t spec; // [esp+1Ch] [ebp-20h] BYREF
  int v11; // [esp+38h] [ebp-4h]

  if ( this->m_Texture2.m_pBinding == nullptr )
  {
    memset(&spec.m_Reflectivity, 0, sizeof(spec.m_Reflectivity));
    v11 = 0;
    spec.m_nDepth = width;
    *(_WORD *)&spec.m_nImageFormat = height;
    spec.m_nMultisampleType = 1;
    spec.m_nFlags = 256;
    V_snprintf(pDest: &pResourceName[4], maxLen: 16, pFormat: "%d", s_UniqueID_0);
    v7 = pRenderDevice->FindOrCreateTexture(
           this: pRenderDevice,
           a2: "matsystemtexture",
           a3: &pResourceName[4],
           a4: &spec.m_nDepth);
    m_pBinding = this->m_Texture2.m_pBinding;
    if ( m_pBinding != nullptr )
    {
      _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
      this->m_Texture2.m_pBinding = nullptr;
    }
    this->m_Texture2.m_pBinding = v7;
    if ( v7 != nullptr )
      _InterlockedExchangeAdd(&v7->m_nRefCount.m_value, 1u);
    ++s_UniqueID_0;
  }
  this->m_iWide = width;
  this->m_iTall = height;
  CMatSystemTexture::SetSubTextureRGBA(
    this,
    pRenderDevice,
    drawX: 0,
    drawY: 0,
    (const unsigned __int8 *)rgba,
    subTextureWide: width,
    subTextureTall: height);
}

//------------------------------------------------------------------------------
// Address: 0x004BE870
// Name: public: virtual void CTextureDictionary::SetTextureRGBAEx(int,char const __near *,int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTextureDictionary::SetTextureRGBAEx(
        CTextureDictionary *this@<ecx>,
        int a2@<ebx>,
        int id,
        const char *rgba,
        int wide,
        int tall,
        ImageFormat format)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v8; // ecx

  if ( this->IsValidId(this, a2: id) )
  {
    v8 = &this->m_Textures.m_Memory.m_pMemory[(unsigned __int16)id];
    if ( g_pMaterialSystem != nullptr )
      CMatSystemTexture::SetTextureRGBA(this: &v8->m_Element, a2, a3: (int)this, rgba, wide, tall, format);
    else
      CMatSystemTexture::SetTextureRGBA(
        this: &v8->m_Element,
        pRenderDevice: g_pRenderDevice,
        rgba,
        width: wide,
        height: tall,
        format);
  }
  else
  {
    _Msg(a1: "SetTextureRGBA: Invalid texture id %i\n", id);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BEA60
// Name: public: virtual int CTextureDictionary::CreateTexture(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureDictionary::CreateTexture(CTextureDictionary *this, bool procedural)
{
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *p_m_Textures; // esi
  int result; // eax
  int v4; // ecx

  p_m_Textures = &this->m_Textures;
  result = (unsigned __int16)CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AddToTail(this: &this->m_Textures);
  v4 = (int)&p_m_Textures->m_Memory.m_pMemory[(unsigned __int16)result];
  *(_DWORD *)(v4 + 48) = (unsigned __int16)result;
  if ( procedural )
    *(_DWORD *)(v4 + 52) |= 1u;
  else
    *(_DWORD *)(v4 + 52) &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BEA90
// Name: public: virtual void CTextureDictionary::DestroyAllTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::DestroyAllTextures(CTextureDictionary *this)
{
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *p_m_Textures; // esi

  p_m_Textures = &this->m_Textures;
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Textures);
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AddToTail(this: p_m_Textures);
  p_m_Textures->m_Memory.m_pMemory->m_Element.m_ID = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BEB00
// Name: public: virtual void CTextureDictionary::DestroyTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureDictionary::DestroyTexture(CTextureDictionary *this, int id)
{
  if ( id != -1 )
    CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::Remove(
      this: &this->m_Textures,
      elem: id);
}

//------------------------------------------------------------------------------
// Address: 0x005353F0
// Name: _GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &stru_5E58D0.m_PanelMessageMapPool);
  CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::RemoveAll(this: &stru_5E58D0.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(this: &stru_5E58D0.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00535440
// Name: _GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CClassMemoryPool<PanelAnimationMap>::Clear(this: &dictionary.m_PanelAnimationMapPool);
  CUtlDict<CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::RemoveAll(this: &dictionary.m_AnimationMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary.m_AnimationMaps.m_Elements.m_Tree);
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary.m_PanelAnimationMapPool);
}

//------------------------------------------------------------------------------
// Address: 0x004BE8E0
// Name: class CMatSystemTexture __near * Construct<class CMatSystemTexture>(class CMatSystemTexture __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMatSystemTexture *__cdecl Construct<CMatSystemTexture>(CMatSystemTexture *pMemory)
{
  CMatSystemTexture *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->m_Texture2.m_pBinding = nullptr;
  pMemory->m_Texture2.m_pBinding = nullptr;
  pMemory->m_t0 = 0.0;
  pMemory->m_s0 = 0.0;
  pMemory->m_pMaterial = nullptr;
  pMemory->m_pTexture = nullptr;
  pMemory->m_crcFile = 0;
  pMemory->m_iTall = 0;
  pMemory->m_iWide = 0;
  pMemory->m_t1 = 1.0;
  pMemory->m_s1 = 1.0;
  pMemory->m_Flags = 0;
  pMemory->m_pRegen = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00535410
// Name: _dynamic_atexit_destructor_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KBMgr__()
{
  CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>(this: &g_KBMgr.m_Bindings);
}

} // namespace vgui_perftest
