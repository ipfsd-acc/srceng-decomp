// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/remoteserver.cpp
// Functions: 35
// ============================================================

#include "tracker\adminserver\remoteserver.h"

//------------------------------------------------------------------------------
// Address: 0x100032C0
// Name: public: void CRemoteServer::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRemoteServer::Initialize(CRemoteServer *this)
{
  unsigned int v2; // eax

  this->m_bInitialized = true;
  v2 = g_pGameServerData->GetNextListenerID(this: g_pGameServerData, a2: false, a3: nullptr);
  this->m_ListenerID = v2;
  g_pGameServerData->RegisterAdminUIID(this: g_pGameServerData, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100032F0
// Name: public: void CByteswap::SwapBufferToTargetEndian<int>(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003380
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CRemoteServer::MessageHandler_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int> *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                      this: _g_pMemAlloc,
                                                                                      a2: m_pMemory,
                                                                                      a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                      this: _g_pMemAlloc,
                                                                                      a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003410
// Name: public: void CUtlLinkedList<struct CRemoteServer::MessageHandler_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CRemoteServer::MessageHandler_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
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
// Address: 0x10003470
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100034E0
// Name: protected: int CUtlLinkedList<struct CRemoteServer::ResponseHandler_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CRemoteServer::ResponseHandler_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CRemoteServer::ResponseHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::ResponseHandler_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CRemoteServer::ResponseHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::ResponseHandler_t,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CRemoteServer::ResponseHandler_t,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
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
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<CRemoteServer::ResponseHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::ResponseHandler_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CRemoteServer::ResponseHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::ResponseHandler_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x10003610
// Name: protected: int CUtlLinkedList<struct CRemoteServer::MessageHandler_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CRemoteServer::MessageHandler_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int> *m_pMemory; // ecx
  int v10; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result;
    if ( multilist )
    {
      m_pMemory[v10].m_Next = -1;
      m_pMemory[v10].m_Previous = -1;
    }
    else
    {
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
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
    CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x10003740
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
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
// Address: 0x100037C0
// Name: public: void CUtlLinkedList<struct CRemoteServer::MessageHandler_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CRemoteServer::MessageHandler_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int>>::Unlink(
        CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
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
// Address: 0x10003840
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 0xAu);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100038E0
// Name: public: CRemoteServer::~CRemoteServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRemoteServer::~CRemoteServer(CRemoteServer *this)
{
  CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int>>::RemoveAll(this: &this->m_MessageHandlers);
  if ( this->m_MessageHandlers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MessageHandlers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MessageHandlers.m_Memory.m_pMemory);
      this->m_MessageHandlers.m_Memory.m_pMemory = nullptr;
    }
    this->m_MessageHandlers.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_ResponseHandlers);
  if ( this->m_ResponseHandlers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ResponseHandlers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ResponseHandlers.m_Memory.m_pMemory);
      this->m_ResponseHandlers.m_Memory.m_pMemory = nullptr;
    }
    this->m_ResponseHandlers.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003950
// Name: public: void CRemoteServer::SetValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRemoteServer::SetValue(CRemoteServer *this, const char *variable, const char *value)
{
  bool v4; // zf
  int v5; // eax
  char buf[512]; // [esp+4h] [ebp-230h] BYREF
  CUtlBuffer cmd; // [esp+204h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &cmd, pBuffer: buf, nSize: 512, nFlags: 0);
  v4 = (cmd.m_Flags & 1) == 0;
  v5 = this->m_iCurrentRequestID++;
  if ( v4 )
    CUtlBuffer::PutTypeBin<int>(this: &cmd, src: v5);
  else
    CUtlBuffer::Printf(this: &cmd, pFmt: "%d", v5);
  if ( (cmd.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &cmd, pFmt: "%d", 1);
  else
    CUtlBuffer::PutTypeBin<int>(this: &cmd, src: 1);
  CUtlBuffer::PutString(this: &cmd, pString: variable);
  CUtlBuffer::PutString(this: &cmd, pString: value);
  g_pGameServerData->WriteDataRequest(
    this: g_pGameServerData,
    a2: this->m_ListenerID,
    a3: cmd.m_Memory.m_pMemory,
    a4: cmd.m_Put);
  if ( cmd.m_Memory.m_nGrowSize >= 0 && cmd.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10003A20
// Name: public: void CRemoteServer::SendCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRemoteServer::SendCommand(CRemoteServer *this, const char *commandString)
{
  bool v3; // zf
  int v4; // eax
  char buf[512]; // [esp+4h] [ebp-230h] BYREF
  CUtlBuffer cmd; // [esp+204h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &cmd, pBuffer: buf, nSize: 512, nFlags: 0);
  v3 = (cmd.m_Flags & 1) == 0;
  v4 = this->m_iCurrentRequestID++;
  if ( v3 )
    CUtlBuffer::PutTypeBin<int>(this: &cmd, src: v4);
  else
    CUtlBuffer::Printf(this: &cmd, pFmt: "%d", v4);
  if ( (cmd.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &cmd, pFmt: "%d", 2);
  else
    CUtlBuffer::PutTypeBin<int>(this: &cmd, src: 2);
  CUtlBuffer::PutString(this: &cmd, pString: commandString);
  CUtlBuffer::PutString(this: &cmd, pString: defaultValue);
  g_pGameServerData->WriteDataRequest(
    this: g_pGameServerData,
    a2: this->m_ListenerID,
    a3: cmd.m_Memory.m_pMemory,
    a4: cmd.m_Put);
  if ( cmd.m_Memory.m_nGrowSize >= 0 && cmd.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10003AF0
// Name: class CRemoteServer __near & RemoteServer(void)
// Source: json
//------------------------------------------------------------------------------
CRemoteServer *__cdecl RemoteServer()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    s_RemoteServer.m_ResponseHandlers.m_Memory.m_pMemory = nullptr;
    s_RemoteServer.m_ResponseHandlers.m_Memory.m_nAllocationCount = 0;
    s_RemoteServer.m_ResponseHandlers.m_Memory.m_nGrowSize = 0;
    s_RemoteServer.m_ResponseHandlers.m_LastAlloc.index = -1;
    s_RemoteServer.m_ResponseHandlers.m_Head = -1;
    s_RemoteServer.m_ResponseHandlers.m_Tail = -1;
    s_RemoteServer.m_ResponseHandlers.m_FirstFree = -1;
    s_RemoteServer.m_ResponseHandlers.m_ElementCount = 0;
    s_RemoteServer.m_ResponseHandlers.m_NumAlloced = 0;
    s_RemoteServer.m_ResponseHandlers.m_pElements = nullptr;
    s_RemoteServer.m_MessageHandlers.m_Memory.m_pMemory = nullptr;
    s_RemoteServer.m_MessageHandlers.m_Memory.m_nAllocationCount = 0;
    s_RemoteServer.m_MessageHandlers.m_Memory.m_nGrowSize = 0;
    s_RemoteServer.m_MessageHandlers.m_LastAlloc.index = -1;
    s_RemoteServer.m_MessageHandlers.m_Head = -1;
    s_RemoteServer.m_MessageHandlers.m_Tail = -1;
    s_RemoteServer.m_MessageHandlers.m_FirstFree = -1;
    s_RemoteServer.m_MessageHandlers.m_ElementCount = 0;
    s_RemoteServer.m_MessageHandlers.m_NumAlloced = 0;
    s_RemoteServer.m_MessageHandlers.m_pElements = nullptr;
    s_RemoteServer.m_iCurrentRequestID = 0;
    s_RemoteServer.m_ListenerID = -1;
    s_RemoteServer.m_bInitialized = false;
    atexit(func: RemoteServer_::_2_::_dynamic_atexit_destructor_for__s_RemoteServer__);
  }
  return &s_RemoteServer;
}

//------------------------------------------------------------------------------
// Address: 0x10003BA0
// Name: public: bool CRemoteServer::ProcessServerResponse(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRemoteServer::ProcessServerResponse(CRemoteServer *this)
{
  CRemoteServer *v1; // ebx
  int (__thiscall *ReadDataResponse)(IGameServerData *, unsigned int, void *, int); // eax
  int v3; // eax
  unsigned int v4; // esi
  int i; // eax
  int v6; // esi
  int v7; // ecx
  IServerDataResponse *handler; // ecx
  signed int v9; // esi
  int m_Head; // esi
  CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *p_m_ResponseHandlers; // edi
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v12; // eax
  vgui::Panel *labelPanel; // ecx
  unsigned int m_ListenerID; // [esp-Ch] [ebp-10B8h]
  char pBuffer[4096]; // [esp+4h] [ebp-10A8h] BYREF
  char pString[64]; // [esp+1004h] [ebp-A8h] BYREF
  CUtlBuffer v18; // [esp+1044h] [ebp-68h] BYREF
  CUtlBuffer v19; // [esp+1074h] [ebp-38h] BYREF
  CRemoteServer *v20; // [esp+10A4h] [ebp-8h]
  unsigned int Int; // [esp+10A8h] [ebp-4h]

  v1 = this;
  ReadDataResponse = g_pGameServerData->ReadDataResponse;
  m_ListenerID = this->m_ListenerID;
  v20 = this;
  v3 = ReadDataResponse(this: g_pGameServerData, a2: m_ListenerID, a3: pBuffer, a4: 4096);
  if ( v3 < 1 )
    return 0;
  do
  {
    CUtlBuffer::CUtlBuffer(this: &v19, pBuffer, nSize: v3, nFlags: 8);
    Int = CUtlBuffer::GetInt(this: &v19);
    v4 = CUtlBuffer::GetInt(this: &v19);
    CUtlBuffer::GetString(this: &v19, pString, nMaxChars: 0);
    if ( v4 != 0 )
    {
      if ( v4 == 1 )
      {
        for ( i = v1->m_MessageHandlers.m_Head; i >= 0; i = v1->m_MessageHandlers.m_Memory.m_pMemory[v6].m_Next )
        {
          if ( i >= v1->m_MessageHandlers.m_Memory.m_nAllocationCount )
            break;
          if ( i > v1->m_MessageHandlers.m_LastAlloc.index )
            break;
          v6 = i;
          v7 = (int)&v1->m_MessageHandlers.m_Memory.m_pMemory[i];
          if ( *(_DWORD *)(v7 + 36) == i && *(_DWORD *)(v7 + 40) != i )
            break;
          if ( _V_stricmp(s1: (const char *)v7, s2: pString) == 0 )
          {
            handler = v1->m_MessageHandlers.m_Memory.m_pMemory[v6].m_Element.handler;
            handler->OnServerDataResponse(this: handler, a2: pString, a3: defaultValue);
          }
        }
      }
    }
    else
    {
      v9 = CUtlBuffer::GetInt(this: &v19);
      CUtlBuffer::CUtlBuffer(this: &v18, growSize: 0, initSize: v9, nFlags: 0);
      if ( v9 <= 0 )
        CUtlBuffer::PutChar(this: &v18, c: 0);
      else
        CUtlBuffer::Put(this: &v18, pMem: &v19.m_Memory.m_pMemory[v19.m_Get - v19.m_nOffset], size: v9);
      m_Head = v1->m_ResponseHandlers.m_Head;
      p_m_ResponseHandlers = (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&v1->m_ResponseHandlers;
      while ( m_Head >= 0 )
      {
        if ( m_Head >= v1->m_ResponseHandlers.m_Memory.m_nAllocationCount )
          break;
        if ( m_Head > v1->m_ResponseHandlers.m_LastAlloc.index )
          break;
        v12 = &p_m_ResponseHandlers->m_Memory.m_pMemory[m_Head];
        if ( v12->m_Previous == m_Head && v12->m_Next != m_Head )
          break;
        if ( v12->m_Element.panel == (vgui::Panel *)Int )
        {
          labelPanel = p_m_ResponseHandlers->m_Memory.m_pMemory[m_Head].m_Element.labelPanel;
          ((void (__thiscall *)(vgui::Panel *, char *, unsigned __int8 *))labelPanel->GetVPanel)(
            a1: labelPanel,
            a2: pString,
            a3: v18.m_Memory.m_pMemory);
          CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
            this: p_m_ResponseHandlers,
            elem: m_Head);
          v1->m_ResponseHandlers.m_Memory.m_pMemory[m_Head].m_Next = v1->m_ResponseHandlers.m_FirstFree;
          v1 = v20;
          p_m_ResponseHandlers->m_FirstFree = m_Head;
          break;
        }
        m_Head = v12->m_Next;
      }
      if ( v18.m_Memory.m_nGrowSize >= 0 && v18.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18.m_Memory.m_pMemory);
    }
    if ( v19.m_Memory.m_nGrowSize >= 0 && v19.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Memory.m_pMemory);
    v3 = g_pGameServerData->ReadDataResponse(this: g_pGameServerData, a2: v1->m_ListenerID, a3: pBuffer, a4: 4096);
  }
  while ( v3 >= 1 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003DB0
// Name: public: void CRemoteServer::RemoveServerDataResponseTarget(class IServerDataResponse __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRemoteServer::RemoveServerDataResponseTarget(
        CRemoteServer *this,
        IServerDataResponse *invalidRequester)
{
  int v3; // edi
  int v4; // eax
  UtlLinkedListElem_t<CRemoteServer::ResponseHandler_t,int> *m_pMemory; // ecx
  int v6; // edi
  int v7; // ecx
  UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int> *v8; // eax
  int m_Previous; // edx
  int m_Next; // edx
  int i; // [esp+Ch] [ebp-4h]
  int ia; // [esp+Ch] [ebp-4h]

  v3 = 0;
  if ( this->m_ResponseHandlers.m_Memory.m_nAllocationCount > 0 )
  {
    v4 = 0;
    i = 0;
    do
    {
      if ( v3 >= 0
        && v3 < this->m_ResponseHandlers.m_Memory.m_nAllocationCount
        && v3 <= this->m_ResponseHandlers.m_LastAlloc.index )
      {
        m_pMemory = this->m_ResponseHandlers.m_Memory.m_pMemory;
        if ( (*(int *)((char *)&m_pMemory->m_Previous + v4) != v3 || *(int *)((char *)&m_pMemory->m_Next + v4) == v3)
          && *(IServerDataResponse **)((char *)&m_pMemory->m_Element.handler + v4) == invalidRequester )
        {
          CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
            this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_ResponseHandlers,
            elem: v3);
          this->m_ResponseHandlers.m_Memory.m_pMemory[i].m_Next = this->m_ResponseHandlers.m_FirstFree;
          this->m_ResponseHandlers.m_FirstFree = v3;
        }
      }
      ++v3;
      v4 = i * 16 + 16;
      ++i;
    }
    while ( v3 < this->m_ResponseHandlers.m_Memory.m_nAllocationCount );
  }
  v6 = 0;
  ia = 0;
  if ( this->m_MessageHandlers.m_Memory.m_nAllocationCount > 0 )
  {
    v7 = 0;
    do
    {
      if ( v6 >= 0
        && v6 < this->m_MessageHandlers.m_Memory.m_nAllocationCount
        && v6 <= this->m_MessageHandlers.m_LastAlloc.index )
      {
        v8 = this->m_MessageHandlers.m_Memory.m_pMemory;
        if ( (v8[v7].m_Previous != v6 || v8[v7].m_Next == v6) && v8[v7].m_Element.handler == invalidRequester )
        {
          if ( v6 < this->m_MessageHandlers.m_Memory.m_nAllocationCount
            && v6 <= this->m_MessageHandlers.m_LastAlloc.index
            && v8[v7].m_Previous != v6 )
          {
            m_Previous = v8[v7].m_Previous;
            if ( m_Previous == -1 )
              this->m_MessageHandlers.m_Head = v8[v7].m_Next;
            else
              v8[m_Previous].m_Next = v8[v7].m_Next;
            m_Next = v8[v7].m_Next;
            if ( m_Next == -1 )
            {
              this->m_MessageHandlers.m_Tail = v8[v7].m_Previous;
            }
            else
            {
              this->m_MessageHandlers.m_Memory.m_pMemory[m_Next].m_Previous = v8[v7].m_Previous;
              v6 = ia;
            }
            v8[v7].m_Next = v6;
            v8[v7].m_Previous = v6;
            --this->m_MessageHandlers.m_ElementCount;
          }
          this->m_MessageHandlers.m_Memory.m_pMemory[v7].m_Next = this->m_MessageHandlers.m_FirstFree;
          this->m_MessageHandlers.m_FirstFree = v6;
        }
      }
      ++v6;
      ++v7;
      ia = v6;
    }
    while ( v6 < this->m_MessageHandlers.m_Memory.m_nAllocationCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003EE0
// Name: public: void CRemoteServer::RequestValue(class IServerDataResponse __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRemoteServer::RequestValue(CRemoteServer *this, IServerDataResponse *requester, const char *variable)
{
  int v4; // eax
  int v5; // edi
  UtlLinkedListElem_t<CRemoteServer::ResponseHandler_t,int> *v6; // eax
  int m_Tail; // ecx
  int v8; // edi
  bool v9; // zf
  int v10; // eax
  char buf[512]; // [esp+Ch] [ebp-230h] BYREF
  CUtlBuffer cmd; // [esp+20Ch] [ebp-30h] BYREF

  v4 = CUtlLinkedList<CRemoteServer::ResponseHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::ResponseHandler_t,int>,int>>::AllocInternal(
         this: &this->m_ResponseHandlers,
         multilist: false);
  v5 = v4;
  if ( v4 == -1 )
  {
    v5 = -1;
  }
  else
  {
    CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
      this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_ResponseHandlers,
      elem: v4);
    v6 = &this->m_ResponseHandlers.m_Memory.m_pMemory[v5];
    v6->m_Next = -1;
    m_Tail = this->m_ResponseHandlers.m_Tail;
    v6->m_Previous = m_Tail;
    this->m_ResponseHandlers.m_Tail = v5;
    if ( m_Tail == -1 )
      this->m_ResponseHandlers.m_Head = v5;
    else
      this->m_ResponseHandlers.m_Memory.m_pMemory[m_Tail].m_Next = v5;
    ++this->m_ResponseHandlers.m_ElementCount;
  }
  v8 = v5;
  this->m_ResponseHandlers.m_Memory.m_pMemory[v8].m_Element.requestID = this->m_iCurrentRequestID;
  this->m_ResponseHandlers.m_Memory.m_pMemory[v8].m_Element.handler = requester;
  CUtlBuffer::CUtlBuffer(this: &cmd, pBuffer: buf, nSize: 512, nFlags: 0);
  v9 = (cmd.m_Flags & 1) == 0;
  v10 = this->m_iCurrentRequestID++;
  if ( v9 )
    CUtlBuffer::PutTypeBin<int>(this: &cmd, src: v10);
  else
    CUtlBuffer::Printf(this: &cmd, pFmt: "%d", v10);
  if ( (cmd.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &cmd, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: &cmd, src: 0);
  CUtlBuffer::PutString(this: &cmd, pString: variable);
  CUtlBuffer::PutString(this: &cmd, pString: defaultValue);
  g_pGameServerData->WriteDataRequest(
    this: g_pGameServerData,
    a2: this->m_ListenerID,
    a3: cmd.m_Memory.m_pMemory,
    a4: cmd.m_Put);
  if ( cmd.m_Memory.m_nGrowSize >= 0 && cmd.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10004010
// Name: public: void CRemoteServer::AddServerMessageHandler(class IServerDataResponse __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRemoteServer::AddServerMessageHandler(CRemoteServer *this, IServerDataResponse *handler, char *watch)
{
  CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int> > *p_m_MessageHandlers; // esi
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int m_Tail; // ecx
  int v8; // edi

  p_m_MessageHandlers = &this->m_MessageHandlers;
  v4 = CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int>>::AllocInternal(
         this: &this->m_MessageHandlers,
         multilist: false);
  v5 = v4;
  if ( v4 == -1 )
  {
    v5 = -1;
  }
  else
  {
    CUtlLinkedList<CRemoteServer::MessageHandler_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CRemoteServer::MessageHandler_t,int>,int>>::Unlink(
      this: p_m_MessageHandlers,
      elem: v4);
    v6 = (int)&p_m_MessageHandlers->m_Memory.m_pMemory[v5];
    *(_DWORD *)(v6 + 40) = -1;
    m_Tail = p_m_MessageHandlers->m_Tail;
    *(_DWORD *)(v6 + 36) = m_Tail;
    p_m_MessageHandlers->m_Tail = v5;
    if ( m_Tail == -1 )
      p_m_MessageHandlers->m_Head = v5;
    else
      p_m_MessageHandlers->m_Memory.m_pMemory[m_Tail].m_Next = v5;
    ++p_m_MessageHandlers->m_ElementCount;
  }
  v8 = v5;
  strncpy(
    dest: (unsigned __int8 *)&p_m_MessageHandlers->m_Memory.m_pMemory[v8],
    source: (unsigned __int8 *)watch,
    count: 0x1Fu);
  p_m_MessageHandlers->m_Memory.m_pMemory[v8].m_Element.messageName[31] = 0;
  p_m_MessageHandlers->m_Memory.m_pMemory[v8].m_Element.handler = handler;
}

//------------------------------------------------------------------------------
// Address: 0x10016D70
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x10017450
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
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
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x10019A50
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x10045370
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100454D0
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
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
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x100477F0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047E10
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048C20
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x10048C90
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049130
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050A40
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
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
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x100511C0
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
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
// Address: 0x10051220
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
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
// Address: 0x100522F0
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
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
// Address: 0x1005E300
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x10074230
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
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
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x10074360
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
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
