// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/vbrheader.cpp
// Functions: 5
// ============================================================

#include "engine\audio\private\vbrheader.h"

//------------------------------------------------------------------------------
// Address: 0x100532C0
// Name: private: bool CVBRHeader::ExtractXINGHeader(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVBRHeader::ExtractXINGHeader(CVBRHeader *this, unsigned int dwOffset)
{
  CMPAFile *m_pMPAFile; // edi
  char v5; // bl
  int *v6; // eax
  unsigned int i; // edi

  m_pMPAFile = this->m_pMPAFile;
  if ( CMPAFile::ExtractBytes(this: m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true) != 1483304551
    && CMPAFile::ExtractBytes(this: m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true) != 1231971951 )
  {
    return 0;
  }
  v5 = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  if ( (v5 & 1) != 0 )
    this->m_dwFrames = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  if ( (v5 & 2) != 0 )
    this->m_dwBytes = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  if ( (v5 & 4) != 0 )
  {
    this->m_dwTableSize = 100;
    v6 = (int *)MemAlloc_Alloc(nSize: 0x190u);
    this->m_pnToc = v6;
    if ( v6 != nullptr )
    {
      for ( i = 0; i < this->m_dwTableSize; ++i )
        this->m_pnToc[i] = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 1, bMoveOffset: true);
    }
  }
  this->m_dwQuality = -1;
  if ( (v5 & 8) != 0 )
    this->m_dwQuality = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100533C0
// Name: private: bool CVBRHeader::ExtractVBRIHeader(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVBRHeader::ExtractVBRIHeader(CVBRHeader *this, unsigned int dwOffset)
{
  unsigned int v4; // eax
  CMPAFile *m_pMPAFile; // ecx
  double v6; // st7
  CMPAFile *v7; // ecx
  unsigned int v8; // eax
  CMPAFile *v9; // ecx
  unsigned int v10; // eax
  CMPAFile *v11; // ecx
  unsigned int v12; // eax
  CMPAFile *v13; // ecx
  unsigned int v14; // eax
  CMPAFile *v15; // ecx
  unsigned int v16; // eax
  CMPAFile *v17; // ecx
  unsigned int v18; // eax
  CMPAFile *v19; // ecx
  int *v20; // eax
  unsigned int i; // edi

  if ( CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true) != 1447187017 )
    return 0;
  v4 = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  m_pMPAFile = this->m_pMPAFile;
  this->m_dwVersion = v4;
  v6 = (double)CMPAFile::ExtractBytes(this: m_pMPAFile, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v7 = this->m_pMPAFile;
  this->m_fDelay = v6;
  v8 = CMPAFile::ExtractBytes(this: v7, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v9 = this->m_pMPAFile;
  this->m_dwQuality = v8;
  v10 = CMPAFile::ExtractBytes(this: v9, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  v11 = this->m_pMPAFile;
  this->m_dwBytes = v10;
  v12 = CMPAFile::ExtractBytes(this: v11, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  v13 = this->m_pMPAFile;
  this->m_dwFrames = v12;
  v14 = CMPAFile::ExtractBytes(this: v13, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v15 = this->m_pMPAFile;
  this->m_dwTableSize = v14 + 1;
  v16 = CMPAFile::ExtractBytes(this: v15, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v17 = this->m_pMPAFile;
  this->m_dwTableScale = v16;
  v18 = CMPAFile::ExtractBytes(this: v17, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v19 = this->m_pMPAFile;
  this->m_dwBytesPerEntry = v18;
  this->m_dwFramesPerEntry = CMPAFile::ExtractBytes(this: v19, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v20 = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)this->m_dwTableSize >> 30 != 0 ? -1 : 4 * this->m_dwTableSize);
  this->m_pnToc = v20;
  if ( v20 != nullptr )
  {
    for ( i = 0; i < this->m_dwTableSize; ++i )
      this->m_pnToc[i] = CMPAFile::ExtractBytes(
                           this: this->m_pMPAFile,
                           &dwOffset,
                           dwNumBytes: this->m_dwBytesPerEntry,
                           bMoveOffset: true);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10053500
// Name: public: CVBRHeader::~CVBRHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVBRHeader::~CVBRHeader(CVBRHeader *this)
{
  if ( this->m_pnToc != nullptr )
    free(pMem: this->m_pnToc);
}

//------------------------------------------------------------------------------
// Address: 0x10053510
// Name: public: static bool CVBRHeader::IsVBRHeaderAvailable(class CMPAFile __near *,enum CVBRHeader::VBRHeaderType __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CVBRHeader::IsVBRHeaderAvailable(
        unsigned int pMPAFile,
        CVBRHeader::VBRHeaderType *HeaderType,
        unsigned int *dwOffset)
{
  CMPAFile *v3; // esi
  unsigned int *v4; // edi
  char *v5; // edx
  char *v7; // eax

  v3 = (CMPAFile *)pMPAFile;
  v4 = dwOffset;
  pMPAFile = *dwOffset
           + CVBRHeader::m_dwXINGOffsets[**(unsigned __int8 **)(pMPAFile + 28)][*(_DWORD *)(*(_DWORD *)(pMPAFile + 28)
                                                                                          + 20) == 3];
  if ( CMPAFile::ExtractBytes(this: v3, dwOffset: &pMPAFile, dwNumBytes: 4, bMoveOffset: true) == 1483304551
    || CMPAFile::ExtractBytes(this: v3, dwOffset: &pMPAFile, dwNumBytes: 4, bMoveOffset: true) == 1231971951 )
  {
    v5 = (char *)(pMPAFile - 4);
    *HeaderType = XINGHeader;
    *v4 = (unsigned int)v5;
    return 1;
  }
  else
  {
    pMPAFile = *v4 + 36;
    if ( CMPAFile::ExtractBytes(this: v3, dwOffset: &pMPAFile, dwNumBytes: 4, bMoveOffset: true) == 1447187017 )
    {
      v7 = (char *)(pMPAFile - 4);
      *HeaderType = VBRIHeader;
      *v4 = (unsigned int)v7;
      return 1;
    }
    else
    {
      *HeaderType = NoHeader;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100535C0
// Name: public: CVBRHeader::CVBRHeader(class CMPAFile __near *,enum CVBRHeader::VBRHeaderType,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CVBRHeader *__thiscall CVBRHeader::CVBRHeader(
        CVBRHeader *this,
        CMPAFile *pMPAFile,
        CVBRHeader::VBRHeaderType HeaderType,
        unsigned int dwOffset)
{
  unsigned int m_dwBytes; // edi
  unsigned int m_dwFrames; // edx
  CMPAException v8; // [esp+Ch] [ebp-30h] BYREF
  CMPAException v9; // [esp+1Ch] [ebp-20h] BYREF
  CMPAException pExceptionObject; // [esp+2Ch] [ebp-10h] BYREF

  this->m_HeaderType = HeaderType;
  this->m_dwBytes = 0;
  this->m_dwFrames = 0;
  this->m_pMPAFile = pMPAFile;
  this->m_dwOffset = dwOffset;
  this->m_pnToc = nullptr;
  if ( HeaderType == NoHeader )
  {
    CMPAException::CMPAException(
      this: &v8,
      ErrorID: NoVBRHeader,
      szFile: pMPAFile->m_szFile,
      szFunction: nullptr,
      bGetLastError: false);
    _CxxThrowException(pExceptionObject: &v8, pThrowInfo: &_TI1_AVCMPAException__);
  }
  if ( HeaderType == XINGHeader )
  {
    if ( CVBRHeader::ExtractXINGHeader(this, dwOffset) == 0 )
    {
      CMPAException::CMPAException(
        this: &v9,
        ErrorID: NoVBRHeader,
        szFile: pMPAFile->m_szFile,
        szFunction: nullptr,
        bGetLastError: false);
      goto LABEL_8;
    }
  }
  else if ( HeaderType == VBRIHeader && CVBRHeader::ExtractVBRIHeader(this, dwOffset) == 0 )
  {
    CMPAException::CMPAException(
      this: &pExceptionObject,
      ErrorID: NoVBRHeader,
      szFile: pMPAFile->m_szFile,
      szFunction: nullptr,
      bGetLastError: false);
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVCMPAException__);
  }
  m_dwBytes = this->m_dwBytes;
  if ( m_dwBytes == 0 || (m_dwFrames = this->m_dwFrames) == 0 )
  {
    CMPAException::CMPAException(
      this: &v9,
      ErrorID: IncompleteVBRHeader,
      szFile: pMPAFile->m_szFile,
      szFunction: nullptr,
      bGetLastError: false);
LABEL_8:
    _CxxThrowException(pExceptionObject: &v9, pThrowInfo: &_TI1_AVCMPAException__);
  }
  this->m_dwBytesPerSec = m_dwBytes
                        / (m_dwFrames
                         * this->m_pMPAFile->m_pMPAHeader->m_dwSamplesPerFrame
                         / this->m_pMPAFile->m_pMPAHeader->m_dwSamplesPerSec);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10053070
// Name: private: bool CVBRHeader::ExtractXINGHeader(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVBRHeader::ExtractXINGHeader(CVBRHeader *this, unsigned int dwOffset)
{
  CMPAFile *m_pMPAFile; // edi
  char v5; // bl
  int *v6; // eax
  unsigned int i; // edi

  m_pMPAFile = this->m_pMPAFile;
  if ( CMPAFile::ExtractBytes(this: m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true) != 1483304551
    && CMPAFile::ExtractBytes(this: m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true) != 1231971951 )
  {
    return 0;
  }
  v5 = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  if ( (v5 & 1) != 0 )
    this->m_dwFrames = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  if ( (v5 & 2) != 0 )
    this->m_dwBytes = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  if ( (v5 & 4) != 0 )
  {
    this->m_dwTableSize = 100;
    v6 = (int *)MemAlloc_Alloc(nSize: 0x190u);
    this->m_pnToc = v6;
    if ( v6 != nullptr )
    {
      for ( i = 0; i < this->m_dwTableSize; ++i )
        this->m_pnToc[i] = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 1, bMoveOffset: true);
    }
  }
  this->m_dwQuality = -1;
  if ( (v5 & 8) != 0 )
    this->m_dwQuality = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10053170
// Name: private: bool CVBRHeader::ExtractVBRIHeader(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVBRHeader::ExtractVBRIHeader(CVBRHeader *this, unsigned int dwOffset)
{
  unsigned int v4; // eax
  CMPAFile *m_pMPAFile; // ecx
  double v6; // st7
  CMPAFile *v7; // ecx
  unsigned int v8; // eax
  CMPAFile *v9; // ecx
  unsigned int v10; // eax
  CMPAFile *v11; // ecx
  unsigned int v12; // eax
  CMPAFile *v13; // ecx
  unsigned int v14; // eax
  CMPAFile *v15; // ecx
  unsigned int v16; // eax
  CMPAFile *v17; // ecx
  unsigned int v18; // eax
  CMPAFile *v19; // ecx
  int *v20; // eax
  unsigned int i; // edi

  if ( CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 4, bMoveOffset: true) != 1447187017 )
    return 0;
  v4 = CMPAFile::ExtractBytes(this: this->m_pMPAFile, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  m_pMPAFile = this->m_pMPAFile;
  this->m_dwVersion = v4;
  v6 = (double)CMPAFile::ExtractBytes(this: m_pMPAFile, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v7 = this->m_pMPAFile;
  this->m_fDelay = v6;
  v8 = CMPAFile::ExtractBytes(this: v7, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v9 = this->m_pMPAFile;
  this->m_dwQuality = v8;
  v10 = CMPAFile::ExtractBytes(this: v9, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  v11 = this->m_pMPAFile;
  this->m_dwBytes = v10;
  v12 = CMPAFile::ExtractBytes(this: v11, &dwOffset, dwNumBytes: 4, bMoveOffset: true);
  v13 = this->m_pMPAFile;
  this->m_dwFrames = v12;
  v14 = CMPAFile::ExtractBytes(this: v13, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v15 = this->m_pMPAFile;
  this->m_dwTableSize = v14 + 1;
  v16 = CMPAFile::ExtractBytes(this: v15, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v17 = this->m_pMPAFile;
  this->m_dwTableScale = v16;
  v18 = CMPAFile::ExtractBytes(this: v17, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v19 = this->m_pMPAFile;
  this->m_dwBytesPerEntry = v18;
  this->m_dwFramesPerEntry = CMPAFile::ExtractBytes(this: v19, &dwOffset, dwNumBytes: 2, bMoveOffset: true);
  v20 = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)this->m_dwTableSize >> 30 != 0 ? -1 : 4 * this->m_dwTableSize);
  this->m_pnToc = v20;
  if ( v20 != nullptr )
  {
    for ( i = 0; i < this->m_dwTableSize; ++i )
      this->m_pnToc[i] = CMPAFile::ExtractBytes(
                           this: this->m_pMPAFile,
                           &dwOffset,
                           dwNumBytes: this->m_dwBytesPerEntry,
                           bMoveOffset: true);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100532B0
// Name: public: CVBRHeader::~CVBRHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVBRHeader::~CVBRHeader(CVBRHeader *this)
{
  if ( this->m_pnToc != nullptr )
    free(pMem: this->m_pnToc);
}

//------------------------------------------------------------------------------
// Address: 0x10053370
// Name: public: CVBRHeader::CVBRHeader(class CMPAFile __near *,enum CVBRHeader::VBRHeaderType,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CVBRHeader *__thiscall CVBRHeader::CVBRHeader(
        CVBRHeader *this,
        CMPAFile *pMPAFile,
        CVBRHeader::VBRHeaderType HeaderType,
        unsigned int dwOffset)
{
  unsigned int m_dwBytes; // edi
  unsigned int m_dwFrames; // edx
  CMPAException v8; // [esp+Ch] [ebp-30h] BYREF
  CMPAException v9; // [esp+1Ch] [ebp-20h] BYREF
  CMPAException pExceptionObject; // [esp+2Ch] [ebp-10h] BYREF

  this->m_HeaderType = HeaderType;
  this->m_dwBytes = 0;
  this->m_dwFrames = 0;
  this->m_pMPAFile = pMPAFile;
  this->m_dwOffset = dwOffset;
  this->m_pnToc = nullptr;
  if ( HeaderType == NoHeader )
  {
    CMPAException::CMPAException(
      this: &v8,
      ErrorID: NoVBRHeader,
      szFile: pMPAFile->m_szFile,
      szFunction: nullptr,
      bGetLastError: false);
    _CxxThrowException(pExceptionObject: &v8, pThrowInfo: &_TI1_AVCMPAException__);
  }
  if ( HeaderType == XINGHeader )
  {
    if ( CVBRHeader::ExtractXINGHeader(this, dwOffset) == 0 )
    {
      CMPAException::CMPAException(
        this: &v9,
        ErrorID: NoVBRHeader,
        szFile: pMPAFile->m_szFile,
        szFunction: nullptr,
        bGetLastError: false);
      goto LABEL_8;
    }
  }
  else if ( HeaderType == VBRIHeader && CVBRHeader::ExtractVBRIHeader(this, dwOffset) == 0 )
  {
    CMPAException::CMPAException(
      this: &pExceptionObject,
      ErrorID: NoVBRHeader,
      szFile: pMPAFile->m_szFile,
      szFunction: nullptr,
      bGetLastError: false);
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVCMPAException__);
  }
  m_dwBytes = this->m_dwBytes;
  if ( m_dwBytes == 0 || (m_dwFrames = this->m_dwFrames) == 0 )
  {
    CMPAException::CMPAException(
      this: &v9,
      ErrorID: IncompleteVBRHeader,
      szFile: pMPAFile->m_szFile,
      szFunction: nullptr,
      bGetLastError: false);
LABEL_8:
    _CxxThrowException(pExceptionObject: &v9, pThrowInfo: &_TI1_AVCMPAException__);
  }
  this->m_dwBytesPerSec = m_dwBytes
                        / (m_dwFrames
                         * this->m_pMPAFile->m_pMPAHeader->m_dwSamplesPerFrame
                         / this->m_pMPAFile->m_pMPAHeader->m_dwSamplesPerSec);
  return this;
}

} // namespace engine_xlsp
