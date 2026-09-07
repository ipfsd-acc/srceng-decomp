// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/mysqldatabase.cpp
// Functions: 8
// ============================================================

#include "utils\common\mysqldatabase.h"

//------------------------------------------------------------------------------
// Address: 0x10014AF0
// Name: public: virtual int CMySqlDatabase::QueriesInOutQueue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMySqlDatabase::QueriesInOutQueue(CMySqlDatabase *this)
{
  return this->m_InQueue.m_ElementCount;
}

//------------------------------------------------------------------------------
// Address: 0x10014B00
// Name: public: virtual int CMySqlDatabase::QueriesInFinishedQueue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMySqlDatabase::QueriesInFinishedQueue(CMySqlDatabase *this)
{
  return this->m_OutQueue.m_ElementCount;
}

//------------------------------------------------------------------------------
// Address: 0x10014D20
// Name: public: CMySqlDatabase::CMySqlDatabase(void)
// Source: json
//------------------------------------------------------------------------------
CMySqlDatabase *__thiscall CMySqlDatabase::CMySqlDatabase(CMySqlDatabase *this)
{
  CMySqlDatabase *result; // eax
  UtlLinkedListElem_t<CMySqlDatabase::msg_t,int> *m_pMemory; // ecx

  result = this;
  this->__vftable = (CMySqlDatabase_vtbl *)&CMySqlDatabase::`vftable';
  this->m_InQueue.m_Memory.m_pMemory = nullptr;
  this->m_InQueue.m_Memory.m_nAllocationCount = 0;
  this->m_InQueue.m_Memory.m_nGrowSize = 0;
  this->m_InQueue.m_LastAlloc.index = -1;
  this->m_InQueue.m_Head = -1;
  this->m_InQueue.m_Tail = -1;
  this->m_InQueue.m_FirstFree = -1;
  this->m_InQueue.m_ElementCount = 0;
  this->m_InQueue.m_NumAlloced = 0;
  this->m_InQueue.m_pElements = this->m_InQueue.m_Memory.m_pMemory;
  this->m_OutQueue.m_Memory.m_pMemory = nullptr;
  this->m_OutQueue.m_Memory.m_nAllocationCount = 0;
  this->m_OutQueue.m_Memory.m_nGrowSize = 0;
  this->m_OutQueue.m_LastAlloc.index = -1;
  this->m_OutQueue.m_ElementCount = 0;
  this->m_OutQueue.m_NumAlloced = 0;
  m_pMemory = this->m_OutQueue.m_Memory.m_pMemory;
  result->m_OutQueue.m_Head = -1;
  result->m_OutQueue.m_Tail = -1;
  result->m_OutQueue.m_FirstFree = -1;
  result->m_OutQueue.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014DB0
// Name: public: CMySqlDatabase::~CMySqlDatabase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMySqlDatabase::~CMySqlDatabase(CMySqlDatabase *this)
{
  void *m_hEvent; // [esp-4h] [ebp-Ch]

  m_hEvent = this->m_hEvent;
  this->__vftable = (CMySqlDatabase_vtbl *)&CMySqlDatabase::`vftable';
  this->m_bRunThread = false;
  SetEvent(hEvent: m_hEvent);
  EnterCriticalSection(lpCriticalSection: &this->m_csThread);
  LeaveCriticalSection(lpCriticalSection: &this->m_csThread);
  CUtlLinkedList<CMySqlDatabase::msg_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMySqlDatabase::msg_t,int>,int>>::RemoveAll(this: &this->m_OutQueue);
  if ( this->m_OutQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OutQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OutQueue.m_Memory.m_pMemory);
      this->m_OutQueue.m_Memory.m_pMemory = nullptr;
    }
    this->m_OutQueue.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CMySqlDatabase::msg_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMySqlDatabase::msg_t,int>,int>>::RemoveAll(this: &this->m_InQueue);
  if ( this->m_InQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_InQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_InQueue.m_Memory.m_pMemory);
      this->m_InQueue.m_Memory.m_pMemory = nullptr;
    }
    this->m_InQueue.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014EE0
// Name: public: void CMySqlDatabase::RunThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMySqlDatabase::RunThread(CMySqlDatabase *this)
{
  _RTL_CRITICAL_SECTION *p_m_csThread; // edi
  int m_Head; // ecx
  UtlLinkedListElem_t<CMySqlDatabase::msg_t,int> *m_pMemory; // edx
  unsigned int v5; // eax
  UtlLinkedListElem_t<CMySqlDatabase::msg_t,int> *v6; // edi
  bool v7; // zf
  int m_Previous; // edx
  int m_Next; // edx
  ISQLDBCommand *cmd; // ebx
  ISQLDBReplyTarget *replyTarget; // edi
  CMySqlDatabase::msg_t msg; // [esp+8h] [ebp-18h] BYREF
  _RTL_CRITICAL_SECTION *v13; // [esp+18h] [ebp-8h]
  UtlLinkedListElem_t<CMySqlDatabase::msg_t,int> *v14; // [esp+1Ch] [ebp-4h]

  p_m_csThread = &this->m_csThread;
  v13 = &this->m_csThread;
  EnterCriticalSection(lpCriticalSection: &this->m_csThread);
  if ( this->m_bRunThread )
  {
    do
    {
      if ( this->m_InQueue.m_ElementCount <= 0 )
      {
        WaitForSingleObject(hHandle: this->m_hEvent, dwMilliseconds: 0xFFFFFFFF);
      }
      else
      {
        EnterCriticalSection(lpCriticalSection: &this->m_csInQueue);
        m_Head = this->m_InQueue.m_Head;
        m_pMemory = this->m_InQueue.m_Memory.m_pMemory;
        v5 = m_Head;
        msg = m_pMemory[m_Head].m_Element;
        if ( m_Head >= 0
          && m_Head < this->m_InQueue.m_Memory.m_nAllocationCount
          && m_Head <= this->m_InQueue.m_LastAlloc.index )
        {
          v6 = m_pMemory;
          v7 = m_pMemory[v5].m_Previous == m_Head;
          v14 = m_pMemory;
          if ( !v7 )
          {
            m_Previous = m_pMemory[v5].m_Previous;
            if ( m_Previous == -1 )
              this->m_InQueue.m_Head = v6[v5].m_Next;
            else
              v6[m_Previous].m_Next = v6[v5].m_Next;
            m_Next = v6[v5].m_Next;
            if ( m_Next == -1 )
            {
              this->m_InQueue.m_Tail = v6[v5].m_Previous;
            }
            else
            {
              this->m_InQueue.m_Memory.m_pMemory[m_Next].m_Previous = v6[v5].m_Previous;
              v6 = v14;
            }
            v6[v5].m_Next = m_Head;
            v6[v5].m_Previous = m_Head;
            --this->m_InQueue.m_ElementCount;
          }
        }
        this->m_InQueue.m_Memory.m_pMemory[v5].m_Next = this->m_InQueue.m_FirstFree;
        this->m_InQueue.m_FirstFree = m_Head;
        LeaveCriticalSection(lpCriticalSection: &this->m_csInQueue);
        EnterCriticalSection(lpCriticalSection: &this->m_csDBAccess);
        cmd = msg.cmd;
        msg.result = msg.cmd->RunCommand(this: msg.cmd);
        LeaveCriticalSection(lpCriticalSection: &this->m_csDBAccess);
        replyTarget = msg.replyTarget;
        if ( msg.replyTarget != nullptr )
        {
          EnterCriticalSection(lpCriticalSection: &this->m_csOutQueue);
          CUtlLinkedList<CMySqlDatabase::msg_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMySqlDatabase::msg_t,int>,int>>::AddToTail(
            this: &this->m_OutQueue,
            src: &msg);
          LeaveCriticalSection(lpCriticalSection: &this->m_csOutQueue);
          replyTarget->WakeUp(this: replyTarget);
        }
        else
        {
          cmd->deleteThis(this: cmd);
        }
      }
      if ( this->m_OutQueue.m_ElementCount > 50 )
        Sleep(dwMilliseconds: 2u);
    }
    while ( this->m_bRunThread );
    p_m_csThread = v13;
  }
  LeaveCriticalSection(lpCriticalSection: p_m_csThread);
}

//------------------------------------------------------------------------------
// Address: 0x10015060
// Name: public: void CMySqlDatabase::AddCommandToQueue(class ISQLDBCommand __near *,class ISQLDBReplyTarget __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMySqlDatabase::AddCommandToQueue(
        CMySqlDatabase *this,
        ISQLDBCommand *cmd,
        ISQLDBReplyTarget *replyTarget,
        int returnState)
{
  _RTL_CRITICAL_SECTION *p_m_csInQueue; // edi
  CMySqlDatabase::msg_t msg; // [esp+8h] [ebp-10h] BYREF

  p_m_csInQueue = &this->m_csInQueue;
  EnterCriticalSection(lpCriticalSection: &this->m_csInQueue);
  msg.cmd = cmd;
  msg.replyTarget = replyTarget;
  msg.result = 0;
  msg.returnState = returnState;
  CUtlLinkedList<CMySqlDatabase::msg_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMySqlDatabase::msg_t,int>,int>>::AddToTail(
    this: &this->m_InQueue,
    src: &msg);
  LeaveCriticalSection(lpCriticalSection: p_m_csInQueue);
  SetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x100150C0
// Name: staticThreadFunc
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall staticThreadFunc(CMySqlDatabase *param)
{
  CMySqlDatabase::RunThread(this: param);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100150E0
// Name: public: bool CMySqlDatabase::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMySqlDatabase::Initialize(CMySqlDatabase *this)
{
  unsigned int threadID; // [esp+8h] [ebp-4h] BYREF

  InitializeCriticalSection(lpCriticalSection: &this->m_csThread);
  InitializeCriticalSection(lpCriticalSection: &this->m_csInQueue);
  InitializeCriticalSection(lpCriticalSection: &this->m_csOutQueue);
  InitializeCriticalSection(lpCriticalSection: &this->m_csDBAccess);
  this->m_hEvent = CreateEventA(lpEventAttributes: nullptr, bManualReset: false, bInitialState: true, lpName: nullptr);
  this->m_bRunThread = true;
  CreateThread(
    lpThreadAttributes: nullptr,
    dwStackSize: 0,
    lpStartAddress: (LPTHREAD_START_ROUTINE)staticThreadFunc,
    lpParameter: this,
    dwCreationFlags: 0,
    lpThreadId: &threadID);
  return 1;
}

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1000F4C0
// Name: public: virtual int CMySqlDatabase::QueriesInOutQueue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMySqlDatabase::QueriesInOutQueue(CMySqlDatabase *this)
{
  return this->m_InQueue.m_ElementCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000F4D0
// Name: public: virtual int CMySqlDatabase::QueriesInFinishedQueue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMySqlDatabase::QueriesInFinishedQueue(CMySqlDatabase *this)
{
  return this->m_OutQueue.m_ElementCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000F6F0
// Name: public: CMySqlDatabase::CMySqlDatabase(void)
// Source: json
//------------------------------------------------------------------------------
CMySqlDatabase *__thiscall CMySqlDatabase::CMySqlDatabase(CMySqlDatabase *this)
{
  CMySqlDatabase *result; // eax
  UtlLinkedListElem_t<CMySqlDatabase::msg_t,int> *m_pMemory; // ecx

  result = this;
  this->__vftable = (CMySqlDatabase_vtbl *)&CMySqlDatabase::`vftable';
  this->m_InQueue.m_Memory.m_pMemory = nullptr;
  this->m_InQueue.m_Memory.m_nAllocationCount = 0;
  this->m_InQueue.m_Memory.m_nGrowSize = 0;
  this->m_InQueue.m_LastAlloc.index = -1;
  this->m_InQueue.m_Head = -1;
  this->m_InQueue.m_Tail = -1;
  this->m_InQueue.m_FirstFree = -1;
  this->m_InQueue.m_ElementCount = 0;
  this->m_InQueue.m_NumAlloced = 0;
  this->m_InQueue.m_pElements = this->m_InQueue.m_Memory.m_pMemory;
  this->m_OutQueue.m_Memory.m_pMemory = nullptr;
  this->m_OutQueue.m_Memory.m_nAllocationCount = 0;
  this->m_OutQueue.m_Memory.m_nGrowSize = 0;
  this->m_OutQueue.m_LastAlloc.index = -1;
  this->m_OutQueue.m_ElementCount = 0;
  this->m_OutQueue.m_NumAlloced = 0;
  m_pMemory = this->m_OutQueue.m_Memory.m_pMemory;
  result->m_OutQueue.m_Head = -1;
  result->m_OutQueue.m_Tail = -1;
  result->m_OutQueue.m_FirstFree = -1;
  result->m_OutQueue.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F780
// Name: public: CMySqlDatabase::~CMySqlDatabase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMySqlDatabase::~CMySqlDatabase(CMySqlDatabase *this)
{
  void *m_hEvent; // [esp-4h] [ebp-Ch]

  m_hEvent = this->m_hEvent;
  this->__vftable = (CMySqlDatabase_vtbl *)&CMySqlDatabase::`vftable';
  this->m_bRunThread = false;
  SetEvent(hEvent: m_hEvent);
  EnterCriticalSection(lpCriticalSection: &this->m_csThread);
  LeaveCriticalSection(lpCriticalSection: &this->m_csThread);
  CUtlLinkedList<CMySqlDatabase::msg_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMySqlDatabase::msg_t,int>,int>>::RemoveAll(this: &this->m_OutQueue);
  if ( this->m_OutQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OutQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OutQueue.m_Memory.m_pMemory);
      this->m_OutQueue.m_Memory.m_pMemory = nullptr;
    }
    this->m_OutQueue.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CMySqlDatabase::msg_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMySqlDatabase::msg_t,int>,int>>::RemoveAll(this: &this->m_InQueue);
  if ( this->m_InQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_InQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_InQueue.m_Memory.m_pMemory);
      this->m_InQueue.m_Memory.m_pMemory = nullptr;
    }
    this->m_InQueue.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F8B0
// Name: public: void CMySqlDatabase::RunThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMySqlDatabase::RunThread(CMySqlDatabase *this)
{
  _RTL_CRITICAL_SECTION *p_m_csThread; // edi
  int m_Head; // ecx
  UtlLinkedListElem_t<CMySqlDatabase::msg_t,int> *m_pMemory; // edx
  unsigned int v5; // eax
  UtlLinkedListElem_t<CMySqlDatabase::msg_t,int> *v6; // edi
  bool v7; // zf
  int m_Previous; // edx
  int m_Next; // edx
  ISQLDBCommand *cmd; // ebx
  ISQLDBReplyTarget *replyTarget; // edi
  CMySqlDatabase::msg_t msg; // [esp+8h] [ebp-18h] BYREF
  _RTL_CRITICAL_SECTION *v13; // [esp+18h] [ebp-8h]
  UtlLinkedListElem_t<CMySqlDatabase::msg_t,int> *v14; // [esp+1Ch] [ebp-4h]

  p_m_csThread = &this->m_csThread;
  v13 = &this->m_csThread;
  EnterCriticalSection(lpCriticalSection: &this->m_csThread);
  if ( this->m_bRunThread )
  {
    do
    {
      if ( this->m_InQueue.m_ElementCount <= 0 )
      {
        WaitForSingleObject(hHandle: this->m_hEvent, dwMilliseconds: 0xFFFFFFFF);
      }
      else
      {
        EnterCriticalSection(lpCriticalSection: &this->m_csInQueue);
        m_Head = this->m_InQueue.m_Head;
        m_pMemory = this->m_InQueue.m_Memory.m_pMemory;
        v5 = m_Head;
        msg = m_pMemory[m_Head].m_Element;
        if ( m_Head >= 0
          && m_Head < this->m_InQueue.m_Memory.m_nAllocationCount
          && m_Head <= this->m_InQueue.m_LastAlloc.index )
        {
          v6 = m_pMemory;
          v7 = m_pMemory[v5].m_Previous == m_Head;
          v14 = m_pMemory;
          if ( !v7 )
          {
            m_Previous = m_pMemory[v5].m_Previous;
            if ( m_Previous == -1 )
              this->m_InQueue.m_Head = v6[v5].m_Next;
            else
              v6[m_Previous].m_Next = v6[v5].m_Next;
            m_Next = v6[v5].m_Next;
            if ( m_Next == -1 )
            {
              this->m_InQueue.m_Tail = v6[v5].m_Previous;
            }
            else
            {
              this->m_InQueue.m_Memory.m_pMemory[m_Next].m_Previous = v6[v5].m_Previous;
              v6 = v14;
            }
            v6[v5].m_Next = m_Head;
            v6[v5].m_Previous = m_Head;
            --this->m_InQueue.m_ElementCount;
          }
        }
        this->m_InQueue.m_Memory.m_pMemory[v5].m_Next = this->m_InQueue.m_FirstFree;
        this->m_InQueue.m_FirstFree = m_Head;
        LeaveCriticalSection(lpCriticalSection: &this->m_csInQueue);
        EnterCriticalSection(lpCriticalSection: &this->m_csDBAccess);
        cmd = msg.cmd;
        msg.result = msg.cmd->RunCommand(this: msg.cmd);
        LeaveCriticalSection(lpCriticalSection: &this->m_csDBAccess);
        replyTarget = msg.replyTarget;
        if ( msg.replyTarget != nullptr )
        {
          EnterCriticalSection(lpCriticalSection: &this->m_csOutQueue);
          CUtlLinkedList<CMySqlDatabase::msg_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMySqlDatabase::msg_t,int>,int>>::AddToTail(
            this: &this->m_OutQueue,
            src: &msg);
          LeaveCriticalSection(lpCriticalSection: &this->m_csOutQueue);
          replyTarget->WakeUp(this: replyTarget);
        }
        else
        {
          cmd->deleteThis(this: cmd);
        }
      }
      if ( this->m_OutQueue.m_ElementCount > 50 )
        Sleep(dwMilliseconds: 2u);
    }
    while ( this->m_bRunThread );
    p_m_csThread = v13;
  }
  LeaveCriticalSection(lpCriticalSection: p_m_csThread);
}

//------------------------------------------------------------------------------
// Address: 0x1000FA30
// Name: public: void CMySqlDatabase::AddCommandToQueue(class ISQLDBCommand __near *,class ISQLDBReplyTarget __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMySqlDatabase::AddCommandToQueue(
        CMySqlDatabase *this,
        ISQLDBCommand *cmd,
        ISQLDBReplyTarget *replyTarget,
        int returnState)
{
  _RTL_CRITICAL_SECTION *p_m_csInQueue; // edi
  CMySqlDatabase::msg_t msg; // [esp+8h] [ebp-10h] BYREF

  p_m_csInQueue = &this->m_csInQueue;
  EnterCriticalSection(lpCriticalSection: &this->m_csInQueue);
  msg.cmd = cmd;
  msg.replyTarget = replyTarget;
  msg.result = 0;
  msg.returnState = returnState;
  CUtlLinkedList<CMySqlDatabase::msg_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CMySqlDatabase::msg_t,int>,int>>::AddToTail(
    this: &this->m_InQueue,
    src: &msg);
  LeaveCriticalSection(lpCriticalSection: p_m_csInQueue);
  SetEvent(hEvent: this->m_hEvent);
}

//------------------------------------------------------------------------------
// Address: 0x1000FA90
// Name: staticThreadFunc
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall staticThreadFunc(CMySqlDatabase *param)
{
  CMySqlDatabase::RunThread(this: param);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000FAB0
// Name: public: bool CMySqlDatabase::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMySqlDatabase::Initialize(CMySqlDatabase *this)
{
  unsigned int threadID; // [esp+8h] [ebp-4h] BYREF

  InitializeCriticalSection(lpCriticalSection: &this->m_csThread);
  InitializeCriticalSection(lpCriticalSection: &this->m_csInQueue);
  InitializeCriticalSection(lpCriticalSection: &this->m_csOutQueue);
  InitializeCriticalSection(lpCriticalSection: &this->m_csDBAccess);
  this->m_hEvent = CreateEventA(lpEventAttributes: nullptr, bManualReset: false, bInitialState: true, lpName: nullptr);
  this->m_bRunThread = true;
  CreateThread(
    lpThreadAttributes: nullptr,
    dwStackSize: 0,
    lpStartAddress: (LPTHREAD_START_ROUTINE)staticThreadFunc,
    lpParameter: this,
    dwCreationFlags: 0,
    lpThreadId: &threadID);
  return 1;
}

} // namespace vvis_dll
