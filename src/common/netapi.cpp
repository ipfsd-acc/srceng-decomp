// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/netapi.cpp
// Functions: 8
// ============================================================

#include "common\netapi.h"

//------------------------------------------------------------------------------
// Address: 0x10002EB0
// Name: public: virtual void CNetAPI::NetAdrToSockAddr(struct netadr_s __near *,struct sockaddr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetAPI::NetAdrToSockAddr(CNetAPI *this, netadr_s *a, sockaddr *s)
{
  unsigned __int16 port; // cx

  *(_QWORD *)&s->sa_family = 0;
  *(_QWORD *)&s->sa_data[6] = 0;
  if ( a->type == NA_BROADCAST )
  {
    s->sa_family = 2;
    port = a->port;
    *(_DWORD *)&s->sa_data[2] = -1;
    *(_WORD *)s->sa_data = port;
  }
  else if ( a->type == NA_IP )
  {
    s->sa_family = 2;
    *(_DWORD *)&s->sa_data[2] = *(_DWORD *)a->ip;
    *(_WORD *)s->sa_data = a->port;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F10
// Name: public: virtual void CNetAPI::SockAddrToNetAdr(struct sockaddr __near *,struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetAPI::SockAddrToNetAdr(CNetAPI *this, sockaddr *s, netadr_s *a)
{
  if ( s->sa_family == 2 )
  {
    a->type = NA_IP;
    *(_DWORD *)a->ip = *(_DWORD *)&s->sa_data[2];
    a->port = *(_WORD *)s->sa_data;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F40
// Name: public: virtual char __near * CNetAPI::AdrToString(struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CNetAPI::AdrToString(CNetAPI *this, netadr_s *a)
{
  u_short v3; // ax

  memset(dst: (unsigned __int8 *)s, value: 0, count: sizeof(s));
  if ( a != nullptr )
  {
    if ( a->type == NA_LOOPBACK )
    {
      sprintf(string: s, format: "loopback");
      return s;
    }
    if ( a->type == NA_IP )
    {
      v3 = ntohs(netshort: a->port);
      sprintf(string: s, format: "%i.%i.%i.%i:%i", a->ip[0], a->ip[1], a->ip[2], a->ip[3], v3);
    }
  }
  return s;
}

//------------------------------------------------------------------------------
// Address: 0x10002FD0
// Name: StringToSockaddr
// Source: json
//------------------------------------------------------------------------------
char __usercall StringToSockaddr@<al>(char *s@<eax>, sockaddr *sadr@<edi>)
{
  int v2; // edx
  char v3; // cl
  char v4; // al
  char *v5; // esi
  u_short v6; // ax
  int v7; // eax
  struct hostent *v9; // eax
  char copy[128]; // [esp+0h] [ebp-80h] BYREF

  *(_QWORD *)&sadr->sa_family = 0;
  *(_QWORD *)&sadr->sa_data[6] = 0;
  *(_DWORD *)&sadr->sa_family = 2;
  v2 = copy - s;
  do
  {
    v3 = *s;
    s[v2] = *s;
    ++s;
  }
  while ( v3 != 0 );
  v4 = copy[0];
  v5 = copy;
  if ( copy[0] != 0 )
  {
    do
    {
      if ( *v5 == 58 )
      {
        *v5 = 0;
        v6 = atoi(nptr: v5 + 1);
        *(_WORD *)sadr->sa_data = htons(hostshort: v6);
      }
      ++v5;
    }
    while ( *v5 != 0 );
    v4 = copy[0];
  }
  if ( (unsigned __int8)(v4 - 48) <= 9u && (strstr(str1: (unsigned __int8 *)copy, str2: "."), v7 != 0) )
  {
    *(_DWORD *)&sadr->sa_data[2] = inet_addr(cp: copy);
    return 1;
  }
  else
  {
    v9 = gethostbyname(name: copy);
    if ( v9 != nullptr )
    {
      *(_DWORD *)&sadr->sa_data[2] = **(_DWORD **)v9->h_addr_list;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003080
// Name: public: virtual bool CNetAPI::StringToAdr(char const __near *,struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetAPI::StringToAdr(CNetAPI *this, char *s, netadr_s *a)
{
  char result; // al
  sockaddr sadr; // [esp+8h] [ebp-10h] BYREF

  if ( strcmp(s, "localhost") == 0 )
  {
    *(_QWORD *)&a->type = 0;
    *(_DWORD *)&a->port = 0;
    a->type = NA_LOOPBACK;
    return 1;
  }
  else
  {
    result = StringToSockaddr(s, &sadr);
    if ( result != 0 )
    {
      this->SockAddrToNetAdr(this, a2: &sadr, a3: a);
      return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003110
// Name: public: virtual void CNetAPI::GetSocketAddress(int,struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetAPI::GetSocketAddress(CNetAPI *this, SOCKET socket, int a)
{
  netadr_s *v3; // esi
  bool (__thiscall *StringToAdr)(struct CNetAPI *, const char *, netadr_s *); // edx
  char buff[512]; // [esp+8h] [ebp-210h] BYREF
  sockaddr_in address; // [esp+208h] [ebp-10h] BYREF

  v3 = (netadr_s *)a;
  *(_QWORD *)a = 0;
  *(_DWORD *)&v3->port = 0;
  gethostname(name: buff, namelen: 512);
  StringToAdr = this->StringToAdr;
  buff[511] = 0;
  StringToAdr(this, a2: buff, a3: v3);
  a = 16;
  if ( getsockname(s: socket, name: (struct sockaddr *)&address, namelen: &a) == 0 )
    v3->port = address.sin_port;
}

//------------------------------------------------------------------------------
// Address: 0x10003190
// Name: public: virtual bool CNetAPI::CompareAdr(struct netadr_s __near *,struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetAPI::CompareAdr(CNetAPI *this, netadr_s *a, netadr_s *b)
{
  netadrtype_t type; // edx

  type = a->type;
  return a->type == b->type
      && (type == NA_LOOPBACK
       || type == NA_IP
       && a->ip[0] == b->ip[0]
       && a->ip[1] == b->ip[1]
       && a->ip[2] == b->ip[2]
       && a->ip[3] == b->ip[3]
       && a->port == b->port);
}

//------------------------------------------------------------------------------
// Address: 0x100031E0
// Name: public: virtual void CNetAPI::GetLocalIP(struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetAPI::GetLocalIP(CNetAPI *this, netadr_s *a)
{
  struct hostent *v2; // eax
  char s[64]; // [esp+0h] [ebp-40h] BYREF

  if ( gethostname(name: s, namelen: 64) == 0 )
  {
    v2 = gethostbyname(name: s);
    if ( v2 != nullptr )
    {
      a->type = NA_IP;
      a->port = 0;
      *(_DWORD *)a->ip = **(_DWORD **)v2->h_addr_list;
    }
  }
}
