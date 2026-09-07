// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_events.cpp
// Functions: 15
// ============================================================

#include "matchmaking\mm_events.h"

//------------------------------------------------------------------------------
// Address: 0x10001E50
// Name: public: int CUtlVector<struct CMatchExtensions::RegisteredInterface_t,class CUtlMemory<struct CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
        CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMatchExtensions::RegisteredInterface_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CMatchExtensions::RegisteredInterface_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_pvInterface = nullptr;
          v11->m_nRefCount = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10002B10
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002B80
// Name: public: bool CUtlVector<class CServer __near *,class CUtlMemory<class CServer __near *,int>>::FindAndFastRemove(class CServer __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CServer *,CUtlMemory<CServer *,int>>::FindAndFastRemove(
        CUtlVector<CServer *,CUtlMemory<CServer *,int> > *this,
        CServer **src)
{
  int m_Size; // esi
  int v3; // eax
  CServer **i; // edx

  m_Size = this->m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  if ( v3 == -1 )
    return 0;
  if ( v3 != m_Size - 1 )
    this->m_Memory.m_pMemory[v3] = this->m_Memory.m_pMemory[m_Size - 1];
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002BD0
// Name: public: void CUtlVector<class CServer __near *,class CUtlMemory<class CServer __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(
        CUtlVector<CServer *,CUtlMemory<CServer *,int> > *this)
{
  int i; // edi
  CServer *v3; // ecx
  bool v4; // sf
  CServer **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CServer *, int))v3->dtr_CServer)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003230
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 8;
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
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100032C0
// Name: public: virtual class KeyValues __near * CMatchEventsSubscription::GetEventData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchEventsSubscription::GetEventData(
        CMatchEventsSubscription *this,
        const char *szEventDataKey)
{
  int v3; // edi
  KeyValues *v4; // ebx
  const char *v5; // eax
  int v6; // edi
  const char *Name; // eax

  v3 = 0;
  if ( this->m_arrEventData.m_Size <= 0 )
  {
LABEL_4:
    v6 = 0;
    if ( this->m_arrSentEvents.m_Size <= 0 )
      return nullptr;
    while ( 1 )
    {
      v4 = this->m_arrSentEvents.m_Memory.m_pMemory[v6];
      Name = KeyValues::GetName(this: v4);
      if ( _V_stricmp(s1: szEventDataKey, s2: Name) == 0 )
        break;
      if ( ++v6 >= this->m_arrSentEvents.m_Size )
        return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v4 = this->m_arrEventData.m_Memory.m_pMemory[v3];
      v5 = KeyValues::GetName(this: v4);
      if ( _V_stricmp(s1: szEventDataKey, s2: v5) == 0 )
        break;
      if ( ++v3 >= this->m_arrEventData.m_Size )
        goto LABEL_4;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10003340
// Name: public: void CUtlVector<class IMatchEventsSink __near *,class CUtlMemory<class IMatchEventsSink __near *,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::Remove(
        CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10003380
// Name: public: virtual void CMatchEventsSubscription::Unsubscribe(class IMatchEventsSink __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::Unsubscribe(CMatchEventsSubscription *this, IMatchEventsSink *pSink)
{
  int m_Size; // eax
  CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int> > *p_m_arrSinks; // ecx
  int v5; // esi
  IMatchEventsSink **i; // edx
  int j; // eax
  int *m_pMemory; // ecx
  bool v9; // cc
  int *v10; // ecx

  if ( pSink != nullptr )
  {
    m_Size = this->m_arrSinks.m_Size;
    p_m_arrSinks = &this->m_arrSinks;
    v5 = 0;
    if ( m_Size > 0 )
    {
      for ( i = p_m_arrSinks->m_Memory.m_pMemory; *i != pSink; ++i )
      {
        if ( ++v5 >= m_Size )
          return;
      }
      if ( v5 >= 0 && v5 < this->m_arrSinks.m_Size && --this->m_arrRefCount.m_Memory.m_pMemory[v5] <= 0 )
      {
        CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::Remove(this: p_m_arrSinks, elem: v5);
        CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::Remove(
          this: (CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int> > *)&this->m_arrRefCount,
          elem: v5);
        for ( j = 0; j < this->m_arrIteratorsOutstanding.m_Size; ++j )
        {
          m_pMemory = this->m_arrIteratorsOutstanding.m_Memory.m_pMemory;
          v9 = m_pMemory[j] < v5;
          v10 = &m_pMemory[j];
          if ( !v9 )
            --*v10;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003410
// Name: public: int CUtlVector<class IMatchEventsSink __near *,class CUtlMemory<class IMatchEventsSink __near *,int>>::InsertBefore(int,class IMatchEventsSink __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::InsertBefore(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this,
        int elem,
        CUtlSymbolTable::StringPool_t **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CUtlSymbolTable::StringPool_t **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003480
// Name: public: CMatchEventsSubscription::CMatchEventsSubscription(void)
// Source: json
//------------------------------------------------------------------------------
CMatchEventsSubscription *__thiscall CMatchEventsSubscription::CMatchEventsSubscription(CMatchEventsSubscription *this)
{
  this->__vftable = (CMatchEventsSubscription_vtbl *)&CMatchEventsSubscription::`vftable';
  this->m_arrSinks.m_Memory.m_pMemory = nullptr;
  this->m_arrSinks.m_Memory.m_nAllocationCount = 0;
  this->m_arrSinks.m_Memory.m_nGrowSize = 0;
  this->m_arrSinks.m_Size = 0;
  this->m_arrSinks.m_pElements = nullptr;
  this->m_arrRefCount.m_Memory.m_pMemory = nullptr;
  this->m_arrRefCount.m_Memory.m_nAllocationCount = 0;
  this->m_arrRefCount.m_Memory.m_nGrowSize = 0;
  this->m_arrRefCount.m_Size = 0;
  this->m_arrRefCount.m_pElements = nullptr;
  this->m_arrIteratorsOutstanding.m_Memory.m_pMemory = nullptr;
  this->m_arrIteratorsOutstanding.m_Memory.m_nAllocationCount = 0;
  this->m_arrIteratorsOutstanding.m_Memory.m_nGrowSize = 0;
  this->m_arrIteratorsOutstanding.m_Size = 0;
  this->m_arrIteratorsOutstanding.m_pElements = nullptr;
  this->m_bBroadcasting = false;
  this->m_bAllowNestedBroadcasts = false;
  this->m_arrQueuedEvents.m_Memory.m_pMemory = nullptr;
  this->m_arrQueuedEvents.m_Memory.m_nAllocationCount = 0;
  this->m_arrQueuedEvents.m_Memory.m_nGrowSize = 0;
  this->m_arrQueuedEvents.m_Size = 0;
  this->m_arrQueuedEvents.m_pElements = nullptr;
  this->m_arrEventData.m_Memory.m_pMemory = nullptr;
  this->m_arrEventData.m_Memory.m_nAllocationCount = 0;
  this->m_arrEventData.m_Memory.m_nGrowSize = 0;
  this->m_arrEventData.m_Size = 0;
  this->m_arrEventData.m_pElements = nullptr;
  this->m_arrSentEvents.m_Memory.m_pMemory = nullptr;
  this->m_arrSentEvents.m_Memory.m_nAllocationCount = 0;
  this->m_arrSentEvents.m_Memory.m_nGrowSize = 0;
  this->m_arrSentEvents.m_Size = 0;
  this->m_arrSentEvents.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100034F0
// Name: public: virtual void CMatchEventsSubscription::Subscribe(class IMatchEventsSink __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::Subscribe(CMatchEventsSubscription *this, IMatchEventsSink *pSink)
{
  int m_Size; // edx
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *p_m_arrSinks; // ecx
  int v5; // eax
  IMatchEventsSink **m_pMemory; // esi
  int v7; // [esp-Ch] [ebp-14h]

  if ( pSink != nullptr )
  {
    m_Size = this->m_arrSinks.m_Size;
    p_m_arrSinks = (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrSinks;
    v5 = 0;
    if ( m_Size <= 0 )
      goto LABEL_6;
    m_pMemory = (IMatchEventsSink **)p_m_arrSinks->m_Memory.m_pMemory;
    while ( *m_pMemory != pSink )
    {
      ++v5;
      ++m_pMemory;
      if ( v5 >= m_Size )
        goto LABEL_6;
    }
    if ( v5 < 0 || v5 >= this->m_arrSinks.m_Size )
    {
LABEL_6:
      CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::InsertBefore(
        this: p_m_arrSinks,
        elem: this->m_arrSinks.m_Size,
        src: (CUtlSymbolTable::StringPool_t **)&pSink);
      v7 = this->m_arrRefCount.m_Size;
      pSink = (IMatchEventsSink *)1;
      CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrRefCount,
        elem: v7,
        src: (CUtlSymbolTable::StringPool_t **)&pSink);
    }
    else
    {
      ++this->m_arrRefCount.m_Memory.m_pMemory[v5];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003570
// Name: public: virtual void CMatchEventsSubscription::BroadcastEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::BroadcastEvent(CMatchEventsSubscription *this, KeyValues *pEvent)
{
  KeyValues *v2; // ebx
  const char *Name; // eax
  netpacket_s *Ptr; // edi
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *p_m_arrSentEvents; // ebp
  IMatchEventsSink *v7; // ecx
  bool v8; // cc
  KeyValues *v9; // edi
  bool v10; // zf
  int i; // edi
  bool v12; // sf
  int m_Size; // [esp-Ch] [ebp-18h]

  v2 = pEvent;
  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "OnNetLanConnectionlessPacket", s2: Name) != 0
    || (Ptr = (netpacket_s *)KeyValues::GetPtr(this: v2, keyName: "rawpkt", defaultValue: nullptr)) == nullptr )
  {
    if ( !this->m_bBroadcasting || this->m_bAllowNestedBroadcasts )
    {
      p_m_arrSentEvents = &this->m_arrSentEvents;
      this->m_bBroadcasting = true;
      CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrSentEvents,
        elem: 0,
        src: (CUtlSymbolTable::StringPool_t **)&pEvent);
      g_pMMF->OnEvent(this: &g_pMMF->IMatchEventsSink, a2: v2);
      m_Size = this->m_arrIteratorsOutstanding.m_Size;
      pEvent = nullptr;
      CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrIteratorsOutstanding,
        elem: m_Size,
        src: (CUtlSymbolTable::StringPool_t **)&pEvent);
      for ( ;
            this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[this->m_arrIteratorsOutstanding.m_Size - 1] < this->m_arrSinks.m_Size;
            ++this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[this->m_arrIteratorsOutstanding.m_Size - 1] )
      {
        v7 = this->m_arrSinks.m_Memory.m_pMemory[this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[this->m_arrIteratorsOutstanding.m_Size - 1]];
        v7->OnEvent(this: v7, a2: v2);
      }
      --this->m_arrIteratorsOutstanding.m_Size;
      v8 = this->m_arrQueuedEvents.m_Size <= 0;
      this->m_bBroadcasting = false;
      if ( v8 )
      {
        for ( i = 0; i < this->m_arrEventData.m_Size; ++i )
          KeyValues::deleteThis(this: this->m_arrEventData.m_Memory.m_pMemory[i]);
        v12 = this->m_arrEventData.m_Memory.m_nGrowSize < 0;
        this->m_arrEventData.m_Size = 0;
        if ( !v12 )
        {
          if ( this->m_arrEventData.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arrEventData.m_Memory.m_pMemory);
            this->m_arrEventData.m_Memory.m_pMemory = nullptr;
          }
          this->m_arrEventData.m_Memory.m_nAllocationCount = 0;
        }
        this->m_arrEventData.m_pElements = this->m_arrEventData.m_Memory.m_pMemory;
        v12 = this->m_arrSentEvents.m_Memory.m_nGrowSize < 0;
        this->m_arrSentEvents.m_Size = 0;
        if ( !v12 )
        {
          if ( p_m_arrSentEvents->m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_arrSentEvents->m_Memory.m_pMemory);
            p_m_arrSentEvents->m_Memory.m_pMemory = nullptr;
          }
          this->m_arrSentEvents.m_Memory.m_nAllocationCount = 0;
        }
        this->m_arrSentEvents.m_pElements = this->m_arrSentEvents.m_Memory.m_pMemory;
        v10 = v2 == nullptr;
      }
      else
      {
        v9 = *this->m_arrQueuedEvents.m_Memory.m_pMemory;
        if ( this->m_arrQueuedEvents.m_Size - 1 > 0 )
          _V_memmove(
            dest: this->m_arrQueuedEvents.m_Memory.m_pMemory,
            src: this->m_arrQueuedEvents.m_Memory.m_pMemory + 1,
            count: 4 * (this->m_arrQueuedEvents.m_Size - 1));
        --this->m_arrQueuedEvents.m_Size;
        this->BroadcastEvent(this, a2: v9);
        v10 = v2 == nullptr;
      }
      if ( !v10 )
        KeyValues::deleteThis(this: v2);
    }
    else
    {
      CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::InsertBefore(
        this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrQueuedEvents,
        elem: this->m_arrQueuedEvents.m_Size,
        src: (CUtlSymbolTable::StringPool_t **)&pEvent);
    }
  }
  else
  {
    KeyValues::deleteThis(this: v2);
    g_pConnectionlessLanMgr->ProcessConnectionlessPacket(this: g_pConnectionlessLanMgr, a2: Ptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003750
// Name: public: virtual void CMatchEventsSubscription::RegisterEventData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::RegisterEventData(CMatchEventsSubscription *this, KeyValues *pEventData)
{
  const char *Name; // eax
  const char *v4; // ebp
  int v5; // esi
  KeyValues **v6; // edi
  const char *v7; // eax

  if ( pEventData != nullptr )
  {
    Name = KeyValues::GetName(this: pEventData);
    v4 = Name;
    if ( Name != nullptr && *Name != 0 )
    {
      v5 = 0;
      if ( this->m_arrEventData.m_Size <= 0 )
      {
LABEL_7:
        CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::InsertBefore(
          this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrEventData,
          elem: this->m_arrEventData.m_Size,
          src: (CUtlSymbolTable::StringPool_t **)&pEventData);
      }
      else
      {
        while ( 1 )
        {
          v6 = &this->m_arrEventData.m_Memory.m_pMemory[v5];
          v7 = KeyValues::GetName(this: *v6);
          if ( _V_stricmp(s1: v4, s2: v7) == 0 )
            break;
          if ( ++v5 >= this->m_arrEventData.m_Size )
            goto LABEL_7;
        }
        KeyValues::deleteThis(this: *v6);
        *v6 = pEventData;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008780
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 2;
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
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008970
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CUtlString *v9; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlString,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    CUtlString::CUtlString(this: v9, string: src);
  return elem;
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x10009970
// Name: public: void CMatchEventsSubscription::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::Shutdown(CMatchEventsSubscription *this)
{
  this->m_bBroadcasting = true;
}

//------------------------------------------------------------------------------
// Address: 0x10009980
// Name: public: virtual class KeyValues __near * CMatchEventsSubscription::GetEventData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchEventsSubscription::GetEventData(
        CMatchEventsSubscription *this,
        const char *szEventDataKey)
{
  int v3; // edi
  KeyValues *v4; // ebx
  const char *v5; // eax
  int v6; // edi
  const char *Name; // eax

  v3 = 0;
  if ( this->m_arrEventData.m_Size <= 0 )
  {
LABEL_4:
    v6 = 0;
    if ( this->m_arrSentEvents.m_Size <= 0 )
      return nullptr;
    while ( 1 )
    {
      v4 = this->m_arrSentEvents.m_Memory.m_pMemory[v6];
      Name = KeyValues::GetName(this: v4);
      if ( _V_stricmp(s1: szEventDataKey, s2: Name) == 0 )
        break;
      if ( ++v6 >= this->m_arrSentEvents.m_Size )
        return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v4 = this->m_arrEventData.m_Memory.m_pMemory[v3];
      v5 = KeyValues::GetName(this: v4);
      if ( _V_stricmp(s1: szEventDataKey, s2: v5) == 0 )
        break;
      if ( ++v3 >= this->m_arrEventData.m_Size )
        goto LABEL_4;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10009A00
// Name: public: virtual void CMatchEventsSubscription::Unsubscribe(class IMatchEventsSink __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::Unsubscribe(CMatchEventsSubscription *this, IMatchEventsSink *pSink)
{
  int m_Size; // ecx
  int v4; // edi
  IMatchEventsSink **i; // eax
  int j; // ecx
  int *v7; // eax

  if ( pSink != nullptr )
  {
    m_Size = this->m_arrSinks.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      for ( i = this->m_arrSinks.m_Memory.m_pMemory; *i != pSink; ++i )
      {
        if ( ++v4 >= m_Size )
          return;
      }
      if ( v4 >= 0 && v4 < m_Size && --this->m_arrRefCount.m_Memory.m_pMemory[v4] <= 0 )
      {
        if ( this->m_arrSinks.m_Size - v4 - 1 > 0 )
          _V_memmove(
            dest: &this->m_arrSinks.m_Memory.m_pMemory[v4],
            src: &this->m_arrSinks.m_Memory.m_pMemory[v4 + 1],
            count: 4 * (this->m_arrSinks.m_Size - v4 - 1));
        --this->m_arrSinks.m_Size;
        if ( this->m_arrRefCount.m_Size - v4 - 1 > 0 )
          _V_memmove(
            dest: &this->m_arrRefCount.m_Memory.m_pMemory[v4],
            src: &this->m_arrRefCount.m_Memory.m_pMemory[v4 + 1],
            count: 4 * (this->m_arrRefCount.m_Size - v4 - 1));
        --this->m_arrRefCount.m_Size;
        for ( j = 0; j < this->m_arrIteratorsOutstanding.m_Size; ++j )
        {
          v7 = &this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[j];
          if ( *v7 >= v4 )
            --*v7;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009B30
// Name: public: CMatchEventsSubscription::CMatchEventsSubscription(void)
// Source: json
//------------------------------------------------------------------------------
CMatchEventsSubscription *__thiscall CMatchEventsSubscription::CMatchEventsSubscription(CMatchEventsSubscription *this)
{
  this->__vftable = (CMatchEventsSubscription_vtbl *)&CMatchEventsSubscription::`vftable';
  this->m_arrSinks.m_Memory.m_pMemory = nullptr;
  this->m_arrSinks.m_Memory.m_nAllocationCount = 0;
  this->m_arrSinks.m_Memory.m_nGrowSize = 0;
  this->m_arrSinks.m_Size = 0;
  this->m_arrSinks.m_pElements = nullptr;
  this->m_arrRefCount.m_Memory.m_pMemory = nullptr;
  this->m_arrRefCount.m_Memory.m_nAllocationCount = 0;
  this->m_arrRefCount.m_Memory.m_nGrowSize = 0;
  this->m_arrRefCount.m_Size = 0;
  this->m_arrRefCount.m_pElements = nullptr;
  this->m_arrIteratorsOutstanding.m_Memory.m_pMemory = nullptr;
  this->m_arrIteratorsOutstanding.m_Memory.m_nAllocationCount = 0;
  this->m_arrIteratorsOutstanding.m_Memory.m_nGrowSize = 0;
  this->m_arrIteratorsOutstanding.m_Size = 0;
  this->m_arrIteratorsOutstanding.m_pElements = nullptr;
  *(_WORD *)&this->m_bBroadcasting = 0;
  this->m_arrQueuedEvents.m_Memory.m_pMemory = nullptr;
  this->m_arrQueuedEvents.m_Memory.m_nAllocationCount = 0;
  this->m_arrQueuedEvents.m_Memory.m_nGrowSize = 0;
  this->m_arrQueuedEvents.m_Size = 0;
  this->m_arrQueuedEvents.m_pElements = nullptr;
  this->m_arrEventData.m_Memory.m_pMemory = nullptr;
  this->m_arrEventData.m_Memory.m_nAllocationCount = 0;
  this->m_arrEventData.m_Memory.m_nGrowSize = 0;
  this->m_arrEventData.m_Size = 0;
  this->m_arrEventData.m_pElements = nullptr;
  this->m_arrSentEvents.m_Memory.m_pMemory = nullptr;
  this->m_arrSentEvents.m_Memory.m_nAllocationCount = 0;
  this->m_arrSentEvents.m_Memory.m_nGrowSize = 0;
  this->m_arrSentEvents.m_Size = 0;
  this->m_arrSentEvents.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10009BA0
// Name: public: virtual void CMatchEventsSubscription::Subscribe(class IMatchEventsSink __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::Subscribe(CMatchEventsSubscription *this, IMatchEventsSink *pSink)
{
  int m_Size; // ecx
  int v4; // eax
  IMatchEventsSink **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  IMatchEventsSink **v8; // ecx
  int v9; // eax
  IMatchEventsSink **v10; // eax
  int v11; // edi
  int v12; // eax
  int *v13; // ecx
  int v14; // eax
  int *v15; // eax

  if ( pSink != nullptr )
  {
    m_Size = this->m_arrSinks.m_Size;
    v4 = 0;
    if ( m_Size <= 0 )
      goto LABEL_6;
    m_pMemory = this->m_arrSinks.m_Memory.m_pMemory;
    while ( *m_pMemory != pSink )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_6;
    }
    if ( v4 < 0 || v4 >= m_Size )
    {
LABEL_6:
      m_nAllocationCount = this->m_arrSinks.m_Memory.m_nAllocationCount;
      v7 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<GCSDK::CLock *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrSinks,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_arrSinks.m_Size;
      v8 = this->m_arrSinks.m_Memory.m_pMemory;
      v9 = this->m_arrSinks.m_Size - v7 - 1;
      this->m_arrSinks.m_pElements = v8;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
      v10 = &this->m_arrSinks.m_Memory.m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = pSink;
      v11 = this->m_arrRefCount.m_Size;
      v12 = this->m_arrRefCount.m_Memory.m_nAllocationCount;
      if ( v11 + 1 > v12 )
        CUtlMemory<GCSDK::CLock *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrRefCount,
          num: v11 - v12 + 1);
      ++this->m_arrRefCount.m_Size;
      v13 = this->m_arrRefCount.m_Memory.m_pMemory;
      v14 = this->m_arrRefCount.m_Size - v11 - 1;
      this->m_arrRefCount.m_pElements = v13;
      if ( v14 > 0 )
        _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
      v15 = &this->m_arrRefCount.m_Memory.m_pMemory[v11];
      if ( v15 != nullptr )
        *v15 = 1;
    }
    else
    {
      ++this->m_arrRefCount.m_Memory.m_pMemory[v4];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009CA0
// Name: public: virtual void CMatchEventsSubscription::BroadcastEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::BroadcastEvent(CMatchEventsSubscription *this, KeyValues *pEvent)
{
  const char *Name; // eax
  netpacket_s *Ptr; // ebx
  int v5; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_arrQueuedEvents; // esi
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  KeyValues **m_pMemory; // eax
  int v14; // ecx
  KeyValues **v15; // eax
  int v16; // ecx
  int v17; // eax
  int *v18; // edx
  int v19; // eax
  int *v20; // ecx
  int i; // eax
  IMatchEventsSink *v22; // eax
  bool v23; // cc
  KeyValues **v24; // ecx
  KeyValues *v25; // esi
  KeyValues *v26; // ecx
  bool v27; // zf
  int j; // esi
  int v29; // [esp+Ch] [ebp-4h]

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "OnNetLanConnectionlessPacket", s2: Name) != 0
    || (Ptr = (netpacket_s *)KeyValues::GetPtr(this: pEvent, keyName: "rawpkt", defaultValue: nullptr)) == nullptr )
  {
    if ( !this->m_bBroadcasting || this->m_bAllowNestedBroadcasts )
    {
      this->m_bBroadcasting = true;
      m_Size = this->m_arrSentEvents.m_Size;
      m_nAllocationCount = this->m_arrSentEvents.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<GCSDK::CLock *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrSentEvents,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_arrSentEvents.m_Size;
      m_pMemory = this->m_arrSentEvents.m_Memory.m_pMemory;
      v14 = this->m_arrSentEvents.m_Size - 1;
      this->m_arrSentEvents.m_pElements = m_pMemory;
      if ( v14 > 0 )
        _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v14);
      v15 = this->m_arrSentEvents.m_Memory.m_pMemory;
      if ( v15 != nullptr )
        *v15 = pEvent;
      g_pMMF->OnEvent(this: &g_pMMF->IMatchEventsSink, a2: pEvent);
      v17 = this->m_arrIteratorsOutstanding.m_Memory.m_nAllocationCount;
      v29 = this->m_arrIteratorsOutstanding.m_Size;
      v16 = v29;
      if ( v29 + 1 > v17 )
      {
        CUtlMemory<GCSDK::CLock *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrIteratorsOutstanding,
          num: v29 - v17 + 1);
        v16 = v29;
      }
      ++this->m_arrIteratorsOutstanding.m_Size;
      v18 = this->m_arrIteratorsOutstanding.m_Memory.m_pMemory;
      v19 = this->m_arrIteratorsOutstanding.m_Size - v16 - 1;
      this->m_arrIteratorsOutstanding.m_pElements = v18;
      if ( v19 > 0 )
      {
        _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
        v16 = v29;
      }
      v20 = &this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[v16];
      if ( v20 != nullptr )
        *v20 = 0;
      for ( i = this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[this->m_arrIteratorsOutstanding.m_Size - 1];
            i < this->m_arrSinks.m_Size;
            i = this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[this->m_arrIteratorsOutstanding.m_Size - 1] )
      {
        v22 = this->m_arrSinks.m_Memory.m_pMemory[i];
        v22->OnEvent(this: v22, a2: pEvent);
        ++this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[this->m_arrIteratorsOutstanding.m_Size - 1];
      }
      --this->m_arrIteratorsOutstanding.m_Size;
      v23 = this->m_arrQueuedEvents.m_Size <= 0;
      this->m_bBroadcasting = false;
      if ( v23 )
      {
        for ( j = 0; j < this->m_arrEventData.m_Size; ++j )
          KeyValues::deleteThis(this: this->m_arrEventData.m_Memory.m_pMemory[j]);
        this->m_arrEventData.m_Size = 0;
        if ( this->m_arrEventData.m_Memory.m_nGrowSize >= 0 )
        {
          if ( this->m_arrEventData.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arrEventData.m_Memory.m_pMemory);
            this->m_arrEventData.m_Memory.m_pMemory = nullptr;
          }
          this->m_arrEventData.m_Memory.m_nAllocationCount = 0;
        }
        this->m_arrEventData.m_pElements = this->m_arrEventData.m_Memory.m_pMemory;
        this->m_arrSentEvents.m_Size = 0;
        if ( this->m_arrSentEvents.m_Memory.m_nGrowSize >= 0 )
        {
          if ( this->m_arrSentEvents.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arrSentEvents.m_Memory.m_pMemory);
            this->m_arrSentEvents.m_Memory.m_pMemory = nullptr;
          }
          this->m_arrSentEvents.m_Memory.m_nAllocationCount = 0;
        }
        this->m_arrSentEvents.m_pElements = this->m_arrSentEvents.m_Memory.m_pMemory;
        v26 = pEvent;
        v27 = pEvent == nullptr;
      }
      else
      {
        v24 = this->m_arrQueuedEvents.m_Memory.m_pMemory;
        v25 = *v24;
        if ( this->m_arrQueuedEvents.m_Size - 1 > 0 )
          _V_memmove(dest: v24, src: v24 + 1, count: 4 * (this->m_arrQueuedEvents.m_Size - 1));
        --this->m_arrQueuedEvents.m_Size;
        this->BroadcastEvent(this, a2: v25);
        v26 = pEvent;
        v27 = pEvent == nullptr;
      }
      if ( !v27 )
        KeyValues::deleteThis(this: v26);
    }
    else
    {
      v5 = this->m_arrQueuedEvents.m_Memory.m_nAllocationCount;
      p_m_arrQueuedEvents = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrQueuedEvents;
      v7 = this->m_arrQueuedEvents.m_Size;
      if ( v7 + 1 > v5 )
        CUtlMemory<GCSDK::CLock *,int>::Grow(this: p_m_arrQueuedEvents, num: v7 - v5 + 1);
      ++p_m_arrQueuedEvents[1].m_pMemory;
      v8 = p_m_arrQueuedEvents->m_pMemory;
      v9 = (int)p_m_arrQueuedEvents[1].m_pMemory - v7 - 1;
      p_m_arrQueuedEvents[1].m_nAllocationCount = (int)p_m_arrQueuedEvents->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
      v10 = &p_m_arrQueuedEvents->m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = (CUtlSymbolTable::StringPool_t *)pEvent;
    }
  }
  else
  {
    KeyValues::deleteThis(this: pEvent);
    g_pConnectionlessLanMgr->ProcessConnectionlessPacket(this: g_pConnectionlessLanMgr, a2: Ptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009F30
// Name: public: virtual void CMatchEventsSubscription::RegisterEventData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::RegisterEventData(CMatchEventsSubscription *this, KeyValues *pEventData)
{
  KeyValues *v2; // ebx
  const char *Name; // eax
  int v5; // esi
  KeyValues **v6; // ebx
  const char *v7; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_arrEventData; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v12; // eax
  KeyValues **v13; // edi
  const char *szEventDataKey; // [esp+8h] [ebp-4h]

  v2 = pEventData;
  if ( pEventData != nullptr )
  {
    Name = KeyValues::GetName(this: pEventData);
    szEventDataKey = Name;
    if ( Name != nullptr && *Name != 0 )
    {
      v5 = 0;
      if ( this->m_arrEventData.m_Size <= 0 )
      {
LABEL_8:
        m_nAllocationCount = this->m_arrEventData.m_Memory.m_nAllocationCount;
        p_m_arrEventData = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrEventData;
        m_Size = this->m_arrEventData.m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<GCSDK::CLock *,int>::Grow(this: p_m_arrEventData, num: m_Size - m_nAllocationCount + 1);
        ++p_m_arrEventData[1].m_pMemory;
        m_pMemory = p_m_arrEventData->m_pMemory;
        v12 = (int)p_m_arrEventData[1].m_pMemory - m_Size - 1;
        p_m_arrEventData[1].m_nAllocationCount = (int)p_m_arrEventData->m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
        v13 = (KeyValues **)&p_m_arrEventData->m_pMemory[m_Size];
        if ( v13 != nullptr )
          *v13 = v2;
      }
      else
      {
        while ( 1 )
        {
          v6 = &this->m_arrEventData.m_Memory.m_pMemory[v5];
          v7 = KeyValues::GetName(this: *v6);
          if ( _V_stricmp(s1: szEventDataKey, s2: v7) == 0 )
            break;
          if ( ++v5 >= this->m_arrEventData.m_Size )
          {
            v2 = pEventData;
            goto LABEL_8;
          }
        }
        KeyValues::deleteThis(this: *v6);
        *v6 = pEventData;
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
// Address: 0x10001A90
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 2;
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
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B90
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

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
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D60
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlString,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10001DD0
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E40
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::Purge(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  CUtlString *m_pMemory; // ecx

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E80
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D30
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 8;
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
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002DC0
// Name: public: void CUtlMemory<struct IGameTypes::WeaponProgression,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<IGameTypes::WeaponProgression,int>::Grow(
        CUtlMemory<IGameTypes::WeaponProgression,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  IGameTypes::WeaponProgression *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 2;
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
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (IGameTypes::WeaponProgression *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v7);
    else
      this->m_pMemory = (IGameTypes::WeaponProgression *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003640
// Name: public: virtual class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> const __near * GameTypes::GetWeaponProgressionForCurrentModeCT(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *__thiscall GameTypes::GetWeaponProgressionForCurrentModeCT(
        GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return &v6->m_WeaponProgressionCT;
}

//------------------------------------------------------------------------------
// Address: 0x100036E0
// Name: public: virtual class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> const __near * GameTypes::GetWeaponProgressionForCurrentModeT(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *__thiscall GameTypes::GetWeaponProgressionForCurrentModeT(
        GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return &v6->m_WeaponProgressionT;
}

//------------------------------------------------------------------------------
// Address: 0x10003C50
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003CC0
// Name: public: void CUtlVector<struct GameTypes::FreestyleBotDifficulty __near *,class CUtlMemory<struct GameTypes::FreestyleBotDifficulty __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int> > *this)
{
  int i; // ebx
  GameTypes::FreestyleBotDifficulty *v3; // edi
  KeyValues *m_pConvars; // ecx
  bool v5; // sf
  GameTypes::FreestyleBotDifficulty **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      m_pConvars = v3->m_pConvars;
      if ( m_pConvars != nullptr )
        KeyValues::deleteThis(this: m_pConvars);
      free(pMem: v3);
    }
  }
  v5 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v5 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003FA0
// Name: public: void CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(
        CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  IGameTypes::WeaponProgression *v3; // esi
  CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004160
// Name: public: void CUtlVector<struct GameTypes::Map __near *,class CUtlMemory<struct GameTypes::Map __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int> > *this)
{
  int v2; // eax
  GameTypes::Map *v3; // esi
  char **m_pMemory; // eax
  char **v5; // eax
  GameTypes::Map **v6; // ecx
  int i; // [esp+8h] [ebp-8h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &v3->m_CTModels.CUtlVectorAutoPurge<char *>);
      v3->m_CTModels.m_Size = 0;
      if ( v3->m_CTModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_CTModels.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_CTModels.m_Memory.m_pMemory);
          v3->m_CTModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_CTModels.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_CTModels.m_Memory.m_pMemory;
      v3->m_CTModels.m_pElements = m_pMemory;
      if ( v3->m_CTModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_CTModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_CTModels.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &v3->m_TModels.CUtlVectorAutoPurge<char *>);
      v3->m_TModels.m_Size = 0;
      if ( v3->m_TModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_TModels.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_TModels.m_Memory.m_pMemory);
          v3->m_TModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_TModels.m_Memory.m_nAllocationCount = 0;
      }
      v5 = v3->m_TModels.m_Memory.m_pMemory;
      v3->m_TModels.m_pElements = v5;
      if ( v3->m_TModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          v3->m_TModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_TModels.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    v6 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100046B0
// Name: public: void CUtlVector<struct GameTypes::GameMode __near *,class CUtlMemory<struct GameTypes::GameMode __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int> > *this)
{
  CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int> > *v1; // esi
  int v2; // eax
  GameTypes::GameMode *v3; // ebx
  KeyValues *m_pConvarsSP; // ecx
  KeyValues *m_pConvarsMP; // ecx
  IGameTypes::WeaponProgression *m_pMemory; // eax
  IGameTypes::WeaponProgression *v7; // eax
  char **v8; // eax
  GameTypes::GameMode **v9; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  for ( i = 0; v2 < v1->m_Size; i = v2 )
  {
    v3 = v1->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      m_pConvarsSP = v3->m_pConvarsSP;
      if ( m_pConvarsSP != nullptr )
        KeyValues::deleteThis(this: m_pConvarsSP);
      m_pConvarsMP = v3->m_pConvarsMP;
      if ( m_pConvarsMP != nullptr )
        KeyValues::deleteThis(this: m_pConvarsMP);
      CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(this: &v3->m_WeaponProgressionT);
      if ( v3->m_WeaponProgressionT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_WeaponProgressionT.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_WeaponProgressionT.m_Memory.m_pMemory);
          v3->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_WeaponProgressionT.m_Memory.m_pMemory;
      v3->m_WeaponProgressionT.m_pElements = m_pMemory;
      if ( v3->m_WeaponProgressionT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(this: &v3->m_WeaponProgressionCT);
      if ( v3->m_WeaponProgressionCT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_WeaponProgressionCT.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_WeaponProgressionCT.m_Memory.m_pMemory);
          v3->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
      }
      v7 = v3->m_WeaponProgressionCT.m_Memory.m_pMemory;
      v3->m_WeaponProgressionCT.m_pElements = v7;
      if ( v3->m_WeaponProgressionCT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v7 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
          v3->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &v3->m_Maps.CUtlVectorAutoPurge<char *>);
      v3->m_Maps.m_Size = 0;
      if ( v3->m_Maps.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Maps.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Maps.m_Memory.m_pMemory);
          v3->m_Maps.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Maps.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v3->m_Maps.m_Memory.m_pMemory;
      v3->m_Maps.m_pElements = v8;
      if ( v3->m_Maps.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v8 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
          v3->m_Maps.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Maps.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v1 = this;
      v2 = i;
    }
    ++v2;
  }
  v1->m_Size = 0;
  if ( v1->m_Memory.m_nGrowSize < 0 )
  {
    v1->m_pElements = v1->m_Memory.m_pMemory;
  }
  else
  {
    if ( v1->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Memory.m_pMemory);
      v1->m_Memory.m_pMemory = nullptr;
    }
    v9 = v1->m_Memory.m_pMemory;
    v1->m_Memory.m_nAllocationCount = 0;
    v1->m_pElements = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004880
// Name: public: void CUtlVector<struct GameTypes::GameType __near *,class CUtlMemory<struct GameTypes::GameType __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int> > *this)
{
  int v2; // eax
  GameTypes::GameType *v3; // esi
  GameTypes::GameMode **m_pMemory; // eax
  GameTypes::GameType **v5; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int>>::PurgeAndDeleteElements(this: &v3->m_GameModes);
      v3->m_GameModes.m_Size = 0;
      if ( v3->m_GameModes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_GameModes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_GameModes.m_Memory.m_pMemory);
          v3->m_GameModes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_GameModes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_GameModes.m_Memory.m_pMemory;
      v3->m_GameModes.m_pElements = m_pMemory;
      if ( v3->m_GameModes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_GameModes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_GameModes.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    v5 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100054F0
// Name: public: int CUtlVector<struct CMatchExtensions::RegisteredInterface_t,class CUtlMemory<struct CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
        CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMatchExtensions::RegisteredInterface_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CMatchExtensions::RegisteredInterface_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        v11->m_pvInterface = nullptr;
        v11->m_nRefCount = 0;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10006170
// Name: public: bool CUtlVector<class CDatacenterCmdBatchImpl __near *,class CUtlMemory<class CDatacenterCmdBatchImpl __near *,int>>::FindAndRemove(class CDatacenterCmdBatchImpl __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CDatacenterCmdBatchImpl *,CUtlMemory<CDatacenterCmdBatchImpl *,int>>::FindAndRemove(
        CUtlVector<CDatacenterCmdBatchImpl *,CUtlMemory<CDatacenterCmdBatchImpl *,int> > *this,
        CDatacenterCmdBatchImpl **src)
{
  int m_Size; // edx
  int v4; // eax
  CDatacenterCmdBatchImpl **m_pMemory; // ebx
  CDatacenterCmdBatchImpl **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006640
// Name: public: bool CUtlVector<class CServer __near *,class CUtlMemory<class CServer __near *,int>>::FindAndFastRemove(class CServer __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CServer *,CUtlMemory<CServer *,int>>::FindAndFastRemove(
        CUtlVector<CServer *,CUtlMemory<CServer *,int> > *this,
        CServer **src)
{
  int m_Size; // esi
  int v3; // eax
  CServer **i; // edx

  m_Size = this->m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  if ( v3 == -1 )
    return 0;
  if ( v3 != m_Size - 1 )
    this->m_Memory.m_pMemory[v3] = this->m_Memory.m_pMemory[m_Size - 1];
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006690
// Name: public: void CUtlVector<class CServer __near *,class CUtlMemory<class CServer __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(
        CUtlVector<CServer *,CUtlMemory<CServer *,int> > *this)
{
  int i; // edi
  CServer *v3; // ecx
  bool v4; // sf
  CServer **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CServer *, int))v3->dtr_CServer)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006DA0
// Name: public: void CMatchEventsSubscription::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::Shutdown(CMatchEventsSubscription *this)
{
  this->m_bBroadcasting = true;
}

//------------------------------------------------------------------------------
// Address: 0x10006DB0
// Name: public: virtual class KeyValues __near * CMatchEventsSubscription::GetEventData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchEventsSubscription::GetEventData(
        CMatchEventsSubscription *this,
        const char *szEventDataKey)
{
  int v3; // edi
  KeyValues *v4; // ebx
  const char *v5; // eax
  int v6; // edi
  const char *Name; // eax

  v3 = 0;
  if ( this->m_arrEventData.m_Size <= 0 )
  {
LABEL_4:
    v6 = 0;
    if ( this->m_arrSentEvents.m_Size <= 0 )
      return nullptr;
    while ( 1 )
    {
      v4 = this->m_arrSentEvents.m_Memory.m_pMemory[v6];
      Name = KeyValues::GetName(this: v4);
      if ( _V_stricmp(s1: szEventDataKey, s2: Name) == 0 )
        break;
      if ( ++v6 >= this->m_arrSentEvents.m_Size )
        return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v4 = this->m_arrEventData.m_Memory.m_pMemory[v3];
      v5 = KeyValues::GetName(this: v4);
      if ( _V_stricmp(s1: szEventDataKey, s2: v5) == 0 )
        break;
      if ( ++v3 >= this->m_arrEventData.m_Size )
        goto LABEL_4;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10006E30
// Name: public: virtual void CMatchEventsSubscription::Unsubscribe(class IMatchEventsSink __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::Unsubscribe(CMatchEventsSubscription *this, IMatchEventsSink *pSink)
{
  int m_Size; // ecx
  int v4; // edi
  IMatchEventsSink **i; // eax
  int j; // ecx
  int *v7; // eax

  if ( pSink != nullptr )
  {
    m_Size = this->m_arrSinks.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
    {
      for ( i = this->m_arrSinks.m_Memory.m_pMemory; *i != pSink; ++i )
      {
        if ( ++v4 >= m_Size )
          return;
      }
      if ( v4 >= 0 && v4 < m_Size && --this->m_arrRefCount.m_Memory.m_pMemory[v4] <= 0 )
      {
        if ( this->m_arrSinks.m_Size - v4 - 1 > 0 )
          _V_memmove(
            dest: &this->m_arrSinks.m_Memory.m_pMemory[v4],
            src: &this->m_arrSinks.m_Memory.m_pMemory[v4 + 1],
            count: 4 * (this->m_arrSinks.m_Size - v4 - 1));
        --this->m_arrSinks.m_Size;
        if ( this->m_arrRefCount.m_Size - v4 - 1 > 0 )
          _V_memmove(
            dest: &this->m_arrRefCount.m_Memory.m_pMemory[v4],
            src: &this->m_arrRefCount.m_Memory.m_pMemory[v4 + 1],
            count: 4 * (this->m_arrRefCount.m_Size - v4 - 1));
        --this->m_arrRefCount.m_Size;
        for ( j = 0; j < this->m_arrIteratorsOutstanding.m_Size; ++j )
        {
          v7 = &this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[j];
          if ( *v7 >= v4 )
            --*v7;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006EF0
// Name: public: CUtlVector<struct CMatchTitleGameSettingsMgr::SearchPass __near *,class CUtlMemory<struct CMatchTitleGameSettingsMgr::SearchPass __near *,int>>::~CUtlVector<struct CMatchTitleGameSettingsMgr::SearchPass __near *,class CUtlMemory<struct CMatchTitleGameSettingsMgr::SearchPass __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006F60
// Name: public: CMatchEventsSubscription::CMatchEventsSubscription(void)
// Source: json
//------------------------------------------------------------------------------
CMatchEventsSubscription *__thiscall CMatchEventsSubscription::CMatchEventsSubscription(CMatchEventsSubscription *this)
{
  this->__vftable = (CMatchEventsSubscription_vtbl *)&CMatchEventsSubscription::`vftable';
  this->m_arrSinks.m_Memory.m_pMemory = nullptr;
  this->m_arrSinks.m_Memory.m_nAllocationCount = 0;
  this->m_arrSinks.m_Memory.m_nGrowSize = 0;
  this->m_arrSinks.m_Size = 0;
  this->m_arrSinks.m_pElements = nullptr;
  this->m_arrRefCount.m_Memory.m_pMemory = nullptr;
  this->m_arrRefCount.m_Memory.m_nAllocationCount = 0;
  this->m_arrRefCount.m_Memory.m_nGrowSize = 0;
  this->m_arrRefCount.m_Size = 0;
  this->m_arrRefCount.m_pElements = nullptr;
  this->m_arrIteratorsOutstanding.m_Memory.m_pMemory = nullptr;
  this->m_arrIteratorsOutstanding.m_Memory.m_nAllocationCount = 0;
  this->m_arrIteratorsOutstanding.m_Memory.m_nGrowSize = 0;
  this->m_arrIteratorsOutstanding.m_Size = 0;
  this->m_arrIteratorsOutstanding.m_pElements = nullptr;
  *(_WORD *)&this->m_bBroadcasting = 0;
  this->m_arrQueuedEvents.m_Memory.m_pMemory = nullptr;
  this->m_arrQueuedEvents.m_Memory.m_nAllocationCount = 0;
  this->m_arrQueuedEvents.m_Memory.m_nGrowSize = 0;
  this->m_arrQueuedEvents.m_Size = 0;
  this->m_arrQueuedEvents.m_pElements = nullptr;
  this->m_arrEventData.m_Memory.m_pMemory = nullptr;
  this->m_arrEventData.m_Memory.m_nAllocationCount = 0;
  this->m_arrEventData.m_Memory.m_nGrowSize = 0;
  this->m_arrEventData.m_Size = 0;
  this->m_arrEventData.m_pElements = nullptr;
  this->m_arrSentEvents.m_Memory.m_pMemory = nullptr;
  this->m_arrSentEvents.m_Memory.m_nAllocationCount = 0;
  this->m_arrSentEvents.m_Memory.m_nGrowSize = 0;
  this->m_arrSentEvents.m_Size = 0;
  this->m_arrSentEvents.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006FD0
// Name: public: virtual void CMatchEventsSubscription::Subscribe(class IMatchEventsSink __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::Subscribe(CMatchEventsSubscription *this, IMatchEventsSink *pSink)
{
  int m_Size; // ecx
  int v4; // eax
  IMatchEventsSink **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  IMatchEventsSink **v8; // ecx
  int v9; // eax
  IMatchEventsSink **v10; // eax
  int v11; // edi
  int v12; // eax
  int *v13; // ecx
  int v14; // eax
  int *v15; // eax

  if ( pSink != nullptr )
  {
    m_Size = this->m_arrSinks.m_Size;
    v4 = 0;
    if ( m_Size <= 0 )
      goto LABEL_6;
    m_pMemory = this->m_arrSinks.m_Memory.m_pMemory;
    while ( *m_pMemory != pSink )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_6;
    }
    if ( v4 < 0 || v4 >= m_Size )
    {
LABEL_6:
      m_nAllocationCount = this->m_arrSinks.m_Memory.m_nAllocationCount;
      v7 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrSinks,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_arrSinks.m_Size;
      v8 = this->m_arrSinks.m_Memory.m_pMemory;
      v9 = this->m_arrSinks.m_Size - v7 - 1;
      this->m_arrSinks.m_pElements = v8;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
      v10 = &this->m_arrSinks.m_Memory.m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = pSink;
      v11 = this->m_arrRefCount.m_Size;
      v12 = this->m_arrRefCount.m_Memory.m_nAllocationCount;
      if ( v11 + 1 > v12 )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrRefCount,
          num: v11 - v12 + 1);
      ++this->m_arrRefCount.m_Size;
      v13 = this->m_arrRefCount.m_Memory.m_pMemory;
      v14 = this->m_arrRefCount.m_Size - v11 - 1;
      this->m_arrRefCount.m_pElements = v13;
      if ( v14 > 0 )
        _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
      v15 = &this->m_arrRefCount.m_Memory.m_pMemory[v11];
      if ( v15 != nullptr )
        *v15 = 1;
    }
    else
    {
      ++this->m_arrRefCount.m_Memory.m_pMemory[v4];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100070D0
// Name: public: virtual void CMatchEventsSubscription::BroadcastEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::BroadcastEvent(CMatchEventsSubscription *this, KeyValues *pEvent)
{
  const char *Name; // eax
  netpacket_s *Ptr; // ebx
  int v5; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_arrQueuedEvents; // esi
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  KeyValues **m_pMemory; // eax
  int v14; // ecx
  KeyValues **v15; // eax
  int v16; // ecx
  int v17; // eax
  int *v18; // edx
  int v19; // eax
  int *v20; // ecx
  int i; // eax
  IMatchEventsSink *v22; // eax
  bool v23; // cc
  KeyValues **v24; // ecx
  KeyValues *v25; // esi
  KeyValues *v26; // ecx
  bool v27; // zf
  int j; // esi
  int v29; // [esp+Ch] [ebp-4h]

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "OnNetLanConnectionlessPacket", s2: Name) != 0
    || (Ptr = (netpacket_s *)KeyValues::GetPtr(this: pEvent, keyName: "rawpkt", defaultValue: nullptr)) == nullptr )
  {
    if ( !this->m_bBroadcasting || this->m_bAllowNestedBroadcasts )
    {
      this->m_bBroadcasting = true;
      m_Size = this->m_arrSentEvents.m_Size;
      m_nAllocationCount = this->m_arrSentEvents.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrSentEvents,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_arrSentEvents.m_Size;
      m_pMemory = this->m_arrSentEvents.m_Memory.m_pMemory;
      v14 = this->m_arrSentEvents.m_Size - 1;
      this->m_arrSentEvents.m_pElements = m_pMemory;
      if ( v14 > 0 )
        _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v14);
      v15 = this->m_arrSentEvents.m_Memory.m_pMemory;
      if ( v15 != nullptr )
        *v15 = pEvent;
      g_pMMF->OnEvent(this: &g_pMMF->IMatchEventsSink, a2: pEvent);
      v17 = this->m_arrIteratorsOutstanding.m_Memory.m_nAllocationCount;
      v29 = this->m_arrIteratorsOutstanding.m_Size;
      v16 = v29;
      if ( v29 + 1 > v17 )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrIteratorsOutstanding,
          num: v29 - v17 + 1);
        v16 = v29;
      }
      ++this->m_arrIteratorsOutstanding.m_Size;
      v18 = this->m_arrIteratorsOutstanding.m_Memory.m_pMemory;
      v19 = this->m_arrIteratorsOutstanding.m_Size - v16 - 1;
      this->m_arrIteratorsOutstanding.m_pElements = v18;
      if ( v19 > 0 )
      {
        _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
        v16 = v29;
      }
      v20 = &this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[v16];
      if ( v20 != nullptr )
        *v20 = 0;
      for ( i = this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[this->m_arrIteratorsOutstanding.m_Size - 1];
            i < this->m_arrSinks.m_Size;
            i = this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[this->m_arrIteratorsOutstanding.m_Size - 1] )
      {
        v22 = this->m_arrSinks.m_Memory.m_pMemory[i];
        v22->OnEvent(this: v22, a2: pEvent);
        ++this->m_arrIteratorsOutstanding.m_Memory.m_pMemory[this->m_arrIteratorsOutstanding.m_Size - 1];
      }
      --this->m_arrIteratorsOutstanding.m_Size;
      v23 = this->m_arrQueuedEvents.m_Size <= 0;
      this->m_bBroadcasting = false;
      if ( v23 )
      {
        for ( j = 0; j < this->m_arrEventData.m_Size; ++j )
          KeyValues::deleteThis(this: this->m_arrEventData.m_Memory.m_pMemory[j]);
        this->m_arrEventData.m_Size = 0;
        if ( this->m_arrEventData.m_Memory.m_nGrowSize >= 0 )
        {
          if ( this->m_arrEventData.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arrEventData.m_Memory.m_pMemory);
            this->m_arrEventData.m_Memory.m_pMemory = nullptr;
          }
          this->m_arrEventData.m_Memory.m_nAllocationCount = 0;
        }
        this->m_arrEventData.m_pElements = this->m_arrEventData.m_Memory.m_pMemory;
        this->m_arrSentEvents.m_Size = 0;
        if ( this->m_arrSentEvents.m_Memory.m_nGrowSize >= 0 )
        {
          if ( this->m_arrSentEvents.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arrSentEvents.m_Memory.m_pMemory);
            this->m_arrSentEvents.m_Memory.m_pMemory = nullptr;
          }
          this->m_arrSentEvents.m_Memory.m_nAllocationCount = 0;
        }
        this->m_arrSentEvents.m_pElements = this->m_arrSentEvents.m_Memory.m_pMemory;
        v26 = pEvent;
        v27 = pEvent == nullptr;
      }
      else
      {
        v24 = this->m_arrQueuedEvents.m_Memory.m_pMemory;
        v25 = *v24;
        if ( this->m_arrQueuedEvents.m_Size - 1 > 0 )
          _V_memmove(dest: v24, src: v24 + 1, count: 4 * (this->m_arrQueuedEvents.m_Size - 1));
        --this->m_arrQueuedEvents.m_Size;
        this->BroadcastEvent(this, a2: v25);
        v26 = pEvent;
        v27 = pEvent == nullptr;
      }
      if ( !v27 )
        KeyValues::deleteThis(this: v26);
    }
    else
    {
      v5 = this->m_arrQueuedEvents.m_Memory.m_nAllocationCount;
      p_m_arrQueuedEvents = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrQueuedEvents;
      v7 = this->m_arrQueuedEvents.m_Size;
      if ( v7 + 1 > v5 )
        CUtlMemory<int,int>::Grow(this: p_m_arrQueuedEvents, num: v7 - v5 + 1);
      ++p_m_arrQueuedEvents[1].m_pMemory;
      v8 = p_m_arrQueuedEvents->m_pMemory;
      v9 = (int)p_m_arrQueuedEvents[1].m_pMemory - v7 - 1;
      p_m_arrQueuedEvents[1].m_nAllocationCount = (int)p_m_arrQueuedEvents->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
      v10 = &p_m_arrQueuedEvents->m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = (CUtlSymbolTable::StringPool_t *)pEvent;
    }
  }
  else
  {
    KeyValues::deleteThis(this: pEvent);
    g_pConnectionlessLanMgr->ProcessConnectionlessPacket(this: g_pConnectionlessLanMgr, a2: Ptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007360
// Name: public: virtual void CMatchEventsSubscription::RegisterEventData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchEventsSubscription::RegisterEventData(CMatchEventsSubscription *this, KeyValues *pEventData)
{
  KeyValues *v2; // ebx
  const char *Name; // eax
  int v5; // esi
  KeyValues **v6; // ebx
  const char *v7; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_arrEventData; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v12; // eax
  KeyValues **v13; // edi
  const char *szEventDataKey; // [esp+8h] [ebp-4h]

  v2 = pEventData;
  if ( pEventData != nullptr )
  {
    Name = KeyValues::GetName(this: pEventData);
    szEventDataKey = Name;
    if ( Name != nullptr && *Name != 0 )
    {
      v5 = 0;
      if ( this->m_arrEventData.m_Size <= 0 )
      {
LABEL_8:
        m_nAllocationCount = this->m_arrEventData.m_Memory.m_nAllocationCount;
        p_m_arrEventData = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrEventData;
        m_Size = this->m_arrEventData.m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<int,int>::Grow(this: p_m_arrEventData, num: m_Size - m_nAllocationCount + 1);
        ++p_m_arrEventData[1].m_pMemory;
        m_pMemory = p_m_arrEventData->m_pMemory;
        v12 = (int)p_m_arrEventData[1].m_pMemory - m_Size - 1;
        p_m_arrEventData[1].m_nAllocationCount = (int)p_m_arrEventData->m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
        v13 = (KeyValues **)&p_m_arrEventData->m_pMemory[m_Size];
        if ( v13 != nullptr )
          *v13 = v2;
      }
      else
      {
        while ( 1 )
        {
          v6 = &this->m_arrEventData.m_Memory.m_pMemory[v5];
          v7 = KeyValues::GetName(this: *v6);
          if ( _V_stricmp(s1: szEventDataKey, s2: v7) == 0 )
            break;
          if ( ++v5 >= this->m_arrEventData.m_Size )
          {
            v2 = pEventData;
            goto LABEL_8;
          }
        }
        KeyValues::deleteThis(this: *v6);
        *v6 = pEventData;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E60
// Name: private: struct GameTypes::GameType __near * GameTypes::GetGameType_Internal(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes::GameType *__thiscall GameTypes::GetGameType_Internal(GameTypes *this, const char *gameType)
{
  const char *v2; // eax
  int v4; // edi
  GameTypes::GameType *v5; // esi

  v2 = gameType;
  if ( gameType != nullptr && *gameType != 0 && (v4 = 0, this->m_GameTypes.m_Size > 0) )
  {
    while ( 1 )
    {
      v5 = this->m_GameTypes.m_Memory.m_pMemory[v4];
      if ( v5 != nullptr && _V_stricmp(s1: v5->m_Name, s2: gameType) == 0 )
        return v5;
      if ( ++v4 >= this->m_GameTypes.m_Size )
      {
        v2 = gameType;
        goto LABEL_8;
      }
    }
  }
  else
  {
LABEL_8:
    _Warning(a1: "GameTypes: could not find matching game type \"%s\".\n", v2);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002ED0
// Name: private: struct GameTypes::GameMode __near * GameTypes::GetGameMode_Internal(struct GameTypes::GameType __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes::GameMode *__thiscall GameTypes::GetGameMode_Internal(
        GameTypes *this,
        GameTypes::GameType *pGameType,
        const char *gameMode)
{
  int v3; // edi
  GameTypes::GameMode *v4; // esi
  char *m_Name; // ebx

  if ( pGameType == nullptr )
  {
    m_Name = "null";
    goto LABEL_11;
  }
  if ( gameMode == nullptr || *gameMode == 0 || (v3 = 0, pGameType->m_GameModes.m_Size <= 0) )
  {
LABEL_8:
    m_Name = pGameType->m_Name;
LABEL_11:
    _Warning(a1: "GameTypes: could not find matching game mode \"%s\" for type \"%s\".\n", gameMode, m_Name);
    return nullptr;
  }
  while ( 1 )
  {
    v4 = pGameType->m_GameModes.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr && _V_stricmp(s1: v4->m_Name, s2: gameMode) == 0 )
      return v4;
    if ( ++v3 >= pGameType->m_GameModes.m_Size )
      goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F50
// Name: private: struct GameTypes::Map __near * GameTypes::GetMap_Internal(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetMap_Internal(GameTypes *this, const char *mapName)
{
  int v4; // eax
  char *v5; // esi
  int v6; // eax
  char *v7; // esi
  int v8; // esi
  GameTypes::Map *v9; // edi
  char mapNameNoExt[36]; // [esp+4h] [ebp-24h] BYREF

  if ( this->m_Maps.m_Size != 0 )
  {
    if ( mapName != nullptr && *mapName != 0 )
    {
      V_strncpy(pDest: mapNameNoExt, pSrc: mapName, maxLen: 33);
      v4 = _V_strlen(str: mapNameNoExt);
      v5 = &mapNameNoExt[v4 - 4];
      if ( v5 >= mapNameNoExt && V_strnicmp(s1: &mapNameNoExt[v4 - 4], s2: ".360", n: 4) == 0 )
        *v5 = 0;
      v6 = _V_strlen(str: mapNameNoExt);
      v7 = &mapNameNoExt[v6 - 4];
      if ( v7 >= mapNameNoExt && V_strnicmp(s1: &mapNameNoExt[v6 - 4], s2: ".bsp", n: 4) == 0 )
        *v7 = 0;
      v8 = 0;
      if ( this->m_Maps.m_Size <= 0 )
      {
LABEL_15:
        _Warning(a1: "GameTypes: could not find matching map \"%s\".\n", mapNameNoExt);
        return nullptr;
      }
      else
      {
        while ( 1 )
        {
          v9 = this->m_Maps.m_Memory.m_pMemory[v8];
          if ( v9 != nullptr && _V_stricmp(s1: v9->m_Name, s2: mapNameNoExt) == 0 )
            return v9;
          if ( ++v8 >= this->m_Maps.m_Size )
            goto LABEL_15;
        }
      }
    }
    else
    {
      _Warning(a1: "GamesTypes: invalid map name.\n");
      return nullptr;
    }
  }
  else
  {
    _Warning(a1: "GamesTypes: no maps have been loaded.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003070
// Name: private: struct GameTypes::FreestyleBotDifficulty __near * GameTypes::GetCurrentFreestyleBotDifficulty_Internal(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes::FreestyleBotDifficulty *__thiscall GameTypes::GetCurrentFreestyleBotDifficulty_Internal(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax

  m_Size = this->m_FreestyleBotDifficulties.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no freestyle bot difficulties have been loaded.\n");
    return nullptr;
  }
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
  {
    m_nValue = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
      goto LABEL_8;
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue < m_Size )
    return this->m_FreestyleBotDifficulties.m_Memory.m_pMemory[m_nValue];
LABEL_8:
  _Warning(
    a1: "GamesTypes: freestyle_bot_difficulty is set to an invalid value (%d). Range [%d,%d].\n",
    m_nValue,
    0,
    m_Size - 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100030C0
// Name: public: virtual char const __near * GameTypes::GetCurrentGameTypeNameID(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes::GameType *__thiscall GameTypes::GetCurrentGameTypeNameID(GameTypes *this)
{
  int m_Size; // edx
  GameTypes::GameType *result; // eax
  int m_nValue; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  result = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( result != nullptr )
    return (GameTypes::GameType *)((char *)result + 36);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003120
// Name: public: virtual char const __near * GameTypes::GetCurrentGameModeNameID(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetCurrentGameModeNameID(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return v6->m_NameID;
}

//------------------------------------------------------------------------------
// Address: 0x100031C0
// Name: public: virtual bool GameTypes::ApplyConvarsForCurrentMode(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall GameTypes::ApplyConvarsForCurrentMode(GameTypes *this, bool isMultiplayer)
{
  int m_Size; // ecx
  int m_nValue; // eax
  GameTypes::GameType *v6; // edx
  int v7; // eax
  GameTypes::GameMode *v8; // ebx
  KeyValues *m_pConvarsSP; // edi
  int v10; // ecx
  int v11; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  int v15; // ecx
  int v16; // eax
  GameTypes *v17; // esi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  GameTypes::FreestyleBotDifficulty *v19; // ebx
  KeyValues *m_pConvars; // edi
  KeyValues *j; // esi
  const char *v22; // eax
  const char *v23; // eax
  int v24; // eax
  int v25; // eax
  ConVarRef conVarRef; // [esp+4h] [ebp-18h] BYREF
  IKeyValuesDumpContext v27; // [esp+Ch] [ebp-10h] BYREF
  GameTypes *v28; // [esp+10h] [ebp-Ch]
  IKeyValuesDumpContext pDump; // [esp+14h] [ebp-8h] BYREF
  GameTypes::GameType *pGameType; // [esp+18h] [ebp-4h]

  m_Size = this->m_GameTypes.m_Size;
  v28 = this;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return 0;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return 0;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v6 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  pGameType = v6;
  if ( v6 == nullptr )
    return 0;
  if ( game_mode.m_pParent != nullptr )
  {
    v7 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v7 < 0 )
    {
LABEL_20:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v7,
        0,
        v6->m_GameModes.m_Size - 1);
      return 0;
    }
  }
  else
  {
    v7 = 0;
  }
  if ( v7 >= v6->m_GameModes.m_Size )
    goto LABEL_20;
  v8 = v6->m_GameModes.m_Memory.m_pMemory[v7];
  if ( v8 == nullptr )
    return 0;
  if ( !isMultiplayer || (m_pConvarsSP = v8->m_pConvarsMP) == nullptr )
  {
    m_pConvarsSP = v8->m_pConvarsSP;
    if ( m_pConvarsSP == nullptr )
    {
      if ( game_mode.m_pParent != nullptr )
        v10 = game_mode.m_pParent->m_Value.m_nValue;
      else
        v10 = 0;
      if ( game_type.m_pParent != nullptr )
        v11 = game_type.m_pParent->m_Value.m_nValue;
      else
        v11 = 0;
      _Warning(
        a1: "GamesTypes: unable to set convars. There are no convars for game type/mode (%s:%d/%s:%d).\n",
        v6->m_Name,
        v11,
        v8->m_Name,
        v10);
      return 0;
    }
  }
  for ( i = KeyValues::GetFirstValue(this: m_pConvarsSP); i != nullptr; i = KeyValues::GetNextValue(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    ConVarRef::ConVarRef(this: &conVarRef, pName: Name);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: str);
    conVarRef.m_pConVar->SetValue_4(this: conVarRef.m_pConVar, a2: String);
  }
  if ( game_mode.m_pParent != nullptr )
    v15 = game_mode.m_pParent->m_Value.m_nValue;
  else
    v15 = 0;
  if ( game_type.m_pParent != nullptr )
    v16 = game_type.m_pParent->m_Value.m_nValue;
  else
    v16 = 0;
  DevMsg(a1: "GameTypes: set convars for game type/mode (%s:%d/%s:%d):\n", pGameType->m_Name, v16, v8->m_Name, v15);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  pGameType = (GameTypes::GameType *)1;
  KeyValues::Dump(this: m_pConvarsSP, &pDump, nIndentLevel: 1);
  v17 = v28;
  if ( v28->GetCurrentGameMode(this: v28) != 2 )
    return 1;
  if ( v17->GetCurrentGameType(this: v17) != 0 )
    return 1;
  CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this: v17);
  v19 = CurrentFreestyleBotDifficulty_Internal;
  if ( CurrentFreestyleBotDifficulty_Internal == nullptr )
    return 1;
  m_pConvars = CurrentFreestyleBotDifficulty_Internal->m_pConvars;
  if ( m_pConvars == nullptr )
  {
    if ( freestyle_bot_difficulty.m_pParent != nullptr )
      v25 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
    else
      v25 = 0;
    _Warning(
      a1: "GamesTypes: unable to set freestyle bot difficulty convars. There are no convars for bot difficulty (%s:%d).\n",
      v19->m_Name,
      v25);
    return 1;
  }
  for ( j = KeyValues::GetFirstValue(this: CurrentFreestyleBotDifficulty_Internal->m_pConvars);
        j != nullptr;
        j = KeyValues::GetNextValue(this: j) )
  {
    v22 = KeyValues::GetName(this: j);
    ConVarRef::ConVarRef(this: &conVarRef, pName: v22);
    v23 = KeyValues::GetString(this: j, keyName: nullptr, defaultValue: str);
    conVarRef.m_pConVar->SetValue_4(this: conVarRef.m_pConVar, a2: v23);
  }
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
    v24 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
  else
    v24 = 0;
  DevMsg(a1: "GameTypes: set convars for freestyle bot difficulty (%s:%d):\n", v19->m_Name, v24);
  v27.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v28 = (GameTypes *)1;
  KeyValues::Dump(this: m_pConvars, pDump: &v27, nIndentLevel: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003460
// Name: public: virtual void GameTypes::DisplayConvarsForCurrentMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GameTypes::DisplayConvarsForCurrentMode(GameTypes *this)
{
  GameTypes *v1; // edx
  int m_Size; // esi
  int m_nValue; // eax
  GameTypes::GameType *v4; // ebx
  ConVar *m_pParent; // ecx
  int v6; // eax
  GameTypes::GameMode *v7; // esi
  KeyValues *m_pConvarsSP; // edi
  int v9; // ecx
  int v10; // eax
  KeyValues *m_pConvarsMP; // edi
  int v12; // ecx
  int v13; // eax
  GameTypes *v14; // edi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  KeyValues *m_pConvars; // esi
  int v17; // ecx
  char title[256]; // [esp+4h] [ebp-104h] BYREF
  GameTypes *v19; // [esp+104h] [ebp-4h]

  v1 = this;
  m_Size = this->m_GameTypes.m_Size;
  v19 = this;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_15:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_15;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return;
  m_pParent = game_mode.m_pParent;
  if ( game_mode.m_pParent != nullptr )
  {
    v6 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v6 < 0 )
    {
LABEL_17:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v6,
        0,
        v4->m_GameModes.m_Size - 1);
      return;
    }
  }
  else
  {
    v6 = 0;
  }
  if ( v6 >= v4->m_GameModes.m_Size )
    goto LABEL_17;
  v7 = v4->m_GameModes.m_Memory.m_pMemory[v6];
  if ( v7 != nullptr )
  {
    m_pConvarsSP = v7->m_pConvarsSP;
    if ( m_pConvarsSP != nullptr )
    {
      if ( game_mode.m_pParent != nullptr )
        v9 = game_mode.m_pParent->m_Value.m_nValue;
      else
        v9 = 0;
      if ( game_type.m_pParent != nullptr )
        v10 = game_type.m_pParent->m_Value.m_nValue;
      else
        v10 = 0;
      V_snprintf(
        pDest: title,
        maxLen: 256,
        pFormat: "GameTypes: dumping convars for game type/mode (%s:%d/%s:%d):",
        v4->m_Name,
        v10,
        v7->m_Name,
        v9);
      GameTypes::DisplayConvars(this: v19, pKV_Convars: m_pConvarsSP, title);
      m_pParent = game_mode.m_pParent;
      v1 = v19;
    }
    m_pConvarsMP = v7->m_pConvarsMP;
    if ( m_pConvarsMP != nullptr )
    {
      if ( m_pParent != nullptr )
        v12 = m_pParent->m_Value.m_nValue;
      else
        v12 = 0;
      if ( game_type.m_pParent != nullptr )
        v13 = game_type.m_pParent->m_Value.m_nValue;
      else
        v13 = 0;
      V_snprintf(
        pDest: title,
        maxLen: 256,
        pFormat: "GameTypes: dumping multiplayer convars for game type/mode (%s:%d/%s:%d):",
        v4->m_Name,
        v13,
        v7->m_Name,
        v12);
      GameTypes::DisplayConvars(this: v19, pKV_Convars: m_pConvarsMP, title);
      v1 = v19;
    }
    if ( v1->GetCurrentGameMode(this: v1) == 2 )
    {
      v14 = v19;
      if ( v19->GetCurrentGameType(this: v19) == 0 )
      {
        CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this: v14);
        if ( CurrentFreestyleBotDifficulty_Internal != nullptr )
        {
          m_pConvars = CurrentFreestyleBotDifficulty_Internal->m_pConvars;
          if ( m_pConvars != nullptr )
          {
            if ( freestyle_bot_difficulty.m_pParent != nullptr )
              v17 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
            else
              v17 = 0;
            V_snprintf(
              pDest: title,
              maxLen: 256,
              pFormat: "GameTypes: dumping convars for freestyle bot difficulty (%s:%d):",
              CurrentFreestyleBotDifficulty_Internal->m_Name,
              v17);
            GameTypes::DisplayConvars(this: v14, pKV_Convars: m_pConvars, title);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003780
// Name: public: virtual char const __near * GameTypes::GetRandomMap(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetRandomMap(GameTypes *this, const char *gameType, const char *gameMode)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameMode *GameMode_Internal; // eax
  GameTypes::GameMode *v6; // esi
  int m_Size; // eax

  if ( gameType != nullptr
    && gameMode != nullptr
    && (GameType_Internal = GameTypes::GetGameType_Internal(this, gameType)) != nullptr
    && (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode),
        v6 = GameMode_Internal,
        GameMode_Internal != nullptr)
    && (m_Size = GameMode_Internal->m_Maps.m_Size) != 0 )
  {
    return v6->m_Maps.m_Memory.m_pMemory[_RandomInt(a1: 0, a2: m_Size - 1)];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100037E0
// Name: public: virtual bool GameTypes::ApplyConvarsForMap(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall GameTypes::ApplyConvarsForMap(GameTypes *this, const char *mapName)
{
  GameTypes::Map *Map_Internal; // edi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  ConVarRef bot_quota; // [esp+Ch] [ebp-8h] BYREF

  Map_Internal = GameTypes::GetMap_Internal(this, mapName);
  if ( Map_Internal != nullptr )
  {
    if ( this->GetCurrentGameMode(this) != 2
      || this->GetCurrentGameType(this) != 0
      || (CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this)) == nullptr
      || !CurrentFreestyleBotDifficulty_Internal->m_HasBotQuota )
    {
      DevMsg(a1: "GameTypes: setting bot_quota to %d for map %s.\n", Map_Internal->m_MinPlayers, Map_Internal->m_Name);
      ConVarRef::ConVarRef(this: &bot_quota, pName: "bot_quota");
      bot_quota.m_pConVar->SetValue_2(this: bot_quota.m_pConVar, a2: Map_Internal->m_MinPlayers);
    }
    return 1;
  }
  else
  {
    _Warning(a1: "GamesTypes: unable to set convars for map %s. Could not find matching map name.\n", mapName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003890
// Name: public: virtual bool GameTypes::GetMapInfo(char const __near *,int __near &,int __near &,unsigned int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetMapInfo(
        GameTypes *this,
        const char *mapName,
        int *maxPlayers,
        int *extraSpectators,
        unsigned int *richPresence)
{
  GameTypes::Map *Map_Internal; // eax

  Map_Internal = GameTypes::GetMap_Internal(this, mapName);
  if ( Map_Internal == nullptr )
    return 0;
  *maxPlayers = Map_Internal->m_MaxPlayers;
  *richPresence = Map_Internal->m_RichPresence;
  *extraSpectators = Map_Internal->m_ExtraSpectators;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100038D0
// Name: public: virtual class CUtlStringList const __near * GameTypes::GetTModelsForMap(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetTModelsForMap(GameTypes *this, const char *mapName)
{
  GameTypes::Map *result; // eax

  result = GameTypes::GetMap_Internal(this, mapName);
  if ( result != nullptr )
    return (GameTypes::Map *)((char *)result + 84);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100038F0
// Name: public: virtual class CUtlStringList const __near * GameTypes::GetCTModelsForMap(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetCTModelsForMap(GameTypes *this, const char *mapName)
{
  GameTypes::Map *result; // eax

  result = GameTypes::GetMap_Internal(this, mapName);
  if ( result != nullptr )
    return (GameTypes::Map *)((char *)result + 104);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003910
// Name: public: virtual char const __near * GameTypes::GetGameTypeFromInt(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetGameTypeFromInt(GameTypes *this, int gameType)
{
  int m_Size; // esi
  int v3; // eax
  GameTypes::GameType **m_pMemory; // edx
  GameTypes::GameType *v5; // ecx

  m_Size = this->m_GameTypes.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    _Warning(a1: "GameTypes: could not find matching game type for value \"%d\".\n", gameType);
    return nullptr;
  }
  else
  {
    m_pMemory = this->m_GameTypes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v5 = *m_pMemory;
      if ( *m_pMemory != nullptr && v5->m_Index == gameType )
        return v5->m_Name;
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003960
// Name: public: virtual char const __near * GameTypes::GetGameModeFromInt(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetGameModeFromInt(GameTypes *this, int gameType, int gameMode)
{
  int m_Size; // edx
  int v5; // edi
  GameTypes::GameType **m_pMemory; // ecx
  GameTypes::GameType *v7; // ecx
  int v8; // esi
  int v9; // eax
  GameTypes::GameMode **v10; // edx
  GameTypes::GameMode *v11; // ecx
  int v13; // [esp+Ch] [ebp-4h]
  int gameModea; // [esp+1Ch] [ebp+Ch]

  m_Size = this->m_GameTypes.m_Size;
  v5 = 0;
  v13 = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_12:
    _Warning(
      a1: "GameTypes: could not find matching game mode value of \"%d\" and type value of \"%d\".\n",
      gameType,
      gameMode);
    return nullptr;
  }
  else
  {
    m_pMemory = this->m_GameTypes.m_Memory.m_pMemory;
    gameModea = (int)m_pMemory;
    while ( 1 )
    {
      v7 = *m_pMemory;
      if ( v7 != nullptr && v7->m_Index == gameType )
      {
        v8 = v7->m_GameModes.m_Size;
        v9 = 0;
        if ( v8 > 0 )
          break;
      }
LABEL_11:
      ++v5;
      m_pMemory = (GameTypes::GameType **)(gameModea + 4);
      gameModea += 4;
      if ( v5 >= m_Size )
        goto LABEL_12;
    }
    v10 = v7->m_GameModes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v11 = *v10;
      if ( *v10 != nullptr && v11->m_Index == gameMode )
        return v11->m_Name;
      ++v9;
      ++v10;
      if ( v9 >= v8 )
      {
        m_Size = v13;
        goto LABEL_11;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100039F0
// Name: public: virtual int GameTypes::GetNoResetVoteThresholdForCurrentModeCT(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetNoResetVoteThresholdForCurrentModeCT(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return -1;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return -1;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return -1;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return -1;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return -1;
  return v6->m_NoResetVoteThresholdCT;
}

//------------------------------------------------------------------------------
// Address: 0x10003A90
// Name: public: virtual int GameTypes::GetNoResetVoteThresholdForCurrentModeT(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetNoResetVoteThresholdForCurrentModeT(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return -1;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return -1;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return -1;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return -1;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return -1;
  return v6->m_NoResetVoteThresholdT;
}

//------------------------------------------------------------------------------
// Address: 0x10003B30
// Name: public: virtual bool GameTypes::GetGameModeAndTypeIntsFromStrings(char const __near *,char const __near *,int __near &,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetGameModeAndTypeIntsFromStrings(
        GameTypes *this,
        const char *szGameType,
        const char *szGameMode,
        int *iOutGameType,
        int *iOutGameMode)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameType *v7; // esi
  GameTypes::GameMode *GameMode_Internal; // eax
  int m_Index; // ecx

  *iOutGameType = -1;
  *iOutGameMode = -1;
  if ( szGameType == nullptr || szGameMode == nullptr )
    return 0;
  GameType_Internal = GameTypes::GetGameType_Internal(this, gameType: szGameType);
  v7 = GameType_Internal;
  if ( GameType_Internal == nullptr
    || (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode: szGameMode)) == nullptr )
  {
    _Warning(
      a1: "GamesTypes: unable to get game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      szGameType,
      szGameMode);
    return 0;
  }
  m_Index = v7->m_Index;
  if ( v7->m_Index < 0
    || m_Index >= this->m_GameTypes.m_Size
    || GameMode_Internal->m_Index < 0
    || GameMode_Internal->m_Index >= v7->m_GameModes.m_Size )
  {
    return 0;
  }
  *iOutGameType = m_Index;
  *iOutGameMode = GameMode_Internal->m_Index;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003BC0
// Name: public: virtual bool GameTypes::GetGameModeAndTypeNameIdsFromStrings(char const __near *,char const __near *,char const __near * __near &,char const __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetGameModeAndTypeNameIdsFromStrings(
        GameTypes *this,
        const char *szGameType,
        const char *szGameMode,
        char **szOutGameTypeNameId,
        char **szOutGameModeNameId)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameType *v7; // esi
  GameTypes::GameMode *GameMode_Internal; // eax

  *szOutGameTypeNameId = nullptr;
  *szOutGameModeNameId = nullptr;
  if ( szGameType == nullptr || szGameMode == nullptr )
    return 0;
  GameType_Internal = GameTypes::GetGameType_Internal(this, gameType: szGameType);
  v7 = GameType_Internal;
  if ( GameType_Internal == nullptr
    || (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode: szGameMode)) == nullptr )
  {
    _Warning(
      a1: "GamesTypes: unable to get game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      szGameType,
      szGameMode);
    return 0;
  }
  if ( GameMode_Internal == (GameTypes::GameMode *)-36 || v7 == (GameTypes::GameType *)-36 )
    return 0;
  *szOutGameTypeNameId = v7->m_NameID;
  *szOutGameModeNameId = GameMode_Internal->m_NameID;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003D40
// Name: public: virtual bool GameTypes::IsInitialized(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __thiscall GameTypes::IsInitialized(GameTypes *this)
{
  return this->m_Initialized;
}

//------------------------------------------------------------------------------
// Address: 0x10003D50
// Name: public: void CUtlStringList::CopyAndAddToTail(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CUtlStringList::CopyAndAddToTail(CUtlStringList *this, const char *pString)
{
  char *v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v7; // eax
  char **v8; // edi

  v3 = (char *)operator new(nSize: strlen(pString) + 1);
  _V_strcpy(dest: v3, src: pString);
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10003DD0
// Name: private: bool GameTypes::LoadFreestyleBotDifficulties(class KeyValues __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadFreestyleBotDifficulties(GameTypes *this, KeyValues *pKV)
{
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // edi
  _DWORD *v6; // eax
  GameTypes::FreestyleBotDifficulty *v7; // ebx
  const char *Name; // eax
  const char *String; // eax
  const char *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  GameTypes::FreestyleBotDifficulty **m_pMemory; // ecx
  int v16; // eax
  GameTypes::FreestyleBotDifficulty **v17; // edi
  const char *v18; // eax
  KeyValues *pKV_BotDiff; // [esp+14h] [ebp+8h]

  if ( pKV == nullptr )
    return 0;
  if ( this->m_FreestyleBotDifficulties.m_Size > 0 )
    CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &this->m_FreestyleBotDifficulties);
  Key = KeyValues::FindKey(this: pKV, keyName: "botDifficulty", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "botDifficulty");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  pKV_BotDiff = FirstTrueSubKey;
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      v6 = operator new(nSize: 0x4Cu);
      v7 = nullptr;
      if ( v6 != nullptr )
      {
        v6[17] = 0;
        *((_BYTE *)v6 + 72) = 0;
        *((_BYTE *)v6 + 4) = 0;
        *((_BYTE *)v6 + 36) = 0;
        *v6 = -1;
        v7 = (GameTypes::FreestyleBotDifficulty *)v6;
      }
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      V_strncpy(pDest: v7->m_Name, pSrc: Name, maxLen: 32);
      String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: str);
      if ( String != nullptr )
      {
        V_strncpy(pDest: v7->m_NameID, pSrc: String, maxLen: 32);
      }
      else
      {
        v10 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for bot difficulty %s.\n", "nameID", v10);
      }
      v11 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "convars", bCreate: false);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v7->m_pConvars = KeyValues::MakeCopy(this: v11);
        v7->m_HasBotQuota = KeyValues::GetInt(this: v12, keyName: "bot_quota", defaultValue: -1) != -1;
      }
      else
      {
        v18 = KeyValues::GetName(this: pKV_BotDiff);
        _Warning(a1: "GameTypes: missing entry %s for bot difficulty %s.\n", "convars", v18);
      }
      v7->m_Index = this->m_FreestyleBotDifficulties.m_Size;
      m_Size = this->m_FreestyleBotDifficulties.m_Size;
      m_nAllocationCount = this->m_FreestyleBotDifficulties.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_FreestyleBotDifficulties,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_FreestyleBotDifficulties.m_Size;
      m_pMemory = this->m_FreestyleBotDifficulties.m_Memory.m_pMemory;
      v16 = this->m_FreestyleBotDifficulties.m_Size - m_Size - 1;
      this->m_FreestyleBotDifficulties.m_pElements = m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
      v17 = &this->m_FreestyleBotDifficulties.m_Memory.m_pMemory[m_Size];
      if ( v17 != nullptr )
        *v17 = v7;
      pKV_BotDiff = KeyValues::GetNextTrueSubKey(this: pKV_BotDiff);
      if ( pKV_BotDiff == nullptr )
        break;
      FirstTrueSubKey = pKV_BotDiff;
    }
  }
  if ( this->m_FreestyleBotDifficulties.m_Size == 0 )
    _Warning(a1: "GamesTypes: empty %s entry.\n", "botDifficulty");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004010
// Name: private: void GameTypes::LoadWeaponProgression(class KeyValues __near *,class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> __near &,char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall GameTypes::LoadWeaponProgression(
        GameTypes *this,
        KeyValues *pKV_WeaponProgression,
        CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *vecWeaponProgression,
        const char *szGameType,
        const char *szGameMode)
{
  KeyValues *v5; // edi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IGameTypes::WeaponProgression *m_pMemory; // ecx
  int v12; // eax
  IGameTypes::WeaponProgression *v13; // edi
  const char *v14; // eax
  IGameTypes::WeaponProgression wp; // [esp+4h] [ebp-14h] BYREF

  v5 = pKV_WeaponProgression;
  if ( pKV_WeaponProgression != nullptr )
  {
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKV_WeaponProgression);
    if ( FirstTrueSubKey != nullptr )
    {
      do
      {
        CUtlString::CUtlString(this: &wp.m_Name);
        wp.m_Kills = 0;
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        CUtlString::Set(this: &wp.m_Name, pValue: Name);
        wp.m_Kills = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "kills", defaultValue: -1);
        if ( wp.m_Kills == -1 )
        {
          wp.m_Kills = 0;
          v8 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(
            a1: "GameTypes: missing %s entry for weapon \"%s\" for game type/mode (%s/%s).\n",
            "kills",
            v8,
            szGameType,
            szGameMode);
        }
        m_Size = vecWeaponProgression->m_Size;
        m_nAllocationCount = vecWeaponProgression->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IGameTypes::WeaponProgression,int>::Grow(
            this: &vecWeaponProgression->m_Memory,
            num: m_Size - m_nAllocationCount + 1);
        ++vecWeaponProgression->m_Size;
        m_pMemory = vecWeaponProgression->m_Memory.m_pMemory;
        v12 = vecWeaponProgression->m_Size - m_Size - 1;
        vecWeaponProgression->m_pElements = vecWeaponProgression->m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v12);
        v13 = &vecWeaponProgression->m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
        {
          CUtlString::CUtlString(this: &v13->m_Name, string: &wp.m_Name);
          v13->m_Kills = wp.m_Kills;
        }
        wp.m_Name.m_Storage.m_nActualLength = 0;
        if ( wp.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && wp.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wp.m_Name.m_Storage.m_Memory.m_pMemory);
        FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      }
      while ( FirstTrueSubKey != nullptr );
      v5 = pKV_WeaponProgression;
    }
    if ( vecWeaponProgression->m_Size == 0 )
    {
      v14 = KeyValues::GetName(this: v5);
      _Warning(a1: "GameTypes: empty %s entry for game type/mode (%s/%s).\n", v14, szGameType, szGameMode);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004290
// Name: public: GameTypes::GameMode::GameMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes::GameMode *__thiscall GameTypes::GameMode::GameMode(GameTypes::GameMode *this)
{
  this->m_pConvarsSP = nullptr;
  this->m_pConvarsMP = nullptr;
  this->m_Index = -1;
  this->m_Maps.m_Memory.m_pMemory = nullptr;
  this->m_Maps.m_Memory.m_nAllocationCount = 0;
  this->m_Maps.m_Memory.m_nGrowSize = 0;
  this->m_Maps.m_Size = 0;
  this->m_Maps.m_pElements = nullptr;
  this->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
  this->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponProgressionCT.m_Memory.m_nGrowSize = 0;
  this->m_WeaponProgressionCT.m_Size = 0;
  this->m_WeaponProgressionCT.m_pElements = nullptr;
  this->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
  this->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponProgressionT.m_Memory.m_nGrowSize = 0;
  this->m_WeaponProgressionT.m_Size = 0;
  this->m_WeaponProgressionT.m_pElements = nullptr;
  this->m_Name[0] = 0;
  this->m_NameID[0] = 0;
  this->m_DescID[0] = 0;
  this->m_NoResetVoteThresholdCT = -1;
  this->m_NoResetVoteThresholdT = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004300
// Name: private: bool GameTypes::LoadMaps(class KeyValues __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadMaps(GameTypes *this, KeyValues *pKV)
{
  GameTypes *v2; // edi
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // ebx
  GameTypes::Map *v6; // eax
  unsigned int v7; // ecx
  GameTypes::Map *v8; // edi
  const char *Name; // eax
  const char *String; // eax
  const char *v11; // eax
  int Int; // eax
  int v13; // eax
  int v14; // eax
  KeyValues *v15; // eax
  KeyValues *i; // esi
  const char *v17; // eax
  KeyValues *v18; // eax
  KeyValues *FirstValue; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CTModels; // esi
  const char *v21; // eax
  const char *v22; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v25; // ecx
  int v26; // eax
  char **v27; // edi
  const char *v28; // eax
  int m_Size; // esi
  CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int> > *p_m_Maps; // edi
  int v31; // eax
  GameTypes::Map **v32; // ecx
  int v33; // eax
  GameTypes::Map **v34; // esi
  const char *v35; // [esp-4h] [ebp-1Ch]
  const char *v36; // [esp-4h] [ebp-1Ch]
  const char *v37; // [esp-4h] [ebp-1Ch]
  const char *v38; // [esp-4h] [ebp-1Ch]
  int v39; // [esp-4h] [ebp-1Ch]
  char *v40; // [esp+Ch] [ebp-Ch]
  KeyValues *pKV_Model; // [esp+14h] [ebp-4h]
  GameTypes::Map *pMap; // [esp+20h] [ebp+8h]

  v2 = this;
  if ( pKV == nullptr )
    return 0;
  if ( this->m_Maps.m_Size > 0 )
    CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &this->m_Maps);
  Key = KeyValues::FindKey(this: pKV, keyName: "maps", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "maps");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  if ( FirstTrueSubKey == nullptr )
    goto LABEL_49;
  do
  {
    v6 = (GameTypes::Map *)operator new(nSize: 0x7Cu);
    if ( v6 != nullptr )
    {
      v7 = g_richPresenceDefault;
      v6->m_Index = -1;
      v6->m_MinPlayers = 0;
      v6->m_MaxPlayers = 0;
      v6->m_ExtraSpectators = 0;
      v6->m_RichPresence = v7;
      v6->m_TModels.m_Memory.m_pMemory = nullptr;
      v6->m_TModels.m_Memory.m_nAllocationCount = 0;
      v6->m_TModels.m_Memory.m_nGrowSize = 0;
      v6->m_TModels.m_Size = 0;
      v6->m_TModels.m_pElements = nullptr;
      v6->m_CTModels.m_Memory.m_pMemory = nullptr;
      v6->m_CTModels.m_Memory.m_nAllocationCount = 0;
      v6->m_CTModels.m_Memory.m_nGrowSize = 0;
      v6->m_CTModels.m_Size = 0;
      v6->m_CTModels.m_pElements = nullptr;
      v8 = v6;
      v6->m_Name[0] = 0;
      v6->m_NameID[0] = 0;
      pMap = v6;
    }
    else
    {
      pMap = nullptr;
      v8 = nullptr;
    }
    Name = KeyValues::GetName(this: FirstTrueSubKey);
    V_strncpy(pDest: v8->m_Name, pSrc: Name, maxLen: 32);
    String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: str);
    if ( String != nullptr )
    {
      V_strncpy(pDest: v8->m_NameID, pSrc: String, maxLen: 32);
    }
    else
    {
      v11 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "nameID", v11);
    }
    Int = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "minplayers", defaultValue: -1);
    v8->m_MinPlayers = Int;
    if ( Int == -1 )
    {
      v35 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "minplayers", v35);
    }
    else
    {
      if ( Int >= 0 )
        goto LABEL_19;
      v36 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: invalid %s entry for map %s.\n", "minplayers", v36);
    }
    v8->m_MinPlayers = 0;
LABEL_19:
    v13 = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "maxplayers", defaultValue: -1);
    v8->m_MaxPlayers = v13;
    if ( v13 == -1 )
    {
      v37 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "maxplayers", v37);
    }
    else
    {
      if ( v13 >= 0 )
        goto LABEL_24;
      v38 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: invalid %s entry for map %s.\n", "maxplayers", v38);
    }
    v8->m_MaxPlayers = 0;
LABEL_24:
    v14 = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "extraspectators", defaultValue: 0);
    v39 = g_richPresenceDefault;
    v8->m_ExtraSpectators = v14;
    v8->m_RichPresence = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "richpresencecontext", defaultValue: v39);
    v15 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "t_models", bCreate: false);
    if ( v15 != nullptr )
    {
      for ( i = KeyValues::GetFirstValue(this: v15); i != nullptr; i = KeyValues::GetNextValue(this: i) )
      {
        v17 = KeyValues::GetName(this: i);
        CUtlStringList::CopyAndAddToTail(this: &v8->m_TModels, pString: v17);
      }
    }
    else
    {
      v21 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "t_models", v21);
    }
    v18 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "ct_models", bCreate: false);
    if ( v18 != nullptr )
    {
      FirstValue = KeyValues::GetFirstValue(this: v18);
      pKV_Model = FirstValue;
      if ( FirstValue != nullptr )
      {
        p_m_CTModels = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v8->m_CTModels;
        while ( 1 )
        {
          v22 = KeyValues::GetName(this: FirstValue);
          v40 = (char *)operator new(nSize: strlen(v22) + 1);
          _V_strcpy(dest: v40, src: v22);
          m_pMemory = p_m_CTModels[1].m_pMemory;
          m_nAllocationCount = p_m_CTModels->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<int,int>::Grow(this: p_m_CTModels, num: (int)m_pMemory - m_nAllocationCount + 1);
          ++p_m_CTModels[1].m_pMemory;
          v25 = p_m_CTModels->m_pMemory;
          v26 = (char *)p_m_CTModels[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_CTModels[1].m_nAllocationCount = (int)p_m_CTModels->m_pMemory;
          if ( v26 > 0 )
            _V_memmove(dest: &v25[(_DWORD)m_pMemory + 1], src: &v25[(_DWORD)m_pMemory], count: 4 * v26);
          v27 = (char **)&p_m_CTModels->m_pMemory[(_DWORD)m_pMemory];
          if ( v27 != nullptr )
            *v27 = v40;
          pKV_Model = KeyValues::GetNextValue(this: pKV_Model);
          if ( pKV_Model == nullptr )
            break;
          FirstValue = pKV_Model;
        }
        v8 = pMap;
      }
    }
    else
    {
      v28 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "ct_models", v28);
    }
    v8->m_Index = this->m_Maps.m_Size;
    m_Size = this->m_Maps.m_Size;
    p_m_Maps = &this->m_Maps;
    v31 = this->m_Maps.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v31 )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)p_m_Maps,
        num: m_Size - v31 + 1);
    ++this->m_Maps.m_Size;
    v32 = p_m_Maps->m_Memory.m_pMemory;
    v33 = this->m_Maps.m_Size - m_Size - 1;
    this->m_Maps.m_pElements = this->m_Maps.m_Memory.m_pMemory;
    if ( v33 > 0 )
      _V_memmove(dest: &v32[m_Size + 1], src: &v32[m_Size], count: 4 * v33);
    v34 = &p_m_Maps->m_Memory.m_pMemory[m_Size];
    if ( v34 != nullptr )
      *v34 = pMap;
    FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
  }
  while ( FirstTrueSubKey != nullptr );
  v2 = this;
LABEL_49:
  if ( v2->m_Maps.m_Size == 0 )
    _Warning(a1: "GamesTypes: empty %s entry.\n", "maps");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004950
// Name: private: bool GameTypes::LoadGameTypes(class KeyValues __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadGameTypes(GameTypes *this, KeyValues *pKV)
{
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // edi
  GameTypes::GameType *v5; // eax
  GameTypes::GameType *v6; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v9; // eax
  KeyValues *v10; // eax
  KeyValues *NextTrueSubKey; // ebx
  GameTypes::GameMode *v12; // eax
  GameTypes::GameMode *v13; // esi
  const char *v14; // eax
  const char *v15; // eax
  void (*v16)(const char *, ...); // esi
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  KeyValues *v20; // eax
  const char *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  KeyValues *FirstValue; // edi
  const char *v25; // eax
  const char *v26; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v30; // eax
  char **v31; // edi
  const char *v32; // eax
  const char *v33; // eax
  KeyValues *v34; // esi
  const char *v35; // eax
  const char *v36; // eax
  KeyValues *v37; // eax
  const char *v38; // eax
  bool v39; // zf
  int v40; // eax
  KeyValues *v41; // eax
  int v42; // esi
  const char *v43; // eax
  int v44; // edi
  int v45; // eax
  GameTypes::GameMode **v46; // ecx
  int v47; // eax
  GameTypes::GameMode **v48; // edi
  const char *v49; // eax
  int v50; // ebx
  int v51; // eax
  GameTypes::GameType **v52; // ecx
  int v53; // eax
  GameTypes::GameType **v54; // eax
  const char *v55; // eax
  const char *v56; // [esp-8h] [ebp-28h]
  const char *v57; // [esp-8h] [ebp-28h]
  const char *v58; // [esp-8h] [ebp-28h]
  const char *v59; // [esp-8h] [ebp-28h]
  const char *v60; // [esp-8h] [ebp-28h]
  const char *v61; // [esp-8h] [ebp-28h]
  const char *v62; // [esp-8h] [ebp-28h]
  char *s2; // [esp+8h] [ebp-18h]
  char *s2a; // [esp+8h] [ebp-18h]
  char *pKV_WeaponProgressionT; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTc; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTa; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTb; // [esp+Ch] [ebp-14h]
  GameTypes::GameType *pGameType; // [esp+14h] [ebp-Ch]
  KeyValues *pKV_Map; // [esp+18h] [ebp-8h]
  KeyValues *pKV_Mapa; // [esp+18h] [ebp-8h]
  KeyValues *pKV_GameType; // [esp+1Ch] [ebp-4h]
  GameTypes::GameMode *pGameMode; // [esp+28h] [ebp+8h]

  if ( pKV == nullptr )
    return 0;
  if ( this->m_GameTypes.m_Size > 0 )
    CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &this->m_GameTypes);
  Key = KeyValues::FindKey(this: pKV, keyName: "gameTypes", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "gameTypes");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  pKV_GameType = FirstTrueSubKey;
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      v5 = (GameTypes::GameType *)operator new(nSize: 0x58u);
      if ( v5 != nullptr )
      {
        v5->m_Index = -1;
        v5->m_GameModes.m_Memory.m_pMemory = nullptr;
        v5->m_GameModes.m_Memory.m_nAllocationCount = 0;
        v5->m_GameModes.m_Memory.m_nGrowSize = 0;
        v5->m_GameModes.m_Size = 0;
        v5->m_GameModes.m_pElements = nullptr;
        v6 = v5;
        v5->m_Name[0] = 0;
        v5->m_NameID[0] = 0;
        pGameType = v5;
      }
      else
      {
        pGameType = nullptr;
        v6 = nullptr;
      }
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      V_strncpy(pDest: v6->m_Name, pSrc: Name, maxLen: 32);
      String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: str);
      if ( String != nullptr )
      {
        V_strncpy(pDest: v6->m_NameID, pSrc: String, maxLen: 32);
      }
      else
      {
        v9 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for game type %s.\n", "nameID", v9);
      }
      v10 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "gameModes", bCreate: false);
      if ( v10 != nullptr )
      {
        NextTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v10);
        if ( NextTrueSubKey != nullptr )
        {
          do
          {
            v12 = (GameTypes::GameMode *)operator new(nSize: 0xB0u);
            if ( v12 != nullptr )
            {
              v13 = GameTypes::GameMode::GameMode(this: v12);
              pGameMode = v13;
            }
            else
            {
              pGameMode = nullptr;
              v13 = nullptr;
            }
            v14 = KeyValues::GetName(this: NextTrueSubKey);
            V_strncpy(pDest: v13->m_Name, pSrc: v14, maxLen: 32);
            v15 = KeyValues::GetString(this: NextTrueSubKey, keyName: "nameID", defaultValue: str);
            if ( v15 != nullptr )
            {
              V_strncpy(pDest: v13->m_NameID, pSrc: v15, maxLen: 32);
              v16 = (void (*)(const char *, ...))_Warning;
            }
            else
            {
              v56 = KeyValues::GetName(this: NextTrueSubKey);
              v17 = KeyValues::GetName(this: FirstTrueSubKey);
              v16 = (void (*)(const char *, ...))_Warning;
              _Warning(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "nameID", v17, v56);
            }
            v18 = KeyValues::GetString(this: NextTrueSubKey, keyName: "descID", defaultValue: str);
            if ( v18 != nullptr )
            {
              V_strncpy(pDest: pGameMode->m_DescID, pSrc: v18, maxLen: 32);
            }
            else
            {
              v57 = KeyValues::GetName(this: NextTrueSubKey);
              v19 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "descID", v19, v57);
            }
            v20 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "convars", bCreate: false);
            if ( v20 != nullptr )
            {
              pGameMode->m_pConvarsSP = KeyValues::MakeCopy(this: v20);
            }
            else
            {
              v58 = KeyValues::GetName(this: NextTrueSubKey);
              v21 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing entry %s for game type/mode (%s/%s).\n", "convars", v21, v58);
            }
            v22 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "convars_mp", bCreate: false);
            if ( v22 != nullptr )
              pGameMode->m_pConvarsMP = KeyValues::MakeCopy(this: v22);
            v23 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "maps", bCreate: false);
            if ( v23 != nullptr )
            {
              FirstValue = KeyValues::GetFirstValue(this: v23);
              pKV_Map = FirstValue;
              if ( FirstValue != nullptr )
              {
                while ( 1 )
                {
                  v25 = KeyValues::GetName(this: FirstValue);
                  if ( _V_stricmp(s1: v25, s2: "random") != 0 )
                  {
                    v26 = KeyValues::GetName(this: FirstValue);
                    pKV_WeaponProgressionT = (char *)operator new(nSize: strlen(v26) + 1);
                    _V_strcpy(dest: pKV_WeaponProgressionT, src: v26);
                    m_Size = pGameMode->m_Maps.m_Size;
                    m_nAllocationCount = pGameMode->m_Maps.m_Memory.m_nAllocationCount;
                    if ( m_Size + 1 > m_nAllocationCount )
                      CUtlMemory<int,int>::Grow(
                        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&pGameMode->m_Maps,
                        num: m_Size - m_nAllocationCount + 1);
                    ++pGameMode->m_Maps.m_Size;
                    m_pMemory = pGameMode->m_Maps.m_Memory.m_pMemory;
                    v30 = pGameMode->m_Maps.m_Size - m_Size - 1;
                    pGameMode->m_Maps.m_pElements = m_pMemory;
                    if ( v30 > 0 )
                      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v30);
                    v31 = &pGameMode->m_Maps.m_Memory.m_pMemory[m_Size];
                    if ( v31 != nullptr )
                      *v31 = pKV_WeaponProgressionT;
                    FirstValue = pKV_Map;
                  }
                  pKV_Map = KeyValues::GetNextValue(this: FirstValue);
                  if ( pKV_Map == nullptr )
                    break;
                  FirstValue = pKV_Map;
                }
              }
              if ( pGameMode->m_Maps.m_Size == 0 )
              {
                v59 = KeyValues::GetName(this: NextTrueSubKey);
                v32 = KeyValues::GetName(this: pKV_GameType);
                _Warning(a1: "GameTypes: empty %s entry for game type/mode (%s/%s).\n", "maps", v32, v59);
              }
            }
            else
            {
              v60 = KeyValues::GetName(this: NextTrueSubKey);
              v33 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "maps", v33, v60);
            }
            v34 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "weaponprogression_ct", bCreate: false);
            v61 = KeyValues::GetName(this: NextTrueSubKey);
            v35 = KeyValues::GetName(this: pKV_GameType);
            GameTypes::LoadWeaponProgression(
              this,
              pKV_WeaponProgression: v34,
              vecWeaponProgression: &pGameMode->m_WeaponProgressionCT,
              szGameType: v35,
              szGameMode: v61);
            pKV_WeaponProgressionTc = KeyValues::FindKey(
                                        this: NextTrueSubKey,
                                        keyName: "weaponprogression_t",
                                        bCreate: false);
            v62 = KeyValues::GetName(this: NextTrueSubKey);
            v36 = KeyValues::GetName(this: pKV_GameType);
            GameTypes::LoadWeaponProgression(
              this,
              pKV_WeaponProgression: pKV_WeaponProgressionTc,
              vecWeaponProgression: &pGameMode->m_WeaponProgressionT,
              szGameType: v36,
              szGameMode: v62);
            v37 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "no_reset_vote_threshold_t", bCreate: false);
            if ( v37 != nullptr )
            {
              s2 = (char *)KeyValues::GetString(this: v37, keyName: nullptr, defaultValue: str);
              pKV_WeaponProgressionTa = nullptr;
              if ( pGameMode->m_WeaponProgressionT.m_Size <= 0 )
              {
LABEL_53:
                v40 = -1;
              }
              else
              {
                pKV_Mapa = nullptr;
                while ( 1 )
                {
                  v38 = CUtlString::operator char const *(this: (CUtlString *)((char *)pKV_Mapa
                                                                             + (unsigned int)pGameMode->m_WeaponProgressionT.m_Memory.m_pMemory));
                  v39 = _V_strcmp(s1: v38, s2) == 0;
                  v40 = (int)pKV_WeaponProgressionTa;
                  if ( v39 )
                    break;
                  pKV_Mapa = (KeyValues *)((char *)pKV_Mapa + 20);
                  pKV_WeaponProgressionTa = (KeyValues *)((char *)pKV_WeaponProgressionTa + 1);
                  if ( (int)pKV_WeaponProgressionTa >= pGameMode->m_WeaponProgressionT.m_Size )
                    goto LABEL_53;
                }
              }
              pGameMode->m_NoResetVoteThresholdT = v40;
            }
            v41 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "no_reset_vote_threshold_ct", bCreate: false);
            v42 = 0;
            if ( v41 != nullptr )
            {
              s2a = (char *)KeyValues::GetString(this: v41, keyName: nullptr, defaultValue: str);
              if ( pGameMode->m_WeaponProgressionCT.m_Size <= 0 )
              {
LABEL_60:
                v42 = -1;
              }
              else
              {
                pKV_WeaponProgressionTb = nullptr;
                while ( 1 )
                {
                  v43 = CUtlString::operator char const *(this: (CUtlString *)((char *)pKV_WeaponProgressionTb
                                                                             + (unsigned int)pGameMode->m_WeaponProgressionCT.m_Memory.m_pMemory));
                  if ( _V_strcmp(s1: v43, s2: s2a) == 0 )
                    break;
                  pKV_WeaponProgressionTb = (KeyValues *)((char *)pKV_WeaponProgressionTb + 20);
                  if ( ++v42 >= pGameMode->m_WeaponProgressionCT.m_Size )
                    goto LABEL_60;
                }
              }
              pGameMode->m_NoResetVoteThresholdCT = v42;
            }
            pGameMode->m_Index = pGameType->m_GameModes.m_Size;
            v44 = pGameType->m_GameModes.m_Size;
            v45 = pGameType->m_GameModes.m_Memory.m_nAllocationCount;
            if ( v44 + 1 > v45 )
              CUtlMemory<int,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&pGameType->m_GameModes,
                num: v44 - v45 + 1);
            ++pGameType->m_GameModes.m_Size;
            v46 = pGameType->m_GameModes.m_Memory.m_pMemory;
            v47 = pGameType->m_GameModes.m_Size - v44 - 1;
            pGameType->m_GameModes.m_pElements = v46;
            if ( v47 > 0 )
              _V_memmove(dest: &v46[v44 + 1], src: &v46[v44], count: 4 * v47);
            v48 = &pGameType->m_GameModes.m_Memory.m_pMemory[v44];
            if ( v48 != nullptr )
              *v48 = pGameMode;
            FirstTrueSubKey = pKV_GameType;
            NextTrueSubKey = KeyValues::GetNextTrueSubKey(this: NextTrueSubKey);
          }
          while ( NextTrueSubKey != nullptr );
          v6 = pGameType;
        }
      }
      else
      {
        v55 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for game type %s.\n", "gameModes", v55);
      }
      if ( v6->m_GameModes.m_Size == 0 )
      {
        v49 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: empty %s entry for game type %s.\n", "gameModes", v49);
      }
      v6->m_Index = this->m_GameTypes.m_Size;
      v50 = this->m_GameTypes.m_Size;
      v51 = this->m_GameTypes.m_Memory.m_nAllocationCount;
      if ( v50 + 1 > v51 )
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_GameTypes,
          num: v50 - v51 + 1);
      ++this->m_GameTypes.m_Size;
      v52 = this->m_GameTypes.m_Memory.m_pMemory;
      v53 = this->m_GameTypes.m_Size - v50 - 1;
      this->m_GameTypes.m_pElements = v52;
      if ( v53 > 0 )
        _V_memmove(dest: &v52[v50 + 1], src: &v52[v50], count: 4 * v53);
      v54 = &this->m_GameTypes.m_Memory.m_pMemory[v50];
      if ( v54 != nullptr )
        *v54 = v6;
      pKV_GameType = KeyValues::GetNextTrueSubKey(this: pKV_GameType);
      if ( pKV_GameType == nullptr )
        break;
      FirstTrueSubKey = pKV_GameType;
    }
  }
  if ( this->m_GameTypes.m_Size == 0 )
    _Warning(a1: "GameTypes: empty %s entry.\n", "gameTypes");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004FB0
// Name: public: virtual bool GameTypes::Initialize(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall GameTypes::Initialize(GameTypes *this, bool force)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax

  if ( this->m_Initialized && !force )
    return 1;
  DevMsg(a1: "GameTypes: initializing game types interface from %s.\n", "GameModes.txt");
  CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &this->m_GameTypes);
  CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &this->m_Maps);
  CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &this->m_FreestyleBotDifficulties);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: str);
  else
    v5 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v5,
          filesystem: v6,
          resourceName: "GameModes.txt",
          pathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Warning(a1: "GameTypes: error loading %s.", "GameModes.txt");
    goto LABEL_12;
  }
  DLCHelper::AppendDLCKeyValues(pKeyValues: v5, fileName: "GameModes.txt", startDir: nullptr);
  if ( GameTypes::LoadGameTypes(this, pKV: v5) == 0
    || GameTypes::LoadMaps(this, pKV: v5) == 0
    || GameTypes::LoadFreestyleBotDifficulties(this, pKV: v5) == 0 )
  {
LABEL_12:
    if ( v5 != nullptr )
      KeyValues::deleteThis(this: v5);
    return 0;
  }
  this->m_Initialized = true;
  if ( v5 != nullptr )
    KeyValues::deleteThis(this: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100050B0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x100050D0
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _calloc_crt(unsigned int count, unsigned int size)
{
  unsigned __int8 *v2; // edi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * count);
  memset(dst: v2, value: 0, count: size * count);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10005100
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10005120
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: v3, value: 0, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10005160
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x10005180
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006240
// Name: public: virtual void CDatacenterCmdBatchImpl::AddCommand(class KeyValues __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::AddCommand(CDatacenterCmdBatchImpl *this, KeyValues *pCommand)
{
  KeyValues *Copy; // eax
  int m_Size; // edi
  KeyValues *v5; // ebx
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v8; // eax
  KeyValues **v9; // eax

  if ( pCommand != nullptr )
  {
    Copy = KeyValues::MakeCopy(this: pCommand);
    m_Size = this->m_arrCommands.m_Size;
    v5 = Copy;
    m_nAllocationCount = this->m_arrCommands.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrCommands,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_arrCommands.m_Size;
    m_pMemory = this->m_arrCommands.m_Memory.m_pMemory;
    v8 = this->m_arrCommands.m_Size - m_Size - 1;
    this->m_arrCommands.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_arrCommands.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = v5;
  }
}

} // namespace matchmaking_ds
