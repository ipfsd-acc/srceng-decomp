// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/renderer/scaleformtexture.cpp
// Functions: 15
// ============================================================

#include "materialsystem\scaleformui\renderer\scaleformtexture.h"

//------------------------------------------------------------------------------
// Address: 0x10004D60
// Name: public: ScaleformTexture::ScaleformTexture(class ScaleformRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
ScaleformTexture *__thiscall ScaleformTexture::ScaleformTexture(ScaleformTexture *this, ScaleformRenderer *pRenderer)
{
  GTextureImplNode::GTextureImplNode(this, plistRoot: &pRenderer->m_textures);
  this->m_pRenderer = pRenderer;
  this->m_hTexture = 0;
  this->m_isManaged = false;
  this->__vftable = (ScaleformTexture_vtbl *)&ScaleformTexture::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004D90
// Name: public: virtual bool ScaleformTexture::IsDataValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall ScaleformTexture::IsDataValid(ScaleformTexture *this)
{
  return this->m_hTexture != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004DA0
// Name: public: void ScaleformTexture::ReleaseTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformTexture::ReleaseTexture(ScaleformTexture *this)
{
  int m_hTexture; // eax

  m_hTexture = this->m_hTexture;
  if ( m_hTexture != 0 )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: m_hTexture);
    this->m_hTexture = 0;
  }
  this->m_isManaged = false;
}

//------------------------------------------------------------------------------
// Address: 0x10004DD0
// Name: public: virtual void ScaleformTexture::Bind(enum Sampler_t,enum GRenderer::BitmapWrapMode,enum GRenderer::BitmapSampleMode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformTexture::Bind(
        ScaleformTexture *this,
        Sampler_t sampler,
        GRenderer::BitmapWrapMode wrapMode,
        GRenderer::BitmapSampleMode sampleMode)
{
  int m_hTexture; // eax
  ShaderTexFilterMode_t v6; // esi
  ShaderTexWrapMode_t v7; // edi

  if ( this->m_hTexture == 0 )
    GTextureImplNode::CallRecreate(this);
  m_hTexture = this->m_hTexture;
  if ( m_hTexture != 0 )
  {
    v6 = sampleMode != Sample_Point;
    v7 = wrapMode != Wrap_Clamp;
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: m_hTexture);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: v6);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: v6);
    g_pShaderAPI->TexWrap(this: g_pShaderAPI, a2: SHADER_TEXCOORD_S, a3: v7);
    g_pShaderAPI->TexWrap(this: g_pShaderAPI, a2: SHADER_TEXCOORD_T, a3: v7);
    g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: sampler, a3: TEXTURE_BINDFLAGS_NONE, a4: this->m_hTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004E80
// Name: public: virtual bool ScaleformTexture::InitDynamicTexture(int,int,enum GImageBase::ImageFormat,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformTexture::InitDynamicTexture(
        ScaleformTexture *this,
        int width,
        int height,
        GImageBase::ImageFormat format,
        int mipmaps,
        char usage)
{
  int m_hTexture; // eax
  ScaleformRenderer *m_pRenderer; // eax
  ImageFormat v9; // edi
  int v10; // edx
  int v11; // eax

  m_hTexture = this->m_hTexture;
  if ( m_hTexture != 0 )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: m_hTexture);
    this->m_hTexture = 0;
  }
  m_pRenderer = this->m_pRenderer;
  this->m_isManaged = false;
  if ( m_pRenderer != nullptr && m_pRenderer->m_pDevice != nullptr )
  {
    if ( format == Image_ARGB_8888 || format == Image_RGB_888 )
    {
      this->m_d3dTextureFormat = D3DFMT_A8R8G8B8;
      goto LABEL_10;
    }
    if ( format == Image_A_8 )
    {
      this->m_d3dTextureFormat = D3DFMT_A8;
LABEL_10:
      v9 = ImageLoader::D3DFormatToImageFormat(format: this->m_d3dTextureFormat);
      v10 = 0;
      this->m_isManaged = (usage & 0x20) != 0;
      if ( (usage & 0x20) != 0 )
        v10 = 4;
      if ( (usage & 0x40) != 0 )
        v10 |= 2u;
      if ( (usage & 0x20) == 0 && (usage & 0x10) != 0 )
        v10 |= 0x10u;
      v11 = g_pShaderAPI->CreateTexture(
              this: g_pShaderAPI,
              a2: width,
              a3: height,
              a4: 0,
              a5: v9,
              a6: mipmaps + 1,
              a7: 0,
              a8: v10,
              a9: "ScaleformDynamic",
              a10: "Scaleform textures");
      this->m_hTexture = v11;
      return v11 != 0;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10004FA0
// Name: public: virtual ScaleformTexture::~ScaleformTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformTexture::~ScaleformTexture(ScaleformTexture *this)
{
  int m_hTexture; // eax
  ScaleformRenderer *m_pRenderer; // eax
  _RTL_CRITICAL_SECTION *p_cs; // edi

  this->__vftable = (ScaleformTexture_vtbl *)&ScaleformTexture::`vftable';
  m_hTexture = this->m_hTexture;
  if ( m_hTexture != 0 )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: m_hTexture);
    this->m_hTexture = 0;
  }
  m_pRenderer = this->m_pRenderer;
  this->m_isManaged = false;
  if ( m_pRenderer != nullptr )
  {
    p_cs = &m_pRenderer->m_texturesLock.cs;
    EnterCriticalSection(lpCriticalSection: &m_pRenderer->m_texturesLock.cs);
    if ( this->pNext != nullptr )
    {
      this->pPrev->pNext = this->pNext;
      this->pNext->GTextureImplNode::GRendererNode::$BA6E4D6F36D1F7A012BE29DE786EED17::pPrev = this->pPrev;
      this->pPrev = nullptr;
      this->pNext = nullptr;
    }
    LeaveCriticalSection(lpCriticalSection: p_cs);
  }
  this->m_pRenderer = nullptr;
  GTextureImplNode::~GTextureImplNode(this);
}

//------------------------------------------------------------------------------
// Address: 0x10005040
// Name: public: bool ScaleformTexture::InitTexture(unsigned char const __near *,int,int,enum ImageFormat,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ScaleformTexture::InitTexture(
        ScaleformTexture *this,
        const unsigned __int8 *rgba,
        int width,
        int height,
        ImageFormat srcImageFormat,
        ImageFormat dstImageFormat)
{
  int m_hTexture; // eax
  ImageFormat v8; // ebx
  int v9; // eax
  bool v10; // bl
  int v12; // [esp-8h] [ebp-58h]
  CPixelWriter writer; // [esp+8h] [ebp-48h] BYREF
  char debugName[32]; // [esp+2Ch] [ebp-24h] BYREF
  GTextureImplNode *v15; // [esp+4Ch] [ebp-4h]

  m_hTexture = this->m_hTexture;
  v15 = this;
  if ( m_hTexture != 0 )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: m_hTexture);
    this->m_hTexture = 0;
  }
  this->m_isManaged = false;
  if ( rgba == nullptr || width == 0 || height == 0 )
    return 0;
  v12 = s_textureIndex++;
  V_snprintf(pDest: debugName, maxLen: 32, pFormat: "ScaleformRGB%03d", v12);
  v8 = dstImageFormat;
  if ( dstImageFormat == IMAGE_FORMAT_DEFAULT )
    v8 = srcImageFormat;
  v9 = ((int (__stdcall *)(int, int, _DWORD, ImageFormat, int, int, int, char *, const char *))g_pShaderAPI->CreateTexture)(
         a1: width,
         a2: height,
         a3: 0,
         a4: v8,
         a5: 1,
         a6: 1,
         a7: 16,
         a8: debugName,
         a9: "Scaleform textures");
  v15[1].RefCount.Value = v9;
  g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v9);
  if ( !g_pShaderAPI->TexLock(this: g_pShaderAPI, a2: 0, a3: 0, a4: 0, a5: 0, a6: width, a7: height, a8: &writer) )
    return 0;
  v10 = ImageLoader::ConvertImageFormat(
          src: rgba,
          srcImageFormat,
          dst: writer.m_pBase,
          dstImageFormat: v8,
          width,
          height,
          srcStride: 0,
          dstStride: writer.m_BytesPerRow);
  g_pShaderAPI->TexUnlock(this: g_pShaderAPI);
  if ( !v10 )
    return 0;
  GTextureImplNode::CallHandlers(this: v15, event: Event_DataChange);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005180
// Name: public: virtual bool ScaleformTexture::InitTexture(class GImageBase __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ScaleformTexture::InitTexture(ScaleformTexture *this, GImageBase *pim, char usage)
{
  int m_hTexture; // eax
  __int32 v5; // eax
  ImageFormat v6; // eax
  unsigned int Width; // esi
  unsigned int Height; // edi
  unsigned int v9; // eax
  unsigned int v10; // ecx
  enum ImageFormat Format; // edx
  ScaleformRenderer::TexPowerOfTwo::Support m_texPowerOfTwoSupport; // edx
  _D3DFORMAT m_d3dTextureFormat; // edx
  GImage *v14; // eax
  GImage *v15; // eax
  GImageBase *v16; // edi
  unsigned int v17; // ecx
  int v18; // esi
  int v19; // eax
  GImage *pObject; // ebx
  GImageBase *v21; // ecx
  const unsigned __int8 *pData; // esi
  int m_BytesPerRow; // eax
  bool v24; // bl
  int v26; // [esp-4h] [ebp-88h]
  CPixelWriter writer; // [esp+Ch] [ebp-78h] BYREF
  char debugName[32]; // [esp+30h] [ebp-54h] BYREF
  GImage *v29; // [esp+50h] [ebp-34h]
  GTextureImplNode *v30; // [esp+54h] [ebp-30h]
  enum ImageFormat v31; // [esp+58h] [ebp-2Ch]
  ImageFormat imageFormat; // [esp+5Ch] [ebp-28h]
  GPtr<GImage> pResampleImage; // [esp+60h] [ebp-24h]
  ImageFormat sourceImageFormat; // [esp+64h] [ebp-20h]
  unsigned int bytesPerPixel; // [esp+68h] [ebp-1Ch]
  unsigned int w; // [esp+6Ch] [ebp-18h]
  unsigned int h; // [esp+70h] [ebp-14h]
  bool isDxtFormat; // [esp+77h] [ebp-Dh]
  int v39; // [esp+80h] [ebp-4h]

  m_hTexture = this->m_hTexture;
  v30 = this;
  if ( m_hTexture != 0 )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: m_hTexture);
    this->m_hTexture = 0;
  }
  this->m_isManaged = false;
  if ( pim != nullptr && pim->pData != nullptr )
  {
    v5 = pim->Format - 1;
    sourceImageFormat = IMAGE_FORMAT_UNKNOWN;
    switch ( v5 )
    {
      case 0:
        this->m_d3dTextureFormat = D3DFMT_A8R8G8B8;
        sourceImageFormat = IMAGE_FORMAT_RGBA8888;
        bytesPerPixel = 4;
        isDxtFormat = false;
        goto LABEL_14;
      case 1:
        this->m_d3dTextureFormat = D3DFMT_DXT1;
        sourceImageFormat = IMAGE_FORMAT_RGB888;
        bytesPerPixel = 3;
        goto LABEL_13;
      case 8:
        this->m_d3dTextureFormat = D3DFMT_A8;
        bytesPerPixel = 1;
        isDxtFormat = false;
        goto LABEL_14;
      case 9:
        this->m_d3dTextureFormat = D3DFMT_DXT1;
        goto LABEL_12;
      case 10:
        this->m_d3dTextureFormat = D3DFMT_DXT3;
        goto LABEL_12;
      case 11:
        this->m_d3dTextureFormat = D3DFMT_DXT5;
LABEL_12:
        bytesPerPixel = 1;
LABEL_13:
        isDxtFormat = true;
LABEL_14:
        v6 = ImageLoader::D3DFormatToImageFormat(format: this->m_d3dTextureFormat);
        imageFormat = v6;
        if ( sourceImageFormat == IMAGE_FORMAT_UNKNOWN )
          sourceImageFormat = v6;
        Width = pim->Width;
        Height = pim->Height;
        v9 = Width;
        v10 = Height;
        w = Width;
        h = Height;
        pResampleImage.pObject = nullptr;
        Format = pim->Format;
        v39 = 0;
        v31 = Format;
        if ( Format >= IMAGE_FORMAT_BGR888_BLUESCREEN && Format <= IMAGE_FORMAT_BGRA8888 )
          goto LABEL_48;
        m_texPowerOfTwoSupport = this->m_pRenderer->m_texPowerOfTwoSupport;
        if ( m_texPowerOfTwoSupport == Full || m_texPowerOfTwoSupport == NoRepeat && (usage & 1) == 0 )
        {
          m_d3dTextureFormat = this->m_d3dTextureFormat;
          if ( m_d3dTextureFormat == D3DFMT_DXT1
            || m_d3dTextureFormat == D3DFMT_DXT3
            || m_d3dTextureFormat == D3DFMT_DXT5 )
          {
            if ( (Width & 3) != 0 )
            {
              v9 = (Width & 0xFFFFFFFC) + 4;
              w = v9;
            }
            if ( (Height & 3) != 0 )
            {
              v10 = (Height & 0xFFFFFFFC) + 4;
LABEL_36:
              h = v10;
            }
          }
        }
        else
        {
          if ( ((Width - 1) & Width) != 0 )
          {
            v9 = 1;
            w = 1;
            if ( Width > 1 )
            {
              do
                v9 *= 2;
              while ( v9 < Width );
              w = v9;
            }
          }
          if ( ((Height - 1) & Height) != 0 )
          {
            v10 = 1;
            h = 1;
            if ( Height > 1 )
            {
              do
                v10 *= 2;
              while ( v10 < Height );
              goto LABEL_36;
            }
          }
        }
        if ( v9 == Width && v10 == Height )
        {
LABEL_48:
          v16 = pim;
        }
        else
        {
          v14 = (GImage *)GRefCountBaseStatImpl<GRefCountNTSImpl,3>::operator new(sz: 0x30u);
          v29 = v14;
          LOBYTE(v39) = 1;
          if ( v14 != nullptr )
            v15 = GImage::GImage(this: v14, a2: v31, a3: w, a4: h);
          else
            v15 = nullptr;
          v16 = pim;
          LOBYTE(v39) = 0;
          pResampleImage.pObject = v15;
          if ( v15 != nullptr )
          {
            v17 = pim->Width;
            if ( w != v17 || h != pim->Height )
              ScaleformRenderer::SoftwareResample(
                pDst: v15->pData,
                dstWidth: w,
                dstHeight: h,
                dstPitch: v15->Pitch,
                pSrc: pim->pData,
                srcWidth: v17,
                srcHeight: pim->Height,
                srcPitch: pim->Pitch,
                srcBytesPerPixel: bytesPerPixel,
                destBytePerPixel: bytesPerPixel);
            if ( pim->MipMapCount > 1 )
              _Warning(a1: "ScaleformRenderer - Existing mipmap levels have been skipped due to resampling");
          }
        }
        v18 = 0;
        this->m_isManaged = (usage & 0x20) != 0;
        if ( (usage & 0x20) != 0 )
          v18 = 4;
        if ( (usage & 0x40) != 0 )
          v18 |= 2u;
        if ( (usage & 0x20) == 0 )
          v18 |= 0x10u;
        v26 = s_textureIndex_0++;
        V_snprintf(pDest: debugName, maxLen: 32, pFormat: "Scaleform%03d", v26);
        v19 = g_pShaderAPI->CreateTexture(
                this: g_pShaderAPI,
                a2: w,
                a3: h,
                a4: 0,
                a5: imageFormat,
                a6: 1,
                a7: 1,
                a8: v18,
                a9: debugName,
                a10: "Scaleform textures");
        this->m_hTexture = v19;
        pObject = pResampleImage.pObject;
        v21 = &pResampleImage.pObject->GImageBase;
        if ( pResampleImage.pObject == nullptr )
          v21 = v16;
        pData = v21->pData;
        g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v19);
        if ( g_pShaderAPI->TexLock(this: g_pShaderAPI, a2: 0, a3: 0, a4: 0, a5: 0, a6: w, a7: h, a8: &writer) )
        {
          if ( isDxtFormat )
            m_BytesPerRow = 0;
          else
            m_BytesPerRow = writer.m_BytesPerRow;
          v24 = ImageLoader::ConvertImageFormat(
                  src: pData,
                  srcImageFormat: sourceImageFormat,
                  dst: writer.m_pBase,
                  dstImageFormat: imageFormat,
                  width: w,
                  height: h,
                  srcStride: 0,
                  dstStride: m_BytesPerRow);
          g_pShaderAPI->TexUnlock(this: g_pShaderAPI);
          if ( v24 )
          {
            GTextureImplNode::CallHandlers(this: v30, event: Event_DataChange);
            v39 = -1;
            if ( pResampleImage.pObject != nullptr )
              GRefCountNTSImpl::Release(this: pResampleImage.pObject);
            return 1;
          }
          v39 = -1;
          if ( pResampleImage.pObject != nullptr )
          {
            GRefCountNTSImpl::Release(this: pResampleImage.pObject);
            return 0;
          }
        }
        else
        {
          v39 = -1;
          if ( pObject != nullptr )
            GRefCountNTSImpl::Release(this: pObject);
        }
        return 0;
      default:
        return 0;
    }
  }
  GTextureImplNode::CallHandlers(this, event: Event_DataChange);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100055C0
// Name: public: virtual void ScaleformTexture::Update(int,int,struct GTexture::UpdateRect const __near *,class GImageBase const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformTexture::Update(
        ScaleformTexture *this,
        int level,
        int n,
        const GTexture::UpdateRect *rects,
        const GImageBase *pim)
{
  bool v6; // zf
  __int32 v7; // eax
  __int32 v8; // eax
  int *p_Right; // esi
  int v10; // ecx
  int v11; // edi
  int v12; // ebx
  int v13; // edx
  int v14; // ebx
  const GTexture::UpdateRect *v15; // eax
  int v16; // edi
  int v17; // eax
  unsigned int v18; // ecx
  CPixelWriter writer; // [esp+8h] [ebp-4Ch] BYREF
  GRect<int> rect; // [esp+2Ch] [ebp-28h]
  GPoint<int> dest; // [esp+3Ch] [ebp-18h]
  unsigned __int8 *pDest; // [esp+44h] [ebp-10h]
  unsigned int v23; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  unsigned int bytesPerPixel; // [esp+50h] [ebp-4h]
  const GTexture::UpdateRect *rectsa; // [esp+64h] [ebp+10h]
  unsigned int rectsb; // [esp+64h] [ebp+10h]

  ++this->m_pRenderer->m_statTextureUpdateCnt.Count;
  if ( this->m_hTexture != 0 || GTextureImplNode::CallRecreate(this) != 0 )
  {
    v7 = pim->Format - 1;
    v6 = pim->Format == Image_ARGB_8888;
    bytesPerPixel = 0;
    if ( v6 )
    {
      bytesPerPixel = 4;
    }
    else
    {
      v8 = v7 - 1;
      if ( v8 != 0 )
        bytesPerPixel = v8 == 7;
      else
        bytesPerPixel = 3;
    }
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: this->m_hTexture);
    i = 0;
    if ( n > 0 )
    {
      p_Right = &rects->src.Right;
      do
      {
        v10 = *(p_Right - 2);
        v11 = *(p_Right - 3);
        v12 = p_Right[1];
        v13 = *(p_Right - 4);
        rect.Top = *(p_Right - 1);
        v14 = v12 - rect.Top;
        v15 = (const GTexture::UpdateRect *)(*p_Right - v10);
        rect.Left = v10;
        dest.y = v11;
        rectsa = v15;
        if ( !g_pShaderAPI->TexLock(
                this: g_pShaderAPI,
                a2: level,
                a3: 0,
                a4: v13,
                a5: v11,
                a6: (int)&v15[-1].src.Bottom + 3,
                a7: v14 - 1,
                a8: &writer) )
          break;
        v16 = 0;
        pDest = writer.m_pBase;
        if ( v14 > 0 )
        {
          v17 = bytesPerPixel * (_DWORD)rectsa;
          v18 = bytesPerPixel * rect.Left;
          v23 = bytesPerPixel * (_DWORD)rectsa;
          rectsb = bytesPerPixel * rect.Left;
          while ( 1 )
          {
            _V_memcpy(
              dest: &pDest[v16 * writer.m_BytesPerRow],
              src: &pim->pData[v18 + pim->Pitch * (v16 + rect.Top)],
              count: v17);
            if ( ++v16 >= v14 )
              break;
            v18 = rectsb;
            v17 = v23;
          }
        }
        g_pShaderAPI->TexUnlock(this: g_pShaderAPI);
        p_Right += 6;
        ++i;
      }
      while ( i < n );
    }
  }
  else
  {
    DevWarning(a1: "ScaleformTexture::Update failed, there is no dynamic texture!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005730
// Name: public: void ScaleformTexture::RemoveFromRenderer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformTexture::RemoveFromRenderer(ScaleformTexture *this)
{
  GAtomicInt<long> *p_RefCount; // ebx
  volatile int Value; // edi

  p_RefCount = &this->RefCount;
  this->m_pRenderer = nullptr;
  Value = this->RefCount.Value;
  if ( Value != 0 )
  {
    while ( InterlockedCompareExchange(Destination: &p_RefCount->Value, Exchange: Value + 1, Comperand: Value) != Value )
    {
      Value = p_RefCount->Value;
      if ( p_RefCount->Value == 0 )
        goto LABEL_4;
    }
    if ( this->m_hTexture != 0 )
    {
      g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_hTexture);
      this->m_hTexture = 0;
    }
    this->m_isManaged = false;
    GTextureImplNode::CallHandlers(this, event: (GTexture::ChangeHandler::EventType)2);
    if ( this->pNext != nullptr )
    {
      this->pPrev->pNext = this->pNext;
      this->pNext->GTextureImplNode::GRendererNode::$BA6E4D6F36D1F7A012BE29DE786EED17::pPrev = this->pPrev;
      this->pPrev = nullptr;
      this->pNext = nullptr;
    }
    if ( InterlockedExchangeAdd(Addend: &p_RefCount->Value, Value: -1) == 1 )
      ((void (__thiscall *)(ScaleformTexture *, int))this->dtr_GTexture)(a1: this, a2: 1);
  }
  else
  {
LABEL_4:
    if ( this->pNext != nullptr )
    {
      this->pPrev->pNext = this->pNext;
      this->pNext->GTextureImplNode::GRendererNode::$BA6E4D6F36D1F7A012BE29DE786EED17::pPrev = this->pPrev;
      this->pPrev = nullptr;
      this->pNext = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007ADC0
// Name: public: virtual class GRenderer __near * ScaleformTexture::GetRenderer(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ScaleformTexture::GetRenderer(CBitRead *this)
{
  return *((_DWORD *)this + 10);
}

//------------------------------------------------------------------------------
// Address: 0x101E4FB2
// Name: private: unsigned int D3DXShader::CProgram::CompactPool_Map(struct D3DXShader::_D3DXCP_DATA __near *,unsigned int,unsigned int,unsigned int)
// Source: semantic_flat_class
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CProgram::CompactPool_Map(
        D3DXShader::CProgram *this,
        struct D3DXShader::_D3DXCP_DATA *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  D3DXShader::CProgram *v5; // edx
  _DWORD *v6; // ecx
  unsigned int result; // eax
  _DWORD *v9; // edi
  unsigned int v10; // ebx
  int v11; // edx
  _DWORD *v12; // eax
  int v13; // eax
  int v14; // ebx
  _DWORD *v15; // eax
  _DWORD *v16; // [esp+Ch] [ebp-8h]
  D3DXShader::CProgram *v17; // [esp+10h] [ebp-4h]
  struct D3DXShader::_D3DXCP_DATA *v18; // [esp+1Ch] [ebp+8h]
  unsigned int v19; // [esp+20h] [ebp+Ch]
  unsigned int v20; // [esp+24h] [ebp+10h]
  _DWORD *v21; // [esp+28h] [ebp+14h]

  v5 = this;
  v6 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * a3);
  v17 = v5;
  v16 = v6;
  v20 = *(_DWORD *)(*((_DWORD *)a2 + 7) + 4 * (a5 + 4 * a4));
  result = v20;
  if ( v20 != -1 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD **)(*((_DWORD *)v5 + 5) + 4 * result);
      if ( v9[18] < v6[22] )
      {
        v10 = v6[18];
        if ( v10 >= v9[22] )
          return -1;
        v11 = v9[5];
        if ( v6[5] == v11 && v6[6] == v11 )
          return result;
        if ( v10 >= v9[18] )
        {
          v12 = v9;
          v21 = v6;
        }
        else
        {
          v12 = v6;
          v21 = v9;
        }
        v19 = 0;
        v13 = 4 * v12[29];
        v14 = *((_DWORD *)a2 + 21) + 4 * *(_DWORD *)(v13 + *((_DWORD *)a2 + 20));
        v18 = *(struct D3DXShader::_D3DXCP_DATA **)(v13 + *((_DWORD *)a2 + 19));
        if ( v18 != nullptr )
        {
          do
          {
            v15 = (_DWORD *)(*((_DWORD *)a2 + 22) + 12 * *(_DWORD *)(v14 + 4 * v19));
            if ( *v15 <= v21[18] )
              break;
            if ( D3DXShader::CProgram::MutuallyExclusive(this: v17, a2: v21[5], a3: v21[6], a4: v15[1], a5: v15[2]) == 0 )
              return v20;
            ++v19;
            v6 = v16;
          }
          while ( v19 < (unsigned int)v18 );
        }
      }
      v20 = v9[12];
      if ( v20 == -1 )
        return -1;
      result = v9[12];
      v5 = v17;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101E50B0
// Name: private: unsigned int D3DXShader::CProgram::CompactPool_Score(struct D3DXShader::_D3DXCP_DATA __near *,unsigned int,unsigned int,int,unsigned int __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall D3DXShader::CProgram::CompactPool_Score(
        D3DXShader::CProgram *this,
        struct D3DXShader::_D3DXCP_DATA *a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        unsigned int *a6,
        unsigned int a7)
{
  struct D3DXShader::_D3DXCP_DATA *v7; // ebx
  int v8; // esi
  bool v9; // zf
  unsigned int v10; // eax
  bool v11; // cc
  int v12; // esi
  unsigned int v13; // edi
  int v14; // esi
  unsigned int v15; // eax
  int v16; // eax
  int v17; // ecx
  unsigned int v18; // edi
  unsigned int v19; // ecx
  int v20; // eax
  int v21; // ebx
  unsigned int v22; // esi
  int v23; // eax
  unsigned int v25; // [esp+Ch] [ebp-48h]
  unsigned int v26; // [esp+10h] [ebp-44h]
  unsigned int v27; // [esp+14h] [ebp-40h]
  unsigned int v28; // [esp+18h] [ebp-3Ch]
  _DWORD v29[4]; // [esp+1Ch] [ebp-38h] BYREF
  unsigned int v30; // [esp+2Ch] [ebp-28h]
  unsigned int v31; // [esp+30h] [ebp-24h]
  unsigned int v32; // [esp+34h] [ebp-20h]
  int v33; // [esp+38h] [ebp-1Ch]
  int v34; // [esp+3Ch] [ebp-18h]
  D3DXShader::CProgram *v35; // [esp+40h] [ebp-14h]
  unsigned int v36; // [esp+44h] [ebp-10h]
  int *v37; // [esp+48h] [ebp-Ch]
  unsigned int v38; // [esp+4Ch] [ebp-8h]
  int v39; // [esp+50h] [ebp-4h]
  unsigned int v40; // [esp+60h] [ebp+Ch]
  unsigned int v41; // [esp+60h] [ebp+Ch]
  int v42; // [esp+68h] [ebp+14h]

  v7 = a2;
  v8 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3);
  v9 = *(_BYTE *)(v8 + 3) >= 0;
  v10 = *(_DWORD *)(*((_DWORD *)a2 + 2) + 4 * *(_DWORD *)(v8 + 12));
  v35 = this;
  v33 = v8;
  v32 = v10;
  v38 = 4;
  if ( v9 )
  {
    v11 = v10 <= 1;
    if ( v10 != 1 )
      goto LABEL_5;
    if ( (*((_BYTE *)this + 108) & 4) == 0 )
    {
      v11 = true;
LABEL_5:
      if ( (v11 || (*((_BYTE *)this + 108) & 2) == 0)
        && D3DXShader::CInstruction::IsSpecial(this: *(D3DXShader::CInstruction **)(*((_DWORD *)this + 6)
                                                                                  + 4 * *(_DWORD *)(v8 + 72))) == 0 )
      {
        goto LABEL_9;
      }
    }
  }
  v38 = 1;
LABEL_9:
  v12 = *(_DWORD *)(v8 + 12);
  memset(v29, 255, sizeof(v29));
  v25 = -1;
  v26 = -1;
  v27 = -1;
  v28 = -1;
  v13 = 0;
  v39 = 4;
  v40 = 0;
  v14 = 16 * v12;
  do
  {
    v31 = *(_DWORD *)(v14 + *((_DWORD *)a2 + 6));
    v34 = 0;
    if ( v31 == -1 )
      goto LABEL_25;
    v15 = *(_DWORD *)(v14 + *((_DWORD *)a2 + 12));
    v36 = 0;
    v30 = v15;
    if ( v15 == 0 )
      goto LABEL_25;
    v37 = (int *)(*((_DWORD *)a2 + 14) + 4 * *(_DWORD *)(v14 + *((_DWORD *)a2 + 13)));
    while ( 1 )
    {
      v16 = *v37;
      v17 = *(_DWORD *)(*((_DWORD *)a2 + 4) + 4 * ((unsigned int)*v37 >> 2));
      if ( v17 != -1 )
        v34 = 1;
      if ( a4 == v17 )
      {
        v18 = *(_DWORD *)(*((_DWORD *)a2 + 5) + 4 * v16);
        if ( v18 != -1
          && v29[v18] == -1
          && (v38 != 1 || v40 == v18)
          && D3DXShader::CProgram::CompactPool_Map(this: v35, a2, a3: v31, a4, a5: v18) == -1 )
        {
          break;
        }
      }
      ++v36;
      ++v37;
      if ( v36 >= v30 )
        goto LABEL_24;
    }
    --v39;
    v29[v18] = v40;
    *(&v25 + v40) = v18;
LABEL_24:
    v13 = 0;
    if ( v34 == 0 )
LABEL_25:
      --v39;
    ++v40;
    v14 += 4;
  }
  while ( v40 < 4 );
  v19 = v39 << 29;
  if ( v39 << 29 < a7 )
  {
    v20 = 0;
    if ( a5 >= 0 )
    {
      if ( a5 <= 0 || (a4 & 1) != 0 )
      {
LABEL_34:
        v19 |= v20 << 28;
        v42 = v19;
        if ( v19 < a7 )
        {
          do
          {
            if ( *(&v25 + v13) == -1 )
            {
              v41 = *(_DWORD *)(*((_DWORD *)v7 + 6) + 4 * (v13 + 4 * *(_DWORD *)(v33 + 12)));
              if ( v41 != -1 )
              {
                v21 = 0;
                if ( v38 != 0 )
                {
                  while ( 1 )
                  {
                    v22 = ((_BYTE)v21 + (_BYTE)v13) & 3;
                    if ( v32 == 1
                      && ((*((_BYTE *)v35 + 112) & 2) == 0
                       || ((v23 = **(_DWORD **)(*((_DWORD *)v35 + 6) + 4 * *(_DWORD *)(v33 + 72))) & 0xFFF00000) != 0x50000000
                       || (v23 & 0xFFFFFu) >= 4) )
                    {
                      v22 = 3 - v22;
                    }
                    if ( v29[v22] == -1
                      && D3DXShader::CProgram::CompactPool_Map(this: v35, a2, a3: v41, a4, a5: v22) == -1 )
                    {
                      break;
                    }
                    if ( ++v21 >= v38 )
                      goto LABEL_48;
                  }
                  v29[v22] = v13;
                  *(&v25 + v13) = v22;
                }
LABEL_48:
                if ( v38 == v21 )
                  return -1;
                if ( (*((_BYTE *)a2 + 96) & 1) != 0 && v32 <= 1 )
                {
                  v19 = v42;
                }
                else
                {
                  v19 = (v21 << 24) + v42;
                  v42 = v19;
                  if ( v19 >= a7 )
                    return v19;
                }
                v7 = a2;
              }
            }
            ++v13;
          }
          while ( v13 < 4 );
          if ( a6 != nullptr )
          {
            *a6 = v25;
            a6[1] = v26;
            a6[2] = v27;
            a6[3] = v28;
          }
        }
        return v19;
      }
    }
    else if ( (a4 & 1) == 0 )
    {
      goto LABEL_34;
    }
    v20 = 1;
    goto LABEL_34;
  }
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x101E5326
// Name: private: void D3DXShader::CProgram::CompactPool_ReadCount(struct D3DXShader::_D3DXCP_DATA __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CProgram::CompactPool_ReadCount(
        D3DXShader::CProgram *this,
        struct D3DXShader::_D3DXCP_DATA *a2,
        unsigned int a3,
        unsigned int a4)
{
  int v6; // edx
  _DWORD *v7; // esi
  int v8; // edx
  int v9; // edx
  unsigned int v10; // edi
  int v11; // ebx
  int v12; // edi
  int v13; // ebx
  int v14; // edi
  int v15; // [esp+Ch] [ebp-8h]
  struct D3DXShader::_D3DXCP_DATA *v16; // [esp+1Ch] [ebp+8h]

  do
  {
    v6 = *((_DWORD *)this + 5);
    if ( *(_DWORD *)(*(_DWORD *)(v6 + 4 * a3) + 56) != -1 )
      a3 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * a3) + 56);
    v7 = *(_DWORD **)(v6 + 4 * a3);
    if ( v7[1] == *(_DWORD *)a2 )
    {
      v15 = v7[29];
      if ( *((_DWORD *)a2 + 22) != 0 )
      {
        v8 = *(_DWORD *)(*((_DWORD *)a2 + 19) + 4 * v7[29]) + *(_DWORD *)(*((_DWORD *)a2 + 20) + 4 * v7[29]);
        *(_DWORD *)(*((_DWORD *)a2 + 21) + 4 * v8) = v8;
        v9 = 12 * v8;
        *(_DWORD *)(v9 + *((_DWORD *)a2 + 22)) = a4;
        v10 = **(_DWORD **)(*((_DWORD *)this + 6) + 4 * a4) & 0xFFF00000;
        if ( v10 == 544210944 || v10 == 545259520 || v10 == 290455552 )
        {
          *(_DWORD *)(v9 + *((_DWORD *)a2 + 22) + 4) = v7[5];
          *(_DWORD *)(v9 + *((_DWORD *)a2 + 22) + 8) = v7[6];
        }
        else
        {
          *(_DWORD *)(v9 + *((_DWORD *)a2 + 22) + 4) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                                             + 4
                                                                             * **(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * a4)
                                                                                           + 16))
                                                                 + 20);
          *(_DWORD *)(v9 + *((_DWORD *)a2 + 22) + 8) = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5)
                                                                             + 4
                                                                             * **(_DWORD **)(*(_DWORD *)(*((_DWORD *)this + 6) + 4 * a4)
                                                                                           + 16))
                                                                 + 24);
        }
        v11 = v9 + *((_DWORD *)a2 + 22);
        v12 = *(_DWORD *)(v11 + 4);
        v13 = *(_DWORD *)(v11 + 8);
        while ( v12 != v7[5] )
        {
          v16 = (struct D3DXShader::_D3DXCP_DATA *)(4 * v12);
          if ( *(char *)(*(_DWORD *)(*((_DWORD *)this + 4)
                                   + 4 * *(_DWORD *)(*(_DWORD *)(4 * v12 + *((_DWORD *)this + 5)) + 4))
                       + 5) < 0 )
          {
            *(_DWORD *)(v9 + *((_DWORD *)a2 + 22) + 4) = v12;
            *(_DWORD *)(v9 + *((_DWORD *)a2 + 22) + 8) = v13;
            *(_DWORD *)(v9 + *((_DWORD *)a2 + 22)) = *(_DWORD *)(*(_DWORD *)((char *)v16 + *((_DWORD *)this + 5)) + 88);
            if ( v7[22] < *(_DWORD *)(*(_DWORD *)((char *)v16 + *((_DWORD *)this + 5)) + 88) )
              v7[22] = *(_DWORD *)(*(_DWORD *)((char *)v16 + *((_DWORD *)this + 5)) + 88);
          }
          v14 = *(_DWORD *)((char *)v16 + *((_DWORD *)this + 5));
          v13 = *(_DWORD *)(v14 + 24);
          v12 = *(_DWORD *)(v14 + 20);
        }
      }
      ++*(_DWORD *)(*((_DWORD *)a2 + 19) + 4 * v15);
    }
    a3 = v7[2];
  }
  while ( a3 != -1 );
}

//------------------------------------------------------------------------------
// Address: 0x101E54A9
// Name: private: void D3DXShader::CProgram::CompactPool_WriteCount(struct D3DXShader::_D3DXCP_DATA __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CProgram::CompactPool_WriteCount(
        D3DXShader::CProgram *this,
        struct D3DXShader::_D3DXCP_DATA *a2,
        unsigned int a3,
        unsigned int a4)
{
  unsigned int v4; // eax

  v4 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3) + 20);
  if ( v4 != -1 )
    D3DXShader::CProgram::CompactPool_ReadCount(this, a2, a3: v4, a4);
}
