// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/net_ws_queued_packet_sender.cpp
// Functions: 18
// ============================================================

#include "engine\net_ws_queued_packet_sender.h"

//------------------------------------------------------------------------------
// Address: 0x101B9440
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
// Address: 0x101B9460
// Name: public: virtual bool CQueuedPacketSender::Setup(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQueuedPacketSender::Setup(CQueuedPacketSender *this)
{
  return (*(bool (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 26) + 28))(a1: (char *)this - 104, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B9470
// Name: private: virtual bool CQueuedPacketSender::Start(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CQueuedPacketSender::Start(CQueuedPacketSender *this, unsigned int nBytesStack)
{
  struct ThreadHandle_t__ *ThreadHandle; // eax

  this->Shutdown(this: &this->IQueuedPacketSender);
  if ( !CThread::Start(this, a2: nBytesStack, a3: PRIORITY_DEFAULT) )
    return 0;
  CThread::SetPriority(this, a2: 2);
  ThreadHandle = CThread::GetThreadHandle(this);
  _ThreadSetDebugName(a1: ThreadHandle, a2: "CQueuedPacketSender");
  this->m_bThreadShouldExit = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B94D0
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
// Address: 0x101B9520
// Name: public: void CUtlPriorityQueue<class CQueuedPacketSender::CQueuedPacket __near *,class CDefUtlPriorityQueueLessFunc<class CQueuedPacketSender::CQueuedPacket __near *>,class CUtlMemory<class CQueuedPacketSender::CQueuedPacket __near *,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAtHead(
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *this)
{
  int m_Size; // eax
  int v3; // edi
  int v4; // eax
  int v5; // ebx
  int v6; // ebx
  CQueuedPacketSender::CQueuedPacket *v7; // ecx
  int half; // [esp+8h] [ebp-Ch]
  int count; // [esp+Ch] [ebp-8h]
  int index; // [esp+10h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
      *this->m_heap.m_Memory.m_pMemory = this->m_heap.m_Memory.m_pMemory[m_Size - 1];
    --this->m_heap.m_Size;
  }
  v4 = this->m_heap.m_Size;
  index = 0;
  count = v4;
  if ( v4 != 0 )
  {
    half = v4 / 2;
    if ( v4 / 2 > 0 )
    {
      do
      {
        v5 = 2 * index + 1;
        if ( v5 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[index], a2: &this->m_heap.m_Memory.m_pMemory[v5]) )
        {
          v3 = 2 * index + 1;
        }
        v6 = 2 * index + 2;
        if ( v6 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v3], a2: &this->m_heap.m_Memory.m_pMemory[v6]) )
        {
          v3 = 2 * index + 2;
        }
        if ( v3 == index )
          break;
        v7 = this->m_heap.m_Memory.m_pMemory[index];
        this->m_heap.m_Memory.m_pMemory[index] = this->m_heap.m_Memory.m_pMemory[v3];
        this->m_heap.m_Memory.m_pMemory[v3] = v7;
        index = v3;
      }
      while ( v3 < half );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B95D0
// Name: public: void CUtlPriorityQueue<class CQueuedPacketSender::CQueuedPacket __near *,class CDefUtlPriorityQueueLessFunc<class CQueuedPacketSender::CQueuedPacket __near *>,class CUtlMemory<class CQueuedPacketSender::CQueuedPacket __near *,int>>::RemoveAt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAt(
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *this,
        int index)
{
  int m_Size; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  bool v8; // al
  int v9; // ebx
  bool v10; // al
  CQueuedPacketSender::CQueuedPacket *v11; // edx
  int half; // [esp+4h] [ebp-8h]
  int count; // [esp+8h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  v4 = index;
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
    half = v5 / 2;
    v6 = index;
    if ( index < v5 / 2 )
    {
      while ( 1 )
      {
        v7 = 2 * v4 + 1;
        if ( v7 < count )
        {
          v8 = this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v4], a2: &this->m_heap.m_Memory.m_pMemory[v7]);
          v4 = index;
          if ( v8 )
            v6 = v7;
        }
        v9 = v7 + 1;
        if ( v9 < count )
        {
          v10 = this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v6], a2: &this->m_heap.m_Memory.m_pMemory[v9]);
          v4 = index;
          if ( v10 )
            v6 = v9;
        }
        if ( v6 == v4 )
          break;
        v11 = this->m_heap.m_Memory.m_pMemory[v4];
        this->m_heap.m_Memory.m_pMemory[v4] = this->m_heap.m_Memory.m_pMemory[v6];
        this->m_heap.m_Memory.m_pMemory[v6] = v11;
        index = v6;
        if ( v6 >= half )
          break;
        v4 = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9680
// Name: public: virtual void CQueuedPacketSender::ClearQueuedPacketsForChannel(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedPacketSender::ClearQueuedPacketsForChannel(CQueuedPacketSender *this, INetChannel *pChan)
{
  unsigned int *p_m_currentOwnerID; // ebx
  int v4; // edi
  CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *p_m_Lock; // ebx
  CQueuedPacketSender::CQueuedPacket *v6; // esi
  unsigned int *generated_id_15; // [esp+Ch] [ebp-4h]

  p_m_currentOwnerID = &this->m_Lock.m_currentOwnerID;
  generated_id_15 = &this->m_Lock.m_currentOwnerID;
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
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v6->buf);
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v6->to);
        free(pMem: v6);
      }
      --v4;
    }
    while ( v4 >= 0 );
    p_m_currentOwnerID = generated_id_15;
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_currentOwnerID);
}

//------------------------------------------------------------------------------
// Address: 0x101B96F0
// Name: private: virtual int CQueuedPacketSender::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CQueuedPacketSender::Run@<eax>(CQueuedPacketSender *this@<ecx>, int a2@<esi>)
{
  CQueuedPacketSender *v2; // edi
  _RTL_CRITICAL_SECTION *p_m_QueuedPacketsCS; // esi
  unsigned int v4; // edx
  CStatTime *v5; // ecx
  int m_nValue; // eax
  void ***p_m_QueuedPackets; // esi
  void *v8; // esi
  int v9; // eax
  int v10; // edi
  double v11; // st7
  void *v12; // eax
  void *v13; // eax
  unsigned int v14; // esi
  double v15; // st7
  int v17; // [esp+4h] [ebp-21Ch]
  char v18[20]; // [esp+10h] [ebp-210h] BYREF
  char sz[256]; // [esp+24h] [ebp-1FCh] BYREF
  CQueuedPacketSender *v20; // [esp+210h] [ebp-10h]
  unsigned int v21; // [esp+214h] [ebp-Ch]
  unsigned int v22; // [esp+218h] [ebp-8h]
  bool v23; // [esp+21Fh] [ebp-1h]

  v2 = this;
  v20 = this;
  CThreadEvent::Wait(this: &this->m_hThreadEvent, a2: 0x32u);
  if ( !v2->m_bThreadShouldExit )
  {
    v17 = a2;
    p_m_QueuedPacketsCS = (_RTL_CRITICAL_SECTION *)&v2->m_QueuedPacketsCS;
    do
    {
      v22 = 50;
      EnterCriticalSection(lpCriticalSection: p_m_QueuedPacketsCS);
      v4 = _Plat_MSTime(a1: v17);
      v21 = v4;
      if ( net_queue_trace.m_pParent != nullptr )
        m_nValue = net_queue_trace.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      LOBYTE(v5) = m_nValue == 581304;
      v23 = m_nValue == 581304;
      if ( v2->m_QueuedPackets.m_heap.m_Size > 0 )
      {
        p_m_QueuedPackets = (void ***)&v2->m_QueuedPackets;
        while ( 1 )
        {
          v8 = **p_m_QueuedPackets;
          if ( *(_DWORD *)v8 > v4 )
            break;
          v9 = *((_DWORD *)v8 + 3);
          if ( *(_DWORD *)(v9 + 4) != 0 && *(_WORD *)(v9 + 2) != 0 )
          {
            if ( (_BYTE)v5 != 0 )
            {
              v10 = *((_DWORD *)v8 + 11);
              v11 = _Plat_FloatTime(this: v5);
              V_snprintf(pDest: &sz[236], maxLen: 256, pFormat: "SQ:  sending %d bytes at %f\n", v10, v11);
              _Warning(a1: &sz[236]);
              v2 = v20;
            }
            NET_SendToImpl(
              s: *((_DWORD *)v8 + 2),
              buf: *((const char **)v8 + 8),
              len: *((_DWORD *)v8 + 11),
              to: *((const sockaddr **)v8 + 3),
              tolen: *((_DWORD *)v8 + 6),
              iGameDataLength: -1);
          }
          *((_DWORD *)v8 + 11) = 0;
          if ( *((int *)v8 + 10) >= 0 )
          {
            if ( *((_DWORD *)v8 + 8) != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v8 + 8));
              *((_DWORD *)v8 + 8) = 0;
            }
            *((_DWORD *)v8 + 9) = 0;
          }
          v12 = *((void **)v8 + 8);
          *((_DWORD *)v8 + 12) = v12;
          if ( *((int *)v8 + 10) >= 0 )
          {
            if ( v12 != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
              *((_DWORD *)v8 + 8) = 0;
            }
            *((_DWORD *)v8 + 9) = 0;
          }
          *((_DWORD *)v8 + 6) = 0;
          if ( *((int *)v8 + 5) >= 0 )
          {
            if ( *((_DWORD *)v8 + 3) != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v8 + 3));
              *((_DWORD *)v8 + 3) = 0;
            }
            *((_DWORD *)v8 + 4) = 0;
          }
          v13 = *((void **)v8 + 3);
          *((_DWORD *)v8 + 7) = v13;
          if ( *((int *)v8 + 5) >= 0 )
          {
            if ( v13 != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
              *((_DWORD *)v8 + 3) = 0;
            }
            *((_DWORD *)v8 + 4) = 0;
          }
          free(pMem: v8);
          p_m_QueuedPackets = (void ***)&v2->m_QueuedPackets;
          CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAtHead(this: &v2->m_QueuedPackets);
          if ( v2->m_QueuedPackets.m_heap.m_Size <= 0 )
            goto LABEL_35;
          LOBYTE(v5) = v23;
          v4 = v21;
        }
        v14 = *(_DWORD *)v8 - v4;
        v22 = v14;
        if ( (_BYTE)v5 != 0 )
        {
          v15 = _Plat_FloatTime(this: v5);
          V_snprintf(pDest: v18, maxLen: 256, pFormat: "SQ:  sleeping for %u msecs at %f\n", v14, v15);
          _Warning(a1: v18);
        }
      }
LABEL_35:
      p_m_QueuedPacketsCS = (_RTL_CRITICAL_SECTION *)&v2->m_QueuedPacketsCS;
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v2->m_QueuedPacketsCS);
      CThreadEvent::Wait(this: &v2->m_hThreadEvent, a2: v22);
    }
    while ( !v2->m_bThreadShouldExit );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B9920
// Name: public: void CUtlPriorityQueue<class CQueuedPacketSender::CQueuedPacket __near *,class CDefUtlPriorityQueueLessFunc<class CQueuedPacketSender::CQueuedPacket __near *>,class CUtlMemory<class CQueuedPacketSender::CQueuedPacket __near *,int>>::Insert(class CQueuedPacketSender::CQueuedPacket __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::Insert(
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *this,
        CQueuedPacketSender::CQueuedPacket *const *element)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CQueuedPacketSender::CQueuedPacket **m_pMemory; // ecx
  int v6; // eax
  int v7; // esi
  CQueuedPacketSender::CQueuedPacket *v8; // ecx

  m_Size = this->m_heap.m_Size;
  m_nAllocationCount = this->m_heap.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_heap.m_Size;
  m_pMemory = this->m_heap.m_Memory.m_pMemory;
  v6 = this->m_heap.m_Size - m_Size - 1;
  this->m_heap.m_pElements = this->m_heap.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  this->m_heap.m_Memory.m_pMemory[m_Size] = *element;
  if ( m_Size != 0 )
  {
    do
    {
      v7 = (m_Size + 1) / 2 - 1;
      if ( this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[m_Size], a2: &this->m_heap.m_Memory.m_pMemory[v7]) )
        break;
      v8 = this->m_heap.m_Memory.m_pMemory[v7];
      this->m_heap.m_Memory.m_pMemory[v7] = this->m_heap.m_Memory.m_pMemory[m_Size];
      this->m_heap.m_Memory.m_pMemory[m_Size] = v8;
      m_Size = (m_Size + 1) / 2 - 1;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B99C0
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
  this->m_QueuedPackets.m_LessFunc = CQueuedPacketSender::CQueuedPacket::LessFunc;
  CThreadMutex::CThreadMutex(this: &this->m_QueuedPacketsCS);
  CThreadEvent::CThreadEvent(this: &this->m_hThreadEvent, a2: false);
  CThread::SetName(this, a2: "QueuedPacketSender");
  this->m_bThreadShouldExit = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B9A30
// Name: public: virtual bool CQueuedPacketSender::IsRunning(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQueuedPacketSender::IsRunning(CQueuedPacketSender *this)
{
  return CThread::IsAlive(this: (CQueuedPacketSender *)((char *)this - 104));
}

//------------------------------------------------------------------------------
// Address: 0x101B9A40
// Name: public: virtual void CQueuedPacketSender::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedPacketSender::Shutdown(CQueuedPacketSender *this)
{
  struct ThreadHandle_t__ *ThreadHandle; // eax
  int v3; // esi
  void *v4; // eax
  void *v5; // eax

  if ( CThread::IsAlive(this: (CQueuedPacketSender *)((char *)this - 104)) )
  {
    if ( CThread::GetThreadHandle(this: (CQueuedPacketSender *)((char *)this - 104)) == nullptr )
    {
      ThreadHandle = CThread::GetThreadHandle(this: (CQueuedPacketSender *)((char *)this - 104));
      _Msg(a1: "-->Shutdown %u\n", ThreadHandle);
    }
    this->m_szName[12] = 1;
    CThreadEvent::Set(this: (CThreadEvent *)&this->m_szName[4]);
    CThread::Join(this: (CQueuedPacketSender *)((char *)this - 104), a2: 0xFFFFFFFF);
    while ( *(int *)&this->m_Lock.m_CriticalSection[12] > 0 )
    {
      v3 = **(_DWORD **)this->m_Lock.m_CriticalSection;
      if ( v3 != 0 )
      {
        *(_DWORD *)(v3 + 44) = 0;
        if ( *(int *)(v3 + 40) >= 0 )
        {
          if ( *(_DWORD *)(v3 + 32) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 32));
            *(_DWORD *)(v3 + 32) = 0;
          }
          *(_DWORD *)(v3 + 36) = 0;
        }
        v4 = *(void **)(v3 + 32);
        *(_DWORD *)(v3 + 48) = v4;
        if ( *(int *)(v3 + 40) >= 0 )
        {
          if ( v4 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
            *(_DWORD *)(v3 + 32) = 0;
          }
          *(_DWORD *)(v3 + 36) = 0;
        }
        *(_DWORD *)(v3 + 24) = 0;
        if ( *(int *)(v3 + 20) >= 0 )
        {
          if ( *(_DWORD *)(v3 + 12) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 12));
            *(_DWORD *)(v3 + 12) = 0;
          }
          *(_DWORD *)(v3 + 16) = 0;
        }
        v5 = *(void **)(v3 + 12);
        *(_DWORD *)(v3 + 28) = v5;
        if ( *(int *)(v3 + 20) >= 0 )
        {
          if ( v5 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
            *(_DWORD *)(v3 + 12) = 0;
          }
          *(_DWORD *)(v3 + 16) = 0;
        }
        free(pMem: (void *)v3);
      }
      CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAtHead(this: (CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *)&this->m_Lock);
    }
    *(_DWORD *)&this->m_Lock.m_CriticalSection[12] = 0;
    if ( *(int *)&this->m_Lock.m_CriticalSection[8] >= 0 )
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
// Address: 0x101B9B90
// Name: public: virtual void CQueuedPacketSender::QueuePacket(class INetChannel __near *,unsigned int,char const __near *,int,struct sockaddr const __near *,int,unsigned int)
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
  unsigned int *p_m_currentOwnerID; // esi
  int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // esi
  unsigned int *generated_id_17; // [esp+Ch] [ebp-8h]
  CQueuedPacketSender::CQueuedPacket *pPacket; // [esp+10h] [ebp-4h] BYREF

  p_m_currentOwnerID = &this->m_Lock.m_currentOwnerID;
  generated_id_17 = &this->m_Lock.m_currentOwnerID;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock.m_currentOwnerID);
  v10 = _Plat_MSTime();
  if ( *(int *)&this->m_Lock.m_CriticalSection[12] >= 1024 )
  {
    if ( --nWarnings > 0 )
      _Warning(a1: "CQueuedPacketSender: num queued packets >= nMaxQueuedPackets. Not queueing anymore.\n");
  }
  else
  {
    v11 = MemAlloc_Alloc(nSize: 0x34u);
    v12 = nullptr;
    if ( v11 != nullptr )
    {
      v11[3] = 0;
      v11[4] = 0;
      v11[5] = 0;
      v11[6] = 0;
      v11[7] = 0;
      v11[8] = 0;
      v11[9] = 0;
      v11[10] = 0;
      v11[11] = 0;
      v11[12] = 0;
      v12 = v11;
    }
    *v12 = msecDelay + v10;
    v12[2] = s;
    pPacket = (CQueuedPacketSender::CQueuedPacket *)v12;
    v12[1] = pChan;
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)(v12 + 8),
      pArray: (const unsigned __int8 *)buf,
      size: len);
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)(v12 + 3),
      pArray: (const unsigned __int8 *)to,
      size: tolen);
    CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::Insert(
      this: (CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *)&this->m_Lock,
      element: &pPacket);
    p_m_currentOwnerID = generated_id_17;
  }
  CThreadEvent::Set(this: (CThreadEvent *)&this->m_szName[4]);
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_currentOwnerID);
}

//------------------------------------------------------------------------------
// Address: 0x10264E7A
// Name: ?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Start(CThread *this, unsigned int a2, enum CThread::ThreadPriorityEnum_t a3)
{
  return __imp_?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10264E80
// Name: ?Init@CThread@@MAE_NXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Init(CThread *this)
{
  return __imp_?Init@CThread@@MAE_NXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x10264E86
// Name: ?OnExit@CThread@@MAEXXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThread::OnExit(CThread *this)
{
  __imp_?OnExit@CThread@@MAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x10264E8C
// Name: ?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::WaitForCreateComplete(CThread *this, struct CThreadEvent *a2)
{
  return __imp_?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10264E92
// Name: ?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int (__stdcall *__thiscall CThread::GetThreadProc(CThread *this))(void *)
{
  return __imp_?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ(this);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101B9860
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
// Address: 0x101B9880
// Name: public: virtual bool CQueuedPacketSender::Setup(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQueuedPacketSender::Setup(CQueuedPacketSender *this)
{
  return (*(bool (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 26) + 28))(a1: (char *)this - 104, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B9890
// Name: private: virtual bool CQueuedPacketSender::Start(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CQueuedPacketSender::Start(CQueuedPacketSender *this, unsigned int nBytesStack)
{
  struct ThreadHandle_t__ *ThreadHandle; // eax

  this->Shutdown(this: &this->IQueuedPacketSender);
  if ( !CThread::Start(this, a2: nBytesStack, a3: PRIORITY_DEFAULT) )
    return 0;
  CThread::SetPriority(this, a2: 2);
  ThreadHandle = CThread::GetThreadHandle(this);
  _ThreadSetDebugName(a1: ThreadHandle, a2: "CQueuedPacketSender");
  this->m_bThreadShouldExit = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B98F0
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
// Address: 0x101B9940
// Name: public: void CUtlPriorityQueue<class CQueuedPacketSender::CQueuedPacket __near *,class CDefUtlPriorityQueueLessFunc<class CQueuedPacketSender::CQueuedPacket __near *>,class CUtlMemory<class CQueuedPacketSender::CQueuedPacket __near *,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAtHead(
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *this)
{
  int m_Size; // eax
  int v3; // edi
  int v4; // eax
  int v5; // ebx
  int v6; // ebx
  CQueuedPacketSender::CQueuedPacket *v7; // ecx
  int half; // [esp+8h] [ebp-Ch]
  int count; // [esp+Ch] [ebp-8h]
  int index; // [esp+10h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
      *this->m_heap.m_Memory.m_pMemory = this->m_heap.m_Memory.m_pMemory[m_Size - 1];
    --this->m_heap.m_Size;
  }
  v4 = this->m_heap.m_Size;
  index = 0;
  count = v4;
  if ( v4 != 0 )
  {
    half = v4 / 2;
    if ( v4 / 2 > 0 )
    {
      do
      {
        v5 = 2 * index + 1;
        if ( v5 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[index], a2: &this->m_heap.m_Memory.m_pMemory[v5]) )
        {
          v3 = 2 * index + 1;
        }
        v6 = 2 * index + 2;
        if ( v6 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v3], a2: &this->m_heap.m_Memory.m_pMemory[v6]) )
        {
          v3 = 2 * index + 2;
        }
        if ( v3 == index )
          break;
        v7 = this->m_heap.m_Memory.m_pMemory[index];
        this->m_heap.m_Memory.m_pMemory[index] = this->m_heap.m_Memory.m_pMemory[v3];
        this->m_heap.m_Memory.m_pMemory[v3] = v7;
        index = v3;
      }
      while ( v3 < half );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B99F0
// Name: public: void CUtlPriorityQueue<class CQueuedPacketSender::CQueuedPacket __near *,class CDefUtlPriorityQueueLessFunc<class CQueuedPacketSender::CQueuedPacket __near *>,class CUtlMemory<class CQueuedPacketSender::CQueuedPacket __near *,int>>::RemoveAt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAt(
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *this,
        int index)
{
  int m_Size; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  bool v8; // al
  int v9; // ebx
  bool v10; // al
  CQueuedPacketSender::CQueuedPacket *v11; // edx
  int half; // [esp+4h] [ebp-8h]
  int count; // [esp+8h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  v4 = index;
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
    half = v5 / 2;
    v6 = index;
    if ( index < v5 / 2 )
    {
      while ( 1 )
      {
        v7 = 2 * v4 + 1;
        if ( v7 < count )
        {
          v8 = this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v4], a2: &this->m_heap.m_Memory.m_pMemory[v7]);
          v4 = index;
          if ( v8 )
            v6 = v7;
        }
        v9 = v7 + 1;
        if ( v9 < count )
        {
          v10 = this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v6], a2: &this->m_heap.m_Memory.m_pMemory[v9]);
          v4 = index;
          if ( v10 )
            v6 = v9;
        }
        if ( v6 == v4 )
          break;
        v11 = this->m_heap.m_Memory.m_pMemory[v4];
        this->m_heap.m_Memory.m_pMemory[v4] = this->m_heap.m_Memory.m_pMemory[v6];
        this->m_heap.m_Memory.m_pMemory[v6] = v11;
        index = v6;
        if ( v6 >= half )
          break;
        v4 = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9AA0
// Name: public: virtual void CQueuedPacketSender::ClearQueuedPacketsForChannel(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedPacketSender::ClearQueuedPacketsForChannel(CQueuedPacketSender *this, INetChannel *pChan)
{
  unsigned int *p_m_currentOwnerID; // ebx
  int v4; // edi
  CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *p_m_Lock; // ebx
  CQueuedPacketSender::CQueuedPacket *v6; // esi
  unsigned int *generated_id_15; // [esp+Ch] [ebp-4h]

  p_m_currentOwnerID = &this->m_Lock.m_currentOwnerID;
  generated_id_15 = &this->m_Lock.m_currentOwnerID;
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
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v6->buf);
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v6->to);
        free(pMem: v6);
      }
      --v4;
    }
    while ( v4 >= 0 );
    p_m_currentOwnerID = generated_id_15;
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_currentOwnerID);
}

//------------------------------------------------------------------------------
// Address: 0x101B9B10
// Name: private: virtual int CQueuedPacketSender::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CQueuedPacketSender::Run@<eax>(CQueuedPacketSender *this@<ecx>, int a2@<esi>)
{
  CQueuedPacketSender *v2; // edi
  _RTL_CRITICAL_SECTION *p_m_QueuedPacketsCS; // esi
  unsigned int v4; // edx
  CStatTime *v5; // ecx
  int m_nValue; // eax
  void ***p_m_QueuedPackets; // esi
  void *v8; // esi
  int v9; // eax
  int v10; // edi
  double v11; // st7
  void *v12; // eax
  void *v13; // eax
  unsigned int v14; // esi
  double v15; // st7
  int v17; // [esp+4h] [ebp-21Ch]
  char v18[20]; // [esp+10h] [ebp-210h] BYREF
  char sz[256]; // [esp+24h] [ebp-1FCh] BYREF
  CQueuedPacketSender *v20; // [esp+210h] [ebp-10h]
  unsigned int v21; // [esp+214h] [ebp-Ch]
  unsigned int v22; // [esp+218h] [ebp-8h]
  bool v23; // [esp+21Fh] [ebp-1h]

  v2 = this;
  v20 = this;
  CThreadEvent::Wait(this: &this->m_hThreadEvent, a2: 0x32u);
  if ( !v2->m_bThreadShouldExit )
  {
    v17 = a2;
    p_m_QueuedPacketsCS = (_RTL_CRITICAL_SECTION *)&v2->m_QueuedPacketsCS;
    do
    {
      v22 = 50;
      EnterCriticalSection(lpCriticalSection: p_m_QueuedPacketsCS);
      v4 = _Plat_MSTime(a1: v17);
      v21 = v4;
      if ( net_queue_trace.m_pParent != nullptr )
        m_nValue = net_queue_trace.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      LOBYTE(v5) = m_nValue == 581304;
      v23 = m_nValue == 581304;
      if ( v2->m_QueuedPackets.m_heap.m_Size > 0 )
      {
        p_m_QueuedPackets = (void ***)&v2->m_QueuedPackets;
        while ( 1 )
        {
          v8 = **p_m_QueuedPackets;
          if ( *(_DWORD *)v8 > v4 )
            break;
          v9 = *((_DWORD *)v8 + 3);
          if ( *(_DWORD *)(v9 + 4) != 0 && *(_WORD *)(v9 + 2) != 0 )
          {
            if ( (_BYTE)v5 != 0 )
            {
              v10 = *((_DWORD *)v8 + 11);
              v11 = _Plat_FloatTime(this: v5);
              V_snprintf(pDest: &sz[236], maxLen: 256, pFormat: "SQ:  sending %d bytes at %f\n", v10, v11);
              _Warning(a1: &sz[236]);
              v2 = v20;
            }
            NET_SendToImpl(
              s: *((_DWORD *)v8 + 2),
              buf: *((char **)v8 + 8),
              len: *((_DWORD *)v8 + 11),
              to: *((const sockaddr **)v8 + 3),
              tolen: *((_DWORD *)v8 + 6),
              iGameDataLength: -1);
          }
          *((_DWORD *)v8 + 11) = 0;
          if ( *((int *)v8 + 10) >= 0 )
          {
            if ( *((_DWORD *)v8 + 8) != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v8 + 8));
              *((_DWORD *)v8 + 8) = 0;
            }
            *((_DWORD *)v8 + 9) = 0;
          }
          v12 = *((void **)v8 + 8);
          *((_DWORD *)v8 + 12) = v12;
          if ( *((int *)v8 + 10) >= 0 )
          {
            if ( v12 != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
              *((_DWORD *)v8 + 8) = 0;
            }
            *((_DWORD *)v8 + 9) = 0;
          }
          *((_DWORD *)v8 + 6) = 0;
          if ( *((int *)v8 + 5) >= 0 )
          {
            if ( *((_DWORD *)v8 + 3) != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v8 + 3));
              *((_DWORD *)v8 + 3) = 0;
            }
            *((_DWORD *)v8 + 4) = 0;
          }
          v13 = *((void **)v8 + 3);
          *((_DWORD *)v8 + 7) = v13;
          if ( *((int *)v8 + 5) >= 0 )
          {
            if ( v13 != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
              *((_DWORD *)v8 + 3) = 0;
            }
            *((_DWORD *)v8 + 4) = 0;
          }
          free(pMem: v8);
          p_m_QueuedPackets = (void ***)&v2->m_QueuedPackets;
          CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAtHead(this: &v2->m_QueuedPackets);
          if ( v2->m_QueuedPackets.m_heap.m_Size <= 0 )
            goto LABEL_35;
          LOBYTE(v5) = v23;
          v4 = v21;
        }
        v14 = *(_DWORD *)v8 - v4;
        v22 = v14;
        if ( (_BYTE)v5 != 0 )
        {
          v15 = _Plat_FloatTime(this: v5);
          V_snprintf(pDest: v18, maxLen: 256, pFormat: "SQ:  sleeping for %u msecs at %f\n", v14, v15);
          _Warning(a1: v18);
        }
      }
LABEL_35:
      p_m_QueuedPacketsCS = (_RTL_CRITICAL_SECTION *)&v2->m_QueuedPacketsCS;
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v2->m_QueuedPacketsCS);
      CThreadEvent::Wait(this: &v2->m_hThreadEvent, a2: v22);
    }
    while ( !v2->m_bThreadShouldExit );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B9D40
// Name: public: void CUtlPriorityQueue<class CQueuedPacketSender::CQueuedPacket __near *,class CDefUtlPriorityQueueLessFunc<class CQueuedPacketSender::CQueuedPacket __near *>,class CUtlMemory<class CQueuedPacketSender::CQueuedPacket __near *,int>>::Insert(class CQueuedPacketSender::CQueuedPacket __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::Insert(
        CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *this,
        CQueuedPacketSender::CQueuedPacket *const *element)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CQueuedPacketSender::CQueuedPacket **m_pMemory; // ecx
  int v6; // eax
  int v7; // esi
  CQueuedPacketSender::CQueuedPacket *v8; // ecx

  m_Size = this->m_heap.m_Size;
  m_nAllocationCount = this->m_heap.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_heap.m_Size;
  m_pMemory = this->m_heap.m_Memory.m_pMemory;
  v6 = this->m_heap.m_Size - m_Size - 1;
  this->m_heap.m_pElements = this->m_heap.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  this->m_heap.m_Memory.m_pMemory[m_Size] = *element;
  if ( m_Size != 0 )
  {
    do
    {
      v7 = (m_Size + 1) / 2 - 1;
      if ( this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[m_Size], a2: &this->m_heap.m_Memory.m_pMemory[v7]) )
        break;
      v8 = this->m_heap.m_Memory.m_pMemory[v7];
      this->m_heap.m_Memory.m_pMemory[v7] = this->m_heap.m_Memory.m_pMemory[m_Size];
      this->m_heap.m_Memory.m_pMemory[m_Size] = v8;
      m_Size = (m_Size + 1) / 2 - 1;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9DE0
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
  CThread::SetName(this, a2: "QueuedPacketSender");
  this->m_bThreadShouldExit = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B9E50
// Name: public: virtual bool CQueuedPacketSender::IsRunning(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQueuedPacketSender::IsRunning(CQueuedPacketSender *this)
{
  return CThread::IsAlive(this: (CQueuedPacketSender *)((char *)this - 104));
}

//------------------------------------------------------------------------------
// Address: 0x101B9E60
// Name: public: virtual void CQueuedPacketSender::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedPacketSender::Shutdown(CQueuedPacketSender *this)
{
  struct ThreadHandle_t__ *ThreadHandle; // eax
  int v3; // esi
  void *v4; // eax
  void *v5; // eax

  if ( CThread::IsAlive(this: (CQueuedPacketSender *)((char *)this - 104)) )
  {
    if ( CThread::GetThreadHandle(this: (CQueuedPacketSender *)((char *)this - 104)) == nullptr )
    {
      ThreadHandle = CThread::GetThreadHandle(this: (CQueuedPacketSender *)((char *)this - 104));
      _Msg(a1: "-->Shutdown %u\n", ThreadHandle);
    }
    this->m_szName[12] = 1;
    CThreadEvent::Set(this: (CThreadEvent *)&this->m_szName[4]);
    CThread::Join(this: (CQueuedPacketSender *)((char *)this - 104), a2: 0xFFFFFFFF);
    while ( *(int *)&this->m_Lock.m_CriticalSection[12] > 0 )
    {
      v3 = **(_DWORD **)this->m_Lock.m_CriticalSection;
      if ( v3 != 0 )
      {
        *(_DWORD *)(v3 + 44) = 0;
        if ( *(int *)(v3 + 40) >= 0 )
        {
          if ( *(_DWORD *)(v3 + 32) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 32));
            *(_DWORD *)(v3 + 32) = 0;
          }
          *(_DWORD *)(v3 + 36) = 0;
        }
        v4 = *(void **)(v3 + 32);
        *(_DWORD *)(v3 + 48) = v4;
        if ( *(int *)(v3 + 40) >= 0 )
        {
          if ( v4 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
            *(_DWORD *)(v3 + 32) = 0;
          }
          *(_DWORD *)(v3 + 36) = 0;
        }
        *(_DWORD *)(v3 + 24) = 0;
        if ( *(int *)(v3 + 20) >= 0 )
        {
          if ( *(_DWORD *)(v3 + 12) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v3 + 12));
            *(_DWORD *)(v3 + 12) = 0;
          }
          *(_DWORD *)(v3 + 16) = 0;
        }
        v5 = *(void **)(v3 + 12);
        *(_DWORD *)(v3 + 28) = v5;
        if ( *(int *)(v3 + 20) >= 0 )
        {
          if ( v5 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
            *(_DWORD *)(v3 + 12) = 0;
          }
          *(_DWORD *)(v3 + 16) = 0;
        }
        free(pMem: (void *)v3);
      }
      CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::RemoveAtHead(this: (CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *)&this->m_Lock);
    }
    *(_DWORD *)&this->m_Lock.m_CriticalSection[12] = 0;
    if ( *(int *)&this->m_Lock.m_CriticalSection[8] >= 0 )
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
// Address: 0x101BA020
// Name: public: virtual void CQueuedPacketSender::QueuePacket(class INetChannel __near *,unsigned int,char const __near *,int,struct sockaddr const __near *,int,unsigned int)
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
  unsigned int *p_m_currentOwnerID; // esi
  int v10; // ebx
  _DWORD *v11; // eax
  _DWORD *v12; // esi
  int v13; // [esp+0h] [ebp-14h]
  unsigned int *generated_id_17; // [esp+Ch] [ebp-8h]
  CQueuedPacketSender::CQueuedPacket *pPacket; // [esp+10h] [ebp-4h] BYREF

  p_m_currentOwnerID = &this->m_Lock.m_currentOwnerID;
  generated_id_17 = &this->m_Lock.m_currentOwnerID;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Lock.m_currentOwnerID);
  v10 = _Plat_MSTime(a1: v13);
  if ( *(int *)&this->m_Lock.m_CriticalSection[12] >= 1024 )
  {
    if ( --nWarnings > 0 )
      _Warning(a1: "CQueuedPacketSender: num queued packets >= nMaxQueuedPackets. Not queueing anymore.\n");
  }
  else
  {
    v11 = MemAlloc_Alloc(nSize: 0x34u);
    v12 = nullptr;
    if ( v11 != nullptr )
    {
      v11[3] = 0;
      v11[4] = 0;
      v11[5] = 0;
      v11[6] = 0;
      v11[7] = 0;
      v11[8] = 0;
      v11[9] = 0;
      v11[10] = 0;
      v11[11] = 0;
      v11[12] = 0;
      v12 = v11;
    }
    *v12 = msecDelay + v10;
    v12[2] = s;
    pPacket = (CQueuedPacketSender::CQueuedPacket *)v12;
    v12[1] = pChan;
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)(v12 + 8),
      pArray: (const unsigned __int8 *)buf,
      size: len);
    CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)(v12 + 3),
      pArray: (const unsigned __int8 *)to,
      size: tolen);
    CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::Insert(
      this: (CUtlPriorityQueue<CQueuedPacketSender::CQueuedPacket *,CDefUtlPriorityQueueLessFunc<CQueuedPacketSender::CQueuedPacket *>,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int> > *)&this->m_Lock,
      element: &pPacket);
    p_m_currentOwnerID = generated_id_17;
  }
  CThreadEvent::Set(this: (CThreadEvent *)&this->m_szName[4]);
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_currentOwnerID);
}

//------------------------------------------------------------------------------
// Address: 0x10264E9A
// Name: ?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Start(CThread *this, unsigned int a2, enum CThread::ThreadPriorityEnum_t a3)
{
  return __imp_?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10264EA0
// Name: ?Init@CThread@@MAE_NXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Init(CThread *this)
{
  return __imp_?Init@CThread@@MAE_NXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x10264EA6
// Name: ?OnExit@CThread@@MAEXXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThread::OnExit(CThread *this)
{
  __imp_?OnExit@CThread@@MAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x10264EAC
// Name: ?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::WaitForCreateComplete(CThread *this, struct CThreadEvent *a2)
{
  return __imp_?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10264EB2
// Name: ?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int (__stdcall *__thiscall CThread::GetThreadProc(CThread *this))(void *)
{
  return __imp_?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ(this);
}

} // namespace engine_xlsp
