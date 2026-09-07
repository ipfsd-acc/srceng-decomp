// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/vgui.cpp
// Functions: 67
// ============================================================

#include "vgui2\src\vgui.h"

//------------------------------------------------------------------------------
// Address: 0x10004790
// Name: protected: int CUtlLinkedList<struct CInputWin32::InputContext_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CInputWin32::InputContext_t,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::AllocInternal(
        CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *m_pMemory; // ecx
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
    CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x10005270
// Name: public: void CUtlLinkedList<struct CInputWin32::InputContext_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CInputWin32::InputContext_t,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::Unlink(
        CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx

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
        this->m_Tail = v2->m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
      --this->m_ElementCount;
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005950
// Name: public: void CUtlLinkedList<struct CInputWin32::InputContext_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CInputWin32::InputContext_t,int>,int>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::LinkBefore(
        CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int> > *this,
        int before,
        int elem)
{
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *m_pMemory; // ebx
  int m_Tail; // edx

  CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == -1 )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  m_pMemory[elem].m_Previous = m_Tail;
  if ( m_Tail == -1 )
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
// Address: 0x10005DE0
// Name: public: int CUtlLinkedList<struct CInputWin32::InputContext_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CInputWin32::InputContext_t,int>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::InsertBefore(
        CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int> > *this,
        int before)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *v5; // eax

  result = CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory = nullptr;
      v5->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_nAllocationCount = 0;
      v5->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_nGrowSize = 0;
      v5->m_Element.m_KeyCodeUnhandledListeners.m_Size = 0;
      v5->m_Element.m_KeyCodeUnhandledListeners.m_pElements = nullptr;
      vgui::CKeyRepeatHandler::CKeyRepeatHandler(this: &v5->m_Element.m_keyRepeater);
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005E50
// Name: public: void CUtlLinkedList<struct CInputWin32::InputContext_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct CInputWin32::InputContext_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::RemoveAll(
        CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int> > *this)
{
  int m_Head; // ebx
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *v2; // esi
  bool v3; // sf
  int m_Next; // edi
  vgui::VPanel **m_pMemory; // eax
  int m_FirstFree; // eax
  int v7; // eax
  CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int> > *v8; // [esp+0h] [ebp-4h]

  v8 = this;
  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        v3 = v2->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_nGrowSize < 0;
        m_Next = v2->m_Next;
        v2->m_Element.m_KeyCodeUnhandledListeners.m_Size = 0;
        if ( !v3 )
        {
          if ( v2->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory);
            this = v8;
            v2->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory = nullptr;
          }
          v2->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_nAllocationCount = 0;
        }
        v3 = v2->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_nGrowSize < 0;
        m_pMemory = v2->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory;
        v2->m_Element.m_KeyCodeUnhandledListeners.m_pElements = m_pMemory;
        if ( !v3 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            this = v8;
            v2->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory = nullptr;
          }
          v2->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_nAllocationCount = 0;
        }
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
    v7 = this->m_Head;
    if ( v7 != -1 )
      this->m_FirstFree = v7;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015240
// Name: bool PriorityQueueComp(struct MessageItem_t const __near &,struct MessageItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PriorityQueueComp(const MessageItem_t *x, const MessageItem_t *y)
{
  float arrivalTime; // xmm0_4
  float v3; // xmm1_4

  arrivalTime = x->_arrivalTime;
  v3 = y->_arrivalTime;
  if ( arrivalTime > v3 )
    return true;
  if ( v3 <= arrivalTime )
    return x->_messageID > y->_messageID;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10015290
// Name: bool IsDispatchingMessageQueue(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsDispatchingMessageQueue()
{
  return (*((_BYTE *)&g_VGui + 56) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100152A0
// Name: public: virtual unsigned long CVGui::PanelToHandle(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVGui::PanelToHandle(CVGui *this, unsigned int panel)
{
  if ( panel != 0 )
    return (*(unsigned int (__thiscall **)(unsigned int))(*(_DWORD *)panel + 20))(a1: panel);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100152C0
// Name: public: virtual void CVGui::MarkPanelForDeletion(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::MarkPanelForDeletion(CVGui *this, unsigned int panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Delete");
  else
    v4 = nullptr;
  ((void (__thiscall *)(CVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))this->PostMessageA)(
    a1: this,
    a2: panel,
    a3: v4,
    a4: 0,
    a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10015310
// Name: public: virtual void CVGui::ShutdownMessage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::ShutdownMessage(CVGui *this, unsigned int shutdownID)
{
  unsigned int v2; // esi
  int i; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  vgui::IVGui_vtbl *v6; // edi
  int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax

  v2 = vgui::g_pSurface->GetEmbeddedPanel(this: vgui::g_pSurface);
  for ( i = 0; i < (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 112))(a1: v2); ++i )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ShutdownRequest", firstKey: "id", firstValue: shutdownID);
    else
      v5 = nullptr;
    v6 = vgui::g_pIVgui->__vftable;
    v7 = (*(int (__thiscall **)(unsigned int, int, KeyValues *, _DWORD, _DWORD))(*(_DWORD *)v2 + 116))(
           a1: v2,
           a2: i,
           a3: v5,
           a4: 0,
           a5: 0);
    ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessageA)(a1: vgui::g_pIVgui, a2: v7);
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "ShutdownRequest", firstKey: "id", firstValue: shutdownID);
  else
    v9 = nullptr;
  ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
    a1: vgui::g_pIVgui,
    a2: v2,
    a3: v9,
    a4: 0,
    a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100153E0
// Name: public: virtual void CVGui::DPrintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVGui::DPrintf(CVGui *this, const char *format, ...)
{
  char buf[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+810h] [ebp+10h] BYREF

  va_start(params, format);
  V_vsnprintf(pDest: buf, maxLen: 2048, pFormat: format, params);
  _Plat_DebugString(a1: buf);
}

//------------------------------------------------------------------------------
// Address: 0x10015420
// Name: public: virtual void CVGui::DPrintf2(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CVGui::DPrintf2(CVGui *this, const char *format, ...)
{
  unsigned int v2; // kr00_4
  int v3; // [esp-4h] [ebp-804h]
  char buf[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+810h] [ebp+10h] BYREF

  va_start(params, format);
  v3 = ctr++;
  V_snprintf(pDest: buf, maxLen: 2048, pFormat: "%d:", v3);
  v2 = strlen(buf);
  V_vsnprintf(pDest: &buf[v2], maxLen: 2048 - v2, pFormat: format, params);
  _Plat_DebugString(a1: buf);
}

//------------------------------------------------------------------------------
// Address: 0x100154A0
// Name: void vgui::vgui_strcpy(char __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::vgui_strcpy(char *dst, int dstLen, char *src)
{
  signed int v3; // esi

  v3 = strlen(src) + 1;
  if ( v3 > dstLen )
    v3 = dstLen;
  memcpy((unsigned __int8 *)dst, (unsigned __int8 *)src, count: v3 - 1);
  dst[v3 - 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100154E0
// Name: public: virtual struct AppSystemInfo_t const __near * CVGui::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CVGui::GetDependencies(CVGui *this)
{
  return s_Dependencies;
}

//------------------------------------------------------------------------------
// Address: 0x100154F0
// Name: public: virtual void __near * CVGui::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CVGui::QueryInterface(CVGui *this, const char *pInterfaceName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  return FactoryThis(a1: pInterfaceName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10015510
// Name: public: void CUtlMemory<struct CUtlHandleTable<class vgui::VPanel,20>::EntryType_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlHandleTable<vgui::VPanel,20>::EntryType_t,int>::Grow(
        CUtlMemory<CUtlHandleTable<vgui::VPanel,20>::EntryType_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlHandleTable<vgui::VPanel,20>::EntryType_t *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlHandleTable<vgui::VPanel,20>::EntryType_t *)_g_pMemAlloc->Realloc_2(
                                                                           this: _g_pMemAlloc,
                                                                           a2: m_pMemory,
                                                                           a3: v7);
    else
      this->m_pMemory = (CUtlHandleTable<vgui::VPanel,20>::EntryType_t *)_g_pMemAlloc->Alloc_2(
                                                                           this: _g_pMemAlloc,
                                                                           a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015650
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CVGui::Context_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 4;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: m_pMemory,
                                                                                  a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015700
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct MessageItem_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<MessageItem_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<MessageItem_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<MessageItem_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100157B0
// Name: public: virtual void CBaseAppSystem<class vgui::IVGui>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<vgui::IVGui>::Reconnect(
        CWin32Surface *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x100157D0
// Name: public: virtual void CVGui::AssociatePanelWithContext(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::AssociatePanelWithContext(CVGui *this, int context, unsigned int pRoot)
{
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *p_m_DefaultContext; // eax

  if ( context == -1 )
    p_m_DefaultContext = (UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *)&this->m_DefaultContext;
  else
    p_m_DefaultContext = &this->m_Contexts.m_Memory.m_pMemory[(unsigned __int16)context];
  vgui::g_pInput->AssociatePanelWithInputContext(
    this: vgui::g_pInput,
    a2: p_m_DefaultContext->m_Element.m_hInputContext,
    a3: pRoot);
}

//------------------------------------------------------------------------------
// Address: 0x10015810
// Name: public: virtual void CVGui::ResetContext(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::ResetContext(CVGui *this, int context)
{
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *p_m_DefaultContext; // eax

  if ( context == -1 )
    p_m_DefaultContext = (UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *)&this->m_DefaultContext;
  else
    p_m_DefaultContext = &this->m_Contexts.m_Memory.m_pMemory[(unsigned __int16)context];
  vgui::g_pInput->ResetInputContext(this: vgui::g_pInput, a2: p_m_DefaultContext->m_Element.m_hInputContext);
}

//------------------------------------------------------------------------------
// Address: 0x10015840
// Name: public: void CUtlLinkedList<struct CVGui::Context_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CVGui::Context_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100158B0
// Name: protected: unsigned short CUtlLinkedList<struct CVGui::Context_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CVGui::Context_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10015A30
// Name: protected: unsigned short CUtlLinkedList<struct MessageItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct MessageItem_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<MessageItem_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10015BB0
// Name: public: virtual void CVGui::SpewAllActivePanelNames(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVGui::SpewAllActivePanelNames(CVGui *this@<ecx>, int a2@<edi>)
{
  CVGui *v2; // edx
  int v3; // esi
  CUtlHandleTable<vgui::VPanel,20>::EntryType_t *m_pMemory; // eax
  bool v5; // zf
  CUtlHandleTable<vgui::VPanel,20>::EntryType_t *v6; // eax
  unsigned int v7; // eax
  unsigned int m_Size; // edi
  unsigned int v9; // ecx
  CUtlHandleTable<vgui::VPanel,20>::EntryType_t *v10; // esi
  unsigned int v11; // eax
  unsigned int m_pData; // esi
  const char *v13; // eax
  int nCount; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  v2 = this;
  v3 = 0;
  nCount = this->m_HandleTable.m_list.m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      m_pMemory = v2->m_HandleTable.m_list.m_Memory.m_pMemory;
      v5 = m_pMemory[v3].m_pData == nullptr;
      v6 = &m_pMemory[v3];
      if ( !v5 )
      {
        v7 = v3 & 0xFFFFF | (*(_DWORD *)v6 << 20);
        if ( v7 != -1 )
        {
          m_Size = v2->m_HandleTable.m_list.m_Size;
          v9 = v7 & 0xFFFFF;
          if ( (v7 & 0xFFFFF) < m_Size )
          {
            v10 = v2->m_HandleTable.m_list.m_Memory.m_pMemory;
            v11 = v7 >> 20;
            if ( (*(_DWORD *)&v10[v9] & 0x7FFFFFFF) == v11 && (*(_DWORD *)&v10[v9] & 0x80000000) != 0x80000000 )
            {
              if ( v9 >= m_Size
                || (*(_DWORD *)&v10[v9] & 0x7FFFFFFF) != v11
                || (*(_DWORD *)&v10[v9] & 0x80000000) == 0x80000000 )
              {
                m_pData = 0;
              }
              else
              {
                m_pData = (unsigned int)v10[v9].m_pData;
              }
              a2 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)m_pData + 144))(a1: m_pData, a2);
              v13 = vgui::g_pIPanel->GetName(this: vgui::g_pIPanel, a2: m_pData);
              _Msg(a1: "\tpanel '%s' of type '%s' leaked\n", a2: v13);
            }
            v2 = this;
            v3 = i;
          }
        }
      }
      i = ++v3;
    }
    while ( v3 < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015CA0
// Name: public: virtual unsigned int CVGui::HandleToPanel(unsigned long)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall CVGui::HandleToPanel(CVGui *this, unsigned int index)
{
  unsigned int m_Size; // ebx
  unsigned int v3; // eax
  CUtlHandleTable<vgui::VPanel,20>::EntryType_t *m_pMemory; // esi

  if ( index == -1 )
    return nullptr;
  m_Size = this->m_HandleTable.m_list.m_Size;
  v3 = index & 0xFFFFF;
  if ( (index & 0xFFFFF) >= m_Size )
    return nullptr;
  m_pMemory = this->m_HandleTable.m_list.m_Memory.m_pMemory;
  if ( (*(_DWORD *)&m_pMemory[v3] & 0x7FFFFFFF) != index >> 20
    || (*(_DWORD *)&m_pMemory[v3] & 0x80000000) == 0x80000000
    || v3 >= m_Size
    || (*(_DWORD *)&m_pMemory[v3] & 0x7FFFFFFF) != index >> 20
    || (*(_DWORD *)&m_pMemory[v3] & 0x80000000) == 0x80000000 )
  {
    return nullptr;
  }
  else
  {
    return m_pMemory[v3].m_pData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015D20
// Name: public: virtual void CVGui::RemoveTickSignal(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::RemoveTickSignal(CVGui *this, vgui::VPanel *panel)
{
  int m_Size; // edx
  int v4; // ecx
  CVGui::Tick_t **i; // eax
  CVGui::Tick_t *v6; // edi

  m_Size = this->m_TickSignalVec.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_TickSignalVec.m_Memory.m_pMemory; ; ++i )
    {
      v6 = *i;
      if ( (*i)->panel == panel )
        break;
      if ( ++v4 >= m_Size )
        return;
    }
    if ( m_Size - v4 - 1 > 0 )
      _V_memmove(
        dest: &this->m_TickSignalVec.m_Memory.m_pMemory[v4],
        src: &this->m_TickSignalVec.m_Memory.m_pMemory[v4 + 1],
        count: 4 * (m_Size - v4 - 1));
    --this->m_TickSignalVec.m_Size;
    free(pMem: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015D80
// Name: public: virtual enum InitReturnVal_t CVGui::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVGui::Init(CVGui *this)
{
  int v2; // eax

  this->m_hContext = -1;
  v2 = _CommandLine();
  *((_BYTE *)this + 56) ^= (*((_BYTE *)this + 56)
                          ^ (8
                           * ((*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(
                                a1: v2,
                                a2: "-vguimessages") != 0)))
                         & 8;
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015DD0
// Name: public: void CUtlLinkedList<struct MessageItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct MessageItem_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<MessageItem_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015E40
// Name: public: void CUtlPriorityQueue<struct MessageItem_t,class CDefUtlPriorityQueueLessFunc<struct MessageItem_t>,class CUtlMemory<struct MessageItem_t,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<MessageItem_t,CDefUtlPriorityQueueLessFunc<MessageItem_t>,CUtlMemory<MessageItem_t,int>>::RemoveAtHead(
        CUtlPriorityQueue<MessageItem_t,CDefUtlPriorityQueueLessFunc<MessageItem_t>,CUtlMemory<MessageItem_t,int> > *this)
{
  int m_Size; // ecx
  MessageItem_t *m_pMemory; // eax
  int v4; // ecx
  __int64 v5; // xmm0_8
  MessageItem_t *v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // ebx
  bool v11; // al
  int v12; // ebx
  bool v13; // al
  MessageItem_t *v14; // edx
  __int64 v15; // xmm0_8
  __int64 v16; // xmm1_8
  int messageID; // ebx
  MessageItem_t *v18; // eax
  int v19; // ecx
  MessageItem_t *v20; // eax
  int half; // [esp+4h] [ebp-Ch]
  int count; // [esp+8h] [ebp-8h]
  int index; // [esp+Ch] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
    {
      m_pMemory = this->m_heap.m_Memory.m_pMemory;
      v4 = m_Size;
      v5 = *(_QWORD *)&this->m_heap.m_Memory.m_pMemory[v4 - 1]._params;
      v6 = &this->m_heap.m_Memory.m_pMemory[v4 - 1];
      *(_QWORD *)&m_pMemory->_params = v5;
      *(_QWORD *)&m_pMemory->_from = *(_QWORD *)&v6->_from;
      m_pMemory->_messageID = v6->_messageID;
    }
    --this->m_heap.m_Size;
  }
  v7 = this->m_heap.m_Size;
  v8 = 0;
  index = 0;
  count = v7;
  if ( v7 != 0 )
  {
    v9 = 0;
    half = v7 / 2;
    if ( v7 / 2 > 0 )
    {
      while ( 1 )
      {
        v10 = 2 * v8 + 1;
        if ( v10 < count )
        {
          v11 = this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v8], a2: &this->m_heap.m_Memory.m_pMemory[v10]);
          v8 = index;
          if ( v11 )
            v9 = v10;
        }
        v12 = v10 + 1;
        if ( v12 < count )
        {
          v13 = this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v9], a2: &this->m_heap.m_Memory.m_pMemory[v12]);
          v8 = index;
          if ( v13 )
            v9 = v12;
        }
        if ( v9 == v8 )
          break;
        v14 = this->m_heap.m_Memory.m_pMemory;
        v15 = *(_QWORD *)&this->m_heap.m_Memory.m_pMemory[v8]._params;
        v16 = *(_QWORD *)&this->m_heap.m_Memory.m_pMemory[v8]._from;
        messageID = this->m_heap.m_Memory.m_pMemory[v8]._messageID;
        v18 = &this->m_heap.m_Memory.m_pMemory[v8];
        v19 = v9;
        *(_QWORD *)&v18->_params = *(_QWORD *)&this->m_heap.m_Memory.m_pMemory[v9]._params;
        *(_QWORD *)&v18->_from = *(_QWORD *)&v14[v9]._from;
        v18->_messageID = v14[v9]._messageID;
        v20 = this->m_heap.m_Memory.m_pMemory;
        *(_QWORD *)&v20[v19]._params = v15;
        *(_QWORD *)&v20[v19]._from = v16;
        v20[v19]._messageID = messageID;
        index = v9;
        if ( v9 >= half )
          break;
        v8 = v9;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015FD0
// Name: public: void CUtlLinkedList<struct CVGui::Context_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CVGui::Context_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *m_pMemory; // eax
  int m_Previous; // edi
  unsigned __int16 *p_m_Next; // edx
  unsigned __int16 v7; // cx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      m_Previous = m_pMemory[elem].m_Previous;
      p_m_Next = &m_pMemory[elem].m_Next;
      v7 = *p_m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = v7;
      }
      else
      {
        m_pMemory[m_Previous].m_Next = v7;
        v2 = elem;
      }
      if ( v7 == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[v7].m_Previous = m_Previous;
      *p_m_Next = v2;
      --this->m_ElementCount;
      m_pMemory[elem].m_Previous = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016060
// Name: public: void CUtlLinkedList<struct MessageItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct MessageItem_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<MessageItem_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016170
// Name: private: void CVGui::ClearMessageQueues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::ClearMessageQueues(CVGui *this)
{
  int i; // eax
  int v3; // edi
  KeyValues *params; // ecx
  int j; // eax
  int v6; // edi
  KeyValues *v7; // ecx
  KeyValues *v8; // ecx

  for ( i = this->m_MessageQueue.m_Head; i != 0xFFFF; i = this->m_MessageQueue.m_Memory.m_pMemory[v3].m_Next )
  {
    v3 = (unsigned __int16)i;
    params = this->m_MessageQueue.m_Memory.m_pMemory[v3].m_Element._params;
    if ( params != nullptr )
      KeyValues::deleteThis(this: params);
  }
  CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_MessageQueue);
  for ( j = this->m_SecondaryQueue.m_Head; j != 0xFFFF; j = this->m_SecondaryQueue.m_Memory.m_pMemory[v6].m_Next )
  {
    v6 = (unsigned __int16)j;
    v7 = this->m_SecondaryQueue.m_Memory.m_pMemory[v6].m_Element._params;
    if ( v7 != nullptr )
      KeyValues::deleteThis(this: v7);
  }
  CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_SecondaryQueue);
  while ( this->m_DelayedMessageQueue.m_heap.m_Size > 0 )
  {
    v8 = this->m_DelayedMessageQueue.m_heap.m_Memory.m_pMemory->_params;
    if ( v8 != nullptr )
      KeyValues::deleteThis(this: v8);
    CUtlPriorityQueue<MessageItem_t,CDefUtlPriorityQueueLessFunc<MessageItem_t>,CUtlMemory<MessageItem_t,int>>::RemoveAtHead(this: &this->m_DelayedMessageQueue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016230
// Name: public: virtual bool CVGui::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVGui::Connect(CVGui *this, void *(__cdecl *factory)(const char *, int *))
{
  void (__thiscall ***v2)(_DWORD, const char *, vgui::ILocalize *); // eax
  void *(__cdecl *v4)(const char *, int *); // [esp+0h] [ebp-Ch] BYREF
  void *(__cdecl *v5)(const char *, int *); // [esp+4h] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  v4 = factory;
  v5 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &v5, nFactoryCount: 1);
  CWin32Surface::DrawFlushText(pFactoryList: &v4, nFactoryCount: 1);
  if ( g_pFullFileSystem != nullptr && g_pVGuiLocalize != nullptr )
  {
    if ( g_pMatchFramework != nullptr )
    {
      v2 = (void (__thiscall ***)(_DWORD, const char *, vgui::ILocalize *))((int (__thiscall *)(IMatchFramework *, void *(__cdecl *)(const char *, int *), void *(__cdecl *)(const char *, int *)))g_pMatchFramework->GetMatchExtensions)(
                                                                             a1: g_pMatchFramework,
                                                                             a2: v4,
                                                                             a3: v5);
      if ( v2 != nullptr )
        (**v2)(a1: v2, a2: "Localize_001", a3: g_pVGuiLocalize);
    }
    return vgui::VGui_InternalLoadInterfaces(factoryList: &factory, numFactories: 1);
  }
  else
  {
    _Warning(a1: "IVGui unable to connect to required interfaces!\n");
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100162D0
// Name: public: virtual void CVGui::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10016310
// Name: public: virtual void CVGui::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::Shutdown(CVGui *this)
{
  int m_Head; // eax
  int m_Next; // edi

  vgui::g_pSystem->SaveUserConfigFile(this: vgui::g_pSystem);
  m_Head = this->m_Contexts.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_Next = this->m_Contexts.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      this->DestroyContext(this, a2: m_Head);
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CVGui::ClearMessageQueues(this);
  vgui::g_pSystem->Shutdown(this: vgui::g_pSystem);
  vgui::g_pScheme->Shutdown(this: vgui::g_pScheme, a2: true);
  if ( vgui::g_pSurface->QueryInterface(this: vgui::g_pSurface, a2: "MatSystemSurface006") == nullptr )
    vgui::g_pSurface->Shutdown(this: vgui::g_pSurface);
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x100163B0
// Name: public: void CUtlLinkedList<struct CVGui::Context_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CVGui::Context_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
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
// Address: 0x10016430
// Name: public: void CUtlLinkedList<struct MessageItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct MessageItem_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<MessageItem_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<MessageItem_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<MessageItem_t,unsigned short> *v7; // ebx

  CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
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
// Address: 0x100164C0
// Name: public: virtual void CVGui::AddTickSignal(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::AddTickSignal(CVGui *this, vgui::VPanel *panel, int intervalMilliseconds)
{
  int m_Size; // edx
  int v5; // eax
  CVGui::Tick_t **v6; // ecx
  CVGui::Tick_t *v7; // ebx
  void *v8; // ebx
  int v9; // eax
  const char *v10; // eax
  bool v11; // zf
  vgui::IClientPanel *(__thiscall *Client)(vgui::VPanel *); // eax
  int v13; // ecx
  int (__thiscall *v14)(int); // eax
  unsigned __int8 *v15; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CWin32Font *,int> *p_m_TickSignalVec; // esi
  int v18; // edi
  CWin32Font **m_pMemory; // ecx
  int v20; // eax
  CWin32Font **v21; // edi

  m_Size = this->m_TickSignalVec.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v8 = operator new(nSize: 0x4Cu);
    *(_DWORD *)v8 = panel;
    *((_DWORD *)v8 + 1) = intervalMilliseconds;
    *((_DWORD *)v8 + 2) = *((_DWORD *)v8 + 1) + vgui::g_pSystem->GetTimeMillis(this: vgui::g_pSystem);
    v9 = (int)panel->Client(this: panel);
    v10 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 72))(a1: v9);
    v11 = &v10[strlen(v10) + 1] == v10 + 1;
    Client = panel->Client;
    if ( v11 )
    {
      v13 = (int)Client(this: panel);
      v14 = *(int (__thiscall **)(int))(*(_DWORD *)v13 + 76);
    }
    else
    {
      v13 = (int)Client(this: panel);
      v14 = *(int (__thiscall **)(int))(*(_DWORD *)v13 + 72);
    }
    v15 = (unsigned __int8 *)v14(a1: v13);
    strncpy(dest: (unsigned __int8 *)v8 + 12, source: v15, count: 0x40u);
    m_nAllocationCount = this->m_TickSignalVec.m_Memory.m_nAllocationCount;
    p_m_TickSignalVec = (CUtlMemory<CWin32Font *,int> *)&this->m_TickSignalVec;
    v18 = this->m_TickSignalVec.m_Size;
    if ( v18 + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(this: p_m_TickSignalVec, num: v18 - m_nAllocationCount + 1);
    ++p_m_TickSignalVec[1].m_pMemory;
    m_pMemory = p_m_TickSignalVec->m_pMemory;
    v20 = (int)p_m_TickSignalVec[1].m_pMemory - v18 - 1;
    p_m_TickSignalVec[1].m_nAllocationCount = (int)p_m_TickSignalVec->m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &m_pMemory[v18 + 1], src: &m_pMemory[v18], count: 4 * v20);
    v21 = &p_m_TickSignalVec->m_pMemory[v18];
    if ( v21 != nullptr )
      *v21 = (CWin32Font *)v8;
  }
  else
  {
    v6 = this->m_TickSignalVec.m_Memory.m_pMemory;
    while ( 1 )
    {
      v7 = *v6;
      if ( (*v6)->panel == panel )
        break;
      ++v5;
      ++v6;
      if ( v5 >= m_Size )
        goto LABEL_5;
    }
    v7->interval = intervalMilliseconds;
    v7->nexttick = v7->interval + vgui::g_pSystem->GetTimeMillis(this: vgui::g_pSystem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100165E0
// Name: public: unsigned int CUtlHandleTable<class vgui::VPanel,20>::AddHandle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHandleTable<vgui::VPanel,20>::AddHandle(CUtlHandleTable<vgui::VPanel,20> *this)
{
  int *m_pMemory; // ecx
  int m_current; // ecx
  CUtlHandleTable<vgui::VPanel,20>::EntryType_t *v4; // eax
  CUtlHandleTable<vgui::VPanel,20>::EntryType_t *v5; // eax

  if ( this->m_unused.m_heap.m_Size <= 0 )
  {
    m_current = CUtlVector<CUtlHandleTable<vgui::VPanel,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::VPanel,20>::EntryType_t,int>>::InsertBefore(
                  this: &this->m_list,
                  elem: this->m_list.m_Size);
  }
  else
  {
    m_pMemory = this->m_unused.m_heap.m_Memory.m_pMemory;
    this->m_unused.m_current = *m_pMemory;
    if ( this->m_unused.m_heap.m_Size - 1 > 0 )
      _V_memmove(dest: m_pMemory, src: m_pMemory + 1, count: 4 * (this->m_unused.m_heap.m_Size - 1));
    --this->m_unused.m_heap.m_Size;
    m_current = this->m_unused.m_current;
  }
  v4 = this->m_list.m_Memory.m_pMemory;
  *(_DWORD *)&v4[m_current] &= ~0x80000000;
  v5 = &v4[m_current];
  v5->m_pData = nullptr;
  ++this->m_nValidHandles;
  return m_current & 0xFFFFF | (*(_DWORD *)v5 << 20);
}

//------------------------------------------------------------------------------
// Address: 0x10016650
// Name: public: void CUtlPriorityQueue<struct MessageItem_t,class CDefUtlPriorityQueueLessFunc<struct MessageItem_t>,class CUtlMemory<struct MessageItem_t,int>>::Insert(struct MessageItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<MessageItem_t,CDefUtlPriorityQueueLessFunc<MessageItem_t>,CUtlMemory<MessageItem_t,int>>::Insert(
        CUtlPriorityQueue<MessageItem_t,CDefUtlPriorityQueueLessFunc<MessageItem_t>,CUtlMemory<MessageItem_t,int> > *this,
        const MessageItem_t *element)
{
  CUtlPriorityQueue<MessageItem_t,CDefUtlPriorityQueueLessFunc<MessageItem_t>,CUtlMemory<MessageItem_t,int> > *v2; // ebx
  int v3; // ecx
  MessageItem_t *m_pMemory; // eax
  int v5; // edi
  int v6; // esi
  unsigned int v7; // ebx
  MessageItem_t *v8; // eax
  int messageID; // ecx
  __int64 v10; // xmm0_8
  __int64 v11; // xmm1_8
  MessageItem_t *v12; // eax

  v2 = this;
  v3 = CUtlVector<MessageItem_t,CUtlMemory<MessageItem_t,int>>::InsertBefore(
         this: &this->m_heap,
         elem: this->m_heap.m_Size);
  v2->m_heap.m_Memory.m_pMemory[v3] = *element;
  if ( v3 != 0 )
  {
    while ( 1 )
    {
      m_pMemory = v2->m_heap.m_Memory.m_pMemory;
      v5 = (v3 + 1) / 2 - 1;
      v6 = v5;
      v7 = v3;
      if ( this->m_LessFunc(a1: &m_pMemory[v3], a2: &m_pMemory[v5]) )
        break;
      v8 = this->m_heap.m_Memory.m_pMemory;
      messageID = this->m_heap.m_Memory.m_pMemory[v6]._messageID;
      v10 = *(_QWORD *)&this->m_heap.m_Memory.m_pMemory[v6]._params;
      v11 = *(_QWORD *)&this->m_heap.m_Memory.m_pMemory[v6]._from;
      *(_QWORD *)&v8[v6]._params = *(_QWORD *)&this->m_heap.m_Memory.m_pMemory[v7]._params;
      *(_QWORD *)&v8[v6]._from = *(_QWORD *)&v8[v7]._from;
      v8[v6]._messageID = v8[v7]._messageID;
      v12 = this->m_heap.m_Memory.m_pMemory;
      *(_QWORD *)&v12[v7]._params = v10;
      *(_QWORD *)&v12[v7]._from = v11;
      v12[v7]._messageID = messageID;
      v3 = v5;
      if ( v5 == 0 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016720
// Name: public: void CUtlQueue<int,class CUtlMemory<int,int>>::Insert(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlQueue<int,CUtlMemory<int,int>>::Insert(
        CUtlQueue<int,CUtlMemory<int,int> > *this,
        const int *element)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_heap.m_Memory.m_nAllocationCount;
  m_Size = this->m_heap.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow((CUtlMemory<CWin32Font *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_heap.m_Size;
  m_pMemory = this->m_heap.m_Memory.m_pMemory;
  v6 = this->m_heap.m_Size - m_Size - 1;
  this->m_heap.m_pElements = this->m_heap.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  this->m_heap.m_Memory.m_pMemory[m_Size] = *element;
}

//------------------------------------------------------------------------------
// Address: 0x10016780
// Name: public: virtual enum AppSystemTier_t CTier3AppSystem<class vgui::IVGui,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier3AppSystem<vgui::IVGui,0>::GetTier(CTier3AppSystem<vgui::IVGui,0> *this)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10016790
// Name: public: CVGui::~CVGui(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::~CVGui(CVGui *this)
{
  this->__vftable = (CVGui_vtbl *)&CVGui::`vftable';
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&this->m_DelayedMessageQueue);
  CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_SecondaryQueue);
  if ( this->m_SecondaryQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SecondaryQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SecondaryQueue.m_Memory.m_pMemory);
      this->m_SecondaryQueue.m_Memory.m_pMemory = nullptr;
    }
    this->m_SecondaryQueue.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_MessageQueue);
  if ( this->m_MessageQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MessageQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MessageQueue.m_Memory.m_pMemory);
      this->m_MessageQueue.m_Memory.m_pMemory = nullptr;
    }
    this->m_MessageQueue.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Contexts);
  if ( this->m_Contexts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Contexts.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Contexts.m_Memory.m_pMemory);
      this->m_Contexts.m_Memory.m_pMemory = nullptr;
    }
    this->m_Contexts.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&this->m_TickSignalVec);
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&this->m_HandleTable.m_unused);
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&this->m_HandleTable.m_list);
}

//------------------------------------------------------------------------------
// Address: 0x10016870
// Name: public: virtual void CVGui::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::Start(CVGui *this)
{
  *((_BYTE *)this + 56) |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10016880
// Name: public: virtual void CVGui::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::Stop(CVGui *this)
{
  *((_BYTE *)this + 56) &= ~1u;
}

//------------------------------------------------------------------------------
// Address: 0x10016890
// Name: public: virtual bool CVGui::IsRunning(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVGui::IsRunning(CVGui *this)
{
  return *((_BYTE *)this + 56) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100168A0
// Name: public: virtual void CVGui::SetSleep(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::SetSleep(CVGui *this, bool state)
{
  *((_BYTE *)this + 56) ^= (*((_BYTE *)this + 56) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x100168C0
// Name: public: virtual bool CVGui::GetShouldVGuiControlSleep(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVGui::GetShouldVGuiControlSleep(CVGui *this)
{
  return (*((_BYTE *)this + 56) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100168D0
// Name: public: virtual void CVGui::DestroyContext(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::DestroyContext(CVGui *this, int context)
{
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *p_m_DefaultContext; // eax

  if ( this->m_hContext == context )
    this->ActivateContext(this, a2: -1);
  if ( context == -1 )
    p_m_DefaultContext = (UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *)&this->m_DefaultContext;
  else
    p_m_DefaultContext = &this->m_Contexts.m_Memory.m_pMemory[(unsigned __int16)context];
  vgui::g_pInput->DestroyInputContext(this: vgui::g_pInput, a2: p_m_DefaultContext->m_Element.m_hInputContext);
  CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::Unlink(
    this: &this->m_Contexts,
    elem: context);
  this->m_Contexts.m_Memory.m_pMemory[(unsigned __int16)context].m_Next = this->m_Contexts.m_FirstFree;
  this->m_Contexts.m_FirstFree = context;
}

//------------------------------------------------------------------------------
// Address: 0x10016930
// Name: private: void CVGui::PanelCreated(class vgui::VPanel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::PanelCreated(CVGui *this, vgui::VPanel *panel)
{
  CUtlHandleTable<vgui::VPanel,20> *p_m_HandleTable; // esi
  unsigned int v3; // eax
  int *v4; // ecx

  p_m_HandleTable = &this->m_HandleTable;
  v3 = CUtlHandleTable<vgui::VPanel,20>::AddHandle(this: &this->m_HandleTable);
  if ( v3 != -1 && (v3 & 0xFFFFF) < p_m_HandleTable->m_list.m_Size )
  {
    v4 = (int *)&p_m_HandleTable->m_list.m_Memory.m_pMemory[v3 & 0xFFFFF];
    if ( (*v4 & 0x7FFFFFFF) == v3 >> 20 )
    {
      if ( *v4 < 0 )
      {
        ++p_m_HandleTable->m_nValidHandles;
        *v4 &= ~0x80000000;
      }
      v4[1] = (int)panel;
    }
  }
  panel->SetHPanel(this: panel, a2: v3);
  vgui::g_pSurface->AddPanel(this: vgui::g_pSurface, a2: (unsigned int)panel);
}

//------------------------------------------------------------------------------
// Address: 0x100169B0
// Name: private: bool CVGui::DispatchMessages(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVGui::DispatchMessages(CVGui *this)
{
  CVGui *v1; // edi
  int v2; // eax
  int v3; // ebx
  MessageItem_t *m_pMemory; // eax
  const char *Name; // eax
  vgui::IVGui_vtbl *v6; // esi
  const char *v7; // eax
  vgui::IVGui_vtbl *v8; // esi
  const char *v9; // eax
  KeyValues *v10; // esi
  const char *v11; // eax
  int v12; // ebx
  int v13; // eax
  const char *v14; // eax
  int v15; // eax
  const char *v16; // eax
  int Int; // eax
  int *v18; // ebx
  int v19; // edi
  unsigned int v20; // eax
  int v21; // eax
  const char *String; // [esp-8h] [ebp-30h]
  int v24; // [esp-4h] [ebp-2Ch]
  int v25; // [esp-4h] [ebp-2Ch]
  int time; // [esp+10h] [ebp-18h]
  int nPassCount; // [esp+14h] [ebp-14h]
  const char *qname; // [esp+18h] [ebp-10h]
  unsigned __int16 messageIndex; // [esp+1Ch] [ebp-Ch]
  MessageItem_t *messageItem; // [esp+20h] [ebp-8h]
  bool bUsingSecondaryQueue; // [esp+25h] [ebp-3h]
  bool doneWork; // [esp+26h] [ebp-2h]
  bool bUsingDelayedQueue; // [esp+27h] [ebp-1h]

  v1 = this;
  v2 = vgui::g_pSystem->GetTimeMillis(this: vgui::g_pSystem);
  *((_BYTE *)v1 + 56) |= 4u;
  time = v2;
  doneWork = v1->m_MessageQueue.m_ElementCount > 0xCu;
  nPassCount = 0;
  bUsingDelayedQueue = v1->m_DelayedMessageQueue.m_heap.m_Size > 0;
  do
  {
    while ( 1 )
    {
      while ( v1->m_MessageQueue.m_ElementCount != 0 || v1->m_SecondaryQueue.m_ElementCount != 0 || bUsingDelayedQueue )
      {
        messageIndex = 0;
        bUsingSecondaryQueue = v1->m_SecondaryQueue.m_ElementCount != 0;
        if ( v1->m_SecondaryQueue.m_ElementCount != 0 )
        {
          messageIndex = v1->m_SecondaryQueue.m_Head;
          v3 = (int)&v1->m_SecondaryQueue.m_Memory.m_pMemory[messageIndex];
          doneWork = true;
          messageItem = (MessageItem_t *)v3;
          goto LABEL_14;
        }
        if ( bUsingDelayedQueue )
        {
          if ( v1->m_DelayedMessageQueue.m_heap.m_Size > 0 )
          {
            m_pMemory = v1->m_DelayedMessageQueue.m_heap.m_Memory.m_pMemory;
            messageItem = m_pMemory;
            if ( m_pMemory != nullptr && m_pMemory->_arrivalTime <= (float)time )
              goto LABEL_13;
          }
          bUsingDelayedQueue = false;
        }
        else
        {
          messageIndex = v1->m_MessageQueue.m_Head;
          messageItem = &v1->m_MessageQueue.m_Memory.m_pMemory[messageIndex].m_Element;
LABEL_13:
          v3 = (int)messageItem;
LABEL_14:
          if ( (*((_BYTE *)v1 + 56) & 8) != 0 )
          {
            qname = "Secondary";
            if ( v1->m_SecondaryQueue.m_ElementCount == 0 )
              qname = "Primary";
            if ( strcmp(KeyValues::GetName(this: *(KeyValues **)v3), "Tick") != 0
              && strcmp(KeyValues::GetName(this: *(KeyValues **)v3), "MouseFocusTicked") != 0
              && strcmp(KeyValues::GetName(this: *(KeyValues **)v3), "KeyFocusTicked") != 0
              && strcmp(KeyValues::GetName(this: *(KeyValues **)v3), "CursorMoved") != 0 )
            {
              Name = KeyValues::GetName(this: *(KeyValues **)v3);
              if ( _V_stricmp(s1: Name, s2: "command") != 0 )
              {
                v8 = vgui::g_pIVgui->__vftable;
                v25 = *(_DWORD *)(v3 + 16);
                v9 = KeyValues::GetName(this: *(KeyValues **)v3);
                v8->DPrintf2(this: vgui::g_pIVgui, a2: "%s Queue dispatching( %s -- %i )\n", qname, v9, v25);
              }
              else
              {
                v6 = vgui::g_pIVgui->__vftable;
                v24 = *(_DWORD *)(v3 + 16);
                String = KeyValues::GetString(this: *(KeyValues **)v3, keyName: "command", defaultValue: pHelpString);
                v7 = KeyValues::GetName(this: *(KeyValues **)v3);
                v6->DPrintf2(
                  this: vgui::g_pIVgui,
                  a2: "%s Queue dispatching command( %s, %s -- %i )\n",
                  qname,
                  v7,
                  String,
                  v24);
              }
            }
          }
          v10 = *(KeyValues **)v3;
          if ( *(_DWORD *)(v3 + 4) == -1 )
          {
            v11 = KeyValues::GetName(this: v10);
            if ( _V_stricmp(s1: v11, s2: "SetCursorPosInternal") != 0 )
            {
              v14 = KeyValues::GetName(this: v10);
              if ( _V_stricmp(s1: v14, s2: "SetJoystickXPosInternal") != 0 )
              {
                v16 = KeyValues::GetName(this: v10);
                if ( _V_stricmp(s1: v16, s2: "SetJoystickYPosInternal") == 0 )
                {
                  Int = KeyValues::GetInt(this: v10, keyName: "pos", defaultValue: 0);
                  vgui::g_pInput->UpdateJoystickYPosInternal(this: vgui::g_pInput, a2: Int);
                }
              }
              else
              {
                v15 = KeyValues::GetInt(this: v10, keyName: "pos", defaultValue: 0);
                vgui::g_pInput->UpdateJoystickXPosInternal(this: vgui::g_pInput, a2: v15);
              }
            }
            else
            {
              v12 = KeyValues::GetInt(this: v10, keyName: "xpos", defaultValue: 0);
              v13 = KeyValues::GetInt(this: v10, keyName: "ypos", defaultValue: 0);
              vgui::g_pInput->UpdateCursorPosInternal(this: vgui::g_pInput, a2: v12, a3: v13);
            }
          }
          else
          {
            v18 = (int *)vgui::g_pIVgui->HandleToPanel(this: vgui::g_pIVgui, a2: *(_DWORD *)(v3 + 4));
            if ( v18 != nullptr )
            {
              v19 = *v18;
              v20 = vgui::g_pIVgui->HandleToPanel(this: vgui::g_pIVgui, a2: messageItem->_from);
              (*(void (__thiscall **)(int *, KeyValues *, unsigned int))(v19 + 152))(a1: v18, a2: v10, a3: v20);
              v1 = this;
            }
          }
          if ( v10 != nullptr )
            KeyValues::deleteThis(this: v10);
          if ( bUsingSecondaryQueue )
          {
            CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::Unlink(
              this: &v1->m_SecondaryQueue,
              elem: messageIndex);
            v1->m_SecondaryQueue.m_Memory.m_pMemory[messageIndex].m_Next = v1->m_SecondaryQueue.m_FirstFree;
            v1->m_SecondaryQueue.m_FirstFree = messageIndex;
          }
          else if ( bUsingDelayedQueue )
          {
            CUtlPriorityQueue<MessageItem_t,CDefUtlPriorityQueueLessFunc<MessageItem_t>,CUtlMemory<MessageItem_t,int>>::RemoveAtHead(this: &v1->m_DelayedMessageQueue);
          }
          else
          {
            CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::Unlink(
              this: &v1->m_MessageQueue,
              elem: messageIndex);
            v1->m_MessageQueue.m_Memory.m_pMemory[messageIndex].m_Next = v1->m_MessageQueue.m_FirstFree;
            v1->m_MessageQueue.m_FirstFree = messageIndex;
          }
        }
      }
      v21 = nPassCount + 1;
      nPassCount = v21;
      if ( v21 != 1 )
        break;
      vgui::g_pInput->PostCursorMessage(this: vgui::g_pInput);
    }
  }
  while ( v21 < 2 );
  vgui::g_pInput->HandleExplicitSetCursor(this: vgui::g_pInput);
  *((_BYTE *)v1 + 56) &= ~4u;
  return doneWork;
}

//------------------------------------------------------------------------------
// Address: 0x10016E10
// Name: public: void CUtlHandleTable<class vgui::VPanel,20>::RemoveHandle(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHandleTable<vgui::VPanel,20>::RemoveHandle(
        CUtlHandleTable<vgui::VPanel,20> *this,
        unsigned int handle)
{
  unsigned int v2; // edi
  CUtlHandleTable<vgui::VPanel,20>::EntryType_t *v3; // edx
  int v4; // eax

  v2 = handle & 0xFFFFF;
  if ( (handle & 0xFFFFF) < this->m_list.m_Size )
  {
    v3 = &this->m_list.m_Memory.m_pMemory[v2];
    v4 = *(_DWORD *)v3 ^ (*(_DWORD *)v3 ^ (*(_DWORD *)v3 + 1)) & 0x7FFFFFFF;
    *(_DWORD *)v3 = v4;
    if ( v4 >= 0 )
    {
      *(_DWORD *)v3 = v4 | 0x80000000;
      --this->m_nValidHandles;
    }
    v3->m_pData = nullptr;
    if ( (*(_DWORD *)v3 & 0x7FFFFFFFu) < 0x7FF )
    {
      handle = v2;
      CUtlQueue<int,CUtlMemory<int,int>>::Insert(this: &this->m_unused, element: (const int *)&handle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016E70
// Name: public: unsigned short CUtlLinkedList<struct MessageItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct MessageItem_t,unsigned short>,unsigned short>>::AddToTail(struct MessageItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short> > *this,
        const MessageItem_t *src)
{
  int v3; // esi
  int result; // eax
  UtlLinkedListElem_t<MessageItem_t,unsigned short> *v5; // eax

  v3 = (unsigned __int16)CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v3);
    v5 = &this->m_Memory.m_pMemory[v3];
    if ( v5 != nullptr )
      v5->m_Element = *src;
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016ED0
// Name: public: CVGui::CVGui(void)
// Source: json
//------------------------------------------------------------------------------
CVGui *__thiscall CVGui::CVGui(CVGui *this)
{
  UtlLinkedListElem_t<MessageItem_t,unsigned short> *m_pMemory; // edx
  MessageItem_t *v3; // eax
  char v4; // cl

  this->__vftable = (CVGui_vtbl *)&CVGui::`vftable';
  this->m_HandleTable.m_nValidHandles = 0;
  this->m_HandleTable.m_list.m_Memory.m_pMemory = nullptr;
  this->m_HandleTable.m_list.m_Memory.m_nAllocationCount = 0;
  this->m_HandleTable.m_list.m_Memory.m_nGrowSize = 0;
  this->m_HandleTable.m_list.m_Size = 0;
  this->m_HandleTable.m_list.m_pElements = nullptr;
  this->m_HandleTable.m_unused.m_heap.m_Memory.m_pMemory = nullptr;
  this->m_HandleTable.m_unused.m_heap.m_Memory.m_nAllocationCount = 0;
  this->m_HandleTable.m_unused.m_heap.m_Memory.m_nGrowSize = 0;
  this->m_HandleTable.m_unused.m_heap.m_Size = 0;
  this->m_HandleTable.m_unused.m_heap.m_pElements = nullptr;
  this->m_TickSignalVec.m_Memory.m_pMemory = nullptr;
  this->m_TickSignalVec.m_Memory.m_nAllocationCount = 0;
  this->m_TickSignalVec.m_Memory.m_nGrowSize = 0;
  this->m_TickSignalVec.m_Size = 0;
  this->m_TickSignalVec.m_pElements = nullptr;
  this->m_Contexts.m_Memory.m_pMemory = nullptr;
  this->m_Contexts.m_Memory.m_nAllocationCount = 0;
  this->m_Contexts.m_Memory.m_nGrowSize = 0;
  this->m_Contexts.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Contexts.m_FirstFree = 0xFFFF;
  this->m_Contexts.m_pElements = this->m_Contexts.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Contexts.m_Head = -1;
  this->m_Contexts.m_NumAlloced = 0;
  this->m_MessageQueue.m_Memory.m_pMemory = nullptr;
  this->m_MessageQueue.m_Memory.m_nAllocationCount = 0;
  this->m_MessageQueue.m_Memory.m_nGrowSize = 0;
  this->m_MessageQueue.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_MessageQueue.m_FirstFree = 0xFFFF;
  this->m_MessageQueue.m_pElements = this->m_MessageQueue.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_MessageQueue.m_Head = -1;
  this->m_MessageQueue.m_NumAlloced = 0;
  this->m_SecondaryQueue.m_Memory.m_pMemory = nullptr;
  this->m_SecondaryQueue.m_Memory.m_nAllocationCount = 0;
  this->m_SecondaryQueue.m_Memory.m_nGrowSize = 0;
  this->m_SecondaryQueue.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_SecondaryQueue.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_SecondaryQueue.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_SecondaryQueue.m_Head = -1;
  this->m_SecondaryQueue.m_pElements = m_pMemory;
  this->m_SecondaryQueue.m_NumAlloced = 0;
  this->m_DelayedMessageQueue.m_heap.m_Memory.m_pMemory = nullptr;
  this->m_DelayedMessageQueue.m_heap.m_Memory.m_nAllocationCount = 4;
  this->m_DelayedMessageQueue.m_heap.m_Memory.m_nGrowSize = 0;
  v3 = (MessageItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 80);
  this->m_DelayedMessageQueue.m_heap.m_Memory.m_pMemory = v3;
  this->m_DelayedMessageQueue.m_heap.m_pElements = v3;
  this->m_DelayedMessageQueue.m_heap.m_Size = 0;
  this->m_DelayedMessageQueue.m_LessFunc = PriorityQueueComp;
  v4 = *((_BYTE *)this + 56) & 0xF2;
  this->m_nReentrancyCount = 0;
  this->m_hContext = -1;
  this->m_DefaultContext.m_hInputContext = -1;
  *((_BYTE *)this + 56) = v4 | 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017010
// Name: public: virtual int CVGui::CreateContext(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVGui::CreateContext(CVGui *this)
{
  CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short> > *p_m_Contexts; // esi
  unsigned __int16 v2; // di
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *v5; // esi

  p_m_Contexts = &this->m_Contexts;
  v2 = CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_Contexts,
         multilist: false);
  v3 = -1;
  if ( v2 != 0xFFFF )
  {
    CUtlLinkedList<CVGui::Context_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CVGui::Context_t,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_Contexts,
      before: 0xFFFFu,
      elem: v2);
    v3 = v2;
  }
  v4 = v3;
  v5 = &p_m_Contexts->m_Memory.m_pMemory[v3];
  v5->m_Element.m_hInputContext = vgui::g_pInput->CreateInputContext(this: vgui::g_pInput);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10017060
// Name: public: virtual void CVGui::ActivateContext(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::ActivateContext(CVGui *this, int context)
{
  UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *p_m_DefaultContext; // eax

  if ( this->m_hContext != context )
  {
    if ( this->m_nReentrancyCount <= 0 )
      CVGui::DispatchMessages(this);
    this->m_hContext = context;
    if ( context == -1 )
      p_m_DefaultContext = (UtlLinkedListElem_t<CVGui::Context_t,unsigned short> *)&this->m_DefaultContext;
    else
      p_m_DefaultContext = &this->m_Contexts.m_Memory.m_pMemory[(unsigned __int16)context];
    vgui::g_pInput->ActivateInputContext(this: vgui::g_pInput, a2: p_m_DefaultContext->m_Element.m_hInputContext);
    if ( context != -1 && this->m_nReentrancyCount <= 0 )
      vgui::g_pInput->RunFrame(this: vgui::g_pInput);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100170D0
// Name: public: virtual void CVGui::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::RunFrame(CVGui *this)
{
  bool v2; // zf
  bool v3; // bl
  int v4; // eax
  int v5; // esi
  int v6; // ebx
  CVGui::Tick_t *v7; // eax
  int interval; // ecx
  int v9; // eax
  vgui::ISurface_vtbl *v10; // esi
  int v11; // eax
  int cursorX; // [esp+Ch] [ebp-Ch] BYREF
  int cursorY; // [esp+10h] [ebp-8h] BYREF
  bool bIsReentrant; // [esp+17h] [ebp-1h]

  v3 = (*((_BYTE *)this + 56) & 4) != 0;
  v2 = (*((_BYTE *)this + 56) & 4) == 0;
  bIsReentrant = v3;
  if ( !v2 )
    ++this->m_nReentrancyCount;
  vgui::g_pSurface->RunFrame(this: vgui::g_pSurface);
  vgui::g_pSystem->RunFrame(this: vgui::g_pSystem);
  if ( this->m_nReentrancyCount <= 0 )
  {
    vgui::g_pInput->GetCursorPosition(this: vgui::g_pInput, a2: &cursorX, a3: &cursorY);
    vgui::g_pInput->UpdateMouseFocus(this: vgui::g_pInput, a2: cursorX, a3: cursorY);
  }
  if ( !v3 )
  {
    vgui::g_pInput->RunFrame(this: vgui::g_pInput);
    CVGui::DispatchMessages(this);
    v4 = vgui::g_pSystem->GetTimeMillis(this: vgui::g_pSystem);
    v5 = this->m_TickSignalVec.m_Size - 1;
    v6 = v4;
    if ( v5 >= 0 )
    {
      while ( 1 )
      {
        v7 = this->m_TickSignalVec.m_Memory.m_pMemory[v5];
        interval = v7->interval;
        if ( interval == 0 )
          goto LABEL_10;
        if ( v6 >= v7->nexttick )
          break;
LABEL_11:
        if ( --v5 < 0 )
          goto LABEL_12;
      }
      v7->nexttick = v6 + interval;
LABEL_10:
      v9 = (int)v7->panel->Client(this: v7->panel);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 108))(a1: v9);
      goto LABEL_11;
    }
LABEL_12:
    v3 = bIsReentrant;
  }
  v10 = vgui::g_pSurface->__vftable;
  v11 = ((int (__thiscall *)(vgui::ISurface *, _DWORD))vgui::g_pSurface->GetEmbeddedPanel)(a1: vgui::g_pSurface, a2: 0);
  ((void (__thiscall *)(vgui::ISurface *, int))v10->SolveTraverse)(a1: vgui::g_pSurface, a2: v11);
  vgui::g_pSurface->ApplyChanges(this: vgui::g_pSurface);
  if ( v3 )
    --this->m_nReentrancyCount;
}

//------------------------------------------------------------------------------
// Address: 0x100171E0
// Name: public: virtual unsigned int CVGui::AllocPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall CVGui::AllocPanel(CVGui *this)
{
  vgui::VPanel *v2; // eax
  vgui::VPanel *v3; // esi

  v2 = (vgui::VPanel *)operator new(nSize: 0x58u);
  if ( v2 != nullptr )
  {
    v3 = vgui::VPanel::VPanel(this: v2);
    CVGui::PanelCreated(this, panel: v3);
    return v3;
  }
  else
  {
    CVGui::PanelCreated(this, panel: nullptr);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017220
// Name: private: void CVGui::PanelDeleted(class vgui::VPanel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::PanelDeleted(CVGui *this, vgui::VPanel *focus)
{
  CVGui *v2; // edi
  unsigned int v3; // eax
  int v4; // edx

  v2 = this;
  vgui::g_pSurface->ReleasePanel(this: vgui::g_pSurface, a2: (unsigned int)focus);
  vgui::g_pInput->PanelDeleted(this: vgui::g_pInput, a2: (unsigned int)focus);
  v3 = focus->GetHPanel(this: focus);
  if ( v3 != -1 && (v3 & 0xFFFFF) < v2->m_HandleTable.m_list.m_Size )
  {
    v4 = (int)v2->m_HandleTable.m_list.m_Memory.m_pMemory[v3 & 0xFFFFF];
    if ( (v4 & 0x7FFFFFFF) == v3 >> 20 && (v4 & 0x80000000) != 0x80000000 )
      CUtlHandleTable<vgui::VPanel,20>::RemoveHandle(this: &v2->m_HandleTable, handle: v3);
    v2 = this;
  }
  focus->SetHPanel(this: focus, a2: -1u);
  v2->RemoveTickSignal(this: v2, a2: (unsigned int)focus);
}

//------------------------------------------------------------------------------
// Address: 0x100172C0
// Name: public: virtual void CVGui::PostMessageA(unsigned int,class KeyValues __near *,unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::PostMessageA(
        CVGui *this,
        unsigned int target,
        KeyValues *params,
        unsigned int from,
        float delay)
{
  MessageItem_t messageItem; // [esp+4h] [ebp-14h] BYREF

  if ( this->m_nReentrancyCount <= 0 && target != 0 )
  {
    if ( target == -1 )
      messageItem._messageTo = -1;
    else
      messageItem._messageTo = vgui::g_pIVgui->PanelToHandle(this: vgui::g_pIVgui, a2: target);
    messageItem._params = params;
    messageItem._from = vgui::g_pIVgui->PanelToHandle(this: vgui::g_pIVgui, a2: from);
    messageItem._messageID = this->m_iCurrentMessageID;
    messageItem._arrivalTime = 0.0;
    this->m_iCurrentMessageID = messageItem._messageID + 1;
    if ( delay <= 0.0 )
    {
      if ( (*((_BYTE *)this + 56) & 4) != 0 )
        CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::AddToTail(
          this: &this->m_SecondaryQueue,
          src: &messageItem);
      else
        CUtlLinkedList<MessageItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<MessageItem_t,unsigned short>,unsigned short>>::AddToTail(
          this: &this->m_MessageQueue,
          src: &messageItem);
    }
    else
    {
      messageItem._arrivalTime = (float)vgui::g_pSystem->GetTimeMillis(this: vgui::g_pSystem) + (float)(delay * 1000.0);
      CUtlPriorityQueue<MessageItem_t,CDefUtlPriorityQueueLessFunc<MessageItem_t>,CUtlMemory<MessageItem_t,int>>::Insert(
        this: &this->m_DelayedMessageQueue,
        element: &messageItem);
    }
  }
  else if ( params != nullptr )
  {
    KeyValues::deleteThis(this: params);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100173C0
// Name: public: virtual void CVGui::FreePanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGui::FreePanel(CVGui *this, vgui::VPanel *ipanel)
{
  CVGui::PanelDeleted(this, focus: ipanel);
  if ( ipanel != nullptr )
    ((void (__thiscall *)(vgui::VPanel *, int))ipanel->dtr_VPanel)(a1: ipanel, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001E5E0
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<CWin32Font *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CWin32Font **m_pMemory; // edx
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
      this->m_pMemory = (CWin32Font **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CWin32Font **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E670
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
// Address: 0x10020170
// Name: public: void CUtlMemory<class CFontAmalgam,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFontAmalgam,int>::Grow(CUtlMemory<CFontAmalgam,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CFontAmalgam *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CFontAmalgam *)_g_pMemAlloc->Realloc_2(
                                          this: _g_pMemAlloc,
                                          a2: m_pMemory,
                                          a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (CFontAmalgam *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020220
// Name: public: void CUtlMemory<class CFontAmalgam,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFontAmalgam,int>::EnsureCapacity(CUtlMemory<CFontAmalgam,int> *this, int num)
{
  CFontAmalgam *m_pMemory; // edx

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CFontAmalgam *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 28 * num);
    else
      this->m_pMemory = (CFontAmalgam *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015280
// Name: __CreateCVGuiIVGui_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVGui *__cdecl _CreateCVGuiIVGui_interface()
{
  return &g_VGui;
}
