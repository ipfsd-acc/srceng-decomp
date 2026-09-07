// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/net_ws.cpp
// Functions: 200
// ============================================================

#include "engine\net_ws.h"

//------------------------------------------------------------------------------
// Address: 0x10010C40
// Name: public: CTSQueue<struct StartSoundParams_t,0,1>::Node_t::Node_t(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<StartSoundParams_t,0,1>::Node_t *__thiscall CTSQueue<StartSoundParams_t,0,1>::Node_t::Node_t(
        CTSQueue<StartSoundParams_t,0,1>::Node_t *this)
{
  CTSQueue<StartSoundParams_t,0,1>::Node_t *result; // eax
  char v2; // cl

  result = this;
  this->elem.userdata = 0;
  this->elem.soundsource = 0;
  this->elem.entchannel = 0;
  this->elem.pSfx = nullptr;
  this->elem.flags = 0;
  this->elem.initialStreamPosition = 0;
  this->elem.skipInitialSamples = 0;
  this->elem.m_pSoundEntryName = nullptr;
  this->elem.m_pOperatorsKV = nullptr;
  v2 = *((_BYTE *)&this->elem + 96);
  result->elem.fvol = 1.0;
  result->elem.soundlevel = SNDLVL_NORM;
  result->elem.pitch = 100;
  result->elem.delay = 0.0;
  result->elem.opStackElapsedTime = 0.0;
  result->elem.opStackElapsedStopTime = 0.0;
  result->elem.speakerentity = -1;
  result->elem.m_nQueuedGUID = -1;
  result->elem.m_nSoundScriptHandle = -1;
  *((_BYTE *)&result->elem + 96) = v2 & 0xC0 | 2;
  result->elem.origin.x = 0.0;
  result->elem.origin.y = 0.0;
  result->elem.origin.z = 0.0;
  result->elem.direction.x = 0.0;
  result->elem.direction.y = 0.0;
  result->elem.direction.z = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013A70
// Name: public: CTSQueue<struct StartSoundParams_t,0,1>::CTSQueue<struct StartSoundParams_t,0,1>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<StartSoundParams_t,0,1> *__thiscall CTSQueue<StartSoundParams_t,0,1>::CTSQueue<StartSoundParams_t,0,1>(
        CTSQueue<StartSoundParams_t,0,1> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v3; // eax
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v4; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  p_m_FreeNodes->m_Head.value32.DepthAndSequence = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&this->m_Count.m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v3 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)MemAlloc_Alloc(nSize: 0x68u);
  if ( v3 != nullptr )
  {
    v4 = CTSQueue<StartSoundParams_t,0,1>::Node_t::Node_t(this: v3);
    this->m_Tail.value.pNode = v4;
    this->m_Head.value.pNode = v4;
    v4->pNext = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)this;
  }
  else
  {
    this->m_Tail.value.pNode = nullptr;
    this->m_Head.value.pNode = nullptr;
    MEMORY[0] = this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013B10
// Name: public: struct CTSQueue<class CFunctor __near *,0,1>::Node_t __near * CTSQueue<class CFunctor __near *,0,1>::Push(struct CTSQueue<class CFunctor __near *,0,1>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<StartSoundParams_t,0,1>::Node_t *__thiscall CTSQueue<CFunctor *,0,1>::Push(
        CTSQueue<StartSoundParams_t,0,1> *this,
        CTSQueue<loopback_t *,0,1>::Node_t *pNode)
{
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v3; // edi
  int i; // [esp-4h] [ebp-10h]

  pNode->pNext = (CTSQueue<loopback_t *,0,1>::Node_t *)this;
  v3 = this->m_Tail.value.pNode;
  for ( i = this->m_Tail.value.sequence;
        (CTSQueue<StartSoundParams_t,0,1> *)_InterlockedCompareExchange(
                                              (volatile signed __int32 *)v3,
                                              (signed __int32)pNode,
                                              (signed __int32)this) != this;
        i = this->m_Tail.value.sequence )
  {
    _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: v3->pNext, a3: i + 1, a4: v3, a5: i);
    v3 = this->m_Tail.value.pNode;
  }
  _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: pNode, a3: i + 1, a4: v3, a5: i);
  _InterlockedExchangeAdd(&this->m_Count.m_value, 1u);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10013BC0
// Name: public: struct CTSQueue<struct StartSoundParams_t,0,1>::Node_t __near * CTSQueue<struct StartSoundParams_t,0,1>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<StartSoundParams_t,0,1>::Node_t *__usercall CTSQueue<StartSoundParams_t,0,1>::Pop@<eax>(
        CTSQueue<StartSoundParams_t,0,1> *this@<ecx>,
        CTSQueue<StartSoundParams_t,0,1>::Node_t *volatile *a2@<ebp>)
{
  CTSQueue<StartSoundParams_t,0,1>::Node_t *pNode; // eax
  CTSQueue<StartSoundParams_t,0,1>::Node_t *pNext; // esi
  float opStackElapsedStopTime; // esi
  _BYTE v7[12]; // [esp-Ch] [ebp-8Ch] BYREF
  StartSoundParams_t elem; // [esp+0h] [ebp-80h] BYREF
  CTSQueue<StartSoundParams_t,0,1> *v9; // [esp+64h] [ebp-1Ch]
  CTSQueue<StartSoundParams_t,0,1>::NodeLink_t head; // [esp+68h] [ebp-18h]
  CTSQueue<StartSoundParams_t,0,1>::NodeLink_t *pHead; // [esp+70h] [ebp-10h]
  CTSQueue<StartSoundParams_t,0,1>::Node_t *volatile *pTailNode; // [esp+74h] [ebp-Ch]
  volatile int *pHeadSequence; // [esp+78h] [ebp-8h]
  volatile int *retaddr; // [esp+80h] [ebp+0h]

  pTailNode = a2;
  pHeadSequence = retaddr;
  v9 = this;
  pHead = &this->m_Tail;
  head.value.sequence = (int)&this->m_Head.value.sequence;
  head.value.pNode = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)&this->m_Tail;
  elem.direction.x = 1.0;
  memset(v7, 0, sizeof(v7));
  memset(&elem, 0, 28);
  LODWORD(elem.direction.y) = 75;
  elem.direction.z = 0.0;
  LODWORD(elem.fvol) = 100;
  elem.soundlevel = SNDLVL_NONE;
  elem.flags = -1;
  elem.pitch = 0;
  elem.delay = 0.0;
  elem.speakerentity = -1;
  LOWORD(elem.initialStreamPosition) = -1;
  memset(&elem.skipInitialSamples, 0, 16);
  LOBYTE(elem.m_pOperatorsKV) = (int)elem.m_pOperatorsKV & 0xC0 | 2;
  while ( 1 )
  {
    while ( 1 )
    {
      do
      {
        do
        {
          pNode = this->m_Head.value.pNode;
          *((_DWORD *)&elem + 24) = *(_DWORD *)head.value.sequence;
          LODWORD(elem.opStackElapsedStopTime) = pNode;
          pNext = pNode->pNext;
        }
        while ( pNode->pNext == nullptr );
      }
      while ( *((_DWORD *)&elem + 24) != *(_DWORD *)head.value.sequence );
      if ( (CTSQueue<StartSoundParams_t,0,1>::Node_t *)LODWORD(elem.opStackElapsedStopTime) == head.value.pNode->pNext )
        break;
      if ( pNext != (CTSQueue<StartSoundParams_t,0,1>::Node_t *)this )
      {
        StartSoundParams_t::operator=(this: (StartSoundParams_t *)v7, __that: &pNext->elem);
        if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                a1: v9,
                                a2: pNext,
                                a3: *((_DWORD *)&elem + 24) + 1,
                                a4: LODWORD(elem.opStackElapsedStopTime),
                                a5: *((_DWORD *)&elem + 24)) != 0 )
        {
          _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
          opStackElapsedStopTime = elem.opStackElapsedStopTime;
          StartSoundParams_t::operator=(
            this: (StartSoundParams_t *)(LODWORD(elem.opStackElapsedStopTime) + 4),
            __that: (const StartSoundParams_t *)v7);
          return (CTSQueue<StartSoundParams_t,0,1>::Node_t *)LODWORD(opStackElapsedStopTime);
        }
      }
    }
    if ( pNext == (CTSQueue<StartSoundParams_t,0,1>::Node_t *)this )
      break;
    _ThreadInterlockedAssignIf64(
      a1: &this->m_Tail,
      a2: pNext,
      a3: pHead->value.sequence + 1,
      a4: LODWORD(elem.opStackElapsedStopTime),
      a5: pHead->value.sequence);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10015850
// Name: public: void CTSQueue<struct StartSoundParams_t,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<StartSoundParams_t,0,1>::Purge(CTSQueue<StartSoundParams_t,0,1> *this)
{
  CTSQueue<StartSoundParams_t,0,1>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  CTSQueue<StartSoundParams_t,0,1>::Node_t *savedregs; // [esp+10h] [ebp+0h] BYREF

  for ( i = CTSQueue<StartSoundParams_t,0,1>::Pop(this, a2: &savedregs);
        i != nullptr;
        i = CTSQueue<StartSoundParams_t,0,1>::Pop(this, a2: &savedregs) )
  {
    free(pMem: i);
  }
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: p_m_FreeNodes,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
      if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    free(pMem: Next);
  }
LABEL_7:
  this->m_Head.value.sequence = 0;
  this->m_Tail.value.sequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100158E0
// Name: public: void CTSQueue<struct StartSoundParams_t,0,1>::PushItem(struct StartSoundParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<StartSoundParams_t,0,1>::PushItem(
        CTSQueue<StartSoundParams_t,0,1> *this,
        const StartSoundParams_t *init)
{
  TSLNodeBase_t *v3; // esi
  CTSQueue<loopback_t *,0,1>::Node_t *v4; // eax

  v3 = CTSListBase::Pop(this: &this->m_FreeNodes);
  if ( v3 != nullptr )
  {
    StartSoundParams_t::operator=(this: (StartSoundParams_t *)(&v3->Next + 1), __that: init);
    CTSQueue<CFunctor *,0,1>::Push(this, pNode: (CTSQueue<loopback_t *,0,1>::Node_t *)v3);
  }
  else
  {
    v4 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 0x68u);
    if ( v4 != nullptr )
    {
      qmemcpy(&v4->elem, init, 0x64u);
      CTSQueue<CFunctor *,0,1>::Push(this, pNode: v4);
    }
    else
    {
      CTSQueue<CFunctor *,0,1>::Push(this, pNode: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F080
// Name: public: struct CTSQueue<struct loopback_t __near *,0,1>::Node_t __near * CTSQueue<struct loopback_t __near *,0,1>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<int,0,1>::Node_t *__thiscall CTSQueue<loopback_t *,0,1>::Pop(CTSQueue<int,0,1> *this)
{
  CTSQueue<int,0,1> *v1; // esi
  CTSQueue<int,0,1> *pNext; // eax
  int sequence; // edi
  CTSQueue<int,0,1>::Node_t *pNode; // [esp-Ch] [ebp-2Ch]
  CTSQueue<int,0,1>::NodeLink_t *head_4; // [esp+4h] [ebp-1Ch]
  int *pHead; // [esp+Ch] [ebp-14h]
  CTSQueue<int,0,1>::NodeLink_t *pTailNode; // [esp+10h] [ebp-10h]

  v1 = this;
  pTailNode = &this->m_Tail;
  pHead = &this->m_Head.value.sequence;
  head_4 = &this->m_Tail;
  while ( 1 )
  {
    do
    {
      while ( 1 )
      {
        do
        {
          pNode = v1->m_Head.value.pNode;
          pNext = (CTSQueue<int,0,1> *)v1->m_Head.value.pNode->pNext;
        }
        while ( pNext == nullptr );
        if ( pNode != head_4->value.pNode )
          break;
        if ( pNext == v1 )
          return nullptr;
        _ThreadInterlockedAssignIf64(
          a1: &v1->m_Tail,
          a2: pNext,
          a3: pTailNode->value.sequence + 1,
          a4: pNode,
          a5: pTailNode->value.sequence);
      }
    }
    while ( pNext == v1 );
    sequence = pNext->m_Head.value.sequence;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNext, a3: *pHead + 1, a4: pNode, a5: *pHead) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  pNode->elem = sequence;
  return pNode;
}

//------------------------------------------------------------------------------
// Address: 0x101B4100
// Name: bool NET_StringToSockaddr(char const __near *,struct sockaddr __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_StringToSockaddr(const char *s, sockaddr *sadr)
{
  char v2; // al
  char *v3; // esi
  u_short v4; // ax
  struct hostent *v6; // eax
  char copy[128]; // [esp+8h] [ebp-80h] BYREF

  _V_memset(dest: sadr, fill: 0, count: 16);
  *(_DWORD *)&sadr->sa_family = 2;
  V_strncpy(pDest: copy, pSrc: s, maxLen: 128);
  v2 = copy[0];
  v3 = copy;
  if ( copy[0] != 0 )
  {
    do
    {
      if ( *v3 == 58 )
      {
        *v3 = 0;
        v4 = atoi(nptr: v3 + 1);
        *(_WORD *)sadr->sa_data = htons(hostshort: v4);
      }
      ++v3;
    }
    while ( *v3 != 0 );
    v2 = copy[0];
  }
  if ( (unsigned __int8)(v2 - 48) <= 9u && _V_strstr(s1: copy, search: ".") != nullptr )
  {
    *(_DWORD *)&sadr->sa_data[2] = inet_addr(cp: copy);
    return 1;
  }
  else
  {
    if ( net_nodns )
      return 0;
    v6 = gethostbyname(name: copy);
    if ( v6 == nullptr )
    {
      return 0;
    }
    else
    {
      *(_DWORD *)&sadr->sa_data[2] = **(_DWORD **)v6->h_addr_list;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B41D0
// Name: void NET_ClearLaggedList(struct netpacket_s __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ClearLaggedList(netpacket_s **pList)
{
  netpacket_s **v1; // eax
  netpacket_s *v2; // esi
  netpacket_s *pNext; // edi

  v1 = pList;
  v2 = *pList;
  if ( *pList != nullptr )
  {
    do
    {
      pNext = v2->pNext;
      if ( v2->data != nullptr )
      {
        free(pMem: v2->data);
        v2->data = nullptr;
      }
      free(pMem: v2);
      v2 = pNext;
    }
    while ( pNext != nullptr );
    v1 = pList;
  }
  *v1 = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101B4220
// Name: bool NET_StringToAdr(char const __near *,struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_StringToAdr(const char *s, netadr_s *a)
{
  char result; // al
  char address[128]; // [esp+0h] [ebp-90h] BYREF
  sockaddr saddr; // [esp+80h] [ebp-10h] BYREF

  V_strncpy(pDest: address, pSrc: s, maxLen: 128);
  if ( V_strncmp(s1: address, s2: "localhost", count: 10) == 0
    || V_strncmp(s1: address, s2: "localhost:", count: 10) == 0 )
  {
    _V_memcpy(dest: address, src: "127.0.0.1", count: 9);
  }
  result = NET_StringToSockaddr(s: address, sadr: &saddr);
  if ( result != 0 )
  {
    netadr_s::SetFromSockadr(this: a, s: &saddr);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B42C0
// Name: int NET_SendStream(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NET_SendStream(SOCKET nSock, const char *buf, int len, int flags)
{
  int v4; // esi
  int Error; // eax
  const char *v7; // eax

  v4 = send(s: nSock, buf, len, flags);
  if ( v4 == -1 )
  {
    Error = WSAGetLastError();
    net_error = Error;
    if ( Error == 10035 )
      return 0;
    v7 = NET_ErrorString(code: Error);
    _Msg(a1: "NET_SendStream: %s\n", v7);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101B4320
// Name: int NET_ReceiveStream(int,char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NET_ReceiveStream(SOCKET nSock, char *buf, int len, int flags)
{
  int v4; // esi
  int Error; // eax
  const char *v6; // eax

  v4 = recv(s: nSock, buf, len, flags);
  if ( v4 != -1 )
    return v4;
  Error = WSAGetLastError();
  net_error = Error;
  if ( Error != 10035 && Error != 10057 )
  {
    v6 = NET_ErrorString(code: Error);
    _Msg(a1: "NET_ReceiveStream: %s\n", v6);
    return v4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B4380
// Name: float NET_GetFakeLag(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl NET_GetFakeLag()
{
  return s_FakeLag;
}

//------------------------------------------------------------------------------
// Address: 0x101B4390
// Name: void NET_GetLocalAddress(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_GetLocalAddress()
{
  char *m_pszString; // eax
  char *v1; // eax
  char buff[512]; // [esp+0h] [ebp-200h] BYREF

  netadr_s::Clear(this: &net_local_adr);
  if ( net_noip )
  {
    _Msg(a1: "TCP/UDP Disabled.\n");
  }
  else
  {
    if ( (ipname.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = ipname.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    if ( _V_strcmp(s1: m_pszString, s2: "localhost") != 0 )
    {
      if ( (ipname.m_nFlags & 0x1000) != 0 )
      {
        v1 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v1 = ipname.m_pParent->m_Value.m_pszString;
        if ( v1 == nullptr )
          v1 = (char *)defaultValue;
      }
      V_strncpy(pDest: buff, pSrc: v1, maxLen: 512);
    }
    else
    {
      gethostname(name: buff, namelen: 512);
      buff[511] = 0;
    }
    NET_StringToAdr(s: buff, a: &net_local_adr);
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&hostip.IConVar,
      value: net_local_adr.ip[3] + ((net_local_adr.ip[2] + ((net_local_adr.ip[1] + (net_local_adr.ip[0] << 8)) << 8)) << 8),
      a2: *(unsigned int *)buff,
      a3: *(int *)&buff[4]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B44A0
// Name: bool NET_IsMultiplayer(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NET_IsMultiplayer()
{
  return net_multiplayer;
}

//------------------------------------------------------------------------------
// Address: 0x101B44B0
// Name: bool NET_IsDedicated(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NET_IsDedicated()
{
  return net_dedicated;
}

//------------------------------------------------------------------------------
// Address: 0x101B44C0
// Name: void NET_SetTime(double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_SetTime(long double realtime)
{
  double v2; // st7
  double frametime; // [esp+8h] [ebp+8h]

  frametime = realtime - s_last_realtime;
  s_last_realtime = realtime;
  v2 = 1.0;
  if ( frametime > 1.0 || (v2 = 0.0, frametime < 0.0) )
    frametime = v2;
  net_time = ((double (__thiscall *)(IEngineToolInternal *))g_pEngineToolInternal->GetTimescale)(a1: g_pEngineToolInternal)
           * frametime
           + net_time;
}

//------------------------------------------------------------------------------
// Address: 0x101B4520
// Name: void NET_InitPostFork(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_InitPostFork()
{
  int v0; // eax

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-NoQueuedPacketThread") != 0 )
    _Warning(a1: "Found -NoQueuedPacketThread, so no queued packet thread will be created.\n");
  else
    g_pQueuedPackedSender->Setup(this: g_pQueuedPackedSender);
}

//------------------------------------------------------------------------------
// Address: 0x101B4560
// Name: void NET_PrintChannelStatus(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_PrintChannelStatus(INetChannel *chan)
{
  const char *v1; // eax
  bool v2; // zf
  const char *v3; // eax
  const char *v4; // eax
  double v5; // st7
  char *v6; // eax
  const char *v7; // eax
  unsigned __int64 v8; // st7
  double v9; // st7
  unsigned __int64 v10; // st7
  double v11; // st7
  unsigned __int64 v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  int v16; // eax
  double v17; // [esp+8h] [ebp-10h]
  double v18; // [esp+8h] [ebp-10h]
  double v19; // [esp+8h] [ebp-10h]
  double v20; // [esp+8h] [ebp-10h]
  double v21; // [esp+8h] [ebp-10h]
  int v22; // [esp+10h] [ebp-8h]
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+10h] [ebp-8h]
  int v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+20h] [ebp+8h]

  v1 = (const char *)chan->GetName(this: chan);
  _Msg(a1: "NetChannel '%s':\n", v1);
  v2 = !chan->IsPlayback(this: chan);
  v3 = "(Demo`)";
  if ( v2 )
    v3 = defaultValue;
  v4 = (const char *)((int (__thiscall *)(INetChannel *, const char *))chan->GetAddress)(a1: chan, a2: v3);
  _Msg(a1: "- remote IP: %s\n", v4);
  v5 = ((double (__thiscall *)(INetChannel *))chan->GetTimeConnected)(a1: chan);
  v6 = COM_FormatSeconds(seconds: (int)v5);
  _Msg(a1: "- online: %s\n", v6);
  v2 = !chan->HasPendingReliableData(this: chan);
  v7 = "pending data";
  if ( v2 )
    v7 = "available";
  _Msg(a1: "- reliable: %s\n", v7);
  *(double *)&v8 = ((double (__thiscall *)(INetChannel *, int))chan->GetAvgLoss)(a1: chan, a2: 1);
  v9 = ((double (__thiscall *)(INetChannel *, _DWORD, _DWORD, _DWORD))chan->GetAvgLatency)(
         a1: chan,
         a2: 0,
         a3: v8,
         a4: HIDWORD(v8));
  _Msg(a1: "- latency: %.1f, loss %.2f\n", v9, v17);
  *(double *)&v10 = ((double (__thiscall *)(INetChannel *, _DWORD, int))chan->GetAvgPackets)(a1: chan, a2: 0, a3: v22);
  v11 = ((double (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetAvgPackets)(
          a1: chan,
          a2: 1,
          a3: v10,
          a4: HIDWORD(v10));
  _Msg(a1: "- packets: in %.1f/s, out %.1f/s\n", v11, v18);
  *(double *)&v12 = ((double (__thiscall *)(INetChannel *, _DWORD, int))chan->GetAvgChoke)(a1: chan, a2: 0, a3: v23);
  v13 = ((double (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetAvgChoke)(
          a1: chan,
          a2: 1,
          a3: v12,
          a4: HIDWORD(v12));
  _Msg(a1: "- choke: in %.2f, out %.2f\n", v13, v19);
  v14 = ((double (__thiscall *)(INetChannel *, _DWORD, int))chan->GetAvgData)(a1: chan, a2: 0, a3: v24);
  v15 = ((double (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetAvgData)(
          a1: chan,
          a2: 1,
          a3: COERCE_UNSIGNED_INT64(v14 * 0.0009765625),
          a4: HIDWORD(COERCE_UNSIGNED_INT64(v14 * 0.0009765625)));
  _Msg(a1: "- flow: in %.1f, out %.1f kB/s\n", v15 * 0.0009765625, v20);
  v16 = ((int (__thiscall *)(INetChannel *, _DWORD, int))chan->GetTotalData)(a1: chan, a2: 0, a3: v25);
  v26 = ((int (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetTotalData)(
          a1: chan,
          a2: 1,
          a3: COERCE_UNSIGNED_INT64((double)v16 * 0.00000095367432),
          a4: HIDWORD(COERCE_UNSIGNED_INT64((double)v16 * 0.00000095367432)));
  _Msg(a1: "- total: in %.1f, out %.1f MB\n\n", (double)v26 * 0.00000095367432, v21);
}

//------------------------------------------------------------------------------
// Address: 0x101B4700
// Name: bool NET_BufferToBufferCompress(char __near *,unsigned int __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_BufferToBufferCompress(char *dest, unsigned int *destLen, char *source, unsigned int sourceLen)
{
  unsigned __int8 *v4; // esi
  CLZSS s; // [esp+Ch] [ebp-10h] BYREF
  unsigned int uCompressedLen; // [esp+18h] [ebp-4h] BYREF

  _V_memcpy(dest, src: source, count: sourceLen);
  s.m_nWindowSize = 4096;
  uCompressedLen = 0;
  v4 = CLZSS::Compress(
         this: &s,
         pInput: (unsigned __int8 *)source,
         inputLength: sourceLen,
         pOutputSize: &uCompressedLen);
  if ( v4 != nullptr )
  {
    if ( uCompressedLen != 0 && uCompressedLen <= *destLen )
    {
      _V_memcpy(dest, src: v4, count: uCompressedLen);
      *destLen = uCompressedLen;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      return 1;
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  }
  _V_memcpy(dest, src: source, count: sourceLen);
  *destLen = sourceLen;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B47B0
// Name: bool NET_BufferToBufferDecompress(char __near *,unsigned int __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_BufferToBufferDecompress(char *dest, unsigned int *destLen, char *source, unsigned int sourceLen)
{
  unsigned int ActualSize; // eax
  CLZSS s; // [esp+Ch] [ebp-Ch] BYREF

  s.m_nWindowSize = 4096;
  if ( CLZSS::IsCompressed(this: &s, pInput: (unsigned __int8 *)source) )
  {
    ActualSize = CLZSS::GetActualSize(this: &s, pInput: (unsigned __int8 *)source);
    if ( ActualSize > *destLen )
    {
      _Warning(
        a1: "NET_BufferToBufferDecompress with improperly sized dest buffer (%u in, %u needed)\n",
        *destLen,
        ActualSize);
      return 0;
    }
    *destLen = CLZSS::SafeUncompress(
                 this: &s,
                 pInput: (unsigned __int8 *)source,
                 pOutput: (unsigned __int8 *)dest,
                 unBufSize: *destLen);
    return 1;
  }
  else
  {
    if ( sourceLen > *destLen )
    {
      _Warning(
        a1: "NET_BufferToBufferDecompress with improperly sized dest buffer (%u in, %u needed)\n",
        *destLen,
        sourceLen);
      return 0;
    }
    _V_memcpy(dest, src: source, count: sourceLen);
    *destLen = sourceLen;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B48E0
// Name: void NET_AddToLagged(struct netpacket_s __near * __near *,struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_AddToLagged(netpacket_s **pList, netpacket_s *pPacket)
{
  netpacket_s *v2; // ebx
  netadr_s *v3; // eax
  netpacket_s *v4; // esi
  unsigned __int8 *v5; // eax
  int v6; // eax

  v2 = nullptr;
  if ( pPacket->pNext != nullptr )
  {
    _Msg(a1: "NET_AddToLagged::Packet already linked\n");
  }
  else
  {
    v3 = (netadr_s *)MemAlloc_Alloc(nSize: 0x50u);
    v4 = (netpacket_s *)v3;
    if ( v3 != nullptr )
    {
      netadr_s::SetIP(this: v3, unIP: 0);
      netadr_s::SetPort(this: &v4->from, newport: 0);
      netadr_s::SetType(this: &v4->from, newtype: NA_IP);
      v4->message.m_bOverflow = false;
      v4->message.m_pDebugName = nullptr;
      v4->message.m_nDataBytes = 0;
      v4->message.m_nDataBits = -1;
      v2 = v4;
    }
    qmemcpy(v2, pPacket, sizeof(netpacket_s));
    v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: pPacket->size);
    v2->data = v5;
    _V_memcpy(dest: v5, src: pPacket->data, count: pPacket->size);
    v2->pNext = nullptr;
    v6 = (int)*pList;
    if ( *pList != nullptr )
    {
      for ( ; *(_DWORD *)(v6 + 76) != 0; v6 = *(_DWORD *)(v6 + 76) )
        ;
      *(_DWORD *)(v6 + 76) = v2;
    }
    else
    {
      *pList = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B49A0
// Name: void NET_AdjustLag(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_AdjustLag()
{
  long double v0; // st5
  long double v1; // st6
  long double v2; // st7
  float m_fValue; // xmm1_4
  long double v4; // st6
  long double v5; // st6
  float v6; // xmm1_4
  float v7; // xmm0_4
  float diff; // [esp+0h] [ebp-Ch]
  float converge; // [esp+4h] [ebp-8h]
  float v10; // [esp+8h] [ebp-4h]

  v0 = 0.0;
  if ( net_time - s_LastTime < 0.0 || (v0 = net_time - s_LastTime, v1 = 0.2000000029802322, v0 <= 0.2000000029802322) )
    v1 = v0;
  v2 = v1;
  m_fValue = fakelag.m_pParent->m_Value.m_fValue;
  s_LastTime = net_time;
  if ( m_fValue != s_FakeLag )
  {
    v4 = m_fValue - s_FakeLag;
    diff = v4;
    v5 = fabs(v4);
    if ( v2 * 200.0 <= v5 )
    {
      converge = v2 * 200.0;
      v6 = converge;
    }
    else
    {
      v10 = v5;
      v6 = v10;
    }
    if ( diff >= 0.0 )
      v7 = s_FakeLag + v6;
    else
      v7 = s_FakeLag - v6;
    s_FakeLag = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4A60
// Name: bool NET_LagPacket(bool,struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall NET_LagPacket@<al>(unsigned int a1@<ebx>, bool newdata, netpacket_s *packet)
{
  int source; // ecx
  int m_nValue; // eax
  ConVar *m_pParent; // edx
  float m_fValue; // xmm0_4
  int v8; // eax
  float v9; // xmm0_4
  int v10; // edi
  netpacket_s **v11; // esi
  netpacket_s *v12; // esi
  float v13; // xmm1_4
  float v14; // xmm0_4
  double v15; // st7
  int v16; // [esp+0h] [ebp-10h]
  float v17; // [esp+Ch] [ebp-4h]

  source = packet->source;
  if ( source >= 3 )
    return newdata;
  if ( droppackets.m_pParent != nullptr )
  {
    m_nValue = droppackets.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 && newdata && source == 0 )
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&droppackets.IConVar, value: m_nValue - 1, a2: a1, a3: v16);
      return 0;
    }
  }
  m_pParent = fakeloss.m_pParent;
  if ( fakeloss.m_pParent->m_Value.m_fValue != 0.0 && newdata )
  {
    ++losscount[source];
    m_fValue = m_pParent->m_Value.m_fValue;
    if ( m_fValue <= 0.0 )
    {
      source = (int)fabs(m_pParent->m_Value.m_fValue);
      if ( source < 2 )
        source = 2;
      if ( losscount[packet->source] % source == 0 )
        return 0;
    }
    else
    {
      v8 = _RandomInt(this: (IUniformRandomStream *)source, a2: 0, a3: 100);
      source = (int)m_fValue;
      if ( v8 <= (int)m_fValue )
        return 0;
    }
  }
  v9 = s_FakeLag;
  if ( s_FakeLag > 0.0 )
  {
    if ( newdata )
    {
      NET_AddToLagged(pList: &s_pLagData[packet->source], pPacket: packet);
      v9 = s_FakeLag;
    }
    v12 = s_pLagData[packet->source];
    if ( v12 == nullptr )
      return 0;
    v13 = fakejitter.m_pParent->m_Value.m_fValue;
    v17 = v9;
    if ( v13 <= 0.0 )
    {
      v15 = v9;
    }
    else
    {
      v14 = v9 * 0.5;
      if ( v14 > v13 )
        v14 = fakejitter.m_pParent->m_Value.m_fValue;
      v15 = _RandomFloat(
              this: (IUniformRandomStream *)source,
              a2: COERCE_FLOAT(LODWORD(v14) ^ _mask__NegFloat_),
              a3: v14)
          + v17;
    }
    if ( v15 * 0.001 + v12->received <= net_time )
    {
      s_pLagData[packet->source] = v12->pNext;
      packet->source = v12->source;
      packet->from = v12->from;
      packet->pNext = nullptr;
      packet->received = net_time;
      packet->size = v12->size;
      packet->wiresize = v12->wiresize;
      packet->stream = v12->stream;
      _V_memcpy(dest: packet->data, src: v12->data, count: v12->size);
      free(pMem: v12->data);
      free(pMem: v12);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v10 = 0;
    v11 = s_pLagData;
    do
    {
      if ( v10 < 3 && *v11 != nullptr )
        NET_ClearLaggedList(pList: v11);
      ++v11;
      ++v10;
    }
    while ( (int)v11 < (int)&net_multiplayer );
    return newdata;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4C80
// Name: DescribeSocket
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DescribeSocket(void *sock)
{
  const tokenset_t<enum ESocketIndex_t> *v1; // eax

  v1 = s_SocketDescMap;
  if ( "cl" == nullptr )
    return "??";
  while ( (void *)v1->token != sock )
  {
    ++v1;
    if ( v1->name == nullptr )
      return "??";
  }
  return v1->name;
}

//------------------------------------------------------------------------------
// Address: 0x101B4CB0
// Name: int NET_SendToImpl(unsigned int,char const __near *,int,struct sockaddr const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NET_SendToImpl(unsigned int s, char *buf, int len, const sockaddr *to, int tolen, int iGameDataLength)
{
  char *v6; // eax
  int v8; // [esp-10h] [ebp-34h]
  _WSABUF buffers[2]; // [esp+0h] [ebp-24h] BYREF
  netadr_s toAdr; // [esp+10h] [ebp-14h] BYREF
  int nSend; // [esp+1Ch] [ebp-8h] BYREF
  int nDataBytes; // [esp+20h] [ebp-4h] BYREF

  nSend = 0;
  if ( !net_dedicatedForXbox )
    return g_pSteamSocketMgr->sendto(this: g_pSteamSocketMgr, a2: s, a3: buf, a4: len, a5: 0, a6: to, a7: tolen);
  if ( iGameDataLength == -1 )
    nDataBytes = (unsigned __int16)len;
  else
    nDataBytes = (unsigned __int16)iGameDataLength;
  if ( voice_xsend_debug.m_pParent != nullptr
    && voice_xsend_debug.m_pParent->m_Value.m_nValue != 0
    && iGameDataLength >= 0
    && iGameDataLength != len )
  {
    DevMsg(a1: "XVoice: VDP packet to %d with unencrypted %d bytes out of %d bytes\n", s, len - iGameDataLength, len);
  }
  buffers[0].len = 2;
  buffers[0].buf = (char *)&nDataBytes;
  buffers[1].len = len;
  buffers[1].buf = buf;
  if ( (unsigned __int16)nDataBytes < len
    && voice_verbose.m_pParent != nullptr
    && voice_verbose.m_pParent->m_Value.m_nValue != 0 )
  {
    netadr_s::SetIP(this: &toAdr, unIP: 0);
    netadr_s::SetPort(this: &toAdr, newport: 0);
    netadr_s::SetType(this: &toAdr, newtype: NA_IP);
    netadr_s::SetFromSockadr(this: &toAdr, s: to);
    v8 = len - (unsigned __int16)nDataBytes;
    v6 = netadr_s::ToString(this: &toAdr, baseOnly: false);
    _Msg(a1: "* NET_SendToImpl: sending voice to %s (%d bytes)\n", v6, v8);
  }
  WSASendTo(
    s,
    lpBuffers: buffers,
    dwBufferCount: 2u,
    lpNumberOfBytesSent: (LPDWORD)&nSend,
    dwFlags: 0,
    lpTo: to,
    iTolen: tolen,
    lpOverlapped: nullptr,
    lpCompletionRoutine: nullptr);
  return nSend;
}

//------------------------------------------------------------------------------
// Address: 0x101B4DE0
// Name: NET_SendTo
// Source: json
//------------------------------------------------------------------------------
int __usercall NET_SendTo@<eax>(
        int len@<edi>,
        const sockaddr *to@<esi>,
        unsigned int verbose,
        char *s,
        const char *buf,
        int tolen)
{
  if ( *(_DWORD *)&to->sa_data[2] == 0 && *(_WORD *)to->sa_data == 0 )
    return len;
  if ( (CL_IsHL2Demo() || CL_IsPortalDemo()) && !net_dedicated )
    _Error(a1: defaultValue);
  return NET_SendToImpl(s: verbose, buf: s, len, to, tolen: (int)buf, iGameDataLength: tolen);
}

//------------------------------------------------------------------------------
// Address: 0x101B4EA0
// Name: public: void CUtlMemory<unsigned char,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::ConvertToGrowableMemory(
        CUtlMemory<unsigned char,int> *this,
        int nGrowSize)
{
  unsigned int m_nAllocationCount; // edi
  unsigned __int8 *v4; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    this->m_nGrowSize = nGrowSize;
    if ( m_nAllocationCount != 0 )
    {
      v4 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
      memcpy(dst: v4, src: this->m_pMemory, count: m_nAllocationCount);
      this->m_pMemory = v4;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5040
// Name: class CNetChan __near * NET_FindNetChannel(int,struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
CNetChan *__cdecl NET_FindNetChannel(int socket, netadr_s *adr)
{
  DWORD CurrentThreadId; // ecx
  int v3; // edi
  int m_Size; // ebx
  CNetChan *v5; // esi
  const netadr_s *v6; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_NetChannels.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_NetChannels.m_depth;
  }
  v3 = 0;
  m_Size = s_NetChannels.m_Size;
  if ( s_NetChannels.m_Size <= 0 )
  {
LABEL_9:
    if ( --s_NetChannels.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v5 = s_NetChannels.m_Memory.m_pMemory[v3];
      if ( socket == v5->GetSocket(this: v5) )
      {
        v6 = v5->GetRemoteAddress(this: v5);
        if ( netadr_s::CompareAdr(this: adr, a: v6, onlyBase: false) )
          break;
      }
      if ( ++v3 >= m_Size )
        goto LABEL_9;
    }
    if ( --s_NetChannels.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5110
// Name: void NET_CloseSocket(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_CloseSocket(SOCKET hSocket, int sock)
{
  const char *v2; // eax

  if ( hSocket != 0 )
  {
    if ( closesocket(s: hSocket) == -1 )
    {
      net_error = WSAGetLastError();
      v2 = NET_ErrorString(code: net_error);
      ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v2);
    }
    if ( sock >= 0 && net_sockets.m_Memory.m_pMemory[sock].hTCP == hSocket )
    {
      net_sockets.m_Memory.m_pMemory[sock].hTCP = 0;
      net_sockets.m_Memory.m_pMemory[sock].bListening = false;
    }
    g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: sock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5190
// Name: int NET_OpenSocket(char const __near *,int __near &,int)
// Source: json
//------------------------------------------------------------------------------
SOCKET __cdecl NET_OpenSocket(const char *net_interface, int *port, unsigned int protocol)
{
  unsigned int v3; // edi
  SOCKET v4; // eax
  SOCKET v5; // esi
  int Error; // eax
  const char *v7; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  int v16; // eax
  const char *v17; // eax
  int v18; // ebx
  int v19; // eax
  bool v20; // zf
  int v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  sockaddr_in address; // [esp+Ch] [ebp-14h] BYREF
  linger optlinger; // [esp+1Ch] [ebp-4h] BYREF

  v3 = protocol;
  if ( protocol == 6 )
    v4 = socket(af: 2, type: 1, protocol: 6);
  else
    v4 = socket(af: 2, type: 2, protocol);
  v5 = v4;
  if ( v4 == -1 )
  {
    Error = WSAGetLastError();
    net_error = Error;
    if ( Error != 10047 )
    {
      v7 = NET_ErrorString(code: Error);
      _Msg(a1: "WARNING: NET_OpenSockett: socket failed: %s", v7);
    }
    return 0;
  }
  else
  {
    protocol = 1;
    if ( ioctlsocket(s: v4, cmd: -2147195266, argp: &protocol) == -1 )
    {
      net_error = WSAGetLastError();
      v9 = NET_ErrorString(code: net_error);
      _Msg(a1: "WARNING: NET_OpenSocket: ioctl FIONBIO: %s\n", v9);
    }
    protocol = 1;
    if ( v3 == 6 )
    {
      if ( setsockopt(s: v5, level: 0xFFFF, optname: 8, optval: (const char *)&protocol, optlen: 4) == -1 )
      {
        net_error = WSAGetLastError();
        v10 = NET_ErrorString(code: net_error);
        _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_KEEPALIVE: %s\n", v10);
        return 0;
      }
      else
      {
        optlinger = 0;
        if ( setsockopt(s: v5, level: 0xFFFF, optname: 128, optval: (const char *)&optlinger, optlen: 4) == -1 )
        {
          net_error = WSAGetLastError();
          v11 = NET_ErrorString(code: net_error);
          _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_LINGER: %s\n", v11);
          return 0;
        }
        else
        {
          protocol = 1;
          if ( setsockopt(s: v5, level: 6, optname: 1, optval: (const char *)&protocol, optlen: 4) == -1 )
          {
            net_error = WSAGetLastError();
            v12 = NET_ErrorString(code: net_error);
            _Msg(a1: "WARNING: NET_OpenSocket: setsockopt TCP_NODELAY: %s\n", v12);
            return 0;
          }
          else
          {
            protocol = 96016;
            if ( setsockopt(s: v5, level: 0xFFFF, optname: 4097, optval: (const char *)&protocol, optlen: 4) == -1 )
            {
              net_error = WSAGetLastError();
              v13 = NET_ErrorString(code: net_error);
              _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_SNDBUF: %s\n", v13);
              return 0;
            }
            else
            {
              protocol = 96016;
              if ( setsockopt(s: v5, level: 0xFFFF, optname: 4098, optval: (const char *)&protocol, optlen: 4) == -1 )
              {
                net_error = WSAGetLastError();
                v14 = NET_ErrorString(code: net_error);
                _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_RCVBUF: %s\n", v14);
                return 0;
              }
              else
              {
                return v5;
              }
            }
          }
        }
      }
    }
    else if ( setsockopt(s: v5, level: 0xFFFF, optname: 32, optval: (const char *)&protocol, optlen: 4) == -1 )
    {
      net_error = WSAGetLastError();
      v15 = NET_ErrorString(code: net_error);
      _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_BROADCAST: %s\n", v15);
      return 0;
    }
    else
    {
      v16 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 40))(a1: v16, a2: "-reuse") != 0
        && (protocol = 1, setsockopt(s: v5, level: 0xFFFF, optname: 4, optval: (const char *)&protocol, optlen: 4) == -1) )
      {
        net_error = WSAGetLastError();
        v17 = NET_ErrorString(code: net_error);
        _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_REUSEADDR: %s\n", v17);
        return 0;
      }
      else
      {
        v18 = 0;
        if ( net_interface != nullptr && *net_interface != 0 && _V_strcmp(s1: net_interface, s2: "localhost") != 0 )
          NET_StringToSockaddr(s: net_interface, sadr: (sockaddr *)&address);
        else
          address.sin_addr.S_un.S_addr = 0;
        address.sin_family = 2;
        optlinger = (linger)10;
        if ( g_nForkID > 0 )
          optlinger = (linger)150;
        while ( 1 )
        {
          address.sin_port = *port == -1 ? 0 : htons(hostshort: v18 + *(_WORD *)port);
          if ( bind(s: v5, name: (const struct sockaddr *)&address, namelen: 16) != -1 )
            break;
          v19 = WSAGetLastError();
          v20 = *port == -1;
          net_error = v19;
          if ( v20 || v19 != 10048 )
          {
            v22 = NET_ErrorString(code: v19);
            _Msg(a1: "WARNING: NET_OpenSocket: bind: %s\n", v22);
            goto LABEL_46;
          }
          if ( ++v18 >= *(_DWORD *)&optlinger )
            goto LABEL_40;
        }
        v21 = *port;
        if ( *port != -1 && v18 != 0 )
        {
          *port = v18 + v21;
          _ConDMsg(a1: "Socket bound to non-default port %i because original port was already in use.\n", v18 + v21);
        }
LABEL_40:
        if ( v18 != optlinger )
          return v5;
        _Msg(a1: "WARNING: UDP_OpenSocket: unable to bind socket\n");
LABEL_46:
        if ( v5 != 0 )
        {
          if ( closesocket(s: v5) == -1 )
          {
            net_error = WSAGetLastError();
            v23 = NET_ErrorString(code: net_error);
            ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v23);
          }
          g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
        }
        return 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5580
// Name: int NET_ConnectSocket(int,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NET_ConnectSocket(int sock, netadr_s *addr)
{
  int v2; // ebx
  int v3; // esi
  int *p_hTCP; // edi
  char *m_pszString; // eax
  SOCKET v6; // eax
  int Error; // eax
  const char *v9; // eax
  sockaddr saddr; // [esp+Ch] [ebp-10h] BYREF

  v2 = sock;
  v3 = sock;
  p_hTCP = &net_sockets.m_Memory.m_pMemory[sock].hTCP;
  if ( *p_hTCP != 0 )
    NET_CloseSocket(hSocket: *p_hTCP, sock);
  if ( net_notcp )
    return 0;
  netadr_s::ToSockadr(this: addr, s: &saddr);
  sock = -1;
  if ( (ipname.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = ipname.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v6 = NET_OpenSocket(net_interface: m_pszString, port: &sock, protocol: 1u);
  *p_hTCP = v6;
  if ( v6 == 0 )
  {
    _Msg(
      a1: "Warning! NET_ConnectSocket failed opening socket %i, port %i.\n",
      v2,
      net_sockets.m_Memory.m_pMemory[v3].nPort);
    return 0;
  }
  if ( connect(s: v6, name: &saddr, namelen: 16) != -1 )
    return net_sockets.m_Memory.m_pMemory[v3].hTCP;
  Error = WSAGetLastError();
  net_error = Error;
  if ( Error == 10035 )
    return net_sockets.m_Memory.m_pMemory[v3].hTCP;
  v9 = NET_ErrorString(code: Error);
  _Msg(a1: "NET_ConnectSocket: %s\n", v9);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B5680
// Name: unsigned short NET_GetUDPPort(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl NET_GetUDPPort(int socket)
{
  if ( socket < 0 || socket >= net_sockets.m_Size )
    return 0;
  else
    return net_sockets.m_Memory.m_pMemory[socket].nPort;
}

//------------------------------------------------------------------------------
// Address: 0x101B56B0
// Name: void NET_ListenSocket(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ListenSocket(int sock, bool bListen)
{
  netsocket_t *v2; // esi
  SOCKET hTCP; // eax
  char *m_pszString; // ebx
  SOCKET v5; // eax
  u_short v6; // ax
  int Error; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  SOCKET v11; // [esp-10h] [ebp-28h]
  sockaddr_in address; // [esp+8h] [ebp-10h] BYREF

  v2 = &net_sockets.m_Memory.m_pMemory[sock];
  hTCP = v2->hTCP;
  if ( hTCP != 0 )
    NET_CloseSocket(hSocket: hTCP, sock);
  if ( net_multiplayer && !net_notcp && bListen )
  {
    if ( (ipname.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = ipname.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    v5 = NET_OpenSocket(net_interface: m_pszString, port: &v2->nPort, protocol: 1u);
    v2->hTCP = v5;
    if ( v5 != 0 )
    {
      if ( m_pszString != nullptr && *m_pszString != 0 && _V_strcmp(s1: m_pszString, s2: "localhost") != 0 )
        NET_StringToSockaddr(s: m_pszString, sadr: (sockaddr *)&address);
      else
        address.sin_addr.S_un.S_addr = 0;
      address.sin_family = 2;
      v6 = htons(hostshort: v2->nPort);
      v11 = v2->hTCP;
      address.sin_port = v6;
      if ( bind(s: v11, name: (const struct sockaddr *)&address, namelen: 16) == -1 )
      {
        Error = WSAGetLastError();
        v8 = v2->hTCP;
        net_error = Error;
        _Msg(a1: "WARNING: NET_ListenSocket bind failed on socket %i, port %i.\n", v8, v2->nPort);
      }
      else if ( listen(s: v2->hTCP, backlog: 8) == -1 )
      {
        v9 = WSAGetLastError();
        v10 = v2->hTCP;
        net_error = v9;
        _Msg(a1: "WARNING: NET_ListenSocket listen failed on socket %i, port %i.\n", v10, v2->nPort);
      }
      else
      {
        v2->bListening = true;
      }
    }
    else
    {
      _Msg(
        a1: "Warning! NET_ListenSocket failed opening socket %i, port %i.\n",
        sock,
        net_sockets.m_Memory.m_pMemory[sock].nPort);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5820
// Name: net_channels
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_channels()
{
  int m_Size; // edi
  DWORD CurrentThreadId; // ecx
  int i; // esi

  m_Size = s_NetChannels.m_Size;
  if ( s_NetChannels.m_Size != 0 )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_NetChannels.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_NetChannels.m_depth;
    }
    for ( i = 0; i < m_Size; ++i )
      NET_PrintChannelStatus(chan: s_NetChannels.m_Memory.m_pMemory[i]);
    if ( --s_NetChannels.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
  }
  else
  {
    ConMsg(a1: "No active net channels.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B58C0
// Name: net_status
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_status()
{
  DWORD CurrentThreadId; // ecx
  int m_Size; // esi
  char *v2; // eax
  const char *v3; // ecx
  const char *v4; // eax
  int v5; // esi
  int i; // edi
  int nPort; // ecx
  const tokenset_t<enum ESocketIndex_t> *v8; // eax
  const char *name; // eax
  int v10; // edi
  CNetChan *v11; // esi
  double v12; // st7
  float v13; // [esp+1Ch] [ebp-24h]
  float v14; // [esp+20h] [ebp-20h]
  float v15; // [esp+24h] [ebp-1Ch]
  float v16; // [esp+28h] [ebp-18h]
  int v17; // [esp+2Ch] [ebp-14h]
  float v18; // [esp+2Ch] [ebp-14h]
  float v19; // [esp+30h] [ebp-10h]
  float v20; // [esp+34h] [ebp-Ch]
  __int64 v21; // [esp+38h] [ebp-8h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_NetChannels.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_NetChannels.m_depth;
  }
  m_Size = s_NetChannels.m_Size;
  v17 = s_NetChannels.m_Size;
  v2 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
  ConMsg(a1: "Net status for host %s:\n", v2);
  v3 = "dedicated";
  if ( !net_dedicated )
    v3 = "listen";
  v4 = "Multiplayer";
  if ( !net_multiplayer )
    v4 = "Singleplayer";
  ConMsg(a1: "- Config: %s, %s, %i connections\n", v4, v3, m_Size);
  ConMsg(a1: "- Ports: ");
  v5 = 0;
  for ( i = 0; i < 3; ++i )
  {
    if ( v5 < 0 || v5 >= net_sockets.m_Size )
      LOWORD(nPort) = 0;
    else
      nPort = net_sockets.m_Memory.m_pMemory[i].nPort;
    v8 = s_SocketDescMap;
    if ( "cl" != nullptr )
    {
      while ( v8->token != v5 )
      {
        ++v8;
        if ( v8->name == nullptr )
          goto LABEL_17;
      }
      name = v8->name;
    }
    else
    {
LABEL_17:
      name = "??";
    }
    ConMsg(a1: "%s%d %u, ", name, v5++, (unsigned __int16)nPort);
  }
  ConMsg(a1: "%d total.\n", 3);
  if ( v17 <= 0 )
  {
    if ( --s_NetChannels.m_depth != 0 )
      return;
    goto LABEL_26;
  }
  v10 = 0;
  v15 = 0.0;
  v16 = 0.0;
  v21 = 0;
  v13 = 0.0;
  v14 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  do
  {
    v11 = s_NetChannels.m_Memory.m_pMemory[v10];
    v15 = ((double (__thiscall *)(CNetChan *, _DWORD))v11->GetAvgLatency)(a1: v11, a2: 0) + v15;
    v16 = ((double (__thiscall *)(CNetChan *, int))v11->GetAvgLatency)(a1: v11, a2: 1) + v16;
    v14 = ((double (__thiscall *)(CNetChan *, int))v11->GetAvgLoss)(a1: v11, a2: 1) + v14;
    v13 = ((double (__thiscall *)(CNetChan *, _DWORD))v11->GetAvgLoss)(a1: v11, a2: 0) + v13;
    *((float *)&v21 + 1) = ((double (__thiscall *)(CNetChan *, int))v11->GetAvgPackets)(a1: v11, a2: 1)
                         + *((float *)&v21 + 1);
    *(float *)&v21 = ((double (__thiscall *)(CNetChan *, _DWORD))v11->GetAvgPackets)(a1: v11, a2: 0) + *(float *)&v21;
    v20 = ((double (__thiscall *)(CNetChan *, int))v11->GetAvgData)(a1: v11, a2: 1) + v20;
    ++v10;
    v19 = ((double (__thiscall *)(CNetChan *, _DWORD))v11->GetAvgData)(a1: v11, a2: 0) + v19;
  }
  while ( v10 < v17 );
  v12 = 1.0 / (double)v17;
  v18 = v12;
  ConMsg(a1: "- Latency: avg out %.2fs, in %.2fs\n", v12 * v15, v16 * v12);
  ConMsg(a1: "- Loss:    avg out %.1f, in %.1f\n", v18 * v13, v14 * v18);
  ConMsg(a1: "- Packets: net total out  %.1f/s, in %.1f/s\n", *(float *)&v21, *((float *)&v21 + 1));
  ConMsg(a1: "           per client out %.1f/s, in %.1f/s\n", v18 * *(float *)&v21, *((float *)&v21 + 1) * v18);
  ConMsg(a1: "- Data:    net total out  %.1f, in %.1f kB/s\n", 0.0009765625 * v19, v20 * 0.0009765625);
  ConMsg(a1: "           per client out %.1f, in %.1f kB/s\n", 0.0009765625 * (v18 * v19), v20 * v18 * 0.0009765625);
  if ( --s_NetChannels.m_depth == 0 )
LABEL_26:
    _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B5BB0
// Name: void NET_SleepUntilMessages(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_SleepUntilMessages(int nMilliseconds)
{
  int hUDP; // eax
  fd_set fdset; // [esp+0h] [ebp-10Ch] BYREF
  timeval tv; // [esp+104h] [ebp-8h] BYREF

  fdset.fd_count = 0;
  hUDP = net_sockets.m_Memory.m_pMemory[1].hUDP;
  if ( hUDP != 0 )
  {
    tv.tv_usec = 1000 * nMilliseconds;
    tv.tv_sec = 0;
    fdset.fd_array[0] = hUDP;
    fdset.fd_count = 1;
    select(nfds: hUDP + 1, readfds: &fdset, writefds: nullptr, exceptfds: nullptr, timeout: &tv);
  }
  else
  {
    Sys_Sleep(msec: nMilliseconds);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5C20
// Name: bool NET_GetPublicAdr(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_GetPublicAdr(netadr_s *adr)
{
  char v1; // bl
  unsigned __int16 nPort; // di
  char *v3; // eax
  char *m_pszString; // eax
  CSteam3Server *v6; // eax
  CSteam3Server *v7; // eax
  unsigned int v8; // eax

  v1 = 0;
  if ( net_sockets.m_Size <= 1 )
    nPort = 0;
  else
    nPort = net_sockets.m_Memory.m_pMemory[1].nPort;
  if ( (net_public_adr.m_nFlags & 0x1000) != 0
    || (v3 = net_public_adr.m_pParent->m_Value.m_pszString) != nullptr && *v3 != 0 )
  {
    v1 = 1;
    netadr_s::SetType(this: adr, newtype: NA_IP);
    if ( (net_public_adr.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = net_public_adr.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    netadr_s::SetFromString(this: adr, pch: m_pszString, bUseDNS: 0);
    if ( netadr_s::GetPort(this: adr) == 0 )
    {
      netadr_s::SetPort(this: adr, newport: nPort);
      return 1;
    }
  }
  else if ( net_dedicated )
  {
    v6 = Steam3Server();
    if ( v6->m_pSteamGameServer->GetPublicIP(this: v6->m_pSteamGameServer) != 0 )
    {
      v1 = 1;
      netadr_s::SetType(this: adr, newtype: NA_IP);
      v7 = Steam3Server();
      v8 = v7->m_pSteamGameServer->GetPublicIP(this: v7->m_pSteamGameServer);
      netadr_s::SetIP(this: adr, unIP: v8);
      netadr_s::SetPort(this: adr, newport: nPort);
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101B5D10
// Name: public: void CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(
        CUtlMemoryFixedGrowable<unsigned char,4096,int> *this,
        int num)
{
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc_vtbl *v4; // edx

  if ( this->m_nAllocationCount < num )
  {
    if ( this->m_nGrowSize < 0 )
      CUtlMemory<unsigned char,int>::ConvertToGrowableMemory(this, nGrowSize: this->m_nMallocGrowSize);
    if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
    {
      m_pMemory = this->m_pMemory;
      this->m_nAllocationCount = num;
      v4 = _g_pMemAlloc->__vftable;
      if ( m_pMemory != nullptr )
        this->m_pMemory = (unsigned __int8 *)((int (__stdcall *)(unsigned __int8 *, int))v4->Realloc_2)(
                                               a1: m_pMemory,
                                               a2: num);
      else
        this->m_pMemory = (unsigned __int8 *)((int (__stdcall *)(int))v4->Alloc_2)(a1: num);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5EF0
// Name: void NET_DiscardStaleSplitpackets(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_DiscardStaleSplitpackets(int sock)
{
  int v1; // esi
  CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int> > *v2; // edi
  int v3; // ebx

  if ( sock >= 0 && sock < net_splitpackets.m_Size )
  {
    v1 = net_splitpackets.m_Memory.m_pMemory[sock].m_Size - 1;
    v2 = &net_splitpackets.m_Memory.m_pMemory[sock];
    if ( v1 >= 0 )
    {
      v3 = v1;
      do
      {
        if ( v2->m_Memory.m_pMemory[v3].lastactivetime + 15.0 <= net_time )
        {
          if ( v2->m_Size - v1 - 1 > 0 )
            _V_memmove(
              dest: &v2->m_Memory.m_pMemory[v3],
              src: &v2->m_Memory.m_pMemory[v3 + 1],
              count: 96728 * (v2->m_Size - v1 - 1));
          --v2->m_Size;
        }
        --v3;
        --v1;
      }
      while ( v1 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5F80
// Name: void NET_ProcessPending(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ProcessPending()
{
  DWORD CurrentThreadId; // ecx
  int v1; // esi
  int v2; // edi
  pendingsocket_t *v3; // ebx
  long double v4; // st7
  SOCKET newsock; // eax
  const char *v6; // eax
  int v7; // eax
  int Error; // eax
  const char *v9; // eax
  int m_nBitsAvail; // esi
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v13; // edx
  unsigned int m_nInBufWord; // ebx
  int v15; // edi
  int v16; // edi
  unsigned int v17; // ebx
  unsigned int v18; // edx
  unsigned int v19; // eax
  DWORD v20; // eax
  int v21; // ebx
  CNetChan *v22; // esi
  int v23; // eax
  pendingsocket_t *v24; // edi
  int v25; // eax
  char *v26; // eax
  pendingsocket_t *v27; // edi
  CNetChan_vtbl *v28; // eax
  void (__thiscall *ResetStreaming)(struct CNetChan *); // edx
  char *v30; // eax
  char *v31; // eax
  const char *v32; // eax
  bf_read header; // [esp+4h] [ebp-44h] BYREF
  char headerBuf[5]; // [esp+28h] [ebp-20h] BYREF
  int v35; // [esp+30h] [ebp-18h]
  int i; // [esp+34h] [ebp-14h]
  unsigned int v37; // [esp+38h] [ebp-10h]
  int m_nInBufWord_low; // [esp+3Ch] [ebp-Ch]
  pendingsocket_t *psock; // [esp+40h] [ebp-8h]
  bool bOK; // [esp+47h] [ebp-1h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_PendingSockets.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_PendingSockets.CThreadFastMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_PendingSockets.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_PendingSockets.m_depth;
  }
  v1 = 0;
  i = 0;
  if ( s_PendingSockets.m_Size <= 0 )
    goto LABEL_82;
  v2 = 0;
  v35 = 0;
  do
  {
    v3 = (pendingsocket_t *)((char *)s_PendingSockets.m_Memory.m_pMemory + v2);
    v4 = net_time - *(float *)((char *)&s_PendingSockets.m_Memory.m_pMemory->time + v2);
    newsock = *(int *)((char *)&s_PendingSockets.m_Memory.m_pMemory->newsock + v2);
    psock = (pendingsocket_t *)((char *)s_PendingSockets.m_Memory.m_pMemory + v2);
    if ( v4 > 4.0 )
      goto LABEL_8;
    v7 = recv(s: newsock, buf: headerBuf, len: 5, flags: 0);
    if ( v7 == -1 )
    {
      Error = WSAGetLastError();
      net_error = Error;
      if ( Error == 10035 || Error == 10057 )
        goto LABEL_81;
      v9 = NET_ErrorString(code: Error);
      _Msg(a1: "NET_ReceiveStream: %s\n", v9);
      newsock = v3->newsock;
LABEL_8:
      if ( newsock != 0 )
      {
        if ( closesocket(s: newsock) == -1 )
        {
          net_error = WSAGetLastError();
          v6 = NET_ErrorString(code: net_error);
          ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v6);
        }
        g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
      }
      if ( s_PendingSockets.m_Size - v1 - 1 > 0 )
        _V_memmove(
          dest: (char *)s_PendingSockets.m_Memory.m_pMemory + v2,
          src: (char *)&s_PendingSockets.m_Memory.m_pMemory[1] + v2,
          count: 24 * (s_PendingSockets.m_Size - v1 - 1));
      goto LABEL_80;
    }
    if ( v7 == 0 )
      goto LABEL_81;
    header.m_bOverflow = false;
    header.m_pDebugName = nullptr;
    header.m_nDataBytes = 0;
    header.m_nDataBits = -1;
    CBitRead::StartReading(this: &header, pData: (const unsigned int *)headerBuf, nBytes: 5u, iStartBit: 0, nBits: -1);
    m_nBitsAvail = header.m_nBitsAvail;
    m_pDataIn = header.m_pDataIn;
    m_pBufferEnd = header.m_pBufferEnd;
    if ( header.m_nBitsAvail >= 8 )
    {
      m_nBitsAvail = header.m_nBitsAvail - 8;
      header.m_nBitsAvail = m_nBitsAvail;
      if ( m_nBitsAvail != 0 )
      {
        v13 = header.m_nInBufWord >> 8;
        m_nInBufWord_low = LOBYTE(header.m_nInBufWord);
      }
      else
      {
        m_nBitsAvail = 32;
        header.m_nBitsAvail = 32;
        if ( header.m_pDataIn == header.m_pBufferEnd )
        {
          v13 = 0;
          m_nBitsAvail = 1;
          m_pDataIn = header.m_pDataIn + 1;
          header.m_nBitsAvail = 1;
          ++header.m_pDataIn;
          m_nInBufWord_low = LOBYTE(header.m_nInBufWord);
        }
        else
        {
          if ( header.m_pDataIn <= header.m_pBufferEnd )
          {
            v13 = *header.m_pDataIn;
            m_pDataIn = ++header.m_pDataIn;
          }
          else
          {
            header.m_bOverflow = true;
            v13 = 0;
          }
          m_nInBufWord_low = LOBYTE(header.m_nInBufWord);
        }
      }
      goto LABEL_35;
    }
    m_nInBufWord = header.m_nInBufWord;
    v15 = 8 - header.m_nBitsAvail;
    if ( header.m_pDataIn == header.m_pBufferEnd )
    {
      m_pBufferEnd = header.m_pBufferEnd;
      v3 = psock;
      v13 = 0;
      m_nBitsAvail = 1;
      m_pDataIn = header.m_pDataIn + 1;
      header.m_nBitsAvail = 1;
      header.m_nInBufWord = 0;
      ++header.m_pDataIn;
      header.m_bOverflow = true;
      m_nInBufWord_low = 0;
    }
    else if ( header.m_pDataIn <= header.m_pBufferEnd )
    {
      v13 = *header.m_pDataIn;
      m_pDataIn = header.m_pDataIn + 1;
      header.m_nInBufWord = *header.m_pDataIn++;
      if ( !header.m_bOverflow )
      {
        v37 = v13 & CBitBuffer::s_nMaskTable[v15];
        m_nBitsAvail = 32 - v15;
        v13 >>= v15;
        m_pBufferEnd = header.m_pBufferEnd;
        m_nInBufWord_low = (v37 << SLOBYTE(header.m_nBitsAvail)) | m_nInBufWord;
        v3 = psock;
        header.m_nBitsAvail = 32 - v15;
LABEL_35:
        header.m_nInBufWord = v13;
        goto LABEL_36;
      }
      m_pBufferEnd = header.m_pBufferEnd;
      v3 = psock;
      m_nInBufWord_low = 0;
    }
    else
    {
      m_pBufferEnd = header.m_pBufferEnd;
      v3 = psock;
      v13 = 0;
      header.m_bOverflow = true;
      header.m_nInBufWord = 0;
      m_nInBufWord_low = 0;
    }
LABEL_36:
    if ( m_nBitsAvail < 32 )
    {
      v16 = 32 - m_nBitsAvail;
      v17 = v13;
      if ( m_pDataIn == m_pBufferEnd )
      {
        header.m_nBitsAvail = 1;
        header.m_nInBufWord = 0;
        header.m_pDataIn = m_pDataIn + 1;
        header.m_bOverflow = true;
        v37 = 0;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v18 = *m_pDataIn;
        header.m_nInBufWord = *m_pDataIn;
        header.m_pDataIn = m_pDataIn + 1;
        if ( header.m_bOverflow )
        {
          v37 = 0;
        }
        else
        {
          v19 = (v18 & CBitBuffer::s_nMaskTable[v16]) << m_nBitsAvail;
          header.m_nBitsAvail = m_nBitsAvail;
          v37 = v19 | v17;
          header.m_nInBufWord = v18 >> v16;
        }
      }
      else
      {
        header.m_bOverflow = true;
        header.m_nInBufWord = 0;
        v37 = 0;
      }
      v3 = psock;
    }
    else
    {
      header.m_nBitsAvail = m_nBitsAvail - 32;
      if ( m_nBitsAvail == 32 )
      {
        header.m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          header.m_nBitsAvail = 1;
          header.m_nInBufWord = 0;
          header.m_pDataIn = m_pDataIn + 1;
          v37 = v13;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            header.m_nInBufWord = *m_pDataIn;
            header.m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            header.m_bOverflow = true;
            header.m_nInBufWord = 0;
          }
          v37 = v13;
        }
      }
      else
      {
        header.m_nInBufWord = 0;
        v37 = v13;
      }
    }
    bOK = false;
    if ( m_nInBufWord_low != 4 )
      goto LABEL_73;
    v20 = GetCurrentThreadId();
    if ( v20 != s_NetChannels.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, v20, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: v20, a3: 0);
    }
    else
    {
      ++s_NetChannels.m_depth;
    }
    v21 = 0;
    if ( s_NetChannels.m_Size <= 0 )
      goto LABEL_69;
    while ( 1 )
    {
      v22 = s_NetChannels.m_Memory.m_pMemory[v21];
      v23 = v22->GetSocket(this: v22);
      v24 = psock;
      if ( v23 == psock->netsock )
      {
        v25 = v22->GetChallengeNr(this: v22);
        if ( v37 != v25 || v22->m_StreamSocket != 0 )
          goto LABEL_64;
        if ( netadr_s::CompareAdr(this: &v24->addr, a: &v22->remote_address, onlyBase: true) )
          break;
        v26 = netadr_s::ToString(this: &v24->addr, baseOnly: false);
        _Msg(a1: "TCP <- %s: IP address mismatch.\n", v26);
      }
LABEL_64:
      if ( ++v21 >= s_NetChannels.m_Size )
        goto LABEL_69;
    }
    v27 = psock;
    v28 = v22->__vftable;
    v22->m_StreamSocket = psock->newsock;
    ResetStreaming = v28->ResetStreaming;
    v22->m_StreamActive = true;
    ResetStreaming(this: v22);
    bOK = true;
    if ( net_showtcp.m_pParent != nullptr && net_showtcp.m_pParent->m_Value.m_nValue != 0 )
    {
      v30 = netadr_s::ToString(this: &v27->addr, baseOnly: false);
      _Msg(a1: "TCP <- %s: connection accepted\n", v30);
    }
LABEL_69:
    if ( --s_NetChannels.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
    if ( !bOK )
    {
      v3 = psock;
LABEL_73:
      v31 = netadr_s::ToString(this: &v3->addr, baseOnly: false);
      _Msg(a1: "TCP <- %s: invalid connection request.\n", v31);
      if ( v3->newsock != 0 )
      {
        if ( closesocket(s: v3->newsock) == -1 )
        {
          net_error = WSAGetLastError();
          v32 = NET_ErrorString(code: net_error);
          ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v32);
        }
        g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
      }
    }
    if ( s_PendingSockets.m_Size - i - 1 > 0 )
      _V_memmove(
        dest: (char *)s_PendingSockets.m_Memory.m_pMemory + v35,
        src: (char *)&s_PendingSockets.m_Memory.m_pMemory[1] + v35,
        count: 24 * (s_PendingSockets.m_Size - i - 1));
    v1 = i;
    v2 = v35;
LABEL_80:
    --s_PendingSockets.m_Size;
LABEL_81:
    ++v1;
    v2 += 24;
    i = v1;
    v35 = v2;
  }
  while ( v1 < s_PendingSockets.m_Size );
LABEL_82:
  if ( --s_PendingSockets.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_PendingSockets.CThreadFastMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B64F0
// Name: void NET_CloseAllSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_CloseAllSockets()
{
  int v0; // edi
  netsocket_t *m_pMemory; // eax
  int v2; // esi
  const char *v3; // eax
  const char *v4; // eax
  DWORD CurrentThreadId; // ecx
  int v6; // edi
  int v7; // esi
  const char *v8; // eax

  v0 = 0;
  if ( net_sockets.m_Size > 0 )
  {
    m_pMemory = net_sockets.m_Memory.m_pMemory;
    v2 = 0;
    do
    {
      if ( m_pMemory[v2].nPort != 0 )
      {
        if ( m_pMemory[v2].hUDP != 0 )
        {
          if ( closesocket(s: m_pMemory[v2].hUDP) == -1 )
          {
            net_error = WSAGetLastError();
            v3 = NET_ErrorString(code: net_error);
            ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v3);
          }
          g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
          m_pMemory = net_sockets.m_Memory.m_pMemory;
        }
        if ( m_pMemory[v2].hTCP != 0 )
        {
          if ( closesocket(s: m_pMemory[v2].hTCP) == -1 )
          {
            net_error = WSAGetLastError();
            v4 = NET_ErrorString(code: net_error);
            ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v4);
          }
          g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
          m_pMemory = net_sockets.m_Memory.m_pMemory;
        }
        m_pMemory[v2].nPort = 0;
        net_sockets.m_Memory.m_pMemory[v2].bListening = false;
        net_sockets.m_Memory.m_pMemory[v2].hUDP = 0;
        net_sockets.m_Memory.m_pMemory[v2].hTCP = 0;
        m_pMemory = net_sockets.m_Memory.m_pMemory;
      }
      ++v0;
      ++v2;
    }
    while ( v0 < net_sockets.m_Size );
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_PendingSockets.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_PendingSockets.CThreadFastMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_PendingSockets.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_PendingSockets.m_depth;
  }
  v6 = 0;
  if ( s_PendingSockets.m_Size > 0 )
  {
    v7 = 0;
    do
    {
      if ( s_PendingSockets.m_Memory.m_pMemory[v7].newsock != 0 )
      {
        if ( closesocket(s: s_PendingSockets.m_Memory.m_pMemory[v7].newsock) == -1 )
        {
          net_error = WSAGetLastError();
          v8 = NET_ErrorString(code: net_error);
          ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v8);
        }
        g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < s_PendingSockets.m_Size );
  }
  s_PendingSockets.m_Size = 0;
  g_pSteamSocketMgr->Shutdown(this: g_pSteamSocketMgr);
  g_pSteamSocketMgr->Init(this: g_pSteamSocketMgr);
  if ( --s_PendingSockets.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_PendingSockets.CThreadFastMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B66C0
// Name: void NET_RemoveAllExtraSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_RemoveAllExtraSockets()
{
  netsocket_t *m_pMemory; // edx
  int v1; // edi
  int v2; // esi
  const char *v3; // eax
  const char *v4; // eax

  m_pMemory = net_sockets.m_Memory.m_pMemory;
  v1 = 3;
  if ( net_sockets.m_Size > 3 )
  {
    v2 = 3;
    do
    {
      if ( m_pMemory[v2].nPort != 0 )
      {
        if ( m_pMemory[v2].hUDP != 0 )
        {
          if ( closesocket(s: m_pMemory[v2].hUDP) == -1 )
          {
            net_error = WSAGetLastError();
            v3 = NET_ErrorString(code: net_error);
            ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v3);
          }
          g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
          m_pMemory = net_sockets.m_Memory.m_pMemory;
        }
        if ( m_pMemory[v2].hTCP != 0 )
        {
          if ( closesocket(s: m_pMemory[v2].hTCP) == -1 )
          {
            net_error = WSAGetLastError();
            v4 = NET_ErrorString(code: net_error);
            ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v4);
          }
          g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
          m_pMemory = net_sockets.m_Memory.m_pMemory;
        }
      }
      ++v1;
      ++v2;
    }
    while ( v1 < net_sockets.m_Size );
  }
  net_sockets.m_Size = 3;
}

//------------------------------------------------------------------------------
// Address: 0x101B67E0
// Name: public: void CTSQueue<struct loopback_t __near *,0,1>::PushItem(struct loopback_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<loopback_t *,0,1>::PushItem(CTSQueue<loopback_t *,0,1> *this, loopback_t **init)
{
  CTSQueue<loopback_t *,0,1>::Node_t *v3; // eax

  v3 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_FreeNodes);
  if ( v3 != nullptr || (v3 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
  {
    v3->elem = *init;
    CTSQueue<CFunctor *,0,1>::Push((CTSQueue<StartSoundParams_t,0,1> *)this, pNode: v3);
  }
  else
  {
    CTSQueue<CFunctor *,0,1>::Push((CTSQueue<StartSoundParams_t,0,1> *)this, pNode: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6990
// Name: void NET_SendLoopPacket(int,int,unsigned char const __near *,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_SendLoopPacket(loopback_t *sock, int length, const unsigned __int8 *data)
{
  loopback_t *v3; // ebx
  int v4; // edi
  loopback_t *v5; // eax
  loopback_t *v6; // esi
  char *defbuffer; // eax
  CTSQueue<loopback_t *,0,1>::Node_t *v8; // eax
  const unsigned __int8 *v9; // [esp-10h] [ebp-14h]

  v3 = sock;
  if ( (unsigned int)sock <= 1 )
  {
    v4 = length;
    if ( length <= 96000 )
    {
      v5 = (loopback_t *)CUtlMemoryPool::Alloc(this: &loopback_t::s_Allocator, amount: 0x808u);
      v6 = v5;
      sock = v5;
      if ( v4 > 2048 )
        defbuffer = (char *)MemAlloc_Alloc(nSize: v4);
      else
        defbuffer = v5->defbuffer;
      v9 = data;
      v6->data = defbuffer;
      _V_memcpy(dest: defbuffer, src: v9, count: v4);
      v6->datalen = v4;
      if ( v3 == (loopback_t *)1 )
      {
        v8 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &s_LoopBacks.m_FreeNodes);
        if ( v8 != nullptr || (v8 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
        {
          v8->elem = v6;
          CTSQueue<CFunctor *,0,1>::Push(this: &s_LoopBacks, pNode: v8);
        }
        else
        {
          CTSQueue<CFunctor *,0,1>::Push(this: &s_LoopBacks, pNode: nullptr);
        }
      }
      else if ( v3 != nullptr )
      {
        DevMsg(a1: "NET_SendLoopPacket:  invalid socket (%i).\n", v3);
      }
      else
      {
        CTSQueue<loopback_t *,0,1>::PushItem(this: &stru_1068BBC8, init: &sock);
      }
    }
    else
    {
      DevMsg(a1: "NET_SendLoopPacket:  packet too big (%i).\n", length);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6A80
// Name: bool NET_GetLoopPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_GetLoopPacket(netpacket_s *packet)
{
  int source; // eax
  CTSQueue<int,0,1> *v3; // ebx
  CTSQueue<int,0,1>::Node_t *v4; // eax
  int elem; // esi
  int v6; // eax
  void *v7; // eax
  unsigned int v8; // ebx

  source = packet->source;
  if ( source > 1 )
    return 0;
  v3 = (CTSQueue<int,0,1> *)(&s_LoopBacks + source);
  v4 = CTSQueue<loopback_t *,0,1>::Pop(this: v3);
  if ( v4 == nullptr )
    return 0;
  elem = v4->elem;
  CTSListBase::Push(this: &v3->m_FreeNodes, pNode: (TSLNodeBase_t *)v4);
  if ( *(_DWORD *)(elem + 4) != 0 )
  {
    netadr_s::SetType(this: &packet->from, newtype: NA_LOOPBACK);
    v6 = *(_DWORD *)(elem + 4);
    packet->size = v6;
    packet->wiresize = *(_DWORD *)(elem + 4);
    _V_memcpy(dest: packet->data, src: *(const void **)elem, count: v6);
    v7 = *(void **)elem;
    v8 = elem + 8;
    *(_DWORD *)(elem + 4) = 0;
    if ( v7 != (void *)(elem + 8) )
    {
      free(pMem: v7);
      *(_DWORD *)elem = v8;
    }
    CUtlMemoryPool::Free(this: &loopback_t::s_Allocator, memBlock: (_DWORD *)elem);
    return NET_LagPacket(a1: v8, newdata: true, packet);
  }
  else
  {
    CUtlMemoryPool::Free(this: &loopback_t::s_Allocator, memBlock: (_DWORD *)elem);
    return NET_LagPacket(a1: (unsigned int)v3, newdata: false, packet);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6B40
// Name: void NET_ClearLoopbackBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ClearLoopbackBuffers()
{
  CTSQueue<int,0,1> *v0; // esi
  CTSQueue<int,0,1>::Node_t *v1; // eax
  CTSQueue<int,0,1>::Node_t *v2; // edi
  int DepthAndSequence; // ecx
  CTSListBase *p_m_FreeNodes; // esi
  CTSQueue<int,0,1>::Node_t *Next; // [esp-8h] [ebp-1Ch]
  CTSQueue<int,0,1>::Node_t *v6; // [esp-8h] [ebp-1Ch]
  int v7; // [esp-4h] [ebp-18h]
  loopback_t *loop; // [esp+Ch] [ebp-8h]
  CTSQueue<StartSoundParams_t,0,1> *v9; // [esp+10h] [ebp-4h]

  v0 = (CTSQueue<int,0,1> *)&s_LoopBacks;
  v9 = &s_LoopBacks;
  do
  {
    while ( 1 )
    {
      v1 = CTSQueue<loopback_t *,0,1>::Pop(this: v0);
      v2 = v1;
      if ( v1 == nullptr )
        break;
      DepthAndSequence = v0->m_FreeNodes.m_Head.value32.DepthAndSequence;
      p_m_FreeNodes = &v0->m_FreeNodes;
      loop = (loopback_t *)v1->elem;
      Next = (CTSQueue<int,0,1>::Node_t *)p_m_FreeNodes->m_Head.value.Next;
      v1->pNext = (CTSQueue<int,0,1>::Node_t *)p_m_FreeNodes->m_Head.value.Next;
      if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                              a1: p_m_FreeNodes,
                              a2: v1,
                              a3: DepthAndSequence + 65537,
                              a4: Next,
                              a5: DepthAndSequence) == 0 )
      {
        do
        {
          _mm_pause();
          v7 = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
          v6 = (CTSQueue<int,0,1>::Node_t *)p_m_FreeNodes->m_Head.value.Next;
          v2->pNext = (CTSQueue<int,0,1>::Node_t *)p_m_FreeNodes->m_Head.value.Next;
        }
        while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: p_m_FreeNodes, a2: v2, a3: v7 + 65537, a4: v6, a5: v7) == 0 );
      }
      if ( loop->data != nullptr && loop->data != loop->defbuffer )
        free(pMem: loop->data);
      CUtlMemoryPool::Free(this: &loopback_t::s_Allocator, memBlock: loop);
      v0 = (CTSQueue<int,0,1> *)v9;
    }
    v9 = (CTSQueue<StartSoundParams_t,0,1> *)++v0;
  }
  while ( (int)v0 < (int)&UNSPECIFIED_LOGGING_COLOR_115 );
}

//------------------------------------------------------------------------------
// Address: 0x101B6BF0
// Name: void NET_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_Shutdown()
{
  netpacket_s **v0; // ebx
  netpacket_s *v1; // esi
  netpacket_s *pNext; // edi
  int v3; // eax

  v0 = s_pLagData;
  do
  {
    v1 = *v0;
    if ( *v0 != nullptr )
    {
      do
      {
        pNext = v1->pNext;
        if ( v1->data != nullptr )
        {
          free(pMem: v1->data);
          v1->data = nullptr;
        }
        free(pMem: v1);
        v1 = pNext;
      }
      while ( pNext != nullptr );
    }
    *v0++ = nullptr;
  }
  while ( (int)v0 < (int)&net_multiplayer );
  g_pQueuedPackedSender->Shutdown(this: g_pQueuedPackedSender);
  net_multiplayer = false;
  net_dedicated = false;
  NET_CloseAllSockets();
  NET_ClearLoopbackBuffers();
  if ( !net_noip )
  {
    v3 = WSACleanup();
    if ( v3 != 0 )
      _Msg(a1: "Failed to complete WSACleanup = 0x%x.\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6D20
// Name: class INetChannel __near * NET_CreateNetChannel(int,struct netadr_s __near *,char const __near *,class INetChannelHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CNetChan *__cdecl NET_CreateNetChannel(
        int socket,
        netadr_s *adr,
        const char *name,
        INetChannelHandler *handler,
        bool bForceNewChannel)
{
  CNetChan *NetChannel; // edi
  CNetChan *v6; // eax
  DWORD CurrentThreadId; // ecx
  int m_Size; // eax
  int v9; // esi
  CNetChan **m_pMemory; // ecx
  int v11; // eax
  CNetChan **v12; // eax

  if ( !bForceNewChannel && adr != nullptr && (NetChannel = NET_FindNetChannel(socket, adr)) != nullptr )
  {
    NetChannel->Clear(this: NetChannel);
  }
  else
  {
    v6 = (CNetChan *)MemAlloc_Alloc(nSize: 0x4268u);
    if ( v6 != nullptr )
      NetChannel = CNetChan::CNetChan(this: v6);
    else
      NetChannel = nullptr;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_NetChannels.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_NetChannels.m_depth;
    }
    m_Size = s_NetChannels.m_Size;
    v9 = s_NetChannels.m_Size;
    if ( s_NetChannels.m_Size + 1 > s_NetChannels.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&s_NetChannels,
        num: s_NetChannels.m_Size - s_NetChannels.m_Memory.m_nAllocationCount + 1);
      m_Size = s_NetChannels.m_Size;
    }
    m_pMemory = s_NetChannels.m_Memory.m_pMemory;
    s_NetChannels.m_Size = m_Size + 1;
    v11 = m_Size - v9;
    s_NetChannels.m_pElements = s_NetChannels.m_Memory.m_pMemory;
    if ( v11 > 0 )
    {
      _V_memmove(
        dest: &s_NetChannels.m_Memory.m_pMemory[v9 + 1],
        src: &s_NetChannels.m_Memory.m_pMemory[v9],
        count: 4 * v11);
      m_pMemory = s_NetChannels.m_Memory.m_pMemory;
    }
    v12 = &m_pMemory[v9];
    if ( v12 != nullptr )
      *v12 = NetChannel;
    if ( --s_NetChannels.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
  }
  if ( socket < 3 && s_pLagData[socket] != nullptr )
    NET_ClearLaggedList(pList: &s_pLagData[socket]);
  CNetChan::Setup(this: NetChannel, sock: socket, adr, name, handler);
  return NetChannel;
}

//------------------------------------------------------------------------------
// Address: 0x101B6E70
// Name: void NET_ProcessListen(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ProcessListen(int sock)
{
  int v1; // edi
  netsocket_t *v2; // eax
  SOCKET v3; // esi
  int Error; // eax
  const char *v5; // eax
  DWORD CurrentThreadId; // eax
  char *v7; // eax
  pendingsocket_t psock; // [esp+4h] [ebp-30h] BYREF
  sockaddr sa; // [esp+1Ch] [ebp-18h] BYREF
  int nLengthAddr; // [esp+30h] [ebp-4h] BYREF

  v1 = sock;
  v2 = &net_sockets.m_Memory.m_pMemory[sock];
  if ( v2->bListening )
  {
    nLengthAddr = 16;
    v3 = accept(s: v2->hTCP, addr: &sa, addrlen: &nLengthAddr);
    if ( v3 == -1 )
    {
      Error = WSAGetLastError();
      net_error = Error;
      if ( Error != 10035 )
      {
        v5 = NET_ErrorString(code: Error);
        _ConDMsg(a1: "NET_ThreadListen: %s\n", v5);
      }
    }
    else
    {
      netadr_s::SetIP(this: &psock.addr, unIP: 0);
      netadr_s::SetPort(this: &psock.addr, newport: 0);
      netadr_s::SetType(this: &psock.addr, newtype: NA_IP);
      psock.newsock = v3;
      psock.netsock = v1;
      netadr_s::SetFromSockadr(this: &psock.addr, s: &sa);
      psock.time = net_time;
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != s_PendingSockets.m_ownerID
        && _InterlockedCompareExchange(
             (volatile signed __int32 *)&s_PendingSockets.CThreadFastMutex,
             CurrentThreadId,
             0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &s_PendingSockets.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++s_PendingSockets.m_depth;
      }
      CUtlVector<CEngineVoiceSteam::RemoteTalker_t,CUtlMemory<CEngineVoiceSteam::RemoteTalker_t,int>>::InsertBefore(
        this: (CUtlVector<CEngineVoiceSteam::RemoteTalker_t,CUtlMemory<CEngineVoiceSteam::RemoteTalker_t,int> > *)&s_PendingSockets,
        elem: s_PendingSockets.m_Size,
        src: (const CEngineVoiceSteam::RemoteTalker_t *)&psock);
      HIBYTE(sock) = 1;
      NET_SendStream(nSock: v3, buf: (const char *)&sock + 3, len: 1, flags: 0);
      if ( net_showtcp.m_pParent != nullptr && net_showtcp.m_pParent->m_Value.m_nValue != 0 )
      {
        v7 = netadr_s::ToString(this: &psock.addr, baseOnly: false);
        _Msg(a1: "TCP <- %s: connection request.\n", v7);
      }
      if ( --s_PendingSockets.m_depth == 0 )
        _InterlockedExchange((volatile __int32 *)&s_PendingSockets.CThreadFastMutex, 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6FD0
// Name: private: void CBindAddressHelper::BuildBindAddresses(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBindAddressHelper::BuildBindAddresses(
        CBindAddressHelper *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  _IP_ADAPTER_INFO *v2; // eax
  _IP_ADAPTER_INFO *v3; // edi
  const CUtlString *v4; // eax
  _IP_ADAPTER_INFO info_temp; // [esp+0h] [ebp-2A0h] BYREF
  CUtlString v6; // [esp+288h] [ebp-18h] BYREF
  _IP_ADAPTER_INFO *infos; // [esp+298h] [ebp-8h]
  unsigned int len; // [esp+29Ch] [ebp-4h] BYREF

  len = 0;
  if ( GetAdaptersInfo(AdapterInfo: &info_temp, SizePointer: &len) == 111 )
  {
    v2 = (_IP_ADAPTER_INFO *)MemAlloc_Alloc(nSize: (648 * (unsigned __int64)len) >> 32 != 0 ? -1 : 648 * len);
    v3 = v2;
    infos = v2;
    if ( v2 != nullptr )
    {
      if ( GetAdaptersInfo(AdapterInfo: v2, SizePointer: &len) == 0 )
      {
        do
        {
          if ( v3->Type != 24 && _V_strcmp(s1: v3->IpAddressList.IpAddress.String, s2: "0.0.0.0") != 0 )
          {
            _Msg(a1: "NET_GetBindAddresses found %s: '%s'\n", v3->IpAddressList.IpAddress.String, v3->Description);
            v4 = CUtlString::CUtlString(this: &v6, pString: v3->IpAddressList.IpAddress.String);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: list, elem: list->m_Size, src: v4);
            v6.m_Storage.m_nActualLength = 0;
            if ( v6.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v6.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6.m_Storage.m_Memory.m_pMemory);
                v6.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v6.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
          v3 = v3->Next;
        }
        while ( v3 != nullptr );
        v3 = infos;
      }
      free(pMem: v3);
    }
    else
    {
      Sys_Error(error: "BuildBindAddresses:  Out of memory allocating %d bytes\n", 648 * len);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B70F0
// Name: void NET_RunFrame(double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_RunFrame(long double realtime)
{
  CRConServer *v2; // eax
  CRPTServer *v3; // eax
  CRConClient *v4; // eax
  CRPTClient *v5; // eax
  int v6; // esi
  netsocket_t *m_pMemory; // eax
  int v8; // edi
  double realtimea; // [esp+8h] [ebp+8h]

  realtimea = realtime - s_last_realtime;
  s_last_realtime = realtime;
  if ( realtimea <= 1.0 )
  {
    if ( realtimea < 0.0 )
      realtimea = 0.0;
  }
  else
  {
    realtimea = 1.0;
  }
  net_time = ((double (__thiscall *)(IEngineToolInternal *))g_pEngineToolInternal->GetTimescale)(a1: g_pEngineToolInternal)
           * realtimea
           + net_time;
  v2 = RCONServer();
  CRConServer::RunFrame(this: v2);
  v3 = RPTServer();
  CRConServer::RunFrame(this: v3);
  Con_RunFrame();
  v4 = RCONClient();
  CRConClient::RunFrame(this: v4);
  v5 = RPTClient();
  CRConClient::RunFrame(this: v5);
  if ( g_pMatchFramework != nullptr )
    g_pMatchFramework->RunFrame(this: g_pMatchFramework);
  if ( net_multiplayer && !net_notcp )
  {
    v6 = 0;
    if ( net_sockets.m_Size > 0 )
    {
      m_pMemory = net_sockets.m_Memory.m_pMemory;
      v8 = 0;
      do
      {
        if ( m_pMemory[v8].hTCP != 0 && m_pMemory[v8].bListening )
        {
          NET_ProcessListen(sock: v6);
          m_pMemory = net_sockets.m_Memory.m_pMemory;
        }
        ++v6;
        ++v8;
      }
      while ( v6 < net_sockets.m_Size );
    }
    NET_ProcessPending();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B71F0
// Name: class CSplitPacketEntry __near * NET_FindOrCreateSplitPacketEntry(int,struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitPacketEntry *__cdecl NET_FindOrCreateSplitPacketEntry(const int sock, netadr_s *from)
{
  CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int> > *v2; // esi
  int v3; // ebx
  const netadr_s *p_from; // edi
  int v5; // edx
  int v6; // eax
  int v7; // edi
  int m_nAllocationCount; // eax
  CSplitPacketEntry *m_pMemory; // ecx
  int v10; // eax
  unsigned __int8 *v11; // edi
  _DWORD v13[24182]; // [esp+Ch] [ebp-179DCh] BYREF
  int m_Size; // [esp+179E4h] [ebp-4h]
  int v15; // [esp+179F0h] [ebp+8h]

  v2 = &net_splitpackets.m_Memory.m_pMemory[sock];
  v3 = 0;
  m_Size = v2->m_Size;
  if ( m_Size > 0 )
  {
    v15 = 0;
    while ( 1 )
    {
      p_from = &v2->m_Memory.m_pMemory[v15].from;
      if ( netadr_s::CompareAdr(this: from, a: p_from, onlyBase: false) )
        break;
      ++v15;
      if ( ++v3 >= m_Size )
        goto LABEL_7;
    }
    if ( v3 < m_Size )
      return (CSplitPacketEntry *)p_from;
  }
LABEL_7:
  netadr_s::SetIP(this: (netadr_s *)v13, unIP: 0);
  netadr_s::SetPort(this: (netadr_s *)v13, newport: 0);
  netadr_s::SetType(this: (netadr_s *)v13, newtype: NA_IP);
  memset(v13, 0, 12);
  memset(&v13[3], 0xFFu, 0x2A8u);
  memset(&v13[173], 0, 96036);
  v5 = *(_DWORD *)from->ip;
  v6 = *(_DWORD *)&from->port;
  v7 = v2->m_Size;
  v13[0] = from->type;
  v13[2] = v6;
  m_nAllocationCount = v2->m_Memory.m_nAllocationCount;
  v13[1] = v5;
  if ( v7 + 1 > m_nAllocationCount )
    CUtlMemory<CSplitPacketEntry,int>::Grow(this: &v2->m_Memory, num: v7 - m_nAllocationCount + 1);
  ++v2->m_Size;
  m_pMemory = v2->m_Memory.m_pMemory;
  v10 = v2->m_Size - v7 - 1;
  v2->m_pElements = v2->m_Memory.m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 96728 * v10);
  v11 = (unsigned __int8 *)&v2->m_Memory.m_pMemory[v7];
  if ( v11 != nullptr )
    memcpy(dst: v11, src: (unsigned __int8 *)v13, count: 0x179D8u);
  return &v2->m_Memory.m_pMemory[v2->m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x101B7360
// Name: bool NET_GetLong(int,struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_GetLong(void *sock, netpacket_s *packet)
{
  CSplitPacketEntry *SplitPacketEntry; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 *data; // ecx
  unsigned int v7; // edx
  int v8; // eax
  unsigned int v9; // edi
  int v10; // ecx
  char *v11; // eax
  unsigned int v12; // edx
  int m_nValue; // ecx
  const char *v14; // eax
  char *v15; // eax
  unsigned int v16; // eax
  char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  int v20; // [esp-18h] [ebp-28h]
  unsigned int v21; // [esp-14h] [ebp-24h]
  int v22; // [esp-14h] [ebp-24h]
  int v23; // [esp-10h] [ebp-20h]
  int v24; // [esp-10h] [ebp-20h]
  int v25; // [esp-Ch] [ebp-1Ch]
  char *v26; // [esp-Ch] [ebp-1Ch]
  int nSplitSizeMinusHeader; // [esp+4h] [ebp-Ch]
  unsigned int size; // [esp+8h] [ebp-8h]
  int packetCount; // [esp+Ch] [ebp-4h]
  int sequenceNumber; // [esp+1Ch] [ebp+Ch]

  if ( packet->size < 0xCu )
  {
    _Msg(a1: "Invalid split packet length %i\n", packet->size);
    return 0;
  }
  SplitPacketEntry = NET_FindOrCreateSplitPacketEntry((const int)sock, from: &packet->from);
  v5 = (unsigned __int8 *)SplitPacketEntry;
  if ( SplitPacketEntry == nullptr )
    return 0;
  SplitPacketEntry->lastactivetime = net_time;
  data = packet->data;
  sequenceNumber = *((_DWORD *)data + 1);
  v7 = (unsigned __int8)*((_WORD *)data + 4);
  v8 = *((__int16 *)data + 5);
  v9 = *((__int16 *)data + 4) >> 8;
  packetCount = v7;
  nSplitSizeMinusHeader = v8;
  if ( (unsigned int)(v8 - 564) > 0x270 )
  {
    v22 = *((__int16 *)data + 5);
    v20 = (unsigned __int8)*((_WORD *)data + 4);
    v19 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Split packet from %s with invalid split size (number %i/ count %i) where size %i is out of valid range [%d - %d ]\n",
      v19,
      v9,
      v20,
      v22,
      564,
      1188);
    return 0;
  }
  if ( v9 >= 0xAA || v7 > 0xAA )
  {
    v24 = (unsigned __int8)*((_WORD *)data + 4);
    v18 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Split packet from %s with too many split parts (number %i/ count %i) where %i is max count allowed\n",
      v18,
      v9,
      v24,
      170);
    return 0;
  }
  v10 = *((_DWORD *)v5 + 173);
  if ( v10 == -1 || sequenceNumber != v10 )
  {
    *((_DWORD *)v5 + 173) = sequenceNumber;
    *((_DWORD *)v5 + 174) = v7;
    *((_DWORD *)v5 + 176) = v8;
  }
  if ( *((_DWORD *)v5 + 176) != v8 )
  {
    v25 = *((_DWORD *)v5 + 176);
    v23 = v8;
    v21 = v7;
    v11 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Split packet from %s with inconsistent split size (number %i/ count %i) where size %i not equal to i"
      "nitial size of %i\n",
      v11,
      v9,
      v21,
      v23,
      v25);
    return 0;
  }
  size = packet->size - 12;
  if ( *(_DWORD *)&v5[4 * v9 + 12] == sequenceNumber )
  {
    v15 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Ignoring duplicated split packet %i of %i ( %i bytes ) from %s\n",
      v9 + 1,
      packetCount,
      size,
      v15);
    goto LABEL_21;
  }
  v12 = v7 - 1;
  if ( v9 == v12 )
    *((_DWORD *)v5 + 175) = size + v8 * v12;
  --*((_DWORD *)v5 + 174);
  *(_DWORD *)&v5[4 * v9 + 12] = sequenceNumber;
  if ( net_showsplits.m_pParent != nullptr )
  {
    m_nValue = net_showsplits.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 && m_nValue != 3 )
    {
      v26 = netadr_s::ToString(this: &packet->from, baseOnly: false);
      v14 = DescribeSocket(sock);
      _Msg(
        a1: "<-- [%s] Split packet %4i/%4i seq %5i size %4i mtu %4i from %s\n",
        v14,
        v9 + 1,
        packetCount,
        sequenceNumber,
        size,
        nSplitSizeMinusHeader + 12,
        v26);
LABEL_21:
      v8 = nSplitSizeMinusHeader;
    }
  }
  memcpy(dst: &v5[v9 * v8 + 708], src: packet->data + 12, count: size);
  if ( *((int *)v5 + 174) > 0 )
    return 0;
  v16 = *((_DWORD *)v5 + 175);
  *((_DWORD *)v5 + 173) = -1;
  if ( v16 <= 0x17710 )
  {
    _V_memcpy(dest: packet->data, src: v5 + 708, count: v16);
    packet->size = *((_DWORD *)v5 + 175);
    packet->wiresize = *((_DWORD *)v5 + 175);
    return 1;
  }
  else
  {
    v17 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(a1: "Split packet too large! %d bytes from %s\n", *((_DWORD *)v5 + 175), v17);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B75F0
// Name: bool NET_ReceiveDatagram(int,struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_ReceiveDatagram(void *sock, netpacket_s *packet)
{
  int source; // eax
  unsigned __int8 *data; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // esi
  unsigned __int8 *v8; // edx
  int v9; // eax
  int v10; // ebx
  signed int v11; // esi
  char *v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // esi
  unsigned int ActualSize; // eax
  int v16; // eax
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // ebx
  unsigned int v20; // esi
  int v21; // eax
  int v22; // ebx
  int v23; // esi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v26; // edx
  int v27; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int v30; // eax
  const unsigned int *v31; // ecx
  const unsigned int *v32; // edx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned __int16 v35; // ax
  char v36; // bl
  char *v37; // eax
  int Error; // eax
  const char *v39; // eax
  const void *v40; // [esp-4h] [ebp-2074h]
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v41; // [esp+Ch] [ebp-2064h] BYREF
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v42; // [esp+101Ch] [ebp-1054h] BYREF
  sockaddr s; // [esp+202Ch] [ebp-44h] BYREF
  netadr_s v44; // [esp+203Ch] [ebp-34h] BYREF
  int v45; // [esp+2048h] [ebp-28h] BYREF
  unsigned int v46; // [esp+2050h] [ebp-20h]
  bf_write v47; // [esp+2054h] [ebp-1Ch] BYREF
  unsigned int unBufSize; // [esp+206Ch] [ebp-4h]
  int v49; // [esp+207Ch] [ebp+Ch]

  source = packet->source;
  data = packet->data;
  v5 = 0;
  v45 = 16;
  v6 = g_pSteamSocketMgr->recvfrom(
         this: g_pSteamSocketMgr,
         a2: net_sockets.m_Memory.m_pMemory[source].hUDP,
         a3: (char *)data,
         a4: 96016,
         a5: 0,
         a6: &s,
         a7: &v45);
  v7 = v6;
  if ( v6 <= 0 )
  {
    if ( v6 == -1 )
    {
      Error = WSAGetLastError();
      net_error = Error;
      switch ( Error )
      {
        case 10035:
        case 10054:
        case 10061:
          return 0;
        default:
          v39 = NET_ErrorString(code: Error);
          _ConDMsg(a1: "NET_ReceivePacket: %s\n", v39);
          break;
      }
    }
  }
  else
  {
    packet->wiresize = v6;
    v42.m_pMemory = v42.m_pFixedMemory;
    v42.m_nAllocationCount = 4096;
    v42.m_nGrowSize = -1;
    v42.m_nMallocGrowSize = 4096;
    v49 = 0;
    if ( net_dedicatedForXbox )
    {
      v8 = packet->data;
      v9 = *(unsigned __int16 *)v8;
      if ( (_WORD)v9 != 0xFFFF )
      {
        v10 = *(unsigned __int16 *)v8;
        v11 = v7 - v9 - 2;
        unBufSize = v11;
        if ( v11 > 0 )
        {
          if ( voice_verbose.m_pParent != nullptr && voice_verbose.m_pParent->m_Value.m_nValue != 0 )
          {
            netadr_s::SetIP(this: &v44, unIP: 0);
            netadr_s::SetPort(this: &v44, newport: 0);
            netadr_s::SetType(this: &v44, newtype: NA_IP);
            netadr_s::SetFromSockadr(this: &v44, &s);
            v12 = netadr_s::ToString(this: &v44, baseOnly: false);
            _Msg(a1: "* NET_ReceiveDatagram: receiving voice from %s (%d bytes)\n", v12, v11);
          }
          v13 = packet->data;
          v49 = *(unsigned __int16 *)&v13[v10 + 2];
          v14 = &v13[v10 + 4];
          v47.m_pDebugName = (const char *)4096;
          if ( CLZSS::IsCompressed(this: (CLZSS *)&v47.m_iCurBit, pInput: v14) )
          {
            ActualSize = CLZSS::GetActualSize(this: (CLZSS *)&v47.m_iCurBit, pInput: v14);
            unBufSize = ActualSize;
            if ( ActualSize != (unsigned int)(v49 + 7) >> 3 )
              goto LABEL_11;
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v42, num: ActualSize);
            v16 = CLZSS::SafeUncompress(this: (CLZSS *)&v47.m_iCurBit, pInput: v14, pOutput: v42.m_pMemory, unBufSize);
            if ( v16 != unBufSize )
              goto LABEL_11;
          }
          else
          {
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v42, num: unBufSize);
            _V_memcpy(dest: v42.m_pMemory, src: v14, count: unBufSize);
          }
        }
        _V_memmove(dest: packet->data, src: packet->data + 2, count: v10);
        v7 = v10;
        v5 = 0;
      }
    }
    netadr_s::SetFromSockadr(this: &packet->from, &s);
    packet->size = v7;
    if ( v7 < 96016 )
    {
      if ( *(_DWORD *)packet->data != -2 || NET_GetLong(sock, packet) != 0 )
      {
        v18 = packet->data;
        if ( *(_DWORD *)v18 != -3 )
          goto LABEL_22;
        v19 = v18 + 4;
        v47.m_pDebugName = (const char *)4096;
        v20 = CLZSS::GetActualSize(this: (CLZSS *)&v47.m_iCurBit, pInput: v18 + 4);
        if ( v20 - 1 <= 0x176FF )
        {
          v41.m_pMemory = v41.m_pFixedMemory;
          v41.m_nAllocationCount = 4096;
          v41.m_nGrowSize = -1;
          v41.m_nMallocGrowSize = 4096;
          CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v41, num: v20);
          v21 = CLZSS::SafeUncompress(
                  this: (CLZSS *)&v47.m_iCurBit,
                  pInput: v19,
                  pOutput: v41.m_pMemory,
                  unBufSize: v20);
          v22 = v21;
          if ( v21 == 0 || v20 != v21 )
          {
            CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v41);
            CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v42);
            return 0;
          }
          _V_memcpy(dest: packet->data, src: v41.m_pMemory, count: v21);
          packet->size = v22;
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v41);
          v5 = 0;
LABEL_22:
          if ( v49 == 0 )
          {
LABEL_50:
            v36 = NET_LagPacket(a1: 0, newdata: true, packet);
            CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v42);
            return v36;
          }
          v23 = 8 * packet->size - (packet->data[8] >> 5);
          if ( !ShouldChecksumPackets() )
          {
LABEL_46:
            bf_write::bf_write(this: &v47);
            CNetworkStringTable::SetTick(this: &v47, pDebugName: "X360 Fixup");
            bf_write::StartWriting(this: &v47, pData: packet->data, nBytes: 96016, iStartBit: v23, nBits: -1);
            bf_write::WriteBits(this: &v47, pInData: (unsigned int)v42.m_pMemory, nBits: v49);
            if ( (unsigned int)(v47.m_iCurBit % 8 - 1) <= 1 )
              bf_write::WriteUBitLong(this: &v47, curData: 0, numbits: 6, bCheckRange: true);
            packet->size = (v47.m_iCurBit + 7) >> 3;
            if ( ShouldChecksumPackets() )
            {
              CEngine::SetNextState(this: &v47, bitPos: 72);
              v35 = BufferToShortChecksum(pvData: packet->data + 11, nLength: (const void *)(packet->size - 11));
              bf_write::WriteUBitLong(this: &v47, curData: v35, numbits: 16, bCheckRange: true);
            }
            goto LABEL_50;
          }
          CBitRead::Seek(this: &packet->message, nPosition: 72);
          m_nBitsAvail = packet->message.m_nBitsAvail;
          if ( m_nBitsAvail >= 16 )
          {
            m_nInBufWord = packet->message.m_nInBufWord;
            v26 = (unsigned __int16)m_nInBufWord;
            v27 = m_nBitsAvail - 16;
            packet->message.m_nBitsAvail = v27;
            if ( v27 != 0 )
            {
              packet->message.m_nInBufWord = HIWORD(m_nInBufWord);
              v5 = (unsigned __int16)m_nInBufWord;
            }
            else
            {
              m_pDataIn = packet->message.m_pDataIn;
              m_pBufferEnd = packet->message.m_pBufferEnd;
              packet->message.m_nBitsAvail = 32;
              if ( m_pDataIn == m_pBufferEnd )
              {
                packet->message.m_nInBufWord = 0;
                packet->message.m_nBitsAvail = 1;
                packet->message.m_pDataIn = m_pDataIn + 1;
                v5 = v26;
              }
              else
              {
                if ( m_pDataIn <= m_pBufferEnd )
                {
                  packet->message.m_nInBufWord = *m_pDataIn;
                  packet->message.m_pDataIn = m_pDataIn + 1;
                }
                else
                {
                  packet->message.m_nInBufWord = 0;
                  packet->message.m_bOverflow = true;
                }
                v5 = v26;
              }
            }
LABEL_42:
            CBitRead::Seek(this: &packet->message, nPosition: 0);
            v40 = (const void *)(packet->size - 11);
            if ( (unsigned int)(packet->size - 12) > 0x176FF )
            {
              ConMsg(a1: "corrupted packet detected (checksumbytes %d)\n", v40);
              CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v42);
              return 0;
            }
            if ( (unsigned __int16)BufferToShortChecksum(pvData: packet->data + 11, nLength: v40) != v5 )
            {
              ConMsg(a1: "corrupted packet detected\n");
              CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v42);
              return 0;
            }
            goto LABEL_46;
          }
          v30 = 16 - m_nBitsAvail;
          v31 = packet->message.m_pDataIn;
          v46 = packet->message.m_nInBufWord;
          v32 = packet->message.m_pBufferEnd;
          if ( v31 == v32 )
          {
            packet->message.m_nBitsAvail = 1;
            packet->message.m_nInBufWord = 0;
            packet->message.m_bOverflow = true;
          }
          else
          {
            if ( v31 > v32 )
            {
              packet->message.m_bOverflow = true;
              packet->message.m_nInBufWord = 0;
              goto LABEL_40;
            }
            packet->message.m_nInBufWord = *v31;
          }
          packet->message.m_pDataIn = v31 + 1;
LABEL_40:
          if ( !packet->message.m_bOverflow )
          {
            v33 = packet->message.m_nInBufWord;
            v34 = (v33 & CBitBuffer::s_nMaskTable[v30]) << packet->message.m_nBitsAvail;
            packet->message.m_nBitsAvail = 32 - v30;
            unBufSize = v34;
            v5 = v34 | v46;
            packet->message.m_nInBufWord = v33 >> v30;
          }
          goto LABEL_42;
        }
      }
LABEL_11:
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v42);
      return 0;
    }
    v37 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _ConDMsg(a1: "NET_ReceiveDatagram:  Oversize packet from %s\n", v37);
    if ( v42.m_nGrowSize >= 0 && v42.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42.m_pMemory);
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B7BB0
// Name: struct netpacket_s __near * NET_GetPacket(int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
netpacket_s *__cdecl NET_GetPacket(int sock, unsigned __int8 *scratch)
{
  netpacket_s *v3; // esi

  if ( sock < 0 || sock >= net_packets.m_Size )
    return nullptr;
  v3 = &net_packets.m_Memory.m_pMemory[sock];
  NET_AdjustLag();
  NET_DiscardStaleSplitpackets(sock);
  netadr_s::SetType(this: &v3->from, newtype: NA_IP);
  netadr_s::Clear(this: &v3->from);
  v3->received = net_time;
  v3->source = sock;
  v3->data = scratch;
  v3->size = 0;
  v3->wiresize = 0;
  v3->pNext = nullptr;
  v3->message.m_pDebugName = "inpacket.message";
  if ( NET_GetLoopPacket(packet: v3) == 0
    && (!net_multiplayer
     || NET_ReceiveDatagram((void *)sock, packet: v3) == 0 && NET_LagPacket(a1: 0, newdata: false, packet: v3) == 0) )
  {
    return nullptr;
  }
  CBitRead::StartReading(
    this: &v3->message,
    pData: (const unsigned int *)v3->data,
    nBytes: v3->size,
    iStartBit: 0,
    nBits: -1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101B7C70
// Name: void NET_ProcessSocket(int,class IConnectionlessPacketHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ProcessSocket(int sock, IConnectionlessPacketHandler *handler)
{
  DWORD CurrentThreadId; // ecx
  int i; // edi
  CNetChan *v4; // esi
  int v5; // eax
  TSLHead_t m_Head; // kr00_8
  TSLNodeBase_t *Next; // eax
  unsigned __int8 *v8; // eax
  netpacket_s *Packet; // esi
  int m_nBitsAvail; // eax
  int v11; // eax
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v14; // edx
  int v15; // ecx
  const unsigned int *v16; // eax
  char *v17; // eax
  CNetChan *NetChannel; // eax
  TSLNodeBase_t **v19; // esi
  int size; // [esp-Ch] [ebp-1Ch]
  int v21; // [esp-Ch] [ebp-1Ch]
  int v22; // [esp-Ch] [ebp-1Ch]
  int v23; // [esp-8h] [ebp-18h]
  TSLHead_t v24; // [esp-8h] [ebp-18h]
  TSLHead_t v25; // [esp-8h] [ebp-18h]
  int wiresize; // [esp-4h] [ebp-14h]
  net_scratchbuffer_t *pNetBuffer; // [esp+Ch] [ebp-4h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_NetChannels.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_NetChannels.m_depth;
  }
  for ( i = s_NetChannels.m_Size - 1; i >= 0; --i )
  {
    v4 = s_NetChannels.m_Memory.m_pMemory[i];
    if ( sock == v4->GetSocket(this: v4) && !v4->ProcessStream(this: v4) )
    {
      v5 = (int)v4->GetMsgHandler(this: v4);
      (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 12))(a1: v5, a2: "TCP connection failed.");
    }
  }
  if ( --s_NetChannels.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
  m_Head = g_NetScratchBuffers.m_Head;
  if ( g_NetScratchBuffers.m_Head.value.Next != nullptr )
  {
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &g_NetScratchBuffers,
                               a2: m_Head.value.Next->Next,
                               a3: m_Head.value32.DepthAndSequence - 1,
                               a4: m_Head.value.Next,
                               a5: m_Head.value32.DepthAndSequence) == 0 )
    {
      _mm_pause();
      m_Head = g_NetScratchBuffers.m_Head;
      if ( g_NetScratchBuffers.m_Head.value.Next == nullptr )
        goto LABEL_15;
    }
    Next = m_Head.value.Next;
  }
  else
  {
LABEL_15:
    Next = (TSLNodeBase_t *)MemAlloc_Alloc(nSize: 0x17718u);
  }
  v8 = (unsigned __int8 *)(&Next->Next + 1);
  pNetBuffer = (net_scratchbuffer_t *)v8;
  if ( v8 == nullptr )
  {
    v8 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x17710u);
    pNetBuffer = (net_scratchbuffer_t *)v8;
  }
  Packet = NET_GetPacket(sock, scratch: v8);
  if ( Packet != nullptr )
  {
    while ( Filter_ShouldDiscard(adr: &Packet->from) )
    {
      Filter_SendBan(adr: &Packet->from);
LABEL_47:
      Packet = NET_GetPacket(sock, scratch: pNetBuffer->buf);
      if ( Packet == nullptr )
        goto LABEL_48;
    }
    if ( *(_DWORD *)Packet->data != -1 )
    {
      NetChannel = NET_FindNetChannel(socket: sock, adr: &Packet->from);
      if ( NetChannel != nullptr )
        NetChannel->ProcessPacket(this: NetChannel, a2: Packet, a3: true);
      goto LABEL_47;
    }
    m_nBitsAvail = Packet->message.m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      v11 = m_nBitsAvail - 32;
      Packet->message.m_nBitsAvail = v11;
      if ( v11 != 0 )
      {
        Packet->message.m_nInBufWord = 0;
      }
      else
      {
        m_pDataIn = Packet->message.m_pDataIn;
        Packet->message.m_nBitsAvail = 32;
        m_pBufferEnd = Packet->message.m_pBufferEnd;
        if ( m_pDataIn == m_pBufferEnd )
        {
          Packet->message.m_nBitsAvail = 1;
          Packet->message.m_nInBufWord = 0;
          Packet->message.m_pDataIn = m_pDataIn + 1;
        }
        else if ( m_pDataIn <= m_pBufferEnd )
        {
          Packet->message.m_nInBufWord = *m_pDataIn;
          Packet->message.m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          Packet->message.m_bOverflow = true;
          Packet->message.m_nInBufWord = 0;
        }
      }
LABEL_39:
      if ( net_showudp.m_pParent != nullptr
        && net_showudp.m_pParent->m_Value.m_nValue != 0
        && net_showudp_oob.m_pParent != nullptr
        && net_showudp_oob.m_pParent->m_Value.m_nValue != 0 )
      {
        wiresize = Packet->wiresize;
        v23 = Packet->data[4];
        size = Packet->size;
        v17 = netadr_s::ToString(this: &Packet->from, baseOnly: false);
        _Msg(a1: "UDP <- %s: sz=%d OOB '0x%02X' wire=%d\n", v17, size, v23, wiresize);
      }
      handler->ProcessConnectionlessPacket(this: handler, a2: Packet);
      goto LABEL_47;
    }
    v14 = Packet->message.m_pBufferEnd;
    v15 = 32 - m_nBitsAvail;
    v16 = Packet->message.m_pDataIn;
    if ( v16 == v14 )
    {
      Packet->message.m_nBitsAvail = 1;
      Packet->message.m_nInBufWord = 0;
      Packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v16 > v14 )
      {
        Packet->message.m_bOverflow = true;
        Packet->message.m_nInBufWord = 0;
        goto LABEL_37;
      }
      Packet->message.m_nInBufWord = *v16;
    }
    Packet->message.m_pDataIn = v16 + 1;
LABEL_37:
    if ( !Packet->message.m_bOverflow )
    {
      Packet->message.m_nInBufWord >>= v15;
      Packet->message.m_nBitsAvail = 32 - v15;
    }
    goto LABEL_39;
  }
LABEL_48:
  v24 = g_NetScratchBuffers.m_Head;
  v21 = g_NetScratchBuffers.m_Head.value32.DepthAndSequence + 65537;
  v19 = (TSLNodeBase_t **)&pNetBuffer[-1].buf[96012];
  *(_DWORD *)&pNetBuffer[-1].buf[96012] = g_NetScratchBuffers.m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: &g_NetScratchBuffers,
                          a2: &pNetBuffer[-1].buf[96012],
                          a3: v21,
                          a4: v24.value.Next,
                          a5: v24.value32.DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      v25 = g_NetScratchBuffers.m_Head;
      v22 = g_NetScratchBuffers.m_Head.value32.DepthAndSequence + 65537;
      *v19 = g_NetScratchBuffers.m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &g_NetScratchBuffers,
                               a2: v19,
                               a3: v22,
                               a4: v25.value.Next,
                               a5: v25.value32.DepthAndSequence) == 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7F50
// Name: public: void CBindAddressHelper::GetBindAddresses(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBindAddressHelper::GetBindAddresses(
        CBindAddressHelper *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  CBindAddressHelper *v2; // edi
  CUtlString *m_pMemory; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const CUtlString *v7; // ebx
  CUtlString *v8; // ecx
  int v9; // eax
  CUtlString *v10; // edi
  int i; // [esp+8h] [ebp-4h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *lista; // [esp+14h] [ebp+8h]

  v2 = this;
  if ( !this->m_bInitialized )
  {
    this->m_bInitialized = true;
    CBindAddressHelper::BuildBindAddresses(this, list: &this->m_CachedAddresses);
  }
  i = 0;
  if ( v2->m_CachedAddresses.m_Size > 0 )
  {
    lista = nullptr;
    while ( 1 )
    {
      m_pMemory = v2->m_CachedAddresses.m_Memory.m_pMemory;
      m_Size = list->m_Size;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      v7 = (CUtlString *)((char *)m_pMemory + (_DWORD)lista);
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CPortalRect,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)list,
          num: m_Size - m_nAllocationCount + 1);
      ++list->m_Size;
      v8 = list->m_Memory.m_pMemory;
      v9 = list->m_Size - m_Size - 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[m_Size + 1], src: &v8[m_Size], count: 16 * v9);
      v10 = &list->m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        CUtlString::CUtlString(this: v10, string: v7);
      lista = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)((char *)lista + 16);
      if ( ++i >= this->m_CachedAddresses.m_Size )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8140
// Name: NET_QueuePacketForSend
// Source: json
//------------------------------------------------------------------------------
int __usercall NET_QueuePacketForSend@<eax>(
        int len@<edi>,
        CNetChan *chan,
        unsigned int verbose,
        char *s,
        sockaddr *buf,
        const sockaddr *to,
        unsigned int tolen)
{
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v8; // esi

  if ( net_queued_packet_thread.m_pParent != nullptr
    && net_queued_packet_thread.m_pParent->m_Value.m_nValue != 0
    && g_pQueuedPackedSender->IsRunning(this: g_pQueuedPackedSender) )
  {
    g_pQueuedPackedSender->QueuePacket(
      this: g_pQueuedPackedSender,
      a2: chan,
      a3: verbose,
      a4: s,
      a5: len,
      a6: buf,
      a7: (int)to,
      a8: tolen);
    return len;
  }
  else
  {
    v8 = &g_SendQueue.m_SendQueue.m_Memory.m_pMemory[(unsigned __int16)CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AddToTail(this: &g_SendQueue.m_SendQueue)];
    v8->m_Element.m_Socket = verbose;
    v8->m_Element.m_pChannel = chan;
    CUtlBuffer::Put(this: &v8->m_Element.m_Buffer, pMem: (unsigned __int8 *)s, size: len);
    CUtlBuffer::Put(this: &v8->m_Element.m_To, pMem: (unsigned __int8 *)buf, size: (int)to);
    CNetChan::IncrementQueuedPackets(this: v8->m_Element.m_pChannel);
    return len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B81E0
// Name: NET_SendLong
// Source: json
//------------------------------------------------------------------------------
int __usercall NET_SendLong@<eax>(
        INetChannel *chan@<eax>,
        int sock,
        unsigned int s,
        char *buf,
        int len,
        sockaddr *to,
        const sockaddr *tolen,
        int nMaxRoutableSize)
{
  CNetChan *v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // esi
  int v12; // ebx
  int m_nValue; // eax
  int v14; // edi
  int v15; // eax
  int result; // eax
  int v17; // eax
  const char *v18; // eax
  int v19; // [esp-18h] [ebp-50Ch]
  int v20; // [esp-14h] [ebp-508h]
  char *v21; // [esp-8h] [ebp-4FCh]
  char packet[1200]; // [esp+Ch] [ebp-4E8h] BYREF
  netadr_s adr; // [esp+4BCh] [ebp-38h] BYREF
  int v24[2]; // [esp+4C8h] [ebp-2Ch]
  int v25; // [esp+4D0h] [ebp-24h]
  float flMaxSplitpacketDataRateBytesPerSecond; // [esp+4D4h] [ebp-20h]
  int v27; // [esp+4D8h] [ebp-1Ch]
  int nFragmentsSent; // [esp+4DCh] [ebp-18h]
  void *src; // [esp+4E0h] [ebp-14h]
  int nSequenceNumber; // [esp+4E4h] [ebp-10h]
  int nTotalBytesSent; // [esp+4E8h] [ebp-Ch]
  int nBytesLeft; // [esp+4ECh] [ebp-8h]
  CNetChan *netchan; // [esp+4F0h] [ebp-4h]

  v8 = (CNetChan *)__RTDynamicCast(
                     inptr: chan,
                     VfDelta: 0,
                     SrcType: &INetChannel `RTTI Type Descriptor',
                     TargetType: &CNetChan `RTTI Type Descriptor',
                     isReference: 0);
  netchan = v8;
  if ( v8 != nullptr )
    v9 = CNetChan::IncrementSplitPacketSequence(this: v8);
  else
    v9 = _InterlockedIncrement(&s_SplitPacketSequenceNumber[sock]);
  v10 = (__int16)(nMaxRoutableSize - 12);
  nSequenceNumber = v9;
  *(_WORD *)&packet[10] = nMaxRoutableSize - 12;
  v11 = len;
  *(_DWORD *)&packet[4] = v9;
  v12 = 0;
  *(_DWORD *)packet = -2;
  v27 = v10;
  nBytesLeft = len;
  v25 = (v10 + len - 1) / v10;
  nTotalBytesSent = 0;
  nFragmentsSent = 0;
  if ( len <= 0 )
    return nTotalBytesSent;
  src = buf;
  while ( 1 )
  {
    if ( v10 < v11 )
      v11 = v10;
    *(_WORD *)&packet[8] = v25 + ((_WORD)v12 << 8);
    _V_memcpy(dest: &packet[12], src, count: v11);
    if ( v8 != nullptr
      && (net_splitrate.m_pParent == nullptr ? (m_nValue = 0) : (m_nValue = net_splitrate.m_pParent->m_Value.m_nValue),
          nFragmentsSent >= m_nValue
       || net_queued_packet_thread.m_pParent != nullptr
       && net_queued_packet_thread.m_pParent->m_Value.m_nValue == 581304) )
    {
      v14 = net_splitpacket_maxrate.m_pParent != nullptr ? net_splitpacket_maxrate.m_pParent->m_Value.m_nValue : 0;
      if ( (float)v14 <= (float)netchan->GetDataRate(this: netchan) )
        v15 = net_splitpacket_maxrate.m_pParent != nullptr ? net_splitpacket_maxrate.m_pParent->m_Value.m_nValue : 0;
      else
        v15 = netchan->GetDataRate(this: netchan);
      flMaxSplitpacketDataRateBytesPerSecond = (float)v15;
      *(_QWORD *)v24 = (__int64)((double)(v12 * (nMaxRoutableSize + 28)) / (float)v15 * 1000.0 + 0.5);
      result = NET_QueuePacketForSend(
                 len: v11 + 12,
                 chan: netchan,
                 verbose: s,
                 s: packet,
                 buf: to,
                 to: tolen,
                 tolen: v24[0]);
    }
    else if ( *(_DWORD *)&to->sa_data[2] != 0 || *(_WORD *)to->sa_data != 0 )
    {
      if ( (CL_IsHL2Demo() || CL_IsPortalDemo()) && !net_dedicated )
        _Error(a1: defaultValue);
      result = NET_SendToImpl(s, buf: packet, len: v11 + 12, to, (int)tolen, iGameDataLength: -1);
    }
    else
    {
      result = v11 + 12;
    }
    ++nFragmentsSent;
    if ( result < 0 )
      break;
    if ( result >= v11 )
      nTotalBytesSent += v11;
    src = (char *)src + v27;
    nBytesLeft -= v11;
    ++v12;
    if ( net_showsplits.m_pParent != nullptr )
    {
      v17 = net_showsplits.m_pParent->m_Value.m_nValue;
      if ( v17 != 0 && v17 != 2 )
      {
        netadr_s::SetIP(this: &adr, unIP: 0);
        netadr_s::SetPort(this: &adr, newport: 0);
        netadr_s::SetType(this: &adr, newtype: NA_IP);
        netadr_s::SetFromSockadr(this: &adr, s: to);
        v21 = netadr_s::ToString(this: &adr, baseOnly: false);
        v20 = nSequenceNumber;
        v19 = v25;
        v18 = DescribeSocket((void *)sock);
        _Msg(
          a1: "--> [%s] Split packet %4i/%4i seq %5i size %4i mtu %4i to %s [ total %4i ]\n",
          v18,
          v12,
          v19,
          v20,
          v11,
          nMaxRoutableSize,
          v21,
          len);
      }
    }
    if ( nBytesLeft <= 0 )
      return nTotalBytesSent;
    v11 = nBytesLeft;
    v8 = netchan;
    v10 = v27;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B84A0
// Name: int NET_SendPacket(class INetChannel __near *,int,struct netadr_s const __near &,unsigned char const __near *,int,class bf_write __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NET_SendPacket(
        CNetChan *chan,
        int sock,
        netadr_s *to,
        unsigned __int8 *data,
        int length,
        bf_write *pVoicePayload,
        bool bUseCompression,
        unsigned int unMillisecondsDelay)
{
  int v8; // edi
  netadr_s *v9; // esi
  char *v10; // eax
  IUniformRandomStream *m_pMemory; // ecx
  int m_nValue; // eax
  float m_fValue; // xmm0_4
  int v15; // ebx
  unsigned __int8 *v16; // ebx
  void *v17; // ebx
  int m_iCurBit; // eax
  unsigned __int8 *m_pData; // ecx
  int v20; // edi
  int v21; // esi
  int v22; // eax
  int v23; // eax
  int v24; // esi
  int Error; // eax
  const char *v26; // eax
  int v27; // [esp-4h] [ebp-2060h]
  unsigned int v28; // [esp+0h] [ebp-205Ch]
  int v29; // [esp+4h] [ebp-2058h]
  char *v30; // [esp+4h] [ebp-2058h]
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v31; // [esp+Ch] [ebp-2050h] BYREF
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v32; // [esp+101Ch] [ebp-1040h] BYREF
  sockaddr s; // [esp+202Ch] [ebp-30h] BYREF
  CLZSS v34; // [esp+203Ch] [ebp-20h] BYREF
  unsigned __int8 *v35; // [esp+2048h] [ebp-14h]
  unsigned int pOutputSize; // [esp+204Ch] [ebp-10h] BYREF
  int tolen; // [esp+2050h] [ebp-Ch]
  bool verbose[4]; // [esp+2054h] [ebp-8h]
  unsigned int m_fValue_low; // [esp+2058h] [ebp-4h] BYREF

  v8 = length;
  if ( net_showudp.m_pParent == nullptr
    || net_showudp.m_pParent->m_Value.m_nValue == 0
    || *(_DWORD *)data != -1
    || net_showudp_oob.m_pParent == nullptr
    || net_showudp_oob.m_pParent->m_Value.m_nValue == 0 )
  {
    v9 = to;
    goto LABEL_14;
  }
  if ( net_showudp_remoteonly.m_pParent == nullptr || net_showudp_remoteonly.m_pParent->m_Value.m_nValue == 0 )
  {
    v9 = to;
LABEL_12:
    v27 = data[4];
    v10 = netadr_s::ToString(this: v9, baseOnly: false);
    _Msg(a1: "UDP -> %s: sz=%d OOB '0x%02X'\n", v10, length, v27);
    goto LABEL_14;
  }
  v9 = to;
  if ( (unsigned __int8)netadr_s::IsLocalhost(this: to) == 0 && !netadr_s::IsLoopback(this: to) )
    goto LABEL_12;
LABEL_14:
  if ( !net_multiplayer
    || v9->type == NA_LOOPBACK
    || (unsigned __int8)netadr_s::IsLocalhost(this: v9) != 0
    && (net_usesocketsforloopback.m_pParent == nullptr || net_usesocketsforloopback.m_pParent->m_Value.m_nValue == 0) )
  {
    NET_SendLoopPacket((loopback_t *)sock, length, data);
    return length;
  }
  if ( v9->type == NA_BROADCAST )
  {
    m_pMemory = (IUniformRandomStream *)(2 * sock);
    *(_DWORD *)verbose = net_sockets.m_Memory.m_pMemory[sock].hUDP;
    if ( *(_DWORD *)verbose == 0 )
      return length;
  }
  else
  {
    if ( v9->type != NA_IP )
    {
      DevMsg(a1: "NET_SendPacket: bad address type (%i)\n", v9->type);
      return length;
    }
    m_pMemory = (IUniformRandomStream *)net_sockets.m_Memory.m_pMemory;
    *(_DWORD *)verbose = net_sockets.m_Memory.m_pMemory[sock].hUDP;
    if ( *(_DWORD *)verbose == 0 )
      return length;
  }
  if ( droppackets.m_pParent != nullptr )
  {
    m_nValue = droppackets.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 && sock == 0 )
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&droppackets.IConVar, value: m_nValue + 1, a2: v28, a3: v29);
      return length;
    }
  }
  m_fValue = fakeloss.m_pParent->m_Value.m_fValue;
  if ( m_fValue > 0.0 )
  {
    m_fValue_low = LODWORD(fakeloss.m_pParent->m_Value.m_fValue);
    if ( _RandomInt(this: m_pMemory, a2: 0, a3: 100) <= (int)m_fValue )
      return length;
  }
  netadr_s::ToSockadr(this: v9, &s);
  v32.m_pMemory = v32.m_pFixedMemory;
  v32.m_nAllocationCount = 4096;
  v32.m_nGrowSize = -1;
  v32.m_nMallocGrowSize = 4096;
  v31.m_pMemory = v31.m_pFixedMemory;
  v31.m_nAllocationCount = 4096;
  v31.m_nGrowSize = -1;
  v31.m_nMallocGrowSize = 4096;
  tolen = length;
  if ( pVoicePayload == nullptr )
    tolen = -1;
  v15 = 0;
  if ( pVoicePayload != nullptr )
  {
    CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(
      this: &v31,
      num: ((pVoicePayload->m_iCurBit + 7) >> 3) + 2);
    v16 = v31.m_pMemory;
    *(_WORD *)v31.m_pMemory = pVoicePayload->m_iCurBit;
    v17 = v16 + 2;
    pOutputSize = (pVoicePayload->m_iCurBit + 7) >> 3;
    if ( net_compressvoice.m_pParent == nullptr
      || net_compressvoice.m_pParent->m_Value.m_nValue == 0
      || (m_iCurBit = pVoicePayload->m_iCurBit,
          m_pData = pVoicePayload->m_pData,
          v34.m_nWindowSize = 4096,
          CLZSS::CompressNoAlloc(
            this: &v34,
            pInput: (int)m_pData,
            inputLength: (m_iCurBit + 7) >> 3,
            pOutputBuf: (unsigned __int8 *)v17,
            &pOutputSize) == nullptr) )
    {
      _V_memcpy(dest: v17, src: pVoicePayload->m_pData, count: (pVoicePayload->m_iCurBit + 7) >> 3);
    }
    v15 = pOutputSize + 2;
  }
  if ( voice_xsend_debug.m_pParent != nullptr && voice_xsend_debug.m_pParent->m_Value.m_nValue != 0 && v15 != 0 )
    DevMsg(a1: "XVoice: voice data payload for %p: %d bytes\n", chan, v15);
  if ( bUseCompression
    && (v34.m_nWindowSize = 4096,
        m_fValue_low = length,
        CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v32, num: v15 + length + 4),
        *(_DWORD *)v32.m_pMemory = -3,
        CLZSS::CompressNoAlloc(
          this: &v34,
          pInput: (int)data,
          inputLength: length,
          pOutputBuf: v32.m_pMemory + 4,
          pOutputSize: &m_fValue_low) != nullptr) )
  {
    v20 = m_fValue_low + 4;
    data = v32.m_pMemory;
    if ( pVoicePayload != nullptr && pVoicePayload->m_iCurBit > 0 )
      _V_memcpy(dest: &v32.m_pMemory[v20], src: v31.m_pMemory, count: v15);
    tolen = v20;
    v8 = v15 + v20;
  }
  else if ( pVoicePayload != nullptr && pVoicePayload->m_iCurBit > 0 )
  {
    CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v32, num: v15 + length);
    v35 = v32.m_pMemory;
    _V_memcpy(dest: v32.m_pMemory, src: data, count: length);
    _V_memcpy(dest: &v35[length], src: v31.m_pMemory, count: v15);
    data = v32.m_pMemory;
    v8 = v15 + length;
  }
  v21 = 1200;
  if ( chan != nullptr )
  {
    if ( sv_maxroutable.m_pParent != nullptr )
    {
      v21 = sv_maxroutable.m_pParent->m_Value.m_nValue;
      if ( v21 >= 1200 )
        v21 = 1200;
    }
    else
    {
      v21 = 0;
    }
    v22 = chan->GetMaxRoutablePayloadSize(this: chan);
    if ( v22 >= 576 )
    {
      if ( v22 <= v21 )
        v21 = v22;
    }
    else
    {
      v21 = 576;
    }
  }
  if ( unMillisecondsDelay == 0 )
    goto LABEL_63;
  if ( v8 > v21 )
  {
    _Warning(a1: "Can't delay send a packet larger than maxroutable size %d/%d\n", v8, v21);
LABEL_63:
    if ( v8 > v21
      || net_queued_packet_thread.m_pParent != nullptr
      && net_queued_packet_thread.m_pParent->m_Value.m_nValue == 581304
      && chan != nullptr )
    {
      v23 = NET_SendLong(
              chan,
              sock,
              s: *(unsigned int *)verbose,
              buf: (char *)data,
              len: v8,
              to: &s,
              tolen: (const sockaddr *)0x10,
              nMaxRoutableSize: v21);
    }
    else
    {
      v23 = NET_SendTo(
              len: v8,
              to: &s,
              verbose: *(unsigned int *)verbose,
              s: (char *)data,
              buf: (const char *)0x10,
              tolen);
    }
    goto LABEL_70;
  }
  v23 = NET_QueuePacketForSend(
          len: v8,
          chan,
          verbose: *(unsigned int *)verbose,
          s: (char *)data,
          buf: &s,
          to: (const sockaddr *)0x10,
          tolen: unMillisecondsDelay);
LABEL_70:
  v24 = v23;
  if ( v23 == -1 )
  {
    Error = WSAGetLastError();
    net_error = Error;
    if ( Error == 10035 || Error == 10054 || Error == 10049 && to->type == NA_BROADCAST )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v31);
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v32);
      return 0;
    }
    v30 = netadr_s::ToString(this: to, baseOnly: false);
    v26 = NET_ErrorString(code: net_error);
    _ConDMsg(a1: "NET_SendPacket Warning: %s : %s\n", v26, v30);
    v24 = v8;
  }
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v31);
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v32);
  return v24;
}

//------------------------------------------------------------------------------
// Address: 0x101B8990
// Name: void NET_OutOfBandPrintf(int,struct netadr_s const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void NET_OutOfBandPrintf(int sock, netadr_s *adr, const char *format, ...)
{
  int v3; // eax
  char string[1200]; // [esp+0h] [ebp-4B0h] BYREF
  va_list params; // [esp+4C4h] [ebp+14h] BYREF

  va_start(params, format);
  *(_DWORD *)string = -1;
  V_vsnprintf(pDest: &string[4], maxLen: 1196, pFormat: format, params);
  v3 = _V_strlen(str: &string[4]);
  NET_SendPacket(
    chan: nullptr,
    sock,
    to: adr,
    data: (unsigned __int8 *)string,
    length: v3 + 5,
    pVoicePayload: nullptr,
    bUseCompression: false,
    unMillisecondsDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B89F0
// Name: void NET_OutOfBandDelayedPrintf(int,struct netadr_s const __near &,unsigned int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void NET_OutOfBandDelayedPrintf(int sock, netadr_s *adr, unsigned int unMillisecondsDelay, const char *format, ...)
{
  int v4; // eax
  char string[1200]; // [esp+0h] [ebp-4B0h] BYREF
  va_list params; // [esp+4C8h] [ebp+18h] BYREF

  va_start(params, format);
  *(_DWORD *)string = -1;
  V_vsnprintf(pDest: &string[4], maxLen: 1196, pFormat: format, params);
  v4 = _V_strlen(str: &string[4]);
  NET_SendPacket(
    chan: nullptr,
    sock,
    to: adr,
    data: (unsigned __int8 *)string,
    length: v4 + 5,
    pVoicePayload: nullptr,
    bUseCompression: false,
    unMillisecondsDelay);
}

//------------------------------------------------------------------------------
// Address: 0x101B8A60
// Name: void NET_ClearQueuedPacketsForChannel(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ClearQueuedPacketsForChannel(CNetChan *channel)
{
  unsigned __int16 m_Head; // di
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *m_pMemory; // eax
  unsigned int v3; // esi
  unsigned __int16 m_Next; // cx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v5; // esi
  unsigned __int16 n; // [esp+4h] [ebp-4h]

  m_Head = g_SendQueue.m_SendQueue.m_Head;
  if ( g_SendQueue.m_SendQueue.m_Head != 0xFFFF )
  {
    m_pMemory = g_SendQueue.m_SendQueue.m_Memory.m_pMemory;
    do
    {
      v3 = m_Head;
      m_Next = m_pMemory[v3].m_Next;
      n = m_Next;
      if ( m_pMemory[v3].m_Element.m_pChannel == channel )
      {
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
          this: &g_SendQueue.m_SendQueue,
          elem: m_Head);
        v5 = &g_SendQueue.m_SendQueue.m_Memory.m_pMemory[v3];
        if ( v5->m_Element.m_To.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_To.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_To.m_Memory.m_pMemory);
            v5->m_Element.m_To.m_Memory.m_pMemory = nullptr;
          }
          v5->m_Element.m_To.m_Memory.m_nAllocationCount = 0;
        }
        if ( v5->m_Element.m_Buffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_Buffer.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_Buffer.m_Memory.m_pMemory);
            v5->m_Element.m_Buffer.m_Memory.m_pMemory = nullptr;
          }
          v5->m_Element.m_Buffer.m_Memory.m_nAllocationCount = 0;
        }
        v5->m_Next = g_SendQueue.m_SendQueue.m_FirstFree;
        m_pMemory = g_SendQueue.m_SendQueue.m_Memory.m_pMemory;
        m_Next = n;
        g_SendQueue.m_SendQueue.m_FirstFree = m_Head;
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8B30
// Name: void NET_SendQueuedPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_SendQueuedPackets()
{
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v0; // esi
  unsigned __int8 *m_pMemory; // edi
  int m_Put; // ebx
  int m_Head; // edi
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v4; // esi
  bool v5; // zf
  unsigned int s; // [esp+0h] [ebp-10h]
  char *buf; // [esp+4h] [ebp-Ch]
  int len; // [esp+8h] [ebp-8h]
  int nRemaining; // [esp+Ch] [ebp-4h]

  if ( host_framecount != g_SendQueue.m_nHostFrame )
  {
    g_SendQueue.m_nHostFrame = host_framecount;
    if ( net_splitrate.m_pParent != nullptr )
    {
      nRemaining = net_splitrate.m_pParent->m_Value.m_nValue;
      if ( nRemaining != 0 )
      {
        do
        {
          if ( g_SendQueue.m_SendQueue.m_Head >= g_SendQueue.m_SendQueue.m_Memory.m_nAllocationCount )
            break;
          if ( g_SendQueue.m_SendQueue.m_Head > g_SendQueue.m_SendQueue.m_LastAlloc.index )
            break;
          v0 = &g_SendQueue.m_SendQueue.m_Memory.m_pMemory[g_SendQueue.m_SendQueue.m_Head];
          if ( v0->m_Previous == g_SendQueue.m_SendQueue.m_Head && v0->m_Next != g_SendQueue.m_SendQueue.m_Head )
            break;
          m_pMemory = v0->m_Element.m_To.m_Memory.m_pMemory;
          m_Put = v0->m_Element.m_To.m_Put;
          len = v0->m_Element.m_Buffer.m_Put;
          buf = (char *)v0->m_Element.m_Buffer.m_Memory.m_pMemory;
          s = v0->m_Element.m_Socket;
          if ( *((_DWORD *)m_pMemory + 1) != 0 || *((_WORD *)m_pMemory + 1) != 0 )
          {
            if ( (CL_IsHL2Demo() || CL_IsPortalDemo()) && !net_dedicated )
              _Error(a1: defaultValue);
            NET_SendToImpl(s, buf, len, to: (const sockaddr *)m_pMemory, tolen: m_Put, iGameDataLength: -1);
          }
          CNetChan::DecrementQueuedPackets(this: v0->m_Element.m_pChannel);
          m_Head = g_SendQueue.m_SendQueue.m_Head;
          CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
            this: &g_SendQueue.m_SendQueue,
            elem: g_SendQueue.m_SendQueue.m_Head);
          v4 = &g_SendQueue.m_SendQueue.m_Memory.m_pMemory[m_Head];
          if ( v4->m_Element.m_To.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v4->m_Element.m_To.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Element.m_To.m_Memory.m_pMemory);
              v4->m_Element.m_To.m_Memory.m_pMemory = nullptr;
            }
            v4->m_Element.m_To.m_Memory.m_nAllocationCount = 0;
          }
          if ( v4->m_Element.m_Buffer.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v4->m_Element.m_Buffer.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Element.m_Buffer.m_Memory.m_pMemory);
              v4->m_Element.m_Buffer.m_Memory.m_pMemory = nullptr;
            }
            v4->m_Element.m_Buffer.m_Memory.m_nAllocationCount = 0;
          }
          v5 = nRemaining-- == 1;
          v4->m_Next = g_SendQueue.m_SendQueue.m_FirstFree;
          g_SendQueue.m_SendQueue.m_FirstFree = m_Head;
        }
        while ( !v5 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8CB0
// Name: OpenSocketInternal
// Source: json
//------------------------------------------------------------------------------
void __cdecl OpenSocketInternal(
        int nModule,
        int nSetPort,
        int nDefaultPort,
        const char *pName,
        unsigned int nProtocol,
        BOOL bTryAny)
{
  char *m_pszString; // eax
  CUtlString *v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // esi
  int v11; // eax
  int *p_hTCP; // ebx
  int v13; // edi
  const char *v14; // eax
  const char *v15; // esi
  SOCKET v16; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecBindableAddresses; // [esp+Ch] [ebp-34h] BYREF
  CUtlString v18; // [esp+20h] [ebp-20h] BYREF
  int nSavePort; // [esp+30h] [ebp-10h]
  CUtlString *m_pMemory; // [esp+34h] [ebp-Ch]
  int v21; // [esp+38h] [ebp-8h]
  int port; // [esp+3Ch] [ebp-4h] BYREF

  memset(&vecBindableAddresses, 0, sizeof(vecBindableAddresses));
  if ( (ipname.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = ipname.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v7 = CUtlString::CUtlString(this: &v18, pString: m_pszString);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: &vecBindableAddresses, elem: 0, src: v7);
  v18.m_Storage.m_nActualLength = 0;
  if ( v18.m_Storage.m_Memory.m_nGrowSize >= 0 && v18.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18.m_Storage.m_Memory.m_pMemory);
  CBindAddressHelper::GetBindAddresses(this: &g_BindAddressHelper, list: &vecBindableAddresses);
  v8 = nSetPort;
  v9 = nSetPort;
  if ( nSetPort == 0 )
    v9 = nDefaultPort;
  v10 = nProtocol;
  if ( nProtocol == 6 )
  {
    v11 = 16 * nModule;
    v21 = 16 * nModule;
    p_hTCP = &net_sockets.m_Memory.m_pMemory[nModule].hTCP;
  }
  else
  {
    if ( nProtocol != 17 )
    {
      Sys_Error(error: "Unrecognized protocol type %d", nProtocol);
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecBindableAddresses);
      return;
    }
    v21 = 16 * nModule;
    p_hTCP = &net_sockets.m_Memory.m_pMemory[nModule].hUDP;
    v11 = 16 * nModule;
  }
  if ( *(int *)((char *)&net_sockets.m_Memory.m_pMemory->nPort + v11) != 0 )
  {
    _Msg(
      a1: "WARNING: NET_OpenSockets: %s port %i already open.\n",
      pName,
      *(int *)((char *)&net_sockets.m_Memory.m_pMemory->nPort + v11));
LABEL_31:
    if ( p_hTCP != nullptr )
      g_pSteamSocketMgr->OpenSocket(
        this: g_pSteamSocketMgr,
        a2: *p_hTCP,
        a3: nModule,
        a4: v8,
        a5: nDefaultPort,
        a6: pName,
        a7: v10,
        a8: bTryAny);
    goto LABEL_33;
  }
  v13 = 0;
  nSavePort = v9;
  if ( vecBindableAddresses.m_Size > 0 )
  {
    m_pMemory = vecBindableAddresses.m_Memory.m_pMemory;
    while ( 1 )
    {
      port = nSavePort;
      v14 = CUtlString::operator char const *(this: m_pMemory);
      v15 = v14;
      if ( v13 > 0 )
        _Msg(a1: "Trying to open socket on %s\n", v14);
      v16 = NET_OpenSocket(net_interface: v15, &port, protocol: nProtocol);
      *p_hTCP = v16;
      if ( v16 != 0 )
        break;
      if ( bTryAny )
      {
        port = -1;
        *p_hTCP = NET_OpenSocket(net_interface: v15, &port, protocol: nProtocol);
      }
      if ( *p_hTCP != 0 )
        break;
      ++m_pMemory;
      if ( ++v13 >= vecBindableAddresses.m_Size )
      {
        v9 = port;
        v10 = nProtocol;
        v11 = v21;
        goto LABEL_26;
      }
    }
    v9 = port;
    v10 = nProtocol;
    v11 = v21;
    goto LABEL_29;
  }
LABEL_26:
  if ( *p_hTCP != 0 )
  {
LABEL_29:
    v8 = nSetPort;
    *(int *)((char *)&net_sockets.m_Memory.m_pMemory->nPort + v11) = v9;
    goto LABEL_31;
  }
  Sys_Exit(error: "Couldn't allocate any %s IP port, tried %d addresses", pName, vecBindableAddresses.m_Size);
LABEL_33:
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecBindableAddresses);
  if ( vecBindableAddresses.m_Memory.m_nGrowSize >= 0 && vecBindableAddresses.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecBindableAddresses.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101B8EC0
// Name: void NET_OpenSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_OpenSockets()
{
  int m_nValue; // eax
  int v1; // eax
  int v2; // eax

  if ( hostport.m_pParent != nullptr )
    m_nValue = hostport.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  OpenSocketInternal(
    nModule: 1,
    nSetPort: m_nValue,
    nDefaultPort: 27015,
    pName: "server",
    nProtocol: 0x11u,
    bTryAny: false);
  if ( clientport.m_pParent != nullptr )
    v1 = clientport.m_pParent->m_Value.m_nValue;
  else
    v1 = 0;
  OpenSocketInternal(nModule: 0, nSetPort: v1, nDefaultPort: 27015, pName: "client", nProtocol: 0x11u, bTryAny: true);
  if ( !net_nohltv )
  {
    if ( hltvport.m_pParent != nullptr )
      v2 = hltvport.m_pParent->m_Value.m_nValue;
    else
      v2 = 0;
    OpenSocketInternal(nModule: 2, nSetPort: v2, nDefaultPort: 27020, pName: "hltv", nProtocol: 0x11u, bTryAny: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8F60
// Name: void NET_Config(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_Config()
{
  int v0; // eax
  CRConServer *v1; // eax
  CRConServer *v2; // eax
  const char *v3; // edx
  const char *v4; // ecx
  char *v5; // eax
  const char *v6; // [esp-14h] [ebp-20h]
  const char *v7; // [esp-10h] [ebp-1Ch]
  int v8; // [esp-Ch] [ebp-18h]
  int nPort; // [esp-8h] [ebp-14h]
  char *v10; // [esp-4h] [ebp-10h]
  netadr_s rconAddr; // [esp+0h] [ebp-Ch] BYREF

  NET_CloseAllSockets();
  net_time = 0.0;
  if ( net_multiplayer )
  {
    NET_ClearLoopbackBuffers();
    NET_GetLocalAddress();
    NET_OpenSockets();
    if ( net_dedicated
      || (v0 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-usercon") != 0) )
    {
      rconAddr = net_local_adr;
      netadr_s::SetPort(this: &rconAddr, newport: net_sockets.m_Memory.m_pMemory[1].nPort);
      v10 = netadr_s::ToString(this: &rconAddr, baseOnly: false);
      v1 = RCONServer();
      CRConServer::SetAddress(this: v1, pNetAddress: v10);
      v2 = RCONServer();
      CRConServer::CreateSocket(this: v2);
    }
  }
  else
  {
    NET_ClearLoopbackBuffers();
  }
  v3 = "Yes";
  if ( !net_dedicated )
    v3 = "No";
  v4 = "MP";
  if ( !net_multiplayer )
    v4 = "SP";
  nPort = net_sockets.m_Memory.m_pMemory->nPort;
  v8 = net_sockets.m_Memory.m_pMemory[1].nPort;
  v7 = v3;
  v6 = v4;
  v5 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
  _Msg(a1: "Network: IP %s, mode %s, dedicated %s, ports %i SV / %i CL\n", v5, v6, v7, v8, nPort);
}

//------------------------------------------------------------------------------
// Address: 0x101B9060
// Name: void NET_SetMultiplayer(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_SetMultiplayer(bool multiplayer)
{
  if ( net_noip && multiplayer )
  {
    _Msg(a1: "Warning! Multiplayer mode not available with -noip parameter.\n");
  }
  else if ( !net_dedicated || multiplayer )
  {
    if ( net_multiplayer != multiplayer )
    {
      net_multiplayer = multiplayer;
      NET_Config();
    }
    if ( !multiplayer )
      NET_ClearLoopbackBuffers();
  }
  else
  {
    _Msg(a1: "Warning! Singleplayer mode not available on dedicated server.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B90D0
// Name: void NET_Init(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall NET_Init(int a1@<edi>, bool bIsDedicated)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // edi
  netpacket_s **v10; // esi
  int v11; // eax
  const char *v12; // eax
  int v13; // eax
  int v14; // eax
  IMatchTitle *v15; // eax
  bool v16; // bl
  netsocket_t *v17; // [esp-28h] [ebp-1C0h]
  const char *v18; // [esp-20h] [ebp-1B8h]
  int v19; // [esp-1Ch] [ebp-1B4h]
  WSAData wsaData; // [esp+8h] [ebp-190h] BYREF

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-nodns") != 0 )
    net_nodns = true;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-usetcp") != 0 )
    net_notcp = false;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-nohltv") != 0 )
    net_nohltv = true;
  v5 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-noip") != 0 )
    goto LABEL_10;
  if ( WSAStartup(wVersionRequested: 2u, lpWSAData: &wsaData) != 0 )
  {
    ConMsg(a1: "Error! Failed to load network socket library.\n");
LABEL_10:
    net_noip = true;
  }
  net_time = 0.0;
  v6 = _CommandLine();
  v7 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v6 + 28))(a1: v6, a2: "-port", a3: -1);
  if ( v7 != -1
    || (v8 = _CommandLine(),
        v19 = -1,
        v18 = "+port",
        (v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 28))(a1: v8)) != -1) )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&hostport.IConVar, value: v7, a2: (unsigned int)v18, a3: v19);
  }
  if ( net_sockets.m_Size < 3 )
    CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int>>::InsertMultipleBefore(
      this: &net_sockets,
      elem: net_sockets.m_Size,
      num: 3 - net_sockets.m_Size);
  if ( net_packets.m_Size < 3 )
    CUtlVector<netpacket_s,CUtlMemory<netpacket_s,int>>::InsertMultipleBefore(
      this: &net_packets,
      elem: net_packets.m_Size,
      num: 3 - net_packets.m_Size);
  if ( net_splitpackets.m_Size < 3 )
    CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,int> > *)&net_splitpackets,
      elem: net_splitpackets.m_Size,
      num: 3 - net_splitpackets.m_Size);
  v9 = 0;
  v10 = s_pLagData;
  do
  {
    v17 = &net_sockets.m_Memory.m_pMemory[v9];
    *v10 = nullptr;
    _V_memset(dest: v17, fill: 0, count: 16);
    ++v10;
    ++v9;
  }
  while ( (int)v10 < (int)&net_multiplayer );
  v11 = _CommandLine();
  v12 = (const char *)(*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 32))(a1: v11, a2: "-ip");
  if ( v12 != nullptr )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&ipname.IConVar, value: v12, a2: 0);
  if ( bIsDedicated )
  {
    if ( net_noip )
    {
      _Msg(a1: "Warning! Dedicated not possible with -noip parameter.\n");
    }
    else
    {
      net_dedicated = true;
      v13 = _CommandLine();
      net_dedicatedForXbox = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v13 + 40))(
                               a1: v13,
                               a2: "-xlsp",
                               a3: a1) != 0;
      v14 = _CommandLine();
      net_dedicatedForXboxInsecure = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(
                                       a1: v14,
                                       a2: "-xlsp_insecure") != 0;
    }
  }
  else
  {
    NET_ClearLoopbackBuffers();
  }
  NET_InitParanoidMode();
  v15 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  v16 = (v15->GetTitleSettingsFlags(this: v15) & 1) != 0;
  if ( net_noip && v16 )
  {
    _Msg(a1: "Warning! Multiplayer mode not available with -noip parameter.\n");
  }
  else if ( !net_dedicated || v16 )
  {
    if ( net_multiplayer != v16 )
    {
      net_multiplayer = v16;
      NET_Config();
    }
    if ( !v16 )
      NET_ClearLoopbackBuffers();
  }
  else
  {
    _Msg(a1: "Warning! Singleplayer mode not available on dedicated server.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9350
// Name: net_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_start()
{
  net_multiplayer = true;
  NET_Config();
}

//------------------------------------------------------------------------------
// Address: 0x101B9360
// Name: void NET_RemoveNetChannel(class INetChannel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_RemoveNetChannel(CNetChan *netchan, bool bDeleteNetChan)
{
  CNetChan *v2; // esi
  DWORD CurrentThreadId; // ecx
  int v4; // eax

  v2 = netchan;
  if ( netchan != nullptr )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_NetChannels.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_NetChannels.m_depth;
    }
    v4 = 0;
    if ( s_NetChannels.m_Size <= 0 )
      goto LABEL_11;
    while ( s_NetChannels.m_Memory.m_pMemory[v4] != v2 )
    {
      if ( ++v4 >= s_NetChannels.m_Size )
        goto LABEL_11;
    }
    if ( v4 == -1 )
    {
LABEL_11:
      _DevMsg(a1: 1, a2: "NET_CloseNetChannel: unknown channel.\n");
      if ( --s_NetChannels.m_depth != 0 )
        return;
      goto LABEL_16;
    }
    netchan = v2;
    CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_NetChannels,
      src: (vgui::TreeNode **)&netchan);
    NET_ClearQueuedPacketsForChannel(channel: v2);
    if ( bDeleteNetChan )
      ((void (__thiscall *)(CNetChan *, int))v2->dtr_INetChannel)(a1: v2, a2: 1);
    if ( --s_NetChannels.m_depth == 0 )
LABEL_16:
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10313570
// Name: _dynamic_initializer_for__net_earliertempents__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_earliertempents__()
{
  ConVar::ConVar(this: &net_earliertempents, pName: "net_earliertempents", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__net_earliertempents__);
}

//------------------------------------------------------------------------------
// Address: 0x10317070
// Name: _dynamic_initializer_for__net_megasnapshot__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_megasnapshot__()
{
  ConVar::ConVar(this: &net_megasnapshot, pName: "net_megasnapshot", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__net_megasnapshot__);
}

//------------------------------------------------------------------------------
// Address: 0x10317300
// Name: _dynamic_initializer_for__net_showreliablesounds__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showreliablesounds__()
{
  ConVar::ConVar(this: &net_showreliablesounds, pName: "net_showreliablesounds", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__net_showreliablesounds__);
}

//------------------------------------------------------------------------------
// Address: 0x10319D50
// Name: _dynamic_initializer_for__net_showevents__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showevents__()
{
  ConVar::ConVar(
    this: &net_showevents,
    pName: "net_showevents",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Dump game events to console (1=client only, 2=all).");
  return atexit(func: dynamic_atexit_destructor_for__net_showevents__);
}

//------------------------------------------------------------------------------
// Address: 0x10319D80
// Name: _dynamic_initializer_for__net_showeventlisteners__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showeventlisteners__()
{
  ConVar::ConVar(
    this: &net_showeventlisteners,
    pName: "net_showeventlisteners",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show listening addition/removals");
  return atexit(func: dynamic_atexit_destructor_for__net_showeventlisteners__);
}

//------------------------------------------------------------------------------
// Address: 0x10319E00
// Name: _dynamic_initializer_for__net_dumpeventstats_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_dumpeventstats_command__()
{
  ConCommand::ConCommand(
    this: &net_dumpeventstats_command,
    pName: "net_dumpeventstats",
    callback: net_dumpeventstats,
    pHelpString: "Dumps out a report of game event network usage",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__net_dumpeventstats_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C550
// Name: _dynamic_initializer_for__net_showudp__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showudp__()
{
  ConVar::ConVar(
    this: &net_showudp,
    pName: "net_showudp",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Dump UDP packets summary to console");
  return atexit(func: dynamic_atexit_destructor_for__net_showudp__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C580
// Name: _dynamic_initializer_for__net_showudp_oob__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showudp_oob__()
{
  ConVar::ConVar(
    this: &net_showudp_oob,
    pName: "net_showudp_oob",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Dump OOB UDP packets summary to console");
  return atexit(func: dynamic_atexit_destructor_for__net_showudp_oob__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C5B0
// Name: _dynamic_initializer_for__net_showudp_remoteonly__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showudp_remoteonly__()
{
  ConVar::ConVar(
    this: &net_showudp_remoteonly,
    pName: "net_showudp_remoteonly",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Dump non-loopback udp only");
  return atexit(func: dynamic_atexit_destructor_for__net_showudp_remoteonly__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C5E0
// Name: _dynamic_initializer_for__net_showtcp__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showtcp__()
{
  ConVar::ConVar(
    this: &net_showtcp,
    pName: "net_showtcp",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Dump TCP stream summary to console");
  return atexit(func: dynamic_atexit_destructor_for__net_showtcp__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C610
// Name: _dynamic_initializer_for__net_blocksize__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_blocksize__()
{
  ConVar::ConVar(
    this: &net_blocksize,
    pName: "net_maxfragments",
    pDefaultValue: "1200",
    flags: 0,
    pHelpString: "Max fragment bytes per packet",
    bMin: true,
    fMin: 256.0,
    bMax: true,
    fMax: 1200.0);
  return atexit(func: dynamic_atexit_destructor_for__net_blocksize__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C650
// Name: _dynamic_initializer_for__net_showmsg__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showmsg__()
{
  ConVar::ConVar(
    this: &net_showmsg,
    pName: "net_showmsg",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Show incoming message: <0|1|name>");
  return atexit(func: dynamic_atexit_destructor_for__net_showmsg__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C680
// Name: _dynamic_initializer_for__net_showfragments__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showfragments__()
{
  ConVar::ConVar(
    this: &net_showfragments,
    pName: "net_showfragments",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show netchannel fragments");
  return atexit(func: dynamic_atexit_destructor_for__net_showfragments__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C6B0
// Name: _dynamic_initializer_for__net_showpeaks__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showpeaks__()
{
  ConVar::ConVar(
    this: &net_showpeaks,
    pName: "net_showpeaks",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show messages for large packets only: <size>");
  return atexit(func: dynamic_atexit_destructor_for__net_showpeaks__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C6E0
// Name: _dynamic_initializer_for__net_blockmsg__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_blockmsg__()
{
  ConVar::ConVar(
    this: &net_blockmsg,
    pName: "net_blockmsg",
    pDefaultValue: "none",
    flags: 0x4000,
    pHelpString: "Discards incoming message: <0|1|name>");
  return atexit(func: dynamic_atexit_destructor_for__net_blockmsg__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C710
// Name: _dynamic_initializer_for__net_showdrop__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showdrop__()
{
  ConVar::ConVar(
    this: &net_showdrop,
    pName: "net_showdrop",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Show dropped packets in console");
  return atexit(func: dynamic_atexit_destructor_for__net_showdrop__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C740
// Name: _dynamic_initializer_for__net_drawslider__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_drawslider__()
{
  ConVar::ConVar(
    this: &net_drawslider,
    pName: "net_drawslider",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw completion slider during signon");
  return atexit(func: dynamic_atexit_destructor_for__net_drawslider__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C770
// Name: _dynamic_initializer_for__net_chokeloopback__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_chokeloopback__()
{
  ConVar::ConVar(
    this: &net_chokeloopback,
    pName: "net_chokeloop",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Apply bandwidth choke to loopback packets");
  return atexit(func: dynamic_atexit_destructor_for__net_chokeloopback__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C7A0
// Name: _dynamic_initializer_for__net_maxfilesize__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_maxfilesize__()
{
  ConVar::ConVar(
    this: &net_maxfilesize,
    pName: "net_maxfilesize",
    pDefaultValue: "16",
    flags: 0,
    pHelpString: "Maximum allowed file size for uploading in MB",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 64.0);
  return atexit(func: dynamic_atexit_destructor_for__net_maxfilesize__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C7E0
// Name: _dynamic_initializer_for__net_compresspackets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_compresspackets__()
{
  ConVar::ConVar(
    this: &net_compresspackets,
    pName: "net_compresspackets",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Use lz compression on game packets.");
  return atexit(func: dynamic_atexit_destructor_for__net_compresspackets__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C810
// Name: _dynamic_initializer_for__net_compresspackets_minsize__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_compresspackets_minsize__()
{
  ConVar::ConVar(
    this: &net_compresspackets_minsize,
    pName: "net_compresspackets_minsize",
    pDefaultValue: "1000",
    flags: 2,
    pHelpString: "Don't bother compressing packets below this size.");
  return atexit(func: dynamic_atexit_destructor_for__net_compresspackets_minsize__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C840
// Name: _dynamic_initializer_for__net_maxcleartime__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_maxcleartime__()
{
  ConVar::ConVar(
    this: &net_maxcleartime,
    pName: "net_maxcleartime",
    pDefaultValue: "4.0",
    flags: 0,
    pHelpString: "Max # of seconds we can wait for next packets to be sent based on rate setting (0 == no limit).");
  return atexit(func: dynamic_atexit_destructor_for__net_maxcleartime__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C870
// Name: _dynamic_initializer_for__net_dumptest__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_dumptest__()
{
  ConVar::ConVar(this: &net_dumptest, pName: "net_dumptest", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__net_dumptest__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C8A0
// Name: _dynamic_initializer_for__net_paranoid__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_paranoid__()
{
  ConVar::ConVar(this: &net_paranoid, pName: "net_paranoid", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__net_paranoid__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C8E0
// Name: _dynamic_initializer_for__net_minroutable__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_minroutable__()
{
  ConVar::ConVar(
    this: &net_minroutable,
    pName: "net_minroutable",
    pDefaultValue: "16",
    flags: 2,
    pHelpString: "Forces larger payloads.");
  return atexit(func: dynamic_atexit_destructor_for__net_minroutable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C910
// Name: _dynamic_initializer_for__net_steamcnx_debug__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_steamcnx_debug__()
{
  ConVar::ConVar(
    this: &net_steamcnx_debug,
    pName: "net_steamcnx_debug",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show debug spew for steam based connections, 2 shows all network traffic for steam sockets.");
  return atexit(func: dynamic_atexit_destructor_for__net_steamcnx_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C940
// Name: _dynamic_initializer_for__net_steamcnx_enabled__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_steamcnx_enabled__()
{
  ConVar::ConVar(
    this: &net_steamcnx_enabled,
    pName: "net_steamcnx_enabled",
    pDefaultValue: "1",
    flags: 0x80000,
    pHelpString: "Use steam connections on listen server as a fallback, 2 forces use of steam connections instead of raw UDP.");
  return atexit(func: dynamic_atexit_destructor_for__net_steamcnx_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C970
// Name: _dynamic_initializer_for__net_steamcnx_allowrelay__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_steamcnx_allowrelay__()
{
  ConVar::ConVar(
    this: &net_steamcnx_allowrelay,
    pName: "net_steamcnx_allowrelay",
    pDefaultValue: "1",
    flags: 524416,
    pHelpString: "Allow steam connections to attempt to use relay servers as fallback (best if specified on command line:  +net_steamc"
    "nx_allowrelay 1)");
  return atexit(func: dynamic_atexit_destructor_for__net_steamcnx_allowrelay__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C9C0
// Name: _dynamic_initializer_for__net_steamcnx_status_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_steamcnx_status_command__()
{
  ConCommand::ConCommand(
    this: &net_steamcnx_status_command,
    pName: "net_steamcnx_status",
    callback: net_steamcnx_status,
    pHelpString: "Print status of steam connection sockets.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__net_steamcnx_status_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CA20
// Name: _dynamic_initializer_for__net_showsplits__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showsplits__()
{
  ConVar::ConVar(
    this: &net_showsplits,
    pName: "net_showsplits",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Show info about packet splits");
  return atexit(func: dynamic_atexit_destructor_for__net_showsplits__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CA50
// Name: _dynamic_initializer_for__net_splitrate__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_splitrate__()
{
  ConVar::ConVar(
    this: &net_splitrate,
    pName: "net_splitrate",
    pDefaultValue: "1",
    flags: 0x80000,
    pHelpString: "Number of fragments for a splitpacket that can be sent per frame");
  return atexit(func: dynamic_atexit_destructor_for__net_splitrate__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CB10
// Name: _dynamic_initializer_for__net_public_adr__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_public_adr__()
{
  ConVar::ConVar(
    this: &net_public_adr,
    pName: "net_public_adr",
    pDefaultValue: defaultValue,
    flags: 0x80000,
    pHelpString: "For servers behind NAT/DHCP meant to be exposed to the public internet, this is the public facing ip address string: (\"x.x.x.x\" )");
  return atexit(func: dynamic_atexit_destructor_for__net_public_adr__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CC60
// Name: _dynamic_initializer_for__net_compressvoice__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_compressvoice__()
{
  ConVar::ConVar(
    this: &net_compressvoice,
    pName: "net_compressvoice",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Attempt to compress out of band voice payloads (360 only).");
  return atexit(func: dynamic_atexit_destructor_for__net_compressvoice__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CC90
// Name: _dynamic_initializer_for__net_usesocketsforloopback__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_usesocketsforloopback__()
{
  ConVar::ConVar(
    this: &net_usesocketsforloopback,
    pName: "net_usesocketsforloopback",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Use network sockets layer even for listen server local player's packets (multiplayer only).");
  return atexit(func: dynamic_atexit_destructor_for__net_usesocketsforloopback__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CD90
// Name: _dynamic_initializer_for__net_maxroutable__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_maxroutable__()
{
  ConVar::ConVar(
    this: &net_maxroutable,
    pName: "net_maxroutable",
    pDefaultValue: "1200",
    flags: 640,
    pHelpString: "Requested max packet size before packets are 'split'.",
    bMin: true,
    fMin: 576.0,
    bMax: true,
    fMax: 1200.0);
  return atexit(func: dynamic_atexit_destructor_for__net_maxroutable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CDE0
// Name: _dynamic_initializer_for__net_local_adr__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void dynamic_initializer_for__net_local_adr__()
{
  netadr_s::SetIP(this: &net_local_adr, unIP: 0);
  netadr_s::SetPort(this: &net_local_adr, newport: 0);
  netadr_s::SetType(this: &net_local_adr, newtype: NA_IP);
}

//------------------------------------------------------------------------------
// Address: 0x1031CE10
// Name: _dynamic_initializer_for__net_sockets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_sockets__()
{
  return atexit(func: dynamic_atexit_destructor_for__net_sockets__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CE20
// Name: _dynamic_initializer_for__net_packets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_packets__()
{
  return atexit(func: dynamic_atexit_destructor_for__net_packets__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CEA0
// Name: _dynamic_initializer_for__net_splitpackets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_splitpackets__()
{
  return atexit(func: dynamic_atexit_destructor_for__net_splitpackets__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CEF0
// Name: _dynamic_initializer_for__net_splitpacket_maxrate__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_splitpacket_maxrate__()
{
  ConVar::ConVar(
    this: &net_splitpacket_maxrate,
    pName: "net_splitpacket_maxrate",
    pDefaultValue: "15000",
    flags: 0x80000,
    pHelpString: "Max bytes per second when queueing splitpacket chunks",
    bMin: true,
    fMin: 1000.0,
    bMax: true,
    fMax: 30000.0);
  return atexit(func: dynamic_atexit_destructor_for__net_splitpacket_maxrate__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CF50
// Name: _dynamic_initializer_for__net_channels_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_channels_command__()
{
  ConCommand::ConCommand(
    this: &net_channels_command,
    pName: "net_channels",
    callback: net_channels,
    pHelpString: "Shows net channel info",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__net_channels_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CF80
// Name: _dynamic_initializer_for__net_start_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_start_command__()
{
  ConCommand::ConCommand(
    this: &net_start_command,
    pName: "net_start",
    callback: net_start,
    pHelpString: "Inits multiplayer network sockets",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__net_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CFB0
// Name: _dynamic_initializer_for__net_status_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_status_command__()
{
  ConCommand::ConCommand(
    this: &net_status_command,
    pName: "net_status",
    callback: net_status,
    pHelpString: "Shows current network status",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__net_status_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CFE0
// Name: _dynamic_initializer_for__net_queued_packet_thread__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_queued_packet_thread__()
{
  ConVar::ConVar(
    this: &net_queued_packet_thread,
    pName: "net_queued_packet_thread",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use a high priority thread to send queued packets out instead of sending them each frame.");
  return atexit(func: dynamic_atexit_destructor_for__net_queued_packet_thread__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D010
// Name: _dynamic_initializer_for__net_queue_trace__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_queue_trace__()
{
  ConVar::ConVar(this: &net_queue_trace, pName: "net_queue_trace", pDefaultValue: "0", flags: 0x2000000);
  return atexit(func: dynamic_atexit_destructor_for__net_queue_trace__);
}

//------------------------------------------------------------------------------
// Address: 0x10322750
// Name: _dynamic_atexit_destructor_for__net_earliertempents__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_earliertempents__()
{
  ConVar::~ConVar(this: &net_earliertempents);
}

//------------------------------------------------------------------------------
// Address: 0x10324040
// Name: _dynamic_atexit_destructor_for__net_megasnapshot__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_megasnapshot__()
{
  ConVar::~ConVar(this: &net_megasnapshot);
}

//------------------------------------------------------------------------------
// Address: 0x10324110
// Name: _dynamic_atexit_destructor_for__net_showreliablesounds__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showreliablesounds__()
{
  ConVar::~ConVar(this: &net_showreliablesounds);
}

//------------------------------------------------------------------------------
// Address: 0x103251A0
// Name: _dynamic_atexit_destructor_for__net_showevents__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showevents__()
{
  ConVar::~ConVar(this: &net_showevents);
}

//------------------------------------------------------------------------------
// Address: 0x103251B0
// Name: _dynamic_atexit_destructor_for__net_showeventlisteners__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showeventlisteners__()
{
  ConVar::~ConVar(this: &net_showeventlisteners);
}

//------------------------------------------------------------------------------
// Address: 0x103251D0
// Name: _dynamic_atexit_destructor_for__net_dumpeventstats_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_dumpeventstats_command__()
{
  ConCommand::~ConCommand(this: &net_dumpeventstats_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326030
// Name: _dynamic_atexit_destructor_for__net_showudp__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showudp__()
{
  ConVar::~ConVar(this: &net_showudp);
}

//------------------------------------------------------------------------------
// Address: 0x10326040
// Name: _dynamic_atexit_destructor_for__net_showudp_oob__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showudp_oob__()
{
  ConVar::~ConVar(this: &net_showudp_oob);
}

//------------------------------------------------------------------------------
// Address: 0x10326050
// Name: _dynamic_atexit_destructor_for__net_showudp_remoteonly__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showudp_remoteonly__()
{
  ConVar::~ConVar(this: &net_showudp_remoteonly);
}

//------------------------------------------------------------------------------
// Address: 0x10326060
// Name: _dynamic_atexit_destructor_for__net_showtcp__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showtcp__()
{
  ConVar::~ConVar(this: &net_showtcp);
}

//------------------------------------------------------------------------------
// Address: 0x10326070
// Name: _dynamic_atexit_destructor_for__net_blocksize__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_blocksize__()
{
  ConVar::~ConVar(this: &net_blocksize);
}

//------------------------------------------------------------------------------
// Address: 0x10326080
// Name: _dynamic_atexit_destructor_for__net_showmsg__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showmsg__()
{
  ConVar::~ConVar(this: &net_showmsg);
}

//------------------------------------------------------------------------------
// Address: 0x10326090
// Name: _dynamic_atexit_destructor_for__net_showfragments__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showfragments__()
{
  ConVar::~ConVar(this: &net_showfragments);
}

//------------------------------------------------------------------------------
// Address: 0x103260A0
// Name: _dynamic_atexit_destructor_for__net_showpeaks__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showpeaks__()
{
  ConVar::~ConVar(this: &net_showpeaks);
}

//------------------------------------------------------------------------------
// Address: 0x103260B0
// Name: _dynamic_atexit_destructor_for__net_blockmsg__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_blockmsg__()
{
  ConVar::~ConVar(this: &net_blockmsg);
}

//------------------------------------------------------------------------------
// Address: 0x103260C0
// Name: _dynamic_atexit_destructor_for__net_showdrop__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showdrop__()
{
  ConVar::~ConVar(this: &net_showdrop);
}

//------------------------------------------------------------------------------
// Address: 0x103260D0
// Name: _dynamic_atexit_destructor_for__net_drawslider__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_drawslider__()
{
  ConVar::~ConVar(this: &net_drawslider);
}

//------------------------------------------------------------------------------
// Address: 0x103260E0
// Name: _dynamic_atexit_destructor_for__net_chokeloopback__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_chokeloopback__()
{
  ConVar::~ConVar(this: &net_chokeloopback);
}

//------------------------------------------------------------------------------
// Address: 0x103260F0
// Name: _dynamic_atexit_destructor_for__net_maxfilesize__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_maxfilesize__()
{
  ConVar::~ConVar(this: &net_maxfilesize);
}

//------------------------------------------------------------------------------
// Address: 0x10326100
// Name: _dynamic_atexit_destructor_for__net_compresspackets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_compresspackets__()
{
  ConVar::~ConVar(this: &net_compresspackets);
}

//------------------------------------------------------------------------------
// Address: 0x10326110
// Name: _dynamic_atexit_destructor_for__net_compresspackets_minsize__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_compresspackets_minsize__()
{
  ConVar::~ConVar(this: &net_compresspackets_minsize);
}

//------------------------------------------------------------------------------
// Address: 0x10326120
// Name: _dynamic_atexit_destructor_for__net_maxcleartime__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_maxcleartime__()
{
  ConVar::~ConVar(this: &net_maxcleartime);
}

//------------------------------------------------------------------------------
// Address: 0x10326130
// Name: _dynamic_atexit_destructor_for__net_dumptest__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_dumptest__()
{
  ConVar::~ConVar(this: &net_dumptest);
}

//------------------------------------------------------------------------------
// Address: 0x10326140
// Name: _dynamic_atexit_destructor_for__net_paranoid__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_paranoid__()
{
  ConVar::~ConVar(this: &net_paranoid);
}

//------------------------------------------------------------------------------
// Address: 0x10326150
// Name: _dynamic_atexit_destructor_for__net_minroutable__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_minroutable__()
{
  ConVar::~ConVar(this: &net_minroutable);
}

//------------------------------------------------------------------------------
// Address: 0x10326180
// Name: _dynamic_atexit_destructor_for__net_steamcnx_debug__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_steamcnx_debug__()
{
  ConVar::~ConVar(this: &net_steamcnx_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10326190
// Name: _dynamic_atexit_destructor_for__net_steamcnx_enabled__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_steamcnx_enabled__()
{
  ConVar::~ConVar(this: &net_steamcnx_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x103261A0
// Name: _dynamic_atexit_destructor_for__net_steamcnx_allowrelay__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_steamcnx_allowrelay__()
{
  ConVar::~ConVar(this: &net_steamcnx_allowrelay);
}

//------------------------------------------------------------------------------
// Address: 0x103261B0
// Name: _dynamic_atexit_destructor_for__net_steamcnx_status_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_steamcnx_status_command__()
{
  ConCommand::~ConCommand(this: &net_steamcnx_status_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326240
// Name: _dynamic_atexit_destructor_for__net_showsplits__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showsplits__()
{
  ConVar::~ConVar(this: &net_showsplits);
}

//------------------------------------------------------------------------------
// Address: 0x10326250
// Name: _dynamic_atexit_destructor_for__net_splitrate__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_splitrate__()
{
  ConVar::~ConVar(this: &net_splitrate);
}

//------------------------------------------------------------------------------
// Address: 0x10326290
// Name: _dynamic_atexit_destructor_for__net_public_adr__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_public_adr__()
{
  ConVar::~ConVar(this: &net_public_adr);
}

//------------------------------------------------------------------------------
// Address: 0x10326300
// Name: _dynamic_atexit_destructor_for__net_compressvoice__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_compressvoice__()
{
  ConVar::~ConVar(this: &net_compressvoice);
}

//------------------------------------------------------------------------------
// Address: 0x10326310
// Name: _dynamic_atexit_destructor_for__net_usesocketsforloopback__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_usesocketsforloopback__()
{
  ConVar::~ConVar(this: &net_usesocketsforloopback);
}

//------------------------------------------------------------------------------
// Address: 0x10326360
// Name: _dynamic_atexit_destructor_for__net_maxroutable__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_maxroutable__()
{
  ConVar::~ConVar(this: &net_maxroutable);
}

//------------------------------------------------------------------------------
// Address: 0x10326370
// Name: _dynamic_atexit_destructor_for__net_splitpacket_maxrate__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_splitpacket_maxrate__()
{
  ConVar::~ConVar(this: &net_splitpacket_maxrate);
}

//------------------------------------------------------------------------------
// Address: 0x10326380
// Name: _dynamic_atexit_destructor_for__net_channels_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_channels_command__()
{
  ConCommand::~ConCommand(this: &net_channels_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326390
// Name: _dynamic_atexit_destructor_for__net_start_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_start_command__()
{
  ConCommand::~ConCommand(this: &net_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x103263A0
// Name: _dynamic_atexit_destructor_for__net_status_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_status_command__()
{
  ConCommand::~ConCommand(this: &net_status_command);
}

//------------------------------------------------------------------------------
// Address: 0x103263C0
// Name: _dynamic_atexit_destructor_for__net_sockets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_sockets__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&net_sockets);
}

//------------------------------------------------------------------------------
// Address: 0x103263D0
// Name: _dynamic_atexit_destructor_for__net_packets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_packets__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&net_packets);
}

//------------------------------------------------------------------------------
// Address: 0x10326440
// Name: _dynamic_atexit_destructor_for__net_splitpackets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_splitpackets__()
{
  CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::~CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>(this: (CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,int> > *)&net_splitpackets);
}

//------------------------------------------------------------------------------
// Address: 0x103264B0
// Name: _dynamic_atexit_destructor_for__net_queued_packet_thread__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_queued_packet_thread__()
{
  ConVar::~ConVar(this: &net_queued_packet_thread);
}

//------------------------------------------------------------------------------
// Address: 0x103264C0
// Name: _dynamic_atexit_destructor_for__net_queue_trace__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_queue_trace__()
{
  ConVar::~ConVar(this: &net_queue_trace);
}

//------------------------------------------------------------------------------
// Address: 0x103135A0
// Name: _dynamic_initializer_for__g_SoundMessages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SoundMessages__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SoundMessages__);
}

//------------------------------------------------------------------------------
// Address: 0x103135B0
// Name: _dynamic_initializer_for__retry_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__retry_command__()
{
  ConCommand::ConCommand(
    this: &retry_command,
    pName: "retry",
    callback: retry,
    pHelpString: "Retry connection to last server.",
    flags: 1342308352,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__retry_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319DB0
// Name: _dynamic_initializer_for____g_CreateCGameEventManagerIGameEventManager2_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCGameEventManagerIGameEventManager2_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCGameEventManagerIGameEventManager2_reg,
           fn: (void *(__cdecl *)())_CreateCGameEventManagerIGameEventManager2_interface,
           pName: "GAMEEVENTSMANAGER002");
}

//------------------------------------------------------------------------------
// Address: 0x10319DD0
// Name: _dynamic_initializer_for__display_game_events__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__display_game_events__()
{
  ConVar::ConVar(this: &display_game_events, pName: "display_game_events", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__display_game_events__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C8D0
// Name: _dynamic_initializer_for__g_NetParanoid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NetParanoid__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_NetParanoid__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C9A0
// Name: _dynamic_initializer_for__g_SteamSocketMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SteamSocketMgr__()
{
  CSteamSocketMgr::CSteamSocketMgr(this: &g_SteamSocketMgr);
  return atexit(func: dynamic_atexit_destructor_for__g_SteamSocketMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C9F0
// Name: _dynamic_initializer_for__g_NetSupport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NetSupport__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_NetSupport__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CA00
// Name: _dynamic_initializer_for____g_CreateCNetSupportImplINetSupport_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCNetSupportImplINetSupport_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCNetSupportImplINetSupport_reg,
           fn: (void *(__cdecl *)())_CreateCNetSupportImplINetSupport_interface,
           pName: "INETSUPPORT_002");
}

//------------------------------------------------------------------------------
// Address: 0x1031CA80
// Name: _dynamic_initializer_for__ipname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ipname__()
{
  ConVar::ConVar(
    this: &ipname,
    pName: "ip",
    pDefaultValue: "localhost",
    flags: 0x80000,
    pHelpString: "Overrides IP for multihomed hosts");
  return atexit(func: dynamic_atexit_destructor_for__ipname__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CAB0
// Name: _dynamic_initializer_for__hostport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hostport__()
{
  ConVar::ConVar(
    this: &hostport,
    pName: "hostport",
    pDefaultValue: "27015",
    flags: 0x80000,
    pHelpString: "Host game server port");
  return atexit(func: dynamic_atexit_destructor_for__hostport__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CAE0
// Name: _dynamic_initializer_for__hostip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hostip__()
{
  ConVar::ConVar(
    this: &hostip,
    pName: "hostip",
    pDefaultValue: defaultValue,
    flags: 0x80000,
    pHelpString: "Host game server ip");
  return atexit(func: dynamic_atexit_destructor_for__hostip__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CB40
// Name: _dynamic_initializer_for__clientport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__clientport__()
{
  ConVar::ConVar(
    this: &clientport,
    pName: "clientport",
    pDefaultValue: "27005",
    flags: 0x80000,
    pHelpString: "Host game client port");
  return atexit(func: dynamic_atexit_destructor_for__clientport__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CB70
// Name: _dynamic_initializer_for__hltvport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hltvport__()
{
  ConVar::ConVar(
    this: &hltvport,
    pName: "tv_port",
    pDefaultValue: "27020",
    flags: 0x80000,
    pHelpString: "Host SourceTV port");
  return atexit(func: dynamic_atexit_destructor_for__hltvport__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CBA0
// Name: _dynamic_initializer_for__fakelag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fakelag__()
{
  ConVar::ConVar(
    this: &fakelag,
    pName: "net_fakelag",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Lag all incoming network data (including loopback) by this many milliseconds.");
  return atexit(func: dynamic_atexit_destructor_for__fakelag__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CBD0
// Name: _dynamic_initializer_for__fakeloss__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fakeloss__()
{
  ConVar::ConVar(
    this: &fakeloss,
    pName: "net_fakeloss",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Simulate packet loss as a percentage (negative means drop 1/n packets)");
  return atexit(func: dynamic_atexit_destructor_for__fakeloss__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CC00
// Name: _dynamic_initializer_for__droppackets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__droppackets__()
{
  ConVar::ConVar(
    this: &droppackets,
    pName: "net_droppackets",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Drops next n packets on client");
  return atexit(func: dynamic_atexit_destructor_for__droppackets__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CC30
// Name: _dynamic_initializer_for__fakejitter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fakejitter__()
{
  ConVar::ConVar(
    this: &fakejitter,
    pName: "net_fakejitter",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Jitter fakelag packet time");
  return atexit(func: dynamic_atexit_destructor_for__fakejitter__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CEB0
// Name: _dynamic_initializer_for__g_NetScratchBuffers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NetScratchBuffers__()
{
  if ( ((unsigned __int8)&g_NetScratchBuffers & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_NetScratchBuffers = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_NetScratchBuffers__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CEE0
// Name: _dynamic_initializer_for__g_SendQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SendQueue__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SendQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CF40
// Name: _dynamic_initializer_for__g_BindAddressHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BindAddressHelper__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BindAddressHelper__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D040
// Name: _dynamic_initializer_for__g_QueuedPacketSender__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QueuedPacketSender__()
{
  CQueuedPacketSender::CQueuedPacketSender(this: &g_QueuedPacketSender);
  return atexit(func: dynamic_atexit_destructor_for__g_QueuedPacketSender__);
}

//------------------------------------------------------------------------------
// Address: 0x10322760
// Name: _dynamic_atexit_destructor_for__retry_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__retry_command__()
{
  ConCommand::~ConCommand(this: &retry_command);
}

//------------------------------------------------------------------------------
// Address: 0x103251C0
// Name: _dynamic_atexit_destructor_for__display_game_events__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__display_game_events__()
{
  ConVar::~ConVar(this: &display_game_events);
}

//------------------------------------------------------------------------------
// Address: 0x10326160
// Name: _dynamic_atexit_destructor_for__g_NetParanoid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_NetParanoid__()
{
  free(pMem: g_NetParanoid.m_pPacketMessages);
  free(pMem: g_NetParanoid.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x103261C0
// Name: _dynamic_atexit_destructor_for__g_SteamSocketMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SteamSocketMgr__()
{
  g_SteamSocketMgr.__vftable = (CSteamSocketMgr_vtbl *)&CSteamSocketMgr::`vftable';
  CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_SteamSocketMgr.m_mapSocketToESocketType.m_Tree);
  CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_SteamSocketMgr.m_mapAdrToSteamSocket.m_Tree);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_SteamSocketMgr.m_vecRemoteSockets);
  g_SteamSocketMgr.m_callbackP2PSessionConnectFail.__vftable = (CCallback<CSteamSocketMgr,P2PSessionConnectFail_t,0>_vtbl *)&CCallback<CSteamSocketMgr,P2PSessionConnectFail_t,0>::`vftable';
  if ( (g_SteamSocketMgr.m_callbackP2PSessionConnectFail.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &g_SteamSocketMgr.m_callbackP2PSessionConnectFail);
  g_SteamSocketMgr.m_callbackP2PSessionRequest.__vftable = (CCallback<CSteamSocketMgr,P2PSessionRequest_t,0>_vtbl *)&CCallback<CSteamSocketMgr,P2PSessionRequest_t,0>::`vftable';
  if ( (g_SteamSocketMgr.m_callbackP2PSessionRequest.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &g_SteamSocketMgr.m_callbackP2PSessionRequest);
}

//------------------------------------------------------------------------------
// Address: 0x10326230
// Name: _dynamic_atexit_destructor_for__g_NetSupport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_NetSupport__()
{
  g_NetSupport.__vftable = (CNetSupportImpl_vtbl *)&CNetSupportImpl::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10326260
// Name: _dynamic_atexit_destructor_for__ipname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ipname__()
{
  ConVar::~ConVar(this: &ipname);
}

//------------------------------------------------------------------------------
// Address: 0x10326270
// Name: _dynamic_atexit_destructor_for__hostport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hostport__()
{
  ConVar::~ConVar(this: &hostport);
}

//------------------------------------------------------------------------------
// Address: 0x10326280
// Name: _dynamic_atexit_destructor_for__hostip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hostip__()
{
  ConVar::~ConVar(this: &hostip);
}

//------------------------------------------------------------------------------
// Address: 0x103262A0
// Name: _dynamic_atexit_destructor_for__clientport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__clientport__()
{
  ConVar::~ConVar(this: &clientport);
}

//------------------------------------------------------------------------------
// Address: 0x103262B0
// Name: _dynamic_atexit_destructor_for__hltvport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hltvport__()
{
  ConVar::~ConVar(this: &hltvport);
}

//------------------------------------------------------------------------------
// Address: 0x103262C0
// Name: _dynamic_atexit_destructor_for__fakelag__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fakelag__()
{
  ConVar::~ConVar(this: &fakelag);
}

//------------------------------------------------------------------------------
// Address: 0x103262D0
// Name: _dynamic_atexit_destructor_for__fakeloss__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fakeloss__()
{
  ConVar::~ConVar(this: &fakeloss);
}

//------------------------------------------------------------------------------
// Address: 0x103262E0
// Name: _dynamic_atexit_destructor_for__droppackets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__droppackets__()
{
  ConVar::~ConVar(this: &droppackets);
}

//------------------------------------------------------------------------------
// Address: 0x103262F0
// Name: _dynamic_atexit_destructor_for__fakejitter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fakejitter__()
{
  ConVar::~ConVar(this: &fakejitter);
}

//------------------------------------------------------------------------------
// Address: 0x103263B0
// Name: _dynamic_atexit_destructor_for__g_NetScratchBuffers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_NetScratchBuffers__()
{
  CTSPool<net_scratchbuffer_t>::~CTSPool<net_scratchbuffer_t>(this: &g_NetScratchBuffers);
}

//------------------------------------------------------------------------------
// Address: 0x10326450
// Name: _dynamic_atexit_destructor_for__g_SendQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SendQueue__()
{
  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::RemoveAll(this: &g_SendQueue.m_SendQueue);
  if ( g_SendQueue.m_SendQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SendQueue.m_SendQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SendQueue.m_SendQueue.m_Memory.m_pMemory);
      g_SendQueue.m_SendQueue.m_Memory.m_pMemory = nullptr;
    }
    g_SendQueue.m_SendQueue.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103264A0
// Name: _dynamic_atexit_destructor_for__g_BindAddressHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BindAddressHelper__()
{
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&g_BindAddressHelper.m_CachedAddresses);
}

//------------------------------------------------------------------------------
// Address: 0x103264D0
// Name: _dynamic_atexit_destructor_for__g_QueuedPacketSender__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QueuedPacketSender__()
{
  g_QueuedPacketSender.CThread::__vftable = (CQueuedPacketSender_vtbl *)&CQueuedPacketSender::`vftable'{for `CThread'};
  g_QueuedPacketSender.IQueuedPacketSender::__vftable = (IQueuedPacketSender_vtbl *)&CQueuedPacketSender::`vftable'{for `IQueuedPacketSender'};
  CQueuedPacketSender::Shutdown(this: (CQueuedPacketSender *)&g_QueuedPacketSender.IQueuedPacketSender);
  CThreadSyncObject::~CThreadSyncObject(this: &g_QueuedPacketSender.m_hThreadEvent);
  CThreadMutex::~CThreadMutex(this: &g_QueuedPacketSender.m_QueuedPacketsCS);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_QueuedPacketSender.m_QueuedPackets);
  CThread::~CThread(this: &g_QueuedPacketSender);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10010BE0
// Name: public: CTSQueue<struct StartSoundParams_t,0,1>::Node_t::Node_t(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<StartSoundParams_t,0,1>::Node_t *__thiscall CTSQueue<StartSoundParams_t,0,1>::Node_t::Node_t(
        CTSQueue<StartSoundParams_t,0,1>::Node_t *this)
{
  CTSQueue<StartSoundParams_t,0,1>::Node_t *result; // eax
  char v2; // cl

  result = this;
  this->elem.userdata = 0;
  this->elem.soundsource = 0;
  this->elem.entchannel = 0;
  this->elem.pSfx = nullptr;
  this->elem.flags = 0;
  this->elem.initialStreamPosition = 0;
  this->elem.skipInitialSamples = 0;
  this->elem.m_pSoundEntryName = nullptr;
  this->elem.m_pOperatorsKV = nullptr;
  v2 = *((_BYTE *)&this->elem + 96);
  result->elem.fvol = 1.0;
  result->elem.soundlevel = SNDLVL_NORM;
  result->elem.pitch = 100;
  result->elem.delay = 0.0;
  result->elem.opStackElapsedTime = 0.0;
  result->elem.opStackElapsedStopTime = 0.0;
  result->elem.speakerentity = -1;
  result->elem.m_nQueuedGUID = -1;
  result->elem.m_nSoundScriptHandle = -1;
  *((_BYTE *)&result->elem + 96) = v2 & 0xC0 | 2;
  result->elem.origin.x = 0.0;
  result->elem.origin.y = 0.0;
  result->elem.origin.z = 0.0;
  result->elem.direction.x = 0.0;
  result->elem.direction.y = 0.0;
  result->elem.direction.z = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100138F0
// Name: public: CTSQueue<struct StartSoundParams_t,0,1>::CTSQueue<struct StartSoundParams_t,0,1>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<StartSoundParams_t,0,1> *__thiscall CTSQueue<StartSoundParams_t,0,1>::CTSQueue<StartSoundParams_t,0,1>(
        CTSQueue<StartSoundParams_t,0,1> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v3; // eax
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v4; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  p_m_FreeNodes->m_Head.value32.DepthAndSequence = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&this->m_Count.m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v3 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)MemAlloc_Alloc(nSize: 0x68u);
  if ( v3 != nullptr )
  {
    v4 = CTSQueue<StartSoundParams_t,0,1>::Node_t::Node_t(this: v3);
    this->m_Tail.value.pNode = v4;
    this->m_Head.value.pNode = v4;
    v4->pNext = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)this;
  }
  else
  {
    this->m_Tail.value.pNode = nullptr;
    this->m_Head.value.pNode = nullptr;
    MEMORY[0] = this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013990
// Name: public: struct CTSQueue<struct StartSoundParams_t,0,1>::Node_t __near * CTSQueue<struct StartSoundParams_t,0,1>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<StartSoundParams_t,0,1>::Node_t *__usercall CTSQueue<StartSoundParams_t,0,1>::Pop@<eax>(
        CTSQueue<StartSoundParams_t,0,1> *this@<ecx>,
        CTSQueue<StartSoundParams_t,0,1>::Node_t *volatile *a2@<ebp>)
{
  CTSQueue<StartSoundParams_t,0,1>::Node_t *pNode; // eax
  CTSQueue<StartSoundParams_t,0,1>::Node_t *pNext; // esi
  float opStackElapsedStopTime; // esi
  _BYTE v7[12]; // [esp-Ch] [ebp-8Ch] BYREF
  StartSoundParams_t elem; // [esp+0h] [ebp-80h] BYREF
  CTSQueue<StartSoundParams_t,0,1> *v9; // [esp+64h] [ebp-1Ch]
  CTSQueue<StartSoundParams_t,0,1>::NodeLink_t head; // [esp+68h] [ebp-18h]
  CTSQueue<StartSoundParams_t,0,1>::NodeLink_t *pHead; // [esp+70h] [ebp-10h]
  CTSQueue<StartSoundParams_t,0,1>::Node_t *volatile *pTailNode; // [esp+74h] [ebp-Ch]
  volatile int *pHeadSequence; // [esp+78h] [ebp-8h]
  volatile int *retaddr; // [esp+80h] [ebp+0h]

  pTailNode = a2;
  pHeadSequence = retaddr;
  v9 = this;
  pHead = &this->m_Tail;
  head.value.sequence = (int)&this->m_Head.value.sequence;
  head.value.pNode = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)&this->m_Tail;
  elem.direction.x = 1.0;
  memset(v7, 0, sizeof(v7));
  memset(&elem, 0, 28);
  LODWORD(elem.direction.y) = 75;
  elem.direction.z = 0.0;
  LODWORD(elem.fvol) = 100;
  elem.soundlevel = SNDLVL_NONE;
  elem.flags = -1;
  elem.pitch = 0;
  elem.delay = 0.0;
  elem.speakerentity = -1;
  LOWORD(elem.initialStreamPosition) = -1;
  memset(&elem.skipInitialSamples, 0, 16);
  LOBYTE(elem.m_pOperatorsKV) = (int)elem.m_pOperatorsKV & 0xC0 | 2;
  while ( 1 )
  {
    while ( 1 )
    {
      do
      {
        do
        {
          pNode = this->m_Head.value.pNode;
          *((_DWORD *)&elem + 24) = *(_DWORD *)head.value.sequence;
          LODWORD(elem.opStackElapsedStopTime) = pNode;
          pNext = pNode->pNext;
        }
        while ( pNode->pNext == nullptr );
      }
      while ( *((_DWORD *)&elem + 24) != *(_DWORD *)head.value.sequence );
      if ( (CTSQueue<StartSoundParams_t,0,1>::Node_t *)LODWORD(elem.opStackElapsedStopTime) == head.value.pNode->pNext )
        break;
      if ( pNext != (CTSQueue<StartSoundParams_t,0,1>::Node_t *)this )
      {
        StartSoundParams_t::operator=(this: (StartSoundParams_t *)v7, __that: &pNext->elem);
        if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                a1: v9,
                                a2: pNext,
                                a3: *((_DWORD *)&elem + 24) + 1,
                                a4: LODWORD(elem.opStackElapsedStopTime),
                                a5: *((_DWORD *)&elem + 24)) != 0 )
        {
          _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
          opStackElapsedStopTime = elem.opStackElapsedStopTime;
          StartSoundParams_t::operator=(
            this: (StartSoundParams_t *)(LODWORD(elem.opStackElapsedStopTime) + 4),
            __that: (const StartSoundParams_t *)v7);
          return (CTSQueue<StartSoundParams_t,0,1>::Node_t *)LODWORD(opStackElapsedStopTime);
        }
      }
    }
    if ( pNext == (CTSQueue<StartSoundParams_t,0,1>::Node_t *)this )
      break;
    _ThreadInterlockedAssignIf64(
      a1: &this->m_Tail,
      a2: pNext,
      a3: pHead->value.sequence + 1,
      a4: LODWORD(elem.opStackElapsedStopTime),
      a5: pHead->value.sequence);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100155E0
// Name: public: void CTSQueue<struct StartSoundParams_t,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<StartSoundParams_t,0,1>::Purge(CTSQueue<StartSoundParams_t,0,1> *this)
{
  CTSQueue<StartSoundParams_t,0,1>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  CTSQueue<StartSoundParams_t,0,1>::Node_t *savedregs; // [esp+10h] [ebp+0h] BYREF

  for ( i = CTSQueue<StartSoundParams_t,0,1>::Pop(this, a2: &savedregs);
        i != nullptr;
        i = CTSQueue<StartSoundParams_t,0,1>::Pop(this, a2: &savedregs) )
  {
    free(pMem: i);
  }
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: p_m_FreeNodes,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
      if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    free(pMem: Next);
  }
LABEL_7:
  this->m_Head.value.sequence = 0;
  this->m_Tail.value.sequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015670
// Name: public: void CTSQueue<struct StartSoundParams_t,0,1>::PushItem(struct StartSoundParams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<StartSoundParams_t,0,1>::PushItem(
        CTSQueue<StartSoundParams_t,0,1> *this,
        const StartSoundParams_t *init)
{
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v3; // esi
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v4; // eax

  v3 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_FreeNodes);
  if ( v3 != nullptr )
  {
    StartSoundParams_t::operator=(this: &v3->elem, __that: init);
    CTSQueue<CFunctor *,0,1>::Push(this, pNode: v3);
  }
  else
  {
    v4 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)MemAlloc_Alloc(nSize: 0x68u);
    if ( v4 != nullptr )
    {
      qmemcpy(&v4->elem, init, sizeof(v4->elem));
      CTSQueue<CFunctor *,0,1>::Push(this, pNode: v4);
    }
    else
    {
      CTSQueue<CFunctor *,0,1>::Push(this, pNode: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F950
// Name: public: struct CTSQueue<struct loopback_t __near *,0,1>::Node_t __near * CTSQueue<struct loopback_t __near *,0,1>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<int,0,1>::Node_t *__thiscall CTSQueue<loopback_t *,0,1>::Pop(CTSQueue<int,0,1> *this)
{
  CTSQueue<int,0,1> *v1; // esi
  CTSQueue<int,0,1> *pNext; // eax
  int sequence; // edi
  CTSQueue<int,0,1>::Node_t *pNode; // [esp-Ch] [ebp-2Ch]
  CTSQueue<int,0,1>::NodeLink_t *head_4; // [esp+4h] [ebp-1Ch]
  int *pHead; // [esp+Ch] [ebp-14h]
  CTSQueue<int,0,1>::NodeLink_t *pTailNode; // [esp+10h] [ebp-10h]

  v1 = this;
  pTailNode = &this->m_Tail;
  pHead = &this->m_Head.value.sequence;
  head_4 = &this->m_Tail;
  while ( 1 )
  {
    do
    {
      while ( 1 )
      {
        do
        {
          pNode = v1->m_Head.value.pNode;
          pNext = (CTSQueue<int,0,1> *)v1->m_Head.value.pNode->pNext;
        }
        while ( pNext == nullptr );
        if ( pNode != head_4->value.pNode )
          break;
        if ( pNext == v1 )
          return nullptr;
        _ThreadInterlockedAssignIf64(
          a1: &v1->m_Tail,
          a2: pNext,
          a3: pTailNode->value.sequence + 1,
          a4: pNode,
          a5: pTailNode->value.sequence);
      }
    }
    while ( pNext == v1 );
    sequence = pNext->m_Head.value.sequence;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNext, a3: *pHead + 1, a4: pNode, a5: *pHead) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  pNode->elem = sequence;
  return pNode;
}

//------------------------------------------------------------------------------
// Address: 0x1013F210
// Name: public: struct CTSQueue<class CFunctor __near *,0,1>::Node_t __near * CTSQueue<class CFunctor __near *,0,1>::Push(struct CTSQueue<class CFunctor __near *,0,1>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<StartSoundParams_t,0,1>::Node_t *__thiscall CTSQueue<CFunctor *,0,1>::Push(
        CTSQueue<StartSoundParams_t,0,1> *this,
        CTSQueue<loopback_t *,0,1>::Node_t *pNode)
{
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v3; // edi
  int i; // [esp-4h] [ebp-10h]

  pNode->pNext = (CTSQueue<loopback_t *,0,1>::Node_t *)this;
  v3 = this->m_Tail.value.pNode;
  for ( i = this->m_Tail.value.sequence;
        (CTSQueue<StartSoundParams_t,0,1> *)_InterlockedCompareExchange(
                                              (volatile signed __int32 *)v3,
                                              (signed __int32)pNode,
                                              (signed __int32)this) != this;
        i = this->m_Tail.value.sequence )
  {
    _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: v3->pNext, a3: i + 1, a4: v3, a5: i);
    v3 = this->m_Tail.value.pNode;
  }
  _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: pNode, a3: i + 1, a4: v3, a5: i);
  _InterlockedExchangeAdd(&this->m_Count.m_value, 1u);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101B43E0
// Name: bool NET_StringToSockaddr(char const __near *,struct sockaddr __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_StringToSockaddr(const char *s, sockaddr *sadr)
{
  char v2; // al
  char *v3; // esi
  u_short v4; // ax
  struct hostent *v6; // eax
  char copy[128]; // [esp+8h] [ebp-80h] BYREF

  _V_memset(dest: sadr, fill: 0, count: 16);
  *(_DWORD *)&sadr->sa_family = 2;
  V_strncpy(pDest: copy, pSrc: s, maxLen: 128);
  v2 = copy[0];
  v3 = copy;
  if ( copy[0] != 0 )
  {
    do
    {
      if ( *v3 == 58 )
      {
        *v3 = 0;
        v4 = atoi(nptr: v3 + 1);
        *(_WORD *)sadr->sa_data = htons(hostshort: v4);
      }
      ++v3;
    }
    while ( *v3 != 0 );
    v2 = copy[0];
  }
  if ( (unsigned __int8)(v2 - 48) <= 9u && _V_strstr(s1: copy, search: ".") != nullptr )
  {
    *(_DWORD *)&sadr->sa_data[2] = inet_addr(cp: copy);
    return 1;
  }
  else
  {
    if ( net_nodns )
      return 0;
    v6 = gethostbyname(name: copy);
    if ( v6 == nullptr )
    {
      return 0;
    }
    else
    {
      *(_DWORD *)&sadr->sa_data[2] = **(_DWORD **)v6->h_addr_list;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4500
// Name: bool NET_StringToAdr(char const __near *,struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_StringToAdr(const char *s, netadr_s *a)
{
  char result; // al
  char address[128]; // [esp+0h] [ebp-90h] BYREF
  sockaddr saddr; // [esp+80h] [ebp-10h] BYREF

  V_strncpy(pDest: address, pSrc: s, maxLen: 128);
  if ( V_strncmp(s1: address, s2: "localhost", count: 10) == 0
    || V_strncmp(s1: address, s2: "localhost:", count: 10) == 0 )
  {
    _V_memcpy(dest: address, src: "127.0.0.1", count: 9);
  }
  result = NET_StringToSockaddr(s: address, sadr: &saddr);
  if ( result != 0 )
  {
    netadr_s::SetFromSockadr(this: a, s: &saddr);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B45A0
// Name: int NET_SendStream(int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NET_SendStream(SOCKET nSock, const char *buf, int len, int flags)
{
  int v4; // esi
  int Error; // eax
  const char *v7; // eax

  v4 = send(s: nSock, buf, len, flags);
  if ( v4 == -1 )
  {
    Error = WSAGetLastError();
    net_error = Error;
    if ( Error == 10035 )
      return 0;
    v7 = NET_ErrorString(code: Error);
    _Msg(a1: "NET_SendStream: %s\n", v7);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101B4600
// Name: int NET_ReceiveStream(int,char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NET_ReceiveStream(SOCKET nSock, char *buf, int len, int flags)
{
  int v4; // esi
  int Error; // eax
  const char *v6; // eax

  v4 = recv(s: nSock, buf, len, flags);
  if ( v4 != -1 )
    return v4;
  Error = WSAGetLastError();
  net_error = Error;
  if ( Error != 10035 && Error != 10057 )
  {
    v6 = NET_ErrorString(code: Error);
    _Msg(a1: "NET_ReceiveStream: %s\n", v6);
    return v4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B4660
// Name: float NET_GetFakeLag(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl NET_GetFakeLag()
{
  return s_FakeLag;
}

//------------------------------------------------------------------------------
// Address: 0x101B4670
// Name: void NET_GetLocalAddress(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_GetLocalAddress()
{
  char *m_pszString; // eax
  char *v1; // eax
  char buff[512]; // [esp+0h] [ebp-200h] BYREF

  netadr_s::Clear(this: &net_local_adr);
  if ( net_noip )
  {
    _Msg(a1: "TCP/UDP Disabled.\n");
  }
  else
  {
    if ( (ipname.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = ipname.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    if ( _V_strcmp(s1: m_pszString, s2: "localhost") != 0 )
    {
      if ( (ipname.m_nFlags & 0x1000) != 0 )
      {
        v1 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v1 = ipname.m_pParent->m_Value.m_pszString;
        if ( v1 == nullptr )
          v1 = (char *)defaultValue;
      }
      V_strncpy(pDest: buff, pSrc: v1, maxLen: 512);
    }
    else
    {
      gethostname(name: buff, namelen: 512);
      buff[511] = 0;
    }
    NET_StringToAdr(s: buff, a: &net_local_adr);
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&hostip.IConVar,
      value: net_local_adr.ip[3] + ((net_local_adr.ip[2] + ((net_local_adr.ip[1] + (net_local_adr.ip[0] << 8)) << 8)) << 8));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4780
// Name: bool NET_IsMultiplayer(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NET_IsMultiplayer()
{
  return net_multiplayer;
}

//------------------------------------------------------------------------------
// Address: 0x101B4790
// Name: bool NET_IsDedicated(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NET_IsDedicated()
{
  return net_dedicated;
}

//------------------------------------------------------------------------------
// Address: 0x101B47A0
// Name: bool NET_IsDedicatedForXbox(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl NET_IsDedicatedForXbox()
{
  return net_dedicated && net_dedicatedForXbox;
}

//------------------------------------------------------------------------------
// Address: 0x101B47C0
// Name: void NET_SetTime(double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_SetTime(long double realtime)
{
  double v2; // st7
  double frametime; // [esp+8h] [ebp+8h]

  frametime = realtime - s_last_realtime;
  s_last_realtime = realtime;
  v2 = 1.0;
  if ( frametime > 1.0 || (v2 = 0.0, frametime < 0.0) )
    frametime = v2;
  net_time = ((double (__thiscall *)(IEngineToolInternal *))g_pEngineToolInternal->GetTimescale)(a1: g_pEngineToolInternal)
           * frametime
           + net_time;
}

//------------------------------------------------------------------------------
// Address: 0x101B4820
// Name: void NET_InitPostFork(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x101B4860
// Name: void NET_PrintChannelStatus(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_PrintChannelStatus(INetChannel *chan)
{
  const char *v1; // eax
  bool v2; // zf
  const char *v3; // eax
  const char *v4; // eax
  double v5; // st7
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int64 v8; // st7
  double v9; // st7
  unsigned __int64 v10; // st7
  double v11; // st7
  unsigned __int64 v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  int v16; // eax
  double v17; // [esp+30h] [ebp-10h]
  double v18; // [esp+30h] [ebp-10h]
  double v19; // [esp+30h] [ebp-10h]
  double v20; // [esp+30h] [ebp-10h]
  double v21; // [esp+30h] [ebp-10h]
  int v22; // [esp+38h] [ebp-8h]
  int v23; // [esp+38h] [ebp-8h]
  int v24; // [esp+38h] [ebp-8h]
  int v25; // [esp+38h] [ebp-8h]
  INetChannel *chana; // [esp+48h] [ebp+8h]

  v1 = (const char *)chan->GetName(this: chan);
  _Msg(a1: "NetChannel '%s':\n", v1);
  v2 = !chan->IsPlayback(this: chan);
  v3 = "(Demo`)";
  if ( v2 )
    v3 = defaultValue;
  v4 = (const char *)((int (__thiscall *)(INetChannel *, const char *))chan->GetAddress)(a1: chan, a2: v3);
  _Msg(a1: "- remote IP: %s\n", v4);
  v5 = ((double (__thiscall *)(INetChannel *))chan->GetTimeConnected)(a1: chan);
  v6 = COM_FormatSeconds(seconds: (int)v5);
  _Msg(a1: "- online: %s\n", v6);
  v2 = !chan->HasPendingReliableData(this: chan);
  v7 = "pending data";
  if ( v2 )
    v7 = "available";
  _Msg(a1: "- reliable: %s\n", v7);
  *(double *)&v8 = ((double (__thiscall *)(INetChannel *, int))chan->GetAvgLoss)(a1: chan, a2: 1);
  v9 = ((double (__thiscall *)(INetChannel *, _DWORD, _DWORD, _DWORD))chan->GetAvgLatency)(
         a1: chan,
         a2: 0,
         a3: v8,
         a4: HIDWORD(v8));
  _Msg(a1: "- latency: %.1f, loss %.2f\n", v9, v17);
  *(double *)&v10 = ((double (__thiscall *)(INetChannel *, _DWORD, int))chan->GetAvgPackets)(a1: chan, a2: 0, a3: v22);
  v11 = ((double (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetAvgPackets)(
          a1: chan,
          a2: 1,
          a3: v10,
          a4: HIDWORD(v10));
  _Msg(a1: "- packets: in %.1f/s, out %.1f/s\n", v11, v18);
  *(double *)&v12 = ((double (__thiscall *)(INetChannel *, _DWORD, int))chan->GetAvgChoke)(a1: chan, a2: 0, a3: v23);
  v13 = ((double (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetAvgChoke)(
          a1: chan,
          a2: 1,
          a3: v12,
          a4: HIDWORD(v12));
  _Msg(a1: "- choke: in %.2f, out %.2f\n", v13, v19);
  v14 = ((double (__thiscall *)(INetChannel *, _DWORD, int))chan->GetAvgData)(a1: chan, a2: 0, a3: v24);
  v15 = ((double (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetAvgData)(
          a1: chan,
          a2: 1,
          a3: COERCE_UNSIGNED_INT64(v14 * 0.0009765625),
          a4: HIDWORD(COERCE_UNSIGNED_INT64(v14 * 0.0009765625)));
  _Msg(a1: "- flow: in %.1f, out %.1f kB/s\n", v15 * 0.0009765625, v20);
  v16 = ((int (__thiscall *)(INetChannel *, _DWORD, int))chan->GetTotalData)(a1: chan, a2: 0, a3: v25);
  chana = (INetChannel *)((int (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetTotalData)(
                           a1: chan,
                           a2: 1,
                           a3: COERCE_UNSIGNED_INT64((double)v16 * 0.00000095367432),
                           a4: HIDWORD(COERCE_UNSIGNED_INT64((double)v16 * 0.00000095367432)));
  _Msg(a1: "- total: in %.1f, out %.1f MB\n\n", (double)(int)chana * 0.00000095367432, v21);
}

//------------------------------------------------------------------------------
// Address: 0x101B4A00
// Name: bool NET_BufferToBufferCompress(char __near *,unsigned int __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_BufferToBufferCompress(char *dest, unsigned int *destLen, char *source, unsigned int sourceLen)
{
  unsigned __int8 *v4; // esi
  CLZSS s; // [esp+Ch] [ebp-10h] BYREF
  unsigned int uCompressedLen; // [esp+18h] [ebp-4h] BYREF

  _V_memcpy(dest, src: source, count: sourceLen);
  s.m_nWindowSize = 4096;
  uCompressedLen = 0;
  v4 = CLZSS::Compress(
         this: &s,
         pInput: (unsigned __int8 *)source,
         inputLength: sourceLen,
         pOutputSize: &uCompressedLen);
  if ( v4 != nullptr )
  {
    if ( uCompressedLen != 0 && uCompressedLen <= *destLen )
    {
      _V_memcpy(dest, src: v4, count: uCompressedLen);
      *destLen = uCompressedLen;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      return 1;
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  }
  _V_memcpy(dest, src: source, count: sourceLen);
  *destLen = sourceLen;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B4AB0
// Name: bool NET_BufferToBufferDecompress(char __near *,unsigned int __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_BufferToBufferDecompress(char *dest, unsigned int *destLen, char *source, unsigned int sourceLen)
{
  unsigned int ActualSize; // eax
  CLZSS s; // [esp+Ch] [ebp-Ch] BYREF

  s.m_nWindowSize = 4096;
  if ( CLZSS::IsCompressed(this: &s, pInput: (unsigned __int8 *)source) )
  {
    ActualSize = CLZSS::GetActualSize(this: &s, pInput: (unsigned __int8 *)source);
    if ( ActualSize > *destLen )
    {
      _Warning(
        a1: "NET_BufferToBufferDecompress with improperly sized dest buffer (%u in, %u needed)\n",
        *destLen,
        ActualSize);
      return 0;
    }
    *destLen = CLZSS::SafeUncompress(
                 this: &s,
                 pInput: (unsigned __int8 *)source,
                 pOutput: (unsigned __int8 *)dest,
                 unBufSize: *destLen);
    return 1;
  }
  else
  {
    if ( sourceLen > *destLen )
    {
      _Warning(
        a1: "NET_BufferToBufferDecompress with improperly sized dest buffer (%u in, %u needed)\n",
        *destLen,
        sourceLen);
      return 0;
    }
    _V_memcpy(dest, src: source, count: sourceLen);
    *destLen = sourceLen;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4BE0
// Name: void NET_AddToLagged(struct netpacket_s __near * __near *,struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_AddToLagged(netpacket_s **pList, netpacket_s *pPacket)
{
  netpacket_s *v2; // ebx
  netadr_s *v3; // eax
  netpacket_s *v4; // esi
  unsigned __int8 *v5; // eax
  int v6; // eax

  v2 = nullptr;
  if ( pPacket->pNext != nullptr )
  {
    _Msg(a1: "NET_AddToLagged::Packet already linked\n");
  }
  else
  {
    v3 = (netadr_s *)MemAlloc_Alloc(nSize: 0x50u);
    v4 = (netpacket_s *)v3;
    if ( v3 != nullptr )
    {
      netadr_s::SetIP(this: v3, unIP: 0);
      netadr_s::SetPort(this: &v4->from, newport: 0);
      netadr_s::SetType(this: &v4->from, newtype: NA_IP);
      v4->message.m_bOverflow = false;
      v4->message.m_pDebugName = nullptr;
      v4->message.m_nDataBytes = 0;
      v4->message.m_nDataBits = -1;
      v2 = v4;
    }
    qmemcpy(v2, pPacket, sizeof(netpacket_s));
    v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: pPacket->size);
    v2->data = v5;
    _V_memcpy(dest: v5, src: pPacket->data, count: pPacket->size);
    v2->pNext = nullptr;
    v6 = (int)*pList;
    if ( *pList != nullptr )
    {
      for ( ; *(_DWORD *)(v6 + 76) != 0; v6 = *(_DWORD *)(v6 + 76) )
        ;
      *(_DWORD *)(v6 + 76) = v2;
    }
    else
    {
      *pList = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4CA0
// Name: void NET_AdjustLag(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_AdjustLag()
{
  long double v0; // st5
  long double v1; // st6
  long double v2; // st7
  float m_fValue; // xmm1_4
  long double v4; // st6
  long double v5; // st6
  float v6; // xmm1_4
  float v7; // xmm0_4
  float diff; // [esp+0h] [ebp-Ch]
  float converge; // [esp+4h] [ebp-8h]
  float v10; // [esp+8h] [ebp-4h]

  v0 = 0.0;
  if ( net_time - s_LastTime < 0.0 || (v0 = net_time - s_LastTime, v1 = 0.2000000029802322, v0 <= 0.2000000029802322) )
    v1 = v0;
  v2 = v1;
  m_fValue = fakelag.m_pParent->m_Value.m_fValue;
  s_LastTime = net_time;
  if ( m_fValue != s_FakeLag )
  {
    v4 = m_fValue - s_FakeLag;
    diff = v4;
    v5 = fabs(v4);
    if ( v2 * 200.0 <= v5 )
    {
      converge = v2 * 200.0;
      v6 = converge;
    }
    else
    {
      v10 = v5;
      v6 = v10;
    }
    if ( diff >= 0.0 )
      v7 = s_FakeLag + v6;
    else
      v7 = s_FakeLag - v6;
    s_FakeLag = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4D60
// Name: bool NET_LagPacket(bool,struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __cdecl NET_LagPacket(bool newdata, netpacket_s *packet)
{
  int source; // ecx
  int m_nValue; // eax
  ConVar *m_pParent; // edx
  float m_fValue; // xmm0_4
  int v7; // eax
  float v8; // xmm0_4
  int v9; // edi
  netpacket_s **v10; // esi
  netpacket_s *v11; // esi
  float v12; // xmm1_4
  float v13; // xmm0_4
  double v14; // st7
  float target; // [esp+14h] [ebp-4h]

  source = packet->source;
  if ( source >= 3 )
    return newdata;
  if ( droppackets.m_pParent != nullptr )
  {
    m_nValue = droppackets.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 && newdata && source == 0 )
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&droppackets.IConVar, value: m_nValue - 1);
      return 0;
    }
  }
  m_pParent = fakeloss.m_pParent;
  if ( fakeloss.m_pParent->m_Value.m_fValue != 0.0 && newdata )
  {
    ++losscount[source];
    m_fValue = m_pParent->m_Value.m_fValue;
    if ( m_fValue <= 0.0 )
    {
      source = (int)fabs(m_pParent->m_Value.m_fValue);
      if ( source < 2 )
        source = 2;
      if ( losscount[packet->source] % source == 0 )
        return 0;
    }
    else
    {
      v7 = _RandomInt(this: (IUniformRandomStream *)source, a2: 0, a3: 100);
      source = (int)m_fValue;
      if ( v7 <= (int)m_fValue )
        return 0;
    }
  }
  v8 = s_FakeLag;
  if ( s_FakeLag > 0.0 )
  {
    if ( newdata )
    {
      NET_AddToLagged(pList: &s_pLagData[packet->source], pPacket: packet);
      v8 = s_FakeLag;
    }
    v11 = s_pLagData[packet->source];
    if ( v11 == nullptr )
      return 0;
    v12 = fakejitter.m_pParent->m_Value.m_fValue;
    target = v8;
    if ( v12 <= 0.0 )
    {
      v14 = v8;
    }
    else
    {
      v13 = v8 * 0.5;
      if ( v13 > v12 )
        v13 = fakejitter.m_pParent->m_Value.m_fValue;
      v14 = _RandomFloat(
              this: (IUniformRandomStream *)source,
              a2: COERCE_FLOAT(LODWORD(v13) ^ _mask__NegFloat_),
              a3: v13)
          + target;
    }
    if ( v14 * 0.001 + v11->received <= net_time )
    {
      s_pLagData[packet->source] = v11->pNext;
      packet->source = v11->source;
      packet->from = v11->from;
      packet->pNext = nullptr;
      packet->received = net_time;
      packet->size = v11->size;
      packet->wiresize = v11->wiresize;
      packet->stream = v11->stream;
      _V_memcpy(dest: packet->data, src: v11->data, count: v11->size);
      free(pMem: v11->data);
      free(pMem: v11);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v9 = 0;
    v10 = s_pLagData;
    do
    {
      if ( v9 < 3 && *v10 != nullptr )
        NET_ClearLaggedList(pList: v10);
      ++v10;
      ++v9;
    }
    while ( (int)v10 < (int)&net_multiplayer );
    return newdata;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4F80
// Name: DescribeSocket
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall DescribeSocket(void *sock)
{
  const tokenset_t<enum ESocketIndex_t> *v1; // eax

  v1 = s_SocketDescMap;
  if ( "cl" == nullptr )
    return "??";
  while ( (void *)v1->token != sock )
  {
    ++v1;
    if ( v1->name == nullptr )
      return "??";
  }
  return v1->name;
}

//------------------------------------------------------------------------------
// Address: 0x101B4FB0
// Name: int NET_SendToImpl(unsigned int,char const __near *,int,struct sockaddr const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NET_SendToImpl(unsigned int s, char *buf, int len, const sockaddr *to, int tolen, int iGameDataLength)
{
  const char *v6; // eax
  int v8; // [esp-10h] [ebp-34h]
  _WSABUF buffers[2]; // [esp+0h] [ebp-24h] BYREF
  netadr_s toAdr; // [esp+10h] [ebp-14h] BYREF
  int nSend; // [esp+1Ch] [ebp-8h] BYREF
  int nDataBytes; // [esp+20h] [ebp-4h] BYREF

  nSend = 0;
  if ( !net_dedicatedForXbox )
    return g_pSteamSocketMgr->sendto(this: g_pSteamSocketMgr, a2: s, a3: buf, a4: len, a5: 0, a6: to, a7: tolen);
  if ( iGameDataLength == -1 )
    nDataBytes = (unsigned __int16)len;
  else
    nDataBytes = (unsigned __int16)iGameDataLength;
  if ( voice_xsend_debug.m_pParent != nullptr
    && voice_xsend_debug.m_pParent->m_Value.m_nValue != 0
    && iGameDataLength >= 0
    && iGameDataLength != len )
  {
    DevMsg(a1: "XVoice: VDP packet to %d with unencrypted %d bytes out of %d bytes\n", s, len - iGameDataLength, len);
  }
  buffers[0].len = 2;
  buffers[0].buf = (char *)&nDataBytes;
  buffers[1].len = len;
  buffers[1].buf = buf;
  if ( (unsigned __int16)nDataBytes < len
    && voice_verbose.m_pParent != nullptr
    && voice_verbose.m_pParent->m_Value.m_nValue != 0 )
  {
    netadr_s::SetIP(this: &toAdr, unIP: 0);
    netadr_s::SetPort(this: &toAdr, newport: 0);
    netadr_s::SetType(this: &toAdr, newtype: NA_IP);
    netadr_s::SetFromSockadr(this: &toAdr, s: to);
    v8 = len - (unsigned __int16)nDataBytes;
    v6 = netadr_s::ToString(this: &toAdr, baseOnly: false);
    _Msg(a1: "* NET_SendToImpl: sending voice to %s (%d bytes)\n", v6, v8);
  }
  WSASendTo(
    s,
    lpBuffers: buffers,
    dwBufferCount: 2u,
    lpNumberOfBytesSent: (LPDWORD)&nSend,
    dwFlags: 0,
    lpTo: to,
    iTolen: tolen,
    lpOverlapped: nullptr,
    lpCompletionRoutine: nullptr);
  return nSend;
}

//------------------------------------------------------------------------------
// Address: 0x101B50E0
// Name: NET_SendTo
// Source: json
//------------------------------------------------------------------------------
int __usercall NET_SendTo@<eax>(
        int len@<edi>,
        const sockaddr *to@<esi>,
        unsigned int verbose,
        char *s,
        const char *buf,
        int tolen)
{
  if ( *(_DWORD *)&to->sa_data[2] == 0 && *(_WORD *)to->sa_data == 0 )
    return len;
  if ( (CL_IsHL2Demo() || CL_IsPortalDemo()) && !net_dedicated )
    _Error(a1: defaultValue);
  return NET_SendToImpl(s: verbose, buf: s, len, to, tolen: (int)buf, iGameDataLength: tolen);
}

//------------------------------------------------------------------------------
// Address: 0x101B51A0
// Name: public: void CUtlMemory<unsigned char,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::ConvertToGrowableMemory(
        CUtlMemory<unsigned char,int> *this,
        int nGrowSize)
{
  unsigned int m_nAllocationCount; // edi
  unsigned __int8 *v4; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    this->m_nGrowSize = nGrowSize;
    if ( m_nAllocationCount != 0 )
    {
      v4 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
      memcpy(dst: v4, src: this->m_pMemory, count: m_nAllocationCount);
      this->m_pMemory = v4;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5340
// Name: class CNetChan __near * NET_FindNetChannel(int,struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
CNetChan *__cdecl NET_FindNetChannel(int socket, netadr_s *adr)
{
  DWORD CurrentThreadId; // ecx
  int v3; // edi
  int m_Size; // ebx
  CNetChan *v5; // esi
  const netadr_s *v6; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_NetChannels.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_NetChannels.m_depth;
  }
  v3 = 0;
  m_Size = s_NetChannels.m_Size;
  if ( s_NetChannels.m_Size <= 0 )
  {
LABEL_9:
    if ( --s_NetChannels.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v5 = s_NetChannels.m_Memory.m_pMemory[v3];
      if ( socket == v5->GetSocket(this: v5) )
      {
        v6 = v5->GetRemoteAddress(this: v5);
        if ( netadr_s::CompareAdr(this: adr, a: v6, onlyBase: false) )
          break;
      }
      if ( ++v3 >= m_Size )
        goto LABEL_9;
    }
    if ( --s_NetChannels.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5410
// Name: void NET_CloseSocket(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_CloseSocket(SOCKET hSocket, int sock)
{
  const char *v2; // eax

  if ( hSocket != 0 )
  {
    if ( closesocket(s: hSocket) == -1 )
    {
      net_error = WSAGetLastError();
      v2 = NET_ErrorString(code: net_error);
      ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v2);
    }
    if ( sock >= 0 && net_sockets.m_Memory.m_pMemory[sock].hTCP == hSocket )
    {
      net_sockets.m_Memory.m_pMemory[sock].hTCP = 0;
      net_sockets.m_Memory.m_pMemory[sock].bListening = false;
    }
    g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: sock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5490
// Name: int NET_OpenSocket(char const __near *,int __near &,int)
// Source: json
//------------------------------------------------------------------------------
SOCKET __cdecl NET_OpenSocket(const char *net_interface, int *port, unsigned int protocol)
{
  unsigned int v3; // edi
  SOCKET v4; // eax
  SOCKET v5; // esi
  int Error; // eax
  const char *v7; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  int v16; // eax
  const char *v17; // eax
  int v18; // ebx
  int v19; // eax
  bool v20; // zf
  int v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  sockaddr_in address; // [esp+Ch] [ebp-14h] BYREF
  linger optlinger; // [esp+1Ch] [ebp-4h] BYREF

  v3 = protocol;
  if ( protocol == 6 )
    v4 = socket(af: 2, type: 1, protocol: 6);
  else
    v4 = socket(af: 2, type: 2, protocol);
  v5 = v4;
  if ( v4 == -1 )
  {
    Error = WSAGetLastError();
    net_error = Error;
    if ( Error != 10047 )
    {
      v7 = NET_ErrorString(code: Error);
      _Msg(a1: "WARNING: NET_OpenSockett: socket failed: %s", v7);
    }
    return 0;
  }
  else
  {
    protocol = 1;
    if ( ioctlsocket(s: v4, cmd: -2147195266, argp: &protocol) == -1 )
    {
      net_error = WSAGetLastError();
      v9 = NET_ErrorString(code: net_error);
      _Msg(a1: "WARNING: NET_OpenSocket: ioctl FIONBIO: %s\n", v9);
    }
    protocol = 1;
    if ( v3 == 6 )
    {
      if ( setsockopt(s: v5, level: 0xFFFF, optname: 8, optval: (const char *)&protocol, optlen: 4) == -1 )
      {
        net_error = WSAGetLastError();
        v10 = NET_ErrorString(code: net_error);
        _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_KEEPALIVE: %s\n", v10);
        return 0;
      }
      else
      {
        optlinger = 0;
        if ( setsockopt(s: v5, level: 0xFFFF, optname: 128, optval: (const char *)&optlinger, optlen: 4) == -1 )
        {
          net_error = WSAGetLastError();
          v11 = NET_ErrorString(code: net_error);
          _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_LINGER: %s\n", v11);
          return 0;
        }
        else
        {
          protocol = 1;
          if ( setsockopt(s: v5, level: 6, optname: 1, optval: (const char *)&protocol, optlen: 4) == -1 )
          {
            net_error = WSAGetLastError();
            v12 = NET_ErrorString(code: net_error);
            _Msg(a1: "WARNING: NET_OpenSocket: setsockopt TCP_NODELAY: %s\n", v12);
            return 0;
          }
          else
          {
            protocol = 96016;
            if ( setsockopt(s: v5, level: 0xFFFF, optname: 4097, optval: (const char *)&protocol, optlen: 4) == -1 )
            {
              net_error = WSAGetLastError();
              v13 = NET_ErrorString(code: net_error);
              _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_SNDBUF: %s\n", v13);
              return 0;
            }
            else
            {
              protocol = 96016;
              if ( setsockopt(s: v5, level: 0xFFFF, optname: 4098, optval: (const char *)&protocol, optlen: 4) == -1 )
              {
                net_error = WSAGetLastError();
                v14 = NET_ErrorString(code: net_error);
                _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_RCVBUF: %s\n", v14);
                return 0;
              }
              else
              {
                return v5;
              }
            }
          }
        }
      }
    }
    else if ( setsockopt(s: v5, level: 0xFFFF, optname: 32, optval: (const char *)&protocol, optlen: 4) == -1 )
    {
      net_error = WSAGetLastError();
      v15 = NET_ErrorString(code: net_error);
      _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_BROADCAST: %s\n", v15);
      return 0;
    }
    else
    {
      v16 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v16 + 40))(a1: v16, a2: "-reuse") != 0
        && (protocol = 1, setsockopt(s: v5, level: 0xFFFF, optname: 4, optval: (const char *)&protocol, optlen: 4) == -1) )
      {
        net_error = WSAGetLastError();
        v17 = NET_ErrorString(code: net_error);
        _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_REUSEADDR: %s\n", v17);
        return 0;
      }
      else
      {
        v18 = 0;
        if ( net_interface != nullptr && *net_interface != 0 && _V_strcmp(s1: net_interface, s2: "localhost") != 0 )
          NET_StringToSockaddr(s: net_interface, sadr: (sockaddr *)&address);
        else
          address.sin_addr.S_un.S_addr = 0;
        address.sin_family = 2;
        optlinger = (linger)10;
        if ( g_nForkID > 0 )
          optlinger = (linger)150;
        while ( 1 )
        {
          address.sin_port = *port == -1 ? 0 : htons(hostshort: v18 + *(_WORD *)port);
          if ( bind(s: v5, name: (const struct sockaddr *)&address, namelen: 16) != -1 )
            break;
          v19 = WSAGetLastError();
          v20 = *port == -1;
          net_error = v19;
          if ( v20 || v19 != 10048 )
          {
            v22 = NET_ErrorString(code: v19);
            _Msg(a1: "WARNING: NET_OpenSocket: bind: %s\n", v22);
            goto LABEL_46;
          }
          if ( ++v18 >= *(_DWORD *)&optlinger )
            goto LABEL_40;
        }
        v21 = *port;
        if ( *port != -1 && v18 != 0 )
        {
          *port = v18 + v21;
          _ConDMsg(a1: "Socket bound to non-default port %i because original port was already in use.\n", v18 + v21);
        }
LABEL_40:
        if ( v18 != optlinger )
          return v5;
        _Msg(a1: "WARNING: UDP_OpenSocket: unable to bind socket\n");
LABEL_46:
        if ( v5 != 0 )
        {
          if ( closesocket(s: v5) == -1 )
          {
            net_error = WSAGetLastError();
            v23 = NET_ErrorString(code: net_error);
            ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v23);
          }
          g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
        }
        return 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5880
// Name: int NET_ConnectSocket(int,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NET_ConnectSocket(int sock, netadr_s *addr)
{
  int v2; // ebx
  int v3; // esi
  int *p_hTCP; // edi
  char *m_pszString; // eax
  SOCKET v6; // eax
  int Error; // eax
  const char *v9; // eax
  sockaddr saddr; // [esp+Ch] [ebp-10h] BYREF

  v2 = sock;
  v3 = sock;
  p_hTCP = &net_sockets.m_Memory.m_pMemory[sock].hTCP;
  if ( *p_hTCP != 0 )
    NET_CloseSocket(hSocket: *p_hTCP, sock);
  if ( net_notcp )
    return 0;
  netadr_s::ToSockadr(this: addr, s: &saddr);
  sock = -1;
  if ( (ipname.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = ipname.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v6 = NET_OpenSocket(net_interface: m_pszString, port: &sock, protocol: 1u);
  *p_hTCP = v6;
  if ( v6 == 0 )
  {
    _Msg(
      a1: "Warning! NET_ConnectSocket failed opening socket %i, port %i.\n",
      v2,
      net_sockets.m_Memory.m_pMemory[v3].nPort);
    return 0;
  }
  if ( connect(s: v6, name: &saddr, namelen: 16) != -1 )
    return net_sockets.m_Memory.m_pMemory[v3].hTCP;
  Error = WSAGetLastError();
  net_error = Error;
  if ( Error == 10035 )
    return net_sockets.m_Memory.m_pMemory[v3].hTCP;
  v9 = NET_ErrorString(code: Error);
  _Msg(a1: "NET_ConnectSocket: %s\n", v9);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B5980
// Name: unsigned short NET_GetUDPPort(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl NET_GetUDPPort(int socket)
{
  if ( socket < 0 || socket >= net_sockets.m_Size )
    return 0;
  else
    return net_sockets.m_Memory.m_pMemory[socket].nPort;
}

//------------------------------------------------------------------------------
// Address: 0x101B59B0
// Name: void NET_ListenSocket(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ListenSocket(int sock, bool bListen)
{
  netsocket_t *v2; // esi
  SOCKET hTCP; // eax
  char *m_pszString; // ebx
  SOCKET v5; // eax
  u_short v6; // ax
  int Error; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  SOCKET v11; // [esp-10h] [ebp-28h]
  sockaddr_in address; // [esp+8h] [ebp-10h] BYREF

  v2 = &net_sockets.m_Memory.m_pMemory[sock];
  hTCP = v2->hTCP;
  if ( hTCP != 0 )
    NET_CloseSocket(hSocket: hTCP, sock);
  if ( net_multiplayer && !net_notcp && bListen )
  {
    if ( (ipname.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = ipname.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    v5 = NET_OpenSocket(net_interface: m_pszString, port: &v2->nPort, protocol: 1u);
    v2->hTCP = v5;
    if ( v5 != 0 )
    {
      if ( m_pszString != nullptr && *m_pszString != 0 && _V_strcmp(s1: m_pszString, s2: "localhost") != 0 )
        NET_StringToSockaddr(s: m_pszString, sadr: (sockaddr *)&address);
      else
        address.sin_addr.S_un.S_addr = 0;
      address.sin_family = 2;
      v6 = htons(hostshort: v2->nPort);
      v11 = v2->hTCP;
      address.sin_port = v6;
      if ( bind(s: v11, name: (const struct sockaddr *)&address, namelen: 16) == -1 )
      {
        Error = WSAGetLastError();
        v8 = v2->hTCP;
        net_error = Error;
        _Msg(a1: "WARNING: NET_ListenSocket bind failed on socket %i, port %i.\n", v8, v2->nPort);
      }
      else if ( listen(s: v2->hTCP, backlog: 8) == -1 )
      {
        v9 = WSAGetLastError();
        v10 = v2->hTCP;
        net_error = v9;
        _Msg(a1: "WARNING: NET_ListenSocket listen failed on socket %i, port %i.\n", v10, v2->nPort);
      }
      else
      {
        v2->bListening = true;
      }
    }
    else
    {
      _Msg(
        a1: "Warning! NET_ListenSocket failed opening socket %i, port %i.\n",
        sock,
        net_sockets.m_Memory.m_pMemory[sock].nPort);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5B20
// Name: net_channels
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_channels()
{
  int m_Size; // edi
  DWORD CurrentThreadId; // ecx
  int i; // esi

  m_Size = s_NetChannels.m_Size;
  if ( s_NetChannels.m_Size != 0 )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_NetChannels.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_NetChannels.m_depth;
    }
    for ( i = 0; i < m_Size; ++i )
      NET_PrintChannelStatus(chan: s_NetChannels.m_Memory.m_pMemory[i]);
    if ( --s_NetChannels.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
  }
  else
  {
    ConMsg(a1: "No active net channels.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5BC0
// Name: net_status
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_status()
{
  DWORD CurrentThreadId; // ecx
  int m_Size; // esi
  const char *v2; // eax
  const char *v3; // ecx
  const char *v4; // eax
  int v5; // esi
  int i; // edi
  int nPort; // ecx
  const tokenset_t<enum ESocketIndex_t> *v8; // eax
  const char *name; // eax
  int v10; // edi
  CNetChan *v11; // esi
  double v12; // st7
  float avgLossOut; // [esp+44h] [ebp-24h]
  float avgLossIn; // [esp+48h] [ebp-20h]
  float avgLatencyOut; // [esp+4Ch] [ebp-1Ch]
  float avgLatencyIn; // [esp+50h] [ebp-18h]
  int numChannels; // [esp+54h] [ebp-14h]
  float numChannelsa; // [esp+54h] [ebp-14h]
  float avgDataOut; // [esp+58h] [ebp-10h]
  float avgDataIn; // [esp+5Ch] [ebp-Ch]
  float avgPacketsOut; // [esp+60h] [ebp-8h]
  float avgPacketsIn; // [esp+64h] [ebp-4h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_NetChannels.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_NetChannels.m_depth;
  }
  m_Size = s_NetChannels.m_Size;
  numChannels = s_NetChannels.m_Size;
  v2 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
  ConMsg(a1: "Net status for host %s:\n", v2);
  v3 = "dedicated";
  if ( !net_dedicated )
    v3 = "listen";
  v4 = "Multiplayer";
  if ( !net_multiplayer )
    v4 = "Singleplayer";
  ConMsg(a1: "- Config: %s, %s, %i connections\n", v4, v3, m_Size);
  ConMsg(a1: "- Ports: ");
  v5 = 0;
  for ( i = 0; i < 3; ++i )
  {
    if ( v5 < 0 || v5 >= net_sockets.m_Size )
      LOWORD(nPort) = 0;
    else
      nPort = net_sockets.m_Memory.m_pMemory[i].nPort;
    v8 = s_SocketDescMap;
    if ( "cl" != nullptr )
    {
      while ( v8->token != v5 )
      {
        ++v8;
        if ( v8->name == nullptr )
          goto LABEL_17;
      }
      name = v8->name;
    }
    else
    {
LABEL_17:
      name = "??";
    }
    ConMsg(a1: "%s%d %u, ", name, v5++, (unsigned __int16)nPort);
  }
  ConMsg(a1: "%d total.\n", 3);
  if ( numChannels <= 0 )
  {
    if ( --s_NetChannels.m_depth != 0 )
      return;
    goto LABEL_26;
  }
  v10 = 0;
  avgLatencyOut = 0.0;
  avgLatencyIn = 0.0;
  avgPacketsOut = 0.0;
  avgPacketsIn = 0.0;
  avgLossOut = 0.0;
  avgLossIn = 0.0;
  avgDataOut = 0.0;
  avgDataIn = 0.0;
  do
  {
    v11 = s_NetChannels.m_Memory.m_pMemory[v10];
    avgLatencyOut = ((double (__thiscall *)(CNetChan *, _DWORD))v11->GetAvgLatency)(a1: v11, a2: 0) + avgLatencyOut;
    avgLatencyIn = ((double (__thiscall *)(CNetChan *, int))v11->GetAvgLatency)(a1: v11, a2: 1) + avgLatencyIn;
    avgLossIn = ((double (__thiscall *)(CNetChan *, int))v11->GetAvgLoss)(a1: v11, a2: 1) + avgLossIn;
    avgLossOut = ((double (__thiscall *)(CNetChan *, _DWORD))v11->GetAvgLoss)(a1: v11, a2: 0) + avgLossOut;
    avgPacketsIn = ((double (__thiscall *)(CNetChan *, int))v11->GetAvgPackets)(a1: v11, a2: 1) + avgPacketsIn;
    avgPacketsOut = ((double (__thiscall *)(CNetChan *, _DWORD))v11->GetAvgPackets)(a1: v11, a2: 0) + avgPacketsOut;
    avgDataIn = ((double (__thiscall *)(CNetChan *, int))v11->GetAvgData)(a1: v11, a2: 1) + avgDataIn;
    ++v10;
    avgDataOut = ((double (__thiscall *)(CNetChan *, _DWORD))v11->GetAvgData)(a1: v11, a2: 0) + avgDataOut;
  }
  while ( v10 < numChannels );
  v12 = 1.0 / (double)numChannels;
  numChannelsa = v12;
  ConMsg(a1: "- Latency: avg out %.2fs, in %.2fs\n", v12 * avgLatencyOut, avgLatencyIn * v12);
  ConMsg(a1: "- Loss:    avg out %.1f, in %.1f\n", numChannelsa * avgLossOut, avgLossIn * numChannelsa);
  ConMsg(a1: "- Packets: net total out  %.1f/s, in %.1f/s\n", avgPacketsOut, avgPacketsIn);
  ConMsg(a1: "           per client out %.1f/s, in %.1f/s\n", numChannelsa * avgPacketsOut, avgPacketsIn * numChannelsa);
  ConMsg(a1: "- Data:    net total out  %.1f, in %.1f kB/s\n", 0.0009765625 * avgDataOut, avgDataIn * 0.0009765625);
  ConMsg(
    a1: "           per client out %.1f, in %.1f kB/s\n",
    0.0009765625 * (numChannelsa * avgDataOut),
    avgDataIn * numChannelsa * 0.0009765625);
  if ( --s_NetChannels.m_depth == 0 )
LABEL_26:
    _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B5EB0
// Name: void NET_SleepUntilMessages(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_SleepUntilMessages(int nMilliseconds)
{
  int hUDP; // eax
  fd_set fdset; // [esp+0h] [ebp-10Ch] BYREF
  timeval tv; // [esp+104h] [ebp-8h] BYREF

  fdset.fd_count = 0;
  hUDP = net_sockets.m_Memory.m_pMemory[1].hUDP;
  if ( hUDP != 0 )
  {
    tv.tv_usec = 1000 * nMilliseconds;
    tv.tv_sec = 0;
    fdset.fd_array[0] = hUDP;
    fdset.fd_count = 1;
    select(nfds: hUDP + 1, readfds: &fdset, writefds: nullptr, exceptfds: nullptr, timeout: &tv);
  }
  else
  {
    Sys_Sleep(msec: nMilliseconds);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5F20
// Name: bool NET_GetPublicAdr(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_GetPublicAdr(netadr_s *adr)
{
  char v1; // bl
  unsigned __int16 nPort; // di
  char *v3; // eax
  char *m_pszString; // eax
  CSteam3Server *v6; // eax
  CSteam3Server *v7; // eax
  unsigned int v8; // eax

  v1 = 0;
  if ( net_sockets.m_Size <= 1 )
    nPort = 0;
  else
    nPort = net_sockets.m_Memory.m_pMemory[1].nPort;
  if ( (net_public_adr.m_nFlags & 0x1000) != 0
    || (v3 = net_public_adr.m_pParent->m_Value.m_pszString) != nullptr && *v3 != 0 )
  {
    v1 = 1;
    netadr_s::SetType(this: adr, newtype: NA_IP);
    if ( (net_public_adr.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = net_public_adr.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    netadr_s::SetFromString(this: adr, pch: m_pszString, bUseDNS: false);
    if ( netadr_s::GetPort(this: adr) == 0 )
    {
      netadr_s::SetPort(this: adr, newport: nPort);
      return 1;
    }
  }
  else if ( net_dedicated )
  {
    v6 = Steam3Server();
    if ( v6->m_pSteamGameServer->GetPublicIP(this: v6->m_pSteamGameServer) != 0 )
    {
      v1 = 1;
      netadr_s::SetType(this: adr, newtype: NA_IP);
      v7 = Steam3Server();
      v8 = v7->m_pSteamGameServer->GetPublicIP(this: v7->m_pSteamGameServer);
      netadr_s::SetIP(this: adr, unIP: v8);
      netadr_s::SetPort(this: adr, newport: nPort);
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101B6010
// Name: public: void CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(
        CUtlMemoryFixedGrowable<unsigned char,4096,int> *this,
        int num)
{
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc_vtbl *v4; // edx

  if ( this->m_nAllocationCount < num )
  {
    if ( this->m_nGrowSize < 0 )
      CUtlMemory<unsigned char,int>::ConvertToGrowableMemory(this, nGrowSize: this->m_nMallocGrowSize);
    if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
    {
      m_pMemory = this->m_pMemory;
      this->m_nAllocationCount = num;
      v4 = _g_pMemAlloc->__vftable;
      if ( m_pMemory != nullptr )
        this->m_pMemory = (unsigned __int8 *)((int (__stdcall *)(unsigned __int8 *, int))v4->Realloc_2)(
                                               a1: m_pMemory,
                                               a2: num);
      else
        this->m_pMemory = (unsigned __int8 *)((int (__stdcall *)(int))v4->Alloc_2)(a1: num);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B61F0
// Name: void NET_DiscardStaleSplitpackets(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_DiscardStaleSplitpackets(int sock)
{
  int v1; // esi
  CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int> > *v2; // edi
  int v3; // ebx

  if ( sock >= 0 && sock < net_splitpackets.m_Size )
  {
    v1 = net_splitpackets.m_Memory.m_pMemory[sock].m_Size - 1;
    v2 = &net_splitpackets.m_Memory.m_pMemory[sock];
    if ( v1 >= 0 )
    {
      v3 = v1;
      do
      {
        if ( v2->m_Memory.m_pMemory[v3].lastactivetime + 15.0 <= net_time )
        {
          if ( v2->m_Size - v1 - 1 > 0 )
            _V_memmove(
              dest: &v2->m_Memory.m_pMemory[v3],
              src: &v2->m_Memory.m_pMemory[v3 + 1],
              count: 96728 * (v2->m_Size - v1 - 1));
          --v2->m_Size;
        }
        --v3;
        --v1;
      }
      while ( v1 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B62B0
// Name: void NET_ProcessPending(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ProcessPending()
{
  DWORD CurrentThreadId; // ecx
  int v1; // esi
  int v2; // edi
  pendingsocket_t *v3; // ebx
  long double v4; // st7
  SOCKET newsock; // eax
  const char *v6; // eax
  int v7; // eax
  int Error; // eax
  const char *v9; // eax
  int m_nBitsAvail; // esi
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v13; // edx
  unsigned int m_nInBufWord; // ebx
  int v15; // edi
  int v16; // edi
  unsigned int v17; // ebx
  unsigned int v18; // edx
  unsigned int v19; // eax
  DWORD v20; // eax
  int v21; // ebx
  CNetChan *v22; // esi
  int v23; // eax
  pendingsocket_t *v24; // edi
  int v25; // eax
  const char *v26; // eax
  pendingsocket_t *v27; // edi
  CNetChan_vtbl *v28; // eax
  void (__thiscall *ResetStreaming)(struct CNetChan *); // edx
  const char *v30; // eax
  const char *v31; // eax
  const char *v32; // eax
  bf_read header; // [esp+4h] [ebp-44h] BYREF
  char headerBuf[8]; // [esp+28h] [ebp-20h] BYREF
  int v35; // [esp+30h] [ebp-18h]
  int i; // [esp+34h] [ebp-14h]
  unsigned int v37; // [esp+38h] [ebp-10h]
  int m_nInBufWord_low; // [esp+3Ch] [ebp-Ch]
  pendingsocket_t *psock; // [esp+40h] [ebp-8h]
  bool bOK; // [esp+47h] [ebp-1h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_PendingSockets.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_PendingSockets.CThreadFastMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_PendingSockets.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_PendingSockets.m_depth;
  }
  v1 = 0;
  i = 0;
  if ( s_PendingSockets.m_Size <= 0 )
    goto LABEL_82;
  v2 = 0;
  v35 = 0;
  do
  {
    v3 = (pendingsocket_t *)((char *)s_PendingSockets.m_Memory.m_pMemory + v2);
    v4 = net_time - *(float *)((char *)&s_PendingSockets.m_Memory.m_pMemory->time + v2);
    newsock = *(int *)((char *)&s_PendingSockets.m_Memory.m_pMemory->newsock + v2);
    psock = (pendingsocket_t *)((char *)s_PendingSockets.m_Memory.m_pMemory + v2);
    if ( v4 > 4.0 )
      goto LABEL_8;
    v7 = recv(s: newsock, buf: headerBuf, len: 5, flags: 0);
    if ( v7 == -1 )
    {
      Error = WSAGetLastError();
      net_error = Error;
      if ( Error == 10035 || Error == 10057 )
        goto LABEL_81;
      v9 = NET_ErrorString(code: Error);
      _Msg(a1: "NET_ReceiveStream: %s\n", v9);
      newsock = v3->newsock;
LABEL_8:
      if ( newsock != 0 )
      {
        if ( closesocket(s: newsock) == -1 )
        {
          net_error = WSAGetLastError();
          v6 = NET_ErrorString(code: net_error);
          ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v6);
        }
        g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
      }
      if ( s_PendingSockets.m_Size - v1 - 1 > 0 )
        _V_memmove(
          dest: (char *)s_PendingSockets.m_Memory.m_pMemory + v2,
          src: (char *)&s_PendingSockets.m_Memory.m_pMemory[1] + v2,
          count: 24 * (s_PendingSockets.m_Size - v1 - 1));
      goto LABEL_80;
    }
    if ( v7 == 0 )
      goto LABEL_81;
    header.m_bOverflow = false;
    header.m_pDebugName = nullptr;
    header.m_nDataBytes = 0;
    header.m_nDataBits = -1;
    CBitRead::StartReading(this: &header, pData: headerBuf, nBytes: 5, iStartBit: 0, nBits: -1);
    m_nBitsAvail = header.m_nBitsAvail;
    m_pDataIn = header.m_pDataIn;
    m_pBufferEnd = header.m_pBufferEnd;
    if ( header.m_nBitsAvail >= 8 )
    {
      m_nBitsAvail = header.m_nBitsAvail - 8;
      header.m_nBitsAvail = m_nBitsAvail;
      if ( m_nBitsAvail != 0 )
      {
        v13 = header.m_nInBufWord >> 8;
        m_nInBufWord_low = LOBYTE(header.m_nInBufWord);
      }
      else
      {
        m_nBitsAvail = 32;
        header.m_nBitsAvail = 32;
        if ( header.m_pDataIn == header.m_pBufferEnd )
        {
          v13 = 0;
          m_nBitsAvail = 1;
          m_pDataIn = header.m_pDataIn + 1;
          header.m_nBitsAvail = 1;
          ++header.m_pDataIn;
          m_nInBufWord_low = LOBYTE(header.m_nInBufWord);
        }
        else
        {
          if ( header.m_pDataIn <= header.m_pBufferEnd )
          {
            v13 = *header.m_pDataIn;
            m_pDataIn = ++header.m_pDataIn;
          }
          else
          {
            header.m_bOverflow = true;
            v13 = 0;
          }
          m_nInBufWord_low = LOBYTE(header.m_nInBufWord);
        }
      }
      goto LABEL_35;
    }
    m_nInBufWord = header.m_nInBufWord;
    v15 = 8 - header.m_nBitsAvail;
    if ( header.m_pDataIn == header.m_pBufferEnd )
    {
      m_pBufferEnd = header.m_pBufferEnd;
      v3 = psock;
      v13 = 0;
      m_nBitsAvail = 1;
      m_pDataIn = header.m_pDataIn + 1;
      header.m_nBitsAvail = 1;
      header.m_nInBufWord = 0;
      ++header.m_pDataIn;
      header.m_bOverflow = true;
      m_nInBufWord_low = 0;
    }
    else if ( header.m_pDataIn <= header.m_pBufferEnd )
    {
      v13 = *header.m_pDataIn;
      m_pDataIn = header.m_pDataIn + 1;
      header.m_nInBufWord = *header.m_pDataIn++;
      if ( !header.m_bOverflow )
      {
        v37 = v13 & CBitBuffer::s_nMaskTable[v15];
        m_nBitsAvail = 32 - v15;
        v13 >>= v15;
        m_pBufferEnd = header.m_pBufferEnd;
        m_nInBufWord_low = (v37 << SLOBYTE(header.m_nBitsAvail)) | m_nInBufWord;
        v3 = psock;
        header.m_nBitsAvail = 32 - v15;
LABEL_35:
        header.m_nInBufWord = v13;
        goto LABEL_36;
      }
      m_pBufferEnd = header.m_pBufferEnd;
      v3 = psock;
      m_nInBufWord_low = 0;
    }
    else
    {
      m_pBufferEnd = header.m_pBufferEnd;
      v3 = psock;
      v13 = 0;
      header.m_bOverflow = true;
      header.m_nInBufWord = 0;
      m_nInBufWord_low = 0;
    }
LABEL_36:
    if ( m_nBitsAvail < 32 )
    {
      v16 = 32 - m_nBitsAvail;
      v17 = v13;
      if ( m_pDataIn == m_pBufferEnd )
      {
        header.m_nBitsAvail = 1;
        header.m_nInBufWord = 0;
        header.m_pDataIn = m_pDataIn + 1;
        header.m_bOverflow = true;
        v37 = 0;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v18 = *m_pDataIn;
        header.m_nInBufWord = *m_pDataIn;
        header.m_pDataIn = m_pDataIn + 1;
        if ( header.m_bOverflow )
        {
          v37 = 0;
        }
        else
        {
          v19 = (v18 & CBitBuffer::s_nMaskTable[v16]) << m_nBitsAvail;
          header.m_nBitsAvail = m_nBitsAvail;
          v37 = v19 | v17;
          header.m_nInBufWord = v18 >> v16;
        }
      }
      else
      {
        header.m_bOverflow = true;
        header.m_nInBufWord = 0;
        v37 = 0;
      }
      v3 = psock;
    }
    else
    {
      header.m_nBitsAvail = m_nBitsAvail - 32;
      if ( m_nBitsAvail == 32 )
      {
        header.m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          header.m_nBitsAvail = 1;
          header.m_nInBufWord = 0;
          header.m_pDataIn = m_pDataIn + 1;
          v37 = v13;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            header.m_nInBufWord = *m_pDataIn;
            header.m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            header.m_bOverflow = true;
            header.m_nInBufWord = 0;
          }
          v37 = v13;
        }
      }
      else
      {
        header.m_nInBufWord = 0;
        v37 = v13;
      }
    }
    bOK = false;
    if ( m_nInBufWord_low != 4 )
      goto LABEL_73;
    v20 = GetCurrentThreadId();
    if ( v20 != s_NetChannels.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, v20, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: v20, a3: 0);
    }
    else
    {
      ++s_NetChannels.m_depth;
    }
    v21 = 0;
    if ( s_NetChannels.m_Size <= 0 )
      goto LABEL_69;
    while ( 1 )
    {
      v22 = s_NetChannels.m_Memory.m_pMemory[v21];
      v23 = v22->GetSocket(this: v22);
      v24 = psock;
      if ( v23 == psock->netsock )
      {
        v25 = v22->GetChallengeNr(this: v22);
        if ( v37 != v25 || v22->m_StreamSocket != 0 )
          goto LABEL_64;
        if ( netadr_s::CompareAdr(this: &v24->addr, a: &v22->remote_address, onlyBase: true) )
          break;
        v26 = netadr_s::ToString(this: &v24->addr, baseOnly: false);
        _Msg(a1: "TCP <- %s: IP address mismatch.\n", v26);
      }
LABEL_64:
      if ( ++v21 >= s_NetChannels.m_Size )
        goto LABEL_69;
    }
    v27 = psock;
    v28 = v22->__vftable;
    v22->m_StreamSocket = psock->newsock;
    ResetStreaming = v28->ResetStreaming;
    v22->m_StreamActive = true;
    ResetStreaming(this: v22);
    bOK = true;
    if ( net_showtcp.m_pParent != nullptr && net_showtcp.m_pParent->m_Value.m_nValue != 0 )
    {
      v30 = netadr_s::ToString(this: &v27->addr, baseOnly: false);
      _Msg(a1: "TCP <- %s: connection accepted\n", v30);
    }
LABEL_69:
    if ( --s_NetChannels.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
    if ( !bOK )
    {
      v3 = psock;
LABEL_73:
      v31 = netadr_s::ToString(this: &v3->addr, baseOnly: false);
      _Msg(a1: "TCP <- %s: invalid connection request.\n", v31);
      if ( v3->newsock != 0 )
      {
        if ( closesocket(s: v3->newsock) == -1 )
        {
          net_error = WSAGetLastError();
          v32 = NET_ErrorString(code: net_error);
          ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v32);
        }
        g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
      }
    }
    if ( s_PendingSockets.m_Size - i - 1 > 0 )
      _V_memmove(
        dest: (char *)s_PendingSockets.m_Memory.m_pMemory + v35,
        src: (char *)&s_PendingSockets.m_Memory.m_pMemory[1] + v35,
        count: 24 * (s_PendingSockets.m_Size - i - 1));
    v1 = i;
    v2 = v35;
LABEL_80:
    --s_PendingSockets.m_Size;
LABEL_81:
    ++v1;
    v2 += 24;
    i = v1;
    v35 = v2;
  }
  while ( v1 < s_PendingSockets.m_Size );
LABEL_82:
  if ( --s_PendingSockets.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_PendingSockets.CThreadFastMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B6820
// Name: void NET_CloseAllSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_CloseAllSockets()
{
  int v0; // edi
  netsocket_t *m_pMemory; // eax
  int v2; // esi
  const char *v3; // eax
  const char *v4; // eax
  DWORD CurrentThreadId; // ecx
  int v6; // edi
  int v7; // esi
  const char *v8; // eax

  v0 = 0;
  if ( net_sockets.m_Size > 0 )
  {
    m_pMemory = net_sockets.m_Memory.m_pMemory;
    v2 = 0;
    do
    {
      if ( m_pMemory[v2].nPort != 0 )
      {
        if ( m_pMemory[v2].hUDP != 0 )
        {
          if ( closesocket(s: m_pMemory[v2].hUDP) == -1 )
          {
            net_error = WSAGetLastError();
            v3 = NET_ErrorString(code: net_error);
            ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v3);
          }
          g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
          m_pMemory = net_sockets.m_Memory.m_pMemory;
        }
        if ( m_pMemory[v2].hTCP != 0 )
        {
          if ( closesocket(s: m_pMemory[v2].hTCP) == -1 )
          {
            net_error = WSAGetLastError();
            v4 = NET_ErrorString(code: net_error);
            ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v4);
          }
          g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
          m_pMemory = net_sockets.m_Memory.m_pMemory;
        }
        m_pMemory[v2].nPort = 0;
        net_sockets.m_Memory.m_pMemory[v2].bListening = false;
        net_sockets.m_Memory.m_pMemory[v2].hUDP = 0;
        net_sockets.m_Memory.m_pMemory[v2].hTCP = 0;
        m_pMemory = net_sockets.m_Memory.m_pMemory;
      }
      ++v0;
      ++v2;
    }
    while ( v0 < net_sockets.m_Size );
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_PendingSockets.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_PendingSockets.CThreadFastMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_PendingSockets.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_PendingSockets.m_depth;
  }
  v6 = 0;
  if ( s_PendingSockets.m_Size > 0 )
  {
    v7 = 0;
    do
    {
      if ( s_PendingSockets.m_Memory.m_pMemory[v7].newsock != 0 )
      {
        if ( closesocket(s: s_PendingSockets.m_Memory.m_pMemory[v7].newsock) == -1 )
        {
          net_error = WSAGetLastError();
          v8 = NET_ErrorString(code: net_error);
          ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v8);
        }
        g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < s_PendingSockets.m_Size );
  }
  s_PendingSockets.m_Size = 0;
  g_pSteamSocketMgr->Shutdown(this: g_pSteamSocketMgr);
  g_pSteamSocketMgr->Init(this: g_pSteamSocketMgr);
  if ( --s_PendingSockets.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_PendingSockets.CThreadFastMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B69F0
// Name: void NET_RemoveAllExtraSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_RemoveAllExtraSockets()
{
  netsocket_t *m_pMemory; // edx
  int v1; // edi
  int v2; // esi
  const char *v3; // eax
  const char *v4; // eax

  m_pMemory = net_sockets.m_Memory.m_pMemory;
  v1 = 3;
  if ( net_sockets.m_Size > 3 )
  {
    v2 = 3;
    do
    {
      if ( m_pMemory[v2].nPort != 0 )
      {
        if ( m_pMemory[v2].hUDP != 0 )
        {
          if ( closesocket(s: m_pMemory[v2].hUDP) == -1 )
          {
            net_error = WSAGetLastError();
            v3 = NET_ErrorString(code: net_error);
            ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v3);
          }
          g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
          m_pMemory = net_sockets.m_Memory.m_pMemory;
        }
        if ( m_pMemory[v2].hTCP != 0 )
        {
          if ( closesocket(s: m_pMemory[v2].hTCP) == -1 )
          {
            net_error = WSAGetLastError();
            v4 = NET_ErrorString(code: net_error);
            ConMsg(a1: "WARNING! NET_CloseSocket: %s\n", v4);
          }
          g_pSteamSocketMgr->CloseSocket(this: g_pSteamSocketMgr, a2: -1);
          m_pMemory = net_sockets.m_Memory.m_pMemory;
        }
      }
      ++v1;
      ++v2;
    }
    while ( v1 < net_sockets.m_Size );
  }
  net_sockets.m_Size = 3;
}

//------------------------------------------------------------------------------
// Address: 0x101B6B10
// Name: public: void CTSQueue<struct loopback_t __near *,0,1>::PushItem(struct loopback_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<loopback_t *,0,1>::PushItem(CTSQueue<loopback_t *,0,1> *this, loopback_t **init)
{
  CTSQueue<loopback_t *,0,1>::Node_t *v3; // eax

  v3 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_FreeNodes);
  if ( v3 != nullptr || (v3 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
  {
    v3->elem = *init;
    CTSQueue<CFunctor *,0,1>::Push((CTSQueue<StartSoundParams_t,0,1> *)this, pNode: v3);
  }
  else
  {
    CTSQueue<CFunctor *,0,1>::Push((CTSQueue<StartSoundParams_t,0,1> *)this, pNode: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6DC0
// Name: void NET_SendLoopPacket(int,int,unsigned char const __near *,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_SendLoopPacket(loopback_t *sock, int length, const unsigned __int8 *data)
{
  loopback_t *v3; // ebx
  int v4; // edi
  loopback_t *v5; // eax
  loopback_t *v6; // esi
  char *defbuffer; // eax
  CTSQueue<loopback_t *,0,1>::Node_t *v8; // eax
  const unsigned __int8 *v9; // [esp-10h] [ebp-14h]

  v3 = sock;
  if ( (unsigned int)sock <= 1 )
  {
    v4 = length;
    if ( length <= 96000 )
    {
      v5 = (loopback_t *)CUtlMemoryPool::Alloc(this: &loopback_t::s_Allocator, amount: 0x808u);
      v6 = v5;
      sock = v5;
      if ( v4 > 2048 )
        defbuffer = (char *)MemAlloc_Alloc(nSize: v4);
      else
        defbuffer = v5->defbuffer;
      v9 = data;
      v6->data = defbuffer;
      _V_memcpy(dest: defbuffer, src: v9, count: v4);
      v6->datalen = v4;
      if ( v3 == (loopback_t *)1 )
      {
        v8 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &s_LoopBacks.m_FreeNodes);
        if ( v8 != nullptr || (v8 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
        {
          v8->elem = v6;
          CTSQueue<CFunctor *,0,1>::Push(this: &s_LoopBacks, pNode: v8);
        }
        else
        {
          CTSQueue<CFunctor *,0,1>::Push(this: &s_LoopBacks, pNode: nullptr);
        }
      }
      else if ( v3 != nullptr )
      {
        DevMsg(a1: "NET_SendLoopPacket:  invalid socket (%i).\n", v3);
      }
      else
      {
        CTSQueue<loopback_t *,0,1>::PushItem(this: &stru_1068BBC8, init: &sock);
      }
    }
    else
    {
      DevMsg(a1: "NET_SendLoopPacket:  packet too big (%i).\n", length);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6EB0
// Name: bool NET_GetLoopPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_GetLoopPacket(netpacket_s *packet)
{
  int source; // eax
  CTSQueue<int,0,1> *v3; // ebx
  CTSQueue<int,0,1>::Node_t *v4; // eax
  int elem; // esi
  int v6; // eax
  void *v7; // eax

  source = packet->source;
  if ( source > 1 )
    return 0;
  v3 = (CTSQueue<int,0,1> *)(&s_LoopBacks + source);
  v4 = CTSQueue<loopback_t *,0,1>::Pop(this: v3);
  if ( v4 == nullptr )
    return 0;
  elem = v4->elem;
  CTSListBase::Push(this: &v3->m_FreeNodes, pNode: (TSLNodeBase_t *)v4);
  if ( *(_DWORD *)(elem + 4) != 0 )
  {
    netadr_s::SetType(this: &packet->from, newtype: NA_LOOPBACK);
    v6 = *(_DWORD *)(elem + 4);
    packet->size = v6;
    packet->wiresize = *(_DWORD *)(elem + 4);
    _V_memcpy(dest: packet->data, src: *(const void **)elem, count: v6);
    v7 = *(void **)elem;
    *(_DWORD *)(elem + 4) = 0;
    if ( v7 != (void *)(elem + 8) )
    {
      free(pMem: v7);
      *(_DWORD *)elem = elem + 8;
    }
    CUtlMemoryPool::Free(this: &loopback_t::s_Allocator, memBlock: (void *)elem);
    return NET_LagPacket(newdata: true, packet);
  }
  else
  {
    CUtlMemoryPool::Free(this: &loopback_t::s_Allocator, memBlock: (void *)elem);
    return NET_LagPacket(newdata: false, packet);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6F70
// Name: void NET_ClearLoopbackBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ClearLoopbackBuffers()
{
  CTSQueue<int,0,1> *v0; // esi
  CTSQueue<int,0,1>::Node_t *v1; // eax
  CTSQueue<int,0,1>::Node_t *v2; // edi
  int DepthAndSequence; // ecx
  CTSListBase *p_m_FreeNodes; // esi
  CTSQueue<int,0,1>::Node_t *Next; // [esp-8h] [ebp-1Ch]
  CTSQueue<int,0,1>::Node_t *v6; // [esp-8h] [ebp-1Ch]
  int v7; // [esp-4h] [ebp-18h]
  loopback_t *loop; // [esp+Ch] [ebp-8h]
  CTSQueue<StartSoundParams_t,0,1> *v9; // [esp+10h] [ebp-4h]

  v0 = (CTSQueue<int,0,1> *)&s_LoopBacks;
  v9 = &s_LoopBacks;
  do
  {
    while ( 1 )
    {
      v1 = CTSQueue<loopback_t *,0,1>::Pop(this: v0);
      v2 = v1;
      if ( v1 == nullptr )
        break;
      DepthAndSequence = v0->m_FreeNodes.m_Head.value32.DepthAndSequence;
      p_m_FreeNodes = &v0->m_FreeNodes;
      loop = (loopback_t *)v1->elem;
      Next = (CTSQueue<int,0,1>::Node_t *)p_m_FreeNodes->m_Head.value.Next;
      v1->pNext = (CTSQueue<int,0,1>::Node_t *)p_m_FreeNodes->m_Head.value.Next;
      if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                              a1: p_m_FreeNodes,
                              a2: v1,
                              a3: DepthAndSequence + 65537,
                              a4: Next,
                              a5: DepthAndSequence) == 0 )
      {
        do
        {
          _mm_pause();
          v7 = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
          v6 = (CTSQueue<int,0,1>::Node_t *)p_m_FreeNodes->m_Head.value.Next;
          v2->pNext = (CTSQueue<int,0,1>::Node_t *)p_m_FreeNodes->m_Head.value.Next;
        }
        while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: p_m_FreeNodes, a2: v2, a3: v7 + 65537, a4: v6, a5: v7) == 0 );
      }
      if ( loop->data != nullptr && loop->data != loop->defbuffer )
        free(pMem: loop->data);
      CUtlMemoryPool::Free(this: &loopback_t::s_Allocator, memBlock: loop);
      v0 = (CTSQueue<int,0,1> *)v9;
    }
    v9 = (CTSQueue<StartSoundParams_t,0,1> *)++v0;
  }
  while ( (int)v0 < (int)&UNSPECIFIED_LOGGING_COLOR_115 );
}

//------------------------------------------------------------------------------
// Address: 0x101B7020
// Name: void NET_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_Shutdown()
{
  netpacket_s **v0; // ebx
  netpacket_s *v1; // esi
  netpacket_s *pNext; // edi
  int v3; // eax

  v0 = s_pLagData;
  do
  {
    v1 = *v0;
    if ( *v0 != nullptr )
    {
      do
      {
        pNext = v1->pNext;
        if ( v1->data != nullptr )
        {
          free(pMem: v1->data);
          v1->data = nullptr;
        }
        free(pMem: v1);
        v1 = pNext;
      }
      while ( pNext != nullptr );
    }
    *v0++ = nullptr;
  }
  while ( (int)v0 < (int)&net_multiplayer );
  g_pQueuedPackedSender->Shutdown(this: g_pQueuedPackedSender);
  net_multiplayer = false;
  net_dedicated = false;
  NET_CloseAllSockets();
  NET_ClearLoopbackBuffers();
  if ( !net_noip )
  {
    v3 = WSACleanup();
    if ( v3 != 0 )
      _Msg(a1: "Failed to complete WSACleanup = 0x%x.\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7150
// Name: class INetChannel __near * NET_CreateNetChannel(int,struct netadr_s __near *,char const __near *,class INetChannelHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CNetChan *__cdecl NET_CreateNetChannel(
        int socket,
        netadr_s *adr,
        const char *name,
        INetChannelHandler *handler,
        bool bForceNewChannel)
{
  CNetChan *NetChannel; // edi
  CNetChan *v6; // eax
  DWORD CurrentThreadId; // ecx
  int m_Size; // eax
  int v9; // esi
  CNetChan **m_pMemory; // ecx
  int v11; // eax
  CNetChan **v12; // eax

  if ( !bForceNewChannel && adr != nullptr && (NetChannel = NET_FindNetChannel(socket, adr)) != nullptr )
  {
    NetChannel->Clear(this: NetChannel);
  }
  else
  {
    v6 = (CNetChan *)MemAlloc_Alloc(nSize: 0x4268u);
    if ( v6 != nullptr )
      NetChannel = CNetChan::CNetChan(this: v6);
    else
      NetChannel = nullptr;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_NetChannels.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_NetChannels.m_depth;
    }
    m_Size = s_NetChannels.m_Size;
    v9 = s_NetChannels.m_Size;
    if ( s_NetChannels.m_Size + 1 > s_NetChannels.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&s_NetChannels,
        num: s_NetChannels.m_Size - s_NetChannels.m_Memory.m_nAllocationCount + 1);
      m_Size = s_NetChannels.m_Size;
    }
    m_pMemory = s_NetChannels.m_Memory.m_pMemory;
    s_NetChannels.m_Size = m_Size + 1;
    v11 = m_Size - v9;
    s_NetChannels.m_pElements = s_NetChannels.m_Memory.m_pMemory;
    if ( v11 > 0 )
    {
      _V_memmove(
        dest: &s_NetChannels.m_Memory.m_pMemory[v9 + 1],
        src: &s_NetChannels.m_Memory.m_pMemory[v9],
        count: 4 * v11);
      m_pMemory = s_NetChannels.m_Memory.m_pMemory;
    }
    v12 = &m_pMemory[v9];
    if ( v12 != nullptr )
      *v12 = NetChannel;
    if ( --s_NetChannels.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
  }
  if ( socket < 3 && s_pLagData[socket] != nullptr )
    NET_ClearLaggedList(pList: &s_pLagData[socket]);
  CNetChan::Setup(this: NetChannel, sock: socket, adr, name, handler);
  return NetChannel;
}

//------------------------------------------------------------------------------
// Address: 0x101B72A0
// Name: void NET_ProcessListen(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ProcessListen(int sock)
{
  int v1; // edi
  netsocket_t *v2; // eax
  SOCKET v3; // esi
  int Error; // eax
  const char *v5; // eax
  DWORD CurrentThreadId; // eax
  const char *v7; // eax
  pendingsocket_t psock; // [esp+4h] [ebp-30h] BYREF
  sockaddr sa; // [esp+1Ch] [ebp-18h] BYREF
  int nLengthAddr; // [esp+30h] [ebp-4h] BYREF

  v1 = sock;
  v2 = &net_sockets.m_Memory.m_pMemory[sock];
  if ( v2->bListening )
  {
    nLengthAddr = 16;
    v3 = accept(s: v2->hTCP, addr: &sa, addrlen: &nLengthAddr);
    if ( v3 == -1 )
    {
      Error = WSAGetLastError();
      net_error = Error;
      if ( Error != 10035 )
      {
        v5 = NET_ErrorString(code: Error);
        _ConDMsg(a1: "NET_ThreadListen: %s\n", v5);
      }
    }
    else
    {
      netadr_s::SetIP(this: &psock.addr, unIP: 0);
      netadr_s::SetPort(this: &psock.addr, newport: 0);
      netadr_s::SetType(this: &psock.addr, newtype: NA_IP);
      psock.newsock = v3;
      psock.netsock = v1;
      netadr_s::SetFromSockadr(this: &psock.addr, s: &sa);
      psock.time = net_time;
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != s_PendingSockets.m_ownerID
        && _InterlockedCompareExchange(
             (volatile signed __int32 *)&s_PendingSockets.CThreadFastMutex,
             CurrentThreadId,
             0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &s_PendingSockets.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++s_PendingSockets.m_depth;
      }
      CUtlVector<CEngineVoiceSteam::RemoteTalker_t,CUtlMemory<CEngineVoiceSteam::RemoteTalker_t,int>>::InsertBefore(
        this: (CUtlVector<CEngineVoiceSteam::RemoteTalker_t,CUtlMemory<CEngineVoiceSteam::RemoteTalker_t,int> > *)&s_PendingSockets,
        elem: s_PendingSockets.m_Size,
        src: (const CEngineVoiceSteam::RemoteTalker_t *)&psock);
      HIBYTE(sock) = 1;
      NET_SendStream(nSock: v3, buf: (const char *)&sock + 3, len: 1, flags: 0);
      if ( net_showtcp.m_pParent != nullptr && net_showtcp.m_pParent->m_Value.m_nValue != 0 )
      {
        v7 = netadr_s::ToString(this: &psock.addr, baseOnly: false);
        _Msg(a1: "TCP <- %s: connection request.\n", v7);
      }
      if ( --s_PendingSockets.m_depth == 0 )
        _InterlockedExchange((volatile __int32 *)&s_PendingSockets.CThreadFastMutex, 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7400
// Name: private: void CBindAddressHelper::BuildBindAddresses(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBindAddressHelper::BuildBindAddresses(
        CBindAddressHelper *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  _IP_ADAPTER_INFO *v2; // eax
  _IP_ADAPTER_INFO *v3; // edi
  const CUtlString *v4; // eax
  _IP_ADAPTER_INFO info_temp; // [esp+0h] [ebp-2A0h] BYREF
  CUtlString v6; // [esp+288h] [ebp-18h] BYREF
  _IP_ADAPTER_INFO *infos; // [esp+298h] [ebp-8h]
  unsigned int len; // [esp+29Ch] [ebp-4h] BYREF

  len = 0;
  if ( GetAdaptersInfo(AdapterInfo: &info_temp, SizePointer: &len) == 111 )
  {
    v2 = (_IP_ADAPTER_INFO *)MemAlloc_Alloc(nSize: (648 * (unsigned __int64)len) >> 32 != 0 ? -1 : 648 * len);
    v3 = v2;
    infos = v2;
    if ( v2 != nullptr )
    {
      if ( GetAdaptersInfo(AdapterInfo: v2, SizePointer: &len) == 0 )
      {
        do
        {
          if ( v3->Type != 24 && _V_strcmp(s1: v3->IpAddressList.IpAddress.String, s2: "0.0.0.0") != 0 )
          {
            _Msg(a1: "NET_GetBindAddresses found %s: '%s'\n", v3->IpAddressList.IpAddress.String, v3->Description);
            v4 = CUtlString::CUtlString(this: &v6, pString: v3->IpAddressList.IpAddress.String);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: list, elem: list->m_Size, src: v4);
            v6.m_Storage.m_nActualLength = 0;
            if ( v6.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v6.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6.m_Storage.m_Memory.m_pMemory);
                v6.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v6.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
          v3 = v3->Next;
        }
        while ( v3 != nullptr );
        v3 = infos;
      }
      free(pMem: v3);
    }
    else
    {
      Sys_Error(error: "BuildBindAddresses:  Out of memory allocating %d bytes\n", 648 * len);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7520
// Name: void NET_RunFrame(double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_RunFrame(long double realtime)
{
  CRConServer *v2; // eax
  CRConServer *v3; // eax
  CRConClient *v4; // eax
  CRConClient *v5; // eax
  int v6; // esi
  netsocket_t *m_pMemory; // eax
  int v8; // edi
  double realtimea; // [esp+8h] [ebp+8h]

  realtimea = realtime - s_last_realtime;
  s_last_realtime = realtime;
  if ( realtimea <= 1.0 )
  {
    if ( realtimea < 0.0 )
      realtimea = 0.0;
  }
  else
  {
    realtimea = 1.0;
  }
  net_time = ((double (__thiscall *)(IEngineToolInternal *))g_pEngineToolInternal->GetTimescale)(a1: g_pEngineToolInternal)
           * realtimea
           + net_time;
  v2 = RCONServer();
  CRConServer::RunFrame(this: v2);
  v3 = RPTServer();
  CRConServer::RunFrame(this: v3);
  Con_RunFrame();
  v4 = RCONClient();
  CRConClient::RunFrame(this: v4);
  v5 = RPTClient();
  CRConClient::RunFrame(this: v5);
  if ( g_pMatchFramework != nullptr )
    g_pMatchFramework->RunFrame(this: g_pMatchFramework);
  if ( net_multiplayer && !net_notcp )
  {
    v6 = 0;
    if ( net_sockets.m_Size > 0 )
    {
      m_pMemory = net_sockets.m_Memory.m_pMemory;
      v8 = 0;
      do
      {
        if ( m_pMemory[v8].hTCP != 0 && m_pMemory[v8].bListening )
        {
          NET_ProcessListen(sock: v6);
          m_pMemory = net_sockets.m_Memory.m_pMemory;
        }
        ++v6;
        ++v8;
      }
      while ( v6 < net_sockets.m_Size );
    }
    NET_ProcessPending();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7620
// Name: class CSplitPacketEntry __near * NET_FindOrCreateSplitPacketEntry(int,struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitPacketEntry *__cdecl NET_FindOrCreateSplitPacketEntry(const int sock, netadr_s *from)
{
  CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int> > *v2; // esi
  int v3; // ebx
  const netadr_s *p_from; // edi
  int v5; // edx
  int v6; // eax
  int v7; // edi
  int m_nAllocationCount; // eax
  CSplitPacketEntry *m_pMemory; // ecx
  int v10; // eax
  unsigned __int8 *v11; // edi
  _DWORD v13[24182]; // [esp+Ch] [ebp-179DCh] BYREF
  int m_Size; // [esp+179E4h] [ebp-4h]
  int v15; // [esp+179F0h] [ebp+8h]

  v2 = &net_splitpackets.m_Memory.m_pMemory[sock];
  v3 = 0;
  m_Size = v2->m_Size;
  if ( m_Size > 0 )
  {
    v15 = 0;
    while ( 1 )
    {
      p_from = &v2->m_Memory.m_pMemory[v15].from;
      if ( netadr_s::CompareAdr(this: from, a: p_from, onlyBase: false) )
        break;
      ++v15;
      if ( ++v3 >= m_Size )
        goto LABEL_7;
    }
    if ( v3 < m_Size )
      return (CSplitPacketEntry *)p_from;
  }
LABEL_7:
  netadr_s::SetIP(this: (netadr_s *)v13, unIP: 0);
  netadr_s::SetPort(this: (netadr_s *)v13, newport: 0);
  netadr_s::SetType(this: (netadr_s *)v13, newtype: NA_IP);
  memset(v13, 0, 12);
  memset(&v13[3], 0xFFu, 0x2A8u);
  memset(&v13[173], 0, 96036);
  v5 = *(_DWORD *)from->ip;
  v6 = *(_DWORD *)&from->port;
  v7 = v2->m_Size;
  v13[0] = from->type;
  v13[2] = v6;
  m_nAllocationCount = v2->m_Memory.m_nAllocationCount;
  v13[1] = v5;
  if ( v7 + 1 > m_nAllocationCount )
    CUtlMemory<CSplitPacketEntry,int>::Grow(this: &v2->m_Memory, num: v7 - m_nAllocationCount + 1);
  ++v2->m_Size;
  m_pMemory = v2->m_Memory.m_pMemory;
  v10 = v2->m_Size - v7 - 1;
  v2->m_pElements = v2->m_Memory.m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 96728 * v10);
  v11 = (unsigned __int8 *)&v2->m_Memory.m_pMemory[v7];
  if ( v11 != nullptr )
    memcpy(dst: v11, src: (unsigned __int8 *)v13, count: 0x179D8u);
  return &v2->m_Memory.m_pMemory[v2->m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x101B7790
// Name: bool NET_GetLong(int,struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_GetLong(void *sock, netpacket_s *packet)
{
  CSplitPacketEntry *SplitPacketEntry; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 *data; // ecx
  unsigned int v7; // edx
  int v8; // eax
  unsigned int v9; // edi
  int v10; // ecx
  const char *v11; // eax
  unsigned int v12; // edx
  int m_nValue; // ecx
  const char *v14; // eax
  const char *v15; // eax
  unsigned int v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  int v20; // [esp-18h] [ebp-28h]
  unsigned int v21; // [esp-14h] [ebp-24h]
  int v22; // [esp-14h] [ebp-24h]
  int v23; // [esp-10h] [ebp-20h]
  int v24; // [esp-10h] [ebp-20h]
  int v25; // [esp-Ch] [ebp-1Ch]
  const char *v26; // [esp-Ch] [ebp-1Ch]
  int nSplitSizeMinusHeader; // [esp+4h] [ebp-Ch]
  unsigned int size; // [esp+8h] [ebp-8h]
  int packetCount; // [esp+Ch] [ebp-4h]
  int sequenceNumber; // [esp+1Ch] [ebp+Ch]

  if ( packet->size < 0xCu )
  {
    _Msg(a1: "Invalid split packet length %i\n", packet->size);
    return 0;
  }
  SplitPacketEntry = NET_FindOrCreateSplitPacketEntry((const int)sock, from: &packet->from);
  v5 = (unsigned __int8 *)SplitPacketEntry;
  if ( SplitPacketEntry == nullptr )
    return 0;
  SplitPacketEntry->lastactivetime = net_time;
  data = packet->data;
  sequenceNumber = *((_DWORD *)data + 1);
  v7 = (unsigned __int8)*((_WORD *)data + 4);
  v8 = *((__int16 *)data + 5);
  v9 = *((__int16 *)data + 4) >> 8;
  packetCount = v7;
  nSplitSizeMinusHeader = v8;
  if ( (unsigned int)(v8 - 564) > 0x270 )
  {
    v22 = *((__int16 *)data + 5);
    v20 = (unsigned __int8)*((_WORD *)data + 4);
    v19 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Split packet from %s with invalid split size (number %i/ count %i) where size %i is out of valid range [%d - %d ]\n",
      v19,
      v9,
      v20,
      v22,
      564,
      1188);
    return 0;
  }
  if ( v9 >= 0xAA || v7 > 0xAA )
  {
    v24 = (unsigned __int8)*((_WORD *)data + 4);
    v18 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Split packet from %s with too many split parts (number %i/ count %i) where %i is max count allowed\n",
      v18,
      v9,
      v24,
      170);
    return 0;
  }
  v10 = *((_DWORD *)v5 + 173);
  if ( v10 == -1 || sequenceNumber != v10 )
  {
    *((_DWORD *)v5 + 173) = sequenceNumber;
    *((_DWORD *)v5 + 174) = v7;
    *((_DWORD *)v5 + 176) = v8;
  }
  if ( *((_DWORD *)v5 + 176) != v8 )
  {
    v25 = *((_DWORD *)v5 + 176);
    v23 = v8;
    v21 = v7;
    v11 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Split packet from %s with inconsistent split size (number %i/ count %i) where size %i not equal to i"
      "nitial size of %i\n",
      v11,
      v9,
      v21,
      v23,
      v25);
    return 0;
  }
  size = packet->size - 12;
  if ( *(_DWORD *)&v5[4 * v9 + 12] == sequenceNumber )
  {
    v15 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Ignoring duplicated split packet %i of %i ( %i bytes ) from %s\n",
      v9 + 1,
      packetCount,
      size,
      v15);
    goto LABEL_21;
  }
  v12 = v7 - 1;
  if ( v9 == v12 )
    *((_DWORD *)v5 + 175) = size + v8 * v12;
  --*((_DWORD *)v5 + 174);
  *(_DWORD *)&v5[4 * v9 + 12] = sequenceNumber;
  if ( net_showsplits.m_pParent != nullptr )
  {
    m_nValue = net_showsplits.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 && m_nValue != 3 )
    {
      v26 = netadr_s::ToString(this: &packet->from, baseOnly: false);
      v14 = DescribeSocket(sock);
      _Msg(
        a1: "<-- [%s] Split packet %4i/%4i seq %5i size %4i mtu %4i from %s\n",
        v14,
        v9 + 1,
        packetCount,
        sequenceNumber,
        size,
        nSplitSizeMinusHeader + 12,
        v26);
LABEL_21:
      v8 = nSplitSizeMinusHeader;
    }
  }
  memcpy(dst: &v5[v9 * v8 + 708], src: packet->data + 12, count: size);
  if ( *((int *)v5 + 174) > 0 )
    return 0;
  v16 = *((_DWORD *)v5 + 175);
  *((_DWORD *)v5 + 173) = -1;
  if ( v16 <= 0x17710 )
  {
    _V_memcpy(dest: packet->data, src: v5 + 708, count: v16);
    packet->size = *((_DWORD *)v5 + 175);
    packet->wiresize = *((_DWORD *)v5 + 175);
    return 1;
  }
  else
  {
    v17 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(a1: "Split packet too large! %d bytes from %s\n", *((_DWORD *)v5 + 175), v17);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7A20
// Name: bool NET_ReceiveDatagram(int,struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_ReceiveDatagram(void *sock, netpacket_s *packet)
{
  int source; // eax
  unsigned __int8 *data; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // esi
  unsigned __int8 *v8; // edx
  int v9; // eax
  int v10; // ebx
  signed int v11; // esi
  const char *v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // esi
  unsigned int ActualSize; // eax
  unsigned int v16; // eax
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // ebx
  unsigned int v20; // esi
  int v21; // eax
  int v22; // ebx
  int v23; // esi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v26; // edx
  int v27; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int v30; // eax
  const unsigned int *v31; // ecx
  const unsigned int *v32; // edx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  unsigned __int16 v35; // ax
  char v36; // bl
  const char *v37; // eax
  int Error; // eax
  const char *v39; // eax
  unsigned int v40; // [esp-4h] [ebp-2074h]
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v41; // [esp+Ch] [ebp-2064h] BYREF
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v42; // [esp+101Ch] [ebp-1054h] BYREF
  sockaddr s; // [esp+202Ch] [ebp-44h] BYREF
  netadr_s v44; // [esp+203Ch] [ebp-34h] BYREF
  int v45; // [esp+2048h] [ebp-28h] BYREF
  unsigned int v46; // [esp+2050h] [ebp-20h]
  bf_write v47; // [esp+2054h] [ebp-1Ch] BYREF
  unsigned int unBufSize; // [esp+206Ch] [ebp-4h]
  int v49; // [esp+207Ch] [ebp+Ch]

  source = packet->source;
  data = packet->data;
  v5 = 0;
  v45 = 16;
  v6 = g_pSteamSocketMgr->recvfrom(
         this: g_pSteamSocketMgr,
         a2: net_sockets.m_Memory.m_pMemory[source].hUDP,
         a3: (char *)data,
         a4: 96016,
         a5: 0,
         a6: &s,
         a7: &v45);
  v7 = v6;
  if ( v6 <= 0 )
  {
    if ( v6 == -1 )
    {
      Error = WSAGetLastError();
      net_error = Error;
      switch ( Error )
      {
        case 10035:
        case 10054:
        case 10061:
          return 0;
        default:
          v39 = NET_ErrorString(code: Error);
          _ConDMsg(a1: "NET_ReceivePacket: %s\n", v39);
          break;
      }
    }
  }
  else
  {
    packet->wiresize = v6;
    v42.m_pMemory = v42.m_pFixedMemory;
    v42.m_nAllocationCount = 4096;
    v42.m_nGrowSize = -1;
    v42.m_nMallocGrowSize = 4096;
    v49 = 0;
    if ( net_dedicatedForXbox )
    {
      v8 = packet->data;
      v9 = *(unsigned __int16 *)v8;
      if ( (_WORD)v9 != 0xFFFF )
      {
        v10 = *(unsigned __int16 *)v8;
        v11 = v7 - v9 - 2;
        unBufSize = v11;
        if ( v11 > 0 )
        {
          if ( voice_verbose.m_pParent != nullptr && voice_verbose.m_pParent->m_Value.m_nValue != 0 )
          {
            netadr_s::SetIP(this: &v44, unIP: 0);
            netadr_s::SetPort(this: &v44, newport: 0);
            netadr_s::SetType(this: &v44, newtype: NA_IP);
            netadr_s::SetFromSockadr(this: &v44, &s);
            v12 = netadr_s::ToString(this: &v44, baseOnly: false);
            _Msg(a1: "* NET_ReceiveDatagram: receiving voice from %s (%d bytes)\n", v12, v11);
          }
          v13 = packet->data;
          v49 = *(unsigned __int16 *)&v13[v10 + 2];
          v14 = &v13[v10 + 4];
          v47.m_pDebugName = (const char *)4096;
          if ( CLZSS::IsCompressed(this: (CLZSS *)&v47.m_iCurBit, pInput: v14) )
          {
            ActualSize = CLZSS::GetActualSize(this: (CLZSS *)&v47.m_iCurBit, pInput: v14);
            unBufSize = ActualSize;
            if ( ActualSize != (unsigned int)(v49 + 7) >> 3 )
              goto LABEL_11;
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v42, num: ActualSize);
            v16 = CLZSS::SafeUncompress(this: (CLZSS *)&v47.m_iCurBit, pInput: v14, pOutput: v42.m_pMemory, unBufSize);
            if ( v16 != unBufSize )
              goto LABEL_11;
          }
          else
          {
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v42, num: unBufSize);
            _V_memcpy(dest: v42.m_pMemory, src: v14, count: unBufSize);
          }
        }
        _V_memmove(dest: packet->data, src: packet->data + 2, count: v10);
        v7 = v10;
        v5 = 0;
      }
    }
    netadr_s::SetFromSockadr(this: &packet->from, &s);
    packet->size = v7;
    if ( v7 < 96016 )
    {
      if ( *(_DWORD *)packet->data != -2 || NET_GetLong(sock, packet) != 0 )
      {
        v18 = packet->data;
        if ( *(_DWORD *)v18 != -3 )
          goto LABEL_22;
        v19 = v18 + 4;
        v47.m_pDebugName = (const char *)4096;
        v20 = CLZSS::GetActualSize(this: (CLZSS *)&v47.m_iCurBit, pInput: v18 + 4);
        if ( v20 - 1 <= 0x176FF )
        {
          v41.m_pMemory = v41.m_pFixedMemory;
          v41.m_nAllocationCount = 4096;
          v41.m_nGrowSize = -1;
          v41.m_nMallocGrowSize = 4096;
          CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v41, num: v20);
          v21 = CLZSS::SafeUncompress(
                  this: (CLZSS *)&v47.m_iCurBit,
                  pInput: v19,
                  pOutput: v41.m_pMemory,
                  unBufSize: v20);
          v22 = v21;
          if ( v21 == 0 || v20 != v21 )
          {
            CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v41);
            CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v42);
            return 0;
          }
          _V_memcpy(dest: packet->data, src: v41.m_pMemory, count: v21);
          packet->size = v22;
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v41);
          v5 = 0;
LABEL_22:
          if ( v49 == 0 )
          {
LABEL_50:
            v36 = NET_LagPacket(newdata: true, packet);
            CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v42);
            return v36;
          }
          v23 = 8 * packet->size - (packet->data[8] >> 5);
          if ( !ShouldChecksumPackets() )
          {
LABEL_46:
            bf_write::bf_write(this: &v47);
            CNetworkStringTable::SetTick(this: &v47, pDebugName: "X360 Fixup");
            bf_write::StartWriting(this: &v47, pData: packet->data, nBytes: 96016, iStartBit: v23, nBits: -1);
            bf_write::WriteBits(this: &v47, pInData: v42.m_pMemory, nBits: v49);
            if ( (unsigned int)(v47.m_iCurBit % 8 - 1) <= 1 )
              bf_write::WriteUBitLong(this: &v47, curData: 0, numbits: 6, bCheckRange: true);
            packet->size = (v47.m_iCurBit + 7) >> 3;
            if ( ShouldChecksumPackets() )
            {
              CEngine::SetNextState(this: &v47, bitPos: 72);
              v35 = BufferToShortChecksum(pvData: packet->data + 11, nLength: packet->size - 11);
              bf_write::WriteUBitLong(this: &v47, curData: v35, numbits: 16, bCheckRange: true);
            }
            goto LABEL_50;
          }
          CBitRead::Seek(this: &packet->message, nPosition: 72);
          m_nBitsAvail = packet->message.m_nBitsAvail;
          if ( m_nBitsAvail >= 16 )
          {
            m_nInBufWord = packet->message.m_nInBufWord;
            v26 = (unsigned __int16)m_nInBufWord;
            v27 = m_nBitsAvail - 16;
            packet->message.m_nBitsAvail = v27;
            if ( v27 != 0 )
            {
              packet->message.m_nInBufWord = HIWORD(m_nInBufWord);
              v5 = (unsigned __int16)m_nInBufWord;
            }
            else
            {
              m_pDataIn = packet->message.m_pDataIn;
              m_pBufferEnd = packet->message.m_pBufferEnd;
              packet->message.m_nBitsAvail = 32;
              if ( m_pDataIn == m_pBufferEnd )
              {
                packet->message.m_nInBufWord = 0;
                packet->message.m_nBitsAvail = 1;
                packet->message.m_pDataIn = m_pDataIn + 1;
                v5 = v26;
              }
              else
              {
                if ( m_pDataIn <= m_pBufferEnd )
                {
                  packet->message.m_nInBufWord = *m_pDataIn;
                  packet->message.m_pDataIn = m_pDataIn + 1;
                }
                else
                {
                  packet->message.m_nInBufWord = 0;
                  packet->message.m_bOverflow = true;
                }
                v5 = v26;
              }
            }
LABEL_42:
            CBitRead::Seek(this: &packet->message, nPosition: 0);
            v40 = packet->size - 11;
            if ( (unsigned int)(packet->size - 12) > 0x176FF )
            {
              ConMsg(a1: "corrupted packet detected (checksumbytes %d)\n", v40);
              CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v42);
              return 0;
            }
            if ( BufferToShortChecksum(pvData: packet->data + 11, nLength: v40) != v5 )
            {
              ConMsg(a1: "corrupted packet detected\n");
              CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v42);
              return 0;
            }
            goto LABEL_46;
          }
          v30 = 16 - m_nBitsAvail;
          v31 = packet->message.m_pDataIn;
          v46 = packet->message.m_nInBufWord;
          v32 = packet->message.m_pBufferEnd;
          if ( v31 == v32 )
          {
            packet->message.m_nBitsAvail = 1;
            packet->message.m_nInBufWord = 0;
            packet->message.m_bOverflow = true;
          }
          else
          {
            if ( v31 > v32 )
            {
              packet->message.m_bOverflow = true;
              packet->message.m_nInBufWord = 0;
              goto LABEL_40;
            }
            packet->message.m_nInBufWord = *v31;
          }
          packet->message.m_pDataIn = v31 + 1;
LABEL_40:
          if ( !packet->message.m_bOverflow )
          {
            v33 = packet->message.m_nInBufWord;
            v34 = (v33 & CBitBuffer::s_nMaskTable[v30]) << packet->message.m_nBitsAvail;
            packet->message.m_nBitsAvail = 32 - v30;
            unBufSize = v34;
            v5 = v34 | v46;
            packet->message.m_nInBufWord = v33 >> v30;
          }
          goto LABEL_42;
        }
      }
LABEL_11:
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v42);
      return 0;
    }
    v37 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _ConDMsg(a1: "NET_ReceiveDatagram:  Oversize packet from %s\n", v37);
    if ( v42.m_nGrowSize >= 0 && v42.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42.m_pMemory);
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B7FE0
// Name: struct netpacket_s __near * NET_GetPacket(int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
netpacket_s *__cdecl NET_GetPacket(int sock, unsigned __int8 *scratch)
{
  netpacket_s *v3; // esi

  if ( sock < 0 || sock >= net_packets.m_Size )
    return nullptr;
  v3 = &net_packets.m_Memory.m_pMemory[sock];
  NET_AdjustLag();
  NET_DiscardStaleSplitpackets(sock);
  netadr_s::SetType(this: &v3->from, newtype: NA_IP);
  netadr_s::Clear(this: &v3->from);
  v3->received = net_time;
  v3->source = sock;
  v3->data = scratch;
  v3->size = 0;
  v3->wiresize = 0;
  v3->pNext = nullptr;
  v3->message.m_pDebugName = "inpacket.message";
  if ( NET_GetLoopPacket(packet: v3) == 0
    && (!net_multiplayer
     || NET_ReceiveDatagram((void *)sock, packet: v3) == 0 && NET_LagPacket(newdata: false, packet: v3) == 0) )
  {
    return nullptr;
  }
  CBitRead::StartReading(this: &v3->message, pData: v3->data, nBytes: v3->size, iStartBit: 0, nBits: -1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101B80A0
// Name: void NET_ProcessSocket(int,class IConnectionlessPacketHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ProcessSocket(int sock, IConnectionlessPacketHandler *handler)
{
  DWORD CurrentThreadId; // ecx
  int i; // edi
  CNetChan *v4; // esi
  int v5; // eax
  TSLHead_t m_Head; // kr00_8
  TSLNodeBase_t *Next; // eax
  unsigned __int8 *v8; // eax
  netpacket_s *Packet; // esi
  int m_nBitsAvail; // eax
  int v11; // eax
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v14; // edx
  int v15; // ecx
  const unsigned int *v16; // eax
  const char *v17; // eax
  CNetChan *NetChannel; // eax
  TSLNodeBase_t **v19; // esi
  int size; // [esp-Ch] [ebp-1Ch]
  int v21; // [esp-Ch] [ebp-1Ch]
  int v22; // [esp-Ch] [ebp-1Ch]
  int v23; // [esp-8h] [ebp-18h]
  TSLHead_t v24; // [esp-8h] [ebp-18h]
  TSLHead_t v25; // [esp-8h] [ebp-18h]
  int wiresize; // [esp-4h] [ebp-14h]
  net_scratchbuffer_t *pNetBuffer; // [esp+Ch] [ebp-4h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_NetChannels.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_NetChannels.m_depth;
  }
  for ( i = s_NetChannels.m_Size - 1; i >= 0; --i )
  {
    v4 = s_NetChannels.m_Memory.m_pMemory[i];
    if ( sock == v4->GetSocket(this: v4) && !v4->ProcessStream(this: v4) )
    {
      v5 = (int)v4->GetMsgHandler(this: v4);
      (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 12))(a1: v5, a2: "TCP connection failed.");
    }
  }
  if ( --s_NetChannels.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
  m_Head = g_NetScratchBuffers.m_Head;
  if ( g_NetScratchBuffers.m_Head.value.Next != nullptr )
  {
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &g_NetScratchBuffers,
                               a2: m_Head.value.Next->Next,
                               a3: m_Head.value32.DepthAndSequence - 1,
                               a4: m_Head.value.Next,
                               a5: m_Head.value32.DepthAndSequence) == 0 )
    {
      _mm_pause();
      m_Head = g_NetScratchBuffers.m_Head;
      if ( g_NetScratchBuffers.m_Head.value.Next == nullptr )
        goto LABEL_15;
    }
    Next = m_Head.value.Next;
  }
  else
  {
LABEL_15:
    Next = (TSLNodeBase_t *)MemAlloc_Alloc(nSize: 0x17718u);
  }
  v8 = (unsigned __int8 *)(&Next->Next + 1);
  pNetBuffer = (net_scratchbuffer_t *)v8;
  if ( v8 == nullptr )
  {
    v8 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x17710u);
    pNetBuffer = (net_scratchbuffer_t *)v8;
  }
  Packet = NET_GetPacket(sock, scratch: v8);
  if ( Packet != nullptr )
  {
    while ( Filter_ShouldDiscard(adr: &Packet->from) )
    {
      Filter_SendBan(adr: &Packet->from);
LABEL_47:
      Packet = NET_GetPacket(sock, scratch: pNetBuffer->buf);
      if ( Packet == nullptr )
        goto LABEL_48;
    }
    if ( *(_DWORD *)Packet->data != -1 )
    {
      NetChannel = NET_FindNetChannel(socket: sock, adr: &Packet->from);
      if ( NetChannel != nullptr )
        NetChannel->ProcessPacket(this: NetChannel, a2: Packet, a3: true);
      goto LABEL_47;
    }
    m_nBitsAvail = Packet->message.m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      v11 = m_nBitsAvail - 32;
      Packet->message.m_nBitsAvail = v11;
      if ( v11 != 0 )
      {
        Packet->message.m_nInBufWord = 0;
      }
      else
      {
        m_pDataIn = Packet->message.m_pDataIn;
        Packet->message.m_nBitsAvail = 32;
        m_pBufferEnd = Packet->message.m_pBufferEnd;
        if ( m_pDataIn == m_pBufferEnd )
        {
          Packet->message.m_nBitsAvail = 1;
          Packet->message.m_nInBufWord = 0;
          Packet->message.m_pDataIn = m_pDataIn + 1;
        }
        else if ( m_pDataIn <= m_pBufferEnd )
        {
          Packet->message.m_nInBufWord = *m_pDataIn;
          Packet->message.m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          Packet->message.m_bOverflow = true;
          Packet->message.m_nInBufWord = 0;
        }
      }
LABEL_39:
      if ( net_showudp.m_pParent != nullptr
        && net_showudp.m_pParent->m_Value.m_nValue != 0
        && net_showudp_oob.m_pParent != nullptr
        && net_showudp_oob.m_pParent->m_Value.m_nValue != 0 )
      {
        wiresize = Packet->wiresize;
        v23 = Packet->data[4];
        size = Packet->size;
        v17 = netadr_s::ToString(this: &Packet->from, baseOnly: false);
        _Msg(a1: "UDP <- %s: sz=%d OOB '0x%02X' wire=%d\n", v17, size, v23, wiresize);
      }
      handler->ProcessConnectionlessPacket(this: handler, a2: Packet);
      goto LABEL_47;
    }
    v14 = Packet->message.m_pBufferEnd;
    v15 = 32 - m_nBitsAvail;
    v16 = Packet->message.m_pDataIn;
    if ( v16 == v14 )
    {
      Packet->message.m_nBitsAvail = 1;
      Packet->message.m_nInBufWord = 0;
      Packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v16 > v14 )
      {
        Packet->message.m_bOverflow = true;
        Packet->message.m_nInBufWord = 0;
        goto LABEL_37;
      }
      Packet->message.m_nInBufWord = *v16;
    }
    Packet->message.m_pDataIn = v16 + 1;
LABEL_37:
    if ( !Packet->message.m_bOverflow )
    {
      Packet->message.m_nInBufWord >>= v15;
      Packet->message.m_nBitsAvail = 32 - v15;
    }
    goto LABEL_39;
  }
LABEL_48:
  v24 = g_NetScratchBuffers.m_Head;
  v21 = g_NetScratchBuffers.m_Head.value32.DepthAndSequence + 65537;
  v19 = (TSLNodeBase_t **)&pNetBuffer[-1].buf[96012];
  *(_DWORD *)&pNetBuffer[-1].buf[96012] = g_NetScratchBuffers.m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: &g_NetScratchBuffers,
                          a2: &pNetBuffer[-1].buf[96012],
                          a3: v21,
                          a4: v24.value.Next,
                          a5: v24.value32.DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      v25 = g_NetScratchBuffers.m_Head;
      v22 = g_NetScratchBuffers.m_Head.value32.DepthAndSequence + 65537;
      *v19 = g_NetScratchBuffers.m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &g_NetScratchBuffers,
                               a2: v19,
                               a3: v22,
                               a4: v25.value.Next,
                               a5: v25.value32.DepthAndSequence) == 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8380
// Name: public: void CBindAddressHelper::GetBindAddresses(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBindAddressHelper::GetBindAddresses(
        CBindAddressHelper *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  CBindAddressHelper *v2; // edi
  CUtlString *m_pMemory; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const CUtlString *v7; // ebx
  CUtlString *v8; // ecx
  int v9; // eax
  CUtlString *v10; // edi
  int i; // [esp+8h] [ebp-4h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *lista; // [esp+14h] [ebp+8h]

  v2 = this;
  if ( !this->m_bInitialized )
  {
    this->m_bInitialized = true;
    CBindAddressHelper::BuildBindAddresses(this, list: &this->m_CachedAddresses);
  }
  i = 0;
  if ( v2->m_CachedAddresses.m_Size > 0 )
  {
    lista = nullptr;
    while ( 1 )
    {
      m_pMemory = v2->m_CachedAddresses.m_Memory.m_pMemory;
      m_Size = list->m_Size;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      v7 = (CUtlString *)((char *)m_pMemory + (_DWORD)lista);
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CPortalRect,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)list,
          num: m_Size - m_nAllocationCount + 1);
      ++list->m_Size;
      v8 = list->m_Memory.m_pMemory;
      v9 = list->m_Size - m_Size - 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[m_Size + 1], src: &v8[m_Size], count: 16 * v9);
      v10 = &list->m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        CUtlString::CUtlString(this: v10, string: v7);
      lista = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)((char *)lista + 16);
      if ( ++i >= this->m_CachedAddresses.m_Size )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8570
// Name: NET_QueuePacketForSend
// Source: json
//------------------------------------------------------------------------------
int __usercall NET_QueuePacketForSend@<eax>(
        int len@<edi>,
        CNetChan *chan,
        unsigned int verbose,
        const char *s,
        const sockaddr *buf,
        const sockaddr *to,
        unsigned int tolen)
{
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v8; // esi

  if ( net_queued_packet_thread.m_pParent != nullptr
    && net_queued_packet_thread.m_pParent->m_Value.m_nValue != 0
    && g_pQueuedPackedSender->IsRunning(this: g_pQueuedPackedSender) )
  {
    g_pQueuedPackedSender->QueuePacket(
      this: g_pQueuedPackedSender,
      a2: chan,
      a3: verbose,
      a4: s,
      a5: len,
      a6: buf,
      a7: (int)to,
      a8: tolen);
    return len;
  }
  else
  {
    v8 = &g_SendQueue.m_SendQueue.m_Memory.m_pMemory[CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AddToTail(this: &g_SendQueue.m_SendQueue)];
    v8->m_Element.m_Socket = verbose;
    v8->m_Element.m_pChannel = chan;
    CUtlBuffer::Put(this: &v8->m_Element.m_Buffer, pMem: s, size: len);
    CUtlBuffer::Put(this: &v8->m_Element.m_To, pMem: buf, size: (int)to);
    CNetChan::IncrementQueuedPackets(this: v8->m_Element.m_pChannel);
    return len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8610
// Name: NET_SendLong
// Source: json
//------------------------------------------------------------------------------
int __usercall NET_SendLong@<eax>(
        INetChannel *chan@<eax>,
        int sock,
        unsigned int s,
        char *buf,
        int len,
        const sockaddr *to,
        const sockaddr *tolen,
        int nMaxRoutableSize)
{
  CNetChan *v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // esi
  int v12; // ebx
  int m_nValue; // eax
  int v14; // edi
  int v15; // eax
  int result; // eax
  int v17; // eax
  const char *v18; // eax
  int v19; // [esp-18h] [ebp-50Ch]
  int v20; // [esp-14h] [ebp-508h]
  const char *v21; // [esp-8h] [ebp-4FCh]
  char packet[1200]; // [esp+Ch] [ebp-4E8h] BYREF
  netadr_s adr; // [esp+4BCh] [ebp-38h] BYREF
  int v24[2]; // [esp+4C8h] [ebp-2Ch]
  int v25; // [esp+4D0h] [ebp-24h]
  float flMaxSplitpacketDataRateBytesPerSecond; // [esp+4D4h] [ebp-20h]
  int v27; // [esp+4D8h] [ebp-1Ch]
  int nFragmentsSent; // [esp+4DCh] [ebp-18h]
  void *src; // [esp+4E0h] [ebp-14h]
  int nSequenceNumber; // [esp+4E4h] [ebp-10h]
  int nTotalBytesSent; // [esp+4E8h] [ebp-Ch]
  int nBytesLeft; // [esp+4ECh] [ebp-8h]
  CNetChan *netchan; // [esp+4F0h] [ebp-4h]

  v8 = (CNetChan *)__RTDynamicCast(
                     inptr: chan,
                     VfDelta: 0,
                     SrcType: &INetChannel `RTTI Type Descriptor',
                     TargetType: &CNetChan `RTTI Type Descriptor',
                     isReference: 0);
  netchan = v8;
  if ( v8 != nullptr )
    v9 = CNetChan::IncrementSplitPacketSequence(this: v8);
  else
    v9 = _InterlockedIncrement(&s_SplitPacketSequenceNumber[sock]);
  v10 = (__int16)(nMaxRoutableSize - 12);
  nSequenceNumber = v9;
  *(_WORD *)&packet[10] = nMaxRoutableSize - 12;
  v11 = len;
  *(_DWORD *)&packet[4] = v9;
  v12 = 0;
  *(_DWORD *)packet = -2;
  v27 = v10;
  nBytesLeft = len;
  v25 = (v10 + len - 1) / v10;
  nTotalBytesSent = 0;
  nFragmentsSent = 0;
  if ( len <= 0 )
    return nTotalBytesSent;
  src = buf;
  while ( 1 )
  {
    if ( v10 < v11 )
      v11 = v10;
    *(_WORD *)&packet[8] = v25 + ((_WORD)v12 << 8);
    _V_memcpy(dest: &packet[12], src, count: v11);
    if ( v8 != nullptr
      && (net_splitrate.m_pParent == nullptr ? (m_nValue = 0) : (m_nValue = net_splitrate.m_pParent->m_Value.m_nValue),
          nFragmentsSent >= m_nValue
       || net_queued_packet_thread.m_pParent != nullptr
       && net_queued_packet_thread.m_pParent->m_Value.m_nValue == 581304) )
    {
      v14 = net_splitpacket_maxrate.m_pParent != nullptr ? net_splitpacket_maxrate.m_pParent->m_Value.m_nValue : 0;
      if ( (float)v14 <= (float)netchan->GetDataRate(this: netchan) )
        v15 = net_splitpacket_maxrate.m_pParent != nullptr ? net_splitpacket_maxrate.m_pParent->m_Value.m_nValue : 0;
      else
        v15 = netchan->GetDataRate(this: netchan);
      flMaxSplitpacketDataRateBytesPerSecond = (float)v15;
      *(_QWORD *)v24 = (__int64)((double)(v12 * (nMaxRoutableSize + 28)) / (float)v15 * 1000.0 + 0.5);
      result = NET_QueuePacketForSend(
                 len: v11 + 12,
                 chan: netchan,
                 verbose: s,
                 s: packet,
                 buf: to,
                 to: tolen,
                 tolen: v24[0]);
    }
    else if ( *(_DWORD *)&to->sa_data[2] != 0 || *(_WORD *)to->sa_data != 0 )
    {
      if ( (CL_IsHL2Demo() || CL_IsPortalDemo()) && !net_dedicated )
        _Error(a1: defaultValue);
      result = NET_SendToImpl(s, buf: packet, len: v11 + 12, to, (int)tolen, iGameDataLength: -1);
    }
    else
    {
      result = v11 + 12;
    }
    ++nFragmentsSent;
    if ( result < 0 )
      break;
    if ( result >= v11 )
      nTotalBytesSent += v11;
    src = (char *)src + v27;
    nBytesLeft -= v11;
    ++v12;
    if ( net_showsplits.m_pParent != nullptr )
    {
      v17 = net_showsplits.m_pParent->m_Value.m_nValue;
      if ( v17 != 0 && v17 != 2 )
      {
        netadr_s::SetIP(this: &adr, unIP: 0);
        netadr_s::SetPort(this: &adr, newport: 0);
        netadr_s::SetType(this: &adr, newtype: NA_IP);
        netadr_s::SetFromSockadr(this: &adr, s: to);
        v21 = netadr_s::ToString(this: &adr, baseOnly: false);
        v20 = nSequenceNumber;
        v19 = v25;
        v18 = DescribeSocket((void *)sock);
        _Msg(
          a1: "--> [%s] Split packet %4i/%4i seq %5i size %4i mtu %4i to %s [ total %4i ]\n",
          v18,
          v12,
          v19,
          v20,
          v11,
          nMaxRoutableSize,
          v21,
          len);
      }
    }
    if ( nBytesLeft <= 0 )
      return nTotalBytesSent;
    v11 = nBytesLeft;
    v8 = netchan;
    v10 = v27;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B88D0
// Name: int NET_SendPacket(class INetChannel __near *,int,struct netadr_s const __near &,unsigned char const __near *,int,class bf_write __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NET_SendPacket(
        CNetChan *chan,
        int sock,
        netadr_s *to,
        unsigned __int8 *data,
        int length,
        bf_write *pVoicePayload,
        bool bUseCompression,
        unsigned int unMillisecondsDelay)
{
  int v8; // edi
  netadr_s *v9; // esi
  const char *v10; // eax
  IUniformRandomStream *m_pMemory; // ecx
  int m_nValue; // eax
  float m_fValue; // xmm0_4
  int v15; // ebx
  unsigned __int8 *v16; // ebx
  void *v17; // ebx
  int m_iCurBit; // eax
  unsigned __int8 *m_pData; // ecx
  int v20; // edi
  int v21; // esi
  int v22; // eax
  int v23; // eax
  int v24; // esi
  int Error; // eax
  const char *v26; // eax
  int v27; // [esp-4h] [ebp-2060h]
  const char *v28; // [esp+4h] [ebp-2058h]
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v29; // [esp+Ch] [ebp-2050h] BYREF
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v30; // [esp+101Ch] [ebp-1040h] BYREF
  sockaddr s; // [esp+202Ch] [ebp-30h] BYREF
  CLZSS v32; // [esp+203Ch] [ebp-20h] BYREF
  unsigned __int8 *v33; // [esp+2048h] [ebp-14h]
  unsigned int pOutputSize; // [esp+204Ch] [ebp-10h] BYREF
  int tolen; // [esp+2050h] [ebp-Ch]
  bool verbose[4]; // [esp+2054h] [ebp-8h]
  unsigned int m_fValue_low; // [esp+2058h] [ebp-4h] BYREF

  v8 = length;
  if ( net_showudp.m_pParent == nullptr
    || net_showudp.m_pParent->m_Value.m_nValue == 0
    || *(_DWORD *)data != -1
    || net_showudp_oob.m_pParent == nullptr
    || net_showudp_oob.m_pParent->m_Value.m_nValue == 0 )
  {
    v9 = to;
    goto LABEL_14;
  }
  if ( net_showudp_remoteonly.m_pParent == nullptr || net_showudp_remoteonly.m_pParent->m_Value.m_nValue == 0 )
  {
    v9 = to;
LABEL_12:
    v27 = data[4];
    v10 = netadr_s::ToString(this: v9, baseOnly: false);
    _Msg(a1: "UDP -> %s: sz=%d OOB '0x%02X'\n", v10, length, v27);
    goto LABEL_14;
  }
  v9 = to;
  if ( !netadr_s::IsLocalhost(this: to) && !netadr_s::IsLoopback(this: to) )
    goto LABEL_12;
LABEL_14:
  if ( !net_multiplayer
    || v9->type == NA_LOOPBACK
    || netadr_s::IsLocalhost(this: v9)
    && (net_usesocketsforloopback.m_pParent == nullptr || net_usesocketsforloopback.m_pParent->m_Value.m_nValue == 0) )
  {
    NET_SendLoopPacket((loopback_t *)sock, length, data);
    return length;
  }
  if ( v9->type == NA_BROADCAST )
  {
    m_pMemory = (IUniformRandomStream *)(2 * sock);
    *(_DWORD *)verbose = net_sockets.m_Memory.m_pMemory[sock].hUDP;
    if ( *(_DWORD *)verbose == 0 )
      return length;
  }
  else
  {
    if ( v9->type != NA_IP )
    {
      DevMsg(a1: "NET_SendPacket: bad address type (%i)\n", v9->type);
      return length;
    }
    m_pMemory = (IUniformRandomStream *)net_sockets.m_Memory.m_pMemory;
    *(_DWORD *)verbose = net_sockets.m_Memory.m_pMemory[sock].hUDP;
    if ( *(_DWORD *)verbose == 0 )
      return length;
  }
  if ( droppackets.m_pParent != nullptr )
  {
    m_nValue = droppackets.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 && sock == 0 )
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&droppackets.IConVar, value: m_nValue + 1);
      return length;
    }
  }
  m_fValue = fakeloss.m_pParent->m_Value.m_fValue;
  if ( m_fValue > 0.0 )
  {
    m_fValue_low = LODWORD(fakeloss.m_pParent->m_Value.m_fValue);
    if ( _RandomInt(this: m_pMemory, a2: 0, a3: 100) <= (int)m_fValue )
      return length;
  }
  netadr_s::ToSockadr(this: v9, &s);
  v30.m_pMemory = v30.m_pFixedMemory;
  v30.m_nAllocationCount = 4096;
  v30.m_nGrowSize = -1;
  v30.m_nMallocGrowSize = 4096;
  v29.m_pMemory = v29.m_pFixedMemory;
  v29.m_nAllocationCount = 4096;
  v29.m_nGrowSize = -1;
  v29.m_nMallocGrowSize = 4096;
  tolen = length;
  if ( pVoicePayload == nullptr )
    tolen = -1;
  v15 = 0;
  if ( pVoicePayload != nullptr )
  {
    CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(
      this: &v29,
      num: ((pVoicePayload->m_iCurBit + 7) >> 3) + 2);
    v16 = v29.m_pMemory;
    *(_WORD *)v29.m_pMemory = pVoicePayload->m_iCurBit;
    v17 = v16 + 2;
    pOutputSize = (pVoicePayload->m_iCurBit + 7) >> 3;
    if ( net_compressvoice.m_pParent == nullptr
      || net_compressvoice.m_pParent->m_Value.m_nValue == 0
      || (m_iCurBit = pVoicePayload->m_iCurBit,
          m_pData = pVoicePayload->m_pData,
          v32.m_nWindowSize = 4096,
          CLZSS::CompressNoAlloc(
            this: &v32,
            pInput: m_pData,
            inputLength: (m_iCurBit + 7) >> 3,
            pOutputBuf: (unsigned __int8 *)v17,
            &pOutputSize) == nullptr) )
    {
      _V_memcpy(dest: v17, src: pVoicePayload->m_pData, count: (pVoicePayload->m_iCurBit + 7) >> 3);
    }
    v15 = pOutputSize + 2;
  }
  if ( voice_xsend_debug.m_pParent != nullptr && voice_xsend_debug.m_pParent->m_Value.m_nValue != 0 && v15 != 0 )
    DevMsg(a1: "XVoice: voice data payload for %p: %d bytes\n", chan, v15);
  if ( bUseCompression
    && (v32.m_nWindowSize = 4096,
        m_fValue_low = length,
        CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v30, num: v15 + length + 4),
        *(_DWORD *)v30.m_pMemory = -3,
        CLZSS::CompressNoAlloc(
          this: &v32,
          pInput: data,
          inputLength: length,
          pOutputBuf: v30.m_pMemory + 4,
          pOutputSize: &m_fValue_low) != nullptr) )
  {
    v20 = m_fValue_low + 4;
    data = v30.m_pMemory;
    if ( pVoicePayload != nullptr && pVoicePayload->m_iCurBit > 0 )
      _V_memcpy(dest: &v30.m_pMemory[v20], src: v29.m_pMemory, count: v15);
    tolen = v20;
    v8 = v15 + v20;
  }
  else if ( pVoicePayload != nullptr && pVoicePayload->m_iCurBit > 0 )
  {
    CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v30, num: v15 + length);
    v33 = v30.m_pMemory;
    _V_memcpy(dest: v30.m_pMemory, src: data, count: length);
    _V_memcpy(dest: &v33[length], src: v29.m_pMemory, count: v15);
    data = v30.m_pMemory;
    v8 = v15 + length;
  }
  v21 = 1200;
  if ( chan != nullptr )
  {
    if ( sv_maxroutable.m_pParent != nullptr )
    {
      v21 = sv_maxroutable.m_pParent->m_Value.m_nValue;
      if ( v21 >= 1200 )
        v21 = 1200;
    }
    else
    {
      v21 = 0;
    }
    v22 = chan->GetMaxRoutablePayloadSize(this: chan);
    if ( v22 >= 576 )
    {
      if ( v22 <= v21 )
        v21 = v22;
    }
    else
    {
      v21 = 576;
    }
  }
  if ( unMillisecondsDelay == 0 )
    goto LABEL_63;
  if ( v8 > v21 )
  {
    _Warning(a1: "Can't delay send a packet larger than maxroutable size %d/%d\n", v8, v21);
LABEL_63:
    if ( v8 > v21
      || net_queued_packet_thread.m_pParent != nullptr
      && net_queued_packet_thread.m_pParent->m_Value.m_nValue == 581304
      && chan != nullptr )
    {
      v23 = NET_SendLong(
              chan,
              sock,
              s: *(unsigned int *)verbose,
              buf: (char *)data,
              len: v8,
              to: &s,
              tolen: (const sockaddr *)0x10,
              nMaxRoutableSize: v21);
    }
    else
    {
      v23 = NET_SendTo(
              len: v8,
              to: &s,
              verbose: *(unsigned int *)verbose,
              s: (char *)data,
              buf: (const char *)0x10,
              tolen);
    }
    goto LABEL_70;
  }
  v23 = NET_QueuePacketForSend(
          len: v8,
          chan,
          verbose: *(unsigned int *)verbose,
          s: (const char *)data,
          buf: &s,
          to: (const sockaddr *)0x10,
          tolen: unMillisecondsDelay);
LABEL_70:
  v24 = v23;
  if ( v23 == -1 )
  {
    Error = WSAGetLastError();
    net_error = Error;
    if ( Error == 10035 || Error == 10054 || Error == 10049 && to->type == NA_BROADCAST )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v29);
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v30);
      return 0;
    }
    v28 = netadr_s::ToString(this: to, baseOnly: false);
    v26 = NET_ErrorString(code: net_error);
    _ConDMsg(a1: "NET_SendPacket Warning: %s : %s\n", v26, v28);
    v24 = v8;
  }
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v29);
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&v30);
  return v24;
}

//------------------------------------------------------------------------------
// Address: 0x101B8DC0
// Name: void NET_OutOfBandPrintf(int,struct netadr_s const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void NET_OutOfBandPrintf(int sock, netadr_s *adr, const char *format, ...)
{
  int v3; // eax
  char string[1200]; // [esp+0h] [ebp-4B0h] BYREF
  va_list params; // [esp+4C4h] [ebp+14h] BYREF

  va_start(params, format);
  *(_DWORD *)string = -1;
  V_vsnprintf(pDest: &string[4], maxLen: 1196, pFormat: format, params);
  v3 = _V_strlen(str: &string[4]);
  NET_SendPacket(
    chan: nullptr,
    sock,
    to: adr,
    data: (unsigned __int8 *)string,
    length: v3 + 5,
    pVoicePayload: nullptr,
    bUseCompression: false,
    unMillisecondsDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B8E20
// Name: void NET_OutOfBandDelayedPrintf(int,struct netadr_s const __near &,unsigned int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void NET_OutOfBandDelayedPrintf(int sock, netadr_s *adr, unsigned int unMillisecondsDelay, const char *format, ...)
{
  int v4; // eax
  char string[1200]; // [esp+0h] [ebp-4B0h] BYREF
  va_list params; // [esp+4C8h] [ebp+18h] BYREF

  va_start(params, format);
  *(_DWORD *)string = -1;
  V_vsnprintf(pDest: &string[4], maxLen: 1196, pFormat: format, params);
  v4 = _V_strlen(str: &string[4]);
  NET_SendPacket(
    chan: nullptr,
    sock,
    to: adr,
    data: (unsigned __int8 *)string,
    length: v4 + 5,
    pVoicePayload: nullptr,
    bUseCompression: false,
    unMillisecondsDelay);
}

//------------------------------------------------------------------------------
// Address: 0x101B8E90
// Name: void NET_ClearQueuedPacketsForChannel(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_ClearQueuedPacketsForChannel(CNetChan *channel)
{
  unsigned __int16 m_Head; // di
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *m_pMemory; // eax
  unsigned int v3; // esi
  unsigned __int16 m_Next; // cx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v5; // esi
  unsigned __int16 n; // [esp+4h] [ebp-4h]

  m_Head = g_SendQueue.m_SendQueue.m_Head;
  if ( g_SendQueue.m_SendQueue.m_Head != 0xFFFF )
  {
    m_pMemory = g_SendQueue.m_SendQueue.m_Memory.m_pMemory;
    do
    {
      v3 = m_Head;
      m_Next = m_pMemory[v3].m_Next;
      n = m_Next;
      if ( m_pMemory[v3].m_Element.m_pChannel == channel )
      {
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
          this: &g_SendQueue.m_SendQueue,
          elem: m_Head);
        v5 = &g_SendQueue.m_SendQueue.m_Memory.m_pMemory[v3];
        if ( v5->m_Element.m_To.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_To.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_To.m_Memory.m_pMemory);
            v5->m_Element.m_To.m_Memory.m_pMemory = nullptr;
          }
          v5->m_Element.m_To.m_Memory.m_nAllocationCount = 0;
        }
        if ( v5->m_Element.m_Buffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_Buffer.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_Buffer.m_Memory.m_pMemory);
            v5->m_Element.m_Buffer.m_Memory.m_pMemory = nullptr;
          }
          v5->m_Element.m_Buffer.m_Memory.m_nAllocationCount = 0;
        }
        v5->m_Next = g_SendQueue.m_SendQueue.m_FirstFree;
        m_pMemory = g_SendQueue.m_SendQueue.m_Memory.m_pMemory;
        m_Next = n;
        g_SendQueue.m_SendQueue.m_FirstFree = m_Head;
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B90E0
// Name: OpenSocketInternal
// Source: json
//------------------------------------------------------------------------------
void __cdecl OpenSocketInternal(
        int nModule,
        int nSetPort,
        int nDefaultPort,
        const char *pName,
        unsigned int nProtocol,
        BOOL bTryAny)
{
  char *m_pszString; // eax
  const CUtlString *v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // esi
  int v11; // eax
  int *p_hTCP; // ebx
  int v13; // edi
  const char *v14; // eax
  const char *v15; // esi
  SOCKET v16; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecBindableAddresses; // [esp+Ch] [ebp-34h] BYREF
  CUtlString v18; // [esp+20h] [ebp-20h] BYREF
  int nSavePort; // [esp+30h] [ebp-10h]
  CUtlString *m_pMemory; // [esp+34h] [ebp-Ch]
  int v21; // [esp+38h] [ebp-8h]
  int port; // [esp+3Ch] [ebp-4h] BYREF

  memset(&vecBindableAddresses, 0, sizeof(vecBindableAddresses));
  if ( (ipname.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = ipname.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v7 = CUtlString::CUtlString(this: &v18, pString: m_pszString);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: &vecBindableAddresses, elem: 0, src: v7);
  v18.m_Storage.m_nActualLength = 0;
  if ( v18.m_Storage.m_Memory.m_nGrowSize >= 0 && v18.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18.m_Storage.m_Memory.m_pMemory);
  CBindAddressHelper::GetBindAddresses(this: &g_BindAddressHelper, list: &vecBindableAddresses);
  v8 = nSetPort;
  v9 = nSetPort;
  if ( nSetPort == 0 )
    v9 = nDefaultPort;
  v10 = nProtocol;
  if ( nProtocol == 6 )
  {
    v11 = 16 * nModule;
    v21 = 16 * nModule;
    p_hTCP = &net_sockets.m_Memory.m_pMemory[nModule].hTCP;
  }
  else
  {
    if ( nProtocol != 17 )
    {
      Sys_Error(error: "Unrecognized protocol type %d", nProtocol);
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecBindableAddresses);
      return;
    }
    v21 = 16 * nModule;
    p_hTCP = &net_sockets.m_Memory.m_pMemory[nModule].hUDP;
    v11 = 16 * nModule;
  }
  if ( *(int *)((char *)&net_sockets.m_Memory.m_pMemory->nPort + v11) != 0 )
  {
    _Msg(
      a1: "WARNING: NET_OpenSockets: %s port %i already open.\n",
      pName,
      *(int *)((char *)&net_sockets.m_Memory.m_pMemory->nPort + v11));
LABEL_31:
    if ( p_hTCP != nullptr )
      g_pSteamSocketMgr->OpenSocket(
        this: g_pSteamSocketMgr,
        a2: *p_hTCP,
        a3: nModule,
        a4: v8,
        a5: nDefaultPort,
        a6: pName,
        a7: v10,
        a8: bTryAny);
    goto LABEL_33;
  }
  v13 = 0;
  nSavePort = v9;
  if ( vecBindableAddresses.m_Size > 0 )
  {
    m_pMemory = vecBindableAddresses.m_Memory.m_pMemory;
    while ( 1 )
    {
      port = nSavePort;
      v14 = CUtlString::operator char const *(this: m_pMemory);
      v15 = v14;
      if ( v13 > 0 )
        _Msg(a1: "Trying to open socket on %s\n", v14);
      v16 = NET_OpenSocket(net_interface: v15, &port, protocol: nProtocol);
      *p_hTCP = v16;
      if ( v16 != 0 )
        break;
      if ( bTryAny )
      {
        port = -1;
        *p_hTCP = NET_OpenSocket(net_interface: v15, &port, protocol: nProtocol);
      }
      if ( *p_hTCP != 0 )
        break;
      ++m_pMemory;
      if ( ++v13 >= vecBindableAddresses.m_Size )
      {
        v9 = port;
        v10 = nProtocol;
        v11 = v21;
        goto LABEL_26;
      }
    }
    v9 = port;
    v10 = nProtocol;
    v11 = v21;
    goto LABEL_29;
  }
LABEL_26:
  if ( *p_hTCP != 0 )
  {
LABEL_29:
    v8 = nSetPort;
    *(int *)((char *)&net_sockets.m_Memory.m_pMemory->nPort + v11) = v9;
    goto LABEL_31;
  }
  Sys_Exit(error: "Couldn't allocate any %s IP port, tried %d addresses", pName, vecBindableAddresses.m_Size);
LABEL_33:
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecBindableAddresses);
  if ( vecBindableAddresses.m_Memory.m_nGrowSize >= 0 && vecBindableAddresses.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecBindableAddresses.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101B92F0
// Name: void NET_OpenSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_OpenSockets()
{
  int m_nValue; // eax
  int v1; // eax
  int v2; // eax

  if ( hostport.m_pParent != nullptr )
    m_nValue = hostport.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  OpenSocketInternal(
    nModule: 1,
    nSetPort: m_nValue,
    nDefaultPort: 27015,
    pName: "server",
    nProtocol: 0x11u,
    bTryAny: false);
  if ( clientport.m_pParent != nullptr )
    v1 = clientport.m_pParent->m_Value.m_nValue;
  else
    v1 = 0;
  OpenSocketInternal(nModule: 0, nSetPort: v1, nDefaultPort: 27015, pName: "client", nProtocol: 0x11u, bTryAny: true);
  if ( !net_nohltv )
  {
    if ( hltvport.m_pParent != nullptr )
      v2 = hltvport.m_pParent->m_Value.m_nValue;
    else
      v2 = 0;
    OpenSocketInternal(nModule: 2, nSetPort: v2, nDefaultPort: 27020, pName: "hltv", nProtocol: 0x11u, bTryAny: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9380
// Name: void NET_Config(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_Config()
{
  int v0; // eax
  CRConServer *v1; // eax
  CRConServer *v2; // eax
  const char *v3; // edx
  const char *v4; // ecx
  const char *v5; // eax
  const char *v6; // [esp-14h] [ebp-20h]
  const char *v7; // [esp-10h] [ebp-1Ch]
  int v8; // [esp-Ch] [ebp-18h]
  int nPort; // [esp-8h] [ebp-14h]
  const char *v10; // [esp-4h] [ebp-10h]
  netadr_s rconAddr; // [esp+0h] [ebp-Ch] BYREF

  NET_CloseAllSockets();
  net_time = 0.0;
  if ( net_multiplayer )
  {
    NET_ClearLoopbackBuffers();
    NET_GetLocalAddress();
    NET_OpenSockets();
    if ( net_dedicated
      || (v0 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v0 + 40))(a1: v0, a2: "-usercon") != 0) )
    {
      rconAddr = net_local_adr;
      netadr_s::SetPort(this: &rconAddr, newport: net_sockets.m_Memory.m_pMemory[1].nPort);
      v10 = netadr_s::ToString(this: &rconAddr, baseOnly: false);
      v1 = RCONServer();
      CRConServer::SetAddress(this: v1, pNetAddress: v10);
      v2 = RCONServer();
      CRConServer::CreateSocket(this: v2);
    }
  }
  else
  {
    NET_ClearLoopbackBuffers();
  }
  v3 = "Yes";
  if ( !net_dedicated )
    v3 = "No";
  v4 = "MP";
  if ( !net_multiplayer )
    v4 = "SP";
  nPort = net_sockets.m_Memory.m_pMemory->nPort;
  v8 = net_sockets.m_Memory.m_pMemory[1].nPort;
  v7 = v3;
  v6 = v4;
  v5 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
  _Msg(a1: "Network: IP %s, mode %s, dedicated %s, ports %i SV / %i CL\n", v5, v6, v7, v8, nPort);
}

//------------------------------------------------------------------------------
// Address: 0x101B9480
// Name: void NET_SetMultiplayer(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_SetMultiplayer(bool multiplayer)
{
  if ( net_noip && multiplayer )
  {
    _Msg(a1: "Warning! Multiplayer mode not available with -noip parameter.\n");
  }
  else if ( !net_dedicated || multiplayer )
  {
    if ( net_multiplayer != multiplayer )
    {
      net_multiplayer = multiplayer;
      NET_Config();
    }
    if ( !multiplayer )
      NET_ClearLoopbackBuffers();
  }
  else
  {
    _Msg(a1: "Warning! Singleplayer mode not available on dedicated server.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B94F0
// Name: void NET_Init(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall NET_Init(int a1@<edi>, bool bIsDedicated)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // edi
  netpacket_s **v10; // esi
  int v11; // eax
  const char *v12; // eax
  int v13; // eax
  int v14; // eax
  IMatchTitle *v15; // eax
  char v16; // al
  bool v17; // bl
  netsocket_t *v18; // [esp-28h] [ebp-1C0h]
  WSAData wsaData; // [esp+8h] [ebp-190h] BYREF

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-nodns") != 0 )
    net_nodns = true;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-usetcp") != 0 )
    net_notcp = false;
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-nohltv") != 0 )
    net_nohltv = true;
  v5 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-noip") != 0 )
    goto LABEL_10;
  if ( WSAStartup(wVersionRequested: 2u, lpWSAData: &wsaData) != 0 )
  {
    ConMsg(a1: "Error! Failed to load network socket library.\n");
LABEL_10:
    net_noip = true;
  }
  net_time = 0.0;
  v6 = _CommandLine();
  v7 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v6 + 28))(a1: v6, a2: "-port", a3: -1);
  if ( v7 != -1
    || (v8 = _CommandLine(),
        (v7 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v8 + 28))(a1: v8, a2: "+port", a3: -1)) != -1) )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&hostport.IConVar, value: v7);
  }
  if ( net_sockets.m_Size < 3 )
    CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int>>::InsertMultipleBefore(
      this: &net_sockets,
      elem: net_sockets.m_Size,
      num: 3 - net_sockets.m_Size);
  if ( net_packets.m_Size < 3 )
    CUtlVector<netpacket_s,CUtlMemory<netpacket_s,int>>::InsertMultipleBefore(
      this: &net_packets,
      elem: net_packets.m_Size,
      num: 3 - net_packets.m_Size);
  if ( net_splitpackets.m_Size < 3 )
    CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,int> > *)&net_splitpackets,
      elem: net_splitpackets.m_Size,
      num: 3 - net_splitpackets.m_Size);
  v9 = 0;
  v10 = s_pLagData;
  do
  {
    v18 = &net_sockets.m_Memory.m_pMemory[v9];
    *v10 = nullptr;
    _V_memset(dest: v18, fill: 0, count: 16);
    ++v10;
    ++v9;
  }
  while ( (int)v10 < (int)&net_multiplayer );
  v11 = _CommandLine();
  v12 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD, int))(*(_DWORD *)v11 + 32))(
                        a1: v11,
                        a2: "-ip",
                        a3: 0,
                        a4: a1);
  if ( v12 != nullptr )
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&ipname.IConVar, value: v12);
  if ( bIsDedicated )
  {
    if ( net_noip )
    {
      _Msg(a1: "Warning! Dedicated not possible with -noip parameter.\n");
    }
    else
    {
      net_dedicated = true;
      v13 = _CommandLine();
      net_dedicatedForXbox = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v13 + 40))(a1: v13, a2: "-xlsp") != 0;
      v14 = _CommandLine();
      net_dedicatedForXboxInsecure = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(
                                       a1: v14,
                                       a2: "-xlsp_insecure") != 0;
    }
  }
  else
  {
    NET_ClearLoopbackBuffers();
  }
  NET_InitParanoidMode();
  v15 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  v16 = v15->GetTitleSettingsFlags(this: v15);
  v17 = (v16 & 1) != 0;
  if ( net_noip && (v16 & 1) != 0 )
  {
    _Msg(a1: "Warning! Multiplayer mode not available with -noip parameter.\n");
  }
  else if ( !net_dedicated || (v16 & 1) != 0 )
  {
    if ( net_multiplayer != v17 )
    {
      net_multiplayer = (v16 & 1) != 0;
      NET_Config();
    }
    if ( !v17 )
      NET_ClearLoopbackBuffers();
  }
  else
  {
    _Msg(a1: "Warning! Singleplayer mode not available on dedicated server.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9770
// Name: net_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_start()
{
  net_multiplayer = true;
  NET_Config();
}

//------------------------------------------------------------------------------
// Address: 0x101B9780
// Name: void NET_RemoveNetChannel(class INetChannel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_RemoveNetChannel(CNetChan *netchan, bool bDeleteNetChan)
{
  CNetChan *v2; // esi
  DWORD CurrentThreadId; // ecx
  int v4; // eax

  v2 = netchan;
  if ( netchan != nullptr )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != s_NetChannels.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_NetChannels.CThreadFastMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_NetChannels.CThreadFastMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++s_NetChannels.m_depth;
    }
    v4 = 0;
    if ( s_NetChannels.m_Size <= 0 )
      goto LABEL_11;
    while ( s_NetChannels.m_Memory.m_pMemory[v4] != v2 )
    {
      if ( ++v4 >= s_NetChannels.m_Size )
        goto LABEL_11;
    }
    if ( v4 == -1 )
    {
LABEL_11:
      _DevMsg(a1: 1, a2: "NET_CloseNetChannel: unknown channel.\n");
      if ( --s_NetChannels.m_depth != 0 )
        return;
      goto LABEL_16;
    }
    netchan = v2;
    CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_NetChannels,
      src: (vgui::TreeNode **)&netchan);
    NET_ClearQueuedPacketsForChannel(channel: v2);
    if ( bDeleteNetChan )
      ((void (__thiscall *)(CNetChan *, int))v2->dtr_INetChannel)(a1: v2, a2: 1);
    if ( --s_NetChannels.m_depth == 0 )
LABEL_16:
      _InterlockedExchange((volatile __int32 *)&s_NetChannels.CThreadFastMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10313730
// Name: _dynamic_initializer_for__net_earliertempents__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_earliertempents__()
{
  ConVar::ConVar(this: &net_earliertempents, pName: "net_earliertempents", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__net_earliertempents__);
}

//------------------------------------------------------------------------------
// Address: 0x10317240
// Name: _dynamic_initializer_for__net_megasnapshot__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_megasnapshot__()
{
  ConVar::ConVar(this: &net_megasnapshot, pName: "net_megasnapshot", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__net_megasnapshot__);
}

//------------------------------------------------------------------------------
// Address: 0x103174D0
// Name: _dynamic_initializer_for__net_showreliablesounds__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showreliablesounds__()
{
  ConVar::ConVar(this: &net_showreliablesounds, pName: "net_showreliablesounds", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__net_showreliablesounds__);
}

//------------------------------------------------------------------------------
// Address: 0x10319F30
// Name: _dynamic_initializer_for__net_showevents__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showevents__()
{
  ConVar::ConVar(
    this: &net_showevents,
    pName: "net_showevents",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Dump game events to console (1=client only, 2=all).");
  return atexit(func: dynamic_atexit_destructor_for__net_showevents__);
}

//------------------------------------------------------------------------------
// Address: 0x10319F60
// Name: _dynamic_initializer_for__net_showeventlisteners__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showeventlisteners__()
{
  ConVar::ConVar(
    this: &net_showeventlisteners,
    pName: "net_showeventlisteners",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show listening addition/removals");
  return atexit(func: dynamic_atexit_destructor_for__net_showeventlisteners__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A000
// Name: _dynamic_initializer_for__net_dumpeventstats_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_dumpeventstats_command__()
{
  ConCommand::ConCommand(
    this: &net_dumpeventstats_command,
    pName: "net_dumpeventstats",
    callback: net_dumpeventstats,
    pHelpString: "Dumps out a report of game event network usage",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__net_dumpeventstats_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C7D0
// Name: _dynamic_initializer_for__net_showtcp__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showtcp__()
{
  ConVar::ConVar(
    this: &net_showtcp,
    pName: "net_showtcp",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Dump TCP stream summary to console");
  return atexit(func: dynamic_atexit_destructor_for__net_showtcp__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C800
// Name: _dynamic_initializer_for__net_blocksize__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_blocksize__()
{
  ConVar::ConVar(
    this: &net_blocksize,
    pName: "net_maxfragments",
    pDefaultValue: "1200",
    flags: 0,
    pHelpString: "Max fragment bytes per packet",
    bMin: true,
    fMin: 256.0,
    bMax: true,
    fMax: 1200.0);
  return atexit(func: dynamic_atexit_destructor_for__net_blocksize__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C900
// Name: _dynamic_initializer_for__net_showdrop__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showdrop__()
{
  ConVar::ConVar(
    this: &net_showdrop,
    pName: "net_showdrop",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Show dropped packets in console");
  return atexit(func: dynamic_atexit_destructor_for__net_showdrop__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C930
// Name: _dynamic_initializer_for__net_drawslider__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_drawslider__()
{
  ConVar::ConVar(
    this: &net_drawslider,
    pName: "net_drawslider",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw completion slider during signon");
  return atexit(func: dynamic_atexit_destructor_for__net_drawslider__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C960
// Name: _dynamic_initializer_for__net_chokeloopback__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_chokeloopback__()
{
  ConVar::ConVar(
    this: &net_chokeloopback,
    pName: "net_chokeloop",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Apply bandwidth choke to loopback packets");
  return atexit(func: dynamic_atexit_destructor_for__net_chokeloopback__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C990
// Name: _dynamic_initializer_for__net_maxfilesize__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_maxfilesize__()
{
  ConVar::ConVar(
    this: &net_maxfilesize,
    pName: "net_maxfilesize",
    pDefaultValue: "16",
    flags: 0,
    pHelpString: "Maximum allowed file size for uploading in MB",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 64.0);
  return atexit(func: dynamic_atexit_destructor_for__net_maxfilesize__);
}

//------------------------------------------------------------------------------
// Address: 0x1031C9D0
// Name: _dynamic_initializer_for__net_compresspackets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_compresspackets__()
{
  ConVar::ConVar(
    this: &net_compresspackets,
    pName: "net_compresspackets",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Use lz compression on game packets.");
  return atexit(func: dynamic_atexit_destructor_for__net_compresspackets__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CA30
// Name: _dynamic_initializer_for__net_maxcleartime__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_maxcleartime__()
{
  ConVar::ConVar(
    this: &net_maxcleartime,
    pName: "net_maxcleartime",
    pDefaultValue: "4.0",
    flags: 0,
    pHelpString: "Max # of seconds we can wait for next packets to be sent based on rate setting (0 == no limit).");
  return atexit(func: dynamic_atexit_destructor_for__net_maxcleartime__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CA60
// Name: _dynamic_initializer_for__net_dumptest__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_dumptest__()
{
  ConVar::ConVar(this: &net_dumptest, pName: "net_dumptest", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__net_dumptest__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CA90
// Name: _dynamic_initializer_for__net_paranoid__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_paranoid__()
{
  ConVar::ConVar(this: &net_paranoid, pName: "net_paranoid", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__net_paranoid__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CAD0
// Name: _dynamic_initializer_for__net_minroutable__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_minroutable__()
{
  ConVar::ConVar(
    this: &net_minroutable,
    pName: "net_minroutable",
    pDefaultValue: "16",
    flags: 2,
    pHelpString: "Forces larger payloads.");
  return atexit(func: dynamic_atexit_destructor_for__net_minroutable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CB00
// Name: _dynamic_initializer_for__net_steamcnx_debug__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_steamcnx_debug__()
{
  ConVar::ConVar(
    this: &net_steamcnx_debug,
    pName: "net_steamcnx_debug",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show debug spew for steam based connections, 2 shows all network traffic for steam sockets.");
  return atexit(func: dynamic_atexit_destructor_for__net_steamcnx_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CB30
// Name: _dynamic_initializer_for__net_steamcnx_enabled__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_steamcnx_enabled__()
{
  ConVar::ConVar(
    this: &net_steamcnx_enabled,
    pName: "net_steamcnx_enabled",
    pDefaultValue: "1",
    flags: 0x80000,
    pHelpString: "Use steam connections on listen server as a fallback, 2 forces use of steam connections instead of raw UDP.");
  return atexit(func: dynamic_atexit_destructor_for__net_steamcnx_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CB60
// Name: _dynamic_initializer_for__net_steamcnx_allowrelay__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_steamcnx_allowrelay__()
{
  ConVar::ConVar(
    this: &net_steamcnx_allowrelay,
    pName: "net_steamcnx_allowrelay",
    pDefaultValue: "1",
    flags: 524416,
    pHelpString: "Allow steam connections to attempt to use relay servers as fallback (best if specified on command line:  +net_steamc"
    "nx_allowrelay 1)");
  return atexit(func: dynamic_atexit_destructor_for__net_steamcnx_allowrelay__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CBB0
// Name: _dynamic_initializer_for__net_steamcnx_status_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_steamcnx_status_command__()
{
  ConCommand::ConCommand(
    this: &net_steamcnx_status_command,
    pName: "net_steamcnx_status",
    callback: net_steamcnx_status,
    pHelpString: "Print status of steam connection sockets.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__net_steamcnx_status_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CC10
// Name: _dynamic_initializer_for__net_showsplits__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_showsplits__()
{
  ConVar::ConVar(
    this: &net_showsplits,
    pName: "net_showsplits",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Show info about packet splits");
  return atexit(func: dynamic_atexit_destructor_for__net_showsplits__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CC40
// Name: _dynamic_initializer_for__net_splitrate__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_splitrate__()
{
  ConVar::ConVar(
    this: &net_splitrate,
    pName: "net_splitrate",
    pDefaultValue: "1",
    flags: 0x80000,
    pHelpString: "Number of fragments for a splitpacket that can be sent per frame");
  return atexit(func: dynamic_atexit_destructor_for__net_splitrate__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CD00
// Name: _dynamic_initializer_for__net_public_adr__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_public_adr__()
{
  ConVar::ConVar(
    this: &net_public_adr,
    pName: "net_public_adr",
    pDefaultValue: defaultValue,
    flags: 0x80000,
    pHelpString: "For servers behind NAT/DHCP meant to be exposed to the public internet, this is the public facing ip address string: (\"x.x.x.x\" )");
  return atexit(func: dynamic_atexit_destructor_for__net_public_adr__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CE50
// Name: _dynamic_initializer_for__net_compressvoice__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_compressvoice__()
{
  ConVar::ConVar(
    this: &net_compressvoice,
    pName: "net_compressvoice",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Attempt to compress out of band voice payloads (360 only).");
  return atexit(func: dynamic_atexit_destructor_for__net_compressvoice__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CE80
// Name: _dynamic_initializer_for__net_usesocketsforloopback__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_usesocketsforloopback__()
{
  ConVar::ConVar(
    this: &net_usesocketsforloopback,
    pName: "net_usesocketsforloopback",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Use network sockets layer even for listen server local player's packets (multiplayer only).");
  return atexit(func: dynamic_atexit_destructor_for__net_usesocketsforloopback__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CFD0
// Name: _dynamic_initializer_for__net_local_adr__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void dynamic_initializer_for__net_local_adr__()
{
  netadr_s::SetIP(this: &net_local_adr, unIP: 0);
  netadr_s::SetPort(this: &net_local_adr, newport: 0);
  netadr_s::SetType(this: &net_local_adr, newtype: NA_IP);
}

//------------------------------------------------------------------------------
// Address: 0x1031D000
// Name: _dynamic_initializer_for__net_sockets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_sockets__()
{
  return atexit(func: dynamic_atexit_destructor_for__net_sockets__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D090
// Name: _dynamic_initializer_for__net_splitpackets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_splitpackets__()
{
  return atexit(func: dynamic_atexit_destructor_for__net_splitpackets__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D0E0
// Name: _dynamic_initializer_for__net_splitpacket_maxrate__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_splitpacket_maxrate__()
{
  ConVar::ConVar(
    this: &net_splitpacket_maxrate,
    pName: "net_splitpacket_maxrate",
    pDefaultValue: "15000",
    flags: 0x80000,
    pHelpString: "Max bytes per second when queueing splitpacket chunks",
    bMin: true,
    fMin: 1000.0,
    bMax: true,
    fMax: 30000.0);
  return atexit(func: dynamic_atexit_destructor_for__net_splitpacket_maxrate__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D140
// Name: _dynamic_initializer_for__net_channels_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_channels_command__()
{
  ConCommand::ConCommand(
    this: &net_channels_command,
    pName: "net_channels",
    callback: (void (__cdecl *)(const CCommand *))net_channels,
    pHelpString: "Shows net channel info",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__net_channels_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D170
// Name: _dynamic_initializer_for__net_start_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_start_command__()
{
  ConCommand::ConCommand(
    this: &net_start_command,
    pName: "net_start",
    callback: (void (__cdecl *)(const CCommand *))net_start,
    pHelpString: "Inits multiplayer network sockets",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__net_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D1A0
// Name: _dynamic_initializer_for__net_status_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_status_command__()
{
  ConCommand::ConCommand(
    this: &net_status_command,
    pName: "net_status",
    callback: (void (__cdecl *)(const CCommand *))net_status,
    pHelpString: "Shows current network status",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__net_status_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D1D0
// Name: _dynamic_initializer_for__net_queued_packet_thread__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_queued_packet_thread__()
{
  ConVar::ConVar(
    this: &net_queued_packet_thread,
    pName: "net_queued_packet_thread",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use a high priority thread to send queued packets out instead of sending them each frame.");
  return atexit(func: dynamic_atexit_destructor_for__net_queued_packet_thread__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D200
// Name: _dynamic_initializer_for__net_queue_trace__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_queue_trace__()
{
  ConVar::ConVar(this: &net_queue_trace, pName: "net_queue_trace", pDefaultValue: "0", flags: 0x2000000);
  return atexit(func: dynamic_atexit_destructor_for__net_queue_trace__);
}

//------------------------------------------------------------------------------
// Address: 0x10322920
// Name: _dynamic_atexit_destructor_for__net_earliertempents__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_earliertempents__()
{
  ConVar::~ConVar(this: &net_earliertempents);
}

//------------------------------------------------------------------------------
// Address: 0x10324220
// Name: _dynamic_atexit_destructor_for__net_megasnapshot__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_megasnapshot__()
{
  ConVar::~ConVar(this: &net_megasnapshot);
}

//------------------------------------------------------------------------------
// Address: 0x103242F0
// Name: _dynamic_atexit_destructor_for__net_showreliablesounds__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showreliablesounds__()
{
  ConVar::~ConVar(this: &net_showreliablesounds);
}

//------------------------------------------------------------------------------
// Address: 0x10325390
// Name: _dynamic_atexit_destructor_for__net_showevents__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showevents__()
{
  ConVar::~ConVar(this: &net_showevents);
}

//------------------------------------------------------------------------------
// Address: 0x103253A0
// Name: _dynamic_atexit_destructor_for__net_showeventlisteners__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showeventlisteners__()
{
  ConVar::~ConVar(this: &net_showeventlisteners);
}

//------------------------------------------------------------------------------
// Address: 0x103253C0
// Name: _dynamic_atexit_destructor_for__net_dumpeventstats_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_dumpeventstats_command__()
{
  ConCommand::~ConCommand(this: &net_dumpeventstats_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326220
// Name: _dynamic_atexit_destructor_for__net_showudp__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showudp__()
{
  ConVar::~ConVar(this: &net_showudp);
}

//------------------------------------------------------------------------------
// Address: 0x10326320
// Name: _dynamic_atexit_destructor_for__net_dumptest__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_dumptest__()
{
  ConVar::~ConVar(this: &net_dumptest);
}

//------------------------------------------------------------------------------
// Address: 0x10326330
// Name: _dynamic_atexit_destructor_for__net_paranoid__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_paranoid__()
{
  ConVar::~ConVar(this: &net_paranoid);
}

//------------------------------------------------------------------------------
// Address: 0x10326340
// Name: _dynamic_atexit_destructor_for__net_minroutable__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_minroutable__()
{
  ConVar::~ConVar(this: &net_minroutable);
}

//------------------------------------------------------------------------------
// Address: 0x10326430
// Name: _dynamic_atexit_destructor_for__net_showsplits__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_showsplits__()
{
  ConVar::~ConVar(this: &net_showsplits);
}

//------------------------------------------------------------------------------
// Address: 0x10326480
// Name: _dynamic_atexit_destructor_for__net_public_adr__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_public_adr__()
{
  ConVar::~ConVar(this: &net_public_adr);
}

//------------------------------------------------------------------------------
// Address: 0x103264F0
// Name: _dynamic_atexit_destructor_for__net_compressvoice__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_compressvoice__()
{
  ConVar::~ConVar(this: &net_compressvoice);
}

//------------------------------------------------------------------------------
// Address: 0x10326500
// Name: _dynamic_atexit_destructor_for__net_usesocketsforloopback__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_usesocketsforloopback__()
{
  ConVar::~ConVar(this: &net_usesocketsforloopback);
}

//------------------------------------------------------------------------------
// Address: 0x10326550
// Name: _dynamic_atexit_destructor_for__net_maxroutable__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_maxroutable__()
{
  ConVar::~ConVar(this: &net_maxroutable);
}

//------------------------------------------------------------------------------
// Address: 0x10326560
// Name: _dynamic_atexit_destructor_for__net_splitpacket_maxrate__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_splitpacket_maxrate__()
{
  ConVar::~ConVar(this: &net_splitpacket_maxrate);
}

//------------------------------------------------------------------------------
// Address: 0x10326570
// Name: _dynamic_atexit_destructor_for__net_channels_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_channels_command__()
{
  ConCommand::~ConCommand(this: &net_channels_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326580
// Name: _dynamic_atexit_destructor_for__net_start_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_start_command__()
{
  ConCommand::~ConCommand(this: &net_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326590
// Name: _dynamic_atexit_destructor_for__net_status_command__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_status_command__()
{
  ConCommand::~ConCommand(this: &net_status_command);
}

//------------------------------------------------------------------------------
// Address: 0x103265B0
// Name: _dynamic_atexit_destructor_for__net_sockets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_sockets__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&net_sockets);
}

//------------------------------------------------------------------------------
// Address: 0x103265C0
// Name: _dynamic_atexit_destructor_for__net_packets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_packets__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&net_packets);
}

//------------------------------------------------------------------------------
// Address: 0x10326630
// Name: _dynamic_atexit_destructor_for__net_splitpackets__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_splitpackets__()
{
  CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::~CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>(this: (CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,int> > *)&net_splitpackets);
}

//------------------------------------------------------------------------------
// Address: 0x103266A0
// Name: _dynamic_atexit_destructor_for__net_queued_packet_thread__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_queued_packet_thread__()
{
  ConVar::~ConVar(this: &net_queued_packet_thread);
}

//------------------------------------------------------------------------------
// Address: 0x103266B0
// Name: _dynamic_atexit_destructor_for__net_queue_trace__
// Source: semantic_dyn_pfx_net
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_queue_trace__()
{
  ConVar::~ConVar(this: &net_queue_trace);
}

//------------------------------------------------------------------------------
// Address: 0x10313760
// Name: _dynamic_initializer_for__g_SoundMessages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SoundMessages__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SoundMessages__);
}

//------------------------------------------------------------------------------
// Address: 0x10313770
// Name: _dynamic_initializer_for__retry_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__retry_command__()
{
  ConCommand::ConCommand(
    this: &retry_command,
    pName: "retry",
    callback: retry,
    pHelpString: "Retry connection to last server.",
    flags: 1342308352,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__retry_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319F90
// Name: _dynamic_initializer_for____g_CreateCGameEventManagerIGameEventManager2_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCGameEventManagerIGameEventManager2_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCGameEventManagerIGameEventManager2_reg,
           fn: _CreateCGameEventManagerIGameEventManager2_interface,
           pName: "GAMEEVENTSMANAGER002");
}

//------------------------------------------------------------------------------
// Address: 0x10319FB0
// Name: _dynamic_initializer_for__display_game_events__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__display_game_events__()
{
  ConVar::ConVar(this: &display_game_events, pName: "display_game_events", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__display_game_events__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CAC0
// Name: _dynamic_initializer_for__g_NetParanoid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NetParanoid__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_NetParanoid__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CB90
// Name: _dynamic_initializer_for__g_SteamSocketMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SteamSocketMgr__()
{
  CSteamSocketMgr::CSteamSocketMgr(this: &g_SteamSocketMgr);
  return atexit(func: dynamic_atexit_destructor_for__g_SteamSocketMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CBE0
// Name: _dynamic_initializer_for__g_NetSupport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NetSupport__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_NetSupport__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CBF0
// Name: _dynamic_initializer_for____g_CreateCNetSupportImplINetSupport_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCNetSupportImplINetSupport_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCNetSupportImplINetSupport_reg,
           fn: _CreateCNetSupportImplINetSupport_interface,
           pName: "INETSUPPORT_002");
}

//------------------------------------------------------------------------------
// Address: 0x1031CC70
// Name: _dynamic_initializer_for__ipname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ipname__()
{
  ConVar::ConVar(
    this: &ipname,
    pName: "ip",
    pDefaultValue: "localhost",
    flags: 0x80000,
    pHelpString: "Overrides IP for multihomed hosts");
  return atexit(func: dynamic_atexit_destructor_for__ipname__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CCA0
// Name: _dynamic_initializer_for__hostport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hostport__()
{
  ConVar::ConVar(
    this: &hostport,
    pName: "hostport",
    pDefaultValue: "27015",
    flags: 0x80000,
    pHelpString: "Host game server port");
  return atexit(func: dynamic_atexit_destructor_for__hostport__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CCD0
// Name: _dynamic_initializer_for__hostip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hostip__()
{
  ConVar::ConVar(
    this: &hostip,
    pName: "hostip",
    pDefaultValue: defaultValue,
    flags: 0x80000,
    pHelpString: "Host game server ip");
  return atexit(func: dynamic_atexit_destructor_for__hostip__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CD30
// Name: _dynamic_initializer_for__clientport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__clientport__()
{
  ConVar::ConVar(
    this: &clientport,
    pName: "clientport",
    pDefaultValue: "27005",
    flags: 0x80000,
    pHelpString: "Host game client port");
  return atexit(func: dynamic_atexit_destructor_for__clientport__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CD60
// Name: _dynamic_initializer_for__hltvport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hltvport__()
{
  ConVar::ConVar(
    this: &hltvport,
    pName: "tv_port",
    pDefaultValue: "27020",
    flags: 0x80000,
    pHelpString: "Host SourceTV port");
  return atexit(func: dynamic_atexit_destructor_for__hltvport__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CDC0
// Name: _dynamic_initializer_for__fakeloss__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fakeloss__()
{
  ConVar::ConVar(
    this: &fakeloss,
    pName: "net_fakeloss",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Simulate packet loss as a percentage (negative means drop 1/n packets)");
  return atexit(func: dynamic_atexit_destructor_for__fakeloss__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CDF0
// Name: _dynamic_initializer_for__droppackets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__droppackets__()
{
  ConVar::ConVar(
    this: &droppackets,
    pName: "net_droppackets",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Drops next n packets on client");
  return atexit(func: dynamic_atexit_destructor_for__droppackets__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D0A0
// Name: _dynamic_initializer_for__g_NetScratchBuffers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NetScratchBuffers__()
{
  if ( ((unsigned __int8)&g_NetScratchBuffers & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_NetScratchBuffers = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_NetScratchBuffers__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D0D0
// Name: _dynamic_initializer_for__g_SendQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SendQueue__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SendQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D130
// Name: _dynamic_initializer_for__g_BindAddressHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BindAddressHelper__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BindAddressHelper__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D230
// Name: _dynamic_initializer_for__g_QueuedPacketSender__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QueuedPacketSender__()
{
  CQueuedPacketSender::CQueuedPacketSender(this: &g_QueuedPacketSender);
  return atexit(func: dynamic_atexit_destructor_for__g_QueuedPacketSender__);
}

//------------------------------------------------------------------------------
// Address: 0x10322930
// Name: _dynamic_atexit_destructor_for__retry_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__retry_command__()
{
  ConCommand::~ConCommand(this: &retry_command);
}

//------------------------------------------------------------------------------
// Address: 0x103253B0
// Name: _dynamic_atexit_destructor_for__display_game_events__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__display_game_events__()
{
  ConVar::~ConVar(this: &display_game_events);
}

//------------------------------------------------------------------------------
// Address: 0x10326350
// Name: _dynamic_atexit_destructor_for__g_NetParanoid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_NetParanoid__()
{
  free(pMem: g_NetParanoid.m_pPacketMessages);
  free(pMem: g_NetParanoid.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x10326420
// Name: _dynamic_atexit_destructor_for__g_NetSupport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_NetSupport__()
{
  g_NetSupport.__vftable = (CNetSupportImpl_vtbl *)&CNetSupportImpl::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10326460
// Name: _dynamic_atexit_destructor_for__hostport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hostport__()
{
  ConVar::~ConVar(this: &hostport);
}

//------------------------------------------------------------------------------
// Address: 0x10326470
// Name: _dynamic_atexit_destructor_for__hostip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hostip__()
{
  ConVar::~ConVar(this: &hostip);
}

//------------------------------------------------------------------------------
// Address: 0x10326490
// Name: _dynamic_atexit_destructor_for__clientport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__clientport__()
{
  ConVar::~ConVar(this: &clientport);
}

//------------------------------------------------------------------------------
// Address: 0x103264E0
// Name: _dynamic_atexit_destructor_for__fakejitter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fakejitter__()
{
  ConVar::~ConVar(this: &fakejitter);
}

//------------------------------------------------------------------------------
// Address: 0x103265A0
// Name: _dynamic_atexit_destructor_for__g_NetScratchBuffers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_NetScratchBuffers__()
{
  CTSPool<net_scratchbuffer_t>::~CTSPool<net_scratchbuffer_t>(this: &g_NetScratchBuffers);
}

//------------------------------------------------------------------------------
// Address: 0x10326640
// Name: _dynamic_atexit_destructor_for__g_SendQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SendQueue__()
{
  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::RemoveAll(this: &g_SendQueue.m_SendQueue);
  if ( g_SendQueue.m_SendQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SendQueue.m_SendQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_SendQueue.m_SendQueue.m_Memory.m_pMemory);
      g_SendQueue.m_SendQueue.m_Memory.m_pMemory = nullptr;
    }
    g_SendQueue.m_SendQueue.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326690
// Name: _dynamic_atexit_destructor_for__g_BindAddressHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BindAddressHelper__()
{
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&g_BindAddressHelper.m_CachedAddresses);
}

//------------------------------------------------------------------------------
// Address: 0x103266C0
// Name: _dynamic_atexit_destructor_for__g_QueuedPacketSender__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QueuedPacketSender__()
{
  g_QueuedPacketSender.CThread::__vftable = (CQueuedPacketSender_vtbl *)&CQueuedPacketSender::`vftable'{for `CThread'};
  g_QueuedPacketSender.IQueuedPacketSender::__vftable = (IQueuedPacketSender_vtbl *)&CQueuedPacketSender::`vftable'{for `IQueuedPacketSender'};
  CQueuedPacketSender::Shutdown(this: (CQueuedPacketSender *)&g_QueuedPacketSender.IQueuedPacketSender);
  CThreadSyncObject::~CThreadSyncObject(this: &g_QueuedPacketSender.m_hThreadEvent);
  CThreadMutex::~CThreadMutex(this: &g_QueuedPacketSender.m_QueuedPacketsCS);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_QueuedPacketSender.m_QueuedPackets);
  CThread::~CThread(this: &g_QueuedPacketSender);
}

} // namespace engine_xlsp
