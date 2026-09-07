// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/timedeventmgr.cpp
// Functions: 16
// ============================================================

#include "game\server\timedeventmgr.h"

//------------------------------------------------------------------------------
// Address: 0x1006B240
// Name: public: void CUtlPriorityQueue<struct AI_NearNode_t,class CDefUtlPriorityQueueLessFunc<struct AI_NearNode_t>,class CUtlMemory<struct AI_NearNode_t,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::RemoveAtHead(
        CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int> > *this)
{
  int m_Size; // ecx
  AI_NearNode_t *m_pMemory; // eax
  int v4; // eax
  int v5; // edi
  int v6; // esi
  int v7; // eax
  bool v8; // zf
  int v9; // eax
  AI_NearNode_t *v10; // eax
  float dist; // ecx
  AI_NearNode_t *v12; // eax
  int nodeIndex; // [esp+Ch] [ebp-10h]
  int half; // [esp+10h] [ebp-Ch]
  int count; // [esp+14h] [ebp-8h]
  int child; // [esp+18h] [ebp-4h]
  int childa; // [esp+18h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
    {
      m_pMemory = this->m_heap.m_Memory.m_pMemory;
      m_pMemory->dist = this->m_heap.m_Memory.m_pMemory[m_Size - 1].dist;
      m_pMemory->nodeIndex = m_pMemory[m_Size - 1].nodeIndex;
    }
    --this->m_heap.m_Size;
  }
  v4 = this->m_heap.m_Size;
  v5 = 0;
  count = v4;
  if ( v4 != 0 )
  {
    v6 = 0;
    for ( half = v4 / 2; v6 < half; v5 = v6 )
    {
      v7 = 2 * v5 + 1;
      child = v7;
      if ( v7 < count )
      {
        v8 = !this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v5], a2: &this->m_heap.m_Memory.m_pMemory[v7]);
        v7 = child;
        if ( !v8 )
          v6 = child;
      }
      v9 = v7 + 1;
      childa = v9;
      if ( v9 < count
        && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v6], a2: &this->m_heap.m_Memory.m_pMemory[v9]) )
      {
        v6 = childa;
      }
      if ( v6 == v5 )
        break;
      v10 = this->m_heap.m_Memory.m_pMemory;
      dist = this->m_heap.m_Memory.m_pMemory[v5].dist;
      nodeIndex = this->m_heap.m_Memory.m_pMemory[v5].nodeIndex;
      v10[v5].dist = v10[v6].dist;
      v10[v5].nodeIndex = v10[v6].nodeIndex;
      v12 = this->m_heap.m_Memory.m_pMemory;
      v12[v6].dist = dist;
      v12[v6].nodeIndex = nodeIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B320
// Name: public: void CUtlPriorityQueue<struct AI_NearNode_t,class CDefUtlPriorityQueueLessFunc<struct AI_NearNode_t>,class CUtlMemory<struct AI_NearNode_t,int>>::Insert(struct AI_NearNode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int>>::Insert(
        CUtlPriorityQueue<AI_NearNode_t,CDefUtlPriorityQueueLessFunc<AI_NearNode_t>,CUtlMemory<AI_NearNode_t,int> > *this,
        const AI_NearNode_t *element)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  AI_NearNode_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // esi
  AI_NearNode_t *v8; // eax
  float dist; // ecx
  AI_NearNode_t *v10; // eax
  int nodeIndex; // [esp+Ch] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  m_nAllocationCount = this->m_heap.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_heap.m_Size;
  m_pMemory = this->m_heap.m_Memory.m_pMemory;
  v6 = this->m_heap.m_Size - m_Size - 1;
  this->m_heap.m_pElements = this->m_heap.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v6);
  this->m_heap.m_Memory.m_pMemory[m_Size] = *element;
  if ( m_Size != 0 )
  {
    do
    {
      v7 = (m_Size + 1) / 2 - 1;
      if ( this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[m_Size], a2: &this->m_heap.m_Memory.m_pMemory[v7]) )
        break;
      v8 = this->m_heap.m_Memory.m_pMemory;
      dist = this->m_heap.m_Memory.m_pMemory[v7].dist;
      nodeIndex = this->m_heap.m_Memory.m_pMemory[v7].nodeIndex;
      v8[v7].dist = v8[m_Size].dist;
      v8[v7].nodeIndex = v8[m_Size].nodeIndex;
      v10 = this->m_heap.m_Memory.m_pMemory;
      v10[m_Size].dist = dist;
      v10[m_Size].nodeIndex = nodeIndex;
      m_Size = (m_Size + 1) / 2 - 1;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6510
// Name: protected: void CUtlPriorityQueue<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,class CDefUtlPriorityQueueLessFunc<struct CPhysSaveRestoreBlockHandler::QueuedItem_t>,class CUtlMemory<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Swap(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Swap(
        CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> > *this,
        int index1,
        int index2)
{
  CPhysSaveRestoreBlockHandler::QueuedItem_t *v3; // eax
  PhysInterfaceId_t type; // ebx
  __int64 v5; // xmm0_8
  CPhysSaveRestoreBlockHandler::QueuedItem_t *v6; // eax
  unsigned int tmp_4; // [esp+Ch] [ebp-34h]
  const char *tmp_8; // [esp+10h] [ebp-30h]
  int tmp_12; // [esp+14h] [ebp-2Ch]
  const char *tmp_16; // [esp+18h] [ebp-28h]
  __int64 tmp_20; // [esp+1Ch] [ebp-24h]
  __int64 tmp_28; // [esp+24h] [ebp-1Ch]
  float tmp_44; // [esp+34h] [ebp-Ch]
  int tmp_48; // [esp+38h] [ebp-8h]
  void **tmp_52; // [esp+3Ch] [ebp-4h]

  v3 = &this->m_heap.m_Memory.m_pMemory[index1];
  type = v3->header.type;
  tmp_4 = v3->header.hEntity.m_Index;
  tmp_8 = v3->header.fieldName.pszValue;
  tmp_12 = v3->header.nObjects;
  tmp_16 = v3->header.modelName.pszValue;
  tmp_44 = v3->header.sphere.radius;
  tmp_48 = v3->header.iCollide;
  tmp_52 = v3->ppPhysObj;
  tmp_20 = *(_QWORD *)&v3->header.bbox.mins.x;
  tmp_28 = *(_QWORD *)&v3->header.bbox.mins.z;
  v5 = *(_QWORD *)&v3->header.bbox.maxs.y;
  *v3 = this->m_heap.m_Memory.m_pMemory[index2];
  v6 = &this->m_heap.m_Memory.m_pMemory[index2];
  v6->header.hEntity.m_Index = tmp_4;
  v6->header.fieldName.pszValue = tmp_8;
  v6->header.type = type;
  v6->header.nObjects = tmp_12;
  v6->header.modelName.pszValue = tmp_16;
  *(_QWORD *)&v6->header.bbox.mins.x = tmp_20;
  *(_QWORD *)&v6->header.bbox.mins.z = tmp_28;
  *(_QWORD *)&v6->header.bbox.maxs.y = v5;
  v6->header.sphere.radius = tmp_44;
  v6->header.iCollide = tmp_48;
  v6->ppPhysObj = tmp_52;
}

//------------------------------------------------------------------------------
// Address: 0x101A66E0
// Name: public: void CUtlPriorityQueue<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,class CDefUtlPriorityQueueLessFunc<struct CPhysSaveRestoreBlockHandler::QueuedItem_t>,class CUtlMemory<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Insert(struct CPhysSaveRestoreBlockHandler::QueuedItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Insert(
        CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> > *this,
        const CPhysSaveRestoreBlockHandler::QueuedItem_t *element)
{
  int v3; // edi
  int v4; // esi

  v3 = CUtlVector<CPhysSaveRestoreBlockHandler::QueuedItem_t,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::InsertBefore(
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
      CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Swap(
        this,
        index1: (v3 + 1) / 2 - 1,
        index2: v3);
      v3 = (v3 + 1) / 2 - 1;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AB170
// Name: public: void CUtlPriorityQueue<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,class CDefUtlPriorityQueueLessFunc<struct CPhysSaveRestoreBlockHandler::QueuedItem_t>,class CUtlMemory<struct CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::RemoveAtHead(
        CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int> > *this)
{
  int m_Size; // eax
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // esi
  int half; // [esp+Ch] [ebp-Ch]
  int count; // [esp+10h] [ebp-8h]
  int index; // [esp+14h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
      qmemcpy(
        this->m_heap.m_Memory.m_pMemory,
        &this->m_heap.m_Memory.m_pMemory[m_Size - 1],
        sizeof(CPhysSaveRestoreBlockHandler::QueuedItem_t));
    --this->m_heap.m_Size;
  }
  v3 = this->m_heap.m_Size;
  v4 = 0;
  index = 0;
  count = v3;
  if ( v3 != 0 )
  {
    half = v3 / 2;
    if ( v3 / 2 > 0 )
    {
      do
      {
        v5 = 2 * index + 1;
        if ( v5 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[index], a2: &this->m_heap.m_Memory.m_pMemory[v5]) )
        {
          v4 = 2 * index + 1;
        }
        v6 = 2 * index + 2;
        if ( v6 < count
          && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v4], a2: &this->m_heap.m_Memory.m_pMemory[v6]) )
        {
          v4 = 2 * index + 2;
        }
        if ( v4 == index )
          break;
        CUtlPriorityQueue<CPhysSaveRestoreBlockHandler::QueuedItem_t,CDefUtlPriorityQueueLessFunc<CPhysSaveRestoreBlockHandler::QueuedItem_t>,CUtlMemory<CPhysSaveRestoreBlockHandler::QueuedItem_t,int>>::Swap(
          this,
          index1: index,
          index2: v4);
        index = v4;
      }
      while ( v4 < half );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021D7A0
// Name: public: void CUtlPriorityQueue<class CEventRegister __near *,class CDefUtlPriorityQueueLessFunc<class CEventRegister __near *>,class CUtlMemory<class CEventRegister __near *,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CEventRegister *,CDefUtlPriorityQueueLessFunc<CEventRegister *>,CUtlMemory<CEventRegister *,int>>::RemoveAtHead(
        CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int> > *this)
{
  int m_Size; // eax
  int v3; // edi
  int v4; // eax
  int v5; // ebx
  int v6; // ebx
  SoundCommand_t *v7; // ecx
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
// Address: 0x10234140
// Name: public: CEventRegister::CEventRegister(void)
// Source: json
//------------------------------------------------------------------------------
CEventRegister *__thiscall CEventRegister::CEventRegister(CEventRegister *this)
{
  this->m_bRegistered = false;
  this->m_pEventMgr = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10234150
// Name: bool TimedEventMgr_LessFunc(class CEventRegister __near * const __near &,class CEventRegister __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl TimedEventMgr_LessFunc(SoundCommand_t *const *lhs, SoundCommand_t *const *rhs)
{
  return (*lhs)->m_time > (*rhs)->m_time;
}

//------------------------------------------------------------------------------
// Address: 0x10234180
// Name: private: void CTimedEventMgr::RemoveEvent(class CEventRegister __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimedEventMgr::RemoveEvent(CTimedEventMgr *this, CEventRegister *pEvent)
{
  int m_Size; // eax
  int v4; // edi
  CEventRegister **m_pMemory; // edx
  CEventRegister **i; // ecx
  int v7; // eax
  int v8; // ebx
  int v9; // ebx
  CEventRegister *v10; // ecx
  int j; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]
  CEventRegister *pEventa; // [esp+18h] [ebp+8h]

  if ( pEvent->m_bRegistered )
  {
    m_Size = this->m_Events.m_heap.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_Events.m_heap.m_Memory.m_pMemory;
      for ( i = this->m_Events.m_heap.m_Memory.m_pMemory; *i != pEvent; ++i )
      {
        if ( ++v4 >= m_Size )
          return;
      }
      pEventa = (CEventRegister *)v4;
      if ( v4 != m_Size - 1 )
        m_pMemory[v4] = m_pMemory[m_Size - 1];
      v7 = --this->m_Events.m_heap.m_Size;
      v12 = v7;
      if ( v7 != 0 )
      {
        for ( j = v7 / 2; v4 < j; pEventa = (CEventRegister *)v4 )
        {
          v8 = 2 * (_DWORD)pEventa + 1;
          if ( v8 < v12
            && this->m_Events.m_LessFunc(
                 a1: &this->m_Events.m_heap.m_Memory.m_pMemory[(_DWORD)pEventa],
                 a2: &this->m_Events.m_heap.m_Memory.m_pMemory[v8]) )
          {
            v4 = 2 * (_DWORD)pEventa + 1;
          }
          v9 = 2 * (_DWORD)pEventa + 2;
          if ( v9 < v12
            && this->m_Events.m_LessFunc(
                 a1: &this->m_Events.m_heap.m_Memory.m_pMemory[v4],
                 a2: &this->m_Events.m_heap.m_Memory.m_pMemory[v9]) )
          {
            v4 = 2 * (_DWORD)pEventa + 2;
          }
          if ( (CEventRegister *)v4 == pEventa )
            break;
          v10 = this->m_Events.m_heap.m_Memory.m_pMemory[(_DWORD)pEventa];
          this->m_Events.m_heap.m_Memory.m_pMemory[(_DWORD)pEventa] = this->m_Events.m_heap.m_Memory.m_pMemory[v4];
          this->m_Events.m_heap.m_Memory.m_pMemory[v4] = v10;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234270
// Name: public: void CEventRegister::StopUpdates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventRegister::StopUpdates(CEventRegister *this)
{
  CTimedEventMgr *m_pEventMgr; // ecx

  m_pEventMgr = this->m_pEventMgr;
  if ( m_pEventMgr != nullptr )
    CTimedEventMgr::RemoveEvent(this: m_pEventMgr, pEvent: this);
}

//------------------------------------------------------------------------------
// Address: 0x10234280
// Name: public: void CUtlPriorityQueue<class CEventRegister __near *,class CDefUtlPriorityQueueLessFunc<class CEventRegister __near *>,class CUtlMemory<class CEventRegister __near *,int>>::Insert(class CEventRegister __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<CEventRegister *,CDefUtlPriorityQueueLessFunc<CEventRegister *>,CUtlMemory<CEventRegister *,int>>::Insert(
        CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int> > *this,
        SoundCommand_t *const *element)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  SoundCommand_t **m_pMemory; // ecx
  int v6; // eax
  int v7; // esi
  SoundCommand_t *v8; // ecx

  m_Size = this->m_heap.m_Size;
  m_nAllocationCount = this->m_heap.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x10234320
// Name: public: CEventRegister::~CEventRegister(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventRegister::~CEventRegister(CEventRegister *this)
{
  CTimedEventMgr *m_pEventMgr; // ecx

  m_pEventMgr = this->m_pEventMgr;
  if ( m_pEventMgr != nullptr && this->m_bRegistered )
    CTimedEventMgr::RemoveEvent(this: m_pEventMgr, pEvent: this);
}

//------------------------------------------------------------------------------
// Address: 0x10234340
// Name: public: void CEventRegister::Init(class CTimedEventMgr __near *,class IEventRegisterCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventRegister::Init(CEventRegister *this, CTimedEventMgr *pMgr, IEventRegisterCallback *pCallback)
{
  CTimedEventMgr *m_pEventMgr; // ecx

  m_pEventMgr = this->m_pEventMgr;
  if ( m_pEventMgr != nullptr )
  {
    if ( this->m_bRegistered )
      CTimedEventMgr::RemoveEvent(this: m_pEventMgr, pEvent: this);
    this->m_pEventMgr = pMgr;
    this->m_pCallback = pCallback;
  }
  else
  {
    this->m_pEventMgr = pMgr;
    this->m_pCallback = pCallback;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234390
// Name: public: CTimedEventMgr::CTimedEventMgr(void)
// Source: json
//------------------------------------------------------------------------------
CTimedEventMgr *__thiscall CTimedEventMgr::CTimedEventMgr(CTimedEventMgr *this)
{
  this->m_Events.m_heap.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_heap.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_heap.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_heap.m_Size = 0;
  this->m_Events.m_heap.m_pElements = nullptr;
  this->m_Events.m_LessFunc = (bool (__cdecl *)(CEventRegister *const *, CEventRegister *const *))TimedEventMgr_LessFunc;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102343B0
// Name: public: void CEventRegister::SetUpdateInterval(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventRegister::SetUpdateInterval(CEventRegister *this, CEventRegister *interval)
{
  CTimedEventMgr *m_pEventMgr; // edi
  float v4; // xmm0_4

  m_pEventMgr = this->m_pEventMgr;
  if ( this->m_pEventMgr != nullptr )
  {
    v4 = *(float *)&interval;
    this->m_flUpdateInterval = *(float *)&interval;
    this->m_flNextEventTime = gpGlobals->curtime + v4;
    interval = this;
    CTimedEventMgr::RemoveEvent(this: m_pEventMgr, pEvent: this);
    CUtlPriorityQueue<CEventRegister *,CDefUtlPriorityQueueLessFunc<CEventRegister *>,CUtlMemory<CEventRegister *,int>>::Insert(
      this: (CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int> > *)m_pEventMgr,
      element: (SoundCommand_t *const *)&interval);
    this->m_bRegistered = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10234400
// Name: public: void CTimedEventMgr::FireEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimedEventMgr::FireEvents(CTimedEventMgr *this)
{
  CEventRegister *v2; // esi
  float m_flUpdateInterval; // xmm1_4
  CTimedEventMgr *m_pEventMgr; // edi
  float i; // xmm0_4
  SoundCommand_t *element; // [esp+4h] [ebp-4h] BYREF

  while ( this->m_Events.m_heap.m_Size != 0 )
  {
    v2 = *this->m_Events.m_heap.m_Memory.m_pMemory;
    if ( gpGlobals->curtime < v2->m_flNextEventTime )
      break;
    CUtlPriorityQueue<CEventRegister *,CDefUtlPriorityQueueLessFunc<CEventRegister *>,CUtlMemory<CEventRegister *,int>>::RemoveAtHead((CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int> > *)this);
    m_flUpdateInterval = v2->m_flUpdateInterval;
    v2->m_bRegistered = false;
    if ( m_flUpdateInterval > 0.000001 )
    {
      m_pEventMgr = v2->m_pEventMgr;
      if ( v2->m_pEventMgr != nullptr )
      {
        for ( i = v2->m_flNextEventTime; gpGlobals->curtime >= i; v2->m_flNextEventTime = i )
          i = i + m_flUpdateInterval;
        element = (SoundCommand_t *)v2;
        CTimedEventMgr::RemoveEvent(this: m_pEventMgr, pEvent: v2);
        CUtlPriorityQueue<CEventRegister *,CDefUtlPriorityQueueLessFunc<CEventRegister *>,CUtlMemory<CEventRegister *,int>>::Insert(
          this: (CUtlPriorityQueue<SoundCommand_t *,CDefUtlPriorityQueueLessFunc<SoundCommand_t *>,CUtlMemory<SoundCommand_t *,int> > *)m_pEventMgr,
          &element);
        v2->m_bRegistered = true;
      }
    }
    v2->m_pCallback->FireEvent(this: v2->m_pCallback);
  }
}
