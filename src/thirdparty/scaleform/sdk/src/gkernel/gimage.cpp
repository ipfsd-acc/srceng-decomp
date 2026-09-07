// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gimage.cpp
// Functions: 15
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gimage.h"

//------------------------------------------------------------------------------
// Address: 0x100647C0
// Name: public: void GImageBase::SetPixelRGBA(int,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GImageBase::SetPixelRGBA(CBaseShader *this, IMaterialVar **x, unsigned int y, unsigned int color)
{
  int v4; // eax
  char *v5; // ecx

  if ( (unsigned int)x < *((_DWORD *)this + 1) && y < *((_DWORD *)this + 2) )
  {
    v4 = *((_DWORD *)this + 4) + y * *((_DWORD *)this + 3);
    switch ( (unsigned int)this->__vftable )
    {
      case 1u:
        *(_DWORD *)(v4 + 4 * (_DWORD)x) = color;
        break;
      case 2u:
        v5 = (char *)x + 2 * (_DWORD)x + v4;
        *v5 = color;
        *(_WORD *)(v5 + 1) = *(_WORD *)((char *)&color + 1);
        break;
      case 8u:
        *((_BYTE *)x + v4) = color;
        break;
      case 9u:
        *((_BYTE *)x + v4) = HIBYTE(color);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064860
// Name: public: static unsigned int GImageBase::GetBytesPerPixel(enum GImageBase::ImageFormat)
// Source: json
//------------------------------------------------------------------------------
static unsigned int __stdcall GImageBase::GetBytesPerPixel(enum ImageFormat a1)
{
  unsigned int result; // eax

  switch ( a1 )
  {
    case IMAGE_FORMAT_ABGR8888:
      result = 4;
      break;
    case IMAGE_FORMAT_RGB888:
      result = 3;
      break;
    case IMAGE_FORMAT_A8:
    case IMAGE_FORMAT_RGB888_BLUESCREEN:
    case IMAGE_FORMAT_LE_BGRA8888|IMAGE_FORMAT_RGBA1010102:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064910
// Name: ConvertScanline
// Source: json
//------------------------------------------------------------------------------
char __usercall ConvertScanline@<al>(
        unsigned int a1@<eax>,
        unsigned int a2@<edx>,
        int a3@<ecx>,
        unsigned int a4@<edi>,
        CLoggingSystem *result,
        unsigned int srcDelta,
        int a7,
        unsigned int dstScanlineSize,
        _BYTE *pextraInfo)
{
  unsigned int v10; // eax
  unsigned int j; // edx
  char v12; // bl
  unsigned int v14; // eax
  unsigned int k; // edx
  char v16; // bl
  unsigned int v17; // ebx
  int v18; // edx
  int v19; // eax
  unsigned int v20; // edx
  unsigned int m; // eax
  char v22; // bl
  unsigned int v23; // ebx
  unsigned __int8 *v24; // eax
  unsigned int v25; // edx
  unsigned int v26; // edx
  unsigned int v27; // eax
  _BYTE *v28; // edx
  unsigned int v29; // eax
  unsigned int n; // edx
  char v31; // bl
  unsigned int v32; // edx
  unsigned int ii; // eax
  char v34; // bl
  unsigned int i; // [esp+Ch] [ebp-8h]
  unsigned int ia; // [esp+Ch] [ebp-8h]
  unsigned int ib; // [esp+Ch] [ebp-8h]
  unsigned int dstDelta; // [esp+10h] [ebp-4h]
  unsigned int srcDeltaa; // [esp+20h] [ebp+Ch]

  srcDeltaa = a2 >> 3;
  dstDelta = a1 >> 3;
  switch ( srcDelta )
  {
    case 1u:
      if ( a7 == 9 )
      {
        v10 = 0;
        for ( j = 0; v10 < a4; j += dstDelta )
        {
          if ( j >= dstScanlineSize )
            break;
          v12 = *((_BYTE *)&result->m_nChannelCount + v10 + 3);
          v10 += srcDeltaa;
          *(_BYTE *)(j + a3) = v12;
        }
        return 1;
      }
      if ( a7 == 2 )
      {
        v14 = 0;
        for ( k = 0; v14 < a4; k += dstDelta )
        {
          if ( k >= dstScanlineSize )
            break;
          *(_BYTE *)(k + a3) = *((_BYTE *)&result->m_nChannelCount + v14);
          *(_BYTE *)(k + a3 + 1) = *((_BYTE *)&result->m_nChannelCount + v14 + 1);
          v16 = *((_BYTE *)&result->m_nChannelCount + v14 + 2);
          v14 += srcDeltaa;
          *(_BYTE *)(k + a3 + 2) = v16;
        }
        return 1;
      }
      return 0;
    case 2u:
      if ( a7 == 9 )
      {
        v17 = 0;
        for ( i = 0; v17 < a4; i += dstDelta )
        {
          if ( i >= dstScanlineSize )
            break;
          v18 = *((unsigned __int8 *)&result->m_nChannelCount + v17 + 1)
              + *((unsigned __int8 *)&result->m_nChannelCount + v17 + 2);
          v19 = *((unsigned __int8 *)&result->m_nChannelCount + v17);
          v17 += srcDeltaa;
          *(_BYTE *)(i + a3) = (v19 + v18) / 3u;
        }
        return 1;
      }
      else
      {
        if ( a7 != 1 )
          return 0;
        v20 = 0;
        for ( m = 0; v20 < a4; m += dstDelta )
        {
          if ( m >= dstScanlineSize )
            break;
          *(_BYTE *)(m + a3) = *((_BYTE *)&result->m_nChannelCount + v20);
          *(_BYTE *)(m + a3 + 1) = *((_BYTE *)&result->m_nChannelCount + v20 + 1);
          v22 = *((_BYTE *)&result->m_nChannelCount + v20 + 2);
          v20 += srcDeltaa;
          *(_BYTE *)(m + a3 + 2) = v22;
          *(_BYTE *)(m + a3 + 3) = -1;
        }
        return 1;
      }
    case 0x64u:
      if ( a7 == 9 )
      {
        v23 = 0;
        for ( ia = 0; v23 < a4; ia += dstDelta )
        {
          if ( ia >= dstScanlineSize )
            break;
          if ( pextraInfo[8] != 0 )
          {
            LOBYTE(v25) = pextraInfo[4 * *((unsigned __int8 *)&result->m_nChannelCount + v23) + 15];
          }
          else
          {
            v24 = &pextraInfo[4 * *((unsigned __int8 *)&result->m_nChannelCount + v23) + 12];
            v25 = (*v24 + v24[1] + (unsigned int)v24[2]) / 3;
          }
          v23 += srcDeltaa;
          *(_BYTE *)(ia + a3) = v25;
        }
        return 1;
      }
      else
      {
        if ( a7 != 2 && a7 != 1 )
          return 0;
        v26 = 0;
        v27 = 0;
        for ( ib = 0; v26 < a4; ib = v26 )
        {
          if ( v27 >= dstScanlineSize )
            break;
          v28 = &pextraInfo[4 * *((unsigned __int8 *)&result->m_nChannelCount + v26) + 12];
          *(_BYTE *)(v27 + a3) = *v28;
          *(_BYTE *)(v27 + a3 + 1) = v28[1];
          *(_BYTE *)(v27 + a3 + 2) = v28[2];
          if ( a7 == 1 )
            *(_BYTE *)(v27 + a3 + 3) = v28[3];
          v26 = srcDeltaa + ib;
          v27 += dstDelta;
        }
        return 1;
      }
    case 9u:
      if ( a7 == 2 )
      {
        v29 = 0;
        for ( n = 0; v29 < a4; n += dstDelta )
        {
          if ( n >= dstScanlineSize )
            break;
          *(_BYTE *)(n + a3) = *((_BYTE *)&result->m_nChannelCount + v29);
          *(_BYTE *)(n + a3 + 1) = *((_BYTE *)&result->m_nChannelCount + v29);
          v31 = *((_BYTE *)&result->m_nChannelCount + v29);
          v29 += srcDeltaa;
          *(_BYTE *)(n + a3 + 2) = v31;
        }
        return 1;
      }
      else
      {
        if ( a7 != 1 )
          return 0;
        v32 = 0;
        for ( ii = 0; v32 < a4; ii += dstDelta )
        {
          if ( ii >= dstScanlineSize )
            break;
          *(_BYTE *)(ii + a3) = -1;
          *(_BYTE *)(ii + a3 + 1) = -1;
          *(_BYTE *)(ii + a3 + 2) = -1;
          v34 = *((_BYTE *)&result->m_nChannelCount + v32);
          v32 += srcDeltaa;
          *(_BYTE *)(ii + a3 + 3) = v34;
        }
        return 1;
      }
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064BB0
// Name: GImage_ParseDDSHeader
// Source: json
//------------------------------------------------------------------------------
char __usercall GImage_ParseDDSHeader@<al>(int *a1@<ecx>, int a2@<esi>, _DWORD *a3, CRefPtr<IMatRenderContext> pdata)
{
  _DWORD *v4; // edx
  int v5; // ebx
  unsigned int v6; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // eax
  _DWORD *v10; // ecx
  unsigned int v11; // eax
  int v12; // eax

  v4 = a3;
  v5 = *a1;
  if ( (*a1 & 2) != 0 )
    a3[2] = a1[1];
  if ( (v5 & 4) != 0 )
    a3[1] = a1[2];
  v6 = a1[3];
  v7 = v5 & 8;
  if ( (v5 & 8) != 0 )
  {
    a3[3] = v6;
  }
  else if ( (v5 & 0x80000) != 0 )
  {
    v4 = a3;
    a3[3] = 4 * (v6 / a3[2]);
    v7 = v5 & 8;
  }
  if ( (v5 & 0x20000) != 0 )
    v4[6] = a1[5];
  if ( (v5 & 0x1000) != 0 )
  {
    if ( a1[17] != 32 )
      return 0;
    v8 = a1[18];
    v9 = a1[19];
    v10 = a1 + 20;
    if ( (v8 & 4) != 0 )
    {
      if ( v9 == 894720068 )
      {
        *v4 = 12;
        v10 += 5;
      }
      else if ( v9 == 861165636 )
      {
        *v4 = 11;
        v10 += 5;
      }
      else
      {
        if ( v9 == 827611204 )
          *v4 = 10;
        v10 += 5;
      }
    }
    else if ( (v8 & 0x42) != 0 )
    {
      v11 = *v10;
      if ( a2 != 0 )
        *(_DWORD *)a2 = v11;
      switch ( v11 )
      {
        case 8u:
          if ( (v8 & 2) != 0 )
            *v4 = 9;
          break;
        case 0x18u:
          *v4 = 2;
          break;
        case 0x20u:
          *v4 = 1;
          break;
        default:
          break;
      }
      if ( v7 == 0 )
        v4[3] = v4[1] * (v11 >> 3);
      if ( a2 != 0 )
      {
        *(_DWORD *)(a2 + 4) = v10[1];
        *(_DWORD *)(a2 + 8) = v10[2];
        *(_DWORD *)(a2 + 12) = v10[3];
      }
      v12 = v10[4];
      v10 += 5;
      if ( a2 != 0 && (v8 & 1) != 0 )
      {
        *(_DWORD *)(a2 + 16) = v12;
        *(_BYTE *)(a2 + 20) = 1;
      }
    }
    if ( *v4 == 0 )
      return 0;
  }
  else
  {
    v10 = a1 + 25;
  }
  if ( pdata.m_pObject != nullptr )
    pdata.m_pObject->__vftable = (IMatRenderContext_vtbl *)(v10 + 5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10064D10
// Name: GFx_CalcShiftByMask
// Source: json
//------------------------------------------------------------------------------
char __fastcall GFx_CalcShiftByMask(unsigned int a1)
{
  char v1; // al

  v1 = 0;
  if ( a1 == 0 )
    return 0;
  if ( (a1 & 0xFFFFFF) != 0 )
  {
    if ( (_WORD)a1 != 0 )
    {
      if ( (_BYTE)a1 == 0 )
      {
        a1 >>= 8;
        v1 = 8;
      }
    }
    else
    {
      a1 >>= 16;
      v1 = 16;
    }
  }
  else
  {
    a1 >>= 24;
    v1 = 24;
  }
  for ( ; (a1 & 1) == 0; ++v1 )
    a1 >>= 1;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10064D60
// Name: public: static unsigned int GImageBase::GetMipMapLevelSize(enum GImageBase::ImageFormat,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static int __stdcall GImageBase::GetMipMapLevelSize(enum ImageFormat a1, unsigned int w, unsigned int h)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  int result; // eax
  unsigned int v6; // ecx
  unsigned int v7; // eax

  if ( a1 == IMAGE_FORMAT_BGR888_BLUESCREEN )
  {
    v3 = (w + 3) >> 2;
    if ( v3 == 0 )
      v3 = 1;
    v4 = (h + 3) >> 2;
    if ( v4 == 0 )
      v4 = 1;
    return 8 * v4 * v3;
  }
  else if ( (unsigned int)(a1 - 11) > 1 )
  {
    switch ( a1 )
    {
      case IMAGE_FORMAT_ABGR8888:
        result = h * 4 * w;
        break;
      case IMAGE_FORMAT_RGB888:
        result = h * ((3 * w + 3) & 0xFFFFFFFC);
        break;
      case IMAGE_FORMAT_A8:
      case IMAGE_FORMAT_RGB888_BLUESCREEN:
      case IMAGE_FORMAT_LE_BGRA8888|IMAGE_FORMAT_RGBA1010102:
        result = h * w;
        break;
      default:
        result = 0;
        break;
    }
  }
  else
  {
    v6 = 1;
    if ( (w + 3) >> 2 != 0 )
      v6 = (w + 3) >> 2;
    v7 = (h + 3) >> 2;
    if ( v7 == 0 )
      v7 = 1;
    return 16 * v6 * v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10064EA0
// Name: public: unsigned char __near * GImageBase::GetMipMapLevelData(unsigned int,unsigned int __near *,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall GImageBase::GetMipMapLevelData(
        GImageBase *this,
        unsigned int a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5)
{
  unsigned int Width; // esi
  unsigned int Height; // edi
  unsigned int v10; // [esp+4h] [ebp-8h]
  unsigned int Pitch; // [esp+8h] [ebp-4h]
  unsigned __int8 *pData; // [esp+14h] [ebp+8h]

  if ( a2 > this->MipMapCount )
    return nullptr;
  if ( a2 != 0 )
  {
    Width = this->Width;
    Height = this->Height;
    pData = this->pData;
    Pitch = this->Pitch;
    v10 = a2;
    do
    {
      pData += GImageBase::GetMipMapLevelSize(a1: (enum ImageFormat)this->Format, w: Width, h: Height);
      Width >>= 1;
      if ( Width == 0 )
        Width = 1;
      Height >>= 1;
      if ( Height == 0 )
        Height = 1;
      Pitch >>= 1;
      --v10;
    }
    while ( v10 != 0 );
    if ( a3 != nullptr )
      *a3 = Width;
    if ( a4 != nullptr )
      *a4 = Height;
    if ( a5 != nullptr )
      *a5 = Pitch;
    return pData < &this->pData[this->DataSize] ? pData : nullptr;
  }
  else
  {
    if ( a3 != nullptr )
      *a3 = this->Width;
    if ( a4 != nullptr )
      *a4 = this->Height;
    if ( a5 != nullptr )
      *a5 = this->Pitch;
    return this->pData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064F70
// Name: PostProcessUDDSData
// Source: json
//------------------------------------------------------------------------------
char __cdecl PostProcessUDDSData(int a1, int a2)
{
  int v2; // ebx
  int v3; // eax
  char v4; // al
  int v5; // edx
  unsigned int v6; // ecx
  char v7; // al
  int v8; // edx
  unsigned int v9; // ecx
  char v10; // al
  int v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // esi
  unsigned __int8 *MipMapLevelData; // eax
  unsigned __int16 *v15; // esi
  int v16; // eax
  unsigned __int8 v17; // bl
  unsigned int v18; // edi
  unsigned int v19; // eax
  char v20; // cl
  unsigned int v21; // edx
  unsigned int v22; // eax
  unsigned __int8 v23; // dl
  unsigned int v24; // edi
  unsigned int v25; // eax
  char v26; // cl
  unsigned int v27; // ebx
  char v28; // cl
  bool v29; // zf
  unsigned int pitch; // [esp+Ch] [ebp-24h] BYREF
  unsigned int h; // [esp+10h] [ebp-20h] BYREF
  unsigned int curlevel; // [esp+14h] [ebp-1Ch]
  unsigned int v34; // [esp+18h] [ebp-18h]
  unsigned int w; // [esp+1Ch] [ebp-14h] BYREF
  unsigned __int8 *v36; // [esp+20h] [ebp-10h]
  int v37; // [esp+24h] [ebp-Ch]
  int v38; // [esp+28h] [ebp-8h]
  unsigned __int8 shiftA; // [esp+2Ch] [ebp-4h]
  unsigned __int8 shiftR; // [esp+2Dh] [ebp-3h]
  unsigned __int8 shiftG; // [esp+2Eh] [ebp-2h]
  unsigned __int8 shiftB; // [esp+2Fh] [ebp-1h]

  v2 = a1;
  v3 = *(_DWORD *)(a1 + 8);
  if ( v3 >= 10 && v3 <= 12 )
    return 1;
  if ( v3 != 1 && v3 != 2 )
    return 1;
  v4 = GFx_CalcShiftByMask(a1: *(_DWORD *)(a2 + 4));
  v6 = *(_DWORD *)(v5 + 8);
  shiftR = v4;
  v7 = GFx_CalcShiftByMask(a1: v6);
  v9 = *(_DWORD *)(v8 + 12);
  shiftG = v7;
  v10 = GFx_CalcShiftByMask(a1: v9);
  v12 = *(_DWORD *)(v11 + 16);
  shiftB = v10;
  v13 = 0;
  shiftA = GFx_CalcShiftByMask(a1: v12);
  curlevel = 0;
  if ( *(_DWORD *)(a1 + 32) == 0 )
    return 1;
  while ( 1 )
  {
    MipMapLevelData = GImageBase::GetMipMapLevelData(this: (GImageBase *)(v2 + 8), a2: v13, a3: &w, a4: &h, a5: &pitch);
    if ( MipMapLevelData == nullptr )
      return 0;
    if ( h == 0 )
      goto LABEL_24;
    v15 = (unsigned __int16 *)(MipMapLevelData + 1);
    v36 = MipMapLevelData + 1;
    v34 = h;
    do
    {
      v16 = *(_DWORD *)(v2 + 8);
      if ( v16 == 2 )
      {
        if ( 3 * w == 0 )
          goto LABEL_22;
        v17 = shiftB;
        v38 = shiftG;
        v37 = shiftR;
        v18 = (3 * w - 1) / 3 + 1;
        do
        {
          v19 = *((unsigned __int8 *)v15 - 1) | (*v15 << 8);
          v20 = v38;
          v15 = (unsigned __int16 *)((char *)v15 + 3);
          *((_BYTE *)v15 - 2) = v19 >> v17;
          v21 = v19 >> v20;
          v22 = v19 >> v37;
          --v18;
          *((_BYTE *)v15 - 3) = v21;
          *((_BYTE *)v15 - 4) = v22;
        }
        while ( v18 != 0 );
        goto LABEL_21;
      }
      if ( v16 == 1 && 4 * w != 0 )
      {
        v23 = shiftB;
        v38 = shiftG;
        v37 = shiftR;
        v24 = ((4 * w - 1) >> 2) + 1;
        do
        {
          v25 = *((unsigned __int8 *)v15 - 1)
              | ((*(unsigned __int8 *)v15 | (*(unsigned __int16 *)((char *)v15 + 1) << 8)) << 8);
          v26 = v38;
          *((_BYTE *)v15 + 1) = v25 >> v23;
          v27 = v25 >> v26;
          v28 = v37;
          *(_BYTE *)v15 = v27;
          *((_BYTE *)v15 - 1) = v25 >> v28;
          if ( *(_BYTE *)(a2 + 20) != 0 )
            *((_BYTE *)v15 + 2) = v25 >> shiftA;
          else
            *((_BYTE *)v15 + 2) = -1;
          v15 += 2;
          --v24;
        }
        while ( v24 != 0 );
LABEL_21:
        v2 = a1;
        v15 = (unsigned __int16 *)v36;
      }
LABEL_22:
      v15 = (unsigned __int16 *)((char *)v15 + pitch);
      v29 = v34-- == 1;
      v36 = (unsigned __int8 *)v15;
    }
    while ( !v29 );
    v13 = curlevel;
LABEL_24:
    curlevel = ++v13;
    if ( v13 >= *(_DWORD *)(v2 + 32) )
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100651B0
// Name: public: GImage::GImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GImage::GImage(IMesh *this)
{
  this->IVertexBuffer::__vftable = (IMesh_vtbl *)&GRefCountImplCore::`vftable';
  this->IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)1;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  this->IVertexBuffer::__vftable = (IMesh_vtbl *)&GImage::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10065240
// Name: public: void GImageBase::ClearImageBase(void)
// Source: json
//------------------------------------------------------------------------------
CBasePerInstanceContextData *__thiscall GImageBase::ClearImageBase(char *this)
{
  _DWORD *v1; // esi
  CBasePerInstanceContextData *result; // eax

  v1 = this + 28;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 1;
  if ( *((_DWORD *)this + 8) == 0 )
  {
    if ( *((_DWORD *)this + 9) == 0 )
      result = (CBasePerInstanceContextData *)GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                                                this: (CVertexBuilder *)(this + 28),
                                                pheapAddr: (ButtonCode_t)(this + 28),
                                                newCapacity: 0);
  }
  else if ( (*((_DWORD *)this + 9) & 0xFFFFFFFE) != 0 )
  {
    result = (CBasePerInstanceContextData *)*v1;
    if ( *v1 != 0 )
    {
      result = (CBasePerInstanceContextData *)((int (__thiscall *)(GMemoryHeap *, _DWORD))GMemory::pGlobalHeap->Free)(
                                                a1: GMemory::pGlobalHeap,
                                                a2: *v1);
      *v1 = 0;
    }
    v1[2] = 0;
    v1[1] = 0;
    return result;
  }
  v1[1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100652A0
// Name: public: GImage::GImage(enum GImageBase::ImageFormat,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
GImage *__thiscall GImage::GImage(GImage *this, enum ImageFormat a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // eax
  unsigned int MipMapLevelSize; // eax
  unsigned __int8 *v7; // eax
  unsigned int DataSize; // [esp-4h] [ebp-10h]
  int v10; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (GImage_vtbl *)&GRefCountImplCore::`vftable';
  v5 = 0;
  this->RefCount = 1;
  this->ColorMap.Data.Data = nullptr;
  this->ColorMap.Data.Size = 0;
  this->ColorMap.Data.Policy.Capacity = 0;
  this->__vftable = (GImage_vtbl *)&GImage::`vftable';
  switch ( a2 )
  {
    case IMAGE_FORMAT_ABGR8888:
      v5 = 4 * a3;
      break;
    case IMAGE_FORMAT_RGB888:
      v5 = (3 * a3 + 3) & 0xFFFFFFFC;
      break;
    case IMAGE_FORMAT_A8:
    case IMAGE_FORMAT_RGB888_BLUESCREEN:
    case IMAGE_FORMAT_LE_BGRA8888|IMAGE_FORMAT_RGBA1010102:
      v5 = a3;
      break;
    default:
      break;
  }
  this->Pitch = v5;
  MipMapLevelSize = GImageBase::GetMipMapLevelSize(a1: a2, w: a3, h: a4);
  this->DataSize = MipMapLevelSize;
  v10 = 2;
  v7 = (unsigned __int8 *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                            this: GMemory::pGlobalHeap,
                            a2: this,
                            a3: MipMapLevelSize,
                            a4: &v10);
  this->pData = v7;
  if ( v7 != nullptr )
  {
    this->Format = a2;
    DataSize = this->DataSize;
    this->Width = a3;
    this->Height = a4;
    memset(dst: v7, value: 0, count: DataSize);
  }
  else
  {
    GImageBase::ClearImageBase(this: (char *)&this->GImageBase);
  }
  this->MipMapCount = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100653F0
// Name: public: static class GImage __near * GImage::CreateImage(enum GImageBase::ImageFormat,unsigned long,unsigned long,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GImage *__stdcall GImage::CreateImage(ICachedPerFrameMeshData *result, unsigned int width, unsigned int height, int a4)
{
  GMemoryHeap *v4; // ecx
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  GImage *v6; // eax
  GImage *v7; // eax

  v4 = (GMemoryHeap *)a4;
  if ( a4 == 0 )
    v4 = GMemory::pGlobalHeap;
  Alloc_2 = v4->Alloc_2;
  a4 = 3;
  v6 = (GImage *)Alloc_2(this: v4, a2: 48u, a3: (const GAllocDebugInfo *)&a4);
  if ( v6 != nullptr )
    v7 = GImage::GImage(this: v6, a2: (enum ImageFormat)result, a3: width, a4: height);
  else
    v7 = nullptr;
  if ( v7->pData == nullptr || width == 0 || height == 0 )
  {
    GRefCountNTSImpl::Release(this: v7);
    return nullptr;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10065450
// Name: public: static class GImage __near * GImage::ReadTga(class GFile __near *,enum GImageBase::ImageFormat,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
GImage *__thiscall GImage::ReadTga(const IMesh *pin, int a2, ICachedPerFrameMeshData *a3, int a4)
{
  void (__thiscall *v4)(int, unsigned __int8 *, int); // edx
  void (__thiscall *v5)(int, char *, int); // edx
  void (__thiscall *v6)(int, char *, int); // edx
  void (__thiscall *v7)(int, int *, int); // edx
  void (__thiscall *v8)(int, int *, int); // edx
  void (__thiscall *v9)(int, unsigned __int8 *, int); // edx
  unsigned int v10; // ebx
  void (__thiscall *v11)(int, int *, int); // edx
  void (__thiscall *v12)(int, int *, int); // edx
  void (__thiscall *v13)(int, int *, int); // edx
  void (__thiscall *v14)(int, int *, int); // edx
  void (__thiscall *v15)(int, unsigned __int8 *, int); // edx
  void (__thiscall *v16)(int, char *, int); // edx
  int v17; // eax
  unsigned int v18; // edi
  void (__thiscall *v19)(int, char *, int); // edx
  void (__thiscall *v20)(int, char *, int); // edx
  void (__thiscall *v21)(int, char *, int); // edx
  void (__thiscall *v22)(int, char *, int); // edx
  int v23; // edi
  GImage *Image; // ebx
  CLoggingSystem *v25; // ecx
  int v26; // edi
  CLoggingSystem *v27; // ebx
  int v28; // eax
  int v29; // ecx
  _BYTE *v30; // eax
  unsigned int v31; // ecx
  char v32; // dl
  int v33; // eax
  _BYTE *v34; // ecx
  unsigned int v35; // edx
  char v36; // al
  GImage *v37; // ebx
  unsigned int j; // edi
  GColor *v39; // eax
  unsigned __int8 *v40; // ecx
  unsigned __int8 v41; // dl
  int v43; // [esp+8h] [ebp-445Ch] BYREF
  int v44; // [esp+Ch] [ebp-4458h] BYREF
  int v45; // [esp+10h] [ebp-4454h] BYREF
  int v46; // [esp+14h] [ebp-4450h] BYREF
  int v47; // [esp+18h] [ebp-444Ch] BYREF
  GImage *v48; // [esp+1Ch] [ebp-4448h]
  unsigned int v49; // [esp+20h] [ebp-4444h]
  int v50; // [esp+24h] [ebp-4440h]
  int v51; // [esp+28h] [ebp-443Ch] BYREF
  int v52; // [esp+2Ch] [ebp-4438h]
  CLoggingSystem *v53; // [esp+30h] [ebp-4434h]
  unsigned int v54; // [esp+34h] [ebp-4430h]
  unsigned int v55; // [esp+38h] [ebp-442Ch]
  unsigned int v56; // [esp+3Ch] [ebp-4428h]
  ICachedPerFrameMeshData *v57; // [esp+40h] [ebp-4424h]
  char v58; // [esp+45h] [ebp-441Fh] BYREF
  char v59; // [esp+46h] [ebp-441Eh] BYREF
  char v60; // [esp+47h] [ebp-441Dh] BYREF
  unsigned __int8 v61; // [esp+48h] [ebp-441Ch] BYREF
  char v62; // [esp+49h] [ebp-441Bh] BYREF
  unsigned __int8 v63; // [esp+4Ah] [ebp-441Ah] BYREF
  char v64; // [esp+4Bh] [ebp-4419h] BYREF
  int v65; // [esp+4Ch] [ebp-4418h] BYREF
  char v66; // [esp+50h] [ebp-4414h] BYREF
  unsigned __int8 v67; // [esp+51h] [ebp-4413h] BYREF
  char v68; // [esp+52h] [ebp-4412h] BYREF
  unsigned __int8 v69; // [esp+53h] [ebp-4411h]
  int v70; // [esp+54h] [ebp-4410h] BYREF
  unsigned int v71; // [esp+58h] [ebp-440Ch]
  bool i; // [esp+5Ch] [ebp-4408h]
  _BYTE v73[1024]; // [esp+60h] [ebp-4404h] BYREF
  _BYTE v74[16384]; // [esp+460h] [ebp-4004h] BYREF

  v57 = a3;
  v50 = a4;
  if ( a2 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)a2 + 8))(a1: a2) == 0 )
    return nullptr;
  v4 = *(void (__thiscall **)(int, unsigned __int8 *, int))(*(_DWORD *)a2 + 40);
  v63 = 0;
  v4(a1: a2, a2: &v63, a3: 1);
  v5 = *(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 40);
  v66 = 0;
  v5(a1: a2, a2: &v66, a3: 1);
  v6 = *(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 40);
  v68 = 0;
  v6(a1: a2, a2: &v68, a3: 1);
  v7 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 40);
  v46 = 0;
  v7(a1: a2, a2: &v46, a3: 2);
  v8 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 40);
  v70 = (unsigned __int16)v46;
  v47 = 0;
  v8(a1: a2, a2: &v47, a3: 2);
  v9 = *(void (__thiscall **)(int, unsigned __int8 *, int))(*(_DWORD *)a2 + 40);
  v71 = (unsigned __int16)v47;
  v61 = 0;
  v9(a1: a2, a2: &v61, a3: 1);
  v10 = v61;
  if ( v61 != 0 && v61 != 24 && v61 != 32 )
    return nullptr;
  v11 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 40);
  v43 = 0;
  v11(a1: a2, a2: &v43, a3: 2);
  v12 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 40);
  v44 = 0;
  v12(a1: a2, a2: &v44, a3: 2);
  v13 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 40);
  v65 = 0;
  v13(a1: a2, a2: &v65, a3: 2);
  v14 = *(void (__thiscall **)(int, int *, int))(*(_DWORD *)a2 + 40);
  v51 = 0;
  v14(a1: a2, a2: &v51, a3: 2);
  v15 = *(void (__thiscall **)(int, unsigned __int8 *, int))(*(_DWORD *)a2 + 40);
  v67 = 0;
  v15(a1: a2, a2: &v67, a3: 1);
  v16 = *(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 40);
  v59 = 0;
  v16(a1: a2, a2: &v59, a3: 1);
  if ( v66 != 0 )
  {
    if ( v66 != 1 || v68 != 1 )
      return nullptr;
  }
  else if ( v68 != 2 )
  {
    return nullptr;
  }
  if ( v63 != 0 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a2 + 44))(a1: a2, a2: v63);
  switch ( v67 )
  {
    case 8u:
      v17 = (unsigned __int16)v65;
      v54 = 100;
      break;
    case 0x18u:
      v54 = 2;
      v17 = 3 * (unsigned __int16)v65;
      break;
    case 0x20u:
      v54 = 1;
      v17 = 4 * (unsigned __int16)v65;
      break;
    default:
      return nullptr;
  }
  v56 = v17;
  v69 = v67;
  if ( v57 != nullptr )
  {
    switch ( (unsigned int)v57 )
    {
      case 1u:
        v55 = 4 * (unsigned __int16)v65;
        goto LABEL_29;
      case 2u:
        v69 = 24;
        v55 = 3 * (unsigned __int16)v65;
        goto LABEL_30;
      case 9u:
      case 0x64u:
        v69 = 8;
        v55 = (unsigned __int16)v65;
        goto LABEL_30;
      default:
        return nullptr;
    }
  }
  if ( v54 == 100 )
  {
    if ( v10 >= 0x20 )
    {
      v57 = (ICachedPerFrameMeshData *)1;
      v55 = 4 * (unsigned __int16)v65;
LABEL_29:
      v69 = 32;
    }
    else
    {
      v57 = (ICachedPerFrameMeshData *)2;
      v55 = 3 * (unsigned __int16)v65;
      v69 = 24;
    }
  }
  else
  {
    v57 = (ICachedPerFrameMeshData *)v54;
    v55 = v56;
  }
LABEL_30:
  if ( v66 != 1 || v68 != 1 )
    goto LABEL_38;
  if ( v71 * ((v10 + 7) >> 3) > 0x400 )
    return nullptr;
  v18 = 0;
  for ( i = v10 == 32; v18 < v71; ++v18 )
  {
    v19 = *(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 40);
    v58 = 0;
    v19(a1: a2, a2: &v58, a3: 1);
    v20 = *(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 40);
    v73[4 * v18 + 2] = v58;
    v64 = 0;
    v20(a1: a2, a2: &v64, a3: 1);
    v21 = *(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 40);
    v73[4 * v18 + 1] = v64;
    v62 = 0;
    v21(a1: a2, a2: &v62, a3: 1);
    v73[4 * v18] = v62;
    if ( v10 == 32 )
    {
      v22 = *(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 40);
      v60 = 0;
      v22(a1: a2, a2: &v60, a3: 1);
      v73[4 * v18 + 3] = v60;
    }
    else
    {
      *(_DWORD *)&v73[4 * v18] |= 0xFF000000;
    }
  }
LABEL_38:
  v23 = (unsigned __int16)v51;
  Image = GImage::CreateImage(result: v57, width: (unsigned __int16)v65, height: (unsigned __int16)v51, a4: v50);
  v48 = Image;
  if ( Image != nullptr )
  {
    if ( v56 <= 0x4000 )
    {
      v25 = (CLoggingSystem *)v74;
    }
    else
    {
      v45 = 3;
      v25 = (CLoggingSystem *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: v56, a3: &v45);
    }
    v53 = v25;
    if ( (v59 & 0x20) != 0 )
      v52 = 0;
    else
      v52 = v23 - 1;
    v49 = 0;
    if ( v23 != 0 )
    {
      while ( 1 )
      {
        v26 = (int)&Image->pData[Image->Pitch * abs32(v52)];
        v50 = v26;
        v27 = (CLoggingSystem *)v26;
        if ( (ICachedPerFrameMeshData *)v54 != v57 )
          v27 = v25;
        v28 = (*(int (__thiscall **)(int, CLoggingSystem *, unsigned int))(*(_DWORD *)a2 + 40))(
                a1: a2,
                a2: v27,
                a3: v56);
        if ( v28 != v56 )
          break;
        if ( v54 == 1 )
        {
          v29 = 4 * (unsigned __int16)v65;
          if ( v29 != 0 )
          {
            v30 = (char *)&v27->m_nChannelCount + 2;
            v31 = ((unsigned int)(v29 - 1) >> 2) + 1;
            do
            {
              v32 = *(v30 - 2);
              *(v30 - 2) = *v30;
              *v30 = v32;
              v30 += 4;
              --v31;
            }
            while ( v31 != 0 );
          }
        }
        else if ( v54 == 2 )
        {
          v33 = 3 * (unsigned __int16)v65;
          if ( v33 != 0 )
          {
            v34 = (char *)&v27->m_nChannelCount + 2;
            v35 = (v33 - 1) / 3u + 1;
            do
            {
              v36 = *(v34 - 2);
              *(v34 - 2) = *v34;
              *v34 = v36;
              v34 += 3;
              --v35;
            }
            while ( v35 != 0 );
          }
        }
        else if ( v57 == (ICachedPerFrameMeshData *)100 )
        {
          v37 = v48;
          GArrayBase<GArrayData<GColor,GAllocatorGH<GColor,2>,GArrayDefaultPolicy>>::Resize(
            this: (matrix3x4a_t *)&v48->ColorMap,
            newSize: v71);
          for ( j = 0; j < v71; v39->Channels.Alpha = (unsigned __int8)v40 )
          {
            v39 = &v37->ColorMap.Data.Data[j];
            v40 = &v73[4 * j + 1];
            v39->Channels.Red = v73[4 * j];
            v39->Channels.Green = *v40;
            v41 = v40[1];
            LOBYTE(v40) = v40[2];
            ++j;
            v39->Channels.Blue = v41;
          }
          v26 = v50;
        }
        if ( (ICachedPerFrameMeshData *)v54 != v57
          && ConvertScanline(
               a1: v69,
               a2: v67,
               a3: v26,
               a4: v56,
               result: v53,
               srcDelta: v54,
               a7: (int)v57,
               dstScanlineSize: v55,
               pextraInfo: &v70) == 0 )
        {
          break;
        }
        --v52;
        if ( ++v49 >= (unsigned __int16)v51 )
          break;
        v25 = v53;
        Image = v48;
      }
      v25 = v53;
      Image = v48;
    }
    if ( v25 != nullptr && v25 != (CLoggingSystem *)v74 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v25);
    if ( v49 < (unsigned __int16)v51 )
    {
      GRefCountNTSImpl::Release(this: Image);
      return nullptr;
    }
    ++Image->RefCount;
    GRefCountNTSImpl::Release(this: Image);
  }
  return Image;
}

//------------------------------------------------------------------------------
// Address: 0x10065BD0
// Name: public: static class GImage __near * GImage::ReadJpeg(class GFile __near *,class GJPEGSystem __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
static GJPEGInput *__userpurge GImage::ReadJpeg@<eax>(
        int a1@<esi>,
        struct GFile *a2,
        struct GJPEGSystem *a3,
        struct GMemoryHeap *a4)
{
  GJPEGInput *result; // eax
  struct GImage *v5; // edi
  unsigned int v6; // eax
  GImage *Image; // eax
  GRefCountNTSImpl *v8; // esi
  int v9; // ebx
  unsigned int v10; // [esp-Ch] [ebp-10h]

  result = a3->CreateInput(this: a3, a2);
  v5 = (struct GImage *)result;
  if ( result != nullptr )
  {
    if ( ((unsigned __int8 (__thiscall *)(GJPEGInput *, int))result->IsErrorOccurred)(a1: result, a2: a1) == 0 )
    {
      v10 = ((int (__thiscall *)(struct GImage *))v5->__vftable[5].dtr_GRefCountImplCore)(a1: v5);
      v6 = ((int (__thiscall *)(struct GImage *))v5->__vftable[6].dtr_GRefCountImplCore)(a1: v5);
      Image = GImage::CreateImage(result: (ICachedPerFrameMeshData *)2, width: v6, height: v10, (int)a4);
      v8 = Image;
      if ( Image == nullptr )
        goto LABEL_10;
      v9 = 0;
      if ( Image->Height == 0 )
        goto LABEL_10;
      while ( ((int (__thiscall *)(struct GImage *, int))v5->__vftable[7].dtr_GRefCountImplCore)(
                a1: v5,
                a2: (int)v8[3].__vftable + v9 * v8[2].RefCount) != 0 )
      {
        if ( (GRefCountNTSImpl_vtbl *)++v9 >= v8[2].__vftable )
          goto LABEL_10;
      }
      GRefCountNTSImpl::Release(this: v8);
    }
    v8 = nullptr;
LABEL_10:
    ((void (__thiscall *)(struct GImage *, int))v5->dtr_GRefCountImplCore)(a1: v5, a2: 1);
    return (GJPEGInput *)v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10065C80
// Name: public: static class GImage __near * GImage::ReadDDS(class GFile __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
static struct GImage *__userpurge GImage::ReadDDS@<eax>(int a1@<ebx>, struct GFile *a2, struct GMemoryHeap *a3)
{
  int (__thiscall *GetLength)(GFile *); // eax
  int v4; // eax
  int (__thiscall *Read)(GFile *, unsigned __int8 *, int); // edx
  int v6; // ebx
  int (__thiscall *v7)(GFile *, unsigned __int8 *, int); // edx
  IMesh *v9; // eax
  GRefCountNTSImpl *v10; // eax
  GRefCountNTSImpl *v11; // esi
  bool v12; // zf
  GRefCountNTSImpl_vtbl *v13; // edx
  volatile int v14; // eax
  volatile int v15; // ecx
  GRefCountNTSImpl_vtbl *v16; // edx
  int v17; // eax
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  unsigned __int8 *v19; // ebx
  int v20; // eax
  _DWORD v21[5]; // [esp+8h] [ebp-150h] BYREF
  char v22; // [esp+1Ch] [ebp-13Ch]
  _DWORD v23[7]; // [esp+20h] [ebp-138h] BYREF
  void *v24; // [esp+3Ch] [ebp-11Ch]
  int v25; // [esp+40h] [ebp-118h]
  int v26; // [esp+44h] [ebp-114h]
  int v27; // [esp+48h] [ebp-110h] BYREF
  GMemoryHeap *v28; // [esp+4Ch] [ebp-10Ch]
  int dataSize; // [esp+50h] [ebp-108h] BYREF
  int v30[64]; // [esp+54h] [ebp-104h] BYREF

  v28 = a3;
  if ( a2 == nullptr || !a2->IsValid(this: a2) )
    return nullptr;
  GetLength = a2->GetLength;
  v24 = nullptr;
  v25 = 0;
  v26 = 0;
  v4 = ((int (__thiscall *)(struct GFile *, int))GetLength)(a1: a2, a2: a1);
  Read = a2->Read;
  v6 = v4;
  dataSize = 0;
  Read(this: a2, a2: (unsigned __int8 *)&dataSize, a3: 4);
  if ( dataSize != 542327876
    || (v7 = a2->Read, dataSize = 0, v7(this: a2, a2: (unsigned __int8 *)&dataSize, a3: 4), dataSize != 124)
    || a2->Read(this: a2, a2: (unsigned __int8 *)v30, a3: 120) != 120 )
  {
    ((void (__cdecl *)(_DWORD))GMemory::pGlobalHeap->Free)(a1: 0);
    return nullptr;
  }
  GImageBase::ClearImageBase(this: (char *)v23);
  memset(v21, 0, sizeof(v21));
  v22 = 0;
  if ( GImage_ParseDDSHeader(a1: v30, a2: (int)v21, a3: v23, pdata: 0) == 0 )
  {
LABEL_20:
    ((void (__cdecl *)(void *))GMemory::pGlobalHeap->Free)(a1: v24);
    return nullptr;
  }
  v9 = (IMesh *)GRefCountBaseStatImpl<GRefCountNTSImpl,3>::operator new(sz: 0x30u);
  if ( v9 == nullptr )
    goto LABEL_17;
  GImage::GImage(this: v9);
  v11 = v10;
  if ( v10 == nullptr )
    goto LABEL_17;
  v12 = v28 == nullptr;
  v13 = (GRefCountNTSImpl_vtbl *)v23[2];
  v14 = v23[1];
  v11[1].__vftable = (GRefCountNTSImpl_vtbl *)v23[0];
  v15 = v23[3];
  v11[2].__vftable = v13;
  v16 = (GRefCountNTSImpl_vtbl *)v23[6];
  v11[1].RefCount = v14;
  v11[2].RefCount = v15;
  v11[4].__vftable = v16;
  if ( v12 )
    v28 = GMemory::pGlobalHeap;
  v17 = a2->Tell(this: a2);
  Alloc_2 = v28->Alloc_2;
  dataSize = v6 - v17;
  v27 = 3;
  v19 = (unsigned __int8 *)Alloc_2(this: v28, a2: v6 - v17, a3: (const GAllocDebugInfo *)&v27);
  if ( v19 == nullptr )
  {
    GRefCountNTSImpl::Release(this: v11);
LABEL_17:
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v24);
    return nullptr;
  }
  v20 = a2->Read(this: a2, a2: v19, a3: dataSize);
  if ( v20 != dataSize )
  {
    GRefCountNTSImpl::Release(this: v11);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v19);
    goto LABEL_17;
  }
  v11[3].RefCount = dataSize;
  v11[3].__vftable = (GRefCountNTSImpl_vtbl *)v19;
  if ( PostProcessUDDSData(a1: (int)v11, a2: (int)v21) == 0 )
  {
    GRefCountNTSImpl::Release(this: v11);
    goto LABEL_20;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v24);
  return (struct GImage *)v11;
}
