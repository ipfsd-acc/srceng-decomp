// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/threadhelpers.cpp
// Functions: 12
// ============================================================

#include "utils\vmpi\threadhelpers.h"

//------------------------------------------------------------------------------
// Address: 0x100287A0
// Name: protected: void CCriticalSection::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::Lock(CCriticalSection *this)
{
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x100287B0
// Name: protected: void CCriticalSection::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::Unlock(CCriticalSection *this)
{
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x100287C0
// Name: public: CCriticalSectionLock::CCriticalSectionLock(class CCriticalSection __near *)
// Source: json
//------------------------------------------------------------------------------
CCriticalSectionLock *__thiscall CCriticalSectionLock::CCriticalSectionLock(
        CCriticalSectionLock *this,
        CCriticalSection *pCS)
{
  this->m_pCS = pCS;
  this->m_bLocked = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100287E0
// Name: public: CCriticalSectionLock::~CCriticalSectionLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::~CCriticalSectionLock(CCriticalSectionLock *this)
{
  if ( this->m_bLocked )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this->m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x100287F0
// Name: public: void CCriticalSectionLock::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Lock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = true;
  EnterCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x10028800
// Name: public: void CCriticalSectionLock::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Unlock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = false;
  LeaveCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x10028830
// Name: public: bool CEvent::SetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::SetEvent(CEvent *this)
{
  return SetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10028840
// Name: public: bool CEvent::ResetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::ResetEvent(CEvent *this)
{
  return ResetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10028850
// Name: public: CEvent::~CEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEvent::~CEvent(CEvent *this)
{
  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028870
// Name: public: bool CEvent::Init(bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEvent::Init(CEvent *this, bool bManualReset, bool bInitialState)
{
  HANDLE EventA; // eax

  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
  EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset, bInitialState, lpName: nullptr);
  this->m_hEvent = EventA;
  return EventA != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100288B0
// Name: public: CCriticalSection::CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
CCriticalSection *__thiscall CCriticalSection::CCriticalSection(CCriticalSection *this)
{
  UtlLinkedListElem_t<unsigned long,int> *m_pMemory; // eax

  this->m_Locks.m_Memory.m_pMemory = nullptr;
  this->m_Locks.m_Memory.m_nAllocationCount = 0;
  this->m_Locks.m_Memory.m_nGrowSize = 0;
  this->m_Locks.m_LastAlloc.index = -1;
  this->m_Locks.m_ElementCount = 0;
  this->m_Locks.m_NumAlloced = 0;
  m_pMemory = this->m_Locks.m_Memory.m_pMemory;
  this->m_Locks.m_Head = -1;
  this->m_Locks.m_Tail = -1;
  this->m_Locks.m_FirstFree = -1;
  this->m_Locks.m_pElements = m_pMemory;
  InitializeCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100288F0
// Name: public: CCriticalSection::~CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::~CCriticalSection(CCriticalSection *this)
{
  DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Locks);
  if ( this->m_Locks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Locks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Locks.m_Memory.m_pMemory);
      this->m_Locks.m_Memory.m_pMemory = nullptr;
    }
    this->m_Locks.m_Memory.m_nAllocationCount = 0;
  }
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x1000FDC0
// Name: protected: void CCriticalSection::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::Lock(CCriticalSection *this)
{
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x1000FDD0
// Name: protected: void CCriticalSection::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::Unlock(CCriticalSection *this)
{
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x1000FDE0
// Name: public: CCriticalSectionLock::CCriticalSectionLock(class CCriticalSection __near *)
// Source: json
//------------------------------------------------------------------------------
CCriticalSectionLock *__thiscall CCriticalSectionLock::CCriticalSectionLock(
        CCriticalSectionLock *this,
        CCriticalSection *pCS)
{
  this->m_pCS = pCS;
  this->m_bLocked = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000FE00
// Name: public: CCriticalSectionLock::~CCriticalSectionLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::~CCriticalSectionLock(CCriticalSectionLock *this)
{
  if ( this->m_bLocked )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this->m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE10
// Name: public: void CCriticalSectionLock::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Lock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = true;
  EnterCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE20
// Name: public: void CCriticalSectionLock::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Unlock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = false;
  LeaveCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE30
// Name: public: bool CEvent::SetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::SetEvent(CEvent *this)
{
  return SetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE40
// Name: public: bool CEvent::ResetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::ResetEvent(CEvent *this)
{
  return ResetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE50
// Name: public: CEvent::~CEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEvent::~CEvent(CEvent *this)
{
  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FE70
// Name: public: bool CEvent::Init(bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEvent::Init(CEvent *this, bool bManualReset, bool bInitialState)
{
  HANDLE EventA; // eax

  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
  EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset, bInitialState, lpName: nullptr);
  this->m_hEvent = EventA;
  return EventA != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000FEB0
// Name: public: CCriticalSection::CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
CCriticalSection *__thiscall CCriticalSection::CCriticalSection(CCriticalSection *this)
{
  UtlLinkedListElem_t<unsigned long,int> *m_pMemory; // eax

  this->m_Locks.m_Memory.m_pMemory = nullptr;
  this->m_Locks.m_Memory.m_nAllocationCount = 0;
  this->m_Locks.m_Memory.m_nGrowSize = 0;
  this->m_Locks.m_LastAlloc.index = -1;
  this->m_Locks.m_ElementCount = 0;
  this->m_Locks.m_NumAlloced = 0;
  m_pMemory = this->m_Locks.m_Memory.m_pMemory;
  this->m_Locks.m_Head = -1;
  this->m_Locks.m_Tail = -1;
  this->m_Locks.m_FirstFree = -1;
  this->m_Locks.m_pElements = m_pMemory;
  InitializeCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000FEF0
// Name: public: CCriticalSection::~CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::~CCriticalSection(CCriticalSection *this)
{
  DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Locks);
  if ( this->m_Locks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Locks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Locks.m_Memory.m_pMemory);
      this->m_Locks.m_Memory.m_pMemory = nullptr;
    }
    this->m_Locks.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vmpi_service (Missing functions)
// ============================================================
namespace vmpi_service {

//------------------------------------------------------------------------------
// Address: 0x00405990
// Name: public: CCriticalSectionLock::CCriticalSectionLock(class CCriticalSection __near *)
// Source: json
//------------------------------------------------------------------------------
CCriticalSectionLock *__thiscall CCriticalSectionLock::CCriticalSectionLock(
        CCriticalSectionLock *this,
        CCriticalSection *pCS)
{
  this->m_pCS = pCS;
  this->m_bLocked = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004059B0
// Name: public: CCriticalSectionLock::~CCriticalSectionLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::~CCriticalSectionLock(CCriticalSectionLock *this)
{
  if ( this->m_bLocked )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this->m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x004059C0
// Name: public: void CCriticalSectionLock::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Lock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = true;
  EnterCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x004059D0
// Name: public: void CCriticalSectionLock::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Unlock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = false;
  LeaveCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x004059E0
// Name: public: CEvent::CEvent(void)
// Source: json
//------------------------------------------------------------------------------
CEvent *__thiscall CEvent::CEvent(CEvent *this)
{
  this->m_hEvent = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004059F0
// Name: public: void __near * CEvent::GetEventHandle(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CEvent::GetEventHandle(CEvent *this)
{
  return this->m_hEvent;
}

//------------------------------------------------------------------------------
// Address: 0x00405A00
// Name: public: bool CEvent::SetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::SetEvent(CEvent *this)
{
  return SetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x00405A10
// Name: public: bool CEvent::ResetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::ResetEvent(CEvent *this)
{
  return ResetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x00405A20
// Name: public: CEvent::~CEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEvent::~CEvent(CEvent *this)
{
  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A40
// Name: public: bool CEvent::Init(bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEvent::Init(CEvent *this, bool bManualReset, bool bInitialState)
{
  HANDLE EventA; // eax

  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
  EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset, bInitialState, lpName: nullptr);
  this->m_hEvent = EventA;
  return EventA != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405A80
// Name: public: CCriticalSection::CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
CCriticalSection *__thiscall CCriticalSection::CCriticalSection(CCriticalSection *this)
{
  UtlLinkedListElem_t<unsigned long,int> *m_pMemory; // eax

  this->m_Locks.m_Memory.m_pMemory = nullptr;
  this->m_Locks.m_Memory.m_nAllocationCount = 0;
  this->m_Locks.m_Memory.m_nGrowSize = 0;
  this->m_Locks.m_LastAlloc.index = -1;
  this->m_Locks.m_ElementCount = 0;
  this->m_Locks.m_NumAlloced = 0;
  m_pMemory = this->m_Locks.m_Memory.m_pMemory;
  this->m_Locks.m_Head = -1;
  this->m_Locks.m_Tail = -1;
  this->m_Locks.m_FirstFree = -1;
  this->m_Locks.m_pElements = m_pMemory;
  InitializeCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405AC0
// Name: public: CCriticalSection::~CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::~CCriticalSection(CCriticalSection *this)
{
  DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)&this->m_Locks);
  if ( this->m_Locks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Locks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Locks.m_Memory.m_pMemory);
      this->m_Locks.m_Memory.m_pMemory = nullptr;
    }
    this->m_Locks.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace vmpi_service

// ============================================================
// Overlay from vmpi_service_ui (Missing functions)
// ============================================================
namespace vmpi_service_ui {

//------------------------------------------------------------------------------
// Address: 0x00401770
// Name: protected: int CUtlLinkedList<class CServiceConn __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceConn __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::AllocInternal(
        CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CServiceConn *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00401910
// Name: public: void CUtlLinkedList<struct CThreadedTCPSocket::SendData_t __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CThreadedTCPSocket::SendData_t __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CServiceConn *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004019D0
// Name: public: void CUtlLinkedList<class CServiceConn __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CServiceConn __near *,int>,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::PurgeAndDeleteElements(
        CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *this)
{
  int m_Head; // eax
  int v3; // eax
  CServiceConn *m_Element; // edi
  int m_Next; // ebx
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // ecx

  m_Head = this->m_Head;
  if ( m_Head != -1 )
  {
    do
    {
      v3 = m_Head;
      m_Element = this->m_Memory.m_pMemory[v3].m_Element;
      m_Next = this->m_Memory.m_pMemory[v3].m_Next;
      if ( m_Element != nullptr )
      {
        if ( m_Element->m_pSocket != nullptr )
          m_Element->m_pSocket->Release(this: m_Element->m_pSocket);
        free(pMem: m_Element);
      }
      m_Head = m_Next;
    }
    while ( m_Next != -1 );
  }
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_NumAlloced = 0;
  this->m_FirstFree = -1;
  this->m_LastAlloc.index = -1;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x004028A0
// Name: protected: int CUtlLinkedList<struct CThreadedTCPSocket::SendData_t __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CThreadedTCPSocket::SendData_t __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal(
        CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00403BC0
// Name: protected: int CUtlLinkedList<class CTCPPacket __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CTCPPacket __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AllocInternal(
        CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CTCPPacket *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00403DE0
// Name: public: int CUtlLinkedList<class CTCPPacket __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CTCPPacket __near *,int>,int>>::AddToTail(class CTCPPacket __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToTail(
        CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int> > *this,
        CTCPPacket **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<CTCPPacket *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CTCPPacket *,int> *v8; // esi

  result = CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004040F0
// Name: public: CCriticalSectionLock::CCriticalSectionLock(class CCriticalSection __near *)
// Source: json
//------------------------------------------------------------------------------
CCriticalSectionLock *__thiscall CCriticalSectionLock::CCriticalSectionLock(
        CCriticalSectionLock *this,
        CCriticalSection *pCS)
{
  this->m_pCS = pCS;
  this->m_bLocked = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404110
// Name: public: CCriticalSectionLock::~CCriticalSectionLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::~CCriticalSectionLock(CCriticalSectionLock *this)
{
  if ( this->m_bLocked )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this->m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x00404120
// Name: public: void CCriticalSectionLock::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Lock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = true;
  EnterCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x00404130
// Name: public: void CCriticalSectionLock::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Unlock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = false;
  LeaveCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x00404140
// Name: public: CEvent::CEvent(void)
// Source: json
//------------------------------------------------------------------------------
CEvent *__thiscall CEvent::CEvent(CEvent *this)
{
  this->m_hEvent = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404150
// Name: public: void __near * CEvent::GetEventHandle(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CEvent::GetEventHandle(CEvent *this)
{
  return this->m_hEvent;
}

//------------------------------------------------------------------------------
// Address: 0x00404160
// Name: public: bool CEvent::SetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::SetEvent(CEvent *this)
{
  return SetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x00404170
// Name: public: bool CEvent::ResetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::ResetEvent(CEvent *this)
{
  return ResetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x00404180
// Name: public: CEvent::~CEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEvent::~CEvent(CEvent *this)
{
  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004041A0
// Name: public: bool CEvent::Init(bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEvent::Init(CEvent *this, bool bManualReset, bool bInitialState)
{
  HANDLE EventA; // eax

  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
  EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset, bInitialState, lpName: nullptr);
  this->m_hEvent = EventA;
  return EventA != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004041E0
// Name: public: void CUtlLinkedList<struct CThreadedTCPSocket::SendData_t __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CThreadedTCPSocket::SendData_t __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(
        CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CServiceConn *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404240
// Name: public: CCriticalSection::CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
CCriticalSection *__thiscall CCriticalSection::CCriticalSection(CCriticalSection *this)
{
  UtlLinkedListElem_t<unsigned long,int> *m_pMemory; // eax

  this->m_Locks.m_Memory.m_pMemory = nullptr;
  this->m_Locks.m_Memory.m_nAllocationCount = 0;
  this->m_Locks.m_Memory.m_nGrowSize = 0;
  this->m_Locks.m_LastAlloc.index = -1;
  this->m_Locks.m_ElementCount = 0;
  this->m_Locks.m_NumAlloced = 0;
  m_pMemory = this->m_Locks.m_Memory.m_pMemory;
  this->m_Locks.m_Head = -1;
  this->m_Locks.m_Tail = -1;
  this->m_Locks.m_FirstFree = -1;
  this->m_Locks.m_pElements = m_pMemory;
  InitializeCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404280
// Name: public: CCriticalSection::~CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::~CCriticalSection(CCriticalSection *this)
{
  DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)&this->m_Locks);
  if ( this->m_Locks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Locks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Locks.m_Memory.m_pMemory);
      this->m_Locks.m_Memory.m_pMemory = nullptr;
    }
    this->m_Locks.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace vmpi_service_ui

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10089C10
// Name: protected: void CCriticalSection::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::Lock(CCriticalSection *this)
{
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x10089C20
// Name: protected: void CCriticalSection::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::Unlock(CCriticalSection *this)
{
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x10089C30
// Name: public: CCriticalSectionLock::CCriticalSectionLock(class CCriticalSection __near *)
// Source: json
//------------------------------------------------------------------------------
CCriticalSectionLock *__thiscall CCriticalSectionLock::CCriticalSectionLock(
        CCriticalSectionLock *this,
        CCriticalSection *pCS)
{
  this->m_pCS = pCS;
  this->m_bLocked = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10089C50
// Name: public: CCriticalSectionLock::~CCriticalSectionLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::~CCriticalSectionLock(CCriticalSectionLock *this)
{
  if ( this->m_bLocked )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this->m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x10089C60
// Name: public: void CCriticalSectionLock::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Lock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = true;
  EnterCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x10089C70
// Name: public: void CCriticalSectionLock::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Unlock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = false;
  LeaveCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x10089C90
// Name: public: bool CEvent::SetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::SetEvent(CEvent *this)
{
  return SetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10089CA0
// Name: public: bool CEvent::ResetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::ResetEvent(CEvent *this)
{
  return ResetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10089CB0
// Name: public: CEvent::~CEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEvent::~CEvent(CEvent *this)
{
  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089CD0
// Name: public: bool CEvent::Init(bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEvent::Init(CEvent *this, bool bManualReset, bool bInitialState)
{
  HANDLE EventA; // eax

  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
  EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset, bInitialState, lpName: nullptr);
  this->m_hEvent = EventA;
  return EventA != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10089D10
// Name: public: CCriticalSection::CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
CCriticalSection *__thiscall CCriticalSection::CCriticalSection(CCriticalSection *this)
{
  UtlLinkedListElem_t<unsigned long,int> *m_pMemory; // eax

  this->m_Locks.m_Memory.m_pMemory = nullptr;
  this->m_Locks.m_Memory.m_nAllocationCount = 0;
  this->m_Locks.m_Memory.m_nGrowSize = 0;
  this->m_Locks.m_LastAlloc.index = -1;
  this->m_Locks.m_ElementCount = 0;
  this->m_Locks.m_NumAlloced = 0;
  m_pMemory = this->m_Locks.m_Memory.m_pMemory;
  this->m_Locks.m_Head = -1;
  this->m_Locks.m_Tail = -1;
  this->m_Locks.m_FirstFree = -1;
  this->m_Locks.m_pElements = m_pMemory;
  InitializeCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10089D50
// Name: public: CCriticalSection::~CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::~CCriticalSection(CCriticalSection *this)
{
  DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Locks);
  if ( this->m_Locks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Locks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Locks.m_Memory.m_pMemory);
      this->m_Locks.m_Memory.m_pMemory = nullptr;
    }
    this->m_Locks.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x100283B0
// Name: protected: void CCriticalSection::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::Lock(CCriticalSection *this)
{
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x100283C0
// Name: protected: void CCriticalSection::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::Unlock(CCriticalSection *this)
{
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
}

//------------------------------------------------------------------------------
// Address: 0x100283D0
// Name: public: CCriticalSectionLock::CCriticalSectionLock(class CCriticalSection __near *)
// Source: json
//------------------------------------------------------------------------------
CCriticalSectionLock *__thiscall CCriticalSectionLock::CCriticalSectionLock(
        CCriticalSectionLock *this,
        CCriticalSection *pCS)
{
  this->m_pCS = pCS;
  this->m_bLocked = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100283F0
// Name: public: CCriticalSectionLock::~CCriticalSectionLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::~CCriticalSectionLock(CCriticalSectionLock *this)
{
  if ( this->m_bLocked )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this->m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x10028400
// Name: public: void CCriticalSectionLock::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Lock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = true;
  EnterCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x10028410
// Name: public: void CCriticalSectionLock::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSectionLock::Unlock(CCriticalSectionLock *this)
{
  _RTL_CRITICAL_SECTION *m_pCS; // [esp-4h] [ebp-4h]

  m_pCS = (_RTL_CRITICAL_SECTION *)this->m_pCS;
  this->m_bLocked = false;
  LeaveCriticalSection(lpCriticalSection: m_pCS);
}

//------------------------------------------------------------------------------
// Address: 0x10028420
// Name: public: bool CEvent::SetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::SetEvent(CEvent *this)
{
  return SetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10028430
// Name: public: bool CEvent::ResetEvent(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEvent::ResetEvent(CEvent *this)
{
  return ResetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10028440
// Name: public: CEvent::~CEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEvent::~CEvent(CEvent *this)
{
  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028460
// Name: public: bool CEvent::Init(bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEvent::Init(CEvent *this, bool bManualReset, bool bInitialState)
{
  HANDLE EventA; // eax

  if ( this->m_hEvent != nullptr )
  {
    CloseHandle(hObject: this->m_hEvent);
    this->m_hEvent = nullptr;
  }
  EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset, bInitialState, lpName: nullptr);
  this->m_hEvent = EventA;
  return EventA != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100284A0
// Name: public: CCriticalSection::CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
CCriticalSection *__thiscall CCriticalSection::CCriticalSection(CCriticalSection *this)
{
  UtlLinkedListElem_t<unsigned long,int> *m_pMemory; // eax

  this->m_Locks.m_Memory.m_pMemory = nullptr;
  this->m_Locks.m_Memory.m_nAllocationCount = 0;
  this->m_Locks.m_Memory.m_nGrowSize = 0;
  this->m_Locks.m_LastAlloc.index = -1;
  this->m_Locks.m_ElementCount = 0;
  this->m_Locks.m_NumAlloced = 0;
  m_pMemory = this->m_Locks.m_Memory.m_pMemory;
  this->m_Locks.m_Head = -1;
  this->m_Locks.m_Tail = -1;
  this->m_Locks.m_FirstFree = -1;
  this->m_Locks.m_pElements = m_pMemory;
  InitializeCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100284E0
// Name: public: CCriticalSection::~CCriticalSection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCriticalSection::~CCriticalSection(CCriticalSection *this)
{
  DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Locks);
  if ( this->m_Locks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Locks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Locks.m_Memory.m_pMemory);
      this->m_Locks.m_Memory.m_pMemory = nullptr;
    }
    this->m_Locks.m_Memory.m_nAllocationCount = 0;
  }
}

} // namespace vvis_dll
