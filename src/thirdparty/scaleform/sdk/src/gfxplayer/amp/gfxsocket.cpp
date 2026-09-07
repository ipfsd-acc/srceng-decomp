// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/amp/gfxsocket.cpp
// Functions: 51
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\amp\gfxsocket.h"

//------------------------------------------------------------------------------
// Address: 0x1001DF10
// Name: public: bool GFxSocket::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSocket::IsValid(CMaterial_QueueFriendly *this)
{
  return this->m_pRealTimeVersion->HasProxy(this: this->m_pRealTimeVersion);
}

//------------------------------------------------------------------------------
// Address: 0x10183560
// Name: public: GFxSocket::GFxSocket(bool,class GFxSocketImplFactory __near *)
// Source: json
//------------------------------------------------------------------------------
GFxSocket *__thiscall GFxSocket::GFxSocket(GFxSocket *this, bool a2, struct GFxSocketImplFactory *a3)
{
  int v4; // eax
  bool v5; // zf

  *(_DWORD *)this = a3;
  *((_DWORD *)this + 1) = 0;
  *((_BYTE *)this + 8) = 0;
  *((_BYTE *)this + 9) = a2;
  *((_DWORD *)this + 3) = 0;
  if ( a3 == nullptr )
    *(_DWORD *)this = &defaultSocketFactory;
  v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)this + 4))(a1: *(_DWORD *)this);
  v5 = *((_BYTE *)this + 9) == 0;
  *((_DWORD *)this + 1) = v4;
  if ( !v5 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 72))(a1: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101835B0
// Name: public: int GFxSocket::Send(char const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSocket::Send(GFxSocket *this, const char *a2, unsigned int a3)
{
  int result; // eax

  result = (*(int (__thiscall **)(_DWORD, const char *, unsigned int))(**((_DWORD **)this + 1) + 28))(
             a1: *((_DWORD *)this + 1),
             a2,
             a3);
  if ( result < 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101835D0
// Name: public: int GFxSocket::Receive(char __near *,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSocket::Receive(GFxSocket *this, char *a2, int a3)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(_DWORD, char *, int))(**((_DWORD **)this + 1) + 32))(a1: *((_DWORD *)this + 1), a2, a3);
  return v3 < 0 ? 0 : v3;
}

//------------------------------------------------------------------------------
// Address: 0x10183610
// Name: public: GFxBroadcastSocket::GFxBroadcastSocket(bool,class GFxSocketImplFactory __near *)
// Source: json
//------------------------------------------------------------------------------
GFxBroadcastSocket *__thiscall GFxBroadcastSocket::GFxBroadcastSocket(
        GFxBroadcastSocket *this,
        bool a2,
        struct GFxSocketImplFactory *a3)
{
  int v4; // eax
  bool v5; // zf

  *(_DWORD *)this = a3;
  *((_BYTE *)this + 8) = a2;
  if ( a3 == nullptr )
    *(_DWORD *)this = &defaultSocketFactory;
  v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)this + 4))(a1: *(_DWORD *)this);
  v5 = *((_BYTE *)this + 8) == 0;
  *((_DWORD *)this + 1) = v4;
  if ( !v5 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 72))(a1: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10183650
// Name: public: int GFxBroadcastSocket::Receive(char __near *,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxBroadcastSocket::Receive(GFxBroadcastSocket *this, char *a2, int a3)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(_DWORD, char *, int))(**((_DWORD **)this + 1) + 40))(a1: *((_DWORD *)this + 1), a2, a3);
  return v3 < 0 ? 0 : v3;
}

//------------------------------------------------------------------------------
// Address: 0x10183680
// Name: public: void GFxBroadcastSocket::GetName(unsigned long __near *,unsigned long __near *,char __near *,unsigned long)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxBroadcastSocket::GetName(
        GFxBroadcastSocket *this,
        unsigned int *a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5)
{
  (*(void (__thiscall **)(_DWORD, unsigned int *, unsigned int *, char *, unsigned int))(**((_DWORD **)this + 1) + 64))(
    a1: *((_DWORD *)this + 1),
    a2,
    a3,
    a4,
    a5);
}

//------------------------------------------------------------------------------
// Address: 0x101836C0
// Name: public: virtual void GFxDefaultSocketFactory::Destroy(class GFxSocketInterface __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDefaultSocketFactory::Destroy(GFxDefaultSocketFactory *this, struct GFxSocketInterface *a2)
{
  if ( a2 != nullptr )
    (**(void (__thiscall ***)(struct GFxSocketInterface *, int))a2)(a1: a2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10183710
// Name: public: void GFxSocket::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSocket::Destroy(GFxSocket *this)
{
  _RTL_CRITICAL_SECTION *v2; // esi

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 84))(a1: *((_DWORD *)this + 1)) != 0 )
  {
    v2 = *((_RTL_CRITICAL_SECTION **)this + 3);
    if ( v2 != nullptr )
      EnterCriticalSection(lpCriticalSection: *((LPCRITICAL_SECTION *)this + 3));
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 68))(a1: *((_DWORD *)this + 1));
    if ( v2 != nullptr )
      LeaveCriticalSection(lpCriticalSection: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183750
// Name: public: bool GFxSocket::Accept(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSocket::Accept(GFxSocket *this, int a2)
{
  _RTL_CRITICAL_SECTION *v3; // edi

  if ( *((_BYTE *)this + 8) == 0
    || (*(unsigned __int8 (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 1) + 24))(a1: *((_DWORD *)this + 1), a2) != 0 )
  {
    return 1;
  }
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 84))(a1: *((_DWORD *)this + 1)) != 0 )
  {
    v3 = *((_RTL_CRITICAL_SECTION **)this + 3);
    if ( v3 != nullptr )
      EnterCriticalSection(lpCriticalSection: *((LPCRITICAL_SECTION *)this + 3));
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 68))(a1: *((_DWORD *)this + 1));
    if ( v3 != nullptr )
      LeaveCriticalSection(lpCriticalSection: v3);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101837B0
// Name: public: GFxBroadcastSocket::~GFxBroadcastSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxBroadcastSocket::~GFxBroadcastSocket(GFxBroadcastSocket *this)
{
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 84))(a1: *((_DWORD *)this + 1)) != 0 )
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 68))(a1: *((_DWORD *)this + 1));
  if ( *((_BYTE *)this + 8) != 0 )
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 76))(a1: *((_DWORD *)this + 1));
  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)this + 8))(a1: *(_DWORD *)this, a2: *((_DWORD *)this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x101837F0
// Name: public: bool GFxBroadcastSocket::Create(unsigned long,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxBroadcastSocket::Create(GFxBroadcastSocket *this, unsigned int a2, bool a3)
{
  int v4; // ecx
  bool v6; // zf
  int v7; // eax

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 8))(a1: *((_DWORD *)this + 1)) == 0 )
    return 0;
  v4 = *((_DWORD *)this + 1);
  if ( a3 )
  {
    (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 48))(a1: v4, a2);
    (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 1) + 60))(a1: *((_DWORD *)this + 1), a2: 1);
    return 1;
  }
  (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 44))(a1: v4, a2);
  v6 = (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 12))(a1: *((_DWORD *)this + 1)) == 0;
  v7 = **((_DWORD **)this + 1);
  if ( v6 )
  {
    if ( (*(unsigned __int8 (**)(void))(v7 + 84))() != 0 )
      (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 68))(a1: *((_DWORD *)this + 1));
    return 0;
  }
  (*(void (__stdcall **)(_DWORD))(v7 + 56))(a1: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10183880
// Name: public: GFxSocket::~GFxSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSocket::~GFxSocket(GFxSocket *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  _RTL_CRITICAL_SECTION *v3; // edi

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 84))(a1: *((_DWORD *)this + 1)) != 0 )
  {
    v2 = *((_RTL_CRITICAL_SECTION **)this + 3);
    if ( v2 != nullptr )
      EnterCriticalSection(lpCriticalSection: *((LPCRITICAL_SECTION *)this + 3));
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 68))(a1: *((_DWORD *)this + 1));
    if ( v2 != nullptr )
      LeaveCriticalSection(lpCriticalSection: v2);
  }
  if ( *((_BYTE *)this + 9) != 0 )
  {
    v3 = *((_RTL_CRITICAL_SECTION **)this + 3);
    if ( v3 != nullptr )
      EnterCriticalSection(lpCriticalSection: *((LPCRITICAL_SECTION *)this + 3));
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 76))(a1: *((_DWORD *)this + 1));
    if ( v3 != nullptr )
      LeaveCriticalSection(lpCriticalSection: v3);
  }
  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)this + 8))(a1: *(_DWORD *)this, a2: *((_DWORD *)this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x101838F0
// Name: public: bool GFxSocket::Create(char const __near *,unsigned long,class GString __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSocket::Create(GFxSocket *this, const char *a2, unsigned int a3, IBaseFileSystem_vtbl *a4)
{
  _RTL_CRITICAL_SECTION *v5; // eax
  int v6; // ecx
  int v7; // ecx
  _RTL_CRITICAL_SECTION *v8; // edi
  int v10; // edx
  int v11; // ecx
  IFileSystem v12; // [esp+Ch] [ebp-10h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+18h] [ebp-4h]

  v5 = *((_RTL_CRITICAL_SECTION **)this + 3);
  lpCriticalSection = v5;
  if ( v5 != nullptr )
    EnterCriticalSection(lpCriticalSection: v5);
  v6 = *((_DWORD *)this + 1);
  *((_BYTE *)this + 8) = a2 == nullptr;
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6) == 0 )
  {
    if ( a4 != nullptr )
    {
      v7 = *((_DWORD *)this + 1);
      v12.IBaseFileSystem::__vftable = a4;
      v12.IAppSystem::__vftable = nullptr;
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 80))(a1: v7);
      G_SPrintF(result: &v12);
    }
    v8 = *((_RTL_CRITICAL_SECTION **)this + 3);
    if ( v8 != nullptr )
      EnterCriticalSection(lpCriticalSection: *((LPCRITICAL_SECTION *)this + 3));
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 76))(a1: *((_DWORD *)this + 1));
    if ( v8 != nullptr )
      LeaveCriticalSection(lpCriticalSection: v8);
    if ( lpCriticalSection != nullptr )
      LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  v10 = **((_DWORD **)this + 1);
  if ( *((_BYTE *)this + 8) != 0 )
  {
    (*(void (__stdcall **)(unsigned int))(v10 + 44))(a1: a3);
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 12))(a1: *((_DWORD *)this + 1)) == 0 )
    {
      if ( a4 == nullptr )
      {
LABEL_17:
        GFxSocket::Destroy(this);
        if ( lpCriticalSection != nullptr )
          LeaveCriticalSection(lpCriticalSection);
        return 0;
      }
LABEL_16:
      v11 = *((_DWORD *)this + 1);
      v12.IBaseFileSystem::__vftable = a4;
      v12.IAppSystem::__vftable = nullptr;
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 80))(a1: v11);
      G_SPrintF(result: &v12);
      goto LABEL_17;
    }
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 1) + 16))(
           a1: *((_DWORD *)this + 1),
           a2: 1) == 0 )
    {
      if ( a4 == nullptr )
        goto LABEL_17;
      goto LABEL_16;
    }
  }
  else
  {
    (*(void (__stdcall **)(unsigned int, const char *))(v10 + 52))(a1: a3, a2);
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 20))(a1: *((_DWORD *)this + 1)) == 0 )
    {
      if ( a4 == nullptr )
        goto LABEL_17;
      goto LABEL_16;
    }
  }
  if ( a4 != nullptr )
  {
    v12.IAppSystem::__vftable = nullptr;
    v12.IBaseFileSystem::__vftable = a4;
    G_SPrintF(result: &v12);
  }
  if ( lpCriticalSection != nullptr )
    LeaveCriticalSection(lpCriticalSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10183AA0
// Name: public: virtual bool GFxSocketImpl::CreateStream(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSocketImpl::CreateStream(GFxSocketImpl *this)
{
  SOCKET v2; // eax

  v2 = socket(af: 2, type: 1, protocol: 6);
  *((_DWORD *)this + 5) = v2;
  return v2 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10183AC0
// Name: public: virtual bool GFxSocketImpl::CreateDatagram(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSocketImpl::CreateDatagram(GFxSocketImpl *this)
{
  SOCKET v2; // eax

  v2 = socket(af: 2, type: 2, protocol: 17);
  *((_DWORD *)this + 5) = v2;
  return v2 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10183AE0
// Name: public: virtual bool GFxSocketImpl::Bind(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSocketImpl::Bind(GFxSocketImpl *this)
{
  return bind(s: *((_DWORD *)this + 5), name: (const struct sockaddr *)((char *)this + 4), namelen: 16) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10183B00
// Name: public: virtual bool GFxSocketImpl::Listen(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSocketImpl::Listen(GFxSocketImpl *this, int backlog)
{
  return listen(s: *((_DWORD *)this + 5), backlog) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10183B20
// Name: public: virtual bool GFxSocketImpl::Connect(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxSocketImpl::Connect(GFxSocketImpl *this)
{
  return connect(s: *((_DWORD *)this + 5), name: (const struct sockaddr *)((char *)this + 4), namelen: 16) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10183B40
// Name: public: virtual bool GFxSocketImpl::Accept(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSocketImpl::Accept(GFxSocketImpl *this, int a2)
{
  SOCKET v3; // edi
  SOCKET v5; // [esp-Ch] [ebp-1Ch]
  int addrlen; // [esp+8h] [ebp-8h] BYREF

  v5 = *((_DWORD *)this + 5);
  addrlen = 16;
  v3 = accept(s: v5, addr: (struct sockaddr *)((char *)this + 4), &addrlen);
  if ( v3 == -1 )
    return 0;
  (*(void (__thiscall **)(GFxSocketImpl *))(*(_DWORD *)this + 68))(a1: this);
  *((_DWORD *)this + 5) = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10183BB0
// Name: public: virtual int GFxSocketImpl::Send(char const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
SOCKET __thiscall GFxSocketImpl::Send(GFxSocketImpl *this, char *buf, int len)
{
  SOCKET result; // eax

  result = *((_DWORD *)this + 5);
  if ( result != -1 )
  {
    result = send(s: result, buf, len, flags: 0);
    if ( result == -1 )
      return -((*(int (__thiscall **)(GFxSocketImpl *))(*(_DWORD *)this + 80))(a1: this) != 10035);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10183C00
// Name: public: virtual int GFxSocketImpl::Receive(char __near *,int)const
// Source: json
//------------------------------------------------------------------------------
SOCKET __thiscall GFxSocketImpl::Receive(GFxSocketImpl *this, char *buf, int len)
{
  SOCKET result; // eax

  result = *((_DWORD *)this + 5);
  if ( result != -1 )
    return recv(s: result, buf, len, flags: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10183C30
// Name: public: virtual int GFxSocketImpl::SendBroadcast(char const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
SOCKET __thiscall GFxSocketImpl::SendBroadcast(GFxSocketImpl *this, char *buf, int len)
{
  SOCKET result; // eax

  result = *((_DWORD *)this + 5);
  if ( result != -1 )
    return sendto(s: result, buf, len, flags: 0, to: (const struct sockaddr *)((char *)this + 4), tolen: 16);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10183C60
// Name: public: virtual int GFxSocketImpl::ReceiveBroadcast(char __near *,int)const
// Source: json
//------------------------------------------------------------------------------
SOCKET __thiscall GFxSocketImpl::ReceiveBroadcast(GFxSocketImpl *this, char *buf, int len)
{
  SOCKET result; // eax
  int fromlen; // [esp+0h] [ebp-4h] BYREF

  fromlen = (int)this;
  result = *((_DWORD *)this + 5);
  if ( result != -1 )
  {
    fromlen = 16;
    return recvfrom(s: result, buf, len, flags: 0, from: (struct sockaddr *)((char *)this + 4), &fromlen);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10183CA0
// Name: public: virtual void GFxSocketImpl::SetListenPort(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSocketImpl::SetListenPort(GFxSocketImpl *this, u_short hostshort)
{
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_WORD *)this + 2) = 2;
  *((_DWORD *)this + 2) = htonl(hostlong: 0);
  *((_WORD *)this + 3) = htons(hostshort);
}

//------------------------------------------------------------------------------
// Address: 0x10183CE0
// Name: public: virtual void GFxSocketImpl::SetBroadcastPort(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSocketImpl::SetBroadcastPort(GFxSocketImpl *this, u_short hostshort)
{
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_WORD *)this + 2) = 2;
  *((_DWORD *)this + 2) = htonl(hostlong: 0xFFFFFFFF);
  *((_WORD *)this + 3) = htons(hostshort);
}

//------------------------------------------------------------------------------
// Address: 0x10183D20
// Name: public: virtual void GFxSocketImpl::SetAddress(unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSocketImpl::SetAddress(GFxSocketImpl *this, u_short hostshort, char *cp)
{
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_WORD *)this + 2) = 2;
  *((_DWORD *)this + 2) = inet_addr(cp);
  *((_WORD *)this + 3) = htons(hostshort);
}

//------------------------------------------------------------------------------
// Address: 0x10183D60
// Name: public: virtual void GFxSocketImpl::SetBlocking(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSocketImpl::SetBlocking(GFxSocketImpl *this, u_long argp)
{
  argp = (_BYTE)argp == 0;
  ioctlsocket(s: *((_DWORD *)this + 5), cmd: -2147195266, &argp);
}

//------------------------------------------------------------------------------
// Address: 0x10183D90
// Name: public: virtual void GFxSocketImpl::SetBroadcast(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSocketImpl::SetBroadcast(GFxSocketImpl *this, BOOL optval)
{
  optval = optval;
  setsockopt(s: *((_DWORD *)this + 5), level: 0xFFFF, optname: 32, (const char *)&optval, optlen: 4);
}

//------------------------------------------------------------------------------
// Address: 0x10183DC0
// Name: public: virtual bool GFxSocketImpl::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSocketImpl::Shutdown(GFxSocketImpl *this)
{
  if ( *((_DWORD *)this + 5) != -1 )
  {
    closesocket(s: *((_DWORD *)this + 5));
    *((_DWORD *)this + 5) = -1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10183DE0
// Name: public: virtual bool GFxSocketImpl::Startup(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSocketImpl::Startup(GFxSocketImpl *this)
{
  struct WSAData WSAData; // [esp+0h] [ebp-194h] BYREF

  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GFxSocketImpl::LibRefLock);
  if ( GFxSocketImpl::LibRefs != 0 || WSAStartup(wVersionRequested: 2u, lpWSAData: &WSAData) == 0 )
  {
    ++GFxSocketImpl::LibRefs;
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GFxSocketImpl::LibRefLock);
    return 1;
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GFxSocketImpl::LibRefLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183E60
// Name: public: virtual void GFxSocketImpl::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSocketImpl::Cleanup(GFxSocketImpl *this)
{
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GFxSocketImpl::LibRefLock);
  if ( GFxSocketImpl::LibRefs != 0 && --GFxSocketImpl::LibRefs == 0 )
    WSACleanup();
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&GFxSocketImpl::LibRefLock);
}

//------------------------------------------------------------------------------
// Address: 0x10183E90
// Name: public: virtual int GFxSocketImpl::GetLastError(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall GFxSocketImpl::GetLastError()
{
  return WSAGetLastError();
}

//------------------------------------------------------------------------------
// Address: 0x10183EA0
// Name: public: virtual bool GFxSocketImpl::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxSocketImpl::IsValid(GFxSocketImpl *this)
{
  return *((_DWORD *)this + 5) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10184350
// Name: public: virtual class GFxSocketInterface __near * GFxDefaultSocketFactory::Create(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxSocketInterface *__thiscall GFxDefaultSocketFactory::Create(GFxDefaultSocketFactory *this)
{
  struct GFxSocketInterface *result; // eax
  int v2; // [esp+0h] [ebp-4h] BYREF

  v2 = 2;
  result = (struct GFxSocketInterface *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 32, a3: &v2);
  if ( result == nullptr )
    return nullptr;
  *(_DWORD *)result = &GFxSocketImpl::`vftable';
  *((_DWORD *)result + 5) = -1;
  *((_DWORD *)result + 6) = 0;
  *((_DWORD *)result + 7) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10184420
// Name: public: virtual void GFxSocketImpl::GetName(unsigned long __near *,unsigned long __near *,char __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSocketImpl::GetName(
        GFxSocketImpl *this,
        unsigned int *a2,
        unsigned int *a3,
        PCHAR pNodeBuffer,
        DWORD NodeBufferSize)
{
  u_long v6; // eax
  unsigned int *v7; // ecx
  void *v8; // esi
  struct hostent *v9; // eax
  char **h_addr_list; // edx
  int v11; // ecx
  char **v12; // eax
  u_short v13; // [esp-4h] [ebp-444h]
  int v14; // [esp+Ch] [ebp-434h] BYREF
  GString v15; // [esp+10h] [ebp-430h] BYREF
  unsigned int *v16; // [esp+14h] [ebp-42Ch]
  char name[1028]; // [esp+18h] [ebp-428h] BYREF
  char pServiceBuffer[32]; // [esp+41Ch] [ebp-24h] BYREF

  v13 = *((_WORD *)this + 3);
  v16 = a3;
  *a2 = ntohs(netshort: v13);
  v6 = ntohl(netlong: *((_DWORD *)this + 2));
  v7 = v16;
  *v16 = v6;
  if ( pNodeBuffer != nullptr )
  {
    GHashSetBase<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeAltHashF,GAllocatorLH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GPtr<GFxAmpServer::SwdInfo>,GFixedSizeHash<unsigned long>>::NodeHashF>>::FindAlt<unsigned long>(
      a1: &v14,
      a2: v7);
    if ( v14 != 0 && *(_DWORD *)v14 != 0 && (int)v15.pData <= *(_DWORD *)(*(_DWORD *)v14 + 4) )
    {
      strcpy_s(
        _Dst: pNodeBuffer,
        _SizeInBytes: NodeBufferSize,
        _Src: (const char *)((*(_DWORD *)(*(_DWORD *)v14 + 16 * (int)v15.pData + 20) & 0xFFFFFFFC) + 8));
    }
    else
    {
      if ( getnameinfo(
             pSockaddr: (const SOCKADDR *)((char *)this + 4),
             SockaddrLength: 16,
             pNodeBuffer,
             NodeBufferSize,
             pServiceBuffer,
             ServiceBufferSize: 0x20u,
             Flags: 1) != 0 )
        *pNodeBuffer = 0;
      GString::GString(this: &v15, a2: pNodeBuffer);
      GHash<unsigned long,GString,GFixedSizeHash<unsigned long>,GAllocatorGH<unsigned long,2>,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeHashF>,GHashSet<GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeHashF,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeAltHashF,GAllocatorGH<unsigned long,2>,GHashsetCachedNodeEntry<GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>,GHashNode<unsigned long,GString,GFixedSizeHash<unsigned long>>::NodeHashF>>>::Add(
        a1: v16,
        a2: &v15);
      v8 = (void *)(v15.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v15.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
    }
  }
  if ( *((_DWORD *)this + 7) == 0 && gethostname(name, namelen: 1025) == 0 )
  {
    v9 = gethostbyname(name);
    if ( v9 != nullptr )
    {
      h_addr_list = v9->h_addr_list;
      v11 = 0;
      if ( *h_addr_list != nullptr )
      {
        v12 = v9->h_addr_list;
        while ( *(_DWORD *)*v12 != *((_DWORD *)this + 2) )
        {
          v12 = &h_addr_list[++v11];
          if ( *v12 == nullptr )
            goto LABEL_19;
        }
        *((_DWORD *)this + 7) = *v16;
      }
    }
  }
LABEL_19:
  if ( *((_DWORD *)this + 7) == *v16 )
    *v16 = 2130706433;
}

//------------------------------------------------------------------------------
// Address: 0x1028BE70
// Name: _dynamic_initializer_for__GFxSocketImpl::LibRefLock__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__GFxSocketImpl::LibRefLock__()
{
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)&GFxSocketImpl::LibRefLock, spinCount: 0);
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__GFxSocketImpl::LibRefLock__);
}

//------------------------------------------------------------------------------
// Address: 0x1028CC40
// Name: _dynamic_atexit_destructor_for__GFxSocketImpl::LibRefLock__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GFxSocketImpl::LibRefLock__()
{
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)&GFxSocketImpl::LibRefLock);
}

//------------------------------------------------------------------------------
// Address: 0x1028D6B8
// Name: GFxSocketImpl::LibRefLock$initializer$
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSocketImpl::LibRefLock_initializer_(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this@<ecx>,
        char a2@<of>,
        _BYTE *a3@<eax>,
        char a4@<dl>,
        int a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a6)
{
  if ( !a2 )
  {
    *a3 -= a4;
    JUMPOUT(0x1028D6BC);
  }
  JUMPOUT(0x1028D678);
}

//------------------------------------------------------------------------------
// Address: 0x1028BE90
// Name: _dynamic_initializer_for__defaultSocketFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__defaultSocketFactory__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__defaultSocketFactory__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BEA0
// Name: sub_1028BEA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_1028BEA0()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dword_1035C76C = SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x1028BEC0
// Name: _dynamic_initializer_for____g_CreateIShaderDLLInternal_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateIShaderDLLInternal_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateIShaderDLLInternal_reg,
           fn: (void *(__cdecl *)())GetShaderDLLInternal,
           pName: "ShaderDLL004");
}

//------------------------------------------------------------------------------
// Address: 0x1028BEE0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CTextureReference::CTextureReference(this: (CTextureReference *)&g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BF00
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1028BF10
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BF30
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028BF90
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028BFC0
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BFD0
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x1028CC50
// Name: _dynamic_atexit_destructor_for__defaultSocketFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__defaultSocketFactory__()
{
  defaultSocketFactory = &GMemoryHeap::LimitHandler::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1032FDB8
// Name: GFx_UndoPremultiplyTable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall GFx_UndoPremultiplyTable@<eax>(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        int a4@<ebp>,
        _BYTE *_EDI@<edi>,
        int a6@<esi>,
        CDatamapFieldSizeDeducer<15> *this)
{
  int v7; // ecx
  int v8; // edx
  __int16 v10; // [esp-4h] [ebp-4h]
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  *_EDI = *_EDI;
  *MK_FP(v10, a6) = *MK_FP(v10, a6) - (((unsigned __int8)(*(_BYTE *)(a1 - 534483670) ^ a1) < 0x80u) + a4);
  *MK_FP(v10, a3) = a2 + *MK_FP(v10, a3);
  __asm { lock str word ptr [edi] }
  v7 = -105 * MEMORY[0xC240CC0];
  v8 = *MK_FP(v10, a6) | a2;
  *MK_FP(v10, v7 + 9) = a6 | *MK_FP(v10, v7 + 9);
  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)(a1: v7 - *MK_FP(v10, v7), a2: v8);
}
