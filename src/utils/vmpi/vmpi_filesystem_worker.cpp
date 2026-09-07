// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_filesystem_worker.cpp
// Functions: 21
// ============================================================

#include "utils\vmpi\vmpi_filesystem_worker.h"

//------------------------------------------------------------------------------
// Address: 0x10021880
// Name: __heap_term
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall _heap_term(CFileSystemPassThru *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1002D360
// Name: ZLibDecompress
// Source: json
//------------------------------------------------------------------------------
bool __usercall ZLibDecompress@<al>(
        unsigned int inputLen@<eax>,
        unsigned __int8 *pOut@<edi>,
        unsigned __int8 *pInput,
        int outLen)
{
  unsigned __int8 *v6; // esi
  unsigned int v7; // eax
  z_stream_s decompressStream; // [esp+8h] [ebp-38h] BYREF

  if ( inputLen == 0 )
    return true;
  memset(dst: (int)&decompressStream, value: nullptr, count: sizeof(decompressStream));
  if ( inflateInit_(a1: &decompressStream, a2: "1.1.3", a3: 56) == 0 )
  {
    decompressStream.avail_in = inputLen;
    decompressStream.next_in = pInput;
    v6 = pOut;
    do
    {
      decompressStream.total_out = 0;
      decompressStream.next_out = v6;
      decompressStream.avail_out = outLen + pOut - v6;
      v7 = inflate(a1: &decompressStream, a2: 0);
      if ( v7 > 1 )
        break;
      v6 += decompressStream.total_out;
      if ( v7 == 1 )
        return v6 - pOut == outLen;
    }
    while ( decompressStream.avail_in != 0 );
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1002D400
// Name: public: void CWorkerMulticastListener::FlushAckChunks(unsigned short (__near * const)[2],int __near &,unsigned long __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerMulticastListener::FlushAckChunks(
        CWorkerMulticastListener *this,
        unsigned __int16 (*chunksToAck)[2],
        int *nChunksToAck,
        unsigned int *lastAckTime)
{
  int *v4; // esi
  int v5; // eax
  void *pChunks[2]; // [esp+4h] [ebp-10h] BYREF
  int chunkLengths[2]; // [esp+Ch] [ebp-8h] BYREF

  v4 = nChunksToAck;
  v5 = *nChunksToAck;
  if ( *nChunksToAck != 0 )
  {
    pChunks[0] = &nChunksToAck;
    pChunks[1] = chunksToAck;
    LOWORD(nChunksToAck) = 768;
    chunkLengths[0] = 2;
    chunkLengths[1] = 4 * v5;
    VMPI_SendChunks((const void *const *)pChunks, pChunkLengths: chunkLengths, nChunks: 2, iDest: 0, fVMPISendFlags: 0);
    *v4 = 0;
  }
  *lastAckTime = GetTickCount();
}

//------------------------------------------------------------------------------
// Address: 0x1002D460
// Name: public: void CWorkerMulticastListener::AddAckChunk(unsigned short (__near * const)[2],int __near &,unsigned long __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerMulticastListener::AddAckChunk(
        CWorkerMulticastListener *this,
        unsigned __int16 (*chunksToAck)[2],
        int *nChunksToAck,
        unsigned int *lastAckTime,
        unsigned __int16 fileID,
        unsigned __int16 iChunk)
{
  int *v6; // esi
  int v7; // eax
  void *pChunks[2]; // [esp+8h] [ebp-10h] BYREF
  int pChunkLengths[2]; // [esp+10h] [ebp-8h] BYREF

  v6 = nChunksToAck;
  (*chunksToAck)[2 * *nChunksToAck] = fileID;
  (*chunksToAck)[2 * (*v6)++ + 1] = iChunk;
  if ( *v6 == 512 || VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
  {
    v7 = *v6;
    if ( *v6 != 0 )
    {
      pChunks[0] = &nChunksToAck;
      LOWORD(nChunksToAck) = 768;
      pChunks[1] = chunksToAck;
      pChunkLengths[0] = 2;
      pChunkLengths[1] = 4 * v7;
      VMPI_SendChunks((const void *const *)pChunks, pChunkLengths, nChunks: 2, iDest: 0, fVMPISendFlags: 0);
      *v6 = 0;
    }
    *lastAckTime = GetTickCount();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D4F0
// Name: public: void CWorkerMulticastListener::ShowSDKWorkerMsg(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CWorkerMulticastListener::ShowSDKWorkerMsg(CWorkerMulticastListener *this, char *pMsg, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+10h] BYREF

  va_start(params, pMsg);
  if ( !g_bMPIMaster && VMPI_IsSDKMode() )
  {
    V_vsnprintf(pDest, maxLen: 0x1000u, pFormat: pMsg, params);
    _Msg(a1: "%s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D550
// Name: public: virtual enum InitReturnVal_t CWorkerVMPIFileSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerVMPIFileSystem::Init(CWorkerVMPIFileSystem *this)
{
  int v2; // eax
  unsigned __int16 port; // cx
  CIPAddr mcAddr; // [esp+4h] [ebp-8h] BYREF

  CIPAddr::CIPAddr(this: &mcAddr);
  while ( !g_bReceivedMulticastIP )
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
  v2 = *(_DWORD *)g_MulticastIP.ip;
  port = g_MulticastIP.port;
  *(_DWORD *)this->m_Listener.m_MulticastAddr.ip = *(_DWORD *)g_MulticastIP.ip;
  *(_DWORD *)mcAddr.ip = v2;
  mcAddr.port = port;
  this->m_Listener.m_MulticastAddr.port = port;
  this->m_Listener.m_hMainThread = GetCurrentThread();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002D5B0
// Name: public: virtual void CWorkerVMPIFileSystem::CreateVirtualFile(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::CreateVirtualFile(
        CWorkerVMPIFileSystem *this,
        const char *pFilename,
        const char *pData,
        const void *fileLength)
{
  _Error(a1: "CreateVirtualFile not supported in VMPI worker filesystem.");
}

//------------------------------------------------------------------------------
// Address: 0x1002D5C0
// Name: public: virtual long CWorkerVMPIFileSystem::GetFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerVMPIFileSystem::GetFileTime(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        const char *pathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002D5E0
// Name: public: virtual bool CWorkerVMPIFileSystem::IsFileWritable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerVMPIFileSystem::IsFileWritable(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        const char *pPathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1002D600
// Name: public: virtual bool CWorkerVMPIFileSystem::SetFileWritable(char const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerVMPIFileSystem::SetFileWritable(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        bool writable,
        const char *pPathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1002D620
// Name: public: virtual class CSysModule __near * CWorkerVMPIFileSystem::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
HINSTANCE__ *__thiscall CWorkerVMPIFileSystem::LoadModule(
        CWorkerVMPIFileSystem *this,
        char *pFileName,
        const char *pPathID,
        bool bValidatedDllOnly)
{
  return Sys_LoadModule(pModuleName: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1002D640
// Name: public: virtual void CWorkerVMPIFileSystem::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::UnloadModule(CWorkerVMPIFileSystem *this, struct CSysModule *pModule)
{
  Sys_UnloadModule(pModule);
}

//------------------------------------------------------------------------------
// Address: 0x1002D960
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::FindWorkerFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::FindWorkerFile(
        CWorkerMulticastListener *this,
        const char *pFilename,
        const char *pPathID)
{
  int m_Head; // esi
  int v5; // esi
  CWorkerFile *m_Element; // edi

  m_Head = this->m_WorkerFiles.m_Head;
  if ( m_Head == -1 )
    return nullptr;
  while ( 1 )
  {
    v5 = m_Head;
    m_Element = this->m_WorkerFiles.m_Memory.m_pMemory[v5].m_Element;
    if ( _V_stricmp(s1: m_Element->m_Filename.m_Memory.m_pMemory, s2: pFilename) == 0
      && _V_stricmp(s1: m_Element->m_PathID.m_Memory.m_pMemory, s2: pPathID) == 0 )
    {
      break;
    }
    m_Head = this->m_WorkerFiles.m_Memory.m_pMemory[v5].m_Next;
    if ( m_Head == -1 )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x1002DCD0
// Name: public: int CWorkerMulticastListener::CheckFileChunkPackets(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerMulticastListener::CheckFileChunkPackets(
        CWorkerMulticastListener *this,
        char *data,
        int dataSize)
{
  CFileChunkPacket *m_Element; // edi
  int m_Head; // esi
  int v6; // esi
  unsigned int m_Len; // [esp-Ch] [ebp-14h]
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( g_FileChunkPackets.m_ElementCount > 0 )
  {
    m_Element = g_FileChunkPackets.m_Memory.m_pMemory[g_FileChunkPackets.m_Head].m_Element;
    m_Head = g_FileChunkPackets.m_Head;
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: &g_FileChunkPackets,
      elem: g_FileChunkPackets.m_Head);
    g_FileChunkPackets.m_Memory.m_pMemory[m_Head].m_Next = g_FileChunkPackets.m_FirstFree;
    g_FileChunkPackets.m_FirstFree = m_Head;
    m_Len = m_Element->m_Len;
    if ( m_Element->m_Len <= dataSize )
    {
      memcpy(dst: (unsigned __int8 *)data, src: (unsigned __int8 *)m_Element->m_Data, count: m_Len);
      v6 = m_Element->m_Len;
    }
    else
    {
      v6 = -1;
      _Warning(a1: "CWorkerMulticastListener::ListenFor: Got a section of data too long (%d bytes).", m_Len);
    }
    free(pMem: m_Element);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return v6;
  }
  else
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DD90
// Name: public: virtual void CWorkerVMPIFileSystem::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::Term(CWorkerVMPIFileSystem *this)
{
  CUtlLinkedList<CWorkerFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Listener.m_WorkerFiles);
}

//------------------------------------------------------------------------------
// Address: 0x1002DE10
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::RequestFileFromServer(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::RequestFileFromServer(
        CWorkerMulticastListener *this,
        const char *pFilename,
        const char *pPathID)
{
  char v3; // bl
  int m_Size; // esi
  int v5; // eax
  CFileResponse *m_pMemory; // ecx
  __int64 v7; // xmm0_8
  CFileResponse *v8; // edx
  CWorkerFile *v10; // eax
  CWorkerFile *v11; // ebx
  unsigned int v12; // eax
  int v13; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v15; // ecx
  signed int v16; // eax
  const char *v17; // ecx
  char *v18; // esi
  char v19; // al
  unsigned int v20; // eax
  int v21; // edi
  int v22; // eax
  unsigned __int8 *v23; // ecx
  signed int v24; // eax
  const char *v25; // ecx
  char *v26; // esi
  char v27; // al
  CWorkerMulticastListener *v28; // esi
  int v29; // eax
  UtlLinkedListElem_t<CWorkerFile *,int> *v30; // edi
  UtlLinkedListElem_t<CWorkerFile *,int> *v31; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<CWorkerFile *,int> *v34; // ecx
  int v35; // edx
  int m_Tail; // edi
  CWorkerFile **p_m_Element; // esi
  bool m_bZeroLength; // dl
  CWorkerMulticastListener *v39; // eax
  const void *pChunks[4]; // [esp+Ch] [ebp-44h] BYREF
  int chunkLengths[4]; // [esp+1Ch] [ebp-34h] BYREF
  CFileResponse response; // [esp+2Ch] [ebp-24h]
  CCriticalSectionLock csLock; // [esp+38h] [ebp-18h] BYREF
  CWorkerMulticastListener *v44; // [esp+40h] [ebp-10h]
  CWorkerFile *pTestFile; // [esp+44h] [ebp-Ch]
  int requestID; // [esp+48h] [ebp-8h] BYREF
  unsigned __int8 packetID[2]; // [esp+4Ch] [ebp-4h] BYREF

  v44 = this;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  requestID = g_RequestID++;
  CCriticalSectionLock::Unlock(this: &csLock);
  pChunks[0] = packetID;
  *(_WORD *)packetID = 256;
  pChunks[1] = &requestID;
  pChunks[2] = pFilename;
  pChunks[3] = pPathID;
  chunkLengths[0] = 2;
  chunkLengths[1] = 4;
  chunkLengths[2] = strlen(pFilename) + 1;
  chunkLengths[3] = strlen(pPathID) + 1;
  VMPI_SendChunks(pChunks, pChunkLengths: chunkLengths, nChunks: 4, iDest: 0, fVMPISendFlags: 0);
  response.m_Response = -1;
  response.m_bZeroLength = true;
  while ( 1 )
  {
    v3 = 0;
    CCriticalSectionLock::Lock(this: &csLock);
    m_Size = g_FileResponses.m_Size;
    v5 = 0;
    if ( g_FileResponses.m_Size > 0 )
    {
      m_pMemory = g_FileResponses.m_Memory.m_pMemory;
      while ( m_pMemory->m_RequestID != requestID )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= g_FileResponses.m_Size )
          goto LABEL_10;
      }
      v7 = *(_QWORD *)&g_FileResponses.m_Memory.m_pMemory[v5].m_RequestID;
      v8 = &g_FileResponses.m_Memory.m_pMemory[v5];
      *(_DWORD *)&response.m_bZeroLength = *(_DWORD *)&v8->m_bZeroLength;
      *(_QWORD *)&response.m_RequestID = v7;
      if ( g_FileResponses.m_Size - v5 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)v8,
          src: (unsigned __int8 *)&v8[1],
          count: 12 * (g_FileResponses.m_Size - v5 - 1));
        m_Size = g_FileResponses.m_Size;
      }
      g_FileResponses.m_Size = m_Size - 1;
      v3 = 1;
    }
LABEL_10:
    CCriticalSectionLock::Unlock(this: &csLock);
    if ( v3 != 0 )
      break;
    if ( GetCurrentThread() == v44->m_hMainThread )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x14);
    else
      Sleep(dwMilliseconds: 0x14u);
  }
  if ( response.m_Response == -1 )
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return nullptr;
  }
  else
  {
    v10 = (CWorkerFile *)operator new(nSize: 0x78u);
    if ( v10 != nullptr )
    {
      LODWORD(v10->m_Timer.m_Duration.m_Int64) = 0;
      HIDWORD(v10->m_Timer.m_Duration.m_Int64) = 0;
      v10->m_Filename.m_Memory.m_pMemory = nullptr;
      v10->m_Filename.m_Memory.m_nAllocationCount = 0;
      v10->m_Filename.m_Memory.m_nGrowSize = 0;
      v10->m_Filename.m_Size = 0;
      v10->m_Filename.m_pElements = nullptr;
      v10->m_PathID.m_Memory.m_pMemory = nullptr;
      v10->m_PathID.m_Memory.m_nAllocationCount = 0;
      v10->m_PathID.m_Memory.m_nGrowSize = 0;
      v10->m_PathID.m_Size = 0;
      v10->m_PathID.m_pElements = nullptr;
      v10->m_CompressedData.m_Memory.m_pMemory = nullptr;
      v10->m_CompressedData.m_Memory.m_nAllocationCount = 0;
      v10->m_CompressedData.m_Memory.m_nGrowSize = 0;
      v10->m_CompressedData.m_Size = 0;
      v10->m_CompressedData.m_pElements = nullptr;
      v10->m_ChunksReceived.m_Memory.m_pMemory = nullptr;
      v10->m_ChunksReceived.m_Memory.m_nAllocationCount = 0;
      v10->m_ChunksReceived.m_Memory.m_nGrowSize = 0;
      v10->m_ChunksReceived.m_Size = 0;
      v10->m_ChunksReceived.m_pElements = nullptr;
      v10->m_UncompressedData.m_Memory.m_pMemory = nullptr;
      v10->m_UncompressedData.m_Memory.m_nAllocationCount = 0;
      v10->m_UncompressedData.m_Memory.m_nGrowSize = 0;
      v10->m_UncompressedData.m_Size = 0;
      v10->m_UncompressedData.m_pElements = nullptr;
      v11 = v10;
      pTestFile = v10;
    }
    else
    {
      v11 = nullptr;
      pTestFile = nullptr;
    }
    v12 = strlen(pFilename);
    v13 = v12 + 1;
    v11->m_Filename.m_Size = 0;
    if ( v12 != -1 )
    {
      m_nAllocationCount = v11->m_Filename.m_Memory.m_nAllocationCount;
      if ( v13 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(this: &v11->m_Filename.m_Memory, num: v13 - m_nAllocationCount);
      v11->m_Filename.m_Size += v13;
      v15 = (unsigned __int8 *)v11->m_Filename.m_Memory.m_pMemory;
      v16 = v11->m_Filename.m_Size - v13;
      v11->m_Filename.m_pElements = (char *)v15;
      if ( v16 > 0 && v13 > 0 )
        _V_memmove(dest: &v15[v13], src: v15, count: v16);
    }
    v17 = pFilename;
    v18 = v11->m_Filename.m_Memory.m_pMemory;
    do
    {
      v19 = *v17;
      *v18++ = *v17++;
    }
    while ( v19 != 0 );
    v20 = strlen(pPathID);
    v21 = v20 + 1;
    v11->m_PathID.m_Size = 0;
    if ( v20 != -1 )
    {
      v22 = v11->m_PathID.m_Memory.m_nAllocationCount;
      if ( v21 > v22 )
        CUtlMemory<bool,int>::Grow(this: &v11->m_PathID.m_Memory, num: v21 - v22);
      v11->m_PathID.m_Size += v21;
      v23 = (unsigned __int8 *)v11->m_PathID.m_Memory.m_pMemory;
      v24 = v11->m_PathID.m_Size - v21;
      v11->m_PathID.m_pElements = (char *)v23;
      if ( v24 > 0 && v21 > 0 )
        _V_memmove(dest: &v23[v21], src: v23, count: v24);
    }
    v25 = pPathID;
    v26 = v11->m_PathID.m_Memory.m_pMemory;
    do
    {
      v27 = *v25;
      *v26++ = *v25++;
    }
    while ( v27 != 0 );
    v11->m_FileID = response.m_Response;
    v11->m_nChunksToReceive = 9999;
    v11->m_Timer.m_Duration.m_Int64 = __rdtsc();
    v28 = v44;
    v29 = CUtlLinkedList<CWorkerFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int>>::AllocInternal(
            this: &v44->m_WorkerFiles,
            multilist: false);
    if ( v29 != -1 )
    {
      if ( v29 >= 0
        && v29 < v28->m_WorkerFiles.m_Memory.m_nAllocationCount
        && v29 <= v28->m_WorkerFiles.m_LastAlloc.index )
      {
        v30 = v28->m_WorkerFiles.m_Memory.m_pMemory;
        v31 = &v30[v29];
        if ( v31->m_Previous != v29 )
        {
          m_Previous = v31->m_Previous;
          if ( m_Previous == -1 )
          {
            v28->m_WorkerFiles.m_Head = v31->m_Next;
          }
          else
          {
            v30[m_Previous].m_Next = v31->m_Next;
            v11 = pTestFile;
          }
          m_Next = v31->m_Next;
          if ( m_Next == -1 )
          {
            v28->m_WorkerFiles.m_Tail = v31->m_Previous;
          }
          else
          {
            v28->m_WorkerFiles.m_Memory.m_pMemory[m_Next].m_Previous = v31->m_Previous;
            v11 = pTestFile;
          }
          v31->m_Next = v29;
          v31->m_Previous = v29;
          --v28->m_WorkerFiles.m_ElementCount;
        }
      }
      v34 = v28->m_WorkerFiles.m_Memory.m_pMemory;
      v35 = v29;
      v34[v35].m_Next = -1;
      m_Tail = v28->m_WorkerFiles.m_Tail;
      v34[v35].m_Previous = m_Tail;
      v28->m_WorkerFiles.m_Tail = v29;
      if ( m_Tail == -1 )
        v28->m_WorkerFiles.m_Head = v29;
      else
        v28->m_WorkerFiles.m_Memory.m_pMemory[m_Tail].m_Next = v29;
      ++v28->m_WorkerFiles.m_ElementCount;
      p_m_Element = &v28->m_WorkerFiles.m_Memory.m_pMemory[v35].m_Element;
      if ( p_m_Element != nullptr )
        *p_m_Element = v11;
    }
    m_bZeroLength = response.m_bZeroLength;
    v39 = v44;
    v11->m_bGotCompressedSize = false;
    v11->m_bZeroLength = m_bZeroLength;
    ++v39->m_nUnfinishedFiles;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E1B0
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::ListenFor(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::ListenFor(
        CWorkerMulticastListener *this,
        char *pFilename,
        char *pPathID)
{
  const char *v3; // ebx
  CWorkerMulticastListener *v4; // esi
  CWorkerFile *result; // eax
  unsigned int v6; // edi
  unsigned int v7; // eax
  const CIPAddr *v8; // eax
  int v9; // eax
  int m_Head; // eax
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // esi
  CWorkerFile *m_Element; // esi
  int v13; // edx
  int v14; // ebx
  unsigned __int8 *v15; // edx
  int v16; // edx
  int v17; // ecx
  int v18; // edi
  unsigned int v19; // ecx
  CWorkerFile *v20; // eax
  CWorkerMulticastListener *v21; // edi
  long double Seconds; // st7
  unsigned int m_Size; // [esp+8h] [ebp-4E94h]
  char data[4]; // [esp+18h] [ebp-4E84h] BYREF
  int size; // [esp+1Ch] [ebp-4E80h]
  unsigned __int16 v26; // [esp+20h] [ebp-4E7Ch]
  unsigned __int16 v27; // [esp+22h] [ebp-4E7Ah]
  int v28; // [esp+24h] [ebp-4E78h]
  char v29[17392]; // [esp+28h] [ebp-4E74h] BYREF
  unsigned __int16 chunksToAck[2]; // [esp+4418h] [ebp-A84h] BYREF
  char pStr[512]; // [esp+4C18h] [ebp-284h] BYREF
  char pDest[62]; // [esp+4E18h] [ebp-84h] BYREF
  CIPAddr v33; // [esp+4E56h] [ebp-46h] BYREF
  CIPAddr v34; // [esp+4E5Ch] [ebp-40h] BYREF
  int v35; // [esp+4E64h] [ebp-38h]
  unsigned __int8 *src; // [esp+4E6Ch] [ebp-30h]
  int v37; // [esp+4E70h] [ebp-2Ch]
  int v38; // [esp+4E74h] [ebp-28h]
  char *v39; // [esp+4E78h] [ebp-24h]
  unsigned __int64 v40; // [esp+4E7Ch] [ebp-20h] BYREF
  unsigned __int64 *v41; // [esp+4E84h] [ebp-18h]
  unsigned int count; // [esp+4E88h] [ebp-14h]
  CWorkerFile *WorkerFile; // [esp+4E8Ch] [ebp-10h]
  int nChunksToAck; // [esp+4E90h] [ebp-Ch] BYREF
  CWorkerMulticastListener *v45; // [esp+4E94h] [ebp-8h]
  unsigned int lastAckTime; // [esp+4E98h] [ebp-4h] BYREF
  ISocket *pPathIDa; // [esp+4EA8h] [ebp+Ch]

  v3 = pFilename;
  v4 = this;
  v45 = this;
  WorkerFile = CWorkerMulticastListener::FindWorkerFile(this, pFilename, pPathID);
  if ( WorkerFile == nullptr )
  {
    result = CWorkerMulticastListener::RequestFileFromServer(this: v4, pFilename, pPathID);
    WorkerFile = result;
    if ( result == nullptr )
      return nullptr;
    if ( result->m_bZeroLength )
    {
      --v4->m_nUnfinishedFiles;
      return result;
    }
  }
  if ( _V_strlen(str: pFilename) <= 0x39 )
  {
    V_strncpy(pDest, pSrc: pFilename, maxLen: 58);
  }
  else
  {
    V_strncpy(pDest, pSrc: "[...]", maxLen: 58);
    v6 = _V_strlen(str: pFilename);
    v7 = _V_strlen(str: pDest);
    V_strncat(pDest, pSrc: &pFilename[v7 - 57 + v6], destBufferSize: 0x3Au, max_chars_to_copy: -1);
  }
  CWorkerMulticastListener::ShowSDKWorkerMsg(this: v4, pMsg: "\rRecv %s (0%%)  ", pDest);
  v37 = VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_TCP ? 1024 : 0x4000;
  pPathIDa = nullptr;
  if ( VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_MULTICAST )
  {
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
    {
      pPathIDa = CreateIPSocket();
      if ( !pPathIDa->BindToAny(this: pPathIDa, a2: v4->m_MulticastAddr.port) )
      {
        pPathIDa->Release(this: pPathIDa);
        pPathIDa = nullptr;
      }
    }
  }
  else
  {
    v8 = CIPAddr::CIPAddr(this: &v33);
    pPathIDa = CreateMulticastListenSocket(addr: &v4->m_MulticastAddr, localInterface: v8);
    if ( pPathIDa == nullptr )
    {
      IP_GetLastErrorString(pStr, maxLen: 512);
      _Warning(
        a1: "CreateMulticastListenSocket (%d.%d.%d.%d:%d) failed\n%s\n",
        v4->m_MulticastAddr.ip[0],
        v4->m_MulticastAddr.ip[1],
        v4->m_MulticastAddr.ip[2],
        v4->m_MulticastAddr.ip[3],
        v4->m_MulticastAddr.port,
        pStr);
      return nullptr;
    }
  }
  nChunksToAck = 0;
  lastAckTime = GetTickCount();
  if ( v4->m_nUnfinishedFiles <= 0 )
  {
LABEL_54:
    CWorkerMulticastListener::FlushAckChunks(
      this: v4,
      (unsigned __int16 (*)[2])chunksToAck,
      &nChunksToAck,
      &lastAckTime);
    if ( pPathIDa != nullptr )
      pPathIDa->Release(this: pPathIDa);
    return WorkerFile;
  }
  while ( 1 )
  {
    if ( pPathIDa != nullptr )
    {
      CIPAddr::CIPAddr(this: &v34);
      v9 = pPathIDa->RecvFrom(this: pPathIDa, a2: data, a3: 17408, a4: &v34);
    }
    else
    {
      v9 = CWorkerMulticastListener::CheckFileChunkPackets(this: v4, data, dataSize: 17408);
    }
    if ( v9 != -1 )
      break;
    Sleep(dwMilliseconds: 0);
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xA);
LABEL_53:
    if ( v4->m_nUnfinishedFiles <= 0 )
      goto LABEL_54;
  }
  g_nMulticastBytesReceived += v9;
  src = (unsigned __int8 *)&v29[strlen(v3) + 1];
  v39 = &data[v9 - (_DWORD)src];
  if ( (int)v39 < 0 )
  {
    _Warning(a1: "CWorkerMulticastListener::ListenFor: invalid packet received on multicast group\n");
    goto LABEL_53;
  }
  if ( v26 != WorkerFile->m_FileID )
    goto LABEL_53;
  m_Head = v4->m_WorkerFiles.m_Head;
  if ( m_Head == -1 )
  {
LABEL_28:
    m_Element = nullptr;
    goto LABEL_30;
  }
  m_pMemory = v4->m_WorkerFiles.m_Memory.m_pMemory;
  while ( m_pMemory[m_Head].m_Element->m_FileID != v26 )
  {
    m_Head = m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      goto LABEL_28;
  }
  m_Element = m_pMemory[m_Head].m_Element;
  if ( m_Element == nullptr )
LABEL_30:
    _Error(a1: "FindWorkerFile( %s ) failed\n", v29);
  if ( !m_Element->m_bGotCompressedSize )
  {
    m_Element->m_bGotCompressedSize = true;
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_CompressedData,
      size: *(int *)data);
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_UncompressedData,
      size);
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: &m_Element->m_ChunksReceived,
      size: 8 * ((v27 + 7) / 8) / 8);
    v13 = (int)m_Element->m_ChunksReceived.m_Memory.m_pMemory;
    m_Size = m_Element->m_ChunksReceived.m_Size;
    m_Element->m_nChunksToReceive = v27;
    memset(dst: v13, value: nullptr, count: m_Size);
  }
  v14 = v28;
  if ( v28 < 0 || v28 >= v27 )
    _Error(a1: "ListenFor(): invalid chunk index (%d) for file '%s'\n", v28, v29);
  v15 = m_Element->m_ChunksReceived.m_Memory.m_pMemory;
  count = v14;
  v38 = v14 >> 3;
  v35 = v14 & 7;
  if ( ((unsigned __int8)(1 << (v14 & 7)) & v15[v14 >> 3]) != 0 )
    goto LABEL_49;
  v16 = *(_DWORD *)data;
  if ( size != m_Element->m_UncompressedData.m_Size || *(_DWORD *)data != m_Element->m_CompressedData.m_Size )
  {
    _Error(
      a1: "ListenFor(): invalid compressed or uncompressed size.\n"
      "pInfo = '%s', pTestFile = '%s'\n"
      "Compressed   (pInfo = %d, pTestFile = %d)\n"
      "Uncompressed (pInfo = %d, pTestFile = %d)\n",
      v29,
      m_Element->m_Filename.m_Memory.m_pMemory,
      *(_DWORD *)data,
      m_Element->m_CompressedData.m_Size,
      size,
      m_Element->m_UncompressedData.m_Size);
    v16 = *(_DWORD *)data;
  }
  v17 = m_Element->m_CompressedData.m_Size;
  v18 = v37 * v14;
  if ( v37 * v14 + v37 < v17 )
    v17 = v37 * v14 + v37;
  v19 = v17 - v18;
  count = v19;
  if ( (char *)v19 != v39 )
    _Error(
      a1: "ListenFor(): invalid payload length for '%s' (%d should be %d)\n"
      "pInfo = '%s', pTestFile = '%s'\n"
      "Chunk %d out of %d. Compressed size: %d\n",
      m_Element->m_Filename.m_Memory.m_pMemory,
      v39,
      v19,
      v29,
      m_Element->m_Filename.m_Memory.m_pMemory,
      v14,
      v27,
      v16);
  memcpy(dst: (unsigned __int8 *)&m_Element->m_CompressedData.m_Memory.m_pMemory[v18], src, count);
  m_Element->m_ChunksReceived.m_Memory.m_pMemory[v38] |= 1 << v35;
  v20 = WorkerFile;
  --m_Element->m_nChunksToReceive;
  v21 = v45;
  if ( m_Element == v20 )
    CWorkerMulticastListener::ShowSDKWorkerMsg(
      this: v45,
      pMsg: "\rRecv %s (%d%%) [chunk %d/%d] ",
      pDest,
      100 - 100 * v20->m_nChunksToReceive / v27,
      v27 - v20->m_nChunksToReceive,
      v27);
  CWorkerMulticastListener::AddAckChunk(
    this: v21,
    (unsigned __int16 (*)[2])chunksToAck,
    &nChunksToAck,
    &lastAckTime,
    fileID: v26,
    iChunk: v14);
  if ( m_Element->m_nChunksToReceive != 0 )
  {
LABEL_49:
    if ( nChunksToAck != 0 && GetTickCount() - lastAckTime > 0x1F4 )
      CWorkerMulticastListener::FlushAckChunks(
        this: v45,
        (unsigned __int16 (*)[2])chunksToAck,
        &nChunksToAck,
        &lastAckTime);
    v4 = v45;
    v3 = pFilename;
    goto LABEL_53;
  }
  CWorkerMulticastListener::FlushAckChunks(this: v21, (unsigned __int16 (*)[2])chunksToAck, &nChunksToAck, &lastAckTime);
  v41 = &v40;
  v40 = __rdtsc();
  m_Element->m_Timer.m_Duration.m_Int64 = v40 - m_Element->m_Timer.m_Duration.m_Int64;
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
    this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_UncompressedData,
    size);
  --v21->m_nUnfinishedFiles;
  if ( ZLibDecompress(
         inputLen: m_Element->m_CompressedData.m_Size,
         pOut: (unsigned __int8 *)m_Element->m_UncompressedData.m_Memory.m_pMemory,
         pInput: (unsigned __int8 *)m_Element->m_CompressedData.m_Memory.m_pMemory,
         outLen: m_Element->m_UncompressedData.m_Size) )
  {
    Seconds = CCycleCount::GetSeconds(this: &m_Element->m_Timer.m_Duration);
    V_snprintf(
      pDest: pStr,
      maxLen: 0x200u,
      pFormat: "Got %s (%dk) in %.2fs",
      pDest,
      (m_Element->m_UncompressedData.m_Size + 511) / 1024,
      (double)Seconds);
    _Msg(a1: "\r%-79s\n", pStr);
    CUtlVector<char,CUtlMemory<char,int>>::Purge(this: &m_Element->m_CompressedData);
    goto LABEL_49;
  }
  if ( pPathIDa != nullptr )
    pPathIDa->Release(this: pPathIDa);
  CWorkerMulticastListener::FlushAckChunks(this: v45, (unsigned __int16 (*)[2])chunksToAck, &nChunksToAck, &lastAckTime);
  _Error(a1: "ZLibDecompress failed.\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E7A0
// Name: public: CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CWorkerVMPIFileSystem *__thiscall CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(CWorkerVMPIFileSystem *this)
{
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // eax

  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&IBaseFileSystem::`vftable';
  this->m_pBaseFileSystemPassThru = nullptr;
  this->m_pFileSystemPassThru = nullptr;
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CWorkerVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
  CIPAddr::CIPAddr(this: &this->m_MulticastIP);
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CWorkerVMPIFileSystem_vtbl *)&CWorkerVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CWorkerVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
  CIPAddr::CIPAddr(this: &this->m_Listener.m_MulticastAddr);
  this->m_Listener.m_WorkerFiles.m_Memory.m_pMemory = nullptr;
  this->m_Listener.m_WorkerFiles.m_Memory.m_nAllocationCount = 0;
  this->m_Listener.m_WorkerFiles.m_Memory.m_nGrowSize = 0;
  this->m_Listener.m_WorkerFiles.m_LastAlloc.index = -1;
  this->m_Listener.m_WorkerFiles.m_Head = -1;
  this->m_Listener.m_WorkerFiles.m_Tail = -1;
  this->m_Listener.m_WorkerFiles.m_FirstFree = -1;
  m_pMemory = this->m_Listener.m_WorkerFiles.m_Memory.m_pMemory;
  this->m_Listener.m_WorkerFiles.m_ElementCount = 0;
  this->m_Listener.m_WorkerFiles.m_NumAlloced = 0;
  this->m_Listener.m_WorkerFiles.m_pElements = m_pMemory;
  this->m_Listener.m_nUnfinishedFiles = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002E810
// Name: public: virtual void __near * CWorkerVMPIFileSystem::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerVMPIFileSystem::Open(
        CWorkerVMPIFileSystem *this,
        char *pFilename,
        char *pOptions,
        char *pathID)
{
  CWorkerFile *result; // eax
  CWorkerFile *WorkerFile; // eax
  CWorkerFile *v7; // esi
  CVMPIFile_Memory *v8; // eax
  CVMPIFile_Memory *v9; // edi
  int m_Size; // ebx
  const char *m_pMemory; // esi
  int v12; // eax

  if ( pathID == nullptr )
    pathID = (char *)setName;
  if ( g_bDisableFileAccess )
    _Error(a1: "Open( %s, %s ) - file access has been disabled.", pFilename, pOptions);
  if ( V_stristr(a1: pOptions, a2: pFilename, pStr: pOptions, pSearch: "w") != nullptr )
    return nullptr;
  WorkerFile = CWorkerMulticastListener::FindWorkerFile(
                 this: (CWorkerMulticastListener *)&this->m_MulticastIP.port,
                 pFilename,
                 pPathID: pathID);
  v7 = WorkerFile;
  if ( WorkerFile != nullptr && WorkerFile->m_nChunksToReceive == 0
    || (result = CWorkerMulticastListener::ListenFor(
                   this: (CWorkerMulticastListener *)&this->m_MulticastIP.port,
                   pFilename,
                   pPathID: pathID),
        v7 = result,
        result != nullptr) )
  {
    v8 = (CVMPIFile_Memory *)operator new(nSize: 0x14u);
    if ( v8 != nullptr )
    {
      v8->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_Memory::`vftable';
      v9 = v8;
    }
    else
    {
      v9 = nullptr;
    }
    m_Size = v7->m_UncompressedData.m_Size;
    m_pMemory = v7->m_UncompressedData.m_Memory.m_pMemory;
    strchr(string: pOptions, chr: 0x74u);
    CVMPIFile_Memory::Init(this: v9, pData: m_pMemory, len: m_Size, chMode: v12 != 0 ? 116 : 98);
    return (CWorkerFile *)v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E8E0
// Name: public: virtual bool CWorkerVMPIFileSystem::HandleFileSystemPacket(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkerVMPIFileSystem::HandleFileSystemPacket(
        CWorkerVMPIFileSystem *this,
        CVMPIFile_Memory *pBuf,
        int iSource,
        int iPacketID)
{
  CVMPIFile_Memory *v4; // ebx
  unsigned int v6; // esi
  void *v7; // edi
  CVMPIFile_Memory_vtbl *v8; // ebx
  int v9; // edx
  char v10; // al
  unsigned __int8 *v11; // [esp-14h] [ebp-2Ch]
  CFileResponse res; // [esp+4h] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-8h] BYREF

  v4 = pBuf;
  switch ( BYTE1(pBuf->Close) )
  {
    case 2:
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
      CCriticalSectionLock::Lock(this: &csLock);
      v8 = v4->__vftable;
      v9 = *(int *)((char *)&v8->Seek + 2);
      v10 = BYTE2(v8->Tell);
      res.m_RequestID = *(int *)((char *)&v8->Close + 2);
      res.m_Response = v9;
      res.m_bZeroLength = v10;
      CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int>>::InsertBefore(
        this: &g_FileResponses,
        elem: g_FileResponses.m_Size,
        src: &res);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    case 5:
      g_MulticastIP = *(CIPAddr *)((char *)&pBuf->Close + 2);
      g_bReceivedMulticastIP = true;
      return 1;
    case 6:
      v6 = ConCommandBase::GetName(this: pBuf) - 2;
      v7 = operator new(nSize: v6 + 7);
      v11 = (unsigned __int8 *)&v4->Close + 2;
      pBuf = (CVMPIFile_Memory *)v7;
      memcpy(dst: (unsigned __int8 *)v7 + 4, src: v11, count: v6);
      *(_DWORD *)v7 = v6;
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
      CCriticalSectionLock::Lock(this: &csLock);
      CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int>>::AddToTail(
        this: &g_FileChunkPackets,
        src: (CFileChunkPacket **)&pBuf);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E9F0
// Name: class CBaseVMPIFileSystem __near * CreateWorkerVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CWorkerVMPIFileSystem *__cdecl CreateWorkerVMPIFileSystem()
{
  CWorkerVMPIFileSystem *v0; // eax
  CWorkerVMPIFileSystem *v1; // esi

  v0 = (CWorkerVMPIFileSystem *)operator new(nSize: 0x50u);
  if ( v0 != nullptr )
    v1 = CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(this: v0);
  else
    v1 = nullptr;
  g_pBaseVMPIFileSystem = v1;
  if ( v1->Init(this: v1) != INIT_FAILED )
    return v1;
  ((void (__thiscall *)(CWorkerVMPIFileSystem *, int))v1->dtr_CBaseVMPIFileSystem)(a1: v1, a2: 1);
  g_pBaseVMPIFileSystem = nullptr;
  return nullptr;
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x1000C2E0
// Name: __heap_term
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall _heap_term(CFileSystemPassThru *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10014AB0
// Name: ZLibDecompress
// Source: json
//------------------------------------------------------------------------------
bool __usercall ZLibDecompress@<al>(
        unsigned int inputLen@<eax>,
        unsigned __int8 *pOut@<edi>,
        unsigned __int8 *pInput,
        int outLen)
{
  unsigned __int8 *v6; // esi
  unsigned int v7; // eax
  z_stream_s decompressStream; // [esp+8h] [ebp-38h] BYREF

  if ( inputLen == 0 )
    return true;
  memset(dst: (unsigned __int8 *)&decompressStream, value: 0, count: sizeof(decompressStream));
  if ( inflateInit_(a1: &decompressStream, a2: "1.1.3", a3: 56) == 0 )
  {
    decompressStream.avail_in = inputLen;
    decompressStream.next_in = pInput;
    v6 = pOut;
    do
    {
      decompressStream.total_out = 0;
      decompressStream.next_out = v6;
      decompressStream.avail_out = outLen + pOut - v6;
      v7 = inflate(a1: &decompressStream, a2: 0);
      if ( v7 > 1 )
        break;
      v6 += decompressStream.total_out;
      if ( v7 == 1 )
        return v6 - pOut == outLen;
    }
    while ( decompressStream.avail_in != 0 );
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10014B50
// Name: public: void CWorkerMulticastListener::FlushAckChunks(unsigned short (__near * const)[2],int __near &,unsigned long __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerMulticastListener::FlushAckChunks(
        CWorkerMulticastListener *this,
        unsigned __int16 (*chunksToAck)[2],
        int *nChunksToAck,
        unsigned int *lastAckTime)
{
  int *v4; // esi
  int v5; // eax
  void *pChunks[2]; // [esp+4h] [ebp-10h] BYREF
  int chunkLengths[2]; // [esp+Ch] [ebp-8h] BYREF

  v4 = nChunksToAck;
  v5 = *nChunksToAck;
  if ( *nChunksToAck != 0 )
  {
    pChunks[0] = &nChunksToAck;
    pChunks[1] = chunksToAck;
    LOWORD(nChunksToAck) = 768;
    chunkLengths[0] = 2;
    chunkLengths[1] = 4 * v5;
    VMPI_SendChunks((const void *const *)pChunks, pChunkLengths: chunkLengths, nChunks: 2, iDest: 0, fVMPISendFlags: 0);
    *v4 = 0;
  }
  *lastAckTime = GetTickCount();
}

//------------------------------------------------------------------------------
// Address: 0x10014BB0
// Name: public: void CWorkerMulticastListener::AddAckChunk(unsigned short (__near * const)[2],int __near &,unsigned long __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerMulticastListener::AddAckChunk(
        CWorkerMulticastListener *this,
        unsigned __int16 (*chunksToAck)[2],
        int *nChunksToAck,
        unsigned int *lastAckTime,
        unsigned __int16 fileID,
        unsigned __int16 iChunk)
{
  int *v6; // esi
  int v7; // eax
  void *pChunks[2]; // [esp+8h] [ebp-10h] BYREF
  int pChunkLengths[2]; // [esp+10h] [ebp-8h] BYREF

  v6 = nChunksToAck;
  (*chunksToAck)[2 * *nChunksToAck] = fileID;
  (*chunksToAck)[2 * (*v6)++ + 1] = iChunk;
  if ( *v6 == 512 || VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
  {
    v7 = *v6;
    if ( *v6 != 0 )
    {
      pChunks[0] = &nChunksToAck;
      LOWORD(nChunksToAck) = 768;
      pChunks[1] = chunksToAck;
      pChunkLengths[0] = 2;
      pChunkLengths[1] = 4 * v7;
      VMPI_SendChunks((const void *const *)pChunks, pChunkLengths, nChunks: 2, iDest: 0, fVMPISendFlags: 0);
      *v6 = 0;
    }
    *lastAckTime = GetTickCount();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014C40
// Name: public: void CWorkerMulticastListener::ShowSDKWorkerMsg(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CWorkerMulticastListener::ShowSDKWorkerMsg(CWorkerMulticastListener *this, char *pMsg, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+10h] BYREF

  va_start(params, pMsg);
  if ( !g_bMPIMaster && VMPI_IsSDKMode() )
  {
    V_vsnprintf(pDest, maxLen: 0x1000u, pFormat: pMsg, params);
    _Msg(a1: "%s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014CA0
// Name: public: virtual enum InitReturnVal_t CWorkerVMPIFileSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerVMPIFileSystem::Init(CWorkerVMPIFileSystem *this)
{
  int v2; // eax
  unsigned __int16 port; // cx
  CIPAddr mcAddr; // [esp+4h] [ebp-8h] BYREF

  CIPAddr::CIPAddr(this: &mcAddr);
  while ( !g_bReceivedMulticastIP )
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
  v2 = *(_DWORD *)g_MulticastIP.ip;
  port = g_MulticastIP.port;
  *(_DWORD *)this->m_Listener.m_MulticastAddr.ip = *(_DWORD *)g_MulticastIP.ip;
  *(_DWORD *)mcAddr.ip = v2;
  mcAddr.port = port;
  this->m_Listener.m_MulticastAddr.port = port;
  this->m_Listener.m_hMainThread = GetCurrentThread();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014D00
// Name: public: virtual void CWorkerVMPIFileSystem::CreateVirtualFile(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::CreateVirtualFile(
        CWorkerVMPIFileSystem *this,
        const char *pFilename,
        const char *pData,
        const void *fileLength)
{
  _Error(a1: "CreateVirtualFile not supported in VMPI worker filesystem.");
}

//------------------------------------------------------------------------------
// Address: 0x10014D10
// Name: public: virtual long CWorkerVMPIFileSystem::GetFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerVMPIFileSystem::GetFileTime(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        const char *pathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014D30
// Name: public: virtual bool CWorkerVMPIFileSystem::IsFileWritable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerVMPIFileSystem::IsFileWritable(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        const char *pPathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10014D50
// Name: public: virtual bool CWorkerVMPIFileSystem::SetFileWritable(char const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerVMPIFileSystem::SetFileWritable(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        bool writable,
        const char *pPathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10014D70
// Name: public: virtual class CSysModule __near * CWorkerVMPIFileSystem::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
HINSTANCE__ *__thiscall CWorkerVMPIFileSystem::LoadModule(
        CWorkerVMPIFileSystem *this,
        char *pFileName,
        const char *pPathID,
        bool bValidatedDllOnly)
{
  return Sys_LoadModule(pModuleName: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10014D90
// Name: public: virtual void CWorkerVMPIFileSystem::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::UnloadModule(CWorkerVMPIFileSystem *this, struct CSysModule *pModule)
{
  Sys_UnloadModule(pModule);
}

//------------------------------------------------------------------------------
// Address: 0x100150B0
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::FindWorkerFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::FindWorkerFile(
        CWorkerMulticastListener *this,
        const char *pFilename,
        const char *pPathID)
{
  int m_Head; // esi
  int v5; // esi
  CWorkerFile *m_Element; // edi

  m_Head = this->m_WorkerFiles.m_Head;
  if ( m_Head == -1 )
    return nullptr;
  while ( 1 )
  {
    v5 = m_Head;
    m_Element = this->m_WorkerFiles.m_Memory.m_pMemory[v5].m_Element;
    if ( _V_stricmp(s1: m_Element->m_Filename.m_Memory.m_pMemory, s2: pFilename) == 0
      && _V_stricmp(s1: m_Element->m_PathID.m_Memory.m_pMemory, s2: pPathID) == 0 )
    {
      break;
    }
    m_Head = this->m_WorkerFiles.m_Memory.m_pMemory[v5].m_Next;
    if ( m_Head == -1 )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x100153A0
// Name: public: int CWorkerMulticastListener::CheckFileChunkPackets(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerMulticastListener::CheckFileChunkPackets(
        CWorkerMulticastListener *this,
        char *data,
        int dataSize)
{
  CFileChunkPacket *m_Element; // edi
  int m_Head; // esi
  int v6; // esi
  unsigned int m_Len; // [esp-Ch] [ebp-14h]
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( g_FileChunkPackets.m_ElementCount > 0 )
  {
    m_Element = g_FileChunkPackets.m_Memory.m_pMemory[g_FileChunkPackets.m_Head].m_Element;
    m_Head = g_FileChunkPackets.m_Head;
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: &g_FileChunkPackets,
      elem: g_FileChunkPackets.m_Head);
    g_FileChunkPackets.m_Memory.m_pMemory[m_Head].m_Next = g_FileChunkPackets.m_FirstFree;
    g_FileChunkPackets.m_FirstFree = m_Head;
    m_Len = m_Element->m_Len;
    if ( m_Element->m_Len <= dataSize )
    {
      memcpy(dst: (unsigned __int8 *)data, src: (unsigned __int8 *)m_Element->m_Data, count: m_Len);
      v6 = m_Element->m_Len;
    }
    else
    {
      v6 = -1;
      _Warning(a1: "CWorkerMulticastListener::ListenFor: Got a section of data too long (%d bytes).", m_Len);
    }
    free(pMem: m_Element);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return v6;
  }
  else
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015460
// Name: public: virtual void CWorkerVMPIFileSystem::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::Term(CWorkerVMPIFileSystem *this)
{
  CUtlLinkedList<CWorkerFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Listener.m_WorkerFiles);
}

//------------------------------------------------------------------------------
// Address: 0x100154E0
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::RequestFileFromServer(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::RequestFileFromServer(
        CWorkerMulticastListener *this,
        const char *pFilename,
        const char *pPathID)
{
  char v3; // bl
  int m_Size; // esi
  int v5; // eax
  CFileResponse *m_pMemory; // ecx
  __int64 v7; // xmm0_8
  CFileResponse *v8; // edx
  CWorkerFile *v10; // eax
  CWorkerFile *v11; // ebx
  unsigned int v12; // eax
  int v13; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v15; // ecx
  signed int v16; // eax
  const char *v17; // ecx
  char *v18; // esi
  char v19; // al
  unsigned int v20; // eax
  int v21; // edi
  int v22; // eax
  unsigned __int8 *v23; // ecx
  signed int v24; // eax
  const char *v25; // ecx
  char *v26; // esi
  char v27; // al
  CWorkerMulticastListener *v28; // esi
  int v29; // eax
  UtlLinkedListElem_t<CWorkerFile *,int> *v30; // edi
  UtlLinkedListElem_t<CWorkerFile *,int> *v31; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<CWorkerFile *,int> *v34; // ecx
  int v35; // edx
  int m_Tail; // edi
  CWorkerFile **p_m_Element; // esi
  bool m_bZeroLength; // dl
  CWorkerMulticastListener *v39; // eax
  const void *pChunks[4]; // [esp+Ch] [ebp-44h] BYREF
  int chunkLengths[4]; // [esp+1Ch] [ebp-34h] BYREF
  CFileResponse response; // [esp+2Ch] [ebp-24h]
  CCriticalSectionLock csLock; // [esp+38h] [ebp-18h] BYREF
  CWorkerMulticastListener *v44; // [esp+40h] [ebp-10h]
  CWorkerFile *pTestFile; // [esp+44h] [ebp-Ch]
  int requestID; // [esp+48h] [ebp-8h] BYREF
  unsigned __int8 packetID[2]; // [esp+4Ch] [ebp-4h] BYREF

  v44 = this;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  requestID = g_RequestID++;
  CCriticalSectionLock::Unlock(this: &csLock);
  pChunks[0] = packetID;
  *(_WORD *)packetID = 256;
  pChunks[1] = &requestID;
  pChunks[2] = pFilename;
  pChunks[3] = pPathID;
  chunkLengths[0] = 2;
  chunkLengths[1] = 4;
  chunkLengths[2] = strlen(pFilename) + 1;
  chunkLengths[3] = strlen(pPathID) + 1;
  VMPI_SendChunks(pChunks, pChunkLengths: chunkLengths, nChunks: 4, iDest: 0, fVMPISendFlags: 0);
  response.m_Response = -1;
  response.m_bZeroLength = true;
  while ( 1 )
  {
    v3 = 0;
    CCriticalSectionLock::Lock(this: &csLock);
    m_Size = g_FileResponses.m_Size;
    v5 = 0;
    if ( g_FileResponses.m_Size > 0 )
    {
      m_pMemory = g_FileResponses.m_Memory.m_pMemory;
      while ( m_pMemory->m_RequestID != requestID )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= g_FileResponses.m_Size )
          goto LABEL_10;
      }
      v7 = *(_QWORD *)&g_FileResponses.m_Memory.m_pMemory[v5].m_RequestID;
      v8 = &g_FileResponses.m_Memory.m_pMemory[v5];
      *(_DWORD *)&response.m_bZeroLength = *(_DWORD *)&v8->m_bZeroLength;
      *(_QWORD *)&response.m_RequestID = v7;
      if ( g_FileResponses.m_Size - v5 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)v8,
          src: (unsigned __int8 *)&v8[1],
          count: 12 * (g_FileResponses.m_Size - v5 - 1));
        m_Size = g_FileResponses.m_Size;
      }
      g_FileResponses.m_Size = m_Size - 1;
      v3 = 1;
    }
LABEL_10:
    CCriticalSectionLock::Unlock(this: &csLock);
    if ( v3 != 0 )
      break;
    if ( GetCurrentThread() == v44->m_hMainThread )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x14);
    else
      Sleep(dwMilliseconds: 0x14u);
  }
  if ( response.m_Response == -1 )
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return nullptr;
  }
  else
  {
    v10 = (CWorkerFile *)operator new(nSize: 0x78u);
    if ( v10 != nullptr )
    {
      LODWORD(v10->m_Timer.m_Duration.m_Int64) = 0;
      HIDWORD(v10->m_Timer.m_Duration.m_Int64) = 0;
      v10->m_Filename.m_Memory.m_pMemory = nullptr;
      v10->m_Filename.m_Memory.m_nAllocationCount = 0;
      v10->m_Filename.m_Memory.m_nGrowSize = 0;
      v10->m_Filename.m_Size = 0;
      v10->m_Filename.m_pElements = nullptr;
      v10->m_PathID.m_Memory.m_pMemory = nullptr;
      v10->m_PathID.m_Memory.m_nAllocationCount = 0;
      v10->m_PathID.m_Memory.m_nGrowSize = 0;
      v10->m_PathID.m_Size = 0;
      v10->m_PathID.m_pElements = nullptr;
      v10->m_CompressedData.m_Memory.m_pMemory = nullptr;
      v10->m_CompressedData.m_Memory.m_nAllocationCount = 0;
      v10->m_CompressedData.m_Memory.m_nGrowSize = 0;
      v10->m_CompressedData.m_Size = 0;
      v10->m_CompressedData.m_pElements = nullptr;
      v10->m_ChunksReceived.m_Memory.m_pMemory = nullptr;
      v10->m_ChunksReceived.m_Memory.m_nAllocationCount = 0;
      v10->m_ChunksReceived.m_Memory.m_nGrowSize = 0;
      v10->m_ChunksReceived.m_Size = 0;
      v10->m_ChunksReceived.m_pElements = nullptr;
      v10->m_UncompressedData.m_Memory.m_pMemory = nullptr;
      v10->m_UncompressedData.m_Memory.m_nAllocationCount = 0;
      v10->m_UncompressedData.m_Memory.m_nGrowSize = 0;
      v10->m_UncompressedData.m_Size = 0;
      v10->m_UncompressedData.m_pElements = nullptr;
      v11 = v10;
      pTestFile = v10;
    }
    else
    {
      v11 = nullptr;
      pTestFile = nullptr;
    }
    v12 = strlen(pFilename);
    v13 = v12 + 1;
    v11->m_Filename.m_Size = 0;
    if ( v12 != -1 )
    {
      m_nAllocationCount = v11->m_Filename.m_Memory.m_nAllocationCount;
      if ( v13 > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&v11->m_Filename,
          num: v13 - m_nAllocationCount);
      v11->m_Filename.m_Size += v13;
      v15 = (unsigned __int8 *)v11->m_Filename.m_Memory.m_pMemory;
      v16 = v11->m_Filename.m_Size - v13;
      v11->m_Filename.m_pElements = (char *)v15;
      if ( v16 > 0 && v13 > 0 )
        _V_memmove(dest: &v15[v13], src: v15, count: v16);
    }
    v17 = pFilename;
    v18 = v11->m_Filename.m_Memory.m_pMemory;
    do
    {
      v19 = *v17;
      *v18++ = *v17++;
    }
    while ( v19 != 0 );
    v20 = strlen(pPathID);
    v21 = v20 + 1;
    v11->m_PathID.m_Size = 0;
    if ( v20 != -1 )
    {
      v22 = v11->m_PathID.m_Memory.m_nAllocationCount;
      if ( v21 > v22 )
        CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&v11->m_PathID, num: v21 - v22);
      v11->m_PathID.m_Size += v21;
      v23 = (unsigned __int8 *)v11->m_PathID.m_Memory.m_pMemory;
      v24 = v11->m_PathID.m_Size - v21;
      v11->m_PathID.m_pElements = (char *)v23;
      if ( v24 > 0 && v21 > 0 )
        _V_memmove(dest: &v23[v21], src: v23, count: v24);
    }
    v25 = pPathID;
    v26 = v11->m_PathID.m_Memory.m_pMemory;
    do
    {
      v27 = *v25;
      *v26++ = *v25++;
    }
    while ( v27 != 0 );
    v11->m_FileID = response.m_Response;
    v11->m_nChunksToReceive = 9999;
    v11->m_Timer.m_Duration.m_Int64 = __rdtsc();
    v28 = v44;
    v29 = CUtlLinkedList<CWorkerFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int>>::AllocInternal(
            this: &v44->m_WorkerFiles,
            multilist: false);
    if ( v29 != -1 )
    {
      if ( v29 >= 0
        && v29 < v28->m_WorkerFiles.m_Memory.m_nAllocationCount
        && v29 <= v28->m_WorkerFiles.m_LastAlloc.index )
      {
        v30 = v28->m_WorkerFiles.m_Memory.m_pMemory;
        v31 = &v30[v29];
        if ( v31->m_Previous != v29 )
        {
          m_Previous = v31->m_Previous;
          if ( m_Previous == -1 )
          {
            v28->m_WorkerFiles.m_Head = v31->m_Next;
          }
          else
          {
            v30[m_Previous].m_Next = v31->m_Next;
            v11 = pTestFile;
          }
          m_Next = v31->m_Next;
          if ( m_Next == -1 )
          {
            v28->m_WorkerFiles.m_Tail = v31->m_Previous;
          }
          else
          {
            v28->m_WorkerFiles.m_Memory.m_pMemory[m_Next].m_Previous = v31->m_Previous;
            v11 = pTestFile;
          }
          v31->m_Next = v29;
          v31->m_Previous = v29;
          --v28->m_WorkerFiles.m_ElementCount;
        }
      }
      v34 = v28->m_WorkerFiles.m_Memory.m_pMemory;
      v35 = v29;
      v34[v35].m_Next = -1;
      m_Tail = v28->m_WorkerFiles.m_Tail;
      v34[v35].m_Previous = m_Tail;
      v28->m_WorkerFiles.m_Tail = v29;
      if ( m_Tail == -1 )
        v28->m_WorkerFiles.m_Head = v29;
      else
        v28->m_WorkerFiles.m_Memory.m_pMemory[m_Tail].m_Next = v29;
      ++v28->m_WorkerFiles.m_ElementCount;
      p_m_Element = &v28->m_WorkerFiles.m_Memory.m_pMemory[v35].m_Element;
      if ( p_m_Element != nullptr )
        *p_m_Element = v11;
    }
    m_bZeroLength = response.m_bZeroLength;
    v39 = v44;
    v11->m_bGotCompressedSize = false;
    v11->m_bZeroLength = m_bZeroLength;
    ++v39->m_nUnfinishedFiles;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015880
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::ListenFor(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::ListenFor(
        CWorkerMulticastListener *this,
        char *pFilename,
        char *pPathID)
{
  const char *v3; // ebx
  CWorkerMulticastListener *v4; // esi
  CWorkerFile *result; // eax
  unsigned int v6; // edi
  unsigned int v7; // eax
  const CIPAddr *v8; // eax
  int v9; // eax
  int m_Head; // eax
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // esi
  CWorkerFile *m_Element; // esi
  unsigned __int8 *v13; // edx
  int v14; // ebx
  unsigned __int8 *v15; // edx
  int v16; // edx
  int v17; // ecx
  int v18; // edi
  unsigned int v19; // ecx
  CWorkerFile *v20; // eax
  CWorkerMulticastListener *v21; // edi
  long double Seconds; // st7
  unsigned int m_Size; // [esp+8h] [ebp-4E94h]
  char data[4]; // [esp+18h] [ebp-4E84h] BYREF
  int size; // [esp+1Ch] [ebp-4E80h]
  unsigned __int16 v26; // [esp+20h] [ebp-4E7Ch]
  unsigned __int16 v27; // [esp+22h] [ebp-4E7Ah]
  int v28; // [esp+24h] [ebp-4E78h]
  char v29[17392]; // [esp+28h] [ebp-4E74h] BYREF
  unsigned __int16 chunksToAck[2]; // [esp+4418h] [ebp-A84h] BYREF
  char pStr[512]; // [esp+4C18h] [ebp-284h] BYREF
  char pDest[62]; // [esp+4E18h] [ebp-84h] BYREF
  CIPAddr v33; // [esp+4E56h] [ebp-46h] BYREF
  CIPAddr v34; // [esp+4E5Ch] [ebp-40h] BYREF
  int v35; // [esp+4E64h] [ebp-38h]
  unsigned __int8 *src; // [esp+4E6Ch] [ebp-30h]
  int v37; // [esp+4E70h] [ebp-2Ch]
  int v38; // [esp+4E74h] [ebp-28h]
  char *v39; // [esp+4E78h] [ebp-24h]
  unsigned __int64 v40; // [esp+4E7Ch] [ebp-20h] BYREF
  unsigned __int64 *v41; // [esp+4E84h] [ebp-18h]
  unsigned int count; // [esp+4E88h] [ebp-14h]
  CWorkerFile *WorkerFile; // [esp+4E8Ch] [ebp-10h]
  int nChunksToAck; // [esp+4E90h] [ebp-Ch] BYREF
  CWorkerMulticastListener *v45; // [esp+4E94h] [ebp-8h]
  unsigned int lastAckTime; // [esp+4E98h] [ebp-4h] BYREF
  ISocket *pPathIDa; // [esp+4EA8h] [ebp+Ch]

  v3 = pFilename;
  v4 = this;
  v45 = this;
  WorkerFile = CWorkerMulticastListener::FindWorkerFile(this, pFilename, pPathID);
  if ( WorkerFile == nullptr )
  {
    result = CWorkerMulticastListener::RequestFileFromServer(this: v4, pFilename, pPathID);
    WorkerFile = result;
    if ( result == nullptr )
      return nullptr;
    if ( result->m_bZeroLength )
    {
      --v4->m_nUnfinishedFiles;
      return result;
    }
  }
  if ( _V_strlen(str: pFilename) <= 0x39 )
  {
    V_strncpy(pDest, pSrc: pFilename, maxLen: 58);
  }
  else
  {
    V_strncpy(pDest, pSrc: "[...]", maxLen: 58);
    v6 = _V_strlen(str: pFilename);
    v7 = _V_strlen(str: pDest);
    V_strncat(pDest, pSrc: &pFilename[v7 - 57 + v6], destBufferSize: 0x3Au, max_chars_to_copy: -1);
  }
  CWorkerMulticastListener::ShowSDKWorkerMsg(this: v4, pMsg: "\rRecv %s (0%%)  ", pDest);
  v37 = VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_TCP ? 1024 : 0x4000;
  pPathIDa = nullptr;
  if ( VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_MULTICAST )
  {
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
    {
      pPathIDa = CreateIPSocket();
      if ( !pPathIDa->BindToAny(this: pPathIDa, a2: v4->m_MulticastAddr.port) )
      {
        pPathIDa->Release(this: pPathIDa);
        pPathIDa = nullptr;
      }
    }
  }
  else
  {
    v8 = CIPAddr::CIPAddr(this: &v33);
    pPathIDa = CreateMulticastListenSocket(addr: &v4->m_MulticastAddr, localInterface: v8);
    if ( pPathIDa == nullptr )
    {
      IP_GetLastErrorString(pStr, maxLen: 512);
      _Warning(
        a1: "CreateMulticastListenSocket (%d.%d.%d.%d:%d) failed\n%s\n",
        v4->m_MulticastAddr.ip[0],
        v4->m_MulticastAddr.ip[1],
        v4->m_MulticastAddr.ip[2],
        v4->m_MulticastAddr.ip[3],
        v4->m_MulticastAddr.port,
        pStr);
      return nullptr;
    }
  }
  nChunksToAck = 0;
  lastAckTime = GetTickCount();
  if ( v4->m_nUnfinishedFiles <= 0 )
  {
LABEL_54:
    CWorkerMulticastListener::FlushAckChunks(
      this: v4,
      (unsigned __int16 (*)[2])chunksToAck,
      &nChunksToAck,
      &lastAckTime);
    if ( pPathIDa != nullptr )
      pPathIDa->Release(this: pPathIDa);
    return WorkerFile;
  }
  while ( 1 )
  {
    if ( pPathIDa != nullptr )
    {
      CIPAddr::CIPAddr(this: &v34);
      v9 = pPathIDa->RecvFrom(this: pPathIDa, a2: data, a3: 17408, a4: &v34);
    }
    else
    {
      v9 = CWorkerMulticastListener::CheckFileChunkPackets(this: v4, data, dataSize: 17408);
    }
    if ( v9 != -1 )
      break;
    Sleep(dwMilliseconds: 0);
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xA);
LABEL_53:
    if ( v4->m_nUnfinishedFiles <= 0 )
      goto LABEL_54;
  }
  g_nMulticastBytesReceived += v9;
  src = (unsigned __int8 *)&v29[strlen(v3) + 1];
  v39 = &data[v9 - (_DWORD)src];
  if ( (int)v39 < 0 )
  {
    _Warning(a1: "CWorkerMulticastListener::ListenFor: invalid packet received on multicast group\n");
    goto LABEL_53;
  }
  if ( v26 != WorkerFile->m_FileID )
    goto LABEL_53;
  m_Head = v4->m_WorkerFiles.m_Head;
  if ( m_Head == -1 )
  {
LABEL_28:
    m_Element = nullptr;
    goto LABEL_30;
  }
  m_pMemory = v4->m_WorkerFiles.m_Memory.m_pMemory;
  while ( m_pMemory[m_Head].m_Element->m_FileID != v26 )
  {
    m_Head = m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      goto LABEL_28;
  }
  m_Element = m_pMemory[m_Head].m_Element;
  if ( m_Element == nullptr )
LABEL_30:
    _Error(a1: "FindWorkerFile( %s ) failed\n", v29);
  if ( !m_Element->m_bGotCompressedSize )
  {
    m_Element->m_bGotCompressedSize = true;
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_CompressedData,
      size: *(int *)data);
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_UncompressedData,
      size);
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: &m_Element->m_ChunksReceived,
      size: 8 * ((v27 + 7) / 8) / 8);
    v13 = m_Element->m_ChunksReceived.m_Memory.m_pMemory;
    m_Size = m_Element->m_ChunksReceived.m_Size;
    m_Element->m_nChunksToReceive = v27;
    memset(dst: v13, value: 0, count: m_Size);
  }
  v14 = v28;
  if ( v28 < 0 || v28 >= v27 )
    _Error(a1: "ListenFor(): invalid chunk index (%d) for file '%s'\n", v28, v29);
  v15 = m_Element->m_ChunksReceived.m_Memory.m_pMemory;
  count = v14;
  v38 = v14 >> 3;
  v35 = v14 & 7;
  if ( ((unsigned __int8)(1 << (v14 & 7)) & v15[v14 >> 3]) != 0 )
    goto LABEL_49;
  v16 = *(_DWORD *)data;
  if ( size != m_Element->m_UncompressedData.m_Size || *(_DWORD *)data != m_Element->m_CompressedData.m_Size )
  {
    _Error(
      a1: "ListenFor(): invalid compressed or uncompressed size.\n"
      "pInfo = '%s', pTestFile = '%s'\n"
      "Compressed   (pInfo = %d, pTestFile = %d)\n"
      "Uncompressed (pInfo = %d, pTestFile = %d)\n",
      v29,
      m_Element->m_Filename.m_Memory.m_pMemory,
      *(_DWORD *)data,
      m_Element->m_CompressedData.m_Size,
      size,
      m_Element->m_UncompressedData.m_Size);
    v16 = *(_DWORD *)data;
  }
  v17 = m_Element->m_CompressedData.m_Size;
  v18 = v37 * v14;
  if ( v37 * v14 + v37 < v17 )
    v17 = v37 * v14 + v37;
  v19 = v17 - v18;
  count = v19;
  if ( (char *)v19 != v39 )
    _Error(
      a1: "ListenFor(): invalid payload length for '%s' (%d should be %d)\n"
      "pInfo = '%s', pTestFile = '%s'\n"
      "Chunk %d out of %d. Compressed size: %d\n",
      m_Element->m_Filename.m_Memory.m_pMemory,
      v39,
      v19,
      v29,
      m_Element->m_Filename.m_Memory.m_pMemory,
      v14,
      v27,
      v16);
  memcpy(dst: (unsigned __int8 *)&m_Element->m_CompressedData.m_Memory.m_pMemory[v18], src, count);
  m_Element->m_ChunksReceived.m_Memory.m_pMemory[v38] |= 1 << v35;
  v20 = WorkerFile;
  --m_Element->m_nChunksToReceive;
  v21 = v45;
  if ( m_Element == v20 )
    CWorkerMulticastListener::ShowSDKWorkerMsg(
      this: v45,
      pMsg: "\rRecv %s (%d%%) [chunk %d/%d] ",
      pDest,
      100 - 100 * v20->m_nChunksToReceive / v27,
      v27 - v20->m_nChunksToReceive,
      v27);
  CWorkerMulticastListener::AddAckChunk(
    this: v21,
    (unsigned __int16 (*)[2])chunksToAck,
    &nChunksToAck,
    &lastAckTime,
    fileID: v26,
    iChunk: v14);
  if ( m_Element->m_nChunksToReceive != 0 )
  {
LABEL_49:
    if ( nChunksToAck != 0 && GetTickCount() - lastAckTime > 0x1F4 )
      CWorkerMulticastListener::FlushAckChunks(
        this: v45,
        (unsigned __int16 (*)[2])chunksToAck,
        &nChunksToAck,
        &lastAckTime);
    v4 = v45;
    v3 = pFilename;
    goto LABEL_53;
  }
  CWorkerMulticastListener::FlushAckChunks(this: v21, (unsigned __int16 (*)[2])chunksToAck, &nChunksToAck, &lastAckTime);
  v41 = &v40;
  v40 = __rdtsc();
  m_Element->m_Timer.m_Duration.m_Int64 = v40 - m_Element->m_Timer.m_Duration.m_Int64;
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
    this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_UncompressedData,
    size);
  --v21->m_nUnfinishedFiles;
  if ( ZLibDecompress(
         inputLen: m_Element->m_CompressedData.m_Size,
         pOut: (unsigned __int8 *)m_Element->m_UncompressedData.m_Memory.m_pMemory,
         pInput: (unsigned __int8 *)m_Element->m_CompressedData.m_Memory.m_pMemory,
         outLen: m_Element->m_UncompressedData.m_Size) )
  {
    Seconds = CCycleCount::GetSeconds(this: &m_Element->m_Timer.m_Duration);
    V_snprintf(
      pDest: pStr,
      maxLen: 0x200u,
      pFormat: "Got %s (%dk) in %.2fs",
      pDest,
      (m_Element->m_UncompressedData.m_Size + 511) / 1024,
      (double)Seconds);
    _Msg(a1: "\r%-79s\n", pStr);
    CUtlVector<char,CUtlMemory<char,int>>::Purge(this: &m_Element->m_CompressedData);
    goto LABEL_49;
  }
  if ( pPathIDa != nullptr )
    pPathIDa->Release(this: pPathIDa);
  CWorkerMulticastListener::FlushAckChunks(this: v45, (unsigned __int16 (*)[2])chunksToAck, &nChunksToAck, &lastAckTime);
  _Error(a1: "ZLibDecompress failed.\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10015E70
// Name: public: CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CWorkerVMPIFileSystem *__thiscall CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(CWorkerVMPIFileSystem *this)
{
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // eax

  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&IBaseFileSystem::`vftable';
  this->m_pBaseFileSystemPassThru = nullptr;
  this->m_pFileSystemPassThru = nullptr;
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CWorkerVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
  CIPAddr::CIPAddr(this: &this->m_MulticastIP);
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CWorkerVMPIFileSystem_vtbl *)&CWorkerVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CWorkerVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
  CIPAddr::CIPAddr(this: &this->m_Listener.m_MulticastAddr);
  this->m_Listener.m_WorkerFiles.m_Memory.m_pMemory = nullptr;
  this->m_Listener.m_WorkerFiles.m_Memory.m_nAllocationCount = 0;
  this->m_Listener.m_WorkerFiles.m_Memory.m_nGrowSize = 0;
  this->m_Listener.m_WorkerFiles.m_LastAlloc.index = -1;
  this->m_Listener.m_WorkerFiles.m_Head = -1;
  this->m_Listener.m_WorkerFiles.m_Tail = -1;
  this->m_Listener.m_WorkerFiles.m_FirstFree = -1;
  m_pMemory = this->m_Listener.m_WorkerFiles.m_Memory.m_pMemory;
  this->m_Listener.m_WorkerFiles.m_ElementCount = 0;
  this->m_Listener.m_WorkerFiles.m_NumAlloced = 0;
  this->m_Listener.m_WorkerFiles.m_pElements = m_pMemory;
  this->m_Listener.m_nUnfinishedFiles = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10015EE0
// Name: public: virtual void __near * CWorkerVMPIFileSystem::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerVMPIFileSystem::Open(
        CWorkerVMPIFileSystem *this,
        char *pFilename,
        char *pOptions,
        char *pathID)
{
  CWorkerFile *result; // eax
  CWorkerFile *WorkerFile; // eax
  CWorkerFile *v7; // esi
  CVMPIFile_Memory *v8; // eax
  CVMPIFile_Memory *v9; // edi
  int m_Size; // ebx
  const char *m_pMemory; // esi
  int v12; // eax

  if ( pathID == nullptr )
    pathID = (char *)setName;
  if ( g_bDisableFileAccess )
    _Error(a1: "Open( %s, %s ) - file access has been disabled.", pFilename, pOptions);
  if ( V_stristr(a1: pOptions, a2: pFilename, pStr: pOptions, pSearch: "w") != nullptr )
    return nullptr;
  WorkerFile = CWorkerMulticastListener::FindWorkerFile(
                 this: (CWorkerMulticastListener *)&this->m_MulticastIP.port,
                 pFilename,
                 pPathID: pathID);
  v7 = WorkerFile;
  if ( WorkerFile != nullptr && WorkerFile->m_nChunksToReceive == 0
    || (result = CWorkerMulticastListener::ListenFor(
                   this: (CWorkerMulticastListener *)&this->m_MulticastIP.port,
                   pFilename,
                   pPathID: pathID),
        v7 = result,
        result != nullptr) )
  {
    v8 = (CVMPIFile_Memory *)operator new(nSize: 0x14u);
    if ( v8 != nullptr )
    {
      v8->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_Memory::`vftable';
      v9 = v8;
    }
    else
    {
      v9 = nullptr;
    }
    m_Size = v7->m_UncompressedData.m_Size;
    m_pMemory = v7->m_UncompressedData.m_Memory.m_pMemory;
    strchr(string: (unsigned __int8 *)pOptions, chr: 0x74u);
    CVMPIFile_Memory::Init(this: v9, pData: m_pMemory, len: m_Size, chMode: v12 != 0 ? 116 : 98);
    return (CWorkerFile *)v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015FB0
// Name: public: virtual bool CWorkerVMPIFileSystem::HandleFileSystemPacket(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkerVMPIFileSystem::HandleFileSystemPacket(
        CWorkerVMPIFileSystem *this,
        CVMPIFile_Memory *pBuf,
        int iSource,
        int iPacketID)
{
  CVMPIFile_Memory *v4; // ebx
  unsigned int v6; // esi
  void *v7; // edi
  CVMPIFile_Memory_vtbl *v8; // ebx
  int v9; // edx
  char v10; // al
  unsigned __int8 *v11; // [esp-14h] [ebp-2Ch]
  CFileResponse res; // [esp+4h] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-8h] BYREF

  v4 = pBuf;
  switch ( BYTE1(pBuf->Close) )
  {
    case 2:
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
      CCriticalSectionLock::Lock(this: &csLock);
      v8 = v4->__vftable;
      v9 = *(int *)((char *)&v8->Seek + 2);
      v10 = BYTE2(v8->Tell);
      res.m_RequestID = *(int *)((char *)&v8->Close + 2);
      res.m_Response = v9;
      res.m_bZeroLength = v10;
      CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int>>::InsertBefore(
        this: &g_FileResponses,
        elem: g_FileResponses.m_Size,
        src: &res);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    case 5:
      g_MulticastIP = *(CIPAddr *)((char *)&pBuf->Close + 2);
      g_bReceivedMulticastIP = true;
      return 1;
    case 6:
      v6 = ConCommandBase::GetName(this: pBuf) - 2;
      v7 = operator new(nSize: v6 + 7);
      v11 = (unsigned __int8 *)&v4->Close + 2;
      pBuf = (CVMPIFile_Memory *)v7;
      memcpy(dst: (unsigned __int8 *)v7 + 4, src: v11, count: v6);
      *(_DWORD *)v7 = v6;
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
      CCriticalSectionLock::Lock(this: &csLock);
      CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int>>::AddToTail(
        this: &g_FileChunkPackets,
        src: (CFileChunkPacket **)&pBuf);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100160C0
// Name: class CBaseVMPIFileSystem __near * CreateWorkerVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CWorkerVMPIFileSystem *__cdecl CreateWorkerVMPIFileSystem()
{
  CWorkerVMPIFileSystem *v0; // eax
  CWorkerVMPIFileSystem *v1; // esi

  v0 = (CWorkerVMPIFileSystem *)operator new(nSize: 0x50u);
  if ( v0 != nullptr )
    v1 = CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(this: v0);
  else
    v1 = nullptr;
  g_pBaseVMPIFileSystem = v1;
  if ( v1->Init(this: v1) != INIT_FAILED )
    return v1;
  ((void (__thiscall *)(CWorkerVMPIFileSystem *, int))v1->dtr_CBaseVMPIFileSystem)(a1: v1, a2: 1);
  g_pBaseVMPIFileSystem = nullptr;
  return nullptr;
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10097040
// Name: ZLibDecompress
// Source: json
//------------------------------------------------------------------------------
bool __usercall ZLibDecompress@<al>(
        unsigned int inputLen@<eax>,
        unsigned __int8 *pOut@<edi>,
        unsigned __int8 *pInput,
        int outLen)
{
  unsigned __int8 *v6; // esi
  unsigned int v7; // eax
  z_stream_s decompressStream; // [esp+8h] [ebp-38h] BYREF

  if ( inputLen == 0 )
    return true;
  memset(dst: (unsigned __int8 *)&decompressStream, value: 0, count: sizeof(decompressStream));
  if ( inflateInit_(a1: &decompressStream, a2: "1.1.3", a3: 56) == 0 )
  {
    decompressStream.avail_in = inputLen;
    decompressStream.next_in = pInput;
    v6 = pOut;
    do
    {
      decompressStream.total_out = 0;
      decompressStream.next_out = v6;
      decompressStream.avail_out = outLen + pOut - v6;
      v7 = inflate(a1: &decompressStream, a2: 0);
      if ( v7 > 1 )
        break;
      v6 += decompressStream.total_out;
      if ( v7 == 1 )
        return v6 - pOut == outLen;
    }
    while ( decompressStream.avail_in != 0 );
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100970E0
// Name: public: void CWorkerMulticastListener::FlushAckChunks(unsigned short (__near * const)[2],int __near &,unsigned long __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerMulticastListener::FlushAckChunks(
        CWorkerMulticastListener *this,
        unsigned __int16 (*chunksToAck)[2],
        int *nChunksToAck,
        unsigned int *lastAckTime)
{
  int *v4; // esi
  int v5; // eax
  void *pChunks[2]; // [esp+4h] [ebp-10h] BYREF
  int chunkLengths[2]; // [esp+Ch] [ebp-8h] BYREF

  v4 = nChunksToAck;
  v5 = *nChunksToAck;
  if ( *nChunksToAck != 0 )
  {
    pChunks[0] = &nChunksToAck;
    pChunks[1] = chunksToAck;
    LOWORD(nChunksToAck) = 768;
    chunkLengths[0] = 2;
    chunkLengths[1] = 4 * v5;
    VMPI_SendChunks((const void *const *)pChunks, pChunkLengths: chunkLengths, nChunks: 2, iDest: 0, fVMPISendFlags: 0);
    *v4 = 0;
  }
  *lastAckTime = GetTickCount();
}

//------------------------------------------------------------------------------
// Address: 0x10097140
// Name: public: void CWorkerMulticastListener::AddAckChunk(unsigned short (__near * const)[2],int __near &,unsigned long __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerMulticastListener::AddAckChunk(
        CWorkerMulticastListener *this,
        unsigned __int16 (*chunksToAck)[2],
        int *nChunksToAck,
        unsigned int *lastAckTime,
        unsigned __int16 fileID,
        unsigned __int16 iChunk)
{
  int *v6; // esi
  int v7; // eax
  void *pChunks[2]; // [esp+8h] [ebp-10h] BYREF
  int pChunkLengths[2]; // [esp+10h] [ebp-8h] BYREF

  v6 = nChunksToAck;
  (*chunksToAck)[2 * *nChunksToAck] = fileID;
  (*chunksToAck)[2 * (*v6)++ + 1] = iChunk;
  if ( *v6 == 512 || VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
  {
    v7 = *v6;
    if ( *v6 != 0 )
    {
      pChunks[0] = &nChunksToAck;
      LOWORD(nChunksToAck) = 768;
      pChunks[1] = chunksToAck;
      pChunkLengths[0] = 2;
      pChunkLengths[1] = 4 * v7;
      VMPI_SendChunks((const void *const *)pChunks, pChunkLengths, nChunks: 2, iDest: 0, fVMPISendFlags: 0);
      *v6 = 0;
    }
    *lastAckTime = GetTickCount();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100971D0
// Name: public: void CWorkerMulticastListener::ShowSDKWorkerMsg(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CWorkerMulticastListener::ShowSDKWorkerMsg(CWorkerMulticastListener *this, char *pMsg, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+10h] BYREF

  va_start(params, pMsg);
  if ( !g_bMPIMaster && VMPI_IsSDKMode() )
  {
    V_vsnprintf(pDest, maxLen: 0x1000u, pFormat: pMsg, params);
    _Msg(a1: "%s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097230
// Name: public: virtual enum InitReturnVal_t CWorkerVMPIFileSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerVMPIFileSystem::Init(CWorkerVMPIFileSystem *this)
{
  int v2; // eax
  unsigned __int16 port; // cx
  CIPAddr mcAddr; // [esp+4h] [ebp-8h] BYREF

  CIPAddr::CIPAddr(this: &mcAddr);
  while ( !g_bReceivedMulticastIP )
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
  v2 = *(_DWORD *)g_MulticastIP.ip;
  port = g_MulticastIP.port;
  *(_DWORD *)this->m_Listener.m_MulticastAddr.ip = *(_DWORD *)g_MulticastIP.ip;
  *(_DWORD *)mcAddr.ip = v2;
  mcAddr.port = port;
  this->m_Listener.m_MulticastAddr.port = port;
  this->m_Listener.m_hMainThread = GetCurrentThread();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10097290
// Name: public: virtual void CWorkerVMPIFileSystem::CreateVirtualFile(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::CreateVirtualFile(
        CWorkerVMPIFileSystem *this,
        const char *pFilename,
        const char *pData,
        const void *fileLength)
{
  _Error(a1: "CreateVirtualFile not supported in VMPI worker filesystem.");
}

//------------------------------------------------------------------------------
// Address: 0x100972A0
// Name: public: virtual long CWorkerVMPIFileSystem::GetFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerVMPIFileSystem::GetFileTime(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        const char *pathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100972C0
// Name: public: virtual bool CWorkerVMPIFileSystem::IsFileWritable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerVMPIFileSystem::IsFileWritable(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        const char *pPathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100972E0
// Name: public: virtual bool CWorkerVMPIFileSystem::SetFileWritable(char const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerVMPIFileSystem::SetFileWritable(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        bool writable,
        const char *pPathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10097300
// Name: public: virtual class CSysModule __near * CWorkerVMPIFileSystem::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
HINSTANCE__ *__thiscall CWorkerVMPIFileSystem::LoadModule(
        CWorkerVMPIFileSystem *this,
        char *pFileName,
        const char *pPathID,
        bool bValidatedDllOnly)
{
  return Sys_LoadModule(pModuleName: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10097320
// Name: public: virtual void CWorkerVMPIFileSystem::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::UnloadModule(CWorkerVMPIFileSystem *this, struct CSysModule *pModule)
{
  Sys_UnloadModule(pModule);
}

//------------------------------------------------------------------------------
// Address: 0x10097640
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::FindWorkerFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::FindWorkerFile(
        CWorkerMulticastListener *this,
        const char *pFilename,
        const char *pPathID)
{
  int m_Head; // esi
  int v5; // esi
  CWorkerFile *m_Element; // edi

  m_Head = this->m_WorkerFiles.m_Head;
  if ( m_Head == -1 )
    return nullptr;
  while ( 1 )
  {
    v5 = m_Head;
    m_Element = this->m_WorkerFiles.m_Memory.m_pMemory[v5].m_Element;
    if ( _V_stricmp(s1: m_Element->m_Filename.m_Memory.m_pMemory, s2: pFilename) == 0
      && _V_stricmp(s1: m_Element->m_PathID.m_Memory.m_pMemory, s2: pPathID) == 0 )
    {
      break;
    }
    m_Head = this->m_WorkerFiles.m_Memory.m_pMemory[v5].m_Next;
    if ( m_Head == -1 )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x10097930
// Name: public: int CWorkerMulticastListener::CheckFileChunkPackets(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWorkerMulticastListener::CheckFileChunkPackets(
        CWorkerMulticastListener *this,
        char *data,
        int dataSize)
{
  CFileChunkPacket *m_Element; // edi
  int m_Head; // esi
  unsigned int m_Len; // esi
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( g_FileChunkPackets.m_ElementCount > 0 )
  {
    m_Element = g_FileChunkPackets.m_Memory.m_pMemory[g_FileChunkPackets.m_Head].m_Element;
    m_Head = g_FileChunkPackets.m_Head;
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: &g_FileChunkPackets,
      elem: g_FileChunkPackets.m_Head);
    g_FileChunkPackets.m_Memory.m_pMemory[m_Head].m_Next = g_FileChunkPackets.m_FirstFree;
    g_FileChunkPackets.m_FirstFree = m_Head;
    if ( m_Element->m_Len <= dataSize )
    {
      memcpy(dst: (unsigned __int8 *)data, src: (unsigned __int8 *)m_Element->m_Data, count: m_Element->m_Len);
      m_Len = m_Element->m_Len;
    }
    else
    {
      m_Len = -1;
      _Warning(a1: "CWorkerMulticastListener::ListenFor: Got a section of data too long (%d bytes).");
    }
    free(pMem: m_Element);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return m_Len;
  }
  else
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100979F0
// Name: public: virtual void CWorkerVMPIFileSystem::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::Term(CWorkerVMPIFileSystem *this)
{
  CUtlLinkedList<CWorkerFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Listener.m_WorkerFiles);
}

//------------------------------------------------------------------------------
// Address: 0x10097A70
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::RequestFileFromServer(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::RequestFileFromServer(
        CWorkerMulticastListener *this,
        const char *pFilename,
        const char *pPathID)
{
  char v3; // bl
  int m_Size; // esi
  int v5; // eax
  CFileResponse *m_pMemory; // ecx
  __int64 v7; // xmm0_8
  CFileResponse *v8; // edx
  CWorkerFile *v10; // eax
  CWorkerFile *v11; // ebx
  unsigned int v12; // eax
  int v13; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v15; // ecx
  signed int v16; // eax
  const char *v17; // ecx
  char *v18; // esi
  char v19; // al
  unsigned int v20; // eax
  int v21; // edi
  int v22; // eax
  unsigned __int8 *v23; // ecx
  signed int v24; // eax
  const char *v25; // ecx
  char *v26; // esi
  char v27; // al
  CWorkerMulticastListener *v28; // esi
  int v29; // eax
  UtlLinkedListElem_t<CWorkerFile *,int> *v30; // edi
  UtlLinkedListElem_t<CWorkerFile *,int> *v31; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<CWorkerFile *,int> *v34; // ecx
  int v35; // edx
  int m_Tail; // edi
  CWorkerFile **p_m_Element; // esi
  bool m_bZeroLength; // dl
  CWorkerMulticastListener *v39; // eax
  const void *pChunks[4]; // [esp+Ch] [ebp-44h] BYREF
  int chunkLengths[4]; // [esp+1Ch] [ebp-34h] BYREF
  CFileResponse response; // [esp+2Ch] [ebp-24h]
  CCriticalSectionLock csLock; // [esp+38h] [ebp-18h] BYREF
  CWorkerMulticastListener *v44; // [esp+40h] [ebp-10h]
  CWorkerFile *pTestFile; // [esp+44h] [ebp-Ch]
  int requestID; // [esp+48h] [ebp-8h] BYREF
  unsigned __int8 packetID[2]; // [esp+4Ch] [ebp-4h] BYREF

  v44 = this;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  requestID = g_RequestID++;
  CCriticalSectionLock::Unlock(this: &csLock);
  pChunks[0] = packetID;
  *(_WORD *)packetID = 256;
  pChunks[1] = &requestID;
  pChunks[2] = pFilename;
  pChunks[3] = pPathID;
  chunkLengths[0] = 2;
  chunkLengths[1] = 4;
  chunkLengths[2] = strlen(pFilename) + 1;
  chunkLengths[3] = strlen(pPathID) + 1;
  VMPI_SendChunks(pChunks, pChunkLengths: chunkLengths, nChunks: 4, iDest: 0, fVMPISendFlags: 0);
  response.m_Response = -1;
  response.m_bZeroLength = true;
  while ( 1 )
  {
    v3 = 0;
    CCriticalSectionLock::Lock(this: &csLock);
    m_Size = g_FileResponses.m_Size;
    v5 = 0;
    if ( g_FileResponses.m_Size > 0 )
    {
      m_pMemory = g_FileResponses.m_Memory.m_pMemory;
      while ( m_pMemory->m_RequestID != requestID )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= g_FileResponses.m_Size )
          goto LABEL_10;
      }
      v7 = *(_QWORD *)&g_FileResponses.m_Memory.m_pMemory[v5].m_RequestID;
      v8 = &g_FileResponses.m_Memory.m_pMemory[v5];
      *(_DWORD *)&response.m_bZeroLength = *(_DWORD *)&v8->m_bZeroLength;
      *(_QWORD *)&response.m_RequestID = v7;
      if ( g_FileResponses.m_Size - v5 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)v8,
          src: (unsigned __int8 *)&v8[1],
          count: 12 * (g_FileResponses.m_Size - v5 - 1));
        m_Size = g_FileResponses.m_Size;
      }
      g_FileResponses.m_Size = m_Size - 1;
      v3 = 1;
    }
LABEL_10:
    CCriticalSectionLock::Unlock(this: &csLock);
    if ( v3 != 0 )
      break;
    if ( GetCurrentThread() == v44->m_hMainThread )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x14);
    else
      Sleep(dwMilliseconds: 0x14u);
  }
  if ( response.m_Response == -1 )
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return nullptr;
  }
  else
  {
    v10 = (CWorkerFile *)MemAlloc_Alloc(nSize: 0x78u);
    if ( v10 != nullptr )
    {
      LODWORD(v10->m_Timer.m_Duration.m_Int64) = 0;
      HIDWORD(v10->m_Timer.m_Duration.m_Int64) = 0;
      v10->m_Filename.m_Memory.m_pMemory = nullptr;
      v10->m_Filename.m_Memory.m_nAllocationCount = 0;
      v10->m_Filename.m_Memory.m_nGrowSize = 0;
      v10->m_Filename.m_Size = 0;
      v10->m_Filename.m_pElements = nullptr;
      v10->m_PathID.m_Memory.m_pMemory = nullptr;
      v10->m_PathID.m_Memory.m_nAllocationCount = 0;
      v10->m_PathID.m_Memory.m_nGrowSize = 0;
      v10->m_PathID.m_Size = 0;
      v10->m_PathID.m_pElements = nullptr;
      v10->m_CompressedData.m_Memory.m_pMemory = nullptr;
      v10->m_CompressedData.m_Memory.m_nAllocationCount = 0;
      v10->m_CompressedData.m_Memory.m_nGrowSize = 0;
      v10->m_CompressedData.m_Size = 0;
      v10->m_CompressedData.m_pElements = nullptr;
      v10->m_ChunksReceived.m_Memory.m_pMemory = nullptr;
      v10->m_ChunksReceived.m_Memory.m_nAllocationCount = 0;
      v10->m_ChunksReceived.m_Memory.m_nGrowSize = 0;
      v10->m_ChunksReceived.m_Size = 0;
      v10->m_ChunksReceived.m_pElements = nullptr;
      v10->m_UncompressedData.m_Memory.m_pMemory = nullptr;
      v10->m_UncompressedData.m_Memory.m_nAllocationCount = 0;
      v10->m_UncompressedData.m_Memory.m_nGrowSize = 0;
      v10->m_UncompressedData.m_Size = 0;
      v10->m_UncompressedData.m_pElements = nullptr;
      v11 = v10;
      pTestFile = v10;
    }
    else
    {
      v11 = nullptr;
      pTestFile = nullptr;
    }
    v12 = strlen(pFilename);
    v13 = v12 + 1;
    v11->m_Filename.m_Size = 0;
    if ( v12 != -1 )
    {
      m_nAllocationCount = v11->m_Filename.m_Memory.m_nAllocationCount;
      if ( v13 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&v11->m_Filename,
          num: v13 - m_nAllocationCount);
      v11->m_Filename.m_Size += v13;
      v15 = (unsigned __int8 *)v11->m_Filename.m_Memory.m_pMemory;
      v16 = v11->m_Filename.m_Size - v13;
      v11->m_Filename.m_pElements = (char *)v15;
      if ( v16 > 0 && v13 > 0 )
        _V_memmove(dest: &v15[v13], src: v15, count: v16);
    }
    v17 = pFilename;
    v18 = v11->m_Filename.m_Memory.m_pMemory;
    do
    {
      v19 = *v17;
      *v18++ = *v17++;
    }
    while ( v19 != 0 );
    v20 = strlen(pPathID);
    v21 = v20 + 1;
    v11->m_PathID.m_Size = 0;
    if ( v20 != -1 )
    {
      v22 = v11->m_PathID.m_Memory.m_nAllocationCount;
      if ( v21 > v22 )
        CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&v11->m_PathID, num: v21 - v22);
      v11->m_PathID.m_Size += v21;
      v23 = (unsigned __int8 *)v11->m_PathID.m_Memory.m_pMemory;
      v24 = v11->m_PathID.m_Size - v21;
      v11->m_PathID.m_pElements = (char *)v23;
      if ( v24 > 0 && v21 > 0 )
        _V_memmove(dest: &v23[v21], src: v23, count: v24);
    }
    v25 = pPathID;
    v26 = v11->m_PathID.m_Memory.m_pMemory;
    do
    {
      v27 = *v25;
      *v26++ = *v25++;
    }
    while ( v27 != 0 );
    v11->m_FileID = response.m_Response;
    v11->m_nChunksToReceive = 9999;
    v11->m_Timer.m_Duration.m_Int64 = __rdtsc();
    v28 = v44;
    v29 = CUtlLinkedList<CWorkerFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int>>::AllocInternal(
            this: &v44->m_WorkerFiles,
            multilist: false);
    if ( v29 != -1 )
    {
      if ( v29 >= 0
        && v29 < v28->m_WorkerFiles.m_Memory.m_nAllocationCount
        && v29 <= v28->m_WorkerFiles.m_LastAlloc.index )
      {
        v30 = v28->m_WorkerFiles.m_Memory.m_pMemory;
        v31 = &v30[v29];
        if ( v31->m_Previous != v29 )
        {
          m_Previous = v31->m_Previous;
          if ( m_Previous == -1 )
          {
            v28->m_WorkerFiles.m_Head = v31->m_Next;
          }
          else
          {
            v30[m_Previous].m_Next = v31->m_Next;
            v11 = pTestFile;
          }
          m_Next = v31->m_Next;
          if ( m_Next == -1 )
          {
            v28->m_WorkerFiles.m_Tail = v31->m_Previous;
          }
          else
          {
            v28->m_WorkerFiles.m_Memory.m_pMemory[m_Next].m_Previous = v31->m_Previous;
            v11 = pTestFile;
          }
          v31->m_Next = v29;
          v31->m_Previous = v29;
          --v28->m_WorkerFiles.m_ElementCount;
        }
      }
      v34 = v28->m_WorkerFiles.m_Memory.m_pMemory;
      v35 = v29;
      v34[v35].m_Next = -1;
      m_Tail = v28->m_WorkerFiles.m_Tail;
      v34[v35].m_Previous = m_Tail;
      v28->m_WorkerFiles.m_Tail = v29;
      if ( m_Tail == -1 )
        v28->m_WorkerFiles.m_Head = v29;
      else
        v28->m_WorkerFiles.m_Memory.m_pMemory[m_Tail].m_Next = v29;
      ++v28->m_WorkerFiles.m_ElementCount;
      p_m_Element = &v28->m_WorkerFiles.m_Memory.m_pMemory[v35].m_Element;
      if ( p_m_Element != nullptr )
        *p_m_Element = v11;
    }
    m_bZeroLength = response.m_bZeroLength;
    v39 = v44;
    v11->m_bGotCompressedSize = false;
    v11->m_bZeroLength = m_bZeroLength;
    ++v39->m_nUnfinishedFiles;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097E10
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::ListenFor(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::ListenFor(
        CWorkerMulticastListener *this,
        char *pFilename,
        char *pPathID)
{
  const char *v3; // ebx
  CWorkerMulticastListener *v4; // esi
  CWorkerFile *result; // eax
  unsigned int v6; // edi
  unsigned int v7; // eax
  const CIPAddr *v8; // eax
  unsigned int v9; // eax
  int m_Head; // eax
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // esi
  CWorkerFile *m_Element; // esi
  unsigned __int8 *v13; // edx
  int v14; // ebx
  unsigned __int8 *v15; // edx
  int v16; // edx
  int v17; // ecx
  int v18; // edi
  unsigned int v19; // ecx
  CWorkerFile *v20; // eax
  CWorkerMulticastListener *v21; // edi
  long double Seconds; // st7
  unsigned int m_Size; // [esp+8h] [ebp-4E94h]
  char data[4]; // [esp+18h] [ebp-4E84h] BYREF
  int size; // [esp+1Ch] [ebp-4E80h]
  unsigned __int16 v26; // [esp+20h] [ebp-4E7Ch]
  unsigned __int16 v27; // [esp+22h] [ebp-4E7Ah]
  int v28; // [esp+24h] [ebp-4E78h]
  char v29[17392]; // [esp+28h] [ebp-4E74h] BYREF
  unsigned __int16 chunksToAck[2]; // [esp+4418h] [ebp-A84h] BYREF
  char pStr[512]; // [esp+4C18h] [ebp-284h] BYREF
  char pDest[62]; // [esp+4E18h] [ebp-84h] BYREF
  CIPAddr v33; // [esp+4E56h] [ebp-46h] BYREF
  CIPAddr v34; // [esp+4E5Ch] [ebp-40h] BYREF
  int v35; // [esp+4E64h] [ebp-38h]
  unsigned __int8 *src; // [esp+4E6Ch] [ebp-30h]
  int v37; // [esp+4E70h] [ebp-2Ch]
  int v38; // [esp+4E74h] [ebp-28h]
  char *v39; // [esp+4E78h] [ebp-24h]
  unsigned __int64 v40; // [esp+4E7Ch] [ebp-20h] BYREF
  unsigned __int64 *v41; // [esp+4E84h] [ebp-18h]
  unsigned int count; // [esp+4E88h] [ebp-14h]
  CWorkerFile *WorkerFile; // [esp+4E8Ch] [ebp-10h]
  int nChunksToAck; // [esp+4E90h] [ebp-Ch] BYREF
  CWorkerMulticastListener *v45; // [esp+4E94h] [ebp-8h]
  unsigned int lastAckTime; // [esp+4E98h] [ebp-4h] BYREF
  ISocket *pPathIDa; // [esp+4EA8h] [ebp+Ch]

  v3 = pFilename;
  v4 = this;
  v45 = this;
  WorkerFile = CWorkerMulticastListener::FindWorkerFile(this, pFilename, pPathID);
  if ( WorkerFile == nullptr )
  {
    result = CWorkerMulticastListener::RequestFileFromServer(this: v4, pFilename, pPathID);
    WorkerFile = result;
    if ( result == nullptr )
      return nullptr;
    if ( result->m_bZeroLength )
    {
      --v4->m_nUnfinishedFiles;
      return result;
    }
  }
  if ( _V_strlen(str: pFilename) <= 0x39 )
  {
    V_strncpy(pDest, pSrc: pFilename, maxLen: 58);
  }
  else
  {
    V_strncpy(pDest, pSrc: "[...]", maxLen: 58);
    v6 = _V_strlen(str: pFilename);
    v7 = _V_strlen(str: pDest);
    V_strncat(pDest, pSrc: &pFilename[v7 - 57 + v6], destBufferSize: 0x3Au, max_chars_to_copy: -1);
  }
  CWorkerMulticastListener::ShowSDKWorkerMsg(this: v4, pMsg: "\rRecv %s (0%%)  ", pDest);
  v37 = VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_TCP ? 1024 : 0x4000;
  pPathIDa = nullptr;
  if ( VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_MULTICAST )
  {
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
    {
      pPathIDa = CreateIPSocket();
      if ( !pPathIDa->BindToAny(this: pPathIDa, a2: v4->m_MulticastAddr.port) )
      {
        pPathIDa->Release(this: pPathIDa);
        pPathIDa = nullptr;
      }
    }
  }
  else
  {
    v8 = CIPAddr::CIPAddr(this: &v33);
    pPathIDa = CreateMulticastListenSocket(addr: &v4->m_MulticastAddr, localInterface: v8);
    if ( pPathIDa == nullptr )
    {
      IP_GetLastErrorString(pStr, maxLen: 512);
      _Warning(a1: "CreateMulticastListenSocket (%d.%d.%d.%d:%d) failed\n%s\n");
      return nullptr;
    }
  }
  nChunksToAck = 0;
  lastAckTime = GetTickCount();
  if ( v4->m_nUnfinishedFiles <= 0 )
  {
LABEL_54:
    CWorkerMulticastListener::FlushAckChunks(
      this: v4,
      (unsigned __int16 (*)[2])chunksToAck,
      &nChunksToAck,
      &lastAckTime);
    if ( pPathIDa != nullptr )
      pPathIDa->Release(this: pPathIDa);
    return WorkerFile;
  }
  while ( 1 )
  {
    if ( pPathIDa != nullptr )
    {
      CIPAddr::CIPAddr(this: &v34);
      v9 = pPathIDa->RecvFrom(this: pPathIDa, a2: data, a3: 17408, a4: &v34);
    }
    else
    {
      v9 = CWorkerMulticastListener::CheckFileChunkPackets(this: v4, data, dataSize: 17408);
    }
    if ( v9 != -1 )
      break;
    Sleep(dwMilliseconds: 0);
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xA);
LABEL_53:
    if ( v4->m_nUnfinishedFiles <= 0 )
      goto LABEL_54;
  }
  g_nMulticastBytesReceived += v9;
  src = (unsigned __int8 *)&v29[strlen(v3) + 1];
  v39 = &data[v9 - (_DWORD)src];
  if ( (int)v39 < 0 )
  {
    _Warning(a1: "CWorkerMulticastListener::ListenFor: invalid packet received on multicast group\n");
    goto LABEL_53;
  }
  if ( v26 != WorkerFile->m_FileID )
    goto LABEL_53;
  m_Head = v4->m_WorkerFiles.m_Head;
  if ( m_Head == -1 )
  {
LABEL_28:
    m_Element = nullptr;
    goto LABEL_30;
  }
  m_pMemory = v4->m_WorkerFiles.m_Memory.m_pMemory;
  while ( m_pMemory[m_Head].m_Element->m_FileID != v26 )
  {
    m_Head = m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      goto LABEL_28;
  }
  m_Element = m_pMemory[m_Head].m_Element;
  if ( m_Element == nullptr )
LABEL_30:
    _Error(a1: "FindWorkerFile( %s ) failed\n", v29);
  if ( !m_Element->m_bGotCompressedSize )
  {
    m_Element->m_bGotCompressedSize = true;
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_CompressedData,
      size: *(int *)data);
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_UncompressedData,
      size);
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: &m_Element->m_ChunksReceived,
      size: 8 * ((v27 + 7) / 8) / 8);
    v13 = m_Element->m_ChunksReceived.m_Memory.m_pMemory;
    m_Size = m_Element->m_ChunksReceived.m_Size;
    m_Element->m_nChunksToReceive = v27;
    memset(dst: v13, value: 0, count: m_Size);
  }
  v14 = v28;
  if ( v28 < 0 || v28 >= v27 )
    _Error(a1: "ListenFor(): invalid chunk index (%d) for file '%s'\n", v28, v29);
  v15 = m_Element->m_ChunksReceived.m_Memory.m_pMemory;
  count = v14;
  v38 = v14 >> 3;
  v35 = v14 & 7;
  if ( ((unsigned __int8)(1 << (v14 & 7)) & v15[v14 >> 3]) != 0 )
    goto LABEL_49;
  v16 = *(_DWORD *)data;
  if ( size != m_Element->m_UncompressedData.m_Size || *(_DWORD *)data != m_Element->m_CompressedData.m_Size )
  {
    _Error(
      a1: "ListenFor(): invalid compressed or uncompressed size.\n"
      "pInfo = '%s', pTestFile = '%s'\n"
      "Compressed   (pInfo = %d, pTestFile = %d)\n"
      "Uncompressed (pInfo = %d, pTestFile = %d)\n",
      v29,
      m_Element->m_Filename.m_Memory.m_pMemory,
      *(_DWORD *)data,
      m_Element->m_CompressedData.m_Size,
      size,
      m_Element->m_UncompressedData.m_Size);
    v16 = *(_DWORD *)data;
  }
  v17 = m_Element->m_CompressedData.m_Size;
  v18 = v37 * v14;
  if ( v37 * v14 + v37 < v17 )
    v17 = v37 * v14 + v37;
  v19 = v17 - v18;
  count = v19;
  if ( (char *)v19 != v39 )
    _Error(
      a1: "ListenFor(): invalid payload length for '%s' (%d should be %d)\n"
      "pInfo = '%s', pTestFile = '%s'\n"
      "Chunk %d out of %d. Compressed size: %d\n",
      m_Element->m_Filename.m_Memory.m_pMemory,
      v39,
      v19,
      v29,
      m_Element->m_Filename.m_Memory.m_pMemory,
      v14,
      v27,
      v16);
  memcpy(dst: (unsigned __int8 *)&m_Element->m_CompressedData.m_Memory.m_pMemory[v18], src, count);
  m_Element->m_ChunksReceived.m_Memory.m_pMemory[v38] |= 1 << v35;
  v20 = WorkerFile;
  --m_Element->m_nChunksToReceive;
  v21 = v45;
  if ( m_Element == v20 )
    CWorkerMulticastListener::ShowSDKWorkerMsg(
      this: v45,
      pMsg: "\rRecv %s (%d%%) [chunk %d/%d] ",
      pDest,
      100 - 100 * v20->m_nChunksToReceive / v27,
      v27 - v20->m_nChunksToReceive,
      v27);
  CWorkerMulticastListener::AddAckChunk(
    this: v21,
    (unsigned __int16 (*)[2])chunksToAck,
    &nChunksToAck,
    &lastAckTime,
    fileID: v26,
    iChunk: v14);
  if ( m_Element->m_nChunksToReceive != 0 )
  {
LABEL_49:
    if ( nChunksToAck != 0 && GetTickCount() - lastAckTime > 0x1F4 )
      CWorkerMulticastListener::FlushAckChunks(
        this: v45,
        (unsigned __int16 (*)[2])chunksToAck,
        &nChunksToAck,
        &lastAckTime);
    v4 = v45;
    v3 = pFilename;
    goto LABEL_53;
  }
  CWorkerMulticastListener::FlushAckChunks(this: v21, (unsigned __int16 (*)[2])chunksToAck, &nChunksToAck, &lastAckTime);
  v41 = &v40;
  v40 = __rdtsc();
  m_Element->m_Timer.m_Duration.m_Int64 = v40 - m_Element->m_Timer.m_Duration.m_Int64;
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
    this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_UncompressedData,
    size);
  --v21->m_nUnfinishedFiles;
  if ( ZLibDecompress(
         inputLen: m_Element->m_CompressedData.m_Size,
         pOut: (unsigned __int8 *)m_Element->m_UncompressedData.m_Memory.m_pMemory,
         pInput: (unsigned __int8 *)m_Element->m_CompressedData.m_Memory.m_pMemory,
         outLen: m_Element->m_UncompressedData.m_Size) )
  {
    Seconds = CCycleCount::GetSeconds(this: &m_Element->m_Timer.m_Duration);
    V_snprintf(
      pDest: pStr,
      maxLen: 0x200u,
      pFormat: "Got %s (%dk) in %.2fs",
      pDest,
      (m_Element->m_UncompressedData.m_Size + 511) / 1024,
      (double)Seconds);
    _Msg(a1: "\r%-79s\n", pStr);
    CUtlVector<CLightValue,CUtlMemory<CLightValue,int>>::Purge(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_CompressedData);
    goto LABEL_49;
  }
  if ( pPathIDa != nullptr )
    pPathIDa->Release(this: pPathIDa);
  CWorkerMulticastListener::FlushAckChunks(this: v45, (unsigned __int16 (*)[2])chunksToAck, &nChunksToAck, &lastAckTime);
  _Error(a1: "ZLibDecompress failed.\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10098400
// Name: public: CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CWorkerVMPIFileSystem *__thiscall CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(CWorkerVMPIFileSystem *this)
{
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // eax

  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&IBaseFileSystem::`vftable';
  this->m_pBaseFileSystemPassThru = nullptr;
  this->m_pFileSystemPassThru = nullptr;
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CWorkerVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
  CIPAddr::CIPAddr(this: &this->m_MulticastIP);
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CWorkerVMPIFileSystem_vtbl *)&CWorkerVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CWorkerVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
  CIPAddr::CIPAddr(this: &this->m_Listener.m_MulticastAddr);
  this->m_Listener.m_WorkerFiles.m_Memory.m_pMemory = nullptr;
  this->m_Listener.m_WorkerFiles.m_Memory.m_nAllocationCount = 0;
  this->m_Listener.m_WorkerFiles.m_Memory.m_nGrowSize = 0;
  this->m_Listener.m_WorkerFiles.m_LastAlloc.index = -1;
  this->m_Listener.m_WorkerFiles.m_Head = -1;
  this->m_Listener.m_WorkerFiles.m_Tail = -1;
  this->m_Listener.m_WorkerFiles.m_FirstFree = -1;
  m_pMemory = this->m_Listener.m_WorkerFiles.m_Memory.m_pMemory;
  this->m_Listener.m_WorkerFiles.m_ElementCount = 0;
  this->m_Listener.m_WorkerFiles.m_NumAlloced = 0;
  this->m_Listener.m_WorkerFiles.m_pElements = m_pMemory;
  this->m_Listener.m_nUnfinishedFiles = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10098470
// Name: public: virtual void __near * CWorkerVMPIFileSystem::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerVMPIFileSystem::Open(
        CWorkerVMPIFileSystem *this,
        char *pFilename,
        char *pOptions,
        char *pathID)
{
  CWorkerFile *result; // eax
  CWorkerFile *WorkerFile; // eax
  CWorkerFile *v7; // esi
  CVMPIFile_Memory *v8; // eax
  CVMPIFile_Memory *v9; // edi
  int m_Size; // ebx
  const char *m_pMemory; // esi
  int v12; // eax

  if ( pathID == nullptr )
    pathID = (char *)defaultValue;
  if ( g_bDisableFileAccess )
    _Error(a1: "Open( %s, %s ) - file access has been disabled.", pFilename, pOptions);
  if ( V_stristr(a1: pOptions, a2: pFilename, pStr: pOptions, pSearch: "w") != nullptr )
    return nullptr;
  WorkerFile = CWorkerMulticastListener::FindWorkerFile(
                 this: (CWorkerMulticastListener *)&this->m_MulticastIP.port,
                 pFilename,
                 pPathID: pathID);
  v7 = WorkerFile;
  if ( WorkerFile != nullptr && WorkerFile->m_nChunksToReceive == 0
    || (result = CWorkerMulticastListener::ListenFor(
                   this: (CWorkerMulticastListener *)&this->m_MulticastIP.port,
                   pFilename,
                   pPathID: pathID),
        v7 = result,
        result != nullptr) )
  {
    v8 = (CVMPIFile_Memory *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v8 != nullptr )
    {
      v8->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_Memory::`vftable';
      v9 = v8;
    }
    else
    {
      v9 = nullptr;
    }
    m_Size = v7->m_UncompressedData.m_Size;
    m_pMemory = v7->m_UncompressedData.m_Memory.m_pMemory;
    strchr(string: (unsigned __int8 *)pOptions, chr: 0x74u);
    CVMPIFile_Memory::Init(this: v9, pData: m_pMemory, len: m_Size, chMode: v12 != 0 ? 116 : 98);
    return (CWorkerFile *)v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10098540
// Name: public: virtual bool CWorkerVMPIFileSystem::HandleFileSystemPacket(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkerVMPIFileSystem::HandleFileSystemPacket(
        CWorkerVMPIFileSystem *this,
        CFileChunkPacket *pBuf,
        int iSource,
        int iPacketID)
{
  CFileChunkPacket *v4; // ebx
  unsigned int v6; // esi
  CFileChunkPacket *v7; // edi
  int m_Len; // ebx
  int v9; // edx
  char v10; // al
  unsigned __int8 *v11; // [esp-14h] [ebp-2Ch]
  CFileResponse res; // [esp+4h] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-8h] BYREF

  v4 = pBuf;
  switch ( *(_BYTE *)(pBuf->m_Len + 1) )
  {
    case 2:
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
      CCriticalSectionLock::Lock(this: &csLock);
      m_Len = v4->m_Len;
      v9 = *(_DWORD *)(m_Len + 6);
      v10 = *(_BYTE *)(m_Len + 10);
      res.m_RequestID = *(_DWORD *)(m_Len + 2);
      res.m_Response = v9;
      res.m_bZeroLength = v10;
      CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int>>::InsertBefore(
        this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_FileResponses,
        elem: g_FileResponses.m_Size,
        src: (const CVTFTexture::ResourceMemorySection *)&res);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    case 5:
      g_MulticastIP = *(CIPAddr *)(pBuf->m_Len + 2);
      g_bReceivedMulticastIP = true;
      return 1;
    case 6:
      v6 = ConCommandBase::GetName(this: (CVTFTexture *)pBuf) - 2;
      v7 = (CFileChunkPacket *)MemAlloc_Alloc(nSize: v6 + 7);
      v11 = (unsigned __int8 *)(v4->m_Len + 2);
      pBuf = v7;
      memcpy(dst: (unsigned __int8 *)v7->m_Data, src: v11, count: v6);
      v7->m_Len = v6;
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
      CCriticalSectionLock::Lock(this: &csLock);
      CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int>>::AddToTail(
        this: &g_FileChunkPackets,
        src: &pBuf);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098650
// Name: class CBaseVMPIFileSystem __near * CreateWorkerVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CWorkerVMPIFileSystem *__cdecl CreateWorkerVMPIFileSystem()
{
  CWorkerVMPIFileSystem *v0; // eax
  CWorkerVMPIFileSystem *v1; // esi

  v0 = (CWorkerVMPIFileSystem *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v0 != nullptr )
    v1 = CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(this: v0);
  else
    v1 = nullptr;
  g_pBaseVMPIFileSystem = v1;
  if ( v1->Init(this: v1) != INIT_FAILED )
    return v1;
  ((void (__thiscall *)(CWorkerVMPIFileSystem *, int))v1->dtr_CBaseVMPIFileSystem)(a1: v1, a2: 1);
  g_pBaseVMPIFileSystem = nullptr;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10098700
// Name: _deflateInit_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateInit_(int a1, int a2, int a3, int a4)
{
  return deflateInit2_(a1, a2, a3: 8, a4: 15, a5: 8, a6: 0, a7: a3, a8: a4);
}

//------------------------------------------------------------------------------
// Address: 0x10098730
// Name: _deflateInit2_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateInit2_(_DWORD *a1, int a2, int a3, int a4, int a5, unsigned int a6, _BYTE *a7, int a8)
{
  int v8; // ebp
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // ebx
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  unsigned int v21; // ecx

  v8 = 0;
  if ( a7 == nullptr || *a7 != *off_101377D4 || a8 != 56 )
    return -6;
  if ( a1 == nullptr )
    return -2;
  v10 = a1[8];
  a1[6] = 0;
  if ( v10 == 0 )
  {
    a1[8] = zcalloc;
    a1[10] = 0;
  }
  if ( a1[9] == 0 )
    a1[9] = zcfree;
  v11 = a2;
  if ( a2 == -1 )
  {
    a2 = 6;
    v11 = 6;
  }
  v12 = a4;
  if ( a4 < 0 )
  {
    v8 = 1;
    v12 = -a4;
  }
  if ( a5 < 1 || a5 > 9 || a3 != 8 || v12 < 8 || v12 > 15 || v11 > 9 || a6 > 2 )
    return -2;
  v13 = (_DWORD *)((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1, a3: 5816);
  v14 = v13;
  if ( v13 == nullptr )
    return -4;
  a1[7] = v13;
  v13[6] = v8;
  v13[10] = v12;
  *v13 = a1;
  v13[18] = a5 + 7;
  v13[9] = 1 << v12;
  v13[11] = (1 << v12) - 1;
  v15 = 1 << (a5 + 7);
  v14[17] = v15;
  v14[19] = v15 - 1;
  v14[20] = (a5 + 9) / 3u;
  v16 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1 << v12, a3: 2);
  v17 = v14[9];
  v14[12] = v16;
  v18 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: v17, a3: 2);
  v19 = v14[17];
  v14[14] = v18;
  v14[15] = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: v19, a3: 2);
  v14[1445] = 1 << (a5 + 6);
  v20 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1 << (a5 + 6), a3: 4);
  v21 = v14[1445];
  v14[2] = v20;
  v14[3] = 4 * v21;
  if ( v14[12] != 0 && v14[14] != 0 && v14[15] != 0 && v20 != 0 )
  {
    *((_BYTE *)v14 + 29) = 8;
    v14[1447] = v20 + 2 * (v21 >> 1);
    v14[1444] = v20 + 2 * v21 + v21;
    v14[32] = a6;
    v14[31] = a2;
    return deflateReset(a1);
  }
  else
  {
    a1[6] = off_10137868[0];
    deflateEnd(a1);
    return -4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098930
// Name: _deflateReset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateReset(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // edx

  if ( a1 == nullptr )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( v1 == nullptr || a1[8] == 0 || a1[9] == 0 )
    return -2;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  a1[11] = 2;
  v2 = v1[2];
  v1[5] = 0;
  v1[4] = v2;
  if ( (int)v1[6] < 0 )
    v1[6] = 0;
  v1[1] = v1[6] != 0 ? 113 : 42;
  a1[12] = 1;
  v1[8] = 0;
  _tr_init(a1: v1);
  sub_10098DC0(a1: v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100989B0
// Name: _deflate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflate(int a1, int a2)
{
  int v3; // esi
  int v4; // eax
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // [esp+14h] [ebp+4h]

  if ( a1 == 0 )
    return -2;
  v3 = *(_DWORD *)(a1 + 28);
  if ( v3 == 0 || (unsigned int)a2 > 4 )
    return -2;
  if ( *(_DWORD *)(a1 + 12) == 0
    || *(_DWORD *)a1 == 0 && *(_DWORD *)(a1 + 4) != 0
    || (v4 = *(_DWORD *)(v3 + 4)) == 666 && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_10137860[0];
    return -2;
  }
  if ( *(_DWORD *)(a1 + 16) == 0 )
  {
    *(char **)(a1 + 24) = off_1013786C[0];
    return -5;
  }
  v6 = *(_DWORD *)(v3 + 32);
  *(_DWORD *)v3 = a1;
  v13 = v6;
  *(_DWORD *)(v3 + 32) = a2;
  if ( v4 == 42 )
  {
    v7 = (*(_DWORD *)(v3 + 124) - 1) >> 1;
    if ( v7 > 3 )
      v7 = 3;
    v8 = (v7 << 6) | ((*(_DWORD *)(v3 + 40) << 12) - 30720);
    if ( *(_DWORD *)(v3 + 100) != 0 )
      v8 |= 0x20u;
    *(_DWORD *)(v3 + 4) = 113;
    sub_10098C60(a1: v3, a2: v8 - v8 % 0x1F + 31);
    if ( *(_DWORD *)(v3 + 100) != 0 )
    {
      sub_10098C60(a1: v3, a2: *(unsigned __int16 *)(a1 + 50));
      sub_10098C60(a1: v3, a2: (unsigned __int16)*(_DWORD *)(a1 + 48));
    }
    *(_DWORD *)(a1 + 48) = 1;
  }
  if ( *(_DWORD *)(v3 + 20) != 0 )
  {
    sub_10098C90(a1);
    if ( *(_DWORD *)(a1 + 16) == 0 )
    {
      *(_DWORD *)(v3 + 32) = -1;
      return 0;
    }
  }
  else if ( *(_DWORD *)(a1 + 4) == 0 && a2 <= v13 && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_1013786C[0];
    return -5;
  }
  v9 = *(_DWORD *)(v3 + 4);
  v10 = *(_DWORD *)(a1 + 4);
  if ( v9 == 666 )
  {
    if ( v10 != 0 )
    {
      *(char **)(a1 + 24) = off_1013786C[0];
      return -5;
    }
  }
  else if ( v10 != 0 )
  {
    goto LABEL_33;
  }
  if ( *(_DWORD *)(v3 + 108) == 0 && (a2 == 0 || v9 == 666) )
  {
LABEL_45:
    if ( a2 != 4 )
      return 0;
    if ( *(_DWORD *)(v3 + 24) != 0 )
      return 1;
    sub_10098C60(a1: v3, a2: *(unsigned __int16 *)(a1 + 50));
    sub_10098C60(a1: v3, a2: (unsigned __int16)*(_DWORD *)(a1 + 48));
    sub_10098C90(a1);
    v12 = *(_DWORD *)(v3 + 20);
    *(_DWORD *)(v3 + 24) = -1;
    return v12 == 0;
  }
LABEL_33:
  v11 = funcs_10098B44[3 * *(_DWORD *)(v3 + 124)](a1: v3, a2);
  if ( v11 == 2 || v11 == 3 )
    *(_DWORD *)(v3 + 4) = 666;
  if ( v11 != 0 && v11 != 2 )
  {
    if ( v11 == 1 )
    {
      if ( a2 == 1 )
      {
        _tr_align(a1: v3);
      }
      else
      {
        _tr_stored_block(a1: v3, a2: 0, a3: 0, a4: 0);
        if ( a2 == 3 )
        {
          *(_WORD *)(*(_DWORD *)(v3 + 60) + 2 * *(_DWORD *)(v3 + 68) - 2) = 0;
          memset(*(void **)(v3 + 60), 0, 2 * *(_DWORD *)(v3 + 68) - 2);
        }
      }
      sub_10098C90(a1);
      if ( *(_DWORD *)(a1 + 16) == 0 )
      {
        *(_DWORD *)(v3 + 32) = -1;
        return 0;
      }
    }
    goto LABEL_45;
  }
  if ( *(_DWORD *)(a1 + 16) == 0 )
    *(_DWORD *)(v3 + 32) = -1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10098C60
// Name: sub_10098C60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10098C60(int a1, __int16 a2)
{
  int v3; // esi
  int v4; // edx

  *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = HIBYTE(a2);
  v3 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(a1 + 20) + 1;
  *(_DWORD *)(a1 + 20) = v4;
  *(_BYTE *)(v4 + v3) = a2;
  ++*(_DWORD *)(a1 + 20);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x10098C90
// Name: sub_10098C90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_10098C90(int a1)
{
  _DWORD *result; // eax
  int v2; // esi
  unsigned int v3; // edx
  int v4; // ecx
  int v5; // ecx
  unsigned int v6; // edi

  result = (_DWORD *)a1;
  v2 = *(_DWORD *)(a1 + 28);
  v3 = *(_DWORD *)(v2 + 20);
  if ( v3 > *(_DWORD *)(a1 + 16) )
    v3 = *(_DWORD *)(a1 + 16);
  if ( v3 != 0 )
  {
    qmemcpy(*(void **)(a1 + 12), *(const void **)(v2 + 16), v3);
    v4 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 12) += v3;
    *(_DWORD *)(v4 + 16) += v3;
    v5 = *(_DWORD *)(a1 + 28);
    v6 = *(_DWORD *)(a1 + 16) - v3;
    *(_DWORD *)(a1 + 20) += v3;
    *(_DWORD *)(a1 + 16) = v6;
    *(_DWORD *)(v5 + 20) -= v3;
    result = *(_DWORD **)(a1 + 28);
    if ( result[5] == 0 )
      result[4] = result[2];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10098D10
// Name: _deflateEnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl deflateEnd(int a1)
{
  int v1; // eax
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // edx

  if ( a1 == 0 )
    return -2;
  v1 = *(_DWORD *)(a1 + 28);
  if ( v1 == 0 )
    return -2;
  v2 = *(_DWORD *)(v1 + 4);
  if ( v2 != 42 && v2 != 113 && v2 != 666 )
    return -2;
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 != 0 )
    (*(void (__cdecl **)(_DWORD, int))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v3);
  v4 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v4 + 60) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v4 + 60));
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 28) + 56) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(
      a1: *(_DWORD *)(a1 + 40),
      a2: *(_DWORD *)(*(_DWORD *)(a1 + 28) + 56));
  v5 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v5 + 48) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v5 + 48));
  (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(a1 + 28));
  *(_DWORD *)(a1 + 28) = 0;
  return v2 != 113 ? 0 : 0xFD;
}

//------------------------------------------------------------------------------
// Address: 0x10098DC0
// Name: sub_10098DC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10098DC0(int a1)
{
  int v1; // ecx
  int v2; // eax
  int v3; // ecx

  v1 = *(_DWORD *)(a1 + 68);
  *(_DWORD *)(a1 + 52) = 2 * *(_DWORD *)(a1 + 36);
  *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * v1 - 2) = 0;
  memset(*(void **)(a1 + 60), 0, 2 * *(_DWORD *)(a1 + 68) - 2);
  v2 = 6 * *(_DWORD *)(a1 + 124);
  *(_DWORD *)(a1 + 120) = (unsigned __int16)word_1010F1D2[v2];
  *(_DWORD *)(a1 + 132) = (unsigned __int16)word_1010F1D0[v2];
  *(_DWORD *)(a1 + 136) = (unsigned __int16)word_1010F1D4[v2];
  v3 = (unsigned __int16)word_1010F1D6[v2];
  *(_DWORD *)(a1 + 100) = 0;
  *(_DWORD *)(a1 + 84) = 0;
  *(_DWORD *)(a1 + 108) = 0;
  *(_DWORD *)(a1 + 96) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 116) = v3;
  *(_DWORD *)(a1 + 112) = 2;
  *(_DWORD *)(a1 + 88) = 2;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10098E60
// Name: sub_10098E60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10098E60(int *a1, int a2)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // ecx
  bool v5; // zf
  int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // eax
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // [esp-14h] [ebp-1Ch]
  int v17; // [esp-14h] [ebp-1Ch]
  int v18; // [esp-14h] [ebp-1Ch]

  v2 = 0xFFFF;
  if ( (unsigned int)(a1[3] - 5) < 0xFFFF )
    v2 = a1[3] - 5;
  while ( 1 )
  {
    v3 = a1[27];
    if ( v3 <= 1 )
    {
      sub_10098FB0(a1);
      v3 = a1[27];
      if ( v3 == 0 )
        break;
    }
    v4 = a1[25];
    a1[27] = 0;
    v5 = v3 + v4 == 0;
    a1[25] = v3 + v4;
    v6 = a1[21];
    v7 = a1[25];
    v8 = v6 + v2;
    if ( !v5 && v7 < v8
      || ((a1[25] = v8, a1[27] = v7 - v8, v6 < 0) ? (v9 = 0) : (v9 = v6 + a1[12]),
          _tr_flush_block(a1, a2: v9, a3: v2, a4: 0),
          v16 = *a1,
          a1[21] = a1[25],
          sub_10098C90(a1: v16),
          *(_DWORD *)(*a1 + 16) != 0) )
    {
      v10 = a1[21];
      v11 = a1[25] - v10;
      if ( v11 < a1[9] - 262 )
        continue;
      v12 = v10 < 0 ? 0 : v10 + a1[12];
      _tr_flush_block(a1, a2: v12, a3: v11, a4: 0);
      v17 = *a1;
      a1[21] = a1[25];
      sub_10098C90(a1: v17);
      if ( *(_DWORD *)(*a1 + 16) != 0 )
        continue;
    }
    return 0;
  }
  if ( a2 == 0 )
    return 0;
  v14 = a1[21];
  if ( v14 < 0 )
    v15 = 0;
  else
    v15 = v14 + a1[12];
  _tr_flush_block(a1, a2: v15, a3: a1[25] - v14, a4: a2 == 4);
  v18 = *a1;
  a1[21] = a1[25];
  sub_10098C90(a1: v18);
  if ( *(_DWORD *)(*a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x10098FB0
// Name: sub_10098FB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10098FB0(int a1)
{
  unsigned int v1; // ebp
  unsigned int v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // esi
  int v8; // ecx
  _WORD *v9; // ecx
  __int16 v10; // ax
  unsigned int v11; // esi
  _WORD *v12; // ecx
  __int16 v13; // ax
  int result; // eax
  unsigned int v15; // esi
  int v16; // ecx
  unsigned __int8 *v17; // edi
  int v18; // eax

  v1 = *(_DWORD *)(a1 + 36);
  do
  {
    v2 = *(_DWORD *)(a1 + 100);
    v3 = *(_DWORD *)(a1 + 108);
    v4 = *(_DWORD *)(a1 + 52) - v2 - v3;
    if ( v4 != 0 )
    {
      if ( v4 == -1 )
      {
        v4 = -2;
        goto LABEL_20;
      }
    }
    else if ( v2 == 0 && v3 == 0 )
    {
      v4 = v1;
      goto LABEL_20;
    }
    if ( v2 >= *(_DWORD *)(a1 + 36) + v1 - 262 )
    {
      qmemcpy(*(void **)(a1 + 48), (const void *)(*(_DWORD *)(a1 + 48) + v1), v1);
      v5 = *(_DWORD *)(a1 + 84);
      v6 = *(_DWORD *)(a1 + 100) - v1;
      *(_DWORD *)(a1 + 104) -= v1;
      v7 = *(_DWORD *)(a1 + 68);
      *(_DWORD *)(a1 + 100) = v6;
      v8 = *(_DWORD *)(a1 + 60);
      *(_DWORD *)(a1 + 84) = v5 - v1;
      v9 = (_WORD *)(v8 + 2 * v7);
      do
      {
        if ( (unsigned __int16)*--v9 < v1 )
          v10 = 0;
        else
          v10 = *v9 - v1;
        --v7;
        *v9 = v10;
      }
      while ( v7 != 0 );
      v11 = v1;
      v12 = (_WORD *)(*(_DWORD *)(a1 + 56) + 2 * v1);
      do
      {
        if ( (unsigned __int16)*--v12 < v1 )
          v13 = 0;
        else
          v13 = *v12 - v1;
        --v11;
        *v12 = v13;
      }
      while ( v11 != 0 );
      v4 += v1;
    }
LABEL_20:
    result = *(_DWORD *)a1;
    if ( *(_DWORD *)(*(_DWORD *)a1 + 4) == 0 )
      break;
    result = sub_100990E0(a1: result, a2: *(_DWORD *)(a1 + 48) + *(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 108), a3: v4);
    v15 = result + *(_DWORD *)(a1 + 108);
    *(_DWORD *)(a1 + 108) = v15;
    if ( v15 >= 3 )
    {
      v16 = *(_DWORD *)(a1 + 80);
      v17 = (unsigned __int8 *)(*(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 48));
      v18 = *v17;
      *(_DWORD *)(a1 + 64) = v18;
      result = *(_DWORD *)(a1 + 76) & (v17[1] ^ (v18 << v16));
      *(_DWORD *)(a1 + 64) = result;
    }
    if ( v15 >= 0x106 )
      break;
    result = *(_DWORD *)(*(_DWORD *)a1 + 4);
  }
  while ( result != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100990E0
// Name: sub_100990E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_100990E0(_DWORD *a1, void *a2, unsigned int a3)
{
  unsigned int v3; // ebx
  int v5; // eax

  v3 = a1[1];
  if ( v3 > a3 )
    v3 = a3;
  if ( v3 == 0 )
    return 0;
  a1[1] -= v3;
  if ( *(_DWORD *)(a1[7] + 24) == 0 )
    a1[12] = adler32(a1: a1[12], a2: *a1, a3: v3);
  qmemcpy(a2, (const void *)*a1, v3);
  v5 = a1[2];
  *a1 += v3;
  a1[2] = v3 + v5;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10099160
// Name: sub_10099160
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10099160(int a1, int a2)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  char v7; // cl
  __int16 v8; // ax
  unsigned __int16 v9; // ax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // edx
  BOOL v14; // ebp
  unsigned int v15; // ecx
  int v16; // eax
  int v17; // edi
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  unsigned int v22; // ecx
  unsigned __int8 *v23; // edx
  int v24; // ecx
  int v25; // eax
  unsigned __int8 v26; // al
  int v27; // ecx
  int v28; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // [esp-14h] [ebp-2Ch]
  int v33; // [esp-14h] [ebp-2Ch]

  v2 = 0;
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 108);
    if ( v3 < 0x106 )
    {
      sub_10098FB0(a1);
      v3 = *(_DWORD *)(a1 + 108);
      if ( v3 < 0x106 && a2 == 0 )
        return 0;
      if ( v3 == 0 )
        break;
    }
    if ( v3 >= 3 )
    {
      v4 = *(_DWORD *)(a1 + 100);
      v5 = *(_DWORD *)(a1 + 60);
      v6 = *(_DWORD *)(a1 + 76)
         & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 48) + v4 + 2)
          ^ (*(_DWORD *)(a1 + 64) << *(_DWORD *)(a1 + 80)));
      HIWORD(v2) = 0;
      *(_DWORD *)(a1 + 64) = v6;
      LOWORD(v2) = *(_WORD *)(v5 + 2 * v6);
      *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * (v4 & *(_DWORD *)(a1 + 44))) = v2;
      *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * *(_DWORD *)(a1 + 64)) = *(_WORD *)(a1 + 100);
    }
    if ( v2 != 0
      && *(_DWORD *)(a1 + 100) - v2 <= (unsigned int)(*(_DWORD *)(a1 + 36) - 262)
      && *(_DWORD *)(a1 + 128) != 2 )
    {
      *(_DWORD *)(a1 + 88) = sub_100994A0(a1, a2: v2);
    }
    if ( *(_DWORD *)(a1 + 88) < 3u )
    {
      v26 = *(_BYTE *)(*(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 48));
      *(_WORD *)(*(_DWORD *)(a1 + 5788) + 2 * *(_DWORD *)(a1 + 5784)) = 0;
      *(_BYTE *)(*(_DWORD *)(a1 + 5776) + (*(_DWORD *)(a1 + 5784))++) = v26;
      ++*(_WORD *)(a1 + 4 * v26 + 140);
      v14 = *(_DWORD *)(a1 + 5784) == *(_DWORD *)(a1 + 5780) - 1;
      --*(_DWORD *)(a1 + 108);
    }
    else
    {
      v7 = *(_DWORD *)(a1 + 88);
      v8 = *(_WORD *)(a1 + 100) - *(_WORD *)(a1 + 104);
      *(_WORD *)(*(_DWORD *)(a1 + 5788) + 2 * *(_DWORD *)(a1 + 5784)) = v8;
      v9 = v8 - 1;
      *(_BYTE *)(*(_DWORD *)(a1 + 5776) + (*(_DWORD *)(a1 + 5784))++) = v7 - 3;
      v10 = (unsigned __int8)_length_code[(unsigned __int8)(v7 - 3)];
      ++*(_WORD *)(a1 + 4 * v10 + 1168);
      if ( v9 >= 0x100u )
        v11 = (unsigned __int8)byte_1010F998[v9 >> 7];
      else
        v11 = (unsigned __int8)_dist_code[v9];
      ++*(_WORD *)(a1 + 4 * v11 + 2432);
      v12 = *(_DWORD *)(a1 + 88);
      v13 = *(_DWORD *)(a1 + 120);
      v14 = *(_DWORD *)(a1 + 5784) == *(_DWORD *)(a1 + 5780) - 1;
      v15 = *(_DWORD *)(a1 + 108) - v12;
      *(_DWORD *)(a1 + 108) = v15;
      if ( v12 > v13 || v15 < 3 )
      {
        v22 = v12 + *(_DWORD *)(a1 + 100);
        v23 = (unsigned __int8 *)(v22 + *(_DWORD *)(a1 + 48));
        *(_DWORD *)(a1 + 100) = v22;
        v24 = *(_DWORD *)(a1 + 80);
        *(_DWORD *)(a1 + 88) = 0;
        v25 = *v23;
        *(_DWORD *)(a1 + 64) = v25;
        *(_DWORD *)(a1 + 64) = *(_DWORD *)(a1 + 76) & (v23[1] ^ (v25 << v24));
        goto LABEL_24;
      }
      *(_DWORD *)(a1 + 88) = v12 - 1;
      do
      {
        v16 = *(_DWORD *)(a1 + 48);
        v17 = *(_DWORD *)(a1 + 64);
        v18 = *(_DWORD *)(a1 + 100) + 1;
        *(_DWORD *)(a1 + 100) = v18;
        v19 = *(_DWORD *)(a1 + 60);
        v20 = *(_DWORD *)(a1 + 76) & ((v17 << *(_DWORD *)(a1 + 80)) ^ *(unsigned __int8 *)(v18 + v16 + 2));
        HIWORD(v2) = 0;
        *(_DWORD *)(a1 + 64) = v20;
        LOWORD(v2) = *(_WORD *)(v19 + 2 * v20);
        *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * (*(_DWORD *)(a1 + 44) & v18)) = v2;
        *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * *(_DWORD *)(a1 + 64)) = *(_WORD *)(a1 + 100);
        v21 = *(_DWORD *)(a1 + 88) - 1;
        *(_DWORD *)(a1 + 88) = v21;
      }
      while ( v21 != 0 );
    }
    ++*(_DWORD *)(a1 + 100);
LABEL_24:
    if ( v14 )
    {
      v27 = *(_DWORD *)(a1 + 84);
      v28 = v27 < 0 ? 0 : v27 + *(_DWORD *)(a1 + 48);
      _tr_flush_block(a1, a2: v28, a3: *(_DWORD *)(a1 + 100) - v27, a4: 0);
      v32 = *(_DWORD *)a1;
      *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 100);
      sub_10098C90(a1: v32);
      if ( *(_DWORD *)(*(_DWORD *)a1 + 16) == 0 )
        return 0;
    }
  }
  v30 = *(_DWORD *)(a1 + 84);
  if ( v30 < 0 )
    v31 = 0;
  else
    v31 = v30 + *(_DWORD *)(a1 + 48);
  _tr_flush_block(a1, a2: v31, a3: *(_DWORD *)(a1 + 100) - v30, a4: a2 == 4);
  v33 = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 100);
  sub_10098C90(a1: v33);
  if ( *(_DWORD *)(*(_DWORD *)a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x100994A0
// Name: sub_100994A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_100994A0(_DWORD *a1, int a2)
{
  int v3; // esi
  unsigned int v4; // edx
  unsigned int v5; // ebp
  unsigned int v6; // eax
  _BYTE *v7; // ecx
  _BYTE *v8; // ebx
  _BYTE *v10; // edx
  char v11; // al
  _BYTE *v12; // edx
  _BYTE *v13; // ecx
  _BYTE *v14; // edx
  char v15; // al
  _BYTE *v16; // edx
  char v17; // al
  _BYTE *v18; // edx
  char v19; // al
  _BYTE *v20; // edx
  char v21; // al
  _BYTE *v22; // edx
  char v23; // al
  _BYTE *v24; // edx
  char v25; // al
  _BYTE *v26; // edx
  char v27; // al
  _BYTE *v28; // edx
  char v29; // al
  _BYTE *v30; // edx
  int v31; // edx
  unsigned int result; // eax
  char v33; // [esp+13h] [ebp-11h]
  unsigned int v34; // [esp+14h] [ebp-10h]
  int v35; // [esp+18h] [ebp-Ch]
  unsigned int v36; // [esp+1Ch] [ebp-8h]
  unsigned int v37; // [esp+20h] [ebp-4h]
  char v38; // [esp+28h] [ebp+4h]

  v3 = a1[9];
  v4 = a1[25];
  v5 = a1[28];
  v34 = a1[29];
  v6 = a1[34];
  v7 = (_BYTE *)(v4 + a1[12]);
  v35 = v6;
  if ( v4 <= v3 - 262 )
    v36 = 0;
  else
    v36 = v4 - v3 + 262;
  v8 = v7 + 258;
  v38 = v7[v5 - 1];
  v33 = v7[v5];
  if ( v5 >= a1[33] )
    v34 >>= 2;
  v37 = a1[27];
  if ( v6 > v37 )
    v35 = a1[27];
  do
  {
    v10 = (_BYTE *)(a2 + a1[12]);
    if ( v10[v5] == v33 && v10[v5 - 1] == v38 && *v10 == *v7 )
    {
      v11 = v10[1];
      v12 = v10 + 1;
      if ( v11 == v7[1] )
      {
        v13 = v7 + 2;
        v14 = v12 + 1;
        do
        {
          v15 = *++v13;
          v16 = v14 + 1;
          if ( v15 != *v16 )
            break;
          v17 = *++v13;
          v18 = v16 + 1;
          if ( v17 != *v18 )
            break;
          v19 = *++v13;
          v20 = v18 + 1;
          if ( v19 != *v20 )
            break;
          v21 = *++v13;
          v22 = v20 + 1;
          if ( v21 != *v22 )
            break;
          v23 = *++v13;
          v24 = v22 + 1;
          if ( v23 != *v24 )
            break;
          v25 = *++v13;
          v26 = v24 + 1;
          if ( v25 != *v26 )
            break;
          v27 = *++v13;
          v28 = v26 + 1;
          if ( v27 != *v28 )
            break;
          v29 = *++v13;
          v14 = v28 + 1;
          if ( v29 != *v14 )
            break;
        }
        while ( v13 < v8 );
        v30 = v13;
        v7 = v8 - 258;
        v31 = v30 - v8 + 258;
        if ( v31 > (int)v5 )
        {
          a1[26] = a2;
          v5 = v31;
          if ( v31 >= v35 )
            break;
          v38 = v7[v31 - 1];
          v33 = v7[v31];
        }
      }
    }
    a2 = *(unsigned __int16 *)(a1[14] + 2 * (a2 & a1[11]));
    if ( (unsigned __int16)a2 <= v36 )
      break;
    --v34;
  }
  while ( v34 != 0 );
  result = v37;
  if ( v5 <= v37 )
    return v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10099610
// Name: sub_10099610
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10099610(_DWORD *a1, int a2)
{
  int v3; // edi
  unsigned int v4; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ebp
  __int16 v14; // ax
  unsigned __int16 v15; // ax
  int v16; // eax
  int v17; // eax
  BOOL v18; // ebx
  unsigned int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // eax
  int v26; // eax
  unsigned __int8 v28; // al
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  int v32; // edx
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // [esp-14h] [ebp-2Ch]
  int v38; // [esp-14h] [ebp-2Ch]
  int v39; // [esp-14h] [ebp-2Ch]
  unsigned __int8 v40; // [esp+1Ch] [ebp+4h]
  unsigned __int8 v41; // [esp+20h] [ebp+8h]

  v3 = 0;
  while ( 1 )
  {
    v4 = a1[27];
    if ( v4 < 0x106 )
    {
      sub_10098FB0((int)a1);
      v4 = a1[27];
      if ( v4 < 0x106 && a2 == 0 )
        return 0;
      if ( v4 == 0 )
        break;
    }
    if ( v4 >= 3 )
    {
      v6 = a1[25];
      v7 = a1[15];
      v8 = a1[19] & (*(unsigned __int8 *)(a1[12] + v6 + 2) ^ (a1[16] << a1[20]));
      HIWORD(v3) = 0;
      a1[16] = v8;
      LOWORD(v3) = *(_WORD *)(v7 + 2 * v8);
      *(_WORD *)(a1[14] + 2 * (v6 & a1[11])) = v3;
      *(_WORD *)(a1[15] + 2 * a1[16]) = *((_WORD *)a1 + 50);
    }
    v9 = a1[22];
    v10 = a1[26];
    a1[28] = v9;
    a1[23] = v10;
    a1[22] = 2;
    if ( v3 != 0 && v9 < a1[30] && a1[25] - v3 <= (unsigned int)(a1[9] - 262) )
    {
      if ( a1[32] != 2 )
        a1[22] = sub_100994A0(a1, a2: v3);
      v11 = a1[22];
      if ( v11 <= 5 && (a1[32] == 1 || v11 == 3 && (unsigned int)(a1[25] - a1[26]) > 0x1000) )
        a1[22] = 2;
    }
    v12 = a1[28];
    if ( v12 < 3 || a1[22] > v12 )
    {
      if ( a1[24] != 0 )
      {
        v28 = *(_BYTE *)(a1[25] + a1[12] - 1);
        *(_WORD *)(a1[1447] + 2 * a1[1446]) = 0;
        *(_BYTE *)(a1[1444] + a1[1446]++) = v28;
        ++LOWORD(a1[v28 + 35]);
        if ( a1[1446] == a1[1445] - 1 )
        {
          v29 = a1[21];
          if ( v29 < 0 )
            v30 = 0;
          else
            v30 = v29 + a1[12];
          _tr_flush_block(a1, a2: v30, a3: a1[25] - v29, a4: 0);
          v38 = *a1;
          a1[21] = a1[25];
          sub_10098C90(a1: v38);
        }
        v31 = a1[27] - 1;
        ++a1[25];
        v32 = *a1;
        a1[27] = v31;
        v26 = *(_DWORD *)(v32 + 16);
        goto LABEL_32;
      }
      v33 = a1[25] + 1;
      v34 = a1[27] - 1;
      a1[24] = 1;
      a1[25] = v33;
      a1[27] = v34;
    }
    else
    {
      v13 = a1[25] + a1[27] - 3;
      v14 = a1[25] - *((_WORD *)a1 + 46) - 1;
      v40 = *((_BYTE *)a1 + 112) - 3;
      *(_WORD *)(a1[1447] + 2 * a1[1446]) = v14;
      v15 = v14 - 1;
      *(_BYTE *)(a1[1444] + a1[1446]++) = v40;
      ++LOWORD(a1[(unsigned __int8)_length_code[v40] + 292]);
      if ( v15 >= 0x100u )
        v16 = (unsigned __int8)byte_1010F998[v15 >> 7];
      else
        v16 = (unsigned __int8)_dist_code[v15];
      ++LOWORD(a1[v16 + 608]);
      v17 = a1[28];
      v18 = a1[1446] == a1[1445] - 1;
      a1[27] += 1 - v17;
      a1[28] = v17 - 2;
      do
      {
        v19 = a1[25] + 1;
        a1[25] = v19;
        if ( v19 <= v13 )
        {
          v20 = a1[15];
          v21 = a1[19] & (*(unsigned __int8 *)(a1[12] + v19 + 2) ^ (a1[16] << a1[20]));
          HIWORD(v3) = 0;
          a1[16] = v21;
          LOWORD(v3) = *(_WORD *)(v20 + 2 * v21);
          *(_WORD *)(a1[14] + 2 * (v19 & a1[11])) = v3;
          *(_WORD *)(a1[15] + 2 * a1[16]) = *((_WORD *)a1 + 50);
        }
        v22 = a1[28] - 1;
        a1[28] = v22;
      }
      while ( v22 != 0 );
      v23 = a1[25] + 1;
      a1[24] = 0;
      a1[22] = 2;
      a1[25] = v23;
      if ( v18 )
      {
        v24 = a1[21];
        if ( v24 < 0 )
          v25 = 0;
        else
          v25 = v24 + a1[12];
        _tr_flush_block(a1, a2: v25, a3: v23 - v24, a4: 0);
        v37 = *a1;
        a1[21] = a1[25];
        sub_10098C90(a1: v37);
        v26 = *(_DWORD *)(*a1 + 16);
LABEL_32:
        if ( v26 == 0 )
          return 0;
      }
    }
  }
  if ( a1[24] != 0 )
  {
    v41 = *(_BYTE *)(a1[25] + a1[12] - 1);
    *(_WORD *)(a1[1447] + 2 * a1[1446]) = 0;
    *(_BYTE *)(a1[1444] + a1[1446]++) = v41;
    ++LOWORD(a1[v41 + 35]);
    a1[24] = 0;
  }
  v35 = a1[21];
  if ( v35 < 0 )
    v36 = 0;
  else
    v36 = v35 + a1[12];
  _tr_flush_block(a1, a2: v36, a3: a1[25] - v35, a4: a2 == 4);
  v39 = *a1;
  a1[21] = a1[25];
  sub_10098C90(a1: v39);
  if ( *(_DWORD *)(*a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x10099A40
// Name: _inflateReset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateReset(_DWORD *a1)
{
  _DWORD *v1; // ecx

  if ( a1 == nullptr )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( v1 == nullptr )
    return -2;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  *v1 = v1[3] != 0 ? 7 : 0;
  inflate_blocks_reset(a1: *(_DWORD *)(a1[7] + 20), a2: a1, a3: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10099A90
// Name: _inflateEnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateEnd(_DWORD *a1)
{
  int v1; // eax
  int v2; // eax

  if ( a1 == nullptr )
    return -2;
  v1 = a1[7];
  if ( v1 == 0 || a1[9] == 0 )
    return -2;
  v2 = *(_DWORD *)(v1 + 20);
  if ( v2 != 0 )
    inflate_blocks_free(a1: v2, a2: a1);
  ((void (__cdecl *)(_DWORD, _DWORD))a1[9])(a1: a1[10], a2: a1[7]);
  a1[7] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10099AE0
// Name: _inflateInit2_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateInit2_(_DWORD *a1, int a2, _BYTE *a3, int a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // ecx

  if ( a3 == nullptr || *a3 != a113_0[0] || a4 != 56 )
    return -6;
  if ( a1 == nullptr )
    return -2;
  v5 = a1[8];
  a1[6] = 0;
  if ( v5 == 0 )
  {
    a1[8] = zcalloc;
    a1[10] = 0;
  }
  if ( a1[9] == 0 )
    a1[9] = zcfree;
  v6 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1, a3: 24);
  a1[7] = v6;
  if ( v6 == 0 )
    return -4;
  v7 = a2;
  *(_DWORD *)(v6 + 20) = 0;
  *(_DWORD *)(a1[7] + 12) = 0;
  if ( a2 < 0 )
  {
    v7 = -a2;
    *(_DWORD *)(a1[7] + 12) = 1;
  }
  if ( v7 < 8 || v7 > 15 )
  {
    inflateEnd(a1);
    return -2;
  }
  else
  {
    *(_DWORD *)(a1[7] + 16) = v7;
    *(_DWORD *)(a1[7] + 20) = inflate_blocks_new(a1, a2: *(_DWORD *)(a1[7] + 12) == 0 ? adler32 : nullptr, a3: 1 << v7);
    if ( *(_DWORD *)(a1[7] + 20) != 0 )
    {
      inflateReset(a1);
      return 0;
    }
    else
    {
      inflateEnd(a1);
      return -4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099BF0
// Name: _inflateInit_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateInit_(_DWORD *a1, _BYTE *a2, int a3)
{
  return inflateInit2_(a1, a2: 15, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10099C10
// Name: _inflate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate(unsigned __int8 **a1, int a2)
{
  int v2; // edi
  unsigned int v3; // ebx
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // eax
  int v7; // ecx
  unsigned __int8 *v8; // edx
  unsigned __int8 *v9; // edx
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // ebx
  int v12; // ecx
  unsigned __int8 *v13; // eax
  int v14; // eax
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // edx
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // ecx
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // ecx
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // ecx
  int v24; // edx
  unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // eax
  unsigned __int8 *v27; // edx
  unsigned __int8 *v28; // eax
  unsigned __int8 *v30; // ecx
  unsigned __int8 *v31; // ecx
  unsigned __int8 *v32; // eax
  unsigned __int8 *v33; // edx
  unsigned __int8 *v34; // edx
  unsigned __int8 *v35; // eax
  unsigned __int8 *v36; // ecx
  unsigned __int8 *v37; // eax
  unsigned __int8 *v38; // ecx
  int v39; // edx
  unsigned __int8 *v40; // eax
  unsigned __int8 *v41; // eax
  unsigned __int8 *v42; // eax
  unsigned int v43; // [esp+18h] [ebp+8h]

  if ( a1 == nullptr || a1[7] == nullptr || *a1 == nullptr )
    return -2;
  v2 = -5;
  v3 = a2 != 4 ? 0 : 0xFFFFFFFB;
  v43 = v3;
  while ( 2 )
  {
    v4 = a1[7];
    switch ( *(_DWORD *)v4 )
    {
      case 0:
        v5 = a1[1];
        if ( v5 == nullptr )
          return v2;
        a1[1] = v5 - 1;
        v2 = v3;
        ++a1[2];
        *((_DWORD *)v4 + 1) = **a1;
        v6 = a1[7];
        v7 = *((_DWORD *)v6 + 1) & 0xF;
        ++*a1;
        if ( (_BYTE)v7 != 8 )
        {
          *(_DWORD *)v6 = 13;
          v8 = a1[7];
          a1[6] = (unsigned __int8 *)aUnknownCompres;
          *((_DWORD *)v8 + 1) = 5;
          continue;
        }
        if ( (unsigned int)((*((_DWORD *)v6 + 1) >> 4) + 8) > *((_DWORD *)v6 + 4) )
        {
          *(_DWORD *)v6 = 13;
          v9 = a1[7];
          a1[6] = (unsigned __int8 *)aInvalidWindowS;
          *((_DWORD *)v9 + 1) = 5;
          continue;
        }
        *(_DWORD *)v6 = 1;
LABEL_12:
        v10 = a1[1];
        if ( v10 == nullptr )
          return v2;
        a1[1] = v10 - 1;
        v2 = v3;
        v11 = a1[7];
        ++a1[2];
        v12 = *(*a1)++;
        if ( (v12 + (*((_DWORD *)v11 + 1) << 8)) % 0x1Fu != 0 )
        {
          *(_DWORD *)v11 = 13;
          v13 = a1[7];
          v3 = v43;
          a1[6] = (unsigned __int8 *)aIncorrectHeade;
          *((_DWORD *)v13 + 1) = 5;
          continue;
        }
        if ( (v12 & 0x20) == 0 )
        {
          *(_DWORD *)v11 = 7;
          v3 = v43;
          continue;
        }
        v3 = v43;
        *(_DWORD *)a1[7] = 2;
LABEL_35:
        v28 = a1[1];
        if ( v28 == nullptr )
          return v2;
        v30 = *a1;
        ++a1[2];
        a1[1] = v28 - 1;
        v2 = v3;
        *((_DWORD *)a1[7] + 2) = *v30 << 24;
        v31 = a1[7];
        ++*a1;
        *(_DWORD *)v31 = 3;
LABEL_38:
        v32 = a1[1];
        if ( v32 == nullptr )
          return v2;
        v33 = *a1;
        a1[1] = v32 - 1;
        ++a1[2];
        v2 = v3;
        *((_DWORD *)a1[7] + 2) += *v33 << 16;
        v34 = a1[7];
        ++*a1;
        *(_DWORD *)v34 = 4;
LABEL_41:
        v35 = a1[1];
        if ( v35 == nullptr )
          return v2;
        v36 = *a1;
        a1[1] = v35 - 1;
        ++a1[2];
        v2 = v3;
        *((_DWORD *)a1[7] + 2) += *v36 << 8;
        ++*a1;
        *(_DWORD *)a1[7] = 5;
LABEL_44:
        v37 = a1[1];
        if ( v37 == nullptr )
          return v2;
        v38 = *a1;
        v39 = (int)(a1[2] + 1);
        a1[1] = v37 - 1;
        v40 = a1[7];
        a1[2] = (unsigned __int8 *)v39;
        *((_DWORD *)v40 + 2) += *v38;
        ++*a1;
        v41 = a1[7];
        a1[12] = *((unsigned __int8 **)v41 + 2);
        *(_DWORD *)v41 = 6;
        return 2;
      case 1:
        goto LABEL_12;
      case 2:
        goto LABEL_35;
      case 3:
        goto LABEL_38;
      case 4:
        goto LABEL_41;
      case 5:
        goto LABEL_44;
      case 6:
        *(_DWORD *)a1[7] = 13;
        v42 = a1[7];
        a1[6] = (unsigned __int8 *)aNeedDictionary;
        *((_DWORD *)v42 + 1) = 0;
        return -2;
      case 7:
        v14 = inflate_blocks(a1: *((_DWORD *)v4 + 5), a2: a1, a3: v2);
        v2 = v14;
        if ( v14 == -3 )
        {
          *(_DWORD *)a1[7] = 13;
          *((_DWORD *)a1[7] + 1) = 0;
        }
        else
        {
          if ( v14 == 0 )
            v2 = v3;
          if ( v2 != 1 )
            return v2;
          v2 = v3;
          inflate_blocks_reset(a1: *((_DWORD *)a1[7] + 5), a2: a1, a3: a1[7] + 4);
          v15 = a1[7];
          if ( *((_DWORD *)v15 + 3) != 0 )
          {
            *(_DWORD *)v15 = 12;
          }
          else
          {
            *(_DWORD *)v15 = 8;
LABEL_25:
            v16 = a1[1];
            if ( v16 == nullptr )
              return v2;
            v17 = a1[7];
            a1[1] = v16 - 1;
            ++a1[2];
            v2 = v3;
            *((_DWORD *)v17 + 2) = *(*a1)++ << 24;
            *(_DWORD *)a1[7] = 9;
LABEL_27:
            v18 = a1[1];
            if ( v18 == nullptr )
              return v2;
            v19 = *a1;
            ++a1[2];
            a1[1] = v18 - 1;
            v2 = v3;
            *((_DWORD *)a1[7] + 2) += *v19 << 16;
            ++*a1;
            *(_DWORD *)a1[7] = 10;
LABEL_29:
            v20 = a1[1];
            if ( v20 == nullptr )
              return v2;
            v21 = *a1;
            ++a1[2];
            a1[1] = v20 - 1;
            v2 = v3;
            *((_DWORD *)a1[7] + 2) += *v21 << 8;
            ++*a1;
            *(_DWORD *)a1[7] = 11;
LABEL_31:
            v22 = a1[1];
            if ( v22 == nullptr )
              return v2;
            v23 = *a1;
            v24 = (int)(a1[2] + 1);
            a1[1] = v22 - 1;
            v25 = a1[7];
            a1[2] = (unsigned __int8 *)v24;
            v2 = v3;
            *((_DWORD *)v25 + 2) += *v23;
            ++*a1;
            v26 = a1[7];
            if ( *((_DWORD *)v26 + 1) == *((_DWORD *)v26 + 2) )
            {
              *(_DWORD *)a1[7] = 12;
              return 1;
            }
            *(_DWORD *)v26 = 13;
            v27 = a1[7];
            a1[6] = (unsigned __int8 *)aIncorrectDataC;
            *((_DWORD *)v27 + 1) = 5;
          }
        }
        continue;
      case 8:
        goto LABEL_25;
      case 9:
        goto LABEL_27;
      case 0xA:
        goto LABEL_29;
      case 0xB:
        goto LABEL_31;
      case 0xC:
        return 1;
      case 0xD:
        return -3;
      default:
        return -2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A040
// Name: _zcalloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl zcalloc(int a1, unsigned int count, unsigned int size)
{
  return calloc(count, size);
}

//------------------------------------------------------------------------------
// Address: 0x1009A060
// Name: _zcfree
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl zcfree(int a1, void *pMem)
{
  free(pMem);
}

//------------------------------------------------------------------------------
// Address: 0x1009A070
// Name: _adler32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl adler32(unsigned int a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned __int8 *v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // edi
  unsigned int i; // ebx
  int v8; // eax
  unsigned int v9; // ebp
  int v10; // edx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // edi
  int v15; // ecx
  int v16; // edi
  int v17; // ecx
  int v18; // edi
  int v19; // ecx
  int v20; // edi
  int v21; // ecx
  int v22; // edi
  int v23; // ecx
  int v24; // edi
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // edi
  int v29; // ecx
  int v30; // edi
  int v31; // ecx
  int v32; // edi
  int v33; // ecx
  int v34; // edi
  int v35; // ecx
  int v36; // edi
  int v37; // ecx
  int v38; // edi
  int v39; // ecx
  int v40; // edi

  v3 = a2;
  v4 = (unsigned __int16)a1;
  v5 = HIWORD(a1);
  if ( a2 == nullptr )
    return 1;
  for ( i = a3; i != 0; v5 %= 0xFFF1u )
  {
    v8 = i;
    if ( i >= 0x15B0 )
      v8 = 5552;
    i -= v8;
    if ( v8 >= 16 )
    {
      v9 = (unsigned int)v8 >> 4;
      v8 += -16 * ((unsigned int)v8 >> 4);
      do
      {
        v10 = *v3;
        v3 += 16;
        v11 = v10 + v4;
        v12 = v11 + v5;
        v13 = *(v3 - 15) + v11;
        v14 = v13 + v12;
        v15 = *(v3 - 14) + v13;
        v16 = v15 + v14;
        v17 = *(v3 - 13) + v15;
        v18 = v17 + v16;
        v19 = *(v3 - 12) + v17;
        v20 = v19 + v18;
        v21 = *(v3 - 11) + v19;
        v22 = v21 + v20;
        v23 = *(v3 - 10) + v21;
        v24 = v23 + v22;
        v25 = *(v3 - 9) + v23;
        v26 = v25 + v24;
        v27 = *(v3 - 8) + v25;
        v28 = v27 + v26;
        v29 = *(v3 - 7) + v27;
        v30 = v29 + v28;
        v31 = *(v3 - 6) + v29;
        v32 = v31 + v30;
        v33 = *(v3 - 5) + v31;
        v34 = v33 + v32;
        v35 = *(v3 - 4) + v33;
        v36 = v35 + v34;
        v37 = *(v3 - 3) + v35;
        v38 = v37 + v36;
        v39 = *(v3 - 2) + v37;
        v40 = v39 + v38;
        v4 = *(v3 - 1) + v39;
        v5 = v4 + v40;
        --v9;
      }
      while ( v9 != 0 );
    }
    for ( ; v8 != 0; --v8 )
    {
      v4 += *v3++;
      v5 += v4;
    }
    v4 %= 0xFFF1u;
  }
  return v4 | (v5 << 16);
}

//------------------------------------------------------------------------------
// Address: 0x1009A1A0
// Name: __tr_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_init(int a1)
{
  nullsub_4();
  *(_DWORD *)(a1 + 2832) = a1 + 140;
  *(_DWORD *)(a1 + 2856) = a1 + 2676;
  *(_DWORD *)(a1 + 2840) = &off_101378E8;
  *(_DWORD *)(a1 + 2844) = a1 + 2432;
  *(_DWORD *)(a1 + 2852) = &off_101378FC;
  *(_DWORD *)(a1 + 2864) = &unk_10137910;
  *(_WORD *)(a1 + 5808) = 0;
  *(_DWORD *)(a1 + 5812) = 0;
  *(_DWORD *)(a1 + 5804) = 8;
  return sub_1009A220(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1009A210
// Name: nullsub_4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_4()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1009A220
// Name: sub_1009A220
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_WORD *__cdecl sub_1009A220(int a1)
{
  int v1; // ecx
  _WORD *v2; // eax
  _WORD *v3; // eax
  int i; // ecx
  _WORD *result; // eax
  int j; // ecx

  v1 = 286;
  v2 = (_WORD *)(a1 + 140);
  do
  {
    *v2 = 0;
    v2 += 2;
    --v1;
  }
  while ( v1 != 0 );
  v3 = (_WORD *)(a1 + 2432);
  for ( i = 30; i != 0; --i )
  {
    *v3 = 0;
    v3 += 2;
  }
  result = (_WORD *)(a1 + 2676);
  for ( j = 19; j != 0; --j )
  {
    *result = 0;
    result += 2;
  }
  *(_DWORD *)(a1 + 5796) = 0;
  *(_DWORD *)(a1 + 5792) = 0;
  *(_DWORD *)(a1 + 5800) = 0;
  *(_DWORD *)(a1 + 5784) = 0;
  *(_WORD *)(a1 + 1164) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009A290
// Name: __tr_stored_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_stored_block(int a1, int a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  char v8; // bl
  int v9; // ecx
  int v10; // edx

  v4 = *(_DWORD *)(a1 + 5812);
  if ( v4 <= 13 )
  {
    *(_WORD *)(a1 + 5808) |= a4 << v4;
    *(_DWORD *)(a1 + 5812) = v4 + 3;
  }
  else
  {
    v5 = a4 << v4;
    v6 = *(_DWORD *)(a1 + 8);
    *(_WORD *)(a1 + 5808) |= v5;
    *(_BYTE *)(v6 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v7 = *(_DWORD *)(a1 + 8);
    v8 = *(_BYTE *)(a1 + 5809);
    v9 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v9;
    *(_BYTE *)(v9 + v7) = v8;
    v10 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v10 - 13;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)a4 >> (16 - v10);
  }
  return sub_1009BB50(a1, a2, a3, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1009A330
// Name: __tr_align
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_align(int a1)
{
  int v1; // ecx
  char v2; // dl
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  char v8; // dl
  int v9; // ecx
  int result; // eax
  int v11; // ecx
  char v12; // dl
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  char v18; // dl
  int v19; // ecx

  v1 = *(_DWORD *)(a1 + 5812);
  *(_WORD *)(a1 + 5808) |= 2 << v1;
  if ( v1 <= 13 )
  {
    *(_DWORD *)(a1 + 5812) = v1 + 3;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v2 = *(_BYTE *)(a1 + 5809);
    v3 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v3;
    *(_BYTE *)(v3 + *(_DWORD *)(a1 + 8)) = v2;
    ++*(_DWORD *)(a1 + 20);
    v4 = *(_DWORD *)(a1 + 5812);
    *(_DWORD *)(a1 + 5812) = v4 - 13;
    *(_WORD *)(a1 + 5808) = 2u >> (16 - v4);
  }
  v5 = *(_DWORD *)(a1 + 5812);
  if ( v5 <= 9 )
  {
    *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
    *(_DWORD *)(a1 + 5812) = v5 + 7;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 8);
    v7 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
    *(_BYTE *)(v6 + v7) = *(_BYTE *)(a1 + 5808);
    v8 = *(_BYTE *)(a1 + 5809);
    v9 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v9;
    *(_BYTE *)(v9 + *(_DWORD *)(a1 + 8)) = v8;
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) -= 9;
    *(_WORD *)(a1 + 5808) = 0;
  }
  result = sub_1009BA40(a1);
  v11 = *(_DWORD *)(a1 + 5812);
  if ( *(_DWORD *)(a1 + 5804) - v11 + 11 < 9 )
  {
    *(_WORD *)(a1 + 5808) |= 2 << v11;
    if ( v11 <= 13 )
    {
      *(_DWORD *)(a1 + 5812) = v11 + 3;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
      v12 = *(_BYTE *)(a1 + 5809);
      v13 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v13;
      *(_BYTE *)(v13 + *(_DWORD *)(a1 + 8)) = v12;
      ++*(_DWORD *)(a1 + 20);
      v14 = *(_DWORD *)(a1 + 5812);
      *(_DWORD *)(a1 + 5812) = v14 - 13;
      *(_WORD *)(a1 + 5808) = 2u >> (16 - v14);
    }
    v15 = *(_DWORD *)(a1 + 5812);
    if ( v15 <= 9 )
    {
      *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
      *(_DWORD *)(a1 + 5812) = v15 + 7;
    }
    else
    {
      v16 = *(_DWORD *)(a1 + 8);
      v17 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
      *(_BYTE *)(v16 + v17) = *(_BYTE *)(a1 + 5808);
      v18 = *(_BYTE *)(a1 + 5809);
      v19 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v19;
      *(_BYTE *)(v19 + *(_DWORD *)(a1 + 8)) = v18;
      ++*(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 5812) -= 9;
      *(_WORD *)(a1 + 5808) = 0;
    }
    result = sub_1009BA40(a1);
  }
  *(_DWORD *)(a1 + 5804) = 7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009A540
// Name: __tr_flush_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_WORD *__cdecl _tr_flush_block(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // ecx
  int v7; // edi
  bool v8; // zf
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  char v13; // bl
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // ebx
  int v18; // ecx
  int v19; // ebx
  char v20; // al
  int v21; // ecx
  int v22; // ebx
  _WORD *result; // eax
  int v24; // [esp+20h] [ebp+10h]

  v4 = 0;
  if ( *(int *)(a1 + 124) <= 0 )
  {
    v6 = a3 + 5;
LABEL_7:
    v5 = v6;
    goto LABEL_8;
  }
  if ( *(_BYTE *)(a1 + 28) == 2 )
    sub_1009B9A0(a1);
  sub_1009A730(a1, a2: a1 + 2832);
  sub_1009A730(a1, a2: a1 + 2844);
  v4 = sub_1009ACC0(a1);
  v5 = (unsigned int)(*(_DWORD *)(a1 + 5792) + 10) >> 3;
  v6 = (unsigned int)(*(_DWORD *)(a1 + 5796) + 10) >> 3;
  if ( v6 <= v5 )
    goto LABEL_7;
LABEL_8:
  if ( a3 + 4 <= v5 && a2 != 0 )
  {
    v7 = a4;
    _tr_stored_block(a1, a2, a3, a4);
  }
  else
  {
    v7 = a4;
    v8 = v6 == v5;
    v9 = *(_DWORD *)(a1 + 5812);
    if ( v8 )
    {
      v10 = a4 + 2;
      if ( v9 <= 13 )
      {
        *(_WORD *)(a1 + 5808) |= v10 << v9;
        *(_DWORD *)(a1 + 5812) = v9 + 3;
      }
      else
      {
        v11 = v10 << v9;
        v12 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5808) |= v11;
        *(_BYTE *)(v12 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
        v13 = *(_BYTE *)(a1 + 5809);
        v14 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v14;
        *(_BYTE *)(v14 + *(_DWORD *)(a1 + 8)) = v13;
        v15 = *(_DWORD *)(a1 + 5812);
        ++*(_DWORD *)(a1 + 20);
        *(_DWORD *)(a1 + 5812) = v15 - 13;
        *(_WORD *)(a1 + 5808) = (unsigned __int16)v10 >> (16 - v15);
      }
      sub_1009B590(a1, a2: &unk_1010F3A0, a3: &unk_1010F820);
    }
    else
    {
      v16 = a4 + 4;
      if ( v9 <= 13 )
      {
        *(_WORD *)(a1 + 5808) |= v16 << v9;
        *(_DWORD *)(a1 + 5812) = v9 + 3;
      }
      else
      {
        v24 = v4;
        v17 = v16 << v9;
        v18 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5808) |= v17;
        *(_BYTE *)(v18 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
        v19 = *(_DWORD *)(a1 + 8);
        v20 = *(_BYTE *)(a1 + 5809);
        v21 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v21;
        *(_BYTE *)(v21 + v19) = v20;
        v22 = *(_DWORD *)(a1 + 5812);
        ++*(_DWORD *)(a1 + 20);
        v4 = v24;
        *(_DWORD *)(a1 + 5812) = v22 - 13;
        *(_WORD *)(a1 + 5808) = (unsigned __int16)v16 >> (16 - v22);
      }
      sub_1009AE20(a1, a2: *(_DWORD *)(a1 + 2836) + 1, a3: *(_DWORD *)(a1 + 2848) + 1, a4: v4 + 1);
      sub_1009B590(a1, a2: a1 + 140, a3: a1 + 2432);
    }
  }
  result = sub_1009A220(a1);
  if ( v7 != 0 )
    return (_WORD *)sub_1009BAD0(a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009A730
// Name: sub_1009A730
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009A730(_DWORD *a1, int *a2)
{
  int v3; // edi
  int *v4; // eax
  int v5; // ebp
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int i; // ebx
  int v14; // eax
  int v15; // ebx
  int v16; // ebp
  int v17; // edx
  int v18; // ecx
  char v19; // cl
  int v20; // ecx
  int v21; // edx
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]
  int v25; // [esp+1Ch] [ebp+4h]

  v3 = *a2;
  v4 = (int *)a2[2];
  v5 = -1;
  v6 = *v4;
  v7 = v4[3];
  v8 = 0;
  v24 = v7;
  v23 = -1;
  a1[1298] = 0;
  for ( a1[1299] = 573; v8 < v7; ++v8 )
  {
    if ( *(_WORD *)(v3 + 4 * v8) != 0 )
    {
      v23 = v8;
      v9 = a1[1298] + 1;
      v5 = v8;
      a1[1298] = v9;
      a1[v9 + 725] = v8;
      v7 = v24;
      *((_BYTE *)a1 + v8 + 5200) = 0;
    }
    else
    {
      *(_WORD *)(v3 + 4 * v8 + 2) = 0;
    }
  }
  v10 = a1[1298];
  if ( v10 < 2 )
  {
    do
    {
      if ( v5 >= 2 )
        v11 = 0;
      else
        v11 = ++v5;
      v12 = v10 + 1;
      a1[1298] = v12;
      a1[v12 + 725] = v11;
      *(_WORD *)(v3 + 4 * v11) = 1;
      *((_BYTE *)a1 + v11 + 5200) = 0;
      --a1[1448];
      if ( v6 != 0 )
        a1[1449] -= *(unsigned __int16 *)(v6 + 4 * v11 + 2);
      v10 = a1[1298];
    }
    while ( v10 < 2 );
    v23 = v5;
  }
  a2[1] = v5;
  for ( i = a1[1298] / 2; i >= 1; --i )
    sub_1009A950(a1, a2: v3, a3: i);
  v25 = v24;
  do
  {
    v14 = a1[1298];
    v15 = a1[726];
    a1[726] = a1[v14 + 725];
    a1[1298] = v14 - 1;
    sub_1009A950(a1, a2: v3, a3: 1);
    v16 = a1[726];
    v17 = a1[1299] - 1;
    a1[1299] = v17;
    a1[v17 + 725] = v15;
    v18 = a1[1299] - 1;
    a1[1299] = v18;
    a1[v18 + 725] = v16;
    *(_WORD *)(v3 + 4 * v25) = *(_WORD *)(v3 + 4 * v15) + *(_WORD *)(v3 + 4 * v16);
    if ( *((_BYTE *)a1 + v15 + 5200) < *((_BYTE *)a1 + v16 + 5200) )
      v19 = *((_BYTE *)a1 + v16 + 5200);
    else
      v19 = *((_BYTE *)a1 + v15 + 5200);
    *((_BYTE *)a1 + v25 + 5200) = v19 + 1;
    *(_WORD *)(v3 + 4 * v16 + 2) = v25;
    *(_WORD *)(v3 + 4 * v15 + 2) = v25;
    a1[726] = v25++;
    sub_1009A950(a1, a2: v3, a3: 1);
  }
  while ( (int)a1[1298] >= 2 );
  v20 = a1[726];
  v21 = a1[1299] - 1;
  a1[1299] = v21;
  a1[v21 + 725] = v20;
  sub_1009AA30(a1, a2);
  return sub_1009AC40(a1: v3, a2: v23, a3: a1 + 717);
}

//------------------------------------------------------------------------------
// Address: 0x1009A950
// Name: sub_1009A950
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009A950(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // edx
  int v5; // ebp
  int v6; // ecx
  bool v7; // cc
  int v8; // esi
  int v9; // ebp
  unsigned __int16 v10; // dx
  unsigned __int16 v11; // bx
  int v12; // esi
  unsigned __int16 v13; // dx
  unsigned __int16 v14; // bx
  int v15; // edx
  int v16; // edx
  int v17; // [esp+14h] [ebp+4h]

  result = a1;
  v4 = *(_DWORD *)(a1 + 5192);
  v5 = *(_DWORD *)(a1 + 4 * a3 + 2900);
  v6 = 2 * a3;
  v7 = 2 * a3 < v4;
  v17 = v5;
  if ( 2 * a3 > v4 )
  {
    *(_DWORD *)(result + 4 * a3 + 2900) = v5;
  }
  else
  {
    while ( 1 )
    {
      if ( v7 )
      {
        v8 = *(_DWORD *)(result + 4 * v6 + 2904);
        v9 = *(_DWORD *)(result + 4 * v6 + 2900);
        v10 = *(_WORD *)(a2 + 4 * v8);
        v11 = *(_WORD *)(a2 + 4 * v9);
        if ( v10 < v11 || v10 == v11 && *(_BYTE *)(v8 + result + 5200) <= *(_BYTE *)(result + v9 + 5200) )
          ++v6;
        v5 = v17;
      }
      v12 = *(_DWORD *)(result + 4 * v6 + 2900);
      v13 = *(_WORD *)(a2 + 4 * v5);
      v14 = *(_WORD *)(a2 + 4 * v12);
      if ( v13 < v14 )
      {
LABEL_12:
        *(_DWORD *)(result + 4 * a3 + 2900) = v5;
        return result;
      }
      if ( v13 == v14 && *(_BYTE *)(result + v5 + 5200) <= *(_BYTE *)(v12 + result + 5200) )
        break;
      v15 = a3;
      a3 = v6;
      v6 *= 2;
      *(_DWORD *)(result + 4 * v15 + 2900) = v12;
      v16 = *(_DWORD *)(result + 5192);
      v7 = v6 < v16;
      if ( v6 > v16 )
        goto LABEL_12;
    }
    *(_DWORD *)(result + 4 * a3 + 2900) = v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009AA30
// Name: sub_1009AA30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl sub_1009AA30(_DWORD *a1, int *a2)
{
  int v2; // ebp
  int *v3; // eax
  int v4; // ebx
  int v5; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  bool v12; // zf
  _WORD *v13; // edi
  _WORD *i; // ecx
  int v15; // esi
  int v16; // ebx
  int v17; // ecx
  _WORD *v18; // edi
  int v19; // eax
  int v21; // [esp+10h] [ebp-18h]
  int v22; // [esp+14h] [ebp-14h]
  int v23; // [esp+18h] [ebp-10h]
  int v24; // [esp+1Ch] [ebp-Ch]
  int v25; // [esp+20h] [ebp-8h]
  int v26; // [esp+24h] [ebp-4h]
  int *v27; // [esp+2Ch] [ebp+4h]
  int v28; // [esp+2Ch] [ebp+4h]
  int v29; // [esp+30h] [ebp+8h]
  int v30; // [esp+30h] [ebp+8h]

  v2 = *a2;
  v3 = (int *)a2[2];
  v24 = a2[1];
  v4 = 0;
  v5 = *v3;
  v26 = v3[1];
  v25 = v3[2];
  v21 = v3[4];
  v29 = 0;
  memset(a1 + 717, 0, 0x20u);
  *(_WORD *)(v2 + 4 * a1[a1[1299] + 725] + 2) = 0;
  v7 = a1[1299] + 1;
  if ( v7 < 573 )
  {
    v27 = &a1[v7 + 725];
    v23 = 573 - v7;
    v22 = 573;
    do
    {
      v8 = *v27;
      v9 = *(unsigned __int16 *)(v2 + 4 * *(unsigned __int16 *)(v2 + 4 * *v27 + 2) + 2) + 1;
      if ( v9 > v21 )
      {
        ++v4;
        v9 = v21;
        v29 = v4;
      }
      *(_WORD *)(v2 + 4 * v8 + 2) = v9;
      if ( v8 <= v24 )
      {
        ++*((_WORD *)a1 + v9 + 1434);
        v10 = 0;
        if ( v8 >= v25 )
          v10 = *(_DWORD *)(v26 + 4 * (v8 - v25));
        v11 = *(unsigned __int16 *)(v2 + 4 * v8);
        a1[1448] += v11 * (v10 + v9);
        if ( v5 != 0 )
          a1[1449] += v11 * (v10 + *(unsigned __int16 *)(v5 + 4 * v8 + 2));
        v4 = v29;
      }
      LOWORD(v7) = v23 - 1;
      v12 = v23 == 1;
      ++v27;
      --v23;
    }
    while ( !v12 );
    if ( v4 != 0 )
    {
      v13 = (_WORD *)a1 + v21 + 1434;
      do
      {
        v7 = v21 - 1;
        for ( i = (_WORD *)a1 + v21 + 1433; *i == 0; --v7 )
          --i;
        --*((_WORD *)a1 + v7 + 1434);
        *((_WORD *)a1 + v7 + 1435) += 2;
        --*v13;
        v4 -= 2;
      }
      while ( v4 > 0 );
      v15 = v21;
      if ( v21 != 0 )
      {
        v28 = (int)a1 + 2 * v21 + 2868;
        do
        {
          v7 = (unsigned __int16)*v13;
          v30 = v7;
          if ( *v13 != 0 )
          {
            v16 = (int)&a1[v22 + 725];
            do
            {
              v17 = *(_DWORD *)(v16 - 4);
              v16 -= 4;
              --v22;
              if ( v17 <= v24 )
              {
                v18 = (_WORD *)(v2 + 4 * v17 + 2);
                HIWORD(v19) = 0;
                if ( (unsigned __int16)*v18 != v15 )
                {
                  LOWORD(v19) = *v18;
                  a1[1448] += *(unsigned __int16 *)(v2 + 4 * v17) * (v15 - v19);
                  *v18 = v15;
                }
                v7 = --v30;
              }
            }
            while ( v7 != 0 );
          }
          --v15;
          v13 = (_WORD *)(v28 - 2);
          v28 -= 2;
        }
        while ( v15 != 0 );
      }
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1009AC40
// Name: sub_1009AC40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl sub_1009AC40(int a1, int a2, int a3)
{
  __int16 v3; // cx
  int i; // eax
  __int16 v5; // si
  int j; // esi
  unsigned __int16 v7; // dx
  _WORD v9[2]; // [esp+6h] [ebp-22h]
  char v10; // [esp+Ah] [ebp-1Eh] BYREF

  v3 = 0;
  for ( i = 1; i <= 15; v9[i] = 2 * v5 )
  {
    v5 = v3 + *(_WORD *)((char *)&v9[++i] + a3 - (_DWORD)&v10);
    v3 = 2 * v5;
  }
  for ( j = 0; j <= a2; ++j )
  {
    i = *(unsigned __int16 *)(a1 + 4 * j + 2);
    if ( (_WORD)i != 0 )
    {
      v7 = v9[i + 1];
      v9[i + 1] = v7 + 1;
      LOWORD(i) = sub_1009BA20(a1: v7, a2: i);
      *(_WORD *)(a1 + 4 * j) = i;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x1009ACC0
// Name: sub_1009ACC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009ACC0(_DWORD *a1)
{
  int result; // eax

  sub_1009AD30(a1, a2: a1 + 35, a3: a1[709]);
  sub_1009AD30(a1, a2: a1 + 608, a3: a1[712]);
  sub_1009A730(a1, a2: a1 + 714);
  for ( result = 18; result >= 3; --result )
  {
    if ( HIWORD(a1[(unsigned __int8)byte_1010F38C[result] + 669]) != 0 )
      break;
  }
  a1[1448] += 3 * result + 17;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009AD30
// Name: sub_1009AD30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009AD30(_WORD *a1, int a2, int a3)
{
  int result; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // edx
  int v7; // esi
  unsigned __int16 *v8; // ebp
  int v9; // eax
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+18h] [ebp+8h]

  result = a2;
  v4 = *(unsigned __int16 *)(a2 + 2);
  v5 = 0;
  v10 = -1;
  v6 = 7;
  v7 = 4;
  if ( (_WORD)v4 == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  *(_WORD *)(a2 + 4 * a3 + 6) = -1;
  if ( a3 >= 0 )
  {
    v11 = a3 + 1;
    v8 = (unsigned __int16 *)(result + 6);
    do
    {
      v9 = v4;
      v4 = *v8;
      if ( ++v5 >= v6 || v9 != v4 )
      {
        if ( v5 >= v7 )
        {
          if ( v9 != 0 )
          {
            if ( v9 != v10 )
              ++a1[2 * v9 + 1338];
            ++a1[1370];
          }
          else if ( v5 > 10 )
          {
            ++a1[1374];
          }
          else
          {
            ++a1[1372];
          }
        }
        else
        {
          a1[2 * v9 + 1338] += v5;
        }
        v5 = 0;
        v10 = v9;
        if ( v4 != 0 )
        {
          if ( v9 == v4 )
          {
            v6 = 6;
            v7 = 3;
          }
          else
          {
            v6 = 7;
            v7 = 4;
          }
        }
        else
        {
          v6 = 138;
          v7 = 3;
        }
      }
      v8 += 2;
      result = --v11;
    }
    while ( v11 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009AE20
// Name: sub_1009AE20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009AE20(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  char v9; // bl
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  char v16; // bl
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  char v23; // bl
  int v24; // edx
  int v25; // edx
  int i; // edi
  int v27; // ecx
  int v28; // eax
  int v29; // edx
  int v30; // ecx
  char v31; // bl
  int v32; // edx
  int v33; // edx

  v4 = a2 - 257;
  v5 = *(_DWORD *)(a1 + 5812);
  if ( v5 <= 11 )
  {
    *(_WORD *)(a1 + 5808) |= v4 << v5;
    *(_DWORD *)(a1 + 5812) = v5 + 5;
  }
  else
  {
    v6 = v4 << v5;
    v7 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v6;
    *(_BYTE *)(v7 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v8 = *(_DWORD *)(a1 + 8);
    v9 = *(_BYTE *)(a1 + 5809);
    v10 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v10;
    *(_BYTE *)(v10 + v8) = v9;
    v11 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v11 - 11;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)v4 >> (16 - v11);
  }
  v12 = *(_DWORD *)(a1 + 5812);
  if ( v12 <= 11 )
  {
    *(_WORD *)(a1 + 5808) |= (a3 - 1) << v12;
    *(_DWORD *)(a1 + 5812) = v12 + 5;
  }
  else
  {
    v13 = (a3 - 1) << v12;
    v14 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v13;
    *(_BYTE *)(v14 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v15 = *(_DWORD *)(a1 + 8);
    v16 = *(_BYTE *)(a1 + 5809);
    v17 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v17;
    *(_BYTE *)(v17 + v15) = v16;
    v18 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v18 - 11;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)(a3 - 1) >> (16 - v18);
  }
  v19 = *(_DWORD *)(a1 + 5812);
  v20 = a4 - 4;
  if ( v19 <= 12 )
  {
    *(_WORD *)(a1 + 5808) |= v20 << v19;
    *(_DWORD *)(a1 + 5812) = v19 + 4;
  }
  else
  {
    v21 = v20 << v19;
    v22 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v21;
    *(_BYTE *)(v22 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v23 = *(_BYTE *)(a1 + 5809);
    v24 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v24;
    *(_BYTE *)(v24 + *(_DWORD *)(a1 + 8)) = v23;
    v25 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v25 - 12;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)v20 >> (16 - v25);
  }
  for ( i = 0; i < a4; ++i )
  {
    v27 = *(_DWORD *)(a1 + 5812);
    v28 = 0;
    if ( v27 <= 13 )
    {
      LOBYTE(v28) = byte_1010F38C[i];
      *(_WORD *)(a1 + 5808) |= *(_WORD *)(a1 + 4 * v28 + 2678) << v27;
      *(_DWORD *)(a1 + 5812) = v27 + 3;
    }
    else
    {
      LOWORD(v28) = *(_WORD *)(a1 + 4 * (unsigned __int8)byte_1010F38C[i] + 2678);
      v29 = v28 << v27;
      v30 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5808) |= v29;
      *(_BYTE *)(v30 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
      v31 = *(_BYTE *)(a1 + 5809);
      v32 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v32;
      *(_BYTE *)(v32 + *(_DWORD *)(a1 + 8)) = v31;
      v33 = *(_DWORD *)(a1 + 5812);
      ++*(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 5812) = v33 - 13;
      *(_WORD *)(a1 + 5808) = (unsigned __int16)v28 >> (16 - v33);
    }
  }
  sub_1009B070(a1, a2: a1 + 140, a3: a2 - 1);
  return sub_1009B070(a1, a2: a1 + 2432, a3: a3 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1009B070
// Name: sub_1009B070
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009B070(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int v7; // edx
  int v8; // edi
  int v9; // ebp
  int v10; // ecx
  int v11; // edi
  unsigned __int16 v12; // si
  int v13; // edx
  int v14; // ecx
  char v15; // bl
  int v16; // edx
  int v17; // edx
  int v18; // ecx
  int v19; // ecx
  int v20; // edi
  unsigned __int16 v21; // si
  int v22; // edx
  int v23; // ecx
  char v24; // bl
  int v25; // edx
  int v26; // edx
  int v27; // ecx
  int v28; // ecx
  int v29; // edi
  unsigned __int16 v30; // si
  int v31; // edx
  int v32; // ecx
  char v33; // bl
  int v34; // edx
  int v35; // edx
  int v36; // ecx
  int v37; // esi
  int v38; // edx
  int v39; // ecx
  char v40; // bl
  int v41; // edx
  int v42; // edx
  int v43; // ecx
  int v44; // ecx
  int v45; // edi
  unsigned __int16 v46; // si
  int v47; // edx
  int v48; // ecx
  char v49; // bl
  int v50; // edx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edx
  int v55; // ecx
  char v56; // bl
  int v57; // edx
  int v58; // edx
  unsigned __int16 v59; // si
  int v60; // edx
  int v61; // ecx
  char v62; // bl
  int v63; // edx
  int v64; // edx
  int v65; // ecx
  int v66; // esi
  int v67; // edx
  int v68; // ecx
  char v69; // bl
  int v70; // edx
  int v71; // edx
  bool v72; // zf
  int v73; // [esp+Ch] [ebp-8h]
  int v74; // [esp+10h] [ebp-4h]
  int v75; // [esp+18h] [ebp+4h]
  int v76; // [esp+1Ch] [ebp+8h]
  unsigned __int16 *v77; // [esp+20h] [ebp+Ch]

  result = a2;
  v4 = *(unsigned __int16 *)(a2 + 2);
  v5 = 0;
  v73 = -1;
  v6 = 7;
  v7 = 4;
  if ( (_WORD)v4 == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  if ( a3 >= 0 )
  {
    v8 = a3 + 1;
    v77 = (unsigned __int16 *)(a2 + 6);
    result = a1;
    v74 = v8;
    do
    {
      v9 = v4;
      ++v5;
      v4 = *v77;
      v75 = v4;
      v76 = v5;
      if ( v5 < v6 && v9 == v4 )
        goto LABEL_44;
      if ( v5 < v7 )
      {
        do
        {
          v10 = *(_DWORD *)(result + 5812);
          v11 = *(unsigned __int16 *)(result + 4 * v9 + 2678);
          if ( v10 <= 16 - (unsigned __int16)v11 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 4 * v9 + 2676) << v10;
            v18 = v11 + v10;
          }
          else
          {
            v12 = *(_WORD *)(result + 4 * v9 + 2676);
            v13 = v12 << v10;
            v14 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v13;
            *(_BYTE *)(v14 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v15 = *(_BYTE *)(result + 5809);
            v16 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v16;
            *(_BYTE *)(v16 + *(_DWORD *)(result + 8)) = v15;
            v17 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v18 = v17 + v11 - 16;
            *(_WORD *)(result + 5808) = v12 >> (16 - v17);
            v5 = v76;
          }
          --v5;
          *(_DWORD *)(result + 5812) = v18;
          v76 = v5;
        }
        while ( v5 != 0 );
        goto LABEL_39;
      }
      if ( v9 != 0 )
      {
        if ( v9 != v73 )
        {
          v19 = *(_DWORD *)(result + 5812);
          v20 = *(unsigned __int16 *)(result + 4 * v9 + 2678);
          if ( v19 <= 16 - (unsigned __int16)v20 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 4 * v9 + 2676) << v19;
            v27 = v20 + v19;
          }
          else
          {
            v21 = *(_WORD *)(result + 4 * v9 + 2676);
            v22 = v21 << v19;
            v23 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v22;
            *(_BYTE *)(v23 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v24 = *(_BYTE *)(result + 5809);
            v25 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v25;
            *(_BYTE *)(v25 + *(_DWORD *)(result + 8)) = v24;
            v26 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v27 = v26 + v20 - 16;
            *(_WORD *)(result + 5808) = v21 >> (16 - v26);
            v5 = v76;
          }
          --v5;
          *(_DWORD *)(result + 5812) = v27;
          v76 = v5;
        }
        v28 = *(_DWORD *)(result + 5812);
        v29 = *(unsigned __int16 *)(result + 2742);
        if ( v28 <= 16 - (unsigned __int16)v29 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2740) << v28;
          v36 = v29 + v28;
        }
        else
        {
          v30 = *(_WORD *)(result + 2740);
          v31 = v30 << v28;
          v32 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v31;
          *(_BYTE *)(v32 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v33 = *(_BYTE *)(result + 5809);
          v34 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v34;
          *(_BYTE *)(v34 + *(_DWORD *)(result + 8)) = v33;
          v35 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v36 = v35 + v29 - 16;
          *(_WORD *)(result + 5808) = v30 >> (16 - v35);
          v5 = v76;
        }
        v37 = v5 - 3;
        *(_DWORD *)(result + 5812) = v36;
        if ( v36 > 14 )
        {
          v38 = v37 << v36;
          v39 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v38;
          *(_BYTE *)(v39 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v40 = *(_BYTE *)(result + 5809);
          v41 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v41;
          *(_BYTE *)(v41 + *(_DWORD *)(result + 8)) = v40;
          v42 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          *(_DWORD *)(result + 5812) = v42 - 14;
          *(_WORD *)(result + 5808) = (unsigned __int16)v37 >> (16 - v42);
          goto LABEL_39;
        }
        *(_WORD *)(result + 5808) |= v37 << v36;
        v43 = v36 + 2;
      }
      else
      {
        v44 = *(_DWORD *)(result + 5812);
        HIWORD(v45) = 0;
        if ( v5 > 10 )
        {
          LOWORD(v45) = *(_WORD *)(result + 2750);
          if ( v44 <= 16 - v45 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2748) << v44;
            v65 = v45 + v44;
          }
          else
          {
            v59 = *(_WORD *)(result + 2748);
            v60 = v59 << v44;
            v61 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v60;
            *(_BYTE *)(v61 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v62 = *(_BYTE *)(result + 5809);
            v63 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v63;
            *(_BYTE *)(v63 + *(_DWORD *)(result + 8)) = v62;
            v64 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v65 = v64 + v45 - 16;
            *(_WORD *)(result + 5808) = v59 >> (16 - v64);
            v5 = v76;
          }
          v66 = v5 - 11;
          *(_DWORD *)(result + 5812) = v65;
          if ( v65 > 9 )
          {
            v67 = v66 << v65;
            v68 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v67;
            *(_BYTE *)(v68 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v69 = *(_BYTE *)(result + 5809);
            v70 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v70;
            *(_BYTE *)(v70 + *(_DWORD *)(result + 8)) = v69;
            v71 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5812) = v71 - 9;
            *(_WORD *)(result + 5808) = (unsigned __int16)v66 >> (16 - v71);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5808) |= v66 << v65;
          v43 = v65 + 7;
        }
        else
        {
          LOWORD(v45) = *(_WORD *)(result + 2746);
          if ( v44 <= 16 - v45 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2744) << v44;
            v52 = v45 + v44;
          }
          else
          {
            v46 = *(_WORD *)(result + 2744);
            v47 = v46 << v44;
            v48 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v47;
            *(_BYTE *)(v48 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v49 = *(_BYTE *)(result + 5809);
            v50 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v50;
            *(_BYTE *)(v50 + *(_DWORD *)(result + 8)) = v49;
            v51 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v52 = v51 + v45 - 16;
            *(_WORD *)(result + 5808) = v46 >> (16 - v51);
            v5 = v76;
          }
          v53 = v5 - 3;
          *(_DWORD *)(result + 5812) = v52;
          if ( v52 > 13 )
          {
            v54 = v53 << v52;
            v55 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v54;
            *(_BYTE *)(v55 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v56 = *(_BYTE *)(result + 5809);
            v57 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v57;
            *(_BYTE *)(v57 + *(_DWORD *)(result + 8)) = v56;
            v58 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5812) = v58 - 13;
            *(_WORD *)(result + 5808) = (unsigned __int16)v53 >> (16 - v58);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5808) |= v53 << v52;
          v43 = v52 + 3;
        }
      }
      *(_DWORD *)(result + 5812) = v43;
LABEL_39:
      v4 = v75;
      v5 = 0;
      v73 = v9;
      if ( v75 != 0 )
      {
        if ( v9 == v75 )
        {
          v6 = 6;
          v7 = 3;
        }
        else
        {
          v6 = 7;
          v7 = 4;
        }
      }
      else
      {
        v6 = 138;
        v7 = 3;
      }
LABEL_44:
      v72 = v74 == 1;
      v77 += 2;
      --v74;
    }
    while ( !v72 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009B590
// Name: sub_1009B590
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009B590(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // ebx
  unsigned int v5; // edi
  int v6; // ebp
  int v7; // esi
  int v8; // ecx
  unsigned __int16 v9; // di
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  int v13; // edx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // edi
  unsigned __int16 v18; // di
  int v19; // edx
  int v20; // ecx
  char v21; // bl
  int v22; // edx
  int v23; // edx
  __int16 v24; // di
  __int16 v25; // bx
  int v26; // ecx
  int v27; // edi
  int v28; // esi
  int v29; // ecx
  int v30; // edx
  int v31; // ecx
  char v32; // bl
  int v33; // edx
  int v34; // edx
  int v35; // ecx
  unsigned int v36; // ebp
  int v37; // edx
  int v38; // ecx
  int v39; // edi
  unsigned __int16 v40; // si
  int v41; // edx
  int v42; // ecx
  char v43; // bl
  int v44; // edx
  int v45; // edx
  __int16 v46; // si
  int v47; // ecx
  int v48; // esi
  unsigned int v49; // ebp
  int v50; // ecx
  unsigned int v51; // edx
  int v52; // ecx
  int v53; // ecx
  int v54; // edx
  int v55; // edx
  int v56; // ecx
  int v57; // edi
  unsigned __int16 v58; // si
  int v59; // edx
  int v60; // ecx
  int v61; // ecx
  int v62; // edx
  int v63; // edx
  int v64; // ecx
  int v65; // [esp+10h] [ebp-8h]
  unsigned int v66; // [esp+14h] [ebp-4h]
  int v67; // [esp+1Ch] [ebp+4h]
  int v68; // [esp+1Ch] [ebp+4h]

  result = a1;
  v4 = a2;
  v5 = 0;
  if ( *(_DWORD *)(a1 + 5784) != 0 )
  {
    do
    {
      v6 = *(unsigned __int16 *)(*(_DWORD *)(result + 5788) + 2 * v5);
      v7 = *(unsigned __int8 *)(v5 + *(_DWORD *)(result + 5776));
      v8 = *(_DWORD *)(result + 5812);
      v66 = v5 + 1;
      if ( (_WORD)v6 != 0 )
      {
        HIWORD(v17) = 0;
        v16 = (unsigned __int8)_length_code[v7];
        v67 = v16;
        LOWORD(v17) = *(_WORD *)(v4 + 4 * v16 + 1030);
        v65 = (unsigned __int16)v17;
        if ( v8 <= 16 - (unsigned __int16)v17 )
        {
          v25 = *(_WORD *)(a2 + 4 * v16 + 1028) << v8;
          v26 = *(_DWORD *)(result + 5812);
          *(_WORD *)(result + 5808) |= v25;
          *(_DWORD *)(result + 5812) = v17 + v26;
        }
        else
        {
          v18 = *(_WORD *)(a2 + 4 * v16 + 1028);
          v19 = v18 << v8;
          v20 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v19;
          *(_BYTE *)(v20 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v21 = *(_BYTE *)(result + 5809);
          v22 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v22;
          *(_BYTE *)(v22 + *(_DWORD *)(result + 8)) = v21;
          v23 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v24 = v18 >> (16 - v23);
          *(_DWORD *)(result + 5812) = v23 + v65 - 16;
          v16 = v67;
          *(_WORD *)(result + 5808) = v24;
        }
        v27 = dword_1010F250[v16];
        if ( v27 != 0 )
        {
          v28 = v7 - dword_1010FB98[v16];
          v29 = *(_DWORD *)(result + 5812);
          if ( v29 <= 16 - v27 )
          {
            *(_WORD *)(result + 5808) |= v28 << v29;
            v35 = v27 + v29;
          }
          else
          {
            v30 = v28 << v29;
            v31 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v30;
            *(_BYTE *)(v31 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v32 = *(_BYTE *)(result + 5809);
            v33 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v33;
            *(_BYTE *)(v33 + *(_DWORD *)(result + 8)) = v32;
            v34 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v35 = v34 + v27 - 16;
            *(_WORD *)(result + 5808) = (unsigned __int16)v28 >> (16 - v34);
          }
          *(_DWORD *)(result + 5812) = v35;
        }
        v36 = v6 - 1;
        if ( v36 >= 0x100 )
          v37 = (unsigned __int8)byte_1010F998[v36 >> 7];
        else
          v37 = (unsigned __int8)_dist_code[v36];
        v38 = *(_DWORD *)(result + 5812);
        v39 = *(unsigned __int16 *)(a3 + 4 * v37 + 2);
        v68 = v37;
        if ( v38 <= 16 - (unsigned __int16)v39 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(a3 + 4 * v37) << v38;
          v47 = v39 + v38;
        }
        else
        {
          v40 = *(_WORD *)(a3 + 4 * v37);
          v41 = v40 << v38;
          v42 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v41;
          *(_BYTE *)(v42 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v43 = *(_BYTE *)(result + 5809);
          v44 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v44;
          *(_BYTE *)(v44 + *(_DWORD *)(result + 8)) = v43;
          v45 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v46 = v40 >> (16 - v45);
          v47 = v45 + v39 - 16;
          v37 = v68;
          *(_WORD *)(result + 5808) = v46;
        }
        v4 = a2;
        *(_DWORD *)(result + 5812) = v47;
        v48 = dword_1010F2C8[v37];
        if ( v48 == 0 )
          goto LABEL_25;
        v49 = v36 - dword_1010FC10[v37];
        v50 = *(_DWORD *)(result + 5812);
        if ( v50 <= 16 - v48 )
        {
          *(_WORD *)(result + 5808) |= v49 << v50;
          v15 = v48 + v50;
        }
        else
        {
          v51 = v49 << v50;
          v52 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v51;
          *(_BYTE *)(v52 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v53 = *(_DWORD *)(result + 8);
          v54 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v54;
          *(_BYTE *)(v54 + v53) = *(_BYTE *)(result + 5809);
          v55 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v15 = v55 + v48 - 16;
          *(_WORD *)(result + 5808) = (unsigned __int16)v49 >> (16 - v55);
        }
      }
      else
      {
        LOWORD(v6) = *(_WORD *)(v4 + 4 * v7 + 2);
        if ( v8 <= 16 - (unsigned __int16)v6 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(v4 + 4 * v7) << v8;
          v15 = v6 + v8;
        }
        else
        {
          v9 = *(_WORD *)(v4 + 4 * v7);
          v10 = v9 << v8;
          v11 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v10;
          *(_BYTE *)(v11 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v12 = *(_DWORD *)(result + 8);
          v13 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v13;
          *(_BYTE *)(v13 + v12) = *(_BYTE *)(result + 5809);
          v14 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v15 = v14 + v6 - 16;
          *(_WORD *)(result + 5808) = v9 >> (16 - v14);
        }
      }
      *(_DWORD *)(result + 5812) = v15;
LABEL_25:
      v5 = v66;
    }
    while ( v66 < *(_DWORD *)(result + 5784) );
  }
  v56 = *(_DWORD *)(result + 5812);
  v57 = *(unsigned __int16 *)(v4 + 1026);
  if ( v56 <= 16 - (unsigned __int16)v57 )
  {
    *(_WORD *)(result + 5808) |= *(_WORD *)(v4 + 1024) << v56;
    v64 = v57 + v56;
  }
  else
  {
    v58 = *(_WORD *)(v4 + 1024);
    v59 = v58 << v56;
    v60 = *(_DWORD *)(result + 8);
    *(_WORD *)(result + 5808) |= v59;
    *(_BYTE *)(v60 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
    v61 = *(_DWORD *)(result + 8);
    v62 = *(_DWORD *)(result + 20) + 1;
    *(_DWORD *)(result + 20) = v62;
    *(_BYTE *)(v61 + v62) = *(_BYTE *)(result + 5809);
    v63 = *(_DWORD *)(result + 5812);
    ++*(_DWORD *)(result + 20);
    v64 = v63 + v57 - 16;
    *(_WORD *)(result + 5808) = v58 >> (16 - v63);
  }
  *(_DWORD *)(result + 5812) = v64;
  *(_DWORD *)(result + 5804) = *(unsigned __int16 *)(v4 + 1026);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009B9A0
// Name: sub_1009B9A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl sub_1009B9A0(int a1)
{
  unsigned int v1; // edi
  unsigned int v2; // edx
  unsigned __int16 *v3; // eax
  int i; // ecx
  unsigned __int16 v5; // si
  unsigned __int16 *v6; // eax
  int j; // ecx
  unsigned __int16 v8; // bp
  unsigned __int16 *v9; // ecx
  int k; // eax
  unsigned __int16 v11; // si
  unsigned int v12; // edi

  v1 = 0;
  v2 = 0;
  v3 = (unsigned __int16 *)(a1 + 140);
  for ( i = 7; i != 0; --i )
  {
    v5 = *v3;
    v3 += 2;
    v2 += v5;
  }
  v6 = (unsigned __int16 *)(a1 + 168);
  for ( j = 121; j != 0; --j )
  {
    v8 = *v6;
    v6 += 2;
    v1 += v8;
  }
  v9 = (unsigned __int16 *)(a1 + 652);
  for ( k = 128; k != 0; --k )
  {
    v11 = *v9;
    v9 += 2;
    v2 += v11;
  }
  v12 = v1 >> 2;
  *(_BYTE *)(a1 + 28) = v2 <= v12;
  return v2 <= v12;
}

//------------------------------------------------------------------------------
// Address: 0x1009BA20
// Name: sub_1009BA20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_1009BA20(unsigned int a1, int a2)
{
  unsigned int v4; // eax
  int v5; // esi

  v4 = 0;
  do
  {
    v5 = a1 & 1;
    a1 >>= 1;
    v4 = 2 * (v5 | v4);
    --a2;
  }
  while ( a2 > 0 );
  return v4 >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009BA40
// Name: sub_1009BA40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009BA40(int a1)
{
  int result; // eax
  int v2; // ecx
  char v3; // bl
  int v4; // edx
  int v5; // edx
  int v6; // ecx

  result = a1;
  v2 = *(_DWORD *)(a1 + 5812);
  if ( v2 == 16 )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v3 = *(_BYTE *)(a1 + 5809);
    v4 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v4;
    *(_BYTE *)(v4 + *(_DWORD *)(a1 + 8)) = v3;
    ++*(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  else if ( v2 >= 8 )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v5 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = *(unsigned __int8 *)(a1 + 5809);
    v6 = *(_DWORD *)(a1 + 5812);
    *(_DWORD *)(a1 + 20) = v5 + 1;
    *(_DWORD *)(a1 + 5812) = v6 - 8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009BAD0
// Name: sub_1009BAD0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009BAD0(int a1)
{
  int result; // eax
  int v2; // edx
  char v3; // bl
  int v4; // edx

  result = a1;
  v2 = *(_DWORD *)(a1 + 5812);
  if ( v2 <= 8 )
  {
    if ( v2 > 0 )
      *(_BYTE *)(*(_DWORD *)(a1 + 8) + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5808);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v3 = *(_BYTE *)(a1 + 5809);
    v4 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v4;
    *(_BYTE *)(v4 + *(_DWORD *)(a1 + 8)) = v3;
    ++*(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009BB50
// Name: sub_1009BB50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009BB50(_DWORD *a1, _BYTE *a2, int a3, int a4)
{
  int result; // eax
  int v5; // edi
  int v6; // edx
  int v7; // edi
  int v8; // ecx
  int v9; // edi
  int v10; // ecx

  sub_1009BAD0((int)a1);
  result = a3;
  a1[1451] = 8;
  if ( a4 != 0 )
  {
    *(_BYTE *)(a1[5] + a1[2]) = a3;
    v5 = a1[2];
    v6 = a1[5] + 1;
    a1[5] = v6;
    *(_BYTE *)(v6 + v5) = BYTE1(a3);
    v7 = a1[2];
    v8 = a1[5] + 1;
    a1[5] = v8;
    *(_BYTE *)(v8 + v7) = ~(_BYTE)a3;
    v9 = a1[5] + 1;
    v10 = a1[2];
    a1[5] = v9;
    *(_BYTE *)(v9 + v10) = ~BYTE1(a3);
    ++a1[5];
  }
  if ( a3 != 0 )
  {
    do
    {
      *(_BYTE *)(a1[5] + a1[2]) = *a2++;
      --result;
      ++a1[5];
    }
    while ( result != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009BBF0
// Name: _inflate_blocks_reset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int (__cdecl *__cdecl inflate_blocks_reset(_DWORD *a1, int a2, _DWORD *a3))(_DWORD, _DWORD, _DWORD)
{
  int v3; // eax
  int (__cdecl *result)(_DWORD, _DWORD, _DWORD); // eax

  if ( a3 != nullptr )
    *a3 = a1[15];
  if ( *a1 == 4 || *a1 == 5 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[3]);
  if ( *a1 == 6 )
    inflate_codes_free(a1: a1[1], a2);
  v3 = a1[10];
  *a1 = 0;
  a1[13] = v3;
  a1[12] = v3;
  result = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))a1[14];
  a1[7] = 0;
  a1[8] = 0;
  if ( result != nullptr )
  {
    result = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))result(a1: 0, a2: 0, a3: 0);
    a1[15] = result;
    *(_DWORD *)(a2 + 48) = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009BC70
// Name: _inflate_blocks_new
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks_new(int a1, int a2, int a3)
{
  int result; // eax
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // eax

  result = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 1, a3: 64);
  v4 = (_DWORD *)result;
  if ( result != 0 )
  {
    v5 = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 8, a3: 1440);
    v4[9] = v5;
    if ( v5 != 0 )
    {
      v6 = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 1, a3);
      v4[10] = v6;
      if ( v6 != 0 )
      {
        v4[11] = a3 + v6;
        v4[14] = a2;
        *v4 = 0;
        inflate_blocks_reset(a1: v4, a2: a1, a3: nullptr);
        return (int)v4;
      }
      else
      {
        (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4[9]);
        (*(void (__cdecl **)(_DWORD, _DWORD *))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4);
        return 0;
      }
    }
    else
    {
      (*(void (__cdecl **)(_DWORD, _DWORD *))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4);
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009BD10
// Name: _inflate_blocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks(_DWORD *a1, int *a2, int a3)
{
  unsigned int v4; // edx
  unsigned int v5; // ebp
  char *v6; // ecx
  unsigned int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // eax
  int v12; // edx
  unsigned int v13; // ebp
  int v14; // ecx
  int v15; // eax
  unsigned __int8 *v16; // eax
  int v17; // edi
  int v18; // esi
  int v19; // edx
  unsigned int v20; // edi
  unsigned int v21; // ecx
  char *v22; // ecx
  char *v23; // edx
  unsigned int v24; // eax
  unsigned int v25; // esi
  int v26; // eax
  char *v27; // edx
  unsigned int v28; // esi
  int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edi
  unsigned int v34; // esi
  unsigned __int8 *v35; // eax
  int v36; // edx
  unsigned int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  int *v40; // esi
  int v41; // eax
  unsigned int v42; // edi
  unsigned __int8 *v43; // eax
  char v44; // cl
  int v45; // eax
  unsigned int v46; // edx
  unsigned int v47; // ecx
  unsigned __int8 *v48; // eax
  unsigned int v49; // ecx
  char v50; // cl
  int v51; // edx
  int v52; // edx
  unsigned int v53; // ecx
  unsigned int v54; // edx
  char v55; // cl
  unsigned int v56; // edi
  unsigned int v57; // eax
  int v58; // ecx
  int v59; // eax
  unsigned int v60; // eax
  unsigned int v61; // eax
  int v62; // edx
  int v63; // eax
  unsigned __int8 *v64; // edi
  int v65; // edx
  int v66; // eax
  char *v67; // ecx
  unsigned __int8 *v68; // edi
  unsigned int v69; // edx
  unsigned int v70; // eax
  int v71; // eax
  int v72; // ebp
  int result; // eax
  int v74; // ebp
  unsigned __int8 **v75; // eax
  unsigned __int8 *v76; // edx
  unsigned __int8 *v77; // esi
  int v78; // ebp
  int v79; // ebp
  int v80; // ebp
  unsigned __int8 *v81; // edx
  unsigned __int8 *v82; // ebp
  unsigned __int8 *v83; // ebp
  int v84; // esi
  unsigned __int8 *v85; // esi
  int v86; // ebp
  unsigned __int8 *v87; // edi
  int v88; // edx
  int v89; // ecx
  unsigned __int8 *v90; // edx
  bool v91; // zf
  unsigned __int8 *v92; // edi
  int v93; // ecx
  unsigned __int8 *v94; // edi
  int v95; // ecx
  unsigned __int8 *v96; // edi
  char *v97; // ecx
  int v98; // edx
  unsigned __int8 *v99; // ebp
  unsigned __int8 *v100; // ebp
  unsigned __int8 *v101; // esi
  int v102; // [esp-1Ch] [ebp-60h]
  int v103; // [esp-14h] [ebp-58h]
  int v104; // [esp-8h] [ebp-4Ch]
  int v105; // [esp-8h] [ebp-4Ch]
  int v106; // [esp-4h] [ebp-48h]
  unsigned int v107; // [esp-4h] [ebp-48h]
  unsigned __int8 *v108; // [esp+10h] [ebp-34h]
  unsigned int v109; // [esp+14h] [ebp-30h]
  int v110; // [esp+18h] [ebp-2Ch] BYREF
  unsigned int v111; // [esp+1Ch] [ebp-28h]
  int v112; // [esp+20h] [ebp-24h] BYREF
  int v113; // [esp+24h] [ebp-20h] BYREF
  int v114; // [esp+28h] [ebp-1Ch] BYREF
  int v115; // [esp+2Ch] [ebp-18h] BYREF
  int v116; // [esp+30h] [ebp-14h] BYREF
  unsigned int v117; // [esp+34h] [ebp-10h]
  unsigned int v118; // [esp+38h] [ebp-Ch]
  int v119; // [esp+3Ch] [ebp-8h] BYREF
  int v120; // [esp+40h] [ebp-4h] BYREF
  char *v121; // [esp+48h] [ebp+4h]
  int v122; // [esp+50h] [ebp+Ch]

  v4 = a2[1];
  v5 = a1[7];
  v108 = (unsigned __int8 *)*a2;
  v6 = (char *)a1[13];
  v110 = a1[8];
  v7 = a1[12];
  v109 = v4;
  v121 = v6;
  if ( (unsigned int)v6 >= v7 )
    v8 = a1[11] - (_DWORD)v6;
  else
    v8 = v7 - (_DWORD)v6 - 1;
  v111 = v8;
  while ( 2 )
  {
    switch ( *a1 )
    {
      case 0:
        v9 = v108;
        v10 = v110;
        if ( v5 >= 3 )
          goto LABEL_10;
        v11 = v109;
        do
        {
          if ( v11 == 0 )
          {
            a1[8] = v10;
            a1[7] = v5;
            v72 = (int)&v9[a2[2] - *a2];
            a2[1] = 0;
            a2[2] = v72;
            *a2 = (int)v9;
            a1[13] = v121;
            return inflate_flush(a1, a2, a3);
          }
          --v11;
          a3 = 0;
          v12 = *v9 << v5;
          v5 += 8;
          v109 = v11;
          v10 |= v12;
          ++v9;
          v110 = v10;
          v108 = v9;
        }
        while ( v5 < 3 );
LABEL_10:
        a1[6] = v10 & 1;
        switch ( (unsigned __int8)(v10 & 7) >> 1 )
        {
          case 0:
            v13 = v5 - 3;
            *a1 = 1;
            v14 = v13 & 7;
            v5 = v13 - v14;
            v110 = v10 >> 3 >> v14;
            continue;
          case 1:
            inflate_trees_fixed(a1: &v116, a2: &v115, a3: &v114, a4: &v113);
            v15 = inflate_codes_new(a1: v116, a2: v115, a3: v114, a4: v113, a5: a2);
            a1[1] = v15;
            if ( v15 != 0 )
            {
              v110 = v10 >> 3;
              v5 -= 3;
              *a1 = 6;
              continue;
            }
            a1[8] = v10;
            a1[7] = v5;
            v74 = a2[2];
            a2[1] = v109;
            a2[2] = (int)&v9[v74 - *a2];
            *a2 = (int)v9;
            a1[13] = v121;
            result = inflate_flush(a1, a2, a3: -4);
            break;
          case 2:
            v110 = v10 >> 3;
            v5 -= 3;
            *a1 = 3;
            continue;
          case 3:
            v75 = (unsigned __int8 **)a2;
            *a1 = 9;
            a2[6] = (int)aInvalidBlockTy;
            a1[8] = v10 >> 3;
            a1[7] = v5 - 3;
            a2[1] = v109;
            v76 = &v9[-*a2];
            *a2 = (int)v9;
            v106 = -3;
            goto LABEL_129;
          default:
            continue;
        }
        return result;
      case 1:
        v16 = v108;
        v17 = v109;
        v18 = v110;
        if ( v5 >= 0x20 )
          goto LABEL_18;
        do
        {
          if ( v17 == 0 )
          {
            a1[8] = v18;
            a1[7] = v5;
            v77 = (unsigned __int8 *)*a2;
            v78 = a2[2];
            a2[1] = 0;
            *a2 = (int)v16;
            a2[2] = v16 - v77 + v78;
            a1[13] = v121;
            return inflate_flush(a1, a2, a3);
          }
          a3 = 0;
          --v17;
          v19 = *v16 << v5;
          v5 += 8;
          v109 = v17;
          v18 |= v19;
          v108 = ++v16;
        }
        while ( v5 < 0x20 );
LABEL_18:
        if ( (unsigned int)~v18 >> 16 != (unsigned __int16)v18 )
        {
          *a1 = 9;
          a2[6] = (int)aInvalidStoredB;
          a1[8] = v18;
          a1[7] = v5;
          v79 = (int)&v16[a2[2] - *a2];
          *a2 = (int)v16;
          a2[1] = v17;
          a2[2] = v79;
          a1[13] = v121;
          return inflate_flush(a1, a2, a3: -3);
        }
        v5 = 0;
        a1[1] = (unsigned __int16)v18;
        v110 = 0;
        if ( (_WORD)v18 != 0 )
        {
          *a1 = 2;
          continue;
        }
LABEL_45:
        *a1 = a1[6] != 0 ? 7 : 0;
        continue;
      case 2:
        v20 = v109;
        if ( v109 == 0 )
        {
          v75 = (unsigned __int8 **)a2;
          a1[8] = v110;
          a1[7] = v5;
          v80 = a2[2];
          v81 = &v108[-*a2];
          a2[1] = 0;
          v82 = &v81[v80];
          *a2 = (int)v108;
          v106 = a3;
          goto LABEL_130;
        }
        v21 = v111;
        if ( v111 == 0 )
        {
          v22 = (char *)a1[11];
          v23 = v121;
          if ( v121 != v22 )
            goto LABEL_29;
          v24 = a1[12];
          v25 = a1[10];
          if ( v24 == v25 )
            goto LABEL_29;
          v23 = (char *)a1[10];
          v121 = v23;
          v21 = v25 >= v24 ? (unsigned int)&v22[-v25] : v24 - v25 - 1;
          v111 = v21;
          if ( v21 == 0 )
          {
LABEL_29:
            a1[13] = v23;
            v26 = inflate_flush(a1, a2, a3);
            v27 = (char *)a1[13];
            v28 = a1[12];
            v122 = v26;
            v121 = v27;
            if ( (unsigned int)v27 >= v28 )
              v21 = a1[11] - (_DWORD)v27;
            else
              v21 = v28 - (_DWORD)v27 - 1;
            v29 = a1[11];
            v111 = v21;
            v112 = v29;
            if ( v27 == (char *)v29 )
            {
              v30 = a1[10];
              if ( v28 != v30 )
              {
                v27 = (char *)a1[10];
                v121 = v27;
                if ( v30 >= v28 )
                  v21 = v112 - v30;
                else
                  v21 = v28 - v30 - 1;
                v111 = v21;
              }
            }
            if ( v21 == 0 )
            {
              a1[8] = v110;
              a1[7] = v5;
              v83 = (unsigned __int8 *)*a2;
              v84 = a2[2];
              a2[1] = v109;
              *a2 = (int)v108;
              a2[2] = v108 - v83 + v84;
              a1[13] = v27;
              return inflate_flush(a1, a2, a3: v122);
            }
            v20 = v109;
          }
        }
        v31 = a1[1];
        a3 = 0;
        if ( v31 > v20 )
          v31 = v20;
        if ( v31 > v21 )
          v31 = v21;
        qmemcpy(v121, v108, v31);
        v108 += v31;
        v32 = a1[1] - v31;
        v109 -= v31;
        v121 += v31;
        v111 -= v31;
        a1[1] = v32;
        if ( v32 == 0 )
          goto LABEL_45;
        continue;
      case 3:
        v33 = v110;
        if ( v5 >= 0xE )
          goto LABEL_50;
        v34 = v109;
        v35 = v108;
        do
        {
          if ( v34 == 0 )
          {
            v75 = (unsigned __int8 **)a2;
            a1[8] = v33;
            a1[7] = v5;
            v85 = (unsigned __int8 *)*a2;
            v86 = a2[2];
            a2[1] = 0;
            *a2 = (int)v108;
            v82 = (unsigned __int8 *)(v108 - v85 + v86);
            v106 = a3;
            goto LABEL_130;
          }
          --v34;
          a3 = 0;
          v36 = *v35 << v5;
          v5 += 8;
          v109 = v34;
          v33 |= v36;
          v108 = ++v35;
        }
        while ( v5 < 0xE );
LABEL_50:
        v37 = v33 & 0x3FFF;
        a1[1] = v37;
        v38 = v33 & 0x1F;
        if ( v38 > 0x1D || (unsigned int)(v39 = (v37 >> 5) & 0x1F) > 0x1D )
        {
          v75 = (unsigned __int8 **)a2;
          *a1 = 9;
          v106 = -3;
          a2[6] = (int)aTooManyLengthO;
          a1[8] = v33;
LABEL_127:
          a1[7] = v5;
          v75[1] = (unsigned __int8 *)v109;
LABEL_128:
          v101 = *v75;
          *v75 = v108;
          v76 = (unsigned __int8 *)(v108 - v101);
LABEL_129:
          v82 = &v75[2][(_DWORD)v76];
LABEL_130:
          v75[2] = v82;
          a1[13] = v121;
          return inflate_flush(a1, a2: v75, a3: v106);
        }
        v40 = a2;
        v41 = ((int (__cdecl *)(int, unsigned int, int))a2[8])(a1: a2[10], a2: v39 + v38 + 258, a3: 4);
        a1[3] = v41;
        if ( v41 == 0 )
        {
          a1[8] = v33;
          a1[7] = v5;
          v87 = (unsigned __int8 *)*a2;
          v88 = a2[2];
          a2[1] = v109;
          *a2 = (int)v108;
          a2[2] = v108 - v87 + v88;
          a1[13] = v121;
          return inflate_flush(a1, a2, a3: -4);
        }
        v42 = v33 >> 14;
        v5 -= 14;
        a1[2] = 0;
        *a1 = 4;
LABEL_55:
        if ( a1[2] < (unsigned int)((a1[1] >> 10) + 4) )
        {
          while ( v5 >= 3 )
          {
LABEL_60:
            v45 = v42 & 7;
            v5 -= 3;
            v42 >>= 3;
            *(_DWORD *)(a1[3] + 4 * dword_1010FC88[a1[2]]) = v45;
            v46 = a1[2] + 1;
            a1[2] = v46;
            if ( v46 >= (a1[1] >> 10) + 4 )
              goto LABEL_61;
          }
          v43 = v108;
          while ( v109 != 0 )
          {
            --v109;
            v44 = v5;
            v5 += 8;
            a3 = 0;
            v42 |= *v43++ << v44;
            v108 = v43;
            if ( v5 >= 3 )
              goto LABEL_60;
          }
          goto LABEL_108;
        }
LABEL_61:
        if ( a1[2] < 0x13u )
        {
          do
          {
            *(_DWORD *)(a1[3] + 4 * dword_1010FC88[a1[2]]) = 0;
            v47 = a1[2] + 1;
            a1[2] = v47;
          }
          while ( v47 < 0x13 );
        }
        v104 = a1[9];
        v103 = a1[3];
        a1[4] = 7;
        v111 = inflate_trees_bits(a1: v103, a2: a1 + 4, a3: a1 + 5, a4: v104, a5: v40);
        if ( v111 != 0 )
        {
          ((void (__cdecl *)(int, _DWORD))v40[9])(a1: v40[10], a2: a1[3]);
          v91 = v111 == -3;
LABEL_113:
          if ( v91 )
            *a1 = 9;
          a1[8] = v42;
          a1[7] = v5;
          v94 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          v95 = v40[2];
          *v40 = (int)v108;
          v40[2] = v108 - v94 + v95;
          v107 = v111;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3: v107);
        }
        a1[2] = 0;
        *a1 = 5;
LABEL_66:
        v48 = v108;
        if ( a1[2] < ((a1[1] >> 5) & 0x1F) + (a1[1] & 0x1Fu) + 258 )
        {
          while ( 1 )
          {
            v49 = a1[4];
            if ( v5 < v49 )
              break;
LABEL_72:
            v52 = a1[5] + 8 * (v42 & inflate_mask[v49]);
            v53 = *(unsigned __int8 *)(v52 + 1);
            v54 = *(_DWORD *)(v52 + 4);
            v111 = v53;
            v118 = v54;
            if ( v54 >= 0x10 )
            {
              if ( v54 == 18 )
                v112 = 7;
              else
                v112 = v54 - 14;
              v110 = 8 * (v54 == 18) + 3;
              v117 = v112 + v111;
              if ( v5 < v112 + v111 )
              {
                while ( v109 != 0 )
                {
                  v55 = v5;
                  v5 += 8;
                  --v109;
                  a3 = 0;
                  v42 |= *v48++ << v55;
                  v108 = v48;
                  if ( v5 >= v117 )
                    goto LABEL_80;
                }
                goto LABEL_108;
              }
LABEL_80:
              v56 = v42 >> v111;
              v57 = a1[1];
              v110 += v56 & inflate_mask[v112];
              v42 = v56 >> v112;
              v5 -= v111 + v112;
              v58 = a1[2];
              if ( v58 + v110 > ((v57 >> 5) & 0x1F) + (v57 & 0x1F) + 258 )
                goto LABEL_111;
              if ( v118 == 16 )
              {
                if ( v58 == 0 )
                {
LABEL_111:
                  ((void (__cdecl *)(int, _DWORD))v40[9])(a1: v40[10], a2: a1[3]);
                  *a1 = 9;
                  v40[6] = (int)aInvalidBitLeng;
                  a1[8] = v42;
                  a1[7] = v5;
                  v92 = (unsigned __int8 *)*v40;
                  v40[1] = v109;
                  v93 = v40[2];
                  *v40 = (int)v108;
                  v40[2] = v108 - v92 + v93;
                  a1[13] = v121;
                  return inflate_flush(a1, a2: v40, a3: -3);
                }
                v59 = *(_DWORD *)(a1[3] + 4 * v58 - 4);
              }
              else
              {
                v59 = 0;
              }
              do
              {
                ++v58;
                *(_DWORD *)(a1[3] + 4 * v58 - 4) = v59;
                --v110;
              }
              while ( v110 != 0 );
              a1[2] = v58;
            }
            else
            {
              v5 -= v53;
              v42 >>= v53;
              *(_DWORD *)(a1[3] + 4 * a1[2]++) = v54;
            }
            if ( a1[2] >= ((a1[1] >> 5) & 0x1F) + (a1[1] & 0x1Fu) + 258 )
              goto LABEL_88;
            v48 = v108;
          }
          while ( v109 != 0 )
          {
            v50 = v5;
            v5 += 8;
            --v109;
            a3 = 0;
            v51 = *v48 << v50;
            v49 = a1[4];
            v42 |= v51;
            v108 = ++v48;
            if ( v5 >= v49 )
              goto LABEL_72;
          }
LABEL_108:
          a1[8] = v42;
          a1[7] = v5;
          v89 = v40[2];
          v90 = &v108[-*v40];
          *v40 = (int)v108;
          v40[2] = (int)&v90[v89];
          v40[1] = 0;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3);
        }
LABEL_88:
        v60 = a1[1];
        v105 = a1[9];
        v102 = a1[3];
        a1[5] = 0;
        v110 = 9;
        v112 = 6;
        v61 = inflate_trees_dynamic(
                a1: (v60 & 0x1F) + 257,
                a2: ((v60 >> 5) & 0x1F) + 1,
                a3: v102,
                a4: &v110,
                a5: &v112,
                a6: &v120,
                a7: &v119,
                a8: v105,
                a9: v40);
        v62 = a1[3];
        v111 = v61;
        ((void (__cdecl *)(int, int))v40[9])(a1: v40[10], a2: v62);
        if ( v111 != 0 )
        {
          v91 = v111 == -3;
          goto LABEL_113;
        }
        v63 = inflate_codes_new(a1: v110, a2: v112, a3: v120, a4: v119, a5: v40);
        if ( v63 == 0 )
        {
          a1[8] = v42;
          a1[7] = v5;
          v96 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          v40[2] += v108 - v96;
          *v40 = (int)v108;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3: -4);
        }
        a1[1] = v63;
        *a1 = 6;
LABEL_92:
        a1[8] = v42;
        a1[7] = v5;
        v64 = (unsigned __int8 *)*v40;
        v40[1] = v109;
        v65 = v40[2];
        *v40 = (int)v108;
        v40[2] = v108 - v64 + v65;
        a1[13] = v121;
        v66 = inflate_codes(a1, a2: v40, a3);
        if ( v66 != 1 )
          return inflate_flush(a1, a2: v40, a3: v66);
        a3 = 0;
        inflate_codes_free(a1: a1[1], a2: v40);
        v67 = (char *)a1[13];
        v68 = (unsigned __int8 *)*v40;
        v69 = v40[1];
        v5 = a1[7];
        v110 = a1[8];
        v70 = a1[12];
        v108 = v68;
        v109 = v69;
        v121 = v67;
        if ( (unsigned int)v67 >= v70 )
          v71 = a1[11] - (_DWORD)v67;
        else
          v71 = v70 - (_DWORD)v67 - 1;
        v111 = v71;
        if ( a1[6] == 0 )
        {
          *a1 = 0;
          continue;
        }
        *a1 = 7;
LABEL_119:
        a1[13] = v67;
        v66 = inflate_flush(a1, a2: v40, a3);
        v97 = (char *)a1[13];
        if ( (char *)a1[12] != v97 )
        {
          v98 = v110;
          a1[7] = v5;
          a1[8] = v98;
          v99 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          *v40 = (int)v68;
          v40[2] += v68 - v99;
          a1[13] = v97;
          return inflate_flush(a1, a2: v40, a3: v66);
        }
        *a1 = 8;
LABEL_124:
        a1[8] = v110;
        a1[7] = v5;
        v100 = (unsigned __int8 *)*v40;
        v40[1] = v109;
        v40[2] += v68 - v100;
        *v40 = (int)v68;
        a1[13] = v97;
        return inflate_flush(a1, a2: v40, a3: 1);
      case 4:
        v42 = v110;
        v40 = a2;
        goto LABEL_55;
      case 5:
        v42 = v110;
        v40 = a2;
        goto LABEL_66;
      case 6:
        v42 = v110;
        v40 = a2;
        goto LABEL_92;
      case 7:
        v67 = v121;
        v68 = v108;
        v40 = a2;
        goto LABEL_119;
      case 8:
        v97 = v121;
        v68 = v108;
        v40 = a2;
        goto LABEL_124;
      case 9:
        v75 = (unsigned __int8 **)a2;
        a1[8] = v110;
        a1[7] = v5;
        a2[1] = v109;
        v106 = -3;
        goto LABEL_128;
      default:
        v75 = (unsigned __int8 **)a2;
        a1[8] = v110;
        v106 = -2;
        goto LABEL_127;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C960
// Name: _inflate_blocks_free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks_free(_DWORD *a1, int a2)
{
  inflate_blocks_reset(a1, a2, a3: nullptr);
  (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[10]);
  (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[9]);
  (*(void (__cdecl **)(_DWORD, _DWORD *))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009C9A0
// Name: _inflate_codes_new
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes_new(char a1, char a2, int a3, int a4, int a5)
{
  int result; // eax

  result = (*(int (__cdecl **)(_DWORD, int, int))(a5 + 32))(a1: *(_DWORD *)(a5 + 40), a2: 1, a3: 28);
  if ( result != 0 )
  {
    *(_BYTE *)(result + 16) = a1;
    *(_BYTE *)(result + 17) = a2;
    *(_DWORD *)result = 0;
    *(_DWORD *)(result + 20) = a3;
    *(_DWORD *)(result + 24) = a4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009C9E0
// Name: _inflate_codes
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes(_DWORD *a1, unsigned __int8 **a2, int a3)
{
  _DWORD *v5; // eax
  unsigned __int8 *v6; // ebp
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  _BYTE *v9; // edx
  int v10; // ecx
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  bool v16; // zf
  int v17; // ecx
  unsigned int v18; // eax
  char v19; // cl
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  unsigned int v24; // eax
  char v25; // cl
  int v26; // ecx
  int v27; // ecx
  unsigned int v28; // eax
  char v29; // cl
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  unsigned int v33; // eax
  char v34; // cl
  int v35; // ecx
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  int v40; // eax
  unsigned int v41; // eax
  int v42; // ecx
  unsigned int v43; // ecx
  int v44; // eax
  int v45; // ecx
  unsigned int v46; // eax
  unsigned int v47; // ecx
  int v48; // eax
  int v49; // eax
  unsigned int v50; // eax
  int v51; // ecx
  unsigned int v52; // ecx
  int v53; // eax
  unsigned __int8 *v54; // eax
  unsigned __int8 *v55; // ecx
  unsigned __int8 *v57; // ebx
  int v58; // eax
  unsigned __int8 *v59; // ebx
  unsigned __int8 *v60; // ebx
  unsigned __int8 *v61; // ebx
  int v62; // [esp-4h] [ebp-24h]
  _DWORD *v63; // [esp+10h] [ebp-10h]
  unsigned int v64; // [esp+14h] [ebp-Ch]
  unsigned int i; // [esp+18h] [ebp-8h]
  unsigned __int8 *v66; // [esp+18h] [ebp-8h]
  unsigned int j; // [esp+18h] [ebp-8h]
  unsigned int v68; // [esp+18h] [ebp-8h]
  unsigned int k; // [esp+18h] [ebp-8h]
  _BYTE *v70; // [esp+1Ch] [ebp-4h]
  unsigned int v71; // [esp+24h] [ebp+4h]
  unsigned int v72; // [esp+28h] [ebp+8h]
  int v73; // [esp+2Ch] [ebp+Ch]

  v5 = (_DWORD *)a1[1];
  v6 = *a2;
  v7 = a1[7];
  v72 = (unsigned int)a2[1];
  v8 = a1[12];
  v71 = a1[8];
  v9 = (_BYTE *)a1[13];
  v63 = v5;
  if ( (unsigned int)v9 >= v8 )
    v10 = a1[11] - (_DWORD)v9;
  else
    v10 = v8 - (_DWORD)v9 - 1;
LABEL_4:
  v64 = v10;
  while ( 2 )
  {
    switch ( *v5 )
    {
      case 0:
        if ( v64 >= 0x102 && v72 >= 0xA )
        {
          a1[8] = v71;
          a1[7] = v7;
          v11 = *a2;
          a2[1] = (unsigned __int8 *)v72;
          v12 = a2[2];
          *a2 = v6;
          a2[2] = &v12[v6 - v11];
          a1[13] = v9;
          v13 = inflate_fast(
                  a1: *((unsigned __int8 *)v63 + 16),
                  a2: *((unsigned __int8 *)v63 + 17),
                  a3: v63[5],
                  a4: v63[6],
                  a5: a1,
                  a6: a2);
          v6 = *a2;
          v7 = a1[7];
          v72 = (unsigned int)a2[1];
          v14 = a1[12];
          v71 = a1[8];
          v9 = (_BYTE *)a1[13];
          a3 = v13;
          v15 = (unsigned int)v9 >= v14 ? a1[11] - (_DWORD)v9 : v14 - (_DWORD)v9 - 1;
          v64 = v15;
          if ( v13 != 0 )
          {
            v16 = v13 == 1;
            v5 = v63;
            *v63 = 2 * !v16 + 7;
            continue;
          }
        }
        v5 = v63;
        v17 = *((unsigned __int8 *)v63 + 16);
        *v63 = 1;
        v63[3] = v17;
        v63[2] = v63[5];
        goto LABEL_14;
      case 1:
LABEL_14:
        v18 = v5[3];
        for ( i = v18; v7 < i; v71 = v20 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v19 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v20 = (*v6 << v19) | v71;
          v18 = i;
          ++v6;
        }
        v66 = (unsigned __int8 *)(v63[2] + 8 * (v71 & inflate_mask[v18]));
        v21 = v66[1];
        v71 >>= v21;
        v7 -= v21;
        v22 = *v66;
        if ( *v66 != 0 )
        {
          if ( (v22 & 0x10) != 0 )
          {
            v5 = v63;
            v63[2] = v22 & 0xF;
            v23 = *((_DWORD *)v66 + 1);
            *v63 = 2;
            v63[1] = v23;
          }
          else
          {
            if ( (v22 & 0x40) == 0 )
              goto LABEL_22;
            v5 = v63;
            if ( (v22 & 0x20) == 0 )
            {
              *v63 = 9;
              a2[6] = (unsigned __int8 *)aInvalidLiteral;
              v62 = -3;
LABEL_96:
              a1[7] = v7;
              a1[8] = v71;
              v61 = *a2;
              a2[1] = (unsigned __int8 *)v72;
              a2[2] += v6 - v61;
LABEL_97:
              *a2 = v6;
              a1[13] = v9;
              return inflate_flush(a1, a2, a3: v62);
            }
            *v63 = 7;
          }
        }
        else
        {
          v5 = v63;
          v63[2] = *((_DWORD *)v66 + 1);
          *v63 = 6;
        }
        continue;
      case 2:
        v24 = v5[2];
        for ( j = v24; v7 < j; v71 = v26 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v25 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v26 = (*v6 << v25) | v71;
          v24 = j;
          ++v6;
        }
        v63[1] += v71 & inflate_mask[v24];
        v71 >>= j;
        v7 -= j;
        v5 = v63;
        v27 = *((unsigned __int8 *)v63 + 17);
        *v63 = 3;
        v63[3] = v27;
        v63[2] = v63[6];
LABEL_29:
        v28 = v5[3];
        v68 = v28;
        if ( v7 >= v28 )
        {
LABEL_32:
          v66 = (unsigned __int8 *)(v63[2] + 8 * (v71 & inflate_mask[v28]));
          v31 = v66[1];
          v7 -= v31;
          v71 >>= v31;
          v22 = *v66;
          if ( (v22 & 0x10) != 0 )
          {
            v5 = v63;
            v63[2] = v22 & 0xF;
            v32 = *((_DWORD *)v66 + 1);
            *v63 = 4;
            v63[3] = v32;
          }
          else
          {
            if ( (v22 & 0x40) != 0 )
            {
              v62 = -3;
              *v63 = 9;
              a2[6] = (unsigned __int8 *)aInvalidDistanc;
              goto LABEL_96;
            }
LABEL_22:
            v63[3] = v22;
            v5 = v63;
            v63[2] = &v66[8 * *((_DWORD *)v66 + 1)];
          }
          continue;
        }
        while ( v72 != 0 )
        {
          v29 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v30 = (*v6 << v29) | v71;
          v28 = v68;
          ++v6;
          v71 = v30;
          if ( v7 >= v68 )
            goto LABEL_32;
        }
LABEL_86:
        a1[7] = v7;
        a1[8] = v71;
        v54 = a2[2];
        v55 = (unsigned __int8 *)(v6 - *a2);
        a2[1] = nullptr;
        *a2 = v6;
        a2[2] = &v54[(_DWORD)v55];
        a1[13] = v9;
        return inflate_flush(a1, a2, a3);
      case 3:
        goto LABEL_29;
      case 4:
        v33 = v5[2];
        for ( k = v33; v7 < k; v71 = v35 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v34 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v35 = (*v6 << v34) | v71;
          v33 = k;
          ++v6;
        }
        v63[3] += v71 & inflate_mask[v33];
        v71 >>= k;
        v7 -= k;
        *v63 = 5;
LABEL_40:
        v36 = v63[3];
        if ( (unsigned int)&v9[-a1[10]] >= v36 )
          v70 = &v9[-v36];
        else
          v70 = &v9[a1[11] - a1[10] - v63[3]];
        v5 = v63;
        if ( v63[1] != 0 )
        {
          do
          {
            if ( v64 == 0 )
            {
              if ( v9 != (_BYTE *)a1[11]
                || (v37 = a1[12], v38 = a1[10], v37 == v38)
                || ((v9 = (_BYTE *)a1[10], v38 >= v37) ? (v39 = a1[11] - v38) : (v39 = v37 - v38 - 1),
                    v64 = v39,
                    v39 == 0) )
              {
                a1[13] = v9;
                v40 = inflate_flush(a1, a2, a3);
                v9 = (_BYTE *)a1[13];
                v73 = v40;
                v41 = a1[12];
                if ( (unsigned int)v9 >= v41 )
                  v42 = a1[11] - (_DWORD)v9;
                else
                  v42 = v41 - (_DWORD)v9 - 1;
                v64 = v42;
                if ( v9 == (_BYTE *)a1[11] )
                {
                  v43 = a1[10];
                  if ( v41 != v43 )
                  {
                    v9 = (_BYTE *)a1[10];
                    if ( v43 >= v41 )
                      v44 = a1[11] - v43;
                    else
                      v44 = v41 - v43 - 1;
                    v64 = v44;
                  }
                }
                if ( v64 == 0 )
                {
LABEL_87:
                  a1[8] = v71;
                  a1[7] = v7;
                  v57 = *a2;
                  a2[1] = (unsigned __int8 *)v72;
                  a2[2] += v6 - v57;
                  v62 = v73;
                  goto LABEL_97;
                }
              }
              v5 = v63;
            }
            ++v9;
            a3 = 0;
            *(v9 - 1) = *v70++;
            --v64;
            if ( v70 == (_BYTE *)a1[11] )
              v70 = (_BYTE *)a1[10];
            v45 = v5[1] - 1;
            v5[1] = v45;
          }
          while ( v45 != 0 );
        }
        *v5 = 0;
        continue;
      case 5:
        goto LABEL_40;
      case 6:
        if ( v64 != 0 )
          goto LABEL_84;
        if ( v9 != (_BYTE *)a1[11]
          || (v46 = a1[12], v47 = a1[10], v46 == v47)
          || ((v9 = (_BYTE *)a1[10], v47 >= v46) ? (v48 = a1[11] - v47) : (v48 = v46 - v47 - 1), v64 = v48, v48 == 0) )
        {
          a1[13] = v9;
          v49 = inflate_flush(a1, a2, a3);
          v9 = (_BYTE *)a1[13];
          v73 = v49;
          v50 = a1[12];
          if ( (unsigned int)v9 >= v50 )
            v51 = a1[11] - (_DWORD)v9;
          else
            v51 = v50 - (_DWORD)v9 - 1;
          v64 = v51;
          if ( v9 == (_BYTE *)a1[11] )
          {
            v52 = a1[10];
            if ( v50 != v52 )
            {
              v9 = (_BYTE *)a1[10];
              if ( v52 >= v50 )
                v53 = a1[11] - v52;
              else
                v53 = v50 - v52 - 1;
              v64 = v53;
            }
          }
          if ( v64 == 0 )
            goto LABEL_87;
        }
        v5 = v63;
LABEL_84:
        a3 = 0;
        *v9++ = *((_BYTE *)v5 + 8);
        v10 = v64 - 1;
        *v5 = 0;
        goto LABEL_4;
      case 7:
        if ( v7 > 7 )
        {
          v7 -= 8;
          --v6;
          ++v72;
        }
        a1[13] = v9;
        v58 = inflate_flush(a1, a2, a3);
        v9 = (_BYTE *)a1[13];
        if ( (_BYTE *)a1[12] != v9 )
        {
          a1[7] = v7;
          a1[8] = v71;
          v59 = *a2;
          a2[1] = (unsigned __int8 *)v72;
          v62 = v58;
          a2[2] += v6 - v59;
          goto LABEL_97;
        }
        *v63 = 8;
LABEL_93:
        v62 = 1;
        goto LABEL_96;
      case 8:
        goto LABEL_93;
      case 9:
        a1[8] = v71;
        a1[7] = v7;
        v60 = *a2;
        a2[1] = (unsigned __int8 *)v72;
        v62 = -3;
        a2[2] += v6 - v60;
        goto LABEL_97;
      default:
        v62 = -2;
        goto LABEL_96;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D0E0
// Name: _inflate_codes_free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes_free(int a1, int a2)
{
  return (*(int (__cdecl **)(_DWORD, int))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1009D100
// Name: _inflate_trees_bits
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_bits(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // [esp-10h] [ebp-1Ch]
  int v10; // [esp+8h] [ebp-4h] BYREF

  v10 = 0;
  v5 = (*(int (__cdecl **)(_DWORD, int, int))(a5 + 32))(a1: *(_DWORD *)(a5 + 40), a2: 19, a3: 4);
  if ( v5 == 0 )
    return -4;
  v7 = sub_1009D1B0(a1, a2: 19, a3: 19, a4: 0, a5: 0, a6: a3, a7: a2, a8: a4, a9: &v10, a10: v5);
  v8 = v7;
  if ( v7 == -3 )
  {
    v9 = *(_DWORD *)(a5 + 40);
    *(_DWORD *)(a5 + 24) = aOversubscribed_0;
    (*(void (__cdecl **)(int, int))(a5 + 36))(a1: v9, a2: v5);
    return -3;
  }
  else
  {
    if ( v7 == -5 || *a2 == 0 )
    {
      *(_DWORD *)(a5 + 24) = aIncompleteDyna;
      v8 = -3;
    }
    (*(void (__cdecl **)(_DWORD, int))(a5 + 36))(a1: *(_DWORD *)(a5 + 40), a2: v5);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D1B0
// Name: sub_1009D1B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1009D1B0(
        int *a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        int a5,
        _DWORD *a6,
        unsigned int *a7,
        int a8,
        unsigned int *a9,
        unsigned int *a10)
{
  unsigned int v10; // ebp
  int *v11; // ecx
  unsigned int v12; // edx
  int v13; // eax
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int i; // esi
  int j; // edx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  unsigned int v23; // esi
  int v24; // edi
  int *v25; // esi
  unsigned int v26; // edi
  int v27; // ecx
  int v28; // esi
  unsigned int v29; // edi
  signed int v30; // ecx
  int v31; // ebx
  unsigned int v32; // esi
  unsigned int m; // ecx
  unsigned int v34; // edx
  unsigned int v35; // ecx
  unsigned int v36; // eax
  _DWORD *v37; // ebp
  unsigned int v38; // eax
  unsigned int v39; // edi
  unsigned int v40; // eax
  unsigned int v41; // edx
  int v42; // ebp
  unsigned int v43; // eax
  int v44; // ecx
  int v45; // esi
  int v46; // edx
  unsigned int v47; // eax
  _DWORD *v48; // ecx
  unsigned int k; // eax
  int v50; // eax
  unsigned int v51; // [esp+10h] [ebp-FCh]
  signed int v52; // [esp+14h] [ebp-F8h]
  int v53; // [esp+18h] [ebp-F4h]
  int v54; // [esp+1Ch] [ebp-F0h]
  int *v55; // [esp+20h] [ebp-ECh]
  unsigned int *v56; // [esp+20h] [ebp-ECh]
  _DWORD *v57; // [esp+24h] [ebp-E8h]
  signed int v58; // [esp+28h] [ebp-E4h]
  unsigned int v59; // [esp+2Ch] [ebp-E0h]
  unsigned int v60; // [esp+30h] [ebp-DCh]
  int v61; // [esp+30h] [ebp-DCh]
  int v62; // [esp+34h] [ebp-D8h]
  unsigned int v63; // [esp+38h] [ebp-D4h]
  signed int v64; // [esp+3Ch] [ebp-D0h]
  char v65; // [esp+40h] [ebp-CCh]
  unsigned int v66; // [esp+44h] [ebp-C8h]
  _DWORD *v67; // [esp+48h] [ebp-C4h]
  int v68; // [esp+4Ch] [ebp-C0h]
  int v69; // [esp+50h] [ebp-BCh] BYREF
  _DWORD v70[15]; // [esp+54h] [ebp-B8h] BYREF
  int v71; // [esp+90h] [ebp-7Ch]
  _DWORD v72[15]; // [esp+94h] [ebp-78h]
  _DWORD v73[15]; // [esp+D0h] [ebp-3Ch] BYREF
  int v74; // [esp+114h] [ebp+8h]

  v10 = 0;
  v69 = 0;
  memset(v70, 0, sizeof(v70));
  v11 = a1;
  v12 = a2;
  do
  {
    v13 = *v11++;
    --v12;
    ++v70[v13 - 1];
  }
  while ( v12 != 0 );
  if ( v69 == a2 )
  {
    *a6 = 0;
    *a7 = 0;
    return 0;
  }
  v15 = *a7;
  v16 = 1;
  v51 = *a7;
  do
  {
    if ( v70[v16 - 1] != 0 )
      break;
    ++v16;
  }
  while ( v16 <= 0xF );
  v52 = v16;
  if ( v15 < v16 )
  {
    v51 = v16;
    v15 = v16;
  }
  for ( i = 15; i != 0; --i )
  {
    if ( v70[i - 1] != 0 )
      break;
  }
  v58 = i;
  if ( v15 > i )
  {
    v51 = i;
    v15 = i;
  }
  *a7 = v15;
  for ( j = 1 << v16; v16 < i; j = 2 * v19 )
  {
    v19 = j - v70[v16 - 1];
    if ( v19 < 0 )
      return -3;
    ++v16;
  }
  v60 = i;
  v20 = v70[i - 1];
  v21 = j - v20;
  v68 = v21;
  if ( v21 < 0 )
    return -3;
  v72[0] = 0;
  v70[i - 1] = v21 + v20;
  v22 = 0;
  v23 = i - 1;
  if ( v23 != 0 )
  {
    v24 = 0;
    do
    {
      v22 += v70[v24++];
      --v23;
      v72[v24] = v22;
    }
    while ( v23 != 0 );
  }
  v25 = a1;
  v26 = 0;
  do
  {
    v27 = *v25++;
    v55 = v25;
    if ( v27 != 0 )
    {
      v28 = v72[v27 - 1];
      a10[v28] = v26;
      v72[v27 - 1] = v28 + 1;
      v25 = v55;
    }
    ++v26;
  }
  while ( v26 < a2 );
  v29 = 0;
  v59 = 0;
  v74 = v72[v60 - 1];
  v56 = a10;
  v30 = v52;
  v31 = -v15;
  v71 = 0;
  v53 = -1;
  v73[0] = 0;
  v61 = 0;
  if ( v52 > v58 )
  {
LABEL_66:
    if ( v21 == 0 || v58 == 1 )
      return 0;
    return -5;
  }
  else
  {
    v32 = v63;
    v65 = v52 - 1;
    v57 = &v70[v52 - 1];
    while ( 1 )
    {
      v54 = *v57;
      if ( *v57 != 0 )
        break;
LABEL_64:
      v52 = ++v30;
      ++v57;
      ++v65;
      if ( v30 > v58 )
      {
        v21 = v68;
        goto LABEL_66;
      }
    }
    while ( 1 )
    {
      --v54;
      if ( v52 > (int)(v31 + v15) )
        break;
LABEL_47:
      if ( v56 < &a10[v74] )
      {
        v32 = *v56;
        if ( *v56 >= a3 )
        {
          v45 = 4 * (v32 - a3);
          LOBYTE(v62) = *(_BYTE *)(v45 + a5) + 80;
          v32 = *(_DWORD *)(v45 + a4);
        }
        else
        {
          LOBYTE(v62) = v32 < 0x100 ? 0 : 96;
        }
        ++v56;
      }
      else
      {
        LOBYTE(v62) = -64;
      }
      v46 = 1 << (v52 - v31);
      v47 = v10 >> v31;
      if ( v10 >> v31 < v29 )
      {
        v48 = (_DWORD *)(v61 + 8 * v47);
        do
        {
          v48[1] = v32;
          BYTE1(v62) = v52 - v31;
          *v48 = v62;
          v47 += v46;
          v48 += 2 * v46;
        }
        while ( v47 < v29 );
        v10 = v59;
      }
      for ( k = 1 << v65; (k & v10) != 0; k >>= 1 )
        v10 ^= k;
      v10 ^= k;
      v50 = v53;
      v59 = v10;
      if ( (v10 & ((1 << v31) - 1)) != v72[v53 - 1] )
      {
        do
        {
          --v50;
          v31 -= v51;
        }
        while ( (v10 & ((1 << v31) - 1)) != v72[v50 - 1] );
        v53 = v50;
      }
      v15 = v51;
      if ( v54 == 0 )
      {
        v30 = v52;
        goto LABEL_64;
      }
    }
    v64 = v31 + v15;
    for ( m = v31 - v15; ; m = v66 )
    {
      v31 += v15;
      ++v53;
      v34 = v58 - v31;
      v66 = v15 + m;
      v64 += v15;
      if ( v58 - v31 > v15 )
        v34 = v15;
      v35 = v52 - v31;
      v36 = 1 << (v52 - v31);
      if ( v36 > v54 + 1 )
      {
        v37 = v57;
        v38 = -1 - v54 + v36;
        if ( v35 < v34 && ++v35 < v34 )
        {
          do
          {
            v39 = v37[1];
            ++v37;
            v40 = 2 * v38;
            if ( v40 <= v39 )
              break;
            v38 = v40 - v39;
            ++v35;
          }
          while ( v35 < v34 );
        }
      }
      v29 = 1 << v35;
      v41 = *a9 + (1 << v35);
      if ( v41 > 0x5A0 )
        break;
      v42 = a8 + 8 * *a9;
      v61 = v42;
      v67 = &v73[v53];
      *v67 = v42;
      *a9 = v41;
      if ( v53 != 0 )
      {
        LOBYTE(v62) = v35;
        v72[v53 - 1] = v59;
        v43 = v59 >> v66;
        BYTE1(v62) = v51;
        v44 = *(v67 - 1);
        v32 = ((v42 - v44) >> 3) - (v59 >> v66);
        *(_DWORD *)(v44 + 8 * v43) = v62;
        *(_DWORD *)(v44 + 8 * v43 + 4) = v32;
      }
      else
      {
        *a6 = v42;
      }
      if ( v52 <= v64 )
      {
        v10 = v59;
        goto LABEL_47;
      }
      v15 = v51;
    }
    return -4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D660
// Name: _inflate_trees_dynamic
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_dynamic(
        unsigned int a1,
        unsigned int a2,
        int *a3,
        unsigned int *a4,
        unsigned int *a5,
        _DWORD *a6,
        _DWORD *a7,
        int a8,
        int a9)
{
  unsigned int *v9; // edi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // [esp-Ch] [ebp-20h]
  int v15; // [esp-8h] [ebp-1Ch]
  int v16; // [esp-8h] [ebp-1Ch]
  int v17; // [esp-8h] [ebp-1Ch]
  unsigned int v18; // [esp+10h] [ebp-4h] BYREF

  v14 = *(_DWORD *)(a9 + 40);
  v18 = 0;
  v9 = (unsigned int *)(*(int (__cdecl **)(int, int, int))(a9 + 32))(a1: v14, a2: 288, a3: 4);
  if ( v9 == nullptr )
    return -4;
  v11 = sub_1009D1B0(
          a1: a3,
          a2: a1,
          a3: 0x101u,
          a4: (int)&unk_1010FD08,
          a5: (int)&unk_1010FD88,
          a6,
          a7: a4,
          a8,
          a9: &v18,
          a10: v9);
  v12 = v11;
  if ( v11 != 0 )
  {
    if ( v11 == -3 )
    {
      v17 = *(_DWORD *)(a9 + 40);
      *(_DWORD *)(a9 + 24) = aOversubscribed_1;
      (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v17, a2: v9);
      return -3;
    }
    if ( v11 == -4 )
      goto LABEL_20;
LABEL_19:
    *(_DWORD *)(a9 + 24) = aIncompleteLite;
    v12 = -3;
    goto LABEL_20;
  }
  if ( *a4 == 0 )
    goto LABEL_19;
  v13 = sub_1009D1B0(
          a1: &a3[a1],
          a2,
          a3: 0,
          a4: (int)&unk_1010FE08,
          a5: (int)&unk_1010FE80,
          a6: a7,
          a7: a5,
          a8,
          a9: &v18,
          a10: v9);
  v12 = v13;
  if ( v13 != 0 )
  {
    switch ( v13 )
    {
      case -3:
        v15 = *(_DWORD *)(a9 + 40);
        *(_DWORD *)(a9 + 24) = aOversubscribed;
        (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v15, a2: v9);
        return -3;
      case -5:
        v16 = *(_DWORD *)(a9 + 40);
        *(_DWORD *)(a9 + 24) = aIncompleteDist;
        (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v16, a2: v9);
        return -3;
      case -4:
        goto LABEL_20;
      default:
        break;
    }
  }
  else if ( *a5 != 0 || a1 <= 0x101 )
  {
    (*(void (__cdecl **)(_DWORD, unsigned int *))(a9 + 36))(a1: *(_DWORD *)(a9 + 40), a2: v9);
    return 0;
  }
  *(_DWORD *)(a9 + 24) = aEmptyDistanceT;
  v12 = -3;
LABEL_20:
  (*(void (__cdecl **)(_DWORD, unsigned int *))(a9 + 36))(a1: *(_DWORD *)(a9 + 40), a2: v9);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1009D7F0
// Name: _inflate_trees_fixed
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_fixed(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  *a1 = dword_101379D0;
  *a2 = dword_101379D4;
  *a3 = &unk_101379D8;
  *a4 = &unk_101389D8;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009D820
// Name: _inflate_flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_flush(_DWORD *a1, _DWORD *a2, int a3)
{
  unsigned int v3; // ebp
  char *v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // edx
  int (__cdecl *v8)(_DWORD, char *, unsigned int); // eax
  int v9; // eax
  char *v10; // eax
  char *v11; // ecx
  char *v12; // esi
  unsigned int v13; // ebp
  unsigned int v14; // eax
  unsigned int v15; // edx
  int (__cdecl *v16)(_DWORD, char *, unsigned int); // eax
  int v17; // eax
  char *v18; // edi
  char *v20; // [esp+10h] [ebp-4h]
  char *v21; // [esp+10h] [ebp-4h]

  v3 = a1[13];
  v4 = (char *)a1[12];
  v20 = (char *)a2[3];
  if ( (unsigned int)v4 > v3 )
    v3 = a1[11];
  v5 = a2[4];
  v6 = v3 - (_DWORD)v4;
  if ( v6 > v5 )
    v6 = a2[4];
  if ( v6 != 0 && a3 == -5 )
    a3 = 0;
  v7 = v6 + a2[5];
  a2[4] = v5 - v6;
  a2[5] = v7;
  v8 = (int (__cdecl *)(_DWORD, char *, unsigned int))a1[14];
  if ( v8 != nullptr )
  {
    v9 = v8(a1: a1[15], a2: v4, a3: v6);
    a1[15] = v9;
    a2[12] = v9;
  }
  qmemcpy(v20, v4, v6);
  v10 = &v4[v6];
  v11 = (char *)a1[11];
  v21 = &v20[v6];
  if ( &v4[v6] == v11 )
  {
    v12 = (char *)a1[10];
    if ( (char *)a1[13] == v11 )
      a1[13] = v12;
    v13 = a1[13] - (_DWORD)v12;
    v14 = a2[4];
    if ( v13 > v14 )
      v13 = a2[4];
    if ( v13 != 0 && a3 == -5 )
      a3 = 0;
    v15 = v13 + a2[5];
    a2[4] = v14 - v13;
    a2[5] = v15;
    v16 = (int (__cdecl *)(_DWORD, char *, unsigned int))a1[14];
    if ( v16 != nullptr )
    {
      v17 = v16(a1: a1[15], a2: v12, a3: v13);
      a1[15] = v17;
      a2[12] = v17;
    }
    qmemcpy(v21, v12, 4 * (v13 >> 2));
    v18 = &v21[4 * (v13 >> 2)];
    v21 += v13;
    v10 = &v12[v13];
    qmemcpy(v18, &v12[4 * (v13 >> 2)], v13 & 3);
  }
  a2[3] = v21;
  a1[12] = v10;
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x1009D960
// Name: _inflate_fast
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_fast(int a1, int a2, int a3, unsigned __int8 *a4, _DWORD *a5, unsigned __int8 **a6)
{
  _BYTE *v6; // ebx
  unsigned int v7; // esi
  unsigned int v8; // edx
  unsigned __int8 **v9; // edi
  unsigned __int8 *v10; // ebp
  unsigned int v11; // eax
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // ebx
  int v19; // esi
  unsigned __int8 *v20; // esi
  int i; // ecx
  int v22; // ecx
  int v23; // ebx
  unsigned int j; // ebx
  char v25; // cl
  unsigned int v26; // edi
  int v27; // esi
  _BYTE *v28; // ecx
  _BYTE *v29; // esi
  unsigned int v30; // edi
  unsigned int v31; // ecx
  unsigned __int8 *v32; // ebp
  unsigned __int8 *v33; // edx
  int v34; // ecx
  unsigned int v36; // ecx
  unsigned __int8 *v37; // ebp
  unsigned __int8 *v38; // edx
  unsigned __int8 *v39; // ecx
  unsigned int v40; // ecx
  unsigned __int8 *v41; // ebp
  unsigned __int8 *v42; // edx
  unsigned __int8 *v43; // ecx
  unsigned int v44; // [esp+10h] [ebp-14h]
  _BYTE *v45; // [esp+14h] [ebp-10h]
  unsigned int v46; // [esp+18h] [ebp-Ch]
  int v47; // [esp+1Ch] [ebp-8h]
  int v48; // [esp+20h] [ebp-4h]
  unsigned int v49; // [esp+28h] [ebp+4h]

  v6 = (_BYTE *)a5[13];
  v7 = a5[12];
  v8 = a5[8];
  v9 = a6;
  v45 = v6;
  v10 = *a6;
  v44 = (unsigned int)a6[1];
  v11 = a5[7];
  if ( (unsigned int)v6 >= v7 )
    v46 = a5[11] - (_DWORD)v6;
  else
    v46 = v7 - (_DWORD)v6 - 1;
  v47 = inflate_mask[a1];
  v48 = inflate_mask[a2];
  do
  {
    for ( ; v11 < 0x14; ++v10 )
    {
      --v44;
      v12 = *v10 << v11;
      v11 += 8;
      v8 |= v12;
    }
    v13 = *(unsigned __int8 *)(a3 + 8 * (v8 & v47));
    v14 = a3 + 8 * (v8 & v47);
    if ( *(_BYTE *)v14 != 0 )
    {
      while ( 1 )
      {
        v15 = *(unsigned __int8 *)(v14 + 1);
        v8 >>= v15;
        v11 -= v15;
        if ( (v13 & 0x10) != 0 )
          break;
        if ( (v13 & 0x40) != 0 )
        {
          if ( (v13 & 0x20) != 0 )
          {
            v36 = (unsigned int)&v9[1][-v44];
            if ( v11 >> 3 < v36 )
              v36 = v11 >> 3;
            v37 = &v10[-v36];
            a5[8] = v8;
            a5[7] = v11 - 8 * v36;
            v38 = *v9;
            v9[1] = (unsigned __int8 *)(v44 + v36);
            v39 = v9[2];
            *v9 = v37;
            v9[2] = &v39[v37 - v38];
            a5[13] = v45;
            return 1;
          }
          else
          {
            v9[6] = (unsigned __int8 *)aInvalidLiteral;
LABEL_40:
            v40 = (unsigned int)&v9[1][-v44];
            if ( v11 >> 3 < v40 )
              v40 = v11 >> 3;
            v41 = &v10[-v40];
            a5[8] = v8;
            a5[7] = v11 - 8 * v40;
            v42 = *v9;
            v9[1] = (unsigned __int8 *)(v44 + v40);
            v43 = v9[2];
            *v9 = v41;
            v9[2] = &v43[v41 - v42];
            a5[13] = v45;
            return -3;
          }
        }
        v16 = *(_DWORD *)(v14 + 4) + (v8 & inflate_mask[v13]);
        v13 = *(unsigned __int8 *)(v14 + 8 * v16);
        v14 += 8 * v16;
        if ( v13 == 0 )
          goto LABEL_11;
      }
      v18 = v13 & 0xF;
      v11 -= v18;
      v49 = *(_DWORD *)(v14 + 4) + (v8 & inflate_mask[v18]);
      for ( v8 >>= v18; v11 < 0xF; ++v10 )
      {
        --v44;
        v19 = *v10 << v11;
        v11 += 8;
        v8 |= v19;
      }
      v20 = a4;
      for ( i = v8 & v48; ; i = *((_DWORD *)v20 + 1) + (v8 & inflate_mask[v23]) )
      {
        v20 += 8 * i;
        v22 = v20[1];
        v23 = *v20;
        v8 >>= v22;
        v11 -= v22;
        if ( (v23 & 0x10) != 0 )
          break;
        if ( (v23 & 0x40) != 0 )
        {
          v9[6] = (unsigned __int8 *)aInvalidDistanc;
          goto LABEL_40;
        }
      }
      for ( j = v23 & 0xF; v11 < j; ++v10 )
      {
        --v44;
        v25 = v11;
        v11 += 8;
        v8 |= *v10 << v25;
      }
      v26 = *((_DWORD *)v20 + 1) + (v8 & inflate_mask[j]);
      v8 >>= j;
      v11 -= j;
      v46 -= v49;
      v27 = a5[10];
      v28 = v45;
      if ( (unsigned int)&v45[-v27] < v26 )
      {
        v30 = v26 + v27 - (_DWORD)v45;
        v29 = (_BYTE *)(a5[11] - v30);
        if ( v49 > v30 )
        {
          v49 -= v30;
          do
          {
            *v28++ = *v29++;
            --v30;
          }
          while ( v30 != 0 );
          v29 = (_BYTE *)a5[10];
        }
      }
      else
      {
        *v45 = v45[-v26];
        v28 = v45 + 2;
        v29 = &v45[-v26 + 2];
        v45[1] = v45[-v26 + 1];
        v49 -= 2;
      }
      do
      {
        *v28++ = *v29++;
        --v49;
      }
      while ( v49 != 0 );
      v9 = a6;
      v45 = v28;
    }
    else
    {
LABEL_11:
      v17 = *(unsigned __int8 *)(v14 + 1);
      v11 -= v17;
      v8 >>= v17;
      *v45++ = *(_BYTE *)(v14 + 4);
      --v46;
    }
  }
  while ( v46 >= 0x102 && v44 >= 0xA );
  v31 = (unsigned int)&v9[1][-v44];
  if ( v11 >> 3 < v31 )
    v31 = v11 >> 3;
  v32 = &v10[-v31];
  a5[8] = v8;
  a5[7] = v11 - 8 * v31;
  v33 = *v9;
  v9[1] = (unsigned __int8 *)(v44 + v31);
  v34 = (int)&v9[2][v32 - v33];
  *v9 = v32;
  v9[2] = (unsigned __int8 *)v34;
  a5[13] = v45;
  return 0;
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x10035B30
// Name: ZLibDecompress
// Source: json
//------------------------------------------------------------------------------
bool __usercall ZLibDecompress@<al>(
        unsigned int inputLen@<eax>,
        unsigned __int8 *pOut@<edi>,
        unsigned __int8 *pInput,
        int outLen)
{
  unsigned __int8 *v6; // esi
  unsigned int v7; // eax
  z_stream_s decompressStream; // [esp+8h] [ebp-38h] BYREF

  if ( inputLen == 0 )
    return true;
  memset(dst: (unsigned __int8 *)&decompressStream, value: 0, count: sizeof(decompressStream));
  if ( inflateInit_(a1: &decompressStream, a2: "1.1.3", a3: 56) == 0 )
  {
    decompressStream.avail_in = inputLen;
    decompressStream.next_in = pInput;
    v6 = pOut;
    do
    {
      decompressStream.total_out = 0;
      decompressStream.next_out = v6;
      decompressStream.avail_out = outLen + pOut - v6;
      v7 = inflate(a1: &decompressStream, a2: 0);
      if ( v7 > 1 )
        break;
      v6 += decompressStream.total_out;
      if ( v7 == 1 )
        return v6 - pOut == outLen;
    }
    while ( decompressStream.avail_in != 0 );
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10035BD0
// Name: public: void CWorkerMulticastListener::FlushAckChunks(unsigned short (__near * const)[2],int __near &,unsigned long __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerMulticastListener::FlushAckChunks(
        CWorkerMulticastListener *this,
        unsigned __int16 (*chunksToAck)[2],
        int *nChunksToAck,
        unsigned int *lastAckTime)
{
  int *v4; // esi
  int v5; // eax
  void *pChunks[2]; // [esp+4h] [ebp-10h] BYREF
  int chunkLengths[2]; // [esp+Ch] [ebp-8h] BYREF

  v4 = nChunksToAck;
  v5 = *nChunksToAck;
  if ( *nChunksToAck != 0 )
  {
    pChunks[0] = &nChunksToAck;
    pChunks[1] = chunksToAck;
    LOWORD(nChunksToAck) = 768;
    chunkLengths[0] = 2;
    chunkLengths[1] = 4 * v5;
    VMPI_SendChunks((const void *const *)pChunks, pChunkLengths: chunkLengths, nChunks: 2, iDest: 0, fVMPISendFlags: 0);
    *v4 = 0;
  }
  *lastAckTime = GetTickCount();
}

//------------------------------------------------------------------------------
// Address: 0x10035C30
// Name: public: void CWorkerMulticastListener::AddAckChunk(unsigned short (__near * const)[2],int __near &,unsigned long __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerMulticastListener::AddAckChunk(
        CWorkerMulticastListener *this,
        unsigned __int16 (*chunksToAck)[2],
        int *nChunksToAck,
        unsigned int *lastAckTime,
        unsigned __int16 fileID,
        unsigned __int16 iChunk)
{
  int *v6; // esi
  int v7; // eax
  void *pChunks[2]; // [esp+8h] [ebp-10h] BYREF
  int pChunkLengths[2]; // [esp+10h] [ebp-8h] BYREF

  v6 = nChunksToAck;
  (*chunksToAck)[2 * *nChunksToAck] = fileID;
  (*chunksToAck)[2 * (*v6)++ + 1] = iChunk;
  if ( *v6 == 512 || VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_TCP )
  {
    v7 = *v6;
    if ( *v6 != 0 )
    {
      pChunks[0] = &nChunksToAck;
      LOWORD(nChunksToAck) = 768;
      pChunks[1] = chunksToAck;
      pChunkLengths[0] = 2;
      pChunkLengths[1] = 4 * v7;
      VMPI_SendChunks((const void *const *)pChunks, pChunkLengths, nChunks: 2, iDest: 0, fVMPISendFlags: 0);
      *v6 = 0;
    }
    *lastAckTime = GetTickCount();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035CC0
// Name: public: void CWorkerMulticastListener::ShowSDKWorkerMsg(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CWorkerMulticastListener::ShowSDKWorkerMsg(CWorkerMulticastListener *this, char *pMsg, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+10h] BYREF

  va_start(params, pMsg);
  if ( !g_bMPIMaster && VMPI_IsSDKMode() )
  {
    V_vsnprintf(pDest, maxLen: 0x1000u, pFormat: pMsg, params);
    _Msg(a1: "%s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035D20
// Name: public: virtual enum InitReturnVal_t CWorkerVMPIFileSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerVMPIFileSystem::Init(CWorkerVMPIFileSystem *this)
{
  int v2; // eax
  unsigned __int16 port; // cx
  CIPAddr mcAddr; // [esp+4h] [ebp-8h] BYREF

  CIPAddr::CIPAddr(this: &mcAddr);
  while ( !g_bReceivedMulticastIP )
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
  v2 = *(_DWORD *)g_MulticastIP.ip;
  port = g_MulticastIP.port;
  *(_DWORD *)this->m_Listener.m_MulticastAddr.ip = *(_DWORD *)g_MulticastIP.ip;
  *(_DWORD *)mcAddr.ip = v2;
  mcAddr.port = port;
  this->m_Listener.m_MulticastAddr.port = port;
  this->m_Listener.m_hMainThread = GetCurrentThread();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035D80
// Name: public: virtual void CWorkerVMPIFileSystem::CreateVirtualFile(char const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::CreateVirtualFile(
        CWorkerVMPIFileSystem *this,
        const char *pFilename,
        const char *pData,
        const void *fileLength)
{
  _Error(a1: "CreateVirtualFile not supported in VMPI worker filesystem.");
}

//------------------------------------------------------------------------------
// Address: 0x10035D90
// Name: public: virtual long CWorkerVMPIFileSystem::GetFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerVMPIFileSystem::GetFileTime(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        const char *pathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035DB0
// Name: public: virtual bool CWorkerVMPIFileSystem::IsFileWritable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerVMPIFileSystem::IsFileWritable(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        const char *pPathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10035DD0
// Name: public: virtual bool CWorkerVMPIFileSystem::SetFileWritable(char const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorkerVMPIFileSystem::SetFileWritable(
        CWorkerVMPIFileSystem *this,
        const char *pFileName,
        bool writable,
        const char *pPathID)
{
  _Error(a1: "GetFileTime not supported in VMPI worker filesystem.");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10035DF0
// Name: public: virtual class CSysModule __near * CWorkerVMPIFileSystem::LoadModule(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
HINSTANCE__ *__thiscall CWorkerVMPIFileSystem::LoadModule(
        CWorkerVMPIFileSystem *this,
        char *pFileName,
        const char *pPathID,
        bool bValidatedDllOnly)
{
  return Sys_LoadModule(pModuleName: pFileName);
}

//------------------------------------------------------------------------------
// Address: 0x10035E10
// Name: public: virtual void CWorkerVMPIFileSystem::UnloadModule(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::UnloadModule(CWorkerVMPIFileSystem *this, struct CSysModule *pModule)
{
  Sys_UnloadModule(pModule);
}

//------------------------------------------------------------------------------
// Address: 0x10036090
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::FindWorkerFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::FindWorkerFile(
        CWorkerMulticastListener *this,
        const char *pFilename,
        const char *pPathID)
{
  int m_Head; // esi
  int v5; // esi
  CWorkerFile *m_Element; // edi

  m_Head = this->m_WorkerFiles.m_Head;
  if ( m_Head == -1 )
    return nullptr;
  while ( 1 )
  {
    v5 = m_Head;
    m_Element = this->m_WorkerFiles.m_Memory.m_pMemory[v5].m_Element;
    if ( _V_stricmp(s1: m_Element->m_Filename.m_Memory.m_pMemory, s2: pFilename) == 0
      && _V_stricmp(s1: m_Element->m_PathID.m_Memory.m_pMemory, s2: pPathID) == 0 )
    {
      break;
    }
    m_Head = this->m_WorkerFiles.m_Memory.m_pMemory[v5].m_Next;
    if ( m_Head == -1 )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x10036380
// Name: public: int CWorkerMulticastListener::CheckFileChunkPackets(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkerMulticastListener::CheckFileChunkPackets(
        CWorkerMulticastListener *this,
        char *data,
        int dataSize)
{
  CFileChunkPacket *m_Element; // edi
  int m_Head; // esi
  int v6; // esi
  unsigned int m_Len; // [esp-Ch] [ebp-14h]
  CCriticalSectionLock csLock; // [esp+0h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( g_FileChunkPackets.m_ElementCount > 0 )
  {
    m_Element = g_FileChunkPackets.m_Memory.m_pMemory[g_FileChunkPackets.m_Head].m_Element;
    m_Head = g_FileChunkPackets.m_Head;
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: &g_FileChunkPackets,
      elem: g_FileChunkPackets.m_Head);
    g_FileChunkPackets.m_Memory.m_pMemory[m_Head].m_Next = g_FileChunkPackets.m_FirstFree;
    g_FileChunkPackets.m_FirstFree = m_Head;
    m_Len = m_Element->m_Len;
    if ( m_Element->m_Len <= dataSize )
    {
      memcpy(dst: (unsigned __int8 *)data, src: (unsigned __int8 *)m_Element->m_Data, count: m_Len);
      v6 = m_Element->m_Len;
    }
    else
    {
      v6 = -1;
      _Warning(a1: "CWorkerMulticastListener::ListenFor: Got a section of data too long (%d bytes).", m_Len);
    }
    free(pBlock: m_Element);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return v6;
  }
  else
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036440
// Name: public: virtual void CWorkerVMPIFileSystem::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkerVMPIFileSystem::Term(CWorkerVMPIFileSystem *this)
{
  CUtlLinkedList<CWorkerFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Listener.m_WorkerFiles);
}

//------------------------------------------------------------------------------
// Address: 0x100364C0
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::RequestFileFromServer(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::RequestFileFromServer(
        CWorkerMulticastListener *this,
        const char *pFilename,
        const char *pPathID)
{
  char v3; // bl
  int m_Size; // esi
  int v5; // eax
  CFileResponse *m_pMemory; // ecx
  __int64 v7; // xmm0_8
  CFileResponse *v8; // edx
  CWorkerFile *v10; // eax
  CWorkerFile *v11; // ebx
  unsigned int v12; // eax
  int v13; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v15; // ecx
  signed int v16; // eax
  const char *v17; // ecx
  char *v18; // esi
  char v19; // al
  unsigned int v20; // eax
  int v21; // edi
  int v22; // eax
  unsigned __int8 *v23; // ecx
  signed int v24; // eax
  const char *v25; // ecx
  char *v26; // esi
  char v27; // al
  CWorkerMulticastListener *v28; // esi
  int v29; // eax
  UtlLinkedListElem_t<CWorkerFile *,int> *v30; // edi
  UtlLinkedListElem_t<CWorkerFile *,int> *v31; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<CWorkerFile *,int> *v34; // ecx
  int v35; // edx
  int m_Tail; // edi
  CWorkerFile **p_m_Element; // esi
  bool m_bZeroLength; // dl
  CWorkerMulticastListener *v39; // eax
  const void *pChunks[4]; // [esp+Ch] [ebp-44h] BYREF
  int chunkLengths[4]; // [esp+1Ch] [ebp-34h] BYREF
  CFileResponse response; // [esp+2Ch] [ebp-24h]
  CCriticalSectionLock csLock; // [esp+38h] [ebp-18h] BYREF
  CWorkerMulticastListener *v44; // [esp+40h] [ebp-10h]
  CWorkerFile *pTestFile; // [esp+44h] [ebp-Ch]
  int requestID; // [esp+48h] [ebp-8h] BYREF
  unsigned __int8 packetID[2]; // [esp+4Ch] [ebp-4h] BYREF

  v44 = this;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
  CCriticalSectionLock::Lock(this: &csLock);
  requestID = g_RequestID++;
  CCriticalSectionLock::Unlock(this: &csLock);
  pChunks[0] = packetID;
  *(_WORD *)packetID = 256;
  pChunks[1] = &requestID;
  pChunks[2] = pFilename;
  pChunks[3] = pPathID;
  chunkLengths[0] = 2;
  chunkLengths[1] = 4;
  chunkLengths[2] = strlen(pFilename) + 1;
  chunkLengths[3] = strlen(pPathID) + 1;
  VMPI_SendChunks(pChunks, pChunkLengths: chunkLengths, nChunks: 4, iDest: 0, fVMPISendFlags: 0);
  response.m_Response = -1;
  response.m_bZeroLength = true;
  while ( 1 )
  {
    v3 = 0;
    CCriticalSectionLock::Lock(this: &csLock);
    m_Size = g_FileResponses.m_Size;
    v5 = 0;
    if ( g_FileResponses.m_Size > 0 )
    {
      m_pMemory = g_FileResponses.m_Memory.m_pMemory;
      while ( m_pMemory->m_RequestID != requestID )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= g_FileResponses.m_Size )
          goto LABEL_10;
      }
      v7 = *(_QWORD *)&g_FileResponses.m_Memory.m_pMemory[v5].m_RequestID;
      v8 = &g_FileResponses.m_Memory.m_pMemory[v5];
      *(_DWORD *)&response.m_bZeroLength = *(_DWORD *)&v8->m_bZeroLength;
      *(_QWORD *)&response.m_RequestID = v7;
      if ( g_FileResponses.m_Size - v5 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)v8,
          src: (unsigned __int8 *)&v8[1],
          count: 12 * (g_FileResponses.m_Size - v5 - 1));
        m_Size = g_FileResponses.m_Size;
      }
      g_FileResponses.m_Size = m_Size - 1;
      v3 = 1;
    }
LABEL_10:
    CCriticalSectionLock::Unlock(this: &csLock);
    if ( v3 != 0 )
      break;
    if ( GetCurrentThread() == v44->m_hMainThread )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x14);
    else
      Sleep(dwMilliseconds: 0x14u);
  }
  if ( response.m_Response == -1 )
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return nullptr;
  }
  else
  {
    v10 = (CWorkerFile *)operator new(size: 0x78u);
    if ( v10 != nullptr )
    {
      LODWORD(v10->m_Timer.m_Duration.m_Int64) = 0;
      HIDWORD(v10->m_Timer.m_Duration.m_Int64) = 0;
      v10->m_Filename.m_Memory.m_pMemory = nullptr;
      v10->m_Filename.m_Memory.m_nAllocationCount = 0;
      v10->m_Filename.m_Memory.m_nGrowSize = 0;
      v10->m_Filename.m_Size = 0;
      v10->m_Filename.m_pElements = nullptr;
      v10->m_PathID.m_Memory.m_pMemory = nullptr;
      v10->m_PathID.m_Memory.m_nAllocationCount = 0;
      v10->m_PathID.m_Memory.m_nGrowSize = 0;
      v10->m_PathID.m_Size = 0;
      v10->m_PathID.m_pElements = nullptr;
      v10->m_CompressedData.m_Memory.m_pMemory = nullptr;
      v10->m_CompressedData.m_Memory.m_nAllocationCount = 0;
      v10->m_CompressedData.m_Memory.m_nGrowSize = 0;
      v10->m_CompressedData.m_Size = 0;
      v10->m_CompressedData.m_pElements = nullptr;
      v10->m_ChunksReceived.m_Memory.m_pMemory = nullptr;
      v10->m_ChunksReceived.m_Memory.m_nAllocationCount = 0;
      v10->m_ChunksReceived.m_Memory.m_nGrowSize = 0;
      v10->m_ChunksReceived.m_Size = 0;
      v10->m_ChunksReceived.m_pElements = nullptr;
      v10->m_UncompressedData.m_Memory.m_pMemory = nullptr;
      v10->m_UncompressedData.m_Memory.m_nAllocationCount = 0;
      v10->m_UncompressedData.m_Memory.m_nGrowSize = 0;
      v10->m_UncompressedData.m_Size = 0;
      v10->m_UncompressedData.m_pElements = nullptr;
      v11 = v10;
      pTestFile = v10;
    }
    else
    {
      v11 = nullptr;
      pTestFile = nullptr;
    }
    v12 = strlen(pFilename);
    v13 = v12 + 1;
    v11->m_Filename.m_Size = 0;
    if ( v12 != -1 )
    {
      m_nAllocationCount = v11->m_Filename.m_Memory.m_nAllocationCount;
      if ( v13 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(
          this: (CUtlMemory<unsigned char,int> *)&v11->m_Filename,
          num: v13 - m_nAllocationCount);
      v11->m_Filename.m_Size += v13;
      v15 = (unsigned __int8 *)v11->m_Filename.m_Memory.m_pMemory;
      v16 = v11->m_Filename.m_Size - v13;
      v11->m_Filename.m_pElements = (char *)v15;
      if ( v16 > 0 && v13 > 0 )
        _V_memmove(dest: &v15[v13], src: v15, count: v16);
    }
    v17 = pFilename;
    v18 = v11->m_Filename.m_Memory.m_pMemory;
    do
    {
      v19 = *v17;
      *v18++ = *v17++;
    }
    while ( v19 != 0 );
    v20 = strlen(pPathID);
    v21 = v20 + 1;
    v11->m_PathID.m_Size = 0;
    if ( v20 != -1 )
    {
      v22 = v11->m_PathID.m_Memory.m_nAllocationCount;
      if ( v21 > v22 )
        CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&v11->m_PathID, num: v21 - v22);
      v11->m_PathID.m_Size += v21;
      v23 = (unsigned __int8 *)v11->m_PathID.m_Memory.m_pMemory;
      v24 = v11->m_PathID.m_Size - v21;
      v11->m_PathID.m_pElements = (char *)v23;
      if ( v24 > 0 && v21 > 0 )
        _V_memmove(dest: &v23[v21], src: v23, count: v24);
    }
    v25 = pPathID;
    v26 = v11->m_PathID.m_Memory.m_pMemory;
    do
    {
      v27 = *v25;
      *v26++ = *v25++;
    }
    while ( v27 != 0 );
    v11->m_FileID = response.m_Response;
    v11->m_nChunksToReceive = 9999;
    v11->m_Timer.m_Duration.m_Int64 = __rdtsc();
    v28 = v44;
    v29 = CUtlLinkedList<CWorkerFile *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int>>::AllocInternal(
            this: &v44->m_WorkerFiles,
            multilist: false);
    if ( v29 != -1 )
    {
      if ( v29 >= 0
        && v29 < v28->m_WorkerFiles.m_Memory.m_nAllocationCount
        && v29 <= v28->m_WorkerFiles.m_LastAlloc.index )
      {
        v30 = v28->m_WorkerFiles.m_Memory.m_pMemory;
        v31 = &v30[v29];
        if ( v31->m_Previous != v29 )
        {
          m_Previous = v31->m_Previous;
          if ( m_Previous == -1 )
          {
            v28->m_WorkerFiles.m_Head = v31->m_Next;
          }
          else
          {
            v30[m_Previous].m_Next = v31->m_Next;
            v11 = pTestFile;
          }
          m_Next = v31->m_Next;
          if ( m_Next == -1 )
          {
            v28->m_WorkerFiles.m_Tail = v31->m_Previous;
          }
          else
          {
            v28->m_WorkerFiles.m_Memory.m_pMemory[m_Next].m_Previous = v31->m_Previous;
            v11 = pTestFile;
          }
          v31->m_Next = v29;
          v31->m_Previous = v29;
          --v28->m_WorkerFiles.m_ElementCount;
        }
      }
      v34 = v28->m_WorkerFiles.m_Memory.m_pMemory;
      v35 = v29;
      v34[v35].m_Next = -1;
      m_Tail = v28->m_WorkerFiles.m_Tail;
      v34[v35].m_Previous = m_Tail;
      v28->m_WorkerFiles.m_Tail = v29;
      if ( m_Tail == -1 )
        v28->m_WorkerFiles.m_Head = v29;
      else
        v28->m_WorkerFiles.m_Memory.m_pMemory[m_Tail].m_Next = v29;
      ++v28->m_WorkerFiles.m_ElementCount;
      p_m_Element = &v28->m_WorkerFiles.m_Memory.m_pMemory[v35].m_Element;
      if ( p_m_Element != nullptr )
        *p_m_Element = v11;
    }
    m_bZeroLength = response.m_bZeroLength;
    v39 = v44;
    v11->m_bGotCompressedSize = false;
    v11->m_bZeroLength = m_bZeroLength;
    ++v39->m_nUnfinishedFiles;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036860
// Name: public: class CWorkerFile __near * CWorkerMulticastListener::ListenFor(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerMulticastListener::ListenFor(
        CWorkerMulticastListener *this,
        char *pFilename,
        char *pPathID)
{
  const char *v3; // ebx
  CWorkerMulticastListener *v4; // esi
  CWorkerFile *result; // eax
  int v6; // edi
  int v7; // eax
  const CIPAddr *v8; // eax
  int v9; // eax
  int m_Head; // eax
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // esi
  CWorkerFile *m_Element; // esi
  unsigned __int8 *v13; // edx
  int v14; // ebx
  unsigned __int8 *v15; // edx
  int v16; // edx
  int v17; // ecx
  int v18; // edi
  unsigned int v19; // ecx
  CWorkerFile *v20; // eax
  CWorkerMulticastListener *v21; // edi
  long double Seconds; // st7
  unsigned int m_Size; // [esp+8h] [ebp-4E94h]
  char data[4]; // [esp+18h] [ebp-4E84h] BYREF
  int size; // [esp+1Ch] [ebp-4E80h]
  unsigned __int16 v26; // [esp+20h] [ebp-4E7Ch]
  unsigned __int16 v27; // [esp+22h] [ebp-4E7Ah]
  int v28; // [esp+24h] [ebp-4E78h]
  char v29[17392]; // [esp+28h] [ebp-4E74h] BYREF
  unsigned __int16 chunksToAck[2]; // [esp+4418h] [ebp-A84h] BYREF
  char pStr[512]; // [esp+4C18h] [ebp-284h] BYREF
  char pDest[62]; // [esp+4E18h] [ebp-84h] BYREF
  CIPAddr v33; // [esp+4E56h] [ebp-46h] BYREF
  CIPAddr v34; // [esp+4E5Ch] [ebp-40h] BYREF
  int v35; // [esp+4E64h] [ebp-38h]
  unsigned __int8 *src; // [esp+4E6Ch] [ebp-30h]
  int v37; // [esp+4E70h] [ebp-2Ch]
  int v38; // [esp+4E74h] [ebp-28h]
  char *v39; // [esp+4E78h] [ebp-24h]
  unsigned __int64 v40; // [esp+4E7Ch] [ebp-20h] BYREF
  unsigned __int64 *v41; // [esp+4E84h] [ebp-18h]
  unsigned int count; // [esp+4E88h] [ebp-14h]
  CWorkerFile *WorkerFile; // [esp+4E8Ch] [ebp-10h]
  int nChunksToAck; // [esp+4E90h] [ebp-Ch] BYREF
  CWorkerMulticastListener *v45; // [esp+4E94h] [ebp-8h]
  unsigned int lastAckTime; // [esp+4E98h] [ebp-4h] BYREF
  ISocket *pPathIDa; // [esp+4EA8h] [ebp+Ch]

  v3 = pFilename;
  v4 = this;
  v45 = this;
  WorkerFile = CWorkerMulticastListener::FindWorkerFile(this, pFilename, pPathID);
  if ( WorkerFile == nullptr )
  {
    result = CWorkerMulticastListener::RequestFileFromServer(this: v4, pFilename, pPathID);
    WorkerFile = result;
    if ( result == nullptr )
      return nullptr;
    if ( result->m_bZeroLength )
    {
      --v4->m_nUnfinishedFiles;
      return result;
    }
  }
  if ( (unsigned int)_V_strlen(str: pFilename) <= 0x39 )
  {
    V_strncpy(pDest, pSrc: pFilename, maxLen: 58);
  }
  else
  {
    V_strncpy(pDest, pSrc: "[...]", maxLen: 58);
    v6 = _V_strlen(str: pFilename);
    v7 = _V_strlen(str: pDest);
    V_strncat(pDest, pSrc: &pFilename[v7 - 57 + v6], destBufferSize: 0x3Au, max_chars_to_copy: -1);
  }
  CWorkerMulticastListener::ShowSDKWorkerMsg(this: v4, pMsg: "\rRecv %s (0%%)  ", pDest);
  v37 = VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_TCP ? 1024 : 0x4000;
  pPathIDa = nullptr;
  if ( VMPI_GetFileSystemMode() != VMPI_FILESYSTEM_MULTICAST )
  {
    if ( VMPI_GetFileSystemMode() == VMPI_FILESYSTEM_BROADCAST )
    {
      pPathIDa = CreateIPSocket();
      if ( !pPathIDa->BindToAny(this: pPathIDa, a2: v4->m_MulticastAddr.port) )
      {
        pPathIDa->Release(this: pPathIDa);
        pPathIDa = nullptr;
      }
    }
  }
  else
  {
    v8 = CIPAddr::CIPAddr(this: &v33);
    pPathIDa = CreateMulticastListenSocket(addr: &v4->m_MulticastAddr, localInterface: v8);
    if ( pPathIDa == nullptr )
    {
      IP_GetLastErrorString(pStr, maxLen: 512);
      _Warning(
        a1: "CreateMulticastListenSocket (%d.%d.%d.%d:%d) failed\n%s\n",
        v4->m_MulticastAddr.ip[0],
        v4->m_MulticastAddr.ip[1],
        v4->m_MulticastAddr.ip[2],
        v4->m_MulticastAddr.ip[3],
        v4->m_MulticastAddr.port,
        pStr);
      return nullptr;
    }
  }
  nChunksToAck = 0;
  lastAckTime = GetTickCount();
  if ( v4->m_nUnfinishedFiles <= 0 )
  {
LABEL_54:
    CWorkerMulticastListener::FlushAckChunks(
      this: v4,
      (unsigned __int16 (*)[2])chunksToAck,
      &nChunksToAck,
      &lastAckTime);
    if ( pPathIDa != nullptr )
      pPathIDa->Release(this: pPathIDa);
    return WorkerFile;
  }
  while ( 1 )
  {
    if ( pPathIDa != nullptr )
    {
      CIPAddr::CIPAddr(this: &v34);
      v9 = pPathIDa->RecvFrom(this: pPathIDa, a2: data, a3: 17408, a4: &v34);
    }
    else
    {
      v9 = CWorkerMulticastListener::CheckFileChunkPackets(this: v4, data, dataSize: 17408);
    }
    if ( v9 != -1 )
      break;
    Sleep(dwMilliseconds: 0);
    VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xA);
LABEL_53:
    if ( v4->m_nUnfinishedFiles <= 0 )
      goto LABEL_54;
  }
  g_nMulticastBytesReceived += v9;
  src = (unsigned __int8 *)&v29[strlen(v3) + 1];
  v39 = &data[v9 - (_DWORD)src];
  if ( (int)v39 < 0 )
  {
    _Warning(a1: "CWorkerMulticastListener::ListenFor: invalid packet received on multicast group\n");
    goto LABEL_53;
  }
  if ( v26 != WorkerFile->m_FileID )
    goto LABEL_53;
  m_Head = v4->m_WorkerFiles.m_Head;
  if ( m_Head == -1 )
  {
LABEL_28:
    m_Element = nullptr;
    goto LABEL_30;
  }
  m_pMemory = v4->m_WorkerFiles.m_Memory.m_pMemory;
  while ( m_pMemory[m_Head].m_Element->m_FileID != v26 )
  {
    m_Head = m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      goto LABEL_28;
  }
  m_Element = m_pMemory[m_Head].m_Element;
  if ( m_Element == nullptr )
LABEL_30:
    _Error(a1: "FindWorkerFile( %s ) failed\n", v29);
  if ( !m_Element->m_bGotCompressedSize )
  {
    m_Element->m_bGotCompressedSize = true;
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_CompressedData,
      size: *(int *)data);
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_UncompressedData,
      size);
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
      this: &m_Element->m_ChunksReceived,
      size: 8 * ((v27 + 7) / 8) / 8);
    v13 = m_Element->m_ChunksReceived.m_Memory.m_pMemory;
    m_Size = m_Element->m_ChunksReceived.m_Size;
    m_Element->m_nChunksToReceive = v27;
    memset(dst: v13, value: 0, count: m_Size);
  }
  v14 = v28;
  if ( v28 < 0 || v28 >= v27 )
    _Error(a1: "ListenFor(): invalid chunk index (%d) for file '%s'\n", v28, v29);
  v15 = m_Element->m_ChunksReceived.m_Memory.m_pMemory;
  count = v14;
  v38 = v14 >> 3;
  v35 = v14 & 7;
  if ( ((unsigned __int8)(1 << (v14 & 7)) & v15[v14 >> 3]) != 0 )
    goto LABEL_49;
  v16 = *(_DWORD *)data;
  if ( size != m_Element->m_UncompressedData.m_Size || *(_DWORD *)data != m_Element->m_CompressedData.m_Size )
  {
    _Error(
      a1: "ListenFor(): invalid compressed or uncompressed size.\n"
      "pInfo = '%s', pTestFile = '%s'\n"
      "Compressed   (pInfo = %d, pTestFile = %d)\n"
      "Uncompressed (pInfo = %d, pTestFile = %d)\n",
      v29,
      m_Element->m_Filename.m_Memory.m_pMemory,
      *(_DWORD *)data,
      m_Element->m_CompressedData.m_Size,
      size,
      m_Element->m_UncompressedData.m_Size);
    v16 = *(_DWORD *)data;
  }
  v17 = m_Element->m_CompressedData.m_Size;
  v18 = v37 * v14;
  if ( v37 * v14 + v37 < v17 )
    v17 = v37 * v14 + v37;
  v19 = v17 - v18;
  count = v19;
  if ( (char *)v19 != v39 )
    _Error(
      a1: "ListenFor(): invalid payload length for '%s' (%d should be %d)\n"
      "pInfo = '%s', pTestFile = '%s'\n"
      "Chunk %d out of %d. Compressed size: %d\n",
      m_Element->m_Filename.m_Memory.m_pMemory,
      v39,
      v19,
      v29,
      m_Element->m_Filename.m_Memory.m_pMemory,
      v14,
      v27,
      v16);
  memcpy(dst: (unsigned __int8 *)&m_Element->m_CompressedData.m_Memory.m_pMemory[v18], src, count);
  m_Element->m_ChunksReceived.m_Memory.m_pMemory[v38] |= 1 << v35;
  v20 = WorkerFile;
  --m_Element->m_nChunksToReceive;
  v21 = v45;
  if ( m_Element == v20 )
    CWorkerMulticastListener::ShowSDKWorkerMsg(
      this: v45,
      pMsg: "\rRecv %s (%d%%) [chunk %d/%d] ",
      pDest,
      100 - 100 * v20->m_nChunksToReceive / v27,
      v27 - v20->m_nChunksToReceive,
      v27);
  CWorkerMulticastListener::AddAckChunk(
    this: v21,
    (unsigned __int16 (*)[2])chunksToAck,
    &nChunksToAck,
    &lastAckTime,
    fileID: v26,
    iChunk: v14);
  if ( m_Element->m_nChunksToReceive != 0 )
  {
LABEL_49:
    if ( nChunksToAck != 0 && GetTickCount() - lastAckTime > 0x1F4 )
      CWorkerMulticastListener::FlushAckChunks(
        this: v45,
        (unsigned __int16 (*)[2])chunksToAck,
        &nChunksToAck,
        &lastAckTime);
    v4 = v45;
    v3 = pFilename;
    goto LABEL_53;
  }
  CWorkerMulticastListener::FlushAckChunks(this: v21, (unsigned __int16 (*)[2])chunksToAck, &nChunksToAck, &lastAckTime);
  v41 = &v40;
  v40 = __rdtsc();
  m_Element->m_Timer.m_Duration.m_Int64 = v40 - m_Element->m_Timer.m_Duration.m_Int64;
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
    this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&m_Element->m_UncompressedData,
    size);
  --v21->m_nUnfinishedFiles;
  if ( ZLibDecompress(
         inputLen: m_Element->m_CompressedData.m_Size,
         pOut: (unsigned __int8 *)m_Element->m_UncompressedData.m_Memory.m_pMemory,
         pInput: (unsigned __int8 *)m_Element->m_CompressedData.m_Memory.m_pMemory,
         outLen: m_Element->m_UncompressedData.m_Size) )
  {
    Seconds = CCycleCount::GetSeconds(this: &m_Element->m_Timer.m_Duration);
    V_snprintf(
      pDest: pStr,
      maxLen: 0x200u,
      pFormat: "Got %s (%dk) in %.2fs",
      pDest,
      (m_Element->m_UncompressedData.m_Size + 511) / 1024,
      (double)Seconds);
    _Msg(a1: "\r%-79s\n", pStr);
    CUtlVector<char,CUtlMemory<char,int>>::Purge(this: &m_Element->m_CompressedData);
    goto LABEL_49;
  }
  if ( pPathIDa != nullptr )
    pPathIDa->Release(this: pPathIDa);
  CWorkerMulticastListener::FlushAckChunks(this: v45, (unsigned __int16 (*)[2])chunksToAck, &nChunksToAck, &lastAckTime);
  _Error(a1: "ZLibDecompress failed.\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10036E50
// Name: public: CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CWorkerVMPIFileSystem *__thiscall CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(CWorkerVMPIFileSystem *this)
{
  UtlLinkedListElem_t<CWorkerFile *,int> *m_pMemory; // eax

  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&IBaseFileSystem::`vftable';
  this->m_pBaseFileSystemPassThru = nullptr;
  this->m_pFileSystemPassThru = nullptr;
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CWorkerVMPIFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CBaseVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
  CIPAddr::CIPAddr(this: &this->m_MulticastIP);
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CWorkerVMPIFileSystem_vtbl *)&CWorkerVMPIFileSystem::`vftable'{for `IAppSystem'};
  this->CBaseVMPIFileSystem::CFileSystemPassThru::CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&CWorkerVMPIFileSystem::`vftable'{for `IBaseFileSystem'};
  CIPAddr::CIPAddr(this: &this->m_Listener.m_MulticastAddr);
  this->m_Listener.m_WorkerFiles.m_Memory.m_pMemory = nullptr;
  this->m_Listener.m_WorkerFiles.m_Memory.m_nAllocationCount = 0;
  this->m_Listener.m_WorkerFiles.m_Memory.m_nGrowSize = 0;
  this->m_Listener.m_WorkerFiles.m_LastAlloc.index = -1;
  this->m_Listener.m_WorkerFiles.m_Head = -1;
  this->m_Listener.m_WorkerFiles.m_Tail = -1;
  this->m_Listener.m_WorkerFiles.m_FirstFree = -1;
  m_pMemory = this->m_Listener.m_WorkerFiles.m_Memory.m_pMemory;
  this->m_Listener.m_WorkerFiles.m_ElementCount = 0;
  this->m_Listener.m_WorkerFiles.m_NumAlloced = 0;
  this->m_Listener.m_WorkerFiles.m_pElements = m_pMemory;
  this->m_Listener.m_nUnfinishedFiles = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10036EC0
// Name: public: virtual void __near * CWorkerVMPIFileSystem::Open(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWorkerFile *__thiscall CWorkerVMPIFileSystem::Open(
        CWorkerVMPIFileSystem *this,
        char *pFilename,
        char *pOptions,
        char *pathID)
{
  CWorkerFile *result; // eax
  CWorkerFile *WorkerFile; // eax
  CWorkerFile *v7; // esi
  CVMPIFile_Memory *v8; // eax
  CVMPIFile_Memory *v9; // edi
  int m_Size; // ebx
  const char *m_pMemory; // esi
  int v12; // eax

  if ( pathID == nullptr )
    pathID = (char *)defaultValue;
  if ( g_bDisableFileAccess )
    _Error(a1: "Open( %s, %s ) - file access has been disabled.", pFilename, pOptions);
  if ( V_stristr(a1: pOptions, a2: pFilename, pStr: pOptions, pSearch: "w") != nullptr )
    return nullptr;
  WorkerFile = CWorkerMulticastListener::FindWorkerFile(
                 this: (CWorkerMulticastListener *)&this->m_MulticastIP.port,
                 pFilename,
                 pPathID: pathID);
  v7 = WorkerFile;
  if ( WorkerFile != nullptr && WorkerFile->m_nChunksToReceive == 0
    || (result = CWorkerMulticastListener::ListenFor(
                   this: (CWorkerMulticastListener *)&this->m_MulticastIP.port,
                   pFilename,
                   pPathID: pathID),
        v7 = result,
        result != nullptr) )
  {
    v8 = (CVMPIFile_Memory *)operator new(size: 0x14u);
    if ( v8 != nullptr )
    {
      v8->__vftable = (CVMPIFile_Memory_vtbl *)&CVMPIFile_Memory::`vftable';
      v9 = v8;
    }
    else
    {
      v9 = nullptr;
    }
    m_Size = v7->m_UncompressedData.m_Size;
    m_pMemory = v7->m_UncompressedData.m_Memory.m_pMemory;
    strchr(string: (unsigned __int8 *)pOptions, chr: 0x74u);
    CVMPIFile_Memory::Init(this: v9, pData: m_pMemory, len: m_Size, chMode: v12 != 0 ? 116 : 98);
    return (CWorkerFile *)v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10036F90
// Name: public: virtual bool CWorkerVMPIFileSystem::HandleFileSystemPacket(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkerVMPIFileSystem::HandleFileSystemPacket(
        CWorkerVMPIFileSystem *this,
        CVMPIFile_Memory *pBuf,
        int iSource,
        int iPacketID)
{
  CVMPIFile_Memory *v4; // ebx
  unsigned int v6; // esi
  void *v7; // edi
  CVMPIFile_Memory_vtbl *v8; // ebx
  int v9; // edx
  char v10; // al
  unsigned __int8 *v11; // [esp-14h] [ebp-2Ch]
  CFileResponse res; // [esp+4h] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-8h] BYREF

  v4 = pBuf;
  switch ( BYTE1(pBuf->Close) )
  {
    case 2:
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
      CCriticalSectionLock::Lock(this: &csLock);
      v8 = v4->__vftable;
      v9 = *(int *)((char *)&v8->Seek + 2);
      v10 = BYTE2(v8->Tell);
      res.m_RequestID = *(int *)((char *)&v8->Close + 2);
      res.m_Response = v9;
      res.m_bZeroLength = v10;
      CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int>>::InsertBefore(
        this: &g_FileResponses,
        elem: g_FileResponses.m_Size,
        src: &res);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    case 5:
      g_MulticastIP = *(CIPAddr *)((char *)&pBuf->Close + 2);
      g_bReceivedMulticastIP = true;
      return 1;
    case 6:
      v6 = ConCommandBase::GetName(this: pBuf) - 2;
      v7 = malloc(size: v6 + 7);
      v11 = (unsigned __int8 *)&v4->Close + 2;
      pBuf = (CVMPIFile_Memory *)v7;
      memcpy(dst: (unsigned __int8 *)v7 + 4, src: v11, count: v6);
      *(_DWORD *)v7 = v6;
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &g_FileResponsesCS);
      CCriticalSectionLock::Lock(this: &csLock);
      CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int>>::AddToTail(
        this: &g_FileChunkPackets,
        src: (CFileChunkPacket **)&pBuf);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100370A0
// Name: class CBaseVMPIFileSystem __near * CreateWorkerVMPIFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CWorkerVMPIFileSystem *__cdecl CreateWorkerVMPIFileSystem()
{
  CWorkerVMPIFileSystem *v0; // eax
  CWorkerVMPIFileSystem *v1; // esi

  v0 = (CWorkerVMPIFileSystem *)operator new(size: 0x50u);
  if ( v0 != nullptr )
    v1 = CWorkerVMPIFileSystem::CWorkerVMPIFileSystem(this: v0);
  else
    v1 = nullptr;
  g_pBaseVMPIFileSystem = v1;
  if ( v1->Init(this: v1) != INIT_FAILED )
    return v1;
  ((void (__thiscall *)(CWorkerVMPIFileSystem *, int))v1->dtr_CBaseVMPIFileSystem)(a1: v1, a2: 1);
  g_pBaseVMPIFileSystem = nullptr;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10037150
// Name: _deflateInit_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateInit_(int a1, int a2, int a3, int a4)
{
  return deflateInit2_(a1, a2, a3: 8, a4: 15, a5: 8, a6: 0, a7: a3, a8: a4);
}

//------------------------------------------------------------------------------
// Address: 0x10037180
// Name: _deflateInit2_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateInit2_(_DWORD *a1, int a2, int a3, int a4, int a5, unsigned int a6, _BYTE *a7, int a8)
{
  int v8; // ebp
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // ebx
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  unsigned int v21; // ecx

  v8 = 0;
  if ( a7 == nullptr || *a7 != *off_1008879C || a8 != 56 )
    return -6;
  if ( a1 == nullptr )
    return -2;
  v10 = a1[8];
  a1[6] = 0;
  if ( v10 == 0 )
  {
    a1[8] = zcalloc;
    a1[10] = 0;
  }
  if ( a1[9] == 0 )
    a1[9] = zcfree;
  v11 = a2;
  if ( a2 == -1 )
  {
    a2 = 6;
    v11 = 6;
  }
  v12 = a4;
  if ( a4 < 0 )
  {
    v8 = 1;
    v12 = -a4;
  }
  if ( a5 < 1 || a5 > 9 || a3 != 8 || v12 < 8 || v12 > 15 || v11 > 9 || a6 > 2 )
    return -2;
  v13 = (_DWORD *)((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1, a3: 5816);
  v14 = v13;
  if ( v13 == nullptr )
    return -4;
  a1[7] = v13;
  v13[6] = v8;
  v13[10] = v12;
  *v13 = a1;
  v13[18] = a5 + 7;
  v13[9] = 1 << v12;
  v13[11] = (1 << v12) - 1;
  v15 = 1 << (a5 + 7);
  v14[17] = v15;
  v14[19] = v15 - 1;
  v14[20] = (a5 + 9) / 3u;
  v16 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1 << v12, a3: 2);
  v17 = v14[9];
  v14[12] = v16;
  v18 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: v17, a3: 2);
  v19 = v14[17];
  v14[14] = v18;
  v14[15] = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: v19, a3: 2);
  v14[1445] = 1 << (a5 + 6);
  v20 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1 << (a5 + 6), a3: 4);
  v21 = v14[1445];
  v14[2] = v20;
  v14[3] = 4 * v21;
  if ( v14[12] != 0 && v14[14] != 0 && v14[15] != 0 && v20 != 0 )
  {
    *((_BYTE *)v14 + 29) = 8;
    v14[1447] = v20 + 2 * (v21 >> 1);
    v14[1444] = v20 + 2 * v21 + v21;
    v14[32] = a6;
    v14[31] = a2;
    return deflateReset(a1);
  }
  else
  {
    a1[6] = off_10088830[0];
    deflateEnd(a1);
    return -4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037380
// Name: _deflateReset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateReset(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // edx

  if ( a1 == nullptr )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( v1 == nullptr || a1[8] == 0 || a1[9] == 0 )
    return -2;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  a1[11] = 2;
  v2 = v1[2];
  v1[5] = 0;
  v1[4] = v2;
  if ( (int)v1[6] < 0 )
    v1[6] = 0;
  v1[1] = v1[6] != 0 ? 113 : 42;
  a1[12] = 1;
  v1[8] = 0;
  _tr_init(a1: v1);
  sub_10037810(a1: v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10037400
// Name: _deflate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflate(int a1, int a2)
{
  int v3; // esi
  int v4; // eax
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // [esp+14h] [ebp+4h]

  if ( a1 == 0 )
    return -2;
  v3 = *(_DWORD *)(a1 + 28);
  if ( v3 == 0 || (unsigned int)a2 > 4 )
    return -2;
  if ( *(_DWORD *)(a1 + 12) == 0
    || *(_DWORD *)a1 == 0 && *(_DWORD *)(a1 + 4) != 0
    || (v4 = *(_DWORD *)(v3 + 4)) == 666 && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_10088828[0];
    return -2;
  }
  if ( *(_DWORD *)(a1 + 16) == 0 )
  {
    *(char **)(a1 + 24) = off_10088834[0];
    return -5;
  }
  v6 = *(_DWORD *)(v3 + 32);
  *(_DWORD *)v3 = a1;
  v13 = v6;
  *(_DWORD *)(v3 + 32) = a2;
  if ( v4 == 42 )
  {
    v7 = (*(_DWORD *)(v3 + 124) - 1) >> 1;
    if ( v7 > 3 )
      v7 = 3;
    v8 = (v7 << 6) | ((*(_DWORD *)(v3 + 40) << 12) - 30720);
    if ( *(_DWORD *)(v3 + 100) != 0 )
      v8 |= 0x20u;
    *(_DWORD *)(v3 + 4) = 113;
    sub_100376B0(a1: v3, a2: v8 - v8 % 0x1F + 31);
    if ( *(_DWORD *)(v3 + 100) != 0 )
    {
      sub_100376B0(a1: v3, a2: *(unsigned __int16 *)(a1 + 50));
      sub_100376B0(a1: v3, a2: (unsigned __int16)*(_DWORD *)(a1 + 48));
    }
    *(_DWORD *)(a1 + 48) = 1;
  }
  if ( *(_DWORD *)(v3 + 20) != 0 )
  {
    sub_100376E0(a1);
    if ( *(_DWORD *)(a1 + 16) == 0 )
    {
      *(_DWORD *)(v3 + 32) = -1;
      return 0;
    }
  }
  else if ( *(_DWORD *)(a1 + 4) == 0 && a2 <= v13 && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_10088834[0];
    return -5;
  }
  v9 = *(_DWORD *)(v3 + 4);
  v10 = *(_DWORD *)(a1 + 4);
  if ( v9 == 666 )
  {
    if ( v10 != 0 )
    {
      *(char **)(a1 + 24) = off_10088834[0];
      return -5;
    }
  }
  else if ( v10 != 0 )
  {
    goto LABEL_33;
  }
  if ( *(_DWORD *)(v3 + 108) == 0 && (a2 == 0 || v9 == 666) )
  {
LABEL_45:
    if ( a2 != 4 )
      return 0;
    if ( *(_DWORD *)(v3 + 24) != 0 )
      return 1;
    sub_100376B0(a1: v3, a2: *(unsigned __int16 *)(a1 + 50));
    sub_100376B0(a1: v3, a2: (unsigned __int16)*(_DWORD *)(a1 + 48));
    sub_100376E0(a1);
    v12 = *(_DWORD *)(v3 + 20);
    *(_DWORD *)(v3 + 24) = -1;
    return v12 == 0;
  }
LABEL_33:
  v11 = funcs_10037594[3 * *(_DWORD *)(v3 + 124)](a1: v3, a2);
  if ( v11 == 2 || v11 == 3 )
    *(_DWORD *)(v3 + 4) = 666;
  if ( v11 != 0 && v11 != 2 )
  {
    if ( v11 == 1 )
    {
      if ( a2 == 1 )
      {
        _tr_align(a1: v3);
      }
      else
      {
        _tr_stored_block(a1: v3, a2: 0, a3: 0, a4: 0);
        if ( a2 == 3 )
        {
          *(_WORD *)(*(_DWORD *)(v3 + 60) + 2 * *(_DWORD *)(v3 + 68) - 2) = 0;
          memset(*(void **)(v3 + 60), 0, 2 * *(_DWORD *)(v3 + 68) - 2);
        }
      }
      sub_100376E0(a1);
      if ( *(_DWORD *)(a1 + 16) == 0 )
      {
        *(_DWORD *)(v3 + 32) = -1;
        return 0;
      }
    }
    goto LABEL_45;
  }
  if ( *(_DWORD *)(a1 + 16) == 0 )
    *(_DWORD *)(v3 + 32) = -1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100376B0
// Name: sub_100376B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_100376B0(int a1, __int16 a2)
{
  int v3; // esi
  int v4; // edx

  *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = HIBYTE(a2);
  v3 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(a1 + 20) + 1;
  *(_DWORD *)(a1 + 20) = v4;
  *(_BYTE *)(v4 + v3) = a2;
  ++*(_DWORD *)(a1 + 20);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100376E0
// Name: sub_100376E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_100376E0(int a1)
{
  _DWORD *result; // eax
  int v2; // esi
  unsigned int v3; // edx
  int v4; // ecx
  int v5; // ecx
  unsigned int v6; // edi

  result = (_DWORD *)a1;
  v2 = *(_DWORD *)(a1 + 28);
  v3 = *(_DWORD *)(v2 + 20);
  if ( v3 > *(_DWORD *)(a1 + 16) )
    v3 = *(_DWORD *)(a1 + 16);
  if ( v3 != 0 )
  {
    qmemcpy(*(void **)(a1 + 12), *(const void **)(v2 + 16), v3);
    v4 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 12) += v3;
    *(_DWORD *)(v4 + 16) += v3;
    v5 = *(_DWORD *)(a1 + 28);
    v6 = *(_DWORD *)(a1 + 16) - v3;
    *(_DWORD *)(a1 + 20) += v3;
    *(_DWORD *)(a1 + 16) = v6;
    *(_DWORD *)(v5 + 20) -= v3;
    result = *(_DWORD **)(a1 + 28);
    if ( result[5] == 0 )
      result[4] = result[2];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037760
// Name: _deflateEnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl deflateEnd(int a1)
{
  int v1; // eax
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // edx

  if ( a1 == 0 )
    return -2;
  v1 = *(_DWORD *)(a1 + 28);
  if ( v1 == 0 )
    return -2;
  v2 = *(_DWORD *)(v1 + 4);
  if ( v2 != 42 && v2 != 113 && v2 != 666 )
    return -2;
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 != 0 )
    (*(void (__cdecl **)(_DWORD, int))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v3);
  v4 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v4 + 60) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v4 + 60));
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 28) + 56) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(
      a1: *(_DWORD *)(a1 + 40),
      a2: *(_DWORD *)(*(_DWORD *)(a1 + 28) + 56));
  v5 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v5 + 48) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v5 + 48));
  (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(a1 + 28));
  *(_DWORD *)(a1 + 28) = 0;
  return v2 != 113 ? 0 : 0xFD;
}

//------------------------------------------------------------------------------
// Address: 0x10037810
// Name: sub_10037810
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10037810(int a1)
{
  int v1; // ecx
  int v2; // eax
  int v3; // ecx

  v1 = *(_DWORD *)(a1 + 68);
  *(_DWORD *)(a1 + 52) = 2 * *(_DWORD *)(a1 + 36);
  *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * v1 - 2) = 0;
  memset(*(void **)(a1 + 60), 0, 2 * *(_DWORD *)(a1 + 68) - 2);
  v2 = 6 * *(_DWORD *)(a1 + 124);
  *(_DWORD *)(a1 + 120) = (unsigned __int16)word_1006324A[v2];
  *(_DWORD *)(a1 + 132) = (unsigned __int16)word_10063248[v2];
  *(_DWORD *)(a1 + 136) = (unsigned __int16)word_1006324C[v2];
  v3 = (unsigned __int16)word_1006324E[v2];
  *(_DWORD *)(a1 + 100) = 0;
  *(_DWORD *)(a1 + 84) = 0;
  *(_DWORD *)(a1 + 108) = 0;
  *(_DWORD *)(a1 + 96) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 116) = v3;
  *(_DWORD *)(a1 + 112) = 2;
  *(_DWORD *)(a1 + 88) = 2;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x100378B0
// Name: sub_100378B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_100378B0(int *a1, int a2)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // ecx
  bool v5; // zf
  int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // eax
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // [esp-14h] [ebp-1Ch]
  int v17; // [esp-14h] [ebp-1Ch]
  int v18; // [esp-14h] [ebp-1Ch]

  v2 = 0xFFFF;
  if ( (unsigned int)(a1[3] - 5) < 0xFFFF )
    v2 = a1[3] - 5;
  while ( 1 )
  {
    v3 = a1[27];
    if ( v3 <= 1 )
    {
      sub_10037A00(a1);
      v3 = a1[27];
      if ( v3 == 0 )
        break;
    }
    v4 = a1[25];
    a1[27] = 0;
    v5 = v3 + v4 == 0;
    a1[25] = v3 + v4;
    v6 = a1[21];
    v7 = a1[25];
    v8 = v6 + v2;
    if ( !v5 && v7 < v8
      || ((a1[25] = v8, a1[27] = v7 - v8, v6 < 0) ? (v9 = 0) : (v9 = v6 + a1[12]),
          _tr_flush_block(a1, a2: v9, a3: v2, a4: 0),
          v16 = *a1,
          a1[21] = a1[25],
          sub_100376E0(a1: v16),
          *(_DWORD *)(*a1 + 16) != 0) )
    {
      v10 = a1[21];
      v11 = a1[25] - v10;
      if ( v11 < a1[9] - 262 )
        continue;
      v12 = v10 < 0 ? 0 : v10 + a1[12];
      _tr_flush_block(a1, a2: v12, a3: v11, a4: 0);
      v17 = *a1;
      a1[21] = a1[25];
      sub_100376E0(a1: v17);
      if ( *(_DWORD *)(*a1 + 16) != 0 )
        continue;
    }
    return 0;
  }
  if ( a2 == 0 )
    return 0;
  v14 = a1[21];
  if ( v14 < 0 )
    v15 = 0;
  else
    v15 = v14 + a1[12];
  _tr_flush_block(a1, a2: v15, a3: a1[25] - v14, a4: a2 == 4);
  v18 = *a1;
  a1[21] = a1[25];
  sub_100376E0(a1: v18);
  if ( *(_DWORD *)(*a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x10037A00
// Name: sub_10037A00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10037A00(int a1)
{
  unsigned int v1; // ebp
  unsigned int v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // esi
  int v8; // ecx
  _WORD *v9; // ecx
  __int16 v10; // ax
  unsigned int v11; // esi
  _WORD *v12; // ecx
  __int16 v13; // ax
  int result; // eax
  unsigned int v15; // esi
  int v16; // ecx
  unsigned __int8 *v17; // edi
  int v18; // eax

  v1 = *(_DWORD *)(a1 + 36);
  do
  {
    v2 = *(_DWORD *)(a1 + 100);
    v3 = *(_DWORD *)(a1 + 108);
    v4 = *(_DWORD *)(a1 + 52) - v2 - v3;
    if ( v4 != 0 )
    {
      if ( v4 == -1 )
      {
        v4 = -2;
        goto LABEL_20;
      }
    }
    else if ( v2 == 0 && v3 == 0 )
    {
      v4 = v1;
      goto LABEL_20;
    }
    if ( v2 >= *(_DWORD *)(a1 + 36) + v1 - 262 )
    {
      qmemcpy(*(void **)(a1 + 48), (const void *)(*(_DWORD *)(a1 + 48) + v1), v1);
      v5 = *(_DWORD *)(a1 + 84);
      v6 = *(_DWORD *)(a1 + 100) - v1;
      *(_DWORD *)(a1 + 104) -= v1;
      v7 = *(_DWORD *)(a1 + 68);
      *(_DWORD *)(a1 + 100) = v6;
      v8 = *(_DWORD *)(a1 + 60);
      *(_DWORD *)(a1 + 84) = v5 - v1;
      v9 = (_WORD *)(v8 + 2 * v7);
      do
      {
        if ( (unsigned __int16)*--v9 < v1 )
          v10 = 0;
        else
          v10 = *v9 - v1;
        --v7;
        *v9 = v10;
      }
      while ( v7 != 0 );
      v11 = v1;
      v12 = (_WORD *)(*(_DWORD *)(a1 + 56) + 2 * v1);
      do
      {
        if ( (unsigned __int16)*--v12 < v1 )
          v13 = 0;
        else
          v13 = *v12 - v1;
        --v11;
        *v12 = v13;
      }
      while ( v11 != 0 );
      v4 += v1;
    }
LABEL_20:
    result = *(_DWORD *)a1;
    if ( *(_DWORD *)(*(_DWORD *)a1 + 4) == 0 )
      break;
    result = sub_10037B30(a1: result, a2: *(_DWORD *)(a1 + 48) + *(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 108), a3: v4);
    v15 = result + *(_DWORD *)(a1 + 108);
    *(_DWORD *)(a1 + 108) = v15;
    if ( v15 >= 3 )
    {
      v16 = *(_DWORD *)(a1 + 80);
      v17 = (unsigned __int8 *)(*(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 48));
      v18 = *v17;
      *(_DWORD *)(a1 + 64) = v18;
      result = *(_DWORD *)(a1 + 76) & (v17[1] ^ (v18 << v16));
      *(_DWORD *)(a1 + 64) = result;
    }
    if ( v15 >= 0x106 )
      break;
    result = *(_DWORD *)(*(_DWORD *)a1 + 4);
  }
  while ( result != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037B30
// Name: sub_10037B30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_10037B30(_DWORD *a1, void *a2, unsigned int a3)
{
  unsigned int v3; // ebx
  int v5; // eax

  v3 = a1[1];
  if ( v3 > a3 )
    v3 = a3;
  if ( v3 == 0 )
    return 0;
  a1[1] -= v3;
  if ( *(_DWORD *)(a1[7] + 24) == 0 )
    a1[12] = adler32(a1: a1[12], a2: *a1, a3: v3);
  qmemcpy(a2, (const void *)*a1, v3);
  v5 = a1[2];
  *a1 += v3;
  a1[2] = v3 + v5;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10037BB0
// Name: sub_10037BB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10037BB0(int a1, int a2)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  char v7; // cl
  __int16 v8; // ax
  unsigned __int16 v9; // ax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // edx
  BOOL v14; // ebp
  unsigned int v15; // ecx
  int v16; // eax
  int v17; // edi
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  unsigned int v22; // ecx
  unsigned __int8 *v23; // edx
  int v24; // ecx
  int v25; // eax
  unsigned __int8 v26; // al
  int v27; // ecx
  int v28; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // [esp-14h] [ebp-2Ch]
  int v33; // [esp-14h] [ebp-2Ch]

  v2 = 0;
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 108);
    if ( v3 < 0x106 )
    {
      sub_10037A00(a1);
      v3 = *(_DWORD *)(a1 + 108);
      if ( v3 < 0x106 && a2 == 0 )
        return 0;
      if ( v3 == 0 )
        break;
    }
    if ( v3 >= 3 )
    {
      v4 = *(_DWORD *)(a1 + 100);
      v5 = *(_DWORD *)(a1 + 60);
      v6 = *(_DWORD *)(a1 + 76)
         & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 48) + v4 + 2)
          ^ (*(_DWORD *)(a1 + 64) << *(_DWORD *)(a1 + 80)));
      HIWORD(v2) = 0;
      *(_DWORD *)(a1 + 64) = v6;
      LOWORD(v2) = *(_WORD *)(v5 + 2 * v6);
      *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * (v4 & *(_DWORD *)(a1 + 44))) = v2;
      *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * *(_DWORD *)(a1 + 64)) = *(_WORD *)(a1 + 100);
    }
    if ( v2 != 0
      && *(_DWORD *)(a1 + 100) - v2 <= (unsigned int)(*(_DWORD *)(a1 + 36) - 262)
      && *(_DWORD *)(a1 + 128) != 2 )
    {
      *(_DWORD *)(a1 + 88) = sub_10037EF0(a1, a2: v2);
    }
    if ( *(_DWORD *)(a1 + 88) < 3u )
    {
      v26 = *(_BYTE *)(*(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 48));
      *(_WORD *)(*(_DWORD *)(a1 + 5788) + 2 * *(_DWORD *)(a1 + 5784)) = 0;
      *(_BYTE *)(*(_DWORD *)(a1 + 5776) + (*(_DWORD *)(a1 + 5784))++) = v26;
      ++*(_WORD *)(a1 + 4 * v26 + 140);
      v14 = *(_DWORD *)(a1 + 5784) == *(_DWORD *)(a1 + 5780) - 1;
      --*(_DWORD *)(a1 + 108);
    }
    else
    {
      v7 = *(_DWORD *)(a1 + 88);
      v8 = *(_WORD *)(a1 + 100) - *(_WORD *)(a1 + 104);
      *(_WORD *)(*(_DWORD *)(a1 + 5788) + 2 * *(_DWORD *)(a1 + 5784)) = v8;
      v9 = v8 - 1;
      *(_BYTE *)(*(_DWORD *)(a1 + 5776) + (*(_DWORD *)(a1 + 5784))++) = v7 - 3;
      v10 = (unsigned __int8)_length_code[(unsigned __int8)(v7 - 3)];
      ++*(_WORD *)(a1 + 4 * v10 + 1168);
      if ( v9 >= 0x100u )
        v11 = (unsigned __int8)byte_10063A10[v9 >> 7];
      else
        v11 = (unsigned __int8)_dist_code[v9];
      ++*(_WORD *)(a1 + 4 * v11 + 2432);
      v12 = *(_DWORD *)(a1 + 88);
      v13 = *(_DWORD *)(a1 + 120);
      v14 = *(_DWORD *)(a1 + 5784) == *(_DWORD *)(a1 + 5780) - 1;
      v15 = *(_DWORD *)(a1 + 108) - v12;
      *(_DWORD *)(a1 + 108) = v15;
      if ( v12 > v13 || v15 < 3 )
      {
        v22 = v12 + *(_DWORD *)(a1 + 100);
        v23 = (unsigned __int8 *)(v22 + *(_DWORD *)(a1 + 48));
        *(_DWORD *)(a1 + 100) = v22;
        v24 = *(_DWORD *)(a1 + 80);
        *(_DWORD *)(a1 + 88) = 0;
        v25 = *v23;
        *(_DWORD *)(a1 + 64) = v25;
        *(_DWORD *)(a1 + 64) = *(_DWORD *)(a1 + 76) & (v23[1] ^ (v25 << v24));
        goto LABEL_24;
      }
      *(_DWORD *)(a1 + 88) = v12 - 1;
      do
      {
        v16 = *(_DWORD *)(a1 + 48);
        v17 = *(_DWORD *)(a1 + 64);
        v18 = *(_DWORD *)(a1 + 100) + 1;
        *(_DWORD *)(a1 + 100) = v18;
        v19 = *(_DWORD *)(a1 + 60);
        v20 = *(_DWORD *)(a1 + 76) & ((v17 << *(_DWORD *)(a1 + 80)) ^ *(unsigned __int8 *)(v18 + v16 + 2));
        HIWORD(v2) = 0;
        *(_DWORD *)(a1 + 64) = v20;
        LOWORD(v2) = *(_WORD *)(v19 + 2 * v20);
        *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * (*(_DWORD *)(a1 + 44) & v18)) = v2;
        *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * *(_DWORD *)(a1 + 64)) = *(_WORD *)(a1 + 100);
        v21 = *(_DWORD *)(a1 + 88) - 1;
        *(_DWORD *)(a1 + 88) = v21;
      }
      while ( v21 != 0 );
    }
    ++*(_DWORD *)(a1 + 100);
LABEL_24:
    if ( v14 )
    {
      v27 = *(_DWORD *)(a1 + 84);
      v28 = v27 < 0 ? 0 : v27 + *(_DWORD *)(a1 + 48);
      _tr_flush_block(a1, a2: v28, a3: *(_DWORD *)(a1 + 100) - v27, a4: 0);
      v32 = *(_DWORD *)a1;
      *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 100);
      sub_100376E0(a1: v32);
      if ( *(_DWORD *)(*(_DWORD *)a1 + 16) == 0 )
        return 0;
    }
  }
  v30 = *(_DWORD *)(a1 + 84);
  if ( v30 < 0 )
    v31 = 0;
  else
    v31 = v30 + *(_DWORD *)(a1 + 48);
  _tr_flush_block(a1, a2: v31, a3: *(_DWORD *)(a1 + 100) - v30, a4: a2 == 4);
  v33 = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 100);
  sub_100376E0(a1: v33);
  if ( *(_DWORD *)(*(_DWORD *)a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x10037EF0
// Name: sub_10037EF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_10037EF0(_DWORD *a1, int a2)
{
  int v3; // esi
  unsigned int v4; // edx
  unsigned int v5; // ebp
  unsigned int v6; // eax
  _BYTE *v7; // ecx
  _BYTE *v8; // ebx
  _BYTE *v10; // edx
  char v11; // al
  _BYTE *v12; // edx
  _BYTE *v13; // ecx
  _BYTE *v14; // edx
  char v15; // al
  _BYTE *v16; // edx
  char v17; // al
  _BYTE *v18; // edx
  char v19; // al
  _BYTE *v20; // edx
  char v21; // al
  _BYTE *v22; // edx
  char v23; // al
  _BYTE *v24; // edx
  char v25; // al
  _BYTE *v26; // edx
  char v27; // al
  _BYTE *v28; // edx
  char v29; // al
  _BYTE *v30; // edx
  int v31; // edx
  unsigned int result; // eax
  char v33; // [esp+13h] [ebp-11h]
  unsigned int v34; // [esp+14h] [ebp-10h]
  int v35; // [esp+18h] [ebp-Ch]
  unsigned int v36; // [esp+1Ch] [ebp-8h]
  unsigned int v37; // [esp+20h] [ebp-4h]
  char v38; // [esp+28h] [ebp+4h]

  v3 = a1[9];
  v4 = a1[25];
  v5 = a1[28];
  v34 = a1[29];
  v6 = a1[34];
  v7 = (_BYTE *)(v4 + a1[12]);
  v35 = v6;
  if ( v4 <= v3 - 262 )
    v36 = 0;
  else
    v36 = v4 - v3 + 262;
  v8 = v7 + 258;
  v38 = v7[v5 - 1];
  v33 = v7[v5];
  if ( v5 >= a1[33] )
    v34 >>= 2;
  v37 = a1[27];
  if ( v6 > v37 )
    v35 = a1[27];
  do
  {
    v10 = (_BYTE *)(a2 + a1[12]);
    if ( v10[v5] == v33 && v10[v5 - 1] == v38 && *v10 == *v7 )
    {
      v11 = v10[1];
      v12 = v10 + 1;
      if ( v11 == v7[1] )
      {
        v13 = v7 + 2;
        v14 = v12 + 1;
        do
        {
          v15 = *++v13;
          v16 = v14 + 1;
          if ( v15 != *v16 )
            break;
          v17 = *++v13;
          v18 = v16 + 1;
          if ( v17 != *v18 )
            break;
          v19 = *++v13;
          v20 = v18 + 1;
          if ( v19 != *v20 )
            break;
          v21 = *++v13;
          v22 = v20 + 1;
          if ( v21 != *v22 )
            break;
          v23 = *++v13;
          v24 = v22 + 1;
          if ( v23 != *v24 )
            break;
          v25 = *++v13;
          v26 = v24 + 1;
          if ( v25 != *v26 )
            break;
          v27 = *++v13;
          v28 = v26 + 1;
          if ( v27 != *v28 )
            break;
          v29 = *++v13;
          v14 = v28 + 1;
          if ( v29 != *v14 )
            break;
        }
        while ( v13 < v8 );
        v30 = v13;
        v7 = v8 - 258;
        v31 = v30 - v8 + 258;
        if ( v31 > (int)v5 )
        {
          a1[26] = a2;
          v5 = v31;
          if ( v31 >= v35 )
            break;
          v38 = v7[v31 - 1];
          v33 = v7[v31];
        }
      }
    }
    a2 = *(unsigned __int16 *)(a1[14] + 2 * (a2 & a1[11]));
    if ( (unsigned __int16)a2 <= v36 )
      break;
    --v34;
  }
  while ( v34 != 0 );
  result = v37;
  if ( v5 <= v37 )
    return v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038060
// Name: sub_10038060
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10038060(_DWORD *a1, int a2)
{
  int v3; // edi
  unsigned int v4; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ebp
  __int16 v14; // ax
  unsigned __int16 v15; // ax
  int v16; // eax
  int v17; // eax
  BOOL v18; // ebx
  unsigned int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // eax
  int v26; // eax
  unsigned __int8 v28; // al
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  int v32; // edx
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // [esp-14h] [ebp-2Ch]
  int v38; // [esp-14h] [ebp-2Ch]
  int v39; // [esp-14h] [ebp-2Ch]
  unsigned __int8 v40; // [esp+1Ch] [ebp+4h]
  unsigned __int8 v41; // [esp+20h] [ebp+8h]

  v3 = 0;
  while ( 1 )
  {
    v4 = a1[27];
    if ( v4 < 0x106 )
    {
      sub_10037A00((int)a1);
      v4 = a1[27];
      if ( v4 < 0x106 && a2 == 0 )
        return 0;
      if ( v4 == 0 )
        break;
    }
    if ( v4 >= 3 )
    {
      v6 = a1[25];
      v7 = a1[15];
      v8 = a1[19] & (*(unsigned __int8 *)(a1[12] + v6 + 2) ^ (a1[16] << a1[20]));
      HIWORD(v3) = 0;
      a1[16] = v8;
      LOWORD(v3) = *(_WORD *)(v7 + 2 * v8);
      *(_WORD *)(a1[14] + 2 * (v6 & a1[11])) = v3;
      *(_WORD *)(a1[15] + 2 * a1[16]) = *((_WORD *)a1 + 50);
    }
    v9 = a1[22];
    v10 = a1[26];
    a1[28] = v9;
    a1[23] = v10;
    a1[22] = 2;
    if ( v3 != 0 && v9 < a1[30] && a1[25] - v3 <= (unsigned int)(a1[9] - 262) )
    {
      if ( a1[32] != 2 )
        a1[22] = sub_10037EF0(a1, a2: v3);
      v11 = a1[22];
      if ( v11 <= 5 && (a1[32] == 1 || v11 == 3 && (unsigned int)(a1[25] - a1[26]) > 0x1000) )
        a1[22] = 2;
    }
    v12 = a1[28];
    if ( v12 < 3 || a1[22] > v12 )
    {
      if ( a1[24] != 0 )
      {
        v28 = *(_BYTE *)(a1[25] + a1[12] - 1);
        *(_WORD *)(a1[1447] + 2 * a1[1446]) = 0;
        *(_BYTE *)(a1[1444] + a1[1446]++) = v28;
        ++LOWORD(a1[v28 + 35]);
        if ( a1[1446] == a1[1445] - 1 )
        {
          v29 = a1[21];
          if ( v29 < 0 )
            v30 = 0;
          else
            v30 = v29 + a1[12];
          _tr_flush_block(a1, a2: v30, a3: a1[25] - v29, a4: 0);
          v38 = *a1;
          a1[21] = a1[25];
          sub_100376E0(a1: v38);
        }
        v31 = a1[27] - 1;
        ++a1[25];
        v32 = *a1;
        a1[27] = v31;
        v26 = *(_DWORD *)(v32 + 16);
        goto LABEL_32;
      }
      v33 = a1[25] + 1;
      v34 = a1[27] - 1;
      a1[24] = 1;
      a1[25] = v33;
      a1[27] = v34;
    }
    else
    {
      v13 = a1[25] + a1[27] - 3;
      v14 = a1[25] - *((_WORD *)a1 + 46) - 1;
      v40 = *((_BYTE *)a1 + 112) - 3;
      *(_WORD *)(a1[1447] + 2 * a1[1446]) = v14;
      v15 = v14 - 1;
      *(_BYTE *)(a1[1444] + a1[1446]++) = v40;
      ++LOWORD(a1[(unsigned __int8)_length_code[v40] + 292]);
      if ( v15 >= 0x100u )
        v16 = (unsigned __int8)byte_10063A10[v15 >> 7];
      else
        v16 = (unsigned __int8)_dist_code[v15];
      ++LOWORD(a1[v16 + 608]);
      v17 = a1[28];
      v18 = a1[1446] == a1[1445] - 1;
      a1[27] += 1 - v17;
      a1[28] = v17 - 2;
      do
      {
        v19 = a1[25] + 1;
        a1[25] = v19;
        if ( v19 <= v13 )
        {
          v20 = a1[15];
          v21 = a1[19] & (*(unsigned __int8 *)(a1[12] + v19 + 2) ^ (a1[16] << a1[20]));
          HIWORD(v3) = 0;
          a1[16] = v21;
          LOWORD(v3) = *(_WORD *)(v20 + 2 * v21);
          *(_WORD *)(a1[14] + 2 * (v19 & a1[11])) = v3;
          *(_WORD *)(a1[15] + 2 * a1[16]) = *((_WORD *)a1 + 50);
        }
        v22 = a1[28] - 1;
        a1[28] = v22;
      }
      while ( v22 != 0 );
      v23 = a1[25] + 1;
      a1[24] = 0;
      a1[22] = 2;
      a1[25] = v23;
      if ( v18 )
      {
        v24 = a1[21];
        if ( v24 < 0 )
          v25 = 0;
        else
          v25 = v24 + a1[12];
        _tr_flush_block(a1, a2: v25, a3: v23 - v24, a4: 0);
        v37 = *a1;
        a1[21] = a1[25];
        sub_100376E0(a1: v37);
        v26 = *(_DWORD *)(*a1 + 16);
LABEL_32:
        if ( v26 == 0 )
          return 0;
      }
    }
  }
  if ( a1[24] != 0 )
  {
    v41 = *(_BYTE *)(a1[25] + a1[12] - 1);
    *(_WORD *)(a1[1447] + 2 * a1[1446]) = 0;
    *(_BYTE *)(a1[1444] + a1[1446]++) = v41;
    ++LOWORD(a1[v41 + 35]);
    a1[24] = 0;
  }
  v35 = a1[21];
  if ( v35 < 0 )
    v36 = 0;
  else
    v36 = v35 + a1[12];
  _tr_flush_block(a1, a2: v36, a3: a1[25] - v35, a4: a2 == 4);
  v39 = *a1;
  a1[21] = a1[25];
  sub_100376E0(a1: v39);
  if ( *(_DWORD *)(*a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x10038490
// Name: _inflateReset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateReset(_DWORD *a1)
{
  _DWORD *v1; // ecx

  if ( a1 == nullptr )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( v1 == nullptr )
    return -2;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  *v1 = v1[3] != 0 ? 7 : 0;
  inflate_blocks_reset(a1: *(_DWORD *)(a1[7] + 20), a2: a1, a3: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100384E0
// Name: _inflateEnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateEnd(_DWORD *a1)
{
  int v1; // eax
  int v2; // eax

  if ( a1 == nullptr )
    return -2;
  v1 = a1[7];
  if ( v1 == 0 || a1[9] == 0 )
    return -2;
  v2 = *(_DWORD *)(v1 + 20);
  if ( v2 != 0 )
    inflate_blocks_free(a1: v2, a2: a1);
  ((void (__cdecl *)(_DWORD, _DWORD))a1[9])(a1: a1[10], a2: a1[7]);
  a1[7] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10038530
// Name: _inflateInit2_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateInit2_(_DWORD *a1, int a2, _BYTE *a3, int a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // ecx

  if ( a3 == nullptr || *a3 != a113_0[0] || a4 != 56 )
    return -6;
  if ( a1 == nullptr )
    return -2;
  v5 = a1[8];
  a1[6] = 0;
  if ( v5 == 0 )
  {
    a1[8] = zcalloc;
    a1[10] = 0;
  }
  if ( a1[9] == 0 )
    a1[9] = zcfree;
  v6 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1, a3: 24);
  a1[7] = v6;
  if ( v6 == 0 )
    return -4;
  v7 = a2;
  *(_DWORD *)(v6 + 20) = 0;
  *(_DWORD *)(a1[7] + 12) = 0;
  if ( a2 < 0 )
  {
    v7 = -a2;
    *(_DWORD *)(a1[7] + 12) = 1;
  }
  if ( v7 < 8 || v7 > 15 )
  {
    inflateEnd(a1);
    return -2;
  }
  else
  {
    *(_DWORD *)(a1[7] + 16) = v7;
    *(_DWORD *)(a1[7] + 20) = inflate_blocks_new(a1, a2: *(_DWORD *)(a1[7] + 12) == 0 ? adler32 : nullptr, a3: 1 << v7);
    if ( *(_DWORD *)(a1[7] + 20) != 0 )
    {
      inflateReset(a1);
      return 0;
    }
    else
    {
      inflateEnd(a1);
      return -4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038640
// Name: _inflateInit_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateInit_(_DWORD *a1, _BYTE *a2, int a3)
{
  return inflateInit2_(a1, a2: 15, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10038660
// Name: _inflate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate(unsigned __int8 **a1, int a2)
{
  int v2; // edi
  unsigned int v3; // ebx
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // eax
  int v7; // ecx
  unsigned __int8 *v8; // edx
  unsigned __int8 *v9; // edx
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // ebx
  int v12; // ecx
  unsigned __int8 *v13; // eax
  int v14; // eax
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // edx
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // ecx
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // ecx
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // ecx
  int v24; // edx
  unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // eax
  unsigned __int8 *v27; // edx
  unsigned __int8 *v28; // eax
  unsigned __int8 *v30; // ecx
  unsigned __int8 *v31; // ecx
  unsigned __int8 *v32; // eax
  unsigned __int8 *v33; // edx
  unsigned __int8 *v34; // edx
  unsigned __int8 *v35; // eax
  unsigned __int8 *v36; // ecx
  unsigned __int8 *v37; // eax
  unsigned __int8 *v38; // ecx
  int v39; // edx
  unsigned __int8 *v40; // eax
  unsigned __int8 *v41; // eax
  unsigned __int8 *v42; // eax
  unsigned int v43; // [esp+18h] [ebp+8h]

  if ( a1 == nullptr || a1[7] == nullptr || *a1 == nullptr )
    return -2;
  v2 = -5;
  v3 = a2 != 4 ? 0 : 0xFFFFFFFB;
  v43 = v3;
  while ( 2 )
  {
    v4 = a1[7];
    switch ( *(_DWORD *)v4 )
    {
      case 0:
        v5 = a1[1];
        if ( v5 == nullptr )
          return v2;
        a1[1] = v5 - 1;
        v2 = v3;
        ++a1[2];
        *((_DWORD *)v4 + 1) = **a1;
        v6 = a1[7];
        v7 = *((_DWORD *)v6 + 1) & 0xF;
        ++*a1;
        if ( (_BYTE)v7 != 8 )
        {
          *(_DWORD *)v6 = 13;
          v8 = a1[7];
          a1[6] = (unsigned __int8 *)aUnknownCompres;
          *((_DWORD *)v8 + 1) = 5;
          continue;
        }
        if ( (unsigned int)((*((_DWORD *)v6 + 1) >> 4) + 8) > *((_DWORD *)v6 + 4) )
        {
          *(_DWORD *)v6 = 13;
          v9 = a1[7];
          a1[6] = (unsigned __int8 *)aInvalidWindowS;
          *((_DWORD *)v9 + 1) = 5;
          continue;
        }
        *(_DWORD *)v6 = 1;
LABEL_12:
        v10 = a1[1];
        if ( v10 == nullptr )
          return v2;
        a1[1] = v10 - 1;
        v2 = v3;
        v11 = a1[7];
        ++a1[2];
        v12 = *(*a1)++;
        if ( (v12 + (*((_DWORD *)v11 + 1) << 8)) % 0x1Fu != 0 )
        {
          *(_DWORD *)v11 = 13;
          v13 = a1[7];
          v3 = v43;
          a1[6] = (unsigned __int8 *)aIncorrectHeade;
          *((_DWORD *)v13 + 1) = 5;
          continue;
        }
        if ( (v12 & 0x20) == 0 )
        {
          *(_DWORD *)v11 = 7;
          v3 = v43;
          continue;
        }
        v3 = v43;
        *(_DWORD *)a1[7] = 2;
LABEL_35:
        v28 = a1[1];
        if ( v28 == nullptr )
          return v2;
        v30 = *a1;
        ++a1[2];
        a1[1] = v28 - 1;
        v2 = v3;
        *((_DWORD *)a1[7] + 2) = *v30 << 24;
        v31 = a1[7];
        ++*a1;
        *(_DWORD *)v31 = 3;
LABEL_38:
        v32 = a1[1];
        if ( v32 == nullptr )
          return v2;
        v33 = *a1;
        a1[1] = v32 - 1;
        ++a1[2];
        v2 = v3;
        *((_DWORD *)a1[7] + 2) += *v33 << 16;
        v34 = a1[7];
        ++*a1;
        *(_DWORD *)v34 = 4;
LABEL_41:
        v35 = a1[1];
        if ( v35 == nullptr )
          return v2;
        v36 = *a1;
        a1[1] = v35 - 1;
        ++a1[2];
        v2 = v3;
        *((_DWORD *)a1[7] + 2) += *v36 << 8;
        ++*a1;
        *(_DWORD *)a1[7] = 5;
LABEL_44:
        v37 = a1[1];
        if ( v37 == nullptr )
          return v2;
        v38 = *a1;
        v39 = (int)(a1[2] + 1);
        a1[1] = v37 - 1;
        v40 = a1[7];
        a1[2] = (unsigned __int8 *)v39;
        *((_DWORD *)v40 + 2) += *v38;
        ++*a1;
        v41 = a1[7];
        a1[12] = *((unsigned __int8 **)v41 + 2);
        *(_DWORD *)v41 = 6;
        return 2;
      case 1:
        goto LABEL_12;
      case 2:
        goto LABEL_35;
      case 3:
        goto LABEL_38;
      case 4:
        goto LABEL_41;
      case 5:
        goto LABEL_44;
      case 6:
        *(_DWORD *)a1[7] = 13;
        v42 = a1[7];
        a1[6] = (unsigned __int8 *)aNeedDictionary;
        *((_DWORD *)v42 + 1) = 0;
        return -2;
      case 7:
        v14 = inflate_blocks(a1: *((_DWORD *)v4 + 5), a2: a1, a3: v2);
        v2 = v14;
        if ( v14 == -3 )
        {
          *(_DWORD *)a1[7] = 13;
          *((_DWORD *)a1[7] + 1) = 0;
        }
        else
        {
          if ( v14 == 0 )
            v2 = v3;
          if ( v2 != 1 )
            return v2;
          v2 = v3;
          inflate_blocks_reset(a1: *((_DWORD *)a1[7] + 5), a2: a1, a3: a1[7] + 4);
          v15 = a1[7];
          if ( *((_DWORD *)v15 + 3) != 0 )
          {
            *(_DWORD *)v15 = 12;
          }
          else
          {
            *(_DWORD *)v15 = 8;
LABEL_25:
            v16 = a1[1];
            if ( v16 == nullptr )
              return v2;
            v17 = a1[7];
            a1[1] = v16 - 1;
            ++a1[2];
            v2 = v3;
            *((_DWORD *)v17 + 2) = *(*a1)++ << 24;
            *(_DWORD *)a1[7] = 9;
LABEL_27:
            v18 = a1[1];
            if ( v18 == nullptr )
              return v2;
            v19 = *a1;
            ++a1[2];
            a1[1] = v18 - 1;
            v2 = v3;
            *((_DWORD *)a1[7] + 2) += *v19 << 16;
            ++*a1;
            *(_DWORD *)a1[7] = 10;
LABEL_29:
            v20 = a1[1];
            if ( v20 == nullptr )
              return v2;
            v21 = *a1;
            ++a1[2];
            a1[1] = v20 - 1;
            v2 = v3;
            *((_DWORD *)a1[7] + 2) += *v21 << 8;
            ++*a1;
            *(_DWORD *)a1[7] = 11;
LABEL_31:
            v22 = a1[1];
            if ( v22 == nullptr )
              return v2;
            v23 = *a1;
            v24 = (int)(a1[2] + 1);
            a1[1] = v22 - 1;
            v25 = a1[7];
            a1[2] = (unsigned __int8 *)v24;
            v2 = v3;
            *((_DWORD *)v25 + 2) += *v23;
            ++*a1;
            v26 = a1[7];
            if ( *((_DWORD *)v26 + 1) == *((_DWORD *)v26 + 2) )
            {
              *(_DWORD *)a1[7] = 12;
              return 1;
            }
            *(_DWORD *)v26 = 13;
            v27 = a1[7];
            a1[6] = (unsigned __int8 *)aIncorrectDataC;
            *((_DWORD *)v27 + 1) = 5;
          }
        }
        continue;
      case 8:
        goto LABEL_25;
      case 9:
        goto LABEL_27;
      case 0xA:
        goto LABEL_29;
      case 0xB:
        goto LABEL_31;
      case 0xC:
        return 1;
      case 0xD:
        return -3;
      default:
        return -2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038A90
// Name: _zcalloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl zcalloc(int a1, unsigned int num, unsigned int size)
{
  return calloc(num, size);
}

//------------------------------------------------------------------------------
// Address: 0x10038AB0
// Name: _zcfree
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl zcfree(int a1, void *pBlock)
{
  free(pBlock);
}

//------------------------------------------------------------------------------
// Address: 0x10038AC0
// Name: _adler32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl adler32(unsigned int a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned __int8 *v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // edi
  unsigned int i; // ebx
  int v8; // eax
  unsigned int v9; // ebp
  int v10; // edx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // edi
  int v15; // ecx
  int v16; // edi
  int v17; // ecx
  int v18; // edi
  int v19; // ecx
  int v20; // edi
  int v21; // ecx
  int v22; // edi
  int v23; // ecx
  int v24; // edi
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // edi
  int v29; // ecx
  int v30; // edi
  int v31; // ecx
  int v32; // edi
  int v33; // ecx
  int v34; // edi
  int v35; // ecx
  int v36; // edi
  int v37; // ecx
  int v38; // edi
  int v39; // ecx
  int v40; // edi

  v3 = a2;
  v4 = (unsigned __int16)a1;
  v5 = HIWORD(a1);
  if ( a2 == nullptr )
    return 1;
  for ( i = a3; i != 0; v5 %= 0xFFF1u )
  {
    v8 = i;
    if ( i >= 0x15B0 )
      v8 = 5552;
    i -= v8;
    if ( v8 >= 16 )
    {
      v9 = (unsigned int)v8 >> 4;
      v8 += -16 * ((unsigned int)v8 >> 4);
      do
      {
        v10 = *v3;
        v3 += 16;
        v11 = v10 + v4;
        v12 = v11 + v5;
        v13 = *(v3 - 15) + v11;
        v14 = v13 + v12;
        v15 = *(v3 - 14) + v13;
        v16 = v15 + v14;
        v17 = *(v3 - 13) + v15;
        v18 = v17 + v16;
        v19 = *(v3 - 12) + v17;
        v20 = v19 + v18;
        v21 = *(v3 - 11) + v19;
        v22 = v21 + v20;
        v23 = *(v3 - 10) + v21;
        v24 = v23 + v22;
        v25 = *(v3 - 9) + v23;
        v26 = v25 + v24;
        v27 = *(v3 - 8) + v25;
        v28 = v27 + v26;
        v29 = *(v3 - 7) + v27;
        v30 = v29 + v28;
        v31 = *(v3 - 6) + v29;
        v32 = v31 + v30;
        v33 = *(v3 - 5) + v31;
        v34 = v33 + v32;
        v35 = *(v3 - 4) + v33;
        v36 = v35 + v34;
        v37 = *(v3 - 3) + v35;
        v38 = v37 + v36;
        v39 = *(v3 - 2) + v37;
        v40 = v39 + v38;
        v4 = *(v3 - 1) + v39;
        v5 = v4 + v40;
        --v9;
      }
      while ( v9 != 0 );
    }
    for ( ; v8 != 0; --v8 )
    {
      v4 += *v3++;
      v5 += v4;
    }
    v4 %= 0xFFF1u;
  }
  return v4 | (v5 << 16);
}

//------------------------------------------------------------------------------
// Address: 0x10038BF0
// Name: __tr_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_init(int a1)
{
  nullsub_4();
  *(_DWORD *)(a1 + 2832) = a1 + 140;
  *(_DWORD *)(a1 + 2856) = a1 + 2676;
  *(_DWORD *)(a1 + 2840) = &off_100888B0;
  *(_DWORD *)(a1 + 2844) = a1 + 2432;
  *(_DWORD *)(a1 + 2852) = &off_100888C4;
  *(_DWORD *)(a1 + 2864) = &unk_100888D8;
  *(_WORD *)(a1 + 5808) = 0;
  *(_DWORD *)(a1 + 5812) = 0;
  *(_DWORD *)(a1 + 5804) = 8;
  return sub_10038C70(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10038C60
// Name: nullsub_4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_4()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10038C70
// Name: sub_10038C70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_WORD *__cdecl sub_10038C70(int a1)
{
  int v1; // ecx
  _WORD *v2; // eax
  _WORD *v3; // eax
  int i; // ecx
  _WORD *result; // eax
  int j; // ecx

  v1 = 286;
  v2 = (_WORD *)(a1 + 140);
  do
  {
    *v2 = 0;
    v2 += 2;
    --v1;
  }
  while ( v1 != 0 );
  v3 = (_WORD *)(a1 + 2432);
  for ( i = 30; i != 0; --i )
  {
    *v3 = 0;
    v3 += 2;
  }
  result = (_WORD *)(a1 + 2676);
  for ( j = 19; j != 0; --j )
  {
    *result = 0;
    result += 2;
  }
  *(_DWORD *)(a1 + 5796) = 0;
  *(_DWORD *)(a1 + 5792) = 0;
  *(_DWORD *)(a1 + 5800) = 0;
  *(_DWORD *)(a1 + 5784) = 0;
  *(_WORD *)(a1 + 1164) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038CE0
// Name: __tr_stored_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_stored_block(int a1, int a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  char v8; // bl
  int v9; // ecx
  int v10; // edx

  v4 = *(_DWORD *)(a1 + 5812);
  if ( v4 <= 13 )
  {
    *(_WORD *)(a1 + 5808) |= a4 << v4;
    *(_DWORD *)(a1 + 5812) = v4 + 3;
  }
  else
  {
    v5 = a4 << v4;
    v6 = *(_DWORD *)(a1 + 8);
    *(_WORD *)(a1 + 5808) |= v5;
    *(_BYTE *)(v6 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v7 = *(_DWORD *)(a1 + 8);
    v8 = *(_BYTE *)(a1 + 5809);
    v9 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v9;
    *(_BYTE *)(v9 + v7) = v8;
    v10 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v10 - 13;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)a4 >> (16 - v10);
  }
  return sub_1003A5A0(a1, a2, a3, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10038D80
// Name: __tr_align
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_align(int a1)
{
  int v1; // ecx
  char v2; // dl
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  char v8; // dl
  int v9; // ecx
  int result; // eax
  int v11; // ecx
  char v12; // dl
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  char v18; // dl
  int v19; // ecx

  v1 = *(_DWORD *)(a1 + 5812);
  *(_WORD *)(a1 + 5808) |= 2 << v1;
  if ( v1 <= 13 )
  {
    *(_DWORD *)(a1 + 5812) = v1 + 3;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v2 = *(_BYTE *)(a1 + 5809);
    v3 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v3;
    *(_BYTE *)(v3 + *(_DWORD *)(a1 + 8)) = v2;
    ++*(_DWORD *)(a1 + 20);
    v4 = *(_DWORD *)(a1 + 5812);
    *(_DWORD *)(a1 + 5812) = v4 - 13;
    *(_WORD *)(a1 + 5808) = 2u >> (16 - v4);
  }
  v5 = *(_DWORD *)(a1 + 5812);
  if ( v5 <= 9 )
  {
    *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
    *(_DWORD *)(a1 + 5812) = v5 + 7;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 8);
    v7 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
    *(_BYTE *)(v6 + v7) = *(_BYTE *)(a1 + 5808);
    v8 = *(_BYTE *)(a1 + 5809);
    v9 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v9;
    *(_BYTE *)(v9 + *(_DWORD *)(a1 + 8)) = v8;
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) -= 9;
    *(_WORD *)(a1 + 5808) = 0;
  }
  result = sub_1003A490(a1);
  v11 = *(_DWORD *)(a1 + 5812);
  if ( *(_DWORD *)(a1 + 5804) - v11 + 11 < 9 )
  {
    *(_WORD *)(a1 + 5808) |= 2 << v11;
    if ( v11 <= 13 )
    {
      *(_DWORD *)(a1 + 5812) = v11 + 3;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
      v12 = *(_BYTE *)(a1 + 5809);
      v13 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v13;
      *(_BYTE *)(v13 + *(_DWORD *)(a1 + 8)) = v12;
      ++*(_DWORD *)(a1 + 20);
      v14 = *(_DWORD *)(a1 + 5812);
      *(_DWORD *)(a1 + 5812) = v14 - 13;
      *(_WORD *)(a1 + 5808) = 2u >> (16 - v14);
    }
    v15 = *(_DWORD *)(a1 + 5812);
    if ( v15 <= 9 )
    {
      *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
      *(_DWORD *)(a1 + 5812) = v15 + 7;
    }
    else
    {
      v16 = *(_DWORD *)(a1 + 8);
      v17 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
      *(_BYTE *)(v16 + v17) = *(_BYTE *)(a1 + 5808);
      v18 = *(_BYTE *)(a1 + 5809);
      v19 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v19;
      *(_BYTE *)(v19 + *(_DWORD *)(a1 + 8)) = v18;
      ++*(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 5812) -= 9;
      *(_WORD *)(a1 + 5808) = 0;
    }
    result = sub_1003A490(a1);
  }
  *(_DWORD *)(a1 + 5804) = 7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038F90
// Name: __tr_flush_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_WORD *__cdecl _tr_flush_block(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // ecx
  int v7; // edi
  bool v8; // zf
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  char v13; // bl
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // ebx
  int v18; // ecx
  int v19; // ebx
  char v20; // al
  int v21; // ecx
  int v22; // ebx
  _WORD *result; // eax
  int v24; // [esp+20h] [ebp+10h]

  v4 = 0;
  if ( *(int *)(a1 + 124) <= 0 )
  {
    v6 = a3 + 5;
LABEL_7:
    v5 = v6;
    goto LABEL_8;
  }
  if ( *(_BYTE *)(a1 + 28) == 2 )
    sub_1003A3F0(a1);
  sub_10039180(a1, a2: a1 + 2832);
  sub_10039180(a1, a2: a1 + 2844);
  v4 = sub_10039710(a1);
  v5 = (unsigned int)(*(_DWORD *)(a1 + 5792) + 10) >> 3;
  v6 = (unsigned int)(*(_DWORD *)(a1 + 5796) + 10) >> 3;
  if ( v6 <= v5 )
    goto LABEL_7;
LABEL_8:
  if ( a3 + 4 <= v5 && a2 != 0 )
  {
    v7 = a4;
    _tr_stored_block(a1, a2, a3, a4);
  }
  else
  {
    v7 = a4;
    v8 = v6 == v5;
    v9 = *(_DWORD *)(a1 + 5812);
    if ( v8 )
    {
      v10 = a4 + 2;
      if ( v9 <= 13 )
      {
        *(_WORD *)(a1 + 5808) |= v10 << v9;
        *(_DWORD *)(a1 + 5812) = v9 + 3;
      }
      else
      {
        v11 = v10 << v9;
        v12 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5808) |= v11;
        *(_BYTE *)(v12 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
        v13 = *(_BYTE *)(a1 + 5809);
        v14 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v14;
        *(_BYTE *)(v14 + *(_DWORD *)(a1 + 8)) = v13;
        v15 = *(_DWORD *)(a1 + 5812);
        ++*(_DWORD *)(a1 + 20);
        *(_DWORD *)(a1 + 5812) = v15 - 13;
        *(_WORD *)(a1 + 5808) = (unsigned __int16)v10 >> (16 - v15);
      }
      sub_10039FE0(a1, a2: &unk_10063418, a3: &unk_10063898);
    }
    else
    {
      v16 = a4 + 4;
      if ( v9 <= 13 )
      {
        *(_WORD *)(a1 + 5808) |= v16 << v9;
        *(_DWORD *)(a1 + 5812) = v9 + 3;
      }
      else
      {
        v24 = v4;
        v17 = v16 << v9;
        v18 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5808) |= v17;
        *(_BYTE *)(v18 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
        v19 = *(_DWORD *)(a1 + 8);
        v20 = *(_BYTE *)(a1 + 5809);
        v21 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v21;
        *(_BYTE *)(v21 + v19) = v20;
        v22 = *(_DWORD *)(a1 + 5812);
        ++*(_DWORD *)(a1 + 20);
        v4 = v24;
        *(_DWORD *)(a1 + 5812) = v22 - 13;
        *(_WORD *)(a1 + 5808) = (unsigned __int16)v16 >> (16 - v22);
      }
      sub_10039870(a1, a2: *(_DWORD *)(a1 + 2836) + 1, a3: *(_DWORD *)(a1 + 2848) + 1, a4: v4 + 1);
      sub_10039FE0(a1, a2: a1 + 140, a3: a1 + 2432);
    }
  }
  result = sub_10038C70(a1);
  if ( v7 != 0 )
    return (_WORD *)sub_1003A520(a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039180
// Name: sub_10039180
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10039180(_DWORD *a1, int *a2)
{
  int v3; // edi
  int *v4; // eax
  int v5; // ebp
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int i; // ebx
  int v14; // eax
  int v15; // ebx
  int v16; // ebp
  int v17; // edx
  int v18; // ecx
  char v19; // cl
  int v20; // ecx
  int v21; // edx
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]
  int v25; // [esp+1Ch] [ebp+4h]

  v3 = *a2;
  v4 = (int *)a2[2];
  v5 = -1;
  v6 = *v4;
  v7 = v4[3];
  v8 = 0;
  v24 = v7;
  v23 = -1;
  a1[1298] = 0;
  for ( a1[1299] = 573; v8 < v7; ++v8 )
  {
    if ( *(_WORD *)(v3 + 4 * v8) != 0 )
    {
      v23 = v8;
      v9 = a1[1298] + 1;
      v5 = v8;
      a1[1298] = v9;
      a1[v9 + 725] = v8;
      v7 = v24;
      *((_BYTE *)a1 + v8 + 5200) = 0;
    }
    else
    {
      *(_WORD *)(v3 + 4 * v8 + 2) = 0;
    }
  }
  v10 = a1[1298];
  if ( v10 < 2 )
  {
    do
    {
      if ( v5 >= 2 )
        v11 = 0;
      else
        v11 = ++v5;
      v12 = v10 + 1;
      a1[1298] = v12;
      a1[v12 + 725] = v11;
      *(_WORD *)(v3 + 4 * v11) = 1;
      *((_BYTE *)a1 + v11 + 5200) = 0;
      --a1[1448];
      if ( v6 != 0 )
        a1[1449] -= *(unsigned __int16 *)(v6 + 4 * v11 + 2);
      v10 = a1[1298];
    }
    while ( v10 < 2 );
    v23 = v5;
  }
  a2[1] = v5;
  for ( i = a1[1298] / 2; i >= 1; --i )
    sub_100393A0(a1, a2: v3, a3: i);
  v25 = v24;
  do
  {
    v14 = a1[1298];
    v15 = a1[726];
    a1[726] = a1[v14 + 725];
    a1[1298] = v14 - 1;
    sub_100393A0(a1, a2: v3, a3: 1);
    v16 = a1[726];
    v17 = a1[1299] - 1;
    a1[1299] = v17;
    a1[v17 + 725] = v15;
    v18 = a1[1299] - 1;
    a1[1299] = v18;
    a1[v18 + 725] = v16;
    *(_WORD *)(v3 + 4 * v25) = *(_WORD *)(v3 + 4 * v15) + *(_WORD *)(v3 + 4 * v16);
    if ( *((_BYTE *)a1 + v15 + 5200) < *((_BYTE *)a1 + v16 + 5200) )
      v19 = *((_BYTE *)a1 + v16 + 5200);
    else
      v19 = *((_BYTE *)a1 + v15 + 5200);
    *((_BYTE *)a1 + v25 + 5200) = v19 + 1;
    *(_WORD *)(v3 + 4 * v16 + 2) = v25;
    *(_WORD *)(v3 + 4 * v15 + 2) = v25;
    a1[726] = v25++;
    sub_100393A0(a1, a2: v3, a3: 1);
  }
  while ( (int)a1[1298] >= 2 );
  v20 = a1[726];
  v21 = a1[1299] - 1;
  a1[1299] = v21;
  a1[v21 + 725] = v20;
  sub_10039480(a1, a2);
  return sub_10039690(a1: v3, a2: v23, a3: a1 + 717);
}

//------------------------------------------------------------------------------
// Address: 0x100393A0
// Name: sub_100393A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_100393A0(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // edx
  int v5; // ebp
  int v6; // ecx
  bool v7; // cc
  int v8; // esi
  int v9; // ebp
  unsigned __int16 v10; // dx
  unsigned __int16 v11; // bx
  int v12; // esi
  unsigned __int16 v13; // dx
  unsigned __int16 v14; // bx
  int v15; // edx
  int v16; // edx
  int v17; // [esp+14h] [ebp+4h]

  result = a1;
  v4 = *(_DWORD *)(a1 + 5192);
  v5 = *(_DWORD *)(a1 + 4 * a3 + 2900);
  v6 = 2 * a3;
  v7 = 2 * a3 < v4;
  v17 = v5;
  if ( 2 * a3 > v4 )
  {
    *(_DWORD *)(result + 4 * a3 + 2900) = v5;
  }
  else
  {
    while ( 1 )
    {
      if ( v7 )
      {
        v8 = *(_DWORD *)(result + 4 * v6 + 2904);
        v9 = *(_DWORD *)(result + 4 * v6 + 2900);
        v10 = *(_WORD *)(a2 + 4 * v8);
        v11 = *(_WORD *)(a2 + 4 * v9);
        if ( v10 < v11 || v10 == v11 && *(_BYTE *)(v8 + result + 5200) <= *(_BYTE *)(result + v9 + 5200) )
          ++v6;
        v5 = v17;
      }
      v12 = *(_DWORD *)(result + 4 * v6 + 2900);
      v13 = *(_WORD *)(a2 + 4 * v5);
      v14 = *(_WORD *)(a2 + 4 * v12);
      if ( v13 < v14 )
      {
LABEL_12:
        *(_DWORD *)(result + 4 * a3 + 2900) = v5;
        return result;
      }
      if ( v13 == v14 && *(_BYTE *)(result + v5 + 5200) <= *(_BYTE *)(v12 + result + 5200) )
        break;
      v15 = a3;
      a3 = v6;
      v6 *= 2;
      *(_DWORD *)(result + 4 * v15 + 2900) = v12;
      v16 = *(_DWORD *)(result + 5192);
      v7 = v6 < v16;
      if ( v6 > v16 )
        goto LABEL_12;
    }
    *(_DWORD *)(result + 4 * a3 + 2900) = v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039480
// Name: sub_10039480
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl sub_10039480(_DWORD *a1, int *a2)
{
  int v2; // ebp
  int *v3; // eax
  int v4; // ebx
  int v5; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  bool v12; // zf
  _WORD *v13; // edi
  _WORD *i; // ecx
  int v15; // esi
  int v16; // ebx
  int v17; // ecx
  _WORD *v18; // edi
  int v19; // eax
  int v21; // [esp+10h] [ebp-18h]
  int v22; // [esp+14h] [ebp-14h]
  int v23; // [esp+18h] [ebp-10h]
  int v24; // [esp+1Ch] [ebp-Ch]
  int v25; // [esp+20h] [ebp-8h]
  int v26; // [esp+24h] [ebp-4h]
  int *v27; // [esp+2Ch] [ebp+4h]
  int v28; // [esp+2Ch] [ebp+4h]
  int v29; // [esp+30h] [ebp+8h]
  int v30; // [esp+30h] [ebp+8h]

  v2 = *a2;
  v3 = (int *)a2[2];
  v24 = a2[1];
  v4 = 0;
  v5 = *v3;
  v26 = v3[1];
  v25 = v3[2];
  v21 = v3[4];
  v29 = 0;
  memset(a1 + 717, 0, 0x20u);
  *(_WORD *)(v2 + 4 * a1[a1[1299] + 725] + 2) = 0;
  v7 = a1[1299] + 1;
  if ( v7 < 573 )
  {
    v27 = &a1[v7 + 725];
    v23 = 573 - v7;
    v22 = 573;
    do
    {
      v8 = *v27;
      v9 = *(unsigned __int16 *)(v2 + 4 * *(unsigned __int16 *)(v2 + 4 * *v27 + 2) + 2) + 1;
      if ( v9 > v21 )
      {
        ++v4;
        v9 = v21;
        v29 = v4;
      }
      *(_WORD *)(v2 + 4 * v8 + 2) = v9;
      if ( v8 <= v24 )
      {
        ++*((_WORD *)a1 + v9 + 1434);
        v10 = 0;
        if ( v8 >= v25 )
          v10 = *(_DWORD *)(v26 + 4 * (v8 - v25));
        v11 = *(unsigned __int16 *)(v2 + 4 * v8);
        a1[1448] += v11 * (v10 + v9);
        if ( v5 != 0 )
          a1[1449] += v11 * (v10 + *(unsigned __int16 *)(v5 + 4 * v8 + 2));
        v4 = v29;
      }
      LOWORD(v7) = v23 - 1;
      v12 = v23 == 1;
      ++v27;
      --v23;
    }
    while ( !v12 );
    if ( v4 != 0 )
    {
      v13 = (_WORD *)a1 + v21 + 1434;
      do
      {
        v7 = v21 - 1;
        for ( i = (_WORD *)a1 + v21 + 1433; *i == 0; --v7 )
          --i;
        --*((_WORD *)a1 + v7 + 1434);
        *((_WORD *)a1 + v7 + 1435) += 2;
        --*v13;
        v4 -= 2;
      }
      while ( v4 > 0 );
      v15 = v21;
      if ( v21 != 0 )
      {
        v28 = (int)a1 + 2 * v21 + 2868;
        do
        {
          v7 = (unsigned __int16)*v13;
          v30 = v7;
          if ( *v13 != 0 )
          {
            v16 = (int)&a1[v22 + 725];
            do
            {
              v17 = *(_DWORD *)(v16 - 4);
              v16 -= 4;
              --v22;
              if ( v17 <= v24 )
              {
                v18 = (_WORD *)(v2 + 4 * v17 + 2);
                HIWORD(v19) = 0;
                if ( (unsigned __int16)*v18 != v15 )
                {
                  LOWORD(v19) = *v18;
                  a1[1448] += *(unsigned __int16 *)(v2 + 4 * v17) * (v15 - v19);
                  *v18 = v15;
                }
                v7 = --v30;
              }
            }
            while ( v7 != 0 );
          }
          --v15;
          v13 = (_WORD *)(v28 - 2);
          v28 -= 2;
        }
        while ( v15 != 0 );
      }
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10039690
// Name: sub_10039690
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl sub_10039690(int a1, int a2, int a3)
{
  __int16 v3; // cx
  int i; // eax
  __int16 v5; // si
  int j; // esi
  unsigned __int16 v7; // dx
  _WORD v9[2]; // [esp+6h] [ebp-22h]
  char v10; // [esp+Ah] [ebp-1Eh] BYREF

  v3 = 0;
  for ( i = 1; i <= 15; v9[i] = 2 * v5 )
  {
    v5 = v3 + *(_WORD *)((char *)&v9[++i] + a3 - (_DWORD)&v10);
    v3 = 2 * v5;
  }
  for ( j = 0; j <= a2; ++j )
  {
    i = *(unsigned __int16 *)(a1 + 4 * j + 2);
    if ( (_WORD)i != 0 )
    {
      v7 = v9[i + 1];
      v9[i + 1] = v7 + 1;
      LOWORD(i) = sub_1003A470(a1: v7, a2: i);
      *(_WORD *)(a1 + 4 * j) = i;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10039710
// Name: sub_10039710
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10039710(_DWORD *a1)
{
  int result; // eax

  sub_10039780(a1, a2: a1 + 35, a3: a1[709]);
  sub_10039780(a1, a2: a1 + 608, a3: a1[712]);
  sub_10039180(a1, a2: a1 + 714);
  for ( result = 18; result >= 3; --result )
  {
    if ( HIWORD(a1[(unsigned __int8)byte_10063404[result] + 669]) != 0 )
      break;
  }
  a1[1448] += 3 * result + 17;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039780
// Name: sub_10039780
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10039780(_WORD *a1, int a2, int a3)
{
  int result; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // edx
  int v7; // esi
  unsigned __int16 *v8; // ebp
  int v9; // eax
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+18h] [ebp+8h]

  result = a2;
  v4 = *(unsigned __int16 *)(a2 + 2);
  v5 = 0;
  v10 = -1;
  v6 = 7;
  v7 = 4;
  if ( (_WORD)v4 == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  *(_WORD *)(a2 + 4 * a3 + 6) = -1;
  if ( a3 >= 0 )
  {
    v11 = a3 + 1;
    v8 = (unsigned __int16 *)(result + 6);
    do
    {
      v9 = v4;
      v4 = *v8;
      if ( ++v5 >= v6 || v9 != v4 )
      {
        if ( v5 >= v7 )
        {
          if ( v9 != 0 )
          {
            if ( v9 != v10 )
              ++a1[2 * v9 + 1338];
            ++a1[1370];
          }
          else if ( v5 > 10 )
          {
            ++a1[1374];
          }
          else
          {
            ++a1[1372];
          }
        }
        else
        {
          a1[2 * v9 + 1338] += v5;
        }
        v5 = 0;
        v10 = v9;
        if ( v4 != 0 )
        {
          if ( v9 == v4 )
          {
            v6 = 6;
            v7 = 3;
          }
          else
          {
            v6 = 7;
            v7 = 4;
          }
        }
        else
        {
          v6 = 138;
          v7 = 3;
        }
      }
      v8 += 2;
      result = --v11;
    }
    while ( v11 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039870
// Name: sub_10039870
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10039870(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  char v9; // bl
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  char v16; // bl
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  char v23; // bl
  int v24; // edx
  int v25; // edx
  int i; // edi
  int v27; // ecx
  int v28; // eax
  int v29; // edx
  int v30; // ecx
  char v31; // bl
  int v32; // edx
  int v33; // edx

  v4 = a2 - 257;
  v5 = *(_DWORD *)(a1 + 5812);
  if ( v5 <= 11 )
  {
    *(_WORD *)(a1 + 5808) |= v4 << v5;
    *(_DWORD *)(a1 + 5812) = v5 + 5;
  }
  else
  {
    v6 = v4 << v5;
    v7 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v6;
    *(_BYTE *)(v7 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v8 = *(_DWORD *)(a1 + 8);
    v9 = *(_BYTE *)(a1 + 5809);
    v10 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v10;
    *(_BYTE *)(v10 + v8) = v9;
    v11 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v11 - 11;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)v4 >> (16 - v11);
  }
  v12 = *(_DWORD *)(a1 + 5812);
  if ( v12 <= 11 )
  {
    *(_WORD *)(a1 + 5808) |= (a3 - 1) << v12;
    *(_DWORD *)(a1 + 5812) = v12 + 5;
  }
  else
  {
    v13 = (a3 - 1) << v12;
    v14 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v13;
    *(_BYTE *)(v14 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v15 = *(_DWORD *)(a1 + 8);
    v16 = *(_BYTE *)(a1 + 5809);
    v17 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v17;
    *(_BYTE *)(v17 + v15) = v16;
    v18 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v18 - 11;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)(a3 - 1) >> (16 - v18);
  }
  v19 = *(_DWORD *)(a1 + 5812);
  v20 = a4 - 4;
  if ( v19 <= 12 )
  {
    *(_WORD *)(a1 + 5808) |= v20 << v19;
    *(_DWORD *)(a1 + 5812) = v19 + 4;
  }
  else
  {
    v21 = v20 << v19;
    v22 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v21;
    *(_BYTE *)(v22 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v23 = *(_BYTE *)(a1 + 5809);
    v24 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v24;
    *(_BYTE *)(v24 + *(_DWORD *)(a1 + 8)) = v23;
    v25 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v25 - 12;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)v20 >> (16 - v25);
  }
  for ( i = 0; i < a4; ++i )
  {
    v27 = *(_DWORD *)(a1 + 5812);
    v28 = 0;
    if ( v27 <= 13 )
    {
      LOBYTE(v28) = byte_10063404[i];
      *(_WORD *)(a1 + 5808) |= *(_WORD *)(a1 + 4 * v28 + 2678) << v27;
      *(_DWORD *)(a1 + 5812) = v27 + 3;
    }
    else
    {
      LOWORD(v28) = *(_WORD *)(a1 + 4 * (unsigned __int8)byte_10063404[i] + 2678);
      v29 = v28 << v27;
      v30 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5808) |= v29;
      *(_BYTE *)(v30 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
      v31 = *(_BYTE *)(a1 + 5809);
      v32 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v32;
      *(_BYTE *)(v32 + *(_DWORD *)(a1 + 8)) = v31;
      v33 = *(_DWORD *)(a1 + 5812);
      ++*(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 5812) = v33 - 13;
      *(_WORD *)(a1 + 5808) = (unsigned __int16)v28 >> (16 - v33);
    }
  }
  sub_10039AC0(a1, a2: a1 + 140, a3: a2 - 1);
  return sub_10039AC0(a1, a2: a1 + 2432, a3: a3 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10039AC0
// Name: sub_10039AC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10039AC0(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int v7; // edx
  int v8; // edi
  int v9; // ebp
  int v10; // ecx
  int v11; // edi
  unsigned __int16 v12; // si
  int v13; // edx
  int v14; // ecx
  char v15; // bl
  int v16; // edx
  int v17; // edx
  int v18; // ecx
  int v19; // ecx
  int v20; // edi
  unsigned __int16 v21; // si
  int v22; // edx
  int v23; // ecx
  char v24; // bl
  int v25; // edx
  int v26; // edx
  int v27; // ecx
  int v28; // ecx
  int v29; // edi
  unsigned __int16 v30; // si
  int v31; // edx
  int v32; // ecx
  char v33; // bl
  int v34; // edx
  int v35; // edx
  int v36; // ecx
  int v37; // esi
  int v38; // edx
  int v39; // ecx
  char v40; // bl
  int v41; // edx
  int v42; // edx
  int v43; // ecx
  int v44; // ecx
  int v45; // edi
  unsigned __int16 v46; // si
  int v47; // edx
  int v48; // ecx
  char v49; // bl
  int v50; // edx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edx
  int v55; // ecx
  char v56; // bl
  int v57; // edx
  int v58; // edx
  unsigned __int16 v59; // si
  int v60; // edx
  int v61; // ecx
  char v62; // bl
  int v63; // edx
  int v64; // edx
  int v65; // ecx
  int v66; // esi
  int v67; // edx
  int v68; // ecx
  char v69; // bl
  int v70; // edx
  int v71; // edx
  bool v72; // zf
  int v73; // [esp+Ch] [ebp-8h]
  int v74; // [esp+10h] [ebp-4h]
  int v75; // [esp+18h] [ebp+4h]
  int v76; // [esp+1Ch] [ebp+8h]
  unsigned __int16 *v77; // [esp+20h] [ebp+Ch]

  result = a2;
  v4 = *(unsigned __int16 *)(a2 + 2);
  v5 = 0;
  v73 = -1;
  v6 = 7;
  v7 = 4;
  if ( (_WORD)v4 == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  if ( a3 >= 0 )
  {
    v8 = a3 + 1;
    v77 = (unsigned __int16 *)(a2 + 6);
    result = a1;
    v74 = v8;
    do
    {
      v9 = v4;
      ++v5;
      v4 = *v77;
      v75 = v4;
      v76 = v5;
      if ( v5 < v6 && v9 == v4 )
        goto LABEL_44;
      if ( v5 < v7 )
      {
        do
        {
          v10 = *(_DWORD *)(result + 5812);
          v11 = *(unsigned __int16 *)(result + 4 * v9 + 2678);
          if ( v10 <= 16 - (unsigned __int16)v11 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 4 * v9 + 2676) << v10;
            v18 = v11 + v10;
          }
          else
          {
            v12 = *(_WORD *)(result + 4 * v9 + 2676);
            v13 = v12 << v10;
            v14 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v13;
            *(_BYTE *)(v14 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v15 = *(_BYTE *)(result + 5809);
            v16 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v16;
            *(_BYTE *)(v16 + *(_DWORD *)(result + 8)) = v15;
            v17 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v18 = v17 + v11 - 16;
            *(_WORD *)(result + 5808) = v12 >> (16 - v17);
            v5 = v76;
          }
          --v5;
          *(_DWORD *)(result + 5812) = v18;
          v76 = v5;
        }
        while ( v5 != 0 );
        goto LABEL_39;
      }
      if ( v9 != 0 )
      {
        if ( v9 != v73 )
        {
          v19 = *(_DWORD *)(result + 5812);
          v20 = *(unsigned __int16 *)(result + 4 * v9 + 2678);
          if ( v19 <= 16 - (unsigned __int16)v20 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 4 * v9 + 2676) << v19;
            v27 = v20 + v19;
          }
          else
          {
            v21 = *(_WORD *)(result + 4 * v9 + 2676);
            v22 = v21 << v19;
            v23 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v22;
            *(_BYTE *)(v23 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v24 = *(_BYTE *)(result + 5809);
            v25 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v25;
            *(_BYTE *)(v25 + *(_DWORD *)(result + 8)) = v24;
            v26 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v27 = v26 + v20 - 16;
            *(_WORD *)(result + 5808) = v21 >> (16 - v26);
            v5 = v76;
          }
          --v5;
          *(_DWORD *)(result + 5812) = v27;
          v76 = v5;
        }
        v28 = *(_DWORD *)(result + 5812);
        v29 = *(unsigned __int16 *)(result + 2742);
        if ( v28 <= 16 - (unsigned __int16)v29 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2740) << v28;
          v36 = v29 + v28;
        }
        else
        {
          v30 = *(_WORD *)(result + 2740);
          v31 = v30 << v28;
          v32 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v31;
          *(_BYTE *)(v32 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v33 = *(_BYTE *)(result + 5809);
          v34 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v34;
          *(_BYTE *)(v34 + *(_DWORD *)(result + 8)) = v33;
          v35 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v36 = v35 + v29 - 16;
          *(_WORD *)(result + 5808) = v30 >> (16 - v35);
          v5 = v76;
        }
        v37 = v5 - 3;
        *(_DWORD *)(result + 5812) = v36;
        if ( v36 > 14 )
        {
          v38 = v37 << v36;
          v39 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v38;
          *(_BYTE *)(v39 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v40 = *(_BYTE *)(result + 5809);
          v41 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v41;
          *(_BYTE *)(v41 + *(_DWORD *)(result + 8)) = v40;
          v42 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          *(_DWORD *)(result + 5812) = v42 - 14;
          *(_WORD *)(result + 5808) = (unsigned __int16)v37 >> (16 - v42);
          goto LABEL_39;
        }
        *(_WORD *)(result + 5808) |= v37 << v36;
        v43 = v36 + 2;
      }
      else
      {
        v44 = *(_DWORD *)(result + 5812);
        HIWORD(v45) = 0;
        if ( v5 > 10 )
        {
          LOWORD(v45) = *(_WORD *)(result + 2750);
          if ( v44 <= 16 - v45 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2748) << v44;
            v65 = v45 + v44;
          }
          else
          {
            v59 = *(_WORD *)(result + 2748);
            v60 = v59 << v44;
            v61 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v60;
            *(_BYTE *)(v61 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v62 = *(_BYTE *)(result + 5809);
            v63 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v63;
            *(_BYTE *)(v63 + *(_DWORD *)(result + 8)) = v62;
            v64 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v65 = v64 + v45 - 16;
            *(_WORD *)(result + 5808) = v59 >> (16 - v64);
            v5 = v76;
          }
          v66 = v5 - 11;
          *(_DWORD *)(result + 5812) = v65;
          if ( v65 > 9 )
          {
            v67 = v66 << v65;
            v68 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v67;
            *(_BYTE *)(v68 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v69 = *(_BYTE *)(result + 5809);
            v70 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v70;
            *(_BYTE *)(v70 + *(_DWORD *)(result + 8)) = v69;
            v71 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5812) = v71 - 9;
            *(_WORD *)(result + 5808) = (unsigned __int16)v66 >> (16 - v71);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5808) |= v66 << v65;
          v43 = v65 + 7;
        }
        else
        {
          LOWORD(v45) = *(_WORD *)(result + 2746);
          if ( v44 <= 16 - v45 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2744) << v44;
            v52 = v45 + v44;
          }
          else
          {
            v46 = *(_WORD *)(result + 2744);
            v47 = v46 << v44;
            v48 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v47;
            *(_BYTE *)(v48 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v49 = *(_BYTE *)(result + 5809);
            v50 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v50;
            *(_BYTE *)(v50 + *(_DWORD *)(result + 8)) = v49;
            v51 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v52 = v51 + v45 - 16;
            *(_WORD *)(result + 5808) = v46 >> (16 - v51);
            v5 = v76;
          }
          v53 = v5 - 3;
          *(_DWORD *)(result + 5812) = v52;
          if ( v52 > 13 )
          {
            v54 = v53 << v52;
            v55 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v54;
            *(_BYTE *)(v55 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v56 = *(_BYTE *)(result + 5809);
            v57 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v57;
            *(_BYTE *)(v57 + *(_DWORD *)(result + 8)) = v56;
            v58 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5812) = v58 - 13;
            *(_WORD *)(result + 5808) = (unsigned __int16)v53 >> (16 - v58);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5808) |= v53 << v52;
          v43 = v52 + 3;
        }
      }
      *(_DWORD *)(result + 5812) = v43;
LABEL_39:
      v4 = v75;
      v5 = 0;
      v73 = v9;
      if ( v75 != 0 )
      {
        if ( v9 == v75 )
        {
          v6 = 6;
          v7 = 3;
        }
        else
        {
          v6 = 7;
          v7 = 4;
        }
      }
      else
      {
        v6 = 138;
        v7 = 3;
      }
LABEL_44:
      v72 = v74 == 1;
      v77 += 2;
      --v74;
    }
    while ( !v72 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039FE0
// Name: sub_10039FE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10039FE0(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // ebx
  unsigned int v5; // edi
  int v6; // ebp
  int v7; // esi
  int v8; // ecx
  unsigned __int16 v9; // di
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  int v13; // edx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // edi
  unsigned __int16 v18; // di
  int v19; // edx
  int v20; // ecx
  char v21; // bl
  int v22; // edx
  int v23; // edx
  __int16 v24; // di
  __int16 v25; // bx
  int v26; // ecx
  int v27; // edi
  int v28; // esi
  int v29; // ecx
  int v30; // edx
  int v31; // ecx
  char v32; // bl
  int v33; // edx
  int v34; // edx
  int v35; // ecx
  unsigned int v36; // ebp
  int v37; // edx
  int v38; // ecx
  int v39; // edi
  unsigned __int16 v40; // si
  int v41; // edx
  int v42; // ecx
  char v43; // bl
  int v44; // edx
  int v45; // edx
  __int16 v46; // si
  int v47; // ecx
  int v48; // esi
  unsigned int v49; // ebp
  int v50; // ecx
  unsigned int v51; // edx
  int v52; // ecx
  int v53; // ecx
  int v54; // edx
  int v55; // edx
  int v56; // ecx
  int v57; // edi
  unsigned __int16 v58; // si
  int v59; // edx
  int v60; // ecx
  int v61; // ecx
  int v62; // edx
  int v63; // edx
  int v64; // ecx
  int v65; // [esp+10h] [ebp-8h]
  unsigned int v66; // [esp+14h] [ebp-4h]
  int v67; // [esp+1Ch] [ebp+4h]
  int v68; // [esp+1Ch] [ebp+4h]

  result = a1;
  v4 = a2;
  v5 = 0;
  if ( *(_DWORD *)(a1 + 5784) != 0 )
  {
    do
    {
      v6 = *(unsigned __int16 *)(*(_DWORD *)(result + 5788) + 2 * v5);
      v7 = *(unsigned __int8 *)(v5 + *(_DWORD *)(result + 5776));
      v8 = *(_DWORD *)(result + 5812);
      v66 = v5 + 1;
      if ( (_WORD)v6 != 0 )
      {
        HIWORD(v17) = 0;
        v16 = (unsigned __int8)_length_code[v7];
        v67 = v16;
        LOWORD(v17) = *(_WORD *)(v4 + 4 * v16 + 1030);
        v65 = (unsigned __int16)v17;
        if ( v8 <= 16 - (unsigned __int16)v17 )
        {
          v25 = *(_WORD *)(a2 + 4 * v16 + 1028) << v8;
          v26 = *(_DWORD *)(result + 5812);
          *(_WORD *)(result + 5808) |= v25;
          *(_DWORD *)(result + 5812) = v17 + v26;
        }
        else
        {
          v18 = *(_WORD *)(a2 + 4 * v16 + 1028);
          v19 = v18 << v8;
          v20 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v19;
          *(_BYTE *)(v20 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v21 = *(_BYTE *)(result + 5809);
          v22 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v22;
          *(_BYTE *)(v22 + *(_DWORD *)(result + 8)) = v21;
          v23 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v24 = v18 >> (16 - v23);
          *(_DWORD *)(result + 5812) = v23 + v65 - 16;
          v16 = v67;
          *(_WORD *)(result + 5808) = v24;
        }
        v27 = dword_100632C8[v16];
        if ( v27 != 0 )
        {
          v28 = v7 - dword_10063C10[v16];
          v29 = *(_DWORD *)(result + 5812);
          if ( v29 <= 16 - v27 )
          {
            *(_WORD *)(result + 5808) |= v28 << v29;
            v35 = v27 + v29;
          }
          else
          {
            v30 = v28 << v29;
            v31 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v30;
            *(_BYTE *)(v31 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v32 = *(_BYTE *)(result + 5809);
            v33 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v33;
            *(_BYTE *)(v33 + *(_DWORD *)(result + 8)) = v32;
            v34 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v35 = v34 + v27 - 16;
            *(_WORD *)(result + 5808) = (unsigned __int16)v28 >> (16 - v34);
          }
          *(_DWORD *)(result + 5812) = v35;
        }
        v36 = v6 - 1;
        if ( v36 >= 0x100 )
          v37 = (unsigned __int8)byte_10063A10[v36 >> 7];
        else
          v37 = (unsigned __int8)_dist_code[v36];
        v38 = *(_DWORD *)(result + 5812);
        v39 = *(unsigned __int16 *)(a3 + 4 * v37 + 2);
        v68 = v37;
        if ( v38 <= 16 - (unsigned __int16)v39 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(a3 + 4 * v37) << v38;
          v47 = v39 + v38;
        }
        else
        {
          v40 = *(_WORD *)(a3 + 4 * v37);
          v41 = v40 << v38;
          v42 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v41;
          *(_BYTE *)(v42 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v43 = *(_BYTE *)(result + 5809);
          v44 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v44;
          *(_BYTE *)(v44 + *(_DWORD *)(result + 8)) = v43;
          v45 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v46 = v40 >> (16 - v45);
          v47 = v45 + v39 - 16;
          v37 = v68;
          *(_WORD *)(result + 5808) = v46;
        }
        v4 = a2;
        *(_DWORD *)(result + 5812) = v47;
        v48 = dword_10063340[v37];
        if ( v48 == 0 )
          goto LABEL_25;
        v49 = v36 - dword_10063C88[v37];
        v50 = *(_DWORD *)(result + 5812);
        if ( v50 <= 16 - v48 )
        {
          *(_WORD *)(result + 5808) |= v49 << v50;
          v15 = v48 + v50;
        }
        else
        {
          v51 = v49 << v50;
          v52 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v51;
          *(_BYTE *)(v52 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v53 = *(_DWORD *)(result + 8);
          v54 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v54;
          *(_BYTE *)(v54 + v53) = *(_BYTE *)(result + 5809);
          v55 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v15 = v55 + v48 - 16;
          *(_WORD *)(result + 5808) = (unsigned __int16)v49 >> (16 - v55);
        }
      }
      else
      {
        LOWORD(v6) = *(_WORD *)(v4 + 4 * v7 + 2);
        if ( v8 <= 16 - (unsigned __int16)v6 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(v4 + 4 * v7) << v8;
          v15 = v6 + v8;
        }
        else
        {
          v9 = *(_WORD *)(v4 + 4 * v7);
          v10 = v9 << v8;
          v11 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v10;
          *(_BYTE *)(v11 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v12 = *(_DWORD *)(result + 8);
          v13 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v13;
          *(_BYTE *)(v13 + v12) = *(_BYTE *)(result + 5809);
          v14 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v15 = v14 + v6 - 16;
          *(_WORD *)(result + 5808) = v9 >> (16 - v14);
        }
      }
      *(_DWORD *)(result + 5812) = v15;
LABEL_25:
      v5 = v66;
    }
    while ( v66 < *(_DWORD *)(result + 5784) );
  }
  v56 = *(_DWORD *)(result + 5812);
  v57 = *(unsigned __int16 *)(v4 + 1026);
  if ( v56 <= 16 - (unsigned __int16)v57 )
  {
    *(_WORD *)(result + 5808) |= *(_WORD *)(v4 + 1024) << v56;
    v64 = v57 + v56;
  }
  else
  {
    v58 = *(_WORD *)(v4 + 1024);
    v59 = v58 << v56;
    v60 = *(_DWORD *)(result + 8);
    *(_WORD *)(result + 5808) |= v59;
    *(_BYTE *)(v60 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
    v61 = *(_DWORD *)(result + 8);
    v62 = *(_DWORD *)(result + 20) + 1;
    *(_DWORD *)(result + 20) = v62;
    *(_BYTE *)(v61 + v62) = *(_BYTE *)(result + 5809);
    v63 = *(_DWORD *)(result + 5812);
    ++*(_DWORD *)(result + 20);
    v64 = v63 + v57 - 16;
    *(_WORD *)(result + 5808) = v58 >> (16 - v63);
  }
  *(_DWORD *)(result + 5812) = v64;
  *(_DWORD *)(result + 5804) = *(unsigned __int16 *)(v4 + 1026);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A3F0
// Name: sub_1003A3F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl sub_1003A3F0(int a1)
{
  unsigned int v1; // edi
  unsigned int v2; // edx
  unsigned __int16 *v3; // eax
  int i; // ecx
  unsigned __int16 v5; // si
  unsigned __int16 *v6; // eax
  int j; // ecx
  unsigned __int16 v8; // bp
  unsigned __int16 *v9; // ecx
  int k; // eax
  unsigned __int16 v11; // si
  unsigned int v12; // edi

  v1 = 0;
  v2 = 0;
  v3 = (unsigned __int16 *)(a1 + 140);
  for ( i = 7; i != 0; --i )
  {
    v5 = *v3;
    v3 += 2;
    v2 += v5;
  }
  v6 = (unsigned __int16 *)(a1 + 168);
  for ( j = 121; j != 0; --j )
  {
    v8 = *v6;
    v6 += 2;
    v1 += v8;
  }
  v9 = (unsigned __int16 *)(a1 + 652);
  for ( k = 128; k != 0; --k )
  {
    v11 = *v9;
    v9 += 2;
    v2 += v11;
  }
  v12 = v1 >> 2;
  *(_BYTE *)(a1 + 28) = v2 <= v12;
  return v2 <= v12;
}

//------------------------------------------------------------------------------
// Address: 0x1003A470
// Name: sub_1003A470
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_1003A470(unsigned int a1, int a2)
{
  unsigned int v4; // eax
  int v5; // esi

  v4 = 0;
  do
  {
    v5 = a1 & 1;
    a1 >>= 1;
    v4 = 2 * (v5 | v4);
    --a2;
  }
  while ( a2 > 0 );
  return v4 >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A490
// Name: sub_1003A490
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1003A490(int a1)
{
  int result; // eax
  int v2; // ecx
  char v3; // bl
  int v4; // edx
  int v5; // edx
  int v6; // ecx

  result = a1;
  v2 = *(_DWORD *)(a1 + 5812);
  if ( v2 == 16 )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v3 = *(_BYTE *)(a1 + 5809);
    v4 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v4;
    *(_BYTE *)(v4 + *(_DWORD *)(a1 + 8)) = v3;
    ++*(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  else if ( v2 >= 8 )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v5 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = *(unsigned __int8 *)(a1 + 5809);
    v6 = *(_DWORD *)(a1 + 5812);
    *(_DWORD *)(a1 + 20) = v5 + 1;
    *(_DWORD *)(a1 + 5812) = v6 - 8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A520
// Name: sub_1003A520
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1003A520(int a1)
{
  int result; // eax
  int v2; // edx
  char v3; // bl
  int v4; // edx

  result = a1;
  v2 = *(_DWORD *)(a1 + 5812);
  if ( v2 <= 8 )
  {
    if ( v2 > 0 )
      *(_BYTE *)(*(_DWORD *)(a1 + 8) + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5808);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v3 = *(_BYTE *)(a1 + 5809);
    v4 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v4;
    *(_BYTE *)(v4 + *(_DWORD *)(a1 + 8)) = v3;
    ++*(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A5A0
// Name: sub_1003A5A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1003A5A0(_DWORD *a1, _BYTE *a2, int a3, int a4)
{
  int result; // eax
  int v5; // edi
  int v6; // edx
  int v7; // edi
  int v8; // ecx
  int v9; // edi
  int v10; // ecx

  sub_1003A520((int)a1);
  result = a3;
  a1[1451] = 8;
  if ( a4 != 0 )
  {
    *(_BYTE *)(a1[5] + a1[2]) = a3;
    v5 = a1[2];
    v6 = a1[5] + 1;
    a1[5] = v6;
    *(_BYTE *)(v6 + v5) = BYTE1(a3);
    v7 = a1[2];
    v8 = a1[5] + 1;
    a1[5] = v8;
    *(_BYTE *)(v8 + v7) = ~(_BYTE)a3;
    v9 = a1[5] + 1;
    v10 = a1[2];
    a1[5] = v9;
    *(_BYTE *)(v9 + v10) = ~BYTE1(a3);
    ++a1[5];
  }
  if ( a3 != 0 )
  {
    do
    {
      *(_BYTE *)(a1[5] + a1[2]) = *a2++;
      --result;
      ++a1[5];
    }
    while ( result != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A640
// Name: _inflate_blocks_reset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int (__cdecl *__cdecl inflate_blocks_reset(_DWORD *a1, int a2, _DWORD *a3))(_DWORD, _DWORD, _DWORD)
{
  int v3; // eax
  int (__cdecl *result)(_DWORD, _DWORD, _DWORD); // eax

  if ( a3 != nullptr )
    *a3 = a1[15];
  if ( *a1 == 4 || *a1 == 5 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[3]);
  if ( *a1 == 6 )
    inflate_codes_free(a1: a1[1], a2);
  v3 = a1[10];
  *a1 = 0;
  a1[13] = v3;
  a1[12] = v3;
  result = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))a1[14];
  a1[7] = 0;
  a1[8] = 0;
  if ( result != nullptr )
  {
    result = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))result(a1: 0, a2: 0, a3: 0);
    a1[15] = result;
    *(_DWORD *)(a2 + 48) = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A6C0
// Name: _inflate_blocks_new
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks_new(int a1, int a2, int a3)
{
  int result; // eax
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // eax

  result = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 1, a3: 64);
  v4 = (_DWORD *)result;
  if ( result != 0 )
  {
    v5 = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 8, a3: 1440);
    v4[9] = v5;
    if ( v5 != 0 )
    {
      v6 = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 1, a3);
      v4[10] = v6;
      if ( v6 != 0 )
      {
        v4[11] = a3 + v6;
        v4[14] = a2;
        *v4 = 0;
        inflate_blocks_reset(a1: v4, a2: a1, a3: nullptr);
        return (int)v4;
      }
      else
      {
        (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4[9]);
        (*(void (__cdecl **)(_DWORD, _DWORD *))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4);
        return 0;
      }
    }
    else
    {
      (*(void (__cdecl **)(_DWORD, _DWORD *))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4);
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A760
// Name: _inflate_blocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks(_DWORD *a1, int *a2, int a3)
{
  unsigned int v4; // edx
  unsigned int v5; // ebp
  char *v6; // ecx
  unsigned int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // eax
  int v12; // edx
  unsigned int v13; // ebp
  int v14; // ecx
  int v15; // eax
  unsigned __int8 *v16; // eax
  int v17; // edi
  int v18; // esi
  int v19; // edx
  unsigned int v20; // edi
  unsigned int v21; // ecx
  char *v22; // ecx
  char *v23; // edx
  unsigned int v24; // eax
  unsigned int v25; // esi
  int v26; // eax
  char *v27; // edx
  unsigned int v28; // esi
  int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edi
  unsigned int v34; // esi
  unsigned __int8 *v35; // eax
  int v36; // edx
  unsigned int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  int *v40; // esi
  int v41; // eax
  unsigned int v42; // edi
  unsigned __int8 *v43; // eax
  char v44; // cl
  int v45; // eax
  unsigned int v46; // edx
  unsigned int v47; // ecx
  unsigned __int8 *v48; // eax
  unsigned int v49; // ecx
  char v50; // cl
  int v51; // edx
  int v52; // edx
  unsigned int v53; // ecx
  unsigned int v54; // edx
  char v55; // cl
  unsigned int v56; // edi
  unsigned int v57; // eax
  int v58; // ecx
  int v59; // eax
  unsigned int v60; // eax
  unsigned int v61; // eax
  int v62; // edx
  int v63; // eax
  unsigned __int8 *v64; // edi
  int v65; // edx
  int v66; // eax
  char *v67; // ecx
  unsigned __int8 *v68; // edi
  unsigned int v69; // edx
  unsigned int v70; // eax
  int v71; // eax
  int v72; // ebp
  int result; // eax
  int v74; // ebp
  unsigned __int8 **v75; // eax
  unsigned __int8 *v76; // edx
  unsigned __int8 *v77; // esi
  int v78; // ebp
  int v79; // ebp
  int v80; // ebp
  unsigned __int8 *v81; // edx
  unsigned __int8 *v82; // ebp
  unsigned __int8 *v83; // ebp
  int v84; // esi
  unsigned __int8 *v85; // esi
  int v86; // ebp
  unsigned __int8 *v87; // edi
  int v88; // edx
  int v89; // ecx
  unsigned __int8 *v90; // edx
  bool v91; // zf
  unsigned __int8 *v92; // edi
  int v93; // ecx
  unsigned __int8 *v94; // edi
  int v95; // ecx
  unsigned __int8 *v96; // edi
  char *v97; // ecx
  int v98; // edx
  unsigned __int8 *v99; // ebp
  unsigned __int8 *v100; // ebp
  unsigned __int8 *v101; // esi
  int v102; // [esp-1Ch] [ebp-60h]
  int v103; // [esp-14h] [ebp-58h]
  int v104; // [esp-8h] [ebp-4Ch]
  int v105; // [esp-8h] [ebp-4Ch]
  int v106; // [esp-4h] [ebp-48h]
  unsigned int v107; // [esp-4h] [ebp-48h]
  unsigned __int8 *v108; // [esp+10h] [ebp-34h]
  unsigned int v109; // [esp+14h] [ebp-30h]
  int v110; // [esp+18h] [ebp-2Ch] BYREF
  unsigned int v111; // [esp+1Ch] [ebp-28h]
  int v112; // [esp+20h] [ebp-24h] BYREF
  int v113; // [esp+24h] [ebp-20h] BYREF
  int v114; // [esp+28h] [ebp-1Ch] BYREF
  int v115; // [esp+2Ch] [ebp-18h] BYREF
  int v116; // [esp+30h] [ebp-14h] BYREF
  unsigned int v117; // [esp+34h] [ebp-10h]
  unsigned int v118; // [esp+38h] [ebp-Ch]
  int v119; // [esp+3Ch] [ebp-8h] BYREF
  int v120; // [esp+40h] [ebp-4h] BYREF
  char *v121; // [esp+48h] [ebp+4h]
  int v122; // [esp+50h] [ebp+Ch]

  v4 = a2[1];
  v5 = a1[7];
  v108 = (unsigned __int8 *)*a2;
  v6 = (char *)a1[13];
  v110 = a1[8];
  v7 = a1[12];
  v109 = v4;
  v121 = v6;
  if ( (unsigned int)v6 >= v7 )
    v8 = a1[11] - (_DWORD)v6;
  else
    v8 = v7 - (_DWORD)v6 - 1;
  v111 = v8;
  while ( 2 )
  {
    switch ( *a1 )
    {
      case 0:
        v9 = v108;
        v10 = v110;
        if ( v5 >= 3 )
          goto LABEL_10;
        v11 = v109;
        do
        {
          if ( v11 == 0 )
          {
            a1[8] = v10;
            a1[7] = v5;
            v72 = (int)&v9[a2[2] - *a2];
            a2[1] = 0;
            a2[2] = v72;
            *a2 = (int)v9;
            a1[13] = v121;
            return inflate_flush(a1, a2, a3);
          }
          --v11;
          a3 = 0;
          v12 = *v9 << v5;
          v5 += 8;
          v109 = v11;
          v10 |= v12;
          ++v9;
          v110 = v10;
          v108 = v9;
        }
        while ( v5 < 3 );
LABEL_10:
        a1[6] = v10 & 1;
        switch ( (unsigned __int8)(v10 & 7) >> 1 )
        {
          case 0:
            v13 = v5 - 3;
            *a1 = 1;
            v14 = v13 & 7;
            v5 = v13 - v14;
            v110 = v10 >> 3 >> v14;
            continue;
          case 1:
            inflate_trees_fixed(a1: &v116, a2: &v115, a3: &v114, a4: &v113);
            v15 = inflate_codes_new(a1: v116, a2: v115, a3: v114, a4: v113, a5: a2);
            a1[1] = v15;
            if ( v15 != 0 )
            {
              v110 = v10 >> 3;
              v5 -= 3;
              *a1 = 6;
              continue;
            }
            a1[8] = v10;
            a1[7] = v5;
            v74 = a2[2];
            a2[1] = v109;
            a2[2] = (int)&v9[v74 - *a2];
            *a2 = (int)v9;
            a1[13] = v121;
            result = inflate_flush(a1, a2, a3: -4);
            break;
          case 2:
            v110 = v10 >> 3;
            v5 -= 3;
            *a1 = 3;
            continue;
          case 3:
            v75 = (unsigned __int8 **)a2;
            *a1 = 9;
            a2[6] = (int)aInvalidBlockTy;
            a1[8] = v10 >> 3;
            a1[7] = v5 - 3;
            a2[1] = v109;
            v76 = &v9[-*a2];
            *a2 = (int)v9;
            v106 = -3;
            goto LABEL_129;
          default:
            continue;
        }
        return result;
      case 1:
        v16 = v108;
        v17 = v109;
        v18 = v110;
        if ( v5 >= 0x20 )
          goto LABEL_18;
        do
        {
          if ( v17 == 0 )
          {
            a1[8] = v18;
            a1[7] = v5;
            v77 = (unsigned __int8 *)*a2;
            v78 = a2[2];
            a2[1] = 0;
            *a2 = (int)v16;
            a2[2] = v16 - v77 + v78;
            a1[13] = v121;
            return inflate_flush(a1, a2, a3);
          }
          a3 = 0;
          --v17;
          v19 = *v16 << v5;
          v5 += 8;
          v109 = v17;
          v18 |= v19;
          v108 = ++v16;
        }
        while ( v5 < 0x20 );
LABEL_18:
        if ( (unsigned int)~v18 >> 16 != (unsigned __int16)v18 )
        {
          *a1 = 9;
          a2[6] = (int)aInvalidStoredB;
          a1[8] = v18;
          a1[7] = v5;
          v79 = (int)&v16[a2[2] - *a2];
          *a2 = (int)v16;
          a2[1] = v17;
          a2[2] = v79;
          a1[13] = v121;
          return inflate_flush(a1, a2, a3: -3);
        }
        v5 = 0;
        a1[1] = (unsigned __int16)v18;
        v110 = 0;
        if ( (_WORD)v18 != 0 )
        {
          *a1 = 2;
          continue;
        }
LABEL_45:
        *a1 = a1[6] != 0 ? 7 : 0;
        continue;
      case 2:
        v20 = v109;
        if ( v109 == 0 )
        {
          v75 = (unsigned __int8 **)a2;
          a1[8] = v110;
          a1[7] = v5;
          v80 = a2[2];
          v81 = &v108[-*a2];
          a2[1] = 0;
          v82 = &v81[v80];
          *a2 = (int)v108;
          v106 = a3;
          goto LABEL_130;
        }
        v21 = v111;
        if ( v111 == 0 )
        {
          v22 = (char *)a1[11];
          v23 = v121;
          if ( v121 != v22 )
            goto LABEL_29;
          v24 = a1[12];
          v25 = a1[10];
          if ( v24 == v25 )
            goto LABEL_29;
          v23 = (char *)a1[10];
          v121 = v23;
          v21 = v25 >= v24 ? (unsigned int)&v22[-v25] : v24 - v25 - 1;
          v111 = v21;
          if ( v21 == 0 )
          {
LABEL_29:
            a1[13] = v23;
            v26 = inflate_flush(a1, a2, a3);
            v27 = (char *)a1[13];
            v28 = a1[12];
            v122 = v26;
            v121 = v27;
            if ( (unsigned int)v27 >= v28 )
              v21 = a1[11] - (_DWORD)v27;
            else
              v21 = v28 - (_DWORD)v27 - 1;
            v29 = a1[11];
            v111 = v21;
            v112 = v29;
            if ( v27 == (char *)v29 )
            {
              v30 = a1[10];
              if ( v28 != v30 )
              {
                v27 = (char *)a1[10];
                v121 = v27;
                if ( v30 >= v28 )
                  v21 = v112 - v30;
                else
                  v21 = v28 - v30 - 1;
                v111 = v21;
              }
            }
            if ( v21 == 0 )
            {
              a1[8] = v110;
              a1[7] = v5;
              v83 = (unsigned __int8 *)*a2;
              v84 = a2[2];
              a2[1] = v109;
              *a2 = (int)v108;
              a2[2] = v108 - v83 + v84;
              a1[13] = v27;
              return inflate_flush(a1, a2, a3: v122);
            }
            v20 = v109;
          }
        }
        v31 = a1[1];
        a3 = 0;
        if ( v31 > v20 )
          v31 = v20;
        if ( v31 > v21 )
          v31 = v21;
        qmemcpy(v121, v108, v31);
        v108 += v31;
        v32 = a1[1] - v31;
        v109 -= v31;
        v121 += v31;
        v111 -= v31;
        a1[1] = v32;
        if ( v32 == 0 )
          goto LABEL_45;
        continue;
      case 3:
        v33 = v110;
        if ( v5 >= 0xE )
          goto LABEL_50;
        v34 = v109;
        v35 = v108;
        do
        {
          if ( v34 == 0 )
          {
            v75 = (unsigned __int8 **)a2;
            a1[8] = v33;
            a1[7] = v5;
            v85 = (unsigned __int8 *)*a2;
            v86 = a2[2];
            a2[1] = 0;
            *a2 = (int)v108;
            v82 = (unsigned __int8 *)(v108 - v85 + v86);
            v106 = a3;
            goto LABEL_130;
          }
          --v34;
          a3 = 0;
          v36 = *v35 << v5;
          v5 += 8;
          v109 = v34;
          v33 |= v36;
          v108 = ++v35;
        }
        while ( v5 < 0xE );
LABEL_50:
        v37 = v33 & 0x3FFF;
        a1[1] = v37;
        v38 = v33 & 0x1F;
        if ( v38 > 0x1D || (unsigned int)(v39 = (v37 >> 5) & 0x1F) > 0x1D )
        {
          v75 = (unsigned __int8 **)a2;
          *a1 = 9;
          v106 = -3;
          a2[6] = (int)aTooManyLengthO;
          a1[8] = v33;
LABEL_127:
          a1[7] = v5;
          v75[1] = (unsigned __int8 *)v109;
LABEL_128:
          v101 = *v75;
          *v75 = v108;
          v76 = (unsigned __int8 *)(v108 - v101);
LABEL_129:
          v82 = &v75[2][(_DWORD)v76];
LABEL_130:
          v75[2] = v82;
          a1[13] = v121;
          return inflate_flush(a1, a2: v75, a3: v106);
        }
        v40 = a2;
        v41 = ((int (__cdecl *)(int, unsigned int, int))a2[8])(a1: a2[10], a2: v39 + v38 + 258, a3: 4);
        a1[3] = v41;
        if ( v41 == 0 )
        {
          a1[8] = v33;
          a1[7] = v5;
          v87 = (unsigned __int8 *)*a2;
          v88 = a2[2];
          a2[1] = v109;
          *a2 = (int)v108;
          a2[2] = v108 - v87 + v88;
          a1[13] = v121;
          return inflate_flush(a1, a2, a3: -4);
        }
        v42 = v33 >> 14;
        v5 -= 14;
        a1[2] = 0;
        *a1 = 4;
LABEL_55:
        if ( a1[2] < (unsigned int)((a1[1] >> 10) + 4) )
        {
          while ( v5 >= 3 )
          {
LABEL_60:
            v45 = v42 & 7;
            v5 -= 3;
            v42 >>= 3;
            *(_DWORD *)(a1[3] + 4 * dword_10063D00[a1[2]]) = v45;
            v46 = a1[2] + 1;
            a1[2] = v46;
            if ( v46 >= (a1[1] >> 10) + 4 )
              goto LABEL_61;
          }
          v43 = v108;
          while ( v109 != 0 )
          {
            --v109;
            v44 = v5;
            v5 += 8;
            a3 = 0;
            v42 |= *v43++ << v44;
            v108 = v43;
            if ( v5 >= 3 )
              goto LABEL_60;
          }
          goto LABEL_108;
        }
LABEL_61:
        if ( a1[2] < 0x13u )
        {
          do
          {
            *(_DWORD *)(a1[3] + 4 * dword_10063D00[a1[2]]) = 0;
            v47 = a1[2] + 1;
            a1[2] = v47;
          }
          while ( v47 < 0x13 );
        }
        v104 = a1[9];
        v103 = a1[3];
        a1[4] = 7;
        v111 = inflate_trees_bits(a1: v103, a2: a1 + 4, a3: a1 + 5, a4: v104, a5: v40);
        if ( v111 != 0 )
        {
          ((void (__cdecl *)(int, _DWORD))v40[9])(a1: v40[10], a2: a1[3]);
          v91 = v111 == -3;
LABEL_113:
          if ( v91 )
            *a1 = 9;
          a1[8] = v42;
          a1[7] = v5;
          v94 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          v95 = v40[2];
          *v40 = (int)v108;
          v40[2] = v108 - v94 + v95;
          v107 = v111;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3: v107);
        }
        a1[2] = 0;
        *a1 = 5;
LABEL_66:
        v48 = v108;
        if ( a1[2] < ((a1[1] >> 5) & 0x1F) + (a1[1] & 0x1Fu) + 258 )
        {
          while ( 1 )
          {
            v49 = a1[4];
            if ( v5 < v49 )
              break;
LABEL_72:
            v52 = a1[5] + 8 * (v42 & inflate_mask[v49]);
            v53 = *(unsigned __int8 *)(v52 + 1);
            v54 = *(_DWORD *)(v52 + 4);
            v111 = v53;
            v118 = v54;
            if ( v54 >= 0x10 )
            {
              if ( v54 == 18 )
                v112 = 7;
              else
                v112 = v54 - 14;
              v110 = 8 * (v54 == 18) + 3;
              v117 = v112 + v111;
              if ( v5 < v112 + v111 )
              {
                while ( v109 != 0 )
                {
                  v55 = v5;
                  v5 += 8;
                  --v109;
                  a3 = 0;
                  v42 |= *v48++ << v55;
                  v108 = v48;
                  if ( v5 >= v117 )
                    goto LABEL_80;
                }
                goto LABEL_108;
              }
LABEL_80:
              v56 = v42 >> v111;
              v57 = a1[1];
              v110 += v56 & inflate_mask[v112];
              v42 = v56 >> v112;
              v5 -= v111 + v112;
              v58 = a1[2];
              if ( v58 + v110 > ((v57 >> 5) & 0x1F) + (v57 & 0x1F) + 258 )
                goto LABEL_111;
              if ( v118 == 16 )
              {
                if ( v58 == 0 )
                {
LABEL_111:
                  ((void (__cdecl *)(int, _DWORD))v40[9])(a1: v40[10], a2: a1[3]);
                  *a1 = 9;
                  v40[6] = (int)aInvalidBitLeng;
                  a1[8] = v42;
                  a1[7] = v5;
                  v92 = (unsigned __int8 *)*v40;
                  v40[1] = v109;
                  v93 = v40[2];
                  *v40 = (int)v108;
                  v40[2] = v108 - v92 + v93;
                  a1[13] = v121;
                  return inflate_flush(a1, a2: v40, a3: -3);
                }
                v59 = *(_DWORD *)(a1[3] + 4 * v58 - 4);
              }
              else
              {
                v59 = 0;
              }
              do
              {
                ++v58;
                *(_DWORD *)(a1[3] + 4 * v58 - 4) = v59;
                --v110;
              }
              while ( v110 != 0 );
              a1[2] = v58;
            }
            else
            {
              v5 -= v53;
              v42 >>= v53;
              *(_DWORD *)(a1[3] + 4 * a1[2]++) = v54;
            }
            if ( a1[2] >= ((a1[1] >> 5) & 0x1F) + (a1[1] & 0x1Fu) + 258 )
              goto LABEL_88;
            v48 = v108;
          }
          while ( v109 != 0 )
          {
            v50 = v5;
            v5 += 8;
            --v109;
            a3 = 0;
            v51 = *v48 << v50;
            v49 = a1[4];
            v42 |= v51;
            v108 = ++v48;
            if ( v5 >= v49 )
              goto LABEL_72;
          }
LABEL_108:
          a1[8] = v42;
          a1[7] = v5;
          v89 = v40[2];
          v90 = &v108[-*v40];
          *v40 = (int)v108;
          v40[2] = (int)&v90[v89];
          v40[1] = 0;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3);
        }
LABEL_88:
        v60 = a1[1];
        v105 = a1[9];
        v102 = a1[3];
        a1[5] = 0;
        v110 = 9;
        v112 = 6;
        v61 = inflate_trees_dynamic(
                a1: (v60 & 0x1F) + 257,
                a2: ((v60 >> 5) & 0x1F) + 1,
                a3: v102,
                a4: &v110,
                a5: &v112,
                a6: &v120,
                a7: &v119,
                a8: v105,
                a9: v40);
        v62 = a1[3];
        v111 = v61;
        ((void (__cdecl *)(int, int))v40[9])(a1: v40[10], a2: v62);
        if ( v111 != 0 )
        {
          v91 = v111 == -3;
          goto LABEL_113;
        }
        v63 = inflate_codes_new(a1: v110, a2: v112, a3: v120, a4: v119, a5: v40);
        if ( v63 == 0 )
        {
          a1[8] = v42;
          a1[7] = v5;
          v96 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          v40[2] += v108 - v96;
          *v40 = (int)v108;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3: -4);
        }
        a1[1] = v63;
        *a1 = 6;
LABEL_92:
        a1[8] = v42;
        a1[7] = v5;
        v64 = (unsigned __int8 *)*v40;
        v40[1] = v109;
        v65 = v40[2];
        *v40 = (int)v108;
        v40[2] = v108 - v64 + v65;
        a1[13] = v121;
        v66 = inflate_codes(a1, a2: v40, a3);
        if ( v66 != 1 )
          return inflate_flush(a1, a2: v40, a3: v66);
        a3 = 0;
        inflate_codes_free(a1: a1[1], a2: v40);
        v67 = (char *)a1[13];
        v68 = (unsigned __int8 *)*v40;
        v69 = v40[1];
        v5 = a1[7];
        v110 = a1[8];
        v70 = a1[12];
        v108 = v68;
        v109 = v69;
        v121 = v67;
        if ( (unsigned int)v67 >= v70 )
          v71 = a1[11] - (_DWORD)v67;
        else
          v71 = v70 - (_DWORD)v67 - 1;
        v111 = v71;
        if ( a1[6] == 0 )
        {
          *a1 = 0;
          continue;
        }
        *a1 = 7;
LABEL_119:
        a1[13] = v67;
        v66 = inflate_flush(a1, a2: v40, a3);
        v97 = (char *)a1[13];
        if ( (char *)a1[12] != v97 )
        {
          v98 = v110;
          a1[7] = v5;
          a1[8] = v98;
          v99 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          *v40 = (int)v68;
          v40[2] += v68 - v99;
          a1[13] = v97;
          return inflate_flush(a1, a2: v40, a3: v66);
        }
        *a1 = 8;
LABEL_124:
        a1[8] = v110;
        a1[7] = v5;
        v100 = (unsigned __int8 *)*v40;
        v40[1] = v109;
        v40[2] += v68 - v100;
        *v40 = (int)v68;
        a1[13] = v97;
        return inflate_flush(a1, a2: v40, a3: 1);
      case 4:
        v42 = v110;
        v40 = a2;
        goto LABEL_55;
      case 5:
        v42 = v110;
        v40 = a2;
        goto LABEL_66;
      case 6:
        v42 = v110;
        v40 = a2;
        goto LABEL_92;
      case 7:
        v67 = v121;
        v68 = v108;
        v40 = a2;
        goto LABEL_119;
      case 8:
        v97 = v121;
        v68 = v108;
        v40 = a2;
        goto LABEL_124;
      case 9:
        v75 = (unsigned __int8 **)a2;
        a1[8] = v110;
        a1[7] = v5;
        a2[1] = v109;
        v106 = -3;
        goto LABEL_128;
      default:
        v75 = (unsigned __int8 **)a2;
        a1[8] = v110;
        v106 = -2;
        goto LABEL_127;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B3B0
// Name: _inflate_blocks_free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks_free(_DWORD *a1, int a2)
{
  inflate_blocks_reset(a1, a2, a3: nullptr);
  (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[10]);
  (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[9]);
  (*(void (__cdecl **)(_DWORD, _DWORD *))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003B3F0
// Name: _inflate_codes_new
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes_new(char a1, char a2, int a3, int a4, int a5)
{
  int result; // eax

  result = (*(int (__cdecl **)(_DWORD, int, int))(a5 + 32))(a1: *(_DWORD *)(a5 + 40), a2: 1, a3: 28);
  if ( result != 0 )
  {
    *(_BYTE *)(result + 16) = a1;
    *(_BYTE *)(result + 17) = a2;
    *(_DWORD *)result = 0;
    *(_DWORD *)(result + 20) = a3;
    *(_DWORD *)(result + 24) = a4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003B430
// Name: _inflate_codes
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes(_DWORD *a1, unsigned __int8 **a2, int a3)
{
  _DWORD *v5; // eax
  unsigned __int8 *v6; // ebp
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  _BYTE *v9; // edx
  int v10; // ecx
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  bool v16; // zf
  int v17; // ecx
  unsigned int v18; // eax
  char v19; // cl
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  unsigned int v24; // eax
  char v25; // cl
  int v26; // ecx
  int v27; // ecx
  unsigned int v28; // eax
  char v29; // cl
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  unsigned int v33; // eax
  char v34; // cl
  int v35; // ecx
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  int v40; // eax
  unsigned int v41; // eax
  int v42; // ecx
  unsigned int v43; // ecx
  int v44; // eax
  int v45; // ecx
  unsigned int v46; // eax
  unsigned int v47; // ecx
  int v48; // eax
  int v49; // eax
  unsigned int v50; // eax
  int v51; // ecx
  unsigned int v52; // ecx
  int v53; // eax
  unsigned __int8 *v54; // eax
  unsigned __int8 *v55; // ecx
  unsigned __int8 *v57; // ebx
  int v58; // eax
  unsigned __int8 *v59; // ebx
  unsigned __int8 *v60; // ebx
  unsigned __int8 *v61; // ebx
  int v62; // [esp-4h] [ebp-24h]
  _DWORD *v63; // [esp+10h] [ebp-10h]
  unsigned int v64; // [esp+14h] [ebp-Ch]
  unsigned int i; // [esp+18h] [ebp-8h]
  unsigned __int8 *v66; // [esp+18h] [ebp-8h]
  unsigned int j; // [esp+18h] [ebp-8h]
  unsigned int v68; // [esp+18h] [ebp-8h]
  unsigned int k; // [esp+18h] [ebp-8h]
  _BYTE *v70; // [esp+1Ch] [ebp-4h]
  unsigned int v71; // [esp+24h] [ebp+4h]
  unsigned int v72; // [esp+28h] [ebp+8h]
  int v73; // [esp+2Ch] [ebp+Ch]

  v5 = (_DWORD *)a1[1];
  v6 = *a2;
  v7 = a1[7];
  v72 = (unsigned int)a2[1];
  v8 = a1[12];
  v71 = a1[8];
  v9 = (_BYTE *)a1[13];
  v63 = v5;
  if ( (unsigned int)v9 >= v8 )
    v10 = a1[11] - (_DWORD)v9;
  else
    v10 = v8 - (_DWORD)v9 - 1;
LABEL_4:
  v64 = v10;
  while ( 2 )
  {
    switch ( *v5 )
    {
      case 0:
        if ( v64 >= 0x102 && v72 >= 0xA )
        {
          a1[8] = v71;
          a1[7] = v7;
          v11 = *a2;
          a2[1] = (unsigned __int8 *)v72;
          v12 = a2[2];
          *a2 = v6;
          a2[2] = &v12[v6 - v11];
          a1[13] = v9;
          v13 = inflate_fast(
                  a1: *((unsigned __int8 *)v63 + 16),
                  a2: *((unsigned __int8 *)v63 + 17),
                  a3: v63[5],
                  a4: v63[6],
                  a5: a1,
                  a6: a2);
          v6 = *a2;
          v7 = a1[7];
          v72 = (unsigned int)a2[1];
          v14 = a1[12];
          v71 = a1[8];
          v9 = (_BYTE *)a1[13];
          a3 = v13;
          v15 = (unsigned int)v9 >= v14 ? a1[11] - (_DWORD)v9 : v14 - (_DWORD)v9 - 1;
          v64 = v15;
          if ( v13 != 0 )
          {
            v16 = v13 == 1;
            v5 = v63;
            *v63 = 2 * !v16 + 7;
            continue;
          }
        }
        v5 = v63;
        v17 = *((unsigned __int8 *)v63 + 16);
        *v63 = 1;
        v63[3] = v17;
        v63[2] = v63[5];
        goto LABEL_14;
      case 1:
LABEL_14:
        v18 = v5[3];
        for ( i = v18; v7 < i; v71 = v20 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v19 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v20 = (*v6 << v19) | v71;
          v18 = i;
          ++v6;
        }
        v66 = (unsigned __int8 *)(v63[2] + 8 * (v71 & inflate_mask[v18]));
        v21 = v66[1];
        v71 >>= v21;
        v7 -= v21;
        v22 = *v66;
        if ( *v66 != 0 )
        {
          if ( (v22 & 0x10) != 0 )
          {
            v5 = v63;
            v63[2] = v22 & 0xF;
            v23 = *((_DWORD *)v66 + 1);
            *v63 = 2;
            v63[1] = v23;
          }
          else
          {
            if ( (v22 & 0x40) == 0 )
              goto LABEL_22;
            v5 = v63;
            if ( (v22 & 0x20) == 0 )
            {
              *v63 = 9;
              a2[6] = (unsigned __int8 *)aInvalidLiteral;
              v62 = -3;
LABEL_96:
              a1[7] = v7;
              a1[8] = v71;
              v61 = *a2;
              a2[1] = (unsigned __int8 *)v72;
              a2[2] += v6 - v61;
LABEL_97:
              *a2 = v6;
              a1[13] = v9;
              return inflate_flush(a1, a2, a3: v62);
            }
            *v63 = 7;
          }
        }
        else
        {
          v5 = v63;
          v63[2] = *((_DWORD *)v66 + 1);
          *v63 = 6;
        }
        continue;
      case 2:
        v24 = v5[2];
        for ( j = v24; v7 < j; v71 = v26 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v25 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v26 = (*v6 << v25) | v71;
          v24 = j;
          ++v6;
        }
        v63[1] += v71 & inflate_mask[v24];
        v71 >>= j;
        v7 -= j;
        v5 = v63;
        v27 = *((unsigned __int8 *)v63 + 17);
        *v63 = 3;
        v63[3] = v27;
        v63[2] = v63[6];
LABEL_29:
        v28 = v5[3];
        v68 = v28;
        if ( v7 >= v28 )
        {
LABEL_32:
          v66 = (unsigned __int8 *)(v63[2] + 8 * (v71 & inflate_mask[v28]));
          v31 = v66[1];
          v7 -= v31;
          v71 >>= v31;
          v22 = *v66;
          if ( (v22 & 0x10) != 0 )
          {
            v5 = v63;
            v63[2] = v22 & 0xF;
            v32 = *((_DWORD *)v66 + 1);
            *v63 = 4;
            v63[3] = v32;
          }
          else
          {
            if ( (v22 & 0x40) != 0 )
            {
              v62 = -3;
              *v63 = 9;
              a2[6] = (unsigned __int8 *)aInvalidDistanc;
              goto LABEL_96;
            }
LABEL_22:
            v63[3] = v22;
            v5 = v63;
            v63[2] = &v66[8 * *((_DWORD *)v66 + 1)];
          }
          continue;
        }
        while ( v72 != 0 )
        {
          v29 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v30 = (*v6 << v29) | v71;
          v28 = v68;
          ++v6;
          v71 = v30;
          if ( v7 >= v68 )
            goto LABEL_32;
        }
LABEL_86:
        a1[7] = v7;
        a1[8] = v71;
        v54 = a2[2];
        v55 = (unsigned __int8 *)(v6 - *a2);
        a2[1] = nullptr;
        *a2 = v6;
        a2[2] = &v54[(_DWORD)v55];
        a1[13] = v9;
        return inflate_flush(a1, a2, a3);
      case 3:
        goto LABEL_29;
      case 4:
        v33 = v5[2];
        for ( k = v33; v7 < k; v71 = v35 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v34 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v35 = (*v6 << v34) | v71;
          v33 = k;
          ++v6;
        }
        v63[3] += v71 & inflate_mask[v33];
        v71 >>= k;
        v7 -= k;
        *v63 = 5;
LABEL_40:
        v36 = v63[3];
        if ( (unsigned int)&v9[-a1[10]] >= v36 )
          v70 = &v9[-v36];
        else
          v70 = &v9[a1[11] - a1[10] - v63[3]];
        v5 = v63;
        if ( v63[1] != 0 )
        {
          do
          {
            if ( v64 == 0 )
            {
              if ( v9 != (_BYTE *)a1[11]
                || (v37 = a1[12], v38 = a1[10], v37 == v38)
                || ((v9 = (_BYTE *)a1[10], v38 >= v37) ? (v39 = a1[11] - v38) : (v39 = v37 - v38 - 1),
                    v64 = v39,
                    v39 == 0) )
              {
                a1[13] = v9;
                v40 = inflate_flush(a1, a2, a3);
                v9 = (_BYTE *)a1[13];
                v73 = v40;
                v41 = a1[12];
                if ( (unsigned int)v9 >= v41 )
                  v42 = a1[11] - (_DWORD)v9;
                else
                  v42 = v41 - (_DWORD)v9 - 1;
                v64 = v42;
                if ( v9 == (_BYTE *)a1[11] )
                {
                  v43 = a1[10];
                  if ( v41 != v43 )
                  {
                    v9 = (_BYTE *)a1[10];
                    if ( v43 >= v41 )
                      v44 = a1[11] - v43;
                    else
                      v44 = v41 - v43 - 1;
                    v64 = v44;
                  }
                }
                if ( v64 == 0 )
                {
LABEL_87:
                  a1[8] = v71;
                  a1[7] = v7;
                  v57 = *a2;
                  a2[1] = (unsigned __int8 *)v72;
                  a2[2] += v6 - v57;
                  v62 = v73;
                  goto LABEL_97;
                }
              }
              v5 = v63;
            }
            ++v9;
            a3 = 0;
            *(v9 - 1) = *v70++;
            --v64;
            if ( v70 == (_BYTE *)a1[11] )
              v70 = (_BYTE *)a1[10];
            v45 = v5[1] - 1;
            v5[1] = v45;
          }
          while ( v45 != 0 );
        }
        *v5 = 0;
        continue;
      case 5:
        goto LABEL_40;
      case 6:
        if ( v64 != 0 )
          goto LABEL_84;
        if ( v9 != (_BYTE *)a1[11]
          || (v46 = a1[12], v47 = a1[10], v46 == v47)
          || ((v9 = (_BYTE *)a1[10], v47 >= v46) ? (v48 = a1[11] - v47) : (v48 = v46 - v47 - 1), v64 = v48, v48 == 0) )
        {
          a1[13] = v9;
          v49 = inflate_flush(a1, a2, a3);
          v9 = (_BYTE *)a1[13];
          v73 = v49;
          v50 = a1[12];
          if ( (unsigned int)v9 >= v50 )
            v51 = a1[11] - (_DWORD)v9;
          else
            v51 = v50 - (_DWORD)v9 - 1;
          v64 = v51;
          if ( v9 == (_BYTE *)a1[11] )
          {
            v52 = a1[10];
            if ( v50 != v52 )
            {
              v9 = (_BYTE *)a1[10];
              if ( v52 >= v50 )
                v53 = a1[11] - v52;
              else
                v53 = v50 - v52 - 1;
              v64 = v53;
            }
          }
          if ( v64 == 0 )
            goto LABEL_87;
        }
        v5 = v63;
LABEL_84:
        a3 = 0;
        *v9++ = *((_BYTE *)v5 + 8);
        v10 = v64 - 1;
        *v5 = 0;
        goto LABEL_4;
      case 7:
        if ( v7 > 7 )
        {
          v7 -= 8;
          --v6;
          ++v72;
        }
        a1[13] = v9;
        v58 = inflate_flush(a1, a2, a3);
        v9 = (_BYTE *)a1[13];
        if ( (_BYTE *)a1[12] != v9 )
        {
          a1[7] = v7;
          a1[8] = v71;
          v59 = *a2;
          a2[1] = (unsigned __int8 *)v72;
          v62 = v58;
          a2[2] += v6 - v59;
          goto LABEL_97;
        }
        *v63 = 8;
LABEL_93:
        v62 = 1;
        goto LABEL_96;
      case 8:
        goto LABEL_93;
      case 9:
        a1[8] = v71;
        a1[7] = v7;
        v60 = *a2;
        a2[1] = (unsigned __int8 *)v72;
        v62 = -3;
        a2[2] += v6 - v60;
        goto LABEL_97;
      default:
        v62 = -2;
        goto LABEL_96;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BB30
// Name: _inflate_codes_free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes_free(int a1, int a2)
{
  return (*(int (__cdecl **)(_DWORD, int))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1003BB50
// Name: _inflate_trees_bits
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_bits(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // [esp-10h] [ebp-1Ch]
  int v10; // [esp+8h] [ebp-4h] BYREF

  v10 = 0;
  v5 = (*(int (__cdecl **)(_DWORD, int, int))(a5 + 32))(a1: *(_DWORD *)(a5 + 40), a2: 19, a3: 4);
  if ( v5 == 0 )
    return -4;
  v7 = sub_1003BC00(a1, a2: 19, a3: 19, a4: 0, a5: 0, a6: a3, a7: a2, a8: a4, a9: &v10, a10: v5);
  v8 = v7;
  if ( v7 == -3 )
  {
    v9 = *(_DWORD *)(a5 + 40);
    *(_DWORD *)(a5 + 24) = aOversubscribed_0;
    (*(void (__cdecl **)(int, int))(a5 + 36))(a1: v9, a2: v5);
    return -3;
  }
  else
  {
    if ( v7 == -5 || *a2 == 0 )
    {
      *(_DWORD *)(a5 + 24) = aIncompleteDyna;
      v8 = -3;
    }
    (*(void (__cdecl **)(_DWORD, int))(a5 + 36))(a1: *(_DWORD *)(a5 + 40), a2: v5);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BC00
// Name: sub_1003BC00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1003BC00(
        int *a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        int a5,
        _DWORD *a6,
        unsigned int *a7,
        int a8,
        unsigned int *a9,
        unsigned int *a10)
{
  unsigned int v10; // ebp
  int *v11; // ecx
  unsigned int v12; // edx
  int v13; // eax
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int i; // esi
  int j; // edx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  unsigned int v23; // esi
  int v24; // edi
  int *v25; // esi
  unsigned int v26; // edi
  int v27; // ecx
  int v28; // esi
  unsigned int v29; // edi
  signed int v30; // ecx
  int v31; // ebx
  unsigned int v32; // esi
  unsigned int m; // ecx
  unsigned int v34; // edx
  unsigned int v35; // ecx
  unsigned int v36; // eax
  _DWORD *v37; // ebp
  unsigned int v38; // eax
  unsigned int v39; // edi
  unsigned int v40; // eax
  unsigned int v41; // edx
  int v42; // ebp
  unsigned int v43; // eax
  int v44; // ecx
  int v45; // esi
  int v46; // edx
  unsigned int v47; // eax
  _DWORD *v48; // ecx
  unsigned int k; // eax
  int v50; // eax
  unsigned int v51; // [esp+10h] [ebp-FCh]
  signed int v52; // [esp+14h] [ebp-F8h]
  int v53; // [esp+18h] [ebp-F4h]
  int v54; // [esp+1Ch] [ebp-F0h]
  int *v55; // [esp+20h] [ebp-ECh]
  unsigned int *v56; // [esp+20h] [ebp-ECh]
  _DWORD *v57; // [esp+24h] [ebp-E8h]
  signed int v58; // [esp+28h] [ebp-E4h]
  unsigned int v59; // [esp+2Ch] [ebp-E0h]
  unsigned int v60; // [esp+30h] [ebp-DCh]
  int v61; // [esp+30h] [ebp-DCh]
  int v62; // [esp+34h] [ebp-D8h]
  unsigned int v63; // [esp+38h] [ebp-D4h]
  signed int v64; // [esp+3Ch] [ebp-D0h]
  char v65; // [esp+40h] [ebp-CCh]
  unsigned int v66; // [esp+44h] [ebp-C8h]
  _DWORD *v67; // [esp+48h] [ebp-C4h]
  int v68; // [esp+4Ch] [ebp-C0h]
  int v69; // [esp+50h] [ebp-BCh] BYREF
  _DWORD v70[15]; // [esp+54h] [ebp-B8h] BYREF
  int v71; // [esp+90h] [ebp-7Ch]
  _DWORD v72[15]; // [esp+94h] [ebp-78h]
  _DWORD v73[15]; // [esp+D0h] [ebp-3Ch] BYREF
  int v74; // [esp+114h] [ebp+8h]

  v10 = 0;
  v69 = 0;
  memset(v70, 0, sizeof(v70));
  v11 = a1;
  v12 = a2;
  do
  {
    v13 = *v11++;
    --v12;
    ++v70[v13 - 1];
  }
  while ( v12 != 0 );
  if ( v69 == a2 )
  {
    *a6 = 0;
    *a7 = 0;
    return 0;
  }
  v15 = *a7;
  v16 = 1;
  v51 = *a7;
  do
  {
    if ( v70[v16 - 1] != 0 )
      break;
    ++v16;
  }
  while ( v16 <= 0xF );
  v52 = v16;
  if ( v15 < v16 )
  {
    v51 = v16;
    v15 = v16;
  }
  for ( i = 15; i != 0; --i )
  {
    if ( v70[i - 1] != 0 )
      break;
  }
  v58 = i;
  if ( v15 > i )
  {
    v51 = i;
    v15 = i;
  }
  *a7 = v15;
  for ( j = 1 << v16; v16 < i; j = 2 * v19 )
  {
    v19 = j - v70[v16 - 1];
    if ( v19 < 0 )
      return -3;
    ++v16;
  }
  v60 = i;
  v20 = v70[i - 1];
  v21 = j - v20;
  v68 = v21;
  if ( v21 < 0 )
    return -3;
  v72[0] = 0;
  v70[i - 1] = v21 + v20;
  v22 = 0;
  v23 = i - 1;
  if ( v23 != 0 )
  {
    v24 = 0;
    do
    {
      v22 += v70[v24++];
      --v23;
      v72[v24] = v22;
    }
    while ( v23 != 0 );
  }
  v25 = a1;
  v26 = 0;
  do
  {
    v27 = *v25++;
    v55 = v25;
    if ( v27 != 0 )
    {
      v28 = v72[v27 - 1];
      a10[v28] = v26;
      v72[v27 - 1] = v28 + 1;
      v25 = v55;
    }
    ++v26;
  }
  while ( v26 < a2 );
  v29 = 0;
  v59 = 0;
  v74 = v72[v60 - 1];
  v56 = a10;
  v30 = v52;
  v31 = -v15;
  v71 = 0;
  v53 = -1;
  v73[0] = 0;
  v61 = 0;
  if ( v52 > v58 )
  {
LABEL_66:
    if ( v21 == 0 || v58 == 1 )
      return 0;
    return -5;
  }
  else
  {
    v32 = v63;
    v65 = v52 - 1;
    v57 = &v70[v52 - 1];
    while ( 1 )
    {
      v54 = *v57;
      if ( *v57 != 0 )
        break;
LABEL_64:
      v52 = ++v30;
      ++v57;
      ++v65;
      if ( v30 > v58 )
      {
        v21 = v68;
        goto LABEL_66;
      }
    }
    while ( 1 )
    {
      --v54;
      if ( v52 > (int)(v31 + v15) )
        break;
LABEL_47:
      if ( v56 < &a10[v74] )
      {
        v32 = *v56;
        if ( *v56 >= a3 )
        {
          v45 = 4 * (v32 - a3);
          LOBYTE(v62) = *(_BYTE *)(v45 + a5) + 80;
          v32 = *(_DWORD *)(v45 + a4);
        }
        else
        {
          LOBYTE(v62) = v32 < 0x100 ? 0 : 96;
        }
        ++v56;
      }
      else
      {
        LOBYTE(v62) = -64;
      }
      v46 = 1 << (v52 - v31);
      v47 = v10 >> v31;
      if ( v10 >> v31 < v29 )
      {
        v48 = (_DWORD *)(v61 + 8 * v47);
        do
        {
          v48[1] = v32;
          BYTE1(v62) = v52 - v31;
          *v48 = v62;
          v47 += v46;
          v48 += 2 * v46;
        }
        while ( v47 < v29 );
        v10 = v59;
      }
      for ( k = 1 << v65; (k & v10) != 0; k >>= 1 )
        v10 ^= k;
      v10 ^= k;
      v50 = v53;
      v59 = v10;
      if ( (v10 & ((1 << v31) - 1)) != v72[v53 - 1] )
      {
        do
        {
          --v50;
          v31 -= v51;
        }
        while ( (v10 & ((1 << v31) - 1)) != v72[v50 - 1] );
        v53 = v50;
      }
      v15 = v51;
      if ( v54 == 0 )
      {
        v30 = v52;
        goto LABEL_64;
      }
    }
    v64 = v31 + v15;
    for ( m = v31 - v15; ; m = v66 )
    {
      v31 += v15;
      ++v53;
      v34 = v58 - v31;
      v66 = v15 + m;
      v64 += v15;
      if ( v58 - v31 > v15 )
        v34 = v15;
      v35 = v52 - v31;
      v36 = 1 << (v52 - v31);
      if ( v36 > v54 + 1 )
      {
        v37 = v57;
        v38 = -1 - v54 + v36;
        if ( v35 < v34 && ++v35 < v34 )
        {
          do
          {
            v39 = v37[1];
            ++v37;
            v40 = 2 * v38;
            if ( v40 <= v39 )
              break;
            v38 = v40 - v39;
            ++v35;
          }
          while ( v35 < v34 );
        }
      }
      v29 = 1 << v35;
      v41 = *a9 + (1 << v35);
      if ( v41 > 0x5A0 )
        break;
      v42 = a8 + 8 * *a9;
      v61 = v42;
      v67 = &v73[v53];
      *v67 = v42;
      *a9 = v41;
      if ( v53 != 0 )
      {
        LOBYTE(v62) = v35;
        v72[v53 - 1] = v59;
        v43 = v59 >> v66;
        BYTE1(v62) = v51;
        v44 = *(v67 - 1);
        v32 = ((v42 - v44) >> 3) - (v59 >> v66);
        *(_DWORD *)(v44 + 8 * v43) = v62;
        *(_DWORD *)(v44 + 8 * v43 + 4) = v32;
      }
      else
      {
        *a6 = v42;
      }
      if ( v52 <= v64 )
      {
        v10 = v59;
        goto LABEL_47;
      }
      v15 = v51;
    }
    return -4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C0B0
// Name: _inflate_trees_dynamic
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_dynamic(
        unsigned int a1,
        unsigned int a2,
        int *a3,
        unsigned int *a4,
        unsigned int *a5,
        _DWORD *a6,
        _DWORD *a7,
        int a8,
        int a9)
{
  unsigned int *v9; // edi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // [esp-Ch] [ebp-20h]
  int v15; // [esp-8h] [ebp-1Ch]
  int v16; // [esp-8h] [ebp-1Ch]
  int v17; // [esp-8h] [ebp-1Ch]
  unsigned int v18; // [esp+10h] [ebp-4h] BYREF

  v14 = *(_DWORD *)(a9 + 40);
  v18 = 0;
  v9 = (unsigned int *)(*(int (__cdecl **)(int, int, int))(a9 + 32))(a1: v14, a2: 288, a3: 4);
  if ( v9 == nullptr )
    return -4;
  v11 = sub_1003BC00(
          a1: a3,
          a2: a1,
          a3: 0x101u,
          a4: (int)&unk_10063D80,
          a5: (int)&unk_10063E00,
          a6,
          a7: a4,
          a8,
          a9: &v18,
          a10: v9);
  v12 = v11;
  if ( v11 != 0 )
  {
    if ( v11 == -3 )
    {
      v17 = *(_DWORD *)(a9 + 40);
      *(_DWORD *)(a9 + 24) = aOversubscribed_1;
      (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v17, a2: v9);
      return -3;
    }
    if ( v11 == -4 )
      goto LABEL_20;
LABEL_19:
    *(_DWORD *)(a9 + 24) = aIncompleteLite;
    v12 = -3;
    goto LABEL_20;
  }
  if ( *a4 == 0 )
    goto LABEL_19;
  v13 = sub_1003BC00(
          a1: &a3[a1],
          a2,
          a3: 0,
          a4: (int)&unk_10063E80,
          a5: (int)&unk_10063EF8,
          a6: a7,
          a7: a5,
          a8,
          a9: &v18,
          a10: v9);
  v12 = v13;
  if ( v13 != 0 )
  {
    switch ( v13 )
    {
      case -3:
        v15 = *(_DWORD *)(a9 + 40);
        *(_DWORD *)(a9 + 24) = aOversubscribed;
        (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v15, a2: v9);
        return -3;
      case -5:
        v16 = *(_DWORD *)(a9 + 40);
        *(_DWORD *)(a9 + 24) = aIncompleteDist;
        (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v16, a2: v9);
        return -3;
      case -4:
        goto LABEL_20;
      default:
        break;
    }
  }
  else if ( *a5 != 0 || a1 <= 0x101 )
  {
    (*(void (__cdecl **)(_DWORD, unsigned int *))(a9 + 36))(a1: *(_DWORD *)(a9 + 40), a2: v9);
    return 0;
  }
  *(_DWORD *)(a9 + 24) = aEmptyDistanceT;
  v12 = -3;
LABEL_20:
  (*(void (__cdecl **)(_DWORD, unsigned int *))(a9 + 36))(a1: *(_DWORD *)(a9 + 40), a2: v9);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1003C240
// Name: _inflate_trees_fixed
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_fixed(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  *a1 = dword_10088998;
  *a2 = dword_1008899C;
  *a3 = &unk_100889A0;
  *a4 = &unk_100899A0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003C270
// Name: _inflate_flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_flush(_DWORD *a1, _DWORD *a2, int a3)
{
  unsigned int v3; // ebp
  char *v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // edx
  int (__cdecl *v8)(_DWORD, char *, unsigned int); // eax
  int v9; // eax
  char *v10; // eax
  char *v11; // ecx
  char *v12; // esi
  unsigned int v13; // ebp
  unsigned int v14; // eax
  unsigned int v15; // edx
  int (__cdecl *v16)(_DWORD, char *, unsigned int); // eax
  int v17; // eax
  char *v18; // edi
  char *v20; // [esp+10h] [ebp-4h]
  char *v21; // [esp+10h] [ebp-4h]

  v3 = a1[13];
  v4 = (char *)a1[12];
  v20 = (char *)a2[3];
  if ( (unsigned int)v4 > v3 )
    v3 = a1[11];
  v5 = a2[4];
  v6 = v3 - (_DWORD)v4;
  if ( v6 > v5 )
    v6 = a2[4];
  if ( v6 != 0 && a3 == -5 )
    a3 = 0;
  v7 = v6 + a2[5];
  a2[4] = v5 - v6;
  a2[5] = v7;
  v8 = (int (__cdecl *)(_DWORD, char *, unsigned int))a1[14];
  if ( v8 != nullptr )
  {
    v9 = v8(a1: a1[15], a2: v4, a3: v6);
    a1[15] = v9;
    a2[12] = v9;
  }
  qmemcpy(v20, v4, v6);
  v10 = &v4[v6];
  v11 = (char *)a1[11];
  v21 = &v20[v6];
  if ( &v4[v6] == v11 )
  {
    v12 = (char *)a1[10];
    if ( (char *)a1[13] == v11 )
      a1[13] = v12;
    v13 = a1[13] - (_DWORD)v12;
    v14 = a2[4];
    if ( v13 > v14 )
      v13 = a2[4];
    if ( v13 != 0 && a3 == -5 )
      a3 = 0;
    v15 = v13 + a2[5];
    a2[4] = v14 - v13;
    a2[5] = v15;
    v16 = (int (__cdecl *)(_DWORD, char *, unsigned int))a1[14];
    if ( v16 != nullptr )
    {
      v17 = v16(a1: a1[15], a2: v12, a3: v13);
      a1[15] = v17;
      a2[12] = v17;
    }
    qmemcpy(v21, v12, 4 * (v13 >> 2));
    v18 = &v21[4 * (v13 >> 2)];
    v21 += v13;
    v10 = &v12[v13];
    qmemcpy(v18, &v12[4 * (v13 >> 2)], v13 & 3);
  }
  a2[3] = v21;
  a1[12] = v10;
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x1003C3B0
// Name: _inflate_fast
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_fast(int a1, int a2, int a3, unsigned __int8 *a4, _DWORD *a5, unsigned __int8 **a6)
{
  _BYTE *v6; // ebx
  unsigned int v7; // esi
  unsigned int v8; // edx
  unsigned __int8 **v9; // edi
  unsigned __int8 *v10; // ebp
  unsigned int v11; // eax
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // ebx
  int v19; // esi
  unsigned __int8 *v20; // esi
  int i; // ecx
  int v22; // ecx
  int v23; // ebx
  unsigned int j; // ebx
  char v25; // cl
  unsigned int v26; // edi
  int v27; // esi
  _BYTE *v28; // ecx
  _BYTE *v29; // esi
  unsigned int v30; // edi
  unsigned int v31; // ecx
  unsigned __int8 *v32; // ebp
  unsigned __int8 *v33; // edx
  int v34; // ecx
  unsigned int v36; // ecx
  unsigned __int8 *v37; // ebp
  unsigned __int8 *v38; // edx
  unsigned __int8 *v39; // ecx
  unsigned int v40; // ecx
  unsigned __int8 *v41; // ebp
  unsigned __int8 *v42; // edx
  unsigned __int8 *v43; // ecx
  unsigned int v44; // [esp+10h] [ebp-14h]
  _BYTE *v45; // [esp+14h] [ebp-10h]
  unsigned int v46; // [esp+18h] [ebp-Ch]
  int v47; // [esp+1Ch] [ebp-8h]
  int v48; // [esp+20h] [ebp-4h]
  unsigned int v49; // [esp+28h] [ebp+4h]

  v6 = (_BYTE *)a5[13];
  v7 = a5[12];
  v8 = a5[8];
  v9 = a6;
  v45 = v6;
  v10 = *a6;
  v44 = (unsigned int)a6[1];
  v11 = a5[7];
  if ( (unsigned int)v6 >= v7 )
    v46 = a5[11] - (_DWORD)v6;
  else
    v46 = v7 - (_DWORD)v6 - 1;
  v47 = inflate_mask[a1];
  v48 = inflate_mask[a2];
  do
  {
    for ( ; v11 < 0x14; ++v10 )
    {
      --v44;
      v12 = *v10 << v11;
      v11 += 8;
      v8 |= v12;
    }
    v13 = *(unsigned __int8 *)(a3 + 8 * (v8 & v47));
    v14 = a3 + 8 * (v8 & v47);
    if ( *(_BYTE *)v14 != 0 )
    {
      while ( 1 )
      {
        v15 = *(unsigned __int8 *)(v14 + 1);
        v8 >>= v15;
        v11 -= v15;
        if ( (v13 & 0x10) != 0 )
          break;
        if ( (v13 & 0x40) != 0 )
        {
          if ( (v13 & 0x20) != 0 )
          {
            v36 = (unsigned int)&v9[1][-v44];
            if ( v11 >> 3 < v36 )
              v36 = v11 >> 3;
            v37 = &v10[-v36];
            a5[8] = v8;
            a5[7] = v11 - 8 * v36;
            v38 = *v9;
            v9[1] = (unsigned __int8 *)(v44 + v36);
            v39 = v9[2];
            *v9 = v37;
            v9[2] = &v39[v37 - v38];
            a5[13] = v45;
            return 1;
          }
          else
          {
            v9[6] = (unsigned __int8 *)aInvalidLiteral;
LABEL_40:
            v40 = (unsigned int)&v9[1][-v44];
            if ( v11 >> 3 < v40 )
              v40 = v11 >> 3;
            v41 = &v10[-v40];
            a5[8] = v8;
            a5[7] = v11 - 8 * v40;
            v42 = *v9;
            v9[1] = (unsigned __int8 *)(v44 + v40);
            v43 = v9[2];
            *v9 = v41;
            v9[2] = &v43[v41 - v42];
            a5[13] = v45;
            return -3;
          }
        }
        v16 = *(_DWORD *)(v14 + 4) + (v8 & inflate_mask[v13]);
        v13 = *(unsigned __int8 *)(v14 + 8 * v16);
        v14 += 8 * v16;
        if ( v13 == 0 )
          goto LABEL_11;
      }
      v18 = v13 & 0xF;
      v11 -= v18;
      v49 = *(_DWORD *)(v14 + 4) + (v8 & inflate_mask[v18]);
      for ( v8 >>= v18; v11 < 0xF; ++v10 )
      {
        --v44;
        v19 = *v10 << v11;
        v11 += 8;
        v8 |= v19;
      }
      v20 = a4;
      for ( i = v8 & v48; ; i = *((_DWORD *)v20 + 1) + (v8 & inflate_mask[v23]) )
      {
        v20 += 8 * i;
        v22 = v20[1];
        v23 = *v20;
        v8 >>= v22;
        v11 -= v22;
        if ( (v23 & 0x10) != 0 )
          break;
        if ( (v23 & 0x40) != 0 )
        {
          v9[6] = (unsigned __int8 *)aInvalidDistanc;
          goto LABEL_40;
        }
      }
      for ( j = v23 & 0xF; v11 < j; ++v10 )
      {
        --v44;
        v25 = v11;
        v11 += 8;
        v8 |= *v10 << v25;
      }
      v26 = *((_DWORD *)v20 + 1) + (v8 & inflate_mask[j]);
      v8 >>= j;
      v11 -= j;
      v46 -= v49;
      v27 = a5[10];
      v28 = v45;
      if ( (unsigned int)&v45[-v27] < v26 )
      {
        v30 = v26 + v27 - (_DWORD)v45;
        v29 = (_BYTE *)(a5[11] - v30);
        if ( v49 > v30 )
        {
          v49 -= v30;
          do
          {
            *v28++ = *v29++;
            --v30;
          }
          while ( v30 != 0 );
          v29 = (_BYTE *)a5[10];
        }
      }
      else
      {
        *v45 = v45[-v26];
        v28 = v45 + 2;
        v29 = &v45[-v26 + 2];
        v45[1] = v45[-v26 + 1];
        v49 -= 2;
      }
      do
      {
        *v28++ = *v29++;
        --v49;
      }
      while ( v49 != 0 );
      v9 = a6;
      v45 = v28;
    }
    else
    {
LABEL_11:
      v17 = *(unsigned __int8 *)(v14 + 1);
      v11 -= v17;
      v8 >>= v17;
      *v45++ = *(_BYTE *)(v14 + 4);
      --v46;
    }
  }
  while ( v46 >= 0x102 && v44 >= 0xA );
  v31 = (unsigned int)&v9[1][-v44];
  if ( v11 >> 3 < v31 )
    v31 = v11 >> 3;
  v32 = &v10[-v31];
  a5[8] = v8;
  a5[7] = v11 - 8 * v31;
  v33 = *v9;
  v9[1] = (unsigned __int8 *)(v44 + v31);
  v34 = (int)&v9[2][v32 - v33];
  *v9 = v32;
  v9[2] = (unsigned __int8 *)v34;
  a5[13] = v45;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003C710
// Name: void __near * operator new[](unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new[](unsigned int count)
{
  return operator new(size: count);
}

//------------------------------------------------------------------------------
// Address: 0x1003C720
// Name: _ceil
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x1003C760
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns, (__m128i)_mm_and_pd(v2, *(__m128d *)&S));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      a1.m128i_i64[0] = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One);
      return *(double *)a1.m128i_i64;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C8C0
// Name: _floor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl floor(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _floor_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _floor_pentium4(X);
  else
    return _floor_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x1003C900
// Name: __floor_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _floor_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns_0, (__m128i)_mm_and_pd(v2, *(__m128d *)&S_0));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmplt_pd(v9, v8).m128d_f64[0];
    if ( v3 < 3071 )
    {
      a1.m128i_i64[0] = (*(_QWORD *)&_mm_cmplt_pd(v9, *(__m128d *)&NegZero_0).m128d_f64[0] | NegZero_0) & NegOne;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 3122 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] - COERCE_DOUBLE(*(_QWORD *)&v10 & One_0);
      return *(double *)a1.m128i_i64;
    }
  }
  else
  {
    if ( v3 >= 1023 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 1074 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C9E1
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003CA68
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  number = 0;
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / ibase;
  pctype = locinfo->pctype;
  v16 = 0xFFFFFFFF % ibase;
  while ( 1 )
  {
    if ( (pctype[v7] & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (pctype[v7] & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v12 <= v16 )
    {
      number = v12 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v14 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v14;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x1003CC93
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003CCBE
// Name: _strtoul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoul(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 1);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1003CCF0
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 *value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = (_BYTE)value;
    if ( (_BYTE)value != 0 || count < 0x80 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = (unsigned __int8)value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero((void *)dst, val: (int)value, len: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CD6A
// Name: _free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl free(void *pBlock)
{
  int *v1; // esi
  DWORD LastError; // eax

  if ( pBlock != nullptr && !HeapFree(hHeap: _crtheap, dwFlags: 0, lpMem: pBlock) )
  {
    v1 = _errno();
    LastError = GetLastError();
    *v1 = _get_errno_from_oserr(oserrno: LastError);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CDA4
// Name: _malloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __cdecl malloc(unsigned int size)
{
  SIZE_T v1; // eax
  LPVOID v2; // edi

  if ( size > 0xFFFFFFE0 )
  {
    _callnewh(size);
    *_errno() = 12;
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      if ( _crtheap == nullptr )
      {
        _FF_MSGBANNER();
        _NMSG_WRITE(rterrnum: 30);
        __crtExitProcess(status: 255);
      }
      v1 = size != 0 ? size : 1;
      v2 = HeapAlloc(hHeap: _crtheap, dwFlags: 0, dwBytes: v1);
      if ( v2 != nullptr )
        return v2;
      if ( _newmode == 0 )
      {
        *_errno() = 12;
LABEL_12:
        *_errno() = 12;
        return v2;
      }
      if ( _callnewh(size) == 0 )
        goto LABEL_12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CE38
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(const char *nptr, localeinfo_struct *plocinfo)
{
  const char *v2; // esi
  long double result; // st7
  int v4; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v2] & 8
         : _isctype_l(c: *(unsigned __int8 *)v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    result = _fltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003CEE3
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(const char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003CEF6
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x1003CF0C
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003CF17
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    strlen(buf: (unsigned __int8 *)string);
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      str._cnt = v6;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CF85
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(string, inputfn: _input_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x1003D010
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x1003D040
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 1003D099 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D3A1
// Name: void operator delete[](void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl operator delete[](void *p)
{
  operator delete(p);
}

//------------------------------------------------------------------------------
// Address: 0x1003D3B0
// Name: shortsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shortsort(
        char *hi@<eax>,
        char *lo,
        unsigned int width,
        int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edx
  char *v5; // edi
  unsigned int v6; // ecx
  char *v7; // esi
  char *v8; // ebx
  unsigned int v9; // esi
  char *v10; // eax
  int v11; // ecx
  char v12; // dl

  v4 = lo;
  v5 = hi;
  if ( hi > lo )
  {
    v6 = width;
    do
    {
      v7 = &lo[width];
      v8 = v4;
      if ( &lo[width] <= v5 )
      {
        do
        {
          if ( comp(a1: v7, a2: v8) > 0 )
            v8 = v7;
          v7 += width;
        }
        while ( v7 <= v5 );
        v6 = width;
        v4 = lo;
      }
      v9 = v6;
      v10 = v5;
      if ( v8 != v5 && v6 != 0 )
      {
        v11 = v8 - v5;
        do
        {
          v12 = v10[v11];
          v10[v11] = *v10;
          *v10++ = v12;
          --v9;
        }
        while ( v9 != 0 );
        v6 = width;
        v4 = lo;
      }
      v5 -= v6;
    }
    while ( v5 > v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D440
// Name: _qsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl qsort(char *base, unsigned int num, unsigned int width, int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edi
  unsigned int v5; // ebx
  char *v6; // esi
  unsigned int v7; // eax
  char *v8; // ebx
  unsigned int v9; // edx
  char *v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  char *v13; // eax
  int v14; // edi
  unsigned int v15; // ecx
  char *v16; // eax
  int v17; // edi
  unsigned int v18; // edx
  char *v19; // eax
  int v20; // ecx
  char *v21; // eax
  char *v22; // edx
  int v23; // ecx
  int v24; // ecx
  int v25; // eax
  char *v26; // edx
  char *v27; // eax
  char *histk[30]; // [esp+8h] [ebp-100h]
  char *lostk[30]; // [esp+80h] [ebp-88h]
  unsigned int v30; // [esp+F8h] [ebp-10h]
  int stkptr; // [esp+FCh] [ebp-Ch]
  char *hi; // [esp+100h] [ebp-8h]
  char *lo; // [esp+104h] [ebp-4h]
  char base_3; // [esp+113h] [ebp+Bh]
  char base_3a; // [esp+113h] [ebp+Bh]
  char base_3b; // [esp+113h] [ebp+Bh]
  char base_3c; // [esp+113h] [ebp+Bh]

  v4 = base;
  if ( base == nullptr && num != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  v5 = width;
  if ( width == 0 || comp == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  if ( num >= 2 )
  {
    v6 = &base[width * (num - 1)];
    stkptr = 0;
    lo = base;
    hi = v6;
    while ( 1 )
    {
      v7 = (v6 - v4) / v5 + 1;
      if ( v7 <= 8 )
      {
        shortsort(hi: v6, lo: v4, width: v5, comp);
        goto LABEL_57;
      }
      v8 = &v4[(v7 >> 1) * v5];
      if ( comp(a1: v4, a2: v8) > 0 )
      {
        v9 = width;
        v10 = v8;
        if ( v4 != v8 )
        {
          v11 = v4 - v8;
          do
          {
            v30 = v9 - 1;
            base_3 = v10[v11];
            v10[v11] = *v10;
            *v10 = base_3;
            v9 = v30;
            ++v10;
          }
          while ( v30 != 0 );
        }
      }
      if ( comp(a1: v4, a2: v6) > 0 )
      {
        v12 = width;
        v13 = v6;
        if ( v4 != v6 )
        {
          v14 = v4 - v6;
          do
          {
            base_3a = v13[v14];
            v13[v14] = *v13;
            *v13++ = base_3a;
            --v12;
          }
          while ( v12 != 0 );
          v4 = lo;
        }
      }
      if ( comp(a1: v8, a2: v6) > 0 )
      {
        v15 = width;
        v16 = v6;
        if ( v8 != v6 )
        {
          v17 = v8 - v6;
          do
          {
            base_3b = v16[v17];
            v16[v17] = *v16;
            *v16++ = base_3b;
            --v15;
          }
          while ( v15 != 0 );
          v4 = lo;
        }
      }
      while ( 1 )
      {
        if ( v8 > v4 )
        {
          while ( 1 )
          {
            v4 += width;
            if ( v4 >= v8 )
              break;
            if ( comp(a1: v4, a2: v8) > 0 )
            {
              if ( v8 > v4 )
                goto LABEL_32;
              goto LABEL_30;
            }
          }
        }
        do
LABEL_30:
          v4 += width;
        while ( v4 <= hi && comp(a1: v4, a2: v8) <= 0 );
        do
LABEL_32:
          v6 -= width;
        while ( v6 > v8 && comp(a1: v6, a2: v8) > 0 );
        if ( v4 > v6 )
          break;
        v18 = width;
        v19 = v6;
        if ( v4 != v6 )
        {
          v20 = v4 - v6;
          do
          {
            v30 = v18 - 1;
            base_3c = v19[v20];
            v19[v20] = *v19;
            *v19 = base_3c;
            v18 = v30;
            ++v19;
          }
          while ( v30 != 0 );
        }
        if ( v8 == v6 )
          v8 = v4;
      }
      v6 += width;
      if ( v8 >= v6 )
        goto LABEL_44;
      do
      {
        v6 -= width;
        if ( v6 <= v8 )
          goto LABEL_44;
      }
      while ( comp(a1: v6, a2: v8) == 0 );
      if ( v8 < v6 )
      {
LABEL_46:
        v21 = lo;
      }
      else
      {
LABEL_44:
        while ( 1 )
        {
          v6 -= width;
          v21 = lo;
          if ( v6 <= lo )
            break;
          if ( comp(a1: v6, a2: v8) != 0 )
            goto LABEL_46;
        }
      }
      v22 = hi;
      if ( v6 - v21 < hi - v4 )
      {
        if ( v4 < hi )
        {
          v24 = stkptr;
          lostk[stkptr] = v4;
          histk[v24] = v22;
          stkptr = v24 + 1;
        }
        if ( v21 >= v6 )
          goto LABEL_56;
        v4 = lo;
        v5 = width;
        hi = v6;
      }
      else
      {
        if ( v21 < v6 )
        {
          v23 = stkptr;
          lostk[stkptr] = v21;
          histk[v23] = v6;
          stkptr = v23 + 1;
        }
        if ( v4 >= v22 )
        {
LABEL_56:
          v5 = width;
LABEL_57:
          v25 = --stkptr;
          if ( stkptr < 0 )
            return;
          v26 = lostk[v25];
          v27 = histk[v25];
          lo = v26;
          hi = v27;
          v6 = v27;
          v4 = v26;
        }
        else
        {
          v6 = hi;
          v5 = width;
          lo = v4;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D6CB
// Name: void operator delete(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl operator delete(void *p)
{
  free(pBlock: p);
}

//------------------------------------------------------------------------------
// Address: 0x1003D6D6
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pBlock: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D743
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D7B7
// Name: __fwrite_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fwrite_nolock(unsigned __int8 *buffer, unsigned int size, unsigned int num, _iobuf *stream)
{
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int cnt; // eax
  unsigned int v8; // edi
  unsigned int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int bufsize; // [esp+10h] [ebp-8h]
  unsigned __int8 *data; // [esp+14h] [ebp-4h]

  if ( size == 0 || num == 0 )
    return 0;
  if ( stream == nullptr || buffer == nullptr || num > 0xFFFFFFFF / size )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v5 = num * size;
  data = buffer;
  v6 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsize = stream->_bufsiz;
  else
    bufsize = 4096;
  if ( v5 == 0 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x108) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt != 0 )
      {
        if ( cnt < 0 )
        {
          stream->_flag |= 0x20u;
LABEL_34:
          v13 = v5;
          return (v13 - v6) / size;
        }
        v8 = v6;
        if ( v6 >= cnt )
          v8 = stream->_cnt;
        memcpy(dst: (unsigned __int8 *)stream->_ptr, src: data, count: v8);
        stream->_cnt -= v8;
        stream->_ptr += v8;
        v6 -= v8;
        data += v8;
        goto LABEL_27;
      }
    }
    if ( v6 >= bufsize )
      break;
    if ( _flsbuf(ch: (char)*data, str: stream) == -1 )
      goto LABEL_34;
    ++data;
    --v6;
    bufsize = stream->_bufsiz;
    if ( (int)bufsize <= 0 )
      bufsize = 1;
LABEL_31:
    if ( v6 == 0 )
      return num;
  }
  if ( (stream->_flag & 0x108) != 0 && _flush(str: stream) != 0 )
    goto LABEL_34;
  v9 = v6;
  if ( bufsize != 0 )
    v9 = v6 - v6 % bufsize;
  v10 = _fileno(stream);
  v11 = _write(fh: v10, buf: data, cnt: v9);
  if ( v11 != -1 )
  {
    v12 = v9;
    if ( v11 <= v9 )
      v12 = v11;
    data += v12;
    v6 -= v12;
    if ( v11 >= v9 )
    {
LABEL_27:
      v5 = num * size;
      goto LABEL_31;
    }
  }
  stream->_flag |= 0x20u;
  v13 = num * size;
  return (v13 - v6) / size;
}

//------------------------------------------------------------------------------
// Address: 0x1003D90E
// Name: _fwrite
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fwrite(unsigned __int8 *buffer, unsigned int size, unsigned int count, _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( size == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fwrite_nolock(buffer, size, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003D988
// Name: _fprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fprintf(_iobuf *str, const char *format, ...)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v6; // esi
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v3 = _fileno(stream: str);
      if ( v3 == -1 || v3 == -2 )
        v4 = &__badioinfo;
      else
        v4 = &__pioinfo[v3 >> 5][v3 & 0x1F];
      if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
        || (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v6 = _stbuf(str);
      retval = _output_l(stream: str, format, plocinfo: nullptr, argptr);
      _ftbuf(flag: v6, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DA94
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x1003DA9A
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int osfhnd; // eax

  v0 = _nstream;
  if ( _nstream == 0 )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)_calloc_crt(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)_calloc_crt(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&std::bad_alloc `RTTI Type Descriptor' )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_10089C20;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_10089C80 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003DB4B
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pBlock: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x1003DB6B
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_10089E70 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(locknum: pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DBAC
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(locknum: i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DBDE
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_10089E70 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(locknum: pf - _iob + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DC1A
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(locknum: i + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DC49
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  ms_exc.registration.TryLevel = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: (int)&ms_exc.registration, a3: 0xFFFFFFFE);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003DD05
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x1003DD1C
// Name: __fseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseek_nolock(_iobuf *str, LONG offset, DWORD whence)
{
  int flag; // eax
  int v5; // eax
  int v6; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock(str);
      whence = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = _fileno(stream: str);
    return (_lseek(fh: v6, pos: offset, mthd: whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DDA6
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fseek(_iobuf *stream, LONG offset, DWORD whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseek_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DE22
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fread_nolock_s(
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned __int8 *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  unsigned __int8 *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = buffer;
  dataSize = bufferSize;
  if ( elementSize == 0 || num == 0 )
    return 0;
  if ( buffer != nullptr )
  {
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
      goto LABEL_13;
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
    {
LABEL_13:
      v6 = num * elementSize;
      v7 = num * elementSize;
      if ( (stream->_flag & 0x10C) != 0 )
        streambufsize = stream->_bufsiz;
      else
        streambufsize = 4096;
      if ( v6 == 0 )
        return num;
      while ( 1 )
      {
        if ( (stream->_flag & 0x10C) != 0 )
        {
          cnt = stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_44;
            v9 = v7;
            if ( v7 >= cnt )
              v9 = stream->_cnt;
            if ( v9 > dataSize )
              goto LABEL_41;
            memcpy_s(dst: data, sizeInBytes: dataSize, src: (unsigned __int8 *)stream->_ptr, count: v9);
            stream->_cnt -= v9;
            stream->_ptr += v9;
            data += v9;
            v7 -= v9;
            dataSize -= v9;
            v6 = num * elementSize;
            goto LABEL_39;
          }
        }
        if ( v7 < streambufsize )
          break;
        if ( streambufsize != 0 )
        {
          if ( v7 <= 0x7FFFFFFF )
          {
            v10 = v7 % streambufsize;
            v11 = v7;
          }
          else
          {
            v10 = 0x7FFFFFFF % streambufsize;
            v11 = 0x7FFFFFFF;
          }
          v12 = v11 - v10;
        }
        else
        {
          v12 = 0x7FFFFFFF;
          if ( v7 <= 0x7FFFFFFF )
            v12 = v7;
        }
        if ( v12 > dataSize )
          goto LABEL_41;
        v17 = v12;
        v13 = _fileno(stream);
        v14 = _read(fh: v13, buf: data, cnt: v17);
        if ( v14 == 0 )
        {
          stream->_flag |= 0x10u;
          return (v6 - v7) / elementSize;
        }
        if ( v14 == -1 )
        {
LABEL_44:
          stream->_flag |= 0x20u;
          return (v6 - v7) / elementSize;
        }
        data += v14;
        v7 -= v14;
        dataSize -= v14;
LABEL_39:
        if ( v7 == 0 )
          return num;
      }
      v15 = _filbuf(str: stream);
      if ( v15 == -1 )
        return (v6 - v7) / elementSize;
      if ( dataSize != 0 )
      {
        v16 = data++;
        *v16 = v15;
        --v7;
        --dataSize;
        streambufsize = stream->_bufsiz;
        goto LABEL_39;
      }
LABEL_41:
      if ( bufferSize != -1 )
        memset(dst: (int)buffer, value: nullptr, count: bufferSize);
      *_errno() = 34;
LABEL_5:
      _invalid_parameter_noinfo();
      return 0;
    }
  }
  *_errno() = 22;
  goto LABEL_5;
}

//------------------------------------------------------------------------------
// Address: 0x1003DFDE
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread_s(
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( elementSize == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fread_nolock_s(buffer, bufferSize, elementSize, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003E06C
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread(unsigned __int8 *buffer, unsigned int elementSize, unsigned int count, _iobuf *stream)
{
  return fread_s(buffer, bufferSize: 0xFFFFFFFF, elementSize, count, stream);
}

//------------------------------------------------------------------------------
// Address: 0x1003E0D8
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __cdecl operator new(unsigned int size)
{
  LPVOID result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-10h] BYREF
  char *_What; // [esp+Ch] [ebp-4h] BYREF

  while ( 1 )
  {
    result = malloc(size);
    if ( result != nullptr )
      break;
    if ( _callnewh(size) == 0 )
    {
      if ( (_S1_2 & 1) == 0 )
      {
        _S1_2 |= 1u;
        _What = "bad allocation";
        std::exception::exception(this: &nomem, (const char *const *)&_What, __formal: 1);
        nomem.__vftable = (std::bad_alloc_vtbl *)&std::bad_alloc::`vftable';
        atexit(func: operator_new_::_6_::_dynamic_atexit_destructor_for__nomem__);
      }
      std::exception::exception(this: &pExceptionObject, _That: &nomem);
      pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003E27B
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003E292
// Name: _sprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+38h] [ebp+10h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && string != nullptr )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(ch: 0, &str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E330
// Name: _strchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strchr(char *string, unsigned __int8 chr)
{
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = string;
  if ( ((unsigned __int8)string & 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == chr || v3 == 0 )
        break;
      if ( ((unsigned __int8)v2 & 3) == 0 )
        goto main_loop;
    }
  }
  else
  {
    do
    {
main_loop:
      while ( 1 )
      {
        v4 = ((chr << 8) | chr | (((chr << 8) | chr) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( (((v4 + 2130640639) ^ ~v4) & 0x81010100) != 0 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 != 0 && ((v7 & 0x1010100) != 0 || (v5 & 0x80000000) == 0) )
          return;
      }
      v8 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v8 == chr )
        break;
      if ( (_BYTE)v8 == 0 )
        break;
      if ( BYTE1(v8) == chr )
        break;
      if ( BYTE1(v8) == 0 )
        break;
      v9 = HIWORD(v8);
      if ( (_BYTE)v9 == chr )
        break;
    }
    while ( (_BYTE)v9 != 0 && BYTE1(v9) != chr && BYTE1(v9) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E3F0
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x1003E336);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E476
// Name: IsRootUNCName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall IsRootUNCName@<eax>(const char *path@<esi>)
{
  unsigned int v1; // eax
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  unsigned __int8 *v9; // [esp+0h] [ebp-4h]

  strlen(buf: v9);
  if ( v1 < 5 || *path != 92 && *path != 47 )
    return false;
  v2 = path[1];
  if ( v2 != 92 && v2 != 47 )
    return false;
  v3 = path[2];
  if ( v3 == 92 )
    return false;
  if ( v3 == 47 )
    return false;
  v4 = path + 3;
  v5 = path[3];
  if ( v5 == 0 )
    return false;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    v5 = *++v4;
  }
  while ( *v4 != 0 );
  if ( *v4 == 0 )
    return false;
  v6 = (char *)(v4 + 1);
  if ( *v6 == 0 )
    return false;
  v7 = *v6;
  do
  {
    if ( v7 == 92 )
      break;
    if ( v7 == 47 )
      break;
    v7 = *++v6;
  }
  while ( *v6 != 0 );
  return *v6 == 0 || v6[1] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E4F0
// Name: _fullpath_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fullpath_helper(char *buf, const char *path, DWORD sz, char **pBuf)
{
  int v4; // esi
  char *v5; // edi
  int *v6; // eax
  char *result; // eax

  v4 = *_errno();
  *_errno() = 0;
  v5 = _fullpath(UserBuf: buf, path, maxlen: sz);
  v6 = _errno();
  if ( v5 != nullptr )
  {
    *v6 = v4;
    return v5;
  }
  else if ( *v6 == 34 )
  {
    *_errno() = v4;
    result = _fullpath(UserBuf: nullptr, path, maxlen: 0);
    *pBuf = result;
  }
  else
  {
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003E550
// Name: __stat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stat64i32(char *name, _stat64i32 *buf)
{
  const char *dwHighDateTime; // esi
  int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  unsigned __int8 *v6; // eax
  const char *v7; // esi
  int v8; // eax
  __int64 v9; // rax
  int v10; // esi
  int v12; // edx
  int v13; // edx
  int v14; // edx
  DWORD LastError; // eax
  int retval; // [esp+Ch] [ebp-26Ch]
  int drive; // [esp+10h] [ebp-268h]
  _FILETIME LocalFTime; // [esp+14h] [ebp-264h] BYREF
  int fd; // [esp+1Ch] [ebp-25Ch] BYREF
  _WIN32_FIND_DATAA findbuf; // [esp+20h] [ebp-258h] BYREF
  _SYSTEMTIME SystemTime; // [esp+160h] [ebp-118h] BYREF
  char pathbuf[260]; // [esp+170h] [ebp-108h] BYREF

  dwHighDateTime = name;
  LocalFTime.dwHighDateTime = (unsigned int)name;
  retval = 0;
  if ( name == nullptr || buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _mbspbrk(string: (unsigned __int8 *)name, charset: "?*");
  if ( v3 != 0 )
  {
LABEL_5:
    *_errno() = 2;
    *__doserrno() = 2;
    return -1;
  }
  if ( name[1] == 58 )
  {
    if ( *name != 0 && name[2] == 0 )
      goto LABEL_5;
    v4 = _mbctolower(c: *name) - 96;
  }
  else
  {
    v4 = _getdrive();
  }
  drive = v4;
  fd = (int)FindFirstFileExA(
              lpFileName: name,
              fInfoLevelId: FindExInfoStandard,
              lpFindFileData: &findbuf,
              fSearchOp: FindExSearchNameMatch,
              lpSearchFilter: nullptr,
              dwAdditionalFlags: 0);
  if ( fd != -1 )
  {
    if ( (findbuf.dwFileAttributes & 0x400) != 0 && findbuf.dwReserved0 == -1610612724 )
    {
      fd = -1;
      if ( _sopen_s(pfh: &fd, path: name, oflag: 0, shflag: 64, pmode: 0) == 0 && fd != -1 )
      {
        v10 = _fstat64i32(fildes: fd, buf);
        _close(fh: fd);
        return v10;
      }
      goto LABEL_5;
    }
    if ( findbuf.ftLastWriteTime.dwLowDateTime != 0 || findbuf.ftLastWriteTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastWriteTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      LODWORD(buf->st_mtime) = __loctotime64_t(
                                 yr: SystemTime.wYear,
                                 mo: SystemTime.wMonth,
                                 dy: SystemTime.wDay,
                                 hr: SystemTime.wHour,
                                 mn: SystemTime.wMinute,
                                 sc: SystemTime.wSecond,
                                 dstflag: -1);
      HIDWORD(buf->st_mtime) = v12;
    }
    else
    {
      buf->st_mtime = 0;
    }
    if ( findbuf.ftLastAccessTime.dwLowDateTime != 0 || findbuf.ftLastAccessTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastAccessTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      LODWORD(buf->st_atime) = __loctotime64_t(
                                 yr: SystemTime.wYear,
                                 mo: SystemTime.wMonth,
                                 dy: SystemTime.wDay,
                                 hr: SystemTime.wHour,
                                 mn: SystemTime.wMinute,
                                 sc: SystemTime.wSecond,
                                 dstflag: -1);
      HIDWORD(buf->st_atime) = v13;
    }
    else
    {
      buf->st_atime = buf->st_mtime;
    }
    if ( findbuf.ftCreationTime.dwLowDateTime == 0 && findbuf.ftCreationTime.dwHighDateTime == 0 )
    {
      buf->st_ctime = buf->st_mtime;
LABEL_45:
      FindClose(hFindFile: (HANDLE)fd);
      goto LABEL_46;
    }
    if ( FileTimeToLocalFileTime(lpFileTime: &findbuf.ftCreationTime, lpLocalFileTime: &LocalFTime)
      && FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
    {
      LODWORD(buf->st_ctime) = __loctotime64_t(
                                 yr: SystemTime.wYear,
                                 mo: SystemTime.wMonth,
                                 dy: SystemTime.wDay,
                                 hr: SystemTime.wHour,
                                 mn: SystemTime.wMinute,
                                 sc: SystemTime.wSecond,
                                 dstflag: -1);
      HIDWORD(buf->st_ctime) = v14;
      goto LABEL_45;
    }
LABEL_49:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    FindClose(hFindFile: (HANDLE)fd);
    return -1;
  }
  fd = 0;
  _mbspbrk(string: (unsigned __int8 *)name, charset: "./\\");
  if ( v5 == 0 )
    goto LABEL_5;
  v6 = (unsigned __int8 *)fullpath_helper(buf: pathbuf, path: name, sz: 0x104u, pBuf: (char **)&fd);
  v7 = (const char *)v6;
  if ( v6 == nullptr || (strlen(buf: v6), v8 != 3) && !IsRootUNCName(path: v7) || GetDriveTypeA(lpRootPathName: v7) <= 1 )
  {
    if ( fd != 0 )
      free(pBlock: (void *)fd);
    goto LABEL_5;
  }
  if ( fd != 0 )
    free(pBlock: (void *)fd);
  findbuf.dwFileAttributes = 16;
  findbuf.nFileSizeHigh = 0;
  findbuf.nFileSizeLow = 0;
  findbuf.cFileName[0] = 0;
  LODWORD(v9) = __loctotime64_t(yr: 1980, mo: 1, dy: 1, hr: 0, mn: 0, sc: 0, dstflag: -1);
  dwHighDateTime = (const char *)LocalFTime.dwHighDateTime;
  buf->st_mtime = v9;
  buf->st_atime = v9;
  buf->st_ctime = v9;
LABEL_46:
  buf->st_mode = __dtoxmode(attr: findbuf.dwFileAttributes, name: dwHighDateTime);
  buf->st_nlink = 1;
  buf->st_size = findbuf.nFileSizeLow;
  if ( findbuf.nFileSizeHigh != 0 )
  {
    retval = -1;
    buf->st_size = 0;
  }
  buf->st_ino = 0;
  buf->st_gid = 0;
  buf->st_uid = 0;
  buf->st_dev = drive - 1;
  buf->st_rdev = drive - 1;
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003E9A7
// Name: _setvbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl setvbuf(_iobuf *str, char *buffer, int type, unsigned int size)
{
  unsigned int v5; // edi
  int v6; // edi
  int flag; // ecx
  int v8; // ecx
  char *p_charbuf; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str == nullptr )
    goto LABEL_2;
  if ( type != 4 )
  {
    if ( type == 0 )
      goto LABEL_7;
    if ( type != 64 )
    {
LABEL_2:
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( type != 64 )
  {
    v5 = size;
    goto LABEL_10;
  }
LABEL_7:
  v5 = size;
  if ( size - 2 > 0x7FFFFFFD )
    goto LABEL_2;
LABEL_10:
  v6 = v5 & 0xFFFFFFFE;
  _lock_file(pf: str);
  _flush(str);
  _freebuf(stream: str);
  str->_flag &= 0xFFFFC2F3;
  flag = str->_flag;
  if ( (type & 4) != 0 )
  {
    v8 = flag | 4;
    p_charbuf = (char *)&str->_charbuf;
    v6 = 2;
LABEL_17:
    str->_flag = v8;
    goto LABEL_18;
  }
  p_charbuf = buffer;
  if ( buffer != nullptr )
  {
    v8 = flag | 0x500;
    goto LABEL_17;
  }
  p_charbuf = (char *)_malloc_crt(cb: v6);
  if ( p_charbuf != nullptr )
  {
    str->_flag |= 0x408u;
LABEL_18:
    str->_bufsiz = v6;
    str->_base = p_charbuf;
    str->_ptr = p_charbuf;
    str->_cnt = 0;
    goto done_0;
  }
  ++_cflush;
  retval = -1;
done_0:
  _unlock_file(pf: str);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003EA9D
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(void *enull)
{
  _pnhHeap = enull;
}

//------------------------------------------------------------------------------
// Address: 0x1003EAAC
// Name: int (*_set_new_handler(int (*)(unsigned int)))(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int (__cdecl *__cdecl _set_new_handler(int (__cdecl *pnh)(unsigned int)))(unsigned int)
{
  PVOID v1; // esi

  _lock(locknum: 4);
  v1 = DecodePointer(Ptr: _pnhHeap);
  _pnhHeap = EncodePointer(Ptr: pnh);
  _unlock(locknum: 4);
  return (int (__cdecl *)(unsigned int))v1;
}

//------------------------------------------------------------------------------
// Address: 0x1003EAE3
// Name: __callnewh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _callnewh(unsigned int size)
{
  int (__cdecl *v1)(unsigned int); // eax

  v1 = (int (__cdecl *)(unsigned int))DecodePointer(Ptr: _pnhHeap);
  return v1 != nullptr && v1(a1: size) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003EB0B
// Name: int _set_new_mode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _set_new_mode(unsigned int nhm)
{
  int result; // eax

  if ( nhm < 2 )
  {
    result = _newmode;
    _newmode = nhm;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003EB3E
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax
  wchar_t drvstr[4]; // [esp+0h] [ebp-Ch] BYREF

  result = true;
  if ( drive != 0 )
  {
    drvstr[0] = drive + 64;
    wcscpy(&drvstr[1], L":\\");
    if ( GetDriveTypeW(lpRootPathName: drvstr) <= 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003EB98
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  unsigned int v3; // ebx
  char *v5; // edi
  signed int FullPathNameA; // eax
  char *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  int count; // [esp+8h] [ebp-4h]

  v3 = drive;
  if ( drive != 0 )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  else
  {
    v3 = _getdrive();
  }
  v5 = pnbuf;
  if ( pnbuf != nullptr )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v3 != 0 )
  {
    LOBYTE(drive) = v3 + 64;
    strcpy((char *)&drive + 1, ":.");
  }
  else
  {
    strcpy((char *)&drive, ".");
  }
  FullPathNameA = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: count, lpBuffer: v5, lpFilePart: &pname);
  if ( FullPathNameA == 0 )
    goto LABEL_24;
  if ( v5 == nullptr )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v7 = (char *)calloc(num: maxlen, size: 1u);
    v5 = v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return nullptr;
    }
    v8 = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: maxlen, lpBuffer: v7, lpFilePart: &pname);
    if ( v8 != 0 && v8 < maxlen )
      return v5;
LABEL_24:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return nullptr;
  }
  if ( FullPathNameA < count )
    return v5;
  *_errno() = 34;
  *v5 = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003ECBC
// Name: __getcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getcwd(char *pnbuf, int maxlen)
{
  char *retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = _getdcwd_nolock(drive: 0, pnbuf, maxlen);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003ED05
// Name: __mkdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mkdir(const char *path)
{
  DWORD LastError; // eax

  if ( CreateDirectoryA(lpPathName: path, lpSecurityAttributes: nullptr) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003ED40
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _alloca_probe_16@<eax>(int a1@<eax>, int a2@<ecx>)
{
  char v2; // sp
  int v3; // ecx

  v3 = (v2 + 8 - (_BYTE)a1) & 0xF;
  return _chkstk(a1: __CFADD__(v3, a1) ? -1 : v3 + a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1003ED6C
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int printf(const char *format, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  int v4; // edi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    v2 = __iob_func();
    _lock_file2(i: 1, s: (char *)&v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: (char *)&v7[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EE13
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x1003EE29
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleW; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"mscoree.dll");
  if ( ModuleHandleW != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleW, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EE54
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x1003EE6C
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x1003EE75
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x1003EE7E
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _init_pointers()
{
  void *v0; // esi

  v0 = (void *)_encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_invarg(enull: v0);
  _initp_misc_purevirt(enull: v0);
  _initp_misc_rand_s(enull: (int (__stdcall *)(void *, unsigned int))v0);
  _initp_misc_winsig(enull: v0);
  _initp_eh_hooks();
}

//------------------------------------------------------------------------------
// Address: 0x1003EEB1
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && result == 0 )
  {
    if ( *pfbegin != nullptr )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003EED5
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // edi

  if ( _fpmath != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) )
    _fpmath(initPrecision: initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(pfbegin: __xi_a, pfend: __xi_z);
  if ( result == 0 )
  {
    atexit(func: _RTC_Terminate);
    for ( i = __xc_a; i < __xc_z; ++i )
    {
      if ( *i != nullptr )
        (*i)();
    }
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003EF6C
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  PVOID *v3; // ebx
  PVOID *v4; // edi
  void (*v5)(void); // ebx
  void (__cdecl **v6)(); // ebx
  void (__cdecl **v7)(); // eax
  void (__cdecl **onexitbegin)(); // [esp+10h] [ebp-30h]
  void (__cdecl **onexitend_saved)(); // [esp+18h] [ebp-28h]
  void (__cdecl **onexitbegin_saved)(); // [esp+1Ch] [ebp-24h]
  void (**j)(void); // [esp+20h] [ebp-20h]
  void (**i)(void); // [esp+24h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      v3 = (PVOID *)DecodePointer(Ptr: __onexitbegin);
      onexitbegin = (void (__cdecl **)())v3;
      if ( v3 != nullptr )
      {
        v4 = (PVOID *)DecodePointer(Ptr: __onexitend);
        onexitbegin_saved = (void (__cdecl **)())v3;
        onexitend_saved = (void (__cdecl **)())v4;
        while ( --v4 >= v3 )
        {
          if ( *v4 != (PVOID)_encoded_null() )
          {
            if ( v4 < v3 )
              break;
            v5 = (void (*)(void))DecodePointer(Ptr: *v4);
            *v4 = (PVOID)_encoded_null();
            v5();
            v6 = (void (__cdecl **)())DecodePointer(Ptr: __onexitbegin);
            v7 = (void (__cdecl **)())DecodePointer(Ptr: __onexitend);
            if ( onexitbegin_saved != v6 || onexitend_saved != v7 )
            {
              onexitbegin_saved = v6;
              onexitbegin = v6;
              onexitend_saved = v7;
              v4 = (PVOID *)v7;
            }
            v3 = (PVOID *)onexitbegin;
          }
        }
      }
      for ( i = __xp_a; i < __xp_z; ++i )
      {
        if ( *i != nullptr )
          (*i)();
      }
    }
    for ( j = __xt_a; j < __xt_z; ++j )
    {
      if ( *j != nullptr )
        (*j)();
    }
  }
  if ( retcaller != 0 )
    _unlock(locknum: 8);
  if ( retcaller == 0 )
  {
    _C_Exit_Done = 1;
    _unlock(locknum: 8);
    __crtExitProcess(status: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F0AC
// Name: _exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn exit(int code)
{
  doexit(code, quick: 0, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003F0C2
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003F0D8
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1003F0E7
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _amsg_exit(int rterrnum)
{
  _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  _exit(code: 255);
}

//------------------------------------------------------------------------------
// Address: 0x1003F105
// Name: __findclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findclose(void *hFile)
{
  if ( FindClose(hFindFile: hFile) )
    return 0;
  *_errno() = 22;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003F12B
// Name: ___time64_t_from_ft
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __time64_t_from_ft(_FILETIME *pft)
{
  _FILETIME lft; // [esp+0h] [ebp-1Ch] BYREF
  _SYSTEMTIME st; // [esp+8h] [ebp-14h] BYREF

  if ( (pft->dwLowDateTime != 0 || pft->dwHighDateTime != 0)
    && FileTimeToLocalFileTime(lpFileTime: pft, lpLocalFileTime: &lft)
    && FileTimeToSystemTime(lpFileTime: &lft, lpSystemTime: &st) )
  {
    return __loctotime64_t(
             yr: st.wYear,
             mo: st.wMonth,
             dy: st.wDay,
             hr: st.wHour,
             mn: st.wMinute,
             sc: st.wSecond,
             dstflag: 0);
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F1A7
// Name: __findfirst64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findfirst64i32(const char *szWild, _finddata64i32_t *pfd)
{
  HANDLE FirstFile; // ebx
  DWORD LastError; // eax
  int v5; // edx
  int v6; // edx
  int v7; // edx
  _WIN32_FIND_DATAA wfd; // [esp+8h] [ebp-144h] BYREF

  if ( pfd == nullptr || szWild == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  FirstFile = FindFirstFileExA(
                lpFileName: szWild,
                fInfoLevelId: FindExInfoStandard,
                lpFindFileData: &wfd,
                fSearchOp: FindExSearchNameMatch,
                lpSearchFilter: nullptr,
                dwAdditionalFlags: 0);
  if ( FirstFile == (HANDLE)-1 )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_13;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_13:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  LODWORD(pfd->time_create) = __time64_t_from_ft(pft: &wfd.ftCreationTime);
  HIDWORD(pfd->time_create) = v5;
  LODWORD(pfd->time_access) = __time64_t_from_ft(pft: &wfd.ftLastAccessTime);
  HIDWORD(pfd->time_access) = v6;
  LODWORD(pfd->time_write) = __time64_t_from_ft(pft: &wfd.ftLastWriteTime);
  pfd->size = wfd.nFileSizeLow;
  HIDWORD(pfd->time_write) = v7;
  if ( strcpy_s(_Dst: pfd->name, _SizeInBytes: 0x104u, _Src: wfd.cFileName) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return (int)FirstFile;
}

//------------------------------------------------------------------------------
// Address: 0x1003F2CE
// Name: __findnext64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findnext64i32(void *hFile, _finddata64i32_t *pfd)
{
  int result; // eax
  DWORD LastError; // eax
  int v4; // edx
  int v5; // edx
  int v6; // edx
  _WIN32_FIND_DATAA wfd; // [esp+4h] [ebp-144h] BYREF

  if ( hFile == (void *)-1 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( pfd == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( !FindNextFileA(hFindFile: hFile, lpFindFileData: &wfd) )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_14;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_14:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  LODWORD(pfd->time_create) = __time64_t_from_ft(pft: &wfd.ftCreationTime);
  HIDWORD(pfd->time_create) = v4;
  LODWORD(pfd->time_access) = __time64_t_from_ft(pft: &wfd.ftLastAccessTime);
  HIDWORD(pfd->time_access) = v5;
  LODWORD(pfd->time_write) = __time64_t_from_ft(pft: &wfd.ftLastWriteTime);
  pfd->size = wfd.nFileSizeLow;
  HIDWORD(pfd->time_write) = v6;
  result = strcpy_s(_Dst: pfd->name, _SizeInBytes: 0x104u, _Src: wfd.cFileName);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003F3FC
// Name: _strtok
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strtok(char *string, const char *control)
{
  char v3; // dl
  char *token; // edx
  char *v5; // ebx
  _tiddata *ptd; // [esp+10h] [ebp-28h]
  unsigned __int8 map[32]; // [esp+14h] [ebp-24h] BYREF

  ptd = _getptd();
  memset(map, 0, sizeof(map));
  do
  {
    v3 = *control;
    map[*(unsigned __int8 *)control >> 3] |= 1 << (*control & 7);
    ++control;
  }
  while ( v3 != 0 );
  token = string;
  if ( string == nullptr )
    token = ptd->_token;
  while ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 && *token != 0 )
    ++token;
  v5 = token;
  while ( *token != 0 )
  {
    if ( ((unsigned __int8)(1 << (*token & 7)) & map[(unsigned __int8)*token >> 3]) != 0 )
    {
      *token++ = 0;
      break;
    }
    ++token;
  }
  ptd->_token = token;
  return token != v5 ? v5 : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003F4B9
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003F565
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x1003F590
// Name: __aulldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldiv(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v3; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = v6 / v5;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    return v8;
  }
  else
  {
    LODWORD(v3) = a1;
    HIDWORD(v3) = HIDWORD(a1) % (unsigned int)a2;
    return v3 / (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F600
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x1003F634
// Name: __toupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _toupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+14h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 2;
    }
    else
    {
      v4 = _isctype_l(c, mask: 2, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pcumap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x1003F74A
// Name: _toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl toupper(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _toupper_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 97 <= 0x19 )
    return c - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003F776
// Name: __get_sys_err_msg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _get_sys_err_msg(int m)
{
  int v1; // esi

  v1 = m;
  if ( m < 0 || m >= *__sys_nerr() )
    v1 = *__sys_nerr();
  return __sys_errlist()[v1];
}

//------------------------------------------------------------------------------
// Address: 0x1003F79E
// Name: _strerror
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strerror(int errnum)
{
  _tiddata *v1; // eax
  _tiddata *v2; // esi
  char *v4; // eax
  char *errmsg; // esi
  char *sys_err_msg; // eax

  v1 = _getptd_noexit();
  v2 = v1;
  if ( v1 == nullptr )
    return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  if ( v1->_errmsg == nullptr )
  {
    v4 = (char *)_calloc_crt(count: 0x86u, size: 1u);
    v2->_errmsg = v4;
    if ( v4 == nullptr )
      return "Visual C++ CRT: Not enough memory to complete call to strerror.";
  }
  errmsg = v2->_errmsg;
  sys_err_msg = _get_sys_err_msg(m: errnum);
  if ( strcpy_s(_Dst: errmsg, _SizeInBytes: 0x86u, _Src: sys_err_msg) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return errmsg;
}

//------------------------------------------------------------------------------
// Address: 0x1003F808
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x1003F84A
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x1003F85D
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x1003F870
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x1003F893
// Name: __tempnam
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _tempnam(char *dir, char *pfx)
{
  char *result; // eax
  int v3; // eax
  char *v4; // edi
  unsigned int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v8; // esi
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  char *v12; // edi
  int v13; // ebx
  char *first; // [esp+14h] [ebp-2Ch]
  unsigned int firsta; // [esp+14h] [ebp-2Ch]
  unsigned int pfxlength; // [esp+1Ch] [ebp-24h]
  char *envbuf; // [esp+20h] [ebp-20h] BYREF
  unsigned int bufsz; // [esp+24h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+28h] [ebp-18h]

  pfxlength = 0;
  envbuf = nullptr;
  result = (char *)_mtinitlocknum(locknum: 2);
  if ( result == nullptr )
    return result;
  v3 = _dupenv_s(pBuffer: &envbuf, pBufferSizeInTChars: nullptr, varname: "TMP");
  if ( v3 != 0 )
  {
    if ( v3 == 22 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  else if ( envbuf != nullptr && _access_s(path: envbuf, amode: 0) == 0 )
  {
    v4 = envbuf;
LABEL_9:
    if ( pfx != nullptr )
    {
      strlen(buf: (unsigned __int8 *)pfx);
      pfxlength = v5;
    }
    strlen(buf: (unsigned __int8 *)v4);
    bufsz = v6 + pfxlength + 12;
    v7 = (char *)calloc(num: bufsz, size: 1u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      *v7 = 0;
      if ( strcat_s(_Dst: v7, _SizeInBytes: bufsz, _Src: v4) != 0 )
LABEL_39:
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      strlen(buf: (unsigned __int8 *)v4);
      first = &v4[v9 - 1];
      if ( *first == 92 )
      {
        _mbsrchr(str: (unsigned __int8 *)v4, c: 0x5Cu);
        if ( first != v10 && strcat_s(_Dst: v8, _SizeInBytes: bufsz, _Src: "\\") != 0 )
LABEL_16:
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      }
      else if ( *first != 47 && strcat_s(_Dst: v8, _SizeInBytes: bufsz, _Src: "\\") != 0 )
      {
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      }
      if ( pfx != nullptr && strcat_s(_Dst: v8, _SizeInBytes: bufsz, _Src: pfx) != 0 )
        goto LABEL_16;
      strlen(buf: (unsigned __int8 *)v8);
      v12 = &v8[v11];
      _lock(locknum: 2);
      ms_exc.registration.TryLevel = 0;
      if ( _old_pfxlen < pfxlength )
        _tempoff = 1;
      _old_pfxlen = pfxlength;
      firsta = _tempoff;
      v13 = *_errno();
      do
      {
        if ( ++_tempoff - firsta > 0x7FFFFFFF )
        {
          *_errno() = v13;
          free(pBlock: v8);
          v8 = nullptr;
          goto done1;
        }
        if ( _ultoa_s(val: _tempoff, buf: v12, sizeInTChars: (unsigned int)&v8[bufsz - (_DWORD)v12], radix: 0xAu) != 0 )
          goto LABEL_39;
        *_errno() = 0;
      }
      while ( _access_s(path: v8, amode: 0) == 0 || *_errno() == 13 );
      *_errno() = v13;
done1:
      ms_exc.registration.TryLevel = -2;
      _unlock(locknum: 2);
    }
    free(pBlock: envbuf);
    free(pBlock: nullptr);
    return v8;
  }
  v4 = dir;
  if ( dir == nullptr || _access_s(path: dir, amode: 0) != 0 )
  {
    if ( _access_s(path: "\\", amode: 0) != 0 )
      v4 = ".";
    else
      v4 = "\\";
  }
  goto LABEL_9;
}

//------------------------------------------------------------------------------
// Address: 0x1003FAFE
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, mask: 4, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003FB4F
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 4;
}

//------------------------------------------------------------------------------
// Address: 0x1003FB7D
// Name: __isxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isxdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x80;
  else
    result = _isctype_l(c, mask: 128, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003FBD3
// Name: _isxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isxdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isxdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x80;
}

//------------------------------------------------------------------------------
// Address: 0x1003FC03
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isspace_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 8;
  else
    result = _isctype_l(c, mask: 8, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003FC54
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isspace(int c)
{
  if ( __locale_changed != 0 )
    return _isspace_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 8;
}

//------------------------------------------------------------------------------
// Address: 0x1003FC82
// Name: __isalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isalnum_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x107;
  else
    result = _isctype_l(c, mask: 263, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003FCD8
// Name: _isalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isalnum(int c)
{
  if ( __locale_changed != 0 )
    return _isalnum_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x107;
}

//------------------------------------------------------------------------------
// Address: 0x1003FD08
// Name: _remove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl remove(const char *path)
{
  DWORD LastError; // eax

  if ( DeleteFileA(lpFileName: path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003FD38
// Name: __unlink
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unlink(const char *path)
{
  return remove(path);
}

//------------------------------------------------------------------------------
// Address: 0x1003FD43
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl _getenv_helper_nolock(char *option)
{
  unsigned __int8 **v1; // esi
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax

  v1 = (unsigned __int8 **)_environ;
  if ( __env_initialized == 0 )
    return nullptr;
  if ( _environ != nullptr
    || _wenviron != nullptr && __wtomb_environ() == 0 && (v1 = (unsigned __int8 **)_environ, _environ != nullptr) )
  {
    if ( option != nullptr )
    {
      strlen(buf: (unsigned __int8 *)option);
      v4 = v3;
      while ( *v1 != nullptr )
      {
        strlen(buf: *v1);
        if ( v5 > v4 && (*v1)[v4] == 61 && _mbsnbicoll(s1: *v1, s2: (const unsigned __int8 *)option, n: v4) == 0 )
          return (const char *)&(*v1)[v4 + 1];
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003FDCA
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv(char *option)
{
  char *retval; // [esp+14h] [ebp-1Ch]

  if ( option != nullptr && strnlen(str: option, maxsize: 0x7FFFu) < 0x7FFF )
  {
    _lock(locknum: 7);
    retval = (char *)_getenv_helper_nolock(option);
    _unlock(locknum: 7);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003FE44
// Name: __dupenv_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _dupenv_s(char **pBuffer, unsigned int *pBufferSizeInTChars, char *varname)
{
  int v3; // esi
  unsigned __int8 *v4; // eax
  const char *v5; // ebx
  int v6; // eax
  unsigned int v7; // esi
  char *v8; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  v3 = 0;
  if ( pBuffer != nullptr )
  {
    *pBuffer = nullptr;
    if ( pBufferSizeInTChars != nullptr )
      *pBufferSizeInTChars = 0;
    if ( varname != nullptr )
    {
      v4 = (unsigned __int8 *)_getenv_helper_nolock(option: varname);
      v5 = (const char *)v4;
      if ( v4 == nullptr )
        goto LABEL_3;
      strlen(buf: v4);
      v7 = v6 + 1;
      v8 = (char *)calloc(num: v6 + 1, size: 1u);
      *pBuffer = v8;
      if ( v8 != nullptr )
      {
        if ( strcpy_s(_Dst: v8, _SizeInBytes: v7, _Src: v5) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        if ( pBufferSizeInTChars != nullptr )
          *pBufferSizeInTChars = v7;
        retval = 0;
      }
      else
      {
        *_errno() = 12;
        retval = *_errno();
      }
LABEL_14:
      _unlock(locknum: 7);
      return retval;
    }
  }
  v3 = 22;
  *_errno() = 22;
  _invalid_parameter_noinfo();
LABEL_3:
  retval = v3;
  goto LABEL_14;
}

//------------------------------------------------------------------------------
// Address: 0x1003FF20
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1003FF29
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x1003FF3C
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp+0h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1003FF56
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003FFD0
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x1003FFFD
// Name: _vfscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl vfscanf(
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        _iobuf *stream,
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  int v6; // eax
  ioinfo *v7; // ecx
  ioinfo *v8; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( stream != nullptr && format != nullptr )
  {
    _lock_file(pf: stream);
    if ( (stream->_flag & 0x40) == 0 )
    {
      v6 = _fileno(stream);
      if ( v6 == -1 || v6 == -2 )
        v7 = &__badioinfo;
      else
        v7 = &__pioinfo[v6 >> 5][v6 & 0x1F];
      if ( (*((_BYTE *)v7 + 36) & 0x7F) != 0
        || (v6 == -1 || v6 == -2 ? (v8 = &__badioinfo) : (v8 = &__pioinfo[v6 >> 5][v6 & 0x1F]), *((char *)v8 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
      retval = inputfn(a1: stream, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100400F7
// Name: _fscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fscanf(_iobuf *stream, const char *format, ...)
{
  va_list arglist; // [esp+10h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vfscanf(inputfn: _input_l, stream, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x10040117
// Name: __snprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snprintf(char *string, unsigned int count, const char *format, ...)
{
  int result; // eax
  int v4; // edi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+3Ch] [ebp+14h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr = 0;
      return v4;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100401C3
// Name: init_namebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl init_namebuf(char *flag)
{
  unsigned int v1; // edi
  char *v2; // esi
  _BYTE *v3; // eax
  char *v4; // eax
  DWORD v5; // eax
  char *v6; // [esp-Ch] [ebp-18h]
  unsigned int v7; // [esp-8h] [ebp-14h]
  int v8; // [esp-4h] [ebp-10h]

  v1 = 0;
  if ( flag != nullptr )
  {
    if ( flag == (char *)1 )
    {
      v2 = tmpfile_buf;
    }
    else
    {
      if ( flag != (char *)2 )
      {
        v2 = flag;
        goto LABEL_10;
      }
      v2 = tmpnam_s_buf;
    }
    v8 = 18;
  }
  else
  {
    v2 = tmpnam_buf;
    v8 = 14;
  }
  v1 = v8;
LABEL_10:
  if ( strcpy_s(_Dst: v2, _SizeInBytes: v1, _Src: "\\") != 0 )
    goto LABEL_19;
  v3 = v2 + 1;
  if ( *v2 != 92 && *v2 != 47 )
  {
    *v3 = 92;
    v3 = v2 + 2;
  }
  *v3 = flag == (char *)1 ? 116 : 115;
  v4 = v3 + 1;
  v7 = v1 + v2 - v4;
  v6 = v4;
  v5 = _getpid();
  if ( _ultoa_s(val: v5, buf: v6, sizeInTChars: v7, radix: 0x20u) != 0
    || strcat_s(_Dst: v2, _SizeInBytes: v1, _Src: ".") != 0 )
  {
LABEL_19:
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004026D
// Name: genfname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl genfname(unsigned int fnameSize, unsigned int tmp_max)
{
  char *fname; // ecx
  char *v3; // edi
  int v4; // eax
  char *v5; // esi
  int result; // eax
  unsigned int v7; // eax
  char pext[8]; // [esp+8h] [ebp-Ch] BYREF

  v3 = fname;
  _mbsrchr(str: (unsigned __int8 *)fname, c: 0x2Eu);
  v5 = (char *)(v4 + 1);
  if ( v4 + 1 >= (unsigned int)v3 && fnameSize > v5 - v3 )
  {
    v7 = strtoul(nptr: v5, endptr: nullptr, ibase: 0x20u) + 1;
    if ( v7 < tmp_max )
    {
      if ( _ultoa_s(val: v7, buf: pext, sizeInTChars: 8u, radix: 0x20u) != 0
        || (result = strcpy_s(_Dst: v5, _SizeInBytes: fnameSize + v3 - v5, _Src: pext)) != 0 )
      {
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      }
    }
    else
    {
      return -1;
    }
  }
  else
  {
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10040305
// Name: __tmpnam_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tmpnam_helper(char *s, unsigned int sz, char *buffer_no, unsigned int tmp_max, char **ret)
{
  char *v6; // edi
  unsigned int v7; // esi
  _tiddata *v8; // eax
  _tiddata *v9; // esi
  char *v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  int *v13; // eax
  int v14; // [esp-4h] [ebp-34h]
  int saved_errno; // [esp+10h] [ebp-20h]
  int retval; // [esp+14h] [ebp-1Ch]

  retval = 0;
  saved_errno = *_errno();
  if ( _mtinitlocknum(locknum: 2) == 0 )
  {
    *ret = nullptr;
    return *_errno();
  }
  _lock(locknum: 2);
  if ( buffer_no != nullptr )
  {
    v6 = tmpnam_s_buf;
    v14 = 18;
  }
  else
  {
    v6 = tmpnam_buf;
    v14 = 14;
  }
  v7 = v14;
  if ( *v6 != 0 )
    goto LABEL_8;
  init_namebuf(flag: buffer_no);
  while ( _access_s(path: v6, amode: 0) == 0 )
  {
LABEL_8:
    if ( genfname(fnameSize: v7, tmp_max) != 0 )
      goto tmpnam_err;
  }
  if ( s != nullptr )
  {
    if ( buffer_no != nullptr )
    {
      strlen(buf: (unsigned __int8 *)v6);
      if ( v12 >= sz )
      {
        retval = 34;
        if ( sz != 0 )
          *s = 0;
        goto tmpnam_err;
      }
    }
    v11 = strcpy_s(_Dst: s, _SizeInBytes: sz, _Src: v6);
    goto LABEL_22;
  }
  v8 = _getptd_noexit();
  v9 = v8;
  if ( v8 != nullptr )
  {
    if ( v8->_namebuf0 != nullptr || (v10 = (char *)_malloc_crt(cb: 0xEu), v9->_namebuf0 = v10, v10 != nullptr) )
    {
      s = v9->_namebuf0;
      v11 = strcpy_s(_Dst: s, _SizeInBytes: 0xEu, _Src: v6);
LABEL_22:
      if ( v11 != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      goto tmpnam_err;
    }
  }
  retval = 12;
tmpnam_err:
  _unlock(locknum: 2);
  *ret = s;
  v13 = _errno();
  if ( retval != 0 )
    *v13 = retval;
  else
    *v13 = saved_errno;
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10040441
// Name: _tmpnam
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl tmpnam(char *s)
{
  char *ret; // [esp+0h] [ebp-4h] BYREF

  ret = nullptr;
  _tmpnam_helper(s, sz: 0xFFFFFFFF, buffer_no: nullptr, tmp_max: 0x7FFFu, &ret);
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x10040468
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftell_nolock(_iobuf *str)
{
  int v3; // eax
  int v4; // esi
  signed int v5; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v9; // ebx
  char *v10; // edx
  int cnt; // edx
  ioinfo **v12; // ebx
  int v13; // esi
  char *v14; // eax
  char *v15; // ecx
  bool v16; // zf
  int bufsiz; // eax
  int v18; // ecx
  unsigned int offset; // [esp+8h] [ebp-Ch]
  int fd; // [esp+Ch] [ebp-8h]
  LONG filepos; // [esp+10h] [ebp-4h]
  unsigned int rdcnt; // [esp+1Ch] [ebp+8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = _fileno(stream: str);
  v4 = v3;
  fd = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v5 = _lseek(fh: v3, pos: 0, mthd: 1u);
  filepos = v5;
  if ( v5 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v5 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  v9 = (char *)(str->_ptr - base);
  offset = (unsigned int)v9;
  if ( (flag & 3) != 0 )
  {
    if ( __pioinfo[v4 >> 5][v4 & 0x1F].osfile < 0 )
    {
      v10 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v10 == 10 )
            ++v9;
          ++v10;
        }
        while ( v10 < ptr );
        offset = (unsigned int)v9;
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( filepos == 0 )
    return (int)v9;
  if ( (str->_flag & 1) == 0 )
    return filepos + offset;
  cnt = str->_cnt;
  if ( cnt != 0 )
  {
    v12 = &__pioinfo[fd >> 5];
    rdcnt = cnt + ptr - base;
    v13 = (fd & 0x1F) << 6;
    if ( *(&(*v12)->osfile + v13) >= 0 )
    {
LABEL_39:
      filepos -= rdcnt;
      return filepos + offset;
    }
    if ( _lseek(fh: fd, pos: 0, mthd: 2u) == filepos )
    {
      v14 = str->_base;
      v15 = &v14[rdcnt];
      while ( v14 < v15 )
      {
        if ( *v14 == 10 )
          ++rdcnt;
        ++v14;
      }
      v16 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v16 )
        ++rdcnt;
      goto LABEL_39;
    }
    if ( (_lseek(fh: fd, pos: filepos, mthd: 0) & 0x80000000) == 0 )
    {
      bufsiz = 512;
      if ( rdcnt > 0x200 || ((v18 = str->_flag) & 8) == 0 || (v18 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      rdcnt = bufsiz;
      v16 = (*(&(*v12)->osfile + v13) & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  offset = 0;
  return filepos + offset;
}

//------------------------------------------------------------------------------
// Address: 0x100405FC
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ftell(_iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ftell_nolock(str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040661
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _CRT_INIT(void *hDllHandle, unsigned int dwReason, void *lpreserved)
{
  _tiddata *v4; // eax
  _tiddata *v5; // esi
  int (__stdcall *v6)(unsigned int, _tiddata *); // eax
  unsigned int v7; // [esp-8h] [ebp-30h]
  _tiddata *v8; // [esp-4h] [ebp-2Ch]

  if ( dwReason == 1 )
  {
    if ( _heap_init() == 0 )
      return 0;
    if ( _mtinit() == 0 )
    {
LABEL_5:
      _heap_term();
      return 0;
    }
    _RTC_Initialize();
    _acmdln = GetCommandLineA();
    _aenvptr = __crtGetEnvironmentStringsA();
    if ( _ioinit() < 0 )
    {
LABEL_7:
      _mtterm();
      goto LABEL_5;
    }
    if ( _setargv() < 0 || _setenvp() < 0 || _cinit(initFloatingPrecision: 0) != 0 )
    {
      _ioterm();
      goto LABEL_7;
    }
    ++_proc_attached;
  }
  else if ( dwReason != 0 )
  {
    if ( dwReason == 2 )
    {
      __set_flsgetvalue();
      v4 = (_tiddata *)_calloc_crt(count: 1u, size: 0x214u);
      v5 = v4;
      if ( v4 == nullptr )
        return 0;
      v8 = v4;
      v7 = __flsindex;
      v6 = (int (__stdcall *)(unsigned int, _tiddata *))DecodePointer(Ptr: gpFlsSetValue);
      if ( v6(a1: v7, a2: v8) == 0 )
      {
        free(pBlock: v5);
        return 0;
      }
      _initptd(ptd: v5, ptloci: nullptr);
      v5->_tid = GetCurrentThreadId();
      v5->_thandle = -1;
    }
    else if ( dwReason == 3 )
    {
      _freeptd(ptd: nullptr);
    }
  }
  else
  {
    if ( _proc_attached <= 0 )
      return 0;
    --_proc_attached;
    if ( _C_Termination_Done == 0 )
      _cexit();
    if ( lpreserved == nullptr )
    {
      _ioterm();
      _mtterm();
      _heap_term();
      if ( __flsindex != -1 )
        _mtterm();
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100407C5
// Name: __DllMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _DllMainCRTStartup(void *lpreserved, unsigned int dwReason, HINSTANCE hDllHandle)
{
  BOOL v5; // eax
  int retcode; // [esp+10h] [ebp-1Ch]

  if ( dwReason == 0 && _proc_attached == 0
    || (dwReason == 1 || dwReason == 2) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
  {
    return 0;
  }
  v5 = DllMain(hinstDLL: hDllHandle, fdwReason: dwReason, lpvReserved: lpreserved);
  retcode = v5;
  if ( dwReason == 1 && !v5 )
  {
    DllMain(hinstDLL: hDllHandle, fdwReason: 0, lpvReserved: lpreserved);
    _CRT_INIT(hDllHandle, dwReason: 0, lpreserved);
  }
  if ( (dwReason == 0 || dwReason == 3) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
    return 0;
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x100408BB
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    __security_init_cookie();
  return _DllMainCRTStartup(lpreserved: lpReserved, dwReason: fdwReason, hDllHandle: hinstDLL);
}

//------------------------------------------------------------------------------
// Address: 0x100408E0
// Name: _acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl acos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x1004CC08);
  }
  JUMPOUT(0x1004096F);
}

//------------------------------------------------------------------------------
// Address: 0x10040920
// Name: __CIacos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIacos(int a1, int a2)
{
  int v3; // eax
  bool v4; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIacos;
  v3 = _mm_getcsr() & 0x7F80;
  v4 = v3 == 8064;
  if ( v3 == 8064 )
    v4 = (v5 & 0x7F) == 127;
  if ( v4 )
    _CIacos_pentium4();
  else
__CIacos:
    _CIacos_default(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1004095B
// Name: __CIacos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10040A30
// Name: _asin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl asin(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x1004D528);
  }
  JUMPOUT(0x10040ABF);
}

//------------------------------------------------------------------------------
// Address: 0x10040A70
// Name: __CIasin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIasin(int a1, int a2)
{
  int v3; // eax
  bool v4; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIasin;
  v3 = _mm_getcsr() & 0x7F80;
  v4 = v3 == 8064;
  if ( v3 == 8064 )
    v4 = (v5 & 0x7F) == 127;
  if ( v4 )
    _CIasin_pentium4();
  else
__CIasin:
    _CIasin_default(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10040AAB
// Name: __CIasin_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10040B80
// Name: _fmod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl fmod(double X, double Y)
{
  double v2; // st6
  double v3; // st7
  double result; // st7

  _ctrandisp2(a1: v2, a2: v3, parm1: *(unsigned __int64 *)&X, parm2: *(unsigned __int64 *)&Y);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10040B8A
// Name: __CIfmod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _CIfmod@<st0>(double x@<st0>, double y@<st1>, __int16 a3@<fpstat>)
{
  double result; // st7

  _cintrindisp2(a1: (int)&_OP_FMODjmptab, a2: a3, a3: y, a4: x);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10040B94
// Name: fFMOD
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall fFMOD@<st0>(long double a1@<st1>, long double a2@<st0>)
{
  long double v4; // st7
  char v6; // c2

  v4 = a1;
  do
    a2 = __FPREM__(a2, v4);
  while ( v6 != 0 );
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10040BB0
// Name: _pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl pow(double X, double Y)
{
  int v2; // eax
  bool v3; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v2 = _mm_getcsr() & 0x7F80;
    v3 = v2 == 8064;
    if ( v2 == 8064 )
      v3 = (v5 & 0x7F) == 127;
    if ( v3 )
      JUMPOUT(0x1004DD29);
  }
  JUMPOUT(0x10040C44);
}

//------------------------------------------------------------------------------
// Address: 0x10040BF0
// Name: __CIpow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIpow(int a1, int a2, int a3, int a4)
{
  int v6; // eax
  bool v7; // zf
  char v8; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIpow;
  v6 = _mm_getcsr() & 0x7F80;
  v7 = v6 == 8064;
  if ( v6 == 8064 )
    v7 = (v8 & 0x7F) == 127;
  if ( v7 )
    _CIpow_pentium4();
  else
__CIpow:
    _CIpow_default(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x10040C2B
// Name: __CIpow_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIpow_default()
{
  JUMPOUT(0x10040C4D);
}

//------------------------------------------------------------------------------
// Address: 0x10040E3A
// Name: ___libm_sse2_sin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_sin@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(X, 3) & 0x7FF0) != 0x7FF0 )
    return sin(X: *(double *)X.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10040FF2
// Name: ___libm_sse2_atan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_atan2()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10041508
// Name: _srand
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl srand(unsigned int seed)
{
  _getptd()->_holdrand = seed;
}

//------------------------------------------------------------------------------
// Address: 0x1004151A
// Name: ___libm_sse2_pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_pow()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10041F92
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pBlock: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x10041FB2
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _tolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+18h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+1Ch] [ebp-4h] BYREF
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pclmap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x100420C7
// Name: _tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl tolower(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _tolower_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 65 <= 0x19 )
    return c + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042100
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  char *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  const char *v9; // esi
  char v10; // bl
  size_t v11; // ecx
  int v12; // edx
  char v13; // dl
  int v15; // eax

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Destination;
  if ( ((unsigned __int8)Destination & 3) == 0 )
    goto find_end_of_front_string_loop;
  do
  {
    v5 = *v4++;
    if ( v5 == 0 )
    {
start_byte_3:
      v8 = v4 - 1;
      goto copy_start;
    }
  }
  while ( ((unsigned __int8)v4 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_front_string_loop:
      v6 = (*(_DWORD *)v4 + 2130640639) ^ ~*(_DWORD *)v4;
      v4 += 4;
    }
    while ( (v6 & 0x81010100) == 0 );
    v7 = *((_DWORD *)v4 - 1);
    if ( (_BYTE)v7 == 0 )
      break;
    if ( BYTE1(v7) == 0 )
    {
      v8 = v4 - 3;
      goto copy_start;
    }
    if ( (v7 & 0xFF0000) == 0 )
    {
      v8 = v4 - 2;
      goto copy_start;
    }
    if ( (v7 & 0xFF000000) == 0 )
      goto start_byte_3;
  }
  v8 = v4 - 4;
copy_start:
  v9 = Source;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v10 = Count;
    v11 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance;
tail_loop_start:
    v3 = v10 & 3;
    if ( (v10 & 3) != 0 )
    {
      while ( 1 )
      {
        v13 = *v9++;
        *v8++ = v13;
        if ( v13 == 0 )
          break;
        if ( --v3 == 0 )
          goto empty_counter;
      }
    }
    else
    {
empty_counter:
      *v8 = v3;
    }
    return Destination;
  }
  do
  {
    LOBYTE(v12) = *v9++;
    if ( (_BYTE)v12 == 0 )
    {
LABEL_26:
      *v8 = v12;
      return Destination;
    }
    *v8++ = v12;
    if ( --v3 == 0 )
      goto empty_counter;
  }
  while ( ((unsigned __int8)v9 & 3) != 0 );
  v10 = v3;
  v11 = v3 >> 2;
  if ( v11 == 0 )
    goto tail_loop_start;
  while ( 1 )
  {
main_loop_entrance:
    v15 = (*(_DWORD *)v9 + 2130640639) ^ ~*(_DWORD *)v9;
    v12 = *(_DWORD *)v9;
    v9 += 4;
    if ( (v15 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        goto LABEL_26;
      if ( BYTE1(v12) == 0 )
        break;
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_WORD *)v8 = v12;
        v8[2] = 0;
        return Destination;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v8 = v12;
        return Destination;
      }
    }
    *(_DWORD *)v8 = v12;
    v8 += 4;
    if ( --v11 == 0 )
      goto tail_loop_start;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x10042240
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown_0+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 10042299 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100425A1
// Name: __chdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chdir(const char *path)
{
  char *v1; // esi
  signed int CurrentDirectoryA; // eax
  DWORD v4; // edi
  char *v5; // eax
  char v6; // al
  DWORD LastError; // eax
  int memfree; // [esp+4h] [ebp-118h]
  int retval; // [esp+8h] [ebp-114h]
  char env_var[4]; // [esp+Ch] [ebp-110h] BYREF
  char abspath[264]; // [esp+10h] [ebp-10Ch] BYREF

  memfree = 0;
  retval = -1;
  v1 = abspath;
  if ( path == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( !SetCurrentDirectoryA(lpPathName: path) )
    goto LABEL_14;
  CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x105u, lpBuffer: abspath);
  v4 = CurrentDirectoryA;
  if ( CurrentDirectoryA > 260 )
  {
    v5 = (char *)_calloc_crt(count: CurrentDirectoryA + 1, size: 1u);
    v1 = v5;
    if ( v5 == nullptr || (memfree = 1, v4 == 0) )
    {
LABEL_14:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      goto LABEL_15;
    }
    v4 = GetCurrentDirectoryA(nBufferLength: v4 + 1, lpBuffer: v5);
  }
  if ( v4 == 0 )
    goto LABEL_14;
  if ( (v6 = *v1, *v1 != 92) && v6 != 47 || v6 != v1[1] )
  {
    env_var[0] = 61;
    env_var[1] = _mbctoupper(c: (unsigned __int8)*v1);
    strcpy(&env_var[2], ":");
    if ( !SetEnvironmentVariableA(lpName: env_var, lpValue: v1) )
      goto LABEL_14;
  }
  retval = 0;
LABEL_15:
  if ( memfree != 0 )
    free(pBlock: v1);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x100426CA
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isleadbyte_l(unsigned __int8 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _loc_update.localeinfo.locinfo->pctype[c] & 0x8000;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042702
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isleadbyte(unsigned __int8 c)
{
  return _isleadbyte_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10042720
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance_0;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start_0:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance_0:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start_0;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x10042850
// Name: __alldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldiv(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v8 = v7 / (unsigned int)v6;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    v5 = v8;
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    LODWORD(v5) = v4 / (unsigned int)a2;
    HIDWORD(v5) = HIDWORD(a1) / (unsigned int)a2;
  }
  if ( v2 == 1 )
    return -v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100428FA
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  const char *v3; // esi
  int v5; // eax
  _flt *v6; // eax
  _flt *v7; // ecx
  int flags; // eax
  long double v9; // st7
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-34h] BYREF
  long double tmp; // [esp+1Ch] [ebp-24h]
  _flt answerstruct; // [esp+24h] [ebp-1Ch] BYREF

  v3 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
       ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v3] & 8
       : _isctype_l(c: *(unsigned __int8 *)v3, mask: 8, plocinfo: &_loc_update.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  v6 = _fltin2(flt: &answerstruct, str: v3, _Locale: &_loc_update.localeinfo);
  v7 = v6;
  if ( endptr != nullptr )
    *endptr = (char *)&v3[v6->nbytes];
  flags = v6->flags;
  if ( (v7->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr != nullptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v9 = _HUGE;
    if ( *v3 == 45 )
      v9 = -_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v9 = 0.0, 0.0 != v7->dval) )
  {
    tmp = v7->dval;
    goto LABEL_24;
  }
  tmp = v9;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x10042A1D
// Name: _strtod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl strtod(char *nptr, char **endptr)
{
  return _strtod_l(nptr, endptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10042A34
// Name: __wtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wtol(const wchar_t *nptr)
{
  return wcstol(nptr, endptr: nullptr, ibase: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x10042A4A
// Name: __wtoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wtoi(const wchar_t *nptr)
{
  return _wtol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x10042A55
// Name: __time64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __cdecl _time64(__int64 *timeptr)
{
  __int64 result; // rax
  FT nt_time; // [esp+0h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&nt_time);
  result = (nt_time.ft_scalar - 116444736000000000LL) / 0x989680;
  if ( result > 0x793406FFFLL )
    result = -1;
  if ( timeptr != nullptr )
    *timeptr = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042AA6
// Name: _fgets
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fgets(_iobuf *string, int count, _iobuf *str)
{
  char *v3; // edi
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  int v9; // eax
  char *retval; // [esp+18h] [ebp-1Ch]

  v3 = (char *)string;
  retval = (char *)string;
  if ( string == nullptr && count != 0 || count < 0 || str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  if ( count == 0 )
    return nullptr;
  _lock_file(pf: str);
  if ( (str->_flag & 0x40) == 0 )
  {
    v5 = _fileno(stream: str);
    if ( v5 == -1 || v5 == -2 )
      v6 = &__badioinfo;
    else
      v6 = &__pioinfo[v5 >> 5][v5 & 0x1F];
    if ( (*((_BYTE *)v6 + 36) & 0x7F) != 0
      || (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = &__pioinfo[v5 >> 5][v5 & 0x1F]), *((char *)v7 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      retval = nullptr;
    }
  }
  if ( retval != nullptr )
  {
    do
    {
      if ( --count == 0 )
        break;
      if ( --str->_cnt < 0 )
        v9 = _filbuf(str);
      else
        v9 = *(unsigned __int8 *)str->_ptr++;
      if ( v9 == -1 )
      {
        if ( v3 == (char *)string )
        {
          retval = nullptr;
          goto done_1;
        }
        break;
      }
      *v3++ = v9;
    }
    while ( (_BYTE)v9 != 10 );
    *v3 = 0;
  }
done_1:
  _unlock_file(pf: str);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10042BDE
// Name: __access_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access_s(const char *path, int amode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  if ( path == nullptr || (amode & 0xFFFFFFF9) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  FileAttributesA = GetFileAttributesA(lpFileName: path);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return *_errno();
  }
  if ( (FileAttributesA & 0x10) == 0 && (FileAttributesA & 1) != 0 && (amode & 2) != 0 )
  {
    *__doserrno() = 5;
    *_errno() = 13;
    return *_errno();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10042C5D
// Name: _access
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl access(const char *path, int amode)
{
  return -(_access_s(path, amode) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10042C80
// Name: _memchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memchr(unsigned __int8 *buf, unsigned __int8 chr, unsigned int cnt)
{
  unsigned int v3; // eax
  unsigned __int8 *v4; // edx
  int v5; // ebx
  unsigned __int8 v6; // cl
  bool v7; // cf
  unsigned int v8; // eax
  unsigned int i; // eax
  unsigned __int8 v10; // cl
  int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx

  v3 = cnt;
  if ( cnt != 0 )
  {
    v4 = buf;
    LOBYTE(v5) = chr;
    if ( ((unsigned __int8)buf & 3) != 0 )
    {
      while ( 1 )
      {
        v6 = *v4++;
        if ( chr == v6 )
          break;
        if ( --v3 == 0 )
          break;
        if ( ((unsigned __int8)v4 & 3) == 0 )
          goto main_loop_start_0;
      }
    }
    else
    {
main_loop_start_0:
      v7 = v3 < 4;
      v8 = v3 - 4;
      if ( v7 )
      {
tail_less_then_4:
        for ( i = v8 + 4; i != 0; --i )
        {
          v10 = *v4++;
          if ( (unsigned __int8)v5 == v10 )
            break;
        }
      }
      else
      {
        v5 = 16843009 * chr;
        while ( 1 )
        {
          v11 = v5 ^ *(_DWORD *)v4;
          v4 += 4;
          if ( (((v11 + 2130640639) ^ ~v11) & 0x81010100) != 0 )
          {
            v12 = *((_DWORD *)v4 - 1);
            LOBYTE(v12) = chr ^ v12;
            if ( (_BYTE)v12 == 0 )
              break;
            BYTE1(v12) ^= chr;
            if ( BYTE1(v12) == 0 )
              break;
            v13 = HIWORD(v12);
            if ( chr == (unsigned __int8)v13 || chr == BYTE1(v13) )
              break;
          }
          v7 = v8 < 4;
          v8 -= 4;
          if ( v7 )
            goto tail_less_then_4;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042D2D
// Name: _putenv_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl putenv_helper(char *name, const char *value)
{
  const CHAR *v3; // edi
  int v4; // eax
  int v5; // eax
  unsigned int v6; // esi
  char *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // esi
  char *v11; // eax
  int v12; // edi
  int v13; // eax
  unsigned __int16 *v14; // eax
  int v15; // eax
  char *newoption; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 *woption; // [esp+8h] [ebp-4h] BYREF

  newoption = nullptr;
  if ( __env_initialized == 0 )
    return -1;
  v3 = name;
  if ( name == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( value != nullptr )
  {
    v8 = strnlen(str: name, maxsize: 0x7FFFu);
    v9 = strnlen(str: value, maxsize: 0x7FFFu);
    if ( v8 < 0x7FFF && v9 < 0x7FFF )
    {
      v10 = v9 + v8 + 2;
      v11 = (char *)_calloc_crt(count: v10, size: 1u);
      newoption = v11;
      if ( v11 != nullptr )
      {
        strcpy_s(_Dst: v11, _SizeInBytes: v10, _Src: name);
        newoption[v8] = 61;
        strcpy_s(_Dst: &newoption[v8 + 1], _SizeInBytes: v10 - (v8 + 1), _Src: value);
        v3 = name;
        goto LABEL_16;
      }
      return -1;
    }
LABEL_13:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _mbschr(string: (unsigned __int8 *)name, c: 0x3Du);
  if ( v4 != 0 && (v4 - (int)name >= 0x7FFF || strnlen(str: (const char *)(v4 + 1), maxsize: 0x7FFFu) >= 0x7FFF) )
    goto LABEL_13;
  strlen(buf: (unsigned __int8 *)name);
  v6 = v5 + 1;
  v7 = (char *)_calloc_crt(count: v5 + 1, size: 1u);
  newoption = v7;
  if ( v7 == nullptr )
    return -1;
  strcpy_s(_Dst: v7, _SizeInBytes: v6, _Src: name);
LABEL_16:
  if ( __crtsetenv(poption: &newoption, primary: 1) != 0 )
  {
    if ( newoption != nullptr )
      free(pBlock: newoption);
    return -1;
  }
  if ( _wenviron == nullptr )
    return 0;
  woption = nullptr;
  v12 = MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: v3,
          cbMultiByte: -1,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  if ( v12 == 0 )
    goto LABEL_29;
  if ( value != nullptr )
  {
    v13 = MultiByteToWideChar(
            CodePage: 0,
            dwFlags: 0,
            lpMultiByteStr: value,
            cbMultiByte: -1,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    if ( v13 == 0 )
    {
LABEL_29:
      *_errno() = 42;
      return -1;
    }
    v12 += v13 + 1;
  }
  v14 = (unsigned __int16 *)_calloc_crt(count: v12, size: 2u);
  woption = v14;
  if ( v14 == nullptr )
    return -1;
  if ( MultiByteToWideChar(
         CodePage: 0,
         dwFlags: 0,
         lpMultiByteStr: name,
         cbMultiByte: -1,
         lpWideCharStr: v14,
         cchWideChar: v12) == 0
    || value != nullptr
    && (v15 = wcslen(wcs: woption),
        woption[v15] = 61,
        MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: value,
          cbMultiByte: -1,
          lpWideCharStr: &woption[v15 + 1],
          cchWideChar: v12 - (v15 + 1)) == 0) )
  {
    free(pBlock: woption);
    goto LABEL_29;
  }
  if ( __crtwsetenv(poption: &woption, primary: 0) != 0 )
  {
    if ( woption != nullptr )
      free(pBlock: woption);
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10042F2A
// Name: __putenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _putenv(char *option)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = putenv_helper(name: option, value: nullptr);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10042F6F
// Name: __spawnv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnv(int modeflag, char *pathname, const char *const *argv)
{
  if ( pathname != nullptr && *pathname != 0 && argv != nullptr && *argv != nullptr && **(_BYTE **)argv != 0 )
    return _spawnve(mode: modeflag, name: pathname, argv, envp: nullptr);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10042FB9
// Name: __localtime64_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _localtime64_s(tm *ptm, const __int64 *ptime)
{
  int result; // eax
  int v3; // eax
  __int64 v4; // kr00_8
  __int64 v5; // kr10_8
  __int64 v6; // kr20_8
  __int64 v7; // rax
  int v8; // ecx
  int v9; // edx
  __int64 ltime; // [esp+8h] [ebp-14h] BYREF
  int dstbias; // [esp+10h] [ebp-Ch] BYREF
  int daylight; // [esp+14h] [ebp-8h] BYREF
  int timezone; // [esp+18h] [ebp-4h] BYREF

  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( ptm == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  memset(dst: (int)ptm, value: (unsigned __int8 *)0xFF, count: sizeof(tm));
  if ( ptime == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  if ( *((int *)ptime + 1) < 0 || *ptime > 0x793406FFFLL )
  {
    *_errno() = 22;
    return 22;
  }
  __tzset();
  if ( _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
    || _get_timezone(_Timezone: &timezone) != 0 )
  {
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  if ( *ptime <= 259200 )
  {
    result = _gmtime64_s(ptm, timp: ptime);
    if ( result == 0 )
    {
      if ( daylight != 0 && _isindst(tb: ptm) != 0 )
      {
        v3 = dstbias + timezone;
        ptm->tm_isdst = 1;
        v4 = ptm->tm_sec - (__int64)v3;
      }
      else
      {
        v4 = ptm->tm_sec - (__int64)timezone;
      }
      ptm->tm_sec = v4 % 60;
      if ( v4 % 60 < 0 )
      {
        ptm->tm_sec = v4 % 60 + 60;
        v4 = __PAIR64__((unsigned int)__CFADD__((_DWORD)v4, -60) + HIDWORD(v4) - 1, (int)v4 - 60);
      }
      v5 = ptm->tm_min + v4 / 60;
      ptm->tm_min = v5 % 60;
      if ( v5 % 60 < 0 )
      {
        ptm->tm_min = v5 % 60 + 60;
        v5 -= 60;
      }
      v6 = ptm->tm_hour + v5 / 60;
      ptm->tm_hour = v6 % 24;
      if ( v6 % 24 < 0 )
      {
        ptm->tm_hour = v6 % 24 + 24;
        v6 -= 24;
      }
      v7 = v6 / 24;
      v8 = v6 / 24;
      if ( (((unsigned __int64)(v6 / 24) >> 32) & 0x80000000) != 0LL )
      {
        HIDWORD(v7) = ((int)v7 + ptm->tm_wday + 7) % 7;
        ptm->tm_mday += v7;
        LODWORD(v7) = ptm->tm_mday;
        ptm->tm_wday = HIDWORD(v7);
        if ( (int)v7 <= 0 )
        {
          ptm->tm_yday += v8 + 365;
          --ptm->tm_year;
          ptm->tm_mday = v7 + 31;
          ptm->tm_mon = 11;
          return 0;
        }
      }
      else
      {
        if ( v7 <= 0 )
          return 0;
        v9 = (v8 + ptm->tm_wday) % 7;
        ptm->tm_mday += v8;
        ptm->tm_wday = v9;
      }
      ptm->tm_yday += v8;
      return 0;
    }
  }
  else
  {
    ltime = *ptime - timezone;
    result = _gmtime64_s(ptm, timp: &ltime);
    if ( result == 0 )
    {
      if ( daylight == 0 || _isindst(tb: ptm) == 0 )
        return 0;
      ltime -= dstbias;
      result = _gmtime64_s(ptm, timp: &ltime);
      if ( result == 0 )
      {
        ptm->tm_isdst = 1;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10043241
// Name: __localtime64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tm *__cdecl _localtime64(const __int64 *ptime)
{
  tm *result; // eax

  result = (tm *)__getgmtimebuf();
  if ( result != nullptr )
    return _localtime64_s(ptm: result, ptime) == 0 ? result : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10043268
// Name: __flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = _fileno(stream: str);
      if ( (char *)_write(fh: v5, buf: v9, cnt: (unsigned int)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100432D0
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fflush_nolock(_iobuf *str)
{
  int v2; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v2 = _fileno(stream: str);
  return -(_commit(filedes: v2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10043318
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl flsall(int flushflag)
{
  int i; // esi
  char **v2; // eax
  char *v3; // eax
  int v4; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = (char **)&__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = *v2;
      if ( (v3[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v3);
        v4 = *((_DWORD *)__piob[i] + 3);
        if ( (v4 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v4 & 2) != 0 && _fflush_nolock(str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100433F2
// Name: _fflush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fflush(_iobuf *stream)
{
  int rc; // [esp+10h] [ebp-1Ch]

  if ( stream == nullptr )
    return flsall(flushflag: 0);
  _lock_file(pf: stream);
  rc = _fflush_nolock(str: stream);
  _unlock_file(pf: stream);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x10043445
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flushall()
{
  return flsall(flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1004344E
// Name: _vfprintf_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl vfprintf_helper(
        int (__cdecl *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        _iobuf *str,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int v6; // eax
  ioinfo *v7; // ecx
  ioinfo *v8; // eax
  int v9; // esi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v6 = _fileno(stream: str);
      if ( v6 == -1 || v6 == -2 )
        v7 = &__badioinfo;
      else
        v7 = &__pioinfo[v6 >> 5][v6 & 0x1F];
      if ( (*((_BYTE *)v7 + 36) & 0x7F) != 0
        || (v6 == -1 || v6 == -2 ? (v8 = &__badioinfo) : (v8 = &__pioinfo[v6 >> 5][v6 & 0x1F]), *((char *)v8 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v9 = _stbuf(str);
      retval = outfn(a1: str, a2: format, a3: plocinfo, a4: ap);
      _ftbuf(flag: v9, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043559
// Name: _vfprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl vfprintf(_iobuf *str, const char *format, char *ap)
{
  return vfprintf_helper(outfn: _output_l, str, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x10043578
// Name: _asctime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl asctime(const tm *tb)
{
  char *asctimebuf; // edi
  _tiddata *v2; // eax
  _tiddata *v3; // esi
  char *v4; // eax
  char *v5; // ecx
  int tm_mon; // edi
  int tm_mday; // edx
  int tm_wday; // eax
  int v10; // edx
  int i; // eax
  char v12; // dl
  char v13; // dl
  char v14; // dl
  char v15; // dl
  char v16; // dl
  int v17; // edx
  char *p; // [esp+10h] [ebp-4h]

  asctimebuf = buf_0;
  p = buf_0;
  v2 = _getptd_noexit();
  v3 = v2;
  if ( v2 != nullptr )
  {
    if ( v2->_asctimebuf != nullptr
      || (v4 = (char *)_calloc_crt(count: 0x1Au, size: 1u), v3->_asctimebuf = v4, v4 != nullptr) )
    {
      asctimebuf = v3->_asctimebuf;
      p = asctimebuf;
    }
  }
  v5 = asctimebuf;
  if ( asctimebuf != nullptr
    && (*asctimebuf = 0, tb != nullptr)
    && tb->tm_year >= 0
    && (unsigned int)(tm_mon = tb->tm_mon) < 0xC
    && tb->tm_hour < 0x18u
    && tb->tm_min < 0x3Cu
    && tb->tm_sec < 0x3Cu
    && (tm_mday = tb->tm_mday) >= 1
    && (dword_1008ACA8[tm_mon] - _days[tm_mon] >= tm_mday
     || ((tb->tm_year + 1900) % 4 == 0 && (tb->tm_year + 1900) % 100 != 0 || (tb->tm_year + 1900) % 400 == 0)
     && tm_mon == 1
     && tb->tm_mday <= 29)
    && (unsigned int)(tm_wday = tb->tm_wday) <= 6 )
  {
    v10 = 3 * tm_wday;
    for ( i = 0; i < 3; ++i )
    {
      *v5 = __dnames[v10 + i];
      p[i + 4] = __mnames[3 * tm_mon + i];
      ++v5;
    }
    *v5 = 32;
    v5[4] = 32;
    v12 = tb->tm_mday % 10;
    v5[5] = tb->tm_mday / 10 + 48;
    v5[6] = v12 + 48;
    v5[7] = 32;
    v13 = tb->tm_hour % 10;
    v5[8] = tb->tm_hour / 10 + 48;
    v5[9] = v13 + 48;
    v5[10] = 58;
    v14 = tb->tm_min % 10;
    v5[11] = tb->tm_min / 10 + 48;
    v5[12] = v14 + 48;
    v5[13] = 58;
    v15 = tb->tm_sec % 10;
    v5[14] = tb->tm_sec / 10 + 48;
    v5[15] = v15 + 48;
    v5[16] = 32;
    v16 = (tb->tm_year / 100 + 19) % 10;
    v5[17] = (tb->tm_year / 100 + 19) / 10 + 48;
    v5[18] = v16 + 48;
    v17 = tb->tm_year % 100;
    v5[19] = v17 / 10 + 48;
    v5[20] = v17 % 10 + 48;
    *(_WORD *)(v5 + 21) = 10;
    return p;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043760
// Name: __aullrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _aullrem(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  bool v7; // cf
  int v8; // ecx
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = HIDWORD(a2) * (v6 / v5);
    v9 = (unsigned int)a2 * (unsigned __int64)(unsigned int)(v6 / v5);
    v7 = __CFADD__(v8, HIDWORD(v9));
    HIDWORD(v9) += v8;
    if ( v7 || v9 > a1 )
      v9 -= a2;
    return a1 - v9;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 % (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100437E0
// Name: __aulldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldvrm(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned __int64 v8; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v3 = v6 / v5;
    v8 = v3 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v3, HIDWORD(v8)) || (HIDWORD(v8) = (a2 * (unsigned __int64)v3) >> 32, v8 > a1) )
      --v3;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 / (unsigned int)a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10043875
// Name: _calloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __cdecl calloc(unsigned int num, unsigned int size)
{
  LPVOID v2; // esi
  int errno_tmp; // [esp+4h] [ebp-4h] BYREF

  errno_tmp = 0;
  v2 = _calloc_impl(num, size, &errno_tmp);
  if ( v2 == nullptr && errno_tmp != 0 && _errno() != nullptr )
    *_errno() = errno_tmp;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100438B5
// Name: ___libm_error_support
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_error_support(
        unsigned __int64 *arg1,
        unsigned __int64 *arg2,
        unsigned __int64 *retval,
        error_types input_tag)
{
  int (__cdecl *v4)(_exception *); // eax
  double *v5; // esi
  unsigned __int64 v6; // st7
  unsigned __int64 *v7; // ecx
  double v8; // st7
  _exception exc; // [esp+0h] [ebp-28h] BYREF
  char double_zero[8]; // [esp+20h] [ebp-8h] BYREF

  memset(double_zero, 0, sizeof(double_zero));
  if ( pmatherr_set != 0 )
    v4 = (int (__cdecl *)(_exception *))DecodePointer(Ptr: _pmatherr);
  else
    v4 = (int (__cdecl *)(_exception *))_matherr;
  if ( input_tag > exp10_overflow )
  {
    switch ( input_tag )
    {
      case log_nan:
        exc.nam = (unsigned int)"log";
        goto LABEL_38;
      case log10_nan:
        exc.nam = (unsigned int)"log10";
        goto LABEL_38;
      case exp_nan:
        exc.nam = (unsigned int)"exp";
        goto LABEL_38;
      case atan_nan:
        exc.nam = (unsigned int)"atan";
        goto LABEL_38;
      case ceil_nan:
        exc.nam = (unsigned int)"ceil";
        goto LABEL_38;
      case floor_nan:
        exc.nam = (unsigned int)"floor";
        goto LABEL_38;
      case pow_nan:
        goto $LN36;
      case modf_nan:
        exc.nam = (unsigned int)"modf";
        goto LABEL_38;
      case acos_nan:
        goto $LN30_0;
      case asin_nan:
        goto $LN8_10;
      case sin_naninf:
        exc.nam = (unsigned int)"sin";
        goto LABEL_54;
      case cos_naninf:
        exc.nam = (unsigned int)"cos";
        goto LABEL_54;
      case tan_naninf:
        exc.nam = (unsigned int)"tan";
LABEL_54:
        v5 = (double *)retval;
        v8 = *(double *)arg1 * *(double *)double_zero;
        *(double *)retval = v8;
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        goto LABEL_55;
      default:
        return;
    }
  }
  if ( input_tag == exp10_overflow )
  {
    exc.typ = 3;
    exc.nam = (unsigned int)"exp10";
LABEL_17:
    v5 = (double *)retval;
    exc.arg1 = *arg1;
    exc.arg2 = *arg2;
    exc.retval = *retval;
    if ( v4(a1: &exc) == 0 )
      *_errno() = 34;
    goto LABEL_57;
  }
  if ( input_tag > pow_underflow )
  {
    switch ( input_tag )
    {
      case pow_zero_to_zero:
        *(double *)retval = 1.0;
        return;
      case pow_zero_to_negative:
        exc.typ = 2;
LABEL_16:
        exc.nam = (unsigned int)"pow";
        goto LABEL_17;
      case pow_neg_to_non_integer:
$LN36:
        exc.nam = (unsigned int)"pow";
        break;
      case pow_nan_to_zero:
        exc.nam = (unsigned int)"pow";
LABEL_38:
        v7 = arg1;
        v5 = (double *)retval;
        *retval = *arg1;
LABEL_24:
        exc.arg1 = *v7;
        exc.arg2 = *arg2;
        v8 = *v5;
LABEL_55:
        *(double *)&exc.retval = v8;
        exc.typ = 1;
        if ( v4(a1: &exc) == 0 )
          *_errno() = 33;
        goto LABEL_57;
      case acos_gt_one:
$LN30_0:
        exc.nam = (unsigned int)"acos";
        break;
      case asin_gt_one:
$LN8_10:
        exc.nam = (unsigned int)"asin";
        break;
      default:
        return;
    }
LABEL_23:
    v7 = arg1;
    v5 = (double *)retval;
    goto LABEL_24;
  }
  switch ( input_tag )
  {
    case pow_underflow:
      exc.nam = (unsigned int)"pow";
      goto LABEL_20;
    case log_zero:
      exc.typ = 2;
      exc.nam = (unsigned int)"log";
      goto LABEL_17;
    case log_negative:
      exc.nam = (unsigned int)"log";
      goto LABEL_23;
    case log10_zero:
      exc.typ = 2;
      exc.nam = (unsigned int)"log10";
      goto LABEL_17;
    case log10_negative:
      exc.nam = (unsigned int)"log10";
      goto LABEL_23;
    case exp_overflow:
      exc.typ = 3;
      exc.nam = (unsigned int)"exp";
      goto LABEL_17;
    default:
      break;
  }
  if ( input_tag != exp_underflow )
  {
    if ( input_tag != pow_overflow )
      return;
    exc.typ = 3;
    goto LABEL_16;
  }
  exc.nam = (unsigned int)"exp";
LABEL_20:
  v5 = (double *)retval;
  exc.arg1 = *arg1;
  exc.arg2 = *arg2;
  v6 = *retval;
  exc.typ = 4;
  exc.retval = v6;
  v4(a1: &exc);
LABEL_57:
  *v5 = *(double *)&exc.retval;
}

//------------------------------------------------------------------------------
// Address: 0x10043B81
// Name: __sse2_mathfcns_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sse2_mathfcns_init()
{
  __use_sse2_mathfcns = IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10043B91
// Name: __ceil_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _ceil_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v1 = _ctrlfp();
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp();
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xCu, x, savedcw: v1);
    }
    return _except1(a1: (int)&savedregs, flags: 8, opcode: 12, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp();
      return v4;
    }
    else
    {
      return _except1(a1: (int)&savedregs, flags: 16, opcode: 12, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043C69
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  char *v2; // esi
  bool i; // zf
  char v4; // al
  char *v5; // esi
  char v6; // cl
  char v7; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buffer;
  for ( i = tolower(c: *buffer) == 101; !i; i = isdigit(c: (unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower(c: *v2) == 120 )
    v2 += 2;
  v4 = *v2;
  *v2 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = v4;
    v4 = v6;
    v7 = *v5++;
  }
  while ( v7 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x10043CDD
// Name: __cropzeros_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char *v2; // eax
  char i; // cl
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *v7; // edx
  char v8; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buf;
  for ( i = *buf; *v2 != 0; i = *++v2 )
  {
    if ( i == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *v5;
      if ( *v5 == 0 || v6 == 101 || v6 == 69 )
        break;
      ++v5;
    }
    v7 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v8 = *v7;
      ++v5;
      ++v7;
      *v5 = v8;
    }
    while ( v8 != 0 );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x10043D5F
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _positive(long double *arg)
{
  return *arg >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10043D7B
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign_l(_CRT_FLOAT flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE doubletemp; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) != 0 )
  {
    _atodbl_l(d: &doubletemp, str: number, plocinfo);
    *(_CRT_DOUBLE *)argument = doubletemp;
  }
  else
  {
    _atoflt_l(d: &flag, str: number, plocinfo);
    *(_CRT_FLOAT *)argument = flag;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043DBD
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign(int flag, char *argument, char *number)
{
  _fassign_l((_CRT_FLOAT)flag, argument, number, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10043DD7
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(char *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist != 0 )
  {
    strlen(buf: (unsigned __int8 *)s);
    memmove(dst: (unsigned __int8 *)&s[dist], src: (unsigned __int8 *)s, count: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043DF6
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt(char *buffer)
{
  _forcdecpt_l(buffer, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10043E09
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros(char *buf)
{
  _cropzeros_l(buf, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10043E1C
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int *v8; // eax
  int v10; // eax
  char *v11; // esi
  threadlocaleinfostruct *locinfo; // eax
  char *v13; // esi
  unsigned int v14; // ebx
  int v15; // eax
  int v16; // [esp-4h] [ebp-1Ch]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v16 = 22;
LABEL_3:
    *v8 = v16;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v16;
  }
  if ( ndec <= 0 )
    v10 = 0;
  else
    v10 = ndec;
  if ( sizeInBytes <= v10 + 9 )
  {
    v8 = _errno();
    v16 = 34;
    goto LABEL_3;
  }
  if ( g_fmt != 0 )
    shift(s: &buf[pflt->sign == 45], dist: ndec > 0);
  v11 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v11 = buf + 1;
  }
  if ( ndec > 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    *v11 = v11[1];
    *++v11 = *locinfo->lconv->decimal_point;
  }
  v13 = &v11[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v14 = -1;
  else
    v14 = sizeInBytes + buf - v13;
  if ( strcpy_s(_Dst: v13, _SizeInBytes: v14, _Src: "e+000") != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( caps != 0 )
    *v13 = 69;
  if ( *pflt->mantissa != 48 )
  {
    v15 = pflt->decpt - 1;
    if ( v15 < 0 )
    {
      v15 = 1 - pflt->decpt;
      v13[1] = 45;
    }
    if ( v15 >= 100 )
    {
      v13[2] += v15 / 100;
      v15 %= 100;
    }
    if ( v15 >= 10 )
    {
      v13[3] += v15 / 10;
      LOBYTE(v15) = v15 % 10;
    }
    v13[4] += v15;
  }
  if ( (_outputformat & 1) != 0 && v13[2] == 48 )
    memmove(dst: (unsigned __int8 *)v13 + 2, src: (unsigned __int8 *)v13 + 3, count: 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10043F7D
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - (retstrflt.sign == 45) - (ndec > 0);
    result = _fptostr(
               buf: &buf[(retstrflt.sign == 45) + (ndec > 0)],
               sizeInBytes: v7,
               digits: ndec + 1,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10044044
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, int caps)
{
  return _cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10044064
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoa_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v6; // esi
  int *v7; // eax
  int result; // eax
  unsigned int v9; // eax
  bool v10; // zf
  _BYTE *v11; // eax
  char *v12; // esi
  char *v13; // eax
  char *v14; // esi
  int x_low; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  char *i; // eax
  __int64 v19; // rax
  __int64 v20; // rcx
  _BYTE *v21; // esi
  _BYTE *v22; // edi
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rcx
  __int64 v28; // [esp-Ch] [ebp-38h]
  int v29; // [esp-4h] [ebp-30h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-24h] BYREF
  __int64 exponent; // [esp+18h] [ebp-14h]
  unsigned __int64 mask; // [esp+20h] [ebp-Ch]
  int maskpos; // [esp+28h] [ebp-4h]
  char *pos; // [esp+38h] [ebp+Ch]

  LODWORD(exponent) = 1023;
  maskpos = 48;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v6 = buf;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v7 = _errno();
    v29 = 22;
LABEL_5:
    *v7 = v29;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v29;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v7 = _errno();
    v29 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v9 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v9 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf: buf + 2, sizeInBytes: v9, ndec, caps: 0);
    if ( result != 0 )
    {
      v10 = !_loc_update.updated;
      *buf = 0;
      if ( !v10 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    strrchr(string: (unsigned __int8 *)v6 + 2, chr: 0x65u);
    if ( v11 != nullptr )
    {
      *v11 = caps == 0 ? 112 : 80;
      v11[3] = 0;
    }
  }
  else
  {
    if ( (HIDWORD(pvalue->x) & 0x80000000) != 0 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      v6[2] = 49;
      v12 = v6 + 3;
    }
    else
    {
      v6[2] = 48;
      v12 = v6 + 3;
      if ( (HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x)) != 0 )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v13 = v12;
    v14 = v12 + 1;
    pos = v13;
    if ( ndec != 0 )
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v13 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(mask) != 0 || x_low != 0 )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        v16 = (unsigned __int16)(((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48);
        if ( v16 > 0x39 )
          LOBYTE(v16) = (caps != 0 ? 7 : 39) + ((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48;
        v17 = HIDWORD(mask);
        maskpos -= 4;
        *v14++ = v16;
        --ndec;
        mask = __PAIR64__(v17, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0
        && (unsigned __int16)((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) > 8u )
      {
        for ( i = v14 - 1; *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == pos )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = caps != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( ndec > 0 )
    {
      memset(dst: (int)v14, value: (unsigned __int8 *)0x30, count: ndec);
      v14 += ndec;
    }
    if ( *pos == 0 )
      v14 = pos;
    *v14 = caps == 0 ? 112 : 80;
    HIDWORD(v20) = 0;
    v19 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v19 < 0 )
    {
      v14[1] = 45;
      v21 = v14 + 2;
      v19 = -v19;
    }
    else
    {
      v14[1] = 43;
      v21 = v14 + 2;
    }
    v22 = v21;
    *v21 = 48;
    if ( v19 >= 0 )
    {
      LODWORD(v20) = 1000;
      if ( v19 >= 1000 )
      {
        v28 = v20;
        v24 = v19 % v20;
        v23 = v19 / v28;
        *v21++ = v23 + 48;
        HIDWORD(exponent) = HIDWORD(v23);
        v19 = v24;
        if ( v21 != v22 )
          goto LABEL_60;
      }
    }
    if ( v19 >= 100 )
    {
LABEL_60:
      v26 = v19 % 100;
      v25 = v19 / 100;
      *v21 = v25 + 48;
      HIDWORD(exponent) = HIDWORD(v25);
      ++v21;
      v19 = v26;
    }
    if ( v21 != v22 || v19 >= 10 )
    {
      v27 = v19 % 10;
      *v21++ = v19 / 10 + 48;
      LOBYTE(v19) = v19 % 10;
      HIDWORD(exponent) = HIDWORD(v27);
    }
    *v21 = v19 + 48;
    v21[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100443DA
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftof2_l@<eax>(
        char *buf@<ecx>,
        _strflt *pflt@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v8; // esi
  char *v10; // esi
  int decpt; // eax
  int v12; // eax
  unsigned __int8 *v13; // esi
  int v14; // eax
  int v15; // edi
  int v16; // edi
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( g_fmt != 0 && v8 == ndec )
      *(_WORD *)&buf[v8 + (pflt->sign == 45)] = 48;
    v10 = buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v10 = buf + 1;
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = (unsigned __int8 *)&v10[decpt];
    }
    else
    {
      strlen(buf: (unsigned __int8 *)v10);
      memmove(dst: (unsigned __int8 *)v10 + 1, src: (unsigned __int8 *)v10, count: v12 + 1);
      *v10 = 48;
      v13 = (unsigned __int8 *)(v10 + 1);
    }
    if ( ndec > 0 )
    {
      strlen(buf: v13);
      memmove(dst: v13 + 1, src: v13, count: v14 + 1);
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      v15 = pflt->decpt;
      if ( v15 < 0 )
      {
        v16 = -v15;
        if ( g_fmt != 0 || ndec >= v16 )
          ndec = v16;
        shift(s: (char *)v13 + 1, dist: ndec);
        memset(dst: (int)(v13 + 1), value: (unsigned __int8 *)0x30, count: ndec);
      }
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100444DD
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    v6 = -1;
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (retstrflt.sign == 45);
    result = _fptostr(
               buf: &buf[retstrflt.sign == 45],
               sizeInBytes: v6,
               digits: ndec + retstrflt.decpt,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004459E
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  BOOL v9; // eax
  char *v10; // edi
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    v8 = retstrflt.decpt - 1;
    v9 = retstrflt.sign == 45;
    v10 = &buf[v9];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v9;
    result = _fptostr(buf: v10, sizeInBytes: v7, digits: ndec, pflt: &retstrflt);
    if ( result != 0 )
    {
      *buf = 0;
    }
    else if ( retstrflt.decpt - 1 < -4 || retstrflt.decpt - 1 >= ndec )
    {
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 1, plocinfo);
    }
    else
    {
      if ( v8 < retstrflt.decpt - 1 )
        v10[strlen(v10) - 1] = 0;
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10044759
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _setdefaultprecision()
{
  int result; // eax

  result = _controlfp_s(_CurrentState: nullptr, newctrl: 0x10000u, mask: 0x30000u);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10044781
// Name: __floor_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _floor_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v1 = _ctrlfp();
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp();
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xBu, x, savedcw: v1);
    }
    return _except1(a1: (int)&savedregs, flags: 8, opcode: 11, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp();
      return v4;
    }
    else
    {
      return _except1(a1: (int)&savedregs, flags: 16, opcode: 11, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044859
// Name: CPtoLCID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CPtoLCID@<eax>(int codepage@<eax>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax

  v1 = codepage - 932;
  if ( v1 == 0 )
    return 1041;
  v2 = v1 - 4;
  if ( v2 == 0 )
    return 2052;
  v3 = v2 - 13;
  if ( v3 == 0 )
    return 1042;
  if ( v3 == 1 )
    return 1028;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044888
// Name: setSBCS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBCS(threadmbcinfostruct *ptmbci@<eax>)
{
  unsigned __int8 *mbctype; // eax
  int v3; // ecx
  int i; // edi
  unsigned __int8 *mbcasemap; // eax
  int j; // esi

  memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
  ptmbci->mbcodepage = 0;
  ptmbci->ismbcodepage = 0;
  ptmbci->mblcid = 0;
  *(_DWORD *)ptmbci->mbulinfo = 0;
  *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
  *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
  mbctype = ptmbci->mbctype;
  v3 = (char *)&__initialmbcinfo - (char *)ptmbci;
  for ( i = 257; i != 0; --i )
  {
    *mbctype = mbctype[v3];
    ++mbctype;
  }
  mbcasemap = ptmbci->mbcasemap;
  for ( j = 256; j != 0; --j )
  {
    *mbcasemap = mbcasemap[v3];
    ++mbcasemap;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100448EC
// Name: setSBUpLow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBUpLow(threadmbcinfostruct *ptmbci@<esi>)
{
  unsigned int i; // eax
  unsigned __int8 v2; // al
  unsigned __int8 *v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // eax
  unsigned __int16 v7; // cx
  unsigned __int8 v8; // cl
  unsigned int v9; // ecx
  unsigned __int8 *v10; // eax
  unsigned __int8 v11; // dl
  int v12; // [esp+8h] [ebp-51Ch]
  _cpinfo cpinfo; // [esp+Ch] [ebp-518h] BYREF
  unsigned __int16 wVector[256]; // [esp+20h] [ebp-504h] BYREF
  unsigned __int8 upVector[256]; // [esp+220h] [ebp-304h] BYREF
  unsigned __int8 lowVector[256]; // [esp+320h] [ebp-204h] BYREF
  unsigned __int8 sbVector[256]; // [esp+420h] [ebp-104h] BYREF

  if ( GetCPInfo(CodePage: ptmbci->mbcodepage, lpCPInfo: &cpinfo) )
  {
    for ( i = 0; i < 0x100; ++i )
      sbVector[i] = i;
    v2 = cpinfo.LeadByte[0];
    sbVector[0] = 32;
    if ( cpinfo.LeadByte[0] != 0 )
    {
      v3 = &cpinfo.LeadByte[1];
      do
      {
        v4 = v2;
        v5 = *v3;
        if ( v4 <= v5 )
          memset(dst: (int)&sbVector[v4], value: (unsigned __int8 *)0x20, count: v5 - v4 + 1);
        v2 = v3[1];
        v3 += 2;
      }
      while ( v2 != 0 );
    }
    __crtGetStringTypeA(
      plocinfo: nullptr,
      dwInfoType: 1u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpCharType: wVector,
      code_page: ptmbci->mbcodepage,
      lcid: ptmbci->mblcid,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x100u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)lowVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x200u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)upVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    v6 = 0;
    while ( 1 )
    {
      v7 = wVector[v6];
      if ( (v7 & 1) != 0 )
      {
        ptmbci->mbctype[v6 + 1] |= 0x10u;
        v8 = lowVector[v6];
      }
      else
      {
        if ( (v7 & 2) == 0 )
        {
          ptmbci->mbcasemap[v6] = 0;
          goto LABEL_16;
        }
        ptmbci->mbctype[v6 + 1] |= 0x20u;
        v8 = upVector[v6];
      }
      ptmbci->mbcasemap[v6] = v8;
LABEL_16:
      if ( (unsigned int)++v6 >= 0x100 )
        return;
    }
  }
  v9 = 0;
  v12 = -97 - (_DWORD)ptmbci->mbcasemap;
  do
  {
    v10 = &ptmbci->mbcasemap[v9];
    if ( (unsigned int)&v10[v12 + 32] <= 0x19 )
    {
      ptmbci->mbctype[v9 + 1] |= 0x10u;
      v11 = v9 + 32;
LABEL_23:
      *v10 = v11;
      goto LABEL_25;
    }
    if ( (unsigned int)&v10[v12] <= 0x19 )
    {
      ptmbci->mbctype[v9 + 1] |= 0x20u;
      v11 = v9 - 32;
      goto LABEL_23;
    }
    *v10 = 0;
LABEL_25:
    ++v9;
  }
  while ( v9 < 0x100 );
}

//------------------------------------------------------------------------------
// Address: 0x10044A7C
// Name: ___updatetmbcinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadmbcinfostruct *__cdecl __updatetmbcinfo()
{
  _tiddata *v0; // edi
  threadmbcinfostruct *ptmbcinfo; // esi

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptmbcinfo = v0->ptmbcinfo;
  }
  else
  {
    _lock(locknum: 13);
    ptmbcinfo = v0->ptmbcinfo;
    if ( ptmbcinfo != __ptmbcinfo )
    {
      if ( ptmbcinfo != nullptr
        && InterlockedDecrement(lpAddend: &ptmbcinfo->refcount) == 0
        && ptmbcinfo != &__initialmbcinfo )
      {
        free(pBlock: ptmbcinfo);
      }
      v0->ptmbcinfo = __ptmbcinfo;
      ptmbcinfo = __ptmbcinfo;
      InterlockedIncrement(lpAddend: &__ptmbcinfo->refcount);
    }
    _unlock(locknum: 13);
  }
  if ( ptmbcinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptmbcinfo;
}

//------------------------------------------------------------------------------
// Address: 0x10044B20
// Name: getSystemCP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT __usercall getSystemCP@<eax>(int codepage@<esi>)
{
  UINT result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: nullptr);
  fSystemSet = 0;
  switch ( codepage )
  {
    case -2:
      fSystemSet = 1;
      result = GetOEMCP();
      goto LABEL_3;
    case -3:
      fSystemSet = 1;
      result = GetACP();
      goto LABEL_3;
    case -4:
      result = _loc_update.localeinfo.locinfo->lc_codepage;
      fSystemSet = 1;
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    default:
      break;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return codepage;
}

//------------------------------------------------------------------------------
// Address: 0x10044B9C
// Name: __setmbcp_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp_nolock(int codepage, threadmbcinfostruct *ptmbci)
{
  UINT SystemCP; // edi
  unsigned int i; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // cl
  unsigned int k; // eax
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned __int16 *mbulinfo; // eax
  int v12; // ecx
  unsigned __int16 *v13; // ecx
  int j; // edx
  unsigned __int8 *v15; // eax
  int m; // ecx
  int v17; // edx
  unsigned int irg; // [esp+Ch] [ebp-20h]
  unsigned int icp; // [esp+10h] [ebp-1Ch]
  unsigned int icpa; // [esp+10h] [ebp-1Ch]
  _cpinfo cpinfo; // [esp+14h] [ebp-18h] BYREF
  int codepagea; // [esp+34h] [ebp+8h]

  SystemCP = getSystemCP(codepage);
  codepagea = SystemCP;
  if ( SystemCP != 0 )
  {
    icp = 0;
    for ( i = 0; i < 5; ++i )
    {
      if ( _rgcode_page_info[i].code_page == SystemCP )
      {
        memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
        irg = 0;
        v8 = _rgcode_page_info[icp].rgrange[0];
        icpa = (unsigned int)v8;
        do
        {
          while ( *v8 != 0 )
          {
            LOBYTE(v9) = v8[1];
            if ( (_BYTE)v9 == 0 )
              break;
            v10 = *v8;
            v9 = (unsigned __int8)v9;
            while ( v10 <= v9 )
            {
              ptmbci->mbctype[v10 + 1] |= _rgctypeflag[irg];
              v9 = v8[1];
              ++v10;
            }
            SystemCP = codepagea;
            v8 += 2;
          }
          ++irg;
          v8 = (unsigned __int8 *)(icpa + 8);
          icpa += 8;
        }
        while ( irg < 4 );
        ptmbci->mbcodepage = SystemCP;
        ptmbci->ismbcodepage = 1;
        ptmbci->mblcid = CPtoLCID(codepage: SystemCP);
        mbulinfo = ptmbci->mbulinfo;
        v13 = (unsigned __int16 *)((char *)_rgcode_page_info[0].mbulinfo + v12);
        for ( j = 6; j != 0; --j )
          *mbulinfo++ = *v13++;
LABEL_26:
        setSBUpLow(ptmbci);
        return 0;
      }
      ++icp;
    }
    if ( SystemCP == 65000 || SystemCP == 65001 || !IsValidCodePage(CodePage: (unsigned __int16)SystemCP) )
      return -1;
    if ( GetCPInfo(CodePage: SystemCP, lpCPInfo: &cpinfo) )
    {
      memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
      ptmbci->mbcodepage = SystemCP;
      ptmbci->mblcid = 0;
      if ( cpinfo.MaxCharSize <= 1 )
      {
        ptmbci->ismbcodepage = 0;
      }
      else
      {
        if ( cpinfo.LeadByte[0] != 0 )
        {
          v5 = &cpinfo.LeadByte[1];
          do
          {
            v6 = *v5;
            if ( *v5 == 0 )
              break;
            for ( k = *(v5 - 1); k <= v6; ++k )
              ptmbci->mbctype[k + 1] |= 4u;
            v5 += 2;
          }
          while ( *(v5 - 1) != 0 );
        }
        v15 = &ptmbci->mbctype[2];
        for ( m = 254; m != 0; --m )
          *v15++ |= 8u;
        ptmbci->mblcid = CPtoLCID(codepage: ptmbci->mbcodepage);
        ptmbci->ismbcodepage = v17;
      }
      *(_DWORD *)ptmbci->mbulinfo = 0;
      *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
      *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
      goto LABEL_26;
    }
    if ( fSystemSet == 0 )
      return -1;
  }
  setSBCS(ptmbci);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044D85
// Name: __setmbcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp(int codepage)
{
  _tiddata *v1; // edi
  threadmbcinfostruct *ptmbcinfo; // ebx
  threadmbcinfostruct *v3; // eax
  threadmbcinfostruct *v4; // ebx
  int v5; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  int retcode; // [esp+14h] [ebp-20h]
  UINT codepagea; // [esp+3Ch] [ebp+8h]

  retcode = -1;
  v1 = _getptd();
  __updatetmbcinfo();
  ptmbcinfo = v1->ptmbcinfo;
  codepagea = getSystemCP(codepage);
  if ( codepagea == ptmbcinfo->mbcodepage )
    return 0;
  v3 = (threadmbcinfostruct *)_malloc_crt(cb: 0x220u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    qmemcpy(v3, v1->ptmbcinfo, sizeof(threadmbcinfostruct));
    v3->refcount = 0;
    v5 = _setmbcp_nolock(codepage: codepagea, ptmbci: v3);
    retcode = v5;
    if ( v5 != 0 )
    {
      if ( v5 == -1 )
      {
        if ( v4 != &__initialmbcinfo )
          free(pBlock: v4);
        *_errno() = 22;
      }
    }
    else
    {
      if ( InterlockedDecrement(lpAddend: &v1->ptmbcinfo->refcount) == 0 && v1->ptmbcinfo != &__initialmbcinfo )
        free(pBlock: v1->ptmbcinfo);
      v1->ptmbcinfo = v4;
      InterlockedIncrement(lpAddend: &v4->refcount);
      if ( (v1->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
      {
        _lock(locknum: 13);
        __mbcodepage = v4->mbcodepage;
        __ismbcodepage = v4->ismbcodepage;
        __mblcid = v4->mblcid;
        for ( i = 0; i < 5; ++i )
          __mbulinfo[i] = v4->mbulinfo[i];
        for ( j = 0; j < 257; ++j )
          _mbctype[j] = v4->mbctype[j];
        for ( k = 0; k < 256; ++k )
          _mbcasemap[k] = v4->mbcasemap[k];
        if ( InterlockedDecrement(lpAddend: &__ptmbcinfo->refcount) == 0 && __ptmbcinfo != &__initialmbcinfo )
          free(pBlock: __ptmbcinfo);
        __ptmbcinfo = v4;
        InterlockedIncrement(lpAddend: &v4->refcount);
        _unlock(locknum: 13);
      }
    }
  }
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x10044F1F
// Name: ___initmbctable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initmbctable()
{
  if ( __mbctype_initialized == 0 )
  {
    _setmbcp(codepage: -3);
    __mbctype_initialized = 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044F3D
// Name: ___addlocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __addlocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int ptlocia; // [esp+14h] [ebp+8h]

  InterlockedIncrement(lpAddend: &ptloci->refcount);
  if ( ptloci->lconv_intl_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_intl_refcount);
  if ( ptloci->lconv_mon_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_mon_refcount);
  if ( ptloci->lconv_num_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_num_refcount);
  if ( ptloci->ctype1_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->ctype1_refcount);
  p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
  for ( ptlocia = 6; ptlocia != 0; --ptlocia )
  {
    if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
      InterlockedIncrement(lpAddend: *p_refcount);
    if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
      InterlockedIncrement(lpAddend: p_refcount[1]);
    p_refcount += 4;
  }
  InterlockedIncrement(lpAddend: &ptloci->lc_time_curr->refcount);
}

//------------------------------------------------------------------------------
// Address: 0x10044FCC
// Name: ___removelocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __removelocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int ptlocia; // [esp+Ch] [ebp+8h]

  if ( ptloci != nullptr )
  {
    InterlockedDecrement(lpAddend: &ptloci->refcount);
    if ( ptloci->lconv_intl_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_intl_refcount);
    if ( ptloci->lconv_mon_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_mon_refcount);
    if ( ptloci->lconv_num_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_num_refcount);
    if ( ptloci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->ctype1_refcount);
    p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
    for ( ptlocia = 6; ptlocia != 0; --ptlocia )
    {
      if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
        InterlockedDecrement(lpAddend: *p_refcount);
      if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
        InterlockedDecrement(lpAddend: p_refcount[1]);
      p_refcount += 4;
    }
    InterlockedDecrement(lpAddend: &ptloci->lc_time_curr->refcount);
  }
  return ptloci;
}

//------------------------------------------------------------------------------
// Address: 0x10045065
// Name: ___freetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __freetlocinfo(threadlocaleinfostruct *ptloci)
{
  lconv *lconv; // eax
  int *lconv_intl_refcount; // eax
  int *lconv_mon_refcount; // eax
  int *lconv_num_refcount; // eax
  int *ctype1_refcount; // eax
  __lc_time_data *lc_time_curr; // eax
  void **p_refcount; // edi
  _DWORD *v9; // eax
  int ptlocia; // [esp+14h] [ebp+8h]

  lconv = ptloci->lconv;
  if ( lconv != nullptr && lconv != &__lconv_c )
  {
    lconv_intl_refcount = ptloci->lconv_intl_refcount;
    if ( lconv_intl_refcount != nullptr && *lconv_intl_refcount == 0 )
    {
      lconv_mon_refcount = ptloci->lconv_mon_refcount;
      if ( lconv_mon_refcount != nullptr && *lconv_mon_refcount == 0 )
      {
        free(pBlock: ptloci->lconv_mon_refcount);
        __free_lconv_mon(l: ptloci->lconv);
      }
      lconv_num_refcount = ptloci->lconv_num_refcount;
      if ( lconv_num_refcount != nullptr && *lconv_num_refcount == 0 )
      {
        free(pBlock: ptloci->lconv_num_refcount);
        __free_lconv_num(l: ptloci->lconv);
      }
      free(pBlock: ptloci->lconv_intl_refcount);
      free(pBlock: ptloci->lconv);
    }
  }
  ctype1_refcount = ptloci->ctype1_refcount;
  if ( ctype1_refcount != nullptr && *ctype1_refcount == 0 )
  {
    free(pBlock: ptloci->ctype1 - 127);
    free(pBlock: (void *)(ptloci->pclmap - 128));
    free(pBlock: (void *)(ptloci->pcumap - 128));
    free(pBlock: ptloci->ctype1_refcount);
  }
  lc_time_curr = ptloci->lc_time_curr;
  if ( lc_time_curr != &__lc_time_c && lc_time_curr->refcount == 0 )
  {
    __free_lc_time(lc_time: ptloci->lc_time_curr);
    free(pBlock: ptloci->lc_time_curr);
  }
  p_refcount = (void **)&ptloci->lc_category[0].refcount;
  for ( ptlocia = 6; ptlocia != 0; --ptlocia )
  {
    if ( *(p_refcount - 2) != __clocalestr && *p_refcount != nullptr && *(_DWORD *)*p_refcount == 0 )
      free(pBlock: *p_refcount);
    if ( *(p_refcount - 1) != nullptr )
    {
      v9 = p_refcount[1];
      if ( v9 != nullptr && *v9 == 0 )
        free(pBlock: p_refcount[1]);
    }
    p_refcount += 4;
  }
  free(pBlock: ptloci);
}

//------------------------------------------------------------------------------
// Address: 0x100451B0
// Name: __updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl _updatetlocinfoEx_nolock(
        threadlocaleinfostruct **pptlocid,
        threadlocaleinfostruct *ptlocis)
{
  threadlocaleinfostruct *v2; // esi

  if ( ptlocis == nullptr || pptlocid == nullptr )
    return nullptr;
  v2 = *pptlocid;
  if ( *pptlocid != ptlocis )
  {
    *pptlocid = ptlocis;
    __addlocaleref(ptloci: ptlocis);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: v2);
      if ( v2->refcount == 0 && v2 != &__initiallocinfo )
        __freetlocinfo(ptloci: v2);
    }
  }
  return ptlocis;
}

//------------------------------------------------------------------------------
// Address: 0x100451FD
// Name: ___updatetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __updatetlocinfo()
{
  _tiddata *v0; // esi
  threadlocaleinfostruct *ptlocinfo; // esi
  threadlocaleinfostruct *ptloci; // [esp+10h] [ebp-1Ch]

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptlocinfo = _getptd()->ptlocinfo;
  }
  else
  {
    _lock(locknum: 12);
    ptloci = _updatetlocinfoEx_nolock(pptlocid: &v0->ptlocinfo, ptlocis: __ptlocinfo);
    _unlock(locknum: 12);
    ptlocinfo = ptloci;
  }
  if ( ptlocinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptlocinfo;
}

//------------------------------------------------------------------------------
// Address: 0x10045276
// Name: __encoded_null
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID _encoded_null()
{
  return EncodePointer(Ptr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1004527F
// Name: __crtTlsAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall __crtTlsAlloc(void (__stdcall *lpCallBack)(void *))
{
  return TlsAlloc();
}

//------------------------------------------------------------------------------
// Address: 0x10045288
// Name: ___set_flsgetvalue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__set_flsgetvalue()
{
  void *Value; // esi

  Value = TlsGetValue(dwTlsIndex: __getvalueindex);
  if ( Value == nullptr )
  {
    Value = DecodePointer(Ptr: gpFlsGetValue);
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: Value);
  }
  return Value;
}

//------------------------------------------------------------------------------
// Address: 0x100452BC
// Name: __mtterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mtterm()
{
  void (__stdcall *v0)(unsigned int); // eax
  unsigned int v1; // [esp-4h] [ebp-4h]

  if ( __flsindex != -1 )
  {
    v1 = __flsindex;
    v0 = (void (__stdcall *)(unsigned int))DecodePointer(Ptr: gpFlsFree);
    v0(a1: v1);
    __flsindex = -1;
  }
  if ( __getvalueindex != -1 )
  {
    TlsFree(dwTlsIndex: __getvalueindex);
    __getvalueindex = -1;
  }
  _mtdeletelocks();
}

//------------------------------------------------------------------------------
// Address: 0x100452F9
// Name: __initptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initptd(_tiddata *ptd, threadlocaleinfostruct *ptloci)
{
  int savedregs; // [esp+28h] [ebp+0h]

  GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  ptd->_pxcptacttab = (void *)_XcptActTab;
  ptd->_terrno = 0;
  ptd->_holdrand = 1;
  ptd->_ownlocale = 1;
  ptd->_setloc_data._cachein[0] = 67;
  ptd->_setloc_data._cacheout[0] = 67;
  ptd->ptmbcinfo = &__initialmbcinfo;
  _lock(locknum: 13);
  InterlockedIncrement(lpAddend: &ptd->ptmbcinfo->refcount);
  _unlock(locknum: 13);
  _lock(locknum: 12);
  ptd->ptlocinfo = ptloci;
  if ( ptloci == nullptr )
    ptd->ptlocinfo = __ptlocinfo;
  __addlocaleref(ptloci: ptd->ptlocinfo);
  savedregs = 268718991;
  _unlock(locknum: 12);
}

//------------------------------------------------------------------------------
// Address: 0x100453AD
// Name: __getptd_noexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd_noexit()
{
  DWORD LastError; // eax
  DWORD v1; // edi
  int (__stdcall *v2)(unsigned int); // eax
  _tiddata *v3; // esi
  _tiddata *v4; // eax
  int (__stdcall *v5)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v8; // [esp-8h] [ebp-10h]
  unsigned int v9; // [esp-4h] [ebp-Ch]
  _tiddata *v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = __flsindex;
  v1 = LastError;
  v2 = (int (__stdcall *)(unsigned int))__set_flsgetvalue();
  v3 = (_tiddata *)v2(a1: v9);
  if ( v3 == nullptr )
  {
    v4 = (_tiddata *)_calloc_crt(count: 1u, size: 0x214u);
    v3 = v4;
    if ( v4 != nullptr )
    {
      v10 = v4;
      v8 = __flsindex;
      v5 = (int (__stdcall *)(unsigned int, _tiddata *))DecodePointer(Ptr: gpFlsSetValue);
      if ( v5(a1: v8, a2: v10) != 0 )
      {
        _initptd(ptd: v3, ptloci: nullptr);
        CurrentThreadId = GetCurrentThreadId();
        v3->_thandle = -1;
        v3->_tid = CurrentThreadId;
      }
      else
      {
        free(pBlock: v3);
        v3 = nullptr;
      }
    }
  }
  SetLastError(dwErrCode: v1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10045426
// Name: __getptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd()
{
  _tiddata *result; // eax

  result = _getptd_noexit();
  if ( result == nullptr )
    _amsg_exit(rterrnum: 16);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045440
// Name: _freefls(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _freefls(void *data)
{
  threadmbcinfostruct *v1; // edi
  threadlocaleinfostruct *v2; // edi
  int savedregs; // [esp+28h] [ebp+0h]

  if ( data != nullptr )
  {
    if ( *((_DWORD *)data + 9) != 0 )
      free(pBlock: *((void **)data + 9));
    if ( *((_DWORD *)data + 11) != 0 )
      free(pBlock: *((void **)data + 11));
    if ( *((_DWORD *)data + 13) != 0 )
      free(pBlock: *((void **)data + 13));
    if ( *((_DWORD *)data + 15) != 0 )
      free(pBlock: *((void **)data + 15));
    if ( *((_DWORD *)data + 16) != 0 )
      free(pBlock: *((void **)data + 16));
    if ( *((_DWORD *)data + 17) != 0 )
      free(pBlock: *((void **)data + 17));
    if ( *((_DWORD *)data + 18) != 0 )
      free(pBlock: *((void **)data + 18));
    if ( *((const _XCPT_ACTION **)data + 23) != _XcptActTab )
      free(pBlock: *((void **)data + 23));
    _lock(locknum: 13);
    v1 = *((threadmbcinfostruct **)data + 26);
    if ( v1 != nullptr && InterlockedDecrement(lpAddend: *((volatile LONG **)data + 26)) == 0 && v1 != &__initialmbcinfo )
      free(pBlock: v1);
    _unlock(locknum: 13);
    _lock(locknum: 12);
    v2 = *((threadlocaleinfostruct **)data + 27);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: *((threadlocaleinfostruct **)data + 27));
      if ( v2 != __ptlocinfo && v2 != &__initiallocinfo && v2->refcount == 0 )
        __freetlocinfo(ptloci: v2);
    }
    savedregs = 268719432;
    _unlock(locknum: 12);
    free(pBlock: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004556F
// Name: __freeptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freeptd(_tiddata *ptd)
{
  int (__stdcall *Value)(unsigned int); // eax
  void (__stdcall *v2)(unsigned int, _DWORD); // eax
  unsigned int v3; // [esp-8h] [ebp-8h]
  unsigned int v4; // [esp-8h] [ebp-8h]

  if ( __flsindex != -1 )
  {
    if ( ptd == nullptr && TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr )
    {
      v3 = __flsindex;
      Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex);
      ptd = (_tiddata *)Value(a1: v3);
    }
    v4 = __flsindex;
    v2 = (void (__stdcall *)(unsigned int, _DWORD))DecodePointer(Ptr: gpFlsSetValue);
    v2(a1: v4, a2: 0);
    _freefls(data: ptd);
  }
  if ( __getvalueindex != -1 )
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100455DD
// Name: __mtinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinit()
{
  HMODULE ModuleHandleW; // eax
  HMODULE v1; // edi
  BOOL (__stdcall *FlsFree)(DWORD); // eax
  DWORD v4; // eax
  int (__stdcall *v5)(_DWORD); // eax
  _tiddata *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v10; // [esp-Ch] [ebp-10h]
  _tiddata *v11; // [esp-8h] [ebp-Ch]

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  v1 = ModuleHandleW;
  if ( ModuleHandleW == nullptr )
  {
    _mtterm();
    return 0;
  }
  gpFlsAlloc = GetProcAddress(hModule: ModuleHandleW, lpProcName: "FlsAlloc");
  gpFlsGetValue = GetProcAddress(hModule: v1, lpProcName: "FlsGetValue");
  gpFlsSetValue = GetProcAddress(hModule: v1, lpProcName: "FlsSetValue");
  FlsFree = (BOOL (__stdcall *)(DWORD))GetProcAddress(hModule: v1, lpProcName: "FlsFree");
  gpFlsFree = FlsFree;
  if ( gpFlsAlloc == nullptr || gpFlsGetValue == nullptr || gpFlsSetValue == nullptr || FlsFree == nullptr )
  {
    gpFlsGetValue = TlsGetValue;
    gpFlsAlloc = __crtTlsAlloc;
    gpFlsSetValue = TlsSetValue;
    gpFlsFree = TlsFree;
  }
  v4 = TlsAlloc();
  __getvalueindex = v4;
  if ( v4 != -1 && TlsSetValue(dwTlsIndex: v4, lpTlsValue: gpFlsGetValue) )
  {
    _init_pointers();
    gpFlsAlloc = EncodePointer(Ptr: gpFlsAlloc);
    gpFlsGetValue = EncodePointer(Ptr: gpFlsGetValue);
    gpFlsSetValue = EncodePointer(Ptr: gpFlsSetValue);
    gpFlsFree = EncodePointer(Ptr: gpFlsFree);
    if ( _mtinitlocks() != 0 )
    {
      v5 = (int (__stdcall *)(_DWORD))DecodePointer(Ptr: gpFlsAlloc);
      __flsindex = v5(a1: _freefls);
      if ( __flsindex != -1 )
      {
        v6 = (_tiddata *)_calloc_crt(count: 1u, size: 0x214u);
        v7 = v6;
        if ( v6 != nullptr )
        {
          v11 = v6;
          v10 = __flsindex;
          v8 = (int (__stdcall *)(unsigned int, _tiddata *))DecodePointer(Ptr: gpFlsSetValue);
          if ( v8(a1: v10, a2: v11) != 0 )
          {
            _initptd(ptd: v7, ptloci: nullptr);
            CurrentThreadId = GetCurrentThreadId();
            v7->_thandle = -1;
            v7->_tid = CurrentThreadId;
            return 1;
          }
        }
      }
    }
    _mtterm();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10045758
// Name: __isctype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isctype_l(int c, int mask, localeinfo_struct *plocinfo)
{
  __int16 v3; // bx
  int v4; // eax
  int v5; // ecx
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char buffer[4]; // [esp+14h] [ebp-8h] BYREF
  unsigned __int16 chartype; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = c;
  if ( (unsigned int)(c + 1) <= 0x100 )
  {
    v4 = _loc_update.localeinfo.locinfo->pctype[c];
    goto LABEL_11;
  }
  ca = c >> 8;
  if ( _isleadbyte_l(c: HIBYTE(v3), plocinfo: &_loc_update.localeinfo) != 0 )
  {
    buffer[0] = ca;
    buffer[1] = v3;
    buffer[2] = 0;
    v5 = 2;
  }
  else
  {
    buffer[0] = v3;
    buffer[1] = 0;
    v5 = 1;
  }
  if ( __crtGetStringTypeA(
         plocinfo: &_loc_update.localeinfo,
         dwInfoType: 1u,
         lpSrcStr: buffer,
         cchSrc: v5,
         lpCharType: &chartype,
         code_page: _loc_update.localeinfo.locinfo->lc_codepage,
         lcid: _loc_update.localeinfo.locinfo->lc_handle[2],
         bError: 1) != 0 )
  {
    v4 = chartype;
LABEL_11:
    result = mask & v4;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10045810
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg(void *enull)
{
  __pInvalidArgHandler = enull;
}

//------------------------------------------------------------------------------
// Address: 0x1004581F
// Name: __call_reportfault
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _call_reportfault(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        unsigned int nDbgHookCode,
        unsigned int dwExceptionCode,
        unsigned int dwExceptionFlags)
{
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // kr00_4
  BOOL v8; // edi
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+8h] [ebp-328h] BYREF
  _EXCEPTION_RECORD ExceptionRecord; // [esp+10h] [ebp-320h] BYREF
  _CONTEXT ContextRecord; // [esp+60h] [ebp-2D0h] BYREF
  unsigned int savedregs; // [esp+330h] [ebp+0h]
  void *retaddr; // [esp+334h] [ebp+4h] BYREF

  if ( nDbgHookCode != -1 )
    _crt_debugger_hook();
  memset(dst: (int)&ExceptionRecord.ExceptionFlags, value: nullptr, count: 0x4Cu);
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionPointers.ContextRecord = &ContextRecord;
  ContextRecord.Eax = (unsigned int)&ContextRecord;
  ContextRecord.Ecx = v5;
  ContextRecord.Edx = v6;
  ContextRecord.Ebx = nDbgHookCode;
  ContextRecord.Esi = a2;
  ContextRecord.Edi = a1;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v7 = __readeflags();
  ContextRecord.EFlags = v7;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Ebp = savedregs;
  ExceptionRecord.ExceptionCode = dwExceptionCode;
  ExceptionRecord.ExceptionFlags = dwExceptionFlags;
  ExceptionRecord.ExceptionAddress = retaddr;
  v8 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers) == 0 && !v8 && nDbgHookCode != -1 )
    _crt_debugger_hook();
}

//------------------------------------------------------------------------------
// Address: 0x10045948
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(unsigned int a1@<edi>)
{
  HANDLE CurrentProcess; // eax

  _call_reportfault(a1, a2: 0xC0000417, nDbgHookCode: 2u, dwExceptionCode: 0xC0000417, dwExceptionFlags: 1u);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000417);
}

//------------------------------------------------------------------------------
// Address: 0x1004596D
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(unsigned int a1@<edi>)
{
  void (*v1)(void); // eax

  v1 = (void (*)(void))DecodePointer(Ptr: __pInvalidArgHandler);
  if ( v1 == nullptr )
    _invoke_watson(a1);
  v1();
}

//------------------------------------------------------------------------------
// Address: 0x1004599A
// Name: __invalid_parameter_noinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invalid_parameter_noinfo()
{
  unsigned int v0; // edi

  _invalid_parameter(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x100459AA
// Name: __VEC_memzero
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__fastcall _VEC_memzero(_BYTE *a1, unsigned int a2)
{
  int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  char *result; // eax
  unsigned int v6; // edx
  char v7; // al
  unsigned int k; // edx
  int i; // edx
  unsigned int j; // ebx
  unsigned int v11; // [esp-4h] [ebp-Ch]

  v2 = (unsigned __int8)a1 & 0xF;
  if ( ((unsigned __int8)a1 & 0xF) != 0 )
  {
    v11 = a2 - (16 - v2);
    for ( i = (16 - (_BYTE)v2) & 3; i != 0; --i )
      *a1++ = 0;
    for ( j = (unsigned int)(16 - v2) >> 2; j != 0; --j )
    {
      *(_DWORD *)a1 = 0;
      a1 += 4;
    }
    a2 = v11;
  }
  v3 = a2;
  v4 = a2 & 0x7F;
  for ( result = (char *)(v3 >> 7); result != nullptr; --result )
  {
    *(_OWORD *)a1 = 0;
    *((_OWORD *)a1 + 1) = 0;
    *((_OWORD *)a1 + 2) = 0;
    *((_OWORD *)a1 + 3) = 0;
    *((_OWORD *)a1 + 4) = 0;
    *((_OWORD *)a1 + 5) = 0;
    *((_OWORD *)a1 + 6) = 0;
    *((_OWORD *)a1 + 7) = 0;
    a1 += 128;
  }
  if ( v4 != 0 )
  {
    result = (char *)(v4 >> 4);
    if ( v4 >> 4 != 0 )
    {
      do
      {
        *(_OWORD *)a1 = 0;
        a1 += 16;
        --result;
      }
      while ( result != nullptr );
    }
    v6 = v4 & 0xF;
    if ( v6 != 0 )
    {
      v7 = v6;
      for ( k = v6 >> 2; k != 0; --k )
      {
        *(_DWORD *)a1 = 0;
        a1 += 4;
      }
      for ( result = (char *)(v7 & 3); result != nullptr; --result )
        *a1++ = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045A64
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __sse2_available_init()
{
  __sse2_available = IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10045A74
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  _crtheap = HeapCreate(flOptions: 0, dwInitialSize: 0x1000u, dwMaximumSize: 0);
  return _crtheap != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10045A92
// Name: __heap_term
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _heap_term()
{
  BOOL result; // eax

  result = HeapDestroy(hHeap: _crtheap);
  _crtheap = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045AA6
// Name: __GET_RTERRMSG
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const wchar_t *__cdecl _GET_RTERRMSG(int rterrnum)
{
  int v1; // eax

  v1 = 0;
  while ( rterrnum != rterrs[v1].rterrno )
  {
    if ( (unsigned int)++v1 >= 0x16 )
      return nullptr;
  }
  return rterrs[v1].rterrtxt;
}

//------------------------------------------------------------------------------
// Address: 0x10045ACC
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  const wchar_t *v1; // edi
  int v2; // eax
  HANDLE StdHandle; // eax
  void *v4; // esi
  unsigned int i; // eax
  DWORD v6; // eax
  unsigned int bytes_written; // [esp+Ch] [ebp-1FCh] BYREF
  char buffer[500]; // [esp+10h] [ebp-1F8h] BYREF

  v1 = _GET_RTERRMSG(rterrnum);
  bytes_written = (unsigned int)v1;
  if ( v1 != nullptr )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v4 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        for ( i = 0; i < 0x1F4; ++i )
        {
          buffer[i] = v1[i];
          if ( v1[i] == 0 )
            break;
        }
        buffer[499] = 0;
        strlen(buf: (unsigned __int8 *)buffer);
        WriteFile(
          hFile: v4,
          lpBuffer: buffer,
          nNumberOfBytesToWrite: v6,
          lpNumberOfBytesWritten: &bytes_written,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( wcscpy_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: aRuntimeErrorPr) != 0
        || (outmsg[285] = 0, GetModuleFileNameW(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0)
        && wcscpy_s(_Dst: &outmsg[25], _SizeInWords: 0x2FBu, _Src: L"<program name unknown>") != 0
        || (unsigned int)(wcslen(wcs: &outmsg[25]) + 1) > 0x3C
        && (v2 = wcslen(wcs: &outmsg[25]),
            wcsncpy_s(
              _Dst: (unsigned __int16 *)&buf_0[2 * v2 + 24],
              _SizeInWords: 763 - ((&buf_0[2 * v2 + 24] - (char *)&outmsg[25]) >> 1),
              _Src: L"...",
              _Count: 3u) != 0)
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"\n\n") != 0
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: (const wchar_t *)bytes_written) != 0 )
      {
        _invoke_watson(a1: (unsigned int)outmsg);
      }
      __crtMessageBoxW(lpText: outmsg, lpCaption: L"Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045C7B
// Name: __FF_MSGBANNER
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _FF_MSGBANNER()
{
  if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
  {
    _NMSG_WRITE(rterrnum: 252);
    _NMSG_WRITE(rterrnum: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045CB4
// Name: __fltin2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_flt *__cdecl _fltin2(_flt *flt, const char *str, localeinfo_struct *_Locale)
{
  int v3; // ebx
  INTRNCVT_STATUS v4; // eax
  const char *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const char *v7; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v7 = str;
  v3 = 0;
  flags = __strgtold12_l(pld12: &ld12, p_end_ptr: &EndPtr, str, mult12: 0, scale: 0, decpt: 0, implicit_E: 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v3 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v4 = _ld12tod(pld12: &ld12, d: &x);
    if ( (flags & 2) != 0 || v4 == INTRNCVT_OVERFLOW )
      v3 = 128;
    if ( (flags & 1) != 0 || v4 == INTRNCVT_UNDERFLOW )
      v3 |= 0x100u;
  }
  flt->nbytes = EndPtr - v7;
  flt->dval = x.x;
  flt->flags = v3;
  return flt;
}

//------------------------------------------------------------------------------
// Address: 0x10045D5B
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(unsigned int cookie)
{
  if ( cookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x10045D6A
// Name: ___strgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __strgtold12_l(
        _LDBL12 *pld12,
        const char **p_end_ptr,
        const char *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v8; // ecx
  char *v9; // edi
  const char *v11; // edx
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // eax
  const char *v16; // edx
  int v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  _LDBL12 *v24; // ecx
  char v25; // al
  _LDBL12 *v26; // ecx
  int v27; // eax
  _LDBL12 *v28; // ebx
  __int16 v29; // ax
  __int16 v30; // si
  unsigned __int16 v31; // cx
  int v32; // eax
  _WORD *v33; // edi
  unsigned int v34; // eax
  unsigned int v35; // edx
  unsigned int v36; // esi
  __int16 v37; // cx
  unsigned int v38; // eax
  int v39; // esi
  int v40; // eax
  int v41; // esi
  int v42; // eax
  int v43; // edi
  int v44; // eax
  __int16 v45; // cx
  int v46; // esi
  unsigned int v47; // edx
  __int16 v48; // ax
  int v49; // [esp-8h] [ebp-8Ch]
  int v50; // [esp-8h] [ebp-8Ch]
  _LDBL12 *v51; // [esp+8h] [ebp-7Ch]
  __int16 man_sign; // [esp+10h] [ebp-74h]
  __int16 v53; // [esp+14h] [ebp-70h]
  unsigned int result_flags; // [esp+18h] [ebp-6Ch]
  int exp_sign; // [esp+1Ch] [ebp-68h]
  int exp_signa; // [esp+1Ch] [ebp-68h]
  int pow; // [esp+20h] [ebp-64h]
  int powa; // [esp+20h] [ebp-64h]
  int found_exponent; // [esp+24h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+24h] [ebp-60h]
  int found_decpoint; // [esp+28h] [ebp-5Ch]
  unsigned __int8 *found_decpointa; // [esp+28h] [ebp-5Ch]
  int found_digit; // [esp+2Ch] [ebp-58h]
  int found_digita; // [esp+2Ch] [ebp-58h]
  const char *savedp; // [esp+30h] [ebp-54h]
  int savedpa; // [esp+30h] [ebp-54h]
  int exp_adj; // [esp+34h] [ebp-50h]
  int exp_adja; // [esp+34h] [ebp-50h]
  unsigned int manlen; // [esp+38h] [ebp-4Ch]
  unsigned int manlena; // [esp+38h] [ebp-4Ch]
  __int64 v71; // [esp+3Ch] [ebp-48h] BYREF
  int v72; // [esp+44h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+48h] [ebp-3Ch] BYREF
  _BYTE v74[12]; // [esp+58h] [ebp-2Ch] BYREF
  char buf[28]; // [esp+64h] [ebp-20h] BYREF

  v8 = 0;
  v9 = buf;
  man_sign = 0;
  exp_sign = 1;
  manlen = 0;
  found_digit = 0;
  found_decpoint = 0;
  found_exponent = 0;
  pow = 0;
  exp_adj = 0;
  result_flags = 0;
  if ( _Locale == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v11 = str;
  savedp = str;
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v11;
  }
  while ( 2 )
  {
    v13 = *v11++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v14 = v13 - 43;
        if ( v14 == 0 )
        {
          man_sign = 0;
          v8 = 2;
          continue;
        }
        v15 = v14 - 2;
        if ( v15 == 0 )
        {
          v8 = 2;
          man_sign = 0x8000;
          continue;
        }
        if ( v15 != 3 )
          goto LABEL_74;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_32;
        if ( v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (unsigned __int8)(v13 - 100) > 1u )
          goto LABEL_74;
        v50 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
        {
LABEL_11:
          v49 = 3;
LABEL_12:
          v8 = v49;
          --v11;
        }
        else
        {
          if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v50 = 5;
            goto LABEL_15;
          }
          if ( v13 != 48 )
          {
LABEL_36:
            v16 = savedp;
            goto LABEL_81;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        found_digit = 1;
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen >= 0x19 )
          {
            ++exp_adj;
          }
          else
          {
            ++manlen;
            *v9++ = v13 - 48;
          }
          v13 = *v11++;
        }
        if ( v13 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_45;
LABEL_24:
        v50 = 4;
        goto LABEL_15;
      case 4:
        found_digit = 1;
        found_decpoint = 1;
        if ( manlen == 0 )
        {
          while ( v13 == 48 )
          {
            --exp_adj;
            v13 = *v11++;
          }
        }
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            *v9++ = v13 - 48;
            --exp_adj;
          }
          v13 = *v11++;
        }
LABEL_45:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_32:
        --v11;
        v50 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int8)(v13 - 48) > 9u )
          goto LABEL_36;
        v49 = 4;
        goto LABEL_12;
      case 6:
        savedp = v11 - 2;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_62;
        v17 = v13 - 43;
        if ( v17 == 0 )
          goto LABEL_69;
        v18 = v17 - 2;
        if ( v18 == 0 )
          goto LABEL_68;
        v19 = v18 == 3;
LABEL_66:
        if ( !v19 )
          goto LABEL_36;
        v50 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_62;
        v19 = v13 == 48;
        goto LABEL_66;
      case 8:
        found_exponent = 1;
        while ( v13 == 48 )
          v13 = *v11++;
        if ( (unsigned __int8)(v13 - 49) > 8u )
          goto LABEL_74;
LABEL_62:
        v49 = 9;
        goto LABEL_12;
      case 9:
        found_exponent = 1;
        v21 = 0;
        while ( 2 )
        {
          if ( v13 >= 48 && v13 <= 57 )
          {
            v21 = 10 * v21 + v13 - 48;
            if ( v21 <= 5200 )
            {
              v13 = *v11++;
              continue;
            }
            v21 = 5201;
          }
          break;
        }
        pow = v21;
        while ( v13 >= 48 && v13 <= 57 )
          v13 = *v11++;
LABEL_74:
        v16 = v11 - 1;
        goto LABEL_81;
      case 11:
        if ( implicit_E != 0 )
        {
          v20 = v13 - 43;
          savedp = v11 - 1;
          if ( v20 != 0 )
          {
            if ( v20 != 2 )
            {
              v16 = v11 - 1;
              goto LABEL_81;
            }
LABEL_68:
            exp_sign = -1;
            v8 = 7;
          }
          else
          {
LABEL_69:
            v50 = 7;
LABEL_15:
            v8 = v50;
          }
          continue;
        }
        v16 = v11 - 1;
LABEL_81:
        *p_end_ptr = v16;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_176:
          v45 = 0;
          v48 = 0;
          v47 = 0;
          v46 = 0;
          goto LABEL_177;
        }
        if ( manlen > 0x18 )
        {
          if ( buf[23] >= 5 )
            ++buf[23];
          --v9;
          ++exp_adj;
          manlen = 24;
        }
        if ( manlen == 0 )
          goto LABEL_176;
        while ( *--v9 == 0 )
        {
          --manlen;
          ++exp_adj;
        }
        __mtold12(manptr: buf, manlen, ld12: &tmpld12);
        v22 = pow;
        if ( exp_sign < 0 )
          v22 = -pow;
        v23 = exp_adj + v22;
        if ( found_exponent == 0 )
          v23 += scale;
        if ( found_decpoint == 0 )
          v23 -= decpt;
        if ( v23 > 5200 )
        {
          v46 = 0;
          v48 = 0x7FFF;
          v47 = 0x80000000;
          v45 = 0;
          result_flags = 2;
          goto LABEL_177;
        }
        if ( v23 < -5200 )
        {
          result_flags = 1;
          goto LABEL_176;
        }
        v24 = &_pow10pos[-8];
        savedpa = v23;
        if ( v23 != 0 )
        {
          if ( v23 < 0 )
          {
            savedpa = -v23;
            v24 = &_pow10neg[-8];
          }
          if ( mult12 == 0 )
            *(_WORD *)tmpld12.ld12 = 0;
          if ( savedpa != 0 )
          {
            while ( 1 )
            {
              v25 = savedpa;
              savedpa >>= 3;
              v26 = v24 + 7;
              v27 = v25 & 7;
              v51 = v26;
              if ( v27 == 0 )
                goto LABEL_171;
              v28 = &v26[v27];
              if ( *(_WORD *)v28->ld12 >= 0x8000u )
              {
                v71 = *(_QWORD *)v28->ld12;
                v72 = *(_DWORD *)&v28->ld12[8];
                --*(_DWORD *)((char *)&v71 + 2);
                v28 = (_LDBL12 *)&v71;
              }
              exp_adja = 0;
              memset(v74, 0, sizeof(v74));
              v29 = *(_WORD *)&v28->ld12[10] & 0x7FFF;
              v30 = (*(_WORD *)&tmpld12.ld12[10] ^ *(_WORD *)&v28->ld12[10]) & 0x8000;
              v53 = v30;
              v31 = v29 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF
                || (*(_WORD *)&v28->ld12[10] & 0x7FFF) == 0x7FFF
                || v31 > 0xBFFDu )
              {
                break;
              }
              if ( v31 <= 0x3FBFu )
              {
                v32 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_170:
                *(_DWORD *)&tmpld12.ld12[8] = v32;
                goto LABEL_171;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v31, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v29 != 0
                  || (++v31, (*(_DWORD *)&v28->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v28->ld12[4] != 0
                  || *(_DWORD *)v28->ld12 != 0 )
                {
                  exp_signa = 0;
                  v33 = &v74[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v28->ld12[8];
                    do
                    {
                      manlena = 0;
                      v34 = *(unsigned __int16 *)found_decpointa * *(unsigned __int16 *)found_exponenta;
                      v35 = *((_DWORD *)v33 - 1);
                      v36 = v35 + v34;
                      if ( v35 + v34 < v35 || v36 < v34 )
                        manlena = 1;
                      *((_DWORD *)v33 - 1) = v36;
                      if ( manlena != 0 )
                        ++*v33;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    ++v33;
                    ++exp_signa;
                  }
                  v37 = v31 - 16382;
                  if ( v37 <= 0 )
                    goto LABEL_180;
                  do
                  {
                    if ( *(int *)&v74[8] < 0 )
                      break;
                    v38 = *(_DWORD *)v74;
                    *(_DWORD *)v74 *= 2;
                    v39 = (v38 >> 31) | (2 * *(_DWORD *)&v74[4]);
                    v40 = *(__int64 *)&v74[4] >> 31;
                    --v37;
                    *(_DWORD *)&v74[4] = v39;
                    *(_DWORD *)&v74[8] = v40;
                  }
                  while ( v37 > 0 );
                  if ( v37 <= 0 )
                  {
LABEL_180:
                    if ( --v37 < 0 )
                    {
                      v41 = (unsigned __int16)-v37;
                      v37 = 0;
                      do
                      {
                        if ( (v74[0] & 1) != 0 )
                          ++exp_adja;
                        v42 = *(_DWORD *)&v74[8];
                        *(_DWORD *)&v74[8] >>= 1;
                        v43 = (v42 << 31) | (*(_DWORD *)&v74[4] >> 1);
                        v44 = *(__int64 *)v74 >> 1;
                        --v41;
                        *(_DWORD *)&v74[4] = v43;
                        *(_DWORD *)v74 = v44;
                      }
                      while ( v41 != 0 );
                      if ( exp_adja != 0 )
                        *(_WORD *)v74 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v74 > 0x8000u || (*(_DWORD *)v74 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v74[2] == -1 )
                    {
                      *(_DWORD *)&v74[2] = 0;
                      if ( *(_DWORD *)&v74[6] == -1 )
                      {
                        *(_DWORD *)&v74[6] = 0;
                        if ( *(_WORD *)&v74[10] == 0xFFFF )
                        {
                          *(_WORD *)&v74[10] = 0x8000;
                          ++v37;
                        }
                        else
                        {
                          ++*(_WORD *)&v74[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v74[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v74[2];
                    }
                  }
                  if ( (unsigned __int16)v37 < 0x7FFFu )
                  {
                    *(_WORD *)tmpld12.ld12 = *(_WORD *)&v74[2];
                    *(_DWORD *)&tmpld12.ld12[2] = *(_DWORD *)&v74[4];
                    *(_DWORD *)&tmpld12.ld12[6] = *(_DWORD *)&v74[8];
                    *(_WORD *)&tmpld12.ld12[10] = v53 | v37;
                  }
                  else
                  {
                    *(_DWORD *)&tmpld12.ld12[4] = 0;
                    *(_DWORD *)tmpld12.ld12 = 0;
                    *(_DWORD *)&tmpld12.ld12[8] = v53 == 0 ? 2147450880 : -32768;
                  }
                }
                else
                {
                  memset(&tmpld12, 0, sizeof(tmpld12));
                }
              }
              else
              {
                *(_WORD *)&tmpld12.ld12[10] = 0;
              }
LABEL_171:
              if ( savedpa == 0 )
                goto LABEL_172;
              v24 = v51;
            }
            *(_DWORD *)&tmpld12.ld12[4] = 0;
            v32 = v30 == 0 ? 2147450880 : -32768;
            *(_DWORD *)tmpld12.ld12 = 0;
            goto LABEL_170;
          }
        }
LABEL_172:
        v45 = *(_WORD *)tmpld12.ld12;
        v46 = *(_DWORD *)&tmpld12.ld12[2];
        v47 = *(_DWORD *)&tmpld12.ld12[6];
        v48 = *(_WORD *)&tmpld12.ld12[10];
LABEL_177:
        *(_WORD *)pld12->ld12 = v45;
        *(_WORD *)&pld12->ld12[10] = man_sign | v48;
        *(_DWORD *)&pld12->ld12[2] = v46;
        *(_DWORD *)&pld12->ld12[6] = v47;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046450
// Name: _strlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strlen(char *buf)
{
  char *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = buf;
  if ( ((unsigned __int8)buf & 3) != 0 )
  {
    while ( 1 )
    {
      v2 = *v1++;
      if ( v2 == 0 )
        break;
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto main_loop_3;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_3:
        v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
        v1 += 4;
      }
      while ( (v3 & 0x81010100) == 0 );
      v4 = *((_DWORD *)v1 - 1);
    }
    while ( (_BYTE)v4 != 0 && BYTE1(v4) != 0 && (v4 & 0xFF0000) != 0 && (v4 & 0xFF000000) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100464DB
// Name: __check_float_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _check_float_string@<eax>(
        unsigned int *pnFloatStrSz@<esi>,
        char **pFloatStr@<edi>,
        unsigned int nFloatStrUsed,
        char *floatstring,
        int *pmalloc_FloatStrFlag)
{
  unsigned int v5; // eax
  char *v6; // eax
  char *v8; // eax

  v5 = *pnFloatStrSz;
  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v6 = (char *)_calloc_crt(count: v5, size: 2u);
      *pFloatStr = v6;
      if ( v6 == nullptr )
        return 0;
      *pmalloc_FloatStrFlag = 1;
      memcpy(dst: (unsigned __int8 *)*pFloatStr, src: (unsigned __int8 *)floatstring, count: *pnFloatStrSz);
    }
    else
    {
      v8 = (char *)_recalloc_crt(ptr: *pFloatStr, count: v5, size: 2u);
      if ( v8 == nullptr )
        return 0;
      *pFloatStr = v8;
    }
    *pnFloatStrSz *= 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10046532
// Name: _hextodec
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl hextodec(unsigned __int8 chr)
{
  bool v1; // zf
  unsigned int result; // eax

  v1 = isdigit(c: chr) == 0;
  result = (char)chr;
  if ( v1 )
    return ((char)chr & 0xFFFFFFDF) - 7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10046552
// Name: _inc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall inc(int a1, _iobuf *fileptr)
{
  if ( --fileptr->_cnt < 0 )
    return _filbuf(str: fileptr);
  return *(unsigned __int8 *)fileptr->_ptr++;
}

//------------------------------------------------------------------------------
// Address: 0x10046568
// Name: _whiteout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall whiteout@<eax>(int *counter@<esi>, int a2@<ecx>, _iobuf *fileptr)
{
  int v3; // ebx
  int v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  do
  {
    ++*counter;
    v3 = inc(a1: a2, fileptr);
    if ( v3 == -1 )
      break;
    v4 = isspace(c: (unsigned __int8)v3);
    a2 = v6;
  }
  while ( v4 != 0 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10046592
// Name: __input_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _input_l(_iobuf *stream, unsigned __int8 *format, localeinfo_struct *plocinfo, char *arglist)
{
  int result; // eax
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  unsigned __int8 v8; // al
  const unsigned __int8 *v9; // edi
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // ecx
  const unsigned __int8 *v14; // eax
  _WORD *v15; // esi
  unsigned __int8 v16; // al
  int v17; // ebx
  int v18; // eax
  int v19; // ecx
  int v20; // edi
  int v21; // ebx
  int v22; // ebx
  int i; // eax
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int j; // eax
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  int v32; // ecx
  int v33; // eax
  int k; // eax
  int v35; // eax
  int v36; // ecx
  void (__cdecl *v37)(int, void *, char *, _LocaleUpdate *); // eax
  _WORD *v38; // edi
  int v39; // eax
  int v40; // eax
  unsigned __int8 *v41; // esi
  unsigned __int8 v42; // dl
  unsigned __int8 v43; // cl
  unsigned int v44; // edi
  int v45; // edx
  unsigned __int8 v46; // al
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  int v50; // ecx
  unsigned __int64 v51; // kr00_8
  unsigned int v52; // edi
  unsigned int v53; // esi
  int v54; // eax
  int v55; // ecx
  int v56; // edi
  int v57; // ebx
  int v58; // eax
  int v59; // eax
  int v60; // ecx
  bool v61; // zf
  int v62; // [esp-14h] [ebp-21Ch]
  void *v63; // [esp-10h] [ebp-218h]
  char *v64; // [esp-Ch] [ebp-214h]
  int v65; // [esp-8h] [ebp-210h]
  int v66; // [esp-8h] [ebp-210h]
  int v67; // [esp-8h] [ebp-210h]
  int v68; // [esp-8h] [ebp-210h]
  int v69; // [esp-8h] [ebp-210h]
  int v70; // [esp-8h] [ebp-210h]
  int v71; // [esp-8h] [ebp-210h]
  int v72; // [esp-8h] [ebp-210h]
  int v73; // [esp-8h] [ebp-210h]
  int v74; // [esp-8h] [ebp-210h]
  char *arglistsave; // [esp+8h] [ebp-200h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-1FCh] BYREF
  int wctemp; // [esp+1Ch] [ebp-1ECh] BYREF
  char *v78; // [esp+20h] [ebp-1E8h]
  unsigned int number; // [esp+24h] [ebp-1E4h]
  char temp[4]; // [esp+28h] [ebp-1E0h] BYREF
  unsigned int nFloatStrSz; // [esp+2Ch] [ebp-1DCh] BYREF
  int integer64; // [esp+30h] [ebp-1D8h]
  unsigned __int8 prevchar; // [esp+37h] [ebp-1D1h]
  int malloc_FloatStrFlag; // [esp+38h] [ebp-1D0h] BYREF
  int count; // [esp+3Ch] [ebp-1CCh]
  unsigned __int64 num64; // [esp+40h] [ebp-1C8h]
  void *pointer; // [esp+48h] [ebp-1C0h]
  const unsigned __int8 *v88; // [esp+4Ch] [ebp-1BCh]
  int widthset; // [esp+50h] [ebp-1B8h]
  int comchr; // [esp+54h] [ebp-1B4h]
  char *pFloatStr; // [esp+58h] [ebp-1B0h] BYREF
  int started; // [esp+5Ch] [ebp-1ACh]
  char decimal; // [esp+60h] [ebp-1A8h]
  char negative; // [esp+61h] [ebp-1A7h]
  char fl_wchar_arg; // [esp+62h] [ebp-1A6h]
  char match; // [esp+63h] [ebp-1A5h]
  _iobuf *fileptr; // [esp+64h] [ebp-1A4h]
  char suppress; // [esp+6Bh] [ebp-19Dh]
  int width; // [esp+6Ch] [ebp-19Ch]
  char widechar; // [esp+73h] [ebp-195h]
  char chr[4]; // [esp+74h] [ebp-194h]
  char done_flag; // [esp+7Bh] [ebp-18Dh]
  int charcount; // [esp+7Ch] [ebp-18Ch] BYREF
  unsigned __int8 last; // [esp+83h] [ebp-185h]
  char floatstring[352]; // [esp+84h] [ebp-184h] BYREF
  char AsciiTable[32]; // [esp+1E4h] [ebp-24h] BYREF

  v78 = arglist;
  fileptr = stream;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  *(_DWORD *)chr = 0;
  if ( format == nullptr
    || stream == nullptr
    || (stream->_flag & 0x40) == 0
    && ((v5 = _fileno(stream)) == -1 || v5 == -2 ? (v6 = &__badioinfo) : (v6 = &__pioinfo[v5 >> 5][v5 & 0x1F]),
        (*((_BYTE *)v6 + 36) & 0x7F) != 0
     || (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = &__pioinfo[v5 >> 5][v5 & 0x1F]), *((char *)v7 + 36) < 0)) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v8 = *format;
  match = 0;
  charcount = 0;
  count = 0;
  if ( v8 == 0 )
    goto LABEL_288;
  v9 = format;
  while ( 2 )
  {
    if ( isspace(c: v8) != 0 )
    {
      --charcount;
      v10 = whiteout(counter: &charcount, a2: v65, fileptr);
      if ( v10 != -1 )
        _ungetc_nolock(ch: v10, str: fileptr);
      do
        ++v9;
      while ( isspace(c: *v9) != 0 );
      goto LABEL_272;
    }
    if ( *v9 != 37 )
      goto LABEL_264;
    if ( v9[1] == 37 )
    {
      ++v9;
LABEL_264:
      ++charcount;
      v57 = inc(a1: v65, fileptr);
      v58 = *v9++;
      *(_DWORD *)chr = v57;
      v88 = v9;
      if ( v58 == v57 )
      {
        if ( isleadbyte(c: v57) == 0 )
          goto LABEL_268;
        ++charcount;
        v59 = inc(a1: v74, fileptr);
        v60 = *v9++;
        v88 = v9;
        if ( v60 == v59 )
        {
          --charcount;
          goto LABEL_268;
        }
        if ( v59 != -1 )
          _ungetc_nolock(ch: v59, str: fileptr);
      }
      v61 = v57 == -1;
      goto LABEL_278;
    }
    number = 0;
    prevchar = 0;
    started = 0;
    widthset = 0;
    width = 0;
    decimal = 0;
    negative = 0;
    suppress = 0;
    done_flag = 0;
    fl_wchar_arg = 0;
    widechar = 0;
    last = 1;
    integer64 = 0;
    do
    {
      v11 = *++v9;
      v12 = isdigit(c: (unsigned __int8)v11);
      v13 = v66;
      if ( v12 != 0 )
      {
        ++widthset;
        width = 10 * width + v11 - 48;
        continue;
      }
      if ( v11 > 78 )
      {
        if ( v11 == 104 )
        {
          --last;
          --widechar;
        }
        else
        {
          if ( v11 == 108 )
          {
            v14 = v9 + 1;
            if ( v9[1] == 108 )
              goto LABEL_37;
            ++last;
          }
          else if ( v11 != 119 )
          {
            goto DEFAULT_LABEL;
          }
          ++widechar;
        }
      }
      else
      {
        switch ( v11 )
        {
          case 'N':
            continue;
          case '*':
            ++suppress;
            continue;
          case 'F':
            continue;
          default:
            break;
        }
        if ( v11 != 73 )
        {
          if ( v11 == 76 )
          {
            ++last;
            continue;
          }
DEFAULT_LABEL:
          ++done_flag;
          continue;
        }
        LOBYTE(v13) = v9[1];
        if ( (_BYTE)v13 == 54 )
        {
          v14 = v9 + 2;
          if ( v9[2] == 52 )
          {
LABEL_37:
            ++integer64;
            v9 = v14;
            num64 = 0;
            continue;
          }
        }
        if ( (_BYTE)v13 == 51 && v9[2] == 50 )
        {
          v9 += 2;
          continue;
        }
        if ( (_BYTE)v13 != 100 && (_BYTE)v13 != 105 && (_BYTE)v13 != 111 && (_BYTE)v13 != 120 && (_BYTE)v13 != 88 )
          goto DEFAULT_LABEL;
      }
    }
    while ( done_flag == 0 );
    v88 = v9;
    if ( suppress != 0 )
    {
      v15 = nullptr;
    }
    else
    {
      v15 = *(_WORD **)v78;
      arglistsave = v78;
      v78 += 4;
    }
    pointer = v15;
    done_flag = 0;
    if ( widechar == 0 )
    {
      v16 = *v9;
      if ( *v9 == 83 || (widechar = -1, v16 == 67) )
        widechar = 1;
    }
    v17 = *v9 | 0x20;
    comchr = v17;
    if ( v17 != 110 )
    {
      if ( v17 == 99 || v17 == 123 )
      {
        ++charcount;
        v18 = inc(a1: v13, fileptr);
      }
      else
      {
        v18 = whiteout(counter: &charcount, a2: v13, fileptr);
      }
      *(_DWORD *)chr = v18;
      if ( v18 == -1 )
        goto error_return;
      v15 = pointer;
      v9 = v88;
    }
    v19 = widthset;
    if ( widthset != 0 && width == 0 )
      goto LABEL_274;
    if ( v17 > 111 )
    {
      switch ( v17 )
      {
        case 'p':
          last = 1;
          break;
        case 's':
LABEL_129:
          if ( widechar > 0 )
            fl_wchar_arg = 1;
          goto scanit;
        case 'u':
          break;
        case 'x':
          goto LABEL_84;
        case '{':
          if ( widechar > 0 )
            fl_wchar_arg = 1;
          v41 = (unsigned __int8 *)(v9 + 1);
          if ( v9[1] == 94 )
          {
            v41 = (unsigned __int8 *)(v9 + 2);
            decimal = -1;
          }
          memset(dst: (int)AsciiTable, value: nullptr, count: sizeof(AsciiTable));
          if ( *v41 == 93 )
          {
            v42 = 93;
            ++v41;
            AsciiTable[11] = 32;
          }
          else
          {
            v42 = prevchar;
          }
          while ( 1 )
          {
            v46 = *v41;
            if ( *v41 == 93 )
              break;
            ++v41;
            if ( v46 == 45 && v42 != 0 && (v43 = *v41, *v41 != 93) )
            {
              ++v41;
              if ( v42 >= v43 )
              {
                last = v42;
                v42 = v43;
              }
              else
              {
                last = v43;
              }
              if ( v42 < last )
              {
                v44 = v42;
                v45 = (unsigned __int8)(last - v42);
                do
                {
                  AsciiTable[v44 >> 3] |= 1 << (v44 & 7);
                  ++v44;
                  --v45;
                }
                while ( v45 != 0 );
                v17 = comchr;
              }
              v19 = last & 7;
              AsciiTable[last >> 3] |= 1 << v19;
              v42 = 0;
            }
            else
            {
              v42 = v46;
              v19 = v46 & 7;
              AsciiTable[v46 >> 3] |= 1 << (v46 & 7);
              v17 = comchr;
            }
          }
          v88 = v41;
          v15 = pointer;
scanit:
          --charcount;
          v38 = v15;
          if ( *(_DWORD *)chr != -1 )
          {
            _ungetc_nolock(ch: *(int *)chr, str: fileptr);
            v19 = v68;
          }
          while ( 1 )
          {
            if ( widthset != 0 )
            {
              v39 = width--;
              if ( v39 == 0 )
                goto LABEL_202;
            }
            ++charcount;
            v40 = inc(a1: v19, fileptr);
            *(_DWORD *)chr = v40;
            if ( v40 == -1 )
              goto LABEL_200;
            if ( v17 != 99 )
            {
              if ( v17 != 115 )
                goto LABEL_293;
              if ( v40 >= 9 && v40 <= 13 )
              {
LABEL_200:
                --charcount;
                if ( v40 != -1 )
                  _ungetc_nolock(ch: v40, str: fileptr);
LABEL_202:
                if ( v38 != v15 )
                {
                  if ( suppress == 0 )
                  {
                    ++count;
                    if ( v17 != 99 )
                    {
                      if ( fl_wchar_arg != 0 )
                        *(_WORD *)pointer = 0;
                      else
                        *(_BYTE *)pointer = 0;
                    }
                  }
                  goto LABEL_262;
                }
                goto error_return;
              }
              if ( v40 == 32 )
              {
LABEL_293:
                if ( v17 != 123 )
                  goto LABEL_200;
                v19 = decimal ^ AsciiTable[v40 >> 3];
                v17 = comchr;
                if ( ((1 << (v40 & 7)) & v19) == 0 )
                  goto LABEL_200;
              }
            }
            if ( suppress != 0 )
            {
              v38 = (_WORD *)((char *)v38 + 1);
            }
            else
            {
              if ( fl_wchar_arg != 0 )
              {
                temp[0] = v40;
                if ( isleadbyte(c: v40) != 0 )
                {
                  ++charcount;
                  temp[1] = inc(a1: v69, fileptr);
                }
                wctemp = 63;
                _mbtowc_l(
                  pwc: (wchar_t *)&wctemp,
                  s: temp,
                  n: _loc_update.localeinfo.locinfo->mb_cur_max,
                  plocinfo: &_loc_update.localeinfo);
                *v15++ = wctemp;
              }
              else
              {
                *(_BYTE *)v15 = v40;
                v15 = (_WORD *)((char *)v15 + 1);
              }
              pointer = v15;
            }
          }
        default:
          goto LABEL_153;
      }
LABEL_209:
      v21 = *(_DWORD *)chr;
      if ( *(_DWORD *)chr == 45 )
      {
        negative = 1;
      }
      else if ( *(_DWORD *)chr != 43 )
      {
        goto getnum;
      }
      if ( --width == 0 && widthset != 0 )
      {
        done_flag = 1;
        goto getnum;
      }
      ++charcount;
      v21 = inc(a1: widthset, fileptr);
      goto LABEL_216;
    }
    switch ( v17 )
    {
      case 'o':
        goto LABEL_209;
      case 'c':
        if ( widthset == 0 )
        {
          ++width;
          widthset = 1;
        }
        goto LABEL_129;
      case 'd':
        goto LABEL_209;
      default:
        break;
    }
    if ( v17 <= 100 )
      goto LABEL_153;
    if ( v17 <= 103 )
    {
      v22 = 0;
      if ( *(_DWORD *)chr == 45 )
      {
        *pFloatStr = 45;
        v22 = 1;
        goto f_incwidth;
      }
      if ( *(_DWORD *)chr == 43 )
      {
f_incwidth:
        --width;
        ++charcount;
        *(_DWORD *)chr = inc(a1: v19, fileptr);
      }
      if ( widthset == 0 )
        width = -1;
      for ( i = (unsigned __int8)chr[0]; isdigit(c: i) != 0; i = (unsigned __int8)chr[0] )
      {
        v24 = width--;
        if ( v24 == 0 )
          break;
        ++started;
        pFloatStr[v22] = chr[0];
        if ( _check_float_string(
               pnFloatStrSz: &nFloatStrSz,
               &pFloatStr,
               nFloatStrUsed: ++v22,
               floatstring,
               pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
          goto error_return;
        ++charcount;
        *(_DWORD *)chr = inc(a1: v25, fileptr);
      }
      decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      if ( decimal == chr[0] )
      {
        v26 = width--;
        if ( v26 != 0 )
        {
          ++charcount;
          *(_DWORD *)chr = inc(a1: v67, fileptr);
          pFloatStr[v22] = decimal;
          if ( _check_float_string(
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 nFloatStrUsed: ++v22,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return;
          for ( j = (unsigned __int8)chr[0]; isdigit(c: j) != 0; j = (unsigned __int8)chr[0] )
          {
            v28 = width--;
            if ( v28 == 0 )
              break;
            ++started;
            pFloatStr[v22] = chr[0];
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v22,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return;
            ++charcount;
            *(_DWORD *)chr = inc(a1: v29, fileptr);
          }
        }
      }
      if ( started != 0 && (*(_DWORD *)chr == 101 || *(_DWORD *)chr == 69) )
      {
        v30 = width--;
        if ( v30 != 0 )
        {
          pFloatStr[v22] = 101;
          if ( _check_float_string(
                 pnFloatStrSz: &nFloatStrSz,
                 &pFloatStr,
                 nFloatStrUsed: ++v22,
                 floatstring,
                 pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
            goto error_return;
          ++charcount;
          *(_DWORD *)chr = inc(a1: v31, fileptr);
          if ( *(_DWORD *)chr == 45 )
          {
            pFloatStr[v22] = 45;
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v22,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return;
f_incwidth2:
            v33 = width--;
            if ( v33 != 0 )
            {
              ++charcount;
              *(_DWORD *)chr = inc(a1: v32, fileptr);
            }
            else
            {
              width = 0;
            }
          }
          else if ( *(_DWORD *)chr == 43 )
          {
            goto f_incwidth2;
          }
          for ( k = (unsigned __int8)chr[0]; isdigit(c: k) != 0; k = (unsigned __int8)chr[0] )
          {
            v35 = width--;
            if ( v35 == 0 )
              break;
            ++started;
            pFloatStr[v22] = chr[0];
            if ( _check_float_string(
                   pnFloatStrSz: &nFloatStrSz,
                   &pFloatStr,
                   nFloatStrUsed: ++v22,
                   floatstring,
                   pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
              goto error_return;
            ++charcount;
            *(_DWORD *)chr = inc(a1: v36, fileptr);
          }
        }
      }
      --charcount;
      if ( *(_DWORD *)chr != -1 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      if ( started != 0 )
      {
        if ( suppress == 0 )
        {
          ++count;
          v64 = pFloatStr;
          v63 = pointer;
          pFloatStr[v22] = 0;
          v62 = (char)last - 1;
          v37 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))DecodePointer(Ptr: Ptr);
          v37(a1: v62, a2: v63, a3: v64, a4: &_loc_update);
        }
        goto LABEL_262;
      }
      goto error_return;
    }
    if ( v17 != 105 )
    {
      if ( v17 == 110 )
      {
        v20 = charcount;
        if ( suppress == 0 )
        {
assign_num:
          if ( integer64 != 0 )
          {
            *(_QWORD *)v15 = num64;
          }
          else if ( last != 0 )
          {
            *(_DWORD *)v15 = v20;
          }
          else
          {
            *v15 = v20;
          }
        }
        goto LABEL_262;
      }
LABEL_153:
      if ( *v9 == *(_DWORD *)chr )
      {
        --match;
        if ( suppress == 0 )
          v78 = arglistsave;
        goto LABEL_262;
      }
LABEL_274:
      v61 = *(_DWORD *)chr == -1;
LABEL_278:
      if ( !v61 )
        _ungetc_nolock(ch: *(int *)chr, str: fileptr);
      goto error_return;
    }
    comchr = 100;
LABEL_84:
    v21 = *(_DWORD *)chr;
    if ( *(_DWORD *)chr == 45 )
    {
      negative = 1;
      goto x_incwidth;
    }
    if ( *(_DWORD *)chr == 43 )
    {
x_incwidth:
      if ( --width != 0 || widthset == 0 )
      {
        ++charcount;
        v21 = inc(a1: widthset, fileptr);
        *(_DWORD *)chr = v21;
      }
      else
      {
        done_flag = 1;
      }
    }
    if ( v21 == 48 )
    {
      ++charcount;
      v47 = inc(a1: v19, fileptr);
      v21 = v47;
      *(_DWORD *)chr = v47;
      if ( (_BYTE)v47 != 120 && (_BYTE)v47 != 88 )
      {
        started = 1;
        if ( comchr != 120 )
        {
          if ( widthset != 0 && --width == 0 )
            ++done_flag;
          comchr = 111;
          goto getnum;
        }
        --charcount;
        if ( v47 != -1 )
          _ungetc_nolock(ch: v47, str: fileptr);
        v21 = 48;
LABEL_216:
        *(_DWORD *)chr = v21;
        goto getnum;
      }
      ++charcount;
      v21 = inc(a1: v48, fileptr);
      *(_DWORD *)chr = v21;
      if ( widthset != 0 )
      {
        width -= 2;
        if ( width < 1 )
          ++done_flag;
      }
      comchr = 120;
    }
getnum:
    if ( integer64 == 0 )
    {
      v20 = number;
      if ( done_flag == 0 )
      {
        while ( 1 )
        {
          if ( comchr == 120 || comchr == 112 )
          {
            if ( isxdigit(c: (unsigned __int8)v21) == 0 )
            {
LABEL_248:
              --charcount;
              if ( v21 != -1 )
                _ungetc_nolock(ch: v21, str: fileptr);
              break;
            }
            v56 = 16 * v20;
            v21 = hextodec(chr: v21);
            v55 = v73;
            *(_DWORD *)chr = v21;
          }
          else
          {
            v54 = isdigit(c: (unsigned __int8)v21);
            v55 = v72;
            if ( v54 == 0 )
              goto LABEL_248;
            if ( comchr == 111 )
            {
              if ( v21 >= 56 )
                goto LABEL_248;
              v56 = 8 * v20;
            }
            else
            {
              v56 = 10 * v20;
            }
          }
          ++started;
          v20 = v56 + v21 - 48;
          if ( widthset != 0 && --width == 0 )
            break;
          ++charcount;
          v21 = inc(a1: v55, fileptr);
          *(_DWORD *)chr = v21;
        }
      }
      if ( negative != 0 )
        v20 = -v20;
      goto LABEL_252;
    }
    if ( done_flag != 0 )
      goto LABEL_233;
    while ( 2 )
    {
      if ( comchr != 120 && comchr != 112 )
      {
        v49 = isdigit(c: (unsigned __int8)v21);
        v50 = v70;
        if ( v49 == 0 )
          break;
        if ( comchr == 111 )
        {
          if ( v21 >= 56 )
            break;
          v51 = 8 * num64;
        }
        else
        {
          v51 = 10 * num64;
        }
        goto LABEL_228;
      }
      if ( isxdigit(c: (unsigned __int8)v21) != 0 )
      {
        v52 = num64 >> 28;
        v53 = 16 * num64;
        v21 = hextodec(chr: v21);
        v50 = v71;
        *(_DWORD *)chr = v21;
        v51 = __PAIR64__(v52, v53);
LABEL_228:
        ++started;
        num64 = v21 - 48 + v51;
        if ( widthset != 0 && --width == 0 )
          goto LABEL_233;
        ++charcount;
        v21 = inc(a1: v50, fileptr);
        *(_DWORD *)chr = v21;
        continue;
      }
      break;
    }
    --charcount;
    if ( v21 != -1 )
      _ungetc_nolock(ch: v21, str: fileptr);
LABEL_233:
    v20 = number;
    if ( negative != 0 )
      num64 = -(__int64)num64;
LABEL_252:
    if ( comchr == 70 )
      started = 0;
    if ( started == 0 )
      goto error_return;
    if ( suppress == 0 )
    {
      ++count;
      v15 = pointer;
      goto assign_num;
    }
LABEL_262:
    ++match;
    v9 = ++v88;
LABEL_268:
    if ( *(_DWORD *)chr != -1 )
    {
LABEL_272:
      v8 = *v9;
      if ( *v9 == 0 )
        goto error_return;
      continue;
    }
    break;
  }
  if ( *v9 == 37 && v88[1] == 110 )
  {
    v9 = v88;
    goto LABEL_272;
  }
error_return:
  if ( malloc_FloatStrFlag == 1 )
    free(pBlock: pFloatStr);
  if ( *(_DWORD *)chr == -1 )
  {
    result = count;
    if ( count == 0 && match == 0 )
      result = -1;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
LABEL_288:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x10047610
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcmp(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int16 v6; // ax

  v2 = str1;
  v3 = str2;
  if ( ((unsigned __int8)str1 & 3) != 0 )
  {
    if ( ((unsigned __int8)str1 & 1) == 0 )
      goto doword;
    v2 = str1 + 1;
    if ( *str1 != *str2 )
      return;
    v3 = str2 + 1;
    if ( *str1 == 0 )
      return;
    if ( ((unsigned __int8)v2 & 2) != 0 )
    {
doword:
      v6 = *(_WORD *)v2;
      v2 += 2;
      if ( (_BYTE)v6 != *v3 || (_BYTE)v6 == 0 || HIBYTE(v6) != v3[1] || HIBYTE(v6) == 0 )
        return;
      v3 += 2;
    }
  }
  do
  {
    v4 = *(_DWORD *)v2;
    if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
      break;
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) != v3[1] )
      break;
    if ( BYTE1(v4) == 0 )
      break;
    v5 = HIWORD(v4);
    if ( (_BYTE)v5 != v3[2] )
      break;
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) != v3[3] )
      break;
    v3 += 4;
    v2 += 4;
  }
  while ( BYTE1(v5) != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10047698
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  unsigned int v0; // edi
  unsigned int v1; // esi

  if ( __get_sigabrt() != nullptr )
    raise(signum: 22);
  if ( (__abort_behavior & 2) != 0 )
    _call_reportfault(a1: v0, a2: v1, nDbgHookCode: 3u, dwExceptionCode: 0x40000015u, dwExceptionFlags: 1u);
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x100476CB
// Name: __set_abort_behavior
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior(unsigned int flags, unsigned int mask)
{
  unsigned int result; // eax

  result = __abort_behavior;
  __abort_behavior = mask & flags | __abort_behavior & ~mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100476EC
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void *enull)
{
  __pPurecall = enull;
}

//------------------------------------------------------------------------------
// Address: 0x100476FB
// Name: __VEC_memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _VEC_memcpy@<eax>(unsigned int a1@<ecx>, __m128i *a2@<edi>, const __m128i *a3@<esi>)
{
  int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int k; // edx
  __m128i si128; // xmm1
  __m128i v8; // xmm2
  __m128i v9; // xmm3
  __m128i v10; // xmm5
  __m128i v11; // xmm6
  __m128i v12; // xmm7
  unsigned int m; // edx
  unsigned int v14; // ecx
  char v15; // al
  unsigned int n; // ecx
  int ii; // ecx
  unsigned int v19; // eax
  int i; // ecx
  unsigned int j; // eax
  unsigned int v22; // [esp-10h] [ebp-14h]
  int v23; // [esp-Ch] [ebp-10h]

  v3 = (unsigned __int8)a3 & 0xF;
  if ( ((unsigned __int8)a3 & 0xF) != 0 )
  {
    v22 = a1 - (16 - v3);
    v19 = 16 - v3;
    for ( i = v19 & 3; i != 0; --i )
    {
      a2->m128i_i8[0] = a3->m128i_i8[0];
      a3 = (const __m128i *)((char *)a3 + 1);
      a2 = (__m128i *)((char *)a2 + 1);
    }
    for ( j = v19 >> 2; j != 0; --j )
    {
      a2->m128i_i32[0] = a3->m128i_i32[0];
      a3 = (const __m128i *)((char *)a3 + 4);
      a2 = (__m128i *)((char *)a2 + 4);
    }
    a1 = v22;
  }
  v4 = a1;
  v5 = a1 & 0x7F;
  for ( k = v4 >> 7; k != 0; --k )
  {
    si128 = _mm_load_si128(a3 + 1);
    v8 = _mm_load_si128(a3 + 2);
    v9 = _mm_load_si128(a3 + 3);
    *a2 = _mm_load_si128(a3);
    a2[1] = si128;
    a2[2] = v8;
    a2[3] = v9;
    v10 = _mm_load_si128(a3 + 5);
    v11 = _mm_load_si128(a3 + 6);
    v12 = _mm_load_si128(a3 + 7);
    a2[4] = _mm_load_si128(a3 + 4);
    a2[5] = v10;
    a2[6] = v11;
    a2[7] = v12;
    a3 += 8;
    a2 += 8;
  }
  if ( v5 != 0 )
  {
    for ( m = v5 >> 4; m != 0; --m )
      *a2++ = _mm_load_si128(a3++);
    v14 = v5 & 0xF;
    if ( v14 != 0 )
    {
      v15 = v14;
      for ( n = v14 >> 2; n != 0; --n )
      {
        a2->m128i_i32[0] = a3->m128i_i32[0];
        a3 = (const __m128i *)((char *)a3 + 4);
        a2 = (__m128i *)((char *)a2 + 4);
      }
      for ( ii = v15 & 3; ii != 0; --ii )
      {
        a2->m128i_i8[0] = a3->m128i_i8[0];
        a3 = (const __m128i *)((char *)a3 + 1);
        a2 = (__m128i *)((char *)a2 + 1);
      }
    }
  }
  return v23;
}

//------------------------------------------------------------------------------
// Address: 0x100477FE
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_nolock(int fh)
{
  int osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(fh) == -1
    || (fh == 1 && (__pioinfo[0][2].osfile & 1) != 0 || fh == 2 && (__pioinfo[0][1].osfile & 1) != 0)
    && (osfhandle = _get_osfhandle(fh: 2), _get_osfhandle(fh: 1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(fh), CloseHandle(hObject: v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  __pioinfo[fh >> 5][fh & 0x1F].osfile = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004789A
// Name: __close
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close(int fh)
{
  ioinfo **v2; // edi
  int v3; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v2 = &__pioinfo[fh >> 5], v3 = (fh & 0x1F) << 6, (*(&(*v2)->osfile + v3) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    r = _close_nolock(fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x1004795E
// Name: __fileno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fileno(_iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_file;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10047984
// Name: __freebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(pBlock: stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = nullptr;
    stream->_base = nullptr;
    stream->_cnt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047A05
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x10047BAF
// Name: __flsbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flsbuf(unsigned __int8 ch, int str)
{
  _iobuf *v2; // esi
  int flag; // eax
  unsigned int v5; // eax
  char *base; // eax
  char *ptr; // edi
  signed int v8; // edi
  ioinfo *v9; // eax
  doubleint v10; // rax
  int written; // [esp+4h] [ebp-4h]

  v2 = (_iobuf *)str;
  str = _fileno(stream: (_iobuf *)str);
  flag = v2->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    v2->_flag |= 0x20u;
    return -1;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    v2->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      v2->_flag = flag | 0x20;
      return -1;
    }
    v2->_ptr = v2->_base;
    v2->_flag = flag & 0xFFFFFFFE;
  }
  v5 = v2->_flag & 0xFFFFFFED | 2;
  v2->_flag = v5;
  v2->_cnt = 0;
  written = 0;
  if ( (v5 & 0x10C) == 0 && (v2 != &__iob_func()[1] && v2 != &__iob_func()[2] || _isatty(fh: str) == 0) )
    _getbuf(str: v2);
  if ( (v2->_flag & 0x108) != 0 )
  {
    base = v2->_base;
    ptr = v2->_ptr;
    v2->_ptr = base + 1;
    v8 = ptr - base;
    v2->_cnt = v2->_bufsiz - 1;
    if ( v8 <= 0 )
    {
      if ( str == -1 || str == -2 )
        v9 = &__badioinfo;
      else
        v9 = &__pioinfo[str >> 5][str & 0x1F];
      if ( (v9->osfile & 0x20) != 0 )
      {
        v10.bigint = _lseeki64(fh: str, pos: 0, mthd: 2u).bigint;
        if ( (v10.twoints.upperhalf & v10.twoints.lowerhalf) == -1 )
          goto LABEL_27;
      }
    }
    else
    {
      written = _write(fh: str, buf: base, cnt: v8);
    }
    *v2->_base = ch;
  }
  else
  {
    v8 = 1;
    written = _write(fh: str, buf: &ch, cnt: 1u);
  }
  if ( written != v8 )
  {
LABEL_27:
    v2->_flag |= 0x20u;
    return -1;
  }
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x10047D13
// Name: __write_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _write_nolock(int fh, char *buf, unsigned int cnt)
{
  ioinfo **v4; // ebx
  ioinfo *v5; // eax
  int v6; // edi
  char v7; // cl
  BOOL v8; // esi
  UINT ConsoleCP; // eax
  char *v10; // ebx
  unsigned __int8 v11; // cl
  ioinfo **v12; // esi
  int v13; // eax
  int v14; // eax
  DWORD v15; // eax
  signed int v16; // esi
  ioinfo *v17; // eax
  int v18; // esi
  ioinfo *v19; // ecx
  char v20; // dl
  char *v21; // ebx
  unsigned int v22; // esi
  unsigned int v23; // ecx
  char *v24; // eax
  char v25; // dl
  signed int v26; // esi
  char *v27; // ebx
  unsigned int v28; // ecx
  char *v29; // eax
  int v30; // edx
  signed int v31; // esi
  unsigned int v32; // ecx
  WCHAR *v33; // eax
  int v34; // edx
  int v35; // esi
  int v36; // ebx
  BOOL v37; // [esp+8h] [ebp-1AE4h]
  unsigned int Mode; // [esp+Ch] [ebp-1AE0h] BYREF
  ioinfo **v39; // [esp+10h] [ebp-1ADCh]
  unsigned int v40; // [esp+14h] [ebp-1AD8h] BYREF
  unsigned int NumberOfBytesWritten; // [esp+18h] [ebp-1AD4h] BYREF
  int v42; // [esp+1Ch] [ebp-1AD0h]
  char *s; // [esp+20h] [ebp-1ACCh]
  unsigned int v44; // [esp+24h] [ebp-1AC8h]
  char v45; // [esp+2Bh] [ebp-1AC1h]
  unsigned int v46; // [esp+2Ch] [ebp-1AC0h]
  wchar_t pwc[2]; // [esp+30h] [ebp-1ABCh] BYREF
  char Buffer[1704]; // [esp+34h] [ebp-1AB8h] BYREF
  char v49[3416]; // [esp+6DCh] [ebp-1410h] BYREF
  WCHAR WideCharStr[854]; // [esp+1434h] [ebp-6B8h] BYREF
  char MultiByteStr[8]; // [esp+1AE0h] [ebp-Ch] BYREF

  s = buf;
  v44 = 0;
  v42 = 0;
  if ( cnt == 0 )
    return 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v4 = &__pioinfo[fh >> 5];
  v5 = *v4;
  v6 = (fh & 0x1F) << 6;
  v7 = (char)(2 * *((_BYTE *)*v4 + v6 + 36)) >> 1;
  v39 = v4;
  v45 = v7;
  if ( (v7 == 2 || v7 == 1) && (cnt & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( (*(&v5->osfile + v6) & 0x20) != 0 )
    _lseeki64_nolock(fh, pos: 0, mthd: 2u);
  if ( _isatty(fh) != 0 && *(&(*v4)->osfile + v6) < 0 )
  {
    v8 = _getptd()->ptlocinfo->lc_handle[2] == 0;
    if ( GetConsoleMode(hConsoleHandle: *(HANDLE *)((char *)&(*v4)->osfhnd + v6), lpMode: &Mode) && (!v8 || v45 != 0) )
    {
      ConsoleCP = GetConsoleCP();
      v10 = s;
      Mode = ConsoleCP;
      NumberOfBytesWritten = 0;
      v46 = 0;
      while ( 1 )
      {
        if ( v45 != 0 )
        {
          if ( v45 == 1 || v45 == 2 )
          {
            v18 = *(unsigned __int16 *)v10;
            v10 += 2;
            v46 += 2;
            *(_DWORD *)pwc = v18;
            v37 = v18 == 10;
          }
          if ( v45 == 1 || v45 == 2 )
          {
            if ( _putwch_nolock(ch: pwc[0]) != pwc[0] )
              goto LABEL_85;
            v44 += 2;
            if ( v37 )
            {
              wcscpy(pwc, L"\r");
              if ( _putwch_nolock(ch: 0xDu) != pwc[0] )
                goto LABEL_85;
              ++v44;
              ++v42;
            }
          }
          goto LABEL_43;
        }
        v11 = *v10;
        v12 = v39;
        v37 = *v10 == 10;
        v13 = (int)*v39 + v6;
        if ( *(_DWORD *)(v13 + 56) != 0 )
        {
          MultiByteStr[0] = *(_BYTE *)(v13 + 52);
          MultiByteStr[1] = v11;
          *(_DWORD *)(v13 + 56) = 0;
          v14 = mbtowc(pwc, s: MultiByteStr, n: 2u);
        }
        else
        {
          if ( isleadbyte(c: v11) != 0 )
          {
            if ( cnt + s - v10 <= 1 )
            {
              v19 = *v12;
              v20 = *v10;
              ++v44;
              *(&v19->dbcsBuffer + v6) = v20;
              *(int *)((char *)&(*v12)->dbcsBufferUsed + v6) = 1;
              goto LABEL_86;
            }
            if ( mbtowc(pwc, s: v10, n: 2u) == -1 )
              goto LABEL_86;
            ++v10;
            ++v46;
            goto LABEL_27;
          }
          v14 = mbtowc(pwc, s: v10, n: 1u);
        }
        if ( v14 == -1 )
          goto LABEL_86;
LABEL_27:
        ++v10;
        ++v46;
        v15 = WideCharToMultiByte(
                CodePage: Mode,
                dwFlags: 0,
                lpWideCharStr: pwc,
                cchWideChar: 1,
                lpMultiByteStr: MultiByteStr,
                cbMultiByte: 5,
                lpDefaultChar: nullptr,
                lpUsedDefaultChar: nullptr);
        v16 = v15;
        if ( v15 == 0 )
          goto LABEL_86;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                lpBuffer: MultiByteStr,
                nNumberOfBytesToWrite: v15,
                lpNumberOfBytesWritten: &NumberOfBytesWritten,
                lpOverlapped: nullptr) )
          goto LABEL_85;
        v44 = v42 + v46;
        if ( (int)NumberOfBytesWritten < v16 )
          goto LABEL_86;
        if ( v37 )
        {
          v17 = *v39;
          MultiByteStr[0] = 13;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&v17->osfhnd + v6),
                  lpBuffer: MultiByteStr,
                  nNumberOfBytesToWrite: 1u,
                  lpNumberOfBytesWritten: &NumberOfBytesWritten,
                  lpOverlapped: nullptr) )
            goto LABEL_85;
          if ( (int)NumberOfBytesWritten < 1 )
            goto LABEL_86;
          ++v42;
          ++v44;
        }
LABEL_43:
        if ( v46 >= cnt )
          goto LABEL_86;
      }
    }
  }
  if ( *(&(*v4)->osfile + v6) >= 0 )
  {
    if ( WriteFile(
           hFile: (HANDLE)(*v4)[fh & 0x1F].osfhnd,
           lpBuffer: s,
           nNumberOfBytesToWrite: cnt,
           lpNumberOfBytesWritten: &v40,
           lpOverlapped: nullptr) )
    {
      *(_DWORD *)pwc = 0;
      v44 = v40;
      goto LABEL_86;
    }
  }
  else
  {
    *(_DWORD *)pwc = 0;
    if ( v45 != 0 )
    {
      if ( v45 == 2 )
      {
        v27 = s;
        while ( 1 )
        {
          v46 = 0;
          v28 = v27 - s;
          v29 = Buffer;
          do
          {
            if ( v28 >= cnt )
              break;
            v30 = *(unsigned __int16 *)v27;
            v27 += 2;
            v28 += 2;
            Mode = (unsigned int)v27;
            if ( v30 == 10 )
            {
              v42 += 2;
              *(_WORD *)v29 = 13;
              v27 = (char *)Mode;
              v29 += 2;
              v46 += 2;
            }
            v46 += 2;
            *(_WORD *)v29 = v30;
            v29 += 2;
          }
          while ( v46 < 0x13FE );
          v31 = v29 - Buffer;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                  lpBuffer: Buffer,
                  nNumberOfBytesToWrite: v29 - Buffer,
                  lpNumberOfBytesWritten: &v40,
                  lpOverlapped: nullptr) )
            break;
          v44 += v40;
          if ( (int)v40 < v31 || v27 - s >= cnt )
            goto LABEL_86;
        }
      }
      else
      {
        NumberOfBytesWritten = (unsigned int)s;
        while ( 1 )
        {
          v46 = 0;
          v32 = NumberOfBytesWritten - (_DWORD)s;
          v33 = WideCharStr;
          do
          {
            if ( v32 >= cnt )
              break;
            v34 = *(unsigned __int16 *)NumberOfBytesWritten;
            NumberOfBytesWritten += 2;
            v32 += 2;
            if ( v34 == 10 )
            {
              *v33++ = 13;
              v46 += 2;
            }
            v46 += 2;
            *v33++ = v34;
          }
          while ( v46 < 0x6A8 );
          v35 = 0;
          v36 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: WideCharStr,
                  cchWideChar: v33 - WideCharStr,
                  lpMultiByteStr: v49,
                  cbMultiByte: 3413,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          if ( v36 == 0 )
            break;
          while ( WriteFile(
                    hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                    lpBuffer: &v49[v35],
                    nNumberOfBytesToWrite: v36 - v35,
                    lpNumberOfBytesWritten: &v40,
                    lpOverlapped: nullptr) )
          {
            v35 += v40;
            if ( v36 <= v35 )
              goto LABEL_80;
          }
          *(_DWORD *)pwc = GetLastError();
LABEL_80:
          if ( v36 <= v35 )
          {
            v44 = NumberOfBytesWritten - (_DWORD)s;
            if ( NumberOfBytesWritten - (unsigned int)s < cnt )
              continue;
          }
          goto LABEL_86;
        }
      }
    }
    else
    {
      v21 = s;
      while ( 1 )
      {
        v22 = 0;
        v23 = v21 - s;
        v24 = Buffer;
        do
        {
          if ( v23 >= cnt )
            break;
          v25 = *v21++;
          ++v23;
          Mode = (unsigned int)v21;
          if ( v25 == 10 )
          {
            ++v42;
            *v24++ = 13;
            ++v22;
          }
          *v24++ = v25;
          ++v22;
        }
        while ( v22 < 0x13FF );
        v26 = v24 - Buffer;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                lpBuffer: Buffer,
                nNumberOfBytesToWrite: v24 - Buffer,
                lpNumberOfBytesWritten: &v40,
                lpOverlapped: nullptr) )
          break;
        v44 += v40;
        if ( (int)v40 < v26 || v21 - s >= cnt )
          goto LABEL_86;
      }
    }
  }
LABEL_85:
  *(_DWORD *)pwc = GetLastError();
LABEL_86:
  if ( v44 == 0 )
  {
    if ( *(_DWORD *)pwc != 0 )
    {
      if ( *(_DWORD *)pwc == 5 )
      {
        *_errno() = 9;
        *__doserrno() = 5;
      }
      else
      {
        _dosmaperr(oserrno: *(unsigned int *)pwc);
      }
    }
    else
    {
      if ( (*(&(*v39)->osfile + v6) & 0x40) != 0 && *s == 26 )
        return 0;
      *_errno() = 28;
      *__doserrno() = 0;
    }
    return -1;
  }
  return v44 - v42;
}

} // namespace vvis_dll
