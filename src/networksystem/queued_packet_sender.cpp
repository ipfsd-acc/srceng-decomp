// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: networksystem/queued_packet_sender.cpp
// Functions: 17
// ============================================================

#include "networksystem\queued_packet_sender.h"

//------------------------------------------------------------------------------
// Address: 0x1000EC30
// Name: public: static bool CQueuedPacketSender::CQueuedPacket::LessFunc(class CQueuedPacketSender::CQueuedPacket __near * const __near &,class CQueuedPacketSender::CQueuedPacket __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CQueuedPacketSender::CQueuedPacket::LessFunc(
        CQueuedPacketSender::CQueuedPacket *const *lhs,
        CQueuedPacketSender::CQueuedPacket *const *rhs)
{
  return **(_DWORD **)rhs < **(_DWORD **)lhs;
}

//------------------------------------------------------------------------------
// Address: 0x1000EC50
// Name: public: virtual bool CQueuedPacketSender::Setup(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQueuedPacketSender::Setup(CQueuedPacketSender *this)
{
  return (*(bool (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 24) + 4))(a1: (char *)this - 96, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000EC60
// Name: private: virtual bool CQueuedPacketSender::Start(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CQueuedPacketSender::Start(CQueuedPacketSender *this, unsigned int nBytesStack)
{
  struct ThreadHandle_t__ *ThreadHandle; // eax

  this->Shutdown(this: &this->IQueuedPacketSender);
  if ( !CThread::Start(this, a2: nBytesStack) )
    return 0;
  CThread::SetPriority(this, a2: 2);
  ThreadHandle = CThread::GetThreadHandle(this);
  _ThreadSetDebugName(a1: ThreadHandle, a2: "CQueuedPacketSender");
  this->m_bThreadShouldExit = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000ED20
// Name: public: virtual bool CQueuedPacketSender::HasQueuedPackets(class INetChannel const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CQueuedPacketSender::HasQueuedPackets(CQueuedPacketSender *this, const INetChannel *pChan)
{
  unsigned int *p_m_currentOwnerID; // edi
  int v4; // ecx
  int v5; // eax
  int v6; // esi

  p_m_currentOwnerID = &this->m_Lock.m_currentOwnerID;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock.m_currentOwnerID);
  v4 = *(_DWORD *)&this->m_Lock.m_CriticalSection[12];
  v5 = 0;
  if ( v4 <= 0 )
  {
LABEL_5:
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_currentOwnerID);
    return 0;
  }
  else
  {
    v6 = *(_DWORD *)this->m_Lock.m_CriticalSection;
    while ( *(const INetChannel **)(*(_DWORD *)v6 + 4) != pChan )
    {
      ++v5;
      v6 += 4;
      if ( v5 >= v4 )
        goto LABEL_5;
    }
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_currentOwnerID);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ED70
// Name: public: void CUtlPriorityQueue<class CQueuedPacketSender::CQueuedPacket __near *,class CDefUtlPriorityQueueLessFunc<class CQueuedPacketSender::CQueuedPacket __near *>,class CUtlMemory<class CQueuedPacketSender::CQueuedPacket __near *,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAtHead(
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *this)
{
  int m_Size; // eax
  int v3; // eax
  int v4; // ebp
  int v5; // edi
  int v6; // ebx
  int v7; // ebx
  CQueuedPacketSender::CQueuedPacket *v8; // ecx
  int half; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
      *this->m_heap.m_Memory.m_pMemory = this->m_heap.m_Memory.m_pMemory[m_Size - 1];
    --this->m_heap.m_Size;
  }
  v3 = this->m_heap.m_Size;
  v4 = 0;
  half = v3;
  if ( v3 != 0 )
  {
    v5 = 0;
    for ( i = v3 / 2; v5 < i; v4 = v5 )
    {
      v6 = 2 * v4 + 1;
      if ( v6 < half
        && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v4], a2: &this->m_heap.m_Memory.m_pMemory[v6]) )
      {
        v5 = 2 * v4 + 1;
      }
      v7 = 2 * v4 + 2;
      if ( v7 < half
        && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v5], a2: &this->m_heap.m_Memory.m_pMemory[v7]) )
      {
        v5 = 2 * v4 + 2;
      }
      if ( v5 == v4 )
        break;
      v8 = this->m_heap.m_Memory.m_pMemory[v4];
      this->m_heap.m_Memory.m_pMemory[v4] = this->m_heap.m_Memory.m_pMemory[v5];
      this->m_heap.m_Memory.m_pMemory[v5] = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EE20
// Name: public: void CUtlPriorityQueue<class CQueuedPacketSender::CQueuedPacket __near *,class CDefUtlPriorityQueueLessFunc<class CQueuedPacketSender::CQueuedPacket __near *>,class CUtlMemory<class CQueuedPacketSender::CQueuedPacket __near *,int>>::RemoveAt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAt(
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *this,
        int index)
{
  int v2; // ebp
  int m_Size; // eax
  int v5; // eax
  int i; // edi
  int v7; // ebx
  int v8; // ebx
  CQueuedPacketSender::CQueuedPacket *v9; // ecx
  int v10; // [esp+8h] [ebp-4h]
  int count; // [esp+10h] [ebp+4h]

  v2 = index;
  m_Size = this->m_heap.m_Size;
  if ( m_Size > 0 )
  {
    if ( index != m_Size - 1 )
      this->m_heap.m_Memory.m_pMemory[index] = this->m_heap.m_Memory.m_pMemory[m_Size - 1];
    --this->m_heap.m_Size;
  }
  v5 = this->m_heap.m_Size;
  count = v5;
  if ( v5 != 0 )
  {
    v10 = v5 / 2;
    for ( i = v2; i < v10; v2 = i )
    {
      v7 = 2 * v2 + 1;
      if ( v7 < count
        && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v2], a2: &this->m_heap.m_Memory.m_pMemory[v7]) )
      {
        i = 2 * v2 + 1;
      }
      v8 = 2 * v2 + 2;
      if ( v8 < count
        && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[i], a2: &this->m_heap.m_Memory.m_pMemory[v8]) )
      {
        i = 2 * v2 + 2;
      }
      if ( i == v2 )
        break;
      v9 = this->m_heap.m_Memory.m_pMemory[v2];
      this->m_heap.m_Memory.m_pMemory[v2] = this->m_heap.m_Memory.m_pMemory[i];
      this->m_heap.m_Memory.m_pMemory[i] = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EF30
// Name: public: virtual void CQueuedPacketSender::ClearQueuedPacketsForChannel(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedPacketSender::ClearQueuedPacketsForChannel(CQueuedPacketSender *this, INetChannel *pChan)
{
  unsigned int *p_m_currentOwnerID; // ebx
  int v4; // edi
  CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *p_m_Lock; // ebx
  CQueuedPacketSender::CQueuedPacket *v6; // esi
  unsigned int *v7; // [esp+Ch] [ebp-4h]

  p_m_currentOwnerID = &this->m_Lock.m_currentOwnerID;
  v7 = &this->m_Lock.m_currentOwnerID;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock.m_currentOwnerID);
  v4 = *(_DWORD *)&this->m_Lock.m_CriticalSection[12] - 1;
  if ( v4 >= 0 )
  {
    p_m_Lock = (CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *)&this->m_Lock;
    do
    {
      v6 = p_m_Lock->m_heap.m_Memory.m_pMemory[v4];
      if ( v6->m_pChannel == pChan )
      {
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAt(
          this: p_m_Lock,
          index: v4);
        CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&v6->buf);
        CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&v6->to);
        free(pMem: v6);
      }
      --v4;
    }
    while ( v4 >= 0 );
    p_m_currentOwnerID = v7;
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_currentOwnerID);
}

//------------------------------------------------------------------------------
// Address: 0x1000EFA0
// Name: private: virtual int CQueuedPacketSender::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CQueuedPacketSender::Run(CQueuedPacketSender *this)
{
  CQueuedPacketSender *v1; // edi
  unsigned int v2; // ebp
  unsigned int v3; // eax
  bool v4; // cl
  void ***p_m_QueuedPackets; // esi
  void *v6; // esi
  int v7; // eax
  int v8; // edi
  double v9; // st7
  bool v10; // sf
  void *v11; // eax
  void *v12; // eax
  double v13; // st7
  bool bTrace; // [esp+43h] [ebp-209h]
  unsigned int msNow; // [esp+48h] [ebp-204h]
  char pDest[256]; // [esp+4Ch] [ebp-200h] BYREF
  char sz[256]; // [esp+14Ch] [ebp-100h] BYREF

  v1 = this;
  v2 = 50;
  while ( !CThreadEvent::Wait(this: &v1->m_hThreadEvent, a2: v2) || !v1->m_bThreadShouldExit )
  {
    v2 = 50;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v1->m_QueuedPacketsCS);
    v3 = _Plat_MSTime();
    msNow = v3;
    v4 = net_queue_trace.m_pParent->m_Value.m_nValue == 581304;
    bTrace = v4;
    if ( v1->m_QueuedPackets.m_heap.m_Size > 0 )
    {
      p_m_QueuedPackets = (void ***)&v1->m_QueuedPackets;
      while ( 1 )
      {
        v6 = **p_m_QueuedPackets;
        if ( *(_DWORD *)v6 > v3 )
          break;
        v7 = *((_DWORD *)v6 + 3);
        if ( *(_DWORD *)(v7 + 4) != 0 && *(_WORD *)(v7 + 2) != 0 )
        {
          if ( v4 )
          {
            v8 = *((_DWORD *)v6 + 11);
            v9 = _Plat_FloatTime();
            V_snprintf(pDest, maxLen: 256, pFormat: "SQ:  sending %d bytes at %f\n", v8, v9);
            _Warning(a1: pDest);
            v1 = this;
          }
          NET_SendToImpl(
            s: *((_DWORD *)v6 + 2),
            buf: *((const char **)v6 + 8),
            len: *((char **)v6 + 11),
            to: *((const sockaddr **)v6 + 3),
            tolen: *((_DWORD *)v6 + 6),
            iGameDataLength: -1);
        }
        v10 = *((int *)v6 + 10) < 0;
        *((_DWORD *)v6 + 11) = 0;
        if ( !v10 )
        {
          if ( *((_DWORD *)v6 + 8) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v6 + 8));
            *((_DWORD *)v6 + 8) = 0;
          }
          *((_DWORD *)v6 + 9) = 0;
        }
        v10 = *((int *)v6 + 10) < 0;
        v11 = *((void **)v6 + 8);
        *((_DWORD *)v6 + 12) = v11;
        if ( !v10 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            *((_DWORD *)v6 + 8) = 0;
          }
          *((_DWORD *)v6 + 9) = 0;
        }
        v10 = *((int *)v6 + 5) < 0;
        *((_DWORD *)v6 + 6) = 0;
        if ( !v10 )
        {
          if ( *((_DWORD *)v6 + 3) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v6 + 3));
            *((_DWORD *)v6 + 3) = 0;
          }
          *((_DWORD *)v6 + 4) = 0;
        }
        v10 = *((int *)v6 + 5) < 0;
        v12 = *((void **)v6 + 3);
        *((_DWORD *)v6 + 7) = v12;
        if ( !v10 )
        {
          if ( v12 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
            *((_DWORD *)v6 + 3) = 0;
          }
          *((_DWORD *)v6 + 4) = 0;
        }
        free(pMem: v6);
        p_m_QueuedPackets = (void ***)&v1->m_QueuedPackets;
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAtHead(this: &v1->m_QueuedPackets);
        if ( v1->m_QueuedPackets.m_heap.m_Size <= 0 )
          goto LABEL_30;
        v4 = bTrace;
        v3 = msNow;
      }
      v2 = *(_DWORD *)v6 - v3;
      if ( v4 )
      {
        v13 = _Plat_FloatTime();
        V_snprintf(pDest: sz, maxLen: 256, pFormat: "SQ:  sleeping for %u msecs at %f\n", v2, v13);
        _Warning(a1: sz);
      }
    }
LABEL_30:
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v1->m_QueuedPacketsCS);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F1B0
// Name: public: void CUtlPriorityQueue<class CQueuedPacketSender::CQueuedPacket __near *,class CDefUtlPriorityQueueLessFunc<class CQueuedPacketSender::CQueuedPacket __near *>,class CUtlMemory<class CQueuedPacketSender::CQueuedPacket __near *,int>>::Insert(class CQueuedPacketSender::CQueuedPacket __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::Insert(
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *this,
        CQueuedPacketSender::CQueuedPacket *const *element)
{
  int v3; // edi
  int v4; // esi
  CQueuedPacketSender::CQueuedPacket *v5; // ecx

  v3 = CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::InsertBefore(
         this: &this->m_heap,
         elem: this->m_heap.m_Size);
  this->m_heap.m_Memory.m_pMemory[v3] = *element;
  if ( v3 != 0 )
  {
    do
    {
      v4 = (v3 + 1) / 2 - 1;
      if ( this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v3], a2: &this->m_heap.m_Memory.m_pMemory[v4]) )
        break;
      v5 = this->m_heap.m_Memory.m_pMemory[v4];
      this->m_heap.m_Memory.m_pMemory[v4] = this->m_heap.m_Memory.m_pMemory[v3];
      this->m_heap.m_Memory.m_pMemory[v3] = v5;
      v3 = (v3 + 1) / 2 - 1;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F210
// Name: public: CQueuedPacketSender::CQueuedPacketSender(void)
// Source: json
//------------------------------------------------------------------------------
CQueuedPacketSender *__thiscall CQueuedPacketSender::CQueuedPacketSender(CQueuedPacketSender *this)
{
  CThread::CThread(this);
  this->IQueuedPacketSender::__vftable = (IQueuedPacketSender_vtbl *)&IQueuedPacketSender::`vftable';
  this->CThread::__vftable = (CQueuedPacketSender_vtbl *)&CQueuedPacketSender::`vftable'{for `CThread'};
  this->IQueuedPacketSender::__vftable = (IQueuedPacketSender_vtbl *)&CQueuedPacketSender::`vftable'{for `IQueuedPacketSender'};
  this->m_QueuedPackets.m_heap.m_Memory.m_pMemory = nullptr;
  this->m_QueuedPackets.m_heap.m_Memory.m_nAllocationCount = 0;
  this->m_QueuedPackets.m_heap.m_Memory.m_nGrowSize = 0;
  this->m_QueuedPackets.m_heap.m_Size = 0;
  this->m_QueuedPackets.m_heap.m_pElements = nullptr;
  this->m_QueuedPackets.m_LessFunc = (bool (__cdecl *)(CQueuedPacketSender::CQueuedPacket *const *, CQueuedPacketSender::CQueuedPacket *const *))CQueuedPacketSender::CQueuedPacket::LessFunc;
  CThreadMutex::CThreadMutex(this: &this->m_QueuedPacketsCS);
  CThreadEvent::CThreadEvent(this: &this->m_hThreadEvent, a2: false);
  this->m_bThreadShouldExit = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F270
// Name: public: virtual bool CQueuedPacketSender::IsRunning(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQueuedPacketSender::IsRunning(CQueuedPacketSender *this)
{
  return CThread::IsAlive(this: (CQueuedPacketSender *)((char *)this - 96));
}

//------------------------------------------------------------------------------
// Address: 0x1000F280
// Name: public: virtual void CQueuedPacketSender::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedPacketSender::Shutdown(CQueuedPacketSender *this)
{
  CThread *v2; // edi
  struct ThreadHandle_t__ *ThreadHandle; // eax
  int v4; // edi
  bool v5; // sf

  v2 = (CQueuedPacketSender *)((char *)this - 96);
  if ( CThread::IsAlive(this: (CQueuedPacketSender *)((char *)this - 96)) )
  {
    if ( CThread::GetThreadHandle(this: v2) == nullptr )
    {
      ThreadHandle = CThread::GetThreadHandle(this: v2);
      _Msg(a1: "-->Shutdown %u\n", ThreadHandle);
    }
    this->m_szName[12] = 1;
    CThreadEvent::Set(this: (CThreadEvent *)&this->m_szName[4]);
    CThread::Join(this: v2, a2: 0xFFFFFFFF);
    while ( *(int *)&this->m_Lock.m_CriticalSection[12] > 0 )
    {
      v4 = **(_DWORD **)this->m_Lock.m_CriticalSection;
      if ( v4 != 0 )
      {
        CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)(v4 + 32));
        CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)(v4 + 12));
        free(pMem: (void *)v4);
      }
      CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAtHead(this: (CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *)&this->m_Lock);
    }
    v5 = *(int *)&this->m_Lock.m_CriticalSection[8] < 0;
    *(_DWORD *)&this->m_Lock.m_CriticalSection[12] = 0;
    if ( !v5 )
    {
      if ( *(_DWORD *)this->m_Lock.m_CriticalSection != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)this->m_Lock.m_CriticalSection);
        *(_DWORD *)this->m_Lock.m_CriticalSection = 0;
      }
      *(_DWORD *)&this->m_Lock.m_CriticalSection[4] = 0;
    }
    *(_DWORD *)&this->m_Lock.m_CriticalSection[16] = *(_DWORD *)this->m_Lock.m_CriticalSection;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F390
// Name: public: virtual void CQueuedPacketSender::QueuePacket(class INetChannel __near *,int,char const __near *,int,struct sockaddr const __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedPacketSender::QueuePacket(
        CQueuedPacketSender *this,
        INetChannel *pChan,
        unsigned int s,
        const char *buf,
        int len,
        const sockaddr *to,
        int tolen,
        unsigned int msecDelay)
{
  unsigned int *p_m_currentOwnerID; // ebp
  int v10; // ebx
  CQueuedPacketSender::CQueuedPacket *v11; // eax
  CQueuedPacketSender::CQueuedPacket *v12; // esi
  CQueuedPacketSender::CQueuedPacket *element; // [esp+Ch] [ebp-4h] BYREF

  p_m_currentOwnerID = &this->m_Lock.m_currentOwnerID;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock.m_currentOwnerID);
  v10 = _Plat_MSTime();
  if ( *(int *)&this->m_Lock.m_CriticalSection[12] >= 1024 )
  {
    if ( --nWarnings > 0 )
      _Warning(a1: "CQueuedPacketSender: num queued packets >= nMaxQueuedPackets. Not queueing anymore.\n");
  }
  else
  {
    v11 = (CQueuedPacketSender::CQueuedPacket *)operator new(nSize: 0x34u);
    v12 = nullptr;
    if ( v11 != nullptr )
    {
      v11->to.m_Memory.m_pMemory = nullptr;
      v11->to.m_Memory.m_nAllocationCount = 0;
      v11->to.m_Memory.m_nGrowSize = 0;
      v11->to.m_Size = 0;
      v11->to.m_pElements = nullptr;
      v11->buf.m_Memory.m_pMemory = nullptr;
      v11->buf.m_Memory.m_nAllocationCount = 0;
      v11->buf.m_Memory.m_nGrowSize = 0;
      v11->buf.m_Size = 0;
      v11->buf.m_pElements = nullptr;
      v12 = v11;
    }
    v12->m_unSendTime = msecDelay + v10;
    v12->m_Socket = s;
    element = v12;
    v12->m_pChannel = pChan;
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &v12->buf, pArray: buf, size: len);
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &v12->to, pArray: (const char *)to, size: tolen);
    CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::Insert(
      this: (CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *)&this->m_Lock,
      &element);
  }
  CThreadEvent::Set(this: (CThreadEvent *)&this->m_szName[4]);
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_currentOwnerID);
}

//------------------------------------------------------------------------------
// Address: 0x1001A910
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx
  bool v7; // zf

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
        m_nAllocationCount = 32;
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
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B8B6
// Name: ?Init@CThread@@MAE_NXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Init(CThread *this)
{
  return __imp_?Init@CThread@@MAE_NXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001B8BC
// Name: ?OnExit@CThread@@MAEXXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThread::OnExit(CThread *this)
{
  __imp_?OnExit@CThread@@MAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001B8C2
// Name: ?GetThreadProc@CThread@@MAEP6GIPAX@ZXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int (__stdcall *__thiscall CThread::GetThreadProc(CThread *this))(void *)
{
  return __imp_?GetThreadProc@CThread@@MAEP6GIPAX@ZXZ(this);
}
