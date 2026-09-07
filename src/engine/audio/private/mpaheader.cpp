// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/mpaheader.cpp
// Functions: 4
// ============================================================

#include "engine\audio\private\mpaheader.h"

//------------------------------------------------------------------------------
// Address: 0x100054C0
// Name: public: CMPAHeader::CMPAHeader(class CMPAFile __near *,unsigned int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100055C0
// Name: private: enum CMPAHeader::HeaderError CMPAHeader::DecodeHeader(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMPAHeader::DecodeHeader(CMPAHeader *this, unsigned int dwHeader, bool bSimpleDecode)
{
  CMPAHeader::MPAVersion v3; // eax
  CMPAHeader::MPALayer v5; // edi
  int v6; // ebx
  unsigned int v7; // edx
  unsigned int v8; // edi

  if ( (dwHeader & 0xFF000000) != 0xFF000000 || (BYTE2(dwHeader) & 0xE0) != 0xE0 )
    return 1;
  v3 = (dwHeader >> 19) & 3;
  this->m_Version = v3;
  if ( v3 == MPEGReserved )
    return 3;
  this->m_bLSF = v3 != MPEG1;
  v5 = 3 - ((dwHeader >> 17) & 3);
  this->m_Layer = v5;
  if ( v5 == LayerReserved )
    return 3;
  this->m_bCRC = (dwHeader & 0x10000) == 0;
  if ( ((dwHeader >> 12) & 0xF) == 0xF )
    return 3;
  v6 = v5 + 2 * this->m_bLSF + this->m_bLSF;
  v7 = 1000 * CMPAHeader::m_dwBitrates[0][v6][(unsigned __int16)dwHeader >> 12];
  this->m_dwBitrate = v7;
  if ( v7 == 0 )
    return 2;
  if ( ((dwHeader >> 10) & 3) == 3 )
    return 3;
  this->m_dwSamplesPerSec = CMPAHeader::m_dwSamplingRates[v3][(dwHeader >> 10) & 3];
  v8 = ((dwHeader & 0x200) != 0) * CMPAHeader::m_dwPaddingSizes[v5];
  this->m_dwPaddingSize = v8;
  this->m_dwComputedFrameSize = v8 + this->m_dwBitrate * CMPAHeader::m_dwCoefficients[v6] / this->m_dwSamplesPerSec;
  this->m_dwSamplesPerFrame = CMPAHeader::m_dwSamplesPerFrames[v6];
  if ( bSimpleDecode )
    return 0;
  this->m_bPrivate = BYTE1(dwHeader) & 1;
  this->m_ChannelMode = (unsigned __int8)dwHeader >> 6;
  this->m_ModeExt = (dwHeader >> 4) & 3;
  this->m_bCopyright = (dwHeader & 4) != 0;
  this->m_Emphasis = dwHeader & 3;
  if ( (dwHeader & 3) == 2 )
    return 3;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10005730
// Name: private: enum CMPAHeader::HeaderError CMPAHeader::IsSync(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMPAHeader::IsSync(CMPAHeader *this, unsigned int dwOffset, CMPAHeader::HeaderError bExtended)
{
  int v4; // edi
  unsigned int v5; // eax
  int v7; // [esp+0h] [ebp-60h] BYREF
  CMPAHeader m_SubsequentFrame; // [esp+Ch] [ebp-54h] BYREF
  CMPAHeader *v9; // [esp+4Ch] [ebp-14h]
  int *v10; // [esp+50h] [ebp-10h]
  int v11; // [esp+5Ch] [ebp-4h]

  v10 = &v7;
  v9 = this;
  v4 = 1;
  v5 = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: false);
  if ( (v5 & 0xFFE00000) == 0xFFE00000 )
  {
    v4 = CMPAHeader::DecodeHeader(this, dwHeader: v5, bSimpleDecode: false);
    if ( v4 == 0 && (_BYTE)bExtended != noError )
    {
      bExtended = this->m_dwSyncOffset + this->m_dwComputedFrameSize;
      v11 = 0;
      CMPAHeader::CMPAHeader(
        this: &m_SubsequentFrame,
        pMPAFile: this->m_pMPAFile,
        dwExpectedOffset: bExtended,
        bSubsequentFrame: true,
        bReverse: false);
      this->m_dwRealFrameSize = m_SubsequentFrame.m_dwSyncOffset - this->m_dwSyncOffset;
      v11 = -1;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10005840
// Name: public: bool CMPAHeader::SkipEmptyFrames(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMPAHeader::SkipEmptyFrames(CMPAHeader *this)
{
  unsigned int Bytes; // eax
  _DWORD v4[7]; // [esp+0h] [ebp-1Ch] BYREF

  v4[3] = v4;
  if ( this->m_dwBitrate > 0x20 )
    return 0;
  v4[6] = 0;
  while ( this->m_dwBitrate <= 0x20 )
  {
    this->m_dwSyncOffset += this->m_dwComputedFrameSize + 4;
    Bytes = CMPAFile::ExtractBytes(
              this: this->m_pMPAFile,
              dwOffset: &this->m_dwSyncOffset,
              dwNumBytes: 4,
              bMoveOffset: false);
    if ( CMPAHeader::IsSync(this, dwOffset: Bytes, bExtended: noError) != 0 )
      return 0;
  }
  return 1;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100054B0
// Name: public: CMPAHeader::CMPAHeader(class CMPAFile __near *,unsigned int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CMPAHeader *__thiscall CMPAHeader::CMPAHeader(
        CMPAHeader *this,
        CMPAFile *pMPAFile,
        unsigned int dwExpectedOffset,
        bool bSubsequentFrame,
        bool bReverse)
{
  unsigned int v7; // ebx
  signed int v8; // ecx
  CMPAFile *v9; // eax
  bool v11; // [esp-4h] [ebp-24h]
  CMPAException pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  bool bExtended[4]; // [esp+1Ch] [ebp-4h]
  unsigned int dwExpectedOffseta; // [esp+2Ch] [ebp+Ch]

  this->m_pMPAFile = pMPAFile;
  this->m_dwSyncOffset = dwExpectedOffset;
  this->m_dwRealFrameSize = 0;
  v7 = 1;
  bExtended[0] = !bSubsequentFrame;
  if ( CMPAHeader::IsSync(this, dwOffset: dwExpectedOffset, bExtended: !bSubsequentFrame) != noError )
  {
    dwExpectedOffseta = dwExpectedOffset - 1;
    while ( 1 )
    {
      if ( bSubsequentFrame )
      {
        if ( v7 > 3 )
        {
          CMPAException::CMPAException(
            this: &pExceptionObject,
            ErrorID: NoFrameInTolerance,
            szFile: pMPAFile->m_szFile,
            szFunction: nullptr,
            bGetLastError: false);
          _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVCMPAException__);
        }
        if ( this->m_dwSyncOffset > dwExpectedOffset )
        {
          v8 = dwExpectedOffseta;
          ++v7;
          --dwExpectedOffseta;
        }
        else
        {
          v8 = v7 + dwExpectedOffset;
        }
      }
      else
      {
        v8 = this->m_dwSyncOffset + 2 * !bReverse - 1;
      }
      v9 = pMPAFile;
      if ( v8 < 0 || v8 > (signed int)(pMPAFile->m_dwEnd - pMPAFile->m_dwBegin - 4) )
        goto LABEL_16;
      if ( abs32(v8 - dwExpectedOffset) > 0x40000 )
        break;
      v11 = bExtended[0];
      this->m_dwSyncOffset = v8;
      if ( CMPAHeader::IsSync(this, dwOffset: v8, bExtended: v11) == noError )
        return this;
    }
    v9 = pMPAFile;
LABEL_16:
    CMPAException::CMPAException(
      this: &pExceptionObject,
      ErrorID: NoFrame,
      szFile: v9->m_szFile,
      szFunction: nullptr,
      bGetLastError: false);
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVCMPAException__);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100055B0
// Name: private: enum CMPAHeader::HeaderError CMPAHeader::DecodeHeader(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMPAHeader::DecodeHeader(CMPAHeader *this, unsigned int dwHeader, bool bSimpleDecode)
{
  CMPAHeader::MPAVersion v3; // eax
  CMPAHeader::MPALayer v5; // edi
  int v6; // ebx
  unsigned int v7; // edx
  unsigned int v8; // edi

  if ( (dwHeader & 0xFF000000) != 0xFF000000 || (BYTE2(dwHeader) & 0xE0) != 0xE0 )
    return 1;
  v3 = (dwHeader >> 19) & 3;
  this->m_Version = v3;
  if ( v3 == MPEGReserved )
    return 3;
  this->m_bLSF = v3 != MPEG1;
  v5 = 3 - ((dwHeader >> 17) & 3);
  this->m_Layer = v5;
  if ( v5 == LayerReserved )
    return 3;
  this->m_bCRC = (dwHeader & 0x10000) == 0;
  if ( ((dwHeader >> 12) & 0xF) == 0xF )
    return 3;
  v6 = v5 + 2 * this->m_bLSF + this->m_bLSF;
  v7 = 1000 * CMPAHeader::m_dwBitrates[0][v6][(unsigned __int16)dwHeader >> 12];
  this->m_dwBitrate = v7;
  if ( v7 == 0 )
    return 2;
  if ( ((dwHeader >> 10) & 3) == 3 )
    return 3;
  this->m_dwSamplesPerSec = CMPAHeader::m_dwSamplingRates[v3][(dwHeader >> 10) & 3];
  v8 = ((dwHeader & 0x200) != 0) * CMPAHeader::m_dwPaddingSizes[v5];
  this->m_dwPaddingSize = v8;
  this->m_dwComputedFrameSize = v8 + this->m_dwBitrate * CMPAHeader::m_dwCoefficients[v6] / this->m_dwSamplesPerSec;
  this->m_dwSamplesPerFrame = CMPAHeader::m_dwSamplesPerFrames[v6];
  if ( bSimpleDecode )
    return 0;
  this->m_bPrivate = BYTE1(dwHeader) & 1;
  this->m_ChannelMode = (unsigned __int8)dwHeader >> 6;
  this->m_ModeExt = (dwHeader >> 4) & 3;
  this->m_bCopyright = (dwHeader & 4) != 0;
  this->m_Emphasis = dwHeader & 3;
  if ( (dwHeader & 3) == 2 )
    return 3;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10005720
// Name: private: enum CMPAHeader::HeaderError CMPAHeader::IsSync(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMPAHeader::IsSync(CMPAHeader *this, unsigned int dwOffset, CMPAHeader::HeaderError bExtended)
{
  int v4; // edi
  unsigned int v5; // eax
  int v7; // [esp+0h] [ebp-60h] BYREF
  CMPAHeader m_SubsequentFrame; // [esp+Ch] [ebp-54h] BYREF
  CMPAHeader *v9; // [esp+4Ch] [ebp-14h]
  int *v10; // [esp+50h] [ebp-10h]
  int v11; // [esp+5Ch] [ebp-4h]

  v10 = &v7;
  v9 = this;
  v4 = 1;
  v5 = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: false);
  if ( (v5 & 0xFFE00000) == 0xFFE00000 )
  {
    v4 = CMPAHeader::DecodeHeader(this, dwHeader: v5, bSimpleDecode: false);
    if ( v4 == 0 && (_BYTE)bExtended != noError )
    {
      bExtended = this->m_dwSyncOffset + this->m_dwComputedFrameSize;
      v11 = 0;
      CMPAHeader::CMPAHeader(
        this: &m_SubsequentFrame,
        pMPAFile: this->m_pMPAFile,
        dwExpectedOffset: bExtended,
        bSubsequentFrame: true,
        bReverse: false);
      this->m_dwRealFrameSize = m_SubsequentFrame.m_dwSyncOffset - this->m_dwSyncOffset;
      v11 = -1;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10005830
// Name: public: bool CMPAHeader::SkipEmptyFrames(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMPAHeader::SkipEmptyFrames(CMPAHeader *this)
{
  unsigned int Bytes; // eax
  _DWORD v4[7]; // [esp+0h] [ebp-1Ch] BYREF

  v4[3] = v4;
  if ( this->m_dwBitrate > 0x20 )
    return 0;
  v4[6] = 0;
  while ( this->m_dwBitrate <= 0x20 )
  {
    this->m_dwSyncOffset += this->m_dwComputedFrameSize + 4;
    Bytes = CMPAFile::ExtractBytes(
              this: this->m_pMPAFile,
              dwOffset: &this->m_dwSyncOffset,
              dwNumBytes: 4,
              bMoveOffset: false);
    if ( CMPAHeader::IsSync(this, dwOffset: Bytes, bExtended: noError) != 0 )
      return 0;
  }
  return 1;
}

} // namespace engine_xlsp
