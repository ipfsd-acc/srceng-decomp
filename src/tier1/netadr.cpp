// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/netadr.cpp
// Functions: 19
// ============================================================

#include "tier1\netadr.h"

//------------------------------------------------------------------------------
// Address: 0x10273180
// Name: public: bool netadr_s::CompareAdr(struct netadr_s const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareAdr(netadr_s *this, const netadr_s *a, bool onlyBase)
{
  netadrtype_t type; // edx

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK
       || type == NA_BROADCAST
       || type == NA_IP
       && (onlyBase || this->port == a->port)
       && a->ip[0] == this->ip[0]
       && a->ip[1] == this->ip[1]
       && a->ip[2] == this->ip[2]
       && a->ip[3] == this->ip[3]);
}

//------------------------------------------------------------------------------
// Address: 0x102731E0
// Name: public: bool netadr_s::CompareClassBAdr(struct netadr_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareClassBAdr(netadr_s *this, const netadr_s *a)
{
  netadrtype_t type; // eax

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK || type == NA_IP && a->ip[0] == this->ip[0] && a->ip[1] == this->ip[1]);
}

//------------------------------------------------------------------------------
// Address: 0x10273220
// Name: public: bool netadr_s::CompareClassCAdr(struct netadr_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareClassCAdr(netadr_s *this, const netadr_s *a)
{
  netadrtype_t type; // eax

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK
       || type == NA_IP && a->ip[0] == this->ip[0] && a->ip[1] == this->ip[1] && a->ip[2] == this->ip[2]);
}

//------------------------------------------------------------------------------
// Address: 0x10273260
// Name: public: bool netadr_s::IsReservedAdr(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::IsReservedAdr(netadr_s *this)
{
  bool result; // al
  unsigned __int8 v2; // al
  unsigned __int8 v3; // dl

  result = true;
  if ( this->type != NA_LOOPBACK )
  {
    if ( this->type != NA_IP )
      return false;
    v2 = this->ip[0];
    if ( v2 != 10
      && v2 != 127
      && (v2 != 0xAC || (v3 = this->ip[1]) < 0x10u || v3 > 0x1Fu)
      && (v2 != 0xC0 || this->ip[1] < 0xA8u) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102732A0
// Name: public: char const __near * netadr_s::ToString(bool)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall netadr_s::ToString(netadr_s *this, bool baseOnly)
{
  char *v3; // edi
  netadrtype_t type; // eax
  u_short v6; // ax

  v3 = s[slot % 4];
  ++slot;
  V_strncpy(pDest: v3, pSrc: "unknown", maxLen: 64);
  type = this->type;
  if ( this->type == NA_LOOPBACK )
  {
    V_strncpy(pDest: v3, pSrc: "loopback", maxLen: 64);
    return v3;
  }
  if ( type == NA_BROADCAST )
  {
    V_strncpy(pDest: v3, pSrc: "broadcast", maxLen: 64);
    return v3;
  }
  if ( type == NA_IP )
  {
    if ( baseOnly )
    {
      V_snprintf(pDest: v3, maxLen: 64, pFormat: "%i.%i.%i.%i", this->ip[0], this->ip[1], this->ip[2], this->ip[3]);
      return v3;
    }
    v6 = ntohs(netshort: this->port);
    V_snprintf(pDest: v3, maxLen: 64, pFormat: "%i.%i.%i.%i:%i", this->ip[0], this->ip[1], this->ip[2], this->ip[3], v6);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10273390
// Name: public: bool netadr_s::IsLocalhost(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall netadr_s::IsLocalhost(netadr_s *this)
{
  int result; // eax

  if ( this->ip[0] != 127 )
    return 0;
  if ( this->ip[1] != 0 )
    return 0;
  if ( this->ip[2] != 0 )
    return 0;
  result = 1;
  if ( this->ip[3] != 1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102733B0
// Name: public: bool netadr_s::IsLoopback(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall netadr_s::IsLoopback(netadr_s *this)
{
  return this->type == NA_LOOPBACK;
}

//------------------------------------------------------------------------------
// Address: 0x102733C0
// Name: public: void netadr_s::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::Clear(netadr_s *this)
{
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  this->type = NA_NULL;
}

//------------------------------------------------------------------------------
// Address: 0x102733D0
// Name: public: void netadr_s::SetIP(unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(
        netadr_s *this,
        unsigned __int8 b1,
        unsigned __int8 b2,
        unsigned __int8 b3,
        unsigned __int8 b4)
{
  this->ip[0] = b1;
  this->ip[1] = b2;
  this->ip[2] = b3;
  this->ip[3] = b4;
}

//------------------------------------------------------------------------------
// Address: 0x102733F0
// Name: public: void netadr_s::SetType(enum netadrtype_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetType(netadr_s *this, netadrtype_t newtype)
{
  this->type = newtype;
}

//------------------------------------------------------------------------------
// Address: 0x10273410
// Name: public: unsigned long netadr_s::addr_ntohl(void)const
// Source: json
//------------------------------------------------------------------------------
u_long __thiscall netadr_s::addr_ntohl(netadr_s *this)
{
  return ntohl(netlong: *(_DWORD *)this->ip);
}

//------------------------------------------------------------------------------
// Address: 0x10273420
// Name: public: unsigned long netadr_s::addr_htonl(void)const
// Source: json
//------------------------------------------------------------------------------
u_long __thiscall netadr_s::addr_htonl(netadr_s *this)
{
  return htonl(hostlong: *(_DWORD *)this->ip);
}

//------------------------------------------------------------------------------
// Address: 0x10273430
// Name: public: void netadr_s::ToSockadr(struct sockaddr __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::ToSockadr(netadr_s *this, sockaddr *s)
{
  netadrtype_t type; // eax

  _V_memset(dest: s, fill: 0, count: 16);
  type = this->type;
  if ( this->type == NA_BROADCAST )
  {
    s->sa_family = 2;
    *(_WORD *)s->sa_data = this->port;
    *(_DWORD *)&s->sa_data[2] = -1;
  }
  else if ( type == NA_IP )
  {
    s->sa_family = 2;
    *(_DWORD *)&s->sa_data[2] = *(_DWORD *)this->ip;
    *(_WORD *)s->sa_data = this->port;
  }
  else if ( type == NA_LOOPBACK )
  {
    s->sa_family = 2;
    *(_WORD *)s->sa_data = this->port;
    *(_DWORD *)&s->sa_data[2] = 2130706433;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102734B0
// Name: public: bool netadr_s::SetFromSockadr(struct sockaddr const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall netadr_s::SetFromSockadr(netadr_s *this, const sockaddr *s)
{
  if ( s->sa_family == 2 )
  {
    this->type = NA_IP;
    *(_DWORD *)this->ip = *(_DWORD *)&s->sa_data[2];
    this->port = *(_WORD *)s->sa_data;
    return 1;
  }
  else
  {
    *(_DWORD *)this->ip = 0;
    this->type = NA_NULL;
    this->port = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102734F0
// Name: public: bool netadr_s::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall netadr_s::IsValid(netadr_s *this)
{
  return this->port != 0
      && this->type != NA_NULL
      && (this->ip[0] != 0 || this->ip[1] != 0 || this->ip[2] != 0 || this->ip[3] != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10273560
// Name: public: void netadr_s::SetIP(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(netadr_s *this, unsigned int unIP)
{
  *(_DWORD *)this->ip = _byteswap_ulong(unIP);
}

//------------------------------------------------------------------------------
// Address: 0x10273570
// Name: public: unsigned short netadr_s::GetPort(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall netadr_s::GetPort(netadr_s *this)
{
  unsigned __int16 result; // ax

  LOBYTE(result) = HIBYTE(this->port);
  HIBYTE(result) = this->port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10273590
// Name: public: void netadr_s::SetPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetPort(netadr_s *this, unsigned __int16 newport)
{
  unsigned __int16 v2; // ax

  LOBYTE(v2) = HIBYTE(newport);
  HIBYTE(v2) = newport;
  this->port = v2;
}

//------------------------------------------------------------------------------
// Address: 0x102735B0
// Name: public: void netadr_s::SetFromString(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetFromString(netadr_s *this, char *pch, unsigned __int8 bUseDNS)
{
  char *v3; // edi
  int v5; // eax
  int v6; // eax
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  _BYTE *v10; // eax
  _BYTE *v11; // edi
  struct hostent *v12; // eax
  u_long v13; // eax
  unsigned __int16 v14; // ax
  char szHostName[256]; // [esp+Ch] [ebp-10Ch] BYREF
  int n3; // [esp+10Ch] [ebp-Ch] BYREF
  int n5; // [esp+110h] [ebp-8h] BYREF
  int n4; // [esp+114h] [ebp-4h] BYREF

  v3 = pch;
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  this->type = NA_IP;
  if ( v3 != nullptr )
  {
    if ( *v3 >= 48 && *v3 <= 57 && (strchr(string: (unsigned __int8 *)v3, chr: 0x2Eu), v5 != 0) )
    {
      v6 = sscanf(string: v3, format: "%d.%d.%d.%d:%d", &bUseDNS, &pch, &n3, &n4, &n5);
      if ( v6 >= 4 )
      {
        v7 = (unsigned __int8)pch;
        this->ip[0] = bUseDNS;
        v8 = n3;
        this->ip[1] = v7;
        v9 = n4;
        this->ip[2] = v8;
        this->ip[3] = v9;
      }
      if ( v6 == 5 )
        netadr_s::SetPort(this, newport: n5);
    }
    else if ( bUseDNS != 0 )
    {
      V_strncpy(pDest: szHostName, pSrc: v3, maxLen: 256);
      strchr(string: (unsigned __int8 *)szHostName, chr: 0x3Au);
      v11 = v10;
      if ( v10 != nullptr )
        *v10 = 0;
      v12 = gethostbyname(name: szHostName);
      if ( v12 != nullptr )
      {
        v13 = ntohl(netlong: **(_DWORD **)v12->h_addr_list);
        netadr_s::SetIP(this, unIP: v13);
        if ( v11 != nullptr )
        {
          v14 = atoi(nptr: v11 + 1);
          netadr_s::SetPort(this, newport: v14);
        }
      }
    }
  }
}

// ============================================================
// Overlay from bugreporter_public (Missing functions)
// ============================================================
namespace bugreporter_public {

//------------------------------------------------------------------------------
// Address: 0x10004740
// Name: public: void netadr_s::SetType(enum netadrtype_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetType(netadr_s *this, netadrtype_t newtype)
{
  this->type = newtype;
}

//------------------------------------------------------------------------------
// Address: 0x10004750
// Name: public: void netadr_s::ToSockadr(struct sockaddr __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::ToSockadr(netadr_s *this, sockaddr *s)
{
  netadrtype_t type; // eax

  _V_memset(dest: s, fill: 0, count: 16);
  type = this->type;
  if ( this->type == NA_BROADCAST )
  {
    s->sa_family = 2;
    *(_WORD *)s->sa_data = this->port;
    *(_DWORD *)&s->sa_data[2] = -1;
  }
  else if ( type == NA_IP )
  {
    s->sa_family = 2;
    *(_DWORD *)&s->sa_data[2] = *(_DWORD *)this->ip;
    *(_WORD *)s->sa_data = this->port;
  }
  else if ( type == NA_LOOPBACK )
  {
    s->sa_family = 2;
    *(_WORD *)s->sa_data = this->port;
    *(_DWORD *)&s->sa_data[2] = 2130706433;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100047D0
// Name: public: bool netadr_s::SetFromSockadr(struct sockaddr const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall netadr_s::SetFromSockadr(netadr_s *this, const sockaddr *s)
{
  if ( s->sa_family == 2 )
  {
    this->type = NA_IP;
    *(_DWORD *)this->ip = *(_DWORD *)&s->sa_data[2];
    this->port = *(_WORD *)s->sa_data;
    return 1;
  }
  else
  {
    *(_DWORD *)this->ip = 0;
    this->type = NA_NULL;
    this->port = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004810
// Name: public: void netadr_s::SetIP(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(netadr_s *this, unsigned int unIP)
{
  *(_DWORD *)this->ip = _byteswap_ulong(unIP);
}

//------------------------------------------------------------------------------
// Address: 0x10004820
// Name: public: void netadr_s::SetPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetPort(netadr_s *this, unsigned __int16 newport)
{
  unsigned __int16 v2; // ax

  LOBYTE(v2) = HIBYTE(newport);
  HIBYTE(v2) = newport;
  this->port = v2;
}

} // namespace bugreporter_public

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10036240
// Name: public: void netadr_s::SetType(enum netadrtype_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetType(netadr_s *this, netadrtype_t newtype)
{
  this->type = newtype;
}

//------------------------------------------------------------------------------
// Address: 0x10036250
// Name: public: void netadr_s::SetIP(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(netadr_s *this, unsigned int unIP)
{
  *(_DWORD *)this->ip = _byteswap_ulong(unIP);
}

//------------------------------------------------------------------------------
// Address: 0x10036260
// Name: public: void netadr_s::SetPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetPort(netadr_s *this, unsigned __int16 newport)
{
  unsigned __int16 v2; // ax

  LOBYTE(v2) = HIBYTE(newport);
  HIBYTE(v2) = newport;
  this->port = v2;
}

} // namespace dedicated

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10273230
// Name: public: bool netadr_s::CompareAdr(struct netadr_s const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareAdr(netadr_s *this, const netadr_s *a, bool onlyBase)
{
  netadrtype_t type; // edx

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK
       || type == NA_BROADCAST
       || type == NA_IP
       && (onlyBase || this->port == a->port)
       && a->ip[0] == this->ip[0]
       && a->ip[1] == this->ip[1]
       && a->ip[2] == this->ip[2]
       && a->ip[3] == this->ip[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10273290
// Name: public: bool netadr_s::CompareClassBAdr(struct netadr_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareClassBAdr(netadr_s *this, const netadr_s *a)
{
  netadrtype_t type; // eax

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK || type == NA_IP && a->ip[0] == this->ip[0] && a->ip[1] == this->ip[1]);
}

//------------------------------------------------------------------------------
// Address: 0x102732D0
// Name: public: bool netadr_s::CompareClassCAdr(struct netadr_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareClassCAdr(netadr_s *this, const netadr_s *a)
{
  netadrtype_t type; // eax

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK
       || type == NA_IP && a->ip[0] == this->ip[0] && a->ip[1] == this->ip[1] && a->ip[2] == this->ip[2]);
}

//------------------------------------------------------------------------------
// Address: 0x10273310
// Name: public: bool netadr_s::IsReservedAdr(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::IsReservedAdr(netadr_s *this)
{
  bool result; // al
  unsigned __int8 v2; // al
  unsigned __int8 v3; // dl

  result = true;
  if ( this->type != NA_LOOPBACK )
  {
    if ( this->type != NA_IP )
      return false;
    v2 = this->ip[0];
    if ( v2 != 10
      && v2 != 127
      && (v2 != 0xAC || (v3 = this->ip[1]) < 0x10u || v3 > 0x1Fu)
      && (v2 != 0xC0 || this->ip[1] < 0xA8u) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10273350
// Name: public: char const __near * netadr_s::ToString(bool)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall netadr_s::ToString(netadr_s *this, bool baseOnly)
{
  char *v3; // edi
  netadrtype_t type; // eax
  u_short v6; // ax

  v3 = s[slot % 4];
  ++slot;
  V_strncpy(pDest: v3, pSrc: "unknown", maxLen: 64);
  type = this->type;
  if ( this->type == NA_LOOPBACK )
  {
    V_strncpy(pDest: v3, pSrc: "loopback", maxLen: 64);
    return v3;
  }
  if ( type == NA_BROADCAST )
  {
    V_strncpy(pDest: v3, pSrc: "broadcast", maxLen: 64);
    return v3;
  }
  if ( type == NA_IP )
  {
    if ( baseOnly )
    {
      V_snprintf(pDest: v3, maxLen: 64, pFormat: "%i.%i.%i.%i", this->ip[0], this->ip[1], this->ip[2], this->ip[3]);
      return v3;
    }
    v6 = ntohs(netshort: this->port);
    V_snprintf(pDest: v3, maxLen: 64, pFormat: "%i.%i.%i.%i:%i", this->ip[0], this->ip[1], this->ip[2], this->ip[3], v6);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10273440
// Name: public: bool netadr_s::IsLocalhost(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall netadr_s::IsLocalhost(netadr_s *this)
{
  int result; // eax

  if ( this->ip[0] != 127 )
    return 0;
  if ( this->ip[1] != 0 )
    return 0;
  if ( this->ip[2] != 0 )
    return 0;
  result = 1;
  if ( this->ip[3] != 1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10273460
// Name: public: bool netadr_s::IsLoopback(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall netadr_s::IsLoopback(netadr_s *this)
{
  return this->type == NA_LOOPBACK;
}

//------------------------------------------------------------------------------
// Address: 0x10273470
// Name: public: void netadr_s::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::Clear(netadr_s *this)
{
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  this->type = NA_NULL;
}

//------------------------------------------------------------------------------
// Address: 0x10273480
// Name: public: void netadr_s::SetIP(unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(
        netadr_s *this,
        unsigned __int8 b1,
        unsigned __int8 b2,
        unsigned __int8 b3,
        unsigned __int8 b4)
{
  this->ip[0] = b1;
  this->ip[1] = b2;
  this->ip[2] = b3;
  this->ip[3] = b4;
}

//------------------------------------------------------------------------------
// Address: 0x102734A0
// Name: public: void netadr_s::SetType(enum netadrtype_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetType(netadr_s *this, netadrtype_t newtype)
{
  this->type = newtype;
}

//------------------------------------------------------------------------------
// Address: 0x102734C0
// Name: public: unsigned long netadr_s::addr_htonl(void)const
// Source: json
//------------------------------------------------------------------------------
u_long __thiscall netadr_s::addr_htonl(netadr_s *this)
{
  return htonl(hostlong: *(_DWORD *)this->ip);
}

//------------------------------------------------------------------------------
// Address: 0x102734D0
// Name: public: void netadr_s::ToSockadr(struct sockaddr __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::ToSockadr(netadr_s *this, sockaddr *s)
{
  netadrtype_t type; // eax

  _V_memset(dest: s, fill: 0, count: 16);
  type = this->type;
  if ( this->type == NA_BROADCAST )
  {
    s->sa_family = 2;
    *(_WORD *)s->sa_data = this->port;
    *(_DWORD *)&s->sa_data[2] = -1;
  }
  else if ( type == NA_IP )
  {
    s->sa_family = 2;
    *(_DWORD *)&s->sa_data[2] = *(_DWORD *)this->ip;
    *(_WORD *)s->sa_data = this->port;
  }
  else if ( type == NA_LOOPBACK )
  {
    s->sa_family = 2;
    *(_WORD *)s->sa_data = this->port;
    *(_DWORD *)&s->sa_data[2] = 2130706433;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10273550
// Name: public: bool netadr_s::SetFromSockadr(struct sockaddr const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall netadr_s::SetFromSockadr(netadr_s *this, const sockaddr *s)
{
  if ( s->sa_family == 2 )
  {
    this->type = NA_IP;
    *(_DWORD *)this->ip = *(_DWORD *)&s->sa_data[2];
    this->port = *(_WORD *)s->sa_data;
    return 1;
  }
  else
  {
    *(_DWORD *)this->ip = 0;
    this->type = NA_NULL;
    this->port = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10273600
// Name: public: void netadr_s::SetIP(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(netadr_s *this, unsigned int unIP)
{
  *(_DWORD *)this->ip = _byteswap_ulong(unIP);
}

//------------------------------------------------------------------------------
// Address: 0x10273610
// Name: public: unsigned short netadr_s::GetPort(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall netadr_s::GetPort(netadr_s *this)
{
  unsigned __int16 result; // ax

  LOBYTE(result) = HIBYTE(this->port);
  HIBYTE(result) = this->port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10273630
// Name: public: void netadr_s::SetPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetPort(netadr_s *this, unsigned __int16 newport)
{
  unsigned __int16 v2; // ax

  LOBYTE(v2) = HIBYTE(newport);
  HIBYTE(v2) = newport;
  this->port = v2;
}

//------------------------------------------------------------------------------
// Address: 0x10273650
// Name: public: void netadr_s::SetFromString(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetFromString(netadr_s *this, char *pch, unsigned __int8 bUseDNS)
{
  char *v3; // edi
  int v5; // eax
  int v6; // eax
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  _BYTE *v10; // eax
  _BYTE *v11; // edi
  struct hostent *v12; // eax
  u_long v13; // eax
  unsigned __int16 v14; // ax
  char szHostName[256]; // [esp+Ch] [ebp-10Ch] BYREF
  int n3; // [esp+10Ch] [ebp-Ch] BYREF
  int n5; // [esp+110h] [ebp-8h] BYREF
  int n4; // [esp+114h] [ebp-4h] BYREF

  v3 = pch;
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  this->type = NA_IP;
  if ( v3 != nullptr )
  {
    if ( *v3 >= 48 && *v3 <= 57 && (strchr(string: (unsigned __int8 *)v3, chr: 0x2Eu), v5 != 0) )
    {
      v6 = sscanf(string: v3, format: "%d.%d.%d.%d:%d", &bUseDNS, &pch, &n3, &n4, &n5);
      if ( v6 >= 4 )
      {
        v7 = (unsigned __int8)pch;
        this->ip[0] = bUseDNS;
        v8 = n3;
        this->ip[1] = v7;
        v9 = n4;
        this->ip[2] = v8;
        this->ip[3] = v9;
      }
      if ( v6 == 5 )
        netadr_s::SetPort(this, newport: n5);
    }
    else if ( bUseDNS != 0 )
    {
      V_strncpy(pDest: szHostName, pSrc: v3, maxLen: 256);
      strchr(string: (unsigned __int8 *)szHostName, chr: 0x3Au);
      v11 = v10;
      if ( v10 != nullptr )
        *v10 = 0;
      v12 = gethostbyname(name: szHostName);
      if ( v12 != nullptr )
      {
        v13 = ntohl(netlong: **(_DWORD **)v12->h_addr_list);
        netadr_s::SetIP(this, unIP: v13);
        if ( v11 != nullptr )
        {
          v14 = atoi(nptr: v11 + 1);
          netadr_s::SetPort(this, newport: v14);
        }
      }
    }
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10007BF0
// Name: public: bool netadr_s::CompareAdr(struct netadr_s const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareAdr(netadr_s *this, const netadr_s *a, bool onlyBase)
{
  netadrtype_t type; // edx

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK
       || type == NA_BROADCAST
       || type == NA_IP
       && (onlyBase || this->port == a->port)
       && a->ip[0] == this->ip[0]
       && a->ip[1] == this->ip[1]
       && a->ip[2] == this->ip[2]
       && a->ip[3] == this->ip[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10007C50
// Name: public: char const __near * netadr_s::ToString(bool)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall netadr_s::ToString(netadr_s *this, bool baseOnly)
{
  char *v3; // edi
  netadrtype_t type; // eax
  u_short v6; // ax

  v3 = s[slot % 4];
  ++slot;
  V_strncpy(pDest: v3, pSrc: "unknown", maxLen: 64);
  type = this->type;
  if ( this->type == NA_LOOPBACK )
  {
    V_strncpy(pDest: v3, pSrc: "loopback", maxLen: 64);
    return v3;
  }
  if ( type == NA_BROADCAST )
  {
    V_strncpy(pDest: v3, pSrc: "broadcast", maxLen: 64);
    return v3;
  }
  if ( type == NA_IP )
  {
    if ( baseOnly )
    {
      V_snprintf(pDest: v3, maxLen: 0x40u, pFormat: "%i.%i.%i.%i", this->ip[0], this->ip[1], this->ip[2], this->ip[3]);
      return v3;
    }
    v6 = ntohs(netshort: this->port);
    V_snprintf(
      pDest: v3,
      maxLen: 0x40u,
      pFormat: "%i.%i.%i.%i:%i",
      this->ip[0],
      this->ip[1],
      this->ip[2],
      this->ip[3],
      v6);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10007D40
// Name: public: void netadr_s::SetType(enum netadrtype_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetType(netadr_s *this, netadrtype_t newtype)
{
  this->type = newtype;
}

//------------------------------------------------------------------------------
// Address: 0x10007D50
// Name: public: enum netadrtype_t netadr_s::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
netadrtype_t __thiscall netadr_s::GetType(netadr_s *this)
{
  return this->type;
}

//------------------------------------------------------------------------------
// Address: 0x10007D60
// Name: public: unsigned int netadr_s::GetIP(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall netadr_s::GetIP(netadr_s *this)
{
  return *(_DWORD *)this->ip;
}

//------------------------------------------------------------------------------
// Address: 0x10007D70
// Name: public: void netadr_s::SetIP(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(netadr_s *this, unsigned int unIP)
{
  *(_DWORD *)this->ip = _byteswap_ulong(unIP);
}

//------------------------------------------------------------------------------
// Address: 0x10007D80
// Name: public: unsigned short netadr_s::GetPort(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall netadr_s::GetPort(netadr_s *this)
{
  unsigned __int16 result; // ax

  LOBYTE(result) = HIBYTE(this->port);
  HIBYTE(result) = this->port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007D90
// Name: public: void netadr_s::SetPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetPort(netadr_s *this, unsigned __int16 newport)
{
  unsigned __int16 v2; // ax

  LOBYTE(v2) = HIBYTE(newport);
  HIBYTE(v2) = newport;
  this->port = v2;
}

//------------------------------------------------------------------------------
// Address: 0x10007DA0
// Name: public: void netadr_s::SetFromString(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetFromString(netadr_s *this, char *pch, bool bUseDNS)
{
  int v4; // eax
  int v5; // eax
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl
  _BYTE *v9; // eax
  _BYTE *v10; // edi
  struct hostent *v11; // eax
  u_long v12; // eax
  unsigned __int16 v13; // ax
  int n4; // [esp+Ch] [ebp-114h] BYREF
  int n2; // [esp+10h] [ebp-110h] BYREF
  int n5; // [esp+14h] [ebp-10Ch] BYREF
  int n1; // [esp+18h] [ebp-108h] BYREF
  char szHostName[260]; // [esp+1Ch] [ebp-104h] BYREF

  this->ip[3] = 0;
  this->ip[2] = 0;
  this->ip[1] = 0;
  this->ip[0] = 0;
  this->port = 0;
  this->type = NA_IP;
  if ( pch != nullptr )
  {
    if ( *pch >= 48 && *pch <= 57 && (strchr(string: (unsigned __int8 *)pch, chr: 0x2Eu), v4 != 0) )
    {
      v5 = sscanf(string: pch, format: "%d.%d.%d.%d:%d", szHostName, &n5, &n4, &n2, &n1);
      if ( v5 >= 4 )
      {
        v6 = n5;
        this->ip[0] = szHostName[0];
        v7 = n4;
        this->ip[1] = v6;
        v8 = n2;
        this->ip[2] = v7;
        this->ip[3] = v8;
      }
      if ( v5 == 5 )
        netadr_s::SetPort(this, newport: n1);
    }
    else if ( bUseDNS )
    {
      V_strncpy(pDest: &szHostName[4], pSrc: pch, maxLen: 256);
      strchr(string: (unsigned __int8 *)&szHostName[4], chr: 0x3Au);
      v10 = v9;
      if ( v9 != nullptr )
        *v9 = 0;
      v11 = gethostbyname(name: &szHostName[4]);
      if ( v11 != nullptr )
      {
        v12 = ntohl(netlong: **(_DWORD **)v11->h_addr_list);
        netadr_s::SetIP(this, unIP: v12);
        if ( v10 != nullptr )
        {
          v13 = atoi(nptr: v10 + 1);
          netadr_s::SetPort(this, newport: v13);
        }
      }
    }
  }
}

} // namespace matchmaking_ds

// ============================================================
// Overlay from networksystem (Missing functions)
// ============================================================
namespace networksystem {

//------------------------------------------------------------------------------
// Address: 0x10019140
// Name: public: bool netadr_s::CompareAdr(struct netadr_s const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareAdr(netadr_s *this, const netadr_s *a, bool onlyBase)
{
  netadrtype_t type; // edx

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK
       || type == NA_BROADCAST
       || type == NA_IP
       && (onlyBase || this->port == a->port)
       && a->ip[0] == this->ip[0]
       && a->ip[1] == this->ip[1]
       && a->ip[2] == this->ip[2]
       && a->ip[3] == this->ip[3]);
}

//------------------------------------------------------------------------------
// Address: 0x100191A0
// Name: public: char const __near * netadr_s::ToString(bool)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall netadr_s::ToString(netadr_s *this, bool baseOnly)
{
  char *v3; // edi
  netadrtype_t type; // eax
  u_short v6; // ax

  v3 = s[slot % 4];
  ++slot;
  V_strncpy(pDest: v3, pSrc: "unknown", maxLen: 64);
  type = this->type;
  if ( this->type == NA_LOOPBACK )
  {
    V_strncpy(pDest: v3, pSrc: "loopback", maxLen: 64);
    return v3;
  }
  if ( type == NA_BROADCAST )
  {
    V_strncpy(pDest: v3, pSrc: "broadcast", maxLen: 64);
    return v3;
  }
  if ( type == NA_IP )
  {
    if ( baseOnly )
    {
      V_snprintf(pDest: v3, maxLen: 64, pFormat: "%i.%i.%i.%i", this->ip[0], this->ip[1], this->ip[2], this->ip[3]);
      return v3;
    }
    v6 = ntohs(netshort: this->port);
    V_snprintf(pDest: v3, maxLen: 64, pFormat: "%i.%i.%i.%i:%i", this->ip[0], this->ip[1], this->ip[2], this->ip[3], v6);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10019290
// Name: public: bool netadr_s::IsLocalhost(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall netadr_s::IsLocalhost(netadr_s *this)
{
  int result; // eax

  if ( this->ip[0] != 127 )
    return 0;
  if ( this->ip[1] != 0 )
    return 0;
  if ( this->ip[2] != 0 )
    return 0;
  result = 1;
  if ( this->ip[3] != 1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100192B0
// Name: public: bool netadr_s::IsLoopback(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall netadr_s::IsLoopback(netadr_s *this)
{
  return this->type == NA_LOOPBACK;
}

//------------------------------------------------------------------------------
// Address: 0x100192C0
// Name: public: void netadr_s::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::Clear(netadr_s *this)
{
  this->ip[3] = 0;
  this->ip[2] = 0;
  this->ip[1] = 0;
  this->ip[0] = 0;
  this->port = 0;
  this->type = NA_NULL;
}

//------------------------------------------------------------------------------
// Address: 0x100192E0
// Name: public: void netadr_s::SetType(enum netadrtype_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetType(netadr_s *this, netadrtype_t newtype)
{
  this->type = newtype;
}

//------------------------------------------------------------------------------
// Address: 0x100192F0
// Name: public: enum netadrtype_t netadr_s::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
netadrtype_t __thiscall netadr_s::GetType(netadr_s *this)
{
  return this->type;
}

//------------------------------------------------------------------------------
// Address: 0x10019300
// Name: public: unsigned int netadr_s::GetIP(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall netadr_s::GetIP(netadr_s *this)
{
  return *(_DWORD *)this->ip;
}

//------------------------------------------------------------------------------
// Address: 0x10019310
// Name: public: void netadr_s::ToSockadr(struct sockaddr __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::ToSockadr(netadr_s *this, sockaddr *s)
{
  netadrtype_t type; // eax
  unsigned __int16 port; // ax
  unsigned __int16 v5; // ax

  _V_memset(dest: (void *)s, fill: 0, count: 16);
  type = this->type;
  if ( this->type == NA_BROADCAST )
  {
    s->sa_family = 2;
    port = this->port;
    *(_DWORD *)&s->sa_data[2] = -1;
    *(_WORD *)s->sa_data = port;
  }
  else if ( type == NA_IP )
  {
    s->sa_family = 2;
    *(_DWORD *)&s->sa_data[2] = *(_DWORD *)this->ip;
    *(_WORD *)s->sa_data = this->port;
  }
  else if ( type == NA_LOOPBACK )
  {
    s->sa_family = 2;
    v5 = this->port;
    *(_DWORD *)&s->sa_data[2] = 2130706433;
    *(_WORD *)s->sa_data = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019380
// Name: public: bool netadr_s::SetFromSockadr(struct sockaddr const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall netadr_s::SetFromSockadr(netadr_s *this, const sockaddr *s)
{
  if ( s->sa_family == 2 )
  {
    this->type = NA_IP;
    *(_DWORD *)this->ip = *(_DWORD *)&s->sa_data[2];
    this->port = *(_WORD *)s->sa_data;
    return 1;
  }
  else
  {
    this->ip[3] = 0;
    this->ip[2] = 0;
    this->ip[1] = 0;
    this->ip[0] = 0;
    this->port = 0;
    this->type = NA_NULL;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100193C0
// Name: public: bool netadr_s::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall netadr_s::IsValid(netadr_s *this)
{
  return this->port != 0
      && this->type != NA_NULL
      && (this->ip[0] != 0 || this->ip[1] != 0 || this->ip[2] != 0 || this->ip[3] != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100193F0
// Name: public: void netadr_s::SetIP(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(netadr_s *this, unsigned int unIP)
{
  *(_DWORD *)this->ip = _byteswap_ulong(unIP);
}

//------------------------------------------------------------------------------
// Address: 0x10019400
// Name: public: unsigned short netadr_s::GetPort(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall netadr_s::GetPort(netadr_s *this)
{
  unsigned __int16 result; // ax

  LOBYTE(result) = HIBYTE(this->port);
  HIBYTE(result) = this->port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019410
// Name: public: void netadr_s::SetPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetPort(netadr_s *this, unsigned __int16 newport)
{
  unsigned __int16 v2; // ax

  LOBYTE(v2) = HIBYTE(newport);
  HIBYTE(v2) = newport;
  this->port = v2;
}

//------------------------------------------------------------------------------
// Address: 0x10019420
// Name: public: bool netadr_s::SetFromString(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall netadr_s::SetFromString(netadr_s *this, const char *pch, bool bUseDNS)
{
  int v5; // eax
  int v6; // eax
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // cl
  _BYTE *v10; // eax
  _BYTE *v11; // edi
  struct hostent *v12; // eax
  u_long v13; // eax
  unsigned __int16 v14; // [esp-8h] [ebp-A4h]
  int n4; // [esp+8h] [ebp-94h] BYREF
  int n2; // [esp+Ch] [ebp-90h] BYREF
  int n5; // [esp+10h] [ebp-8Ch] BYREF
  int n1; // [esp+14h] [ebp-88h] BYREF
  char address[132]; // [esp+18h] [ebp-84h] BYREF

  this->ip[3] = 0;
  this->ip[2] = 0;
  this->ip[1] = 0;
  this->ip[0] = 0;
  this->port = 0;
  this->type = NA_IP;
  if ( pch == nullptr )
    return 0;
  V_strncpy(pDest: &address[4], pSrc: pch, maxLen: 128);
  if ( V_strnicmp(s1: &address[4], s2: "localhost", n: 9) == 0 )
    _V_memcpy(dest: &address[4], src: "127.0.0.1", count: 9);
  if ( (unsigned __int8)(address[4] - 48) <= 9u && (strchr(string: (unsigned __int8 *)&address[4], chr: 0x2Eu), v5 != 0) )
  {
    v6 = sscanf(string: &address[4], format: "%d.%d.%d.%d:%d", address, &n5, &n4, &n2, &n1);
    if ( v6 >= 4 )
    {
      v7 = n5;
      this->ip[0] = address[0];
      v8 = n4;
      this->ip[1] = v7;
      v9 = n2;
      this->ip[2] = v8;
      this->ip[3] = v9;
    }
    if ( v6 == 5 )
      netadr_s::SetPort(this, newport: n1);
  }
  else if ( bUseDNS )
  {
    strchr(string: (unsigned __int8 *)&address[4], chr: 0x3Au);
    v11 = v10;
    if ( v10 != nullptr )
      *v10 = 0;
    v12 = gethostbyname(name: &address[4]);
    if ( v12 == nullptr )
      return 0;
    v13 = ntohl(netlong: **(_DWORD **)v12->h_addr_list);
    netadr_s::SetIP(this, unIP: v13);
    if ( v11 != nullptr )
    {
      v14 = V_atoi(str: v11 + 1);
      netadr_s::SetPort(this, newport: v14);
    }
  }
  return 1;
}

} // namespace networksystem

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1001B9A0
// Name: public: bool netadr_s::CompareAdr(struct netadr_s const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareAdr(netadr_s *this, const netadr_s *a, bool onlyBase)
{
  netadrtype_t type; // edx

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK
       || type == NA_BROADCAST
       || type == NA_IP
       && (onlyBase || this->port == a->port)
       && a->ip[0] == this->ip[0]
       && a->ip[1] == this->ip[1]
       && a->ip[2] == this->ip[2]
       && a->ip[3] == this->ip[3]);
}

//------------------------------------------------------------------------------
// Address: 0x1001BA00
// Name: public: bool netadr_s::CompareClassCAdr(struct netadr_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareClassCAdr(netadr_s *this, const netadr_s *a)
{
  netadrtype_t type; // eax

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK
       || type == NA_IP && a->ip[0] == this->ip[0] && a->ip[1] == this->ip[1] && a->ip[2] == this->ip[2]);
}

//------------------------------------------------------------------------------
// Address: 0x1001BA40
// Name: public: bool netadr_s::IsReservedAdr(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::IsReservedAdr(netadr_s *this)
{
  bool result; // al
  unsigned __int8 v2; // al
  unsigned __int8 v3; // dl

  result = true;
  if ( this->type != NA_LOOPBACK )
  {
    if ( this->type != NA_IP )
      return false;
    v2 = this->ip[0];
    if ( v2 != 10
      && v2 != 127
      && (v2 != 0xAC || (v3 = this->ip[1]) < 0x10u || v3 > 0x1Fu)
      && (v2 != 0xC0 || this->ip[1] < 0xA8u) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001BA80
// Name: public: char const __near * netadr_s::ToString(bool)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall netadr_s::ToString(netadr_s *this, bool baseOnly)
{
  char *v3; // edi
  netadrtype_t type; // eax
  u_short v6; // ax

  v3 = s[slot % 4];
  ++slot;
  V_strncpy(pDest: v3, pSrc: "unknown", maxLen: 64);
  type = this->type;
  if ( this->type == NA_LOOPBACK )
  {
    V_strncpy(pDest: v3, pSrc: "loopback", maxLen: 64);
    return v3;
  }
  if ( type == NA_BROADCAST )
  {
    V_strncpy(pDest: v3, pSrc: "broadcast", maxLen: 64);
    return v3;
  }
  if ( type == NA_IP )
  {
    if ( baseOnly )
    {
      V_snprintf(pDest: v3, maxLen: 0x40u, pFormat: "%i.%i.%i.%i", this->ip[0], this->ip[1], this->ip[2], this->ip[3]);
      return v3;
    }
    v6 = ntohs(netshort: this->port);
    V_snprintf(
      pDest: v3,
      maxLen: 0x40u,
      pFormat: "%i.%i.%i.%i:%i",
      this->ip[0],
      this->ip[1],
      this->ip[2],
      this->ip[3],
      v6);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001BB70
// Name: public: void netadr_s::SetType(enum netadrtype_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetType(netadr_s *this, netadrtype_t newtype)
{
  this->type = newtype;
}

//------------------------------------------------------------------------------
// Address: 0x1001BB80
// Name: public: unsigned long netadr_s::addr_ntohl(void)const
// Source: json
//------------------------------------------------------------------------------
u_long __thiscall netadr_s::addr_ntohl(netadr_s *this)
{
  return ntohl(netlong: *(_DWORD *)this->ip);
}

//------------------------------------------------------------------------------
// Address: 0x1001BB90
// Name: public: unsigned long netadr_s::addr_htonl(void)const
// Source: json
//------------------------------------------------------------------------------
u_long __thiscall netadr_s::addr_htonl(netadr_s *this)
{
  return htonl(hostlong: *(_DWORD *)this->ip);
}

//------------------------------------------------------------------------------
// Address: 0x1001BBA0
// Name: public: bool netadr_s::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall netadr_s::IsValid(netadr_s *this)
{
  return this->port != 0
      && this->type != NA_NULL
      && (this->ip[0] != 0 || this->ip[1] != 0 || this->ip[2] != 0 || this->ip[3] != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001BBD0
// Name: public: bool netadr_s::operator<(struct netadr_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::operator<(netadr_s *this, const netadr_s *netadr)
{
  unsigned int v2; // edx
  unsigned int v3; // eax

  v2 = *(_DWORD *)this->ip;
  v3 = *(_DWORD *)netadr->ip;
  if ( v3 < v2 )
    return true;
  if ( v3 <= v2 )
    return netadr->port < this->port;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1001BC10
// Name: public: void netadr_s::SetIP(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(netadr_s *this, unsigned int unIP)
{
  *(_DWORD *)this->ip = _byteswap_ulong(unIP);
}

//------------------------------------------------------------------------------
// Address: 0x1001BC20
// Name: public: unsigned short netadr_s::GetPort(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall netadr_s::GetPort(netadr_s *this)
{
  unsigned __int16 result; // ax

  LOBYTE(result) = HIBYTE(this->port);
  HIBYTE(result) = this->port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001BC40
// Name: public: void netadr_s::SetPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetPort(netadr_s *this, unsigned __int16 newport)
{
  unsigned __int16 v2; // ax

  LOBYTE(v2) = HIBYTE(newport);
  HIBYTE(v2) = newport;
  this->port = v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001BC60
// Name: public: void netadr_s::SetFromString(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetFromString(netadr_s *this, char *pch, unsigned __int8 bUseDNS)
{
  char *v3; // edi
  int v5; // eax
  int v6; // eax
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  _BYTE *v10; // eax
  _BYTE *v11; // edi
  struct hostent *v12; // eax
  u_long v13; // eax
  unsigned __int16 v14; // ax
  char szHostName[256]; // [esp+Ch] [ebp-10Ch] BYREF
  int n3; // [esp+10Ch] [ebp-Ch] BYREF
  int n5; // [esp+110h] [ebp-8h] BYREF
  int n4; // [esp+114h] [ebp-4h] BYREF

  v3 = pch;
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  this->type = NA_IP;
  if ( v3 != nullptr )
  {
    if ( *v3 >= 48 && *v3 <= 57 && (strchr(string: v3, chr: 0x2Eu), v5 != 0) )
    {
      v6 = sscanf(string: v3, format: "%d.%d.%d.%d:%d", &bUseDNS, &pch, &n3, &n4, &n5);
      if ( v6 >= 4 )
      {
        v7 = (unsigned __int8)pch;
        this->ip[0] = bUseDNS;
        v8 = n3;
        this->ip[1] = v7;
        v9 = n4;
        this->ip[2] = v8;
        this->ip[3] = v9;
      }
      if ( v6 == 5 )
        netadr_s::SetPort(this, newport: n5);
    }
    else if ( bUseDNS != 0 )
    {
      V_strncpy(pDest: szHostName, pSrc: v3, maxLen: 256);
      strchr(string: szHostName, chr: 0x3Au);
      v11 = v10;
      if ( v10 != nullptr )
        *v10 = 0;
      v12 = gethostbyname(name: szHostName);
      if ( v12 != nullptr )
      {
        v13 = ntohl(netlong: **(_DWORD **)v12->h_addr_list);
        netadr_s::SetIP(this, unIP: v13);
        if ( v11 != nullptr )
        {
          v14 = atoi(nptr: v11 + 1);
          netadr_s::SetPort(this, newport: v14);
        }
      }
    }
  }
}

} // namespace ServerBrowser

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x10039120
// Name: public: bool netadr_s::CompareAdr(struct netadr_s const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareAdr(netadr_s *this, const netadr_s *a, bool onlyBase)
{
  netadrtype_t type; // edx

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK
       || type == NA_BROADCAST
       || type == NA_IP
       && (onlyBase || this->port == a->port)
       && a->ip[0] == this->ip[0]
       && a->ip[1] == this->ip[1]
       && a->ip[2] == this->ip[2]
       && a->ip[3] == this->ip[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10039180
// Name: public: char const __near * netadr_s::ToString(bool)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall netadr_s::ToString(netadr_s *this, bool baseOnly)
{
  char *v3; // edi
  netadrtype_t type; // eax
  u_short v6; // ax

  v3 = s[slot % 4];
  ++slot;
  V_strncpy(pDest: v3, pSrc: "unknown", maxLen: 64);
  type = this->type;
  if ( this->type == NA_LOOPBACK )
  {
    V_strncpy(pDest: v3, pSrc: "loopback", maxLen: 64);
    return v3;
  }
  if ( type == NA_BROADCAST )
  {
    V_strncpy(pDest: v3, pSrc: "broadcast", maxLen: 64);
    return v3;
  }
  if ( type == NA_IP )
  {
    if ( baseOnly )
    {
      V_snprintf(pDest: v3, maxLen: 0x40u, pFormat: "%i.%i.%i.%i", this->ip[0], this->ip[1], this->ip[2], this->ip[3]);
      return v3;
    }
    v6 = ntohs(netshort: this->port);
    V_snprintf(
      pDest: v3,
      maxLen: 0x40u,
      pFormat: "%i.%i.%i.%i:%i",
      this->ip[0],
      this->ip[1],
      this->ip[2],
      this->ip[3],
      v6);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10039270
// Name: public: void netadr_s::SetType(enum netadrtype_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetType(netadr_s *this, netadrtype_t newtype)
{
  this->type = newtype;
}

//------------------------------------------------------------------------------
// Address: 0x10039280
// Name: public: enum netadrtype_t netadr_s::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
netadrtype_t __thiscall netadr_s::GetType(netadr_s *this)
{
  return this->type;
}

//------------------------------------------------------------------------------
// Address: 0x10039290
// Name: public: unsigned int netadr_s::GetIP(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall netadr_s::GetIP(netadr_s *this)
{
  return *(_DWORD *)this->ip;
}

//------------------------------------------------------------------------------
// Address: 0x100392A0
// Name: public: unsigned long netadr_s::addr_htonl(void)const
// Source: json
//------------------------------------------------------------------------------
u_long __thiscall netadr_s::addr_htonl(netadr_s *this)
{
  return htonl(hostlong: *(_DWORD *)this->ip);
}

//------------------------------------------------------------------------------
// Address: 0x100392B0
// Name: public: void netadr_s::SetIP(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(netadr_s *this, unsigned int unIP)
{
  *(_DWORD *)this->ip = _byteswap_ulong(unIP);
}

//------------------------------------------------------------------------------
// Address: 0x100392C0
// Name: public: unsigned short netadr_s::GetPort(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall netadr_s::GetPort(netadr_s *this)
{
  unsigned __int16 result; // ax

  LOBYTE(result) = HIBYTE(this->port);
  HIBYTE(result) = this->port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100392E0
// Name: public: void netadr_s::SetPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetPort(netadr_s *this, unsigned __int16 newport)
{
  unsigned __int16 v2; // ax

  LOBYTE(v2) = HIBYTE(newport);
  HIBYTE(v2) = newport;
  this->port = v2;
}

//------------------------------------------------------------------------------
// Address: 0x10039300
// Name: public: void netadr_s::SetFromString(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetFromString(netadr_s *this, char *pch, unsigned __int8 bUseDNS)
{
  char *v3; // edi
  int v5; // eax
  int v6; // eax
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  _BYTE *v10; // eax
  _BYTE *v11; // edi
  struct hostent *v12; // eax
  u_long v13; // eax
  unsigned __int16 v14; // ax
  char szHostName[256]; // [esp+Ch] [ebp-10Ch] BYREF
  int n3; // [esp+10Ch] [ebp-Ch] BYREF
  int n5; // [esp+110h] [ebp-8h] BYREF
  int n4; // [esp+114h] [ebp-4h] BYREF

  v3 = pch;
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  this->type = NA_IP;
  if ( v3 != nullptr )
  {
    if ( *v3 >= 48 && *v3 <= 57 && (strchr(string: (unsigned __int8 *)v3, chr: 0x2Eu), v5 != 0) )
    {
      v6 = sscanf(string: v3, format: "%d.%d.%d.%d:%d", &bUseDNS, &pch, &n3, &n4, &n5);
      if ( v6 >= 4 )
      {
        v7 = (unsigned __int8)pch;
        this->ip[0] = bUseDNS;
        v8 = n3;
        this->ip[1] = v7;
        v9 = n4;
        this->ip[2] = v8;
        this->ip[3] = v9;
      }
      if ( v6 == 5 )
        netadr_s::SetPort(this, newport: n5);
    }
    else if ( bUseDNS != 0 )
    {
      V_strncpy(pDest: szHostName, pSrc: v3, maxLen: 256);
      strchr(string: (unsigned __int8 *)szHostName, chr: 0x3Au);
      v11 = v10;
      if ( v10 != nullptr )
        *v10 = 0;
      v12 = gethostbyname(name: szHostName);
      if ( v12 != nullptr )
      {
        v13 = ntohl(netlong: **(_DWORD **)v12->h_addr_list);
        netadr_s::SetIP(this, unIP: v13);
        if ( v11 != nullptr )
        {
          v14 = atoi(nptr: v11 + 1);
          netadr_s::SetPort(this, newport: v14);
        }
      }
    }
  }
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x1000CFE0
// Name: public: bool netadr_s::CompareAdr(struct netadr_s const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::CompareAdr(netadr_s *this, const netadr_s *a, bool onlyBase)
{
  netadrtype_t type; // edx

  type = this->type;
  return a->type == this->type
      && (type == NA_LOOPBACK
       || type == NA_BROADCAST
       || type == NA_IP
       && (onlyBase || this->port == a->port)
       && a->ip[0] == this->ip[0]
       && a->ip[1] == this->ip[1]
       && a->ip[2] == this->ip[2]
       && a->ip[3] == this->ip[3]);
}

//------------------------------------------------------------------------------
// Address: 0x1000D040
// Name: public: char const __near * netadr_s::ToString(bool)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall netadr_s::ToString(netadr_s *this, bool baseOnly)
{
  char *v3; // edi
  netadrtype_t type; // eax
  u_short v6; // ax

  v3 = s[slot % 4];
  ++slot;
  V_strncpy(pDest: v3, pSrc: "unknown", maxLen: 64);
  type = this->type;
  if ( this->type == NA_LOOPBACK )
  {
    V_strncpy(pDest: v3, pSrc: "loopback", maxLen: 64);
    return v3;
  }
  if ( type == NA_BROADCAST )
  {
    V_strncpy(pDest: v3, pSrc: "broadcast", maxLen: 64);
    return v3;
  }
  if ( type == NA_IP )
  {
    if ( baseOnly )
    {
      V_snprintf(pDest: v3, maxLen: 0x40u, pFormat: "%i.%i.%i.%i", this->ip[0], this->ip[1], this->ip[2], this->ip[3]);
      return v3;
    }
    v6 = ntohs(netshort: this->port);
    V_snprintf(
      pDest: v3,
      maxLen: 0x40u,
      pFormat: "%i.%i.%i.%i:%i",
      this->ip[0],
      this->ip[1],
      this->ip[2],
      this->ip[3],
      v6);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000D130
// Name: public: void netadr_s::SetType(enum netadrtype_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetType(netadr_s *this, netadrtype_t newtype)
{
  this->type = newtype;
}

//------------------------------------------------------------------------------
// Address: 0x1000D140
// Name: public: enum netadrtype_t netadr_s::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
netadrtype_t __thiscall netadr_s::GetType(netadr_s *this)
{
  return this->type;
}

//------------------------------------------------------------------------------
// Address: 0x1000D150
// Name: public: unsigned int netadr_s::GetIP(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall netadr_s::GetIP(netadr_s *this)
{
  return *(_DWORD *)this->ip;
}

//------------------------------------------------------------------------------
// Address: 0x1000D160
// Name: public: void netadr_s::SetIP(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetIP(netadr_s *this, unsigned int unIP)
{
  *(_DWORD *)this->ip = _byteswap_ulong(unIP);
}

//------------------------------------------------------------------------------
// Address: 0x1000D170
// Name: public: unsigned short netadr_s::GetPort(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall netadr_s::GetPort(netadr_s *this)
{
  unsigned __int16 result; // ax

  LOBYTE(result) = HIBYTE(this->port);
  HIBYTE(result) = this->port;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D190
// Name: public: void netadr_s::SetPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetPort(netadr_s *this, unsigned __int16 newport)
{
  unsigned __int16 v2; // ax

  LOBYTE(v2) = HIBYTE(newport);
  HIBYTE(v2) = newport;
  this->port = v2;
}

//------------------------------------------------------------------------------
// Address: 0x1000D1B0
// Name: public: void netadr_s::SetFromString(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netadr_s::SetFromString(netadr_s *this, char *pch, unsigned __int8 bUseDNS)
{
  char *v3; // edi
  int v5; // eax
  int v6; // eax
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  _BYTE *v10; // eax
  _BYTE *v11; // edi
  struct hostent *v12; // eax
  u_long v13; // eax
  unsigned __int16 v14; // ax
  char szHostName[256]; // [esp+Ch] [ebp-10Ch] BYREF
  int n3; // [esp+10Ch] [ebp-Ch] BYREF
  int n5; // [esp+110h] [ebp-8h] BYREF
  int n4; // [esp+114h] [ebp-4h] BYREF

  v3 = pch;
  *(_DWORD *)this->ip = 0;
  this->port = 0;
  this->type = NA_IP;
  if ( v3 != nullptr )
  {
    if ( *v3 >= 48 && *v3 <= 57 && (strchr(string: (unsigned __int8 *)v3, chr: 0x2Eu), v5 != 0) )
    {
      v6 = sscanf(string: v3, format: "%d.%d.%d.%d:%d", &bUseDNS, &pch, &n3, &n4, &n5);
      if ( v6 >= 4 )
      {
        v7 = (unsigned __int8)pch;
        this->ip[0] = bUseDNS;
        v8 = n3;
        this->ip[1] = v7;
        v9 = n4;
        this->ip[2] = v8;
        this->ip[3] = v9;
      }
      if ( v6 == 5 )
        netadr_s::SetPort(this, newport: n5);
    }
    else if ( bUseDNS != 0 )
    {
      V_strncpy(pDest: szHostName, pSrc: v3, maxLen: 256);
      strchr(string: (unsigned __int8 *)szHostName, chr: 0x3Au);
      v11 = v10;
      if ( v10 != nullptr )
        *v10 = 0;
      v12 = gethostbyname(name: szHostName);
      if ( v12 != nullptr )
      {
        v13 = ntohl(netlong: **(_DWORD **)v12->h_addr_list);
        netadr_s::SetIP(this, unIP: v13);
        if ( v11 != nullptr )
        {
          v14 = atoi(nptr: v11 + 1);
          netadr_s::SetPort(this, newport: v14);
        }
      }
    }
  }
}

} // namespace matchmaking_ds
