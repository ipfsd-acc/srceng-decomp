// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/socketcreator.cpp
// Functions: 15
// ============================================================

#include "tier2\socketcreator.h"

//------------------------------------------------------------------------------
// Address: 0x1027E4C0
// Name: char const __near * NET_ErrorString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl NET_ErrorString(int code)
{
  const char *result; // eax

  if ( code > 11001 )
  {
    switch ( code )
    {
      case 11002:
        return "WSATRY_AGAIN";
      case 11003:
        return "WSANO_RECOVERY";
      case 11004:
        return "WSANO_DATA";
      default:
        return "UNKNOWN ERROR";
    }
  }
  else if ( code == 11001 )
  {
    return "WSAHOST_NOT_FOUND";
  }
  else
  {
    switch ( code )
    {
      case 10004:
        result = "WSAEINTR";
        break;
      case 10009:
        result = "WSAEBADF";
        break;
      case 10013:
        result = "WSAEACCES";
        break;
      case 10014:
        result = "WSAEFAULT";
        break;
      case 10022:
        result = "WSAEINVAL";
        break;
      case 10024:
        result = "WSAEMFILE";
        break;
      case 10035:
        result = "WSAEWOULDBLOCK";
        break;
      case 10036:
        result = "WSAEINPROGRESS";
        break;
      case 10037:
        result = "WSAEALREADY";
        break;
      case 10038:
        result = "WSAENOTSOCK";
        break;
      case 10039:
        result = "WSAEDESTADDRREQ";
        break;
      case 10040:
        result = "WSAEMSGSIZE";
        break;
      case 10041:
        result = "WSAEPROTOTYPE";
        break;
      case 10042:
        result = "WSAENOPROTOOPT";
        break;
      case 10043:
        result = "WSAEPROTONOSUPPORT";
        break;
      case 10044:
        result = "WSAESOCKTNOSUPPORT";
        break;
      case 10045:
        result = "WSAEOPNOTSUPP";
        break;
      case 10046:
        result = "WSAEPFNOSUPPORT";
        break;
      case 10047:
        result = "WSAEAFNOSUPPORT";
        break;
      case 10048:
        result = "WSAEADDRINUSE";
        break;
      case 10049:
        result = "WSAEADDRNOTAVAIL";
        break;
      case 10050:
        result = "WSAENETDOWN";
        break;
      case 10051:
        result = "WSAENETUNREACH";
        break;
      case 10052:
        result = "WSAENETRESET";
        break;
      case 10053:
        result = "WSWSAECONNABORTEDAEINTR";
        break;
      case 10054:
        result = "WSAECONNRESET";
        break;
      case 10055:
        result = "WSAENOBUFS";
        break;
      case 10056:
        result = "WSAEISCONN";
        break;
      case 10057:
        result = "WSAENOTCONN";
        break;
      case 10058:
        result = "WSAESHUTDOWN";
        break;
      case 10059:
        result = "WSAETOOMANYREFS";
        break;
      case 10060:
        result = "WSAETIMEDOUT";
        break;
      case 10061:
        result = "WSAECONNREFUSED";
        break;
      case 10062:
        result = "WSAELOOP";
        break;
      case 10063:
        result = "WSAENAMETOOLONG";
        break;
      case 10064:
        result = "WSAEHOSTDOWN";
        break;
      case 10091:
        result = "WSASYSNOTREADY";
        break;
      case 10092:
        result = "WSAVERNOTSUPPORTED";
        break;
      case 10093:
        result = "WSANOTINITIALISED";
        break;
      case 10101:
        result = "WSAEDISCON";
        break;
      default:
        return "UNKNOWN ERROR";
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027E750
// Name: bool SocketWouldBlock(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SocketWouldBlock()
{
  return WSAGetLastError() == 10035;
}

//------------------------------------------------------------------------------
// Address: 0x1027E760
// Name: private: bool CSocketCreator::ConfigureSocket(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSocketCreator::ConfigureSocket(CSocketCreator *this, SOCKET sock)
{
  SOCKET v2; // esi
  int Error; // eax
  int nodelay; // [esp+4h] [ebp-4h] BYREF

  v2 = sock;
  nodelay = 1;
  setsockopt(s: sock, level: 6, optname: 1, optval: (const char *)&nodelay, optlen: 4);
  nodelay = 1;
  setsockopt(s: v2, level: 0xFFFF, optname: 4, optval: (const char *)&nodelay, optlen: 4);
  sock = 1;
  if ( ioctlsocket(s: v2, cmd: -2147195266, argp: &sock) != -1 )
    return 1;
  Error = WSAGetLastError();
  _Warning(a1: "Socket accept ioctl(FIONBIO) failed (%i)\n", Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1027E7E0
// Name: public: void CSocketCreator::CloseListenSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::CloseListenSocket(CSocketCreator *this)
{
  if ( this->m_hListenSocket != -1 )
  {
    closesocket(s: this->m_hListenSocket);
    this->m_hListenSocket = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027E800
// Name: public: bool CSocketCreator::CreateListenSocket(struct netadr_s const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSocketCreator::CreateListenSocket(
        CSocketCreator *this,
        const netadr_s *netAdr,
        bool bListenOnAllInterfaces)
{
  SOCKET v4; // eax
  int Error; // eax
  const char *v6; // eax
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  sockaddr_in s; // [esp+Ch] [ebp-10h] BYREF

  if ( this->m_hListenSocket != -1 )
  {
    closesocket(s: this->m_hListenSocket);
    this->m_hListenSocket = -1;
  }
  this->m_ListenAddress = *netAdr;
  v4 = socket(af: 2, type: 1, protocol: 6);
  this->m_hListenSocket = v4;
  if ( v4 == -1 )
  {
    Error = WSAGetLastError();
    v6 = NET_ErrorString(code: Error);
    _Warning(a1: "Socket unable to create socket (%s)\n", v6);
    return 0;
  }
  if ( CSocketCreator::ConfigureSocket(this, sock: v4) == 0 )
    goto LABEL_10;
  netadr_s::ToSockadr(this: &this->m_ListenAddress, (sockaddr *)&s);
  if ( bListenOnAllInterfaces )
    s.sin_addr.S_un.S_addr = 0;
  if ( bind(s: this->m_hListenSocket, name: (const struct sockaddr *)&s, namelen: 16) == -1 )
  {
    v8 = WSAGetLastError();
    v9 = NET_ErrorString(code: v8);
    _Warning(a1: "Socket bind failed (%s)\n", v9);
LABEL_10:
    if ( this->m_hListenSocket != -1 )
    {
      closesocket(s: this->m_hListenSocket);
      this->m_hListenSocket = -1;
    }
    return 0;
  }
  if ( listen(s: this->m_hListenSocket, backlog: 2) != -1 )
    return 1;
  v10 = WSAGetLastError();
  v11 = NET_ErrorString(code: v10);
  _Warning(a1: "Socket listen failed (%s)\n", v11);
  if ( this->m_hListenSocket == -1 )
    return 0;
  closesocket(s: this->m_hListenSocket);
  this->m_hListenSocket = -1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1027E930
// Name: public: int CSocketCreator::GetAcceptedSocketHandle(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSocketCreator::GetAcceptedSocketHandle(CSocketCreator *this, int nIndex)
{
  return this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex].m_hSocket;
}

//------------------------------------------------------------------------------
// Address: 0x1027E950
// Name: public: struct netadr_s const __near & CSocketCreator::GetAcceptedSocketAddress(int)const
// Source: json
//------------------------------------------------------------------------------
const netadr_s *__thiscall CSocketCreator::GetAcceptedSocketAddress(CSocketCreator *this, int nIndex)
{
  return &this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex].m_Address;
}

//------------------------------------------------------------------------------
// Address: 0x1027E970
// Name: public: void __near * CSocketCreator::GetAcceptedSocketData(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CSocketCreator::GetAcceptedSocketData(CSocketCreator *this, int nIndex)
{
  return this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex].m_pData;
}

//------------------------------------------------------------------------------
// Address: 0x1027E990
// Name: public: void CSocketCreator::CloseAcceptedSocket(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::CloseAcceptedSocket(CSocketCreator *this, int nIndex)
{
  ISocketCreatorListener *m_pListener; // ecx
  CSocketCreator::AcceptedSocket_t *v4; // esi

  if ( nIndex < this->m_hAcceptedSockets.m_Size )
  {
    m_pListener = this->m_pListener;
    v4 = &this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex];
    if ( m_pListener != nullptr )
      m_pListener->OnSocketClosed(this: m_pListener, a2: v4->m_hSocket, a3: &v4->m_Address, a4: v4->m_pData);
    closesocket(s: v4->m_hSocket);
    if ( this->m_hAcceptedSockets.m_Size - nIndex - 1 > 0 )
      _V_memmove(
        dest: &this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex],
        src: &this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex + 1],
        count: 20 * (this->m_hAcceptedSockets.m_Size - nIndex - 1));
    --this->m_hAcceptedSockets.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027EA00
// Name: public: void CSocketCreator::CloseAllAcceptedSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::CloseAllAcceptedSockets(CSocketCreator *this)
{
  int v2; // edi
  CSocketCreator::AcceptedSocket_t *v3; // esi
  int m_Size; // [esp+8h] [ebp-4h]

  v2 = 0;
  if ( this->m_hAcceptedSockets.m_Size <= 0 )
  {
    this->m_hAcceptedSockets.m_Size = 0;
  }
  else
  {
    m_Size = this->m_hAcceptedSockets.m_Size;
    do
    {
      v3 = &this->m_hAcceptedSockets.m_Memory.m_pMemory[v2];
      if ( this->m_pListener != nullptr )
        this->m_pListener->OnSocketClosed(
          this: this->m_pListener,
          a2: v3->m_hSocket,
          a3: &v3->m_Address,
          a4: v3->m_pData);
      closesocket(s: v3->m_hSocket);
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
    this->m_hAcceptedSockets.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027EAF0
// Name: public: CSocketCreator::CSocketCreator(struct ISocketCreatorListener __near *)
// Source: json
//------------------------------------------------------------------------------
CSocketCreator *__thiscall CSocketCreator::CSocketCreator(CSocketCreator *this, ISocketCreatorListener *pListener)
{
  this->m_hAcceptedSockets.m_Memory.m_pMemory = nullptr;
  this->m_hAcceptedSockets.m_Memory.m_nAllocationCount = 0;
  this->m_hAcceptedSockets.m_Memory.m_nGrowSize = 0;
  this->m_hAcceptedSockets.m_Size = 0;
  this->m_hAcceptedSockets.m_pElements = nullptr;
  netadr_s::SetIP(this: &this->m_ListenAddress, unIP: 0);
  netadr_s::SetPort(this: &this->m_ListenAddress, newport: 0);
  netadr_s::SetType(this: &this->m_ListenAddress, newtype: NA_IP);
  this->m_pListener = pListener;
  this->m_hListenSocket = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1027EB40
// Name: public: CSocketCreator::~CSocketCreator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::~CSocketCreator(CSocketCreator *this)
{
  if ( this->m_hListenSocket != -1 )
  {
    closesocket(s: this->m_hListenSocket);
    this->m_hListenSocket = -1;
  }
  CSocketCreator::CloseAllAcceptedSockets(this);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_hAcceptedSockets);
}

//------------------------------------------------------------------------------
// Address: 0x1027EB70
// Name: private: void CSocketCreator::ProcessAccept(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::ProcessAccept(CSocketCreator *this)
{
  SOCKET v2; // eax
  SOCKET v3; // ebx
  int Error; // eax
  const char *v5; // eax
  CSocketCreator::AcceptedSocket_t *v6; // esi
  ISocketCreatorListener *m_pListener; // ecx
  SOCKET m_hListenSocket; // [esp-Ch] [ebp-38h]
  sockaddr sa; // [esp+8h] [ebp-24h] BYREF
  netadr_s adr; // [esp+18h] [ebp-14h] BYREF
  int nLengthAddr; // [esp+24h] [ebp-8h] BYREF
  void *pData; // [esp+28h] [ebp-4h] BYREF

  m_hListenSocket = this->m_hListenSocket;
  nLengthAddr = 16;
  v2 = accept(s: m_hListenSocket, addr: &sa, addrlen: &nLengthAddr);
  v3 = v2;
  if ( v2 == -1 )
  {
    if ( WSAGetLastError() != 10035 )
    {
      Error = WSAGetLastError();
      v5 = NET_ErrorString(code: Error);
      _Warning(a1: "Socket ProcessAccept Error: %s\n", v5);
    }
  }
  else if ( CSocketCreator::ConfigureSocket(this, sock: v2) != 0
         && ((netadr_s::SetIP(this: &adr, unIP: 0),
              netadr_s::SetPort(this: &adr, newport: 0),
              netadr_s::SetType(this: &adr, newtype: NA_IP),
              netadr_s::SetFromSockadr(this: &adr, s: &sa),
              this->m_pListener == nullptr)
          || ((int (__thiscall *)(ISocketCreatorListener *, SOCKET, netadr_s *))this->m_pListener->ShouldAcceptSocket)(
               a1: this->m_pListener,
               a2: v3,
               a3: &adr) != 0) )
  {
    v6 = &this->m_hAcceptedSockets.m_Memory.m_pMemory[CUtlVector<CSocketCreator::AcceptedSocket_t,CUtlMemory<CSocketCreator::AcceptedSocket_t,int>>::InsertBefore(
                                                        this: &this->m_hAcceptedSockets,
                                                        elem: this->m_hAcceptedSockets.m_Size)];
    v6->m_hSocket = v3;
    v6->m_Address = adr;
    v6->m_pData = nullptr;
    m_pListener = this->m_pListener;
    pData = nullptr;
    if ( m_pListener != nullptr )
      m_pListener->OnSocketAccepted(this: m_pListener, a2: v3, a3: &adr, a4: &pData);
    v6->m_pData = pData;
  }
  else
  {
    closesocket(s: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027EC80
// Name: public: int CSocketCreator::ConnectSocket(struct netadr_s const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSocketCreator::ConnectSocket(CSocketCreator *this, netadr_s *netAdr, void *bSingleSocket)
{
  unsigned int v3; // esi
  int Error; // eax
  const char *v5; // eax
  int v7; // eax
  const char *v8; // eax
  int v9; // eax
  const char *v10; // eax
  CSocketCreator *v11; // ebx
  int v12; // eax
  CSocketCreator::AcceptedSocket_t *m_pMemory; // edx
  int v14; // ebx
  CSocketCreator::AcceptedSocket_t *v15; // edi
  CSocketCreator *v16; // ecx
  ISocketCreatorListener *m_pListener; // ecx
  int m_Size; // [esp-10h] [ebp-138h]
  fd_set writefds; // [esp+0h] [ebp-128h] BYREF
  sockaddr_in s; // [esp+104h] [ebp-24h] BYREF
  timeval tv; // [esp+114h] [ebp-14h] BYREF
  int opt; // [esp+11Ch] [ebp-Ch] BYREF
  int nodelay; // [esp+120h] [ebp-8h] BYREF
  CSocketCreator *v24; // [esp+124h] [ebp-4h]

  v24 = this;
  if ( (_BYTE)bSingleSocket != 0 )
    CSocketCreator::CloseAllAcceptedSockets(this);
  v3 = socket(af: 2, type: 1, protocol: 6);
  if ( v3 == -1 )
  {
    Error = WSAGetLastError();
    v5 = NET_ErrorString(code: Error);
    _Warning(a1: "Unable to create socket (%s)\n", v5);
    return -1;
  }
  opt = 1;
  if ( ioctlsocket(s: v3, cmd: -2147195266, argp: (u_long *)&opt) == -1 )
  {
    v7 = WSAGetLastError();
    v8 = NET_ErrorString(code: v7);
    _Warning(a1: "Socket ioctl(FIONBIO) failed (%s)\n", v8);
    closesocket(s: v3);
    return -1;
  }
  nodelay = 1;
  setsockopt(s: v3, level: 6, optname: 1, optval: (const char *)&nodelay, optlen: 4);
  netadr_s::ToSockadr(this: netAdr, (sockaddr *)&s);
  if ( connect(s: v3, name: (const struct sockaddr *)&s, namelen: 16) == -1 )
  {
    if ( WSAGetLastError() != 10035 )
    {
      v9 = WSAGetLastError();
      v10 = NET_ErrorString(code: v9);
      _Warning(a1: "Socket connection failed (%s)\n", v10);
LABEL_10:
      closesocket(s: v3);
      return -1;
    }
    tv.tv_usec = 0;
    tv.tv_sec = 1;
    writefds.fd_array[0] = v3;
    writefds.fd_count = 1;
    if ( select(nfds: 1, readfds: nullptr, &writefds, exceptfds: nullptr, timeout: &tv) < 1 )
      goto LABEL_10;
  }
  v11 = v24;
  if ( v24->m_pListener != nullptr
    && ((unsigned int (__thiscall *)(ISocketCreatorListener *, unsigned int, netadr_s *))v24->m_pListener->ShouldAcceptSocket)(
         a1: v24->m_pListener,
         a2: v3,
         a3: netAdr) == 0 )
  {
    goto LABEL_10;
  }
  m_Size = v11->m_hAcceptedSockets.m_Size;
  bSingleSocket = nullptr;
  v12 = CUtlVector<CSocketCreator::AcceptedSocket_t,CUtlMemory<CSocketCreator::AcceptedSocket_t,int>>::InsertBefore(
          this: &v11->m_hAcceptedSockets,
          elem: m_Size);
  m_pMemory = v11->m_hAcceptedSockets.m_Memory.m_pMemory;
  v14 = v12;
  v15 = &m_pMemory[v12];
  v16 = v24;
  v15->m_hSocket = v3;
  v15->m_Address = *netAdr;
  v15->m_pData = nullptr;
  m_pListener = v16->m_pListener;
  if ( m_pListener != nullptr )
    m_pListener->OnSocketAccepted(this: m_pListener, a2: v3, a3: netAdr, a4: &bSingleSocket);
  v15->m_pData = bSingleSocket;
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x1027EE30
// Name: public: void CSocketCreator::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::RunFrame(CSocketCreator *this)
{
  if ( this->m_hListenSocket != -1 )
    CSocketCreator::ProcessAccept(this);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027E600
// Name: char const __near * NET_ErrorString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl NET_ErrorString(int code)
{
  const char *result; // eax

  if ( code > 11001 )
  {
    switch ( code )
    {
      case 11002:
        return "WSATRY_AGAIN";
      case 11003:
        return "WSANO_RECOVERY";
      case 11004:
        return "WSANO_DATA";
      default:
        return "UNKNOWN ERROR";
    }
  }
  else if ( code == 11001 )
  {
    return "WSAHOST_NOT_FOUND";
  }
  else
  {
    switch ( code )
    {
      case 10004:
        result = "WSAEINTR";
        break;
      case 10009:
        result = "WSAEBADF";
        break;
      case 10013:
        result = "WSAEACCES";
        break;
      case 10014:
        result = "WSAEFAULT";
        break;
      case 10022:
        result = "WSAEINVAL";
        break;
      case 10024:
        result = "WSAEMFILE";
        break;
      case 10035:
        result = "WSAEWOULDBLOCK";
        break;
      case 10036:
        result = "WSAEINPROGRESS";
        break;
      case 10037:
        result = "WSAEALREADY";
        break;
      case 10038:
        result = "WSAENOTSOCK";
        break;
      case 10039:
        result = "WSAEDESTADDRREQ";
        break;
      case 10040:
        result = "WSAEMSGSIZE";
        break;
      case 10041:
        result = "WSAEPROTOTYPE";
        break;
      case 10042:
        result = "WSAENOPROTOOPT";
        break;
      case 10043:
        result = "WSAEPROTONOSUPPORT";
        break;
      case 10044:
        result = "WSAESOCKTNOSUPPORT";
        break;
      case 10045:
        result = "WSAEOPNOTSUPP";
        break;
      case 10046:
        result = "WSAEPFNOSUPPORT";
        break;
      case 10047:
        result = "WSAEAFNOSUPPORT";
        break;
      case 10048:
        result = "WSAEADDRINUSE";
        break;
      case 10049:
        result = "WSAEADDRNOTAVAIL";
        break;
      case 10050:
        result = "WSAENETDOWN";
        break;
      case 10051:
        result = "WSAENETUNREACH";
        break;
      case 10052:
        result = "WSAENETRESET";
        break;
      case 10053:
        result = "WSWSAECONNABORTEDAEINTR";
        break;
      case 10054:
        result = "WSAECONNRESET";
        break;
      case 10055:
        result = "WSAENOBUFS";
        break;
      case 10056:
        result = "WSAEISCONN";
        break;
      case 10057:
        result = "WSAENOTCONN";
        break;
      case 10058:
        result = "WSAESHUTDOWN";
        break;
      case 10059:
        result = "WSAETOOMANYREFS";
        break;
      case 10060:
        result = "WSAETIMEDOUT";
        break;
      case 10061:
        result = "WSAECONNREFUSED";
        break;
      case 10062:
        result = "WSAELOOP";
        break;
      case 10063:
        result = "WSAENAMETOOLONG";
        break;
      case 10064:
        result = "WSAEHOSTDOWN";
        break;
      case 10091:
        result = "WSASYSNOTREADY";
        break;
      case 10092:
        result = "WSAVERNOTSUPPORTED";
        break;
      case 10093:
        result = "WSANOTINITIALISED";
        break;
      case 10101:
        result = "WSAEDISCON";
        break;
      default:
        return "UNKNOWN ERROR";
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027E890
// Name: bool SocketWouldBlock(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SocketWouldBlock()
{
  return WSAGetLastError() == 10035;
}

//------------------------------------------------------------------------------
// Address: 0x1027E8A0
// Name: private: bool CSocketCreator::ConfigureSocket(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSocketCreator::ConfigureSocket(CSocketCreator *this, SOCKET sock)
{
  SOCKET v2; // esi
  int Error; // eax
  int nodelay; // [esp+4h] [ebp-4h] BYREF

  v2 = sock;
  nodelay = 1;
  setsockopt(s: sock, level: 6, optname: 1, optval: (const char *)&nodelay, optlen: 4);
  nodelay = 1;
  setsockopt(s: v2, level: 0xFFFF, optname: 4, optval: (const char *)&nodelay, optlen: 4);
  sock = 1;
  if ( ioctlsocket(s: v2, cmd: -2147195266, argp: &sock) != -1 )
    return 1;
  Error = WSAGetLastError();
  _Warning(a1: "Socket accept ioctl(FIONBIO) failed (%i)\n", Error);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1027E920
// Name: public: void CSocketCreator::CloseListenSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::CloseListenSocket(CSocketCreator *this)
{
  if ( this->m_hListenSocket != -1 )
  {
    closesocket(s: this->m_hListenSocket);
    this->m_hListenSocket = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027E940
// Name: public: bool CSocketCreator::CreateListenSocket(struct netadr_s const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSocketCreator::CreateListenSocket(
        CSocketCreator *this,
        const netadr_s *netAdr,
        bool bListenOnAllInterfaces)
{
  SOCKET v4; // eax
  int Error; // eax
  const char *v6; // eax
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  sockaddr_in s; // [esp+Ch] [ebp-10h] BYREF

  if ( this->m_hListenSocket != -1 )
  {
    closesocket(s: this->m_hListenSocket);
    this->m_hListenSocket = -1;
  }
  this->m_ListenAddress = *netAdr;
  v4 = socket(af: 2, type: 1, protocol: 6);
  this->m_hListenSocket = v4;
  if ( v4 == -1 )
  {
    Error = WSAGetLastError();
    v6 = NET_ErrorString(code: Error);
    _Warning(a1: "Socket unable to create socket (%s)\n", v6);
    return 0;
  }
  if ( CSocketCreator::ConfigureSocket(this, sock: v4) == 0 )
    goto LABEL_10;
  netadr_s::ToSockadr(this: &this->m_ListenAddress, (sockaddr *)&s);
  if ( bListenOnAllInterfaces )
    s.sin_addr.S_un.S_addr = 0;
  if ( bind(s: this->m_hListenSocket, name: (const struct sockaddr *)&s, namelen: 16) == -1 )
  {
    v8 = WSAGetLastError();
    v9 = NET_ErrorString(code: v8);
    _Warning(a1: "Socket bind failed (%s)\n", v9);
LABEL_10:
    if ( this->m_hListenSocket != -1 )
    {
      closesocket(s: this->m_hListenSocket);
      this->m_hListenSocket = -1;
    }
    return 0;
  }
  if ( listen(s: this->m_hListenSocket, backlog: 2) != -1 )
    return 1;
  v10 = WSAGetLastError();
  v11 = NET_ErrorString(code: v10);
  _Warning(a1: "Socket listen failed (%s)\n", v11);
  if ( this->m_hListenSocket == -1 )
    return 0;
  closesocket(s: this->m_hListenSocket);
  this->m_hListenSocket = -1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1027EA80
// Name: public: int CSocketCreator::GetAcceptedSocketHandle(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSocketCreator::GetAcceptedSocketHandle(CSocketCreator *this, int nIndex)
{
  return this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex].m_hSocket;
}

//------------------------------------------------------------------------------
// Address: 0x1027EAA0
// Name: public: struct netadr_s const __near & CSocketCreator::GetAcceptedSocketAddress(int)const
// Source: json
//------------------------------------------------------------------------------
const netadr_s *__thiscall CSocketCreator::GetAcceptedSocketAddress(CSocketCreator *this, int nIndex)
{
  return &this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex].m_Address;
}

//------------------------------------------------------------------------------
// Address: 0x1027EAC0
// Name: public: void __near * CSocketCreator::GetAcceptedSocketData(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CSocketCreator::GetAcceptedSocketData(CSocketCreator *this, int nIndex)
{
  return this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex].m_pData;
}

//------------------------------------------------------------------------------
// Address: 0x1027EAE0
// Name: public: void CSocketCreator::CloseAcceptedSocket(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::CloseAcceptedSocket(CSocketCreator *this, int nIndex)
{
  ISocketCreatorListener *m_pListener; // ecx
  CSocketCreator::AcceptedSocket_t *v4; // esi

  if ( nIndex < this->m_hAcceptedSockets.m_Size )
  {
    m_pListener = this->m_pListener;
    v4 = &this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex];
    if ( m_pListener != nullptr )
      m_pListener->OnSocketClosed(this: m_pListener, a2: v4->m_hSocket, a3: &v4->m_Address, a4: v4->m_pData);
    closesocket(s: v4->m_hSocket);
    if ( this->m_hAcceptedSockets.m_Size - nIndex - 1 > 0 )
      _V_memmove(
        dest: &this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex],
        src: &this->m_hAcceptedSockets.m_Memory.m_pMemory[nIndex + 1],
        count: 20 * (this->m_hAcceptedSockets.m_Size - nIndex - 1));
    --this->m_hAcceptedSockets.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027EB50
// Name: public: void CSocketCreator::CloseAllAcceptedSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::CloseAllAcceptedSockets(CSocketCreator *this)
{
  int v2; // edi
  CSocketCreator::AcceptedSocket_t *v3; // esi
  int m_Size; // [esp+8h] [ebp-4h]

  v2 = 0;
  if ( this->m_hAcceptedSockets.m_Size <= 0 )
  {
    this->m_hAcceptedSockets.m_Size = 0;
  }
  else
  {
    m_Size = this->m_hAcceptedSockets.m_Size;
    do
    {
      v3 = &this->m_hAcceptedSockets.m_Memory.m_pMemory[v2];
      if ( this->m_pListener != nullptr )
        this->m_pListener->OnSocketClosed(
          this: this->m_pListener,
          a2: v3->m_hSocket,
          a3: &v3->m_Address,
          a4: v3->m_pData);
      closesocket(s: v3->m_hSocket);
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
    this->m_hAcceptedSockets.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027EC40
// Name: public: CSocketCreator::CSocketCreator(struct ISocketCreatorListener __near *)
// Source: json
//------------------------------------------------------------------------------
CSocketCreator *__thiscall CSocketCreator::CSocketCreator(CSocketCreator *this, ISocketCreatorListener *pListener)
{
  this->m_hAcceptedSockets.m_Memory.m_pMemory = nullptr;
  this->m_hAcceptedSockets.m_Memory.m_nAllocationCount = 0;
  this->m_hAcceptedSockets.m_Memory.m_nGrowSize = 0;
  this->m_hAcceptedSockets.m_Size = 0;
  this->m_hAcceptedSockets.m_pElements = nullptr;
  netadr_s::SetIP(this: &this->m_ListenAddress, unIP: 0);
  netadr_s::SetPort(this: &this->m_ListenAddress, newport: 0);
  netadr_s::SetType(this: &this->m_ListenAddress, newtype: NA_IP);
  this->m_pListener = pListener;
  this->m_hListenSocket = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1027EC90
// Name: public: CSocketCreator::~CSocketCreator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::~CSocketCreator(CSocketCreator *this)
{
  if ( this->m_hListenSocket != -1 )
  {
    closesocket(s: this->m_hListenSocket);
    this->m_hListenSocket = -1;
  }
  CSocketCreator::CloseAllAcceptedSockets(this);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_hAcceptedSockets);
}

//------------------------------------------------------------------------------
// Address: 0x1027ECC0
// Name: private: void CSocketCreator::ProcessAccept(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::ProcessAccept(CSocketCreator *this)
{
  SOCKET v2; // eax
  SOCKET v3; // ebx
  int Error; // eax
  const char *v5; // eax
  CSocketCreator::AcceptedSocket_t *v6; // esi
  ISocketCreatorListener *m_pListener; // ecx
  SOCKET m_hListenSocket; // [esp-Ch] [ebp-38h]
  sockaddr sa; // [esp+8h] [ebp-24h] BYREF
  netadr_s adr; // [esp+18h] [ebp-14h] BYREF
  int nLengthAddr; // [esp+24h] [ebp-8h] BYREF
  void *pData; // [esp+28h] [ebp-4h] BYREF

  m_hListenSocket = this->m_hListenSocket;
  nLengthAddr = 16;
  v2 = accept(s: m_hListenSocket, addr: &sa, addrlen: &nLengthAddr);
  v3 = v2;
  if ( v2 == -1 )
  {
    if ( WSAGetLastError() != 10035 )
    {
      Error = WSAGetLastError();
      v5 = NET_ErrorString(code: Error);
      _Warning(a1: "Socket ProcessAccept Error: %s\n", v5);
    }
  }
  else if ( CSocketCreator::ConfigureSocket(this, sock: v2) != 0
         && ((netadr_s::SetIP(this: &adr, unIP: 0),
              netadr_s::SetPort(this: &adr, newport: 0),
              netadr_s::SetType(this: &adr, newtype: NA_IP),
              netadr_s::SetFromSockadr(this: &adr, s: &sa),
              this->m_pListener == nullptr)
          || ((int (__thiscall *)(ISocketCreatorListener *, SOCKET, netadr_s *))this->m_pListener->ShouldAcceptSocket)(
               a1: this->m_pListener,
               a2: v3,
               a3: &adr) != 0) )
  {
    v6 = &this->m_hAcceptedSockets.m_Memory.m_pMemory[CUtlVector<CSocketCreator::AcceptedSocket_t,CUtlMemory<CSocketCreator::AcceptedSocket_t,int>>::InsertBefore(
                                                        this: &this->m_hAcceptedSockets,
                                                        elem: this->m_hAcceptedSockets.m_Size)];
    v6->m_hSocket = v3;
    v6->m_Address = adr;
    v6->m_pData = nullptr;
    m_pListener = this->m_pListener;
    pData = nullptr;
    if ( m_pListener != nullptr )
      m_pListener->OnSocketAccepted(this: m_pListener, a2: v3, a3: &adr, a4: &pData);
    v6->m_pData = pData;
  }
  else
  {
    closesocket(s: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027EDD0
// Name: public: int CSocketCreator::ConnectSocket(struct netadr_s const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSocketCreator::ConnectSocket(CSocketCreator *this, netadr_s *netAdr, void *bSingleSocket)
{
  unsigned int v3; // esi
  int Error; // eax
  const char *v5; // eax
  int v7; // eax
  const char *v8; // eax
  int v9; // eax
  const char *v10; // eax
  CSocketCreator *v11; // ebx
  int v12; // eax
  CSocketCreator::AcceptedSocket_t *m_pMemory; // edx
  int v14; // ebx
  CSocketCreator::AcceptedSocket_t *v15; // edi
  CSocketCreator *v16; // ecx
  ISocketCreatorListener *m_pListener; // ecx
  int m_Size; // [esp-10h] [ebp-138h]
  fd_set writefds; // [esp+0h] [ebp-128h] BYREF
  sockaddr_in s; // [esp+104h] [ebp-24h] BYREF
  timeval tv; // [esp+114h] [ebp-14h] BYREF
  int opt; // [esp+11Ch] [ebp-Ch] BYREF
  int nodelay; // [esp+120h] [ebp-8h] BYREF
  CSocketCreator *v24; // [esp+124h] [ebp-4h]

  v24 = this;
  if ( (_BYTE)bSingleSocket != 0 )
    CSocketCreator::CloseAllAcceptedSockets(this);
  v3 = socket(af: 2, type: 1, protocol: 6);
  if ( v3 == -1 )
  {
    Error = WSAGetLastError();
    v5 = NET_ErrorString(code: Error);
    _Warning(a1: "Unable to create socket (%s)\n", v5);
    return -1;
  }
  opt = 1;
  if ( ioctlsocket(s: v3, cmd: -2147195266, argp: (u_long *)&opt) == -1 )
  {
    v7 = WSAGetLastError();
    v8 = NET_ErrorString(code: v7);
    _Warning(a1: "Socket ioctl(FIONBIO) failed (%s)\n", v8);
    closesocket(s: v3);
    return -1;
  }
  nodelay = 1;
  setsockopt(s: v3, level: 6, optname: 1, optval: (const char *)&nodelay, optlen: 4);
  netadr_s::ToSockadr(this: netAdr, (sockaddr *)&s);
  if ( connect(s: v3, name: (const struct sockaddr *)&s, namelen: 16) == -1 )
  {
    if ( WSAGetLastError() != 10035 )
    {
      v9 = WSAGetLastError();
      v10 = NET_ErrorString(code: v9);
      _Warning(a1: "Socket connection failed (%s)\n", v10);
LABEL_10:
      closesocket(s: v3);
      return -1;
    }
    tv.tv_usec = 0;
    tv.tv_sec = 1;
    writefds.fd_array[0] = v3;
    writefds.fd_count = 1;
    if ( select(nfds: 1, readfds: nullptr, &writefds, exceptfds: nullptr, timeout: &tv) < 1 )
      goto LABEL_10;
  }
  v11 = v24;
  if ( v24->m_pListener != nullptr
    && ((unsigned int (__thiscall *)(ISocketCreatorListener *, unsigned int, netadr_s *))v24->m_pListener->ShouldAcceptSocket)(
         a1: v24->m_pListener,
         a2: v3,
         a3: netAdr) == 0 )
  {
    goto LABEL_10;
  }
  m_Size = v11->m_hAcceptedSockets.m_Size;
  bSingleSocket = nullptr;
  v12 = CUtlVector<CSocketCreator::AcceptedSocket_t,CUtlMemory<CSocketCreator::AcceptedSocket_t,int>>::InsertBefore(
          this: &v11->m_hAcceptedSockets,
          elem: m_Size);
  m_pMemory = v11->m_hAcceptedSockets.m_Memory.m_pMemory;
  v14 = v12;
  v15 = &m_pMemory[v12];
  v16 = v24;
  v15->m_hSocket = v3;
  v15->m_Address = *netAdr;
  v15->m_pData = nullptr;
  m_pListener = v16->m_pListener;
  if ( m_pListener != nullptr )
    m_pListener->OnSocketAccepted(this: m_pListener, a2: v3, a3: netAdr, a4: &bSingleSocket);
  v15->m_pData = bSingleSocket;
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x1027EF80
// Name: public: void CSocketCreator::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketCreator::RunFrame(CSocketCreator *this)
{
  if ( this->m_hListenSocket != -1 )
    CSocketCreator::ProcessAccept(this);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from networksystem (Missing functions)
// ============================================================
namespace networksystem {

//------------------------------------------------------------------------------
// Address: 0x10018280
// Name: char const __near * SocketErrorString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl SocketErrorString(int code)
{
  const char *result; // eax

  if ( code > 11001 )
  {
    switch ( code )
    {
      case 11002:
        return "WSATRY_AGAIN";
      case 11003:
        return "WSANO_RECOVERY";
      case 11004:
        return "WSANO_DATA";
      default:
        return "UNKNOWN ERROR";
    }
  }
  else if ( code == 11001 )
  {
    return "WSAHOST_NOT_FOUND";
  }
  else
  {
    switch ( code )
    {
      case 10004:
        result = "WSAEINTR";
        break;
      case 10009:
        result = "WSAEBADF";
        break;
      case 10013:
        result = "WSAEACCES";
        break;
      case 10014:
        result = "WSAEFAULT";
        break;
      case 10022:
        result = "WSAEINVAL";
        break;
      case 10024:
        result = "WSAEMFILE";
        break;
      case 10035:
        result = "WSAEWOULDBLOCK";
        break;
      case 10036:
        result = "WSAEINPROGRESS";
        break;
      case 10037:
        result = "WSAEALREADY";
        break;
      case 10038:
        result = "WSAENOTSOCK";
        break;
      case 10039:
        result = "WSAEDESTADDRREQ";
        break;
      case 10040:
        result = "WSAEMSGSIZE";
        break;
      case 10041:
        result = "WSAEPROTOTYPE";
        break;
      case 10042:
        result = "WSAENOPROTOOPT";
        break;
      case 10043:
        result = "WSAEPROTONOSUPPORT";
        break;
      case 10044:
        result = "WSAESOCKTNOSUPPORT";
        break;
      case 10045:
        result = "WSAEOPNOTSUPP";
        break;
      case 10046:
        result = "WSAEPFNOSUPPORT";
        break;
      case 10047:
        result = "WSAEAFNOSUPPORT";
        break;
      case 10048:
        result = "WSAEADDRINUSE";
        break;
      case 10049:
        result = "WSAEADDRNOTAVAIL";
        break;
      case 10050:
        result = "WSAENETDOWN";
        break;
      case 10051:
        result = "WSAENETUNREACH";
        break;
      case 10052:
        result = "WSAENETRESET";
        break;
      case 10053:
        result = "WSWSAECONNABORTEDAEINTR";
        break;
      case 10054:
        result = "WSAECONNRESET";
        break;
      case 10055:
        result = "WSAENOBUFS";
        break;
      case 10056:
        result = "WSAEISCONN";
        break;
      case 10057:
        result = "WSAENOTCONN";
        break;
      case 10058:
        result = "WSAESHUTDOWN";
        break;
      case 10059:
        result = "WSAETOOMANYREFS";
        break;
      case 10060:
        result = "WSAETIMEDOUT";
        break;
      case 10061:
        result = "WSAECONNREFUSED";
        break;
      case 10062:
        result = "WSAELOOP";
        break;
      case 10063:
        result = "WSAENAMETOOLONG";
        break;
      case 10064:
        result = "WSAEHOSTDOWN";
        break;
      case 10091:
        result = "WSASYSNOTREADY";
        break;
      case 10092:
        result = "WSAVERNOTSUPPORTED";
        break;
      case 10093:
        result = "WSANOTINITIALISED";
        break;
      case 10101:
        result = "WSAEDISCON";
        break;
      default:
        return "UNKNOWN ERROR";
    }
  }
  return result;
}

} // namespace networksystem
