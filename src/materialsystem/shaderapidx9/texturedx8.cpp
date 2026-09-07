// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/texturedx8.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10029720
// Name: GetImageFormat
// Source: json
//------------------------------------------------------------------------------
ImageFormat __usercall GetImageFormat@<eax>(IDirect3DBaseTexture9 *pTexture@<esi>)
{
  _D3DRESOURCETYPE v1; // eax
  IDirect3DBaseTexture9_vtbl *v2; // edx
  int v3; // eax
  _D3DVOLUME_DESC desc; // [esp+0h] [ebp-20h] BYREF

  if ( pTexture != nullptr )
  {
    v1 = pTexture->GetType(this: pTexture);
    v2 = pTexture->__vftable;
    if ( v1 == D3DRTYPE_VOLUMETEXTURE )
    {
      if ( v2[1].QueryInterface(this: pTexture, a2: nullptr, a3: (void **)&desc.Type) >= 0 )
        return ImageLoader::D3DFormatToImageFormat(format: (_D3DFORMAT)desc.Type);
    }
    else
    {
      v3 = v2->GetType(this: pTexture) - 3;
      if ( (v3 == 0 || v3 == 2)
        && pTexture->__vftable[1].QueryInterface(this: pTexture, a2: nullptr, a3: (void **)&desc) >= 0 )
      {
        return ImageLoader::D3DFormatToImageFormat(format: desc.Format);
      }
    }
  }
  return IMAGE_FORMAT_UNKNOWN;
}

//------------------------------------------------------------------------------
// Address: 0x100297A0
// Name: struct IDirect3DBaseTexture9 __near * CreateD3DTexture(int,int,int,enum ImageFormat,int,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
IDirect3DBaseTexture9 *__cdecl CreateD3DTexture(
        unsigned int width,
        unsigned int height,
        _D3DPOOL nDepth,
        ImageFormat dstFormat,
        unsigned int numLevels,
        int nCreationFlags)
{
  int v6; // edi
  char v8; // bl
  _D3DFORMAT NearestSupportedFormat; // eax
  _D3DFORMAT v10; // esi
  D3DDeviceWrapper *v12; // ebx
  int v13; // eax
  void *v14; // ecx
  D3DDeviceWrapper *v15; // ebx
  D3DDeviceWrapper *v16; // ebx
  IDirect3DTexture9 *pD3DTexture; // [esp+Ch] [ebp-14h] BYREF
  IDirect3DVolumeTexture9 *pD3DVolumeTexture; // [esp+10h] [ebp-10h] BYREF
  IDirect3DCubeTexture9 *pD3DCubeTexture; // [esp+14h] [ebp-Ch] BYREF
  BOOL bIsRenderTarget; // [esp+18h] [ebp-8h]
  bool bSysMem; // [esp+1Ch] [ebp-4h]
  bool bVolumeTexture; // [esp+1Dh] [ebp-3h]
  bool bAutoMipMap; // [esp+1Eh] [ebp-2h]
  bool bIsDynamic; // [esp+1Fh] [ebp-1h]
  _D3DPOOL d3dPool; // [esp+30h] [ebp+10h]
  bool bManaged_3; // [esp+3Fh] [ebp+1Fh]

  v6 = 0;
  if ( nDepth <= D3DPOOL_DEFAULT )
    nDepth = D3DPOOL_MANAGED;
  LOBYTE(bIsRenderTarget) = (nCreationFlags & 2) != 0;
  bManaged_3 = (nCreationFlags & 4) != 0;
  bIsDynamic = (nCreationFlags & 0x10) != 0;
  bAutoMipMap = (nCreationFlags & 0x20) != 0;
  v8 = nCreationFlags & 1;
  bVolumeTexture = nDepth > D3DPOOL_MANAGED;
  bSysMem = BYTE2(nCreationFlags) & 1;
  NearestSupportedFormat = FindNearestSupportedFormat(
                             format: dstFormat,
                             bIsVertexTexture: (nCreationFlags & 0x40) != 0,
                             bIsRenderTarget,
                             bFilterableRequired: (nCreationFlags & 0x1000) != 0);
  v10 = NearestSupportedFormat;
  if ( NearestSupportedFormat == D3DFMT_UNKNOWN )
  {
    _Warning(a1: "ShaderAPIDX8::CreateD3DTexture: Invalid color format!\n");
    return nullptr;
  }
  pD3DTexture = nullptr;
  pD3DCubeTexture = nullptr;
  pD3DVolumeTexture = nullptr;
  if ( bIsRenderTarget )
    v6 = 1;
  if ( bIsDynamic )
    v6 |= 0x200u;
  if ( bAutoMipMap )
    v6 |= 0x400u;
  if ( v8 != 0 )
  {
    v12 = Dx9Device();
    D3DDeviceWrapper::Synchronize(this: v12);
    v13 = v12->m_pD3DDevice->CreateCubeTexture(
            this: v12->m_pD3DDevice,
            a2: width,
            a3: numLevels,
            a4: v6,
            a5: v10,
            a6: (_D3DPOOL)((nCreationFlags & 4) != 0),
            a7: &pD3DCubeTexture,
            a8: nullptr);
    v14 = pD3DCubeTexture;
  }
  else if ( bVolumeTexture )
  {
    v15 = Dx9Device();
    D3DDeviceWrapper::Synchronize(this: v15);
    v13 = v15->m_pD3DDevice->CreateVolumeTexture(
            this: v15->m_pD3DDevice,
            a2: width,
            a3: height,
            a4: nDepth,
            a5: numLevels,
            a6: v6,
            a7: v10,
            a8: (_D3DPOOL)((nCreationFlags & 4) != 0),
            a9: &pD3DVolumeTexture,
            a10: nullptr);
    v14 = pD3DVolumeTexture;
  }
  else
  {
    if ( NearestSupportedFormat == 1515667794
      || NearestSupportedFormat == 1515474505
      || NearestSupportedFormat == D3DFMT_D16
      || NearestSupportedFormat == D3DFMT_D24S8
      || NearestSupportedFormat == 909198916
      || NearestSupportedFormat == 875710020 )
    {
      v6 = 2;
      bManaged_3 = false;
    }
    if ( NearestSupportedFormat == 1280070990 )
      bManaged_3 = false;
    if ( bSysMem )
      d3dPool = D3DPOOL_SYSTEMMEM;
    else
      d3dPool = bManaged_3;
    v16 = Dx9Device();
    D3DDeviceWrapper::Synchronize(this: v16);
    v13 = v16->m_pD3DDevice->CreateTexture(
            this: v16->m_pD3DDevice,
            a2: width,
            a3: height,
            a4: numLevels,
            a5: v6,
            a6: v10,
            a7: d3dPool,
            a8: &pD3DTexture,
            a9: nullptr);
    v14 = pD3DTexture;
  }
  if ( v13 >= 0 )
  {
    ++s_TextureCount;
    return (IDirect3DBaseTexture9 *)v14;
  }
  else
  {
    switch ( v13 )
    {
      case -2147024882:
        _Warning(a1: "ShaderAPIDX8::CreateD3DTexture: E_OUTOFMEMORY\n");
        break;
      case -2005532292:
        if ( bManaged_3 )
        {
          _Warning(a1: "ShaderAPIDX8::CreateD3DTexture: D3DERR_OUTOFVIDEOMEMORY\n");
          return nullptr;
        }
        break;
      case -2005530516:
        _Warning(a1: "ShaderAPIDX8::CreateD3DTexture: D3DERR_INVALIDCALL\n");
        return nullptr;
      default:
        break;
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029A00
// Name: void DestroyD3DTexture(struct IDirect3DBaseTexture9 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyD3DTexture(IDirect3DBaseTexture9 *pD3DTex)
{
  if ( pD3DTex != nullptr )
  {
    pD3DTex->Release(this: pD3DTex);
    --s_TextureCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029A20
// Name: bool LockTexture(int,int,struct IDirect3DBaseTexture9 __near *,int,enum _D3DCUBEMAP_FACES,int,int,int,int,bool,class CPixelWriter __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LockTexture(
        int bindId,
        int copy,
        IDirect3DSurface9 *pTexture,
        int level,
        _D3DCUBEMAP_FACES cubeFaceID,
        int xOffset,
        int yOffset,
        int width,
        int height,
        bool bDiscard,
        CPixelWriter *writer)
{
  IDirect3DBaseTexture9 *v11; // esi
  __int32 v12; // eax
  int v13; // eax
  bool result; // al
  int v15; // edi
  unsigned __int8 *pBits; // edi
  ImageFormat ImageFormat; // eax
  CPixelWriter *v18; // ecx
  ImageFormat v19; // edx
  __int16 v20; // dx
  __int16 v21; // dx
  unsigned __int16 Pitch; // [esp+8h] [ebp-4h]

  v11 = (IDirect3DBaseTexture9 *)pTexture;
  if ( pTexture == nullptr )
    return false;
  v12 = pTexture->GetType(this: pTexture) - 3;
  if ( v12 != 0 )
  {
    if ( v12 != 2 )
      return false;
    v13 = ((int (__stdcall *)(IDirect3DBaseTexture9 *, _D3DCUBEMAP_FACES, int, IDirect3DSurface9 **))v11->__vftable[1].AddRef)(
            a1: v11,
            a2: cubeFaceID,
            a3: level,
            a4: &pTexture);
  }
  else
  {
    v13 = ((int (__stdcall *)(IDirect3DBaseTexture9 *, int, IDirect3DSurface9 **))v11->__vftable[1].AddRef)(
            a1: v11,
            a2: level,
            a3: &pTexture);
  }
  if ( v13 < 0 )
    return false;
  s_LockedSrcRect.left = xOffset;
  s_LockedSrcRect.right = width + xOffset;
  s_LockedSrcRect.top = yOffset;
  s_LockedSrcRect.bottom = height + yOffset;
  v15 = pTexture->LockRect(this: pTexture, a2: &s_LockedRect, a3: &s_LockedSrcRect, a4: (bDiscard ? 0x2000 : 0) | 0x800);
  pTexture->Release(this: pTexture);
  if ( v15 < 0 )
    return false;
  pBits = (unsigned __int8 *)s_LockedRect.pBits;
  Pitch = s_LockedRect.Pitch;
  ImageFormat = GetImageFormat(pTexture: v11);
  v18 = writer;
  v19 = ImageFormat;
  writer->m_BytesPerRow = Pitch;
  v18->m_pBits = pBits;
  v18->m_pBase = pBits;
  v18->m_nFlags = 0;
  result = true;
  switch ( v19 )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      v18->m_RShift = 0;
      v18->m_GShift = 8;
      v20 = 16;
      goto LABEL_15;
    case IMAGE_FORMAT_BGR888:
      v18->m_RShift = 16;
      v18->m_GShift = 8;
      v21 = 0;
      v18->m_Size = 3;
      v18->m_BShift = 0;
      goto LABEL_19;
    case IMAGE_FORMAT_I8:
      v18->m_Size = 1;
      v18->m_RShift = 0;
      goto LABEL_28;
    case IMAGE_FORMAT_A8:
      v18->m_RMask = 0;
      v18->m_GMask = 0;
      v18->m_BMask = 0;
      v18->m_Size = 1;
      v18->m_RShift = 0;
      v18->m_GShift = 0;
      v18->m_BShift = 0;
      v18->m_AShift = 0;
      v18->m_AMask = 255;
      return result;
    case IMAGE_FORMAT_BGRA8888:
      v18->m_RShift = 16;
      v18->m_GShift = 8;
      v20 = 0;
LABEL_15:
      v18->m_BShift = v20;
      v18->m_AShift = 24;
      v18->m_Size = 4;
      v18->m_RMask = 255;
      v18->m_GMask = 255;
      v18->m_BMask = 255;
      v18->m_AMask = 255;
      return result;
    case IMAGE_FORMAT_BGRX8888:
      v18->m_RShift = 16;
      v18->m_GShift = 8;
      v18->m_BShift = 0;
      v18->m_Size = 4;
      v21 = 24;
LABEL_19:
      v18->m_AShift = v21;
      v18->m_AMask = 0;
      v18->m_GMask = 255;
      v18->m_RMask = 255;
      v18->m_BMask = 255;
      return result;
    case IMAGE_FORMAT_BGR565:
      v18->m_RShift = 8;
      v18->m_GShift = 3;
      v18->m_BShift = -3;
      v18->m_AShift = 0;
      v18->m_AMask = 0;
      v18->m_Size = 2;
      v18->m_GMask = 252;
      v18->m_RMask = 248;
      v18->m_BMask = 248;
      return result;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      v18->m_RShift = 7;
      v18->m_GShift = 2;
      v18->m_BShift = -3;
      v18->m_AShift = 8;
      v18->m_Size = 2;
      v18->m_RMask = 248;
      v18->m_GMask = 248;
      v18->m_BMask = 248;
      v18->m_AMask = 128;
      return result;
    case IMAGE_FORMAT_BGRA4444:
      v18->m_RShift = 4;
      v18->m_GShift = 0;
      v18->m_BShift = -4;
      v18->m_AShift = 8;
      v18->m_Size = 2;
      v18->m_RMask = 240;
      v18->m_GMask = 240;
      v18->m_BMask = 240;
      v18->m_AMask = 240;
      return result;
    case IMAGE_FORMAT_RGBA16161616F:
      v18->m_RShift = 0;
      v18->m_GShift = 16;
      v18->m_BShift = 32;
      v18->m_AShift = 48;
      v18->m_RMask = 0xFFFF;
      v18->m_GMask = 0xFFFF;
      v18->m_BMask = 0xFFFF;
      v18->m_AMask = 0xFFFF;
      *(_WORD *)&v18->m_Size = 776;
      return result;
    case IMAGE_FORMAT_RGBA16161616:
      v18->m_RShift = 0;
      v18->m_GShift = 16;
      v18->m_BShift = 32;
      v18->m_AShift = 48;
      v18->m_Size = 8;
      v18->m_RMask = 0xFFFF;
      v18->m_GMask = 0xFFFF;
      v18->m_BMask = 0xFFFF;
      v18->m_AMask = 0xFFFF;
      return result;
    case IMAGE_FORMAT_R32F:
      v18->m_Size = 4;
      v18->m_RShift = 0;
      v18->m_RMask = -1;
      v18->m_nFlags = 1;
      goto LABEL_29;
    case IMAGE_FORMAT_RGBA32323232F:
      v18->m_RShift = 0;
      v18->m_GShift = 32;
      v18->m_BShift = 64;
      v18->m_AShift = 96;
      v18->m_Size = 16;
      v18->m_RMask = -1;
      v18->m_GMask = -1;
      v18->m_BMask = -1;
      v18->m_AMask = -1;
      v18->m_nFlags = 1;
      return result;
    case IMAGE_FORMAT_BGRA1010102:
      v18->m_RShift = 20;
      v18->m_GShift = 10;
      v18->m_BShift = 0;
      v18->m_AShift = 30;
      v18->m_Size = 4;
      v18->m_RMask = 1023;
      v18->m_GMask = 1023;
      v18->m_BMask = 1023;
      v18->m_AMask = 3;
      return result;
    default:
      *(_DWORD *)&v18->m_Size = 2048;
LABEL_28:
      v18->m_RMask = 255;
LABEL_29:
      v18->m_GMask = 0;
      v18->m_BMask = 0;
      v18->m_AMask = 0;
      v18->m_GShift = 0;
      v18->m_BShift = 0;
      v18->m_AShift = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029E70
// Name: void UnlockTexture(int,int,struct IDirect3DBaseTexture9 __near *,int,enum _D3DCUBEMAP_FACES)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnlockTexture(int bindId, int copy, IDirect3DSurface9 *pTexture, int level, _D3DCUBEMAP_FACES cubeFaceID)
{
  IDirect3DSurface9 *v5; // esi
  __int32 v6; // eax
  int v7; // eax

  v5 = pTexture;
  if ( pTexture != nullptr )
  {
    v6 = pTexture->GetType(this: pTexture) - 3;
    if ( v6 != 0 )
    {
      if ( v6 != 2 )
        return;
      v7 = ((int (__stdcall *)(IDirect3DSurface9 *, _D3DCUBEMAP_FACES, int, IDirect3DSurface9 **))v5->__vftable[1].AddRef)(
             a1: v5,
             a2: cubeFaceID,
             a3: level,
             a4: &pTexture);
    }
    else
    {
      v7 = ((int (__stdcall *)(IDirect3DSurface9 *, int, IDirect3DSurface9 **))v5->__vftable[1].AddRef)(
             a1: v5,
             a2: level,
             a3: &pTexture);
    }
    if ( v7 >= 0 )
    {
      pTexture->UnlockRect(this: pTexture);
      pTexture->Release(this: pTexture);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029ED0
// Name: BlitSurfaceBits
// Source: json
//------------------------------------------------------------------------------
void __usercall BlitSurfaceBits(TextureLoadInfo_t *info@<edi>, int xOffset, int yOffset, int srcStride)
{
  int m_nLevel; // ebx
  IDirect3DBaseTexture9 *m_pTexture; // esi
  int v6; // eax
  int v7; // eax
  int m_nHeight; // edx
  int v9; // ecx
  ImageFormat ImageFormat; // eax
  tagRECT srcRect; // [esp+8h] [ebp-20h] BYREF
  _D3DLOCKED_RECT lockedRect; // [esp+18h] [ebp-10h] BYREF
  _D3DCUBEMAP_FACES m_CubeFaceID; // [esp+20h] [ebp-8h]
  IDirect3DSurface9 *pTextureLevel; // [esp+24h] [ebp-4h] BYREF

  m_nLevel = info->m_nLevel;
  m_pTexture = info->m_pTexture;
  m_CubeFaceID = info->m_CubeFaceID;
  if ( m_pTexture != nullptr )
  {
    v6 = m_pTexture->GetType(this: m_pTexture) - 3;
    if ( v6 != 0 )
    {
      if ( v6 != 2 )
        return;
      v7 = ((int (__stdcall *)(IDirect3DBaseTexture9 *, _D3DCUBEMAP_FACES, int, IDirect3DSurface9 **))m_pTexture->__vftable[1].AddRef)(
             a1: m_pTexture,
             a2: m_CubeFaceID,
             a3: m_nLevel,
             a4: &pTextureLevel);
    }
    else
    {
      v7 = ((int (__stdcall *)(IDirect3DBaseTexture9 *, int, IDirect3DSurface9 **))m_pTexture->__vftable[1].AddRef)(
             a1: m_pTexture,
             a2: m_nLevel,
             a3: &pTextureLevel);
    }
    if ( v7 >= 0 )
    {
      m_nHeight = info->m_nHeight;
      v9 = xOffset + info->m_nWidth;
      srcRect.left = xOffset;
      srcRect.bottom = yOffset + m_nHeight;
      srcRect.top = yOffset;
      srcRect.right = v9;
      if ( pTextureLevel->LockRect(this: pTextureLevel, a2: &lockedRect, a3: &srcRect, a4: 2048u) >= 0 )
      {
        ImageFormat = GetImageFormat(pTexture: info->m_pTexture);
        g_pShaderUtil->ConvertImageFormat(
          this: g_pShaderUtil,
          a2: info->m_pSrcData,
          a3: info->m_SrcFormat,
          a4: (unsigned __int8 *)lockedRect.pBits,
          a5: ImageFormat,
          a6: info->m_nWidth,
          a7: info->m_nHeight,
          a8: srcStride,
          a9: lockedRect.Pitch);
        if ( pTextureLevel->UnlockRect(this: pTextureLevel) < 0 )
          _Warning(a1: "CShaderAPIDX8::BlitTextureBits: couldn't unlock texture rect\n");
      }
      else
      {
        _Warning(a1: "CShaderAPIDX8::BlitTextureBits: couldn't lock texture rect\n");
      }
      pTextureLevel->Release(this: pTextureLevel);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029FD0
// Name: BlitVolumeBits
// Source: json
//------------------------------------------------------------------------------
void __usercall BlitVolumeBits(
        TextureLoadInfo_t *info@<edi>,
        unsigned int xOffset@<ecx>,
        unsigned int yOffset@<eax>,
        int srcStride)
{
  unsigned int v4; // edx
  int m_nHeight; // ecx
  IDirect3DBaseTexture9 *m_pTexture; // ebx
  int m_nLevel; // eax
  ImageFormat ImageFormat; // eax
  _D3DBOX srcBox; // [esp+4h] [ebp-24h] BYREF
  _D3DLOCKED_BOX lockedBox; // [esp+1Ch] [ebp-Ch] BYREF

  v4 = xOffset + info->m_nWidth;
  srcBox.Left = xOffset;
  m_nHeight = info->m_nHeight;
  srcBox.Top = yOffset;
  m_pTexture = info->m_pTexture;
  srcBox.Front = info->m_nZOffset;
  srcBox.Back = srcBox.Front + 1;
  srcBox.Bottom = yOffset + m_nHeight;
  m_nLevel = info->m_nLevel;
  srcBox.Right = v4;
  if ( ((int (__stdcall *)(IDirect3DBaseTexture9 *, int, _D3DLOCKED_BOX *, _D3DBOX *, int))m_pTexture->__vftable[1].Release)(
         a1: m_pTexture,
         a2: m_nLevel,
         a3: &lockedBox,
         a4: &srcBox,
         a5: 2048) >= 0 )
  {
    ImageFormat = GetImageFormat(pTexture: info->m_pTexture);
    g_pShaderUtil->ConvertImageFormat(
      this: g_pShaderUtil,
      a2: info->m_pSrcData,
      a3: info->m_SrcFormat,
      a4: (unsigned __int8 *)lockedBox.pBits,
      a5: ImageFormat,
      a6: info->m_nWidth,
      a7: info->m_nHeight,
      a8: srcStride,
      a9: lockedBox.RowPitch);
    if ( m_pTexture->__vftable[1].GetDevice(this: m_pTexture, a2: (IDirect3DDevice9 **)info->m_nLevel) < 0 )
      _Warning(a1: "BlitVolumeBits: couldn't unlock volume texture rect\n");
  }
  else
  {
    _Warning(a1: "BlitVolumeBits: couldn't lock volume texture rect\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A090
// Name: void LoadTexture(struct TextureLoadInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadTexture(TextureLoadInfo_t *info)
{
  IDirect3DBaseTexture9 *m_pTexture; // eax

  m_pTexture = info->m_pTexture;
  if ( m_pTexture != nullptr && m_pTexture->GetType(this: info->m_pTexture) == D3DRTYPE_VOLUMETEXTURE )
    BlitVolumeBits(info, xOffset: 0, yOffset: 0, srcStride: 0);
  else
    BlitSurfaceBits(info, xOffset: 0, yOffset: 0, srcStride: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002A0E0
// Name: void LoadSubTexture(struct TextureLoadInfo_t __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadSubTexture(TextureLoadInfo_t *info, int xOffset, int yOffset, int srcStride)
{
  IDirect3DBaseTexture9 *m_pTexture; // eax

  m_pTexture = info->m_pTexture;
  if ( m_pTexture != nullptr && m_pTexture->GetType(this: info->m_pTexture) == D3DRTYPE_VOLUMETEXTURE )
    BlitVolumeBits(info, xOffset, yOffset, srcStride);
  else
    BlitSurfaceBits(info, xOffset, yOffset, srcStride);
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x1002FE60
// Name: GetImageFormat
// Source: json
//------------------------------------------------------------------------------
ImageFormat __usercall GetImageFormat@<eax>(IDirect3DBaseTexture9 *pTexture@<esi>)
{
  _D3DRESOURCETYPE v1; // eax
  IDirect3DBaseTexture9_vtbl *v2; // edx
  int v3; // eax
  _D3DVOLUME_DESC desc; // [esp+10h] [ebp-24h] BYREF

  if ( pTexture != nullptr )
  {
    v1 = pTexture->GetType(this: pTexture);
    v2 = pTexture->__vftable;
    if ( v1 == D3DRTYPE_VOLUMETEXTURE )
    {
      if ( v2[1].QueryInterface(this: pTexture, a2: nullptr, a3: (void **)&desc.Type) >= 0 )
        return ImageLoader::D3DFormatToImageFormat(format: (_D3DFORMAT)desc.Type);
    }
    else
    {
      v3 = v2->GetType(this: pTexture) - 3;
      if ( (v3 == 0 || v3 == 2)
        && pTexture->__vftable[1].QueryInterface(this: pTexture, a2: nullptr, a3: (void **)&desc.Type) >= 0 )
      {
        return ImageLoader::D3DFormatToImageFormat(format: (_D3DFORMAT)desc.Type);
      }
    }
  }
  return IMAGE_FORMAT_UNKNOWN;
}

//------------------------------------------------------------------------------
// Address: 0x1002FEE0
// Name: struct IDirect3DBaseTexture9 __near * CreateD3DTexture(int,int,int,enum ImageFormat,int,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
IDirect3DBaseTexture9 *__cdecl CreateD3DTexture(
        unsigned int width,
        unsigned int height,
        _D3DPOOL nDepth,
        ImageFormat dstFormat,
        unsigned int numLevels,
        int nCreationFlags)
{
  bool v7; // bl
  _D3DFORMAT NearestSupportedFormat; // eax
  _D3DFORMAT v9; // esi
  int v11; // ebp
  D3DDeviceWrapper *v12; // edi
  int v13; // eax
  void *v14; // ecx
  D3DDeviceWrapper *v15; // edi
  D3DDeviceWrapper *v16; // edi
  bool bIsRenderTarget; // [esp+1Ch] [ebp-14h]
  char v18; // [esp+1Dh] [ebp-13h]
  char v19; // [esp+1Fh] [ebp-11h]
  bool pD3DCubeTexture; // [esp+20h] [ebp-10h]
  IDirect3DVolumeTexture9 *pD3DVolumeTexture; // [esp+24h] [ebp-Ch] BYREF
  IDirect3DTexture9 *pD3DTexture; // [esp+28h] [ebp-8h] BYREF
  void *v23; // [esp+2Ch] [ebp-4h] BYREF
  _D3DPOOL d3dPool; // [esp+3Ch] [ebp+Ch]
  bool bIsDynamic; // [esp+48h] [ebp+18h]

  if ( nDepth <= D3DPOOL_DEFAULT )
    nDepth = D3DPOOL_MANAGED;
  v18 = nCreationFlags & 1;
  pD3DCubeTexture = (nCreationFlags & 2) != 0;
  bIsDynamic = (nCreationFlags & 0x10) != 0;
  bIsRenderTarget = (nCreationFlags & 0x20) != 0;
  v7 = (nCreationFlags & 4) != 0;
  v19 = BYTE2(nCreationFlags) & 1;
  NearestSupportedFormat = FindNearestSupportedFormat(
                             format: dstFormat,
                             bIsVertexTexture: (nCreationFlags & 0x40) != 0,
                             bIsRenderTarget: pD3DCubeTexture,
                             bFilterableRequired: (nCreationFlags & 0x1000) != 0);
  v9 = NearestSupportedFormat;
  if ( NearestSupportedFormat == D3DFMT_UNKNOWN )
  {
    _Warning(a1: "ShaderAPIDX8::CreateD3DTexture: Invalid color format!\n");
    return nullptr;
  }
  v23 = nullptr;
  pD3DVolumeTexture = nullptr;
  pD3DTexture = nullptr;
  v11 = pD3DCubeTexture;
  if ( bIsDynamic )
    v11 |= 0x200u;
  if ( bIsRenderTarget )
    v11 |= 0x400u;
  if ( v18 != 0 )
  {
    v12 = Dx9Device();
    D3DDeviceWrapper::Synchronize(this: v12);
    v13 = v12->m_pD3DDevice->CreateCubeTexture(
            this: v12->m_pD3DDevice,
            a2: width,
            a3: numLevels,
            a4: v11,
            a5: v9,
            a6: (_D3DPOOL)v7,
            a7: (IDirect3DCubeTexture9 **)&pD3DVolumeTexture,
            a8: nullptr);
    v14 = pD3DVolumeTexture;
  }
  else if ( nDepth <= D3DPOOL_MANAGED )
  {
    if ( NearestSupportedFormat == 1515667794
      || NearestSupportedFormat == 1515474505
      || NearestSupportedFormat == D3DFMT_D16
      || NearestSupportedFormat == D3DFMT_D24S8
      || NearestSupportedFormat == 909198916
      || NearestSupportedFormat == 875710020 )
    {
      v11 = 2;
      v7 = false;
    }
    if ( NearestSupportedFormat == 1280070990 )
      v7 = false;
    if ( v19 != 0 )
      d3dPool = D3DPOOL_SYSTEMMEM;
    else
      d3dPool = v7;
    v16 = Dx9Device();
    D3DDeviceWrapper::Synchronize(this: v16);
    v13 = v16->m_pD3DDevice->CreateTexture(
            this: v16->m_pD3DDevice,
            a2: width,
            a3: height,
            a4: numLevels,
            a5: v11,
            a6: v9,
            a7: d3dPool,
            a8: (IDirect3DTexture9 **)&v23,
            a9: nullptr);
    v14 = v23;
  }
  else
  {
    v15 = Dx9Device();
    D3DDeviceWrapper::Synchronize(this: v15);
    v13 = v15->m_pD3DDevice->CreateVolumeTexture(
            this: v15->m_pD3DDevice,
            a2: width,
            a3: height,
            a4: nDepth,
            a5: numLevels,
            a6: v11,
            a7: v9,
            a8: (_D3DPOOL)v7,
            a9: (IDirect3DVolumeTexture9 **)&pD3DTexture,
            a10: nullptr);
    v14 = pD3DTexture;
  }
  if ( v13 >= 0 )
  {
    ++s_TextureCount;
    return (IDirect3DBaseTexture9 *)v14;
  }
  else
  {
    switch ( v13 )
    {
      case -2147024882:
        _Warning(a1: "ShaderAPIDX8::CreateD3DTexture: E_OUTOFMEMORY\n");
        break;
      case -2005532292:
        if ( v7 )
        {
          _Warning(a1: "ShaderAPIDX8::CreateD3DTexture: D3DERR_OUTOFVIDEOMEMORY\n");
          return nullptr;
        }
        break;
      case -2005530516:
        _Warning(a1: "ShaderAPIDX8::CreateD3DTexture: D3DERR_INVALIDCALL\n");
        return nullptr;
      default:
        break;
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030160
// Name: void DestroyD3DTexture(struct IDirect3DBaseTexture9 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyD3DTexture(IDirect3DBaseTexture9 *pD3DTex)
{
  if ( pD3DTex != nullptr )
  {
    pD3DTex->Release(this: pD3DTex);
    --s_TextureCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030180
// Name: bool LockTexture(int,int,struct IDirect3DBaseTexture9 __near *,int,enum _D3DCUBEMAP_FACES,int,int,int,int,bool,class CPixelWriter __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LockTexture(
        int bindId,
        int copy,
        IDirect3DSurface9 *pTexture,
        int level,
        _D3DCUBEMAP_FACES cubeFaceID,
        int xOffset,
        int yOffset,
        int width,
        int height,
        bool bDiscard,
        CPixelWriter *writer)
{
  IDirect3DBaseTexture9 *v11; // esi
  __int32 v12; // eax
  int v13; // eax
  bool result; // al
  int v15; // edi
  unsigned __int8 *pBits; // edi
  ImageFormat ImageFormat; // eax
  CPixelWriter *v18; // esi
  ImageFormat v19; // ebp
  unsigned __int16 Pitch; // [esp+8h] [ebp-4h]

  v11 = (IDirect3DBaseTexture9 *)pTexture;
  if ( pTexture == nullptr )
    return false;
  v12 = pTexture->GetType(this: pTexture) - 3;
  if ( v12 != 0 )
  {
    if ( v12 != 2 )
      return false;
    v13 = ((int (__stdcall *)(IDirect3DBaseTexture9 *, _D3DCUBEMAP_FACES, int, IDirect3DSurface9 **))v11->__vftable[1].AddRef)(
            a1: v11,
            a2: cubeFaceID,
            a3: level,
            a4: &pTexture);
  }
  else
  {
    v13 = ((int (__stdcall *)(IDirect3DBaseTexture9 *, int, IDirect3DSurface9 **))v11->__vftable[1].AddRef)(
            a1: v11,
            a2: level,
            a3: &pTexture);
  }
  if ( v13 < 0 )
    return false;
  s_LockedSrcRect.left = xOffset;
  s_LockedSrcRect.right = width + xOffset;
  s_LockedSrcRect.top = yOffset;
  s_LockedSrcRect.bottom = height + yOffset;
  v15 = pTexture->LockRect(this: pTexture, a2: &s_LockedRect, a3: &s_LockedSrcRect, a4: (bDiscard ? 0x2000 : 0) | 0x800);
  pTexture->Release(this: pTexture);
  if ( v15 < 0 )
    return false;
  pBits = (unsigned __int8 *)s_LockedRect.pBits;
  Pitch = s_LockedRect.Pitch;
  ImageFormat = GetImageFormat(pTexture: v11);
  v18 = writer;
  v19 = ImageFormat;
  writer->m_pBits = pBits;
  v18->m_pBase = pBits;
  v18->m_BytesPerRow = Pitch;
  v18->m_nFlags = 0;
  switch ( ImageFormat )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      v18->m_RShift = 0;
      v18->m_RMask = 255;
      v18->m_GMask = 255;
      v18->m_BMask = 255;
      v18->m_AMask = 255;
      v18->m_Size = 4;
      v18->m_GShift = 8;
      v18->m_BShift = 16;
      v18->m_AShift = 24;
      result = true;
      break;
    case IMAGE_FORMAT_BGR888:
      v18->m_Size = 3;
      v18->m_AShift = 0;
      goto LABEL_18;
    case IMAGE_FORMAT_I8:
      v18->m_RShift = 0;
      v18->m_GShift = 0;
      v18->m_BShift = 0;
      v18->m_AShift = 0;
      v18->m_GMask = 0;
      v18->m_BMask = 0;
      v18->m_AMask = 0;
      v18->m_Size = 1;
      v18->m_RMask = 255;
      result = true;
      break;
    case IMAGE_FORMAT_A8:
      v18->m_RShift = 0;
      v18->m_GShift = 0;
      v18->m_BShift = 0;
      v18->m_AShift = 0;
      v18->m_RMask = 0;
      v18->m_GMask = 0;
      v18->m_BMask = 0;
      v18->m_Size = 1;
      v18->m_AMask = 255;
      result = true;
      break;
    case IMAGE_FORMAT_BGRA8888:
      v18->m_BShift = 0;
      v18->m_RMask = 255;
      v18->m_GMask = 255;
      v18->m_BMask = 255;
      v18->m_AMask = 255;
      v18->m_Size = 4;
      v18->m_RShift = 16;
      v18->m_GShift = 8;
      v18->m_AShift = 24;
      result = true;
      break;
    case IMAGE_FORMAT_BGRX8888:
      v18->m_Size = 4;
      v18->m_AShift = 24;
LABEL_18:
      v18->m_BShift = 0;
      v18->m_GMask = 255;
      v18->m_RMask = 255;
      v18->m_BMask = 255;
      v18->m_AMask = 0;
      v18->m_GShift = 8;
      v18->m_RShift = 16;
      result = true;
      break;
    case IMAGE_FORMAT_BGR565:
      v18->m_AShift = 0;
      v18->m_RMask = 248;
      v18->m_BMask = 248;
      v18->m_AMask = 0;
      v18->m_Size = 2;
      v18->m_RShift = 8;
      v18->m_GShift = 3;
      v18->m_BShift = -3;
      v18->m_GMask = 252;
      result = true;
      break;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      v18->m_RMask = 248;
      v18->m_GMask = 248;
      v18->m_BMask = 248;
      v18->m_Size = 2;
      v18->m_RShift = 7;
      v18->m_GShift = 2;
      v18->m_BShift = -3;
      v18->m_AShift = 8;
      v18->m_AMask = 128;
      result = true;
      break;
    case IMAGE_FORMAT_BGRA4444:
      v18->m_GShift = 0;
      v18->m_RMask = 240;
      v18->m_GMask = 240;
      v18->m_BMask = 240;
      v18->m_AMask = 240;
      v18->m_Size = 2;
      v18->m_RShift = 4;
      v18->m_BShift = -4;
      v18->m_AShift = 8;
      result = true;
      break;
    case IMAGE_FORMAT_RGBA16161616F:
      v18->m_RShift = 0;
      v18->m_RMask = 0xFFFF;
      v18->m_GMask = 0xFFFF;
      v18->m_BMask = 0xFFFF;
      v18->m_AMask = 0xFFFF;
      v18->m_Size = 8;
      v18->m_GShift = 16;
      v18->m_BShift = 32;
      v18->m_AShift = 48;
      v18->m_nFlags = 3;
      result = true;
      break;
    case IMAGE_FORMAT_RGBA16161616:
      v18->m_RShift = 0;
      v18->m_RMask = 0xFFFF;
      v18->m_GMask = 0xFFFF;
      v18->m_BMask = 0xFFFF;
      v18->m_AMask = 0xFFFF;
      v18->m_Size = 8;
      v18->m_GShift = 16;
      v18->m_BShift = 32;
      v18->m_AShift = 48;
      result = true;
      break;
    case IMAGE_FORMAT_R32F:
      v18->m_RShift = 0;
      v18->m_GShift = 0;
      v18->m_BShift = 0;
      v18->m_AShift = 0;
      v18->m_GMask = 0;
      v18->m_BMask = 0;
      v18->m_AMask = 0;
      v18->m_Size = 4;
      v18->m_RMask = -1;
      v18->m_nFlags = 1;
      result = true;
      break;
    case IMAGE_FORMAT_RGBA32323232F:
      v18->m_RShift = 0;
      v18->m_RMask = -1;
      v18->m_GMask = -1;
      v18->m_BMask = -1;
      v18->m_AMask = -1;
      v18->m_Size = 16;
      v18->m_GShift = 32;
      v18->m_BShift = 64;
      v18->m_AShift = 96;
      v18->m_nFlags = 1;
      result = true;
      break;
    case IMAGE_FORMAT_BGRA1010102:
      v18->m_BShift = 0;
      v18->m_RMask = 1023;
      v18->m_GMask = 1023;
      v18->m_BMask = 1023;
      v18->m_Size = 4;
      v18->m_RShift = 20;
      v18->m_GShift = 10;
      v18->m_AShift = 30;
      v18->m_AMask = 3;
      result = true;
      break;
    default:
      if ( `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[ImageFormat] == 0 )
      {
        _Msg(a1: "CPixelWriter::SetPixelMemory:  Unsupported image format %i\n", ImageFormat);
        `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v19] = 1;
      }
      v18->m_Size = 0;
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100305C0
// Name: void UnlockTexture(int,int,struct IDirect3DBaseTexture9 __near *,int,enum _D3DCUBEMAP_FACES)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnlockTexture(int bindId, int copy, IDirect3DSurface9 *pTexture, int level, _D3DCUBEMAP_FACES cubeFaceID)
{
  IDirect3DSurface9 *v5; // esi
  __int32 v6; // eax
  int v7; // eax

  v5 = pTexture;
  if ( pTexture != nullptr )
  {
    v6 = pTexture->GetType(this: pTexture) - 3;
    if ( v6 != 0 )
    {
      if ( v6 != 2 )
        return;
      v7 = ((int (__stdcall *)(IDirect3DSurface9 *, _D3DCUBEMAP_FACES, int, IDirect3DSurface9 **))v5->__vftable[1].AddRef)(
             a1: v5,
             a2: cubeFaceID,
             a3: level,
             a4: &pTexture);
    }
    else
    {
      v7 = ((int (__stdcall *)(IDirect3DSurface9 *, int, IDirect3DSurface9 **))v5->__vftable[1].AddRef)(
             a1: v5,
             a2: level,
             a3: &pTexture);
    }
    if ( v7 >= 0 )
    {
      pTexture->UnlockRect(this: pTexture);
      pTexture->Release(this: pTexture);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030630
// Name: BlitSurfaceBits
// Source: json
//------------------------------------------------------------------------------
void __usercall BlitSurfaceBits(TextureLoadInfo_t *info@<edi>, int xOffset, int yOffset, int srcStride)
{
  int m_nLevel; // ebx
  _D3DCUBEMAP_FACES m_CubeFaceID; // ebp
  IDirect3DBaseTexture9 *m_pTexture; // esi
  int v7; // eax
  int v8; // eax
  int m_nHeight; // ecx
  int v10; // edx
  ImageFormat ImageFormat; // eax
  _D3DLOCKED_RECT lockedRect; // [esp+44h] [ebp-1Ch] BYREF
  tagRECT srcRect; // [esp+4Ch] [ebp-14h] BYREF
  int v14; // [esp+5Ch] [ebp-4h]

  m_nLevel = info->m_nLevel;
  m_CubeFaceID = info->m_CubeFaceID;
  m_pTexture = info->m_pTexture;
  if ( m_pTexture != nullptr )
  {
    v7 = m_pTexture->GetType(this: info->m_pTexture) - 3;
    if ( v7 != 0 )
    {
      if ( v7 != 2 )
        return;
      v8 = ((int (__stdcall *)(IDirect3DBaseTexture9 *, _D3DCUBEMAP_FACES, int, _D3DLOCKED_RECT *))m_pTexture->__vftable[1].AddRef)(
             a1: m_pTexture,
             a2: m_CubeFaceID,
             a3: m_nLevel,
             a4: &lockedRect);
    }
    else
    {
      v8 = ((int (__stdcall *)(IDirect3DBaseTexture9 *, int, _D3DLOCKED_RECT *))m_pTexture->__vftable[1].AddRef)(
             a1: m_pTexture,
             a2: m_nLevel,
             a3: &lockedRect);
    }
    if ( v8 >= 0 )
    {
      m_nHeight = info->m_nHeight;
      v10 = xOffset + info->m_nWidth;
      srcRect.top = xOffset;
      v14 = yOffset + m_nHeight;
      srcRect.right = yOffset;
      srcRect.bottom = v10;
      if ( (*(int (__stdcall **)(int, void **, int *, int))(*(_DWORD *)lockedRect.Pitch + 52))(
             a1: lockedRect.Pitch,
             a2: &lockedRect.pBits,
             a3: &srcRect.top,
             a4: 2048) >= 0 )
      {
        ImageFormat = GetImageFormat(pTexture: info->m_pTexture);
        g_pShaderUtil->ConvertImageFormat(
          this: g_pShaderUtil,
          a2: info->m_pSrcData,
          a3: info->m_SrcFormat,
          a4: (unsigned __int8 *)srcRect.left,
          a5: ImageFormat,
          a6: info->m_nWidth,
          a7: info->m_nHeight,
          a8: srcStride,
          a9: (int)lockedRect.pBits);
        if ( (*(int (__stdcall **)(int))(*(_DWORD *)lockedRect.Pitch + 56))(a1: lockedRect.Pitch) < 0 )
          _Warning(a1: "CShaderAPIDX8::BlitTextureBits: couldn't unlock texture rect\n");
      }
      else
      {
        _Warning(a1: "CShaderAPIDX8::BlitTextureBits: couldn't lock texture rect\n");
      }
      (*(void (__stdcall **)(int))(*(_DWORD *)lockedRect.Pitch + 8))(a1: lockedRect.Pitch);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030740
// Name: BlitVolumeBits
// Source: json
//------------------------------------------------------------------------------
void __usercall BlitVolumeBits(
        TextureLoadInfo_t *info@<edi>,
        unsigned int xOffset@<ecx>,
        unsigned int yOffset@<eax>,
        int srcStride)
{
  unsigned int v4; // edx
  unsigned int v5; // ecx
  IDirect3DBaseTexture9 *m_pTexture; // ebx
  int m_nLevel; // eax
  ImageFormat ImageFormat; // eax
  _D3DLOCKED_BOX lockedBox; // [esp+10h] [ebp-28h] BYREF
  _D3DBOX srcBox; // [esp+1Ch] [ebp-1Ch] BYREF
  unsigned int v11; // [esp+34h] [ebp-4h]

  v4 = xOffset + info->m_nWidth;
  srcBox.Top = xOffset;
  v5 = yOffset + info->m_nHeight;
  srcBox.Right = yOffset;
  m_pTexture = info->m_pTexture;
  srcBox.Back = info->m_nZOffset;
  v11 = srcBox.Back + 1;
  srcBox.Front = v5;
  m_nLevel = info->m_nLevel;
  srcBox.Bottom = v4;
  if ( ((int (__stdcall *)(IDirect3DBaseTexture9 *, int, int *, unsigned int *, int))m_pTexture->__vftable[1].Release)(
         a1: m_pTexture,
         a2: m_nLevel,
         a3: &lockedBox.SlicePitch,
         a4: &srcBox.Top,
         a5: 2048) >= 0 )
  {
    ImageFormat = GetImageFormat(pTexture: info->m_pTexture);
    g_pShaderUtil->ConvertImageFormat(
      this: g_pShaderUtil,
      a2: info->m_pSrcData,
      a3: info->m_SrcFormat,
      a4: (unsigned __int8 *)srcBox.Left,
      a5: ImageFormat,
      a6: info->m_nWidth,
      a7: info->m_nHeight,
      a8: srcStride,
      a9: lockedBox.SlicePitch);
    if ( m_pTexture->__vftable[1].GetDevice(this: m_pTexture, a2: (IDirect3DDevice9 **)info->m_nLevel) < 0 )
      _Warning(a1: "BlitVolumeBits: couldn't unlock volume texture rect\n");
  }
  else
  {
    _Warning(a1: "BlitVolumeBits: couldn't lock volume texture rect\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030800
// Name: void LoadTexture(struct TextureLoadInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadTexture(TextureLoadInfo_t *info)
{
  IDirect3DBaseTexture9 *m_pTexture; // eax

  m_pTexture = info->m_pTexture;
  if ( m_pTexture != nullptr && m_pTexture->GetType(this: info->m_pTexture) == D3DRTYPE_VOLUMETEXTURE )
    BlitVolumeBits(info, xOffset: 0, yOffset: 0, srcStride: 0);
  else
    BlitSurfaceBits(info, xOffset: 0, yOffset: 0, srcStride: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10030840
// Name: void LoadSubTexture(struct TextureLoadInfo_t __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadSubTexture(TextureLoadInfo_t *info, int xOffset, int yOffset, int srcStride)
{
  IDirect3DBaseTexture9 *m_pTexture; // eax

  m_pTexture = info->m_pTexture;
  if ( m_pTexture != nullptr && m_pTexture->GetType(this: info->m_pTexture) == D3DRTYPE_VOLUMETEXTURE )
    BlitVolumeBits(info, xOffset, yOffset, srcStride);
  else
    BlitSurfaceBits(info, xOffset, yOffset, srcStride);
}

} // namespace shaderapidx10
