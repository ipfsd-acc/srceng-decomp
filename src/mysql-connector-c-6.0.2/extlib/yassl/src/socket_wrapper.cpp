// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/src/socket_wrapper.cpp
// Functions: 8
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\src\socket_wrapper.h"

//------------------------------------------------------------------------------
// Address: 0x0042BED0
// Name: public: yaSSL::Socket::Socket(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Socket::Socket(CKeyValuesDumpContextAsDevMsg *this, CKeyValuesDumpContextAsDevMsg_vtbl *s)
{
  this->__vftable = s;
  LOWORD(this->m_nDeveloperLevel) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042BF10
// Name: public: unsigned int yaSSL::Socket::get_ready(void)const
// Source: json
//------------------------------------------------------------------------------
CThreadFastMutex *__thiscall yaSSL::Socket::get_ready(SOCKET *this)
{
  SOCKET v2; // [esp-Ch] [ebp-10h]
  unsigned int ready; // [esp+0h] [ebp-4h] BYREF

  ready = (unsigned int)this;
  v2 = *this;
  ready = 0;
  ioctlsocket(s: v2, cmd: 1074030207, argp: &ready);
  return (CThreadFastMutex *)ready;
}

//------------------------------------------------------------------------------
// Address: 0x0042BF30
// Name: public: unsigned int yaSSL::Socket::send(unsigned char const __near *,unsigned int,int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall yaSSL::Socket::send(SOCKET *this, const LoggingContext_t *buf, unsigned int sz, int flags)
{
  const char *v4; // esi
  const char *v5; // edi
  int v7; // eax

  v4 = (const char *)buf;
  v5 = (char *)buf + sz;
  if ( buf == (const LoggingContext_t *)((char *)buf + sz) )
    return sz;
  while ( 1 )
  {
    v7 = send(s: *this, buf: v4, len: v5 - v4, flags);
    if ( v7 == -1 )
      break;
    v4 += v7;
    if ( v4 == v5 )
      return sz;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042BF80
// Name: public: static int yaSSL::Socket::get_lastError(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall yaSSL::Socket::get_lastError()
{
  return WSAGetLastError();
}

//------------------------------------------------------------------------------
// Address: 0x0042BF90
// Name: public: bool yaSSL::Socket::WouldBlock(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::Socket::WouldBlock(yaSSL::Socket *this)
{
  return *((_BYTE *)this + 4);
}

//------------------------------------------------------------------------------
// Address: 0x0042BFA0
// Name: public: bool yaSSL::Socket::IsNonBlocking(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::Socket::IsNonBlocking(yaSSL::Socket *this)
{
  return *((_BYTE *)this + 5);
}

//------------------------------------------------------------------------------
// Address: 0x0042BFB0
// Name: public: unsigned int yaSSL::Socket::receive(unsigned char __near *,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::Socket::receive(SOCKET *this, char *buf, unsigned int len, int flags)
{
  int v5; // eax
  int v6; // edi
  SOCKET v8; // [esp-10h] [ebp-18h]

  v8 = *this;
  *((_BYTE *)this + 4) = 0;
  v5 = recv(s: v8, buf, len, flags);
  v6 = v5;
  if ( v5 == -1 )
  {
    if ( yaSSL::Socket::get_lastError() == 10035 || yaSSL::Socket::get_lastError() == 10035 )
    {
      *((_BYTE *)this + 4) = 1;
      *((_BYTE *)this + 5) = 1;
      return 0;
    }
  }
  else if ( v5 == 0 )
  {
    return -1;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0042C020
// Name: public: bool yaSSL::Socket::wait(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::Socket::wait(CThreadFastMutex *this)
{
  unsigned __int8 ba; // [esp+1h] [ebp-1h] BYREF

  ba = HIBYTE(this);
  return yaSSL::Socket::receive(this: (SOCKET *)&this->m_ownerID, buf: (char *)&ba, len: 1u, flags: 2) != -1;
}
