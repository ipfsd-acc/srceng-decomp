// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/iphelpers.cpp
// Functions: 24
// ============================================================

#include "utils\vmpi\iphelpers.h"

//------------------------------------------------------------------------------
// Address: 0x1002C900
// Name: public: void CIPAddr::Init(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIPAddr::Init(
        CIPAddr *this,
        unsigned __int8 ip0,
        unsigned __int8 ip1,
        unsigned __int8 ip2,
        unsigned __int8 ip3,
        unsigned __int16 ipPort)
{
  this->ip[0] = ip0;
  this->ip[1] = ip1;
  this->ip[2] = ip2;
  this->ip[3] = ip3;
  this->port = ipPort;
}

//------------------------------------------------------------------------------
// Address: 0x1002C930
// Name: void IPAddrToSockAddr(class CIPAddr const __near *,struct sockaddr_in __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IPAddrToSockAddr(const CIPAddr *pIn, sockaddr_in *pOut)
{
  *(_QWORD *)&pOut->sin_family = 0;
  *(_QWORD *)pOut->sin_zero = 0;
  pOut->sin_family = 2;
  pOut->sin_port = htons(hostshort: pIn->port);
  pOut->sin_addr.S_un.S_addr = *(_DWORD *)pIn->ip;
}

//------------------------------------------------------------------------------
// Address: 0x1002C980
// Name: void SockAddrToIPAddr(struct sockaddr_in const __near *,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SockAddrToIPAddr(const sockaddr_in *pIn, CIPAddr *pOut)
{
  *(_DWORD *)pOut->ip = pIn->sin_addr.S_un.S_addr;
  pOut->port = ntohs(netshort: pIn->sin_port);
}

//------------------------------------------------------------------------------
// Address: 0x1002C9C0
// Name: bool ConvertStringToIPAddr(char const __near *,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ConvertStringToIPAddr(char *pStr, CIPAddr *pOut)
{
  int v2; // eax
  int v3; // edi
  unsigned int v4; // esi
  CIPAddr *v5; // esi
  unsigned __int8 v7; // al
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  struct hostent *v10; // eax
  char ipStr[512]; // [esp+Ch] [ebp-210h] BYREF
  int v12[4]; // [esp+20Ch] [ebp-10h] BYREF

  strchr(string: pStr, chr: 0x3Au);
  v3 = v2;
  if ( v2 != 0 )
  {
    v4 = v2 - (_DWORD)pStr;
    if ( v2 - (int)pStr < 2 || v4 > 0x1FF )
      return 0;
    memcpy(dst: (unsigned __int8 *)ipStr, src: (unsigned __int8 *)pStr, count: v2 - (_DWORD)pStr);
    ipStr[v4] = 0;
    v5 = pOut;
    pOut->port = atoi(nptr: (const char *)(v3 + 1));
  }
  else
  {
    strncpy(dest: (unsigned __int8 *)ipStr, source: (unsigned __int8 *)pStr, count: 0x200u);
    v5 = pOut;
    ipStr[511] = 0;
  }
  if ( (unsigned __int8)(ipStr[0] - 48) <= 9u )
  {
    sscanf(string: ipStr, format: "%d.%d.%d.%d", v12, &v12[1], &v12[2], &v12[3]);
    v7 = v12[1];
    v8 = v12[2];
    v5->ip[0] = v12[0];
    v9 = v12[3];
    v5->ip[1] = v7;
    v5->ip[2] = v8;
    v5->ip[3] = v9;
    return 1;
  }
  v10 = gethostbyname(name: ipStr);
  if ( v10 == nullptr )
    return 0;
  v5->ip[0] = **v10->h_addr_list;
  v5->ip[1] = (*v10->h_addr_list)[1];
  v5->ip[2] = (*v10->h_addr_list)[2];
  v5->ip[3] = (*v10->h_addr_list)[3];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002CAE0
// Name: void IP_GetLastErrorString(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IP_GetLastErrorString(char *pStr, int maxLen)
{
  DWORD LastError; // eax
  char *lpMsgBuf; // [esp+0h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  V_strncpy(pDest: pStr, pSrc: lpMsgBuf, maxLen);
  LocalFree(hMem: lpMsgBuf);
}

//------------------------------------------------------------------------------
// Address: 0x1002CB30
// Name: public: CWaitTimer::CWaitTimer(double)
// Source: json
//------------------------------------------------------------------------------
CWaitTimer *__thiscall CWaitTimer::CWaitTimer(CWaitTimer *this, long double flSeconds)
{
  unsigned __int64 v3; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v4; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v5; // [esp+Ch] [ebp-4h]

  v5 = &v4;
  v4 = __rdtsc();
  HIDWORD(v3) = HIDWORD(_g_ClockSpeed);
  LODWORD(v3) = _g_ClockSpeed;
  this->m_StartTime = 1000 * v4 / v3;
  this->m_WaitMS = (__int64)(flSeconds * 1000.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002CBB0
// Name: public: bool CWaitTimer::ShouldKeepWaiting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaitTimer::ShouldKeepWaiting(CWaitTimer *this)
{
  unsigned __int64 v2; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v3; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v4; // [esp+Ch] [ebp-4h]

  if ( this->m_WaitMS == 0 )
    return false;
  v4 = &v3;
  v3 = __rdtsc();
  HIDWORD(v2) = HIDWORD(_g_ClockSpeed);
  LODWORD(v2) = _g_ClockSpeed;
  return (unsigned int)(1000 * v3 / v2) - this->m_StartTime <= this->m_WaitMS || g_bForceWaitTimers;
}

//------------------------------------------------------------------------------
// Address: 0x1002CC30
// Name: public: CIPAddr::CIPAddr(void)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(CIPAddr *this)
{
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002CC40
// Name: public: CIPAddr::CIPAddr(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(
        CIPAddr *this,
        unsigned __int8 ip0,
        unsigned __int8 ip1,
        unsigned __int8 ip2,
        unsigned __int8 ip3,
        unsigned __int16 ipPort)
{
  this->ip[0] = ip0;
  this->ip[1] = ip1;
  this->ip[2] = ip2;
  this->ip[3] = ip3;
  this->port = ipPort;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002CC70
// Name: public: double CCycleCount::GetSeconds(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CCycleCount::GetSeconds(CCycleCount *this)
{
  return (double)this->m_Int64 * _g_ClockSpeedSecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1002CCB0
// Name: public: virtual void CIPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIPSocket::Release(CIPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CIPSocket *, int))this->dtr_CIPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002CCC0
// Name: public: virtual bool CIPSocket::Bind(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Bind(CIPSocket *this, const CIPAddr *pAddr)
{
  bool result; // al

  result = this->CreateSocket(this);
  if ( result )
    return this->BindPart2(this, a2: pAddr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002CCF0
// Name: public: virtual bool CIPSocket::ListenToMulticastStream(class CIPAddr const __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::ListenToMulticastStream(CIPSocket *this, int addr, const CIPAddr *localInterface)
{
  unsigned __int8 v3; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // dl
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // dl
  in_addr::<unnamed_type_S_un> S_un; // ecx
  in_addr::<unnamed_type_S_un> v12; // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  ip_mreq mr; // [esp+8h] [ebp-8h] BYREF

  v3 = *(_BYTE *)(addr + 1);
  mr.imr_multiaddr.S_un.S_un_b.s_b1 = *(_BYTE *)addr;
  v5 = *(_BYTE *)(addr + 2);
  mr.imr_multiaddr.S_un.S_un_b.s_b2 = v3;
  v6 = *(_BYTE *)(addr + 3);
  mr.imr_multiaddr.S_un.S_un_b.s_b3 = v5;
  v7 = localInterface->ip[0];
  mr.imr_multiaddr.S_un.S_un_b.s_b4 = v6;
  v8 = localInterface->ip[1];
  mr.imr_interface.S_un.S_un_b.s_b1 = v7;
  v9 = localInterface->ip[2];
  mr.imr_interface.S_un.S_un_b.s_b2 = v8;
  v10 = localInterface->ip[3];
  mr.imr_interface.S_un.S_un_b.s_b3 = v9;
  m_Socket = this->m_Socket;
  mr.imr_interface.S_un.S_un_b.s_b4 = v10;
  addr = 0x200000;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 4098, optval: (const char *)&addr, optlen: 4);
  if ( setsockopt(s: this->m_Socket, level: 0, optname: 12, optval: (const char *)&mr, optlen: 8) != 0 )
    return 0;
  S_un = mr.imr_multiaddr.S_un;
  v12 = mr.imr_interface.S_un;
  this->m_bMulticastGroupMembership = true;
  this->m_MulticastGroupMREQ.imr_multiaddr.S_un = S_un;
  this->m_MulticastGroupMREQ.imr_interface.S_un = v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002CD90
// Name: public: virtual bool CIPSocket::SendTo(class CIPAddr const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::SendTo(CIPSocket *this, const CIPAddr *pAddr, const void *pData, int len)
{
  return this->SendChunksTo(this, a2: pAddr, a3: &pData, a4: &len, a5: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002CDB0
// Name: public: virtual bool CIPSocket::SendChunksTo(class CIPAddr const __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CIPSocket::SendChunksTo(
        CIPSocket *this,
        const CIPAddr *pAddr,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  signed int v5; // ebx
  char *v6; // edx
  signed int v7; // eax
  int v8; // esi
  unsigned int *v9; // ecx
  char *v10; // ebx
  unsigned int v11; // edx
  char *v12; // ebx
  unsigned int v13; // edx
  unsigned int v14; // edx
  char *v15; // ecx
  u_short port; // ax
  u_short v17; // ax
  unsigned __int8 v18; // dl
  unsigned __int8 v19; // cl
  unsigned __int8 v20; // cl
  SOCKET m_Socket; // eax
  _WSABUF bufs[32]; // [esp+Ch] [ebp-124h] BYREF
  CIPSocket *v24; // [esp+10Ch] [ebp-24h]
  int nTotalBytes; // [esp+110h] [ebp-20h]
  sockaddr_in addr; // [esp+114h] [ebp-1Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+124h] [ebp-Ch] BYREF
  int v28; // [esp+128h] [ebp-8h]
  int v29; // [esp+12Ch] [ebp-4h]

  v5 = nChunks;
  v24 = this;
  if ( nChunks > 32 )
    _Error(a1: "CIPSocket::SendChunksTo: too many chunks (%d).", nChunks);
  v6 = pChunkLengths;
  v7 = 0;
  v8 = 0;
  v29 = 0;
  v28 = 0;
  nTotalBytes = 0;
  if ( nChunks >= 2 )
  {
    v9 = (unsigned int *)(pChunkLengths + 4);
    do
    {
      v10 = (char *)pChunks[v7];
      v11 = *(v9 - 1);
      v29 += v11;
      bufs[v7].buf = v10;
      v12 = *(char **)((char *)v9 + (char *)pChunks - pChunkLengths);
      bufs[v7].len = v11;
      v13 = *v9;
      v28 += *v9;
      bufs[v7 + 1].buf = v12;
      v5 = nChunks;
      bufs[v7 + 1].len = v13;
      v7 += 2;
      v9 += 2;
    }
    while ( v7 < nChunks - 1 );
    v6 = pChunkLengths;
    v8 = nTotalBytes;
  }
  if ( v7 < v5 )
  {
    v14 = *(_DWORD *)&v6[4 * v7];
    v15 = (char *)pChunks[v7];
    bufs[v7].len = v14;
    bufs[v7].buf = v15;
    v8 = v14;
  }
  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v17 = htons(hostshort: port);
  v18 = pAddr->ip[1];
  v19 = pAddr->ip[0];
  addr.sin_port = v17;
  LOBYTE(v17) = pAddr->ip[2];
  addr.sin_addr.S_un.S_un_b.s_b2 = v18;
  addr.sin_addr.S_un.S_un_b.s_b1 = v19;
  v20 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v17;
  m_Socket = v24->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v20;
  dwNumBytesSent = 0;
  return WSASendTo(
           s: m_Socket,
           lpBuffers: bufs,
           dwBufferCount: v5,
           lpNumberOfBytesSent: &dwNumBytesSent,
           dwFlags: 0,
           lpTo: (const struct sockaddr *)&addr,
           iTolen: 16,
           lpOverlapped: nullptr,
           lpCompletionRoutine: nullptr) == 0
      && dwNumBytesSent == v8 + v29 + v28;
}

//------------------------------------------------------------------------------
// Address: 0x1002CEF0
// Name: IP_FloatTime
// Source: json
//------------------------------------------------------------------------------
long double __cdecl IP_FloatTime()
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1002CF50
// Name: public: virtual bool CIPSocket::CreateSocket(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::CreateSocket(CIPSocket *this)
{
  SOCKET m_Socket; // eax
  SOCKET v3; // edi
  unsigned int val; // [esp+8h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  if ( m_Socket != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: m_Socket, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  v3 = socket(af: 2, type: 2, protocol: 0);
  if ( v3 == -1 )
    return 0;
  val = 1;
  if ( ioctlsocket(s: v3, cmd: -2147195266, argp: &val) != 0 )
  {
    closesocket(s: v3);
    return 0;
  }
  this->m_Socket = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002CFE0
// Name: public: virtual bool CIPSocket::BindPart2(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::BindPart2(CIPSocket *this, const CIPAddr *pAddr)
{
  u_short port; // cx
  u_short v4; // ax
  unsigned __int8 v5; // dl
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // dl
  SOCKET v9; // eax
  SOCKET m_Socket; // [esp-Ch] [ebp-24h]
  sockaddr_in addr; // [esp+8h] [ebp-10h] BYREF

  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v4 = htons(hostshort: port);
  v5 = pAddr->ip[0];
  v6 = pAddr->ip[2];
  addr.sin_port = v4;
  addr.sin_addr.S_un.S_un_b.s_b2 = pAddr->ip[1];
  addr.sin_addr.S_un.S_un_b.s_b1 = v5;
  v7 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v6;
  m_Socket = this->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v7;
  if ( bind(s: m_Socket, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
    return 1;
  v9 = this->m_Socket;
  if ( v9 != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: v9, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002D090
// Name: public: virtual bool CIPSocket::BindToAny(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::BindToAny(CIPSocket *this, unsigned __int16 port)
{
  bool (__thiscall *Bind)(struct CIPSocket *, const CIPAddr *); // edx
  CIPAddr addr; // [esp+0h] [ebp-8h] BYREF

  Bind = this->Bind;
  addr.port = port;
  *(_DWORD *)addr.ip = 0;
  return Bind(this, a2: &addr);
}

//------------------------------------------------------------------------------
// Address: 0x1002D0C0
// Name: public: virtual bool CIPSocket::Broadcast(void const __near *,int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Broadcast(CIPSocket *this, const void *pData, int len, unsigned __int16 port)
{
  CIPSocket_vtbl *v6; // eax
  bool (__thiscall *SendTo)(struct CIPSocket *, const CIPAddr *, const void *, const int); // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  CIPAddr addr; // [esp+4h] [ebp-Ch] BYREF
  int bBroadcast; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bSetupToBroadcast )
  {
    m_Socket = this->m_Socket;
    bBroadcast = 1;
    if ( setsockopt(s: m_Socket, level: 0xFFFF, optname: 32, optval: (const char *)&bBroadcast, optlen: 4) != 0 )
      return false;
    this->m_bSetupToBroadcast = true;
  }
  v6 = this->__vftable;
  addr.port = port;
  SendTo = v6->SendTo;
  *(_DWORD *)addr.ip = -1;
  return SendTo(this, a2: &addr, a3: pData, a4: len);
}

//------------------------------------------------------------------------------
// Address: 0x1002D130
// Name: public: virtual int CIPSocket::RecvFrom(void __near *,int,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CIPSocket::RecvFrom(CIPSocket *this, char *pData, int maxDataLen, CIPAddr *pFrom)
{
  unsigned int m_Socket; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  SOCKET v10; // [esp-1Ch] [ebp-140h]
  fd_set readSet; // [esp+4h] [ebp-120h] BYREF
  sockaddr_in sender; // [esp+108h] [ebp-1Ch] BYREF
  timeval timeVal; // [esp+118h] [ebp-Ch] BYREF
  int fromSize; // [esp+120h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  timeVal.tv_usec = 0;
  readSet.fd_array[0] = m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  v6 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v6 == 0 || v6 == -1 )
    return -1;
  v10 = this->m_Socket;
  fromSize = 16;
  v7 = recvfrom(s: v10, buf: pData, len: maxDataLen, flags: 0, from: (struct sockaddr *)&sender, fromlen: &fromSize);
  v8 = v7;
  if ( v7 == 0 || v7 == -1 )
    return -1;
  if ( pFrom != nullptr )
    SockAddrToIPAddr(pIn: &sender, pOut: pFrom);
  this->m_flLastRecvTime = IP_FloatTime();
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1002D1E0
// Name: public: virtual double CIPSocket::GetRecvTimeout(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CIPSocket::GetRecvTimeout(CIPSocket *this)
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier - this->m_flLastRecvTime;
}

//------------------------------------------------------------------------------
// Address: 0x1002D2A0
// Name: class ISocket __near * CreateIPSocket(void)
// Source: json
//------------------------------------------------------------------------------
ISocket *__cdecl CreateIPSocket()
{
  ISocket *result; // eax

  result = (ISocket *)operator new(nSize: 0x28u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ISocket_vtbl *)&CIPSocket::`vftable';
  result[1].__vftable = (ISocket_vtbl *)-1;
  LOBYTE(result[5].__vftable) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D2D0
// Name: class ISocket __near * CreateMulticastListenSocket(class CIPAddr const __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
ISocket *__cdecl CreateMulticastListenSocket(const CIPAddr *addr, const CIPAddr *localInterface)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax
  CIPAddr bindAddr; // [esp+Ch] [ebp-8h] BYREF

  v2 = operator new(nSize: 0x28u);
  if ( v2 != nullptr )
  {
    *v2 = &CIPSocket::`vftable';
    v2[1] = -1;
    *((_BYTE *)v2 + 20) = 0;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = *(_DWORD *)localInterface->ip;
  bindAddr.port = addr->port;
  *(_DWORD *)bindAddr.ip = v4;
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CIPAddr *))(*v3 + 4))(a1: v3, a2: &bindAddr) != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD *, const CIPAddr *, const CIPAddr *))(*v3 + 44))(
         a1: v3,
         a2: addr,
         a3: localInterface) != 0 )
  {
    return (ISocket *)v3;
  }
  (*(void (__thiscall **)(_DWORD *))*v3)(a1: v3);
  return nullptr;
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10014050
// Name: public: void CIPAddr::Init(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIPAddr::Init(
        CIPAddr *this,
        unsigned __int8 ip0,
        unsigned __int8 ip1,
        unsigned __int8 ip2,
        unsigned __int8 ip3,
        unsigned __int16 ipPort)
{
  this->ip[0] = ip0;
  this->ip[1] = ip1;
  this->ip[2] = ip2;
  this->ip[3] = ip3;
  this->port = ipPort;
}

//------------------------------------------------------------------------------
// Address: 0x10014080
// Name: void IPAddrToSockAddr(class CIPAddr const __near *,struct sockaddr_in __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IPAddrToSockAddr(const CIPAddr *pIn, sockaddr_in *pOut)
{
  *(_QWORD *)&pOut->sin_family = 0;
  *(_QWORD *)pOut->sin_zero = 0;
  pOut->sin_family = 2;
  pOut->sin_port = htons(hostshort: pIn->port);
  pOut->sin_addr.S_un.S_addr = *(_DWORD *)pIn->ip;
}

//------------------------------------------------------------------------------
// Address: 0x100140D0
// Name: void SockAddrToIPAddr(struct sockaddr_in const __near *,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SockAddrToIPAddr(const sockaddr_in *pIn, CIPAddr *pOut)
{
  *(_DWORD *)pOut->ip = pIn->sin_addr.S_un.S_addr;
  pOut->port = ntohs(netshort: pIn->sin_port);
}

//------------------------------------------------------------------------------
// Address: 0x10014110
// Name: bool ConvertStringToIPAddr(char const __near *,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ConvertStringToIPAddr(char *pStr, CIPAddr *pOut)
{
  int v2; // eax
  int v3; // edi
  unsigned int v4; // esi
  CIPAddr *v5; // esi
  unsigned __int8 v7; // al
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  struct hostent *v10; // eax
  char ipStr[512]; // [esp+Ch] [ebp-210h] BYREF
  int v12[4]; // [esp+20Ch] [ebp-10h] BYREF

  strchr(string: (unsigned __int8 *)pStr, chr: 0x3Au);
  v3 = v2;
  if ( v2 != 0 )
  {
    v4 = v2 - (_DWORD)pStr;
    if ( v2 - (int)pStr < 2 || v4 > 0x1FF )
      return 0;
    memcpy(dst: (unsigned __int8 *)ipStr, src: (unsigned __int8 *)pStr, count: v2 - (_DWORD)pStr);
    ipStr[v4] = 0;
    v5 = pOut;
    pOut->port = atoi(nptr: (const char *)(v3 + 1));
  }
  else
  {
    strncpy(dest: (unsigned __int8 *)ipStr, source: (unsigned __int8 *)pStr, count: 0x200u);
    v5 = pOut;
    ipStr[511] = 0;
  }
  if ( (unsigned __int8)(ipStr[0] - 48) <= 9u )
  {
    sscanf(string: ipStr, format: "%d.%d.%d.%d", v12, &v12[1], &v12[2], &v12[3]);
    v7 = v12[1];
    v8 = v12[2];
    v5->ip[0] = v12[0];
    v9 = v12[3];
    v5->ip[1] = v7;
    v5->ip[2] = v8;
    v5->ip[3] = v9;
    return 1;
  }
  v10 = gethostbyname(name: ipStr);
  if ( v10 == nullptr )
    return 0;
  v5->ip[0] = **v10->h_addr_list;
  v5->ip[1] = (*v10->h_addr_list)[1];
  v5->ip[2] = (*v10->h_addr_list)[2];
  v5->ip[3] = (*v10->h_addr_list)[3];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014230
// Name: void IP_GetLastErrorString(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IP_GetLastErrorString(char *pStr, int maxLen)
{
  DWORD LastError; // eax
  char *lpMsgBuf; // [esp+0h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  V_strncpy(pDest: pStr, pSrc: lpMsgBuf, maxLen);
  LocalFree(hMem: lpMsgBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10014280
// Name: public: CWaitTimer::CWaitTimer(double)
// Source: json
//------------------------------------------------------------------------------
CWaitTimer *__thiscall CWaitTimer::CWaitTimer(CWaitTimer *this, long double flSeconds)
{
  unsigned __int64 v3; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v4; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v5; // [esp+Ch] [ebp-4h]

  v5 = &v4;
  v4 = __rdtsc();
  HIDWORD(v3) = HIDWORD(_g_ClockSpeed);
  LODWORD(v3) = _g_ClockSpeed;
  this->m_StartTime = 1000 * v4 / v3;
  this->m_WaitMS = (__int64)(flSeconds * 1000.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10014300
// Name: public: bool CWaitTimer::ShouldKeepWaiting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaitTimer::ShouldKeepWaiting(CWaitTimer *this)
{
  unsigned __int64 v2; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v3; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v4; // [esp+Ch] [ebp-4h]

  if ( this->m_WaitMS == 0 )
    return false;
  v4 = &v3;
  v3 = __rdtsc();
  HIDWORD(v2) = HIDWORD(_g_ClockSpeed);
  LODWORD(v2) = _g_ClockSpeed;
  return (unsigned int)(1000 * v3 / v2) - this->m_StartTime <= this->m_WaitMS || g_bForceWaitTimers;
}

//------------------------------------------------------------------------------
// Address: 0x10014380
// Name: public: CIPAddr::CIPAddr(void)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(CIPAddr *this)
{
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10014390
// Name: public: CIPAddr::CIPAddr(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(
        CIPAddr *this,
        unsigned __int8 ip0,
        unsigned __int8 ip1,
        unsigned __int8 ip2,
        unsigned __int8 ip3,
        unsigned __int16 ipPort)
{
  this->ip[0] = ip0;
  this->ip[1] = ip1;
  this->ip[2] = ip2;
  this->ip[3] = ip3;
  this->port = ipPort;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100143C0
// Name: public: double CCycleCount::GetSeconds(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CCycleCount::GetSeconds(CCycleCount *this)
{
  return (double)this->m_Int64 * _g_ClockSpeedSecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x10014400
// Name: public: virtual void CIPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIPSocket::Release(CIPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CIPSocket *, int))this->dtr_CIPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10014410
// Name: public: virtual bool CIPSocket::Bind(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Bind(CIPSocket *this, const CIPAddr *pAddr)
{
  bool result; // al

  result = this->CreateSocket(this);
  if ( result )
    return this->BindPart2(this, a2: pAddr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014440
// Name: public: virtual bool CIPSocket::ListenToMulticastStream(class CIPAddr const __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::ListenToMulticastStream(CIPSocket *this, int addr, const CIPAddr *localInterface)
{
  unsigned __int8 v3; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // dl
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // dl
  in_addr::<unnamed_type_S_un> S_un; // ecx
  in_addr::<unnamed_type_S_un> v12; // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  ip_mreq mr; // [esp+8h] [ebp-8h] BYREF

  v3 = *(_BYTE *)(addr + 1);
  mr.imr_multiaddr.S_un.S_un_b.s_b1 = *(_BYTE *)addr;
  v5 = *(_BYTE *)(addr + 2);
  mr.imr_multiaddr.S_un.S_un_b.s_b2 = v3;
  v6 = *(_BYTE *)(addr + 3);
  mr.imr_multiaddr.S_un.S_un_b.s_b3 = v5;
  v7 = localInterface->ip[0];
  mr.imr_multiaddr.S_un.S_un_b.s_b4 = v6;
  v8 = localInterface->ip[1];
  mr.imr_interface.S_un.S_un_b.s_b1 = v7;
  v9 = localInterface->ip[2];
  mr.imr_interface.S_un.S_un_b.s_b2 = v8;
  v10 = localInterface->ip[3];
  mr.imr_interface.S_un.S_un_b.s_b3 = v9;
  m_Socket = this->m_Socket;
  mr.imr_interface.S_un.S_un_b.s_b4 = v10;
  addr = 0x200000;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 4098, optval: (const char *)&addr, optlen: 4);
  if ( setsockopt(s: this->m_Socket, level: 0, optname: 12, optval: (const char *)&mr, optlen: 8) != 0 )
    return 0;
  S_un = mr.imr_multiaddr.S_un;
  v12 = mr.imr_interface.S_un;
  this->m_bMulticastGroupMembership = true;
  this->m_MulticastGroupMREQ.imr_multiaddr.S_un = S_un;
  this->m_MulticastGroupMREQ.imr_interface.S_un = v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100144E0
// Name: public: virtual bool CIPSocket::SendTo(class CIPAddr const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::SendTo(CIPSocket *this, const CIPAddr *pAddr, const void *pData, int len)
{
  return this->SendChunksTo(this, a2: pAddr, a3: &pData, a4: &len, a5: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10014500
// Name: public: virtual bool CIPSocket::SendChunksTo(class CIPAddr const __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CIPSocket::SendChunksTo(
        CIPSocket *this,
        const CIPAddr *pAddr,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  signed int v5; // ebx
  char *v6; // edx
  signed int v7; // eax
  int v8; // esi
  unsigned int *v9; // ecx
  char *v10; // ebx
  unsigned int v11; // edx
  char *v12; // ebx
  unsigned int v13; // edx
  unsigned int v14; // edx
  char *v15; // ecx
  u_short port; // ax
  u_short v17; // ax
  unsigned __int8 v18; // dl
  unsigned __int8 v19; // cl
  unsigned __int8 v20; // cl
  SOCKET m_Socket; // eax
  _WSABUF bufs[32]; // [esp+Ch] [ebp-124h] BYREF
  CIPSocket *v24; // [esp+10Ch] [ebp-24h]
  int nTotalBytes; // [esp+110h] [ebp-20h]
  sockaddr_in addr; // [esp+114h] [ebp-1Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+124h] [ebp-Ch] BYREF
  int v28; // [esp+128h] [ebp-8h]
  int v29; // [esp+12Ch] [ebp-4h]

  v5 = nChunks;
  v24 = this;
  if ( nChunks > 32 )
    _Error(a1: "CIPSocket::SendChunksTo: too many chunks (%d).", nChunks);
  v6 = pChunkLengths;
  v7 = 0;
  v8 = 0;
  v29 = 0;
  v28 = 0;
  nTotalBytes = 0;
  if ( nChunks >= 2 )
  {
    v9 = (unsigned int *)(pChunkLengths + 4);
    do
    {
      v10 = (char *)pChunks[v7];
      v11 = *(v9 - 1);
      v29 += v11;
      bufs[v7].buf = v10;
      v12 = *(char **)((char *)v9 + (char *)pChunks - pChunkLengths);
      bufs[v7].len = v11;
      v13 = *v9;
      v28 += *v9;
      bufs[v7 + 1].buf = v12;
      v5 = nChunks;
      bufs[v7 + 1].len = v13;
      v7 += 2;
      v9 += 2;
    }
    while ( v7 < nChunks - 1 );
    v6 = pChunkLengths;
    v8 = nTotalBytes;
  }
  if ( v7 < v5 )
  {
    v14 = *(_DWORD *)&v6[4 * v7];
    v15 = (char *)pChunks[v7];
    bufs[v7].len = v14;
    bufs[v7].buf = v15;
    v8 = v14;
  }
  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v17 = htons(hostshort: port);
  v18 = pAddr->ip[1];
  v19 = pAddr->ip[0];
  addr.sin_port = v17;
  LOBYTE(v17) = pAddr->ip[2];
  addr.sin_addr.S_un.S_un_b.s_b2 = v18;
  addr.sin_addr.S_un.S_un_b.s_b1 = v19;
  v20 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v17;
  m_Socket = v24->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v20;
  dwNumBytesSent = 0;
  return WSASendTo(
           s: m_Socket,
           lpBuffers: bufs,
           dwBufferCount: v5,
           lpNumberOfBytesSent: &dwNumBytesSent,
           dwFlags: 0,
           lpTo: (const struct sockaddr *)&addr,
           iTolen: 16,
           lpOverlapped: nullptr,
           lpCompletionRoutine: nullptr) == 0
      && dwNumBytesSent == v8 + v29 + v28;
}

//------------------------------------------------------------------------------
// Address: 0x10014640
// Name: IP_FloatTime
// Source: json
//------------------------------------------------------------------------------
long double __cdecl IP_FloatTime()
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x100146A0
// Name: public: virtual bool CIPSocket::CreateSocket(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::CreateSocket(CIPSocket *this)
{
  SOCKET m_Socket; // eax
  SOCKET v3; // edi
  unsigned int val; // [esp+8h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  if ( m_Socket != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: m_Socket, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  v3 = socket(af: 2, type: 2, protocol: 0);
  if ( v3 == -1 )
    return 0;
  val = 1;
  if ( ioctlsocket(s: v3, cmd: -2147195266, argp: &val) != 0 )
  {
    closesocket(s: v3);
    return 0;
  }
  this->m_Socket = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014730
// Name: public: virtual bool CIPSocket::BindPart2(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::BindPart2(CIPSocket *this, const CIPAddr *pAddr)
{
  u_short port; // cx
  u_short v4; // ax
  unsigned __int8 v5; // dl
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // dl
  SOCKET v9; // eax
  SOCKET m_Socket; // [esp-Ch] [ebp-24h]
  sockaddr_in addr; // [esp+8h] [ebp-10h] BYREF

  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v4 = htons(hostshort: port);
  v5 = pAddr->ip[0];
  v6 = pAddr->ip[2];
  addr.sin_port = v4;
  addr.sin_addr.S_un.S_un_b.s_b2 = pAddr->ip[1];
  addr.sin_addr.S_un.S_un_b.s_b1 = v5;
  v7 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v6;
  m_Socket = this->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v7;
  if ( bind(s: m_Socket, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
    return 1;
  v9 = this->m_Socket;
  if ( v9 != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: v9, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100147E0
// Name: public: virtual bool CIPSocket::BindToAny(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::BindToAny(CIPSocket *this, unsigned __int16 port)
{
  bool (__thiscall *Bind)(struct CIPSocket *, const CIPAddr *); // edx
  CIPAddr addr; // [esp+0h] [ebp-8h] BYREF

  Bind = this->Bind;
  addr.port = port;
  *(_DWORD *)addr.ip = 0;
  return Bind(this, a2: &addr);
}

//------------------------------------------------------------------------------
// Address: 0x10014810
// Name: public: virtual bool CIPSocket::Broadcast(void const __near *,int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Broadcast(CIPSocket *this, const void *pData, int len, unsigned __int16 port)
{
  CIPSocket_vtbl *v6; // eax
  bool (__thiscall *SendTo)(struct CIPSocket *, const CIPAddr *, const void *, const int); // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  CIPAddr addr; // [esp+4h] [ebp-Ch] BYREF
  int bBroadcast; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bSetupToBroadcast )
  {
    m_Socket = this->m_Socket;
    bBroadcast = 1;
    if ( setsockopt(s: m_Socket, level: 0xFFFF, optname: 32, optval: (const char *)&bBroadcast, optlen: 4) != 0 )
      return false;
    this->m_bSetupToBroadcast = true;
  }
  v6 = this->__vftable;
  addr.port = port;
  SendTo = v6->SendTo;
  *(_DWORD *)addr.ip = -1;
  return SendTo(this, a2: &addr, a3: pData, a4: len);
}

//------------------------------------------------------------------------------
// Address: 0x10014880
// Name: public: virtual int CIPSocket::RecvFrom(void __near *,int,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CIPSocket::RecvFrom(CIPSocket *this, char *pData, int maxDataLen, CIPAddr *pFrom)
{
  unsigned int m_Socket; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  SOCKET v10; // [esp-1Ch] [ebp-140h]
  fd_set readSet; // [esp+4h] [ebp-120h] BYREF
  sockaddr_in sender; // [esp+108h] [ebp-1Ch] BYREF
  timeval timeVal; // [esp+118h] [ebp-Ch] BYREF
  int fromSize; // [esp+120h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  timeVal.tv_usec = 0;
  readSet.fd_array[0] = m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  v6 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v6 == 0 || v6 == -1 )
    return -1;
  v10 = this->m_Socket;
  fromSize = 16;
  v7 = recvfrom(s: v10, buf: pData, len: maxDataLen, flags: 0, from: (struct sockaddr *)&sender, fromlen: &fromSize);
  v8 = v7;
  if ( v7 == 0 || v7 == -1 )
    return -1;
  if ( pFrom != nullptr )
    SockAddrToIPAddr(pIn: &sender, pOut: pFrom);
  this->m_flLastRecvTime = IP_FloatTime();
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10014930
// Name: public: virtual double CIPSocket::GetRecvTimeout(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CIPSocket::GetRecvTimeout(CIPSocket *this)
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier - this->m_flLastRecvTime;
}

//------------------------------------------------------------------------------
// Address: 0x100149F0
// Name: class ISocket __near * CreateIPSocket(void)
// Source: json
//------------------------------------------------------------------------------
ISocket *__cdecl CreateIPSocket()
{
  ISocket *result; // eax

  result = (ISocket *)operator new(nSize: 0x28u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ISocket_vtbl *)&CIPSocket::`vftable';
  result[1].__vftable = (ISocket_vtbl *)-1;
  LOBYTE(result[5].__vftable) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014A20
// Name: class ISocket __near * CreateMulticastListenSocket(class CIPAddr const __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
ISocket *__cdecl CreateMulticastListenSocket(const CIPAddr *addr, const CIPAddr *localInterface)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax
  CIPAddr bindAddr; // [esp+Ch] [ebp-8h] BYREF

  v2 = operator new(nSize: 0x28u);
  if ( v2 != nullptr )
  {
    *v2 = &CIPSocket::`vftable';
    v2[1] = -1;
    *((_BYTE *)v2 + 20) = 0;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = *(_DWORD *)localInterface->ip;
  bindAddr.port = addr->port;
  *(_DWORD *)bindAddr.ip = v4;
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CIPAddr *))(*v3 + 4))(a1: v3, a2: &bindAddr) != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD *, const CIPAddr *, const CIPAddr *))(*v3 + 44))(
         a1: v3,
         a2: addr,
         a3: localInterface) != 0 )
  {
    return (ISocket *)v3;
  }
  (*(void (__thiscall **)(_DWORD *))*v3)(a1: v3);
  return nullptr;
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vmpi_service (Missing functions)
// ============================================================
namespace vmpi_service {

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: bool CIPAddr::operator==(class CIPAddr const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CIPAddr::operator==(CIPAddr *this, const CIPAddr *o)
{
  return this->ip[0] == o->ip[0]
      && this->ip[1] == o->ip[1]
      && this->ip[2] == o->ip[2]
      && this->ip[3] == o->ip[3]
      && this->port == o->port;
}

//------------------------------------------------------------------------------
// Address: 0x00401040
// Name: void IPAddrToSockAddr(class CIPAddr const __near *,struct sockaddr_in __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IPAddrToSockAddr(const CIPAddr *pIn, sockaddr_in *pOut)
{
  *(_QWORD *)&pOut->sin_family = 0;
  *(_QWORD *)pOut->sin_zero = 0;
  pOut->sin_family = 2;
  pOut->sin_port = htons(hostshort: pIn->port);
  pOut->sin_addr.S_un.S_addr = *(_DWORD *)pIn->ip;
}

//------------------------------------------------------------------------------
// Address: 0x00401090
// Name: void SockAddrToIPAddr(struct sockaddr_in const __near *,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SockAddrToIPAddr(const sockaddr_in *pIn, CIPAddr *pOut)
{
  *(_DWORD *)pOut->ip = pIn->sin_addr.S_un.S_addr;
  pOut->port = ntohs(netshort: pIn->sin_port);
}

//------------------------------------------------------------------------------
// Address: 0x004010D0
// Name: public: CWaitTimer::CWaitTimer(double)
// Source: json
//------------------------------------------------------------------------------
CWaitTimer *__thiscall CWaitTimer::CWaitTimer(CWaitTimer *this, long double flSeconds)
{
  unsigned __int64 v3; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v4; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v5; // [esp+Ch] [ebp-4h]

  v5 = &v4;
  v4 = __rdtsc();
  HIDWORD(v3) = HIDWORD(_g_ClockSpeed);
  LODWORD(v3) = _g_ClockSpeed;
  this->m_StartTime = 1000 * v4 / v3;
  this->m_WaitMS = (__int64)(flSeconds * 1000.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401150
// Name: public: bool CWaitTimer::ShouldKeepWaiting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaitTimer::ShouldKeepWaiting(CWaitTimer *this)
{
  unsigned __int64 v2; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v3; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v4; // [esp+Ch] [ebp-4h]

  if ( this->m_WaitMS == 0 )
    return false;
  v4 = &v3;
  v3 = __rdtsc();
  HIDWORD(v2) = HIDWORD(_g_ClockSpeed);
  LODWORD(v2) = _g_ClockSpeed;
  return (unsigned int)(1000 * v3 / v2) - this->m_StartTime <= this->m_WaitMS || g_bForceWaitTimers;
}

//------------------------------------------------------------------------------
// Address: 0x004011D0
// Name: public: CIPAddr::CIPAddr(void)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(CIPAddr *this)
{
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004011E0
// Name: public: CIPAddr::CIPAddr(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(
        CIPAddr *this,
        unsigned __int8 ip0,
        unsigned __int8 ip1,
        unsigned __int8 ip2,
        unsigned __int8 ip3,
        unsigned __int16 ipPort)
{
  this->ip[0] = ip0;
  this->ip[1] = ip1;
  this->ip[2] = ip2;
  this->ip[3] = ip3;
  this->port = ipPort;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401210
// Name: public: virtual void CIPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIPSocket::Release(CIPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CIPSocket *, int))this->dtr_CIPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00401220
// Name: public: virtual bool CIPSocket::Bind(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Bind(CIPSocket *this, const CIPAddr *pAddr)
{
  bool result; // al

  result = this->CreateSocket(this);
  if ( result )
    return this->BindPart2(this, a2: pAddr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401250
// Name: public: virtual bool CIPSocket::ListenToMulticastStream(class CIPAddr const __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::ListenToMulticastStream(CIPSocket *this, int addr, const CIPAddr *localInterface)
{
  unsigned __int8 v3; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // dl
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // dl
  in_addr::<unnamed_type_S_un> S_un; // ecx
  in_addr::<unnamed_type_S_un> v12; // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  ip_mreq mr; // [esp+8h] [ebp-8h] BYREF

  v3 = *(_BYTE *)(addr + 1);
  mr.imr_multiaddr.S_un.S_un_b.s_b1 = *(_BYTE *)addr;
  v5 = *(_BYTE *)(addr + 2);
  mr.imr_multiaddr.S_un.S_un_b.s_b2 = v3;
  v6 = *(_BYTE *)(addr + 3);
  mr.imr_multiaddr.S_un.S_un_b.s_b3 = v5;
  v7 = localInterface->ip[0];
  mr.imr_multiaddr.S_un.S_un_b.s_b4 = v6;
  v8 = localInterface->ip[1];
  mr.imr_interface.S_un.S_un_b.s_b1 = v7;
  v9 = localInterface->ip[2];
  mr.imr_interface.S_un.S_un_b.s_b2 = v8;
  v10 = localInterface->ip[3];
  mr.imr_interface.S_un.S_un_b.s_b3 = v9;
  m_Socket = this->m_Socket;
  mr.imr_interface.S_un.S_un_b.s_b4 = v10;
  addr = 0x200000;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 4098, optval: (const char *)&addr, optlen: 4);
  if ( setsockopt(s: this->m_Socket, level: 0, optname: 12, optval: (const char *)&mr, optlen: 8) != 0 )
    return 0;
  S_un = mr.imr_multiaddr.S_un;
  v12 = mr.imr_interface.S_un;
  this->m_bMulticastGroupMembership = true;
  this->m_MulticastGroupMREQ.imr_multiaddr.S_un = S_un;
  this->m_MulticastGroupMREQ.imr_interface.S_un = v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004012F0
// Name: public: virtual bool CIPSocket::SendTo(class CIPAddr const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::SendTo(CIPSocket *this, const CIPAddr *pAddr, const void *pData, int len)
{
  return this->SendChunksTo(this, a2: pAddr, a3: &pData, a4: &len, a5: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00401310
// Name: public: virtual bool CIPSocket::SendChunksTo(class CIPAddr const __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CIPSocket::SendChunksTo(
        CIPSocket *this,
        const CIPAddr *pAddr,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  signed int v5; // ebx
  char *v6; // edx
  signed int v7; // eax
  int v8; // esi
  unsigned int *v9; // ecx
  char *v10; // ebx
  unsigned int v11; // edx
  char *v12; // ebx
  unsigned int v13; // edx
  unsigned int v14; // edx
  char *v15; // ecx
  u_short port; // ax
  u_short v17; // ax
  unsigned __int8 v18; // dl
  unsigned __int8 v19; // cl
  unsigned __int8 v20; // cl
  SOCKET m_Socket; // eax
  _WSABUF bufs[32]; // [esp+Ch] [ebp-124h] BYREF
  CIPSocket *v24; // [esp+10Ch] [ebp-24h]
  int nTotalBytes; // [esp+110h] [ebp-20h]
  sockaddr_in addr; // [esp+114h] [ebp-1Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+124h] [ebp-Ch] BYREF
  int v28; // [esp+128h] [ebp-8h]
  int v29; // [esp+12Ch] [ebp-4h]

  v5 = nChunks;
  v24 = this;
  if ( nChunks > 32 )
    _Error(a1: "CIPSocket::SendChunksTo: too many chunks (%d).", nChunks);
  v6 = pChunkLengths;
  v7 = 0;
  v8 = 0;
  v29 = 0;
  v28 = 0;
  nTotalBytes = 0;
  if ( nChunks >= 2 )
  {
    v9 = (unsigned int *)(pChunkLengths + 4);
    do
    {
      v10 = (char *)pChunks[v7];
      v11 = *(v9 - 1);
      v29 += v11;
      bufs[v7].buf = v10;
      v12 = *(char **)((char *)v9 + (char *)pChunks - pChunkLengths);
      bufs[v7].len = v11;
      v13 = *v9;
      v28 += *v9;
      bufs[v7 + 1].buf = v12;
      v5 = nChunks;
      bufs[v7 + 1].len = v13;
      v7 += 2;
      v9 += 2;
    }
    while ( v7 < nChunks - 1 );
    v6 = pChunkLengths;
    v8 = nTotalBytes;
  }
  if ( v7 < v5 )
  {
    v14 = *(_DWORD *)&v6[4 * v7];
    v15 = (char *)pChunks[v7];
    bufs[v7].len = v14;
    bufs[v7].buf = v15;
    v8 = v14;
  }
  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v17 = htons(hostshort: port);
  v18 = pAddr->ip[1];
  v19 = pAddr->ip[0];
  addr.sin_port = v17;
  LOBYTE(v17) = pAddr->ip[2];
  addr.sin_addr.S_un.S_un_b.s_b2 = v18;
  addr.sin_addr.S_un.S_un_b.s_b1 = v19;
  v20 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v17;
  m_Socket = v24->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v20;
  dwNumBytesSent = 0;
  return WSASendTo(
           s: m_Socket,
           lpBuffers: bufs,
           dwBufferCount: v5,
           lpNumberOfBytesSent: &dwNumBytesSent,
           dwFlags: 0,
           lpTo: (const struct sockaddr *)&addr,
           iTolen: 16,
           lpOverlapped: nullptr,
           lpCompletionRoutine: nullptr) == 0
      && dwNumBytesSent == v8 + v29 + v28;
}

//------------------------------------------------------------------------------
// Address: 0x00401450
// Name: IP_FloatTime
// Source: json
//------------------------------------------------------------------------------
long double __cdecl IP_FloatTime()
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x004014B0
// Name: public: virtual bool CIPSocket::CreateSocket(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::CreateSocket(CIPSocket *this)
{
  SOCKET m_Socket; // eax
  SOCKET v3; // edi
  unsigned int val; // [esp+8h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  if ( m_Socket != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: m_Socket, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  v3 = socket(af: 2, type: 2, protocol: 0);
  if ( v3 == -1 )
    return 0;
  val = 1;
  if ( ioctlsocket(s: v3, cmd: -2147195266, argp: &val) != 0 )
  {
    closesocket(s: v3);
    return 0;
  }
  this->m_Socket = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401540
// Name: public: virtual bool CIPSocket::BindPart2(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::BindPart2(CIPSocket *this, const CIPAddr *pAddr)
{
  u_short port; // cx
  u_short v4; // ax
  unsigned __int8 v5; // dl
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // dl
  SOCKET v9; // eax
  SOCKET m_Socket; // [esp-Ch] [ebp-24h]
  sockaddr_in addr; // [esp+8h] [ebp-10h] BYREF

  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v4 = htons(hostshort: port);
  v5 = pAddr->ip[0];
  v6 = pAddr->ip[2];
  addr.sin_port = v4;
  addr.sin_addr.S_un.S_un_b.s_b2 = pAddr->ip[1];
  addr.sin_addr.S_un.S_un_b.s_b1 = v5;
  v7 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v6;
  m_Socket = this->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v7;
  if ( bind(s: m_Socket, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
    return 1;
  v9 = this->m_Socket;
  if ( v9 != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: v9, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004015F0
// Name: public: virtual bool CIPSocket::BindToAny(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::BindToAny(CIPSocket *this, unsigned __int16 port)
{
  bool (__thiscall *Bind)(struct CIPSocket *, const CIPAddr *); // edx
  CIPAddr addr; // [esp+0h] [ebp-8h] BYREF

  Bind = this->Bind;
  addr.port = port;
  *(_DWORD *)addr.ip = 0;
  return Bind(this, a2: &addr);
}

//------------------------------------------------------------------------------
// Address: 0x00401620
// Name: public: virtual bool CIPSocket::Broadcast(void const __near *,int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Broadcast(CIPSocket *this, const void *pData, int len, unsigned __int16 port)
{
  CIPSocket_vtbl *v6; // eax
  bool (__thiscall *SendTo)(struct CIPSocket *, const CIPAddr *, const void *, const int); // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  CIPAddr addr; // [esp+4h] [ebp-Ch] BYREF
  int bBroadcast; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bSetupToBroadcast )
  {
    m_Socket = this->m_Socket;
    bBroadcast = 1;
    if ( setsockopt(s: m_Socket, level: 0xFFFF, optname: 32, optval: (const char *)&bBroadcast, optlen: 4) != 0 )
      return false;
    this->m_bSetupToBroadcast = true;
  }
  v6 = this->__vftable;
  addr.port = port;
  SendTo = v6->SendTo;
  *(_DWORD *)addr.ip = -1;
  return SendTo(this, a2: &addr, a3: pData, a4: len);
}

//------------------------------------------------------------------------------
// Address: 0x00401690
// Name: public: virtual int CIPSocket::RecvFrom(void __near *,int,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CIPSocket::RecvFrom(CIPSocket *this, char *pData, int maxDataLen, CIPAddr *pFrom)
{
  unsigned int m_Socket; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  SOCKET v10; // [esp-1Ch] [ebp-140h]
  fd_set readSet; // [esp+4h] [ebp-120h] BYREF
  sockaddr_in sender; // [esp+108h] [ebp-1Ch] BYREF
  timeval timeVal; // [esp+118h] [ebp-Ch] BYREF
  int fromSize; // [esp+120h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  timeVal.tv_usec = 0;
  readSet.fd_array[0] = m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  v6 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v6 == 0 || v6 == -1 )
    return -1;
  v10 = this->m_Socket;
  fromSize = 16;
  v7 = recvfrom(s: v10, buf: pData, len: maxDataLen, flags: 0, from: (struct sockaddr *)&sender, fromlen: &fromSize);
  v8 = v7;
  if ( v7 == 0 || v7 == -1 )
    return -1;
  if ( pFrom != nullptr )
    SockAddrToIPAddr(pIn: &sender, pOut: pFrom);
  this->m_flLastRecvTime = IP_FloatTime();
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00401740
// Name: public: virtual double CIPSocket::GetRecvTimeout(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CIPSocket::GetRecvTimeout(CIPSocket *this)
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier - this->m_flLastRecvTime;
}

//------------------------------------------------------------------------------
// Address: 0x00401800
// Name: class ISocket __near * CreateIPSocket(void)
// Source: json
//------------------------------------------------------------------------------
ISocket *__cdecl CreateIPSocket()
{
  ISocket *result; // eax

  result = (ISocket *)operator new(nSize: 0x28u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ISocket_vtbl *)&CIPSocket::`vftable';
  result[1].__vftable = (ISocket_vtbl *)-1;
  LOBYTE(result[5].__vftable) = 0;
  return result;
}

} // namespace vmpi_service

// ============================================================
// Overlay from vmpi_services_watch (Missing functions)
// ============================================================
namespace vmpi_services_watch {

//------------------------------------------------------------------------------
// Address: 0x00406B70
// Name: void SockAddrToIPAddr(struct sockaddr_in const __near *,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SockAddrToIPAddr(const sockaddr_in *pIn, CIPAddr *pOut)
{
  *(_DWORD *)pOut->ip = pIn->sin_addr.S_un.S_addr;
  pOut->port = ntohs(netshort: pIn->sin_port);
}

//------------------------------------------------------------------------------
// Address: 0x00406BB0
// Name: public: CIPAddr::CIPAddr(void)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(CIPAddr *this)
{
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00406BC0
// Name: public: virtual void CIPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIPSocket::Release(CIPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CIPSocket *, int))this->dtr_CIPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00406BD0
// Name: public: virtual bool CIPSocket::Bind(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Bind(CIPSocket *this, const CIPAddr *pAddr)
{
  bool result; // al

  result = this->CreateSocket(this);
  if ( result )
    return this->BindPart2(this, a2: pAddr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406C00
// Name: public: virtual bool CIPSocket::ListenToMulticastStream(class CIPAddr const __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::ListenToMulticastStream(CIPSocket *this, int addr, const CIPAddr *localInterface)
{
  unsigned __int8 v3; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // dl
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // dl
  in_addr::<unnamed_type_S_un> S_un; // ecx
  in_addr::<unnamed_type_S_un> v12; // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  ip_mreq mr; // [esp+8h] [ebp-8h] BYREF

  v3 = *(_BYTE *)(addr + 1);
  mr.imr_multiaddr.S_un.S_un_b.s_b1 = *(_BYTE *)addr;
  v5 = *(_BYTE *)(addr + 2);
  mr.imr_multiaddr.S_un.S_un_b.s_b2 = v3;
  v6 = *(_BYTE *)(addr + 3);
  mr.imr_multiaddr.S_un.S_un_b.s_b3 = v5;
  v7 = localInterface->ip[0];
  mr.imr_multiaddr.S_un.S_un_b.s_b4 = v6;
  v8 = localInterface->ip[1];
  mr.imr_interface.S_un.S_un_b.s_b1 = v7;
  v9 = localInterface->ip[2];
  mr.imr_interface.S_un.S_un_b.s_b2 = v8;
  v10 = localInterface->ip[3];
  mr.imr_interface.S_un.S_un_b.s_b3 = v9;
  m_Socket = this->m_Socket;
  mr.imr_interface.S_un.S_un_b.s_b4 = v10;
  addr = 0x200000;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 4098, optval: (const char *)&addr, optlen: 4);
  if ( setsockopt(s: this->m_Socket, level: 0, optname: 12, optval: (const char *)&mr, optlen: 8) != 0 )
    return 0;
  S_un = mr.imr_multiaddr.S_un;
  v12 = mr.imr_interface.S_un;
  this->m_bMulticastGroupMembership = true;
  this->m_MulticastGroupMREQ.imr_multiaddr.S_un = S_un;
  this->m_MulticastGroupMREQ.imr_interface.S_un = v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406CA0
// Name: public: virtual bool CIPSocket::SendTo(class CIPAddr const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::SendTo(CIPSocket *this, const CIPAddr *pAddr, const void *pData, int len)
{
  return this->SendChunksTo(this, a2: pAddr, a3: &pData, a4: &len, a5: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00406CC0
// Name: public: virtual bool CIPSocket::SendChunksTo(class CIPAddr const __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CIPSocket::SendChunksTo(
        CIPSocket *this,
        const CIPAddr *pAddr,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  signed int v5; // ebx
  char *v6; // edx
  signed int v7; // eax
  int v8; // esi
  unsigned int *v9; // ecx
  char *v10; // ebx
  unsigned int v11; // edx
  char *v12; // ebx
  unsigned int v13; // edx
  unsigned int v14; // edx
  char *v15; // ecx
  u_short port; // ax
  u_short v17; // ax
  unsigned __int8 v18; // dl
  unsigned __int8 v19; // cl
  unsigned __int8 v20; // cl
  SOCKET m_Socket; // eax
  int *v23; // [esp+0h] [ebp-130h]
  _WSABUF bufs[32]; // [esp+Ch] [ebp-124h] BYREF
  CIPSocket *v25; // [esp+10Ch] [ebp-24h]
  int nTotalBytes; // [esp+110h] [ebp-20h]
  sockaddr_in addr; // [esp+114h] [ebp-1Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+124h] [ebp-Ch] BYREF
  int v29; // [esp+128h] [ebp-8h]
  int v30; // [esp+12Ch] [ebp-4h]

  v5 = nChunks;
  v25 = this;
  if ( nChunks > 32 )
    _Error(this: (IVBDSC *)&stru_52C230, a2: nChunks, a3: v23);
  v6 = pChunkLengths;
  v7 = 0;
  v8 = 0;
  v30 = 0;
  v29 = 0;
  nTotalBytes = 0;
  if ( nChunks >= 2 )
  {
    v9 = (unsigned int *)(pChunkLengths + 4);
    do
    {
      v10 = (char *)pChunks[v7];
      v11 = *(v9 - 1);
      v30 += v11;
      bufs[v7].buf = v10;
      v12 = *(char **)((char *)v9 + (char *)pChunks - pChunkLengths);
      bufs[v7].len = v11;
      v13 = *v9;
      v29 += *v9;
      bufs[v7 + 1].buf = v12;
      v5 = nChunks;
      bufs[v7 + 1].len = v13;
      v7 += 2;
      v9 += 2;
    }
    while ( v7 < nChunks - 1 );
    v6 = pChunkLengths;
    v8 = nTotalBytes;
  }
  if ( v7 < v5 )
  {
    v14 = *(_DWORD *)&v6[4 * v7];
    v15 = (char *)pChunks[v7];
    bufs[v7].len = v14;
    bufs[v7].buf = v15;
    v8 = v14;
  }
  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v17 = htons(hostshort: port);
  v18 = pAddr->ip[1];
  v19 = pAddr->ip[0];
  addr.sin_port = v17;
  LOBYTE(v17) = pAddr->ip[2];
  addr.sin_addr.S_un.S_un_b.s_b2 = v18;
  addr.sin_addr.S_un.S_un_b.s_b1 = v19;
  v20 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v17;
  m_Socket = v25->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v20;
  dwNumBytesSent = 0;
  return WSASendTo(
           s: m_Socket,
           lpBuffers: bufs,
           dwBufferCount: v5,
           lpNumberOfBytesSent: &dwNumBytesSent,
           dwFlags: 0,
           lpTo: (const struct sockaddr *)&addr,
           iTolen: 16,
           lpOverlapped: nullptr,
           lpCompletionRoutine: nullptr) == 0
      && dwNumBytesSent == v8 + v30 + v29;
}

//------------------------------------------------------------------------------
// Address: 0x00406E00
// Name: IP_FloatTime
// Source: json
//------------------------------------------------------------------------------
long double __cdecl IP_FloatTime()
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x00406E60
// Name: public: virtual bool CIPSocket::CreateSocket(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::CreateSocket(CIPSocket *this)
{
  SOCKET m_Socket; // eax
  SOCKET v3; // edi
  unsigned int val; // [esp+8h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  if ( m_Socket != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: m_Socket, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  v3 = socket(af: 2, type: 2, protocol: 0);
  if ( v3 == -1 )
    return 0;
  val = 1;
  if ( ioctlsocket(s: v3, cmd: -2147195266, argp: &val) != 0 )
  {
    closesocket(s: v3);
    return 0;
  }
  this->m_Socket = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406EF0
// Name: public: virtual bool CIPSocket::BindPart2(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::BindPart2(CIPSocket *this, const CIPAddr *pAddr)
{
  u_short port; // cx
  u_short v4; // ax
  unsigned __int8 v5; // dl
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // dl
  SOCKET v9; // eax
  SOCKET m_Socket; // [esp-Ch] [ebp-24h]
  sockaddr_in addr; // [esp+8h] [ebp-10h] BYREF

  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v4 = htons(hostshort: port);
  v5 = pAddr->ip[0];
  v6 = pAddr->ip[2];
  addr.sin_port = v4;
  addr.sin_addr.S_un.S_un_b.s_b2 = pAddr->ip[1];
  addr.sin_addr.S_un.S_un_b.s_b1 = v5;
  v7 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v6;
  m_Socket = this->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v7;
  if ( bind(s: m_Socket, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
    return 1;
  v9 = this->m_Socket;
  if ( v9 != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: v9, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406FA0
// Name: public: virtual bool CIPSocket::BindToAny(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::BindToAny(CIPSocket *this, unsigned __int16 port)
{
  bool (__thiscall *Bind)(struct CIPSocket *, const CIPAddr *); // edx
  CIPAddr addr; // [esp+0h] [ebp-8h] BYREF

  Bind = this->Bind;
  addr.port = port;
  *(_DWORD *)addr.ip = 0;
  return Bind(this, a2: &addr);
}

//------------------------------------------------------------------------------
// Address: 0x00406FD0
// Name: public: virtual bool CIPSocket::Broadcast(void const __near *,int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Broadcast(CIPSocket *this, const void *pData, int len, unsigned __int16 port)
{
  CIPSocket_vtbl *v6; // eax
  bool (__thiscall *SendTo)(struct CIPSocket *, const CIPAddr *, const void *, const int); // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  CIPAddr addr; // [esp+4h] [ebp-Ch] BYREF
  int bBroadcast; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bSetupToBroadcast )
  {
    m_Socket = this->m_Socket;
    bBroadcast = 1;
    if ( setsockopt(s: m_Socket, level: 0xFFFF, optname: 32, optval: (const char *)&bBroadcast, optlen: 4) != 0 )
      return false;
    this->m_bSetupToBroadcast = true;
  }
  v6 = this->__vftable;
  addr.port = port;
  SendTo = v6->SendTo;
  *(_DWORD *)addr.ip = -1;
  return SendTo(this, a2: &addr, a3: pData, a4: len);
}

//------------------------------------------------------------------------------
// Address: 0x00407040
// Name: public: virtual int CIPSocket::RecvFrom(void __near *,int,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CIPSocket::RecvFrom(CIPSocket *this, char *pData, int maxDataLen, CIPAddr *pFrom)
{
  unsigned int m_Socket; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  SOCKET v10; // [esp-1Ch] [ebp-140h]
  fd_set readSet; // [esp+4h] [ebp-120h] BYREF
  sockaddr_in sender; // [esp+108h] [ebp-1Ch] BYREF
  timeval timeVal; // [esp+118h] [ebp-Ch] BYREF
  int fromSize; // [esp+120h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  timeVal.tv_usec = 0;
  readSet.fd_array[0] = m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  v6 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v6 == 0 || v6 == -1 )
    return -1;
  v10 = this->m_Socket;
  fromSize = 16;
  v7 = recvfrom(s: v10, buf: pData, len: maxDataLen, flags: 0, from: (struct sockaddr *)&sender, fromlen: &fromSize);
  v8 = v7;
  if ( v7 == 0 || v7 == -1 )
    return -1;
  if ( pFrom != nullptr )
    SockAddrToIPAddr(pIn: &sender, pOut: pFrom);
  this->m_flLastRecvTime = IP_FloatTime();
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004070F0
// Name: public: virtual double CIPSocket::GetRecvTimeout(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CIPSocket::GetRecvTimeout(CIPSocket *this)
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier - this->m_flLastRecvTime;
}

//------------------------------------------------------------------------------
// Address: 0x004071B0
// Name: class ISocket __near * CreateIPSocket(void)
// Source: json
//------------------------------------------------------------------------------
ISocket *__cdecl CreateIPSocket()
{
  ISocket *result; // eax

  result = (ISocket *)operator new(nSize: 0x28u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ISocket_vtbl *)&CIPSocket::`vftable';
  result[1].__vftable = (ISocket_vtbl *)-1;
  LOBYTE(result[5].__vftable) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424C12
// Name: public: static void ATL::CAccessorBase::Bind(struct tagDBBINDING __near *,unsigned long,unsigned short,unsigned long,unsigned char,unsigned char,unsigned long,unsigned long,unsigned long,unsigned long,struct tagDBOBJECT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ATL::CAccessorBase::Bind(
        tagDBBINDING *pBinding,
        unsigned int nOrdinal,
        unsigned __int16 wType,
        unsigned int nLength,
        unsigned __int8 nPrecision,
        unsigned __int8 nScale,
        unsigned int eParamIO,
        unsigned int nDataOffset,
        unsigned int nLengthOffset,
        unsigned int nStatusOffset,
        tagDBOBJECT *pdbobject)
{
  if ( pBinding == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  pBinding->wType = wType;
  pBinding->bPrecision = nPrecision;
  pBinding->dwMemOwner = (wType & 0x4000) != 0;
  pBinding->bScale = nScale;
  pBinding->pObject = pdbobject;
  pBinding->obValue = nDataOffset;
  pBinding->eParamIO = eParamIO;
  pBinding->cbMaxLen = nLength;
  pBinding->iOrdinal = nOrdinal;
  pBinding->dwFlags = 0;
  pBinding->obLength = 0;
  pBinding->obStatus = 0;
  pBinding->pTypeInfo = nullptr;
  pBinding->pBindExt = nullptr;
  pBinding->dwPart = 1;
  if ( nLengthOffset != 0 )
  {
    pBinding->dwPart = 3;
    pBinding->obLength = nLengthOffset;
  }
  if ( nStatusOffset != 0 )
  {
    pBinding->dwPart |= 4u;
    pBinding->obStatus = nStatusOffset;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004071D3
// Name: int AfxNewHandler(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl __noreturn AfxNewHandler()
{
  AfxThrowMemoryException();
}

//------------------------------------------------------------------------------
// Address: 0x004071D8
// Name: int (*AfxSetNewHandler(int (*)(unsigned int)))(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int (__cdecl *__stdcall AfxSetNewHandler(int (__cdecl *pfnNewHandler)(unsigned int)))(unsigned int)
{
  int (__cdecl *result)(unsigned int); // eax

  result = _afxNewHandler;
  _afxNewHandler = pfnNewHandler;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004071EF
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __cdecl operator new(unsigned int nSize)
{
  LPVOID result; // eax

  result = malloc(size: nSize);
  if ( result == nullptr && _afxNewHandler != nullptr )
    _afxNewHandler(a1: nSize);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040721E
// Name: void operator delete(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl operator delete(void *p)
{
  free(pBlock: p);
}

//------------------------------------------------------------------------------
// Address: 0x00407229
// Name: void __near * operator new[](unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __cdecl operator new[](unsigned int nSize)
{
  return operator new(nSize);
}

//------------------------------------------------------------------------------
// Address: 0x00407234
// Name: int AfxDlgProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__stdcall AfxDlgProc(HWND__ *hWnd, unsigned int message, unsigned int __formal, int a4)
{
  CWnd *v4; // eax
  CObject *v5; // eax

  if ( message != 272 )
    return nullptr;
  v4 = CWnd::FromHandlePermanent(hWnd);
  v5 = AfxDynamicDownCast(pClass: &CDialog::classCDialog, pObject: v4);
  if ( v5 != nullptr )
    return v5->__vftable[31].GetRuntimeClass(this: v5);
  else
    return (CRuntimeClass *)1;
}

//------------------------------------------------------------------------------
// Address: 0x00424C9F
// Name: public: bool ATL::CDynamicAccessor::GetColumnType(unsigned long,unsigned short __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::GetColumnType(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        unsigned __int16 *pType)
{
  if ( ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 || pType == nullptr )
    return 0;
  *pType = this->m_pColumnInfo[nColumn].wType;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00424CD7
// Name: public: void __near * ATL::CDynamicAccessor::GetValue(unsigned long)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall ATL::CDynamicAccessor::GetValue(ATL::CDynamicAccessor *this, unsigned int nColumn)
{
  if ( ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) != 0 )
    return &this->m_pBuffer[(unsigned int)this->m_pColumnInfo[nColumn].pTypeInfo];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00424D05
// Name: public: wchar_t __near * ATL::CDynamicAccessor::GetColumnName(unsigned long)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t *__thiscall ATL::CDynamicAccessor::GetColumnName(ATL::CDynamicAccessor *this, unsigned int nColumn)
{
  if ( ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) != 0 )
    return this->m_pColumnInfo[nColumn].pwszName;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00424D2F
// Name: public: ATL::CComPtr<struct IAccessibleProxy>::~CComPtr<struct IAccessibleProxy>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CComPtr<IAccessibleProxy>::~CComPtr<IAccessibleProxy>(
        ATL::CComQIPtr<ITaskbarList4,&_GUID_c43dc798_95d1_4bea_9030_bb99e2983a1a> *this)
{
  if ( this->p != nullptr )
    this->p->Release(this: this->p);
}

//------------------------------------------------------------------------------
// Address: 0x00424D3C
// Name: public: void ATL::CManualAccessor::AddBindEntry(unsigned long,unsigned short,unsigned long,void __near *,void __near *,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CManualAccessor::AddBindEntry(
        ATL::CManualAccessor *this,
        unsigned int nOrdinal,
        unsigned __int16 wType,
        unsigned int nColumnSize,
        void *pData,
        _BYTE *pLength,
        _BYTE *pStatus)
{
  unsigned int v8; // eax
  unsigned int v9; // ecx

  if ( pStatus != nullptr )
    v8 = pStatus - this->m_pBuffer;
  else
    v8 = 0;
  if ( pLength != nullptr )
    v9 = pLength - this->m_pBuffer;
  else
    v9 = 0;
  ATL::CAccessorBase::Bind(
    pBinding: &this->m_pEntry[this->m_nEntry],
    nOrdinal,
    wType,
    nLength: nColumnSize,
    nPrecision: 0,
    nScale: 0,
    eParamIO: 0,
    nDataOffset: (unsigned int)pData - (unsigned int)this->m_pBuffer,
    nLengthOffset: v9,
    nStatusOffset: v8,
    pdbobject: nullptr);
  ++this->m_nEntry;
}

//------------------------------------------------------------------------------
// Address: 0x00424D92
// Name: protected: int COleControlSite::SetExtent(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall COleControlSite::SetExtent(COleControlSite *this)
{
  int v2; // eax
  IOleObject *m_pObject; // eax
  int v4; // edi
  CClientDC dc; // [esp+10h] [ebp-28h] BYREF
  CSize size; // [esp+24h] [ebp-14h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  v2 = this->m_rect.bottom - this->m_rect.top;
  size.cx = this->m_rect.right - this->m_rect.left;
  size.cy = v2;
  CClientDC::CClientDC(this: &dc, pWnd: nullptr);
  v8 = 0;
  CDC::DPtoHIMETRIC(this: &dc, lpSize: &size);
  m_pObject = this->m_pObject;
  if ( m_pObject == nullptr )
    AfxThrowInvalidArgException();
  v4 = m_pObject->SetExtent(this: m_pObject, a2: 1u, a3: &size);
  if ( v4 >= 0 && this->m_pObject->GetExtent(this: this->m_pObject, a2: 1u, a3: &size) >= 0 )
  {
    CDC::HIMETRICtoDP(this: &dc, lpSize: &size);
    this->m_rect.right = size.cx + this->m_rect.left;
    this->m_rect.bottom = size.cy + this->m_rect.top;
  }
  v8 = -1;
  CClientDC::~CClientDC(this: &dc);
  return v4 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424E3F
// Name: public: virtual long COleControlSite::CreateControl(class CWnd __near *,struct _GUID const __near &,char const __near *,unsigned long,struct tagRECT const __near &,unsigned int,class CFile __near *,int,wchar_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall COleControlSite::CreateControl(
        COleControlSite *this,
        CWnd *pWndCtrl,
        const _GUID *clsid,
        const char *lpszWindowName,
        unsigned int dwStyle,
        const tagRECT *rect,
        unsigned int nID,
        CFile *pPersist,
        int bStorage,
        wchar_t *bstrLicKey)
{
  COleControlSite_vtbl *v11; // eax
  CPoint pt; // [esp+Ch] [ebp-30h] BYREF
  CSize size; // [esp+14h] [ebp-28h] BYREF
  wchar_t *v15; // [esp+1Ch] [ebp-20h]
  CFile *v16; // [esp+20h] [ebp-1Ch]
  const char *v17; // [esp+24h] [ebp-18h]
  CRect rect2; // [esp+28h] [ebp-14h] BYREF

  v17 = lpszWindowName;
  v16 = pPersist;
  v15 = bstrLicKey;
  CopyRect(lprcDst: &rect2, lprcSrc: rect);
  pt.x = rect2.left;
  size.cy = rect2.bottom - rect2.top;
  size.cx = rect2.right - rect2.left;
  v11 = this->__vftable;
  pt.y = rect2.top;
  return v11->CreateControl(
           this,
           a2: pWndCtrl,
           a3: clsid,
           a4: lpszWindowName,
           a5: dwStyle,
           a6: &pt,
           a7: &size,
           a8: nID,
           a9: pPersist,
           a10: bStorage,
           a11: bstrLicKey);
}

//------------------------------------------------------------------------------
// Address: 0x00424ECC
// Name: protected: virtual long COleControlSite::CreateControlCommon(class CWnd __near *,struct _GUID const __near &,class CControlCreationInfo const __near &,char const __near *,unsigned long,struct tagPOINT const __near *,struct tagSIZE const __near *,unsigned int,class CFile __near *,int,wchar_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall COleControlSite::CreateControlCommon(
        COleControlSite *this,
        CWnd *pWndCtrl,
        const _GUID *clsid,
        const CControlCreationInfo *creationInfo,
        const char *lpszWindowName,
        unsigned int dwStyle,
        const tagPOINT *ppt,
        const tagSIZE *psize,
        unsigned int nID,
        CFile *pPersist,
        int bStorage,
        wchar_t *bstrLicKey)
{
  bool v14; // zf
  COleControlSite_vtbl *v15; // eax
  int v16; // eax
  IOleObject_vtbl *v17; // ecx
  int v18; // esi
  int cy; // edx
  int cx; // ecx
  int y; // esi
  unsigned int m_dwMiscStatus; // eax
  IOleInPlaceObject **p_m_pInPlaceObject; // edi
  int v24; // eax
  IOleObject *v25; // eax
  IOleObject *m_pObject; // [esp-Ch] [ebp-54h]
  CClientDC dc; // [esp+10h] [ebp-38h] BYREF
  int x; // [esp+24h] [ebp-24h]
  int v29; // [esp+28h] [ebp-20h]
  int v30; // [esp+2Ch] [ebp-1Ch]
  int v31; // [esp+30h] [ebp-18h]
  CSize size; // [esp+34h] [ebp-14h] BYREF
  int v33; // [esp+44h] [ebp-4h]
  HRESULT hr; // [esp+58h] [ebp+10h]

  this->m_hWnd = nullptr;
  size.cx = 0;
  size.cy = 0;
  if ( pWndCtrl != nullptr )
  {
    this->m_pWndCtrl = pWndCtrl;
    pWndCtrl->m_pCtrlSite = this;
  }
  if ( AfxGetThreadState()->m_bNeedTerm == 0 && AfxOleInit() == 0 )
    return -2147467259;
  v14 = !CControlCreationInfo::IsManaged(this: creationInfo);
  v15 = this->__vftable;
  if ( v14 )
    v16 = v15->CreateOrLoad(this, a2: clsid, a3: pPersist, a4: bStorage, a5: bstrLicKey);
  else
    v16 = v15->CreateOrLoad(this, a2: creationInfo);
  hr = v16;
  if ( v16 >= 0 )
  {
    if ( this->m_pObject == nullptr || (this->m_nID = nID, ppt == nullptr) )
      AfxThrowInvalidArgException();
    if ( psize != nullptr )
    {
      cy = psize->cy;
      cx = psize->cx;
      y = ppt->y;
      x = ppt->x;
      v29 = y;
      v30 = cx + x;
      v31 = y + cy;
      this->m_rect.left = x;
      this->m_rect.top = v29;
      this->m_rect.right = v30;
      this->m_rect.bottom = v31;
    }
    else
    {
      CClientDC::CClientDC(this: &dc, pWnd: nullptr);
      v17 = this->m_pObject->__vftable;
      m_pObject = this->m_pObject;
      v33 = 0;
      v17->GetExtent(this: m_pObject, a2: 1u, a3: &size);
      CDC::HIMETRICtoDP(this: &dc, lpSize: &size);
      v18 = ppt->y;
      x = ppt->x;
      v33 = -1;
      v30 = size.cx + x;
      v29 = v18;
      v31 = v18 + size.cy;
      this->m_rect.left = x;
      this->m_rect.top = v29;
      this->m_rect.right = v30;
      this->m_rect.bottom = v31;
      CClientDC::~CClientDC(this: &dc);
    }
    m_dwMiscStatus = this->m_dwMiscStatus;
    this->m_dwStyleMask = 196608;
    if ( (m_dwMiscStatus & 0x1000) != 0 )
      this->m_dwStyleMask = 196609;
    if ( (m_dwMiscStatus & 0x400) != 0 )
      dwStyle &= ~0x10000000u;
    this->m_dwStyle = dwStyle & this->m_dwStyleMask;
    if ( hr != 1 )
    {
      this->m_dwEventSink = COleControlSite::ConnectSink(this, iid: &this->m_iidEvents, punkSink: &this->m_xEventSink);
      this->m_dwPropNotifySink = COleControlSite::ConnectSink(
                                   this,
                                   iid: &IID_IPropertyNotifySink,
                                   punkSink: &this->m_xPropertyNotifySink);
    }
    this->m_dwNotifyDBEvents = COleControlSite::ConnectSink(
                                 this,
                                 iid: &IID_INotifyDBEvents,
                                 punkSink: &this->m_xNotifyDBEvents);
    COleControlSite::SetExtent(this);
    p_m_pInPlaceObject = &this->m_pInPlaceObject;
    hr = this->m_pObject->QueryInterface(
           this: this->m_pObject,
           a2: &IID_IOleInPlaceObject,
           a3: (void **)&this->m_pInPlaceObject);
    if ( hr >= 0 )
    {
      if ( (dwStyle & 0x10000000) != 0 )
      {
        v24 = this->DoVerb(this, a2: -5, a3: nullptr);
      }
      else
      {
        OffsetRect(lprc: &this->m_rect, dx: -32000, dy: -32000);
        hr = this->DoVerb(this, a2: -5, a3: nullptr);
        if ( hr < 0 )
          goto LABEL_30;
        hr = this->DoVerb(this, a2: -3, a3: nullptr);
        if ( hr < 0 )
          goto LABEL_30;
        OffsetRect(lprc: &this->m_rect, dx: 32000, dy: 32000);
        v24 = (*p_m_pInPlaceObject)->SetObjectRects(this: *p_m_pInPlaceObject, a2: &this->m_rect, a3: &this->m_rect);
      }
      hr = v24;
      if ( v24 >= 0 )
      {
        this->m_pCtrlCont->m_pSiteFocus = this;
        COleControlSite::GetControlInfo(this);
LABEL_33:
        COleControlSite::AttachWindow(this);
        if ( lpszWindowName != nullptr )
          this->SetWindowTextA(this, a2: lpszWindowName);
        this->ModifyStyle(this, a2: 0, a3: this->m_dwStyle | dwStyle & 0x8800000, a4: 0);
        return hr;
      }
    }
LABEL_30:
    if ( *p_m_pInPlaceObject != nullptr )
    {
      (*p_m_pInPlaceObject)->Release(this: *p_m_pInPlaceObject);
      *p_m_pInPlaceObject = nullptr;
    }
    COleControlSite::DisconnectSink(this, iid: &this->m_iidEvents, dwCookie: this->m_dwEventSink);
    COleControlSite::DisconnectSink(this, iid: &IID_IPropertyNotifySink, dwCookie: this->m_dwPropNotifySink);
    COleControlSite::DisconnectSink(this, iid: &IID_INotifyDBEvents, dwCookie: this->m_dwNotifyDBEvents);
    v25 = this->m_pObject;
    this->m_dwEventSink = 0;
    this->m_dwPropNotifySink = 0;
    this->m_dwNotifyDBEvents = 0;
    v25->Release(this: v25);
    this->m_pObject = nullptr;
    if ( hr < 0 )
      return hr;
    goto LABEL_33;
  }
  return hr;
}

//------------------------------------------------------------------------------
// Address: 0x004251A6
// Name: public: virtual int COleControlSite::DestroyControl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleControlSite::DestroyControl(COleControlSite *this)
{
  HWND__ *m_hWnd; // eax
  COleControlContainer *m_pCtrlCont; // ecx
  CPtrList::CNode *m_pNodeHead; // eax
  __POSITION *v5; // ebx
  COleControlSiteOrWnd *data; // edi

  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
    CMapPtrToPtr::RemoveKey(this: &this->m_pCtrlCont->m_siteMap, key: (CDocument *)m_hWnd);
  this->ShowWindow(this, a2: 0);
  m_pCtrlCont = this->m_pCtrlCont;
  m_pNodeHead = m_pCtrlCont->m_listSitesOrWnds.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
    {
      ((void (__thiscall *)(COleControlSite *, int))this->dtr_CObject)(a1: this, a2: 1);
      return 1;
    }
    v5 = (__POSITION *)m_pNodeHead;
    data = (COleControlSiteOrWnd *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
  }
  while ( data->m_pSite != this );
  CPtrList::RemoveAt(this: (CObList *)&m_pCtrlCont->m_listSitesOrWnds, position: v5);
  COleControlSiteOrWnd::~COleControlSiteOrWnd(this: data);
  operator delete(p: data);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042521C
// Name: public: virtual int COleControlSite::QuickActivate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleControlSite::QuickActivate(COleControlSite *this)
{
  IOleObject *m_pObject; // eax
  unsigned int v3; // ebx
  IOleObject_vtbl *v4; // ecx
  COleControlContainer *m_pCtrlCont; // eax
  CWnd *m_pWnd; // edi
  _DWORD v8[5]; // [esp+10h] [ebp-80h] BYREF
  int v9; // [esp+24h] [ebp-6Ch]
  unsigned int Lo32; // [esp+28h] [ebp-68h]
  unsigned int v11; // [esp+2Ch] [ebp-64h]
  _DWORD v12[8]; // [esp+30h] [ebp-60h] BYREF
  int v13; // [esp+50h] [ebp-40h]
  tagVARIANT pVar; // [esp+54h] [ebp-3Ch] BYREF
  int v15; // [esp+64h] [ebp-2Ch] BYREF
  _DWORD v16[10]; // [esp+68h] [ebp-28h] BYREF

  m_pObject = this->m_pObject;
  v3 = 0;
  if ( m_pObject == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  v15 = 0;
  v4 = m_pObject->__vftable;
  v13 = 0;
  if ( v4->QueryInterface(this: m_pObject, a2: &IID_IQuickActivate, a3: (void **)&v15) >= 0 )
  {
    if ( v15 == 0 )
      goto LABEL_2;
    v8[1] = &this->m_xOleClientSite;
    v8[3] = &this->m_xPropertyNotifySink;
    v8[4] = &this->m_xEventSink;
    v8[0] = 64;
    v8[2] = 0;
    v12[1] = 0;
    v12[4] = 0;
    v12[5] = 0;
    AfxVariantInit(&pVar);
    m_pCtrlCont = this->m_pCtrlCont;
    v16[9] = 0;
    if ( m_pCtrlCont == nullptr )
      goto LABEL_2;
    m_pWnd = m_pCtrlCont->m_pWnd;
    v9 = 0;
    if ( m_pWnd == nullptr )
      goto LABEL_2;
    do
    {
      m_pWnd->OnAmbientProperty(this: m_pWnd, a2: this, a3: _afxAmbients[v3 / 2].dwDispID, a4: &pVar);
      if ( pVar.iVal != 0 )
        v9 |= dword_52F794[v3];
      v3 += 2;
    }
    while ( v3 < 16 );
    m_pWnd->OnAmbientProperty(this: m_pWnd, a2: this, a3: -704, a4: &pVar);
    Lo32 = pVar.decVal.Lo32;
    m_pWnd->OnAmbientProperty(this: m_pWnd, a2: this, a3: -701, a4: &pVar);
    v11 = pVar.decVal.Lo32;
    m_pWnd->OnAmbientProperty(this: m_pWnd, a2: this, a3: -716, a4: &pVar);
    v12[2] = pVar.iVal;
    m_pWnd->OnAmbientProperty(this: m_pWnd, a2: this, a3: -705, a4: &pVar);
    v12[3] = pVar.decVal.Lo32;
    m_pWnd->OnAmbientProperty(this: m_pWnd, a2: this, a3: -703, a4: &pVar);
    if ( (**(int (__stdcall ***)(unsigned int, GUID *, _DWORD *))pVar.decVal.Lo32)(
           a1: pVar.decVal.Lo32,
           a2: &IID_IFont,
           a3: v12) < 0 )
      v12[0] = 0;
    v16[0] = 24;
    if ( (*(int (__stdcall **)(int, _DWORD *, _DWORD *))(*(_DWORD *)v15 + 12))(a1: v15, a2: v8, a3: v16) >= 0 )
    {
      this->m_dwMiscStatus = v16[1];
      this->m_dwEventSink = v16[3];
      this->m_dwPropNotifySink = v16[4];
      v13 = 1;
    }
    (*(void (__stdcall **)(int))(*(_DWORD *)v15 + 8))(a1: v15);
    if ( v12[0] != 0 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v12[0] + 8))(a1: v12[0]);
    VariantClear(pvarg: &pVar);
  }
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x004253D3
// Name: protected: virtual long COleControlSite::CreateOrLoad(struct _GUID const __near &,class CFile __near *,int,wchar_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall COleControlSite::CreateOrLoad(
        COleControlSite *this,
        IPersistStreamInit *clsid,
        ILockBytes *pFile,
        IStorage *bStorage,
        wchar_t *bstrLicKey)
{
  IOleObject **p_m_pObject; // edi
  HRESULT result; // eax
  CFile *v8; // esi
  CFile_vtbl *v9; // eax
  int v10; // eax
  HRESULT v11; // eax
  IPersistStorage *v12; // eax
  LPLOCKBYTES v13; // eax
  unsigned __int64 v14; // rax
  IStorage *v15; // eax
  LPVOID v16; // eax
  CArchive ar; // [esp+10h] [ebp-74h] BYREF
  unsigned __int64 cb; // [esp+58h] [ebp-2Ch] BYREF
  COleControlSite *v19; // [esp+60h] [ebp-24h]
  int bQuickActivated; // [esp+64h] [ebp-20h]
  LPLOCKBYTES pplkbyt; // [esp+68h] [ebp-1Ch] BYREF
  IStorage *pStorage; // [esp+6Ch] [ebp-18h] BYREF
  IPersistStorage *pPersStg; // [esp+70h] [ebp-14h] BYREF
  HRESULT hr; // [esp+74h] [ebp-10h]
  int v25; // [esp+80h] [ebp-4h]

  v19 = this;
  p_m_pObject = &this->m_pObject;
  hr = 0;
  if ( this->m_pObject == nullptr )
  {
    result = _AfxCoCreateInstanceLic(
               (const _GUID *)clsid,
               pUnkOuter: nullptr,
               dwClsCtx: 3u,
               iid: &IID_IOleObject,
               ppv: (void **)&this->m_pObject,
               bstrLicKey);
    hr = result;
    if ( result < 0 )
      return result;
  }
  clsid = nullptr;
  pPersStg = nullptr;
  bstrLicKey = nullptr;
  COleControlSite::GetEventIID(this, piid: &this->m_iidEvents);
  bQuickActivated = this->QuickActivate(this);
  if ( bQuickActivated == 0 )
  {
    (*p_m_pObject)->GetMiscStatus(this: *p_m_pObject, a2: 1u, a3: &this->m_dwMiscStatus);
    if ( (this->m_dwMiscStatus & 0x20000) != 0 )
    {
      hr = (*p_m_pObject)->SetClientSite(this: *p_m_pObject, a2: &this->m_xOleClientSite);
      if ( hr < 0 )
        goto LABEL_43;
    }
  }
  v8 = (CFile *)pFile;
  if ( pFile == nullptr )
  {
    if ( bStorage != nullptr )
      goto LABEL_17;
    goto LABEL_12;
  }
  if ( bStorage != nullptr )
    goto LABEL_17;
  if ( (*p_m_pObject)->QueryInterface(this: *p_m_pObject, a2: &IID_IPersistMemory, a3: (void **)&bstrLicKey) < 0
    || v8->GetBufferPtr(this: v8, a2: 3u, a3: 0, a4: nullptr, a5: nullptr) == 0 )
  {
LABEL_12:
    if ( (*p_m_pObject)->QueryInterface(this: *p_m_pObject, a2: &IID_IPersistStreamInit, a3: (void **)&clsid) >= 0 )
    {
      if ( v8 != nullptr )
      {
        CArchive::CArchive(this: &ar, pFile: v8, nMode: 1u, nBufSize: 4096, lpBuf: nullptr);
        v25 = 0;
        CArchiveStream::CArchiveStream(this: (CArchiveStream *)&cb, pArchive: &ar);
        v11 = clsid->Load(this: clsid, a2: (IStream *)&cb);
        v25 = -1;
        hr = v11;
        CArchive::~CArchive(this: &ar);
      }
      else
      {
        hr = clsid->InitNew(this: clsid);
      }
      v12 = (IPersistStorage *)clsid;
      goto LABEL_37;
    }
LABEL_17:
    if ( (*p_m_pObject)->QueryInterface(this: *p_m_pObject, a2: &IID_IPersistStorage, a3: (void **)&pPersStg) < 0 )
      goto CreateOrLoadFailed;
    if ( v8 != nullptr )
    {
      if ( bStorage == nullptr )
      {
        hr = -2147418113;
        goto LABEL_36;
      }
      v14 = v8->GetLength(this: v8);
      LODWORD(cb) = v14;
      if ( v14 < 0xFFFFFFFF
        && (v15 = (IStorage *)GlobalAlloc(uFlags: 0, dwBytes: v14), bStorage = v15, v15 != nullptr)
        && (v16 = GlobalLock(hMem: v15)) != nullptr )
      {
        v8->Read(this: v8, a2: v16, a3: cb);
        GlobalUnlock(hMem: bStorage);
      }
      else
      {
        hr = -2147024882;
        bStorage = nullptr;
      }
      pplkbyt = nullptr;
      if ( bStorage == nullptr )
        goto LABEL_36;
      hr = CreateILockBytesOnHGlobal(hGlobal: bStorage, fDeleteOnRelease: true, &pplkbyt);
      if ( hr < 0 )
        goto LABEL_36;
      pStorage = nullptr;
      hr = StgOpenStorageOnILockBytes(
             plkbyt: pplkbyt,
             pstgPriority: nullptr,
             grfMode: 0x12u,
             snbExclude: nullptr,
             reserved: 0,
             ppstgOpen: &pStorage);
      if ( hr >= 0 )
      {
        hr = pPersStg->Load(this: pPersStg, a2: pStorage);
        pStorage->Release(this: pStorage);
      }
      v13 = pplkbyt;
    }
    else
    {
      pFile = nullptr;
      hr = CreateILockBytesOnHGlobal(hGlobal: nullptr, fDeleteOnRelease: true, pplkbyt: &pFile);
      if ( hr < 0 )
      {
LABEL_36:
        v12 = pPersStg;
LABEL_37:
        v12->Release(this: v12);
        goto LABEL_38;
      }
      bStorage = nullptr;
      hr = StgCreateDocfileOnILockBytes(plkbyt: pFile, grfMode: 0x1012u, reserved: 0, ppstgOpen: &bStorage);
      if ( hr >= 0 )
      {
        hr = pPersStg->InitNew(this: pPersStg, a2: bStorage);
        bStorage->Release(this: bStorage);
      }
      v13 = pFile;
    }
    v13->Release(this: v13);
    goto LABEL_36;
  }
  v9 = v8->__vftable;
  bStorage = nullptr;
  v10 = v9->GetBufferPtr(this: v8, a2: 0, a3: -1u, a4: (void **)&bStorage, a5: (void **)&pFile);
  hr = (*(int (__stdcall **)(wchar_t *, IStorage *, int))(*(_DWORD *)bstrLicKey + 20))(
         a1: bstrLicKey,
         a2: bStorage,
         a3: v10);
  (*(void (__stdcall **)(wchar_t *))(*(_DWORD *)bstrLicKey + 8))(a1: bstrLicKey);
  bstrLicKey = nullptr;
LABEL_38:
  if ( hr < 0 )
    goto LABEL_43;
  if ( bQuickActivated == 0 && (v19->m_dwMiscStatus & 0x20000) == 0 )
    hr = (*p_m_pObject)->SetClientSite(this: *p_m_pObject, a2: &v19->m_xOleClientSite);
CreateOrLoadFailed:
  if ( hr < 0 )
  {
LABEL_43:
    if ( *p_m_pObject != nullptr )
    {
      (*p_m_pObject)->Close(this: *p_m_pObject, a2: 1u);
      (*p_m_pObject)->Release(this: *p_m_pObject);
      *p_m_pObject = nullptr;
    }
  }
  if ( bstrLicKey != nullptr )
    (*(void (__stdcall **)(wchar_t *))(*(_DWORD *)bstrLicKey + 8))(a1: bstrLicKey);
  if ( bQuickActivated != 0 && hr >= 0 )
    return 1;
  return hr;
}

//------------------------------------------------------------------------------
// Address: 0x004256E5
// Name: public: virtual long COleControlSite::DoVerb(long,struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall COleControlSite::DoVerb(COleControlSite *this, int nVerb, tagMSG *lpMsg)
{
  COleControlContainer *m_pCtrlCont; // eax
  CWnd *m_pWnd; // edx

  if ( this->m_pObject == nullptr
    || (m_pCtrlCont = this->m_pCtrlCont) == nullptr
    || (m_pWnd = m_pCtrlCont->m_pWnd) == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  return this->m_pObject->DoVerb(
           this: this->m_pObject,
           a2: nVerb,
           a3: lpMsg,
           a4: &this->m_xOleClientSite,
           a5: 0,
           a6: m_pWnd->m_hWnd,
           a7: &this->m_rect);
}

//------------------------------------------------------------------------------
// Address: 0x0042572A
// Name: public: virtual void COleControlSite::MoveWindow(int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleControlSite::MoveWindow(COleControlSite *this, int x, int y, int nWidth, int nHeight)
{
  CRect *p_m_rect; // ebx
  CRect rectOld; // 0:^20.16

  if ( this->m_pInPlaceObject == nullptr || this->m_pObject == nullptr )
    AfxThrowInvalidArgException();
  p_m_rect = &this->m_rect;
  rectOld = this->m_rect;
  SetRect(lprc: &this->m_rect, xLeft: x, yTop: y, xRight: x + nWidth, yBottom: y + nHeight);
  if ( COleControlSite::SetExtent(this) )
  {
    SetRect(
      lprc: p_m_rect,
      xLeft: x,
      yTop: y,
      xRight: x + p_m_rect->right - p_m_rect->left,
      yBottom: y + p_m_rect->bottom - p_m_rect->top);
    this->m_pInPlaceObject->SetObjectRects(this: this->m_pInPlaceObject, a2: p_m_rect, a3: p_m_rect);
  }
  else
  {
    *p_m_rect = rectOld;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004257B9
// Name: public: virtual int COleControlSite::SetWindowPos(class CWnd const __near *,int,int,int,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall COleControlSite::SetWindowPos(
        COleControlSite *this,
        HWND__ *pWndInsertAfter,
        int x,
        int y,
        int cx,
        int cy,
        int nFlags)
{
  int left; // edx
  int top; // eax
  int v11; // eax
  int v12; // ecx
  HWND__ *v13; // eax
  UINT v14; // ebx
  int yNew; // [esp+24h] [ebp+1Ch]

  if ( (nFlags & 0x80u) != 0 )
    this->ShowWindow(this, a2: 0);
  if ( (nFlags & 3) != 3 )
  {
    if ( (nFlags & 2) != 0 )
    {
      left = this->m_rect.left;
      top = this->m_rect.top;
    }
    else
    {
      left = x;
      top = y;
    }
    yNew = top;
    if ( (nFlags & 1) != 0 )
    {
      v11 = this->m_rect.right - this->m_rect.left;
      v12 = this->m_rect.bottom - this->m_rect.top;
    }
    else
    {
      v11 = cx;
      v12 = cy;
    }
    this->MoveWindow(this, a2: left, a3: yNew, a4: v11, a5: v12);
  }
  if ( (nFlags & 0x40) != 0 )
    this->ShowWindow(this, a2: 5);
  v13 = pWndInsertAfter;
  v14 = nFlags & 0xFFFFFF3C | 3;
  if ( pWndInsertAfter != nullptr )
    v13 = *((HWND__ **)pWndInsertAfter + 8);
  return SetWindowPos(hWnd: this->m_hWnd, hWndInsertAfter: v13, X: x, Y: y, cx, cy, uFlags: v14);
}

//------------------------------------------------------------------------------
// Address: 0x0042585E
// Name: public: virtual class CWnd __near * COleControlSite::SetFocus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall COleControlSite::SetFocus(COleControlSite *this)
{
  HWND v2; // eax
  HWND Focus; // eax
  CWnd *v5; // edi

  if ( (this->m_dwMiscStatus & 0x4000) == 0 || this->m_bIsWindowless != 0 )
  {
    Focus = GetFocus();
    v5 = CWnd::FromHandle(hWnd: Focus);
    if ( (this->m_dwMiscStatus & 0x400) == 0 && this->DoVerb(this, a2: -4, a3: nullptr) >= 0 )
      this->m_pCtrlCont->m_pSiteFocus = this;
    return v5;
  }
  else
  {
    v2 = SetFocus(hWnd: this->m_hWnd);
    return CWnd::FromHandle(hWnd: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004258B5
// Name: public: virtual class CWnd __near * COleControlSite::SetFocus(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall COleControlSite::SetFocus(COleControlSite *this, tagMSG *lpmsg)
{
  HWND v3; // eax
  HWND Focus; // eax
  CWnd *v6; // edi

  if ( (this->m_dwMiscStatus & 0x4000) == 0 || this->m_bIsWindowless != 0 )
  {
    Focus = GetFocus();
    v6 = CWnd::FromHandle(hWnd: Focus);
    if ( (this->m_dwMiscStatus & 0x400) == 0 && this->DoVerb(this, a2: -4, a3: lpmsg) >= 0 )
      this->m_pCtrlCont->m_pSiteFocus = this;
    return v6;
  }
  else
  {
    v3 = SetFocus(hWnd: this->m_hWnd);
    return CWnd::FromHandle(hWnd: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425913
// Name: public: virtual void COleControlSite::BindProperty(long,class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleControlSite::BindProperty(COleControlSite *this, int dwDispId, CWnd *pWndDSC)
{
  CDataBoundProperty *v4; // ecx
  CDataBoundProperty *v5; // eax
  CDataBoundProperty *v6; // ecx
  CDataBoundProperty *m_pBindings; // edi
  CDataBoundProperty *m_pNext; // eax
  COleControlSite *m_pDSCSite; // eax

  v4 = nullptr;
  if ( pWndDSC == nullptr || dwDispId == -1 )
  {
    m_pBindings = this->m_pBindings;
    if ( m_pBindings != nullptr )
    {
      while ( 1 )
      {
        m_pNext = m_pBindings->m_pNext;
        if ( (dwDispId == -1 || m_pBindings->m_dispid == dwDispId)
          && (pWndDSC == nullptr || pWndDSC->m_pCtrlSite == m_pBindings->m_pDSCSite) )
        {
          break;
        }
        v4 = m_pBindings;
        m_pBindings = m_pBindings->m_pNext;
        if ( m_pNext == nullptr )
          return;
      }
      if ( v4 != nullptr )
        v4->m_pNext = m_pNext;
      else
        this->m_pBindings = m_pNext;
      m_pDSCSite = m_pBindings->m_pDSCSite;
      if ( m_pDSCSite != nullptr && m_pDSCSite->m_pDataSourceControl != nullptr )
        m_pDSCSite->m_pDataSourceControl->BindProp(this: m_pDSCSite->m_pDataSourceControl, a2: m_pBindings, a3: 0);
      operator delete(p: m_pBindings);
    }
  }
  else
  {
    v5 = (CDataBoundProperty *)operator new(nSize: 0x1Cu);
    if ( v5 != nullptr )
    {
      v6 = this->m_pBindings;
      v5->m_pClientSite = nullptr;
      v5->m_ctlid = 0;
      v5->m_dispid = dwDispId;
      v5->m_pDSCSite = nullptr;
      v5->m_bIsDirty = 0;
      v5->m_pNext = v6;
    }
    else
    {
      v5 = nullptr;
    }
    this->m_pBindings = v5;
    v5->m_pDSCSite = pWndDSC->m_pCtrlSite;
    this->m_pBindings->m_pClientSite = this;
    this->m_pBindings->m_pDSCSite->EnableDSC(this: this->m_pBindings->m_pDSCSite);
    this->m_pBindings->m_pDSCSite->m_pDataSourceControl->BindProp(
      this: this->m_pBindings->m_pDSCSite->m_pDataSourceControl,
      a2: this->m_pBindings,
      a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425A04
// Name: public: virtual unsigned long COleControlSite::XOleClientSite::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall COleControlSite::XOleClientSite::AddRef(COleControlSite::XOleClientSite *this)
{
  return InterlockedIncrement(lpAddend: (volatile LONG *)this - 49);
}

//------------------------------------------------------------------------------
// Address: 0x00425A1C
// Name: public: virtual long COleControlSite::XOleClientSite::ShowObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleClientSite::ShowObject(COleControlSite::XOleClientSite *this)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 43));
  COleControlSite::AttachWindow(this: (COleControlSite *)(this - 50));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425A4F
// Name: public: virtual unsigned long COleControlSite::XOleIPSite::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall COleControlSite::XOleIPSite::AddRef(COleControlSite::XOleIPSite *this)
{
  return InterlockedIncrement(lpAddend: (volatile LONG *)this - 50);
}

//------------------------------------------------------------------------------
// Address: 0x00425A67
// Name: public: virtual long COleControlSite::XOleIPSite::GetWindow(struct HWND__ __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::GetWindow(COleControlSite::XOleIPSite *this, HWND__ **phWnd)
{
  HWND__ *v2; // eax

  v2 = *(HWND__ **)(*((_DWORD *)this - 43) + 32);
  if ( v2 != nullptr )
    v2 = *((HWND__ **)v2 + 8);
  *phWnd = v2;
  return v2 != nullptr ? 0 : -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x00425A96
// Name: public: virtual long COleControlSite::XOleIPSite::GetWindowContext(struct IOleInPlaceFrame __near * __near *,struct IOleInPlaceUIWindow __near * __near *,struct tagRECT __near *,struct tagRECT __near *,struct tagOIFI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::GetWindowContext(
        COleControlSite::XOleIPSite *this,
        IOleInPlaceFrame **ppFrame,
        IOleInPlaceUIWindow **ppDoc,
        tagRECT *prectPos,
        tagRECT *prectClip,
        tagOIFI *pFrameInfo)
{
  int v6; // ebx
  int v8; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+8h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  v6 = 0;
  if ( ppDoc != nullptr )
    *ppDoc = nullptr;
  if ( CCmdTarget::InternalQueryInterface(
         this: *((CCmdTarget **)this - 43),
         iid: &IID_IOleInPlaceFrame,
         ppvObj: (void **)ppFrame) >= 0 )
  {
    v8 = *(_DWORD *)(*((_DWORD *)this - 43) + 32);
    CopyRect(lprcDst: prectPos, lprcSrc: (const RECT *)(this - 39));
    GetClientRect(hWnd: *(HWND *)(v8 + 32), lpRect: prectClip);
    pFrameInfo->fMDIApp = 0;
    pFrameInfo->hwndFrame = *(HWND__ **)(v8 + 32);
    pFrameInfo->haccel = nullptr;
    pFrameInfo->cAccelEntries = 0;
  }
  else
  {
    v6 = -2147467259;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00425B22
// Name: public: virtual long COleControlSite::XOleIPSite::OnInPlaceDeactivate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::OnInPlaceDeactivate(COleControlSite::XOleIPSite *this)
{
  int v1; // eax
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  COleControlSite::DetachWindow(this: (COleControlSite *)(this - 51));
  if ( *((_DWORD *)this - 22) != 0 )
  {
    v1 = *((_DWORD *)this - 28);
    if ( v1 != 0 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v1 + 8))(a1: *((_DWORD *)this - 28));
      *((_DWORD *)this - 28) = 0;
    }
    --*(_DWORD *)(*((_DWORD *)this - 43) + 116);
    *((_DWORD *)this - 22) = 0;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425B79
// Name: public: virtual long COleControlSite::XOleIPSite::OnPosRectChange(struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::OnPosRectChange(
        COleControlSite::XOleIPSite *this,
        const tagRECT *lprcPosRect)
{
  int v2; // eax
  COleControlSite::XOleIPSite *v3; // eax
  int v4; // ebx
  tagRECT rcDst; // [esp+Ch] [ebp-24h] BYREF
  CRect rectClip; // [esp+1Ch] [ebp-14h] BYREF

  v2 = *((_DWORD *)this - 43);
  if ( v2 == 0 || *(_DWORD *)(v2 + 32) == 0 || *((_DWORD *)this - 30) == 0 )
    AfxThrowInvalidArgException();
  memset(&rectClip, 0, sizeof(rectClip));
  GetClientRect(hWnd: *(HWND *)(*(_DWORD *)(v2 + 32) + 32), lpRect: &rectClip);
  CopyRect(lprcDst: &rcDst, lprcSrc: lprcPosRect);
  v3 = this - 39;
  v4 = *((_DWORD *)this - 30);
  v3->__vftable = (COleControlSite::XOleIPSite_vtbl *)rcDst.left;
  v3[1].__vftable = (COleControlSite::XOleIPSite_vtbl *)rcDst.top;
  v3[2].__vftable = (COleControlSite::XOleIPSite_vtbl *)rcDst.right;
  v3[3].__vftable = (COleControlSite::XOleIPSite_vtbl *)rcDst.bottom;
  return (*(HRESULT (__stdcall **)(int, COleControlSite::XOleIPSite *, CRect *))(*(_DWORD *)v4 + 28))(
           a1: v4,
           a2: this - 39,
           a3: &rectClip);
}

//------------------------------------------------------------------------------
// Address: 0x00425C04
// Name: public: virtual long COleControlSite::XOleIPSite::OnInPlaceActivateEx(int __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::OnInPlaceActivateEx(
        COleControlSite::XOleIPSite *this,
        int *ptNoRedraw,
        char dwFlags)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  if ( (dwFlags & 1) != 0 )
  {
    (***((void (__cdecl ****)(_DWORD, GUID *, COleControlSite::XOleIPSite *))this - 31))(
      a1: *((_DWORD *)this - 31),
      a2: &IID_IOleInPlaceObjectWindowless,
      a3: this - 28);
    *((_DWORD *)this - 22) = 1;
    ++*(_DWORD *)(*((_DWORD *)this - 43) + 116);
  }
  if ( ptNoRedraw != nullptr )
    *ptNoRedraw = 0;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425C5D
// Name: public: virtual long COleControlSite::XOleIPSite::AdjustRect(struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::AdjustRect(COleControlSite::XOleIPSite *this, tagRECT *__formal)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+0h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return -2147467263;
}

//------------------------------------------------------------------------------
// Address: 0x00425C86
// Name: public: virtual long COleControlSite::XOleIPSite::RequestUIActivate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::RequestUIActivate(COleControlSite::XOleIPSite *this)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+0h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425CAC
// Name: public: virtual long COleControlSite::XOleIPSite::GetCapture(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall COleControlSite::XOleIPSite::GetCapture(COleControlSite::XOleIPSite *this)
{
  BOOL v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  v1 = *(_DWORD *)(*((_DWORD *)this - 43) + 108) != (_DWORD)(this - 51);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00425CE9
// Name: public: virtual long COleControlSite::XOleIPSite::GetFocus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::GetFocus(COleControlSite::XOleIPSite *this)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+0h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return -2147467263;
}

//------------------------------------------------------------------------------
// Address: 0x00425D12
// Name: public: virtual long COleControlSite::XOleIPSite::InvalidateRect(struct tagRECT const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::InvalidateRect(
        COleControlSite::XOleIPSite *this,
        const tagRECT *prect,
        BOOL bErase)
{
  AFX_MODULE_STATE *v4; // [esp-4h] [ebp-2Ch]
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+Ch] [ebp-1Ch] BYREF
  CRect rect; // [esp+14h] [ebp-14h] BYREF

  v4 = *((AFX_MODULE_STATE **)this - 44);
  memset(&rect, 0, sizeof(rect));
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: v4);
  if ( prect != nullptr )
  {
    IntersectRect(lprcDst: &rect, lprcSrc1: prect, lprcSrc2: (const RECT *)(this - 39));
    EqualRect(lprc1: &rect, lprc2: prect);
  }
  else
  {
    rect.left = (int)*(this - 39);
    rect.top = (int)*(this - 38);
    rect.right = (int)*(this - 37);
    rect.bottom = (int)*(this - 36);
  }
  if ( !IsRectEmpty(lprc: &rect) )
    InvalidateRect(hWnd: *(HWND *)(*(_DWORD *)(*((_DWORD *)this - 43) + 32) + 32), lpRect: &rect, bErase);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425DBB
// Name: public: virtual long COleControlSite::XOleIPSite::ScrollRect(int,int,struct tagRECT const __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::ScrollRect(
        COleControlSite::XOleIPSite *this,
        int __formal,
        int a3,
        const tagRECT *a4,
        const tagRECT *a5)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+0h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return -2147467263;
}

//------------------------------------------------------------------------------
// Address: 0x00425DE4
// Name: public: virtual long COleControlSite::XOleIPSite::ReleaseDC(struct HDC__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::ReleaseDC(COleControlSite::XOleIPSite *this, HDC__ *hDC)
{
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  ReleaseDC(hWnd: *(HWND *)(*(_DWORD *)(*((_DWORD *)this - 43) + 32) + 32), hDC: *(HDC *)(*((_DWORD *)this - 2) + 4));
  *((_DWORD *)this - 2) = 0;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425E28
// Name: public: virtual long COleControlSite::XOleIPSite::SetCapture(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::SetCapture(COleControlSite::XOleIPSite *this, int bCapture)
{
  int v2; // eax
  HWND v3; // eax
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  v2 = *((_DWORD *)this - 43);
  if ( bCapture != 0 )
  {
    v3 = SetCapture(hWnd: *(HWND *)(*(_DWORD *)(v2 + 32) + 32));
    CWnd::FromHandle(hWnd: v3);
    *(_DWORD *)(*((_DWORD *)this - 43) + 108) = this - 51;
  }
  else
  {
    *(_DWORD *)(v2 + 108) = 0;
    ReleaseCapture();
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425E83
// Name: public: virtual long COleControlSite::XOleIPSite::SetFocus(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::SetFocus(COleControlSite::XOleIPSite *this, int bFocus)
{
  COleControlSite::XOleIPSite *v2; // esi
  int v3; // eax
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  v2 = this - 51;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  v3 = *((_DWORD *)this - 43);
  if ( bFocus != 0 )
  {
    *(_DWORD *)(v3 + 112) = v2;
    CWnd::SetFocus(this: (CWnd *)v2[8].GetWindowContext);
  }
  else
  {
    *(_DWORD *)(v3 + 112) = 0;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425ECE
// Name: public: virtual unsigned long COleControlSite::XOleControlSite::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall COleControlSite::XOleControlSite::AddRef(COleControlSite::XOleControlSite *this)
{
  return InterlockedIncrement(lpAddend: (volatile LONG *)this - 51);
}

//------------------------------------------------------------------------------
// Address: 0x00425EE6
// Name: public: virtual unsigned long COleControlSite::XAmbientProps::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall COleControlSite::XAmbientProps::AddRef(COleControlSite::XAmbientProps *this)
{
  return InterlockedIncrement(lpAddend: (volatile LONG *)this - 52);
}

//------------------------------------------------------------------------------
// Address: 0x00425EFE
// Name: public: virtual long COleControlSite::XAmbientProps::Invoke(long,struct _GUID const __near &,unsigned long,unsigned short,struct tagDISPPARAMS __near *,struct tagVARIANT __near *,struct tagEXCEPINFO __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XAmbientProps::Invoke(
        COleControlSite::XAmbientProps *this,
        int dispid,
        const _GUID *__formal,
        unsigned int a4,
        unsigned __int16 wFlags,
        tagDISPPARAMS *pDispParams,
        tagVARIANT *pvarResult,
        tagEXCEPINFO *a8,
        unsigned int *a9)
{
  int v9; // eax
  int v10; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 46));
  v9 = *((_DWORD *)this - 45);
  if ( v9 == 0 || *(_DWORD *)(v9 + 32) == 0 )
    AfxThrowInvalidArgException();
  v10 = (*(int (__thiscall **)(_DWORD, COleControlSite::XAmbientProps *, int, tagVARIANT *))(**(_DWORD **)(v9 + 32) + 272))(
          a1: *(_DWORD *)(v9 + 32),
          a2: this - 53,
          a3: dispid,
          a4: pvarResult) != 0
      ? 0x7FFDFFFD
      : 0;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v10 - 2147352573;
}

//------------------------------------------------------------------------------
// Address: 0x00425F5E
// Name: public: virtual long COleControlSite::XPropertyNotifySink::OnChanged(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XPropertyNotifySink::OnChanged(
        COleControlSite::XPropertyNotifySink *this,
        HRESULT dispid)
{
  COleControlSite::XPropertyNotifySink *v2; // esi
  HRESULT m_hResult; // edi
  HRESULT v5; // ebx
  COleControlSite::XPropertyNotifySink_vtbl *v6; // eax
  AFX_EVENT event; // [esp+Ch] [ebp-60h] BYREF
  tagEXCEPINFO excepinfo; // [esp+30h] [ebp-3Ch] BYREF
  tagDISPPARAMS dispparamsGetProp; // [esp+50h] [ebp-1Ch] BYREF
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+60h] [ebp-Ch] BYREF
  unsigned int uArgErr; // [esp+68h] [ebp-4h] BYREF

  v2 = this;
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 47));
  m_hResult = 0;
  if ( v2[-20].__vftable != nullptr )
    goto LABEL_2;
  v5 = dispid;
  if ( v2[-18].__vftable == nullptr )
  {
    event.m_eventKind = 2;
    event.m_dispid = dispid;
    memset(&event.m_pDispParams, 0, 12);
    memset(&event.m_hResult, 0, 12);
    COleControlSite::OnEvent(this: (COleControlSite *)&v2[-54], pEvent: &event);
    if ( event.m_hResult != 0 )
    {
      m_hResult = event.m_hResult;
LABEL_2:
      AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
      return m_hResult;
    }
  }
  if ( v2[-15].__vftable == (COleControlSite::XPropertyNotifySink_vtbl *)v5 )
  {
    VariantClear(pvarg: (VARIANTARG *)&v2[-11]);
    v6 = v2[-34].__vftable;
    this = nullptr;
    if ( v6 == nullptr )
      goto LABEL_8;
    if ( (*(int (__stdcall **)(COleControlSite::XPropertyNotifySink_vtbl *, GUID *, COleControlSite::XPropertyNotifySink **))v6->QueryInterface)(
           a1: v6,
           a2: &IID_IDispatch,
           a3: &this) < 0 )
      goto LABEL_2;
    memset(dst: (int)&excepinfo, value: nullptr, count: sizeof(excepinfo));
    memset(dst: (int)&dispparamsGetProp, value: nullptr, count: sizeof(dispparamsGetProp));
    if ( this == nullptr )
LABEL_8:
      AfxThrowInvalidArgException();
    dispid = ((int (__stdcall *)(COleControlSite::XPropertyNotifySink *, HRESULT, GUID *, _DWORD, int, tagDISPPARAMS *, COleControlSite::XPropertyNotifySink *, tagEXCEPINFO *, unsigned int *))this->__vftable[1].AddRef)(
               a1: this,
               a2: v5,
               a3: &GUID_NULL,
               a4: 0,
               a5: 2,
               a6: &dispparamsGetProp,
               a7: &v2[-11],
               a8: &excepinfo,
               a9: &uArgErr);
    if ( excepinfo.bstrSource != nullptr )
      SysFreeString(bstrString: excepinfo.bstrSource);
    if ( excepinfo.bstrDescription != nullptr )
      SysFreeString(bstrString: excepinfo.bstrDescription);
    if ( excepinfo.bstrHelpFile != nullptr )
      SysFreeString(bstrString: excepinfo.bstrHelpFile);
    this->Release(this);
    if ( dispid < 0 )
      goto LABEL_2;
    v2[-12].__vftable = (COleControlSite::XPropertyNotifySink_vtbl *)1;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042609A
// Name: public: virtual long COleControlSite::XPropertyNotifySink::OnRequestEdit(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XPropertyNotifySink::OnRequestEdit(
        COleControlSite::XPropertyNotifySink *this,
        int dispid)
{
  HRESULT m_hResult; // edi
  AFX_EVENT event; // [esp+8h] [ebp-2Ch] BYREF
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+2Ch] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 47));
  m_hResult = 0;
  if ( *((_DWORD *)this - 20) == 0 && *((_DWORD *)this - 18) == 0 )
  {
    event.m_dispid = dispid;
    event.m_eventKind = 1;
    memset(&event.m_pDispParams, 0, 12);
    memset(&event.m_hResult, 0, 12);
    COleControlSite::OnEvent(this: (COleControlSite *)(this - 54), pEvent: &event);
    if ( event.m_hResult != 0 )
      m_hResult = event.m_hResult;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return m_hResult;
}

//------------------------------------------------------------------------------
// Address: 0x00426109
// Name: public: virtual long COleControlSite::XEventSink::Invoke(long,struct _GUID const __near &,unsigned long,unsigned short,struct tagDISPPARAMS __near *,struct tagVARIANT __near *,struct tagEXCEPINFO __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XEventSink::Invoke(
        COleControlSite::XEventSink *this,
        int dispid,
        const _GUID *__formal,
        unsigned int a4,
        unsigned __int16 wFlags,
        tagDISPPARAMS *pDispParams,
        tagVARIANT *pvarResult,
        tagEXCEPINFO *pExcepInfo,
        unsigned int *puArgError)
{
  HRESULT m_hResult; // esi
  AFX_EVENT event; // [esp+8h] [ebp-2Ch] BYREF
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+2Ch] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 48));
  event.m_dispid = dispid;
  event.m_pDispParams = pDispParams;
  event.m_pExcepInfo = pExcepInfo;
  event.m_puArgError = puArgError;
  event.m_eventKind = 0;
  memset(&event.m_hResult, 0, 12);
  COleControlSite::OnEvent(this: (COleControlSite *)(this - 55), pEvent: &event);
  if ( pvarResult != nullptr )
    VariantClear(pvarg: pvarResult);
  m_hResult = event.m_hResult;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return m_hResult;
}

//------------------------------------------------------------------------------
// Address: 0x0042617A
// Name: public: void CDataBoundProperty::Notify(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDataBoundProperty::Notify(CDataBoundProperty *this)
{
  COleControlSite *m_pClientSite; // eax
  IUnknown *Cursor; // eax
  int v4; // edx
  IBoundObject *pBO; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_dispid != -2147418111 )
  {
    m_pClientSite = this->m_pClientSite;
    if ( this->m_pClientSite != nullptr )
    {
      if ( m_pClientSite->m_pObject == nullptr )
        AfxThrowInvalidArgException();
      if ( m_pClientSite->m_pObject->QueryInterface(
             this: m_pClientSite->m_pObject,
             a2: &IID_IBoundObject,
             a3: (void **)&pBO) < 0 )
      {
        Cursor = CDataBoundProperty::GetCursor(this);
        if ( Cursor != nullptr )
        {
          v4 = 13;
          if ( this->m_pDSCSite->m_pDataSourceControl != nullptr )
            v4 = 32781;
          this->m_pClientSite->SetProperty(this: this->m_pClientSite, a2: this->m_dispid, a3: v4, Cursor);
        }
      }
      else
      {
        pBO->OnSourceChanged(this: pBO, a2: this->m_dispid, a3: this->m_pDSCSite != nullptr, a4: &this->m_bOwnXferOut);
        pBO->Release(this: pBO);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042620A
// Name: public: long COleControlSite::XNotifyDBEvents::FireEvent(unsigned long,unsigned long,struct tagDBNOTIFYREASON __near * const,enum DSCSTATE)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall COleControlSite::XNotifyDBEvents::FireEvent(
        COleControlSite::XNotifyDBEvents *this,
        char dwEventWhat,
        unsigned int cReasons,
        tagDBNOTIFYREASON *rgReasons,
        DSCSTATE nState)
{
  COleControlSite *v5; // ecx
  HRESULT result; // eax
  unsigned int v7; // esi
  DSCREASON v9; // eax
  int v10; // [esp-Ch] [ebp-30h]
  AFX_EVENT event; // [esp+0h] [ebp-24h] BYREF

  v5 = (COleControlSite *)(this - 57);
  if ( (dwEventWhat & 3) == 0 )
    return 0;
  v7 = 0;
  if ( cReasons == 0 )
    return 0;
  while ( 2 )
  {
    switch ( rgReasons->dwReason )
    {
      case 1u:
        v10 = 3;
        goto LABEL_14;
      case 2u:
      case 0x14u:
        v10 = 5;
        goto LABEL_14;
      case 3u:
      case 9u:
      case 0xAu:
      case 0x17u:
        v10 = 6;
        goto LABEL_14;
      case 6u:
      case 7u:
      case 8u:
      case 0xBu:
      case 0xCu:
      case 0xFu:
      case 0x10u:
      case 0x13u:
      case 0x15u:
        v10 = 7;
        goto LABEL_14;
      case 0x18u:
        v10 = 2;
        goto LABEL_14;
      case 0x19u:
        v9 = dscClose;
        goto LABEL_15;
      case 0x1Fu:
        v10 = 4;
LABEL_14:
        v9 = v10;
LABEL_15:
        event.m_dispid = -1;
        event.m_nDSCReason = v9;
        event.m_eventKind = 3;
        memset(&event.m_pDispParams, 0, 12);
        event.m_hResult = 0;
        event.m_nDSCState = nState;
        COleControlSite::OnEvent(this: v5, pEvent: &event);
        result = event.m_hResult;
        break;
      default:
        ++v7;
        ++rgReasons;
        if ( v7 >= cReasons )
          return 0;
        continue;
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004262E1
// Name: public: ATL::CAutoVectorPtr<struct tagDBBINDING>::~CAutoVectorPtr<struct tagDBBINDING>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CAutoVectorPtr<tagDBBINDING>::~CAutoVectorPtr<tagDBBINDING>(
        ATL::CAutoVectorPtr<tagDBBINDING> *this)
{
  operator delete(p: this->m_p);
  this->m_p = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004262F3
// Name: public: long ATL::CRowset<class ATL::CAccessorBase>::GetData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CRowset<ATL::CAccessorBase>::GetData(ATL::CRowset<ATL::CAccessorBase> *this)
{
  unsigned int m_nAccessors; // edi
  unsigned int v3; // ebx
  HRESULT result; // eax
  HRESULT hr; // [esp+Ch] [ebp-4h]

  m_nAccessors = this->m_pAccessor->m_nAccessors;
  v3 = 0;
  hr = 0;
  if ( m_nAccessors == 0 )
    return hr;
  while ( 1 )
  {
    if ( ATL::CAccessorBase::IsAutoAccessor(this: this->m_pAccessor, nAccessor: v3) )
    {
      result = ATL::CRowset<ATL::CAccessorBase>::GetData(this, nAccessor: v3);
      hr = result;
      if ( result < 0 )
        break;
    }
    if ( ++v3 >= m_nAccessors )
      return hr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426336
// Name: public: long ATL::CRowset<class ATL::CAccessorBase>::MoveNext(long,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CRowset<ATL::CAccessorBase>::MoveNext(
        ATL::CRowset<ATL::CAccessorBase> *this,
        int lSkip,
        bool bForward)
{
  HRESULT result; // eax
  int Data; // edi
  unsigned int ulRowsFetched; // [esp+4h] [ebp-8h] BYREF
  unsigned int *phRow; // [esp+8h] [ebp-4h] BYREF

  ulRowsFetched = 0;
  ATL::CRowset<ATL::CAccessorBase>::ReleaseRows(this);
  phRow = &this->m_hRow;
  result = this->m_spRowset.p->GetNextRows(
             this: this->m_spRowset.p,
             a2: 0,
             a3: lSkip,
             a4: 2 * bForward - 1,
             a5: &ulRowsFetched,
             a6: &phRow);
  if ( result == 0 )
  {
    Data = ATL::CRowset<ATL::CAccessorBase>::GetData(this);
    if ( Data < 0 )
      ATL::CRowset<ATL::CAccessorBase>::ReleaseRows(this);
    return Data;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426392
// Name: public: bool ATL::CDynamicAccessor::GetValue<struct tagDB_NUMERIC>(unsigned long,struct tagDB_NUMERIC __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::GetValue<tagDB_NUMERIC>(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        tagDB_NUMERIC *pData)
{
  unsigned __int8 *v4; // esi
  tagDB_NUMERIC *v5; // edi

  if ( pData == nullptr || ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  v4 = &this->m_pBuffer[(unsigned int)this->m_pColumnInfo[nColumn].pTypeInfo];
  v5 = pData;
  *(_DWORD *)&pData->precision = *(_DWORD *)v4;
  v4 += 4;
  v5 = (tagDB_NUMERIC *)((char *)v5 + 4);
  *(_DWORD *)&v5->precision = *(_DWORD *)v4;
  v4 += 4;
  v5 = (tagDB_NUMERIC *)((char *)v5 + 4);
  *(_DWORD *)&v5->precision = *(_DWORD *)v4;
  v4 += 4;
  v5 = (tagDB_NUMERIC *)((char *)v5 + 4);
  *(_DWORD *)&v5->precision = *(_DWORD *)v4;
  v4 += 4;
  v5 = (tagDB_NUMERIC *)((char *)v5 + 4);
  *(_WORD *)&v5->precision = *(_WORD *)v4;
  v5->sign = v4[2];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004263D4
// Name: public: bool ATL::CDynamicAccessor::GetValue<struct tagDBTIME>(unsigned long,struct tagDBTIME __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::GetValue<tagDBTIME>(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        tagDBTIME *pData)
{
  if ( pData == nullptr || ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  *pData = *(tagDBTIME *)&this->m_pBuffer[(unsigned int)this->m_pColumnInfo[nColumn].pTypeInfo];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00426412
// Name: public: bool ATL::CDynamicAccessor::GetValue<struct tagDBTIMESTAMP>(unsigned long,struct tagDBTIMESTAMP __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::GetValue<tagDBTIMESTAMP>(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        tagDBTIMESTAMP *pData)
{
  unsigned __int8 *v4; // esi
  tagDBTIMESTAMP *v5; // edi

  if ( pData == nullptr || ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  v4 = &this->m_pBuffer[(unsigned int)this->m_pColumnInfo[nColumn].pTypeInfo];
  v5 = pData;
  *(_DWORD *)&pData->year = *(_DWORD *)v4;
  v4 += 4;
  v5 = (tagDBTIMESTAMP *)((char *)v5 + 4);
  *(_DWORD *)&v5->year = *(_DWORD *)v4;
  v4 += 4;
  v5 = (tagDBTIMESTAMP *)((char *)v5 + 4);
  *(_DWORD *)&v5->year = *(_DWORD *)v4;
  *(_DWORD *)&v5->day = *((_DWORD *)v4 + 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00426451
// Name: public: bool ATL::CDynamicAccessor::SetValue<unsigned long>(unsigned long,unsigned long const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::SetValue<unsigned long>(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        const unsigned int *data)
{
  if ( ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  *(ITypeInfo_vtbl **)((char *)&this->m_pColumnInfo[nColumn].pTypeInfo->__vftable + (unsigned int)this->m_pBuffer) = (ITypeInfo_vtbl *)*data;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00426489
// Name: public: bool ATL::CDynamicAccessor::SetValue<float>(unsigned long,float const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::SetValue<float>(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        const float *data)
{
  if ( ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  *(float *)((char *)&this->m_pColumnInfo[nColumn].pTypeInfo->__vftable + (unsigned int)this->m_pBuffer) = *data;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004264C1
// Name: public: bool ATL::CDynamicAccessor::SetValue<double>(unsigned long,double const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::SetValue<double>(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        const long double *data)
{
  if ( ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  *(double *)((char *)&this->m_pColumnInfo[nColumn].pTypeInfo->__vftable + (unsigned int)this->m_pBuffer) = *(double *)data;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004264F9
// Name: public: bool ATL::CDynamicAccessor::GetValue<wchar_t __near *>(unsigned long,wchar_t __near * __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::GetValue<wchar_t *>(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        wchar_t **pData)
{
  wchar_t **v3; // edi

  v3 = pData;
  if ( pData == nullptr || ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  *v3 = *(wchar_t **)((char *)&this->m_pColumnInfo[nColumn].pTypeInfo->__vftable + (unsigned int)this->m_pBuffer);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00426537
// Name: public: bool ATL::CDynamicAccessor::SetValue<struct tagDEC>(unsigned long,struct tagDEC const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::SetValue<tagDEC>(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        const tagDEC *data)
{
  unsigned __int8 *v4; // edi
  unsigned int Hi32; // [esp+8h] [ebp-Ch]
  unsigned __int64 Lo64; // 0:^14.8

  if ( ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  Hi32 = data->Hi32;
  Lo64 = data->Lo64;
  v4 = &this->m_pBuffer[(unsigned int)this->m_pColumnInfo[nColumn].pTypeInfo];
  *(_DWORD *)v4 = *(_DWORD *)&data->wReserved;
  v4 += 4;
  *(_DWORD *)v4 = Hi32;
  *(_QWORD *)(v4 + 4) = Lo64;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042657F
// Name: public: bool ATL::CDynamicAccessor::SetValue<unsigned char>(unsigned long,unsigned char const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::SetValue<unsigned char>(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        const char *data)
{
  if ( ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  *((_BYTE *)&this->m_pColumnInfo[nColumn].pTypeInfo->__vftable + (unsigned int)this->m_pBuffer) = *data;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004265B7
// Name: public: bool ATL::CDynamicAccessor::SetValue<unsigned short>(unsigned long,unsigned short const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::SetValue<unsigned short>(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        const unsigned __int16 *data)
{
  if ( ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  *(_WORD *)((char *)&this->m_pColumnInfo[nColumn].pTypeInfo->__vftable + (unsigned int)this->m_pBuffer) = *data;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004265F1
// Name: public: long ATL::CAccessorBase::ReleaseAccessors(struct IUnknown __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CAccessorBase::ReleaseAccessors(ATL::CAccessorBase *this, IUnknown *pUnk)
{
  IUnknown_vtbl *v4; // ecx
  unsigned int i; // edi
  IUnknown *v6; // eax
  IUnknown *v7; // [esp-Ch] [ebp-18h]
  ATL::_ATL_ACCESSOR_INFO *m_pAccessorInfo; // [esp-4h] [ebp-10h]
  HRESULT hr; // [esp+8h] [ebp-4h]

  if ( pUnk == nullptr )
    return -2147467259;
  hr = 0;
  if ( this->m_nAccessors != 0 )
  {
    v4 = pUnk->__vftable;
    v7 = pUnk;
    pUnk = nullptr;
    hr = v4->QueryInterface(this: v7, a2: &_GUID_0c733a8c_2a1c_11ce_ade5_00aa0044773d, a3: (void **)&pUnk);
    if ( hr >= 0 )
    {
      if ( this->m_pAccessorInfo == nullptr )
      {
        if ( pUnk != nullptr )
          pUnk->Release(this: pUnk);
        return -2147467259;
      }
      for ( i = 0; i < this->m_nAccessors; ++i )
        pUnk->__vftable[2].QueryInterface(
          this: pUnk,
          a2: (const _GUID *)this->m_pAccessorInfo[i].hAccessor,
          a3: nullptr);
    }
    m_pAccessorInfo = this->m_pAccessorInfo;
    this->m_nAccessors = 0;
    operator delete(p: m_pAccessorInfo);
    v6 = pUnk;
    this->m_pAccessorInfo = nullptr;
    if ( v6 != nullptr )
      v6->Release(this: v6);
  }
  return hr;
}

//------------------------------------------------------------------------------
// Address: 0x0042667F
// Name: public: bool ATL::CDynamicAccessor::GetStatus(unsigned long,unsigned long __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall ATL::CDynamicAccessor::GetStatus(
        ATL::CDynamicAccessor *this,
        unsigned int nColumn,
        unsigned int *pStatus)
{
  unsigned int *v3; // edi

  v3 = pStatus;
  if ( pStatus == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  if ( ATL::CDynamicAccessor::TranslateColumnNo(this, &nColumn) == 0 )
    return 0;
  *v3 = *(_DWORD *)&this->m_pBuffer[((((int)&this->m_pColumnInfo[nColumn].pTypeInfo->__vftable
                                     + this->m_pColumnInfo[nColumn].ulColumnSize
                                     + 3)
                                    & 0xFFFFFFFC)
                                   + 4)
                                  & 0xFFFFFFFC];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004266D6
// Name: public: long ATL::CManualAccessor::BindColumns(struct IUnknown __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CManualAccessor::BindColumns(ATL::CManualAccessor *this, IAccessor *pUnk)
{
  IAccessor *v2; // eax
  IUnknown_vtbl *v5; // ecx
  HRESULT AccessorMemory; // edi
  HRESULT v7; // esi

  v2 = pUnk;
  if ( pUnk == nullptr )
    return -2147467259;
  v5 = (IUnknown_vtbl *)pUnk->__vftable;
  pUnk = nullptr;
  AccessorMemory = v5->QueryInterface(this: v2, a2: &_GUID_0c733a8c_2a1c_11ce_ade5_00aa0044773d, a3: (void **)&pUnk);
  if ( AccessorMemory < 0 )
    goto LABEL_6;
  if ( this->m_pAccessorInfo == nullptr )
  {
    AccessorMemory = ATL::CAccessorBase::AllocateAccessorMemory(this, nAccessors: 1u);
    if ( AccessorMemory < 0 )
    {
LABEL_6:
      if ( pUnk != nullptr )
        pUnk->Release(this: pUnk);
      return AccessorMemory;
    }
    this->m_pAccessorInfo->bAutoAccessor = true;
  }
  v7 = ATL::CAccessorBase::BindEntries(
         pBindings: this->m_pEntry,
         nColumns: this->m_nColumns,
         pHAccessor: &this->m_pAccessorInfo->hAccessor,
         nSize: this->m_nBufferSize,
         pAccessor: pUnk);
  if ( pUnk != nullptr )
    pUnk->Release(this: pUnk);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0042675D
// Name: public: long CDataSourceControl::GetBoundClientRow(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CDataSourceControl::GetBoundClientRow(CDataSourceControl *this)
{
  ATL::CRowset<ATL::CAccessorBase> *m_pRowset; // ecx
  tagVARIANT *m_pValues; // eax
  ICursorMove *m_pCursorMove; // ecx
  tagDBFETCHROWS FetchRows; // [esp+0h] [ebp-18h] BYREF

  if ( this->m_pDataSource != nullptr )
  {
    m_pRowset = this->m_pRowset;
    if ( m_pRowset != nullptr && m_pRowset->m_hRow != 0 )
      return ATL::CRowset<ATL::CAccessorBase>::GetData(this: m_pRowset);
    return 0;
  }
  if ( this->m_nBindings == 0 )
    return 0;
  m_pValues = this->m_pValues;
  m_pCursorMove = this->m_pCursorMove;
  FetchRows.pData = m_pValues;
  FetchRows.pVarData = nullptr;
  FetchRows.cbVarData = 0;
  FetchRows.cRowsRequested = 1;
  FetchRows.dwFlags = 0;
  return ((int (__stdcall *)(ICursorMove *, int, const unsigned __int8 *, _DWORD, _DWORD, tagDBFETCHROWS *))m_pCursorMove->Move)(
           a1: m_pCursorMove,
           a2: 1,
           a3: &DBBMK_CURRENT,
           a4: 0,
           a5: 0,
           a6: &FetchRows);
}

//------------------------------------------------------------------------------
// Address: 0x004267BC
// Name: public: void CDataBoundProperty::SetDSCSite(class COleControlSite __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDataBoundProperty::SetDSCSite(CDataBoundProperty *this, COleControlSite *pDSCSite)
{
  if ( this->m_pDSCSite != pDSCSite )
  {
    this->m_pDSCSite = pDSCSite;
    CDataBoundProperty::Notify(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004267D5
// Name: public: virtual long COleControlSite::XNotifyDBEvents::OKToDo(unsigned long,unsigned long,struct tagDBNOTIFYREASON __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XNotifyDBEvents::OKToDo(
        COleControlSite::XNotifyDBEvents *this,
        char dwEventWhat,
        unsigned int cReasons,
        tagDBNOTIFYREASON *rgReasons)
{
  HRESULT v4; // eax
  HRESULT v5; // esi
  unsigned int dwReason; // edi
  int v8; // ecx
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+8h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 50));
  v4 = COleControlSite::XNotifyDBEvents::FireEvent(this, dwEventWhat, cReasons, rgReasons, nState: dscOKToDo);
  if ( v4 < 0 )
    goto LABEL_2;
  dwReason = rgReasons->dwReason;
  if ( rgReasons->dwReason != 30 && dwReason != 2 && dwReason != 3 )
  {
    if ( (dwEventWhat & 1) == 0 && dwReason != 1 && dwReason != 20
      || (v8 = *((_DWORD *)this - 21)) == 0
      || (dwEventWhat & 1) == 0 )
    {
      v5 = 0;
      goto LABEL_3;
    }
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 20))(a1: v8);
LABEL_2:
    v5 = v4;
LABEL_3:
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return v5;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042685D
// Name: public: virtual long COleControlSite::XNotifyDBEvents::Cancelled(unsigned long,unsigned long,struct tagDBNOTIFYREASON __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XNotifyDBEvents::Cancelled(
        COleControlSite::XNotifyDBEvents *this,
        char dwEventWhat,
        unsigned int cReasons,
        tagDBNOTIFYREASON *rgReasons)
{
  HRESULT v4; // eax
  HRESULT v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 50));
  v4 = COleControlSite::XNotifyDBEvents::FireEvent(this, dwEventWhat, cReasons, rgReasons, nState: dscCancelled);
  if ( v4 >= 0 )
    v5 = 0;
  else
    v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004268A1
// Name: public: virtual long COleControlSite::XNotifyDBEvents::SyncBefore(unsigned long,unsigned long,struct tagDBNOTIFYREASON __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XNotifyDBEvents::SyncBefore(
        COleControlSite::XNotifyDBEvents *this,
        char dwEventWhat,
        unsigned int cReasons,
        tagDBNOTIFYREASON *rgReasons)
{
  HRESULT v4; // eax
  HRESULT v5; // esi
  unsigned int dwReason; // edi
  int v8; // ecx
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+8h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 50));
  v4 = COleControlSite::XNotifyDBEvents::FireEvent(this, dwEventWhat, cReasons, rgReasons, nState: dscSyncBefore);
  if ( v4 >= 0 )
  {
    dwReason = rgReasons->dwReason;
    if ( rgReasons->dwReason == 2 || dwReason == 3 || dwReason == 20 )
    {
      v8 = *((_DWORD *)this - 21);
      if ( v8 != 0 && dwEventWhat < 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 20))(a1: v8);
    }
    v5 = 0;
  }
  else
  {
    v5 = v4;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0042690D
// Name: public: virtual long COleControlSite::XNotifyDBEvents::AboutToDo(unsigned long,unsigned long,struct tagDBNOTIFYREASON __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XNotifyDBEvents::AboutToDo(
        COleControlSite::XNotifyDBEvents *this,
        char dwEventWhat,
        unsigned int cReasons,
        tagDBNOTIFYREASON *rgReasons)
{
  HRESULT v4; // eax
  HRESULT v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 50));
  v4 = COleControlSite::XNotifyDBEvents::FireEvent(this, dwEventWhat, cReasons, rgReasons, nState: dscAboutToDo);
  if ( v4 >= 0 )
    v5 = 0;
  else
    v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00426951
// Name: public: virtual long COleControlSite::XNotifyDBEvents::FailedToDo(unsigned long,unsigned long,struct tagDBNOTIFYREASON __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XNotifyDBEvents::FailedToDo(
        COleControlSite::XNotifyDBEvents *this,
        char dwEventWhat,
        unsigned int cReasons,
        tagDBNOTIFYREASON *rgReasons)
{
  HRESULT v4; // eax
  HRESULT v5; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 50));
  v4 = COleControlSite::XNotifyDBEvents::FireEvent(this, dwEventWhat, cReasons, rgReasons, nState: dscFailedToDo);
  if ( v4 >= 0 )
    v5 = 0;
  else
    v5 = v4;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00426995
// Name: public: virtual long COleControlSite::XNotifyDBEvents::SyncAfter(unsigned long,unsigned long,struct tagDBNOTIFYREASON __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XNotifyDBEvents::SyncAfter(
        COleControlSite::XNotifyDBEvents *this,
        char dwEventWhat,
        unsigned int cReasons,
        tagDBNOTIFYREASON *rgReasons)
{
  HRESULT v4; // eax
  HRESULT v5; // esi
  CDataSourceControl *v7; // esi
  unsigned int dwReason; // edi
  CDataSourceControl_vtbl *v9; // eax
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+8h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 50));
  v4 = COleControlSite::XNotifyDBEvents::FireEvent(this, dwEventWhat, cReasons, rgReasons, nState: dscSyncAfter);
  if ( v4 < 0 )
  {
    v5 = v4;
LABEL_3:
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return v5;
  }
  v7 = *((CDataSourceControl **)this - 21);
  dwReason = rgReasons->dwReason;
  if ( v7 == nullptr )
  {
LABEL_5:
    v5 = 0;
    goto LABEL_3;
  }
  if ( v7->m_bUpdateInProgress == 0 && dwReason != 31 && dwReason != 30 )
  {
    if ( (dwEventWhat & 3) == 0 )
      goto LABEL_5;
    if ( dwReason != 2 && dwReason != 3 )
    {
      v7->m_bUpdateInProgress = 1;
      CDataSourceControl::GetBoundClientRow(this: v7);
      v9 = v7->__vftable;
      v7->m_bUpdateInProgress = 0;
      v9->UpdateControls(this: v7);
    }
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00426A2A
// Name: public: virtual long COleControlSite::XNotifyDBEvents::DidEvent(unsigned long,unsigned long,struct tagDBNOTIFYREASON __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XNotifyDBEvents::DidEvent(
        COleControlSite::XNotifyDBEvents *this,
        char dwEventWhat,
        unsigned int cReasons,
        tagDBNOTIFYREASON *rgReasons)
{
  HRESULT v4; // eax
  HRESULT v5; // esi
  CDataSourceControl *v7; // esi
  int m_bUpdateInProgress; // edi
  CDataSourceControl_vtbl *v9; // eax
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 50));
  v4 = COleControlSite::XNotifyDBEvents::FireEvent(this, dwEventWhat, cReasons, rgReasons, nState: dscDidEvent);
  if ( v4 >= 0 )
  {
    v7 = *((CDataSourceControl **)this - 21);
    if ( v7 != nullptr && dwEventWhat < 0 )
    {
      m_bUpdateInProgress = v7->m_bUpdateInProgress;
      v7->m_bUpdateInProgress = 1;
      CDataSourceControl::GetBoundClientRow(this: v7);
      v9 = v7->__vftable;
      v7->m_bUpdateInProgress = m_bUpdateInProgress;
      v9->UpdateControls(this: v7);
    }
    v5 = 0;
  }
  else
  {
    v5 = v4;
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00426A9A
// Name: public: virtual long COleControlSite::XRowsetNotify::OnFieldChange(struct IRowset __near *,unsigned long,unsigned long,unsigned long __near * const,unsigned long,unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XRowsetNotify::OnFieldChange(
        COleControlSite::XRowsetNotify *this,
        IRowset *__formal,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5,
        unsigned int a6,
        unsigned int ePhase,
        int a8)
{
  HRESULT m_hResult; // ebx
  CDataSourceControl *v10; // esi
  CDataSourceControl_vtbl *v12; // eax
  AFX_EVENT event; // [esp+Ch] [ebp-2Ch] BYREF
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+30h] [ebp-8h] BYREF
  DSCSTATE nState; // [esp+40h] [ebp+8h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 51));
  m_hResult = 0;
  nState = dscNoState;
  switch ( ePhase )
  {
    case 0u:
      nState = dscOKToDo;
      goto LABEL_14;
    case 1u:
      nState = dscAboutToDo;
      goto LABEL_14;
    case 2u:
      nState = dscSyncAfter;
      goto LABEL_14;
    case 3u:
      nState = dscFailedToDo;
      goto LABEL_14;
    default:
      break;
  }
  if ( ePhase != 4 )
  {
LABEL_14:
    event.m_dispid = -1;
    event.m_nDSCState = nState;
    event.m_eventKind = 3;
    memset(&event.m_pDispParams, 0, 12);
    event.m_hResult = 0;
    event.m_nDSCReason = dscModify;
    COleControlSite::OnEvent(this: (COleControlSite *)(this - 58), pEvent: &event);
    m_hResult = event.m_hResult;
    goto LABEL_7;
  }
  v10 = *((CDataSourceControl **)this - 22);
  nState = dscDidEvent;
  if ( v10 != nullptr )
  {
    if ( v10->m_bUpdateInProgress == 0 )
    {
      v10->m_bUpdateInProgress = 1;
      CDataSourceControl::GetBoundClientRow(this: v10);
      v12 = v10->__vftable;
      v10->m_bUpdateInProgress = 0;
      v12->UpdateControls(this: v10);
    }
    goto LABEL_14;
  }
LABEL_7:
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return m_hResult;
}

//------------------------------------------------------------------------------
// Address: 0x00426B69
// Name: public: virtual long COleControlSite::XRowsetNotify::OnRowChange(struct IRowset __near *,unsigned long,unsigned long const __near * const,unsigned long,unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XRowsetNotify::OnRowChange(
        COleControlSite::XRowsetNotify *this,
        IRowset *__formal,
        unsigned int cRows,
        unsigned int *rghRows,
        unsigned int eReason,
        unsigned int ePhase,
        int a7)
{
  CDataSourceControl *v8; // esi
  HRESULT m_hResult; // esi
  int m_bUpdateInProgress; // edi
  AFX_EVENT event; // [esp+Ch] [ebp-30h] BYREF
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+30h] [ebp-Ch] BYREF
  DSCSTATE nState; // [esp+38h] [ebp-4h]
  DSCREASON nReason; // [esp+44h] [ebp+8h]

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 51));
  nState = dscNoState;
  if ( ePhase != 0 )
  {
    switch ( ePhase )
    {
      case 1u:
        nState = dscAboutToDo;
        break;
      case 2u:
        nState = dscSyncAfter;
        break;
      case 3u:
        nState = dscFailedToDo;
        break;
      case 4u:
        nState = dscDidEvent;
        break;
      default:
        break;
    }
  }
  else
  {
    nState = dscOKToDo;
  }
  nReason = dscNoReason;
  switch ( eReason )
  {
    case 4u:
      nReason = dscMove;
      break;
    case 6u:
      nReason = dscDelete;
      break;
    case 8u:
      nReason = dscInsert;
      break;
    case 0xDu:
      nReason = dscCommit;
      break;
    default:
      break;
  }
  v8 = *((CDataSourceControl **)this - 22);
  if ( v8 == nullptr )
    goto LABEL_20;
  if ( nReason == dscCommit )
  {
    if ( nState == dscAboutToDo )
    {
      v8->UpdateCursor(this: *((CDataSourceControl **)this - 22));
      goto LABEL_32;
    }
LABEL_27:
    if ( nState != dscSyncAfter || nReason != dscInsert )
      goto LABEL_31;
    goto LABEL_29;
  }
  if ( nReason != dscMove || cRows != 1 )
    goto LABEL_27;
LABEL_29:
  v8->UpdateCursor(this: *((CDataSourceControl **)this - 22));
  v8->m_pRowset->m_hRow = *rghRows;
  m_bUpdateInProgress = v8->m_bUpdateInProgress;
  v8->m_bUpdateInProgress = 1;
  CDataSourceControl::GetBoundClientRow(this: v8);
  v8->m_bUpdateInProgress = m_bUpdateInProgress;
  if ( m_bUpdateInProgress == 0 )
    v8->UpdateControls(this: v8);
LABEL_31:
  if ( nReason != dscNoReason )
  {
LABEL_32:
    event.m_dispid = -1;
    event.m_nDSCState = nState;
    event.m_nDSCReason = nReason;
    event.m_eventKind = 3;
    memset(&event.m_pDispParams, 0, 12);
    event.m_hResult = 0;
    COleControlSite::OnEvent(this: (COleControlSite *)(this - 58), pEvent: &event);
    m_hResult = event.m_hResult;
    if ( event.m_hResult < 0 )
      goto LABEL_21;
  }
LABEL_20:
  m_hResult = 0;
LABEL_21:
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return m_hResult;
}

//------------------------------------------------------------------------------
// Address: 0x00426CBA
// Name: public: void ATL::CRowset<class ATL::CAccessorBase>::SetupOptionalRowsetInterfaces(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CRowset<ATL::CAccessorBase>::SetupOptionalRowsetInterfaces(ATL::CRowset<ATL::CAccessorBase> *this)
{
  if ( this->m_spRowset.p != nullptr )
    this->m_spRowset.p->QueryInterface(
      this: this->m_spRowset.p,
      a2: &_GUID_0c733a05_2a1c_11ce_ade5_00aa0044773d,
      a3: (void **)&this->m_spRowsetChange);
}

//------------------------------------------------------------------------------
// Address: 0x00426CCF
// Name: public: long ATL::CRowset<class ATL::CAccessorBase>::SetData(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CRowset<ATL::CAccessorBase>::SetData(
        ATL::CRowset<ATL::CAccessorBase> *this,
        unsigned int nAccessor)
{
  IRowsetChange *p; // edx
  ATL::CAccessorBase *m_pAccessor; // eax
  unsigned int hAccessor; // esi

  p = this->m_spRowsetChange.p;
  if ( p == nullptr )
    return -2147467262;
  m_pAccessor = this->m_pAccessor;
  if ( nAccessor < m_pAccessor->m_nAccessors )
    hAccessor = m_pAccessor->m_pAccessorInfo[nAccessor].hAccessor;
  else
    hAccessor = 0;
  return p->SetData(this: p, a2: this->m_hRow, a3: hAccessor, a4: m_pAccessor->m_pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x00426D0C
// Name: public: static void ATL::CAccessorBase::FreeType(unsigned short,unsigned char __near *,struct IRowset __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ATL::CAccessorBase::FreeType(unsigned __int16 wType, VARIANTARG *pValue, IRowset *pRowset)
{
  VARIANTARG *v3; // esi

  v3 = pValue;
  if ( pValue == nullptr )
    return;
  if ( (wType & 0x2000) != 0 )
  {
    if ( *(_DWORD *)&pValue->vt == 0 )
      goto LABEL_19;
    SafeArrayDestroy(psa: *(SAFEARRAY **)&pValue->vt);
    goto LABEL_18;
  }
  if ( wType == 8 )
  {
    SysFreeString(bstrString: *(BSTR *)&pValue->vt);
    goto LABEL_18;
  }
  if ( wType != 9 )
  {
    if ( wType == 12 )
    {
      VariantClear(pvarg: pValue);
      goto LABEL_19;
    }
    if ( wType != 13 )
    {
      if ( wType == 136 )
      {
        pValue = nullptr;
        if ( pRowset != nullptr )
        {
          pRowset->QueryInterface(this: pRowset, a2: &_GUID_0c733a93_2a1c_11ce_ade5_00aa0044773d, a3: (void **)&pValue);
          if ( pValue != nullptr )
          {
            (*(void (__stdcall **)(VARIANTARG *, _DWORD, _DWORD))(*(_DWORD *)&pValue->vt + 16))(
              a1: pValue,
              a2: *(_DWORD *)&v3->vt,
              a3: 0);
            if ( pValue != nullptr )
              (*(void (__stdcall **)(VARIANTARG *))(*(_DWORD *)&pValue->vt + 8))(a1: pValue);
          }
        }
      }
      goto LABEL_19;
    }
  }
  if ( *(_DWORD *)&pValue->vt != 0 )
  {
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)&pValue->vt + 8))(a1: *(_DWORD *)&pValue->vt);
LABEL_18:
    *(_DWORD *)&v3->vt = 0;
  }
LABEL_19:
  if ( (wType & 0x1000) != 0 && (wType & 0x4000) != 0xFFFFFFFF )
    CoTaskMemFree(pv: (LPVOID)v3->decVal.Hi32);
}

//------------------------------------------------------------------------------
// Address: 0x00426DCD
// Name: public: void ATL::CDynamicAccessor::FreeRecordMemory(struct IRowset __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CDynamicAccessor::FreeRecordMemory(ATL::CDynamicAccessor *this, IRowset *pRowset)
{
  int v2; // edi
  bool *m_pfClientOwnedMemRef; // eax
  unsigned __int8 *m_pBuffer; // ecx
  LPVOID *v6; // ebx
  int wType; // eax
  unsigned __int8 *v8; // ecx
  unsigned int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < this->m_nColumns; ++v2 )
  {
    m_pfClientOwnedMemRef = this->m_pfClientOwnedMemRef;
    if ( m_pfClientOwnedMemRef != nullptr && m_pfClientOwnedMemRef[i] )
    {
      m_pBuffer = this->m_pBuffer;
      if ( *(_DWORD *)&m_pBuffer[((((int)&this->m_pColumnInfo[v2].pTypeInfo->__vftable
                                  + this->m_pColumnInfo[v2].ulColumnSize
                                  + 3)
                                 & 0xFFFFFFFC)
                                + 4)
                               & 0xFFFFFFFC] != 3 )
      {
        v6 = (LPVOID *)&m_pBuffer[(unsigned int)this->m_pColumnInfo[v2].pTypeInfo];
        if ( v6 != nullptr && *v6 != nullptr )
        {
          CoTaskMemFree(pv: *v6);
          *v6 = nullptr;
        }
      }
    }
    else
    {
      wType = this->m_pColumnInfo[v2].wType;
      if ( wType == 13 || wType == 9 )
      {
        v8 = this->m_pBuffer;
        if ( *(_DWORD *)&v8[((((int)&this->m_pColumnInfo[v2].pTypeInfo->__vftable
                             + this->m_pColumnInfo[v2].ulColumnSize
                             + 3)
                            & 0xFFFFFFFC)
                           + 4)
                          & 0xFFFFFFFC] == 0 )
          ATL::CAccessorBase::FreeType(
            wType: this->m_pColumnInfo[v2].wType,
            pValue: (VARIANTARG *)&v8[(unsigned int)this->m_pColumnInfo[v2].pTypeInfo],
            pRowset);
      }
      else
      {
        ATL::CAccessorBase::FreeType(
          wType: this->m_pColumnInfo[v2].wType,
          pValue: (VARIANTARG *)&this->m_pBuffer[(unsigned int)this->m_pColumnInfo[v2].pTypeInfo],
          pRowset);
      }
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426EAB
// Name: public: virtual void CDataSourceControl::BindColumns(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDataSourceControl::BindColumns(CDataSourceControl *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // edx
  int v5; // ecx
  CPtrList **p_m_pClientList; // eax
  int m_nBindings; // eax
  CPtrList::CNode *m_pNodeHead; // ebx
  int v9; // edi
  CPtrList::CNode *v10; // eax
  int v11; // eax
  int v12; // ebx
  COleControlSite *pSite; // [esp+8h] [ebp-10h]
  int nCol; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  int nItem; // [esp+14h] [ebp-4h]

  v2 = 0;
  if ( this->m_pDataSource != nullptr )
  {
    CDataSourceControl::GetBoundClientRow(this);
    this->UpdateControls(this);
  }
  else
  {
    if ( this->m_pValues != nullptr )
    {
      v3 = 0;
      if ( this->m_nBindings > 0 )
      {
        do
        {
          VariantClear(pvarg: (VARIANTARG *)((char *)this->m_pValues + v2));
          ++v3;
          v2 += 16;
        }
        while ( v3 < this->m_nBindings );
        v2 = 0;
        if ( this->m_nBindings > 0 )
        {
          operator delete(p: this->m_pValues);
          operator delete(p: this->m_pColumnBindings);
        }
      }
      this->m_pValues = nullptr;
    }
    v4 = 0;
    this->m_nBindings = 0;
    if ( this->m_nColumns > 0 )
    {
      v5 = 0;
      p_m_pClientList = &this->m_pMetaRowData->m_pClientList;
      do
      {
        v5 += (*p_m_pClientList)->m_nCount;
        ++v4;
        this->m_nBindings = v5;
        p_m_pClientList += 10;
      }
      while ( v4 < this->m_nColumns );
    }
    m_nBindings = this->m_nBindings;
    if ( m_nBindings > 0 )
      this->m_pColumnBindings = (tagDBCOLUMNBINDING *)operator new(nSize: 48 * m_nBindings);
    nItem = 0;
    nCol = 0;
    if ( this->m_nColumns > 0 )
    {
      v15 = 0;
      do
      {
        m_pNodeHead = this->m_pMetaRowData[v15].m_pClientList->m_pNodeHead;
        if ( m_pNodeHead != nullptr )
        {
          v9 = nItem;
          do
          {
            v10 = m_pNodeHead;
            m_pNodeHead = m_pNodeHead->pNext;
            pSite = (COleControlSite *)v10->data;
            CDataSourceControl::CopyColumnID(
              this,
              pcidDst: &this->m_pColumnBindings[v9].columnID,
              pcidSrc: &this->m_pMetaRowData[v15].idColumnID);
            this->m_pColumnBindings[v9].obData = 16 * nItem;
            this->m_pColumnBindings[v9].cbMaxLen = 0;
            this->m_pColumnBindings[v9].obInfo = -1;
            this->m_pColumnBindings[v9].obVarDataLen = -1;
            ++nItem;
            this->m_pColumnBindings[v9].dwBinding = 1;
            this->m_pColumnBindings[v9++].dwDataType = pSite->m_dwType;
          }
          while ( m_pNodeHead != nullptr );
          v2 = 0;
        }
        ++nCol;
        ++v15;
      }
      while ( nCol < this->m_nColumns );
    }
    this->m_pCursorMove->SetBindings(
      this: this->m_pCursorMove,
      a2: this->m_nBindings,
      a3: this->m_pColumnBindings,
      a4: 16 * this->m_nBindings,
      a5: 0);
    v11 = this->m_nBindings;
    if ( v11 != 0 )
      this->m_pValues = (tagVARIANT *)operator new(nSize: 16 * v11);
    v12 = 0;
    if ( this->m_nBindings > 0 )
    {
      do
      {
        memset(dst: (int)&this->m_pValues[v12], value: nullptr, count: sizeof(this->m_pValues[v12]));
        this->m_pValues[v12].vt = 0;
        ++v2;
        ++v12;
      }
      while ( v2 < this->m_nBindings );
    }
    CDataSourceControl::GetBoundClientRow(this);
    this->UpdateControls(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427077
// Name: public: ATL::CRowset<class ATL::CAccessorBase>::CRowset<class ATL::CAccessorBase>(struct IRowset __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ATL::CRowset<ATL::CAccessorBase> *__thiscall ATL::CRowset<ATL::CAccessorBase>::CRowset<ATL::CAccessorBase>(
        ATL::CRowset<ATL::CAccessorBase> *this,
        IRowset *pRowset)
{
  this->m_spRowset.p = nullptr;
  this->m_spRowsetChange.p = nullptr;
  this->m_pXMLAccessor = nullptr;
  this->m_pAccessor = nullptr;
  this->m_hRow = 0;
  if ( this->m_spRowset.p != pRowset )
    ATL::AtlComPtrAssign(pp: &this->m_spRowset.p, lp: pRowset);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004270A4
// Name: public: long ATL::CRowset<class ATL::CAccessorBase>::MoveFirst(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CRowset<ATL::CAccessorBase>::MoveFirst(ATL::CRowset<ATL::CAccessorBase> *this)
{
  HRESULT result; // eax

  ATL::CRowset<ATL::CAccessorBase>::ReleaseRows(this);
  result = this->m_spRowset.p->RestartPosition(this: this->m_spRowset.p, a2: 0);
  if ( result >= 0 )
    return ATL::CRowset<ATL::CAccessorBase>::MoveNext(this, lSkip: 0, bForward: true);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004270C9
// Name: public: long ATL::CRowset<class ATL::CAccessorBase>::SetData(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CRowset<ATL::CAccessorBase>::SetData(ATL::CRowset<ATL::CAccessorBase> *this)
{
  unsigned int m_nAccessors; // edi
  HRESULT result; // eax
  unsigned int i; // ebx

  m_nAccessors = this->m_pAccessor->m_nAccessors;
  result = 0;
  for ( i = 0; i < m_nAccessors; ++i )
  {
    result = ATL::CRowset<ATL::CAccessorBase>::SetData(this, nAccessor: i);
    if ( result < 0 )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004270F3
// Name: public: long ATL::CDynamicAccessor::GetRowsetProperties(struct IUnknown __near *,unsigned long __near *,int __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CDynamicAccessor::GetRowsetProperties(
        ATL::CDynamicAccessor *this,
        IUnknown *pUnk,
        unsigned int *prgPropertyIDs,
        int *pbValues,
        unsigned int nPropCount)
{
  IUnknown_vtbl *v6; // ecx
  tagDBPROPSET *m_pData; // eax
  unsigned int v8; // ecx
  int i; // esi
  unsigned int cProperties; // edx
  unsigned int cPropSets; // [esp+8h] [ebp-30h] BYREF
  int *v12; // [esp+Ch] [ebp-2Ch]
  ATL::CComPtr<IRowsetInfo> spRowsetInfo; // [esp+10h] [ebp-28h] BYREF
  HRESULT hr; // [esp+14h] [ebp-24h]
  ATL::CComHeapPtr<tagDBPROPSET> rgPropSets; // [esp+18h] [ebp-20h] BYREF
  tagDBPROPIDSET rgPropertyIDSets[1]; // [esp+1Ch] [ebp-1Ch] BYREF

  v12 = pbValues;
  if ( pUnk == nullptr || pbValues == nullptr )
    return -2147467259;
  v6 = pUnk->__vftable;
  spRowsetInfo.p = nullptr;
  hr = v6->QueryInterface(this: pUnk, a2: &_GUID_0c733a55_2a1c_11ce_ade5_00aa0044773d, a3: (void **)&spRowsetInfo.p);
  if ( nPropCount != 0 )
    memset(pbValues, 0, 4 * nPropCount);
  if ( hr >= 0 )
  {
    rgPropertyIDSets[0].rgPropertyIDs = prgPropertyIDs;
    rgPropertyIDSets[0].cPropertyIDs = nPropCount;
    rgPropertyIDSets[0].guidPropertySet.Data1 = -927653186;
    *(_DWORD *)&rgPropertyIDSets[0].guidPropertySet.Data2 = *(_DWORD *)&DBPROPSET_ROWSET.Data2;
    *(_DWORD *)rgPropertyIDSets[0].guidPropertySet.Data4 = *(_DWORD *)DBPROPSET_ROWSET.Data4;
    cPropSets = 0;
    rgPropSets.m_pData = nullptr;
    *(_DWORD *)&rgPropertyIDSets[0].guidPropertySet.Data4[4] = *(_DWORD *)&DBPROPSET_ROWSET.Data4[4];
    hr = spRowsetInfo.p->GetProperties(
           this: spRowsetInfo.p,
           a2: 1u,
           a3: rgPropertyIDSets,
           a4: &cPropSets,
           a5: (tagDBPROPSET **)&rgPropSets);
    m_pData = rgPropSets.m_pData;
    if ( hr >= 0 )
    {
      v8 = 0;
      for ( i = 0; ; ++i )
      {
        cProperties = m_pData->cProperties;
        if ( cProperties >= nPropCount )
          cProperties = nPropCount;
        if ( v8 >= cProperties )
          break;
        v12[v8++] = m_pData->rgProperties[i].vValue.iVal;
      }
      if ( m_pData->rgProperties != nullptr )
      {
        CoTaskMemFree(pv: m_pData->rgProperties);
        m_pData = rgPropSets.m_pData;
      }
    }
    CoTaskMemFree(pv: m_pData);
  }
  if ( spRowsetInfo.p != nullptr )
    spRowsetInfo.p->Release(this: spRowsetInfo.p);
  return hr;
}

//------------------------------------------------------------------------------
// Address: 0x004271E4
// Name: public: long ATL::CDynamicAccessor::BindColumns(struct IUnknown __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CDynamicAccessor::BindColumns(ATL::CDynamicAccessor *this, IUnknown *pUnk)
{
  IUnknown_vtbl *v4; // eax
  IAccessor *p; // eax
  bool v6; // zf
  IUnknown_vtbl *v7; // eax
  int v8; // edi
  int v9; // esi
  IColumnsInfo *v10; // eax
  IAccessor *v11; // eax
  bool v12; // zf
  unsigned int m_nColumns; // eax
  tagDBBINDING *v14; // eax
  IAccessor *v15; // eax
  bool v16; // zf
  unsigned int v17; // edi
  unsigned int v18; // edi
  tagDBCOLUMNINFO *v19; // eax
  ATL::DBBLOBHANDLINGENUM m_eBlobHandling; // ecx
  unsigned int v21; // ecx
  tagDBCOLUMNINFO *v22; // eax
  unsigned int v23; // esi
  unsigned int v24; // ecx
  unsigned int Alignment; // eax
  IColumnsInfo *v26; // eax
  unsigned int v27; // ecx
  GUID *v28; // esi
  unsigned __int16 *p_Data2; // esi
  unsigned int v30; // edi
  void **p_pObject; // esi
  _GUID *p_iidStreamToUse; // esi
  tagDBOBJECT *v33; // eax
  unsigned __int16 *v34; // esi
  unsigned int v35; // eax
  IColumnsInfo *v36; // edx
  int wType; // ecx
  unsigned int v38; // edi
  void **v39; // esi
  tagDBCOLUMNINFO *m_pColumnInfo; // eax
  unsigned int v41; // eax
  tagDBCOLUMNINFO *v42; // eax
  unsigned int v43; // esi
  void **v44; // edi
  unsigned __int8 *m_pBuffer; // eax
  unsigned int v46; // edi
  void **v47; // esi
  IColumnsInfo_vtbl *v48; // [esp-2Ch] [ebp-A8h]
  unsigned __int16 v49; // [esp-28h] [ebp-A4h]
  IColumnsInfo_vtbl *v50; // [esp-24h] [ebp-A0h]
  unsigned __int8 v51; // [esp-20h] [ebp-9Ch]
  unsigned __int8 v52; // [esp-1Ch] [ebp-98h]
  unsigned int v53; // [esp-14h] [ebp-90h]
  unsigned int v54; // [esp-10h] [ebp-8Ch]
  unsigned int v55; // [esp-Ch] [ebp-88h]
  tagDBBINDING *m_p; // [esp-8h] [ebp-84h]
  tagDBOBJECT *v57; // [esp-8h] [ebp-84h]
  tagDBBINDING *v58; // [esp-8h] [ebp-84h]
  unsigned int v59; // [esp-4h] [ebp-80h]
  unsigned int v60; // [esp-4h] [ebp-80h]
  _GUID iidStreamToUse; // [esp+10h] [ebp-6Ch] BYREF
  unsigned int rgPropertyIDs[2]; // [esp+20h] [ebp-5Ch] BYREF
  int rgStreamsSupported[2]; // [esp+28h] [ebp-54h] BYREF
  ATL::CAutoVectorPtr<tagDBBINDING> spBinding; // [esp+44h] [ebp-38h]
  ATL::CDynamicAccessor *v65; // [esp+48h] [ebp-34h]
  ATL::CComPtr<IColumnsInfo> spColumnsInfo; // [esp+4Ch] [ebp-30h] BYREF
  unsigned int i; // [esp+50h] [ebp-2Ch]
  tagDBBINDING *pBinding; // [esp+54h] [ebp-28h]
  tagDBOBJECT *pObject; // [esp+58h] [ebp-24h]
  ATL::CComPtr<IAccessor> spAccessor; // [esp+5Ch] [ebp-20h] BYREF
  tagDBBINDING *pCurrent; // [esp+60h] [ebp-1Ch]
  unsigned int nOffset; // [esp+64h] [ebp-18h]
  bool fIStreamSupportTested; // [esp+6Bh] [ebp-11h]
  int v74; // [esp+78h] [ebp-4h]

  v65 = this;
  iidStreamToUse.Data1 = 208878128;
  *(_DWORD *)&iidStreamToUse.Data2 = *(_DWORD *)&_GUID_0c733a30_2a1c_11ce_ade5_00aa0044773d.Data2;
  *(_QWORD *)iidStreamToUse.Data4 = *(_QWORD *)_GUID_0c733a30_2a1c_11ce_ade5_00aa0044773d.Data4;
  fIStreamSupportTested = false;
  if ( pUnk == nullptr )
    return -2147467259;
  spAccessor.p = nullptr;
  v4 = pUnk->__vftable;
  v74 = 0;
  spColumnsInfo.p = (IColumnsInfo *)v4->QueryInterface(
                                      this: pUnk,
                                      a2: &_GUID_0c733a8c_2a1c_11ce_ade5_00aa0044773d,
                                      a3: (void **)&spAccessor.p);
  if ( (int)spColumnsInfo.p < 0 )
  {
    p = spAccessor.p;
    v74 = -1;
    v6 = spAccessor.p == nullptr;
    goto LABEL_5;
  }
  nOffset = 0;
  if ( this->m_pColumnInfo != nullptr )
  {
    this->m_bOverride = true;
  }
  else
  {
    spColumnsInfo.p = nullptr;
    v7 = pUnk->__vftable;
    LOBYTE(v74) = 1;
    v8 = v7->QueryInterface(this: pUnk, a2: &_GUID_0c733a11_2a1c_11ce_ade5_00aa0044773d, a3: (void **)&spColumnsInfo.p);
    if ( v8 < 0 )
    {
      LOBYTE(v74) = 0;
      if ( spColumnsInfo.p != nullptr )
        spColumnsInfo.p->Release(this: spColumnsInfo.p);
      v74 = -1;
      if ( spAccessor.p != nullptr )
        spAccessor.p->Release(this: spAccessor.p);
      return v8;
    }
    v9 = spColumnsInfo.p->GetColumnInfo(
           this: spColumnsInfo.p,
           a2: &this->m_nColumns,
           a3: &this->m_pColumnInfo,
           a4: &this->m_pStringsBuffer);
    v10 = spColumnsInfo.p;
    LOBYTE(v74) = 0;
    if ( v9 < 0 )
    {
      if ( spColumnsInfo.p != nullptr )
        spColumnsInfo.p->Release(this: spColumnsInfo.p);
      v11 = spAccessor.p;
      v74 = -1;
      v12 = spAccessor.p == nullptr;
LABEL_80:
      if ( !v12 )
        v11->Release(this: v11);
      return v9;
    }
    this->m_bOverride = false;
    if ( v10 != nullptr )
      v10->Release(this: v10);
  }
  m_nColumns = this->m_nColumns;
  pBinding = nullptr;
  LOBYTE(v74) = 2;
  v14 = (tagDBBINDING *)operator new(nSize: 52 * m_nColumns);
  v74 = 0;
  pBinding = v14;
  if ( v14 == nullptr )
  {
LABEL_23:
    v15 = spAccessor.p;
    v74 = -1;
    v16 = spAccessor.p == nullptr;
LABEL_24:
    if ( !v16 )
      v15->Release(this: v15);
    return -2147024882;
  }
  spBinding.m_p = pBinding;
  v59 = this->m_nColumns;
  LOBYTE(v74) = 5;
  this->m_pfClientOwnedMemRef = (bool *)operator new(nSize: v59);
  v74 = 4;
  v17 = 0;
  if ( this->m_pfClientOwnedMemRef == nullptr )
  {
    LOBYTE(v74) = 0;
    operator delete(p: pBinding);
    v15 = spAccessor.p;
    v74 = -1;
    v16 = spAccessor.p == nullptr;
    goto LABEL_24;
  }
  pCurrent = pBinding;
  i = 0;
  while ( v17 < this->m_nColumns )
  {
    this->m_pfClientOwnedMemRef[v17] = false;
    v18 = v17;
    v19 = &this->m_pColumnInfo[v18];
    if ( v19->ulColumnSize > this->m_nBlobSize && v19->wType != 13 )
    {
      m_eBlobHandling = this->m_eBlobHandling;
      if ( m_eBlobHandling == DBBLOBHANDLING_SKIP )
      {
        v21 = (nOffset + 3) & 0xFFFFFFFC;
        spColumnsInfo.p = (IColumnsInfo *)((v21 + 7) & 0xFFFFFFFC);
        nOffset = (unsigned int)&spColumnsInfo.p[1];
        v19->ulColumnSize = 0;
        v22 = &this->m_pColumnInfo[v18];
        v23 = 0;
        ATL::CDynamicAccessor::BindEx(
          pBinding: pCurrent,
          nOrdinal: v22->iOrdinal,
          wType: v22->wType,
          nLength: v22->ulColumnSize,
          nPrecision: v22->bPrecision,
          nScale: v22->bScale,
          eParamIO: 0,
          nDataOffset: 0,
          nLengthOffset: v21,
          nStatusOffset: (v21 + 7) & 0xFFFFFFFC,
          pdbobject: nullptr,
          dwMemOwner: 0,
          fSkipData: true);
        goto LABEL_64;
      }
      if ( m_eBlobHandling == DBBLOBHANDLING_NOSTREAMS )
      {
        v19->wType |= 0x4000u;
        v24 = i;
        this->m_pColumnInfo[v18].ulColumnSize = 4;
        this->m_pfClientOwnedMemRef[v24] = true;
        spColumnsInfo.p = (IColumnsInfo *)&this->m_pColumnInfo[v18];
        Alignment = ATL::CDynamicAccessor::GetAlignment(bType: (unsigned __int16)spColumnsInfo.p[5].__vftable);
        v23 = ~(Alignment - 1) & (Alignment + nOffset - 1);
        v26 = spColumnsInfo.p;
        v27 = ((int)&spColumnsInfo.p[4].QueryInterface + v23 + 3) & 0xFFFFFFFC;
        spColumnsInfo.p = (IColumnsInfo *)((v27 + 7) & 0xFFFFFFFC);
        nOffset = (unsigned int)&spColumnsInfo.p[1];
        ATL::CDynamicAccessor::BindEx(
          pBinding: pCurrent,
          nOrdinal: (unsigned int)v26[2].__vftable,
          wType: (unsigned __int16)v26[5].__vftable,
          nLength: (unsigned int)v26[4].__vftable,
          nPrecision: BYTE2(v26[5].__vftable),
          nScale: HIBYTE(v26[5].__vftable),
          eParamIO: 0,
          nDataOffset: v23,
          nLengthOffset: v27,
          nStatusOffset: (unsigned int)spColumnsInfo.p,
          pdbobject: nullptr,
          dwMemOwner: 0,
          fSkipData: false);
        goto LABEL_64;
      }
      if ( !fIStreamSupportTested )
      {
        rgPropertyIDs[0] = 137;
        rgPropertyIDs[1] = 139;
        rgStreamsSupported[0] = 0;
        rgStreamsSupported[1] = 0;
        ATL::CDynamicAccessor::GetRowsetProperties(
          this,
          pUnk,
          prgPropertyIDs: rgPropertyIDs,
          pbValues: rgStreamsSupported,
          nPropCount: 2u);
        if ( rgStreamsSupported[0] != 0 )
        {
          v28 = &_GUID_0c733a30_2a1c_11ce_ade5_00aa0044773d;
          goto LABEL_42;
        }
        if ( rgStreamsSupported[1] != 0 )
        {
          v28 = &_GUID_0000000c_0000_0000_c000_000000000046;
LABEL_42:
          iidStreamToUse.Data1 = v28->Data1;
          p_Data2 = &v28->Data2;
          *(_DWORD *)&iidStreamToUse.Data2 = *(_DWORD *)p_Data2;
          *(_QWORD *)iidStreamToUse.Data4 = *(_QWORD *)(p_Data2 + 2);
        }
        fIStreamSupportTested = true;
      }
      pObject = nullptr;
      LOBYTE(v74) = 7;
      pObject = (tagDBOBJECT *)operator new(nSize: 0x14u);
      v74 = 4;
      if ( pObject == nullptr )
      {
        v30 = i;
        if ( i != 0 )
        {
          p_pObject = (void **)&pBinding->pObject;
          do
          {
            operator delete(p: *p_pObject);
            p_pObject += 13;
            --v30;
          }
          while ( v30 != 0 );
        }
LABEL_48:
        operator delete(p: this->m_pfClientOwnedMemRef);
        m_p = spBinding.m_p;
        this->m_pfClientOwnedMemRef = nullptr;
        LOBYTE(v74) = 0;
        operator delete(p: m_p);
        goto LABEL_23;
      }
      p_iidStreamToUse = &iidStreamToUse;
      goto LABEL_50;
    }
    wType = v19->wType;
    if ( wType != 13 )
    {
      if ( (_WORD)wType == 129 )
        ++v19->ulColumnSize;
      m_pColumnInfo = this->m_pColumnInfo;
      if ( m_pColumnInfo[v18].wType == 130 )
        m_pColumnInfo[v18].ulColumnSize = 2 * m_pColumnInfo[v18].ulColumnSize + 2;
      spColumnsInfo.p = (IColumnsInfo *)&this->m_pColumnInfo[v18];
      v41 = ATL::CDynamicAccessor::GetAlignment(bType: (unsigned __int16)spColumnsInfo.p[5].__vftable);
      v23 = ~(v41 - 1) & (v41 + nOffset - 1);
      v57 = nullptr;
      v36 = (IColumnsInfo *)(((((int)&spColumnsInfo.p[4].QueryInterface + v23 + 3) & 0xFFFFFFFC) + 7) & 0xFFFFFFFC);
      v55 = (unsigned int)v36;
      v54 = ((int)&spColumnsInfo.p[4].QueryInterface + v23 + 3) & 0xFFFFFFFC;
      v53 = v23;
      v52 = HIBYTE(spColumnsInfo.p[5].__vftable);
      v51 = BYTE2(spColumnsInfo.p[5].__vftable);
      v50 = spColumnsInfo.p[4].__vftable;
      v49 = (unsigned __int16)spColumnsInfo.p[5].__vftable;
      v48 = spColumnsInfo.p[2].__vftable;
      spColumnsInfo.p = v36;
      goto LABEL_63;
    }
    pObject = nullptr;
    LOBYTE(v74) = 9;
    pObject = (tagDBOBJECT *)operator new(nSize: 0x14u);
    v74 = 4;
    if ( pObject == nullptr )
    {
      v38 = i;
      if ( i != 0 )
      {
        v39 = (void **)&pBinding->pObject;
        do
        {
          operator delete(p: *v39);
          v39 += 13;
          --v38;
        }
        while ( v38 != 0 );
      }
      goto LABEL_48;
    }
    p_iidStreamToUse = &_GUID_00000000_0000_0000_c000_000000000046;
LABEL_50:
    v33 = pObject;
    pObject->dwFlags = 0;
    v33->iid.Data1 = p_iidStreamToUse->Data1;
    v34 = &p_iidStreamToUse->Data2;
    *(_DWORD *)&v33->iid.Data2 = *(_DWORD *)v34;
    v34 += 2;
    *(_DWORD *)v33->iid.Data4 = *(_DWORD *)v34;
    *(_DWORD *)&v33->iid.Data4[4] = *((_DWORD *)v34 + 1);
    v18 = i;
    this->m_pColumnInfo[v18].wType = 13;
    this->m_pColumnInfo[v18].ulColumnSize = 4;
    spColumnsInfo.p = (IColumnsInfo *)&this->m_pColumnInfo[v18];
    v35 = ATL::CDynamicAccessor::GetAlignment(bType: (unsigned __int16)spColumnsInfo.p[5].__vftable);
    v57 = pObject;
    v23 = ~(v35 - 1) & (v35 + nOffset - 1);
    v36 = (IColumnsInfo *)(((((int)&spColumnsInfo.p[4].QueryInterface + v23 + 3) & 0xFFFFFFFC) + 7) & 0xFFFFFFFC);
    v55 = (unsigned int)v36;
    v54 = ((int)&spColumnsInfo.p[4].QueryInterface + v23 + 3) & 0xFFFFFFFC;
    v53 = v23;
    v52 = HIBYTE(spColumnsInfo.p[5].__vftable);
    v51 = BYTE2(spColumnsInfo.p[5].__vftable);
    v50 = spColumnsInfo.p[4].__vftable;
    v49 = (unsigned __int16)spColumnsInfo.p[5].__vftable;
    v48 = spColumnsInfo.p[2].__vftable;
    spColumnsInfo.p = v36;
LABEL_63:
    nOffset = (unsigned int)&v36[1];
    ATL::CAccessorBase::Bind(
      pBinding: pCurrent,
      nOrdinal: (unsigned int)v48,
      wType: v49,
      nLength: (unsigned int)v50,
      nPrecision: v51,
      nScale: v52,
      eParamIO: 0,
      nDataOffset: v53,
      nLengthOffset: v54,
      nStatusOffset: v55,
      pdbobject: v57);
LABEL_64:
    ++pCurrent;
    v42 = this->m_pColumnInfo;
    ++i;
    v42[v18].pTypeInfo = (ITypeInfo *)v23;
    v17 = i;
  }
  if ( this->m_pAccessorInfo != nullptr )
  {
LABEL_72:
    v60 = nOffset;
    this->m_pBuffer = nullptr;
    LOBYTE(v74) = 11;
    this->m_pBuffer = (unsigned __int8 *)operator new(nSize: v60);
    v74 = 4;
    m_pBuffer = this->m_pBuffer;
    v46 = 0;
    if ( m_pBuffer == nullptr )
    {
      if ( this->m_nColumns != 0 )
      {
        v47 = (void **)&pBinding->pObject;
        do
        {
          operator delete(p: *v47);
          ++v46;
          v47 += 13;
        }
        while ( v46 < this->m_nColumns );
      }
      goto LABEL_48;
    }
    memset(dst: (int)m_pBuffer, value: nullptr, count: nOffset);
    v9 = ATL::CAccessorBase::BindEntries(
           pBindings: pBinding,
           nColumns: this->m_nColumns,
           pHAccessor: &this->m_pAccessorInfo->hAccessor,
           nSize: nOffset,
           pAccessor: spAccessor.p);
    if ( v9 < 0 )
    {
      operator delete(p: this->m_pfClientOwnedMemRef);
      this->m_pfClientOwnedMemRef = nullptr;
    }
    LOBYTE(v74) = 0;
    operator delete(p: spBinding.m_p);
    v11 = spAccessor.p;
    v74 = -1;
    v12 = spAccessor.p == nullptr;
    goto LABEL_80;
  }
  spColumnsInfo.p = (IColumnsInfo *)ATL::CAccessorBase::AllocateAccessorMemory(this, nAccessors: 1u);
  if ( (int)spColumnsInfo.p >= 0 )
  {
    this->m_pAccessorInfo->bAutoAccessor = true;
    goto LABEL_72;
  }
  v43 = 0;
  if ( this->m_nColumns != 0 )
  {
    v44 = (void **)&pBinding->pObject;
    do
    {
      operator delete(p: *v44);
      ++v43;
      v44 += 13;
    }
    while ( v43 < this->m_nColumns );
  }
  operator delete(p: this->m_pfClientOwnedMemRef);
  v58 = spBinding.m_p;
  this->m_pfClientOwnedMemRef = nullptr;
  LOBYTE(v74) = 0;
  operator delete(p: v58);
  p = spAccessor.p;
  v74 = -1;
  v6 = spAccessor.p == nullptr;
LABEL_5:
  if ( !v6 )
    p->Release(this: p);
  return (HRESULT)spColumnsInfo.p;
}

//------------------------------------------------------------------------------
// Address: 0x0042783D
// Name: public: long CDataSourceControl::GetMetaData(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CDataSourceControl::GetMetaData(CDataSourceControl *this)
{
  HRESULT result; // eax
  ATL::CRowset<ATL::CAccessorBase> *v3; // eax
  ATL::CRowset<ATL::CAccessorBase> *v4; // eax
  ATL::CDynamicAccessor *v5; // eax
  ATL::CRowset<ATL::CAccessorBase> *m_pRowset; // edx
  unsigned int v7; // eax
  CDataSourceControl::METAROWTYPE *v8; // eax
  ICursorMove *m_pCursorMove; // eax
  int v10; // ebx
  void *v11; // ecx
  int v12; // eax
  int v13; // ebx
  CPtrList *v14; // eax
  CPtrList *v15; // eax
  CDataSourceControl::METAROWTYPE *m_pMetaRowData; // ecx
  CObList::CNode *m_pNodeHead; // ebx
  CObList::CNode *v18; // eax
  _DWORD v19[2]; // [esp+10h] [ebp-A8h] BYREF
  CDataSourceControl::METAROWTYPE *v20; // [esp+18h] [ebp-A0h]
  void *v21; // [esp+1Ch] [ebp-9Ch]
  int v22; // [esp+20h] [ebp-98h]
  int v23; // [esp+24h] [ebp-94h]
  int v24; // [esp+28h] [ebp-90h] BYREF
  int m_nColumns; // [esp+2Ch] [ebp-8Ch]
  LPVOID pv; // [esp+30h] [ebp-88h]
  int v27; // [esp+34h] [ebp-84h]
  void *p; // [esp+38h] [ebp-80h] BYREF
  int v29; // [esp+3Ch] [ebp-7Ch] BYREF
  CObList **v30; // [esp+40h] [ebp-78h] BYREF
  IRowset *pRowset; // [esp+44h] [ebp-74h] BYREF
  tagDBCOLUMNID pcidDst; // [esp+48h] [ebp-70h] BYREF
  int v33; // [esp+60h] [ebp-58h]
  int v34; // [esp+64h] [ebp-54h]
  int v35; // [esp+68h] [ebp-50h]
  int v36; // [esp+6Ch] [ebp-4Ch]
  int v37; // [esp+70h] [ebp-48h]
  int v38; // [esp+74h] [ebp-44h]
  tagDBCOLUMNID v39; // [esp+78h] [ebp-40h] BYREF
  int v40; // [esp+90h] [ebp-28h]
  int v41; // [esp+94h] [ebp-24h]
  int v42; // [esp+98h] [ebp-20h]
  int v43; // [esp+9Ch] [ebp-1Ch]
  int v44; // [esp+A0h] [ebp-18h]
  int v45; // [esp+A4h] [ebp-14h]
  int v46; // [esp+B4h] [ebp-4h]

  pv = this->m_pMetaRowData;
  m_nColumns = this->m_nColumns;
  if ( this->m_pDataSource != nullptr )
  {
    result = this->m_pRowPosition->GetRowset(this: this->m_pRowPosition, a2: &IID_IRowset, a3: &pRowset);
    v27 = result;
    if ( result < 0 )
      return result;
    if ( pRowset->QueryInterface(this: pRowset, a2: &IID_IConnectionPointContainer, a3: &p) >= 0 )
    {
      v30 = nullptr;
      if ( (*(int (__stdcall **)(void *, GUID *, CObList ***))(*(_DWORD *)p + 16))(
             a1: p,
             a2: &IID_IRowsetNotify,
             a3: &v30) >= 0 )
      {
        ((void (__stdcall *)(CObList **, COleControlSite::XRowsetNotify *, unsigned int *))(*v30)->m_pBlocks)(
          a1: v30,
          a2: &this->m_pClientSite->m_xRowsetNotify,
          a3: &this->m_dwRowsetNotify);
        ((void (__stdcall *)(CObList **))(*v30)->m_pNodeTail)(a1: v30);
      }
      (*(void (__stdcall **)(void *))(*(_DWORD *)p + 8))(a1: p);
    }
    v3 = (ATL::CRowset<ATL::CAccessorBase> *)operator new(nSize: 0x14u);
    if ( v3 != nullptr )
      v4 = ATL::CRowset<ATL::CAccessorBase>::CRowset<ATL::CAccessorBase>(this: v3, pRowset);
    else
      v4 = nullptr;
    this->m_pRowset = v4;
    pRowset->Release(this: pRowset);
    ATL::CRowset<ATL::CAccessorBase>::SetupOptionalRowsetInterfaces(this: this->m_pRowset);
    v5 = (ATL::CDynamicAccessor *)operator new(nSize: 0x28u);
    if ( v5 != nullptr )
    {
      v5->m_pAccessorInfo = nullptr;
      v5->m_nAccessors = 0;
      v5->m_pBuffer = nullptr;
      v5->m_nColumns = 0;
      v5->m_pColumnInfo = nullptr;
      v5->m_pStringsBuffer = nullptr;
      v5->m_eBlobHandling = DBBLOBHANDLING_DEFAULT;
      v5->m_nBlobSize = 8000;
      v5->m_pfClientOwnedMemRef = nullptr;
    }
    else
    {
      v5 = nullptr;
    }
    m_pRowset = this->m_pRowset;
    this->m_pDynamicAccessor = v5;
    ATL::CDynamicAccessor::BindColumns(this: v5, pUnk: m_pRowset->m_spRowset.p);
    this->m_pRowset->m_pAccessor = this->m_pDynamicAccessor;
    v7 = this->m_pDynamicAccessor->m_nColumns;
    this->m_nColumns = v7;
    if ( v7 > 0x3333333 )
      return -2147024882;
    v8 = (CDataSourceControl::METAROWTYPE *)CoTaskMemAlloc(cb: 40 * v7);
    this->m_pMetaRowData = v8;
    if ( v8 == nullptr )
      AfxThrowMemoryException();
    memset(dst: (int)v8, value: nullptr, count: 40 * this->m_nColumns);
    ATL::CRowset<ATL::CAccessorBase>::MoveFirst(this: this->m_pRowset);
    ATL::CRowset<ATL::CAccessorBase>::ReleaseRows(this: this->m_pRowset);
    goto LABEL_26;
  }
  m_pCursorMove = this->m_pCursorMove;
  if ( m_pCursorMove == nullptr )
    return 0;
  result = m_pCursorMove->GetColumnsCursor(
             this: m_pCursorMove,
             a2: &IID_ICursor,
             a3: (IUnknown **)&v29,
             a4: (unsigned int *)&v24);
  if ( result >= 0 )
  {
    CDataSourceControl::CopyColumnID(this, &pcidDst, pcidSrc: &COLUMN_COLUMNID);
    v35 = -1;
    v33 = 0;
    v34 = 0;
    v36 = 24;
    v37 = 0;
    v38 = 507;
    CDataSourceControl::CopyColumnID(this, pcidDst: &v39, pcidSrc: &COLUMN_NAME);
    v42 = -1;
    v40 = 28;
    v41 = 0;
    v43 = 32;
    v44 = 0;
    v45 = 30;
    v10 = (*(int (__stdcall **)(int, int, tagDBCOLUMNID *, int, _DWORD))(*(_DWORD *)v29 + 16))(
            a1: v29,
            a2: 2,
            a3: &pcidDst,
            a4: 40,
            a5: 0);
    if ( v10 < 0 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v29 + 8))(a1: v29);
      return v10;
    }
    v19[0] = v24;
    v19[1] = 1;
    v20 = nullptr;
    v21 = nullptr;
    v22 = 0;
    v27 = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)v29 + 24))(a1: v29, a2: 0, a3: 0, a4: v19);
    if ( v27 < 0 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v29 + 8))(a1: v29);
      return v27;
    }
    v11 = v21;
    this->m_pMetaRowData = v20;
    v24 = v23;
    this->m_nColumns = v23;
    v12 = v29;
    this->m_pVarData = v11;
    (*(void (__stdcall **)(int))(*(_DWORD *)v12 + 8))(a1: v12);
LABEL_26:
    pRowset = nullptr;
    if ( this->m_nColumns > 0 )
    {
      v13 = 0;
      do
      {
        v14 = (CPtrList *)operator new(nSize: 0x1Cu);
        p = v14;
        v46 = 0;
        if ( v14 != nullptr )
          v15 = CPtrList::CPtrList(this: v14, nBlockSize: 10);
        else
          v15 = nullptr;
        v46 = -1;
        m_pMetaRowData = this->m_pMetaRowData;
        pRowset = (IRowset *)((char *)pRowset + 1);
        m_pMetaRowData[v13++].m_pClientList = v15;
      }
      while ( (int)pRowset < this->m_nColumns );
    }
    if ( pv != nullptr )
    {
      pRowset = nullptr;
      if ( m_nColumns > 0 )
      {
        v30 = (CObList **)((char *)pv + 36);
        do
        {
          m_pNodeHead = (*v30)->m_pNodeHead;
          while ( m_pNodeHead != nullptr )
          {
            v18 = m_pNodeHead;
            m_pNodeHead = m_pNodeHead->pNext;
            this->BindProp_2(this, a2: (COleControlSite *)v18->data, a3: 1);
          }
          CObList::RemoveAll(this: *v30);
          if ( *v30 != nullptr )
            ((void (__thiscall *)(CObList *, int))(*v30)->dtr_CObject)(a1: *v30, a2: 1);
          pRowset = (IRowset *)((char *)pRowset + 1);
          v30 += 10;
        }
        while ( (int)pRowset < m_nColumns );
      }
      CoTaskMemFree(pv);
    }
    return v27;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427BAA
// Name: public: virtual long CDataSourceControl::UpdateCursor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CDataSourceControl::UpdateCursor(CDataSourceControl *this)
{
  HRESULT result; // eax
  int v3; // eax
  IBoundObject *i; // eax
  IBoundObject_vtbl *v5; // edi
  ATL::CDynamicAccessor *m_pDynamicAccessor; // ecx
  int v7; // edi
  unsigned __int8 *Value; // eax
  ATL::CDynamicAccessor *v9; // ecx
  char *v10; // edi
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // eax
  ATL::CDynamicAccessor *v13; // ecx
  wchar_t *v14; // eax
  ATL::CDynamicAccessor *v15; // ecx
  ATL::CDynamicAccessor *v16; // ecx
  ATL::CDynamicAccessor *v17; // ecx
  unsigned __int8 *v18; // eax
  ATL::CDynamicAccessor *v19; // edi
  unsigned __int8 *v20; // eax
  int v21; // eax
  __POSITION *m_pNodeHead; // eax
  IBoundObject *v23; // ecx
  int v24; // edi
  int v25; // eax
  tagDBCOLUMNID *v26; // eax
  ICursorUpdateARow *m_pCursorUpdateARow; // ecx
  wchar_t **v28; // eax
  wchar_t *v29; // ecx
  wchar_t *v30; // edi
  int v31; // eax
  int v32; // edi
  int v33; // [esp-Ch] [ebp-90h]
  unsigned int v34; // [esp-4h] [ebp-88h]
  VARIANTARG *v35; // [esp-4h] [ebp-88h]
  tagDBBINDPARAMS bpBindParams; // [esp+10h] [ebp-74h] BYREF
  int v37; // [esp+28h] [ebp-5Ch] BYREF
  int v38; // [esp+2Ch] [ebp-58h]
  int lNumber; // [esp+30h] [ebp-54h]
  void *p; // [esp+34h] [ebp-50h]
  int v41; // [esp+38h] [ebp-4Ch]
  COleVariant *p_vt; // [esp+3Ch] [ebp-48h]
  COleVariant vt; // [esp+40h] [ebp-44h] BYREF
  unsigned int dwEdit; // [esp+50h] [ebp-34h] BYREF
  IBoundObject *pBO; // [esp+54h] [ebp-30h] BYREF
  wchar_t *bstrNewString; // [esp+58h] [ebp-2Ch] BYREF
  int v47; // [esp+5Ch] [ebp-28h] BYREF
  int nVariant; // [esp+60h] [ebp-24h]
  int v49; // [esp+64h] [ebp-20h]
  int nDirtyField; // [esp+68h] [ebp-1Ch]
  int nCol; // [esp+6Ch] [ebp-18h]
  __POSITION *pos; // [esp+70h] [ebp-14h] BYREF
  char data[9]; // [esp+77h] [ebp-Dh] BYREF
  int v54; // [esp+80h] [ebp-4h]

  nVariant = 0;
  nDirtyField = 0;
  if ( this->m_pDataSource == nullptr )
  {
    if ( this->m_pCursorUpdateARow != nullptr
      || this->m_pCursorMove->QueryInterface(
           this: this->m_pCursorMove,
           a2: &IID_ICursorUpdateARow,
           a3: (void **)&this->m_pCursorUpdateARow) >= 0 )
    {
      nCol = 0;
      if ( this->m_nColumns > 0 )
      {
        v49 = 0;
        while ( 1 )
        {
          m_pNodeHead = (__POSITION *)(*(CPtrList **)((char *)&this->m_pMetaRowData->m_pClientList + v49))->m_pNodeHead;
          if ( m_pNodeHead != nullptr )
            break;
LABEL_73:
          ++nCol;
          v49 += 40;
          if ( nCol >= this->m_nColumns )
            goto LABEL_74;
        }
        v47 = 48 * nVariant;
        while ( 1 )
        {
          v23 = *(IBoundObject **)&m_pNodeHead[8];
          m_pNodeHead = *(__POSITION **)m_pNodeHead;
          pos = m_pNodeHead;
          pBO = v23;
          if ( v23[42].__vftable != nullptr )
            break;
LABEL_72:
          ++nVariant;
          v47 += 48;
          if ( m_pNodeHead == nullptr )
            goto LABEL_73;
        }
        ++nDirtyField;
        v23[42].__vftable = nullptr;
        if ( nDirtyField == 1 )
        {
          result = this->m_pCursorUpdateARow->GetEditMode(this: this->m_pCursorUpdateARow, a2: &dwEdit);
          if ( result < 0 )
            return result;
          if ( dwEdit == 1 )
          {
            result = this->m_pCursorUpdateARow->BeginUpdate(this: this->m_pCursorUpdateARow, a2: 1u);
            if ( result < 0 )
              return result;
          }
          this->m_bUpdateInProgress = 1;
        }
        v24 = 16;
        AfxVariantInit(pVar: &vt);
        v25 = LOWORD(pBO[43].__vftable);
        v54 = 2;
        bstrNewString = (wchar_t *)&pBO[43];
        if ( v25 <= 1 )
          goto LABEL_69;
        if ( v25 == 8 )
        {
          if ( pBO[45].QueryInterface == nullptr )
          {
            v24 = -1;
            goto LABEL_71;
          }
        }
        else if ( v25 == 10 )
        {
LABEL_69:
          v24 = -1;
        }
        COleVariant::operator=(this: &vt, varSrc: (const COleVariant *)&pBO[43]);
LABEL_71:
        v26 = (tagDBCOLUMNID *)((char *)&this->m_pColumnBindings->columnID + v47);
        v37 = 0;
        v38 = 1;
        lNumber = v26[1].lNumber;
        v41 = v24;
        p_vt = &vt;
        m_pCursorUpdateARow = this->m_pCursorUpdateARow;
        p = nullptr;
        m_pCursorUpdateARow->SetColumn(this: m_pCursorUpdateARow, a2: v26, a3: (tagDBBINDPARAMS *)&v37);
        VariantClear(pvarg: (VARIANTARG *)bstrNewString);
        v54 = -1;
        VariantClear(pvarg: &vt);
        m_pNodeHead = pos;
        goto LABEL_72;
      }
LABEL_74:
      v28 = (wchar_t **)this->m_CursorBoundProps.m_pNodeHead;
      if ( v28 != nullptr )
      {
        while ( 1 )
        {
          v29 = *v28;
          v30 = v28[2];
          v31 = *(_DWORD *)v30;
          bstrNewString = v29;
          if ( *(_DWORD *)(v31 + 80) != 0
            && (***(int (__stdcall ****)(_DWORD, GUID *, IBoundObject **))(v31 + 80))(
                 a1: *(_DWORD *)(v31 + 80),
                 a2: &IID_IBoundObject,
                 a3: &pBO) >= 0 )
          {
            if ( pBO->IsDirty(this: pBO, a2: *((_DWORD *)v30 + 2)) == 0 && ++nDirtyField == 1 )
            {
              result = this->m_pCursorUpdateARow->GetEditMode(this: this->m_pCursorUpdateARow, a2: (unsigned int *)&v47);
              if ( result < 0 )
                return result;
              if ( v47 == 1 )
              {
                result = this->m_pCursorUpdateARow->BeginUpdate(this: this->m_pCursorUpdateARow, a2: 1u);
                if ( result < 0 )
                  return result;
              }
              this->m_bUpdateInProgress = 1;
            }
            pBO->Release(this: pBO);
          }
          if ( bstrNewString == nullptr )
            break;
          v28 = (wchar_t **)bstrNewString;
        }
      }
      if ( nDirtyField > 0 )
      {
        v32 = this->m_pCursorUpdateARow->Update(this: this->m_pCursorUpdateARow, a2: nullptr, a3: nullptr, a4: nullptr);
        this->m_bUpdateInProgress = 0;
        if ( v32 < 0 )
        {
          this->UpdateControls(this);
          return v32;
        }
      }
    }
    return 0;
  }
  result = 0;
  if ( this->m_pDynamicAccessor != nullptr )
  {
    nCol = 1;
    if ( this->m_nColumns < 1 )
      return 0;
    v49 = 48;
    v47 = 40;
    while ( 1 )
    {
      v3 = *(_DWORD *)((char *)this->m_pMetaRowData + v47 - 4);
      if ( v3 != 0 )
        break;
LABEL_49:
      ++nCol;
      v47 += 40;
      v49 += 48;
      if ( nCol > this->m_nColumns )
      {
        if ( nDirtyField > 0 )
          this->m_bUpdateInProgress = 0;
        return 0;
      }
    }
    for ( i = *(IBoundObject **)(v3 + 4); ; i = pBO )
    {
      while ( 1 )
      {
        if ( i == nullptr )
          goto LABEL_49;
        v5 = i[2].__vftable;
        i = (IBoundObject *)i->__vftable;
        pBO = i;
        if ( v5[8].Release != nullptr )
          break;
LABEL_46:
        ++nVariant;
      }
      ++nDirtyField;
      v5[8].Release = nullptr;
      if ( nDirtyField == 1 )
        this->m_bUpdateInProgress = 1;
      if ( ATL::CDynamicAccessor::GetColumnType(
             this: this->m_pDynamicAccessor,
             nColumn: nCol,
             pType: (unsigned __int16 *)&pos) != 0 )
        break;
    }
    dwEdit = (unsigned int)&v5[8].OnSourceChanged;
    COleVariant::COleVariant(this: &vt, varSrc: (const COleVariant *)&v5[8].OnSourceChanged);
    v54 = 0;
    memset(&bpBindParams, 0, 20);
    v38 = 0;
    p = nullptr;
    p_vt = nullptr;
    m_pDynamicAccessor = this->m_pDynamicAccessor;
    v7 = v49;
    v34 = *(unsigned int *)((char *)&m_pDynamicAccessor->m_pColumnInfo->ulColumnSize + v49);
    LOBYTE(v54) = 1;
    Value = ATL::CDynamicAccessor::GetValue(this: m_pDynamicAccessor, nColumn: nCol);
    ATL::CManualAccessor::CreateAccessor(
      this: (ATL::CManualAccessor *)&bpBindParams,
      nBindEntries: 1u,
      pBuffer: Value,
      nBufferSize: v34);
    v9 = this->m_pDynamicAccessor;
    v10 = (char *)v9->m_pColumnInfo + v7;
    v11 = ATL::CDynamicAccessor::GetValue(this: v9, nColumn: nCol);
    ATL::CManualAccessor::AddBindEntry(
      this: (ATL::CManualAccessor *)&bpBindParams,
      nOrdinal: *((_DWORD *)v10 + 2),
      wType: *((_WORD *)v10 + 10),
      nColumnSize: *((_DWORD *)v10 + 4),
      pData: v11,
      pLength: nullptr,
      pStatus: nullptr);
    ATL::CManualAccessor::BindColumns(
      this: (ATL::CManualAccessor *)&bpBindParams,
      pUnk: (IAccessor *)this->m_pRowset->m_spRowset.p);
    if ( (unsigned __int16)pos > 0x81u )
    {
      if ( (unsigned __int16)pos == 130 )
      {
        COleVariant::ChangeType(this: &vt, vartype: 8u, pSrc: nullptr);
        v19 = this->m_pDynamicAccessor;
        v20 = ATL::CDynamicAccessor::GetValue(this: v19, nColumn: nCol);
        v21 = wcsncpy_s(
                _Dst: (unsigned __int16 *)v20,
                _SizeInWords: *(unsigned int *)((char *)&v19->m_pColumnInfo->ulColumnSize + v49) >> 1,
                _Src: vt.bstrVal,
                _Count: (*(unsigned int *)((char *)&v19->m_pColumnInfo->ulColumnSize + v49) >> 1) - 1);
        ATL::AtlCrtErrorCheck(nError: v21);
      }
      goto LABEL_45;
    }
    if ( (unsigned __int16)pos == 129 )
    {
      COleVariant::ChangeType(this: &vt, vartype: 8u, pSrc: nullptr);
      v17 = this->m_pDynamicAccessor;
      v33 = *(unsigned int *)((char *)&v17->m_pColumnInfo->ulColumnSize + v49);
      v18 = ATL::CDynamicAccessor::GetValue(this: v17, nColumn: nCol);
      WideCharToMultiByte(
        CodePage: 0,
        dwFlags: 0,
        lpWideCharStr: vt.bstrVal,
        cchWideChar: -1,
        lpMultiByteStr: (LPSTR)v18,
        cbMultiByte: v33,
        lpDefaultChar: nullptr,
        lpUsedDefaultChar: nullptr);
      goto LABEL_45;
    }
    if ( (unsigned __int16)pos > 8u )
    {
      if ( (unsigned __int16)pos != 11 )
      {
        switch ( (unsigned __int16)pos )
        {
          case 0xEu:
            COleVariant::ChangeType(this: &vt, vartype: 0xEu, pSrc: nullptr);
            ATL::CDynamicAccessor::SetValue<tagDEC>(
              this: this->m_pDynamicAccessor,
              nColumn: nCol,
              data: (const tagDEC *)&vt);
            break;
          case 0x10u:
            COleVariant::ChangeType(this: &vt, vartype: 0x10u, pSrc: nullptr);
            v16 = this->m_pDynamicAccessor;
            data[0] = vt.cVal;
            ATL::CDynamicAccessor::SetValue<unsigned char>(this: v16, nColumn: nCol, data);
            break;
          case 0x11u:
            COleVariant::ChangeType(this: &vt, vartype: 0x11u, pSrc: nullptr);
            ATL::CDynamicAccessor::SetValue<unsigned char>(
              this: this->m_pDynamicAccessor,
              nColumn: nCol,
              data: &vt.cVal);
            break;
          case 0x12u:
            COleVariant::ChangeType(this: &vt, vartype: 0x12u, pSrc: nullptr);
            ATL::CDynamicAccessor::SetValue<unsigned short>(
              this: this->m_pDynamicAccessor,
              nColumn: nCol,
              data: &vt.uiVal);
            break;
          case 0x13u:
            COleVariant::ChangeType(this: &vt, vartype: 0x13u, pSrc: nullptr);
            ATL::CDynamicAccessor::SetValue<unsigned long>(
              this: this->m_pDynamicAccessor,
              nColumn: nCol,
              data: &vt.decVal.Lo32);
            break;
          default:
            break;
        }
        goto LABEL_45;
      }
      COleVariant::ChangeType(this: &vt, vartype: 0xBu, pSrc: nullptr);
    }
    else
    {
      if ( (unsigned __int16)pos == 8 )
      {
        COleVariant::ChangeType(this: &vt, vartype: 8u, pSrc: nullptr);
        v13 = this->m_pDynamicAccessor;
        bstrNewString = nullptr;
        ATL::CDynamicAccessor::GetValue<wchar_t *>(this: v13, nColumn: nCol, pData: &bstrNewString);
        SysFreeString(bstrString: bstrNewString);
        v14 = SysAllocString(psz: vt.bstrVal);
        v15 = this->m_pDynamicAccessor;
        bstrNewString = v14;
        ATL::CDynamicAccessor::SetValue<unsigned long>(
          this: v15,
          nColumn: nCol,
          data: (const unsigned int *)&bstrNewString);
        goto LABEL_45;
      }
      if ( (unsigned __int16)pos != 2 )
      {
        if ( (unsigned __int16)pos == 3 )
        {
          COleVariant::ChangeType(this: &vt, vartype: 3u, pSrc: nullptr);
          ATL::CDynamicAccessor::SetValue<unsigned long>(
            this: this->m_pDynamicAccessor,
            nColumn: nCol,
            data: &vt.decVal.Lo32);
          goto LABEL_45;
        }
        if ( (unsigned __int16)pos == 4 )
        {
          COleVariant::ChangeType(this: &vt, vartype: 4u, pSrc: nullptr);
          ATL::CDynamicAccessor::SetValue<float>(this: this->m_pDynamicAccessor, nColumn: nCol, data: &vt.fltVal);
          goto LABEL_45;
        }
        if ( (unsigned __int16)pos != 5 )
        {
          if ( (unsigned __int16)pos == 6 )
          {
            COleVariant::ChangeType(this: &vt, vartype: 6u, pSrc: nullptr);
            v12 = ATL::CDynamicAccessor::GetValue(this: this->m_pDynamicAccessor, nColumn: nCol);
            *(_QWORD *)v12 = vt.llVal;
          }
          else if ( (unsigned __int16)pos == 7 )
          {
            COleVariant::ChangeType(this: &vt, vartype: 7u, pSrc: nullptr);
LABEL_24:
            ATL::CDynamicAccessor::SetValue<double>(this: this->m_pDynamicAccessor, nColumn: nCol, data: &vt.dblVal);
          }
LABEL_45:
          this->m_pRowset->m_pAccessor = (ATL::CAccessorBase *)&bpBindParams;
          ATL::CRowset<ATL::CAccessorBase>::SetData(this: this->m_pRowset);
          v35 = (VARIANTARG *)dwEdit;
          this->m_pRowset->m_pAccessor = this->m_pDynamicAccessor;
          VariantClear(pvarg: v35);
          LOBYTE(v54) = 0;
          operator delete(p: (void *)bpBindParams.cbVarDataLen);
          operator delete(p);
          v54 = -1;
          VariantClear(pvarg: &vt);
          i = pBO;
          goto LABEL_46;
        }
        COleVariant::ChangeType(this: &vt, vartype: 5u, pSrc: nullptr);
        goto LABEL_24;
      }
      COleVariant::ChangeType(this: &vt, vartype: 2u, pSrc: nullptr);
    }
    ATL::CDynamicAccessor::SetValue<unsigned short>(this: this->m_pDynamicAccessor, nColumn: nCol, data: &vt.uiVal);
    goto LABEL_45;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004281F4
// Name: public: virtual long COleControlSite::XRowsetNotify::OnRowsetChange(struct IRowset __near *,unsigned long,unsigned long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XRowsetNotify::OnRowsetChange(
        COleControlSite::XRowsetNotify *this,
        IRowset *__formal,
        unsigned int eReason,
        unsigned int a4,
        int a5)
{
  int v5; // esi
  IRowset **v6; // eax
  ATL::CDynamicAccessor *v7; // ebx
  IRowset *v8; // edi
  int v9; // eax
  LPVOID v10; // eax
  unsigned int v12; // [esp-Ch] [ebp-18h]
  void *v13; // [esp-4h] [ebp-10h]
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 51));
  if ( eReason == 14 )
  {
    v5 = *((_DWORD *)this - 22);
    if ( v5 != 0 )
    {
      v6 = *(IRowset ***)(v5 + 80);
      if ( v6 == nullptr || (v7 = *(ATL::CDynamicAccessor **)(v5 + 84)) == nullptr )
        AfxThrowInvalidArgException();
      v8 = *v6;
      ATL::CDynamicAccessor::FreeRecordMemory(this: v7, pRowset: *v6);
      ATL::CAccessorBase::ReleaseAccessors(this: v7, pUnk: v8);
      ATL::CDynamicAccessor::Close(this: *(ATL::CDynamicAccessor **)(v5 + 84));
      ATL::CDynamicAccessor::BindColumns(this: *(ATL::CDynamicAccessor **)(v5 + 84), pUnk: **(IUnknown ***)(v5 + 80));
      v9 = *(_DWORD *)(*(_DWORD *)(v5 + 84) + 12);
      if ( *(_DWORD *)(v5 + 16) != v9 )
      {
        v13 = *(void **)(v5 + 20);
        *(_DWORD *)(v5 + 16) = v9;
        CoTaskMemFree(pv: v13);
        v10 = ATL::AtlCoTaskMemCAlloc(nCount: 0x28u, nSize: *(_DWORD *)(v5 + 16));
        v12 = 40 * *(_DWORD *)(v5 + 16);
        *(_DWORD *)(v5 + 20) = v10;
        memset(dst: (int)v10, value: nullptr, count: v12);
      }
    }
  }
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042829D
// Name: public: void ATL::CRowset<class ATL::CAccessorBase>::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CRowset<ATL::CAccessorBase>::Close(ATL::CRowset<ATL::CAccessorBase> *this)
{
  ATL::CXMLAccessor *m_pXMLAccessor; // ebx
  IRowset *p; // edi
  ATL::CXMLAccessor *v4; // edi
  IRowset *v5; // eax
  IRowsetChange *v6; // eax

  m_pXMLAccessor = this->m_pXMLAccessor;
  if ( m_pXMLAccessor != nullptr )
  {
    p = this->m_spRowset.p;
    if ( this->m_spRowset.p != nullptr )
    {
      ATL::CDynamicAccessor::FreeRecordMemory(this: m_pXMLAccessor, pRowset: this->m_spRowset.p);
      ATL::CAccessorBase::ReleaseAccessors(this: m_pXMLAccessor, pUnk: p);
    }
    v4 = this->m_pXMLAccessor;
    if ( v4 != nullptr )
    {
      ATL::CDynamicAccessor::Close(this: this->m_pXMLAccessor);
      operator delete(p: v4);
    }
    this->m_pXMLAccessor = nullptr;
  }
  if ( this->m_spRowset.p != nullptr )
  {
    ATL::CRowset<ATL::CAccessorBase>::ReleaseRows(this);
    v5 = this->m_spRowset.p;
    if ( this->m_spRowset.p != nullptr )
    {
      this->m_spRowset.p = nullptr;
      v5->Release(this: v5);
    }
    v6 = this->m_spRowsetChange.p;
    if ( v6 != nullptr )
    {
      this->m_spRowsetChange.p = nullptr;
      v6->Release(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042830A
// Name: public: long CDataSourceControl::Initialize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CDataSourceControl::Initialize(CDataSourceControl *this)
{
  COleControlSite *m_pClientSite; // eax
  CWnd *m_pWndCtrl; // eax
  CWnd *TopLevelParent; // eax
  CWnd *v5; // ebx
  BOOL v6; // eax
  HWND DesktopWindow; // eax
  CWnd *v8; // eax
  HRESULT result; // eax
  HRESULT MetaData; // esi
  BOOL bHidden; // [esp+Ch] [ebp-38h]
  IVBDSC *pDSC; // [esp+10h] [ebp-34h] BYREF
  ICursor *pCursor; // [esp+14h] [ebp-30h] BYREF
  CWnd *v14; // [esp+18h] [ebp-2Ch]
  HRESULT hRes; // [esp+1Ch] [ebp-28h]
  CRect rcDesktop; // [esp+20h] [ebp-24h] BYREF
  CRect rcParent; // [esp+30h] [ebp-14h] BYREF

  m_pClientSite = this->m_pClientSite;
  if ( m_pClientSite == nullptr
    || (m_pWndCtrl = m_pClientSite->m_pWndCtrl) == nullptr
    || (TopLevelParent = CWnd::GetTopLevelParent(this: m_pWndCtrl),
        v5 = TopLevelParent,
        v14 = TopLevelParent,
        TopLevelParent == nullptr) )
  {
    AfxThrowInvalidArgException();
  }
  v6 = IsWindowVisible(hWnd: TopLevelParent->m_hWnd);
  bHidden = !v6;
  memset(&rcParent, 0, sizeof(rcParent));
  if ( !v6 )
  {
    memset(&rcDesktop, 0, sizeof(rcDesktop));
    DesktopWindow = GetDesktopWindow();
    v8 = CWnd::FromHandle(hWnd: DesktopWindow);
    GetWindowRect(hWnd: v8->m_hWnd, lpRect: &rcDesktop);
    GetWindowRect(hWnd: v5->m_hWnd, lpRect: &rcParent);
    CWnd::MoveWindow(
      this: v5,
      x: (rcDesktop.right - rcDesktop.left) / 2,
      y: (rcDesktop.bottom - rcDesktop.top) / 2,
      nWidth: 0,
      nHeight: 0,
      bRepaint: false);
    CWnd::ShowWindow(this: v5, nCmdShow: 1);
  }
  if ( this->m_pClientSite->m_pObject->QueryInterface(
         this: this->m_pClientSite->m_pObject,
         a2: &IID_IDataSource,
         a3: (void **)&this->m_pDataSource) >= 0 )
  {
    hRes = this->m_pDataSource->GetDataMember(
             this: this->m_pDataSource,
             a2: nullptr,
             a3: &IID_IRowPosition,
             a4: &this->m_pRowPosition);
    if ( this->m_pRowPosition == nullptr )
      hRes = -2147467261;
    if ( hRes < 0 )
    {
      if ( bHidden )
      {
        CWnd::MoveWindow(
          this: v14,
          x: rcParent.left,
          y: rcParent.top,
          nWidth: rcParent.right - rcParent.left,
          nHeight: rcParent.bottom - rcParent.top,
          bRepaint: false);
        CWnd::ShowWindow(this: v14, nCmdShow: 0);
      }
      return hRes;
    }
    goto LABEL_19;
  }
  result = this->m_pClientSite->m_pObject->QueryInterface(
             this: this->m_pClientSite->m_pObject,
             a2: &IID_IVBDSC,
             a3: (void **)&pDSC);
  if ( result < 0 )
    return result;
  pDSC->CreateCursor(this: pDSC, a2: &pCursor);
  pDSC->Release(this: pDSC);
  if ( pCursor == nullptr )
    return -2147467259;
  hRes = pCursor->QueryInterface(this: pCursor, a2: &IID_ICursorMove, a3: (void **)&this->m_pCursorMove);
  pCursor->Release(this: pCursor);
  result = hRes;
  if ( hRes >= 0 )
  {
    this->m_pCursorMove->QueryInterface(
      this: this->m_pCursorMove,
      a2: &IID_ICursorUpdateARow,
      a3: (void **)&this->m_pCursorUpdateARow);
LABEL_19:
    MetaData = CDataSourceControl::GetMetaData(this);
    if ( bHidden )
    {
      CWnd::MoveWindow(
        this: v14,
        x: rcParent.left,
        y: rcParent.top,
        nWidth: rcParent.right - rcParent.left,
        nHeight: rcParent.bottom - rcParent.top,
        bRepaint: false);
      CWnd::ShowWindow(this: v14, nCmdShow: 0);
    }
    return MetaData;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004284EC
// Name: public: ATL::CRowset<class ATL::CAccessorBase>::~CRowset<class ATL::CAccessorBase>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CRowset<ATL::CAccessorBase>::~CRowset<ATL::CAccessorBase>(ATL::CRowset<ATL::CAccessorBase> *this)
{
  IRowsetChange *p; // eax
  IRowset *v3; // esi

  ATL::CRowset<ATL::CAccessorBase>::Close(this);
  p = this->m_spRowsetChange.p;
  if ( p != nullptr )
    p->Release(this: this->m_spRowsetChange.p);
  v3 = this->m_spRowset.p;
  if ( v3 != nullptr )
    v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00428511
// Name: public: COleControlSite::COleControlSite(class COleControlContainer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleControlSite *__thiscall COleControlSite::COleControlSite(COleControlSite *this, COleControlContainer *pCtrlCont)
{
  CAfxStringMgr *StringManager; // eax

  CCmdTarget::CCmdTarget(this);
  this->m_nID = -1;
  this->__vftable = (COleControlSite_vtbl *)&COleControlSite::`vftable';
  this->m_pCtrlCont = pCtrlCont;
  this->m_pWndCtrl = nullptr;
  this->m_rect.left = 0;
  this->m_rect.top = 0;
  this->m_rect.right = 0;
  this->m_rect.bottom = 0;
  this->m_pObject = nullptr;
  this->m_pInPlaceObject = nullptr;
  this->m_pActiveObject = nullptr;
  this->m_pWindowlessObject = nullptr;
  this->m_dwEventSink = 0;
  this->m_dwPropNotifySink = 0;
  this->m_dwMiscStatus = 0;
  this->m_bIsWindowless = 0;
  this->m_bIgnoreNotify = 0;
  this->m_dwNotifyDBEvents = 0;
  this->m_pDataSourceControl = nullptr;
  this->m_pBindings = nullptr;
  this->m_pDSCSite = nullptr;
  this->m_defdispid = 0;
  this->m_dwType = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDataField, pStringMgr: StringManager);
  this->m_bIsDirty = 0;
  COleDispatchDriver::COleDispatchDriver(this: &this->m_dispDriver);
  this->m_pDC = nullptr;
  this->m_xOleClientSite.__vftable = (COleControlSite::XOleClientSite_vtbl *)&COleControlSite::XOleClientSite::`vftable';
  this->m_xOleIPSite.__vftable = (COleControlSite::XOleIPSite_vtbl *)&COleControlSite::XOleIPSite::`vftable';
  this->m_xOleControlSite.__vftable = (COleControlSite::XOleControlSite_vtbl *)&COleControlSite::XOleControlSite::`vftable';
  this->m_xAmbientProps.__vftable = (COleControlSite::XAmbientProps_vtbl *)&COleControlSite::XAmbientProps::`vftable';
  this->m_xPropertyNotifySink.__vftable = (COleControlSite::XPropertyNotifySink_vtbl *)&COleControlSite::XPropertyNotifySink::`vftable';
  this->m_xEventSink.__vftable = (COleControlSite::XEventSink_vtbl *)&COleControlSite::XEventSink::`vftable';
  this->m_xBoundObjectSite.__vftable = (COleControlSite::XBoundObjectSite_vtbl *)&COleControlSite::XBoundObjectSite::`vftable';
  this->m_xNotifyDBEvents.__vftable = (COleControlSite::XNotifyDBEvents_vtbl *)&COleControlSite::XNotifyDBEvents::`vftable';
  this->m_xRowsetNotify.__vftable = (COleControlSite::XRowsetNotify_vtbl *)&COleControlSite::XRowsetNotify::`vftable';
  memset(dst: (int)&this->m_varResult, value: nullptr, count: sizeof(this->m_varResult));
  this->m_varResult.vt = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428634
// Name: public: virtual void COleControlSite::EnableDSC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleControlSite::EnableDSC(COleControlSite *this)
{
  CDataSourceControl *v2; // ecx
  CDataSourceControl *v3; // eax

  if ( this->m_pDataSourceControl == nullptr )
  {
    v2 = (CDataSourceControl *)operator new(nSize: 0x5Cu);
    if ( v2 != nullptr )
      v3 = CDataSourceControl::CDataSourceControl(this: v2, pClientSite: this);
    else
      v3 = nullptr;
    this->m_pDataSourceControl = v3;
    CDataSourceControl::Initialize(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428681
// Name: public: virtual long COleControlSite::XOleIPSite::GetDC(struct tagRECT const __near *,unsigned long,struct HDC__ __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::GetDC(
        COleControlSite::XOleIPSite *this,
        const tagRECT *prect,
        unsigned int __formal,
        HDC__ **phDC)
{
  HDC__ **v4; // edi
  HDC__ *v5; // esi
  HDC DC; // eax
  CDC *v8; // eax
  HRGN v9; // eax
  int v10; // ebx
  AFX_MODULE_STATE *v11; // [esp-4h] [ebp-3Ch]
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+10h] [ebp-28h] BYREF
  const RECT *lprcSrc2; // [esp+18h] [ebp-20h]
  CRgn rgn; // [esp+1Ch] [ebp-1Ch] BYREF
  CRect rect; // [esp+24h] [ebp-14h] BYREF

  v4 = phDC;
  v11 = *((AFX_MODULE_STATE **)this - 44);
  v5 = nullptr;
  lprcSrc2 = prect;
  rgn.m_hObject = nullptr;
  rgn.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
  memset(&rect, 0, sizeof(rect));
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: v11);
  if ( phDC == nullptr )
    AfxThrowInvalidArgException();
  *phDC = nullptr;
  if ( *((_DWORD *)this - 2) != 0
    || (DC = GetDC(hWnd: *(HWND *)(*(_DWORD *)(*((_DWORD *)this - 43) + 32) + 32)),
        v8 = CDC::FromHandle(hDC: DC),
        *((_DWORD *)this - 2) = v8,
        v8 == nullptr) )
  {
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    rgn.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
    CGdiObject::~CGdiObject(this: &rgn);
    return -2147467259;
  }
  else
  {
    if ( lprcSrc2 != nullptr )
    {
      IntersectRect(lprcDst: &rect, lprcSrc1: (const RECT *)(this - 39), lprcSrc2);
    }
    else
    {
      rect.left = (int)*(this - 39);
      rect.top = (int)*(this - 38);
      rect.right = (int)*(this - 37);
      rect.bottom = (int)*(this - 36);
      v4 = phDC;
      v5 = nullptr;
    }
    v9 = CreateRectRgnIndirect(lprect: &rect);
    CGdiObject::Attach(this: &rgn, hObject: v9);
    CDC::SelectClipRgn(this: *((CDC **)this - 2), pRgn: &rgn, nMode: 1);
    v10 = *((_DWORD *)this - 2);
    if ( v10 != 0 )
      v5 = *(HDC__ **)(v10 + 4);
    *v4 = v5;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    rgn.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
    CGdiObject::~CGdiObject(this: &rgn);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042879F
// Name: public: virtual long COleControlSite::XOleIPSite::InvalidateRgn(struct HRGN__ __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall COleControlSite::XOleIPSite::InvalidateRgn(
        COleControlSite::XOleIPSite *this,
        HRGN__ *hRgn,
        BOOL bErase)
{
  HRESULT v3; // edi
  CGdiObject *v5; // ebx
  BOOL v6; // eax
  AFX_MODULE_STATE *v7; // [esp-4h] [ebp-44h]
  int v8; // [esp-4h] [ebp-44h]
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+Ch] [ebp-34h] BYREF
  CRgn rgn; // [esp+14h] [ebp-2Ch] BYREF
  CRect rect; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectRgn; // [esp+2Ch] [ebp-14h] BYREF

  v7 = *((AFX_MODULE_STATE **)this - 44);
  v3 = 0;
  rgn.m_hObject = nullptr;
  rgn.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
  memset(&rectRgn, 0, sizeof(rectRgn));
  memset(&rect, 0, sizeof(rect));
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: v7);
  if ( hRgn != nullptr )
  {
    v5 = CGdiObject::FromHandle(h: hRgn);
    GetRgnBox(hrgn: (HRGN)v5->m_hObject, lprc: &rectRgn);
    IntersectRect(lprcDst: &rect, lprcSrc1: &rectRgn, lprcSrc2: (const RECT *)(this - 39));
    v6 = EqualRect(lprc1: &rect, lprc2: &rectRgn);
    v8 = bErase;
    if ( v6 )
    {
      CWnd::InvalidateRgn(this: *(CWnd **)(*((_DWORD *)this - 43) + 32), pRgn: (CRgn *)v5, bErase);
      goto LABEL_4;
    }
  }
  else
  {
    v8 = bErase;
  }
  v3 = this->InvalidateRect(this, a2: nullptr, a3: v8);
LABEL_4:
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  rgn.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &rgn);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00428876
// Name: public: virtual void COleControlSite::BindDefaultProperty(long,unsigned short,char const __near *,class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleControlSite::BindDefaultProperty(
        COleControlSite *this,
        int dwDispID,
        unsigned __int16 vtProp,
        const char *szFieldName,
        CWnd *pDSCWnd)
{
  COleControlSite *m_pDSCSite; // eax
  COleControlSite *v7; // esi

  m_pDSCSite = this->m_pDSCSite;
  if ( m_pDSCSite != nullptr )
  {
    m_pDSCSite->m_pDataSourceControl->BindProp_2(this: m_pDSCSite->m_pDataSourceControl, a2: this, a3: 0);
    this->m_pDSCSite->m_pDataSourceControl->BindColumns(this: this->m_pDSCSite->m_pDataSourceControl);
    this->m_pDSCSite = nullptr;
  }
  if ( pDSCWnd != nullptr )
  {
    pDSCWnd->m_pCtrlSite->EnableDSC(this: pDSCWnd->m_pCtrlSite);
    this->m_pDSCSite = pDSCWnd->m_pCtrlSite;
    this->m_defdispid = dwDispID;
    this->m_dwType = vtProp;
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strDataField, pszSrc: szFieldName);
    this->m_pDSCSite->m_pDataSourceControl->BindProp_2(this: this->m_pDSCSite->m_pDataSourceControl, a2: this, a3: 1);
    v7 = this->m_pDSCSite;
    if ( v7 != nullptr )
      v7->m_pDataSourceControl->BindColumns(this: v7->m_pDataSourceControl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042891A
// Name: public: CDataSourceControl::~CDataSourceControl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDataSourceControl::~CDataSourceControl(CDataSourceControl *this)
{
  ATL::CRowset<ATL::CAccessorBase> *m_pRowset; // eax
  _DWORD *data; // edi
  int v4; // edi
  bool v5; // zf
  ICursorMove *m_pCursorMove; // eax
  ICursorUpdateARow *m_pCursorUpdateARow; // eax
  int v8; // edi
  CPtrList::CNode *m_pNodeHead; // eax
  CPtrList::CNode *v10; // ecx
  CPtrList *m_pClientList; // ecx
  ATL::CDynamicAccessor *m_pDynamicAccessor; // ebx
  IRowset *p; // edi
  ATL::CDynamicAccessor *v14; // edi
  ATL::CRowset<ATL::CAccessorBase> *v15; // edi
  IRowPosition *m_pRowPosition; // eax
  IDataSource *m_pDataSource; // esi
  CPtrList *p_m_CursorBoundProps; // [esp+14h] [ebp-1Ch]
  IConnectionPointContainer *pConnPtCont; // [esp+18h] [ebp-18h] BYREF
  int nCol; // [esp+1Ch] [ebp-14h]
  IConnectionPoint *pConnPt; // [esp+20h] [ebp-10h] BYREF
  int v22; // [esp+2Ch] [ebp-4h]

  this->__vftable = (CDataSourceControl_vtbl *)&CDataSourceControl::`vftable';
  v22 = 0;
  if ( this->m_dwRowsetNotify != 0 )
  {
    m_pRowset = this->m_pRowset;
    if ( m_pRowset != nullptr
      && m_pRowset->m_spRowset.p->QueryInterface(
           this: m_pRowset->m_spRowset.p,
           a2: &IID_IConnectionPointContainer,
           a3: (void **)&pConnPtCont) >= 0
      && pConnPtCont != nullptr )
    {
      pConnPt = nullptr;
      if ( pConnPtCont->FindConnectionPoint(this: pConnPtCont, a2: &IID_IRowsetNotify, a3: &pConnPt) >= 0
        && pConnPt != nullptr )
      {
        pConnPt->Unadvise(this: pConnPt, a2: this->m_dwRowsetNotify);
        pConnPt->Release(this: pConnPt);
      }
      pConnPtCont->Release(this: pConnPtCont);
    }
  }
  while ( this->m_CursorBoundProps.m_nCount != 0 )
  {
    data = this->m_CursorBoundProps.m_pNodeHead->data;
    if ( data == nullptr || *data == 0 )
      break;
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)*data + 188))(a1: *data, a2: data[2], a3: 0);
    *(_DWORD *)(*data + 152) = 0;
  }
  p_m_CursorBoundProps = &this->m_CursorBoundProps;
  CObList::RemoveAll(this: (CObList *)&this->m_CursorBoundProps);
  if ( this->m_pValues != nullptr )
  {
    v4 = 0;
    v5 = this->m_nBindings == 0;
    if ( this->m_nBindings > 0 )
    {
      nCol = 0;
      do
      {
        VariantClear(pvarg: (VARIANTARG *)((char *)this->m_pValues + nCol));
        nCol += 16;
        ++v4;
      }
      while ( v4 < this->m_nBindings );
      v5 = this->m_nBindings == 0;
    }
    if ( !v5 )
    {
      operator delete(p: this->m_pColumnBindings);
      operator delete(p: this->m_pValues);
    }
  }
  m_pCursorMove = this->m_pCursorMove;
  if ( m_pCursorMove != nullptr )
    m_pCursorMove->Release(this: this->m_pCursorMove);
  m_pCursorUpdateARow = this->m_pCursorUpdateARow;
  if ( m_pCursorUpdateARow != nullptr )
    m_pCursorUpdateARow->Release(this: this->m_pCursorUpdateARow);
  if ( this->m_pMetaRowData != nullptr )
  {
    nCol = 0;
    if ( this->m_nColumns > 0 )
    {
      v8 = 0;
      do
      {
        m_pNodeHead = this->m_pMetaRowData[v8].m_pClientList->m_pNodeHead;
        while ( m_pNodeHead != nullptr )
        {
          v10 = m_pNodeHead;
          m_pNodeHead = m_pNodeHead->pNext;
          *((_DWORD *)v10->data + 38) = 0;
        }
        CObList::RemoveAll(this: (CObList *)this->m_pMetaRowData[v8].m_pClientList);
        m_pClientList = this->m_pMetaRowData[v8].m_pClientList;
        if ( m_pClientList != nullptr )
          ((void (__thiscall *)(CPtrList *, int))m_pClientList->dtr_CObject)(a1: m_pClientList, a2: 1);
        ++nCol;
        ++v8;
      }
      while ( nCol < this->m_nColumns );
    }
    CoTaskMemFree(pv: this->m_pMetaRowData);
  }
  if ( this->m_pVarData != nullptr )
    CoTaskMemFree(pv: this->m_pVarData);
  m_pDynamicAccessor = this->m_pDynamicAccessor;
  if ( m_pDynamicAccessor != nullptr )
  {
    p = this->m_pRowset->m_spRowset.p;
    ATL::CDynamicAccessor::FreeRecordMemory(this: m_pDynamicAccessor, pRowset: p);
    ATL::CAccessorBase::ReleaseAccessors(this: m_pDynamicAccessor, pUnk: p);
    ATL::CDynamicAccessor::Close(this: this->m_pDynamicAccessor);
  }
  v14 = this->m_pDynamicAccessor;
  if ( v14 != nullptr )
  {
    ATL::CDynamicAccessor::Close(this: this->m_pDynamicAccessor);
    operator delete(p: v14);
  }
  v15 = this->m_pRowset;
  if ( v15 != nullptr )
  {
    ATL::CRowset<ATL::CAccessorBase>::~CRowset<ATL::CAccessorBase>(this: this->m_pRowset);
    operator delete(p: v15);
  }
  m_pRowPosition = this->m_pRowPosition;
  if ( m_pRowPosition != nullptr )
    m_pRowPosition->Release(this: this->m_pRowPosition);
  m_pDataSource = this->m_pDataSource;
  if ( m_pDataSource != nullptr )
    m_pDataSource->Release(this: m_pDataSource);
  v22 = -1;
  CPtrList::~CPtrList(this: p_m_CursorBoundProps);
}

//------------------------------------------------------------------------------
// Address: 0x00428B1D
// Name: public: virtual void CDataSourceControl::BindProp(class COleControlSite __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDataSourceControl::BindProp(CDataSourceControl *this, COleControlSite *pClientSite, int bBind)
{
  CDataSourceControl_vtbl *v4; // eax
  int v5; // edi
  ATL::CDynamicAccessor *m_pDynamicAccessor; // ecx
  const wchar_t *ColumnName; // eax
  int v8; // eax
  char v9; // bl
  const char **v10; // eax
  int v11; // eax
  char v12; // bl
  int v13; // ecx
  CDataSourceControl::METAROWTYPE *m_pMetaRowData; // esi
  CPtrList **i; // edi
  __POSITION *m_pNodeHead; // eax
  __POSITION *v17; // ebx
  COleControlSite *v18; // edx
  char *m_pszData; // [esp-4h] [ebp-28h]
  char *v20; // [esp-4h] [ebp-28h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v21; // [esp+10h] [ebp-14h] BYREF
  int v22; // [esp+14h] [ebp-10h]
  int v23; // [esp+20h] [ebp-4h]

  v4 = this->__vftable;
  if ( bBind != 0 )
  {
    ((void (__stdcall *)(COleControlSite *, _DWORD))v4->BindProp_2)(a1: pClientSite, a2: 0);
    v5 = 0;
    if ( this->m_pDataSource != nullptr )
    {
      if ( this->m_nColumns > 0 )
      {
        while ( 1 )
        {
          m_pDynamicAccessor = this->m_pDynamicAccessor;
          v22 = v5 + 1;
          ColumnName = ATL::CDynamicAccessor::GetColumnName(this: m_pDynamicAccessor, nColumn: v5 + 1);
          m_pszData = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&bBind,
                        pszSrc: ColumnName)->m_pszData;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
            this: &pClientSite->m_strDataField,
            psz: m_pszData);
          v9 = -(v8 != 0);
          v23 = -1;
          ATL::CStringData::Release(this: (ATL::CStringData *)(bBind - 16));
          if ( v9 != -1 )
            break;
          v5 = v22;
          if ( v22 >= this->m_nColumns )
            goto LABEL_13;
        }
LABEL_7:
        CPtrList::AddTail(this: (CObList *)this->m_pMetaRowData[v5].m_pClientList, newElement: pClientSite);
        return;
      }
    }
    else if ( this->m_nColumns > 0 )
    {
      bBind = 0;
      do
      {
        v10 = (const char **)((char *)&this->m_pMetaRowData->lpstrName + bBind);
        if ( *v10 != nullptr )
        {
          v20 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                  this: &v21,
                  pszSrc: *v10)->m_pszData;
          v23 = 1;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
            this: &pClientSite->m_strDataField,
            psz: v20);
          v12 = -(v11 != 0);
          v23 = -1;
          ATL::CStringData::Release(this: (ATL::CStringData *)v21.m_pszData - 1);
          if ( v12 != -1 )
            goto LABEL_7;
        }
        bBind += 40;
      }
      while ( ++v5 < this->m_nColumns );
    }
LABEL_13:
    pClientSite->m_pDSCSite = nullptr;
  }
  else
  {
    ((void (*)(void))v4->UpdateCursor)();
    v13 = 0;
    bBind = this->m_nColumns;
    if ( bBind > 0 )
    {
      m_pMetaRowData = this->m_pMetaRowData;
      for ( i = &m_pMetaRowData->m_pClientList; ; i += 10 )
      {
        m_pNodeHead = (__POSITION *)(*i)->m_pNodeHead;
        if ( m_pNodeHead != nullptr )
          break;
LABEL_19:
        if ( ++v13 >= bBind )
          return;
      }
      while ( 1 )
      {
        v17 = m_pNodeHead;
        v18 = *(COleControlSite **)&m_pNodeHead[8];
        m_pNodeHead = *(__POSITION **)m_pNodeHead;
        if ( v18 == pClientSite )
          break;
        if ( m_pNodeHead == nullptr )
          goto LABEL_19;
      }
      CPtrList::RemoveAt(this: (CObList *)m_pMetaRowData[v13].m_pClientList, position: v17);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428C7C
// Name: public: class COleVariant CDataSourceControl::ToVariant(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleVariant *__thiscall CDataSourceControl::ToVariant(CDataSourceControl *this, COleVariant *result, float nCol)
{
  ATL::CDynamicAccessor *m_pDynamicAccessor; // ecx
  ATL::CDynamicAccessor *v5; // edi
  COleVariant *p_varSrc; // eax
  unsigned __int8 *v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned __int8 *v10; // eax
  COleVariant *v11; // eax
  __int16 *v12; // eax
  const COleVariant *v13; // eax
  unsigned __int8 v14; // al
  const COleVariant *v15; // eax
  const COleVariant *v16; // eax
  __int16 *v17; // eax
  const COleVariant *v18; // eax
  unsigned __int8 *Value; // eax
  const COleVariant *v20; // eax
  unsigned int v21; // ecx
  long double v22; // st7
  bool v23; // zf
  unsigned __int8 *v24; // eax
  const COleVariant *v25; // eax
  char *m_pszData; // [esp-8h] [ebp-150h]
  char *v28; // [esp-8h] [ebp-150h]
  COleVariant v29; // [esp+10h] [ebp-138h] BYREF
  COleVariant v30; // [esp+20h] [ebp-128h] BYREF
  COleVariant v31; // [esp+30h] [ebp-118h] BYREF
  COleVariant v32; // [esp+40h] [ebp-108h] BYREF
  COleVariant v33; // [esp+50h] [ebp-F8h] BYREF
  COleVariant v34; // [esp+60h] [ebp-E8h] BYREF
  ATL::COleDateTime v35; // [esp+70h] [ebp-D8h] BYREF
  COleVariant varSrc; // [esp+7Ch] [ebp-CCh] BYREF
  COleVariant v37; // [esp+8Ch] [ebp-BCh] BYREF
  COleVariant v38; // [esp+9Ch] [ebp-ACh] BYREF
  COleVariant v39; // [esp+ACh] [ebp-9Ch] BYREF
  COleVariant v40; // [esp+BCh] [ebp-8Ch] BYREF
  COleVariant v41; // [esp+CCh] [ebp-7Ch] BYREF
  COleVariant v42; // [esp+DCh] [ebp-6Ch] BYREF
  COleVariant v43; // [esp+ECh] [ebp-5Ch] BYREF
  COleVariant v44; // [esp+FCh] [ebp-4Ch] BYREF
  tagDBTIMESTAMP dbTimeStamp; // [esp+10Ch] [ebp-3Ch] BYREF
  tagDBTIME dbTime; // [esp+120h] [ebp-28h] BYREF
  COleVariant vt; // [esp+128h] [ebp-20h] BYREF
  unsigned int dbStatus; // [esp+138h] [ebp-10h] BYREF
  int v49; // [esp+144h] [ebp-4h]

  dbStatus = 0;
  if ( this->m_pDataSource == nullptr || this->m_pDynamicAccessor == nullptr )
    AfxThrowInvalidArgException();
  AfxVariantInit(pVar: &vt);
  m_pDynamicAccessor = this->m_pDynamicAccessor;
  v49 = 0;
  dbStatus = 3;
  ATL::CDynamicAccessor::GetStatus(this: m_pDynamicAccessor, nColumn: LODWORD(nCol), pStatus: &dbStatus);
  if ( dbStatus != 3 )
  {
    v5 = this->m_pDynamicAccessor;
    if ( ATL::CDynamicAccessor::GetColumnType(this: v5, nColumn: LODWORD(nCol), pType: (unsigned __int16 *)&dbStatus) != 0 )
    {
      if ( (unsigned __int16)dbStatus > 0x81u )
      {
        if ( (unsigned __int16)dbStatus != 130 )
        {
          switch ( (unsigned __int16)dbStatus )
          {
            case 0x83u:
              if ( ATL::CDynamicAccessor::GetValue<tagDB_NUMERIC>(
                     this: v5,
                     nColumn: LODWORD(nCol),
                     pData: (tagDB_NUMERIC *)&dbTimeStamp) == 0 )
                goto LABEL_53;
              v22 = (double)*(__int64 *)((char *)&dbTimeStamp.month + 1);
              if ( HIBYTE(dbTimeStamp.year) != 0 )
              {
                do
                {
                  v23 = HIBYTE(dbTimeStamp.year)-- == 1;
                  v22 = v22 / 10.0;
                }
                while ( !v23 );
              }
              if ( LOBYTE(dbTimeStamp.month) == 0 )
                v22 = -v22;
              v41.dblVal = v22;
              v41.vt = 5;
              LOBYTE(v49) = 14;
              COleVariant::operator=(this: &vt, varSrc: &v41);
              p_varSrc = &v41;
              break;
            case 0x85u:
              if ( ATL::CDynamicAccessor::GetValue<tagDBTIME>(this: v5, nColumn: LODWORD(nCol), pData: &dbTime) == 0 )
                goto LABEL_53;
              *(double *)&dbTimeStamp.day = 0.0;
              dbTimeStamp.fraction = 0;
              ATL::COleDateTime::SetDateTime(
                this: (ATL::COleDateTime *)&dbTimeStamp.day,
                nYear: dbTime.hour,
                nMonth: dbTime.minute,
                nDay: dbTime.second,
                nHour: 0,
                nMin: 0,
                nSec: 0);
              v42.dblVal = *(double *)&dbTimeStamp.day;
              v42.vt = 7;
              LOBYTE(v49) = 15;
              COleVariant::operator=(this: &vt, varSrc: &v42);
              p_varSrc = &v42;
              break;
            case 0x86u:
              if ( ATL::CDynamicAccessor::GetValue<tagDBTIME>(this: v5, nColumn: LODWORD(nCol), pData: &dbTime) == 0 )
                goto LABEL_53;
              *(double *)&dbTimeStamp.day = 0.0;
              dbTimeStamp.fraction = 0;
              ATL::COleDateTime::SetDateTime(
                this: (ATL::COleDateTime *)&dbTimeStamp.day,
                nYear: 0x76Bu,
                nMonth: 0xCu,
                nDay: 0x1Eu,
                nHour: dbTime.hour,
                nMin: dbTime.minute,
                nSec: dbTime.second);
              v39.dblVal = *(double *)&dbTimeStamp.day;
              v39.vt = 7;
              LOBYTE(v49) = 16;
              COleVariant::operator=(this: &vt, varSrc: &v39);
              p_varSrc = &v39;
              break;
            default:
              if ( (unsigned __int16)dbStatus != 135
                || ATL::CDynamicAccessor::GetValue<tagDBTIMESTAMP>(
                     this: v5,
                     nColumn: LODWORD(nCol),
                     pData: &dbTimeStamp) == 0 )
              {
                goto LABEL_53;
              }
              ATL::COleDateTime::SetDateTime(
                this: &v35,
                nYear: dbTimeStamp.year,
                nMonth: dbTimeStamp.month,
                nDay: dbTimeStamp.day,
                nHour: dbTimeStamp.hour,
                nMin: dbTimeStamp.minute,
                nSec: dbTimeStamp.second);
              v38.dblVal = v35.m_dt;
              v38.vt = 7;
              LOBYTE(v49) = 17;
              COleVariant::operator=(this: &vt, varSrc: &v38);
              p_varSrc = &v38;
              break;
          }
          goto LABEL_31;
        }
      }
      else
      {
        if ( (unsigned __int16)dbStatus == 129 )
        {
          Value = ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
          m_pszData = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
                        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nCol,
                        pszSrc: (const char *)Value)->m_pszData;
          LOBYTE(v49) = 2;
          v20 = COleVariant::COleVariant(this: &v31, lpszSrc: m_pszData, vtSrc: 8u);
          LOBYTE(v49) = 3;
          COleVariant::operator=(this: &vt, varSrc: v20);
          VariantClear(pvarg: &v31);
          v21 = LODWORD(nCol);
LABEL_52:
          LOBYTE(v49) = 0;
          ATL::CStringData::Release(this: (ATL::CStringData *)(v21 - 16));
          goto LABEL_53;
        }
        if ( (unsigned __int16)dbStatus > 8u )
        {
          if ( (unsigned __int16)dbStatus == 11 )
          {
            v17 = (__int16 *)ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
            v18 = COleVariant::COleVariant(this: &v33, nSrc: *v17, vtSrc: 0xBu);
            LOBYTE(v49) = 11;
            COleVariant::operator=(this: &vt, varSrc: v18);
            p_varSrc = &v33;
            goto LABEL_31;
          }
          if ( (unsigned __int16)dbStatus == 12 )
          {
            v15 = (const COleVariant *)ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
            v16 = COleVariant::COleVariant(this: &v30, varSrc: v15);
            LOBYTE(v49) = 1;
            COleVariant::operator=(this: &vt, varSrc: v16);
            p_varSrc = &v30;
            goto LABEL_31;
          }
          if ( (unsigned __int16)dbStatus <= 0xFu )
            goto LABEL_53;
          if ( (unsigned __int16)dbStatus <= 0x11u )
          {
            v14 = *ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
            v43.vt = 17;
            v43.bVal = v14;
            LOBYTE(v49) = 6;
            COleVariant::operator=(this: &vt, varSrc: &v43);
            p_varSrc = &v43;
            goto LABEL_31;
          }
          if ( (unsigned __int16)dbStatus != 18 )
          {
            if ( (unsigned __int16)dbStatus != 19 )
              goto LABEL_53;
            goto LABEL_27;
          }
LABEL_28:
          v12 = (__int16 *)ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
          v13 = COleVariant::COleVariant(this: &v32, nSrc: *v12, vtSrc: 2u);
          LOBYTE(v49) = 7;
          COleVariant::operator=(this: &vt, varSrc: v13);
          p_varSrc = &v32;
          goto LABEL_31;
        }
        if ( (unsigned __int16)dbStatus != 8 )
        {
          if ( (unsigned __int16)dbStatus != 2 )
          {
            if ( (unsigned __int16)dbStatus != 3 )
            {
              switch ( (unsigned __int16)dbStatus )
              {
                case 4u:
                  nCol = *(float *)ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
                  v37.fltVal = nCol;
                  v37.vt = 4;
                  LOBYTE(v49) = 9;
                  COleVariant::operator=(this: &vt, varSrc: &v37);
                  p_varSrc = &v37;
                  goto LABEL_31;
                case 5u:
                  v40.dblVal = *(double *)ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
                  v40.vt = 5;
                  LOBYTE(v49) = 10;
                  COleVariant::operator=(this: &vt, varSrc: &v40);
                  p_varSrc = &v40;
                  goto LABEL_31;
                case 6u:
                  v7 = ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
                  v8 = *(_DWORD *)v7;
                  v9 = *((_DWORD *)v7 + 1);
                  v44.vt = 6;
                  v44.llVal = __PAIR64__(v9, v8);
                  LOBYTE(v49) = 13;
                  COleVariant::operator=(this: &vt, varSrc: &v44);
                  p_varSrc = &v44;
                  goto LABEL_31;
                case 7u:
                  varSrc.dblVal = *(double *)ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
                  varSrc.vt = 7;
                  LOBYTE(v49) = 12;
                  COleVariant::operator=(this: &vt, &varSrc);
                  p_varSrc = &varSrc;
LABEL_31:
                  LOBYTE(v49) = 0;
                  VariantClear(pvarg: p_varSrc);
                  break;
                default:
                  break;
              }
LABEL_53:
              COleVariant::COleVariant(this: result, varSrc: &vt);
              VariantClear(pvarg: &vt);
              return result;
            }
LABEL_27:
            v10 = ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
            v11 = COleVariant::COleVariant(this: &v34, lSrc: *(_DWORD *)v10, vtSrc: 3u);
            LOBYTE(v49) = 8;
            COleVariant::operator=(this: &vt, varSrc: v11);
            p_varSrc = &v34;
            goto LABEL_31;
          }
          goto LABEL_28;
        }
      }
      v24 = ATL::CDynamicAccessor::GetValue(this: v5, nColumn: LODWORD(nCol));
      v28 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&dbStatus,
              pszSrc: (const wchar_t *)v24)->m_pszData;
      LOBYTE(v49) = 4;
      v25 = COleVariant::COleVariant(this: &v29, lpszSrc: v28, vtSrc: 8u);
      LOBYTE(v49) = 5;
      COleVariant::operator=(this: &vt, varSrc: v25);
      VariantClear(pvarg: &v29);
      v21 = dbStatus;
      goto LABEL_52;
    }
  }
  COleVariant::COleVariant(this: result, varSrc: &vt);
  VariantClear(pvarg: &vt);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004291BC
// Name: public: virtual long CDataSourceControl::UpdateControls(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CDataSourceControl::UpdateControls(CDataSourceControl *this)
{
  CPtrList *m_pClientList; // eax
  __POSITION *m_pNodeHead; // eax
  _DWORD *v4; // esi
  COleVariant *v5; // eax
  COleVariant *p_vt; // eax
  int (__stdcall ***v7)(_DWORD, GUID *, IDispatch **); // eax
  tagEXCEPINFO excepinfo; // [esp+10h] [ebp-78h] BYREF
  COleVariant v10; // [esp+30h] [ebp-58h] BYREF
  COleVariant vt; // [esp+40h] [ebp-48h] BYREF
  tagDISPPARAMS dispparamsSetProp; // [esp+50h] [ebp-38h] BYREF
  unsigned int uArgErr; // [esp+60h] [ebp-28h] BYREF
  int dispidNamed; // [esp+64h] [ebp-24h] BYREF
  __POSITION *pos; // [esp+68h] [ebp-20h]
  IDispatch *pDispatch; // [esp+6Ch] [ebp-1Ch] BYREF
  unsigned int v17; // [esp+70h] [ebp-18h]
  int nItem; // [esp+74h] [ebp-14h]
  int nCol; // [esp+78h] [ebp-10h]
  int v20; // [esp+84h] [ebp-4h]

  this->m_bUpdateInProgress = 1;
  nItem = 0;
  for ( nCol = 0; nCol < this->m_nColumns; ++nCol )
  {
    m_pClientList = this->m_pMetaRowData[nCol].m_pClientList;
    if ( m_pClientList != nullptr )
    {
      m_pNodeHead = (__POSITION *)m_pClientList->m_pNodeHead;
      if ( m_pNodeHead != nullptr )
      {
        v17 = 16 * nItem;
        while ( 1 )
        {
          v4 = *(_DWORD **)&m_pNodeHead[8];
          pos = *(__POSITION **)m_pNodeHead;
          dispidNamed = -3;
          memset(dst: (int)&excepinfo, value: nullptr, count: sizeof(excepinfo));
          AfxVariantInit(pVar: &vt);
          v20 = 0;
          if ( this->m_pDataSource != nullptr )
          {
            v5 = CDataSourceControl::ToVariant(this, result: &v10, nCol: COERCE_FLOAT(nCol + 1));
            LOBYTE(v20) = 1;
            COleVariant::operator=(this: &vt, varSrc: v5);
            LOBYTE(v20) = 0;
            VariantClear(pvarg: &v10);
            p_vt = &vt;
          }
          else
          {
            p_vt = (COleVariant *)&this->m_pValues[v17 / 0x10];
          }
          dispparamsSetProp.rgvarg = p_vt;
          dispparamsSetProp.rgdispidNamedArgs = &dispidNamed;
          dispparamsSetProp.cArgs = 1;
          dispparamsSetProp.cNamedArgs = 1;
          v4[34] = 1;
          v7 = (int (__stdcall ***)(_DWORD, GUID *, IDispatch **))v4[20];
          if ( v7 != nullptr && (**v7)(a1: v7, a2: &IID_IDispatch, a3: &pDispatch) >= 0 )
          {
            pDispatch->Invoke(
              this: pDispatch,
              a2: v4[39],
              a3: &GUID_NULL,
              a4: 0,
              a5: 4u,
              a6: &dispparamsSetProp,
              a7: nullptr,
              a8: &excepinfo,
              a9: &uArgErr);
            pDispatch->Release(this: pDispatch);
            v4[34] = 0;
            if ( excepinfo.bstrSource != nullptr )
              SysFreeString(bstrString: excepinfo.bstrSource);
            if ( excepinfo.bstrDescription != nullptr )
              SysFreeString(bstrString: excepinfo.bstrDescription);
            if ( excepinfo.bstrHelpFile != nullptr )
              SysFreeString(bstrString: excepinfo.bstrHelpFile);
            ++nItem;
            v17 += 16;
          }
          v20 = -1;
          VariantClear(pvarg: &vt);
          if ( pos == nullptr )
            break;
          m_pNodeHead = pos;
        }
      }
    }
  }
  this->m_bUpdateInProgress = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00429348
// Name: public: virtual COleControlSite::~COleControlSite(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleControlSite::~COleControlSite(COleControlSite *this)
{
  COleControlContainer *m_pCtrlCont; // eax
  CDataSourceControl *m_pDataSourceControl; // edi
  IOleInPlaceObjectWindowless *m_pWindowlessObject; // eax
  IOleInPlaceObject *m_pInPlaceObject; // eax
  IOleInPlaceActiveObject *m_pActiveObject; // eax
  IOleObject *m_pObject; // eax
  CDataBoundProperty *m_pBindings; // edi
  COleControlSite *m_pDSCSite; // eax
  COleControlSite *v10; // eax
  COleControlContainer *v11; // eax
  COleControlSite::XPropertyNotifySink_vtbl *v12; // ecx
  COleControlSite::XEventSink_vtbl *v13; // ecx
  ATL::CComPtr<IUnknown> spPropertyIUnknown; // [esp+14h] [ebp-14h] BYREF
  ATL::CComPtr<IUnknown> spEventIUnknown; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+24h] [ebp-4h]

  this->__vftable = (COleControlSite_vtbl *)&COleControlSite::`vftable';
  m_pCtrlCont = this->m_pCtrlCont;
  v16 = 2;
  if ( m_pCtrlCont != nullptr && m_pCtrlCont->m_pSiteCapture == this )
    m_pCtrlCont->m_pSiteCapture = nullptr;
  m_pDataSourceControl = this->m_pDataSourceControl;
  if ( m_pDataSourceControl != nullptr )
  {
    CDataSourceControl::~CDataSourceControl(this: this->m_pDataSourceControl);
    operator delete(p: m_pDataSourceControl);
  }
  COleControlSite::DetachWindow(this);
  COleControlSite::DisconnectSink(this, iid: &this->m_iidEvents, dwCookie: this->m_dwEventSink);
  COleControlSite::DisconnectSink(this, iid: &IID_IPropertyNotifySink, dwCookie: this->m_dwPropNotifySink);
  COleControlSite::DisconnectSink(this, iid: &IID_INotifyDBEvents, dwCookie: this->m_dwNotifyDBEvents);
  m_pWindowlessObject = this->m_pWindowlessObject;
  if ( m_pWindowlessObject != nullptr )
  {
    m_pWindowlessObject->Release(this: this->m_pWindowlessObject);
    this->m_pWindowlessObject = nullptr;
  }
  m_pInPlaceObject = this->m_pInPlaceObject;
  if ( m_pInPlaceObject != nullptr )
  {
    m_pInPlaceObject->InPlaceDeactivate(this: this->m_pInPlaceObject);
    this->m_pInPlaceObject->Release(this: this->m_pInPlaceObject);
    this->m_pInPlaceObject = nullptr;
  }
  m_pActiveObject = this->m_pActiveObject;
  if ( m_pActiveObject != nullptr )
  {
    m_pActiveObject->Release(this: this->m_pActiveObject);
    this->m_pActiveObject = nullptr;
  }
  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    m_pObject->SetClientSite(this: m_pObject, a2: nullptr);
    this->m_pObject->Close(this: this->m_pObject, a2: 1u);
    this->m_pObject->Release(this: this->m_pObject);
    this->m_pObject = nullptr;
  }
  VariantClear(pvarg: &this->m_varResult);
  m_pBindings = this->m_pBindings;
  if ( m_pBindings != nullptr )
  {
    this->m_pBindings = m_pBindings->m_pNext;
    m_pDSCSite = m_pBindings->m_pDSCSite;
    if ( m_pDSCSite != nullptr && m_pDSCSite->m_pDataSourceControl != nullptr )
      m_pDSCSite->m_pDataSourceControl->BindProp(this: m_pDSCSite->m_pDataSourceControl, a2: m_pBindings, a3: 0);
    operator delete(p: m_pBindings);
  }
  if ( this->m_defdispid != 0 )
  {
    v10 = this->m_pDSCSite;
    if ( v10 != nullptr && v10->m_pDataSourceControl != nullptr )
      v10->m_pDataSourceControl->BindProp_2(this: v10->m_pDataSourceControl, a2: this, a3: 0);
  }
  v11 = this->m_pCtrlCont;
  if ( v11 != nullptr && this->m_bIsWindowless != 0 )
    --v11->m_nWindowlessControls;
  spPropertyIUnknown.p = nullptr;
  v12 = this->m_xPropertyNotifySink.__vftable;
  LOBYTE(v16) = 3;
  if ( v12->QueryInterface(this: &this->m_xPropertyNotifySink, a2: &IID_IUnknown, a3: (void **)&spPropertyIUnknown.p) >= 0 )
    _AfxReleaseManagedRefs(lpUnk: spPropertyIUnknown.p);
  spEventIUnknown.p = nullptr;
  v13 = this->m_xEventSink.__vftable;
  LOBYTE(v16) = 4;
  if ( v13->QueryInterface(this: &this->m_xEventSink, a2: &IID_IUnknown, a3: (void **)&spEventIUnknown.p) >= 0 )
    _AfxReleaseManagedRefs(lpUnk: spEventIUnknown.p);
  LOBYTE(v16) = 3;
  if ( spEventIUnknown.p != nullptr )
    spEventIUnknown.p->Release(this: spEventIUnknown.p);
  LOBYTE(v16) = 2;
  if ( spPropertyIUnknown.p != nullptr )
    spPropertyIUnknown.p->Release(this: spPropertyIUnknown.p);
  LOBYTE(v16) = 1;
  COleDispatchDriver::ReleaseDispatch(this: &this->m_dispDriver);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strDataField.m_pszData - 1);
  v16 = -1;
  CCmdTarget::~CCmdTarget(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042955A
// Name: unsigned long _AfxGetDlgCode(class CWnd __near *,struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __stdcall _AfxGetDlgCode(CWnd *pWnd, tagMSG *lpMsg)
{
  WPARAM wParam; // eax

  if ( pWnd == nullptr )
    return 0;
  if ( lpMsg != nullptr )
    wParam = lpMsg->wParam;
  else
    wParam = 0;
  return SendMessageA(hWnd: pWnd->m_hWnd, Msg: 0x87u, wParam, lParam: (LPARAM)lpMsg);
}

//------------------------------------------------------------------------------
// Address: 0x0042958C
// Name: public: static int COccManager::IsMatchingMnemonic(struct COleControlSiteOrWnd __near *,struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl COccManager::IsMatchingMnemonic(COleControlSiteOrWnd *pSiteOrWnd, tagMSG *lpMsg)
{
  COleControlSite *m_pSite; // ecx

  m_pSite = pSiteOrWnd->m_pSite;
  return m_pSite != nullptr && COleControlSite::IsMatchingMnemonic(this: m_pSite, lpMsg) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004295B0
// Name: public: static int COccManager::IsLabelControl(struct COleControlSiteOrWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl COccManager::IsLabelControl(COleControlSiteOrWnd *pSiteOrWnd)
{
  COleControlSite *m_pSite; // eax
  HWND__ *m_hWnd; // ecx
  COleControlSite *v4; // esi

  if ( pSiteOrWnd == nullptr )
    return false;
  m_pSite = pSiteOrWnd->m_pSite;
  if ( m_pSite != nullptr )
    m_hWnd = m_pSite->m_hWnd;
  else
    m_hWnd = pSiteOrWnd->m_hWnd;
  if ( m_hWnd != nullptr )
  {
    if ( !IsWindowEnabled(hWnd: m_hWnd) )
      return false;
  }
  else if ( m_pSite != nullptr && (((int (*)(void))m_pSite->GetStyle)() & 0x8000000) != 0 )
  {
    return false;
  }
  v4 = pSiteOrWnd->m_pSite;
  return v4 != nullptr && (v4->m_dwMiscStatus & 0x2000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00429606
// Name: public: static unsigned long COccManager::GetDefBtnCode(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__cdecl COccManager::GetDefBtnCode(CWnd *pWnd)
{
  CWnd *result; // eax
  COleControlSite *m_pCtrlSite; // ecx

  result = pWnd;
  if ( pWnd != nullptr )
  {
    m_pCtrlSite = pWnd->m_pCtrlSite;
    if ( m_pCtrlSite != nullptr )
      return (CWnd *)COleControlSite::GetDefBtnCode(this: m_pCtrlSite);
    else
      return (CWnd *)(_AfxGetDlgCode(pWnd, lpMsg: nullptr) & 0x30);
  }
  return result;
}

} // namespace vmpi_services_watch

// ============================================================
// Overlay from vmpi_service_ui (Missing functions)
// ============================================================
namespace vmpi_service_ui {

//------------------------------------------------------------------------------
// Address: 0x00401460
// Name: void IPAddrToSockAddr(class CIPAddr const __near *,struct sockaddr_in __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IPAddrToSockAddr(const CIPAddr *pIn, sockaddr_in *pOut)
{
  *(_QWORD *)&pOut->sin_family = 0;
  *(_QWORD *)pOut->sin_zero = 0;
  pOut->sin_family = 2;
  pOut->sin_port = htons(hostshort: pIn->port);
  pOut->sin_addr.S_un.S_addr = *(_DWORD *)pIn->ip;
}

//------------------------------------------------------------------------------
// Address: 0x00401530
// Name: public: bool CWaitTimer::ShouldKeepWaiting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaitTimer::ShouldKeepWaiting(CWaitTimer *this)
{
  unsigned __int64 v2; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v3; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v4; // [esp+Ch] [ebp-4h]

  if ( this->m_WaitMS == 0 )
    return false;
  v4 = &v3;
  v3 = __rdtsc();
  HIDWORD(v2) = HIDWORD(_g_ClockSpeed);
  LODWORD(v2) = _g_ClockSpeed;
  return (unsigned int)(1000 * v3 / v2) - this->m_StartTime <= this->m_WaitMS || g_bForceWaitTimers;
}

//------------------------------------------------------------------------------
// Address: 0x004015B0
// Name: public: CIPAddr::CIPAddr(void)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(CIPAddr *this)
{
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004015C0
// Name: public: CIPAddr::CIPAddr(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(
        CIPAddr *this,
        unsigned __int8 ip0,
        unsigned __int8 ip1,
        unsigned __int8 ip2,
        unsigned __int8 ip3,
        unsigned __int16 ipPort)
{
  this->ip[0] = ip0;
  this->ip[1] = ip1;
  this->ip[2] = ip2;
  this->ip[3] = ip3;
  this->port = ipPort;
  return this;
}

} // namespace vmpi_service_ui

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10091120
// Name: public: void CIPAddr::Init(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIPAddr::Init(
        CIPAddr *this,
        unsigned __int8 ip0,
        unsigned __int8 ip1,
        unsigned __int8 ip2,
        unsigned __int8 ip3,
        unsigned __int16 ipPort)
{
  this->ip[0] = ip0;
  this->ip[1] = ip1;
  this->ip[2] = ip2;
  this->ip[3] = ip3;
  this->port = ipPort;
}

//------------------------------------------------------------------------------
// Address: 0x10091150
// Name: void IPAddrToSockAddr(class CIPAddr const __near *,struct sockaddr_in __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IPAddrToSockAddr(const CIPAddr *pIn, sockaddr_in *pOut)
{
  *(_QWORD *)&pOut->sin_family = 0;
  *(_QWORD *)pOut->sin_zero = 0;
  pOut->sin_family = 2;
  pOut->sin_port = htons(hostshort: pIn->port);
  pOut->sin_addr.S_un.S_addr = *(_DWORD *)pIn->ip;
}

//------------------------------------------------------------------------------
// Address: 0x100911A0
// Name: void SockAddrToIPAddr(struct sockaddr_in const __near *,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SockAddrToIPAddr(const sockaddr_in *pIn, CIPAddr *pOut)
{
  *(_DWORD *)pOut->ip = pIn->sin_addr.S_un.S_addr;
  pOut->port = ntohs(netshort: pIn->sin_port);
}

//------------------------------------------------------------------------------
// Address: 0x100911E0
// Name: bool ConvertStringToIPAddr(char const __near *,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ConvertStringToIPAddr(char *pStr, CIPAddr *pOut)
{
  int v2; // eax
  int v3; // edi
  unsigned int v4; // esi
  CIPAddr *v5; // esi
  unsigned __int8 v7; // al
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  struct hostent *v10; // eax
  char ipStr[512]; // [esp+Ch] [ebp-210h] BYREF
  int v12[4]; // [esp+20Ch] [ebp-10h] BYREF

  strchr(string: (unsigned __int8 *)pStr, chr: 0x3Au);
  v3 = v2;
  if ( v2 != 0 )
  {
    v4 = v2 - (_DWORD)pStr;
    if ( v2 - (int)pStr < 2 || v4 > 0x1FF )
      return 0;
    memcpy(dst: (unsigned __int8 *)ipStr, src: (unsigned __int8 *)pStr, count: v2 - (_DWORD)pStr);
    ipStr[v4] = 0;
    v5 = pOut;
    pOut->port = atoi(nptr: (const char *)(v3 + 1));
  }
  else
  {
    strncpy(dest: (unsigned __int8 *)ipStr, source: (unsigned __int8 *)pStr, count: 0x200u);
    v5 = pOut;
    ipStr[511] = 0;
  }
  if ( (unsigned __int8)(ipStr[0] - 48) <= 9u )
  {
    sscanf(string: ipStr, format: "%d.%d.%d.%d", v12, &v12[1], &v12[2], &v12[3]);
    v7 = v12[1];
    v8 = v12[2];
    v5->ip[0] = v12[0];
    v9 = v12[3];
    v5->ip[1] = v7;
    v5->ip[2] = v8;
    v5->ip[3] = v9;
    return 1;
  }
  v10 = gethostbyname(name: ipStr);
  if ( v10 == nullptr )
    return 0;
  v5->ip[0] = **v10->h_addr_list;
  v5->ip[1] = (*v10->h_addr_list)[1];
  v5->ip[2] = (*v10->h_addr_list)[2];
  v5->ip[3] = (*v10->h_addr_list)[3];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091300
// Name: void IP_GetLastErrorString(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IP_GetLastErrorString(char *pStr, int maxLen)
{
  DWORD LastError; // eax
  char *lpMsgBuf; // [esp+0h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  V_strncpy(pDest: pStr, pSrc: lpMsgBuf, maxLen);
  LocalFree(hMem: lpMsgBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10091350
// Name: public: CWaitTimer::CWaitTimer(double)
// Source: json
//------------------------------------------------------------------------------
CWaitTimer *__thiscall CWaitTimer::CWaitTimer(CWaitTimer *this, long double flSeconds)
{
  unsigned __int64 v3; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v4; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v5; // [esp+Ch] [ebp-4h]

  v5 = &v4;
  v4 = __rdtsc();
  HIDWORD(v3) = HIDWORD(_g_ClockSpeed);
  LODWORD(v3) = _g_ClockSpeed;
  this->m_StartTime = 1000 * v4 / v3;
  this->m_WaitMS = (__int64)(flSeconds * 1000.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100913D0
// Name: public: bool CWaitTimer::ShouldKeepWaiting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaitTimer::ShouldKeepWaiting(CWaitTimer *this)
{
  unsigned __int64 v2; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v3; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v4; // [esp+Ch] [ebp-4h]

  if ( this->m_WaitMS == 0 )
    return false;
  v4 = &v3;
  v3 = __rdtsc();
  HIDWORD(v2) = HIDWORD(_g_ClockSpeed);
  LODWORD(v2) = _g_ClockSpeed;
  return (unsigned int)(1000 * v3 / v2) - this->m_StartTime <= this->m_WaitMS || g_bForceWaitTimers;
}

//------------------------------------------------------------------------------
// Address: 0x10091450
// Name: public: CIPAddr::CIPAddr(void)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(CIPAddr *this)
{
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10091460
// Name: public: CIPAddr::CIPAddr(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(
        CIPAddr *this,
        unsigned __int8 ip0,
        unsigned __int8 ip1,
        unsigned __int8 ip2,
        unsigned __int8 ip3,
        unsigned __int16 ipPort)
{
  this->ip[0] = ip0;
  this->ip[1] = ip1;
  this->ip[2] = ip2;
  this->ip[3] = ip3;
  this->port = ipPort;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10091490
// Name: public: virtual void CIPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIPSocket::Release(CIPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CIPSocket *, int))this->dtr_CIPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100914A0
// Name: public: virtual bool CIPSocket::Bind(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Bind(CIPSocket *this, const CIPAddr *pAddr)
{
  bool result; // al

  result = this->CreateSocket(this);
  if ( result )
    return this->BindPart2(this, a2: pAddr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100914D0
// Name: public: virtual bool CIPSocket::ListenToMulticastStream(class CIPAddr const __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::ListenToMulticastStream(CIPSocket *this, int addr, const CIPAddr *localInterface)
{
  unsigned __int8 v3; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // dl
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // dl
  in_addr::<unnamed_type_S_un> S_un; // ecx
  in_addr::<unnamed_type_S_un> v12; // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  ip_mreq mr; // [esp+8h] [ebp-8h] BYREF

  v3 = *(_BYTE *)(addr + 1);
  mr.imr_multiaddr.S_un.S_un_b.s_b1 = *(_BYTE *)addr;
  v5 = *(_BYTE *)(addr + 2);
  mr.imr_multiaddr.S_un.S_un_b.s_b2 = v3;
  v6 = *(_BYTE *)(addr + 3);
  mr.imr_multiaddr.S_un.S_un_b.s_b3 = v5;
  v7 = localInterface->ip[0];
  mr.imr_multiaddr.S_un.S_un_b.s_b4 = v6;
  v8 = localInterface->ip[1];
  mr.imr_interface.S_un.S_un_b.s_b1 = v7;
  v9 = localInterface->ip[2];
  mr.imr_interface.S_un.S_un_b.s_b2 = v8;
  v10 = localInterface->ip[3];
  mr.imr_interface.S_un.S_un_b.s_b3 = v9;
  m_Socket = this->m_Socket;
  mr.imr_interface.S_un.S_un_b.s_b4 = v10;
  addr = 0x200000;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 4098, optval: (const char *)&addr, optlen: 4);
  if ( setsockopt(s: this->m_Socket, level: 0, optname: 12, optval: (const char *)&mr, optlen: 8) != 0 )
    return 0;
  S_un = mr.imr_multiaddr.S_un;
  v12 = mr.imr_interface.S_un;
  this->m_bMulticastGroupMembership = true;
  this->m_MulticastGroupMREQ.imr_multiaddr.S_un = S_un;
  this->m_MulticastGroupMREQ.imr_interface.S_un = v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091570
// Name: public: virtual bool CIPSocket::SendTo(class CIPAddr const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::SendTo(CIPSocket *this, const CIPAddr *pAddr, const void *pData, int len)
{
  return this->SendChunksTo(this, a2: pAddr, a3: &pData, a4: &len, a5: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10091590
// Name: public: virtual bool CIPSocket::SendChunksTo(class CIPAddr const __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CIPSocket::SendChunksTo(
        CIPSocket *this,
        const CIPAddr *pAddr,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  signed int v5; // ebx
  char *v6; // edx
  signed int v7; // eax
  int v8; // esi
  unsigned int *v9; // ecx
  char *v10; // ebx
  unsigned int v11; // edx
  char *v12; // ebx
  unsigned int v13; // edx
  unsigned int v14; // edx
  char *v15; // ecx
  u_short port; // ax
  u_short v17; // ax
  unsigned __int8 v18; // dl
  unsigned __int8 v19; // cl
  unsigned __int8 v20; // cl
  SOCKET m_Socket; // eax
  _WSABUF bufs[32]; // [esp+Ch] [ebp-124h] BYREF
  CIPSocket *v24; // [esp+10Ch] [ebp-24h]
  int nTotalBytes; // [esp+110h] [ebp-20h]
  sockaddr_in addr; // [esp+114h] [ebp-1Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+124h] [ebp-Ch] BYREF
  int v28; // [esp+128h] [ebp-8h]
  int v29; // [esp+12Ch] [ebp-4h]

  v5 = nChunks;
  v24 = this;
  if ( nChunks > 32 )
    _Error(a1: "CIPSocket::SendChunksTo: too many chunks (%d).", nChunks);
  v6 = pChunkLengths;
  v7 = 0;
  v8 = 0;
  v29 = 0;
  v28 = 0;
  nTotalBytes = 0;
  if ( nChunks >= 2 )
  {
    v9 = (unsigned int *)(pChunkLengths + 4);
    do
    {
      v10 = (char *)pChunks[v7];
      v11 = *(v9 - 1);
      v29 += v11;
      bufs[v7].buf = v10;
      v12 = *(char **)((char *)v9 + (char *)pChunks - pChunkLengths);
      bufs[v7].len = v11;
      v13 = *v9;
      v28 += *v9;
      bufs[v7 + 1].buf = v12;
      v5 = nChunks;
      bufs[v7 + 1].len = v13;
      v7 += 2;
      v9 += 2;
    }
    while ( v7 < nChunks - 1 );
    v6 = pChunkLengths;
    v8 = nTotalBytes;
  }
  if ( v7 < v5 )
  {
    v14 = *(_DWORD *)&v6[4 * v7];
    v15 = (char *)pChunks[v7];
    bufs[v7].len = v14;
    bufs[v7].buf = v15;
    v8 = v14;
  }
  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v17 = htons(hostshort: port);
  v18 = pAddr->ip[1];
  v19 = pAddr->ip[0];
  addr.sin_port = v17;
  LOBYTE(v17) = pAddr->ip[2];
  addr.sin_addr.S_un.S_un_b.s_b2 = v18;
  addr.sin_addr.S_un.S_un_b.s_b1 = v19;
  v20 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v17;
  m_Socket = v24->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v20;
  dwNumBytesSent = 0;
  return WSASendTo(
           s: m_Socket,
           lpBuffers: bufs,
           dwBufferCount: v5,
           lpNumberOfBytesSent: &dwNumBytesSent,
           dwFlags: 0,
           lpTo: (const struct sockaddr *)&addr,
           iTolen: 16,
           lpOverlapped: nullptr,
           lpCompletionRoutine: nullptr) == 0
      && dwNumBytesSent == v8 + v29 + v28;
}

//------------------------------------------------------------------------------
// Address: 0x100916D0
// Name: IP_FloatTime
// Source: json
//------------------------------------------------------------------------------
long double __cdecl IP_FloatTime()
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x10091730
// Name: public: virtual bool CIPSocket::CreateSocket(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::CreateSocket(CIPSocket *this)
{
  SOCKET m_Socket; // eax
  SOCKET v3; // edi
  unsigned int val; // [esp+8h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  if ( m_Socket != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: m_Socket, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  v3 = socket(af: 2, type: 2, protocol: 0);
  if ( v3 == -1 )
    return 0;
  val = 1;
  if ( ioctlsocket(s: v3, cmd: -2147195266, argp: &val) != 0 )
  {
    closesocket(s: v3);
    return 0;
  }
  this->m_Socket = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100917C0
// Name: public: virtual bool CIPSocket::BindPart2(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::BindPart2(CIPSocket *this, const CIPAddr *pAddr)
{
  u_short port; // cx
  u_short v4; // ax
  unsigned __int8 v5; // dl
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // dl
  SOCKET v9; // eax
  SOCKET m_Socket; // [esp-Ch] [ebp-24h]
  sockaddr_in addr; // [esp+8h] [ebp-10h] BYREF

  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v4 = htons(hostshort: port);
  v5 = pAddr->ip[0];
  v6 = pAddr->ip[2];
  addr.sin_port = v4;
  addr.sin_addr.S_un.S_un_b.s_b2 = pAddr->ip[1];
  addr.sin_addr.S_un.S_un_b.s_b1 = v5;
  v7 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v6;
  m_Socket = this->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v7;
  if ( bind(s: m_Socket, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
    return 1;
  v9 = this->m_Socket;
  if ( v9 != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: v9, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10091870
// Name: public: virtual bool CIPSocket::BindToAny(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::BindToAny(CIPSocket *this, unsigned __int16 port)
{
  bool (__thiscall *Bind)(struct CIPSocket *, const CIPAddr *); // edx
  CIPAddr addr; // [esp+0h] [ebp-8h] BYREF

  Bind = this->Bind;
  addr.port = port;
  *(_DWORD *)addr.ip = 0;
  return Bind(this, a2: &addr);
}

//------------------------------------------------------------------------------
// Address: 0x100918A0
// Name: public: virtual bool CIPSocket::Broadcast(void const __near *,int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Broadcast(CIPSocket *this, const void *pData, int len, unsigned __int16 port)
{
  CIPSocket_vtbl *v6; // eax
  bool (__thiscall *SendTo)(struct CIPSocket *, const CIPAddr *, const void *, const int); // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  CIPAddr addr; // [esp+4h] [ebp-Ch] BYREF
  int bBroadcast; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bSetupToBroadcast )
  {
    m_Socket = this->m_Socket;
    bBroadcast = 1;
    if ( setsockopt(s: m_Socket, level: 0xFFFF, optname: 32, optval: (const char *)&bBroadcast, optlen: 4) != 0 )
      return false;
    this->m_bSetupToBroadcast = true;
  }
  v6 = this->__vftable;
  addr.port = port;
  SendTo = v6->SendTo;
  *(_DWORD *)addr.ip = -1;
  return SendTo(this, a2: &addr, a3: pData, a4: len);
}

//------------------------------------------------------------------------------
// Address: 0x10091910
// Name: public: virtual int CIPSocket::RecvFrom(void __near *,int,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CIPSocket::RecvFrom(CIPSocket *this, char *pData, int maxDataLen, CIPAddr *pFrom)
{
  unsigned int m_Socket; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  SOCKET v10; // [esp-1Ch] [ebp-140h]
  fd_set readSet; // [esp+4h] [ebp-120h] BYREF
  sockaddr_in sender; // [esp+108h] [ebp-1Ch] BYREF
  timeval timeVal; // [esp+118h] [ebp-Ch] BYREF
  int fromSize; // [esp+120h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  timeVal.tv_usec = 0;
  readSet.fd_array[0] = m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  v6 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v6 == 0 || v6 == -1 )
    return -1;
  v10 = this->m_Socket;
  fromSize = 16;
  v7 = recvfrom(s: v10, buf: pData, len: maxDataLen, flags: 0, from: (struct sockaddr *)&sender, fromlen: &fromSize);
  v8 = v7;
  if ( v7 == 0 || v7 == -1 )
    return -1;
  if ( pFrom != nullptr )
    SockAddrToIPAddr(pIn: &sender, pOut: pFrom);
  this->m_flLastRecvTime = IP_FloatTime();
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100919C0
// Name: public: virtual double CIPSocket::GetRecvTimeout(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CIPSocket::GetRecvTimeout(CIPSocket *this)
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier - this->m_flLastRecvTime;
}

//------------------------------------------------------------------------------
// Address: 0x10091A80
// Name: class ISocket __near * CreateIPSocket(void)
// Source: json
//------------------------------------------------------------------------------
ISocket *__cdecl CreateIPSocket()
{
  ISocket *result; // eax

  result = (ISocket *)MemAlloc_Alloc(nSize: 0x28u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ISocket_vtbl *)&CIPSocket::`vftable';
  result[1].__vftable = (ISocket_vtbl *)-1;
  LOBYTE(result[5].__vftable) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10091AB0
// Name: class ISocket __near * CreateMulticastListenSocket(class CIPAddr const __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
ISocket *__cdecl CreateMulticastListenSocket(const CIPAddr *addr, const CIPAddr *localInterface)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax
  CIPAddr bindAddr; // [esp+Ch] [ebp-8h] BYREF

  v2 = MemAlloc_Alloc(nSize: 0x28u);
  if ( v2 != nullptr )
  {
    *v2 = &CIPSocket::`vftable';
    v2[1] = -1;
    *((_BYTE *)v2 + 20) = 0;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = *(_DWORD *)localInterface->ip;
  bindAddr.port = addr->port;
  *(_DWORD *)bindAddr.ip = v4;
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CIPAddr *))(*v3 + 4))(a1: v3, a2: &bindAddr) != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD *, const CIPAddr *, const CIPAddr *))(*v3 + 44))(
         a1: v3,
         a2: addr,
         a3: localInterface) != 0 )
  {
    return (ISocket *)v3;
  }
  (*(void (__thiscall **)(_DWORD *))*v3)(a1: v3);
  return nullptr;
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x10029A90
// Name: public: void CIPAddr::Init(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIPAddr::Init(
        CIPAddr *this,
        unsigned __int8 ip0,
        unsigned __int8 ip1,
        unsigned __int8 ip2,
        unsigned __int8 ip3,
        unsigned __int16 ipPort)
{
  this->ip[0] = ip0;
  this->ip[1] = ip1;
  this->ip[2] = ip2;
  this->ip[3] = ip3;
  this->port = ipPort;
}

//------------------------------------------------------------------------------
// Address: 0x10029AC0
// Name: void IPAddrToSockAddr(class CIPAddr const __near *,struct sockaddr_in __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IPAddrToSockAddr(const CIPAddr *pIn, sockaddr_in *pOut)
{
  *(_QWORD *)&pOut->sin_family = 0;
  *(_QWORD *)pOut->sin_zero = 0;
  pOut->sin_family = 2;
  pOut->sin_port = htons(hostshort: pIn->port);
  pOut->sin_addr.S_un.S_addr = *(_DWORD *)pIn->ip;
}

//------------------------------------------------------------------------------
// Address: 0x10029B10
// Name: void SockAddrToIPAddr(struct sockaddr_in const __near *,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SockAddrToIPAddr(const sockaddr_in *pIn, CIPAddr *pOut)
{
  *(_DWORD *)pOut->ip = pIn->sin_addr.S_un.S_addr;
  pOut->port = ntohs(netshort: pIn->sin_port);
}

//------------------------------------------------------------------------------
// Address: 0x10029B50
// Name: bool ConvertStringToIPAddr(char const __near *,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ConvertStringToIPAddr(char *pStr, CIPAddr *pOut)
{
  int v2; // eax
  int v3; // edi
  unsigned int v4; // esi
  CIPAddr *v5; // esi
  unsigned __int8 v7; // al
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  struct hostent *v10; // eax
  char ipStr[512]; // [esp+Ch] [ebp-210h] BYREF
  int v12[4]; // [esp+20Ch] [ebp-10h] BYREF

  strchr(string: (unsigned __int8 *)pStr, chr: 0x3Au);
  v3 = v2;
  if ( v2 != 0 )
  {
    v4 = v2 - (_DWORD)pStr;
    if ( v2 - (int)pStr < 2 || v4 > 0x1FF )
      return 0;
    memcpy(dst: (unsigned __int8 *)ipStr, src: (unsigned __int8 *)pStr, count: v2 - (_DWORD)pStr);
    ipStr[v4] = 0;
    v5 = pOut;
    pOut->port = atoi(nptr: (const char *)(v3 + 1));
  }
  else
  {
    strncpy(dest: (unsigned __int8 *)ipStr, source: (unsigned __int8 *)pStr, count: 0x200u);
    v5 = pOut;
    ipStr[511] = 0;
  }
  if ( (unsigned __int8)(ipStr[0] - 48) <= 9u )
  {
    sscanf(string: ipStr, format: "%d.%d.%d.%d", v12, &v12[1], &v12[2], &v12[3]);
    v7 = v12[1];
    v8 = v12[2];
    v5->ip[0] = v12[0];
    v9 = v12[3];
    v5->ip[1] = v7;
    v5->ip[2] = v8;
    v5->ip[3] = v9;
    return 1;
  }
  v10 = gethostbyname(name: ipStr);
  if ( v10 == nullptr )
    return 0;
  v5->ip[0] = **v10->h_addr_list;
  v5->ip[1] = (*v10->h_addr_list)[1];
  v5->ip[2] = (*v10->h_addr_list)[2];
  v5->ip[3] = (*v10->h_addr_list)[3];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029C70
// Name: void IP_GetLastErrorString(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IP_GetLastErrorString(char *pStr, int maxLen)
{
  DWORD LastError; // eax
  char *lpMsgBuf; // [esp+0h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  V_strncpy(pDest: pStr, pSrc: lpMsgBuf, maxLen);
  LocalFree(hMem: lpMsgBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10029CC0
// Name: public: CWaitTimer::CWaitTimer(double)
// Source: json
//------------------------------------------------------------------------------
CWaitTimer *__thiscall CWaitTimer::CWaitTimer(CWaitTimer *this, long double flSeconds)
{
  unsigned __int64 v3; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v4; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v5; // [esp+Ch] [ebp-4h]

  v5 = &v4;
  v4 = __rdtsc();
  HIDWORD(v3) = HIDWORD(_g_ClockSpeed);
  LODWORD(v3) = _g_ClockSpeed;
  this->m_StartTime = 1000 * v4 / v3;
  this->m_WaitMS = (__int64)(flSeconds * 1000.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10029D40
// Name: public: bool CWaitTimer::ShouldKeepWaiting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaitTimer::ShouldKeepWaiting(CWaitTimer *this)
{
  unsigned __int64 v2; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v3; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v4; // [esp+Ch] [ebp-4h]

  if ( this->m_WaitMS == 0 )
    return false;
  v4 = &v3;
  v3 = __rdtsc();
  HIDWORD(v2) = HIDWORD(_g_ClockSpeed);
  LODWORD(v2) = _g_ClockSpeed;
  return (unsigned int)(1000 * v3 / v2) - this->m_StartTime <= this->m_WaitMS || g_bForceWaitTimers;
}

//------------------------------------------------------------------------------
// Address: 0x10029DC0
// Name: public: CIPAddr::CIPAddr(void)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(CIPAddr *this)
{
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10029DD0
// Name: public: CIPAddr::CIPAddr(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CIPAddr *__thiscall CIPAddr::CIPAddr(
        CIPAddr *this,
        unsigned __int8 ip0,
        unsigned __int8 ip1,
        unsigned __int8 ip2,
        unsigned __int8 ip3,
        unsigned __int16 ipPort)
{
  this->ip[0] = ip0;
  this->ip[1] = ip1;
  this->ip[2] = ip2;
  this->ip[3] = ip3;
  this->port = ipPort;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10029E00
// Name: public: virtual void CIPSocket::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIPSocket::Release(CIPSocket *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CIPSocket *, int))this->dtr_CIPSocket)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10029E10
// Name: public: virtual bool CIPSocket::Bind(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Bind(CIPSocket *this, const CIPAddr *pAddr)
{
  bool result; // al

  result = this->CreateSocket(this);
  if ( result )
    return this->BindPart2(this, a2: pAddr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029E40
// Name: public: virtual bool CIPSocket::ListenToMulticastStream(class CIPAddr const __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::ListenToMulticastStream(CIPSocket *this, int addr, const CIPAddr *localInterface)
{
  unsigned __int8 v3; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // dl
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // dl
  in_addr::<unnamed_type_S_un> S_un; // ecx
  in_addr::<unnamed_type_S_un> v12; // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  ip_mreq mr; // [esp+8h] [ebp-8h] BYREF

  v3 = *(_BYTE *)(addr + 1);
  mr.imr_multiaddr.S_un.S_un_b.s_b1 = *(_BYTE *)addr;
  v5 = *(_BYTE *)(addr + 2);
  mr.imr_multiaddr.S_un.S_un_b.s_b2 = v3;
  v6 = *(_BYTE *)(addr + 3);
  mr.imr_multiaddr.S_un.S_un_b.s_b3 = v5;
  v7 = localInterface->ip[0];
  mr.imr_multiaddr.S_un.S_un_b.s_b4 = v6;
  v8 = localInterface->ip[1];
  mr.imr_interface.S_un.S_un_b.s_b1 = v7;
  v9 = localInterface->ip[2];
  mr.imr_interface.S_un.S_un_b.s_b2 = v8;
  v10 = localInterface->ip[3];
  mr.imr_interface.S_un.S_un_b.s_b3 = v9;
  m_Socket = this->m_Socket;
  mr.imr_interface.S_un.S_un_b.s_b4 = v10;
  addr = 0x200000;
  setsockopt(s: m_Socket, level: 0xFFFF, optname: 4098, optval: (const char *)&addr, optlen: 4);
  if ( setsockopt(s: this->m_Socket, level: 0, optname: 12, optval: (const char *)&mr, optlen: 8) != 0 )
    return 0;
  S_un = mr.imr_multiaddr.S_un;
  v12 = mr.imr_interface.S_un;
  this->m_bMulticastGroupMembership = true;
  this->m_MulticastGroupMREQ.imr_multiaddr.S_un = S_un;
  this->m_MulticastGroupMREQ.imr_interface.S_un = v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029EE0
// Name: public: virtual bool CIPSocket::SendTo(class CIPAddr const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::SendTo(CIPSocket *this, const CIPAddr *pAddr, const void *pData, int len)
{
  return this->SendChunksTo(this, a2: pAddr, a3: &pData, a4: &len, a5: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10029F00
// Name: public: virtual bool CIPSocket::SendChunksTo(class CIPAddr const __near *,void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CIPSocket::SendChunksTo(
        CIPSocket *this,
        const CIPAddr *pAddr,
        const void *const *pChunks,
        char *pChunkLengths,
        int nChunks)
{
  signed int v5; // ebx
  char *v6; // edx
  signed int v7; // eax
  int v8; // esi
  unsigned int *v9; // ecx
  char *v10; // ebx
  unsigned int v11; // edx
  char *v12; // ebx
  unsigned int v13; // edx
  unsigned int v14; // edx
  char *v15; // ecx
  u_short port; // ax
  u_short v17; // ax
  unsigned __int8 v18; // dl
  unsigned __int8 v19; // cl
  unsigned __int8 v20; // cl
  SOCKET m_Socket; // eax
  _WSABUF bufs[32]; // [esp+Ch] [ebp-124h] BYREF
  CIPSocket *v24; // [esp+10Ch] [ebp-24h]
  int nTotalBytes; // [esp+110h] [ebp-20h]
  sockaddr_in addr; // [esp+114h] [ebp-1Ch] BYREF
  unsigned int dwNumBytesSent; // [esp+124h] [ebp-Ch] BYREF
  int v28; // [esp+128h] [ebp-8h]
  int v29; // [esp+12Ch] [ebp-4h]

  v5 = nChunks;
  v24 = this;
  if ( nChunks > 32 )
    _Error(a1: "CIPSocket::SendChunksTo: too many chunks (%d).", nChunks);
  v6 = pChunkLengths;
  v7 = 0;
  v8 = 0;
  v29 = 0;
  v28 = 0;
  nTotalBytes = 0;
  if ( nChunks >= 2 )
  {
    v9 = (unsigned int *)(pChunkLengths + 4);
    do
    {
      v10 = (char *)pChunks[v7];
      v11 = *(v9 - 1);
      v29 += v11;
      bufs[v7].buf = v10;
      v12 = *(char **)((char *)v9 + (char *)pChunks - pChunkLengths);
      bufs[v7].len = v11;
      v13 = *v9;
      v28 += *v9;
      bufs[v7 + 1].buf = v12;
      v5 = nChunks;
      bufs[v7 + 1].len = v13;
      v7 += 2;
      v9 += 2;
    }
    while ( v7 < nChunks - 1 );
    v6 = pChunkLengths;
    v8 = nTotalBytes;
  }
  if ( v7 < v5 )
  {
    v14 = *(_DWORD *)&v6[4 * v7];
    v15 = (char *)pChunks[v7];
    bufs[v7].len = v14;
    bufs[v7].buf = v15;
    v8 = v14;
  }
  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v17 = htons(hostshort: port);
  v18 = pAddr->ip[1];
  v19 = pAddr->ip[0];
  addr.sin_port = v17;
  LOBYTE(v17) = pAddr->ip[2];
  addr.sin_addr.S_un.S_un_b.s_b2 = v18;
  addr.sin_addr.S_un.S_un_b.s_b1 = v19;
  v20 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v17;
  m_Socket = v24->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v20;
  dwNumBytesSent = 0;
  return WSASendTo(
           s: m_Socket,
           lpBuffers: bufs,
           dwBufferCount: v5,
           lpNumberOfBytesSent: &dwNumBytesSent,
           dwFlags: 0,
           lpTo: (const struct sockaddr *)&addr,
           iTolen: 16,
           lpOverlapped: nullptr,
           lpCompletionRoutine: nullptr) == 0
      && dwNumBytesSent == v8 + v29 + v28;
}

//------------------------------------------------------------------------------
// Address: 0x1002A040
// Name: IP_FloatTime
// Source: json
//------------------------------------------------------------------------------
long double __cdecl IP_FloatTime()
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier;
}

//------------------------------------------------------------------------------
// Address: 0x1002A0A0
// Name: public: virtual bool CIPSocket::CreateSocket(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::CreateSocket(CIPSocket *this)
{
  SOCKET m_Socket; // eax
  SOCKET v3; // edi
  unsigned int val; // [esp+8h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  if ( m_Socket != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: m_Socket, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  v3 = socket(af: 2, type: 2, protocol: 0);
  if ( v3 == -1 )
    return 0;
  val = 1;
  if ( ioctlsocket(s: v3, cmd: -2147195266, argp: &val) != 0 )
  {
    closesocket(s: v3);
    return 0;
  }
  this->m_Socket = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002A130
// Name: public: virtual bool CIPSocket::BindPart2(class CIPAddr const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIPSocket::BindPart2(CIPSocket *this, const CIPAddr *pAddr)
{
  u_short port; // cx
  u_short v4; // ax
  unsigned __int8 v5; // dl
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // dl
  SOCKET v9; // eax
  SOCKET m_Socket; // [esp-Ch] [ebp-24h]
  sockaddr_in addr; // [esp+8h] [ebp-10h] BYREF

  port = pAddr->port;
  *(_QWORD *)&addr.sin_family = 2;
  *(_QWORD *)addr.sin_zero = 0;
  v4 = htons(hostshort: port);
  v5 = pAddr->ip[0];
  v6 = pAddr->ip[2];
  addr.sin_port = v4;
  addr.sin_addr.S_un.S_un_b.s_b2 = pAddr->ip[1];
  addr.sin_addr.S_un.S_un_b.s_b1 = v5;
  v7 = pAddr->ip[3];
  addr.sin_addr.S_un.S_un_b.s_b3 = v6;
  m_Socket = this->m_Socket;
  addr.sin_addr.S_un.S_un_b.s_b4 = v7;
  if ( bind(s: m_Socket, name: (const struct sockaddr *)&addr, namelen: 16) == 0 )
    return 1;
  v9 = this->m_Socket;
  if ( v9 != -1 )
  {
    if ( this->m_bMulticastGroupMembership )
      setsockopt(s: v9, level: 0, optname: 13, optval: (const char *)&this->m_MulticastGroupMREQ, optlen: 8);
    closesocket(s: this->m_Socket);
    this->m_Socket = -1;
  }
  this->m_bSetupToBroadcast = false;
  this->m_bMulticastGroupMembership = false;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A1E0
// Name: public: virtual bool CIPSocket::BindToAny(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::BindToAny(CIPSocket *this, unsigned __int16 port)
{
  bool (__thiscall *Bind)(struct CIPSocket *, const CIPAddr *); // edx
  CIPAddr addr; // [esp+0h] [ebp-8h] BYREF

  Bind = this->Bind;
  addr.port = port;
  *(_DWORD *)addr.ip = 0;
  return Bind(this, a2: &addr);
}

//------------------------------------------------------------------------------
// Address: 0x1002A210
// Name: public: virtual bool CIPSocket::Broadcast(void const __near *,int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIPSocket::Broadcast(CIPSocket *this, const void *pData, int len, unsigned __int16 port)
{
  CIPSocket_vtbl *v6; // eax
  bool (__thiscall *SendTo)(struct CIPSocket *, const CIPAddr *, const void *, const int); // edx
  SOCKET m_Socket; // [esp-14h] [ebp-24h]
  CIPAddr addr; // [esp+4h] [ebp-Ch] BYREF
  int bBroadcast; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bSetupToBroadcast )
  {
    m_Socket = this->m_Socket;
    bBroadcast = 1;
    if ( setsockopt(s: m_Socket, level: 0xFFFF, optname: 32, optval: (const char *)&bBroadcast, optlen: 4) != 0 )
      return false;
    this->m_bSetupToBroadcast = true;
  }
  v6 = this->__vftable;
  addr.port = port;
  SendTo = v6->SendTo;
  *(_DWORD *)addr.ip = -1;
  return SendTo(this, a2: &addr, a3: pData, a4: len);
}

//------------------------------------------------------------------------------
// Address: 0x1002A280
// Name: public: virtual int CIPSocket::RecvFrom(void __near *,int,class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CIPSocket::RecvFrom(CIPSocket *this, char *pData, int maxDataLen, CIPAddr *pFrom)
{
  unsigned int m_Socket; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  SOCKET v10; // [esp-1Ch] [ebp-140h]
  fd_set readSet; // [esp+4h] [ebp-120h] BYREF
  sockaddr_in sender; // [esp+108h] [ebp-1Ch] BYREF
  timeval timeVal; // [esp+118h] [ebp-Ch] BYREF
  int fromSize; // [esp+120h] [ebp-4h] BYREF

  m_Socket = this->m_Socket;
  timeVal.tv_usec = 0;
  readSet.fd_array[0] = m_Socket;
  readSet.fd_count = 1;
  timeVal.tv_sec = 0;
  v6 = select(nfds: 0, readfds: &readSet, writefds: nullptr, exceptfds: nullptr, timeout: &timeVal);
  if ( v6 == 0 || v6 == -1 )
    return -1;
  v10 = this->m_Socket;
  fromSize = 16;
  v7 = recvfrom(s: v10, buf: pData, len: maxDataLen, flags: 0, from: (struct sockaddr *)&sender, fromlen: &fromSize);
  v8 = v7;
  if ( v7 == 0 || v7 == -1 )
    return -1;
  if ( pFrom != nullptr )
    SockAddrToIPAddr(pIn: &sender, pOut: pFrom);
  this->m_flLastRecvTime = IP_FloatTime();
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1002A330
// Name: public: virtual double CIPSocket::GetRecvTimeout(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CIPSocket::GetRecvTimeout(CIPSocket *this)
{
  return (double)__rdtsc() * _g_ClockSpeedSecondsMultiplier - this->m_flLastRecvTime;
}

//------------------------------------------------------------------------------
// Address: 0x1002A3F0
// Name: class ISocket __near * CreateIPSocket(void)
// Source: json
//------------------------------------------------------------------------------
ISocket *__cdecl CreateIPSocket()
{
  ISocket *result; // eax

  result = (ISocket *)operator new(size: 0x28u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (ISocket_vtbl *)&CIPSocket::`vftable';
  result[1].__vftable = (ISocket_vtbl *)-1;
  LOBYTE(result[5].__vftable) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002A420
// Name: class ISocket __near * CreateMulticastListenSocket(class CIPAddr const __near &,class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
ISocket *__cdecl CreateMulticastListenSocket(const CIPAddr *addr, const CIPAddr *localInterface)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax
  CIPAddr bindAddr; // [esp+Ch] [ebp-8h] BYREF

  v2 = operator new(size: 0x28u);
  if ( v2 != nullptr )
  {
    *v2 = &CIPSocket::`vftable';
    v2[1] = -1;
    *((_BYTE *)v2 + 20) = 0;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = *(_DWORD *)localInterface->ip;
  bindAddr.port = addr->port;
  *(_DWORD *)bindAddr.ip = v4;
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, CIPAddr *))(*v3 + 4))(a1: v3, a2: &bindAddr) != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD *, const CIPAddr *, const CIPAddr *))(*v3 + 44))(
         a1: v3,
         a2: addr,
         a3: localInterface) != 0 )
  {
    return (ISocket *)v3;
  }
  (*(void (__thiscall **)(_DWORD *))*v3)(a1: v3);
  return nullptr;
}

} // namespace vvis_dll
