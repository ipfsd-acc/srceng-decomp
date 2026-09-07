// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_rcon.cpp
// Functions: 49
// ============================================================

#include "engine\cl_rcon.h"

//------------------------------------------------------------------------------
// Address: 0x1008EB50
// Name: class CRConClient __near & RCONClient(void)
// Source: json
//------------------------------------------------------------------------------
CRConClient *__cdecl RCONClient()
{
  return &g_RCONClient;
}

//------------------------------------------------------------------------------
// Address: 0x1008EB60
// Name: class CRConClient __near & RPTClient(void)
// Source: json
//------------------------------------------------------------------------------
CRPTClient *__cdecl RPTClient()
{
  return &g_RPTClient;
}

//------------------------------------------------------------------------------
// Address: 0x1008EB70
// Name: public: virtual void CRConVProfExport::PauseProfile(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRConVProfExport::PauseProfile(CRConVProfExport *this)
{
  VProfExport_Pause((CVProfExport *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1008EB80
// Name: public: virtual void CRConVProfExport::ResumeProfile(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRConVProfExport::ResumeProfile(CRConVProfExport *this)
{
  CVProfExport::ResumeProfile((CVProfExport *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1008EB90
// Name: public: void CRConClient::SetPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SetPassword(CRConClient *this, const char *pPassword)
{
  CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  CUtlString::operator=(this: &this->m_Password, src: pPassword);
}

//------------------------------------------------------------------------------
// Address: 0x1008EBC0
// Name: public: void CRConClient::SetRemoteFileDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SetRemoteFileDirectory(CRConClient *this, const char *pDir)
{
  CUtlString::operator=(this: &this->m_RemoteFileDir, src: pDir);
  this->m_nScreenShotIndex = 0;
  this->m_nConsoleLogIndex = 0;
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: pDir, a3: "MOD");
}

//------------------------------------------------------------------------------
// Address: 0x1008EC00
// Name: public: void CRConClient::SetAddress(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SetAddress(CRConClient *this, const netadr_s *netAdr)
{
  CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  this->m_Address = *netAdr;
  if ( netadr_s::GetPort(this: &this->m_Address) == 0 )
    netadr_s::SetPort(this: &this->m_Address, newport: 0x6987u);
}

//------------------------------------------------------------------------------
// Address: 0x1008EC50
// Name: public: void CRConClient::CreateListenSocket(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::CreateListenSocket(CRConClient *this, const netadr_s *netAdr)
{
  CSocketCreator::CreateListenSocket(this: &this->m_Socket, netAdr, bListenOnAllInterfaces: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008EC70
// Name: public: void CRConClient::CloseListenSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::CloseListenSocket(CRConClient *this)
{
  CSocketCreator::CloseListenSocket(this: &this->m_Socket);
}

//------------------------------------------------------------------------------
// Address: 0x1008EC80
// Name: private: void CRConClient::SaveRemoteScreenshot(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SaveRemoteScreenshot(CRConClient *this, void *pBuffer, unsigned int nBufLen)
{
  int m_nScreenShotIndex; // eax
  const char *v5; // eax
  HZIP__ *v6; // esi
  int v7; // [esp-4h] [ebp-344h]
  ZIPENTRY zipInfo; // [esp+8h] [ebp-338h] BYREF
  char pFullPath[260]; // [esp+134h] [ebp-20Ch] BYREF
  char pScreenshotPath[260]; // [esp+238h] [ebp-108h] BYREF
  int nIndex; // [esp+33Ch] [ebp-4h] BYREF

  do
  {
    m_nScreenShotIndex = this->m_nScreenShotIndex;
    this->m_nScreenShotIndex = m_nScreenShotIndex + 1;
    v7 = m_nScreenShotIndex;
    v5 = CUtlString::Get(this: &this->m_RemoteFileDir);
    V_snprintf(pDest: pScreenshotPath, maxLen: 260, pFormat: "%s/screenshot%04d.jpg", v5, v7);
  }
  while ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pScreenshotPath, a3: "MOD") );
  GetModSubdirectory(pSubDir: pScreenshotPath, pBuf: pFullPath, nBufLen: 260);
  v6 = OpenZipU(z: pBuffer, len: nBufLen, flags: 3u);
  FindZipItemA(hz: v6, name: "screenshot.jpg", ic: true, index: &nIndex, ze: &zipInfo);
  if ( nIndex >= 0 )
    UnzipItem(hz: v6, index: nIndex, dst: pFullPath, len: 0, flags: 2u);
  CloseZipU(hz: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1008ED60
// Name: private: void CRConClient::SaveRemoteConsoleLog(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SaveRemoteConsoleLog(CRConClient *this, void *pBuffer, int nBufLen)
{
  unsigned int v3; // ebx
  int m_nConsoleLogIndex; // eax
  const char *v6; // eax
  HZIP__ *v7; // esi
  int v8; // [esp-8h] [ebp-344h]
  ZIPENTRY zipInfo; // [esp+8h] [ebp-334h] BYREF
  char pFullPath[260]; // [esp+134h] [ebp-208h] BYREF
  char pLogPath[260]; // [esp+238h] [ebp-104h] BYREF

  v3 = nBufLen;
  if ( nBufLen != 0 )
  {
    do
    {
      m_nConsoleLogIndex = this->m_nConsoleLogIndex;
      this->m_nConsoleLogIndex = m_nConsoleLogIndex + 1;
      v8 = m_nConsoleLogIndex;
      v6 = CUtlString::Get(this: &this->m_RemoteFileDir);
      V_snprintf(pDest: pLogPath, maxLen: 260, pFormat: "%s/console%04d.log", v6, v8);
    }
    while ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pLogPath, a3: "MOD") );
    GetModSubdirectory(pSubDir: pLogPath, pBuf: pFullPath, nBufLen: 260);
    v7 = OpenZipU(z: pBuffer, len: v3, flags: 3u);
    FindZipItemA(hz: v7, name: "console.log", ic: true, index: &nBufLen, ze: &zipInfo);
    if ( nBufLen >= 0 )
      UnzipItem(hz: v7, index: nBufLen, dst: pFullPath, len: 0, flags: 2u);
    CloseZipU(hz: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EE50
// Name: RconAddressChanged_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl RconAddressChanged_f(IConVar *pConVar)
{
  netadr_s to; // [esp+0h] [ebp-14h] BYREF
  ConVarRef var; // [esp+Ch] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  netadr_s::SetIP(this: &to, unIP: 0);
  netadr_s::SetPort(this: &to, newport: 0);
  netadr_s::SetType(this: &to, newtype: NA_IP);
  if ( NET_StringToAdr(s: var.m_pConVarState->m_Value.m_pszString, a: &to) )
  {
    CSocketCreator::CloseAllAcceptedSockets(this: &g_RCONClient.m_Socket);
    g_RCONClient.m_Address = to;
    if ( netadr_s::GetPort(this: &g_RCONClient.m_Address) == 0 )
      netadr_s::SetPort(this: &g_RCONClient.m_Address, newport: 0x6987u);
  }
  else
  {
    _Msg(a1: "Unable to resolve rcon address %s\n", var.m_pConVarState->m_Value.m_pszString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EF00
// Name: public: virtual bool CRConClient::ShouldAcceptSocket(int,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRConClient::ShouldAcceptSocket(CRConClient *this, int hSocket, const netadr_s *netAdr)
{
  return CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008EF20
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
// Address: 0x1008EF90
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
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
// Address: 0x1008F010
// Name: public: virtual void CRConVProfExport::GetBudgetGroupInfos(class IVProfExport::CExportedBudgetGroupInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConVProfExport::GetBudgetGroupInfos(
        CRConVProfExport *this,
        IVProfExport::CExportedBudgetGroupInfo *pInfos)
{
  unsigned __int8 *m_pMemory; // esi
  int v3; // eax

  m_pMemory = (unsigned __int8 *)this->m_Info.m_Memory.m_pMemory;
  v3 = ((int (*)(void))this->GetNumBudgetGroups)();
  memcpy(dst: (unsigned __int8 *)pInfos, src: m_pMemory, count: 12 * v3);
}

//------------------------------------------------------------------------------
// Address: 0x1008F040
// Name: public: virtual void CRConVProfExport::GetBudgetGroupTimes(float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConVProfExport::GetBudgetGroupTimes(CRConVProfExport *this, float *times)
{
  int m_Size; // edi

  m_Size = this->m_Times.m_Size;
  if ( m_Size >= 512 )
    m_Size = 512;
  memset(dst: (unsigned __int8 *)times, value: 0, count: 4 * m_Size);
  if ( this->GetNumBudgetGroups(this) < m_Size )
    m_Size = this->GetNumBudgetGroups(this);
  memcpy(dst: (unsigned __int8 *)times, src: (unsigned __int8 *)this->m_Times.m_Memory.m_pMemory, count: 4 * m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x1008F0B0
// Name: public: virtual void CRConClient::OnSocketClosed(int,struct netadr_s const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::OnSocketClosed(
        CRConClient *this,
        int hSocket,
        const netadr_s *netAdr,
        const netadr_s *pData)
{
  this->m_bAuthenticated = false;
  this->m_iReqID = 0;
  this->m_iAuthRequestID = 1;
  this->m_SendBuffer.m_Get = 0;
  this->m_SendBuffer.m_Put = 0;
  this->m_SendBuffer.m_nOffset = 0;
  this->m_SendBuffer.m_nMaxPut = 0;
  this->m_SendBuffer.m_Error = 0;
  if ( this->m_SendBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SendBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendBuffer.m_Memory.m_pMemory);
      this->m_SendBuffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_SendBuffer.m_Memory.m_nAllocationCount = 0;
  }
  this->m_RecvBuffer.m_Get = 0;
  this->m_RecvBuffer.m_Put = 0;
  this->m_RecvBuffer.m_nOffset = 0;
  this->m_RecvBuffer.m_nMaxPut = 0;
  this->m_RecvBuffer.m_Error = 0;
  if ( this->m_RecvBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RecvBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RecvBuffer.m_Memory.m_pMemory);
      this->m_RecvBuffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_RecvBuffer.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F160
// Name: private: void CRConClient::SendQueuedData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SendQueuedData(CRConClient *this)
{
  const char *v2; // eax
  int v3; // ebx
  unsigned int v4; // edi
  CUtlBuffer tmpBuf; // [esp+Ch] [ebp-34h] BYREF
  int hSocket; // [esp+3Ch] [ebp-4h]

  hSocket = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( (unsigned int)(this->m_SendBuffer.m_nMaxPut - this->m_SendBuffer.m_Get) > 4 )
  {
    while ( 1 )
    {
      v2 = (const char *)&this->m_SendBuffer.m_Memory.m_pMemory[this->m_SendBuffer.m_Get - this->m_SendBuffer.m_nOffset];
      v3 = *(_DWORD *)v2 + 4;
      if ( send(s: hSocket, buf: v2, len: v3, flags: 0) == -1 )
        break;
      CUtlBuffer::SeekGet(this: &this->m_SendBuffer, type: SEEK_CURRENT, offset: v3);
      if ( (unsigned int)(this->m_SendBuffer.m_nMaxPut - this->m_SendBuffer.m_Get) <= 4 )
        goto LABEL_7;
    }
    if ( !SocketWouldBlock() )
    {
      _Warning(a1: "Lost RCON connection, please retry command.\n");
      CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
    }
  }
LABEL_7:
  v4 = this->m_SendBuffer.m_nMaxPut - this->m_SendBuffer.m_Get;
  if ( v4 > 4 )
  {
    CUtlBuffer::CUtlBuffer(this: &tmpBuf, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::Put(
      this: &tmpBuf,
      pMem: &this->m_SendBuffer.m_Memory.m_pMemory[this->m_SendBuffer.m_Get - this->m_SendBuffer.m_nOffset],
      size: v4);
    this->m_SendBuffer.m_Get = 0;
    this->m_SendBuffer.m_Put = 0;
    this->m_SendBuffer.m_nOffset = 0;
    this->m_SendBuffer.m_nMaxPut = 0;
    this->m_SendBuffer.m_Error = 0;
    if ( this->m_SendBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_SendBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendBuffer.m_Memory.m_pMemory);
        this->m_SendBuffer.m_Memory.m_pMemory = nullptr;
      }
      this->m_SendBuffer.m_Memory.m_nAllocationCount = 0;
    }
    CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: tmpBuf.m_Memory.m_pMemory, size: tmpBuf.m_Put);
    if ( tmpBuf.m_Memory.m_nGrowSize >= 0 && tmpBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpBuf.m_Memory.m_pMemory);
  }
  else
  {
    this->m_SendBuffer.m_Get = 0;
    this->m_SendBuffer.m_Put = 0;
    this->m_SendBuffer.m_nOffset = 0;
    this->m_SendBuffer.m_nMaxPut = 0;
    this->m_SendBuffer.m_Error = 0;
    if ( this->m_SendBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_SendBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendBuffer.m_Memory.m_pMemory);
        this->m_SendBuffer.m_Memory.m_pMemory = nullptr;
      }
      this->m_SendBuffer.m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F3B0
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

//------------------------------------------------------------------------------
// Address: 0x1008F450
// Name: public: CRConClient::~CRConClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::~CRConClient(CRConClient *this)
{
  this->__vftable = (CRConClient_vtbl *)&CRConClient::`vftable';
  this->m_RemoteFileDir.m_Storage.m_nActualLength = 0;
  if ( this->m_RemoteFileDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RemoteFileDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RemoteFileDir.m_Storage.m_Memory.m_pMemory);
      this->m_RemoteFileDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_RemoteFileDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Password.m_Storage.m_nActualLength = 0;
  if ( this->m_Password.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Password.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Password.m_Storage.m_Memory.m_pMemory);
      this->m_Password.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Password.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_SendBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SendBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendBuffer.m_Memory.m_pMemory);
      this->m_SendBuffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_SendBuffer.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_RecvBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RecvBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RecvBuffer.m_Memory.m_pMemory);
      this->m_RecvBuffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_RecvBuffer.m_Memory.m_nAllocationCount = 0;
  }
  CSocketCreator::~CSocketCreator(this: &this->m_Socket);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_VProfExport.m_Times);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_VProfExport.m_Info);
}

//------------------------------------------------------------------------------
// Address: 0x1008F530
// Name: private: void CRConClient::ParseReceivedData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::ParseReceivedData(CRConClient *this)
{
  CUtlBuffer *p_m_RecvBuffer; // esi
  int Int; // edi
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  const char *v9; // eax
  char *v10; // edi
  int v11; // eax
  IMemAlloc_vtbl *v12; // edx
  int v13; // eax
  char pBuf[2048]; // [esp+Ch] [ebp-954h] BYREF
  char pString[260]; // [esp+80Ch] [ebp-154h] BYREF
  CUtlBuffer tmpBuf; // [esp+910h] [ebp-50h] BYREF
  CUtlMemory<char,int> msg; // [esp+940h] [ebp-20h]
  CUtlString bugcmd; // [esp+94Ch] [ebp-14h] BYREF
  char dummy[4]; // [esp+95Ch] [ebp-4h] BYREF

  p_m_RecvBuffer = &this->m_RecvBuffer;
  CUtlBuffer::SeekGet(this: &this->m_RecvBuffer, type: SEEK_HEAD, offset: 0);
  Int = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
  if ( Int != 0 )
  {
    while ( Int <= this->m_RecvBuffer.m_Put - this->m_RecvBuffer.m_Get )
    {
      v4 = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
      switch ( CUtlBuffer::GetInt(this: p_m_RecvBuffer) )
      {
        case 2:
          if ( v4 == -1 )
          {
            _Msg(a1: "Bad RCON password\n");
            this->m_bAuthenticated = false;
          }
          else
          {
            this->m_bAuthenticated = true;
          }
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString: dummy, nMaxChars: 2);
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString: dummy, nMaxChars: 2);
          break;
        case 3:
          v7 = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
          this->m_VProfExport.OnRemoteData(
            this: &this->m_VProfExport.IVProfData,
            a2: &p_m_RecvBuffer->m_Memory.m_pMemory[p_m_RecvBuffer->m_Get - p_m_RecvBuffer->m_nOffset],
            a3: v7);
          CUtlBuffer::SeekGet(this: p_m_RecvBuffer, type: SEEK_CURRENT, offset: v7);
          break;
        case 4:
          v8 = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
          this->m_VProfExport.OnRemoteGroupData(
            this: &this->m_VProfExport.IVProfData,
            a2: &p_m_RecvBuffer->m_Memory.m_pMemory[p_m_RecvBuffer->m_Get - p_m_RecvBuffer->m_nOffset],
            a3: v8);
          CUtlBuffer::SeekGet(this: p_m_RecvBuffer, type: SEEK_CURRENT, offset: v8);
          break;
        case 5:
          v5 = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
          CRConClient::SaveRemoteScreenshot(
            this,
            pBuffer: &p_m_RecvBuffer->m_Memory.m_pMemory[p_m_RecvBuffer->m_Get - p_m_RecvBuffer->m_nOffset],
            nBufLen: v5);
          CUtlBuffer::SeekGet(this: p_m_RecvBuffer, type: SEEK_CURRENT, offset: v5);
          break;
        case 6:
          v6 = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
          CRConClient::SaveRemoteConsoleLog(
            this,
            pBuffer: &p_m_RecvBuffer->m_Memory.m_pMemory[p_m_RecvBuffer->m_Get - p_m_RecvBuffer->m_nOffset],
            nBufLen: v6);
          CUtlBuffer::SeekGet(this: p_m_RecvBuffer, type: SEEK_CURRENT, offset: v6);
          break;
        case 7:
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString: pBuf, nMaxChars: 2048);
          _Msg(a1: "%s", pBuf);
          break;
        case 8:
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString, nMaxChars: 260);
          CUtlString::CUtlString(this: &bugcmd);
          CUtlString::Format(this: &bugcmd, pFormat: "bug -remotebugpath %s", pString);
          v9 = CUtlString::Get(this: &bugcmd);
          Cbuf_AddText(eTarget: CBUF_SERVER, pText: v9, nTickDelay: 0);
          Cbuf_AddText(eTarget: CBUF_SERVER, pText: "\n", nTickDelay: 0);
          Cbuf_Execute();
          bugcmd.m_Storage.m_nActualLength = 0;
          if ( bugcmd.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( bugcmd.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bugcmd.m_Storage.m_Memory.m_pMemory);
              bugcmd.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            bugcmd.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          break;
        default:
          v10 = nullptr;
          v11 = this->m_RecvBuffer.m_Put - this->m_RecvBuffer.m_Get + 1;
          msg.m_nAllocationCount = 0;
          if ( v11 > 0 )
          {
            v12 = _g_pMemAlloc->__vftable;
            msg.m_nAllocationCount = v11;
            v10 = (char *)v12->Alloc_2(this: _g_pMemAlloc, a2: v11);
          }
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString: v10, nMaxChars: msg.m_nAllocationCount);
          v10[msg.m_nAllocationCount - 1] = 0;
          _Msg(a1: "%s", v10);
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString: v10, nMaxChars: msg.m_nAllocationCount);
          if ( v10 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
          break;
      }
      if ( (unsigned int)(this->m_RecvBuffer.m_Put - this->m_RecvBuffer.m_Get) < 4 )
      {
        Int = 0;
        goto LABEL_26;
      }
      Int = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
      if ( Int == 0 )
        goto LABEL_26;
    }
  }
  else
  {
LABEL_26:
    if ( this->m_RecvBuffer.m_Put - this->m_RecvBuffer.m_Get <= 0 )
    {
      p_m_RecvBuffer->m_Get = 0;
      p_m_RecvBuffer->m_Put = 0;
      p_m_RecvBuffer->m_nOffset = 0;
      p_m_RecvBuffer->m_nMaxPut = 0;
      p_m_RecvBuffer->m_Error = 0;
      if ( p_m_RecvBuffer->m_Memory.m_nGrowSize >= 0 )
      {
        if ( p_m_RecvBuffer->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_RecvBuffer->m_Memory.m_pMemory);
          p_m_RecvBuffer->m_Memory.m_pMemory = nullptr;
        }
        p_m_RecvBuffer->m_Memory.m_nAllocationCount = 0;
      }
      return;
    }
  }
  CUtlBuffer::CUtlBuffer(this: &tmpBuf, growSize: 0, initSize: 0, nFlags: 0);
  v13 = this->m_RecvBuffer.m_Put - this->m_RecvBuffer.m_Get;
  if ( v13 > 0 )
    CUtlBuffer::Put(
      this: &tmpBuf,
      pMem: &p_m_RecvBuffer->m_Memory.m_pMemory[p_m_RecvBuffer->m_Get - p_m_RecvBuffer->m_nOffset],
      size: v13);
  p_m_RecvBuffer->m_Get = 0;
  p_m_RecvBuffer->m_Put = 0;
  p_m_RecvBuffer->m_nOffset = 0;
  p_m_RecvBuffer->m_nMaxPut = 0;
  p_m_RecvBuffer->m_Error = 0;
  if ( p_m_RecvBuffer->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_RecvBuffer->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_RecvBuffer->m_Memory.m_pMemory);
      p_m_RecvBuffer->m_Memory.m_pMemory = nullptr;
    }
    p_m_RecvBuffer->m_Memory.m_nAllocationCount = 0;
  }
  if ( Int > 0 )
  {
    if ( (p_m_RecvBuffer->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: p_m_RecvBuffer, pFmt: "%d", Int);
    else
      CUtlBuffer::PutTypeBin<int>(this: p_m_RecvBuffer, src: Int);
  }
  if ( tmpBuf.m_Put > 0 )
    CUtlBuffer::Put(this: p_m_RecvBuffer, pMem: tmpBuf.m_Memory.m_pMemory, size: tmpBuf.m_Put);
  if ( tmpBuf.m_Memory.m_nGrowSize >= 0 && tmpBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1008F900
// Name: public: void CRConClient::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::RunFrame(CRConClient *this)
{
  int AcceptedSocketHandle; // edi
  int v3; // eax
  int Error; // eax
  const char *v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  void *v8; // esp
  unsigned int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  const char *v14; // eax
  char v15[12]; // [esp+0h] [ebp-1Ch] BYREF
  int hSocket; // [esp+Ch] [ebp-10h]
  CRConClient *v17; // [esp+10h] [ebp-Ch]
  unsigned int readLen; // [esp+14h] [ebp-8h] BYREF
  char buf; // [esp+1Bh] [ebp-1h] BYREF

  v17 = this;
  CSocketCreator::RunFrame(this: &this->m_Socket);
  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) > 0 )
  {
    CRConClient::SendQueuedData(this);
    AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
    hSocket = AcceptedSocketHandle;
    v3 = recv(s: AcceptedSocketHandle, &buf, len: 1, flags: 2);
    if ( v3 == -1 )
    {
      if ( SocketWouldBlock() )
        return;
LABEL_8:
      CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
      Error = WSAGetLastError();
      v5 = NET_ErrorString(code: Error);
      _Warning(a1: "Lost RCON connection, please retry command (%s)\n", v5);
      return;
    }
    if ( v3 == 0 )
    {
      CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
      return;
    }
    if ( v3 < 0 )
      goto LABEL_8;
    readLen = 0;
    ioctlsocket(s: AcceptedSocketHandle, cmd: 1074030207, argp: &readLen);
    if ( readLen > 4 )
    {
      CUtlBuffer::EnsureCapacity(this: &this->m_RecvBuffer, num: this->m_RecvBuffer.m_Put + readLen + 1);
      v6 = readLen;
      v7 = readLen + 1;
      if ( readLen + 1 > 0x400 )
        v7 = 1024;
      v8 = alloca(v7);
      v9 = 0;
      if ( readLen != 0 )
      {
        while ( 1 )
        {
          v10 = v6 - v9;
          if ( v6 - v9 > 0x400 )
            v10 = 1024;
          v11 = recv(s: hSocket, buf: v15, len: v10, flags: 0);
          v12 = v11;
          if ( v11 == 0 )
          {
            CSocketCreator::CloseAllAcceptedSockets(this: &v17->m_Socket);
            CRConClient::ParseReceivedData(this: v17);
            return;
          }
          if ( v11 < 0 && !SocketWouldBlock() )
            break;
          CUtlBuffer::Put(this: &v17->m_RecvBuffer, pMem: v15, size: v12);
          v9 += v12;
          v6 = readLen;
          if ( v9 >= readLen )
            goto LABEL_22;
        }
        v13 = WSAGetLastError();
        v14 = NET_ErrorString(code: v13);
        _Warning(a1: "RCON Cmd: recv error (%s)\n", v14);
      }
LABEL_22:
      CRConClient::ParseReceivedData(this: v17);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FAA0
// Name: private: void CRConClient::BuildResponse(class CUtlBuffer __near &,enum ServerDataRequestType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::BuildResponse(
        CRConClient *this,
        CUtlBuffer *response,
        ServerDataRequestType_t msg,
        const char *pString1,
        const char *pString2)
{
  int m_iReqID; // eax
  int v7; // edi

  if ( (response->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: response, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: response, src: 0);
  m_iReqID = this->m_iReqID;
  this->m_iReqID = m_iReqID + 1;
  if ( (response->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: response, pFmt: "%d", m_iReqID);
  else
    CUtlBuffer::PutTypeBin<int>(this: response, src: m_iReqID);
  if ( (response->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: response, pFmt: "%d", msg);
  else
    CUtlBuffer::PutTypeBin<int>(this: response, src: msg);
  CUtlBuffer::PutString(this: response, pString: pString1);
  CUtlBuffer::PutString(this: response, pString: pString2);
  v7 = response->m_Put - 4;
  CUtlBuffer::SeekPut(this: response, type: SEEK_HEAD, offset: 0);
  if ( (response->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: response, pFmt: "%d", v7);
  else
    CUtlBuffer::PutTypeBin<int>(this: response, src: v7);
  CUtlBuffer::SeekPut(this: response, type: SEEK_CURRENT, offset: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1008FB80
// Name: private: void CRConClient::Authenticate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::Authenticate(CRConClient *this)
{
  int v2; // eax
  bool v3; // zf
  const char *v4; // eax
  int *p_m_nMaxClients; // esi
  INetworkStringTable *m_pUserInfoTable; // edi
  INetworkStringTable_vtbl *v7; // esi
  CClientState *BaseLocalClient; // eax
  int v9; // eax
  int v10; // esi
  const char *v11; // [esp-4h] [ebp-3Ch]
  CUtlBuffer response; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  if ( (response.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &response, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: &response, src: 0);
  v2 = this->m_iAuthRequestID + 1;
  v3 = (response.m_Flags & 1) == 0;
  this->m_iAuthRequestID = v2;
  if ( v3 )
    CUtlBuffer::PutTypeBin<int>(this: &response, src: v2);
  else
    CUtlBuffer::Printf(this: &response, pFmt: "%d", v2);
  if ( (response.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &response, pFmt: "%d", 3);
  else
    CUtlBuffer::PutTypeBin<int>(this: &response, src: 3);
  v4 = CUtlString::Get(this: &this->m_Password);
  CUtlBuffer::PutString(this: &response, pString: v4);
  if ( GetBaseLocalClient()->m_nSignonState >= 2
    && (p_m_nMaxClients = &GetBaseLocalClient()->m_nMaxClients, GetBaseLocalClient()->m_nPlayerSlot < *p_m_nMaxClients)
    && GetBaseLocalClient()->m_nPlayerSlot >= 0
    && GetBaseLocalClient()->m_pUserInfoTable != nullptr
    && (m_pUserInfoTable = GetBaseLocalClient()->m_pUserInfoTable,
        v7 = m_pUserInfoTable->__vftable,
        BaseLocalClient = GetBaseLocalClient(),
        (v9 = (int)v7->GetStringUserData(this: m_pUserInfoTable, a2: BaseLocalClient->m_nPlayerSlot, a3: nullptr)) != 0) )
  {
    v11 = va(format: "%d", *(_DWORD *)(v9 + 40));
    CUtlBuffer::PutString(this: &response, pString: v11);
  }
  else
  {
    CUtlBuffer::PutString(this: &response, pString: defaultValue);
  }
  v10 = response.m_Put - 4;
  CUtlBuffer::SeekPut(this: &response, type: SEEK_HEAD, offset: 0);
  if ( (response.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &response, pFmt: "%d", v10);
  else
    CUtlBuffer::PutTypeBin<int>(this: &response, src: v10);
  CUtlBuffer::SeekPut(this: &response, type: SEEK_CURRENT, offset: v10);
  CRConClient::SendResponse(this, &response, bAutoAuthenticate: false);
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1008FD10
// Name: public: unsigned char CUtlBuffer::GetUnsignedChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetUnsignedChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( (this->m_Flags & 1) != 0 )
    return CUtlBuffer::GetUnsignedShort(this);
  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008FD50
// Name: public: virtual void CRConVProfExport::OnRemoteGroupData(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConVProfExport::OnRemoteGroupData(CRConVProfExport *this, const void *data, int len)
{
  int m_nGrowSize; // ebx
  int v5; // esi
  IVProfData *v6; // esi
  int Int; // ebx
  int inserted; // eax
  int v9; // eax
  char *v10; // esi
  unsigned __int8 v11; // bl
  int v12; // eax
  unsigned __int8 v13; // dl
  unsigned int v14; // edi
  unsigned __int8 *v15; // eax
  bool v16; // zf
  int v17; // [esp-8h] [ebp-454h]
  char temp[1024]; // [esp+Ch] [ebp-440h] BYREF
  IVProfData *v19; // [esp+40Ch] [ebp-40h]
  CUtlBuffer buf; // [esp+410h] [ebp-3Ch] BYREF
  int v21; // [esp+440h] [ebp-Ch]
  int v22; // [esp+444h] [ebp-8h]
  unsigned __int8 UnsignedShort; // [esp+44Bh] [ebp-1h]
  unsigned __int8 data_3; // [esp+457h] [ebp+Bh]
  unsigned __int8 len_3; // [esp+45Bh] [ebp+Fh]

  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: data, nSize: len, nFlags: 8);
  if ( CUtlBuffer::GetInt(this: &buf) == 0 )
  {
    m_nGrowSize = this->m_Info.m_Memory.m_nGrowSize;
    if ( m_nGrowSize > 0 )
    {
      v5 = 0;
      do
      {
        free(pMem: *(void **)((char *)&this->OnRemoteGroupData + v5));
        v5 += 12;
        --m_nGrowSize;
      }
      while ( m_nGrowSize != 0 );
    }
    this->m_Info.m_Memory.m_nGrowSize = 0;
  }
  v6 = &this->IVProfData;
  Int = CUtlBuffer::GetInt(this: &buf);
  v17 = this->m_Info.m_Memory.m_nGrowSize;
  v19 = &this->IVProfData;
  inserted = CUtlVector<IVProfExport::CExportedBudgetGroupInfo,CUtlMemory<IVProfExport::CExportedBudgetGroupInfo,int>>::InsertMultipleBefore(
               this: (CUtlVector<IVProfExport::CExportedBudgetGroupInfo,CUtlMemory<IVProfExport::CExportedBudgetGroupInfo,int> > *)&this->IVProfData,
               elem: v17,
               num: Int);
  if ( Int > 0 )
  {
    v9 = 12 * inserted;
    v22 = v9;
    v21 = Int;
    while ( 1 )
    {
      v10 = (char *)v6->__vftable + v9;
      if ( (buf.m_Flags & 1) != 0 )
      {
        len_3 = CUtlBuffer::GetUnsignedShort(this: &buf);
      }
      else if ( CUtlBuffer::CheckGet(this: &buf, nSize: 1) )
      {
        len_3 = buf.m_Memory.m_pMemory[buf.m_Get++ - buf.m_nOffset];
      }
      else
      {
        len_3 = 0;
      }
      if ( (buf.m_Flags & 1) != 0 )
      {
        data_3 = CUtlBuffer::GetUnsignedShort(this: &buf);
      }
      else if ( CUtlBuffer::CheckGet(this: &buf, nSize: 1) )
      {
        data_3 = buf.m_Memory.m_pMemory[buf.m_Get++ - buf.m_nOffset];
      }
      else
      {
        data_3 = 0;
      }
      if ( (buf.m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: &buf);
      }
      else if ( CUtlBuffer::CheckGet(this: &buf, nSize: 1) )
      {
        UnsignedShort = buf.m_Memory.m_pMemory[buf.m_Get++ - buf.m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      if ( (buf.m_Flags & 1) != 0 )
      {
        v11 = CUtlBuffer::GetUnsignedShort(this: &buf);
      }
      else if ( CUtlBuffer::CheckGet(this: &buf, nSize: 1) )
      {
        v11 = buf.m_Memory.m_pMemory[buf.m_Get++ - buf.m_nOffset];
      }
      else
      {
        v11 = 0;
      }
      CUtlBuffer::GetString(this: &buf, pString: temp, nMaxChars: 1024);
      v12 = _V_strlen(str: temp);
      v10[8] = len_3;
      v13 = UnsignedShort;
      v14 = v12 + 1;
      v10[9] = data_3;
      v10[10] = v13;
      v10[11] = v11;
      v15 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v12 + 1);
      *(_DWORD *)v10 = v15;
      memcpy(dst: v15, src: (unsigned __int8 *)temp, count: v14);
      v22 += 12;
      v16 = v21-- == 1;
      *((_DWORD *)v10 + 1) = 0;
      if ( v16 )
        break;
      v9 = v22;
      v6 = v19;
    }
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1008FF50
// Name: public: virtual void CRConVProfExport::OnRemoteData(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConVProfExport::OnRemoteData(CRConVProfExport *this, void *data, unsigned int len)
{
  CUtlBuffer buf; // [esp+Ch] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: data, nSize: len, nFlags: 8);
  this->m_Times.m_Memory.m_nGrowSize = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_Info.m_pElements,
    elem: 0,
    num: len >> 2);
  memcpy(dst: (unsigned __int8 *)this->m_Info.m_pElements, src: (unsigned __int8 *)data, count: 4 * (len >> 2));
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1008FFC0
// Name: public: CRConClient::CRConClient(void)
// Source: json
//------------------------------------------------------------------------------
CRConClient *__thiscall CRConClient::CRConClient(CRConClient *this)
{
  this->__vftable = (CRConClient_vtbl *)&CRConClient::`vftable';
  this->m_VProfExport.__vftable = (IVProfData_vtbl *)&IVProfData::`vftable';
  this->m_VProfExport.__vftable = (CRConVProfExport_vtbl *)&CRConVProfExport::`vftable'{for `IVProfExport'};
  this->m_VProfExport.__vftable = (IVProfData_vtbl *)&CRConVProfExport::`vftable'{for `IVProfData'};
  this->m_VProfExport.m_Info.m_Memory.m_pMemory = nullptr;
  this->m_VProfExport.m_Info.m_Memory.m_nAllocationCount = 0;
  this->m_VProfExport.m_Info.m_Memory.m_nGrowSize = 0;
  this->m_VProfExport.m_Info.m_Size = 0;
  this->m_VProfExport.m_Info.m_pElements = nullptr;
  this->m_VProfExport.m_Times.m_Memory.m_pMemory = nullptr;
  this->m_VProfExport.m_Times.m_Memory.m_nAllocationCount = 0;
  this->m_VProfExport.m_Times.m_Memory.m_nGrowSize = 0;
  this->m_VProfExport.m_Times.m_Size = 0;
  this->m_VProfExport.m_Times.m_pElements = nullptr;
  CSocketCreator::CSocketCreator(this: &this->m_Socket, pListener: this);
  netadr_s::SetIP(this: &this->m_Address, unIP: 0);
  netadr_s::SetPort(this: &this->m_Address, newport: 0);
  netadr_s::SetType(this: &this->m_Address, newtype: NA_IP);
  CUtlBuffer::CUtlBuffer(this: &this->m_RecvBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &this->m_SendBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlString::CUtlString(this: &this->m_Password);
  CUtlString::CUtlString(this: &this->m_RemoteFileDir);
  this->m_bAuthenticated = false;
  this->m_iReqID = 0;
  this->m_nScreenShotIndex = 0;
  this->m_nConsoleLogIndex = 0;
  this->m_iAuthRequestID = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10090080
// Name: private: void CRConClient::SendResponse(class CUtlBuffer __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SendResponse(CRConClient *this, CUtlBuffer *response, bool bAutoAuthenticate)
{
  int m_nMaxPut; // eax
  SOCKET AcceptedSocketHandle; // eax
  unsigned __int8 *responsea; // [esp+Ch] [ebp+8h]
  int bAutoAuthenticatea; // [esp+10h] [ebp+Ch]

  if ( !bAutoAuthenticate || this->m_bAuthenticated )
  {
    m_nMaxPut = response->m_nMaxPut;
    responsea = response->m_Memory.m_pMemory;
    bAutoAuthenticatea = m_nMaxPut;
    AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
    if ( send(s: AcceptedSocketHandle, buf: (const char *)responsea, len: bAutoAuthenticatea, flags: 0) == -1 )
    {
      if ( SocketWouldBlock() )
      {
        CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response->m_Memory.m_pMemory, size: response->m_nMaxPut);
      }
      else
      {
        _Warning(a1: "Lost RCON connection, please retry command\n");
        CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
      }
    }
  }
  else
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) > 0 )
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response->m_Memory.m_pMemory, size: response->m_nMaxPut);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090130
// Name: public: void CRConClient::SendCmd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SendCmd(CRConClient *this, const char *msg)
{
  const char *v3; // eax
  int m_nMaxPut; // ebx
  SOCKET AcceptedSocketHandle; // eax
  CUtlBuffer response; // [esp+Ch] [ebp-30h] BYREF
  const char *msga; // [esp+44h] [ebp+8h]

  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0
    && CSocketCreator::ConnectSocket(this: &this->m_Socket, netAdr: &this->m_Address, bSingleSocket: true) < 0 )
  {
    v3 = netadr_s::ToString(this: &this->m_Address, baseOnly: false);
    _Warning(a1: "Unable to connect to remote server (%s)\n", v3);
    return;
  }
  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  CRConClient::BuildResponse(this, &response, msg: SERVERDATA_EXECCOMMAND, pString1: msg, pString2: defaultValue);
  if ( !this->m_bAuthenticated )
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
      goto LABEL_10;
    goto LABEL_6;
  }
  m_nMaxPut = response.m_nMaxPut;
  msga = (const char *)response.m_Memory.m_pMemory;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( send(s: AcceptedSocketHandle, buf: msga, len: m_nMaxPut, flags: 0) == -1 )
  {
    if ( SocketWouldBlock() )
    {
LABEL_6:
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response.m_Memory.m_pMemory, size: response.m_nMaxPut);
      goto LABEL_10;
    }
    _Warning(a1: "Lost RCON connection, please retry command\n");
    CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  }
LABEL_10:
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10090250
// Name: public: void CRConClient::StartVProfData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::StartVProfData(CRConClient *this)
{
  const char *v2; // eax
  int m_nMaxPut; // ebx
  SOCKET AcceptedSocketHandle; // eax
  CUtlBuffer response; // [esp+Ch] [ebp-34h] BYREF
  char *buf; // [esp+3Ch] [ebp-4h]

  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0
    && CSocketCreator::ConnectSocket(this: &this->m_Socket, netAdr: &this->m_Address, bSingleSocket: true) < 0 )
  {
    v2 = netadr_s::ToString(this: &this->m_Address, baseOnly: false);
    _Warning(a1: "Unable to connect to remote server (%s)\n", v2);
    return;
  }
  OverrideVProfExport(pExport: &this->m_VProfExport);
  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  CRConClient::BuildResponse(this, &response, msg: SERVERDATA_VPROF, pString1: defaultValue, pString2: defaultValue);
  if ( !this->m_bAuthenticated )
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
      goto LABEL_10;
    goto LABEL_6;
  }
  m_nMaxPut = response.m_nMaxPut;
  buf = (char *)response.m_Memory.m_pMemory;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( send(s: AcceptedSocketHandle, buf, len: m_nMaxPut, flags: 0) == -1 )
  {
    if ( SocketWouldBlock() )
    {
LABEL_6:
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response.m_Memory.m_pMemory, size: response.m_nMaxPut);
      goto LABEL_10;
    }
    _Warning(a1: "Lost RCON connection, please retry command\n");
    CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  }
LABEL_10:
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10090380
// Name: public: void CRConClient::StopVProfData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::StopVProfData(CRConClient *this)
{
  int m_nMaxPut; // ebx
  SOCKET AcceptedSocketHandle; // eax
  CUtlBuffer response; // [esp+8h] [ebp-34h] BYREF
  char *buf; // [esp+38h] [ebp-4h]

  ResetVProfExport(pExport: &this->m_VProfExport);
  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
    return;
  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  CRConClient::BuildResponse(
    this,
    &response,
    msg: SERVERDATA_REMOVE_VPROF,
    pString1: defaultValue,
    pString2: defaultValue);
  if ( !this->m_bAuthenticated )
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
      goto LABEL_8;
    goto LABEL_4;
  }
  m_nMaxPut = response.m_nMaxPut;
  buf = (char *)response.m_Memory.m_pMemory;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( send(s: AcceptedSocketHandle, buf, len: m_nMaxPut, flags: 0) == -1 )
  {
    if ( SocketWouldBlock() )
    {
LABEL_4:
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response.m_Memory.m_pMemory, size: response.m_nMaxPut);
      goto LABEL_8;
    }
    _Warning(a1: "Lost RCON connection, please retry command\n");
    CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  }
LABEL_8:
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10090480
// Name: public: void CRConClient::TakeScreenshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::TakeScreenshot(CRConClient *this)
{
  const char *v2; // eax
  int m_nMaxPut; // ebx
  SOCKET AcceptedSocketHandle; // eax
  CUtlBuffer response; // [esp+Ch] [ebp-34h] BYREF
  char *buf; // [esp+3Ch] [ebp-4h]

  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0
    && CSocketCreator::ConnectSocket(this: &this->m_Socket, netAdr: &this->m_Address, bSingleSocket: true) < 0 )
  {
    v2 = netadr_s::ToString(this: &this->m_Address, baseOnly: false);
    _Warning(a1: "Unable to connect to remote server (%s)\n", v2);
    return;
  }
  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  CRConClient::BuildResponse(
    this,
    &response,
    msg: SERVERDATA_TAKE_SCREENSHOT,
    pString1: defaultValue,
    pString2: defaultValue);
  if ( !this->m_bAuthenticated )
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
      goto LABEL_10;
    goto LABEL_6;
  }
  m_nMaxPut = response.m_nMaxPut;
  buf = (char *)response.m_Memory.m_pMemory;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( send(s: AcceptedSocketHandle, buf, len: m_nMaxPut, flags: 0) == -1 )
  {
    if ( SocketWouldBlock() )
    {
LABEL_6:
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response.m_Memory.m_pMemory, size: response.m_nMaxPut);
      goto LABEL_10;
    }
    _Warning(a1: "Lost RCON connection, please retry command\n");
    CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  }
LABEL_10:
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100905A0
// Name: public: void CRConClient::GrabConsoleLog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::GrabConsoleLog(CRConClient *this)
{
  const char *v2; // eax
  int m_nMaxPut; // ebx
  SOCKET AcceptedSocketHandle; // eax
  CUtlBuffer response; // [esp+Ch] [ebp-34h] BYREF
  char *buf; // [esp+3Ch] [ebp-4h]

  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0
    && CSocketCreator::ConnectSocket(this: &this->m_Socket, netAdr: &this->m_Address, bSingleSocket: true) < 0 )
  {
    v2 = netadr_s::ToString(this: &this->m_Address, baseOnly: false);
    _Warning(a1: "Unable to connect to remote server (%s)\n", v2);
    return;
  }
  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  CRConClient::BuildResponse(
    this,
    &response,
    msg: SERVERDATA_SEND_CONSOLE_LOG,
    pString1: defaultValue,
    pString2: defaultValue);
  if ( !this->m_bAuthenticated )
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
      goto LABEL_10;
    goto LABEL_6;
  }
  m_nMaxPut = response.m_nMaxPut;
  buf = (char *)response.m_Memory.m_pMemory;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( send(s: AcceptedSocketHandle, buf, len: m_nMaxPut, flags: 0) == -1 )
  {
    if ( SocketWouldBlock() )
    {
LABEL_6:
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response.m_Memory.m_pMemory, size: response.m_nMaxPut);
      goto LABEL_10;
    }
    _Warning(a1: "Lost RCON connection, please retry command\n");
    CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  }
LABEL_10:
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100906C0
// Name: public: void CRConClient::SendBugRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SendBugRequest(CRConClient *this)
{
  const char *v2; // eax
  int m_nMaxPut; // ebx
  SOCKET AcceptedSocketHandle; // eax
  CUtlBuffer response; // [esp+Ch] [ebp-34h] BYREF
  char *buf; // [esp+3Ch] [ebp-4h]

  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0
    && CSocketCreator::ConnectSocket(this: &this->m_Socket, netAdr: &this->m_Address, bSingleSocket: true) < 0 )
  {
    v2 = netadr_s::ToString(this: &this->m_Address, baseOnly: false);
    _Warning(a1: "Unable to connect to remote server (%s)\n", v2);
    _Warning(a1: "Could not connect to remote machine, remote bug command failed\n");
    return;
  }
  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  CRConClient::BuildResponse(
    this,
    &response,
    msg: SERVERDATA_SEND_REMOTEBUG,
    pString1: defaultValue,
    pString2: defaultValue);
  if ( !this->m_bAuthenticated )
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
      goto LABEL_10;
    goto LABEL_6;
  }
  m_nMaxPut = response.m_nMaxPut;
  buf = (char *)response.m_Memory.m_pMemory;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( send(s: AcceptedSocketHandle, buf, len: m_nMaxPut, flags: 0) == -1 )
  {
    if ( SocketWouldBlock() )
    {
LABEL_6:
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response.m_Memory.m_pMemory, size: response.m_nMaxPut);
      goto LABEL_10;
    }
    _Warning(a1: "Lost RCON connection, please retry command\n");
    CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  }
LABEL_10:
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100907F0
// Name: remote_bug
// Source: json
//------------------------------------------------------------------------------
void __cdecl remote_bug()
{
  CRConClient::SendBugRequest(this: &g_RCONClient);
}

//------------------------------------------------------------------------------
// Address: 0x10090800
// Name: public: virtual void CRPTClient::OnSocketAccepted(int,struct netadr_s const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRPTClient::OnSocketAccepted(
        CRPTClient *this,
        int hSocket,
        const netadr_s *netAdr,
        const netadr_s *ppData)
{
  Cmd_SetRptActive(bActive: true);
  CRConClient::StartVProfData(this);
}

//------------------------------------------------------------------------------
// Address: 0x10090820
// Name: public: virtual void CRPTClient::OnSocketClosed(int,struct netadr_s const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRPTClient::OnSocketClosed(
        CRPTClient *this,
        int hSocket,
        const netadr_s *netAdr,
        const netadr_s *pData)
{
  CRConClient::StopVProfData(this);
  Cmd_SetRptActive(bActive: false);
  CRConClient::OnSocketClosed(this, hSocket, netAdr, pData);
}

//------------------------------------------------------------------------------
// Address: 0x10090850
// Name: rpt_screenshot
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_screenshot()
{
  CRConClient::TakeScreenshot(this: &g_RPTClient);
}

//------------------------------------------------------------------------------
// Address: 0x10090860
// Name: rpt_download_log
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_download_log()
{
  CRConClient::GrabConsoleLog(this: &g_RPTClient);
}

//------------------------------------------------------------------------------
// Address: 0x103137F0
// Name: _dynamic_initializer_for__rcon_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rcon_command__()
{
  ConCommand::ConCommand(
    this: &rcon_command,
    pName: "rcon",
    callback: (void (__cdecl *)())rcon,
    pHelpString: "Issue an rcon command.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rcon_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313A70
// Name: _dynamic_initializer_for__rcon_address__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rcon_address__()
{
  ConVar::ConVar(
    this: &rcon_address,
    pName: "rcon_address",
    pDefaultValue: defaultValue,
    flags: 537001984,
    pHelpString: "Address of remote server if sending unconnected rcon commands (format x.x.x.x:p) ",
    callback: (void (__cdecl *)(IConVar *, const char *, float))RconAddressChanged_f);
  return atexit(func: dynamic_atexit_destructor_for__rcon_address__);
}

//------------------------------------------------------------------------------
// Address: 0x103185B0
// Name: _dynamic_initializer_for__rcon_password__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rcon_password__()
{
  ConVar::ConVar(
    this: &rcon_password,
    pName: "rcon_password",
    pDefaultValue: defaultValue,
    flags: 537526272,
    pHelpString: "remote console password.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))RconPasswordChanged_f);
  return atexit(func: dynamic_atexit_destructor_for__rcon_password__);
}

//------------------------------------------------------------------------------
// Address: 0x10322820
// Name: _dynamic_atexit_destructor_for__rcon_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rcon_command__()
{
  ConCommand::~ConCommand(this: &rcon_command);
}

//------------------------------------------------------------------------------
// Address: 0x103228F0
// Name: _dynamic_atexit_destructor_for__rcon_address__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rcon_address__()
{
  ConVar::~ConVar(this: &rcon_address);
}

//------------------------------------------------------------------------------
// Address: 0x10324730
// Name: _dynamic_atexit_destructor_for__rcon_password__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rcon_password__()
{
  ConVar::~ConVar(this: &rcon_password);
}

//------------------------------------------------------------------------------
// Address: 0x10313820
// Name: _dynamic_initializer_for__box_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__box_command__()
{
  ConCommand::ConCommand(
    this: &box_command,
    pName: "box",
    callback: (void (__cdecl *)())box,
    pHelpString: "Draw a debug box.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__box_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322830
// Name: _dynamic_atexit_destructor_for__box_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__box_command__()
{
  ConCommand::~ConCommand(this: &box_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1008E800
// Name: class CRConClient __near & RCONClient(void)
// Source: json
//------------------------------------------------------------------------------
CRConClient *__cdecl RCONClient()
{
  return &g_RCONClient;
}

//------------------------------------------------------------------------------
// Address: 0x1008E810
// Name: class CRConClient __near & RPTClient(void)
// Source: json
//------------------------------------------------------------------------------
CRPTClient *__cdecl RPTClient()
{
  return &g_RPTClient;
}

//------------------------------------------------------------------------------
// Address: 0x1008E820
// Name: public: virtual void CRConVProfExport::PauseProfile(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRConVProfExport::PauseProfile(CRConVProfExport *this)
{
  VProfExport_Pause((CVProfExport *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1008E830
// Name: public: virtual void CRConVProfExport::ResumeProfile(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRConVProfExport::ResumeProfile(CRConVProfExport *this)
{
  CVProfExport::ResumeProfile((CVProfExport *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1008E840
// Name: public: void CRConClient::SetPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SetPassword(CRConClient *this, const char *pPassword)
{
  CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  CUtlString::operator=(this: &this->m_Password, src: pPassword);
}

//------------------------------------------------------------------------------
// Address: 0x1008E870
// Name: public: void CRConClient::SetRemoteFileDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SetRemoteFileDirectory(CRConClient *this, const char *pDir)
{
  CUtlString::operator=(this: &this->m_RemoteFileDir, src: pDir);
  this->m_nScreenShotIndex = 0;
  this->m_nConsoleLogIndex = 0;
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: pDir, a3: "MOD");
}

//------------------------------------------------------------------------------
// Address: 0x1008E8B0
// Name: public: void CRConClient::SetAddress(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SetAddress(CRConClient *this, const netadr_s *netAdr)
{
  CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  this->m_Address = *netAdr;
  if ( netadr_s::GetPort(this: &this->m_Address) == 0 )
    netadr_s::SetPort(this: &this->m_Address, newport: 0x6987u);
}

//------------------------------------------------------------------------------
// Address: 0x1008E900
// Name: public: void CRConClient::CreateListenSocket(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::CreateListenSocket(CRConClient *this, const netadr_s *netAdr)
{
  CSocketCreator::CreateListenSocket(this: &this->m_Socket, netAdr, bListenOnAllInterfaces: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008E920
// Name: public: void CRConClient::CloseListenSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::CloseListenSocket(CRConClient *this)
{
  CSocketCreator::CloseListenSocket(this: &this->m_Socket);
}

//------------------------------------------------------------------------------
// Address: 0x1008E930
// Name: private: void CRConClient::SaveRemoteScreenshot(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SaveRemoteScreenshot(CRConClient *this, void *pBuffer, unsigned int nBufLen)
{
  int m_nScreenShotIndex; // eax
  const char *v5; // eax
  HZIP__ *v6; // esi
  int v7; // [esp-4h] [ebp-344h]
  ZIPENTRY zipInfo; // [esp+8h] [ebp-338h] BYREF
  char pFullPath[260]; // [esp+134h] [ebp-20Ch] BYREF
  char pScreenshotPath[260]; // [esp+238h] [ebp-108h] BYREF
  int nIndex; // [esp+33Ch] [ebp-4h] BYREF

  do
  {
    m_nScreenShotIndex = this->m_nScreenShotIndex;
    this->m_nScreenShotIndex = m_nScreenShotIndex + 1;
    v7 = m_nScreenShotIndex;
    v5 = CUtlString::Get(this: &this->m_RemoteFileDir);
    V_snprintf(pDest: pScreenshotPath, maxLen: 260, pFormat: "%s/screenshot%04d.jpg", v5, v7);
  }
  while ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pScreenshotPath, a3: "MOD") );
  GetModSubdirectory(pSubDir: pScreenshotPath, pBuf: pFullPath, nBufLen: 260);
  v6 = OpenZipU(z: pBuffer, len: nBufLen, flags: 3u);
  FindZipItemA(hz: v6, name: "screenshot.jpg", ic: true, index: &nIndex, ze: &zipInfo);
  if ( nIndex >= 0 )
    UnzipItem(hz: v6, index: nIndex, dst: pFullPath, len: 0, flags: 2u);
  CloseZipU(hz: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1008EA10
// Name: private: void CRConClient::SaveRemoteConsoleLog(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SaveRemoteConsoleLog(CRConClient *this, void *pBuffer, int nBufLen)
{
  unsigned int v3; // ebx
  int m_nConsoleLogIndex; // eax
  const char *v6; // eax
  HZIP__ *v7; // esi
  int v8; // [esp-8h] [ebp-344h]
  ZIPENTRY zipInfo; // [esp+8h] [ebp-334h] BYREF
  char pFullPath[260]; // [esp+134h] [ebp-208h] BYREF
  char pLogPath[260]; // [esp+238h] [ebp-104h] BYREF

  v3 = nBufLen;
  if ( nBufLen != 0 )
  {
    do
    {
      m_nConsoleLogIndex = this->m_nConsoleLogIndex;
      this->m_nConsoleLogIndex = m_nConsoleLogIndex + 1;
      v8 = m_nConsoleLogIndex;
      v6 = CUtlString::Get(this: &this->m_RemoteFileDir);
      V_snprintf(pDest: pLogPath, maxLen: 260, pFormat: "%s/console%04d.log", v6, v8);
    }
    while ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pLogPath, a3: "MOD") );
    GetModSubdirectory(pSubDir: pLogPath, pBuf: pFullPath, nBufLen: 260);
    v7 = OpenZipU(z: pBuffer, len: v3, flags: 3u);
    FindZipItemA(hz: v7, name: "console.log", ic: true, index: &nBufLen, ze: &zipInfo);
    if ( nBufLen >= 0 )
      UnzipItem(hz: v7, index: nBufLen, dst: pFullPath, len: 0, flags: 2u);
    CloseZipU(hz: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EB00
// Name: RconAddressChanged_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl RconAddressChanged_f(IConVar *pConVar)
{
  netadr_s to; // [esp+0h] [ebp-14h] BYREF
  ConVarRef var; // [esp+Ch] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  netadr_s::SetIP(this: &to, unIP: 0);
  netadr_s::SetPort(this: &to, newport: 0);
  netadr_s::SetType(this: &to, newtype: NA_IP);
  if ( NET_StringToAdr(s: var.m_pConVarState->m_Value.m_pszString, a: &to) != 0 )
  {
    CSocketCreator::CloseAllAcceptedSockets(this: &g_RCONClient.m_Socket);
    g_RCONClient.m_Address = to;
    if ( netadr_s::GetPort(this: &g_RCONClient.m_Address) == 0 )
      netadr_s::SetPort(this: &g_RCONClient.m_Address, newport: 0x6987u);
  }
  else
  {
    _Msg(a1: "Unable to resolve rcon address %s\n", var.m_pConVarState->m_Value.m_pszString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EBB0
// Name: public: virtual bool CRConClient::ShouldAcceptSocket(int,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRConClient::ShouldAcceptSocket(CRConClient *this, int hSocket, const netadr_s *netAdr)
{
  return CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008EBD0
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, unsigned int nRadix)
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
// Address: 0x1008EC40
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
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
// Address: 0x1008ECC0
// Name: public: virtual void CRConVProfExport::GetBudgetGroupInfos(class IVProfExport::CExportedBudgetGroupInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConVProfExport::GetBudgetGroupInfos(
        CRConVProfExport *this,
        IVProfExport::CExportedBudgetGroupInfo *pInfos)
{
  unsigned __int8 *m_pMemory; // esi
  int v3; // eax

  m_pMemory = (unsigned __int8 *)this->m_Info.m_Memory.m_pMemory;
  v3 = ((int (*)(void))this->GetNumBudgetGroups)();
  memcpy(dst: (unsigned __int8 *)pInfos, src: m_pMemory, count: 12 * v3);
}

//------------------------------------------------------------------------------
// Address: 0x1008ECF0
// Name: public: virtual void CRConVProfExport::GetBudgetGroupTimes(float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConVProfExport::GetBudgetGroupTimes(CRConVProfExport *this, float *times)
{
  int m_Size; // edi

  m_Size = this->m_Times.m_Size;
  if ( m_Size >= 512 )
    m_Size = 512;
  memset(dst: (unsigned __int8 *)times, value: 0, count: 4 * m_Size);
  if ( this->GetNumBudgetGroups(this) < m_Size )
    m_Size = this->GetNumBudgetGroups(this);
  memcpy(dst: (unsigned __int8 *)times, src: (unsigned __int8 *)this->m_Times.m_Memory.m_pMemory, count: 4 * m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x1008EE10
// Name: private: void CRConClient::SendQueuedData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SendQueuedData(CRConClient *this)
{
  const char *v2; // eax
  int v3; // ebx
  unsigned int v4; // edi
  CUtlBuffer tmpBuf; // [esp+Ch] [ebp-34h] BYREF
  int hSocket; // [esp+3Ch] [ebp-4h]

  hSocket = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( (unsigned int)(this->m_SendBuffer.m_nMaxPut - this->m_SendBuffer.m_Get) > 4 )
  {
    while ( 1 )
    {
      v2 = (const char *)&this->m_SendBuffer.m_Memory.m_pMemory[this->m_SendBuffer.m_Get - this->m_SendBuffer.m_nOffset];
      v3 = *(_DWORD *)v2 + 4;
      if ( send(s: hSocket, buf: v2, len: v3, flags: 0) == -1 )
        break;
      CUtlBuffer::SeekGet(this: &this->m_SendBuffer, type: SEEK_CURRENT, offset: v3);
      if ( (unsigned int)(this->m_SendBuffer.m_nMaxPut - this->m_SendBuffer.m_Get) <= 4 )
        goto LABEL_7;
    }
    if ( !SocketWouldBlock() )
    {
      _Warning(a1: "Lost RCON connection, please retry command.\n");
      CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
    }
  }
LABEL_7:
  v4 = this->m_SendBuffer.m_nMaxPut - this->m_SendBuffer.m_Get;
  if ( v4 > 4 )
  {
    CUtlBuffer::CUtlBuffer(this: &tmpBuf, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::Put(
      this: &tmpBuf,
      pMem: &this->m_SendBuffer.m_Memory.m_pMemory[this->m_SendBuffer.m_Get - this->m_SendBuffer.m_nOffset],
      size: v4);
    this->m_SendBuffer.m_Get = 0;
    this->m_SendBuffer.m_Put = 0;
    this->m_SendBuffer.m_nOffset = 0;
    this->m_SendBuffer.m_nMaxPut = 0;
    this->m_SendBuffer.m_Error = 0;
    if ( this->m_SendBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_SendBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendBuffer.m_Memory.m_pMemory);
        this->m_SendBuffer.m_Memory.m_pMemory = nullptr;
      }
      this->m_SendBuffer.m_Memory.m_nAllocationCount = 0;
    }
    CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: tmpBuf.m_Memory.m_pMemory, size: tmpBuf.m_Put);
    if ( tmpBuf.m_Memory.m_nGrowSize >= 0 && tmpBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpBuf.m_Memory.m_pMemory);
  }
  else
  {
    this->m_SendBuffer.m_Get = 0;
    this->m_SendBuffer.m_Put = 0;
    this->m_SendBuffer.m_nOffset = 0;
    this->m_SendBuffer.m_nMaxPut = 0;
    this->m_SendBuffer.m_Error = 0;
    if ( this->m_SendBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_SendBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendBuffer.m_Memory.m_pMemory);
        this->m_SendBuffer.m_Memory.m_pMemory = nullptr;
      }
      this->m_SendBuffer.m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F060
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
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 0xAu);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008F100
// Name: public: CRConClient::~CRConClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::~CRConClient(CRConClient *this)
{
  this->__vftable = (CRConClient_vtbl *)&CRConClient::`vftable';
  this->m_RemoteFileDir.m_Storage.m_nActualLength = 0;
  if ( this->m_RemoteFileDir.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RemoteFileDir.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RemoteFileDir.m_Storage.m_Memory.m_pMemory);
      this->m_RemoteFileDir.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_RemoteFileDir.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Password.m_Storage.m_nActualLength = 0;
  if ( this->m_Password.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Password.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Password.m_Storage.m_Memory.m_pMemory);
      this->m_Password.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Password.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_SendBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SendBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendBuffer.m_Memory.m_pMemory);
      this->m_SendBuffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_SendBuffer.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_RecvBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RecvBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RecvBuffer.m_Memory.m_pMemory);
      this->m_RecvBuffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_RecvBuffer.m_Memory.m_nAllocationCount = 0;
  }
  CSocketCreator::~CSocketCreator(this: &this->m_Socket);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_VProfExport.m_Times);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_VProfExport.m_Info);
}

//------------------------------------------------------------------------------
// Address: 0x1008F1E0
// Name: private: void CRConClient::ParseReceivedData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::ParseReceivedData(CRConClient *this)
{
  CUtlBuffer *p_m_RecvBuffer; // esi
  int Int; // edi
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  const char *v9; // eax
  char *v10; // edi
  int v11; // eax
  IMemAlloc_vtbl *v12; // edx
  int v13; // eax
  char pBuf[2048]; // [esp+Ch] [ebp-954h] BYREF
  char pString[260]; // [esp+80Ch] [ebp-154h] BYREF
  CUtlBuffer tmpBuf; // [esp+910h] [ebp-50h] BYREF
  CUtlMemory<char,int> msg; // [esp+940h] [ebp-20h]
  CUtlString bugcmd; // [esp+94Ch] [ebp-14h] BYREF
  char dummy[4]; // [esp+95Ch] [ebp-4h] BYREF

  p_m_RecvBuffer = &this->m_RecvBuffer;
  CUtlBuffer::SeekGet(this: &this->m_RecvBuffer, type: SEEK_HEAD, offset: 0);
  Int = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
  if ( Int != 0 )
  {
    while ( Int <= this->m_RecvBuffer.m_Put - this->m_RecvBuffer.m_Get )
    {
      v4 = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
      switch ( CUtlBuffer::GetInt(this: p_m_RecvBuffer) )
      {
        case 2:
          if ( v4 == -1 )
          {
            _Msg(a1: "Bad RCON password\n");
            this->m_bAuthenticated = false;
          }
          else
          {
            this->m_bAuthenticated = true;
          }
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString: dummy, nMaxChars: 2);
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString: dummy, nMaxChars: 2);
          break;
        case 3:
          v7 = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
          this->m_VProfExport.OnRemoteData(
            this: &this->m_VProfExport.IVProfData,
            a2: &p_m_RecvBuffer->m_Memory.m_pMemory[p_m_RecvBuffer->m_Get - p_m_RecvBuffer->m_nOffset],
            a3: v7);
          CUtlBuffer::SeekGet(this: p_m_RecvBuffer, type: SEEK_CURRENT, offset: v7);
          break;
        case 4:
          v8 = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
          this->m_VProfExport.OnRemoteGroupData(
            this: &this->m_VProfExport.IVProfData,
            a2: &p_m_RecvBuffer->m_Memory.m_pMemory[p_m_RecvBuffer->m_Get - p_m_RecvBuffer->m_nOffset],
            a3: v8);
          CUtlBuffer::SeekGet(this: p_m_RecvBuffer, type: SEEK_CURRENT, offset: v8);
          break;
        case 5:
          v5 = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
          CRConClient::SaveRemoteScreenshot(
            this,
            pBuffer: &p_m_RecvBuffer->m_Memory.m_pMemory[p_m_RecvBuffer->m_Get - p_m_RecvBuffer->m_nOffset],
            nBufLen: v5);
          CUtlBuffer::SeekGet(this: p_m_RecvBuffer, type: SEEK_CURRENT, offset: v5);
          break;
        case 6:
          v6 = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
          CRConClient::SaveRemoteConsoleLog(
            this,
            pBuffer: &p_m_RecvBuffer->m_Memory.m_pMemory[p_m_RecvBuffer->m_Get - p_m_RecvBuffer->m_nOffset],
            nBufLen: v6);
          CUtlBuffer::SeekGet(this: p_m_RecvBuffer, type: SEEK_CURRENT, offset: v6);
          break;
        case 7:
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString: pBuf, nMaxChars: 2048);
          _Msg(a1: "%s", pBuf);
          break;
        case 8:
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString, nMaxChars: 260);
          CUtlString::CUtlString(this: &bugcmd);
          CUtlString::Format(this: &bugcmd, pFormat: "bug -remotebugpath %s", pString);
          v9 = CUtlString::Get(this: &bugcmd);
          Cbuf_AddText(eTarget: CBUF_SERVER, pText: v9, nTickDelay: 0);
          Cbuf_AddText(eTarget: CBUF_SERVER, pText: "\n", nTickDelay: 0);
          Cbuf_Execute();
          bugcmd.m_Storage.m_nActualLength = 0;
          if ( bugcmd.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( bugcmd.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bugcmd.m_Storage.m_Memory.m_pMemory);
              bugcmd.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            bugcmd.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          break;
        default:
          v10 = nullptr;
          v11 = this->m_RecvBuffer.m_Put - this->m_RecvBuffer.m_Get + 1;
          msg.m_nAllocationCount = 0;
          if ( v11 > 0 )
          {
            v12 = _g_pMemAlloc->__vftable;
            msg.m_nAllocationCount = v11;
            v10 = (char *)v12->Alloc_2(this: _g_pMemAlloc, a2: v11);
          }
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString: v10, nMaxChars: msg.m_nAllocationCount);
          v10[msg.m_nAllocationCount - 1] = 0;
          _Msg(a1: "%s", v10);
          CUtlBuffer::GetString(this: p_m_RecvBuffer, pString: v10, nMaxChars: msg.m_nAllocationCount);
          if ( v10 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
          break;
      }
      if ( (unsigned int)(this->m_RecvBuffer.m_Put - this->m_RecvBuffer.m_Get) < 4 )
      {
        Int = 0;
        goto LABEL_26;
      }
      Int = CUtlBuffer::GetInt(this: p_m_RecvBuffer);
      if ( Int == 0 )
        goto LABEL_26;
    }
  }
  else
  {
LABEL_26:
    if ( this->m_RecvBuffer.m_Put - this->m_RecvBuffer.m_Get <= 0 )
    {
      p_m_RecvBuffer->m_Get = 0;
      p_m_RecvBuffer->m_Put = 0;
      p_m_RecvBuffer->m_nOffset = 0;
      p_m_RecvBuffer->m_nMaxPut = 0;
      p_m_RecvBuffer->m_Error = 0;
      if ( p_m_RecvBuffer->m_Memory.m_nGrowSize >= 0 )
      {
        if ( p_m_RecvBuffer->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_RecvBuffer->m_Memory.m_pMemory);
          p_m_RecvBuffer->m_Memory.m_pMemory = nullptr;
        }
        p_m_RecvBuffer->m_Memory.m_nAllocationCount = 0;
      }
      return;
    }
  }
  CUtlBuffer::CUtlBuffer(this: &tmpBuf, growSize: 0, initSize: 0, nFlags: 0);
  v13 = this->m_RecvBuffer.m_Put - this->m_RecvBuffer.m_Get;
  if ( v13 > 0 )
    CUtlBuffer::Put(
      this: &tmpBuf,
      pMem: &p_m_RecvBuffer->m_Memory.m_pMemory[p_m_RecvBuffer->m_Get - p_m_RecvBuffer->m_nOffset],
      size: v13);
  p_m_RecvBuffer->m_Get = 0;
  p_m_RecvBuffer->m_Put = 0;
  p_m_RecvBuffer->m_nOffset = 0;
  p_m_RecvBuffer->m_nMaxPut = 0;
  p_m_RecvBuffer->m_Error = 0;
  if ( p_m_RecvBuffer->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_RecvBuffer->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_RecvBuffer->m_Memory.m_pMemory);
      p_m_RecvBuffer->m_Memory.m_pMemory = nullptr;
    }
    p_m_RecvBuffer->m_Memory.m_nAllocationCount = 0;
  }
  if ( Int > 0 )
  {
    if ( (p_m_RecvBuffer->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: p_m_RecvBuffer, pFmt: "%d", Int);
    else
      CUtlBuffer::PutTypeBin<int>(this: p_m_RecvBuffer, src: Int);
  }
  if ( tmpBuf.m_Put > 0 )
    CUtlBuffer::Put(this: p_m_RecvBuffer, pMem: tmpBuf.m_Memory.m_pMemory, size: tmpBuf.m_Put);
  if ( tmpBuf.m_Memory.m_nGrowSize >= 0 && tmpBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1008F5B0
// Name: public: void CRConClient::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::RunFrame(CRConClient *this)
{
  int AcceptedSocketHandle; // edi
  int v3; // eax
  int Error; // eax
  const char *v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  void *v8; // esp
  unsigned int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  const char *v14; // eax
  char v15[12]; // [esp+0h] [ebp-1Ch] BYREF
  int hSocket; // [esp+Ch] [ebp-10h]
  CRConClient *v17; // [esp+10h] [ebp-Ch]
  unsigned int readLen; // [esp+14h] [ebp-8h] BYREF
  char buf; // [esp+1Bh] [ebp-1h] BYREF

  v17 = this;
  CSocketCreator::RunFrame(this: &this->m_Socket);
  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) > 0 )
  {
    CRConClient::SendQueuedData(this);
    AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
    hSocket = AcceptedSocketHandle;
    v3 = recv(s: AcceptedSocketHandle, &buf, len: 1, flags: 2);
    if ( v3 == -1 )
    {
      if ( SocketWouldBlock() )
        return;
LABEL_8:
      CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
      Error = WSAGetLastError();
      v5 = NET_ErrorString(code: Error);
      _Warning(a1: "Lost RCON connection, please retry command (%s)\n", v5);
      return;
    }
    if ( v3 == 0 )
    {
      CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
      return;
    }
    if ( v3 < 0 )
      goto LABEL_8;
    readLen = 0;
    ioctlsocket(s: AcceptedSocketHandle, cmd: 1074030207, argp: &readLen);
    if ( readLen > 4 )
    {
      CUtlBuffer::EnsureCapacity(this: &this->m_RecvBuffer, num: this->m_RecvBuffer.m_Put + readLen + 1);
      v6 = readLen;
      v7 = readLen + 1;
      if ( readLen + 1 > 0x400 )
        v7 = 1024;
      v8 = alloca(v7);
      v9 = 0;
      if ( readLen != 0 )
      {
        while ( 1 )
        {
          v10 = v6 - v9;
          if ( v6 - v9 > 0x400 )
            v10 = 1024;
          v11 = recv(s: hSocket, buf: v15, len: v10, flags: 0);
          v12 = v11;
          if ( v11 == 0 )
          {
            CSocketCreator::CloseAllAcceptedSockets(this: &v17->m_Socket);
            CRConClient::ParseReceivedData(this: v17);
            return;
          }
          if ( v11 < 0 && !SocketWouldBlock() )
            break;
          CUtlBuffer::Put(this: &v17->m_RecvBuffer, pMem: v15, size: v12);
          v9 += v12;
          v6 = readLen;
          if ( v9 >= readLen )
            goto LABEL_22;
        }
        v13 = WSAGetLastError();
        v14 = NET_ErrorString(code: v13);
        _Warning(a1: "RCON Cmd: recv error (%s)\n", v14);
      }
LABEL_22:
      CRConClient::ParseReceivedData(this: v17);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F750
// Name: private: void CRConClient::BuildResponse(class CUtlBuffer __near &,enum ServerDataRequestType_t,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::BuildResponse(
        CRConClient *this,
        CUtlBuffer *response,
        ServerDataRequestType_t msg,
        const char *pString1,
        const char *pString2)
{
  int m_iReqID; // eax
  int v7; // edi

  if ( (response->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: response, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: response, src: 0);
  m_iReqID = this->m_iReqID;
  this->m_iReqID = m_iReqID + 1;
  if ( (response->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: response, pFmt: "%d", m_iReqID);
  else
    CUtlBuffer::PutTypeBin<int>(this: response, src: m_iReqID);
  if ( (response->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: response, pFmt: "%d", msg);
  else
    CUtlBuffer::PutTypeBin<int>(this: response, src: msg);
  CUtlBuffer::PutString(this: response, pString: pString1);
  CUtlBuffer::PutString(this: response, pString: pString2);
  v7 = response->m_Put - 4;
  CUtlBuffer::SeekPut(this: response, type: SEEK_HEAD, offset: 0);
  if ( (response->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: response, pFmt: "%d", v7);
  else
    CUtlBuffer::PutTypeBin<int>(this: response, src: v7);
  CUtlBuffer::SeekPut(this: response, type: SEEK_CURRENT, offset: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1008F830
// Name: private: void CRConClient::Authenticate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::Authenticate(CRConClient *this)
{
  int v2; // eax
  bool v3; // zf
  const char *v4; // eax
  int *p_m_nMaxClients; // esi
  INetworkStringTable *m_pUserInfoTable; // edi
  INetworkStringTable_vtbl *v7; // esi
  CClientState *BaseLocalClient; // eax
  int v9; // eax
  int v10; // esi
  const char *v11; // [esp-4h] [ebp-3Ch]
  CUtlBuffer response; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  if ( (response.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &response, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: &response, src: 0);
  v2 = this->m_iAuthRequestID + 1;
  v3 = (response.m_Flags & 1) == 0;
  this->m_iAuthRequestID = v2;
  if ( v3 )
    CUtlBuffer::PutTypeBin<int>(this: &response, src: v2);
  else
    CUtlBuffer::Printf(this: &response, pFmt: "%d", v2);
  if ( (response.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &response, pFmt: "%d", 3);
  else
    CUtlBuffer::PutTypeBin<int>(this: &response, src: 3);
  v4 = CUtlString::Get(this: &this->m_Password);
  CUtlBuffer::PutString(this: &response, pString: v4);
  if ( GetBaseLocalClient()->m_nSignonState >= 2
    && (p_m_nMaxClients = &GetBaseLocalClient()->m_nMaxClients, GetBaseLocalClient()->m_nPlayerSlot < *p_m_nMaxClients)
    && GetBaseLocalClient()->m_nPlayerSlot >= 0
    && GetBaseLocalClient()->m_pUserInfoTable != nullptr
    && (m_pUserInfoTable = GetBaseLocalClient()->m_pUserInfoTable,
        v7 = m_pUserInfoTable->__vftable,
        BaseLocalClient = GetBaseLocalClient(),
        (v9 = (int)v7->GetStringUserData(this: m_pUserInfoTable, a2: BaseLocalClient->m_nPlayerSlot, a3: nullptr)) != 0) )
  {
    v11 = va(format: "%d", *(_DWORD *)(v9 + 40));
    CUtlBuffer::PutString(this: &response, pString: v11);
  }
  else
  {
    CUtlBuffer::PutString(this: &response, pString: defaultValue);
  }
  v10 = response.m_Put - 4;
  CUtlBuffer::SeekPut(this: &response, type: SEEK_HEAD, offset: 0);
  if ( (response.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &response, pFmt: "%d", v10);
  else
    CUtlBuffer::PutTypeBin<int>(this: &response, src: v10);
  CUtlBuffer::SeekPut(this: &response, type: SEEK_CURRENT, offset: v10);
  CRConClient::SendResponse(this, &response, bAutoAuthenticate: false);
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1008F9C0
// Name: public: unsigned char CUtlBuffer::GetUnsignedChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetUnsignedChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( (this->m_Flags & 1) != 0 )
    return CUtlBuffer::GetUnsignedShort(this);
  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008FA00
// Name: public: virtual void CRConVProfExport::OnRemoteGroupData(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConVProfExport::OnRemoteGroupData(CRConVProfExport *this, const void *data, int len)
{
  int m_nGrowSize; // ebx
  int v5; // esi
  IVProfData *v6; // esi
  int Int; // ebx
  int inserted; // eax
  int v9; // eax
  char *v10; // esi
  unsigned __int8 v11; // bl
  int v12; // eax
  unsigned __int8 v13; // dl
  unsigned int v14; // edi
  unsigned __int8 *v15; // eax
  bool v16; // zf
  int v17; // [esp-8h] [ebp-454h]
  char temp[1024]; // [esp+Ch] [ebp-440h] BYREF
  IVProfData *v19; // [esp+40Ch] [ebp-40h]
  CUtlBuffer buf; // [esp+410h] [ebp-3Ch] BYREF
  int v21; // [esp+440h] [ebp-Ch]
  int v22; // [esp+444h] [ebp-8h]
  unsigned __int8 UnsignedShort; // [esp+44Bh] [ebp-1h]
  unsigned __int8 data_3; // [esp+457h] [ebp+Bh]
  unsigned __int8 len_3; // [esp+45Bh] [ebp+Fh]

  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: data, nSize: len, nFlags: 8);
  if ( CUtlBuffer::GetInt(this: &buf) == 0 )
  {
    m_nGrowSize = this->m_Info.m_Memory.m_nGrowSize;
    if ( m_nGrowSize > 0 )
    {
      v5 = 0;
      do
      {
        free(pMem: *(void **)((char *)&this->OnRemoteGroupData + v5));
        v5 += 12;
        --m_nGrowSize;
      }
      while ( m_nGrowSize != 0 );
    }
    this->m_Info.m_Memory.m_nGrowSize = 0;
  }
  v6 = &this->IVProfData;
  Int = CUtlBuffer::GetInt(this: &buf);
  v17 = this->m_Info.m_Memory.m_nGrowSize;
  v19 = &this->IVProfData;
  inserted = CUtlVector<IVProfExport::CExportedBudgetGroupInfo,CUtlMemory<IVProfExport::CExportedBudgetGroupInfo,int>>::InsertMultipleBefore(
               this: (CUtlVector<IVProfExport::CExportedBudgetGroupInfo,CUtlMemory<IVProfExport::CExportedBudgetGroupInfo,int> > *)&this->IVProfData,
               elem: v17,
               num: Int);
  if ( Int > 0 )
  {
    v9 = 12 * inserted;
    v22 = v9;
    v21 = Int;
    while ( 1 )
    {
      v10 = (char *)v6->__vftable + v9;
      if ( (buf.m_Flags & 1) != 0 )
      {
        len_3 = CUtlBuffer::GetUnsignedShort(this: &buf);
      }
      else if ( CUtlBuffer::CheckGet(this: &buf, nSize: 1) )
      {
        len_3 = buf.m_Memory.m_pMemory[buf.m_Get++ - buf.m_nOffset];
      }
      else
      {
        len_3 = 0;
      }
      if ( (buf.m_Flags & 1) != 0 )
      {
        data_3 = CUtlBuffer::GetUnsignedShort(this: &buf);
      }
      else if ( CUtlBuffer::CheckGet(this: &buf, nSize: 1) )
      {
        data_3 = buf.m_Memory.m_pMemory[buf.m_Get++ - buf.m_nOffset];
      }
      else
      {
        data_3 = 0;
      }
      if ( (buf.m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: &buf);
      }
      else if ( CUtlBuffer::CheckGet(this: &buf, nSize: 1) )
      {
        UnsignedShort = buf.m_Memory.m_pMemory[buf.m_Get++ - buf.m_nOffset];
      }
      else
      {
        UnsignedShort = 0;
      }
      if ( (buf.m_Flags & 1) != 0 )
      {
        v11 = CUtlBuffer::GetUnsignedShort(this: &buf);
      }
      else if ( CUtlBuffer::CheckGet(this: &buf, nSize: 1) )
      {
        v11 = buf.m_Memory.m_pMemory[buf.m_Get++ - buf.m_nOffset];
      }
      else
      {
        v11 = 0;
      }
      CUtlBuffer::GetString(this: &buf, pString: temp, nMaxChars: 1024);
      v12 = _V_strlen(str: temp);
      v10[8] = len_3;
      v13 = UnsignedShort;
      v14 = v12 + 1;
      v10[9] = data_3;
      v10[10] = v13;
      v10[11] = v11;
      v15 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v12 + 1);
      *(_DWORD *)v10 = v15;
      memcpy(dst: v15, src: (unsigned __int8 *)temp, count: v14);
      v22 += 12;
      v16 = v21-- == 1;
      *((_DWORD *)v10 + 1) = 0;
      if ( v16 )
        break;
      v9 = v22;
      v6 = v19;
    }
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1008FC00
// Name: public: virtual void CRConVProfExport::OnRemoteData(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConVProfExport::OnRemoteData(CRConVProfExport *this, void *data, unsigned int len)
{
  CUtlBuffer buf; // [esp+Ch] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: data, nSize: len, nFlags: 8);
  this->m_Times.m_Memory.m_nGrowSize = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_Info.m_pElements,
    elem: 0,
    num: len >> 2);
  memcpy(dst: (unsigned __int8 *)this->m_Info.m_pElements, src: (unsigned __int8 *)data, count: 4 * (len >> 2));
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1008FC70
// Name: public: CRConClient::CRConClient(void)
// Source: json
//------------------------------------------------------------------------------
CRConClient *__thiscall CRConClient::CRConClient(CRConClient *this)
{
  this->__vftable = (CRConClient_vtbl *)&CRConClient::`vftable';
  this->m_VProfExport.__vftable = (IVProfData_vtbl *)&IVProfData::`vftable';
  this->m_VProfExport.__vftable = (CRConVProfExport_vtbl *)&CRConVProfExport::`vftable'{for `IVProfExport'};
  this->m_VProfExport.__vftable = (IVProfData_vtbl *)&CRConVProfExport::`vftable'{for `IVProfData'};
  this->m_VProfExport.m_Info.m_Memory.m_pMemory = nullptr;
  this->m_VProfExport.m_Info.m_Memory.m_nAllocationCount = 0;
  this->m_VProfExport.m_Info.m_Memory.m_nGrowSize = 0;
  this->m_VProfExport.m_Info.m_Size = 0;
  this->m_VProfExport.m_Info.m_pElements = nullptr;
  this->m_VProfExport.m_Times.m_Memory.m_pMemory = nullptr;
  this->m_VProfExport.m_Times.m_Memory.m_nAllocationCount = 0;
  this->m_VProfExport.m_Times.m_Memory.m_nGrowSize = 0;
  this->m_VProfExport.m_Times.m_Size = 0;
  this->m_VProfExport.m_Times.m_pElements = nullptr;
  CSocketCreator::CSocketCreator(this: &this->m_Socket, pListener: this);
  netadr_s::SetIP(this: &this->m_Address, unIP: 0);
  netadr_s::SetPort(this: &this->m_Address, newport: 0);
  netadr_s::SetType(this: &this->m_Address, newtype: NA_IP);
  CUtlBuffer::CUtlBuffer(this: &this->m_RecvBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &this->m_SendBuffer, growSize: 0, initSize: 0, nFlags: 0);
  CUtlString::CUtlString(this: &this->m_Password);
  CUtlString::CUtlString(this: &this->m_RemoteFileDir);
  this->m_bAuthenticated = false;
  this->m_iReqID = 0;
  this->m_nScreenShotIndex = 0;
  this->m_nConsoleLogIndex = 0;
  this->m_iAuthRequestID = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008FD30
// Name: private: void CRConClient::SendResponse(class CUtlBuffer __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SendResponse(CRConClient *this, CUtlBuffer *response, bool bAutoAuthenticate)
{
  int m_nMaxPut; // eax
  SOCKET AcceptedSocketHandle; // eax
  unsigned __int8 *responsea; // [esp+Ch] [ebp+8h]
  int bAutoAuthenticatea; // [esp+10h] [ebp+Ch]

  if ( !bAutoAuthenticate || this->m_bAuthenticated )
  {
    m_nMaxPut = response->m_nMaxPut;
    responsea = response->m_Memory.m_pMemory;
    bAutoAuthenticatea = m_nMaxPut;
    AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
    if ( send(s: AcceptedSocketHandle, buf: (const char *)responsea, len: bAutoAuthenticatea, flags: 0) == -1 )
    {
      if ( SocketWouldBlock() )
      {
        CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response->m_Memory.m_pMemory, size: response->m_nMaxPut);
      }
      else
      {
        _Warning(a1: "Lost RCON connection, please retry command\n");
        CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
      }
    }
  }
  else
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) > 0 )
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response->m_Memory.m_pMemory, size: response->m_nMaxPut);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FDE0
// Name: public: void CRConClient::SendCmd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SendCmd(CRConClient *this, const char *msg)
{
  const char *v3; // eax
  int m_nMaxPut; // ebx
  SOCKET AcceptedSocketHandle; // eax
  CUtlBuffer response; // [esp+Ch] [ebp-30h] BYREF
  const char *msga; // [esp+44h] [ebp+8h]

  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0
    && CSocketCreator::ConnectSocket(this: &this->m_Socket, netAdr: &this->m_Address, bSingleSocket: true) < 0 )
  {
    v3 = netadr_s::ToString(this: &this->m_Address, baseOnly: false);
    _Warning(a1: "Unable to connect to remote server (%s)\n", v3);
    return;
  }
  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  CRConClient::BuildResponse(this, &response, msg: SERVERDATA_EXECCOMMAND, pString1: msg, pString2: defaultValue);
  if ( !this->m_bAuthenticated )
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
      goto LABEL_10;
    goto LABEL_6;
  }
  m_nMaxPut = response.m_nMaxPut;
  msga = (const char *)response.m_Memory.m_pMemory;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( send(s: AcceptedSocketHandle, buf: msga, len: m_nMaxPut, flags: 0) == -1 )
  {
    if ( SocketWouldBlock() )
    {
LABEL_6:
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response.m_Memory.m_pMemory, size: response.m_nMaxPut);
      goto LABEL_10;
    }
    _Warning(a1: "Lost RCON connection, please retry command\n");
    CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  }
LABEL_10:
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1008FF00
// Name: public: void CRConClient::StartVProfData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::StartVProfData(CRConClient *this)
{
  const char *v2; // eax
  int m_nMaxPut; // ebx
  SOCKET AcceptedSocketHandle; // eax
  CUtlBuffer response; // [esp+Ch] [ebp-34h] BYREF
  char *buf; // [esp+3Ch] [ebp-4h]

  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0
    && CSocketCreator::ConnectSocket(this: &this->m_Socket, netAdr: &this->m_Address, bSingleSocket: true) < 0 )
  {
    v2 = netadr_s::ToString(this: &this->m_Address, baseOnly: false);
    _Warning(a1: "Unable to connect to remote server (%s)\n", v2);
    return;
  }
  OverrideVProfExport(pExport: &this->m_VProfExport);
  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  CRConClient::BuildResponse(this, &response, msg: SERVERDATA_VPROF, pString1: defaultValue, pString2: defaultValue);
  if ( !this->m_bAuthenticated )
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
      goto LABEL_10;
    goto LABEL_6;
  }
  m_nMaxPut = response.m_nMaxPut;
  buf = (char *)response.m_Memory.m_pMemory;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( send(s: AcceptedSocketHandle, buf, len: m_nMaxPut, flags: 0) == -1 )
  {
    if ( SocketWouldBlock() )
    {
LABEL_6:
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response.m_Memory.m_pMemory, size: response.m_nMaxPut);
      goto LABEL_10;
    }
    _Warning(a1: "Lost RCON connection, please retry command\n");
    CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  }
LABEL_10:
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10090030
// Name: public: void CRConClient::StopVProfData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::StopVProfData(CRConClient *this)
{
  int m_nMaxPut; // ebx
  SOCKET AcceptedSocketHandle; // eax
  CUtlBuffer response; // [esp+8h] [ebp-34h] BYREF
  char *buf; // [esp+38h] [ebp-4h]

  ResetVProfExport(pExport: &this->m_VProfExport);
  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
    return;
  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  CRConClient::BuildResponse(
    this,
    &response,
    msg: SERVERDATA_REMOVE_VPROF,
    pString1: defaultValue,
    pString2: defaultValue);
  if ( !this->m_bAuthenticated )
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
      goto LABEL_8;
    goto LABEL_4;
  }
  m_nMaxPut = response.m_nMaxPut;
  buf = (char *)response.m_Memory.m_pMemory;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( send(s: AcceptedSocketHandle, buf, len: m_nMaxPut, flags: 0) == -1 )
  {
    if ( SocketWouldBlock() )
    {
LABEL_4:
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response.m_Memory.m_pMemory, size: response.m_nMaxPut);
      goto LABEL_8;
    }
    _Warning(a1: "Lost RCON connection, please retry command\n");
    CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  }
LABEL_8:
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10090370
// Name: public: void CRConClient::SendBugRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRConClient::SendBugRequest(CRConClient *this)
{
  const char *v2; // eax
  int m_nMaxPut; // ebx
  SOCKET AcceptedSocketHandle; // eax
  CUtlBuffer response; // [esp+Ch] [ebp-34h] BYREF
  char *buf; // [esp+3Ch] [ebp-4h]

  if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0
    && CSocketCreator::ConnectSocket(this: &this->m_Socket, netAdr: &this->m_Address, bSingleSocket: true) < 0 )
  {
    v2 = netadr_s::ToString(this: &this->m_Address, baseOnly: false);
    _Warning(a1: "Unable to connect to remote server (%s)\n", v2);
    _Warning(a1: "Could not connect to remote machine, remote bug command failed\n");
    return;
  }
  CUtlBuffer::CUtlBuffer(this: &response, growSize: 0, initSize: 0, nFlags: 0);
  CRConClient::BuildResponse(
    this,
    &response,
    msg: SERVERDATA_SEND_REMOTEBUG,
    pString1: defaultValue,
    pString2: defaultValue);
  if ( !this->m_bAuthenticated )
  {
    CRConClient::Authenticate(this);
    if ( CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&this->m_Socket) <= 0 )
      goto LABEL_10;
    goto LABEL_6;
  }
  m_nMaxPut = response.m_nMaxPut;
  buf = (char *)response.m_Memory.m_pMemory;
  AcceptedSocketHandle = CSocketCreator::GetAcceptedSocketHandle(this: &this->m_Socket, nIndex: 0);
  if ( send(s: AcceptedSocketHandle, buf, len: m_nMaxPut, flags: 0) == -1 )
  {
    if ( SocketWouldBlock() )
    {
LABEL_6:
      CUtlBuffer::Put(this: &this->m_SendBuffer, pMem: response.m_Memory.m_pMemory, size: response.m_nMaxPut);
      goto LABEL_10;
    }
    _Warning(a1: "Lost RCON connection, please retry command\n");
    CSocketCreator::CloseAllAcceptedSockets(this: &this->m_Socket);
  }
LABEL_10:
  if ( response.m_Memory.m_nGrowSize >= 0 && response.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: response.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100904A0
// Name: remote_bug
// Source: json
//------------------------------------------------------------------------------
void __cdecl remote_bug()
{
  CRConClient::SendBugRequest(this: &g_RCONClient);
}

//------------------------------------------------------------------------------
// Address: 0x100904B0
// Name: public: virtual void CRPTClient::OnSocketAccepted(int,struct netadr_s const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRPTClient::OnSocketAccepted(
        CRPTClient *this,
        int hSocket,
        const netadr_s *netAdr,
        const netadr_s *ppData)
{
  Cmd_SetRptActive(bActive: true);
  CRConClient::StartVProfData(this);
}

//------------------------------------------------------------------------------
// Address: 0x100904D0
// Name: public: virtual void CRPTClient::OnSocketClosed(int,struct netadr_s const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRPTClient::OnSocketClosed(CRPTClient *this, int hSocket, const netadr_s *netAdr, void *pData)
{
  CRConClient::StopVProfData(this);
  Cmd_SetRptActive(bActive: false);
  CRConClient::OnSocketClosed(this, hSocket, netAdr, pData);
}

//------------------------------------------------------------------------------
// Address: 0x10090500
// Name: rpt_screenshot
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_screenshot()
{
  CRConClient::TakeScreenshot(this: &g_RPTClient);
}

//------------------------------------------------------------------------------
// Address: 0x10090510
// Name: rpt_download_log
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_download_log()
{
  CRConClient::GrabConsoleLog(this: &g_RPTClient);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x103139B0
// Name: _dynamic_initializer_for__rcon_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rcon_command__()
{
  ConCommand::ConCommand(
    this: &rcon_command,
    pName: "rcon",
    callback: rcon,
    pHelpString: "Issue an rcon command.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rcon_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313C30
// Name: _dynamic_initializer_for__rcon_address__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rcon_address__()
{
  ConVar::ConVar(
    this: &rcon_address,
    pName: "rcon_address",
    pDefaultValue: defaultValue,
    flags: 537001984,
    pHelpString: "Address of remote server if sending unconnected rcon commands (format x.x.x.x:p) ",
    callback: RconAddressChanged_f);
  return atexit(func: dynamic_atexit_destructor_for__rcon_address__);
}

//------------------------------------------------------------------------------
// Address: 0x10318780
// Name: _dynamic_initializer_for__rcon_password__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__rcon_password__()
{
  ConVar::ConVar(
    this: &rcon_password,
    pName: "rcon_password",
    pDefaultValue: defaultValue,
    flags: 537526272,
    pHelpString: "remote console password.",
    callback: RconPasswordChanged_f);
  return atexit(func: dynamic_atexit_destructor_for__rcon_password__);
}

//------------------------------------------------------------------------------
// Address: 0x103229F0
// Name: _dynamic_atexit_destructor_for__rcon_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rcon_command__()
{
  ConCommand::~ConCommand(this: &rcon_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322AC0
// Name: _dynamic_atexit_destructor_for__rcon_address__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rcon_address__()
{
  ConVar::~ConVar(this: &rcon_address);
}

//------------------------------------------------------------------------------
// Address: 0x10324910
// Name: _dynamic_atexit_destructor_for__rcon_password__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rcon_password__()
{
  ConVar::~ConVar(this: &rcon_password);
}

//------------------------------------------------------------------------------
// Address: 0x103139E0
// Name: _dynamic_initializer_for__box_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__box_command__()
{
  ConCommand::ConCommand(
    this: &box_command,
    pName: "box",
    callback: box,
    pHelpString: "Draw a debug box.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__box_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322A00
// Name: _dynamic_atexit_destructor_for__box_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__box_command__()
{
  ConCommand::~ConCommand(this: &box_command);
}

} // namespace engine_xlsp
