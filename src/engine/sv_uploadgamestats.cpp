// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_uploadgamestats.cpp
// Functions: 30
// ============================================================

#include "engine\sv_uploadgamestats.h"

//------------------------------------------------------------------------------
// Address: 0x10130400
// Name: void UpdateProgress(struct TGameStatsParameters const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void UpdateProgress(const TGameStatsParameters *params, char *fmt, ...)
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
    params->m_pOptionalProgressFunc(a1: params->m_uProgressContext, a2: (const TGameStatsProgress *)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130490
// Name: private: bool CWin32UploadGameStats::CreateTCPSocket(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::CreateTCPSocket(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *__formal)
{
  SOCKET v4; // eax

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Creating game stats upload socket.");
  v4 = socket(af: 2, type: 1, protocol: 6);
  this->m_SocketTCP = v4;
  if ( v4 == -1 )
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Socket creation failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101304F0
// Name: private: bool CWin32UploadGameStats::ConnectToHarvesterServer(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::ConnectToHarvesterServer(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *__formal)
{
  UpdateProgress(params: this->m_rCrashParameters, fmt: "Connecting to game stats harvesting server.");
  if ( connect(s: this->m_SocketTCP, name: (const struct sockaddr *)&this->m_HarvesterSockAddr, namelen: 16) == -1 )
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Connection failed.");
    *status = eGameStatsConnectToCSERServerFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 2;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130550
// Name: private: bool CWin32UploadGameStats::SendWholeFile(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::SendWholeFile(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *__formal)
{
  UpdateProgress(params: this->m_rCrashParameters, fmt: "Uploading game stats data.");
  if ( send(
         s: this->m_SocketTCP,
         buf: (const char *)this->m_rCrashParameters->m_pStatsBlobData,
         len: this->m_rCrashParameters->m_uStatsBlobSize,
         flags: 0) == -1 )
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Send failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 7;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101305C0
// Name: private: bool CWin32UploadGameStats::CloseTCPSocket(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32UploadGameStats::CloseTCPSocket(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *__formal)
{
  UpdateProgress(params: this->m_rCrashParameters, fmt: "Closing socket, upload succeeded.");
  closesocket(s: this->m_SocketTCP);
  this->m_SocketTCP = 0;
  *status = eGameStatsUploadSucceeded;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10130600
// Name: public: struct CAsyncUploaderThread::DataEntry __near * CAsyncUploaderThread::DataEntry::AllocCopy(void)const
// Source: json
//------------------------------------------------------------------------------
CAsyncUploaderThread::DataEntry *__thiscall CAsyncUploaderThread::DataEntry::AllocCopy(
        CAsyncUploaderThread::DataEntry *this)
{
  CAsyncUploaderThread::DataEntry *result; // eax
  CAsyncUploaderThread::DataEntry *v3; // esi
  unsigned __int8 *v4; // ebx
  unsigned int lenMapName; // [esp+8h] [ebp-4h]

  if ( this->szMapName != nullptr )
    lenMapName = strlen(this->szMapName);
  else
    lenMapName = 0;
  result = (CAsyncUploaderThread::DataEntry *)MemAlloc_Alloc(nSize: this->uiBlobSize + lenMapName + 17);
  v3 = result;
  if ( result != nullptr )
  {
    result->uiBlobVersion = this->uiBlobVersion;
    result->uiBlobSize = this->uiBlobSize;
    result->szMapName = (const char *)&result[1];
    memcpy(dst: (unsigned __int8 *)&result[1], src: (unsigned __int8 *)this->szMapName, count: lenMapName);
    *((_BYTE *)&v3[1].szMapName + lenMapName) = 0;
    v4 = (unsigned __int8 *)&v3[1].szMapName + lenMapName + 1;
    v3->pvBlob = v4;
    memcpy(dst: v4, src: (unsigned __int8 *)this->pvBlob, count: this->uiBlobSize);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10130690
// Name: public: virtual void CUploadGameStats::InitConnection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUploadGameStats::InitConnection(CUploadGameStats *this)
{
  this->m_bConnected = false;
  netadr_s::Clear(this: &this->m_Adr);
  netadr_s::SetType(this: &this->m_Adr, newtype: NA_IP);
  this->m_flNextConnectAttempt = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101306C0
// Name: public: virtual void CUploadGameStats::UpdateConnection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUploadGameStats::UpdateConnection(CUploadGameStats *this)
{
  CStatTime *v2; // ecx
  ISteamUtils *m_pSteamUtils; // esi
  double v4; // st7
  float curTime; // [esp+4h] [ebp-Ch]
  int usPort; // [esp+8h] [ebp-8h] BYREF
  unsigned int unIP; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bConnected )
  {
    m_pSteamUtils = Steam3Client()->m_pSteamUtils;
    if ( m_pSteamUtils != nullptr || (m_pSteamUtils = Steam3Server()->m_pSteamGameServerUtils) != nullptr )
    {
      v4 = _Plat_FloatTime(this: v2);
      if ( this->m_flNextConnectAttempt <= v4 )
      {
        unIP = 0;
        usPort = 0;
        m_pSteamUtils->GetCSERIPPort(this: m_pSteamUtils, a2: &unIP, a3: (unsigned __int16 *)&usPort);
        if ( unIP != 0 )
        {
          netadr_s::SetIP(this: &this->m_Adr, unIP);
          netadr_s::SetPort(this: &this->m_Adr, newport: usPort);
          netadr_s::SetType(this: &this->m_Adr, newtype: NA_IP);
          this->m_bConnected = true;
        }
        else
        {
          curTime = v4;
          this->m_flNextConnectAttempt = curTime + 1.0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130770
// Name: public: virtual bool CUploadGameStats::IsGameStatsLoggingEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUploadGameStats::IsGameStatsLoggingEnabled(CUploadGameStats *this)
{
  int v1; // eax
  IRegistry *v3; // esi
  int v4; // edi

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-nogamestats") != 0 )
    return false;
  v3 = InstanceRegistry(subDirectoryUnderValve: "Steam");
  v4 = v3->ReadInt_2(this: v3, a2: "DisableGameStats", a3: 0);
  ReleaseInstancedRegistry(reg: v3);
  return v4 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101307C0
// Name: public: virtual void CUploadGameStats::GetPseudoUniqueId(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUploadGameStats::GetPseudoUniqueId(CUploadGameStats *this, char *buf, unsigned int bufsize)
{
  int v3; // ebx
  CSteam3Client *v4; // eax
  CSteam3Client *v5; // eax
  BOOL UserNameA; // eax
  IRegistry *v7; // edi
  char *v8; // eax
  int v9; // [esp-4h] [ebp-70h]
  char username[64]; // [esp+8h] [ebp-64h] BYREF
  char hex[20]; // [esp+48h] [ebp-24h] BYREF
  _GUID newId; // [esp+5Ch] [ebp-10h] BYREF

  v3 = bufsize;
  _V_memset(dest: buf, fill: 0, count: bufsize);
  V_strncpy(pDest: buf, pSrc: "unknown", maxLen: v3);
  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v4 = Steam3Client();
    if ( v4->m_pSteamUser->BLoggedOn(this: v4->m_pSteamUser) )
    {
      v5 = Steam3Client();
      if ( v5->m_pSteamUtils->GetConnectedUniverse(this: v5->m_pSteamUtils) == k_EUniverseBeta )
      {
        memset(username, 0, sizeof(username));
        _V_memset(dest: username, fill: 0, count: 64);
        bufsize = 63;
        UserNameA = GetUserNameA(lpBuffer: username, pcbBuffer: &bufsize);
        v9 = v3;
        if ( UserNameA )
        {
          username[63] = 0;
          V_strncpy(pDest: buf, pSrc: username, maxLen: v3);
          goto LABEL_13;
        }
        goto LABEL_12;
      }
    }
  }
  v7 = InstanceRegistry(subDirectoryUnderValve: "Steam");
  v8 = (char *)v7->ReadString_2(this: v7, a2: "PseudoUUID", a3: defaultValue);
  if ( v8 == nullptr || *v8 == 0 )
  {
    UuidCreate(Uuid: &newId);
    _V_memset(dest: hex, fill: 0, count: 17);
    V_binarytohex(in: (const unsigned __int8 *)&newId, inputbytes: 16, out: hex, outsize: 17);
    v7->WriteString_2(this: v7, a2: "PseudoUUID", a3: hex);
    v8 = hex;
  }
  V_strncpy(pDest: buf, pSrc: v8, maxLen: v3);
  ReleaseInstancedRegistry(reg: v7);
  if ( *buf == 0 )
  {
    if ( sv.m_bIsDedicated )
    {
      v9 = v3;
LABEL_12:
      V_strncpy(pDest: buf, pSrc: "unknown", maxLen: v9);
    }
LABEL_13:
    if ( *buf == 0 && sv.m_bIsDedicated )
      V_strncpy(pDest: buf, pSrc: "unknown", maxLen: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130930
// Name: public: virtual bool CUploadGameStats::IsHDREnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUploadGameStats::IsHDREnabled(CUploadGameStats *this)
{
  return g_pMaterialSystemHardwareConfig->GetHDREnabled(this: g_pMaterialSystemHardwareConfig);
}

//------------------------------------------------------------------------------
// Address: 0x10130940
// Name: private: bool CWin32UploadGameStats::DoBlockingReceive(unsigned int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::DoBlockingReceive(
        CWin32UploadGameStats *this,
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
    CUtlBuffer::Put(this: buf, pMem: (unsigned __int8 *)bufa, size: v4);
    if ( buf->m_Put >= bytesExpected )
      break;
    v4 = recv(s: this->m_SocketTCP, buf: bufa, len: 0x2000, flags: 0);
    if ( v4 <= 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101309F0
// Name: public: enum EGameStatsUploadStatus CWin32UploadGameStats::Upload(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
EGameStatsUploadStatus __thiscall CWin32UploadGameStats::Upload(CWin32UploadGameStats *this, CUtlBuffer *buf)
{
  EGameStatsUploadStatus v4; // [esp+8h] [ebp-4h] BYREF

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Commencing game stats upload connection.");
  v4 = eGameStatsUploadSucceeded;
  while ( this->m_States.m_Memory.m_pMemory[this->m_uCurrentState].second(this, a2: &v4, a3: buf) )
    ;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10130A40
// Name: private: bool CWin32UploadGameStats::ReceiveProtocolOkay(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::ReceiveProtocolOkay(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  unsigned __int8 v5; // cl

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Receiving harvesting protocol acknowledgement.");
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
  if ( CWin32UploadGameStats::DoBlockingReceive(this, bytesExpected: 1u, buf) != 0 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1)
      && (v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], ++buf->m_Get, v5 != 0) )
    {
      UpdateProgress(params: this->m_rCrashParameters, fmt: "Protocol OK.");
      this->m_uCurrentState = 4;
      return 1;
    }
    else
    {
      UpdateProgress(params: this->m_rCrashParameters, fmt: "Server rejected protocol.");
      *status = eGameStatsUploadFailed;
      return 0;
    }
  }
  else
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Didn't receive protocol failure data.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130B30
// Name: private: bool CWin32UploadGameStats::ReceiveOKToSendFile(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::ReceiveOKToSendFile(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  unsigned __int8 v5; // cl

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Receive game stats harvesting protocol upload permissible.");
  if ( CWin32UploadGameStats::DoBlockingReceive(this, bytesExpected: 1u, buf) != 0 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1)
      && (v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], ++buf->m_Get, v5 != 0) )
    {
      UpdateProgress(params: this->m_rCrashParameters, fmt: "Server rejected upload command.");
      *status = eGameStatsUploadFailed;
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
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Receive failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130BD0
// Name: private: bool CWin32UploadGameStats::ReceiveFileUploadSuccess(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::ReceiveFileUploadSuccess(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  unsigned __int8 v5; // cl

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Receiving game stats upload success/fail message.");
  if ( CWin32UploadGameStats::DoBlockingReceive(this, bytesExpected: 1u, buf) != 0 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1)
      && (v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], ++buf->m_Get, v5 == 1) )
    {
      UpdateProgress(params: this->m_rCrashParameters, fmt: "Upload OK.");
      this->m_uCurrentState = 8;
      return 1;
    }
    else
    {
      UpdateProgress(params: this->m_rCrashParameters, fmt: "Upload failed.");
      *status = eGameStatsUploadFailed;
      return 0;
    }
  }
  else
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Receive failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130C80
// Name: public: void CAsyncUploaderThread::ThreadProc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall __noreturn CAsyncUploaderThread::ThreadProc(CAsyncUploaderThread *this)
{
  CAsyncUploaderThread *v1; // ebx
  CAsyncUploaderThread::DataEntry *v2; // esi
  CThreadFastMutex *p_m_mtx; // edi
  DWORD CurrentThreadId; // ecx

  v1 = this;
  while ( 1 )
  {
    v2 = nullptr;
    p_m_mtx = &v1->m_mtx;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId == v1->m_mtx.m_ownerID )
      goto LABEL_5;
    if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtx, CurrentThreadId, 0) == 0 )
      break;
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mtx, a2: CurrentThreadId, a3: 0);
    v1 = this;
LABEL_7:
    if ( v1->m_queue.m_Size != 0 )
    {
      v2 = *v1->m_queue.m_Memory.m_pMemory;
      if ( v1->m_queue.m_Size - 1 > 0 )
        _V_memmove(
          dest: v1->m_queue.m_Memory.m_pMemory,
          src: v1->m_queue.m_Memory.m_pMemory + 1,
          count: 4 * (v1->m_queue.m_Size - 1));
      --v1->m_queue.m_Size;
    }
    if ( p_m_mtx->m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mtx, 0);
    if ( v2 != nullptr )
    {
      g_pUploadGameStats->UploadGameStats(
        this: g_pUploadGameStats,
        a2: v2->szMapName,
        a3: v2->uiBlobVersion,
        a4: v2->uiBlobSize,
        a5: v2->pvBlob);
      _ThreadSleep(a1: 10000);
      free(pMem: v2);
    }
    else
    {
      _ThreadSleep(a1: 60000);
    }
  }
  v1 = this;
LABEL_5:
  ++p_m_mtx->m_depth;
  goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x10130DC0
// Name: public: CWin32UploadGameStats::~CWin32UploadGameStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32UploadGameStats::~CWin32UploadGameStats(CWin32UploadGameStats *this)
{
  if ( this->m_SocketTCP != 0 )
  {
    closesocket(s: this->m_SocketTCP);
    this->m_SocketTCP = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10130DE0
// Name: private: bool CWin32UploadGameStats::SendProtocolVersion(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::SendProtocolVersion(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  UpdateProgress(params: this->m_rCrashParameters, fmt: "Sending game stats harvester protocol info.");
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
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Send failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 3;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130EA0
// Name: private: bool CWin32UploadGameStats::SendUploadCommand(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::SendUploadCommand(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  int m_Put; // eax
  unsigned int m_ContextID; // [esp-4h] [ebp-10h]
  unsigned int m_uStatsBlobSize; // [esp-4h] [ebp-10h]

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Sending harvesting protocol upload request.");
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
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
  {
    buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 1;
    CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
  }
  m_ContextID = this->m_ContextID;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_ContextID);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_ContextID);
  m_uStatsBlobSize = this->m_rCrashParameters->m_uStatsBlobSize;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_uStatsBlobSize);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_uStatsBlobSize);
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
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Send failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 5;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131030
// Name: private: bool CWin32UploadGameStats::SendGracefulClose(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::SendGracefulClose(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  int m_Put; // eax

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Closing connection to server.");
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
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
  {
    buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
  }
  if ( send(s: this->m_SocketTCP, buf: (const char *)buf->m_Memory.m_pMemory, len: buf->m_Put, flags: 0) == -1 )
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Send failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 9;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131130
// Name: public: static unsigned int CAsyncUploaderThread::CallbackThreadProc(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn CAsyncUploaderThread::CallbackThreadProc(CAsyncUploaderThread *pvParam)
{
  CAsyncUploaderThread::ThreadProc(this: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x10131140
// Name: public: void CAsyncUploaderThread::QueueData(char const __near *,unsigned int,unsigned int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncUploaderThread::QueueData(
        CAsyncUploaderThread *this,
        CAsyncUploaderThread::DataEntry *szMapName,
        unsigned int uiBlobVersion,
        unsigned int uiBlobSize,
        const void *pvBlob)
{
  CThreadFastMutex *p_m_mtx; // ebx
  DWORD CurrentThreadId; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CAsyncUploaderThread::DataEntry **m_pMemory; // ecx
  int v11; // eax
  CAsyncUploaderThread::DataEntry **v12; // eax
  CAsyncUploaderThread::DataEntry de; // [esp+4h] [ebp-14h] BYREF
  CAsyncUploaderThread::DataEntry *pNew; // [esp+20h] [ebp+8h]

  de.szMapName = (const char *)szMapName;
  de.uiBlobVersion = uiBlobVersion;
  de.uiBlobSize = uiBlobSize;
  de.pvBlob = pvBlob;
  pNew = CAsyncUploaderThread::DataEntry::AllocCopy(this: &de);
  if ( pNew != nullptr )
  {
    p_m_mtx = &this->m_mtx;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mtx.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtx, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mtx, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mtx.m_depth;
    }
    m_Size = this->m_queue.m_Size;
    m_nAllocationCount = this->m_queue.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_queue,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_queue.m_Size;
    m_pMemory = this->m_queue.m_Memory.m_pMemory;
    v11 = this->m_queue.m_Size - m_Size - 1;
    this->m_queue.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
    v12 = &this->m_queue.m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      *v12 = pNew;
    if ( this->m_hThread == nullptr )
      this->m_hThread = (ThreadHandle_t__ *)_CreateSimpleThread(
                                              a1: CAsyncUploaderThread::CallbackThreadProc,
                                              a2: this,
                                              a3: 0);
    if ( this->m_mtx.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mtx, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131230
// Name: void AsyncUpload_QueueData(char const __near *,unsigned int,unsigned int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AsyncUpload_QueueData(
        CAsyncUploaderThread::DataEntry *szMapName,
        unsigned int uiBlobVersion,
        unsigned int uiBlobSize,
        const void *pvBlob)
{
  CAsyncUploaderThread::QueueData(this: &g_AsyncUploader, szMapName, uiBlobVersion, uiBlobSize, pvBlob);
}

//------------------------------------------------------------------------------
// Address: 0x10131250
// Name: public: CWin32UploadGameStats::CWin32UploadGameStats(struct netadr_s const __near &,struct TGameStatsParameters const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CWin32UploadGameStats *__thiscall CWin32UploadGameStats::CWin32UploadGameStats(
        CWin32UploadGameStats *this,
        netadr_s *harvester,
        const TGameStatsParameters *rGameStatsParameters,
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
  int v15; // [esp-8h] [ebp-18h]
  vgui::PropertySheet::Page_t src; // [esp+8h] [ebp-8h] BYREF

  this->m_States.m_Memory.m_pMemory = nullptr;
  this->m_States.m_Memory.m_nAllocationCount = 0;
  this->m_States.m_Memory.m_nGrowSize = 0;
  this->m_States.m_Size = 0;
  this->m_States.m_pElements = nullptr;
  this->m_uCurrentState = 0;
  *(_DWORD *)&this->m_HarvesterSockAddr.sin_family = 0;
  this->m_HarvesterSockAddr.sin_addr.S_un.S_addr = 0;
  *(_DWORD *)this->m_HarvesterSockAddr.sin_zero = 0;
  *(_DWORD *)&this->m_HarvesterSockAddr.sin_zero[4] = 0;
  this->m_rCrashParameters = rGameStatsParameters;
  this->m_SocketTCP = 0;
  this->m_ContextID = contextid;
  netadr_s::ToSockadr(this: harvester, s: (sockaddr *)&this->m_HarvesterSockAddr);
  m_Size = this->m_States.m_Size;
  src.page = nullptr;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::CreateTCPSocket;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: m_Size,
    &src);
  v7 = this->m_States.m_Size;
  src.page = (vgui::Panel *)1;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::ConnectToHarvesterServer;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v7,
    &src);
  v8 = this->m_States.m_Size;
  src.page = (vgui::Panel *)2;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::SendProtocolVersion;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v8,
    &src);
  v9 = this->m_States.m_Size;
  src.page = (vgui::Panel *)3;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::ReceiveProtocolOkay;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v9,
    &src);
  v10 = this->m_States.m_Size;
  src.page = (vgui::Panel *)4;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::SendUploadCommand;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v10,
    &src);
  v11 = this->m_States.m_Size;
  src.page = (vgui::Panel *)5;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::ReceiveOKToSendFile;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v11,
    &src);
  v12 = this->m_States.m_Size;
  src.page = (vgui::Panel *)6;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::SendWholeFile;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v12,
    &src);
  src.page = (vgui::Panel *)7;
  v13 = this->m_States.m_Size;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::ReceiveFileUploadSuccess;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v13,
    &src);
  v14 = this->m_States.m_Size;
  src.page = (vgui::Panel *)8;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::SendGracefulClose;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v14,
    &src);
  v15 = this->m_States.m_Size;
  src.page = (vgui::Panel *)9;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::CloseTCPSocket;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v15,
    &src);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101313C0
// Name: enum EGameStatsUploadStatus Win32UploadGameStatsBlocking(struct TGameStatsParameters const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __cdecl Win32UploadGameStatsBlocking(const TGameStatsParameters *rGameStatsParameters)
{
  unsigned int m_uStatsBlobSize; // eax
  unsigned int m_Socket; // edx
  int v4; // eax
  char *v6; // eax
  int v7; // eax
  char v8; // cl
  char v9; // cl
  int Int; // edi
  u_short Short; // bx
  char *v12; // eax
  unsigned int m_uAppId; // [esp+0h] [ebp-CCh]
  unsigned int v14; // [esp+0h] [ebp-CCh]
  CWin32UploadGameStats v15; // [esp+10h] [ebp-BCh] BYREF
  int v16; // [esp+44h] [ebp-88h] BYREF
  sockaddr_in replyaddress; // [esp+4Ch] [ebp-80h] BYREF
  sockaddr_in sa; // [esp+5Ch] [ebp-70h] BYREF
  sockaddr_in adr; // [esp+6Ch] [ebp-60h] BYREF
  netadr_s GameStatsHarvesterFSMIPAddress; // [esp+7Ch] [ebp-50h] BYREF
  CBlockingUDPSocket bcs; // [esp+88h] [ebp-44h] BYREF
  EGameStatsUploadStatus status; // [esp+A0h] [ebp-2Ch]
  _BYTE buf[28]; // [esp+A4h] [ebp-28h] OVERLAPPED BYREF
  unsigned int v24; // [esp+D4h] [ebp+8h]

  m_uStatsBlobSize = rGameStatsParameters->m_uStatsBlobSize;
  *(_DWORD *)&bcs.m_cserIP.port = 0;
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&bcs.m_Socket, growSize: m_uStatsBlobSize + 4096, initSize: 0, nFlags: 0);
  UpdateProgress(params: rGameStatsParameters, fmt: "Creating initial report.");
  CUtlBuffer::SetBigEndian(this: (CUtlBuffer *)&bcs.m_Socket, bigEndian: false);
  m_Socket = bcs.m_Socket;
  v4 = 0;
  memset(&buf[4], 0, 9);
  *(_DWORD *)&buf[24] = 0;
  *(_DWORD *)&buf[20] = 0;
  if ( *(int *)buf >= 0 )
  {
    if ( bcs.m_Socket != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)bcs.m_Socket);
      v4 = *(_DWORD *)&buf[8];
      m_Socket = 0;
      bcs.m_Socket = 0;
    }
    status = eGameStatsUploadSucceeded;
  }
  if ( (buf[13] & 1) != 0 && v4 != 0 && *(_BYTE *)(v4 - *(_DWORD *)&buf[24] + m_Socket - 1) == 10 )
    CUtlBuffer::PutTabs(this: (CUtlBuffer *)&bcs.m_Socket);
  if ( CUtlBuffer::CheckPut(this: (CUtlBuffer *)&bcs.m_Socket, nSize: 1) != 0 )
  {
    *(_BYTE *)(*(_DWORD *)&buf[8] - *(_DWORD *)&buf[24] + bcs.m_Socket) = 107;
    ++*(_DWORD *)&buf[8];
    CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&bcs.m_Socket, nPut: *(int *)&buf[8]);
  }
  if ( (buf[13] & 1) != 0
    && *(_DWORD *)&buf[8] != 0
    && *(_BYTE *)(*(_DWORD *)&buf[8] - *(_DWORD *)&buf[24] + bcs.m_Socket - 1) == 10 )
  {
    CUtlBuffer::PutTabs(this: (CUtlBuffer *)&bcs.m_Socket);
  }
  if ( CUtlBuffer::CheckPut(this: (CUtlBuffer *)&bcs.m_Socket, nSize: 1) != 0 )
  {
    *(_BYTE *)(*(_DWORD *)&buf[8] - *(_DWORD *)&buf[24] + bcs.m_Socket) = 10;
    ++*(_DWORD *)&buf[8];
    CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&bcs.m_Socket, nPut: *(int *)&buf[8]);
  }
  if ( (buf[13] & 1) != 0
    && *(_DWORD *)&buf[8] != 0
    && *(_BYTE *)(*(_DWORD *)&buf[8] - *(_DWORD *)&buf[24] + bcs.m_Socket - 1) == 10 )
  {
    CUtlBuffer::PutTabs(this: (CUtlBuffer *)&bcs.m_Socket);
  }
  if ( CUtlBuffer::CheckPut(this: (CUtlBuffer *)&bcs.m_Socket, nSize: 1) != 0 )
  {
    *(_BYTE *)(*(_DWORD *)&buf[8] - *(_DWORD *)&buf[24] + bcs.m_Socket) = 2;
    ++*(_DWORD *)&buf[8];
    CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&bcs.m_Socket, nPut: *(int *)&buf[8]);
  }
  m_uAppId = rGameStatsParameters->m_uAppId;
  if ( (buf[13] & 1) != 0 )
    CUtlBuffer::Printf(this: (CUtlBuffer *)&bcs.m_Socket, pFmt: "%d", m_uAppId);
  else
    CUtlBuffer::PutTypeBin<int>(this: (CUtlBuffer *)&bcs.m_Socket, src: m_uAppId);
  v14 = rGameStatsParameters->m_uStatsBlobSize;
  if ( (buf[13] & 1) != 0 )
    CUtlBuffer::Printf(this: (CUtlBuffer *)&bcs.m_Socket, pFmt: "%d", v14);
  else
    CUtlBuffer::PutTypeBin<int>(this: (CUtlBuffer *)&bcs.m_Socket, src: v14);
  CBlockingUDPSocket::CBlockingUDPSocket(this: (CBlockingUDPSocket *)GameStatsHarvesterFSMIPAddress.ip);
  if ( *(_DWORD *)bcs.m_cserIP.ip != 0 )
  {
    netadr_s::ToSockadr(this: &rGameStatsParameters->m_ipCSERServer, s: (sockaddr *)replyaddress.sin_zero);
    v6 = netadr_s::ToString(this: &rGameStatsParameters->m_ipCSERServer, baseOnly: false);
    UpdateProgress(params: rGameStatsParameters, fmt: "Sending game stats to server %s.", v6);
    CBlockingUDPSocket::SendSocketMessage(
      this: (CBlockingUDPSocket *)GameStatsHarvesterFSMIPAddress.ip,
      rRecipient: (const sockaddr_in *)replyaddress.sin_zero,
      buf: (const unsigned __int8 *)bcs.m_Socket,
      bufsize: *(unsigned int *)&buf[8]);
    UpdateProgress(params: rGameStatsParameters, fmt: "Waiting for response.");
    if ( CBlockingUDPSocket::WaitForMessage(
           this: (CBlockingUDPSocket *)GameStatsHarvesterFSMIPAddress.ip,
           timeOutInSeconds: 2.0) )
    {
      UpdateProgress(params: rGameStatsParameters, fmt: "Received response.");
      CUtlBuffer::EnsureCapacity(this: (CUtlBuffer *)&bcs.m_Socket, num: 4096);
      v7 = CBlockingUDPSocket::ReceiveSocketMessage(
             this: (CBlockingUDPSocket *)GameStatsHarvesterFSMIPAddress.ip,
             packet_from: (int)&v16,
             buf: (unsigned __int8 *)bcs.m_Socket,
             bufsize: 0x1000u);
      if ( v7 != 0 )
      {
        CUtlBuffer::SeekPut(this: (CUtlBuffer *)&bcs.m_Socket, type: SEEK_HEAD, offset: v7);
        UpdateProgress(params: rGameStatsParameters, fmt: "Checking response.");
        if ( !CUtlBuffer::CheckGet(this: (CUtlBuffer *)&bcs.m_Socket, nSize: 1)
          || (v8 = *(_BYTE *)(*(_DWORD *)&buf[4] - *(_DWORD *)&buf[24] + bcs.m_Socket), ++*(_DWORD *)&buf[4], v8 != 108) )
        {
          UpdateProgress(params: rGameStatsParameters, fmt: "Request denied, invalid message type.");
          CBlockingUDPSocket::~CBlockingUDPSocket(this: (CBlockingUDPSocket *)GameStatsHarvesterFSMIPAddress.ip);
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&bcs.m_Socket);
          return 5;
        }
        if ( !CUtlBuffer::CheckGet(this: (CUtlBuffer *)&bcs.m_Socket, nSize: 1)
          || (v9 = *(_BYTE *)(*(_DWORD *)&buf[4] - *(_DWORD *)&buf[24] + bcs.m_Socket), ++*(_DWORD *)&buf[4], v9 != 1) )
        {
          UpdateProgress(params: rGameStatsParameters, fmt: "Request denied, invalid message protocol.");
          CBlockingUDPSocket::~CBlockingUDPSocket(this: (CBlockingUDPSocket *)GameStatsHarvesterFSMIPAddress.ip);
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&bcs.m_Socket);
          return 5;
        }
        if ( CUtlBuffer::GetChar(this: (CUtlBuffer *)&bcs.m_Socket) != 2 )
        {
          UpdateProgress(params: rGameStatsParameters, fmt: "Stats report accepted, data upload skipped.");
          CBlockingUDPSocket::~CBlockingUDPSocket(this: (CBlockingUDPSocket *)GameStatsHarvesterFSMIPAddress.ip);
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&bcs.m_Socket);
          return 0;
        }
        Int = CUtlBuffer::GetInt(this: (CUtlBuffer *)&bcs.m_Socket);
        Short = CUtlBuffer::GetShort(this: (CUtlBuffer *)&bcs.m_Socket);
        v24 = CUtlBuffer::GetInt(this: (CUtlBuffer *)&bcs.m_Socket);
        *(_WORD *)sa.sin_zero = 2;
        *(_WORD *)&sa.sin_zero[2] = htons(hostshort: Short);
        *(_DWORD *)&sa.sin_zero[4] = Int;
        netadr_s::netadr_s(this: (netadr_s *)adr.sin_zero);
        netadr_s::SetFromSockadr(this: (netadr_s *)adr.sin_zero, s: (const sockaddr *)sa.sin_zero);
        v12 = netadr_s::ToString(this: (netadr_s *)adr.sin_zero, baseOnly: false);
        UpdateProgress(params: rGameStatsParameters, fmt: "Server requested game stats upload to %s.", v12);
        CWin32UploadGameStats::CWin32UploadGameStats(
          this: &v15,
          harvester: (netadr_s *)adr.sin_zero,
          rGameStatsParameters,
          contextid: v24);
        *(_DWORD *)&bcs.m_cserIP.port = CWin32UploadGameStats::Upload(this: &v15, buf: (CUtlBuffer *)&bcs.m_Socket);
        CWin32UploadGameStats::~CWin32UploadGameStats(this: &v15);
      }
    }
    else
    {
      UpdateProgress(params: rGameStatsParameters, fmt: "No response from server.");
    }
    CBlockingUDPSocket::~CBlockingUDPSocket(this: (CBlockingUDPSocket *)GameStatsHarvesterFSMIPAddress.ip);
    if ( *(int *)buf >= 0 && bcs.m_Socket != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)bcs.m_Socket);
    return *(_DWORD *)&bcs.m_cserIP.port;
  }
  else
  {
    CBlockingUDPSocket::~CBlockingUDPSocket(this: (CBlockingUDPSocket *)GameStatsHarvesterFSMIPAddress.ip);
    if ( *(int *)buf >= 0 && bcs.m_Socket != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)bcs.m_Socket);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131810
// Name: public: virtual bool CUploadGameStats::UploadGameStats(char const __near *,unsigned int,unsigned int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUploadGameStats::UploadGameStats(
        CUploadGameStats *this,
        const char *mapname,
        unsigned int blobversion,
        unsigned int blobsize,
        void *pvBlobData)
{
  unsigned int SteamAppID; // edi
  int v8; // edx
  int v9; // eax
  TGameStatsParameters params; // [esp+4h] [ebp-E8h] BYREF

  this->UpdateConnection(this);
  if ( !this->m_bConnected )
    return false;
  SteamAppID = GetSteamAppID();
  if ( SteamAppID == 0 )
    return false;
  netadr_s::SetIP(this: &params.m_ipCSERServer, unIP: 0);
  netadr_s::SetPort(this: &params.m_ipCSERServer, newport: 0);
  netadr_s::SetType(this: &params.m_ipCSERServer, newtype: NA_IP);
  params.m_uAppId = 0;
  _V_memset(dest: (void *)&params, fill: 0, count: 232);
  v8 = *(_DWORD *)this->m_Adr.ip;
  v9 = *(_DWORD *)&this->m_Adr.port;
  params.m_ipCSERServer.type = this->m_Adr.type;
  *(_DWORD *)params.m_ipCSERServer.ip = v8;
  *(_DWORD *)&params.m_ipCSERServer.port = v9;
  params.m_uEngineBuildNumber = build_number();
  V_strncpy(pDest: params.m_sExecutableName, pSrc: "hl2.exe", maxLen: 64);
  V_FileBase(in: com_gamedir, out: params.m_sGameDirectory, maxlen: 64);
  V_FileBase(in: mapname, out: params.m_sMapName, maxlen: 64);
  params.m_uStatsBlobVersion = blobversion;
  params.m_uStatsBlobSize = blobsize;
  params.m_pStatsBlobData = pvBlobData;
  params.m_uAppId = SteamAppID;
  return Win32UploadGameStatsBlocking(rGameStatsParameters: &params) == eGameStatsUploadSucceeded;
}

//------------------------------------------------------------------------------
// Address: 0x10318770
// Name: _dynamic_initializer_for__stats__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stats__()
{
  ConCommand::ConCommand(
    this: &stats,
    pName: "stats",
    callback: Host_Stats_f,
    pHelpString: "Prints server performance variables",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stats__);
}

//------------------------------------------------------------------------------
// Address: 0x10324850
// Name: _dynamic_atexit_destructor_for__stats__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stats__()
{
  ConCommand::~ConCommand(this: &stats);
}

//------------------------------------------------------------------------------
// Address: 0x10324860
// Name: _dynamic_atexit_destructor_for__g_ServerRemoteAccess__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ServerRemoteAccess__()
{
  CServerRemoteAccess::~CServerRemoteAccess(this: &g_ServerRemoteAccess);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101304E0
// Name: void UpdateProgress(struct TGameStatsParameters const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void UpdateProgress(const TGameStatsParameters *params, char *fmt, ...)
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
    params->m_pOptionalProgressFunc(a1: params->m_uProgressContext, a2: (const TGameStatsProgress *)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130570
// Name: private: bool CWin32UploadGameStats::CreateTCPSocket(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::CreateTCPSocket(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *__formal)
{
  SOCKET v4; // eax

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Creating game stats upload socket.");
  v4 = socket(af: 2, type: 1, protocol: 6);
  this->m_SocketTCP = v4;
  if ( v4 == -1 )
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Socket creation failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101305D0
// Name: private: bool CWin32UploadGameStats::ConnectToHarvesterServer(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::ConnectToHarvesterServer(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *__formal)
{
  UpdateProgress(params: this->m_rCrashParameters, fmt: "Connecting to game stats harvesting server.");
  if ( connect(s: this->m_SocketTCP, name: (const struct sockaddr *)&this->m_HarvesterSockAddr, namelen: 16) == -1 )
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Connection failed.");
    *status = eGameStatsConnectToCSERServerFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 2;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130630
// Name: private: bool CWin32UploadGameStats::SendWholeFile(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::SendWholeFile(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *__formal)
{
  UpdateProgress(params: this->m_rCrashParameters, fmt: "Uploading game stats data.");
  if ( send(
         s: this->m_SocketTCP,
         buf: (const char *)this->m_rCrashParameters->m_pStatsBlobData,
         len: this->m_rCrashParameters->m_uStatsBlobSize,
         flags: 0) == -1 )
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Send failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 7;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101306A0
// Name: private: bool CWin32UploadGameStats::CloseTCPSocket(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWin32UploadGameStats::CloseTCPSocket(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *__formal)
{
  UpdateProgress(params: this->m_rCrashParameters, fmt: "Closing socket, upload succeeded.");
  closesocket(s: this->m_SocketTCP);
  this->m_SocketTCP = 0;
  *status = eGameStatsUploadSucceeded;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101306E0
// Name: public: struct CAsyncUploaderThread::DataEntry __near * CAsyncUploaderThread::DataEntry::AllocCopy(void)const
// Source: json
//------------------------------------------------------------------------------
CAsyncUploaderThread::DataEntry *__thiscall CAsyncUploaderThread::DataEntry::AllocCopy(
        CAsyncUploaderThread::DataEntry *this)
{
  CAsyncUploaderThread::DataEntry *result; // eax
  CAsyncUploaderThread::DataEntry *v3; // esi
  unsigned __int8 *v4; // ebx
  unsigned int lenMapName; // [esp+8h] [ebp-4h]

  if ( this->szMapName != nullptr )
    lenMapName = strlen(this->szMapName);
  else
    lenMapName = 0;
  result = (CAsyncUploaderThread::DataEntry *)MemAlloc_Alloc(nSize: this->uiBlobSize + lenMapName + 17);
  v3 = result;
  if ( result != nullptr )
  {
    result->uiBlobVersion = this->uiBlobVersion;
    result->uiBlobSize = this->uiBlobSize;
    result->szMapName = (const char *)&result[1];
    memcpy(dst: (unsigned __int8 *)&result[1], src: (unsigned __int8 *)this->szMapName, count: lenMapName);
    *((_BYTE *)&v3[1].szMapName + lenMapName) = 0;
    v4 = (unsigned __int8 *)&v3[1].szMapName + lenMapName + 1;
    v3->pvBlob = v4;
    memcpy(dst: v4, src: (unsigned __int8 *)this->pvBlob, count: this->uiBlobSize);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101307A0
// Name: public: virtual void CUploadGameStats::UpdateConnection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUploadGameStats::UpdateConnection(CUploadGameStats *this)
{
  int v2; // ecx
  ISteamUtils *m_pSteamUtils; // esi
  double v4; // st7
  float curTime; // [esp+4h] [ebp-Ch]
  int usPort; // [esp+8h] [ebp-8h] BYREF
  unsigned int unIP; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bConnected )
  {
    m_pSteamUtils = Steam3Client()->m_pSteamUtils;
    if ( m_pSteamUtils != nullptr || (m_pSteamUtils = Steam3Server()->m_pSteamGameServerUtils) != nullptr )
    {
      v4 = _Plat_FloatTime(a1: v2);
      if ( this->m_flNextConnectAttempt <= v4 )
      {
        unIP = 0;
        usPort = 0;
        m_pSteamUtils->GetCSERIPPort(this: m_pSteamUtils, a2: &unIP, a3: (unsigned __int16 *)&usPort);
        if ( unIP != 0 )
        {
          netadr_s::SetIP(this: &this->m_Adr, unIP);
          netadr_s::SetPort(this: &this->m_Adr, newport: usPort);
          netadr_s::SetType(this: &this->m_Adr, newtype: NA_IP);
          this->m_bConnected = true;
        }
        else
        {
          curTime = v4;
          this->m_flNextConnectAttempt = curTime + 1.0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130850
// Name: public: virtual bool CUploadGameStats::IsGameStatsLoggingEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUploadGameStats::IsGameStatsLoggingEnabled(CUploadGameStats *this)
{
  int v1; // eax
  IRegistry *v3; // esi
  int v4; // edi

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-nogamestats") != 0 )
    return false;
  v3 = InstanceRegistry(subDirectoryUnderValve: "Steam");
  v4 = v3->ReadInt_2(this: v3, a2: "DisableGameStats", a3: 0);
  ReleaseInstancedRegistry(reg: v3);
  return v4 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101308A0
// Name: public: virtual void CUploadGameStats::GetPseudoUniqueId(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUploadGameStats::GetPseudoUniqueId(CUploadGameStats *this, char *buf, unsigned int bufsize)
{
  int v3; // ebx
  CSteam3Client *v4; // eax
  CSteam3Client *v5; // eax
  BOOL UserNameA; // eax
  IRegistry *v7; // edi
  char *v8; // eax
  int v9; // [esp-4h] [ebp-70h]
  char username[64]; // [esp+8h] [ebp-64h] BYREF
  char hex[20]; // [esp+48h] [ebp-24h] BYREF
  _GUID newId; // [esp+5Ch] [ebp-10h] BYREF

  v3 = bufsize;
  _V_memset(dest: buf, fill: 0, count: bufsize);
  V_strncpy(pDest: buf, pSrc: "unknown", maxLen: v3);
  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v4 = Steam3Client();
    if ( v4->m_pSteamUser->BLoggedOn(this: v4->m_pSteamUser) )
    {
      v5 = Steam3Client();
      if ( v5->m_pSteamUtils->GetConnectedUniverse(this: v5->m_pSteamUtils) == k_EUniverseBeta )
      {
        memset(username, 0, sizeof(username));
        _V_memset(dest: username, fill: 0, count: 64);
        bufsize = 63;
        UserNameA = GetUserNameA(lpBuffer: username, pcbBuffer: &bufsize);
        v9 = v3;
        if ( UserNameA )
        {
          username[63] = 0;
          V_strncpy(pDest: buf, pSrc: username, maxLen: v3);
          goto LABEL_13;
        }
        goto LABEL_12;
      }
    }
  }
  v7 = InstanceRegistry(subDirectoryUnderValve: "Steam");
  v8 = (char *)v7->ReadString_2(this: v7, a2: "PseudoUUID", a3: defaultValue);
  if ( v8 == nullptr || *v8 == 0 )
  {
    UuidCreate(Uuid: &newId);
    _V_memset(dest: hex, fill: 0, count: 17);
    V_binarytohex(in: (const unsigned __int8 *)&newId, inputbytes: 16, out: hex, outsize: 17);
    v7->WriteString_2(this: v7, a2: "PseudoUUID", a3: hex);
    v8 = hex;
  }
  V_strncpy(pDest: buf, pSrc: v8, maxLen: v3);
  ReleaseInstancedRegistry(reg: v7);
  if ( *buf == 0 )
  {
    if ( sv.m_bIsDedicated )
    {
      v9 = v3;
LABEL_12:
      V_strncpy(pDest: buf, pSrc: "unknown", maxLen: v9);
    }
LABEL_13:
    if ( *buf == 0 && sv.m_bIsDedicated )
      V_strncpy(pDest: buf, pSrc: "unknown", maxLen: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130A10
// Name: public: virtual bool CUploadGameStats::IsHDREnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUploadGameStats::IsHDREnabled(CUploadGameStats *this)
{
  return g_pMaterialSystemHardwareConfig->GetHDREnabled(this: g_pMaterialSystemHardwareConfig);
}

//------------------------------------------------------------------------------
// Address: 0x10130A20
// Name: private: bool CWin32UploadGameStats::DoBlockingReceive(unsigned int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::DoBlockingReceive(
        CWin32UploadGameStats *this,
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
// Address: 0x10130AD0
// Name: public: enum EGameStatsUploadStatus CWin32UploadGameStats::Upload(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
EGameStatsUploadStatus __thiscall CWin32UploadGameStats::Upload(CWin32UploadGameStats *this, CUtlBuffer *buf)
{
  EGameStatsUploadStatus v4; // [esp+8h] [ebp-4h] BYREF

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Commencing game stats upload connection.");
  v4 = eGameStatsUploadSucceeded;
  while ( this->m_States.m_Memory.m_pMemory[this->m_uCurrentState].second(this, a2: &v4, a3: buf) )
    ;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10130B20
// Name: private: bool CWin32UploadGameStats::ReceiveProtocolOkay(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::ReceiveProtocolOkay(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  unsigned __int8 v5; // cl

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Receiving harvesting protocol acknowledgement.");
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
  if ( CWin32UploadGameStats::DoBlockingReceive(this, bytesExpected: 1u, buf) != 0 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1)
      && (v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], ++buf->m_Get, v5 != 0) )
    {
      UpdateProgress(params: this->m_rCrashParameters, fmt: "Protocol OK.");
      this->m_uCurrentState = 4;
      return 1;
    }
    else
    {
      UpdateProgress(params: this->m_rCrashParameters, fmt: "Server rejected protocol.");
      *status = eGameStatsUploadFailed;
      return 0;
    }
  }
  else
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Didn't receive protocol failure data.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130C10
// Name: private: bool CWin32UploadGameStats::ReceiveOKToSendFile(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::ReceiveOKToSendFile(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  unsigned __int8 v5; // cl

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Receive game stats harvesting protocol upload permissible.");
  if ( CWin32UploadGameStats::DoBlockingReceive(this, bytesExpected: 1u, buf) != 0 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1)
      && (v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], ++buf->m_Get, v5 != 0) )
    {
      UpdateProgress(params: this->m_rCrashParameters, fmt: "Server rejected upload command.");
      *status = eGameStatsUploadFailed;
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
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Receive failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130CB0
// Name: private: bool CWin32UploadGameStats::ReceiveFileUploadSuccess(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::ReceiveFileUploadSuccess(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  unsigned __int8 v5; // cl

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Receiving game stats upload success/fail message.");
  if ( CWin32UploadGameStats::DoBlockingReceive(this, bytesExpected: 1u, buf) != 0 )
  {
    if ( CUtlBuffer::CheckGet(this: buf, nSize: 1)
      && (v5 = buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], ++buf->m_Get, v5 == 1) )
    {
      UpdateProgress(params: this->m_rCrashParameters, fmt: "Upload OK.");
      this->m_uCurrentState = 8;
      return 1;
    }
    else
    {
      UpdateProgress(params: this->m_rCrashParameters, fmt: "Upload failed.");
      *status = eGameStatsUploadFailed;
      return 0;
    }
  }
  else
  {
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Receive failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130D60
// Name: public: void CAsyncUploaderThread::ThreadProc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall __noreturn CAsyncUploaderThread::ThreadProc(CAsyncUploaderThread *this)
{
  CAsyncUploaderThread *v1; // ebx
  CAsyncUploaderThread::DataEntry *v2; // esi
  CThreadFastMutex *p_m_mtx; // edi
  DWORD CurrentThreadId; // ecx

  v1 = this;
  while ( 1 )
  {
    v2 = nullptr;
    p_m_mtx = &v1->m_mtx;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId == v1->m_mtx.m_ownerID )
      goto LABEL_5;
    if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtx, CurrentThreadId, 0) == 0 )
      break;
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mtx, a2: CurrentThreadId, a3: 0);
    v1 = this;
LABEL_7:
    if ( v1->m_queue.m_Size != 0 )
    {
      v2 = *v1->m_queue.m_Memory.m_pMemory;
      if ( v1->m_queue.m_Size - 1 > 0 )
        _V_memmove(
          dest: v1->m_queue.m_Memory.m_pMemory,
          src: v1->m_queue.m_Memory.m_pMemory + 1,
          count: 4 * (v1->m_queue.m_Size - 1));
      --v1->m_queue.m_Size;
    }
    if ( p_m_mtx->m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mtx, 0);
    if ( v2 != nullptr )
    {
      g_pUploadGameStats->UploadGameStats(
        this: g_pUploadGameStats,
        a2: v2->szMapName,
        a3: v2->uiBlobVersion,
        a4: v2->uiBlobSize,
        a5: v2->pvBlob);
      _ThreadSleep(a1: 10000);
      free(pMem: v2);
    }
    else
    {
      _ThreadSleep(a1: 60000);
    }
  }
  v1 = this;
LABEL_5:
  ++p_m_mtx->m_depth;
  goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x10130E30
// Name: public: CWin32UploadGameStats::~CWin32UploadGameStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWin32UploadGameStats::~CWin32UploadGameStats(CWin32UploadGameStats *this)
{
  if ( this->m_SocketTCP != 0 )
  {
    closesocket(s: this->m_SocketTCP);
    this->m_SocketTCP = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10130E50
// Name: private: bool CWin32UploadGameStats::SendProtocolVersion(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::SendProtocolVersion(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  UpdateProgress(params: this->m_rCrashParameters, fmt: "Sending game stats harvester protocol info.");
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
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Send failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 3;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130F10
// Name: private: bool CWin32UploadGameStats::SendUploadCommand(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::SendUploadCommand(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  int m_Put; // eax
  unsigned int m_ContextID; // [esp-4h] [ebp-10h]
  unsigned int m_uStatsBlobSize; // [esp-4h] [ebp-10h]

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Sending harvesting protocol upload request.");
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
  m_uStatsBlobSize = this->m_rCrashParameters->m_uStatsBlobSize;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_uStatsBlobSize);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_uStatsBlobSize);
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
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Send failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 5;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101310A0
// Name: private: bool CWin32UploadGameStats::SendGracefulClose(enum EGameStatsUploadStatus __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWin32UploadGameStats::SendGracefulClose(
        CWin32UploadGameStats *this,
        EGameStatsUploadStatus *status,
        CUtlBuffer *buf)
{
  int m_Put; // eax

  UpdateProgress(params: this->m_rCrashParameters, fmt: "Closing connection to server.");
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
    UpdateProgress(params: this->m_rCrashParameters, fmt: "Send failed.");
    *status = eGameStatsUploadFailed;
    return 0;
  }
  else
  {
    this->m_uCurrentState = 9;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101311A0
// Name: public: static unsigned int CAsyncUploaderThread::CallbackThreadProc(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn CAsyncUploaderThread::CallbackThreadProc(CAsyncUploaderThread *pvParam)
{
  CAsyncUploaderThread::ThreadProc(this: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x101311B0
// Name: public: void CAsyncUploaderThread::QueueData(char const __near *,unsigned int,unsigned int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAsyncUploaderThread::QueueData(
        CAsyncUploaderThread *this,
        CAsyncUploaderThread::DataEntry *szMapName,
        unsigned int uiBlobVersion,
        unsigned int uiBlobSize,
        const void *pvBlob)
{
  CThreadFastMutex *p_m_mtx; // ebx
  DWORD CurrentThreadId; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CAsyncUploaderThread::DataEntry **m_pMemory; // ecx
  int v11; // eax
  CAsyncUploaderThread::DataEntry **v12; // eax
  CAsyncUploaderThread::DataEntry de; // [esp+4h] [ebp-14h] BYREF
  CAsyncUploaderThread::DataEntry *pNew; // [esp+20h] [ebp+8h]

  de.szMapName = (const char *)szMapName;
  de.uiBlobVersion = uiBlobVersion;
  de.uiBlobSize = uiBlobSize;
  de.pvBlob = pvBlob;
  pNew = CAsyncUploaderThread::DataEntry::AllocCopy(this: &de);
  if ( pNew != nullptr )
  {
    p_m_mtx = &this->m_mtx;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mtx.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mtx, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mtx, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mtx.m_depth;
    }
    m_Size = this->m_queue.m_Size;
    m_nAllocationCount = this->m_queue.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_queue,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_queue.m_Size;
    m_pMemory = this->m_queue.m_Memory.m_pMemory;
    v11 = this->m_queue.m_Size - m_Size - 1;
    this->m_queue.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
    v12 = &this->m_queue.m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      *v12 = pNew;
    if ( this->m_hThread == nullptr )
      this->m_hThread = (ThreadHandle_t__ *)_CreateSimpleThread(
                                              a1: CAsyncUploaderThread::CallbackThreadProc,
                                              a2: this,
                                              a3: 0);
    if ( this->m_mtx.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mtx, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101312A0
// Name: void AsyncUpload_QueueData(char const __near *,unsigned int,unsigned int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AsyncUpload_QueueData(
        CAsyncUploaderThread::DataEntry *szMapName,
        unsigned int uiBlobVersion,
        unsigned int uiBlobSize,
        const void *pvBlob)
{
  CAsyncUploaderThread::QueueData(this: &g_AsyncUploader, szMapName, uiBlobVersion, uiBlobSize, pvBlob);
}

//------------------------------------------------------------------------------
// Address: 0x101312C0
// Name: public: CWin32UploadGameStats::CWin32UploadGameStats(struct netadr_s const __near &,struct TGameStatsParameters const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CWin32UploadGameStats *__thiscall CWin32UploadGameStats::CWin32UploadGameStats(
        CWin32UploadGameStats *this,
        netadr_s *harvester,
        const TGameStatsParameters *rGameStatsParameters,
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
  int v15; // [esp-8h] [ebp-18h]
  vgui::PropertySheet::Page_t src; // [esp+8h] [ebp-8h] BYREF

  this->m_States.m_Memory.m_pMemory = nullptr;
  this->m_States.m_Memory.m_nAllocationCount = 0;
  this->m_States.m_Memory.m_nGrowSize = 0;
  this->m_States.m_Size = 0;
  this->m_States.m_pElements = nullptr;
  this->m_uCurrentState = 0;
  *(_DWORD *)&this->m_HarvesterSockAddr.sin_family = 0;
  this->m_HarvesterSockAddr.sin_addr.S_un.S_addr = 0;
  *(_DWORD *)this->m_HarvesterSockAddr.sin_zero = 0;
  *(_DWORD *)&this->m_HarvesterSockAddr.sin_zero[4] = 0;
  this->m_rCrashParameters = rGameStatsParameters;
  this->m_SocketTCP = 0;
  this->m_ContextID = contextid;
  netadr_s::ToSockadr(this: harvester, s: (sockaddr *)&this->m_HarvesterSockAddr);
  m_Size = this->m_States.m_Size;
  src.page = nullptr;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::CreateTCPSocket;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: m_Size,
    &src);
  v7 = this->m_States.m_Size;
  src.page = (vgui::Panel *)1;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::ConnectToHarvesterServer;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v7,
    &src);
  v8 = this->m_States.m_Size;
  src.page = (vgui::Panel *)2;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::SendProtocolVersion;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v8,
    &src);
  v9 = this->m_States.m_Size;
  src.page = (vgui::Panel *)3;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::ReceiveProtocolOkay;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v9,
    &src);
  v10 = this->m_States.m_Size;
  src.page = (vgui::Panel *)4;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::SendUploadCommand;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v10,
    &src);
  v11 = this->m_States.m_Size;
  src.page = (vgui::Panel *)5;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::ReceiveOKToSendFile;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v11,
    &src);
  v12 = this->m_States.m_Size;
  src.page = (vgui::Panel *)6;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::SendWholeFile;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v12,
    &src);
  src.page = (vgui::Panel *)7;
  v13 = this->m_States.m_Size;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::ReceiveFileUploadSuccess;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v13,
    &src);
  v14 = this->m_States.m_Size;
  src.page = (vgui::Panel *)8;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::SendGracefulClose;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v14,
    &src);
  v15 = this->m_States.m_Size;
  src.page = (vgui::Panel *)9;
  *(_DWORD *)&src.contextMenu = CWin32UploadGameStats::CloseTCPSocket;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)this,
    elem: v15,
    &src);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10131430
// Name: enum EGameStatsUploadStatus Win32UploadGameStatsBlocking(struct TGameStatsParameters const __near &)
// Source: json
//------------------------------------------------------------------------------
EGameStatsUploadStatus __cdecl Win32UploadGameStatsBlocking(const TGameStatsParameters *rGameStatsParameters)
{
  unsigned int m_uStatsBlobSize; // eax
  unsigned __int8 *m_pMemory; // edx
  int m_Put; // eax
  const char *v6; // eax
  int v7; // eax
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // cl
  in_addr::<unnamed_type_S_un> v10; // edi
  u_short Short; // bx
  const char *v12; // eax
  unsigned int timeOutInSeconds; // [esp+4h] [ebp-CCh]
  unsigned int timeOutInSecondsa; // [esp+4h] [ebp-CCh]
  CWin32UploadGameStats uploader; // [esp+14h] [ebp-BCh] BYREF
  sockaddr_in replyaddress; // [esp+48h] [ebp-88h] BYREF
  sockaddr_in sa; // [esp+58h] [ebp-78h] BYREF
  sockaddr_in adr; // [esp+68h] [ebp-68h] BYREF
  netadr_s GameStatsHarvesterFSMIPAddress; // [esp+78h] [ebp-58h] BYREF
  CBlockingUDPSocket bcs; // [esp+84h] [ebp-4Ch] BYREF
  EGameStatsUploadStatus status; // [esp+9Ch] [ebp-34h]
  CUtlBuffer buf; // [esp+A0h] [ebp-30h] BYREF
  int dumpcontext; // [esp+D8h] [ebp+8h]

  m_uStatsBlobSize = rGameStatsParameters->m_uStatsBlobSize;
  status = eGameStatsUploadSucceeded;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: m_uStatsBlobSize + 4096, initSize: 0, nFlags: 0);
  UpdateProgress(params: rGameStatsParameters, fmt: "Creating initial report.");
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
    buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = 107;
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
    buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = 2;
    CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
  }
  timeOutInSeconds = rGameStatsParameters->m_uAppId;
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", timeOutInSeconds);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: timeOutInSeconds);
  timeOutInSecondsa = rGameStatsParameters->m_uStatsBlobSize;
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", timeOutInSecondsa);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: timeOutInSecondsa);
  CBlockingUDPSocket::CBlockingUDPSocket(this: &bcs);
  if ( bcs.m_Socket != 0 )
  {
    netadr_s::ToSockadr(this: &rGameStatsParameters->m_ipCSERServer, s: (sockaddr *)&sa);
    v6 = netadr_s::ToString(this: &rGameStatsParameters->m_ipCSERServer, baseOnly: false);
    UpdateProgress(params: rGameStatsParameters, fmt: "Sending game stats to server %s.", v6);
    CBlockingUDPSocket::SendSocketMessage(this: &bcs, rRecipient: &sa, buf: buf.m_Memory.m_pMemory, bufsize: buf.m_Put);
    UpdateProgress(params: rGameStatsParameters, fmt: "Waiting for response.");
    if ( CBlockingUDPSocket::WaitForMessage(this: &bcs, timeOutInSeconds: 2.0) )
    {
      UpdateProgress(params: rGameStatsParameters, fmt: "Received response.");
      CUtlBuffer::EnsureCapacity(this: &buf, num: 4096);
      v7 = CBlockingUDPSocket::ReceiveSocketMessage(
             this: &bcs,
             packet_from: &replyaddress,
             buf: buf.m_Memory.m_pMemory,
             bufsize: 0x1000u);
      if ( v7 != 0 )
      {
        CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v7);
        UpdateProgress(params: rGameStatsParameters, fmt: "Checking response.");
        if ( !CUtlBuffer::CheckGet(this: &buf, nSize: 1)
          || (v8 = buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset], ++buf.m_Get, v8 != 108) )
        {
          UpdateProgress(params: rGameStatsParameters, fmt: "Request denied, invalid message type.");
          CBlockingUDPSocket::~CBlockingUDPSocket(this: &bcs);
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &buf);
          return eGameStatsSendingGameStatsHeaderFailed;
        }
        if ( !CUtlBuffer::CheckGet(this: &buf, nSize: 1)
          || (v9 = buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset], ++buf.m_Get, v9 != 1) )
        {
          UpdateProgress(params: rGameStatsParameters, fmt: "Request denied, invalid message protocol.");
          CBlockingUDPSocket::~CBlockingUDPSocket(this: &bcs);
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &buf);
          return eGameStatsSendingGameStatsHeaderFailed;
        }
        if ( CUtlBuffer::GetChar(this: &buf) != 2 )
        {
          UpdateProgress(params: rGameStatsParameters, fmt: "Stats report accepted, data upload skipped.");
          CBlockingUDPSocket::~CBlockingUDPSocket(this: &bcs);
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &buf);
          return eGameStatsUploadSucceeded;
        }
        v10.S_addr = CUtlBuffer::GetInt(this: &buf);
        Short = CUtlBuffer::GetShort(this: &buf);
        dumpcontext = CUtlBuffer::GetInt(this: &buf);
        adr.sin_family = 2;
        adr.sin_port = htons(hostshort: Short);
        adr.sin_addr.S_un = v10;
        netadr_s::netadr_s(this: &GameStatsHarvesterFSMIPAddress);
        netadr_s::SetFromSockadr(this: &GameStatsHarvesterFSMIPAddress, s: (const sockaddr *)&adr);
        v12 = netadr_s::ToString(this: &GameStatsHarvesterFSMIPAddress, baseOnly: false);
        UpdateProgress(params: rGameStatsParameters, fmt: "Server requested game stats upload to %s.", v12);
        CWin32UploadGameStats::CWin32UploadGameStats(
          this: &uploader,
          harvester: &GameStatsHarvesterFSMIPAddress,
          rGameStatsParameters,
          contextid: dumpcontext);
        status = CWin32UploadGameStats::Upload(this: &uploader, &buf);
        CWin32UploadGameStats::~CWin32UploadGameStats(this: &uploader);
      }
    }
    else
    {
      UpdateProgress(params: rGameStatsParameters, fmt: "No response from server.");
    }
    CBlockingUDPSocket::~CBlockingUDPSocket(this: &bcs);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return status;
  }
  else
  {
    CBlockingUDPSocket::~CBlockingUDPSocket(this: &bcs);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return eGameStatsUploadFailed;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131880
// Name: public: virtual bool CUploadGameStats::UploadGameStats(char const __near *,unsigned int,unsigned int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUploadGameStats::UploadGameStats(
        CUploadGameStats *this,
        const char *mapname,
        unsigned int blobversion,
        unsigned int blobsize,
        void *pvBlobData)
{
  unsigned int SteamAppID; // edi
  int v8; // edx
  int v9; // eax
  TGameStatsParameters params; // [esp+4h] [ebp-E8h] BYREF

  this->UpdateConnection(this);
  if ( !this->m_bConnected )
    return false;
  SteamAppID = GetSteamAppID();
  if ( SteamAppID == 0 )
    return false;
  netadr_s::SetIP(this: &params.m_ipCSERServer, unIP: 0);
  netadr_s::SetPort(this: &params.m_ipCSERServer, newport: 0);
  netadr_s::SetType(this: &params.m_ipCSERServer, newtype: NA_IP);
  params.m_uAppId = 0;
  _V_memset(dest: (void *)&params, fill: 0, count: 232);
  v8 = *(_DWORD *)this->m_Adr.ip;
  v9 = *(_DWORD *)&this->m_Adr.port;
  params.m_ipCSERServer.type = this->m_Adr.type;
  *(_DWORD *)params.m_ipCSERServer.ip = v8;
  *(_DWORD *)&params.m_ipCSERServer.port = v9;
  params.m_uEngineBuildNumber = build_number();
  V_strncpy(pDest: params.m_sExecutableName, pSrc: "hl2.exe", maxLen: 64);
  V_FileBase(in: com_gamedir, out: params.m_sGameDirectory, maxlen: 64);
  V_FileBase(in: mapname, out: params.m_sMapName, maxlen: 64);
  params.m_uStatsBlobVersion = blobversion;
  params.m_uStatsBlobSize = blobsize;
  params.m_pStatsBlobData = pvBlobData;
  params.m_uAppId = SteamAppID;
  return Win32UploadGameStatsBlocking(rGameStatsParameters: &params) == eGameStatsUploadSucceeded;
}

} // namespace engine_xlsp
