// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_filesystem_master.cpp
// Functions: 46
// ============================================================

#include "utils\vmpi\vmpi_filesystem_master.h"

//------------------------------------------------------------------------------
// Address: 0x10009820
// Name: public: void CUtlMemory<class CTransmitRateMgr::CMachineRecord,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
        CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CTransmitRateMgr::CMachineRecord *m_pMemory; // edx
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
      this->m_pMemory = (CTransmitRateMgr::CMachineRecord *)_g_pMemAlloc->Realloc_2(
                                                              this: _g_pMemAlloc,
                                                              a2: m_pMemory,
                                                              a3: v7);
    else
      this->m_pMemory = (CTransmitRateMgr::CMachineRecord *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028930
// Name: public: virtual class CSysModule __near * CMasterVMPIFileSystem::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CMasterVMPIFileSystem::LoadModule(
        CMasterVMPIFileSystem *this,
        const char *pFileName,
        const char *pPathID,
        BOOL bValidatedDllOnly)
{
  return this->m_pMasterVMPIFileSystemPassThru->LoadModule(
           this: this->m_pMasterVMPIFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: bValidatedDllOnly);
}

//------------------------------------------------------------------------------
// Address: 0x10028950
// Name: public: virtual void CMasterVMPIFileSystem::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::UnloadModule(CMasterVMPIFileSystem *this, struct CSysModule *pModule)
{
  this->m_pMasterVMPIFileSystemPassThru->UnloadModule(this: this->m_pMasterVMPIFileSystemPassThru, a2: pModule);
}

//------------------------------------------------------------------------------
// Address: 0x10028970
// Name: public: void CRateLimiter::NoteExcessTimeTaken(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRateLimiter::NoteExcessTimeTaken(CRateLimiter *this, unsigned int excessTimeInMicroseconds)
{
  unsigned int m_AccumulatedSleepMicroseconds; // eax
  unsigned int v3; // esi
  unsigned __int64 v4; // [esp-Ch] [ebp-20h]
  CCycleCount startCount; // [esp+Ch] [ebp-8h]

  m_AccumulatedSleepMicroseconds = this->m_AccumulatedSleepMicroseconds;
  if ( excessTimeInMicroseconds <= m_AccumulatedSleepMicroseconds )
  {
    this->m_AccumulatedSleepMicroseconds = m_AccumulatedSleepMicroseconds - excessTimeInMicroseconds;
  }
  else
  {
    v3 = excessTimeInMicroseconds - m_AccumulatedSleepMicroseconds;
    this->m_AccumulatedSleepMicroseconds = 0;
    startCount.m_Int64 = __rdtsc();
    do
    {
      HIDWORD(v4) = HIDWORD(_g_ClockSpeed);
      LODWORD(v4) = _g_ClockSpeed;
    }
    while ( (unsigned int)(1000000 * (__rdtsc() - startCount.m_Int64) / v4) < v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028A10
// Name: public: virtual void CVMPIFile_PassThru::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Close(CVMPIFile_PassThru *this)
{
  this->m_pPassThru->Close(this: this->m_pPassThru, a2: this->m_fp);
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x10028A30
// Name: public: virtual void CVMPIFile_PassThru::Seek(int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Seek(CVMPIFile_PassThru *this, int pos, FileSystemSeek_t seekType)
{
  this->m_pPassThru->Seek(this: this->m_pPassThru, a2: this->m_fp, a3: pos, a4: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x10028A60
// Name: public: virtual unsigned int CVMPIFile_PassThru::Tell(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_PassThru::Tell(CVMPIFile_PassThru *this)
{
  return this->m_pPassThru->Tell(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10028A80
// Name: public: virtual unsigned int CVMPIFile_PassThru::Size(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_PassThru::Size(CVMPIFile_PassThru *this)
{
  return this->m_pPassThru->Size_2(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10028AA0
// Name: public: virtual void CVMPIFile_PassThru::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Flush(CVMPIFile_PassThru *this)
{
  this->m_pPassThru->Flush(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10028AC0
// Name: public: virtual int CVMPIFile_PassThru::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_PassThru::Read(CVMPIFile_PassThru *this, void *pOutput, int size)
{
  return this->m_pPassThru->Read(this: this->m_pPassThru, a2: pOutput, a3: size, a4: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10028AE0
// Name: public: virtual int CVMPIFile_PassThru::Write(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_PassThru::Write(CVMPIFile_PassThru *this, const void *pInput, int size)
{
  return this->m_pPassThru->Write(this: this->m_pPassThru, a2: pInput, a3: size, a4: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10028B00
// Name: public: void CRateLimiter::GiveUpTimeSlice(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRateLimiter::GiveUpTimeSlice(CRateLimiter *this)
{
  CCycleCount *p_m_LastSleepTime; // edi
  unsigned __int64 v3; // [esp-Ch] [ebp-30h]
  unsigned __int64 v4; // [esp-Ch] [ebp-30h]
  unsigned __int64 v5; // [esp+8h] [ebp-1Ch] BYREF
  CFastTimer sleepTimer; // [esp+10h] [ebp-14h] BYREF
  CCycleCount currentTime; // [esp+18h] [ebp-Ch] BYREF
  CFastTimer *p_currentTime; // [esp+20h] [ebp-4h]

  p_currentTime = (CFastTimer *)&currentTime;
  currentTime.m_Int64 = __rdtsc();
  p_m_LastSleepTime = &this->m_LastSleepTime;
  HIDWORD(v3) = HIDWORD(_g_ClockSpeed);
  LODWORD(v3) = _g_ClockSpeed;
  if ( (unsigned int)(1000 * (currentTime.m_Int64 - this->m_LastSleepTime.m_Int64) / v3) >= this->m_SleepIntervalMS )
  {
    p_currentTime = &sleepTimer;
    sleepTimer.m_Duration.m_Int64 = __rdtsc();
    Sleep(dwMilliseconds: 0xAu);
    p_currentTime = (CFastTimer *)&v5;
    v5 = __rdtsc();
    sleepTimer.m_Duration.m_Int64 = v5 - sleepTimer.m_Duration.m_Int64;
    HIDWORD(v4) = HIDWORD(_g_ClockSpeed);
    LODWORD(v4) = _g_ClockSpeed;
    this->m_AccumulatedSleepMicroseconds += 1000000 * sleepTimer.m_Duration.m_Int64 / v4;
    p_m_LastSleepTime->m_Int64 = __rdtsc();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028BE0
// Name: private: void CMasterMulticastThread::TCP_SendNextChunk(class CMasterMulticastThread::CMulticastFile __near *,class CMasterMulticastThread::CClientFileInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::TCP_SendNextChunk(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pFile,
        CMasterMulticastThread::CClientFileInfo *pClient)
{
  CMasterMulticastThread::CMulticastFile *v3; // edx
  CMasterMulticastThread::CClientFileInfo *v4; // ebx
  int v5; // eax
  int v6; // ecx
  int m_Size; // edi
  int v8; // esi
  char *m_pMemory; // eax
  char *v10; // edx
  int m_ClientID; // [esp-10h] [ebp-3Ch]
  const void *chunks[5]; // [esp+4h] [ebp-28h] BYREF
  int chunkLengths[5]; // [esp+18h] [ebp-14h] BYREF

  v3 = pFile;
  v4 = pClient;
  v5 = pClient->m_TCP_LastChunkSent + 1;
  if ( v5 < pFile->m_Info.m_nChunks )
  {
    v6 = v5 << 14;
    m_Size = pFile->m_Data.m_Size;
    v8 = (v5 << 14) + 0x4000;
    pFile = (CMasterMulticastThread::CMulticastFile *)(pClient->m_TCP_LastChunkSent + 1);
    if ( v8 >= m_Size )
      v8 = m_Size;
    if ( v6 < m_Size )
    {
      pClient->m_TCP_LastChunkSent = v5;
      chunks[0] = &pClient;
      chunks[1] = &v3->m_Info;
      chunks[2] = &pFile;
      m_pMemory = v3->m_Filename.m_Memory.m_pMemory;
      v10 = v3->m_Data.m_Memory.m_pMemory;
      LOWORD(pClient) = 1536;
      chunks[3] = m_pMemory;
      chunks[4] = &v10[v6];
      chunkLengths[0] = 2;
      chunkLengths[1] = 12;
      chunkLengths[2] = 4;
      chunkLengths[3] = strlen(m_pMemory) + 1;
      m_ClientID = v4->m_ClientID;
      chunkLengths[4] = v8 - v6;
      VMPI_SendChunks(pChunks: chunks, pChunkLengths: chunkLengths, nChunks: 5, iDest: m_ClientID, fVMPISendFlags: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028CA0
// Name: private: bool CMasterMulticastThread::Thread_SendFileChunk_Multicast(int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMasterMulticastThread::Thread_SendFileChunk_Multicast(
        CMasterMulticastThread *this,
        unsigned int *pnBytesSent)
{
  CMasterMulticastThread::CMulticastFile *m_Element; // ecx
  volatile int v4; // edx
  int m_Size; // edi
  unsigned int v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned int v8; // eax
  int v9; // edi
  bool v10; // zf
  unsigned int v11; // eax
  int v13; // ecx
  DWORD LastError; // eax
  char dst[8192]; // [esp+Ch] [ebp-202Ch] BYREF
  _WSABUF count; // [esp+200Ch] [ebp-2Ch] BYREF
  unsigned int v17; // [esp+2014h] [ebp-24h]
  unsigned __int8 *p_m_iCurActiveChunk; // [esp+2018h] [ebp-20h]
  unsigned int v19; // [esp+201Ch] [ebp-1Ch]
  unsigned __int8 *m_pMemory; // [esp+2020h] [ebp-18h]
  unsigned int v21; // [esp+2024h] [ebp-14h]
  unsigned __int8 *v22; // [esp+2028h] [ebp-10h]
  char Buffer[4]; // [esp+202Ch] [ebp-Ch] BYREF
  unsigned int NumberOfBytesSent; // [esp+2030h] [ebp-8h] BYREF
  int len; // [esp+2034h] [ebp-4h]

  m_Element = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element;
  v4 = this->m_iCurActiveChunk << 10;
  m_Size = m_Element->m_Data.m_Size;
  len = v4 + 1024;
  if ( v4 + 1024 >= m_Size )
    len = m_Size;
  count.buf = (char *)&m_Element->m_Info;
  count.len = 12;
  p_m_iCurActiveChunk = (unsigned __int8 *)&this->m_iCurActiveChunk;
  v17 = 4;
  m_pMemory = (unsigned __int8 *)m_Element->m_Filename.m_Memory.m_pMemory;
  v6 = strlen(m_Element->m_Filename.m_Memory.m_pMemory) + 1;
  v19 = v6;
  v7 = (unsigned __int8 *)&m_Element->m_Data.m_Memory.m_pMemory[v4];
  v10 = this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b1 == 127;
  v21 = len - v4;
  v8 = len - v4 + v6 + 16;
  v22 = v7;
  NumberOfBytesSent = 0;
  len = v8;
  if ( !v10
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b2 != 0
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b3 != 0
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b4 != 1 )
  {
    WSASendTo(
      s: this->m_Socket,
      lpBuffers: &count,
      dwBufferCount: 4u,
      lpNumberOfBytesSent: &NumberOfBytesSent,
      dwFlags: 0,
      lpTo: (const struct sockaddr *)&this->m_MulticastAddr,
      iTolen: 16,
      lpOverlapped: nullptr,
      lpCompletionRoutine: nullptr);
    v11 = NumberOfBytesSent;
    v10 = NumberOfBytesSent == len;
    v9 = len;
  }
  else
  {
    if ( v8 > 0x2000 )
    {
      _Error(a1: "nWantedBytes > sizeof( allData )");
      v7 = v22;
      v6 = v19;
    }
    memcpy((unsigned __int8 *)dst, src: (unsigned __int8 *)count.buf, count: count.len);
    memcpy(dst: (unsigned __int8 *)&dst[count.len], src: p_m_iCurActiveChunk, count: v17);
    memcpy(dst: (unsigned __int8 *)&dst[count.len + v17], src: m_pMemory, count: v6);
    memcpy(dst: (unsigned __int8 *)&dst[count.len + v17 + v6], src: v7, count: v21);
    v9 = len;
    v10 = sendto(
            s: this->m_Socket,
            buf: dst,
            len,
            flags: 0,
            to: (const struct sockaddr *)&this->m_MulticastAddr,
            tolen: 16) == v9;
    v11 = NumberOfBytesSent;
  }
  if ( v10 )
  {
    *pnBytesSent = v11;
    return v10;
  }
  v13 = `CMasterMulticastThread::Thread_SendFileChunk_Multicast'::`14'::nWarnings + 1;
  `CMasterMulticastThread::Thread_SendFileChunk_Multicast'::`14'::nWarnings = v13;
  if ( v13 >= 10 )
  {
    if ( v13 == 10 )
      _Warning(a1: "\nThis machine's ability to multicast may be broken. Please reboot and try again.\n");
  }
  else
  {
    _Warning(a1: "\nMulticastThread: WSASendTo with %d bytes sent %d bytes.\n", v9, v11);
    LastError = GetLastError();
    if ( FormatMessageA(
           dwFlags: 0x1300u,
           lpSource: nullptr,
           dwMessageId: LastError,
           dwLanguageId: 0x400u,
           lpBuffer: Buffer,
           nSize: 0,
           Arguments: nullptr) != 0 )
    {
      _Warning(a1: "%s", *(const char **)Buffer);
      LocalFree(hMem: *(HLOCAL *)Buffer);
      return false;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100292B0
// Name: private: int CMasterMulticastThread::FindFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FindFile(CMasterMulticastThread *this, const char *pName, const char *pPathID)
{
  int m_Head; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  CMasterMulticastThread *v6; // [esp+Ch] [ebp-4h]

  m_Head = this->m_Files.m_Head;
  v6 = this;
  if ( m_Head == -1 )
    return -1;
  while ( 1 )
  {
    m_Element = this->m_Files.m_Memory.m_pMemory[m_Head].m_Element;
    if ( _V_stricmp(s1: m_Element->m_Filename.m_Memory.m_pMemory, s2: pName) == 0
      && _V_stricmp(s1: m_Element->m_PathID.m_Memory.m_pMemory, s2: pPathID) == 0 )
    {
      break;
    }
    m_Head = v6->m_Files.m_Memory.m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      return -1;
    this = v6;
  }
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x10029330
// Name: private: void CMasterMulticastThread::EnsureMemoryLimit(class CMasterMulticastThread::CMulticastFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::EnsureMemoryLimit(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pIgnore)
{
  unsigned int m_nMaxMemoryUsage; // eax
  int i; // eax
  int v5; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // esi

  m_nMaxMemoryUsage = this->m_nMaxMemoryUsage;
  if ( m_nMaxMemoryUsage != 0 && this->m_nCurMemoryUsage > m_nMaxMemoryUsage )
  {
    for ( i = this->m_Files.m_Head; i != -1; i = this->m_Files.m_Memory.m_pMemory[v5].m_Next )
    {
      v5 = i;
      m_Element = this->m_Files.m_Memory.m_pMemory[i].m_Element;
      if ( m_Element != pIgnore && m_Element->m_bDataLoaded && m_Element->m_ActiveChunks.m_ElementCount == 0 )
      {
        this->m_nCurMemoryUsage -= m_Element->m_Info.m_CompressedSize + m_Element->m_Info.m_UncompressedSize;
        CUtlVector<char,CUtlMemory<char,int>>::Purge(this: &m_Element->m_Data);
        CUtlVector<char,CUtlMemory<char,int>>::Purge(this: &m_Element->m_UncompressedData);
        m_Element->m_bDataLoaded = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029420
// Name: public: CTransmitRateMgr::CTransmitRateMgr(void)
// Source: json
//------------------------------------------------------------------------------
CTransmitRateMgr *__thiscall CTransmitRateMgr::CTransmitRateMgr(CTransmitRateMgr *this)
{
  long double v2; // xmm1_8
  ISocket *IPSocket; // eax
  unsigned __int64 v5; // [esp-14h] [ebp-20h]
  CCycleCount cnt; // [esp+0h] [ebp-Ch] BYREF
  CCycleCount *p_cnt; // [esp+8h] [ebp-4h]

  this->m_MachineRecords.m_Memory.m_pMemory = nullptr;
  this->m_MachineRecords.m_Memory.m_nAllocationCount = 0;
  this->m_MachineRecords.m_Memory.m_nGrowSize = 0;
  this->m_MachineRecords.m_Size = 0;
  this->m_MachineRecords.m_pElements = nullptr;
  v2 = 1000000.0 / (double)MULTICAST_TRANSMIT_RATE;
  this->m_flLastBroadcastTime = 0.0;
  this->m_nMicrosecondsPerByte = v2;
  this->m_UniqueID = (unsigned int)this;
  p_cnt = &cnt;
  cnt.m_Int64 = __rdtsc();
  HIDWORD(v5) = HIDWORD(_g_ClockSpeed);
  LODWORD(v5) = _g_ClockSpeed;
  this->m_UniqueID += 1000000 * cnt.m_Int64 / v5;
  Sleep(dwMilliseconds: 1u);
  HIDWORD(v5) = HIDWORD(_g_ClockSpeed);
  LODWORD(v5) = _g_ClockSpeed;
  this->m_UniqueID += 1000000 * cnt.m_Int64 / v5;
  IPSocket = CreateIPSocket();
  this->m_pSocket = IPSocket;
  if ( IPSocket != nullptr )
    IPSocket->BindToAny(this: IPSocket, a2: 21146u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10029500
// Name: public: CMasterMulticastThread::CMasterMulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
CMasterMulticastThread *__thiscall CMasterMulticastThread::CMasterMulticastThread(CMasterMulticastThread *this)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *m_pMemory; // ecx
  UtlLinkedListElem_t<char *,int> *v3; // edx

  this->m_Files.m_Memory.m_pMemory = nullptr;
  this->m_Files.m_Memory.m_nAllocationCount = 0;
  this->m_Files.m_Memory.m_nGrowSize = 0;
  this->m_Files.m_LastAlloc.index = -1;
  m_pMemory = this->m_Files.m_Memory.m_pMemory;
  this->m_Files.m_Head = -1;
  this->m_Files.m_Tail = -1;
  this->m_Files.m_FirstFree = -1;
  this->m_Files.m_ElementCount = 0;
  this->m_Files.m_NumAlloced = 0;
  this->m_Files.m_pElements = m_pMemory;
  this->m_WarningSuppressions.m_Memory.m_pMemory = nullptr;
  this->m_WarningSuppressions.m_Memory.m_nAllocationCount = 0;
  this->m_WarningSuppressions.m_Memory.m_nGrowSize = 0;
  this->m_WarningSuppressions.m_LastAlloc.index = -1;
  v3 = this->m_WarningSuppressions.m_Memory.m_pMemory;
  this->m_WarningSuppressions.m_Head = -1;
  this->m_WarningSuppressions.m_Tail = -1;
  this->m_WarningSuppressions.m_FirstFree = -1;
  this->m_WarningSuppressions.m_ElementCount = 0;
  this->m_WarningSuppressions.m_NumAlloced = 0;
  this->m_WarningSuppressions.m_pElements = v3;
  this->m_hMainThread = nullptr;
  this->m_hThread = nullptr;
  this->m_Socket = -1;
  this->m_nTotalActiveChunks = 0;
  this->m_iCurActiveChunk = -1;
  this->m_iCurFile = -1;
  this->m_pPassThru = nullptr;
  this->m_hTermEvent = CreateEventA(
                         lpEventAttributes: nullptr,
                         bManualReset: false,
                         bInitialState: false,
                         lpName: nullptr);
  InitializeCriticalSection(lpCriticalSection: &this->m_CS);
  this->m_nMaxMemoryUsage = 0;
  this->m_nCurMemoryUsage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100295A0
// Name: public: CMasterMulticastThread::CMulticastFile::CMulticastFile(void)
// Source: json
//------------------------------------------------------------------------------
CMasterMulticastThread::CMulticastFile *__thiscall CMasterMulticastThread::CMulticastFile::CMulticastFile(
        CMasterMulticastThread::CMulticastFile *this)
{
  CMasterMulticastThread::CMulticastFile *result; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // ecx

  result = this;
  this->m_Filename.m_Memory.m_pMemory = nullptr;
  this->m_Filename.m_Memory.m_nAllocationCount = 0;
  this->m_Filename.m_Memory.m_nGrowSize = 0;
  this->m_Filename.m_Size = 0;
  this->m_Filename.m_pElements = nullptr;
  this->m_PathID.m_Memory.m_pMemory = nullptr;
  this->m_PathID.m_Memory.m_nAllocationCount = 0;
  this->m_PathID.m_Memory.m_nGrowSize = 0;
  this->m_PathID.m_Size = 0;
  this->m_PathID.m_pElements = nullptr;
  this->m_UncompressedData.m_Memory.m_pMemory = nullptr;
  this->m_UncompressedData.m_Memory.m_nAllocationCount = 0;
  this->m_UncompressedData.m_Memory.m_nGrowSize = 0;
  this->m_UncompressedData.m_Size = 0;
  this->m_UncompressedData.m_pElements = nullptr;
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_Chunks.m_Memory.m_pMemory = nullptr;
  this->m_Chunks.m_Memory.m_nAllocationCount = 0;
  this->m_Chunks.m_Memory.m_nGrowSize = 0;
  this->m_Chunks.m_Size = 0;
  this->m_Chunks.m_pElements = nullptr;
  this->m_ActiveChunks.m_Memory.m_pMemory = nullptr;
  this->m_ActiveChunks.m_Memory.m_nAllocationCount = 0;
  this->m_ActiveChunks.m_Memory.m_nGrowSize = 0;
  this->m_ActiveChunks.m_LastAlloc.index = -1;
  this->m_ActiveChunks.m_Head = -1;
  this->m_ActiveChunks.m_Tail = -1;
  this->m_ActiveChunks.m_FirstFree = -1;
  this->m_ActiveChunks.m_ElementCount = 0;
  this->m_ActiveChunks.m_NumAlloced = 0;
  this->m_ActiveChunks.m_pElements = this->m_ActiveChunks.m_Memory.m_pMemory;
  this->m_Clients.m_Memory.m_pMemory = nullptr;
  this->m_Clients.m_Memory.m_nAllocationCount = 0;
  this->m_Clients.m_Memory.m_nGrowSize = 0;
  this->m_Clients.m_LastAlloc.index = -1;
  this->m_Clients.m_ElementCount = 0;
  this->m_Clients.m_NumAlloced = 0;
  m_pMemory = this->m_Clients.m_Memory.m_pMemory;
  result->m_Clients.m_Head = -1;
  result->m_Clients.m_Tail = -1;
  result->m_Clients.m_FirstFree = -1;
  result->m_Clients.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100296C0
// Name: public: void CTransmitRateMgr::ReadPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransmitRateMgr::ReadPackets(CTransmitRateMgr *this)
{
  int i; // eax
  unsigned int v3; // ebx
  int v4; // eax
  bool v5; // zf
  CTransmitRateMgr::CMachineRecord *m_pMemory; // ecx
  int v7; // eax
  float v8; // xmm0_4
  int j; // edi
  char data[768]; // [esp+4h] [ebp-30Ch] BYREF
  CIPAddr ipFrom; // [esp+304h] [ebp-Ch] BYREF
  float flCurTime; // [esp+30Ch] [ebp-4h]

  if ( this->m_pSocket != nullptr )
  {
    flCurTime = _Plat_FloatTime();
    CIPAddr::CIPAddr(this: &ipFrom);
    for ( i = this->m_pSocket->RecvFrom(this: this->m_pSocket, a2: data, a3: 768, a4: &ipFrom);
          i != -1;
          i = this->m_pSocket->RecvFrom(this: this->m_pSocket, a2: data, a3: 768, a4: &ipFrom) )
    {
      if ( i == 10
        && *(_DWORD *)data == *(_DWORD *)s_cTransmitRateMgrPacket
        && s_cTransmitRateMgrPacket[4] == data[4]
        && s_cTransmitRateMgrPacket[5] == data[5] )
      {
        v3 = *(_DWORD *)&data[6];
        if ( *(_DWORD *)&data[6] != this->m_UniqueID )
        {
          v4 = 0;
          v5 = this->m_MachineRecords.m_Size == 0;
          if ( this->m_MachineRecords.m_Size > 0 )
          {
            m_pMemory = this->m_MachineRecords.m_Memory.m_pMemory;
            while ( m_pMemory->m_UniqueID != *(_DWORD *)&data[6] )
            {
              ++v4;
              ++m_pMemory;
              if ( v4 >= this->m_MachineRecords.m_Size )
                goto LABEL_14;
            }
            this->m_MachineRecords.m_Memory.m_pMemory[v4].m_flLastTime = flCurTime;
LABEL_14:
            v5 = v4 == this->m_MachineRecords.m_Size;
          }
          if ( v5 )
          {
            v7 = CUtlVector<CTransmitRateMgr::CMachineRecord,CUtlMemory<CTransmitRateMgr::CMachineRecord,int>>::AddToTail(this: &this->m_MachineRecords);
            v8 = flCurTime;
            this->m_MachineRecords.m_Memory.m_pMemory[v7].m_UniqueID = v3;
            this->m_MachineRecords.m_Memory.m_pMemory[v7].m_flLastTime = v8;
          }
        }
      }
      CIPAddr::CIPAddr(this: &ipFrom);
    }
    for ( j = 0; j < this->m_MachineRecords.m_Size; ++j )
    {
      if ( (float)(flCurTime - this->m_MachineRecords.m_Memory.m_pMemory[j].m_flLastTime) > 0.7 )
      {
        if ( this->m_MachineRecords.m_Size - j - 1 > 0 )
          _V_memmove(
            dest: &this->m_MachineRecords.m_Memory.m_pMemory[j],
            src: &this->m_MachineRecords.m_Memory.m_pMemory[j + 1],
            count: 8 * (this->m_MachineRecords.m_Size - j - 1));
        --this->m_MachineRecords.m_Size;
        --j;
      }
    }
    this->m_nMicrosecondsPerByte = 1000000.0 / (double)(MULTICAST_TRANSMIT_RATE / (this->m_MachineRecords.m_Size + 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029960
// Name: ZLibCompress
// Source: json
//------------------------------------------------------------------------------
char __usercall ZLibCompress@<al>(
        CUtlVector<char,CUtlMemory<char,int> > *out@<esi>,
        unsigned __int8 *pData,
        unsigned int len)
{
  int v3; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned int m_Size; // edx
  int v10; // ebx
  z_stream_s zs; // [esp+8h] [ebp-38h] BYREF

  v3 = len;
  if ( len != 0 )
  {
    memset(dst: (int)&zs, value: nullptr, count: sizeof(zs));
    if ( deflateInit_(a1: &zs, a2: 1, a3: "1.1.3", a4: 56) != 0 )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        out->m_Size = 0;
        if ( v3 != 0 )
        {
          m_nAllocationCount = out->m_Memory.m_nAllocationCount;
          if ( v3 > m_nAllocationCount )
            CUtlMemory<bool,int>::Grow(this: &out->m_Memory, num: v3 - m_nAllocationCount);
          out->m_Size += v3;
          m_pMemory = out->m_Memory.m_pMemory;
          v7 = out->m_Size - v3;
          out->m_pElements = out->m_Memory.m_pMemory;
          if ( v7 > 0 && v3 > 0 )
            _V_memmove(dest: &m_pMemory[v3], src: m_pMemory, count: v7);
        }
        v8 = (unsigned __int8 *)out->m_Memory.m_pMemory;
        zs.avail_in = len;
        zs.next_in = pData;
        m_Size = out->m_Size;
        zs.next_out = v8;
        zs.avail_out = m_Size;
        v10 = deflate(a1: &zs, a2: 4);
        deflateEnd(a1: &zs);
        if ( v10 == 1 )
          break;
        if ( v10 != 0 )
          return 0;
        v3 += 0x20000;
        memset(dst: (int)&zs, value: nullptr, count: sizeof(zs));
        if ( deflateInit_(a1: &zs, a2: 1, a3: "1.1.3", a4: 56) != 0 )
          return 0;
      }
      out->m_Size -= out->m_Size - zs.total_out;
      return 1;
    }
  }
  else
  {
    out->m_Size = 0;
    if ( out->m_Memory.m_nGrowSize >= 0 )
    {
      if ( out->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: out->m_Memory.m_pMemory);
        out->m_Memory.m_pMemory = nullptr;
      }
      out->m_Memory.m_nAllocationCount = 0;
    }
    out->m_pElements = out->m_Memory.m_pMemory;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029AC0
// Name: public: CMasterMulticastThread::CMulticastFile::~CMulticastFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::CMulticastFile::~CMulticastFile(CMasterMulticastThread::CMulticastFile *this)
{
  CUtlLinkedList<CMasterMulticastThread::CClientFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Clients);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Clients);
  if ( this->m_Clients.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Clients.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Clients.m_Memory.m_pMemory);
      this->m_Clients.m_Memory.m_pMemory = nullptr;
    }
    this->m_Clients.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_ActiveChunks);
  if ( this->m_ActiveChunks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ActiveChunks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ActiveChunks.m_Memory.m_pMemory);
      this->m_ActiveChunks.m_Memory.m_pMemory = nullptr;
    }
    this->m_ActiveChunks.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Chunks);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Data);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_UncompressedData);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_PathID);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Filename);
}

//------------------------------------------------------------------------------
// Address: 0x10029DE0
// Name: public: void CMasterMulticastThread::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::Term(CMasterMulticastThread *this)
{
  if ( this->m_hThread != nullptr )
  {
    SetEvent(hEvent: this->m_hTermEvent);
    WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  if ( this->m_Socket != -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  CUtlLinkedList<CMasterMulticastThread::CMulticastFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Files);
  this->m_nMaxMemoryUsage = 0;
  this->m_nCurMemoryUsage = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10029E40
// Name: private: void CMasterMulticastThread::DecrementChunkRefCount(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::DecrementChunkRefCount(CMasterMulticastThread *this, int iFile, int iChunk)
{
  int v4; // ecx
  CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *m_Element; // ebx
  int m_FirstFree; // edx
  bool v7; // zf
  int v8; // edi
  volatile int m_iCurFile; // edx
  int v10; // eax
  int v11; // edi
  unsigned __int16 v12; // ax

  v4 = iFile;
  m_Element = (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)this->m_Files.m_Memory.m_pMemory[iFile].m_Element;
  m_FirstFree = m_Element[2].m_FirstFree;
  v7 = *(_WORD *)(m_FirstFree + 6 * iChunk + 2) == 0;
  v8 = m_FirstFree + 6 * iChunk;
  iChunk = v8;
  if ( v7 )
  {
    _Error(a1: "CMasterMulticastThread::DecrementChunkRefCount - refcount already zero!\n");
    v4 = iFile;
  }
  v7 = (*(_WORD *)(v8 + 2))-- == 1;
  if ( v7 )
  {
    m_iCurFile = this->m_iCurFile;
    --this->m_nTotalActiveChunks;
    if ( v4 == m_iCurFile )
    {
      v10 = *(unsigned __int16 *)(iChunk + 4);
      if ( v10 == this->m_iCurActiveChunk )
        this->m_iCurActiveChunk = m_Element[3].m_Memory.m_pMemory[v10].m_Next;
    }
    v11 = *(unsigned __int16 *)(iChunk + 4);
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: m_Element + 3,
      elem: v11);
    m_Element[3].m_Memory.m_pMemory[v11].m_Next = m_Element[3].m_FirstFree;
    m_Element[3].m_FirstFree = v11;
    v12 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToTail(
            this: (CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int> > *)&m_Element[3],
            src: (CMasterMulticastThread::CChunkInfo **)&iChunk);
    *(_WORD *)(iChunk + 4) = v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029EF0
// Name: private: int CMasterMulticastThread::FinishFileSetup(class CMasterMulticastThread::CMulticastFile __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FinishFileSetup(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pFile,
        const char *pFilename,
        CMasterMulticastThread::CChunkInfo *pPathID,
        bool bFileAlreadyExisted)
{
  CMasterMulticastThread::CMulticastFile *v5; // edi
  CMasterMulticastThread *v6; // ebx
  unsigned int v8; // esi
  const char *v9; // ecx
  char *m_pMemory; // edx
  char v11; // al
  CMasterMulticastThread::CChunkInfo *v12; // ecx
  char *v13; // edx
  char m_iChunk; // al
  int v15; // ebx
  unsigned __int16 v16; // ax
  char *v17; // esi
  __int16 v18; // ax

  v5 = pFile;
  v6 = this;
  if ( ZLibCompress(
         out: &pFile->m_Data,
         pData: (unsigned __int8 *)pFile->m_UncompressedData.m_Memory.m_pMemory,
         len: pFile->m_UncompressedData.m_Size) != 0 )
  {
    v5->m_bDataLoaded = true;
    v8 = VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_TCP ? 1024 : 0x4000;
    if ( !bFileAlreadyExisted )
    {
      CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v5->m_Filename,
        size: strlen(pFilename) + 1);
      v9 = pFilename;
      m_pMemory = v5->m_Filename.m_Memory.m_pMemory;
      do
      {
        v11 = *v9;
        *m_pMemory++ = *v9++;
      }
      while ( v11 != 0 );
      CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v5->m_PathID,
        size: strlen((const char *)pPathID) + 1);
      v12 = pPathID;
      v13 = v5->m_PathID.m_Memory.m_pMemory;
      do
      {
        m_iChunk = v12->m_iChunk;
        *v13 = v12->m_iChunk;
        v12 = (CMasterMulticastThread::CChunkInfo *)((char *)v12 + 1);
        ++v13;
      }
      while ( m_iChunk != 0 );
      v15 = 0;
      v5->m_nCycles = 0;
      v5->m_Info.m_CompressedSize = v5->m_Data.m_Size;
      v5->m_Info.m_UncompressedSize = v5->m_UncompressedData.m_Size;
      v16 = v8 * ((v5->m_Info.m_CompressedSize + v8 - 1) / v8) / v8;
      v5->m_Info.m_nChunks = v16;
      v5->m_Chunks.m_Size = 0;
      CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::InsertMultipleBefore(
        this: &v5->m_Chunks,
        elem: 0,
        num: v16);
      if ( v5->m_Chunks.m_Size > 0 )
      {
        pFilename = nullptr;
        do
        {
          v17 = (char *)&pFilename[(unsigned int)v5->m_Chunks.m_Memory.m_pMemory];
          *(_WORD *)v17 = v15;
          pPathID = (CMasterMulticastThread::CChunkInfo *)v17;
          *((_WORD *)v17 + 1) = 0;
          v18 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToTail(
                  this: &v5->m_ActiveChunks,
                  src: &pPathID);
          pFilename += 6;
          ++v15;
          *((_WORD *)v17 + 2) = v18;
        }
        while ( v15 < v5->m_Chunks.m_Size );
      }
      EnterCriticalSection(lpCriticalSection: &this->m_CS);
      v6 = this;
    }
    v6->m_nCurMemoryUsage += v5->m_Info.m_CompressedSize + v5->m_Info.m_UncompressedSize;
    CMasterMulticastThread::EnsureMemoryLimit(this: v6, pIgnore: v5);
    if ( !bFileAlreadyExisted )
    {
      v5->m_Info.m_FileID = CUtlLinkedList<CMasterMulticastThread::CMulticastFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>>::AddToTail(
                              this: &v6->m_Files,
                              src: &pFile);
      LeaveCriticalSection(lpCriticalSection: &v6->m_CS);
    }
    return v5->m_Info.m_FileID;
  }
  else
  {
    CMasterMulticastThread::CMulticastFile::~CMulticastFile(this: v5);
    free(pMem: v5);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A080
// Name: public: virtual void CMasterVMPIFileSystem::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::Term(CMasterVMPIFileSystem *this)
{
  CMasterMulticastThread::Term(this: &this->m_MasterThread);
}

//------------------------------------------------------------------------------
// Address: 0x1002A090
// Name: public: CMasterMulticastThread::~CMasterMulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::~CMasterMulticastThread(CMasterMulticastThread *this)
{
  CMasterMulticastThread::Term(this);
  CloseHandle(hObject: this->m_hTermEvent);
  DeleteCriticalSection(lpCriticalSection: &this->m_CS);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_WarningSuppressions);
  if ( this->m_WarningSuppressions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WarningSuppressions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WarningSuppressions.m_Memory.m_pMemory);
      this->m_WarningSuppressions.m_Memory.m_pMemory = nullptr;
    }
    this->m_WarningSuppressions.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll((CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)this);
  if ( this->m_Files.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Files.m_Memory.m_pMemory);
      this->m_Files.m_Memory.m_pMemory = nullptr;
    }
    this->m_Files.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A120
// Name: public: void CMasterMulticastThread::OnChunkReceived(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnChunkReceived(
        CMasterMulticastThread *this,
        int fileID,
        int clientID,
        int iChunk)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v4; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  int m_Head; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // edx
  CMasterMulticastThread::CClientFileInfo *v8; // esi

  if ( fileID >= 0
    && fileID < this->m_Files.m_Memory.m_nAllocationCount
    && fileID <= this->m_Files.m_LastAlloc.index
    && ((v4 = &this->m_Files.m_Memory.m_pMemory[fileID])->m_Previous != fileID || v4->m_Next == fileID) )
  {
    m_Element = v4->m_Element;
    m_Head = v4->m_Element->m_Clients.m_Head;
    if ( m_Head != -1 )
    {
      m_pMemory = m_Element->m_Clients.m_Memory.m_pMemory;
      while ( m_pMemory[m_Head].m_Element->m_ClientID != clientID )
      {
        m_Head = m_pMemory[m_Head].m_Next;
        if ( m_Head == -1 )
          return;
      }
      v8 = m_pMemory[m_Head].m_Element;
      if ( v8 != nullptr )
      {
        if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
        {
          EnterCriticalSection(lpCriticalSection: &this->m_CS);
          CMasterMulticastThread::TCP_SendNextChunk(this, pFile: m_Element, pClient: v8);
          LeaveCriticalSection(lpCriticalSection: &this->m_CS);
        }
        else if ( iChunk >= 0 && iChunk < m_Element->m_Chunks.m_Size )
        {
          v8->m_ChunksToSend.m_Memory.m_pMemory[iChunk >> 3] &= ~(1 << (iChunk & 7));
          --v8->m_nChunksLeft;
          v8->m_flLastAckTime = _Plat_FloatTime();
          if ( v8->m_nChunksLeft == 0 && g_iVMPIVerboseLevel >= 2 )
            _Warning(a1: "Client %d got file %s\n", clientID, m_Element->m_Filename.m_Memory.m_pMemory);
          EnterCriticalSection(lpCriticalSection: &this->m_CS);
          CMasterMulticastThread::DecrementChunkRefCount(this, iFile: fileID, iChunk);
          LeaveCriticalSection(lpCriticalSection: &this->m_CS);
        }
        else
        {
          _Warning(
            a1: "CMasterMulticastThread::OnChunkReceived: invalid chunk index (%d) for file %s\n",
            iChunk,
            m_Element->m_Filename.m_Memory.m_pMemory);
        }
      }
    }
  }
  else
  {
    _Warning(a1: "CMasterMulticastThread::OnChunkReceived: invalid file (%d) from client %d\n", fileID, clientID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A280
// Name: public: void CMasterMulticastThread::OnFileReceived(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnFileReceived(CMasterMulticastThread *this, int fileID, int clientID)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v3; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  int v5; // esi
  CMasterMulticastThread *v6; // [esp+4h] [ebp-4h]

  v6 = this;
  if ( fileID >= 0
    && fileID < this->m_Files.m_Memory.m_nAllocationCount
    && fileID <= this->m_Files.m_LastAlloc.index
    && ((v3 = &this->m_Files.m_Memory.m_pMemory[fileID])->m_Previous != fileID || v3->m_Next == fileID) )
  {
    m_Element = v3->m_Element;
    v5 = 0;
    if ( v3->m_Element->m_Info.m_nChunks != 0 )
    {
      while ( 1 )
      {
        CMasterMulticastThread::OnChunkReceived(this, fileID, clientID, iChunk: v5++);
        if ( v5 >= m_Element->m_Info.m_nChunks )
          break;
        this = v6;
      }
    }
  }
  else
  {
    _Warning(a1: "CMasterMulticastThread::OnChunkReceived: invalid file (%d) from client %d\n", fileID, clientID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A300
// Name: public: void CMasterMulticastThread::OnClientDisconnect(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnClientDisconnect(
        CMasterMulticastThread *this,
        int clientID,
        bool bGrabCriticalSection)
{
  CMasterMulticastThread *v3; // edi
  int m_Head; // eax
  int v5; // ecx
  CMasterMulticastThread::CMulticastFile *m_Element; // edx
  int v7; // esi
  int v8; // eax
  _DWORD *v9; // edi
  int v10; // ebx
  bool v11; // sf
  void *v12; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // edi
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *v14; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  int v17; // [esp+4h] [ebp-10h]
  int iFile; // [esp+8h] [ebp-Ch]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+10h] [ebp-4h]

  v3 = this;
  if ( bGrabCriticalSection )
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
  m_Head = v3->m_Files.m_Head;
  iFile = m_Head;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      v5 = 12 * m_Head;
      m_Element = v3->m_Files.m_Memory.m_pMemory[m_Head].m_Element;
      v7 = m_Element->m_Clients.m_Head;
      v17 = 12 * m_Head;
      pFile = m_Element;
      if ( v7 != -1 )
      {
        while ( 1 )
        {
          v8 = (int)&m_Element->m_Clients.m_Memory.m_pMemory[v7];
          v9 = *(_DWORD **)v8;
          if ( **(_DWORD **)v8 == clientID )
            break;
          v7 = *(_DWORD *)(v8 + 8);
          if ( v7 == -1 )
            goto LABEL_34;
        }
        v10 = 0;
        if ( m_Element->m_Info.m_nChunks != 0 )
        {
          do
          {
            if ( ((unsigned __int8)(1 << (v10 & 7)) & *(_BYTE *)((v10 >> 3) + v9[1])) != 0 )
              CMasterMulticastThread::DecrementChunkRefCount(this, iFile, iChunk: v10);
            ++v10;
          }
          while ( v10 < pFile->m_Info.m_nChunks );
        }
        v11 = (int)v9[3] < 0;
        v9[4] = 0;
        if ( !v11 )
        {
          if ( v9[1] != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v9[1]);
            v9[1] = 0;
          }
          v9[2] = 0;
        }
        v11 = (int)v9[3] < 0;
        v12 = (void *)v9[1];
        v9[5] = v12;
        if ( !v11 )
        {
          if ( v12 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
            v9[1] = 0;
          }
          v9[2] = 0;
        }
        free(pMem: v9);
        if ( v7 >= 0 && v7 < pFile->m_Clients.m_Memory.m_nAllocationCount && v7 <= pFile->m_Clients.m_LastAlloc.index )
        {
          m_pMemory = pFile->m_Clients.m_Memory.m_pMemory;
          v14 = &m_pMemory[v7];
          if ( v14->m_Previous != v7 )
          {
            m_Previous = v14->m_Previous;
            if ( m_Previous == -1 )
              pFile->m_Clients.m_Head = v14->m_Next;
            else
              m_pMemory[m_Previous].m_Next = v14->m_Next;
            m_Next = v14->m_Next;
            if ( m_Next == -1 )
              pFile->m_Clients.m_Tail = v14->m_Previous;
            else
              pFile->m_Clients.m_Memory.m_pMemory[m_Next].m_Previous = v14->m_Previous;
            v14->m_Next = v7;
            v14->m_Previous = v7;
            --pFile->m_Clients.m_ElementCount;
          }
        }
        pFile->m_Clients.m_Memory.m_pMemory[v7].m_Next = pFile->m_Clients.m_FirstFree;
        v5 = v17;
        pFile->m_Clients.m_FirstFree = v7;
LABEL_34:
        v3 = this;
      }
      iFile = *(int *)((char *)&v3->m_Files.m_Memory.m_pMemory->m_Next + v5);
      if ( iFile == -1 )
        break;
      m_Head = *(int *)((char *)&v3->m_Files.m_Memory.m_pMemory->m_Next + v5);
    }
  }
  if ( bGrabCriticalSection )
    LeaveCriticalSection(lpCriticalSection: &v3->m_CS);
}

//------------------------------------------------------------------------------
// Address: 0x1002A4F0
// Name: public: void CMasterMulticastThread::CreateVirtualFile(char const __near *,void const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::CreateVirtualFile(
        CMasterMulticastThread *this,
        const char *pFilename,
        const char *pData,
        unsigned int fileLength)
{
  CMasterMulticastThread::CMulticastFile *v5; // eax
  CMasterMulticastThread::CMulticastFile *v6; // esi

  if ( CMasterMulticastThread::FindFile(this, pName: pFilename, pPathID: "VMPI_VIRTUAL_FILES_PATH_ID") != -1 )
    _Error(a1: "CMasterMulticastThread::CreateVirtualFile( %s ) - file already exists!", pFilename);
  v5 = (CMasterMulticastThread::CMulticastFile *)operator new(nSize: 0xC8u);
  if ( v5 != nullptr )
    v6 = CMasterMulticastThread::CMulticastFile::CMulticastFile(this: v5);
  else
    v6 = nullptr;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &v6->m_UncompressedData, pArray: pData, size: fileLength);
  CMasterMulticastThread::FinishFileSetup(
    this,
    pFile: v6,
    pFilename,
    pPathID: (CMasterMulticastThread::CChunkInfo *)"VMPI_VIRTUAL_FILES_PATH_ID",
    bFileAlreadyExisted: false);
}

//------------------------------------------------------------------------------
// Address: 0x1002A560
// Name: private: bool CMasterMulticastThread::CheckClientTimeouts(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterMulticastThread::CheckClientTimeouts(CMasterMulticastThread *this)
{
  CMasterMulticastThread *v1; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // esi
  char v3; // bl
  int m_Head; // eax
  float v5; // xmm2_4
  int v6; // edx
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // eax
  CMasterMulticastThread::CClientFileInfo *v8; // esi
  int m_Next; // ecx
  float m_flLastAckTime; // xmm1_4
  int v11; // eax
  CMasterMulticastThread::CMulticastFile *v12; // ecx
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v13; // ebx
  float *v14; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *v15; // edi
  float **v16; // eax
  float *v17; // ecx
  const char *MachineName; // eax
  const char *v20; // [esp-4h] [ebp-34h]
  int iNext; // [esp+1Ch] [ebp-14h]
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v23; // [esp+24h] [ebp-Ch]
  float flCurTime; // [esp+28h] [ebp-8h]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+2Ch] [ebp-4h]

  v1 = this;
  m_Element = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element;
  v3 = 0;
  pFile = m_Element;
  flCurTime = _Plat_FloatTime();
  m_Head = m_Element->m_Clients.m_Head;
  if ( m_Head != -1 )
  {
    v5 = flCurTime;
    while ( 1 )
    {
      v6 = m_Head;
      m_pMemory = m_Element->m_Clients.m_Memory.m_pMemory;
      v8 = m_pMemory[v6].m_Element;
      m_Next = m_pMemory[v6].m_Next;
      iNext = m_Next;
      if ( v8->m_nChunksLeft != 0 && ++v8->m_nTimesFileCycled >= 5 )
      {
        m_flLastAckTime = v8->m_flLastAckTime;
        if ( (float)(v5 - m_flLastAckTime) > 20.0 )
        {
          v11 = v1->m_Files.m_Head;
          if ( v11 != -1 )
          {
            v23 = v1->m_Files.m_Memory.m_pMemory;
            do
            {
              v12 = v23[v11].m_Element;
              v13 = &v23[v11];
              v14 = (float *)v12->m_Clients.m_Head;
              if ( v14 != (float *)-1 )
              {
                v15 = v12->m_Clients.m_Memory.m_pMemory;
                do
                {
                  v16 = (float **)&v15[(_DWORD)v14];
                  v17 = *v16;
                  if ( *(_DWORD *)*v16 == v8->m_ClientID && m_flLastAckTime <= v17[10] )
                    m_flLastAckTime = v17[10];
                  v14 = v16[2];
                }
                while ( v14 != (float *)-1 );
                v1 = this;
              }
              v11 = v13->m_Next;
            }
            while ( v11 != -1 );
          }
          v20 = pFile->m_Filename.m_Memory.m_pMemory;
          MachineName = VMPI_GetMachineName(iProc: v8->m_ClientID);
          _Warning(
            a1: "\nClient %s timed out on file %s (latest: %.2f / cur: %.2f).\n",
            MachineName,
            v20,
            m_flLastAckTime,
            v5);
          CMasterMulticastThread::OnClientDisconnect(this: v1, clientID: v8->m_ClientID, bGrabCriticalSection: false);
          v5 = flCurTime;
          m_Next = iNext;
          v3 = 1;
        }
      }
      m_Head = m_Next;
      if ( m_Next == -1 )
        break;
      m_Element = pFile;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1002A6B0
// Name: private: void CMasterMulticastThread::Thread_SeekToNextActiveChunk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::Thread_SeekToNextActiveChunk(CMasterMulticastThread *this)
{
  if ( this->m_iCurFile == -1 )
  {
    this->m_iCurFile = this->m_Files.m_Head;
    this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Head;
  }
  while ( this->m_iCurActiveChunk != -1
       && this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Element->m_RefCount != 0 )
  {
LABEL_10:
    if ( this->m_iCurActiveChunk != -1 )
    {
      if ( this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Element->m_RefCount != 0 )
        return;
      this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Next;
    }
  }
  if ( CMasterMulticastThread::CheckClientTimeouts(this) == 0 || this->m_nTotalActiveChunks != 0 )
  {
    this->m_iCurFile = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Next;
    if ( this->m_iCurFile == -1 )
      this->m_iCurFile = this->m_Files.m_Head;
    this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Head;
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A790
// Name: private: unsigned long CMasterMulticastThread::MulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMasterMulticastThread::MulticastThread(CMasterMulticastThread *this)
{
  void (__stdcall *v2)(LPCRITICAL_SECTION); // ebx
  DWORD v3; // eax
  double v4; // st7
  unsigned int v5; // ecx
  unsigned __int64 v7; // [esp-10h] [ebp-80h]
  CTransmitRateMgr transmitRateMgr; // [esp+4h] [ebp-6Ch] BYREF
  CRateLimiter rateLimiter; // [esp+34h] [ebp-3Ch] BYREF
  int v10; // [esp+44h] [ebp-2Ch] BYREF
  __int16 v11; // [esp+48h] [ebp-28h]
  unsigned int m_UniqueID; // [esp+4Ah] [ebp-26h]
  unsigned __int64 v13; // [esp+50h] [ebp-20h] BYREF
  CFastTimer timer; // [esp+58h] [ebp-18h] BYREF
  __int64 v15; // [esp+60h] [ebp-10h]
  unsigned int msToWait; // [esp+68h] [ebp-8h]
  int nBytesSent; // [esp+6Ch] [ebp-4h] BYREF

  CTransmitRateMgr::CTransmitRateMgr(this: &transmitRateMgr);
  rateLimiter.m_SleepIntervalMS = 50;
  rateLimiter.m_AccumulatedSleepMicroseconds = 0;
  msToWait = (unsigned int)&rateLimiter.m_LastSleepTime;
  rateLimiter.m_LastSleepTime.m_Int64 = __rdtsc();
  if ( WaitForSingleObject(hHandle: this->m_hTermEvent, dwMilliseconds: 0) != 0 )
  {
    v2 = LeaveCriticalSection;
    do
    {
      CRateLimiter::GiveUpTimeSlice(this: &rateLimiter);
      msToWait = 0;
      EnterCriticalSection(lpCriticalSection: &this->m_CS);
      CTransmitRateMgr::ReadPackets(this: &transmitRateMgr);
      if ( this->m_nTotalActiveChunks == 0 )
        goto LABEL_4;
      if ( transmitRateMgr.m_pSocket != nullptr )
      {
        v4 = _Plat_FloatTime();
        *(float *)&nBytesSent = v4;
        if ( v4 - transmitRateMgr.m_flLastBroadcastTime >= 0.3333333333333333 )
        {
          m_UniqueID = transmitRateMgr.m_UniqueID;
          v10 = *(_DWORD *)s_cTransmitRateMgrPacket;
          v11 = *(_WORD *)&s_cTransmitRateMgrPacket[4];
          LODWORD(transmitRateMgr.m_flLastBroadcastTime) = nBytesSent;
          transmitRateMgr.m_pSocket->Broadcast(this: transmitRateMgr.m_pSocket, a2: &v10, a3: 10, a4: 21146u);
        }
      }
      *(float *)&nBytesSent = COERCE_FLOAT(&timer);
      timer.m_Duration.m_Int64 = __rdtsc();
      CMasterMulticastThread::Thread_SeekToNextActiveChunk(this);
      if ( this->m_nTotalActiveChunks != 0 )
      {
        *(float *)&nBytesSent = 0.0;
        CMasterMulticastThread::Thread_SendFileChunk_Multicast(this, pnBytesSent: (unsigned int *)&nBytesSent);
        g_nMulticastBytesSent += nBytesSent;
        this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Next;
        v2(lpCriticalSection: &this->m_CS);
        HIDWORD(v15) = &v13;
        v13 = __rdtsc();
        timer.m_Duration.m_Int64 = v13 - timer.m_Duration.m_Int64;
        HIDWORD(v7) = HIDWORD(_g_ClockSpeed);
        LODWORD(v7) = _g_ClockSpeed;
        v5 = 1000000 * timer.m_Duration.m_Int64 / v7;
        v15 = (__int64)((double)(unsigned int)(nBytesSent + 32) * transmitRateMgr.m_nMicrosecondsPerByte);
        if ( v5 < (unsigned int)v15 )
          CRateLimiter::NoteExcessTimeTaken(this: &rateLimiter, excessTimeInMicroseconds: v15 - v5);
        v2 = LeaveCriticalSection;
        v3 = msToWait;
      }
      else
      {
LABEL_4:
        v2(lpCriticalSection: &this->m_CS);
        v3 = 50;
      }
    }
    while ( WaitForSingleObject(hHandle: this->m_hTermEvent, dwMilliseconds: v3) != 0 );
  }
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&transmitRateMgr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A9A0
// Name: public: int CMasterMulticastThread::FindOrAddFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FindOrAddFile(
        CMasterMulticastThread *this,
        const char *pFilename,
        char *pPathID)
{
  int result; // eax
  void *v5; // esi
  CMasterMulticastThread::CMulticastFile *v6; // eax
  int v7; // ebx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v10; // eax
  int v11; // esi
  bool bFileAlreadyExisted; // [esp+10h] [ebp-8h]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+14h] [ebp-4h]

  pFile = nullptr;
  bFileAlreadyExisted = false;
  result = CMasterMulticastThread::FindFile(this, pName: pFilename, pPathID);
  if ( result != -1 )
  {
    pFile = this->m_Files.m_Memory.m_pMemory[result].m_Element;
    if ( pFile->m_bDataLoaded )
      return result;
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
    bFileAlreadyExisted = true;
  }
  v5 = this->m_pPassThru->Open(this: this->m_pPassThru, a2: pFilename, a3: "rb", a4: *pPathID != 0 ? pPathID : nullptr);
  if ( v5 != nullptr )
  {
    if ( !bFileAlreadyExisted )
    {
      v6 = (CMasterMulticastThread::CMulticastFile *)operator new(nSize: 0xC8u);
      if ( v6 != nullptr )
        pFile = CMasterMulticastThread::CMulticastFile::CMulticastFile(this: v6);
      else
        pFile = nullptr;
    }
    v7 = this->m_pPassThru->Size_2(this: this->m_pPassThru, a2: v5);
    pFile->m_UncompressedData.m_Size = 0;
    if ( v7 != 0 )
    {
      m_nAllocationCount = pFile->m_UncompressedData.m_Memory.m_nAllocationCount;
      if ( v7 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(this: &pFile->m_UncompressedData.m_Memory, num: v7 - m_nAllocationCount);
      pFile->m_UncompressedData.m_Size += v7;
      m_pMemory = pFile->m_UncompressedData.m_Memory.m_pMemory;
      v10 = pFile->m_UncompressedData.m_Size - v7;
      pFile->m_UncompressedData.m_pElements = m_pMemory;
      if ( v10 > 0 && v7 > 0 )
        _V_memmove(dest: &m_pMemory[v7], src: m_pMemory, count: v10);
    }
    this->m_pPassThru->Read(
      this: this->m_pPassThru,
      a2: pFile->m_UncompressedData.m_Memory.m_pMemory,
      a3: pFile->m_UncompressedData.m_Size,
      a4: v5);
    this->m_pPassThru->Close(this: this->m_pPassThru, a2: v5);
    v11 = CMasterMulticastThread::FinishFileSetup(
            this,
            pFile,
            pFilename,
            (CMasterMulticastThread::CChunkInfo *)pPathID,
            bFileAlreadyExisted);
    if ( bFileAlreadyExisted )
      LeaveCriticalSection(lpCriticalSection: &this->m_CS);
    return v11;
  }
  else
  {
    if ( bFileAlreadyExisted )
      LeaveCriticalSection(lpCriticalSection: &this->m_CS);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AB00
// Name: public: virtual void __near * CMasterVMPIFileSystem::OpenEx(char const __near *,char const __near *,unsigned int,char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMasterVMPIFileSystem::OpenEx(
        CMasterVMPIFileSystem *this,
        const char *pFileName,
        const char *pOptions,
        unsigned int flags,
        const char *pathID,
        char **ppszResolvedFilename)
{
  return this->Open(this: &this->IBaseFileSystem, a2: pFileName, a3: pOptions, a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1002AB20
// Name: public: virtual void __near * CMasterVMPIFileSystem::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVMPIFile_Memory *__thiscall CMasterVMPIFileSystem::Open(
        CMasterVMPIFileSystem *this,
        const char *pFilename,
        char *pOptions,
        char *pPathID)
{
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  CVMPIFile_Memory *result; // eax
  IBaseFileSystem_vtbl *v10; // ecx
  IBaseFileSystem_vtbl *v11; // ecx
  char *v12; // eax
  int v13; // eax
  int v14; // esi
  CVMPIFile_Memory *v15; // eax
  CVMPIFile_Memory *v16; // edi
  int v17; // ebx
  const char *v18; // esi
  int v19; // eax

  if ( g_bDisableFileAccess )
    _Error(a1: "Open( %s, %s ) - file access has been disabled.", pFilename, pOptions);
  strchr(string: pOptions, chr: 0x77u);
  if ( v5 != 0 || (strchr(string: pOptions, chr: 0x61u), v6 != 0) || (strchr(string: pOptions, chr: 0x2Bu), v7 != 0) )
  {
    v8 = (*((int (__thiscall **)(IBaseFileSystem_vtbl *, const char *, char *, char *))this->Read + 2))(
           a1: this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable,
           a2: pFilename,
           a3: pOptions,
           a4: pPathID);
    if ( v8 == 0 )
      return nullptr;
    result = (CVMPIFile_Memory *)operator new(nSize: 0xCu);
    if ( result != nullptr )
    {
      result->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_PassThru::`vftable';
      v10 = this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable;
      result->m_DataLen = v8;
      result->m_pData = (const char *)v10;
    }
    else
    {
      v11 = this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable;
      MEMORY[8] = v8;
      MEMORY[4] = v11;
      return nullptr;
    }
  }
  else
  {
    v12 = pPathID;
    if ( pPathID == nullptr )
      v12 = (char *)setName;
    v13 = CMasterMulticastThread::FindOrAddFile(
            this: (CMasterMulticastThread *)&this->m_MulticastIP.port,
            pFilename,
            pPathID: v12);
    if ( v13 == -1 )
      return nullptr;
    v14 = *(_DWORD *)(*(_DWORD *)&this->m_MulticastIP.port + 12 * v13);
    v15 = (CVMPIFile_Memory *)operator new(nSize: 0x14u);
    if ( v15 != nullptr )
    {
      v15->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_Memory::`vftable';
      v16 = v15;
    }
    else
    {
      v16 = nullptr;
    }
    v17 = *(_DWORD *)(v14 + 68);
    v18 = *(const char **)(v14 + 56);
    strchr(string: pOptions, chr: 0x74u);
    CVMPIFile_Memory::Init(this: v16, pData: v18, len: v17, chMode: v19 != 0 ? 116 : 98);
    return v16;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AC40
// Name: private: static void CMasterVMPIFileSystem::OnClientDisconnect(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMasterVMPIFileSystem::OnClientDisconnect(int procID)
{
  CMasterMulticastThread::OnClientDisconnect(
    this: &CMasterVMPIFileSystem::s_pMasterVMPIFileSystem->m_MasterThread,
    clientID: procID,
    bGrabCriticalSection: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002AC60
// Name: public: virtual void CMasterVMPIFileSystem::CreateVirtualFile(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::CreateVirtualFile(
        CMasterVMPIFileSystem *this,
        const char *pFilename,
        const char *pData,
        unsigned int fileLength)
{
  CMasterMulticastThread::CreateVirtualFile(this: &this->m_MasterThread, pFilename, pData, fileLength);
}

//------------------------------------------------------------------------------
// Address: 0x1002AC70
// Name: public: int CMasterMulticastThread::AddFileRequest(char const __near *,char const __near *,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::AddFileRequest(
        CMasterMulticastThread *this,
        const char *pFilename,
        char *pPathID,
        int clientID,
        bool *bZeroLength)
{
  int result; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  char *v8; // eax
  char *v9; // edi
  int v10; // ecx
  double v11; // st7
  int v12; // eax
  int v13; // ecx
  char *v14; // edx
  int v15; // ecx
  CMasterMulticastThread::CChunkInfo *v16; // esi
  bool v17; // zf
  unsigned __int16 v18; // ax
  int v19; // eax
  int j; // esi
  int iFile; // [esp+4h] [ebp-14h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+8h] [ebp-10h]
  CMasterMulticastThread::CChunkInfo *src; // [esp+Ch] [ebp-Ch] BYREF
  CMasterMulticastThread *v24; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  const char *pFilenamea; // [esp+20h] [ebp+8h]
  const char *pFilenameb; // [esp+20h] [ebp+8h]

  v24 = this;
  result = CMasterMulticastThread::FindOrAddFile(this, pFilename, pPathID);
  iFile = result;
  if ( result != -1 )
  {
    m_Element = this->m_Files.m_Memory.m_pMemory[result].m_Element;
    lpCriticalSection = &this->m_CS;
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
    v8 = (char *)operator new(nSize: 0x30u);
    if ( v8 != nullptr )
    {
      v9 = v8;
      *((_DWORD *)v8 + 1) = 0;
      *((_DWORD *)v8 + 2) = 0;
      *((_DWORD *)v8 + 3) = 0;
      *((_DWORD *)v8 + 4) = 0;
      *((_DWORD *)v8 + 5) = 0;
      pPathID = v8;
    }
    else
    {
      pPathID = nullptr;
      v9 = nullptr;
    }
    v10 = clientID;
    *((_DWORD *)v9 + 7) = -1;
    *((_DWORD *)v9 + 8) = -1;
    *(_DWORD *)v9 = v10;
    v11 = _Plat_FloatTime();
    *((float *)v9 + 10) = v11;
    *((float *)v9 + 9) = v11;
    *((_DWORD *)v9 + 11) = 0;
    *((_DWORD *)v9 + 6) = m_Element->m_Info.m_nChunks;
    v12 = 8 * ((m_Element->m_Info.m_nChunks + 7) / 8) / 8;
    pFilenamea = (const char *)v12;
    *((_DWORD *)v9 + 4) = 0;
    if ( v12 != 0 )
    {
      v13 = *((_DWORD *)v9 + 2);
      if ( v12 > v13 )
      {
        CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)(v9 + 4), num: v12 - v13);
        v12 = (int)pFilenamea;
      }
      *((_DWORD *)v9 + 4) += v12;
      v14 = *((char **)v9 + 1);
      v15 = *((_DWORD *)v9 + 4) - v12;
      *((_DWORD *)v9 + 5) = v14;
      if ( v15 > 0 && v12 > 0 )
        _V_memmove(dest: &v14[v12], src: v14, count: v15);
    }
    memset(dst: *((_DWORD *)v9 + 1), value: (unsigned __int8 *)0xFF, count: *((_DWORD *)v9 + 4));
    CUtlLinkedList<CMasterMulticastThread::CClientFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int>,int>>::AddToTail(
      this: &m_Element->m_Clients,
      src: (CMasterMulticastThread::CClientFileInfo **)&pPathID);
    i = 0;
    if ( m_Element->m_Chunks.m_Size > 0 )
    {
      pFilenameb = nullptr;
      do
      {
        v16 = (CMasterMulticastThread::CChunkInfo *)&pFilenameb[(unsigned int)m_Element->m_Chunks.m_Memory.m_pMemory];
        v17 = v16->m_RefCount == 0;
        src = v16;
        if ( v17 )
        {
          ++v24->m_nTotalActiveChunks;
          clientID = v16->m_iActiveChunksIndex;
          CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
            this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&m_Element->m_ActiveChunks,
            elem: clientID);
          m_Element->m_ActiveChunks.m_Memory.m_pMemory[clientID].m_Next = m_Element->m_ActiveChunks.m_FirstFree;
          m_Element->m_ActiveChunks.m_FirstFree = clientID;
          v18 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToHead(
                  this: &m_Element->m_ActiveChunks,
                  &src);
          v9 = pPathID;
          v16->m_iActiveChunksIndex = v18;
        }
        v19 = i;
        ++v16->m_RefCount;
        pFilenameb += 6;
        i = v19 + 1;
      }
      while ( v19 + 1 < m_Element->m_Chunks.m_Size );
    }
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
    {
      for ( j = 16; j != 0; --j )
        CMasterMulticastThread::TCP_SendNextChunk(
          this: v24,
          pFile: m_Element,
          pClient: (CMasterMulticastThread::CClientFileInfo *)v9);
    }
    LeaveCriticalSection(lpCriticalSection);
    *bZeroLength = m_Element->m_Info.m_UncompressedSize == 0;
    return iFile;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AE40
// Name: private: static unsigned long CMasterMulticastThread::StaticMulticastThread(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CMasterMulticastThread::StaticMulticastThread(CMasterMulticastThread *pParameter)
{
  return CMasterMulticastThread::MulticastThread(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x1002AEA0
// Name: public: virtual bool CMasterVMPIFileSystem::HandleFileSystemPacket(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterVMPIFileSystem::HandleFileSystemPacket(
        CMasterVMPIFileSystem *this,
        CVMPIFile_Memory *pBuf,
        int iSource,
        int iPacketID)
{
  char *v5; // eax
  int v6; // edx
  int v7; // edx
  unsigned __int16 *v9; // esi
  unsigned __int16 *v10; // edi
  int v11; // eax
  int i; // ebx
  const char *v13; // esi
  unsigned int v14; // kr04_4
  int v15; // edi
  void *pChunks[4]; // [esp+Ch] [ebp-2Ch] BYREF
  int chunkLen[4]; // [esp+1Ch] [ebp-1Ch] BYREF
  int fileID; // [esp+2Ch] [ebp-Ch] BYREF
  int requestID; // [esp+30h] [ebp-8h] BYREF
  CMasterVMPIFileSystem *v20; // [esp+34h] [ebp-4h]

  v5 = (char *)pBuf->__vftable;
  v6 = SBYTE1(pBuf->Close) - 1;
  v20 = this;
  if ( v6 == 0 )
  {
    v13 = v5 + 6;
    requestID = *(_DWORD *)(v5 + 2);
    v14 = strlen(v5 + 6);
    v15 = iSource;
    if ( g_iVMPIVerboseLevel >= 2 )
      _Msg(a1: "Client %d requested '%s'\n", iSource, v13);
    fileID = CMasterMulticastThread::AddFileRequest(
               this: &v20->m_MasterThread,
               pFilename: v13,
               pPathID: (char *)&v13[v14 + 1],
               clientID: v15,
               bZeroLength: (bool *)&iSource + 3);
    pChunks[0] = &pBuf;
    pChunks[3] = (char *)&iSource + 3;
    pChunks[1] = &requestID;
    pChunks[2] = &fileID;
    LOWORD(pBuf) = 512;
    chunkLen[0] = 2;
    chunkLen[1] = 4;
    chunkLen[2] = 4;
    chunkLen[3] = 1;
    VMPI_SendChunks((const void *const *)pChunks, pChunkLengths: chunkLen, nChunks: 4, iDest: v15, fVMPISendFlags: 0);
    return 1;
  }
  v7 = v6 - 2;
  if ( v7 != 0 )
  {
    if ( v7 != 1 )
      return 0;
    CMasterMulticastThread::OnFileReceived(
      this: &this->m_MasterThread,
      fileID: *((unsigned __int16 *)v5 + 1),
      clientID: iSource);
    return 1;
  }
  v9 = (unsigned __int16 *)(v5 + 2);
  v10 = (unsigned __int16 *)(v5 + 4);
  v11 = (int)(ConCommandBase::GetName(this: pBuf) - 2) / 4;
  if ( v11 <= 0 )
    return 1;
  pBuf = (CVMPIFile_Memory *)&this->m_MasterThread;
  for ( i = v11; i != 0; --i )
  {
    CMasterMulticastThread::OnChunkReceived(
      this: (CMasterMulticastThread *)pBuf,
      fileID: *v9,
      clientID: iSource,
      iChunk: *v10);
    v9 += 2;
    v10 += 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002AFE0
// Name: public: bool CMasterMulticastThread::Init(class IBaseFileSystem __near *,unsigned short,class CIPAddr const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterMulticastThread::Init(
        CMasterMulticastThread *this,
        IBaseFileSystem *pPassThru,
        int localPort,
        const CIPAddr *pAddr,
        unsigned int maxMemoryUsage)
{
  SOCKET v6; // eax
  const CIPAddr *v8; // edi
  HANDLE v9; // eax
  SOCKET m_Socket; // [esp-14h] [ebp-34h]
  sockaddr_in addr; // [esp+8h] [ebp-18h] BYREF
  CIPAddr localAddr; // [esp+18h] [ebp-8h] BYREF

  CMasterMulticastThread::Term(this);
  this->m_nMaxMemoryUsage = maxMemoryUsage;
  this->m_nCurMemoryUsage = 0;
  if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
  {
    this->m_Socket = -1;
  }
  else
  {
    v6 = socket(af: 2, type: 2, protocol: 0);
    this->m_Socket = v6;
    if ( v6 == -1 )
    {
      _Warning(a1: "CMasterMulticastThread::Init - socket() failed\n");
      return 0;
    }
    CIPAddr::CIPAddr(this: &localAddr, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: (unsigned __int16)localPort);
    IPAddrToSockAddr(pIn: &localAddr, pOut: &addr);
    if ( bind(s: this->m_Socket, name: (const struct sockaddr *)&addr, namelen: 16) != 0 )
    {
      CMasterMulticastThread::Term(this);
      _Warning(
        a1: "CMasterMulticastThread::Init - bind( %d.%d.%d.%d:%d ) failed\n",
        pAddr->ip[0],
        pAddr->ip[1],
        pAddr->ip[2],
        pAddr->ip[3],
        pAddr->port);
      return 0;
    }
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
    {
      m_Socket = this->m_Socket;
      localPort = 1;
      if ( setsockopt(s: m_Socket, level: 0xFFFF, optname: 32, optval: (const char *)&localPort, optlen: 1) == -1 )
      {
        CMasterMulticastThread::Term(this);
        _Warning(a1: "CMasterMulticastThread::Init - setsockopt() failed to set broadcast mode\n");
        return 0;
      }
    }
    v8 = pAddr;
    IPAddrToSockAddr(pIn: pAddr, pOut: &this->m_MulticastAddr);
    maxMemoryUsage = 0;
    v9 = CreateThread(
           lpThreadAttributes: nullptr,
           dwStackSize: 0,
           lpStartAddress: (LPTHREAD_START_ROUTINE)CMasterMulticastThread::StaticMulticastThread,
           lpParameter: this,
           dwCreationFlags: 0,
           lpThreadId: &maxMemoryUsage);
    this->m_hThread = v9;
    if ( v9 == nullptr )
    {
      CMasterMulticastThread::Term(this);
      _Warning(
        a1: "CMasterMulticastThread::Init - CreateThread failed\n",
        v8->ip[0],
        v8->ip[1],
        v8->ip[2],
        v8->ip[3],
        v8->port);
      return 0;
    }
    SetThreadPriority(hThread: v9, nPriority: -2);
  }
  this->m_hMainThread = GetCurrentThread();
  this->m_pPassThru = pPassThru;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B190
// Name: public: bool CMasterVMPIFileSystem::Init(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterVMPIFileSystem::Init(
        CMasterVMPIFileSystem *this,
        unsigned int maxMemoryUsage,
        IFileSystem *pPassThru)
{
  IFileSystem *v3; // edi
  int v5; // ebx
  IBaseFileSystem *v6; // eax
  char result; // al
  unsigned __int64 v8; // [esp-8h] [ebp-20h]
  CCycleCount cnt; // [esp+Ch] [ebp-Ch] BYREF
  CCycleCount *p_cnt; // [esp+14h] [ebp-4h]

  v3 = pPassThru;
  this->InitPassThru_2(this, a2: pPassThru, a3: false);
  this->m_pMasterVMPIFileSystemPassThru = v3;
  p_cnt = &cnt;
  cnt.m_Int64 = __rdtsc();
  HIDWORD(v8) = HIDWORD(_g_ClockSpeed);
  LODWORD(v8) = _g_ClockSpeed;
  _RandomSeed(a1: 1000000 * cnt.m_Int64 / v8);
  v5 = (unsigned __int16)_RandomInt(a1: 22000, a2: 25000);
  if ( VMPI_GetRunMode() != VMPI_RUN_NETWORKED )
  {
    CIPAddr::Init(this: &this->m_MulticastIP, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: 0);
  }
  else if ( VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_MULTICAST )
  {
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
      CIPAddr::Init(this: &this->m_MulticastIP, ip0: 255, ip1: 255, ip2: 255, ip3: 255, ipPort: v5);
  }
  else
  {
    this->m_MulticastIP.port = v5;
    this->m_MulticastIP.ip[0] = _RandomInt(a1: 225, a2: 238);
    this->m_MulticastIP.ip[1] = _RandomInt(a1: 0, a2: 255);
    this->m_MulticastIP.ip[2] = _RandomInt(a1: 0, a2: 255);
    this->m_MulticastIP.ip[3] = _RandomInt(a1: 3, a2: 255);
  }
  if ( pPassThru != nullptr )
    v6 = &pPassThru->IBaseFileSystem;
  else
    v6 = nullptr;
  result = CMasterMulticastThread::Init(
             this: &this->m_MasterThread,
             pPassThru: v6,
             localPort: 23412,
             pAddr: &this->m_MulticastIP,
             maxMemoryUsage);
  if ( result != 0 )
  {
    LOWORD(pPassThru) = 1280;
    VMPI_Send2Chunks(
      pChunk1: &pPassThru,
      chunk1Len: 2,
      pChunk2: &this->m_MulticastIP,
      chunk2Len: 6,
      iDest: -3,
      fVMPISendFlags: 0);
    VMPI_AddDisconnectHandler(handler: (void (__cdecl *)(int, const char *))CMasterVMPIFileSystem::OnClientDisconnect);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B300
// Name: class CBaseVMPIFileSystem __near * CreateMasterVMPIFileSystem(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CMasterVMPIFileSystem *__cdecl CreateMasterVMPIFileSystem(unsigned int maxMemoryUsage, IFileSystem *pPassThru)
{
  CMasterVMPIFileSystem *v2; // eax
  CMasterVMPIFileSystem *v3; // esi

  v2 = (CMasterVMPIFileSystem *)operator new(nSize: 0xBCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&IBaseFileSystem::`vftable';
    v2->m_pBaseFileSystemPassThru = nullptr;
    v2->m_pFileSystemPassThru = nullptr;
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CMasterVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
    CIPAddr::CIPAddr(this: &v2->m_MulticastIP);
    v3->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CMasterVMPIFileSystem_vtbl *)&CMasterVMPIFileSystem::`vftable'{for `IAppSystem'};
    v3->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CMasterVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
    CMasterMulticastThread::CMasterMulticastThread(this: &v3->m_MasterThread);
    CMasterVMPIFileSystem::s_pMasterVMPIFileSystem = v3;
  }
  else
  {
    v3 = nullptr;
  }
  g_pBaseVMPIFileSystem = v3;
  if ( CMasterVMPIFileSystem::Init(this: v3, maxMemoryUsage, pPassThru) != 0 )
    return v3;
  if ( v3 != nullptr )
    ((void (__thiscall *)(CMasterVMPIFileSystem *, int))v3->dtr_CBaseVMPIFileSystem)(a1: v3, a2: 1);
  g_pBaseVMPIFileSystem = nullptr;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002D660
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CMasterMulticastThread::CMulticastFile __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CWorkerFile *,int> *)_g_pMemAlloc->Realloc_2(
                                                                    this: _g_pMemAlloc,
                                                                    a2: m_pMemory,
                                                                    a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CWorkerFile *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10001AB0
// Name: public: void CUtlMemory<class CTransmitRateMgr::CMachineRecord,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
        CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CTransmitRateMgr::CMachineRecord *m_pMemory; // edx
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
      this->m_pMemory = (CTransmitRateMgr::CMachineRecord *)_g_pMemAlloc->Realloc_2(
                                                              this: _g_pMemAlloc,
                                                              a2: m_pMemory,
                                                              a3: v7);
    else
      this->m_pMemory = (CTransmitRateMgr::CMachineRecord *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FF30
// Name: public: virtual class CSysModule __near * CMasterVMPIFileSystem::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CMasterVMPIFileSystem::LoadModule(
        CMasterVMPIFileSystem *this,
        const char *pFileName,
        const char *pPathID,
        BOOL bValidatedDllOnly)
{
  return this->m_pMasterVMPIFileSystemPassThru->LoadModule(
           this: this->m_pMasterVMPIFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: bValidatedDllOnly);
}

//------------------------------------------------------------------------------
// Address: 0x1000FF50
// Name: public: virtual void CMasterVMPIFileSystem::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::UnloadModule(CMasterVMPIFileSystem *this, struct CSysModule *pModule)
{
  this->m_pMasterVMPIFileSystemPassThru->UnloadModule(this: this->m_pMasterVMPIFileSystemPassThru, a2: pModule);
}

//------------------------------------------------------------------------------
// Address: 0x10010010
// Name: public: void CRateLimiter::NoteExcessTimeTaken(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRateLimiter::NoteExcessTimeTaken(CRateLimiter *this, unsigned int excessTimeInMicroseconds)
{
  unsigned int m_AccumulatedSleepMicroseconds; // eax
  unsigned int v3; // esi
  unsigned __int64 v4; // [esp-Ch] [ebp-20h]
  CCycleCount startCount; // [esp+Ch] [ebp-8h]

  m_AccumulatedSleepMicroseconds = this->m_AccumulatedSleepMicroseconds;
  if ( excessTimeInMicroseconds <= m_AccumulatedSleepMicroseconds )
  {
    this->m_AccumulatedSleepMicroseconds = m_AccumulatedSleepMicroseconds - excessTimeInMicroseconds;
  }
  else
  {
    v3 = excessTimeInMicroseconds - m_AccumulatedSleepMicroseconds;
    this->m_AccumulatedSleepMicroseconds = 0;
    startCount.m_Int64 = __rdtsc();
    do
    {
      HIDWORD(v4) = HIDWORD(_g_ClockSpeed);
      LODWORD(v4) = _g_ClockSpeed;
    }
    while ( (unsigned int)(1000000 * (__rdtsc() - startCount.m_Int64) / v4) < v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100100B0
// Name: public: virtual void CVMPIFile_PassThru::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Close(CVMPIFile_PassThru *this)
{
  this->m_pPassThru->Close(this: this->m_pPassThru, a2: this->m_fp);
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x100100D0
// Name: public: virtual void CVMPIFile_PassThru::Seek(int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Seek(CVMPIFile_PassThru *this, int pos, FileSystemSeek_t seekType)
{
  this->m_pPassThru->Seek(this: this->m_pPassThru, a2: this->m_fp, a3: pos, a4: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x10010100
// Name: public: virtual unsigned int CVMPIFile_PassThru::Tell(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_PassThru::Tell(CVMPIFile_PassThru *this)
{
  return this->m_pPassThru->Tell(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10010120
// Name: public: virtual unsigned int CVMPIFile_PassThru::Size(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_PassThru::Size(CVMPIFile_PassThru *this)
{
  return this->m_pPassThru->Size_2(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10010140
// Name: public: virtual void CVMPIFile_PassThru::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Flush(CVMPIFile_PassThru *this)
{
  this->m_pPassThru->Flush(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10010160
// Name: public: virtual int CVMPIFile_PassThru::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_PassThru::Read(CVMPIFile_PassThru *this, void *pOutput, int size)
{
  return this->m_pPassThru->Read(this: this->m_pPassThru, a2: pOutput, a3: size, a4: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10010180
// Name: public: virtual int CVMPIFile_PassThru::Write(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_PassThru::Write(CVMPIFile_PassThru *this, const void *pInput, int size)
{
  return this->m_pPassThru->Write(this: this->m_pPassThru, a2: pInput, a3: size, a4: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x100101A0
// Name: public: void CRateLimiter::GiveUpTimeSlice(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRateLimiter::GiveUpTimeSlice(CRateLimiter *this)
{
  CCycleCount *p_m_LastSleepTime; // edi
  unsigned __int64 v3; // [esp-Ch] [ebp-30h]
  unsigned __int64 v4; // [esp-Ch] [ebp-30h]
  unsigned __int64 v5; // [esp+8h] [ebp-1Ch] BYREF
  CFastTimer sleepTimer; // [esp+10h] [ebp-14h] BYREF
  CCycleCount currentTime; // [esp+18h] [ebp-Ch] BYREF
  CFastTimer *p_currentTime; // [esp+20h] [ebp-4h]

  p_currentTime = (CFastTimer *)&currentTime;
  currentTime.m_Int64 = __rdtsc();
  p_m_LastSleepTime = &this->m_LastSleepTime;
  HIDWORD(v3) = HIDWORD(_g_ClockSpeed);
  LODWORD(v3) = _g_ClockSpeed;
  if ( (unsigned int)(1000 * (currentTime.m_Int64 - this->m_LastSleepTime.m_Int64) / v3) >= this->m_SleepIntervalMS )
  {
    p_currentTime = &sleepTimer;
    sleepTimer.m_Duration.m_Int64 = __rdtsc();
    Sleep(dwMilliseconds: 0xAu);
    p_currentTime = (CFastTimer *)&v5;
    v5 = __rdtsc();
    sleepTimer.m_Duration.m_Int64 = v5 - sleepTimer.m_Duration.m_Int64;
    HIDWORD(v4) = HIDWORD(_g_ClockSpeed);
    LODWORD(v4) = _g_ClockSpeed;
    this->m_AccumulatedSleepMicroseconds += 1000000 * sleepTimer.m_Duration.m_Int64 / v4;
    p_m_LastSleepTime->m_Int64 = __rdtsc();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010280
// Name: private: void CMasterMulticastThread::TCP_SendNextChunk(class CMasterMulticastThread::CMulticastFile __near *,class CMasterMulticastThread::CClientFileInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::TCP_SendNextChunk(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pFile,
        CMasterMulticastThread::CClientFileInfo *pClient)
{
  CMasterMulticastThread::CMulticastFile *v3; // edx
  CMasterMulticastThread::CClientFileInfo *v4; // ebx
  int v5; // eax
  int v6; // ecx
  int m_Size; // edi
  int v8; // esi
  char *m_pMemory; // eax
  char *v10; // edx
  int m_ClientID; // [esp-10h] [ebp-3Ch]
  const void *chunks[5]; // [esp+4h] [ebp-28h] BYREF
  int chunkLengths[5]; // [esp+18h] [ebp-14h] BYREF

  v3 = pFile;
  v4 = pClient;
  v5 = pClient->m_TCP_LastChunkSent + 1;
  if ( v5 < pFile->m_Info.m_nChunks )
  {
    v6 = v5 << 14;
    m_Size = pFile->m_Data.m_Size;
    v8 = (v5 << 14) + 0x4000;
    pFile = (CMasterMulticastThread::CMulticastFile *)(pClient->m_TCP_LastChunkSent + 1);
    if ( v8 >= m_Size )
      v8 = m_Size;
    if ( v6 < m_Size )
    {
      pClient->m_TCP_LastChunkSent = v5;
      chunks[0] = &pClient;
      chunks[1] = &v3->m_Info;
      chunks[2] = &pFile;
      m_pMemory = v3->m_Filename.m_Memory.m_pMemory;
      v10 = v3->m_Data.m_Memory.m_pMemory;
      LOWORD(pClient) = 1536;
      chunks[3] = m_pMemory;
      chunks[4] = &v10[v6];
      chunkLengths[0] = 2;
      chunkLengths[1] = 12;
      chunkLengths[2] = 4;
      chunkLengths[3] = strlen(m_pMemory) + 1;
      m_ClientID = v4->m_ClientID;
      chunkLengths[4] = v8 - v6;
      VMPI_SendChunks(pChunks: chunks, pChunkLengths: chunkLengths, nChunks: 5, iDest: m_ClientID, fVMPISendFlags: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010340
// Name: private: bool CMasterMulticastThread::Thread_SendFileChunk_Multicast(int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMasterMulticastThread::Thread_SendFileChunk_Multicast(
        CMasterMulticastThread *this,
        unsigned int *pnBytesSent)
{
  CMasterMulticastThread::CMulticastFile *m_Element; // ecx
  volatile int v4; // edx
  int m_Size; // edi
  unsigned int v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned int v8; // eax
  int v9; // edi
  bool v10; // zf
  unsigned int v11; // eax
  int v13; // ecx
  DWORD LastError; // eax
  char dst[8192]; // [esp+Ch] [ebp-202Ch] BYREF
  _WSABUF count; // [esp+200Ch] [ebp-2Ch] BYREF
  unsigned int v17; // [esp+2014h] [ebp-24h]
  unsigned __int8 *p_m_iCurActiveChunk; // [esp+2018h] [ebp-20h]
  unsigned int v19; // [esp+201Ch] [ebp-1Ch]
  unsigned __int8 *m_pMemory; // [esp+2020h] [ebp-18h]
  unsigned int v21; // [esp+2024h] [ebp-14h]
  unsigned __int8 *v22; // [esp+2028h] [ebp-10h]
  char Buffer[4]; // [esp+202Ch] [ebp-Ch] BYREF
  unsigned int NumberOfBytesSent; // [esp+2030h] [ebp-8h] BYREF
  int len; // [esp+2034h] [ebp-4h]

  m_Element = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element;
  v4 = this->m_iCurActiveChunk << 10;
  m_Size = m_Element->m_Data.m_Size;
  len = v4 + 1024;
  if ( v4 + 1024 >= m_Size )
    len = m_Size;
  count.buf = (char *)&m_Element->m_Info;
  count.len = 12;
  p_m_iCurActiveChunk = (unsigned __int8 *)&this->m_iCurActiveChunk;
  v17 = 4;
  m_pMemory = (unsigned __int8 *)m_Element->m_Filename.m_Memory.m_pMemory;
  v6 = strlen(m_Element->m_Filename.m_Memory.m_pMemory) + 1;
  v19 = v6;
  v7 = (unsigned __int8 *)&m_Element->m_Data.m_Memory.m_pMemory[v4];
  v10 = this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b1 == 127;
  v21 = len - v4;
  v8 = len - v4 + v6 + 16;
  v22 = v7;
  NumberOfBytesSent = 0;
  len = v8;
  if ( !v10
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b2 != 0
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b3 != 0
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b4 != 1 )
  {
    WSASendTo(
      s: this->m_Socket,
      lpBuffers: &count,
      dwBufferCount: 4u,
      lpNumberOfBytesSent: &NumberOfBytesSent,
      dwFlags: 0,
      lpTo: (const struct sockaddr *)&this->m_MulticastAddr,
      iTolen: 16,
      lpOverlapped: nullptr,
      lpCompletionRoutine: nullptr);
    v11 = NumberOfBytesSent;
    v10 = NumberOfBytesSent == len;
    v9 = len;
  }
  else
  {
    if ( v8 > 0x2000 )
    {
      _Error(a1: "nWantedBytes > sizeof( allData )");
      v7 = v22;
      v6 = v19;
    }
    memcpy((unsigned __int8 *)dst, src: (unsigned __int8 *)count.buf, count: count.len);
    memcpy(dst: (unsigned __int8 *)&dst[count.len], src: p_m_iCurActiveChunk, count: v17);
    memcpy(dst: (unsigned __int8 *)&dst[count.len + v17], src: m_pMemory, count: v6);
    memcpy(dst: (unsigned __int8 *)&dst[count.len + v17 + v6], src: v7, count: v21);
    v9 = len;
    v10 = sendto(
            s: this->m_Socket,
            buf: dst,
            len,
            flags: 0,
            to: (const struct sockaddr *)&this->m_MulticastAddr,
            tolen: 16) == v9;
    v11 = NumberOfBytesSent;
  }
  if ( v10 )
  {
    *pnBytesSent = v11;
    return v10;
  }
  v13 = `CMasterMulticastThread::Thread_SendFileChunk_Multicast'::`14'::nWarnings + 1;
  `CMasterMulticastThread::Thread_SendFileChunk_Multicast'::`14'::nWarnings = v13;
  if ( v13 >= 10 )
  {
    if ( v13 == 10 )
      _Warning(a1: "\nThis machine's ability to multicast may be broken. Please reboot and try again.\n");
  }
  else
  {
    _Warning(a1: "\nMulticastThread: WSASendTo with %d bytes sent %d bytes.\n", v9, v11);
    LastError = GetLastError();
    if ( FormatMessageA(
           dwFlags: 0x1300u,
           lpSource: nullptr,
           dwMessageId: LastError,
           dwLanguageId: 0x400u,
           lpBuffer: Buffer,
           nSize: 0,
           Arguments: nullptr) != 0 )
    {
      _Warning(a1: "%s", *(const char **)Buffer);
      LocalFree(hMem: *(HLOCAL *)Buffer);
      return false;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100108F0
// Name: private: int CMasterMulticastThread::FindFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FindFile(CMasterMulticastThread *this, const char *pName, const char *pPathID)
{
  int m_Head; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  CMasterMulticastThread *v6; // [esp+Ch] [ebp-4h]

  m_Head = this->m_Files.m_Head;
  v6 = this;
  if ( m_Head == -1 )
    return -1;
  while ( 1 )
  {
    m_Element = this->m_Files.m_Memory.m_pMemory[m_Head].m_Element;
    if ( _V_stricmp(s1: m_Element->m_Filename.m_Memory.m_pMemory, s2: pName) == 0
      && _V_stricmp(s1: m_Element->m_PathID.m_Memory.m_pMemory, s2: pPathID) == 0 )
    {
      break;
    }
    m_Head = v6->m_Files.m_Memory.m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      return -1;
    this = v6;
  }
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x10010970
// Name: private: void CMasterMulticastThread::EnsureMemoryLimit(class CMasterMulticastThread::CMulticastFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::EnsureMemoryLimit(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pIgnore)
{
  unsigned int m_nMaxMemoryUsage; // eax
  int i; // eax
  int v5; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // esi

  m_nMaxMemoryUsage = this->m_nMaxMemoryUsage;
  if ( m_nMaxMemoryUsage != 0 && this->m_nCurMemoryUsage > m_nMaxMemoryUsage )
  {
    for ( i = this->m_Files.m_Head; i != -1; i = this->m_Files.m_Memory.m_pMemory[v5].m_Next )
    {
      v5 = i;
      m_Element = this->m_Files.m_Memory.m_pMemory[i].m_Element;
      if ( m_Element != pIgnore && m_Element->m_bDataLoaded && m_Element->m_ActiveChunks.m_ElementCount == 0 )
      {
        this->m_nCurMemoryUsage -= m_Element->m_Info.m_CompressedSize + m_Element->m_Info.m_UncompressedSize;
        CUtlVector<char,CUtlMemory<char,int>>::Purge(this: &m_Element->m_Data);
        CUtlVector<char,CUtlMemory<char,int>>::Purge(this: &m_Element->m_UncompressedData);
        m_Element->m_bDataLoaded = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010B50
// Name: public: CTransmitRateMgr::CTransmitRateMgr(void)
// Source: json
//------------------------------------------------------------------------------
CTransmitRateMgr *__thiscall CTransmitRateMgr::CTransmitRateMgr(CTransmitRateMgr *this)
{
  long double v2; // xmm1_8
  ISocket *IPSocket; // eax
  unsigned __int64 v5; // [esp-14h] [ebp-20h]
  CCycleCount cnt; // [esp+0h] [ebp-Ch] BYREF
  CCycleCount *p_cnt; // [esp+8h] [ebp-4h]

  this->m_MachineRecords.m_Memory.m_pMemory = nullptr;
  this->m_MachineRecords.m_Memory.m_nAllocationCount = 0;
  this->m_MachineRecords.m_Memory.m_nGrowSize = 0;
  this->m_MachineRecords.m_Size = 0;
  this->m_MachineRecords.m_pElements = nullptr;
  v2 = 1000000.0 / (double)MULTICAST_TRANSMIT_RATE;
  this->m_flLastBroadcastTime = 0.0;
  this->m_nMicrosecondsPerByte = v2;
  this->m_UniqueID = (unsigned int)this;
  p_cnt = &cnt;
  cnt.m_Int64 = __rdtsc();
  HIDWORD(v5) = HIDWORD(_g_ClockSpeed);
  LODWORD(v5) = _g_ClockSpeed;
  this->m_UniqueID += 1000000 * cnt.m_Int64 / v5;
  Sleep(dwMilliseconds: 1u);
  HIDWORD(v5) = HIDWORD(_g_ClockSpeed);
  LODWORD(v5) = _g_ClockSpeed;
  this->m_UniqueID += 1000000 * cnt.m_Int64 / v5;
  IPSocket = CreateIPSocket();
  this->m_pSocket = IPSocket;
  if ( IPSocket != nullptr )
    IPSocket->BindToAny(this: IPSocket, a2: 21146u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10010C30
// Name: public: CMasterMulticastThread::CMasterMulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
CMasterMulticastThread *__thiscall CMasterMulticastThread::CMasterMulticastThread(CMasterMulticastThread *this)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *m_pMemory; // ecx
  UtlLinkedListElem_t<char *,int> *v3; // edx

  this->m_Files.m_Memory.m_pMemory = nullptr;
  this->m_Files.m_Memory.m_nAllocationCount = 0;
  this->m_Files.m_Memory.m_nGrowSize = 0;
  this->m_Files.m_LastAlloc.index = -1;
  m_pMemory = this->m_Files.m_Memory.m_pMemory;
  this->m_Files.m_Head = -1;
  this->m_Files.m_Tail = -1;
  this->m_Files.m_FirstFree = -1;
  this->m_Files.m_ElementCount = 0;
  this->m_Files.m_NumAlloced = 0;
  this->m_Files.m_pElements = m_pMemory;
  this->m_WarningSuppressions.m_Memory.m_pMemory = nullptr;
  this->m_WarningSuppressions.m_Memory.m_nAllocationCount = 0;
  this->m_WarningSuppressions.m_Memory.m_nGrowSize = 0;
  this->m_WarningSuppressions.m_LastAlloc.index = -1;
  v3 = this->m_WarningSuppressions.m_Memory.m_pMemory;
  this->m_WarningSuppressions.m_Head = -1;
  this->m_WarningSuppressions.m_Tail = -1;
  this->m_WarningSuppressions.m_FirstFree = -1;
  this->m_WarningSuppressions.m_ElementCount = 0;
  this->m_WarningSuppressions.m_NumAlloced = 0;
  this->m_WarningSuppressions.m_pElements = v3;
  this->m_hMainThread = nullptr;
  this->m_hThread = nullptr;
  this->m_Socket = -1;
  this->m_nTotalActiveChunks = 0;
  this->m_iCurActiveChunk = -1;
  this->m_iCurFile = -1;
  this->m_pPassThru = nullptr;
  this->m_hTermEvent = CreateEventA(
                         lpEventAttributes: nullptr,
                         bManualReset: false,
                         bInitialState: false,
                         lpName: nullptr);
  InitializeCriticalSection(lpCriticalSection: &this->m_CS);
  this->m_nMaxMemoryUsage = 0;
  this->m_nCurMemoryUsage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10010CD0
// Name: public: CMasterMulticastThread::CMulticastFile::CMulticastFile(void)
// Source: json
//------------------------------------------------------------------------------
CMasterMulticastThread::CMulticastFile *__thiscall CMasterMulticastThread::CMulticastFile::CMulticastFile(
        CMasterMulticastThread::CMulticastFile *this)
{
  CMasterMulticastThread::CMulticastFile *result; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // ecx

  result = this;
  this->m_Filename.m_Memory.m_pMemory = nullptr;
  this->m_Filename.m_Memory.m_nAllocationCount = 0;
  this->m_Filename.m_Memory.m_nGrowSize = 0;
  this->m_Filename.m_Size = 0;
  this->m_Filename.m_pElements = nullptr;
  this->m_PathID.m_Memory.m_pMemory = nullptr;
  this->m_PathID.m_Memory.m_nAllocationCount = 0;
  this->m_PathID.m_Memory.m_nGrowSize = 0;
  this->m_PathID.m_Size = 0;
  this->m_PathID.m_pElements = nullptr;
  this->m_UncompressedData.m_Memory.m_pMemory = nullptr;
  this->m_UncompressedData.m_Memory.m_nAllocationCount = 0;
  this->m_UncompressedData.m_Memory.m_nGrowSize = 0;
  this->m_UncompressedData.m_Size = 0;
  this->m_UncompressedData.m_pElements = nullptr;
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_Chunks.m_Memory.m_pMemory = nullptr;
  this->m_Chunks.m_Memory.m_nAllocationCount = 0;
  this->m_Chunks.m_Memory.m_nGrowSize = 0;
  this->m_Chunks.m_Size = 0;
  this->m_Chunks.m_pElements = nullptr;
  this->m_ActiveChunks.m_Memory.m_pMemory = nullptr;
  this->m_ActiveChunks.m_Memory.m_nAllocationCount = 0;
  this->m_ActiveChunks.m_Memory.m_nGrowSize = 0;
  this->m_ActiveChunks.m_LastAlloc.index = -1;
  this->m_ActiveChunks.m_Head = -1;
  this->m_ActiveChunks.m_Tail = -1;
  this->m_ActiveChunks.m_FirstFree = -1;
  this->m_ActiveChunks.m_ElementCount = 0;
  this->m_ActiveChunks.m_NumAlloced = 0;
  this->m_ActiveChunks.m_pElements = this->m_ActiveChunks.m_Memory.m_pMemory;
  this->m_Clients.m_Memory.m_pMemory = nullptr;
  this->m_Clients.m_Memory.m_nAllocationCount = 0;
  this->m_Clients.m_Memory.m_nGrowSize = 0;
  this->m_Clients.m_LastAlloc.index = -1;
  this->m_Clients.m_ElementCount = 0;
  this->m_Clients.m_NumAlloced = 0;
  m_pMemory = this->m_Clients.m_Memory.m_pMemory;
  result->m_Clients.m_Head = -1;
  result->m_Clients.m_Tail = -1;
  result->m_Clients.m_FirstFree = -1;
  result->m_Clients.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010DF0
// Name: public: void CTransmitRateMgr::ReadPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransmitRateMgr::ReadPackets(CTransmitRateMgr *this)
{
  int i; // eax
  unsigned int v3; // ebx
  int v4; // eax
  bool v5; // zf
  CTransmitRateMgr::CMachineRecord *m_pMemory; // ecx
  int v7; // eax
  float v8; // xmm0_4
  int j; // edi
  char data[512]; // [esp+4h] [ebp-20Ch] BYREF
  CIPAddr ipFrom; // [esp+204h] [ebp-Ch] BYREF
  float flCurTime; // [esp+20Ch] [ebp-4h]

  if ( this->m_pSocket != nullptr )
  {
    flCurTime = _Plat_FloatTime();
    CIPAddr::CIPAddr(this: &ipFrom);
    for ( i = this->m_pSocket->RecvFrom(this: this->m_pSocket, a2: data, a3: 512, a4: &ipFrom);
          i != -1;
          i = this->m_pSocket->RecvFrom(this: this->m_pSocket, a2: data, a3: 512, a4: &ipFrom) )
    {
      if ( i == 10
        && *(_DWORD *)data == *(_DWORD *)s_cTransmitRateMgrPacket
        && s_cTransmitRateMgrPacket[4] == data[4]
        && s_cTransmitRateMgrPacket[5] == data[5] )
      {
        v3 = *(_DWORD *)&data[6];
        if ( *(_DWORD *)&data[6] != this->m_UniqueID )
        {
          v4 = 0;
          v5 = this->m_MachineRecords.m_Size == 0;
          if ( this->m_MachineRecords.m_Size > 0 )
          {
            m_pMemory = this->m_MachineRecords.m_Memory.m_pMemory;
            while ( m_pMemory->m_UniqueID != *(_DWORD *)&data[6] )
            {
              ++v4;
              ++m_pMemory;
              if ( v4 >= this->m_MachineRecords.m_Size )
                goto LABEL_14;
            }
            this->m_MachineRecords.m_Memory.m_pMemory[v4].m_flLastTime = flCurTime;
LABEL_14:
            v5 = v4 == this->m_MachineRecords.m_Size;
          }
          if ( v5 )
          {
            v7 = CUtlVector<CTransmitRateMgr::CMachineRecord,CUtlMemory<CTransmitRateMgr::CMachineRecord,int>>::AddToTail(this: &this->m_MachineRecords);
            v8 = flCurTime;
            this->m_MachineRecords.m_Memory.m_pMemory[v7].m_UniqueID = v3;
            this->m_MachineRecords.m_Memory.m_pMemory[v7].m_flLastTime = v8;
          }
        }
      }
      CIPAddr::CIPAddr(this: &ipFrom);
    }
    for ( j = 0; j < this->m_MachineRecords.m_Size; ++j )
    {
      if ( (float)(flCurTime - this->m_MachineRecords.m_Memory.m_pMemory[j].m_flLastTime) > 0.7 )
      {
        if ( this->m_MachineRecords.m_Size - j - 1 > 0 )
          _V_memmove(
            dest: &this->m_MachineRecords.m_Memory.m_pMemory[j],
            src: &this->m_MachineRecords.m_Memory.m_pMemory[j + 1],
            count: 8 * (this->m_MachineRecords.m_Size - j - 1));
        --this->m_MachineRecords.m_Size;
        --j;
      }
    }
    this->m_nMicrosecondsPerByte = 1000000.0 / (double)(MULTICAST_TRANSMIT_RATE / (this->m_MachineRecords.m_Size + 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011090
// Name: ZLibCompress
// Source: json
//------------------------------------------------------------------------------
char __usercall ZLibCompress@<al>(CUtlMemory<unsigned char,int> *out@<esi>, unsigned __int8 *pData, unsigned int len)
{
  int v3; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned int v9; // edx
  int v10; // ebx
  z_stream_s zs; // [esp+8h] [ebp-38h] BYREF

  v3 = len;
  if ( len != 0 )
  {
    memset(dst: (unsigned __int8 *)&zs, value: 0, count: sizeof(zs));
    if ( deflateInit_(a1: &zs, a2: 1, a3: "1.1.3", a4: 56) != 0 )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        out[1].m_pMemory = nullptr;
        if ( v3 != 0 )
        {
          m_nAllocationCount = out->m_nAllocationCount;
          if ( v3 > m_nAllocationCount )
            CUtlMemory<bool,int>::Grow(this: out, num: v3 - m_nAllocationCount);
          out[1].m_pMemory += v3;
          m_pMemory = (char *)out->m_pMemory;
          v7 = (int)&out[1].m_pMemory[-v3];
          out[1].m_nAllocationCount = (int)out->m_pMemory;
          if ( v7 > 0 && v3 > 0 )
            _V_memmove(dest: &m_pMemory[v3], src: m_pMemory, count: v7);
        }
        v8 = out->m_pMemory;
        zs.avail_in = len;
        zs.next_in = pData;
        v9 = (unsigned int)out[1].m_pMemory;
        zs.next_out = v8;
        zs.avail_out = v9;
        v10 = deflate(a1: &zs, a2: 4);
        deflateEnd(a1: &zs);
        if ( v10 == 1 )
          break;
        if ( v10 != 0 )
          return 0;
        v3 += 0x20000;
        memset(dst: (unsigned __int8 *)&zs, value: 0, count: sizeof(zs));
        if ( deflateInit_(a1: &zs, a2: 1, a3: "1.1.3", a4: 56) != 0 )
          return 0;
      }
      out[1].m_pMemory -= (unsigned int)&out[1].m_pMemory[-zs.total_out];
      return 1;
    }
  }
  else
  {
    out[1].m_pMemory = nullptr;
    if ( out->m_nGrowSize >= 0 )
    {
      if ( out->m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: out->m_pMemory);
        out->m_pMemory = nullptr;
      }
      out->m_nAllocationCount = 0;
    }
    out[1].m_nAllocationCount = (int)out->m_pMemory;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100111F0
// Name: public: CMasterMulticastThread::CMulticastFile::~CMulticastFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::CMulticastFile::~CMulticastFile(CMasterMulticastThread::CMulticastFile *this)
{
  CUtlLinkedList<CMasterMulticastThread::CClientFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Clients);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Clients);
  if ( this->m_Clients.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Clients.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Clients.m_Memory.m_pMemory);
      this->m_Clients.m_Memory.m_pMemory = nullptr;
    }
    this->m_Clients.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_ActiveChunks);
  if ( this->m_ActiveChunks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ActiveChunks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ActiveChunks.m_Memory.m_pMemory);
      this->m_ActiveChunks.m_Memory.m_pMemory = nullptr;
    }
    this->m_ActiveChunks.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Chunks);
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Data);
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_UncompressedData);
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_PathID);
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Filename);
}

//------------------------------------------------------------------------------
// Address: 0x10011510
// Name: public: void CMasterMulticastThread::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::Term(CMasterMulticastThread *this)
{
  if ( this->m_hThread != nullptr )
  {
    SetEvent(hEvent: this->m_hTermEvent);
    WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  if ( this->m_Socket != -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  CUtlLinkedList<CMasterMulticastThread::CMulticastFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Files);
  this->m_nMaxMemoryUsage = 0;
  this->m_nCurMemoryUsage = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011570
// Name: private: void CMasterMulticastThread::DecrementChunkRefCount(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::DecrementChunkRefCount(CMasterMulticastThread *this, int iFile, int iChunk)
{
  int v4; // ecx
  CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *m_Element; // ebx
  int m_FirstFree; // edx
  bool v7; // zf
  int v8; // edi
  volatile int m_iCurFile; // edx
  int v10; // eax
  int v11; // edi
  unsigned __int16 v12; // ax

  v4 = iFile;
  m_Element = (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)this->m_Files.m_Memory.m_pMemory[iFile].m_Element;
  m_FirstFree = m_Element[2].m_FirstFree;
  v7 = *(_WORD *)(m_FirstFree + 6 * iChunk + 2) == 0;
  v8 = m_FirstFree + 6 * iChunk;
  iChunk = v8;
  if ( v7 )
  {
    _Error(a1: "CMasterMulticastThread::DecrementChunkRefCount - refcount already zero!\n");
    v4 = iFile;
  }
  v7 = (*(_WORD *)(v8 + 2))-- == 1;
  if ( v7 )
  {
    m_iCurFile = this->m_iCurFile;
    --this->m_nTotalActiveChunks;
    if ( v4 == m_iCurFile )
    {
      v10 = *(unsigned __int16 *)(iChunk + 4);
      if ( v10 == this->m_iCurActiveChunk )
        this->m_iCurActiveChunk = m_Element[3].m_Memory.m_pMemory[v10].m_Next;
    }
    v11 = *(unsigned __int16 *)(iChunk + 4);
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: m_Element + 3,
      elem: v11);
    m_Element[3].m_Memory.m_pMemory[v11].m_Next = m_Element[3].m_FirstFree;
    m_Element[3].m_FirstFree = v11;
    v12 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToTail(
            this: (CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int> > *)&m_Element[3],
            src: (CMasterMulticastThread::CChunkInfo **)&iChunk);
    *(_WORD *)(iChunk + 4) = v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011620
// Name: private: int CMasterMulticastThread::FinishFileSetup(class CMasterMulticastThread::CMulticastFile __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FinishFileSetup(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pFile,
        const char *pFilename,
        CMasterMulticastThread::CChunkInfo *pPathID,
        bool bFileAlreadyExisted)
{
  CMasterMulticastThread::CMulticastFile *v5; // edi
  CMasterMulticastThread *v6; // ebx
  unsigned int v8; // esi
  const char *v9; // ecx
  char *m_pMemory; // edx
  char v11; // al
  CMasterMulticastThread::CChunkInfo *v12; // ecx
  char *v13; // edx
  char m_iChunk; // al
  int v15; // ebx
  unsigned __int16 v16; // ax
  char *v17; // esi
  __int16 v18; // ax

  v5 = pFile;
  v6 = this;
  if ( ZLibCompress(
         out: (CUtlMemory<unsigned char,int> *)&pFile->m_Data,
         pData: (unsigned __int8 *)pFile->m_UncompressedData.m_Memory.m_pMemory,
         len: pFile->m_UncompressedData.m_Size) != 0 )
  {
    v5->m_bDataLoaded = true;
    v8 = VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_TCP ? 1024 : 0x4000;
    if ( !bFileAlreadyExisted )
    {
      CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v5->m_Filename,
        size: strlen(pFilename) + 1);
      v9 = pFilename;
      m_pMemory = v5->m_Filename.m_Memory.m_pMemory;
      do
      {
        v11 = *v9;
        *m_pMemory++ = *v9++;
      }
      while ( v11 != 0 );
      CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v5->m_PathID,
        size: strlen((const char *)pPathID) + 1);
      v12 = pPathID;
      v13 = v5->m_PathID.m_Memory.m_pMemory;
      do
      {
        m_iChunk = v12->m_iChunk;
        *v13 = v12->m_iChunk;
        v12 = (CMasterMulticastThread::CChunkInfo *)((char *)v12 + 1);
        ++v13;
      }
      while ( m_iChunk != 0 );
      v15 = 0;
      v5->m_nCycles = 0;
      v5->m_Info.m_CompressedSize = v5->m_Data.m_Size;
      v5->m_Info.m_UncompressedSize = v5->m_UncompressedData.m_Size;
      v16 = v8 * ((v5->m_Info.m_CompressedSize + v8 - 1) / v8) / v8;
      v5->m_Info.m_nChunks = v16;
      v5->m_Chunks.m_Size = 0;
      CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::InsertMultipleBefore(
        this: &v5->m_Chunks,
        elem: 0,
        num: v16);
      if ( v5->m_Chunks.m_Size > 0 )
      {
        pFilename = nullptr;
        do
        {
          v17 = (char *)&pFilename[(unsigned int)v5->m_Chunks.m_Memory.m_pMemory];
          *(_WORD *)v17 = v15;
          pPathID = (CMasterMulticastThread::CChunkInfo *)v17;
          *((_WORD *)v17 + 1) = 0;
          v18 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToTail(
                  this: &v5->m_ActiveChunks,
                  src: &pPathID);
          pFilename += 6;
          ++v15;
          *((_WORD *)v17 + 2) = v18;
        }
        while ( v15 < v5->m_Chunks.m_Size );
      }
      EnterCriticalSection(lpCriticalSection: &this->m_CS);
      v6 = this;
    }
    v6->m_nCurMemoryUsage += v5->m_Info.m_CompressedSize + v5->m_Info.m_UncompressedSize;
    CMasterMulticastThread::EnsureMemoryLimit(this: v6, pIgnore: v5);
    if ( !bFileAlreadyExisted )
    {
      v5->m_Info.m_FileID = CUtlLinkedList<CMasterMulticastThread::CMulticastFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>>::AddToTail(
                              this: &v6->m_Files,
                              src: &pFile);
      LeaveCriticalSection(lpCriticalSection: &v6->m_CS);
    }
    return v5->m_Info.m_FileID;
  }
  else
  {
    CMasterMulticastThread::CMulticastFile::~CMulticastFile(this: v5);
    free(pMem: v5);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100117B0
// Name: public: virtual void CMasterVMPIFileSystem::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::Term(CMasterVMPIFileSystem *this)
{
  CMasterMulticastThread::Term(this: &this->m_MasterThread);
}

//------------------------------------------------------------------------------
// Address: 0x100117C0
// Name: public: CMasterMulticastThread::~CMasterMulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::~CMasterMulticastThread(CMasterMulticastThread *this)
{
  CMasterMulticastThread::Term(this);
  CloseHandle(hObject: this->m_hTermEvent);
  DeleteCriticalSection(lpCriticalSection: &this->m_CS);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_WarningSuppressions);
  if ( this->m_WarningSuppressions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WarningSuppressions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WarningSuppressions.m_Memory.m_pMemory);
      this->m_WarningSuppressions.m_Memory.m_pMemory = nullptr;
    }
    this->m_WarningSuppressions.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll((CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)this);
  if ( this->m_Files.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Files.m_Memory.m_pMemory);
      this->m_Files.m_Memory.m_pMemory = nullptr;
    }
    this->m_Files.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011850
// Name: public: void CMasterMulticastThread::OnChunkReceived(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnChunkReceived(
        CMasterMulticastThread *this,
        int fileID,
        int clientID,
        int iChunk)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v4; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  int m_Head; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // edx
  CMasterMulticastThread::CClientFileInfo *v8; // esi

  if ( fileID >= 0
    && fileID < this->m_Files.m_Memory.m_nAllocationCount
    && fileID <= this->m_Files.m_LastAlloc.index
    && ((v4 = &this->m_Files.m_Memory.m_pMemory[fileID])->m_Previous != fileID || v4->m_Next == fileID) )
  {
    m_Element = v4->m_Element;
    m_Head = v4->m_Element->m_Clients.m_Head;
    if ( m_Head != -1 )
    {
      m_pMemory = m_Element->m_Clients.m_Memory.m_pMemory;
      while ( m_pMemory[m_Head].m_Element->m_ClientID != clientID )
      {
        m_Head = m_pMemory[m_Head].m_Next;
        if ( m_Head == -1 )
          return;
      }
      v8 = m_pMemory[m_Head].m_Element;
      if ( v8 != nullptr )
      {
        if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
        {
          EnterCriticalSection(lpCriticalSection: &this->m_CS);
          CMasterMulticastThread::TCP_SendNextChunk(this, pFile: m_Element, pClient: v8);
          LeaveCriticalSection(lpCriticalSection: &this->m_CS);
        }
        else if ( iChunk >= 0 && iChunk < m_Element->m_Chunks.m_Size )
        {
          v8->m_ChunksToSend.m_Memory.m_pMemory[iChunk >> 3] &= ~(1 << (iChunk & 7));
          --v8->m_nChunksLeft;
          v8->m_flLastAckTime = _Plat_FloatTime();
          if ( v8->m_nChunksLeft == 0 && g_iVMPIVerboseLevel >= 2 )
            _Warning(a1: "Client %d got file %s\n", clientID, m_Element->m_Filename.m_Memory.m_pMemory);
          EnterCriticalSection(lpCriticalSection: &this->m_CS);
          CMasterMulticastThread::DecrementChunkRefCount(this, iFile: fileID, iChunk);
          LeaveCriticalSection(lpCriticalSection: &this->m_CS);
        }
        else
        {
          _Warning(
            a1: "CMasterMulticastThread::OnChunkReceived: invalid chunk index (%d) for file %s\n",
            iChunk,
            m_Element->m_Filename.m_Memory.m_pMemory);
        }
      }
    }
  }
  else
  {
    _Warning(a1: "CMasterMulticastThread::OnChunkReceived: invalid file (%d) from client %d\n", fileID, clientID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100119B0
// Name: public: void CMasterMulticastThread::OnFileReceived(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnFileReceived(CMasterMulticastThread *this, int fileID, int clientID)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v3; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  int v5; // esi
  CMasterMulticastThread *v6; // [esp+4h] [ebp-4h]

  v6 = this;
  if ( fileID >= 0
    && fileID < this->m_Files.m_Memory.m_nAllocationCount
    && fileID <= this->m_Files.m_LastAlloc.index
    && ((v3 = &this->m_Files.m_Memory.m_pMemory[fileID])->m_Previous != fileID || v3->m_Next == fileID) )
  {
    m_Element = v3->m_Element;
    v5 = 0;
    if ( v3->m_Element->m_Info.m_nChunks != 0 )
    {
      while ( 1 )
      {
        CMasterMulticastThread::OnChunkReceived(this, fileID, clientID, iChunk: v5++);
        if ( v5 >= m_Element->m_Info.m_nChunks )
          break;
        this = v6;
      }
    }
  }
  else
  {
    _Warning(a1: "CMasterMulticastThread::OnChunkReceived: invalid file (%d) from client %d\n", fileID, clientID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011A30
// Name: public: void CMasterMulticastThread::OnClientDisconnect(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnClientDisconnect(
        CMasterMulticastThread *this,
        int clientID,
        bool bGrabCriticalSection)
{
  CMasterMulticastThread *v3; // edi
  int m_Head; // eax
  int v5; // ecx
  CMasterMulticastThread::CMulticastFile *m_Element; // edx
  int v7; // esi
  int v8; // eax
  _DWORD *v9; // edi
  int v10; // ebx
  bool v11; // sf
  void *v12; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // edi
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *v14; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  int v17; // [esp+4h] [ebp-10h]
  int iFile; // [esp+8h] [ebp-Ch]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+10h] [ebp-4h]

  v3 = this;
  if ( bGrabCriticalSection )
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
  m_Head = v3->m_Files.m_Head;
  iFile = m_Head;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      v5 = 12 * m_Head;
      m_Element = v3->m_Files.m_Memory.m_pMemory[m_Head].m_Element;
      v7 = m_Element->m_Clients.m_Head;
      v17 = 12 * m_Head;
      pFile = m_Element;
      if ( v7 != -1 )
      {
        while ( 1 )
        {
          v8 = (int)&m_Element->m_Clients.m_Memory.m_pMemory[v7];
          v9 = *(_DWORD **)v8;
          if ( **(_DWORD **)v8 == clientID )
            break;
          v7 = *(_DWORD *)(v8 + 8);
          if ( v7 == -1 )
            goto LABEL_34;
        }
        v10 = 0;
        if ( m_Element->m_Info.m_nChunks != 0 )
        {
          do
          {
            if ( ((unsigned __int8)(1 << (v10 & 7)) & *(_BYTE *)((v10 >> 3) + v9[1])) != 0 )
              CMasterMulticastThread::DecrementChunkRefCount(this, iFile, iChunk: v10);
            ++v10;
          }
          while ( v10 < pFile->m_Info.m_nChunks );
        }
        v11 = (int)v9[3] < 0;
        v9[4] = 0;
        if ( !v11 )
        {
          if ( v9[1] != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v9[1]);
            v9[1] = 0;
          }
          v9[2] = 0;
        }
        v11 = (int)v9[3] < 0;
        v12 = (void *)v9[1];
        v9[5] = v12;
        if ( !v11 )
        {
          if ( v12 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
            v9[1] = 0;
          }
          v9[2] = 0;
        }
        free(pMem: v9);
        if ( v7 >= 0 && v7 < pFile->m_Clients.m_Memory.m_nAllocationCount && v7 <= pFile->m_Clients.m_LastAlloc.index )
        {
          m_pMemory = pFile->m_Clients.m_Memory.m_pMemory;
          v14 = &m_pMemory[v7];
          if ( v14->m_Previous != v7 )
          {
            m_Previous = v14->m_Previous;
            if ( m_Previous == -1 )
              pFile->m_Clients.m_Head = v14->m_Next;
            else
              m_pMemory[m_Previous].m_Next = v14->m_Next;
            m_Next = v14->m_Next;
            if ( m_Next == -1 )
              pFile->m_Clients.m_Tail = v14->m_Previous;
            else
              pFile->m_Clients.m_Memory.m_pMemory[m_Next].m_Previous = v14->m_Previous;
            v14->m_Next = v7;
            v14->m_Previous = v7;
            --pFile->m_Clients.m_ElementCount;
          }
        }
        pFile->m_Clients.m_Memory.m_pMemory[v7].m_Next = pFile->m_Clients.m_FirstFree;
        v5 = v17;
        pFile->m_Clients.m_FirstFree = v7;
LABEL_34:
        v3 = this;
      }
      iFile = *(int *)((char *)&v3->m_Files.m_Memory.m_pMemory->m_Next + v5);
      if ( iFile == -1 )
        break;
      m_Head = *(int *)((char *)&v3->m_Files.m_Memory.m_pMemory->m_Next + v5);
    }
  }
  if ( bGrabCriticalSection )
    LeaveCriticalSection(lpCriticalSection: &v3->m_CS);
}

//------------------------------------------------------------------------------
// Address: 0x10011C20
// Name: public: void CMasterMulticastThread::CreateVirtualFile(char const __near *,void const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::CreateVirtualFile(
        CMasterMulticastThread *this,
        const char *pFilename,
        const char *pData,
        unsigned int fileLength)
{
  CMasterMulticastThread::CMulticastFile *v5; // eax
  CMasterMulticastThread::CMulticastFile *v6; // esi

  if ( CMasterMulticastThread::FindFile(this, pName: pFilename, pPathID: "VMPI_VIRTUAL_FILES_PATH_ID") != -1 )
    _Error(a1: "CMasterMulticastThread::CreateVirtualFile( %s ) - file already exists!", pFilename);
  v5 = (CMasterMulticastThread::CMulticastFile *)operator new(nSize: 0xC8u);
  if ( v5 != nullptr )
    v6 = CMasterMulticastThread::CMulticastFile::CMulticastFile(this: v5);
  else
    v6 = nullptr;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &v6->m_UncompressedData, pArray: pData, size: fileLength);
  CMasterMulticastThread::FinishFileSetup(
    this,
    pFile: v6,
    pFilename,
    pPathID: (CMasterMulticastThread::CChunkInfo *)"VMPI_VIRTUAL_FILES_PATH_ID",
    bFileAlreadyExisted: false);
}

//------------------------------------------------------------------------------
// Address: 0x10011C90
// Name: private: bool CMasterMulticastThread::CheckClientTimeouts(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterMulticastThread::CheckClientTimeouts(CMasterMulticastThread *this)
{
  CMasterMulticastThread *v1; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // esi
  char v3; // bl
  int m_Head; // eax
  float v5; // xmm2_4
  int v6; // edx
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // eax
  CMasterMulticastThread::CClientFileInfo *v8; // esi
  int m_Next; // ecx
  float m_flLastAckTime; // xmm1_4
  int v11; // eax
  CMasterMulticastThread::CMulticastFile *v12; // ecx
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v13; // ebx
  float *v14; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *v15; // edi
  float **v16; // eax
  float *v17; // ecx
  const char *MachineName; // eax
  const char *v20; // [esp-4h] [ebp-34h]
  int iNext; // [esp+1Ch] [ebp-14h]
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v23; // [esp+24h] [ebp-Ch]
  float flCurTime; // [esp+28h] [ebp-8h]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+2Ch] [ebp-4h]

  v1 = this;
  m_Element = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element;
  v3 = 0;
  pFile = m_Element;
  flCurTime = _Plat_FloatTime();
  m_Head = m_Element->m_Clients.m_Head;
  if ( m_Head != -1 )
  {
    v5 = flCurTime;
    while ( 1 )
    {
      v6 = m_Head;
      m_pMemory = m_Element->m_Clients.m_Memory.m_pMemory;
      v8 = m_pMemory[v6].m_Element;
      m_Next = m_pMemory[v6].m_Next;
      iNext = m_Next;
      if ( v8->m_nChunksLeft != 0 && ++v8->m_nTimesFileCycled >= 5 )
      {
        m_flLastAckTime = v8->m_flLastAckTime;
        if ( (float)(v5 - m_flLastAckTime) > 20.0 )
        {
          v11 = v1->m_Files.m_Head;
          if ( v11 != -1 )
          {
            v23 = v1->m_Files.m_Memory.m_pMemory;
            do
            {
              v12 = v23[v11].m_Element;
              v13 = &v23[v11];
              v14 = (float *)v12->m_Clients.m_Head;
              if ( v14 != (float *)-1 )
              {
                v15 = v12->m_Clients.m_Memory.m_pMemory;
                do
                {
                  v16 = (float **)&v15[(_DWORD)v14];
                  v17 = *v16;
                  if ( *(_DWORD *)*v16 == v8->m_ClientID && m_flLastAckTime <= v17[10] )
                    m_flLastAckTime = v17[10];
                  v14 = v16[2];
                }
                while ( v14 != (float *)-1 );
                v1 = this;
              }
              v11 = v13->m_Next;
            }
            while ( v11 != -1 );
          }
          v20 = pFile->m_Filename.m_Memory.m_pMemory;
          MachineName = VMPI_GetMachineName(iProc: v8->m_ClientID);
          _Warning(
            a1: "\nClient %s timed out on file %s (latest: %.2f / cur: %.2f).\n",
            MachineName,
            v20,
            m_flLastAckTime,
            v5);
          CMasterMulticastThread::OnClientDisconnect(this: v1, clientID: v8->m_ClientID, bGrabCriticalSection: false);
          v5 = flCurTime;
          m_Next = iNext;
          v3 = 1;
        }
      }
      m_Head = m_Next;
      if ( m_Next == -1 )
        break;
      m_Element = pFile;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10011DE0
// Name: private: void CMasterMulticastThread::Thread_SeekToNextActiveChunk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::Thread_SeekToNextActiveChunk(CMasterMulticastThread *this)
{
  if ( this->m_iCurFile == -1 )
  {
    this->m_iCurFile = this->m_Files.m_Head;
    this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Head;
  }
  while ( this->m_iCurActiveChunk != -1
       && this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Element->m_RefCount != 0 )
  {
LABEL_10:
    if ( this->m_iCurActiveChunk != -1 )
    {
      if ( this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Element->m_RefCount != 0 )
        return;
      this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Next;
    }
  }
  if ( CMasterMulticastThread::CheckClientTimeouts(this) == 0 || this->m_nTotalActiveChunks != 0 )
  {
    this->m_iCurFile = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Next;
    if ( this->m_iCurFile == -1 )
      this->m_iCurFile = this->m_Files.m_Head;
    this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Head;
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011EC0
// Name: private: unsigned long CMasterMulticastThread::MulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMasterMulticastThread::MulticastThread(CMasterMulticastThread *this)
{
  void (__stdcall *v2)(LPCRITICAL_SECTION); // ebx
  DWORD v3; // eax
  double v4; // st7
  unsigned int v5; // ecx
  unsigned __int64 v7; // [esp-10h] [ebp-80h]
  CTransmitRateMgr transmitRateMgr; // [esp+4h] [ebp-6Ch] BYREF
  CRateLimiter rateLimiter; // [esp+34h] [ebp-3Ch] BYREF
  int v10; // [esp+44h] [ebp-2Ch] BYREF
  __int16 v11; // [esp+48h] [ebp-28h]
  unsigned int m_UniqueID; // [esp+4Ah] [ebp-26h]
  unsigned __int64 v13; // [esp+50h] [ebp-20h] BYREF
  CFastTimer timer; // [esp+58h] [ebp-18h] BYREF
  __int64 v15; // [esp+60h] [ebp-10h]
  unsigned int msToWait; // [esp+68h] [ebp-8h]
  int nBytesSent; // [esp+6Ch] [ebp-4h] BYREF

  CTransmitRateMgr::CTransmitRateMgr(this: &transmitRateMgr);
  rateLimiter.m_SleepIntervalMS = 50;
  rateLimiter.m_AccumulatedSleepMicroseconds = 0;
  msToWait = (unsigned int)&rateLimiter.m_LastSleepTime;
  rateLimiter.m_LastSleepTime.m_Int64 = __rdtsc();
  if ( WaitForSingleObject(hHandle: this->m_hTermEvent, dwMilliseconds: 0) != 0 )
  {
    v2 = LeaveCriticalSection;
    do
    {
      CRateLimiter::GiveUpTimeSlice(this: &rateLimiter);
      msToWait = 0;
      EnterCriticalSection(lpCriticalSection: &this->m_CS);
      CTransmitRateMgr::ReadPackets(this: &transmitRateMgr);
      if ( this->m_nTotalActiveChunks == 0 )
        goto LABEL_4;
      if ( transmitRateMgr.m_pSocket != nullptr )
      {
        v4 = _Plat_FloatTime();
        *(float *)&nBytesSent = v4;
        if ( v4 - transmitRateMgr.m_flLastBroadcastTime >= 0.3333333333333333 )
        {
          m_UniqueID = transmitRateMgr.m_UniqueID;
          v10 = *(_DWORD *)s_cTransmitRateMgrPacket;
          v11 = *(_WORD *)&s_cTransmitRateMgrPacket[4];
          LODWORD(transmitRateMgr.m_flLastBroadcastTime) = nBytesSent;
          transmitRateMgr.m_pSocket->Broadcast(this: transmitRateMgr.m_pSocket, a2: &v10, a3: 10, a4: 21146u);
        }
      }
      *(float *)&nBytesSent = COERCE_FLOAT(&timer);
      timer.m_Duration.m_Int64 = __rdtsc();
      CMasterMulticastThread::Thread_SeekToNextActiveChunk(this);
      if ( this->m_nTotalActiveChunks != 0 )
      {
        *(float *)&nBytesSent = 0.0;
        CMasterMulticastThread::Thread_SendFileChunk_Multicast(this, pnBytesSent: (unsigned int *)&nBytesSent);
        g_nMulticastBytesSent += nBytesSent;
        this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Next;
        v2(lpCriticalSection: &this->m_CS);
        HIDWORD(v15) = &v13;
        v13 = __rdtsc();
        timer.m_Duration.m_Int64 = v13 - timer.m_Duration.m_Int64;
        HIDWORD(v7) = HIDWORD(_g_ClockSpeed);
        LODWORD(v7) = _g_ClockSpeed;
        v5 = 1000000 * timer.m_Duration.m_Int64 / v7;
        v15 = (__int64)((double)(unsigned int)(nBytesSent + 32) * transmitRateMgr.m_nMicrosecondsPerByte);
        if ( v5 < (unsigned int)v15 )
          CRateLimiter::NoteExcessTimeTaken(this: &rateLimiter, excessTimeInMicroseconds: v15 - v5);
        v2 = LeaveCriticalSection;
        v3 = msToWait;
      }
      else
      {
LABEL_4:
        v2(lpCriticalSection: &this->m_CS);
        v3 = 50;
      }
    }
    while ( WaitForSingleObject(hHandle: this->m_hTermEvent, dwMilliseconds: v3) != 0 );
  }
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&transmitRateMgr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100120D0
// Name: public: int CMasterMulticastThread::FindOrAddFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FindOrAddFile(
        CMasterMulticastThread *this,
        const char *pFilename,
        char *pPathID)
{
  int result; // eax
  void *v5; // esi
  CMasterMulticastThread::CMulticastFile *v6; // eax
  int v7; // ebx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v10; // eax
  int v11; // esi
  bool bFileAlreadyExisted; // [esp+10h] [ebp-8h]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+14h] [ebp-4h]

  pFile = nullptr;
  bFileAlreadyExisted = false;
  result = CMasterMulticastThread::FindFile(this, pName: pFilename, pPathID);
  if ( result != -1 )
  {
    pFile = this->m_Files.m_Memory.m_pMemory[result].m_Element;
    if ( pFile->m_bDataLoaded )
      return result;
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
    bFileAlreadyExisted = true;
  }
  v5 = this->m_pPassThru->Open(this: this->m_pPassThru, a2: pFilename, a3: "rb", a4: *pPathID != 0 ? pPathID : nullptr);
  if ( v5 != nullptr )
  {
    if ( !bFileAlreadyExisted )
    {
      v6 = (CMasterMulticastThread::CMulticastFile *)operator new(nSize: 0xC8u);
      if ( v6 != nullptr )
        pFile = CMasterMulticastThread::CMulticastFile::CMulticastFile(this: v6);
      else
        pFile = nullptr;
    }
    v7 = this->m_pPassThru->Size_2(this: this->m_pPassThru, a2: v5);
    pFile->m_UncompressedData.m_Size = 0;
    if ( v7 != 0 )
    {
      m_nAllocationCount = pFile->m_UncompressedData.m_Memory.m_nAllocationCount;
      if ( v7 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&pFile->m_UncompressedData,
          num: v7 - m_nAllocationCount);
      pFile->m_UncompressedData.m_Size += v7;
      m_pMemory = pFile->m_UncompressedData.m_Memory.m_pMemory;
      v10 = pFile->m_UncompressedData.m_Size - v7;
      pFile->m_UncompressedData.m_pElements = m_pMemory;
      if ( v10 > 0 && v7 > 0 )
        _V_memmove(dest: &m_pMemory[v7], src: m_pMemory, count: v10);
    }
    this->m_pPassThru->Read(
      this: this->m_pPassThru,
      a2: pFile->m_UncompressedData.m_Memory.m_pMemory,
      a3: pFile->m_UncompressedData.m_Size,
      a4: v5);
    this->m_pPassThru->Close(this: this->m_pPassThru, a2: v5);
    v11 = CMasterMulticastThread::FinishFileSetup(
            this,
            pFile,
            pFilename,
            (CMasterMulticastThread::CChunkInfo *)pPathID,
            bFileAlreadyExisted);
    if ( bFileAlreadyExisted )
      LeaveCriticalSection(lpCriticalSection: &this->m_CS);
    return v11;
  }
  else
  {
    if ( bFileAlreadyExisted )
      LeaveCriticalSection(lpCriticalSection: &this->m_CS);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012230
// Name: public: virtual void __near * CMasterVMPIFileSystem::OpenEx(char const __near *,char const __near *,unsigned int,char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMasterVMPIFileSystem::OpenEx(
        CMasterVMPIFileSystem *this,
        const char *pFileName,
        const char *pOptions,
        unsigned int flags,
        const char *pathID,
        char **ppszResolvedFilename)
{
  return this->Open(this: &this->IBaseFileSystem, a2: pFileName, a3: pOptions, a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10012250
// Name: public: virtual void __near * CMasterVMPIFileSystem::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVMPIFile_Memory *__thiscall CMasterVMPIFileSystem::Open(
        CMasterVMPIFileSystem *this,
        const char *pFilename,
        char *pOptions,
        char *pPathID)
{
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  CVMPIFile_Memory *result; // eax
  IBaseFileSystem_vtbl *v10; // ecx
  IBaseFileSystem_vtbl *v11; // ecx
  char *v12; // eax
  int v13; // eax
  int v14; // esi
  CVMPIFile_Memory *v15; // eax
  CVMPIFile_Memory *v16; // edi
  int v17; // ebx
  const char *v18; // esi
  int v19; // eax

  if ( g_bDisableFileAccess )
    _Error(a1: "Open( %s, %s ) - file access has been disabled.", pFilename, pOptions);
  strchr(string: (unsigned __int8 *)pOptions, chr: 0x77u);
  if ( v5 != 0
    || (strchr(string: (unsigned __int8 *)pOptions, chr: 0x61u), v6 != 0)
    || (strchr(string: (unsigned __int8 *)pOptions, chr: 0x2Bu), v7 != 0) )
  {
    v8 = (*((int (__thiscall **)(IBaseFileSystem_vtbl *, const char *, char *, char *))this->Read + 2))(
           a1: this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable,
           a2: pFilename,
           a3: pOptions,
           a4: pPathID);
    if ( v8 == 0 )
      return nullptr;
    result = (CVMPIFile_Memory *)operator new(nSize: 0xCu);
    if ( result != nullptr )
    {
      result->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_PassThru::`vftable';
      v10 = this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable;
      result->m_DataLen = v8;
      result->m_pData = (const char *)v10;
    }
    else
    {
      v11 = this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable;
      MEMORY[8] = v8;
      MEMORY[4] = v11;
      return nullptr;
    }
  }
  else
  {
    v12 = pPathID;
    if ( pPathID == nullptr )
      v12 = (char *)setName;
    v13 = CMasterMulticastThread::FindOrAddFile(
            this: (CMasterMulticastThread *)&this->m_MulticastIP.port,
            pFilename,
            pPathID: v12);
    if ( v13 == -1 )
      return nullptr;
    v14 = *(_DWORD *)(*(_DWORD *)&this->m_MulticastIP.port + 12 * v13);
    v15 = (CVMPIFile_Memory *)operator new(nSize: 0x14u);
    if ( v15 != nullptr )
    {
      v15->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_Memory::`vftable';
      v16 = v15;
    }
    else
    {
      v16 = nullptr;
    }
    v17 = *(_DWORD *)(v14 + 68);
    v18 = *(const char **)(v14 + 56);
    strchr(string: (unsigned __int8 *)pOptions, chr: 0x74u);
    CVMPIFile_Memory::Init(this: v16, pData: v18, len: v17, chMode: v19 != 0 ? 116 : 98);
    return v16;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012370
// Name: private: static void CMasterVMPIFileSystem::OnClientDisconnect(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMasterVMPIFileSystem::OnClientDisconnect(int procID)
{
  CMasterMulticastThread::OnClientDisconnect(
    this: &CMasterVMPIFileSystem::s_pMasterVMPIFileSystem->m_MasterThread,
    clientID: procID,
    bGrabCriticalSection: true);
}

//------------------------------------------------------------------------------
// Address: 0x10012390
// Name: public: virtual void CMasterVMPIFileSystem::CreateVirtualFile(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::CreateVirtualFile(
        CMasterVMPIFileSystem *this,
        const char *pFilename,
        const char *pData,
        unsigned int fileLength)
{
  CMasterMulticastThread::CreateVirtualFile(this: &this->m_MasterThread, pFilename, pData, fileLength);
}

//------------------------------------------------------------------------------
// Address: 0x100123A0
// Name: public: int CMasterMulticastThread::AddFileRequest(char const __near *,char const __near *,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::AddFileRequest(
        CMasterMulticastThread *this,
        const char *pFilename,
        char *pPathID,
        int clientID,
        bool *bZeroLength)
{
  int result; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  CMasterMulticastThread::CClientFileInfo *v8; // eax
  CMasterMulticastThread::CClientFileInfo *v9; // edi
  int v10; // ecx
  double v11; // st7
  int v12; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 *m_pMemory; // edx
  int v15; // ecx
  CMasterMulticastThread::CChunkInfo *v16; // esi
  bool v17; // zf
  unsigned __int16 v18; // ax
  int v19; // eax
  int j; // esi
  int iFile; // [esp+4h] [ebp-14h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+8h] [ebp-10h]
  CMasterMulticastThread::CChunkInfo *src; // [esp+Ch] [ebp-Ch] BYREF
  CMasterMulticastThread *v24; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  const char *pFilenamea; // [esp+20h] [ebp+8h]
  const char *pFilenameb; // [esp+20h] [ebp+8h]

  v24 = this;
  result = CMasterMulticastThread::FindOrAddFile(this, pFilename, pPathID);
  iFile = result;
  if ( result != -1 )
  {
    m_Element = this->m_Files.m_Memory.m_pMemory[result].m_Element;
    lpCriticalSection = &this->m_CS;
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
    v8 = (CMasterMulticastThread::CClientFileInfo *)operator new(nSize: 0x30u);
    if ( v8 != nullptr )
    {
      v9 = v8;
      v8->m_ChunksToSend.m_Memory.m_pMemory = nullptr;
      v8->m_ChunksToSend.m_Memory.m_nAllocationCount = 0;
      v8->m_ChunksToSend.m_Memory.m_nGrowSize = 0;
      v8->m_ChunksToSend.m_Size = 0;
      v8->m_ChunksToSend.m_pElements = nullptr;
      pPathID = (char *)v8;
    }
    else
    {
      pPathID = nullptr;
      v9 = nullptr;
    }
    v10 = clientID;
    v9->m_TCP_LastChunkAcked = -1;
    v9->m_TCP_LastChunkSent = -1;
    v9->m_ClientID = v10;
    v11 = _Plat_FloatTime();
    v9->m_flLastAckTime = v11;
    v9->m_flTransmitStartTime = v11;
    v9->m_nTimesFileCycled = 0;
    v9->m_nChunksLeft = m_Element->m_Info.m_nChunks;
    v12 = 8 * ((m_Element->m_Info.m_nChunks + 7) / 8) / 8;
    pFilenamea = (const char *)v12;
    v9->m_ChunksToSend.m_Size = 0;
    if ( v12 != 0 )
    {
      m_nAllocationCount = v9->m_ChunksToSend.m_Memory.m_nAllocationCount;
      if ( v12 > m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(this: &v9->m_ChunksToSend.m_Memory, num: v12 - m_nAllocationCount);
        v12 = (int)pFilenamea;
      }
      v9->m_ChunksToSend.m_Size += v12;
      m_pMemory = v9->m_ChunksToSend.m_Memory.m_pMemory;
      v15 = v9->m_ChunksToSend.m_Size - v12;
      v9->m_ChunksToSend.m_pElements = m_pMemory;
      if ( v15 > 0 && v12 > 0 )
        _V_memmove(dest: &m_pMemory[v12], src: m_pMemory, count: v15);
    }
    memset(dst: v9->m_ChunksToSend.m_Memory.m_pMemory, value: 0xFFu, count: v9->m_ChunksToSend.m_Size);
    CUtlLinkedList<CMasterMulticastThread::CClientFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int>,int>>::AddToTail(
      this: &m_Element->m_Clients,
      src: (CMasterMulticastThread::CClientFileInfo **)&pPathID);
    i = 0;
    if ( m_Element->m_Chunks.m_Size > 0 )
    {
      pFilenameb = nullptr;
      do
      {
        v16 = (CMasterMulticastThread::CChunkInfo *)&pFilenameb[(unsigned int)m_Element->m_Chunks.m_Memory.m_pMemory];
        v17 = v16->m_RefCount == 0;
        src = v16;
        if ( v17 )
        {
          ++v24->m_nTotalActiveChunks;
          clientID = v16->m_iActiveChunksIndex;
          CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
            this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&m_Element->m_ActiveChunks,
            elem: clientID);
          m_Element->m_ActiveChunks.m_Memory.m_pMemory[clientID].m_Next = m_Element->m_ActiveChunks.m_FirstFree;
          m_Element->m_ActiveChunks.m_FirstFree = clientID;
          v18 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToHead(
                  this: &m_Element->m_ActiveChunks,
                  &src);
          v9 = (CMasterMulticastThread::CClientFileInfo *)pPathID;
          v16->m_iActiveChunksIndex = v18;
        }
        v19 = i;
        ++v16->m_RefCount;
        pFilenameb += 6;
        i = v19 + 1;
      }
      while ( v19 + 1 < m_Element->m_Chunks.m_Size );
    }
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
    {
      for ( j = 16; j != 0; --j )
        CMasterMulticastThread::TCP_SendNextChunk(this: v24, pFile: m_Element, pClient: v9);
    }
    LeaveCriticalSection(lpCriticalSection);
    *bZeroLength = m_Element->m_Info.m_UncompressedSize == 0;
    return iFile;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012570
// Name: private: static unsigned long CMasterMulticastThread::StaticMulticastThread(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CMasterMulticastThread::StaticMulticastThread(CMasterMulticastThread *pParameter)
{
  return CMasterMulticastThread::MulticastThread(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x100125D0
// Name: public: virtual bool CMasterVMPIFileSystem::HandleFileSystemPacket(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterVMPIFileSystem::HandleFileSystemPacket(
        CMasterVMPIFileSystem *this,
        CVMPIFile_Memory *pBuf,
        int iSource,
        int iPacketID)
{
  char *v5; // eax
  int v6; // edx
  int v7; // edx
  unsigned __int16 *v9; // esi
  unsigned __int16 *v10; // edi
  int v11; // eax
  int i; // ebx
  const char *v13; // esi
  unsigned int v14; // kr04_4
  int v15; // edi
  void *pChunks[4]; // [esp+Ch] [ebp-2Ch] BYREF
  int chunkLen[4]; // [esp+1Ch] [ebp-1Ch] BYREF
  int fileID; // [esp+2Ch] [ebp-Ch] BYREF
  int requestID; // [esp+30h] [ebp-8h] BYREF
  CMasterVMPIFileSystem *v20; // [esp+34h] [ebp-4h]

  v5 = (char *)pBuf->__vftable;
  v6 = SBYTE1(pBuf->Close) - 1;
  v20 = this;
  if ( v6 == 0 )
  {
    v13 = v5 + 6;
    requestID = *(_DWORD *)(v5 + 2);
    v14 = strlen(v5 + 6);
    v15 = iSource;
    if ( g_iVMPIVerboseLevel >= 2 )
      _Msg(a1: "Client %d requested '%s'\n", iSource, v13);
    fileID = CMasterMulticastThread::AddFileRequest(
               this: &v20->m_MasterThread,
               pFilename: v13,
               pPathID: (char *)&v13[v14 + 1],
               clientID: v15,
               bZeroLength: (bool *)&iSource + 3);
    pChunks[0] = &pBuf;
    pChunks[3] = (char *)&iSource + 3;
    pChunks[1] = &requestID;
    pChunks[2] = &fileID;
    LOWORD(pBuf) = 512;
    chunkLen[0] = 2;
    chunkLen[1] = 4;
    chunkLen[2] = 4;
    chunkLen[3] = 1;
    VMPI_SendChunks((const void *const *)pChunks, pChunkLengths: chunkLen, nChunks: 4, iDest: v15, fVMPISendFlags: 0);
    return 1;
  }
  v7 = v6 - 2;
  if ( v7 != 0 )
  {
    if ( v7 != 1 )
      return 0;
    CMasterMulticastThread::OnFileReceived(
      this: &this->m_MasterThread,
      fileID: *((unsigned __int16 *)v5 + 1),
      clientID: iSource);
    return 1;
  }
  v9 = (unsigned __int16 *)(v5 + 2);
  v10 = (unsigned __int16 *)(v5 + 4);
  v11 = (ConCommandBase::GetName(this: pBuf) - 2) / 4;
  if ( v11 <= 0 )
    return 1;
  pBuf = (CVMPIFile_Memory *)&this->m_MasterThread;
  for ( i = v11; i != 0; --i )
  {
    CMasterMulticastThread::OnChunkReceived(
      this: (CMasterMulticastThread *)pBuf,
      fileID: *v9,
      clientID: iSource,
      iChunk: *v10);
    v9 += 2;
    v10 += 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012710
// Name: public: bool CMasterMulticastThread::Init(class IBaseFileSystem __near *,unsigned short,class CIPAddr const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterMulticastThread::Init(
        CMasterMulticastThread *this,
        IBaseFileSystem *pPassThru,
        int localPort,
        const CIPAddr *pAddr,
        unsigned int maxMemoryUsage)
{
  SOCKET v6; // eax
  const CIPAddr *v8; // edi
  HANDLE v9; // eax
  SOCKET m_Socket; // [esp-14h] [ebp-34h]
  sockaddr_in addr; // [esp+8h] [ebp-18h] BYREF
  CIPAddr localAddr; // [esp+18h] [ebp-8h] BYREF

  CMasterMulticastThread::Term(this);
  this->m_nMaxMemoryUsage = maxMemoryUsage;
  this->m_nCurMemoryUsage = 0;
  if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
  {
    this->m_Socket = -1;
  }
  else
  {
    v6 = socket(af: 2, type: 2, protocol: 0);
    this->m_Socket = v6;
    if ( v6 == -1 )
    {
      _Warning(a1: "CMasterMulticastThread::Init - socket() failed\n");
      return 0;
    }
    CIPAddr::CIPAddr(this: &localAddr, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: (unsigned __int16)localPort);
    IPAddrToSockAddr(pIn: &localAddr, pOut: &addr);
    if ( bind(s: this->m_Socket, name: (const struct sockaddr *)&addr, namelen: 16) != 0 )
    {
      CMasterMulticastThread::Term(this);
      _Warning(
        a1: "CMasterMulticastThread::Init - bind( %d.%d.%d.%d:%d ) failed\n",
        pAddr->ip[0],
        pAddr->ip[1],
        pAddr->ip[2],
        pAddr->ip[3],
        pAddr->port);
      return 0;
    }
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
    {
      m_Socket = this->m_Socket;
      localPort = 1;
      if ( setsockopt(s: m_Socket, level: 0xFFFF, optname: 32, optval: (const char *)&localPort, optlen: 1) == -1 )
      {
        CMasterMulticastThread::Term(this);
        _Warning(a1: "CMasterMulticastThread::Init - setsockopt() failed to set broadcast mode\n");
        return 0;
      }
    }
    v8 = pAddr;
    IPAddrToSockAddr(pIn: pAddr, pOut: &this->m_MulticastAddr);
    maxMemoryUsage = 0;
    v9 = CreateThread(
           lpThreadAttributes: nullptr,
           dwStackSize: 0,
           lpStartAddress: (LPTHREAD_START_ROUTINE)CMasterMulticastThread::StaticMulticastThread,
           lpParameter: this,
           dwCreationFlags: 0,
           lpThreadId: &maxMemoryUsage);
    this->m_hThread = v9;
    if ( v9 == nullptr )
    {
      CMasterMulticastThread::Term(this);
      _Warning(
        a1: "CMasterMulticastThread::Init - CreateThread failed\n",
        v8->ip[0],
        v8->ip[1],
        v8->ip[2],
        v8->ip[3],
        v8->port);
      return 0;
    }
    SetThreadPriority(hThread: v9, nPriority: -2);
  }
  this->m_hMainThread = GetCurrentThread();
  this->m_pPassThru = pPassThru;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100128C0
// Name: public: bool CMasterVMPIFileSystem::Init(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterVMPIFileSystem::Init(
        CMasterVMPIFileSystem *this,
        unsigned int maxMemoryUsage,
        IFileSystem *pPassThru)
{
  IFileSystem *v3; // edi
  int v5; // ebx
  IBaseFileSystem *v6; // eax
  char result; // al
  unsigned __int64 v8; // [esp-8h] [ebp-20h]
  CCycleCount cnt; // [esp+Ch] [ebp-Ch] BYREF
  CCycleCount *p_cnt; // [esp+14h] [ebp-4h]

  v3 = pPassThru;
  this->InitPassThru_2(this, a2: pPassThru, a3: false);
  this->m_pMasterVMPIFileSystemPassThru = v3;
  p_cnt = &cnt;
  cnt.m_Int64 = __rdtsc();
  HIDWORD(v8) = HIDWORD(_g_ClockSpeed);
  LODWORD(v8) = _g_ClockSpeed;
  _RandomSeed(a1: 1000000 * cnt.m_Int64 / v8);
  v5 = (unsigned __int16)_RandomInt(a1: 22000, a2: 25000);
  if ( VMPI_GetRunMode() != VMPI_RUN_NETWORKED )
  {
    CIPAddr::Init(this: &this->m_MulticastIP, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: 0);
  }
  else if ( VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_MULTICAST )
  {
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
      CIPAddr::Init(this: &this->m_MulticastIP, ip0: 255, ip1: 255, ip2: 255, ip3: 255, ipPort: v5);
  }
  else
  {
    this->m_MulticastIP.port = v5;
    this->m_MulticastIP.ip[0] = _RandomInt(a1: 225, a2: 238);
    this->m_MulticastIP.ip[1] = _RandomInt(a1: 0, a2: 255);
    this->m_MulticastIP.ip[2] = _RandomInt(a1: 0, a2: 255);
    this->m_MulticastIP.ip[3] = _RandomInt(a1: 3, a2: 255);
  }
  if ( pPassThru != nullptr )
    v6 = &pPassThru->IBaseFileSystem;
  else
    v6 = nullptr;
  result = CMasterMulticastThread::Init(
             this: &this->m_MasterThread,
             pPassThru: v6,
             localPort: 23412,
             pAddr: &this->m_MulticastIP,
             maxMemoryUsage);
  if ( result != 0 )
  {
    LOWORD(pPassThru) = 1280;
    VMPI_Send2Chunks(
      pChunk1: &pPassThru,
      chunk1Len: 2,
      pChunk2: &this->m_MulticastIP,
      chunk2Len: 6,
      iDest: -3,
      fVMPISendFlags: 0);
    VMPI_AddDisconnectHandler(handler: (void (__cdecl *)(int, const char *))CMasterVMPIFileSystem::OnClientDisconnect);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012A30
// Name: class CBaseVMPIFileSystem __near * CreateMasterVMPIFileSystem(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CMasterVMPIFileSystem *__cdecl CreateMasterVMPIFileSystem(unsigned int maxMemoryUsage, IFileSystem *pPassThru)
{
  CMasterVMPIFileSystem *v2; // eax
  CMasterVMPIFileSystem *v3; // esi

  v2 = (CMasterVMPIFileSystem *)operator new(nSize: 0xBCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&IBaseFileSystem::`vftable';
    v2->m_pBaseFileSystemPassThru = nullptr;
    v2->m_pFileSystemPassThru = nullptr;
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CMasterVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
    CIPAddr::CIPAddr(this: &v2->m_MulticastIP);
    v3->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CMasterVMPIFileSystem_vtbl *)&CMasterVMPIFileSystem::`vftable'{for `IAppSystem'};
    v3->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CMasterVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
    CMasterMulticastThread::CMasterMulticastThread(this: &v3->m_MasterThread);
    CMasterVMPIFileSystem::s_pMasterVMPIFileSystem = v3;
  }
  else
  {
    v3 = nullptr;
  }
  g_pBaseVMPIFileSystem = v3;
  if ( CMasterVMPIFileSystem::Init(this: v3, maxMemoryUsage, pPassThru) != 0 )
    return v3;
  if ( v3 != nullptr )
    ((void (__thiscall *)(CMasterVMPIFileSystem *, int))v3->dtr_CBaseVMPIFileSystem)(a1: v3, a2: 1);
  g_pBaseVMPIFileSystem = nullptr;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10014DB0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CMasterMulticastThread::CMulticastFile __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CWorkerFile *,int> *)_g_pMemAlloc->Realloc_2(
                                                                    this: _g_pMemAlloc,
                                                                    a2: m_pMemory,
                                                                    a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CWorkerFile *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x1008D0C0
// Name: public: virtual class CSysModule __near * CMasterVMPIFileSystem::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CMasterVMPIFileSystem::LoadModule(
        CMasterVMPIFileSystem *this,
        const char *pFileName,
        const char *pPathID,
        BOOL bValidatedDllOnly)
{
  return this->m_pMasterVMPIFileSystemPassThru->LoadModule(
           this: this->m_pMasterVMPIFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: bValidatedDllOnly);
}

//------------------------------------------------------------------------------
// Address: 0x1008D0E0
// Name: public: virtual void CMasterVMPIFileSystem::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::UnloadModule(CMasterVMPIFileSystem *this, struct CSysModule *pModule)
{
  this->m_pMasterVMPIFileSystemPassThru->UnloadModule(this: this->m_pMasterVMPIFileSystemPassThru, a2: pModule);
}

//------------------------------------------------------------------------------
// Address: 0x1008D1A0
// Name: public: void CRateLimiter::NoteExcessTimeTaken(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRateLimiter::NoteExcessTimeTaken(CRateLimiter *this, unsigned int excessTimeInMicroseconds)
{
  unsigned int m_AccumulatedSleepMicroseconds; // eax
  unsigned int v3; // esi
  unsigned __int64 v4; // [esp-Ch] [ebp-20h]
  CCycleCount startCount; // [esp+Ch] [ebp-8h]

  m_AccumulatedSleepMicroseconds = this->m_AccumulatedSleepMicroseconds;
  if ( excessTimeInMicroseconds <= m_AccumulatedSleepMicroseconds )
  {
    this->m_AccumulatedSleepMicroseconds = m_AccumulatedSleepMicroseconds - excessTimeInMicroseconds;
  }
  else
  {
    v3 = excessTimeInMicroseconds - m_AccumulatedSleepMicroseconds;
    this->m_AccumulatedSleepMicroseconds = 0;
    startCount.m_Int64 = __rdtsc();
    do
    {
      HIDWORD(v4) = HIDWORD(_g_ClockSpeed);
      LODWORD(v4) = _g_ClockSpeed;
    }
    while ( (unsigned int)(1000000 * (__rdtsc() - startCount.m_Int64) / v4) < v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D240
// Name: public: virtual void CVMPIFile_PassThru::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Close(CVMPIFile_PassThru *this)
{
  this->m_pPassThru->Close(this: this->m_pPassThru, a2: this->m_fp);
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x1008D260
// Name: public: virtual void CVMPIFile_PassThru::Seek(int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Seek(CVMPIFile_PassThru *this, int pos, FileSystemSeek_t seekType)
{
  this->m_pPassThru->Seek(this: this->m_pPassThru, a2: this->m_fp, a3: pos, a4: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x1008D290
// Name: public: virtual unsigned int CVMPIFile_PassThru::Tell(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_PassThru::Tell(CVMPIFile_PassThru *this)
{
  return this->m_pPassThru->Tell(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1008D2B0
// Name: public: virtual unsigned int CVMPIFile_PassThru::Size(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_PassThru::Size(CVMPIFile_PassThru *this)
{
  return this->m_pPassThru->Size_2(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1008D2D0
// Name: public: virtual void CVMPIFile_PassThru::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Flush(CVMPIFile_PassThru *this)
{
  this->m_pPassThru->Flush(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1008D2F0
// Name: public: virtual int CVMPIFile_PassThru::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_PassThru::Read(CVMPIFile_PassThru *this, void *pOutput, int size)
{
  return this->m_pPassThru->Read(this: this->m_pPassThru, a2: pOutput, a3: size, a4: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1008D310
// Name: public: virtual int CVMPIFile_PassThru::Write(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_PassThru::Write(CVMPIFile_PassThru *this, const void *pInput, int size)
{
  return this->m_pPassThru->Write(this: this->m_pPassThru, a2: pInput, a3: size, a4: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1008D330
// Name: public: void CRateLimiter::GiveUpTimeSlice(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRateLimiter::GiveUpTimeSlice(CRateLimiter *this)
{
  CCycleCount *p_m_LastSleepTime; // edi
  unsigned __int64 v3; // [esp-Ch] [ebp-30h]
  unsigned __int64 v4; // [esp-Ch] [ebp-30h]
  unsigned __int64 v5; // [esp+8h] [ebp-1Ch] BYREF
  CFastTimer sleepTimer; // [esp+10h] [ebp-14h] BYREF
  CCycleCount currentTime; // [esp+18h] [ebp-Ch] BYREF
  CFastTimer *p_currentTime; // [esp+20h] [ebp-4h]

  p_currentTime = (CFastTimer *)&currentTime;
  currentTime.m_Int64 = __rdtsc();
  p_m_LastSleepTime = &this->m_LastSleepTime;
  HIDWORD(v3) = HIDWORD(_g_ClockSpeed);
  LODWORD(v3) = _g_ClockSpeed;
  if ( (unsigned int)(1000 * (currentTime.m_Int64 - this->m_LastSleepTime.m_Int64) / v3) >= this->m_SleepIntervalMS )
  {
    p_currentTime = &sleepTimer;
    sleepTimer.m_Duration.m_Int64 = __rdtsc();
    Sleep(dwMilliseconds: 0xAu);
    p_currentTime = (CFastTimer *)&v5;
    v5 = __rdtsc();
    sleepTimer.m_Duration.m_Int64 = v5 - sleepTimer.m_Duration.m_Int64;
    HIDWORD(v4) = HIDWORD(_g_ClockSpeed);
    LODWORD(v4) = _g_ClockSpeed;
    this->m_AccumulatedSleepMicroseconds += 1000000 * sleepTimer.m_Duration.m_Int64 / v4;
    p_m_LastSleepTime->m_Int64 = __rdtsc();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D410
// Name: private: void CMasterMulticastThread::TCP_SendNextChunk(class CMasterMulticastThread::CMulticastFile __near *,class CMasterMulticastThread::CClientFileInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::TCP_SendNextChunk(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pFile,
        CMasterMulticastThread::CClientFileInfo *pClient)
{
  CMasterMulticastThread::CMulticastFile *v3; // edx
  CMasterMulticastThread::CClientFileInfo *v4; // ebx
  int v5; // eax
  int v6; // ecx
  int m_Size; // edi
  int v8; // esi
  char *m_pMemory; // eax
  char *v10; // edx
  int m_ClientID; // [esp-10h] [ebp-3Ch]
  const void *chunks[5]; // [esp+4h] [ebp-28h] BYREF
  int chunkLengths[5]; // [esp+18h] [ebp-14h] BYREF

  v3 = pFile;
  v4 = pClient;
  v5 = pClient->m_TCP_LastChunkSent + 1;
  if ( v5 < pFile->m_Info.m_nChunks )
  {
    v6 = v5 << 14;
    m_Size = pFile->m_Data.m_Size;
    v8 = (v5 << 14) + 0x4000;
    pFile = (CMasterMulticastThread::CMulticastFile *)(pClient->m_TCP_LastChunkSent + 1);
    if ( v8 >= m_Size )
      v8 = m_Size;
    if ( v6 < m_Size )
    {
      pClient->m_TCP_LastChunkSent = v5;
      chunks[0] = &pClient;
      chunks[1] = &v3->m_Info;
      chunks[2] = &pFile;
      m_pMemory = v3->m_Filename.m_Memory.m_pMemory;
      v10 = v3->m_Data.m_Memory.m_pMemory;
      LOWORD(pClient) = 1536;
      chunks[3] = m_pMemory;
      chunks[4] = &v10[v6];
      chunkLengths[0] = 2;
      chunkLengths[1] = 12;
      chunkLengths[2] = 4;
      chunkLengths[3] = strlen(m_pMemory) + 1;
      m_ClientID = v4->m_ClientID;
      chunkLengths[4] = v8 - v6;
      VMPI_SendChunks(pChunks: chunks, pChunkLengths: chunkLengths, nChunks: 5, iDest: m_ClientID, fVMPISendFlags: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D4D0
// Name: private: bool CMasterMulticastThread::Thread_SendFileChunk_Multicast(int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMasterMulticastThread::Thread_SendFileChunk_Multicast(
        CMasterMulticastThread *this,
        unsigned int *pnBytesSent)
{
  CMasterMulticastThread::CMulticastFile *m_Element; // ecx
  volatile int v4; // edx
  int m_Size; // edi
  unsigned int v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned int v8; // eax
  int v9; // edi
  bool v10; // zf
  unsigned int v11; // eax
  int v13; // ecx
  DWORD LastError; // eax
  char dst[8192]; // [esp+Ch] [ebp-202Ch] BYREF
  _WSABUF count; // [esp+200Ch] [ebp-2Ch] BYREF
  unsigned int v17; // [esp+2014h] [ebp-24h]
  unsigned __int8 *p_m_iCurActiveChunk; // [esp+2018h] [ebp-20h]
  unsigned int v19; // [esp+201Ch] [ebp-1Ch]
  unsigned __int8 *m_pMemory; // [esp+2020h] [ebp-18h]
  unsigned int v21; // [esp+2024h] [ebp-14h]
  unsigned __int8 *v22; // [esp+2028h] [ebp-10h]
  char Buffer[4]; // [esp+202Ch] [ebp-Ch] BYREF
  unsigned int NumberOfBytesSent; // [esp+2030h] [ebp-8h] BYREF
  int len; // [esp+2034h] [ebp-4h]

  m_Element = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element;
  v4 = this->m_iCurActiveChunk << 10;
  m_Size = m_Element->m_Data.m_Size;
  len = v4 + 1024;
  if ( v4 + 1024 >= m_Size )
    len = m_Size;
  count.buf = (char *)&m_Element->m_Info;
  count.len = 12;
  p_m_iCurActiveChunk = (unsigned __int8 *)&this->m_iCurActiveChunk;
  v17 = 4;
  m_pMemory = (unsigned __int8 *)m_Element->m_Filename.m_Memory.m_pMemory;
  v6 = strlen(m_Element->m_Filename.m_Memory.m_pMemory) + 1;
  v19 = v6;
  v7 = (unsigned __int8 *)&m_Element->m_Data.m_Memory.m_pMemory[v4];
  v10 = this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b1 == 127;
  v21 = len - v4;
  v8 = len - v4 + v6 + 16;
  v22 = v7;
  NumberOfBytesSent = 0;
  len = v8;
  if ( !v10
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b2 != 0
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b3 != 0
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b4 != 1 )
  {
    WSASendTo(
      s: this->m_Socket,
      lpBuffers: &count,
      dwBufferCount: 4u,
      lpNumberOfBytesSent: &NumberOfBytesSent,
      dwFlags: 0,
      lpTo: (const struct sockaddr *)&this->m_MulticastAddr,
      iTolen: 16,
      lpOverlapped: nullptr,
      lpCompletionRoutine: nullptr);
    v11 = NumberOfBytesSent;
    v10 = NumberOfBytesSent == len;
  }
  else
  {
    if ( v8 > 0x2000 )
    {
      _Error(a1: "nWantedBytes > sizeof( allData )");
      v7 = v22;
      v6 = v19;
    }
    memcpy((unsigned __int8 *)dst, src: (unsigned __int8 *)count.buf, count: count.len);
    memcpy(dst: (unsigned __int8 *)&dst[count.len], src: p_m_iCurActiveChunk, count: v17);
    memcpy(dst: (unsigned __int8 *)&dst[count.len + v17], src: m_pMemory, count: v6);
    memcpy(dst: (unsigned __int8 *)&dst[count.len + v17 + v6], src: v7, count: v21);
    v9 = len;
    v10 = sendto(
            s: this->m_Socket,
            buf: dst,
            len,
            flags: 0,
            to: (const struct sockaddr *)&this->m_MulticastAddr,
            tolen: 16) == v9;
    v11 = NumberOfBytesSent;
  }
  if ( v10 )
  {
    *pnBytesSent = v11;
    return v10;
  }
  v13 = `CMasterMulticastThread::Thread_SendFileChunk_Multicast'::`14'::nWarnings + 1;
  `CMasterMulticastThread::Thread_SendFileChunk_Multicast'::`14'::nWarnings = v13;
  if ( v13 >= 10 )
  {
    if ( v13 == 10 )
      _Warning(a1: "\nThis machine's ability to multicast may be broken. Please reboot and try again.\n");
  }
  else
  {
    _Warning(a1: "\nMulticastThread: WSASendTo with %d bytes sent %d bytes.\n");
    LastError = GetLastError();
    if ( FormatMessageA(
           dwFlags: 0x1300u,
           lpSource: nullptr,
           dwMessageId: LastError,
           dwLanguageId: 0x400u,
           lpBuffer: Buffer,
           nSize: 0,
           Arguments: nullptr) != 0 )
    {
      _Warning(a1: "%s");
      LocalFree(hMem: *(HLOCAL *)Buffer);
      return false;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1008DAA0
// Name: private: int CMasterMulticastThread::FindFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FindFile(CMasterMulticastThread *this, const char *pName, const char *pPathID)
{
  int m_Head; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  CMasterMulticastThread *v6; // [esp+Ch] [ebp-4h]

  m_Head = this->m_Files.m_Head;
  v6 = this;
  if ( m_Head == -1 )
    return -1;
  while ( 1 )
  {
    m_Element = this->m_Files.m_Memory.m_pMemory[m_Head].m_Element;
    if ( _V_stricmp(s1: m_Element->m_Filename.m_Memory.m_pMemory, s2: pName) == 0
      && _V_stricmp(s1: m_Element->m_PathID.m_Memory.m_pMemory, s2: pPathID) == 0 )
    {
      break;
    }
    m_Head = v6->m_Files.m_Memory.m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      return -1;
    this = v6;
  }
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x1008DB20
// Name: private: void CMasterMulticastThread::EnsureMemoryLimit(class CMasterMulticastThread::CMulticastFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::EnsureMemoryLimit(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pIgnore)
{
  unsigned int m_nMaxMemoryUsage; // eax
  int i; // eax
  int v5; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // esi

  m_nMaxMemoryUsage = this->m_nMaxMemoryUsage;
  if ( m_nMaxMemoryUsage != 0 && this->m_nCurMemoryUsage > m_nMaxMemoryUsage )
  {
    for ( i = this->m_Files.m_Head; i != -1; i = this->m_Files.m_Memory.m_pMemory[v5].m_Next )
    {
      v5 = i;
      m_Element = this->m_Files.m_Memory.m_pMemory[i].m_Element;
      if ( m_Element != pIgnore && m_Element->m_bDataLoaded && m_Element->m_ActiveChunks.m_ElementCount == 0 )
      {
        this->m_nCurMemoryUsage -= m_Element->m_Info.m_CompressedSize + m_Element->m_Info.m_UncompressedSize;
        CUtlVector<CLightValue,CUtlMemory<CLightValue,int>>::Purge(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_Data);
        CUtlVector<CLightValue,CUtlMemory<CLightValue,int>>::Purge(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_UncompressedData);
        m_Element->m_bDataLoaded = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DC10
// Name: public: CTransmitRateMgr::CTransmitRateMgr(void)
// Source: json
//------------------------------------------------------------------------------
CTransmitRateMgr *__thiscall CTransmitRateMgr::CTransmitRateMgr(CTransmitRateMgr *this)
{
  long double v2; // xmm1_8
  ISocket *IPSocket; // eax
  unsigned __int64 v5; // [esp-14h] [ebp-20h]
  CCycleCount cnt; // [esp+0h] [ebp-Ch] BYREF
  CCycleCount *p_cnt; // [esp+8h] [ebp-4h]

  this->m_MachineRecords.m_Memory.m_pMemory = nullptr;
  this->m_MachineRecords.m_Memory.m_nAllocationCount = 0;
  this->m_MachineRecords.m_Memory.m_nGrowSize = 0;
  this->m_MachineRecords.m_Size = 0;
  this->m_MachineRecords.m_pElements = nullptr;
  v2 = 1000000.0 / (double)MULTICAST_TRANSMIT_RATE;
  this->m_flLastBroadcastTime = 0.0;
  this->m_nMicrosecondsPerByte = v2;
  this->m_UniqueID = (unsigned int)this;
  p_cnt = &cnt;
  cnt.m_Int64 = __rdtsc();
  HIDWORD(v5) = HIDWORD(_g_ClockSpeed);
  LODWORD(v5) = _g_ClockSpeed;
  this->m_UniqueID += 1000000 * cnt.m_Int64 / v5;
  Sleep(dwMilliseconds: 1u);
  HIDWORD(v5) = HIDWORD(_g_ClockSpeed);
  LODWORD(v5) = _g_ClockSpeed;
  this->m_UniqueID += 1000000 * cnt.m_Int64 / v5;
  IPSocket = CreateIPSocket();
  this->m_pSocket = IPSocket;
  if ( IPSocket != nullptr )
    IPSocket->BindToAny(this: IPSocket, a2: 21146u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008DCF0
// Name: public: CMasterMulticastThread::CMasterMulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
CMasterMulticastThread *__thiscall CMasterMulticastThread::CMasterMulticastThread(CMasterMulticastThread *this)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *m_pMemory; // ecx
  UtlLinkedListElem_t<char *,int> *v3; // edx

  this->m_Files.m_Memory.m_pMemory = nullptr;
  this->m_Files.m_Memory.m_nAllocationCount = 0;
  this->m_Files.m_Memory.m_nGrowSize = 0;
  this->m_Files.m_LastAlloc.index = -1;
  m_pMemory = this->m_Files.m_Memory.m_pMemory;
  this->m_Files.m_Head = -1;
  this->m_Files.m_Tail = -1;
  this->m_Files.m_FirstFree = -1;
  this->m_Files.m_ElementCount = 0;
  this->m_Files.m_NumAlloced = 0;
  this->m_Files.m_pElements = m_pMemory;
  this->m_WarningSuppressions.m_Memory.m_pMemory = nullptr;
  this->m_WarningSuppressions.m_Memory.m_nAllocationCount = 0;
  this->m_WarningSuppressions.m_Memory.m_nGrowSize = 0;
  this->m_WarningSuppressions.m_LastAlloc.index = -1;
  v3 = this->m_WarningSuppressions.m_Memory.m_pMemory;
  this->m_WarningSuppressions.m_Head = -1;
  this->m_WarningSuppressions.m_Tail = -1;
  this->m_WarningSuppressions.m_FirstFree = -1;
  this->m_WarningSuppressions.m_ElementCount = 0;
  this->m_WarningSuppressions.m_NumAlloced = 0;
  this->m_WarningSuppressions.m_pElements = v3;
  this->m_hMainThread = nullptr;
  this->m_hThread = nullptr;
  this->m_Socket = -1;
  this->m_nTotalActiveChunks = 0;
  this->m_iCurActiveChunk = -1;
  this->m_iCurFile = -1;
  this->m_pPassThru = nullptr;
  this->m_hTermEvent = CreateEventA(
                         lpEventAttributes: nullptr,
                         bManualReset: false,
                         bInitialState: false,
                         lpName: nullptr);
  InitializeCriticalSection(lpCriticalSection: &this->m_CS);
  this->m_nMaxMemoryUsage = 0;
  this->m_nCurMemoryUsage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008DD90
// Name: public: CMasterMulticastThread::CMulticastFile::CMulticastFile(void)
// Source: json
//------------------------------------------------------------------------------
CMasterMulticastThread::CMulticastFile *__thiscall CMasterMulticastThread::CMulticastFile::CMulticastFile(
        CMasterMulticastThread::CMulticastFile *this)
{
  CMasterMulticastThread::CMulticastFile *result; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // ecx

  result = this;
  this->m_Filename.m_Memory.m_pMemory = nullptr;
  this->m_Filename.m_Memory.m_nAllocationCount = 0;
  this->m_Filename.m_Memory.m_nGrowSize = 0;
  this->m_Filename.m_Size = 0;
  this->m_Filename.m_pElements = nullptr;
  this->m_PathID.m_Memory.m_pMemory = nullptr;
  this->m_PathID.m_Memory.m_nAllocationCount = 0;
  this->m_PathID.m_Memory.m_nGrowSize = 0;
  this->m_PathID.m_Size = 0;
  this->m_PathID.m_pElements = nullptr;
  this->m_UncompressedData.m_Memory.m_pMemory = nullptr;
  this->m_UncompressedData.m_Memory.m_nAllocationCount = 0;
  this->m_UncompressedData.m_Memory.m_nGrowSize = 0;
  this->m_UncompressedData.m_Size = 0;
  this->m_UncompressedData.m_pElements = nullptr;
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_Chunks.m_Memory.m_pMemory = nullptr;
  this->m_Chunks.m_Memory.m_nAllocationCount = 0;
  this->m_Chunks.m_Memory.m_nGrowSize = 0;
  this->m_Chunks.m_Size = 0;
  this->m_Chunks.m_pElements = nullptr;
  this->m_ActiveChunks.m_Memory.m_pMemory = nullptr;
  this->m_ActiveChunks.m_Memory.m_nAllocationCount = 0;
  this->m_ActiveChunks.m_Memory.m_nGrowSize = 0;
  this->m_ActiveChunks.m_LastAlloc.index = -1;
  this->m_ActiveChunks.m_Head = -1;
  this->m_ActiveChunks.m_Tail = -1;
  this->m_ActiveChunks.m_FirstFree = -1;
  this->m_ActiveChunks.m_ElementCount = 0;
  this->m_ActiveChunks.m_NumAlloced = 0;
  this->m_ActiveChunks.m_pElements = this->m_ActiveChunks.m_Memory.m_pMemory;
  this->m_Clients.m_Memory.m_pMemory = nullptr;
  this->m_Clients.m_Memory.m_nAllocationCount = 0;
  this->m_Clients.m_Memory.m_nGrowSize = 0;
  this->m_Clients.m_LastAlloc.index = -1;
  this->m_Clients.m_ElementCount = 0;
  this->m_Clients.m_NumAlloced = 0;
  m_pMemory = this->m_Clients.m_Memory.m_pMemory;
  result->m_Clients.m_Head = -1;
  result->m_Clients.m_Tail = -1;
  result->m_Clients.m_FirstFree = -1;
  result->m_Clients.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DEB0
// Name: public: void CTransmitRateMgr::ReadPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTransmitRateMgr::ReadPackets(CTransmitRateMgr *this@<ecx>, int a2@<edi>)
{
  int i; // eax
  unsigned int v4; // ebx
  int v5; // eax
  bool v6; // zf
  CTransmitRateMgr::CMachineRecord *m_pMemory; // ecx
  int v8; // eax
  float v9; // xmm0_4
  int j; // edi
  char data[768]; // [esp+4h] [ebp-30Ch] BYREF
  CIPAddr ipFrom; // [esp+304h] [ebp-Ch] BYREF
  float flCurTime; // [esp+30Ch] [ebp-4h]

  if ( this->m_pSocket != nullptr )
  {
    flCurTime = _Plat_FloatTime(a1: a2);
    CIPAddr::CIPAddr(this: &ipFrom);
    for ( i = this->m_pSocket->RecvFrom(this: this->m_pSocket, a2: data, a3: 768, a4: &ipFrom);
          i != -1;
          i = this->m_pSocket->RecvFrom(this: this->m_pSocket, a2: data, a3: 768, a4: &ipFrom) )
    {
      if ( i == 10
        && *(_DWORD *)data == *(_DWORD *)s_cTransmitRateMgrPacket
        && s_cTransmitRateMgrPacket[4] == data[4]
        && s_cTransmitRateMgrPacket[5] == data[5] )
      {
        v4 = *(_DWORD *)&data[6];
        if ( *(_DWORD *)&data[6] != this->m_UniqueID )
        {
          v5 = 0;
          v6 = this->m_MachineRecords.m_Size == 0;
          if ( this->m_MachineRecords.m_Size > 0 )
          {
            m_pMemory = this->m_MachineRecords.m_Memory.m_pMemory;
            while ( m_pMemory->m_UniqueID != *(_DWORD *)&data[6] )
            {
              ++v5;
              ++m_pMemory;
              if ( v5 >= this->m_MachineRecords.m_Size )
                goto LABEL_14;
            }
            this->m_MachineRecords.m_Memory.m_pMemory[v5].m_flLastTime = flCurTime;
LABEL_14:
            v6 = v5 == this->m_MachineRecords.m_Size;
          }
          if ( v6 )
          {
            v8 = CUtlVector<CTransmitRateMgr::CMachineRecord,CUtlMemory<CTransmitRateMgr::CMachineRecord,int>>::AddToTail(this: &this->m_MachineRecords);
            v9 = flCurTime;
            this->m_MachineRecords.m_Memory.m_pMemory[v8].m_UniqueID = v4;
            this->m_MachineRecords.m_Memory.m_pMemory[v8].m_flLastTime = v9;
          }
        }
      }
      CIPAddr::CIPAddr(this: &ipFrom);
    }
    for ( j = 0; j < this->m_MachineRecords.m_Size; ++j )
    {
      if ( (float)(flCurTime - this->m_MachineRecords.m_Memory.m_pMemory[j].m_flLastTime) > 0.7 )
      {
        if ( this->m_MachineRecords.m_Size - j - 1 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&this->m_MachineRecords.m_Memory.m_pMemory[j],
            src: (unsigned __int8 *)&this->m_MachineRecords.m_Memory.m_pMemory[j + 1],
            count: 8 * (this->m_MachineRecords.m_Size - j - 1));
        --this->m_MachineRecords.m_Size;
        --j;
      }
    }
    this->m_nMicrosecondsPerByte = 1000000.0 / (double)(MULTICAST_TRANSMIT_RATE / (this->m_MachineRecords.m_Size + 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E100
// Name: ZLibCompress
// Source: json
//------------------------------------------------------------------------------
char __usercall ZLibCompress@<al>(CUtlMemory<unsigned char,int> *out@<esi>, unsigned __int8 *pData, unsigned int len)
{
  int v3; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  signed int v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned int v9; // edx
  int v10; // ebx
  z_stream_s zs; // [esp+8h] [ebp-38h] BYREF

  v3 = len;
  if ( len != 0 )
  {
    memset(dst: (unsigned __int8 *)&zs, value: 0, count: sizeof(zs));
    if ( deflateInit_(a1: &zs, a2: 1, a3: "1.1.3", a4: 56) != 0 )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        out[1].m_pMemory = nullptr;
        if ( v3 != 0 )
        {
          m_nAllocationCount = out->m_nAllocationCount;
          if ( v3 > m_nAllocationCount )
            CUtlMemory<char,int>::Grow(this: out, num: v3 - m_nAllocationCount);
          out[1].m_pMemory += v3;
          m_pMemory = out->m_pMemory;
          v7 = (signed int)&out[1].m_pMemory[-v3];
          out[1].m_nAllocationCount = (int)out->m_pMemory;
          if ( v7 > 0 && v3 > 0 )
            _V_memmove(dest: &m_pMemory[v3], src: m_pMemory, count: v7);
        }
        v8 = out->m_pMemory;
        zs.avail_in = len;
        zs.next_in = pData;
        v9 = (unsigned int)out[1].m_pMemory;
        zs.next_out = v8;
        zs.avail_out = v9;
        v10 = deflate(a1: &zs, a2: 4);
        deflateEnd(a1: &zs);
        if ( v10 == 1 )
          break;
        if ( v10 != 0 )
          return 0;
        v3 += 0x20000;
        memset(dst: (unsigned __int8 *)&zs, value: 0, count: sizeof(zs));
        if ( deflateInit_(a1: &zs, a2: 1, a3: "1.1.3", a4: 56) != 0 )
          return 0;
      }
      out[1].m_pMemory -= (unsigned int)&out[1].m_pMemory[-zs.total_out];
      return 1;
    }
  }
  else
  {
    out[1].m_pMemory = nullptr;
    if ( out->m_nGrowSize >= 0 )
    {
      if ( out->m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: out->m_pMemory);
        out->m_pMemory = nullptr;
      }
      out->m_nAllocationCount = 0;
    }
    out[1].m_nAllocationCount = (int)out->m_pMemory;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E260
// Name: public: CMasterMulticastThread::CMulticastFile::~CMulticastFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::CMulticastFile::~CMulticastFile(CMasterMulticastThread::CMulticastFile *this)
{
  CUtlLinkedList<CMasterMulticastThread::CClientFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Clients);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Clients);
  if ( this->m_Clients.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Clients.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Clients.m_Memory.m_pMemory);
      this->m_Clients.m_Memory.m_pMemory = nullptr;
    }
    this->m_Clients.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_ActiveChunks);
  if ( this->m_ActiveChunks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ActiveChunks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ActiveChunks.m_Memory.m_pMemory);
      this->m_ActiveChunks.m_Memory.m_pMemory = nullptr;
    }
    this->m_ActiveChunks.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Chunks);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Data);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_UncompressedData);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_PathID);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Filename);
}

//------------------------------------------------------------------------------
// Address: 0x1008E580
// Name: public: void CMasterMulticastThread::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::Term(CMasterMulticastThread *this)
{
  if ( this->m_hThread != nullptr )
  {
    SetEvent(hEvent: this->m_hTermEvent);
    WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  if ( this->m_Socket != -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  CUtlLinkedList<CMasterMulticastThread::CMulticastFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Files);
  this->m_nMaxMemoryUsage = 0;
  this->m_nCurMemoryUsage = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008E5E0
// Name: private: void CMasterMulticastThread::DecrementChunkRefCount(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::DecrementChunkRefCount(CMasterMulticastThread *this, int iFile, int iChunk)
{
  int v4; // ecx
  CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *m_Element; // ebx
  int m_FirstFree; // edx
  bool v7; // zf
  int v8; // edi
  volatile int m_iCurFile; // edx
  int v10; // eax
  int v11; // edi
  unsigned __int16 v12; // ax

  v4 = iFile;
  m_Element = (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)this->m_Files.m_Memory.m_pMemory[iFile].m_Element;
  m_FirstFree = m_Element[2].m_FirstFree;
  v7 = *(_WORD *)(m_FirstFree + 6 * iChunk + 2) == 0;
  v8 = m_FirstFree + 6 * iChunk;
  iChunk = v8;
  if ( v7 )
  {
    _Error(a1: "CMasterMulticastThread::DecrementChunkRefCount - refcount already zero!\n");
    v4 = iFile;
  }
  v7 = (*(_WORD *)(v8 + 2))-- == 1;
  if ( v7 )
  {
    m_iCurFile = this->m_iCurFile;
    --this->m_nTotalActiveChunks;
    if ( v4 == m_iCurFile )
    {
      v10 = *(unsigned __int16 *)(iChunk + 4);
      if ( v10 == this->m_iCurActiveChunk )
        this->m_iCurActiveChunk = m_Element[3].m_Memory.m_pMemory[v10].m_Next;
    }
    v11 = *(unsigned __int16 *)(iChunk + 4);
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: m_Element + 3,
      elem: v11);
    m_Element[3].m_Memory.m_pMemory[v11].m_Next = m_Element[3].m_FirstFree;
    m_Element[3].m_FirstFree = v11;
    v12 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToTail(
            this: (CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int> > *)&m_Element[3],
            src: (CMasterMulticastThread::CChunkInfo *const *)&iChunk);
    *(_WORD *)(iChunk + 4) = v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E690
// Name: private: int CMasterMulticastThread::FinishFileSetup(class CMasterMulticastThread::CMulticastFile __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FinishFileSetup(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pFile,
        const char *pFilename,
        CMasterMulticastThread::CChunkInfo *pPathID,
        bool bFileAlreadyExisted)
{
  CMasterMulticastThread::CMulticastFile *v5; // edi
  CMasterMulticastThread *v6; // ebx
  unsigned int v8; // esi
  const char *v9; // ecx
  char *m_pMemory; // edx
  char v11; // al
  CMasterMulticastThread::CChunkInfo *v12; // ecx
  char *v13; // edx
  char m_iChunk; // al
  int v15; // ebx
  unsigned __int16 v16; // ax
  char *v17; // esi
  __int16 v18; // ax

  v5 = pFile;
  v6 = this;
  if ( ZLibCompress(
         out: (CUtlMemory<unsigned char,int> *)&pFile->m_Data,
         pData: (unsigned __int8 *)pFile->m_UncompressedData.m_Memory.m_pMemory,
         len: pFile->m_UncompressedData.m_Size) != 0 )
  {
    v5->m_bDataLoaded = true;
    v8 = VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_TCP ? 1024 : 0x4000;
    if ( !bFileAlreadyExisted )
    {
      CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v5->m_Filename,
        size: strlen(pFilename) + 1);
      v9 = pFilename;
      m_pMemory = v5->m_Filename.m_Memory.m_pMemory;
      do
      {
        v11 = *v9;
        *m_pMemory++ = *v9++;
      }
      while ( v11 != 0 );
      CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v5->m_PathID,
        size: strlen((const char *)pPathID) + 1);
      v12 = pPathID;
      v13 = v5->m_PathID.m_Memory.m_pMemory;
      do
      {
        m_iChunk = v12->m_iChunk;
        *v13 = v12->m_iChunk;
        v12 = (CMasterMulticastThread::CChunkInfo *)((char *)v12 + 1);
        ++v13;
      }
      while ( m_iChunk != 0 );
      v15 = 0;
      v5->m_nCycles = 0;
      v5->m_Info.m_CompressedSize = v5->m_Data.m_Size;
      v5->m_Info.m_UncompressedSize = v5->m_UncompressedData.m_Size;
      v16 = v8 * ((v5->m_Info.m_CompressedSize + v8 - 1) / v8) / v8;
      v5->m_Info.m_nChunks = v16;
      v5->m_Chunks.m_Size = 0;
      CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::InsertMultipleBefore(
        this: &v5->m_Chunks,
        elem: 0,
        num: v16);
      if ( v5->m_Chunks.m_Size > 0 )
      {
        pFilename = nullptr;
        do
        {
          v17 = (char *)&pFilename[(unsigned int)v5->m_Chunks.m_Memory.m_pMemory];
          *(_WORD *)v17 = v15;
          pPathID = (CMasterMulticastThread::CChunkInfo *)v17;
          *((_WORD *)v17 + 1) = 0;
          v18 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToTail(
                  this: &v5->m_ActiveChunks,
                  src: &pPathID);
          pFilename += 6;
          ++v15;
          *((_WORD *)v17 + 2) = v18;
        }
        while ( v15 < v5->m_Chunks.m_Size );
      }
      EnterCriticalSection(lpCriticalSection: &this->m_CS);
      v6 = this;
    }
    v6->m_nCurMemoryUsage += v5->m_Info.m_CompressedSize + v5->m_Info.m_UncompressedSize;
    CMasterMulticastThread::EnsureMemoryLimit(this: v6, pIgnore: v5);
    if ( !bFileAlreadyExisted )
    {
      v5->m_Info.m_FileID = CUtlLinkedList<CMasterMulticastThread::CMulticastFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>>::AddToTail(
                              this: &v6->m_Files,
                              src: &pFile);
      LeaveCriticalSection(lpCriticalSection: &v6->m_CS);
    }
    return v5->m_Info.m_FileID;
  }
  else
  {
    CMasterMulticastThread::CMulticastFile::~CMulticastFile(this: v5);
    free(pMem: v5);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E820
// Name: public: virtual void CMasterVMPIFileSystem::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::Term(CMasterVMPIFileSystem *this)
{
  CMasterMulticastThread::Term(this: &this->m_MasterThread);
}

//------------------------------------------------------------------------------
// Address: 0x1008E830
// Name: public: CMasterMulticastThread::~CMasterMulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::~CMasterMulticastThread(CMasterMulticastThread *this)
{
  CMasterMulticastThread::Term(this);
  CloseHandle(hObject: this->m_hTermEvent);
  DeleteCriticalSection(lpCriticalSection: &this->m_CS);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_WarningSuppressions);
  if ( this->m_WarningSuppressions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WarningSuppressions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WarningSuppressions.m_Memory.m_pMemory);
      this->m_WarningSuppressions.m_Memory.m_pMemory = nullptr;
    }
    this->m_WarningSuppressions.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll((CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)this);
  if ( this->m_Files.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Files.m_Memory.m_pMemory);
      this->m_Files.m_Memory.m_pMemory = nullptr;
    }
    this->m_Files.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E8C0
// Name: public: void CMasterMulticastThread::OnChunkReceived(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMasterMulticastThread::OnChunkReceived(
        CMasterMulticastThread *this@<ecx>,
        int a2@<edi>,
        int fileID,
        int clientID,
        int iChunk)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v5; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  int m_Head; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // edx
  CMasterMulticastThread::CClientFileInfo *v9; // esi

  if ( fileID >= 0
    && fileID < this->m_Files.m_Memory.m_nAllocationCount
    && fileID <= this->m_Files.m_LastAlloc.index
    && ((v5 = &this->m_Files.m_Memory.m_pMemory[fileID])->m_Previous != fileID || v5->m_Next == fileID) )
  {
    m_Element = v5->m_Element;
    m_Head = v5->m_Element->m_Clients.m_Head;
    if ( m_Head != -1 )
    {
      m_pMemory = m_Element->m_Clients.m_Memory.m_pMemory;
      while ( m_pMemory[m_Head].m_Element->m_ClientID != clientID )
      {
        m_Head = m_pMemory[m_Head].m_Next;
        if ( m_Head == -1 )
          return;
      }
      v9 = m_pMemory[m_Head].m_Element;
      if ( v9 != nullptr )
      {
        if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
        {
          EnterCriticalSection(lpCriticalSection: &this->m_CS);
          CMasterMulticastThread::TCP_SendNextChunk(this, pFile: m_Element, pClient: v9);
          LeaveCriticalSection(lpCriticalSection: &this->m_CS);
        }
        else if ( iChunk >= 0 && iChunk < m_Element->m_Chunks.m_Size )
        {
          v9->m_ChunksToSend.m_Memory.m_pMemory[iChunk >> 3] &= ~(1 << (iChunk & 7));
          --v9->m_nChunksLeft;
          v9->m_flLastAckTime = _Plat_FloatTime(a1: a2);
          if ( v9->m_nChunksLeft == 0 && g_iVMPIVerboseLevel >= 2 )
            _Warning(a1: "Client %d got file %s\n");
          EnterCriticalSection(lpCriticalSection: &this->m_CS);
          CMasterMulticastThread::DecrementChunkRefCount(this, iFile: fileID, iChunk);
          LeaveCriticalSection(lpCriticalSection: &this->m_CS);
        }
        else
        {
          _Warning(a1: "CMasterMulticastThread::OnChunkReceived: invalid chunk index (%d) for file %s\n");
        }
      }
    }
  }
  else
  {
    _Warning(a1: "CMasterMulticastThread::OnChunkReceived: invalid file (%d) from client %d\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EA20
// Name: public: void CMasterMulticastThread::OnFileReceived(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnFileReceived(CMasterMulticastThread *this, int fileID, int clientID)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v3; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  int v5; // esi
  CMasterMulticastThread *v6; // [esp+4h] [ebp-4h]

  v6 = this;
  if ( fileID >= 0
    && fileID < this->m_Files.m_Memory.m_nAllocationCount
    && fileID <= this->m_Files.m_LastAlloc.index
    && ((v3 = &this->m_Files.m_Memory.m_pMemory[fileID])->m_Previous != fileID || v3->m_Next == fileID) )
  {
    m_Element = v3->m_Element;
    v5 = 0;
    if ( v3->m_Element->m_Info.m_nChunks != 0 )
    {
      while ( 1 )
      {
        CMasterMulticastThread::OnChunkReceived(this, a2: fileID, fileID, clientID, iChunk: v5++);
        if ( v5 >= m_Element->m_Info.m_nChunks )
          break;
        this = v6;
      }
    }
  }
  else
  {
    _Warning(a1: "CMasterMulticastThread::OnChunkReceived: invalid file (%d) from client %d\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EAA0
// Name: public: void CMasterMulticastThread::OnClientDisconnect(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnClientDisconnect(
        CMasterMulticastThread *this,
        int clientID,
        bool bGrabCriticalSection)
{
  CMasterMulticastThread *v3; // edi
  int m_Head; // eax
  int v5; // ecx
  CMasterMulticastThread::CMulticastFile *m_Element; // edx
  int v7; // esi
  int v8; // eax
  _DWORD *v9; // edi
  int v10; // ebx
  bool v11; // sf
  void *v12; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // edi
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *v14; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  int v17; // [esp+4h] [ebp-10h]
  int iFile; // [esp+8h] [ebp-Ch]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+10h] [ebp-4h]

  v3 = this;
  if ( bGrabCriticalSection )
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
  m_Head = v3->m_Files.m_Head;
  iFile = m_Head;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      v5 = 12 * m_Head;
      m_Element = v3->m_Files.m_Memory.m_pMemory[m_Head].m_Element;
      v7 = m_Element->m_Clients.m_Head;
      v17 = 12 * m_Head;
      pFile = m_Element;
      if ( v7 != -1 )
      {
        while ( 1 )
        {
          v8 = (int)&m_Element->m_Clients.m_Memory.m_pMemory[v7];
          v9 = *(_DWORD **)v8;
          if ( **(_DWORD **)v8 == clientID )
            break;
          v7 = *(_DWORD *)(v8 + 8);
          if ( v7 == -1 )
            goto LABEL_34;
        }
        v10 = 0;
        if ( m_Element->m_Info.m_nChunks != 0 )
        {
          do
          {
            if ( ((unsigned __int8)(1 << (v10 & 7)) & *(_BYTE *)((v10 >> 3) + v9[1])) != 0 )
              CMasterMulticastThread::DecrementChunkRefCount(this, iFile, iChunk: v10);
            ++v10;
          }
          while ( v10 < pFile->m_Info.m_nChunks );
        }
        v11 = (int)v9[3] < 0;
        v9[4] = 0;
        if ( !v11 )
        {
          if ( v9[1] != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v9[1]);
            v9[1] = 0;
          }
          v9[2] = 0;
        }
        v11 = (int)v9[3] < 0;
        v12 = (void *)v9[1];
        v9[5] = v12;
        if ( !v11 )
        {
          if ( v12 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
            v9[1] = 0;
          }
          v9[2] = 0;
        }
        free(pMem: v9);
        if ( v7 >= 0 && v7 < pFile->m_Clients.m_Memory.m_nAllocationCount && v7 <= pFile->m_Clients.m_LastAlloc.index )
        {
          m_pMemory = pFile->m_Clients.m_Memory.m_pMemory;
          v14 = &m_pMemory[v7];
          if ( v14->m_Previous != v7 )
          {
            m_Previous = v14->m_Previous;
            if ( m_Previous == -1 )
              pFile->m_Clients.m_Head = v14->m_Next;
            else
              m_pMemory[m_Previous].m_Next = v14->m_Next;
            m_Next = v14->m_Next;
            if ( m_Next == -1 )
              pFile->m_Clients.m_Tail = v14->m_Previous;
            else
              pFile->m_Clients.m_Memory.m_pMemory[m_Next].m_Previous = v14->m_Previous;
            v14->m_Next = v7;
            v14->m_Previous = v7;
            --pFile->m_Clients.m_ElementCount;
          }
        }
        pFile->m_Clients.m_Memory.m_pMemory[v7].m_Next = pFile->m_Clients.m_FirstFree;
        v5 = v17;
        pFile->m_Clients.m_FirstFree = v7;
LABEL_34:
        v3 = this;
      }
      iFile = *(int *)((char *)&v3->m_Files.m_Memory.m_pMemory->m_Next + v5);
      if ( iFile == -1 )
        break;
      m_Head = *(int *)((char *)&v3->m_Files.m_Memory.m_pMemory->m_Next + v5);
    }
  }
  if ( bGrabCriticalSection )
    LeaveCriticalSection(lpCriticalSection: &v3->m_CS);
}

//------------------------------------------------------------------------------
// Address: 0x1008EC90
// Name: public: void CMasterMulticastThread::CreateVirtualFile(char const __near *,void const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::CreateVirtualFile(
        CMasterMulticastThread *this,
        const char *pFilename,
        const unsigned __int8 *pData,
        unsigned int fileLength)
{
  CMasterMulticastThread::CMulticastFile *v5; // eax
  CMasterMulticastThread::CMulticastFile *v6; // esi

  if ( CMasterMulticastThread::FindFile(this, pName: pFilename, pPathID: "VMPI_VIRTUAL_FILES_PATH_ID") != -1 )
    _Error(a1: "CMasterMulticastThread::CreateVirtualFile( %s ) - file already exists!", pFilename);
  v5 = (CMasterMulticastThread::CMulticastFile *)MemAlloc_Alloc(nSize: 0xC8u);
  if ( v5 != nullptr )
    v6 = CMasterMulticastThread::CMulticastFile::CMulticastFile(this: v5);
  else
    v6 = nullptr;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v6->m_UncompressedData,
    pArray: pData,
    size: fileLength);
  CMasterMulticastThread::FinishFileSetup(
    this,
    pFile: v6,
    pFilename,
    pPathID: (CMasterMulticastThread::CChunkInfo *)"VMPI_VIRTUAL_FILES_PATH_ID",
    bFileAlreadyExisted: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008ED00
// Name: private: bool CMasterMulticastThread::CheckClientTimeouts(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterMulticastThread::CheckClientTimeouts(CMasterMulticastThread *this)
{
  CMasterMulticastThread *v1; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // esi
  char v3; // bl
  int m_Head; // eax
  float v5; // xmm2_4
  int v6; // edx
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // eax
  CMasterMulticastThread::CClientFileInfo *v8; // esi
  int m_Next; // ecx
  float m_flLastAckTime; // xmm1_4
  int v11; // eax
  CMasterMulticastThread::CMulticastFile *v12; // ecx
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v13; // ebx
  float *v14; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *v15; // edi
  float **v16; // eax
  float *v17; // ecx
  int v19; // [esp+10h] [ebp-20h]
  int iNext; // [esp+1Ch] [ebp-14h]
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v22; // [esp+24h] [ebp-Ch]
  float flCurTime; // [esp+28h] [ebp-8h]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+2Ch] [ebp-4h]

  v1 = this;
  m_Element = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element;
  v3 = 0;
  pFile = m_Element;
  flCurTime = _Plat_FloatTime(a1: v19);
  m_Head = m_Element->m_Clients.m_Head;
  if ( m_Head != -1 )
  {
    v5 = flCurTime;
    while ( 1 )
    {
      v6 = m_Head;
      m_pMemory = m_Element->m_Clients.m_Memory.m_pMemory;
      v8 = m_pMemory[v6].m_Element;
      m_Next = m_pMemory[v6].m_Next;
      iNext = m_Next;
      if ( v8->m_nChunksLeft != 0 && ++v8->m_nTimesFileCycled >= 5 )
      {
        m_flLastAckTime = v8->m_flLastAckTime;
        if ( (float)(v5 - m_flLastAckTime) > 20.0 )
        {
          v11 = v1->m_Files.m_Head;
          if ( v11 != -1 )
          {
            v22 = v1->m_Files.m_Memory.m_pMemory;
            do
            {
              v12 = v22[v11].m_Element;
              v13 = &v22[v11];
              v14 = (float *)v12->m_Clients.m_Head;
              if ( v14 != (float *)-1 )
              {
                v15 = v12->m_Clients.m_Memory.m_pMemory;
                do
                {
                  v16 = (float **)&v15[(_DWORD)v14];
                  v17 = *v16;
                  if ( *(_DWORD *)*v16 == v8->m_ClientID && m_flLastAckTime <= v17[10] )
                    m_flLastAckTime = v17[10];
                  v14 = v16[2];
                }
                while ( v14 != (float *)-1 );
                v1 = this;
              }
              v11 = v13->m_Next;
            }
            while ( v11 != -1 );
          }
          VMPI_GetMachineName(iProc: v8->m_ClientID);
          _Warning(a1: "\nClient %s timed out on file %s (latest: %.2f / cur: %.2f).\n");
          CMasterMulticastThread::OnClientDisconnect(this: v1, clientID: v8->m_ClientID, bGrabCriticalSection: false);
          v5 = flCurTime;
          m_Next = iNext;
          v3 = 1;
        }
      }
      m_Head = m_Next;
      if ( m_Next == -1 )
        break;
      m_Element = pFile;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008EE50
// Name: private: void CMasterMulticastThread::Thread_SeekToNextActiveChunk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::Thread_SeekToNextActiveChunk(CMasterMulticastThread *this)
{
  if ( this->m_iCurFile == -1 )
  {
    this->m_iCurFile = this->m_Files.m_Head;
    this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Head;
  }
  while ( this->m_iCurActiveChunk != -1
       && this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Element->m_RefCount != 0 )
  {
LABEL_10:
    if ( this->m_iCurActiveChunk != -1 )
    {
      if ( this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Element->m_RefCount != 0 )
        return;
      this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Next;
    }
  }
  if ( CMasterMulticastThread::CheckClientTimeouts(this) == 0 || this->m_nTotalActiveChunks != 0 )
  {
    this->m_iCurFile = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Next;
    if ( this->m_iCurFile == -1 )
      this->m_iCurFile = this->m_Files.m_Head;
    this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Head;
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EF30
// Name: private: unsigned long CMasterMulticastThread::MulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall CMasterMulticastThread::MulticastThread@<eax>(CMasterMulticastThread *this@<ecx>, int a2@<edi>)
{
  void (__stdcall *v3)(LPCRITICAL_SECTION); // ebx
  DWORD v4; // eax
  double v5; // st7
  unsigned int v6; // ecx
  unsigned __int64 v8; // [esp-10h] [ebp-80h]
  int v9; // [esp-8h] [ebp-78h]
  CTransmitRateMgr transmitRateMgr; // [esp+4h] [ebp-6Ch] BYREF
  CRateLimiter rateLimiter; // [esp+34h] [ebp-3Ch] BYREF
  int v12; // [esp+44h] [ebp-2Ch] BYREF
  __int16 v13; // [esp+48h] [ebp-28h]
  unsigned int m_UniqueID; // [esp+4Ah] [ebp-26h]
  unsigned __int64 v15; // [esp+50h] [ebp-20h] BYREF
  CFastTimer timer; // [esp+58h] [ebp-18h] BYREF
  __int64 v17; // [esp+60h] [ebp-10h]
  unsigned int msToWait; // [esp+68h] [ebp-8h]
  int nBytesSent; // [esp+6Ch] [ebp-4h] BYREF

  CTransmitRateMgr::CTransmitRateMgr(this: &transmitRateMgr);
  rateLimiter.m_SleepIntervalMS = 50;
  rateLimiter.m_AccumulatedSleepMicroseconds = 0;
  msToWait = (unsigned int)&rateLimiter.m_LastSleepTime;
  rateLimiter.m_LastSleepTime.m_Int64 = __rdtsc();
  if ( WaitForSingleObject(hHandle: this->m_hTermEvent, dwMilliseconds: 0) != 0 )
  {
    v3 = LeaveCriticalSection;
    v9 = a2;
    do
    {
      CRateLimiter::GiveUpTimeSlice(this: &rateLimiter);
      msToWait = 0;
      EnterCriticalSection(lpCriticalSection: &this->m_CS);
      CTransmitRateMgr::ReadPackets(this: &transmitRateMgr, a2: (int)&this->m_CS);
      if ( this->m_nTotalActiveChunks == 0 )
        goto LABEL_4;
      if ( transmitRateMgr.m_pSocket != nullptr )
      {
        v5 = _Plat_FloatTime(a1: v9);
        *(float *)&nBytesSent = v5;
        if ( v5 - transmitRateMgr.m_flLastBroadcastTime >= 0.3333333333333333 )
        {
          m_UniqueID = transmitRateMgr.m_UniqueID;
          v12 = *(_DWORD *)s_cTransmitRateMgrPacket;
          v13 = *(_WORD *)&s_cTransmitRateMgrPacket[4];
          LODWORD(transmitRateMgr.m_flLastBroadcastTime) = nBytesSent;
          transmitRateMgr.m_pSocket->Broadcast(this: transmitRateMgr.m_pSocket, a2: &v12, a3: 10, a4: 21146u);
        }
      }
      *(float *)&nBytesSent = COERCE_FLOAT(&timer);
      timer.m_Duration.m_Int64 = __rdtsc();
      CMasterMulticastThread::Thread_SeekToNextActiveChunk(this);
      if ( this->m_nTotalActiveChunks != 0 )
      {
        *(float *)&nBytesSent = 0.0;
        CMasterMulticastThread::Thread_SendFileChunk_Multicast(this, pnBytesSent: (unsigned int *)&nBytesSent);
        g_nMulticastBytesSent += nBytesSent;
        this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Next;
        v3(lpCriticalSection: &this->m_CS);
        HIDWORD(v17) = &v15;
        v15 = __rdtsc();
        timer.m_Duration.m_Int64 = v15 - timer.m_Duration.m_Int64;
        HIDWORD(v8) = HIDWORD(_g_ClockSpeed);
        LODWORD(v8) = _g_ClockSpeed;
        v6 = 1000000 * timer.m_Duration.m_Int64 / v8;
        v17 = (__int64)((double)(unsigned int)(nBytesSent + 32) * transmitRateMgr.m_nMicrosecondsPerByte);
        if ( v6 < (unsigned int)v17 )
          CRateLimiter::NoteExcessTimeTaken(this: &rateLimiter, excessTimeInMicroseconds: v17 - v6);
        v3 = LeaveCriticalSection;
        v4 = msToWait;
      }
      else
      {
LABEL_4:
        v3(lpCriticalSection: &this->m_CS);
        v4 = 50;
      }
    }
    while ( WaitForSingleObject(hHandle: this->m_hTermEvent, dwMilliseconds: v4) != 0 );
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&transmitRateMgr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008F140
// Name: public: int CMasterMulticastThread::FindOrAddFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FindOrAddFile(
        CMasterMulticastThread *this,
        const char *pFilename,
        char *pPathID)
{
  int result; // eax
  void *v5; // esi
  CMasterMulticastThread::CMulticastFile *v6; // eax
  int v7; // ebx
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  signed int v10; // eax
  int v11; // esi
  bool bFileAlreadyExisted; // [esp+10h] [ebp-8h]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+14h] [ebp-4h]

  pFile = nullptr;
  bFileAlreadyExisted = false;
  result = CMasterMulticastThread::FindFile(this, pName: pFilename, pPathID);
  if ( result != -1 )
  {
    pFile = this->m_Files.m_Memory.m_pMemory[result].m_Element;
    if ( pFile->m_bDataLoaded )
      return result;
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
    bFileAlreadyExisted = true;
  }
  v5 = this->m_pPassThru->Open(this: this->m_pPassThru, a2: pFilename, a3: "rb", a4: *pPathID != 0 ? pPathID : nullptr);
  if ( v5 != nullptr )
  {
    if ( !bFileAlreadyExisted )
    {
      v6 = (CMasterMulticastThread::CMulticastFile *)MemAlloc_Alloc(nSize: 0xC8u);
      if ( v6 != nullptr )
        pFile = CMasterMulticastThread::CMulticastFile::CMulticastFile(this: v6);
      else
        pFile = nullptr;
    }
    v7 = this->m_pPassThru->Size_2(this: this->m_pPassThru, a2: v5);
    pFile->m_UncompressedData.m_Size = 0;
    if ( v7 != 0 )
    {
      m_nAllocationCount = pFile->m_UncompressedData.m_Memory.m_nAllocationCount;
      if ( v7 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&pFile->m_UncompressedData,
          num: v7 - m_nAllocationCount);
      pFile->m_UncompressedData.m_Size += v7;
      m_pMemory = (unsigned __int8 *)pFile->m_UncompressedData.m_Memory.m_pMemory;
      v10 = pFile->m_UncompressedData.m_Size - v7;
      pFile->m_UncompressedData.m_pElements = (char *)m_pMemory;
      if ( v10 > 0 && v7 > 0 )
        _V_memmove(dest: &m_pMemory[v7], src: m_pMemory, count: v10);
    }
    this->m_pPassThru->Read(
      this: this->m_pPassThru,
      a2: pFile->m_UncompressedData.m_Memory.m_pMemory,
      a3: pFile->m_UncompressedData.m_Size,
      a4: v5);
    this->m_pPassThru->Close(this: this->m_pPassThru, a2: v5);
    v11 = CMasterMulticastThread::FinishFileSetup(
            this,
            pFile,
            pFilename,
            (CMasterMulticastThread::CChunkInfo *)pPathID,
            bFileAlreadyExisted);
    if ( bFileAlreadyExisted )
      LeaveCriticalSection(lpCriticalSection: &this->m_CS);
    return v11;
  }
  else
  {
    if ( bFileAlreadyExisted )
      LeaveCriticalSection(lpCriticalSection: &this->m_CS);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F2A0
// Name: public: virtual void __near * CMasterVMPIFileSystem::OpenEx(char const __near *,char const __near *,unsigned int,char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMasterVMPIFileSystem::OpenEx(
        CMasterVMPIFileSystem *this,
        const char *pFileName,
        const char *pOptions,
        unsigned int flags,
        const char *pathID,
        char **ppszResolvedFilename)
{
  return this->Open(this: &this->IBaseFileSystem, a2: pFileName, a3: pOptions, a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1008F2C0
// Name: public: virtual void __near * CMasterVMPIFileSystem::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVMPIFile_Memory *__thiscall CMasterVMPIFileSystem::Open(
        CMasterVMPIFileSystem *this,
        const char *pFilename,
        char *pOptions,
        char *pPathID)
{
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  CVMPIFile_Memory *result; // eax
  IBaseFileSystem_vtbl *v10; // ecx
  IBaseFileSystem_vtbl *v11; // ecx
  char *v12; // eax
  int v13; // eax
  int v14; // esi
  CVMPIFile_Memory *v15; // eax
  CVMPIFile_Memory *v16; // edi
  int v17; // ebx
  const char *v18; // esi
  int v19; // eax

  if ( g_bDisableFileAccess )
    _Error(a1: "Open( %s, %s ) - file access has been disabled.", pFilename, pOptions);
  strchr(string: (unsigned __int8 *)pOptions, chr: 0x77u);
  if ( v5 != 0
    || (strchr(string: (unsigned __int8 *)pOptions, chr: 0x61u), v6 != 0)
    || (strchr(string: (unsigned __int8 *)pOptions, chr: 0x2Bu), v7 != 0) )
  {
    v8 = (*((int (__thiscall **)(IBaseFileSystem_vtbl *, const char *, char *, char *))this->Read + 2))(
           a1: this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable,
           a2: pFilename,
           a3: pOptions,
           a4: pPathID);
    if ( v8 == 0 )
      return nullptr;
    result = (CVMPIFile_Memory *)MemAlloc_Alloc(nSize: 0xCu);
    if ( result != nullptr )
    {
      result->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_PassThru::`vftable';
      v10 = this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable;
      result->m_DataLen = v8;
      result->m_pData = (const char *)v10;
    }
    else
    {
      v11 = this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable;
      MEMORY[8] = v8;
      MEMORY[4] = v11;
      return nullptr;
    }
  }
  else
  {
    v12 = pPathID;
    if ( pPathID == nullptr )
      v12 = (char *)defaultValue;
    v13 = CMasterMulticastThread::FindOrAddFile(
            this: (CMasterMulticastThread *)&this->m_MulticastIP.port,
            pFilename,
            pPathID: v12);
    if ( v13 == -1 )
      return nullptr;
    v14 = *(_DWORD *)(*(_DWORD *)&this->m_MulticastIP.port + 12 * v13);
    v15 = (CVMPIFile_Memory *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v15 != nullptr )
    {
      v15->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_Memory::`vftable';
      v16 = v15;
    }
    else
    {
      v16 = nullptr;
    }
    v17 = *(_DWORD *)(v14 + 68);
    v18 = *(const char **)(v14 + 56);
    strchr(string: (unsigned __int8 *)pOptions, chr: 0x74u);
    CVMPIFile_Memory::Init(this: v16, pData: v18, len: v17, chMode: v19 != 0 ? 116 : 98);
    return v16;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008F3E0
// Name: private: static void CMasterVMPIFileSystem::OnClientDisconnect(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMasterVMPIFileSystem::OnClientDisconnect(int procID)
{
  CMasterMulticastThread::OnClientDisconnect(
    this: &CMasterVMPIFileSystem::s_pMasterVMPIFileSystem->m_MasterThread,
    clientID: procID,
    bGrabCriticalSection: true);
}

//------------------------------------------------------------------------------
// Address: 0x1008F400
// Name: public: virtual void CMasterVMPIFileSystem::CreateVirtualFile(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::CreateVirtualFile(
        CMasterVMPIFileSystem *this,
        const char *pFilename,
        const unsigned __int8 *pData,
        unsigned int fileLength)
{
  CMasterMulticastThread::CreateVirtualFile(this: &this->m_MasterThread, pFilename, pData, fileLength);
}

//------------------------------------------------------------------------------
// Address: 0x1008F410
// Name: public: int CMasterMulticastThread::AddFileRequest(char const __near *,char const __near *,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CMasterMulticastThread::AddFileRequest@<eax>(
        CMasterMulticastThread *this@<ecx>,
        int a2@<esi>,
        const char *pFilename,
        char *pPathID,
        int clientID,
        bool *bZeroLength)
{
  int result; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  CMasterMulticastThread::CClientFileInfo *v9; // eax
  CMasterMulticastThread::CClientFileInfo *v10; // edi
  int v11; // ecx
  double v12; // st7
  int v13; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 *m_pMemory; // edx
  signed int v16; // ecx
  CMasterMulticastThread::CChunkInfo *v17; // esi
  bool v18; // zf
  unsigned __int16 v19; // ax
  int v20; // eax
  int j; // esi
  int iFile; // [esp+4h] [ebp-14h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+8h] [ebp-10h]
  CMasterMulticastThread::CChunkInfo *src; // [esp+Ch] [ebp-Ch] BYREF
  CMasterMulticastThread *v25; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  const char *pFilenamea; // [esp+20h] [ebp+8h]
  const char *pFilenameb; // [esp+20h] [ebp+8h]

  v25 = this;
  result = CMasterMulticastThread::FindOrAddFile(this, pFilename, pPathID);
  iFile = result;
  if ( result != -1 )
  {
    m_Element = this->m_Files.m_Memory.m_pMemory[result].m_Element;
    lpCriticalSection = &this->m_CS;
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
    v9 = (CMasterMulticastThread::CClientFileInfo *)MemAlloc_Alloc(nSize: 0x30u);
    if ( v9 != nullptr )
    {
      v10 = v9;
      v9->m_ChunksToSend.m_Memory.m_pMemory = nullptr;
      v9->m_ChunksToSend.m_Memory.m_nAllocationCount = 0;
      v9->m_ChunksToSend.m_Memory.m_nGrowSize = 0;
      v9->m_ChunksToSend.m_Size = 0;
      v9->m_ChunksToSend.m_pElements = nullptr;
      pPathID = (char *)v9;
    }
    else
    {
      pPathID = nullptr;
      v10 = nullptr;
    }
    v11 = clientID;
    v10->m_TCP_LastChunkAcked = -1;
    v10->m_TCP_LastChunkSent = -1;
    v10->m_ClientID = v11;
    v12 = _Plat_FloatTime(a1: a2);
    v10->m_flLastAckTime = v12;
    v10->m_flTransmitStartTime = v12;
    v10->m_nTimesFileCycled = 0;
    v10->m_nChunksLeft = m_Element->m_Info.m_nChunks;
    v13 = 8 * ((m_Element->m_Info.m_nChunks + 7) / 8) / 8;
    pFilenamea = (const char *)v13;
    v10->m_ChunksToSend.m_Size = 0;
    if ( v13 != 0 )
    {
      m_nAllocationCount = v10->m_ChunksToSend.m_Memory.m_nAllocationCount;
      if ( v13 > m_nAllocationCount )
      {
        CUtlMemory<char,int>::Grow(this: &v10->m_ChunksToSend.m_Memory, num: v13 - m_nAllocationCount);
        v13 = (int)pFilenamea;
      }
      v10->m_ChunksToSend.m_Size += v13;
      m_pMemory = v10->m_ChunksToSend.m_Memory.m_pMemory;
      v16 = v10->m_ChunksToSend.m_Size - v13;
      v10->m_ChunksToSend.m_pElements = m_pMemory;
      if ( v16 > 0 && v13 > 0 )
        _V_memmove(dest: &m_pMemory[v13], src: m_pMemory, count: v16);
    }
    memset(dst: v10->m_ChunksToSend.m_Memory.m_pMemory, value: 0xFFu, count: v10->m_ChunksToSend.m_Size);
    CUtlLinkedList<CMasterMulticastThread::CClientFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int>,int>>::AddToTail(
      this: &m_Element->m_Clients,
      src: (CMasterMulticastThread::CClientFileInfo *const *)&pPathID);
    i = 0;
    if ( m_Element->m_Chunks.m_Size > 0 )
    {
      pFilenameb = nullptr;
      do
      {
        v17 = (CMasterMulticastThread::CChunkInfo *)&pFilenameb[(unsigned int)m_Element->m_Chunks.m_Memory.m_pMemory];
        v18 = v17->m_RefCount == 0;
        src = v17;
        if ( v18 )
        {
          ++v25->m_nTotalActiveChunks;
          clientID = v17->m_iActiveChunksIndex;
          CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
            this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&m_Element->m_ActiveChunks,
            elem: clientID);
          m_Element->m_ActiveChunks.m_Memory.m_pMemory[clientID].m_Next = m_Element->m_ActiveChunks.m_FirstFree;
          m_Element->m_ActiveChunks.m_FirstFree = clientID;
          v19 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToHead(
                  this: &m_Element->m_ActiveChunks,
                  &src);
          v10 = (CMasterMulticastThread::CClientFileInfo *)pPathID;
          v17->m_iActiveChunksIndex = v19;
        }
        v20 = i;
        ++v17->m_RefCount;
        pFilenameb += 6;
        i = v20 + 1;
      }
      while ( v20 + 1 < m_Element->m_Chunks.m_Size );
    }
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
    {
      for ( j = 16; j != 0; --j )
        CMasterMulticastThread::TCP_SendNextChunk(this: v25, pFile: m_Element, pClient: v10);
    }
    LeaveCriticalSection(lpCriticalSection);
    *bZeroLength = m_Element->m_Info.m_UncompressedSize == 0;
    return iFile;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008F5E0
// Name: private: static unsigned long CMasterMulticastThread::StaticMulticastThread(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge CMasterMulticastThread::StaticMulticastThread@<eax>(
        int a1@<edi>,
        CMasterMulticastThread *pParameter)
{
  return CMasterMulticastThread::MulticastThread(this: pParameter, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1008F640
// Name: public: virtual bool CMasterVMPIFileSystem::HandleFileSystemPacket(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterVMPIFileSystem::HandleFileSystemPacket(
        CMasterVMPIFileSystem *this,
        CMasterMulticastThread *pBuf,
        int iSource,
        int iPacketID)
{
  char *m_pMemory; // eax
  int v6; // edx
  int v7; // edx
  unsigned __int16 *v9; // esi
  unsigned __int16 *v10; // edi
  int v11; // eax
  int i; // ebx
  const char *v13; // esi
  unsigned int v14; // kr04_4
  int v15; // edi
  void *pChunks[4]; // [esp+Ch] [ebp-2Ch] BYREF
  int chunkLen[4]; // [esp+1Ch] [ebp-1Ch] BYREF
  int fileID; // [esp+2Ch] [ebp-Ch] BYREF
  int requestID; // [esp+30h] [ebp-8h] BYREF
  CMasterVMPIFileSystem *v20; // [esp+34h] [ebp-4h]

  m_pMemory = (char *)pBuf->m_Files.m_Memory.m_pMemory;
  v6 = SBYTE1(pBuf->m_Files.m_Memory.m_pMemory->m_Element) - 1;
  v20 = this;
  if ( v6 == 0 )
  {
    v13 = m_pMemory + 6;
    requestID = *(_DWORD *)(m_pMemory + 2);
    v14 = strlen(m_pMemory + 6);
    v15 = iSource;
    if ( g_iVMPIVerboseLevel >= 2 )
      _Msg(a1: "Client %d requested '%s'\n", iSource, v13);
    fileID = CMasterMulticastThread::AddFileRequest(
               this: &v20->m_MasterThread,
               a2: (int)v13,
               pFilename: v13,
               pPathID: (char *)&v13[v14 + 1],
               clientID: v15,
               bZeroLength: (bool *)&iSource + 3);
    pChunks[0] = &pBuf;
    pChunks[3] = (char *)&iSource + 3;
    pChunks[1] = &requestID;
    pChunks[2] = &fileID;
    LOWORD(pBuf) = 512;
    chunkLen[0] = 2;
    chunkLen[1] = 4;
    chunkLen[2] = 4;
    chunkLen[3] = 1;
    VMPI_SendChunks((const void *const *)pChunks, pChunkLengths: chunkLen, nChunks: 4, iDest: v15, fVMPISendFlags: 0);
    return 1;
  }
  v7 = v6 - 2;
  if ( v7 != 0 )
  {
    if ( v7 != 1 )
      return 0;
    CMasterMulticastThread::OnFileReceived(
      this: &this->m_MasterThread,
      fileID: *((unsigned __int16 *)m_pMemory + 1),
      clientID: iSource);
    return 1;
  }
  v9 = (unsigned __int16 *)(m_pMemory + 2);
  v10 = (unsigned __int16 *)(m_pMemory + 4);
  v11 = (ConCommandBase::GetName(this: (CVTFTexture *)pBuf) - 2) / 4;
  if ( v11 <= 0 )
    return 1;
  pBuf = &this->m_MasterThread;
  for ( i = v11; i != 0; --i )
  {
    CMasterMulticastThread::OnChunkReceived(this: pBuf, a2: (int)v10, fileID: *v9, clientID: iSource, iChunk: *v10);
    v9 += 2;
    v10 += 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008F780
// Name: public: bool CMasterMulticastThread::Init(class IBaseFileSystem __near *,unsigned short,class CIPAddr const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterMulticastThread::Init(
        CMasterMulticastThread *this,
        IBaseFileSystem *pPassThru,
        int localPort,
        const CIPAddr *pAddr,
        unsigned int maxMemoryUsage)
{
  SOCKET v6; // eax
  HANDLE v8; // eax
  SOCKET m_Socket; // [esp-14h] [ebp-34h]
  sockaddr_in addr; // [esp+8h] [ebp-18h] BYREF
  CIPAddr localAddr; // [esp+18h] [ebp-8h] BYREF

  CMasterMulticastThread::Term(this);
  this->m_nMaxMemoryUsage = maxMemoryUsage;
  this->m_nCurMemoryUsage = 0;
  if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
  {
    this->m_Socket = -1;
  }
  else
  {
    v6 = socket(af: 2, type: 2, protocol: 0);
    this->m_Socket = v6;
    if ( v6 == -1 )
    {
      _Warning(a1: "CMasterMulticastThread::Init - socket() failed\n");
      return 0;
    }
    CIPAddr::CIPAddr(this: &localAddr, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: (unsigned __int16)localPort);
    IPAddrToSockAddr(pIn: &localAddr, pOut: &addr);
    if ( bind(s: this->m_Socket, name: (const struct sockaddr *)&addr, namelen: 16) != 0 )
    {
      CMasterMulticastThread::Term(this);
      _Warning(a1: "CMasterMulticastThread::Init - bind( %d.%d.%d.%d:%d ) failed\n");
      return 0;
    }
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
    {
      m_Socket = this->m_Socket;
      localPort = 1;
      if ( setsockopt(s: m_Socket, level: 0xFFFF, optname: 32, optval: (const char *)&localPort, optlen: 1) == -1 )
      {
        CMasterMulticastThread::Term(this);
        _Warning(a1: "CMasterMulticastThread::Init - setsockopt() failed to set broadcast mode\n");
        return 0;
      }
    }
    IPAddrToSockAddr(pIn: pAddr, pOut: &this->m_MulticastAddr);
    maxMemoryUsage = 0;
    v8 = CreateThread(
           lpThreadAttributes: nullptr,
           dwStackSize: 0,
           lpStartAddress: (LPTHREAD_START_ROUTINE)CMasterMulticastThread::StaticMulticastThread,
           lpParameter: this,
           dwCreationFlags: 0,
           lpThreadId: &maxMemoryUsage);
    this->m_hThread = v8;
    if ( v8 == nullptr )
    {
      CMasterMulticastThread::Term(this);
      _Warning(a1: "CMasterMulticastThread::Init - CreateThread failed\n");
      return 0;
    }
    SetThreadPriority(hThread: v8, nPriority: -2);
  }
  this->m_hMainThread = GetCurrentThread();
  this->m_pPassThru = pPassThru;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008F930
// Name: public: bool CMasterVMPIFileSystem::Init(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __thiscall CMasterVMPIFileSystem::Init(
        CMasterVMPIFileSystem *this,
        unsigned int maxMemoryUsage,
        IFileSystem *pPassThru)
{
  IFileSystem *v3; // edi
  IUniformRandomStream *v5; // ecx
  int v6; // ebx
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  IUniformRandomStream *v9; // ecx
  IUniformRandomStream *v10; // ecx
  IBaseFileSystem *v11; // eax
  char result; // al
  unsigned __int64 v13; // [esp-20h] [ebp-38h]
  CCycleCount cnt; // [esp+Ch] [ebp-Ch] BYREF
  CCycleCount *p_cnt; // [esp+14h] [ebp-4h]

  v3 = pPassThru;
  this->InitPassThru_2(this, a2: pPassThru, a3: false);
  this->m_pMasterVMPIFileSystemPassThru = v3;
  p_cnt = &cnt;
  cnt.m_Int64 = __rdtsc();
  HIDWORD(v13) = HIDWORD(_g_ClockSpeed);
  LODWORD(v13) = _g_ClockSpeed;
  ((void (__cdecl *)(_DWORD))_RandomSeed)(a1: 1000000 * cnt.m_Int64 / v13);
  v6 = (unsigned __int16)_RandomInt(this: v5, a2: 22000, a3: 25000);
  if ( VMPI_GetRunMode() != VMPI_RUN_NETWORKED )
  {
    CIPAddr::Init(this: &this->m_MulticastIP, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: 0);
  }
  else if ( VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_MULTICAST )
  {
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
      CIPAddr::Init(this: &this->m_MulticastIP, ip0: 255, ip1: 255, ip2: 255, ip3: 255, ipPort: v6);
  }
  else
  {
    this->m_MulticastIP.port = v6;
    this->m_MulticastIP.ip[0] = _RandomInt(this: v7, a2: 225, a3: 238);
    this->m_MulticastIP.ip[1] = _RandomInt(this: v8, a2: 0, a3: 255);
    this->m_MulticastIP.ip[2] = _RandomInt(this: v9, a2: 0, a3: 255);
    this->m_MulticastIP.ip[3] = _RandomInt(this: v10, a2: 3, a3: 255);
  }
  if ( pPassThru != nullptr )
    v11 = &pPassThru->IBaseFileSystem;
  else
    v11 = nullptr;
  result = CMasterMulticastThread::Init(
             this: &this->m_MasterThread,
             pPassThru: v11,
             localPort: 23412,
             pAddr: &this->m_MulticastIP,
             maxMemoryUsage);
  if ( result != 0 )
  {
    LOWORD(pPassThru) = 1280;
    VMPI_Send2Chunks(
      pChunk1: &pPassThru,
      chunk1Len: 2,
      pChunk2: &this->m_MulticastIP,
      chunk2Len: 6,
      iDest: -3,
      fVMPISendFlags: 0);
    VMPI_AddDisconnectHandler(handler: (void (__cdecl *)(int, const char *))CMasterVMPIFileSystem::OnClientDisconnect);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008FAA0
// Name: class CBaseVMPIFileSystem __near * CreateMasterVMPIFileSystem(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CMasterVMPIFileSystem *__cdecl CreateMasterVMPIFileSystem(unsigned int maxMemoryUsage, IFileSystem *pPassThru)
{
  CMasterVMPIFileSystem *v2; // eax
  CMasterVMPIFileSystem *v3; // esi

  v2 = (CMasterVMPIFileSystem *)MemAlloc_Alloc(nSize: 0xBCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&IBaseFileSystem::`vftable';
    v2->m_pBaseFileSystemPassThru = nullptr;
    v2->m_pFileSystemPassThru = nullptr;
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CMasterVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
    CIPAddr::CIPAddr(this: &v2->m_MulticastIP);
    v3->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CMasterVMPIFileSystem_vtbl *)&CMasterVMPIFileSystem::`vftable'{for `IAppSystem'};
    v3->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CMasterVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
    CMasterMulticastThread::CMasterMulticastThread(this: &v3->m_MasterThread);
    CMasterVMPIFileSystem::s_pMasterVMPIFileSystem = v3;
  }
  else
  {
    v3 = nullptr;
  }
  g_pBaseVMPIFileSystem = v3;
  if ( CMasterVMPIFileSystem::Init(this: v3, maxMemoryUsage, pPassThru) != 0 )
    return v3;
  if ( v3 != nullptr )
    ((void (__thiscall *)(CMasterVMPIFileSystem *, int))v3->dtr_CBaseVMPIFileSystem)(a1: v3, a2: 1);
  g_pBaseVMPIFileSystem = nullptr;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10097340
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CMasterMulticastThread::CMulticastFile __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
        CUtlMemory<CVTFTexture::ResourceMemorySection,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x10012DA0
// Name: public: void CUtlMemory<class CTransmitRateMgr::CMachineRecord,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
        CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CTransmitRateMgr::CMachineRecord *m_pMemory; // edx
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
      this->m_pMemory = (CTransmitRateMgr::CMachineRecord *)_g_pMemAlloc->Realloc_2(
                                                              this: _g_pMemAlloc,
                                                              a2: m_pMemory,
                                                              a3: v7);
    else
      this->m_pMemory = (CTransmitRateMgr::CMachineRecord *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022E10
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CMasterMulticastThread::CMulticastFile __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CWorkerFile *,int> *)_g_pMemAlloc->Realloc_2(
                                                                    this: _g_pMemAlloc,
                                                                    a2: m_pMemory,
                                                                    a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CWorkerFile *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C510
// Name: public: virtual class CSysModule __near * CMasterVMPIFileSystem::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct CSysModule *__thiscall CMasterVMPIFileSystem::LoadModule(
        CMasterVMPIFileSystem *this,
        const char *pFileName,
        const char *pPathID,
        BOOL bValidatedDllOnly)
{
  return this->m_pMasterVMPIFileSystemPassThru->LoadModule(
           this: this->m_pMasterVMPIFileSystemPassThru,
           a2: pFileName,
           a3: pPathID,
           a4: bValidatedDllOnly);
}

//------------------------------------------------------------------------------
// Address: 0x1002C530
// Name: public: virtual void CMasterVMPIFileSystem::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::UnloadModule(CMasterVMPIFileSystem *this, struct CSysModule *pModule)
{
  this->m_pMasterVMPIFileSystemPassThru->UnloadModule(this: this->m_pMasterVMPIFileSystemPassThru, a2: pModule);
}

//------------------------------------------------------------------------------
// Address: 0x1002C5F0
// Name: public: void CRateLimiter::NoteExcessTimeTaken(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRateLimiter::NoteExcessTimeTaken(CRateLimiter *this, unsigned int excessTimeInMicroseconds)
{
  unsigned int m_AccumulatedSleepMicroseconds; // eax
  unsigned int v3; // esi
  unsigned __int64 v4; // [esp-Ch] [ebp-20h]
  CCycleCount startCount; // [esp+Ch] [ebp-8h]

  m_AccumulatedSleepMicroseconds = this->m_AccumulatedSleepMicroseconds;
  if ( excessTimeInMicroseconds <= m_AccumulatedSleepMicroseconds )
  {
    this->m_AccumulatedSleepMicroseconds = m_AccumulatedSleepMicroseconds - excessTimeInMicroseconds;
  }
  else
  {
    v3 = excessTimeInMicroseconds - m_AccumulatedSleepMicroseconds;
    this->m_AccumulatedSleepMicroseconds = 0;
    startCount.m_Int64 = __rdtsc();
    do
    {
      HIDWORD(v4) = HIDWORD(_g_ClockSpeed);
      LODWORD(v4) = _g_ClockSpeed;
    }
    while ( (unsigned int)(1000000 * (__rdtsc() - startCount.m_Int64) / v4) < v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C690
// Name: public: virtual void CVMPIFile_PassThru::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Close(CVMPIFile_PassThru *this)
{
  this->m_pPassThru->Close(this: this->m_pPassThru, a2: this->m_fp);
  operator delete(p: this);
}

//------------------------------------------------------------------------------
// Address: 0x1002C6B0
// Name: public: virtual void CVMPIFile_PassThru::Seek(int,enum FileSystemSeek_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Seek(CVMPIFile_PassThru *this, int pos, FileSystemSeek_t seekType)
{
  this->m_pPassThru->Seek(this: this->m_pPassThru, a2: this->m_fp, a3: pos, a4: seekType);
}

//------------------------------------------------------------------------------
// Address: 0x1002C6E0
// Name: public: virtual unsigned int CVMPIFile_PassThru::Tell(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_PassThru::Tell(CVMPIFile_PassThru *this)
{
  return this->m_pPassThru->Tell(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1002C700
// Name: public: virtual unsigned int CVMPIFile_PassThru::Size(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVMPIFile_PassThru::Size(CVMPIFile_PassThru *this)
{
  return this->m_pPassThru->Size_2(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1002C720
// Name: public: virtual void CVMPIFile_PassThru::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMPIFile_PassThru::Flush(CVMPIFile_PassThru *this)
{
  this->m_pPassThru->Flush(this: this->m_pPassThru, a2: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1002C740
// Name: public: virtual int CVMPIFile_PassThru::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_PassThru::Read(CVMPIFile_PassThru *this, void *pOutput, int size)
{
  return this->m_pPassThru->Read(this: this->m_pPassThru, a2: pOutput, a3: size, a4: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1002C760
// Name: public: virtual int CVMPIFile_PassThru::Write(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVMPIFile_PassThru::Write(CVMPIFile_PassThru *this, const void *pInput, int size)
{
  return this->m_pPassThru->Write(this: this->m_pPassThru, a2: pInput, a3: size, a4: this->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1002C780
// Name: public: void CRateLimiter::GiveUpTimeSlice(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRateLimiter::GiveUpTimeSlice(CRateLimiter *this)
{
  CCycleCount *p_m_LastSleepTime; // edi
  unsigned __int64 v3; // [esp-Ch] [ebp-30h]
  unsigned __int64 v4; // [esp-Ch] [ebp-30h]
  unsigned __int64 v5; // [esp+8h] [ebp-1Ch] BYREF
  CFastTimer sleepTimer; // [esp+10h] [ebp-14h] BYREF
  CCycleCount currentTime; // [esp+18h] [ebp-Ch] BYREF
  CFastTimer *p_currentTime; // [esp+20h] [ebp-4h]

  p_currentTime = (CFastTimer *)&currentTime;
  currentTime.m_Int64 = __rdtsc();
  p_m_LastSleepTime = &this->m_LastSleepTime;
  HIDWORD(v3) = HIDWORD(_g_ClockSpeed);
  LODWORD(v3) = _g_ClockSpeed;
  if ( (unsigned int)(1000 * (currentTime.m_Int64 - this->m_LastSleepTime.m_Int64) / v3) >= this->m_SleepIntervalMS )
  {
    p_currentTime = &sleepTimer;
    sleepTimer.m_Duration.m_Int64 = __rdtsc();
    Sleep(dwMilliseconds: 0xAu);
    p_currentTime = (CFastTimer *)&v5;
    v5 = __rdtsc();
    sleepTimer.m_Duration.m_Int64 = v5 - sleepTimer.m_Duration.m_Int64;
    HIDWORD(v4) = HIDWORD(_g_ClockSpeed);
    LODWORD(v4) = _g_ClockSpeed;
    this->m_AccumulatedSleepMicroseconds += 1000000 * sleepTimer.m_Duration.m_Int64 / v4;
    p_m_LastSleepTime->m_Int64 = __rdtsc();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C860
// Name: private: void CMasterMulticastThread::TCP_SendNextChunk(class CMasterMulticastThread::CMulticastFile __near *,class CMasterMulticastThread::CClientFileInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::TCP_SendNextChunk(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pFile,
        CMasterMulticastThread::CClientFileInfo *pClient)
{
  CMasterMulticastThread::CMulticastFile *v3; // edx
  CMasterMulticastThread::CClientFileInfo *v4; // ebx
  int v5; // eax
  int v6; // ecx
  int m_Size; // edi
  int v8; // esi
  char *m_pMemory; // eax
  char *v10; // edx
  int m_ClientID; // [esp-10h] [ebp-3Ch]
  const void *chunks[5]; // [esp+4h] [ebp-28h] BYREF
  int chunkLengths[5]; // [esp+18h] [ebp-14h] BYREF

  v3 = pFile;
  v4 = pClient;
  v5 = pClient->m_TCP_LastChunkSent + 1;
  if ( v5 < pFile->m_Info.m_nChunks )
  {
    v6 = v5 << 14;
    m_Size = pFile->m_Data.m_Size;
    v8 = (v5 << 14) + 0x4000;
    pFile = (CMasterMulticastThread::CMulticastFile *)(pClient->m_TCP_LastChunkSent + 1);
    if ( v8 >= m_Size )
      v8 = m_Size;
    if ( v6 < m_Size )
    {
      pClient->m_TCP_LastChunkSent = v5;
      chunks[0] = &pClient;
      chunks[1] = &v3->m_Info;
      chunks[2] = &pFile;
      m_pMemory = v3->m_Filename.m_Memory.m_pMemory;
      v10 = v3->m_Data.m_Memory.m_pMemory;
      LOWORD(pClient) = 1536;
      chunks[3] = m_pMemory;
      chunks[4] = &v10[v6];
      chunkLengths[0] = 2;
      chunkLengths[1] = 12;
      chunkLengths[2] = 4;
      chunkLengths[3] = strlen(m_pMemory) + 1;
      m_ClientID = v4->m_ClientID;
      chunkLengths[4] = v8 - v6;
      VMPI_SendChunks(pChunks: chunks, pChunkLengths: chunkLengths, nChunks: 5, iDest: m_ClientID, fVMPISendFlags: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C920
// Name: private: bool CMasterMulticastThread::Thread_SendFileChunk_Multicast(int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMasterMulticastThread::Thread_SendFileChunk_Multicast(
        CMasterMulticastThread *this,
        unsigned int *pnBytesSent)
{
  CMasterMulticastThread::CMulticastFile *m_Element; // ecx
  volatile int v4; // edx
  int m_Size; // edi
  unsigned int v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned int v8; // eax
  int v9; // edi
  bool v10; // zf
  unsigned int v11; // eax
  int v13; // ecx
  DWORD LastError; // eax
  char dst[8192]; // [esp+Ch] [ebp-202Ch] BYREF
  _WSABUF count; // [esp+200Ch] [ebp-2Ch] BYREF
  unsigned int v17; // [esp+2014h] [ebp-24h]
  unsigned __int8 *p_m_iCurActiveChunk; // [esp+2018h] [ebp-20h]
  unsigned int v19; // [esp+201Ch] [ebp-1Ch]
  unsigned __int8 *m_pMemory; // [esp+2020h] [ebp-18h]
  unsigned int v21; // [esp+2024h] [ebp-14h]
  unsigned __int8 *v22; // [esp+2028h] [ebp-10h]
  char Buffer[4]; // [esp+202Ch] [ebp-Ch] BYREF
  unsigned int NumberOfBytesSent; // [esp+2030h] [ebp-8h] BYREF
  int len; // [esp+2034h] [ebp-4h]

  m_Element = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element;
  v4 = this->m_iCurActiveChunk << 10;
  m_Size = m_Element->m_Data.m_Size;
  len = v4 + 1024;
  if ( v4 + 1024 >= m_Size )
    len = m_Size;
  count.buf = (char *)&m_Element->m_Info;
  count.len = 12;
  p_m_iCurActiveChunk = (unsigned __int8 *)&this->m_iCurActiveChunk;
  v17 = 4;
  m_pMemory = (unsigned __int8 *)m_Element->m_Filename.m_Memory.m_pMemory;
  v6 = strlen(m_Element->m_Filename.m_Memory.m_pMemory) + 1;
  v19 = v6;
  v7 = (unsigned __int8 *)&m_Element->m_Data.m_Memory.m_pMemory[v4];
  v10 = this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b1 == 127;
  v21 = len - v4;
  v8 = len - v4 + v6 + 16;
  v22 = v7;
  NumberOfBytesSent = 0;
  len = v8;
  if ( !v10
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b2 != 0
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b3 != 0
    || this->m_MulticastAddr.sin_addr.S_un.S_un_b.s_b4 != 1 )
  {
    WSASendTo(
      s: this->m_Socket,
      lpBuffers: &count,
      dwBufferCount: 4u,
      lpNumberOfBytesSent: &NumberOfBytesSent,
      dwFlags: 0,
      lpTo: (const struct sockaddr *)&this->m_MulticastAddr,
      iTolen: 16,
      lpOverlapped: nullptr,
      lpCompletionRoutine: nullptr);
    v11 = NumberOfBytesSent;
    v10 = NumberOfBytesSent == len;
    v9 = len;
  }
  else
  {
    if ( v8 > 0x2000 )
    {
      _Error(a1: "nWantedBytes > sizeof( allData )");
      v7 = v22;
      v6 = v19;
    }
    memcpy((unsigned __int8 *)dst, src: (unsigned __int8 *)count.buf, count: count.len);
    memcpy(dst: (unsigned __int8 *)&dst[count.len], src: p_m_iCurActiveChunk, count: v17);
    memcpy(dst: (unsigned __int8 *)&dst[count.len + v17], src: m_pMemory, count: v6);
    memcpy(dst: (unsigned __int8 *)&dst[count.len + v17 + v6], src: v7, count: v21);
    v9 = len;
    v10 = sendto(
            s: this->m_Socket,
            buf: dst,
            len,
            flags: 0,
            to: (const struct sockaddr *)&this->m_MulticastAddr,
            tolen: 16) == v9;
    v11 = NumberOfBytesSent;
  }
  if ( v10 )
  {
    *pnBytesSent = v11;
    return v10;
  }
  v13 = `CMasterMulticastThread::Thread_SendFileChunk_Multicast'::`14'::nWarnings + 1;
  `CMasterMulticastThread::Thread_SendFileChunk_Multicast'::`14'::nWarnings = v13;
  if ( v13 >= 10 )
  {
    if ( v13 == 10 )
      _Warning(a1: "\nThis machine's ability to multicast may be broken. Please reboot and try again.\n");
  }
  else
  {
    _Warning(a1: "\nMulticastThread: WSASendTo with %d bytes sent %d bytes.\n", v9, v11);
    LastError = GetLastError();
    if ( FormatMessageA(
           dwFlags: 0x1300u,
           lpSource: nullptr,
           dwMessageId: LastError,
           dwLanguageId: 0x400u,
           lpBuffer: Buffer,
           nSize: 0,
           Arguments: nullptr) != 0 )
    {
      _Warning(a1: "%s", *(const char **)Buffer);
      LocalFree(hMem: *(HLOCAL *)Buffer);
      return false;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1002CEF0
// Name: private: int CMasterMulticastThread::FindFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FindFile(CMasterMulticastThread *this, const char *pName, const char *pPathID)
{
  int m_Head; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  CMasterMulticastThread *v6; // [esp+Ch] [ebp-4h]

  m_Head = this->m_Files.m_Head;
  v6 = this;
  if ( m_Head == -1 )
    return -1;
  while ( 1 )
  {
    m_Element = this->m_Files.m_Memory.m_pMemory[m_Head].m_Element;
    if ( _V_stricmp(s1: m_Element->m_Filename.m_Memory.m_pMemory, s2: pName) == 0
      && _V_stricmp(s1: m_Element->m_PathID.m_Memory.m_pMemory, s2: pPathID) == 0 )
    {
      break;
    }
    m_Head = v6->m_Files.m_Memory.m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      return -1;
    this = v6;
  }
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x1002CF70
// Name: private: void CMasterMulticastThread::EnsureMemoryLimit(class CMasterMulticastThread::CMulticastFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::EnsureMemoryLimit(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pIgnore)
{
  unsigned int m_nMaxMemoryUsage; // eax
  int i; // eax
  int v5; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // esi

  m_nMaxMemoryUsage = this->m_nMaxMemoryUsage;
  if ( m_nMaxMemoryUsage != 0 && this->m_nCurMemoryUsage > m_nMaxMemoryUsage )
  {
    for ( i = this->m_Files.m_Head; i != -1; i = this->m_Files.m_Memory.m_pMemory[v5].m_Next )
    {
      v5 = i;
      m_Element = this->m_Files.m_Memory.m_pMemory[i].m_Element;
      if ( m_Element != pIgnore && m_Element->m_bDataLoaded && m_Element->m_ActiveChunks.m_ElementCount == 0 )
      {
        this->m_nCurMemoryUsage -= m_Element->m_Info.m_CompressedSize + m_Element->m_Info.m_UncompressedSize;
        CUtlVector<char,CUtlMemory<char,int>>::Purge(this: &m_Element->m_Data);
        CUtlVector<char,CUtlMemory<char,int>>::Purge(this: &m_Element->m_UncompressedData);
        m_Element->m_bDataLoaded = false;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D060
// Name: public: CTransmitRateMgr::CTransmitRateMgr(void)
// Source: json
//------------------------------------------------------------------------------
CTransmitRateMgr *__thiscall CTransmitRateMgr::CTransmitRateMgr(CTransmitRateMgr *this)
{
  long double v2; // xmm1_8
  ISocket *IPSocket; // eax
  unsigned __int64 v5; // [esp-14h] [ebp-20h]
  CCycleCount cnt; // [esp+0h] [ebp-Ch] BYREF
  CCycleCount *p_cnt; // [esp+8h] [ebp-4h]

  this->m_MachineRecords.m_Memory.m_pMemory = nullptr;
  this->m_MachineRecords.m_Memory.m_nAllocationCount = 0;
  this->m_MachineRecords.m_Memory.m_nGrowSize = 0;
  this->m_MachineRecords.m_Size = 0;
  this->m_MachineRecords.m_pElements = nullptr;
  v2 = 1000000.0 / (double)MULTICAST_TRANSMIT_RATE;
  this->m_flLastBroadcastTime = 0.0;
  this->m_nMicrosecondsPerByte = v2;
  this->m_UniqueID = (unsigned int)this;
  p_cnt = &cnt;
  cnt.m_Int64 = __rdtsc();
  HIDWORD(v5) = HIDWORD(_g_ClockSpeed);
  LODWORD(v5) = _g_ClockSpeed;
  this->m_UniqueID += 1000000 * cnt.m_Int64 / v5;
  Sleep(dwMilliseconds: 1u);
  HIDWORD(v5) = HIDWORD(_g_ClockSpeed);
  LODWORD(v5) = _g_ClockSpeed;
  this->m_UniqueID += 1000000 * cnt.m_Int64 / v5;
  IPSocket = CreateIPSocket();
  this->m_pSocket = IPSocket;
  if ( IPSocket != nullptr )
    IPSocket->BindToAny(this: IPSocket, a2: 21146u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002D140
// Name: public: CMasterMulticastThread::CMasterMulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
CMasterMulticastThread *__thiscall CMasterMulticastThread::CMasterMulticastThread(CMasterMulticastThread *this)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *m_pMemory; // ecx
  UtlLinkedListElem_t<char *,int> *v3; // edx

  this->m_Files.m_Memory.m_pMemory = nullptr;
  this->m_Files.m_Memory.m_nAllocationCount = 0;
  this->m_Files.m_Memory.m_nGrowSize = 0;
  this->m_Files.m_LastAlloc.index = -1;
  m_pMemory = this->m_Files.m_Memory.m_pMemory;
  this->m_Files.m_Head = -1;
  this->m_Files.m_Tail = -1;
  this->m_Files.m_FirstFree = -1;
  this->m_Files.m_ElementCount = 0;
  this->m_Files.m_NumAlloced = 0;
  this->m_Files.m_pElements = m_pMemory;
  this->m_WarningSuppressions.m_Memory.m_pMemory = nullptr;
  this->m_WarningSuppressions.m_Memory.m_nAllocationCount = 0;
  this->m_WarningSuppressions.m_Memory.m_nGrowSize = 0;
  this->m_WarningSuppressions.m_LastAlloc.index = -1;
  v3 = this->m_WarningSuppressions.m_Memory.m_pMemory;
  this->m_WarningSuppressions.m_Head = -1;
  this->m_WarningSuppressions.m_Tail = -1;
  this->m_WarningSuppressions.m_FirstFree = -1;
  this->m_WarningSuppressions.m_ElementCount = 0;
  this->m_WarningSuppressions.m_NumAlloced = 0;
  this->m_WarningSuppressions.m_pElements = v3;
  this->m_hMainThread = nullptr;
  this->m_hThread = nullptr;
  this->m_Socket = -1;
  this->m_nTotalActiveChunks = 0;
  this->m_iCurActiveChunk = -1;
  this->m_iCurFile = -1;
  this->m_pPassThru = nullptr;
  this->m_hTermEvent = CreateEventA(
                         lpEventAttributes: nullptr,
                         bManualReset: false,
                         bInitialState: false,
                         lpName: nullptr);
  InitializeCriticalSection(lpCriticalSection: &this->m_CS);
  this->m_nMaxMemoryUsage = 0;
  this->m_nCurMemoryUsage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002D1E0
// Name: public: CMasterMulticastThread::CMulticastFile::CMulticastFile(void)
// Source: json
//------------------------------------------------------------------------------
CMasterMulticastThread::CMulticastFile *__thiscall CMasterMulticastThread::CMulticastFile::CMulticastFile(
        CMasterMulticastThread::CMulticastFile *this)
{
  CMasterMulticastThread::CMulticastFile *result; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // ecx

  result = this;
  this->m_Filename.m_Memory.m_pMemory = nullptr;
  this->m_Filename.m_Memory.m_nAllocationCount = 0;
  this->m_Filename.m_Memory.m_nGrowSize = 0;
  this->m_Filename.m_Size = 0;
  this->m_Filename.m_pElements = nullptr;
  this->m_PathID.m_Memory.m_pMemory = nullptr;
  this->m_PathID.m_Memory.m_nAllocationCount = 0;
  this->m_PathID.m_Memory.m_nGrowSize = 0;
  this->m_PathID.m_Size = 0;
  this->m_PathID.m_pElements = nullptr;
  this->m_UncompressedData.m_Memory.m_pMemory = nullptr;
  this->m_UncompressedData.m_Memory.m_nAllocationCount = 0;
  this->m_UncompressedData.m_Memory.m_nGrowSize = 0;
  this->m_UncompressedData.m_Size = 0;
  this->m_UncompressedData.m_pElements = nullptr;
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_Chunks.m_Memory.m_pMemory = nullptr;
  this->m_Chunks.m_Memory.m_nAllocationCount = 0;
  this->m_Chunks.m_Memory.m_nGrowSize = 0;
  this->m_Chunks.m_Size = 0;
  this->m_Chunks.m_pElements = nullptr;
  this->m_ActiveChunks.m_Memory.m_pMemory = nullptr;
  this->m_ActiveChunks.m_Memory.m_nAllocationCount = 0;
  this->m_ActiveChunks.m_Memory.m_nGrowSize = 0;
  this->m_ActiveChunks.m_LastAlloc.index = -1;
  this->m_ActiveChunks.m_Head = -1;
  this->m_ActiveChunks.m_Tail = -1;
  this->m_ActiveChunks.m_FirstFree = -1;
  this->m_ActiveChunks.m_ElementCount = 0;
  this->m_ActiveChunks.m_NumAlloced = 0;
  this->m_ActiveChunks.m_pElements = this->m_ActiveChunks.m_Memory.m_pMemory;
  this->m_Clients.m_Memory.m_pMemory = nullptr;
  this->m_Clients.m_Memory.m_nAllocationCount = 0;
  this->m_Clients.m_Memory.m_nGrowSize = 0;
  this->m_Clients.m_LastAlloc.index = -1;
  this->m_Clients.m_ElementCount = 0;
  this->m_Clients.m_NumAlloced = 0;
  m_pMemory = this->m_Clients.m_Memory.m_pMemory;
  result->m_Clients.m_Head = -1;
  result->m_Clients.m_Tail = -1;
  result->m_Clients.m_FirstFree = -1;
  result->m_Clients.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D300
// Name: public: void CTransmitRateMgr::ReadPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransmitRateMgr::ReadPackets(CTransmitRateMgr *this)
{
  int i; // eax
  unsigned int v3; // ebx
  int v4; // eax
  bool v5; // zf
  CTransmitRateMgr::CMachineRecord *m_pMemory; // ecx
  int v7; // eax
  float v8; // xmm0_4
  int j; // edi
  char data[768]; // [esp+4h] [ebp-30Ch] BYREF
  CIPAddr ipFrom; // [esp+304h] [ebp-Ch] BYREF
  float flCurTime; // [esp+30Ch] [ebp-4h]

  if ( this->m_pSocket != nullptr )
  {
    flCurTime = _Plat_FloatTime();
    CIPAddr::CIPAddr(this: &ipFrom);
    for ( i = this->m_pSocket->RecvFrom(this: this->m_pSocket, a2: data, a3: 768, a4: &ipFrom);
          i != -1;
          i = this->m_pSocket->RecvFrom(this: this->m_pSocket, a2: data, a3: 768, a4: &ipFrom) )
    {
      if ( i == 10
        && *(_DWORD *)data == *(_DWORD *)s_cTransmitRateMgrPacket
        && s_cTransmitRateMgrPacket[4] == data[4]
        && s_cTransmitRateMgrPacket[5] == data[5] )
      {
        v3 = *(_DWORD *)&data[6];
        if ( *(_DWORD *)&data[6] != this->m_UniqueID )
        {
          v4 = 0;
          v5 = this->m_MachineRecords.m_Size == 0;
          if ( this->m_MachineRecords.m_Size > 0 )
          {
            m_pMemory = this->m_MachineRecords.m_Memory.m_pMemory;
            while ( m_pMemory->m_UniqueID != *(_DWORD *)&data[6] )
            {
              ++v4;
              ++m_pMemory;
              if ( v4 >= this->m_MachineRecords.m_Size )
                goto LABEL_14;
            }
            this->m_MachineRecords.m_Memory.m_pMemory[v4].m_flLastTime = flCurTime;
LABEL_14:
            v5 = v4 == this->m_MachineRecords.m_Size;
          }
          if ( v5 )
          {
            v7 = CUtlVector<CTransmitRateMgr::CMachineRecord,CUtlMemory<CTransmitRateMgr::CMachineRecord,int>>::AddToTail(this: &this->m_MachineRecords);
            v8 = flCurTime;
            this->m_MachineRecords.m_Memory.m_pMemory[v7].m_UniqueID = v3;
            this->m_MachineRecords.m_Memory.m_pMemory[v7].m_flLastTime = v8;
          }
        }
      }
      CIPAddr::CIPAddr(this: &ipFrom);
    }
    for ( j = 0; j < this->m_MachineRecords.m_Size; ++j )
    {
      if ( (float)(flCurTime - this->m_MachineRecords.m_Memory.m_pMemory[j].m_flLastTime) > 0.7 )
      {
        if ( this->m_MachineRecords.m_Size - j - 1 > 0 )
          _V_memmove(
            dest: &this->m_MachineRecords.m_Memory.m_pMemory[j],
            src: &this->m_MachineRecords.m_Memory.m_pMemory[j + 1],
            count: 8 * (this->m_MachineRecords.m_Size - j - 1));
        --this->m_MachineRecords.m_Size;
        --j;
      }
    }
    this->m_nMicrosecondsPerByte = 1000000.0 / (double)(MULTICAST_TRANSMIT_RATE / (this->m_MachineRecords.m_Size + 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D550
// Name: ZLibCompress
// Source: json
//------------------------------------------------------------------------------
char __usercall ZLibCompress@<al>(CUtlMemory<unsigned char,int> *out@<esi>, unsigned __int8 *pData, unsigned int len)
{
  int v3; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned int v9; // edx
  int v10; // ebx
  z_stream_s zs; // [esp+8h] [ebp-38h] BYREF

  v3 = len;
  if ( len != 0 )
  {
    memset(dst: (unsigned __int8 *)&zs, value: 0, count: sizeof(zs));
    if ( deflateInit_(a1: &zs, a2: 1, a3: "1.1.3", a4: 56) != 0 )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        out[1].m_pMemory = nullptr;
        if ( v3 != 0 )
        {
          m_nAllocationCount = out->m_nAllocationCount;
          if ( v3 > m_nAllocationCount )
            CUtlMemory<char,int>::Grow(this: out, num: v3 - m_nAllocationCount);
          out[1].m_pMemory += v3;
          m_pMemory = (char *)out->m_pMemory;
          v7 = (int)&out[1].m_pMemory[-v3];
          out[1].m_nAllocationCount = (int)out->m_pMemory;
          if ( v7 > 0 && v3 > 0 )
            _V_memmove(dest: &m_pMemory[v3], src: m_pMemory, count: v7);
        }
        v8 = out->m_pMemory;
        zs.avail_in = len;
        zs.next_in = pData;
        v9 = (unsigned int)out[1].m_pMemory;
        zs.next_out = v8;
        zs.avail_out = v9;
        v10 = deflate(a1: &zs, a2: 4);
        deflateEnd(a1: &zs);
        if ( v10 == 1 )
          break;
        if ( v10 != 0 )
          return 0;
        v3 += 0x20000;
        memset(dst: (unsigned __int8 *)&zs, value: 0, count: sizeof(zs));
        if ( deflateInit_(a1: &zs, a2: 1, a3: "1.1.3", a4: 56) != 0 )
          return 0;
      }
      out[1].m_pMemory -= (unsigned int)&out[1].m_pMemory[-zs.total_out];
      return 1;
    }
  }
  else
  {
    out[1].m_pMemory = nullptr;
    if ( out->m_nGrowSize >= 0 )
    {
      if ( out->m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: out->m_pMemory);
        out->m_pMemory = nullptr;
      }
      out->m_nAllocationCount = 0;
    }
    out[1].m_nAllocationCount = (int)out->m_pMemory;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D6B0
// Name: public: CMasterMulticastThread::CMulticastFile::~CMulticastFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::CMulticastFile::~CMulticastFile(CMasterMulticastThread::CMulticastFile *this)
{
  CUtlLinkedList<CMasterMulticastThread::CClientFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Clients);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Clients);
  if ( this->m_Clients.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Clients.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Clients.m_Memory.m_pMemory);
      this->m_Clients.m_Memory.m_pMemory = nullptr;
    }
    this->m_Clients.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_ActiveChunks);
  if ( this->m_ActiveChunks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ActiveChunks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ActiveChunks.m_Memory.m_pMemory);
      this->m_ActiveChunks.m_Memory.m_pMemory = nullptr;
    }
    this->m_ActiveChunks.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Chunks);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Data);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_UncompressedData);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_PathID);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Filename);
}

//------------------------------------------------------------------------------
// Address: 0x1002D9D0
// Name: public: void CMasterMulticastThread::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::Term(CMasterMulticastThread *this)
{
  if ( this->m_hThread != nullptr )
  {
    SetEvent(hEvent: this->m_hTermEvent);
    WaitForSingleObject(hHandle: this->m_hThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hThread);
    this->m_hThread = nullptr;
  }
  if ( this->m_Socket != -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  CUtlLinkedList<CMasterMulticastThread::CMulticastFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Files);
  this->m_nMaxMemoryUsage = 0;
  this->m_nCurMemoryUsage = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002DA30
// Name: private: void CMasterMulticastThread::DecrementChunkRefCount(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::DecrementChunkRefCount(CMasterMulticastThread *this, int iFile, int iChunk)
{
  int v4; // ecx
  CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *m_Element; // ebx
  int m_FirstFree; // edx
  bool v7; // zf
  int v8; // edi
  volatile int m_iCurFile; // edx
  int v10; // eax
  int v11; // edi
  unsigned __int16 v12; // ax

  v4 = iFile;
  m_Element = (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)this->m_Files.m_Memory.m_pMemory[iFile].m_Element;
  m_FirstFree = m_Element[2].m_FirstFree;
  v7 = *(_WORD *)(m_FirstFree + 6 * iChunk + 2) == 0;
  v8 = m_FirstFree + 6 * iChunk;
  iChunk = v8;
  if ( v7 )
  {
    _Error(a1: "CMasterMulticastThread::DecrementChunkRefCount - refcount already zero!\n");
    v4 = iFile;
  }
  v7 = (*(_WORD *)(v8 + 2))-- == 1;
  if ( v7 )
  {
    m_iCurFile = this->m_iCurFile;
    --this->m_nTotalActiveChunks;
    if ( v4 == m_iCurFile )
    {
      v10 = *(unsigned __int16 *)(iChunk + 4);
      if ( v10 == this->m_iCurActiveChunk )
        this->m_iCurActiveChunk = m_Element[3].m_Memory.m_pMemory[v10].m_Next;
    }
    v11 = *(unsigned __int16 *)(iChunk + 4);
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: m_Element + 3,
      elem: v11);
    m_Element[3].m_Memory.m_pMemory[v11].m_Next = m_Element[3].m_FirstFree;
    m_Element[3].m_FirstFree = v11;
    v12 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToTail(
            this: (CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int> > *)&m_Element[3],
            src: (CMasterMulticastThread::CChunkInfo **)&iChunk);
    *(_WORD *)(iChunk + 4) = v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DAE0
// Name: private: int CMasterMulticastThread::FinishFileSetup(class CMasterMulticastThread::CMulticastFile __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FinishFileSetup(
        CMasterMulticastThread *this,
        CMasterMulticastThread::CMulticastFile *pFile,
        const char *pFilename,
        CMasterMulticastThread::CChunkInfo *pPathID,
        bool bFileAlreadyExisted)
{
  CMasterMulticastThread::CMulticastFile *v5; // edi
  CMasterMulticastThread *v6; // ebx
  unsigned int v8; // esi
  const char *v9; // ecx
  char *m_pMemory; // edx
  char v11; // al
  CMasterMulticastThread::CChunkInfo *v12; // ecx
  char *v13; // edx
  char m_iChunk; // al
  int v15; // ebx
  unsigned __int16 v16; // ax
  char *v17; // esi
  __int16 v18; // ax

  v5 = pFile;
  v6 = this;
  if ( ZLibCompress(
         out: (CUtlMemory<unsigned char,int> *)&pFile->m_Data,
         pData: (unsigned __int8 *)pFile->m_UncompressedData.m_Memory.m_pMemory,
         len: pFile->m_UncompressedData.m_Size) != 0 )
  {
    v5->m_bDataLoaded = true;
    v8 = VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_TCP ? 1024 : 0x4000;
    if ( !bFileAlreadyExisted )
    {
      CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v5->m_Filename,
        size: strlen(pFilename) + 1);
      v9 = pFilename;
      m_pMemory = v5->m_Filename.m_Memory.m_pMemory;
      do
      {
        v11 = *v9;
        *m_pMemory++ = *v9++;
      }
      while ( v11 != 0 );
      CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v5->m_PathID,
        size: strlen((const char *)pPathID) + 1);
      v12 = pPathID;
      v13 = v5->m_PathID.m_Memory.m_pMemory;
      do
      {
        m_iChunk = v12->m_iChunk;
        *v13 = v12->m_iChunk;
        v12 = (CMasterMulticastThread::CChunkInfo *)((char *)v12 + 1);
        ++v13;
      }
      while ( m_iChunk != 0 );
      v15 = 0;
      v5->m_nCycles = 0;
      v5->m_Info.m_CompressedSize = v5->m_Data.m_Size;
      v5->m_Info.m_UncompressedSize = v5->m_UncompressedData.m_Size;
      v16 = v8 * ((v5->m_Info.m_CompressedSize + v8 - 1) / v8) / v8;
      v5->m_Info.m_nChunks = v16;
      v5->m_Chunks.m_Size = 0;
      CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::InsertMultipleBefore(
        this: &v5->m_Chunks,
        elem: 0,
        num: v16);
      if ( v5->m_Chunks.m_Size > 0 )
      {
        pFilename = nullptr;
        do
        {
          v17 = (char *)&pFilename[(unsigned int)v5->m_Chunks.m_Memory.m_pMemory];
          *(_WORD *)v17 = v15;
          pPathID = (CMasterMulticastThread::CChunkInfo *)v17;
          *((_WORD *)v17 + 1) = 0;
          v18 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToTail(
                  this: &v5->m_ActiveChunks,
                  src: &pPathID);
          pFilename += 6;
          ++v15;
          *((_WORD *)v17 + 2) = v18;
        }
        while ( v15 < v5->m_Chunks.m_Size );
      }
      EnterCriticalSection(lpCriticalSection: &this->m_CS);
      v6 = this;
    }
    v6->m_nCurMemoryUsage += v5->m_Info.m_CompressedSize + v5->m_Info.m_UncompressedSize;
    CMasterMulticastThread::EnsureMemoryLimit(this: v6, pIgnore: v5);
    if ( !bFileAlreadyExisted )
    {
      v5->m_Info.m_FileID = CUtlLinkedList<CMasterMulticastThread::CMulticastFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>>::AddToTail(
                              this: &v6->m_Files,
                              src: &pFile);
      LeaveCriticalSection(lpCriticalSection: &v6->m_CS);
    }
    return v5->m_Info.m_FileID;
  }
  else
  {
    CMasterMulticastThread::CMulticastFile::~CMulticastFile(this: v5);
    operator delete(p: v5);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DC70
// Name: public: virtual void CMasterVMPIFileSystem::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::Term(CMasterVMPIFileSystem *this)
{
  CMasterMulticastThread::Term(this: &this->m_MasterThread);
}

//------------------------------------------------------------------------------
// Address: 0x1002DC80
// Name: public: CMasterMulticastThread::~CMasterMulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::~CMasterMulticastThread(CMasterMulticastThread *this)
{
  CMasterMulticastThread::Term(this);
  CloseHandle(hObject: this->m_hTermEvent);
  DeleteCriticalSection(lpCriticalSection: &this->m_CS);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_WarningSuppressions);
  if ( this->m_WarningSuppressions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WarningSuppressions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WarningSuppressions.m_Memory.m_pMemory);
      this->m_WarningSuppressions.m_Memory.m_pMemory = nullptr;
    }
    this->m_WarningSuppressions.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll((CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)this);
  if ( this->m_Files.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Files.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Files.m_Memory.m_pMemory);
      this->m_Files.m_Memory.m_pMemory = nullptr;
    }
    this->m_Files.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DD10
// Name: public: void CMasterMulticastThread::OnChunkReceived(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnChunkReceived(
        CMasterMulticastThread *this,
        int fileID,
        int clientID,
        int iChunk)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v4; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  int m_Head; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // edx
  CMasterMulticastThread::CClientFileInfo *v8; // esi

  if ( fileID >= 0
    && fileID < this->m_Files.m_Memory.m_nAllocationCount
    && fileID <= this->m_Files.m_LastAlloc.index
    && ((v4 = &this->m_Files.m_Memory.m_pMemory[fileID])->m_Previous != fileID || v4->m_Next == fileID) )
  {
    m_Element = v4->m_Element;
    m_Head = v4->m_Element->m_Clients.m_Head;
    if ( m_Head != -1 )
    {
      m_pMemory = m_Element->m_Clients.m_Memory.m_pMemory;
      while ( m_pMemory[m_Head].m_Element->m_ClientID != clientID )
      {
        m_Head = m_pMemory[m_Head].m_Next;
        if ( m_Head == -1 )
          return;
      }
      v8 = m_pMemory[m_Head].m_Element;
      if ( v8 != nullptr )
      {
        if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
        {
          EnterCriticalSection(lpCriticalSection: &this->m_CS);
          CMasterMulticastThread::TCP_SendNextChunk(this, pFile: m_Element, pClient: v8);
          LeaveCriticalSection(lpCriticalSection: &this->m_CS);
        }
        else if ( iChunk >= 0 && iChunk < m_Element->m_Chunks.m_Size )
        {
          v8->m_ChunksToSend.m_Memory.m_pMemory[iChunk >> 3] &= ~(1 << (iChunk & 7));
          --v8->m_nChunksLeft;
          v8->m_flLastAckTime = _Plat_FloatTime();
          if ( v8->m_nChunksLeft == 0 && g_iVMPIVerboseLevel >= 2 )
            _Warning(a1: "Client %d got file %s\n", clientID, m_Element->m_Filename.m_Memory.m_pMemory);
          EnterCriticalSection(lpCriticalSection: &this->m_CS);
          CMasterMulticastThread::DecrementChunkRefCount(this, iFile: fileID, iChunk);
          LeaveCriticalSection(lpCriticalSection: &this->m_CS);
        }
        else
        {
          _Warning(
            a1: "CMasterMulticastThread::OnChunkReceived: invalid chunk index (%d) for file %s\n",
            iChunk,
            m_Element->m_Filename.m_Memory.m_pMemory);
        }
      }
    }
  }
  else
  {
    _Warning(a1: "CMasterMulticastThread::OnChunkReceived: invalid file (%d) from client %d\n", fileID, clientID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DE70
// Name: public: void CMasterMulticastThread::OnFileReceived(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnFileReceived(CMasterMulticastThread *this, int fileID, int clientID)
{
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v3; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  int v5; // esi
  CMasterMulticastThread *v6; // [esp+4h] [ebp-4h]

  v6 = this;
  if ( fileID >= 0
    && fileID < this->m_Files.m_Memory.m_nAllocationCount
    && fileID <= this->m_Files.m_LastAlloc.index
    && ((v3 = &this->m_Files.m_Memory.m_pMemory[fileID])->m_Previous != fileID || v3->m_Next == fileID) )
  {
    m_Element = v3->m_Element;
    v5 = 0;
    if ( v3->m_Element->m_Info.m_nChunks != 0 )
    {
      while ( 1 )
      {
        CMasterMulticastThread::OnChunkReceived(this, fileID, clientID, iChunk: v5++);
        if ( v5 >= m_Element->m_Info.m_nChunks )
          break;
        this = v6;
      }
    }
  }
  else
  {
    _Warning(a1: "CMasterMulticastThread::OnChunkReceived: invalid file (%d) from client %d\n", fileID, clientID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DEF0
// Name: public: void CMasterMulticastThread::OnClientDisconnect(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::OnClientDisconnect(
        CMasterMulticastThread *this,
        int clientID,
        bool bGrabCriticalSection)
{
  CMasterMulticastThread *v3; // edi
  int m_Head; // eax
  int v5; // ecx
  CMasterMulticastThread::CMulticastFile *m_Element; // edx
  int v7; // esi
  int v8; // eax
  _DWORD *v9; // edi
  int v10; // ebx
  bool v11; // sf
  void *v12; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // edi
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *v14; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  int v17; // [esp+4h] [ebp-10h]
  int iFile; // [esp+8h] [ebp-Ch]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+10h] [ebp-4h]

  v3 = this;
  if ( bGrabCriticalSection )
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
  m_Head = v3->m_Files.m_Head;
  iFile = m_Head;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      v5 = 12 * m_Head;
      m_Element = v3->m_Files.m_Memory.m_pMemory[m_Head].m_Element;
      v7 = m_Element->m_Clients.m_Head;
      v17 = 12 * m_Head;
      pFile = m_Element;
      if ( v7 != -1 )
      {
        while ( 1 )
        {
          v8 = (int)&m_Element->m_Clients.m_Memory.m_pMemory[v7];
          v9 = *(_DWORD **)v8;
          if ( **(_DWORD **)v8 == clientID )
            break;
          v7 = *(_DWORD *)(v8 + 8);
          if ( v7 == -1 )
            goto LABEL_34;
        }
        v10 = 0;
        if ( m_Element->m_Info.m_nChunks != 0 )
        {
          do
          {
            if ( ((unsigned __int8)(1 << (v10 & 7)) & *(_BYTE *)((v10 >> 3) + v9[1])) != 0 )
              CMasterMulticastThread::DecrementChunkRefCount(this, iFile, iChunk: v10);
            ++v10;
          }
          while ( v10 < pFile->m_Info.m_nChunks );
        }
        v11 = (int)v9[3] < 0;
        v9[4] = 0;
        if ( !v11 )
        {
          if ( v9[1] != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v9[1]);
            v9[1] = 0;
          }
          v9[2] = 0;
        }
        v11 = (int)v9[3] < 0;
        v12 = (void *)v9[1];
        v9[5] = v12;
        if ( !v11 )
        {
          if ( v12 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
            v9[1] = 0;
          }
          v9[2] = 0;
        }
        operator delete(p: v9);
        if ( v7 >= 0 && v7 < pFile->m_Clients.m_Memory.m_nAllocationCount && v7 <= pFile->m_Clients.m_LastAlloc.index )
        {
          m_pMemory = pFile->m_Clients.m_Memory.m_pMemory;
          v14 = &m_pMemory[v7];
          if ( v14->m_Previous != v7 )
          {
            m_Previous = v14->m_Previous;
            if ( m_Previous == -1 )
              pFile->m_Clients.m_Head = v14->m_Next;
            else
              m_pMemory[m_Previous].m_Next = v14->m_Next;
            m_Next = v14->m_Next;
            if ( m_Next == -1 )
              pFile->m_Clients.m_Tail = v14->m_Previous;
            else
              pFile->m_Clients.m_Memory.m_pMemory[m_Next].m_Previous = v14->m_Previous;
            v14->m_Next = v7;
            v14->m_Previous = v7;
            --pFile->m_Clients.m_ElementCount;
          }
        }
        pFile->m_Clients.m_Memory.m_pMemory[v7].m_Next = pFile->m_Clients.m_FirstFree;
        v5 = v17;
        pFile->m_Clients.m_FirstFree = v7;
LABEL_34:
        v3 = this;
      }
      iFile = *(int *)((char *)&v3->m_Files.m_Memory.m_pMemory->m_Next + v5);
      if ( iFile == -1 )
        break;
      m_Head = *(int *)((char *)&v3->m_Files.m_Memory.m_pMemory->m_Next + v5);
    }
  }
  if ( bGrabCriticalSection )
    LeaveCriticalSection(lpCriticalSection: &v3->m_CS);
}

//------------------------------------------------------------------------------
// Address: 0x1002E0E0
// Name: public: void CMasterMulticastThread::CreateVirtualFile(char const __near *,void const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::CreateVirtualFile(
        CMasterMulticastThread *this,
        const char *pFilename,
        const char *pData,
        unsigned int fileLength)
{
  CMasterMulticastThread::CMulticastFile *v5; // eax
  CMasterMulticastThread::CMulticastFile *v6; // esi

  if ( CMasterMulticastThread::FindFile(this, pName: pFilename, pPathID: "VMPI_VIRTUAL_FILES_PATH_ID") != -1 )
    _Error(a1: "CMasterMulticastThread::CreateVirtualFile( %s ) - file already exists!", pFilename);
  v5 = (CMasterMulticastThread::CMulticastFile *)operator new(size: 0xC8u);
  if ( v5 != nullptr )
    v6 = CMasterMulticastThread::CMulticastFile::CMulticastFile(this: v5);
  else
    v6 = nullptr;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &v6->m_UncompressedData, pArray: pData, size: fileLength);
  CMasterMulticastThread::FinishFileSetup(
    this,
    pFile: v6,
    pFilename,
    pPathID: (CMasterMulticastThread::CChunkInfo *)"VMPI_VIRTUAL_FILES_PATH_ID",
    bFileAlreadyExisted: false);
}

//------------------------------------------------------------------------------
// Address: 0x1002E150
// Name: private: bool CMasterMulticastThread::CheckClientTimeouts(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterMulticastThread::CheckClientTimeouts(CMasterMulticastThread *this)
{
  CMasterMulticastThread *v1; // edi
  CMasterMulticastThread::CMulticastFile *m_Element; // esi
  char v3; // bl
  int m_Head; // eax
  float v5; // xmm2_4
  int v6; // edx
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *m_pMemory; // eax
  CMasterMulticastThread::CClientFileInfo *v8; // esi
  int m_Next; // ecx
  float m_flLastAckTime; // xmm1_4
  int v11; // eax
  CMasterMulticastThread::CMulticastFile *v12; // ecx
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v13; // ebx
  float *v14; // eax
  UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int> *v15; // edi
  float **v16; // eax
  float *v17; // ecx
  const char *MachineName; // eax
  const char *v20; // [esp-4h] [ebp-34h]
  int iNext; // [esp+1Ch] [ebp-14h]
  UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int> *v23; // [esp+24h] [ebp-Ch]
  float flCurTime; // [esp+28h] [ebp-8h]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+2Ch] [ebp-4h]

  v1 = this;
  m_Element = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element;
  v3 = 0;
  pFile = m_Element;
  flCurTime = _Plat_FloatTime();
  m_Head = m_Element->m_Clients.m_Head;
  if ( m_Head != -1 )
  {
    v5 = flCurTime;
    while ( 1 )
    {
      v6 = m_Head;
      m_pMemory = m_Element->m_Clients.m_Memory.m_pMemory;
      v8 = m_pMemory[v6].m_Element;
      m_Next = m_pMemory[v6].m_Next;
      iNext = m_Next;
      if ( v8->m_nChunksLeft != 0 && ++v8->m_nTimesFileCycled >= 5 )
      {
        m_flLastAckTime = v8->m_flLastAckTime;
        if ( (float)(v5 - m_flLastAckTime) > 20.0 )
        {
          v11 = v1->m_Files.m_Head;
          if ( v11 != -1 )
          {
            v23 = v1->m_Files.m_Memory.m_pMemory;
            do
            {
              v12 = v23[v11].m_Element;
              v13 = &v23[v11];
              v14 = (float *)v12->m_Clients.m_Head;
              if ( v14 != (float *)-1 )
              {
                v15 = v12->m_Clients.m_Memory.m_pMemory;
                do
                {
                  v16 = (float **)&v15[(_DWORD)v14];
                  v17 = *v16;
                  if ( *(_DWORD *)*v16 == v8->m_ClientID && m_flLastAckTime <= v17[10] )
                    m_flLastAckTime = v17[10];
                  v14 = v16[2];
                }
                while ( v14 != (float *)-1 );
                v1 = this;
              }
              v11 = v13->m_Next;
            }
            while ( v11 != -1 );
          }
          v20 = pFile->m_Filename.m_Memory.m_pMemory;
          MachineName = VMPI_GetMachineName(iProc: v8->m_ClientID);
          _Warning(
            a1: "\nClient %s timed out on file %s (latest: %.2f / cur: %.2f).\n",
            MachineName,
            v20,
            m_flLastAckTime,
            v5);
          CMasterMulticastThread::OnClientDisconnect(this: v1, clientID: v8->m_ClientID, bGrabCriticalSection: false);
          v5 = flCurTime;
          m_Next = iNext;
          v3 = 1;
        }
      }
      m_Head = m_Next;
      if ( m_Next == -1 )
        break;
      m_Element = pFile;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1002E2A0
// Name: private: void CMasterMulticastThread::Thread_SeekToNextActiveChunk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterMulticastThread::Thread_SeekToNextActiveChunk(CMasterMulticastThread *this)
{
  if ( this->m_iCurFile == -1 )
  {
    this->m_iCurFile = this->m_Files.m_Head;
    this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Head;
  }
  while ( this->m_iCurActiveChunk != -1
       && this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Element->m_RefCount != 0 )
  {
LABEL_10:
    if ( this->m_iCurActiveChunk != -1 )
    {
      if ( this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Element->m_RefCount != 0 )
        return;
      this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Next;
    }
  }
  if ( CMasterMulticastThread::CheckClientTimeouts(this) == 0 || this->m_nTotalActiveChunks != 0 )
  {
    this->m_iCurFile = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Next;
    if ( this->m_iCurFile == -1 )
      this->m_iCurFile = this->m_Files.m_Head;
    this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Head;
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E380
// Name: private: unsigned long CMasterMulticastThread::MulticastThread(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMasterMulticastThread::MulticastThread(CMasterMulticastThread *this)
{
  void (__stdcall *v2)(LPCRITICAL_SECTION); // ebx
  DWORD v3; // eax
  double v4; // st7
  unsigned int v5; // ecx
  unsigned __int64 v7; // [esp-10h] [ebp-80h]
  CTransmitRateMgr transmitRateMgr; // [esp+4h] [ebp-6Ch] BYREF
  CRateLimiter rateLimiter; // [esp+34h] [ebp-3Ch] BYREF
  int v10; // [esp+44h] [ebp-2Ch] BYREF
  __int16 v11; // [esp+48h] [ebp-28h]
  unsigned int m_UniqueID; // [esp+4Ah] [ebp-26h]
  unsigned __int64 v13; // [esp+50h] [ebp-20h] BYREF
  CFastTimer timer; // [esp+58h] [ebp-18h] BYREF
  __int64 v15; // [esp+60h] [ebp-10h]
  unsigned int msToWait; // [esp+68h] [ebp-8h]
  int nBytesSent; // [esp+6Ch] [ebp-4h] BYREF

  CTransmitRateMgr::CTransmitRateMgr(this: &transmitRateMgr);
  rateLimiter.m_SleepIntervalMS = 50;
  rateLimiter.m_AccumulatedSleepMicroseconds = 0;
  msToWait = (unsigned int)&rateLimiter.m_LastSleepTime;
  rateLimiter.m_LastSleepTime.m_Int64 = __rdtsc();
  if ( WaitForSingleObject(hHandle: this->m_hTermEvent, dwMilliseconds: 0) != 0 )
  {
    v2 = LeaveCriticalSection;
    do
    {
      CRateLimiter::GiveUpTimeSlice(this: &rateLimiter);
      msToWait = 0;
      EnterCriticalSection(lpCriticalSection: &this->m_CS);
      CTransmitRateMgr::ReadPackets(this: &transmitRateMgr);
      if ( this->m_nTotalActiveChunks == 0 )
        goto LABEL_4;
      if ( transmitRateMgr.m_pSocket != nullptr )
      {
        v4 = _Plat_FloatTime();
        *(float *)&nBytesSent = v4;
        if ( v4 - transmitRateMgr.m_flLastBroadcastTime >= 0.3333333333333333 )
        {
          m_UniqueID = transmitRateMgr.m_UniqueID;
          v10 = *(_DWORD *)s_cTransmitRateMgrPacket;
          v11 = *(_WORD *)&s_cTransmitRateMgrPacket[4];
          LODWORD(transmitRateMgr.m_flLastBroadcastTime) = nBytesSent;
          transmitRateMgr.m_pSocket->Broadcast(this: transmitRateMgr.m_pSocket, a2: &v10, a3: 10, a4: 21146u);
        }
      }
      *(float *)&nBytesSent = COERCE_FLOAT(&timer);
      timer.m_Duration.m_Int64 = __rdtsc();
      CMasterMulticastThread::Thread_SeekToNextActiveChunk(this);
      if ( this->m_nTotalActiveChunks != 0 )
      {
        *(float *)&nBytesSent = 0.0;
        CMasterMulticastThread::Thread_SendFileChunk_Multicast(this, pnBytesSent: (unsigned int *)&nBytesSent);
        g_nMulticastBytesSent += nBytesSent;
        this->m_iCurActiveChunk = this->m_Files.m_Memory.m_pMemory[this->m_iCurFile].m_Element->m_ActiveChunks.m_Memory.m_pMemory[this->m_iCurActiveChunk].m_Next;
        v2(lpCriticalSection: &this->m_CS);
        HIDWORD(v15) = &v13;
        v13 = __rdtsc();
        timer.m_Duration.m_Int64 = v13 - timer.m_Duration.m_Int64;
        HIDWORD(v7) = HIDWORD(_g_ClockSpeed);
        LODWORD(v7) = _g_ClockSpeed;
        v5 = 1000000 * timer.m_Duration.m_Int64 / v7;
        v15 = (__int64)((double)(unsigned int)(nBytesSent + 32) * transmitRateMgr.m_nMicrosecondsPerByte);
        if ( v5 < (unsigned int)v15 )
          CRateLimiter::NoteExcessTimeTaken(this: &rateLimiter, excessTimeInMicroseconds: v15 - v5);
        v2 = LeaveCriticalSection;
        v3 = msToWait;
      }
      else
      {
LABEL_4:
        v2(lpCriticalSection: &this->m_CS);
        v3 = 50;
      }
    }
    while ( WaitForSingleObject(hHandle: this->m_hTermEvent, dwMilliseconds: v3) != 0 );
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&transmitRateMgr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002E590
// Name: public: int CMasterMulticastThread::FindOrAddFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::FindOrAddFile(
        CMasterMulticastThread *this,
        const char *pFilename,
        char *pPathID)
{
  int result; // eax
  void *v5; // esi
  CMasterMulticastThread::CMulticastFile *v6; // eax
  int v7; // ebx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v10; // eax
  int v11; // esi
  bool bFileAlreadyExisted; // [esp+10h] [ebp-8h]
  CMasterMulticastThread::CMulticastFile *pFile; // [esp+14h] [ebp-4h]

  pFile = nullptr;
  bFileAlreadyExisted = false;
  result = CMasterMulticastThread::FindFile(this, pName: pFilename, pPathID);
  if ( result != -1 )
  {
    pFile = this->m_Files.m_Memory.m_pMemory[result].m_Element;
    if ( pFile->m_bDataLoaded )
      return result;
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
    bFileAlreadyExisted = true;
  }
  v5 = this->m_pPassThru->Open(this: this->m_pPassThru, a2: pFilename, a3: "rb", a4: *pPathID != 0 ? pPathID : nullptr);
  if ( v5 != nullptr )
  {
    if ( !bFileAlreadyExisted )
    {
      v6 = (CMasterMulticastThread::CMulticastFile *)operator new(size: 0xC8u);
      if ( v6 != nullptr )
        pFile = CMasterMulticastThread::CMulticastFile::CMulticastFile(this: v6);
      else
        pFile = nullptr;
    }
    v7 = this->m_pPassThru->Size_2(this: this->m_pPassThru, a2: v5);
    pFile->m_UncompressedData.m_Size = 0;
    if ( v7 != 0 )
    {
      m_nAllocationCount = pFile->m_UncompressedData.m_Memory.m_nAllocationCount;
      if ( v7 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&pFile->m_UncompressedData,
          num: v7 - m_nAllocationCount);
      pFile->m_UncompressedData.m_Size += v7;
      m_pMemory = pFile->m_UncompressedData.m_Memory.m_pMemory;
      v10 = pFile->m_UncompressedData.m_Size - v7;
      pFile->m_UncompressedData.m_pElements = m_pMemory;
      if ( v10 > 0 && v7 > 0 )
        _V_memmove(dest: &m_pMemory[v7], src: m_pMemory, count: v10);
    }
    this->m_pPassThru->Read(
      this: this->m_pPassThru,
      a2: pFile->m_UncompressedData.m_Memory.m_pMemory,
      a3: pFile->m_UncompressedData.m_Size,
      a4: v5);
    this->m_pPassThru->Close(this: this->m_pPassThru, a2: v5);
    v11 = CMasterMulticastThread::FinishFileSetup(
            this,
            pFile,
            pFilename,
            (CMasterMulticastThread::CChunkInfo *)pPathID,
            bFileAlreadyExisted);
    if ( bFileAlreadyExisted )
      LeaveCriticalSection(lpCriticalSection: &this->m_CS);
    return v11;
  }
  else
  {
    if ( bFileAlreadyExisted )
      LeaveCriticalSection(lpCriticalSection: &this->m_CS);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E6F0
// Name: public: virtual void __near * CMasterVMPIFileSystem::OpenEx(char const __near *,char const __near *,unsigned int,char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMasterVMPIFileSystem::OpenEx(
        CMasterVMPIFileSystem *this,
        const char *pFileName,
        const char *pOptions,
        unsigned int flags,
        const char *pathID,
        char **ppszResolvedFilename)
{
  return this->Open(this: &this->IBaseFileSystem, a2: pFileName, a3: pOptions, a4: pathID);
}

//------------------------------------------------------------------------------
// Address: 0x1002E710
// Name: public: virtual void __near * CMasterVMPIFileSystem::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVMPIFile_Memory *__thiscall CMasterVMPIFileSystem::Open(
        CMasterVMPIFileSystem *this,
        const char *pFilename,
        char *pOptions,
        char *pPathID)
{
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  CVMPIFile_Memory *result; // eax
  IBaseFileSystem_vtbl *v10; // ecx
  IBaseFileSystem_vtbl *v11; // ecx
  char *v12; // eax
  int v13; // eax
  int v14; // esi
  CVMPIFile_Memory *v15; // eax
  CVMPIFile_Memory *v16; // edi
  int v17; // ebx
  const char *v18; // esi
  int v19; // eax

  if ( g_bDisableFileAccess )
    _Error(a1: "Open( %s, %s ) - file access has been disabled.", pFilename, pOptions);
  strchr(string: (unsigned __int8 *)pOptions, chr: 0x77u);
  if ( v5 != 0
    || (strchr(string: (unsigned __int8 *)pOptions, chr: 0x61u), v6 != 0)
    || (strchr(string: (unsigned __int8 *)pOptions, chr: 0x2Bu), v7 != 0) )
  {
    v8 = (*((int (__thiscall **)(IBaseFileSystem_vtbl *, const char *, char *, char *))this->Read + 2))(
           a1: this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable,
           a2: pFilename,
           a3: pOptions,
           a4: pPathID);
    if ( v8 == 0 )
      return nullptr;
    result = (CVMPIFile_Memory *)operator new(size: 0xCu);
    if ( result != nullptr )
    {
      result->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_PassThru::`vftable';
      v10 = this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable;
      result->m_DataLen = v8;
      result->m_pData = (const char *)v10;
    }
    else
    {
      v11 = this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable;
      MEMORY[8] = v8;
      MEMORY[4] = v11;
      return nullptr;
    }
  }
  else
  {
    v12 = pPathID;
    if ( pPathID == nullptr )
      v12 = (char *)defaultValue;
    v13 = CMasterMulticastThread::FindOrAddFile(
            this: (CMasterMulticastThread *)&this->m_MulticastIP.port,
            pFilename,
            pPathID: v12);
    if ( v13 == -1 )
      return nullptr;
    v14 = *(_DWORD *)(*(_DWORD *)&this->m_MulticastIP.port + 12 * v13);
    v15 = (CVMPIFile_Memory *)operator new(size: 0x14u);
    if ( v15 != nullptr )
    {
      v15->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_Memory::`vftable';
      v16 = v15;
    }
    else
    {
      v16 = nullptr;
    }
    v17 = *(_DWORD *)(v14 + 68);
    v18 = *(const char **)(v14 + 56);
    strchr(string: (unsigned __int8 *)pOptions, chr: 0x74u);
    CVMPIFile_Memory::Init(this: v16, pData: v18, len: v17, chMode: v19 != 0 ? 116 : 98);
    return v16;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E830
// Name: private: static void CMasterVMPIFileSystem::OnClientDisconnect(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMasterVMPIFileSystem::OnClientDisconnect(int procID)
{
  CMasterMulticastThread::OnClientDisconnect(
    this: &CMasterVMPIFileSystem::s_pMasterVMPIFileSystem->m_MasterThread,
    clientID: procID,
    bGrabCriticalSection: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002E850
// Name: public: virtual void CMasterVMPIFileSystem::CreateVirtualFile(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterVMPIFileSystem::CreateVirtualFile(
        CMasterVMPIFileSystem *this,
        const char *pFilename,
        const char *pData,
        unsigned int fileLength)
{
  CMasterMulticastThread::CreateVirtualFile(this: &this->m_MasterThread, pFilename, pData, fileLength);
}

//------------------------------------------------------------------------------
// Address: 0x1002E860
// Name: public: int CMasterMulticastThread::AddFileRequest(char const __near *,char const __near *,int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterMulticastThread::AddFileRequest(
        CMasterMulticastThread *this,
        const char *pFilename,
        char *pPathID,
        int clientID,
        bool *bZeroLength)
{
  int result; // eax
  CMasterMulticastThread::CMulticastFile *m_Element; // ebx
  CMasterMulticastThread::CClientFileInfo *v8; // eax
  CMasterMulticastThread::CClientFileInfo *v9; // edi
  int v10; // ecx
  double v11; // st7
  int v12; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 *m_pMemory; // edx
  int v15; // ecx
  CMasterMulticastThread::CChunkInfo *v16; // esi
  bool v17; // zf
  unsigned __int16 v18; // ax
  int v19; // eax
  int j; // esi
  int iFile; // [esp+4h] [ebp-14h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+8h] [ebp-10h]
  CMasterMulticastThread::CChunkInfo *src; // [esp+Ch] [ebp-Ch] BYREF
  CMasterMulticastThread *v24; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  const char *pFilenamea; // [esp+20h] [ebp+8h]
  const char *pFilenameb; // [esp+20h] [ebp+8h]

  v24 = this;
  result = CMasterMulticastThread::FindOrAddFile(this, pFilename, pPathID);
  iFile = result;
  if ( result != -1 )
  {
    m_Element = this->m_Files.m_Memory.m_pMemory[result].m_Element;
    lpCriticalSection = &this->m_CS;
    EnterCriticalSection(lpCriticalSection: &this->m_CS);
    v8 = (CMasterMulticastThread::CClientFileInfo *)operator new(size: 0x30u);
    if ( v8 != nullptr )
    {
      v9 = v8;
      v8->m_ChunksToSend.m_Memory.m_pMemory = nullptr;
      v8->m_ChunksToSend.m_Memory.m_nAllocationCount = 0;
      v8->m_ChunksToSend.m_Memory.m_nGrowSize = 0;
      v8->m_ChunksToSend.m_Size = 0;
      v8->m_ChunksToSend.m_pElements = nullptr;
      pPathID = (char *)v8;
    }
    else
    {
      pPathID = nullptr;
      v9 = nullptr;
    }
    v10 = clientID;
    v9->m_TCP_LastChunkAcked = -1;
    v9->m_TCP_LastChunkSent = -1;
    v9->m_ClientID = v10;
    v11 = _Plat_FloatTime();
    v9->m_flLastAckTime = v11;
    v9->m_flTransmitStartTime = v11;
    v9->m_nTimesFileCycled = 0;
    v9->m_nChunksLeft = m_Element->m_Info.m_nChunks;
    v12 = 8 * ((m_Element->m_Info.m_nChunks + 7) / 8) / 8;
    pFilenamea = (const char *)v12;
    v9->m_ChunksToSend.m_Size = 0;
    if ( v12 != 0 )
    {
      m_nAllocationCount = v9->m_ChunksToSend.m_Memory.m_nAllocationCount;
      if ( v12 > m_nAllocationCount )
      {
        CUtlMemory<char,int>::Grow(this: &v9->m_ChunksToSend.m_Memory, num: v12 - m_nAllocationCount);
        v12 = (int)pFilenamea;
      }
      v9->m_ChunksToSend.m_Size += v12;
      m_pMemory = v9->m_ChunksToSend.m_Memory.m_pMemory;
      v15 = v9->m_ChunksToSend.m_Size - v12;
      v9->m_ChunksToSend.m_pElements = m_pMemory;
      if ( v15 > 0 && v12 > 0 )
        _V_memmove(dest: &m_pMemory[v12], src: m_pMemory, count: v15);
    }
    memset(dst: v9->m_ChunksToSend.m_Memory.m_pMemory, value: 0xFFu, count: v9->m_ChunksToSend.m_Size);
    CUtlLinkedList<CMasterMulticastThread::CClientFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CClientFileInfo *,int>,int>>::AddToTail(
      this: &m_Element->m_Clients,
      src: (CMasterMulticastThread::CClientFileInfo **)&pPathID);
    i = 0;
    if ( m_Element->m_Chunks.m_Size > 0 )
    {
      pFilenameb = nullptr;
      do
      {
        v16 = (CMasterMulticastThread::CChunkInfo *)&pFilenameb[(unsigned int)m_Element->m_Chunks.m_Memory.m_pMemory];
        v17 = v16->m_RefCount == 0;
        src = v16;
        if ( v17 )
        {
          ++v24->m_nTotalActiveChunks;
          clientID = v16->m_iActiveChunksIndex;
          CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
            this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&m_Element->m_ActiveChunks,
            elem: clientID);
          m_Element->m_ActiveChunks.m_Memory.m_pMemory[clientID].m_Next = m_Element->m_ActiveChunks.m_FirstFree;
          m_Element->m_ActiveChunks.m_FirstFree = clientID;
          v18 = CUtlLinkedList<CMasterMulticastThread::CChunkInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CChunkInfo *,int>,int>>::AddToHead(
                  this: &m_Element->m_ActiveChunks,
                  &src);
          v9 = (CMasterMulticastThread::CClientFileInfo *)pPathID;
          v16->m_iActiveChunksIndex = v18;
        }
        v19 = i;
        ++v16->m_RefCount;
        pFilenameb += 6;
        i = v19 + 1;
      }
      while ( v19 + 1 < m_Element->m_Chunks.m_Size );
    }
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
    {
      for ( j = 16; j != 0; --j )
        CMasterMulticastThread::TCP_SendNextChunk(this: v24, pFile: m_Element, pClient: v9);
    }
    LeaveCriticalSection(lpCriticalSection);
    *bZeroLength = m_Element->m_Info.m_UncompressedSize == 0;
    return iFile;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002EA30
// Name: private: static unsigned long CMasterMulticastThread::StaticMulticastThread(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CMasterMulticastThread::StaticMulticastThread(CMasterMulticastThread *pParameter)
{
  return CMasterMulticastThread::MulticastThread(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x1002EA90
// Name: public: virtual bool CMasterVMPIFileSystem::HandleFileSystemPacket(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterVMPIFileSystem::HandleFileSystemPacket(
        CMasterVMPIFileSystem *this,
        CVMPIFile_Memory *pBuf,
        int iSource,
        int iPacketID)
{
  char *v5; // eax
  int v6; // edx
  int v7; // edx
  unsigned __int16 *v9; // esi
  unsigned __int16 *v10; // edi
  int v11; // eax
  int i; // ebx
  const char *v13; // esi
  unsigned int v14; // kr04_4
  int v15; // edi
  void *pChunks[4]; // [esp+Ch] [ebp-2Ch] BYREF
  int chunkLen[4]; // [esp+1Ch] [ebp-1Ch] BYREF
  int fileID; // [esp+2Ch] [ebp-Ch] BYREF
  int requestID; // [esp+30h] [ebp-8h] BYREF
  CMasterVMPIFileSystem *v20; // [esp+34h] [ebp-4h]

  v5 = (char *)pBuf->__vftable;
  v6 = SBYTE1(pBuf->Close) - 1;
  v20 = this;
  if ( v6 == 0 )
  {
    v13 = v5 + 6;
    requestID = *(_DWORD *)(v5 + 2);
    v14 = strlen(v5 + 6);
    v15 = iSource;
    if ( g_iVMPIVerboseLevel >= 2 )
      _Msg(a1: "Client %d requested '%s'\n", iSource, v13);
    fileID = CMasterMulticastThread::AddFileRequest(
               this: &v20->m_MasterThread,
               pFilename: v13,
               pPathID: (char *)&v13[v14 + 1],
               clientID: v15,
               bZeroLength: (bool *)&iSource + 3);
    pChunks[0] = &pBuf;
    pChunks[3] = (char *)&iSource + 3;
    pChunks[1] = &requestID;
    pChunks[2] = &fileID;
    LOWORD(pBuf) = 512;
    chunkLen[0] = 2;
    chunkLen[1] = 4;
    chunkLen[2] = 4;
    chunkLen[3] = 1;
    VMPI_SendChunks((const void *const *)pChunks, pChunkLengths: chunkLen, nChunks: 4, iDest: v15, fVMPISendFlags: 0);
    return 1;
  }
  v7 = v6 - 2;
  if ( v7 != 0 )
  {
    if ( v7 != 1 )
      return 0;
    CMasterMulticastThread::OnFileReceived(
      this: &this->m_MasterThread,
      fileID: *((unsigned __int16 *)v5 + 1),
      clientID: iSource);
    return 1;
  }
  v9 = (unsigned __int16 *)(v5 + 2);
  v10 = (unsigned __int16 *)(v5 + 4);
  v11 = (int)(ConCommandBase::GetName(this: pBuf) - 2) / 4;
  if ( v11 <= 0 )
    return 1;
  pBuf = (CVMPIFile_Memory *)&this->m_MasterThread;
  for ( i = v11; i != 0; --i )
  {
    CMasterMulticastThread::OnChunkReceived(
      this: (CMasterMulticastThread *)pBuf,
      fileID: *v9,
      clientID: iSource,
      iChunk: *v10);
    v9 += 2;
    v10 += 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002EBD0
// Name: public: bool CMasterMulticastThread::Init(class IBaseFileSystem __near *,unsigned short,class CIPAddr const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterMulticastThread::Init(
        CMasterMulticastThread *this,
        IBaseFileSystem *pPassThru,
        int localPort,
        const CIPAddr *pAddr,
        unsigned int maxMemoryUsage)
{
  SOCKET v6; // eax
  const CIPAddr *v8; // edi
  HANDLE v9; // eax
  SOCKET m_Socket; // [esp-14h] [ebp-34h]
  sockaddr_in addr; // [esp+8h] [ebp-18h] BYREF
  CIPAddr localAddr; // [esp+18h] [ebp-8h] BYREF

  CMasterMulticastThread::Term(this);
  this->m_nMaxMemoryUsage = maxMemoryUsage;
  this->m_nCurMemoryUsage = 0;
  if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
  {
    this->m_Socket = -1;
  }
  else
  {
    v6 = socket(af: 2, type: 2, protocol: 0);
    this->m_Socket = v6;
    if ( v6 == -1 )
    {
      _Warning(a1: "CMasterMulticastThread::Init - socket() failed\n");
      return 0;
    }
    CIPAddr::CIPAddr(this: &localAddr, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: (unsigned __int16)localPort);
    IPAddrToSockAddr(pIn: &localAddr, pOut: &addr);
    if ( bind(s: this->m_Socket, name: (const struct sockaddr *)&addr, namelen: 16) != 0 )
    {
      CMasterMulticastThread::Term(this);
      _Warning(
        a1: "CMasterMulticastThread::Init - bind( %d.%d.%d.%d:%d ) failed\n",
        pAddr->ip[0],
        pAddr->ip[1],
        pAddr->ip[2],
        pAddr->ip[3],
        pAddr->port);
      return 0;
    }
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
    {
      m_Socket = this->m_Socket;
      localPort = 1;
      if ( setsockopt(s: m_Socket, level: 0xFFFF, optname: 32, optval: (const char *)&localPort, optlen: 1) == -1 )
      {
        CMasterMulticastThread::Term(this);
        _Warning(a1: "CMasterMulticastThread::Init - setsockopt() failed to set broadcast mode\n");
        return 0;
      }
    }
    v8 = pAddr;
    IPAddrToSockAddr(pIn: pAddr, pOut: &this->m_MulticastAddr);
    maxMemoryUsage = 0;
    v9 = CreateThread(
           lpThreadAttributes: nullptr,
           dwStackSize: 0,
           lpStartAddress: (LPTHREAD_START_ROUTINE)CMasterMulticastThread::StaticMulticastThread,
           lpParameter: this,
           dwCreationFlags: 0,
           lpThreadId: &maxMemoryUsage);
    this->m_hThread = v9;
    if ( v9 == nullptr )
    {
      CMasterMulticastThread::Term(this);
      _Warning(
        a1: "CMasterMulticastThread::Init - CreateThread failed\n",
        v8->ip[0],
        v8->ip[1],
        v8->ip[2],
        v8->ip[3],
        v8->port);
      return 0;
    }
    SetThreadPriority(hThread: v9, nPriority: -2);
  }
  this->m_hMainThread = GetCurrentThread();
  this->m_pPassThru = pPassThru;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002ED80
// Name: public: bool CMasterVMPIFileSystem::Init(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __thiscall CMasterVMPIFileSystem::Init(
        CMasterVMPIFileSystem *this,
        unsigned int maxMemoryUsage,
        IFileSystem *pPassThru)
{
  IFileSystem *v3; // edi
  IUniformRandomStream *v5; // ecx
  int v6; // ebx
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  IUniformRandomStream *v9; // ecx
  IUniformRandomStream *v10; // ecx
  IBaseFileSystem *v11; // eax
  char result; // al
  unsigned __int64 v13; // [esp-20h] [ebp-38h]
  CCycleCount cnt; // [esp+Ch] [ebp-Ch] BYREF
  CCycleCount *p_cnt; // [esp+14h] [ebp-4h]

  v3 = pPassThru;
  this->InitPassThru_2(this, a2: pPassThru, a3: false);
  this->m_pMasterVMPIFileSystemPassThru = v3;
  p_cnt = &cnt;
  cnt.m_Int64 = __rdtsc();
  HIDWORD(v13) = HIDWORD(_g_ClockSpeed);
  LODWORD(v13) = _g_ClockSpeed;
  ((void (__cdecl *)(_DWORD))_RandomSeed)(a1: 1000000 * cnt.m_Int64 / v13);
  v6 = (unsigned __int16)_RandomInt(this: v5, a2: 22000, a3: 25000);
  if ( VMPI_GetRunMode() != VMPI_RUN_NETWORKED )
  {
    CIPAddr::Init(this: &this->m_MulticastIP, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: 0);
  }
  else if ( VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_MULTICAST )
  {
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
      CIPAddr::Init(this: &this->m_MulticastIP, ip0: 255, ip1: 255, ip2: 255, ip3: 255, ipPort: v6);
  }
  else
  {
    this->m_MulticastIP.port = v6;
    this->m_MulticastIP.ip[0] = _RandomInt(this: v7, a2: 225, a3: 238);
    this->m_MulticastIP.ip[1] = _RandomInt(this: v8, a2: 0, a3: 255);
    this->m_MulticastIP.ip[2] = _RandomInt(this: v9, a2: 0, a3: 255);
    this->m_MulticastIP.ip[3] = _RandomInt(this: v10, a2: 3, a3: 255);
  }
  if ( pPassThru != nullptr )
    v11 = &pPassThru->IBaseFileSystem;
  else
    v11 = nullptr;
  result = CMasterMulticastThread::Init(
             this: &this->m_MasterThread,
             pPassThru: v11,
             localPort: 23412,
             pAddr: &this->m_MulticastIP,
             maxMemoryUsage);
  if ( result != 0 )
  {
    LOWORD(pPassThru) = 1280;
    VMPI_Send2Chunks(
      pChunk1: &pPassThru,
      chunk1Len: 2,
      pChunk2: &this->m_MulticastIP,
      chunk2Len: 6,
      iDest: -3,
      fVMPISendFlags: 0);
    VMPI_AddDisconnectHandler(handler: (void (__cdecl *)(int, const char *))CMasterVMPIFileSystem::OnClientDisconnect);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002EEF0
// Name: class CBaseVMPIFileSystem __near * CreateMasterVMPIFileSystem(int,class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CMasterVMPIFileSystem *__cdecl CreateMasterVMPIFileSystem(unsigned int maxMemoryUsage, IFileSystem *pPassThru)
{
  CMasterVMPIFileSystem *v2; // eax
  CMasterVMPIFileSystem *v3; // esi

  v2 = (CMasterVMPIFileSystem *)operator new(size: 0xBCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&IBaseFileSystem::`vftable';
    v2->m_pBaseFileSystemPassThru = nullptr;
    v2->m_pFileSystemPassThru = nullptr;
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CMasterVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
    v2->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
    CIPAddr::CIPAddr(this: &v2->m_MulticastIP);
    v3->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CMasterVMPIFileSystem_vtbl *)&CMasterVMPIFileSystem::`vftable'{for `IAppSystem'};
    v3->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CMasterVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
    CMasterMulticastThread::CMasterMulticastThread(this: &v3->m_MasterThread);
    CMasterVMPIFileSystem::s_pMasterVMPIFileSystem = v3;
  }
  else
  {
    v3 = nullptr;
  }
  g_pBaseVMPIFileSystem = v3;
  if ( CMasterVMPIFileSystem::Init(this: v3, maxMemoryUsage, pPassThru) != 0 )
    return v3;
  if ( v3 != nullptr )
    ((void (__thiscall *)(CMasterVMPIFileSystem *, int))v3->dtr_CBaseVMPIFileSystem)(a1: v3, a2: 1);
  g_pBaseVMPIFileSystem = nullptr;
  return nullptr;
}

} // namespace vvis_dll
