// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/lzma/c/7zip/compress/lzma/lzmaencoder.cpp
// Functions: 85
// ============================================================

#include "utils\lzma\c\7zip\compress\lzma\lzmaencoder.h"

//------------------------------------------------------------------------------
// Address: 0x10017C00
// Name: private: virtual long NHC4::CMatchFinder::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::QueryInterface(
        NHC4::CMatchFinder *this,
        NHC4::CMatchFinder *__formal,
        const _GUID *__formala)
{
  return -2147467262;
}

//------------------------------------------------------------------------------
// Address: 0x10018010
// Name: public: void NCompress::NRangeCoder::CEncoder::ShiftLow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::ShiftLow(NCompress::NRangeCoder::CEncoder *this)
{
  unsigned int Low; // esi
  unsigned __int8 cache; // bl

  Low = this->Low;
  if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
  {
    cache = this->_cache;
    do
    {
      this->Stream._buffer[this->Stream._pos] = cache + HIDWORD(this->Low);
      if ( ++this->Stream._pos == this->Stream._limitPos )
        COutBuffer::FlushWithCheck(this: &this->Stream);
      cache = -1;
    }
    while ( this->_cacheSize-- != 1 );
    Low = this->Low;
    this->_cache = HIBYTE(Low);
  }
  ++this->_cacheSize;
  LODWORD(this->Low) = Low << 8;
  HIDWORD(this->Low) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018090
// Name: public: void NCompress::NRangeCoder::CEncoder::EncodeDirectBits(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::EncodeDirectBits(
        NCompress::NRangeCoder::CEncoder *this,
        unsigned int value,
        int numTotalBits)
{
  bool v3; // sf
  int v4; // ebx
  unsigned int Range; // eax
  unsigned int Low; // edi
  unsigned __int8 cache; // bl
  int i; // [esp+14h] [ebp+Ch]

  v4 = numTotalBits - 1;
  v3 = numTotalBits - 1 < 0;
  i = numTotalBits - 1;
  if ( !v3 )
  {
    do
    {
      this->Range >>= 1;
      Range = this->Range;
      if ( ((value >> v4) & 1) != 0 )
        this->Low += Range;
      if ( Range < 0x1000000 )
      {
        Low = this->Low;
        this->Range = Range << 8;
        if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
        {
          cache = this->_cache;
          do
          {
            this->Stream._buffer[this->Stream._pos++] = cache + HIDWORD(this->Low);
            if ( this->Stream._pos == this->Stream._limitPos )
              COutBuffer::FlushWithCheck(this: &this->Stream);
            cache = -1;
          }
          while ( this->_cacheSize-- != 1 );
          Low = this->Low;
          v4 = i;
          this->_cache = HIBYTE(Low);
        }
        ++this->_cacheSize;
        LODWORD(this->Low) = Low << 8;
        HIDWORD(this->Low) = 0;
      }
      i = --v4;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018150
// Name: public: unsigned __int64 NCompress::NRangeCoder::CEncoder::GetProcessedSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall NCompress::NRangeCoder::CEncoder::GetProcessedSize(NCompress::NRangeCoder::CEncoder *this)
{
  return this->_cacheSize + COutBuffer::GetProcessedSize(this: &this->Stream) + 4;
}

//------------------------------------------------------------------------------
// Address: 0x10018170
// Name: public: bool NCompress::NLZMA::CLiteralEncoder::Create(int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NCompress::NLZMA::CLiteralEncoder::Create(
        NCompress::NLZMA::CLiteralEncoder *this,
        int numPosBits,
        int numPrevBits)
{
  bool v4; // zf

  if ( this->_coders == nullptr || numPosBits + numPrevBits != this->_numPrevBits + this->_numPosBits )
  {
    MyFree(address: this->_coders);
    this->_coders = nullptr;
    this->_coders = (NCompress::NLZMA::CLiteralEncoder2 *)MyAlloc(size: 3072 * (1 << (numPosBits + numPrevBits)));
  }
  this->_numPosBits = numPosBits;
  v4 = this->_coders == nullptr;
  this->_numPrevBits = numPrevBits;
  this->_posMask = (1 << numPosBits) - 1;
  return !v4;
}

//------------------------------------------------------------------------------
// Address: 0x100181E0
// Name: public: class NCompress::NLZMA::CLiteralEncoder2 __near * NCompress::NLZMA::CLiteralEncoder::GetSubCoder(unsigned int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
NCompress::NLZMA::CLiteralEncoder2 *__thiscall NCompress::NLZMA::CLiteralEncoder::GetSubCoder(
        NCompress::NLZMA::CLiteralEncoder *this,
        unsigned int pos,
        unsigned __int8 prevByte)
{
  return &this->_coders[((pos & this->_posMask) << this->_numPrevBits) + (prevByte >> (8 - this->_numPrevBits))];
}

//------------------------------------------------------------------------------
// Address: 0x10018220
// Name: private: unsigned int NCompress::NLZMA::CEncoder::GetPosLenPrice(unsigned int,unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetPosLenPrice(
        NCompress::NLZMA::CEncoder *this,
        unsigned int pos,
        unsigned int len,
        unsigned int posState)
{
  int v4; // eax
  unsigned int v5; // esi
  int v6; // esi

  v4 = len - 2;
  if ( len - 2 >= 4 )
    v4 = 3;
  if ( pos >= 0x80 )
  {
    if ( pos >= 0x20000 )
    {
      if ( pos >= 0x8000000 )
        v6 = NCompress::NLZMA::g_FastPos[pos >> 26] + 52;
      else
        v6 = NCompress::NLZMA::g_FastPos[HIWORD(pos)] + 32;
    }
    else
    {
      v6 = NCompress::NLZMA::g_FastPos[pos >> 6] + 12;
    }
    v5 = this->_alignPrices[pos & 0xF] + this->_posSlotPrices[v4][v6];
  }
  else
  {
    v5 = this->_distancesPrices[v4][pos];
  }
  return v5 + this->_lenEncoder._highCoder.Models[272 * posState + 254 + len].Prob;
}

//------------------------------------------------------------------------------
// Address: 0x100182F0
// Name: private: virtual long NBT2::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::Create(
        NBT2::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  int v8; // eax
  unsigned int *v9; // eax
  unsigned int *v10; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_9:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = 2 * v7 + 0x10000;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  this->_hashSizeSum = 0x10000;
  if ( (unsigned int)(4 * v8) >> 2 == v8 )
  {
    v9 = (unsigned int *)BigAlloc(size: 4 * v8);
    v10 = &v9[this->_hashSizeSum];
    this->_hash = v9;
    this->_son = v10;
    if ( v9 != nullptr )
      return 0;
    goto LABEL_9;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x100183F0
// Name: private: virtual long NBT4::CMatchFinder::SetStream(struct ISequentialInStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::SetStream(NHC4::CMatchFinder *this, ISequentialInStream *stream)
{
  CLZInWindow::SetStream(this: &this->CLZInWindow, stream);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018410
// Name: private: long NBT4::CMatchFinder::MovePos(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NBT4::CMatchFinder::MovePos(NBT4::CMatchFinder *this)
{
  unsigned int v2; // eax
  HRESULT result; // eax

  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v2 = ++this->_pos;
  if ( v2 <= this->_posLimit )
    goto LABEL_7;
  if ( &this->_buffer[v2] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_7:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018470
// Name: private: virtual unsigned int NHC4::CMatchFinder::GetNumAvailableBytes(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::GetNumAvailableBytes(NHC4::CMatchFinder *this)
{
  return this->_streamPos - this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x10018480
// Name: private: virtual long NBT3::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::Create(
        NBT3::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int *v12; // eax
  unsigned int *v13; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = ((((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4)
     | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
     | ((historySize - 1) >> 1)
     | (historySize - 1);
  v9 = (v8 | ((v8 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v9 > 0x1000000 )
    v9 = 0xFFFFFF;
  this->_hashMask = v9;
  v10 = v9 + 1025;
  v11 = v10 + 2 * v7;
  this->_hashSizeSum = v10;
  if ( (4 * v11) >> 2 == v11 )
  {
    v12 = (unsigned int *)BigAlloc(size: 4 * v11);
    v13 = &v12[this->_hashSizeSum];
    this->_hash = v12;
    this->_son = v13;
    if ( v12 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x100185C0
// Name: private: virtual long NHC4::CMatchFinder::Init(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::Init(NHC4::CMatchFinder *this)
{
  unsigned int result; // eax

  result = CLZInWindow::Init(this: &this->CLZInWindow);
  if ( result == 0 )
  {
    if ( this->_hashSizeSum != 0 )
    {
      do
        this->_hash[result++] = 0;
      while ( result < this->_hashSizeSum );
    }
    this->_cyclicBufferPos = 0;
    --this->_buffer;
    ++this->_posLimit;
    ++this->_pos;
    ++this->_streamPos;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018610
// Name: private: virtual void NBT2::CMatchFinder::ReleaseStream(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT2::CMatchFinder::ReleaseStream(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10018620
// Name: private: void NBT4::CMatchFinder::Normalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT4::CMatchFinder::Normalize(NBT4::CMatchFinder *this)
{
  unsigned int cyclicBufferSize; // eax
  unsigned int v2; // esi
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int *i; // edi
  unsigned int v6; // edx
  unsigned int v7; // edx

  cyclicBufferSize = this->_cyclicBufferSize;
  v2 = this->_pos - cyclicBufferSize;
  v3 = this->_hashSizeSum + 2 * cyclicBufferSize;
  v4 = 0;
  for ( i = this->_hash; v4 < v3; ++v4 )
  {
    v6 = i[v4];
    if ( v6 > v2 )
      v7 = v6 - v2;
    else
      v7 = 0;
    i[v4] = v7;
  }
  this->_buffer += v2;
  this->_posLimit -= v2;
  this->_pos -= v2;
  this->_streamPos -= v2;
}

//------------------------------------------------------------------------------
// Address: 0x10018670
// Name: private: virtual unsigned char const __near * NBT4::CMatchFinder::GetPointerToCurrentPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__stdcall NBT4::CMatchFinder::GetPointerToCurrentPos(NHC4::CMatchFinder *this)
{
  return &this->_buffer[this->_pos];
}

//------------------------------------------------------------------------------
// Address: 0x10018680
// Name: private: virtual void NBT2::CMatchFinder::ChangeBufferPos(void)
// Source: json
//------------------------------------------------------------------------------
void __stdcall NBT2::CMatchFinder::ChangeBufferPos(NHC4::CMatchFinder *this)
{
  CLZInWindow::MoveBlock(this: &this->CLZInWindow);
}

//------------------------------------------------------------------------------
// Address: 0x100186A0
// Name: private: virtual unsigned long NHC4::CMatchFinder::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::AddRef(NHC4::CMatchFinder *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100186C0
// Name: private: virtual unsigned long NHC4::CMatchFinder::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::Release(NHC4::CMatchFinder *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    ((void (__thiscall *)(CLZInWindow *, int))this->dtr_CLZInWindow)(a1: &this->CLZInWindow, a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100186E0
// Name: private: virtual long NBT4::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::Create(
        NBT4::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int *v13; // eax
  unsigned int *v14; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = (((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4;
  v9 = v8 | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1);
  v10 = (v9 | ((v9 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v10 > 0x1000000 )
    v10 = (v9
         | ((v8
           | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
           | ((historySize - 1) >> 1)
           | (historySize - 1)
           | 0x1FFFE00) >> 8)) >> 2;
  this->_hashMask = v10;
  v11 = v10 + 66561;
  v12 = v11 + 2 * v7;
  this->_hashSizeSum = v11;
  if ( (4 * v12) >> 2 == v12 )
  {
    v13 = (unsigned int *)BigAlloc(size: 4 * v12);
    v14 = &v13[this->_hashSizeSum];
    this->_hash = v13;
    this->_son = v14;
    if ( v13 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x10018820
// Name: private: virtual unsigned char NBT2::CMatchFinder::GetIndexByte(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __stdcall NBT2::CMatchFinder::GetIndexByte(NHC4::CMatchFinder *this, int index)
{
  return this->_buffer[this->_pos + index];
}

//------------------------------------------------------------------------------
// Address: 0x10018840
// Name: public: virtual void NBT3::CMatchFinder::SetNumPasses(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT3::CMatchFinder::SetNumPasses(NHC4::CMatchFinder *this, unsigned int numPasses)
{
  this->_blockSize = numPasses;
}

//------------------------------------------------------------------------------
// Address: 0x10018850
// Name: private: virtual long NHC4::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::Create(
        NHC4::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int *v14; // eax
  unsigned int *v15; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 2) + 8;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = (((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4;
  v9 = v8 | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1);
  v10 = (v9 | ((v9 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v10 > 0x1000000 )
    v10 = (v9
         | ((v8
           | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
           | ((historySize - 1) >> 1)
           | (historySize - 1)
           | 0x1FFFE00) >> 8)) >> 2;
  this->_hashMask = v10;
  v11 = v10 + 66561;
  v12 = v11 + v7;
  this->_hashSizeSum = v11;
  v13 = 4 * (v11 + v7);
  if ( v13 >> 2 == v12 )
  {
    v14 = (unsigned int *)BigAlloc(size: v13);
    v15 = &v14[this->_hashSizeSum];
    this->_hash = v14;
    this->_son = v15;
    if ( v14 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x10018990
// Name: private: void NHC4::CMatchFinder::Normalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NHC4::CMatchFinder::Normalize(NHC4::CMatchFinder *this)
{
  unsigned int cyclicBufferSize; // eax
  unsigned int *hash; // ebx
  unsigned int hashSizeSum; // edi
  unsigned int v4; // esi
  bool v5; // zf
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // edx

  cyclicBufferSize = this->_cyclicBufferSize;
  hash = this->_hash;
  hashSizeSum = this->_hashSizeSum;
  v4 = this->_pos - cyclicBufferSize;
  v5 = cyclicBufferSize + hashSizeSum == 0;
  v6 = cyclicBufferSize + hashSizeSum;
  v7 = 0;
  if ( !v5 )
  {
    do
    {
      v8 = hash[v7];
      if ( v8 > v4 )
        v9 = v8 - v4;
      else
        v9 = 0;
      hash[v7++] = v9;
    }
    while ( v7 < v6 );
  }
  this->_buffer += v4;
  this->_posLimit -= v4;
  this->_pos -= v4;
  this->_streamPos -= v4;
}

//------------------------------------------------------------------------------
// Address: 0x100189E0
// Name: private: long NHC4::CMatchFinder::MovePos(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NHC4::CMatchFinder::MovePos(NHC4::CMatchFinder *this)
{
  unsigned int v2; // eax
  HRESULT result; // eax

  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v2 = ++this->_pos;
  if ( v2 <= this->_posLimit )
    goto LABEL_7;
  if ( &this->_buffer[v2] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_7:
    if ( this->_pos == 0x7FFFFFFF )
      NHC4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018A40
// Name: private: virtual unsigned int NBT4::CMatchFinder::GetMatchLen(int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NBT4::CMatchFinder::GetMatchLen(
        NHC4::CMatchFinder *this,
        int index,
        unsigned int back,
        unsigned int limit)
{
  unsigned int v4; // esi
  unsigned int pos; // edi
  unsigned int streamPos; // ecx
  unsigned __int8 *v7; // ecx
  unsigned int result; // eax

  v4 = limit;
  if ( this->_streamEndWasReached )
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( limit + pos + index > streamPos )
      v4 = streamPos - pos - index;
  }
  for ( result = 0; result < v4; ++result )
  {
    v7 = &this->_buffer[this->_pos + index];
    if ( v7[result] != v7[result - 1 - back] )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018AA0
// Name: private: virtual int NHC4::CMatchFinder::NeedChangeBufferPos(unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall NHC4::CMatchFinder::NeedChangeBufferPos(NHC4::CMatchFinder *this, unsigned int numCheckBytes)
{
  return numCheckBytes >= &this->_pointerToLastSafePosition[-this->_pos] - this->_buffer;
}

//------------------------------------------------------------------------------
// Address: 0x10018AC0
// Name: public: void NCompress::NLZMA::CFastPosInit::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CFastPosInit::Init(NCompress::NLZMA::CFastPosInit *this)
{
  char v1; // bl
  unsigned int v2; // edi
  unsigned int v3; // esi
  unsigned __int8 slotFast; // [esp+Ch] [ebp-8h]
  int c; // [esp+10h] [ebp-4h]

  v1 = 2;
  c = 2;
  *(_WORD *)NCompress::NLZMA::g_FastPos = 256;
  slotFast = 2;
  v2 = 2;
  do
  {
    v3 = 1 << ((v2 >> 1) - 1);
    if ( v3 != 0 )
    {
      memset(dst: &NCompress::NLZMA::g_FastPos[c], value: slotFast, count: v3);
      c += v3;
    }
    ++v1;
    ++v2;
    slotFast = v1;
  }
  while ( (unsigned __int8)v1 < 0x16u );
}

//------------------------------------------------------------------------------
// Address: 0x10018B20
// Name: NCompress::NLZMA::FindMatchFinder
// Source: json
//------------------------------------------------------------------------------
int __usercall NCompress::NLZMA::FindMatchFinder@<eax>(const wchar_t *s@<edi>)
{
  int result; // eax
  const wchar_t *i; // edx
  wchar_t v3; // cx

  for ( result = 0; result < 4; ++result )
  {
    for ( i = s; ; ++i )
    {
      v3 = *i;
      if ( (unsigned __int16)(*i - 97) <= 0x19u )
        v3 -= 32;
      if ( *(const wchar_t *)((char *)i + (char *)kMatchFinderIDs[result] - (char *)s) != v3 )
        break;
      if ( v3 == 0 )
        return result;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10018B60
// Name: public: virtual long NCompress::NLZMA::CEncoder::WriteCoderProperties(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::WriteCoderProperties(
        NCompress::NLZMA::CEncoder *this,
        ISequentialOutStream *outStream)
{
  unsigned int posStateMask; // edx
  unsigned __int8 properties[8]; // [esp+0h] [ebp-8h] BYREF

  properties[0] = LOBYTE(this->_posStateBits) + 9 * (LOBYTE(this->_distTableSize) + 5 * LOBYTE(this->_alignPrices[15]));
  posStateMask = this->_posStateMask;
  *(_DWORD *)&properties[1] = posStateMask;
  return WriteStream(stream: outStream, data: properties, size: 5u, processedSize: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10018BD0
// Name: public: virtual long NCompress::NLZMA::CEncoder::SetOutStream(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::SetOutStream(
        NCompress::NLZMA::CEncoder *this,
        ISequentialOutStream *outStream)
{
  COutBuffer::SetStream(this: (COutBuffer *)(&this->_rangeEncoder.Range + 1), stream: outStream);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018BF0
// Name: private: unsigned int NCompress::NLZMA::CEncoder::Backward(unsigned int __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::Backward(
        NCompress::NLZMA::CEncoder *this,
        unsigned int *backRes,
        unsigned int cur)
{
  unsigned int v3; // esi
  char *v4; // eax
  unsigned int PosPrev; // edx
  char *v6; // edi
  char *v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned int result; // eax
  unsigned int backMem; // [esp+18h] [ebp+Ch]

  v3 = cur;
  v4 = (char *)this + 40 * cur;
  this->_optimumEndIndex = cur;
  PosPrev = *((_DWORD *)v4 + 14);
  backMem = *((_DWORD *)v4 + 15);
  do
  {
    v6 = (char *)this + 40 * v3;
    if ( v6[41] != 0 )
    {
      v7 = (char *)this + 40 * PosPrev;
      *((_DWORD *)v7 + 15) = -1;
      v7[41] = 0;
      *((_DWORD *)v7 + 14) = PosPrev - 1;
      if ( v6[42] != 0 )
      {
        v7[1] = 0;
        *((_DWORD *)v7 + 4) = *((_DWORD *)v6 + 11);
        *((_DWORD *)v7 + 5) = *((_DWORD *)v6 + 12);
      }
    }
    v8 = backMem;
    v9 = PosPrev;
    v10 = PosPrev;
    backMem = this->_optimum[PosPrev].BackPrev;
    PosPrev = this->_optimum[PosPrev].PosPrev;
    this->_optimum[v9].PosPrev = v3;
    this->_optimum[v9].BackPrev = v8;
    v3 = v10;
  }
  while ( v10 != 0 );
  *backRes = this->_optimum[0].BackPrev;
  result = this->_optimum[0].PosPrev;
  this->_optimumCurrentIndex = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018C90
// Name: public: void NCompress::NRangeCoder::CBitEncoder<5>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitEncoder<5>::Encode(
        NCompress::NRangeCoder::CBitEncoder<5> *this,
        NCompress::NRangeCoder::CEncoder *encoder,
        unsigned int symbol)
{
  unsigned int Range; // esi
  unsigned int v4; // edx
  unsigned int v5; // ecx

  Range = encoder->Range;
  v4 = this->Prob * (Range >> 11);
  if ( symbol != 0 )
  {
    encoder->Low += v4;
    encoder->Range = Range - v4;
    this->Prob -= this->Prob >> 5;
  }
  else
  {
    encoder->Range = v4;
    this->Prob += (2048 - this->Prob) >> 5;
  }
  v5 = encoder->Range;
  if ( v5 < 0x1000000 )
  {
    encoder->Range = v5 << 8;
    NCompress::NRangeCoder::CEncoder::ShiftLow(this: encoder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018D00
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,3> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,3> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 3;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10018DA0
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,8> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,8> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 8;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10018E40
// Name: public: struct IMatchFinder __near * CMyComPtr<struct IMatchFinder>::operator=(struct IMatchFinder __near *)
// Source: json
//------------------------------------------------------------------------------
IMatchFinder *__thiscall CMyComPtr<IMatchFinder>::operator=(CMyComPtr<IMatchFinder> *this, IMatchFinder *p)
{
  if ( p != nullptr )
    p->AddRef(this: p);
  if ( this->_p != nullptr )
    this->_p->Release(this: this->_p);
  this->_p = p;
  return p;
}

//------------------------------------------------------------------------------
// Address: 0x10018E70
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,6> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,6> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 6;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10018F10
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,4> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,4> *v4; // edx
  int v5; // edi
  unsigned int Range; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  int rangeEncodera; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  for ( rangeEncodera = 4; rangeEncodera != 0; --rangeEncodera )
  {
    Range = rangeEncoder->Range;
    v7 = v4->Models[v5].Prob * (Range >> 11);
    v8 = symbol & 1;
    if ( (symbol & 1) != 0 )
    {
      rangeEncoder->Low += v7;
      rangeEncoder->Range = Range - v7;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v7;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v9 = rangeEncoder->Range;
    if ( v9 < 0x1000000 )
    {
      rangeEncoder->Range = v9 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    symbol >>= 1;
    v5 = v8 | (2 * v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018FB0
// Name: void NCompress::NRangeCoder::ReverseBitTreeEncode<5>(class NCompress::NRangeCoder::CBitEncoder<5> __near *,class NCompress::NRangeCoder::CEncoder __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NCompress::NRangeCoder::ReverseBitTreeEncode<5>(
        NCompress::NRangeCoder::CBitEncoder<5> *Models,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        int NumBitLevels,
        unsigned int symbol)
{
  int v4; // edi
  unsigned int Range; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax

  v4 = 1;
  if ( NumBitLevels > 0 )
  {
    do
    {
      Range = rangeEncoder->Range;
      v6 = Models[v4].Prob * (Range >> 11);
      v7 = symbol & 1;
      if ( (symbol & 1) != 0 )
      {
        rangeEncoder->Low += v6;
        rangeEncoder->Range = Range - v6;
        Models[v4].Prob -= Models[v4].Prob >> 5;
      }
      else
      {
        rangeEncoder->Range = v6;
        Models[v4].Prob += (2048 - Models[v4].Prob) >> 5;
      }
      v8 = rangeEncoder->Range;
      if ( v8 < 0x1000000 )
      {
        rangeEncoder->Range = v8 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      symbol >>= 1;
      v4 = v7 | (2 * v4);
      --NumBitLevels;
    }
    while ( NumBitLevels != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019040
// Name: unsigned int NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(class NCompress::NRangeCoder::CBitEncoder<5> __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(
        NCompress::NRangeCoder::CBitEncoder<5> *Models,
        int NumBitLevels,
        unsigned int symbol)
{
  __int64 i; // rax
  unsigned int v5; // ecx

  for ( i = 0x100000000LL; NumBitLevels != 0; --NumBitLevels )
  {
    v5 = symbol & 1;
    LODWORD(i) = NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v5 ^ (Models[HIDWORD(i)].Prob - v5)) >> 2) & 0x1FF]
               + i;
    symbol >>= 1;
    HIDWORD(i) = v5 | (2 * HIDWORD(i));
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x100190D0
// Name: public: void NCompress::NRangeCoder::CEncoder::FlushData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::FlushData(NCompress::NRangeCoder::CEncoder *this)
{
  unsigned int Low; // edi
  unsigned __int8 cache; // bl
  bool v4; // zf
  int v5; // [esp+Ch] [ebp-4h]

  v5 = 5;
  do
  {
    Low = this->Low;
    if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
    {
      cache = this->_cache;
      do
      {
        this->Stream._buffer[this->Stream._pos++] = cache + HIDWORD(this->Low);
        if ( this->Stream._pos == this->Stream._limitPos )
          COutBuffer::FlushWithCheck(this: &this->Stream);
        cache = -1;
        v4 = this->_cacheSize-- == 1;
      }
      while ( !v4 );
      Low = this->Low;
      this->_cache = HIBYTE(Low);
    }
    ++this->_cacheSize;
    v4 = v5-- == 1;
    LODWORD(this->Low) = Low << 8;
    HIDWORD(this->Low) = 0;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x10019160
// Name: private: void NCompress::NLZMA::CEncoder::ReleaseMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::ReleaseMatchFinder(NCompress::NLZMA::CEncoder *this)
{
  IMatchFinder *p; // eax

  this->setMfPasses = nullptr;
  p = this->_matchFinder._p;
  if ( p != nullptr )
  {
    p->Release(this: p);
    this->_matchFinder._p = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019190
// Name: private: unsigned int NCompress::NLZMA::CEncoder::GetPureRepPrice(unsigned int,class NCompress::NLZMA::CState,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetPureRepPrice(
        NCompress::NLZMA::CEncoder *this,
        unsigned int repIndex,
        NCompress::NLZMA::CState state,
        unsigned int posState)
{
  unsigned int v5; // eax

  if ( repIndex == 0 )
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[state.Index].Prob >> 2]
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[state.Index][posState].Prob) >> 2];
  v5 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRepG0[state.Index].Prob) >> 2];
  if ( repIndex == 1 )
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG1[state.Index].Prob >> 2] + v5;
  else
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[(((2 - repIndex)
                                                            ^ (this->_isRepG2[state.Index].Prob - (repIndex - 2))) >> 2)
                                                          & 0x1FF]
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRepG1[state.Index].Prob) >> 2]
         + v5;
}

//------------------------------------------------------------------------------
// Address: 0x10019250
// Name: public: NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(
        NCompress::NLZMA::CEncoder::CCoderReleaser *this)
{
  NCompress::NLZMA::CEncoder *coder; // esi
  IMatchFinder *p; // eax

  coder = this->_coder;
  p = this->_coder->_matchFinder._p;
  if ( p != nullptr && coder->_needReleaseMFStream )
  {
    p->ReleaseStream(this: p);
    coder->_needReleaseMFStream = false;
  }
  coder->ReleaseOutStream(this: &coder->ICompressSetOutStream);
}

//------------------------------------------------------------------------------
// Address: 0x100192F0
// Name: private: virtual long NBT2::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::GetMatches(NBT2::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // edx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  unsigned int v6; // ebx
  HRESULT result; // eax
  unsigned __int8 *buffer; // edi
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned int *v11; // eax
  unsigned int v12; // ecx
  unsigned int cutValue; // eax
  unsigned int v14; // eax
  unsigned int cyclicBufferPos; // ebx
  unsigned int v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned __int8 *v19; // edx
  int v20; // edx
  unsigned __int8 *v21; // ebx
  unsigned int *v22; // ecx
  const unsigned __int8 *cur; // [esp+8h] [ebp-38h]
  unsigned int delta; // [esp+Ch] [ebp-34h]
  int i; // [esp+10h] [ebp-30h]
  unsigned int *son; // [esp+14h] [ebp-2Ch]
  unsigned int count; // [esp+18h] [ebp-28h]
  unsigned int matchMinPos; // [esp+1Ch] [ebp-24h]
  unsigned int len1; // [esp+20h] [ebp-20h]
  unsigned int *pair; // [esp+24h] [ebp-1Ch]
  unsigned int len0; // [esp+28h] [ebp-18h]
  const unsigned __int8 *pb; // [esp+2Ch] [ebp-14h]
  unsigned int maxLen; // [esp+30h] [ebp-10h]
  int offset; // [esp+34h] [ebp-Ch]
  unsigned int *ptr0; // [esp+38h] [ebp-8h]
  unsigned int *ptr1; // [esp+3Ch] [ebp-4h]
  unsigned int lenLimit; // [esp+48h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 3 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos((NBT4::CMatchFinder *)this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    v6 = 0;
  else
    v6 = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v9 = buffer[pos + 1];
  v10 = &buffer[pos];
  maxLen = 1;
  v11 = &this->_hash[*v10 ^ (v9 << 8)];
  v12 = *v11;
  *v11 = pos;
  son = this->_son;
  ptr1 = &son[2 * this->_cyclicBufferPos];
  matchMinPos = v6;
  cur = v10;
  ptr0 = ptr1 + 1;
  len1 = 2;
  len0 = 2;
  if ( v12 > v6 && this->_buffer[v12 + 2] != v10[2] )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - v12 - 1;
    offset = 3;
  }
  cutValue = this->_cutValue;
  if ( v12 > v6 )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v16 = this->_pos - v12;
      delta = v16;
      if ( v16 > cyclicBufferPos )
        v17 = cyclicBufferPos + this->_cyclicBufferSize - v16;
      else
        v17 = cyclicBufferPos - v16;
      v18 = len1;
      pair = &son[2 * v17];
      v19 = &this->_buffer[v12];
      pb = v19;
      if ( len0 < len1 )
        v18 = len0;
      if ( v19[v18] == v10[v18] )
      {
        if ( ++v18 != lenLimit )
        {
          v20 = v19 - v10;
          v21 = &v10[v18];
          for ( i = v20; v21[v20] == *v21; v20 = i )
          {
            ++v18;
            ++v21;
            if ( v18 == lenLimit )
              break;
          }
          v19 = &this->_buffer[v12];
        }
        if ( maxLen < v18 )
        {
          distances[offset] = v18;
          distances[offset + 1] = delta - 1;
          maxLen = v18;
          offset += 2;
          if ( v18 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0 = pair[1];
            goto LABEL_13;
          }
          v10 = (unsigned __int8 *)cur;
          v19 = (unsigned __int8 *)pb;
        }
      }
      if ( v19[v18] >= v10[v18] )
      {
        *ptr0 = v12;
        v22 = pair;
        ptr0 = pair;
        len0 = v18;
      }
      else
      {
        *ptr1 = v12;
        v22 = pair + 1;
        ptr1 = pair + 1;
        len1 = v18;
      }
      v12 = *v22;
      if ( v12 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  *ptr1 = 0;
  *ptr0 = 0;
LABEL_13:
  *distances = offset - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v14 = ++this->_pos;
  if ( v14 <= this->_posLimit )
    goto LABEL_19;
  if ( &this->_buffer[v14] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_19:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize((NBT4::CMatchFinder *)this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019530
// Name: private: virtual long NBT2::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::Skip(NBT2::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // edi
  int v16; // eax
  int v17; // ecx
  unsigned __int8 *v18; // edi
  unsigned int *v19; // eax
  unsigned int v20; // ecx
  unsigned int *v21; // ebx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v24; // edx
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned __int8 *v27; // edx
  unsigned __int8 *v28; // edx
  unsigned __int8 *v29; // ebx
  unsigned int *v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // eax
  unsigned int *hash; // ebx
  unsigned int v34; // edx
  unsigned int v35; // eax
  unsigned int v36; // edx
  unsigned int v37; // edx
  unsigned int count; // [esp+Ch] [ebp-28h]
  unsigned int *son; // [esp+10h] [ebp-24h]
  unsigned __int8 *v40; // [esp+18h] [ebp-1Ch]
  unsigned int len0; // [esp+1Ch] [ebp-18h]
  unsigned int len1; // [esp+20h] [ebp-14h]
  unsigned int *pair; // [esp+24h] [ebp-10h]
  unsigned int matchMinPos; // [esp+28h] [ebp-Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-8h]
  unsigned int *ptr1; // [esp+30h] [ebp-4h]
  unsigned int lenLimit; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimita; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimitb; // [esp+3Ch] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = buffer[pos + 1];
      v17 = buffer[pos];
      v18 = &buffer[pos];
      v19 = &this->_hash[v17 ^ (v16 << 8)];
      v20 = *v19;
      *v19 = pos;
      v21 = this->_son;
      ptr1 = &v21[2 * this->_cyclicBufferPos];
      len1 = 2;
      len0 = 2;
      cutValue = this->_cutValue;
      son = v21;
      ptr0 = ptr1 + 1;
      if ( v20 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v24 = this->_pos - v20;
          if ( v24 > cyclicBufferPos )
            v25 = this->_cyclicBufferSize + cyclicBufferPos - v24;
          else
            v25 = cyclicBufferPos - v24;
          pair = &v21[2 * v25];
          v26 = len0;
          v27 = &this->_buffer[v20];
          if ( len0 >= len1 )
            v26 = len1;
          if ( v27[v26] == v18[v26] )
          {
            if ( ++v26 == lenLimit )
              goto LABEL_40;
            v28 = (unsigned __int8 *)(v27 - v18);
            v29 = &v18[v26];
            v40 = v28;
            while ( v29[(_DWORD)v28] == *v29 )
            {
              ++v26;
              ++v29;
              if ( v26 == lenLimit )
                goto LABEL_40;
              v28 = v40;
            }
            if ( v26 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v27 = &this->_buffer[v20];
          }
          if ( v27[v26] >= v18[v26] )
          {
            *ptr0 = v20;
            v30 = pair;
            ptr0 = pair;
            len0 = v26;
          }
          else
          {
            *ptr1 = v20;
            v30 = pair + 1;
            ptr1 = pair + 1;
            len1 = v26;
          }
          v20 = *v30;
          if ( v20 <= matchMinPos )
            break;
          v21 = son;
          cutValue = count;
        }
      }
      *ptr1 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v31 = ++this->_pos;
      if ( v31 > this->_posLimit )
      {
        if ( &this->_buffer[v31] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v32 = this->_cyclicBufferSize;
        hash = this->_hash;
        v34 = this->_hashSizeSum + 2 * v32;
        v11 = 0x7FFFFFFF - v32;
        v35 = 0;
        for ( lenLimitb = v34; v35 < lenLimitb; ++v35 )
        {
          v36 = hash[v35];
          if ( v36 > v11 )
            v37 = v36 - v11;
          else
            v37 = 0;
          hash[v35] = v37;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 3 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019820
// Name: private: virtual long NBT3::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::GetMatches(NBT3::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int *hash; // ecx
  unsigned int v13; // eax
  int v14; // edx
  unsigned int v15; // edi
  unsigned int cyclicBufferPos; // ecx
  unsigned int v17; // ebx
  int v18; // edx
  unsigned int *v19; // ecx
  unsigned int cutValue; // eax
  unsigned int *v21; // edx
  int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // edx
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int *v27; // edx
  unsigned int v28; // eax
  unsigned __int8 *v29; // ecx
  const unsigned __int8 *v30; // edx
  int i; // ebx
  const unsigned __int8 *pb; // [esp+8h] [ebp-3Ch]
  unsigned int delta; // [esp+Ch] [ebp-38h]
  unsigned int *son; // [esp+18h] [ebp-2Ch]
  unsigned int count; // [esp+1Ch] [ebp-28h]
  unsigned int len0; // [esp+20h] [ebp-24h]
  unsigned int len0a; // [esp+20h] [ebp-24h]
  unsigned int len1; // [esp+24h] [ebp-20h]
  unsigned int *pair; // [esp+28h] [ebp-1Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-18h]
  unsigned int *ptr1; // [esp+30h] [ebp-14h]
  unsigned int matchMinPos; // [esp+34h] [ebp-10h]
  const unsigned __int8 *cur; // [esp+38h] [ebp-Ch]
  unsigned int lenLimit; // [esp+3Ch] [ebp-8h]
  unsigned int maxLen; // [esp+40h] [ebp-4h]
  int offset; // [esp+4Ch] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 3 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos((NBT4::CMatchFinder *)this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  cur = v9;
  LOWORD(v8) = LOWORD(CCRC::Table[v8]) ^ v9[1];
  v11 = v10 ^ (v9[2] << 8);
  hash = this->_hash;
  v13 = this->_hashMask & v11;
  v14 = v8 & 0x3FF;
  len0 = hash[v14];
  maxLen = 1;
  v15 = hash[v13 + 1024];
  hash[v14] = this->_pos;
  if ( len0 > matchMinPos && this->_buffer[len0] == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - len0 - 1;
    offset = 3;
    if ( len0 == v15 )
    {
      offset = 1;
      maxLen = 1;
    }
  }
  this->_hash[v13 + 1024] = this->_pos;
  cyclicBufferPos = this->_cyclicBufferPos;
  son = this->_son;
  v17 = 0;
  v18 = (int)&son[2 * cyclicBufferPos + 1];
  v19 = &son[2 * cyclicBufferPos];
  cutValue = this->_cutValue;
  ptr0 = (unsigned int *)v18;
  ptr1 = v19;
  len1 = 0;
  len0a = 0;
  if ( v15 > matchMinPos )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      v24 = this->_cyclicBufferPos;
      v25 = this->_pos - v15;
      delta = v25;
      if ( v25 > v24 )
        v26 = v24 + this->_cyclicBufferSize - v25;
      else
        v26 = v24 - v25;
      v27 = &son[2 * v26];
      v28 = len1;
      v29 = &this->_buffer[v15];
      pair = v27;
      pb = v29;
      if ( v17 < len1 )
        v28 = v17;
      if ( v29[v28] == cur[v28] )
      {
        if ( ++v28 != lenLimit )
        {
          v30 = &cur[v28];
          for ( i = v29 - cur; v30[i] == *v30; i = v29 - cur )
          {
            ++v28;
            ++v30;
            if ( v28 == lenLimit )
              break;
          }
        }
        if ( maxLen < v28 )
        {
          v21 = distances;
          distances[offset] = v28;
          distances[offset + 1] = delta - 1;
          v22 = offset + 2;
          maxLen = v28;
          offset += 2;
          if ( v28 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0 = pair[1];
            goto LABEL_14;
          }
          v29 = (unsigned __int8 *)pb;
        }
      }
      if ( v29[v28] >= cur[v28] )
      {
        *ptr0 = v15;
        v15 = *pair;
        v17 = v28;
        ptr0 = pair;
        v19 = ptr1;
        len0a = v28;
      }
      else
      {
        v17 = len0a;
        *ptr1 = v15;
        v15 = pair[1];
        v19 = pair + 1;
        ptr1 = pair + 1;
        len1 = v28;
      }
      if ( v15 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  v21 = distances;
  *v19 = 0;
  *ptr0 = 0;
  v22 = offset;
LABEL_14:
  *v21 = v22 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v23 = ++this->_pos;
  if ( v23 <= this->_posLimit )
    goto LABEL_20;
  if ( &this->_buffer[v23] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_20:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize((NBT4::CMatchFinder *)this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019AB0
// Name: private: virtual long NBT3::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::Skip(NBT3::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // edx
  unsigned int v16; // eax
  int v17; // ecx
  unsigned __int8 *v18; // edx
  unsigned int v19; // ecx
  unsigned int *hash; // eax
  unsigned int v21; // edi
  unsigned int *v22; // ebx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // ecx
  unsigned __int8 *v29; // ecx
  unsigned __int8 *v30; // ebx
  unsigned int *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int *v34; // ebx
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // edx
  unsigned int *son; // [esp+Ch] [ebp-28h]
  unsigned int count; // [esp+10h] [ebp-24h]
  unsigned __int8 *v41; // [esp+18h] [ebp-1Ch]
  unsigned int len0; // [esp+1Ch] [ebp-18h]
  unsigned int len1; // [esp+20h] [ebp-14h]
  unsigned int *pair; // [esp+24h] [ebp-10h]
  unsigned int matchMinPos; // [esp+28h] [ebp-Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-8h]
  unsigned int *ptr1; // [esp+30h] [ebp-4h]
  unsigned int lenLimit; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimita; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimitb; // [esp+3Ch] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v17 = buffer[pos + 2];
      v18 = &buffer[pos];
      v19 = this->_hashMask & (v16 ^ (v17 << 8));
      this->_hash[v16 & 0x3FF] = pos;
      hash = this->_hash;
      v21 = hash[v19 + 1024];
      hash[v19 + 1024] = this->_pos;
      v22 = this->_son;
      ptr1 = &v22[2 * this->_cyclicBufferPos];
      len1 = 0;
      len0 = 0;
      cutValue = this->_cutValue;
      son = v22;
      ptr0 = ptr1 + 1;
      if ( v21 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v25 = this->_pos - v21;
          if ( v25 > cyclicBufferPos )
            v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
          else
            v26 = cyclicBufferPos - v25;
          pair = &v22[2 * v26];
          v27 = len0;
          v28 = &this->_buffer[v21];
          if ( len0 >= len1 )
            v27 = len1;
          if ( v28[v27] == v18[v27] )
          {
            if ( ++v27 == lenLimit )
              goto LABEL_40;
            v29 = (unsigned __int8 *)(v28 - v18);
            v30 = &v18[v27];
            v41 = v29;
            while ( v30[(_DWORD)v29] == *v30 )
            {
              ++v27;
              ++v30;
              if ( v27 == lenLimit )
                goto LABEL_40;
              v29 = v41;
            }
            if ( v27 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v28 = &this->_buffer[v21];
          }
          if ( v28[v27] >= v18[v27] )
          {
            *ptr0 = v21;
            v31 = pair;
            ptr0 = pair;
            len0 = v27;
          }
          else
          {
            *ptr1 = v21;
            v31 = pair + 1;
            ptr1 = pair + 1;
            len1 = v27;
          }
          v21 = *v31;
          if ( *v31 <= matchMinPos )
            break;
          cutValue = count;
          v22 = son;
        }
      }
      *ptr1 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v32 = ++this->_pos;
      if ( v32 > this->_posLimit )
      {
        if ( &this->_buffer[v32] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v33 = this->_cyclicBufferSize;
        v34 = this->_hash;
        v35 = this->_hashSizeSum + 2 * v33;
        v11 = 0x7FFFFFFF - v33;
        v36 = 0;
        for ( lenLimitb = v35; v36 < lenLimitb; ++v36 )
        {
          v37 = v34[v36];
          if ( v37 > v11 )
            v38 = v37 - v11;
          else
            v38 = 0;
          v34[v36] = v38;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 3 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019DC0
// Name: private: virtual long NBT4::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::GetMatches(NBT4::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned __int16 v13; // dx
  __int16 v14; // di
  unsigned int *hash; // ecx
  int v16; // edi
  int v17; // ebx
  unsigned int *v18; // edi
  unsigned int v19; // ecx
  unsigned int *v20; // edi
  unsigned int cutValue; // eax
  unsigned int *v22; // ecx
  unsigned int v23; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // edi
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // edi
  const unsigned __int8 *v29; // ecx
  unsigned int delta; // [esp+8h] [ebp-34h]
  unsigned int *son; // [esp+Ch] [ebp-30h]
  unsigned int count; // [esp+10h] [ebp-2Ch]
  unsigned int curMatch3; // [esp+14h] [ebp-28h]
  unsigned int curMatch3a; // [esp+14h] [ebp-28h]
  unsigned int len1; // [esp+18h] [ebp-24h]
  unsigned int *pair; // [esp+1Ch] [ebp-20h]
  unsigned int *ptr0; // [esp+20h] [ebp-1Ch]
  unsigned int *ptr0a; // [esp+20h] [ebp-1Ch]
  unsigned int *ptr1; // [esp+24h] [ebp-18h]
  const unsigned __int8 *cur; // [esp+28h] [ebp-14h]
  unsigned int lenLimit; // [esp+2Ch] [ebp-10h]
  unsigned int matchMinPos; // [esp+30h] [ebp-Ch]
  unsigned int maxLen; // [esp+34h] [ebp-8h]
  unsigned int curMatch; // [esp+38h] [ebp-4h]
  int offset; // [esp+44h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 4 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos(this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  v11 = v9[2];
  cur = v9;
  v12 = this->_hashMask & (v10 ^ (32 * (CCRC::Table[v9[3]] ^ (8 * v11))));
  maxLen = 1;
  v13 = v10 ^ ((_WORD)v11 << 8);
  v14 = v10;
  hash = this->_hash;
  v16 = v14 & 0x3FF;
  curMatch = hash[v12 + 66560];
  ptr0 = (unsigned int *)hash[v16];
  curMatch3 = hash[v13 + 1024];
  hash[v16] = this->_pos;
  if ( (unsigned int)ptr0 > matchMinPos && *((_BYTE *)ptr0 + (unsigned int)this->_buffer) == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - (_DWORD)ptr0 - 1;
    v17 = 3;
    offset = 3;
  }
  else
  {
    v17 = 1;
  }
  this->_hash[v13 + 1024] = this->_pos;
  v18 = (unsigned int *)curMatch3;
  if ( curMatch3 > matchMinPos && this->_buffer[curMatch3] == *cur )
  {
    if ( (unsigned int *)curMatch3 == ptr0 )
      v17 -= 2;
    distances[v17] = 3;
    distances[v17 + 1] = this->_pos - curMatch3 - 1;
    v17 += 2;
    maxLen = 3;
    offset = v17;
  }
  else
  {
    v18 = ptr0;
  }
  v19 = curMatch;
  if ( v17 != 1 && v18 == (unsigned int *)curMatch )
  {
    v17 -= 2;
    offset = v17;
    maxLen = 1;
  }
  this->_hash[v12 + 66560] = this->_pos;
  son = this->_son;
  v20 = &son[2 * this->_cyclicBufferPos];
  len1 = 0;
  curMatch3a = 0;
  cutValue = this->_cutValue;
  ptr0a = v20 + 1;
  ptr1 = v20;
  if ( curMatch > matchMinPos )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v25 = this->_pos - v19;
      delta = v25;
      if ( v25 > cyclicBufferPos )
        v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
      else
        v26 = cyclicBufferPos - v25;
      pair = &son[2 * v26];
      v27 = curMatch3a;
      v28 = &this->_buffer[v19];
      if ( curMatch3a >= len1 )
        v27 = len1;
      if ( v28[v27] == cur[v27] )
      {
        if ( ++v27 != lenLimit )
        {
          v29 = &cur[v27];
          do
          {
            if ( v29[v28 - cur] != *v29 )
              break;
            ++v27;
            ++v29;
          }
          while ( v27 != lenLimit );
          v19 = curMatch;
        }
        v17 = offset;
        if ( maxLen < v27 )
        {
          v22 = distances;
          distances[offset] = v27;
          distances[offset + 1] = delta - 1;
          v17 = offset + 2;
          maxLen = v27;
          offset += 2;
          if ( v27 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0a = pair[1];
            goto LABEL_23;
          }
          v19 = curMatch;
        }
      }
      else
      {
        v17 = offset;
      }
      if ( v28[v27] >= cur[v27] )
      {
        v20 = ptr1;
        *ptr0a = v19;
        ptr0a = pair;
        v19 = *pair;
        curMatch3a = v27;
      }
      else
      {
        v20 = pair + 1;
        *ptr1 = v19;
        v19 = pair[1];
        ptr1 = pair + 1;
        len1 = v27;
      }
      curMatch = v19;
      if ( v19 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  v22 = distances;
  *v20 = 0;
  *ptr0a = 0;
LABEL_23:
  *v22 = v17 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v23 = ++this->_pos;
  if ( v23 <= this->_posLimit )
    goto LABEL_29;
  if ( &this->_buffer[v23] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_29:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A0E0
// Name: private: virtual long NBT4::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::Skip(NBT4::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // ecx
  unsigned int v16; // eax
  int v17; // edx
  unsigned int v18; // ecx
  unsigned int *hash; // eax
  unsigned int v20; // edx
  unsigned int *v21; // edi
  unsigned int *v22; // ecx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // edi
  const unsigned __int8 *v29; // ecx
  int v30; // ebx
  const unsigned __int8 *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int *v34; // ebx
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // edx
  unsigned int count; // [esp+Ch] [ebp-2Ch]
  unsigned int *son; // [esp+10h] [ebp-28h]
  unsigned int len0; // [esp+1Ch] [ebp-1Ch]
  unsigned int len1; // [esp+20h] [ebp-18h]
  const unsigned __int8 *cur; // [esp+24h] [ebp-14h]
  unsigned int *pair; // [esp+28h] [ebp-10h]
  unsigned int matchMinPos; // [esp+2Ch] [ebp-Ch]
  unsigned int *ptr0; // [esp+30h] [ebp-8h]
  unsigned int *ptr1; // [esp+34h] [ebp-4h]
  unsigned int lenLimit; // [esp+40h] [ebp+8h]
  unsigned int lenLimita; // [esp+40h] [ebp+8h]
  unsigned int lenLimitb; // [esp+40h] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v17 = buffer[pos + 2];
      cur = &buffer[pos];
      v18 = this->_hashMask & (v16 ^ (32 * (CCRC::Table[buffer[pos + 3]] ^ (8 * v17))));
      this->_hash[(unsigned __int16)(v16 ^ ((_WORD)v17 << 8)) + 1024] = pos;
      this->_hash[v16 & 0x3FF] = this->_pos;
      hash = this->_hash;
      v20 = hash[v18 + 66560];
      hash[v18 + 66560] = this->_pos;
      v21 = this->_son;
      ptr0 = &v21[2 * this->_cyclicBufferPos + 1];
      v22 = &v21[2 * this->_cyclicBufferPos];
      len1 = 0;
      len0 = 0;
      cutValue = this->_cutValue;
      son = v21;
      ptr1 = v22;
      if ( v20 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v25 = this->_pos - v20;
          if ( v25 > cyclicBufferPos )
            v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
          else
            v26 = cyclicBufferPos - v25;
          pair = &v21[2 * v26];
          v27 = len0;
          v28 = &this->_buffer[v20];
          if ( len0 >= len1 )
            v27 = len1;
          v29 = cur;
          if ( v28[v27] == cur[v27] )
          {
            if ( ++v27 == lenLimit )
              goto LABEL_40;
            v30 = v28 - cur;
            v31 = &cur[v27];
            while ( v31[v30] == *v31 )
            {
              ++v27;
              ++v31;
              if ( v27 == lenLimit )
                goto LABEL_40;
              v30 = v28 - cur;
            }
            if ( v27 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v29 = cur;
          }
          if ( v28[v27] >= v29[v27] )
          {
            *ptr0 = v20;
            v20 = *pair;
            ptr0 = pair;
            v22 = ptr1;
            len0 = v27;
          }
          else
          {
            *ptr1 = v20;
            v20 = pair[1];
            v22 = pair + 1;
            ptr1 = pair + 1;
            len1 = v27;
          }
          if ( v20 <= matchMinPos )
            break;
          v21 = son;
          cutValue = count;
        }
      }
      *v22 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v32 = ++this->_pos;
      if ( v32 > this->_posLimit )
      {
        if ( &this->_buffer[v32] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v33 = this->_cyclicBufferSize;
        v34 = this->_hash;
        v35 = this->_hashSizeSum + 2 * v33;
        v11 = 0x7FFFFFFF - v33;
        v36 = 0;
        for ( lenLimitb = v35; v36 < lenLimitb; ++v36 )
        {
          v37 = v34[v36];
          if ( v37 > v11 )
            v38 = v37 - v11;
          else
            v38 = 0;
          v34[v36] = v38;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 4 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A430
// Name: private: virtual long NHC4::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::GetMatches(NHC4::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned __int16 v13; // dx
  __int16 v14; // di
  unsigned int *hash; // ecx
  int v16; // edi
  int v17; // ecx
  unsigned int v18; // edi
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v21; // edx
  unsigned int v22; // eax
  unsigned __int8 *v23; // edx
  unsigned int v24; // eax
  _BYTE *v25; // edi
  int v26; // edx
  unsigned int v27; // eax
  unsigned int *son; // [esp+8h] [ebp-20h]
  unsigned int curMatch3; // [esp+Ch] [ebp-1Ch]
  unsigned int curMatch3a; // [esp+Ch] [ebp-1Ch]
  unsigned int lenLimit; // [esp+10h] [ebp-18h]
  unsigned int cyclicPos; // [esp+14h] [ebp-14h]
  unsigned int cyclicPosa; // [esp+14h] [ebp-14h]
  int offset; // [esp+18h] [ebp-10h]
  unsigned int delta; // [esp+1Ch] [ebp-Ch]
  unsigned int deltaa; // [esp+1Ch] [ebp-Ch]
  unsigned int matchMinPos; // [esp+20h] [ebp-8h]
  const unsigned __int8 *cur; // [esp+24h] [ebp-4h]
  unsigned int maxLen; // [esp+30h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 4 )
    {
      *distances = 0;
      return NHC4::CMatchFinder::MovePos(this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  v11 = v9[2];
  cur = v9;
  v12 = this->_hashMask & (v10 ^ (32 * (CCRC::Table[v9[3]] ^ (8 * v11))));
  maxLen = 1;
  v13 = v10 ^ ((_WORD)v11 << 8);
  v14 = v10;
  hash = this->_hash;
  v16 = v14 & 0x3FF;
  cyclicPos = hash[v12 + 66560];
  delta = hash[v16];
  curMatch3 = hash[v13 + 1024];
  hash[v16] = this->_pos;
  if ( delta > matchMinPos && this->_buffer[delta] == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - delta - 1;
    v17 = 3;
  }
  else
  {
    v17 = 1;
  }
  this->_hash[v13 + 1024] = this->_pos;
  if ( curMatch3 > matchMinPos && this->_buffer[curMatch3] == *cur )
  {
    if ( curMatch3 == delta )
      v17 -= 2;
    distances[v17] = 3;
    distances[v17 + 1] = this->_pos - curMatch3 - 1;
    maxLen = 3;
    v17 += 2;
    delta = curMatch3;
  }
  v18 = cyclicPos;
  if ( v17 != 1 && delta == cyclicPos )
  {
    v17 -= 2;
    maxLen = 1;
  }
  this->_hash[v12 + 66560] = this->_pos;
  son = this->_son;
  son[this->_cyclicBufferPos] = cyclicPos;
  cutValue = this->_cutValue;
  if ( cyclicPos > matchMinPos )
  {
    while ( 1 )
    {
      curMatch3a = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v21 = this->_pos - v18;
      deltaa = v21;
      v22 = v21 > cyclicBufferPos ? this->_cyclicBufferSize + cyclicBufferPos - v21 : cyclicBufferPos - v21;
      v23 = &this->_buffer[v18];
      cyclicPosa = v22;
      if ( v23[maxLen] == cur[maxLen] && *v23 == *cur )
      {
        v24 = 1;
        if ( lenLimit != 1 )
        {
          v25 = cur + 1;
          v26 = v23 - cur;
          for ( offset = v26; v25[v26] == *v25; v26 = offset )
          {
            ++v24;
            ++v25;
            if ( v24 == lenLimit )
              break;
          }
        }
        if ( maxLen < v24 )
        {
          distances[v17] = v24;
          distances[v17 + 1] = deltaa - 1;
          v17 += 2;
          maxLen = v24;
          if ( v24 == lenLimit )
            break;
        }
      }
      v18 = son[cyclicPosa];
      if ( v18 <= matchMinPos )
        break;
      cutValue = curMatch3a;
    }
  }
  *distances = v17 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v27 = ++this->_pos;
  if ( v27 <= this->_posLimit )
    goto LABEL_43;
  if ( &this->_buffer[v27] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_43:
    if ( this->_pos == 0x7FFFFFFF )
      NHC4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A6D0
// Name: private: virtual long NHC4::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::Skip(NHC4::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int v3; // eax
  HRESULT result; // eax
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int *v7; // ebx
  unsigned int v8; // ecx
  bool v9; // zf
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // edx
  unsigned __int8 *buffer; // ecx
  unsigned int v15; // eax
  int v16; // edx
  unsigned int v17; // ecx
  unsigned int *v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int cyclicBufferSize; // eax
  unsigned int hashSizeSum; // edi
  unsigned int *hash; // ebx
  unsigned int v24; // edi
  unsigned int v25; // eax
  unsigned int v26; // edx
  unsigned int v27; // edx

  do
  {
    pos = this->_pos;
    if ( this->_streamPos - pos >= 4 )
    {
      buffer = this->_buffer;
      v15 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v16 = buffer[pos + 2];
      v17 = this->_hashMask & (v15 ^ (32 * (CCRC::Table[buffer[pos + 3]] ^ (8 * v16))));
      this->_hash[(unsigned __int16)(v15 ^ ((_WORD)v16 << 8)) + 1024] = pos;
      this->_hash[v15 & 0x3FF] = this->_pos;
      v18 = &this->_hash[v17 + 66560];
      v19 = *v18;
      *v18 = this->_pos;
      this->_son[this->_cyclicBufferPos++] = v19;
      if ( this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v20 = ++this->_pos;
      if ( v20 > this->_posLimit )
      {
        if ( &this->_buffer[v20] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        cyclicBufferSize = this->_cyclicBufferSize;
        hashSizeSum = this->_hashSizeSum;
        hash = this->_hash;
        v8 = 0x7FFFFFFF - cyclicBufferSize;
        v9 = cyclicBufferSize + hashSizeSum == 0;
        v24 = cyclicBufferSize + hashSizeSum;
        v25 = 0;
        if ( !v9 )
        {
          do
          {
            v26 = hash[v25];
            if ( v26 > v8 )
              v27 = v26 - v8;
            else
              v27 = 0;
            hash[v25++] = v27;
          }
          while ( v25 < v24 );
        }
        goto LABEL_27;
      }
    }
    else
    {
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v3 = ++this->_pos;
      if ( v3 > this->_posLimit )
      {
        if ( &this->_buffer[v3] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v5 = this->_cyclicBufferSize;
        v6 = this->_hashSizeSum;
        v7 = this->_hash;
        v8 = 0x7FFFFFFF - v5;
        v9 = v5 + v6 == 0;
        v10 = v5 + v6;
        v11 = 0;
        if ( !v9 )
        {
          do
          {
            v12 = v7[v11];
            if ( v12 > v8 )
              v13 = v12 - v8;
            else
              v13 = 0;
            v7[v11++] = v13;
          }
          while ( v11 < v10 );
        }
LABEL_27:
        this->_buffer += v8;
        this->_posLimit -= v8;
        this->_pos -= v8;
        this->_streamPos -= v8;
      }
    }
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A890
// Name: public: void NCompress::NLZMA::CLiteralEncoder2::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CLiteralEncoder2::Encode(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned __int8 symbol)
{
  NCompress::NLZMA::CLiteralEncoder2 *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int i; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 8;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    i = v7;
    Range = rangeEncoder->Range;
    v10 = v4->_encoders[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->_encoders[v5].Prob -= v4->_encoders[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->_encoders[v5].Prob += (2048 - v4->_encoders[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = i;
    v5 = v11 | (2 * v5);
  }
  while ( i != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1001A930
// Name: public: void NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(class NCompress::NRangeCoder::CEncoder __near *,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned __int8 matchByte,
        unsigned __int8 symbol)
{
  int v5; // edx
  int v6; // edx
  int v7; // ebx
  int v8; // edi
  unsigned int Range; // edx
  int v10; // ebx
  NCompress::NRangeCoder::CBitEncoder<5> *v11; // ecx
  unsigned int v12; // eax
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // eax
  int v17; // edi
  bool v18; // cf
  unsigned int v19; // ebx
  unsigned int v20; // eax
  unsigned int context; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  int ia; // [esp+1Ch] [ebp+8h]

  context = 1;
  v5 = 8;
  while ( 1 )
  {
    v6 = v5 - 1;
    v7 = matchByte >> v6;
    v8 = symbol >> v6;
    i = v6;
    Range = rangeEncoder->Range;
    v10 = v7 & 1;
    v11 = &this->_encoders[256 * v10 + 256 + context];
    v12 = v11->Prob * (Range >> 11);
    v13 = v8 & 1;
    if ( v13 != 0 )
    {
      rangeEncoder->Low += v12;
      rangeEncoder->Range = Range - v12;
      v11->Prob -= v11->Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v12;
      v11->Prob += (2048 - v11->Prob) >> 5;
    }
    v14 = rangeEncoder->Range;
    if ( v14 < 0x1000000 )
    {
      rangeEncoder->Range = v14 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    v5 = i;
    context = v13 | (2 * context);
    if ( v10 != v13 )
      break;
    if ( i == 0 )
      return;
  }
  if ( i != 0 )
  {
    do
    {
      --v5;
      v15 = context;
      v16 = this->_encoders[context].Prob * (rangeEncoder->Range >> 11);
      v17 = (symbol >> v5) & 1;
      ia = v5;
      if ( v17 != 0 )
      {
        v18 = __CFADD__(v16, rangeEncoder->Low);
        LODWORD(rangeEncoder->Low) += v16;
        v19 = rangeEncoder->Range;
        HIDWORD(rangeEncoder->Low) += v18;
        rangeEncoder->Range = v19 - v16;
        this->_encoders[context].Prob -= this->_encoders[context].Prob >> 5;
      }
      else
      {
        rangeEncoder->Range = v16;
        this->_encoders[context].Prob += (2048 - this->_encoders[context].Prob) >> 5;
      }
      v20 = rangeEncoder->Range;
      if ( v20 < 0x1000000 )
      {
        rangeEncoder->Range = v20 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
        v5 = ia;
        v15 = context;
      }
      context = v17 | (2 * v15);
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AA90
// Name: public: unsigned int NCompress::NLZMA::CLiteralEncoder2::GetPrice(bool,unsigned char,unsigned char)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CLiteralEncoder2::GetPrice(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        bool matchMode,
        unsigned __int8 matchByte,
        unsigned __int8 symbol)
{
  unsigned int result; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // edx
  int v8; // edx
  unsigned int price; // [esp+10h] [ebp-4h]

  result = 0;
  price = 0;
  v5 = 1;
  v6 = 8;
  if ( !matchMode )
    goto LABEL_9;
  do
  {
    v7 = (symbol >> --v6) & 1;
    result = NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v7
                                                              ^ (this->_encoders[256 * ((matchByte >> v6) & 1)
                                                                               + 256
                                                                               + v5].Prob
                                                               - v7)) >> 2)
                                                            & 0x1FF]
           + price;
    v5 = v7 | (2 * v5);
    price = result;
    if ( ((matchByte >> v6) & 1) != v7 )
      break;
  }
  while ( v6 != 0 );
  if ( v6 != 0 )
  {
LABEL_9:
    do
    {
      v8 = (symbol >> --v6) & 1;
      result += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v8 ^ (this->_encoders[v5].Prob - v8)) >> 2) & 0x1FF];
      v5 = v8 | (2 * v5);
    }
    while ( v6 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001AB60
// Name: public: void NCompress::NLZMA::NLength::CEncoder::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::Init(
        NCompress::NLZMA::NLength::CEncoder *this,
        unsigned int numPosStates)
{
  unsigned int v2; // esi
  NCompress::NRangeCoder::CBitEncoder<5> *v3; // eax

  v2 = numPosStates;
  this->_choice.Prob = 1024;
  this->_choice2.Prob = 1024;
  if ( numPosStates != 0 )
  {
    v3 = &this->_midCoder[0].Models[1];
    do
    {
      v3[-128].Prob = 1024;
      v3[-127].Prob = 1024;
      v3[-126].Prob = 1024;
      v3[-125].Prob = 1024;
      v3[-124].Prob = 1024;
      v3[-123].Prob = 1024;
      v3[-122].Prob = 1024;
      v3->Prob = 1024;
      v3[1].Prob = 1024;
      v3[2].Prob = 1024;
      v3[3].Prob = 1024;
      v3[4].Prob = 1024;
      v3[5].Prob = 1024;
      v3[6].Prob = 1024;
      v3 += 8;
      --v2;
    }
    while ( v2 != 0 );
  }
  memset32(&this->_highCoder.Models[1], 1024, 0xFFu);
}

//------------------------------------------------------------------------------
// Address: 0x1001ABE0
// Name: public: void NCompress::NLZMA::NLength::CEncoder::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::Encode(
        NCompress::NLZMA::NLength::CEncoder *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol,
        unsigned int posState)
{
  unsigned int v5; // eax
  unsigned int Range; // ecx
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // eax

  if ( symbol >= 8 )
  {
    Range = rangeEncoder->Range;
    v7 = this->_choice.Prob * (Range >> 11);
    rangeEncoder->Low += v7;
    rangeEncoder->Range = Range - v7;
    this->_choice.Prob -= this->_choice.Prob >> 5;
    v8 = rangeEncoder->Range;
    if ( v8 < 0x1000000 )
    {
      rangeEncoder->Range = v8 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    if ( symbol >= 0x10 )
    {
      v10 = rangeEncoder->Range;
      v11 = this->_choice2.Prob * (v10 >> 11);
      rangeEncoder->Low += v11;
      rangeEncoder->Range = v10 - v11;
      this->_choice2.Prob -= this->_choice2.Prob >> 5;
      v12 = rangeEncoder->Range;
      if ( v12 < 0x1000000 )
      {
        rangeEncoder->Range = v12 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(this: &this->_highCoder, rangeEncoder, symbol: symbol - 16);
    }
    else
    {
      rangeEncoder->Range = this->_choice2.Prob * (rangeEncoder->Range >> 11);
      this->_choice2.Prob += (2048 - this->_choice2.Prob) >> 5;
      v9 = rangeEncoder->Range;
      if ( v9 < 0x1000000 )
      {
        rangeEncoder->Range = v9 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(
        this: &this->_midCoder[posState],
        rangeEncoder,
        symbol: symbol - 8);
    }
  }
  else
  {
    rangeEncoder->Range = this->_choice.Prob * (rangeEncoder->Range >> 11);
    this->_choice.Prob += (2048 - this->_choice.Prob) >> 5;
    v5 = rangeEncoder->Range;
    if ( v5 < 0x1000000 )
    {
      rangeEncoder->Range = v5 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(this: &this->_lowCoder[posState], rangeEncoder, symbol);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AD30
// Name: public: void NCompress::NLZMA::NLength::CEncoder::SetPrices(unsigned int,unsigned int,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::SetPrices(
        NCompress::NLZMA::NLength::CEncoder *this,
        unsigned int posState,
        unsigned int numSymbols,
        unsigned int *prices)
{
  unsigned int v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // edx
  int i; // edi
  char v8; // al
  unsigned int v9; // edx
  unsigned int v10; // edx
  int v11; // edi
  char v12; // al
  unsigned int v13; // edx
  unsigned int v14; // edx
  int v15; // edi
  char v16; // al
  unsigned int b1; // [esp+Ch] [ebp-Ch]
  unsigned int b0; // [esp+10h] [ebp-8h]
  unsigned int a0; // [esp+14h] [ebp-4h]
  unsigned int a0a; // [esp+14h] [ebp-4h]
  unsigned int posStatea; // [esp+20h] [ebp+8h]

  a0 = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_choice.Prob >> 2];
  v4 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_choice.Prob) >> 2];
  b0 = v4 + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_choice2.Prob >> 2];
  b1 = v4 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_choice2.Prob) >> 2];
  v5 = 0;
  while ( v5 < numSymbols )
  {
    v6 = v5 | 8;
    for ( i = 0;
          v6 != 1;
          i += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v8 & 1)
                                                                ^ (this->_lowCoder[posState].Models[v6].Prob - (v8 & 1))) >> 2)
                                                              & 0x1FF] )
    {
      v8 = v6;
      v6 >>= 1;
    }
    prices[v5++] = a0 + i;
    if ( v5 >= 8 )
    {
      if ( v5 >= 0x10 )
      {
LABEL_12:
        if ( v5 < numSymbols )
        {
          v13 = v5 - 16;
          posStatea = v5 - 16;
          do
          {
            v14 = v13 | 0x100;
            v15 = 0;
            do
            {
              v16 = v14;
              v14 >>= 1;
              v15 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v16 & 1)
                                                                      ^ (this->_highCoder.Models[v14].Prob - (v16 & 1))) >> 2)
                                                                    & 0x1FF];
            }
            while ( v14 != 1 );
            prices[v5++] = b1 + v15;
            v13 = ++posStatea;
          }
          while ( v5 < numSymbols );
        }
      }
      else
      {
        v9 = v5 - 8;
        a0a = v5 - 8;
        while ( v5 < numSymbols )
        {
          v10 = v9 | 8;
          v11 = 0;
          do
          {
            v12 = v10;
            v10 >>= 1;
            v11 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v12 & 1)
                                                                    ^ (this->_midCoder[posState].Models[v10].Prob
                                                                     - (v12 & 1))) >> 2)
                                                                  & 0x1FF];
          }
          while ( v10 != 1 );
          prices[v5++] = b0 + v11;
          v9 = ++a0a;
          if ( v5 >= 0x10 )
            goto LABEL_12;
        }
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AEB0
// Name: public: virtual long NCompress::NLZMA::CEncoder::SetCoderProperties(unsigned long const __near *,struct tagPROPVARIANT const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::SetCoderProperties(
        NCompress::NLZMA::CEncoder *this,
        const unsigned int *propIDs,
        const tagPROPVARIANT *properties,
        unsigned int numProperties)
{
  unsigned int v4; // eax
  unsigned int v6; // eax
  ISequentialInStream *MatchFinder; // eax
  bool v8; // zf
  unsigned int Lo32; // edx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int i; // [esp+Ch] [ebp-4h]
  ISequentialInStream *matchFinderIndexPrev; // [esp+20h] [ebp+10h]

  v4 = 0;
  i = 0;
  if ( numProperties != 0 )
  {
    while ( 2 )
    {
      switch ( propIDs[v4] )
      {
        case 0x400u:
          if ( properties->vt != 19 )
            return -2147024809;
          Lo32 = properties->decVal.Lo32;
          if ( Lo32 - 1 > 0x3FFFFFFF )
            return -2147024809;
          this->_numLiteralPosStateBits = Lo32;
          v10 = 0;
          v11 = 1;
          do
          {
            if ( Lo32 <= v11 )
              break;
            ++v10;
            v11 = __ROL4__(v11, 1);
          }
          while ( v10 < 0x1E );
          this->_alignPrices[15] = 2 * v10;
          goto LABEL_32;
        case 0x440u:
          if ( properties->vt != 19 )
            return -2147024809;
          v12 = properties->decVal.Lo32;
          if ( v12 > 4 )
            return -2147024809;
          this->_alignPriceCount = v12;
          this->_distTableSize = (1 << v12) - 1;
          goto LABEL_32;
        case 0x441u:
          if ( properties->vt != 19 )
            return -2147024809;
          v14 = properties->decVal.Lo32;
          if ( v14 > 8 )
            return -2147024809;
          this->_posStateMask = v14;
          goto LABEL_32;
        case 0x442u:
          if ( properties->vt != 19 )
            return -2147024809;
          v13 = properties->decVal.Lo32;
          if ( v13 > 4 )
            return -2147024809;
          this->_posStateBits = v13;
          goto LABEL_32;
        case 0x450u:
          if ( properties->vt != 19 )
            return -2147024809;
          v6 = properties->decVal.Lo32;
          if ( v6 - 5 > 0x10C )
            return -2147024809;
          this->_matchDistances[548] = v6;
          goto LABEL_32;
        case 0x451u:
          if ( properties->vt != 8 )
            return -2147024809;
          matchFinderIndexPrev = this->_inStream;
          MatchFinder = (ISequentialInStream *)NCompress::NLZMA::FindMatchFinder(s: properties->bstrVal);
          if ( (int)MatchFinder < 0 )
            return -2147024809;
          v8 = this->_optimum[4095].Backs[2] == 0;
          this->_inStream = MatchFinder;
          if ( !v8 && matchFinderIndexPrev != MatchFinder )
          {
            this->_numLiteralContextBits = -1;
            NCompress::NLZMA::CEncoder::ReleaseMatchFinder(this: (NCompress::NLZMA::CEncoder *)((char *)this - 8));
          }
          goto LABEL_32;
        case 0x452u:
          if ( properties->vt != 19 )
            return -2147024809;
          *(_DWORD *)&this->_finished = properties->decVal.Lo32;
          goto LABEL_32;
        case 0x470u:
          if ( properties->vt != 19 )
            return -2147024809;
          LOBYTE(this->_matchDistances[547]) = properties->decVal.Lo32 == 0;
          goto LABEL_32;
        case 0x490u:
          if ( properties->vt != 11 )
            return -2147024809;
          LOBYTE(this->_matchFinderCycles) = properties->iVal == -1;
LABEL_32:
          v4 = i + 1;
          ++properties;
          i = v4;
          if ( v4 >= numProperties )
            return 0;
          continue;
        default:
          return -2147024809;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B140
// Name: public: virtual long NCompress::NLZMA::CEncoder::ReleaseOutStream(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::ReleaseOutStream(NCompress::NLZMA::CEncoder *this)
{
  unsigned int bufferSize; // eax

  bufferSize = this->_rangeEncoder.Stream._bufferSize;
  if ( bufferSize != 0 )
  {
    (*(void (__stdcall **)(unsigned int))(*(_DWORD *)bufferSize + 8))(a1: this->_rangeEncoder.Stream._bufferSize);
    this->_rangeEncoder.Stream._bufferSize = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B170
// Name: public: long NCompress::NLZMA::CEncoder::Init(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Init(NCompress::NLZMA::CEncoder *this)
{
  NCompress::NRangeCoder::CBitEncoder<5> *isRepG0; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v3; // edi
  unsigned int v4; // edx
  NCompress::NRangeCoder::CBitEncoder<5> *v5; // eax
  int v6; // ecx
  int v7; // edx
  NCompress::NLZMA::CLiteralEncoder2 *v8; // edi
  bool v9; // zf
  NCompress::NRangeCoder::CBitEncoder<5> *v10; // edx
  NCompress::NRangeCoder::CBitEncoder<5> *v11; // edi
  int i; // [esp+Ch] [ebp-4h]
  int v14; // [esp+Ch] [ebp-4h]
  int v15; // [esp+Ch] [ebp-4h]

  *(_WORD *)&this->_state.Index = 0;
  this->_repDistances[0] = 0;
  this->_repDistances[1] = 0;
  this->_repDistances[2] = 0;
  this->_repDistances[3] = 0;
  COutBuffer::Init(this: &this->_rangeEncoder.Stream);
  this->_rangeEncoder.Low = 0;
  this->_rangeEncoder.Range = -1;
  this->_rangeEncoder._cacheSize = 1;
  this->_rangeEncoder._cache = 0;
  isRepG0 = this->_isRepG0;
  v3 = this->_isRep0Long[0];
  for ( i = 12; i != 0; --i )
  {
    v4 = 0;
    v5 = v3;
    do
    {
      v5[-240].Prob = 1024;
      v5->Prob = 1024;
      ++v4;
      ++v5;
    }
    while ( v4 <= this->_posStateMask );
    isRepG0[-12].Prob = 1024;
    isRepG0->Prob = 1024;
    isRepG0[12].Prob = 1024;
    isRepG0[24].Prob = 1024;
    ++isRepG0;
    v3 += 16;
  }
  v6 = this->_literalEncoder._numPrevBits + this->_literalEncoder._numPosBits;
  if ( 1 << v6 != 0 )
  {
    v7 = 0;
    v14 = 1 << v6;
    do
    {
      v8 = &this->_literalEncoder._coders[v7++];
      v9 = v14-- == 1;
      memset32(v8, 1024, 0x300u);
    }
    while ( !v9 );
  }
  v10 = &this->_posSlotEncoder[0].Models[1];
  v15 = 4;
  do
  {
    v11 = v10;
    v10 += 64;
    v9 = v15-- == 1;
    memset32(v11, 1024, 0x3Fu);
  }
  while ( !v9 );
  memset32(this->_posEncoders, 1024, 0x72u);
  NCompress::NLZMA::NLength::CEncoder::Init(this: &this->_lenEncoder, numPosStates: 1 << this->_posStateBits);
  NCompress::NLZMA::NLength::CEncoder::Init(this: &this->_repMatchLenEncoder, numPosStates: 1 << this->_posStateBits);
  this->_posAlignEncoder.Models[1].Prob = 1024;
  this->_posAlignEncoder.Models[2].Prob = 1024;
  this->_posAlignEncoder.Models[3].Prob = 1024;
  this->_posAlignEncoder.Models[4].Prob = 1024;
  this->_posAlignEncoder.Models[5].Prob = 1024;
  this->_posAlignEncoder.Models[6].Prob = 1024;
  this->_posAlignEncoder.Models[7].Prob = 1024;
  this->_posAlignEncoder.Models[8].Prob = 1024;
  this->_posAlignEncoder.Models[9].Prob = 1024;
  this->_posAlignEncoder.Models[10].Prob = 1024;
  this->_posAlignEncoder.Models[11].Prob = 1024;
  this->_posAlignEncoder.Models[12].Prob = 1024;
  this->_posAlignEncoder.Models[13].Prob = 1024;
  this->_posAlignEncoder.Models[14].Prob = 1024;
  this->_posAlignEncoder.Models[15].Prob = 1024;
  this->_longestMatchWasFound = false;
  this->_optimumEndIndex = 0;
  this->_optimumCurrentIndex = 0;
  this->_additionalOffset = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B340
// Name: private: long NCompress::NLZMA::CEncoder::ReadMatchDistances(unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::ReadMatchDistances(
        NCompress::NLZMA::CEncoder *this,
        unsigned int *lenRes,
        unsigned int *numDistancePairs)
{
  unsigned int *matchDistances; // ebx
  HRESULT result; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax

  *lenRes = 0;
  matchDistances = this->_matchDistances;
  result = this->_matchFinder._p->GetMatches(this: this->_matchFinder._p, a2: this->_matchDistances);
  if ( result == 0 )
  {
    v6 = *matchDistances;
    *numDistancePairs = *matchDistances;
    if ( v6 != 0 )
    {
      v7 = *(&this->_literalEncoder._posMask + v6);
      *lenRes = v7;
      if ( v7 == this->_numFastBytes )
        *lenRes += this->_matchFinder._p->GetMatchLen(
                     this: this->_matchFinder._p,
                     a2: v7 - 1,
                     a3: this->_matchDistances[*numDistancePairs],
                     a4: 273 - v7);
    }
    ++this->_additionalOffset;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B3C0
// Name: private: long NCompress::NLZMA::CEncoder::GetOptimumFast(unsigned int,unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetOptimumFast(
        NCompress::NLZMA::CEncoder *this,
        unsigned int position,
        unsigned int *backRes,
        unsigned int *lenRes)
{
  NCompress::NLZMA::CEncoder *v4; // ebx
  bool v5; // zf
  unsigned int result; // eax
  unsigned int v7; // eax
  const unsigned __int8 *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  const unsigned __int8 *v11; // ecx
  unsigned int j; // eax
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int *v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned int longestMatchLength; // eax
  unsigned int v20; // esi
  unsigned int v21; // edx
  unsigned int *repDistances; // esi
  const unsigned __int8 *v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int repLens[4]; // [esp+4h] [ebp-28h]
  unsigned int newDistance; // [esp+14h] [ebp-18h]
  unsigned int i; // [esp+18h] [ebp-14h]
  unsigned int numDistancePairs; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int numAvailableBytes; // [esp+20h] [ebp-Ch]
  unsigned int backMain; // [esp+24h] [ebp-8h]
  unsigned int lenMain; // [esp+28h] [ebp-4h] BYREF

  v4 = this;
  v5 = !this->_longestMatchWasFound;
  newDistance = (unsigned int)this;
  if ( v5 )
  {
    result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &lenMain, &numDistancePairs);
    if ( result != 0 )
      return result;
  }
  else
  {
    v7 = this->_numDistancePairs;
    lenMain = this->_longestMatchLength;
    numDistancePairs = v7;
    this->_longestMatchWasFound = false;
  }
  v8 = v4->_matchFinder._p->GetPointerToCurrentPos(this: v4->_matchFinder._p);
  v9 = v4->_matchFinder._p->GetNumAvailableBytes(this: v4->_matchFinder._p) + 1;
  numAvailableBytes = v9;
  if ( v9 <= 0x111 )
  {
    if ( v9 < 2 )
    {
      *backRes = -1;
      *lenRes = 1;
      return 0;
    }
  }
  else
  {
    numAvailableBytes = 273;
  }
  v10 = 0;
  i = 0;
  backMain = 0;
  while ( 1 )
  {
    v11 = &v8[-v4->_repDistances[v10] - 2];
    if ( *(v8 - 1) == *v11 && *v8 == v8[-v4->_repDistances[v10] - 1] )
      break;
    repLens[v10] = 0;
LABEL_19:
    if ( ++v10 >= 4 )
    {
      v14 = lenMain;
      if ( lenMain >= v4->_numFastBytes )
      {
        *backRes = v4->_matchDistances[numDistancePairs] + 4;
        result = v14 - 1;
        *lenRes = v14;
        if ( v14 == 1 )
          return result;
        goto LABEL_24;
      }
      backMain = 0;
      if ( lenMain >= 2 )
      {
        v15 = numDistancePairs;
        backMain = v4->_matchDistances[numDistancePairs];
        if ( numDistancePairs > 2 )
        {
          v16 = (unsigned int *)(&v4->_literalEncoder._numPosBits + numDistancePairs);
          do
          {
            if ( lenMain != *(v16 - 1) + 1 )
              break;
            if ( backMain >> 7 <= *v16 )
              break;
            v17 = *(v16 - 1);
            v16 -= 2;
            v15 -= 2;
            lenMain = v17;
            backMain = v16[2];
          }
          while ( v15 > 2 );
          v14 = lenMain;
        }
        if ( v14 == 2 && backMain >= 0x80 )
        {
          lenMain = 1;
          v14 = 1;
        }
      }
      v18 = repLens[i];
      if ( v18 >= 2 && (v18 + 1 >= v14 || v18 + 2 >= v14 && backMain > 0x200 || v18 + 3 >= v14 && backMain > 0x8000) )
      {
        *backRes = i;
        *lenRes = v18;
        result = v18 - 1;
        if ( result != 0 )
          goto LABEL_24;
        return result;
      }
      if ( v14 < 2 || numAvailableBytes <= 2 )
      {
        *backRes = -1;
        *lenRes = 1;
        return 0;
      }
      result = NCompress::NLZMA::CEncoder::ReadMatchDistances(
                 this: v4,
                 lenRes: &v4->_longestMatchLength,
                 numDistancePairs: &v4->_numDistancePairs);
      if ( result != 0 )
        return result;
      longestMatchLength = v4->_longestMatchLength;
      if ( longestMatchLength >= 2 )
      {
        v20 = v4->_matchDistances[v4->_numDistancePairs];
        newDistance = v20;
        if ( longestMatchLength >= lenMain && v20 < backMain )
          goto LABEL_56;
        if ( longestMatchLength == lenMain + 1 )
        {
          if ( v20 >> 7 <= backMain )
          {
LABEL_56:
            v4->_longestMatchWasFound = true;
            *backRes = -1;
            *lenRes = 1;
            return 0;
          }
          v20 = newDistance;
        }
        if ( longestMatchLength > lenMain + 1
          || longestMatchLength + 1 >= lenMain && lenMain >= 3 && backMain >> 7 > v20 )
        {
          goto LABEL_56;
        }
      }
      --numAvailableBytes;
      v21 = 0;
      i = 0;
      repDistances = v4->_repDistances;
      do
      {
        v23 = &v8[-*repDistances - 1];
        if ( v8[1] == v8[-*repDistances] && v8[2] == v23[2] )
        {
          v24 = 2;
          if ( numAvailableBytes > 2 )
          {
            do
            {
              if ( v8[v24] != v23[v24] )
                break;
              ++v24;
            }
            while ( v24 < numAvailableBytes );
            v21 = i;
          }
          if ( v24 + 1 >= lenMain )
            goto LABEL_56;
        }
        else
        {
          repLens[v21] = 0;
        }
        ++v21;
        ++repDistances;
        i = v21;
      }
      while ( v21 < 4 );
      *backRes = backMain + 4;
      v25 = lenMain;
      *lenRes = lenMain;
      result = v25 - 2;
      if ( result != 0 )
        goto LABEL_24;
      return 0;
    }
  }
  for ( j = 2; j < numAvailableBytes; ++j )
  {
    if ( v8[j - 1] != v11[j] )
      break;
  }
  v4 = (NCompress::NLZMA::CEncoder *)newDistance;
  if ( j < *(_DWORD *)(newDistance + 208512) )
  {
    v13 = backMain;
    repLens[v10] = j;
    if ( j > *(unsigned int *)((char *)repLens + v13) )
    {
      i = v10;
      backMain = 4 * v10;
    }
    goto LABEL_19;
  }
  *backRes = v10;
  *lenRes = j;
  result = j - 1;
  if ( result != 0 )
  {
LABEL_24:
    v4->_additionalOffset += result;
    return v4->_matchFinder._p->Skip(this: v4->_matchFinder._p, a2: result);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B750
// Name: private: void NCompress::NLZMA::CEncoder::FillDistancesPrices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::FillDistancesPrices(NCompress::NLZMA::CEncoder *this)
{
  NCompress::NLZMA::CEncoder *v1; // ebx
  unsigned int i; // esi
  int v3; // eax
  unsigned int *v4; // esi
  unsigned int *v5; // edx
  unsigned int v6; // edi
  unsigned int v7; // ecx
  unsigned int v8; // esi
  char v9; // al
  unsigned int j; // eax
  unsigned int v11; // eax
  _DWORD *v12; // esi
  int v13; // ecx
  unsigned int tempPrices[128]; // [esp+Ch] [ebp-210h] BYREF
  NCompress::NLZMA::CEncoder *v15; // [esp+20Ch] [ebp-10h]
  int v16; // [esp+210h] [ebp-Ch]
  char *v17; // [esp+214h] [ebp-8h]
  unsigned int *v18; // [esp+218h] [ebp-4h]

  v1 = this;
  v15 = this;
  for ( i = 4; i < 0x80; ++i )
  {
    v3 = (NCompress::NLZMA::g_FastPos[i] & 1 | 2) << ((NCompress::NLZMA::g_FastPos[i] >> 1) - 1);
    tempPrices[i] = NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(
                      Models: &v1->_posSlotEncoder[3].Models[v3 - NCompress::NLZMA::g_FastPos[i] + 63],
                      NumBitLevels: (NCompress::NLZMA::g_FastPos[i] >> 1) - 1,
                      symbol: i - v3);
  }
  v4 = &v1->_distancesPrices[0][2];
  v5 = v1->_posSlotPrices[0];
  v18 = &v1->_distancesPrices[0][2];
  v17 = (char *)((char *)tempPrices - (char *)v1 - 209564);
  v16 = 4;
  while ( 1 )
  {
    v6 = 0;
    if ( v1->_distTableSize != 0 )
    {
      do
      {
        v7 = v6 | 0x40;
        v8 = 0;
        if ( (v6 | 0x40) != 1 )
        {
          do
          {
            v9 = v7;
            v7 >>= 1;
            v8 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v9 & 1) ^ (v5[v7 - 10713] - (v9 & 1))) >> 2)
                                                                 & 0x1FF];
          }
          while ( v7 != 1 );
          v1 = v15;
        }
        v5[v6++] = v8;
      }
      while ( v6 < v1->_distTableSize );
      v4 = v18;
    }
    for ( j = 14; j < v1->_distTableSize; ++j )
      v5[j] += ((j >> 1) - 5) << 6;
    *(v4 - 2) = *v5;
    *(v4 - 1) = v5[1];
    *v4 = v5[2];
    v4[1] = v5[3];
    v11 = 4;
    v12 = v4 + 2;
    do
    {
      v13 = NCompress::NLZMA::g_FastPos[v11++];
      *v12 = *(_DWORD *)((char *)v12 + (_DWORD)v17) + v5[v13];
      ++v12;
    }
    while ( v11 < 0x80 );
    v18 += 128;
    v17 -= 512;
    v5 += 64;
    if ( --v16 == 0 )
      break;
    v4 = v18;
  }
  v1->_matchPriceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B920
// Name: private: void NCompress::NLZMA::CEncoder::FillAlignPrices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::FillAlignPrices(NCompress::NLZMA::CEncoder *this)
{
  unsigned int v1; // edi
  unsigned int v2; // esi
  int v3; // edx
  int v4; // eax
  unsigned int *alignPrices; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  v1 = 0;
  i = 0;
  alignPrices = this->_alignPrices;
  do
  {
    v2 = 0;
    v3 = 1;
    for ( j = 4; j != 0; --j )
    {
      v4 = v1 & 1;
      v2 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v4 ^ (this->_posAlignEncoder.Models[v3].Prob - v4)) >> 2)
                                                           & 0x1FF];
      v1 >>= 1;
      v3 = v4 | (2 * v3);
    }
    v1 = i + 1;
    *alignPrices = v2;
    i = v1;
    ++alignPrices;
  }
  while ( v1 < 0x10 );
  this->_alignPriceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B9B0
// Name: public: void NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(
        NCompress::NLZMA::NLength::CPriceTableEncoder *this,
        unsigned int numPosStates)
{
  unsigned int v2; // esi
  unsigned int *counters; // edi
  unsigned int *v4; // ebx

  v2 = 0;
  if ( numPosStates != 0 )
  {
    counters = this->_counters;
    v4 = this->_prices[0];
    do
    {
      NCompress::NLZMA::NLength::CEncoder::SetPrices(this, posState: v2, numSymbols: this->_tableSize, prices: v4);
      *counters = this->_tableSize;
      ++v2;
      ++counters;
      v4 += 272;
    }
    while ( v2 < numPosStates );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BA00
// Name: public: void NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(
        NCompress::NLZMA::NLength::CPriceTableEncoder *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol,
        unsigned int posState,
        bool updatePrice)
{
  NCompress::NLZMA::NLength::CEncoder::Encode(this, rangeEncoder, symbol, posState);
  if ( updatePrice && this->_counters[posState]-- == 1 )
  {
    NCompress::NLZMA::NLength::CEncoder::SetPrices(
      this,
      posState,
      numSymbols: this->_tableSize,
      prices: this->_prices[posState]);
    this->_counters[posState] = this->_tableSize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BA60
// Name: public: NBT3::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT3::CMatchFinder *__thiscall NBT3::CMatchFinder::CMatchFinder(NBT3::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT3::CMatchFinder_vtbl *)&NBT3::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT3::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT3::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001BA90
// Name: public: NBT4::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT4::CMatchFinder *__thiscall NBT4::CMatchFinder::CMatchFinder(NBT4::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT4::CMatchFinder_vtbl *)&NBT4::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT4::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT4::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001BAC0
// Name: public: NHC4::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NHC4::CMatchFinder *__thiscall NHC4::CMatchFinder::CMatchFinder(NHC4::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NHC4::CMatchFinder_vtbl *)&NHC4::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NHC4::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NHC4::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001BAF0
// Name: public: NCompress::NLZMA::CEncoder::CEncoder(void)
// Source: json
//------------------------------------------------------------------------------
NCompress::NLZMA::CEncoder *__thiscall NCompress::NLZMA::CEncoder::CEncoder(NCompress::NLZMA::CEncoder *this)
{
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&ICompressSetOutStream::`vftable';
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&ICompressSetCoderProperties::`vftable';
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&ICompressWriteCoderProperties::`vftable';
  this->__m_RefCount = 0;
  this->ICompressCoder::IUnknown::__vftable = (NCompress::NLZMA::CEncoder_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressCoder'};
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetOutStream'};
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetCoderProperties'};
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressWriteCoderProperties'};
  this->_matchFinder._p = nullptr;
  this->_rangeEncoder.Stream._buffer = nullptr;
  this->_rangeEncoder.Stream._pos = 0;
  this->_rangeEncoder.Stream._stream._p = nullptr;
  this->_rangeEncoder.Stream._buffer2 = nullptr;
  this->_literalEncoder._coders = nullptr;
  this->_posStateMask = 3;
  this->_numLiteralContextBits = 3;
  this->_numFastBytes = 32;
  this->_distTableSize = 44;
  this->_posStateBits = 2;
  this->_numLiteralPosStateBits = 0;
  this->_dictionarySize = 0x400000;
  this->_dictionarySizePrev = -1;
  this->_numFastBytesPrev = -1;
  this->_matchFinderCycles = 0;
  this->_matchFinderIndex = 2;
  this->_writeEndMark = false;
  this->setMfPasses = nullptr;
  this->_fastMode = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001BBC0
// Name: _IsEqualGUID
// Source: json
//------------------------------------------------------------------------------
int __cdecl IsEqualGUID(const _GUID *rguid1, const _GUID *rguid2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( rguid1->Data1 == rguid2->Data1 )
  {
    v4 -= 4;
    rguid2 = (const _GUID *)((char *)rguid2 + 4);
    rguid1 = (const _GUID *)((char *)rguid1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001BC30
// Name: public: virtual long NCompress::NLZMA::CEncoder::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::QueryInterface(
        NCompress::NLZMA::CEncoder *this,
        const _GUID *iid,
        void **outObject)
{
  NCompress::NLZMA::CEncoder *v3; // eax

  if ( IsEqualGUID(rguid1: iid, rguid2: &IID_ICompressSetOutStream) != 0 )
  {
    v3 = this;
    if ( this != nullptr )
    {
      *outObject = &this->ICompressSetOutStream;
      this->AddRef(this);
      return 0;
    }
    goto LABEL_4;
  }
  if ( IsEqualGUID(rguid1: iid, rguid2: &IID_ICompressSetCoderProperties) != 0 )
  {
    v3 = this;
    if ( this != nullptr )
    {
      *outObject = &this->ICompressSetCoderProperties;
      this->AddRef(this);
      return 0;
    }
LABEL_4:
    *outObject = nullptr;
    v3->AddRef(this: v3);
    return 0;
  }
  if ( IsEqualGUID(rguid1: iid, rguid2: &IID_ICompressWriteCoderProperties) == 0 )
    return -2147467262;
  v3 = this;
  if ( this == nullptr )
    goto LABEL_4;
  *outObject = &this->ICompressWriteCoderProperties;
  this->AddRef(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001BCF0
// Name: public: virtual unsigned long NCompress::NLZMA::CEncoder::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NCompress::NLZMA::CEncoder::AddRef(NCompress::NLZMA::CEncoder *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001BD10
// Name: public: virtual unsigned long NCompress::NLZMA::CEncoder::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NCompress::NLZMA::CEncoder::Release(NCompress::NLZMA::CEncoder *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    ((void (__thiscall *)(NCompress::NLZMA::CEncoder *, int))this->dtr_CEncoder)(a1: this, a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001BDC0
// Name: public: virtual NCompress::NLZMA::CEncoder::~CEncoder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::~CEncoder(NCompress::NLZMA::CEncoder *this)
{
  ISequentialOutStream *p; // edi
  IMatchFinder *v3; // esi

  this->ICompressCoder::IUnknown::__vftable = (NCompress::NLZMA::CEncoder_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressCoder'};
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetOutStream'};
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetCoderProperties'};
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressWriteCoderProperties'};
  MyFree(address: this->_literalEncoder._coders);
  this->_literalEncoder._coders = nullptr;
  COutBuffer::Free(this: &this->_rangeEncoder.Stream);
  p = this->_rangeEncoder.Stream._stream._p;
  if ( p != nullptr )
    p->Release(this: this->_rangeEncoder.Stream._stream._p);
  v3 = this->_matchFinder._p;
  if ( v3 != nullptr )
    v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1001BE60
// Name: private: long NCompress::NLZMA::CEncoder::GetOptimum(unsigned int,unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
HRESULT __userpurge NCompress::NLZMA::CEncoder::GetOptimum@<eax>(
        NCompress::NLZMA::CEncoder *this@<ecx>,
        IMatchFinder *a2@<esi>,
        unsigned int position,
        unsigned int *backRes,
        unsigned int *lenRes)
{
  unsigned int optimumCurrentIndex; // eax
  int v7; // ecx
  int v8; // edx
  char *v9; // ecx
  HRESULT result; // eax
  bool v11; // zf
  unsigned int v12; // edx
  const unsigned __int8 *v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // ecx
  const unsigned __int8 *v18; // edi
  unsigned int i; // ecx
  unsigned int v20; // eax
  bool v21; // cc
  unsigned int v22; // edi
  unsigned int numFastBytes; // ecx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned __int8 v26; // cl
  unsigned __int8 v27; // dl
  unsigned __int8 Index; // cl
  unsigned int posStateMask; // edi
  unsigned __int8 v30; // dl
  int numPrevBits; // eax
  unsigned int v32; // edi
  int v33; // edx
  unsigned __int8 v34; // cl
  unsigned int v35; // esi
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  unsigned int *p_Price; // ecx
  unsigned int v40; // esi
  unsigned int PureRepPrice; // eax
  unsigned int v42; // eax
  unsigned int *v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // eax
  unsigned int *j; // esi
  unsigned int PosLenPrice; // eax
  unsigned int v50; // eax
  unsigned int v51; // edx
  HRESULT (__stdcall *GetMatches)(IMatchFinder *, unsigned int *); // eax
  unsigned int v53; // esi
  unsigned int v54; // edi
  unsigned int v55; // edx
  int v56; // esi
  char *v57; // eax
  char v58; // dl
  int v59; // ecx
  int v60; // ecx
  unsigned __int8 v61; // cl
  unsigned int v62; // edi
  unsigned __int8 v63; // cl
  NCompress::NLZMA::COptimal *v64; // edx
  unsigned int v65; // esi
  unsigned int v66; // ecx
  unsigned int v67; // edx
  unsigned int v68; // edx
  unsigned int v69; // esi
  unsigned int v70; // ecx
  const unsigned __int8 *v71; // edi
  unsigned __int8 v72; // al
  unsigned __int8 v73; // dl
  unsigned int v74; // esi
  int v75; // eax
  unsigned int v76; // edx
  unsigned int v77; // esi
  unsigned int v78; // eax
  unsigned int v79; // esi
  NCompress::NLZMA::COptimal *v80; // eax
  unsigned int v81; // ecx
  unsigned int v82; // ecx
  unsigned int v83; // eax
  unsigned int v84; // ecx
  unsigned int v85; // ecx
  unsigned int v86; // ecx
  unsigned int v87; // ecx
  unsigned int v88; // eax
  unsigned int v89; // edi
  unsigned int v90; // edx
  unsigned int v91; // ecx
  unsigned int v92; // edx
  unsigned int v93; // esi
  unsigned int v94; // ecx
  unsigned int v95; // edi
  unsigned int *v96; // ecx
  unsigned int v97; // ecx
  NCompress::NLZMA::COptimal *v98; // eax
  unsigned int v99; // eax
  unsigned int v100; // eax
  const unsigned __int8 *v101; // ecx
  unsigned int k; // edi
  unsigned int v103; // eax
  unsigned int *v104; // ecx
  unsigned int v105; // esi
  unsigned int v106; // eax
  unsigned int v107; // eax
  unsigned int *v108; // ecx
  unsigned int v109; // edx
  unsigned int v110; // eax
  unsigned int v111; // ecx
  const unsigned __int8 *v112; // edi
  unsigned int v113; // eax
  unsigned int v114; // ecx
  int v115; // eax
  unsigned int v116; // edi
  unsigned int v117; // eax
  unsigned int v118; // eax
  unsigned int v119; // edx
  unsigned int v120; // ecx
  _DWORD *v121; // edi
  unsigned int v122; // ecx
  NCompress::NLZMA::COptimal *v123; // eax
  unsigned int v124; // edx
  unsigned int v125; // ecx
  unsigned int v126; // edx
  int v127; // eax
  unsigned int v128; // edi
  unsigned int v129; // eax
  unsigned int *v130; // edx
  unsigned int v131; // eax
  unsigned int v132; // eax
  unsigned int v133; // ecx
  int v134; // esi
  unsigned int *v135; // edx
  unsigned int v136; // edi
  unsigned int v137; // eax
  unsigned int v138; // eax
  unsigned int v139; // eax
  unsigned int v140; // ecx
  unsigned int v141; // eax
  unsigned int v142; // esi
  const unsigned __int8 *v143; // eax
  unsigned int v144; // eax
  unsigned int v145; // esi
  int v146; // edx
  unsigned __int8 v147; // cl
  int v148; // edi
  unsigned int Prob; // edx
  unsigned int v150; // esi
  int v151; // edi
  int v152; // eax
  unsigned int v153; // eax
  unsigned int v154; // eax
  unsigned int v155; // edx
  unsigned int v156; // ecx
  _DWORD *v157; // esi
  unsigned int v158; // ecx
  NCompress::NLZMA::COptimal *v159; // eax
  unsigned int v160; // edx
  unsigned int v161; // edx
  unsigned int v162; // ecx
  unsigned int v163; // eax
  unsigned int v164; // eax
  unsigned int v165; // eax
  IMatchFinder *p; // [esp-10h] [ebp-98h]
  unsigned __int8 v167; // [esp-Ch] [ebp-94h]
  unsigned __int8 v168; // [esp-Ch] [ebp-94h]
  unsigned int repLens[4]; // [esp+4h] [ebp-84h]
  unsigned int v171; // [esp+14h] [ebp-74h]
  unsigned int v172; // [esp+18h] [ebp-70h]
  unsigned int curAndLenPrice; // [esp+1Ch] [ebp-6Ch]
  unsigned __int8 matchByte[4]; // [esp+20h] [ebp-68h]
  int currentByte; // [esp+24h] [ebp-64h]
  unsigned int reps[4]; // [esp+28h] [ebp-60h] BYREF
  unsigned int price; // [esp+38h] [ebp-50h]
  unsigned int backOffset; // [esp+3Ch] [ebp-4Ch]
  unsigned int v179; // [esp+40h] [ebp-48h]
  unsigned int newLen; // [esp+44h] [ebp-44h]
  unsigned int lenTest2; // [esp+48h] [ebp-40h]
  unsigned int repMatchPrice; // [esp+4Ch] [ebp-3Ch]
  const unsigned __int8 *data; // [esp+50h] [ebp-38h]
  unsigned int normalMatchPrice; // [esp+54h] [ebp-34h]
  unsigned int numDistancePairs; // [esp+58h] [ebp-30h] BYREF
  unsigned int posState; // [esp+5Ch] [ebp-2Ch]
  unsigned int curPrice; // [esp+60h] [ebp-28h]
  unsigned int startLen; // [esp+64h] [ebp-24h]
  unsigned int offs; // [esp+68h] [ebp-20h]
  unsigned int state; // [esp+6Ch] [ebp-1Ch] OVERLAPPED
  bool nextIsChar; // [esp+73h] [ebp-15h]
  unsigned int lenEnd; // [esp+74h] [ebp-14h]
  unsigned int cur; // [esp+78h] [ebp-10h]
  unsigned int posSlot; // [esp+7Ch] [ebp-Ch] BYREF
  unsigned int repIndex; // [esp+80h] [ebp-8h]
  unsigned int curBack; // [esp+84h] [ebp-4h]

  optimumCurrentIndex = this->_optimumCurrentIndex;
  if ( this->_optimumEndIndex != optimumCurrentIndex )
  {
    v7 = 5 * optimumCurrentIndex + 5;
    v8 = *((_DWORD *)&this->_state.Index + 2 * v7);
    v9 = (char *)this + 8 * v7;
    *lenRes = v8 - optimumCurrentIndex;
    *backRes = *((_DWORD *)v9 + 5);
    this->_optimumCurrentIndex = *((_DWORD *)v9 + 4);
    return 0;
  }
  v11 = !this->_longestMatchWasFound;
  this->_optimumEndIndex = 0;
  this->_optimumCurrentIndex = 0;
  if ( v11 )
  {
    result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &posSlot, &numDistancePairs);
    if ( result != 0 )
      return result;
  }
  else
  {
    v12 = this->_numDistancePairs;
    posSlot = this->_longestMatchLength;
    numDistancePairs = v12;
    this->_longestMatchWasFound = false;
  }
  v13 = this->_matchFinder._p->GetPointerToCurrentPos(this: this->_matchFinder._p) - 1;
  v14 = this->_matchFinder._p->GetNumAvailableBytes(this: this->_matchFinder._p) + 1;
  curBack = v14;
  if ( v14 < 2 )
  {
LABEL_8:
    *backRes = -1;
    *lenRes = 1;
    return 0;
  }
  if ( v14 > 0x111 )
    curBack = 273;
  v15 = 0;
  offs = 0;
  repIndex = 0;
  curPrice = 0;
  do
  {
    v16 = v15;
    v17 = this->_repDistances[v15];
    reps[v15] = v17;
    v18 = &v13[-v17 - 1];
    if ( *v13 == *v18 && v13[1] == v13[-v17] )
    {
      for ( i = 2; i < curBack; ++i )
      {
        if ( v13[i] != v18[i] )
          break;
      }
      v20 = curPrice;
      repLens[v16] = i;
      v21 = i <= *(unsigned int *)((char *)repLens + v20);
      v15 = repIndex;
      if ( !v21 )
      {
        offs = repIndex;
        curPrice = v16 * 4;
      }
    }
    else
    {
      repLens[v15] = 0;
    }
    repIndex = ++v15;
  }
  while ( v15 < 4 );
  v22 = repLens[offs];
  numFastBytes = this->_numFastBytes;
  normalMatchPrice = v22;
  if ( v22 >= numFastBytes )
  {
    *backRes = offs;
    *lenRes = v22;
    if ( v22 != 1 )
    {
      this->_additionalOffset += v22 - 1;
      return this->_matchFinder._p->Skip(this: this->_matchFinder._p, a2: v22 - 1);
    }
    return 0;
  }
  v24 = posSlot;
  if ( posSlot >= numFastBytes )
  {
    *backRes = this->_matchDistances[numDistancePairs] + 4;
    *lenRes = v24;
    v25 = v24 - 1;
    if ( v25 != 0 )
    {
      this->_additionalOffset += v25;
      return this->_matchFinder._p->Skip(this: this->_matchFinder._p, a2: v25);
    }
    return 0;
  }
  v26 = *v13;
  LOBYTE(curPrice) = *v13;
  v27 = v13[-reps[0] - 1];
  LOBYTE(posState) = v27;
  if ( posSlot < 2 && v26 != v27 && v22 < 2 )
    goto LABEL_8;
  Index = this->_state.Index;
  posStateMask = this->_posStateMask;
  v30 = curPrice;
  this->_optimum[0].State.Index = Index;
  numPrevBits = this->_literalEncoder._numPrevBits;
  v167 = v30;
  v32 = position & posStateMask;
  v33 = this->_previousByte >> (8 - numPrevBits);
  repMatchPrice = position & this->_literalEncoder._posMask;
  this->_optimum[1].Price = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[this->_state.Index][v32].Prob >> 2]
                          + NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                              this: &this->_literalEncoder._coders[(repMatchPrice << numPrevBits) + v33],
                              matchMode: Index >= 7u,
                              matchByte: posState,
                              symbol: v167);
  this->_optimum[1].BackPrev = -1;
  this->_optimum[1].Prev1IsChar = false;
  v34 = this->_state.Index;
  v35 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[v34][v32].Prob) >> 2]
      + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v34].Prob) >> 2];
  startLen = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[v34][v32].Prob) >> 2];
  repMatchPrice = v35;
  if ( (_BYTE)posState == (_BYTE)curPrice )
  {
    v36 = v35
        + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[v34].Prob >> 2]
        + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep0Long[v34][v32].Prob >> 2];
    if ( v36 < this->_optimum[1].Price )
    {
      this->_optimum[1].Price = v36;
      this->_optimum[1].BackPrev = 0;
      this->_optimum[1].Prev1IsChar = false;
    }
  }
  v37 = normalMatchPrice;
  if ( posSlot < normalMatchPrice )
  {
    lenEnd = normalMatchPrice;
  }
  else
  {
    v37 = posSlot;
    lenEnd = posSlot;
  }
  if ( v37 < 2 )
  {
    *backRes = this->_optimum[1].BackPrev;
    *lenRes = 1;
    return 0;
  }
  v38 = reps[0];
  this->_optimum[1].PosPrev = 0;
  this->_optimum[0].Backs[0] = v38;
  this->_optimum[0].Backs[1] = reps[1];
  this->_optimum[0].Backs[2] = reps[2];
  this->_optimum[0].Backs[3] = reps[3];
  p_Price = &this->_optimum[v37].Price;
  do
  {
    *p_Price = 0xFFFFFFF;
    --v37;
    p_Price -= 10;
  }
  while ( v37 >= 2 );
  for ( repIndex = 0; repIndex < 4; ++repIndex )
  {
    v40 = repLens[repIndex];
    if ( v40 >= 2 )
    {
      PureRepPrice = NCompress::NLZMA::CEncoder::GetPureRepPrice(this, repIndex, state: this->_state, posState: v32);
      v42 = repMatchPrice + PureRepPrice;
      curBack = (unsigned int)&this->_repMatchLenEncoder._highCoder.Models[272 * v32 + 254 + v40];
      v43 = &this->_optimum[v40].Price;
      do
      {
        v44 = v42 + *(_DWORD *)curBack;
        if ( v44 < *v43 )
        {
          *v43 = v44;
          v45 = repIndex;
          v43[1] = 0;
          v43[2] = v45;
          *((_BYTE *)v43 - 11) = 0;
        }
        curBack -= 4;
        --v40;
        v43 -= 10;
      }
      while ( v40 >= 2 );
    }
  }
  repMatchPrice = startLen
                + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep[this->_state.Index].Prob >> 2];
  if ( repLens[0] < 2 )
    v46 = 2;
  else
    v46 = repLens[0] + 1;
  state = v46;
  if ( v46 <= posSlot )
  {
    v47 = 0;
    posSlot = 0;
    if ( state > this->_matchDistances[1] )
    {
      do
        v47 += 2;
      while ( state > this->_matchDistances[v47 + 1] );
      posSlot = v47;
    }
    for ( j = &this->_optimum[state].Price; ; j += 10 )
    {
      normalMatchPrice = this->_matchDistances[posSlot + 2];
      PosLenPrice = NCompress::NLZMA::CEncoder::GetPosLenPrice(this, pos: normalMatchPrice, len: state, posState: v32);
      v50 = repMatchPrice + PosLenPrice;
      if ( v50 < *j )
      {
        v51 = normalMatchPrice + 4;
        *j = v50;
        j[1] = 0;
        j[2] = v51;
        *((_BYTE *)j - 11) = 0;
      }
      if ( state == this->_matchDistances[posSlot + 1] )
      {
        posSlot += 2;
        if ( posSlot == numDistancePairs )
          break;
      }
      ++state;
    }
  }
  cur = 1;
  if ( lenEnd == 1 )
  {
LABEL_193:
    *lenRes = NCompress::NLZMA::CEncoder::Backward(this, backRes, cur);
    return 0;
  }
  while ( 1 )
  {
    p = this->_matchFinder._p;
    GetMatches = p->GetMatches;
    v53 = 0;
    newLen = 0;
    result = GetMatches(this: p, a2: this->_matchDistances);
    if ( result != 0 )
      return result;
    v54 = this->_matchDistances[0];
    repMatchPrice = v54;
    if ( v54 != 0 )
    {
      v53 = *(&this->_literalEncoder._posMask + v54);
      newLen = v53;
      if ( v53 == this->_numFastBytes )
      {
        v53 += this->_matchFinder._p->GetMatchLen(
                 this: this->_matchFinder._p,
                 a2: v53 - 1,
                 a3: this->_matchDistances[v54],
                 a4: 273 - v53);
        newLen = v53;
      }
    }
    ++this->_additionalOffset;
    if ( v53 >= this->_numFastBytes )
    {
      this->_numDistancePairs = v54;
      this->_longestMatchLength = v53;
      this->_longestMatchWasFound = true;
      goto LABEL_193;
    }
    ++position;
    v55 = 5 * cur + 5;
    v56 = *((_DWORD *)&this->_state.Index + 2 * v55);
    v57 = (char *)this + 8 * v55;
    v58 = v57[1];
    if ( v58 != 0 )
    {
      --v56;
      if ( v57[2] != 0 )
      {
        v59 = this->_optimum[*((_DWORD *)v57 + 1)].State.Index;
        if ( *((_DWORD *)v57 + 2) >= 4u )
          v60 = kMatchNextStates_0[v59];
        else
          v60 = kRepNextStates_0[v59];
        v61 = kLiteralNextStates_0[v60];
      }
      else
      {
        v61 = kLiteralNextStates_0[this->_optimum[v56].State.Index];
      }
    }
    else
    {
      v61 = this->_optimum[v56].State.Index;
    }
    if ( v56 == cur - 1 )
    {
      if ( *((_DWORD *)v57 + 5) != 0 )
        LOBYTE(state) = kLiteralNextStates_0[v61];
      else
        LOBYTE(state) = kShortRepNextStates_0[v61];
    }
    else
    {
      if ( v58 != 0 && v57[2] != 0 )
      {
        v62 = *((_DWORD *)v57 + 2);
        v56 = *((_DWORD *)v57 + 1);
        v63 = kRepNextStates_0[v61];
        posSlot = v62;
      }
      else
      {
        posSlot = *((_DWORD *)v57 + 5);
        v62 = posSlot;
        if ( posSlot >= 4 )
          v63 = kMatchNextStates_0[v61];
        else
          v63 = kRepNextStates_0[v61];
      }
      LOBYTE(state) = v63;
      v64 = &this->_optimum[v56];
      if ( v62 >= 4 )
      {
        reps[1] = v64->Backs[0];
        v66 = v64->Backs[1];
        v67 = v64->Backs[2];
        reps[0] = v62 - 4;
        reps[2] = v66;
        reps[3] = v67;
      }
      else
      {
        v65 = 1;
        reps[0] = v64->Backs[v62];
        if ( v62 == 0 || (qmemcpy(&reps[1], v64->Backs, 4 * v62), v65 = posSlot + 1, posSlot + 1 < 4) )
          qmemcpy(&reps[v65], &v64->Backs[v65], 4 * (4 - v65));
      }
    }
    v68 = reps[1];
    v69 = reps[0];
    *v57 = state;
    v70 = reps[2];
    *((_DWORD *)v57 + 7) = v68;
    *((_DWORD *)v57 + 9) = reps[3];
    *((_DWORD *)v57 + 6) = v69;
    *((_DWORD *)v57 + 8) = v70;
    curPrice = *((_DWORD *)v57 + 3);
    v71 = (const unsigned __int8 *)(((int (__stdcall *)(IMatchFinder *, IMatchFinder *))this->_matchFinder._p->GetPointerToCurrentPos)(
                                      a1: this->_matchFinder._p,
                                      a2)
                                  - 1);
    v72 = *v71;
    v73 = v71[-v69 - 1];
    v74 = position & this->_posStateMask;
    matchByte[0] = v73;
    numDistancePairs = (unsigned __int8)state;
    curBack = v74 + 16 * (unsigned __int8)state;
    LOBYTE(currentByte) = v72;
    v75 = this->_literalEncoder._numPrevBits;
    v168 = v73;
    v76 = *(v71 - 1);
    posState = v74;
    v77 = (position & this->_literalEncoder._posMask) << v75;
    data = v71;
    v78 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
            this: &this->_literalEncoder._coders[v77 + (v76 >> (8 - v75))],
            matchMode: (unsigned __int8)state >= 7u,
            matchByte: v168,
            symbol: currentByte);
    v79 = curPrice + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[0][curBack].Prob >> 2] + v78;
    v80 = &this->_optimum[cur + 1];
    nextIsChar = false;
    if ( v79 < v80->Price )
    {
      v81 = cur;
      v80->Price = v79;
      v80->PosPrev = v81;
      v80->BackPrev = -1;
      v80->Prev1IsChar = false;
      nextIsChar = true;
    }
    normalMatchPrice = curPrice
                     + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][curBack].Prob) >> 2];
    v172 = normalMatchPrice
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[numDistancePairs].Prob) >> 2];
    if ( matchByte[0] == (_BYTE)currentByte && (v80->PosPrev >= cur || v80->BackPrev != 0) )
    {
      v82 = v172
          + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[numDistancePairs].Prob >> 2]
          + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep0Long[0][curBack].Prob >> 2];
      if ( v82 <= v80->Price )
      {
        v80->Price = v82;
        v80->PosPrev = cur;
        v80->BackPrev = 0;
        v80->Prev1IsChar = false;
        nextIsChar = true;
      }
    }
    a2 = this->_matchFinder._p;
    v83 = ((int (*)(void))a2->GetNumAvailableBytes)() + 1;
    curPrice = v83;
    if ( 4095 - cur < v83 )
    {
      v83 = 4095 - cur;
      curPrice = 4095 - cur;
    }
    offs = v83;
    if ( v83 >= 2 )
    {
      v84 = this->_numFastBytes;
      if ( v83 > v84 )
        offs = this->_numFastBytes;
      if ( !nextIsChar && matchByte[0] != (_BYTE)currentByte )
      {
        v85 = v84 + 1;
        if ( v83 >= v85 )
        {
          v83 = v85;
          curBack = v85;
        }
        else
        {
          curBack = v83;
        }
        v86 = 1;
        if ( v83 > 1 )
        {
          do
          {
            if ( v71[v86] != v71[v86 - 1 - reps[0]] )
              break;
            ++v86;
          }
          while ( v86 < curBack );
        }
        curBack = v86 - 1;
        if ( v86 - 1 >= 2 )
        {
          v87 = kLiteralNextStates_0[numDistancePairs];
          v88 = this->_posStateMask & (position + 1);
          lenTest2 = v87;
          v89 = v88 + 16 * v87;
          v90 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v87].Prob) >> 2];
          v91 = 2048 - this->_isMatch[0][v89].Prob;
          v179 = v89;
          v92 = v79 + NCompress::NRangeCoder::CPriceTables::ProbPrices[v91 >> 2] + v90;
          v93 = curBack + cur + 1;
          v94 = lenEnd;
          if ( lenEnd < v93 )
          {
            startLen = (unsigned int)&this->_optimum[lenEnd].Price;
            v95 = v93 - lenEnd;
            lenEnd = curBack + cur + 1;
            v96 = &this->_optimum[v94].Price;
            do
            {
              v96 += 10;
              --v95;
              *v96 = 0xFFFFFFF;
            }
            while ( v95 != 0 );
            v89 = v179;
          }
          v97 = v92
              + this->_repMatchLenEncoder._highCoder.Models[272 * v88 + 254 + curBack].Prob
              + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[lenTest2].Prob >> 2]
              + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][v89].Prob) >> 2];
          v98 = &this->_optimum[v93];
          if ( v97 < v98->Price )
          {
            v98->Price = v97;
            v98->PosPrev = cur + 1;
            v98->BackPrev = 0;
            *(_WORD *)&v98->Prev1IsChar = 1;
          }
        }
      }
      repIndex = 0;
      v99 = 0;
      startLen = 2;
      do
      {
        v100 = reps[v99] + 1;
        v101 = &data[-v100];
        lenTest2 = v100;
        if ( *data == data[-v100] && data[1] == v101[1] )
        {
          for ( k = 2; k < offs; ++k )
          {
            if ( data[k] != v101[k] )
              break;
          }
          if ( lenEnd < k + cur )
          {
            v103 = k + cur - lenEnd;
            v104 = &this->_optimum[lenEnd].Price;
            lenEnd = k + cur;
            do
            {
              v104 += 10;
              --v103;
              *v104 = 0xFFFFFFF;
            }
            while ( v103 != 0 );
          }
          v105 = k;
          v106 = NCompress::NLZMA::CEncoder::GetPureRepPrice(this, repIndex, (NCompress::NLZMA::CState)state, posState);
          v107 = v172 + v106;
          v171 = 272 * posState;
          curBack = (unsigned int)&this->_repMatchLenEncoder._highCoder.Models[272 * posState + 254 + k];
          price = v107;
          v108 = &this->_optimum[k + cur].Price;
          do
          {
            v109 = v107 + *(_DWORD *)curBack;
            if ( v109 < *v108 )
            {
              *v108 = v109;
              v108[1] = cur;
              v108[2] = repIndex;
              *((_BYTE *)v108 - 11) = 0;
            }
            curBack -= 4;
            --k;
            v108 -= 10;
          }
          while ( k >= 2 );
          if ( repIndex == 0 )
            startLen = v105 + 1;
          v110 = v105 + 1;
          v111 = v105 + 1 + this->_numFastBytes;
          if ( curPrice < v111 )
            v111 = curPrice;
          if ( v110 < v111 )
          {
            v112 = &data[v110 - lenTest2];
            do
            {
              if ( data[v110] != *v112 )
                break;
              ++v110;
              ++v112;
            }
            while ( v110 < v111 );
          }
          v179 = -1 - v105 + v110;
          if ( v179 >= 2 )
          {
            v113 = this->_posStateMask;
            posSlot = kRepNextStates_0[numDistancePairs];
            curAndLenPrice = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[posSlot][(v105 + position) & v113].Prob >> 2];
            v114 = v113 & (v105 + position + 1);
            v115 = this->_literalEncoder._numPrevBits;
            posSlot = kLiteralNextStates_0[posSlot];
            v116 = this->_literalEncoder._posMask & (v105 + position);
            backOffset = v114;
            curBack = v114 + 16 * posSlot;
            v117 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                     this: &this->_literalEncoder._coders[(v116 << v115) + (data[v105 - 1] >> (8 - v115))],
                     matchMode: true,
                     matchByte: data[v105 - lenTest2],
                     symbol: data[v105]);
            v118 = price
                 + curAndLenPrice
                 + this->_repMatchLenEncoder._highCoder.Models[v105 + 254 + v171].Prob
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[posSlot].Prob) >> 2]
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][curBack].Prob) >> 2]
                 + v117;
            v119 = v105 + v179 + cur + 1;
            if ( lenEnd < v119 )
            {
              price = (unsigned int)&this->_optimum[lenEnd].Price;
              v120 = v119 - lenEnd;
              lenEnd = v105 + v179 + cur + 1;
              v121 = (_DWORD *)price;
              do
              {
                v121 += 10;
                --v120;
                *v121 = 0xFFFFFFF;
              }
              while ( v120 != 0 );
            }
            v122 = v118
                 + this->_repMatchLenEncoder._highCoder.Models[272 * backOffset + 254 + v179].Prob
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[posSlot].Prob >> 2]
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][curBack].Prob) >> 2];
            v123 = &this->_optimum[v119];
            if ( v122 < v123->Price )
            {
              v123->Price = v122;
              v124 = v105 + cur + 1;
              v123->PosPrev2 = cur;
              v125 = repIndex;
              v123->PosPrev = v124;
              v123->BackPrev = 0;
              *(_WORD *)&v123->Prev1IsChar = 257;
              v123->BackPrev2 = v125;
            }
          }
        }
        v99 = repIndex + 1;
        repIndex = v99;
      }
      while ( v99 < 4 );
      v126 = newLen;
      if ( newLen > offs )
      {
        v127 = 0;
        v126 = offs;
        if ( offs > this->_matchDistances[1] )
        {
          do
            v127 += 2;
          while ( offs > this->_matchDistances[v127 + 1] );
        }
        this->_matchDistances[v127 + 1] = offs;
        repMatchPrice = v127 + 2;
      }
      v128 = startLen;
      if ( v126 >= startLen )
      {
        normalMatchPrice += NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep[numDistancePairs].Prob >> 2];
        if ( lenEnd < v126 + cur )
        {
          v129 = v126 + cur - lenEnd;
          v130 = &this->_optimum[lenEnd].Price;
          lenEnd += v129;
          do
          {
            v130 += 10;
            --v129;
            *v130 = 0xFFFFFFF;
          }
          while ( v129 != 0 );
        }
        v131 = 0;
        offs = 0;
        if ( v128 > this->_matchDistances[1] )
        {
          do
            v131 += 2;
          while ( v128 > this->_matchDistances[v131 + 1] );
          offs = v131;
        }
        v132 = v131;
        v133 = this->_matchDistances[v132 + 2];
        startLen = v132 * 4;
        curBack = v133;
        if ( v133 >= 0x20000 )
        {
          if ( v133 >= 0x8000000 )
            v134 = NCompress::NLZMA::g_FastPos[v133 >> 26] + 52;
          else
            v134 = NCompress::NLZMA::g_FastPos[HIWORD(v133)] + 32;
        }
        else
        {
          v134 = NCompress::NLZMA::g_FastPos[v133 >> 6] + 12;
        }
        repIndex = v128 + 1;
        posState = (unsigned int)&this->_lenEncoder._highCoder.Models[272 * posState + 254 + v128];
        v135 = &this->_optimum[v128 + cur].Price;
        posSlot = v134;
        for ( newLen = (unsigned int)v135; ; v135 = (unsigned int *)newLen )
        {
          v136 = repIndex;
          v137 = repIndex - 3;
          if ( repIndex - 3 >= 4 )
            v137 = 3;
          if ( v133 >= 0x80 )
            v138 = this->_alignPrices[v133 & 0xF] + this->_posSlotPrices[v137][v134];
          else
            v138 = this->_distancesPrices[v137][v133];
          v139 = *(_DWORD *)posState + normalMatchPrice + v138;
          curAndLenPrice = v139;
          if ( v139 < *v135 )
          {
            *v135 = v139;
            v135[1] = cur;
            v135[2] = v133 + 4;
            *((_BYTE *)v135 - 11) = 0;
          }
          if ( v136 - 1 == *(unsigned int *)((char *)&this->_matchDistances[1] + startLen) )
          {
            v140 = curPrice;
            v141 = repIndex + this->_numFastBytes;
            backOffset = curBack + 1;
            v142 = repIndex;
            if ( curPrice >= v141 )
              v140 = v141;
            if ( repIndex < v140 )
            {
              v143 = &data[repIndex - (curBack + 1)];
              do
              {
                if ( data[v142] != *v143 )
                  break;
                ++v142;
                ++v143;
              }
              while ( v142 < v140 );
            }
            lenTest2 = -1 - (repIndex - 1) + v142;
            if ( lenTest2 >= 2 )
            {
              v144 = this->_posStateMask;
              v145 = position + repIndex - 1;
              v146 = kMatchNextStates_0[numDistancePairs];
              v147 = kLiteralNextStates_0[v146];
              v148 = v145 & v144;
              Prob = this->_isMatch[v146][v145 & v144].Prob;
              v179 = v147;
              price = NCompress::NRangeCoder::CPriceTables::ProbPrices[Prob >> 2];
              v150 = this->_literalEncoder._posMask & v145;
              v151 = v144 & (v148 + 1);
              v152 = this->_literalEncoder._numPrevBits;
              startLen = v151 + 16 * v147;
              v153 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                       this: &this->_literalEncoder._coders[(v150 << v152) + (data[repIndex - 2] >> (8 - v152))],
                       matchMode: true,
                       matchByte: data[repIndex - backOffset - 1],
                       symbol: data[repIndex - 1]);
              v154 = curAndLenPrice
                   + price
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][startLen].Prob) >> 2]
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v179].Prob) >> 2]
                   + v153;
              v155 = lenTest2 + repIndex + cur;
              if ( lenEnd < v155 )
              {
                backOffset = (unsigned int)&this->_optimum[lenEnd].Price;
                v156 = v155 - lenEnd;
                lenEnd = lenTest2 + repIndex + cur;
                v157 = (_DWORD *)backOffset;
                do
                {
                  v157 += 10;
                  --v156;
                  *v157 = 0xFFFFFFF;
                }
                while ( v156 != 0 );
              }
              v158 = v154
                   + this->_repMatchLenEncoder._highCoder.Models[272 * v151 + 254 + lenTest2].Prob
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[v179].Prob >> 2]
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][startLen].Prob) >> 2];
              v159 = &this->_optimum[v155];
              if ( v158 < v159->Price )
              {
                v160 = repIndex;
                v159->Price = v158;
                v161 = cur + v160;
                v159->PosPrev2 = cur;
                v162 = curBack + 4;
                v159->PosPrev = v161;
                v159->BackPrev = 0;
                *(_WORD *)&v159->Prev1IsChar = 257;
                v159->BackPrev2 = v162;
              }
            }
            v163 = offs + 2;
            offs = v163;
            if ( v163 == repMatchPrice )
              break;
            startLen = 4 * v163;
            v164 = this->_matchDistances[v163 + 2];
            curBack = v164;
            if ( v164 >= 0x80 )
            {
              if ( v164 >= 0x20000 )
              {
                if ( v164 >= 0x8000000 )
                  v165 = NCompress::NLZMA::g_FastPos[v164 >> 26] + 52;
                else
                  v165 = NCompress::NLZMA::g_FastPos[HIWORD(v164)] + 32;
              }
              else
              {
                v165 = NCompress::NLZMA::g_FastPos[v164 >> 6] + 12;
              }
              posSlot = v165;
            }
          }
          newLen += 40;
          posState += 4;
          ++repIndex;
          v134 = posSlot;
          v133 = curBack;
        }
      }
    }
    if ( ++cur == lenEnd )
      goto LABEL_193;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CF00
// Name: private: void NCompress::NLZMA::CEncoder::WriteEndMarker(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::WriteEndMarker(NCompress::NLZMA::CEncoder *this, unsigned int posState)
{
  unsigned int Range; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v4; // edx
  int v5; // eax
  unsigned int v6; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v7; // eax
  unsigned int v8; // eax
  bool v10; // [esp+4h] [ebp-4h]

  if ( this->_writeEndMark )
  {
    Range = this->_rangeEncoder.Range;
    v4 = &this->_isMatch[this->_state.Index][posState];
    v5 = v4->Prob * (Range >> 11);
    this->_rangeEncoder.Low += (unsigned int)v5;
    this->_rangeEncoder.Range = Range - v5;
    v4->Prob -= v4->Prob >> 5;
    v6 = this->_rangeEncoder.Range;
    if ( v6 < 0x1000000 )
    {
      this->_rangeEncoder.Range = v6 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    v7 = &this->_isRep[this->_state.Index];
    this->_rangeEncoder.Range = v7->Prob * (this->_rangeEncoder.Range >> 11);
    v7->Prob += (2048 - v7->Prob) >> 5;
    v8 = this->_rangeEncoder.Range;
    if ( v8 < 0x1000000 )
    {
      this->_rangeEncoder.Range = v8 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    this->_state.Index = kMatchNextStates_0[this->_state.Index];
    v10 = !this->_fastMode;
    NCompress::NLZMA::NLength::CEncoder::Encode(
      this: &this->_lenEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0,
      posState);
    if ( v10 && this->_lenEncoder._counters[posState]-- == 1 )
    {
      NCompress::NLZMA::NLength::CEncoder::SetPrices(
        this: &this->_lenEncoder,
        posState,
        numSymbols: this->_lenEncoder._tableSize,
        prices: this->_lenEncoder._prices[posState]);
      this->_lenEncoder._counters[posState] = this->_lenEncoder._tableSize;
    }
    NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
      this: this->_posSlotEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0x3Fu);
    NCompress::NRangeCoder::CEncoder::EncodeDirectBits(this: &this->_rangeEncoder, value: 0x3FFFFFFu, numTotalBits: 26);
    NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
      this: &this->_posAlignEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0xFu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D050
// Name: public: NBT2::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT2::CMatchFinder *__thiscall NBT2::CMatchFinder::CMatchFinder(NBT2::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT2::CMatchFinder_vtbl *)&NBT2::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT2::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT2::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001D080
// Name: public: long NCompress::NLZMA::CEncoder::Create(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Create(NCompress::NLZMA::CEncoder *this)
{
  HRESULT result; // eax
  NBT2::CMatchFinder *v3; // eax
  NBT3::CMatchFinder *v4; // eax
  IMatchFinderSetNumPasses *v5; // ecx
  NBT3::CMatchFinder *v6; // eax
  NBT4::CMatchFinder *v7; // eax
  NHC4::CMatchFinder *v8; // eax
  unsigned int dictionarySize; // ecx
  IMatchFinderSetNumPasses *setMfPasses; // ecx
  unsigned int numFastBytes; // edx

  if ( !COutBuffer::Create(this: &this->_rangeEncoder.Stream, bufferSize: 0x100000u) )
    return -2147024882;
  if ( this->_matchFinder._p == nullptr )
  {
    switch ( this->_matchFinderIndex )
    {
      case 0:
        v3 = (NBT2::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v3 == nullptr )
          goto LABEL_15;
        v4 = (NBT3::CMatchFinder *)NBT2::CMatchFinder::CMatchFinder(this: v3);
        goto LABEL_7;
      case 1:
        v6 = (NBT3::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v6 == nullptr )
          goto LABEL_15;
        v4 = NBT3::CMatchFinder::CMatchFinder(this: v6);
        goto LABEL_7;
      case 2:
        v7 = (NBT4::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v7 == nullptr )
          goto LABEL_15;
        v4 = (NBT3::CMatchFinder *)NBT4::CMatchFinder::CMatchFinder(this: v7);
        goto LABEL_7;
      case 3:
        v8 = (NHC4::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v8 != nullptr )
        {
          v4 = (NBT3::CMatchFinder *)NHC4::CMatchFinder::CMatchFinder(this: v8);
LABEL_7:
          if ( v4 != nullptr )
          {
            v5 = &v4->IMatchFinderSetNumPasses;
            goto LABEL_17;
          }
        }
        else
        {
LABEL_15:
          v4 = nullptr;
        }
        v5 = nullptr;
LABEL_17:
        this->setMfPasses = v5;
        CMyComPtr<IMatchFinder>::operator=(this: &this->_matchFinder, p: v4);
LABEL_18:
        if ( this->_matchFinder._p != nullptr )
          break;
        return -2147024882;
      default:
        goto LABEL_18;
    }
  }
  if ( !NCompress::NLZMA::CLiteralEncoder::Create(
          this: &this->_literalEncoder,
          numPosBits: this->_numLiteralPosStateBits,
          numPrevBits: this->_numLiteralContextBits) )
    return -2147024882;
  dictionarySize = this->_dictionarySize;
  if ( dictionarySize != this->_dictionarySizePrev || this->_numFastBytesPrev != this->_numFastBytes )
  {
    result = this->_matchFinder._p->Create(
               this: this->_matchFinder._p,
               a2: dictionarySize,
               a3: 4096u,
               a4: this->_numFastBytes,
               a5: 274u);
    if ( result != 0 )
      return result;
    if ( this->_matchFinderCycles != 0 )
    {
      setMfPasses = this->setMfPasses;
      if ( setMfPasses != nullptr )
        setMfPasses->SetNumPasses(this: setMfPasses, a2: this->_matchFinderCycles);
    }
    numFastBytes = this->_numFastBytes;
    this->_dictionarySizePrev = this->_dictionarySize;
    this->_numFastBytesPrev = numFastBytes;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001D200
// Name: private: long NCompress::NLZMA::CEncoder::Flush(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Flush(NCompress::NLZMA::CEncoder *this, unsigned int nowPos)
{
  IMatchFinder *p; // eax

  p = this->_matchFinder._p;
  if ( p != nullptr && this->_needReleaseMFStream )
  {
    p->ReleaseStream(this: p);
    this->_needReleaseMFStream = false;
  }
  NCompress::NLZMA::CEncoder::WriteEndMarker(this, posState: nowPos & this->_posStateMask);
  NCompress::NRangeCoder::CEncoder::FlushData(this: &this->_rangeEncoder);
  return COutBuffer::Flush(this: &this->_rangeEncoder.Stream);
}

//------------------------------------------------------------------------------
// Address: 0x1001D260
// Name: public: long NCompress::NLZMA::CEncoder::SetStreams(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::SetStreams(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize)
{
  HRESULT result; // eax
  unsigned int v7; // edx

  this->_inStream = inStream;
  this->_finished = false;
  result = NCompress::NLZMA::CEncoder::Create(this);
  if ( result == 0 )
  {
    result = this->SetOutStream(this: &this->ICompressSetOutStream, a2: outStream);
    if ( result == 0 )
    {
      result = NCompress::NLZMA::CEncoder::Init(this);
      if ( result == 0 )
      {
        if ( !this->_fastMode )
        {
          NCompress::NLZMA::CEncoder::FillDistancesPrices(this);
          NCompress::NLZMA::CEncoder::FillAlignPrices(this);
        }
        this->_lenEncoder._tableSize = this->_numFastBytes - 1;
        NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(
          this: &this->_lenEncoder,
          numPosStates: 1 << this->_posStateBits);
        v7 = 1 << this->_posStateBits;
        this->_repMatchLenEncoder._tableSize = this->_numFastBytes - 1;
        NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(this: &this->_repMatchLenEncoder, numPosStates: v7);
        LODWORD(this->nowPos64) = 0;
        HIDWORD(this->nowPos64) = 0;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D330
// Name: public: long NCompress::NLZMA::CEncoder::CodeOneBlock(unsigned __int64 __near *,unsigned __int64 __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::CodeOneBlock(
        NCompress::NLZMA::CEncoder *this,
        unsigned __int64 *inSize,
        unsigned __int64 *outSize,
        int *finished)
{
  ISequentialInStream *inStream; // ecx
  unsigned int result; // eax
  bool v7; // zf
  int v8; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v9; // eax
  unsigned int Range; // eax
  unsigned __int8 v11; // al
  unsigned __int8 previousByte; // dl
  unsigned __int8 v13; // bl
  NCompress::NLZMA::CLiteralEncoder2 *SubCoder; // eax
  bool v15; // cf
  unsigned int nowPos64; // edi
  unsigned int (__stdcall *GetNumAvailableBytes)(IInWindowStream *); // edx
  unsigned int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // eax
  unsigned __int8 v21; // al
  unsigned int v22; // edi
  unsigned int v23; // edx
  NCompress::NLZMA::CLiteralEncoder2 *v24; // edi
  unsigned __int8 v25; // dl
  unsigned int v26; // ebx
  NCompress::NRangeCoder::CBitEncoder<5> *v27; // edx
  unsigned int v28; // ecx
  int v29; // eax
  unsigned int v30; // eax
  int Index; // edx
  unsigned int v32; // ecx
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v36; // eax
  unsigned int v37; // eax
  int v38; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v39; // edx
  int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v43; // eax
  unsigned int v44; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v45; // edx
  int v46; // eax
  unsigned int v47; // eax
  unsigned int v48; // ebx
  unsigned int v49; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // edx
  unsigned int v53; // eax
  unsigned int v54; // eax
  unsigned int v55; // eax
  unsigned int v56; // ebx
  unsigned int v57; // eax
  int v58; // eax
  unsigned int v59; // edx
  unsigned int v60; // eax
  unsigned int v61; // ecx
  unsigned int v62; // edx
  unsigned int additionalOffset; // eax
  unsigned int v64; // edi
  int v65; // edx
  unsigned __int8 v66; // [esp-Ch] [ebp-34h]
  IMatchFinder *p; // [esp-Ch] [ebp-34h]
  unsigned int numDistancePairs; // [esp+4h] [ebp-24h] BYREF
  unsigned int posReduced; // [esp+8h] [ebp-20h] BYREF
  int matchByte; // [esp+Ch] [ebp-1Ch]
  int curByte; // [esp+10h] [ebp-18h]
  unsigned int nowPos32; // [esp+14h] [ebp-14h]
  unsigned int posState; // [esp+18h] [ebp-10h]
  unsigned int lenRes; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned int pos; // [esp+20h] [ebp-8h] BYREF
  bool v76; // [esp+24h] [ebp-4h]

  inStream = this->_inStream;
  if ( inStream != nullptr )
  {
    result = this->_matchFinder._p->SetStream(this: this->_matchFinder._p, a2: inStream);
    if ( result != 0 )
      return result;
    result = this->_matchFinder._p->Init(this: this->_matchFinder._p);
    if ( result != 0 )
      return result;
    this->_needReleaseMFStream = true;
    this->_inStream = nullptr;
  }
  *finished = 1;
  if ( this->_finished )
    return 0;
  v8 = HIDWORD(this->nowPos64) | LODWORD(this->nowPos64);
  v7 = this->nowPos64 == 0;
  this->_finished = true;
  if ( !v7 )
    goto LABEL_14;
  if ( ((int (__thiscall *)(int, IMatchFinder *))this->_matchFinder._p->GetNumAvailableBytes)(
         a1: v8,
         a2: this->_matchFinder._p) == 0 )
    return NCompress::NLZMA::CEncoder::Flush(this, nowPos: this->nowPos64);
  result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &posReduced, &numDistancePairs);
  if ( result == 0 )
  {
    v9 = &this->_isMatch[this->_state.Index][this->nowPos64 & this->_posStateMask];
    this->_rangeEncoder.Range = v9->Prob * (this->_rangeEncoder.Range >> 11);
    v9->Prob += (2048 - v9->Prob) >> 5;
    Range = this->_rangeEncoder.Range;
    if ( Range < 0x1000000 )
    {
      this->_rangeEncoder.Range = Range << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    this->_state.Index = kLiteralNextStates_0[this->_state.Index];
    v11 = this->_matchFinder._p->GetIndexByte(this: this->_matchFinder._p, a2: -this->_additionalOffset);
    previousByte = this->_previousByte;
    v13 = v11;
    LOBYTE(curByte) = v11;
    v66 = v11;
    SubCoder = NCompress::NLZMA::CLiteralEncoder::GetSubCoder(
                 this: &this->_literalEncoder,
                 pos: this->nowPos64,
                 prevByte: previousByte);
    NCompress::NLZMA::CLiteralEncoder2::Encode(this: SubCoder, rangeEncoder: &this->_rangeEncoder, symbol: v66);
    --this->_additionalOffset;
    v15 = __CFADD__(LODWORD(this->nowPos64)++, 1);
    this->_previousByte = v13;
    HIDWORD(this->nowPos64) += v15;
LABEL_14:
    nowPos64 = this->nowPos64;
    GetNumAvailableBytes = this->_matchFinder._p->GetNumAvailableBytes;
    p = this->_matchFinder._p;
    nowPos32 = nowPos64;
    numDistancePairs = nowPos64;
    if ( GetNumAvailableBytes(this: p) != 0 )
    {
      if ( this->_rangeEncoder.Stream.ErrorCode != 0 )
      {
        return this->_rangeEncoder.Stream.ErrorCode;
      }
      else
      {
        while ( 1 )
        {
          result = this->_fastMode
                 ? NCompress::NLZMA::CEncoder::GetOptimumFast(this, position: nowPos64, backRes: &pos, &lenRes)
                 : NCompress::NLZMA::CEncoder::GetOptimum(
                     this,
                     a2: (IMatchFinder *)this,
                     position: nowPos64,
                     backRes: &pos,
                     &lenRes);
          if ( result != 0 )
            break;
          v18 = nowPos64 & this->_posStateMask;
          posState = v18;
          if ( lenRes == 1 && pos == -1 )
          {
            v19 = v18 + 16 * this->_state.Index;
            this->_rangeEncoder.Range = this->_isMatch[0][v19].Prob * (this->_rangeEncoder.Range >> 11);
            this->_isMatch[0][v19].Prob += (2048 - this->_isMatch[0][v19].Prob) >> 5;
            v20 = this->_rangeEncoder.Range;
            if ( v20 < 0x1000000 )
            {
              this->_rangeEncoder.Range = v20 << 8;
              NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
            }
            v21 = this->_matchFinder._p->GetIndexByte(this: this->_matchFinder._p, a2: -this->_additionalOffset);
            v22 = this->_previousByte;
            v23 = nowPos32 & this->_literalEncoder._posMask;
            LOBYTE(curByte) = v21;
            v24 = &this->_literalEncoder._coders[(v23 << this->_literalEncoder._numPrevBits)
                                               + (v22 >> (8 - this->_literalEncoder._numPrevBits))];
            if ( this->_state.Index >= 7u )
            {
              LOBYTE(matchByte) = this->_matchFinder._p->GetIndexByte(
                                    this: this->_matchFinder._p,
                                    a2: -1 - this->_repDistances[0] - this->_additionalOffset);
              NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(
                this: v24,
                rangeEncoder: &this->_rangeEncoder,
                matchByte,
                symbol: curByte);
            }
            else
            {
              NCompress::NLZMA::CLiteralEncoder2::Encode(this: v24, rangeEncoder: &this->_rangeEncoder, symbol: curByte);
            }
            v25 = curByte;
            v26 = lenRes;
            this->_state.Index = kLiteralNextStates_0[this->_state.Index];
            this->_previousByte = v25;
          }
          else
          {
            v27 = &this->_isMatch[this->_state.Index][v18];
            v28 = this->_rangeEncoder.Range;
            v29 = v27->Prob * (v28 >> 11);
            v15 = __CFADD__(v29, this->_rangeEncoder.Low);
            LODWORD(this->_rangeEncoder.Low) += v29;
            HIDWORD(this->_rangeEncoder.Low) += v15;
            this->_rangeEncoder.Range = v28 - v29;
            v27->Prob -= v27->Prob >> 5;
            v30 = this->_rangeEncoder.Range;
            if ( v30 < 0x1000000 )
            {
              this->_rangeEncoder.Range = v30 << 8;
              NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
            }
            if ( pos >= 4 )
            {
              v50 = &this->_isRep[this->_state.Index];
              this->_rangeEncoder.Range = v50->Prob * (this->_rangeEncoder.Range >> 11);
              v50->Prob += (2048 - v50->Prob) >> 5;
              v51 = this->_rangeEncoder.Range;
              if ( v51 < 0x1000000 )
              {
                this->_rangeEncoder.Range = v51 << 8;
                NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
              }
              v52 = posState;
              v53 = lenRes;
              this->_state.Index = kMatchNextStates_0[this->_state.Index];
              v76 = !this->_fastMode;
              NCompress::NLZMA::NLength::CEncoder::Encode(
                this: &this->_lenEncoder,
                rangeEncoder: &this->_rangeEncoder,
                symbol: v53 - 2,
                posState: v52);
              if ( v76 )
              {
                v54 = posState;
                v7 = this->_lenEncoder._counters[posState]-- == 1;
                if ( v7 )
                {
                  NCompress::NLZMA::NLength::CEncoder::SetPrices(
                    this: &this->_lenEncoder,
                    posState: v54,
                    numSymbols: this->_lenEncoder._tableSize,
                    prices: this->_lenEncoder._prices[v54]);
                  this->_lenEncoder._counters[posState] = this->_lenEncoder._tableSize;
                }
              }
              v55 = pos - 4;
              pos = v55;
              if ( v55 >= 0x800 )
              {
                if ( v55 >= 0x200000 )
                  v56 = NCompress::NLZMA::g_FastPos[v55 >> 20] + 40;
                else
                  v56 = NCompress::NLZMA::g_FastPos[v55 >> 10] + 20;
              }
              else
              {
                v56 = NCompress::NLZMA::g_FastPos[v55];
              }
              v57 = lenRes - 2;
              if ( lenRes - 2 >= 4 )
                v57 = 3;
              NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
                this: &this->_posSlotEncoder[v57],
                rangeEncoder: &this->_rangeEncoder,
                symbol: v56);
              if ( v56 >= 4 )
              {
                v58 = (v56 & 1 | 2) << ((v56 >> 1) - 1);
                posReduced = pos - v58;
                if ( v56 >= 0xE )
                {
                  NCompress::NRangeCoder::CEncoder::EncodeDirectBits(
                    this: &this->_rangeEncoder,
                    value: (pos - v58) >> 4,
                    numTotalBits: (v56 >> 1) - 5);
                  NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
                    this: &this->_posAlignEncoder,
                    rangeEncoder: &this->_rangeEncoder,
                    symbol: posReduced & 0xF);
                  ++this->_alignPriceCount;
                }
                else
                {
                  NCompress::NRangeCoder::ReverseBitTreeEncode<5>(
                    Models: &this->_posSlotEncoder[3].Models[v58 - v56 + 63],
                    rangeEncoder: &this->_rangeEncoder,
                    NumBitLevels: (v56 >> 1) - 1,
                    symbol: pos - v58);
                }
              }
              v59 = this->_repDistances[2];
              v60 = this->_repDistances[1];
              v61 = this->_repDistances[0];
              ++this->_matchPriceCount;
              v26 = lenRes;
              this->_repDistances[3] = v59;
              v62 = pos;
              this->_repDistances[2] = v60;
              this->_repDistances[1] = v61;
              this->_repDistances[0] = v62;
            }
            else
            {
              Index = this->_state.Index;
              v32 = this->_rangeEncoder.Range;
              v33 = this->_isRep[Index].Prob * (v32 >> 11);
              v15 = __CFADD__(v33, this->_rangeEncoder.Low);
              LODWORD(this->_rangeEncoder.Low) += v33;
              HIDWORD(this->_rangeEncoder.Low) += v15;
              this->_rangeEncoder.Range = v32 - v33;
              this->_isRep[Index].Prob -= this->_isRep[Index].Prob >> 5;
              v34 = this->_rangeEncoder.Range;
              if ( v34 < 0x1000000 )
              {
                this->_rangeEncoder.Range = v34 << 8;
                NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
              }
              v35 = this->_rangeEncoder.Range;
              if ( pos != 0 )
              {
                v38 = this->_state.Index;
                posReduced = this->_repDistances[pos];
                v39 = &this->_isRepG0[v38];
                v40 = v39->Prob * (v35 >> 11);
                this->_rangeEncoder.Low += (unsigned int)v40;
                this->_rangeEncoder.Range = v35 - v40;
                v39->Prob -= v39->Prob >> 5;
                v41 = this->_rangeEncoder.Range;
                if ( v41 < 0x1000000 )
                {
                  this->_rangeEncoder.Range = v41 << 8;
                  NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                }
                v42 = this->_rangeEncoder.Range;
                if ( pos == 1 )
                {
                  v43 = &this->_isRepG1[this->_state.Index];
                  this->_rangeEncoder.Range = v43->Prob * (v42 >> 11);
                  v43->Prob += (2048 - v43->Prob) >> 5;
                  v44 = this->_rangeEncoder.Range;
                  if ( v44 < 0x1000000 )
                  {
                    this->_rangeEncoder.Range = v44 << 8;
                    NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                  }
                }
                else
                {
                  v45 = &this->_isRepG1[this->_state.Index];
                  v46 = v45->Prob * (v42 >> 11);
                  this->_rangeEncoder.Low += (unsigned int)v46;
                  this->_rangeEncoder.Range = v42 - v46;
                  v45->Prob -= v45->Prob >> 5;
                  v47 = this->_rangeEncoder.Range;
                  if ( v47 < 0x1000000 )
                  {
                    this->_rangeEncoder.Range = v47 << 8;
                    NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                  }
                  v48 = pos;
                  NCompress::NRangeCoder::CBitEncoder<5>::Encode(
                    this: &this->_isRepG2[this->_state.Index],
                    encoder: &this->_rangeEncoder,
                    symbol: pos - 2);
                  if ( v48 == 3 )
                    this->_repDistances[3] = this->_repDistances[2];
                  this->_repDistances[2] = this->_repDistances[1];
                }
                v49 = posReduced;
                v26 = lenRes;
                this->_repDistances[1] = this->_repDistances[0];
                this->_repDistances[0] = v49;
              }
              else
              {
                v36 = &this->_isRepG0[this->_state.Index];
                this->_rangeEncoder.Range = v36->Prob * (v35 >> 11);
                v36->Prob += (2048 - v36->Prob) >> 5;
                v37 = this->_rangeEncoder.Range;
                if ( v37 < 0x1000000 )
                {
                  this->_rangeEncoder.Range = v37 << 8;
                  NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                }
                v26 = lenRes;
                NCompress::NRangeCoder::CBitEncoder<5>::Encode(
                  this: &this->_isRep0Long[this->_state.Index][posState],
                  encoder: &this->_rangeEncoder,
                  symbol: lenRes != 1);
              }
              if ( v26 == 1 )
              {
                this->_state.Index = kShortRepNextStates_0[this->_state.Index];
              }
              else
              {
                NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(
                  this: &this->_repMatchLenEncoder,
                  rangeEncoder: &this->_rangeEncoder,
                  symbol: v26 - 2,
                  posState,
                  updatePrice: !this->_fastMode);
                this->_state.Index = kRepNextStates_0[this->_state.Index];
              }
            }
            this->_previousByte = this->_matchFinder._p->GetIndexByte(
                                    this: this->_matchFinder._p,
                                    a2: v26 - this->_additionalOffset - 1);
          }
          this->_additionalOffset -= v26;
          additionalOffset = this->_additionalOffset;
          nowPos64 = v26 + nowPos32;
          nowPos32 += v26;
          if ( additionalOffset == 0 )
          {
            if ( !this->_fastMode )
            {
              if ( this->_matchPriceCount >= 0x80 )
                NCompress::NLZMA::CEncoder::FillDistancesPrices(this);
              if ( this->_alignPriceCount >= 0x10 )
                NCompress::NLZMA::CEncoder::FillAlignPrices(this);
            }
            if ( this->_matchFinder._p->GetNumAvailableBytes(this: this->_matchFinder._p) == 0 )
              return NCompress::NLZMA::CEncoder::Flush(this, nowPos: nowPos64);
            if ( nowPos64 - numDistancePairs >= 0x4000 )
            {
              v64 = nowPos64 - numDistancePairs;
              v15 = __CFADD__(v64, this->nowPos64);
              LODWORD(this->nowPos64) += v64;
              v65 = this->nowPos64;
              HIDWORD(this->nowPos64) += v15;
              *(_DWORD *)inSize = v65;
              *((_DWORD *)inSize + 1) = HIDWORD(this->nowPos64);
              *outSize = NCompress::NRangeCoder::CEncoder::GetProcessedSize(this: &this->_rangeEncoder);
              this->_finished = false;
              *finished = 0;
              return 0;
            }
          }
          if ( this->_rangeEncoder.Stream.ErrorCode != 0 )
            return this->_rangeEncoder.Stream.ErrorCode;
          nowPos64 = nowPos32;
        }
      }
    }
    else
    {
      return NCompress::NLZMA::CEncoder::Flush(this, nowPos: nowPos64);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DB30
// Name: public: long NCompress::NLZMA::CEncoder::CodeReal(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *,struct ICompressProgressInfo __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::CodeReal(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize,
        ICompressProgressInfo *progress)
{
  HRESULT v7; // edi
  IMatchFinder *p; // eax
  unsigned int v10; // edi
  ICompressProgressInfo *v11; // ebx
  const unsigned __int64 *v12; // [esp-4h] [ebp-20h]
  unsigned __int64 processedInSize; // [esp+8h] [ebp-14h] BYREF
  unsigned __int64 processedOutSize; // [esp+10h] [ebp-Ch] BYREF
  NCompress::NLZMA::CEncoder::CCoderReleaser coderReleaser; // [esp+18h] [ebp-4h] BYREF

  v12 = outSize;
  this->_needReleaseMFStream = false;
  coderReleaser._coder = this;
  v7 = NCompress::NLZMA::CEncoder::SetStreams(this, inStream, outStream, inSize, outSize: v12);
  if ( v7 != 0 )
  {
    p = this->_matchFinder._p;
    if ( p != nullptr && this->_needReleaseMFStream )
    {
      p->ReleaseStream(this: this->_matchFinder._p);
      this->_needReleaseMFStream = false;
    }
    this->ReleaseOutStream(this: &this->ICompressSetOutStream);
    return v7;
  }
  else
  {
    v10 = NCompress::NLZMA::CEncoder::CodeOneBlock(
            this,
            inSize: &processedInSize,
            outSize: &processedOutSize,
            finished: (int *)&outSize);
    if ( v10 != 0 )
    {
LABEL_12:
      NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(this: &coderReleaser);
      return v10;
    }
    else
    {
      v11 = progress;
      while ( outSize == nullptr )
      {
        if ( v11 == nullptr || (v10 = v11->SetRatioInfo(this: v11, a2: &processedInSize, a3: &processedOutSize)) == 0 )
        {
          v10 = NCompress::NLZMA::CEncoder::CodeOneBlock(
                  this,
                  inSize: &processedInSize,
                  outSize: &processedOutSize,
                  finished: (int *)&outSize);
          if ( v10 == 0 )
            continue;
        }
        goto LABEL_12;
      }
      NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(this: &coderReleaser);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DC20
// Name: public: virtual long NCompress::NLZMA::CEncoder::Code(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *,struct ICompressProgressInfo __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::Code(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize,
        ICompressProgressInfo *progress)
{
  return NCompress::NLZMA::CEncoder::CodeReal(this, inStream, outStream, inSize, outSize, progress);
}

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004564C0
// Name: private: virtual void NBT2::CMatchFinder::ReleaseStream(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT2::CMatchFinder::ReleaseStream(CEmptyConVar *this, NBT2::CMatchFinder *nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004B6B70
// Name: public: void NCompress::NRangeCoder::CEncoder::ShiftLow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::ShiftLow(NCompress::NRangeCoder::CEncoder *this)
{
  unsigned int Low; // esi
  unsigned __int8 cache; // bl

  Low = this->Low;
  if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
  {
    cache = this->_cache;
    do
    {
      this->Stream._buffer[this->Stream._pos] = cache + HIDWORD(this->Low);
      if ( ++this->Stream._pos == this->Stream._limitPos )
        COutBuffer::FlushWithCheck(this: &this->Stream);
      cache = -1;
    }
    while ( this->_cacheSize-- != 1 );
    Low = this->Low;
    this->_cache = HIBYTE(Low);
  }
  ++this->_cacheSize;
  LODWORD(this->Low) = Low << 8;
  HIDWORD(this->Low) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B6BF0
// Name: public: void NCompress::NRangeCoder::CEncoder::EncodeDirectBits(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::EncodeDirectBits(
        NCompress::NRangeCoder::CEncoder *this,
        unsigned int value,
        int numTotalBits)
{
  bool v3; // sf
  int v4; // ebx
  unsigned int Range; // eax
  unsigned int Low; // edi
  unsigned __int8 cache; // bl
  int i; // [esp+14h] [ebp+Ch]

  v4 = numTotalBits - 1;
  v3 = numTotalBits - 1 < 0;
  i = numTotalBits - 1;
  if ( !v3 )
  {
    do
    {
      this->Range >>= 1;
      Range = this->Range;
      if ( ((value >> v4) & 1) != 0 )
        this->Low += Range;
      if ( Range < 0x1000000 )
      {
        Low = this->Low;
        this->Range = Range << 8;
        if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
        {
          cache = this->_cache;
          do
          {
            this->Stream._buffer[this->Stream._pos++] = cache + HIDWORD(this->Low);
            if ( this->Stream._pos == this->Stream._limitPos )
              COutBuffer::FlushWithCheck(this: &this->Stream);
            cache = -1;
          }
          while ( this->_cacheSize-- != 1 );
          Low = this->Low;
          v4 = i;
          this->_cache = HIBYTE(Low);
        }
        ++this->_cacheSize;
        LODWORD(this->Low) = Low << 8;
        HIDWORD(this->Low) = 0;
      }
      i = --v4;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6CB0
// Name: public: unsigned __int64 NCompress::NRangeCoder::CEncoder::GetProcessedSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall NCompress::NRangeCoder::CEncoder::GetProcessedSize(NCompress::NRangeCoder::CEncoder *this)
{
  return this->_cacheSize + COutBuffer::GetProcessedSize(this: &this->Stream) + 4;
}

//------------------------------------------------------------------------------
// Address: 0x004B6CD0
// Name: public: bool NCompress::NLZMA::CLiteralEncoder::Create(int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NCompress::NLZMA::CLiteralEncoder::Create(
        NCompress::NLZMA::CLiteralEncoder *this,
        int numPosBits,
        int numPrevBits)
{
  bool v4; // zf

  if ( this->_coders == nullptr || numPosBits + numPrevBits != this->_numPrevBits + this->_numPosBits )
  {
    MyFree(address: this->_coders);
    this->_coders = nullptr;
    this->_coders = (NCompress::NLZMA::CLiteralEncoder2 *)MyAlloc(size: 3072 * (1 << (numPosBits + numPrevBits)));
  }
  this->_numPosBits = numPosBits;
  v4 = this->_coders == nullptr;
  this->_numPrevBits = numPrevBits;
  this->_posMask = (1 << numPosBits) - 1;
  return !v4;
}

//------------------------------------------------------------------------------
// Address: 0x004B6D40
// Name: public: class NCompress::NLZMA::CLiteralEncoder2 __near * NCompress::NLZMA::CLiteralEncoder::GetSubCoder(unsigned int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
NCompress::NLZMA::CLiteralEncoder2 *__thiscall NCompress::NLZMA::CLiteralEncoder::GetSubCoder(
        NCompress::NLZMA::CLiteralEncoder *this,
        unsigned int pos,
        unsigned __int8 prevByte)
{
  return &this->_coders[((pos & this->_posMask) << this->_numPrevBits) + (prevByte >> (8 - this->_numPrevBits))];
}

//------------------------------------------------------------------------------
// Address: 0x004B6D80
// Name: private: unsigned int NCompress::NLZMA::CEncoder::GetPosLenPrice(unsigned int,unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetPosLenPrice(
        NCompress::NLZMA::CEncoder *this,
        unsigned int pos,
        unsigned int len,
        unsigned int posState)
{
  int v4; // eax
  unsigned int v5; // esi
  int v6; // esi

  v4 = len - 2;
  if ( len - 2 >= 4 )
    v4 = 3;
  if ( pos >= 0x80 )
  {
    if ( pos >= 0x20000 )
    {
      if ( pos >= 0x8000000 )
        v6 = NCompress::NLZMA::g_FastPos[pos >> 26] + 52;
      else
        v6 = NCompress::NLZMA::g_FastPos[HIWORD(pos)] + 32;
    }
    else
    {
      v6 = NCompress::NLZMA::g_FastPos[pos >> 6] + 12;
    }
    v5 = this->_alignPrices[pos & 0xF] + this->_posSlotPrices[v4][v6];
  }
  else
  {
    v5 = this->_distancesPrices[v4][pos];
  }
  return v5 + this->_lenEncoder._highCoder.Models[272 * posState + 254 + len].Prob;
}

//------------------------------------------------------------------------------
// Address: 0x004B6E50
// Name: private: virtual long NBT2::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::Create(
        NBT2::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  int v8; // eax
  unsigned int *v9; // eax
  unsigned int *v10; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_9:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = 2 * v7 + 0x10000;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  this->_hashSizeSum = 0x10000;
  if ( (unsigned int)(4 * v8) >> 2 == v8 )
  {
    v9 = (unsigned int *)BigAlloc(size: 4 * v8);
    v10 = &v9[this->_hashSizeSum];
    this->_hash = v9;
    this->_son = v10;
    if ( v9 != nullptr )
      return 0;
    goto LABEL_9;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x004B6F50
// Name: private: virtual long NHC4::CMatchFinder::Init(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::Init(NHC4::CMatchFinder *this)
{
  unsigned int result; // eax

  result = CLZInWindow::Init(this: &this->CLZInWindow);
  if ( result == 0 )
  {
    if ( this->_hashSizeSum != 0 )
    {
      do
        this->_hash[result++] = 0;
      while ( result < this->_hashSizeSum );
    }
    this->_cyclicBufferPos = 0;
    --this->_buffer;
    ++this->_posLimit;
    ++this->_pos;
    ++this->_streamPos;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B6FA0
// Name: private: long NBT4::CMatchFinder::MovePos(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NBT4::CMatchFinder::MovePos(NBT4::CMatchFinder *this)
{
  unsigned int v2; // eax
  HRESULT result; // eax

  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v2 = ++this->_pos;
  if ( v2 <= this->_posLimit )
    goto LABEL_7;
  if ( &this->_buffer[v2] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_7:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B7000
// Name: private: virtual int NHC4::CMatchFinder::NeedChangeBufferPos(unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall NHC4::CMatchFinder::NeedChangeBufferPos(NHC4::CMatchFinder *this, unsigned int numCheckBytes)
{
  return numCheckBytes >= &this->_pointerToLastSafePosition[-this->_pos] - this->_buffer;
}

//------------------------------------------------------------------------------
// Address: 0x004B7020
// Name: private: virtual long NBT3::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::Create(
        NBT3::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int *v12; // eax
  unsigned int *v13; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = ((((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4)
     | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
     | ((historySize - 1) >> 1)
     | (historySize - 1);
  v9 = (v8 | ((v8 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v9 > 0x1000000 )
    v9 = 0xFFFFFF;
  this->_hashMask = v9;
  v10 = v9 + 1025;
  v11 = v10 + 2 * v7;
  this->_hashSizeSum = v10;
  if ( (4 * v11) >> 2 == v11 )
  {
    v12 = (unsigned int *)BigAlloc(size: 4 * v11);
    v13 = &v12[this->_hashSizeSum];
    this->_hash = v12;
    this->_son = v13;
    if ( v12 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x004B7160
// Name: private: void NBT4::CMatchFinder::Normalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT4::CMatchFinder::Normalize(NBT4::CMatchFinder *this)
{
  unsigned int cyclicBufferSize; // eax
  unsigned int v2; // esi
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int *i; // edi
  unsigned int v6; // edx
  unsigned int v7; // edx

  cyclicBufferSize = this->_cyclicBufferSize;
  v2 = this->_pos - cyclicBufferSize;
  v3 = this->_hashSizeSum + 2 * cyclicBufferSize;
  v4 = 0;
  for ( i = this->_hash; v4 < v3; ++v4 )
  {
    v6 = i[v4];
    if ( v6 > v2 )
      v7 = v6 - v2;
    else
      v7 = 0;
    i[v4] = v7;
  }
  this->_buffer += v2;
  this->_posLimit -= v2;
  this->_pos -= v2;
  this->_streamPos -= v2;
}

//------------------------------------------------------------------------------
// Address: 0x004B71B0
// Name: private: virtual unsigned char NBT2::CMatchFinder::GetIndexByte(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __stdcall NBT2::CMatchFinder::GetIndexByte(NHC4::CMatchFinder *this, int index)
{
  return this->_buffer[this->_pos + index];
}

//------------------------------------------------------------------------------
// Address: 0x004B71D0
// Name: private: virtual unsigned int NBT4::CMatchFinder::GetMatchLen(int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NBT4::CMatchFinder::GetMatchLen(
        NHC4::CMatchFinder *this,
        int index,
        unsigned int back,
        unsigned int limit)
{
  unsigned int v4; // esi
  unsigned int pos; // edi
  unsigned int streamPos; // ecx
  unsigned __int8 *v7; // ecx
  unsigned int result; // eax

  v4 = limit;
  if ( this->_streamEndWasReached )
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( limit + pos + index > streamPos )
      v4 = streamPos - pos - index;
  }
  for ( result = 0; result < v4; ++result )
  {
    v7 = &this->_buffer[this->_pos + index];
    if ( v7[result] != v7[result - 1 - back] )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B7230
// Name: private: virtual unsigned long NHC4::CMatchFinder::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::AddRef(NHC4::CMatchFinder *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B7250
// Name: private: virtual long NBT4::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::Create(
        NBT4::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int *v13; // eax
  unsigned int *v14; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = (((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4;
  v9 = v8 | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1);
  v10 = (v9 | ((v9 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v10 > 0x1000000 )
    v10 = (v9
         | ((v8
           | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
           | ((historySize - 1) >> 1)
           | (historySize - 1)
           | 0x1FFFE00) >> 8)) >> 2;
  this->_hashMask = v10;
  v11 = v10 + 66561;
  v12 = v11 + 2 * v7;
  this->_hashSizeSum = v11;
  if ( (4 * v12) >> 2 == v12 )
  {
    v13 = (unsigned int *)BigAlloc(size: 4 * v12);
    v14 = &v13[this->_hashSizeSum];
    this->_hash = v13;
    this->_son = v14;
    if ( v13 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x004B7390
// Name: private: virtual unsigned int NHC4::CMatchFinder::GetNumAvailableBytes(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::GetNumAvailableBytes(NHC4::CMatchFinder *this)
{
  return this->_streamPos - this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x004B73A0
// Name: private: virtual unsigned char const __near * NBT4::CMatchFinder::GetPointerToCurrentPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__stdcall NBT4::CMatchFinder::GetPointerToCurrentPos(NHC4::CMatchFinder *this)
{
  return &this->_buffer[this->_pos];
}

//------------------------------------------------------------------------------
// Address: 0x004B73B0
// Name: private: virtual long NHC4::CMatchFinder::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::QueryInterface(
        NHC4::CMatchFinder *this,
        NHC4::CMatchFinder *__formal,
        const _GUID *__formala)
{
  return -2147467262;
}

//------------------------------------------------------------------------------
// Address: 0x004B73C0
// Name: private: virtual unsigned long NHC4::CMatchFinder::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::Release(NHC4::CMatchFinder *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    ((void (__thiscall *)(CLZInWindow *, int))this->dtr_CLZInWindow)(a1: &this->CLZInWindow, a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B73E0
// Name: public: virtual void NBT3::CMatchFinder::SetNumPasses(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT3::CMatchFinder::SetNumPasses(NHC4::CMatchFinder *this, unsigned int numPasses)
{
  this->_blockSize = numPasses;
}

//------------------------------------------------------------------------------
// Address: 0x004B73F0
// Name: private: virtual long NHC4::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::Create(
        NHC4::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int *v14; // eax
  unsigned int *v15; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 2) + 8;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = (((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4;
  v9 = v8 | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1);
  v10 = (v9 | ((v9 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v10 > 0x1000000 )
    v10 = (v9
         | ((v8
           | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
           | ((historySize - 1) >> 1)
           | (historySize - 1)
           | 0x1FFFE00) >> 8)) >> 2;
  this->_hashMask = v10;
  v11 = v10 + 66561;
  v12 = v11 + v7;
  this->_hashSizeSum = v11;
  v13 = 4 * (v11 + v7);
  if ( v13 >> 2 == v12 )
  {
    v14 = (unsigned int *)BigAlloc(size: v13);
    v15 = &v14[this->_hashSizeSum];
    this->_hash = v14;
    this->_son = v15;
    if ( v14 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x004B7530
// Name: private: virtual long NBT4::CMatchFinder::SetStream(struct ISequentialInStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::SetStream(NHC4::CMatchFinder *this, ISequentialInStream *stream)
{
  CLZInWindow::SetStream(this: &this->CLZInWindow, stream);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B7550
// Name: private: void NHC4::CMatchFinder::Normalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NHC4::CMatchFinder::Normalize(NHC4::CMatchFinder *this)
{
  unsigned int cyclicBufferSize; // eax
  unsigned int *hash; // ebx
  unsigned int hashSizeSum; // edi
  unsigned int v4; // esi
  bool v5; // zf
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // edx

  cyclicBufferSize = this->_cyclicBufferSize;
  hash = this->_hash;
  hashSizeSum = this->_hashSizeSum;
  v4 = this->_pos - cyclicBufferSize;
  v5 = cyclicBufferSize + hashSizeSum == 0;
  v6 = cyclicBufferSize + hashSizeSum;
  v7 = 0;
  if ( !v5 )
  {
    do
    {
      v8 = hash[v7];
      if ( v8 > v4 )
        v9 = v8 - v4;
      else
        v9 = 0;
      hash[v7++] = v9;
    }
    while ( v7 < v6 );
  }
  this->_buffer += v4;
  this->_posLimit -= v4;
  this->_pos -= v4;
  this->_streamPos -= v4;
}

//------------------------------------------------------------------------------
// Address: 0x004B75A0
// Name: private: long NHC4::CMatchFinder::MovePos(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NHC4::CMatchFinder::MovePos(NHC4::CMatchFinder *this)
{
  unsigned int v2; // eax
  HRESULT result; // eax

  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v2 = ++this->_pos;
  if ( v2 <= this->_posLimit )
    goto LABEL_7;
  if ( &this->_buffer[v2] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_7:
    if ( this->_pos == 0x7FFFFFFF )
      NHC4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B7600
// Name: private: virtual void NBT2::CMatchFinder::ChangeBufferPos(void)
// Source: json
//------------------------------------------------------------------------------
void __stdcall NBT2::CMatchFinder::ChangeBufferPos(NHC4::CMatchFinder *this)
{
  CLZInWindow::MoveBlock(this: &this->CLZInWindow);
}

//------------------------------------------------------------------------------
// Address: 0x004B7620
// Name: public: void NCompress::NLZMA::CFastPosInit::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CFastPosInit::Init(NCompress::NLZMA::CFastPosInit *this)
{
  char v1; // bl
  unsigned int v2; // edi
  unsigned int v3; // esi
  unsigned __int8 slotFast; // [esp+Ch] [ebp-8h]
  int c; // [esp+10h] [ebp-4h]

  v1 = 2;
  c = 2;
  *(_WORD *)NCompress::NLZMA::g_FastPos = 256;
  slotFast = 2;
  v2 = 2;
  do
  {
    v3 = 1 << ((v2 >> 1) - 1);
    if ( v3 != 0 )
    {
      memset(dst: &NCompress::NLZMA::g_FastPos[c], value: slotFast, count: v3);
      c += v3;
    }
    ++v1;
    ++v2;
    slotFast = v1;
  }
  while ( (unsigned __int8)v1 < 0x16u );
}

//------------------------------------------------------------------------------
// Address: 0x004B7680
// Name: NCompress::NLZMA::FindMatchFinder
// Source: json
//------------------------------------------------------------------------------
int __usercall NCompress::NLZMA::FindMatchFinder@<eax>(const wchar_t *s@<edi>)
{
  int result; // eax
  const wchar_t *i; // edx
  wchar_t v3; // cx

  for ( result = 0; result < 4; ++result )
  {
    for ( i = s; ; ++i )
    {
      v3 = *i;
      if ( (unsigned __int16)(*i - 97) <= 0x19u )
        v3 -= 32;
      if ( *(const wchar_t *)((char *)i + (char *)kMatchFinderIDs[result] - (char *)s) != v3 )
        break;
      if ( v3 == 0 )
        return result;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B76C0
// Name: public: virtual long NCompress::NLZMA::CEncoder::WriteCoderProperties(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::WriteCoderProperties(
        NCompress::NLZMA::CEncoder *this,
        ISequentialOutStream *outStream)
{
  unsigned int posStateMask; // edx
  unsigned __int8 properties[8]; // [esp+0h] [ebp-8h] BYREF

  properties[0] = LOBYTE(this->_posStateBits) + 9 * (LOBYTE(this->_distTableSize) + 5 * LOBYTE(this->_alignPrices[15]));
  posStateMask = this->_posStateMask;
  *(_DWORD *)&properties[1] = posStateMask;
  return WriteStream(stream: outStream, data: properties, size: 5u, processedSize: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004B7730
// Name: public: virtual long NCompress::NLZMA::CEncoder::SetOutStream(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::SetOutStream(
        NCompress::NLZMA::CEncoder *this,
        ISequentialOutStream *outStream)
{
  COutBuffer::SetStream(this: (COutBuffer *)(&this->_rangeEncoder.Range + 1), stream: outStream);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B7750
// Name: private: unsigned int NCompress::NLZMA::CEncoder::Backward(unsigned int __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::Backward(
        NCompress::NLZMA::CEncoder *this,
        unsigned int *backRes,
        unsigned int cur)
{
  unsigned int v3; // esi
  char *v4; // eax
  unsigned int PosPrev; // edx
  char *v6; // edi
  char *v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned int result; // eax
  unsigned int backMem; // [esp+18h] [ebp+Ch]

  v3 = cur;
  v4 = (char *)this + 40 * cur;
  this->_optimumEndIndex = cur;
  PosPrev = *((_DWORD *)v4 + 14);
  backMem = *((_DWORD *)v4 + 15);
  do
  {
    v6 = (char *)this + 40 * v3;
    if ( v6[41] != 0 )
    {
      v7 = (char *)this + 40 * PosPrev;
      *((_DWORD *)v7 + 15) = -1;
      v7[41] = 0;
      *((_DWORD *)v7 + 14) = PosPrev - 1;
      if ( v6[42] != 0 )
      {
        v7[1] = 0;
        *((_DWORD *)v7 + 4) = *((_DWORD *)v6 + 11);
        *((_DWORD *)v7 + 5) = *((_DWORD *)v6 + 12);
      }
    }
    v8 = backMem;
    v9 = PosPrev;
    v10 = PosPrev;
    backMem = this->_optimum[PosPrev].BackPrev;
    PosPrev = this->_optimum[PosPrev].PosPrev;
    this->_optimum[v9].PosPrev = v3;
    this->_optimum[v9].BackPrev = v8;
    v3 = v10;
  }
  while ( v10 != 0 );
  *backRes = this->_optimum[0].BackPrev;
  result = this->_optimum[0].PosPrev;
  this->_optimumCurrentIndex = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B77F0
// Name: public: void NCompress::NRangeCoder::CBitEncoder<5>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitEncoder<5>::Encode(
        NCompress::NRangeCoder::CBitEncoder<5> *this,
        NCompress::NRangeCoder::CEncoder *encoder,
        unsigned int symbol)
{
  unsigned int Range; // esi
  unsigned int v4; // edx
  unsigned int v5; // ecx

  Range = encoder->Range;
  v4 = this->Prob * (Range >> 11);
  if ( symbol != 0 )
  {
    encoder->Low += v4;
    encoder->Range = Range - v4;
    this->Prob -= this->Prob >> 5;
  }
  else
  {
    encoder->Range = v4;
    this->Prob += (2048 - this->Prob) >> 5;
  }
  v5 = encoder->Range;
  if ( v5 < 0x1000000 )
  {
    encoder->Range = v5 << 8;
    NCompress::NRangeCoder::CEncoder::ShiftLow(this: encoder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7860
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,3> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,3> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 3;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x004B7900
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,8> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,8> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 8;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x004B79A0
// Name: public: struct IMatchFinder __near * CMyComPtr<struct IMatchFinder>::operator=(struct IMatchFinder __near *)
// Source: json
//------------------------------------------------------------------------------
IMatchFinder *__thiscall CMyComPtr<IMatchFinder>::operator=(CMyComPtr<IMatchFinder> *this, IMatchFinder *p)
{
  if ( p != nullptr )
    p->AddRef(this: p);
  if ( this->_p != nullptr )
    this->_p->Release(this: this->_p);
  this->_p = p;
  return p;
}

//------------------------------------------------------------------------------
// Address: 0x004B79D0
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,6> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,6> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 6;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x004B7A70
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,4> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,4> *v4; // edx
  int v5; // edi
  unsigned int Range; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  int rangeEncodera; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  for ( rangeEncodera = 4; rangeEncodera != 0; --rangeEncodera )
  {
    Range = rangeEncoder->Range;
    v7 = v4->Models[v5].Prob * (Range >> 11);
    v8 = symbol & 1;
    if ( (symbol & 1) != 0 )
    {
      rangeEncoder->Low += v7;
      rangeEncoder->Range = Range - v7;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v7;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v9 = rangeEncoder->Range;
    if ( v9 < 0x1000000 )
    {
      rangeEncoder->Range = v9 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    symbol >>= 1;
    v5 = v8 | (2 * v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7B10
// Name: void NCompress::NRangeCoder::ReverseBitTreeEncode<5>(class NCompress::NRangeCoder::CBitEncoder<5> __near *,class NCompress::NRangeCoder::CEncoder __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NCompress::NRangeCoder::ReverseBitTreeEncode<5>(
        NCompress::NRangeCoder::CBitEncoder<5> *Models,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        int NumBitLevels,
        unsigned int symbol)
{
  int v4; // edi
  unsigned int Range; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax

  v4 = 1;
  if ( NumBitLevels > 0 )
  {
    do
    {
      Range = rangeEncoder->Range;
      v6 = Models[v4].Prob * (Range >> 11);
      v7 = symbol & 1;
      if ( (symbol & 1) != 0 )
      {
        rangeEncoder->Low += v6;
        rangeEncoder->Range = Range - v6;
        Models[v4].Prob -= Models[v4].Prob >> 5;
      }
      else
      {
        rangeEncoder->Range = v6;
        Models[v4].Prob += (2048 - Models[v4].Prob) >> 5;
      }
      v8 = rangeEncoder->Range;
      if ( v8 < 0x1000000 )
      {
        rangeEncoder->Range = v8 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      symbol >>= 1;
      v4 = v7 | (2 * v4);
      --NumBitLevels;
    }
    while ( NumBitLevels != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7BA0
// Name: unsigned int NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(class NCompress::NRangeCoder::CBitEncoder<5> __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(
        NCompress::NRangeCoder::CBitEncoder<5> *Models,
        int NumBitLevels,
        unsigned int symbol)
{
  __int64 i; // rax
  unsigned int v5; // ecx

  for ( i = 0x100000000LL; NumBitLevels != 0; --NumBitLevels )
  {
    v5 = symbol & 1;
    LODWORD(i) = NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v5 ^ (Models[HIDWORD(i)].Prob - v5)) >> 2) & 0x1FF]
               + i;
    symbol >>= 1;
    HIDWORD(i) = v5 | (2 * HIDWORD(i));
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x004B7C30
// Name: public: void NCompress::NRangeCoder::CEncoder::FlushData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::FlushData(NCompress::NRangeCoder::CEncoder *this)
{
  unsigned int Low; // edi
  unsigned __int8 cache; // bl
  bool v4; // zf
  int v5; // [esp+Ch] [ebp-4h]

  v5 = 5;
  do
  {
    Low = this->Low;
    if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
    {
      cache = this->_cache;
      do
      {
        this->Stream._buffer[this->Stream._pos++] = cache + HIDWORD(this->Low);
        if ( this->Stream._pos == this->Stream._limitPos )
          COutBuffer::FlushWithCheck(this: &this->Stream);
        cache = -1;
        v4 = this->_cacheSize-- == 1;
      }
      while ( !v4 );
      Low = this->Low;
      this->_cache = HIBYTE(Low);
    }
    ++this->_cacheSize;
    v4 = v5-- == 1;
    LODWORD(this->Low) = Low << 8;
    HIDWORD(this->Low) = 0;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x004B7CC0
// Name: private: void NCompress::NLZMA::CEncoder::ReleaseMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::ReleaseMatchFinder(NCompress::NLZMA::CEncoder *this)
{
  IMatchFinder *p; // eax

  this->setMfPasses = nullptr;
  p = this->_matchFinder._p;
  if ( p != nullptr )
  {
    p->Release(this: p);
    this->_matchFinder._p = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7CF0
// Name: private: unsigned int NCompress::NLZMA::CEncoder::GetPureRepPrice(unsigned int,class NCompress::NLZMA::CState,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetPureRepPrice(
        NCompress::NLZMA::CEncoder *this,
        unsigned int repIndex,
        NCompress::NLZMA::CState state,
        unsigned int posState)
{
  unsigned int v5; // eax

  if ( repIndex == 0 )
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[state.Index].Prob >> 2]
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[state.Index][posState].Prob) >> 2];
  v5 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRepG0[state.Index].Prob) >> 2];
  if ( repIndex == 1 )
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG1[state.Index].Prob >> 2] + v5;
  else
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[(((2 - repIndex)
                                                            ^ (this->_isRepG2[state.Index].Prob - (repIndex - 2))) >> 2)
                                                          & 0x1FF]
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRepG1[state.Index].Prob) >> 2]
         + v5;
}

//------------------------------------------------------------------------------
// Address: 0x004B7DB0
// Name: public: NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(
        NCompress::NLZMA::CEncoder::CCoderReleaser *this)
{
  NCompress::NLZMA::CEncoder *coder; // esi
  IMatchFinder *p; // eax

  coder = this->_coder;
  p = this->_coder->_matchFinder._p;
  if ( p != nullptr && coder->_needReleaseMFStream )
  {
    p->ReleaseStream(this: p);
    coder->_needReleaseMFStream = false;
  }
  coder->ReleaseOutStream(this: &coder->ICompressSetOutStream);
}

//------------------------------------------------------------------------------
// Address: 0x004B7E50
// Name: private: virtual long NBT2::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::GetMatches(NBT2::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // edx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  unsigned int v6; // ebx
  HRESULT result; // eax
  unsigned __int8 *buffer; // edi
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned int *v11; // eax
  unsigned int v12; // ecx
  unsigned int cutValue; // eax
  unsigned int v14; // eax
  unsigned int cyclicBufferPos; // ebx
  unsigned int v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned __int8 *v19; // edx
  int v20; // edx
  unsigned __int8 *v21; // ebx
  unsigned int *v22; // ecx
  const unsigned __int8 *cur; // [esp+8h] [ebp-38h]
  unsigned int delta; // [esp+Ch] [ebp-34h]
  int i; // [esp+10h] [ebp-30h]
  unsigned int *son; // [esp+14h] [ebp-2Ch]
  unsigned int count; // [esp+18h] [ebp-28h]
  unsigned int matchMinPos; // [esp+1Ch] [ebp-24h]
  unsigned int len1; // [esp+20h] [ebp-20h]
  unsigned int *pair; // [esp+24h] [ebp-1Ch]
  unsigned int len0; // [esp+28h] [ebp-18h]
  const unsigned __int8 *pb; // [esp+2Ch] [ebp-14h]
  unsigned int maxLen; // [esp+30h] [ebp-10h]
  int offset; // [esp+34h] [ebp-Ch]
  unsigned int *ptr0; // [esp+38h] [ebp-8h]
  unsigned int *ptr1; // [esp+3Ch] [ebp-4h]
  unsigned int lenLimit; // [esp+48h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 3 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos((NBT4::CMatchFinder *)this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    v6 = 0;
  else
    v6 = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v9 = buffer[pos + 1];
  v10 = &buffer[pos];
  maxLen = 1;
  v11 = &this->_hash[*v10 ^ (v9 << 8)];
  v12 = *v11;
  *v11 = pos;
  son = this->_son;
  ptr1 = &son[2 * this->_cyclicBufferPos];
  matchMinPos = v6;
  cur = v10;
  ptr0 = ptr1 + 1;
  len1 = 2;
  len0 = 2;
  if ( v12 > v6 && this->_buffer[v12 + 2] != v10[2] )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - v12 - 1;
    offset = 3;
  }
  cutValue = this->_cutValue;
  if ( v12 > v6 )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v16 = this->_pos - v12;
      delta = v16;
      if ( v16 > cyclicBufferPos )
        v17 = cyclicBufferPos + this->_cyclicBufferSize - v16;
      else
        v17 = cyclicBufferPos - v16;
      v18 = len1;
      pair = &son[2 * v17];
      v19 = &this->_buffer[v12];
      pb = v19;
      if ( len0 < len1 )
        v18 = len0;
      if ( v19[v18] == v10[v18] )
      {
        if ( ++v18 != lenLimit )
        {
          v20 = v19 - v10;
          v21 = &v10[v18];
          for ( i = v20; v21[v20] == *v21; v20 = i )
          {
            ++v18;
            ++v21;
            if ( v18 == lenLimit )
              break;
          }
          v19 = &this->_buffer[v12];
        }
        if ( maxLen < v18 )
        {
          distances[offset] = v18;
          distances[offset + 1] = delta - 1;
          maxLen = v18;
          offset += 2;
          if ( v18 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0 = pair[1];
            goto LABEL_13;
          }
          v10 = (unsigned __int8 *)cur;
          v19 = (unsigned __int8 *)pb;
        }
      }
      if ( v19[v18] >= v10[v18] )
      {
        *ptr0 = v12;
        v22 = pair;
        ptr0 = pair;
        len0 = v18;
      }
      else
      {
        *ptr1 = v12;
        v22 = pair + 1;
        ptr1 = pair + 1;
        len1 = v18;
      }
      v12 = *v22;
      if ( v12 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  *ptr1 = 0;
  *ptr0 = 0;
LABEL_13:
  *distances = offset - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v14 = ++this->_pos;
  if ( v14 <= this->_posLimit )
    goto LABEL_19;
  if ( &this->_buffer[v14] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_19:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize((NBT4::CMatchFinder *)this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B8090
// Name: private: virtual long NBT2::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::Skip(NBT2::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // edi
  int v16; // eax
  int v17; // ecx
  unsigned __int8 *v18; // edi
  unsigned int *v19; // eax
  unsigned int v20; // ecx
  unsigned int *v21; // ebx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v24; // edx
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned __int8 *v27; // edx
  unsigned __int8 *v28; // edx
  unsigned __int8 *v29; // ebx
  unsigned int *v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // eax
  unsigned int *hash; // ebx
  unsigned int v34; // edx
  unsigned int v35; // eax
  unsigned int v36; // edx
  unsigned int v37; // edx
  unsigned int count; // [esp+Ch] [ebp-28h]
  unsigned int *son; // [esp+10h] [ebp-24h]
  unsigned __int8 *v40; // [esp+18h] [ebp-1Ch]
  unsigned int len0; // [esp+1Ch] [ebp-18h]
  unsigned int len1; // [esp+20h] [ebp-14h]
  unsigned int *pair; // [esp+24h] [ebp-10h]
  unsigned int matchMinPos; // [esp+28h] [ebp-Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-8h]
  unsigned int *ptr1; // [esp+30h] [ebp-4h]
  unsigned int lenLimit; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimita; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimitb; // [esp+3Ch] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = buffer[pos + 1];
      v17 = buffer[pos];
      v18 = &buffer[pos];
      v19 = &this->_hash[v17 ^ (v16 << 8)];
      v20 = *v19;
      *v19 = pos;
      v21 = this->_son;
      ptr1 = &v21[2 * this->_cyclicBufferPos];
      len1 = 2;
      len0 = 2;
      cutValue = this->_cutValue;
      son = v21;
      ptr0 = ptr1 + 1;
      if ( v20 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v24 = this->_pos - v20;
          if ( v24 > cyclicBufferPos )
            v25 = this->_cyclicBufferSize + cyclicBufferPos - v24;
          else
            v25 = cyclicBufferPos - v24;
          pair = &v21[2 * v25];
          v26 = len0;
          v27 = &this->_buffer[v20];
          if ( len0 >= len1 )
            v26 = len1;
          if ( v27[v26] == v18[v26] )
          {
            if ( ++v26 == lenLimit )
              goto LABEL_40;
            v28 = (unsigned __int8 *)(v27 - v18);
            v29 = &v18[v26];
            v40 = v28;
            while ( v29[(_DWORD)v28] == *v29 )
            {
              ++v26;
              ++v29;
              if ( v26 == lenLimit )
                goto LABEL_40;
              v28 = v40;
            }
            if ( v26 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v27 = &this->_buffer[v20];
          }
          if ( v27[v26] >= v18[v26] )
          {
            *ptr0 = v20;
            v30 = pair;
            ptr0 = pair;
            len0 = v26;
          }
          else
          {
            *ptr1 = v20;
            v30 = pair + 1;
            ptr1 = pair + 1;
            len1 = v26;
          }
          v20 = *v30;
          if ( v20 <= matchMinPos )
            break;
          v21 = son;
          cutValue = count;
        }
      }
      *ptr1 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v31 = ++this->_pos;
      if ( v31 > this->_posLimit )
      {
        if ( &this->_buffer[v31] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v32 = this->_cyclicBufferSize;
        hash = this->_hash;
        v34 = this->_hashSizeSum + 2 * v32;
        v11 = 0x7FFFFFFF - v32;
        v35 = 0;
        for ( lenLimitb = v34; v35 < lenLimitb; ++v35 )
        {
          v36 = hash[v35];
          if ( v36 > v11 )
            v37 = v36 - v11;
          else
            v37 = 0;
          hash[v35] = v37;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 3 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B8380
// Name: private: virtual long NBT3::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::GetMatches(NBT3::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int *hash; // ecx
  unsigned int v13; // eax
  int v14; // edx
  unsigned int v15; // edi
  unsigned int cyclicBufferPos; // ecx
  unsigned int v17; // ebx
  int v18; // edx
  unsigned int *v19; // ecx
  unsigned int cutValue; // eax
  unsigned int *v21; // edx
  int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // edx
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int *v27; // edx
  unsigned int v28; // eax
  unsigned __int8 *v29; // ecx
  const unsigned __int8 *v30; // edx
  int i; // ebx
  const unsigned __int8 *pb; // [esp+8h] [ebp-3Ch]
  unsigned int delta; // [esp+Ch] [ebp-38h]
  unsigned int *son; // [esp+18h] [ebp-2Ch]
  unsigned int count; // [esp+1Ch] [ebp-28h]
  unsigned int len0; // [esp+20h] [ebp-24h]
  unsigned int len0a; // [esp+20h] [ebp-24h]
  unsigned int len1; // [esp+24h] [ebp-20h]
  unsigned int *pair; // [esp+28h] [ebp-1Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-18h]
  unsigned int *ptr1; // [esp+30h] [ebp-14h]
  unsigned int matchMinPos; // [esp+34h] [ebp-10h]
  const unsigned __int8 *cur; // [esp+38h] [ebp-Ch]
  unsigned int lenLimit; // [esp+3Ch] [ebp-8h]
  unsigned int maxLen; // [esp+40h] [ebp-4h]
  int offset; // [esp+4Ch] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 3 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos((NBT4::CMatchFinder *)this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  cur = v9;
  LOWORD(v8) = LOWORD(CCRC::Table[v8]) ^ v9[1];
  v11 = v10 ^ (v9[2] << 8);
  hash = this->_hash;
  v13 = this->_hashMask & v11;
  v14 = v8 & 0x3FF;
  len0 = hash[v14];
  maxLen = 1;
  v15 = hash[v13 + 1024];
  hash[v14] = this->_pos;
  if ( len0 > matchMinPos && this->_buffer[len0] == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - len0 - 1;
    offset = 3;
    if ( len0 == v15 )
    {
      offset = 1;
      maxLen = 1;
    }
  }
  this->_hash[v13 + 1024] = this->_pos;
  cyclicBufferPos = this->_cyclicBufferPos;
  son = this->_son;
  v17 = 0;
  v18 = (int)&son[2 * cyclicBufferPos + 1];
  v19 = &son[2 * cyclicBufferPos];
  cutValue = this->_cutValue;
  ptr0 = (unsigned int *)v18;
  ptr1 = v19;
  len1 = 0;
  len0a = 0;
  if ( v15 > matchMinPos )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      v24 = this->_cyclicBufferPos;
      v25 = this->_pos - v15;
      delta = v25;
      if ( v25 > v24 )
        v26 = v24 + this->_cyclicBufferSize - v25;
      else
        v26 = v24 - v25;
      v27 = &son[2 * v26];
      v28 = len1;
      v29 = &this->_buffer[v15];
      pair = v27;
      pb = v29;
      if ( v17 < len1 )
        v28 = v17;
      if ( v29[v28] == cur[v28] )
      {
        if ( ++v28 != lenLimit )
        {
          v30 = &cur[v28];
          for ( i = v29 - cur; v30[i] == *v30; i = v29 - cur )
          {
            ++v28;
            ++v30;
            if ( v28 == lenLimit )
              break;
          }
        }
        if ( maxLen < v28 )
        {
          v21 = distances;
          distances[offset] = v28;
          distances[offset + 1] = delta - 1;
          v22 = offset + 2;
          maxLen = v28;
          offset += 2;
          if ( v28 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0 = pair[1];
            goto LABEL_14;
          }
          v29 = (unsigned __int8 *)pb;
        }
      }
      if ( v29[v28] >= cur[v28] )
      {
        *ptr0 = v15;
        v15 = *pair;
        v17 = v28;
        ptr0 = pair;
        v19 = ptr1;
        len0a = v28;
      }
      else
      {
        v17 = len0a;
        *ptr1 = v15;
        v15 = pair[1];
        v19 = pair + 1;
        ptr1 = pair + 1;
        len1 = v28;
      }
      if ( v15 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  v21 = distances;
  *v19 = 0;
  *ptr0 = 0;
  v22 = offset;
LABEL_14:
  *v21 = v22 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v23 = ++this->_pos;
  if ( v23 <= this->_posLimit )
    goto LABEL_20;
  if ( &this->_buffer[v23] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_20:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize((NBT4::CMatchFinder *)this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B8610
// Name: private: virtual long NBT3::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::Skip(NBT3::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // edx
  unsigned int v16; // eax
  int v17; // ecx
  unsigned __int8 *v18; // edx
  unsigned int v19; // ecx
  unsigned int *hash; // eax
  unsigned int v21; // edi
  unsigned int *v22; // ebx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // ecx
  unsigned __int8 *v29; // ecx
  unsigned __int8 *v30; // ebx
  unsigned int *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int *v34; // ebx
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // edx
  unsigned int *son; // [esp+Ch] [ebp-28h]
  unsigned int count; // [esp+10h] [ebp-24h]
  unsigned __int8 *v41; // [esp+18h] [ebp-1Ch]
  unsigned int len0; // [esp+1Ch] [ebp-18h]
  unsigned int len1; // [esp+20h] [ebp-14h]
  unsigned int *pair; // [esp+24h] [ebp-10h]
  unsigned int matchMinPos; // [esp+28h] [ebp-Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-8h]
  unsigned int *ptr1; // [esp+30h] [ebp-4h]
  unsigned int lenLimit; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimita; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimitb; // [esp+3Ch] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v17 = buffer[pos + 2];
      v18 = &buffer[pos];
      v19 = this->_hashMask & (v16 ^ (v17 << 8));
      this->_hash[v16 & 0x3FF] = pos;
      hash = this->_hash;
      v21 = hash[v19 + 1024];
      hash[v19 + 1024] = this->_pos;
      v22 = this->_son;
      ptr1 = &v22[2 * this->_cyclicBufferPos];
      len1 = 0;
      len0 = 0;
      cutValue = this->_cutValue;
      son = v22;
      ptr0 = ptr1 + 1;
      if ( v21 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v25 = this->_pos - v21;
          if ( v25 > cyclicBufferPos )
            v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
          else
            v26 = cyclicBufferPos - v25;
          pair = &v22[2 * v26];
          v27 = len0;
          v28 = &this->_buffer[v21];
          if ( len0 >= len1 )
            v27 = len1;
          if ( v28[v27] == v18[v27] )
          {
            if ( ++v27 == lenLimit )
              goto LABEL_40;
            v29 = (unsigned __int8 *)(v28 - v18);
            v30 = &v18[v27];
            v41 = v29;
            while ( v30[(_DWORD)v29] == *v30 )
            {
              ++v27;
              ++v30;
              if ( v27 == lenLimit )
                goto LABEL_40;
              v29 = v41;
            }
            if ( v27 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v28 = &this->_buffer[v21];
          }
          if ( v28[v27] >= v18[v27] )
          {
            *ptr0 = v21;
            v31 = pair;
            ptr0 = pair;
            len0 = v27;
          }
          else
          {
            *ptr1 = v21;
            v31 = pair + 1;
            ptr1 = pair + 1;
            len1 = v27;
          }
          v21 = *v31;
          if ( *v31 <= matchMinPos )
            break;
          cutValue = count;
          v22 = son;
        }
      }
      *ptr1 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v32 = ++this->_pos;
      if ( v32 > this->_posLimit )
      {
        if ( &this->_buffer[v32] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v33 = this->_cyclicBufferSize;
        v34 = this->_hash;
        v35 = this->_hashSizeSum + 2 * v33;
        v11 = 0x7FFFFFFF - v33;
        v36 = 0;
        for ( lenLimitb = v35; v36 < lenLimitb; ++v36 )
        {
          v37 = v34[v36];
          if ( v37 > v11 )
            v38 = v37 - v11;
          else
            v38 = 0;
          v34[v36] = v38;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 3 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B8920
// Name: private: virtual long NBT4::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::GetMatches(NBT4::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned __int16 v13; // dx
  __int16 v14; // di
  unsigned int *hash; // ecx
  int v16; // edi
  int v17; // ebx
  unsigned int *v18; // edi
  unsigned int v19; // ecx
  unsigned int *v20; // edi
  unsigned int cutValue; // eax
  unsigned int *v22; // ecx
  unsigned int v23; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // edi
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // edi
  const unsigned __int8 *v29; // ecx
  unsigned int delta; // [esp+8h] [ebp-34h]
  unsigned int *son; // [esp+Ch] [ebp-30h]
  unsigned int count; // [esp+10h] [ebp-2Ch]
  unsigned int curMatch3; // [esp+14h] [ebp-28h]
  unsigned int curMatch3a; // [esp+14h] [ebp-28h]
  unsigned int len1; // [esp+18h] [ebp-24h]
  unsigned int *pair; // [esp+1Ch] [ebp-20h]
  unsigned int *ptr0; // [esp+20h] [ebp-1Ch]
  unsigned int *ptr0a; // [esp+20h] [ebp-1Ch]
  unsigned int *ptr1; // [esp+24h] [ebp-18h]
  const unsigned __int8 *cur; // [esp+28h] [ebp-14h]
  unsigned int lenLimit; // [esp+2Ch] [ebp-10h]
  unsigned int matchMinPos; // [esp+30h] [ebp-Ch]
  unsigned int maxLen; // [esp+34h] [ebp-8h]
  unsigned int curMatch; // [esp+38h] [ebp-4h]
  int offset; // [esp+44h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 4 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos(this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  v11 = v9[2];
  cur = v9;
  v12 = this->_hashMask & (v10 ^ (32 * (CCRC::Table[v9[3]] ^ (8 * v11))));
  maxLen = 1;
  v13 = v10 ^ ((_WORD)v11 << 8);
  v14 = v10;
  hash = this->_hash;
  v16 = v14 & 0x3FF;
  curMatch = hash[v12 + 66560];
  ptr0 = (unsigned int *)hash[v16];
  curMatch3 = hash[v13 + 1024];
  hash[v16] = this->_pos;
  if ( (unsigned int)ptr0 > matchMinPos && *((_BYTE *)ptr0 + (unsigned int)this->_buffer) == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - (_DWORD)ptr0 - 1;
    v17 = 3;
    offset = 3;
  }
  else
  {
    v17 = 1;
  }
  this->_hash[v13 + 1024] = this->_pos;
  v18 = (unsigned int *)curMatch3;
  if ( curMatch3 > matchMinPos && this->_buffer[curMatch3] == *cur )
  {
    if ( (unsigned int *)curMatch3 == ptr0 )
      v17 -= 2;
    distances[v17] = 3;
    distances[v17 + 1] = this->_pos - curMatch3 - 1;
    v17 += 2;
    maxLen = 3;
    offset = v17;
  }
  else
  {
    v18 = ptr0;
  }
  v19 = curMatch;
  if ( v17 != 1 && v18 == (unsigned int *)curMatch )
  {
    v17 -= 2;
    offset = v17;
    maxLen = 1;
  }
  this->_hash[v12 + 66560] = this->_pos;
  son = this->_son;
  v20 = &son[2 * this->_cyclicBufferPos];
  len1 = 0;
  curMatch3a = 0;
  cutValue = this->_cutValue;
  ptr0a = v20 + 1;
  ptr1 = v20;
  if ( curMatch > matchMinPos )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v25 = this->_pos - v19;
      delta = v25;
      if ( v25 > cyclicBufferPos )
        v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
      else
        v26 = cyclicBufferPos - v25;
      pair = &son[2 * v26];
      v27 = curMatch3a;
      v28 = &this->_buffer[v19];
      if ( curMatch3a >= len1 )
        v27 = len1;
      if ( v28[v27] == cur[v27] )
      {
        if ( ++v27 != lenLimit )
        {
          v29 = &cur[v27];
          do
          {
            if ( v29[v28 - cur] != *v29 )
              break;
            ++v27;
            ++v29;
          }
          while ( v27 != lenLimit );
          v19 = curMatch;
        }
        v17 = offset;
        if ( maxLen < v27 )
        {
          v22 = distances;
          distances[offset] = v27;
          distances[offset + 1] = delta - 1;
          v17 = offset + 2;
          maxLen = v27;
          offset += 2;
          if ( v27 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0a = pair[1];
            goto LABEL_23;
          }
          v19 = curMatch;
        }
      }
      else
      {
        v17 = offset;
      }
      if ( v28[v27] >= cur[v27] )
      {
        v20 = ptr1;
        *ptr0a = v19;
        ptr0a = pair;
        v19 = *pair;
        curMatch3a = v27;
      }
      else
      {
        v20 = pair + 1;
        *ptr1 = v19;
        v19 = pair[1];
        ptr1 = pair + 1;
        len1 = v27;
      }
      curMatch = v19;
      if ( v19 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  v22 = distances;
  *v20 = 0;
  *ptr0a = 0;
LABEL_23:
  *v22 = v17 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v23 = ++this->_pos;
  if ( v23 <= this->_posLimit )
    goto LABEL_29;
  if ( &this->_buffer[v23] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_29:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B8C40
// Name: private: virtual long NBT4::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::Skip(NBT4::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // ecx
  unsigned int v16; // eax
  int v17; // edx
  unsigned int v18; // ecx
  unsigned int *hash; // eax
  unsigned int v20; // edx
  unsigned int *v21; // edi
  unsigned int *v22; // ecx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // edi
  const unsigned __int8 *v29; // ecx
  int v30; // ebx
  const unsigned __int8 *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int *v34; // ebx
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // edx
  unsigned int count; // [esp+Ch] [ebp-2Ch]
  unsigned int *son; // [esp+10h] [ebp-28h]
  unsigned int len0; // [esp+1Ch] [ebp-1Ch]
  unsigned int len1; // [esp+20h] [ebp-18h]
  const unsigned __int8 *cur; // [esp+24h] [ebp-14h]
  unsigned int *pair; // [esp+28h] [ebp-10h]
  unsigned int matchMinPos; // [esp+2Ch] [ebp-Ch]
  unsigned int *ptr0; // [esp+30h] [ebp-8h]
  unsigned int *ptr1; // [esp+34h] [ebp-4h]
  unsigned int lenLimit; // [esp+40h] [ebp+8h]
  unsigned int lenLimita; // [esp+40h] [ebp+8h]
  unsigned int lenLimitb; // [esp+40h] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v17 = buffer[pos + 2];
      cur = &buffer[pos];
      v18 = this->_hashMask & (v16 ^ (32 * (CCRC::Table[buffer[pos + 3]] ^ (8 * v17))));
      this->_hash[(unsigned __int16)(v16 ^ ((_WORD)v17 << 8)) + 1024] = pos;
      this->_hash[v16 & 0x3FF] = this->_pos;
      hash = this->_hash;
      v20 = hash[v18 + 66560];
      hash[v18 + 66560] = this->_pos;
      v21 = this->_son;
      ptr0 = &v21[2 * this->_cyclicBufferPos + 1];
      v22 = &v21[2 * this->_cyclicBufferPos];
      len1 = 0;
      len0 = 0;
      cutValue = this->_cutValue;
      son = v21;
      ptr1 = v22;
      if ( v20 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v25 = this->_pos - v20;
          if ( v25 > cyclicBufferPos )
            v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
          else
            v26 = cyclicBufferPos - v25;
          pair = &v21[2 * v26];
          v27 = len0;
          v28 = &this->_buffer[v20];
          if ( len0 >= len1 )
            v27 = len1;
          v29 = cur;
          if ( v28[v27] == cur[v27] )
          {
            if ( ++v27 == lenLimit )
              goto LABEL_40;
            v30 = v28 - cur;
            v31 = &cur[v27];
            while ( v31[v30] == *v31 )
            {
              ++v27;
              ++v31;
              if ( v27 == lenLimit )
                goto LABEL_40;
              v30 = v28 - cur;
            }
            if ( v27 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v29 = cur;
          }
          if ( v28[v27] >= v29[v27] )
          {
            *ptr0 = v20;
            v20 = *pair;
            ptr0 = pair;
            v22 = ptr1;
            len0 = v27;
          }
          else
          {
            *ptr1 = v20;
            v20 = pair[1];
            v22 = pair + 1;
            ptr1 = pair + 1;
            len1 = v27;
          }
          if ( v20 <= matchMinPos )
            break;
          v21 = son;
          cutValue = count;
        }
      }
      *v22 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v32 = ++this->_pos;
      if ( v32 > this->_posLimit )
      {
        if ( &this->_buffer[v32] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v33 = this->_cyclicBufferSize;
        v34 = this->_hash;
        v35 = this->_hashSizeSum + 2 * v33;
        v11 = 0x7FFFFFFF - v33;
        v36 = 0;
        for ( lenLimitb = v35; v36 < lenLimitb; ++v36 )
        {
          v37 = v34[v36];
          if ( v37 > v11 )
            v38 = v37 - v11;
          else
            v38 = 0;
          v34[v36] = v38;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 4 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B8FA0
// Name: private: virtual long NHC4::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::GetMatches(NHC4::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned __int16 v13; // dx
  __int16 v14; // di
  unsigned int *hash; // ecx
  int v16; // edi
  int v17; // ecx
  unsigned int v18; // edi
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v21; // edx
  unsigned int v22; // eax
  unsigned __int8 *v23; // edx
  unsigned int v24; // eax
  _BYTE *v25; // edi
  int v26; // edx
  unsigned int v27; // eax
  unsigned int *son; // [esp+8h] [ebp-20h]
  unsigned int curMatch3; // [esp+Ch] [ebp-1Ch]
  unsigned int curMatch3a; // [esp+Ch] [ebp-1Ch]
  unsigned int lenLimit; // [esp+10h] [ebp-18h]
  unsigned int cyclicPos; // [esp+14h] [ebp-14h]
  unsigned int cyclicPosa; // [esp+14h] [ebp-14h]
  int offset; // [esp+18h] [ebp-10h]
  unsigned int delta; // [esp+1Ch] [ebp-Ch]
  unsigned int deltaa; // [esp+1Ch] [ebp-Ch]
  unsigned int matchMinPos; // [esp+20h] [ebp-8h]
  const unsigned __int8 *cur; // [esp+24h] [ebp-4h]
  unsigned int maxLen; // [esp+30h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 4 )
    {
      *distances = 0;
      return NHC4::CMatchFinder::MovePos(this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  v11 = v9[2];
  cur = v9;
  v12 = this->_hashMask & (v10 ^ (32 * (CCRC::Table[v9[3]] ^ (8 * v11))));
  maxLen = 1;
  v13 = v10 ^ ((_WORD)v11 << 8);
  v14 = v10;
  hash = this->_hash;
  v16 = v14 & 0x3FF;
  cyclicPos = hash[v12 + 66560];
  delta = hash[v16];
  curMatch3 = hash[v13 + 1024];
  hash[v16] = this->_pos;
  if ( delta > matchMinPos && this->_buffer[delta] == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - delta - 1;
    v17 = 3;
  }
  else
  {
    v17 = 1;
  }
  this->_hash[v13 + 1024] = this->_pos;
  if ( curMatch3 > matchMinPos && this->_buffer[curMatch3] == *cur )
  {
    if ( curMatch3 == delta )
      v17 -= 2;
    distances[v17] = 3;
    distances[v17 + 1] = this->_pos - curMatch3 - 1;
    maxLen = 3;
    v17 += 2;
    delta = curMatch3;
  }
  v18 = cyclicPos;
  if ( v17 != 1 && delta == cyclicPos )
  {
    v17 -= 2;
    maxLen = 1;
  }
  this->_hash[v12 + 66560] = this->_pos;
  son = this->_son;
  son[this->_cyclicBufferPos] = cyclicPos;
  cutValue = this->_cutValue;
  if ( cyclicPos > matchMinPos )
  {
    while ( 1 )
    {
      curMatch3a = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v21 = this->_pos - v18;
      deltaa = v21;
      v22 = v21 > cyclicBufferPos ? this->_cyclicBufferSize + cyclicBufferPos - v21 : cyclicBufferPos - v21;
      v23 = &this->_buffer[v18];
      cyclicPosa = v22;
      if ( v23[maxLen] == cur[maxLen] && *v23 == *cur )
      {
        v24 = 1;
        if ( lenLimit != 1 )
        {
          v25 = cur + 1;
          v26 = v23 - cur;
          for ( offset = v26; v25[v26] == *v25; v26 = offset )
          {
            ++v24;
            ++v25;
            if ( v24 == lenLimit )
              break;
          }
        }
        if ( maxLen < v24 )
        {
          distances[v17] = v24;
          distances[v17 + 1] = deltaa - 1;
          v17 += 2;
          maxLen = v24;
          if ( v24 == lenLimit )
            break;
        }
      }
      v18 = son[cyclicPosa];
      if ( v18 <= matchMinPos )
        break;
      cutValue = curMatch3a;
    }
  }
  *distances = v17 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v27 = ++this->_pos;
  if ( v27 <= this->_posLimit )
    goto LABEL_43;
  if ( &this->_buffer[v27] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_43:
    if ( this->_pos == 0x7FFFFFFF )
      NHC4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B9240
// Name: private: virtual long NHC4::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::Skip(NHC4::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int v3; // eax
  HRESULT result; // eax
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int *v7; // ebx
  unsigned int v8; // ecx
  bool v9; // zf
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // edx
  unsigned __int8 *buffer; // ecx
  unsigned int v15; // eax
  int v16; // edx
  unsigned int v17; // ecx
  unsigned int *v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int cyclicBufferSize; // eax
  unsigned int hashSizeSum; // edi
  unsigned int *hash; // ebx
  unsigned int v24; // edi
  unsigned int v25; // eax
  unsigned int v26; // edx
  unsigned int v27; // edx

  do
  {
    pos = this->_pos;
    if ( this->_streamPos - pos >= 4 )
    {
      buffer = this->_buffer;
      v15 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v16 = buffer[pos + 2];
      v17 = this->_hashMask & (v15 ^ (32 * (CCRC::Table[buffer[pos + 3]] ^ (8 * v16))));
      this->_hash[(unsigned __int16)(v15 ^ ((_WORD)v16 << 8)) + 1024] = pos;
      this->_hash[v15 & 0x3FF] = this->_pos;
      v18 = &this->_hash[v17 + 66560];
      v19 = *v18;
      *v18 = this->_pos;
      this->_son[this->_cyclicBufferPos++] = v19;
      if ( this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v20 = ++this->_pos;
      if ( v20 > this->_posLimit )
      {
        if ( &this->_buffer[v20] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        cyclicBufferSize = this->_cyclicBufferSize;
        hashSizeSum = this->_hashSizeSum;
        hash = this->_hash;
        v8 = 0x7FFFFFFF - cyclicBufferSize;
        v9 = cyclicBufferSize + hashSizeSum == 0;
        v24 = cyclicBufferSize + hashSizeSum;
        v25 = 0;
        if ( !v9 )
        {
          do
          {
            v26 = hash[v25];
            if ( v26 > v8 )
              v27 = v26 - v8;
            else
              v27 = 0;
            hash[v25++] = v27;
          }
          while ( v25 < v24 );
        }
        goto LABEL_27;
      }
    }
    else
    {
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v3 = ++this->_pos;
      if ( v3 > this->_posLimit )
      {
        if ( &this->_buffer[v3] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v5 = this->_cyclicBufferSize;
        v6 = this->_hashSizeSum;
        v7 = this->_hash;
        v8 = 0x7FFFFFFF - v5;
        v9 = v5 + v6 == 0;
        v10 = v5 + v6;
        v11 = 0;
        if ( !v9 )
        {
          do
          {
            v12 = v7[v11];
            if ( v12 > v8 )
              v13 = v12 - v8;
            else
              v13 = 0;
            v7[v11++] = v13;
          }
          while ( v11 < v10 );
        }
LABEL_27:
        this->_buffer += v8;
        this->_posLimit -= v8;
        this->_pos -= v8;
        this->_streamPos -= v8;
      }
    }
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B9400
// Name: public: void NCompress::NLZMA::CLiteralEncoder2::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CLiteralEncoder2::Encode(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned __int8 symbol)
{
  NCompress::NLZMA::CLiteralEncoder2 *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int i; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 8;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    i = v7;
    Range = rangeEncoder->Range;
    v10 = v4->_encoders[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->_encoders[v5].Prob -= v4->_encoders[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->_encoders[v5].Prob += (2048 - v4->_encoders[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = i;
    v5 = v11 | (2 * v5);
  }
  while ( i != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x004B94A0
// Name: public: void NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(class NCompress::NRangeCoder::CEncoder __near *,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned __int8 matchByte,
        unsigned __int8 symbol)
{
  int v5; // edx
  int v6; // edx
  int v7; // ebx
  int v8; // edi
  unsigned int Range; // edx
  int v10; // ebx
  NCompress::NRangeCoder::CBitEncoder<5> *v11; // ecx
  unsigned int v12; // eax
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // eax
  int v17; // edi
  bool v18; // cf
  unsigned int v19; // ebx
  unsigned int v20; // eax
  unsigned int context; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  int ia; // [esp+1Ch] [ebp+8h]

  context = 1;
  v5 = 8;
  while ( 1 )
  {
    v6 = v5 - 1;
    v7 = matchByte >> v6;
    v8 = symbol >> v6;
    i = v6;
    Range = rangeEncoder->Range;
    v10 = v7 & 1;
    v11 = &this->_encoders[256 * v10 + 256 + context];
    v12 = v11->Prob * (Range >> 11);
    v13 = v8 & 1;
    if ( v13 != 0 )
    {
      rangeEncoder->Low += v12;
      rangeEncoder->Range = Range - v12;
      v11->Prob -= v11->Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v12;
      v11->Prob += (2048 - v11->Prob) >> 5;
    }
    v14 = rangeEncoder->Range;
    if ( v14 < 0x1000000 )
    {
      rangeEncoder->Range = v14 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    v5 = i;
    context = v13 | (2 * context);
    if ( v10 != v13 )
      break;
    if ( i == 0 )
      return;
  }
  if ( i != 0 )
  {
    do
    {
      --v5;
      v15 = context;
      v16 = this->_encoders[context].Prob * (rangeEncoder->Range >> 11);
      v17 = (symbol >> v5) & 1;
      ia = v5;
      if ( v17 != 0 )
      {
        v18 = __CFADD__(v16, rangeEncoder->Low);
        LODWORD(rangeEncoder->Low) += v16;
        v19 = rangeEncoder->Range;
        HIDWORD(rangeEncoder->Low) += v18;
        rangeEncoder->Range = v19 - v16;
        this->_encoders[context].Prob -= this->_encoders[context].Prob >> 5;
      }
      else
      {
        rangeEncoder->Range = v16;
        this->_encoders[context].Prob += (2048 - this->_encoders[context].Prob) >> 5;
      }
      v20 = rangeEncoder->Range;
      if ( v20 < 0x1000000 )
      {
        rangeEncoder->Range = v20 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
        v5 = ia;
        v15 = context;
      }
      context = v17 | (2 * v15);
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9600
// Name: public: unsigned int NCompress::NLZMA::CLiteralEncoder2::GetPrice(bool,unsigned char,unsigned char)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CLiteralEncoder2::GetPrice(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        bool matchMode,
        unsigned __int8 matchByte,
        unsigned __int8 symbol)
{
  unsigned int result; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // edx
  int v8; // edx
  unsigned int price; // [esp+10h] [ebp-4h]

  result = 0;
  price = 0;
  v5 = 1;
  v6 = 8;
  if ( !matchMode )
    goto LABEL_9;
  do
  {
    v7 = (symbol >> --v6) & 1;
    result = NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v7
                                                              ^ (this->_encoders[256 * ((matchByte >> v6) & 1)
                                                                               + 256
                                                                               + v5].Prob
                                                               - v7)) >> 2)
                                                            & 0x1FF]
           + price;
    v5 = v7 | (2 * v5);
    price = result;
    if ( ((matchByte >> v6) & 1) != v7 )
      break;
  }
  while ( v6 != 0 );
  if ( v6 != 0 )
  {
LABEL_9:
    do
    {
      v8 = (symbol >> --v6) & 1;
      result += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v8 ^ (this->_encoders[v5].Prob - v8)) >> 2) & 0x1FF];
      v5 = v8 | (2 * v5);
    }
    while ( v6 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B96D0
// Name: public: void NCompress::NLZMA::NLength::CEncoder::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::Init(
        NCompress::NLZMA::NLength::CEncoder *this,
        unsigned int numPosStates)
{
  unsigned int v2; // esi
  NCompress::NRangeCoder::CBitEncoder<5> *v3; // eax

  v2 = numPosStates;
  this->_choice.Prob = 1024;
  this->_choice2.Prob = 1024;
  if ( numPosStates != 0 )
  {
    v3 = &this->_midCoder[0].Models[1];
    do
    {
      v3[-128].Prob = 1024;
      v3[-127].Prob = 1024;
      v3[-126].Prob = 1024;
      v3[-125].Prob = 1024;
      v3[-124].Prob = 1024;
      v3[-123].Prob = 1024;
      v3[-122].Prob = 1024;
      v3->Prob = 1024;
      v3[1].Prob = 1024;
      v3[2].Prob = 1024;
      v3[3].Prob = 1024;
      v3[4].Prob = 1024;
      v3[5].Prob = 1024;
      v3[6].Prob = 1024;
      v3 += 8;
      --v2;
    }
    while ( v2 != 0 );
  }
  memset32(&this->_highCoder.Models[1], 1024, 0xFFu);
}

//------------------------------------------------------------------------------
// Address: 0x004B9750
// Name: public: void NCompress::NLZMA::NLength::CEncoder::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::Encode(
        NCompress::NLZMA::NLength::CEncoder *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol,
        unsigned int posState)
{
  unsigned int v5; // eax
  unsigned int Range; // ecx
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // eax

  if ( symbol >= 8 )
  {
    Range = rangeEncoder->Range;
    v7 = this->_choice.Prob * (Range >> 11);
    rangeEncoder->Low += v7;
    rangeEncoder->Range = Range - v7;
    this->_choice.Prob -= this->_choice.Prob >> 5;
    v8 = rangeEncoder->Range;
    if ( v8 < 0x1000000 )
    {
      rangeEncoder->Range = v8 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    if ( symbol >= 0x10 )
    {
      v10 = rangeEncoder->Range;
      v11 = this->_choice2.Prob * (v10 >> 11);
      rangeEncoder->Low += v11;
      rangeEncoder->Range = v10 - v11;
      this->_choice2.Prob -= this->_choice2.Prob >> 5;
      v12 = rangeEncoder->Range;
      if ( v12 < 0x1000000 )
      {
        rangeEncoder->Range = v12 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(this: &this->_highCoder, rangeEncoder, symbol: symbol - 16);
    }
    else
    {
      rangeEncoder->Range = this->_choice2.Prob * (rangeEncoder->Range >> 11);
      this->_choice2.Prob += (2048 - this->_choice2.Prob) >> 5;
      v9 = rangeEncoder->Range;
      if ( v9 < 0x1000000 )
      {
        rangeEncoder->Range = v9 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(
        this: &this->_midCoder[posState],
        rangeEncoder,
        symbol: symbol - 8);
    }
  }
  else
  {
    rangeEncoder->Range = this->_choice.Prob * (rangeEncoder->Range >> 11);
    this->_choice.Prob += (2048 - this->_choice.Prob) >> 5;
    v5 = rangeEncoder->Range;
    if ( v5 < 0x1000000 )
    {
      rangeEncoder->Range = v5 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(this: &this->_lowCoder[posState], rangeEncoder, symbol);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B98A0
// Name: public: void NCompress::NLZMA::NLength::CEncoder::SetPrices(unsigned int,unsigned int,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::SetPrices(
        NCompress::NLZMA::NLength::CEncoder *this,
        unsigned int posState,
        unsigned int numSymbols,
        unsigned int *prices)
{
  unsigned int v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // edx
  int i; // edi
  char v8; // al
  unsigned int v9; // edx
  unsigned int v10; // edx
  int v11; // edi
  char v12; // al
  unsigned int v13; // edx
  unsigned int v14; // edx
  int v15; // edi
  char v16; // al
  unsigned int b1; // [esp+Ch] [ebp-Ch]
  unsigned int b0; // [esp+10h] [ebp-8h]
  unsigned int a0; // [esp+14h] [ebp-4h]
  unsigned int a0a; // [esp+14h] [ebp-4h]
  unsigned int posStatea; // [esp+20h] [ebp+8h]

  a0 = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_choice.Prob >> 2];
  v4 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_choice.Prob) >> 2];
  b0 = v4 + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_choice2.Prob >> 2];
  b1 = v4 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_choice2.Prob) >> 2];
  v5 = 0;
  while ( v5 < numSymbols )
  {
    v6 = v5 | 8;
    for ( i = 0;
          v6 != 1;
          i += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v8 & 1)
                                                                ^ (this->_lowCoder[posState].Models[v6].Prob - (v8 & 1))) >> 2)
                                                              & 0x1FF] )
    {
      v8 = v6;
      v6 >>= 1;
    }
    prices[v5++] = a0 + i;
    if ( v5 >= 8 )
    {
      if ( v5 >= 0x10 )
      {
LABEL_12:
        if ( v5 < numSymbols )
        {
          v13 = v5 - 16;
          posStatea = v5 - 16;
          do
          {
            v14 = v13 | 0x100;
            v15 = 0;
            do
            {
              v16 = v14;
              v14 >>= 1;
              v15 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v16 & 1)
                                                                      ^ (this->_highCoder.Models[v14].Prob - (v16 & 1))) >> 2)
                                                                    & 0x1FF];
            }
            while ( v14 != 1 );
            prices[v5++] = b1 + v15;
            v13 = ++posStatea;
          }
          while ( v5 < numSymbols );
        }
      }
      else
      {
        v9 = v5 - 8;
        a0a = v5 - 8;
        while ( v5 < numSymbols )
        {
          v10 = v9 | 8;
          v11 = 0;
          do
          {
            v12 = v10;
            v10 >>= 1;
            v11 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v12 & 1)
                                                                    ^ (this->_midCoder[posState].Models[v10].Prob
                                                                     - (v12 & 1))) >> 2)
                                                                  & 0x1FF];
          }
          while ( v10 != 1 );
          prices[v5++] = b0 + v11;
          v9 = ++a0a;
          if ( v5 >= 0x10 )
            goto LABEL_12;
        }
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9A20
// Name: public: virtual long NCompress::NLZMA::CEncoder::SetCoderProperties(unsigned long const __near *,struct tagPROPVARIANT const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::SetCoderProperties(
        NCompress::NLZMA::CEncoder *this,
        const unsigned int *propIDs,
        const tagPROPVARIANT *properties,
        unsigned int numProperties)
{
  unsigned int v4; // eax
  unsigned int v6; // eax
  ISequentialInStream *MatchFinder; // eax
  bool v8; // zf
  unsigned int Lo32; // edx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int i; // [esp+Ch] [ebp-4h]
  ISequentialInStream *matchFinderIndexPrev; // [esp+20h] [ebp+10h]

  v4 = 0;
  i = 0;
  if ( numProperties != 0 )
  {
    while ( 2 )
    {
      switch ( propIDs[v4] )
      {
        case 0x400u:
          if ( properties->vt != 19 )
            return -2147024809;
          Lo32 = properties->decVal.Lo32;
          if ( Lo32 - 1 > 0x3FFFFFFF )
            return -2147024809;
          this->_numLiteralPosStateBits = Lo32;
          v10 = 0;
          v11 = 1;
          do
          {
            if ( Lo32 <= v11 )
              break;
            ++v10;
            v11 = __ROL4__(v11, 1);
          }
          while ( v10 < 0x1E );
          this->_alignPrices[15] = 2 * v10;
          goto LABEL_32;
        case 0x440u:
          if ( properties->vt != 19 )
            return -2147024809;
          v12 = properties->decVal.Lo32;
          if ( v12 > 4 )
            return -2147024809;
          this->_alignPriceCount = v12;
          this->_distTableSize = (1 << v12) - 1;
          goto LABEL_32;
        case 0x441u:
          if ( properties->vt != 19 )
            return -2147024809;
          v14 = properties->decVal.Lo32;
          if ( v14 > 8 )
            return -2147024809;
          this->_posStateMask = v14;
          goto LABEL_32;
        case 0x442u:
          if ( properties->vt != 19 )
            return -2147024809;
          v13 = properties->decVal.Lo32;
          if ( v13 > 4 )
            return -2147024809;
          this->_posStateBits = v13;
          goto LABEL_32;
        case 0x450u:
          if ( properties->vt != 19 )
            return -2147024809;
          v6 = properties->decVal.Lo32;
          if ( v6 - 5 > 0x10C )
            return -2147024809;
          this->_matchDistances[548] = v6;
          goto LABEL_32;
        case 0x451u:
          if ( properties->vt != 8 )
            return -2147024809;
          matchFinderIndexPrev = this->_inStream;
          MatchFinder = (ISequentialInStream *)NCompress::NLZMA::FindMatchFinder(s: properties->bstrVal);
          if ( (int)MatchFinder < 0 )
            return -2147024809;
          v8 = this->_optimum[4095].Backs[2] == 0;
          this->_inStream = MatchFinder;
          if ( !v8 && matchFinderIndexPrev != MatchFinder )
          {
            this->_numLiteralContextBits = -1;
            NCompress::NLZMA::CEncoder::ReleaseMatchFinder(this: (NCompress::NLZMA::CEncoder *)((char *)this - 8));
          }
          goto LABEL_32;
        case 0x452u:
          if ( properties->vt != 19 )
            return -2147024809;
          *(_DWORD *)&this->_finished = properties->decVal.Lo32;
          goto LABEL_32;
        case 0x470u:
          if ( properties->vt != 19 )
            return -2147024809;
          LOBYTE(this->_matchDistances[547]) = properties->decVal.Lo32 == 0;
          goto LABEL_32;
        case 0x490u:
          if ( properties->vt != 11 )
            return -2147024809;
          LOBYTE(this->_matchFinderCycles) = properties->iVal == -1;
LABEL_32:
          v4 = i + 1;
          ++properties;
          i = v4;
          if ( v4 >= numProperties )
            return 0;
          continue;
        default:
          return -2147024809;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B9CB0
// Name: public: virtual long NCompress::NLZMA::CEncoder::ReleaseOutStream(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::ReleaseOutStream(NCompress::NLZMA::CEncoder *this)
{
  unsigned int bufferSize; // eax

  bufferSize = this->_rangeEncoder.Stream._bufferSize;
  if ( bufferSize != 0 )
  {
    (*(void (__stdcall **)(unsigned int))(*(_DWORD *)bufferSize + 8))(a1: this->_rangeEncoder.Stream._bufferSize);
    this->_rangeEncoder.Stream._bufferSize = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B9CE0
// Name: public: long NCompress::NLZMA::CEncoder::Init(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Init(NCompress::NLZMA::CEncoder *this)
{
  NCompress::NRangeCoder::CBitEncoder<5> *isRepG0; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v3; // edi
  unsigned int v4; // edx
  NCompress::NRangeCoder::CBitEncoder<5> *v5; // eax
  int v6; // ecx
  int v7; // edx
  NCompress::NLZMA::CLiteralEncoder2 *v8; // edi
  bool v9; // zf
  NCompress::NRangeCoder::CBitEncoder<5> *v10; // edx
  NCompress::NRangeCoder::CBitEncoder<5> *v11; // edi
  int i; // [esp+Ch] [ebp-4h]
  int v14; // [esp+Ch] [ebp-4h]
  int v15; // [esp+Ch] [ebp-4h]

  *(_WORD *)&this->_state.Index = 0;
  this->_repDistances[0] = 0;
  this->_repDistances[1] = 0;
  this->_repDistances[2] = 0;
  this->_repDistances[3] = 0;
  COutBuffer::Init(this: &this->_rangeEncoder.Stream);
  this->_rangeEncoder.Low = 0;
  this->_rangeEncoder.Range = -1;
  this->_rangeEncoder._cacheSize = 1;
  this->_rangeEncoder._cache = 0;
  isRepG0 = this->_isRepG0;
  v3 = this->_isRep0Long[0];
  for ( i = 12; i != 0; --i )
  {
    v4 = 0;
    v5 = v3;
    do
    {
      v5[-240].Prob = 1024;
      v5->Prob = 1024;
      ++v4;
      ++v5;
    }
    while ( v4 <= this->_posStateMask );
    isRepG0[-12].Prob = 1024;
    isRepG0->Prob = 1024;
    isRepG0[12].Prob = 1024;
    isRepG0[24].Prob = 1024;
    ++isRepG0;
    v3 += 16;
  }
  v6 = this->_literalEncoder._numPrevBits + this->_literalEncoder._numPosBits;
  if ( 1 << v6 != 0 )
  {
    v7 = 0;
    v14 = 1 << v6;
    do
    {
      v8 = &this->_literalEncoder._coders[v7++];
      v9 = v14-- == 1;
      memset32(v8, 1024, 0x300u);
    }
    while ( !v9 );
  }
  v10 = &this->_posSlotEncoder[0].Models[1];
  v15 = 4;
  do
  {
    v11 = v10;
    v10 += 64;
    v9 = v15-- == 1;
    memset32(v11, 1024, 0x3Fu);
  }
  while ( !v9 );
  memset32(this->_posEncoders, 1024, 0x72u);
  NCompress::NLZMA::NLength::CEncoder::Init(this: &this->_lenEncoder, numPosStates: 1 << this->_posStateBits);
  NCompress::NLZMA::NLength::CEncoder::Init(this: &this->_repMatchLenEncoder, numPosStates: 1 << this->_posStateBits);
  this->_posAlignEncoder.Models[1].Prob = 1024;
  this->_posAlignEncoder.Models[2].Prob = 1024;
  this->_posAlignEncoder.Models[3].Prob = 1024;
  this->_posAlignEncoder.Models[4].Prob = 1024;
  this->_posAlignEncoder.Models[5].Prob = 1024;
  this->_posAlignEncoder.Models[6].Prob = 1024;
  this->_posAlignEncoder.Models[7].Prob = 1024;
  this->_posAlignEncoder.Models[8].Prob = 1024;
  this->_posAlignEncoder.Models[9].Prob = 1024;
  this->_posAlignEncoder.Models[10].Prob = 1024;
  this->_posAlignEncoder.Models[11].Prob = 1024;
  this->_posAlignEncoder.Models[12].Prob = 1024;
  this->_posAlignEncoder.Models[13].Prob = 1024;
  this->_posAlignEncoder.Models[14].Prob = 1024;
  this->_posAlignEncoder.Models[15].Prob = 1024;
  this->_longestMatchWasFound = false;
  this->_optimumEndIndex = 0;
  this->_optimumCurrentIndex = 0;
  this->_additionalOffset = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B9EB0
// Name: private: long NCompress::NLZMA::CEncoder::ReadMatchDistances(unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::ReadMatchDistances(
        NCompress::NLZMA::CEncoder *this,
        unsigned int *lenRes,
        unsigned int *numDistancePairs)
{
  unsigned int *matchDistances; // ebx
  HRESULT result; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax

  *lenRes = 0;
  matchDistances = this->_matchDistances;
  result = this->_matchFinder._p->GetMatches(this: this->_matchFinder._p, a2: this->_matchDistances);
  if ( result == 0 )
  {
    v6 = *matchDistances;
    *numDistancePairs = *matchDistances;
    if ( v6 != 0 )
    {
      v7 = *(&this->_literalEncoder._posMask + v6);
      *lenRes = v7;
      if ( v7 == this->_numFastBytes )
        *lenRes += this->_matchFinder._p->GetMatchLen(
                     this: this->_matchFinder._p,
                     a2: v7 - 1,
                     a3: this->_matchDistances[*numDistancePairs],
                     a4: 273 - v7);
    }
    ++this->_additionalOffset;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B9F30
// Name: private: long NCompress::NLZMA::CEncoder::GetOptimumFast(unsigned int,unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetOptimumFast(
        NCompress::NLZMA::CEncoder *this,
        unsigned int position,
        unsigned int *backRes,
        unsigned int *lenRes)
{
  NCompress::NLZMA::CEncoder *v4; // ebx
  bool v5; // zf
  unsigned int result; // eax
  unsigned int v7; // eax
  const unsigned __int8 *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  const unsigned __int8 *v11; // ecx
  unsigned int j; // eax
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int *v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned int longestMatchLength; // eax
  unsigned int v20; // esi
  unsigned int v21; // edx
  unsigned int *repDistances; // esi
  const unsigned __int8 *v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int repLens[4]; // [esp+4h] [ebp-28h]
  unsigned int newDistance; // [esp+14h] [ebp-18h]
  unsigned int i; // [esp+18h] [ebp-14h]
  unsigned int numDistancePairs; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int numAvailableBytes; // [esp+20h] [ebp-Ch]
  unsigned int backMain; // [esp+24h] [ebp-8h]
  unsigned int lenMain; // [esp+28h] [ebp-4h] BYREF

  v4 = this;
  v5 = !this->_longestMatchWasFound;
  newDistance = (unsigned int)this;
  if ( v5 )
  {
    result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &lenMain, &numDistancePairs);
    if ( result != 0 )
      return result;
  }
  else
  {
    v7 = this->_numDistancePairs;
    lenMain = this->_longestMatchLength;
    numDistancePairs = v7;
    this->_longestMatchWasFound = false;
  }
  v8 = v4->_matchFinder._p->GetPointerToCurrentPos(this: v4->_matchFinder._p);
  v9 = v4->_matchFinder._p->GetNumAvailableBytes(this: v4->_matchFinder._p) + 1;
  numAvailableBytes = v9;
  if ( v9 <= 0x111 )
  {
    if ( v9 < 2 )
    {
      *backRes = -1;
      *lenRes = 1;
      return 0;
    }
  }
  else
  {
    numAvailableBytes = 273;
  }
  v10 = 0;
  i = 0;
  backMain = 0;
  while ( 1 )
  {
    v11 = &v8[-v4->_repDistances[v10] - 2];
    if ( *(v8 - 1) == *v11 && *v8 == v8[-v4->_repDistances[v10] - 1] )
      break;
    repLens[v10] = 0;
LABEL_19:
    if ( ++v10 >= 4 )
    {
      v14 = lenMain;
      if ( lenMain >= v4->_numFastBytes )
      {
        *backRes = v4->_matchDistances[numDistancePairs] + 4;
        result = v14 - 1;
        *lenRes = v14;
        if ( v14 == 1 )
          return result;
        goto LABEL_24;
      }
      backMain = 0;
      if ( lenMain >= 2 )
      {
        v15 = numDistancePairs;
        backMain = v4->_matchDistances[numDistancePairs];
        if ( numDistancePairs > 2 )
        {
          v16 = (unsigned int *)(&v4->_literalEncoder._numPosBits + numDistancePairs);
          do
          {
            if ( lenMain != *(v16 - 1) + 1 )
              break;
            if ( backMain >> 7 <= *v16 )
              break;
            v17 = *(v16 - 1);
            v16 -= 2;
            v15 -= 2;
            lenMain = v17;
            backMain = v16[2];
          }
          while ( v15 > 2 );
          v14 = lenMain;
        }
        if ( v14 == 2 && backMain >= 0x80 )
        {
          lenMain = 1;
          v14 = 1;
        }
      }
      v18 = repLens[i];
      if ( v18 >= 2 && (v18 + 1 >= v14 || v18 + 2 >= v14 && backMain > 0x200 || v18 + 3 >= v14 && backMain > 0x8000) )
      {
        *backRes = i;
        *lenRes = v18;
        result = v18 - 1;
        if ( result != 0 )
          goto LABEL_24;
        return result;
      }
      if ( v14 < 2 || numAvailableBytes <= 2 )
      {
        *backRes = -1;
        *lenRes = 1;
        return 0;
      }
      result = NCompress::NLZMA::CEncoder::ReadMatchDistances(
                 this: v4,
                 lenRes: &v4->_longestMatchLength,
                 numDistancePairs: &v4->_numDistancePairs);
      if ( result != 0 )
        return result;
      longestMatchLength = v4->_longestMatchLength;
      if ( longestMatchLength >= 2 )
      {
        v20 = v4->_matchDistances[v4->_numDistancePairs];
        newDistance = v20;
        if ( longestMatchLength >= lenMain && v20 < backMain )
          goto LABEL_56;
        if ( longestMatchLength == lenMain + 1 )
        {
          if ( v20 >> 7 <= backMain )
          {
LABEL_56:
            v4->_longestMatchWasFound = true;
            *backRes = -1;
            *lenRes = 1;
            return 0;
          }
          v20 = newDistance;
        }
        if ( longestMatchLength > lenMain + 1
          || longestMatchLength + 1 >= lenMain && lenMain >= 3 && backMain >> 7 > v20 )
        {
          goto LABEL_56;
        }
      }
      --numAvailableBytes;
      v21 = 0;
      i = 0;
      repDistances = v4->_repDistances;
      do
      {
        v23 = &v8[-*repDistances - 1];
        if ( v8[1] == v8[-*repDistances] && v8[2] == v23[2] )
        {
          v24 = 2;
          if ( numAvailableBytes > 2 )
          {
            do
            {
              if ( v8[v24] != v23[v24] )
                break;
              ++v24;
            }
            while ( v24 < numAvailableBytes );
            v21 = i;
          }
          if ( v24 + 1 >= lenMain )
            goto LABEL_56;
        }
        else
        {
          repLens[v21] = 0;
        }
        ++v21;
        ++repDistances;
        i = v21;
      }
      while ( v21 < 4 );
      *backRes = backMain + 4;
      v25 = lenMain;
      *lenRes = lenMain;
      result = v25 - 2;
      if ( result != 0 )
        goto LABEL_24;
      return 0;
    }
  }
  for ( j = 2; j < numAvailableBytes; ++j )
  {
    if ( v8[j - 1] != v11[j] )
      break;
  }
  v4 = (NCompress::NLZMA::CEncoder *)newDistance;
  if ( j < *(_DWORD *)(newDistance + 208512) )
  {
    v13 = backMain;
    repLens[v10] = j;
    if ( j > *(unsigned int *)((char *)repLens + v13) )
    {
      i = v10;
      backMain = 4 * v10;
    }
    goto LABEL_19;
  }
  *backRes = v10;
  *lenRes = j;
  result = j - 1;
  if ( result != 0 )
  {
LABEL_24:
    v4->_additionalOffset += result;
    return v4->_matchFinder._p->Skip(this: v4->_matchFinder._p, a2: result);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BA2C0
// Name: private: void NCompress::NLZMA::CEncoder::FillDistancesPrices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::FillDistancesPrices(NCompress::NLZMA::CEncoder *this)
{
  NCompress::NLZMA::CEncoder *v1; // ebx
  unsigned int i; // esi
  int v3; // eax
  unsigned int *v4; // esi
  unsigned int *v5; // edx
  unsigned int v6; // edi
  unsigned int v7; // ecx
  unsigned int v8; // esi
  char v9; // al
  unsigned int j; // eax
  unsigned int v11; // eax
  _DWORD *v12; // esi
  int v13; // ecx
  unsigned int tempPrices[128]; // [esp+Ch] [ebp-210h] BYREF
  NCompress::NLZMA::CEncoder *v15; // [esp+20Ch] [ebp-10h]
  int v16; // [esp+210h] [ebp-Ch]
  char *v17; // [esp+214h] [ebp-8h]
  unsigned int *v18; // [esp+218h] [ebp-4h]

  v1 = this;
  v15 = this;
  for ( i = 4; i < 0x80; ++i )
  {
    v3 = (NCompress::NLZMA::g_FastPos[i] & 1 | 2) << ((NCompress::NLZMA::g_FastPos[i] >> 1) - 1);
    tempPrices[i] = NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(
                      Models: &v1->_posSlotEncoder[3].Models[v3 - NCompress::NLZMA::g_FastPos[i] + 63],
                      NumBitLevels: (NCompress::NLZMA::g_FastPos[i] >> 1) - 1,
                      symbol: i - v3);
  }
  v4 = &v1->_distancesPrices[0][2];
  v5 = v1->_posSlotPrices[0];
  v18 = &v1->_distancesPrices[0][2];
  v17 = (char *)((char *)tempPrices - (char *)v1 - 209564);
  v16 = 4;
  while ( 1 )
  {
    v6 = 0;
    if ( v1->_distTableSize != 0 )
    {
      do
      {
        v7 = v6 | 0x40;
        v8 = 0;
        if ( (v6 | 0x40) != 1 )
        {
          do
          {
            v9 = v7;
            v7 >>= 1;
            v8 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v9 & 1) ^ (v5[v7 - 10713] - (v9 & 1))) >> 2)
                                                                 & 0x1FF];
          }
          while ( v7 != 1 );
          v1 = v15;
        }
        v5[v6++] = v8;
      }
      while ( v6 < v1->_distTableSize );
      v4 = v18;
    }
    for ( j = 14; j < v1->_distTableSize; ++j )
      v5[j] += ((j >> 1) - 5) << 6;
    *(v4 - 2) = *v5;
    *(v4 - 1) = v5[1];
    *v4 = v5[2];
    v4[1] = v5[3];
    v11 = 4;
    v12 = v4 + 2;
    do
    {
      v13 = NCompress::NLZMA::g_FastPos[v11++];
      *v12 = *(_DWORD *)((char *)v12 + (_DWORD)v17) + v5[v13];
      ++v12;
    }
    while ( v11 < 0x80 );
    v18 += 128;
    v17 -= 512;
    v5 += 64;
    if ( --v16 == 0 )
      break;
    v4 = v18;
  }
  v1->_matchPriceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BA490
// Name: private: void NCompress::NLZMA::CEncoder::FillAlignPrices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::FillAlignPrices(NCompress::NLZMA::CEncoder *this)
{
  unsigned int v1; // edi
  unsigned int v2; // esi
  int v3; // edx
  int v4; // eax
  unsigned int *alignPrices; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  v1 = 0;
  i = 0;
  alignPrices = this->_alignPrices;
  do
  {
    v2 = 0;
    v3 = 1;
    for ( j = 4; j != 0; --j )
    {
      v4 = v1 & 1;
      v2 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v4 ^ (this->_posAlignEncoder.Models[v3].Prob - v4)) >> 2)
                                                           & 0x1FF];
      v1 >>= 1;
      v3 = v4 | (2 * v3);
    }
    v1 = i + 1;
    *alignPrices = v2;
    i = v1;
    ++alignPrices;
  }
  while ( v1 < 0x10 );
  this->_alignPriceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BA520
// Name: public: void NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(
        NCompress::NLZMA::NLength::CPriceTableEncoder *this,
        unsigned int numPosStates)
{
  unsigned int v2; // esi
  unsigned int *counters; // edi
  unsigned int *v4; // ebx

  v2 = 0;
  if ( numPosStates != 0 )
  {
    counters = this->_counters;
    v4 = this->_prices[0];
    do
    {
      NCompress::NLZMA::NLength::CEncoder::SetPrices(this, posState: v2, numSymbols: this->_tableSize, prices: v4);
      *counters = this->_tableSize;
      ++v2;
      ++counters;
      v4 += 272;
    }
    while ( v2 < numPosStates );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA570
// Name: public: void NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(
        NCompress::NLZMA::NLength::CPriceTableEncoder *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol,
        unsigned int posState,
        bool updatePrice)
{
  NCompress::NLZMA::NLength::CEncoder::Encode(this, rangeEncoder, symbol, posState);
  if ( updatePrice && this->_counters[posState]-- == 1 )
  {
    NCompress::NLZMA::NLength::CEncoder::SetPrices(
      this,
      posState,
      numSymbols: this->_tableSize,
      prices: this->_prices[posState]);
    this->_counters[posState] = this->_tableSize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA5D0
// Name: public: NBT3::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT3::CMatchFinder *__thiscall NBT3::CMatchFinder::CMatchFinder(NBT3::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT3::CMatchFinder_vtbl *)&NBT3::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT3::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT3::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BA600
// Name: public: NBT4::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT4::CMatchFinder *__thiscall NBT4::CMatchFinder::CMatchFinder(NBT4::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT4::CMatchFinder_vtbl *)&NBT4::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT4::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT4::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BA630
// Name: public: NHC4::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NHC4::CMatchFinder *__thiscall NHC4::CMatchFinder::CMatchFinder(NHC4::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NHC4::CMatchFinder_vtbl *)&NHC4::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NHC4::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NHC4::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BA660
// Name: public: NCompress::NLZMA::CEncoder::CEncoder(void)
// Source: json
//------------------------------------------------------------------------------
NCompress::NLZMA::CEncoder *__thiscall NCompress::NLZMA::CEncoder::CEncoder(NCompress::NLZMA::CEncoder *this)
{
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&ICompressSetOutStream::`vftable';
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&ICompressSetCoderProperties::`vftable';
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&ICompressWriteCoderProperties::`vftable';
  this->__m_RefCount = 0;
  this->ICompressCoder::IUnknown::__vftable = (NCompress::NLZMA::CEncoder_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressCoder'};
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetOutStream'};
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetCoderProperties'};
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressWriteCoderProperties'};
  this->_matchFinder._p = nullptr;
  this->_rangeEncoder.Stream._buffer = nullptr;
  this->_rangeEncoder.Stream._pos = 0;
  this->_rangeEncoder.Stream._stream._p = nullptr;
  this->_rangeEncoder.Stream._buffer2 = nullptr;
  this->_literalEncoder._coders = nullptr;
  this->_posStateMask = 3;
  this->_numLiteralContextBits = 3;
  this->_numFastBytes = 32;
  this->_distTableSize = 44;
  this->_posStateBits = 2;
  this->_numLiteralPosStateBits = 0;
  this->_dictionarySize = 0x400000;
  this->_dictionarySizePrev = -1;
  this->_numFastBytesPrev = -1;
  this->_matchFinderCycles = 0;
  this->_matchFinderIndex = 2;
  this->_writeEndMark = false;
  this->setMfPasses = nullptr;
  this->_fastMode = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BA730
// Name: _IsEqualGUID
// Source: json
//------------------------------------------------------------------------------
int __cdecl IsEqualGUID(const _GUID *rguid1, const _GUID *rguid2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( rguid1->Data1 == rguid2->Data1 )
  {
    v4 -= 4;
    rguid2 = (const _GUID *)((char *)rguid2 + 4);
    rguid1 = (const _GUID *)((char *)rguid1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BA7A0
// Name: public: virtual long NCompress::NLZMA::CEncoder::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::QueryInterface(
        NCompress::NLZMA::CEncoder *this,
        const _GUID *iid,
        void **outObject)
{
  NCompress::NLZMA::CEncoder *v3; // eax

  if ( IsEqualGUID(rguid1: iid, rguid2: &IID_ICompressSetOutStream) != 0 )
  {
    v3 = this;
    if ( this != nullptr )
    {
      *outObject = &this->ICompressSetOutStream;
      this->AddRef(this);
      return 0;
    }
    goto LABEL_4;
  }
  if ( IsEqualGUID(rguid1: iid, rguid2: &IID_ICompressSetCoderProperties) != 0 )
  {
    v3 = this;
    if ( this != nullptr )
    {
      *outObject = &this->ICompressSetCoderProperties;
      this->AddRef(this);
      return 0;
    }
LABEL_4:
    *outObject = nullptr;
    v3->AddRef(this: v3);
    return 0;
  }
  if ( IsEqualGUID(rguid1: iid, rguid2: &IID_ICompressWriteCoderProperties) == 0 )
    return -2147467262;
  v3 = this;
  if ( this == nullptr )
    goto LABEL_4;
  *outObject = &this->ICompressWriteCoderProperties;
  this->AddRef(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BA860
// Name: public: virtual unsigned long NCompress::NLZMA::CEncoder::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NCompress::NLZMA::CEncoder::AddRef(NCompress::NLZMA::CEncoder *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BA880
// Name: public: virtual unsigned long NCompress::NLZMA::CEncoder::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NCompress::NLZMA::CEncoder::Release(NCompress::NLZMA::CEncoder *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    ((void (__thiscall *)(NCompress::NLZMA::CEncoder *, int))this->dtr_CEncoder)(a1: this, a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BA930
// Name: public: virtual NCompress::NLZMA::CEncoder::~CEncoder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::~CEncoder(NCompress::NLZMA::CEncoder *this)
{
  ISequentialOutStream *p; // edi
  IMatchFinder *v3; // esi

  this->ICompressCoder::IUnknown::__vftable = (NCompress::NLZMA::CEncoder_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressCoder'};
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetOutStream'};
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetCoderProperties'};
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressWriteCoderProperties'};
  MyFree(address: this->_literalEncoder._coders);
  this->_literalEncoder._coders = nullptr;
  COutBuffer::Free(this: &this->_rangeEncoder.Stream);
  p = this->_rangeEncoder.Stream._stream._p;
  if ( p != nullptr )
    p->Release(this: this->_rangeEncoder.Stream._stream._p);
  v3 = this->_matchFinder._p;
  if ( v3 != nullptr )
    v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004BA9D0
// Name: private: long NCompress::NLZMA::CEncoder::GetOptimum(unsigned int,unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
HRESULT __userpurge NCompress::NLZMA::CEncoder::GetOptimum@<eax>(
        NCompress::NLZMA::CEncoder *this@<ecx>,
        IMatchFinder *a2@<esi>,
        unsigned int position,
        unsigned int *backRes,
        unsigned int *lenRes)
{
  unsigned int optimumCurrentIndex; // eax
  int v7; // ecx
  int v8; // edx
  char *v9; // ecx
  HRESULT result; // eax
  bool v11; // zf
  unsigned int v12; // edx
  const unsigned __int8 *v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // ecx
  const unsigned __int8 *v18; // edi
  unsigned int i; // ecx
  unsigned int v20; // eax
  bool v21; // cc
  unsigned int v22; // edi
  unsigned int numFastBytes; // ecx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned __int8 v26; // cl
  unsigned __int8 v27; // dl
  unsigned __int8 Index; // cl
  unsigned int posStateMask; // edi
  unsigned __int8 v30; // dl
  int numPrevBits; // eax
  unsigned int v32; // edi
  int v33; // edx
  unsigned __int8 v34; // cl
  unsigned int v35; // esi
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  unsigned int *p_Price; // ecx
  unsigned int v40; // esi
  unsigned int PureRepPrice; // eax
  unsigned int v42; // eax
  unsigned int *v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // eax
  unsigned int *j; // esi
  unsigned int PosLenPrice; // eax
  unsigned int v50; // eax
  unsigned int v51; // edx
  HRESULT (__stdcall *GetMatches)(IMatchFinder *, unsigned int *); // eax
  unsigned int v53; // esi
  unsigned int v54; // edi
  unsigned int v55; // edx
  int v56; // esi
  char *v57; // eax
  char v58; // dl
  int v59; // ecx
  int v60; // ecx
  unsigned __int8 v61; // cl
  unsigned int v62; // edi
  unsigned __int8 v63; // cl
  NCompress::NLZMA::COptimal *v64; // edx
  unsigned int v65; // esi
  unsigned int v66; // ecx
  unsigned int v67; // edx
  unsigned int v68; // edx
  unsigned int v69; // esi
  unsigned int v70; // ecx
  const unsigned __int8 *v71; // edi
  unsigned __int8 v72; // al
  unsigned __int8 v73; // dl
  unsigned int v74; // esi
  int v75; // eax
  unsigned int v76; // edx
  unsigned int v77; // esi
  unsigned int v78; // eax
  unsigned int v79; // esi
  NCompress::NLZMA::COptimal *v80; // eax
  unsigned int v81; // ecx
  unsigned int v82; // ecx
  unsigned int v83; // eax
  unsigned int v84; // ecx
  unsigned int v85; // ecx
  unsigned int v86; // ecx
  unsigned int v87; // ecx
  unsigned int v88; // eax
  unsigned int v89; // edi
  unsigned int v90; // edx
  unsigned int v91; // ecx
  unsigned int v92; // edx
  unsigned int v93; // esi
  unsigned int v94; // ecx
  unsigned int v95; // edi
  unsigned int *v96; // ecx
  unsigned int v97; // ecx
  NCompress::NLZMA::COptimal *v98; // eax
  unsigned int v99; // eax
  unsigned int v100; // eax
  const unsigned __int8 *v101; // ecx
  unsigned int k; // edi
  unsigned int v103; // eax
  unsigned int *v104; // ecx
  unsigned int v105; // esi
  unsigned int v106; // eax
  unsigned int v107; // eax
  unsigned int *v108; // ecx
  unsigned int v109; // edx
  unsigned int v110; // eax
  unsigned int v111; // ecx
  const unsigned __int8 *v112; // edi
  unsigned int v113; // eax
  unsigned int v114; // ecx
  int v115; // eax
  unsigned int v116; // edi
  unsigned int v117; // eax
  unsigned int v118; // eax
  unsigned int v119; // edx
  unsigned int v120; // ecx
  _DWORD *v121; // edi
  unsigned int v122; // ecx
  NCompress::NLZMA::COptimal *v123; // eax
  unsigned int v124; // edx
  unsigned int v125; // ecx
  unsigned int v126; // edx
  int v127; // eax
  unsigned int v128; // edi
  unsigned int v129; // eax
  unsigned int *v130; // edx
  unsigned int v131; // eax
  unsigned int v132; // eax
  unsigned int v133; // ecx
  int v134; // esi
  unsigned int *v135; // edx
  unsigned int v136; // edi
  unsigned int v137; // eax
  unsigned int v138; // eax
  unsigned int v139; // eax
  unsigned int v140; // ecx
  unsigned int v141; // eax
  unsigned int v142; // esi
  const unsigned __int8 *v143; // eax
  unsigned int v144; // eax
  unsigned int v145; // esi
  int v146; // edx
  unsigned __int8 v147; // cl
  int v148; // edi
  unsigned int Prob; // edx
  unsigned int v150; // esi
  int v151; // edi
  int v152; // eax
  unsigned int v153; // eax
  unsigned int v154; // eax
  unsigned int v155; // edx
  unsigned int v156; // ecx
  _DWORD *v157; // esi
  unsigned int v158; // ecx
  NCompress::NLZMA::COptimal *v159; // eax
  unsigned int v160; // edx
  unsigned int v161; // edx
  unsigned int v162; // ecx
  unsigned int v163; // eax
  unsigned int v164; // eax
  unsigned int v165; // eax
  IMatchFinder *p; // [esp-10h] [ebp-98h]
  unsigned __int8 v167; // [esp-Ch] [ebp-94h]
  unsigned __int8 v168; // [esp-Ch] [ebp-94h]
  unsigned int repLens[4]; // [esp+4h] [ebp-84h]
  unsigned int v171; // [esp+14h] [ebp-74h]
  unsigned int v172; // [esp+18h] [ebp-70h]
  unsigned int curAndLenPrice; // [esp+1Ch] [ebp-6Ch]
  unsigned __int8 matchByte[4]; // [esp+20h] [ebp-68h]
  int currentByte; // [esp+24h] [ebp-64h]
  unsigned int reps[4]; // [esp+28h] [ebp-60h] BYREF
  unsigned int price; // [esp+38h] [ebp-50h]
  unsigned int backOffset; // [esp+3Ch] [ebp-4Ch]
  unsigned int v179; // [esp+40h] [ebp-48h]
  unsigned int newLen; // [esp+44h] [ebp-44h]
  unsigned int lenTest2; // [esp+48h] [ebp-40h]
  unsigned int repMatchPrice; // [esp+4Ch] [ebp-3Ch]
  const unsigned __int8 *data; // [esp+50h] [ebp-38h]
  unsigned int normalMatchPrice; // [esp+54h] [ebp-34h]
  unsigned int numDistancePairs; // [esp+58h] [ebp-30h] BYREF
  unsigned int posState; // [esp+5Ch] [ebp-2Ch]
  unsigned int curPrice; // [esp+60h] [ebp-28h]
  unsigned int startLen; // [esp+64h] [ebp-24h]
  unsigned int offs; // [esp+68h] [ebp-20h]
  unsigned int state; // [esp+6Ch] [ebp-1Ch] OVERLAPPED
  bool nextIsChar; // [esp+73h] [ebp-15h]
  unsigned int lenEnd; // [esp+74h] [ebp-14h]
  unsigned int cur; // [esp+78h] [ebp-10h]
  unsigned int posSlot; // [esp+7Ch] [ebp-Ch] BYREF
  unsigned int repIndex; // [esp+80h] [ebp-8h]
  unsigned int curBack; // [esp+84h] [ebp-4h]

  optimumCurrentIndex = this->_optimumCurrentIndex;
  if ( this->_optimumEndIndex != optimumCurrentIndex )
  {
    v7 = 5 * optimumCurrentIndex + 5;
    v8 = *((_DWORD *)&this->_state.Index + 2 * v7);
    v9 = (char *)this + 8 * v7;
    *lenRes = v8 - optimumCurrentIndex;
    *backRes = *((_DWORD *)v9 + 5);
    this->_optimumCurrentIndex = *((_DWORD *)v9 + 4);
    return 0;
  }
  v11 = !this->_longestMatchWasFound;
  this->_optimumEndIndex = 0;
  this->_optimumCurrentIndex = 0;
  if ( v11 )
  {
    result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &posSlot, &numDistancePairs);
    if ( result != 0 )
      return result;
  }
  else
  {
    v12 = this->_numDistancePairs;
    posSlot = this->_longestMatchLength;
    numDistancePairs = v12;
    this->_longestMatchWasFound = false;
  }
  v13 = this->_matchFinder._p->GetPointerToCurrentPos(this: this->_matchFinder._p) - 1;
  v14 = this->_matchFinder._p->GetNumAvailableBytes(this: this->_matchFinder._p) + 1;
  curBack = v14;
  if ( v14 < 2 )
  {
LABEL_8:
    *backRes = -1;
    *lenRes = 1;
    return 0;
  }
  if ( v14 > 0x111 )
    curBack = 273;
  v15 = 0;
  offs = 0;
  repIndex = 0;
  curPrice = 0;
  do
  {
    v16 = v15;
    v17 = this->_repDistances[v15];
    reps[v15] = v17;
    v18 = &v13[-v17 - 1];
    if ( *v13 == *v18 && v13[1] == v13[-v17] )
    {
      for ( i = 2; i < curBack; ++i )
      {
        if ( v13[i] != v18[i] )
          break;
      }
      v20 = curPrice;
      repLens[v16] = i;
      v21 = i <= *(unsigned int *)((char *)repLens + v20);
      v15 = repIndex;
      if ( !v21 )
      {
        offs = repIndex;
        curPrice = v16 * 4;
      }
    }
    else
    {
      repLens[v15] = 0;
    }
    repIndex = ++v15;
  }
  while ( v15 < 4 );
  v22 = repLens[offs];
  numFastBytes = this->_numFastBytes;
  normalMatchPrice = v22;
  if ( v22 >= numFastBytes )
  {
    *backRes = offs;
    *lenRes = v22;
    if ( v22 != 1 )
    {
      this->_additionalOffset += v22 - 1;
      return this->_matchFinder._p->Skip(this: this->_matchFinder._p, a2: v22 - 1);
    }
    return 0;
  }
  v24 = posSlot;
  if ( posSlot >= numFastBytes )
  {
    *backRes = this->_matchDistances[numDistancePairs] + 4;
    *lenRes = v24;
    v25 = v24 - 1;
    if ( v25 != 0 )
    {
      this->_additionalOffset += v25;
      return this->_matchFinder._p->Skip(this: this->_matchFinder._p, a2: v25);
    }
    return 0;
  }
  v26 = *v13;
  LOBYTE(curPrice) = *v13;
  v27 = v13[-reps[0] - 1];
  LOBYTE(posState) = v27;
  if ( posSlot < 2 && v26 != v27 && v22 < 2 )
    goto LABEL_8;
  Index = this->_state.Index;
  posStateMask = this->_posStateMask;
  v30 = curPrice;
  this->_optimum[0].State.Index = Index;
  numPrevBits = this->_literalEncoder._numPrevBits;
  v167 = v30;
  v32 = position & posStateMask;
  v33 = this->_previousByte >> (8 - numPrevBits);
  repMatchPrice = position & this->_literalEncoder._posMask;
  this->_optimum[1].Price = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[this->_state.Index][v32].Prob >> 2]
                          + NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                              this: &this->_literalEncoder._coders[(repMatchPrice << numPrevBits) + v33],
                              matchMode: Index >= 7u,
                              matchByte: posState,
                              symbol: v167);
  this->_optimum[1].BackPrev = -1;
  this->_optimum[1].Prev1IsChar = false;
  v34 = this->_state.Index;
  v35 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[v34][v32].Prob) >> 2]
      + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v34].Prob) >> 2];
  startLen = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[v34][v32].Prob) >> 2];
  repMatchPrice = v35;
  if ( (_BYTE)posState == (_BYTE)curPrice )
  {
    v36 = v35
        + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[v34].Prob >> 2]
        + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep0Long[v34][v32].Prob >> 2];
    if ( v36 < this->_optimum[1].Price )
    {
      this->_optimum[1].Price = v36;
      this->_optimum[1].BackPrev = 0;
      this->_optimum[1].Prev1IsChar = false;
    }
  }
  v37 = normalMatchPrice;
  if ( posSlot < normalMatchPrice )
  {
    lenEnd = normalMatchPrice;
  }
  else
  {
    v37 = posSlot;
    lenEnd = posSlot;
  }
  if ( v37 < 2 )
  {
    *backRes = this->_optimum[1].BackPrev;
    *lenRes = 1;
    return 0;
  }
  v38 = reps[0];
  this->_optimum[1].PosPrev = 0;
  this->_optimum[0].Backs[0] = v38;
  this->_optimum[0].Backs[1] = reps[1];
  this->_optimum[0].Backs[2] = reps[2];
  this->_optimum[0].Backs[3] = reps[3];
  p_Price = &this->_optimum[v37].Price;
  do
  {
    *p_Price = 0xFFFFFFF;
    --v37;
    p_Price -= 10;
  }
  while ( v37 >= 2 );
  for ( repIndex = 0; repIndex < 4; ++repIndex )
  {
    v40 = repLens[repIndex];
    if ( v40 >= 2 )
    {
      PureRepPrice = NCompress::NLZMA::CEncoder::GetPureRepPrice(this, repIndex, state: this->_state, posState: v32);
      v42 = repMatchPrice + PureRepPrice;
      curBack = (unsigned int)&this->_repMatchLenEncoder._highCoder.Models[272 * v32 + 254 + v40];
      v43 = &this->_optimum[v40].Price;
      do
      {
        v44 = v42 + *(_DWORD *)curBack;
        if ( v44 < *v43 )
        {
          *v43 = v44;
          v45 = repIndex;
          v43[1] = 0;
          v43[2] = v45;
          *((_BYTE *)v43 - 11) = 0;
        }
        curBack -= 4;
        --v40;
        v43 -= 10;
      }
      while ( v40 >= 2 );
    }
  }
  repMatchPrice = startLen
                + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep[this->_state.Index].Prob >> 2];
  if ( repLens[0] < 2 )
    v46 = 2;
  else
    v46 = repLens[0] + 1;
  state = v46;
  if ( v46 <= posSlot )
  {
    v47 = 0;
    posSlot = 0;
    if ( state > this->_matchDistances[1] )
    {
      do
        v47 += 2;
      while ( state > this->_matchDistances[v47 + 1] );
      posSlot = v47;
    }
    for ( j = &this->_optimum[state].Price; ; j += 10 )
    {
      normalMatchPrice = this->_matchDistances[posSlot + 2];
      PosLenPrice = NCompress::NLZMA::CEncoder::GetPosLenPrice(this, pos: normalMatchPrice, len: state, posState: v32);
      v50 = repMatchPrice + PosLenPrice;
      if ( v50 < *j )
      {
        v51 = normalMatchPrice + 4;
        *j = v50;
        j[1] = 0;
        j[2] = v51;
        *((_BYTE *)j - 11) = 0;
      }
      if ( state == this->_matchDistances[posSlot + 1] )
      {
        posSlot += 2;
        if ( posSlot == numDistancePairs )
          break;
      }
      ++state;
    }
  }
  cur = 1;
  if ( lenEnd == 1 )
  {
LABEL_193:
    *lenRes = NCompress::NLZMA::CEncoder::Backward(this, backRes, cur);
    return 0;
  }
  while ( 1 )
  {
    p = this->_matchFinder._p;
    GetMatches = p->GetMatches;
    v53 = 0;
    newLen = 0;
    result = GetMatches(this: p, a2: this->_matchDistances);
    if ( result != 0 )
      return result;
    v54 = this->_matchDistances[0];
    repMatchPrice = v54;
    if ( v54 != 0 )
    {
      v53 = *(&this->_literalEncoder._posMask + v54);
      newLen = v53;
      if ( v53 == this->_numFastBytes )
      {
        v53 += this->_matchFinder._p->GetMatchLen(
                 this: this->_matchFinder._p,
                 a2: v53 - 1,
                 a3: this->_matchDistances[v54],
                 a4: 273 - v53);
        newLen = v53;
      }
    }
    ++this->_additionalOffset;
    if ( v53 >= this->_numFastBytes )
    {
      this->_numDistancePairs = v54;
      this->_longestMatchLength = v53;
      this->_longestMatchWasFound = true;
      goto LABEL_193;
    }
    ++position;
    v55 = 5 * cur + 5;
    v56 = *((_DWORD *)&this->_state.Index + 2 * v55);
    v57 = (char *)this + 8 * v55;
    v58 = v57[1];
    if ( v58 != 0 )
    {
      --v56;
      if ( v57[2] != 0 )
      {
        v59 = this->_optimum[*((_DWORD *)v57 + 1)].State.Index;
        if ( *((_DWORD *)v57 + 2) >= 4u )
          v60 = kMatchNextStates_0[v59];
        else
          v60 = kRepNextStates_0[v59];
        v61 = kLiteralNextStates_0[v60];
      }
      else
      {
        v61 = kLiteralNextStates_0[this->_optimum[v56].State.Index];
      }
    }
    else
    {
      v61 = this->_optimum[v56].State.Index;
    }
    if ( v56 == cur - 1 )
    {
      if ( *((_DWORD *)v57 + 5) != 0 )
        LOBYTE(state) = kLiteralNextStates_0[v61];
      else
        LOBYTE(state) = kShortRepNextStates_0[v61];
    }
    else
    {
      if ( v58 != 0 && v57[2] != 0 )
      {
        v62 = *((_DWORD *)v57 + 2);
        v56 = *((_DWORD *)v57 + 1);
        v63 = kRepNextStates_0[v61];
        posSlot = v62;
      }
      else
      {
        posSlot = *((_DWORD *)v57 + 5);
        v62 = posSlot;
        if ( posSlot >= 4 )
          v63 = kMatchNextStates_0[v61];
        else
          v63 = kRepNextStates_0[v61];
      }
      LOBYTE(state) = v63;
      v64 = &this->_optimum[v56];
      if ( v62 >= 4 )
      {
        reps[1] = v64->Backs[0];
        v66 = v64->Backs[1];
        v67 = v64->Backs[2];
        reps[0] = v62 - 4;
        reps[2] = v66;
        reps[3] = v67;
      }
      else
      {
        v65 = 1;
        reps[0] = v64->Backs[v62];
        if ( v62 == 0 || (qmemcpy(&reps[1], v64->Backs, 4 * v62), v65 = posSlot + 1, posSlot + 1 < 4) )
          qmemcpy(&reps[v65], &v64->Backs[v65], 4 * (4 - v65));
      }
    }
    v68 = reps[1];
    v69 = reps[0];
    *v57 = state;
    v70 = reps[2];
    *((_DWORD *)v57 + 7) = v68;
    *((_DWORD *)v57 + 9) = reps[3];
    *((_DWORD *)v57 + 6) = v69;
    *((_DWORD *)v57 + 8) = v70;
    curPrice = *((_DWORD *)v57 + 3);
    v71 = (const unsigned __int8 *)(((int (__stdcall *)(IMatchFinder *, IMatchFinder *))this->_matchFinder._p->GetPointerToCurrentPos)(
                                      a1: this->_matchFinder._p,
                                      a2)
                                  - 1);
    v72 = *v71;
    v73 = v71[-v69 - 1];
    v74 = position & this->_posStateMask;
    matchByte[0] = v73;
    numDistancePairs = (unsigned __int8)state;
    curBack = v74 + 16 * (unsigned __int8)state;
    LOBYTE(currentByte) = v72;
    v75 = this->_literalEncoder._numPrevBits;
    v168 = v73;
    v76 = *(v71 - 1);
    posState = v74;
    v77 = (position & this->_literalEncoder._posMask) << v75;
    data = v71;
    v78 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
            this: &this->_literalEncoder._coders[v77 + (v76 >> (8 - v75))],
            matchMode: (unsigned __int8)state >= 7u,
            matchByte: v168,
            symbol: currentByte);
    v79 = curPrice + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[0][curBack].Prob >> 2] + v78;
    v80 = &this->_optimum[cur + 1];
    nextIsChar = false;
    if ( v79 < v80->Price )
    {
      v81 = cur;
      v80->Price = v79;
      v80->PosPrev = v81;
      v80->BackPrev = -1;
      v80->Prev1IsChar = false;
      nextIsChar = true;
    }
    normalMatchPrice = curPrice
                     + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][curBack].Prob) >> 2];
    v172 = normalMatchPrice
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[numDistancePairs].Prob) >> 2];
    if ( matchByte[0] == (_BYTE)currentByte && (v80->PosPrev >= cur || v80->BackPrev != 0) )
    {
      v82 = v172
          + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[numDistancePairs].Prob >> 2]
          + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep0Long[0][curBack].Prob >> 2];
      if ( v82 <= v80->Price )
      {
        v80->Price = v82;
        v80->PosPrev = cur;
        v80->BackPrev = 0;
        v80->Prev1IsChar = false;
        nextIsChar = true;
      }
    }
    a2 = this->_matchFinder._p;
    v83 = ((int (*)(void))a2->GetNumAvailableBytes)() + 1;
    curPrice = v83;
    if ( 4095 - cur < v83 )
    {
      v83 = 4095 - cur;
      curPrice = 4095 - cur;
    }
    offs = v83;
    if ( v83 >= 2 )
    {
      v84 = this->_numFastBytes;
      if ( v83 > v84 )
        offs = this->_numFastBytes;
      if ( !nextIsChar && matchByte[0] != (_BYTE)currentByte )
      {
        v85 = v84 + 1;
        if ( v83 >= v85 )
        {
          v83 = v85;
          curBack = v85;
        }
        else
        {
          curBack = v83;
        }
        v86 = 1;
        if ( v83 > 1 )
        {
          do
          {
            if ( v71[v86] != v71[v86 - 1 - reps[0]] )
              break;
            ++v86;
          }
          while ( v86 < curBack );
        }
        curBack = v86 - 1;
        if ( v86 - 1 >= 2 )
        {
          v87 = kLiteralNextStates_0[numDistancePairs];
          v88 = this->_posStateMask & (position + 1);
          lenTest2 = v87;
          v89 = v88 + 16 * v87;
          v90 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v87].Prob) >> 2];
          v91 = 2048 - this->_isMatch[0][v89].Prob;
          v179 = v89;
          v92 = v79 + NCompress::NRangeCoder::CPriceTables::ProbPrices[v91 >> 2] + v90;
          v93 = curBack + cur + 1;
          v94 = lenEnd;
          if ( lenEnd < v93 )
          {
            startLen = (unsigned int)&this->_optimum[lenEnd].Price;
            v95 = v93 - lenEnd;
            lenEnd = curBack + cur + 1;
            v96 = &this->_optimum[v94].Price;
            do
            {
              v96 += 10;
              --v95;
              *v96 = 0xFFFFFFF;
            }
            while ( v95 != 0 );
            v89 = v179;
          }
          v97 = v92
              + this->_repMatchLenEncoder._highCoder.Models[272 * v88 + 254 + curBack].Prob
              + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[lenTest2].Prob >> 2]
              + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][v89].Prob) >> 2];
          v98 = &this->_optimum[v93];
          if ( v97 < v98->Price )
          {
            v98->Price = v97;
            v98->PosPrev = cur + 1;
            v98->BackPrev = 0;
            *(_WORD *)&v98->Prev1IsChar = 1;
          }
        }
      }
      repIndex = 0;
      v99 = 0;
      startLen = 2;
      do
      {
        v100 = reps[v99] + 1;
        v101 = &data[-v100];
        lenTest2 = v100;
        if ( *data == data[-v100] && data[1] == v101[1] )
        {
          for ( k = 2; k < offs; ++k )
          {
            if ( data[k] != v101[k] )
              break;
          }
          if ( lenEnd < k + cur )
          {
            v103 = k + cur - lenEnd;
            v104 = &this->_optimum[lenEnd].Price;
            lenEnd = k + cur;
            do
            {
              v104 += 10;
              --v103;
              *v104 = 0xFFFFFFF;
            }
            while ( v103 != 0 );
          }
          v105 = k;
          v106 = NCompress::NLZMA::CEncoder::GetPureRepPrice(this, repIndex, (NCompress::NLZMA::CState)state, posState);
          v107 = v172 + v106;
          v171 = 272 * posState;
          curBack = (unsigned int)&this->_repMatchLenEncoder._highCoder.Models[272 * posState + 254 + k];
          price = v107;
          v108 = &this->_optimum[k + cur].Price;
          do
          {
            v109 = v107 + *(_DWORD *)curBack;
            if ( v109 < *v108 )
            {
              *v108 = v109;
              v108[1] = cur;
              v108[2] = repIndex;
              *((_BYTE *)v108 - 11) = 0;
            }
            curBack -= 4;
            --k;
            v108 -= 10;
          }
          while ( k >= 2 );
          if ( repIndex == 0 )
            startLen = v105 + 1;
          v110 = v105 + 1;
          v111 = v105 + 1 + this->_numFastBytes;
          if ( curPrice < v111 )
            v111 = curPrice;
          if ( v110 < v111 )
          {
            v112 = &data[v110 - lenTest2];
            do
            {
              if ( data[v110] != *v112 )
                break;
              ++v110;
              ++v112;
            }
            while ( v110 < v111 );
          }
          v179 = -1 - v105 + v110;
          if ( v179 >= 2 )
          {
            v113 = this->_posStateMask;
            posSlot = kRepNextStates_0[numDistancePairs];
            curAndLenPrice = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[posSlot][(v105 + position) & v113].Prob >> 2];
            v114 = v113 & (v105 + position + 1);
            v115 = this->_literalEncoder._numPrevBits;
            posSlot = kLiteralNextStates_0[posSlot];
            v116 = this->_literalEncoder._posMask & (v105 + position);
            backOffset = v114;
            curBack = v114 + 16 * posSlot;
            v117 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                     this: &this->_literalEncoder._coders[(v116 << v115) + (data[v105 - 1] >> (8 - v115))],
                     matchMode: true,
                     matchByte: data[v105 - lenTest2],
                     symbol: data[v105]);
            v118 = price
                 + curAndLenPrice
                 + this->_repMatchLenEncoder._highCoder.Models[v105 + 254 + v171].Prob
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[posSlot].Prob) >> 2]
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][curBack].Prob) >> 2]
                 + v117;
            v119 = v105 + v179 + cur + 1;
            if ( lenEnd < v119 )
            {
              price = (unsigned int)&this->_optimum[lenEnd].Price;
              v120 = v119 - lenEnd;
              lenEnd = v105 + v179 + cur + 1;
              v121 = (_DWORD *)price;
              do
              {
                v121 += 10;
                --v120;
                *v121 = 0xFFFFFFF;
              }
              while ( v120 != 0 );
            }
            v122 = v118
                 + this->_repMatchLenEncoder._highCoder.Models[272 * backOffset + 254 + v179].Prob
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[posSlot].Prob >> 2]
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][curBack].Prob) >> 2];
            v123 = &this->_optimum[v119];
            if ( v122 < v123->Price )
            {
              v123->Price = v122;
              v124 = v105 + cur + 1;
              v123->PosPrev2 = cur;
              v125 = repIndex;
              v123->PosPrev = v124;
              v123->BackPrev = 0;
              *(_WORD *)&v123->Prev1IsChar = 257;
              v123->BackPrev2 = v125;
            }
          }
        }
        v99 = repIndex + 1;
        repIndex = v99;
      }
      while ( v99 < 4 );
      v126 = newLen;
      if ( newLen > offs )
      {
        v127 = 0;
        v126 = offs;
        if ( offs > this->_matchDistances[1] )
        {
          do
            v127 += 2;
          while ( offs > this->_matchDistances[v127 + 1] );
        }
        this->_matchDistances[v127 + 1] = offs;
        repMatchPrice = v127 + 2;
      }
      v128 = startLen;
      if ( v126 >= startLen )
      {
        normalMatchPrice += NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep[numDistancePairs].Prob >> 2];
        if ( lenEnd < v126 + cur )
        {
          v129 = v126 + cur - lenEnd;
          v130 = &this->_optimum[lenEnd].Price;
          lenEnd += v129;
          do
          {
            v130 += 10;
            --v129;
            *v130 = 0xFFFFFFF;
          }
          while ( v129 != 0 );
        }
        v131 = 0;
        offs = 0;
        if ( v128 > this->_matchDistances[1] )
        {
          do
            v131 += 2;
          while ( v128 > this->_matchDistances[v131 + 1] );
          offs = v131;
        }
        v132 = v131;
        v133 = this->_matchDistances[v132 + 2];
        startLen = v132 * 4;
        curBack = v133;
        if ( v133 >= 0x20000 )
        {
          if ( v133 >= 0x8000000 )
            v134 = NCompress::NLZMA::g_FastPos[v133 >> 26] + 52;
          else
            v134 = NCompress::NLZMA::g_FastPos[HIWORD(v133)] + 32;
        }
        else
        {
          v134 = NCompress::NLZMA::g_FastPos[v133 >> 6] + 12;
        }
        repIndex = v128 + 1;
        posState = (unsigned int)&this->_lenEncoder._highCoder.Models[272 * posState + 254 + v128];
        v135 = &this->_optimum[v128 + cur].Price;
        posSlot = v134;
        for ( newLen = (unsigned int)v135; ; v135 = (unsigned int *)newLen )
        {
          v136 = repIndex;
          v137 = repIndex - 3;
          if ( repIndex - 3 >= 4 )
            v137 = 3;
          if ( v133 >= 0x80 )
            v138 = this->_alignPrices[v133 & 0xF] + this->_posSlotPrices[v137][v134];
          else
            v138 = this->_distancesPrices[v137][v133];
          v139 = *(_DWORD *)posState + normalMatchPrice + v138;
          curAndLenPrice = v139;
          if ( v139 < *v135 )
          {
            *v135 = v139;
            v135[1] = cur;
            v135[2] = v133 + 4;
            *((_BYTE *)v135 - 11) = 0;
          }
          if ( v136 - 1 == *(unsigned int *)((char *)&this->_matchDistances[1] + startLen) )
          {
            v140 = curPrice;
            v141 = repIndex + this->_numFastBytes;
            backOffset = curBack + 1;
            v142 = repIndex;
            if ( curPrice >= v141 )
              v140 = v141;
            if ( repIndex < v140 )
            {
              v143 = &data[repIndex - (curBack + 1)];
              do
              {
                if ( data[v142] != *v143 )
                  break;
                ++v142;
                ++v143;
              }
              while ( v142 < v140 );
            }
            lenTest2 = -1 - (repIndex - 1) + v142;
            if ( lenTest2 >= 2 )
            {
              v144 = this->_posStateMask;
              v145 = position + repIndex - 1;
              v146 = kMatchNextStates_0[numDistancePairs];
              v147 = kLiteralNextStates_0[v146];
              v148 = v145 & v144;
              Prob = this->_isMatch[v146][v145 & v144].Prob;
              v179 = v147;
              price = NCompress::NRangeCoder::CPriceTables::ProbPrices[Prob >> 2];
              v150 = this->_literalEncoder._posMask & v145;
              v151 = v144 & (v148 + 1);
              v152 = this->_literalEncoder._numPrevBits;
              startLen = v151 + 16 * v147;
              v153 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                       this: &this->_literalEncoder._coders[(v150 << v152) + (data[repIndex - 2] >> (8 - v152))],
                       matchMode: true,
                       matchByte: data[repIndex - backOffset - 1],
                       symbol: data[repIndex - 1]);
              v154 = curAndLenPrice
                   + price
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][startLen].Prob) >> 2]
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v179].Prob) >> 2]
                   + v153;
              v155 = lenTest2 + repIndex + cur;
              if ( lenEnd < v155 )
              {
                backOffset = (unsigned int)&this->_optimum[lenEnd].Price;
                v156 = v155 - lenEnd;
                lenEnd = lenTest2 + repIndex + cur;
                v157 = (_DWORD *)backOffset;
                do
                {
                  v157 += 10;
                  --v156;
                  *v157 = 0xFFFFFFF;
                }
                while ( v156 != 0 );
              }
              v158 = v154
                   + this->_repMatchLenEncoder._highCoder.Models[272 * v151 + 254 + lenTest2].Prob
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[v179].Prob >> 2]
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][startLen].Prob) >> 2];
              v159 = &this->_optimum[v155];
              if ( v158 < v159->Price )
              {
                v160 = repIndex;
                v159->Price = v158;
                v161 = cur + v160;
                v159->PosPrev2 = cur;
                v162 = curBack + 4;
                v159->PosPrev = v161;
                v159->BackPrev = 0;
                *(_WORD *)&v159->Prev1IsChar = 257;
                v159->BackPrev2 = v162;
              }
            }
            v163 = offs + 2;
            offs = v163;
            if ( v163 == repMatchPrice )
              break;
            startLen = 4 * v163;
            v164 = this->_matchDistances[v163 + 2];
            curBack = v164;
            if ( v164 >= 0x80 )
            {
              if ( v164 >= 0x20000 )
              {
                if ( v164 >= 0x8000000 )
                  v165 = NCompress::NLZMA::g_FastPos[v164 >> 26] + 52;
                else
                  v165 = NCompress::NLZMA::g_FastPos[HIWORD(v164)] + 32;
              }
              else
              {
                v165 = NCompress::NLZMA::g_FastPos[v164 >> 6] + 12;
              }
              posSlot = v165;
            }
          }
          newLen += 40;
          posState += 4;
          ++repIndex;
          v134 = posSlot;
          v133 = curBack;
        }
      }
    }
    if ( ++cur == lenEnd )
      goto LABEL_193;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BBA70
// Name: private: void NCompress::NLZMA::CEncoder::WriteEndMarker(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::WriteEndMarker(NCompress::NLZMA::CEncoder *this, unsigned int posState)
{
  unsigned int Range; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v4; // edx
  int v5; // eax
  unsigned int v6; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v7; // eax
  unsigned int v8; // eax
  bool v10; // [esp+4h] [ebp-4h]

  if ( this->_writeEndMark )
  {
    Range = this->_rangeEncoder.Range;
    v4 = &this->_isMatch[this->_state.Index][posState];
    v5 = v4->Prob * (Range >> 11);
    this->_rangeEncoder.Low += (unsigned int)v5;
    this->_rangeEncoder.Range = Range - v5;
    v4->Prob -= v4->Prob >> 5;
    v6 = this->_rangeEncoder.Range;
    if ( v6 < 0x1000000 )
    {
      this->_rangeEncoder.Range = v6 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    v7 = &this->_isRep[this->_state.Index];
    this->_rangeEncoder.Range = v7->Prob * (this->_rangeEncoder.Range >> 11);
    v7->Prob += (2048 - v7->Prob) >> 5;
    v8 = this->_rangeEncoder.Range;
    if ( v8 < 0x1000000 )
    {
      this->_rangeEncoder.Range = v8 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    this->_state.Index = kMatchNextStates_0[this->_state.Index];
    v10 = !this->_fastMode;
    NCompress::NLZMA::NLength::CEncoder::Encode(
      this: &this->_lenEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0,
      posState);
    if ( v10 && this->_lenEncoder._counters[posState]-- == 1 )
    {
      NCompress::NLZMA::NLength::CEncoder::SetPrices(
        this: &this->_lenEncoder,
        posState,
        numSymbols: this->_lenEncoder._tableSize,
        prices: this->_lenEncoder._prices[posState]);
      this->_lenEncoder._counters[posState] = this->_lenEncoder._tableSize;
    }
    NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
      this: this->_posSlotEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0x3Fu);
    NCompress::NRangeCoder::CEncoder::EncodeDirectBits(this: &this->_rangeEncoder, value: 0x3FFFFFFu, numTotalBits: 26);
    NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
      this: &this->_posAlignEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0xFu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BBBC0
// Name: public: NBT2::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT2::CMatchFinder *__thiscall NBT2::CMatchFinder::CMatchFinder(NBT2::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT2::CMatchFinder_vtbl *)&NBT2::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT2::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT2::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BBBF0
// Name: public: long NCompress::NLZMA::CEncoder::Create(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Create(NCompress::NLZMA::CEncoder *this)
{
  HRESULT result; // eax
  NBT2::CMatchFinder *v3; // eax
  NBT3::CMatchFinder *v4; // eax
  IMatchFinderSetNumPasses *v5; // ecx
  NBT3::CMatchFinder *v6; // eax
  NBT4::CMatchFinder *v7; // eax
  NHC4::CMatchFinder *v8; // eax
  unsigned int dictionarySize; // ecx
  IMatchFinderSetNumPasses *setMfPasses; // ecx
  unsigned int numFastBytes; // edx

  if ( !COutBuffer::Create(this: &this->_rangeEncoder.Stream, bufferSize: 0x100000u) )
    return -2147024882;
  if ( this->_matchFinder._p == nullptr )
  {
    switch ( this->_matchFinderIndex )
    {
      case 0:
        v3 = (NBT2::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v3 == nullptr )
          goto LABEL_15;
        v4 = (NBT3::CMatchFinder *)NBT2::CMatchFinder::CMatchFinder(this: v3);
        goto LABEL_7;
      case 1:
        v6 = (NBT3::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v6 == nullptr )
          goto LABEL_15;
        v4 = NBT3::CMatchFinder::CMatchFinder(this: v6);
        goto LABEL_7;
      case 2:
        v7 = (NBT4::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v7 == nullptr )
          goto LABEL_15;
        v4 = (NBT3::CMatchFinder *)NBT4::CMatchFinder::CMatchFinder(this: v7);
        goto LABEL_7;
      case 3:
        v8 = (NHC4::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v8 != nullptr )
        {
          v4 = (NBT3::CMatchFinder *)NHC4::CMatchFinder::CMatchFinder(this: v8);
LABEL_7:
          if ( v4 != nullptr )
          {
            v5 = &v4->IMatchFinderSetNumPasses;
            goto LABEL_17;
          }
        }
        else
        {
LABEL_15:
          v4 = nullptr;
        }
        v5 = nullptr;
LABEL_17:
        this->setMfPasses = v5;
        CMyComPtr<IMatchFinder>::operator=(this: &this->_matchFinder, p: v4);
LABEL_18:
        if ( this->_matchFinder._p != nullptr )
          break;
        return -2147024882;
      default:
        goto LABEL_18;
    }
  }
  if ( !NCompress::NLZMA::CLiteralEncoder::Create(
          this: &this->_literalEncoder,
          numPosBits: this->_numLiteralPosStateBits,
          numPrevBits: this->_numLiteralContextBits) )
    return -2147024882;
  dictionarySize = this->_dictionarySize;
  if ( dictionarySize != this->_dictionarySizePrev || this->_numFastBytesPrev != this->_numFastBytes )
  {
    result = this->_matchFinder._p->Create(
               this: this->_matchFinder._p,
               a2: dictionarySize,
               a3: 4096u,
               a4: this->_numFastBytes,
               a5: 274u);
    if ( result != 0 )
      return result;
    if ( this->_matchFinderCycles != 0 )
    {
      setMfPasses = this->setMfPasses;
      if ( setMfPasses != nullptr )
        setMfPasses->SetNumPasses(this: setMfPasses, a2: this->_matchFinderCycles);
    }
    numFastBytes = this->_numFastBytes;
    this->_dictionarySizePrev = this->_dictionarySize;
    this->_numFastBytesPrev = numFastBytes;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BBD70
// Name: private: long NCompress::NLZMA::CEncoder::Flush(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Flush(NCompress::NLZMA::CEncoder *this, unsigned int nowPos)
{
  IMatchFinder *p; // eax

  p = this->_matchFinder._p;
  if ( p != nullptr && this->_needReleaseMFStream )
  {
    p->ReleaseStream(this: p);
    this->_needReleaseMFStream = false;
  }
  NCompress::NLZMA::CEncoder::WriteEndMarker(this, posState: nowPos & this->_posStateMask);
  NCompress::NRangeCoder::CEncoder::FlushData(this: &this->_rangeEncoder);
  return COutBuffer::Flush(this: &this->_rangeEncoder.Stream);
}

//------------------------------------------------------------------------------
// Address: 0x004BBDD0
// Name: public: long NCompress::NLZMA::CEncoder::SetStreams(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::SetStreams(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize)
{
  HRESULT result; // eax
  unsigned int v7; // edx

  this->_inStream = inStream;
  this->_finished = false;
  result = NCompress::NLZMA::CEncoder::Create(this);
  if ( result == 0 )
  {
    result = this->SetOutStream(this: &this->ICompressSetOutStream, a2: outStream);
    if ( result == 0 )
    {
      result = NCompress::NLZMA::CEncoder::Init(this);
      if ( result == 0 )
      {
        if ( !this->_fastMode )
        {
          NCompress::NLZMA::CEncoder::FillDistancesPrices(this);
          NCompress::NLZMA::CEncoder::FillAlignPrices(this);
        }
        this->_lenEncoder._tableSize = this->_numFastBytes - 1;
        NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(
          this: &this->_lenEncoder,
          numPosStates: 1 << this->_posStateBits);
        v7 = 1 << this->_posStateBits;
        this->_repMatchLenEncoder._tableSize = this->_numFastBytes - 1;
        NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(this: &this->_repMatchLenEncoder, numPosStates: v7);
        LODWORD(this->nowPos64) = 0;
        HIDWORD(this->nowPos64) = 0;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BBEA0
// Name: public: long NCompress::NLZMA::CEncoder::CodeOneBlock(unsigned __int64 __near *,unsigned __int64 __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::CodeOneBlock(
        NCompress::NLZMA::CEncoder *this,
        unsigned __int64 *inSize,
        unsigned __int64 *outSize,
        int *finished)
{
  ISequentialInStream *inStream; // ecx
  unsigned int result; // eax
  bool v7; // zf
  int v8; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v9; // eax
  unsigned int Range; // eax
  unsigned __int8 v11; // al
  unsigned __int8 previousByte; // dl
  unsigned __int8 v13; // bl
  NCompress::NLZMA::CLiteralEncoder2 *SubCoder; // eax
  bool v15; // cf
  unsigned int nowPos64; // edi
  unsigned int (__stdcall *GetNumAvailableBytes)(IInWindowStream *); // edx
  unsigned int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // eax
  unsigned __int8 v21; // al
  unsigned int v22; // edi
  unsigned int v23; // edx
  NCompress::NLZMA::CLiteralEncoder2 *v24; // edi
  unsigned __int8 v25; // dl
  unsigned int v26; // ebx
  NCompress::NRangeCoder::CBitEncoder<5> *v27; // edx
  unsigned int v28; // ecx
  int v29; // eax
  unsigned int v30; // eax
  int Index; // edx
  unsigned int v32; // ecx
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v36; // eax
  unsigned int v37; // eax
  int v38; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v39; // edx
  int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v43; // eax
  unsigned int v44; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v45; // edx
  int v46; // eax
  unsigned int v47; // eax
  unsigned int v48; // ebx
  unsigned int v49; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // edx
  unsigned int v53; // eax
  unsigned int v54; // eax
  unsigned int v55; // eax
  unsigned int v56; // ebx
  unsigned int v57; // eax
  int v58; // eax
  unsigned int v59; // edx
  unsigned int v60; // eax
  unsigned int v61; // ecx
  unsigned int v62; // edx
  unsigned int additionalOffset; // eax
  unsigned int v64; // edi
  int v65; // edx
  unsigned __int8 v66; // [esp-Ch] [ebp-34h]
  IMatchFinder *p; // [esp-Ch] [ebp-34h]
  unsigned int numDistancePairs; // [esp+4h] [ebp-24h] BYREF
  unsigned int posReduced; // [esp+8h] [ebp-20h] BYREF
  int matchByte; // [esp+Ch] [ebp-1Ch]
  int curByte; // [esp+10h] [ebp-18h]
  unsigned int nowPos32; // [esp+14h] [ebp-14h]
  unsigned int posState; // [esp+18h] [ebp-10h]
  unsigned int lenRes; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned int pos; // [esp+20h] [ebp-8h] BYREF
  bool v76; // [esp+24h] [ebp-4h]

  inStream = this->_inStream;
  if ( inStream != nullptr )
  {
    result = this->_matchFinder._p->SetStream(this: this->_matchFinder._p, a2: inStream);
    if ( result != 0 )
      return result;
    result = this->_matchFinder._p->Init(this: this->_matchFinder._p);
    if ( result != 0 )
      return result;
    this->_needReleaseMFStream = true;
    this->_inStream = nullptr;
  }
  *finished = 1;
  if ( this->_finished )
    return 0;
  v8 = HIDWORD(this->nowPos64) | LODWORD(this->nowPos64);
  v7 = this->nowPos64 == 0;
  this->_finished = true;
  if ( !v7 )
    goto LABEL_14;
  if ( ((int (__thiscall *)(int, IMatchFinder *))this->_matchFinder._p->GetNumAvailableBytes)(
         a1: v8,
         a2: this->_matchFinder._p) == 0 )
    return NCompress::NLZMA::CEncoder::Flush(this, nowPos: this->nowPos64);
  result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &posReduced, &numDistancePairs);
  if ( result == 0 )
  {
    v9 = &this->_isMatch[this->_state.Index][this->nowPos64 & this->_posStateMask];
    this->_rangeEncoder.Range = v9->Prob * (this->_rangeEncoder.Range >> 11);
    v9->Prob += (2048 - v9->Prob) >> 5;
    Range = this->_rangeEncoder.Range;
    if ( Range < 0x1000000 )
    {
      this->_rangeEncoder.Range = Range << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    this->_state.Index = kLiteralNextStates_0[this->_state.Index];
    v11 = this->_matchFinder._p->GetIndexByte(this: this->_matchFinder._p, a2: -this->_additionalOffset);
    previousByte = this->_previousByte;
    v13 = v11;
    LOBYTE(curByte) = v11;
    v66 = v11;
    SubCoder = NCompress::NLZMA::CLiteralEncoder::GetSubCoder(
                 this: &this->_literalEncoder,
                 pos: this->nowPos64,
                 prevByte: previousByte);
    NCompress::NLZMA::CLiteralEncoder2::Encode(this: SubCoder, rangeEncoder: &this->_rangeEncoder, symbol: v66);
    --this->_additionalOffset;
    v15 = __CFADD__(LODWORD(this->nowPos64)++, 1);
    this->_previousByte = v13;
    HIDWORD(this->nowPos64) += v15;
LABEL_14:
    nowPos64 = this->nowPos64;
    GetNumAvailableBytes = this->_matchFinder._p->GetNumAvailableBytes;
    p = this->_matchFinder._p;
    nowPos32 = nowPos64;
    numDistancePairs = nowPos64;
    if ( GetNumAvailableBytes(this: p) != 0 )
    {
      if ( this->_rangeEncoder.Stream.ErrorCode != 0 )
      {
        return this->_rangeEncoder.Stream.ErrorCode;
      }
      else
      {
        while ( 1 )
        {
          result = this->_fastMode
                 ? NCompress::NLZMA::CEncoder::GetOptimumFast(this, position: nowPos64, backRes: &pos, &lenRes)
                 : NCompress::NLZMA::CEncoder::GetOptimum(
                     this,
                     a2: (IMatchFinder *)this,
                     position: nowPos64,
                     backRes: &pos,
                     &lenRes);
          if ( result != 0 )
            break;
          v18 = nowPos64 & this->_posStateMask;
          posState = v18;
          if ( lenRes == 1 && pos == -1 )
          {
            v19 = v18 + 16 * this->_state.Index;
            this->_rangeEncoder.Range = this->_isMatch[0][v19].Prob * (this->_rangeEncoder.Range >> 11);
            this->_isMatch[0][v19].Prob += (2048 - this->_isMatch[0][v19].Prob) >> 5;
            v20 = this->_rangeEncoder.Range;
            if ( v20 < 0x1000000 )
            {
              this->_rangeEncoder.Range = v20 << 8;
              NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
            }
            v21 = this->_matchFinder._p->GetIndexByte(this: this->_matchFinder._p, a2: -this->_additionalOffset);
            v22 = this->_previousByte;
            v23 = nowPos32 & this->_literalEncoder._posMask;
            LOBYTE(curByte) = v21;
            v24 = &this->_literalEncoder._coders[(v23 << this->_literalEncoder._numPrevBits)
                                               + (v22 >> (8 - this->_literalEncoder._numPrevBits))];
            if ( this->_state.Index >= 7u )
            {
              LOBYTE(matchByte) = this->_matchFinder._p->GetIndexByte(
                                    this: this->_matchFinder._p,
                                    a2: -1 - this->_repDistances[0] - this->_additionalOffset);
              NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(
                this: v24,
                rangeEncoder: &this->_rangeEncoder,
                matchByte,
                symbol: curByte);
            }
            else
            {
              NCompress::NLZMA::CLiteralEncoder2::Encode(this: v24, rangeEncoder: &this->_rangeEncoder, symbol: curByte);
            }
            v25 = curByte;
            v26 = lenRes;
            this->_state.Index = kLiteralNextStates_0[this->_state.Index];
            this->_previousByte = v25;
          }
          else
          {
            v27 = &this->_isMatch[this->_state.Index][v18];
            v28 = this->_rangeEncoder.Range;
            v29 = v27->Prob * (v28 >> 11);
            v15 = __CFADD__(v29, this->_rangeEncoder.Low);
            LODWORD(this->_rangeEncoder.Low) += v29;
            HIDWORD(this->_rangeEncoder.Low) += v15;
            this->_rangeEncoder.Range = v28 - v29;
            v27->Prob -= v27->Prob >> 5;
            v30 = this->_rangeEncoder.Range;
            if ( v30 < 0x1000000 )
            {
              this->_rangeEncoder.Range = v30 << 8;
              NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
            }
            if ( pos >= 4 )
            {
              v50 = &this->_isRep[this->_state.Index];
              this->_rangeEncoder.Range = v50->Prob * (this->_rangeEncoder.Range >> 11);
              v50->Prob += (2048 - v50->Prob) >> 5;
              v51 = this->_rangeEncoder.Range;
              if ( v51 < 0x1000000 )
              {
                this->_rangeEncoder.Range = v51 << 8;
                NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
              }
              v52 = posState;
              v53 = lenRes;
              this->_state.Index = kMatchNextStates_0[this->_state.Index];
              v76 = !this->_fastMode;
              NCompress::NLZMA::NLength::CEncoder::Encode(
                this: &this->_lenEncoder,
                rangeEncoder: &this->_rangeEncoder,
                symbol: v53 - 2,
                posState: v52);
              if ( v76 )
              {
                v54 = posState;
                v7 = this->_lenEncoder._counters[posState]-- == 1;
                if ( v7 )
                {
                  NCompress::NLZMA::NLength::CEncoder::SetPrices(
                    this: &this->_lenEncoder,
                    posState: v54,
                    numSymbols: this->_lenEncoder._tableSize,
                    prices: this->_lenEncoder._prices[v54]);
                  this->_lenEncoder._counters[posState] = this->_lenEncoder._tableSize;
                }
              }
              v55 = pos - 4;
              pos = v55;
              if ( v55 >= 0x800 )
              {
                if ( v55 >= 0x200000 )
                  v56 = NCompress::NLZMA::g_FastPos[v55 >> 20] + 40;
                else
                  v56 = NCompress::NLZMA::g_FastPos[v55 >> 10] + 20;
              }
              else
              {
                v56 = NCompress::NLZMA::g_FastPos[v55];
              }
              v57 = lenRes - 2;
              if ( lenRes - 2 >= 4 )
                v57 = 3;
              NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
                this: &this->_posSlotEncoder[v57],
                rangeEncoder: &this->_rangeEncoder,
                symbol: v56);
              if ( v56 >= 4 )
              {
                v58 = (v56 & 1 | 2) << ((v56 >> 1) - 1);
                posReduced = pos - v58;
                if ( v56 >= 0xE )
                {
                  NCompress::NRangeCoder::CEncoder::EncodeDirectBits(
                    this: &this->_rangeEncoder,
                    value: (pos - v58) >> 4,
                    numTotalBits: (v56 >> 1) - 5);
                  NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
                    this: &this->_posAlignEncoder,
                    rangeEncoder: &this->_rangeEncoder,
                    symbol: posReduced & 0xF);
                  ++this->_alignPriceCount;
                }
                else
                {
                  NCompress::NRangeCoder::ReverseBitTreeEncode<5>(
                    Models: &this->_posSlotEncoder[3].Models[v58 - v56 + 63],
                    rangeEncoder: &this->_rangeEncoder,
                    NumBitLevels: (v56 >> 1) - 1,
                    symbol: pos - v58);
                }
              }
              v59 = this->_repDistances[2];
              v60 = this->_repDistances[1];
              v61 = this->_repDistances[0];
              ++this->_matchPriceCount;
              v26 = lenRes;
              this->_repDistances[3] = v59;
              v62 = pos;
              this->_repDistances[2] = v60;
              this->_repDistances[1] = v61;
              this->_repDistances[0] = v62;
            }
            else
            {
              Index = this->_state.Index;
              v32 = this->_rangeEncoder.Range;
              v33 = this->_isRep[Index].Prob * (v32 >> 11);
              v15 = __CFADD__(v33, this->_rangeEncoder.Low);
              LODWORD(this->_rangeEncoder.Low) += v33;
              HIDWORD(this->_rangeEncoder.Low) += v15;
              this->_rangeEncoder.Range = v32 - v33;
              this->_isRep[Index].Prob -= this->_isRep[Index].Prob >> 5;
              v34 = this->_rangeEncoder.Range;
              if ( v34 < 0x1000000 )
              {
                this->_rangeEncoder.Range = v34 << 8;
                NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
              }
              v35 = this->_rangeEncoder.Range;
              if ( pos != 0 )
              {
                v38 = this->_state.Index;
                posReduced = this->_repDistances[pos];
                v39 = &this->_isRepG0[v38];
                v40 = v39->Prob * (v35 >> 11);
                this->_rangeEncoder.Low += (unsigned int)v40;
                this->_rangeEncoder.Range = v35 - v40;
                v39->Prob -= v39->Prob >> 5;
                v41 = this->_rangeEncoder.Range;
                if ( v41 < 0x1000000 )
                {
                  this->_rangeEncoder.Range = v41 << 8;
                  NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                }
                v42 = this->_rangeEncoder.Range;
                if ( pos == 1 )
                {
                  v43 = &this->_isRepG1[this->_state.Index];
                  this->_rangeEncoder.Range = v43->Prob * (v42 >> 11);
                  v43->Prob += (2048 - v43->Prob) >> 5;
                  v44 = this->_rangeEncoder.Range;
                  if ( v44 < 0x1000000 )
                  {
                    this->_rangeEncoder.Range = v44 << 8;
                    NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                  }
                }
                else
                {
                  v45 = &this->_isRepG1[this->_state.Index];
                  v46 = v45->Prob * (v42 >> 11);
                  this->_rangeEncoder.Low += (unsigned int)v46;
                  this->_rangeEncoder.Range = v42 - v46;
                  v45->Prob -= v45->Prob >> 5;
                  v47 = this->_rangeEncoder.Range;
                  if ( v47 < 0x1000000 )
                  {
                    this->_rangeEncoder.Range = v47 << 8;
                    NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                  }
                  v48 = pos;
                  NCompress::NRangeCoder::CBitEncoder<5>::Encode(
                    this: &this->_isRepG2[this->_state.Index],
                    encoder: &this->_rangeEncoder,
                    symbol: pos - 2);
                  if ( v48 == 3 )
                    this->_repDistances[3] = this->_repDistances[2];
                  this->_repDistances[2] = this->_repDistances[1];
                }
                v49 = posReduced;
                v26 = lenRes;
                this->_repDistances[1] = this->_repDistances[0];
                this->_repDistances[0] = v49;
              }
              else
              {
                v36 = &this->_isRepG0[this->_state.Index];
                this->_rangeEncoder.Range = v36->Prob * (v35 >> 11);
                v36->Prob += (2048 - v36->Prob) >> 5;
                v37 = this->_rangeEncoder.Range;
                if ( v37 < 0x1000000 )
                {
                  this->_rangeEncoder.Range = v37 << 8;
                  NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                }
                v26 = lenRes;
                NCompress::NRangeCoder::CBitEncoder<5>::Encode(
                  this: &this->_isRep0Long[this->_state.Index][posState],
                  encoder: &this->_rangeEncoder,
                  symbol: lenRes != 1);
              }
              if ( v26 == 1 )
              {
                this->_state.Index = kShortRepNextStates_0[this->_state.Index];
              }
              else
              {
                NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(
                  this: &this->_repMatchLenEncoder,
                  rangeEncoder: &this->_rangeEncoder,
                  symbol: v26 - 2,
                  posState,
                  updatePrice: !this->_fastMode);
                this->_state.Index = kRepNextStates_0[this->_state.Index];
              }
            }
            this->_previousByte = this->_matchFinder._p->GetIndexByte(
                                    this: this->_matchFinder._p,
                                    a2: v26 - this->_additionalOffset - 1);
          }
          this->_additionalOffset -= v26;
          additionalOffset = this->_additionalOffset;
          nowPos64 = v26 + nowPos32;
          nowPos32 += v26;
          if ( additionalOffset == 0 )
          {
            if ( !this->_fastMode )
            {
              if ( this->_matchPriceCount >= 0x80 )
                NCompress::NLZMA::CEncoder::FillDistancesPrices(this);
              if ( this->_alignPriceCount >= 0x10 )
                NCompress::NLZMA::CEncoder::FillAlignPrices(this);
            }
            if ( this->_matchFinder._p->GetNumAvailableBytes(this: this->_matchFinder._p) == 0 )
              return NCompress::NLZMA::CEncoder::Flush(this, nowPos: nowPos64);
            if ( nowPos64 - numDistancePairs >= 0x4000 )
            {
              v64 = nowPos64 - numDistancePairs;
              v15 = __CFADD__(v64, this->nowPos64);
              LODWORD(this->nowPos64) += v64;
              v65 = this->nowPos64;
              HIDWORD(this->nowPos64) += v15;
              *(_DWORD *)inSize = v65;
              *((_DWORD *)inSize + 1) = HIDWORD(this->nowPos64);
              *outSize = NCompress::NRangeCoder::CEncoder::GetProcessedSize(this: &this->_rangeEncoder);
              this->_finished = false;
              *finished = 0;
              return 0;
            }
          }
          if ( this->_rangeEncoder.Stream.ErrorCode != 0 )
            return this->_rangeEncoder.Stream.ErrorCode;
          nowPos64 = nowPos32;
        }
      }
    }
    else
    {
      return NCompress::NLZMA::CEncoder::Flush(this, nowPos: nowPos64);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BC6A0
// Name: public: long NCompress::NLZMA::CEncoder::CodeReal(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *,struct ICompressProgressInfo __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::CodeReal(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize,
        ICompressProgressInfo *progress)
{
  HRESULT v7; // edi
  IMatchFinder *p; // eax
  unsigned int v10; // edi
  ICompressProgressInfo *v11; // ebx
  const unsigned __int64 *v12; // [esp-4h] [ebp-20h]
  unsigned __int64 processedInSize; // [esp+8h] [ebp-14h] BYREF
  unsigned __int64 processedOutSize; // [esp+10h] [ebp-Ch] BYREF
  NCompress::NLZMA::CEncoder::CCoderReleaser coderReleaser; // [esp+18h] [ebp-4h] BYREF

  v12 = outSize;
  this->_needReleaseMFStream = false;
  coderReleaser._coder = this;
  v7 = NCompress::NLZMA::CEncoder::SetStreams(this, inStream, outStream, inSize, outSize: v12);
  if ( v7 != 0 )
  {
    p = this->_matchFinder._p;
    if ( p != nullptr && this->_needReleaseMFStream )
    {
      p->ReleaseStream(this: this->_matchFinder._p);
      this->_needReleaseMFStream = false;
    }
    this->ReleaseOutStream(this: &this->ICompressSetOutStream);
    return v7;
  }
  else
  {
    v10 = NCompress::NLZMA::CEncoder::CodeOneBlock(
            this,
            inSize: &processedInSize,
            outSize: &processedOutSize,
            finished: (int *)&outSize);
    if ( v10 != 0 )
    {
LABEL_12:
      NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(this: &coderReleaser);
      return v10;
    }
    else
    {
      v11 = progress;
      while ( outSize == nullptr )
      {
        if ( v11 == nullptr || (v10 = v11->SetRatioInfo(this: v11, a2: &processedInSize, a3: &processedOutSize)) == 0 )
        {
          v10 = NCompress::NLZMA::CEncoder::CodeOneBlock(
                  this,
                  inSize: &processedInSize,
                  outSize: &processedOutSize,
                  finished: (int *)&outSize);
          if ( v10 == 0 )
            continue;
        }
        goto LABEL_12;
      }
      NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(this: &coderReleaser);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BC790
// Name: public: virtual long NCompress::NLZMA::CEncoder::Code(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *,struct ICompressProgressInfo __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::Code(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize,
        ICompressProgressInfo *progress)
{
  return NCompress::NLZMA::CEncoder::CodeReal(this, inStream, outStream, inSize, outSize, progress);
}

} // namespace hlfaceposer

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00435BB0
// Name: public: long CStreamEncoder::Encode(long,long,long __near *,unsigned char __near * __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CStreamEncoder::Encode(
        CStreamEncoder *this,
        int cbSrc,
        int cbYield,
        int *pcbSrcUsed,
        unsigned __int8 **ppDst,
        int *pcbDstUsed)
{
  tagPERFTIMERINFO *m_pPerfTimerInfo; // ecx
  int cbReconUsed; // [esp+14h] [ebp-30h] BYREF
  unsigned __int16 cDuration; // [esp+18h] [ebp-2Ch] BYREF
  HRESULT hr; // [esp+1Ch] [ebp-28h]
  int cbDstUsed; // [esp+20h] [ebp-24h] BYREF
  unsigned int ulOutputDuration[32]; // [esp+24h] [ebp-20h] BYREF

  cbDstUsed = 0;
  cbReconUsed = 0;
  if ( cbYield != cbSrc )
  {
    cbSrc = cbYield;
    this->m_cbSourceBytesLeft = cbYield;
  }
  if ( this->m_pPerfTimerInfo != nullptr )
    PerfTimerStart(pInfo: this->m_pPerfTimerInfo);
  hr = auencEncode(
         pauenc: this->m_pauenc,
         pbSrc: this->m_pbSrc,
         cbSrcLength: cbSrc,
         cbUnused: 0,
         pcbSrcUsed,
         pbDst: this->m_pbDst,
         cbDstLength: this->m_cbDstBufLength,
         pcbDstUsed: &cbDstUsed,
         pbRecon: nullptr,
         cbReconLength: 0,
         pcbReconUsed: &cbReconUsed,
         pulDuration: ulOutputDuration,
         cDurationLength: 0x20u,
         pcDurationUsed: &cDuration);
  if ( hr >= 0 )
  {
    if ( cbDstUsed != 0 )
      hr = CStreamEncoder::ProcessSampleInfo(this, adwDuration: ulOutputDuration, dwEntries: cDuration);
    if ( hr >= 0 )
    {
      m_pPerfTimerInfo = this->m_pPerfTimerInfo;
      if ( m_pPerfTimerInfo != nullptr )
        PerfTimerStop(pInfo: m_pPerfTimerInfo, lSamplesDecoded: 0 / this->m_wfx.Format.wBitsPerSample);
      *ppDst = this->m_pbDst;
      *pcbDstUsed = cbDstUsed;
      this->m_cbSourceBytesLeft -= *pcbSrcUsed;
    }
  }
  return hr;
}

//------------------------------------------------------------------------------
// Address: 0x005206E0
// Name: public: void NCompress::NRangeCoder::CEncoder::ShiftLow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::ShiftLow(NCompress::NRangeCoder::CEncoder *this)
{
  unsigned int Low; // esi
  unsigned __int8 cache; // bl

  Low = this->Low;
  if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
  {
    cache = this->_cache;
    do
    {
      this->Stream._buffer[this->Stream._pos] = cache + HIDWORD(this->Low);
      if ( ++this->Stream._pos == this->Stream._limitPos )
        COutBuffer::FlushWithCheck(this: &this->Stream);
      cache = -1;
    }
    while ( this->_cacheSize-- != 1 );
    Low = this->Low;
    this->_cache = HIBYTE(Low);
  }
  ++this->_cacheSize;
  LODWORD(this->Low) = Low << 8;
  HIDWORD(this->Low) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00520760
// Name: public: void NCompress::NRangeCoder::CEncoder::EncodeDirectBits(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::EncodeDirectBits(
        NCompress::NRangeCoder::CEncoder *this,
        unsigned int value,
        int numTotalBits)
{
  bool v3; // sf
  int v4; // ebx
  unsigned int Range; // eax
  unsigned int Low; // edi
  unsigned __int8 cache; // bl
  int i; // [esp+14h] [ebp+Ch]

  v4 = numTotalBits - 1;
  v3 = numTotalBits - 1 < 0;
  i = numTotalBits - 1;
  if ( !v3 )
  {
    do
    {
      this->Range >>= 1;
      Range = this->Range;
      if ( ((value >> v4) & 1) != 0 )
        this->Low += Range;
      if ( Range < 0x1000000 )
      {
        Low = this->Low;
        this->Range = Range << 8;
        if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
        {
          cache = this->_cache;
          do
          {
            this->Stream._buffer[this->Stream._pos++] = cache + HIDWORD(this->Low);
            if ( this->Stream._pos == this->Stream._limitPos )
              COutBuffer::FlushWithCheck(this: &this->Stream);
            cache = -1;
          }
          while ( this->_cacheSize-- != 1 );
          Low = this->Low;
          v4 = i;
          this->_cache = HIBYTE(Low);
        }
        ++this->_cacheSize;
        LODWORD(this->Low) = Low << 8;
        HIDWORD(this->Low) = 0;
      }
      i = --v4;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520820
// Name: public: unsigned __int64 NCompress::NRangeCoder::CEncoder::GetProcessedSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall NCompress::NRangeCoder::CEncoder::GetProcessedSize(NCompress::NRangeCoder::CEncoder *this)
{
  return this->_cacheSize + COutBuffer::GetProcessedSize(this: &this->Stream) + 4;
}

//------------------------------------------------------------------------------
// Address: 0x00520840
// Name: public: bool NCompress::NLZMA::CLiteralEncoder::Create(int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NCompress::NLZMA::CLiteralEncoder::Create(
        NCompress::NLZMA::CLiteralEncoder *this,
        int numPosBits,
        int numPrevBits)
{
  bool v4; // zf

  if ( this->_coders == nullptr || numPosBits + numPrevBits != this->_numPrevBits + this->_numPosBits )
  {
    MyFree(address: this->_coders);
    this->_coders = nullptr;
    this->_coders = (NCompress::NLZMA::CLiteralEncoder2 *)MyAlloc(size: 3072 * (1 << (numPosBits + numPrevBits)));
  }
  this->_numPosBits = numPosBits;
  v4 = this->_coders == nullptr;
  this->_numPrevBits = numPrevBits;
  this->_posMask = (1 << numPosBits) - 1;
  return !v4;
}

//------------------------------------------------------------------------------
// Address: 0x005208B0
// Name: public: class NCompress::NLZMA::CLiteralEncoder2 __near * NCompress::NLZMA::CLiteralEncoder::GetSubCoder(unsigned int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
NCompress::NLZMA::CLiteralEncoder2 *__thiscall NCompress::NLZMA::CLiteralEncoder::GetSubCoder(
        NCompress::NLZMA::CLiteralEncoder *this,
        unsigned int pos,
        unsigned __int8 prevByte)
{
  return &this->_coders[((pos & this->_posMask) << this->_numPrevBits) + (prevByte >> (8 - this->_numPrevBits))];
}

//------------------------------------------------------------------------------
// Address: 0x005208F0
// Name: private: unsigned int NCompress::NLZMA::CEncoder::GetPosLenPrice(unsigned int,unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetPosLenPrice(
        NCompress::NLZMA::CEncoder *this,
        unsigned int pos,
        unsigned int len,
        unsigned int posState)
{
  int v4; // eax
  unsigned int v5; // esi
  int v6; // esi

  v4 = len - 2;
  if ( len - 2 >= 4 )
    v4 = 3;
  if ( pos >= 0x80 )
  {
    if ( pos >= 0x20000 )
    {
      if ( pos >= 0x8000000 )
        v6 = NCompress::NLZMA::g_FastPos[pos >> 26] + 52;
      else
        v6 = NCompress::NLZMA::g_FastPos[HIWORD(pos)] + 32;
    }
    else
    {
      v6 = NCompress::NLZMA::g_FastPos[pos >> 6] + 12;
    }
    v5 = this->_alignPrices[pos & 0xF] + this->_posSlotPrices[v4][v6];
  }
  else
  {
    v5 = this->_distancesPrices[v4][pos];
  }
  return v5 + this->_lenEncoder._highCoder.Models[272 * posState + 254 + len].Prob;
}

//------------------------------------------------------------------------------
// Address: 0x005209C0
// Name: private: virtual unsigned long NHC4::CMatchFinder::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::AddRef(NHC4::CMatchFinder *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005209E0
// Name: private: virtual unsigned long NHC4::CMatchFinder::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::Release(NHC4::CMatchFinder *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    ((void (__thiscall *)(CLZInWindow *, int))this->dtr_CLZInWindow)(a1: &this->CLZInWindow, a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00520A00
// Name: private: virtual long NBT2::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::Create(
        NBT2::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  int v8; // eax
  unsigned int *v9; // eax
  unsigned int *v10; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_9:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = 2 * v7 + 0x10000;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  this->_hashSizeSum = 0x10000;
  if ( (unsigned int)(4 * v8) >> 2 == v8 )
  {
    v9 = (unsigned int *)BigAlloc(size: 4 * v8);
    v10 = &v9[this->_hashSizeSum];
    this->_hash = v9;
    this->_son = v10;
    if ( v9 != nullptr )
      return 0;
    goto LABEL_9;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x00520B00
// Name: private: void NBT4::CMatchFinder::Normalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT4::CMatchFinder::Normalize(NBT4::CMatchFinder *this)
{
  unsigned int cyclicBufferSize; // eax
  unsigned int v2; // esi
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int *i; // edi
  unsigned int v6; // edx
  unsigned int v7; // edx

  cyclicBufferSize = this->_cyclicBufferSize;
  v2 = this->_pos - cyclicBufferSize;
  v3 = this->_hashSizeSum + 2 * cyclicBufferSize;
  v4 = 0;
  for ( i = this->_hash; v4 < v3; ++v4 )
  {
    v6 = i[v4];
    if ( v6 > v2 )
      v7 = v6 - v2;
    else
      v7 = 0;
    i[v4] = v7;
  }
  this->_buffer += v2;
  this->_posLimit -= v2;
  this->_pos -= v2;
  this->_streamPos -= v2;
}

//------------------------------------------------------------------------------
// Address: 0x00520B50
// Name: private: long NBT4::CMatchFinder::MovePos(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NBT4::CMatchFinder::MovePos(NBT4::CMatchFinder *this)
{
  unsigned int v2; // eax
  HRESULT result; // eax

  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v2 = ++this->_pos;
  if ( v2 <= this->_posLimit )
    goto LABEL_7;
  if ( &this->_buffer[v2] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_7:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00520BB0
// Name: private: virtual unsigned char NBT2::CMatchFinder::GetIndexByte(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __stdcall NBT2::CMatchFinder::GetIndexByte(NHC4::CMatchFinder *this, int index)
{
  return this->_buffer[this->_pos + index];
}

//------------------------------------------------------------------------------
// Address: 0x00520BD0
// Name: private: virtual long NBT3::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::Create(
        NBT3::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int *v12; // eax
  unsigned int *v13; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = ((((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4)
     | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
     | ((historySize - 1) >> 1)
     | (historySize - 1);
  v9 = (v8 | ((v8 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v9 > 0x1000000 )
    v9 = 0xFFFFFF;
  this->_hashMask = v9;
  v10 = v9 + 1025;
  v11 = v10 + 2 * v7;
  this->_hashSizeSum = v10;
  if ( (4 * v11) >> 2 == v11 )
  {
    v12 = (unsigned int *)BigAlloc(size: 4 * v11);
    v13 = &v12[this->_hashSizeSum];
    this->_hash = v12;
    this->_son = v13;
    if ( v12 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x00520D10
// Name: private: virtual int NHC4::CMatchFinder::NeedChangeBufferPos(unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall NHC4::CMatchFinder::NeedChangeBufferPos(NHC4::CMatchFinder *this, unsigned int numCheckBytes)
{
  return numCheckBytes >= &this->_pointerToLastSafePosition[-this->_pos] - this->_buffer;
}

//------------------------------------------------------------------------------
// Address: 0x00520D30
// Name: private: virtual long NBT4::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::Create(
        NBT4::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int *v13; // eax
  unsigned int *v14; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = (((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4;
  v9 = v8 | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1);
  v10 = (v9 | ((v9 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v10 > 0x1000000 )
    v10 = (v9
         | ((v8
           | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
           | ((historySize - 1) >> 1)
           | (historySize - 1)
           | 0x1FFFE00) >> 8)) >> 2;
  this->_hashMask = v10;
  v11 = v10 + 66561;
  v12 = v11 + 2 * v7;
  this->_hashSizeSum = v11;
  if ( (4 * v12) >> 2 == v12 )
  {
    v13 = (unsigned int *)BigAlloc(size: 4 * v12);
    v14 = &v13[this->_hashSizeSum];
    this->_hash = v13;
    this->_son = v14;
    if ( v13 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x00520E70
// Name: private: virtual long NHC4::CMatchFinder::Init(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::Init(NHC4::CMatchFinder *this)
{
  unsigned int result; // eax

  result = CLZInWindow::Init(this: &this->CLZInWindow);
  if ( result == 0 )
  {
    if ( this->_hashSizeSum != 0 )
    {
      do
        this->_hash[result++] = 0;
      while ( result < this->_hashSizeSum );
    }
    this->_cyclicBufferPos = 0;
    --this->_buffer;
    ++this->_posLimit;
    ++this->_pos;
    ++this->_streamPos;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00520EC0
// Name: private: virtual unsigned int NBT4::CMatchFinder::GetMatchLen(int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NBT4::CMatchFinder::GetMatchLen(
        NHC4::CMatchFinder *this,
        int index,
        unsigned int back,
        unsigned int limit)
{
  unsigned int v4; // esi
  unsigned int pos; // edi
  unsigned int streamPos; // ecx
  unsigned __int8 *v7; // ecx
  unsigned int result; // eax

  v4 = limit;
  if ( this->_streamEndWasReached )
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( limit + pos + index > streamPos )
      v4 = streamPos - pos - index;
  }
  for ( result = 0; result < v4; ++result )
  {
    v7 = &this->_buffer[this->_pos + index];
    if ( v7[result] != v7[result - 1 - back] )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00520F20
// Name: private: virtual unsigned int NHC4::CMatchFinder::GetNumAvailableBytes(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::GetNumAvailableBytes(NHC4::CMatchFinder *this)
{
  return this->_streamPos - this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x00520F30
// Name: private: virtual unsigned char const __near * NBT4::CMatchFinder::GetPointerToCurrentPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__stdcall NBT4::CMatchFinder::GetPointerToCurrentPos(NHC4::CMatchFinder *this)
{
  return &this->_buffer[this->_pos];
}

//------------------------------------------------------------------------------
// Address: 0x00520F40
// Name: private: virtual void NBT2::CMatchFinder::ChangeBufferPos(void)
// Source: json
//------------------------------------------------------------------------------
void __stdcall NBT2::CMatchFinder::ChangeBufferPos(NHC4::CMatchFinder *this)
{
  CLZInWindow::MoveBlock(this: &this->CLZInWindow);
}

//------------------------------------------------------------------------------
// Address: 0x00520F60
// Name: private: virtual long NHC4::CMatchFinder::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::QueryInterface(
        NHC4::CMatchFinder *this,
        NHC4::CMatchFinder *__formal,
        const _GUID *__formala)
{
  return -2147467262;
}

//------------------------------------------------------------------------------
// Address: 0x00520F70
// Name: public: virtual void NBT3::CMatchFinder::SetNumPasses(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT3::CMatchFinder::SetNumPasses(NHC4::CMatchFinder *this, unsigned int numPasses)
{
  this->_blockSize = numPasses;
}

//------------------------------------------------------------------------------
// Address: 0x00520F80
// Name: private: virtual long NHC4::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::Create(
        NHC4::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int *v14; // eax
  unsigned int *v15; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 2) + 8;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = (((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4;
  v9 = v8 | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1);
  v10 = (v9 | ((v9 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v10 > 0x1000000 )
    v10 = (v9
         | ((v8
           | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
           | ((historySize - 1) >> 1)
           | (historySize - 1)
           | 0x1FFFE00) >> 8)) >> 2;
  this->_hashMask = v10;
  v11 = v10 + 66561;
  v12 = v11 + v7;
  this->_hashSizeSum = v11;
  v13 = 4 * (v11 + v7);
  if ( v13 >> 2 == v12 )
  {
    v14 = (unsigned int *)BigAlloc(size: v13);
    v15 = &v14[this->_hashSizeSum];
    this->_hash = v14;
    this->_son = v15;
    if ( v14 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x005210C0
// Name: private: virtual long NBT4::CMatchFinder::SetStream(struct ISequentialInStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::SetStream(NHC4::CMatchFinder *this, ISequentialInStream *stream)
{
  CLZInWindow::SetStream(this: &this->CLZInWindow, stream);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005210E0
// Name: private: void NHC4::CMatchFinder::Normalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NHC4::CMatchFinder::Normalize(NHC4::CMatchFinder *this)
{
  unsigned int cyclicBufferSize; // eax
  unsigned int *hash; // ebx
  unsigned int hashSizeSum; // edi
  unsigned int v4; // esi
  bool v5; // zf
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // edx

  cyclicBufferSize = this->_cyclicBufferSize;
  hash = this->_hash;
  hashSizeSum = this->_hashSizeSum;
  v4 = this->_pos - cyclicBufferSize;
  v5 = cyclicBufferSize + hashSizeSum == 0;
  v6 = cyclicBufferSize + hashSizeSum;
  v7 = 0;
  if ( !v5 )
  {
    do
    {
      v8 = hash[v7];
      if ( v8 > v4 )
        v9 = v8 - v4;
      else
        v9 = 0;
      hash[v7++] = v9;
    }
    while ( v7 < v6 );
  }
  this->_buffer += v4;
  this->_posLimit -= v4;
  this->_pos -= v4;
  this->_streamPos -= v4;
}

//------------------------------------------------------------------------------
// Address: 0x00521130
// Name: private: long NHC4::CMatchFinder::MovePos(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NHC4::CMatchFinder::MovePos(NHC4::CMatchFinder *this)
{
  unsigned int v2; // eax
  HRESULT result; // eax

  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v2 = ++this->_pos;
  if ( v2 <= this->_posLimit )
    goto LABEL_7;
  if ( &this->_buffer[v2] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_7:
    if ( this->_pos == 0x7FFFFFFF )
      NHC4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00521190
// Name: public: void NCompress::NLZMA::CFastPosInit::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CFastPosInit::Init(NCompress::NLZMA::CFastPosInit *this)
{
  char v1; // bl
  unsigned int v2; // edi
  unsigned int v3; // esi
  unsigned __int8 slotFast; // [esp+Ch] [ebp-8h]
  int c; // [esp+10h] [ebp-4h]

  v1 = 2;
  c = 2;
  *(_WORD *)NCompress::NLZMA::g_FastPos = 256;
  slotFast = 2;
  v2 = 2;
  do
  {
    v3 = 1 << ((v2 >> 1) - 1);
    if ( v3 != 0 )
    {
      memset(dst: &NCompress::NLZMA::g_FastPos[c], value: slotFast, count: v3);
      c += v3;
    }
    ++v1;
    ++v2;
    slotFast = v1;
  }
  while ( (unsigned __int8)v1 < 0x16u );
}

//------------------------------------------------------------------------------
// Address: 0x005211F0
// Name: NCompress::NLZMA::FindMatchFinder
// Source: json
//------------------------------------------------------------------------------
int __usercall NCompress::NLZMA::FindMatchFinder@<eax>(const wchar_t *s@<edi>)
{
  int result; // eax
  const wchar_t *i; // edx
  wchar_t v3; // cx

  for ( result = 0; result < 4; ++result )
  {
    for ( i = s; ; ++i )
    {
      v3 = *i;
      if ( (unsigned __int16)(*i - 97) <= 0x19u )
        v3 -= 32;
      if ( *(const wchar_t *)((char *)i + (char *)kMatchFinderIDs[result] - (char *)s) != v3 )
        break;
      if ( v3 == 0 )
        return result;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00521230
// Name: public: virtual long NCompress::NLZMA::CEncoder::WriteCoderProperties(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::WriteCoderProperties(
        NCompress::NLZMA::CEncoder *this,
        ISequentialOutStream *outStream)
{
  unsigned int posStateMask; // edx
  unsigned __int8 properties[8]; // [esp+0h] [ebp-8h] BYREF

  properties[0] = LOBYTE(this->_posStateBits) + 9 * (LOBYTE(this->_distTableSize) + 5 * LOBYTE(this->_alignPrices[15]));
  posStateMask = this->_posStateMask;
  *(_DWORD *)&properties[1] = posStateMask;
  return WriteStream(stream: outStream, data: properties, size: 5u, processedSize: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x005212A0
// Name: public: virtual long NCompress::NLZMA::CEncoder::SetOutStream(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::SetOutStream(
        NCompress::NLZMA::CEncoder *this,
        ISequentialOutStream *outStream)
{
  COutBuffer::SetStream(this: (COutBuffer *)(&this->_rangeEncoder.Range + 1), stream: outStream);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005212C0
// Name: private: unsigned int NCompress::NLZMA::CEncoder::Backward(unsigned int __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::Backward(
        NCompress::NLZMA::CEncoder *this,
        unsigned int *backRes,
        unsigned int cur)
{
  unsigned int v3; // esi
  char *v4; // eax
  unsigned int PosPrev; // edx
  char *v6; // edi
  char *v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned int result; // eax
  unsigned int backMem; // [esp+18h] [ebp+Ch]

  v3 = cur;
  v4 = (char *)this + 40 * cur;
  this->_optimumEndIndex = cur;
  PosPrev = *((_DWORD *)v4 + 14);
  backMem = *((_DWORD *)v4 + 15);
  do
  {
    v6 = (char *)this + 40 * v3;
    if ( v6[41] != 0 )
    {
      v7 = (char *)this + 40 * PosPrev;
      *((_DWORD *)v7 + 15) = -1;
      v7[41] = 0;
      *((_DWORD *)v7 + 14) = PosPrev - 1;
      if ( v6[42] != 0 )
      {
        v7[1] = 0;
        *((_DWORD *)v7 + 4) = *((_DWORD *)v6 + 11);
        *((_DWORD *)v7 + 5) = *((_DWORD *)v6 + 12);
      }
    }
    v8 = backMem;
    v9 = PosPrev;
    v10 = PosPrev;
    backMem = this->_optimum[PosPrev].BackPrev;
    PosPrev = this->_optimum[PosPrev].PosPrev;
    this->_optimum[v9].PosPrev = v3;
    this->_optimum[v9].BackPrev = v8;
    v3 = v10;
  }
  while ( v10 != 0 );
  *backRes = this->_optimum[0].BackPrev;
  result = this->_optimum[0].PosPrev;
  this->_optimumCurrentIndex = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00521360
// Name: public: void NCompress::NRangeCoder::CBitEncoder<5>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitEncoder<5>::Encode(
        NCompress::NRangeCoder::CBitEncoder<5> *this,
        NCompress::NRangeCoder::CEncoder *encoder,
        unsigned int symbol)
{
  unsigned int Range; // esi
  unsigned int v4; // edx
  unsigned int v5; // ecx

  Range = encoder->Range;
  v4 = this->Prob * (Range >> 11);
  if ( symbol != 0 )
  {
    encoder->Low += v4;
    encoder->Range = Range - v4;
    this->Prob -= this->Prob >> 5;
  }
  else
  {
    encoder->Range = v4;
    this->Prob += (2048 - this->Prob) >> 5;
  }
  v5 = encoder->Range;
  if ( v5 < 0x1000000 )
  {
    encoder->Range = v5 << 8;
    NCompress::NRangeCoder::CEncoder::ShiftLow(this: encoder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005213D0
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,3> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,3> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 3;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00521470
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,8> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,8> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 8;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00521510
// Name: public: struct IMatchFinder __near * CMyComPtr<struct IMatchFinder>::operator=(struct IMatchFinder __near *)
// Source: json
//------------------------------------------------------------------------------
IMatchFinder *__thiscall CMyComPtr<IMatchFinder>::operator=(CMyComPtr<IMatchFinder> *this, IMatchFinder *p)
{
  if ( p != nullptr )
    p->AddRef(a1: p);
  if ( this->_p != nullptr )
    this->_p->Release(a1: this->_p);
  this->_p = p;
  return p;
}

//------------------------------------------------------------------------------
// Address: 0x00521540
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,6> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,6> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 6;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x005215E0
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,4> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,4> *v4; // edx
  int v5; // edi
  unsigned int Range; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  int rangeEncodera; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  for ( rangeEncodera = 4; rangeEncodera != 0; --rangeEncodera )
  {
    Range = rangeEncoder->Range;
    v7 = v4->Models[v5].Prob * (Range >> 11);
    v8 = symbol & 1;
    if ( (symbol & 1) != 0 )
    {
      rangeEncoder->Low += v7;
      rangeEncoder->Range = Range - v7;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v7;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v9 = rangeEncoder->Range;
    if ( v9 < 0x1000000 )
    {
      rangeEncoder->Range = v9 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    symbol >>= 1;
    v5 = v8 | (2 * v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00521680
// Name: void NCompress::NRangeCoder::ReverseBitTreeEncode<5>(class NCompress::NRangeCoder::CBitEncoder<5> __near *,class NCompress::NRangeCoder::CEncoder __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NCompress::NRangeCoder::ReverseBitTreeEncode<5>(
        NCompress::NRangeCoder::CBitEncoder<5> *Models,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        int NumBitLevels,
        unsigned int symbol)
{
  int v4; // edi
  unsigned int Range; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax

  v4 = 1;
  if ( NumBitLevels > 0 )
  {
    do
    {
      Range = rangeEncoder->Range;
      v6 = Models[v4].Prob * (Range >> 11);
      v7 = symbol & 1;
      if ( (symbol & 1) != 0 )
      {
        rangeEncoder->Low += v6;
        rangeEncoder->Range = Range - v6;
        Models[v4].Prob -= Models[v4].Prob >> 5;
      }
      else
      {
        rangeEncoder->Range = v6;
        Models[v4].Prob += (2048 - Models[v4].Prob) >> 5;
      }
      v8 = rangeEncoder->Range;
      if ( v8 < 0x1000000 )
      {
        rangeEncoder->Range = v8 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      symbol >>= 1;
      v4 = v7 | (2 * v4);
      --NumBitLevels;
    }
    while ( NumBitLevels != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00521710
// Name: unsigned int NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(class NCompress::NRangeCoder::CBitEncoder<5> __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(
        NCompress::NRangeCoder::CBitEncoder<5> *Models,
        int NumBitLevels,
        unsigned int symbol)
{
  __int64 i; // rax
  unsigned int v5; // ecx

  for ( i = 0x100000000LL; NumBitLevels != 0; --NumBitLevels )
  {
    v5 = symbol & 1;
    LODWORD(i) = NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v5 ^ (Models[HIDWORD(i)].Prob - v5)) >> 2) & 0x1FF]
               + i;
    symbol >>= 1;
    HIDWORD(i) = v5 | (2 * HIDWORD(i));
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x005217A0
// Name: public: void NCompress::NRangeCoder::CEncoder::FlushData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::FlushData(NCompress::NRangeCoder::CEncoder *this)
{
  unsigned int Low; // edi
  unsigned __int8 cache; // bl
  bool v4; // zf
  int v5; // [esp+Ch] [ebp-4h]

  v5 = 5;
  do
  {
    Low = this->Low;
    if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
    {
      cache = this->_cache;
      do
      {
        this->Stream._buffer[this->Stream._pos++] = cache + HIDWORD(this->Low);
        if ( this->Stream._pos == this->Stream._limitPos )
          COutBuffer::FlushWithCheck(this: &this->Stream);
        cache = -1;
        v4 = this->_cacheSize-- == 1;
      }
      while ( !v4 );
      Low = this->Low;
      this->_cache = HIBYTE(Low);
    }
    ++this->_cacheSize;
    v4 = v5-- == 1;
    LODWORD(this->Low) = Low << 8;
    HIDWORD(this->Low) = 0;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x00521830
// Name: private: void NCompress::NLZMA::CEncoder::ReleaseMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::ReleaseMatchFinder(NCompress::NLZMA::CEncoder *this)
{
  IMatchFinder *p; // eax

  this->setMfPasses = nullptr;
  p = this->_matchFinder._p;
  if ( p != nullptr )
  {
    p->Release(a1: p);
    this->_matchFinder._p = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00521860
// Name: private: unsigned int NCompress::NLZMA::CEncoder::GetPureRepPrice(unsigned int,class NCompress::NLZMA::CState,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetPureRepPrice(
        NCompress::NLZMA::CEncoder *this,
        unsigned int repIndex,
        NCompress::NLZMA::CState state,
        unsigned int posState)
{
  unsigned int v5; // eax

  if ( repIndex == 0 )
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[state.Index].Prob >> 2]
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[state.Index][posState].Prob) >> 2];
  v5 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRepG0[state.Index].Prob) >> 2];
  if ( repIndex == 1 )
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG1[state.Index].Prob >> 2] + v5;
  else
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[(((2 - repIndex)
                                                            ^ (this->_isRepG2[state.Index].Prob - (repIndex - 2))) >> 2)
                                                          & 0x1FF]
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRepG1[state.Index].Prob) >> 2]
         + v5;
}

//------------------------------------------------------------------------------
// Address: 0x00521920
// Name: public: NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(
        NCompress::NLZMA::CEncoder::CCoderReleaser *this)
{
  NCompress::NLZMA::CEncoder *coder; // esi
  IMatchFinder *p; // eax

  coder = this->_coder;
  p = this->_coder->_matchFinder._p;
  if ( p != nullptr && coder->_needReleaseMFStream )
  {
    p->ReleaseStream(this: p);
    coder->_needReleaseMFStream = false;
  }
  coder->ReleaseOutStream(this: &coder->ICompressSetOutStream);
}

//------------------------------------------------------------------------------
// Address: 0x005219C0
// Name: private: virtual long NBT2::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::GetMatches(NBT2::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // edx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  unsigned int v6; // ebx
  HRESULT result; // eax
  unsigned __int8 *buffer; // edi
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned int *v11; // eax
  unsigned int v12; // ecx
  unsigned int cutValue; // eax
  unsigned int v14; // eax
  unsigned int cyclicBufferPos; // ebx
  unsigned int v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned __int8 *v19; // edx
  int v20; // edx
  unsigned __int8 *v21; // ebx
  unsigned int *v22; // ecx
  const unsigned __int8 *cur; // [esp+8h] [ebp-38h]
  unsigned int delta; // [esp+Ch] [ebp-34h]
  int i; // [esp+10h] [ebp-30h]
  unsigned int *son; // [esp+14h] [ebp-2Ch]
  unsigned int count; // [esp+18h] [ebp-28h]
  unsigned int matchMinPos; // [esp+1Ch] [ebp-24h]
  unsigned int len1; // [esp+20h] [ebp-20h]
  unsigned int *pair; // [esp+24h] [ebp-1Ch]
  unsigned int len0; // [esp+28h] [ebp-18h]
  const unsigned __int8 *pb; // [esp+2Ch] [ebp-14h]
  unsigned int maxLen; // [esp+30h] [ebp-10h]
  int offset; // [esp+34h] [ebp-Ch]
  unsigned int *ptr0; // [esp+38h] [ebp-8h]
  unsigned int *ptr1; // [esp+3Ch] [ebp-4h]
  unsigned int lenLimit; // [esp+48h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 3 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos((NBT4::CMatchFinder *)this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    v6 = 0;
  else
    v6 = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v9 = buffer[pos + 1];
  v10 = &buffer[pos];
  maxLen = 1;
  v11 = &this->_hash[*v10 ^ (v9 << 8)];
  v12 = *v11;
  *v11 = pos;
  son = this->_son;
  ptr1 = &son[2 * this->_cyclicBufferPos];
  matchMinPos = v6;
  cur = v10;
  ptr0 = ptr1 + 1;
  len1 = 2;
  len0 = 2;
  if ( v12 > v6 && this->_buffer[v12 + 2] != v10[2] )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - v12 - 1;
    offset = 3;
  }
  cutValue = this->_cutValue;
  if ( v12 > v6 )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v16 = this->_pos - v12;
      delta = v16;
      if ( v16 > cyclicBufferPos )
        v17 = cyclicBufferPos + this->_cyclicBufferSize - v16;
      else
        v17 = cyclicBufferPos - v16;
      v18 = len1;
      pair = &son[2 * v17];
      v19 = &this->_buffer[v12];
      pb = v19;
      if ( len0 < len1 )
        v18 = len0;
      if ( v19[v18] == v10[v18] )
      {
        if ( ++v18 != lenLimit )
        {
          v20 = v19 - v10;
          v21 = &v10[v18];
          for ( i = v20; v21[v20] == *v21; v20 = i )
          {
            ++v18;
            ++v21;
            if ( v18 == lenLimit )
              break;
          }
          v19 = &this->_buffer[v12];
        }
        if ( maxLen < v18 )
        {
          distances[offset] = v18;
          distances[offset + 1] = delta - 1;
          maxLen = v18;
          offset += 2;
          if ( v18 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0 = pair[1];
            goto LABEL_13;
          }
          v10 = (unsigned __int8 *)cur;
          v19 = (unsigned __int8 *)pb;
        }
      }
      if ( v19[v18] >= v10[v18] )
      {
        *ptr0 = v12;
        v22 = pair;
        ptr0 = pair;
        len0 = v18;
      }
      else
      {
        *ptr1 = v12;
        v22 = pair + 1;
        ptr1 = pair + 1;
        len1 = v18;
      }
      v12 = *v22;
      if ( v12 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  *ptr1 = 0;
  *ptr0 = 0;
LABEL_13:
  *distances = offset - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v14 = ++this->_pos;
  if ( v14 <= this->_posLimit )
    goto LABEL_19;
  if ( &this->_buffer[v14] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_19:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize((NBT4::CMatchFinder *)this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00521C00
// Name: private: virtual long NBT2::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::Skip(NBT2::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // edi
  int v16; // eax
  int v17; // ecx
  unsigned __int8 *v18; // edi
  unsigned int *v19; // eax
  unsigned int v20; // ecx
  unsigned int *v21; // ebx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v24; // edx
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned __int8 *v27; // edx
  unsigned __int8 *v28; // edx
  unsigned __int8 *v29; // ebx
  unsigned int *v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // eax
  unsigned int *hash; // ebx
  unsigned int v34; // edx
  unsigned int v35; // eax
  unsigned int v36; // edx
  unsigned int v37; // edx
  unsigned int count; // [esp+Ch] [ebp-28h]
  unsigned int *son; // [esp+10h] [ebp-24h]
  unsigned __int8 *v40; // [esp+18h] [ebp-1Ch]
  unsigned int len0; // [esp+1Ch] [ebp-18h]
  unsigned int len1; // [esp+20h] [ebp-14h]
  unsigned int *pair; // [esp+24h] [ebp-10h]
  unsigned int matchMinPos; // [esp+28h] [ebp-Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-8h]
  unsigned int *ptr1; // [esp+30h] [ebp-4h]
  unsigned int lenLimit; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimita; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimitb; // [esp+3Ch] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = buffer[pos + 1];
      v17 = buffer[pos];
      v18 = &buffer[pos];
      v19 = &this->_hash[v17 ^ (v16 << 8)];
      v20 = *v19;
      *v19 = pos;
      v21 = this->_son;
      ptr1 = &v21[2 * this->_cyclicBufferPos];
      len1 = 2;
      len0 = 2;
      cutValue = this->_cutValue;
      son = v21;
      ptr0 = ptr1 + 1;
      if ( v20 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v24 = this->_pos - v20;
          if ( v24 > cyclicBufferPos )
            v25 = this->_cyclicBufferSize + cyclicBufferPos - v24;
          else
            v25 = cyclicBufferPos - v24;
          pair = &v21[2 * v25];
          v26 = len0;
          v27 = &this->_buffer[v20];
          if ( len0 >= len1 )
            v26 = len1;
          if ( v27[v26] == v18[v26] )
          {
            if ( ++v26 == lenLimit )
              goto LABEL_40;
            v28 = (unsigned __int8 *)(v27 - v18);
            v29 = &v18[v26];
            v40 = v28;
            while ( v29[(_DWORD)v28] == *v29 )
            {
              ++v26;
              ++v29;
              if ( v26 == lenLimit )
                goto LABEL_40;
              v28 = v40;
            }
            if ( v26 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v27 = &this->_buffer[v20];
          }
          if ( v27[v26] >= v18[v26] )
          {
            *ptr0 = v20;
            v30 = pair;
            ptr0 = pair;
            len0 = v26;
          }
          else
          {
            *ptr1 = v20;
            v30 = pair + 1;
            ptr1 = pair + 1;
            len1 = v26;
          }
          v20 = *v30;
          if ( v20 <= matchMinPos )
            break;
          v21 = son;
          cutValue = count;
        }
      }
      *ptr1 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v31 = ++this->_pos;
      if ( v31 > this->_posLimit )
      {
        if ( &this->_buffer[v31] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v32 = this->_cyclicBufferSize;
        hash = this->_hash;
        v34 = this->_hashSizeSum + 2 * v32;
        v11 = 0x7FFFFFFF - v32;
        v35 = 0;
        for ( lenLimitb = v34; v35 < lenLimitb; ++v35 )
        {
          v36 = hash[v35];
          if ( v36 > v11 )
            v37 = v36 - v11;
          else
            v37 = 0;
          hash[v35] = v37;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 3 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00521EF0
// Name: private: virtual long NBT3::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::GetMatches(NBT3::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int *hash; // ecx
  unsigned int v13; // eax
  int v14; // edx
  unsigned int v15; // edi
  unsigned int cyclicBufferPos; // ecx
  unsigned int v17; // ebx
  int v18; // edx
  unsigned int *v19; // ecx
  unsigned int cutValue; // eax
  unsigned int *v21; // edx
  int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // edx
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int *v27; // edx
  unsigned int v28; // eax
  unsigned __int8 *v29; // ecx
  const unsigned __int8 *v30; // edx
  int i; // ebx
  const unsigned __int8 *pb; // [esp+8h] [ebp-3Ch]
  unsigned int delta; // [esp+Ch] [ebp-38h]
  unsigned int *son; // [esp+18h] [ebp-2Ch]
  unsigned int count; // [esp+1Ch] [ebp-28h]
  unsigned int len0; // [esp+20h] [ebp-24h]
  unsigned int len0a; // [esp+20h] [ebp-24h]
  unsigned int len1; // [esp+24h] [ebp-20h]
  unsigned int *pair; // [esp+28h] [ebp-1Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-18h]
  unsigned int *ptr1; // [esp+30h] [ebp-14h]
  unsigned int matchMinPos; // [esp+34h] [ebp-10h]
  const unsigned __int8 *cur; // [esp+38h] [ebp-Ch]
  unsigned int lenLimit; // [esp+3Ch] [ebp-8h]
  unsigned int maxLen; // [esp+40h] [ebp-4h]
  int offset; // [esp+4Ch] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 3 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos((NBT4::CMatchFinder *)this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  cur = v9;
  LOWORD(v8) = LOWORD(CCRC::Table[v8]) ^ v9[1];
  v11 = v10 ^ (v9[2] << 8);
  hash = this->_hash;
  v13 = this->_hashMask & v11;
  v14 = v8 & 0x3FF;
  len0 = hash[v14];
  maxLen = 1;
  v15 = hash[v13 + 1024];
  hash[v14] = this->_pos;
  if ( len0 > matchMinPos && this->_buffer[len0] == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - len0 - 1;
    offset = 3;
    if ( len0 == v15 )
    {
      offset = 1;
      maxLen = 1;
    }
  }
  this->_hash[v13 + 1024] = this->_pos;
  cyclicBufferPos = this->_cyclicBufferPos;
  son = this->_son;
  v17 = 0;
  v18 = (int)&son[2 * cyclicBufferPos + 1];
  v19 = &son[2 * cyclicBufferPos];
  cutValue = this->_cutValue;
  ptr0 = (unsigned int *)v18;
  ptr1 = v19;
  len1 = 0;
  len0a = 0;
  if ( v15 > matchMinPos )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      v24 = this->_cyclicBufferPos;
      v25 = this->_pos - v15;
      delta = v25;
      if ( v25 > v24 )
        v26 = v24 + this->_cyclicBufferSize - v25;
      else
        v26 = v24 - v25;
      v27 = &son[2 * v26];
      v28 = len1;
      v29 = &this->_buffer[v15];
      pair = v27;
      pb = v29;
      if ( v17 < len1 )
        v28 = v17;
      if ( v29[v28] == cur[v28] )
      {
        if ( ++v28 != lenLimit )
        {
          v30 = &cur[v28];
          for ( i = v29 - cur; v30[i] == *v30; i = v29 - cur )
          {
            ++v28;
            ++v30;
            if ( v28 == lenLimit )
              break;
          }
        }
        if ( maxLen < v28 )
        {
          v21 = distances;
          distances[offset] = v28;
          distances[offset + 1] = delta - 1;
          v22 = offset + 2;
          maxLen = v28;
          offset += 2;
          if ( v28 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0 = pair[1];
            goto LABEL_14;
          }
          v29 = (unsigned __int8 *)pb;
        }
      }
      if ( v29[v28] >= cur[v28] )
      {
        *ptr0 = v15;
        v15 = *pair;
        v17 = v28;
        ptr0 = pair;
        v19 = ptr1;
        len0a = v28;
      }
      else
      {
        v17 = len0a;
        *ptr1 = v15;
        v15 = pair[1];
        v19 = pair + 1;
        ptr1 = pair + 1;
        len1 = v28;
      }
      if ( v15 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  v21 = distances;
  *v19 = 0;
  *ptr0 = 0;
  v22 = offset;
LABEL_14:
  *v21 = v22 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v23 = ++this->_pos;
  if ( v23 <= this->_posLimit )
    goto LABEL_20;
  if ( &this->_buffer[v23] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_20:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize((NBT4::CMatchFinder *)this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00522180
// Name: private: virtual long NBT3::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::Skip(NBT3::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // edx
  unsigned int v16; // eax
  int v17; // ecx
  unsigned __int8 *v18; // edx
  unsigned int v19; // ecx
  unsigned int *hash; // eax
  unsigned int v21; // edi
  unsigned int *v22; // ebx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // ecx
  unsigned __int8 *v29; // ecx
  unsigned __int8 *v30; // ebx
  unsigned int *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int *v34; // ebx
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // edx
  unsigned int *son; // [esp+Ch] [ebp-28h]
  unsigned int count; // [esp+10h] [ebp-24h]
  unsigned __int8 *v41; // [esp+18h] [ebp-1Ch]
  unsigned int len0; // [esp+1Ch] [ebp-18h]
  unsigned int len1; // [esp+20h] [ebp-14h]
  unsigned int *pair; // [esp+24h] [ebp-10h]
  unsigned int matchMinPos; // [esp+28h] [ebp-Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-8h]
  unsigned int *ptr1; // [esp+30h] [ebp-4h]
  unsigned int lenLimit; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimita; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimitb; // [esp+3Ch] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v17 = buffer[pos + 2];
      v18 = &buffer[pos];
      v19 = this->_hashMask & (v16 ^ (v17 << 8));
      this->_hash[v16 & 0x3FF] = pos;
      hash = this->_hash;
      v21 = hash[v19 + 1024];
      hash[v19 + 1024] = this->_pos;
      v22 = this->_son;
      ptr1 = &v22[2 * this->_cyclicBufferPos];
      len1 = 0;
      len0 = 0;
      cutValue = this->_cutValue;
      son = v22;
      ptr0 = ptr1 + 1;
      if ( v21 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v25 = this->_pos - v21;
          if ( v25 > cyclicBufferPos )
            v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
          else
            v26 = cyclicBufferPos - v25;
          pair = &v22[2 * v26];
          v27 = len0;
          v28 = &this->_buffer[v21];
          if ( len0 >= len1 )
            v27 = len1;
          if ( v28[v27] == v18[v27] )
          {
            if ( ++v27 == lenLimit )
              goto LABEL_40;
            v29 = (unsigned __int8 *)(v28 - v18);
            v30 = &v18[v27];
            v41 = v29;
            while ( v30[(_DWORD)v29] == *v30 )
            {
              ++v27;
              ++v30;
              if ( v27 == lenLimit )
                goto LABEL_40;
              v29 = v41;
            }
            if ( v27 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v28 = &this->_buffer[v21];
          }
          if ( v28[v27] >= v18[v27] )
          {
            *ptr0 = v21;
            v31 = pair;
            ptr0 = pair;
            len0 = v27;
          }
          else
          {
            *ptr1 = v21;
            v31 = pair + 1;
            ptr1 = pair + 1;
            len1 = v27;
          }
          v21 = *v31;
          if ( *v31 <= matchMinPos )
            break;
          cutValue = count;
          v22 = son;
        }
      }
      *ptr1 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v32 = ++this->_pos;
      if ( v32 > this->_posLimit )
      {
        if ( &this->_buffer[v32] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v33 = this->_cyclicBufferSize;
        v34 = this->_hash;
        v35 = this->_hashSizeSum + 2 * v33;
        v11 = 0x7FFFFFFF - v33;
        v36 = 0;
        for ( lenLimitb = v35; v36 < lenLimitb; ++v36 )
        {
          v37 = v34[v36];
          if ( v37 > v11 )
            v38 = v37 - v11;
          else
            v38 = 0;
          v34[v36] = v38;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 3 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00522490
// Name: private: virtual long NBT4::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::GetMatches(NBT4::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned __int16 v13; // dx
  __int16 v14; // di
  unsigned int *hash; // ecx
  int v16; // edi
  int v17; // ebx
  unsigned int *v18; // edi
  unsigned int v19; // ecx
  unsigned int *v20; // edi
  unsigned int cutValue; // eax
  unsigned int *v22; // ecx
  unsigned int v23; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // edi
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // edi
  const unsigned __int8 *v29; // ecx
  unsigned int delta; // [esp+8h] [ebp-34h]
  unsigned int *son; // [esp+Ch] [ebp-30h]
  unsigned int count; // [esp+10h] [ebp-2Ch]
  unsigned int curMatch3; // [esp+14h] [ebp-28h]
  unsigned int curMatch3a; // [esp+14h] [ebp-28h]
  unsigned int len1; // [esp+18h] [ebp-24h]
  unsigned int *pair; // [esp+1Ch] [ebp-20h]
  unsigned int *ptr0; // [esp+20h] [ebp-1Ch]
  unsigned int *ptr0a; // [esp+20h] [ebp-1Ch]
  unsigned int *ptr1; // [esp+24h] [ebp-18h]
  const unsigned __int8 *cur; // [esp+28h] [ebp-14h]
  unsigned int lenLimit; // [esp+2Ch] [ebp-10h]
  unsigned int matchMinPos; // [esp+30h] [ebp-Ch]
  unsigned int maxLen; // [esp+34h] [ebp-8h]
  unsigned int curMatch; // [esp+38h] [ebp-4h]
  int offset; // [esp+44h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 4 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos(this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  v11 = v9[2];
  cur = v9;
  v12 = this->_hashMask & (v10 ^ (32 * (CCRC::Table[v9[3]] ^ (8 * v11))));
  maxLen = 1;
  v13 = v10 ^ ((_WORD)v11 << 8);
  v14 = v10;
  hash = this->_hash;
  v16 = v14 & 0x3FF;
  curMatch = hash[v12 + 66560];
  ptr0 = (unsigned int *)hash[v16];
  curMatch3 = hash[v13 + 1024];
  hash[v16] = this->_pos;
  if ( (unsigned int)ptr0 > matchMinPos && *((_BYTE *)ptr0 + (unsigned int)this->_buffer) == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - (_DWORD)ptr0 - 1;
    v17 = 3;
    offset = 3;
  }
  else
  {
    v17 = 1;
  }
  this->_hash[v13 + 1024] = this->_pos;
  v18 = (unsigned int *)curMatch3;
  if ( curMatch3 > matchMinPos && this->_buffer[curMatch3] == *cur )
  {
    if ( (unsigned int *)curMatch3 == ptr0 )
      v17 -= 2;
    distances[v17] = 3;
    distances[v17 + 1] = this->_pos - curMatch3 - 1;
    v17 += 2;
    maxLen = 3;
    offset = v17;
  }
  else
  {
    v18 = ptr0;
  }
  v19 = curMatch;
  if ( v17 != 1 && v18 == (unsigned int *)curMatch )
  {
    v17 -= 2;
    offset = v17;
    maxLen = 1;
  }
  this->_hash[v12 + 66560] = this->_pos;
  son = this->_son;
  v20 = &son[2 * this->_cyclicBufferPos];
  len1 = 0;
  curMatch3a = 0;
  cutValue = this->_cutValue;
  ptr0a = v20 + 1;
  ptr1 = v20;
  if ( curMatch > matchMinPos )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v25 = this->_pos - v19;
      delta = v25;
      if ( v25 > cyclicBufferPos )
        v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
      else
        v26 = cyclicBufferPos - v25;
      pair = &son[2 * v26];
      v27 = curMatch3a;
      v28 = &this->_buffer[v19];
      if ( curMatch3a >= len1 )
        v27 = len1;
      if ( v28[v27] == cur[v27] )
      {
        if ( ++v27 != lenLimit )
        {
          v29 = &cur[v27];
          do
          {
            if ( v29[v28 - cur] != *v29 )
              break;
            ++v27;
            ++v29;
          }
          while ( v27 != lenLimit );
          v19 = curMatch;
        }
        v17 = offset;
        if ( maxLen < v27 )
        {
          v22 = distances;
          distances[offset] = v27;
          distances[offset + 1] = delta - 1;
          v17 = offset + 2;
          maxLen = v27;
          offset += 2;
          if ( v27 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0a = pair[1];
            goto LABEL_23;
          }
          v19 = curMatch;
        }
      }
      else
      {
        v17 = offset;
      }
      if ( v28[v27] >= cur[v27] )
      {
        v20 = ptr1;
        *ptr0a = v19;
        ptr0a = pair;
        v19 = *pair;
        curMatch3a = v27;
      }
      else
      {
        v20 = pair + 1;
        *ptr1 = v19;
        v19 = pair[1];
        ptr1 = pair + 1;
        len1 = v27;
      }
      curMatch = v19;
      if ( v19 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  v22 = distances;
  *v20 = 0;
  *ptr0a = 0;
LABEL_23:
  *v22 = v17 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v23 = ++this->_pos;
  if ( v23 <= this->_posLimit )
    goto LABEL_29;
  if ( &this->_buffer[v23] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_29:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005227B0
// Name: private: virtual long NBT4::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::Skip(NBT4::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // ecx
  unsigned int v16; // eax
  int v17; // edx
  unsigned int v18; // ecx
  unsigned int *hash; // eax
  unsigned int v20; // edx
  unsigned int *v21; // edi
  unsigned int *v22; // ecx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // edi
  const unsigned __int8 *v29; // ecx
  int v30; // ebx
  const unsigned __int8 *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int *v34; // ebx
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // edx
  unsigned int count; // [esp+Ch] [ebp-2Ch]
  unsigned int *son; // [esp+10h] [ebp-28h]
  unsigned int len0; // [esp+1Ch] [ebp-1Ch]
  unsigned int len1; // [esp+20h] [ebp-18h]
  const unsigned __int8 *cur; // [esp+24h] [ebp-14h]
  unsigned int *pair; // [esp+28h] [ebp-10h]
  unsigned int matchMinPos; // [esp+2Ch] [ebp-Ch]
  unsigned int *ptr0; // [esp+30h] [ebp-8h]
  unsigned int *ptr1; // [esp+34h] [ebp-4h]
  unsigned int lenLimit; // [esp+40h] [ebp+8h]
  unsigned int lenLimita; // [esp+40h] [ebp+8h]
  unsigned int lenLimitb; // [esp+40h] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v17 = buffer[pos + 2];
      cur = &buffer[pos];
      v18 = this->_hashMask & (v16 ^ (32 * (CCRC::Table[buffer[pos + 3]] ^ (8 * v17))));
      this->_hash[(unsigned __int16)(v16 ^ ((_WORD)v17 << 8)) + 1024] = pos;
      this->_hash[v16 & 0x3FF] = this->_pos;
      hash = this->_hash;
      v20 = hash[v18 + 66560];
      hash[v18 + 66560] = this->_pos;
      v21 = this->_son;
      ptr0 = &v21[2 * this->_cyclicBufferPos + 1];
      v22 = &v21[2 * this->_cyclicBufferPos];
      len1 = 0;
      len0 = 0;
      cutValue = this->_cutValue;
      son = v21;
      ptr1 = v22;
      if ( v20 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v25 = this->_pos - v20;
          if ( v25 > cyclicBufferPos )
            v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
          else
            v26 = cyclicBufferPos - v25;
          pair = &v21[2 * v26];
          v27 = len0;
          v28 = &this->_buffer[v20];
          if ( len0 >= len1 )
            v27 = len1;
          v29 = cur;
          if ( v28[v27] == cur[v27] )
          {
            if ( ++v27 == lenLimit )
              goto LABEL_40;
            v30 = v28 - cur;
            v31 = &cur[v27];
            while ( v31[v30] == *v31 )
            {
              ++v27;
              ++v31;
              if ( v27 == lenLimit )
                goto LABEL_40;
              v30 = v28 - cur;
            }
            if ( v27 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v29 = cur;
          }
          if ( v28[v27] >= v29[v27] )
          {
            *ptr0 = v20;
            v20 = *pair;
            ptr0 = pair;
            v22 = ptr1;
            len0 = v27;
          }
          else
          {
            *ptr1 = v20;
            v20 = pair[1];
            v22 = pair + 1;
            ptr1 = pair + 1;
            len1 = v27;
          }
          if ( v20 <= matchMinPos )
            break;
          v21 = son;
          cutValue = count;
        }
      }
      *v22 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v32 = ++this->_pos;
      if ( v32 > this->_posLimit )
      {
        if ( &this->_buffer[v32] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v33 = this->_cyclicBufferSize;
        v34 = this->_hash;
        v35 = this->_hashSizeSum + 2 * v33;
        v11 = 0x7FFFFFFF - v33;
        v36 = 0;
        for ( lenLimitb = v35; v36 < lenLimitb; ++v36 )
        {
          v37 = v34[v36];
          if ( v37 > v11 )
            v38 = v37 - v11;
          else
            v38 = 0;
          v34[v36] = v38;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 4 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00522B00
// Name: private: virtual long NHC4::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::GetMatches(NHC4::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned __int16 v13; // dx
  __int16 v14; // di
  unsigned int *hash; // ecx
  int v16; // edi
  int v17; // ecx
  unsigned int v18; // edi
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v21; // edx
  unsigned int v22; // eax
  unsigned __int8 *v23; // edx
  unsigned int v24; // eax
  _BYTE *v25; // edi
  int v26; // edx
  unsigned int v27; // eax
  unsigned int *son; // [esp+8h] [ebp-20h]
  unsigned int curMatch3; // [esp+Ch] [ebp-1Ch]
  unsigned int curMatch3a; // [esp+Ch] [ebp-1Ch]
  unsigned int lenLimit; // [esp+10h] [ebp-18h]
  unsigned int cyclicPos; // [esp+14h] [ebp-14h]
  unsigned int cyclicPosa; // [esp+14h] [ebp-14h]
  int offset; // [esp+18h] [ebp-10h]
  unsigned int delta; // [esp+1Ch] [ebp-Ch]
  unsigned int deltaa; // [esp+1Ch] [ebp-Ch]
  unsigned int matchMinPos; // [esp+20h] [ebp-8h]
  const unsigned __int8 *cur; // [esp+24h] [ebp-4h]
  unsigned int maxLen; // [esp+30h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 4 )
    {
      *distances = 0;
      return NHC4::CMatchFinder::MovePos(this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  v11 = v9[2];
  cur = v9;
  v12 = this->_hashMask & (v10 ^ (32 * (CCRC::Table[v9[3]] ^ (8 * v11))));
  maxLen = 1;
  v13 = v10 ^ ((_WORD)v11 << 8);
  v14 = v10;
  hash = this->_hash;
  v16 = v14 & 0x3FF;
  cyclicPos = hash[v12 + 66560];
  delta = hash[v16];
  curMatch3 = hash[v13 + 1024];
  hash[v16] = this->_pos;
  if ( delta > matchMinPos && this->_buffer[delta] == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - delta - 1;
    v17 = 3;
  }
  else
  {
    v17 = 1;
  }
  this->_hash[v13 + 1024] = this->_pos;
  if ( curMatch3 > matchMinPos && this->_buffer[curMatch3] == *cur )
  {
    if ( curMatch3 == delta )
      v17 -= 2;
    distances[v17] = 3;
    distances[v17 + 1] = this->_pos - curMatch3 - 1;
    maxLen = 3;
    v17 += 2;
    delta = curMatch3;
  }
  v18 = cyclicPos;
  if ( v17 != 1 && delta == cyclicPos )
  {
    v17 -= 2;
    maxLen = 1;
  }
  this->_hash[v12 + 66560] = this->_pos;
  son = this->_son;
  son[this->_cyclicBufferPos] = cyclicPos;
  cutValue = this->_cutValue;
  if ( cyclicPos > matchMinPos )
  {
    while ( 1 )
    {
      curMatch3a = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v21 = this->_pos - v18;
      deltaa = v21;
      v22 = v21 > cyclicBufferPos ? this->_cyclicBufferSize + cyclicBufferPos - v21 : cyclicBufferPos - v21;
      v23 = &this->_buffer[v18];
      cyclicPosa = v22;
      if ( v23[maxLen] == cur[maxLen] && *v23 == *cur )
      {
        v24 = 1;
        if ( lenLimit != 1 )
        {
          v25 = cur + 1;
          v26 = v23 - cur;
          for ( offset = v26; v25[v26] == *v25; v26 = offset )
          {
            ++v24;
            ++v25;
            if ( v24 == lenLimit )
              break;
          }
        }
        if ( maxLen < v24 )
        {
          distances[v17] = v24;
          distances[v17 + 1] = deltaa - 1;
          v17 += 2;
          maxLen = v24;
          if ( v24 == lenLimit )
            break;
        }
      }
      v18 = son[cyclicPosa];
      if ( v18 <= matchMinPos )
        break;
      cutValue = curMatch3a;
    }
  }
  *distances = v17 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v27 = ++this->_pos;
  if ( v27 <= this->_posLimit )
    goto LABEL_43;
  if ( &this->_buffer[v27] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_43:
    if ( this->_pos == 0x7FFFFFFF )
      NHC4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00522DA0
// Name: private: virtual long NHC4::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::Skip(NHC4::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int v3; // eax
  HRESULT result; // eax
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int *v7; // ebx
  unsigned int v8; // ecx
  bool v9; // zf
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // edx
  unsigned __int8 *buffer; // ecx
  unsigned int v15; // eax
  int v16; // edx
  unsigned int v17; // ecx
  unsigned int *v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int cyclicBufferSize; // eax
  unsigned int hashSizeSum; // edi
  unsigned int *hash; // ebx
  unsigned int v24; // edi
  unsigned int v25; // eax
  unsigned int v26; // edx
  unsigned int v27; // edx

  do
  {
    pos = this->_pos;
    if ( this->_streamPos - pos >= 4 )
    {
      buffer = this->_buffer;
      v15 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v16 = buffer[pos + 2];
      v17 = this->_hashMask & (v15 ^ (32 * (CCRC::Table[buffer[pos + 3]] ^ (8 * v16))));
      this->_hash[(unsigned __int16)(v15 ^ ((_WORD)v16 << 8)) + 1024] = pos;
      this->_hash[v15 & 0x3FF] = this->_pos;
      v18 = &this->_hash[v17 + 66560];
      v19 = *v18;
      *v18 = this->_pos;
      this->_son[this->_cyclicBufferPos++] = v19;
      if ( this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v20 = ++this->_pos;
      if ( v20 > this->_posLimit )
      {
        if ( &this->_buffer[v20] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        cyclicBufferSize = this->_cyclicBufferSize;
        hashSizeSum = this->_hashSizeSum;
        hash = this->_hash;
        v8 = 0x7FFFFFFF - cyclicBufferSize;
        v9 = cyclicBufferSize + hashSizeSum == 0;
        v24 = cyclicBufferSize + hashSizeSum;
        v25 = 0;
        if ( !v9 )
        {
          do
          {
            v26 = hash[v25];
            if ( v26 > v8 )
              v27 = v26 - v8;
            else
              v27 = 0;
            hash[v25++] = v27;
          }
          while ( v25 < v24 );
        }
        goto LABEL_27;
      }
    }
    else
    {
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v3 = ++this->_pos;
      if ( v3 > this->_posLimit )
      {
        if ( &this->_buffer[v3] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v5 = this->_cyclicBufferSize;
        v6 = this->_hashSizeSum;
        v7 = this->_hash;
        v8 = 0x7FFFFFFF - v5;
        v9 = v5 + v6 == 0;
        v10 = v5 + v6;
        v11 = 0;
        if ( !v9 )
        {
          do
          {
            v12 = v7[v11];
            if ( v12 > v8 )
              v13 = v12 - v8;
            else
              v13 = 0;
            v7[v11++] = v13;
          }
          while ( v11 < v10 );
        }
LABEL_27:
        this->_buffer += v8;
        this->_posLimit -= v8;
        this->_pos -= v8;
        this->_streamPos -= v8;
      }
    }
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00522F60
// Name: public: void NCompress::NLZMA::CLiteralEncoder2::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CLiteralEncoder2::Encode(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned __int8 symbol)
{
  NCompress::NLZMA::CLiteralEncoder2 *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int i; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 8;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    i = v7;
    Range = rangeEncoder->Range;
    v10 = v4->_encoders[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->_encoders[v5].Prob -= v4->_encoders[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->_encoders[v5].Prob += (2048 - v4->_encoders[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = i;
    v5 = v11 | (2 * v5);
  }
  while ( i != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00523000
// Name: public: void NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(class NCompress::NRangeCoder::CEncoder __near *,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned __int8 matchByte,
        unsigned __int8 symbol)
{
  int v5; // edx
  int v6; // edx
  int v7; // ebx
  int v8; // edi
  unsigned int Range; // edx
  int v10; // ebx
  NCompress::NRangeCoder::CBitEncoder<5> *v11; // ecx
  unsigned int v12; // eax
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // eax
  int v17; // edi
  bool v18; // cf
  unsigned int v19; // ebx
  unsigned int v20; // eax
  unsigned int context; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  int ia; // [esp+1Ch] [ebp+8h]

  context = 1;
  v5 = 8;
  while ( 1 )
  {
    v6 = v5 - 1;
    v7 = matchByte >> v6;
    v8 = symbol >> v6;
    i = v6;
    Range = rangeEncoder->Range;
    v10 = v7 & 1;
    v11 = &this->_encoders[256 * v10 + 256 + context];
    v12 = v11->Prob * (Range >> 11);
    v13 = v8 & 1;
    if ( v13 != 0 )
    {
      rangeEncoder->Low += v12;
      rangeEncoder->Range = Range - v12;
      v11->Prob -= v11->Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v12;
      v11->Prob += (2048 - v11->Prob) >> 5;
    }
    v14 = rangeEncoder->Range;
    if ( v14 < 0x1000000 )
    {
      rangeEncoder->Range = v14 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    v5 = i;
    context = v13 | (2 * context);
    if ( v10 != v13 )
      break;
    if ( i == 0 )
      return;
  }
  if ( i != 0 )
  {
    do
    {
      --v5;
      v15 = context;
      v16 = this->_encoders[context].Prob * (rangeEncoder->Range >> 11);
      v17 = (symbol >> v5) & 1;
      ia = v5;
      if ( v17 != 0 )
      {
        v18 = __CFADD__(v16, rangeEncoder->Low);
        LODWORD(rangeEncoder->Low) += v16;
        v19 = rangeEncoder->Range;
        HIDWORD(rangeEncoder->Low) += v18;
        rangeEncoder->Range = v19 - v16;
        this->_encoders[context].Prob -= this->_encoders[context].Prob >> 5;
      }
      else
      {
        rangeEncoder->Range = v16;
        this->_encoders[context].Prob += (2048 - this->_encoders[context].Prob) >> 5;
      }
      v20 = rangeEncoder->Range;
      if ( v20 < 0x1000000 )
      {
        rangeEncoder->Range = v20 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
        v5 = ia;
        v15 = context;
      }
      context = v17 | (2 * v15);
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523160
// Name: public: unsigned int NCompress::NLZMA::CLiteralEncoder2::GetPrice(bool,unsigned char,unsigned char)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CLiteralEncoder2::GetPrice(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        bool matchMode,
        unsigned __int8 matchByte,
        unsigned __int8 symbol)
{
  unsigned int result; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // edx
  int v8; // edx
  unsigned int price; // [esp+10h] [ebp-4h]

  result = 0;
  price = 0;
  v5 = 1;
  v6 = 8;
  if ( !matchMode )
    goto LABEL_9;
  do
  {
    v7 = (symbol >> --v6) & 1;
    result = NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v7
                                                              ^ (this->_encoders[256 * ((matchByte >> v6) & 1)
                                                                               + 256
                                                                               + v5].Prob
                                                               - v7)) >> 2)
                                                            & 0x1FF]
           + price;
    v5 = v7 | (2 * v5);
    price = result;
    if ( ((matchByte >> v6) & 1) != v7 )
      break;
  }
  while ( v6 != 0 );
  if ( v6 != 0 )
  {
LABEL_9:
    do
    {
      v8 = (symbol >> --v6) & 1;
      result += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v8 ^ (this->_encoders[v5].Prob - v8)) >> 2) & 0x1FF];
      v5 = v8 | (2 * v5);
    }
    while ( v6 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00523230
// Name: public: void NCompress::NLZMA::NLength::CEncoder::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::Init(
        NCompress::NLZMA::NLength::CEncoder *this,
        unsigned int numPosStates)
{
  unsigned int v2; // esi
  NCompress::NRangeCoder::CBitEncoder<5> *v3; // eax

  v2 = numPosStates;
  this->_choice.Prob = 1024;
  this->_choice2.Prob = 1024;
  if ( numPosStates != 0 )
  {
    v3 = &this->_midCoder[0].Models[1];
    do
    {
      v3[-128].Prob = 1024;
      v3[-127].Prob = 1024;
      v3[-126].Prob = 1024;
      v3[-125].Prob = 1024;
      v3[-124].Prob = 1024;
      v3[-123].Prob = 1024;
      v3[-122].Prob = 1024;
      v3->Prob = 1024;
      v3[1].Prob = 1024;
      v3[2].Prob = 1024;
      v3[3].Prob = 1024;
      v3[4].Prob = 1024;
      v3[5].Prob = 1024;
      v3[6].Prob = 1024;
      v3 += 8;
      --v2;
    }
    while ( v2 != 0 );
  }
  memset32(&this->_highCoder.Models[1], 1024, 0xFFu);
}

//------------------------------------------------------------------------------
// Address: 0x005232B0
// Name: public: void NCompress::NLZMA::NLength::CEncoder::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::Encode(
        NCompress::NLZMA::NLength::CEncoder *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol,
        unsigned int posState)
{
  unsigned int v5; // eax
  unsigned int Range; // ecx
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // eax

  if ( symbol >= 8 )
  {
    Range = rangeEncoder->Range;
    v7 = this->_choice.Prob * (Range >> 11);
    rangeEncoder->Low += v7;
    rangeEncoder->Range = Range - v7;
    this->_choice.Prob -= this->_choice.Prob >> 5;
    v8 = rangeEncoder->Range;
    if ( v8 < 0x1000000 )
    {
      rangeEncoder->Range = v8 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    if ( symbol >= 0x10 )
    {
      v10 = rangeEncoder->Range;
      v11 = this->_choice2.Prob * (v10 >> 11);
      rangeEncoder->Low += v11;
      rangeEncoder->Range = v10 - v11;
      this->_choice2.Prob -= this->_choice2.Prob >> 5;
      v12 = rangeEncoder->Range;
      if ( v12 < 0x1000000 )
      {
        rangeEncoder->Range = v12 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(this: &this->_highCoder, rangeEncoder, symbol: symbol - 16);
    }
    else
    {
      rangeEncoder->Range = this->_choice2.Prob * (rangeEncoder->Range >> 11);
      this->_choice2.Prob += (2048 - this->_choice2.Prob) >> 5;
      v9 = rangeEncoder->Range;
      if ( v9 < 0x1000000 )
      {
        rangeEncoder->Range = v9 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(
        this: &this->_midCoder[posState],
        rangeEncoder,
        symbol: symbol - 8);
    }
  }
  else
  {
    rangeEncoder->Range = this->_choice.Prob * (rangeEncoder->Range >> 11);
    this->_choice.Prob += (2048 - this->_choice.Prob) >> 5;
    v5 = rangeEncoder->Range;
    if ( v5 < 0x1000000 )
    {
      rangeEncoder->Range = v5 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(this: &this->_lowCoder[posState], rangeEncoder, symbol);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523400
// Name: public: void NCompress::NLZMA::NLength::CEncoder::SetPrices(unsigned int,unsigned int,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::SetPrices(
        NCompress::NLZMA::NLength::CEncoder *this,
        unsigned int posState,
        unsigned int numSymbols,
        unsigned int *prices)
{
  unsigned int v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // edx
  int i; // edi
  char v8; // al
  unsigned int v9; // edx
  unsigned int v10; // edx
  int v11; // edi
  char v12; // al
  unsigned int v13; // edx
  unsigned int v14; // edx
  int v15; // edi
  char v16; // al
  unsigned int b1; // [esp+Ch] [ebp-Ch]
  unsigned int b0; // [esp+10h] [ebp-8h]
  unsigned int a0; // [esp+14h] [ebp-4h]
  unsigned int a0a; // [esp+14h] [ebp-4h]
  unsigned int posStatea; // [esp+20h] [ebp+8h]

  a0 = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_choice.Prob >> 2];
  v4 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_choice.Prob) >> 2];
  b0 = v4 + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_choice2.Prob >> 2];
  b1 = v4 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_choice2.Prob) >> 2];
  v5 = 0;
  while ( v5 < numSymbols )
  {
    v6 = v5 | 8;
    for ( i = 0;
          v6 != 1;
          i += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v8 & 1)
                                                                ^ (this->_lowCoder[posState].Models[v6].Prob - (v8 & 1))) >> 2)
                                                              & 0x1FF] )
    {
      v8 = v6;
      v6 >>= 1;
    }
    prices[v5++] = a0 + i;
    if ( v5 >= 8 )
    {
      if ( v5 >= 0x10 )
      {
LABEL_12:
        if ( v5 < numSymbols )
        {
          v13 = v5 - 16;
          posStatea = v5 - 16;
          do
          {
            v14 = v13 | 0x100;
            v15 = 0;
            do
            {
              v16 = v14;
              v14 >>= 1;
              v15 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v16 & 1)
                                                                      ^ (this->_highCoder.Models[v14].Prob - (v16 & 1))) >> 2)
                                                                    & 0x1FF];
            }
            while ( v14 != 1 );
            prices[v5++] = b1 + v15;
            v13 = ++posStatea;
          }
          while ( v5 < numSymbols );
        }
      }
      else
      {
        v9 = v5 - 8;
        a0a = v5 - 8;
        while ( v5 < numSymbols )
        {
          v10 = v9 | 8;
          v11 = 0;
          do
          {
            v12 = v10;
            v10 >>= 1;
            v11 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v12 & 1)
                                                                    ^ (this->_midCoder[posState].Models[v10].Prob
                                                                     - (v12 & 1))) >> 2)
                                                                  & 0x1FF];
          }
          while ( v10 != 1 );
          prices[v5++] = b0 + v11;
          v9 = ++a0a;
          if ( v5 >= 0x10 )
            goto LABEL_12;
        }
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523580
// Name: public: virtual long NCompress::NLZMA::CEncoder::SetCoderProperties(unsigned long const __near *,struct tagPROPVARIANT const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::SetCoderProperties(
        NCompress::NLZMA::CEncoder *this,
        const unsigned int *propIDs,
        const tagPROPVARIANT *properties,
        unsigned int numProperties)
{
  unsigned int v4; // eax
  unsigned int v6; // eax
  ISequentialInStream *MatchFinder; // eax
  bool v8; // zf
  unsigned int Lo32; // edx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int i; // [esp+Ch] [ebp-4h]
  ISequentialInStream *matchFinderIndexPrev; // [esp+20h] [ebp+10h]

  v4 = 0;
  i = 0;
  if ( numProperties != 0 )
  {
    while ( 2 )
    {
      switch ( propIDs[v4] )
      {
        case 0x400u:
          if ( properties->vt != 19 )
            return -2147024809;
          Lo32 = properties->decVal.Lo32;
          if ( Lo32 - 1 > 0x3FFFFFFF )
            return -2147024809;
          this->_numLiteralPosStateBits = Lo32;
          v10 = 0;
          v11 = 1;
          do
          {
            if ( Lo32 <= v11 )
              break;
            ++v10;
            v11 = __ROL4__(v11, 1);
          }
          while ( v10 < 0x1E );
          this->_alignPrices[15] = 2 * v10;
          goto LABEL_32;
        case 0x440u:
          if ( properties->vt != 19 )
            return -2147024809;
          v12 = properties->decVal.Lo32;
          if ( v12 > 4 )
            return -2147024809;
          this->_alignPriceCount = v12;
          this->_distTableSize = (1 << v12) - 1;
          goto LABEL_32;
        case 0x441u:
          if ( properties->vt != 19 )
            return -2147024809;
          v14 = properties->decVal.Lo32;
          if ( v14 > 8 )
            return -2147024809;
          this->_posStateMask = v14;
          goto LABEL_32;
        case 0x442u:
          if ( properties->vt != 19 )
            return -2147024809;
          v13 = properties->decVal.Lo32;
          if ( v13 > 4 )
            return -2147024809;
          this->_posStateBits = v13;
          goto LABEL_32;
        case 0x450u:
          if ( properties->vt != 19 )
            return -2147024809;
          v6 = properties->decVal.Lo32;
          if ( v6 - 5 > 0x10C )
            return -2147024809;
          this->_matchDistances[548] = v6;
          goto LABEL_32;
        case 0x451u:
          if ( properties->vt != 8 )
            return -2147024809;
          matchFinderIndexPrev = this->_inStream;
          MatchFinder = (ISequentialInStream *)NCompress::NLZMA::FindMatchFinder(s: properties->bstrVal);
          if ( (int)MatchFinder < 0 )
            return -2147024809;
          v8 = this->_optimum[4095].Backs[2] == 0;
          this->_inStream = MatchFinder;
          if ( !v8 && matchFinderIndexPrev != MatchFinder )
          {
            this->_numLiteralContextBits = -1;
            NCompress::NLZMA::CEncoder::ReleaseMatchFinder(this: (NCompress::NLZMA::CEncoder *)((char *)this - 8));
          }
          goto LABEL_32;
        case 0x452u:
          if ( properties->vt != 19 )
            return -2147024809;
          *(_DWORD *)&this->_finished = properties->decVal.Lo32;
          goto LABEL_32;
        case 0x470u:
          if ( properties->vt != 19 )
            return -2147024809;
          LOBYTE(this->_matchDistances[547]) = properties->decVal.Lo32 == 0;
          goto LABEL_32;
        case 0x490u:
          if ( properties->vt != 11 )
            return -2147024809;
          LOBYTE(this->_matchFinderCycles) = properties->iVal == -1;
LABEL_32:
          v4 = i + 1;
          ++properties;
          i = v4;
          if ( v4 >= numProperties )
            return 0;
          continue;
        default:
          return -2147024809;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00523810
// Name: public: virtual long NCompress::NLZMA::CEncoder::ReleaseOutStream(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::ReleaseOutStream(NCompress::NLZMA::CEncoder *this)
{
  unsigned int bufferSize; // eax

  bufferSize = this->_rangeEncoder.Stream._bufferSize;
  if ( bufferSize != 0 )
  {
    (*(void (__stdcall **)(unsigned int))(*(_DWORD *)bufferSize + 8))(a1: this->_rangeEncoder.Stream._bufferSize);
    this->_rangeEncoder.Stream._bufferSize = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00523840
// Name: public: long NCompress::NLZMA::CEncoder::Init(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Init(NCompress::NLZMA::CEncoder *this)
{
  NCompress::NRangeCoder::CBitEncoder<5> *isRepG0; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v3; // edi
  unsigned int v4; // edx
  NCompress::NRangeCoder::CBitEncoder<5> *v5; // eax
  int v6; // ecx
  int v7; // edx
  NCompress::NLZMA::CLiteralEncoder2 *v8; // edi
  bool v9; // zf
  NCompress::NRangeCoder::CBitEncoder<5> *v10; // edx
  NCompress::NRangeCoder::CBitEncoder<5> *v11; // edi
  int i; // [esp+Ch] [ebp-4h]
  int v14; // [esp+Ch] [ebp-4h]
  int v15; // [esp+Ch] [ebp-4h]

  *(_WORD *)&this->_state.Index = 0;
  this->_repDistances[0] = 0;
  this->_repDistances[1] = 0;
  this->_repDistances[2] = 0;
  this->_repDistances[3] = 0;
  COutBuffer::Init(this: &this->_rangeEncoder.Stream);
  this->_rangeEncoder.Low = 0;
  this->_rangeEncoder.Range = -1;
  this->_rangeEncoder._cacheSize = 1;
  this->_rangeEncoder._cache = 0;
  isRepG0 = this->_isRepG0;
  v3 = this->_isRep0Long[0];
  for ( i = 12; i != 0; --i )
  {
    v4 = 0;
    v5 = v3;
    do
    {
      v5[-240].Prob = 1024;
      v5->Prob = 1024;
      ++v4;
      ++v5;
    }
    while ( v4 <= this->_posStateMask );
    isRepG0[-12].Prob = 1024;
    isRepG0->Prob = 1024;
    isRepG0[12].Prob = 1024;
    isRepG0[24].Prob = 1024;
    ++isRepG0;
    v3 += 16;
  }
  v6 = this->_literalEncoder._numPrevBits + this->_literalEncoder._numPosBits;
  if ( 1 << v6 != 0 )
  {
    v7 = 0;
    v14 = 1 << v6;
    do
    {
      v8 = &this->_literalEncoder._coders[v7++];
      v9 = v14-- == 1;
      memset32(v8, 1024, 0x300u);
    }
    while ( !v9 );
  }
  v10 = &this->_posSlotEncoder[0].Models[1];
  v15 = 4;
  do
  {
    v11 = v10;
    v10 += 64;
    v9 = v15-- == 1;
    memset32(v11, 1024, 0x3Fu);
  }
  while ( !v9 );
  memset32(this->_posEncoders, 1024, 0x72u);
  NCompress::NLZMA::NLength::CEncoder::Init(this: &this->_lenEncoder, numPosStates: 1 << this->_posStateBits);
  NCompress::NLZMA::NLength::CEncoder::Init(this: &this->_repMatchLenEncoder, numPosStates: 1 << this->_posStateBits);
  this->_posAlignEncoder.Models[1].Prob = 1024;
  this->_posAlignEncoder.Models[2].Prob = 1024;
  this->_posAlignEncoder.Models[3].Prob = 1024;
  this->_posAlignEncoder.Models[4].Prob = 1024;
  this->_posAlignEncoder.Models[5].Prob = 1024;
  this->_posAlignEncoder.Models[6].Prob = 1024;
  this->_posAlignEncoder.Models[7].Prob = 1024;
  this->_posAlignEncoder.Models[8].Prob = 1024;
  this->_posAlignEncoder.Models[9].Prob = 1024;
  this->_posAlignEncoder.Models[10].Prob = 1024;
  this->_posAlignEncoder.Models[11].Prob = 1024;
  this->_posAlignEncoder.Models[12].Prob = 1024;
  this->_posAlignEncoder.Models[13].Prob = 1024;
  this->_posAlignEncoder.Models[14].Prob = 1024;
  this->_posAlignEncoder.Models[15].Prob = 1024;
  this->_longestMatchWasFound = false;
  this->_optimumEndIndex = 0;
  this->_optimumCurrentIndex = 0;
  this->_additionalOffset = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00523A10
// Name: private: long NCompress::NLZMA::CEncoder::ReadMatchDistances(unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::ReadMatchDistances(
        NCompress::NLZMA::CEncoder *this,
        unsigned int *lenRes,
        unsigned int *numDistancePairs)
{
  unsigned int *matchDistances; // ebx
  HRESULT result; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax

  *lenRes = 0;
  matchDistances = this->_matchDistances;
  result = this->_matchFinder._p->GetMatches(this: this->_matchFinder._p, a2: this->_matchDistances);
  if ( result == 0 )
  {
    v6 = *matchDistances;
    *numDistancePairs = *matchDistances;
    if ( v6 != 0 )
    {
      v7 = *(&this->_literalEncoder._posMask + v6);
      *lenRes = v7;
      if ( v7 == this->_numFastBytes )
        *lenRes += this->_matchFinder._p->GetMatchLen(
                     this: this->_matchFinder._p,
                     a2: v7 - 1,
                     a3: this->_matchDistances[*numDistancePairs],
                     a4: 273 - v7);
    }
    ++this->_additionalOffset;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00523A90
// Name: private: long NCompress::NLZMA::CEncoder::GetOptimumFast(unsigned int,unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetOptimumFast(
        NCompress::NLZMA::CEncoder *this,
        unsigned int position,
        unsigned int *backRes,
        unsigned int *lenRes)
{
  NCompress::NLZMA::CEncoder *v4; // ebx
  bool v5; // zf
  unsigned int result; // eax
  unsigned int v7; // eax
  const unsigned __int8 *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  const unsigned __int8 *v11; // ecx
  unsigned int j; // eax
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int *v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned int longestMatchLength; // eax
  unsigned int v20; // esi
  unsigned int v21; // edx
  unsigned int *repDistances; // esi
  const unsigned __int8 *v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int repLens[4]; // [esp+4h] [ebp-28h]
  unsigned int newDistance; // [esp+14h] [ebp-18h]
  unsigned int i; // [esp+18h] [ebp-14h]
  unsigned int numDistancePairs; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int numAvailableBytes; // [esp+20h] [ebp-Ch]
  unsigned int backMain; // [esp+24h] [ebp-8h]
  unsigned int lenMain; // [esp+28h] [ebp-4h] BYREF

  v4 = this;
  v5 = !this->_longestMatchWasFound;
  newDistance = (unsigned int)this;
  if ( v5 )
  {
    result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &lenMain, &numDistancePairs);
    if ( result != 0 )
      return result;
  }
  else
  {
    v7 = this->_numDistancePairs;
    lenMain = this->_longestMatchLength;
    numDistancePairs = v7;
    this->_longestMatchWasFound = false;
  }
  v8 = v4->_matchFinder._p->GetPointerToCurrentPos(this: v4->_matchFinder._p);
  v9 = v4->_matchFinder._p->GetNumAvailableBytes(this: v4->_matchFinder._p) + 1;
  numAvailableBytes = v9;
  if ( v9 <= 0x111 )
  {
    if ( v9 < 2 )
    {
      *backRes = -1;
      *lenRes = 1;
      return 0;
    }
  }
  else
  {
    numAvailableBytes = 273;
  }
  v10 = 0;
  i = 0;
  backMain = 0;
  while ( 1 )
  {
    v11 = &v8[-v4->_repDistances[v10] - 2];
    if ( *(v8 - 1) == *v11 && *v8 == v8[-v4->_repDistances[v10] - 1] )
      break;
    repLens[v10] = 0;
LABEL_19:
    if ( ++v10 >= 4 )
    {
      v14 = lenMain;
      if ( lenMain >= v4->_numFastBytes )
      {
        *backRes = v4->_matchDistances[numDistancePairs] + 4;
        result = v14 - 1;
        *lenRes = v14;
        if ( v14 == 1 )
          return result;
        goto LABEL_24;
      }
      backMain = 0;
      if ( lenMain >= 2 )
      {
        v15 = numDistancePairs;
        backMain = v4->_matchDistances[numDistancePairs];
        if ( numDistancePairs > 2 )
        {
          v16 = (unsigned int *)(&v4->_literalEncoder._numPosBits + numDistancePairs);
          do
          {
            if ( lenMain != *(v16 - 1) + 1 )
              break;
            if ( backMain >> 7 <= *v16 )
              break;
            v17 = *(v16 - 1);
            v16 -= 2;
            v15 -= 2;
            lenMain = v17;
            backMain = v16[2];
          }
          while ( v15 > 2 );
          v14 = lenMain;
        }
        if ( v14 == 2 && backMain >= 0x80 )
        {
          lenMain = 1;
          v14 = 1;
        }
      }
      v18 = repLens[i];
      if ( v18 >= 2 && (v18 + 1 >= v14 || v18 + 2 >= v14 && backMain > 0x200 || v18 + 3 >= v14 && backMain > 0x8000) )
      {
        *backRes = i;
        *lenRes = v18;
        result = v18 - 1;
        if ( result != 0 )
          goto LABEL_24;
        return result;
      }
      if ( v14 < 2 || numAvailableBytes <= 2 )
      {
        *backRes = -1;
        *lenRes = 1;
        return 0;
      }
      result = NCompress::NLZMA::CEncoder::ReadMatchDistances(
                 this: v4,
                 lenRes: &v4->_longestMatchLength,
                 numDistancePairs: &v4->_numDistancePairs);
      if ( result != 0 )
        return result;
      longestMatchLength = v4->_longestMatchLength;
      if ( longestMatchLength >= 2 )
      {
        v20 = v4->_matchDistances[v4->_numDistancePairs];
        newDistance = v20;
        if ( longestMatchLength >= lenMain && v20 < backMain )
          goto LABEL_56;
        if ( longestMatchLength == lenMain + 1 )
        {
          if ( v20 >> 7 <= backMain )
          {
LABEL_56:
            v4->_longestMatchWasFound = true;
            *backRes = -1;
            *lenRes = 1;
            return 0;
          }
          v20 = newDistance;
        }
        if ( longestMatchLength > lenMain + 1
          || longestMatchLength + 1 >= lenMain && lenMain >= 3 && backMain >> 7 > v20 )
        {
          goto LABEL_56;
        }
      }
      --numAvailableBytes;
      v21 = 0;
      i = 0;
      repDistances = v4->_repDistances;
      do
      {
        v23 = &v8[-*repDistances - 1];
        if ( v8[1] == v8[-*repDistances] && v8[2] == v23[2] )
        {
          v24 = 2;
          if ( numAvailableBytes > 2 )
          {
            do
            {
              if ( v8[v24] != v23[v24] )
                break;
              ++v24;
            }
            while ( v24 < numAvailableBytes );
            v21 = i;
          }
          if ( v24 + 1 >= lenMain )
            goto LABEL_56;
        }
        else
        {
          repLens[v21] = 0;
        }
        ++v21;
        ++repDistances;
        i = v21;
      }
      while ( v21 < 4 );
      *backRes = backMain + 4;
      v25 = lenMain;
      *lenRes = lenMain;
      result = v25 - 2;
      if ( result != 0 )
        goto LABEL_24;
      return 0;
    }
  }
  for ( j = 2; j < numAvailableBytes; ++j )
  {
    if ( v8[j - 1] != v11[j] )
      break;
  }
  v4 = (NCompress::NLZMA::CEncoder *)newDistance;
  if ( j < *(_DWORD *)(newDistance + 208512) )
  {
    v13 = backMain;
    repLens[v10] = j;
    if ( j > *(unsigned int *)((char *)repLens + v13) )
    {
      i = v10;
      backMain = 4 * v10;
    }
    goto LABEL_19;
  }
  *backRes = v10;
  *lenRes = j;
  result = j - 1;
  if ( result != 0 )
  {
LABEL_24:
    v4->_additionalOffset += result;
    return v4->_matchFinder._p->Skip(this: v4->_matchFinder._p, a2: result);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00523E20
// Name: private: void NCompress::NLZMA::CEncoder::FillDistancesPrices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::FillDistancesPrices(NCompress::NLZMA::CEncoder *this)
{
  NCompress::NLZMA::CEncoder *v1; // ebx
  unsigned int i; // esi
  int v3; // eax
  unsigned int *v4; // esi
  unsigned int *v5; // edx
  unsigned int v6; // edi
  unsigned int v7; // ecx
  unsigned int v8; // esi
  char v9; // al
  unsigned int j; // eax
  unsigned int v11; // eax
  _DWORD *v12; // esi
  int v13; // ecx
  unsigned int tempPrices[128]; // [esp+Ch] [ebp-210h] BYREF
  NCompress::NLZMA::CEncoder *v15; // [esp+20Ch] [ebp-10h]
  int v16; // [esp+210h] [ebp-Ch]
  char *v17; // [esp+214h] [ebp-8h]
  unsigned int *v18; // [esp+218h] [ebp-4h]

  v1 = this;
  v15 = this;
  for ( i = 4; i < 0x80; ++i )
  {
    v3 = (NCompress::NLZMA::g_FastPos[i] & 1 | 2) << ((NCompress::NLZMA::g_FastPos[i] >> 1) - 1);
    tempPrices[i] = NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(
                      Models: &v1->_posSlotEncoder[3].Models[v3 - NCompress::NLZMA::g_FastPos[i] + 63],
                      NumBitLevels: (NCompress::NLZMA::g_FastPos[i] >> 1) - 1,
                      symbol: i - v3);
  }
  v4 = &v1->_distancesPrices[0][2];
  v5 = v1->_posSlotPrices[0];
  v18 = &v1->_distancesPrices[0][2];
  v17 = (char *)((char *)tempPrices - (char *)v1 - 209564);
  v16 = 4;
  while ( 1 )
  {
    v6 = 0;
    if ( v1->_distTableSize != 0 )
    {
      do
      {
        v7 = v6 | 0x40;
        v8 = 0;
        if ( (v6 | 0x40) != 1 )
        {
          do
          {
            v9 = v7;
            v7 >>= 1;
            v8 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v9 & 1) ^ (v5[v7 - 10713] - (v9 & 1))) >> 2)
                                                                 & 0x1FF];
          }
          while ( v7 != 1 );
          v1 = v15;
        }
        v5[v6++] = v8;
      }
      while ( v6 < v1->_distTableSize );
      v4 = v18;
    }
    for ( j = 14; j < v1->_distTableSize; ++j )
      v5[j] += ((j >> 1) - 5) << 6;
    *(v4 - 2) = *v5;
    *(v4 - 1) = v5[1];
    *v4 = v5[2];
    v4[1] = v5[3];
    v11 = 4;
    v12 = v4 + 2;
    do
    {
      v13 = NCompress::NLZMA::g_FastPos[v11++];
      *v12 = *(_DWORD *)((char *)v12 + (_DWORD)v17) + v5[v13];
      ++v12;
    }
    while ( v11 < 0x80 );
    v18 += 128;
    v17 -= 512;
    v5 += 64;
    if ( --v16 == 0 )
      break;
    v4 = v18;
  }
  v1->_matchPriceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00523FF0
// Name: private: void NCompress::NLZMA::CEncoder::FillAlignPrices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::FillAlignPrices(NCompress::NLZMA::CEncoder *this)
{
  unsigned int v1; // edi
  unsigned int v2; // esi
  int v3; // edx
  int v4; // eax
  unsigned int *alignPrices; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  v1 = 0;
  i = 0;
  alignPrices = this->_alignPrices;
  do
  {
    v2 = 0;
    v3 = 1;
    for ( j = 4; j != 0; --j )
    {
      v4 = v1 & 1;
      v2 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v4 ^ (this->_posAlignEncoder.Models[v3].Prob - v4)) >> 2)
                                                           & 0x1FF];
      v1 >>= 1;
      v3 = v4 | (2 * v3);
    }
    v1 = i + 1;
    *alignPrices = v2;
    i = v1;
    ++alignPrices;
  }
  while ( v1 < 0x10 );
  this->_alignPriceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00524080
// Name: public: void NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(
        NCompress::NLZMA::NLength::CPriceTableEncoder *this,
        unsigned int numPosStates)
{
  unsigned int v2; // esi
  unsigned int *counters; // edi
  unsigned int *v4; // ebx

  v2 = 0;
  if ( numPosStates != 0 )
  {
    counters = this->_counters;
    v4 = this->_prices[0];
    do
    {
      NCompress::NLZMA::NLength::CEncoder::SetPrices(this, posState: v2, numSymbols: this->_tableSize, prices: v4);
      *counters = this->_tableSize;
      ++v2;
      ++counters;
      v4 += 272;
    }
    while ( v2 < numPosStates );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005240D0
// Name: public: void NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(
        NCompress::NLZMA::NLength::CPriceTableEncoder *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol,
        unsigned int posState,
        bool updatePrice)
{
  NCompress::NLZMA::NLength::CEncoder::Encode(this, rangeEncoder, symbol, posState);
  if ( updatePrice && this->_counters[posState]-- == 1 )
  {
    NCompress::NLZMA::NLength::CEncoder::SetPrices(
      this,
      posState,
      numSymbols: this->_tableSize,
      prices: this->_prices[posState]);
    this->_counters[posState] = this->_tableSize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524130
// Name: public: NBT3::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT3::CMatchFinder *__thiscall NBT3::CMatchFinder::CMatchFinder(NBT3::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT3::CMatchFinder_vtbl *)&NBT3::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT3::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT3::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00524160
// Name: public: NBT4::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT4::CMatchFinder *__thiscall NBT4::CMatchFinder::CMatchFinder(NBT4::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT4::CMatchFinder_vtbl *)&NBT4::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT4::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT4::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00524190
// Name: public: NHC4::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NHC4::CMatchFinder *__thiscall NHC4::CMatchFinder::CMatchFinder(NHC4::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NHC4::CMatchFinder_vtbl *)&NHC4::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NHC4::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NHC4::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005241C0
// Name: public: NCompress::NLZMA::CEncoder::CEncoder(void)
// Source: json
//------------------------------------------------------------------------------
NCompress::NLZMA::CEncoder *__thiscall NCompress::NLZMA::CEncoder::CEncoder(NCompress::NLZMA::CEncoder *this)
{
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&ICompressSetOutStream::`vftable';
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&ICompressSetCoderProperties::`vftable';
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&ICompressWriteCoderProperties::`vftable';
  this->__m_RefCount = 0;
  this->ICompressCoder::IUnknown::__vftable = (NCompress::NLZMA::CEncoder_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressCoder'};
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetOutStream'};
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetCoderProperties'};
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressWriteCoderProperties'};
  this->_matchFinder._p = nullptr;
  this->_rangeEncoder.Stream._buffer = nullptr;
  this->_rangeEncoder.Stream._pos = 0;
  this->_rangeEncoder.Stream._stream._p = nullptr;
  this->_rangeEncoder.Stream._buffer2 = nullptr;
  this->_literalEncoder._coders = nullptr;
  this->_posStateMask = 3;
  this->_numLiteralContextBits = 3;
  this->_numFastBytes = 32;
  this->_distTableSize = 44;
  this->_posStateBits = 2;
  this->_numLiteralPosStateBits = 0;
  this->_dictionarySize = 0x400000;
  this->_dictionarySizePrev = -1;
  this->_numFastBytesPrev = -1;
  this->_matchFinderCycles = 0;
  this->_matchFinderIndex = 2;
  this->_writeEndMark = false;
  this->setMfPasses = nullptr;
  this->_fastMode = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00524290
// Name: _IsEqualGUID
// Source: json
//------------------------------------------------------------------------------
int __cdecl IsEqualGUID(const _GUID *rguid1, const _GUID *rguid2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( rguid1->Data1 == rguid2->Data1 )
  {
    v4 -= 4;
    rguid2 = (const _GUID *)((char *)rguid2 + 4);
    rguid1 = (const _GUID *)((char *)rguid1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00524300
// Name: public: virtual long NCompress::NLZMA::CEncoder::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::QueryInterface(
        NCompress::NLZMA::CEncoder *this,
        const _GUID *iid,
        void **outObject)
{
  NCompress::NLZMA::CEncoder *v3; // eax

  if ( IsEqualGUID(rguid1: iid, rguid2: (const _GUID *)&IID_ICompressSetOutStream) != 0 )
  {
    v3 = this;
    if ( this != nullptr )
    {
      *outObject = &this->ICompressSetOutStream;
      this->AddRef(a1: this);
      return 0;
    }
    goto LABEL_4;
  }
  if ( IsEqualGUID(rguid1: iid, rguid2: (const _GUID *)&IID_ICompressSetCoderProperties) != 0 )
  {
    v3 = this;
    if ( this != nullptr )
    {
      *outObject = &this->ICompressSetCoderProperties;
      this->AddRef(a1: this);
      return 0;
    }
LABEL_4:
    *outObject = nullptr;
    v3->AddRef(a1: v3);
    return 0;
  }
  if ( IsEqualGUID(rguid1: iid, rguid2: (const _GUID *)&IID_ICompressWriteCoderProperties) == 0 )
    return -2147467262;
  v3 = this;
  if ( this == nullptr )
    goto LABEL_4;
  *outObject = &this->ICompressWriteCoderProperties;
  this->AddRef(a1: this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005243C0
// Name: public: virtual unsigned long NCompress::NLZMA::CEncoder::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NCompress::NLZMA::CEncoder::AddRef(NCompress::NLZMA::CEncoder *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005243E0
// Name: public: virtual unsigned long NCompress::NLZMA::CEncoder::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NCompress::NLZMA::CEncoder::Release(NCompress::NLZMA::CEncoder *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    ((void (__thiscall *)(NCompress::NLZMA::CEncoder *, int))this->dtr_CEncoder)(a1: this, a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00524490
// Name: public: virtual NCompress::NLZMA::CEncoder::~CEncoder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::~CEncoder(NCompress::NLZMA::CEncoder *this)
{
  ISequentialOutStream *p; // edi
  IMatchFinder *v3; // esi

  this->ICompressCoder::IUnknown::__vftable = (NCompress::NLZMA::CEncoder_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressCoder'};
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetOutStream'};
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetCoderProperties'};
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressWriteCoderProperties'};
  MyFree(address: this->_literalEncoder._coders);
  this->_literalEncoder._coders = nullptr;
  COutBuffer::Free(this: &this->_rangeEncoder.Stream);
  p = this->_rangeEncoder.Stream._stream._p;
  if ( p != nullptr )
    p->Release(a1: this->_rangeEncoder.Stream._stream._p);
  v3 = this->_matchFinder._p;
  if ( v3 != nullptr )
    v3->Release(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00524540
// Name: private: long NCompress::NLZMA::CEncoder::GetOptimum(unsigned int,unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
HRESULT __userpurge NCompress::NLZMA::CEncoder::GetOptimum@<eax>(
        NCompress::NLZMA::CEncoder *this@<ecx>,
        IMatchFinder *a2@<esi>,
        unsigned int position,
        unsigned int *backRes,
        unsigned int *lenRes)
{
  unsigned int optimumCurrentIndex; // eax
  int v7; // ecx
  int v8; // edx
  char *v9; // ecx
  HRESULT result; // eax
  bool v11; // zf
  unsigned int v12; // edx
  const unsigned __int8 *v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // ecx
  const unsigned __int8 *v18; // edi
  unsigned int i; // ecx
  unsigned int v20; // eax
  bool v21; // cc
  unsigned int v22; // edi
  unsigned int numFastBytes; // ecx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned __int8 v26; // cl
  unsigned __int8 v27; // dl
  unsigned __int8 Index; // cl
  unsigned int posStateMask; // edi
  unsigned __int8 v30; // dl
  int numPrevBits; // eax
  unsigned int v32; // edi
  int v33; // edx
  unsigned __int8 v34; // cl
  unsigned int v35; // esi
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  unsigned int *p_Price; // ecx
  unsigned int v40; // esi
  unsigned int PureRepPrice; // eax
  unsigned int v42; // eax
  unsigned int *v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // eax
  unsigned int *j; // esi
  unsigned int PosLenPrice; // eax
  unsigned int v50; // eax
  unsigned int v51; // edx
  HRESULT (__stdcall *GetMatches)(IMatchFinder *, unsigned int *); // eax
  unsigned int v53; // esi
  unsigned int v54; // edi
  unsigned int v55; // edx
  int v56; // esi
  char *v57; // eax
  char v58; // dl
  int v59; // ecx
  int v60; // ecx
  unsigned __int8 v61; // cl
  unsigned int v62; // edi
  unsigned __int8 v63; // cl
  NCompress::NLZMA::COptimal *v64; // edx
  unsigned int v65; // esi
  unsigned int v66; // ecx
  unsigned int v67; // edx
  unsigned int v68; // edx
  unsigned int v69; // esi
  unsigned int v70; // ecx
  const unsigned __int8 *v71; // edi
  unsigned __int8 v72; // al
  unsigned __int8 v73; // dl
  unsigned int v74; // esi
  int v75; // eax
  unsigned int v76; // edx
  unsigned int v77; // esi
  unsigned int v78; // eax
  unsigned int v79; // esi
  NCompress::NLZMA::COptimal *v80; // eax
  unsigned int v81; // ecx
  unsigned int v82; // ecx
  unsigned int v83; // eax
  unsigned int v84; // ecx
  unsigned int v85; // ecx
  unsigned int v86; // ecx
  unsigned int v87; // ecx
  unsigned int v88; // eax
  unsigned int v89; // edi
  unsigned int v90; // edx
  unsigned int v91; // ecx
  unsigned int v92; // edx
  unsigned int v93; // esi
  unsigned int v94; // ecx
  unsigned int v95; // edi
  unsigned int *v96; // ecx
  unsigned int v97; // ecx
  NCompress::NLZMA::COptimal *v98; // eax
  unsigned int v99; // eax
  unsigned int v100; // eax
  const unsigned __int8 *v101; // ecx
  unsigned int k; // edi
  unsigned int v103; // eax
  unsigned int *v104; // ecx
  unsigned int v105; // esi
  unsigned int v106; // eax
  unsigned int v107; // eax
  unsigned int *v108; // ecx
  unsigned int v109; // edx
  unsigned int v110; // eax
  unsigned int v111; // ecx
  const unsigned __int8 *v112; // edi
  unsigned int v113; // eax
  unsigned int v114; // ecx
  int v115; // eax
  unsigned int v116; // edi
  unsigned int v117; // eax
  unsigned int v118; // eax
  unsigned int v119; // edx
  unsigned int v120; // ecx
  _DWORD *v121; // edi
  unsigned int v122; // ecx
  NCompress::NLZMA::COptimal *v123; // eax
  unsigned int v124; // edx
  unsigned int v125; // ecx
  unsigned int v126; // edx
  int v127; // eax
  unsigned int v128; // edi
  unsigned int v129; // eax
  unsigned int *v130; // edx
  unsigned int v131; // eax
  unsigned int v132; // eax
  unsigned int v133; // ecx
  int v134; // esi
  unsigned int *v135; // edx
  unsigned int v136; // edi
  unsigned int v137; // eax
  unsigned int v138; // eax
  unsigned int v139; // eax
  unsigned int v140; // ecx
  unsigned int v141; // eax
  unsigned int v142; // esi
  const unsigned __int8 *v143; // eax
  unsigned int v144; // eax
  unsigned int v145; // esi
  int v146; // edx
  unsigned __int8 v147; // cl
  int v148; // edi
  unsigned int Prob; // edx
  unsigned int v150; // esi
  int v151; // edi
  int v152; // eax
  unsigned int v153; // eax
  unsigned int v154; // eax
  unsigned int v155; // edx
  unsigned int v156; // ecx
  _DWORD *v157; // esi
  unsigned int v158; // ecx
  NCompress::NLZMA::COptimal *v159; // eax
  unsigned int v160; // edx
  unsigned int v161; // edx
  unsigned int v162; // ecx
  unsigned int v163; // eax
  unsigned int v164; // eax
  unsigned int v165; // eax
  IMatchFinder *p; // [esp-10h] [ebp-98h]
  unsigned __int8 v167; // [esp-Ch] [ebp-94h]
  unsigned __int8 v168; // [esp-Ch] [ebp-94h]
  unsigned int repLens[4]; // [esp+4h] [ebp-84h]
  unsigned int v171; // [esp+14h] [ebp-74h]
  unsigned int v172; // [esp+18h] [ebp-70h]
  unsigned int curAndLenPrice; // [esp+1Ch] [ebp-6Ch]
  unsigned __int8 matchByte[4]; // [esp+20h] [ebp-68h]
  int currentByte; // [esp+24h] [ebp-64h]
  unsigned int reps[4]; // [esp+28h] [ebp-60h] BYREF
  unsigned int price; // [esp+38h] [ebp-50h]
  unsigned int backOffset; // [esp+3Ch] [ebp-4Ch]
  unsigned int v179; // [esp+40h] [ebp-48h]
  unsigned int newLen; // [esp+44h] [ebp-44h]
  unsigned int lenTest2; // [esp+48h] [ebp-40h]
  unsigned int repMatchPrice; // [esp+4Ch] [ebp-3Ch]
  const unsigned __int8 *data; // [esp+50h] [ebp-38h]
  unsigned int normalMatchPrice; // [esp+54h] [ebp-34h]
  unsigned int numDistancePairs; // [esp+58h] [ebp-30h] BYREF
  unsigned int posState; // [esp+5Ch] [ebp-2Ch]
  unsigned int curPrice; // [esp+60h] [ebp-28h]
  unsigned int startLen; // [esp+64h] [ebp-24h]
  unsigned int offs; // [esp+68h] [ebp-20h]
  unsigned int state; // [esp+6Ch] [ebp-1Ch] OVERLAPPED
  bool nextIsChar; // [esp+73h] [ebp-15h]
  unsigned int lenEnd; // [esp+74h] [ebp-14h]
  unsigned int cur; // [esp+78h] [ebp-10h]
  unsigned int posSlot; // [esp+7Ch] [ebp-Ch] BYREF
  unsigned int repIndex; // [esp+80h] [ebp-8h]
  unsigned int curBack; // [esp+84h] [ebp-4h]

  optimumCurrentIndex = this->_optimumCurrentIndex;
  if ( this->_optimumEndIndex != optimumCurrentIndex )
  {
    v7 = 5 * optimumCurrentIndex + 5;
    v8 = *((_DWORD *)&this->_state.Index + 2 * v7);
    v9 = (char *)this + 8 * v7;
    *lenRes = v8 - optimumCurrentIndex;
    *backRes = *((_DWORD *)v9 + 5);
    this->_optimumCurrentIndex = *((_DWORD *)v9 + 4);
    return 0;
  }
  v11 = !this->_longestMatchWasFound;
  this->_optimumEndIndex = 0;
  this->_optimumCurrentIndex = 0;
  if ( v11 )
  {
    result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &posSlot, &numDistancePairs);
    if ( result != 0 )
      return result;
  }
  else
  {
    v12 = this->_numDistancePairs;
    posSlot = this->_longestMatchLength;
    numDistancePairs = v12;
    this->_longestMatchWasFound = false;
  }
  v13 = this->_matchFinder._p->GetPointerToCurrentPos(this: this->_matchFinder._p) - 1;
  v14 = this->_matchFinder._p->GetNumAvailableBytes(this: this->_matchFinder._p) + 1;
  curBack = v14;
  if ( v14 < 2 )
  {
LABEL_8:
    *backRes = -1;
    *lenRes = 1;
    return 0;
  }
  if ( v14 > 0x111 )
    curBack = 273;
  v15 = 0;
  offs = 0;
  repIndex = 0;
  curPrice = 0;
  do
  {
    v16 = v15;
    v17 = this->_repDistances[v15];
    reps[v15] = v17;
    v18 = &v13[-v17 - 1];
    if ( *v13 == *v18 && v13[1] == v13[-v17] )
    {
      for ( i = 2; i < curBack; ++i )
      {
        if ( v13[i] != v18[i] )
          break;
      }
      v20 = curPrice;
      repLens[v16] = i;
      v21 = i <= *(unsigned int *)((char *)repLens + v20);
      v15 = repIndex;
      if ( !v21 )
      {
        offs = repIndex;
        curPrice = v16 * 4;
      }
    }
    else
    {
      repLens[v15] = 0;
    }
    repIndex = ++v15;
  }
  while ( v15 < 4 );
  v22 = repLens[offs];
  numFastBytes = this->_numFastBytes;
  normalMatchPrice = v22;
  if ( v22 >= numFastBytes )
  {
    *backRes = offs;
    *lenRes = v22;
    if ( v22 != 1 )
    {
      this->_additionalOffset += v22 - 1;
      return this->_matchFinder._p->Skip(this: this->_matchFinder._p, a2: v22 - 1);
    }
    return 0;
  }
  v24 = posSlot;
  if ( posSlot >= numFastBytes )
  {
    *backRes = this->_matchDistances[numDistancePairs] + 4;
    *lenRes = v24;
    v25 = v24 - 1;
    if ( v25 != 0 )
    {
      this->_additionalOffset += v25;
      return this->_matchFinder._p->Skip(this: this->_matchFinder._p, a2: v25);
    }
    return 0;
  }
  v26 = *v13;
  LOBYTE(curPrice) = *v13;
  v27 = v13[-reps[0] - 1];
  LOBYTE(posState) = v27;
  if ( posSlot < 2 && v26 != v27 && v22 < 2 )
    goto LABEL_8;
  Index = this->_state.Index;
  posStateMask = this->_posStateMask;
  v30 = curPrice;
  this->_optimum[0].State.Index = Index;
  numPrevBits = this->_literalEncoder._numPrevBits;
  v167 = v30;
  v32 = position & posStateMask;
  v33 = this->_previousByte >> (8 - numPrevBits);
  repMatchPrice = position & this->_literalEncoder._posMask;
  this->_optimum[1].Price = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[this->_state.Index][v32].Prob >> 2]
                          + NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                              this: &this->_literalEncoder._coders[(repMatchPrice << numPrevBits) + v33],
                              matchMode: Index >= 7u,
                              matchByte: posState,
                              symbol: v167);
  this->_optimum[1].BackPrev = -1;
  this->_optimum[1].Prev1IsChar = false;
  v34 = this->_state.Index;
  v35 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[v34][v32].Prob) >> 2]
      + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v34].Prob) >> 2];
  startLen = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[v34][v32].Prob) >> 2];
  repMatchPrice = v35;
  if ( (_BYTE)posState == (_BYTE)curPrice )
  {
    v36 = v35
        + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[v34].Prob >> 2]
        + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep0Long[v34][v32].Prob >> 2];
    if ( v36 < this->_optimum[1].Price )
    {
      this->_optimum[1].Price = v36;
      this->_optimum[1].BackPrev = 0;
      this->_optimum[1].Prev1IsChar = false;
    }
  }
  v37 = normalMatchPrice;
  if ( posSlot < normalMatchPrice )
  {
    lenEnd = normalMatchPrice;
  }
  else
  {
    v37 = posSlot;
    lenEnd = posSlot;
  }
  if ( v37 < 2 )
  {
    *backRes = this->_optimum[1].BackPrev;
    *lenRes = 1;
    return 0;
  }
  v38 = reps[0];
  this->_optimum[1].PosPrev = 0;
  this->_optimum[0].Backs[0] = v38;
  this->_optimum[0].Backs[1] = reps[1];
  this->_optimum[0].Backs[2] = reps[2];
  this->_optimum[0].Backs[3] = reps[3];
  p_Price = &this->_optimum[v37].Price;
  do
  {
    *p_Price = 0xFFFFFFF;
    --v37;
    p_Price -= 10;
  }
  while ( v37 >= 2 );
  for ( repIndex = 0; repIndex < 4; ++repIndex )
  {
    v40 = repLens[repIndex];
    if ( v40 >= 2 )
    {
      PureRepPrice = NCompress::NLZMA::CEncoder::GetPureRepPrice(this, repIndex, state: this->_state, posState: v32);
      v42 = repMatchPrice + PureRepPrice;
      curBack = (unsigned int)&this->_repMatchLenEncoder._highCoder.Models[272 * v32 + 254 + v40];
      v43 = &this->_optimum[v40].Price;
      do
      {
        v44 = v42 + *(_DWORD *)curBack;
        if ( v44 < *v43 )
        {
          *v43 = v44;
          v45 = repIndex;
          v43[1] = 0;
          v43[2] = v45;
          *((_BYTE *)v43 - 11) = 0;
        }
        curBack -= 4;
        --v40;
        v43 -= 10;
      }
      while ( v40 >= 2 );
    }
  }
  repMatchPrice = startLen
                + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep[this->_state.Index].Prob >> 2];
  if ( repLens[0] < 2 )
    v46 = 2;
  else
    v46 = repLens[0] + 1;
  state = v46;
  if ( v46 <= posSlot )
  {
    v47 = 0;
    posSlot = 0;
    if ( state > this->_matchDistances[1] )
    {
      do
        v47 += 2;
      while ( state > this->_matchDistances[v47 + 1] );
      posSlot = v47;
    }
    for ( j = &this->_optimum[state].Price; ; j += 10 )
    {
      normalMatchPrice = this->_matchDistances[posSlot + 2];
      PosLenPrice = NCompress::NLZMA::CEncoder::GetPosLenPrice(this, pos: normalMatchPrice, len: state, posState: v32);
      v50 = repMatchPrice + PosLenPrice;
      if ( v50 < *j )
      {
        v51 = normalMatchPrice + 4;
        *j = v50;
        j[1] = 0;
        j[2] = v51;
        *((_BYTE *)j - 11) = 0;
      }
      if ( state == this->_matchDistances[posSlot + 1] )
      {
        posSlot += 2;
        if ( posSlot == numDistancePairs )
          break;
      }
      ++state;
    }
  }
  cur = 1;
  if ( lenEnd == 1 )
  {
LABEL_193:
    *lenRes = NCompress::NLZMA::CEncoder::Backward(this, backRes, cur);
    return 0;
  }
  while ( 1 )
  {
    p = this->_matchFinder._p;
    GetMatches = p->GetMatches;
    v53 = 0;
    newLen = 0;
    result = GetMatches(this: p, a2: this->_matchDistances);
    if ( result != 0 )
      return result;
    v54 = this->_matchDistances[0];
    repMatchPrice = v54;
    if ( v54 != 0 )
    {
      v53 = *(&this->_literalEncoder._posMask + v54);
      newLen = v53;
      if ( v53 == this->_numFastBytes )
      {
        v53 += this->_matchFinder._p->GetMatchLen(
                 this: this->_matchFinder._p,
                 a2: v53 - 1,
                 a3: this->_matchDistances[v54],
                 a4: 273 - v53);
        newLen = v53;
      }
    }
    ++this->_additionalOffset;
    if ( v53 >= this->_numFastBytes )
    {
      this->_numDistancePairs = v54;
      this->_longestMatchLength = v53;
      this->_longestMatchWasFound = true;
      goto LABEL_193;
    }
    ++position;
    v55 = 5 * cur + 5;
    v56 = *((_DWORD *)&this->_state.Index + 2 * v55);
    v57 = (char *)this + 8 * v55;
    v58 = v57[1];
    if ( v58 != 0 )
    {
      --v56;
      if ( v57[2] != 0 )
      {
        v59 = this->_optimum[*((_DWORD *)v57 + 1)].State.Index;
        if ( *((_DWORD *)v57 + 2) >= 4u )
          v60 = kMatchNextStates_0[v59];
        else
          v60 = kRepNextStates_0[v59];
        v61 = kLiteralNextStates_0[v60];
      }
      else
      {
        v61 = kLiteralNextStates_0[this->_optimum[v56].State.Index];
      }
    }
    else
    {
      v61 = this->_optimum[v56].State.Index;
    }
    if ( v56 == cur - 1 )
    {
      if ( *((_DWORD *)v57 + 5) != 0 )
        LOBYTE(state) = kLiteralNextStates_0[v61];
      else
        LOBYTE(state) = kShortRepNextStates_0[v61];
    }
    else
    {
      if ( v58 != 0 && v57[2] != 0 )
      {
        v62 = *((_DWORD *)v57 + 2);
        v56 = *((_DWORD *)v57 + 1);
        v63 = kRepNextStates_0[v61];
        posSlot = v62;
      }
      else
      {
        posSlot = *((_DWORD *)v57 + 5);
        v62 = posSlot;
        if ( posSlot >= 4 )
          v63 = kMatchNextStates_0[v61];
        else
          v63 = kRepNextStates_0[v61];
      }
      LOBYTE(state) = v63;
      v64 = &this->_optimum[v56];
      if ( v62 >= 4 )
      {
        reps[1] = v64->Backs[0];
        v66 = v64->Backs[1];
        v67 = v64->Backs[2];
        reps[0] = v62 - 4;
        reps[2] = v66;
        reps[3] = v67;
      }
      else
      {
        v65 = 1;
        reps[0] = v64->Backs[v62];
        if ( v62 == 0 || (qmemcpy(&reps[1], v64->Backs, 4 * v62), v65 = posSlot + 1, posSlot + 1 < 4) )
          qmemcpy(&reps[v65], &v64->Backs[v65], 4 * (4 - v65));
      }
    }
    v68 = reps[1];
    v69 = reps[0];
    *v57 = state;
    v70 = reps[2];
    *((_DWORD *)v57 + 7) = v68;
    *((_DWORD *)v57 + 9) = reps[3];
    *((_DWORD *)v57 + 6) = v69;
    *((_DWORD *)v57 + 8) = v70;
    curPrice = *((_DWORD *)v57 + 3);
    v71 = (const unsigned __int8 *)(((int (__stdcall *)(IMatchFinder *, IMatchFinder *))this->_matchFinder._p->GetPointerToCurrentPos)(
                                      a1: this->_matchFinder._p,
                                      a2)
                                  - 1);
    v72 = *v71;
    v73 = v71[-v69 - 1];
    v74 = position & this->_posStateMask;
    matchByte[0] = v73;
    numDistancePairs = (unsigned __int8)state;
    curBack = v74 + 16 * (unsigned __int8)state;
    LOBYTE(currentByte) = v72;
    v75 = this->_literalEncoder._numPrevBits;
    v168 = v73;
    v76 = *(v71 - 1);
    posState = v74;
    v77 = (position & this->_literalEncoder._posMask) << v75;
    data = v71;
    v78 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
            this: &this->_literalEncoder._coders[v77 + (v76 >> (8 - v75))],
            matchMode: (unsigned __int8)state >= 7u,
            matchByte: v168,
            symbol: currentByte);
    v79 = curPrice + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[0][curBack].Prob >> 2] + v78;
    v80 = &this->_optimum[cur + 1];
    nextIsChar = false;
    if ( v79 < v80->Price )
    {
      v81 = cur;
      v80->Price = v79;
      v80->PosPrev = v81;
      v80->BackPrev = -1;
      v80->Prev1IsChar = false;
      nextIsChar = true;
    }
    normalMatchPrice = curPrice
                     + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][curBack].Prob) >> 2];
    v172 = normalMatchPrice
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[numDistancePairs].Prob) >> 2];
    if ( matchByte[0] == (_BYTE)currentByte && (v80->PosPrev >= cur || v80->BackPrev != 0) )
    {
      v82 = v172
          + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[numDistancePairs].Prob >> 2]
          + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep0Long[0][curBack].Prob >> 2];
      if ( v82 <= v80->Price )
      {
        v80->Price = v82;
        v80->PosPrev = cur;
        v80->BackPrev = 0;
        v80->Prev1IsChar = false;
        nextIsChar = true;
      }
    }
    a2 = this->_matchFinder._p;
    v83 = ((int (*)(void))a2->GetNumAvailableBytes)() + 1;
    curPrice = v83;
    if ( 4095 - cur < v83 )
    {
      v83 = 4095 - cur;
      curPrice = 4095 - cur;
    }
    offs = v83;
    if ( v83 >= 2 )
    {
      v84 = this->_numFastBytes;
      if ( v83 > v84 )
        offs = this->_numFastBytes;
      if ( !nextIsChar && matchByte[0] != (_BYTE)currentByte )
      {
        v85 = v84 + 1;
        if ( v83 >= v85 )
        {
          v83 = v85;
          curBack = v85;
        }
        else
        {
          curBack = v83;
        }
        v86 = 1;
        if ( v83 > 1 )
        {
          do
          {
            if ( v71[v86] != v71[v86 - 1 - reps[0]] )
              break;
            ++v86;
          }
          while ( v86 < curBack );
        }
        curBack = v86 - 1;
        if ( v86 - 1 >= 2 )
        {
          v87 = kLiteralNextStates_0[numDistancePairs];
          v88 = this->_posStateMask & (position + 1);
          lenTest2 = v87;
          v89 = v88 + 16 * v87;
          v90 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v87].Prob) >> 2];
          v91 = 2048 - this->_isMatch[0][v89].Prob;
          v179 = v89;
          v92 = v79 + NCompress::NRangeCoder::CPriceTables::ProbPrices[v91 >> 2] + v90;
          v93 = curBack + cur + 1;
          v94 = lenEnd;
          if ( lenEnd < v93 )
          {
            startLen = (unsigned int)&this->_optimum[lenEnd].Price;
            v95 = v93 - lenEnd;
            lenEnd = curBack + cur + 1;
            v96 = &this->_optimum[v94].Price;
            do
            {
              v96 += 10;
              --v95;
              *v96 = 0xFFFFFFF;
            }
            while ( v95 != 0 );
            v89 = v179;
          }
          v97 = v92
              + this->_repMatchLenEncoder._highCoder.Models[272 * v88 + 254 + curBack].Prob
              + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[lenTest2].Prob >> 2]
              + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][v89].Prob) >> 2];
          v98 = &this->_optimum[v93];
          if ( v97 < v98->Price )
          {
            v98->Price = v97;
            v98->PosPrev = cur + 1;
            v98->BackPrev = 0;
            *(_WORD *)&v98->Prev1IsChar = 1;
          }
        }
      }
      repIndex = 0;
      v99 = 0;
      startLen = 2;
      do
      {
        v100 = reps[v99] + 1;
        v101 = &data[-v100];
        lenTest2 = v100;
        if ( *data == data[-v100] && data[1] == v101[1] )
        {
          for ( k = 2; k < offs; ++k )
          {
            if ( data[k] != v101[k] )
              break;
          }
          if ( lenEnd < k + cur )
          {
            v103 = k + cur - lenEnd;
            v104 = &this->_optimum[lenEnd].Price;
            lenEnd = k + cur;
            do
            {
              v104 += 10;
              --v103;
              *v104 = 0xFFFFFFF;
            }
            while ( v103 != 0 );
          }
          v105 = k;
          v106 = NCompress::NLZMA::CEncoder::GetPureRepPrice(this, repIndex, (NCompress::NLZMA::CState)state, posState);
          v107 = v172 + v106;
          v171 = 272 * posState;
          curBack = (unsigned int)&this->_repMatchLenEncoder._highCoder.Models[272 * posState + 254 + k];
          price = v107;
          v108 = &this->_optimum[k + cur].Price;
          do
          {
            v109 = v107 + *(_DWORD *)curBack;
            if ( v109 < *v108 )
            {
              *v108 = v109;
              v108[1] = cur;
              v108[2] = repIndex;
              *((_BYTE *)v108 - 11) = 0;
            }
            curBack -= 4;
            --k;
            v108 -= 10;
          }
          while ( k >= 2 );
          if ( repIndex == 0 )
            startLen = v105 + 1;
          v110 = v105 + 1;
          v111 = v105 + 1 + this->_numFastBytes;
          if ( curPrice < v111 )
            v111 = curPrice;
          if ( v110 < v111 )
          {
            v112 = &data[v110 - lenTest2];
            do
            {
              if ( data[v110] != *v112 )
                break;
              ++v110;
              ++v112;
            }
            while ( v110 < v111 );
          }
          v179 = -1 - v105 + v110;
          if ( v179 >= 2 )
          {
            v113 = this->_posStateMask;
            posSlot = kRepNextStates_0[numDistancePairs];
            curAndLenPrice = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[posSlot][(v105 + position) & v113].Prob >> 2];
            v114 = v113 & (v105 + position + 1);
            v115 = this->_literalEncoder._numPrevBits;
            posSlot = kLiteralNextStates_0[posSlot];
            v116 = this->_literalEncoder._posMask & (v105 + position);
            backOffset = v114;
            curBack = v114 + 16 * posSlot;
            v117 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                     this: &this->_literalEncoder._coders[(v116 << v115) + (data[v105 - 1] >> (8 - v115))],
                     matchMode: true,
                     matchByte: data[v105 - lenTest2],
                     symbol: data[v105]);
            v118 = price
                 + curAndLenPrice
                 + this->_repMatchLenEncoder._highCoder.Models[v105 + 254 + v171].Prob
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[posSlot].Prob) >> 2]
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][curBack].Prob) >> 2]
                 + v117;
            v119 = v105 + v179 + cur + 1;
            if ( lenEnd < v119 )
            {
              price = (unsigned int)&this->_optimum[lenEnd].Price;
              v120 = v119 - lenEnd;
              lenEnd = v105 + v179 + cur + 1;
              v121 = (_DWORD *)price;
              do
              {
                v121 += 10;
                --v120;
                *v121 = 0xFFFFFFF;
              }
              while ( v120 != 0 );
            }
            v122 = v118
                 + this->_repMatchLenEncoder._highCoder.Models[272 * backOffset + 254 + v179].Prob
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[posSlot].Prob >> 2]
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][curBack].Prob) >> 2];
            v123 = &this->_optimum[v119];
            if ( v122 < v123->Price )
            {
              v123->Price = v122;
              v124 = v105 + cur + 1;
              v123->PosPrev2 = cur;
              v125 = repIndex;
              v123->PosPrev = v124;
              v123->BackPrev = 0;
              *(_WORD *)&v123->Prev1IsChar = 257;
              v123->BackPrev2 = v125;
            }
          }
        }
        v99 = repIndex + 1;
        repIndex = v99;
      }
      while ( v99 < 4 );
      v126 = newLen;
      if ( newLen > offs )
      {
        v127 = 0;
        v126 = offs;
        if ( offs > this->_matchDistances[1] )
        {
          do
            v127 += 2;
          while ( offs > this->_matchDistances[v127 + 1] );
        }
        this->_matchDistances[v127 + 1] = offs;
        repMatchPrice = v127 + 2;
      }
      v128 = startLen;
      if ( v126 >= startLen )
      {
        normalMatchPrice += NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep[numDistancePairs].Prob >> 2];
        if ( lenEnd < v126 + cur )
        {
          v129 = v126 + cur - lenEnd;
          v130 = &this->_optimum[lenEnd].Price;
          lenEnd += v129;
          do
          {
            v130 += 10;
            --v129;
            *v130 = 0xFFFFFFF;
          }
          while ( v129 != 0 );
        }
        v131 = 0;
        offs = 0;
        if ( v128 > this->_matchDistances[1] )
        {
          do
            v131 += 2;
          while ( v128 > this->_matchDistances[v131 + 1] );
          offs = v131;
        }
        v132 = v131;
        v133 = this->_matchDistances[v132 + 2];
        startLen = v132 * 4;
        curBack = v133;
        if ( v133 >= 0x20000 )
        {
          if ( v133 >= 0x8000000 )
            v134 = NCompress::NLZMA::g_FastPos[v133 >> 26] + 52;
          else
            v134 = NCompress::NLZMA::g_FastPos[HIWORD(v133)] + 32;
        }
        else
        {
          v134 = NCompress::NLZMA::g_FastPos[v133 >> 6] + 12;
        }
        repIndex = v128 + 1;
        posState = (unsigned int)&this->_lenEncoder._highCoder.Models[272 * posState + 254 + v128];
        v135 = &this->_optimum[v128 + cur].Price;
        posSlot = v134;
        for ( newLen = (unsigned int)v135; ; v135 = (unsigned int *)newLen )
        {
          v136 = repIndex;
          v137 = repIndex - 3;
          if ( repIndex - 3 >= 4 )
            v137 = 3;
          if ( v133 >= 0x80 )
            v138 = this->_alignPrices[v133 & 0xF] + this->_posSlotPrices[v137][v134];
          else
            v138 = this->_distancesPrices[v137][v133];
          v139 = *(_DWORD *)posState + normalMatchPrice + v138;
          curAndLenPrice = v139;
          if ( v139 < *v135 )
          {
            *v135 = v139;
            v135[1] = cur;
            v135[2] = v133 + 4;
            *((_BYTE *)v135 - 11) = 0;
          }
          if ( v136 - 1 == *(unsigned int *)((char *)&this->_matchDistances[1] + startLen) )
          {
            v140 = curPrice;
            v141 = repIndex + this->_numFastBytes;
            backOffset = curBack + 1;
            v142 = repIndex;
            if ( curPrice >= v141 )
              v140 = v141;
            if ( repIndex < v140 )
            {
              v143 = &data[repIndex - (curBack + 1)];
              do
              {
                if ( data[v142] != *v143 )
                  break;
                ++v142;
                ++v143;
              }
              while ( v142 < v140 );
            }
            lenTest2 = -1 - (repIndex - 1) + v142;
            if ( lenTest2 >= 2 )
            {
              v144 = this->_posStateMask;
              v145 = position + repIndex - 1;
              v146 = kMatchNextStates_0[numDistancePairs];
              v147 = kLiteralNextStates_0[v146];
              v148 = v145 & v144;
              Prob = this->_isMatch[v146][v145 & v144].Prob;
              v179 = v147;
              price = NCompress::NRangeCoder::CPriceTables::ProbPrices[Prob >> 2];
              v150 = this->_literalEncoder._posMask & v145;
              v151 = v144 & (v148 + 1);
              v152 = this->_literalEncoder._numPrevBits;
              startLen = v151 + 16 * v147;
              v153 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                       this: &this->_literalEncoder._coders[(v150 << v152) + (data[repIndex - 2] >> (8 - v152))],
                       matchMode: true,
                       matchByte: data[repIndex - backOffset - 1],
                       symbol: data[repIndex - 1]);
              v154 = curAndLenPrice
                   + price
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][startLen].Prob) >> 2]
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v179].Prob) >> 2]
                   + v153;
              v155 = lenTest2 + repIndex + cur;
              if ( lenEnd < v155 )
              {
                backOffset = (unsigned int)&this->_optimum[lenEnd].Price;
                v156 = v155 - lenEnd;
                lenEnd = lenTest2 + repIndex + cur;
                v157 = (_DWORD *)backOffset;
                do
                {
                  v157 += 10;
                  --v156;
                  *v157 = 0xFFFFFFF;
                }
                while ( v156 != 0 );
              }
              v158 = v154
                   + this->_repMatchLenEncoder._highCoder.Models[272 * v151 + 254 + lenTest2].Prob
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[v179].Prob >> 2]
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][startLen].Prob) >> 2];
              v159 = &this->_optimum[v155];
              if ( v158 < v159->Price )
              {
                v160 = repIndex;
                v159->Price = v158;
                v161 = cur + v160;
                v159->PosPrev2 = cur;
                v162 = curBack + 4;
                v159->PosPrev = v161;
                v159->BackPrev = 0;
                *(_WORD *)&v159->Prev1IsChar = 257;
                v159->BackPrev2 = v162;
              }
            }
            v163 = offs + 2;
            offs = v163;
            if ( v163 == repMatchPrice )
              break;
            startLen = 4 * v163;
            v164 = this->_matchDistances[v163 + 2];
            curBack = v164;
            if ( v164 >= 0x80 )
            {
              if ( v164 >= 0x20000 )
              {
                if ( v164 >= 0x8000000 )
                  v165 = NCompress::NLZMA::g_FastPos[v164 >> 26] + 52;
                else
                  v165 = NCompress::NLZMA::g_FastPos[HIWORD(v164)] + 32;
              }
              else
              {
                v165 = NCompress::NLZMA::g_FastPos[v164 >> 6] + 12;
              }
              posSlot = v165;
            }
          }
          newLen += 40;
          posState += 4;
          ++repIndex;
          v134 = posSlot;
          v133 = curBack;
        }
      }
    }
    if ( ++cur == lenEnd )
      goto LABEL_193;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005255E0
// Name: private: void NCompress::NLZMA::CEncoder::WriteEndMarker(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::WriteEndMarker(NCompress::NLZMA::CEncoder *this, unsigned int posState)
{
  unsigned int Range; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v4; // edx
  int v5; // eax
  unsigned int v6; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v7; // eax
  unsigned int v8; // eax
  bool v10; // [esp+4h] [ebp-4h]

  if ( this->_writeEndMark )
  {
    Range = this->_rangeEncoder.Range;
    v4 = &this->_isMatch[this->_state.Index][posState];
    v5 = v4->Prob * (Range >> 11);
    this->_rangeEncoder.Low += (unsigned int)v5;
    this->_rangeEncoder.Range = Range - v5;
    v4->Prob -= v4->Prob >> 5;
    v6 = this->_rangeEncoder.Range;
    if ( v6 < 0x1000000 )
    {
      this->_rangeEncoder.Range = v6 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    v7 = &this->_isRep[this->_state.Index];
    this->_rangeEncoder.Range = v7->Prob * (this->_rangeEncoder.Range >> 11);
    v7->Prob += (2048 - v7->Prob) >> 5;
    v8 = this->_rangeEncoder.Range;
    if ( v8 < 0x1000000 )
    {
      this->_rangeEncoder.Range = v8 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    this->_state.Index = kMatchNextStates_0[this->_state.Index];
    v10 = !this->_fastMode;
    NCompress::NLZMA::NLength::CEncoder::Encode(
      this: &this->_lenEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0,
      posState);
    if ( v10 && this->_lenEncoder._counters[posState]-- == 1 )
    {
      NCompress::NLZMA::NLength::CEncoder::SetPrices(
        this: &this->_lenEncoder,
        posState,
        numSymbols: this->_lenEncoder._tableSize,
        prices: this->_lenEncoder._prices[posState]);
      this->_lenEncoder._counters[posState] = this->_lenEncoder._tableSize;
    }
    NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
      this: this->_posSlotEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0x3Fu);
    NCompress::NRangeCoder::CEncoder::EncodeDirectBits(this: &this->_rangeEncoder, value: 0x3FFFFFFu, numTotalBits: 26);
    NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
      this: &this->_posAlignEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0xFu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00525730
// Name: public: NBT2::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT2::CMatchFinder *__thiscall NBT2::CMatchFinder::CMatchFinder(NBT2::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT2::CMatchFinder_vtbl *)&NBT2::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT2::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT2::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00525760
// Name: public: long NCompress::NLZMA::CEncoder::Create(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Create(NCompress::NLZMA::CEncoder *this)
{
  HRESULT result; // eax
  NBT2::CMatchFinder *v3; // eax
  NBT3::CMatchFinder *v4; // eax
  IMatchFinderSetNumPasses *v5; // ecx
  NBT3::CMatchFinder *v6; // eax
  NBT4::CMatchFinder *v7; // eax
  NHC4::CMatchFinder *v8; // eax
  unsigned int dictionarySize; // ecx
  IMatchFinderSetNumPasses *setMfPasses; // ecx
  unsigned int numFastBytes; // edx

  if ( !COutBuffer::Create(this: &this->_rangeEncoder.Stream, bufferSize: 0x100000u) )
    return -2147024882;
  if ( this->_matchFinder._p == nullptr )
  {
    switch ( this->_matchFinderIndex )
    {
      case 0:
        v3 = (NBT2::CMatchFinder *)MemAlloc_Alloc(nSize: 0x5Cu);
        if ( v3 == nullptr )
          goto LABEL_15;
        v4 = (NBT3::CMatchFinder *)NBT2::CMatchFinder::CMatchFinder(this: v3);
        goto LABEL_7;
      case 1:
        v6 = (NBT3::CMatchFinder *)MemAlloc_Alloc(nSize: 0x5Cu);
        if ( v6 == nullptr )
          goto LABEL_15;
        v4 = NBT3::CMatchFinder::CMatchFinder(this: v6);
        goto LABEL_7;
      case 2:
        v7 = (NBT4::CMatchFinder *)MemAlloc_Alloc(nSize: 0x5Cu);
        if ( v7 == nullptr )
          goto LABEL_15;
        v4 = (NBT3::CMatchFinder *)NBT4::CMatchFinder::CMatchFinder(this: v7);
        goto LABEL_7;
      case 3:
        v8 = (NHC4::CMatchFinder *)MemAlloc_Alloc(nSize: 0x5Cu);
        if ( v8 != nullptr )
        {
          v4 = (NBT3::CMatchFinder *)NHC4::CMatchFinder::CMatchFinder(this: v8);
LABEL_7:
          if ( v4 != nullptr )
          {
            v5 = &v4->IMatchFinderSetNumPasses;
            goto LABEL_17;
          }
        }
        else
        {
LABEL_15:
          v4 = nullptr;
        }
        v5 = nullptr;
LABEL_17:
        this->setMfPasses = v5;
        CMyComPtr<IMatchFinder>::operator=(this: &this->_matchFinder, p: v4);
LABEL_18:
        if ( this->_matchFinder._p != nullptr )
          break;
        return -2147024882;
      default:
        goto LABEL_18;
    }
  }
  if ( !NCompress::NLZMA::CLiteralEncoder::Create(
          this: &this->_literalEncoder,
          numPosBits: this->_numLiteralPosStateBits,
          numPrevBits: this->_numLiteralContextBits) )
    return -2147024882;
  dictionarySize = this->_dictionarySize;
  if ( dictionarySize != this->_dictionarySizePrev || this->_numFastBytesPrev != this->_numFastBytes )
  {
    result = this->_matchFinder._p->Create(
               this: this->_matchFinder._p,
               a2: dictionarySize,
               a3: 4096u,
               a4: this->_numFastBytes,
               a5: 274u);
    if ( result != 0 )
      return result;
    if ( this->_matchFinderCycles != 0 )
    {
      setMfPasses = this->setMfPasses;
      if ( setMfPasses != nullptr )
        setMfPasses->SetNumPasses(this: setMfPasses, a2: this->_matchFinderCycles);
    }
    numFastBytes = this->_numFastBytes;
    this->_dictionarySizePrev = this->_dictionarySize;
    this->_numFastBytesPrev = numFastBytes;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005258E0
// Name: private: long NCompress::NLZMA::CEncoder::Flush(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Flush(NCompress::NLZMA::CEncoder *this, unsigned int nowPos)
{
  IMatchFinder *p; // eax

  p = this->_matchFinder._p;
  if ( p != nullptr && this->_needReleaseMFStream )
  {
    p->ReleaseStream(this: p);
    this->_needReleaseMFStream = false;
  }
  NCompress::NLZMA::CEncoder::WriteEndMarker(this, posState: nowPos & this->_posStateMask);
  NCompress::NRangeCoder::CEncoder::FlushData(this: &this->_rangeEncoder);
  return COutBuffer::Flush(this: &this->_rangeEncoder.Stream);
}

//------------------------------------------------------------------------------
// Address: 0x00525940
// Name: public: long NCompress::NLZMA::CEncoder::SetStreams(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::SetStreams(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize)
{
  HRESULT result; // eax
  unsigned int v7; // edx

  this->_inStream = inStream;
  this->_finished = false;
  result = NCompress::NLZMA::CEncoder::Create(this);
  if ( result == 0 )
  {
    result = this->SetOutStream(this: &this->ICompressSetOutStream, a2: outStream);
    if ( result == 0 )
    {
      result = NCompress::NLZMA::CEncoder::Init(this);
      if ( result == 0 )
      {
        if ( !this->_fastMode )
        {
          NCompress::NLZMA::CEncoder::FillDistancesPrices(this);
          NCompress::NLZMA::CEncoder::FillAlignPrices(this);
        }
        this->_lenEncoder._tableSize = this->_numFastBytes - 1;
        NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(
          this: &this->_lenEncoder,
          numPosStates: 1 << this->_posStateBits);
        v7 = 1 << this->_posStateBits;
        this->_repMatchLenEncoder._tableSize = this->_numFastBytes - 1;
        NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(this: &this->_repMatchLenEncoder, numPosStates: v7);
        LODWORD(this->nowPos64) = 0;
        HIDWORD(this->nowPos64) = 0;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00525A10
// Name: public: long NCompress::NLZMA::CEncoder::CodeOneBlock(unsigned __int64 __near *,unsigned __int64 __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::CodeOneBlock(
        NCompress::NLZMA::CEncoder *this,
        unsigned __int64 *inSize,
        unsigned __int64 *outSize,
        int *finished)
{
  ISequentialInStream *inStream; // ecx
  unsigned int result; // eax
  bool v7; // zf
  int v8; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v9; // eax
  unsigned int Range; // eax
  unsigned __int8 v11; // al
  unsigned __int8 previousByte; // dl
  unsigned __int8 v13; // bl
  NCompress::NLZMA::CLiteralEncoder2 *SubCoder; // eax
  bool v15; // cf
  unsigned int nowPos64; // edi
  unsigned int (__stdcall *GetNumAvailableBytes)(IInWindowStream *); // edx
  unsigned int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // eax
  unsigned __int8 v21; // al
  unsigned int v22; // edi
  unsigned int v23; // edx
  NCompress::NLZMA::CLiteralEncoder2 *v24; // edi
  unsigned __int8 v25; // dl
  unsigned int v26; // ebx
  NCompress::NRangeCoder::CBitEncoder<5> *v27; // edx
  unsigned int v28; // ecx
  int v29; // eax
  unsigned int v30; // eax
  int Index; // edx
  unsigned int v32; // ecx
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v36; // eax
  unsigned int v37; // eax
  int v38; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v39; // edx
  int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v43; // eax
  unsigned int v44; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v45; // edx
  int v46; // eax
  unsigned int v47; // eax
  unsigned int v48; // ebx
  unsigned int v49; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // edx
  unsigned int v53; // eax
  unsigned int v54; // eax
  unsigned int v55; // eax
  unsigned int v56; // ebx
  unsigned int v57; // eax
  int v58; // eax
  unsigned int v59; // edx
  unsigned int v60; // eax
  unsigned int v61; // ecx
  unsigned int v62; // edx
  unsigned int additionalOffset; // eax
  unsigned int v64; // edi
  int v65; // edx
  unsigned __int8 v66; // [esp-Ch] [ebp-34h]
  IMatchFinder *p; // [esp-Ch] [ebp-34h]
  unsigned int numDistancePairs; // [esp+4h] [ebp-24h] BYREF
  unsigned int posReduced; // [esp+8h] [ebp-20h] BYREF
  int matchByte; // [esp+Ch] [ebp-1Ch]
  int curByte; // [esp+10h] [ebp-18h]
  unsigned int nowPos32; // [esp+14h] [ebp-14h]
  unsigned int posState; // [esp+18h] [ebp-10h]
  unsigned int lenRes; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned int pos; // [esp+20h] [ebp-8h] BYREF
  bool v76; // [esp+24h] [ebp-4h]

  inStream = this->_inStream;
  if ( inStream != nullptr )
  {
    result = this->_matchFinder._p->SetStream(this: this->_matchFinder._p, a2: inStream);
    if ( result != 0 )
      return result;
    result = this->_matchFinder._p->Init(this: this->_matchFinder._p);
    if ( result != 0 )
      return result;
    this->_needReleaseMFStream = true;
    this->_inStream = nullptr;
  }
  *finished = 1;
  if ( this->_finished )
    return 0;
  v8 = HIDWORD(this->nowPos64) | LODWORD(this->nowPos64);
  v7 = this->nowPos64 == 0;
  this->_finished = true;
  if ( !v7 )
    goto LABEL_14;
  if ( ((int (__thiscall *)(int, IMatchFinder *))this->_matchFinder._p->GetNumAvailableBytes)(
         a1: v8,
         a2: this->_matchFinder._p) == 0 )
    return NCompress::NLZMA::CEncoder::Flush(this, nowPos: this->nowPos64);
  result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &posReduced, &numDistancePairs);
  if ( result == 0 )
  {
    v9 = &this->_isMatch[this->_state.Index][this->nowPos64 & this->_posStateMask];
    this->_rangeEncoder.Range = v9->Prob * (this->_rangeEncoder.Range >> 11);
    v9->Prob += (2048 - v9->Prob) >> 5;
    Range = this->_rangeEncoder.Range;
    if ( Range < 0x1000000 )
    {
      this->_rangeEncoder.Range = Range << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    this->_state.Index = kLiteralNextStates_0[this->_state.Index];
    v11 = this->_matchFinder._p->GetIndexByte(this: this->_matchFinder._p, a2: -this->_additionalOffset);
    previousByte = this->_previousByte;
    v13 = v11;
    LOBYTE(curByte) = v11;
    v66 = v11;
    SubCoder = NCompress::NLZMA::CLiteralEncoder::GetSubCoder(
                 this: &this->_literalEncoder,
                 pos: this->nowPos64,
                 prevByte: previousByte);
    NCompress::NLZMA::CLiteralEncoder2::Encode(this: SubCoder, rangeEncoder: &this->_rangeEncoder, symbol: v66);
    --this->_additionalOffset;
    v15 = __CFADD__(LODWORD(this->nowPos64)++, 1);
    this->_previousByte = v13;
    HIDWORD(this->nowPos64) += v15;
LABEL_14:
    nowPos64 = this->nowPos64;
    GetNumAvailableBytes = this->_matchFinder._p->GetNumAvailableBytes;
    p = this->_matchFinder._p;
    nowPos32 = nowPos64;
    numDistancePairs = nowPos64;
    if ( GetNumAvailableBytes(this: p) != 0 )
    {
      if ( this->_rangeEncoder.Stream.ErrorCode != 0 )
      {
        return this->_rangeEncoder.Stream.ErrorCode;
      }
      else
      {
        while ( 1 )
        {
          result = this->_fastMode
                 ? NCompress::NLZMA::CEncoder::GetOptimumFast(this, position: nowPos64, backRes: &pos, &lenRes)
                 : NCompress::NLZMA::CEncoder::GetOptimum(
                     this,
                     a2: (IMatchFinder *)this,
                     position: nowPos64,
                     backRes: &pos,
                     &lenRes);
          if ( result != 0 )
            break;
          v18 = nowPos64 & this->_posStateMask;
          posState = v18;
          if ( lenRes == 1 && pos == -1 )
          {
            v19 = v18 + 16 * this->_state.Index;
            this->_rangeEncoder.Range = this->_isMatch[0][v19].Prob * (this->_rangeEncoder.Range >> 11);
            this->_isMatch[0][v19].Prob += (2048 - this->_isMatch[0][v19].Prob) >> 5;
            v20 = this->_rangeEncoder.Range;
            if ( v20 < 0x1000000 )
            {
              this->_rangeEncoder.Range = v20 << 8;
              NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
            }
            v21 = this->_matchFinder._p->GetIndexByte(this: this->_matchFinder._p, a2: -this->_additionalOffset);
            v22 = this->_previousByte;
            v23 = nowPos32 & this->_literalEncoder._posMask;
            LOBYTE(curByte) = v21;
            v24 = &this->_literalEncoder._coders[(v23 << this->_literalEncoder._numPrevBits)
                                               + (v22 >> (8 - this->_literalEncoder._numPrevBits))];
            if ( this->_state.Index >= 7u )
            {
              LOBYTE(matchByte) = this->_matchFinder._p->GetIndexByte(
                                    this: this->_matchFinder._p,
                                    a2: -1 - this->_repDistances[0] - this->_additionalOffset);
              NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(
                this: v24,
                rangeEncoder: &this->_rangeEncoder,
                matchByte,
                symbol: curByte);
            }
            else
            {
              NCompress::NLZMA::CLiteralEncoder2::Encode(this: v24, rangeEncoder: &this->_rangeEncoder, symbol: curByte);
            }
            v25 = curByte;
            v26 = lenRes;
            this->_state.Index = kLiteralNextStates_0[this->_state.Index];
            this->_previousByte = v25;
          }
          else
          {
            v27 = &this->_isMatch[this->_state.Index][v18];
            v28 = this->_rangeEncoder.Range;
            v29 = v27->Prob * (v28 >> 11);
            v15 = __CFADD__(v29, this->_rangeEncoder.Low);
            LODWORD(this->_rangeEncoder.Low) += v29;
            HIDWORD(this->_rangeEncoder.Low) += v15;
            this->_rangeEncoder.Range = v28 - v29;
            v27->Prob -= v27->Prob >> 5;
            v30 = this->_rangeEncoder.Range;
            if ( v30 < 0x1000000 )
            {
              this->_rangeEncoder.Range = v30 << 8;
              NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
            }
            if ( pos >= 4 )
            {
              v50 = &this->_isRep[this->_state.Index];
              this->_rangeEncoder.Range = v50->Prob * (this->_rangeEncoder.Range >> 11);
              v50->Prob += (2048 - v50->Prob) >> 5;
              v51 = this->_rangeEncoder.Range;
              if ( v51 < 0x1000000 )
              {
                this->_rangeEncoder.Range = v51 << 8;
                NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
              }
              v52 = posState;
              v53 = lenRes;
              this->_state.Index = kMatchNextStates_0[this->_state.Index];
              v76 = !this->_fastMode;
              NCompress::NLZMA::NLength::CEncoder::Encode(
                this: &this->_lenEncoder,
                rangeEncoder: &this->_rangeEncoder,
                symbol: v53 - 2,
                posState: v52);
              if ( v76 )
              {
                v54 = posState;
                v7 = this->_lenEncoder._counters[posState]-- == 1;
                if ( v7 )
                {
                  NCompress::NLZMA::NLength::CEncoder::SetPrices(
                    this: &this->_lenEncoder,
                    posState: v54,
                    numSymbols: this->_lenEncoder._tableSize,
                    prices: this->_lenEncoder._prices[v54]);
                  this->_lenEncoder._counters[posState] = this->_lenEncoder._tableSize;
                }
              }
              v55 = pos - 4;
              pos = v55;
              if ( v55 >= 0x800 )
              {
                if ( v55 >= 0x200000 )
                  v56 = NCompress::NLZMA::g_FastPos[v55 >> 20] + 40;
                else
                  v56 = NCompress::NLZMA::g_FastPos[v55 >> 10] + 20;
              }
              else
              {
                v56 = NCompress::NLZMA::g_FastPos[v55];
              }
              v57 = lenRes - 2;
              if ( lenRes - 2 >= 4 )
                v57 = 3;
              NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
                this: &this->_posSlotEncoder[v57],
                rangeEncoder: &this->_rangeEncoder,
                symbol: v56);
              if ( v56 >= 4 )
              {
                v58 = (v56 & 1 | 2) << ((v56 >> 1) - 1);
                posReduced = pos - v58;
                if ( v56 >= 0xE )
                {
                  NCompress::NRangeCoder::CEncoder::EncodeDirectBits(
                    this: &this->_rangeEncoder,
                    value: (pos - v58) >> 4,
                    numTotalBits: (v56 >> 1) - 5);
                  NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
                    this: &this->_posAlignEncoder,
                    rangeEncoder: &this->_rangeEncoder,
                    symbol: posReduced & 0xF);
                  ++this->_alignPriceCount;
                }
                else
                {
                  NCompress::NRangeCoder::ReverseBitTreeEncode<5>(
                    Models: &this->_posSlotEncoder[3].Models[v58 - v56 + 63],
                    rangeEncoder: &this->_rangeEncoder,
                    NumBitLevels: (v56 >> 1) - 1,
                    symbol: pos - v58);
                }
              }
              v59 = this->_repDistances[2];
              v60 = this->_repDistances[1];
              v61 = this->_repDistances[0];
              ++this->_matchPriceCount;
              v26 = lenRes;
              this->_repDistances[3] = v59;
              v62 = pos;
              this->_repDistances[2] = v60;
              this->_repDistances[1] = v61;
              this->_repDistances[0] = v62;
            }
            else
            {
              Index = this->_state.Index;
              v32 = this->_rangeEncoder.Range;
              v33 = this->_isRep[Index].Prob * (v32 >> 11);
              v15 = __CFADD__(v33, this->_rangeEncoder.Low);
              LODWORD(this->_rangeEncoder.Low) += v33;
              HIDWORD(this->_rangeEncoder.Low) += v15;
              this->_rangeEncoder.Range = v32 - v33;
              this->_isRep[Index].Prob -= this->_isRep[Index].Prob >> 5;
              v34 = this->_rangeEncoder.Range;
              if ( v34 < 0x1000000 )
              {
                this->_rangeEncoder.Range = v34 << 8;
                NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
              }
              v35 = this->_rangeEncoder.Range;
              if ( pos != 0 )
              {
                v38 = this->_state.Index;
                posReduced = this->_repDistances[pos];
                v39 = &this->_isRepG0[v38];
                v40 = v39->Prob * (v35 >> 11);
                this->_rangeEncoder.Low += (unsigned int)v40;
                this->_rangeEncoder.Range = v35 - v40;
                v39->Prob -= v39->Prob >> 5;
                v41 = this->_rangeEncoder.Range;
                if ( v41 < 0x1000000 )
                {
                  this->_rangeEncoder.Range = v41 << 8;
                  NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                }
                v42 = this->_rangeEncoder.Range;
                if ( pos == 1 )
                {
                  v43 = &this->_isRepG1[this->_state.Index];
                  this->_rangeEncoder.Range = v43->Prob * (v42 >> 11);
                  v43->Prob += (2048 - v43->Prob) >> 5;
                  v44 = this->_rangeEncoder.Range;
                  if ( v44 < 0x1000000 )
                  {
                    this->_rangeEncoder.Range = v44 << 8;
                    NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                  }
                }
                else
                {
                  v45 = &this->_isRepG1[this->_state.Index];
                  v46 = v45->Prob * (v42 >> 11);
                  this->_rangeEncoder.Low += (unsigned int)v46;
                  this->_rangeEncoder.Range = v42 - v46;
                  v45->Prob -= v45->Prob >> 5;
                  v47 = this->_rangeEncoder.Range;
                  if ( v47 < 0x1000000 )
                  {
                    this->_rangeEncoder.Range = v47 << 8;
                    NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                  }
                  v48 = pos;
                  NCompress::NRangeCoder::CBitEncoder<5>::Encode(
                    this: &this->_isRepG2[this->_state.Index],
                    encoder: &this->_rangeEncoder,
                    symbol: pos - 2);
                  if ( v48 == 3 )
                    this->_repDistances[3] = this->_repDistances[2];
                  this->_repDistances[2] = this->_repDistances[1];
                }
                v49 = posReduced;
                v26 = lenRes;
                this->_repDistances[1] = this->_repDistances[0];
                this->_repDistances[0] = v49;
              }
              else
              {
                v36 = &this->_isRepG0[this->_state.Index];
                this->_rangeEncoder.Range = v36->Prob * (v35 >> 11);
                v36->Prob += (2048 - v36->Prob) >> 5;
                v37 = this->_rangeEncoder.Range;
                if ( v37 < 0x1000000 )
                {
                  this->_rangeEncoder.Range = v37 << 8;
                  NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                }
                v26 = lenRes;
                NCompress::NRangeCoder::CBitEncoder<5>::Encode(
                  this: &this->_isRep0Long[this->_state.Index][posState],
                  encoder: &this->_rangeEncoder,
                  symbol: lenRes != 1);
              }
              if ( v26 == 1 )
              {
                this->_state.Index = kShortRepNextStates_0[this->_state.Index];
              }
              else
              {
                NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(
                  this: &this->_repMatchLenEncoder,
                  rangeEncoder: &this->_rangeEncoder,
                  symbol: v26 - 2,
                  posState,
                  updatePrice: !this->_fastMode);
                this->_state.Index = kRepNextStates_0[this->_state.Index];
              }
            }
            this->_previousByte = this->_matchFinder._p->GetIndexByte(
                                    this: this->_matchFinder._p,
                                    a2: v26 - this->_additionalOffset - 1);
          }
          this->_additionalOffset -= v26;
          additionalOffset = this->_additionalOffset;
          nowPos64 = v26 + nowPos32;
          nowPos32 += v26;
          if ( additionalOffset == 0 )
          {
            if ( !this->_fastMode )
            {
              if ( this->_matchPriceCount >= 0x80 )
                NCompress::NLZMA::CEncoder::FillDistancesPrices(this);
              if ( this->_alignPriceCount >= 0x10 )
                NCompress::NLZMA::CEncoder::FillAlignPrices(this);
            }
            if ( this->_matchFinder._p->GetNumAvailableBytes(this: this->_matchFinder._p) == 0 )
              return NCompress::NLZMA::CEncoder::Flush(this, nowPos: nowPos64);
            if ( nowPos64 - numDistancePairs >= 0x4000 )
            {
              v64 = nowPos64 - numDistancePairs;
              v15 = __CFADD__(v64, this->nowPos64);
              LODWORD(this->nowPos64) += v64;
              v65 = this->nowPos64;
              HIDWORD(this->nowPos64) += v15;
              *(_DWORD *)inSize = v65;
              *((_DWORD *)inSize + 1) = HIDWORD(this->nowPos64);
              *outSize = NCompress::NRangeCoder::CEncoder::GetProcessedSize(this: &this->_rangeEncoder);
              this->_finished = false;
              *finished = 0;
              return 0;
            }
          }
          if ( this->_rangeEncoder.Stream.ErrorCode != 0 )
            return this->_rangeEncoder.Stream.ErrorCode;
          nowPos64 = nowPos32;
        }
      }
    }
    else
    {
      return NCompress::NLZMA::CEncoder::Flush(this, nowPos: nowPos64);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00526210
// Name: public: long NCompress::NLZMA::CEncoder::CodeReal(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *,struct ICompressProgressInfo __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::CodeReal(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize,
        ICompressProgressInfo *progress)
{
  HRESULT v7; // edi
  IMatchFinder *p; // eax
  unsigned int v10; // edi
  ICompressProgressInfo *v11; // ebx
  const unsigned __int64 *v12; // [esp-4h] [ebp-20h]
  unsigned __int64 processedInSize; // [esp+8h] [ebp-14h] BYREF
  unsigned __int64 processedOutSize; // [esp+10h] [ebp-Ch] BYREF
  NCompress::NLZMA::CEncoder::CCoderReleaser coderReleaser; // [esp+18h] [ebp-4h] BYREF

  v12 = outSize;
  this->_needReleaseMFStream = false;
  coderReleaser._coder = this;
  v7 = NCompress::NLZMA::CEncoder::SetStreams(this, inStream, outStream, inSize, outSize: v12);
  if ( v7 != 0 )
  {
    p = this->_matchFinder._p;
    if ( p != nullptr && this->_needReleaseMFStream )
    {
      p->ReleaseStream(this: this->_matchFinder._p);
      this->_needReleaseMFStream = false;
    }
    this->ReleaseOutStream(this: &this->ICompressSetOutStream);
    return v7;
  }
  else
  {
    v10 = NCompress::NLZMA::CEncoder::CodeOneBlock(
            this,
            inSize: &processedInSize,
            outSize: &processedOutSize,
            finished: (int *)&outSize);
    if ( v10 != 0 )
    {
LABEL_12:
      NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(this: &coderReleaser);
      return v10;
    }
    else
    {
      v11 = progress;
      while ( outSize == nullptr )
      {
        if ( v11 == nullptr || (v10 = v11->SetRatioInfo(this: v11, a2: &processedInSize, a3: &processedOutSize)) == 0 )
        {
          v10 = NCompress::NLZMA::CEncoder::CodeOneBlock(
                  this,
                  inSize: &processedInSize,
                  outSize: &processedOutSize,
                  finished: (int *)&outSize);
          if ( v10 == 0 )
            continue;
        }
        goto LABEL_12;
      }
      NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(this: &coderReleaser);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00526300
// Name: public: virtual long NCompress::NLZMA::CEncoder::Code(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *,struct ICompressProgressInfo __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::Code(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize,
        ICompressProgressInfo *progress)
{
  return NCompress::NLZMA::CEncoder::CodeReal(this, inStream, outStream, inSize, outSize, progress);
}

//------------------------------------------------------------------------------
// Address: 0x00435CB6
// Name: private: unsigned long CXMAInterleave::ReadSomeBits(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CXMAInterleave::ReadSomeBits(CXMAInterleave *this, unsigned int stream, unsigned int numBits)
{
  CXMAInterleave *v3; // edi
  CXMAStreamCopy *v4; // esi
  int m_bitsInCache; // eax
  unsigned int v6; // ebx
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edi
  unsigned int Data; // eax
  unsigned int m_dwFrameSizeInBits; // ecx
  unsigned int v13; // [esp+10h] [ebp-Ch]
  int bytesToRead; // [esp+18h] [ebp-4h]
  unsigned int bytesToReada; // [esp+18h] [ebp-4h]

  v3 = this;
  v4 = &this->m_pStreamState[stream];
  v13 = 1;
  BitCopy(
    pbSrc: &v4->m_bitCache,
    pbDst: v4->m_pFrameData,
    nSrcOff: 0,
    nDstOff: v4->m_dwFrameSizeInBits,
    nLen: v4->m_bitsInCache);
  m_bitsInCache = v4->m_bitsInCache;
  v6 = numBits;
  v4->m_dwFrameSizeInBits += m_bitsInCache;
  v7 = v6 - m_bitsInCache;
  v4->m_bitsInCache = 0;
  if ( v7 == 0 )
    return v13;
  while ( 1 )
  {
    v8 = (v7 + 7) >> 3;
    if ( (v4->m_bytesRead & 0x7FF) == 0 )
    {
      if ( CTargetStream::ReadData(
             this: v3->m_aXMAstreams[stream].pStream,
             ppbReadPosition: &v3->m_aXMAstreams[stream].pStreamPosition,
             pbDataBuffer: (unsigned __int8 *)&numBits,
             dwBufferSize: 4u) != 4 )
        return 0;
      v4->m_bytesRead += 4;
      v8 = (v7 + 7) >> 3;
      v13 = 3 - ((((numBits & 3) << 13) | (32 * BYTE1(numBits)) | (BYTE2(numBits) >> 3)) < 0x4000);
    }
    bytesToRead = v8;
    if ( v8 > (-v4->m_bytesRead & 0x7FF) )
      bytesToRead = -v4->m_bytesRead & 0x7FF;
    v9 = (v4->m_dwFrameSizeInBits + 7) >> 3;
    Data = CTargetStream::ReadData(
             this: this->m_aXMAstreams[stream].pStream,
             ppbReadPosition: &this->m_aXMAstreams[stream].pStreamPosition,
             pbDataBuffer: &v4->m_pFrameData[v9],
             dwBufferSize: bytesToRead);
    if ( Data != bytesToRead )
      break;
    v4->m_bytesRead += Data;
    bytesToReada = 8 * Data;
    BitCopy(
      pbSrc: v4->m_pFrameData,
      pbDst: v4->m_pFrameData,
      nSrcOff: 8 * v9,
      nDstOff: v4->m_dwFrameSizeInBits,
      nLen: 8 * Data);
    if ( bytesToReada > v7 )
    {
      v4->m_dwFrameSizeInBits += v7;
      m_dwFrameSizeInBits = v4->m_dwFrameSizeInBits;
      v4->m_bitsInCache = bytesToReada - v7;
      BitCopy(
        pbSrc: v4->m_pFrameData,
        pbDst: &v4->m_bitCache,
        nSrcOff: m_dwFrameSizeInBits,
        nDstOff: 0,
        nLen: (unsigned __int8)(bytesToReada - v7));
      return v13;
    }
    v4->m_dwFrameSizeInBits += bytesToReada;
    v7 -= bytesToReada;
    if ( v7 == 0 )
      return v13;
    v3 = this;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00435E0A
// Name: private: void CXMAInterleave::CloseCurrentPacket(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CXMAInterleave::CloseCurrentPacket(CXMAInterleave *this, unsigned int stream)
{
  CXMAStreamCopy *v2; // edx
  int m_nCurrentPacket; // eax
  unsigned int m_dwFrameCount; // edx
  unsigned __int8 *v5; // eax
  unsigned int v6; // ecx

  v2 = &this->m_pStreamState[stream];
  m_nCurrentPacket = v2->m_nCurrentPacket;
  m_dwFrameCount = v2->m_dwFrameCount;
  v5 = &this->m_pBlockData[2048 * m_nCurrentPacket];
  v6 = v5[3] | ((v5[2] | ((v5[1] | ((*v5 | (4 * m_dwFrameCount)) << 8)) << 8) | 1) << 8);
  if ( m_dwFrameCount == 0 )
    v6 = ((v5[2] | ((v5[1] | (*v5 << 8)) << 8) | 1) << 8) & 0xFC000000 | 0x3FFF800;
  *v5 = HIBYTE(v6);
  v5[1] = BYTE2(v6);
  v5[2] = BYTE1(v6);
  v5[3] = v6;
}

//------------------------------------------------------------------------------
// Address: 0x00435E82
// Name: private: void CXMAInterleave::StartNewPacket(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CXMAInterleave::StartNewPacket(CXMAInterleave *this, unsigned int stream, __int16 bitLocOfFirstFrame)
{
  unsigned int v3; // edi
  unsigned int m_nNextAvailablePacket; // edx
  int *p_m_nCurrentPacket; // ecx
  unsigned int v7; // eax
  unsigned __int8 *v8; // ebx
  int v9; // eax
  unsigned int lastPacketNum; // [esp+14h] [ebp+8h]

  v3 = stream;
  m_nNextAvailablePacket = this->m_nNextAvailablePacket;
  p_m_nCurrentPacket = &this->m_pStreamState[stream].m_nCurrentPacket;
  v7 = *p_m_nCurrentPacket;
  *p_m_nCurrentPacket = m_nNextAvailablePacket;
  ++this->m_nNextAvailablePacket;
  lastPacketNum = v7;
  v8 = &this->m_pBlockData[2048 * this->m_pStreamState[v3].m_nCurrentPacket];
  memset(dst: v8, value: 0, count: 0x800u);
  v9 = (bitLocOfFirstFrame & 0x7FFF) << 11;
  *v8 = HIBYTE(v9);
  v8[1] = BYTE2(v9);
  v8[3] = 0;
  v8[2] = BYTE1(v9);
  this->m_pBlockData[2048 * lastPacketNum + 3] = LOBYTE(this->m_pStreamState[v3].m_nCurrentPacket) - lastPacketNum - 1;
  this->m_pStreamState[v3].m_dwPacketOffsetInBits = 32;
  this->m_pStreamState[v3].m_dwFrameCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00435F36
// Name: private: bool CXMAInterleave::NewPacketRequired(unsigned int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __thiscall CXMAInterleave::NewPacketRequired(CXMAInterleave *this, unsigned int stream)
{
  CXMAStreamCopy *m_pStreamState; // edx

  m_pStreamState = this->m_pStreamState;
  return m_pStreamState[stream].m_dwFrameCount == 63
      || (signed int)m_pStreamState[stream].m_dwFrameSizeInBits > (signed int)(0x4000
                                                                             - m_pStreamState[stream].m_dwPacketOffsetInBits);
}

//------------------------------------------------------------------------------
// Address: 0x00435F66
// Name: ByteReverse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall ByteReverse(unsigned int val)
{
  return ((HIWORD(val) | val & 0xFF0000) >> 8) | (((val << 16) | val & 0xFF00) << 8);
}

//------------------------------------------------------------------------------
// Address: 0x00435F8A
// Name: private: static void CXMAInterleave::ClearToEndOfPacket(unsigned char __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CXMAInterleave::ClearToEndOfPacket(unsigned __int8 *pPacket, unsigned int startingBitPos)
{
  while ( (startingBitPos & 7) != 0 )
    SetOneBit(pb: pPacket, nOffset: startingBitPos++);
  while ( startingBitPos < 0x4000 )
  {
    pPacket[startingBitPos >> 3] = -1;
    startingBitPos += 8;
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10011810
// Name: private: virtual long NHC4::CMatchFinder::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::QueryInterface(
        NHC4::CMatchFinder *this,
        NHC4::CMatchFinder *__formal,
        const _GUID *__formala)
{
  return -2147467262;
}

//------------------------------------------------------------------------------
// Address: 0x10011C20
// Name: public: void NCompress::NRangeCoder::CEncoder::ShiftLow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::ShiftLow(NCompress::NRangeCoder::CEncoder *this)
{
  unsigned int Low; // esi
  unsigned __int8 cache; // bl

  Low = this->Low;
  if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
  {
    cache = this->_cache;
    do
    {
      this->Stream._buffer[this->Stream._pos] = cache + HIDWORD(this->Low);
      if ( ++this->Stream._pos == this->Stream._limitPos )
        COutBuffer::FlushWithCheck(this: &this->Stream);
      cache = -1;
    }
    while ( this->_cacheSize-- != 1 );
    Low = this->Low;
    this->_cache = HIBYTE(Low);
  }
  ++this->_cacheSize;
  LODWORD(this->Low) = Low << 8;
  HIDWORD(this->Low) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011CA0
// Name: public: void NCompress::NRangeCoder::CEncoder::EncodeDirectBits(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::EncodeDirectBits(
        NCompress::NRangeCoder::CEncoder *this,
        unsigned int value,
        int numTotalBits)
{
  bool v3; // sf
  int v4; // ebx
  unsigned int Range; // eax
  unsigned int Low; // edi
  unsigned __int8 cache; // bl
  int i; // [esp+14h] [ebp+Ch]

  v4 = numTotalBits - 1;
  v3 = numTotalBits - 1 < 0;
  i = numTotalBits - 1;
  if ( !v3 )
  {
    do
    {
      this->Range >>= 1;
      Range = this->Range;
      if ( ((value >> v4) & 1) != 0 )
        this->Low += Range;
      if ( Range < 0x1000000 )
      {
        Low = this->Low;
        this->Range = Range << 8;
        if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
        {
          cache = this->_cache;
          do
          {
            this->Stream._buffer[this->Stream._pos++] = cache + HIDWORD(this->Low);
            if ( this->Stream._pos == this->Stream._limitPos )
              COutBuffer::FlushWithCheck(this: &this->Stream);
            cache = -1;
          }
          while ( this->_cacheSize-- != 1 );
          Low = this->Low;
          v4 = i;
          this->_cache = HIBYTE(Low);
        }
        ++this->_cacheSize;
        LODWORD(this->Low) = Low << 8;
        HIDWORD(this->Low) = 0;
      }
      i = --v4;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011D60
// Name: public: unsigned __int64 NCompress::NRangeCoder::CEncoder::GetProcessedSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall NCompress::NRangeCoder::CEncoder::GetProcessedSize(NCompress::NRangeCoder::CEncoder *this)
{
  return this->_cacheSize + COutBuffer::GetProcessedSize(this: &this->Stream) + 4;
}

//------------------------------------------------------------------------------
// Address: 0x10011D80
// Name: public: bool NCompress::NLZMA::CLiteralEncoder::Create(int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NCompress::NLZMA::CLiteralEncoder::Create(
        NCompress::NLZMA::CLiteralEncoder *this,
        int numPosBits,
        int numPrevBits)
{
  bool v4; // zf

  if ( this->_coders == nullptr || numPosBits + numPrevBits != this->_numPrevBits + this->_numPosBits )
  {
    MyFree(address: this->_coders);
    this->_coders = nullptr;
    this->_coders = (NCompress::NLZMA::CLiteralEncoder2 *)MyAlloc(size: 3072 * (1 << (numPosBits + numPrevBits)));
  }
  this->_numPosBits = numPosBits;
  v4 = this->_coders == nullptr;
  this->_numPrevBits = numPrevBits;
  this->_posMask = (1 << numPosBits) - 1;
  return !v4;
}

//------------------------------------------------------------------------------
// Address: 0x10011DF0
// Name: public: class NCompress::NLZMA::CLiteralEncoder2 __near * NCompress::NLZMA::CLiteralEncoder::GetSubCoder(unsigned int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
NCompress::NLZMA::CLiteralEncoder2 *__thiscall NCompress::NLZMA::CLiteralEncoder::GetSubCoder(
        NCompress::NLZMA::CLiteralEncoder *this,
        unsigned int pos,
        unsigned __int8 prevByte)
{
  return &this->_coders[((pos & this->_posMask) << this->_numPrevBits) + (prevByte >> (8 - this->_numPrevBits))];
}

//------------------------------------------------------------------------------
// Address: 0x10011E30
// Name: private: unsigned int NCompress::NLZMA::CEncoder::GetPosLenPrice(unsigned int,unsigned int,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetPosLenPrice(
        NCompress::NLZMA::CEncoder *this,
        unsigned int pos,
        unsigned int len,
        unsigned int posState)
{
  int v4; // eax
  unsigned int v5; // esi
  int v6; // esi

  v4 = len - 2;
  if ( len - 2 >= 4 )
    v4 = 3;
  if ( pos >= 0x80 )
  {
    if ( pos >= 0x20000 )
    {
      if ( pos >= 0x8000000 )
        v6 = NCompress::NLZMA::g_FastPos[pos >> 26] + 52;
      else
        v6 = NCompress::NLZMA::g_FastPos[HIWORD(pos)] + 32;
    }
    else
    {
      v6 = NCompress::NLZMA::g_FastPos[pos >> 6] + 12;
    }
    v5 = this->_alignPrices[pos & 0xF] + this->_posSlotPrices[v4][v6];
  }
  else
  {
    v5 = this->_distancesPrices[v4][pos];
  }
  return v5 + this->_lenEncoder._highCoder.Models[272 * posState + 254 + len].Prob;
}

//------------------------------------------------------------------------------
// Address: 0x10011F00
// Name: private: virtual long NBT2::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::Create(
        NBT2::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  int v8; // eax
  unsigned int *v9; // eax
  unsigned int *v10; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_9:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = 2 * v7 + 0x10000;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  this->_hashSizeSum = 0x10000;
  if ( (unsigned int)(4 * v8) >> 2 == v8 )
  {
    v9 = (unsigned int *)BigAlloc(size: 4 * v8);
    v10 = &v9[this->_hashSizeSum];
    this->_hash = v9;
    this->_son = v10;
    if ( v9 != nullptr )
      return 0;
    goto LABEL_9;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x10012000
// Name: private: void NBT4::CMatchFinder::Normalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT4::CMatchFinder::Normalize(NBT4::CMatchFinder *this)
{
  unsigned int cyclicBufferSize; // eax
  unsigned int v2; // esi
  unsigned int v3; // ebx
  unsigned int v4; // eax
  unsigned int *i; // edi
  unsigned int v6; // edx
  unsigned int v7; // edx

  cyclicBufferSize = this->_cyclicBufferSize;
  v2 = this->_pos - cyclicBufferSize;
  v3 = this->_hashSizeSum + 2 * cyclicBufferSize;
  v4 = 0;
  for ( i = this->_hash; v4 < v3; ++v4 )
  {
    v6 = i[v4];
    if ( v6 > v2 )
      v7 = v6 - v2;
    else
      v7 = 0;
    i[v4] = v7;
  }
  this->_buffer += v2;
  this->_posLimit -= v2;
  this->_pos -= v2;
  this->_streamPos -= v2;
}

//------------------------------------------------------------------------------
// Address: 0x10012050
// Name: private: virtual unsigned char NBT2::CMatchFinder::GetIndexByte(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __stdcall NBT2::CMatchFinder::GetIndexByte(NHC4::CMatchFinder *this, int index)
{
  return this->_buffer[this->_pos + index];
}

//------------------------------------------------------------------------------
// Address: 0x10012070
// Name: private: virtual unsigned long NHC4::CMatchFinder::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::Release(NHC4::CMatchFinder *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    ((void (__thiscall *)(CLZInWindow *, int))this->dtr_CLZInWindow)(a1: &this->CLZInWindow, a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012090
// Name: public: virtual void NBT3::CMatchFinder::SetNumPasses(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT3::CMatchFinder::SetNumPasses(NHC4::CMatchFinder *this, unsigned int numPasses)
{
  this->_blockSize = numPasses;
}

//------------------------------------------------------------------------------
// Address: 0x100120A0
// Name: private: virtual long NBT3::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::Create(
        NBT3::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int *v12; // eax
  unsigned int *v13; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = ((((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4)
     | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
     | ((historySize - 1) >> 1)
     | (historySize - 1);
  v9 = (v8 | ((v8 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v9 > 0x1000000 )
    v9 = 0xFFFFFF;
  this->_hashMask = v9;
  v10 = v9 + 1025;
  v11 = v10 + 2 * v7;
  this->_hashSizeSum = v10;
  if ( (4 * v11) >> 2 == v11 )
  {
    v12 = (unsigned int *)BigAlloc(size: 4 * v11);
    v13 = &v12[this->_hashSizeSum];
    this->_hash = v12;
    this->_son = v13;
    if ( v12 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x100121E0
// Name: private: long NBT4::CMatchFinder::MovePos(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NBT4::CMatchFinder::MovePos(NBT4::CMatchFinder *this)
{
  unsigned int v2; // eax
  HRESULT result; // eax

  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v2 = ++this->_pos;
  if ( v2 <= this->_posLimit )
    goto LABEL_7;
  if ( &this->_buffer[v2] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_7:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012240
// Name: private: virtual void NBT2::CMatchFinder::ChangeBufferPos(void)
// Source: json
//------------------------------------------------------------------------------
void __stdcall NBT2::CMatchFinder::ChangeBufferPos(NHC4::CMatchFinder *this)
{
  CLZInWindow::MoveBlock(this: &this->CLZInWindow);
}

//------------------------------------------------------------------------------
// Address: 0x10012260
// Name: private: virtual long NBT4::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::Create(
        NBT4::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int *v13; // eax
  unsigned int *v14; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 1) + 16;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = (((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4;
  v9 = v8 | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1);
  v10 = (v9 | ((v9 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v10 > 0x1000000 )
    v10 = (v9
         | ((v8
           | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
           | ((historySize - 1) >> 1)
           | (historySize - 1)
           | 0x1FFFE00) >> 8)) >> 2;
  this->_hashMask = v10;
  v11 = v10 + 66561;
  v12 = v11 + 2 * v7;
  this->_hashSizeSum = v11;
  if ( (4 * v12) >> 2 == v12 )
  {
    v13 = (unsigned int *)BigAlloc(size: 4 * v12);
    v14 = &v13[this->_hashSizeSum];
    this->_hash = v13;
    this->_son = v14;
    if ( v13 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x100123A0
// Name: private: virtual long NHC4::CMatchFinder::Init(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::Init(NHC4::CMatchFinder *this)
{
  unsigned int result; // eax

  result = CLZInWindow::Init(this: &this->CLZInWindow);
  if ( result == 0 )
  {
    if ( this->_hashSizeSum != 0 )
    {
      do
        this->_hash[result++] = 0;
      while ( result < this->_hashSizeSum );
    }
    this->_cyclicBufferPos = 0;
    --this->_buffer;
    ++this->_posLimit;
    ++this->_pos;
    ++this->_streamPos;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100123F0
// Name: private: virtual void NBT2::CMatchFinder::ReleaseStream(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NBT2::CMatchFinder::ReleaseStream(CDistributor_DefaultWorker *this, CDSInfo *pInfo)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10012400
// Name: private: virtual unsigned int NBT4::CMatchFinder::GetMatchLen(int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NBT4::CMatchFinder::GetMatchLen(
        NHC4::CMatchFinder *this,
        int index,
        unsigned int back,
        unsigned int limit)
{
  unsigned int v4; // esi
  unsigned int pos; // edi
  unsigned int streamPos; // ecx
  unsigned __int8 *v7; // ecx
  unsigned int result; // eax

  v4 = limit;
  if ( this->_streamEndWasReached )
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( limit + pos + index > streamPos )
      v4 = streamPos - pos - index;
  }
  for ( result = 0; result < v4; ++result )
  {
    v7 = &this->_buffer[this->_pos + index];
    if ( v7[result] != v7[result - 1 - back] )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012460
// Name: private: virtual unsigned int NHC4::CMatchFinder::GetNumAvailableBytes(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::GetNumAvailableBytes(NHC4::CMatchFinder *this)
{
  return this->_streamPos - this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x10012470
// Name: private: virtual unsigned char const __near * NBT4::CMatchFinder::GetPointerToCurrentPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__stdcall NBT4::CMatchFinder::GetPointerToCurrentPos(NHC4::CMatchFinder *this)
{
  return &this->_buffer[this->_pos];
}

//------------------------------------------------------------------------------
// Address: 0x10012480
// Name: private: virtual unsigned long NHC4::CMatchFinder::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NHC4::CMatchFinder::AddRef(NHC4::CMatchFinder *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100124A0
// Name: private: virtual long NHC4::CMatchFinder::Create(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::Create(
        NHC4::CMatchFinder *this,
        unsigned int historySize,
        unsigned int keepAddBufferBefore,
        unsigned int matchMaxLen,
        unsigned int keepAddBufferAfter)
{
  unsigned int *hash; // eax
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int *v14; // eax
  unsigned int *v15; // edx

  if ( historySize > 0x7FFFFEFF )
  {
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024809;
  }
  this->_cutValue = (matchMaxLen >> 2) + 8;
  if ( !CLZInWindow::Create(
          this: &this->CLZInWindow,
          keepSizeBefore: historySize + keepAddBufferBefore,
          keepSizeAfter: matchMaxLen + keepAddBufferAfter,
          keepSizeReserv: ((keepAddBufferAfter + historySize + keepAddBufferBefore + matchMaxLen) >> 1) + 256) )
  {
LABEL_11:
    MidFree(address: this->_hash);
    this->_hash = nullptr;
    CLZInWindow::Free(this: &this->CLZInWindow);
    return -2147024882;
  }
  hash = this->_hash;
  this->_matchMaxLen = matchMaxLen;
  v7 = historySize + 1;
  if ( hash != nullptr && v7 == this->_cyclicBufferSize )
    return 0;
  MidFree(address: hash);
  v8 = (((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1)) >> 4;
  v9 = v8 | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2) | ((historySize - 1) >> 1) | (historySize - 1);
  v10 = (v9 | ((v9 | 0x1FFFE00) >> 8)) >> 1;
  this->_hash = nullptr;
  this->_cyclicBufferSize = v7;
  if ( v10 > 0x1000000 )
    v10 = (v9
         | ((v8
           | ((((historySize - 1) >> 1) | (historySize - 1)) >> 2)
           | ((historySize - 1) >> 1)
           | (historySize - 1)
           | 0x1FFFE00) >> 8)) >> 2;
  this->_hashMask = v10;
  v11 = v10 + 66561;
  v12 = v11 + v7;
  this->_hashSizeSum = v11;
  v13 = 4 * (v11 + v7);
  if ( v13 >> 2 == v12 )
  {
    v14 = (unsigned int *)BigAlloc(size: v13);
    v15 = &v14[this->_hashSizeSum];
    this->_hash = v14;
    this->_son = v15;
    if ( v14 != nullptr )
      return 0;
    goto LABEL_11;
  }
  return -2147024882;
}

//------------------------------------------------------------------------------
// Address: 0x100125E0
// Name: private: virtual long NBT4::CMatchFinder::SetStream(struct ISequentialInStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::SetStream(NHC4::CMatchFinder *this, IBaseFileSystem *stream)
{
  CLZInWindow::SetStream(
    this: (CInternalFileSystemPassThru<IFileSystem> *)&this->CLZInWindow,
    pBaseFileSystemPassThru: stream);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012600
// Name: private: void NHC4::CMatchFinder::Normalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NHC4::CMatchFinder::Normalize(NHC4::CMatchFinder *this)
{
  unsigned int cyclicBufferSize; // eax
  unsigned int *hash; // ebx
  unsigned int hashSizeSum; // edi
  unsigned int v4; // esi
  bool v5; // zf
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // edx

  cyclicBufferSize = this->_cyclicBufferSize;
  hash = this->_hash;
  hashSizeSum = this->_hashSizeSum;
  v4 = this->_pos - cyclicBufferSize;
  v5 = cyclicBufferSize + hashSizeSum == 0;
  v6 = cyclicBufferSize + hashSizeSum;
  v7 = 0;
  if ( !v5 )
  {
    do
    {
      v8 = hash[v7];
      if ( v8 > v4 )
        v9 = v8 - v4;
      else
        v9 = 0;
      hash[v7++] = v9;
    }
    while ( v7 < v6 );
  }
  this->_buffer += v4;
  this->_posLimit -= v4;
  this->_pos -= v4;
  this->_streamPos -= v4;
}

//------------------------------------------------------------------------------
// Address: 0x10012650
// Name: private: long NHC4::CMatchFinder::MovePos(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NHC4::CMatchFinder::MovePos(NHC4::CMatchFinder *this)
{
  unsigned int v2; // eax
  HRESULT result; // eax

  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v2 = ++this->_pos;
  if ( v2 <= this->_posLimit )
    goto LABEL_7;
  if ( &this->_buffer[v2] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_7:
    if ( this->_pos == 0x7FFFFFFF )
      NHC4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100126B0
// Name: private: virtual int NHC4::CMatchFinder::NeedChangeBufferPos(unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall NHC4::CMatchFinder::NeedChangeBufferPos(NHC4::CMatchFinder *this, unsigned int numCheckBytes)
{
  return numCheckBytes >= &this->_pointerToLastSafePosition[-this->_pos] - this->_buffer;
}

//------------------------------------------------------------------------------
// Address: 0x100126D0
// Name: public: void NCompress::NLZMA::CFastPosInit::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CFastPosInit::Init(NCompress::NLZMA::CFastPosInit *this)
{
  char v1; // bl
  unsigned int v2; // edi
  unsigned int v3; // esi
  unsigned __int8 *slotFast; // [esp+Ch] [ebp-8h]
  int c; // [esp+10h] [ebp-4h]

  v1 = 2;
  c = 2;
  *(_WORD *)NCompress::NLZMA::g_FastPos = 256;
  LOBYTE(slotFast) = 2;
  v2 = 2;
  do
  {
    v3 = 1 << ((v2 >> 1) - 1);
    if ( v3 != 0 )
    {
      memset(dst: (int)&NCompress::NLZMA::g_FastPos[c], value: slotFast, count: v3);
      c += v3;
    }
    ++v1;
    ++v2;
    LOBYTE(slotFast) = v1;
  }
  while ( (unsigned __int8)v1 < 0x16u );
}

//------------------------------------------------------------------------------
// Address: 0x10012730
// Name: NCompress::NLZMA::FindMatchFinder
// Source: json
//------------------------------------------------------------------------------
int __usercall NCompress::NLZMA::FindMatchFinder@<eax>(const wchar_t *s@<edi>)
{
  int result; // eax
  const wchar_t *i; // edx
  wchar_t v3; // cx

  for ( result = 0; result < 4; ++result )
  {
    for ( i = s; ; ++i )
    {
      v3 = *i;
      if ( (unsigned __int16)(*i - 97) <= 0x19u )
        v3 -= 32;
      if ( *(const wchar_t *)((char *)i + (char *)kMatchFinderIDs[result] - (char *)s) != v3 )
        break;
      if ( v3 == 0 )
        return result;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10012770
// Name: public: virtual long NCompress::NLZMA::CEncoder::WriteCoderProperties(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::WriteCoderProperties(
        NCompress::NLZMA::CEncoder *this,
        ISequentialOutStream *outStream)
{
  unsigned int posStateMask; // edx
  unsigned __int8 properties[8]; // [esp+0h] [ebp-8h] BYREF

  properties[0] = LOBYTE(this->_posStateBits) + 9 * (LOBYTE(this->_distTableSize) + 5 * LOBYTE(this->_alignPrices[15]));
  posStateMask = this->_posStateMask;
  *(_DWORD *)&properties[1] = posStateMask;
  return WriteStream(stream: outStream, data: properties, size: 5u, processedSize: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100127E0
// Name: public: virtual long NCompress::NLZMA::CEncoder::SetOutStream(struct ISequentialOutStream __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::SetOutStream(
        NCompress::NLZMA::CEncoder *this,
        ISequentialOutStream *outStream)
{
  COutBuffer::SetStream(this: (COutBuffer *)(&this->_rangeEncoder.Range + 1), stream: outStream);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012800
// Name: private: unsigned int NCompress::NLZMA::CEncoder::Backward(unsigned int __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::Backward(
        NCompress::NLZMA::CEncoder *this,
        unsigned int *backRes,
        unsigned int cur)
{
  unsigned int v3; // esi
  char *v4; // eax
  unsigned int PosPrev; // edx
  char *v6; // edi
  char *v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned int result; // eax
  unsigned int backMem; // [esp+18h] [ebp+Ch]

  v3 = cur;
  v4 = (char *)this + 40 * cur;
  this->_optimumEndIndex = cur;
  PosPrev = *((_DWORD *)v4 + 14);
  backMem = *((_DWORD *)v4 + 15);
  do
  {
    v6 = (char *)this + 40 * v3;
    if ( v6[41] != 0 )
    {
      v7 = (char *)this + 40 * PosPrev;
      *((_DWORD *)v7 + 15) = -1;
      v7[41] = 0;
      *((_DWORD *)v7 + 14) = PosPrev - 1;
      if ( v6[42] != 0 )
      {
        v7[1] = 0;
        *((_DWORD *)v7 + 4) = *((_DWORD *)v6 + 11);
        *((_DWORD *)v7 + 5) = *((_DWORD *)v6 + 12);
      }
    }
    v8 = backMem;
    v9 = PosPrev;
    v10 = PosPrev;
    backMem = this->_optimum[PosPrev].BackPrev;
    PosPrev = this->_optimum[PosPrev].PosPrev;
    this->_optimum[v9].PosPrev = v3;
    this->_optimum[v9].BackPrev = v8;
    v3 = v10;
  }
  while ( v10 != 0 );
  *backRes = this->_optimum[0].BackPrev;
  result = this->_optimum[0].PosPrev;
  this->_optimumCurrentIndex = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100128A0
// Name: public: void NCompress::NRangeCoder::CBitEncoder<5>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitEncoder<5>::Encode(
        NCompress::NRangeCoder::CBitEncoder<5> *this,
        NCompress::NRangeCoder::CEncoder *encoder,
        unsigned int symbol)
{
  unsigned int Range; // esi
  unsigned int v4; // edx
  unsigned int v5; // ecx

  Range = encoder->Range;
  v4 = this->Prob * (Range >> 11);
  if ( symbol != 0 )
  {
    encoder->Low += v4;
    encoder->Range = Range - v4;
    this->Prob -= this->Prob >> 5;
  }
  else
  {
    encoder->Range = v4;
    this->Prob += (2048 - this->Prob) >> 5;
  }
  v5 = encoder->Range;
  if ( v5 < 0x1000000 )
  {
    encoder->Range = v5 << 8;
    NCompress::NRangeCoder::CEncoder::ShiftLow(this: encoder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012910
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,3> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,3> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 3;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x100129B0
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,8> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,8> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 8;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10012A50
// Name: public: struct IMatchFinder __near * CMyComPtr<struct IMatchFinder>::operator=(struct IMatchFinder __near *)
// Source: json
//------------------------------------------------------------------------------
IMatchFinder *__thiscall CMyComPtr<IMatchFinder>::operator=(CMyComPtr<IMatchFinder> *this, IMatchFinder *p)
{
  if ( p != nullptr )
    p->AddRef(this: p);
  if ( this->_p != nullptr )
    this->_p->Release(this: this->_p);
  this->_p = p;
  return p;
}

//------------------------------------------------------------------------------
// Address: 0x10012A80
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,6> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,6> *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int bitIndex; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 6;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    bitIndex = v7;
    Range = rangeEncoder->Range;
    v10 = v4->Models[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = bitIndex;
    v5 = v11 | (2 * v5);
  }
  while ( bitIndex != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10012B20
// Name: public: void NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
        NCompress::NRangeCoder::CBitTreeEncoder<5,4> *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol)
{
  NCompress::NRangeCoder::CBitTreeEncoder<5,4> *v4; // edx
  int v5; // edi
  unsigned int Range; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  int rangeEncodera; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  for ( rangeEncodera = 4; rangeEncodera != 0; --rangeEncodera )
  {
    Range = rangeEncoder->Range;
    v7 = v4->Models[v5].Prob * (Range >> 11);
    v8 = symbol & 1;
    if ( (symbol & 1) != 0 )
    {
      rangeEncoder->Low += v7;
      rangeEncoder->Range = Range - v7;
      v4->Models[v5].Prob -= v4->Models[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v7;
      v4->Models[v5].Prob += (2048 - v4->Models[v5].Prob) >> 5;
    }
    v9 = rangeEncoder->Range;
    if ( v9 < 0x1000000 )
    {
      rangeEncoder->Range = v9 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    symbol >>= 1;
    v5 = v8 | (2 * v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012BC0
// Name: void NCompress::NRangeCoder::ReverseBitTreeEncode<5>(class NCompress::NRangeCoder::CBitEncoder<5> __near *,class NCompress::NRangeCoder::CEncoder __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NCompress::NRangeCoder::ReverseBitTreeEncode<5>(
        NCompress::NRangeCoder::CBitEncoder<5> *Models,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        int NumBitLevels,
        unsigned int symbol)
{
  int v4; // edi
  unsigned int Range; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax

  v4 = 1;
  if ( NumBitLevels > 0 )
  {
    do
    {
      Range = rangeEncoder->Range;
      v6 = Models[v4].Prob * (Range >> 11);
      v7 = symbol & 1;
      if ( (symbol & 1) != 0 )
      {
        rangeEncoder->Low += v6;
        rangeEncoder->Range = Range - v6;
        Models[v4].Prob -= Models[v4].Prob >> 5;
      }
      else
      {
        rangeEncoder->Range = v6;
        Models[v4].Prob += (2048 - Models[v4].Prob) >> 5;
      }
      v8 = rangeEncoder->Range;
      if ( v8 < 0x1000000 )
      {
        rangeEncoder->Range = v8 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      symbol >>= 1;
      v4 = v7 | (2 * v4);
      --NumBitLevels;
    }
    while ( NumBitLevels != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012C50
// Name: unsigned int NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(class NCompress::NRangeCoder::CBitEncoder<5> __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(
        NCompress::NRangeCoder::CBitEncoder<5> *Models,
        int NumBitLevels,
        unsigned int symbol)
{
  __int64 i; // rax
  unsigned int v5; // ecx

  for ( i = 0x100000000LL; NumBitLevels != 0; --NumBitLevels )
  {
    v5 = symbol & 1;
    LODWORD(i) = NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v5 ^ (Models[HIDWORD(i)].Prob - v5)) >> 2) & 0x1FF]
               + i;
    symbol >>= 1;
    HIDWORD(i) = v5 | (2 * HIDWORD(i));
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10012CE0
// Name: public: void NCompress::NRangeCoder::CEncoder::FlushData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NRangeCoder::CEncoder::FlushData(NCompress::NRangeCoder::CEncoder *this)
{
  unsigned int Low; // edi
  unsigned __int8 cache; // bl
  bool v4; // zf
  int v5; // [esp+Ch] [ebp-4h]

  v5 = 5;
  do
  {
    Low = this->Low;
    if ( Low < 0xFF000000 || HIDWORD(this->Low) != 0 )
    {
      cache = this->_cache;
      do
      {
        this->Stream._buffer[this->Stream._pos++] = cache + HIDWORD(this->Low);
        if ( this->Stream._pos == this->Stream._limitPos )
          COutBuffer::FlushWithCheck(this: &this->Stream);
        cache = -1;
        v4 = this->_cacheSize-- == 1;
      }
      while ( !v4 );
      Low = this->Low;
      this->_cache = HIBYTE(Low);
    }
    ++this->_cacheSize;
    v4 = v5-- == 1;
    LODWORD(this->Low) = Low << 8;
    HIDWORD(this->Low) = 0;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x10012D70
// Name: private: void NCompress::NLZMA::CEncoder::ReleaseMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::ReleaseMatchFinder(NCompress::NLZMA::CEncoder *this)
{
  IMatchFinder *p; // eax

  this->setMfPasses = nullptr;
  p = this->_matchFinder._p;
  if ( p != nullptr )
  {
    p->Release(this: p);
    this->_matchFinder._p = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012DA0
// Name: private: unsigned int NCompress::NLZMA::CEncoder::GetPureRepPrice(unsigned int,class NCompress::NLZMA::CState,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetPureRepPrice(
        NCompress::NLZMA::CEncoder *this,
        unsigned int repIndex,
        NCompress::NLZMA::CState state,
        unsigned int posState)
{
  unsigned int v5; // eax

  if ( repIndex == 0 )
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[state.Index].Prob >> 2]
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[state.Index][posState].Prob) >> 2];
  v5 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRepG0[state.Index].Prob) >> 2];
  if ( repIndex == 1 )
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG1[state.Index].Prob >> 2] + v5;
  else
    return NCompress::NRangeCoder::CPriceTables::ProbPrices[(((2 - repIndex)
                                                            ^ (this->_isRepG2[state.Index].Prob - (repIndex - 2))) >> 2)
                                                          & 0x1FF]
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRepG1[state.Index].Prob) >> 2]
         + v5;
}

//------------------------------------------------------------------------------
// Address: 0x10012E60
// Name: public: NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(
        NCompress::NLZMA::CEncoder::CCoderReleaser *this)
{
  NCompress::NLZMA::CEncoder *coder; // esi
  IMatchFinder *p; // eax

  coder = this->_coder;
  p = this->_coder->_matchFinder._p;
  if ( p != nullptr && coder->_needReleaseMFStream )
  {
    p->ReleaseStream(this: p);
    coder->_needReleaseMFStream = false;
  }
  coder->ReleaseOutStream(this: &coder->ICompressSetOutStream);
}

//------------------------------------------------------------------------------
// Address: 0x10012F00
// Name: private: virtual long NBT2::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::GetMatches(NBT2::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // edx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  unsigned int v6; // ebx
  HRESULT result; // eax
  unsigned __int8 *buffer; // edi
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned int *v11; // eax
  unsigned int v12; // ecx
  unsigned int cutValue; // eax
  unsigned int v14; // eax
  unsigned int cyclicBufferPos; // ebx
  unsigned int v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned __int8 *v19; // edx
  int v20; // edx
  unsigned __int8 *v21; // ebx
  unsigned int *v22; // ecx
  const unsigned __int8 *cur; // [esp+8h] [ebp-38h]
  unsigned int delta; // [esp+Ch] [ebp-34h]
  int i; // [esp+10h] [ebp-30h]
  unsigned int *son; // [esp+14h] [ebp-2Ch]
  unsigned int count; // [esp+18h] [ebp-28h]
  unsigned int matchMinPos; // [esp+1Ch] [ebp-24h]
  unsigned int len1; // [esp+20h] [ebp-20h]
  unsigned int *pair; // [esp+24h] [ebp-1Ch]
  unsigned int len0; // [esp+28h] [ebp-18h]
  const unsigned __int8 *pb; // [esp+2Ch] [ebp-14h]
  unsigned int maxLen; // [esp+30h] [ebp-10h]
  int offset; // [esp+34h] [ebp-Ch]
  unsigned int *ptr0; // [esp+38h] [ebp-8h]
  unsigned int *ptr1; // [esp+3Ch] [ebp-4h]
  unsigned int lenLimit; // [esp+48h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 3 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos((NBT4::CMatchFinder *)this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    v6 = 0;
  else
    v6 = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v9 = buffer[pos + 1];
  v10 = &buffer[pos];
  maxLen = 1;
  v11 = &this->_hash[*v10 ^ (v9 << 8)];
  v12 = *v11;
  *v11 = pos;
  son = this->_son;
  ptr1 = &son[2 * this->_cyclicBufferPos];
  matchMinPos = v6;
  cur = v10;
  ptr0 = ptr1 + 1;
  len1 = 2;
  len0 = 2;
  if ( v12 > v6 && this->_buffer[v12 + 2] != v10[2] )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - v12 - 1;
    offset = 3;
  }
  cutValue = this->_cutValue;
  if ( v12 > v6 )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v16 = this->_pos - v12;
      delta = v16;
      if ( v16 > cyclicBufferPos )
        v17 = cyclicBufferPos + this->_cyclicBufferSize - v16;
      else
        v17 = cyclicBufferPos - v16;
      v18 = len1;
      pair = &son[2 * v17];
      v19 = &this->_buffer[v12];
      pb = v19;
      if ( len0 < len1 )
        v18 = len0;
      if ( v19[v18] == v10[v18] )
      {
        if ( ++v18 != lenLimit )
        {
          v20 = v19 - v10;
          v21 = &v10[v18];
          for ( i = v20; v21[v20] == *v21; v20 = i )
          {
            ++v18;
            ++v21;
            if ( v18 == lenLimit )
              break;
          }
          v19 = &this->_buffer[v12];
        }
        if ( maxLen < v18 )
        {
          distances[offset] = v18;
          distances[offset + 1] = delta - 1;
          maxLen = v18;
          offset += 2;
          if ( v18 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0 = pair[1];
            goto LABEL_13;
          }
          v10 = (unsigned __int8 *)cur;
          v19 = (unsigned __int8 *)pb;
        }
      }
      if ( v19[v18] >= v10[v18] )
      {
        *ptr0 = v12;
        v22 = pair;
        ptr0 = pair;
        len0 = v18;
      }
      else
      {
        *ptr1 = v12;
        v22 = pair + 1;
        ptr1 = pair + 1;
        len1 = v18;
      }
      v12 = *v22;
      if ( v12 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  *ptr1 = 0;
  *ptr0 = 0;
LABEL_13:
  *distances = offset - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v14 = ++this->_pos;
  if ( v14 <= this->_posLimit )
    goto LABEL_19;
  if ( &this->_buffer[v14] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_19:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize((NBT4::CMatchFinder *)this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013140
// Name: private: virtual long NBT2::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT2::CMatchFinder::Skip(NBT2::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // edi
  int v16; // eax
  int v17; // ecx
  unsigned __int8 *v18; // edi
  unsigned int *v19; // eax
  unsigned int v20; // ecx
  unsigned int *v21; // ebx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v24; // edx
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned __int8 *v27; // edx
  unsigned __int8 *v28; // edx
  unsigned __int8 *v29; // ebx
  unsigned int *v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // eax
  unsigned int *hash; // ebx
  unsigned int v34; // edx
  unsigned int v35; // eax
  unsigned int v36; // edx
  unsigned int v37; // edx
  unsigned int count; // [esp+Ch] [ebp-28h]
  unsigned int *son; // [esp+10h] [ebp-24h]
  unsigned __int8 *v40; // [esp+18h] [ebp-1Ch]
  unsigned int len0; // [esp+1Ch] [ebp-18h]
  unsigned int len1; // [esp+20h] [ebp-14h]
  unsigned int *pair; // [esp+24h] [ebp-10h]
  unsigned int matchMinPos; // [esp+28h] [ebp-Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-8h]
  unsigned int *ptr1; // [esp+30h] [ebp-4h]
  unsigned int lenLimit; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimita; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimitb; // [esp+3Ch] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = buffer[pos + 1];
      v17 = buffer[pos];
      v18 = &buffer[pos];
      v19 = &this->_hash[v17 ^ (v16 << 8)];
      v20 = *v19;
      *v19 = pos;
      v21 = this->_son;
      ptr1 = &v21[2 * this->_cyclicBufferPos];
      len1 = 2;
      len0 = 2;
      cutValue = this->_cutValue;
      son = v21;
      ptr0 = ptr1 + 1;
      if ( v20 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v24 = this->_pos - v20;
          if ( v24 > cyclicBufferPos )
            v25 = this->_cyclicBufferSize + cyclicBufferPos - v24;
          else
            v25 = cyclicBufferPos - v24;
          pair = &v21[2 * v25];
          v26 = len0;
          v27 = &this->_buffer[v20];
          if ( len0 >= len1 )
            v26 = len1;
          if ( v27[v26] == v18[v26] )
          {
            if ( ++v26 == lenLimit )
              goto LABEL_40;
            v28 = (unsigned __int8 *)(v27 - v18);
            v29 = &v18[v26];
            v40 = v28;
            while ( v29[(_DWORD)v28] == *v29 )
            {
              ++v26;
              ++v29;
              if ( v26 == lenLimit )
                goto LABEL_40;
              v28 = v40;
            }
            if ( v26 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v27 = &this->_buffer[v20];
          }
          if ( v27[v26] >= v18[v26] )
          {
            *ptr0 = v20;
            v30 = pair;
            ptr0 = pair;
            len0 = v26;
          }
          else
          {
            *ptr1 = v20;
            v30 = pair + 1;
            ptr1 = pair + 1;
            len1 = v26;
          }
          v20 = *v30;
          if ( v20 <= matchMinPos )
            break;
          v21 = son;
          cutValue = count;
        }
      }
      *ptr1 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v31 = ++this->_pos;
      if ( v31 > this->_posLimit )
      {
        if ( &this->_buffer[v31] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v32 = this->_cyclicBufferSize;
        hash = this->_hash;
        v34 = this->_hashSizeSum + 2 * v32;
        v11 = 0x7FFFFFFF - v32;
        v35 = 0;
        for ( lenLimitb = v34; v35 < lenLimitb; ++v35 )
        {
          v36 = hash[v35];
          if ( v36 > v11 )
            v37 = v36 - v11;
          else
            v37 = 0;
          hash[v35] = v37;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 3 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013430
// Name: private: virtual long NBT3::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::GetMatches(NBT3::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int *hash; // ecx
  unsigned int v13; // eax
  int v14; // edx
  unsigned int v15; // edi
  unsigned int cyclicBufferPos; // ecx
  unsigned int v17; // ebx
  int v18; // edx
  unsigned int *v19; // ecx
  unsigned int cutValue; // eax
  unsigned int *v21; // edx
  int v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // edx
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int *v27; // edx
  unsigned int v28; // eax
  unsigned __int8 *v29; // ecx
  const unsigned __int8 *v30; // edx
  int i; // ebx
  const unsigned __int8 *pb; // [esp+8h] [ebp-3Ch]
  unsigned int delta; // [esp+Ch] [ebp-38h]
  unsigned int *son; // [esp+18h] [ebp-2Ch]
  unsigned int count; // [esp+1Ch] [ebp-28h]
  unsigned int len0; // [esp+20h] [ebp-24h]
  unsigned int len0a; // [esp+20h] [ebp-24h]
  unsigned int len1; // [esp+24h] [ebp-20h]
  unsigned int *pair; // [esp+28h] [ebp-1Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-18h]
  unsigned int *ptr1; // [esp+30h] [ebp-14h]
  unsigned int matchMinPos; // [esp+34h] [ebp-10h]
  const unsigned __int8 *cur; // [esp+38h] [ebp-Ch]
  unsigned int lenLimit; // [esp+3Ch] [ebp-8h]
  unsigned int maxLen; // [esp+40h] [ebp-4h]
  int offset; // [esp+4Ch] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 3 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos((NBT4::CMatchFinder *)this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  cur = v9;
  LOWORD(v8) = LOWORD(CCRC::Table[v8]) ^ v9[1];
  v11 = v10 ^ (v9[2] << 8);
  hash = this->_hash;
  v13 = this->_hashMask & v11;
  v14 = v8 & 0x3FF;
  len0 = hash[v14];
  maxLen = 1;
  v15 = hash[v13 + 1024];
  hash[v14] = this->_pos;
  if ( len0 > matchMinPos && this->_buffer[len0] == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - len0 - 1;
    offset = 3;
    if ( len0 == v15 )
    {
      offset = 1;
      maxLen = 1;
    }
  }
  this->_hash[v13 + 1024] = this->_pos;
  cyclicBufferPos = this->_cyclicBufferPos;
  son = this->_son;
  v17 = 0;
  v18 = (int)&son[2 * cyclicBufferPos + 1];
  v19 = &son[2 * cyclicBufferPos];
  cutValue = this->_cutValue;
  ptr0 = (unsigned int *)v18;
  ptr1 = v19;
  len1 = 0;
  len0a = 0;
  if ( v15 > matchMinPos )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      v24 = this->_cyclicBufferPos;
      v25 = this->_pos - v15;
      delta = v25;
      if ( v25 > v24 )
        v26 = v24 + this->_cyclicBufferSize - v25;
      else
        v26 = v24 - v25;
      v27 = &son[2 * v26];
      v28 = len1;
      v29 = &this->_buffer[v15];
      pair = v27;
      pb = v29;
      if ( v17 < len1 )
        v28 = v17;
      if ( v29[v28] == cur[v28] )
      {
        if ( ++v28 != lenLimit )
        {
          v30 = &cur[v28];
          for ( i = v29 - cur; v30[i] == *v30; i = v29 - cur )
          {
            ++v28;
            ++v30;
            if ( v28 == lenLimit )
              break;
          }
        }
        if ( maxLen < v28 )
        {
          v21 = distances;
          distances[offset] = v28;
          distances[offset + 1] = delta - 1;
          v22 = offset + 2;
          maxLen = v28;
          offset += 2;
          if ( v28 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0 = pair[1];
            goto LABEL_14;
          }
          v29 = (unsigned __int8 *)pb;
        }
      }
      if ( v29[v28] >= cur[v28] )
      {
        *ptr0 = v15;
        v15 = *pair;
        v17 = v28;
        ptr0 = pair;
        v19 = ptr1;
        len0a = v28;
      }
      else
      {
        v17 = len0a;
        *ptr1 = v15;
        v15 = pair[1];
        v19 = pair + 1;
        ptr1 = pair + 1;
        len1 = v28;
      }
      if ( v15 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  v21 = distances;
  *v19 = 0;
  *ptr0 = 0;
  v22 = offset;
LABEL_14:
  *v21 = v22 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v23 = ++this->_pos;
  if ( v23 <= this->_posLimit )
    goto LABEL_20;
  if ( &this->_buffer[v23] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_20:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize((NBT4::CMatchFinder *)this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100136C0
// Name: private: virtual long NBT3::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT3::CMatchFinder::Skip(NBT3::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // edx
  unsigned int v16; // eax
  int v17; // ecx
  unsigned __int8 *v18; // edx
  unsigned int v19; // ecx
  unsigned int *hash; // eax
  unsigned int v21; // edi
  unsigned int *v22; // ebx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // ecx
  unsigned __int8 *v29; // ecx
  unsigned __int8 *v30; // ebx
  unsigned int *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int *v34; // ebx
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // edx
  unsigned int *son; // [esp+Ch] [ebp-28h]
  unsigned int count; // [esp+10h] [ebp-24h]
  unsigned __int8 *v41; // [esp+18h] [ebp-1Ch]
  unsigned int len0; // [esp+1Ch] [ebp-18h]
  unsigned int len1; // [esp+20h] [ebp-14h]
  unsigned int *pair; // [esp+24h] [ebp-10h]
  unsigned int matchMinPos; // [esp+28h] [ebp-Ch]
  unsigned int *ptr0; // [esp+2Ch] [ebp-8h]
  unsigned int *ptr1; // [esp+30h] [ebp-4h]
  unsigned int lenLimit; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimita; // [esp+3Ch] [ebp+8h]
  unsigned int lenLimitb; // [esp+3Ch] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v17 = buffer[pos + 2];
      v18 = &buffer[pos];
      v19 = this->_hashMask & (v16 ^ (v17 << 8));
      this->_hash[v16 & 0x3FF] = pos;
      hash = this->_hash;
      v21 = hash[v19 + 1024];
      hash[v19 + 1024] = this->_pos;
      v22 = this->_son;
      ptr1 = &v22[2 * this->_cyclicBufferPos];
      len1 = 0;
      len0 = 0;
      cutValue = this->_cutValue;
      son = v22;
      ptr0 = ptr1 + 1;
      if ( v21 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v25 = this->_pos - v21;
          if ( v25 > cyclicBufferPos )
            v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
          else
            v26 = cyclicBufferPos - v25;
          pair = &v22[2 * v26];
          v27 = len0;
          v28 = &this->_buffer[v21];
          if ( len0 >= len1 )
            v27 = len1;
          if ( v28[v27] == v18[v27] )
          {
            if ( ++v27 == lenLimit )
              goto LABEL_40;
            v29 = (unsigned __int8 *)(v28 - v18);
            v30 = &v18[v27];
            v41 = v29;
            while ( v30[(_DWORD)v29] == *v30 )
            {
              ++v27;
              ++v30;
              if ( v27 == lenLimit )
                goto LABEL_40;
              v29 = v41;
            }
            if ( v27 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v28 = &this->_buffer[v21];
          }
          if ( v28[v27] >= v18[v27] )
          {
            *ptr0 = v21;
            v31 = pair;
            ptr0 = pair;
            len0 = v27;
          }
          else
          {
            *ptr1 = v21;
            v31 = pair + 1;
            ptr1 = pair + 1;
            len1 = v27;
          }
          v21 = *v31;
          if ( *v31 <= matchMinPos )
            break;
          cutValue = count;
          v22 = son;
        }
      }
      *ptr1 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v32 = ++this->_pos;
      if ( v32 > this->_posLimit )
      {
        if ( &this->_buffer[v32] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v33 = this->_cyclicBufferSize;
        v34 = this->_hash;
        v35 = this->_hashSizeSum + 2 * v33;
        v11 = 0x7FFFFFFF - v33;
        v36 = 0;
        for ( lenLimitb = v35; v36 < lenLimitb; ++v36 )
        {
          v37 = v34[v36];
          if ( v37 > v11 )
            v38 = v37 - v11;
          else
            v38 = 0;
          v34[v36] = v38;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 3 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100139D0
// Name: private: virtual long NBT4::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::GetMatches(NBT4::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned __int16 v13; // dx
  __int16 v14; // di
  unsigned int *hash; // ecx
  int v16; // edi
  int v17; // ebx
  unsigned int *v18; // edi
  unsigned int v19; // ecx
  unsigned int *v20; // edi
  unsigned int cutValue; // eax
  unsigned int *v22; // ecx
  unsigned int v23; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // edi
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // edi
  const unsigned __int8 *v29; // ecx
  unsigned int delta; // [esp+8h] [ebp-34h]
  unsigned int *son; // [esp+Ch] [ebp-30h]
  unsigned int count; // [esp+10h] [ebp-2Ch]
  unsigned int curMatch3; // [esp+14h] [ebp-28h]
  unsigned int curMatch3a; // [esp+14h] [ebp-28h]
  unsigned int len1; // [esp+18h] [ebp-24h]
  unsigned int *pair; // [esp+1Ch] [ebp-20h]
  unsigned int *ptr0; // [esp+20h] [ebp-1Ch]
  unsigned int *ptr0a; // [esp+20h] [ebp-1Ch]
  unsigned int *ptr1; // [esp+24h] [ebp-18h]
  const unsigned __int8 *cur; // [esp+28h] [ebp-14h]
  unsigned int lenLimit; // [esp+2Ch] [ebp-10h]
  unsigned int matchMinPos; // [esp+30h] [ebp-Ch]
  unsigned int maxLen; // [esp+34h] [ebp-8h]
  unsigned int curMatch; // [esp+38h] [ebp-4h]
  int offset; // [esp+44h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 4 )
    {
      *distances = 0;
      return NBT4::CMatchFinder::MovePos(this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  offset = 1;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  v11 = v9[2];
  cur = v9;
  v12 = this->_hashMask & (v10 ^ (32 * (CCRC::Table[v9[3]] ^ (8 * v11))));
  maxLen = 1;
  v13 = v10 ^ ((_WORD)v11 << 8);
  v14 = v10;
  hash = this->_hash;
  v16 = v14 & 0x3FF;
  curMatch = hash[v12 + 66560];
  ptr0 = (unsigned int *)hash[v16];
  curMatch3 = hash[v13 + 1024];
  hash[v16] = this->_pos;
  if ( (unsigned int)ptr0 > matchMinPos && *((_BYTE *)ptr0 + (unsigned int)this->_buffer) == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - (_DWORD)ptr0 - 1;
    v17 = 3;
    offset = 3;
  }
  else
  {
    v17 = 1;
  }
  this->_hash[v13 + 1024] = this->_pos;
  v18 = (unsigned int *)curMatch3;
  if ( curMatch3 > matchMinPos && this->_buffer[curMatch3] == *cur )
  {
    if ( (unsigned int *)curMatch3 == ptr0 )
      v17 -= 2;
    distances[v17] = 3;
    distances[v17 + 1] = this->_pos - curMatch3 - 1;
    v17 += 2;
    maxLen = 3;
    offset = v17;
  }
  else
  {
    v18 = ptr0;
  }
  v19 = curMatch;
  if ( v17 != 1 && v18 == (unsigned int *)curMatch )
  {
    v17 -= 2;
    offset = v17;
    maxLen = 1;
  }
  this->_hash[v12 + 66560] = this->_pos;
  son = this->_son;
  v20 = &son[2 * this->_cyclicBufferPos];
  len1 = 0;
  curMatch3a = 0;
  cutValue = this->_cutValue;
  ptr0a = v20 + 1;
  ptr1 = v20;
  if ( curMatch > matchMinPos )
  {
    while ( 1 )
    {
      count = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v25 = this->_pos - v19;
      delta = v25;
      if ( v25 > cyclicBufferPos )
        v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
      else
        v26 = cyclicBufferPos - v25;
      pair = &son[2 * v26];
      v27 = curMatch3a;
      v28 = &this->_buffer[v19];
      if ( curMatch3a >= len1 )
        v27 = len1;
      if ( v28[v27] == cur[v27] )
      {
        if ( ++v27 != lenLimit )
        {
          v29 = &cur[v27];
          do
          {
            if ( v29[v28 - cur] != *v29 )
              break;
            ++v27;
            ++v29;
          }
          while ( v27 != lenLimit );
          v19 = curMatch;
        }
        v17 = offset;
        if ( maxLen < v27 )
        {
          v22 = distances;
          distances[offset] = v27;
          distances[offset + 1] = delta - 1;
          v17 = offset + 2;
          maxLen = v27;
          offset += 2;
          if ( v27 == lenLimit )
          {
            *ptr1 = *pair;
            *ptr0a = pair[1];
            goto LABEL_23;
          }
          v19 = curMatch;
        }
      }
      else
      {
        v17 = offset;
      }
      if ( v28[v27] >= cur[v27] )
      {
        v20 = ptr1;
        *ptr0a = v19;
        ptr0a = pair;
        v19 = *pair;
        curMatch3a = v27;
      }
      else
      {
        v20 = pair + 1;
        *ptr1 = v19;
        v19 = pair[1];
        ptr1 = pair + 1;
        len1 = v27;
      }
      curMatch = v19;
      if ( v19 <= matchMinPos )
        break;
      cutValue = count;
    }
  }
  v22 = distances;
  *v20 = 0;
  *ptr0a = 0;
LABEL_23:
  *v22 = v17 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v23 = ++this->_pos;
  if ( v23 <= this->_posLimit )
    goto LABEL_29;
  if ( &this->_buffer[v23] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_29:
    if ( this->_pos == 0x7FFFFFFF )
      NBT4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013CF0
// Name: private: virtual long NBT4::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NBT4::CMatchFinder::Skip(NBT4::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // ecx
  unsigned int v6; // eax
  HRESULT result; // eax
  unsigned int v8; // eax
  unsigned int *v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *buffer; // ecx
  unsigned int v16; // eax
  int v17; // edx
  unsigned int v18; // ecx
  unsigned int *hash; // eax
  unsigned int v20; // edx
  unsigned int *v21; // edi
  unsigned int *v22; // ecx
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned __int8 *v28; // edi
  const unsigned __int8 *v29; // ecx
  int v30; // ebx
  const unsigned __int8 *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int *v34; // ebx
  unsigned int v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // edx
  unsigned int count; // [esp+Ch] [ebp-2Ch]
  unsigned int *son; // [esp+10h] [ebp-28h]
  unsigned int len0; // [esp+1Ch] [ebp-1Ch]
  unsigned int len1; // [esp+20h] [ebp-18h]
  const unsigned __int8 *cur; // [esp+24h] [ebp-14h]
  unsigned int *pair; // [esp+28h] [ebp-10h]
  unsigned int matchMinPos; // [esp+2Ch] [ebp-Ch]
  unsigned int *ptr0; // [esp+30h] [ebp-8h]
  unsigned int *ptr1; // [esp+34h] [ebp-4h]
  unsigned int lenLimit; // [esp+40h] [ebp+8h]
  unsigned int lenLimita; // [esp+40h] [ebp+8h]
  unsigned int lenLimitb; // [esp+40h] [ebp+8h]

  do
  {
    pos = this->_pos;
    streamPos = this->_streamPos;
    if ( pos + this->_matchMaxLen <= streamPos )
    {
      lenLimit = this->_matchMaxLen;
LABEL_3:
      cyclicBufferSize = this->_cyclicBufferSize;
      if ( pos <= cyclicBufferSize )
        matchMinPos = 0;
      else
        matchMinPos = pos - cyclicBufferSize;
      buffer = this->_buffer;
      v16 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v17 = buffer[pos + 2];
      cur = &buffer[pos];
      v18 = this->_hashMask & (v16 ^ (32 * (CCRC::Table[buffer[pos + 3]] ^ (8 * v17))));
      this->_hash[(unsigned __int16)(v16 ^ ((_WORD)v17 << 8)) + 1024] = pos;
      this->_hash[v16 & 0x3FF] = this->_pos;
      hash = this->_hash;
      v20 = hash[v18 + 66560];
      hash[v18 + 66560] = this->_pos;
      v21 = this->_son;
      ptr0 = &v21[2 * this->_cyclicBufferPos + 1];
      v22 = &v21[2 * this->_cyclicBufferPos];
      len1 = 0;
      len0 = 0;
      cutValue = this->_cutValue;
      son = v21;
      ptr1 = v22;
      if ( v20 > matchMinPos )
      {
        while ( 1 )
        {
          count = cutValue - 1;
          if ( cutValue == 0 )
            break;
          cyclicBufferPos = this->_cyclicBufferPos;
          v25 = this->_pos - v20;
          if ( v25 > cyclicBufferPos )
            v26 = this->_cyclicBufferSize + cyclicBufferPos - v25;
          else
            v26 = cyclicBufferPos - v25;
          pair = &v21[2 * v26];
          v27 = len0;
          v28 = &this->_buffer[v20];
          if ( len0 >= len1 )
            v27 = len1;
          v29 = cur;
          if ( v28[v27] == cur[v27] )
          {
            if ( ++v27 == lenLimit )
              goto LABEL_40;
            v30 = v28 - cur;
            v31 = &cur[v27];
            while ( v31[v30] == *v31 )
            {
              ++v27;
              ++v31;
              if ( v27 == lenLimit )
                goto LABEL_40;
              v30 = v28 - cur;
            }
            if ( v27 == lenLimit )
            {
LABEL_40:
              *ptr1 = *pair;
              *ptr0 = pair[1];
              goto LABEL_42;
            }
            v29 = cur;
          }
          if ( v28[v27] >= v29[v27] )
          {
            *ptr0 = v20;
            v20 = *pair;
            ptr0 = pair;
            v22 = ptr1;
            len0 = v27;
          }
          else
          {
            *ptr1 = v20;
            v20 = pair[1];
            v22 = pair + 1;
            ptr1 = pair + 1;
            len1 = v27;
          }
          if ( v20 <= matchMinPos )
            break;
          v21 = son;
          cutValue = count;
        }
      }
      *v22 = 0;
      *ptr0 = 0;
LABEL_42:
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v32 = ++this->_pos;
      if ( v32 > this->_posLimit )
      {
        if ( &this->_buffer[v32] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v33 = this->_cyclicBufferSize;
        v34 = this->_hash;
        v35 = this->_hashSizeSum + 2 * v33;
        v11 = 0x7FFFFFFF - v33;
        v36 = 0;
        for ( lenLimitb = v35; v36 < lenLimitb; ++v36 )
        {
          v37 = v34[v36];
          if ( v37 > v11 )
            v38 = v37 - v11;
          else
            v38 = 0;
          v34[v36] = v38;
        }
LABEL_54:
        this->_buffer += v11;
        this->_posLimit -= v11;
        this->_pos -= v11;
        this->_streamPos -= v11;
        goto LABEL_55;
      }
      goto LABEL_55;
    }
    lenLimit = streamPos - pos;
    if ( streamPos - pos >= 4 )
      goto LABEL_3;
    if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
      this->_cyclicBufferPos = 0;
    v6 = ++this->_pos;
    if ( v6 > this->_posLimit )
    {
      if ( &this->_buffer[v6] > this->_pointerToLastSafePosition )
        CLZInWindow::MoveBlock(this: &this->CLZInWindow);
      result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
      if ( result != 0 )
        return result;
    }
    if ( this->_pos == 0x7FFFFFFF )
    {
      v8 = this->_cyclicBufferSize;
      v9 = this->_hash;
      v10 = this->_hashSizeSum + 2 * v8;
      v11 = 0x7FFFFFFF - v8;
      v12 = 0;
      for ( lenLimita = v10; v12 < lenLimita; ++v12 )
      {
        v13 = v9[v12];
        if ( v13 > v11 )
          v14 = v13 - v11;
        else
          v14 = 0;
        v9[v12] = v14;
      }
      goto LABEL_54;
    }
LABEL_55:
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014040
// Name: private: virtual long NHC4::CMatchFinder::GetMatches(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::GetMatches(NHC4::CMatchFinder *this, unsigned int *distances)
{
  unsigned int pos; // ecx
  unsigned int streamPos; // eax
  unsigned int cyclicBufferSize; // eax
  HRESULT result; // eax
  unsigned __int8 *buffer; // eax
  int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned __int16 v13; // dx
  __int16 v14; // di
  unsigned int *hash; // ecx
  int v16; // edi
  int v17; // ecx
  unsigned int v18; // edi
  unsigned int cutValue; // eax
  unsigned int cyclicBufferPos; // eax
  unsigned int v21; // edx
  unsigned int v22; // eax
  unsigned __int8 *v23; // edx
  unsigned int v24; // eax
  _BYTE *v25; // edi
  int v26; // edx
  unsigned int v27; // eax
  unsigned int *son; // [esp+8h] [ebp-20h]
  unsigned int curMatch3; // [esp+Ch] [ebp-1Ch]
  unsigned int curMatch3a; // [esp+Ch] [ebp-1Ch]
  unsigned int lenLimit; // [esp+10h] [ebp-18h]
  unsigned int cyclicPos; // [esp+14h] [ebp-14h]
  unsigned int cyclicPosa; // [esp+14h] [ebp-14h]
  int offset; // [esp+18h] [ebp-10h]
  unsigned int delta; // [esp+1Ch] [ebp-Ch]
  unsigned int deltaa; // [esp+1Ch] [ebp-Ch]
  unsigned int matchMinPos; // [esp+20h] [ebp-8h]
  const unsigned __int8 *cur; // [esp+24h] [ebp-4h]
  unsigned int maxLen; // [esp+30h] [ebp+8h]

  pos = this->_pos;
  streamPos = this->_streamPos;
  if ( pos + this->_matchMaxLen > streamPos )
  {
    lenLimit = streamPos - pos;
    if ( streamPos - pos < 4 )
    {
      *distances = 0;
      return NHC4::CMatchFinder::MovePos(this);
    }
  }
  else
  {
    lenLimit = this->_matchMaxLen;
  }
  cyclicBufferSize = this->_cyclicBufferSize;
  if ( pos <= cyclicBufferSize )
    matchMinPos = 0;
  else
    matchMinPos = pos - cyclicBufferSize;
  buffer = this->_buffer;
  v8 = buffer[pos];
  v9 = &buffer[pos];
  v10 = CCRC::Table[v8] ^ v9[1];
  v11 = v9[2];
  cur = v9;
  v12 = this->_hashMask & (v10 ^ (32 * (CCRC::Table[v9[3]] ^ (8 * v11))));
  maxLen = 1;
  v13 = v10 ^ ((_WORD)v11 << 8);
  v14 = v10;
  hash = this->_hash;
  v16 = v14 & 0x3FF;
  cyclicPos = hash[v12 + 66560];
  delta = hash[v16];
  curMatch3 = hash[v13 + 1024];
  hash[v16] = this->_pos;
  if ( delta > matchMinPos && this->_buffer[delta] == *cur )
  {
    distances[1] = 2;
    maxLen = 2;
    distances[2] = this->_pos - delta - 1;
    v17 = 3;
  }
  else
  {
    v17 = 1;
  }
  this->_hash[v13 + 1024] = this->_pos;
  if ( curMatch3 > matchMinPos && this->_buffer[curMatch3] == *cur )
  {
    if ( curMatch3 == delta )
      v17 -= 2;
    distances[v17] = 3;
    distances[v17 + 1] = this->_pos - curMatch3 - 1;
    maxLen = 3;
    v17 += 2;
    delta = curMatch3;
  }
  v18 = cyclicPos;
  if ( v17 != 1 && delta == cyclicPos )
  {
    v17 -= 2;
    maxLen = 1;
  }
  this->_hash[v12 + 66560] = this->_pos;
  son = this->_son;
  son[this->_cyclicBufferPos] = cyclicPos;
  cutValue = this->_cutValue;
  if ( cyclicPos > matchMinPos )
  {
    while ( 1 )
    {
      curMatch3a = cutValue - 1;
      if ( cutValue == 0 )
        break;
      cyclicBufferPos = this->_cyclicBufferPos;
      v21 = this->_pos - v18;
      deltaa = v21;
      v22 = v21 > cyclicBufferPos ? this->_cyclicBufferSize + cyclicBufferPos - v21 : cyclicBufferPos - v21;
      v23 = &this->_buffer[v18];
      cyclicPosa = v22;
      if ( v23[maxLen] == cur[maxLen] && *v23 == *cur )
      {
        v24 = 1;
        if ( lenLimit != 1 )
        {
          v25 = cur + 1;
          v26 = v23 - cur;
          for ( offset = v26; v25[v26] == *v25; v26 = offset )
          {
            ++v24;
            ++v25;
            if ( v24 == lenLimit )
              break;
          }
        }
        if ( maxLen < v24 )
        {
          distances[v17] = v24;
          distances[v17 + 1] = deltaa - 1;
          v17 += 2;
          maxLen = v24;
          if ( v24 == lenLimit )
            break;
        }
      }
      v18 = son[cyclicPosa];
      if ( v18 <= matchMinPos )
        break;
      cutValue = curMatch3a;
    }
  }
  *distances = v17 - 1;
  if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
    this->_cyclicBufferPos = 0;
  v27 = ++this->_pos;
  if ( v27 <= this->_posLimit )
    goto LABEL_43;
  if ( &this->_buffer[v27] > this->_pointerToLastSafePosition )
    CLZInWindow::MoveBlock(this: &this->CLZInWindow);
  result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
  if ( result == 0 )
  {
LABEL_43:
    if ( this->_pos == 0x7FFFFFFF )
      NHC4::CMatchFinder::Normalize(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100142E0
// Name: private: virtual long NHC4::CMatchFinder::Skip(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NHC4::CMatchFinder::Skip(NHC4::CMatchFinder *this, unsigned int num)
{
  unsigned int pos; // edi
  unsigned int v3; // eax
  HRESULT result; // eax
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int *v7; // ebx
  unsigned int v8; // ecx
  bool v9; // zf
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // edx
  unsigned __int8 *buffer; // ecx
  unsigned int v15; // eax
  int v16; // edx
  unsigned int v17; // ecx
  unsigned int *v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int cyclicBufferSize; // eax
  unsigned int hashSizeSum; // edi
  unsigned int *hash; // ebx
  unsigned int v24; // edi
  unsigned int v25; // eax
  unsigned int v26; // edx
  unsigned int v27; // edx

  do
  {
    pos = this->_pos;
    if ( this->_streamPos - pos >= 4 )
    {
      buffer = this->_buffer;
      v15 = CCRC::Table[buffer[pos]] ^ buffer[pos + 1];
      v16 = buffer[pos + 2];
      v17 = this->_hashMask & (v15 ^ (32 * (CCRC::Table[buffer[pos + 3]] ^ (8 * v16))));
      this->_hash[(unsigned __int16)(v15 ^ ((_WORD)v16 << 8)) + 1024] = pos;
      this->_hash[v15 & 0x3FF] = this->_pos;
      v18 = &this->_hash[v17 + 66560];
      v19 = *v18;
      *v18 = this->_pos;
      this->_son[this->_cyclicBufferPos++] = v19;
      if ( this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v20 = ++this->_pos;
      if ( v20 > this->_posLimit )
      {
        if ( &this->_buffer[v20] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        cyclicBufferSize = this->_cyclicBufferSize;
        hashSizeSum = this->_hashSizeSum;
        hash = this->_hash;
        v8 = 0x7FFFFFFF - cyclicBufferSize;
        v9 = cyclicBufferSize + hashSizeSum == 0;
        v24 = cyclicBufferSize + hashSizeSum;
        v25 = 0;
        if ( !v9 )
        {
          do
          {
            v26 = hash[v25];
            if ( v26 > v8 )
              v27 = v26 - v8;
            else
              v27 = 0;
            hash[v25++] = v27;
          }
          while ( v25 < v24 );
        }
        goto LABEL_27;
      }
    }
    else
    {
      if ( ++this->_cyclicBufferPos == this->_cyclicBufferSize )
        this->_cyclicBufferPos = 0;
      v3 = ++this->_pos;
      if ( v3 > this->_posLimit )
      {
        if ( &this->_buffer[v3] > this->_pointerToLastSafePosition )
          CLZInWindow::MoveBlock(this: &this->CLZInWindow);
        result = CLZInWindow::ReadBlock(this: &this->CLZInWindow);
        if ( result != 0 )
          return result;
      }
      if ( this->_pos == 0x7FFFFFFF )
      {
        v5 = this->_cyclicBufferSize;
        v6 = this->_hashSizeSum;
        v7 = this->_hash;
        v8 = 0x7FFFFFFF - v5;
        v9 = v5 + v6 == 0;
        v10 = v5 + v6;
        v11 = 0;
        if ( !v9 )
        {
          do
          {
            v12 = v7[v11];
            if ( v12 > v8 )
              v13 = v12 - v8;
            else
              v13 = 0;
            v7[v11++] = v13;
          }
          while ( v11 < v10 );
        }
LABEL_27:
        this->_buffer += v8;
        this->_posLimit -= v8;
        this->_pos -= v8;
        this->_streamPos -= v8;
      }
    }
    --num;
  }
  while ( num != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100144A0
// Name: public: void NCompress::NLZMA::CLiteralEncoder2::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CLiteralEncoder2::Encode(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned __int8 symbol)
{
  NCompress::NLZMA::CLiteralEncoder2 *v4; // edx
  int v5; // ebx
  int v6; // ecx
  int v7; // ecx
  int v8; // edi
  unsigned int Range; // ecx
  unsigned int v10; // eax
  int v11; // edi
  unsigned int v12; // eax
  int i; // [esp+18h] [ebp+8h]

  v4 = this;
  v5 = 1;
  v6 = 8;
  do
  {
    v7 = v6 - 1;
    v8 = symbol >> v7;
    i = v7;
    Range = rangeEncoder->Range;
    v10 = v4->_encoders[v5].Prob * (Range >> 11);
    v11 = v8 & 1;
    if ( v11 != 0 )
    {
      rangeEncoder->Low += v10;
      rangeEncoder->Range = Range - v10;
      v4->_encoders[v5].Prob -= v4->_encoders[v5].Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v10;
      v4->_encoders[v5].Prob += (2048 - v4->_encoders[v5].Prob) >> 5;
    }
    v12 = rangeEncoder->Range;
    if ( v12 < 0x1000000 )
    {
      rangeEncoder->Range = v12 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      v4 = this;
    }
    v6 = i;
    v5 = v11 | (2 * v5);
  }
  while ( i != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10014540
// Name: public: void NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(class NCompress::NRangeCoder::CEncoder __near *,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned __int8 matchByte,
        unsigned __int8 symbol)
{
  int v5; // edx
  int v6; // edx
  int v7; // ebx
  int v8; // edi
  unsigned int Range; // edx
  int v10; // ebx
  NCompress::NRangeCoder::CBitEncoder<5> *v11; // ecx
  unsigned int v12; // eax
  int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // eax
  int v17; // edi
  bool v18; // cf
  unsigned int v19; // ebx
  unsigned int v20; // eax
  unsigned int context; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  int ia; // [esp+1Ch] [ebp+8h]

  context = 1;
  v5 = 8;
  while ( 1 )
  {
    v6 = v5 - 1;
    v7 = matchByte >> v6;
    v8 = symbol >> v6;
    i = v6;
    Range = rangeEncoder->Range;
    v10 = v7 & 1;
    v11 = &this->_encoders[256 * v10 + 256 + context];
    v12 = v11->Prob * (Range >> 11);
    v13 = v8 & 1;
    if ( v13 != 0 )
    {
      rangeEncoder->Low += v12;
      rangeEncoder->Range = Range - v12;
      v11->Prob -= v11->Prob >> 5;
    }
    else
    {
      rangeEncoder->Range = v12;
      v11->Prob += (2048 - v11->Prob) >> 5;
    }
    v14 = rangeEncoder->Range;
    if ( v14 < 0x1000000 )
    {
      rangeEncoder->Range = v14 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    v5 = i;
    context = v13 | (2 * context);
    if ( v10 != v13 )
      break;
    if ( i == 0 )
      return;
  }
  if ( i != 0 )
  {
    do
    {
      --v5;
      v15 = context;
      v16 = this->_encoders[context].Prob * (rangeEncoder->Range >> 11);
      v17 = (symbol >> v5) & 1;
      ia = v5;
      if ( v17 != 0 )
      {
        v18 = __CFADD__(v16, rangeEncoder->Low);
        LODWORD(rangeEncoder->Low) += v16;
        v19 = rangeEncoder->Range;
        HIDWORD(rangeEncoder->Low) += v18;
        rangeEncoder->Range = v19 - v16;
        this->_encoders[context].Prob -= this->_encoders[context].Prob >> 5;
      }
      else
      {
        rangeEncoder->Range = v16;
        this->_encoders[context].Prob += (2048 - this->_encoders[context].Prob) >> 5;
      }
      v20 = rangeEncoder->Range;
      if ( v20 < 0x1000000 )
      {
        rangeEncoder->Range = v20 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
        v5 = ia;
        v15 = context;
      }
      context = v17 | (2 * v15);
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100146A0
// Name: public: unsigned int NCompress::NLZMA::CLiteralEncoder2::GetPrice(bool,unsigned char,unsigned char)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CLiteralEncoder2::GetPrice(
        NCompress::NLZMA::CLiteralEncoder2 *this,
        bool matchMode,
        unsigned __int8 matchByte,
        unsigned __int8 symbol)
{
  unsigned int result; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // edx
  int v8; // edx
  unsigned int price; // [esp+10h] [ebp-4h]

  result = 0;
  price = 0;
  v5 = 1;
  v6 = 8;
  if ( !matchMode )
    goto LABEL_9;
  do
  {
    v7 = (symbol >> --v6) & 1;
    result = NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v7
                                                              ^ (this->_encoders[256 * ((matchByte >> v6) & 1)
                                                                               + 256
                                                                               + v5].Prob
                                                               - v7)) >> 2)
                                                            & 0x1FF]
           + price;
    v5 = v7 | (2 * v5);
    price = result;
    if ( ((matchByte >> v6) & 1) != v7 )
      break;
  }
  while ( v6 != 0 );
  if ( v6 != 0 )
  {
LABEL_9:
    do
    {
      v8 = (symbol >> --v6) & 1;
      result += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v8 ^ (this->_encoders[v5].Prob - v8)) >> 2) & 0x1FF];
      v5 = v8 | (2 * v5);
    }
    while ( v6 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014770
// Name: public: void NCompress::NLZMA::NLength::CEncoder::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::Init(
        NCompress::NLZMA::NLength::CEncoder *this,
        unsigned int numPosStates)
{
  unsigned int v2; // esi
  NCompress::NRangeCoder::CBitEncoder<5> *v3; // eax

  v2 = numPosStates;
  this->_choice.Prob = 1024;
  this->_choice2.Prob = 1024;
  if ( numPosStates != 0 )
  {
    v3 = &this->_midCoder[0].Models[1];
    do
    {
      v3[-128].Prob = 1024;
      v3[-127].Prob = 1024;
      v3[-126].Prob = 1024;
      v3[-125].Prob = 1024;
      v3[-124].Prob = 1024;
      v3[-123].Prob = 1024;
      v3[-122].Prob = 1024;
      v3->Prob = 1024;
      v3[1].Prob = 1024;
      v3[2].Prob = 1024;
      v3[3].Prob = 1024;
      v3[4].Prob = 1024;
      v3[5].Prob = 1024;
      v3[6].Prob = 1024;
      v3 += 8;
      --v2;
    }
    while ( v2 != 0 );
  }
  memset32(&this->_highCoder.Models[1], 1024, 0xFFu);
}

//------------------------------------------------------------------------------
// Address: 0x100147F0
// Name: public: void NCompress::NLZMA::NLength::CEncoder::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::Encode(
        NCompress::NLZMA::NLength::CEncoder *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol,
        unsigned int posState)
{
  unsigned int v5; // eax
  unsigned int Range; // ecx
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // eax

  if ( symbol >= 8 )
  {
    Range = rangeEncoder->Range;
    v7 = this->_choice.Prob * (Range >> 11);
    rangeEncoder->Low += v7;
    rangeEncoder->Range = Range - v7;
    this->_choice.Prob -= this->_choice.Prob >> 5;
    v8 = rangeEncoder->Range;
    if ( v8 < 0x1000000 )
    {
      rangeEncoder->Range = v8 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    if ( symbol >= 0x10 )
    {
      v10 = rangeEncoder->Range;
      v11 = this->_choice2.Prob * (v10 >> 11);
      rangeEncoder->Low += v11;
      rangeEncoder->Range = v10 - v11;
      this->_choice2.Prob -= this->_choice2.Prob >> 5;
      v12 = rangeEncoder->Range;
      if ( v12 < 0x1000000 )
      {
        rangeEncoder->Range = v12 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      NCompress::NRangeCoder::CBitTreeEncoder<5,8>::Encode(this: &this->_highCoder, rangeEncoder, symbol: symbol - 16);
    }
    else
    {
      rangeEncoder->Range = this->_choice2.Prob * (rangeEncoder->Range >> 11);
      this->_choice2.Prob += (2048 - this->_choice2.Prob) >> 5;
      v9 = rangeEncoder->Range;
      if ( v9 < 0x1000000 )
      {
        rangeEncoder->Range = v9 << 8;
        NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
      }
      NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(
        this: &this->_midCoder[posState],
        rangeEncoder,
        symbol: symbol - 8);
    }
  }
  else
  {
    rangeEncoder->Range = this->_choice.Prob * (rangeEncoder->Range >> 11);
    this->_choice.Prob += (2048 - this->_choice.Prob) >> 5;
    v5 = rangeEncoder->Range;
    if ( v5 < 0x1000000 )
    {
      rangeEncoder->Range = v5 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: rangeEncoder);
    }
    NCompress::NRangeCoder::CBitTreeEncoder<5,3>::Encode(this: &this->_lowCoder[posState], rangeEncoder, symbol);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014940
// Name: public: void NCompress::NLZMA::NLength::CEncoder::SetPrices(unsigned int,unsigned int,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CEncoder::SetPrices(
        NCompress::NLZMA::NLength::CEncoder *this,
        unsigned int posState,
        unsigned int numSymbols,
        unsigned int *prices)
{
  unsigned int v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // edx
  int i; // edi
  char v8; // al
  unsigned int v9; // edx
  unsigned int v10; // edx
  int v11; // edi
  char v12; // al
  unsigned int v13; // edx
  unsigned int v14; // edx
  int v15; // edi
  char v16; // al
  unsigned int b1; // [esp+Ch] [ebp-Ch]
  unsigned int b0; // [esp+10h] [ebp-8h]
  unsigned int a0; // [esp+14h] [ebp-4h]
  unsigned int a0a; // [esp+14h] [ebp-4h]
  unsigned int posStatea; // [esp+20h] [ebp+8h]

  a0 = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_choice.Prob >> 2];
  v4 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_choice.Prob) >> 2];
  b0 = v4 + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_choice2.Prob >> 2];
  b1 = v4 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_choice2.Prob) >> 2];
  v5 = 0;
  while ( v5 < numSymbols )
  {
    v6 = v5 | 8;
    for ( i = 0;
          v6 != 1;
          i += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v8 & 1)
                                                                ^ (this->_lowCoder[posState].Models[v6].Prob - (v8 & 1))) >> 2)
                                                              & 0x1FF] )
    {
      v8 = v6;
      v6 >>= 1;
    }
    prices[v5++] = a0 + i;
    if ( v5 >= 8 )
    {
      if ( v5 >= 0x10 )
      {
LABEL_12:
        if ( v5 < numSymbols )
        {
          v13 = v5 - 16;
          posStatea = v5 - 16;
          do
          {
            v14 = v13 | 0x100;
            v15 = 0;
            do
            {
              v16 = v14;
              v14 >>= 1;
              v15 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v16 & 1)
                                                                      ^ (this->_highCoder.Models[v14].Prob - (v16 & 1))) >> 2)
                                                                    & 0x1FF];
            }
            while ( v14 != 1 );
            prices[v5++] = b1 + v15;
            v13 = ++posStatea;
          }
          while ( v5 < numSymbols );
        }
      }
      else
      {
        v9 = v5 - 8;
        a0a = v5 - 8;
        while ( v5 < numSymbols )
        {
          v10 = v9 | 8;
          v11 = 0;
          do
          {
            v12 = v10;
            v10 >>= 1;
            v11 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v12 & 1)
                                                                    ^ (this->_midCoder[posState].Models[v10].Prob
                                                                     - (v12 & 1))) >> 2)
                                                                  & 0x1FF];
          }
          while ( v10 != 1 );
          prices[v5++] = b0 + v11;
          v9 = ++a0a;
          if ( v5 >= 0x10 )
            goto LABEL_12;
        }
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014AC0
// Name: public: virtual long NCompress::NLZMA::CEncoder::SetCoderProperties(unsigned long const __near *,struct tagPROPVARIANT const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::SetCoderProperties(
        NCompress::NLZMA::CEncoder *this,
        const unsigned int *propIDs,
        const tagPROPVARIANT *properties,
        unsigned int numProperties)
{
  unsigned int v4; // eax
  unsigned int v6; // eax
  ISequentialInStream *MatchFinder; // eax
  bool v8; // zf
  unsigned int Lo32; // edx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int i; // [esp+Ch] [ebp-4h]
  ISequentialInStream *matchFinderIndexPrev; // [esp+20h] [ebp+10h]

  v4 = 0;
  i = 0;
  if ( numProperties != 0 )
  {
    while ( 2 )
    {
      switch ( propIDs[v4] )
      {
        case 0x400u:
          if ( properties->vt != 19 )
            return -2147024809;
          Lo32 = properties->decVal.Lo32;
          if ( Lo32 - 1 > 0x3FFFFFFF )
            return -2147024809;
          this->_numLiteralPosStateBits = Lo32;
          v10 = 0;
          v11 = 1;
          do
          {
            if ( Lo32 <= v11 )
              break;
            ++v10;
            v11 = __ROL4__(v11, 1);
          }
          while ( v10 < 0x1E );
          this->_alignPrices[15] = 2 * v10;
          goto LABEL_32;
        case 0x440u:
          if ( properties->vt != 19 )
            return -2147024809;
          v12 = properties->decVal.Lo32;
          if ( v12 > 4 )
            return -2147024809;
          this->_alignPriceCount = v12;
          this->_distTableSize = (1 << v12) - 1;
          goto LABEL_32;
        case 0x441u:
          if ( properties->vt != 19 )
            return -2147024809;
          v14 = properties->decVal.Lo32;
          if ( v14 > 8 )
            return -2147024809;
          this->_posStateMask = v14;
          goto LABEL_32;
        case 0x442u:
          if ( properties->vt != 19 )
            return -2147024809;
          v13 = properties->decVal.Lo32;
          if ( v13 > 4 )
            return -2147024809;
          this->_posStateBits = v13;
          goto LABEL_32;
        case 0x450u:
          if ( properties->vt != 19 )
            return -2147024809;
          v6 = properties->decVal.Lo32;
          if ( v6 - 5 > 0x10C )
            return -2147024809;
          this->_matchDistances[548] = v6;
          goto LABEL_32;
        case 0x451u:
          if ( properties->vt != 8 )
            return -2147024809;
          matchFinderIndexPrev = this->_inStream;
          MatchFinder = (ISequentialInStream *)NCompress::NLZMA::FindMatchFinder(s: properties->bstrVal);
          if ( (int)MatchFinder < 0 )
            return -2147024809;
          v8 = this->_optimum[4095].Backs[2] == 0;
          this->_inStream = MatchFinder;
          if ( !v8 && matchFinderIndexPrev != MatchFinder )
          {
            this->_numLiteralContextBits = -1;
            NCompress::NLZMA::CEncoder::ReleaseMatchFinder(this: (NCompress::NLZMA::CEncoder *)((char *)this - 8));
          }
          goto LABEL_32;
        case 0x452u:
          if ( properties->vt != 19 )
            return -2147024809;
          *(_DWORD *)&this->_finished = properties->decVal.Lo32;
          goto LABEL_32;
        case 0x470u:
          if ( properties->vt != 19 )
            return -2147024809;
          LOBYTE(this->_matchDistances[547]) = properties->decVal.Lo32 == 0;
          goto LABEL_32;
        case 0x490u:
          if ( properties->vt != 11 )
            return -2147024809;
          LOBYTE(this->_matchFinderCycles) = properties->iVal == -1;
LABEL_32:
          v4 = i + 1;
          ++properties;
          i = v4;
          if ( v4 >= numProperties )
            return 0;
          continue;
        default:
          return -2147024809;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014D50
// Name: public: virtual long NCompress::NLZMA::CEncoder::ReleaseOutStream(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::ReleaseOutStream(NCompress::NLZMA::CEncoder *this)
{
  unsigned int bufferSize; // eax

  bufferSize = this->_rangeEncoder.Stream._bufferSize;
  if ( bufferSize != 0 )
  {
    (*(void (__stdcall **)(unsigned int))(*(_DWORD *)bufferSize + 8))(a1: this->_rangeEncoder.Stream._bufferSize);
    this->_rangeEncoder.Stream._bufferSize = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014D80
// Name: public: long NCompress::NLZMA::CEncoder::Init(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Init(NCompress::NLZMA::CEncoder *this)
{
  NCompress::NRangeCoder::CBitEncoder<5> *isRepG0; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v3; // edi
  unsigned int v4; // edx
  NCompress::NRangeCoder::CBitEncoder<5> *v5; // eax
  int v6; // ecx
  int v7; // edx
  NCompress::NLZMA::CLiteralEncoder2 *v8; // edi
  bool v9; // zf
  NCompress::NRangeCoder::CBitEncoder<5> *v10; // edx
  NCompress::NRangeCoder::CBitEncoder<5> *v11; // edi
  int i; // [esp+Ch] [ebp-4h]
  int v14; // [esp+Ch] [ebp-4h]
  int v15; // [esp+Ch] [ebp-4h]

  *(_WORD *)&this->_state.Index = 0;
  this->_repDistances[0] = 0;
  this->_repDistances[1] = 0;
  this->_repDistances[2] = 0;
  this->_repDistances[3] = 0;
  COutBuffer::Init(this: &this->_rangeEncoder.Stream);
  this->_rangeEncoder.Low = 0;
  this->_rangeEncoder.Range = -1;
  this->_rangeEncoder._cacheSize = 1;
  this->_rangeEncoder._cache = 0;
  isRepG0 = this->_isRepG0;
  v3 = this->_isRep0Long[0];
  for ( i = 12; i != 0; --i )
  {
    v4 = 0;
    v5 = v3;
    do
    {
      v5[-240].Prob = 1024;
      v5->Prob = 1024;
      ++v4;
      ++v5;
    }
    while ( v4 <= this->_posStateMask );
    isRepG0[-12].Prob = 1024;
    isRepG0->Prob = 1024;
    isRepG0[12].Prob = 1024;
    isRepG0[24].Prob = 1024;
    ++isRepG0;
    v3 += 16;
  }
  v6 = this->_literalEncoder._numPrevBits + this->_literalEncoder._numPosBits;
  if ( 1 << v6 != 0 )
  {
    v7 = 0;
    v14 = 1 << v6;
    do
    {
      v8 = &this->_literalEncoder._coders[v7++];
      v9 = v14-- == 1;
      memset32(v8, 1024, 0x300u);
    }
    while ( !v9 );
  }
  v10 = &this->_posSlotEncoder[0].Models[1];
  v15 = 4;
  do
  {
    v11 = v10;
    v10 += 64;
    v9 = v15-- == 1;
    memset32(v11, 1024, 0x3Fu);
  }
  while ( !v9 );
  memset32(this->_posEncoders, 1024, 0x72u);
  NCompress::NLZMA::NLength::CEncoder::Init(this: &this->_lenEncoder, numPosStates: 1 << this->_posStateBits);
  NCompress::NLZMA::NLength::CEncoder::Init(this: &this->_repMatchLenEncoder, numPosStates: 1 << this->_posStateBits);
  this->_posAlignEncoder.Models[1].Prob = 1024;
  this->_posAlignEncoder.Models[2].Prob = 1024;
  this->_posAlignEncoder.Models[3].Prob = 1024;
  this->_posAlignEncoder.Models[4].Prob = 1024;
  this->_posAlignEncoder.Models[5].Prob = 1024;
  this->_posAlignEncoder.Models[6].Prob = 1024;
  this->_posAlignEncoder.Models[7].Prob = 1024;
  this->_posAlignEncoder.Models[8].Prob = 1024;
  this->_posAlignEncoder.Models[9].Prob = 1024;
  this->_posAlignEncoder.Models[10].Prob = 1024;
  this->_posAlignEncoder.Models[11].Prob = 1024;
  this->_posAlignEncoder.Models[12].Prob = 1024;
  this->_posAlignEncoder.Models[13].Prob = 1024;
  this->_posAlignEncoder.Models[14].Prob = 1024;
  this->_posAlignEncoder.Models[15].Prob = 1024;
  this->_longestMatchWasFound = false;
  this->_optimumEndIndex = 0;
  this->_optimumCurrentIndex = 0;
  this->_additionalOffset = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014F50
// Name: private: long NCompress::NLZMA::CEncoder::ReadMatchDistances(unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::ReadMatchDistances(
        NCompress::NLZMA::CEncoder *this,
        unsigned int *lenRes,
        unsigned int *numDistancePairs)
{
  unsigned int *matchDistances; // ebx
  HRESULT result; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax

  *lenRes = 0;
  matchDistances = this->_matchDistances;
  result = this->_matchFinder._p->GetMatches(this: this->_matchFinder._p, a2: this->_matchDistances);
  if ( result == 0 )
  {
    v6 = *matchDistances;
    *numDistancePairs = *matchDistances;
    if ( v6 != 0 )
    {
      v7 = *(&this->_literalEncoder._posMask + v6);
      *lenRes = v7;
      if ( v7 == this->_numFastBytes )
        *lenRes += this->_matchFinder._p->GetMatchLen(
                     this: this->_matchFinder._p,
                     a2: v7 - 1,
                     a3: this->_matchDistances[*numDistancePairs],
                     a4: 273 - v7);
    }
    ++this->_additionalOffset;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014FD0
// Name: private: long NCompress::NLZMA::CEncoder::GetOptimumFast(unsigned int,unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::GetOptimumFast(
        NCompress::NLZMA::CEncoder *this,
        unsigned int position,
        unsigned int *backRes,
        unsigned int *lenRes)
{
  NCompress::NLZMA::CEncoder *v4; // ebx
  bool v5; // zf
  unsigned int result; // eax
  unsigned int v7; // eax
  const unsigned __int8 *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  const unsigned __int8 *v11; // ecx
  unsigned int j; // eax
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  unsigned int *v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned int longestMatchLength; // eax
  unsigned int v20; // esi
  unsigned int v21; // edx
  unsigned int *repDistances; // esi
  const unsigned __int8 *v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int repLens[4]; // [esp+4h] [ebp-28h]
  unsigned int newDistance; // [esp+14h] [ebp-18h]
  unsigned int i; // [esp+18h] [ebp-14h]
  unsigned int numDistancePairs; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int numAvailableBytes; // [esp+20h] [ebp-Ch]
  unsigned int backMain; // [esp+24h] [ebp-8h]
  unsigned int lenMain; // [esp+28h] [ebp-4h] BYREF

  v4 = this;
  v5 = !this->_longestMatchWasFound;
  newDistance = (unsigned int)this;
  if ( v5 )
  {
    result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &lenMain, &numDistancePairs);
    if ( result != 0 )
      return result;
  }
  else
  {
    v7 = this->_numDistancePairs;
    lenMain = this->_longestMatchLength;
    numDistancePairs = v7;
    this->_longestMatchWasFound = false;
  }
  v8 = v4->_matchFinder._p->GetPointerToCurrentPos(this: v4->_matchFinder._p);
  v9 = v4->_matchFinder._p->GetNumAvailableBytes(this: v4->_matchFinder._p) + 1;
  numAvailableBytes = v9;
  if ( v9 <= 0x111 )
  {
    if ( v9 < 2 )
    {
      *backRes = -1;
      *lenRes = 1;
      return 0;
    }
  }
  else
  {
    numAvailableBytes = 273;
  }
  v10 = 0;
  i = 0;
  backMain = 0;
  while ( 1 )
  {
    v11 = &v8[-v4->_repDistances[v10] - 2];
    if ( *(v8 - 1) == *v11 && *v8 == v8[-v4->_repDistances[v10] - 1] )
      break;
    repLens[v10] = 0;
LABEL_19:
    if ( ++v10 >= 4 )
    {
      v14 = lenMain;
      if ( lenMain >= v4->_numFastBytes )
      {
        *backRes = v4->_matchDistances[numDistancePairs] + 4;
        result = v14 - 1;
        *lenRes = v14;
        if ( v14 == 1 )
          return result;
        goto LABEL_24;
      }
      backMain = 0;
      if ( lenMain >= 2 )
      {
        v15 = numDistancePairs;
        backMain = v4->_matchDistances[numDistancePairs];
        if ( numDistancePairs > 2 )
        {
          v16 = (unsigned int *)(&v4->_literalEncoder._numPosBits + numDistancePairs);
          do
          {
            if ( lenMain != *(v16 - 1) + 1 )
              break;
            if ( backMain >> 7 <= *v16 )
              break;
            v17 = *(v16 - 1);
            v16 -= 2;
            v15 -= 2;
            lenMain = v17;
            backMain = v16[2];
          }
          while ( v15 > 2 );
          v14 = lenMain;
        }
        if ( v14 == 2 && backMain >= 0x80 )
        {
          lenMain = 1;
          v14 = 1;
        }
      }
      v18 = repLens[i];
      if ( v18 >= 2 && (v18 + 1 >= v14 || v18 + 2 >= v14 && backMain > 0x200 || v18 + 3 >= v14 && backMain > 0x8000) )
      {
        *backRes = i;
        *lenRes = v18;
        result = v18 - 1;
        if ( result != 0 )
          goto LABEL_24;
        return result;
      }
      if ( v14 < 2 || numAvailableBytes <= 2 )
      {
        *backRes = -1;
        *lenRes = 1;
        return 0;
      }
      result = NCompress::NLZMA::CEncoder::ReadMatchDistances(
                 this: v4,
                 lenRes: &v4->_longestMatchLength,
                 numDistancePairs: &v4->_numDistancePairs);
      if ( result != 0 )
        return result;
      longestMatchLength = v4->_longestMatchLength;
      if ( longestMatchLength >= 2 )
      {
        v20 = v4->_matchDistances[v4->_numDistancePairs];
        newDistance = v20;
        if ( longestMatchLength >= lenMain && v20 < backMain )
          goto LABEL_56;
        if ( longestMatchLength == lenMain + 1 )
        {
          if ( v20 >> 7 <= backMain )
          {
LABEL_56:
            v4->_longestMatchWasFound = true;
            *backRes = -1;
            *lenRes = 1;
            return 0;
          }
          v20 = newDistance;
        }
        if ( longestMatchLength > lenMain + 1
          || longestMatchLength + 1 >= lenMain && lenMain >= 3 && backMain >> 7 > v20 )
        {
          goto LABEL_56;
        }
      }
      --numAvailableBytes;
      v21 = 0;
      i = 0;
      repDistances = v4->_repDistances;
      do
      {
        v23 = &v8[-*repDistances - 1];
        if ( v8[1] == v8[-*repDistances] && v8[2] == v23[2] )
        {
          v24 = 2;
          if ( numAvailableBytes > 2 )
          {
            do
            {
              if ( v8[v24] != v23[v24] )
                break;
              ++v24;
            }
            while ( v24 < numAvailableBytes );
            v21 = i;
          }
          if ( v24 + 1 >= lenMain )
            goto LABEL_56;
        }
        else
        {
          repLens[v21] = 0;
        }
        ++v21;
        ++repDistances;
        i = v21;
      }
      while ( v21 < 4 );
      *backRes = backMain + 4;
      v25 = lenMain;
      *lenRes = lenMain;
      result = v25 - 2;
      if ( result != 0 )
        goto LABEL_24;
      return 0;
    }
  }
  for ( j = 2; j < numAvailableBytes; ++j )
  {
    if ( v8[j - 1] != v11[j] )
      break;
  }
  v4 = (NCompress::NLZMA::CEncoder *)newDistance;
  if ( j < *(_DWORD *)(newDistance + 208512) )
  {
    v13 = backMain;
    repLens[v10] = j;
    if ( j > *(unsigned int *)((char *)repLens + v13) )
    {
      i = v10;
      backMain = 4 * v10;
    }
    goto LABEL_19;
  }
  *backRes = v10;
  *lenRes = j;
  result = j - 1;
  if ( result != 0 )
  {
LABEL_24:
    v4->_additionalOffset += result;
    return v4->_matchFinder._p->Skip(this: v4->_matchFinder._p, a2: result);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015360
// Name: private: void NCompress::NLZMA::CEncoder::FillDistancesPrices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::FillDistancesPrices(NCompress::NLZMA::CEncoder *this)
{
  NCompress::NLZMA::CEncoder *v1; // ebx
  unsigned int i; // esi
  int v3; // eax
  unsigned int *v4; // esi
  unsigned int *v5; // edx
  unsigned int v6; // edi
  unsigned int v7; // ecx
  unsigned int v8; // esi
  char v9; // al
  unsigned int j; // eax
  unsigned int v11; // eax
  _DWORD *v12; // esi
  int v13; // ecx
  unsigned int tempPrices[128]; // [esp+Ch] [ebp-210h] BYREF
  NCompress::NLZMA::CEncoder *v15; // [esp+20Ch] [ebp-10h]
  int v16; // [esp+210h] [ebp-Ch]
  char *v17; // [esp+214h] [ebp-8h]
  unsigned int *v18; // [esp+218h] [ebp-4h]

  v1 = this;
  v15 = this;
  for ( i = 4; i < 0x80; ++i )
  {
    v3 = (NCompress::NLZMA::g_FastPos[i] & 1 | 2) << ((NCompress::NLZMA::g_FastPos[i] >> 1) - 1);
    tempPrices[i] = NCompress::NRangeCoder::ReverseBitTreeGetPrice<5>(
                      Models: &v1->_posSlotEncoder[3].Models[v3 - NCompress::NLZMA::g_FastPos[i] + 63],
                      NumBitLevels: (NCompress::NLZMA::g_FastPos[i] >> 1) - 1,
                      symbol: i - v3);
  }
  v4 = &v1->_distancesPrices[0][2];
  v5 = v1->_posSlotPrices[0];
  v18 = &v1->_distancesPrices[0][2];
  v17 = (char *)((char *)tempPrices - (char *)v1 - 209564);
  v16 = 4;
  while ( 1 )
  {
    v6 = 0;
    if ( v1->_distTableSize != 0 )
    {
      do
      {
        v7 = v6 | 0x40;
        v8 = 0;
        if ( (v6 | 0x40) != 1 )
        {
          do
          {
            v9 = v7;
            v7 >>= 1;
            v8 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-(v9 & 1) ^ (v5[v7 - 10713] - (v9 & 1))) >> 2)
                                                                 & 0x1FF];
          }
          while ( v7 != 1 );
          v1 = v15;
        }
        v5[v6++] = v8;
      }
      while ( v6 < v1->_distTableSize );
      v4 = v18;
    }
    for ( j = 14; j < v1->_distTableSize; ++j )
      v5[j] += ((j >> 1) - 5) << 6;
    *(v4 - 2) = *v5;
    *(v4 - 1) = v5[1];
    *v4 = v5[2];
    v4[1] = v5[3];
    v11 = 4;
    v12 = v4 + 2;
    do
    {
      v13 = NCompress::NLZMA::g_FastPos[v11++];
      *v12 = *(_DWORD *)((char *)v12 + (_DWORD)v17) + v5[v13];
      ++v12;
    }
    while ( v11 < 0x80 );
    v18 += 128;
    v17 -= 512;
    v5 += 64;
    if ( --v16 == 0 )
      break;
    v4 = v18;
  }
  v1->_matchPriceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015530
// Name: private: void NCompress::NLZMA::CEncoder::FillAlignPrices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::FillAlignPrices(NCompress::NLZMA::CEncoder *this)
{
  unsigned int v1; // edi
  unsigned int v2; // esi
  int v3; // edx
  int v4; // eax
  unsigned int *alignPrices; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  v1 = 0;
  i = 0;
  alignPrices = this->_alignPrices;
  do
  {
    v2 = 0;
    v3 = 1;
    for ( j = 4; j != 0; --j )
    {
      v4 = v1 & 1;
      v2 += NCompress::NRangeCoder::CPriceTables::ProbPrices[((-v4 ^ (this->_posAlignEncoder.Models[v3].Prob - v4)) >> 2)
                                                           & 0x1FF];
      v1 >>= 1;
      v3 = v4 | (2 * v3);
    }
    v1 = i + 1;
    *alignPrices = v2;
    i = v1;
    ++alignPrices;
  }
  while ( v1 < 0x10 );
  this->_alignPriceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100155C0
// Name: public: void NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(
        NCompress::NLZMA::NLength::CPriceTableEncoder *this,
        unsigned int numPosStates)
{
  unsigned int v2; // esi
  unsigned int *counters; // edi
  unsigned int *v4; // ebx

  v2 = 0;
  if ( numPosStates != 0 )
  {
    counters = this->_counters;
    v4 = this->_prices[0];
    do
    {
      NCompress::NLZMA::NLength::CEncoder::SetPrices(this, posState: v2, numSymbols: this->_tableSize, prices: v4);
      *counters = this->_tableSize;
      ++v2;
      ++counters;
      v4 += 272;
    }
    while ( v2 < numPosStates );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015610
// Name: public: void NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(class NCompress::NRangeCoder::CEncoder __near *,unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(
        NCompress::NLZMA::NLength::CPriceTableEncoder *this,
        NCompress::NRangeCoder::CEncoder *rangeEncoder,
        unsigned int symbol,
        unsigned int posState,
        bool updatePrice)
{
  NCompress::NLZMA::NLength::CEncoder::Encode(this, rangeEncoder, symbol, posState);
  if ( updatePrice && this->_counters[posState]-- == 1 )
  {
    NCompress::NLZMA::NLength::CEncoder::SetPrices(
      this,
      posState,
      numSymbols: this->_tableSize,
      prices: this->_prices[posState]);
    this->_counters[posState] = this->_tableSize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015670
// Name: public: NBT3::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT3::CMatchFinder *__thiscall NBT3::CMatchFinder::CMatchFinder(NBT3::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT3::CMatchFinder_vtbl *)&NBT3::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT3::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT3::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100156A0
// Name: public: NBT4::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT4::CMatchFinder *__thiscall NBT4::CMatchFinder::CMatchFinder(NBT4::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT4::CMatchFinder_vtbl *)&NBT4::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT4::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT4::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100156D0
// Name: public: NHC4::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NHC4::CMatchFinder *__thiscall NHC4::CMatchFinder::CMatchFinder(NHC4::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NHC4::CMatchFinder_vtbl *)&NHC4::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NHC4::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NHC4::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10015700
// Name: public: NCompress::NLZMA::CEncoder::CEncoder(void)
// Source: json
//------------------------------------------------------------------------------
NCompress::NLZMA::CEncoder *__thiscall NCompress::NLZMA::CEncoder::CEncoder(NCompress::NLZMA::CEncoder *this)
{
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&ICompressSetOutStream::`vftable';
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&ICompressSetCoderProperties::`vftable';
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&ICompressWriteCoderProperties::`vftable';
  this->__m_RefCount = 0;
  this->ICompressCoder::IUnknown::__vftable = (NCompress::NLZMA::CEncoder_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressCoder'};
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetOutStream'};
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetCoderProperties'};
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressWriteCoderProperties'};
  this->_matchFinder._p = nullptr;
  this->_rangeEncoder.Stream._buffer = nullptr;
  this->_rangeEncoder.Stream._pos = 0;
  this->_rangeEncoder.Stream._stream._p = nullptr;
  this->_rangeEncoder.Stream._buffer2 = nullptr;
  this->_literalEncoder._coders = nullptr;
  this->_posStateMask = 3;
  this->_numLiteralContextBits = 3;
  this->_numFastBytes = 32;
  this->_distTableSize = 44;
  this->_posStateBits = 2;
  this->_numLiteralPosStateBits = 0;
  this->_dictionarySize = 0x400000;
  this->_dictionarySizePrev = -1;
  this->_numFastBytesPrev = -1;
  this->_matchFinderCycles = 0;
  this->_matchFinderIndex = 2;
  this->_writeEndMark = false;
  this->setMfPasses = nullptr;
  this->_fastMode = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100157D0
// Name: _IsEqualGUID
// Source: json
//------------------------------------------------------------------------------
int __cdecl IsEqualGUID(const _GUID *rguid1, const _GUID *rguid2)
{
  unsigned int v4; // eax

  v4 = 16;
  while ( rguid1->Data1 == rguid2->Data1 )
  {
    v4 -= 4;
    rguid2 = (const _GUID *)((char *)rguid2 + 4);
    rguid1 = (const _GUID *)((char *)rguid1 + 4);
    if ( v4 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015840
// Name: public: virtual long NCompress::NLZMA::CEncoder::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::QueryInterface(
        NCompress::NLZMA::CEncoder *this,
        const _GUID *iid,
        void **outObject)
{
  NCompress::NLZMA::CEncoder *v3; // eax

  if ( IsEqualGUID(rguid1: iid, rguid2: &IID_ICompressSetOutStream) != 0 )
  {
    v3 = this;
    if ( this != nullptr )
    {
      *outObject = &this->ICompressSetOutStream;
      this->AddRef(this);
      return 0;
    }
    goto LABEL_4;
  }
  if ( IsEqualGUID(rguid1: iid, rguid2: &IID_ICompressSetCoderProperties) != 0 )
  {
    v3 = this;
    if ( this != nullptr )
    {
      *outObject = &this->ICompressSetCoderProperties;
      this->AddRef(this);
      return 0;
    }
LABEL_4:
    *outObject = nullptr;
    v3->AddRef(this: v3);
    return 0;
  }
  if ( IsEqualGUID(rguid1: iid, rguid2: &IID_ICompressWriteCoderProperties) == 0 )
    return -2147467262;
  v3 = this;
  if ( this == nullptr )
    goto LABEL_4;
  *outObject = &this->ICompressWriteCoderProperties;
  this->AddRef(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015900
// Name: public: virtual unsigned long NCompress::NLZMA::CEncoder::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NCompress::NLZMA::CEncoder::AddRef(NCompress::NLZMA::CEncoder *this)
{
  unsigned int result; // eax

  result = this->__m_RefCount + 1;
  this->__m_RefCount = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015920
// Name: public: virtual unsigned long NCompress::NLZMA::CEncoder::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall NCompress::NLZMA::CEncoder::Release(NCompress::NLZMA::CEncoder *this)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = this->__m_RefCount-- == 1;
  result = this->__m_RefCount;
  if ( v1 )
  {
    ((void (__thiscall *)(NCompress::NLZMA::CEncoder *, int))this->dtr_CEncoder)(a1: this, a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100159D0
// Name: public: virtual NCompress::NLZMA::CEncoder::~CEncoder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::~CEncoder(NCompress::NLZMA::CEncoder *this)
{
  ISequentialOutStream *p; // edi
  IMatchFinder *v3; // esi

  this->ICompressCoder::IUnknown::__vftable = (NCompress::NLZMA::CEncoder_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressCoder'};
  this->ICompressSetOutStream::IUnknown::__vftable = (ICompressSetOutStream_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetOutStream'};
  this->ICompressSetCoderProperties::IUnknown::__vftable = (ICompressSetCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressSetCoderProperties'};
  this->ICompressWriteCoderProperties::IUnknown::__vftable = (ICompressWriteCoderProperties_vtbl *)&NCompress::NLZMA::CEncoder::`vftable'{for `ICompressWriteCoderProperties'};
  MyFree(address: this->_literalEncoder._coders);
  this->_literalEncoder._coders = nullptr;
  COutBuffer::Free(this: &this->_rangeEncoder.Stream);
  p = this->_rangeEncoder.Stream._stream._p;
  if ( p != nullptr )
    p->Release(this: this->_rangeEncoder.Stream._stream._p);
  v3 = this->_matchFinder._p;
  if ( v3 != nullptr )
    v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10015A70
// Name: private: long NCompress::NLZMA::CEncoder::GetOptimum(unsigned int,unsigned int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
HRESULT __userpurge NCompress::NLZMA::CEncoder::GetOptimum@<eax>(
        NCompress::NLZMA::CEncoder *this@<ecx>,
        IMatchFinder *a2@<esi>,
        unsigned int position,
        unsigned int *backRes,
        unsigned int *lenRes)
{
  unsigned int optimumCurrentIndex; // eax
  int v7; // ecx
  int v8; // edx
  char *v9; // ecx
  HRESULT result; // eax
  bool v11; // zf
  unsigned int v12; // edx
  const unsigned __int8 *v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // ecx
  const unsigned __int8 *v18; // edi
  unsigned int i; // ecx
  unsigned int v20; // eax
  bool v21; // cc
  unsigned int v22; // edi
  unsigned int numFastBytes; // ecx
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned __int8 v26; // cl
  unsigned __int8 v27; // dl
  unsigned __int8 Index; // cl
  unsigned int posStateMask; // edi
  unsigned __int8 v30; // dl
  int numPrevBits; // eax
  unsigned int v32; // edi
  int v33; // edx
  unsigned __int8 v34; // cl
  unsigned int v35; // esi
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  unsigned int *p_Price; // ecx
  unsigned int v40; // esi
  unsigned int PureRepPrice; // eax
  unsigned int v42; // eax
  unsigned int *v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // eax
  unsigned int *j; // esi
  unsigned int PosLenPrice; // eax
  unsigned int v50; // eax
  unsigned int v51; // edx
  HRESULT (__stdcall *GetMatches)(IMatchFinder *, unsigned int *); // eax
  unsigned int v53; // esi
  unsigned int v54; // edi
  unsigned int v55; // edx
  int v56; // esi
  char *v57; // eax
  char v58; // dl
  int v59; // ecx
  int v60; // ecx
  unsigned __int8 v61; // cl
  unsigned int v62; // edi
  unsigned __int8 v63; // cl
  NCompress::NLZMA::COptimal *v64; // edx
  unsigned int v65; // esi
  unsigned int v66; // ecx
  unsigned int v67; // edx
  unsigned int v68; // edx
  unsigned int v69; // esi
  unsigned int v70; // ecx
  const unsigned __int8 *v71; // edi
  unsigned __int8 v72; // al
  unsigned __int8 v73; // dl
  unsigned int v74; // esi
  int v75; // eax
  unsigned int v76; // edx
  unsigned int v77; // esi
  unsigned int v78; // eax
  unsigned int v79; // esi
  NCompress::NLZMA::COptimal *v80; // eax
  unsigned int v81; // ecx
  unsigned int v82; // ecx
  unsigned int v83; // eax
  unsigned int v84; // ecx
  unsigned int v85; // ecx
  unsigned int v86; // ecx
  unsigned int v87; // ecx
  unsigned int v88; // eax
  unsigned int v89; // edi
  unsigned int v90; // edx
  unsigned int v91; // ecx
  unsigned int v92; // edx
  unsigned int v93; // esi
  unsigned int v94; // ecx
  unsigned int v95; // edi
  unsigned int *v96; // ecx
  unsigned int v97; // ecx
  NCompress::NLZMA::COptimal *v98; // eax
  unsigned int v99; // eax
  unsigned int v100; // eax
  const unsigned __int8 *v101; // ecx
  unsigned int k; // edi
  unsigned int v103; // eax
  unsigned int *v104; // ecx
  unsigned int v105; // esi
  unsigned int v106; // eax
  unsigned int v107; // eax
  unsigned int *v108; // ecx
  unsigned int v109; // edx
  unsigned int v110; // eax
  unsigned int v111; // ecx
  const unsigned __int8 *v112; // edi
  unsigned int v113; // eax
  unsigned int v114; // ecx
  int v115; // eax
  unsigned int v116; // edi
  unsigned int v117; // eax
  unsigned int v118; // eax
  unsigned int v119; // edx
  unsigned int v120; // ecx
  _DWORD *v121; // edi
  unsigned int v122; // ecx
  NCompress::NLZMA::COptimal *v123; // eax
  unsigned int v124; // edx
  unsigned int v125; // ecx
  unsigned int v126; // edx
  int v127; // eax
  unsigned int v128; // edi
  unsigned int v129; // eax
  unsigned int *v130; // edx
  unsigned int v131; // eax
  unsigned int v132; // eax
  unsigned int v133; // ecx
  int v134; // esi
  unsigned int *v135; // edx
  unsigned int v136; // edi
  unsigned int v137; // eax
  unsigned int v138; // eax
  unsigned int v139; // eax
  unsigned int v140; // ecx
  unsigned int v141; // eax
  unsigned int v142; // esi
  const unsigned __int8 *v143; // eax
  unsigned int v144; // eax
  unsigned int v145; // esi
  int v146; // edx
  unsigned __int8 v147; // cl
  int v148; // edi
  unsigned int Prob; // edx
  unsigned int v150; // esi
  int v151; // edi
  int v152; // eax
  unsigned int v153; // eax
  unsigned int v154; // eax
  unsigned int v155; // edx
  unsigned int v156; // ecx
  _DWORD *v157; // esi
  unsigned int v158; // ecx
  NCompress::NLZMA::COptimal *v159; // eax
  unsigned int v160; // edx
  unsigned int v161; // edx
  unsigned int v162; // ecx
  unsigned int v163; // eax
  unsigned int v164; // eax
  unsigned int v165; // eax
  IMatchFinder *p; // [esp-10h] [ebp-98h]
  unsigned __int8 v167; // [esp-Ch] [ebp-94h]
  unsigned __int8 v168; // [esp-Ch] [ebp-94h]
  unsigned int repLens[4]; // [esp+4h] [ebp-84h]
  unsigned int v171; // [esp+14h] [ebp-74h]
  unsigned int v172; // [esp+18h] [ebp-70h]
  unsigned int curAndLenPrice; // [esp+1Ch] [ebp-6Ch]
  unsigned __int8 matchByte[4]; // [esp+20h] [ebp-68h]
  int currentByte; // [esp+24h] [ebp-64h]
  unsigned int reps[4]; // [esp+28h] [ebp-60h] BYREF
  unsigned int price; // [esp+38h] [ebp-50h]
  unsigned int backOffset; // [esp+3Ch] [ebp-4Ch]
  unsigned int v179; // [esp+40h] [ebp-48h]
  unsigned int newLen; // [esp+44h] [ebp-44h]
  unsigned int lenTest2; // [esp+48h] [ebp-40h]
  unsigned int repMatchPrice; // [esp+4Ch] [ebp-3Ch]
  const unsigned __int8 *data; // [esp+50h] [ebp-38h]
  unsigned int normalMatchPrice; // [esp+54h] [ebp-34h]
  unsigned int numDistancePairs; // [esp+58h] [ebp-30h] BYREF
  unsigned int posState; // [esp+5Ch] [ebp-2Ch]
  unsigned int curPrice; // [esp+60h] [ebp-28h]
  unsigned int startLen; // [esp+64h] [ebp-24h]
  unsigned int offs; // [esp+68h] [ebp-20h]
  unsigned int state; // [esp+6Ch] [ebp-1Ch] OVERLAPPED
  bool nextIsChar; // [esp+73h] [ebp-15h]
  unsigned int lenEnd; // [esp+74h] [ebp-14h]
  unsigned int cur; // [esp+78h] [ebp-10h]
  unsigned int posSlot; // [esp+7Ch] [ebp-Ch] BYREF
  unsigned int repIndex; // [esp+80h] [ebp-8h]
  unsigned int curBack; // [esp+84h] [ebp-4h]

  optimumCurrentIndex = this->_optimumCurrentIndex;
  if ( this->_optimumEndIndex != optimumCurrentIndex )
  {
    v7 = 5 * optimumCurrentIndex + 5;
    v8 = *((_DWORD *)&this->_state.Index + 2 * v7);
    v9 = (char *)this + 8 * v7;
    *lenRes = v8 - optimumCurrentIndex;
    *backRes = *((_DWORD *)v9 + 5);
    this->_optimumCurrentIndex = *((_DWORD *)v9 + 4);
    return 0;
  }
  v11 = !this->_longestMatchWasFound;
  this->_optimumEndIndex = 0;
  this->_optimumCurrentIndex = 0;
  if ( v11 )
  {
    result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &posSlot, &numDistancePairs);
    if ( result != 0 )
      return result;
  }
  else
  {
    v12 = this->_numDistancePairs;
    posSlot = this->_longestMatchLength;
    numDistancePairs = v12;
    this->_longestMatchWasFound = false;
  }
  v13 = this->_matchFinder._p->GetPointerToCurrentPos(this: this->_matchFinder._p) - 1;
  v14 = this->_matchFinder._p->GetNumAvailableBytes(this: this->_matchFinder._p) + 1;
  curBack = v14;
  if ( v14 < 2 )
  {
LABEL_8:
    *backRes = -1;
    *lenRes = 1;
    return 0;
  }
  if ( v14 > 0x111 )
    curBack = 273;
  v15 = 0;
  offs = 0;
  repIndex = 0;
  curPrice = 0;
  do
  {
    v16 = v15;
    v17 = this->_repDistances[v15];
    reps[v15] = v17;
    v18 = &v13[-v17 - 1];
    if ( *v13 == *v18 && v13[1] == v13[-v17] )
    {
      for ( i = 2; i < curBack; ++i )
      {
        if ( v13[i] != v18[i] )
          break;
      }
      v20 = curPrice;
      repLens[v16] = i;
      v21 = i <= *(unsigned int *)((char *)repLens + v20);
      v15 = repIndex;
      if ( !v21 )
      {
        offs = repIndex;
        curPrice = v16 * 4;
      }
    }
    else
    {
      repLens[v15] = 0;
    }
    repIndex = ++v15;
  }
  while ( v15 < 4 );
  v22 = repLens[offs];
  numFastBytes = this->_numFastBytes;
  normalMatchPrice = v22;
  if ( v22 >= numFastBytes )
  {
    *backRes = offs;
    *lenRes = v22;
    if ( v22 != 1 )
    {
      this->_additionalOffset += v22 - 1;
      return this->_matchFinder._p->Skip(this: this->_matchFinder._p, a2: v22 - 1);
    }
    return 0;
  }
  v24 = posSlot;
  if ( posSlot >= numFastBytes )
  {
    *backRes = this->_matchDistances[numDistancePairs] + 4;
    *lenRes = v24;
    v25 = v24 - 1;
    if ( v25 != 0 )
    {
      this->_additionalOffset += v25;
      return this->_matchFinder._p->Skip(this: this->_matchFinder._p, a2: v25);
    }
    return 0;
  }
  v26 = *v13;
  LOBYTE(curPrice) = *v13;
  v27 = v13[-reps[0] - 1];
  LOBYTE(posState) = v27;
  if ( posSlot < 2 && v26 != v27 && v22 < 2 )
    goto LABEL_8;
  Index = this->_state.Index;
  posStateMask = this->_posStateMask;
  v30 = curPrice;
  this->_optimum[0].State.Index = Index;
  numPrevBits = this->_literalEncoder._numPrevBits;
  v167 = v30;
  v32 = position & posStateMask;
  v33 = this->_previousByte >> (8 - numPrevBits);
  repMatchPrice = position & this->_literalEncoder._posMask;
  this->_optimum[1].Price = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[this->_state.Index][v32].Prob >> 2]
                          + NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                              this: &this->_literalEncoder._coders[(repMatchPrice << numPrevBits) + v33],
                              matchMode: Index >= 7u,
                              matchByte: posState,
                              symbol: v167);
  this->_optimum[1].BackPrev = -1;
  this->_optimum[1].Prev1IsChar = false;
  v34 = this->_state.Index;
  v35 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[v34][v32].Prob) >> 2]
      + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v34].Prob) >> 2];
  startLen = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[v34][v32].Prob) >> 2];
  repMatchPrice = v35;
  if ( (_BYTE)posState == (_BYTE)curPrice )
  {
    v36 = v35
        + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[v34].Prob >> 2]
        + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep0Long[v34][v32].Prob >> 2];
    if ( v36 < this->_optimum[1].Price )
    {
      this->_optimum[1].Price = v36;
      this->_optimum[1].BackPrev = 0;
      this->_optimum[1].Prev1IsChar = false;
    }
  }
  v37 = normalMatchPrice;
  if ( posSlot < normalMatchPrice )
  {
    lenEnd = normalMatchPrice;
  }
  else
  {
    v37 = posSlot;
    lenEnd = posSlot;
  }
  if ( v37 < 2 )
  {
    *backRes = this->_optimum[1].BackPrev;
    *lenRes = 1;
    return 0;
  }
  v38 = reps[0];
  this->_optimum[1].PosPrev = 0;
  this->_optimum[0].Backs[0] = v38;
  this->_optimum[0].Backs[1] = reps[1];
  this->_optimum[0].Backs[2] = reps[2];
  this->_optimum[0].Backs[3] = reps[3];
  p_Price = &this->_optimum[v37].Price;
  do
  {
    *p_Price = 0xFFFFFFF;
    --v37;
    p_Price -= 10;
  }
  while ( v37 >= 2 );
  for ( repIndex = 0; repIndex < 4; ++repIndex )
  {
    v40 = repLens[repIndex];
    if ( v40 >= 2 )
    {
      PureRepPrice = NCompress::NLZMA::CEncoder::GetPureRepPrice(this, repIndex, state: this->_state, posState: v32);
      v42 = repMatchPrice + PureRepPrice;
      curBack = (unsigned int)&this->_repMatchLenEncoder._highCoder.Models[272 * v32 + 254 + v40];
      v43 = &this->_optimum[v40].Price;
      do
      {
        v44 = v42 + *(_DWORD *)curBack;
        if ( v44 < *v43 )
        {
          *v43 = v44;
          v45 = repIndex;
          v43[1] = 0;
          v43[2] = v45;
          *((_BYTE *)v43 - 11) = 0;
        }
        curBack -= 4;
        --v40;
        v43 -= 10;
      }
      while ( v40 >= 2 );
    }
  }
  repMatchPrice = startLen
                + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep[this->_state.Index].Prob >> 2];
  if ( repLens[0] < 2 )
    v46 = 2;
  else
    v46 = repLens[0] + 1;
  state = v46;
  if ( v46 <= posSlot )
  {
    v47 = 0;
    posSlot = 0;
    if ( state > this->_matchDistances[1] )
    {
      do
        v47 += 2;
      while ( state > this->_matchDistances[v47 + 1] );
      posSlot = v47;
    }
    for ( j = &this->_optimum[state].Price; ; j += 10 )
    {
      normalMatchPrice = this->_matchDistances[posSlot + 2];
      PosLenPrice = NCompress::NLZMA::CEncoder::GetPosLenPrice(this, pos: normalMatchPrice, len: state, posState: v32);
      v50 = repMatchPrice + PosLenPrice;
      if ( v50 < *j )
      {
        v51 = normalMatchPrice + 4;
        *j = v50;
        j[1] = 0;
        j[2] = v51;
        *((_BYTE *)j - 11) = 0;
      }
      if ( state == this->_matchDistances[posSlot + 1] )
      {
        posSlot += 2;
        if ( posSlot == numDistancePairs )
          break;
      }
      ++state;
    }
  }
  cur = 1;
  if ( lenEnd == 1 )
  {
LABEL_193:
    *lenRes = NCompress::NLZMA::CEncoder::Backward(this, backRes, cur);
    return 0;
  }
  while ( 1 )
  {
    p = this->_matchFinder._p;
    GetMatches = p->GetMatches;
    v53 = 0;
    newLen = 0;
    result = GetMatches(this: p, a2: this->_matchDistances);
    if ( result != 0 )
      return result;
    v54 = this->_matchDistances[0];
    repMatchPrice = v54;
    if ( v54 != 0 )
    {
      v53 = *(&this->_literalEncoder._posMask + v54);
      newLen = v53;
      if ( v53 == this->_numFastBytes )
      {
        v53 += this->_matchFinder._p->GetMatchLen(
                 this: this->_matchFinder._p,
                 a2: v53 - 1,
                 a3: this->_matchDistances[v54],
                 a4: 273 - v53);
        newLen = v53;
      }
    }
    ++this->_additionalOffset;
    if ( v53 >= this->_numFastBytes )
    {
      this->_numDistancePairs = v54;
      this->_longestMatchLength = v53;
      this->_longestMatchWasFound = true;
      goto LABEL_193;
    }
    ++position;
    v55 = 5 * cur + 5;
    v56 = *((_DWORD *)&this->_state.Index + 2 * v55);
    v57 = (char *)this + 8 * v55;
    v58 = v57[1];
    if ( v58 != 0 )
    {
      --v56;
      if ( v57[2] != 0 )
      {
        v59 = this->_optimum[*((_DWORD *)v57 + 1)].State.Index;
        if ( *((_DWORD *)v57 + 2) >= 4u )
          v60 = kMatchNextStates_0[v59];
        else
          v60 = kRepNextStates_0[v59];
        v61 = kLiteralNextStates_0[v60];
      }
      else
      {
        v61 = kLiteralNextStates_0[this->_optimum[v56].State.Index];
      }
    }
    else
    {
      v61 = this->_optimum[v56].State.Index;
    }
    if ( v56 == cur - 1 )
    {
      if ( *((_DWORD *)v57 + 5) != 0 )
        LOBYTE(state) = kLiteralNextStates_0[v61];
      else
        LOBYTE(state) = kShortRepNextStates_0[v61];
    }
    else
    {
      if ( v58 != 0 && v57[2] != 0 )
      {
        v62 = *((_DWORD *)v57 + 2);
        v56 = *((_DWORD *)v57 + 1);
        v63 = kRepNextStates_0[v61];
        posSlot = v62;
      }
      else
      {
        posSlot = *((_DWORD *)v57 + 5);
        v62 = posSlot;
        if ( posSlot >= 4 )
          v63 = kMatchNextStates_0[v61];
        else
          v63 = kRepNextStates_0[v61];
      }
      LOBYTE(state) = v63;
      v64 = &this->_optimum[v56];
      if ( v62 >= 4 )
      {
        reps[1] = v64->Backs[0];
        v66 = v64->Backs[1];
        v67 = v64->Backs[2];
        reps[0] = v62 - 4;
        reps[2] = v66;
        reps[3] = v67;
      }
      else
      {
        v65 = 1;
        reps[0] = v64->Backs[v62];
        if ( v62 == 0 || (qmemcpy(&reps[1], v64->Backs, 4 * v62), v65 = posSlot + 1, posSlot + 1 < 4) )
          qmemcpy(&reps[v65], &v64->Backs[v65], 4 * (4 - v65));
      }
    }
    v68 = reps[1];
    v69 = reps[0];
    *v57 = state;
    v70 = reps[2];
    *((_DWORD *)v57 + 7) = v68;
    *((_DWORD *)v57 + 9) = reps[3];
    *((_DWORD *)v57 + 6) = v69;
    *((_DWORD *)v57 + 8) = v70;
    curPrice = *((_DWORD *)v57 + 3);
    v71 = (const unsigned __int8 *)(((int (__stdcall *)(IMatchFinder *, IMatchFinder *))this->_matchFinder._p->GetPointerToCurrentPos)(
                                      a1: this->_matchFinder._p,
                                      a2)
                                  - 1);
    v72 = *v71;
    v73 = v71[-v69 - 1];
    v74 = position & this->_posStateMask;
    matchByte[0] = v73;
    numDistancePairs = (unsigned __int8)state;
    curBack = v74 + 16 * (unsigned __int8)state;
    LOBYTE(currentByte) = v72;
    v75 = this->_literalEncoder._numPrevBits;
    v168 = v73;
    v76 = *(v71 - 1);
    posState = v74;
    v77 = (position & this->_literalEncoder._posMask) << v75;
    data = v71;
    v78 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
            this: &this->_literalEncoder._coders[v77 + (v76 >> (8 - v75))],
            matchMode: (unsigned __int8)state >= 7u,
            matchByte: v168,
            symbol: currentByte);
    v79 = curPrice + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[0][curBack].Prob >> 2] + v78;
    v80 = &this->_optimum[cur + 1];
    nextIsChar = false;
    if ( v79 < v80->Price )
    {
      v81 = cur;
      v80->Price = v79;
      v80->PosPrev = v81;
      v80->BackPrev = -1;
      v80->Prev1IsChar = false;
      nextIsChar = true;
    }
    normalMatchPrice = curPrice
                     + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][curBack].Prob) >> 2];
    v172 = normalMatchPrice
         + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[numDistancePairs].Prob) >> 2];
    if ( matchByte[0] == (_BYTE)currentByte && (v80->PosPrev >= cur || v80->BackPrev != 0) )
    {
      v82 = v172
          + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[numDistancePairs].Prob >> 2]
          + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep0Long[0][curBack].Prob >> 2];
      if ( v82 <= v80->Price )
      {
        v80->Price = v82;
        v80->PosPrev = cur;
        v80->BackPrev = 0;
        v80->Prev1IsChar = false;
        nextIsChar = true;
      }
    }
    a2 = this->_matchFinder._p;
    v83 = ((int (*)(void))a2->GetNumAvailableBytes)() + 1;
    curPrice = v83;
    if ( 4095 - cur < v83 )
    {
      v83 = 4095 - cur;
      curPrice = 4095 - cur;
    }
    offs = v83;
    if ( v83 >= 2 )
    {
      v84 = this->_numFastBytes;
      if ( v83 > v84 )
        offs = this->_numFastBytes;
      if ( !nextIsChar && matchByte[0] != (_BYTE)currentByte )
      {
        v85 = v84 + 1;
        if ( v83 >= v85 )
        {
          v83 = v85;
          curBack = v85;
        }
        else
        {
          curBack = v83;
        }
        v86 = 1;
        if ( v83 > 1 )
        {
          do
          {
            if ( v71[v86] != v71[v86 - 1 - reps[0]] )
              break;
            ++v86;
          }
          while ( v86 < curBack );
        }
        curBack = v86 - 1;
        if ( v86 - 1 >= 2 )
        {
          v87 = kLiteralNextStates_0[numDistancePairs];
          v88 = this->_posStateMask & (position + 1);
          lenTest2 = v87;
          v89 = v88 + 16 * v87;
          v90 = NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v87].Prob) >> 2];
          v91 = 2048 - this->_isMatch[0][v89].Prob;
          v179 = v89;
          v92 = v79 + NCompress::NRangeCoder::CPriceTables::ProbPrices[v91 >> 2] + v90;
          v93 = curBack + cur + 1;
          v94 = lenEnd;
          if ( lenEnd < v93 )
          {
            startLen = (unsigned int)&this->_optimum[lenEnd].Price;
            v95 = v93 - lenEnd;
            lenEnd = curBack + cur + 1;
            v96 = &this->_optimum[v94].Price;
            do
            {
              v96 += 10;
              --v95;
              *v96 = 0xFFFFFFF;
            }
            while ( v95 != 0 );
            v89 = v179;
          }
          v97 = v92
              + this->_repMatchLenEncoder._highCoder.Models[272 * v88 + 254 + curBack].Prob
              + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[lenTest2].Prob >> 2]
              + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][v89].Prob) >> 2];
          v98 = &this->_optimum[v93];
          if ( v97 < v98->Price )
          {
            v98->Price = v97;
            v98->PosPrev = cur + 1;
            v98->BackPrev = 0;
            *(_WORD *)&v98->Prev1IsChar = 1;
          }
        }
      }
      repIndex = 0;
      v99 = 0;
      startLen = 2;
      do
      {
        v100 = reps[v99] + 1;
        v101 = &data[-v100];
        lenTest2 = v100;
        if ( *data == data[-v100] && data[1] == v101[1] )
        {
          for ( k = 2; k < offs; ++k )
          {
            if ( data[k] != v101[k] )
              break;
          }
          if ( lenEnd < k + cur )
          {
            v103 = k + cur - lenEnd;
            v104 = &this->_optimum[lenEnd].Price;
            lenEnd = k + cur;
            do
            {
              v104 += 10;
              --v103;
              *v104 = 0xFFFFFFF;
            }
            while ( v103 != 0 );
          }
          v105 = k;
          v106 = NCompress::NLZMA::CEncoder::GetPureRepPrice(this, repIndex, (NCompress::NLZMA::CState)state, posState);
          v107 = v172 + v106;
          v171 = 272 * posState;
          curBack = (unsigned int)&this->_repMatchLenEncoder._highCoder.Models[272 * posState + 254 + k];
          price = v107;
          v108 = &this->_optimum[k + cur].Price;
          do
          {
            v109 = v107 + *(_DWORD *)curBack;
            if ( v109 < *v108 )
            {
              *v108 = v109;
              v108[1] = cur;
              v108[2] = repIndex;
              *((_BYTE *)v108 - 11) = 0;
            }
            curBack -= 4;
            --k;
            v108 -= 10;
          }
          while ( k >= 2 );
          if ( repIndex == 0 )
            startLen = v105 + 1;
          v110 = v105 + 1;
          v111 = v105 + 1 + this->_numFastBytes;
          if ( curPrice < v111 )
            v111 = curPrice;
          if ( v110 < v111 )
          {
            v112 = &data[v110 - lenTest2];
            do
            {
              if ( data[v110] != *v112 )
                break;
              ++v110;
              ++v112;
            }
            while ( v110 < v111 );
          }
          v179 = -1 - v105 + v110;
          if ( v179 >= 2 )
          {
            v113 = this->_posStateMask;
            posSlot = kRepNextStates_0[numDistancePairs];
            curAndLenPrice = NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isMatch[posSlot][(v105 + position) & v113].Prob >> 2];
            v114 = v113 & (v105 + position + 1);
            v115 = this->_literalEncoder._numPrevBits;
            posSlot = kLiteralNextStates_0[posSlot];
            v116 = this->_literalEncoder._posMask & (v105 + position);
            backOffset = v114;
            curBack = v114 + 16 * posSlot;
            v117 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                     this: &this->_literalEncoder._coders[(v116 << v115) + (data[v105 - 1] >> (8 - v115))],
                     matchMode: true,
                     matchByte: data[v105 - lenTest2],
                     symbol: data[v105]);
            v118 = price
                 + curAndLenPrice
                 + this->_repMatchLenEncoder._highCoder.Models[v105 + 254 + v171].Prob
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[posSlot].Prob) >> 2]
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][curBack].Prob) >> 2]
                 + v117;
            v119 = v105 + v179 + cur + 1;
            if ( lenEnd < v119 )
            {
              price = (unsigned int)&this->_optimum[lenEnd].Price;
              v120 = v119 - lenEnd;
              lenEnd = v105 + v179 + cur + 1;
              v121 = (_DWORD *)price;
              do
              {
                v121 += 10;
                --v120;
                *v121 = 0xFFFFFFF;
              }
              while ( v120 != 0 );
            }
            v122 = v118
                 + this->_repMatchLenEncoder._highCoder.Models[272 * backOffset + 254 + v179].Prob
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[posSlot].Prob >> 2]
                 + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][curBack].Prob) >> 2];
            v123 = &this->_optimum[v119];
            if ( v122 < v123->Price )
            {
              v123->Price = v122;
              v124 = v105 + cur + 1;
              v123->PosPrev2 = cur;
              v125 = repIndex;
              v123->PosPrev = v124;
              v123->BackPrev = 0;
              *(_WORD *)&v123->Prev1IsChar = 257;
              v123->BackPrev2 = v125;
            }
          }
        }
        v99 = repIndex + 1;
        repIndex = v99;
      }
      while ( v99 < 4 );
      v126 = newLen;
      if ( newLen > offs )
      {
        v127 = 0;
        v126 = offs;
        if ( offs > this->_matchDistances[1] )
        {
          do
            v127 += 2;
          while ( offs > this->_matchDistances[v127 + 1] );
        }
        this->_matchDistances[v127 + 1] = offs;
        repMatchPrice = v127 + 2;
      }
      v128 = startLen;
      if ( v126 >= startLen )
      {
        normalMatchPrice += NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRep[numDistancePairs].Prob >> 2];
        if ( lenEnd < v126 + cur )
        {
          v129 = v126 + cur - lenEnd;
          v130 = &this->_optimum[lenEnd].Price;
          lenEnd += v129;
          do
          {
            v130 += 10;
            --v129;
            *v130 = 0xFFFFFFF;
          }
          while ( v129 != 0 );
        }
        v131 = 0;
        offs = 0;
        if ( v128 > this->_matchDistances[1] )
        {
          do
            v131 += 2;
          while ( v128 > this->_matchDistances[v131 + 1] );
          offs = v131;
        }
        v132 = v131;
        v133 = this->_matchDistances[v132 + 2];
        startLen = v132 * 4;
        curBack = v133;
        if ( v133 >= 0x20000 )
        {
          if ( v133 >= 0x8000000 )
            v134 = NCompress::NLZMA::g_FastPos[v133 >> 26] + 52;
          else
            v134 = NCompress::NLZMA::g_FastPos[HIWORD(v133)] + 32;
        }
        else
        {
          v134 = NCompress::NLZMA::g_FastPos[v133 >> 6] + 12;
        }
        repIndex = v128 + 1;
        posState = (unsigned int)&this->_lenEncoder._highCoder.Models[272 * posState + 254 + v128];
        v135 = &this->_optimum[v128 + cur].Price;
        posSlot = v134;
        for ( newLen = (unsigned int)v135; ; v135 = (unsigned int *)newLen )
        {
          v136 = repIndex;
          v137 = repIndex - 3;
          if ( repIndex - 3 >= 4 )
            v137 = 3;
          if ( v133 >= 0x80 )
            v138 = this->_alignPrices[v133 & 0xF] + this->_posSlotPrices[v137][v134];
          else
            v138 = this->_distancesPrices[v137][v133];
          v139 = *(_DWORD *)posState + normalMatchPrice + v138;
          curAndLenPrice = v139;
          if ( v139 < *v135 )
          {
            *v135 = v139;
            v135[1] = cur;
            v135[2] = v133 + 4;
            *((_BYTE *)v135 - 11) = 0;
          }
          if ( v136 - 1 == *(unsigned int *)((char *)&this->_matchDistances[1] + startLen) )
          {
            v140 = curPrice;
            v141 = repIndex + this->_numFastBytes;
            backOffset = curBack + 1;
            v142 = repIndex;
            if ( curPrice >= v141 )
              v140 = v141;
            if ( repIndex < v140 )
            {
              v143 = &data[repIndex - (curBack + 1)];
              do
              {
                if ( data[v142] != *v143 )
                  break;
                ++v142;
                ++v143;
              }
              while ( v142 < v140 );
            }
            lenTest2 = -1 - (repIndex - 1) + v142;
            if ( lenTest2 >= 2 )
            {
              v144 = this->_posStateMask;
              v145 = position + repIndex - 1;
              v146 = kMatchNextStates_0[numDistancePairs];
              v147 = kLiteralNextStates_0[v146];
              v148 = v145 & v144;
              Prob = this->_isMatch[v146][v145 & v144].Prob;
              v179 = v147;
              price = NCompress::NRangeCoder::CPriceTables::ProbPrices[Prob >> 2];
              v150 = this->_literalEncoder._posMask & v145;
              v151 = v144 & (v148 + 1);
              v152 = this->_literalEncoder._numPrevBits;
              startLen = v151 + 16 * v147;
              v153 = NCompress::NLZMA::CLiteralEncoder2::GetPrice(
                       this: &this->_literalEncoder._coders[(v150 << v152) + (data[repIndex - 2] >> (8 - v152))],
                       matchMode: true,
                       matchByte: data[repIndex - backOffset - 1],
                       symbol: data[repIndex - 1]);
              v154 = curAndLenPrice
                   + price
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isMatch[0][startLen].Prob) >> 2]
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep[v179].Prob) >> 2]
                   + v153;
              v155 = lenTest2 + repIndex + cur;
              if ( lenEnd < v155 )
              {
                backOffset = (unsigned int)&this->_optimum[lenEnd].Price;
                v156 = v155 - lenEnd;
                lenEnd = lenTest2 + repIndex + cur;
                v157 = (_DWORD *)backOffset;
                do
                {
                  v157 += 10;
                  --v156;
                  *v157 = 0xFFFFFFF;
                }
                while ( v156 != 0 );
              }
              v158 = v154
                   + this->_repMatchLenEncoder._highCoder.Models[272 * v151 + 254 + lenTest2].Prob
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[this->_isRepG0[v179].Prob >> 2]
                   + NCompress::NRangeCoder::CPriceTables::ProbPrices[(2048 - this->_isRep0Long[0][startLen].Prob) >> 2];
              v159 = &this->_optimum[v155];
              if ( v158 < v159->Price )
              {
                v160 = repIndex;
                v159->Price = v158;
                v161 = cur + v160;
                v159->PosPrev2 = cur;
                v162 = curBack + 4;
                v159->PosPrev = v161;
                v159->BackPrev = 0;
                *(_WORD *)&v159->Prev1IsChar = 257;
                v159->BackPrev2 = v162;
              }
            }
            v163 = offs + 2;
            offs = v163;
            if ( v163 == repMatchPrice )
              break;
            startLen = 4 * v163;
            v164 = this->_matchDistances[v163 + 2];
            curBack = v164;
            if ( v164 >= 0x80 )
            {
              if ( v164 >= 0x20000 )
              {
                if ( v164 >= 0x8000000 )
                  v165 = NCompress::NLZMA::g_FastPos[v164 >> 26] + 52;
                else
                  v165 = NCompress::NLZMA::g_FastPos[HIWORD(v164)] + 32;
              }
              else
              {
                v165 = NCompress::NLZMA::g_FastPos[v164 >> 6] + 12;
              }
              posSlot = v165;
            }
          }
          newLen += 40;
          posState += 4;
          ++repIndex;
          v134 = posSlot;
          v133 = curBack;
        }
      }
    }
    if ( ++cur == lenEnd )
      goto LABEL_193;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016B10
// Name: private: void NCompress::NLZMA::CEncoder::WriteEndMarker(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NCompress::NLZMA::CEncoder::WriteEndMarker(NCompress::NLZMA::CEncoder *this, unsigned int posState)
{
  unsigned int Range; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v4; // edx
  int v5; // eax
  unsigned int v6; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v7; // eax
  unsigned int v8; // eax
  bool v10; // [esp+4h] [ebp-4h]

  if ( this->_writeEndMark )
  {
    Range = this->_rangeEncoder.Range;
    v4 = &this->_isMatch[this->_state.Index][posState];
    v5 = v4->Prob * (Range >> 11);
    this->_rangeEncoder.Low += (unsigned int)v5;
    this->_rangeEncoder.Range = Range - v5;
    v4->Prob -= v4->Prob >> 5;
    v6 = this->_rangeEncoder.Range;
    if ( v6 < 0x1000000 )
    {
      this->_rangeEncoder.Range = v6 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    v7 = &this->_isRep[this->_state.Index];
    this->_rangeEncoder.Range = v7->Prob * (this->_rangeEncoder.Range >> 11);
    v7->Prob += (2048 - v7->Prob) >> 5;
    v8 = this->_rangeEncoder.Range;
    if ( v8 < 0x1000000 )
    {
      this->_rangeEncoder.Range = v8 << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    this->_state.Index = kMatchNextStates_0[this->_state.Index];
    v10 = !this->_fastMode;
    NCompress::NLZMA::NLength::CEncoder::Encode(
      this: &this->_lenEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0,
      posState);
    if ( v10 && this->_lenEncoder._counters[posState]-- == 1 )
    {
      NCompress::NLZMA::NLength::CEncoder::SetPrices(
        this: &this->_lenEncoder,
        posState,
        numSymbols: this->_lenEncoder._tableSize,
        prices: this->_lenEncoder._prices[posState]);
      this->_lenEncoder._counters[posState] = this->_lenEncoder._tableSize;
    }
    NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
      this: this->_posSlotEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0x3Fu);
    NCompress::NRangeCoder::CEncoder::EncodeDirectBits(this: &this->_rangeEncoder, value: 0x3FFFFFFu, numTotalBits: 26);
    NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
      this: &this->_posAlignEncoder,
      rangeEncoder: &this->_rangeEncoder,
      symbol: 0xFu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016C60
// Name: public: NBT2::CMatchFinder::CMatchFinder(void)
// Source: json
//------------------------------------------------------------------------------
NBT2::CMatchFinder *__thiscall NBT2::CMatchFinder::CMatchFinder(NBT2::CMatchFinder *this)
{
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&CLZInWindow::`vftable';
  this->_bufferBase = nullptr;
  this->__m_RefCount = 0;
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&IMatchFinderSetNumPasses::`vftable';
  this->IMatchFinder::IInWindowStream::IUnknown::__vftable = (NBT2::CMatchFinder_vtbl *)&NBT2::CMatchFinder::`vftable'{for `IMatchFinder'};
  this->CLZInWindow::__vftable = (CLZInWindow_vtbl *)&NBT2::CMatchFinder::`vftable'{for `CLZInWindow'};
  this->IMatchFinderSetNumPasses::__vftable = (IMatchFinderSetNumPasses_vtbl *)&NBT2::CMatchFinder::`vftable'{for `IMatchFinderSetNumPasses'};
  this->_hash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016C90
// Name: public: long NCompress::NLZMA::CEncoder::Create(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Create(NCompress::NLZMA::CEncoder *this)
{
  HRESULT result; // eax
  NBT2::CMatchFinder *v3; // eax
  NBT3::CMatchFinder *v4; // eax
  IMatchFinderSetNumPasses *v5; // ecx
  NBT3::CMatchFinder *v6; // eax
  NBT4::CMatchFinder *v7; // eax
  NHC4::CMatchFinder *v8; // eax
  unsigned int dictionarySize; // ecx
  IMatchFinderSetNumPasses *setMfPasses; // ecx
  unsigned int numFastBytes; // edx

  if ( !COutBuffer::Create(this: &this->_rangeEncoder.Stream, bufferSize: 0x100000u) )
    return -2147024882;
  if ( this->_matchFinder._p == nullptr )
  {
    switch ( this->_matchFinderIndex )
    {
      case 0:
        v3 = (NBT2::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v3 == nullptr )
          goto LABEL_15;
        v4 = (NBT3::CMatchFinder *)NBT2::CMatchFinder::CMatchFinder(this: v3);
        goto LABEL_7;
      case 1:
        v6 = (NBT3::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v6 == nullptr )
          goto LABEL_15;
        v4 = NBT3::CMatchFinder::CMatchFinder(this: v6);
        goto LABEL_7;
      case 2:
        v7 = (NBT4::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v7 == nullptr )
          goto LABEL_15;
        v4 = (NBT3::CMatchFinder *)NBT4::CMatchFinder::CMatchFinder(this: v7);
        goto LABEL_7;
      case 3:
        v8 = (NHC4::CMatchFinder *)operator new(nSize: 0x5Cu);
        if ( v8 != nullptr )
        {
          v4 = (NBT3::CMatchFinder *)NHC4::CMatchFinder::CMatchFinder(this: v8);
LABEL_7:
          if ( v4 != nullptr )
          {
            v5 = &v4->IMatchFinderSetNumPasses;
            goto LABEL_17;
          }
        }
        else
        {
LABEL_15:
          v4 = nullptr;
        }
        v5 = nullptr;
LABEL_17:
        this->setMfPasses = v5;
        CMyComPtr<IMatchFinder>::operator=(this: &this->_matchFinder, p: v4);
LABEL_18:
        if ( this->_matchFinder._p != nullptr )
          break;
        return -2147024882;
      default:
        goto LABEL_18;
    }
  }
  if ( !NCompress::NLZMA::CLiteralEncoder::Create(
          this: &this->_literalEncoder,
          numPosBits: this->_numLiteralPosStateBits,
          numPrevBits: this->_numLiteralContextBits) )
    return -2147024882;
  dictionarySize = this->_dictionarySize;
  if ( dictionarySize != this->_dictionarySizePrev || this->_numFastBytesPrev != this->_numFastBytes )
  {
    result = this->_matchFinder._p->Create(
               this: this->_matchFinder._p,
               a2: dictionarySize,
               a3: 4096u,
               a4: this->_numFastBytes,
               a5: 274u);
    if ( result != 0 )
      return result;
    if ( this->_matchFinderCycles != 0 )
    {
      setMfPasses = this->setMfPasses;
      if ( setMfPasses != nullptr )
        setMfPasses->SetNumPasses(this: setMfPasses, a2: this->_matchFinderCycles);
    }
    numFastBytes = this->_numFastBytes;
    this->_dictionarySizePrev = this->_dictionarySize;
    this->_numFastBytesPrev = numFastBytes;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10016E10
// Name: private: long NCompress::NLZMA::CEncoder::Flush(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::Flush(NCompress::NLZMA::CEncoder *this, unsigned int nowPos)
{
  IMatchFinder *p; // eax

  p = this->_matchFinder._p;
  if ( p != nullptr && this->_needReleaseMFStream )
  {
    p->ReleaseStream(this: p);
    this->_needReleaseMFStream = false;
  }
  NCompress::NLZMA::CEncoder::WriteEndMarker(this, posState: nowPos & this->_posStateMask);
  NCompress::NRangeCoder::CEncoder::FlushData(this: &this->_rangeEncoder);
  return COutBuffer::Flush(this: &this->_rangeEncoder.Stream);
}

//------------------------------------------------------------------------------
// Address: 0x10016E70
// Name: public: long NCompress::NLZMA::CEncoder::SetStreams(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::SetStreams(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize)
{
  HRESULT result; // eax
  unsigned int v7; // edx

  this->_inStream = inStream;
  this->_finished = false;
  result = NCompress::NLZMA::CEncoder::Create(this);
  if ( result == 0 )
  {
    result = this->SetOutStream(this: &this->ICompressSetOutStream, a2: outStream);
    if ( result == 0 )
    {
      result = NCompress::NLZMA::CEncoder::Init(this);
      if ( result == 0 )
      {
        if ( !this->_fastMode )
        {
          NCompress::NLZMA::CEncoder::FillDistancesPrices(this);
          NCompress::NLZMA::CEncoder::FillAlignPrices(this);
        }
        this->_lenEncoder._tableSize = this->_numFastBytes - 1;
        NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(
          this: &this->_lenEncoder,
          numPosStates: 1 << this->_posStateBits);
        v7 = 1 << this->_posStateBits;
        this->_repMatchLenEncoder._tableSize = this->_numFastBytes - 1;
        NCompress::NLZMA::NLength::CPriceTableEncoder::UpdateTables(this: &this->_repMatchLenEncoder, numPosStates: v7);
        LODWORD(this->nowPos64) = 0;
        HIDWORD(this->nowPos64) = 0;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016F40
// Name: public: long NCompress::NLZMA::CEncoder::CodeOneBlock(unsigned __int64 __near *,unsigned __int64 __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NCompress::NLZMA::CEncoder::CodeOneBlock(
        NCompress::NLZMA::CEncoder *this,
        unsigned __int64 *inSize,
        unsigned __int64 *outSize,
        int *finished)
{
  ISequentialInStream *inStream; // ecx
  unsigned int result; // eax
  bool v7; // zf
  int v8; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v9; // eax
  unsigned int Range; // eax
  unsigned __int8 v11; // al
  unsigned __int8 previousByte; // dl
  unsigned __int8 v13; // bl
  NCompress::NLZMA::CLiteralEncoder2 *SubCoder; // eax
  bool v15; // cf
  unsigned int nowPos64; // edi
  unsigned int (__stdcall *GetNumAvailableBytes)(IInWindowStream *); // edx
  unsigned int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // eax
  unsigned __int8 v21; // al
  unsigned int v22; // edi
  unsigned int v23; // edx
  NCompress::NLZMA::CLiteralEncoder2 *v24; // edi
  unsigned __int8 v25; // dl
  unsigned int v26; // ebx
  NCompress::NRangeCoder::CBitEncoder<5> *v27; // edx
  unsigned int v28; // ecx
  int v29; // eax
  unsigned int v30; // eax
  int Index; // edx
  unsigned int v32; // ecx
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v36; // eax
  unsigned int v37; // eax
  int v38; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v39; // edx
  int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v43; // eax
  unsigned int v44; // eax
  NCompress::NRangeCoder::CBitEncoder<5> *v45; // edx
  int v46; // eax
  unsigned int v47; // eax
  unsigned int v48; // ebx
  unsigned int v49; // ecx
  NCompress::NRangeCoder::CBitEncoder<5> *v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // edx
  unsigned int v53; // eax
  unsigned int v54; // eax
  unsigned int v55; // eax
  unsigned int v56; // ebx
  unsigned int v57; // eax
  int v58; // eax
  unsigned int v59; // edx
  unsigned int v60; // eax
  unsigned int v61; // ecx
  unsigned int v62; // edx
  unsigned int additionalOffset; // eax
  unsigned int v64; // edi
  int v65; // edx
  unsigned __int8 v66; // [esp-Ch] [ebp-34h]
  IMatchFinder *p; // [esp-Ch] [ebp-34h]
  unsigned int numDistancePairs; // [esp+4h] [ebp-24h] BYREF
  unsigned int posReduced; // [esp+8h] [ebp-20h] BYREF
  int matchByte; // [esp+Ch] [ebp-1Ch]
  int curByte; // [esp+10h] [ebp-18h]
  unsigned int nowPos32; // [esp+14h] [ebp-14h]
  unsigned int posState; // [esp+18h] [ebp-10h]
  unsigned int lenRes; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned int pos; // [esp+20h] [ebp-8h] BYREF
  bool v76; // [esp+24h] [ebp-4h]

  inStream = this->_inStream;
  if ( inStream != nullptr )
  {
    result = this->_matchFinder._p->SetStream(this: this->_matchFinder._p, a2: inStream);
    if ( result != 0 )
      return result;
    result = this->_matchFinder._p->Init(this: this->_matchFinder._p);
    if ( result != 0 )
      return result;
    this->_needReleaseMFStream = true;
    this->_inStream = nullptr;
  }
  *finished = 1;
  if ( this->_finished )
    return 0;
  v8 = HIDWORD(this->nowPos64) | LODWORD(this->nowPos64);
  v7 = this->nowPos64 == 0;
  this->_finished = true;
  if ( !v7 )
    goto LABEL_14;
  if ( ((int (__thiscall *)(int, IMatchFinder *))this->_matchFinder._p->GetNumAvailableBytes)(
         a1: v8,
         a2: this->_matchFinder._p) == 0 )
    return NCompress::NLZMA::CEncoder::Flush(this, nowPos: this->nowPos64);
  result = NCompress::NLZMA::CEncoder::ReadMatchDistances(this, lenRes: &posReduced, &numDistancePairs);
  if ( result == 0 )
  {
    v9 = &this->_isMatch[this->_state.Index][this->nowPos64 & this->_posStateMask];
    this->_rangeEncoder.Range = v9->Prob * (this->_rangeEncoder.Range >> 11);
    v9->Prob += (2048 - v9->Prob) >> 5;
    Range = this->_rangeEncoder.Range;
    if ( Range < 0x1000000 )
    {
      this->_rangeEncoder.Range = Range << 8;
      NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
    }
    this->_state.Index = kLiteralNextStates_0[this->_state.Index];
    v11 = this->_matchFinder._p->GetIndexByte(this: this->_matchFinder._p, a2: -this->_additionalOffset);
    previousByte = this->_previousByte;
    v13 = v11;
    LOBYTE(curByte) = v11;
    v66 = v11;
    SubCoder = NCompress::NLZMA::CLiteralEncoder::GetSubCoder(
                 this: &this->_literalEncoder,
                 pos: this->nowPos64,
                 prevByte: previousByte);
    NCompress::NLZMA::CLiteralEncoder2::Encode(this: SubCoder, rangeEncoder: &this->_rangeEncoder, symbol: v66);
    --this->_additionalOffset;
    v15 = __CFADD__(LODWORD(this->nowPos64)++, 1);
    this->_previousByte = v13;
    HIDWORD(this->nowPos64) += v15;
LABEL_14:
    nowPos64 = this->nowPos64;
    GetNumAvailableBytes = this->_matchFinder._p->GetNumAvailableBytes;
    p = this->_matchFinder._p;
    nowPos32 = nowPos64;
    numDistancePairs = nowPos64;
    if ( GetNumAvailableBytes(this: p) != 0 )
    {
      if ( this->_rangeEncoder.Stream.ErrorCode != 0 )
      {
        return this->_rangeEncoder.Stream.ErrorCode;
      }
      else
      {
        while ( 1 )
        {
          result = this->_fastMode
                 ? NCompress::NLZMA::CEncoder::GetOptimumFast(this, position: nowPos64, backRes: &pos, &lenRes)
                 : NCompress::NLZMA::CEncoder::GetOptimum(
                     this,
                     a2: (IMatchFinder *)this,
                     position: nowPos64,
                     backRes: &pos,
                     &lenRes);
          if ( result != 0 )
            break;
          v18 = nowPos64 & this->_posStateMask;
          posState = v18;
          if ( lenRes == 1 && pos == -1 )
          {
            v19 = v18 + 16 * this->_state.Index;
            this->_rangeEncoder.Range = this->_isMatch[0][v19].Prob * (this->_rangeEncoder.Range >> 11);
            this->_isMatch[0][v19].Prob += (2048 - this->_isMatch[0][v19].Prob) >> 5;
            v20 = this->_rangeEncoder.Range;
            if ( v20 < 0x1000000 )
            {
              this->_rangeEncoder.Range = v20 << 8;
              NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
            }
            v21 = this->_matchFinder._p->GetIndexByte(this: this->_matchFinder._p, a2: -this->_additionalOffset);
            v22 = this->_previousByte;
            v23 = nowPos32 & this->_literalEncoder._posMask;
            LOBYTE(curByte) = v21;
            v24 = &this->_literalEncoder._coders[(v23 << this->_literalEncoder._numPrevBits)
                                               + (v22 >> (8 - this->_literalEncoder._numPrevBits))];
            if ( this->_state.Index >= 7u )
            {
              LOBYTE(matchByte) = this->_matchFinder._p->GetIndexByte(
                                    this: this->_matchFinder._p,
                                    a2: -1 - this->_repDistances[0] - this->_additionalOffset);
              NCompress::NLZMA::CLiteralEncoder2::EncodeMatched(
                this: v24,
                rangeEncoder: &this->_rangeEncoder,
                matchByte,
                symbol: curByte);
            }
            else
            {
              NCompress::NLZMA::CLiteralEncoder2::Encode(this: v24, rangeEncoder: &this->_rangeEncoder, symbol: curByte);
            }
            v25 = curByte;
            v26 = lenRes;
            this->_state.Index = kLiteralNextStates_0[this->_state.Index];
            this->_previousByte = v25;
          }
          else
          {
            v27 = &this->_isMatch[this->_state.Index][v18];
            v28 = this->_rangeEncoder.Range;
            v29 = v27->Prob * (v28 >> 11);
            v15 = __CFADD__(v29, this->_rangeEncoder.Low);
            LODWORD(this->_rangeEncoder.Low) += v29;
            HIDWORD(this->_rangeEncoder.Low) += v15;
            this->_rangeEncoder.Range = v28 - v29;
            v27->Prob -= v27->Prob >> 5;
            v30 = this->_rangeEncoder.Range;
            if ( v30 < 0x1000000 )
            {
              this->_rangeEncoder.Range = v30 << 8;
              NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
            }
            if ( pos >= 4 )
            {
              v50 = &this->_isRep[this->_state.Index];
              this->_rangeEncoder.Range = v50->Prob * (this->_rangeEncoder.Range >> 11);
              v50->Prob += (2048 - v50->Prob) >> 5;
              v51 = this->_rangeEncoder.Range;
              if ( v51 < 0x1000000 )
              {
                this->_rangeEncoder.Range = v51 << 8;
                NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
              }
              v52 = posState;
              v53 = lenRes;
              this->_state.Index = kMatchNextStates_0[this->_state.Index];
              v76 = !this->_fastMode;
              NCompress::NLZMA::NLength::CEncoder::Encode(
                this: &this->_lenEncoder,
                rangeEncoder: &this->_rangeEncoder,
                symbol: v53 - 2,
                posState: v52);
              if ( v76 )
              {
                v54 = posState;
                v7 = this->_lenEncoder._counters[posState]-- == 1;
                if ( v7 )
                {
                  NCompress::NLZMA::NLength::CEncoder::SetPrices(
                    this: &this->_lenEncoder,
                    posState: v54,
                    numSymbols: this->_lenEncoder._tableSize,
                    prices: this->_lenEncoder._prices[v54]);
                  this->_lenEncoder._counters[posState] = this->_lenEncoder._tableSize;
                }
              }
              v55 = pos - 4;
              pos = v55;
              if ( v55 >= 0x800 )
              {
                if ( v55 >= 0x200000 )
                  v56 = NCompress::NLZMA::g_FastPos[v55 >> 20] + 40;
                else
                  v56 = NCompress::NLZMA::g_FastPos[v55 >> 10] + 20;
              }
              else
              {
                v56 = NCompress::NLZMA::g_FastPos[v55];
              }
              v57 = lenRes - 2;
              if ( lenRes - 2 >= 4 )
                v57 = 3;
              NCompress::NRangeCoder::CBitTreeEncoder<5,6>::Encode(
                this: &this->_posSlotEncoder[v57],
                rangeEncoder: &this->_rangeEncoder,
                symbol: v56);
              if ( v56 >= 4 )
              {
                v58 = (v56 & 1 | 2) << ((v56 >> 1) - 1);
                posReduced = pos - v58;
                if ( v56 >= 0xE )
                {
                  NCompress::NRangeCoder::CEncoder::EncodeDirectBits(
                    this: &this->_rangeEncoder,
                    value: (pos - v58) >> 4,
                    numTotalBits: (v56 >> 1) - 5);
                  NCompress::NRangeCoder::CBitTreeEncoder<5,4>::ReverseEncode(
                    this: &this->_posAlignEncoder,
                    rangeEncoder: &this->_rangeEncoder,
                    symbol: posReduced & 0xF);
                  ++this->_alignPriceCount;
                }
                else
                {
                  NCompress::NRangeCoder::ReverseBitTreeEncode<5>(
                    Models: &this->_posSlotEncoder[3].Models[v58 - v56 + 63],
                    rangeEncoder: &this->_rangeEncoder,
                    NumBitLevels: (v56 >> 1) - 1,
                    symbol: pos - v58);
                }
              }
              v59 = this->_repDistances[2];
              v60 = this->_repDistances[1];
              v61 = this->_repDistances[0];
              ++this->_matchPriceCount;
              v26 = lenRes;
              this->_repDistances[3] = v59;
              v62 = pos;
              this->_repDistances[2] = v60;
              this->_repDistances[1] = v61;
              this->_repDistances[0] = v62;
            }
            else
            {
              Index = this->_state.Index;
              v32 = this->_rangeEncoder.Range;
              v33 = this->_isRep[Index].Prob * (v32 >> 11);
              v15 = __CFADD__(v33, this->_rangeEncoder.Low);
              LODWORD(this->_rangeEncoder.Low) += v33;
              HIDWORD(this->_rangeEncoder.Low) += v15;
              this->_rangeEncoder.Range = v32 - v33;
              this->_isRep[Index].Prob -= this->_isRep[Index].Prob >> 5;
              v34 = this->_rangeEncoder.Range;
              if ( v34 < 0x1000000 )
              {
                this->_rangeEncoder.Range = v34 << 8;
                NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
              }
              v35 = this->_rangeEncoder.Range;
              if ( pos != 0 )
              {
                v38 = this->_state.Index;
                posReduced = this->_repDistances[pos];
                v39 = &this->_isRepG0[v38];
                v40 = v39->Prob * (v35 >> 11);
                this->_rangeEncoder.Low += (unsigned int)v40;
                this->_rangeEncoder.Range = v35 - v40;
                v39->Prob -= v39->Prob >> 5;
                v41 = this->_rangeEncoder.Range;
                if ( v41 < 0x1000000 )
                {
                  this->_rangeEncoder.Range = v41 << 8;
                  NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                }
                v42 = this->_rangeEncoder.Range;
                if ( pos == 1 )
                {
                  v43 = &this->_isRepG1[this->_state.Index];
                  this->_rangeEncoder.Range = v43->Prob * (v42 >> 11);
                  v43->Prob += (2048 - v43->Prob) >> 5;
                  v44 = this->_rangeEncoder.Range;
                  if ( v44 < 0x1000000 )
                  {
                    this->_rangeEncoder.Range = v44 << 8;
                    NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                  }
                }
                else
                {
                  v45 = &this->_isRepG1[this->_state.Index];
                  v46 = v45->Prob * (v42 >> 11);
                  this->_rangeEncoder.Low += (unsigned int)v46;
                  this->_rangeEncoder.Range = v42 - v46;
                  v45->Prob -= v45->Prob >> 5;
                  v47 = this->_rangeEncoder.Range;
                  if ( v47 < 0x1000000 )
                  {
                    this->_rangeEncoder.Range = v47 << 8;
                    NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                  }
                  v48 = pos;
                  NCompress::NRangeCoder::CBitEncoder<5>::Encode(
                    this: &this->_isRepG2[this->_state.Index],
                    encoder: &this->_rangeEncoder,
                    symbol: pos - 2);
                  if ( v48 == 3 )
                    this->_repDistances[3] = this->_repDistances[2];
                  this->_repDistances[2] = this->_repDistances[1];
                }
                v49 = posReduced;
                v26 = lenRes;
                this->_repDistances[1] = this->_repDistances[0];
                this->_repDistances[0] = v49;
              }
              else
              {
                v36 = &this->_isRepG0[this->_state.Index];
                this->_rangeEncoder.Range = v36->Prob * (v35 >> 11);
                v36->Prob += (2048 - v36->Prob) >> 5;
                v37 = this->_rangeEncoder.Range;
                if ( v37 < 0x1000000 )
                {
                  this->_rangeEncoder.Range = v37 << 8;
                  NCompress::NRangeCoder::CEncoder::ShiftLow(this: &this->_rangeEncoder);
                }
                v26 = lenRes;
                NCompress::NRangeCoder::CBitEncoder<5>::Encode(
                  this: &this->_isRep0Long[this->_state.Index][posState],
                  encoder: &this->_rangeEncoder,
                  symbol: lenRes != 1);
              }
              if ( v26 == 1 )
              {
                this->_state.Index = kShortRepNextStates_0[this->_state.Index];
              }
              else
              {
                NCompress::NLZMA::NLength::CPriceTableEncoder::Encode(
                  this: &this->_repMatchLenEncoder,
                  rangeEncoder: &this->_rangeEncoder,
                  symbol: v26 - 2,
                  posState,
                  updatePrice: !this->_fastMode);
                this->_state.Index = kRepNextStates_0[this->_state.Index];
              }
            }
            this->_previousByte = this->_matchFinder._p->GetIndexByte(
                                    this: this->_matchFinder._p,
                                    a2: v26 - this->_additionalOffset - 1);
          }
          this->_additionalOffset -= v26;
          additionalOffset = this->_additionalOffset;
          nowPos64 = v26 + nowPos32;
          nowPos32 += v26;
          if ( additionalOffset == 0 )
          {
            if ( !this->_fastMode )
            {
              if ( this->_matchPriceCount >= 0x80 )
                NCompress::NLZMA::CEncoder::FillDistancesPrices(this);
              if ( this->_alignPriceCount >= 0x10 )
                NCompress::NLZMA::CEncoder::FillAlignPrices(this);
            }
            if ( this->_matchFinder._p->GetNumAvailableBytes(this: this->_matchFinder._p) == 0 )
              return NCompress::NLZMA::CEncoder::Flush(this, nowPos: nowPos64);
            if ( nowPos64 - numDistancePairs >= 0x4000 )
            {
              v64 = nowPos64 - numDistancePairs;
              v15 = __CFADD__(v64, this->nowPos64);
              LODWORD(this->nowPos64) += v64;
              v65 = this->nowPos64;
              HIDWORD(this->nowPos64) += v15;
              *(_DWORD *)inSize = v65;
              *((_DWORD *)inSize + 1) = HIDWORD(this->nowPos64);
              *outSize = NCompress::NRangeCoder::CEncoder::GetProcessedSize(this: &this->_rangeEncoder);
              this->_finished = false;
              *finished = 0;
              return 0;
            }
          }
          if ( this->_rangeEncoder.Stream.ErrorCode != 0 )
            return this->_rangeEncoder.Stream.ErrorCode;
          nowPos64 = nowPos32;
        }
      }
    }
    else
    {
      return NCompress::NLZMA::CEncoder::Flush(this, nowPos: nowPos64);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017740
// Name: public: long NCompress::NLZMA::CEncoder::CodeReal(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *,struct ICompressProgressInfo __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall NCompress::NLZMA::CEncoder::CodeReal(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize,
        ICompressProgressInfo *progress)
{
  HRESULT v7; // edi
  IMatchFinder *p; // eax
  unsigned int v10; // edi
  ICompressProgressInfo *v11; // ebx
  const unsigned __int64 *v12; // [esp-4h] [ebp-20h]
  unsigned __int64 processedInSize; // [esp+8h] [ebp-14h] BYREF
  unsigned __int64 processedOutSize; // [esp+10h] [ebp-Ch] BYREF
  NCompress::NLZMA::CEncoder::CCoderReleaser coderReleaser; // [esp+18h] [ebp-4h] BYREF

  v12 = outSize;
  this->_needReleaseMFStream = false;
  coderReleaser._coder = this;
  v7 = NCompress::NLZMA::CEncoder::SetStreams(this, inStream, outStream, inSize, outSize: v12);
  if ( v7 != 0 )
  {
    p = this->_matchFinder._p;
    if ( p != nullptr && this->_needReleaseMFStream )
    {
      p->ReleaseStream(this: this->_matchFinder._p);
      this->_needReleaseMFStream = false;
    }
    this->ReleaseOutStream(this: &this->ICompressSetOutStream);
    return v7;
  }
  else
  {
    v10 = NCompress::NLZMA::CEncoder::CodeOneBlock(
            this,
            inSize: &processedInSize,
            outSize: &processedOutSize,
            finished: (int *)&outSize);
    if ( v10 != 0 )
    {
LABEL_12:
      NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(this: &coderReleaser);
      return v10;
    }
    else
    {
      v11 = progress;
      while ( outSize == nullptr )
      {
        if ( v11 == nullptr || (v10 = v11->SetRatioInfo(this: v11, a2: &processedInSize, a3: &processedOutSize)) == 0 )
        {
          v10 = NCompress::NLZMA::CEncoder::CodeOneBlock(
                  this,
                  inSize: &processedInSize,
                  outSize: &processedOutSize,
                  finished: (int *)&outSize);
          if ( v10 == 0 )
            continue;
        }
        goto LABEL_12;
      }
      NCompress::NLZMA::CEncoder::CCoderReleaser::~CCoderReleaser(this: &coderReleaser);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017830
// Name: public: virtual long NCompress::NLZMA::CEncoder::Code(struct ISequentialInStream __near *,struct ISequentialOutStream __near *,unsigned __int64 const __near *,unsigned __int64 const __near *,struct ICompressProgressInfo __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall NCompress::NLZMA::CEncoder::Code(
        NCompress::NLZMA::CEncoder *this,
        ISequentialInStream *inStream,
        ISequentialOutStream *outStream,
        const unsigned __int64 *inSize,
        const unsigned __int64 *outSize,
        ICompressProgressInfo *progress)
{
  return NCompress::NLZMA::CEncoder::CodeReal(this, inStream, outStream, inSize, outSize, progress);
}

} // namespace shadercompile_dll
