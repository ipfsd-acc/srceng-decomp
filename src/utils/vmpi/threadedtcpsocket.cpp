// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/threadedtcpsocket.cpp
// Functions: 37
// ============================================================

#include "utils\vmpi\threadedtcpsocket.h"

//------------------------------------------------------------------------------
// Address: 0x10021820
// Name: public: void CTCPPacket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPPacket::Release(CVMPIFile_Memory *this)
{
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x10028820
// Name: public: int CTCPPacket::GetUserData(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CTCPPacket::GetUserData(CEvent *this)
{
  return this->m_hEvent;
}

//------------------------------------------------------------------------------
// Address: 0x1002B3A0
// Name: TCPBind
// Source: json
//------------------------------------------------------------------------------
SOCKET __cdecl TCPBind(const CIPAddr *pAddr)
{
  SOCKET v1; // esi
  sockaddr_in addr; // [esp+4h] [ebp-10h] BYREF

  v1 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v1 != -1 )
  {
    IPAddrToSockAddr(pIn: pAddr, pOut: &addr);
    if ( bind(s: v1, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
      return v1;
    closesocket(s: v1);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B400
// Name: public: void CTCPPacket::SetUserData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPPacket::SetUserData(CTCPPacket *this, int userData)
{
  this->m_UserData = userData;
}

//------------------------------------------------------------------------------
// Address: 0x1002B410
// Name: private: void CThreadedTCPSocket::HandleError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, int errorCode, const char *pErrorString)
{
  this->m_pHandler->OnError(this: this->m_pHandler, a2: errorCode, a3: pErrorString);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  this->m_bErrorSignal = true;
}

//------------------------------------------------------------------------------
// Address: 0x1002B450
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Connector::Create(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl CTCPConnectSocket_Connector::Create(
        const CIPAddr *connectAddr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  CIPAddr *v3; // eax
  CIPAddr *v4; // esi
  SOCKET v5; // edi
  int v6; // eax
  SOCKET v8; // [esp-Ch] [ebp-38h]
  sockaddr_in addr; // [esp+8h] [ebp-24h] BYREF
  sockaddr_in pOut; // [esp+18h] [ebp-14h] BYREF
  unsigned int val; // [esp+28h] [ebp-4h] BYREF

  v3 = (CIPAddr *)operator new(nSize: 0x18u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3->ip = &CTCPConnectSocket_Connector::`vftable';
    CIPAddr::CIPAddr(this: v3 + 2);
    *(_DWORD *)&v4[1].ip[2] = -1;
    v4->port = 0;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v5 == -1 )
    goto LABEL_7;
  IPAddrToSockAddr(pIn: localAddr, &pOut);
  if ( bind(s: v5, name: (const struct sockaddr *)&pOut, namelen: 16) != 0 )
  {
    closesocket(s: v5);
LABEL_7:
    v5 = -1;
  }
  *(_DWORD *)&v4[1].ip[2] = v5;
  if ( v5 != -1 )
  {
    IPAddrToSockAddr(pIn: connectAddr, pOut: &addr);
    val = 1;
    if ( ioctlsocket(s: *(_DWORD *)&v4[1].ip[2], cmd: -2147195266, argp: &val) == 0 )
    {
      v4[2] = *connectAddr;
      v8 = *(_DWORD *)&v4[1].ip[2];
      *(_DWORD *)&v4[3].ip[2] = pHandlerCreator;
      v6 = connect(s: v8, name: (const struct sockaddr *)&addr, namelen: 16);
      if ( v6 == 0 )
      {
        HIBYTE(v4->port) = 1;
        return v4;
      }
      if ( v6 == -1 && WSAGetLastError() == 10035 )
        return v4;
    }
  }
  (**(void (__thiscall ***)(CIPAddr *))v4->ip)(a1: v4);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002B570
// Name: public: virtual void CTCPConnectSocket_Listener::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPConnectSocket_Listener::Release(CTCPConnectSocket_Listener *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CTCPConnectSocket_Listener *, int))this->dtr_CTCPConnectSocket_Listener)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002B580
// Name: public: bool CTCPConnectSocket_Connector::EnterErrorMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::EnterErrorMode(CTCPConnectSocket_Connector *this)
{
  SOCKET m_Socket; // [esp-4h] [ebp-8h]

  m_Socket = this->m_Socket;
  this->m_bError = true;
  closesocket(s: m_Socket);
  this->m_Socket = -1;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1002B5E0
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateConnector(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl ThreadedTCP_CreateConnector(
        const CIPAddr *addr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  return CTCPConnectSocket_Connector::Create(connectAddr: addr, localAddr, pHandlerCreator);
}

//------------------------------------------------------------------------------
// Address: 0x1002B5F0
// Name: void ThreadedTCP_EnableTimeouts(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadedTCP_EnableTimeouts(bool bEnable)
{
  g_bHandleTimeouts = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1002B600
// Name: void ThreadedTCP_SetTCPSocketThreadPriorities(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadedTCP_SetTCPSocketThreadPriorities(bool bSetTCPSocketThreadPriorities)
{
  g_bSetTCPSocketThreadPriorities = bSetTCPSocketThreadPriorities;
}

//------------------------------------------------------------------------------
// Address: 0x1002B610
// Name: private: void CThreadedTCPSocket::HandleError(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, unsigned int errorValue)
{
  DWORD LastError; // eax
  char *v4; // edx
  int i; // eax
  char v6; // cl
  char *v7; // [esp-4h] [ebp-10h]
  char *lpMsgBuf; // [esp+8h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  v4 = lpMsgBuf;
  for ( i = strlen(lpMsgBuf); i > 0; v4 = lpMsgBuf )
  {
    v6 = v4[i - 1];
    if ( v6 != 10 && v6 != 13 )
      break;
    v4[--i] = 0;
  }
  this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: v4);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  v7 = lpMsgBuf;
  this->m_bErrorSignal = true;
  LocalFree(hMem: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1002B6E0
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Listener::Create(class IHandlerCreator __near *,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__cdecl CTCPConnectSocket_Listener::Create(
        IHandlerCreator *pHandlerCreator,
        unsigned __int16 port,
        int nQueueLength)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  SOCKET v5; // eax
  int v6; // ecx
  CIPAddr addr; // [esp+4h] [ebp-8h] BYREF

  v3 = operator new(nSize: 0xCu);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  *v3 = &CTCPConnectSocket_Listener::`vftable';
  v3[1] = -1;
  if ( nQueueLength < 0 )
    _Error(
      a1: "CTCPConnectSocket_Listener::Create - SOMAXCONN not allowed - causes some XP SP2 systems to stop receiving any netw"
      "ork data (systemwide).");
  CIPAddr::CIPAddr(this: &addr, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: port);
  v5 = TCPBind(pAddr: &addr);
  v4[1] = v5;
  if ( v5 == -1 )
    goto LABEL_10;
  v6 = 0x7FFFFFFF;
  if ( nQueueLength != -1 )
    v6 = nQueueLength;
  if ( listen(s: v5, backlog: v6) != 0 )
  {
LABEL_10:
    (*(void (__thiscall **)(_DWORD *))*v4)(a1: v4);
    return nullptr;
  }
  else
  {
    v4[2] = pHandlerCreator;
    return (ITCPConnectSocket *)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B780
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateListener(class IHandlerCreator __near *,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__cdecl ThreadedTCP_CreateListener(
        IHandlerCreator *pHandlerCreator,
        unsigned __int16 port,
        int nQueueLength)
{
  return CTCPConnectSocket_Listener::Create(pHandlerCreator, port, nQueueLength);
}

//------------------------------------------------------------------------------
// Address: 0x1002B790
// Name: private: bool CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(CThreadedTCPSocket *this)
{
  CThreadedTCPSocket::SendData_t *m_Element; // eax
  int v3; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-38h]
  _WSABUF buf; // [esp+8h] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+18h] [ebp-4h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Element = this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element;
  buf.len = m_Element->m_Len;
  buf.buf = m_Element->m_Payload;
  this->m_nBytesToTransfer = m_Element->m_Len;
  this->m_bWaitingForSendCompletion = true;
  CCriticalSectionLock::Unlock(this: &csLock);
  m_Socket = this->m_Socket;
  dwNumBytesSent = 0;
  v3 = WSASend(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesSent: &dwNumBytesSent,
         dwFlags: 0,
         lpOverlapped: &this->m_SendOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B850
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalRecv(void __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalRecv(
        CThreadedTCPSocket *this,
        char *pDest,
        int destSize,
        unsigned int bContinuation,
        unsigned int bWaitingForSize)
{
  int v6; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-2Ch]
  _WSABUF buf; // [esp+8h] [ebp-8h] BYREF

  buf.len = destSize;
  buf.buf = pDest;
  if ( (_BYTE)bContinuation == 0 )
  {
    this->m_bWaitingForSize = bWaitingForSize;
    this->m_nBytesToReceive = destSize;
    this->m_nBytesReceivedSoFar = 0;
  }
  m_Socket = this->m_Socket;
  bContinuation = 0;
  bWaitingForSize = 0;
  v6 = WSARecv(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &bWaitingForSize,
         lpFlags: &bContinuation,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v6 == 0 || v6 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002BA20
// Name: private: bool CThreadedTCPSocket::RecvThread_WaitToReceiveSize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_WaitToReceiveSize(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  int v3; // edi
  unsigned int Error; // eax
  _WSABUF Buffers; // [esp+8h] [ebp-10h] BYREF
  unsigned int NumberOfBytesRecvd; // [esp+10h] [ebp-8h] BYREF
  unsigned int Flags; // [esp+14h] [ebp-4h] BYREF

  Buffers.len = 4;
  this->m_nBytesToReceive = 4;
  m_Socket = this->m_Socket;
  Buffers.buf = (char *)&this->m_NextPacketLen;
  this->m_bWaitingForSize = true;
  this->m_nBytesReceivedSoFar = 0;
  Flags = 0;
  NumberOfBytesRecvd = 0;
  v3 = WSARecv(
         s: m_Socket,
         lpBuffers: &Buffers,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &NumberOfBytesRecvd,
         lpFlags: &Flags,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002BAC0
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(
        CThreadedTCPSocket *this,
        signed int dwTransfer)
{
  int m_nBytesToReceive; // eax
  int m_nBytesReceivedSoFar; // edi
  bool v6; // zf
  char *p_m_NextPacketLen; // edx
  int m_NextPacketLen; // eax
  CTCPPacket *v9; // eax
  char pDest[512]; // [esp+8h] [ebp-400h] BYREF
  char str[512]; // [esp+208h] [ebp-200h] BYREF

  m_nBytesToReceive = this->m_nBytesToReceive;
  m_nBytesReceivedSoFar = this->m_nBytesReceivedSoFar;
  if ( dwTransfer > m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    V_snprintf(
      pDest: str,
      maxLen: 0x200u,
      pFormat: "Invalid # bytes received (%d) in recv thread (should be %d)",
      dwTransfer,
      m_nBytesToReceive);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  if ( dwTransfer < m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    v6 = !this->m_bWaitingForSize;
    this->m_nBytesReceivedSoFar = m_nBytesReceivedSoFar + dwTransfer;
    p_m_NextPacketLen = (char *)&this->m_NextPacketLen;
    if ( v6 )
      p_m_NextPacketLen = this->m_pRecvBuffer->m_Data;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: &p_m_NextPacketLen[m_nBytesReceivedSoFar + dwTransfer],
             destSize: m_nBytesToReceive - (m_nBytesReceivedSoFar + dwTransfer),
             bContinuation: 1u,
             bWaitingForSize: 0);
  }
  if ( !this->m_bWaitingForSize )
  {
    this->m_pHandler->OnPacketReceived(this: this->m_pHandler, a2: this->m_pRecvBuffer);
    this->m_pRecvBuffer = nullptr;
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  }
  m_NextPacketLen = this->m_NextPacketLen;
  if ( m_NextPacketLen == -12345 )
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  if ( m_NextPacketLen < 1 || m_NextPacketLen > 78643200 )
  {
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "Invalid packet size in RecvThread (size = %d)", this->m_NextPacketLen);
    CThreadedTCPSocket::HandleError(this, errorCode: 0, pErrorString: pDest);
    return 0;
  }
  else
  {
    v9 = (CTCPPacket *)operator new(nSize: m_NextPacketLen + 11);
    this->m_pRecvBuffer = v9;
    v9->m_UserData = 0;
    this->m_pRecvBuffer->m_Len = this->m_NextPacketLen;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: this->m_pRecvBuffer->m_Data,
             destSize: this->m_pRecvBuffer->m_Len,
             bContinuation: 0,
             bWaitingForSize: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BC40
// Name: private: unsigned long CThreadedTCPSocket::RecvThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::RecvThreadFn(CThreadedTCPSocket *this)
{
  DWORD v3; // eax
  bool i; // zf
  unsigned int Error; // eax
  DWORD LastError; // eax
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int dwFlags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  void *handles[2]; // [esp+20Ch] [ebp-8h] BYREF

  if ( CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this) == 0 )
    return 1;
  handles[0] = CTCPPacket::GetUserData(this: &this->m_hExitThreadsEvent);
  handles[1] = CTCPPacket::GetUserData(this: &this->m_hRecvEvent);
  v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  for ( i = v3 == 258; v3 <= 0x102; i = v3 == 258 )
  {
    if ( i )
    {
      if ( g_bHandleTimeouts )
      {
        this->m_pHandler->OnError(this: this->m_pHandler, a2: 1, a3: "Connection timed out");
LABEL_17:
        CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
        this->m_bErrorSignal = true;
        return 1;
      }
    }
    else
    {
      if ( v3 == 0 )
        return 0;
      if ( v3 != 1 )
        goto LABEL_13;
      if ( !WSAGetOverlappedResult(
              s: this->m_Socket,
              lpOverlapped: &this->m_RecvOverlapped,
              lpcbTransfer: &cbTransfer,
              fWait: true,
              lpdwFlags: &dwFlags) )
      {
        Error = WSAGetLastError();
        CThreadedTCPSocket::HandleError(this, errorValue: Error);
        return 1;
      }
      if ( CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(this, dwTransfer: cbTransfer) == 0 )
        return 1;
    }
    v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  }
  if ( v3 != -1 )
  {
LABEL_13:
    V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v3);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    goto LABEL_17;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002BDB0
// Name: private: static unsigned long CThreadedTCPSocket::StaticRecvThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticRecvThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::RecvThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x1002BDC0
// Name: private: CThreadedTCPSocket::CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__thiscall CThreadedTCPSocket::CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // eax

  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hReadyToSendEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hSendCompletionEvent);
  CCriticalSection::CCriticalSection(this: &this->m_SendCS);
  this->m_SendDatas.m_Memory.m_pMemory = nullptr;
  this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  this->m_SendDatas.m_Memory.m_nGrowSize = 0;
  this->m_SendDatas.m_LastAlloc.index = -1;
  m_pMemory = this->m_SendDatas.m_Memory.m_pMemory;
  this->m_SendDatas.m_Head = -1;
  this->m_SendDatas.m_Tail = -1;
  this->m_SendDatas.m_FirstFree = -1;
  this->m_SendDatas.m_ElementCount = 0;
  this->m_SendDatas.m_NumAlloced = 0;
  this->m_SendDatas.m_pElements = m_pMemory;
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hRecvEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hExitThreadsEvent);
  CIPAddr::CIPAddr(this: &this->m_RemoteAddr);
  this->m_Socket = -1;
  this->m_pHandler = nullptr;
  *(_QWORD *)&this->m_SendOverlapped.Internal = 0;
  *(_QWORD *)&this->m_SendOverlapped.Offset = 0;
  this->m_SendOverlapped.hEvent = nullptr;
  *(_QWORD *)&this->m_RecvOverlapped.Internal = 0;
  *(_QWORD *)&this->m_RecvOverlapped.Offset = 0;
  this->m_RecvOverlapped.hEvent = nullptr;
  this->m_nBytesToReceive = -1;
  this->m_bWaitingForSendCompletion = false;
  this->m_bWaitingForSize = false;
  this->m_bErrorSignal = false;
  this->m_pRecvBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002BEB0
// Name: public: virtual void CThreadedTCPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Release(CThreadedTCPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CThreadedTCPSocket *, int))this->dtr_CThreadedTCPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002BEC0
// Name: public: virtual class CIPAddr CThreadedTCPSocket::GetRemoteAddr(void)const
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CThreadedTCPSocket::GetRemoteAddr(CThreadedTCPSocket *this, CIPAddr *result)
{
  int v2; // edx
  unsigned __int16 port; // cx

  v2 = *(_DWORD *)this->m_RemoteAddr.ip;
  port = this->m_RemoteAddr.port;
  *(_DWORD *)result->ip = v2;
  result->port = port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002BEE0
// Name: public: virtual bool CThreadedTCPSocket::Send(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::Send(CThreadedTCPSocket *this, const void *pData, int len)
{
  return this->SendChunks(this, a2: &pData, a3: &len, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002BF00
// Name: public: virtual class ITCPSocketHandler __near * CThreadedTCPSocket::GetHandler(void)
// Source: json
//------------------------------------------------------------------------------
ITCPSocketHandler *__thiscall CThreadedTCPSocket::GetHandler(CThreadedTCPSocket *this)
{
  return this->m_pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x1002BF10
// Name: private: void CThreadedTCPSocket::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Term(CThreadedTCPSocket *this)
{
  void *m_hSendThread; // eax
  void *m_hRecvThread; // eax
  ITCPSocketHandler *m_pHandler; // ecx

  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  m_hSendThread = this->m_hSendThread;
  if ( m_hSendThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hSendThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hSendThread);
    this->m_hSendThread = nullptr;
  }
  m_hRecvThread = this->m_hRecvThread;
  if ( m_hRecvThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hRecvThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hRecvThread);
    this->m_hRecvThread = nullptr;
  }
  CEvent::ResetEvent(this: &this->m_hExitThreadsEvent);
  if ( this->m_Socket != -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  if ( this->m_bDeleteHandler )
  {
    m_pHandler = this->m_pHandler;
    if ( m_pHandler != nullptr )
    {
      m_pHandler->Release(this: m_pHandler, a2: false);
      this->m_pHandler = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BFC0
// Name: public: virtual bool CThreadedTCPSocket::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::IsValid(CThreadedTCPSocket *this)
{
  return !this->m_bErrorSignal;
}

//------------------------------------------------------------------------------
// Address: 0x1002BFD0
// Name: private: virtual CThreadedTCPSocket::~CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::~CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CThreadedTCPSocket::Term(this);
  CEvent::~CEvent(this: &this->m_hExitThreadsEvent);
  CEvent::~CEvent(this: &this->m_hRecvEvent);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_SendDatas);
  if ( this->m_SendDatas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SendDatas.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendDatas.m_Memory.m_pMemory);
      this->m_SendDatas.m_Memory.m_pMemory = nullptr;
    }
    this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  }
  CCriticalSection::~CCriticalSection(this: &this->m_SendCS);
  CEvent::~CEvent(this: &this->m_hSendCompletionEvent);
  CEvent::~CEvent(this: &this->m_hReadyToSendEvent);
}

//------------------------------------------------------------------------------
// Address: 0x1002C090
// Name: private: bool CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  unsigned int Error; // eax
  int m_Head; // ebx
  bool v6; // cc
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int flags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  CCriticalSectionLock csLock; // [esp+20Ch] [ebp-8h] BYREF

  m_Socket = this->m_Socket;
  this->m_bWaitingForSendCompletion = false;
  if ( WSAGetOverlappedResult(
         s: m_Socket,
         lpOverlapped: &this->m_SendOverlapped,
         lpcbTransfer: &cbTransfer,
         fWait: true,
         lpdwFlags: &flags) )
  {
    if ( cbTransfer == this->m_nBytesToTransfer )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &csLock);
      free(pMem: this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element);
      m_Head = this->m_SendDatas.m_Head;
      CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_SendDatas,
        elem: m_Head);
      this->m_SendDatas.m_Memory.m_pMemory[m_Head].m_Next = this->m_SendDatas.m_FirstFree;
      this->m_SendDatas.m_FirstFree = m_Head;
      v6 = this->m_SendDatas.m_ElementCount <= 0;
      this->m_bWaitingForSendCompletion = false;
      if ( !v6 )
        CEvent::SetEvent(this: &this->m_hReadyToSendEvent);
      CCriticalSectionLock::Unlock(this: &csLock);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    }
    else
    {
      V_snprintf(
        pDest: str,
        maxLen: 0x200u,
        pFormat: "Invalid # bytes transferred (%d) in send thread (should be %d)",
        cbTransfer,
        this->m_nBytesToTransfer);
      this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
      CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
      this->m_bErrorSignal = true;
      return 0;
    }
  }
  else
  {
    Error = WSAGetLastError();
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C1C0
// Name: private: bool CThreadedTCPSocket::InternalSend(void const __near * const __near *,int const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::InternalSend(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks,
        bool bPrependLength)
{
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // esi
  int v10; // eax
  int v11; // esi
  int *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  unsigned int *v15; // esi
  int v16; // ebx
  CThreadedTCPSocket *v17; // ebx
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int> > *p_m_SendDatas; // esi
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // edx
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // ecx
  int v24; // edx
  int m_Tail; // edi
  CThreadedTCPSocket::SendData_t **p_m_Element; // esi
  CCriticalSectionLock csLock; // [esp+Ch] [ebp-Ch] BYREF
  CThreadedTCPSocket *v29; // [esp+14h] [ebp-4h]
  CThreadedTCPSocket::SendData_t *pSendData; // [esp+24h] [ebp+Ch]
  int bPrependLengtha; // [esp+2Ch] [ebp+14h]

  v6 = nChunks;
  v29 = this;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( nChunks >= 2 )
  {
    do
    {
      v7 += *(_DWORD *)&pChunkLengths[4 * v10];
      v8 += *(_DWORD *)&pChunkLengths[4 * v10 + 4];
      v10 += 2;
    }
    while ( v10 < nChunks - 1 );
    v6 = nChunks;
  }
  if ( v10 < v6 )
    v9 = *(_DWORD *)&pChunkLengths[4 * v10];
  v11 = v8 + v7 + v9;
  if ( bPrependLength )
  {
    if ( v11 == 0 )
      return 1;
    v11 += 4;
  }
  v12 = (int *)operator new(nSize: v11 + 7);
  pSendData = (CThreadedTCPSocket::SendData_t *)v12;
  *v12 = v11;
  v13 = (unsigned __int8 *)(v12 + 1);
  if ( bPrependLength )
  {
    *(_DWORD *)v13 = v11 - 4;
    v13 = (unsigned __int8 *)(v12 + 2);
  }
  if ( nChunks > 0 )
  {
    v14 = (char *)pChunks - pChunkLengths;
    v15 = (unsigned int *)pChunkLengths;
    bPrependLengtha = (char *)pChunks - pChunkLengths;
    v16 = nChunks;
    while ( 1 )
    {
      memcpy(dst: v13, src: *(unsigned __int8 **)((char *)v15 + v14), count: *v15);
      v13 += *v15++;
      if ( --v16 == 0 )
        break;
      v14 = bPrependLengtha;
    }
  }
  v17 = v29;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &v29->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  p_m_SendDatas = &v17->m_SendDatas;
  v19 = CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal(
          this: &v17->m_SendDatas,
          multilist: false);
  if ( v19 != -1 )
  {
    if ( v19 >= 0 && v19 < v17->m_SendDatas.m_Memory.m_nAllocationCount && v19 <= v17->m_SendDatas.m_LastAlloc.index )
    {
      v20 = (int)&p_m_SendDatas->m_Memory.m_pMemory[v19];
      if ( *(_DWORD *)(v20 + 4) != v19 )
      {
        v21 = *(_DWORD *)(v20 + 4);
        if ( v21 == -1 )
          v17->m_SendDatas.m_Head = *(_DWORD *)(v20 + 8);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v21].m_Next = *(_DWORD *)(v20 + 8);
        v22 = *(_DWORD *)(v20 + 8);
        if ( v22 == -1 )
          v17->m_SendDatas.m_Tail = *(_DWORD *)(v20 + 4);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v22].m_Previous = *(_DWORD *)(v20 + 4);
        v17 = v29;
        *(_DWORD *)(v20 + 8) = v19;
        *(_DWORD *)(v20 + 4) = v19;
        --p_m_SendDatas->m_ElementCount;
      }
    }
    m_pMemory = p_m_SendDatas->m_Memory.m_pMemory;
    v24 = v19;
    m_pMemory[v24].m_Next = -1;
    m_Tail = p_m_SendDatas->m_Tail;
    m_pMemory[v24].m_Previous = m_Tail;
    p_m_SendDatas->m_Tail = v19;
    if ( m_Tail == -1 )
      p_m_SendDatas->m_Head = v19;
    else
      p_m_SendDatas->m_Memory.m_pMemory[m_Tail].m_Next = v19;
    ++p_m_SendDatas->m_ElementCount;
    p_m_Element = &p_m_SendDatas->m_Memory.m_pMemory[v24].m_Element;
    if ( p_m_Element != nullptr )
      *p_m_Element = pSendData;
  }
  CEvent::SetEvent(this: &v17->m_hReadyToSendEvent);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002C350
// Name: private: unsigned long CThreadedTCPSocket::SendThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::SendThreadFn(CThreadedTCPSocket *this)
{
  void *UserData; // eax
  bool v3; // zf
  DWORD v4; // eax
  DWORD v5; // eax
  int m_ElementCount; // edi
  DWORD LastError; // eax
  char str[512]; // [esp+Ch] [ebp-21Ch] BYREF
  void *handles[3]; // [esp+20Ch] [ebp-1Ch] BYREF
  void *pChunks; // [esp+218h] [ebp-10h] BYREF
  int pChunkLengths; // [esp+21Ch] [ebp-Ch] BYREF
  CCriticalSectionLock v13; // [esp+220h] [ebp-8h] BYREF

  while ( 1 )
  {
    while ( 1 )
    {
      handles[0] = CTCPPacket::GetUserData(this: &this->m_hExitThreadsEvent);
      handles[1] = CTCPPacket::GetUserData(this: &this->m_hSendCompletionEvent);
      UserData = CTCPPacket::GetUserData(this: &this->m_hReadyToSendEvent);
      v3 = !this->m_bWaitingForSendCompletion;
      handles[2] = UserData;
      v4 = 3;
      if ( !v3 )
        v4 = 2;
      v5 = WaitForMultipleObjects(nCount: v4, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0xBB8u);
      if ( v5 > 2 )
        break;
      if ( v5 == 2 )
      {
        if ( CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(this) == 0 )
          return 1;
      }
      else
      {
        if ( v5 == 0 )
          return 0;
        if ( CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(this) == 0 )
          return 1;
      }
    }
    if ( v5 != 258 )
      break;
    if ( g_bHandleTimeouts )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &v13, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &v13);
      m_ElementCount = this->m_SendDatas.m_ElementCount;
      CCriticalSectionLock::Unlock(this: &v13);
      if ( m_ElementCount == 0 )
      {
        pChunks = &g_KeepaliveSentinel;
        pChunkLengths = 4;
        CThreadedTCPSocket::InternalSend(
          this,
          (const void *const *)&pChunks,
          (char *)&pChunkLengths,
          nChunks: 1,
          bPrependLength: false);
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &v13);
    }
  }
  if ( v5 != -1 )
  {
    V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v5);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002C4D0
// Name: private: static unsigned long CThreadedTCPSocket::StaticSendThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticSendThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::SendThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x1002C4E0
// Name: public: virtual bool CThreadedTCPSocket::SendChunks(void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendChunks(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  if ( this->m_bErrorSignal )
    return 0;
  else
    return CThreadedTCPSocket::InternalSend(this, pChunks, pChunkLengths, nChunks, bPrependLength: true);
}

//------------------------------------------------------------------------------
// Address: 0x1002C510
// Name: private: bool CThreadedTCPSocket::Init(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::Init(
        CThreadedTCPSocket *this,
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  unsigned __int16 port; // dx
  unsigned int v6; // eax
  HANDLE v8; // eax
  void *m_hSendThread; // ecx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  unsigned int dwRecvThreadID; // [esp+Ch] [ebp-4h] BYREF

  port = remoteAddr.port;
  v6 = iSocket;
  *(_DWORD *)this->m_RemoteAddr.ip = *(_DWORD *)remoteAddr.ip;
  this->m_pHandler = pHandler;
  this->m_RemoteAddr.port = port;
  LOBYTE(port) = bDeleteHandler;
  this->m_Socket = v6;
  this->m_bDeleteHandler = port;
  iSocket = 1;
  setsockopt(s: v6, level: 6, optname: 1, optval: (const char *)&iSocket, optlen: 4);
  m_Socket = this->m_Socket;
  bDeleteHandler = 196609;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 128, optval: (const char *)&bDeleteHandler, optlen: 4);
  CEvent::Init(this: &this->m_hExitThreadsEvent, bManualReset: true, bInitialState: false);
  CEvent::Init(this: &this->m_hSendCompletionEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hReadyToSendEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hRecvEvent, bManualReset: false, bInitialState: false);
  this->m_SendOverlapped.hEvent = CTCPPacket::GetUserData(this: &this->m_hSendCompletionEvent);
  this->m_RecvOverlapped.hEvent = CTCPPacket::GetUserData(this: &this->m_hRecvEvent);
  this->m_hSendThread = CreateThread(
                          lpThreadAttributes: nullptr,
                          dwStackSize: 0,
                          lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticSendThreadFn,
                          lpParameter: this,
                          dwCreationFlags: 4u,
                          lpThreadId: (LPDWORD)&pHandler);
  v8 = CreateThread(
         lpThreadAttributes: nullptr,
         dwStackSize: 0,
         lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticRecvThreadFn,
         lpParameter: this,
         dwCreationFlags: 4u,
         lpThreadId: &dwRecvThreadID);
  m_hSendThread = this->m_hSendThread;
  this->m_hRecvThread = v8;
  if ( m_hSendThread == nullptr || v8 == nullptr )
    return 0;
  if ( g_bSetTCPSocketThreadPriorities )
  {
    SetThreadPriority(hThread: m_hSendThread, nPriority: -2);
    SetThreadPriority(hThread: this->m_hRecvThread, nPriority: -2);
  }
  this->m_pHandler->Init(this: this->m_pHandler, a2: this);
  ResumeThread(hThread: this->m_hSendThread);
  ResumeThread(hThread: this->m_hRecvThread);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002C670
// Name: public: static class IThreadedTCPSocket __near * CThreadedTCPSocket::Create(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__cdecl CThreadedTCPSocket::Create(
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  CThreadedTCPSocket *v4; // eax
  CThreadedTCPSocket *v5; // esi

  v4 = (CThreadedTCPSocket *)operator new(nSize: 0xF8u);
  if ( v4 != nullptr )
    v5 = CThreadedTCPSocket::CThreadedTCPSocket(this: v4);
  else
    v5 = nullptr;
  if ( CThreadedTCPSocket::Init(this: v5, iSocket, remoteAddr, pHandler, bDeleteHandler) != 0 )
    return v5;
  v5->Release(this: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002C6D0
// Name: public: virtual bool CTCPConnectSocket_Listener::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTCPConnectSocket_Listener::Update(
        CTCPConnectSocket_Listener *this,
        int pSocket,
        unsigned int milliseconds)
{
  CThreadedTCPSocket **v3; // ebx
  int v5; // eax
  SOCKET m_Socket; // edx
  SOCKET v7; // edi
  ITCPSocketHandler *v8; // eax
  CThreadedTCPSocket *v9; // eax
  fd_set readSet; // [esp+Ch] [ebp-124h] BYREF
  sockaddr_in addr; // [esp+110h] [ebp-20h] BYREF
  timeval timeVal; // [esp+120h] [ebp-10h] BYREF
  CIPAddr connectedAddr; // [esp+128h] [ebp-8h] BYREF

  v3 = (CThreadedTCPSocket **)pSocket;
  *(_DWORD *)pSocket = 0;
  if ( this->m_Socket == -1 )
    return 0;
  readSet.fd_array[0] = this->m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  timeVal.tv_usec = 1000 * milliseconds;
  v5 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v5 > 0 )
  {
    m_Socket = this->m_Socket;
    pSocket = 16;
    v7 = accept(s: m_Socket, (struct sockaddr *)&addr, addrlen: &pSocket);
    if ( v7 != -1 )
    {
      CIPAddr::CIPAddr(this: &connectedAddr);
      SockAddrToIPAddr(pIn: &addr, pOut: &connectedAddr);
      v8 = this->m_pHandler->CreateNewHandler(this: this->m_pHandler);
      v9 = CThreadedTCPSocket::Create(iSocket: v7, remoteAddr: connectedAddr, pHandler: v8, bDeleteHandler: 1);
      if ( v9 == nullptr )
      {
        closesocket(s: this->m_Socket);
        this->m_Socket = -1;
        return 0;
      }
      *v3 = v9;
    }
  }
  else if ( v5 == -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002C7F0
// Name: public: virtual bool CTCPConnectSocket_Connector::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::Update(
        CTCPConnectSocket_Connector *this,
        IThreadedTCPSocket **pSocket,
        unsigned int milliseconds)
{
  int v4; // eax
  SOCKET m_Socket; // edx
  ITCPSocketHandler *v7; // eax
  CThreadedTCPSocket *v8; // eax
  SOCKET v9; // [esp-4h] [ebp-114h]
  fd_set writeSet; // [esp+4h] [ebp-10Ch] BYREF
  timeval timeVal; // [esp+108h] [ebp-8h] BYREF

  *pSocket = nullptr;
  if ( this->m_bError )
    return false;
  if ( this->m_Socket == -1 )
    return true;
  if ( !this->m_bConnected )
  {
    writeSet.fd_array[0] = this->m_Socket;
    timeVal.tv_sec = 0;
    timeVal.tv_usec = 1000 * milliseconds;
    writeSet.fd_count = 1;
    v4 = select(nfds: 0, readfds: nullptr, writefds: &writeSet, exceptfds: nullptr, timeout: &timeVal);
    if ( v4 <= 0 )
    {
      if ( v4 == -1 )
        return CTCPConnectSocket_Connector::EnterErrorMode(this);
    }
    else
    {
      this->m_bConnected = true;
    }
    if ( !this->m_bConnected )
      return true;
  }
  m_Socket = this->m_Socket;
  milliseconds = 0;
  if ( ioctlsocket(s: m_Socket, cmd: -2147195266, argp: &milliseconds) != 0 )
  {
    v9 = this->m_Socket;
    this->m_bError = true;
    closesocket(s: v9);
    this->m_Socket = -1;
    return false;
  }
  v7 = this->m_pHandlerCreator->CreateNewHandler(this: this->m_pHandlerCreator);
  v8 = CThreadedTCPSocket::Create(
         iSocket: this->m_Socket,
         remoteAddr: this->m_RemoteAddr,
         pHandler: v7,
         bDeleteHandler: 1);
  if ( v8 != nullptr )
  {
    this->m_Socket = -1;
    *pSocket = v8;
    return true;
  }
  return CTCPConnectSocket_Connector::EnterErrorMode(this);
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10012AD0
// Name: TCPBind
// Source: json
//------------------------------------------------------------------------------
SOCKET __cdecl TCPBind(const CIPAddr *pAddr)
{
  SOCKET v1; // esi
  sockaddr_in addr; // [esp+4h] [ebp-10h] BYREF

  v1 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v1 != -1 )
  {
    IPAddrToSockAddr(pIn: pAddr, pOut: &addr);
    if ( bind(s: v1, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
      return v1;
    closesocket(s: v1);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10012B30
// Name: public: int CTCPPacket::GetUserData(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CTCPPacket::GetUserData(CEvent *this)
{
  return this->m_hEvent;
}

//------------------------------------------------------------------------------
// Address: 0x10012B40
// Name: public: void CTCPPacket::SetUserData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPPacket::SetUserData(CTCPPacket *this, int userData)
{
  this->m_UserData = userData;
}

//------------------------------------------------------------------------------
// Address: 0x10012B50
// Name: public: void CTCPPacket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPPacket::Release(CVMPIFile_Memory *this)
{
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x10012B60
// Name: private: void CThreadedTCPSocket::HandleError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, int errorCode, const char *pErrorString)
{
  this->m_pHandler->OnError(this: this->m_pHandler, a2: errorCode, a3: pErrorString);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  this->m_bErrorSignal = true;
}

//------------------------------------------------------------------------------
// Address: 0x10012BA0
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Connector::Create(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl CTCPConnectSocket_Connector::Create(
        const CIPAddr *connectAddr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  CIPAddr *v3; // eax
  CIPAddr *v4; // esi
  SOCKET v5; // edi
  int v6; // eax
  SOCKET v8; // [esp-Ch] [ebp-38h]
  sockaddr_in addr; // [esp+8h] [ebp-24h] BYREF
  sockaddr_in pOut; // [esp+18h] [ebp-14h] BYREF
  unsigned int val; // [esp+28h] [ebp-4h] BYREF

  v3 = (CIPAddr *)operator new(nSize: 0x18u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3->ip = &CTCPConnectSocket_Connector::`vftable';
    CIPAddr::CIPAddr(this: v3 + 2);
    *(_DWORD *)&v4[1].ip[2] = -1;
    v4->port = 0;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v5 == -1 )
    goto LABEL_7;
  IPAddrToSockAddr(pIn: localAddr, &pOut);
  if ( bind(s: v5, name: (const struct sockaddr *)&pOut, namelen: 16) != 0 )
  {
    closesocket(s: v5);
LABEL_7:
    v5 = -1;
  }
  *(_DWORD *)&v4[1].ip[2] = v5;
  if ( v5 != -1 )
  {
    IPAddrToSockAddr(pIn: connectAddr, pOut: &addr);
    val = 1;
    if ( ioctlsocket(s: *(_DWORD *)&v4[1].ip[2], cmd: -2147195266, argp: &val) == 0 )
    {
      v4[2] = *connectAddr;
      v8 = *(_DWORD *)&v4[1].ip[2];
      *(_DWORD *)&v4[3].ip[2] = pHandlerCreator;
      v6 = connect(s: v8, name: (const struct sockaddr *)&addr, namelen: 16);
      if ( v6 == 0 )
      {
        HIBYTE(v4->port) = 1;
        return v4;
      }
      if ( v6 == -1 && WSAGetLastError() == 10035 )
        return v4;
    }
  }
  (**(void (__thiscall ***)(CIPAddr *))v4->ip)(a1: v4);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10012CC0
// Name: public: bool CTCPConnectSocket_Connector::EnterErrorMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::EnterErrorMode(CTCPConnectSocket_Connector *this)
{
  SOCKET m_Socket; // [esp-4h] [ebp-8h]

  m_Socket = this->m_Socket;
  this->m_bError = true;
  closesocket(s: m_Socket);
  this->m_Socket = -1;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10012D20
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateConnector(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl ThreadedTCP_CreateConnector(
        const CIPAddr *addr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  return CTCPConnectSocket_Connector::Create(connectAddr: addr, localAddr, pHandlerCreator);
}

//------------------------------------------------------------------------------
// Address: 0x10012D30
// Name: void ThreadedTCP_EnableTimeouts(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadedTCP_EnableTimeouts(bool bEnable)
{
  g_bHandleTimeouts = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10012D40
// Name: void ThreadedTCP_SetTCPSocketThreadPriorities(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadedTCP_SetTCPSocketThreadPriorities(bool bSetTCPSocketThreadPriorities)
{
  g_bSetTCPSocketThreadPriorities = bSetTCPSocketThreadPriorities;
}

//------------------------------------------------------------------------------
// Address: 0x10012D50
// Name: private: void CThreadedTCPSocket::HandleError(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, unsigned int errorValue)
{
  DWORD LastError; // eax
  char *v4; // edx
  int i; // eax
  char v6; // cl
  char *v7; // [esp-4h] [ebp-10h]
  char *lpMsgBuf; // [esp+8h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  v4 = lpMsgBuf;
  for ( i = strlen(lpMsgBuf); i > 0; v4 = lpMsgBuf )
  {
    v6 = v4[i - 1];
    if ( v6 != 10 && v6 != 13 )
      break;
    v4[--i] = 0;
  }
  this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: v4);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  v7 = lpMsgBuf;
  this->m_bErrorSignal = true;
  LocalFree(hMem: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10012DE0
// Name: public: virtual void CTCPConnectSocket_Listener::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPConnectSocket_Listener::Release(CTCPConnectSocket_Listener *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CTCPConnectSocket_Listener *, int))this->dtr_CTCPConnectSocket_Listener)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10012E30
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Listener::Create(class IHandlerCreator __near *,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__cdecl CTCPConnectSocket_Listener::Create(
        IHandlerCreator *pHandlerCreator,
        unsigned __int16 port,
        int nQueueLength)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  SOCKET v5; // eax
  int v6; // ecx
  CIPAddr addr; // [esp+4h] [ebp-8h] BYREF

  v3 = operator new(nSize: 0xCu);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  *v3 = &CTCPConnectSocket_Listener::`vftable';
  v3[1] = -1;
  if ( nQueueLength < 0 )
    _Error(
      a1: "CTCPConnectSocket_Listener::Create - SOMAXCONN not allowed - causes some XP SP2 systems to stop receiving any netw"
      "ork data (systemwide).");
  CIPAddr::CIPAddr(this: &addr, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: port);
  v5 = TCPBind(pAddr: &addr);
  v4[1] = v5;
  if ( v5 == -1 )
    goto LABEL_10;
  v6 = 0x7FFFFFFF;
  if ( nQueueLength != -1 )
    v6 = nQueueLength;
  if ( listen(s: v5, backlog: v6) != 0 )
  {
LABEL_10:
    (*(void (__thiscall **)(_DWORD *))*v4)(a1: v4);
    return nullptr;
  }
  else
  {
    v4[2] = pHandlerCreator;
    return (ITCPConnectSocket *)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012ED0
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateListener(class IHandlerCreator __near *,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__cdecl ThreadedTCP_CreateListener(
        IHandlerCreator *pHandlerCreator,
        unsigned __int16 port,
        int nQueueLength)
{
  return CTCPConnectSocket_Listener::Create(pHandlerCreator, port, nQueueLength);
}

//------------------------------------------------------------------------------
// Address: 0x10012EE0
// Name: private: bool CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(CThreadedTCPSocket *this)
{
  CThreadedTCPSocket::SendData_t *m_Element; // eax
  int v3; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-38h]
  _WSABUF buf; // [esp+8h] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+18h] [ebp-4h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Element = this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element;
  buf.len = m_Element->m_Len;
  buf.buf = m_Element->m_Payload;
  this->m_nBytesToTransfer = m_Element->m_Len;
  this->m_bWaitingForSendCompletion = true;
  CCriticalSectionLock::Unlock(this: &csLock);
  m_Socket = this->m_Socket;
  dwNumBytesSent = 0;
  v3 = WSASend(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesSent: &dwNumBytesSent,
         dwFlags: 0,
         lpOverlapped: &this->m_SendOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012FA0
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalRecv(void __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalRecv(
        CThreadedTCPSocket *this,
        char *pDest,
        int destSize,
        unsigned int bContinuation,
        unsigned int bWaitingForSize)
{
  int v6; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-2Ch]
  _WSABUF buf; // [esp+8h] [ebp-8h] BYREF

  buf.len = destSize;
  buf.buf = pDest;
  if ( (_BYTE)bContinuation == 0 )
  {
    this->m_bWaitingForSize = bWaitingForSize;
    this->m_nBytesToReceive = destSize;
    this->m_nBytesReceivedSoFar = 0;
  }
  m_Socket = this->m_Socket;
  bContinuation = 0;
  bWaitingForSize = 0;
  v6 = WSARecv(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &bWaitingForSize,
         lpFlags: &bContinuation,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v6 == 0 || v6 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013170
// Name: private: bool CThreadedTCPSocket::RecvThread_WaitToReceiveSize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_WaitToReceiveSize(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  int v3; // edi
  unsigned int Error; // eax
  _WSABUF Buffers; // [esp+8h] [ebp-10h] BYREF
  unsigned int NumberOfBytesRecvd; // [esp+10h] [ebp-8h] BYREF
  unsigned int Flags; // [esp+14h] [ebp-4h] BYREF

  Buffers.len = 4;
  this->m_nBytesToReceive = 4;
  m_Socket = this->m_Socket;
  Buffers.buf = (char *)&this->m_NextPacketLen;
  this->m_bWaitingForSize = true;
  this->m_nBytesReceivedSoFar = 0;
  Flags = 0;
  NumberOfBytesRecvd = 0;
  v3 = WSARecv(
         s: m_Socket,
         lpBuffers: &Buffers,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &NumberOfBytesRecvd,
         lpFlags: &Flags,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013210
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(
        CThreadedTCPSocket *this,
        signed int dwTransfer)
{
  int m_nBytesToReceive; // eax
  int m_nBytesReceivedSoFar; // edi
  bool v6; // zf
  char *p_m_NextPacketLen; // edx
  int m_NextPacketLen; // eax
  CTCPPacket *v9; // eax
  char pDest[512]; // [esp+8h] [ebp-400h] BYREF
  char str[512]; // [esp+208h] [ebp-200h] BYREF

  m_nBytesToReceive = this->m_nBytesToReceive;
  m_nBytesReceivedSoFar = this->m_nBytesReceivedSoFar;
  if ( dwTransfer > m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    V_snprintf(
      pDest: str,
      maxLen: 0x200u,
      pFormat: "Invalid # bytes received (%d) in recv thread (should be %d)",
      dwTransfer,
      m_nBytesToReceive);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  if ( dwTransfer < m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    v6 = !this->m_bWaitingForSize;
    this->m_nBytesReceivedSoFar = m_nBytesReceivedSoFar + dwTransfer;
    p_m_NextPacketLen = (char *)&this->m_NextPacketLen;
    if ( v6 )
      p_m_NextPacketLen = this->m_pRecvBuffer->m_Data;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: &p_m_NextPacketLen[m_nBytesReceivedSoFar + dwTransfer],
             destSize: m_nBytesToReceive - (m_nBytesReceivedSoFar + dwTransfer),
             bContinuation: 1u,
             bWaitingForSize: 0);
  }
  if ( !this->m_bWaitingForSize )
  {
    this->m_pHandler->OnPacketReceived(this: this->m_pHandler, a2: this->m_pRecvBuffer);
    this->m_pRecvBuffer = nullptr;
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  }
  m_NextPacketLen = this->m_NextPacketLen;
  if ( m_NextPacketLen == -12345 )
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  if ( m_NextPacketLen < 1 || m_NextPacketLen > 78643200 )
  {
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "Invalid packet size in RecvThread (size = %d)", this->m_NextPacketLen);
    CThreadedTCPSocket::HandleError(this, errorCode: 0, pErrorString: pDest);
    return 0;
  }
  else
  {
    v9 = (CTCPPacket *)operator new(nSize: m_NextPacketLen + 11);
    this->m_pRecvBuffer = v9;
    v9->m_UserData = 0;
    this->m_pRecvBuffer->m_Len = this->m_NextPacketLen;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: this->m_pRecvBuffer->m_Data,
             destSize: this->m_pRecvBuffer->m_Len,
             bContinuation: 0,
             bWaitingForSize: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013390
// Name: private: unsigned long CThreadedTCPSocket::RecvThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::RecvThreadFn(CThreadedTCPSocket *this)
{
  DWORD v3; // eax
  bool i; // zf
  unsigned int Error; // eax
  DWORD LastError; // eax
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int dwFlags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  void *handles[2]; // [esp+20Ch] [ebp-8h] BYREF

  if ( CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this) == 0 )
    return 1;
  handles[0] = CTCPPacket::GetUserData(this: &this->m_hExitThreadsEvent);
  handles[1] = CTCPPacket::GetUserData(this: &this->m_hRecvEvent);
  v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  for ( i = v3 == 258; v3 <= 0x102; i = v3 == 258 )
  {
    if ( i )
    {
      if ( g_bHandleTimeouts )
      {
        this->m_pHandler->OnError(this: this->m_pHandler, a2: 1, a3: "Connection timed out");
LABEL_17:
        CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
        this->m_bErrorSignal = true;
        return 1;
      }
    }
    else
    {
      if ( v3 == 0 )
        return 0;
      if ( v3 != 1 )
        goto LABEL_13;
      if ( !WSAGetOverlappedResult(
              s: this->m_Socket,
              lpOverlapped: &this->m_RecvOverlapped,
              lpcbTransfer: &cbTransfer,
              fWait: true,
              lpdwFlags: &dwFlags) )
      {
        Error = WSAGetLastError();
        CThreadedTCPSocket::HandleError(this, errorValue: Error);
        return 1;
      }
      if ( CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(this, dwTransfer: cbTransfer) == 0 )
        return 1;
    }
    v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  }
  if ( v3 != -1 )
  {
LABEL_13:
    V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v3);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    goto LABEL_17;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013500
// Name: private: static unsigned long CThreadedTCPSocket::StaticRecvThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticRecvThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::RecvThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x10013510
// Name: private: CThreadedTCPSocket::CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__thiscall CThreadedTCPSocket::CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // eax

  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hReadyToSendEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hSendCompletionEvent);
  CCriticalSection::CCriticalSection(this: &this->m_SendCS);
  this->m_SendDatas.m_Memory.m_pMemory = nullptr;
  this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  this->m_SendDatas.m_Memory.m_nGrowSize = 0;
  this->m_SendDatas.m_LastAlloc.index = -1;
  m_pMemory = this->m_SendDatas.m_Memory.m_pMemory;
  this->m_SendDatas.m_Head = -1;
  this->m_SendDatas.m_Tail = -1;
  this->m_SendDatas.m_FirstFree = -1;
  this->m_SendDatas.m_ElementCount = 0;
  this->m_SendDatas.m_NumAlloced = 0;
  this->m_SendDatas.m_pElements = m_pMemory;
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hRecvEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hExitThreadsEvent);
  CIPAddr::CIPAddr(this: &this->m_RemoteAddr);
  this->m_Socket = -1;
  this->m_pHandler = nullptr;
  *(_QWORD *)&this->m_SendOverlapped.Internal = 0;
  *(_QWORD *)&this->m_SendOverlapped.Offset = 0;
  this->m_SendOverlapped.hEvent = nullptr;
  *(_QWORD *)&this->m_RecvOverlapped.Internal = 0;
  *(_QWORD *)&this->m_RecvOverlapped.Offset = 0;
  this->m_RecvOverlapped.hEvent = nullptr;
  this->m_nBytesToReceive = -1;
  this->m_bWaitingForSendCompletion = false;
  this->m_bWaitingForSize = false;
  this->m_bErrorSignal = false;
  this->m_pRecvBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013600
// Name: public: virtual void CThreadedTCPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Release(CThreadedTCPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CThreadedTCPSocket *, int))this->dtr_CThreadedTCPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10013610
// Name: public: virtual class CIPAddr CThreadedTCPSocket::GetRemoteAddr(void)const
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CThreadedTCPSocket::GetRemoteAddr(CThreadedTCPSocket *this, CIPAddr *result)
{
  int v2; // edx
  unsigned __int16 port; // cx

  v2 = *(_DWORD *)this->m_RemoteAddr.ip;
  port = this->m_RemoteAddr.port;
  *(_DWORD *)result->ip = v2;
  result->port = port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013630
// Name: public: virtual bool CThreadedTCPSocket::Send(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::Send(CThreadedTCPSocket *this, const void *pData, int len)
{
  return this->SendChunks(this, a2: &pData, a3: &len, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10013650
// Name: public: virtual class ITCPSocketHandler __near * CThreadedTCPSocket::GetHandler(void)
// Source: json
//------------------------------------------------------------------------------
ITCPSocketHandler *__thiscall CThreadedTCPSocket::GetHandler(CThreadedTCPSocket *this)
{
  return this->m_pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x10013660
// Name: private: void CThreadedTCPSocket::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Term(CThreadedTCPSocket *this)
{
  void *m_hSendThread; // eax
  void *m_hRecvThread; // eax
  ITCPSocketHandler *m_pHandler; // ecx

  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  m_hSendThread = this->m_hSendThread;
  if ( m_hSendThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hSendThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hSendThread);
    this->m_hSendThread = nullptr;
  }
  m_hRecvThread = this->m_hRecvThread;
  if ( m_hRecvThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hRecvThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hRecvThread);
    this->m_hRecvThread = nullptr;
  }
  CEvent::ResetEvent(this: &this->m_hExitThreadsEvent);
  if ( this->m_Socket != -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  if ( this->m_bDeleteHandler )
  {
    m_pHandler = this->m_pHandler;
    if ( m_pHandler != nullptr )
    {
      m_pHandler->Release(this: m_pHandler, a2: false);
      this->m_pHandler = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013710
// Name: public: virtual bool CThreadedTCPSocket::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::IsValid(CThreadedTCPSocket *this)
{
  return !this->m_bErrorSignal;
}

//------------------------------------------------------------------------------
// Address: 0x10013720
// Name: private: virtual CThreadedTCPSocket::~CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::~CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CThreadedTCPSocket::Term(this);
  CEvent::~CEvent(this: &this->m_hExitThreadsEvent);
  CEvent::~CEvent(this: &this->m_hRecvEvent);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_SendDatas);
  if ( this->m_SendDatas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SendDatas.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendDatas.m_Memory.m_pMemory);
      this->m_SendDatas.m_Memory.m_pMemory = nullptr;
    }
    this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  }
  CCriticalSection::~CCriticalSection(this: &this->m_SendCS);
  CEvent::~CEvent(this: &this->m_hSendCompletionEvent);
  CEvent::~CEvent(this: &this->m_hReadyToSendEvent);
}

//------------------------------------------------------------------------------
// Address: 0x100137E0
// Name: private: bool CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  unsigned int Error; // eax
  int m_Head; // ebx
  bool v6; // cc
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int flags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  CCriticalSectionLock csLock; // [esp+20Ch] [ebp-8h] BYREF

  m_Socket = this->m_Socket;
  this->m_bWaitingForSendCompletion = false;
  if ( WSAGetOverlappedResult(
         s: m_Socket,
         lpOverlapped: &this->m_SendOverlapped,
         lpcbTransfer: &cbTransfer,
         fWait: true,
         lpdwFlags: &flags) )
  {
    if ( cbTransfer == this->m_nBytesToTransfer )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &csLock);
      free(pMem: this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element);
      m_Head = this->m_SendDatas.m_Head;
      CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_SendDatas,
        elem: m_Head);
      this->m_SendDatas.m_Memory.m_pMemory[m_Head].m_Next = this->m_SendDatas.m_FirstFree;
      this->m_SendDatas.m_FirstFree = m_Head;
      v6 = this->m_SendDatas.m_ElementCount <= 0;
      this->m_bWaitingForSendCompletion = false;
      if ( !v6 )
        CEvent::SetEvent(this: &this->m_hReadyToSendEvent);
      CCriticalSectionLock::Unlock(this: &csLock);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    }
    else
    {
      V_snprintf(
        pDest: str,
        maxLen: 0x200u,
        pFormat: "Invalid # bytes transferred (%d) in send thread (should be %d)",
        cbTransfer,
        this->m_nBytesToTransfer);
      this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
      CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
      this->m_bErrorSignal = true;
      return 0;
    }
  }
  else
  {
    Error = WSAGetLastError();
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013910
// Name: private: bool CThreadedTCPSocket::InternalSend(void const __near * const __near *,int const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::InternalSend(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks,
        bool bPrependLength)
{
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // esi
  int v10; // eax
  int v11; // esi
  int *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  unsigned int *v15; // esi
  int v16; // ebx
  CThreadedTCPSocket *v17; // ebx
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int> > *p_m_SendDatas; // esi
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // edx
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // ecx
  int v24; // edx
  int m_Tail; // edi
  CThreadedTCPSocket::SendData_t **p_m_Element; // esi
  CCriticalSectionLock csLock; // [esp+Ch] [ebp-Ch] BYREF
  CThreadedTCPSocket *v29; // [esp+14h] [ebp-4h]
  CThreadedTCPSocket::SendData_t *pSendData; // [esp+24h] [ebp+Ch]
  int bPrependLengtha; // [esp+2Ch] [ebp+14h]

  v6 = nChunks;
  v29 = this;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( nChunks >= 2 )
  {
    do
    {
      v7 += *(_DWORD *)&pChunkLengths[4 * v10];
      v8 += *(_DWORD *)&pChunkLengths[4 * v10 + 4];
      v10 += 2;
    }
    while ( v10 < nChunks - 1 );
    v6 = nChunks;
  }
  if ( v10 < v6 )
    v9 = *(_DWORD *)&pChunkLengths[4 * v10];
  v11 = v8 + v7 + v9;
  if ( bPrependLength )
  {
    if ( v11 == 0 )
      return 1;
    v11 += 4;
  }
  v12 = (int *)operator new(nSize: v11 + 7);
  pSendData = (CThreadedTCPSocket::SendData_t *)v12;
  *v12 = v11;
  v13 = (unsigned __int8 *)(v12 + 1);
  if ( bPrependLength )
  {
    *(_DWORD *)v13 = v11 - 4;
    v13 = (unsigned __int8 *)(v12 + 2);
  }
  if ( nChunks > 0 )
  {
    v14 = (char *)pChunks - pChunkLengths;
    v15 = (unsigned int *)pChunkLengths;
    bPrependLengtha = (char *)pChunks - pChunkLengths;
    v16 = nChunks;
    while ( 1 )
    {
      memcpy(dst: v13, src: *(unsigned __int8 **)((char *)v15 + v14), count: *v15);
      v13 += *v15++;
      if ( --v16 == 0 )
        break;
      v14 = bPrependLengtha;
    }
  }
  v17 = v29;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &v29->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  p_m_SendDatas = &v17->m_SendDatas;
  v19 = CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal(
          this: &v17->m_SendDatas,
          multilist: false);
  if ( v19 != -1 )
  {
    if ( v19 >= 0 && v19 < v17->m_SendDatas.m_Memory.m_nAllocationCount && v19 <= v17->m_SendDatas.m_LastAlloc.index )
    {
      v20 = (int)&p_m_SendDatas->m_Memory.m_pMemory[v19];
      if ( *(_DWORD *)(v20 + 4) != v19 )
      {
        v21 = *(_DWORD *)(v20 + 4);
        if ( v21 == -1 )
          v17->m_SendDatas.m_Head = *(_DWORD *)(v20 + 8);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v21].m_Next = *(_DWORD *)(v20 + 8);
        v22 = *(_DWORD *)(v20 + 8);
        if ( v22 == -1 )
          v17->m_SendDatas.m_Tail = *(_DWORD *)(v20 + 4);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v22].m_Previous = *(_DWORD *)(v20 + 4);
        v17 = v29;
        *(_DWORD *)(v20 + 8) = v19;
        *(_DWORD *)(v20 + 4) = v19;
        --p_m_SendDatas->m_ElementCount;
      }
    }
    m_pMemory = p_m_SendDatas->m_Memory.m_pMemory;
    v24 = v19;
    m_pMemory[v24].m_Next = -1;
    m_Tail = p_m_SendDatas->m_Tail;
    m_pMemory[v24].m_Previous = m_Tail;
    p_m_SendDatas->m_Tail = v19;
    if ( m_Tail == -1 )
      p_m_SendDatas->m_Head = v19;
    else
      p_m_SendDatas->m_Memory.m_pMemory[m_Tail].m_Next = v19;
    ++p_m_SendDatas->m_ElementCount;
    p_m_Element = &p_m_SendDatas->m_Memory.m_pMemory[v24].m_Element;
    if ( p_m_Element != nullptr )
      *p_m_Element = pSendData;
  }
  CEvent::SetEvent(this: &v17->m_hReadyToSendEvent);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013AA0
// Name: private: unsigned long CThreadedTCPSocket::SendThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::SendThreadFn(CThreadedTCPSocket *this)
{
  void *UserData; // eax
  bool v3; // zf
  DWORD v4; // eax
  DWORD v5; // eax
  int m_ElementCount; // edi
  DWORD LastError; // eax
  char str[512]; // [esp+Ch] [ebp-21Ch] BYREF
  void *handles[3]; // [esp+20Ch] [ebp-1Ch] BYREF
  void *pChunks; // [esp+218h] [ebp-10h] BYREF
  int pChunkLengths; // [esp+21Ch] [ebp-Ch] BYREF
  CCriticalSectionLock v13; // [esp+220h] [ebp-8h] BYREF

  while ( 1 )
  {
    while ( 1 )
    {
      handles[0] = CTCPPacket::GetUserData(this: &this->m_hExitThreadsEvent);
      handles[1] = CTCPPacket::GetUserData(this: &this->m_hSendCompletionEvent);
      UserData = CTCPPacket::GetUserData(this: &this->m_hReadyToSendEvent);
      v3 = !this->m_bWaitingForSendCompletion;
      handles[2] = UserData;
      v4 = 3;
      if ( !v3 )
        v4 = 2;
      v5 = WaitForMultipleObjects(nCount: v4, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0xBB8u);
      if ( v5 > 2 )
        break;
      if ( v5 == 2 )
      {
        if ( CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(this) == 0 )
          return 1;
      }
      else
      {
        if ( v5 == 0 )
          return 0;
        if ( CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(this) == 0 )
          return 1;
      }
    }
    if ( v5 != 258 )
      break;
    if ( g_bHandleTimeouts )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &v13, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &v13);
      m_ElementCount = this->m_SendDatas.m_ElementCount;
      CCriticalSectionLock::Unlock(this: &v13);
      if ( m_ElementCount == 0 )
      {
        pChunks = &g_KeepaliveSentinel;
        pChunkLengths = 4;
        CThreadedTCPSocket::InternalSend(
          this,
          (const void *const *)&pChunks,
          (char *)&pChunkLengths,
          nChunks: 1,
          bPrependLength: false);
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &v13);
    }
  }
  if ( v5 != -1 )
  {
    V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v5);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013C20
// Name: private: static unsigned long CThreadedTCPSocket::StaticSendThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticSendThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::SendThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x10013C30
// Name: public: virtual bool CThreadedTCPSocket::SendChunks(void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendChunks(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  if ( this->m_bErrorSignal )
    return 0;
  else
    return CThreadedTCPSocket::InternalSend(this, pChunks, pChunkLengths, nChunks, bPrependLength: true);
}

//------------------------------------------------------------------------------
// Address: 0x10013C60
// Name: private: bool CThreadedTCPSocket::Init(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::Init(
        CThreadedTCPSocket *this,
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  unsigned __int16 port; // dx
  unsigned int v6; // eax
  HANDLE v8; // eax
  void *m_hSendThread; // ecx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  unsigned int dwRecvThreadID; // [esp+Ch] [ebp-4h] BYREF

  port = remoteAddr.port;
  v6 = iSocket;
  *(_DWORD *)this->m_RemoteAddr.ip = *(_DWORD *)remoteAddr.ip;
  this->m_pHandler = pHandler;
  this->m_RemoteAddr.port = port;
  LOBYTE(port) = bDeleteHandler;
  this->m_Socket = v6;
  this->m_bDeleteHandler = port;
  iSocket = 1;
  setsockopt(s: v6, level: 6, optname: 1, optval: (const char *)&iSocket, optlen: 4);
  m_Socket = this->m_Socket;
  bDeleteHandler = 196609;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 128, optval: (const char *)&bDeleteHandler, optlen: 4);
  CEvent::Init(this: &this->m_hExitThreadsEvent, bManualReset: true, bInitialState: false);
  CEvent::Init(this: &this->m_hSendCompletionEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hReadyToSendEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hRecvEvent, bManualReset: false, bInitialState: false);
  this->m_SendOverlapped.hEvent = CTCPPacket::GetUserData(this: &this->m_hSendCompletionEvent);
  this->m_RecvOverlapped.hEvent = CTCPPacket::GetUserData(this: &this->m_hRecvEvent);
  this->m_hSendThread = CreateThread(
                          lpThreadAttributes: nullptr,
                          dwStackSize: 0,
                          lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticSendThreadFn,
                          lpParameter: this,
                          dwCreationFlags: 4u,
                          lpThreadId: (LPDWORD)&pHandler);
  v8 = CreateThread(
         lpThreadAttributes: nullptr,
         dwStackSize: 0,
         lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticRecvThreadFn,
         lpParameter: this,
         dwCreationFlags: 4u,
         lpThreadId: &dwRecvThreadID);
  m_hSendThread = this->m_hSendThread;
  this->m_hRecvThread = v8;
  if ( m_hSendThread == nullptr || v8 == nullptr )
    return 0;
  if ( g_bSetTCPSocketThreadPriorities )
  {
    SetThreadPriority(hThread: m_hSendThread, nPriority: -2);
    SetThreadPriority(hThread: this->m_hRecvThread, nPriority: -2);
  }
  this->m_pHandler->Init(this: this->m_pHandler, a2: this);
  ResumeThread(hThread: this->m_hSendThread);
  ResumeThread(hThread: this->m_hRecvThread);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013DC0
// Name: public: static class IThreadedTCPSocket __near * CThreadedTCPSocket::Create(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__cdecl CThreadedTCPSocket::Create(
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  CThreadedTCPSocket *v4; // eax
  CThreadedTCPSocket *v5; // esi

  v4 = (CThreadedTCPSocket *)operator new(nSize: 0xF8u);
  if ( v4 != nullptr )
    v5 = CThreadedTCPSocket::CThreadedTCPSocket(this: v4);
  else
    v5 = nullptr;
  if ( CThreadedTCPSocket::Init(this: v5, iSocket, remoteAddr, pHandler, bDeleteHandler) != 0 )
    return v5;
  v5->Release(this: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10013E20
// Name: public: virtual bool CTCPConnectSocket_Listener::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTCPConnectSocket_Listener::Update(
        CTCPConnectSocket_Listener *this,
        int pSocket,
        unsigned int milliseconds)
{
  CThreadedTCPSocket **v3; // ebx
  int v5; // eax
  SOCKET m_Socket; // edx
  SOCKET v7; // edi
  ITCPSocketHandler *v8; // eax
  CThreadedTCPSocket *v9; // eax
  fd_set readSet; // [esp+Ch] [ebp-124h] BYREF
  sockaddr_in addr; // [esp+110h] [ebp-20h] BYREF
  timeval timeVal; // [esp+120h] [ebp-10h] BYREF
  CIPAddr connectedAddr; // [esp+128h] [ebp-8h] BYREF

  v3 = (CThreadedTCPSocket **)pSocket;
  *(_DWORD *)pSocket = 0;
  if ( this->m_Socket == -1 )
    return 0;
  readSet.fd_array[0] = this->m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  timeVal.tv_usec = 1000 * milliseconds;
  v5 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v5 > 0 )
  {
    m_Socket = this->m_Socket;
    pSocket = 16;
    v7 = accept(s: m_Socket, (struct sockaddr *)&addr, addrlen: &pSocket);
    if ( v7 != -1 )
    {
      CIPAddr::CIPAddr(this: &connectedAddr);
      SockAddrToIPAddr(pIn: &addr, pOut: &connectedAddr);
      v8 = this->m_pHandler->CreateNewHandler(this: this->m_pHandler);
      v9 = CThreadedTCPSocket::Create(iSocket: v7, remoteAddr: connectedAddr, pHandler: v8, bDeleteHandler: 1);
      if ( v9 == nullptr )
      {
        closesocket(s: this->m_Socket);
        this->m_Socket = -1;
        return 0;
      }
      *v3 = v9;
    }
  }
  else if ( v5 == -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013F40
// Name: public: virtual bool CTCPConnectSocket_Connector::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::Update(
        CTCPConnectSocket_Connector *this,
        IThreadedTCPSocket **pSocket,
        unsigned int milliseconds)
{
  int v4; // eax
  SOCKET m_Socket; // edx
  ITCPSocketHandler *v7; // eax
  CThreadedTCPSocket *v8; // eax
  SOCKET v9; // [esp-4h] [ebp-114h]
  fd_set writeSet; // [esp+4h] [ebp-10Ch] BYREF
  timeval timeVal; // [esp+108h] [ebp-8h] BYREF

  *pSocket = nullptr;
  if ( this->m_bError )
    return false;
  if ( this->m_Socket == -1 )
    return true;
  if ( !this->m_bConnected )
  {
    writeSet.fd_array[0] = this->m_Socket;
    timeVal.tv_sec = 0;
    timeVal.tv_usec = 1000 * milliseconds;
    writeSet.fd_count = 1;
    v4 = select(nfds: 0, readfds: nullptr, writefds: &writeSet, exceptfds: nullptr, timeout: &timeVal);
    if ( v4 <= 0 )
    {
      if ( v4 == -1 )
        return CTCPConnectSocket_Connector::EnterErrorMode(this);
    }
    else
    {
      this->m_bConnected = true;
    }
    if ( !this->m_bConnected )
      return true;
  }
  m_Socket = this->m_Socket;
  milliseconds = 0;
  if ( ioctlsocket(s: m_Socket, cmd: -2147195266, argp: &milliseconds) != 0 )
  {
    v9 = this->m_Socket;
    this->m_bError = true;
    closesocket(s: v9);
    this->m_Socket = -1;
    return false;
  }
  v7 = this->m_pHandlerCreator->CreateNewHandler(this: this->m_pHandlerCreator);
  v8 = CThreadedTCPSocket::Create(
         iSocket: this->m_Socket,
         remoteAddr: this->m_RemoteAddr,
         pHandler: v7,
         bDeleteHandler: 1);
  if ( v8 != nullptr )
  {
    this->m_Socket = -1;
    *pSocket = v8;
    return true;
  }
  return CTCPConnectSocket_Connector::EnterErrorMode(this);
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vmpi_service (Missing functions)
// ============================================================
namespace vmpi_service {

//------------------------------------------------------------------------------
// Address: 0x00403A30
// Name: TCPBind
// Source: json
//------------------------------------------------------------------------------
SOCKET __cdecl TCPBind(const CIPAddr *pAddr)
{
  SOCKET v1; // esi
  sockaddr_in addr; // [esp+4h] [ebp-10h] BYREF

  v1 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v1 != -1 )
  {
    IPAddrToSockAddr(pIn: pAddr, pOut: &addr);
    if ( bind(s: v1, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
      return v1;
    closesocket(s: v1);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00403A90
// Name: public: void CTCPPacket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPPacket::Release(CTCPPacket *this)
{
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x00403AA0
// Name: private: void CThreadedTCPSocket::HandleError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, int errorCode, const char *pErrorString)
{
  this->m_pHandler->OnError(this: this->m_pHandler, a2: errorCode, a3: pErrorString);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  this->m_bErrorSignal = true;
}

//------------------------------------------------------------------------------
// Address: 0x00403AE0
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Connector::Create(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl CTCPConnectSocket_Connector::Create(
        const CIPAddr *connectAddr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  CIPAddr *v3; // eax
  CIPAddr *v4; // esi
  SOCKET v5; // edi
  int v6; // eax
  SOCKET v8; // [esp-Ch] [ebp-38h]
  sockaddr_in addr; // [esp+8h] [ebp-24h] BYREF
  sockaddr_in pOut; // [esp+18h] [ebp-14h] BYREF
  unsigned int val; // [esp+28h] [ebp-4h] BYREF

  v3 = (CIPAddr *)operator new(nSize: 0x18u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3->ip = &CTCPConnectSocket_Connector::`vftable';
    CIPAddr::CIPAddr(this: v3 + 2);
    *(_DWORD *)&v4[1].ip[2] = -1;
    v4->port = 0;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v5 == -1 )
    goto LABEL_7;
  IPAddrToSockAddr(pIn: localAddr, &pOut);
  if ( bind(s: v5, name: (const struct sockaddr *)&pOut, namelen: 16) != 0 )
  {
    closesocket(s: v5);
LABEL_7:
    v5 = -1;
  }
  *(_DWORD *)&v4[1].ip[2] = v5;
  if ( v5 != -1 )
  {
    IPAddrToSockAddr(pIn: connectAddr, pOut: &addr);
    val = 1;
    if ( ioctlsocket(s: *(_DWORD *)&v4[1].ip[2], cmd: -2147195266, argp: &val) == 0 )
    {
      v4[2] = *connectAddr;
      v8 = *(_DWORD *)&v4[1].ip[2];
      *(_DWORD *)&v4[3].ip[2] = pHandlerCreator;
      v6 = connect(s: v8, name: (const struct sockaddr *)&addr, namelen: 16);
      if ( v6 == 0 )
      {
        HIBYTE(v4->port) = 1;
        return v4;
      }
      if ( v6 == -1 && WSAGetLastError() == 10035 )
        return v4;
    }
  }
  (**(void (__thiscall ***)(CIPAddr *))v4->ip)(a1: v4);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403C00
// Name: public: bool CTCPConnectSocket_Connector::EnterErrorMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::EnterErrorMode(CTCPConnectSocket_Connector *this)
{
  SOCKET m_Socket; // [esp-4h] [ebp-8h]

  m_Socket = this->m_Socket;
  this->m_bError = true;
  closesocket(s: m_Socket);
  this->m_Socket = -1;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00403C60
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateConnector(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl ThreadedTCP_CreateConnector(
        const CIPAddr *addr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  return CTCPConnectSocket_Connector::Create(connectAddr: addr, localAddr, pHandlerCreator);
}

//------------------------------------------------------------------------------
// Address: 0x00403C70
// Name: private: void CThreadedTCPSocket::HandleError(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, unsigned int errorValue)
{
  DWORD LastError; // eax
  char *v4; // edx
  int i; // eax
  char v6; // cl
  char *v7; // [esp-4h] [ebp-10h]
  char *lpMsgBuf; // [esp+8h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  v4 = lpMsgBuf;
  for ( i = strlen(lpMsgBuf); i > 0; v4 = lpMsgBuf )
  {
    v6 = v4[i - 1];
    if ( v6 != 10 && v6 != 13 )
      break;
    v4[--i] = 0;
  }
  this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: v4);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  v7 = lpMsgBuf;
  this->m_bErrorSignal = true;
  LocalFree(hMem: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00403D40
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Listener::Create(class IHandlerCreator __near *,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__cdecl CTCPConnectSocket_Listener::Create(
        IHandlerCreator *pHandlerCreator,
        unsigned __int16 port,
        int nQueueLength)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  SOCKET v5; // eax
  int v6; // ecx
  CIPAddr addr; // [esp+4h] [ebp-8h] BYREF

  v3 = operator new(nSize: 0xCu);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  *v3 = &CTCPConnectSocket_Listener::`vftable';
  v3[1] = -1;
  if ( nQueueLength < 0 )
    _Error(
      a1: "CTCPConnectSocket_Listener::Create - SOMAXCONN not allowed - causes some XP SP2 systems to stop receiving any netw"
      "ork data (systemwide).");
  CIPAddr::CIPAddr(this: &addr, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: port);
  v5 = TCPBind(pAddr: &addr);
  v4[1] = v5;
  if ( v5 == -1 )
    goto LABEL_10;
  v6 = 0x7FFFFFFF;
  if ( nQueueLength != -1 )
    v6 = nQueueLength;
  if ( listen(s: v5, backlog: v6) != 0 )
  {
LABEL_10:
    (*(void (__thiscall **)(_DWORD *))*v4)(a1: v4);
    return nullptr;
  }
  else
  {
    v4[2] = pHandlerCreator;
    return (ITCPConnectSocket *)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403DE0
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateListener(class IHandlerCreator __near *,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__cdecl ThreadedTCP_CreateListener(
        IHandlerCreator *pHandlerCreator,
        unsigned __int16 port,
        int nQueueLength)
{
  return CTCPConnectSocket_Listener::Create(pHandlerCreator, port, nQueueLength);
}

//------------------------------------------------------------------------------
// Address: 0x00403DF0
// Name: private: bool CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(CThreadedTCPSocket *this)
{
  CThreadedTCPSocket::SendData_t *m_Element; // eax
  int v3; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-38h]
  _WSABUF buf; // [esp+8h] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+18h] [ebp-4h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Element = this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element;
  buf.len = m_Element->m_Len;
  buf.buf = m_Element->m_Payload;
  this->m_nBytesToTransfer = m_Element->m_Len;
  this->m_bWaitingForSendCompletion = true;
  CCriticalSectionLock::Unlock(this: &csLock);
  m_Socket = this->m_Socket;
  dwNumBytesSent = 0;
  v3 = WSASend(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesSent: &dwNumBytesSent,
         dwFlags: 0,
         lpOverlapped: &this->m_SendOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403EB0
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalRecv(void __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalRecv(
        CThreadedTCPSocket *this,
        char *pDest,
        int destSize,
        unsigned int bContinuation,
        unsigned int bWaitingForSize)
{
  int v6; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-2Ch]
  _WSABUF buf; // [esp+8h] [ebp-8h] BYREF

  buf.len = destSize;
  buf.buf = pDest;
  if ( (_BYTE)bContinuation == 0 )
  {
    this->m_bWaitingForSize = bWaitingForSize;
    this->m_nBytesToReceive = destSize;
    this->m_nBytesReceivedSoFar = 0;
  }
  m_Socket = this->m_Socket;
  bContinuation = 0;
  bWaitingForSize = 0;
  v6 = WSARecv(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &bWaitingForSize,
         lpFlags: &bContinuation,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v6 == 0 || v6 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404080
// Name: private: bool CThreadedTCPSocket::RecvThread_WaitToReceiveSize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_WaitToReceiveSize(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  int v3; // edi
  unsigned int Error; // eax
  _WSABUF Buffers; // [esp+8h] [ebp-10h] BYREF
  unsigned int NumberOfBytesRecvd; // [esp+10h] [ebp-8h] BYREF
  unsigned int Flags; // [esp+14h] [ebp-4h] BYREF

  Buffers.len = 4;
  this->m_nBytesToReceive = 4;
  m_Socket = this->m_Socket;
  Buffers.buf = (char *)&this->m_NextPacketLen;
  this->m_bWaitingForSize = true;
  this->m_nBytesReceivedSoFar = 0;
  Flags = 0;
  NumberOfBytesRecvd = 0;
  v3 = WSARecv(
         s: m_Socket,
         lpBuffers: &Buffers,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &NumberOfBytesRecvd,
         lpFlags: &Flags,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404120
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(
        CThreadedTCPSocket *this,
        signed int dwTransfer)
{
  int m_nBytesToReceive; // eax
  int m_nBytesReceivedSoFar; // edi
  bool v6; // zf
  char *p_m_NextPacketLen; // edx
  int m_NextPacketLen; // eax
  CTCPPacket *v9; // eax
  char pDest[512]; // [esp+8h] [ebp-400h] BYREF
  char str[512]; // [esp+208h] [ebp-200h] BYREF

  m_nBytesToReceive = this->m_nBytesToReceive;
  m_nBytesReceivedSoFar = this->m_nBytesReceivedSoFar;
  if ( dwTransfer > m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    V_snprintf(
      pDest: str,
      maxLen: 512,
      pFormat: "Invalid # bytes received (%d) in recv thread (should be %d)",
      dwTransfer,
      m_nBytesToReceive);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  if ( dwTransfer < m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    v6 = !this->m_bWaitingForSize;
    this->m_nBytesReceivedSoFar = m_nBytesReceivedSoFar + dwTransfer;
    p_m_NextPacketLen = (char *)&this->m_NextPacketLen;
    if ( v6 )
      p_m_NextPacketLen = this->m_pRecvBuffer->m_Data;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: &p_m_NextPacketLen[m_nBytesReceivedSoFar + dwTransfer],
             destSize: m_nBytesToReceive - (m_nBytesReceivedSoFar + dwTransfer),
             bContinuation: 1u,
             bWaitingForSize: 0);
  }
  if ( !this->m_bWaitingForSize )
  {
    this->m_pHandler->OnPacketReceived(this: this->m_pHandler, a2: this->m_pRecvBuffer);
    this->m_pRecvBuffer = nullptr;
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  }
  m_NextPacketLen = this->m_NextPacketLen;
  if ( m_NextPacketLen == -12345 )
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  if ( m_NextPacketLen < 1 || m_NextPacketLen > 78643200 )
  {
    V_snprintf(pDest, maxLen: 512, pFormat: "Invalid packet size in RecvThread (size = %d)", this->m_NextPacketLen);
    CThreadedTCPSocket::HandleError(this, errorCode: 0, pErrorString: pDest);
    return 0;
  }
  else
  {
    v9 = (CTCPPacket *)operator new(nSize: m_NextPacketLen + 11);
    this->m_pRecvBuffer = v9;
    v9->m_UserData = 0;
    this->m_pRecvBuffer->m_Len = this->m_NextPacketLen;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: this->m_pRecvBuffer->m_Data,
             destSize: this->m_pRecvBuffer->m_Len,
             bContinuation: 0,
             bWaitingForSize: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004042A0
// Name: private: unsigned long CThreadedTCPSocket::RecvThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::RecvThreadFn(CThreadedTCPSocket *this)
{
  DWORD v3; // eax
  bool i; // zf
  unsigned int Error; // eax
  DWORD LastError; // eax
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int dwFlags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  void *handles[2]; // [esp+20Ch] [ebp-8h] BYREF

  if ( CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this) == 0 )
    return 1;
  handles[0] = CEvent::GetEventHandle(this: &this->m_hExitThreadsEvent);
  handles[1] = CEvent::GetEventHandle(this: &this->m_hRecvEvent);
  v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  for ( i = v3 == 258; v3 <= 0x102; i = v3 == 258 )
  {
    if ( i )
    {
      if ( g_bHandleTimeouts )
      {
        this->m_pHandler->OnError(this: this->m_pHandler, a2: 1, a3: "Connection timed out");
LABEL_17:
        CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
        this->m_bErrorSignal = true;
        return 1;
      }
    }
    else
    {
      if ( v3 == 0 )
        return 0;
      if ( v3 != 1 )
        goto LABEL_13;
      if ( !WSAGetOverlappedResult(
              s: this->m_Socket,
              lpOverlapped: &this->m_RecvOverlapped,
              lpcbTransfer: &cbTransfer,
              fWait: true,
              lpdwFlags: &dwFlags) )
      {
        Error = WSAGetLastError();
        CThreadedTCPSocket::HandleError(this, errorValue: Error);
        return 1;
      }
      if ( CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(this, dwTransfer: cbTransfer) == 0 )
        return 1;
    }
    v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  }
  if ( v3 != -1 )
  {
LABEL_13:
    V_snprintf(pDest: str, maxLen: 512, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v3);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    goto LABEL_17;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404410
// Name: private: static unsigned long CThreadedTCPSocket::StaticRecvThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticRecvThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::RecvThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x00404420
// Name: private: CThreadedTCPSocket::CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__thiscall CThreadedTCPSocket::CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // eax

  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CEvent::CEvent(this: &this->m_hReadyToSendEvent);
  CEvent::CEvent(this: &this->m_hSendCompletionEvent);
  CCriticalSection::CCriticalSection(this: &this->m_SendCS);
  this->m_SendDatas.m_Memory.m_pMemory = nullptr;
  this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  this->m_SendDatas.m_Memory.m_nGrowSize = 0;
  this->m_SendDatas.m_LastAlloc.index = -1;
  m_pMemory = this->m_SendDatas.m_Memory.m_pMemory;
  this->m_SendDatas.m_Head = -1;
  this->m_SendDatas.m_Tail = -1;
  this->m_SendDatas.m_FirstFree = -1;
  this->m_SendDatas.m_ElementCount = 0;
  this->m_SendDatas.m_NumAlloced = 0;
  this->m_SendDatas.m_pElements = m_pMemory;
  CEvent::CEvent(this: &this->m_hRecvEvent);
  CEvent::CEvent(this: &this->m_hExitThreadsEvent);
  CIPAddr::CIPAddr(this: &this->m_RemoteAddr);
  this->m_Socket = -1;
  this->m_pHandler = nullptr;
  *(_QWORD *)&this->m_SendOverlapped.Internal = 0;
  *(_QWORD *)&this->m_SendOverlapped.Offset = 0;
  this->m_SendOverlapped.hEvent = nullptr;
  *(_QWORD *)&this->m_RecvOverlapped.Internal = 0;
  *(_QWORD *)&this->m_RecvOverlapped.Offset = 0;
  this->m_RecvOverlapped.hEvent = nullptr;
  this->m_nBytesToReceive = -1;
  this->m_bWaitingForSendCompletion = false;
  this->m_bWaitingForSize = false;
  this->m_bErrorSignal = false;
  this->m_pRecvBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404510
// Name: public: virtual void CThreadedTCPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Release(CThreadedTCPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CThreadedTCPSocket *, int))this->dtr_CThreadedTCPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00404520
// Name: public: virtual class CIPAddr CThreadedTCPSocket::GetRemoteAddr(void)const
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CThreadedTCPSocket::GetRemoteAddr(CThreadedTCPSocket *this, CIPAddr *result)
{
  int v2; // edx
  unsigned __int16 port; // cx

  v2 = *(_DWORD *)this->m_RemoteAddr.ip;
  port = this->m_RemoteAddr.port;
  *(_DWORD *)result->ip = v2;
  result->port = port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404540
// Name: public: virtual bool CThreadedTCPSocket::Send(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::Send(CThreadedTCPSocket *this, const void *pData, int len)
{
  return this->SendChunks(this, a2: &pData, a3: &len, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00404560
// Name: public: virtual class ITCPSocketHandler __near * CThreadedTCPSocket::GetHandler(void)
// Source: json
//------------------------------------------------------------------------------
ITCPSocketHandler *__thiscall CThreadedTCPSocket::GetHandler(CThreadedTCPSocket *this)
{
  return this->m_pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x00404570
// Name: private: void CThreadedTCPSocket::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Term(CThreadedTCPSocket *this)
{
  void *m_hSendThread; // eax
  void *m_hRecvThread; // eax
  ITCPSocketHandler *m_pHandler; // ecx

  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  m_hSendThread = this->m_hSendThread;
  if ( m_hSendThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hSendThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hSendThread);
    this->m_hSendThread = nullptr;
  }
  m_hRecvThread = this->m_hRecvThread;
  if ( m_hRecvThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hRecvThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hRecvThread);
    this->m_hRecvThread = nullptr;
  }
  CEvent::ResetEvent(this: &this->m_hExitThreadsEvent);
  if ( this->m_Socket != -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  if ( this->m_bDeleteHandler )
  {
    m_pHandler = this->m_pHandler;
    if ( m_pHandler != nullptr )
    {
      m_pHandler->Release(this: m_pHandler, a2: false);
      this->m_pHandler = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404620
// Name: public: virtual bool CThreadedTCPSocket::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::IsValid(CThreadedTCPSocket *this)
{
  return !this->m_bErrorSignal;
}

//------------------------------------------------------------------------------
// Address: 0x00404630
// Name: private: virtual CThreadedTCPSocket::~CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::~CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CThreadedTCPSocket::Term(this);
  CEvent::~CEvent(this: &this->m_hExitThreadsEvent);
  CEvent::~CEvent(this: &this->m_hRecvEvent);
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)&this->m_SendDatas);
  if ( this->m_SendDatas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SendDatas.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendDatas.m_Memory.m_pMemory);
      this->m_SendDatas.m_Memory.m_pMemory = nullptr;
    }
    this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  }
  CCriticalSection::~CCriticalSection(this: &this->m_SendCS);
  CEvent::~CEvent(this: &this->m_hSendCompletionEvent);
  CEvent::~CEvent(this: &this->m_hReadyToSendEvent);
}

//------------------------------------------------------------------------------
// Address: 0x004046F0
// Name: private: bool CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  unsigned int Error; // eax
  int m_Head; // ebx
  bool v6; // cc
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int flags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  CCriticalSectionLock csLock; // [esp+20Ch] [ebp-8h] BYREF

  m_Socket = this->m_Socket;
  this->m_bWaitingForSendCompletion = false;
  if ( WSAGetOverlappedResult(
         s: m_Socket,
         lpOverlapped: &this->m_SendOverlapped,
         lpcbTransfer: &cbTransfer,
         fWait: true,
         lpdwFlags: &flags) )
  {
    if ( cbTransfer == this->m_nBytesToTransfer )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &csLock);
      free(pMem: this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element);
      m_Head = this->m_SendDatas.m_Head;
      CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        this: (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)&this->m_SendDatas,
        elem: m_Head);
      this->m_SendDatas.m_Memory.m_pMemory[m_Head].m_Next = this->m_SendDatas.m_FirstFree;
      this->m_SendDatas.m_FirstFree = m_Head;
      v6 = this->m_SendDatas.m_ElementCount <= 0;
      this->m_bWaitingForSendCompletion = false;
      if ( !v6 )
        CEvent::SetEvent(this: &this->m_hReadyToSendEvent);
      CCriticalSectionLock::Unlock(this: &csLock);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    }
    else
    {
      V_snprintf(
        pDest: str,
        maxLen: 512,
        pFormat: "Invalid # bytes transferred (%d) in send thread (should be %d)",
        cbTransfer,
        this->m_nBytesToTransfer);
      this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
      CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
      this->m_bErrorSignal = true;
      return 0;
    }
  }
  else
  {
    Error = WSAGetLastError();
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404820
// Name: private: bool CThreadedTCPSocket::InternalSend(void const __near * const __near *,int const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::InternalSend(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks,
        bool bPrependLength)
{
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // esi
  int v10; // eax
  int v11; // esi
  int *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  unsigned int *v15; // esi
  int v16; // ebx
  CThreadedTCPSocket *v17; // ebx
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int> > *p_m_SendDatas; // esi
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // edx
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // ecx
  int v24; // edx
  int m_Tail; // edi
  CThreadedTCPSocket::SendData_t **p_m_Element; // esi
  CCriticalSectionLock csLock; // [esp+Ch] [ebp-Ch] BYREF
  CThreadedTCPSocket *v29; // [esp+14h] [ebp-4h]
  CThreadedTCPSocket::SendData_t *pSendData; // [esp+24h] [ebp+Ch]
  int bPrependLengtha; // [esp+2Ch] [ebp+14h]

  v6 = nChunks;
  v29 = this;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( nChunks >= 2 )
  {
    do
    {
      v7 += *(_DWORD *)&pChunkLengths[4 * v10];
      v8 += *(_DWORD *)&pChunkLengths[4 * v10 + 4];
      v10 += 2;
    }
    while ( v10 < nChunks - 1 );
    v6 = nChunks;
  }
  if ( v10 < v6 )
    v9 = *(_DWORD *)&pChunkLengths[4 * v10];
  v11 = v8 + v7 + v9;
  if ( bPrependLength )
  {
    if ( v11 == 0 )
      return 1;
    v11 += 4;
  }
  v12 = (int *)operator new(nSize: v11 + 7);
  pSendData = (CThreadedTCPSocket::SendData_t *)v12;
  *v12 = v11;
  v13 = (unsigned __int8 *)(v12 + 1);
  if ( bPrependLength )
  {
    *(_DWORD *)v13 = v11 - 4;
    v13 = (unsigned __int8 *)(v12 + 2);
  }
  if ( nChunks > 0 )
  {
    v14 = (char *)pChunks - pChunkLengths;
    v15 = (unsigned int *)pChunkLengths;
    bPrependLengtha = (char *)pChunks - pChunkLengths;
    v16 = nChunks;
    while ( 1 )
    {
      memcpy(dst: v13, src: *(unsigned __int8 **)((char *)v15 + v14), count: *v15);
      v13 += *v15++;
      if ( --v16 == 0 )
        break;
      v14 = bPrependLengtha;
    }
  }
  v17 = v29;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &v29->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  p_m_SendDatas = &v17->m_SendDatas;
  v19 = CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal(
          this: &v17->m_SendDatas,
          multilist: false);
  if ( v19 != -1 )
  {
    if ( v19 >= 0 && v19 < v17->m_SendDatas.m_Memory.m_nAllocationCount && v19 <= v17->m_SendDatas.m_LastAlloc.index )
    {
      v20 = (int)&p_m_SendDatas->m_Memory.m_pMemory[v19];
      if ( *(_DWORD *)(v20 + 4) != v19 )
      {
        v21 = *(_DWORD *)(v20 + 4);
        if ( v21 == -1 )
          v17->m_SendDatas.m_Head = *(_DWORD *)(v20 + 8);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v21].m_Next = *(_DWORD *)(v20 + 8);
        v22 = *(_DWORD *)(v20 + 8);
        if ( v22 == -1 )
          v17->m_SendDatas.m_Tail = *(_DWORD *)(v20 + 4);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v22].m_Previous = *(_DWORD *)(v20 + 4);
        v17 = v29;
        *(_DWORD *)(v20 + 8) = v19;
        *(_DWORD *)(v20 + 4) = v19;
        --p_m_SendDatas->m_ElementCount;
      }
    }
    m_pMemory = p_m_SendDatas->m_Memory.m_pMemory;
    v24 = v19;
    m_pMemory[v24].m_Next = -1;
    m_Tail = p_m_SendDatas->m_Tail;
    m_pMemory[v24].m_Previous = m_Tail;
    p_m_SendDatas->m_Tail = v19;
    if ( m_Tail == -1 )
      p_m_SendDatas->m_Head = v19;
    else
      p_m_SendDatas->m_Memory.m_pMemory[m_Tail].m_Next = v19;
    ++p_m_SendDatas->m_ElementCount;
    p_m_Element = &p_m_SendDatas->m_Memory.m_pMemory[v24].m_Element;
    if ( p_m_Element != nullptr )
      *p_m_Element = pSendData;
  }
  CEvent::SetEvent(this: &v17->m_hReadyToSendEvent);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004049B0
// Name: private: unsigned long CThreadedTCPSocket::SendThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::SendThreadFn(CThreadedTCPSocket *this)
{
  void *EventHandle; // eax
  bool v3; // zf
  DWORD v4; // eax
  DWORD v5; // eax
  int m_ElementCount; // edi
  DWORD LastError; // eax
  char str[512]; // [esp+Ch] [ebp-21Ch] BYREF
  void *handles[3]; // [esp+20Ch] [ebp-1Ch] BYREF
  void *pChunks; // [esp+218h] [ebp-10h] BYREF
  int pChunkLengths; // [esp+21Ch] [ebp-Ch] BYREF
  CCriticalSectionLock v13; // [esp+220h] [ebp-8h] BYREF

  while ( 1 )
  {
    while ( 1 )
    {
      handles[0] = CEvent::GetEventHandle(this: &this->m_hExitThreadsEvent);
      handles[1] = CEvent::GetEventHandle(this: &this->m_hSendCompletionEvent);
      EventHandle = CEvent::GetEventHandle(this: &this->m_hReadyToSendEvent);
      v3 = !this->m_bWaitingForSendCompletion;
      handles[2] = EventHandle;
      v4 = 3;
      if ( !v3 )
        v4 = 2;
      v5 = WaitForMultipleObjects(nCount: v4, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0xBB8u);
      if ( v5 > 2 )
        break;
      if ( v5 == 2 )
      {
        if ( CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(this) == 0 )
          return 1;
      }
      else
      {
        if ( v5 == 0 )
          return 0;
        if ( CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(this) == 0 )
          return 1;
      }
    }
    if ( v5 != 258 )
      break;
    if ( g_bHandleTimeouts )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &v13, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &v13);
      m_ElementCount = this->m_SendDatas.m_ElementCount;
      CCriticalSectionLock::Unlock(this: &v13);
      if ( m_ElementCount == 0 )
      {
        pChunks = &g_KeepaliveSentinel;
        pChunkLengths = 4;
        CThreadedTCPSocket::InternalSend(
          this,
          (const void *const *)&pChunks,
          (char *)&pChunkLengths,
          nChunks: 1,
          bPrependLength: false);
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &v13);
    }
  }
  if ( v5 != -1 )
  {
    V_snprintf(pDest: str, maxLen: 512, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v5);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404B30
// Name: private: static unsigned long CThreadedTCPSocket::StaticSendThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticSendThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::SendThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x00404B40
// Name: public: virtual bool CThreadedTCPSocket::SendChunks(void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendChunks(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  if ( this->m_bErrorSignal )
    return 0;
  else
    return CThreadedTCPSocket::InternalSend(this, pChunks, pChunkLengths, nChunks, bPrependLength: true);
}

//------------------------------------------------------------------------------
// Address: 0x00404B70
// Name: private: bool CThreadedTCPSocket::Init(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::Init(
        CThreadedTCPSocket *this,
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  unsigned __int16 port; // dx
  unsigned int v6; // eax
  HANDLE v8; // eax
  void *m_hSendThread; // ecx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  unsigned int dwRecvThreadID; // [esp+Ch] [ebp-4h] BYREF

  port = remoteAddr.port;
  v6 = iSocket;
  *(_DWORD *)this->m_RemoteAddr.ip = *(_DWORD *)remoteAddr.ip;
  this->m_pHandler = pHandler;
  this->m_RemoteAddr.port = port;
  LOBYTE(port) = bDeleteHandler;
  this->m_Socket = v6;
  this->m_bDeleteHandler = port;
  iSocket = 1;
  setsockopt(s: v6, level: 6, optname: 1, optval: (const char *)&iSocket, optlen: 4);
  m_Socket = this->m_Socket;
  bDeleteHandler = 196609;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 128, optval: (const char *)&bDeleteHandler, optlen: 4);
  CEvent::Init(this: &this->m_hExitThreadsEvent, bManualReset: true, bInitialState: false);
  CEvent::Init(this: &this->m_hSendCompletionEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hReadyToSendEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hRecvEvent, bManualReset: false, bInitialState: false);
  this->m_SendOverlapped.hEvent = CEvent::GetEventHandle(this: &this->m_hSendCompletionEvent);
  this->m_RecvOverlapped.hEvent = CEvent::GetEventHandle(this: &this->m_hRecvEvent);
  this->m_hSendThread = CreateThread(
                          lpThreadAttributes: nullptr,
                          dwStackSize: 0,
                          lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticSendThreadFn,
                          lpParameter: this,
                          dwCreationFlags: 4u,
                          lpThreadId: (LPDWORD)&pHandler);
  v8 = CreateThread(
         lpThreadAttributes: nullptr,
         dwStackSize: 0,
         lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticRecvThreadFn,
         lpParameter: this,
         dwCreationFlags: 4u,
         lpThreadId: &dwRecvThreadID);
  m_hSendThread = this->m_hSendThread;
  this->m_hRecvThread = v8;
  if ( m_hSendThread == nullptr || v8 == nullptr )
    return 0;
  if ( g_bSetTCPSocketThreadPriorities )
  {
    SetThreadPriority(hThread: m_hSendThread, nPriority: -2);
    SetThreadPriority(hThread: this->m_hRecvThread, nPriority: -2);
  }
  this->m_pHandler->Init(this: this->m_pHandler, a2: this);
  ResumeThread(hThread: this->m_hSendThread);
  ResumeThread(hThread: this->m_hRecvThread);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404CD0
// Name: public: static class IThreadedTCPSocket __near * CThreadedTCPSocket::Create(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__cdecl CThreadedTCPSocket::Create(
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  CThreadedTCPSocket *v4; // eax
  CThreadedTCPSocket *v5; // esi

  v4 = (CThreadedTCPSocket *)operator new(nSize: 0xF8u);
  if ( v4 != nullptr )
    v5 = CThreadedTCPSocket::CThreadedTCPSocket(this: v4);
  else
    v5 = nullptr;
  if ( CThreadedTCPSocket::Init(this: v5, iSocket, remoteAddr, pHandler, bDeleteHandler) != 0 )
    return v5;
  v5->Release(this: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00404D30
// Name: public: virtual bool CTCPConnectSocket_Listener::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTCPConnectSocket_Listener::Update(
        CTCPConnectSocket_Listener *this,
        int pSocket,
        unsigned int milliseconds)
{
  CThreadedTCPSocket **v3; // ebx
  int v5; // eax
  SOCKET m_Socket; // edx
  SOCKET v7; // edi
  ITCPSocketHandler *v8; // eax
  CThreadedTCPSocket *v9; // eax
  fd_set readSet; // [esp+Ch] [ebp-124h] BYREF
  sockaddr_in addr; // [esp+110h] [ebp-20h] BYREF
  timeval timeVal; // [esp+120h] [ebp-10h] BYREF
  CIPAddr connectedAddr; // [esp+128h] [ebp-8h] BYREF

  v3 = (CThreadedTCPSocket **)pSocket;
  *(_DWORD *)pSocket = 0;
  if ( this->m_Socket == -1 )
    return 0;
  readSet.fd_array[0] = this->m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  timeVal.tv_usec = 1000 * milliseconds;
  v5 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v5 > 0 )
  {
    m_Socket = this->m_Socket;
    pSocket = 16;
    v7 = accept(s: m_Socket, (struct sockaddr *)&addr, addrlen: &pSocket);
    if ( v7 != -1 )
    {
      CIPAddr::CIPAddr(this: &connectedAddr);
      SockAddrToIPAddr(pIn: &addr, pOut: &connectedAddr);
      v8 = this->m_pHandler->CreateNewHandler(this: this->m_pHandler);
      v9 = CThreadedTCPSocket::Create(iSocket: v7, remoteAddr: connectedAddr, pHandler: v8, bDeleteHandler: 1);
      if ( v9 == nullptr )
      {
        closesocket(s: this->m_Socket);
        this->m_Socket = -1;
        return 0;
      }
      *v3 = v9;
    }
  }
  else if ( v5 == -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404E50
// Name: public: virtual bool CTCPConnectSocket_Connector::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::Update(
        CTCPConnectSocket_Connector *this,
        IThreadedTCPSocket **pSocket,
        unsigned int milliseconds)
{
  int v4; // eax
  SOCKET m_Socket; // edx
  ITCPSocketHandler *v7; // eax
  CThreadedTCPSocket *v8; // eax
  SOCKET v9; // [esp-4h] [ebp-114h]
  fd_set writeSet; // [esp+4h] [ebp-10Ch] BYREF
  timeval timeVal; // [esp+108h] [ebp-8h] BYREF

  *pSocket = nullptr;
  if ( this->m_bError )
    return false;
  if ( this->m_Socket == -1 )
    return true;
  if ( !this->m_bConnected )
  {
    writeSet.fd_array[0] = this->m_Socket;
    timeVal.tv_sec = 0;
    timeVal.tv_usec = 1000 * milliseconds;
    writeSet.fd_count = 1;
    v4 = select(nfds: 0, readfds: nullptr, writefds: &writeSet, exceptfds: nullptr, timeout: &timeVal);
    if ( v4 <= 0 )
    {
      if ( v4 == -1 )
        return CTCPConnectSocket_Connector::EnterErrorMode(this);
    }
    else
    {
      this->m_bConnected = true;
    }
    if ( !this->m_bConnected )
      return true;
  }
  m_Socket = this->m_Socket;
  milliseconds = 0;
  if ( ioctlsocket(s: m_Socket, cmd: -2147195266, argp: &milliseconds) != 0 )
  {
    v9 = this->m_Socket;
    this->m_bError = true;
    closesocket(s: v9);
    this->m_Socket = -1;
    return false;
  }
  v7 = this->m_pHandlerCreator->CreateNewHandler(this: this->m_pHandlerCreator);
  v8 = CThreadedTCPSocket::Create(
         iSocket: this->m_Socket,
         remoteAddr: this->m_RemoteAddr,
         pHandler: v7,
         bDeleteHandler: 1);
  if ( v8 != nullptr )
  {
    this->m_Socket = -1;
    *pSocket = v8;
    return true;
  }
  return CTCPConnectSocket_Connector::EnterErrorMode(this);
}

//------------------------------------------------------------------------------
// Address: 0x00404F60
// Name: public: virtual void CTCPConnectSocket_Listener::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPConnectSocket_Listener::Release(CTCPConnectSocket_Listener *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CTCPConnectSocket_Listener *, int))this->dtr_CTCPConnectSocket_Listener)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004062C0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CThreadedTCPSocket::SendData_t __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlLinkedListElem_t<CServiceConn *,int> *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CServiceConn *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

} // namespace vmpi_service

// ============================================================
// Overlay from vmpi_service_ui (Missing functions)
// ============================================================
namespace vmpi_service_ui {

//------------------------------------------------------------------------------
// Address: 0x004024C0
// Name: public: void CTCPPacket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPPacket::Release(CTCPPacket *this)
{
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x004024D0
// Name: private: void CThreadedTCPSocket::HandleError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, int errorCode, const char *pErrorString)
{
  this->m_pHandler->OnError(this: this->m_pHandler, a2: errorCode, a3: pErrorString);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  this->m_bErrorSignal = true;
}

//------------------------------------------------------------------------------
// Address: 0x00402510
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Connector::Create(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl CTCPConnectSocket_Connector::Create(
        const CIPAddr *connectAddr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  CIPAddr *v3; // eax
  CIPAddr *v4; // esi
  SOCKET v5; // edi
  int v6; // eax
  SOCKET v8; // [esp-Ch] [ebp-38h]
  sockaddr_in addr; // [esp+8h] [ebp-24h] BYREF
  sockaddr_in pOut; // [esp+18h] [ebp-14h] BYREF
  unsigned int val; // [esp+28h] [ebp-4h] BYREF

  v3 = (CIPAddr *)operator new(nSize: 0x18u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3->ip = &CTCPConnectSocket_Connector::`vftable';
    CIPAddr::CIPAddr(this: v3 + 2);
    *(_DWORD *)&v4[1].ip[2] = -1;
    v4->port = 0;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v5 == -1 )
    goto LABEL_7;
  IPAddrToSockAddr(pIn: localAddr, &pOut);
  if ( bind(s: v5, name: (const struct sockaddr *)&pOut, namelen: 16) != 0 )
  {
    closesocket(s: v5);
LABEL_7:
    v5 = -1;
  }
  *(_DWORD *)&v4[1].ip[2] = v5;
  if ( v5 != -1 )
  {
    IPAddrToSockAddr(pIn: connectAddr, pOut: &addr);
    val = 1;
    if ( ioctlsocket(s: *(_DWORD *)&v4[1].ip[2], cmd: -2147195266, argp: &val) == 0 )
    {
      v4[2] = *connectAddr;
      v8 = *(_DWORD *)&v4[1].ip[2];
      *(_DWORD *)&v4[3].ip[2] = pHandlerCreator;
      v6 = connect(s: v8, name: (const struct sockaddr *)&addr, namelen: 16);
      if ( v6 == 0 )
      {
        HIBYTE(v4->port) = 1;
        return v4;
      }
      if ( v6 == -1 && WSAGetLastError() == 10035 )
        return v4;
    }
  }
  (**(void (__thiscall ***)(CIPAddr *))v4->ip)(a1: v4);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00402630
// Name: public: virtual void CTCPConnectSocket_Connector::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPConnectSocket_Connector::Release(CTCPConnectSocket_Connector *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CTCPConnectSocket_Connector *, int))this->dtr_CTCPConnectSocket_Connector)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00402640
// Name: public: bool CTCPConnectSocket_Connector::EnterErrorMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::EnterErrorMode(CTCPConnectSocket_Connector *this)
{
  SOCKET m_Socket; // [esp-4h] [ebp-8h]

  m_Socket = this->m_Socket;
  this->m_bError = true;
  closesocket(s: m_Socket);
  this->m_Socket = -1;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004026A0
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateConnector(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl ThreadedTCP_CreateConnector(
        const CIPAddr *addr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  return CTCPConnectSocket_Connector::Create(connectAddr: addr, localAddr, pHandlerCreator);
}

//------------------------------------------------------------------------------
// Address: 0x004026B0
// Name: private: void CThreadedTCPSocket::HandleError(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, unsigned int errorValue)
{
  DWORD LastError; // eax
  char *v4; // edx
  int i; // eax
  char v6; // cl
  char *v7; // [esp-4h] [ebp-10h]
  char *lpMsgBuf; // [esp+8h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  v4 = lpMsgBuf;
  for ( i = strlen(lpMsgBuf); i > 0; v4 = lpMsgBuf )
  {
    v6 = v4[i - 1];
    if ( v6 != 10 && v6 != 13 )
      break;
    v4[--i] = 0;
  }
  this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: v4);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  v7 = lpMsgBuf;
  this->m_bErrorSignal = true;
  LocalFree(hMem: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00402740
// Name: private: bool CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(CThreadedTCPSocket *this)
{
  CThreadedTCPSocket::SendData_t *m_Element; // eax
  int v3; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-38h]
  _WSABUF buf; // [esp+8h] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+18h] [ebp-4h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Element = this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element;
  buf.len = m_Element->m_Len;
  buf.buf = m_Element->m_Payload;
  this->m_nBytesToTransfer = m_Element->m_Len;
  this->m_bWaitingForSendCompletion = true;
  CCriticalSectionLock::Unlock(this: &csLock);
  m_Socket = this->m_Socket;
  dwNumBytesSent = 0;
  v3 = WSASend(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesSent: &dwNumBytesSent,
         dwFlags: 0,
         lpOverlapped: &this->m_SendOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402800
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalRecv(void __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalRecv(
        CThreadedTCPSocket *this,
        char *pDest,
        int destSize,
        unsigned int bContinuation,
        unsigned int bWaitingForSize)
{
  int v6; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-2Ch]
  _WSABUF buf; // [esp+8h] [ebp-8h] BYREF

  buf.len = destSize;
  buf.buf = pDest;
  if ( (_BYTE)bContinuation == 0 )
  {
    this->m_bWaitingForSize = bWaitingForSize;
    this->m_nBytesToReceive = destSize;
    this->m_nBytesReceivedSoFar = 0;
  }
  m_Socket = this->m_Socket;
  bContinuation = 0;
  bWaitingForSize = 0;
  v6 = WSARecv(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &bWaitingForSize,
         lpFlags: &bContinuation,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v6 == 0 || v6 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004029D0
// Name: private: bool CThreadedTCPSocket::RecvThread_WaitToReceiveSize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_WaitToReceiveSize(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  int v3; // edi
  unsigned int Error; // eax
  _WSABUF Buffers; // [esp+8h] [ebp-10h] BYREF
  unsigned int NumberOfBytesRecvd; // [esp+10h] [ebp-8h] BYREF
  unsigned int Flags; // [esp+14h] [ebp-4h] BYREF

  Buffers.len = 4;
  this->m_nBytesToReceive = 4;
  m_Socket = this->m_Socket;
  Buffers.buf = (char *)&this->m_NextPacketLen;
  this->m_bWaitingForSize = true;
  this->m_nBytesReceivedSoFar = 0;
  Flags = 0;
  NumberOfBytesRecvd = 0;
  v3 = WSARecv(
         s: m_Socket,
         lpBuffers: &Buffers,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &NumberOfBytesRecvd,
         lpFlags: &Flags,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402A70
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(
        CThreadedTCPSocket *this,
        signed int dwTransfer)
{
  int m_nBytesToReceive; // eax
  int m_nBytesReceivedSoFar; // edi
  bool v6; // zf
  char *p_m_NextPacketLen; // edx
  int m_NextPacketLen; // eax
  CTCPPacket *v9; // eax
  char pDest[512]; // [esp+8h] [ebp-400h] BYREF
  char str[512]; // [esp+208h] [ebp-200h] BYREF

  m_nBytesToReceive = this->m_nBytesToReceive;
  m_nBytesReceivedSoFar = this->m_nBytesReceivedSoFar;
  if ( dwTransfer > m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    V_snprintf(
      pDest: str,
      maxLen: 512,
      pFormat: "Invalid # bytes received (%d) in recv thread (should be %d)",
      dwTransfer,
      m_nBytesToReceive);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  if ( dwTransfer < m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    v6 = !this->m_bWaitingForSize;
    this->m_nBytesReceivedSoFar = m_nBytesReceivedSoFar + dwTransfer;
    p_m_NextPacketLen = (char *)&this->m_NextPacketLen;
    if ( v6 )
      p_m_NextPacketLen = this->m_pRecvBuffer->m_Data;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: &p_m_NextPacketLen[m_nBytesReceivedSoFar + dwTransfer],
             destSize: m_nBytesToReceive - (m_nBytesReceivedSoFar + dwTransfer),
             bContinuation: 1u,
             bWaitingForSize: 0);
  }
  if ( !this->m_bWaitingForSize )
  {
    this->m_pHandler->OnPacketReceived(this: this->m_pHandler, a2: this->m_pRecvBuffer);
    this->m_pRecvBuffer = nullptr;
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  }
  m_NextPacketLen = this->m_NextPacketLen;
  if ( m_NextPacketLen == -12345 )
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  if ( m_NextPacketLen < 1 || m_NextPacketLen > 78643200 )
  {
    V_snprintf(pDest, maxLen: 512, pFormat: "Invalid packet size in RecvThread (size = %d)", this->m_NextPacketLen);
    CThreadedTCPSocket::HandleError(this, errorCode: 0, pErrorString: pDest);
    return 0;
  }
  else
  {
    v9 = (CTCPPacket *)operator new(nSize: m_NextPacketLen + 11);
    this->m_pRecvBuffer = v9;
    v9->m_UserData = 0;
    this->m_pRecvBuffer->m_Len = this->m_NextPacketLen;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: this->m_pRecvBuffer->m_Data,
             destSize: this->m_pRecvBuffer->m_Len,
             bContinuation: 0,
             bWaitingForSize: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402BF0
// Name: private: unsigned long CThreadedTCPSocket::RecvThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::RecvThreadFn(CThreadedTCPSocket *this)
{
  DWORD v3; // eax
  bool i; // zf
  unsigned int Error; // eax
  DWORD LastError; // eax
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int dwFlags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  void *handles[2]; // [esp+20Ch] [ebp-8h] BYREF

  if ( CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this) == 0 )
    return 1;
  handles[0] = CEvent::GetEventHandle(this: &this->m_hExitThreadsEvent);
  handles[1] = CEvent::GetEventHandle(this: &this->m_hRecvEvent);
  v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  for ( i = v3 == 258; v3 <= 0x102; i = v3 == 258 )
  {
    if ( i )
    {
      if ( g_bHandleTimeouts )
      {
        this->m_pHandler->OnError(this: this->m_pHandler, a2: 1, a3: "Connection timed out");
LABEL_17:
        CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
        this->m_bErrorSignal = true;
        return 1;
      }
    }
    else
    {
      if ( v3 == 0 )
        return 0;
      if ( v3 != 1 )
        goto LABEL_13;
      if ( !WSAGetOverlappedResult(
              s: this->m_Socket,
              lpOverlapped: &this->m_RecvOverlapped,
              lpcbTransfer: &cbTransfer,
              fWait: true,
              lpdwFlags: &dwFlags) )
      {
        Error = WSAGetLastError();
        CThreadedTCPSocket::HandleError(this, errorValue: Error);
        return 1;
      }
      if ( CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(this, dwTransfer: cbTransfer) == 0 )
        return 1;
    }
    v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  }
  if ( v3 != -1 )
  {
LABEL_13:
    V_snprintf(pDest: str, maxLen: 512, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v3);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    goto LABEL_17;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402D60
// Name: private: static unsigned long CThreadedTCPSocket::StaticRecvThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticRecvThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::RecvThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x00402D70
// Name: private: CThreadedTCPSocket::CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__thiscall CThreadedTCPSocket::CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // eax

  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CEvent::CEvent(this: &this->m_hReadyToSendEvent);
  CEvent::CEvent(this: &this->m_hSendCompletionEvent);
  CCriticalSection::CCriticalSection(this: &this->m_SendCS);
  this->m_SendDatas.m_Memory.m_pMemory = nullptr;
  this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  this->m_SendDatas.m_Memory.m_nGrowSize = 0;
  this->m_SendDatas.m_LastAlloc.index = -1;
  m_pMemory = this->m_SendDatas.m_Memory.m_pMemory;
  this->m_SendDatas.m_Head = -1;
  this->m_SendDatas.m_Tail = -1;
  this->m_SendDatas.m_FirstFree = -1;
  this->m_SendDatas.m_ElementCount = 0;
  this->m_SendDatas.m_NumAlloced = 0;
  this->m_SendDatas.m_pElements = m_pMemory;
  CEvent::CEvent(this: &this->m_hRecvEvent);
  CEvent::CEvent(this: &this->m_hExitThreadsEvent);
  CIPAddr::CIPAddr(this: &this->m_RemoteAddr);
  this->m_Socket = -1;
  this->m_pHandler = nullptr;
  *(_QWORD *)&this->m_SendOverlapped.Internal = 0;
  *(_QWORD *)&this->m_SendOverlapped.Offset = 0;
  this->m_SendOverlapped.hEvent = nullptr;
  *(_QWORD *)&this->m_RecvOverlapped.Internal = 0;
  *(_QWORD *)&this->m_RecvOverlapped.Offset = 0;
  this->m_RecvOverlapped.hEvent = nullptr;
  this->m_nBytesToReceive = -1;
  this->m_bWaitingForSendCompletion = false;
  this->m_bWaitingForSize = false;
  this->m_bErrorSignal = false;
  this->m_pRecvBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402E60
// Name: public: virtual void CThreadedTCPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Release(CThreadedTCPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CThreadedTCPSocket *, int))this->dtr_CThreadedTCPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00402E70
// Name: public: virtual class CIPAddr CThreadedTCPSocket::GetRemoteAddr(void)const
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CThreadedTCPSocket::GetRemoteAddr(CThreadedTCPSocket *this, CIPAddr *result)
{
  int v2; // edx
  unsigned __int16 port; // cx

  v2 = *(_DWORD *)this->m_RemoteAddr.ip;
  port = this->m_RemoteAddr.port;
  *(_DWORD *)result->ip = v2;
  result->port = port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402E90
// Name: public: virtual bool CThreadedTCPSocket::Send(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::Send(CThreadedTCPSocket *this, const void *pData, int len)
{
  return this->SendChunks(this, a2: &pData, a3: &len, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00402EB0
// Name: public: virtual class ITCPSocketHandler __near * CThreadedTCPSocket::GetHandler(void)
// Source: json
//------------------------------------------------------------------------------
ITCPSocketHandler *__thiscall CThreadedTCPSocket::GetHandler(CThreadedTCPSocket *this)
{
  return this->m_pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x00402EC0
// Name: private: void CThreadedTCPSocket::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Term(CThreadedTCPSocket *this)
{
  void *m_hSendThread; // eax
  void *m_hRecvThread; // eax
  ITCPSocketHandler *m_pHandler; // ecx

  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  m_hSendThread = this->m_hSendThread;
  if ( m_hSendThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hSendThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hSendThread);
    this->m_hSendThread = nullptr;
  }
  m_hRecvThread = this->m_hRecvThread;
  if ( m_hRecvThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hRecvThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hRecvThread);
    this->m_hRecvThread = nullptr;
  }
  CEvent::ResetEvent(this: &this->m_hExitThreadsEvent);
  if ( this->m_Socket != -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  if ( this->m_bDeleteHandler )
  {
    m_pHandler = this->m_pHandler;
    if ( m_pHandler != nullptr )
    {
      m_pHandler->Release(this: m_pHandler, a2: false);
      this->m_pHandler = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402F70
// Name: public: virtual bool CThreadedTCPSocket::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::IsValid(CThreadedTCPSocket *this)
{
  return !this->m_bErrorSignal;
}

//------------------------------------------------------------------------------
// Address: 0x00402F80
// Name: private: virtual CThreadedTCPSocket::~CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::~CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CThreadedTCPSocket::Term(this);
  CEvent::~CEvent(this: &this->m_hExitThreadsEvent);
  CEvent::~CEvent(this: &this->m_hRecvEvent);
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)&this->m_SendDatas);
  if ( this->m_SendDatas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SendDatas.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendDatas.m_Memory.m_pMemory);
      this->m_SendDatas.m_Memory.m_pMemory = nullptr;
    }
    this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  }
  CCriticalSection::~CCriticalSection(this: &this->m_SendCS);
  CEvent::~CEvent(this: &this->m_hSendCompletionEvent);
  CEvent::~CEvent(this: &this->m_hReadyToSendEvent);
}

//------------------------------------------------------------------------------
// Address: 0x00403040
// Name: private: bool CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  unsigned int Error; // eax
  int m_Head; // ebx
  bool v6; // cc
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int flags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  CCriticalSectionLock csLock; // [esp+20Ch] [ebp-8h] BYREF

  m_Socket = this->m_Socket;
  this->m_bWaitingForSendCompletion = false;
  if ( WSAGetOverlappedResult(
         s: m_Socket,
         lpOverlapped: &this->m_SendOverlapped,
         lpcbTransfer: &cbTransfer,
         fWait: true,
         lpdwFlags: &flags) )
  {
    if ( cbTransfer == this->m_nBytesToTransfer )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &csLock);
      free(pMem: this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element);
      m_Head = this->m_SendDatas.m_Head;
      CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        this: (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)&this->m_SendDatas,
        elem: m_Head);
      this->m_SendDatas.m_Memory.m_pMemory[m_Head].m_Next = this->m_SendDatas.m_FirstFree;
      this->m_SendDatas.m_FirstFree = m_Head;
      v6 = this->m_SendDatas.m_ElementCount <= 0;
      this->m_bWaitingForSendCompletion = false;
      if ( !v6 )
        CEvent::SetEvent(this: &this->m_hReadyToSendEvent);
      CCriticalSectionLock::Unlock(this: &csLock);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    }
    else
    {
      V_snprintf(
        pDest: str,
        maxLen: 512,
        pFormat: "Invalid # bytes transferred (%d) in send thread (should be %d)",
        cbTransfer,
        this->m_nBytesToTransfer);
      this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
      CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
      this->m_bErrorSignal = true;
      return 0;
    }
  }
  else
  {
    Error = WSAGetLastError();
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403170
// Name: private: bool CThreadedTCPSocket::InternalSend(void const __near * const __near *,int const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::InternalSend(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks,
        bool bPrependLength)
{
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // esi
  int v10; // eax
  int v11; // esi
  int *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  unsigned int *v15; // esi
  int v16; // ebx
  CThreadedTCPSocket *v17; // ebx
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int> > *p_m_SendDatas; // esi
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // edx
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // ecx
  int v24; // edx
  int m_Tail; // edi
  CThreadedTCPSocket::SendData_t **p_m_Element; // esi
  CCriticalSectionLock csLock; // [esp+Ch] [ebp-Ch] BYREF
  CThreadedTCPSocket *v29; // [esp+14h] [ebp-4h]
  CThreadedTCPSocket::SendData_t *pSendData; // [esp+24h] [ebp+Ch]
  int bPrependLengtha; // [esp+2Ch] [ebp+14h]

  v6 = nChunks;
  v29 = this;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( nChunks >= 2 )
  {
    do
    {
      v7 += *(_DWORD *)&pChunkLengths[4 * v10];
      v8 += *(_DWORD *)&pChunkLengths[4 * v10 + 4];
      v10 += 2;
    }
    while ( v10 < nChunks - 1 );
    v6 = nChunks;
  }
  if ( v10 < v6 )
    v9 = *(_DWORD *)&pChunkLengths[4 * v10];
  v11 = v8 + v7 + v9;
  if ( bPrependLength )
  {
    if ( v11 == 0 )
      return 1;
    v11 += 4;
  }
  v12 = (int *)operator new(nSize: v11 + 7);
  pSendData = (CThreadedTCPSocket::SendData_t *)v12;
  *v12 = v11;
  v13 = (unsigned __int8 *)(v12 + 1);
  if ( bPrependLength )
  {
    *(_DWORD *)v13 = v11 - 4;
    v13 = (unsigned __int8 *)(v12 + 2);
  }
  if ( nChunks > 0 )
  {
    v14 = (char *)pChunks - pChunkLengths;
    v15 = (unsigned int *)pChunkLengths;
    bPrependLengtha = (char *)pChunks - pChunkLengths;
    v16 = nChunks;
    while ( 1 )
    {
      memcpy(dst: v13, src: *(unsigned __int8 **)((char *)v15 + v14), count: *v15);
      v13 += *v15++;
      if ( --v16 == 0 )
        break;
      v14 = bPrependLengtha;
    }
  }
  v17 = v29;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &v29->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  p_m_SendDatas = &v17->m_SendDatas;
  v19 = CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal(
          this: &v17->m_SendDatas,
          multilist: false);
  if ( v19 != -1 )
  {
    if ( v19 >= 0 && v19 < v17->m_SendDatas.m_Memory.m_nAllocationCount && v19 <= v17->m_SendDatas.m_LastAlloc.index )
    {
      v20 = (int)&p_m_SendDatas->m_Memory.m_pMemory[v19];
      if ( *(_DWORD *)(v20 + 4) != v19 )
      {
        v21 = *(_DWORD *)(v20 + 4);
        if ( v21 == -1 )
          v17->m_SendDatas.m_Head = *(_DWORD *)(v20 + 8);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v21].m_Next = *(_DWORD *)(v20 + 8);
        v22 = *(_DWORD *)(v20 + 8);
        if ( v22 == -1 )
          v17->m_SendDatas.m_Tail = *(_DWORD *)(v20 + 4);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v22].m_Previous = *(_DWORD *)(v20 + 4);
        v17 = v29;
        *(_DWORD *)(v20 + 8) = v19;
        *(_DWORD *)(v20 + 4) = v19;
        --p_m_SendDatas->m_ElementCount;
      }
    }
    m_pMemory = p_m_SendDatas->m_Memory.m_pMemory;
    v24 = v19;
    m_pMemory[v24].m_Next = -1;
    m_Tail = p_m_SendDatas->m_Tail;
    m_pMemory[v24].m_Previous = m_Tail;
    p_m_SendDatas->m_Tail = v19;
    if ( m_Tail == -1 )
      p_m_SendDatas->m_Head = v19;
    else
      p_m_SendDatas->m_Memory.m_pMemory[m_Tail].m_Next = v19;
    ++p_m_SendDatas->m_ElementCount;
    p_m_Element = &p_m_SendDatas->m_Memory.m_pMemory[v24].m_Element;
    if ( p_m_Element != nullptr )
      *p_m_Element = pSendData;
  }
  CEvent::SetEvent(this: &v17->m_hReadyToSendEvent);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403300
// Name: private: unsigned long CThreadedTCPSocket::SendThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::SendThreadFn(CThreadedTCPSocket *this)
{
  void *EventHandle; // eax
  bool v3; // zf
  DWORD v4; // eax
  DWORD v5; // eax
  int m_ElementCount; // edi
  DWORD LastError; // eax
  char str[512]; // [esp+Ch] [ebp-21Ch] BYREF
  void *handles[3]; // [esp+20Ch] [ebp-1Ch] BYREF
  void *pChunks; // [esp+218h] [ebp-10h] BYREF
  int pChunkLengths; // [esp+21Ch] [ebp-Ch] BYREF
  CCriticalSectionLock v13; // [esp+220h] [ebp-8h] BYREF

  while ( 1 )
  {
    while ( 1 )
    {
      handles[0] = CEvent::GetEventHandle(this: &this->m_hExitThreadsEvent);
      handles[1] = CEvent::GetEventHandle(this: &this->m_hSendCompletionEvent);
      EventHandle = CEvent::GetEventHandle(this: &this->m_hReadyToSendEvent);
      v3 = !this->m_bWaitingForSendCompletion;
      handles[2] = EventHandle;
      v4 = 3;
      if ( !v3 )
        v4 = 2;
      v5 = WaitForMultipleObjects(nCount: v4, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0xBB8u);
      if ( v5 > 2 )
        break;
      if ( v5 == 2 )
      {
        if ( CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(this) == 0 )
          return 1;
      }
      else
      {
        if ( v5 == 0 )
          return 0;
        if ( CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(this) == 0 )
          return 1;
      }
    }
    if ( v5 != 258 )
      break;
    if ( g_bHandleTimeouts )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &v13, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &v13);
      m_ElementCount = this->m_SendDatas.m_ElementCount;
      CCriticalSectionLock::Unlock(this: &v13);
      if ( m_ElementCount == 0 )
      {
        pChunks = &g_KeepaliveSentinel;
        pChunkLengths = 4;
        CThreadedTCPSocket::InternalSend(
          this,
          (const void *const *)&pChunks,
          (char *)&pChunkLengths,
          nChunks: 1,
          bPrependLength: false);
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &v13);
    }
  }
  if ( v5 != -1 )
  {
    V_snprintf(pDest: str, maxLen: 512, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v5);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403480
// Name: private: static unsigned long CThreadedTCPSocket::StaticSendThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticSendThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::SendThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x00403490
// Name: public: virtual bool CThreadedTCPSocket::SendChunks(void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendChunks(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  if ( this->m_bErrorSignal )
    return 0;
  else
    return CThreadedTCPSocket::InternalSend(this, pChunks, pChunkLengths, nChunks, bPrependLength: true);
}

//------------------------------------------------------------------------------
// Address: 0x004034C0
// Name: private: bool CThreadedTCPSocket::Init(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::Init(
        CThreadedTCPSocket *this,
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  unsigned __int16 port; // dx
  unsigned int v6; // eax
  HANDLE v8; // eax
  void *m_hSendThread; // ecx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  unsigned int dwRecvThreadID; // [esp+Ch] [ebp-4h] BYREF

  port = remoteAddr.port;
  v6 = iSocket;
  *(_DWORD *)this->m_RemoteAddr.ip = *(_DWORD *)remoteAddr.ip;
  this->m_pHandler = pHandler;
  this->m_RemoteAddr.port = port;
  LOBYTE(port) = bDeleteHandler;
  this->m_Socket = v6;
  this->m_bDeleteHandler = port;
  iSocket = 1;
  setsockopt(s: v6, level: 6, optname: 1, optval: (const char *)&iSocket, optlen: 4);
  m_Socket = this->m_Socket;
  bDeleteHandler = 196609;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 128, optval: (const char *)&bDeleteHandler, optlen: 4);
  CEvent::Init(this: &this->m_hExitThreadsEvent, bManualReset: true, bInitialState: false);
  CEvent::Init(this: &this->m_hSendCompletionEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hReadyToSendEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hRecvEvent, bManualReset: false, bInitialState: false);
  this->m_SendOverlapped.hEvent = CEvent::GetEventHandle(this: &this->m_hSendCompletionEvent);
  this->m_RecvOverlapped.hEvent = CEvent::GetEventHandle(this: &this->m_hRecvEvent);
  this->m_hSendThread = CreateThread(
                          lpThreadAttributes: nullptr,
                          dwStackSize: 0,
                          lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticSendThreadFn,
                          lpParameter: this,
                          dwCreationFlags: 4u,
                          lpThreadId: (LPDWORD)&pHandler);
  v8 = CreateThread(
         lpThreadAttributes: nullptr,
         dwStackSize: 0,
         lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticRecvThreadFn,
         lpParameter: this,
         dwCreationFlags: 4u,
         lpThreadId: &dwRecvThreadID);
  m_hSendThread = this->m_hSendThread;
  this->m_hRecvThread = v8;
  if ( m_hSendThread == nullptr || v8 == nullptr )
    return 0;
  if ( g_bSetTCPSocketThreadPriorities )
  {
    SetThreadPriority(hThread: m_hSendThread, nPriority: -2);
    SetThreadPriority(hThread: this->m_hRecvThread, nPriority: -2);
  }
  this->m_pHandler->Init(this: this->m_pHandler, a2: this);
  ResumeThread(hThread: this->m_hSendThread);
  ResumeThread(hThread: this->m_hRecvThread);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403620
// Name: public: static class IThreadedTCPSocket __near * CThreadedTCPSocket::Create(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__cdecl CThreadedTCPSocket::Create(
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  CThreadedTCPSocket *v4; // eax
  CThreadedTCPSocket *v5; // esi

  v4 = (CThreadedTCPSocket *)operator new(nSize: 0xF8u);
  if ( v4 != nullptr )
    v5 = CThreadedTCPSocket::CThreadedTCPSocket(this: v4);
  else
    v5 = nullptr;
  if ( CThreadedTCPSocket::Init(this: v5, iSocket, remoteAddr, pHandler, bDeleteHandler) != 0 )
    return v5;
  v5->Release(this: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403680
// Name: public: virtual bool CTCPConnectSocket_Connector::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::Update(
        CTCPConnectSocket_Connector *this,
        IThreadedTCPSocket **pSocket,
        unsigned int milliseconds)
{
  int v4; // eax
  SOCKET m_Socket; // edx
  ITCPSocketHandler *v7; // eax
  CThreadedTCPSocket *v8; // eax
  SOCKET v9; // [esp-4h] [ebp-114h]
  fd_set writeSet; // [esp+4h] [ebp-10Ch] BYREF
  timeval timeVal; // [esp+108h] [ebp-8h] BYREF

  *pSocket = nullptr;
  if ( this->m_bError )
    return false;
  if ( this->m_Socket == -1 )
    return true;
  if ( !this->m_bConnected )
  {
    writeSet.fd_array[0] = this->m_Socket;
    timeVal.tv_sec = 0;
    timeVal.tv_usec = 1000 * milliseconds;
    writeSet.fd_count = 1;
    v4 = select(nfds: 0, readfds: nullptr, writefds: &writeSet, exceptfds: nullptr, timeout: &timeVal);
    if ( v4 <= 0 )
    {
      if ( v4 == -1 )
        return CTCPConnectSocket_Connector::EnterErrorMode(this);
    }
    else
    {
      this->m_bConnected = true;
    }
    if ( !this->m_bConnected )
      return true;
  }
  m_Socket = this->m_Socket;
  milliseconds = 0;
  if ( ioctlsocket(s: m_Socket, cmd: -2147195266, argp: &milliseconds) != 0 )
  {
    v9 = this->m_Socket;
    this->m_bError = true;
    closesocket(s: v9);
    this->m_Socket = -1;
    return false;
  }
  v7 = this->m_pHandlerCreator->CreateNewHandler(this: this->m_pHandlerCreator);
  v8 = CThreadedTCPSocket::Create(
         iSocket: this->m_Socket,
         remoteAddr: this->m_RemoteAddr,
         pHandler: v7,
         bDeleteHandler: 1);
  if ( v8 != nullptr )
  {
    this->m_Socket = -1;
    *pSocket = v8;
    return true;
  }
  return CTCPConnectSocket_Connector::EnterErrorMode(this);
}

} // namespace vmpi_service_ui

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10089C80
// Name: public: int CTCPPacket::GetUserData(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CTCPPacket::GetUserData(CEvent *this)
{
  return this->m_hEvent;
}

//------------------------------------------------------------------------------
// Address: 0x10089F00
// Name: public: void CTCPPacket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPPacket::Release(CVMPIFile_Memory *this)
{
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x1008FB40
// Name: TCPBind
// Source: json
//------------------------------------------------------------------------------
SOCKET __cdecl TCPBind(const CIPAddr *pAddr)
{
  SOCKET v1; // esi
  sockaddr_in addr; // [esp+4h] [ebp-10h] BYREF

  v1 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v1 != -1 )
  {
    IPAddrToSockAddr(pIn: pAddr, pOut: &addr);
    if ( bind(s: v1, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
      return v1;
    closesocket(s: v1);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1008FBA0
// Name: public: void CTCPPacket::SetUserData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPPacket::SetUserData(CTCPPacket *this, int userData)
{
  this->m_UserData = userData;
}

//------------------------------------------------------------------------------
// Address: 0x1008FBB0
// Name: private: void CThreadedTCPSocket::HandleError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, int errorCode, const char *pErrorString)
{
  this->m_pHandler->OnError(this: this->m_pHandler, a2: errorCode, a3: pErrorString);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  this->m_bErrorSignal = true;
}

//------------------------------------------------------------------------------
// Address: 0x1008FBF0
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Connector::Create(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl CTCPConnectSocket_Connector::Create(
        const CIPAddr *connectAddr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  CIPAddr *v3; // eax
  CIPAddr *v4; // esi
  SOCKET v5; // edi
  int v6; // eax
  SOCKET v8; // [esp-Ch] [ebp-38h]
  sockaddr_in addr; // [esp+8h] [ebp-24h] BYREF
  sockaddr_in pOut; // [esp+18h] [ebp-14h] BYREF
  unsigned int val; // [esp+28h] [ebp-4h] BYREF

  v3 = (CIPAddr *)MemAlloc_Alloc(nSize: 0x18u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3->ip = &CTCPConnectSocket_Connector::`vftable';
    CIPAddr::CIPAddr(this: v3 + 2);
    *(_DWORD *)&v4[1].ip[2] = -1;
    v4->port = 0;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v5 == -1 )
    goto LABEL_7;
  IPAddrToSockAddr(pIn: localAddr, &pOut);
  if ( bind(s: v5, name: (const struct sockaddr *)&pOut, namelen: 16) != 0 )
  {
    closesocket(s: v5);
LABEL_7:
    v5 = -1;
  }
  *(_DWORD *)&v4[1].ip[2] = v5;
  if ( v5 != -1 )
  {
    IPAddrToSockAddr(pIn: connectAddr, pOut: &addr);
    val = 1;
    if ( ioctlsocket(s: *(_DWORD *)&v4[1].ip[2], cmd: -2147195266, argp: &val) == 0 )
    {
      v4[2] = *connectAddr;
      v8 = *(_DWORD *)&v4[1].ip[2];
      *(_DWORD *)&v4[3].ip[2] = pHandlerCreator;
      v6 = connect(s: v8, name: (const struct sockaddr *)&addr, namelen: 16);
      if ( v6 == 0 )
      {
        HIBYTE(v4->port) = 1;
        return v4;
      }
      if ( v6 == -1 && WSAGetLastError() == 10035 )
        return v4;
    }
  }
  (**(void (__thiscall ***)(CIPAddr *))v4->ip)(a1: v4);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008FD10
// Name: public: bool CTCPConnectSocket_Connector::EnterErrorMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::EnterErrorMode(CTCPConnectSocket_Connector *this)
{
  SOCKET m_Socket; // [esp-4h] [ebp-8h]

  m_Socket = this->m_Socket;
  this->m_bError = true;
  closesocket(s: m_Socket);
  this->m_Socket = -1;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1008FD70
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateConnector(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl ThreadedTCP_CreateConnector(
        const CIPAddr *addr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  return CTCPConnectSocket_Connector::Create(connectAddr: addr, localAddr, pHandlerCreator);
}

//------------------------------------------------------------------------------
// Address: 0x1008FD80
// Name: void ThreadedTCP_EnableTimeouts(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadedTCP_EnableTimeouts(bool bEnable)
{
  g_bHandleTimeouts = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1008FD90
// Name: void ThreadedTCP_SetTCPSocketThreadPriorities(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadedTCP_SetTCPSocketThreadPriorities(bool bSetTCPSocketThreadPriorities)
{
  g_bSetTCPSocketThreadPriorities = bSetTCPSocketThreadPriorities;
}

//------------------------------------------------------------------------------
// Address: 0x1008FDA0
// Name: private: void CThreadedTCPSocket::HandleError(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, unsigned int errorValue)
{
  DWORD LastError; // eax
  char *v4; // edx
  int i; // eax
  char v6; // cl
  char *v7; // [esp-4h] [ebp-10h]
  char *lpMsgBuf; // [esp+8h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  v4 = lpMsgBuf;
  for ( i = strlen(lpMsgBuf); i > 0; v4 = lpMsgBuf )
  {
    v6 = v4[i - 1];
    if ( v6 != 10 && v6 != 13 )
      break;
    v4[--i] = 0;
  }
  this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: v4);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  v7 = lpMsgBuf;
  this->m_bErrorSignal = true;
  LocalFree(hMem: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1008FE30
// Name: public: virtual void CTCPConnectSocket_Listener::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPConnectSocket_Listener::Release(CTCPConnectSocket_Listener *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CTCPConnectSocket_Listener *, int))this->dtr_CTCPConnectSocket_Listener)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1008FE80
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Listener::Create(class IHandlerCreator __near *,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__cdecl CTCPConnectSocket_Listener::Create(
        IHandlerCreator *pHandlerCreator,
        unsigned __int16 port,
        int nQueueLength)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  SOCKET v5; // eax
  int v6; // ecx
  CIPAddr addr; // [esp+4h] [ebp-8h] BYREF

  v3 = MemAlloc_Alloc(nSize: 0xCu);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  *v3 = &CTCPConnectSocket_Listener::`vftable';
  v3[1] = -1;
  if ( nQueueLength < 0 )
    _Error(
      a1: "CTCPConnectSocket_Listener::Create - SOMAXCONN not allowed - causes some XP SP2 systems to stop receiving any netw"
      "ork data (systemwide).");
  CIPAddr::CIPAddr(this: &addr, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: port);
  v5 = TCPBind(pAddr: &addr);
  v4[1] = v5;
  if ( v5 == -1 )
    goto LABEL_10;
  v6 = 0x7FFFFFFF;
  if ( nQueueLength != -1 )
    v6 = nQueueLength;
  if ( listen(s: v5, backlog: v6) != 0 )
  {
LABEL_10:
    (*(void (__thiscall **)(_DWORD *))*v4)(a1: v4);
    return nullptr;
  }
  else
  {
    v4[2] = pHandlerCreator;
    return (ITCPConnectSocket *)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FF20
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateListener(class IHandlerCreator __near *,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__cdecl ThreadedTCP_CreateListener(
        IHandlerCreator *pHandlerCreator,
        unsigned __int16 port,
        int nQueueLength)
{
  return CTCPConnectSocket_Listener::Create(pHandlerCreator, port, nQueueLength);
}

//------------------------------------------------------------------------------
// Address: 0x1008FF30
// Name: private: bool CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(CThreadedTCPSocket *this)
{
  CThreadedTCPSocket::SendData_t *m_Element; // eax
  int v3; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-38h]
  _WSABUF buf; // [esp+8h] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+18h] [ebp-4h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Element = this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element;
  buf.len = m_Element->m_Len;
  buf.buf = m_Element->m_Payload;
  this->m_nBytesToTransfer = m_Element->m_Len;
  this->m_bWaitingForSendCompletion = true;
  CCriticalSectionLock::Unlock(this: &csLock);
  m_Socket = this->m_Socket;
  dwNumBytesSent = 0;
  v3 = WSASend(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesSent: &dwNumBytesSent,
         dwFlags: 0,
         lpOverlapped: &this->m_SendOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FFF0
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalRecv(void __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalRecv(
        CThreadedTCPSocket *this,
        char *pDest,
        int destSize,
        unsigned int bContinuation,
        unsigned int bWaitingForSize)
{
  int v6; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-2Ch]
  _WSABUF buf; // [esp+8h] [ebp-8h] BYREF

  buf.len = destSize;
  buf.buf = pDest;
  if ( (_BYTE)bContinuation == 0 )
  {
    this->m_bWaitingForSize = bWaitingForSize;
    this->m_nBytesToReceive = destSize;
    this->m_nBytesReceivedSoFar = 0;
  }
  m_Socket = this->m_Socket;
  bContinuation = 0;
  bWaitingForSize = 0;
  v6 = WSARecv(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &bWaitingForSize,
         lpFlags: &bContinuation,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v6 == 0 || v6 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100901C0
// Name: private: bool CThreadedTCPSocket::RecvThread_WaitToReceiveSize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_WaitToReceiveSize(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  int v3; // edi
  unsigned int Error; // eax
  _WSABUF Buffers; // [esp+8h] [ebp-10h] BYREF
  unsigned int NumberOfBytesRecvd; // [esp+10h] [ebp-8h] BYREF
  unsigned int Flags; // [esp+14h] [ebp-4h] BYREF

  Buffers.len = 4;
  this->m_nBytesToReceive = 4;
  m_Socket = this->m_Socket;
  Buffers.buf = (char *)&this->m_NextPacketLen;
  this->m_bWaitingForSize = true;
  this->m_nBytesReceivedSoFar = 0;
  Flags = 0;
  NumberOfBytesRecvd = 0;
  v3 = WSARecv(
         s: m_Socket,
         lpBuffers: &Buffers,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &NumberOfBytesRecvd,
         lpFlags: &Flags,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10090260
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(
        CThreadedTCPSocket *this,
        signed int dwTransfer)
{
  int m_nBytesToReceive; // eax
  int m_nBytesReceivedSoFar; // edi
  bool v6; // zf
  char *p_m_NextPacketLen; // edx
  int m_NextPacketLen; // eax
  CTCPPacket *v9; // eax
  char pDest[512]; // [esp+8h] [ebp-400h] BYREF
  char str[512]; // [esp+208h] [ebp-200h] BYREF

  m_nBytesToReceive = this->m_nBytesToReceive;
  m_nBytesReceivedSoFar = this->m_nBytesReceivedSoFar;
  if ( dwTransfer > m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    V_snprintf(
      pDest: str,
      maxLen: 0x200u,
      pFormat: "Invalid # bytes received (%d) in recv thread (should be %d)",
      dwTransfer,
      m_nBytesToReceive);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  if ( dwTransfer < m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    v6 = !this->m_bWaitingForSize;
    this->m_nBytesReceivedSoFar = m_nBytesReceivedSoFar + dwTransfer;
    p_m_NextPacketLen = (char *)&this->m_NextPacketLen;
    if ( v6 )
      p_m_NextPacketLen = this->m_pRecvBuffer->m_Data;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: &p_m_NextPacketLen[m_nBytesReceivedSoFar + dwTransfer],
             destSize: m_nBytesToReceive - (m_nBytesReceivedSoFar + dwTransfer),
             bContinuation: 1u,
             bWaitingForSize: 0);
  }
  if ( !this->m_bWaitingForSize )
  {
    this->m_pHandler->OnPacketReceived(this: this->m_pHandler, a2: this->m_pRecvBuffer);
    this->m_pRecvBuffer = nullptr;
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  }
  m_NextPacketLen = this->m_NextPacketLen;
  if ( m_NextPacketLen == -12345 )
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  if ( m_NextPacketLen < 1 || m_NextPacketLen > 78643200 )
  {
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "Invalid packet size in RecvThread (size = %d)", this->m_NextPacketLen);
    CThreadedTCPSocket::HandleError(this, errorCode: 0, pErrorString: pDest);
    return 0;
  }
  else
  {
    v9 = (CTCPPacket *)MemAlloc_Alloc(nSize: m_NextPacketLen + 11);
    this->m_pRecvBuffer = v9;
    v9->m_UserData = 0;
    this->m_pRecvBuffer->m_Len = this->m_NextPacketLen;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: this->m_pRecvBuffer->m_Data,
             destSize: this->m_pRecvBuffer->m_Len,
             bContinuation: 0,
             bWaitingForSize: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100903E0
// Name: private: unsigned long CThreadedTCPSocket::RecvThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::RecvThreadFn(CThreadedTCPSocket *this)
{
  DWORD v3; // eax
  bool i; // zf
  unsigned int Error; // eax
  DWORD LastError; // eax
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int dwFlags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  void *handles[2]; // [esp+20Ch] [ebp-8h] BYREF

  if ( CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this) == 0 )
    return 1;
  handles[0] = CTCPPacket::GetUserData(this: &this->m_hExitThreadsEvent);
  handles[1] = CTCPPacket::GetUserData(this: &this->m_hRecvEvent);
  v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  for ( i = v3 == 258; v3 <= 0x102; i = v3 == 258 )
  {
    if ( i )
    {
      if ( g_bHandleTimeouts )
      {
        this->m_pHandler->OnError(this: this->m_pHandler, a2: 1, a3: "Connection timed out");
LABEL_17:
        CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
        this->m_bErrorSignal = true;
        return 1;
      }
    }
    else
    {
      if ( v3 == 0 )
        return 0;
      if ( v3 != 1 )
        goto LABEL_13;
      if ( !WSAGetOverlappedResult(
              s: this->m_Socket,
              lpOverlapped: &this->m_RecvOverlapped,
              lpcbTransfer: &cbTransfer,
              fWait: true,
              lpdwFlags: &dwFlags) )
      {
        Error = WSAGetLastError();
        CThreadedTCPSocket::HandleError(this, errorValue: Error);
        return 1;
      }
      if ( CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(this, dwTransfer: cbTransfer) == 0 )
        return 1;
    }
    v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  }
  if ( v3 != -1 )
  {
LABEL_13:
    V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v3);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    goto LABEL_17;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090550
// Name: private: static unsigned long CThreadedTCPSocket::StaticRecvThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticRecvThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::RecvThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x100905E0
// Name: private: CThreadedTCPSocket::CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__thiscall CThreadedTCPSocket::CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // eax

  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hReadyToSendEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hSendCompletionEvent);
  CCriticalSection::CCriticalSection(this: &this->m_SendCS);
  this->m_SendDatas.m_Memory.m_pMemory = nullptr;
  this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  this->m_SendDatas.m_Memory.m_nGrowSize = 0;
  this->m_SendDatas.m_LastAlloc.index = -1;
  m_pMemory = this->m_SendDatas.m_Memory.m_pMemory;
  this->m_SendDatas.m_Head = -1;
  this->m_SendDatas.m_Tail = -1;
  this->m_SendDatas.m_FirstFree = -1;
  this->m_SendDatas.m_ElementCount = 0;
  this->m_SendDatas.m_NumAlloced = 0;
  this->m_SendDatas.m_pElements = m_pMemory;
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hRecvEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hExitThreadsEvent);
  CIPAddr::CIPAddr(this: &this->m_RemoteAddr);
  this->m_Socket = -1;
  this->m_pHandler = nullptr;
  *(_QWORD *)&this->m_SendOverlapped.Internal = 0;
  *(_QWORD *)&this->m_SendOverlapped.Offset = 0;
  this->m_SendOverlapped.hEvent = nullptr;
  *(_QWORD *)&this->m_RecvOverlapped.Internal = 0;
  *(_QWORD *)&this->m_RecvOverlapped.Offset = 0;
  this->m_RecvOverlapped.hEvent = nullptr;
  this->m_nBytesToReceive = -1;
  this->m_bWaitingForSendCompletion = false;
  this->m_bWaitingForSize = false;
  this->m_bErrorSignal = false;
  this->m_pRecvBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100906D0
// Name: public: virtual void CThreadedTCPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Release(CThreadedTCPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CThreadedTCPSocket *, int))this->dtr_CThreadedTCPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100906E0
// Name: public: virtual class CIPAddr CThreadedTCPSocket::GetRemoteAddr(void)const
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CThreadedTCPSocket::GetRemoteAddr(CThreadedTCPSocket *this, CIPAddr *result)
{
  int v2; // edx
  unsigned __int16 port; // cx

  v2 = *(_DWORD *)this->m_RemoteAddr.ip;
  port = this->m_RemoteAddr.port;
  *(_DWORD *)result->ip = v2;
  result->port = port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10090700
// Name: public: virtual bool CThreadedTCPSocket::Send(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::Send(CThreadedTCPSocket *this, const void *pData, int len)
{
  return this->SendChunks(this, a2: &pData, a3: &len, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10090720
// Name: public: virtual class ITCPSocketHandler __near * CThreadedTCPSocket::GetHandler(void)
// Source: json
//------------------------------------------------------------------------------
ITCPSocketHandler *__thiscall CThreadedTCPSocket::GetHandler(CThreadedTCPSocket *this)
{
  return this->m_pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x10090730
// Name: private: void CThreadedTCPSocket::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Term(CThreadedTCPSocket *this)
{
  void *m_hSendThread; // eax
  void *m_hRecvThread; // eax
  ITCPSocketHandler *m_pHandler; // ecx

  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  m_hSendThread = this->m_hSendThread;
  if ( m_hSendThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hSendThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hSendThread);
    this->m_hSendThread = nullptr;
  }
  m_hRecvThread = this->m_hRecvThread;
  if ( m_hRecvThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hRecvThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hRecvThread);
    this->m_hRecvThread = nullptr;
  }
  CEvent::ResetEvent(this: &this->m_hExitThreadsEvent);
  if ( this->m_Socket != -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  if ( this->m_bDeleteHandler )
  {
    m_pHandler = this->m_pHandler;
    if ( m_pHandler != nullptr )
    {
      m_pHandler->Release(this: m_pHandler, a2: false);
      this->m_pHandler = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100907E0
// Name: public: virtual bool CThreadedTCPSocket::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::IsValid(CThreadedTCPSocket *this)
{
  return !this->m_bErrorSignal;
}

//------------------------------------------------------------------------------
// Address: 0x100907F0
// Name: private: virtual CThreadedTCPSocket::~CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::~CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CThreadedTCPSocket::Term(this);
  CEvent::~CEvent(this: &this->m_hExitThreadsEvent);
  CEvent::~CEvent(this: &this->m_hRecvEvent);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_SendDatas);
  if ( this->m_SendDatas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SendDatas.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendDatas.m_Memory.m_pMemory);
      this->m_SendDatas.m_Memory.m_pMemory = nullptr;
    }
    this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  }
  CCriticalSection::~CCriticalSection(this: &this->m_SendCS);
  CEvent::~CEvent(this: &this->m_hSendCompletionEvent);
  CEvent::~CEvent(this: &this->m_hReadyToSendEvent);
}

//------------------------------------------------------------------------------
// Address: 0x100908B0
// Name: private: bool CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  unsigned int Error; // eax
  int m_Head; // ebx
  bool v6; // cc
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int flags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  CCriticalSectionLock csLock; // [esp+20Ch] [ebp-8h] BYREF

  m_Socket = this->m_Socket;
  this->m_bWaitingForSendCompletion = false;
  if ( WSAGetOverlappedResult(
         s: m_Socket,
         lpOverlapped: &this->m_SendOverlapped,
         lpcbTransfer: &cbTransfer,
         fWait: true,
         lpdwFlags: &flags) )
  {
    if ( cbTransfer == this->m_nBytesToTransfer )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &csLock);
      free(pMem: this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element);
      m_Head = this->m_SendDatas.m_Head;
      CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_SendDatas,
        elem: m_Head);
      this->m_SendDatas.m_Memory.m_pMemory[m_Head].m_Next = this->m_SendDatas.m_FirstFree;
      this->m_SendDatas.m_FirstFree = m_Head;
      v6 = this->m_SendDatas.m_ElementCount <= 0;
      this->m_bWaitingForSendCompletion = false;
      if ( !v6 )
        CEvent::SetEvent(this: &this->m_hReadyToSendEvent);
      CCriticalSectionLock::Unlock(this: &csLock);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    }
    else
    {
      V_snprintf(
        pDest: str,
        maxLen: 0x200u,
        pFormat: "Invalid # bytes transferred (%d) in send thread (should be %d)",
        cbTransfer,
        this->m_nBytesToTransfer);
      this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
      CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
      this->m_bErrorSignal = true;
      return 0;
    }
  }
  else
  {
    Error = WSAGetLastError();
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100909E0
// Name: private: bool CThreadedTCPSocket::InternalSend(void const __near * const __near *,int const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::InternalSend(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks,
        bool bPrependLength)
{
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // esi
  int v10; // eax
  int v11; // esi
  int *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  unsigned int *v15; // esi
  int v16; // ebx
  CThreadedTCPSocket *v17; // ebx
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int> > *p_m_SendDatas; // esi
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // edx
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // ecx
  int v24; // edx
  int m_Tail; // edi
  CThreadedTCPSocket::SendData_t **p_m_Element; // esi
  CCriticalSectionLock csLock; // [esp+Ch] [ebp-Ch] BYREF
  CThreadedTCPSocket *v29; // [esp+14h] [ebp-4h]
  CThreadedTCPSocket::SendData_t *pSendData; // [esp+24h] [ebp+Ch]
  int bPrependLengtha; // [esp+2Ch] [ebp+14h]

  v6 = nChunks;
  v29 = this;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( nChunks >= 2 )
  {
    do
    {
      v7 += *(_DWORD *)&pChunkLengths[4 * v10];
      v8 += *(_DWORD *)&pChunkLengths[4 * v10 + 4];
      v10 += 2;
    }
    while ( v10 < nChunks - 1 );
    v6 = nChunks;
  }
  if ( v10 < v6 )
    v9 = *(_DWORD *)&pChunkLengths[4 * v10];
  v11 = v8 + v7 + v9;
  if ( bPrependLength )
  {
    if ( v11 == 0 )
      return 1;
    v11 += 4;
  }
  v12 = (int *)MemAlloc_Alloc(nSize: v11 + 7);
  pSendData = (CThreadedTCPSocket::SendData_t *)v12;
  *v12 = v11;
  v13 = (unsigned __int8 *)(v12 + 1);
  if ( bPrependLength )
  {
    *(_DWORD *)v13 = v11 - 4;
    v13 = (unsigned __int8 *)(v12 + 2);
  }
  if ( nChunks > 0 )
  {
    v14 = (char *)pChunks - pChunkLengths;
    v15 = (unsigned int *)pChunkLengths;
    bPrependLengtha = (char *)pChunks - pChunkLengths;
    v16 = nChunks;
    while ( 1 )
    {
      memcpy(dst: v13, src: *(unsigned __int8 **)((char *)v15 + v14), count: *v15);
      v13 += *v15++;
      if ( --v16 == 0 )
        break;
      v14 = bPrependLengtha;
    }
  }
  v17 = v29;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &v29->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  p_m_SendDatas = &v17->m_SendDatas;
  v19 = CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal(
          this: &v17->m_SendDatas,
          multilist: false);
  if ( v19 != -1 )
  {
    if ( v19 >= 0 && v19 < v17->m_SendDatas.m_Memory.m_nAllocationCount && v19 <= v17->m_SendDatas.m_LastAlloc.index )
    {
      v20 = (int)&p_m_SendDatas->m_Memory.m_pMemory[v19];
      if ( *(_DWORD *)(v20 + 4) != v19 )
      {
        v21 = *(_DWORD *)(v20 + 4);
        if ( v21 == -1 )
          v17->m_SendDatas.m_Head = *(_DWORD *)(v20 + 8);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v21].m_Next = *(_DWORD *)(v20 + 8);
        v22 = *(_DWORD *)(v20 + 8);
        if ( v22 == -1 )
          v17->m_SendDatas.m_Tail = *(_DWORD *)(v20 + 4);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v22].m_Previous = *(_DWORD *)(v20 + 4);
        v17 = v29;
        *(_DWORD *)(v20 + 8) = v19;
        *(_DWORD *)(v20 + 4) = v19;
        --p_m_SendDatas->m_ElementCount;
      }
    }
    m_pMemory = p_m_SendDatas->m_Memory.m_pMemory;
    v24 = v19;
    m_pMemory[v24].m_Next = -1;
    m_Tail = p_m_SendDatas->m_Tail;
    m_pMemory[v24].m_Previous = m_Tail;
    p_m_SendDatas->m_Tail = v19;
    if ( m_Tail == -1 )
      p_m_SendDatas->m_Head = v19;
    else
      p_m_SendDatas->m_Memory.m_pMemory[m_Tail].m_Next = v19;
    ++p_m_SendDatas->m_ElementCount;
    p_m_Element = &p_m_SendDatas->m_Memory.m_pMemory[v24].m_Element;
    if ( p_m_Element != nullptr )
      *p_m_Element = pSendData;
  }
  CEvent::SetEvent(this: &v17->m_hReadyToSendEvent);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090B70
// Name: private: unsigned long CThreadedTCPSocket::SendThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::SendThreadFn(CThreadedTCPSocket *this)
{
  void *UserData; // eax
  bool v3; // zf
  DWORD v4; // eax
  DWORD v5; // eax
  int m_ElementCount; // edi
  DWORD LastError; // eax
  char str[512]; // [esp+Ch] [ebp-21Ch] BYREF
  void *handles[3]; // [esp+20Ch] [ebp-1Ch] BYREF
  void *pChunks; // [esp+218h] [ebp-10h] BYREF
  int pChunkLengths; // [esp+21Ch] [ebp-Ch] BYREF
  CCriticalSectionLock v13; // [esp+220h] [ebp-8h] BYREF

  while ( 1 )
  {
    while ( 1 )
    {
      handles[0] = CTCPPacket::GetUserData(this: &this->m_hExitThreadsEvent);
      handles[1] = CTCPPacket::GetUserData(this: &this->m_hSendCompletionEvent);
      UserData = CTCPPacket::GetUserData(this: &this->m_hReadyToSendEvent);
      v3 = !this->m_bWaitingForSendCompletion;
      handles[2] = UserData;
      v4 = 3;
      if ( !v3 )
        v4 = 2;
      v5 = WaitForMultipleObjects(nCount: v4, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0xBB8u);
      if ( v5 > 2 )
        break;
      if ( v5 == 2 )
      {
        if ( CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(this) == 0 )
          return 1;
      }
      else
      {
        if ( v5 == 0 )
          return 0;
        if ( CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(this) == 0 )
          return 1;
      }
    }
    if ( v5 != 258 )
      break;
    if ( g_bHandleTimeouts )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &v13, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &v13);
      m_ElementCount = this->m_SendDatas.m_ElementCount;
      CCriticalSectionLock::Unlock(this: &v13);
      if ( m_ElementCount == 0 )
      {
        pChunks = &g_KeepaliveSentinel;
        pChunkLengths = 4;
        CThreadedTCPSocket::InternalSend(
          this,
          (const void *const *)&pChunks,
          (char *)&pChunkLengths,
          nChunks: 1,
          bPrependLength: false);
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &v13);
    }
  }
  if ( v5 != -1 )
  {
    V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v5);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090CF0
// Name: private: static unsigned long CThreadedTCPSocket::StaticSendThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticSendThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::SendThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x10090D00
// Name: public: virtual bool CThreadedTCPSocket::SendChunks(void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendChunks(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  if ( this->m_bErrorSignal )
    return 0;
  else
    return CThreadedTCPSocket::InternalSend(this, pChunks, pChunkLengths, nChunks, bPrependLength: true);
}

//------------------------------------------------------------------------------
// Address: 0x10090D30
// Name: private: bool CThreadedTCPSocket::Init(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::Init(
        CThreadedTCPSocket *this,
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  unsigned __int16 port; // dx
  unsigned int v6; // eax
  HANDLE v8; // eax
  void *m_hSendThread; // ecx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  unsigned int dwRecvThreadID; // [esp+Ch] [ebp-4h] BYREF

  port = remoteAddr.port;
  v6 = iSocket;
  *(_DWORD *)this->m_RemoteAddr.ip = *(_DWORD *)remoteAddr.ip;
  this->m_pHandler = pHandler;
  this->m_RemoteAddr.port = port;
  LOBYTE(port) = bDeleteHandler;
  this->m_Socket = v6;
  this->m_bDeleteHandler = port;
  iSocket = 1;
  setsockopt(s: v6, level: 6, optname: 1, optval: (const char *)&iSocket, optlen: 4);
  m_Socket = this->m_Socket;
  bDeleteHandler = 196609;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 128, optval: (const char *)&bDeleteHandler, optlen: 4);
  CEvent::Init(this: &this->m_hExitThreadsEvent, bManualReset: true, bInitialState: false);
  CEvent::Init(this: &this->m_hSendCompletionEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hReadyToSendEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hRecvEvent, bManualReset: false, bInitialState: false);
  this->m_SendOverlapped.hEvent = CTCPPacket::GetUserData(this: &this->m_hSendCompletionEvent);
  this->m_RecvOverlapped.hEvent = CTCPPacket::GetUserData(this: &this->m_hRecvEvent);
  this->m_hSendThread = CreateThread(
                          lpThreadAttributes: nullptr,
                          dwStackSize: 0,
                          lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticSendThreadFn,
                          lpParameter: this,
                          dwCreationFlags: 4u,
                          lpThreadId: (LPDWORD)&pHandler);
  v8 = CreateThread(
         lpThreadAttributes: nullptr,
         dwStackSize: 0,
         lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticRecvThreadFn,
         lpParameter: this,
         dwCreationFlags: 4u,
         lpThreadId: &dwRecvThreadID);
  m_hSendThread = this->m_hSendThread;
  this->m_hRecvThread = v8;
  if ( m_hSendThread == nullptr || v8 == nullptr )
    return 0;
  if ( g_bSetTCPSocketThreadPriorities )
  {
    SetThreadPriority(hThread: m_hSendThread, nPriority: -2);
    SetThreadPriority(hThread: this->m_hRecvThread, nPriority: -2);
  }
  this->m_pHandler->Init(this: this->m_pHandler, a2: this);
  ResumeThread(hThread: this->m_hSendThread);
  ResumeThread(hThread: this->m_hRecvThread);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090E90
// Name: public: static class IThreadedTCPSocket __near * CThreadedTCPSocket::Create(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__cdecl CThreadedTCPSocket::Create(
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  CThreadedTCPSocket *v4; // eax
  CThreadedTCPSocket *v5; // esi

  v4 = (CThreadedTCPSocket *)MemAlloc_Alloc(nSize: 0xF8u);
  if ( v4 != nullptr )
    v5 = CThreadedTCPSocket::CThreadedTCPSocket(this: v4);
  else
    v5 = nullptr;
  if ( CThreadedTCPSocket::Init(this: v5, iSocket, remoteAddr, pHandler, bDeleteHandler) != 0 )
    return v5;
  v5->Release(this: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10090EF0
// Name: public: virtual bool CTCPConnectSocket_Listener::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTCPConnectSocket_Listener::Update(
        CTCPConnectSocket_Listener *this,
        int pSocket,
        unsigned int milliseconds)
{
  CThreadedTCPSocket **v3; // ebx
  int v5; // eax
  SOCKET m_Socket; // edx
  SOCKET v7; // edi
  ITCPSocketHandler *v8; // eax
  CThreadedTCPSocket *v9; // eax
  fd_set readSet; // [esp+Ch] [ebp-124h] BYREF
  sockaddr_in addr; // [esp+110h] [ebp-20h] BYREF
  timeval timeVal; // [esp+120h] [ebp-10h] BYREF
  CIPAddr connectedAddr; // [esp+128h] [ebp-8h] BYREF

  v3 = (CThreadedTCPSocket **)pSocket;
  *(_DWORD *)pSocket = 0;
  if ( this->m_Socket == -1 )
    return 0;
  readSet.fd_array[0] = this->m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  timeVal.tv_usec = 1000 * milliseconds;
  v5 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v5 > 0 )
  {
    m_Socket = this->m_Socket;
    pSocket = 16;
    v7 = accept(s: m_Socket, (struct sockaddr *)&addr, addrlen: &pSocket);
    if ( v7 != -1 )
    {
      CIPAddr::CIPAddr(this: &connectedAddr);
      SockAddrToIPAddr(pIn: &addr, pOut: &connectedAddr);
      v8 = this->m_pHandler->CreateNewHandler(this: this->m_pHandler);
      v9 = CThreadedTCPSocket::Create(iSocket: v7, remoteAddr: connectedAddr, pHandler: v8, bDeleteHandler: 1);
      if ( v9 == nullptr )
      {
        closesocket(s: this->m_Socket);
        this->m_Socket = -1;
        return 0;
      }
      *v3 = v9;
    }
  }
  else if ( v5 == -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091010
// Name: public: virtual bool CTCPConnectSocket_Connector::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::Update(
        CTCPConnectSocket_Connector *this,
        IThreadedTCPSocket **pSocket,
        unsigned int milliseconds)
{
  int v4; // eax
  SOCKET m_Socket; // edx
  ITCPSocketHandler *v7; // eax
  CThreadedTCPSocket *v8; // eax
  SOCKET v9; // [esp-4h] [ebp-114h]
  fd_set writeSet; // [esp+4h] [ebp-10Ch] BYREF
  timeval timeVal; // [esp+108h] [ebp-8h] BYREF

  *pSocket = nullptr;
  if ( this->m_bError )
    return false;
  if ( this->m_Socket == -1 )
    return true;
  if ( !this->m_bConnected )
  {
    writeSet.fd_array[0] = this->m_Socket;
    timeVal.tv_sec = 0;
    timeVal.tv_usec = 1000 * milliseconds;
    writeSet.fd_count = 1;
    v4 = select(nfds: 0, readfds: nullptr, writefds: &writeSet, exceptfds: nullptr, timeout: &timeVal);
    if ( v4 <= 0 )
    {
      if ( v4 == -1 )
        return CTCPConnectSocket_Connector::EnterErrorMode(this);
    }
    else
    {
      this->m_bConnected = true;
    }
    if ( !this->m_bConnected )
      return true;
  }
  m_Socket = this->m_Socket;
  milliseconds = 0;
  if ( ioctlsocket(s: m_Socket, cmd: -2147195266, argp: &milliseconds) != 0 )
  {
    v9 = this->m_Socket;
    this->m_bError = true;
    closesocket(s: v9);
    this->m_Socket = -1;
    return false;
  }
  v7 = this->m_pHandlerCreator->CreateNewHandler(this: this->m_pHandlerCreator);
  v8 = CThreadedTCPSocket::Create(
         iSocket: this->m_Socket,
         remoteAddr: this->m_RemoteAddr,
         pHandler: v7,
         bDeleteHandler: 1);
  if ( v8 != nullptr )
  {
    this->m_Socket = -1;
    *pSocket = v8;
    return true;
  }
  return CTCPConnectSocket_Connector::EnterErrorMode(this);
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1002EF90
// Name: TCPBind
// Source: json
//------------------------------------------------------------------------------
SOCKET __cdecl TCPBind(const CIPAddr *pAddr)
{
  SOCKET v1; // esi
  sockaddr_in addr; // [esp+4h] [ebp-10h] BYREF

  v1 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v1 != -1 )
  {
    IPAddrToSockAddr(pIn: pAddr, pOut: &addr);
    if ( bind(s: v1, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
      return v1;
    closesocket(s: v1);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1002EFF0
// Name: public: int CTCPPacket::GetUserData(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CTCPPacket::GetUserData(CEvent *this)
{
  return this->m_hEvent;
}

//------------------------------------------------------------------------------
// Address: 0x1002F000
// Name: public: void CTCPPacket::SetUserData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPPacket::SetUserData(CTCPPacket *this, int userData)
{
  this->m_UserData = userData;
}

//------------------------------------------------------------------------------
// Address: 0x1002F010
// Name: public: void CTCPPacket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPPacket::Release(CTCPPacket *this)
{
  free(pBlock: this);
}

//------------------------------------------------------------------------------
// Address: 0x1002F020
// Name: private: void CThreadedTCPSocket::HandleError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, int errorCode, const char *pErrorString)
{
  this->m_pHandler->OnError(this: this->m_pHandler, a2: errorCode, a3: pErrorString);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  this->m_bErrorSignal = true;
}

//------------------------------------------------------------------------------
// Address: 0x1002F060
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Connector::Create(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl CTCPConnectSocket_Connector::Create(
        const CIPAddr *connectAddr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  CIPAddr *v3; // eax
  CIPAddr *v4; // esi
  SOCKET v5; // edi
  int v6; // eax
  SOCKET v8; // [esp-Ch] [ebp-38h]
  sockaddr_in addr; // [esp+8h] [ebp-24h] BYREF
  sockaddr_in pOut; // [esp+18h] [ebp-14h] BYREF
  unsigned int val; // [esp+28h] [ebp-4h] BYREF

  v3 = (CIPAddr *)operator new(size: 0x18u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3->ip = &CTCPConnectSocket_Connector::`vftable';
    CIPAddr::CIPAddr(this: v3 + 2);
    *(_DWORD *)&v4[1].ip[2] = -1;
    v4->port = 0;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = WSASocketA(af: 2, type: 1, protocol: 6, lpProtocolInfo: nullptr, g: 0, dwFlags: 1u);
  if ( v5 == -1 )
    goto LABEL_7;
  IPAddrToSockAddr(pIn: localAddr, &pOut);
  if ( bind(s: v5, name: (const struct sockaddr *)&pOut, namelen: 16) != 0 )
  {
    closesocket(s: v5);
LABEL_7:
    v5 = -1;
  }
  *(_DWORD *)&v4[1].ip[2] = v5;
  if ( v5 != -1 )
  {
    IPAddrToSockAddr(pIn: connectAddr, pOut: &addr);
    val = 1;
    if ( ioctlsocket(s: *(_DWORD *)&v4[1].ip[2], cmd: -2147195266, argp: &val) == 0 )
    {
      v4[2] = *connectAddr;
      v8 = *(_DWORD *)&v4[1].ip[2];
      *(_DWORD *)&v4[3].ip[2] = pHandlerCreator;
      v6 = connect(s: v8, name: (const struct sockaddr *)&addr, namelen: 16);
      if ( v6 == 0 )
      {
        HIBYTE(v4->port) = 1;
        return v4;
      }
      if ( v6 == -1 && WSAGetLastError() == 10035 )
        return v4;
    }
  }
  (**(void (__thiscall ***)(CIPAddr *))v4->ip)(a1: v4);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002F180
// Name: public: bool CTCPConnectSocket_Connector::EnterErrorMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::EnterErrorMode(CTCPConnectSocket_Connector *this)
{
  SOCKET m_Socket; // [esp-4h] [ebp-8h]

  m_Socket = this->m_Socket;
  this->m_bError = true;
  closesocket(s: m_Socket);
  this->m_Socket = -1;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1002F1E0
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateConnector(class CIPAddr const __near &,class CIPAddr const __near &,class IHandlerCreator __near *)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__cdecl ThreadedTCP_CreateConnector(
        const CIPAddr *addr,
        const CIPAddr *localAddr,
        IHandlerCreator *pHandlerCreator)
{
  return CTCPConnectSocket_Connector::Create(connectAddr: addr, localAddr, pHandlerCreator);
}

//------------------------------------------------------------------------------
// Address: 0x1002F1F0
// Name: void ThreadedTCP_EnableTimeouts(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadedTCP_EnableTimeouts(bool bEnable)
{
  g_bHandleTimeouts = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1002F200
// Name: void ThreadedTCP_SetTCPSocketThreadPriorities(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ThreadedTCP_SetTCPSocketThreadPriorities(bool bSetTCPSocketThreadPriorities)
{
  g_bSetTCPSocketThreadPriorities = bSetTCPSocketThreadPriorities;
}

//------------------------------------------------------------------------------
// Address: 0x1002F210
// Name: private: void CThreadedTCPSocket::HandleError(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::HandleError(CThreadedTCPSocket *this, unsigned int errorValue)
{
  DWORD LastError; // eax
  char *v4; // edx
  int i; // eax
  char v6; // cl
  char *v7; // [esp-4h] [ebp-10h]
  char *lpMsgBuf; // [esp+8h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  v4 = lpMsgBuf;
  for ( i = strlen(lpMsgBuf); i > 0; v4 = lpMsgBuf )
  {
    v6 = v4[i - 1];
    if ( v6 != 10 && v6 != 13 )
      break;
    v4[--i] = 0;
  }
  this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: v4);
  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  v7 = lpMsgBuf;
  this->m_bErrorSignal = true;
  LocalFree(hMem: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1002F2A0
// Name: public: virtual void CTCPConnectSocket_Listener::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTCPConnectSocket_Listener::Release(CTCPConnectSocket_Listener *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CTCPConnectSocket_Listener *, int))this->dtr_CTCPConnectSocket_Listener)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F2F0
// Name: public: static class ITCPConnectSocket __near * CTCPConnectSocket_Listener::Create(class IHandlerCreator __near *,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__cdecl CTCPConnectSocket_Listener::Create(
        IHandlerCreator *pHandlerCreator,
        unsigned __int16 port,
        int nQueueLength)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  SOCKET v5; // eax
  int v6; // ecx
  CIPAddr addr; // [esp+4h] [ebp-8h] BYREF

  v3 = operator new(size: 0xCu);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  *v3 = &CTCPConnectSocket_Listener::`vftable';
  v3[1] = -1;
  if ( nQueueLength < 0 )
    _Error(
      a1: "CTCPConnectSocket_Listener::Create - SOMAXCONN not allowed - causes some XP SP2 systems to stop receiving any netw"
      "ork data (systemwide).");
  CIPAddr::CIPAddr(this: &addr, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: port);
  v5 = TCPBind(pAddr: &addr);
  v4[1] = v5;
  if ( v5 == -1 )
    goto LABEL_10;
  v6 = 0x7FFFFFFF;
  if ( nQueueLength != -1 )
    v6 = nQueueLength;
  if ( listen(s: v5, backlog: v6) != 0 )
  {
LABEL_10:
    (*(void (__thiscall **)(_DWORD *))*v4)(a1: v4);
    return nullptr;
  }
  else
  {
    v4[2] = pHandlerCreator;
    return (ITCPConnectSocket *)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F390
// Name: class ITCPConnectSocket __near * ThreadedTCP_CreateListener(class IHandlerCreator __near *,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__cdecl ThreadedTCP_CreateListener(
        IHandlerCreator *pHandlerCreator,
        unsigned __int16 port,
        int nQueueLength)
{
  return CTCPConnectSocket_Listener::Create(pHandlerCreator, port, nQueueLength);
}

//------------------------------------------------------------------------------
// Address: 0x1002F3A0
// Name: private: bool CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(CThreadedTCPSocket *this)
{
  CThreadedTCPSocket::SendData_t *m_Element; // eax
  int v3; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-38h]
  _WSABUF buf; // [esp+8h] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+18h] [ebp-4h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Element = this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element;
  buf.len = m_Element->m_Len;
  buf.buf = m_Element->m_Payload;
  this->m_nBytesToTransfer = m_Element->m_Len;
  this->m_bWaitingForSendCompletion = true;
  CCriticalSectionLock::Unlock(this: &csLock);
  m_Socket = this->m_Socket;
  dwNumBytesSent = 0;
  v3 = WSASend(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesSent: &dwNumBytesSent,
         dwFlags: 0,
         lpOverlapped: &this->m_SendOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F460
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalRecv(void __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalRecv(
        CThreadedTCPSocket *this,
        char *pDest,
        int destSize,
        unsigned int bContinuation,
        unsigned int bWaitingForSize)
{
  int v6; // edi
  unsigned int Error; // eax
  SOCKET m_Socket; // [esp-1Ch] [ebp-2Ch]
  _WSABUF buf; // [esp+8h] [ebp-8h] BYREF

  buf.len = destSize;
  buf.buf = pDest;
  if ( (_BYTE)bContinuation == 0 )
  {
    this->m_bWaitingForSize = bWaitingForSize;
    this->m_nBytesToReceive = destSize;
    this->m_nBytesReceivedSoFar = 0;
  }
  m_Socket = this->m_Socket;
  bContinuation = 0;
  bWaitingForSize = 0;
  v6 = WSARecv(
         s: m_Socket,
         lpBuffers: &buf,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &bWaitingForSize,
         lpFlags: &bContinuation,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v6 == 0 || v6 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002F630
// Name: private: bool CThreadedTCPSocket::RecvThread_WaitToReceiveSize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_WaitToReceiveSize(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  int v3; // edi
  unsigned int Error; // eax
  _WSABUF Buffers; // [esp+8h] [ebp-10h] BYREF
  unsigned int NumberOfBytesRecvd; // [esp+10h] [ebp-8h] BYREF
  unsigned int Flags; // [esp+14h] [ebp-4h] BYREF

  Buffers.len = 4;
  this->m_nBytesToReceive = 4;
  m_Socket = this->m_Socket;
  Buffers.buf = (char *)&this->m_NextPacketLen;
  this->m_bWaitingForSize = true;
  this->m_nBytesReceivedSoFar = 0;
  Flags = 0;
  NumberOfBytesRecvd = 0;
  v3 = WSARecv(
         s: m_Socket,
         lpBuffers: &Buffers,
         dwBufferCount: 1u,
         lpNumberOfBytesRecvd: &NumberOfBytesRecvd,
         lpFlags: &Flags,
         lpOverlapped: &this->m_RecvOverlapped,
         lpCompletionRoutine: nullptr);
  Error = WSAGetLastError();
  if ( v3 == 0 || v3 == -1 && Error == 997 )
    return 1;
  CThreadedTCPSocket::HandleError(this, errorValue: Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002F6D0
// Name: private: bool CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(
        CThreadedTCPSocket *this,
        signed int dwTransfer)
{
  int m_nBytesToReceive; // eax
  int m_nBytesReceivedSoFar; // edi
  bool v6; // zf
  char *p_m_NextPacketLen; // edx
  int m_NextPacketLen; // eax
  CTCPPacket *v9; // eax
  char pDest[512]; // [esp+8h] [ebp-400h] BYREF
  char str[512]; // [esp+208h] [ebp-200h] BYREF

  m_nBytesToReceive = this->m_nBytesToReceive;
  m_nBytesReceivedSoFar = this->m_nBytesReceivedSoFar;
  if ( dwTransfer > m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    V_snprintf(
      pDest: str,
      maxLen: 0x200u,
      pFormat: "Invalid # bytes received (%d) in recv thread (should be %d)",
      dwTransfer,
      m_nBytesToReceive);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  if ( dwTransfer < m_nBytesToReceive - m_nBytesReceivedSoFar )
  {
    v6 = !this->m_bWaitingForSize;
    this->m_nBytesReceivedSoFar = m_nBytesReceivedSoFar + dwTransfer;
    p_m_NextPacketLen = (char *)&this->m_NextPacketLen;
    if ( v6 )
      p_m_NextPacketLen = this->m_pRecvBuffer->m_Data;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: &p_m_NextPacketLen[m_nBytesReceivedSoFar + dwTransfer],
             destSize: m_nBytesToReceive - (m_nBytesReceivedSoFar + dwTransfer),
             bContinuation: 1u,
             bWaitingForSize: 0);
  }
  if ( !this->m_bWaitingForSize )
  {
    this->m_pHandler->OnPacketReceived(this: this->m_pHandler, a2: this->m_pRecvBuffer);
    this->m_pRecvBuffer = nullptr;
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  }
  m_NextPacketLen = this->m_NextPacketLen;
  if ( m_NextPacketLen == -12345 )
    return CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this);
  if ( m_NextPacketLen < 1 || m_NextPacketLen > 78643200 )
  {
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "Invalid packet size in RecvThread (size = %d)", this->m_NextPacketLen);
    CThreadedTCPSocket::HandleError(this, errorCode: 0, pErrorString: pDest);
    return 0;
  }
  else
  {
    v9 = (CTCPPacket *)malloc(size: m_NextPacketLen + 11);
    this->m_pRecvBuffer = v9;
    v9->m_UserData = 0;
    this->m_pRecvBuffer->m_Len = this->m_NextPacketLen;
    return CThreadedTCPSocket::RecvThread_InternalRecv(
             this,
             pDest: this->m_pRecvBuffer->m_Data,
             destSize: this->m_pRecvBuffer->m_Len,
             bContinuation: 0,
             bWaitingForSize: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F850
// Name: private: unsigned long CThreadedTCPSocket::RecvThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::RecvThreadFn(CThreadedTCPSocket *this)
{
  DWORD v3; // eax
  bool i; // zf
  unsigned int Error; // eax
  DWORD LastError; // eax
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int dwFlags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  void *handles[2]; // [esp+20Ch] [ebp-8h] BYREF

  if ( CThreadedTCPSocket::RecvThread_WaitToReceiveSize(this) == 0 )
    return 1;
  handles[0] = CTCPPacket::GetUserData(this: &this->m_hExitThreadsEvent);
  handles[1] = CTCPPacket::GetUserData(this: &this->m_hRecvEvent);
  v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  for ( i = v3 == 258; v3 <= 0x102; i = v3 == 258 )
  {
    if ( i )
    {
      if ( g_bHandleTimeouts )
      {
        this->m_pHandler->OnError(this: this->m_pHandler, a2: 1, a3: "Connection timed out");
LABEL_17:
        CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
        this->m_bErrorSignal = true;
        return 1;
      }
    }
    else
    {
      if ( v3 == 0 )
        return 0;
      if ( v3 != 1 )
        goto LABEL_13;
      if ( !WSAGetOverlappedResult(
              s: this->m_Socket,
              lpOverlapped: &this->m_RecvOverlapped,
              lpcbTransfer: &cbTransfer,
              fWait: true,
              lpdwFlags: &dwFlags) )
      {
        Error = WSAGetLastError();
        CThreadedTCPSocket::HandleError(this, errorValue: Error);
        return 1;
      }
      if ( CThreadedTCPSocket::RecvThread_InternalHandleRecvCompletion(this, dwTransfer: cbTransfer) == 0 )
        return 1;
    }
    v3 = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0x61A8u);
  }
  if ( v3 != -1 )
  {
LABEL_13:
    V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v3);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    goto LABEL_17;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002F9C0
// Name: private: static unsigned long CThreadedTCPSocket::StaticRecvThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticRecvThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::RecvThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x1002FA50
// Name: private: CThreadedTCPSocket::CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__thiscall CThreadedTCPSocket::CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // eax

  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hReadyToSendEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hSendCompletionEvent);
  CCriticalSection::CCriticalSection(this: &this->m_SendCS);
  this->m_SendDatas.m_Memory.m_pMemory = nullptr;
  this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  this->m_SendDatas.m_Memory.m_nGrowSize = 0;
  this->m_SendDatas.m_LastAlloc.index = -1;
  m_pMemory = this->m_SendDatas.m_Memory.m_pMemory;
  this->m_SendDatas.m_Head = -1;
  this->m_SendDatas.m_Tail = -1;
  this->m_SendDatas.m_FirstFree = -1;
  this->m_SendDatas.m_ElementCount = 0;
  this->m_SendDatas.m_NumAlloced = 0;
  this->m_SendDatas.m_pElements = m_pMemory;
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hRecvEvent);
  CExpressionEvaluator::CExpressionEvaluator(this: &this->m_hExitThreadsEvent);
  CIPAddr::CIPAddr(this: &this->m_RemoteAddr);
  this->m_Socket = -1;
  this->m_pHandler = nullptr;
  *(_QWORD *)&this->m_SendOverlapped.Internal = 0;
  *(_QWORD *)&this->m_SendOverlapped.Offset = 0;
  this->m_SendOverlapped.hEvent = nullptr;
  *(_QWORD *)&this->m_RecvOverlapped.Internal = 0;
  *(_QWORD *)&this->m_RecvOverlapped.Offset = 0;
  this->m_RecvOverlapped.hEvent = nullptr;
  this->m_nBytesToReceive = -1;
  this->m_bWaitingForSendCompletion = false;
  this->m_bWaitingForSize = false;
  this->m_bErrorSignal = false;
  this->m_pRecvBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002FB40
// Name: public: virtual void CThreadedTCPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Release(CThreadedTCPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CThreadedTCPSocket *, int))this->dtr_CThreadedTCPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002FB50
// Name: public: virtual class CIPAddr CThreadedTCPSocket::GetRemoteAddr(void)const
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CThreadedTCPSocket::GetRemoteAddr(CThreadedTCPSocket *this, CIPAddr *result)
{
  int v2; // edx
  unsigned __int16 port; // cx

  v2 = *(_DWORD *)this->m_RemoteAddr.ip;
  port = this->m_RemoteAddr.port;
  *(_DWORD *)result->ip = v2;
  result->port = port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002FB70
// Name: public: virtual bool CThreadedTCPSocket::Send(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::Send(CThreadedTCPSocket *this, const void *pData, int len)
{
  return this->SendChunks(this, a2: &pData, a3: &len, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002FB90
// Name: public: virtual class ITCPSocketHandler __near * CThreadedTCPSocket::GetHandler(void)
// Source: json
//------------------------------------------------------------------------------
ITCPSocketHandler *__thiscall CThreadedTCPSocket::GetHandler(CThreadedTCPSocket *this)
{
  return this->m_pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x1002FBA0
// Name: private: void CThreadedTCPSocket::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::Term(CThreadedTCPSocket *this)
{
  void *m_hSendThread; // eax
  void *m_hRecvThread; // eax
  ITCPSocketHandler *m_pHandler; // ecx

  CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
  m_hSendThread = this->m_hSendThread;
  if ( m_hSendThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hSendThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hSendThread);
    this->m_hSendThread = nullptr;
  }
  m_hRecvThread = this->m_hRecvThread;
  if ( m_hRecvThread != nullptr )
  {
    WaitForSingleObject(hHandle: m_hRecvThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hRecvThread);
    this->m_hRecvThread = nullptr;
  }
  CEvent::ResetEvent(this: &this->m_hExitThreadsEvent);
  if ( this->m_Socket != -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  if ( this->m_bDeleteHandler )
  {
    m_pHandler = this->m_pHandler;
    if ( m_pHandler != nullptr )
    {
      m_pHandler->Release(this: m_pHandler, a2: false);
      this->m_pHandler = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FC50
// Name: public: virtual bool CThreadedTCPSocket::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocket::IsValid(CThreadedTCPSocket *this)
{
  return !this->m_bErrorSignal;
}

//------------------------------------------------------------------------------
// Address: 0x1002FC60
// Name: private: virtual CThreadedTCPSocket::~CThreadedTCPSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocket::~CThreadedTCPSocket(CThreadedTCPSocket *this)
{
  this->__vftable = (CThreadedTCPSocket_vtbl *)&CThreadedTCPSocket::`vftable';
  CThreadedTCPSocket::Term(this);
  CEvent::~CEvent(this: &this->m_hExitThreadsEvent);
  CEvent::~CEvent(this: &this->m_hRecvEvent);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_SendDatas);
  if ( this->m_SendDatas.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SendDatas.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SendDatas.m_Memory.m_pMemory);
      this->m_SendDatas.m_Memory.m_pMemory = nullptr;
    }
    this->m_SendDatas.m_Memory.m_nAllocationCount = 0;
  }
  CCriticalSection::~CCriticalSection(this: &this->m_SendCS);
  CEvent::~CEvent(this: &this->m_hSendCompletionEvent);
  CEvent::~CEvent(this: &this->m_hReadyToSendEvent);
}

//------------------------------------------------------------------------------
// Address: 0x1002FD20
// Name: private: bool CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(CThreadedTCPSocket *this)
{
  SOCKET m_Socket; // eax
  unsigned int Error; // eax
  int m_Head; // ebx
  bool v6; // cc
  char str[512]; // [esp+4h] [ebp-210h] BYREF
  unsigned int flags; // [esp+204h] [ebp-10h] BYREF
  unsigned int cbTransfer; // [esp+208h] [ebp-Ch] BYREF
  CCriticalSectionLock csLock; // [esp+20Ch] [ebp-8h] BYREF

  m_Socket = this->m_Socket;
  this->m_bWaitingForSendCompletion = false;
  if ( WSAGetOverlappedResult(
         s: m_Socket,
         lpOverlapped: &this->m_SendOverlapped,
         lpcbTransfer: &cbTransfer,
         fWait: true,
         lpdwFlags: &flags) )
  {
    if ( cbTransfer == this->m_nBytesToTransfer )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &csLock);
      free(pBlock: this->m_SendDatas.m_Memory.m_pMemory[this->m_SendDatas.m_Head].m_Element);
      m_Head = this->m_SendDatas.m_Head;
      CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_SendDatas,
        elem: m_Head);
      this->m_SendDatas.m_Memory.m_pMemory[m_Head].m_Next = this->m_SendDatas.m_FirstFree;
      this->m_SendDatas.m_FirstFree = m_Head;
      v6 = this->m_SendDatas.m_ElementCount <= 0;
      this->m_bWaitingForSendCompletion = false;
      if ( !v6 )
        CEvent::SetEvent(this: &this->m_hReadyToSendEvent);
      CCriticalSectionLock::Unlock(this: &csLock);
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
      return 1;
    }
    else
    {
      V_snprintf(
        pDest: str,
        maxLen: 0x200u,
        pFormat: "Invalid # bytes transferred (%d) in send thread (should be %d)",
        cbTransfer,
        this->m_nBytesToTransfer);
      this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
      CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
      this->m_bErrorSignal = true;
      return 0;
    }
  }
  else
  {
    Error = WSAGetLastError();
    CThreadedTCPSocket::HandleError(this, errorValue: Error);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FE50
// Name: private: bool CThreadedTCPSocket::InternalSend(void const __near * const __near *,int const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::InternalSend(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks,
        bool bPrependLength)
{
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // esi
  int v10; // eax
  int v11; // esi
  int *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  unsigned int *v15; // esi
  int v16; // ebx
  CThreadedTCPSocket *v17; // ebx
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int> > *p_m_SendDatas; // esi
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  int v22; // edx
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *m_pMemory; // ecx
  int v24; // edx
  int m_Tail; // edi
  CThreadedTCPSocket::SendData_t **p_m_Element; // esi
  CCriticalSectionLock csLock; // [esp+Ch] [ebp-Ch] BYREF
  CThreadedTCPSocket *v29; // [esp+14h] [ebp-4h]
  CThreadedTCPSocket::SendData_t *pSendData; // [esp+24h] [ebp+Ch]
  int bPrependLengtha; // [esp+2Ch] [ebp+14h]

  v6 = nChunks;
  v29 = this;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( nChunks >= 2 )
  {
    do
    {
      v7 += *(_DWORD *)&pChunkLengths[4 * v10];
      v8 += *(_DWORD *)&pChunkLengths[4 * v10 + 4];
      v10 += 2;
    }
    while ( v10 < nChunks - 1 );
    v6 = nChunks;
  }
  if ( v10 < v6 )
    v9 = *(_DWORD *)&pChunkLengths[4 * v10];
  v11 = v8 + v7 + v9;
  if ( bPrependLength )
  {
    if ( v11 == 0 )
      return 1;
    v11 += 4;
  }
  v12 = (int *)malloc(size: v11 + 7);
  pSendData = (CThreadedTCPSocket::SendData_t *)v12;
  *v12 = v11;
  v13 = (unsigned __int8 *)(v12 + 1);
  if ( bPrependLength )
  {
    *(_DWORD *)v13 = v11 - 4;
    v13 = (unsigned __int8 *)(v12 + 2);
  }
  if ( nChunks > 0 )
  {
    v14 = (char *)pChunks - pChunkLengths;
    v15 = (unsigned int *)pChunkLengths;
    bPrependLengtha = (char *)pChunks - pChunkLengths;
    v16 = nChunks;
    while ( 1 )
    {
      memcpy(dst: v13, src: *(unsigned __int8 **)((char *)v15 + v14), count: *v15);
      v13 += *v15++;
      if ( --v16 == 0 )
        break;
      v14 = bPrependLengtha;
    }
  }
  v17 = v29;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &v29->m_SendCS);
  CCriticalSectionLock::Lock(this: &csLock);
  p_m_SendDatas = &v17->m_SendDatas;
  v19 = CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal(
          this: &v17->m_SendDatas,
          multilist: false);
  if ( v19 != -1 )
  {
    if ( v19 >= 0 && v19 < v17->m_SendDatas.m_Memory.m_nAllocationCount && v19 <= v17->m_SendDatas.m_LastAlloc.index )
    {
      v20 = (int)&p_m_SendDatas->m_Memory.m_pMemory[v19];
      if ( *(_DWORD *)(v20 + 4) != v19 )
      {
        v21 = *(_DWORD *)(v20 + 4);
        if ( v21 == -1 )
          v17->m_SendDatas.m_Head = *(_DWORD *)(v20 + 8);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v21].m_Next = *(_DWORD *)(v20 + 8);
        v22 = *(_DWORD *)(v20 + 8);
        if ( v22 == -1 )
          v17->m_SendDatas.m_Tail = *(_DWORD *)(v20 + 4);
        else
          p_m_SendDatas->m_Memory.m_pMemory[v22].m_Previous = *(_DWORD *)(v20 + 4);
        v17 = v29;
        *(_DWORD *)(v20 + 8) = v19;
        *(_DWORD *)(v20 + 4) = v19;
        --p_m_SendDatas->m_ElementCount;
      }
    }
    m_pMemory = p_m_SendDatas->m_Memory.m_pMemory;
    v24 = v19;
    m_pMemory[v24].m_Next = -1;
    m_Tail = p_m_SendDatas->m_Tail;
    m_pMemory[v24].m_Previous = m_Tail;
    p_m_SendDatas->m_Tail = v19;
    if ( m_Tail == -1 )
      p_m_SendDatas->m_Head = v19;
    else
      p_m_SendDatas->m_Memory.m_pMemory[m_Tail].m_Next = v19;
    ++p_m_SendDatas->m_ElementCount;
    p_m_Element = &p_m_SendDatas->m_Memory.m_pMemory[v24].m_Element;
    if ( p_m_Element != nullptr )
      *p_m_Element = pSendData;
  }
  CEvent::SetEvent(this: &v17->m_hReadyToSendEvent);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002FFE0
// Name: private: unsigned long CThreadedTCPSocket::SendThreadFn(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CThreadedTCPSocket::SendThreadFn(CThreadedTCPSocket *this)
{
  void *UserData; // eax
  bool v3; // zf
  DWORD v4; // eax
  DWORD v5; // eax
  int m_ElementCount; // edi
  DWORD LastError; // eax
  char str[512]; // [esp+Ch] [ebp-21Ch] BYREF
  void *handles[3]; // [esp+20Ch] [ebp-1Ch] BYREF
  void *pChunks; // [esp+218h] [ebp-10h] BYREF
  int pChunkLengths; // [esp+21Ch] [ebp-Ch] BYREF
  CCriticalSectionLock v13; // [esp+220h] [ebp-8h] BYREF

  while ( 1 )
  {
    while ( 1 )
    {
      handles[0] = CTCPPacket::GetUserData(this: &this->m_hExitThreadsEvent);
      handles[1] = CTCPPacket::GetUserData(this: &this->m_hSendCompletionEvent);
      UserData = CTCPPacket::GetUserData(this: &this->m_hReadyToSendEvent);
      v3 = !this->m_bWaitingForSendCompletion;
      handles[2] = UserData;
      v4 = 3;
      if ( !v3 )
        v4 = 2;
      v5 = WaitForMultipleObjects(nCount: v4, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0xBB8u);
      if ( v5 > 2 )
        break;
      if ( v5 == 2 )
      {
        if ( CThreadedTCPSocket::SendThread_HandleReadyToSendEvent(this) == 0 )
          return 1;
      }
      else
      {
        if ( v5 == 0 )
          return 0;
        if ( CThreadedTCPSocket::SendThread_HandleSendCompletionEvent(this) == 0 )
          return 1;
      }
    }
    if ( v5 != 258 )
      break;
    if ( g_bHandleTimeouts )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &v13, pCS: &this->m_SendCS);
      CCriticalSectionLock::Lock(this: &v13);
      m_ElementCount = this->m_SendDatas.m_ElementCount;
      CCriticalSectionLock::Unlock(this: &v13);
      if ( m_ElementCount == 0 )
      {
        pChunks = &g_KeepaliveSentinel;
        pChunkLengths = 4;
        CThreadedTCPSocket::InternalSend(
          this,
          (const void *const *)&pChunks,
          (char *)&pChunkLengths,
          nChunks: 1,
          bPrependLength: false);
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &v13);
    }
  }
  if ( v5 != -1 )
  {
    V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "Unknown return value (%lu) from WaitForMultipleObjects", v5);
    this->m_pHandler->OnError(this: this->m_pHandler, a2: 0, a3: str);
    CEvent::SetEvent(this: &this->m_hExitThreadsEvent);
    this->m_bErrorSignal = true;
    return 0;
  }
  LastError = GetLastError();
  CThreadedTCPSocket::HandleError(this, errorValue: LastError);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10030160
// Name: private: static unsigned long CThreadedTCPSocket::StaticSendThreadFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CThreadedTCPSocket::StaticSendThreadFn(CThreadedTCPSocket *pParameter)
{
  return CThreadedTCPSocket::SendThreadFn(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x10030170
// Name: public: virtual bool CThreadedTCPSocket::SendChunks(void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::SendChunks(
        CThreadedTCPSocket *this,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  if ( this->m_bErrorSignal )
    return 0;
  else
    return CThreadedTCPSocket::InternalSend(this, pChunks, pChunkLengths, nChunks, bPrependLength: true);
}

//------------------------------------------------------------------------------
// Address: 0x100301A0
// Name: private: bool CThreadedTCPSocket::Init(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocket::Init(
        CThreadedTCPSocket *this,
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  unsigned __int16 port; // dx
  unsigned int v6; // eax
  HANDLE v8; // eax
  void *m_hSendThread; // ecx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  unsigned int dwRecvThreadID; // [esp+Ch] [ebp-4h] BYREF

  port = remoteAddr.port;
  v6 = iSocket;
  *(_DWORD *)this->m_RemoteAddr.ip = *(_DWORD *)remoteAddr.ip;
  this->m_pHandler = pHandler;
  this->m_RemoteAddr.port = port;
  LOBYTE(port) = bDeleteHandler;
  this->m_Socket = v6;
  this->m_bDeleteHandler = port;
  iSocket = 1;
  setsockopt(s: v6, level: 6, optname: 1, optval: (const char *)&iSocket, optlen: 4);
  m_Socket = this->m_Socket;
  bDeleteHandler = 196609;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 128, optval: (const char *)&bDeleteHandler, optlen: 4);
  CEvent::Init(this: &this->m_hExitThreadsEvent, bManualReset: true, bInitialState: false);
  CEvent::Init(this: &this->m_hSendCompletionEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hReadyToSendEvent, bManualReset: false, bInitialState: false);
  CEvent::Init(this: &this->m_hRecvEvent, bManualReset: false, bInitialState: false);
  this->m_SendOverlapped.hEvent = CTCPPacket::GetUserData(this: &this->m_hSendCompletionEvent);
  this->m_RecvOverlapped.hEvent = CTCPPacket::GetUserData(this: &this->m_hRecvEvent);
  this->m_hSendThread = CreateThread(
                          lpThreadAttributes: nullptr,
                          dwStackSize: 0,
                          lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticSendThreadFn,
                          lpParameter: this,
                          dwCreationFlags: 4u,
                          lpThreadId: (LPDWORD)&pHandler);
  v8 = CreateThread(
         lpThreadAttributes: nullptr,
         dwStackSize: 0,
         lpStartAddress: (LPTHREAD_START_ROUTINE)CThreadedTCPSocket::StaticRecvThreadFn,
         lpParameter: this,
         dwCreationFlags: 4u,
         lpThreadId: &dwRecvThreadID);
  m_hSendThread = this->m_hSendThread;
  this->m_hRecvThread = v8;
  if ( m_hSendThread == nullptr || v8 == nullptr )
    return 0;
  if ( g_bSetTCPSocketThreadPriorities )
  {
    SetThreadPriority(hThread: m_hSendThread, nPriority: -2);
    SetThreadPriority(hThread: this->m_hRecvThread, nPriority: -2);
  }
  this->m_pHandler->Init(this: this->m_pHandler, a2: this);
  ResumeThread(hThread: this->m_hSendThread);
  ResumeThread(hThread: this->m_hRecvThread);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10030300
// Name: public: static class IThreadedTCPSocket __near * CThreadedTCPSocket::Create(unsigned int,class CIPAddr,class ITCPSocketHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocket *__cdecl CThreadedTCPSocket::Create(
        unsigned int iSocket,
        CIPAddr remoteAddr,
        ITCPSocketHandler *pHandler,
        int bDeleteHandler)
{
  CThreadedTCPSocket *v4; // eax
  CThreadedTCPSocket *v5; // esi

  v4 = (CThreadedTCPSocket *)operator new(size: 0xF8u);
  if ( v4 != nullptr )
    v5 = CThreadedTCPSocket::CThreadedTCPSocket(this: v4);
  else
    v5 = nullptr;
  if ( CThreadedTCPSocket::Init(this: v5, iSocket, remoteAddr, pHandler, bDeleteHandler) != 0 )
    return v5;
  v5->Release(this: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10030360
// Name: public: virtual bool CTCPConnectSocket_Listener::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTCPConnectSocket_Listener::Update(
        CTCPConnectSocket_Listener *this,
        int pSocket,
        unsigned int milliseconds)
{
  CThreadedTCPSocket **v3; // ebx
  int v5; // eax
  SOCKET m_Socket; // edx
  SOCKET v7; // edi
  ITCPSocketHandler *v8; // eax
  CThreadedTCPSocket *v9; // eax
  fd_set readSet; // [esp+Ch] [ebp-124h] BYREF
  sockaddr_in addr; // [esp+110h] [ebp-20h] BYREF
  timeval timeVal; // [esp+120h] [ebp-10h] BYREF
  CIPAddr connectedAddr; // [esp+128h] [ebp-8h] BYREF

  v3 = (CThreadedTCPSocket **)pSocket;
  *(_DWORD *)pSocket = 0;
  if ( this->m_Socket == -1 )
    return 0;
  readSet.fd_array[0] = this->m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  timeVal.tv_usec = 1000 * milliseconds;
  v5 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v5 > 0 )
  {
    m_Socket = this->m_Socket;
    pSocket = 16;
    v7 = accept(s: m_Socket, (struct sockaddr *)&addr, addrlen: &pSocket);
    if ( v7 != -1 )
    {
      CIPAddr::CIPAddr(this: &connectedAddr);
      SockAddrToIPAddr(pIn: &addr, pOut: &connectedAddr);
      v8 = this->m_pHandler->CreateNewHandler(this: this->m_pHandler);
      v9 = CThreadedTCPSocket::Create(iSocket: v7, remoteAddr: connectedAddr, pHandler: v8, bDeleteHandler: 1);
      if ( v9 == nullptr )
      {
        closesocket(s: this->m_Socket);
        this->m_Socket = -1;
        return 0;
      }
      *v3 = v9;
    }
  }
  else if ( v5 == -1 )
  {
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10030480
// Name: public: virtual bool CTCPConnectSocket_Connector::Update(class IThreadedTCPSocket __near * __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTCPConnectSocket_Connector::Update(
        CTCPConnectSocket_Connector *this,
        IThreadedTCPSocket **pSocket,
        unsigned int milliseconds)
{
  int v4; // eax
  SOCKET m_Socket; // edx
  ITCPSocketHandler *v7; // eax
  CThreadedTCPSocket *v8; // eax
  SOCKET v9; // [esp-4h] [ebp-114h]
  fd_set writeSet; // [esp+4h] [ebp-10Ch] BYREF
  timeval timeVal; // [esp+108h] [ebp-8h] BYREF

  *pSocket = nullptr;
  if ( this->m_bError )
    return false;
  if ( this->m_Socket == -1 )
    return true;
  if ( !this->m_bConnected )
  {
    writeSet.fd_array[0] = this->m_Socket;
    timeVal.tv_sec = 0;
    timeVal.tv_usec = 1000 * milliseconds;
    writeSet.fd_count = 1;
    v4 = select(nfds: 0, readfds: nullptr, writefds: &writeSet, exceptfds: nullptr, timeout: &timeVal);
    if ( v4 <= 0 )
    {
      if ( v4 == -1 )
        return CTCPConnectSocket_Connector::EnterErrorMode(this);
    }
    else
    {
      this->m_bConnected = true;
    }
    if ( !this->m_bConnected )
      return true;
  }
  m_Socket = this->m_Socket;
  milliseconds = 0;
  if ( ioctlsocket(s: m_Socket, cmd: -2147195266, argp: &milliseconds) != 0 )
  {
    v9 = this->m_Socket;
    this->m_bError = true;
    closesocket(s: v9);
    this->m_Socket = -1;
    return false;
  }
  v7 = this->m_pHandlerCreator->CreateNewHandler(this: this->m_pHandlerCreator);
  v8 = CThreadedTCPSocket::Create(
         iSocket: this->m_Socket,
         remoteAddr: this->m_RemoteAddr,
         pHandler: v7,
         bDeleteHandler: 1);
  if ( v8 != nullptr )
  {
    this->m_Socket = -1;
    *pSocket = v8;
    return true;
  }
  return CTCPConnectSocket_Connector::EnterErrorMode(this);
}

} // namespace vvis_dll
