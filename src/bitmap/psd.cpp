// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/psd.cpp
// Functions: 6
// ============================================================

#include "bitmap\psd.h"

//------------------------------------------------------------------------------
// Address: 0x1021FD90
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned int>(unsigned int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned int>(CUtlBuffer *this, unsigned int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021FE00
// Name: public: unsigned int CUtlBuffer::GetUnsignedInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetUnsignedInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: (int *)&i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021FEA0
// Name: unsigned long GetProcessorCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl GetProcessorCount()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  return SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x102202C0
// Name: public: CATICompressThreadData::CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::CATICompressThreadData(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102202D0
// Name: public: CATICompressThreadData::~CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::~CATICompressThreadData(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*this;
  if ( v2 != nullptr )
  {
    (**v2)(a1: v2, a2: 1);
    *this = 0;
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*(this + 1);
  if ( v3 != nullptr )
  {
    (**v3)(a1: v3, a2: 1);
    *(this + 1) = 0;
  }
  v4 = (void (__thiscall ***)(_DWORD, int))*(this + 2);
  if ( v4 != nullptr )
  {
    (**v4)(a1: v4, a2: 1);
    *(this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10220320
// Name: unsigned long ThreadedCompressProc(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall ThreadedCompressProc(_DWORD *a1)
{
  unsigned int v1; // esi
  int v2; // edi

  v1 = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0x8001Fu, mask: 0x8001Fu);
  v2 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*a1 + 32))(
         a1: *a1,
         a2: a1[1],
         a3: a1[2],
         a4: a1[3],
         a5: a1[4],
         a6: a1[5]);
  _controlfp(newctrl: v1, mask: 0x8001Fu);
  return v2;
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x102321F0
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

} // namespace MaterialSystem

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x10041990
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

} // namespace shaderapidx9

// ============================================================
// Overlay from Dist2alpha (Missing functions)
// ============================================================
namespace Dist2alpha {

//------------------------------------------------------------------------------
// Address: 0x004049B0
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
// Address: 0x00404A10
// Name: PSDConvertToRGBA8888
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDConvertToRGBA8888(
        int nChannelsCount@<edx>,
        PSDMode_t mode@<ecx>,
        Bitmap_t *bitmap@<edi>,
        PSDPalette_t *palette)
{
  unsigned __int8 *m_pBits; // eax
  bool v5; // bl
  unsigned __int8 *v6; // edx
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // esi
  int m_nWidth; // ecx
  int v15; // edx
  unsigned __int8 v16; // cl
  int v17; // esi
  int v18; // ebx
  int v19; // edx
  unsigned __int8 v20; // cl
  unsigned __int8 v21; // cl
  unsigned __int8 v22; // cl
  int i; // [esp+Ch] [ebp-Ch]
  int k; // [esp+10h] [ebp-8h]
  int ka; // [esp+10h] [ebp-8h]
  bool bShouldFillInAlpha; // [esp+17h] [ebp-1h]

  m_pBits = bitmap->m_pBits;
  switch ( mode )
  {
    case MODE_GREYSCALE:
      v5 = nChannelsCount == 1;
      v13 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        m_nWidth = bitmap->m_nWidth;
        do
        {
          v15 = 0;
          if ( m_nWidth > 0 )
          {
            do
            {
              v16 = *m_pBits;
              m_pBits[1] = *m_pBits;
              m_pBits[2] = v16;
              m_nWidth = bitmap->m_nWidth;
              ++v15;
              m_pBits += 4;
            }
            while ( v15 < bitmap->m_nWidth );
          }
          ++v13;
        }
        while ( v13 < bitmap->m_nHeight );
      }
      goto LABEL_3;
    case MODE_PALETTIZED:
      v5 = nChannelsCount == 1;
      bShouldFillInAlpha = nChannelsCount == 1;
      k = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v10 = bitmap->m_nWidth;
        do
        {
          v11 = 0;
          if ( v10 > 0 )
          {
            do
            {
              v12 = *m_pBits;
              *m_pBits = palette->m_pRed[v12];
              m_pBits[1] = palette->m_pGreen[v12];
              m_pBits[2] = palette->m_pBlue[v12];
              v10 = bitmap->m_nWidth;
              ++v11;
              m_pBits += 4;
            }
            while ( v11 < bitmap->m_nWidth );
            v5 = bShouldFillInAlpha;
          }
          ++k;
        }
        while ( k < bitmap->m_nHeight );
      }
      goto LABEL_3;
    case MODE_RGBA:
      v5 = nChannelsCount == 3;
LABEL_3:
      if ( v5 )
      {
        v6 = bitmap->m_pBits;
        v7 = 0;
        if ( bitmap->m_nHeight > 0 )
        {
          v8 = bitmap->m_nWidth;
          do
          {
            v9 = 0;
            if ( v8 > 0 )
            {
              do
              {
                v6[3] = -1;
                v8 = bitmap->m_nWidth;
                ++v9;
                v6 += 4;
              }
              while ( v9 < bitmap->m_nWidth );
            }
            ++v7;
          }
          while ( v7 < bitmap->m_nHeight );
        }
      }
      break;
    case MODE_CMYK:
      for ( i = 0; i < bitmap->m_nHeight; ++i )
      {
        for ( ka = 0; ka < bitmap->m_nWidth; ++ka )
        {
          v17 = (unsigned __int8)(-1 - m_pBits[3]);
          v18 = v17 + (unsigned __int8)(-1 - m_pBits[2]);
          v19 = v17 + (unsigned __int8)(-1 - m_pBits[1]);
          if ( v17 + (unsigned int)(unsigned __int8)(-1 - *m_pBits) >= 0xFF )
            v20 = 0;
          else
            v20 = *m_pBits - v17;
          *m_pBits = v20;
          if ( v19 >= 255 )
            v21 = 0;
          else
            v21 = -1 - v19;
          m_pBits[1] = v21;
          if ( v18 >= 255 )
            v22 = 0;
          else
            v22 = -1 - v18;
          m_pBits[2] = v22;
          m_pBits[3] = -1;
          m_pBits += 4;
        }
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404BD0
// Name: PSDReadUncompressedChannels
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDReadUncompressedChannels(
        Bitmap_t *bitmap@<esi>,
        CUtlBuffer *buf,
        int nChannelsCount,
        PSDMode_t mode,
        PSDPalette_t *palette)
{
  int m_nWidth; // edi
  void *v6; // esp
  int v7; // ecx
  int *v8; // eax
  bool v9; // cc
  unsigned __int8 *m_pBits; // ebx
  int i; // eax
  bool v12; // zf
  unsigned __int8 *v13; // eax
  bool v14; // bl
  unsigned __int8 *v15; // edx
  int v16; // edi
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edi
  int v23; // ecx
  int v24; // edx
  unsigned __int8 v25; // cl
  int v26; // edi
  unsigned int v27; // ecx
  int v28; // ebx
  int v29; // edx
  unsigned __int8 v30; // cl
  unsigned __int8 v31; // cl
  unsigned __int8 v32; // cl
  int v33; // [esp+0h] [ebp-1Ch] BYREF
  int v34; // [esp+8h] [ebp-14h]
  int v35; // [esp+Ch] [ebp-10h]
  int *v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+14h] [ebp-8h]
  void *pMem; // [esp+18h] [ebp-4h]
  int k; // [esp+28h] [ebp+Ch]
  bool v40; // [esp+2Bh] [ebp+Fh]
  int v41; // [esp+2Ch] [ebp+10h]
  int j; // [esp+2Ch] [ebp+10h]

  m_nWidth = bitmap->m_nWidth;
  v6 = alloca(bitmap->m_nWidth);
  v7 = nChannelsCount;
  pMem = &v33;
  if ( nChannelsCount > 0 )
  {
    v8 = s_pChannelIndex[mode];
    v36 = v8;
    v35 = nChannelsCount;
    do
    {
      v9 = bitmap->m_nHeight <= 0;
      m_pBits = bitmap->m_pBits;
      v34 = *v8;
      v37 = 0;
      if ( !v9 )
      {
        do
        {
          CUtlBuffer::Get(this: buf, pMem, size: m_nWidth);
          m_nWidth = bitmap->m_nWidth;
          for ( i = 0; i < bitmap->m_nWidth; m_pBits += 4 )
          {
            m_pBits[v34] = *((_BYTE *)pMem + i);
            m_nWidth = bitmap->m_nWidth;
            ++i;
          }
          ++v37;
        }
        while ( v37 < bitmap->m_nHeight );
        v8 = v36;
        v7 = nChannelsCount;
      }
      ++v8;
      v12 = v35-- == 1;
      v36 = v8;
    }
    while ( !v12 );
  }
  v13 = bitmap->m_pBits;
  switch ( mode )
  {
    case MODE_GREYSCALE:
      v14 = v7 == 1;
      v22 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v23 = bitmap->m_nWidth;
        do
        {
          v24 = 0;
          if ( v23 > 0 )
          {
            do
            {
              v25 = *v13;
              v13[1] = *v13;
              v13[2] = v25;
              v23 = bitmap->m_nWidth;
              ++v24;
              v13 += 4;
            }
            while ( v24 < bitmap->m_nWidth );
          }
          ++v22;
        }
        while ( v22 < bitmap->m_nHeight );
      }
      goto LABEL_11;
    case MODE_PALETTIZED:
      v14 = v7 == 1;
      v40 = v7 == 1;
      v41 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v19 = bitmap->m_nWidth;
        do
        {
          v20 = 0;
          if ( v19 > 0 )
          {
            do
            {
              v21 = *v13;
              *v13 = palette->m_pRed[v21];
              v13[1] = palette->m_pGreen[v21];
              v13[2] = palette->m_pBlue[v21];
              v19 = bitmap->m_nWidth;
              ++v20;
              v13 += 4;
            }
            while ( v20 < bitmap->m_nWidth );
            v14 = v40;
          }
          ++v41;
        }
        while ( v41 < bitmap->m_nHeight );
      }
      goto LABEL_11;
    case MODE_RGBA:
      v14 = v7 == 3;
LABEL_11:
      if ( v14 )
      {
        v15 = bitmap->m_pBits;
        v16 = 0;
        if ( bitmap->m_nHeight > 0 )
        {
          v17 = bitmap->m_nWidth;
          do
          {
            v18 = 0;
            if ( v17 > 0 )
            {
              do
              {
                v15[3] = -1;
                v17 = bitmap->m_nWidth;
                ++v18;
                v15 += 4;
              }
              while ( v18 < bitmap->m_nWidth );
            }
            ++v16;
          }
          while ( v16 < bitmap->m_nHeight );
        }
      }
      break;
    case MODE_CMYK:
      for ( j = 0; j < bitmap->m_nHeight; ++j )
      {
        for ( k = 0; k < bitmap->m_nWidth; ++k )
        {
          v26 = (unsigned __int8)(-1 - v13[3]);
          v27 = v26 + (unsigned __int8)(-1 - *v13);
          v28 = v26 + (unsigned __int8)(-1 - v13[2]);
          v29 = v26 + (unsigned __int8)(-1 - v13[1]);
          v34 = v28;
          if ( v27 >= 0xFF )
          {
            v30 = 0;
          }
          else
          {
            v35 = 255 - v27;
            v30 = -1 - v27;
          }
          *v13 = v30;
          if ( v29 >= 255 )
            v31 = 0;
          else
            v31 = -1 - v29;
          v13[1] = v31;
          if ( v28 >= 255 )
            v32 = 0;
          else
            v32 = -1 - v28;
          v13[2] = v32;
          v13[3] = -1;
          v13 += 4;
        }
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404E20
// Name: bool IsPSDFile(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPSDFile(CUtlBuffer *buf)
{
  int m_Get; // edi
  __int16 v3; // ax
  __int16 v4; // ax
  PSDHeader_t header; // [esp+8h] [ebp-1Ch] BYREF

  m_Get = buf->m_Get;
  CUtlBuffer::Get(this: buf, pMem: &header, size: 26);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: m_Get);
  if ( _byteswap_ulong(header.m_nSignature) != 943870035 )
    return false;
  LOBYTE(v3) = HIBYTE(header.m_nVersion);
  HIBYTE(v3) = header.m_nVersion;
  if ( v3 != 1 )
    return false;
  LOBYTE(v4) = HIBYTE(header.m_nDepth);
  HIBYTE(v4) = header.m_nDepth;
  return v4 == 8;
}

//------------------------------------------------------------------------------
// Address: 0x00404E80
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        unsigned int *outputBuffer,
        unsigned int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  unsigned int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (int *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404F10
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404F90
// Name: public: unsigned int CUtlBuffer::GetUnsignedInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetUnsignedInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (unsigned int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405030
// Name: public: short CUtlBuffer::GetShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004050D0
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405170
// Name: PSDReadCompressedChannels
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDReadCompressedChannels(
        CUtlBuffer *buf@<eax>,
        int nChannelsCount,
        PSDMode_t mode,
        PSDPalette_t *palette,
        Bitmap_t *bitmap)
{
  Bitmap_t *v5; // ebx
  int m_nWidth; // esi
  void *v8; // esp
  int v9; // edx
  int *v10; // eax
  bool v11; // cc
  unsigned __int8 *m_pBits; // ecx
  unsigned __int8 *v13; // ebx
  char v14; // cl
  int v15; // esi
  unsigned __int8 UnsignedShort; // al
  int v17; // eax
  bool v18; // zf
  int v19; // [esp+0h] [ebp-28h] BYREF
  int v20; // [esp+Ch] [ebp-1Ch]
  int v21; // [esp+10h] [ebp-18h]
  int *v22; // [esp+14h] [ebp-14h]
  int v23; // [esp+18h] [ebp-10h]
  unsigned __int8 *v24; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 *v25; // [esp+20h] [ebp-8h]
  int v26; // [esp+24h] [ebp-4h]

  v5 = bitmap;
  m_nWidth = bitmap->m_nWidth;
  v8 = alloca(bitmap->m_nWidth);
  v9 = nChannelsCount;
  v25 = (unsigned __int8 *)&v19;
  if ( nChannelsCount > 0 )
  {
    v10 = s_pChannelIndex[mode];
    v22 = v10;
    v21 = nChannelsCount;
    do
    {
      v11 = v5->m_nHeight <= 0;
      v20 = *v10;
      m_pBits = v5->m_pBits;
      v24 = m_pBits;
      v23 = 0;
      if ( !v11 )
      {
        do
        {
          v13 = v25;
          v26 = m_nWidth;
          if ( m_nWidth != 0 )
          {
            do
            {
              if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
                v14 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
              else
                v14 = 0;
              if ( v14 < 0 )
              {
                v15 = 1 - v14;
                if ( (buf->m_Flags & 1) != 0 )
                {
                  UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
                }
                else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
                {
                  UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
                }
                else
                {
                  UnsignedShort = 0;
                }
                memset(dst: v13, value: UnsignedShort, count: v15);
              }
              else
              {
                v15 = v14 + 1;
                CUtlBuffer::Get(this: buf, pMem: v13, size: v15);
              }
              v13 += v15;
              v26 -= v15;
            }
            while ( v26 != 0 );
            m_pBits = v24;
          }
          v5 = bitmap;
          m_nWidth = bitmap->m_nWidth;
          v17 = 0;
          if ( bitmap->m_nWidth > 0 )
          {
            do
            {
              m_pBits[v20] = v25[v17];
              m_nWidth = bitmap->m_nWidth;
              ++v17;
              m_pBits += 4;
            }
            while ( v17 < bitmap->m_nWidth );
            v24 = m_pBits;
          }
          ++v23;
        }
        while ( v23 < bitmap->m_nHeight );
        v10 = v22;
      }
      ++v10;
      v18 = v21-- == 1;
      v22 = v10;
    }
    while ( !v18 );
    v9 = nChannelsCount;
  }
  PSDConvertToRGBA8888(nChannelsCount: v9, mode, bitmap: v5, palette);
}

//------------------------------------------------------------------------------
// Address: 0x004052D0
// Name: bool PSDReadFileRGBA8888(class CUtlBuffer __near &,struct Bitmap_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PSDReadFileRGBA8888(CUtlBuffer *buf, Bitmap_t *bitmap)
{
  __int16 v2; // ax
  __int16 v3; // ax
  unsigned __int16 v4; // ax
  PSDMode_t v5; // ecx
  unsigned __int16 v6; // ax
  int v7; // esi
  bool result; // al
  int v9; // ebx
  void *v10; // esp
  unsigned __int16 Short; // ax
  char v12; // t0
  _BYTE v13[12]; // [esp+0h] [ebp-4Ch] BYREF
  PSDHeader_t header; // [esp+Ch] [ebp-40h] BYREF
  PSDPalette_t palette; // [esp+28h] [ebp-24h] BYREF
  int nWidth; // [esp+34h] [ebp-18h]
  int nHeight; // [esp+38h] [ebp-14h]
  int nChannelsCount; // [esp+3Ch] [ebp-10h]
  PSDMode_t mode; // [esp+40h] [ebp-Ch]
  unsigned __int8 *pPaletteBits; // [esp+44h] [ebp-8h]
  bool bSecondPassCMYKA; // [esp+4Bh] [ebp-1h]

  CUtlBuffer::Get(this: buf, pMem: &header, size: 26);
  if ( _byteswap_ulong(header.m_nSignature) != 943870035 )
    return false;
  LOBYTE(v2) = HIBYTE(header.m_nVersion);
  HIBYTE(v2) = header.m_nVersion;
  if ( v2 != 1 )
    return false;
  LOBYTE(v3) = HIBYTE(header.m_nDepth);
  HIBYTE(v3) = header.m_nDepth;
  if ( v3 != 8 )
    return false;
  LOBYTE(v4) = HIBYTE(header.m_nMode);
  HIBYTE(v4) = header.m_nMode;
  v5 = v4;
  mode = v5;
  LOBYTE(v6) = HIBYTE(header.m_nChannels);
  HIBYTE(v6) = header.m_nChannels;
  v7 = v6;
  nChannelsCount = v6;
  if ( v5 == MODE_MULTICHANNEL || v5 == MODE_LAB )
    return false;
  switch ( v5 )
  {
    case MODE_GREYSCALE:
    case MODE_PALETTIZED:
      if ( v6 == 1 || v6 == 2 )
        goto LABEL_13;
      return false;
    case MODE_RGBA:
      if ( v6 >= 3u )
        goto LABEL_13;
      return false;
    case MODE_CMYK:
      if ( v6 < 4u )
        return false;
LABEL_13:
      nWidth = _byteswap_ulong(header.m_nColumns);
      nHeight = _byteswap_ulong(header.m_nRows);
      v9 = _byteswap_ulong(CUtlBuffer::GetUnsignedInt(this: buf));
      v10 = alloca(v9);
      pPaletteBits = v13;
      memset(&palette, 0, sizeof(palette));
      if ( v9 != 0 )
      {
        CUtlBuffer::Get(this: buf, pMem: v13, size: v9);
        palette.m_pRed = pPaletteBits;
        palette.m_pBlue = &pPaletteBits[v9 / 3 + v9 / 3];
        v7 = nChannelsCount;
        palette.m_pGreen = &pPaletteBits[v9 / 3];
      }
      nChannelsCount = CUtlBuffer::GetUnsignedInt(this: buf);
      CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: _byteswap_ulong(nChannelsCount));
      nChannelsCount = CUtlBuffer::GetUnsignedInt(this: buf);
      CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: _byteswap_ulong(nChannelsCount));
      Short = CUtlBuffer::GetShort(this: buf);
      nChannelsCount = Short;
      v12 = Short;
      LOBYTE(Short) = HIBYTE(Short);
      HIBYTE(Short) = v12;
      HIWORD(pPaletteBits) = Short;
      Bitmap_t::Init(this: bitmap, nWidth, nHeight, imageFormat: IMAGE_FORMAT_RGBA8888);
      if ( v7 <= 4 || (bSecondPassCMYKA = true, mode != MODE_CMYK) )
        bSecondPassCMYKA = false;
      if ( HIWORD(pPaletteBits) != 0 )
      {
        CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: 2 * v7 * bitmap->m_nHeight);
        if ( v7 > 4 )
          v7 = 4;
        PSDReadCompressedChannels(buf, nChannelsCount: v7, mode, &palette, bitmap);
      }
      else
      {
        if ( v7 > 4 )
          v7 = 4;
        PSDReadUncompressedChannels(bitmap, buf, nChannelsCount: v7, mode, &palette);
      }
      if ( !bSecondPassCMYKA )
        goto LABEL_29;
      if ( HIWORD(pPaletteBits) != 0 )
      {
        PSDReadCompressedChannels(buf, nChannelsCount: 1, mode: MODE_COUNT, &palette, bitmap);
LABEL_29:
        result = true;
      }
      else
      {
        PSDReadUncompressedChannels(bitmap, buf, nChannelsCount: 1, mode: MODE_COUNT, &palette);
        result = true;
      }
      break;
    default:
      _Warning(a1: "Unsupported PSD color mode!\n");
      return false;
  }
  return result;
}

} // namespace Dist2alpha

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004EDB70
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned int>(unsigned int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned int>(CUtlBuffer *this, unsigned int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EDAB0
// Name: void PadLine<unsigned char>(unsigned long,unsigned char,unsigned char __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PadLine<unsigned char>(unsigned int a1, unsigned __int8 a2, unsigned __int8 *src)
{
  while ( a2 - a1 > a1 )
    a2 >>= 1;
  memcpy(dst: &src[a1], src, count: a2 - a1);
}

//------------------------------------------------------------------------------
// Address: 0x004EDAF0
// Name: void PadBlock<unsigned char>(unsigned long,unsigned char,unsigned char,unsigned char __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PadBlock<unsigned char>(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 *src)
{
  unsigned int v4; // ecx

  while ( 1 )
  {
    v4 = a3 - a1;
    if ( v4 <= a1 )
      break;
    a3 >>= 1;
  }
  memcpy(dst: &src[a1 * a2], src, count: v4 * a2);
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1021FF60
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned int>(unsigned int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned int>(CUtlBuffer *this, unsigned int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021FFD0
// Name: public: unsigned int CUtlBuffer::GetUnsignedInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetUnsignedInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: (int *)&i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10220070
// Name: unsigned long GetProcessorCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl GetProcessorCount()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  return SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x10220490
// Name: public: CATICompressThreadData::CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::CATICompressThreadData(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102204A0
// Name: public: CATICompressThreadData::~CATICompressThreadData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CATICompressThreadData::~CATICompressThreadData(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*this;
  if ( v2 != nullptr )
  {
    (**v2)(a1: v2, a2: 1);
    *this = 0;
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*(this + 1);
  if ( v3 != nullptr )
  {
    (**v3)(a1: v3, a2: 1);
    *(this + 1) = 0;
  }
  v4 = (void (__thiscall ***)(_DWORD, int))*(this + 2);
  if ( v4 != nullptr )
  {
    (**v4)(a1: v4, a2: 1);
    *(this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102204F0
// Name: unsigned long ThreadedCompressProc(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall ThreadedCompressProc(_DWORD *a1)
{
  unsigned int v1; // esi
  int v2; // edi

  v1 = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0x8001Fu, mask: 0x8001Fu);
  v2 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*a1 + 32))(
         a1: *a1,
         a2: a1[1],
         a3: a1[2],
         a4: a1[3],
         a5: a1[4],
         a6: a1[5]);
  _controlfp(newctrl: v1, mask: 0x8001Fu);
  return v2;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from height2ssbump (Missing functions)
// ============================================================
namespace height2ssbump {

//------------------------------------------------------------------------------
// Address: 0x004060E0
// Name: public: void Bitmap_t::Init(int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Bitmap_t::Init(Bitmap_t *this, int nWidth, int nHeight, ImageFormat imageFormat)
{
  const ImageFormatInfo_t *v5; // eax

  if ( this->m_pBits != nullptr )
  {
    operator delete(p: this->m_pBits);
    this->m_pBits = nullptr;
  }
  this->m_nWidth = nWidth;
  this->m_nHeight = nHeight;
  this->m_ImageFormat = imageFormat;
  v5 = ImageLoader::ImageFormatInfo(fmt: imageFormat);
  this->m_pBits = (unsigned __int8 *)operator new(size: nHeight * nWidth * v5->m_nNumBytes);
}

//------------------------------------------------------------------------------
// Address: 0x00406140
// Name: PSDConvertToRGBA8888
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDConvertToRGBA8888(
        int nChannelsCount@<edx>,
        PSDMode_t mode@<ecx>,
        Bitmap_t *bitmap@<edi>,
        PSDPalette_t *palette)
{
  unsigned __int8 *m_pBits; // eax
  bool v5; // bl
  unsigned __int8 *v6; // edx
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // esi
  int m_nWidth; // ecx
  int v15; // edx
  unsigned __int8 v16; // cl
  int v17; // esi
  int v18; // ebx
  int v19; // edx
  unsigned __int8 v20; // cl
  unsigned __int8 v21; // cl
  unsigned __int8 v22; // cl
  int i; // [esp+Ch] [ebp-Ch]
  int k; // [esp+10h] [ebp-8h]
  int ka; // [esp+10h] [ebp-8h]
  bool bShouldFillInAlpha; // [esp+17h] [ebp-1h]

  m_pBits = bitmap->m_pBits;
  switch ( mode )
  {
    case MODE_GREYSCALE:
      v5 = nChannelsCount == 1;
      v13 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        m_nWidth = bitmap->m_nWidth;
        do
        {
          v15 = 0;
          if ( m_nWidth > 0 )
          {
            do
            {
              v16 = *m_pBits;
              m_pBits[1] = *m_pBits;
              m_pBits[2] = v16;
              m_nWidth = bitmap->m_nWidth;
              ++v15;
              m_pBits += 4;
            }
            while ( v15 < bitmap->m_nWidth );
          }
          ++v13;
        }
        while ( v13 < bitmap->m_nHeight );
      }
      goto LABEL_3;
    case MODE_PALETTIZED:
      v5 = nChannelsCount == 1;
      bShouldFillInAlpha = nChannelsCount == 1;
      k = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v10 = bitmap->m_nWidth;
        do
        {
          v11 = 0;
          if ( v10 > 0 )
          {
            do
            {
              v12 = *m_pBits;
              *m_pBits = palette->m_pRed[v12];
              m_pBits[1] = palette->m_pGreen[v12];
              m_pBits[2] = palette->m_pBlue[v12];
              v10 = bitmap->m_nWidth;
              ++v11;
              m_pBits += 4;
            }
            while ( v11 < bitmap->m_nWidth );
            v5 = bShouldFillInAlpha;
          }
          ++k;
        }
        while ( k < bitmap->m_nHeight );
      }
      goto LABEL_3;
    case MODE_RGBA:
      v5 = nChannelsCount == 3;
LABEL_3:
      if ( v5 )
      {
        v6 = bitmap->m_pBits;
        v7 = 0;
        if ( bitmap->m_nHeight > 0 )
        {
          v8 = bitmap->m_nWidth;
          do
          {
            v9 = 0;
            if ( v8 > 0 )
            {
              do
              {
                v6[3] = -1;
                v8 = bitmap->m_nWidth;
                ++v9;
                v6 += 4;
              }
              while ( v9 < bitmap->m_nWidth );
            }
            ++v7;
          }
          while ( v7 < bitmap->m_nHeight );
        }
      }
      break;
    case MODE_CMYK:
      for ( i = 0; i < bitmap->m_nHeight; ++i )
      {
        for ( ka = 0; ka < bitmap->m_nWidth; ++ka )
        {
          v17 = (unsigned __int8)(-1 - m_pBits[3]);
          v18 = v17 + (unsigned __int8)(-1 - m_pBits[2]);
          v19 = v17 + (unsigned __int8)(-1 - m_pBits[1]);
          if ( v17 + (unsigned int)(unsigned __int8)(-1 - *m_pBits) >= 0xFF )
            v20 = 0;
          else
            v20 = *m_pBits - v17;
          *m_pBits = v20;
          if ( v19 >= 255 )
            v21 = 0;
          else
            v21 = -1 - v19;
          m_pBits[1] = v21;
          if ( v18 >= 255 )
            v22 = 0;
          else
            v22 = -1 - v18;
          m_pBits[2] = v22;
          m_pBits[3] = -1;
          m_pBits += 4;
        }
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406300
// Name: PSDReadUncompressedChannels
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDReadUncompressedChannels(
        Bitmap_t *bitmap@<esi>,
        CUtlBuffer *buf,
        int nChannelsCount,
        PSDMode_t mode,
        PSDPalette_t *palette)
{
  int m_nWidth; // edi
  void *v6; // esp
  int v7; // ecx
  int *v8; // eax
  bool v9; // cc
  unsigned __int8 *m_pBits; // ebx
  int i; // eax
  bool v12; // zf
  unsigned __int8 *v13; // eax
  bool v14; // bl
  unsigned __int8 *v15; // edx
  int v16; // edi
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edi
  int v23; // ecx
  int v24; // edx
  unsigned __int8 v25; // cl
  int v26; // edi
  unsigned int v27; // ecx
  int v28; // ebx
  int v29; // edx
  unsigned __int8 v30; // cl
  unsigned __int8 v31; // cl
  unsigned __int8 v32; // cl
  int v33; // [esp+0h] [ebp-1Ch] BYREF
  int v34; // [esp+8h] [ebp-14h]
  int v35; // [esp+Ch] [ebp-10h]
  int *v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+14h] [ebp-8h]
  void *pMem; // [esp+18h] [ebp-4h]
  int k; // [esp+28h] [ebp+Ch]
  bool v40; // [esp+2Bh] [ebp+Fh]
  int v41; // [esp+2Ch] [ebp+10h]
  int j; // [esp+2Ch] [ebp+10h]

  m_nWidth = bitmap->m_nWidth;
  v6 = alloca(bitmap->m_nWidth);
  v7 = nChannelsCount;
  pMem = &v33;
  if ( nChannelsCount > 0 )
  {
    v8 = s_pChannelIndex[mode];
    v36 = v8;
    v35 = nChannelsCount;
    do
    {
      v9 = bitmap->m_nHeight <= 0;
      m_pBits = bitmap->m_pBits;
      v34 = *v8;
      v37 = 0;
      if ( !v9 )
      {
        do
        {
          CUtlBuffer::Get(this: buf, pMem, size: m_nWidth);
          m_nWidth = bitmap->m_nWidth;
          for ( i = 0; i < bitmap->m_nWidth; m_pBits += 4 )
          {
            m_pBits[v34] = *((_BYTE *)pMem + i);
            m_nWidth = bitmap->m_nWidth;
            ++i;
          }
          ++v37;
        }
        while ( v37 < bitmap->m_nHeight );
        v8 = v36;
        v7 = nChannelsCount;
      }
      ++v8;
      v12 = v35-- == 1;
      v36 = v8;
    }
    while ( !v12 );
  }
  v13 = bitmap->m_pBits;
  switch ( mode )
  {
    case MODE_GREYSCALE:
      v14 = v7 == 1;
      v22 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v23 = bitmap->m_nWidth;
        do
        {
          v24 = 0;
          if ( v23 > 0 )
          {
            do
            {
              v25 = *v13;
              v13[1] = *v13;
              v13[2] = v25;
              v23 = bitmap->m_nWidth;
              ++v24;
              v13 += 4;
            }
            while ( v24 < bitmap->m_nWidth );
          }
          ++v22;
        }
        while ( v22 < bitmap->m_nHeight );
      }
      goto LABEL_11;
    case MODE_PALETTIZED:
      v14 = v7 == 1;
      v40 = v7 == 1;
      v41 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v19 = bitmap->m_nWidth;
        do
        {
          v20 = 0;
          if ( v19 > 0 )
          {
            do
            {
              v21 = *v13;
              *v13 = palette->m_pRed[v21];
              v13[1] = palette->m_pGreen[v21];
              v13[2] = palette->m_pBlue[v21];
              v19 = bitmap->m_nWidth;
              ++v20;
              v13 += 4;
            }
            while ( v20 < bitmap->m_nWidth );
            v14 = v40;
          }
          ++v41;
        }
        while ( v41 < bitmap->m_nHeight );
      }
      goto LABEL_11;
    case MODE_RGBA:
      v14 = v7 == 3;
LABEL_11:
      if ( v14 )
      {
        v15 = bitmap->m_pBits;
        v16 = 0;
        if ( bitmap->m_nHeight > 0 )
        {
          v17 = bitmap->m_nWidth;
          do
          {
            v18 = 0;
            if ( v17 > 0 )
            {
              do
              {
                v15[3] = -1;
                v17 = bitmap->m_nWidth;
                ++v18;
                v15 += 4;
              }
              while ( v18 < bitmap->m_nWidth );
            }
            ++v16;
          }
          while ( v16 < bitmap->m_nHeight );
        }
      }
      break;
    case MODE_CMYK:
      for ( j = 0; j < bitmap->m_nHeight; ++j )
      {
        for ( k = 0; k < bitmap->m_nWidth; ++k )
        {
          v26 = (unsigned __int8)(-1 - v13[3]);
          v27 = v26 + (unsigned __int8)(-1 - *v13);
          v28 = v26 + (unsigned __int8)(-1 - v13[2]);
          v29 = v26 + (unsigned __int8)(-1 - v13[1]);
          v34 = v28;
          if ( v27 >= 0xFF )
          {
            v30 = 0;
          }
          else
          {
            v35 = 255 - v27;
            v30 = -1 - v27;
          }
          *v13 = v30;
          if ( v29 >= 255 )
            v31 = 0;
          else
            v31 = -1 - v29;
          v13[1] = v31;
          if ( v28 >= 255 )
            v32 = 0;
          else
            v32 = -1 - v28;
          v13[2] = v32;
          v13[3] = -1;
          v13 += 4;
        }
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406550
// Name: bool IsPSDFile(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPSDFile(CUtlBuffer *buf)
{
  int m_Get; // edi
  __int16 v3; // ax
  __int16 v4; // ax
  PSDHeader_t header; // [esp+8h] [ebp-1Ch] BYREF

  m_Get = buf->m_Get;
  CUtlBuffer::Get(this: buf, pMem: &header, size: 26);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: m_Get);
  if ( _byteswap_ulong(header.m_nSignature) != 943870035 )
    return false;
  LOBYTE(v3) = HIBYTE(header.m_nVersion);
  HIBYTE(v3) = header.m_nVersion;
  if ( v3 != 1 )
    return false;
  LOBYTE(v4) = HIBYTE(header.m_nDepth);
  HIBYTE(v4) = header.m_nDepth;
  return v4 == 8;
}

//------------------------------------------------------------------------------
// Address: 0x004065B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        unsigned int *outputBuffer,
        unsigned int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  unsigned int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (int *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406640
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004066C0
// Name: public: unsigned int CUtlBuffer::GetUnsignedInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetUnsignedInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (unsigned int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406760
// Name: public: short CUtlBuffer::GetShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406800
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004068A0
// Name: PSDReadCompressedChannels
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDReadCompressedChannels(
        CUtlBuffer *buf@<eax>,
        int nChannelsCount,
        PSDMode_t mode,
        PSDPalette_t *palette,
        Bitmap_t *bitmap)
{
  Bitmap_t *v5; // ebx
  int m_nWidth; // esi
  void *v8; // esp
  int v9; // edx
  int *v10; // eax
  bool v11; // cc
  unsigned __int8 *m_pBits; // ecx
  unsigned __int8 *v13; // ebx
  char v14; // cl
  int v15; // esi
  unsigned __int8 UnsignedShort; // al
  int v17; // eax
  bool v18; // zf
  int v19; // [esp+0h] [ebp-28h] BYREF
  int v20; // [esp+Ch] [ebp-1Ch]
  int v21; // [esp+10h] [ebp-18h]
  int *v22; // [esp+14h] [ebp-14h]
  int v23; // [esp+18h] [ebp-10h]
  unsigned __int8 *v24; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 *v25; // [esp+20h] [ebp-8h]
  int v26; // [esp+24h] [ebp-4h]

  v5 = bitmap;
  m_nWidth = bitmap->m_nWidth;
  v8 = alloca(bitmap->m_nWidth);
  v9 = nChannelsCount;
  v25 = (unsigned __int8 *)&v19;
  if ( nChannelsCount > 0 )
  {
    v10 = s_pChannelIndex[mode];
    v22 = v10;
    v21 = nChannelsCount;
    do
    {
      v11 = v5->m_nHeight <= 0;
      v20 = *v10;
      m_pBits = v5->m_pBits;
      v24 = m_pBits;
      v23 = 0;
      if ( !v11 )
      {
        do
        {
          v13 = v25;
          v26 = m_nWidth;
          if ( m_nWidth != 0 )
          {
            do
            {
              if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
                v14 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
              else
                v14 = 0;
              if ( v14 < 0 )
              {
                v15 = 1 - v14;
                if ( (buf->m_Flags & 1) != 0 )
                {
                  UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
                }
                else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
                {
                  UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
                }
                else
                {
                  UnsignedShort = 0;
                }
                memset(dst: v13, value: UnsignedShort, count: v15);
              }
              else
              {
                v15 = v14 + 1;
                CUtlBuffer::Get(this: buf, pMem: v13, size: v15);
              }
              v13 += v15;
              v26 -= v15;
            }
            while ( v26 != 0 );
            m_pBits = v24;
          }
          v5 = bitmap;
          m_nWidth = bitmap->m_nWidth;
          v17 = 0;
          if ( bitmap->m_nWidth > 0 )
          {
            do
            {
              m_pBits[v20] = v25[v17];
              m_nWidth = bitmap->m_nWidth;
              ++v17;
              m_pBits += 4;
            }
            while ( v17 < bitmap->m_nWidth );
            v24 = m_pBits;
          }
          ++v23;
        }
        while ( v23 < bitmap->m_nHeight );
        v10 = v22;
      }
      ++v10;
      v18 = v21-- == 1;
      v22 = v10;
    }
    while ( !v18 );
    v9 = nChannelsCount;
  }
  PSDConvertToRGBA8888(nChannelsCount: v9, mode, bitmap: v5, palette);
}

//------------------------------------------------------------------------------
// Address: 0x00406A00
// Name: bool PSDReadFileRGBA8888(class CUtlBuffer __near &,struct Bitmap_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PSDReadFileRGBA8888(CUtlBuffer *buf, Bitmap_t *bitmap)
{
  __int16 v2; // ax
  __int16 v3; // ax
  unsigned __int16 v4; // ax
  PSDMode_t v5; // ecx
  unsigned __int16 v6; // ax
  int v7; // esi
  bool result; // al
  int v9; // ebx
  void *v10; // esp
  unsigned __int16 Short; // ax
  char v12; // t0
  _BYTE v13[12]; // [esp+0h] [ebp-4Ch] BYREF
  PSDHeader_t header; // [esp+Ch] [ebp-40h] BYREF
  PSDPalette_t palette; // [esp+28h] [ebp-24h] BYREF
  int nWidth; // [esp+34h] [ebp-18h]
  int nHeight; // [esp+38h] [ebp-14h]
  int nChannelsCount; // [esp+3Ch] [ebp-10h]
  PSDMode_t mode; // [esp+40h] [ebp-Ch]
  unsigned __int8 *pPaletteBits; // [esp+44h] [ebp-8h]
  bool bSecondPassCMYKA; // [esp+4Bh] [ebp-1h]

  CUtlBuffer::Get(this: buf, pMem: &header, size: 26);
  if ( _byteswap_ulong(header.m_nSignature) != 943870035 )
    return false;
  LOBYTE(v2) = HIBYTE(header.m_nVersion);
  HIBYTE(v2) = header.m_nVersion;
  if ( v2 != 1 )
    return false;
  LOBYTE(v3) = HIBYTE(header.m_nDepth);
  HIBYTE(v3) = header.m_nDepth;
  if ( v3 != 8 )
    return false;
  LOBYTE(v4) = HIBYTE(header.m_nMode);
  HIBYTE(v4) = header.m_nMode;
  v5 = v4;
  mode = v5;
  LOBYTE(v6) = HIBYTE(header.m_nChannels);
  HIBYTE(v6) = header.m_nChannels;
  v7 = v6;
  nChannelsCount = v6;
  if ( v5 == MODE_MULTICHANNEL || v5 == MODE_LAB )
    return false;
  switch ( v5 )
  {
    case MODE_GREYSCALE:
    case MODE_PALETTIZED:
      if ( v6 == 1 || v6 == 2 )
        goto LABEL_13;
      return false;
    case MODE_RGBA:
      if ( v6 >= 3u )
        goto LABEL_13;
      return false;
    case MODE_CMYK:
      if ( v6 < 4u )
        return false;
LABEL_13:
      nWidth = _byteswap_ulong(header.m_nColumns);
      nHeight = _byteswap_ulong(header.m_nRows);
      v9 = _byteswap_ulong(CUtlBuffer::GetUnsignedInt(this: buf));
      v10 = alloca(v9);
      pPaletteBits = v13;
      memset(&palette, 0, sizeof(palette));
      if ( v9 != 0 )
      {
        CUtlBuffer::Get(this: buf, pMem: v13, size: v9);
        palette.m_pRed = pPaletteBits;
        palette.m_pBlue = &pPaletteBits[v9 / 3 + v9 / 3];
        v7 = nChannelsCount;
        palette.m_pGreen = &pPaletteBits[v9 / 3];
      }
      nChannelsCount = CUtlBuffer::GetUnsignedInt(this: buf);
      CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: _byteswap_ulong(nChannelsCount));
      nChannelsCount = CUtlBuffer::GetUnsignedInt(this: buf);
      CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: _byteswap_ulong(nChannelsCount));
      Short = CUtlBuffer::GetShort(this: buf);
      nChannelsCount = Short;
      v12 = Short;
      LOBYTE(Short) = HIBYTE(Short);
      HIBYTE(Short) = v12;
      HIWORD(pPaletteBits) = Short;
      Bitmap_t::Init(this: bitmap, nWidth, nHeight, imageFormat: IMAGE_FORMAT_RGBA8888);
      if ( v7 <= 4 || (bSecondPassCMYKA = true, mode != MODE_CMYK) )
        bSecondPassCMYKA = false;
      if ( HIWORD(pPaletteBits) != 0 )
      {
        CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: 2 * v7 * bitmap->m_nHeight);
        if ( v7 > 4 )
          v7 = 4;
        PSDReadCompressedChannels(buf, nChannelsCount: v7, mode, &palette, bitmap);
      }
      else
      {
        if ( v7 > 4 )
          v7 = 4;
        PSDReadUncompressedChannels(bitmap, buf, nChannelsCount: v7, mode, &palette);
      }
      if ( !bSecondPassCMYKA )
        goto LABEL_29;
      if ( HIWORD(pPaletteBits) != 0 )
      {
        PSDReadCompressedChannels(buf, nChannelsCount: 1, mode: MODE_COUNT, &palette, bitmap);
LABEL_29:
        result = true;
      }
      else
      {
        PSDReadUncompressedChannels(bitmap, buf, nChannelsCount: 1, mode: MODE_COUNT, &palette);
        result = true;
      }
      break;
    default:
      _Warning(a1: "Unsupported PSD color mode!\n");
      return false;
  }
  return result;
}

} // namespace height2ssbump

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1016E910
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned int>(unsigned int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned int>(CUtlBuffer *this, unsigned int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016E980
// Name: protected: bool CUtlBuffer::GetTypeText<short>(short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<short>(CUtlBuffer *this, __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016E9F0
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016EA60
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016EAA0
// Name: public: char CUtlBuffer::GetChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016EAD0
// Name: public: short CUtlBuffer::GetShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: (__int16 *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016EB70
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: (__int16 *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100463E0
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046420
// Name: public: char CUtlBuffer::GetChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10046320
// Name: void PadLine<unsigned char>(unsigned long,unsigned char,unsigned char __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PadLine<unsigned char>(unsigned int a1, unsigned __int8 a2, unsigned __int8 *src)
{
  while ( a2 - a1 > a1 )
    a2 >>= 1;
  memcpy(dst: &src[a1], src, count: a2 - a1);
}

//------------------------------------------------------------------------------
// Address: 0x10046360
// Name: void PadBlock<unsigned char>(unsigned long,unsigned char,unsigned char,unsigned char __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PadBlock<unsigned char>(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 *src)
{
  unsigned int v4; // ecx

  while ( 1 )
  {
    v4 = a3 - a1;
    if ( v4 <= a1 )
      break;
    a3 >>= 1;
  }
  memcpy(dst: &src[a1 * a2], src, count: v4 * a2);
}

} // namespace missionchooser

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00417440
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        unsigned int *outputBuffer,
        unsigned int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  unsigned int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (int *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F850
// Name: public: void Bitmap_t::Init(int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Bitmap_t::Init(Bitmap_t *this, int nWidth, int nHeight, ImageFormat imageFormat)
{
  const ImageFormatInfo_t *v5; // eax

  if ( this->m_pBits != nullptr )
  {
    operator delete(p: this->m_pBits);
    this->m_pBits = nullptr;
  }
  this->m_nWidth = nWidth;
  this->m_nHeight = nHeight;
  this->m_ImageFormat = imageFormat;
  v5 = ImageLoader::ImageFormatInfo(fmt: imageFormat);
  this->m_pBits = (unsigned __int8 *)operator new(size: nHeight * nWidth * v5->m_nNumBytes);
}

//------------------------------------------------------------------------------
// Address: 0x0046F8B0
// Name: PSDConvertToRGBA8888
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDConvertToRGBA8888(
        int nChannelsCount@<edx>,
        PSDMode_t mode@<ecx>,
        Bitmap_t *bitmap@<edi>,
        PSDPalette_t *palette)
{
  unsigned __int8 *m_pBits; // eax
  bool v5; // bl
  unsigned __int8 *v6; // edx
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // esi
  int m_nWidth; // ecx
  int v15; // edx
  unsigned __int8 v16; // cl
  int v17; // esi
  int v18; // ebx
  int v19; // edx
  unsigned __int8 v20; // cl
  unsigned __int8 v21; // cl
  unsigned __int8 v22; // cl
  int i; // [esp+Ch] [ebp-Ch]
  int k; // [esp+10h] [ebp-8h]
  int ka; // [esp+10h] [ebp-8h]
  bool bShouldFillInAlpha; // [esp+17h] [ebp-1h]

  m_pBits = bitmap->m_pBits;
  switch ( mode )
  {
    case MODE_GREYSCALE:
      v5 = nChannelsCount == 1;
      v13 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        m_nWidth = bitmap->m_nWidth;
        do
        {
          v15 = 0;
          if ( m_nWidth > 0 )
          {
            do
            {
              v16 = *m_pBits;
              m_pBits[1] = *m_pBits;
              m_pBits[2] = v16;
              m_nWidth = bitmap->m_nWidth;
              ++v15;
              m_pBits += 4;
            }
            while ( v15 < bitmap->m_nWidth );
          }
          ++v13;
        }
        while ( v13 < bitmap->m_nHeight );
      }
      goto LABEL_3;
    case MODE_PALETTIZED:
      v5 = nChannelsCount == 1;
      bShouldFillInAlpha = nChannelsCount == 1;
      k = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v10 = bitmap->m_nWidth;
        do
        {
          v11 = 0;
          if ( v10 > 0 )
          {
            do
            {
              v12 = *m_pBits;
              *m_pBits = palette->m_pRed[v12];
              m_pBits[1] = palette->m_pGreen[v12];
              m_pBits[2] = palette->m_pBlue[v12];
              v10 = bitmap->m_nWidth;
              ++v11;
              m_pBits += 4;
            }
            while ( v11 < bitmap->m_nWidth );
            v5 = bShouldFillInAlpha;
          }
          ++k;
        }
        while ( k < bitmap->m_nHeight );
      }
      goto LABEL_3;
    case MODE_RGBA:
      v5 = nChannelsCount == 3;
LABEL_3:
      if ( v5 )
      {
        v6 = bitmap->m_pBits;
        v7 = 0;
        if ( bitmap->m_nHeight > 0 )
        {
          v8 = bitmap->m_nWidth;
          do
          {
            v9 = 0;
            if ( v8 > 0 )
            {
              do
              {
                v6[3] = -1;
                v8 = bitmap->m_nWidth;
                ++v9;
                v6 += 4;
              }
              while ( v9 < bitmap->m_nWidth );
            }
            ++v7;
          }
          while ( v7 < bitmap->m_nHeight );
        }
      }
      break;
    case MODE_CMYK:
      for ( i = 0; i < bitmap->m_nHeight; ++i )
      {
        for ( ka = 0; ka < bitmap->m_nWidth; ++ka )
        {
          v17 = (unsigned __int8)(-1 - m_pBits[3]);
          v18 = v17 + (unsigned __int8)(-1 - m_pBits[2]);
          v19 = v17 + (unsigned __int8)(-1 - m_pBits[1]);
          if ( v17 + (unsigned int)(unsigned __int8)(-1 - *m_pBits) >= 0xFF )
            v20 = 0;
          else
            v20 = *m_pBits - v17;
          *m_pBits = v20;
          if ( v19 >= 255 )
            v21 = 0;
          else
            v21 = -1 - v19;
          m_pBits[1] = v21;
          if ( v18 >= 255 )
            v22 = 0;
          else
            v22 = -1 - v18;
          m_pBits[2] = v22;
          m_pBits[3] = -1;
          m_pBits += 4;
        }
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FA70
// Name: PSDReadUncompressedChannels
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDReadUncompressedChannels(
        Bitmap_t *bitmap@<esi>,
        CUtlBuffer *buf,
        int nChannelsCount,
        PSDMode_t mode,
        PSDPalette_t *palette)
{
  int m_nWidth; // edi
  void *v6; // esp
  int v7; // ecx
  int *v8; // eax
  bool v9; // cc
  unsigned __int8 *m_pBits; // ebx
  int i; // eax
  bool v12; // zf
  unsigned __int8 *v13; // eax
  bool v14; // bl
  unsigned __int8 *v15; // edx
  int v16; // edi
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edi
  int v23; // ecx
  int v24; // edx
  unsigned __int8 v25; // cl
  int v26; // edi
  unsigned int v27; // ecx
  int v28; // ebx
  int v29; // edx
  unsigned __int8 v30; // cl
  unsigned __int8 v31; // cl
  unsigned __int8 v32; // cl
  int v33; // [esp+0h] [ebp-1Ch] BYREF
  int v34; // [esp+8h] [ebp-14h]
  int v35; // [esp+Ch] [ebp-10h]
  int *v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+14h] [ebp-8h]
  void *pMem; // [esp+18h] [ebp-4h]
  int k; // [esp+28h] [ebp+Ch]
  bool v40; // [esp+2Bh] [ebp+Fh]
  int v41; // [esp+2Ch] [ebp+10h]
  int j; // [esp+2Ch] [ebp+10h]

  m_nWidth = bitmap->m_nWidth;
  v6 = alloca(bitmap->m_nWidth);
  v7 = nChannelsCount;
  pMem = &v33;
  if ( nChannelsCount > 0 )
  {
    v8 = s_pChannelIndex[mode];
    v36 = v8;
    v35 = nChannelsCount;
    do
    {
      v9 = bitmap->m_nHeight <= 0;
      m_pBits = bitmap->m_pBits;
      v34 = *v8;
      v37 = 0;
      if ( !v9 )
      {
        do
        {
          CUtlBuffer::Get(this: buf, (unsigned __int8 *)pMem, size: m_nWidth);
          m_nWidth = bitmap->m_nWidth;
          for ( i = 0; i < bitmap->m_nWidth; m_pBits += 4 )
          {
            m_pBits[v34] = *((_BYTE *)pMem + i);
            m_nWidth = bitmap->m_nWidth;
            ++i;
          }
          ++v37;
        }
        while ( v37 < bitmap->m_nHeight );
        v8 = v36;
        v7 = nChannelsCount;
      }
      ++v8;
      v12 = v35-- == 1;
      v36 = v8;
    }
    while ( !v12 );
  }
  v13 = bitmap->m_pBits;
  switch ( mode )
  {
    case MODE_GREYSCALE:
      v14 = v7 == 1;
      v22 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v23 = bitmap->m_nWidth;
        do
        {
          v24 = 0;
          if ( v23 > 0 )
          {
            do
            {
              v25 = *v13;
              v13[1] = *v13;
              v13[2] = v25;
              v23 = bitmap->m_nWidth;
              ++v24;
              v13 += 4;
            }
            while ( v24 < bitmap->m_nWidth );
          }
          ++v22;
        }
        while ( v22 < bitmap->m_nHeight );
      }
      goto LABEL_11;
    case MODE_PALETTIZED:
      v14 = v7 == 1;
      v40 = v7 == 1;
      v41 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v19 = bitmap->m_nWidth;
        do
        {
          v20 = 0;
          if ( v19 > 0 )
          {
            do
            {
              v21 = *v13;
              *v13 = palette->m_pRed[v21];
              v13[1] = palette->m_pGreen[v21];
              v13[2] = palette->m_pBlue[v21];
              v19 = bitmap->m_nWidth;
              ++v20;
              v13 += 4;
            }
            while ( v20 < bitmap->m_nWidth );
            v14 = v40;
          }
          ++v41;
        }
        while ( v41 < bitmap->m_nHeight );
      }
      goto LABEL_11;
    case MODE_RGBA:
      v14 = v7 == 3;
LABEL_11:
      if ( v14 )
      {
        v15 = bitmap->m_pBits;
        v16 = 0;
        if ( bitmap->m_nHeight > 0 )
        {
          v17 = bitmap->m_nWidth;
          do
          {
            v18 = 0;
            if ( v17 > 0 )
            {
              do
              {
                v15[3] = -1;
                v17 = bitmap->m_nWidth;
                ++v18;
                v15 += 4;
              }
              while ( v18 < bitmap->m_nWidth );
            }
            ++v16;
          }
          while ( v16 < bitmap->m_nHeight );
        }
      }
      break;
    case MODE_CMYK:
      for ( j = 0; j < bitmap->m_nHeight; ++j )
      {
        for ( k = 0; k < bitmap->m_nWidth; ++k )
        {
          v26 = (unsigned __int8)(-1 - v13[3]);
          v27 = v26 + (unsigned __int8)(-1 - *v13);
          v28 = v26 + (unsigned __int8)(-1 - v13[2]);
          v29 = v26 + (unsigned __int8)(-1 - v13[1]);
          v34 = v28;
          if ( v27 >= 0xFF )
          {
            v30 = 0;
          }
          else
          {
            v35 = 255 - v27;
            v30 = -1 - v27;
          }
          *v13 = v30;
          if ( v29 >= 255 )
            v31 = 0;
          else
            v31 = -1 - v29;
          v13[1] = v31;
          if ( v28 >= 255 )
            v32 = 0;
          else
            v32 = -1 - v28;
          v13[2] = v32;
          v13[3] = -1;
          v13 += 4;
        }
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FCC0
// Name: bool IsPSDFile(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPSDFile(CUtlBuffer *buf)
{
  int m_Get; // edi
  __int16 v3; // ax
  __int16 v4; // ax
  PSDHeader_t header; // [esp+8h] [ebp-1Ch] BYREF

  m_Get = buf->m_Get;
  CUtlBuffer::Get(this: buf, pMem: (unsigned __int8 *)&header, size: 26);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: m_Get);
  if ( _byteswap_ulong(header.m_nSignature) != 943870035 )
    return false;
  LOBYTE(v3) = HIBYTE(header.m_nVersion);
  HIBYTE(v3) = header.m_nVersion;
  if ( v3 != 1 )
    return false;
  LOBYTE(v4) = HIBYTE(header.m_nDepth);
  HIBYTE(v4) = header.m_nDepth;
  return v4 == 8;
}

//------------------------------------------------------------------------------
// Address: 0x0046FD20
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned int>(unsigned int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned int>(CUtlBuffer *this, unsigned int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046FD90
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046FE00
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FE80
// Name: public: unsigned int CUtlBuffer::GetUnsignedInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetUnsignedInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (unsigned int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046FF20
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046FFC0
// Name: PSDReadCompressedChannels
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDReadCompressedChannels(
        CUtlBuffer *buf@<eax>,
        int nChannelsCount,
        PSDMode_t mode,
        PSDPalette_t *palette,
        Bitmap_t *bitmap)
{
  Bitmap_t *v5; // ebx
  int m_nWidth; // esi
  void *v8; // esp
  int v9; // edx
  int *v10; // eax
  bool v11; // cc
  unsigned __int8 *m_pBits; // ecx
  unsigned __int8 *v13; // ebx
  char v14; // cl
  int v15; // esi
  unsigned __int8 UnsignedShort; // al
  int v17; // eax
  bool v18; // zf
  int v19; // [esp+0h] [ebp-28h] BYREF
  int v20; // [esp+Ch] [ebp-1Ch]
  int v21; // [esp+10h] [ebp-18h]
  int *v22; // [esp+14h] [ebp-14h]
  int v23; // [esp+18h] [ebp-10h]
  unsigned __int8 *v24; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 *v25; // [esp+20h] [ebp-8h]
  int v26; // [esp+24h] [ebp-4h]

  v5 = bitmap;
  m_nWidth = bitmap->m_nWidth;
  v8 = alloca(bitmap->m_nWidth);
  v9 = nChannelsCount;
  v25 = (unsigned __int8 *)&v19;
  if ( nChannelsCount > 0 )
  {
    v10 = s_pChannelIndex[mode];
    v22 = v10;
    v21 = nChannelsCount;
    do
    {
      v11 = v5->m_nHeight <= 0;
      v20 = *v10;
      m_pBits = v5->m_pBits;
      v24 = m_pBits;
      v23 = 0;
      if ( !v11 )
      {
        do
        {
          v13 = v25;
          v26 = m_nWidth;
          if ( m_nWidth != 0 )
          {
            do
            {
              if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
                v14 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
              else
                v14 = 0;
              if ( v14 < 0 )
              {
                v15 = 1 - v14;
                if ( (buf->m_Flags & 1) != 0 )
                {
                  UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
                }
                else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
                {
                  UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
                }
                else
                {
                  UnsignedShort = 0;
                }
                memset(dst: v13, value: UnsignedShort, count: v15);
              }
              else
              {
                v15 = v14 + 1;
                CUtlBuffer::Get(this: buf, pMem: v13, size: v15);
              }
              v13 += v15;
              v26 -= v15;
            }
            while ( v26 != 0 );
            m_pBits = v24;
          }
          v5 = bitmap;
          m_nWidth = bitmap->m_nWidth;
          v17 = 0;
          if ( bitmap->m_nWidth > 0 )
          {
            do
            {
              m_pBits[v20] = v25[v17];
              m_nWidth = bitmap->m_nWidth;
              ++v17;
              m_pBits += 4;
            }
            while ( v17 < bitmap->m_nWidth );
            v24 = m_pBits;
          }
          ++v23;
        }
        while ( v23 < bitmap->m_nHeight );
        v10 = v22;
      }
      ++v10;
      v18 = v21-- == 1;
      v22 = v10;
    }
    while ( !v18 );
    v9 = nChannelsCount;
  }
  PSDConvertToRGBA8888(nChannelsCount: v9, mode, bitmap: v5, palette);
}

//------------------------------------------------------------------------------
// Address: 0x00470120
// Name: bool PSDReadFileRGBA8888(class CUtlBuffer __near &,struct Bitmap_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PSDReadFileRGBA8888(CUtlBuffer *buf, Bitmap_t *bitmap)
{
  __int16 v2; // ax
  __int16 v3; // ax
  unsigned __int16 v4; // ax
  PSDMode_t v5; // ecx
  unsigned __int16 v6; // ax
  int v7; // esi
  bool result; // al
  int v9; // ebx
  void *v10; // esp
  unsigned __int16 Short; // ax
  char v12; // t0
  unsigned __int8 v13[12]; // [esp+0h] [ebp-4Ch] BYREF
  PSDHeader_t header; // [esp+Ch] [ebp-40h] BYREF
  PSDPalette_t palette; // [esp+28h] [ebp-24h] BYREF
  int nWidth; // [esp+34h] [ebp-18h]
  int nHeight; // [esp+38h] [ebp-14h]
  int nChannelsCount; // [esp+3Ch] [ebp-10h]
  PSDMode_t mode; // [esp+40h] [ebp-Ch]
  unsigned __int8 *pPaletteBits; // [esp+44h] [ebp-8h]
  bool bSecondPassCMYKA; // [esp+4Bh] [ebp-1h]

  CUtlBuffer::Get(this: buf, pMem: (unsigned __int8 *)&header, size: 26);
  if ( _byteswap_ulong(header.m_nSignature) != 943870035 )
    return false;
  LOBYTE(v2) = HIBYTE(header.m_nVersion);
  HIBYTE(v2) = header.m_nVersion;
  if ( v2 != 1 )
    return false;
  LOBYTE(v3) = HIBYTE(header.m_nDepth);
  HIBYTE(v3) = header.m_nDepth;
  if ( v3 != 8 )
    return false;
  LOBYTE(v4) = HIBYTE(header.m_nMode);
  HIBYTE(v4) = header.m_nMode;
  v5 = v4;
  mode = v5;
  LOBYTE(v6) = HIBYTE(header.m_nChannels);
  HIBYTE(v6) = header.m_nChannels;
  v7 = v6;
  nChannelsCount = v6;
  if ( v5 == MODE_MULTICHANNEL || v5 == MODE_LAB )
    return false;
  switch ( v5 )
  {
    case MODE_GREYSCALE:
    case MODE_PALETTIZED:
      if ( v6 == 1 || v6 == 2 )
        goto LABEL_13;
      return false;
    case MODE_RGBA:
      if ( v6 >= 3u )
        goto LABEL_13;
      return false;
    case MODE_CMYK:
      if ( v6 < 4u )
        return false;
LABEL_13:
      nWidth = _byteswap_ulong(header.m_nColumns);
      nHeight = _byteswap_ulong(header.m_nRows);
      v9 = _byteswap_ulong(CUtlBuffer::GetUnsignedInt(this: buf));
      v10 = alloca(v9);
      pPaletteBits = v13;
      memset(&palette, 0, sizeof(palette));
      if ( v9 != 0 )
      {
        CUtlBuffer::Get(this: buf, pMem: v13, size: v9);
        palette.m_pRed = pPaletteBits;
        palette.m_pBlue = &pPaletteBits[v9 / 3 + v9 / 3];
        v7 = nChannelsCount;
        palette.m_pGreen = &pPaletteBits[v9 / 3];
      }
      nChannelsCount = CUtlBuffer::GetUnsignedInt(this: buf);
      CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: _byteswap_ulong(nChannelsCount));
      nChannelsCount = CUtlBuffer::GetUnsignedInt(this: buf);
      CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: _byteswap_ulong(nChannelsCount));
      Short = CUtlBuffer::GetShort(this: buf);
      nChannelsCount = Short;
      v12 = Short;
      LOBYTE(Short) = HIBYTE(Short);
      HIBYTE(Short) = v12;
      HIWORD(pPaletteBits) = Short;
      Bitmap_t::Init(this: bitmap, nWidth, nHeight, imageFormat: IMAGE_FORMAT_RGBA8888);
      if ( v7 <= 4 || (bSecondPassCMYKA = true, mode != MODE_CMYK) )
        bSecondPassCMYKA = false;
      if ( HIWORD(pPaletteBits) != 0 )
      {
        CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: 2 * v7 * bitmap->m_nHeight);
        if ( v7 > 4 )
          v7 = 4;
        PSDReadCompressedChannels(buf, nChannelsCount: v7, mode, &palette, bitmap);
      }
      else
      {
        if ( v7 > 4 )
          v7 = 4;
        PSDReadUncompressedChannels(bitmap, buf, nChannelsCount: v7, mode, &palette);
      }
      if ( !bSecondPassCMYKA )
        goto LABEL_29;
      if ( HIWORD(pPaletteBits) != 0 )
      {
        PSDReadCompressedChannels(buf, nChannelsCount: 1, mode: MODE_COUNT, &palette, bitmap);
LABEL_29:
        result = true;
      }
      else
      {
        PSDReadUncompressedChannels(bitmap, buf, nChannelsCount: 1, mode: MODE_COUNT, &palette);
        result = true;
      }
      break;
    default:
      _Warning(a1: "Unsupported PSD color mode!\n");
      return false;
  }
  return result;
}

} // namespace mksheet

// ============================================================
// Overlay from psdinfo (Missing functions)
// ============================================================
namespace psdinfo {

//------------------------------------------------------------------------------
// Address: 0x00401780
// Name: bool IsPSDFile(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPSDFile(CUtlBuffer *buf)
{
  int m_Get; // edi
  __int16 v3; // ax
  __int16 v4; // ax
  PSDHeader_t header; // [esp+8h] [ebp-1Ch] BYREF

  m_Get = buf->m_Get;
  CUtlBuffer::Get(this: buf, pMem: &header, size: 26);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: m_Get);
  if ( _byteswap_ulong(header.m_nSignature) != 943870035 )
    return false;
  LOBYTE(v3) = HIBYTE(header.m_nVersion);
  HIBYTE(v3) = header.m_nVersion;
  if ( v3 != 1 )
    return false;
  LOBYTE(v4) = HIBYTE(header.m_nDepth);
  HIBYTE(v4) = header.m_nDepth;
  return v4 == 8;
}

//------------------------------------------------------------------------------
// Address: 0x004017E0
// Name: public: struct PSDImageResources::ResElement PSDImageResources::FindElement(enum PSDImageResources::Resource)const
// Source: json
//------------------------------------------------------------------------------
PSDImageResources::ResElement *__thiscall PSDImageResources::FindElement(
        PSDImageResources *this,
        PSDImageResources::ResElement *result,
        PSDImageResources::Resource eType)
{
  const unsigned __int8 *m_pvBuffer; // edx
  const unsigned __int8 *v4; // esi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // cx
  unsigned __int16 v7; // ax
  const unsigned __int8 *v8; // edx

  m_pvBuffer = this->m_pvBuffer;
  v4 = &m_pvBuffer[this->m_numBytes];
  *(_QWORD *)&result->m_eType = 0;
  result->m_pvData = nullptr;
  if ( m_pvBuffer < v4 )
  {
    while ( _byteswap_ulong(*(_DWORD *)m_pvBuffer) == 943868237 )
    {
      LOBYTE(v5) = HIBYTE(*((_WORD *)m_pvBuffer + 2));
      HIBYTE(v5) = *((_WORD *)m_pvBuffer + 2);
      v6 = v5;
      LOBYTE(v7) = HIBYTE(*((_WORD *)m_pvBuffer + 5));
      HIBYTE(v7) = *((_WORD *)m_pvBuffer + 5);
      v8 = m_pvBuffer + 12;
      if ( v6 == eType )
      {
        result->m_eType = eType;
        result->m_numBytes = v7;
        result->m_pvData = v8;
        return result;
      }
      m_pvBuffer = &v8[(v7 + 1) & 0xFFFFFFFE];
      if ( m_pvBuffer >= v4 )
        return result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401870
// Name: public: struct PSDResFileInfo::ResFileInfoElement PSDResFileInfo::FindElement(enum PSDResFileInfo::ResFileInfo)const
// Source: json
//------------------------------------------------------------------------------
PSDResFileInfo::ResFileInfoElement *__thiscall PSDResFileInfo::FindElement(
        PSDResFileInfo *this,
        PSDResFileInfo::ResFileInfoElement *result,
        PSDResFileInfo::ResFileInfo eType)
{
  const unsigned __int8 *m_pvData; // edx
  const unsigned __int8 *v4; // eax
  __int16 v5; // ax
  __int16 v6; // si
  unsigned __int16 v7; // ax
  unsigned __int8 v8; // cl
  const unsigned __int8 *v9; // edx
  const unsigned __int8 *pvBufferEnd; // [esp+4h] [ebp-4h]

  m_pvData = this->m_res.m_pvData;
  v4 = &m_pvData[this->m_res.m_numBytes];
  *(_QWORD *)&result->m_eType = 0;
  result->m_pvData = nullptr;
  pvBufferEnd = v4;
  if ( m_pvData < v4 )
  {
    while ( 1 )
    {
      LOBYTE(v5) = HIBYTE(*(_WORD *)m_pvData);
      HIBYTE(v5) = *(_WORD *)m_pvData;
      v6 = v5;
      LOBYTE(v7) = HIBYTE(*(_WORD *)(m_pvData + 3));
      HIBYTE(v7) = *(_WORD *)(m_pvData + 3);
      v8 = m_pvData[2];
      v9 = m_pvData + 5;
      if ( v8 == eType && v6 == 7170 )
        break;
      m_pvData = &v9[v7];
      if ( m_pvData >= pvBufferEnd )
        return result;
    }
    result->m_eType = eType;
    result->m_numBytes = v7;
    result->m_pvData = v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401900
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        unsigned int *outputBuffer,
        unsigned int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  unsigned int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (int *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401990
// Name: public: unsigned int CUtlBuffer::GetUnsignedInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetUnsignedInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (unsigned int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401A30
// Name: class PSDImageResources PSDGetImageResources(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
PSDImageResources *__cdecl PSDGetImageResources(PSDImageResources *result, CUtlBuffer *buf)
{
  int m_Get; // ebx
  unsigned int UnsignedInt; // eax
  PSDHeader_t header; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlBuffer *bufa; // [esp+34h] [ebp+Ch]

  m_Get = buf->m_Get;
  CUtlBuffer::Get(this: buf, pMem: &header, size: 26);
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: buf);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: _byteswap_ulong(UnsignedInt));
  bufa = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: buf);
  result->m_pvBuffer = &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
  result->m_numBytes = _byteswap_ulong((unsigned int)bufa);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: m_Get);
  return result;
}

} // namespace psdinfo

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00448FF0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EAB00
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned int>(unsigned int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned int>(CUtlBuffer *this, unsigned int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EAB70
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EABE0
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

} // namespace sceneviewer

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100342C0
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034200
// Name: void PadLine<unsigned char>(unsigned long,unsigned char,unsigned char __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PadLine<unsigned char>(unsigned int a1, unsigned __int8 a2, unsigned __int8 *src)
{
  while ( a2 - a1 > a1 )
    a2 >>= 1;
  memcpy(dst: &src[a1], src, count: a2 - a1);
}

//------------------------------------------------------------------------------
// Address: 0x10034240
// Name: void PadBlock<unsigned char>(unsigned long,unsigned char,unsigned char,unsigned char __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PadBlock<unsigned char>(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 *src)
{
  unsigned int v4; // ecx

  while ( 1 )
  {
    v4 = a3 - a1;
    if ( v4 <= a1 )
      break;
    a3 >>= 1;
  }
  memcpy(dst: &src[a1 * a2], src, count: v4 * a2);
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0043CB00
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned int>(unsigned int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned int>(CUtlBuffer *this, unsigned int *value, unsigned int nRadix)
{
  int v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  int nIncrement; // [esp+8h] [ebp-4h] BYREF

  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
  {
    *value = 0;
    return 0;
  }
  nLength = (int)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = nLength;
  *value = strtoul(nptr: (const char *)nLength, endptr: (char **)&nLength, ibase: nRadix);
  if ( nLength == v5 )
    return 0;
  this->m_Get += nLength - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043CB70
// Name: protected: bool CUtlBuffer::GetTypeText<short>(short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<short>(CUtlBuffer *this, __int16 *value, unsigned int nRadix)
{
  int v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  int nIncrement; // [esp+8h] [ebp-4h] BYREF

  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
  {
    *value = 0;
    return 0;
  }
  nLength = (int)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = nLength;
  *value = strtol(nptr: (const char *)nLength, endptr: (char **)&nLength, ibase: nRadix);
  if ( nLength == v5 )
    return 0;
  this->m_Get += nLength - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043CBE0
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, unsigned int nRadix)
{
  int v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  int nIncrement; // [esp+8h] [ebp-4h] BYREF

  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
  {
    *value = 0;
    return 0;
  }
  nLength = (int)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = nLength;
  *value = strtoul(nptr: (const char *)nLength, endptr: (char **)&nLength, ibase: nRadix);
  if ( nLength == v5 )
    return 0;
  this->m_Get += nLength - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043CC50
// Name: public: void CByteswap::SwapBufferToTargetEndian<short>(short __near *,short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        __int16 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = (unsigned __int8 *)inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CCE0
// Name: protected: void CUtlBuffer::GetTypeBin<short>(short __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<short>(CUtlBuffer *this, __int16 *dest)
{
  int v3; // eax

  if ( CUtlBuffer::CheckGet(this, nSize: 2) )
  {
    v3 = this->m_Get - this->m_nOffset;
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<short>(
        this: &this->m_Byteswap,
        outputBuffer: (unsigned __int8 *)dest,
        inputBuffer: (__int16 *)&this->m_Memory.m_pMemory[v3],
        count: 1);
    else
      *dest = *(_WORD *)&this->m_Memory.m_pMemory[v3];
    this->m_Get += 2;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CD40
// Name: public: char CUtlBuffer::GetChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043CD70
// Name: public: short CUtlBuffer::GetShort(void)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CUtlBuffer::GetShort(CUtlBuffer *this)
{
  CUtlBuffer *dest; // [esp+4h] [ebp-4h] BYREF

  dest = this;
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::GetTypeText<short>(this, value: (__int16 *)&dest, nRadix: 0xAu);
  else
    CUtlBuffer::GetTypeBin<short>(this, (__int16 *)&dest);
  return (__int16)dest;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10013F60
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        unsigned int *outputBuffer,
        unsigned int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  unsigned int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = (int *)outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1000ABA0
// Name: PSDConvertToRGBA8888
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDConvertToRGBA8888(
        int nChannelsCount@<edx>,
        PSDMode_t mode@<ecx>,
        Bitmap_t *bitmap@<edi>,
        PSDPalette_t *palette)
{
  unsigned __int8 *m_pBits; // eax
  bool v5; // bl
  unsigned __int8 *v6; // edx
  int v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // esi
  int m_nWidth; // ecx
  int v15; // edx
  unsigned __int8 v16; // cl
  int v17; // esi
  int v18; // ebx
  int v19; // edx
  unsigned __int8 v20; // cl
  unsigned __int8 v21; // cl
  unsigned __int8 v22; // cl
  int i; // [esp+Ch] [ebp-Ch]
  int k; // [esp+10h] [ebp-8h]
  int ka; // [esp+10h] [ebp-8h]
  bool bShouldFillInAlpha; // [esp+17h] [ebp-1h]

  m_pBits = bitmap->m_pBits;
  switch ( mode )
  {
    case MODE_GREYSCALE:
      v5 = nChannelsCount == 1;
      v13 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        m_nWidth = bitmap->m_nWidth;
        do
        {
          v15 = 0;
          if ( m_nWidth > 0 )
          {
            do
            {
              v16 = *m_pBits;
              m_pBits[1] = *m_pBits;
              m_pBits[2] = v16;
              m_nWidth = bitmap->m_nWidth;
              ++v15;
              m_pBits += 4;
            }
            while ( v15 < bitmap->m_nWidth );
          }
          ++v13;
        }
        while ( v13 < bitmap->m_nHeight );
      }
      goto LABEL_3;
    case MODE_PALETTIZED:
      v5 = nChannelsCount == 1;
      bShouldFillInAlpha = nChannelsCount == 1;
      k = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v10 = bitmap->m_nWidth;
        do
        {
          v11 = 0;
          if ( v10 > 0 )
          {
            do
            {
              v12 = *m_pBits;
              *m_pBits = palette->m_pRed[v12];
              m_pBits[1] = palette->m_pGreen[v12];
              m_pBits[2] = palette->m_pBlue[v12];
              v10 = bitmap->m_nWidth;
              ++v11;
              m_pBits += 4;
            }
            while ( v11 < bitmap->m_nWidth );
            v5 = bShouldFillInAlpha;
          }
          ++k;
        }
        while ( k < bitmap->m_nHeight );
      }
      goto LABEL_3;
    case MODE_RGBA:
      v5 = nChannelsCount == 3;
LABEL_3:
      if ( v5 )
      {
        v6 = bitmap->m_pBits;
        v7 = 0;
        if ( bitmap->m_nHeight > 0 )
        {
          v8 = bitmap->m_nWidth;
          do
          {
            v9 = 0;
            if ( v8 > 0 )
            {
              do
              {
                v6[3] = -1;
                v8 = bitmap->m_nWidth;
                ++v9;
                v6 += 4;
              }
              while ( v9 < bitmap->m_nWidth );
            }
            ++v7;
          }
          while ( v7 < bitmap->m_nHeight );
        }
      }
      break;
    case MODE_CMYK:
      for ( i = 0; i < bitmap->m_nHeight; ++i )
      {
        for ( ka = 0; ka < bitmap->m_nWidth; ++ka )
        {
          v17 = (unsigned __int8)(-1 - m_pBits[3]);
          v18 = v17 + (unsigned __int8)(-1 - m_pBits[2]);
          v19 = v17 + (unsigned __int8)(-1 - m_pBits[1]);
          if ( v17 + (unsigned int)(unsigned __int8)(-1 - *m_pBits) >= 0xFF )
            v20 = 0;
          else
            v20 = *m_pBits - v17;
          *m_pBits = v20;
          if ( v19 >= 255 )
            v21 = 0;
          else
            v21 = -1 - v19;
          m_pBits[1] = v21;
          if ( v18 >= 255 )
            v22 = 0;
          else
            v22 = -1 - v18;
          m_pBits[2] = v22;
          m_pBits[3] = -1;
          m_pBits += 4;
        }
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AD60
// Name: PSDReadUncompressedChannels
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDReadUncompressedChannels(
        Bitmap_t *bitmap@<esi>,
        CUtlBuffer *buf,
        int nChannelsCount,
        PSDMode_t mode,
        PSDPalette_t *palette)
{
  int m_nWidth; // edi
  void *v6; // esp
  int v7; // ecx
  int *v8; // eax
  bool v9; // cc
  unsigned __int8 *m_pBits; // ebx
  int i; // eax
  bool v12; // zf
  unsigned __int8 *v13; // eax
  bool v14; // bl
  unsigned __int8 *v15; // edx
  int v16; // edi
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edi
  int v23; // ecx
  int v24; // edx
  unsigned __int8 v25; // cl
  int v26; // edi
  unsigned int v27; // ecx
  int v28; // ebx
  int v29; // edx
  unsigned __int8 v30; // cl
  unsigned __int8 v31; // cl
  unsigned __int8 v32; // cl
  int v33; // [esp+0h] [ebp-1Ch] BYREF
  int v34; // [esp+8h] [ebp-14h]
  int v35; // [esp+Ch] [ebp-10h]
  int *v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+14h] [ebp-8h]
  void *pMem; // [esp+18h] [ebp-4h]
  int k; // [esp+28h] [ebp+Ch]
  bool v40; // [esp+2Bh] [ebp+Fh]
  int v41; // [esp+2Ch] [ebp+10h]
  int j; // [esp+2Ch] [ebp+10h]

  m_nWidth = bitmap->m_nWidth;
  v6 = alloca(bitmap->m_nWidth);
  v7 = nChannelsCount;
  pMem = &v33;
  if ( nChannelsCount > 0 )
  {
    v8 = s_pChannelIndex[mode];
    v36 = v8;
    v35 = nChannelsCount;
    do
    {
      v9 = bitmap->m_nHeight <= 0;
      m_pBits = bitmap->m_pBits;
      v34 = *v8;
      v37 = 0;
      if ( !v9 )
      {
        do
        {
          CUtlBuffer::Get(this: buf, pMem, size: m_nWidth);
          m_nWidth = bitmap->m_nWidth;
          for ( i = 0; i < bitmap->m_nWidth; m_pBits += 4 )
          {
            m_pBits[v34] = *((_BYTE *)pMem + i);
            m_nWidth = bitmap->m_nWidth;
            ++i;
          }
          ++v37;
        }
        while ( v37 < bitmap->m_nHeight );
        v8 = v36;
        v7 = nChannelsCount;
      }
      ++v8;
      v12 = v35-- == 1;
      v36 = v8;
    }
    while ( !v12 );
  }
  v13 = bitmap->m_pBits;
  switch ( mode )
  {
    case MODE_GREYSCALE:
      v14 = v7 == 1;
      v22 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v23 = bitmap->m_nWidth;
        do
        {
          v24 = 0;
          if ( v23 > 0 )
          {
            do
            {
              v25 = *v13;
              v13[1] = *v13;
              v13[2] = v25;
              v23 = bitmap->m_nWidth;
              ++v24;
              v13 += 4;
            }
            while ( v24 < bitmap->m_nWidth );
          }
          ++v22;
        }
        while ( v22 < bitmap->m_nHeight );
      }
      goto LABEL_11;
    case MODE_PALETTIZED:
      v14 = v7 == 1;
      v40 = v7 == 1;
      v41 = 0;
      if ( bitmap->m_nHeight > 0 )
      {
        v19 = bitmap->m_nWidth;
        do
        {
          v20 = 0;
          if ( v19 > 0 )
          {
            do
            {
              v21 = *v13;
              *v13 = palette->m_pRed[v21];
              v13[1] = palette->m_pGreen[v21];
              v13[2] = palette->m_pBlue[v21];
              v19 = bitmap->m_nWidth;
              ++v20;
              v13 += 4;
            }
            while ( v20 < bitmap->m_nWidth );
            v14 = v40;
          }
          ++v41;
        }
        while ( v41 < bitmap->m_nHeight );
      }
      goto LABEL_11;
    case MODE_RGBA:
      v14 = v7 == 3;
LABEL_11:
      if ( v14 )
      {
        v15 = bitmap->m_pBits;
        v16 = 0;
        if ( bitmap->m_nHeight > 0 )
        {
          v17 = bitmap->m_nWidth;
          do
          {
            v18 = 0;
            if ( v17 > 0 )
            {
              do
              {
                v15[3] = -1;
                v17 = bitmap->m_nWidth;
                ++v18;
                v15 += 4;
              }
              while ( v18 < bitmap->m_nWidth );
            }
            ++v16;
          }
          while ( v16 < bitmap->m_nHeight );
        }
      }
      break;
    case MODE_CMYK:
      for ( j = 0; j < bitmap->m_nHeight; ++j )
      {
        for ( k = 0; k < bitmap->m_nWidth; ++k )
        {
          v26 = (unsigned __int8)(-1 - v13[3]);
          v27 = v26 + (unsigned __int8)(-1 - *v13);
          v28 = v26 + (unsigned __int8)(-1 - v13[2]);
          v29 = v26 + (unsigned __int8)(-1 - v13[1]);
          v34 = v28;
          if ( v27 >= 0xFF )
          {
            v30 = 0;
          }
          else
          {
            v35 = 255 - v27;
            v30 = -1 - v27;
          }
          *v13 = v30;
          if ( v29 >= 255 )
            v31 = 0;
          else
            v31 = -1 - v29;
          v13[1] = v31;
          if ( v28 >= 255 )
            v32 = 0;
          else
            v32 = -1 - v28;
          v13[2] = v32;
          v13[3] = -1;
          v13 += 4;
        }
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AFB0
// Name: bool IsPSDFile(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPSDFile(CUtlBuffer *buf)
{
  int m_Get; // edi
  __int16 v3; // ax
  __int16 v4; // ax
  PSDHeader_t header; // [esp+8h] [ebp-1Ch] BYREF

  m_Get = buf->m_Get;
  CUtlBuffer::Get(this: buf, pMem: &header, size: 26);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: m_Get);
  if ( _byteswap_ulong(header.m_nSignature) != 943870035 )
    return false;
  LOBYTE(v3) = HIBYTE(header.m_nVersion);
  HIBYTE(v3) = header.m_nVersion;
  if ( v3 != 1 )
    return false;
  LOBYTE(v4) = HIBYTE(header.m_nDepth);
  HIBYTE(v4) = header.m_nDepth;
  return v4 == 8;
}

//------------------------------------------------------------------------------
// Address: 0x1000B010
// Name: bool PSDGetInfo(class CUtlBuffer __near &,int __near *,int __near *,enum ImageFormat __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PSDGetInfo(CUtlBuffer *buf, int *pWidth, int *pHeight, ImageFormat *pImageFormat, float *pSourceGamma)
{
  int m_Get; // edi
  __int16 v7; // ax
  __int16 v8; // ax
  __int16 v9; // ax
  PSDHeader_t header; // [esp+8h] [ebp-1Ch] BYREF

  m_Get = buf->m_Get;
  CUtlBuffer::Get(this: buf, pMem: &header, size: 26);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: m_Get);
  if ( _byteswap_ulong(header.m_nSignature) != 943870035 )
    return 0;
  LOBYTE(v7) = HIBYTE(header.m_nVersion);
  HIBYTE(v7) = header.m_nVersion;
  if ( v7 != 1 )
    return 0;
  LOBYTE(v8) = HIBYTE(header.m_nDepth);
  HIBYTE(v8) = header.m_nDepth;
  if ( v8 != 8 )
    return 0;
  *pWidth = _byteswap_ulong(header.m_nColumns);
  *pHeight = _byteswap_ulong(header.m_nRows);
  LOBYTE(v9) = HIBYTE(header.m_nChannels);
  HIBYTE(v9) = header.m_nChannels;
  *pImageFormat = v9 != 3 ? IMAGE_FORMAT_RGBA8888 : IMAGE_FORMAT_RGB888;
  *pSourceGamma = 2.2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B0B0
// Name: public: struct PSDImageResources::ResElement PSDImageResources::FindElement(enum PSDImageResources::Resource)const
// Source: json
//------------------------------------------------------------------------------
PSDImageResources::ResElement *__thiscall PSDImageResources::FindElement(
        PSDImageResources *this,
        PSDImageResources::ResElement *result,
        PSDImageResources::Resource eType)
{
  const unsigned __int8 *m_pvBuffer; // edx
  const unsigned __int8 *v4; // esi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // cx
  unsigned __int16 v7; // ax
  const unsigned __int8 *v8; // edx

  m_pvBuffer = this->m_pvBuffer;
  v4 = &m_pvBuffer[this->m_numBytes];
  *(_QWORD *)&result->m_eType = 0;
  result->m_pvData = nullptr;
  if ( m_pvBuffer < v4 )
  {
    while ( _byteswap_ulong(*(_DWORD *)m_pvBuffer) == 943868237 )
    {
      LOBYTE(v5) = HIBYTE(*((_WORD *)m_pvBuffer + 2));
      HIBYTE(v5) = *((_WORD *)m_pvBuffer + 2);
      v6 = v5;
      LOBYTE(v7) = HIBYTE(*((_WORD *)m_pvBuffer + 5));
      HIBYTE(v7) = *((_WORD *)m_pvBuffer + 5);
      v8 = m_pvBuffer + 12;
      if ( v6 == eType )
      {
        result->m_eType = eType;
        result->m_numBytes = v7;
        result->m_pvData = v8;
        return result;
      }
      m_pvBuffer = &v8[(v7 + 1) & 0xFFFFFFFE];
      if ( m_pvBuffer >= v4 )
        return result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B140
// Name: public: struct PSDResFileInfo::ResFileInfoElement PSDResFileInfo::FindElement(enum PSDResFileInfo::ResFileInfo)const
// Source: json
//------------------------------------------------------------------------------
PSDResFileInfo::ResFileInfoElement *__thiscall PSDResFileInfo::FindElement(
        PSDResFileInfo *this,
        PSDResFileInfo::ResFileInfoElement *result,
        PSDResFileInfo::ResFileInfo eType)
{
  const unsigned __int8 *m_pvData; // edx
  const unsigned __int8 *v4; // eax
  __int16 v5; // ax
  __int16 v6; // si
  unsigned __int16 v7; // ax
  unsigned __int8 v8; // cl
  const unsigned __int8 *v9; // edx
  const unsigned __int8 *pvBufferEnd; // [esp+4h] [ebp-4h]

  m_pvData = this->m_res.m_pvData;
  v4 = &m_pvData[this->m_res.m_numBytes];
  *(_QWORD *)&result->m_eType = 0;
  result->m_pvData = nullptr;
  pvBufferEnd = v4;
  if ( m_pvData < v4 )
  {
    while ( 1 )
    {
      LOBYTE(v5) = HIBYTE(*(_WORD *)m_pvData);
      HIBYTE(v5) = *(_WORD *)m_pvData;
      v6 = v5;
      LOBYTE(v7) = HIBYTE(*(_WORD *)(m_pvData + 3));
      HIBYTE(v7) = *(_WORD *)(m_pvData + 3);
      v8 = m_pvData[2];
      v9 = m_pvData + 5;
      if ( v8 == eType && v6 == 7170 )
        break;
      m_pvData = &v9[v7];
      if ( m_pvData >= pvBufferEnd )
        return result;
    }
    result->m_eType = eType;
    result->m_numBytes = v7;
    result->m_pvData = v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B1D0
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned int>(unsigned int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned int>(CUtlBuffer *this, unsigned int *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B240
// Name: protected: bool CUtlBuffer::GetTypeText<short>(short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<short>(CUtlBuffer *this, __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtol(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B2B0
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B320
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B3B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B430
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B470
// Name: public: unsigned int CUtlBuffer::GetUnsignedInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetUnsignedInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: (int *)&i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B510
// Name: class PSDImageResources PSDGetImageResources(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
PSDImageResources *__cdecl PSDGetImageResources(PSDImageResources *result, CUtlBuffer *buf)
{
  int m_Get; // ebx
  unsigned int UnsignedInt; // eax
  PSDHeader_t header; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlBuffer *bufa; // [esp+34h] [ebp+Ch]

  m_Get = buf->m_Get;
  CUtlBuffer::Get(this: buf, pMem: &header, size: 26);
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: buf);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: _byteswap_ulong(UnsignedInt));
  bufa = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: buf);
  result->m_pvBuffer = &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
  result->m_numBytes = _byteswap_ulong((unsigned int)bufa);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: m_Get);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B580
// Name: public: short CUtlBuffer::GetShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B620
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B6C0
// Name: PSDReadCompressedChannels
// Source: json
//------------------------------------------------------------------------------
void __usercall PSDReadCompressedChannels(
        CUtlBuffer *buf@<eax>,
        int nChannelsCount,
        PSDMode_t mode,
        PSDPalette_t *palette,
        Bitmap_t *bitmap)
{
  Bitmap_t *v5; // ebx
  int m_nWidth; // esi
  void *v8; // esp
  int v9; // edx
  int *v10; // eax
  bool v11; // cc
  unsigned __int8 *m_pBits; // ecx
  unsigned __int8 *v13; // ebx
  char v14; // cl
  int v15; // esi
  unsigned __int8 UnsignedShort; // al
  int v17; // eax
  bool v18; // zf
  int v19; // [esp+0h] [ebp-28h] BYREF
  int v20; // [esp+Ch] [ebp-1Ch]
  int v21; // [esp+10h] [ebp-18h]
  int *v22; // [esp+14h] [ebp-14h]
  int v23; // [esp+18h] [ebp-10h]
  unsigned __int8 *v24; // [esp+1Ch] [ebp-Ch]
  unsigned __int8 *v25; // [esp+20h] [ebp-8h]
  int v26; // [esp+24h] [ebp-4h]

  v5 = bitmap;
  m_nWidth = bitmap->m_nWidth;
  v8 = alloca(bitmap->m_nWidth);
  v9 = nChannelsCount;
  v25 = (unsigned __int8 *)&v19;
  if ( nChannelsCount > 0 )
  {
    v10 = s_pChannelIndex[mode];
    v22 = v10;
    v21 = nChannelsCount;
    do
    {
      v11 = v5->m_nHeight <= 0;
      v20 = *v10;
      m_pBits = v5->m_pBits;
      v24 = m_pBits;
      v23 = 0;
      if ( !v11 )
      {
        do
        {
          v13 = v25;
          v26 = m_nWidth;
          if ( m_nWidth != 0 )
          {
            do
            {
              if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
                v14 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
              else
                v14 = 0;
              if ( v14 < 0 )
              {
                v15 = 1 - v14;
                if ( (buf->m_Flags & 1) != 0 )
                {
                  UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
                }
                else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
                {
                  UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
                }
                else
                {
                  UnsignedShort = 0;
                }
                memset(dst: v13, value: UnsignedShort, count: v15);
              }
              else
              {
                v15 = v14 + 1;
                CUtlBuffer::Get(this: buf, pMem: v13, size: v15);
              }
              v13 += v15;
              v26 -= v15;
            }
            while ( v26 != 0 );
            m_pBits = v24;
          }
          v5 = bitmap;
          m_nWidth = bitmap->m_nWidth;
          v17 = 0;
          if ( bitmap->m_nWidth > 0 )
          {
            do
            {
              m_pBits[v20] = v25[v17];
              m_nWidth = bitmap->m_nWidth;
              ++v17;
              m_pBits += 4;
            }
            while ( v17 < bitmap->m_nWidth );
            v24 = m_pBits;
          }
          ++v23;
        }
        while ( v23 < bitmap->m_nHeight );
        v10 = v22;
      }
      ++v10;
      v18 = v21-- == 1;
      v22 = v10;
    }
    while ( !v18 );
    v9 = nChannelsCount;
  }
  PSDConvertToRGBA8888(nChannelsCount: v9, mode, bitmap: v5, palette);
}

//------------------------------------------------------------------------------
// Address: 0x1000B820
// Name: bool PSDReadFileRGBA8888(class CUtlBuffer __near &,struct Bitmap_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PSDReadFileRGBA8888(CUtlBuffer *buf, Bitmap_t *bitmap)
{
  __int16 v2; // ax
  __int16 v3; // ax
  unsigned __int16 v4; // ax
  PSDMode_t v5; // ecx
  unsigned __int16 v6; // ax
  int v7; // esi
  bool result; // al
  int v9; // ebx
  void *v10; // esp
  unsigned __int16 Short; // ax
  char v12; // t0
  _BYTE v13[12]; // [esp+0h] [ebp-4Ch] BYREF
  PSDHeader_t header; // [esp+Ch] [ebp-40h] BYREF
  PSDPalette_t palette; // [esp+28h] [ebp-24h] BYREF
  int nWidth; // [esp+34h] [ebp-18h]
  int nHeight; // [esp+38h] [ebp-14h]
  int nChannelsCount; // [esp+3Ch] [ebp-10h]
  PSDMode_t mode; // [esp+40h] [ebp-Ch]
  unsigned __int8 *pPaletteBits; // [esp+44h] [ebp-8h]
  bool bSecondPassCMYKA; // [esp+4Bh] [ebp-1h]

  CUtlBuffer::Get(this: buf, pMem: &header, size: 26);
  if ( _byteswap_ulong(header.m_nSignature) != 943870035 )
    return false;
  LOBYTE(v2) = HIBYTE(header.m_nVersion);
  HIBYTE(v2) = header.m_nVersion;
  if ( v2 != 1 )
    return false;
  LOBYTE(v3) = HIBYTE(header.m_nDepth);
  HIBYTE(v3) = header.m_nDepth;
  if ( v3 != 8 )
    return false;
  LOBYTE(v4) = HIBYTE(header.m_nMode);
  HIBYTE(v4) = header.m_nMode;
  v5 = v4;
  mode = v5;
  LOBYTE(v6) = HIBYTE(header.m_nChannels);
  HIBYTE(v6) = header.m_nChannels;
  v7 = v6;
  nChannelsCount = v6;
  if ( v5 == MODE_MULTICHANNEL || v5 == MODE_LAB )
    return false;
  switch ( v5 )
  {
    case MODE_GREYSCALE:
    case MODE_PALETTIZED:
      if ( v6 == 1 || v6 == 2 )
        goto LABEL_13;
      return false;
    case MODE_RGBA:
      if ( v6 >= 3u )
        goto LABEL_13;
      return false;
    case MODE_CMYK:
      if ( v6 < 4u )
        return false;
LABEL_13:
      nWidth = _byteswap_ulong(header.m_nColumns);
      nHeight = _byteswap_ulong(header.m_nRows);
      v9 = _byteswap_ulong(CUtlBuffer::GetUnsignedInt(this: buf));
      v10 = alloca(v9);
      pPaletteBits = v13;
      memset(&palette, 0, sizeof(palette));
      if ( v9 != 0 )
      {
        CUtlBuffer::Get(this: buf, pMem: v13, size: v9);
        palette.m_pRed = pPaletteBits;
        palette.m_pBlue = &pPaletteBits[v9 / 3 + v9 / 3];
        v7 = nChannelsCount;
        palette.m_pGreen = &pPaletteBits[v9 / 3];
      }
      nChannelsCount = CUtlBuffer::GetUnsignedInt(this: buf);
      CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: _byteswap_ulong(nChannelsCount));
      nChannelsCount = CUtlBuffer::GetUnsignedInt(this: buf);
      CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: _byteswap_ulong(nChannelsCount));
      Short = CUtlBuffer::GetShort(this: buf);
      nChannelsCount = Short;
      v12 = Short;
      LOBYTE(Short) = HIBYTE(Short);
      HIBYTE(Short) = v12;
      HIWORD(pPaletteBits) = Short;
      Bitmap_t::Init(this: bitmap, nWidth, nHeight, imageFormat: IMAGE_FORMAT_RGBA8888);
      if ( v7 <= 4 || (bSecondPassCMYKA = true, mode != MODE_CMYK) )
        bSecondPassCMYKA = false;
      if ( HIWORD(pPaletteBits) != 0 )
      {
        CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: 2 * v7 * bitmap->m_nHeight);
        if ( v7 > 4 )
          v7 = 4;
        PSDReadCompressedChannels(buf, nChannelsCount: v7, mode, &palette, bitmap);
      }
      else
      {
        if ( v7 > 4 )
          v7 = 4;
        PSDReadUncompressedChannels(bitmap, buf, nChannelsCount: v7, mode, &palette);
      }
      if ( !bSecondPassCMYKA )
        goto LABEL_29;
      if ( HIWORD(pPaletteBits) != 0 )
      {
        PSDReadCompressedChannels(buf, nChannelsCount: 1, mode: MODE_COUNT, &palette, bitmap);
LABEL_29:
        result = true;
      }
      else
      {
        PSDReadUncompressedChannels(bitmap, buf, nChannelsCount: 1, mode: MODE_COUNT, &palette);
        result = true;
      }
      break;
    default:
      _Warning(a1: "Unsupported PSD color mode!\n");
      return false;
  }
  return result;
}

} // namespace vtex_dll

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1029A750
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned int>(unsigned int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned int>(CUtlBuffer *this, unsigned int *value, unsigned int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029A690
// Name: void PadLine<unsigned char>(unsigned long,unsigned char,unsigned char __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PadLine<unsigned char>(unsigned int a1, unsigned __int8 a2, unsigned __int8 *src)
{
  while ( a2 - a1 > a1 )
    a2 >>= 1;
  memcpy(dst: &src[a1], src, count: a2 - a1);
}

//------------------------------------------------------------------------------
// Address: 0x1029A6D0
// Name: void PadBlock<unsigned char>(unsigned long,unsigned char,unsigned char,unsigned char __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PadBlock<unsigned char>(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 *src)
{
  unsigned int v4; // ecx

  while ( 1 )
  {
    v4 = a3 - a1;
    if ( v4 <= a1 )
      break;
    a3 >>= 1;
  }
  memcpy(dst: &src[a1 * a2], src, count: v4 * a2);
}

} // namespace client
