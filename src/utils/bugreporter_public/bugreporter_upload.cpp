// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/bugreporter_public/bugreporter_upload.cpp
// Functions: 31
// ============================================================

#include "utils\bugreporter_public\bugreporter_upload.h"

//------------------------------------------------------------------------------
// Address: 0x10001830
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbol *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A20
// Name: public: int CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>>::InsertBefore(int,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *this,
        int elem,
        const CUtlSymbol *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlSymbol,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->m_Id = src->m_Id;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10001A90
// Name: public: CUtlVector<struct CUtlSymbolTable::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTable::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTable::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTable::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001DC0
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100022F0
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002540
// Name: void UpdateProgress(struct TBugReportParameters const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void UpdateProgress(const TBugReportParameters *params, char *fmt, ...)
{
  char pDest[2060]; // [esp+4h] [ebp-120Ch] BYREF
  char string[2048]; // [esp+810h] [ebp-A00h] BYREF
  char v4[512]; // [esp+1010h] [ebp-200h] BYREF
  va_list ap; // [esp+1220h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( params->m_pOptionalProgressFunc != nullptr )
  {
    _vsnprintf(string, count: 0x7FFu, format: fmt, ap);
    V_snprintf(pDest, maxLen: 2060, pFormat: "(%u): %s", params->m_uProgressContext, string);
    V_strncpy(pDest: v4, pSrc: pDest, maxLen: 512);
    params->m_pOptionalProgressFunc(a1: params->m_uProgressContext, a2: (const TBugReportProgress *)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100025D0
// Name: private: bool CWin32UploadBugReport::CreateTCPSocket(enum EBugReportUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadBugReport::CreateTCPSocket(
        CWin32UploadBugReport *this,
        EBugReportUploadStatus *status,
        CUtlBuffer *__formal)
{
  SOCKET v4; // eax

  UpdateProgress(params: this->m_rBugReportParameters, fmt: "Creating bug report upload socket.");
  v4 = socket(af: 2, type: 1, protocol: 6);
  this->m_SocketTCP = v4;
  if ( v4 == -1 )
  {
    UpdateProgress(params: this->m_rBugReportParameters, fmt: "Socket creation failed.");
    *status = eBugReportUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002630
// Name: private: bool CWin32UploadBugReport::ConnectToHarvesterServer(enum EBugReportUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadBugReport::ConnectToHarvesterServer(
        CWin32UploadBugReport *this,
        EBugReportUploadStatus *status,
        CUtlBuffer *__formal)
{
  UpdateProgress(params: this->m_rBugReportParameters, fmt: "Connecting to bug report harvesting server.");
  if ( connect(s: this->m_SocketTCP, name: (const struct sockaddr *)&this->m_HarvesterSockAddr, namelen: 16) == -1 )
  {
    UpdateProgress(params: this->m_rBugReportParameters, fmt: "Connection failed.");
    *status = eBugReportConnectToCSERServerFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 2;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002690
// Name: private: bool CWin32UploadBugReport::SendWholeFile(enum EBugReportUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadBugReport::SendWholeFile(
        CWin32UploadBugReport *this,
        EBugReportUploadStatus *status,
        CUtlBuffer *__formal)
{
  int v4; // ebx
  void *v5; // edi
  void *v6; // eax
  void *fh; // [esp+Ch] [ebp-8h]

  UpdateProgress(params: this->m_rBugReportParameters, fmt: "Uploading bug report data.");
  v4 = g_pFileSystem->Size(this: g_pFileSystem, a2: this->m_rBugReportParameters->m_sAttachmentFile, a3: nullptr);
  if ( v4 == 0 )
    goto LABEL_10;
  v5 = operator new(nSize: v4 + 1);
  if ( v5 != nullptr )
  {
    v6 = g_pFileSystem->Open(this: g_pFileSystem, a2: this->m_rBugReportParameters->m_sAttachmentFile, a3: "rb", a4: 0);
    fh = v6;
    if ( v6 != nullptr )
    {
      g_pFileSystem->Read(this: g_pFileSystem, a2: v5, a3: v4, a4: v6);
      g_pFileSystem->Close(this: g_pFileSystem, a2: fh);
    }
    *((_BYTE *)v5 + v4) = 0;
  }
  if ( v5 != nullptr )
  {
    if ( send(s: this->m_SocketTCP, buf: (const char *)v5, len: v4, flags: 0) == -1 )
    {
      UpdateProgress(params: this->m_rBugReportParameters, fmt: "Send failed.");
      *status = eBugReportUploadFailed;
      free(pMem: v5);
      return 0;
    }
    else
    {
      this->m_uCurrentState = 7;
      free(pMem: v5);
      return 1;
    }
  }
  else
  {
LABEL_10:
    UpdateProgress(
      params: this->m_rBugReportParameters,
      fmt: "bug .zip file size zero or unable to allocate memory for file.");
    *status = eBugReportUploadFailed;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100027D0
// Name: private: bool CWin32UploadBugReport::CloseTCPSocket(enum EBugReportUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32UploadBugReport::CloseTCPSocket(
        CWin32UploadBugReport *this,
        EBugReportUploadStatus *status,
        CUtlBuffer *__formal)
{
  UpdateProgress(params: this->m_rBugReportParameters, fmt: "Closing socket, upload succeeded.");
  closesocket(s: this->m_SocketTCP);
  this->m_SocketTCP = 0;
  *status = eBugReportUploadSucceeded;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10002810
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
// Address: 0x10002890
// Name: public: void CByteswap::SwapBufferToTargetEndian<int>(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<int>(
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
// Address: 0x10002920
// Name: public: void CUtlMemory<struct CWin32UploadBugReport::FSMState_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CWin32UploadBugReport::FSMState_t,int>::Grow(
        CUtlMemory<CWin32UploadBugReport::FSMState_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CWin32UploadBugReport::FSMState_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CWin32UploadBugReport::FSMState_t *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: m_pMemory,
                                                               a3: v7);
    else
      this->m_pMemory = (CWin32UploadBugReport::FSMState_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100029C0
// Name: private: bool CWin32UploadBugReport::DoBlockingReceive(unsigned int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadBugReport::DoBlockingReceive(
        CWin32UploadBugReport *this,
        unsigned int bytesExpected,
        CUtlBuffer *buf)
{
  int v4; // eax
  char bufa[8192]; // [esp+Ch] [ebp-2000h] BYREF

  buf->m_Get = 0;
  buf->m_Put = 0;
  buf->m_nOffset = 0;
  buf->m_nMaxPut = 0;
  buf->m_Error = 0;
  if ( buf->m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf->m_Memory.m_pMemory);
      buf->m_Memory.m_pMemory = nullptr;
    }
    buf->m_Memory.m_nAllocationCount = 0;
  }
  v4 = recv(s: this->m_SocketTCP, buf: bufa, len: 0x2000, flags: 0);
  if ( v4 <= 0 )
    return 0;
  while ( 1 )
  {
    CUtlBuffer::Put(this: buf, pMem: bufa, size: v4);
    if ( buf->m_Put >= bytesExpected )
      break;
    v4 = recv(s: this->m_SocketTCP, buf: bufa, len: 0x2000, flags: 0);
    if ( v4 <= 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002A70
// Name: public: enum EBugReportUploadStatus CWin32UploadBugReport::Upload(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
EBugReportUploadStatus __thiscall CWin32UploadBugReport::Upload(CWin32UploadBugReport *this, CUtlBuffer *buf)
{
  EBugReportUploadStatus v4; // [esp+8h] [ebp-4h] BYREF

  UpdateProgress(params: this->m_rBugReportParameters, fmt: "Commencing bug report upload connection.");
  v4 = eBugReportUploadSucceeded;
  while ( this->m_States.m_Memory.m_pMemory[this->m_uCurrentState].second(this, a2: &v4, a3: buf) )
    ;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10002AC0
// Name: protected: void CUtlBuffer::PutTypeBin<short>(short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<short>(CUtlBuffer *this, __int16 src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 2) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<short>(
        this: &this->m_Byteswap,
        outputBuffer: &this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_WORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 2;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002B30
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002BA0
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
// Address: 0x10002BD0
// Name: private: bool CWin32UploadBugReport::ReceiveProtocolOkay(enum EBugReportUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadBugReport::ReceiveProtocolOkay(
        CWin32UploadBugReport *this,
        EBugReportUploadStatus *status,
        CUtlBuffer *buf)
{
  unsigned __int8 v5; // cl

  UpdateProgress(params: this->m_rBugReportParameters, fmt: "Receiving harvesting protocol acknowledgement.");
  buf->m_Get = 0;
  buf->m_Put = 0;
  buf->m_nOffset = 0;
  buf->m_nMaxPut = 0;
  buf->m_Error = 0;
  if ( buf->m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf->m_Memory.m_pMemory);
      buf->m_Memory.m_pMemory = nullptr;
    }
    buf->m_Memory.m_nAllocationCount = 0;
  }
  if ( CWin32UploadBugReport::DoBlockingReceive(this, bytesExpected: 1u, buf) != 0 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1)
      && (v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], ++buf->m_Get, v5 != 0) )
    {
      UpdateProgress(params: this->m_rBugReportParameters, fmt: "Protocol OK.");
      this->m_uCurrentState = 4;
      return 1;
    }
    else
    {
      UpdateProgress(params: this->m_rBugReportParameters, fmt: "Server rejected protocol.");
      *status = eBugReportUploadFailed;
      return 0;
    }
  }
  else
  {
    UpdateProgress(params: this->m_rBugReportParameters, fmt: "Didn't receive protocol failure data.");
    *status = eBugReportUploadFailed;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002CC0
// Name: private: bool CWin32UploadBugReport::ReceiveOKToSendFile(enum EBugReportUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadBugReport::ReceiveOKToSendFile(
        CWin32UploadBugReport *this,
        EBugReportUploadStatus *status,
        CUtlBuffer *buf)
{
  unsigned __int8 v5; // cl

  UpdateProgress(
    params: this->m_rBugReportParameters,
    fmt: "Receive bug report harvesting protocol upload permissible.");
  if ( CWin32UploadBugReport::DoBlockingReceive(this, bytesExpected: 1u, buf) != 0 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1)
      && (v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], ++buf->m_Get, v5 != 0) )
    {
      UpdateProgress(params: this->m_rBugReportParameters, fmt: "Server rejected upload command.");
      *status = eBugReportUploadFailed;
      return 0;
    }
    else
    {
      this->m_uCurrentState = 6;
      return 1;
    }
  }
  else
  {
    UpdateProgress(params: this->m_rBugReportParameters, fmt: "Receive failed.");
    *status = eBugReportUploadFailed;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D60
// Name: private: bool CWin32UploadBugReport::ReceiveFileUploadSuccess(enum EBugReportUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadBugReport::ReceiveFileUploadSuccess(
        CWin32UploadBugReport *this,
        EBugReportUploadStatus *status,
        CUtlBuffer *buf)
{
  unsigned __int8 v5; // cl

  UpdateProgress(params: this->m_rBugReportParameters, fmt: "Receiving bug report upload success/fail message.");
  if ( CWin32UploadBugReport::DoBlockingReceive(this, bytesExpected: 1u, buf) != 0 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1)
      && (v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], ++buf->m_Get, v5 == 1) )
    {
      UpdateProgress(params: this->m_rBugReportParameters, fmt: "Upload OK.");
      this->m_uCurrentState = 8;
      return 1;
    }
    else
    {
      UpdateProgress(params: this->m_rBugReportParameters, fmt: "Upload failed.");
      *status = eBugReportUploadFailed;
      return 0;
    }
  }
  else
  {
    UpdateProgress(params: this->m_rBugReportParameters, fmt: "Receive failed.");
    *status = eBugReportUploadFailed;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E10
// Name: public: int CUtlVector<struct CWin32UploadBugReport::FSMState_t,class CUtlMemory<struct CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(int,struct CWin32UploadBugReport::FSMState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
        CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int> > *this,
        int elem,
        const CWin32UploadBugReport::FSMState_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWin32UploadBugReport::FSMState_t *m_pMemory; // ecx
  int v7; // eax
  CWin32UploadBugReport::FSMState_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CWin32UploadBugReport::FSMState_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10002E80
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
        CByteswap::SwapBufferToTargetEndian<short>(
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
// Address: 0x10002F20
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
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
  result = strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002FC0
// Name: public: CWin32UploadBugReport::~CWin32UploadBugReport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32UploadBugReport::~CWin32UploadBugReport(CWin32UploadBugReport *this)
{
  if ( this->m_SocketTCP != 0 )
  {
    closesocket(s: this->m_SocketTCP);
    this->m_SocketTCP = 0;
  }
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10002FE0
// Name: private: bool CWin32UploadBugReport::SendProtocolVersion(enum EBugReportUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadBugReport::SendProtocolVersion(
        CWin32UploadBugReport *this,
        EBugReportUploadStatus *status,
        CUtlBuffer *buf)
{
  UpdateProgress(params: this->m_rBugReportParameters, fmt: "Sending bug report harvester protocol info.");
  CUtlBuffer::SetBigEndian(this: buf, bigEndian: true);
  buf->m_Get = 0;
  buf->m_Put = 0;
  buf->m_nOffset = 0;
  buf->m_nMaxPut = 0;
  buf->m_Error = 0;
  if ( buf->m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf->m_Memory.m_pMemory);
      buf->m_Memory.m_pMemory = nullptr;
    }
    buf->m_Memory.m_nAllocationCount = 0;
  }
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 1);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 1);
  if ( send(s: this->m_SocketTCP, buf: (const char *)buf->m_Memory.m_pMemory, len: buf->m_Put, flags: 0) == -1 )
  {
    UpdateProgress(params: this->m_rBugReportParameters, fmt: "Send failed.");
    *status = eBugReportUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 3;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100030A0
// Name: private: bool CWin32UploadBugReport::SendUploadCommand(enum EBugReportUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadBugReport::SendUploadCommand(
        CWin32UploadBugReport *this,
        EBugReportUploadStatus *status,
        CUtlBuffer *buf)
{
  int m_Put; // eax
  unsigned int m_ContextID; // [esp-4h] [ebp-10h]
  unsigned int m_uAttachmentFileSize; // [esp-4h] [ebp-10h]

  UpdateProgress(params: this->m_rBugReportParameters, fmt: "Sending harvesting protocol upload request.");
  buf->m_Get = 0;
  buf->m_Put = 0;
  buf->m_nOffset = 0;
  buf->m_nMaxPut = 0;
  buf->m_Error = 0;
  if ( buf->m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf->m_Memory.m_pMemory);
      buf->m_Memory.m_pMemory = nullptr;
    }
    buf->m_Memory.m_nAllocationCount = 0;
  }
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 17);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 17);
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 1;
    CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
  }
  m_ContextID = this->m_ContextID;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_ContextID);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_ContextID);
  m_uAttachmentFileSize = this->m_rBugReportParameters->m_uAttachmentFileSize;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_uAttachmentFileSize);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_uAttachmentFileSize);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 0);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 0);
  if ( send(s: this->m_SocketTCP, buf: (const char *)buf->m_Memory.m_pMemory, len: buf->m_Put, flags: 0) == -1 )
  {
    UpdateProgress(params: this->m_rBugReportParameters, fmt: "Send failed.");
    *status = eBugReportUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 5;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003230
// Name: private: bool CWin32UploadBugReport::SendGracefulClose(enum EBugReportUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadBugReport::SendGracefulClose(
        CWin32UploadBugReport *this,
        EBugReportUploadStatus *status,
        CUtlBuffer *buf)
{
  int m_Put; // eax

  UpdateProgress(params: this->m_rBugReportParameters, fmt: "Closing connection to server.");
  buf->m_Get = 0;
  buf->m_Put = 0;
  buf->m_nOffset = 0;
  buf->m_nMaxPut = 0;
  buf->m_Error = 0;
  if ( buf->m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf->m_Memory.m_pMemory);
      buf->m_Memory.m_pMemory = nullptr;
    }
    buf->m_Memory.m_nAllocationCount = 0;
  }
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 1);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 1);
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
  }
  if ( send(s: this->m_SocketTCP, buf: (const char *)buf->m_Memory.m_pMemory, len: buf->m_Put, flags: 0) == -1 )
  {
    UpdateProgress(params: this->m_rBugReportParameters, fmt: "Send failed.");
    *status = eBugReportUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 9;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003330
// Name: public: CWin32UploadBugReport::CWin32UploadBugReport(struct netadr_s const __near &,struct TBugReportParameters const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CWin32UploadBugReport *__thiscall CWin32UploadBugReport::CWin32UploadBugReport(
        CWin32UploadBugReport *this,
        netadr_s *harvester,
        const TBugReportParameters *rBugReportParameters,
        unsigned int contextid)
{
  int m_Size; // [esp-8h] [ebp-18h]
  int v7; // [esp-8h] [ebp-18h]
  int v8; // [esp-8h] [ebp-18h]
  int v9; // [esp-8h] [ebp-18h]
  int v10; // [esp-8h] [ebp-18h]
  int v11; // [esp-8h] [ebp-18h]
  int v12; // [esp-8h] [ebp-18h]
  int v13; // [esp-8h] [ebp-18h]
  int v14; // [esp-8h] [ebp-18h]
  CWin32UploadBugReport::FSMState_t src; // [esp+8h] [ebp-8h] BYREF

  this->m_States.m_Memory.m_pMemory = nullptr;
  this->m_States.m_Memory.m_nAllocationCount = 0;
  this->m_States.m_Memory.m_nGrowSize = 0;
  this->m_States.m_Size = 0;
  this->m_States.m_pElements = nullptr;
  this->m_uCurrentState = 0;
  *(_QWORD *)&this->m_HarvesterSockAddr.sin_family = 0;
  *(_QWORD *)this->m_HarvesterSockAddr.sin_zero = 0;
  this->m_rBugReportParameters = rBugReportParameters;
  this->m_SocketTCP = 0;
  this->m_ContextID = contextid;
  netadr_s::ToSockadr(this: harvester, s: (sockaddr *)&this->m_HarvesterSockAddr);
  m_Size = this->m_States.m_Size;
  src.first = 0;
  src.second = (bool (__thiscall *)(CWin32UploadBugReport *, EBugReportUploadStatus *, CUtlBuffer *))CWin32UploadBugReport::CreateTCPSocket;
  CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
    this: &this->m_States,
    elem: m_Size,
    &src);
  v7 = this->m_States.m_Size;
  src.first = 1;
  src.second = (bool (__thiscall *)(CWin32UploadBugReport *, EBugReportUploadStatus *, CUtlBuffer *))CWin32UploadBugReport::ConnectToHarvesterServer;
  CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
    this: &this->m_States,
    elem: v7,
    &src);
  v8 = this->m_States.m_Size;
  src.first = 2;
  src.second = (bool (__thiscall *)(CWin32UploadBugReport *, EBugReportUploadStatus *, CUtlBuffer *))CWin32UploadBugReport::SendProtocolVersion;
  CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
    this: &this->m_States,
    elem: v8,
    &src);
  v9 = this->m_States.m_Size;
  src.first = 3;
  src.second = (bool (__thiscall *)(CWin32UploadBugReport *, EBugReportUploadStatus *, CUtlBuffer *))CWin32UploadBugReport::ReceiveProtocolOkay;
  CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
    this: &this->m_States,
    elem: v9,
    &src);
  v10 = this->m_States.m_Size;
  src.first = 4;
  src.second = (bool (__thiscall *)(CWin32UploadBugReport *, EBugReportUploadStatus *, CUtlBuffer *))CWin32UploadBugReport::SendUploadCommand;
  CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
    this: &this->m_States,
    elem: v10,
    &src);
  v11 = this->m_States.m_Size;
  src.first = 5;
  src.second = (bool (__thiscall *)(CWin32UploadBugReport *, EBugReportUploadStatus *, CUtlBuffer *))CWin32UploadBugReport::ReceiveOKToSendFile;
  CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
    this: &this->m_States,
    elem: v11,
    &src);
  v12 = this->m_States.m_Size;
  src.first = 6;
  src.second = (bool (__thiscall *)(CWin32UploadBugReport *, EBugReportUploadStatus *, CUtlBuffer *))CWin32UploadBugReport::SendWholeFile;
  CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
    this: &this->m_States,
    elem: v12,
    &src);
  src.first = 7;
  src.second = (bool (__thiscall *)(CWin32UploadBugReport *, EBugReportUploadStatus *, CUtlBuffer *))CWin32UploadBugReport::ReceiveFileUploadSuccess;
  CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
    this: &this->m_States,
    elem: this->m_States.m_Size,
    &src);
  v13 = this->m_States.m_Size;
  src.first = 8;
  src.second = (bool (__thiscall *)(CWin32UploadBugReport *, EBugReportUploadStatus *, CUtlBuffer *))CWin32UploadBugReport::SendGracefulClose;
  CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
    this: &this->m_States,
    elem: v13,
    &src);
  v14 = this->m_States.m_Size;
  src.first = 9;
  src.second = CWin32UploadBugReport::CloseTCPSocket;
  CUtlVector<CWin32UploadBugReport::FSMState_t,CUtlMemory<CWin32UploadBugReport::FSMState_t,int>>::InsertBefore(
    this: &this->m_States,
    elem: v14,
    &src);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100034A0
// Name: enum EBugReportUploadStatus Win32UploadBugReportBlocking(struct TBugReportParameters const __near &)
// Source: json
//------------------------------------------------------------------------------
EBugReportUploadStatus __cdecl Win32UploadBugReportBlocking(const TBugReportParameters *rBugReportParameters)
{
  unsigned __int8 *m_pMemory; // edx
  int m_Put; // eax
  int v4; // edi
  int i; // eax
  unsigned __int8 *v6; // edi
  unsigned int v7; // ebx
  int v9; // eax
  unsigned __int8 v10; // cl
  unsigned __int8 v11; // cl
  in_addr::<unnamed_type_S_un> v12; // edi
  u_short Short; // bx
  unsigned int timeOutInSeconds; // [esp+4h] [ebp-110h]
  unsigned int timeOutInSecondsa; // [esp+4h] [ebp-110h]
  unsigned int timeOutInSecondsb; // [esp+4h] [ebp-110h]
  unsigned int timeOutInSecondsc; // [esp+4h] [ebp-110h]
  unsigned int timeOutInSecondsd; // [esp+4h] [ebp-110h]
  unsigned int timeOutInSecondse; // [esp+4h] [ebp-110h]
  unsigned int timeOutInSecondsf; // [esp+4h] [ebp-110h]
  unsigned int timeOutInSecondsg; // [esp+4h] [ebp-110h]
  CWin32UploadBugReport uploader; // [esp+14h] [ebp-100h] BYREF
  sockaddr_in replyaddress; // [esp+48h] [ebp-CCh] BYREF
  sockaddr_in sa; // [esp+58h] [ebp-BCh] BYREF
  sockaddr_in adr; // [esp+68h] [ebp-ACh] BYREF
  netadr_s BugReportHarvesterFSMIPAddress; // [esp+78h] [ebp-9Ch] BYREF
  CBlockingUDPSocket bcs; // [esp+84h] [ebp-90h] BYREF
  IceKey cipher; // [esp+9Ch] [ebp-78h] BYREF
  EBugReportUploadStatus status; // [esp+A8h] [ebp-6Ch]
  unsigned __int8 ucEncryptionKey[8]; // [esp+ACh] [ebp-68h] BYREF
  CUtlBuffer buf; // [esp+B4h] [ebp-60h] BYREF
  CUtlBuffer encrypted; // [esp+E4h] [ebp-30h] BYREF
  int dumpcontext; // [esp+11Ch] [ebp+8h]

  status = eBugReportUploadFailed;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 2048, initSize: 0, nFlags: 0);
  UpdateProgress(params: rBugReportParameters, fmt: "Creating initial report.");
  CUtlBuffer::SetBigEndian(this: &buf, bigEndian: false);
  m_pMemory = buf.m_Memory.m_pMemory;
  m_Put = 0;
  memset(&buf.m_Get, 0, 9);
  buf.m_nOffset = 0;
  buf.m_nMaxPut = 0;
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      m_Put = buf.m_Put;
      m_pMemory = nullptr;
      buf.m_Memory.m_pMemory = nullptr;
    }
    buf.m_Memory.m_nAllocationCount = 0;
  }
  if ( (buf.m_Flags & 1) != 0 && m_Put != 0 && m_pMemory[m_Put - buf.m_nOffset - 1] == 10 )
    CUtlBuffer::PutTabs(this: &buf);
  if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
  {
    buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = 111;
    CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
  }
  if ( (buf.m_Flags & 1) != 0 && buf.m_Put != 0 && buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset - 1] == 10 )
    CUtlBuffer::PutTabs(this: &buf);
  if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
  {
    buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = 10;
    CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
  }
  if ( (buf.m_Flags & 1) != 0 && buf.m_Put != 0 && buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset - 1] == 10 )
    CUtlBuffer::PutTabs(this: &buf);
  if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
  {
    buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = 3;
    CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
  }
  IceKey::IceKey(this: &cipher, n: 1);
  *(_DWORD *)ucEncryptionKey = -1794469432;
  *(_DWORD *)&ucEncryptionKey[4] = -210977085;
  IceKey::set(this: &cipher, key: ucEncryptionKey);
  CUtlBuffer::CUtlBuffer(this: &encrypted, growSize: 2000, initSize: 0, nFlags: 0);
  if ( (encrypted.m_Flags & 1) != 0
    && encrypted.m_Put != 0
    && encrypted.m_Memory.m_pMemory[encrypted.m_Put - encrypted.m_nOffset - 1] == 10 )
  {
    CUtlBuffer::PutTabs(this: &encrypted);
  }
  if ( CUtlBuffer::CheckPut(this: &encrypted, nSize: 1) )
  {
    encrypted.m_Memory.m_pMemory[encrypted.m_Put - encrypted.m_nOffset] = 1;
    CUtlBuffer::AddNullTermination(this: &encrypted, nPut: ++encrypted.m_Put);
  }
  timeOutInSeconds = rBugReportParameters->m_uEngineBuildNumber;
  if ( (encrypted.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &encrypted, pFmt: "%d", timeOutInSeconds);
  else
    CUtlBuffer::PutTypeBin<int>(this: &encrypted, src: timeOutInSeconds);
  CUtlBuffer::PutString(this: &encrypted, pString: rBugReportParameters->m_sExecutableName);
  CUtlBuffer::PutString(this: &encrypted, pString: rBugReportParameters->m_sGameDirectory);
  CUtlBuffer::PutString(this: &encrypted, pString: rBugReportParameters->m_sMapName);
  timeOutInSecondsa = rBugReportParameters->m_uRAM;
  if ( (encrypted.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &encrypted, pFmt: "%d", timeOutInSecondsa);
  else
    CUtlBuffer::PutTypeBin<int>(this: &encrypted, src: timeOutInSecondsa);
  timeOutInSecondsb = rBugReportParameters->m_uCPU;
  if ( (encrypted.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &encrypted, pFmt: "%d", timeOutInSecondsb);
  else
    CUtlBuffer::PutTypeBin<int>(this: &encrypted, src: timeOutInSecondsb);
  CUtlBuffer::PutString(this: &encrypted, pString: rBugReportParameters->m_sProcessor);
  timeOutInSecondsc = rBugReportParameters->m_uDXVersionHigh;
  if ( (encrypted.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &encrypted, pFmt: "%d", timeOutInSecondsc);
  else
    CUtlBuffer::PutTypeBin<int>(this: &encrypted, src: timeOutInSecondsc);
  timeOutInSecondsd = rBugReportParameters->m_uDXVersionLow;
  if ( (encrypted.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &encrypted, pFmt: "%d", timeOutInSecondsd);
  else
    CUtlBuffer::PutTypeBin<int>(this: &encrypted, src: timeOutInSecondsd);
  timeOutInSecondse = rBugReportParameters->m_uDXVendorId;
  if ( (encrypted.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &encrypted, pFmt: "%d", timeOutInSecondse);
  else
    CUtlBuffer::PutTypeBin<int>(this: &encrypted, src: timeOutInSecondse);
  timeOutInSecondsf = rBugReportParameters->m_uDXDeviceId;
  if ( (encrypted.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &encrypted, pFmt: "%d", timeOutInSecondsf);
  else
    CUtlBuffer::PutTypeBin<int>(this: &encrypted, src: timeOutInSecondsf);
  CUtlBuffer::PutString(this: &encrypted, pString: rBugReportParameters->m_sOSVersion);
  timeOutInSecondsg = rBugReportParameters->m_uAttachmentFileSize;
  if ( (encrypted.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &encrypted, pFmt: "%d", timeOutInSecondsg);
  else
    CUtlBuffer::PutTypeBin<int>(this: &encrypted, src: timeOutInSecondsg);
  CUtlBuffer::PutString(this: &encrypted, pString: rBugReportParameters->m_sReportType);
  CUtlBuffer::PutString(this: &encrypted, pString: rBugReportParameters->m_sEmail);
  CUtlBuffer::PutString(this: &encrypted, pString: rBugReportParameters->m_sAccountName);
  CUtlBuffer::Put(this: &encrypted, pMem: &rBugReportParameters->m_userid, size: 16);
  CUtlBuffer::PutString(this: &encrypted, pString: rBugReportParameters->m_sTitle);
  v4 = _V_strlen(str: rBugReportParameters->m_sBody) + 1;
  if ( (encrypted.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &encrypted, pFmt: "%d", v4);
  else
    CUtlBuffer::PutTypeBin<int>(this: &encrypted, src: v4);
  CUtlBuffer::Put(this: &encrypted, pMem: rBugReportParameters->m_sBody, size: v4);
  for ( i = encrypted.m_Put; encrypted.m_Put % 8 != 0; i = encrypted.m_Put )
  {
    if ( (encrypted.m_Flags & 1) != 0 && i != 0 && encrypted.m_Memory.m_pMemory[i - encrypted.m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: &encrypted);
    if ( CUtlBuffer::CheckPut(this: &encrypted, nSize: 1) )
    {
      encrypted.m_Memory.m_pMemory[encrypted.m_Put - encrypted.m_nOffset] = 0;
      CUtlBuffer::AddNullTermination(this: &encrypted, nPut: ++encrypted.m_Put);
    }
  }
  v6 = encrypted.m_Memory.m_pMemory;
  if ( i != 0 )
  {
    v7 = ((unsigned int)(i - 1) >> 3) + 1;
    do
    {
      IceKey::encrypt(this: &cipher, ptext: v6, ctext: v6);
      v6 += 8;
      --v7;
    }
    while ( v7 != 0 );
    LOWORD(i) = encrypted.m_Put;
  }
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%hd", (__int16)i);
  else
    CUtlBuffer::PutTypeBin<short>(this: &buf, src: i);
  CUtlBuffer::Put(this: &buf, pMem: encrypted.m_Memory.m_pMemory, size: encrypted.m_Put);
  CBlockingUDPSocket::CBlockingUDPSocket(this: &bcs);
  if ( bcs.m_Socket != 0 )
  {
    netadr_s::ToSockadr(this: &rBugReportParameters->m_ipCSERServer, s: (sockaddr *)&sa);
    UpdateProgress(params: rBugReportParameters, fmt: "Sending bug report to server.");
    CBlockingUDPSocket::SendSocketMessage(this: &bcs, rRecipient: &sa, buf: buf.m_Memory.m_pMemory, bufsize: buf.m_Put);
    UpdateProgress(params: rBugReportParameters, fmt: "Waiting for response.");
    if ( CBlockingUDPSocket::WaitForMessage(this: &bcs, timeOutInSeconds: 2.0) )
    {
      UpdateProgress(params: rBugReportParameters, fmt: "Received response.");
      CUtlBuffer::EnsureCapacity(this: &buf, num: 2048);
      v9 = CBlockingUDPSocket::ReceiveSocketMessage(
             this: &bcs,
             packet_from: (int)&replyaddress,
             buf: buf.m_Memory.m_pMemory,
             bufsize: 0x800u);
      if ( v9 != 0 )
      {
        CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v9);
        UpdateProgress(params: rBugReportParameters, fmt: "Checking response.");
        if ( !CUtlBuffer::CheckGet(this: &buf, nSize: 1)
          || (v10 = buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset], ++buf.m_Get, v10 != 112) )
        {
          UpdateProgress(params: rBugReportParameters, fmt: "Request denied, invalid message type.");
          CBlockingUDPSocket::~CBlockingUDPSocket(this: &bcs);
          CUtlBuffer::~CUtlBuffer(this: &encrypted);
          IceKey::~IceKey(this: &cipher);
          CUtlBuffer::~CUtlBuffer(this: &buf);
          return eBugReportSendingBugReportHeaderFailed;
        }
        if ( !CUtlBuffer::CheckGet(this: &buf, nSize: 1)
          || (v11 = buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset], ++buf.m_Get, v11 != 1) )
        {
          UpdateProgress(params: rBugReportParameters, fmt: "Request denied, invalid message protocol.");
          CBlockingUDPSocket::~CBlockingUDPSocket(this: &bcs);
          CUtlBuffer::~CUtlBuffer(this: &encrypted);
          IceKey::~IceKey(this: &cipher);
          CUtlBuffer::~CUtlBuffer(this: &buf);
          return eBugReportSendingBugReportHeaderFailed;
        }
        if ( CUtlBuffer::GetChar(this: &buf) != 2 )
        {
          if ( rBugReportParameters->m_uAttachmentFileSize != 0 )
            UpdateProgress(
              params: rBugReportParameters,
              fmt: "Bug report accepted, attachment rejected (server too busy)");
          else
            UpdateProgress(params: rBugReportParameters, fmt: "Bug report accepted.");
          CBlockingUDPSocket::~CBlockingUDPSocket(this: &bcs);
          CUtlBuffer::~CUtlBuffer(this: &encrypted);
          IceKey::~IceKey(this: &cipher);
          CUtlBuffer::~CUtlBuffer(this: &buf);
          return eBugReportUploadSucceeded;
        }
        v12.S_addr = CUtlBuffer::GetInt(this: &buf);
        Short = CUtlBuffer::GetShort(this: &buf);
        dumpcontext = CUtlBuffer::GetInt(this: &buf);
        adr.sin_family = 2;
        adr.sin_port = htons(hostshort: Short);
        adr.sin_addr.S_un = v12;
        netadr_s::netadr_s(this: &BugReportHarvesterFSMIPAddress);
        netadr_s::SetFromSockadr(this: &BugReportHarvesterFSMIPAddress, s: (const sockaddr *)&adr);
        UpdateProgress(params: rBugReportParameters, fmt: "Server requested bug report upload.");
        CWin32UploadBugReport::CWin32UploadBugReport(
          this: &uploader,
          harvester: &BugReportHarvesterFSMIPAddress,
          rBugReportParameters,
          contextid: dumpcontext);
        status = CWin32UploadBugReport::Upload(this: &uploader, &buf);
        CWin32UploadBugReport::~CWin32UploadBugReport(this: &uploader);
      }
    }
    else
    {
      UpdateProgress(params: rBugReportParameters, fmt: "No response from server.");
    }
    CBlockingUDPSocket::~CBlockingUDPSocket(this: &bcs);
    if ( encrypted.m_Memory.m_nGrowSize >= 0 )
    {
      if ( encrypted.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: encrypted.m_Memory.m_pMemory);
        encrypted.m_Memory.m_pMemory = nullptr;
      }
      encrypted.m_Memory.m_nAllocationCount = 0;
    }
    IceKey::~IceKey(this: &cipher);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return status;
  }
  else
  {
    CBlockingUDPSocket::~CBlockingUDPSocket(this: &bcs);
    if ( encrypted.m_Memory.m_nGrowSize >= 0 )
    {
      if ( encrypted.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: encrypted.m_Memory.m_pMemory);
        encrypted.m_Memory.m_pMemory = nullptr;
      }
      encrypted.m_Memory.m_nAllocationCount = 0;
    }
    IceKey::~IceKey(this: &cipher);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return eBugReportUploadFailed;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003CB0
// Name: bool UploadBugReport(struct netadr_s const __near &,struct TSteamGlobalUserID const __near &,int,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,int,int,char const __near *,unsigned int,unsigned int,unsigned int,unsigned int,char const __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UploadBugReport(
        const netadr_s *cserIP,
        const TSteamGlobalUserID *userid,
        unsigned int build,
        const char *title,
        const char *body,
        const char *exename,
        const char *gamedir,
        const char *mapname,
        const char *reporttype,
        const char *email,
        const char *accountname,
        unsigned int ram,
        unsigned int cpu,
        const char *processor,
        unsigned int high,
        unsigned int low,
        unsigned int vendor,
        unsigned int device,
        const char *osversion,
        const char *attachedfile,
        unsigned int attachedfilesize)
{
  int v21; // ecx
  TSteamGlobalUserID::<unnamed_type_m_SteamLocalUserID> v22; // xmm0_8
  TBugReportParameters params; // [esp+0h] [ebp-780h] BYREF

  netadr_s::SetIP(this: &params.m_ipCSERServer, unIP: 0);
  netadr_s::SetPort(this: &params.m_ipCSERServer, newport: 0);
  netadr_s::SetType(this: &params.m_ipCSERServer, newtype: NA_IP);
  _V_memset(dest: (void *)&params, fill: 0, count: 1920);
  v21 = *(_DWORD *)&cserIP->port;
  *(_QWORD *)&params.m_ipCSERServer.type = *(_QWORD *)&cserIP->type;
  *(_QWORD *)&params.m_userid.m_SteamInstanceID = *(_QWORD *)&userid->m_SteamInstanceID;
  v22.As64bits = (unsigned __int64)userid->m_SteamLocalUserID;
  *(_DWORD *)&params.m_ipCSERServer.port = v21;
  params.m_userid.m_SteamLocalUserID = v22;
  params.m_uEngineBuildNumber = build;
  V_strncpy(pDest: params.m_sExecutableName, pSrc: exename, maxLen: 64);
  V_strncpy(pDest: params.m_sGameDirectory, pSrc: gamedir, maxLen: 64);
  V_strncpy(pDest: params.m_sMapName, pSrc: mapname, maxLen: 64);
  params.m_uRAM = ram;
  params.m_uCPU = cpu;
  V_strncpy(pDest: params.m_sProcessor, pSrc: processor, maxLen: 128);
  params.m_uDXVersionLow = low;
  params.m_uDXVendorId = vendor;
  params.m_uDXVersionHigh = high;
  params.m_uDXDeviceId = device;
  V_strncpy(pDest: params.m_sOSVersion, pSrc: osversion, maxLen: 64);
  V_strncpy(pDest: params.m_sReportType, pSrc: reporttype, maxLen: 40);
  V_strncpy(pDest: params.m_sEmail, pSrc: email, maxLen: 80);
  V_strncpy(pDest: params.m_sAccountName, pSrc: accountname, maxLen: 64);
  V_strncpy(pDest: params.m_sTitle, pSrc: title, maxLen: 128);
  V_strncpy(pDest: params.m_sBody, pSrc: body, maxLen: 1024);
  V_strncpy(pDest: params.m_sAttachmentFile, pSrc: attachedfile, maxLen: 128);
  params.m_uAttachmentFileSize = attachedfilesize;
  params.m_uProgressContext = 1;
  params.m_pOptionalProgressFunc = (void (__cdecl *)(unsigned int, const TBugReportProgress *))_heap_term;
  return Win32UploadBugReportBlocking(rBugReportParameters: &params) == eBugReportUploadSucceeded;
}
