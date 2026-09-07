// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/mpafile.cpp
// Functions: 10
// ============================================================

#include "engine\audio\private\mpafile.h"

//------------------------------------------------------------------------------
// Address: 0x10003EF0
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003F40
// Name: public: CMPAException::CMPAException(enum CMPAException::ErrorIDs,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMPAException *__thiscall CMPAException::CMPAException(
        CMPAException *this,
        CMPAException::ErrorIDs ErrorID,
        const char *szFile,
        const char *szFunction,
        bool bGetLastError)
{
  char *v6; // eax
  char *v7; // eax

  this->m_ErrorID = ErrorID;
  this->m_bGetLastError = bGetLastError;
  if ( szFile != nullptr && (v6 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(szFile) + 1)) != nullptr )
    strcpy(v6, szFile);
  else
    v6 = nullptr;
  this->m_szFile = v6;
  if ( szFunction != nullptr
    && (v7 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(szFunction) + 1)) != nullptr )
  {
    strcpy(v7, szFunction);
    this->m_szFunction = v7;
    return this;
  }
  else
  {
    this->m_szFunction = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003FF0
// Name: public: CMPAException::CMPAException(class CMPAException const __near &)
// Source: json
//------------------------------------------------------------------------------
CMPAException *__thiscall CMPAException::CMPAException(CMPAException *this, const CMPAException *Source)
{
  const CMPAException *v2; // esi
  const char *m_szFile; // edi
  char *v5; // eax
  const char *m_szFunction; // edi
  char *v7; // eax

  v2 = Source;
  this->m_ErrorID = Source->m_ErrorID;
  this->m_bGetLastError = Source->m_bGetLastError;
  m_szFile = Source->m_szFile;
  if ( m_szFile != nullptr
    && (v5 = (char *)_g_pMemAlloc->Alloc_2(
                       this: _g_pMemAlloc,
                       a2: &Source->m_szFile[strlen(Source->m_szFile) + 1] - m_szFile)) != nullptr )
  {
    strcpy(v5, m_szFile);
    v2 = Source;
  }
  else
  {
    v5 = nullptr;
  }
  this->m_szFile = v5;
  m_szFunction = v2->m_szFunction;
  if ( m_szFunction != nullptr
    && (v7 = (char *)_g_pMemAlloc->Alloc_2(
                       this: _g_pMemAlloc,
                       a2: &v2->m_szFunction[strlen(v2->m_szFunction) + 1] - m_szFunction)) != nullptr )
  {
    strcpy(v7, m_szFunction);
    this->m_szFunction = v7;
    return this;
  }
  else
  {
    this->m_szFunction = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100040B0
// Name: public: CMPAException::~CMPAException(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMPAException::~CMPAException(CMPAException *this)
{
  char *m_szFile; // eax

  m_szFile = (char *)this->m_szFile;
  if ( m_szFile != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_szFile);
  if ( this->m_szFunction != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_szFunction);
}

//------------------------------------------------------------------------------
// Address: 0x100040F0
// Name: public: void CMPAException::ShowError(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMPAException::ShowError(CMPAException *this)
{
  unsigned int v2; // eax
  char *v3; // edi
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  const char *v8; // edx
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  DWORD LastError; // eax
  char *v13; // edi
  char v14; // al
  void *v15; // ebx
  const char *v16; // eax
  const char *v17; // ecx
  unsigned int v18; // eax
  const char *v19; // esi
  char *v20; // edi
  char v21; // cl
  char szHelp[256]; // [esp+Ch] [ebp-204h] BYREF
  char szErrorMsg[256]; // [esp+10Ch] [ebp-104h] BYREF
  void *pMsgBuf; // [esp+20Ch] [ebp-4h] BYREF

  memset(szErrorMsg, 0, sizeof(szErrorMsg));
  if ( this->m_szFunction != nullptr )
  {
    sprintf(string: szHelp, format: "%s: ", this->m_szFunction);
    v2 = strlen(szHelp) + 1;
    v3 = &szHelp[255];
    do
      v4 = *++v3;
    while ( v4 != 0 );
    qmemcpy(v3, szHelp, v2);
  }
  if ( this->m_szFile != nullptr )
  {
    sprintf(string: szHelp, format: "'%s'\n", this->m_szFile);
    v5 = strlen(szHelp) + 1;
    v6 = &szHelp[255];
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, szHelp, v5);
  }
  v8 = m_szErrors[this->m_ErrorID];
  v9 = strlen(v8) + 1;
  v10 = &szHelp[255];
  do
    v11 = *++v10;
  while ( v11 != 0 );
  qmemcpy(v10, v8, v9);
  if ( this->m_bGetLastError )
  {
    LastError = GetLastError();
    if ( FormatMessageA(
           dwFlags: 0x1300u,
           lpSource: nullptr,
           dwMessageId: LastError,
           dwLanguageId: 0x400u,
           lpBuffer: (LPSTR)&pMsgBuf,
           nSize: 0,
           Arguments: nullptr) != 0 )
    {
      v13 = &szHelp[255];
      do
        v14 = *++v13;
      while ( v14 != 0 );
      v15 = pMsgBuf;
      v16 = (const char *)pMsgBuf;
      strcpy(v13, "\n");
      v17 = v16;
      v18 = strlen(v16) + 1;
      v19 = v17;
      v20 = &szHelp[255];
      do
        v21 = *++v20;
      while ( v21 != 0 );
      qmemcpy(v20, v19, v18);
      LocalFree(hMem: v15);
    }
  }
  _Warning(a1: "%s\n", szErrorMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10004290
// Name: private: void CMPAFile::FillBuffer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMPAFile::FillBuffer(CMPAFile *this, unsigned int dwOffsetToRead)
{
  unsigned int m_dwBufferSize; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx
  unsigned __int8 *m_pBuffer; // eax
  unsigned int v7; // eax
  int v8; // edi
  unsigned __int8 *dwOffsetToReada; // [esp+14h] [ebp+8h]

  m_dwBufferSize = this->m_dwBufferSize;
  v4 = 1024;
  if ( m_dwBufferSize != 0 )
    v4 = 2 * m_dwBufferSize;
  if ( v4 < dwOffsetToRead )
    v4 = dwOffsetToRead;
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4);
  m_pBuffer = (unsigned __int8 *)this->m_pBuffer;
  if ( m_pBuffer != nullptr )
  {
    memcpy(dst: v5, src: m_pBuffer, count: this->m_dwBufferSize);
    free(pMem: this->m_pBuffer);
  }
  v7 = this->m_dwBufferSize;
  this->m_pBuffer = (char *)v5;
  dwOffsetToReada = &v5[v7];
  v8 = v4 - v7;
  g_pFullFileSystem->Seek(
    this: &g_pFullFileSystem->IBaseFileSystem,
    a2: this->m_hFile,
    a3: v7 + this->m_dwBegin,
    a4: FILESYSTEM_SEEK_HEAD);
  this->m_dwBufferSize += g_pFullFileSystem->Read(
                            this: &g_pFullFileSystem->IBaseFileSystem,
                            a2: dwOffsetToReada,
                            a3: v8,
                            a4: this->m_hFile);
}

//------------------------------------------------------------------------------
// Address: 0x10004330
// Name: public: CMPAFile::CMPAFile(char const __near *,unsigned int,void __near *)
// Source: json
//------------------------------------------------------------------------------
CMPAFile *__thiscall CMPAFile::CMPAFile(CMPAFile *this, const char *szFile, unsigned int dwFileOffset, void *hFile)
{
  void *v5; // eax
  const char *v6; // ebx
  void *v7; // eax
  char *v8; // eax
  CMPAHeader *v9; // eax
  CMPAHeader *v10; // eax
  CVBRHeader *v11; // eax
  CVBRHeader *v12; // eax
  int v14; // [esp+0h] [ebp-34h] BYREF
  CMPAException pExceptionObject; // [esp+Ch] [ebp-28h] BYREF
  CMPAFile *v16; // [esp+20h] [ebp-14h]
  int *v17; // [esp+24h] [ebp-10h]
  int v18; // [esp+30h] [ebp-4h]

  v17 = &v14;
  v16 = this;
  v5 = hFile;
  this->m_hFile = hFile;
  this->m_szFile = nullptr;
  this->m_bMustReleaseFile = false;
  this->m_dwBegin = dwFileOffset;
  this->m_dwEnd = 0;
  this->m_bVBRFile = false;
  this->m_pMPAHeader = nullptr;
  this->m_dwFrameNo = 1;
  this->m_pVBRHeader = nullptr;
  this->m_dwNumTimesRead = 0;
  this->m_pBuffer = nullptr;
  this->m_dwBufferSize = 0;
  v6 = szFile;
  if ( v5 == nullptr )
  {
    v7 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFile, a3: "rb", a4: "GAME");
    this->m_hFile = v7;
    if ( v7 == nullptr )
    {
      CMPAException::CMPAException(
        this: &pExceptionObject,
        ErrorID: ErrOpenFile,
        szFile: v6,
        szFunction: "CreateFile",
        bGetLastError: true);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVCMPAException__);
    }
    this->m_bMustReleaseFile = true;
  }
  if ( v6 != nullptr && (v8 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(v6) + 1)) != nullptr )
    strcpy(v8, v6);
  else
    v8 = nullptr;
  this->m_szFile = v8;
  if ( this->m_dwEnd == 0 )
    this->m_dwEnd = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: this->m_hFile);
  v9 = (CMPAHeader *)MemAlloc_Alloc(nSize: 0x3Cu);
  if ( v9 != nullptr )
    v10 = CMPAHeader::CMPAHeader(
            this: v9,
            pMPAFile: this,
            dwExpectedOffset: 0,
            bSubsequentFrame: false,
            bReverse: false);
  else
    v10 = nullptr;
  this->m_pMPAHeader = v10;
  hFile = nullptr;
  szFile = (const char *)v10->m_dwSyncOffset;
  if ( CVBRHeader::IsVBRHeaderAvailable(
         pMPAFile: this,
         HeaderType: (CVBRHeader::VBRHeaderType *)&hFile,
         dwOffset: (unsigned int *)&szFile) )
  {
    v18 = 0;
    v11 = (CVBRHeader *)MemAlloc_Alloc(nSize: 0x38u);
    if ( v11 != nullptr )
      v12 = CVBRHeader::CVBRHeader(
              this: v11,
              pMPAFile: this,
              HeaderType: (CVBRHeader::VBRHeaderType)hFile,
              dwOffset: (unsigned int)szFile);
    else
      v12 = nullptr;
    this->m_pVBRHeader = v12;
    this->m_bVBRFile = true;
    this->m_dwBytesPerSec = v12->m_dwBytesPerSec;
    if ( v12->m_dwBytes != 0 )
      this->m_dwEnd = this->m_dwBegin + v12->m_dwBytes;
    v18 = -1;
  }
  if ( this->m_pVBRHeader == nullptr )
  {
    this->m_bVBRFile = CMPAHeader::SkipEmptyFrames(this: this->m_pMPAHeader);
    this->m_dwBytesPerSec = this->m_pMPAHeader->m_dwBitrate >> 3;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004510
// Name: public: CMPAFile::~CMPAFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMPAFile::~CMPAFile(CMPAFile *this)
{
  CMPAHeader *m_pMPAHeader; // edi
  CVBRHeader *m_pVBRHeader; // edi
  char *m_szFile; // esi

  m_pMPAHeader = this->m_pMPAHeader;
  if ( m_pMPAHeader != nullptr )
  {
    CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)this->m_pMPAHeader);
    free(pMem: m_pMPAHeader);
  }
  m_pVBRHeader = this->m_pVBRHeader;
  if ( m_pVBRHeader != nullptr )
  {
    CVBRHeader::~CVBRHeader(this: this->m_pVBRHeader);
    free(pMem: m_pVBRHeader);
  }
  if ( this->m_pBuffer != nullptr )
    free(pMem: this->m_pBuffer);
  if ( this->m_bMustReleaseFile )
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: this->m_hFile);
  m_szFile = (char *)this->m_szFile;
  if ( m_szFile != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_szFile);
}

//------------------------------------------------------------------------------
// Address: 0x10004590
// Name: public: unsigned int CMPAFile::ExtractBytes(unsigned int __near &,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMPAFile::ExtractBytes(
        CMPAFile *this,
        unsigned int *dwOffset,
        signed int dwNumBytes,
        bool bMoveOffset)
{
  unsigned int *v6; // edi
  unsigned int v7; // edx
  unsigned int v8; // ecx
  unsigned int result; // eax
  unsigned int v10; // edi
  unsigned int v11; // ecx
  char *m_pBuffer; // esi
  int v13; // ebx
  unsigned int dwNumBytesa; // [esp+18h] [ebp+Ch]

  v6 = dwOffset;
  if ( this->m_pBuffer == nullptr || (int)(this->m_dwBufferSize - *dwOffset) < dwNumBytes )
    CMPAFile::FillBuffer(this, dwOffsetToRead: dwNumBytes + *dwOffset);
  v7 = *dwOffset;
  v8 = *dwOffset + dwNumBytes;
  result = 0;
  dwNumBytesa = v8;
  if ( *dwOffset < v8 )
  {
    v10 = dwNumBytes + v7;
    v11 = 8 * dwNumBytes - 8;
    m_pBuffer = this->m_pBuffer;
    do
    {
      v13 = m_pBuffer[v7++] << v11;
      v11 -= 8;
      result |= v13;
    }
    while ( v7 < v10 );
    v6 = dwOffset;
    v8 = dwNumBytesa;
  }
  if ( bMoveOffset )
    *v6 = v8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005380
// Name: float GetMP3Duration_Helper(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetMP3Duration_Helper(char *filename)
{
  char *v1; // eax
  int v2; // eax
  int v4; // [esp+0h] [ebp-260h] BYREF
  char fn[512]; // [esp+Ch] [ebp-254h] BYREF
  CMPAFile MPAFile; // [esp+20Ch] [ebp-54h] BYREF
  unsigned int m_dwBytesPerSec; // [esp+240h] [ebp-20h]
  MP3Duration_t search; // [esp+244h] [ebp-1Ch] BYREF
  float duration; // [esp+24Ch] [ebp-14h]
  int *v10; // [esp+250h] [ebp-10h]
  int v11; // [esp+25Ch] [ebp-4h]

  v10 = &v4;
  duration = 60.0;
  v1 = PSkipSoundChars(pch: filename);
  V_snprintf(pDest: fn, maxLen: 512, pFormat: "sound/%s", v1);
  search.h = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: fn);
  v2 = CUtlRBTree<MP3Duration_t,int,bool (__cdecl *)(MP3Duration_t const &,MP3Duration_t const &),CUtlMemory<UtlRBTreeNode_t<MP3Duration_t,int>,int>>::Find(
         this: &g_MP3Durations,
         &search);
  if ( v2 != -1 )
    return g_MP3Durations.m_Elements.m_pMemory[v2].m_Data.duration;
  v11 = 0;
  CMPAFile::CMPAFile(this: &MPAFile, szFile: fn, dwFileOffset: 0, hFile: nullptr);
  if ( MPAFile.m_dwBytesPerSec != 0 )
  {
    m_dwBytesPerSec = MPAFile.m_dwBytesPerSec;
    duration = (double)(MPAFile.m_dwEnd - MPAFile.m_dwBegin) / (double)MPAFile.m_dwBytesPerSec;
  }
  CMPAFile::~CMPAFile(this: &MPAFile);
  v11 = -1;
  search.duration = duration;
  CUtlRBTree<MP3Duration_t,int,bool (__cdecl *)(MP3Duration_t const &,MP3Duration_t const &),CUtlMemory<UtlRBTreeNode_t<MP3Duration_t,int>,int>>::Insert(
    this: &g_MP3Durations,
    insert: &search);
  return duration;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10003EC0
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003F10
// Name: public: CMPAException::CMPAException(enum CMPAException::ErrorIDs,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMPAException *__thiscall CMPAException::CMPAException(
        CMPAException *this,
        CMPAException::ErrorIDs ErrorID,
        const char *szFile,
        const char *szFunction,
        bool bGetLastError)
{
  char *v6; // eax
  char *v7; // eax

  this->m_ErrorID = ErrorID;
  this->m_bGetLastError = bGetLastError;
  if ( szFile != nullptr && (v6 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(szFile) + 1)) != nullptr )
    strcpy(v6, szFile);
  else
    v6 = nullptr;
  this->m_szFile = v6;
  if ( szFunction != nullptr
    && (v7 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(szFunction) + 1)) != nullptr )
  {
    strcpy(v7, szFunction);
    this->m_szFunction = v7;
    return this;
  }
  else
  {
    this->m_szFunction = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003FC0
// Name: public: CMPAException::CMPAException(class CMPAException const __near &)
// Source: json
//------------------------------------------------------------------------------
CMPAException *__thiscall CMPAException::CMPAException(CMPAException *this, const CMPAException *Source)
{
  const CMPAException *v2; // esi
  const char *m_szFile; // edi
  char *v5; // eax
  const char *m_szFunction; // edi
  char *v7; // eax

  v2 = Source;
  this->m_ErrorID = Source->m_ErrorID;
  this->m_bGetLastError = Source->m_bGetLastError;
  m_szFile = Source->m_szFile;
  if ( m_szFile != nullptr
    && (v5 = (char *)_g_pMemAlloc->Alloc_2(
                       this: _g_pMemAlloc,
                       a2: &Source->m_szFile[strlen(Source->m_szFile) + 1] - m_szFile)) != nullptr )
  {
    strcpy(v5, m_szFile);
    v2 = Source;
  }
  else
  {
    v5 = nullptr;
  }
  this->m_szFile = v5;
  m_szFunction = v2->m_szFunction;
  if ( m_szFunction != nullptr
    && (v7 = (char *)_g_pMemAlloc->Alloc_2(
                       this: _g_pMemAlloc,
                       a2: &v2->m_szFunction[strlen(v2->m_szFunction) + 1] - m_szFunction)) != nullptr )
  {
    strcpy(v7, m_szFunction);
    this->m_szFunction = v7;
    return this;
  }
  else
  {
    this->m_szFunction = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004080
// Name: public: CMPAException::~CMPAException(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMPAException::~CMPAException(CMPAException *this)
{
  char *m_szFile; // eax

  m_szFile = (char *)this->m_szFile;
  if ( m_szFile != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_szFile);
  if ( this->m_szFunction != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_szFunction);
}

//------------------------------------------------------------------------------
// Address: 0x100040C0
// Name: public: void CMPAException::ShowError(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMPAException::ShowError(CMPAException *this)
{
  unsigned int v2; // eax
  char *v3; // edi
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  const char *v8; // edx
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  DWORD LastError; // eax
  char *v13; // edi
  char v14; // al
  void *v15; // ebx
  const char *v16; // eax
  const char *v17; // ecx
  unsigned int v18; // eax
  const char *v19; // esi
  char *v20; // edi
  char v21; // cl
  char szHelp[256]; // [esp+Ch] [ebp-204h] BYREF
  char szErrorMsg[256]; // [esp+10Ch] [ebp-104h] BYREF
  void *pMsgBuf; // [esp+20Ch] [ebp-4h] BYREF

  memset(szErrorMsg, 0, sizeof(szErrorMsg));
  if ( this->m_szFunction != nullptr )
  {
    sprintf(string: szHelp, format: "%s: ", this->m_szFunction);
    v2 = strlen(szHelp) + 1;
    v3 = &szHelp[255];
    do
      v4 = *++v3;
    while ( v4 != 0 );
    qmemcpy(v3, szHelp, v2);
  }
  if ( this->m_szFile != nullptr )
  {
    sprintf(string: szHelp, format: "'%s'\n", this->m_szFile);
    v5 = strlen(szHelp) + 1;
    v6 = &szHelp[255];
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, szHelp, v5);
  }
  v8 = m_szErrors[this->m_ErrorID];
  v9 = strlen(v8) + 1;
  v10 = &szHelp[255];
  do
    v11 = *++v10;
  while ( v11 != 0 );
  qmemcpy(v10, v8, v9);
  if ( this->m_bGetLastError )
  {
    LastError = GetLastError();
    if ( FormatMessageA(
           dwFlags: 0x1300u,
           lpSource: nullptr,
           dwMessageId: LastError,
           dwLanguageId: 0x400u,
           lpBuffer: (LPSTR)&pMsgBuf,
           nSize: 0,
           Arguments: nullptr) != 0 )
    {
      v13 = &szHelp[255];
      do
        v14 = *++v13;
      while ( v14 != 0 );
      v15 = pMsgBuf;
      v16 = (const char *)pMsgBuf;
      strcpy(v13, "\n");
      v17 = v16;
      v18 = strlen(v16) + 1;
      v19 = v17;
      v20 = &szHelp[255];
      do
        v21 = *++v20;
      while ( v21 != 0 );
      qmemcpy(v20, v19, v18);
      LocalFree(hMem: v15);
    }
  }
  _Warning(a1: "%s\n", szErrorMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10004260
// Name: private: void CMPAFile::FillBuffer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMPAFile::FillBuffer(CMPAFile *this, unsigned int dwOffsetToRead)
{
  unsigned int m_dwBufferSize; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx
  unsigned __int8 *m_pBuffer; // eax
  unsigned int v7; // eax
  int v8; // edi
  unsigned __int8 *dwOffsetToReada; // [esp+14h] [ebp+8h]

  m_dwBufferSize = this->m_dwBufferSize;
  v4 = 1024;
  if ( m_dwBufferSize != 0 )
    v4 = 2 * m_dwBufferSize;
  if ( v4 < dwOffsetToRead )
    v4 = dwOffsetToRead;
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4);
  m_pBuffer = (unsigned __int8 *)this->m_pBuffer;
  if ( m_pBuffer != nullptr )
  {
    memcpy(dst: v5, src: m_pBuffer, count: this->m_dwBufferSize);
    free(pMem: this->m_pBuffer);
  }
  v7 = this->m_dwBufferSize;
  this->m_pBuffer = (char *)v5;
  dwOffsetToReada = &v5[v7];
  v8 = v4 - v7;
  g_pFullFileSystem->Seek(
    this: &g_pFullFileSystem->IBaseFileSystem,
    a2: this->m_hFile,
    a3: v7 + this->m_dwBegin,
    a4: FILESYSTEM_SEEK_HEAD);
  this->m_dwBufferSize += g_pFullFileSystem->Read(
                            this: &g_pFullFileSystem->IBaseFileSystem,
                            a2: dwOffsetToReada,
                            a3: v8,
                            a4: this->m_hFile);
}

//------------------------------------------------------------------------------
// Address: 0x10004320
// Name: public: CMPAFile::CMPAFile(char const __near *,unsigned int,void __near *)
// Source: json
//------------------------------------------------------------------------------
CMPAFile *__thiscall CMPAFile::CMPAFile(CMPAFile *this, const char *szFile, unsigned int dwFileOffset, void *hFile)
{
  void *v5; // eax
  const char *v6; // ebx
  void *v7; // eax
  char *v8; // eax
  CMPAHeader *v9; // eax
  CMPAHeader *v10; // eax
  CVBRHeader *v11; // eax
  CVBRHeader *v12; // eax
  int v14; // [esp+0h] [ebp-34h] BYREF
  CMPAException pExceptionObject; // [esp+Ch] [ebp-28h] BYREF
  CMPAFile *v16; // [esp+20h] [ebp-14h]
  int *v17; // [esp+24h] [ebp-10h]
  int v18; // [esp+30h] [ebp-4h]

  v17 = &v14;
  v16 = this;
  v5 = hFile;
  this->m_hFile = hFile;
  this->m_szFile = nullptr;
  this->m_bMustReleaseFile = false;
  this->m_dwBegin = dwFileOffset;
  this->m_dwEnd = 0;
  this->m_bVBRFile = false;
  this->m_pMPAHeader = nullptr;
  this->m_dwFrameNo = 1;
  this->m_pVBRHeader = nullptr;
  this->m_dwNumTimesRead = 0;
  this->m_pBuffer = nullptr;
  this->m_dwBufferSize = 0;
  v6 = szFile;
  if ( v5 == nullptr )
  {
    v7 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFile, a3: "rb", a4: "GAME");
    this->m_hFile = v7;
    if ( v7 == nullptr )
    {
      CMPAException::CMPAException(
        this: &pExceptionObject,
        ErrorID: ErrOpenFile,
        szFile: v6,
        szFunction: "CreateFile",
        bGetLastError: true);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVCMPAException__);
    }
    this->m_bMustReleaseFile = true;
  }
  if ( v6 != nullptr && (v8 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(v6) + 1)) != nullptr )
    strcpy(v8, v6);
  else
    v8 = nullptr;
  this->m_szFile = v8;
  if ( this->m_dwEnd == 0 )
    this->m_dwEnd = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: this->m_hFile);
  v9 = (CMPAHeader *)MemAlloc_Alloc(nSize: 0x3Cu);
  if ( v9 != nullptr )
    v10 = CMPAHeader::CMPAHeader(
            this: v9,
            pMPAFile: this,
            dwExpectedOffset: 0,
            bSubsequentFrame: false,
            bReverse: false);
  else
    v10 = nullptr;
  this->m_pMPAHeader = v10;
  hFile = nullptr;
  szFile = (const char *)v10->m_dwSyncOffset;
  if ( CVBRHeader::IsVBRHeaderAvailable(
         pMPAFile: this,
         HeaderType: (CVBRHeader::VBRHeaderType *)&hFile,
         dwOffset: (unsigned int *)&szFile) )
  {
    v18 = 0;
    v11 = (CVBRHeader *)MemAlloc_Alloc(nSize: 0x38u);
    if ( v11 != nullptr )
      v12 = CVBRHeader::CVBRHeader(
              this: v11,
              pMPAFile: this,
              HeaderType: (CVBRHeader::VBRHeaderType)hFile,
              dwOffset: (unsigned int)szFile);
    else
      v12 = nullptr;
    this->m_pVBRHeader = v12;
    this->m_bVBRFile = true;
    this->m_dwBytesPerSec = v12->m_dwBytesPerSec;
    if ( v12->m_dwBytes != 0 )
      this->m_dwEnd = this->m_dwBegin + v12->m_dwBytes;
    v18 = -1;
  }
  if ( this->m_pVBRHeader == nullptr )
  {
    this->m_bVBRFile = CMPAHeader::SkipEmptyFrames(this: this->m_pMPAHeader);
    this->m_dwBytesPerSec = this->m_pMPAHeader->m_dwBitrate >> 3;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004500
// Name: public: CMPAFile::~CMPAFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMPAFile::~CMPAFile(CMPAFile *this)
{
  CMPAHeader *m_pMPAHeader; // edi
  CVBRHeader *m_pVBRHeader; // edi
  char *m_szFile; // esi

  m_pMPAHeader = this->m_pMPAHeader;
  if ( m_pMPAHeader != nullptr )
  {
    CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)this->m_pMPAHeader);
    free(pMem: m_pMPAHeader);
  }
  m_pVBRHeader = this->m_pVBRHeader;
  if ( m_pVBRHeader != nullptr )
  {
    CVBRHeader::~CVBRHeader(this: this->m_pVBRHeader);
    free(pMem: m_pVBRHeader);
  }
  if ( this->m_pBuffer != nullptr )
    free(pMem: this->m_pBuffer);
  if ( this->m_bMustReleaseFile )
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: this->m_hFile);
  m_szFile = (char *)this->m_szFile;
  if ( m_szFile != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_szFile);
}

//------------------------------------------------------------------------------
// Address: 0x10004580
// Name: public: unsigned int CMPAFile::ExtractBytes(unsigned int __near &,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMPAFile::ExtractBytes(
        CMPAFile *this,
        unsigned int *dwOffset,
        signed int dwNumBytes,
        bool bMoveOffset)
{
  unsigned int *v6; // edi
  unsigned int v7; // edx
  unsigned int v8; // ecx
  unsigned int result; // eax
  unsigned int v10; // edi
  unsigned int v11; // ecx
  char *m_pBuffer; // esi
  int v13; // ebx
  unsigned int dwNumBytesa; // [esp+18h] [ebp+Ch]

  v6 = dwOffset;
  if ( this->m_pBuffer == nullptr || (int)(this->m_dwBufferSize - *dwOffset) < dwNumBytes )
    CMPAFile::FillBuffer(this, dwOffsetToRead: dwNumBytes + *dwOffset);
  v7 = *dwOffset;
  v8 = *dwOffset + dwNumBytes;
  result = 0;
  dwNumBytesa = v8;
  if ( *dwOffset < v8 )
  {
    v10 = dwNumBytes + v7;
    v11 = 8 * dwNumBytes - 8;
    m_pBuffer = this->m_pBuffer;
    do
    {
      v13 = m_pBuffer[v7++] << v11;
      v11 -= 8;
      result |= v13;
    }
    while ( v7 < v10 );
    v6 = dwOffset;
    v8 = dwNumBytesa;
  }
  if ( bMoveOffset )
    *v6 = v8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005370
// Name: float GetMP3Duration_Helper(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetMP3Duration_Helper(const char *filename)
{
  const char *v1; // eax
  int v2; // eax
  int v4; // [esp+0h] [ebp-260h] BYREF
  char fn[512]; // [esp+Ch] [ebp-254h] BYREF
  CMPAFile MPAFile; // [esp+20Ch] [ebp-54h] BYREF
  unsigned int m_dwBytesPerSec; // [esp+240h] [ebp-20h]
  MP3Duration_t search; // [esp+244h] [ebp-1Ch] BYREF
  float duration; // [esp+24Ch] [ebp-14h]
  int *v10; // [esp+250h] [ebp-10h]
  int v11; // [esp+25Ch] [ebp-4h]

  v10 = &v4;
  duration = 60.0;
  v1 = PSkipSoundChars(pch: filename);
  V_snprintf(pDest: fn, maxLen: 512, pFormat: "sound/%s", v1);
  search.h = g_pFullFileSystem->FindOrAddFileName(this: g_pFullFileSystem, a2: fn);
  v2 = CUtlRBTree<MP3Duration_t,int,bool (__cdecl *)(MP3Duration_t const &,MP3Duration_t const &),CUtlMemory<UtlRBTreeNode_t<MP3Duration_t,int>,int>>::Find(
         this: &g_MP3Durations,
         &search);
  if ( v2 != -1 )
    return g_MP3Durations.m_Elements.m_pMemory[v2].m_Data.duration;
  v11 = 0;
  CMPAFile::CMPAFile(this: &MPAFile, szFile: fn, dwFileOffset: 0, hFile: nullptr);
  if ( MPAFile.m_dwBytesPerSec != 0 )
  {
    m_dwBytesPerSec = MPAFile.m_dwBytesPerSec;
    duration = (double)(MPAFile.m_dwEnd - MPAFile.m_dwBegin) / (double)MPAFile.m_dwBytesPerSec;
  }
  CMPAFile::~CMPAFile(this: &MPAFile);
  v11 = -1;
  search.duration = duration;
  CUtlRBTree<MP3Duration_t,int,bool (__cdecl *)(MP3Duration_t const &,MP3Duration_t const &),CUtlMemory<UtlRBTreeNode_t<MP3Duration_t,int>,int>>::Insert(
    this: &g_MP3Durations,
    insert: &search);
  return duration;
}

} // namespace engine_xlsp
