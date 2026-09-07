// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: _libs/mod0318_Import:WSOCK32.cpp
// Functions: 20
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10211E1A
// Name: gethostname(x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall gethostname(char *name, int namelen)
{
  return __imp__gethostname@8(name, namelen);
}

//------------------------------------------------------------------------------
// Address: 0x10211E20
// Name: send(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall send(SOCKET s, const char *buf, int len, int flags)
{
  return __imp__send@16(s, buf, len, flags);
}

//------------------------------------------------------------------------------
// Address: 0x10211E26
// Name: ioctlsocket(x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall ioctlsocket(SOCKET s, int cmd, u_long *argp)
{
  return __imp__ioctlsocket@12(s, cmd, argp);
}

//------------------------------------------------------------------------------
// Address: 0x10211E2C
// Name: WSAGetLastError()
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall WSAGetLastError()
{
  return __imp__WSAGetLastError@0();
}

//------------------------------------------------------------------------------
// Address: 0x10211E32
// Name: recv(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall recv(SOCKET s, char *buf, int len, int flags)
{
  return __imp__recv@16(s, buf, len, flags);
}

//------------------------------------------------------------------------------
// Address: 0x10211E38
// Name: ntohl(x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
u_long __stdcall ntohl(u_long netlong)
{
  return __imp__ntohl@4(netlong);
}

//------------------------------------------------------------------------------
// Address: 0x10211E3E
// Name: htonl(x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
u_long __stdcall htonl(u_long hostlong)
{
  return __imp__htonl@4(hostlong);
}

//------------------------------------------------------------------------------
// Address: 0x10211E44
// Name: socket(x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
SOCKET __stdcall socket(int af, int type, int protocol)
{
  return __imp__socket@12(af, type, protocol);
}

//------------------------------------------------------------------------------
// Address: 0x10211E50
// Name: closesocket(x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall closesocket(SOCKET s)
{
  return __imp__closesocket@4(s);
}

//------------------------------------------------------------------------------
// Address: 0x10211E56
// Name: htons(x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
u_short __stdcall htons(u_short hostshort)
{
  return __imp__htons@4(hostshort);
}

//------------------------------------------------------------------------------
// Address: 0x10211E68
// Name: select(x,x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const struct timeval *timeout)
{
  return __imp__select@20(nfds, readfds, writefds, exceptfds, timeout);
}

//------------------------------------------------------------------------------
// Address: 0x10211E6E
// Name: recvfrom(x,x,x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall recvfrom(SOCKET s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen)
{
  return __imp__recvfrom@24(s, buf, len, flags, from, fromlen);
}

//------------------------------------------------------------------------------
// Address: 0x10211E74
// Name: sendto(x,x,x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall sendto(SOCKET s, const char *buf, int len, int flags, const struct sockaddr *to, int tolen)
{
  return __imp__sendto@24(s, buf, len, flags, to, tolen);
}

//------------------------------------------------------------------------------
// Address: 0x10211E7A
// Name: ntohs(x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
u_short __stdcall ntohs(u_short netshort)
{
  return __imp__ntohs@4(netshort);
}

//------------------------------------------------------------------------------
// Address: 0x10211E80
// Name: gethostbyname(x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
struct hostent *__stdcall gethostbyname(const char *name)
{
  return __imp__gethostbyname@4(name);
}

//------------------------------------------------------------------------------
// Address: 0x10211E86
// Name: setsockopt(x,x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall setsockopt(SOCKET s, int level, int optname, const char *optval, int optlen)
{
  return __imp__setsockopt@20(s, level, optname, optval, optlen);
}

//------------------------------------------------------------------------------
// Address: 0x10211E8C
// Name: listen(x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall listen(SOCKET s, int backlog)
{
  return __imp__listen@8(s, backlog);
}

//------------------------------------------------------------------------------
// Address: 0x10211E92
// Name: WSACleanup()
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall WSACleanup()
{
  return __imp__WSACleanup@0();
}

//------------------------------------------------------------------------------
// Address: 0x10211E98
// Name: accept(x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
SOCKET __stdcall accept(SOCKET s, struct sockaddr *addr, int *addrlen)
{
  return __imp__accept@12(s, addr, addrlen);
}

//------------------------------------------------------------------------------
// Address: 0x10211E9E
// Name: WSAStartup(x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData)
{
  return __imp__WSAStartup@8(wVersionRequested, lpWSAData);
}
