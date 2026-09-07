// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/blockingudpsocket.cpp
// Functions: 5
// ============================================================

#include "public\blockingudpsocket.h"

//------------------------------------------------------------------------------
// Address: 0x1013C1E0
// Name: public: virtual CBlockingUDPSocket::~CBlockingUDPSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlockingUDPSocket::~CBlockingUDPSocket(CBlockingUDPSocket *this)
{
  CBlockingUDPSocket::CImpl *m_pImpl; // [esp-4h] [ebp-8h]

  m_pImpl = this->m_pImpl;
  this->__vftable = (CBlockingUDPSocket_vtbl *)&CBlockingUDPSocket::`vftable';
  free(pMem: m_pImpl);
  closesocket(s: this->m_Socket);
}

//------------------------------------------------------------------------------
// Address: 0x1013C200
// Name: public: bool CBlockingUDPSocket::WaitForMessage(float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBlockingUDPSocket::WaitForMessage(CBlockingUDPSocket *this, float timeOutInSeconds)
{
  CBlockingUDPSocket::CImpl *m_pImpl; // ecx
  CBlockingUDPSocket::CImpl *v4; // ecx
  timeval tv; // [esp+4h] [ebp-8h] BYREF

  this->m_pImpl->m_FDSet.fd_count = 0;
  m_pImpl = this->m_pImpl;
  if ( m_pImpl->m_FDSet.fd_count < 0x40 )
  {
    m_pImpl->m_FDSet.fd_array[m_pImpl->m_FDSet.fd_count] = this->m_Socket;
    ++this->m_pImpl->m_FDSet.fd_count;
  }
  v4 = this->m_pImpl;
  tv.tv_sec = (int)timeOutInSeconds;
  tv.tv_usec = (int)(float)((float)((float)(timeOutInSeconds - (float)(int)timeOutInSeconds) * 1000000.0) + 0.5);
  return select(nfds: this->m_Socket + 1, readfds: &v4->m_FDSet, writefds: nullptr, exceptfds: nullptr, timeout: &tv) != -1
      && __WSAFDIsSet(fd: this->m_Socket, a2: &this->m_pImpl->m_FDSet) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013C2A0
// Name: public: unsigned int CBlockingUDPSocket::ReceiveSocketMessage(struct sockaddr_in __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBlockingUDPSocket::ReceiveSocketMessage(
        CBlockingUDPSocket *this,
        int packet_from,
        unsigned __int8 *buf,
        unsigned int bufsize)
{
  sockaddr_in *v4; // esi
  char *v5; // edi
  int result; // eax
  int v7; // edx
  in_addr::<unnamed_type_S_un> v8; // ecx
  int v9; // edx
  int v10; // ecx
  SOCKET m_Socket; // [esp-18h] [ebp-30h]
  sockaddr fromaddress; // [esp+8h] [ebp-10h] BYREF

  v4 = (sockaddr_in *)packet_from;
  *(_DWORD *)packet_from = 0;
  v4->sin_addr.S_un.S_addr = 0;
  v5 = (char *)buf;
  *(_DWORD *)v4->sin_zero = 0;
  *(_DWORD *)&v4->sin_zero[4] = 0;
  m_Socket = this->m_Socket;
  packet_from = 16;
  result = recvfrom(s: m_Socket, buf: v5, len: bufsize, flags: 0, from: &fromaddress, fromlen: &packet_from);
  if ( result == -1 )
    return 0;
  v7 = *(_DWORD *)&fromaddress.sa_family;
  v8 = *(in_addr::<unnamed_type_S_un> *)&fromaddress.sa_data[2];
  v5[result] = 0;
  *(_DWORD *)&v4->sin_family = v7;
  v9 = *(_DWORD *)&fromaddress.sa_data[6];
  v4->sin_addr.S_un = v8;
  v10 = *(_DWORD *)&fromaddress.sa_data[10];
  *(_DWORD *)v4->sin_zero = v9;
  *(_DWORD *)&v4->sin_zero[4] = v10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013C310
// Name: public: bool CBlockingUDPSocket::SendSocketMessage(struct sockaddr_in const __near &,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBlockingUDPSocket::SendSocketMessage(
        CBlockingUDPSocket *this,
        const sockaddr_in *rRecipient,
        const unsigned __int8 *buf,
        unsigned int bufsize)
{
  return sendto(
           s: this->m_Socket,
           (const char *)buf,
           len: bufsize,
           flags: 0,
           to: (const struct sockaddr *)rRecipient,
           tolen: 16) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x1013C340
// Name: public: CBlockingUDPSocket::CBlockingUDPSocket(void)
// Source: json
//------------------------------------------------------------------------------
CBlockingUDPSocket *__thiscall CBlockingUDPSocket::CBlockingUDPSocket(CBlockingUDPSocket *this)
{
  SOCKET v2; // eax
  CBlockingUDPSocket::CImpl *m_pImpl; // eax
  struct sockaddr name; // [esp+8h] [ebp-10h] BYREF

  this->__vftable = (CBlockingUDPSocket_vtbl *)&CBlockingUDPSocket::`vftable';
  this->m_pImpl = (CBlockingUDPSocket::CImpl *)MemAlloc_Alloc(nSize: 0x114u);
  netadr_s::SetIP(this: &this->m_cserIP, unIP: 0);
  netadr_s::SetPort(this: &this->m_cserIP, newport: 0);
  netadr_s::SetType(this: &this->m_cserIP, newtype: NA_IP);
  this->m_Socket = 0;
  v2 = socket(af: 2, type: 2, protocol: 17);
  this->m_Socket = v2;
  if ( v2 != -1 )
  {
    name = (struct sockaddr)this->m_pImpl->m_SocketIP;
    if ( bind(s: v2, &name, namelen: 16) != -1 )
    {
      m_pImpl = this->m_pImpl;
      if ( m_pImpl->m_SocketIP.sin_addr.S_un.S_addr == 0 )
        m_pImpl->m_SocketIP.sin_addr.S_un.S_addr = 0;
    }
  }
  return this;
}

// ============================================================
// Overlay from bugreporter_public (Missing functions)
// ============================================================
namespace bugreporter_public {

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: public: netadr_s::netadr_s(void)
// Source: json
//------------------------------------------------------------------------------
netadr_s *__thiscall netadr_s::netadr_s(netadr_s *this)
{
  netadr_s::SetIP(this, unIP: 0);
  netadr_s::SetPort(this, newport: 0);
  netadr_s::SetType(this, newtype: NA_IP);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001020
// Name: public: virtual CBlockingUDPSocket::~CBlockingUDPSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlockingUDPSocket::~CBlockingUDPSocket(CBlockingUDPSocket *this)
{
  CBlockingUDPSocket::CImpl *m_pImpl; // [esp-4h] [ebp-8h]

  m_pImpl = this->m_pImpl;
  this->__vftable = (CBlockingUDPSocket_vtbl *)&CBlockingUDPSocket::`vftable';
  free(pMem: m_pImpl);
  closesocket(s: this->m_Socket);
}

//------------------------------------------------------------------------------
// Address: 0x10001040
// Name: public: bool CBlockingUDPSocket::WaitForMessage(float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBlockingUDPSocket::WaitForMessage(CBlockingUDPSocket *this, float timeOutInSeconds)
{
  CBlockingUDPSocket::CImpl *m_pImpl; // ecx
  CBlockingUDPSocket::CImpl *v4; // ecx
  timeval tv; // [esp+4h] [ebp-8h] BYREF

  this->m_pImpl->m_FDSet.fd_count = 0;
  m_pImpl = this->m_pImpl;
  if ( m_pImpl->m_FDSet.fd_count < 0x40 )
  {
    m_pImpl->m_FDSet.fd_array[m_pImpl->m_FDSet.fd_count] = this->m_Socket;
    ++this->m_pImpl->m_FDSet.fd_count;
  }
  v4 = this->m_pImpl;
  tv.tv_sec = (int)timeOutInSeconds;
  tv.tv_usec = (int)(float)((float)((float)(timeOutInSeconds - (float)(int)timeOutInSeconds) * 1000000.0) + 0.5);
  return select(nfds: this->m_Socket + 1, readfds: &v4->m_FDSet, writefds: nullptr, exceptfds: nullptr, timeout: &tv) != -1
      && __WSAFDIsSet(fd: this->m_Socket, a2: &this->m_pImpl->m_FDSet) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100010E0
// Name: public: unsigned int CBlockingUDPSocket::ReceiveSocketMessage(struct sockaddr_in __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBlockingUDPSocket::ReceiveSocketMessage(
        CBlockingUDPSocket *this,
        int packet_from,
        unsigned __int8 *buf,
        unsigned int bufsize)
{
  sockaddr_in *v4; // esi
  char *v5; // edi
  int v6; // eax
  int result; // eax
  __int64 v8; // xmm0_8
  SOCKET m_Socket; // [esp-18h] [ebp-30h]
  sockaddr fromaddress; // [esp+8h] [ebp-10h] BYREF

  v4 = (sockaddr_in *)packet_from;
  v5 = (char *)buf;
  v6 = bufsize;
  *(_QWORD *)packet_from = 0;
  *(_QWORD *)v4->sin_zero = 0;
  m_Socket = this->m_Socket;
  packet_from = 16;
  result = recvfrom(s: m_Socket, buf: v5, len: v6, flags: 0, from: &fromaddress, fromlen: &packet_from);
  if ( result == -1 )
    return 0;
  v8 = *(_QWORD *)&fromaddress.sa_family;
  v5[result] = 0;
  *(_QWORD *)&v4->sin_family = v8;
  *(_QWORD *)v4->sin_zero = *(_QWORD *)&fromaddress.sa_data[6];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001150
// Name: public: bool CBlockingUDPSocket::SendSocketMessage(struct sockaddr_in const __near &,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBlockingUDPSocket::SendSocketMessage(
        CBlockingUDPSocket *this,
        const sockaddr_in *rRecipient,
        const unsigned __int8 *buf,
        unsigned int bufsize)
{
  return sendto(
           s: this->m_Socket,
           (const char *)buf,
           len: bufsize,
           flags: 0,
           to: (const struct sockaddr *)rRecipient,
           tolen: 16) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001180
// Name: public: CBlockingUDPSocket::CBlockingUDPSocket(void)
// Source: json
//------------------------------------------------------------------------------
CBlockingUDPSocket *__thiscall CBlockingUDPSocket::CBlockingUDPSocket(CBlockingUDPSocket *this)
{
  SOCKET v2; // eax
  CBlockingUDPSocket::CImpl *m_pImpl; // eax
  struct sockaddr name; // [esp+8h] [ebp-10h] BYREF

  this->__vftable = (CBlockingUDPSocket_vtbl *)&CBlockingUDPSocket::`vftable';
  this->m_pImpl = (CBlockingUDPSocket::CImpl *)operator new(nSize: 0x114u);
  netadr_s::SetIP(this: &this->m_cserIP, unIP: 0);
  netadr_s::SetPort(this: &this->m_cserIP, newport: 0);
  netadr_s::SetType(this: &this->m_cserIP, newtype: NA_IP);
  this->m_Socket = 0;
  v2 = socket(af: 2, type: 2, protocol: 17);
  this->m_Socket = v2;
  if ( v2 != -1 )
  {
    name = (struct sockaddr)this->m_pImpl->m_SocketIP;
    if ( bind(s: v2, &name, namelen: 16) != -1 )
    {
      m_pImpl = this->m_pImpl;
      if ( m_pImpl->m_SocketIP.sin_addr.S_un.S_addr == 0 )
        m_pImpl->m_SocketIP.sin_addr.S_un.S_addr = 0;
    }
  }
  return this;
}

} // namespace bugreporter_public

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1013C2F0
// Name: public: virtual CBlockingUDPSocket::~CBlockingUDPSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlockingUDPSocket::~CBlockingUDPSocket(CBlockingUDPSocket *this)
{
  CBlockingUDPSocket::CImpl *m_pImpl; // [esp-4h] [ebp-8h]

  m_pImpl = this->m_pImpl;
  this->__vftable = (CBlockingUDPSocket_vtbl *)&CBlockingUDPSocket::`vftable';
  free(pMem: m_pImpl);
  closesocket(s: this->m_Socket);
}

//------------------------------------------------------------------------------
// Address: 0x1013C3B0
// Name: public: unsigned int CBlockingUDPSocket::ReceiveSocketMessage(struct sockaddr_in __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBlockingUDPSocket::ReceiveSocketMessage(
        CBlockingUDPSocket *this,
        int packet_from,
        unsigned __int8 *buf,
        unsigned int bufsize)
{
  sockaddr_in *v4; // esi
  char *v5; // edi
  int result; // eax
  int v7; // edx
  in_addr::<unnamed_type_S_un> v8; // ecx
  int v9; // edx
  int v10; // ecx
  SOCKET m_Socket; // [esp-18h] [ebp-30h]
  sockaddr fromaddress; // [esp+8h] [ebp-10h] BYREF

  v4 = (sockaddr_in *)packet_from;
  *(_DWORD *)packet_from = 0;
  v4->sin_addr.S_un.S_addr = 0;
  v5 = (char *)buf;
  *(_DWORD *)v4->sin_zero = 0;
  *(_DWORD *)&v4->sin_zero[4] = 0;
  m_Socket = this->m_Socket;
  packet_from = 16;
  result = recvfrom(s: m_Socket, buf: v5, len: bufsize, flags: 0, from: &fromaddress, fromlen: &packet_from);
  if ( result == -1 )
    return 0;
  v7 = *(_DWORD *)&fromaddress.sa_family;
  v8 = *(in_addr::<unnamed_type_S_un> *)&fromaddress.sa_data[2];
  v5[result] = 0;
  *(_DWORD *)&v4->sin_family = v7;
  v9 = *(_DWORD *)&fromaddress.sa_data[6];
  v4->sin_addr.S_un = v8;
  v10 = *(_DWORD *)&fromaddress.sa_data[10];
  *(_DWORD *)v4->sin_zero = v9;
  *(_DWORD *)&v4->sin_zero[4] = v10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013C420
// Name: public: bool CBlockingUDPSocket::SendSocketMessage(struct sockaddr_in const __near &,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBlockingUDPSocket::SendSocketMessage(
        CBlockingUDPSocket *this,
        const sockaddr_in *rRecipient,
        const unsigned __int8 *buf,
        unsigned int bufsize)
{
  return sendto(
           s: this->m_Socket,
           (const char *)buf,
           len: bufsize,
           flags: 0,
           to: (const struct sockaddr *)rRecipient,
           tolen: 16) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x1013C450
// Name: public: CBlockingUDPSocket::CBlockingUDPSocket(void)
// Source: json
//------------------------------------------------------------------------------
CBlockingUDPSocket *__thiscall CBlockingUDPSocket::CBlockingUDPSocket(CBlockingUDPSocket *this)
{
  SOCKET v2; // eax
  CBlockingUDPSocket::CImpl *m_pImpl; // eax
  struct sockaddr name; // [esp+8h] [ebp-10h] BYREF

  this->__vftable = (CBlockingUDPSocket_vtbl *)&CBlockingUDPSocket::`vftable';
  this->m_pImpl = (CBlockingUDPSocket::CImpl *)MemAlloc_Alloc(nSize: 0x114u);
  netadr_s::SetIP(this: &this->m_cserIP, unIP: 0);
  netadr_s::SetPort(this: &this->m_cserIP, newport: 0);
  netadr_s::SetType(this: &this->m_cserIP, newtype: NA_IP);
  this->m_Socket = 0;
  v2 = socket(af: 2, type: 2, protocol: 17);
  this->m_Socket = v2;
  if ( v2 != -1 )
  {
    name = (struct sockaddr)this->m_pImpl->m_SocketIP;
    if ( bind(s: v2, &name, namelen: 16) != -1 )
    {
      m_pImpl = this->m_pImpl;
      if ( m_pImpl->m_SocketIP.sin_addr.S_un.S_addr == 0 )
        m_pImpl->m_SocketIP.sin_addr.S_un.S_addr = 0;
    }
  }
  return this;
}

} // namespace engine_xlsp
