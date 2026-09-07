// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/ccolorcorrection.cpp
// Functions: 38
// ============================================================

#include "materialsystem\ccolorcorrection.h"

//------------------------------------------------------------------------------
// Address: 0x100176B0
// Name: public: ColorCorrectionLookup_t::~ColorCorrectionLookup_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ColorCorrectionLookup_t::~ColorCorrectionLookup_t(ColorCorrectionLookup_t *this)
{
  int i; // esi

  if ( this->m_pColorCorrectionTexture != nullptr )
  {
    for ( i = 0; i < 4; ++i )
    {
      if ( this->m_pColorCorrectionTexture == g_pTextureManager->ColorCorrectionTexture(this: g_pTextureManager, a2: i) )
        g_pTextureManager->SetColorCorrectionTexture(this: g_pTextureManager, a2: i, a3: nullptr);
    }
    this->m_pColorCorrectionTexture->DecrementReferenceCount(this: this->m_pColorCorrectionTexture);
    ITextureInternal::Destroy(pTex: this->m_pColorCorrectionTexture);
    this->m_pColorCorrectionTexture = nullptr;
  }
  free(pMem: this->m_pColorCorrection);
}

//------------------------------------------------------------------------------
// Address: 0x10017730
// Name: void ReleaseColorCorrection(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseColorCorrection(char nChangeFlags)
{
  if ( (nChangeFlags & 1) == 0 )
    g_pColorCorrectionSystem->ReleaseTextures(this: g_pColorCorrectionSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10017750
// Name: void RestoreColorCorrection(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RestoreColorCorrection(char nChangeFlags)
{
  if ( (nChangeFlags & 1) == 0 )
    g_pColorCorrectionSystem->RestoreTextures(this: g_pColorCorrectionSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10017770
// Name: public: virtual void CColorCorrectionSystem::EnableColorCorrection(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::EnableColorCorrection(CColorCorrectionSystem *this, bool bEnable)
{
  this->m_bEnabled = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10017780
// Name: int CompareLookups(struct ColorCorrectionLookup_t __near * const __near *,struct ColorCorrectionLookup_t __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareLookups(ColorCorrectionLookup_t *const *lookup_a, ColorCorrectionLookup_t *const *lookup_b)
{
  float m_flWeight; // xmm0_4
  float v3; // xmm1_4

  m_flWeight = (*lookup_a)->m_flWeight;
  v3 = (*lookup_b)->m_flWeight;
  if ( v3 > m_flWeight )
    return 1;
  if ( m_flWeight <= v3 )
    return 0;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100177C0
// Name: public: virtual struct color24 CColorCorrectionSystem::ConvertToColor24(struct RGBX5551_t)
// Source: json
//------------------------------------------------------------------------------
color24 *__thiscall CColorCorrectionSystem::ConvertToColor24(
        CColorCorrectionSystem *this,
        color24 *__return_ptr retstr,
        unsigned int inColor)
{
  retstr->r = (8 * inColor) | ((unsigned __int8)inColor >> 2) & 7;
  retstr->g = (8 * (inColor >> 5)) | (inColor >> 7) & 7;
  retstr->b = (8 * ((unsigned __int16)inColor >> 10)) | (inColor >> 12) & 7;
  return retstr;
}

//------------------------------------------------------------------------------
// Address: 0x10017830
// Name: public: virtual void CColorCorrectionRegen::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionRegen::RegenerateTextureBits(
        CColorCorrectionRegen *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pSubRect)
{
  IVTFTexture *v4; // esi
  __int16 v5; // di
  int v6; // eax
  _BYTE *v7; // ebx
  __int16 v8; // ax
  unsigned int v9; // edx
  unsigned int v10; // edx
  int v11; // eax
  unsigned __int64 v12; // kr00_8
  unsigned __int64 v13; // rax
  int v14; // ebx
  int v15; // esi
  __int64 v16; // rax
  __int64 v17; // rax
  unsigned __int64 v18; // rax
  int v19; // ebx
  int v20; // esi
  int pixelWriter; // [esp+8h] [ebp-64h]
  _DWORD *pixelWriter_4; // [esp+Ch] [ebp-60h]
  unsigned __int8 pixelWriter_10; // [esp+12h] [ebp-5Ah]
  int pixelWriter_12; // [esp+14h] [ebp-58h]
  int pixelWriter_16; // [esp+18h] [ebp-54h]
  char pixelWriter_20; // [esp+1Ch] [ebp-50h]
  char pixelWriter_24; // [esp+20h] [ebp-4Ch]
  char pixelWriter_28; // [esp+24h] [ebp-48h]
  unsigned __int8 pixelWriter_32; // [esp+28h] [ebp-44h]
  __int64 v30; // [esp+2Ch] [ebp-40h]
  int nDepth; // [esp+34h] [ebp-38h]
  int v32; // [esp+38h] [ebp-34h]
  __int16 i; // [esp+44h] [ebp-28h]
  int nHeight; // [esp+48h] [ebp-24h]
  unsigned __int16 v36; // [esp+4Ch] [ebp-20h]
  int v37; // [esp+4Ch] [ebp-20h]
  int y; // [esp+50h] [ebp-1Ch]
  int nWidth; // [esp+54h] [ebp-18h]
  RGBX5551_t inColor; // [esp+58h] [ebp-14h]
  int x; // [esp+5Ch] [ebp-10h]
  int z; // [esp+64h] [ebp-8h]
  color24 col; // [esp+68h] [ebp-4h] BYREF

  v4 = pVTFTexture;
  nWidth = pVTFTexture->Width(this: pVTFTexture);
  nHeight = v4->Height(this: v4);
  nDepth = v4->Depth(this: v4);
  z = 0;
  if ( nDepth > 0 )
  {
    while ( 2 )
    {
      v36 = v4->RowSizeInBytes(this: v4, a2: 0);
      pixelWriter = (int)v4->ImageData(this: v4, a2: 0, a3: 0, a4: 0, a5: 0, a6: 0, a7: z);
      switch ( v4->Format(this: v4) )
      {
        case IMAGE_FORMAT_RGBA8888:
        case IMAGE_FORMAT_UVWQ8888:
          pixelWriter_12 = 0x80000;
          v5 = 16;
          pixelWriter_16 = 1572880;
          goto LABEL_7;
        case IMAGE_FORMAT_BGR888:
          pixelWriter_10 = 3;
          pixelWriter_12 = 524304;
          pixelWriter_20 = -1;
          pixelWriter_24 = -1;
          pixelWriter_28 = -1;
          goto LABEL_20;
        case IMAGE_FORMAT_I8:
          pixelWriter_10 = 1;
          goto LABEL_18;
        case IMAGE_FORMAT_A8:
          v5 = 0;
          pixelWriter_10 = 1;
          pixelWriter_12 = 0;
          pixelWriter_16 = 0;
          pixelWriter_20 = 0;
          pixelWriter_24 = 0;
          pixelWriter_28 = 0;
          pixelWriter_32 = -1;
          goto LABEL_22;
        case IMAGE_FORMAT_BGRA8888:
          pixelWriter_12 = 524304;
          v5 = 0;
          pixelWriter_16 = 1572864;
LABEL_7:
          pixelWriter_10 = 4;
          pixelWriter_20 = -1;
          pixelWriter_24 = -1;
          pixelWriter_28 = -1;
          pixelWriter_32 = -1;
          goto LABEL_22;
        case IMAGE_FORMAT_BGRX8888:
          pixelWriter_10 = 4;
          pixelWriter_12 = 524304;
          v5 = 0;
          pixelWriter_16 = 1572864;
          pixelWriter_20 = -1;
          pixelWriter_24 = -1;
          pixelWriter_28 = -1;
          goto LABEL_21;
        case IMAGE_FORMAT_BGR565:
          pixelWriter_10 = 2;
          pixelWriter_12 = 196616;
          v5 = -3;
          pixelWriter_16 = 65533;
          pixelWriter_20 = -8;
          pixelWriter_24 = -4;
          pixelWriter_28 = -8;
          goto LABEL_21;
        case IMAGE_FORMAT_BGRX5551:
        case IMAGE_FORMAT_BGRA5551:
          pixelWriter_10 = 2;
          pixelWriter_12 = 131079;
          v5 = -3;
          pixelWriter_16 = 589821;
          pixelWriter_20 = -8;
          pixelWriter_24 = -8;
          pixelWriter_28 = -8;
          pixelWriter_32 = 0x80;
          goto LABEL_22;
        case IMAGE_FORMAT_BGRA4444:
          pixelWriter_10 = 2;
          pixelWriter_12 = 4;
          v5 = -4;
          pixelWriter_16 = 589820;
          pixelWriter_20 = -16;
          pixelWriter_24 = -16;
          pixelWriter_28 = -16;
          pixelWriter_32 = -16;
          goto LABEL_22;
        case IMAGE_FORMAT_RGBA16161616F:
        case IMAGE_FORMAT_RGBA16161616:
          pixelWriter_10 = 8;
          pixelWriter_12 = 0x100000;
          v5 = 32;
          pixelWriter_16 = 3145760;
          pixelWriter_20 = -1;
          pixelWriter_24 = -1;
          pixelWriter_28 = -1;
          pixelWriter_32 = -1;
          goto LABEL_22;
        case IMAGE_FORMAT_R32F:
          pixelWriter_10 = 4;
          pixelWriter_20 = -1;
          goto LABEL_19;
        case IMAGE_FORMAT_RGBA32323232F:
          pixelWriter_10 = 16;
          pixelWriter_12 = 0x200000;
          v5 = 64;
          pixelWriter_16 = 6291520;
          pixelWriter_20 = -1;
          pixelWriter_24 = -1;
          pixelWriter_28 = -1;
          pixelWriter_32 = -1;
          goto LABEL_22;
        case IMAGE_FORMAT_BGRA1010102:
          pixelWriter_10 = 4;
          pixelWriter_12 = 655380;
          v5 = 0;
          pixelWriter_16 = 1966080;
          pixelWriter_20 = -1;
          pixelWriter_24 = -1;
          pixelWriter_28 = -1;
          pixelWriter_32 = 3;
          goto LABEL_22;
        default:
          pixelWriter_10 = 0;
LABEL_18:
          pixelWriter_20 = -1;
LABEL_19:
          pixelWriter_12 = 0;
          pixelWriter_24 = 0;
          pixelWriter_28 = 0;
LABEL_20:
          v5 = 0;
          pixelWriter_16 = 0;
LABEL_21:
          pixelWriter_32 = 0;
LABEL_22:
          v6 = 0;
          y = 0;
          if ( nHeight > 0 )
          {
            v7 = (_BYTE *)pixelWriter;
            v32 = v36;
            v37 = pixelWriter;
            do
            {
              pixelWriter_4 = v7;
              x = 0;
              if ( nWidth > 0 )
              {
                v8 = 32 * ((32 * (z & 0x1F)) | v6 & 0x1F);
                for ( i = v8; ; v8 = i )
                {
                  inColor = (RGBX5551_t)(v8 | *(_WORD *)&inColor & 0x8000 | x & 0x1F);
                  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _WORD))g_pColorCorrectionSystem->GetLookup)(
                    a1: g_pColorCorrectionSystem,
                    a2: &col,
                    a3: this->m_ColorCorrectionHandle,
                    a4: inColor);
                  if ( pixelWriter_10 != 0 )
                  {
                    if ( pixelWriter_10 >= 5u )
                    {
                      v12 = (unsigned __int64)(unsigned __int8)(col.g & pixelWriter_24) << SBYTE2(pixelWriter_12);
                      v13 = (unsigned __int64)(unsigned __int8)(col.r & pixelWriter_20) << pixelWriter_12;
                      v14 = v13 | v12;
                      v15 = HIDWORD(v13) | HIDWORD(v12);
                      v16 = (unsigned __int8)(col.b & pixelWriter_28);
                      if ( v5 <= 0 )
                        v17 = v16 >> -(char)v5;
                      else
                        v17 = v16 << v5;
                      v30 = v17;
                      v18 = (unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16);
                      v19 = v30 | v18 | v14;
                      v20 = HIDWORD(v30) | HIDWORD(v18) | v15;
                      if ( pixelWriter_10 == 8 )
                      {
                        *pixelWriter_4 = v19;
                        pixelWriter_4[1] = v20;
                      }
                      v7 = pixelWriter_4;
                    }
                    else
                    {
                      v9 = (unsigned __int8)(col.b & pixelWriter_28);
                      if ( v5 <= 0 )
                        v10 = v9 >> -(char)pixelWriter_16;
                      else
                        v10 = v9 << pixelWriter_16;
                      v11 = v10
                          | (pixelWriter_32 << SBYTE2(pixelWriter_16))
                          | ((unsigned __int8)(col.r & pixelWriter_20) << pixelWriter_12)
                          | ((unsigned __int8)(col.g & pixelWriter_24) << SBYTE2(pixelWriter_12));
                      switch ( pixelWriter_10 )
                      {
                        case 1u:
                          *v7 = v11;
                          break;
                        case 2u:
                          *(_WORD *)v7 = v11;
                          break;
                        case 3u:
                          *(_WORD *)v7 = v11;
                          v7[2] = BYTE2(v11);
                          break;
                        case 4u:
                          *(_DWORD *)v7 = v11;
                          break;
                      }
                    }
                  }
                  v7 += pixelWriter_10;
                  pixelWriter_4 = v7;
                  if ( ++x >= nWidth )
                    break;
                }
                v4 = pVTFTexture;
                v6 = y;
              }
              v7 = (_BYTE *)(v32 + v37);
              y = ++v6;
              v37 += v32;
            }
            while ( v6 < nHeight );
          }
          if ( ++z >= nDepth )
            return;
          continue;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017D10
// Name: public: void ColorCorrectionLookup_t::AllocTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ColorCorrectionLookup_t::AllocTexture(ColorCorrectionLookup_t *this)
{
  ITextureRegenerator *v2; // eax
  unsigned int v3; // ecx
  char szShortName[260]; // [esp+4h] [ebp-28Ch] BYREF
  char szFilename[260]; // [esp+108h] [ebp-188h] BYREF
  char szName[128]; // [esp+20Ch] [ebp-84h] BYREF
  unsigned int m_Handle; // [esp+28Ch] [ebp-4h] BYREF

  m_Handle = this->m_Handle;
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)&m_Handle, a3: szFilename, a4: 260);
  V_FileBase(in: szFilename, out: szShortName, maxlen: 260);
  V_snprintf(pDest: szName, maxLen: 128, pFormat: "ColorCorrection (%s)", szShortName);
  this->m_pColorCorrectionTexture = ITextureInternal::CreateProceduralTexture(
                                      pTextureName: szName,
                                      pTextureGroupName: "Other textures",
                                      w: 32,
                                      h: 32,
                                      d: 32,
                                      fmt: IMAGE_FORMAT_BGRX8888,
                                      nFlags: 33948428);
  v2 = (ITextureRegenerator *)MemAlloc_Alloc(nSize: 8u);
  if ( v2 != nullptr )
  {
    v3 = this->m_Handle;
    v2->__vftable = (ITextureRegenerator_vtbl *)&CColorCorrectionRegen::`vftable';
    v2[1].__vftable = (ITextureRegenerator_vtbl *)v3;
  }
  else
  {
    v2 = nullptr;
  }
  this->m_pColorCorrectionTexture->SetTextureRegenerator(this: this->m_pColorCorrectionTexture, a2: v2, a3: true);
  this->m_pColorCorrectionTexture->Download(this: this->m_pColorCorrectionTexture, a2: nullptr, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10017DE0
// Name: public: virtual void CColorCorrectionSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::Init(CColorCorrectionSystem *this)
{
  this->m_DefaultColorCorrectionHandle = -1;
  this->m_UnnamedColorCorrectionHandle = (unsigned int)g_pFullFileSystem->FindOrAddFileName(
                                                         this: g_pFullFileSystem,
                                                         a2: "unnamed");
  this->m_DefaultColorCorrectionWeight = 0.0;
  this->m_bEnabled = true;
  g_pInternalMaterialSystem->AddReleaseFunc(
    this: g_pInternalMaterialSystem,
    a2: (void (__cdecl *)(int))ReleaseColorCorrection);
  g_pInternalMaterialSystem->AddRestoreFunc(
    this: g_pInternalMaterialSystem,
    a2: (void (__cdecl *)(int))RestoreColorCorrection);
}

//------------------------------------------------------------------------------
// Address: 0x10017E40
// Name: public: virtual void CColorCorrectionSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::Shutdown(CColorCorrectionSystem *this)
{
  int i; // esi
  ColorCorrectionLookup_t **m_pMemory; // eax
  ColorCorrectionLookup_t *v4; // edi

  for ( i = 0; i < this->m_ColorCorrectionList.m_Size; ++i )
  {
    m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
    v4 = m_pMemory[i];
    if ( v4 != nullptr )
    {
      ColorCorrectionLookup_t::~ColorCorrectionLookup_t(this: m_pMemory[i]);
      free(pMem: v4);
    }
  }
  g_pInternalMaterialSystem->RemoveReleaseFunc(
    this: g_pInternalMaterialSystem,
    a2: (void (__cdecl *)(int))ReleaseColorCorrection);
  g_pInternalMaterialSystem->RemoveRestoreFunc(
    this: g_pInternalMaterialSystem,
    a2: (void (__cdecl *)(int))RestoreColorCorrection);
}

//------------------------------------------------------------------------------
// Address: 0x10017EA0
// Name: public: virtual float CColorCorrectionSystem::GetLookupWeight(unsigned int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CColorCorrectionSystem::GetLookupWeight(CColorCorrectionSystem *this, unsigned int handle)
{
  int m_Size; // edx
  int v4; // eax
  ColorCorrectionLookup_t **m_pMemory; // esi
  ColorCorrectionLookup_t **i; // ecx
  ColorCorrectionLookup_t *v7; // eax

  if ( handle == this->m_DefaultColorCorrectionHandle )
    return this->m_DefaultColorCorrectionWeight;
  m_Size = this->m_ColorCorrectionList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0.0;
  m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
  for ( i = m_pMemory; (*i)->m_Handle != handle; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0.0;
  }
  v7 = m_pMemory[v4];
  if ( v7 != nullptr )
    return v7->m_flWeight;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10017F00
// Name: public: virtual float CColorCorrectionSystem::GetLookupWeight(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CColorCorrectionSystem::GetLookupWeight(CColorCorrectionSystem *this, int i)
{
  if ( i >= this->m_ColorCorrectionList.m_Size )
    return 0.0;
  if ( i == -1 )
    return this->m_DefaultColorCorrectionWeight;
  return this->m_ColorCorrectionList.m_Memory.m_pMemory[i]->m_flWeight;
}

//------------------------------------------------------------------------------
// Address: 0x10017F30
// Name: public: virtual void CColorCorrectionSystem::LockLookup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::LockLookup(CColorCorrectionSystem *this, unsigned int handle)
{
  int m_Size; // edx
  int v3; // eax
  ColorCorrectionLookup_t **m_pMemory; // esi
  ColorCorrectionLookup_t **i; // ecx
  ColorCorrectionLookup_t *v6; // eax

  if ( handle != this->m_DefaultColorCorrectionHandle )
  {
    m_Size = this->m_ColorCorrectionList.m_Size;
    v3 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
      for ( i = m_pMemory; (*i)->m_Handle != handle; ++i )
      {
        if ( ++v3 >= m_Size )
          return;
      }
      v6 = m_pMemory[v3];
      if ( v6 != nullptr )
        v6->m_bLocked = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017F80
// Name: public: virtual void CColorCorrectionSystem::SetLookup(unsigned int,struct RGBX5551_t,struct color24)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::SetLookup(
        CColorCorrectionSystem *this,
        unsigned int handle,
        unsigned __int16 inColor,
        color24 outColor)
{
  int m_Size; // edx
  int v5; // eax
  ColorCorrectionLookup_t **m_pMemory; // esi
  ColorCorrectionLookup_t **i; // ecx
  ColorCorrectionLookup_t *v8; // eax
  color24 *m_pColorCorrection; // edx
  int v10; // eax

  if ( handle != this->m_DefaultColorCorrectionHandle )
  {
    m_Size = this->m_ColorCorrectionList.m_Size;
    v5 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
      for ( i = m_pMemory; (*i)->m_Handle != handle; ++i )
      {
        if ( ++v5 >= m_Size )
          return;
      }
      v8 = m_pMemory[v5];
      if ( v8 != nullptr )
      {
        m_pColorCorrection = v8->m_pColorCorrection;
        if ( m_pColorCorrection != nullptr )
        {
          v10 = (inColor & 0x1F) + 32 * (((inColor >> 5) & 0x1F) + 32 * ((inColor >> 10) & 0x1F));
          *(color24 *)((char *)m_pColorCorrection + 2 * v10 + v10) = outColor;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018000
// Name: public: virtual struct color24 CColorCorrectionSystem::GetLookup(unsigned int,struct RGBX5551_t)
// Source: json
//------------------------------------------------------------------------------
color24 *__thiscall CColorCorrectionSystem::GetLookup(
        CColorCorrectionSystem *this,
        color24 *__return_ptr retstr,
        unsigned int handle,
        int inColor)
{
  int m_Size; // edx
  int v6; // eax
  ColorCorrectionLookup_t **m_pMemory; // esi
  ColorCorrectionLookup_t **i; // ecx
  ColorCorrectionLookup_t *v9; // eax
  color24 *m_pColorCorrection; // edx
  int v11; // eax
  int v12; // ecx
  __int16 v13; // dx

  if ( handle == this->m_DefaultColorCorrectionHandle )
  {
    ((void (__thiscall *)(CColorCorrectionSystem *, unsigned int *, int))this->ConvertToColor24)(
      a1: this,
      a2: &handle,
      a3: inColor);
    *retstr = (color24)handle;
    return retstr;
  }
  else
  {
    m_Size = this->m_ColorCorrectionList.m_Size;
    v6 = 0;
    if ( m_Size <= 0 )
      goto LABEL_9;
    m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
    for ( i = m_pMemory; (*i)->m_Handle != handle; ++i )
    {
      if ( ++v6 >= m_Size )
      {
        LOWORD(inColor) = 0;
        *(_WORD *)&retstr->r = 0;
        retstr->b = 0;
        return retstr;
      }
    }
    v9 = m_pMemory[v6];
    if ( v9 != nullptr )
    {
      m_pColorCorrection = v9->m_pColorCorrection;
      if ( m_pColorCorrection != nullptr )
      {
        v11 = (inColor & 0x1F)
            + 32 * ((((unsigned __int16)inColor >> 5) & 0x1F) + 32 * (((unsigned __int16)inColor >> 10) & 0x1F));
        v12 = (int)m_pColorCorrection + 2 * v11;
        v13 = *(_WORD *)(v12 + v11);
        LOBYTE(v12) = *(_BYTE *)(v11 + v12 + 2);
        *(_WORD *)&retstr->r = v13;
        retstr->b = v12;
      }
      else
      {
        LOWORD(inColor) = 0;
        *(_WORD *)&retstr->r = 0;
        retstr->b = 0;
      }
      return retstr;
    }
    else
    {
LABEL_9:
      LOWORD(inColor) = 0;
      *(_WORD *)&retstr->r = 0;
      retstr->b = 0;
      return retstr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100180F0
// Name: public: virtual void CColorCorrectionSystem::UnlockLookup(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::UnlockLookup(CColorCorrectionSystem *this, unsigned int handle, bool bDownload)
{
  int m_Size; // edx
  int v4; // eax
  ColorCorrectionLookup_t **m_pMemory; // esi
  ColorCorrectionLookup_t **i; // ecx
  ColorCorrectionLookup_t *v7; // eax

  if ( handle != this->m_DefaultColorCorrectionHandle )
  {
    m_Size = this->m_ColorCorrectionList.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
      for ( i = m_pMemory; (*i)->m_Handle != handle; ++i )
      {
        if ( ++v4 >= m_Size )
          return;
      }
      v7 = m_pMemory[v4];
      if ( v7 != nullptr )
      {
        v7->m_bLocked = false;
        if ( bDownload )
          v7->m_pColorCorrectionTexture->Download(this: v7->m_pColorCorrectionTexture, a2: nullptr, a3: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018150
// Name: public: virtual void CColorCorrectionSystem::CopyLookup(unsigned int,struct color24 const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::CopyLookup(
        CColorCorrectionSystem *this,
        unsigned int handle,
        const color24 *pSrcColorCorrection)
{
  int m_Size; // edx
  int v4; // eax
  ColorCorrectionLookup_t **m_pMemory; // esi
  ColorCorrectionLookup_t **i; // ecx
  ColorCorrectionLookup_t *v7; // eax
  color24 *m_pColorCorrection; // eax

  if ( handle != this->m_DefaultColorCorrectionHandle )
  {
    m_Size = this->m_ColorCorrectionList.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
      for ( i = m_pMemory; (*i)->m_Handle != handle; ++i )
      {
        if ( ++v4 >= m_Size )
          return;
      }
      v7 = m_pMemory[v4];
      if ( v7 != nullptr )
      {
        m_pColorCorrection = v7->m_pColorCorrection;
        if ( m_pColorCorrection != nullptr )
          _V_memcpy(dest: m_pColorCorrection, src: pSrcColorCorrection, count: 98304);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100181B0
// Name: public: virtual void CColorCorrectionSystem::ResetLookup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::ResetLookup(CColorCorrectionSystem *this, unsigned int handle)
{
  CColorCorrectionSystem *v2; // ebx
  int m_Size; // edx
  int v4; // eax
  ColorCorrectionLookup_t **i; // ecx
  __int16 v6; // si
  __int16 v7; // si
  RGBX5551_t v8; // si
  color24 *m_pColorCorrection; // edx
  int v10; // eax
  int v11; // ecx
  bool v12; // zf
  ColorCorrectionLookup_t *lookup; // [esp+Ch] [ebp-18h]
  int j; // [esp+10h] [ebp-14h]
  int k; // [esp+14h] [ebp-10h]
  int v17; // [esp+18h] [ebp-Ch]
  RGBX5551_t inColor; // [esp+1Ch] [ebp-8h]
  RGBX5551_t inColora; // [esp+1Ch] [ebp-8h]
  char v20; // [esp+22h] [ebp-2h]

  v2 = this;
  if ( handle != this->m_DefaultColorCorrectionHandle )
  {
    m_Size = this->m_ColorCorrectionList.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      for ( i = this->m_ColorCorrectionList.m_Memory.m_pMemory; (*i)->m_Handle != handle; ++i )
      {
        if ( ++v4 >= m_Size )
          return;
      }
      lookup = v2->m_ColorCorrectionList.m_Memory.m_pMemory[v4];
      if ( lookup != nullptr )
      {
        v6 = *(_WORD *)&inColor & 0x83FF;
        for ( j = 32; j != 0; --j )
        {
          v7 = v6 & 0xFC1F;
          for ( k = 32; k != 0; --k )
          {
            v8 = (RGBX5551_t)(v7 & 0xFFE0);
            inColora = v8;
            v17 = 32;
            do
            {
              v2->ConvertToColor24(this: v2, retstr: (color24 *)&handle, a3: inColora);
              m_pColorCorrection = lookup->m_pColorCorrection;
              v20 = BYTE2(handle);
              if ( m_pColorCorrection != nullptr )
              {
                v2 = this;
                v10 = (*(_BYTE *)&v8 & 0x1F)
                    + 32 * (((*(unsigned __int16 *)&v8 >> 5) & 0x1F) + 32 * ((*(unsigned __int16 *)&v8 >> 10) & 0x1F));
                v11 = (int)m_pColorCorrection + 2 * v10 + v10;
                *(_WORD *)v11 = handle;
                *(_BYTE *)(v11 + 2) = v20;
              }
              v8 = (RGBX5551_t)((*(_BYTE *)&inColora ^ (unsigned __int8)(*(_BYTE *)&inColora + 1)) & 0x1F ^ *(_WORD *)&v8);
              v12 = v17-- == 1;
              inColora = v8;
            }
            while ( !v12 );
            v7 = (*(_WORD *)&v8 ^ ((*(_WORD *)&v8 & 0xFFE0) + 32)) & 0x3E0 ^ *(_WORD *)&v8;
          }
          v6 = (v7 ^ ((v7 & 0xFC00) + 1024)) & 0x7C00 ^ v7;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018310
// Name: public: virtual void CColorCorrectionSystem::ResetLookupWeights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::ResetLookupWeights(CColorCorrectionSystem *this)
{
  int v1; // eax
  ColorCorrectionLookup_t *v2; // edx

  v1 = 0;
  for ( this->m_DefaultColorCorrectionWeight = 0.0; v1 < this->m_ColorCorrectionList.m_Size; ++v1 )
  {
    v2 = this->m_ColorCorrectionList.m_Memory.m_pMemory[v1];
    if ( v2->m_bResetable )
      v2->m_flWeight = 0.0;
    else
      v2->m_flWeight = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018350
// Name: public: virtual void CColorCorrectionSystem::ReleaseTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::ReleaseTextures(CColorCorrectionSystem *this)
{
  int i; // esi
  ITextureInternal *m_pColorCorrectionTexture; // ecx

  for ( i = 0; i < this->m_ColorCorrectionList.m_Size; ++i )
  {
    m_pColorCorrectionTexture = this->m_ColorCorrectionList.m_Memory.m_pMemory[i]->m_pColorCorrectionTexture;
    m_pColorCorrectionTexture->Release(this: m_pColorCorrectionTexture);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018380
// Name: public: virtual void CColorCorrectionSystem::RestoreTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::RestoreTextures(CColorCorrectionSystem *this)
{
  int i; // esi
  ColorCorrectionLookup_t *v3; // edi

  for ( i = 0; i < this->m_ColorCorrectionList.m_Size; ++i )
  {
    v3 = this->m_ColorCorrectionList.m_Memory.m_pMemory[i];
    v3->m_pColorCorrectionTexture->OnRestore(this: v3->m_pColorCorrectionTexture);
    v3->m_pColorCorrectionTexture->Download(this: v3->m_pColorCorrectionTexture, a2: nullptr, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100183C0
// Name: protected: void CColorCorrectionSystem::GetNormalizedWeights(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::GetNormalizedWeights(
        CColorCorrectionSystem *this,
        float *pDefaultWeight,
        float *pLookupWeights)
{
  int m_Size; // edx
  float v4; // xmm2_4
  float *v5; // ebx
  int v6; // edi
  int v7; // esi
  unsigned int v8; // edx
  float *v9; // eax
  char *v10; // esi
  float v11; // xmm1_4
  int v12; // ebx
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float m_flWeight; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // ecx
  float v21; // xmm0_4
  unsigned int v22; // esi
  float *v23; // eax
  int v24; // [esp+8h] [ebp-8h]
  int v25; // [esp+Ch] [ebp-4h]

  m_Size = this->m_ColorCorrectionList.m_Size;
  v4 = 0.0;
  if ( m_Size >= 4 )
    m_Size = 4;
  v5 = pLookupWeights;
  v6 = 0;
  v24 = m_Size;
  if ( m_Size >= 4 )
  {
    v7 = -8 - (_DWORD)pLookupWeights;
    v8 = ((unsigned int)(m_Size - 4) >> 2) + 1;
    v25 = 8;
    v9 = pLookupWeights + 2;
    v6 = 4 * v8;
    while ( 1 )
    {
      v10 = (char *)v9 + v7;
      v11 = *(float *)(*(_DWORD *)&v10[(unsigned int)this->m_ColorCorrectionList.m_Memory.m_pMemory] + 16);
      *(v9 - 2) = v11;
      v12 = v25;
      v25 += 16;
      v13 = v11 + v4;
      v14 = *(float *)(*(_DWORD *)&v10[(unsigned int)this->m_ColorCorrectionList.m_Memory.m_pMemory + 4] + 16);
      *(v9 - 1) = v14;
      v15 = v14;
      m_flWeight = (*(ColorCorrectionLookup_t **)((char *)this->m_ColorCorrectionList.m_Memory.m_pMemory + v12))->m_flWeight;
      *v9 = m_flWeight;
      v17 = m_flWeight + (float)(v15 + v13);
      v18 = *(float *)(*(_DWORD *)((char *)v9
                                 + 4
                                 - (_DWORD)pLookupWeights
                                 + (unsigned int)this->m_ColorCorrectionList.m_Memory.m_pMemory)
                     + 16);
      v9[1] = v18;
      v9 += 4;
      --v8;
      v4 = v18 + v17;
      if ( v8 == 0 )
        break;
      v7 = -8 - (_DWORD)pLookupWeights;
    }
    m_Size = v24;
    v5 = pLookupWeights;
  }
  for ( ; v6 < m_Size; v4 = v4 + v19 )
  {
    v19 = this->m_ColorCorrectionList.m_Memory.m_pMemory[v6]->m_flWeight;
    v5[v6++] = v19;
  }
  if ( m_Size < 4 )
    memset(&v5[m_Size], 0, 4 * (4 - m_Size));
  if ( v4 > 0.999 )
  {
    v20 = 0;
    *pDefaultWeight = 0.0;
    v21 = 1.0 / v4;
    if ( m_Size >= 4 )
    {
      v22 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v23 = v5 + 2;
      v20 = 4 * v22;
      do
      {
        *(v23 - 2) = *(v23 - 2) * v21;
        *(v23 - 1) = *(v23 - 1) * v21;
        *v23 = *v23 * v21;
        v23[1] = v21 * v23[1];
        v23 += 4;
        --v22;
      }
      while ( v22 != 0 );
    }
    for ( ; v20 < m_Size; ++v20 )
      v5[v20] = v5[v20] * v21;
  }
  else
  {
    *pDefaultWeight = 1.0 - v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018590
// Name: public: virtual int CColorCorrectionSystem::GetNumLookups(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorCorrectionSystem::GetNumLookups(CColorCorrectionSystem *this)
{
  int m_Size; // esi
  int result; // eax
  ColorCorrectionLookup_t **m_pMemory; // edx

  m_Size = this->m_ColorCorrectionList.m_Size;
  result = 0;
  if ( m_Size < 4 )
  {
LABEL_11:
    while ( result < m_Size )
    {
      if ( result >= 4 )
        break;
      if ( this->m_ColorCorrectionList.m_Memory.m_pMemory[result]->m_flWeight <= 0.0 )
        break;
      ++result;
    }
  }
  else
  {
    while ( result < 4 )
    {
      m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
      if ( m_pMemory[result]->m_flWeight <= 0.0 )
        break;
      if ( result + 1 >= 4 || m_pMemory[result + 1]->m_flWeight <= 0.0 )
        return ++result;
      if ( result >= 2 || m_pMemory[result + 2]->m_flWeight <= 0.0 )
      {
        result += 2;
        return result;
      }
      if ( result + 3 >= 4 || m_pMemory[result + 3]->m_flWeight <= 0.0 )
      {
        result += 3;
        return result;
      }
      result += 4;
      if ( result >= m_Size - 3 )
        goto LABEL_11;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018620
// Name: public: virtual void CColorCorrectionSystem::SetResetable(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::SetResetable(
        CColorCorrectionSystem *this,
        unsigned int handle,
        bool bResetable)
{
  int m_Size; // edx
  int v4; // eax
  ColorCorrectionLookup_t **m_pMemory; // esi
  ColorCorrectionLookup_t **i; // ecx
  ColorCorrectionLookup_t *v7; // eax

  m_Size = this->m_ColorCorrectionList.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
    for ( i = m_pMemory; (*i)->m_Handle != handle; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    v7 = m_pMemory[v4];
    if ( v7 != nullptr )
      v7->m_bResetable = bResetable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018660
// Name: public: virtual void CColorCorrectionSystem::GetCurrentColorCorrection(struct ShaderColorCorrectionInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::GetCurrentColorCorrection(
        CColorCorrectionSystem *this,
        ShaderColorCorrectionInfo_t *pInfo)
{
  bool v3; // al

  v3 = this->m_bEnabled && (this->GetNumLookups(this) > 0 || this->m_DefaultColorCorrectionWeight != 0.0);
  pInfo->m_bIsEnabled = v3;
  pInfo->m_nLookupCount = this->GetNumLookups(this);
  CColorCorrectionSystem::GetNormalizedWeights(
    this,
    pDefaultWeight: &pInfo->m_flDefaultWeight,
    pLookupWeights: pInfo->m_pLookupWeights);
}

//------------------------------------------------------------------------------
// Address: 0x10018740
// Name: public: virtual void CColorCorrectionSystem::LockLookup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::LockLookup(CColorCorrectionSystem *this)
{
  int m_Size; // edx
  int v3; // eax
  ColorCorrectionLookup_t **m_pMemory; // ecx

  m_Size = this->m_ColorCorrectionList.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
  while ( (*m_pMemory)->m_Handle != this->m_UnnamedColorCorrectionHandle )
  {
    ++v3;
    ++m_pMemory;
    if ( v3 >= m_Size )
      goto LABEL_7;
  }
  if ( this->m_ColorCorrectionList.m_Memory.m_pMemory[v3] == nullptr )
LABEL_7:
    this->AddLookup(this, a2: "unnamed");
  this->LockLookup(this, a2: this->m_UnnamedColorCorrectionHandle);
}

//------------------------------------------------------------------------------
// Address: 0x10018790
// Name: public: virtual void CColorCorrectionSystem::SetLookup(struct RGBX5551_t,struct color24)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::SetLookup(CColorCorrectionSystem *this, int inColor, color24 outColor)
{
  int m_Size; // esi
  int v4; // eax
  ColorCorrectionLookup_t **m_pMemory; // edx
  unsigned int m_UnnamedColorCorrectionHandle; // edi
  int v7; // [esp-4h] [ebp-10h]

  m_Size = this->m_ColorCorrectionList.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
    m_UnnamedColorCorrectionHandle = this->m_UnnamedColorCorrectionHandle;
    while ( (*m_pMemory)->m_Handle != m_UnnamedColorCorrectionHandle )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        return;
    }
    if ( this->m_ColorCorrectionList.m_Memory.m_pMemory[v4] != nullptr )
    {
      HIBYTE(v7) = HIBYTE(this);
      *(color24 *)&v7 = outColor;
      ((void (__stdcall *)(unsigned int, int, int))this->SetLookup)(
        a1: m_UnnamedColorCorrectionHandle,
        a2: inColor,
        a3: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100187F0
// Name: public: virtual void CColorCorrectionSystem::UnlockLookup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::UnlockLookup(CColorCorrectionSystem *this)
{
  int m_Size; // esi
  int v2; // eax
  ColorCorrectionLookup_t **m_pMemory; // edx
  unsigned int m_UnnamedColorCorrectionHandle; // edi

  m_Size = this->m_ColorCorrectionList.m_Size;
  v2 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
    m_UnnamedColorCorrectionHandle = this->m_UnnamedColorCorrectionHandle;
    while ( (*m_pMemory)->m_Handle != m_UnnamedColorCorrectionHandle )
    {
      ++v2;
      ++m_pMemory;
      if ( v2 >= m_Size )
        return;
    }
    if ( this->m_ColorCorrectionList.m_Memory.m_pMemory[v2] != nullptr )
      this->UnlockLookup(this, a2: m_UnnamedColorCorrectionHandle, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018830
// Name: public: virtual struct color24 CColorCorrectionSystem::GetLookup(struct RGBX5551_t)
// Source: json
//------------------------------------------------------------------------------
color24 *__thiscall CColorCorrectionSystem::GetLookup(
        CColorCorrectionSystem *this,
        color24 *__return_ptr retstr,
        int inColor)
{
  int m_Size; // edx
  int v5; // eax
  ColorCorrectionLookup_t **m_pMemory; // ecx

  m_Size = this->m_ColorCorrectionList.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
  while ( (*m_pMemory)->m_Handle != this->m_UnnamedColorCorrectionHandle )
  {
    ++v5;
    ++m_pMemory;
    if ( v5 >= m_Size )
      goto LABEL_7;
  }
  if ( this->m_ColorCorrectionList.m_Memory.m_pMemory[v5] == nullptr )
LABEL_7:
    this->AddLookup(this, a2: "unnamed");
  ((void (__thiscall *)(CColorCorrectionSystem *, color24 *, unsigned int, int))this->GetLookup)(
    a1: this,
    a2: retstr,
    a3: this->m_UnnamedColorCorrectionHandle,
    a4: inColor);
  return retstr;
}

//------------------------------------------------------------------------------
// Address: 0x10018890
// Name: public: virtual void CColorCorrectionSystem::LoadLookup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::LoadLookup(CColorCorrectionSystem *this, const char *pLookupName)
{
  int m_Size; // esi
  int v3; // eax
  ColorCorrectionLookup_t **m_pMemory; // edx
  unsigned int m_UnnamedColorCorrectionHandle; // edi

  m_Size = this->m_ColorCorrectionList.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
    m_UnnamedColorCorrectionHandle = this->m_UnnamedColorCorrectionHandle;
    while ( (*m_pMemory)->m_Handle != m_UnnamedColorCorrectionHandle )
    {
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        return;
    }
    if ( this->m_ColorCorrectionList.m_Memory.m_pMemory[v3] != nullptr )
      this->LoadLookup(this, a2: m_UnnamedColorCorrectionHandle, a3: pLookupName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100188E0
// Name: public: virtual void CColorCorrectionSystem::CopyLookup(struct color24 const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::CopyLookup(CColorCorrectionSystem *this, const color24 *pSrcColorCorrection)
{
  int m_Size; // esi
  int v3; // eax
  ColorCorrectionLookup_t **m_pMemory; // edx
  unsigned int m_UnnamedColorCorrectionHandle; // edi

  m_Size = this->m_ColorCorrectionList.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
    m_UnnamedColorCorrectionHandle = this->m_UnnamedColorCorrectionHandle;
    while ( (*m_pMemory)->m_Handle != m_UnnamedColorCorrectionHandle )
    {
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        return;
    }
    if ( this->m_ColorCorrectionList.m_Memory.m_pMemory[v3] != nullptr )
      this->CopyLookup(this, a2: m_UnnamedColorCorrectionHandle, a3: pSrcColorCorrection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018930
// Name: public: virtual void CColorCorrectionSystem::ResetLookup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::ResetLookup(CColorCorrectionSystem *this)
{
  int m_Size; // esi
  int v2; // eax
  ColorCorrectionLookup_t **m_pMemory; // edx
  unsigned int m_UnnamedColorCorrectionHandle; // edi

  m_Size = this->m_ColorCorrectionList.m_Size;
  v2 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
    m_UnnamedColorCorrectionHandle = this->m_UnnamedColorCorrectionHandle;
    while ( (*m_pMemory)->m_Handle != m_UnnamedColorCorrectionHandle )
    {
      ++v2;
      ++m_pMemory;
      if ( v2 >= m_Size )
        return;
    }
    if ( this->m_ColorCorrectionList.m_Memory.m_pMemory[v2] != nullptr )
      this->ResetLookup_2(this, a2: m_UnnamedColorCorrectionHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018970
// Name: protected: void CColorCorrectionSystem::SortLookups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::SortLookups(CColorCorrectionSystem *this)
{
  int i; // esi
  int j; // esi

  CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int>>::Sort(
    this: &this->m_ColorCorrectionList,
    pfnCompare: (int (__cdecl *)(const void *, const void *))CompareLookups);
  for ( i = 0; i < 4; ++i )
  {
    if ( i >= this->m_ColorCorrectionList.m_Size )
      break;
    g_pTextureManager->SetColorCorrectionTexture(
      this: g_pTextureManager,
      a2: i,
      a3: this->m_ColorCorrectionList.m_Memory.m_pMemory[i]->m_pColorCorrectionTexture);
  }
  for ( j = this->m_ColorCorrectionList.m_Size; j < 4; ++j )
    g_pTextureManager->SetColorCorrectionTexture(this: g_pTextureManager, a2: j, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100189D0
// Name: public: virtual bool CColorCorrectionSystem::RemoveLookup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorCorrectionSystem::RemoveLookup(CColorCorrectionSystem *this, unsigned int handle)
{
  int m_Size; // edx
  int v5; // ecx
  ColorCorrectionLookup_t **i; // eax
  ColorCorrectionLookup_t *v7; // edi

  if ( handle == this->m_DefaultColorCorrectionHandle )
    return 0;
  m_Size = this->m_ColorCorrectionList.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_ColorCorrectionList.m_Memory.m_pMemory; ; ++i )
  {
    v7 = *i;
    if ( (*i)->m_Handle == handle )
      break;
    if ( ++v5 >= m_Size )
      return 0;
  }
  if ( m_Size - v5 - 1 > 0 )
    _V_memmove(
      dest: &this->m_ColorCorrectionList.m_Memory.m_pMemory[v5],
      src: &this->m_ColorCorrectionList.m_Memory.m_pMemory[v5 + 1],
      count: 4 * (m_Size - v5 - 1));
  --this->m_ColorCorrectionList.m_Size;
  ColorCorrectionLookup_t::~ColorCorrectionLookup_t(this: v7);
  free(pMem: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10018A50
// Name: public: virtual void CColorCorrectionSystem::SetLookupWeight(unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::SetLookupWeight(
        CColorCorrectionSystem *this,
        unsigned int handle,
        float flWeight)
{
  int v3; // eax
  ColorCorrectionLookup_t **m_pMemory; // edx
  ColorCorrectionLookup_t *v5; // eax

  if ( handle == this->m_DefaultColorCorrectionHandle )
  {
    this->m_DefaultColorCorrectionWeight = flWeight;
  }
  else
  {
    v3 = 0;
    if ( this->m_ColorCorrectionList.m_Size > 0 )
    {
      m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
      while ( (*m_pMemory)->m_Handle != handle )
      {
        ++v3;
        ++m_pMemory;
        if ( v3 >= this->m_ColorCorrectionList.m_Size )
          goto LABEL_11;
      }
      v5 = this->m_ColorCorrectionList.m_Memory.m_pMemory[v3];
      if ( v5 != nullptr && flWeight > v5->m_flWeight )
        v5->m_flWeight = flWeight;
    }
LABEL_11:
    CColorCorrectionSystem::SortLookups(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018AC0
// Name: public: virtual void CColorCorrectionSystem::LoadLookup(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionSystem::LoadLookup(
        CColorCorrectionSystem *this,
        unsigned int handle,
        const char *pLookupName)
{
  int m_Size; // edx
  int v4; // eax
  ColorCorrectionLookup_t **m_pMemory; // esi
  ColorCorrectionLookup_t **i; // ecx
  ColorCorrectionLookup_t *v7; // esi
  bool (__thiscall *ReadFile)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, int, int, void *(__cdecl *)(const char *, unsigned int)); // eax
  long double v9; // st7
  __int16 v10; // cx
  unsigned __int8 *v11; // edx
  __int16 v12; // cx
  unsigned __int8 *v13; // eax
  unsigned __int16 v14; // cx
  unsigned __int8 *v15; // edx
  color24 *m_pColorCorrection; // edi
  int v17; // eax
  int v18; // esi
  color24 *v19; // edi
  unsigned __int16 v20; // cx
  int v21; // eax
  int v22; // esi
  unsigned __int16 v23; // cx
  color24 *v24; // edi
  int v25; // eax
  int v26; // esi
  unsigned __int16 v27; // cx
  color24 *v28; // edi
  int v29; // eax
  int v30; // esi
  bool v31; // zf
  CUtlBuffer colorBuff; // [esp+4h] [ebp-74h] BYREF
  unsigned __int8 *v33; // [esp+54h] [ebp-24h]
  unsigned __int8 *v34; // [esp+58h] [ebp-20h]
  int v35; // [esp+5Ch] [ebp-1Ch]
  int v36; // [esp+60h] [ebp-18h]
  int v37; // [esp+64h] [ebp-14h]
  ColorCorrectionLookup_t *lookup; // [esp+68h] [ebp-10h]
  int v39; // [esp+74h] [ebp-4h]
  char vOutColor24_2; // [esp+82h] [ebp+Ah]
  char vOutColor24_2a; // [esp+82h] [ebp+Ah]
  unsigned __int8 vOutColor24_2b; // [esp+82h] [ebp+Ah]
  unsigned __int8 vOutColor24_2c; // [esp+82h] [ebp+Ah]
  unsigned __int8 inColor; // [esp+84h] [ebp+Ch]

  if ( handle != this->m_DefaultColorCorrectionHandle )
  {
    m_Size = this->m_ColorCorrectionList.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
      for ( i = m_pMemory; (*i)->m_Handle != handle; ++i )
      {
        if ( ++v4 >= m_Size )
          return;
      }
      v7 = m_pMemory[v4];
      lookup = v7;
      if ( v7 != nullptr )
      {
        CUtlBuffer::CUtlBuffer(this: &colorBuff, growSize: 0, initSize: 0, nFlags: 0);
        ReadFile = g_pFullFileSystem->ReadFile;
        v39 = 0;
        if ( ReadFile(
               this: &g_pFullFileSystem->IBaseFileSystem,
               a2: pLookupName,
               a3: "GAME",
               a4: &colorBuff,
               a5: 0,
               a6: 0,
               a7: nullptr) )
        {
          v9 = pow((double)(colorBuff.m_nMaxPut / 3u), 0.3333333432674408);
          if ( (int)v9 == 32 && colorBuff.m_nMaxPut == 98304 )
          {
            v10 = (unsigned __int16)pLookupName & 0x83FF;
            v11 = colorBuff.m_Memory.m_pMemory + 6;
            v35 = (int)v9;
            while ( 1 )
            {
              v12 = v10 & 0xFC1F;
              v13 = v11;
              v36 = 32;
              v34 = v11 + 3072;
              while ( 1 )
              {
                v14 = v12 & 0xFFE0;
                v15 = v13;
                inColor = v14;
                v37 = 8;
                v33 = v13 + 96;
                do
                {
                  m_pColorCorrection = v7->m_pColorCorrection;
                  vOutColor24_2 = *(v15 - 4);
                  if ( m_pColorCorrection != nullptr )
                  {
                    v17 = (v14 & 0x1F) + 32 * (((v14 >> 5) & 0x1F) + 32 * ((v14 >> 10) & 0x1F));
                    v18 = (int)m_pColorCorrection + 2 * v17 + v17;
                    *(_WORD *)v18 = *((_WORD *)v15 - 3);
                    *(_BYTE *)(v18 + 2) = vOutColor24_2;
                    v7 = lookup;
                  }
                  v19 = v7->m_pColorCorrection;
                  v20 = (inColor ^ (unsigned __int8)(inColor + 1)) & 0x1F ^ v14;
                  vOutColor24_2a = *(v15 - 1);
                  if ( v19 != nullptr )
                  {
                    v21 = (v20 & 0x1F) + 32 * (((v20 >> 5) & 0x1F) + 32 * ((v20 >> 10) & 0x1F));
                    v22 = (int)v19 + 2 * v21 + v21;
                    *(_WORD *)v22 = *(_WORD *)(v15 - 3);
                    *(_BYTE *)(v22 + 2) = vOutColor24_2a;
                    v7 = lookup;
                  }
                  v23 = ((unsigned __int8)v20 ^ (unsigned __int8)(v20 + 1)) & 0x1F ^ v20;
                  v24 = v7->m_pColorCorrection;
                  vOutColor24_2b = v15[2];
                  if ( v24 != nullptr )
                  {
                    v25 = (v23 & 0x1F) + 32 * (((v23 >> 5) & 0x1F) + 32 * ((v23 >> 10) & 0x1F));
                    v26 = (int)v24 + 2 * v25 + v25;
                    *(_WORD *)v26 = *(_WORD *)v15;
                    *(_BYTE *)(v26 + 2) = vOutColor24_2b;
                    v7 = lookup;
                  }
                  v27 = ((unsigned __int8)v23 ^ (unsigned __int8)(v23 + 1)) & 0x1F ^ v23;
                  v28 = v7->m_pColorCorrection;
                  vOutColor24_2c = v15[5];
                  if ( v28 != nullptr )
                  {
                    v29 = (v27 & 0x1F) + 32 * (((v27 >> 5) & 0x1F) + 32 * ((v27 >> 10) & 0x1F));
                    v30 = (int)v28 + 2 * v29 + v29;
                    *(_WORD *)v30 = *(_WORD *)(v15 + 3);
                    *(_BYTE *)(v30 + 2) = vOutColor24_2c;
                    v7 = lookup;
                  }
                  v14 = ((unsigned __int8)v27 ^ (unsigned __int8)(v27 + 1)) & 0x1F ^ v27;
                  v15 += 12;
                  v31 = v37-- == 1;
                  inColor = v14;
                }
                while ( !v31 );
                v12 = (v14 ^ ((v14 & 0xFFE0) + 32)) & 0x3E0 ^ v14;
                if ( --v36 == 0 )
                  break;
                v13 = v33;
              }
              v10 = (v12 ^ ((v12 & 0xFC00) + 1024)) & 0x7C00 ^ v12;
              if ( --v35 == 0 )
                break;
              v11 = v34;
            }
            v39 = -1;
            if ( colorBuff.m_Memory.m_nGrowSize >= 0 && colorBuff.m_Memory.m_pMemory != nullptr )
              goto LABEL_11;
          }
          else
          {
            _Warning(a1: "CColorCorrectionSystem: Raw file '%s' has bad size (%d)\n", pLookupName, colorBuff.m_nMaxPut);
            v39 = -1;
            CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>::~CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>(this: &colorBuff);
          }
        }
        else
        {
          _Warning(a1: "CColorCorrectionSystem: Missing '%s'\n", pLookupName);
          v39 = -1;
          if ( colorBuff.m_Memory.m_nGrowSize >= 0 && colorBuff.m_Memory.m_pMemory != nullptr )
LABEL_11:
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: colorBuff.m_Memory.m_pMemory);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018E60
// Name: public: virtual unsigned int CColorCorrectionSystem::AddLookup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CColorCorrectionSystem::AddLookup(CColorCorrectionSystem *this, const char *pName)
{
  void *result; // eax
  unsigned int v4; // edi
  int m_Size; // edx
  int v6; // eax
  ColorCorrectionLookup_t **m_pMemory; // ecx
  ColorCorrectionLookup_t *v8; // esi
  int v9; // edi
  int m_nAllocationCount; // eax
  ColorCorrectionLookup_t **v11; // ecx
  int v12; // eax
  ColorCorrectionLookup_t **v13; // edi
  unsigned int handle; // [esp+24h] [ebp-10h]
  const char *pNamea; // [esp+3Ch] [ebp+8h]

  result = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: pName);
  v4 = (unsigned int)result;
  handle = (unsigned int)result;
  if ( result != (void *)this->m_DefaultColorCorrectionHandle )
  {
    m_Size = this->m_ColorCorrectionList.m_Size;
    v6 = 0;
    if ( m_Size <= 0 )
      goto LABEL_6;
    m_pMemory = this->m_ColorCorrectionList.m_Memory.m_pMemory;
    while ( (*m_pMemory)->m_Handle != v4 )
    {
      ++v6;
      ++m_pMemory;
      if ( v6 >= m_Size )
        goto LABEL_6;
    }
    if ( this->m_ColorCorrectionList.m_Memory.m_pMemory[v6] != nullptr )
    {
      return (void *)v4;
    }
    else
    {
LABEL_6:
      v8 = (ColorCorrectionLookup_t *)MemAlloc_Alloc(nSize: 0x18u);
      if ( v8 != nullptr )
      {
        v8->m_Handle = v4;
        v8->m_bLocked = false;
        v8->m_flWeight = 1.0;
        v8->m_bResetable = true;
        v8->m_pColorCorrection = (color24 *)MemAlloc_Alloc(nSize: 0x18000u);
        ColorCorrectionLookup_t::AllocTexture(this: v8);
        pNamea = (const char *)v8;
      }
      else
      {
        pNamea = nullptr;
      }
      v9 = this->m_ColorCorrectionList.m_Size;
      m_nAllocationCount = this->m_ColorCorrectionList.m_Memory.m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IMaterialVar *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_ColorCorrectionList,
          num: v9 - m_nAllocationCount + 1);
      ++this->m_ColorCorrectionList.m_Size;
      v11 = this->m_ColorCorrectionList.m_Memory.m_pMemory;
      v12 = this->m_ColorCorrectionList.m_Size - v9 - 1;
      this->m_ColorCorrectionList.m_pElements = v11;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = &this->m_ColorCorrectionList.m_Memory.m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = (ColorCorrectionLookup_t *)pNamea;
      this->LockLookup(this, a2: handle);
      this->ResetLookup_2(this, a2: handle);
      this->UnlockLookup(this, a2: handle, a3: true);
      ((void (__thiscall *)(CColorCorrectionSystem *, unsigned int, int))this->SetLookupWeight)(
        a1: this,
        a2: handle,
        a3: 1065353216);
      return (void *)handle;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017720
// Name: __CreateCColorCorrectionSystemIColorCorrectionSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CColorCorrectionSystem *__cdecl _CreateCColorCorrectionSystemIColorCorrectionSystem_interface()
{
  return &g_ColorCorrectionSystem;
}
