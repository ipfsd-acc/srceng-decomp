// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/datamanager.cpp
// Functions: 16
// ============================================================

#include "tier1\datamanager.h"

//------------------------------------------------------------------------------
// Address: 0x10277510
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102775A0
// Name: public: unsigned short CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_FirstFree; // ecx
  int m_MaxElementIndex; // ecx
  int result; // eax
  int v5; // ecx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v6; // esi

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_13:
    v5 = (unsigned __int16)result;
    this->m_Memory.m_pMemory[v5].m_Previous = result;
    this->m_Memory.m_pMemory[v5].m_Next = result;
    ++this->m_TotalElements;
    v6 = &this->m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      *(_DWORD *)&v6->m_Element.lockCount = 0x10000;
      v6->m_Element.pStore = nullptr;
    }
    return result;
  }
  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (unsigned __int16)m_MaxElementIndex != m_MaxElementIndex || (_WORD)m_MaxElementIndex == 0xFFFF )
  {
    if ( `CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`9'::__executeCount < 10 )
    {
      ++`CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`9'::__executeCount;
      _Warning(a1: "CUtlMultiList overflow! (exhausted index range)\n");
    }
    return 0xFFFF;
  }
  if ( m_MaxElementIndex != this->m_Memory.m_nAllocationCount
    || (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
          num: 1),
        this->m_pElements = this->m_Memory.m_pMemory,
        (m_MaxElementIndex = this->m_MaxElementIndex) < this->m_Memory.m_nAllocationCount) )
  {
    result = LOWORD(this->m_MaxElementIndex);
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
    goto LABEL_13;
  }
  if ( `CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`19'::__executeCount;
  _Warning(a1: "CUtlMultiList overflow! (exhausted memory allocator)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10277900
// Name: protected: struct memhandle_t__ __near * CDataManagerBase::StoreResourceInHandle(unsigned short,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataManagerBase::StoreResourceInHandle(
        CDataManagerBase *this,
        unsigned __int16 memoryIndex,
        void *pStore,
        unsigned int realSize)
{
  int v5; // eax
  int v6; // edi

  this->Lock(this);
  v5 = memoryIndex;
  this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.pStore = pStore;
  this->m_memUsed += realSize;
  v6 = this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.serial << 16;
  this->Unlock(this);
  return (memhandle_t__ *)(v6 | (unsigned __int16)(memoryIndex + 1));
}

//------------------------------------------------------------------------------
// Address: 0x10277950
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277A10
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x10277B60
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277BE0
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x10277BF0
// Name: protected: void __near * CDataManagerBase::LockResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::LockResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  _WORD *v7; // edx
  int v8; // edi
  memhandle_t__ *handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  v5 = (unsigned int)handle >> 16;
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (v6 = 12 * v4,
        v7 = (unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6),
        handlea = (memhandle_t__ *)v6,
        v7[4] == v3)
    && v7[5] != v3
    || v7[1] != (_WORD)v5
    || v3 == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( *v7 == 0 )
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        elem: v3);
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list: this->m_lockList,
        before: 0xFFFFu,
        elem: v3);
      v6 = (int)handlea;
    }
    ++*(unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6);
    v8 = *(int *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.pStore + v6);
    this->Unlock(this);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277CA0
// Name: public: int CDataManagerBase::UnlockResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::UnlockResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned int v3; // ecx
  int v4; // ebx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // edx
  int lockCount; // esi
  unsigned __int16 handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (unsigned int)handle >> 16;
  handlea = (_WORD)handle - 1;
  if ( handlea >= this->m_memoryLists.m_MaxElementIndex
    || (v4 = handlea, (v5 = &this->m_memoryLists.m_Memory.m_pMemory[v4])->m_Previous == handlea)
    && v5->m_Next != handlea
    || v5->m_Element.serial != (_WORD)v3
    || handlea == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( v5->m_Element.lockCount != 0 )
    {
      --this->m_memoryLists.m_Memory.m_pMemory[handlea].m_Element.lockCount;
      if ( this->m_memoryLists.m_Memory.m_pMemory[v4].m_Element.lockCount == 0 )
      {
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
          this: &this->m_memoryLists,
          list: this->m_lockList,
          elem: handlea);
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
          this: &this->m_memoryLists,
          list: this->m_lruList,
          before: 0xFFFFu,
          elem: handlea);
      }
    }
    lockCount = this->m_memoryLists.m_Memory.m_pMemory[handlea].m_Element.lockCount;
    this->Unlock(this);
    return lockCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277D60
// Name: public: int CDataManagerBase::BreakLock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::BreakLock(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  int v5; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v6; // edx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int lockCount; // ecx
  int nBroken; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 < this->m_memoryLists.m_MaxElementIndex
    && ((v5 = v4, (v6 = &this->m_memoryLists.m_Memory.m_pMemory[v5])->m_Previous != v3) || v6->m_Next == v3)
    && v6->m_Element.serial == HIWORD(handle)
    && (_WORD)handle != 0
    && v6->m_Element.lockCount != 0 )
  {
    v7 = &this->m_memoryLists.m_Memory.m_pMemory[v5];
    lockCount = v7->m_Element.lockCount;
    v7->m_Element.lockCount = 0;
    nBroken = lockCount;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lockList,
      elem: v3);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      before: 0xFFFFu,
      elem: v3);
    this->Unlock(this);
    return nBroken;
  }
  else
  {
    this->Unlock(this);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277E10
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_3 < 1 )
      {
        ++_executeCount_3;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10277EE0
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: &destroyList.m_Memory.m_pMemory[v8 + 1],
          src: &destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: &destroyList.m_Memory.m_pMemory[v14 + 1],
          src: &destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x10278100
// Name: public: void CDataManagerBase::DestroyResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::DestroyResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // cx
  int v4; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edi
  int v6; // eax
  bool v7; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax
  unsigned __int16 v9; // di
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v10; // eax
  void *v11; // edi

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (m_pMemory = this->m_memoryLists.m_Memory.m_pMemory,
        v6 = v4,
        v7 = m_pMemory[v6].m_Previous == v3,
        v8 = &m_pMemory[v6],
        v7)
    && v8->m_Next != v3
    || (v9 = (_WORD)handle - 1, v8->m_Element.serial != HIWORD(handle)) )
  {
    v9 = -1;
  }
  if ( v9 < this->m_memoryLists.m_MaxElementIndex
    && ((v10 = &this->m_memoryLists.m_Memory.m_pMemory[v9])->m_Previous != v9 || v10->m_Next == v9) )
  {
    if ( v10->m_Element.lockCount != 0 )
      CDataManagerBase::BreakLock(this, handle);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      elem: v9);
    v11 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v9);
    this->Unlock(this);
    this->DestroyResourceStorage(this, a2: v11);
  }
  else
  {
    this->Unlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102781C0
// Name: protected: unsigned short CDataManagerBase::CreateHandle(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDataManagerBase::CreateHandle(CDataManagerBase *this, bool bCreateLocked)
{
  int m_Head; // ebx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *p_m_memoryLists; // esi
  unsigned __int16 v5; // ax
  int v6; // ebx
  __int16 v7; // ax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax
  unsigned __int16 list; // [esp+Ch] [ebp-4h]

  this->Lock(this);
  m_Head = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_freeList].m_Element.m_Head;
  if ( bCreateLocked )
    list = this->m_lockList;
  else
    list = this->m_lruList;
  p_m_memoryLists = &this->m_memoryLists;
  if ( m_Head == 0xFFFF )
  {
    v5 = CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(this: &this->m_memoryLists);
    v6 = v5;
    if ( v5 == 0xFFFF )
    {
      v7 = -1;
    }
    else
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list,
        before: 0xFFFFu,
        elem: v5);
      v8 = &p_m_memoryLists->m_Memory.m_pMemory[v6];
      if ( v8 != nullptr )
      {
        *(_DWORD *)&v8->m_Element.lockCount = 0x10000;
        v8->m_Element.pStore = nullptr;
      }
      v7 = v6;
    }
    LOWORD(m_Head) = v7;
  }
  else
  {
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      elem: m_Head);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list,
      before: 0xFFFFu,
      elem: m_Head);
  }
  if ( bCreateLocked )
    ++p_m_memoryLists->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Element.lockCount;
  this->Unlock(this);
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x10278290
// Name: public: unsigned int CDataManagerBase::EnsureCapacity(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::EnsureCapacity(CDataManagerBase *this, unsigned int size)
{
  unsigned int m_memUsed; // ecx
  unsigned int m_targetMemorySize; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  int m_Head; // edi
  void *v7; // edi
  unsigned int nBytesInitial; // [esp+Ch] [ebp-4h]

  nBytesInitial = this->m_memUsed;
  while ( 1 )
  {
    m_memUsed = this->m_memUsed;
    m_targetMemorySize = this->m_targetMemorySize;
    if ( m_memUsed <= m_targetMemorySize && m_targetMemorySize - m_memUsed >= size )
      break;
    this->Lock(this);
    m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
    m_Head = m_pMemory[this->m_lruList].m_Element.m_Head;
    if ( m_Head == 0xFFFF )
    {
      this->Unlock(this);
      return nBytesInitial - this->m_memUsed;
    }
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      elem: m_pMemory[this->m_lruList].m_Element.m_Head);
    v7 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
    this->Unlock(this);
    this->DestroyResourceStorage(this, a2: v7);
  }
  return nBytesInitial - this->m_memUsed;
}

//------------------------------------------------------------------------------
// Address: 0x10278320
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x004157B0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415860
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // eax
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    m_Head = this->m_List.m_Head;
    this->m_FirstFree = 0;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415900
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // edx
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
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415970
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebx
  int m_nAllocationCount; // ecx
  unsigned __int16 result; // ax
  int v7; // edi
  CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Iterator_t *v8; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Iterator_t v11; // [esp+Eh] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_21:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result;
    if ( multilist )
    {
      m_pMemory[v10].m_Next = -1;
      this->m_Memory.m_pMemory[v10].m_Previous = -1;
    }
    else
    {
      m_pMemory[v10].m_Next = result;
      this->m_Memory.m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  p_m_LastAlloc = &this->m_LastAlloc;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
  {
    result = -1;
  }
  else
  {
    result = p_m_LastAlloc->index + 1;
  }
  v11.index = result;
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( p_m_LastAlloc->index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      v11.index = (v7 > 0) - 1;
      v8 = &v11;
    }
    else
    {
      v8 = CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>::Next(
             this: &this->m_Memory,
             result: &v11,
             it: &this->m_LastAlloc);
    }
    result = v8->index;
    if ( result >= v7 )
    {
      if ( _executeCount_0 < 10 )
      {
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
        ++_executeCount_0;
      }
      return -1;
    }
  }
  if ( result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    p_m_LastAlloc->index = result;
    goto LABEL_21;
  }
  if ( _executeCount < 10 )
  {
    _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
    ++_executeCount;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00415AF0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // eax
  unsigned __int16 m_Next; // dx
  unsigned __int16 m_Previous; // bx

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFFFF )
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
// Address: 0x00415B80
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v3; // eax
  unsigned __int16 m_Next; // bp
  unsigned __int16 m_Previous; // si
  unsigned __int16 v6; // si
  unsigned __int16 v7; // bp
  unsigned __int16 *m_pElementList; // ecx

  if ( elem < this->m_MaxElementIndex )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Next = v3->m_Next;
      m_Previous = v3->m_Previous;
      if ( m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v6 = v3->m_Next;
      v7 = v3->m_Previous;
      if ( v6 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v7;
      else
        this->m_Memory.m_pMemory[v6].m_Previous = v7;
      v3->m_Next = elem;
      v3->m_Previous = elem;
      --this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elem] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415C40
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  unsigned __int16 m_Previous; // ax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x00415CF0
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *p_m_List; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  p_m_List = &this->m_List;
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_List->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_List->m_Memory.m_pMemory);
      p_m_List->m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415D70
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x00415D80
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // ebp

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        _Warning(a1: "Data manager 'used' memory incorrect\n");
        ++_executeCount_1;
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return pStore;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415E10
// Name: public: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 v2; // ax
  unsigned __int16 v3; // di
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v5; // eax
  unsigned __int16 m_Tail; // dx

  v2 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this,
         multilist: false);
  v3 = v2;
  if ( v2 == 0xFFFF )
    return 0xFFFF;
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem: v2);
  v5 = &this->m_Memory.m_pMemory[v3];
  v5->m_Next = -1;
  m_Tail = this->m_Tail;
  v5->m_Previous = m_Tail;
  this->m_Tail = v3;
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = v3;
  }
  else
  {
    this->m_Memory.m_pMemory[m_Tail].m_Next = v3;
    ++this->m_ElementCount;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00415EC0
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // dx
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca(4 * nFlush);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<KeyValues *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        memmove(
          dst: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<KeyValues *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        memmove(
          dst: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x004160F0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *p_m_List; // ebx
  unsigned __int16 v5; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v6; // edx
  unsigned __int16 v7; // cx
  int v8; // eax
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *v9; // ebx
  unsigned __int16 v10; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v11; // edx
  unsigned __int16 v12; // cx
  int v13; // eax
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *v14; // ebx
  unsigned __int16 v15; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v16; // edx
  unsigned __int16 v17; // cx
  int v18; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_Tail = -1;
  this->m_memoryLists.m_List.m_FirstFree = -1;
  this->m_memoryLists.m_List.m_ElementCount = 0;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  this->m_memoryLists.m_List.m_pElements = m_pMemory;
  this->m_memoryLists.m_pElements = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  this->m_memoryLists.m_FirstFree = -1;
  this->m_memoryLists.m_TotalElements = 0;
  this->m_memoryLists.m_MaxElementIndex = 0;
  p_m_List = &this->m_memoryLists.m_List;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v5 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AddToTail(this: &this->m_memoryLists.m_List);
  v6 = p_m_List->m_Memory.m_pMemory;
  v7 = v5;
  v8 = v5;
  v6[v8].m_Element.m_Tail = -1;
  p_m_List->m_Memory.m_pMemory[v8].m_Element.m_Head = v6[v8].m_Element.m_Tail;
  p_m_List->m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
  this->m_lruList = v7;
  v9 = &this->m_memoryLists.m_List;
  v10 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AddToTail(this: &this->m_memoryLists.m_List);
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v12 = v10;
  v13 = v10;
  v11[v13].m_Element.m_Tail = -1;
  v9->m_Memory.m_pMemory[v13].m_Element.m_Head = v11[v13].m_Element.m_Tail;
  v9->m_Memory.m_pMemory[v13].m_Element.m_Count = 0;
  this->m_lockList = v12;
  v14 = &this->m_memoryLists.m_List;
  v15 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AddToTail(this: &this->m_memoryLists.m_List);
  v16 = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v17 = v15;
  v18 = v15;
  v16[v18].m_Element.m_Tail = -1;
  v14->m_Memory.m_pMemory[v18].m_Element.m_Head = v16[v18].m_Element.m_Tail;
  v14->m_Memory.m_pMemory[v18].m_Element.m_Count = 0;
  *((_WORD *)this + 37) &= ~1u;
  this->m_freeList = v17;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004180F0
// Name: public: virtual bool CDataManagerBase::TryLock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataManagerBase::TryLock(CP4File_Dummy *this)
{
  return 1;
}

} // namespace choreogen

// ============================================================
// Overlay from datacache (Missing functions)
// ============================================================
namespace datacache {

//------------------------------------------------------------------------------
// Address: 0x10005650
// Name: public: virtual void CDataManagerBase::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDataManagerBase::Unlock()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10016F40
// Name: public: void CDataManagerBase::NotifySizeChanged(struct memhandle_t__ __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::NotifySizeChanged(
        CDataManagerBase *this,
        memhandle_t__ *handle,
        unsigned int oldSize,
        unsigned int newSize)
{
  CDataManagerBase_vtbl *v5; // edx

  this->Lock(this);
  v5 = this->__vftable;
  this->m_memUsed += newSize - oldSize;
  v5->Unlock(this);
}

//------------------------------------------------------------------------------
// Address: 0x10016F70
// Name: public: void CDataManagerBase::SetTargetSize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::SetTargetSize(CDataManagerBase *this, unsigned int targetSize)
{
  this->m_targetMemorySize = targetSize;
}

//------------------------------------------------------------------------------
// Address: 0x10016F80
// Name: public: unsigned int CDataManagerBase::TargetSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::TargetSize(CDataManagerBase *this)
{
  return this->m_targetMemorySize;
}

//------------------------------------------------------------------------------
// Address: 0x10016F90
// Name: public: unsigned int CDataManagerBase::UsedSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::UsedSize(CDataManagerBase *this)
{
  return this->m_memUsed;
}

//------------------------------------------------------------------------------
// Address: 0x10017040
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100170F0
// Name: protected: void __near * CDataManagerBase::GetResource_NoLockNoLRUTouch(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetResource_NoLockNoLRUTouch(CDataManagerBase *this, memhandle_t__ *handle)
{
  __int16 v3; // cx
  int v4; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edi
  int v6; // eax
  void *pStore; // edi

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 < this->m_memoryLists.m_MaxElementIndex
    && ((m_pMemory = this->m_memoryLists.m_Memory.m_pMemory, v6 = v4, m_pMemory[v6].m_Previous != v3)
     || m_pMemory[v6].m_Next == v3)
    && m_pMemory[v6].m_Element.serial == HIWORD(handle)
    && (_WORD)handle != 0 )
  {
    pStore = m_pMemory[v6].m_Element.pStore;
    this->Unlock(this);
    return pStore;
  }
  else
  {
    this->Unlock(this);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017160
// Name: protected: struct memhandle_t__ __near * CDataManagerBase::ToHandle(unsigned short)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataManagerBase::ToHandle(CDataManagerBase *this, unsigned __int16 index)
{
  return (memhandle_t__ *)((unsigned __int16)(index + 1)
                         | (this->m_memoryLists.m_Memory.m_pMemory[index].m_Element.serial << 16));
}

//------------------------------------------------------------------------------
// Address: 0x10017190
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017220
// Name: public: unsigned short CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_FirstFree; // ecx
  int m_MaxElementIndex; // ecx
  int result; // eax
  int v5; // ecx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v6; // esi

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_13:
    v5 = (unsigned __int16)result;
    this->m_Memory.m_pMemory[v5].m_Previous = result;
    this->m_Memory.m_pMemory[v5].m_Next = result;
    ++this->m_TotalElements;
    v6 = &this->m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      *(_DWORD *)&v6->m_Element.lockCount = 0x10000;
      v6->m_Element.pStore = nullptr;
    }
    return result;
  }
  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (unsigned __int16)m_MaxElementIndex != m_MaxElementIndex || (_WORD)m_MaxElementIndex == 0xFFFF )
  {
    if ( `CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`9'::__executeCount < 10 )
    {
      ++`CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`9'::__executeCount;
      _Warning(a1: "CUtlMultiList overflow! (exhausted index range)\n");
    }
    return 0xFFFF;
  }
  if ( m_MaxElementIndex != this->m_Memory.m_nAllocationCount
    || (CUtlMemory<CModelSwapper::ModelSubstitution_t,int>::Grow(this: &this->m_Memory, num: 1),
        this->m_pElements = this->m_Memory.m_pMemory,
        (m_MaxElementIndex = this->m_MaxElementIndex) < this->m_Memory.m_nAllocationCount) )
  {
    result = LOWORD(this->m_MaxElementIndex);
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
    goto LABEL_13;
  }
  if ( `CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`19'::__executeCount;
  _Warning(a1: "CUtlMultiList overflow! (exhausted memory allocator)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10017580
// Name: protected: struct memhandle_t__ __near * CDataManagerBase::StoreResourceInHandle(unsigned short,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataManagerBase::StoreResourceInHandle(
        CDataManagerBase *this,
        unsigned __int16 memoryIndex,
        void *pStore,
        unsigned int realSize)
{
  int v5; // eax
  int v6; // edi

  this->Lock(this);
  v5 = memoryIndex;
  this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.pStore = pStore;
  this->m_memUsed += realSize;
  v6 = this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.serial << 16;
  this->Unlock(this);
  return (memhandle_t__ *)(v6 | (unsigned __int16)(memoryIndex + 1));
}

//------------------------------------------------------------------------------
// Address: 0x100175D0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017690
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x10017750
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkAfter(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkAfter(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Next; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Previous = after;
  if ( after == 0xFFFF )
  {
    v6 = list;
    v5->m_Next = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Head;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Head = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[after];
    v5->m_Next = v7->m_Next;
    v7->m_Next = elem;
  }
  m_Next = v5->m_Next;
  if ( (_WORD)m_Next == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = elem;
  else
    this->m_Memory.m_pMemory[m_Next].m_Previous = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x100178A0
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017920
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x10017940
// Name: protected: void __near * CDataManagerBase::LockResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::LockResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  _WORD *v7; // edx
  int v8; // edi
  memhandle_t__ *handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  v5 = (unsigned int)handle >> 16;
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (v6 = 12 * v4,
        v7 = (unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6),
        handlea = (memhandle_t__ *)v6,
        v7[4] == v3)
    && v7[5] != v3
    || v7[1] != (_WORD)v5
    || v3 == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( *v7 == 0 )
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        elem: v3);
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list: this->m_lockList,
        before: 0xFFFFu,
        elem: v3);
      v6 = (int)handlea;
    }
    ++*(unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6);
    v8 = *(int *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.pStore + v6);
    this->Unlock(this);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100179F0
// Name: protected: void __near * CDataManagerBase::LockResourceReturnCount(int __near *,struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::LockResourceReturnCount(CDataManagerBase *this, int *pCount, memhandle_t__ *handle)
{
  unsigned __int16 v4; // bx
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // eax
  _WORD *v8; // edx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // ecx
  int v10; // edi
  memhandle_t__ *handlea; // [esp+18h] [ebp+Ch]

  this->Lock(this);
  v4 = (_WORD)handle - 1;
  v5 = (unsigned __int16)((_WORD)handle - 1);
  v6 = (unsigned int)handle >> 16;
  if ( v5 >= this->m_memoryLists.m_MaxElementIndex
    || (v7 = 12 * v5,
        v8 = (unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v7),
        handlea = (memhandle_t__ *)v7,
        v8[4] == v4)
    && v8[5] != v4
    || v8[1] != (_WORD)v6
    || v4 == 0xFFFF )
  {
    *pCount = 0;
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( *v8 == 0 )
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        elem: v4);
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list: this->m_lockList,
        before: 0xFFFFu,
        elem: v4);
      v7 = (int)handlea;
    }
    m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
    *pCount = ++*(unsigned __int16 *)((char *)&m_pMemory->m_Element.lockCount + v7);
    v10 = *(int *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.pStore + v7);
    this->Unlock(this);
    return v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017AB0
// Name: public: int CDataManagerBase::UnlockResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::UnlockResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned int v3; // ecx
  int v4; // ebx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // edx
  int lockCount; // esi
  unsigned __int16 handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (unsigned int)handle >> 16;
  handlea = (_WORD)handle - 1;
  if ( handlea >= this->m_memoryLists.m_MaxElementIndex
    || (v4 = handlea, (v5 = &this->m_memoryLists.m_Memory.m_pMemory[v4])->m_Previous == handlea)
    && v5->m_Next != handlea
    || v5->m_Element.serial != (_WORD)v3
    || handlea == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( v5->m_Element.lockCount != 0 )
    {
      --this->m_memoryLists.m_Memory.m_pMemory[handlea].m_Element.lockCount;
      if ( this->m_memoryLists.m_Memory.m_pMemory[v4].m_Element.lockCount == 0 )
      {
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
          this: &this->m_memoryLists,
          list: this->m_lockList,
          elem: handlea);
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
          this: &this->m_memoryLists,
          list: this->m_lruList,
          before: 0xFFFFu,
          elem: handlea);
      }
    }
    lockCount = this->m_memoryLists.m_Memory.m_pMemory[handlea].m_Element.lockCount;
    this->Unlock(this);
    return lockCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017B70
// Name: public: void CDataManagerBase::MarkAsStale(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::MarkAsStale(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // di
  int v4; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  int v6; // eax
  bool v7; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 < this->m_memoryLists.m_MaxElementIndex )
  {
    m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
    v6 = v4;
    v7 = m_pMemory[v6].m_Previous == v3;
    v8 = &m_pMemory[v6];
    if ( (!v7 || v8->m_Next == v3)
      && v8->m_Element.serial == HIWORD(handle)
      && (_WORD)handle != 0
      && v8->m_Element.lockCount == 0 )
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        elem: (_WORD)handle - 1);
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkAfter(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        after: 0xFFFFu,
        elem: v3);
    }
  }
  this->Unlock(this);
}

//------------------------------------------------------------------------------
// Address: 0x10017BF0
// Name: public: int CDataManagerBase::BreakLock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::BreakLock(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  int v5; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v6; // edx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int lockCount; // ecx
  int nBroken; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 < this->m_memoryLists.m_MaxElementIndex
    && ((v5 = v4, (v6 = &this->m_memoryLists.m_Memory.m_pMemory[v5])->m_Previous != v3) || v6->m_Next == v3)
    && v6->m_Element.serial == HIWORD(handle)
    && (_WORD)handle != 0
    && v6->m_Element.lockCount != 0 )
  {
    v7 = &this->m_memoryLists.m_Memory.m_pMemory[v5];
    lockCount = v7->m_Element.lockCount;
    v7->m_Element.lockCount = 0;
    nBroken = lockCount;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lockList,
      elem: v3);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      before: 0xFFFFu,
      elem: v3);
    this->Unlock(this);
    return nBroken;
  }
  else
  {
    this->Unlock(this);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017CA0
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017D70
// Name: public: unsigned int CDataManagerBase::FlushAllUnlocked(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAllUnlocked(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // ecx
  int m_Count; // ebx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v4; // edi
  void *v5; // esp
  int m_Head; // edi
  unsigned int m_memUsed; // edx
  int m_Size; // ebx
  int v9; // edi
  void **v10; // ecx
  void **v11; // edi
  int v12; // ebx
  int i; // edi
  unsigned int result; // eax
  unsigned int v15; // esi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  _BYTE v17[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  unsigned int nBytesInitial; // [esp+20h] [ebp-10h]
  int nFlush; // [esp+24h] [ebp-Ch]
  int next; // [esp+28h] [ebp-8h]
  void *v22; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  m_Count = m_pMemory[this->m_lruList].m_Element.m_Count;
  v4 = &m_pMemory[this->m_lruList];
  nFlush = m_Count;
  v5 = alloca((4 * m_Count + 15) & 0xFFFF0);
  m_Head = v4->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = m_Count;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v17;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v17;
  nBytesInitial = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      next = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      v22 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v9 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<unsigned long,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v10 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v9 - 1 > 0 )
      {
        _V_memmove(
          dest: &destroyList.m_Memory.m_pMemory[v9 + 1],
          src: &destroyList.m_Memory.m_pMemory[v9],
          count: 4 * (m_Size - v9 - 1));
        v10 = destroyList.m_Memory.m_pMemory;
      }
      v11 = &v10[v9];
      if ( v11 != nullptr )
        *v11 = v22;
      LOWORD(m_Head) = next;
    }
    while ( next != 0xFFFF );
  }
  this->Unlock(this);
  v12 = nFlush;
  for ( i = 0; i < v12; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  result = nBytesInitial - this->m_memUsed;
  v15 = result;
  if ( destroyList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( destroyList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
    return v15;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017EC0
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<unsigned long,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: &destroyList.m_Memory.m_pMemory[v8 + 1],
          src: &destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<unsigned long,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: &destroyList.m_Memory.m_pMemory[v14 + 1],
          src: &destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x100180E0
// Name: public: void CDataManagerBase::DestroyResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::DestroyResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // cx
  int v4; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edi
  int v6; // eax
  bool v7; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax
  unsigned __int16 v9; // di
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v10; // eax
  void *v11; // edi

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (m_pMemory = this->m_memoryLists.m_Memory.m_pMemory,
        v6 = v4,
        v7 = m_pMemory[v6].m_Previous == v3,
        v8 = &m_pMemory[v6],
        v7)
    && v8->m_Next != v3
    || (v9 = (_WORD)handle - 1, v8->m_Element.serial != HIWORD(handle)) )
  {
    v9 = -1;
  }
  if ( v9 < this->m_memoryLists.m_MaxElementIndex
    && ((v10 = &this->m_memoryLists.m_Memory.m_pMemory[v9])->m_Previous != v9 || v10->m_Next == v9) )
  {
    if ( v10->m_Element.lockCount != 0 )
      CDataManagerBase::BreakLock(this, handle);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      elem: v9);
    v11 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v9);
    this->Unlock(this);
    this->DestroyResourceStorage(this, a2: v11);
  }
  else
  {
    this->Unlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100181A0
// Name: protected: void __near * CDataManagerBase::GetResource_NoLock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::GetResource_NoLock(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  _WORD *v7; // edx
  int v8; // edi
  memhandle_t__ *handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  v5 = (unsigned int)handle >> 16;
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (v6 = 12 * v4,
        v7 = (unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6),
        handlea = (memhandle_t__ *)v6,
        v7[4] == v3)
    && v7[5] != v3
    || v7[1] != (_WORD)v5
    || v3 == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( *v7 == 0 )
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        elem: v3);
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        before: 0xFFFFu,
        elem: v3);
      v6 = (int)handlea;
    }
    v8 = *(int *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.pStore + v6);
    this->Unlock(this);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018250
// Name: public: void CDataManagerBase::TouchResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::TouchResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // di
  int v4; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  int v6; // eax
  bool v7; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 < this->m_memoryLists.m_MaxElementIndex )
  {
    m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
    v6 = v4;
    v7 = m_pMemory[v6].m_Previous == v3;
    v8 = &m_pMemory[v6];
    if ( (!v7 || v8->m_Next == v3)
      && v8->m_Element.serial == HIWORD(handle)
      && (_WORD)handle != 0
      && v8->m_Element.lockCount == 0 )
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        elem: (_WORD)handle - 1);
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        before: 0xFFFFu,
        elem: v3);
    }
  }
  this->Unlock(this);
}

//------------------------------------------------------------------------------
// Address: 0x100182D0
// Name: protected: unsigned short CDataManagerBase::CreateHandle(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDataManagerBase::CreateHandle(CDataManagerBase *this, bool bCreateLocked)
{
  int m_Head; // ebx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *p_m_memoryLists; // esi
  unsigned __int16 v5; // ax
  int v6; // ebx
  __int16 v7; // ax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax
  unsigned __int16 list; // [esp+Ch] [ebp-4h]

  this->Lock(this);
  m_Head = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_freeList].m_Element.m_Head;
  if ( bCreateLocked )
    list = this->m_lockList;
  else
    list = this->m_lruList;
  p_m_memoryLists = &this->m_memoryLists;
  if ( m_Head == 0xFFFF )
  {
    v5 = CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(this: &this->m_memoryLists);
    v6 = v5;
    if ( v5 == 0xFFFF )
    {
      v7 = -1;
    }
    else
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list,
        before: 0xFFFFu,
        elem: v5);
      v8 = &p_m_memoryLists->m_Memory.m_pMemory[v6];
      if ( v8 != nullptr )
      {
        *(_DWORD *)&v8->m_Element.lockCount = 0x10000;
        v8->m_Element.pStore = nullptr;
      }
      v7 = v6;
    }
    LOWORD(m_Head) = v7;
  }
  else
  {
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      elem: m_Head);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list,
      before: 0xFFFFu,
      elem: m_Head);
  }
  if ( bCreateLocked )
    ++p_m_memoryLists->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Element.lockCount;
  this->Unlock(this);
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x100183A0
// Name: public: unsigned int CDataManagerBase::EnsureCapacity(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::EnsureCapacity(CDataManagerBase *this, unsigned int size)
{
  unsigned int m_memUsed; // ecx
  unsigned int m_targetMemorySize; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  int m_Head; // edi
  void *v7; // edi
  unsigned int nBytesInitial; // [esp+Ch] [ebp-4h]

  nBytesInitial = this->m_memUsed;
  while ( 1 )
  {
    m_memUsed = this->m_memUsed;
    m_targetMemorySize = this->m_targetMemorySize;
    if ( m_memUsed <= m_targetMemorySize && m_targetMemorySize - m_memUsed >= size )
      break;
    this->Lock(this);
    m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
    m_Head = m_pMemory[this->m_lruList].m_Element.m_Head;
    if ( m_Head == 0xFFFF )
    {
      this->Unlock(this);
      return nBytesInitial - this->m_memUsed;
    }
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      elem: m_pMemory[this->m_lruList].m_Element.m_Head);
    v7 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
    this->Unlock(this);
    this->DestroyResourceStorage(this, a2: v7);
  }
  return nBytesInitial - this->m_memUsed;
}

//------------------------------------------------------------------------------
// Address: 0x10018430
// Name: public: void CDataManagerBase::GetLRUHandleList(class CUtlVector<struct memhandle_t__ __near *,class CUtlMemory<struct memhandle_t__ __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::GetLRUHandleList(
        CDataManagerBase *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list)
{
  int m_Tail; // edx
  int m_pMemory; // edi
  int v5; // ebx
  int v6; // edx
  int m_nAllocationCount; // eax
  memhandle_t__ **v8; // ecx
  int v9; // eax
  memhandle_t__ **v10; // edi
  CDataManagerBase *i; // [esp+0h] [ebp-4h]
  CUtlVector<memhandle_t__ *,CUtlMemory<memhandle_t__ *,int> > *lista; // [esp+Ch] [ebp+8h]

  m_Tail = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lruList].m_Element.m_Tail;
  for ( i = this; m_Tail != 0xFFFF; m_Tail = i->m_memoryLists.m_Memory.m_pMemory[v5].m_Previous )
  {
    m_pMemory = (int)list[1].m_pMemory;
    v5 = (unsigned __int16)m_Tail;
    v6 = (this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.serial << 16) | (unsigned __int16)(m_Tail + 1);
    m_nAllocationCount = list->m_nAllocationCount;
    lista = (CUtlVector<memhandle_t__ *,CUtlMemory<memhandle_t__ *,int> > *)v6;
    if ( m_pMemory + 1 > m_nAllocationCount )
    {
      CUtlMemory<unsigned long,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
      v6 = (int)lista;
    }
    ++list[1].m_pMemory;
    v8 = (memhandle_t__ **)list->m_pMemory;
    v9 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v9 > 0 )
    {
      _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
      v6 = (int)lista;
    }
    this = i;
    v10 = (memhandle_t__ **)&list->m_pMemory[m_pMemory];
    if ( v10 != nullptr )
      *v10 = (memhandle_t__ *)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100184F0
// Name: public: void CDataManagerBase::GetLockHandleList(class CUtlVector<struct memhandle_t__ __near *,class CUtlMemory<struct memhandle_t__ __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::GetLockHandleList(
        CDataManagerBase *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list)
{
  int m_Head; // edx
  int m_pMemory; // edi
  int v5; // ebx
  int v6; // edx
  int m_nAllocationCount; // eax
  memhandle_t__ **v8; // ecx
  int v9; // eax
  memhandle_t__ **v10; // edi
  CDataManagerBase *i; // [esp+0h] [ebp-4h]
  CUtlVector<memhandle_t__ *,CUtlMemory<memhandle_t__ *,int> > *lista; // [esp+Ch] [ebp+8h]

  m_Head = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  for ( i = this; m_Head != 0xFFFF; m_Head = i->m_memoryLists.m_Memory.m_pMemory[v5].m_Next )
  {
    m_pMemory = (int)list[1].m_pMemory;
    v5 = (unsigned __int16)m_Head;
    v6 = (this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.serial << 16) | (unsigned __int16)(m_Head + 1);
    m_nAllocationCount = list->m_nAllocationCount;
    lista = (CUtlVector<memhandle_t__ *,CUtlMemory<memhandle_t__ *,int> > *)v6;
    if ( m_pMemory + 1 > m_nAllocationCount )
    {
      CUtlMemory<unsigned long,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
      v6 = (int)lista;
    }
    ++list[1].m_pMemory;
    v8 = (memhandle_t__ **)list->m_pMemory;
    v9 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v9 > 0 )
    {
      _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
      v6 = (int)lista;
    }
    this = i;
    v10 = (memhandle_t__ **)&list->m_pMemory[m_pMemory];
    if ( v10 != nullptr )
      *v10 = (memhandle_t__ *)v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100185B0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10018730
// Name: public: unsigned int CDataManagerBase::FlushToTargetSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushToTargetSize(CDataManagerBase *this)
{
  return CDataManagerBase::EnsureCapacity(this, size: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10018740
// Name: public: unsigned int CDataManagerBase::Purge(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::Purge(CDataManagerBase *this, unsigned int nBytesToPurge)
{
  unsigned int m_memUsed; // edx
  int v3; // eax

  m_memUsed = this->m_memUsed;
  v3 = m_memUsed - nBytesToPurge;
  if ( nBytesToPurge > m_memUsed )
    v3 = 0;
  return CDataManagerBase::EnsureCapacity(this, size: this->m_targetMemorySize - v3);
}

} // namespace datacache

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x005A8630
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A86E0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A89F0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A8AB0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x005A8C00
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A8C80
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x005A8C90
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A8D60
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x005A8F80
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005A90F6
// Name: __getextendedkeycode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const NormKeyVals *__cdecl _getextendedkeycode(_KEY_EVENT_RECORD *pKE)
{
  unsigned int dwControlKeyState; // ebx
  const NormKeyVals *result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  int v5; // ecx
  int wVirtualScanCode; // eax

  dwControlKeyState = pKE->dwControlKeyState;
  if ( (dwControlKeyState & 0x100) != 0 )
  {
    result = nullptr;
    v3 = 0;
    v4 = 0;
    while ( EnhancedKeys[v4].ScanCode != pKE->wVirtualScanCode )
    {
      ++v4;
      ++v3;
      if ( v4 >= 12 )
        return result;
    }
    v5 = v3;
    if ( (dwControlKeyState & 3) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].AltChars;
    if ( (dwControlKeyState & 0xC) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].CtrlChars;
    if ( (dwControlKeyState & 0x10) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].ShiftChars;
    return (const NormKeyVals *)&EnhancedKeys[v5].RegChars;
  }
  else
  {
    wVirtualScanCode = pKE->wVirtualScanCode;
    if ( (dwControlKeyState & 3) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].AltChars;
    }
    else if ( (dwControlKeyState & 0xC) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].CtrlChars;
    }
    else if ( (dwControlKeyState & 0x10) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].ShiftChars;
    }
    else
    {
      result = &NormalKeys[wVirtualScanCode];
    }
    if ( result->RegChars.LeadChar != 0 && result->RegChars.LeadChar != 0xE0 || result->RegChars.SecondChar == 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A91A9
// Name: __getch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getch_nolock()
{
  int result; // eax
  int AsciiChar; // edi
  const NormKeyVals *v2; // eax
  unsigned int oldstate; // [esp+4h] [ebp-20h] BYREF
  unsigned int NumRead; // [esp+8h] [ebp-1Ch] BYREF
  _INPUT_RECORD ConInpRec; // [esp+Ch] [ebp-18h] BYREF

  if ( chbuf == -1 )
  {
    if ( _coninpfh == (HANDLE)-2 )
      __initconin();
    if ( _coninpfh == (HANDLE)-1 )
    {
      return -1;
    }
    else
    {
      GetConsoleMode(hConsoleHandle: _coninpfh, lpMode: &oldstate);
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: 0);
      while ( 1 )
      {
        if ( !ReadConsoleInputA(
                hConsoleInput: _coninpfh,
                lpBuffer: &ConInpRec,
                nLength: 1u,
                lpNumberOfEventsRead: &NumRead)
          || NumRead == 0 )
        {
          AsciiChar = -1;
          goto LABEL_15;
        }
        if ( ConInpRec.EventType == 1 && ConInpRec.Event.KeyEvent.bKeyDown != 0 )
        {
          AsciiChar = (unsigned __int8)ConInpRec.Event.KeyEvent.uChar.AsciiChar;
          if ( ConInpRec.Event.KeyEvent.uChar.AsciiChar != 0 )
            goto LABEL_15;
          v2 = _getextendedkeycode(pKE: &ConInpRec.Event.KeyEvent);
          if ( v2 != nullptr )
            break;
        }
      }
      AsciiChar = v2->RegChars.LeadChar;
      chbuf = v2->RegChars.SecondChar;
LABEL_15:
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: oldstate);
      return AsciiChar;
    }
  }
  else
  {
    result = (unsigned __int8)chbuf;
    chbuf = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9282
// Name: _getch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl getch()
{
  int v1; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 3);
  v1 = _getch_nolock();
  _unlock(locknum: 3);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x005A92C0
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005A943E
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9472
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A94CF
// Name: ___initconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconin()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONIN$",
             dwDesiredAccess: 0xC0000000,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _coninpfh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A94EE
// Name: ___termconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconin()
{
  HANDLE result; // eax

  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9BD0
// Name: _dynamic_initializer_for__LuaFunc_s::m_dmxEdit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LuaFunc_s::m_dmxEdit__()
{
  CDmxEdit::CDmxEdit(this: &LuaFunc_s::m_dmxEdit);
  return atexit(func: dynamic_atexit_destructor_for__LuaFunc_s::m_dmxEdit__);
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00678F20
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00678FD0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006792E0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006793A0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x006794F0
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00679570
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x00679580
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00679650
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x00679870
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10277640
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102776D0
// Name: public: unsigned short CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_FirstFree; // ecx
  int m_MaxElementIndex; // ecx
  int result; // eax
  int v5; // ecx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v6; // esi

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_13:
    v5 = (unsigned __int16)result;
    this->m_Memory.m_pMemory[v5].m_Previous = result;
    this->m_Memory.m_pMemory[v5].m_Next = result;
    ++this->m_TotalElements;
    v6 = &this->m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      *(_DWORD *)&v6->m_Element.lockCount = 0x10000;
      v6->m_Element.pStore = nullptr;
    }
    return result;
  }
  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (unsigned __int16)m_MaxElementIndex != m_MaxElementIndex || (_WORD)m_MaxElementIndex == 0xFFFF )
  {
    if ( `CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`9'::__executeCount < 10 )
    {
      ++`CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`9'::__executeCount;
      _Warning(a1: "CUtlMultiList overflow! (exhausted index range)\n");
    }
    return 0xFFFF;
  }
  if ( m_MaxElementIndex != this->m_Memory.m_nAllocationCount
    || (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
          num: 1),
        this->m_pElements = this->m_Memory.m_pMemory,
        (m_MaxElementIndex = this->m_MaxElementIndex) < this->m_Memory.m_nAllocationCount) )
  {
    result = LOWORD(this->m_MaxElementIndex);
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
    goto LABEL_13;
  }
  if ( `CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`19'::__executeCount;
  _Warning(a1: "CUtlMultiList overflow! (exhausted memory allocator)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10277A30
// Name: protected: struct memhandle_t__ __near * CDataManagerBase::StoreResourceInHandle(unsigned short,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataManagerBase::StoreResourceInHandle(
        CDataManagerBase *this,
        unsigned __int16 memoryIndex,
        void *pStore,
        unsigned int realSize)
{
  int v5; // eax
  int v6; // edi

  this->Lock(this);
  v5 = memoryIndex;
  this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.pStore = pStore;
  this->m_memUsed += realSize;
  v6 = this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.serial << 16;
  this->Unlock(this);
  return (memhandle_t__ *)(v6 | (unsigned __int16)(memoryIndex + 1));
}

//------------------------------------------------------------------------------
// Address: 0x10277A80
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277B40
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x10277C90
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277D10
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x10277D20
// Name: protected: void __near * CDataManagerBase::LockResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::LockResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  _WORD *v7; // edx
  int v8; // edi
  memhandle_t__ *handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  v5 = (unsigned int)handle >> 16;
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (v6 = 12 * v4,
        v7 = (unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6),
        handlea = (memhandle_t__ *)v6,
        v7[4] == v3)
    && v7[5] != v3
    || v7[1] != (_WORD)v5
    || v3 == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( *v7 == 0 )
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        elem: v3);
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list: this->m_lockList,
        before: 0xFFFFu,
        elem: v3);
      v6 = (int)handlea;
    }
    ++*(unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6);
    v8 = *(int *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.pStore + v6);
    this->Unlock(this);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277DD0
// Name: public: int CDataManagerBase::UnlockResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::UnlockResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned int v3; // ecx
  int v4; // ebx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // edx
  int lockCount; // esi
  unsigned __int16 handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (unsigned int)handle >> 16;
  handlea = (_WORD)handle - 1;
  if ( handlea >= this->m_memoryLists.m_MaxElementIndex
    || (v4 = handlea, (v5 = &this->m_memoryLists.m_Memory.m_pMemory[v4])->m_Previous == handlea)
    && v5->m_Next != handlea
    || v5->m_Element.serial != (_WORD)v3
    || handlea == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( v5->m_Element.lockCount != 0 )
    {
      --this->m_memoryLists.m_Memory.m_pMemory[handlea].m_Element.lockCount;
      if ( this->m_memoryLists.m_Memory.m_pMemory[v4].m_Element.lockCount == 0 )
      {
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
          this: &this->m_memoryLists,
          list: this->m_lockList,
          elem: handlea);
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
          this: &this->m_memoryLists,
          list: this->m_lruList,
          before: 0xFFFFu,
          elem: handlea);
      }
    }
    lockCount = this->m_memoryLists.m_Memory.m_pMemory[handlea].m_Element.lockCount;
    this->Unlock(this);
    return lockCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277E90
// Name: public: int CDataManagerBase::BreakLock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::BreakLock(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  int v5; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v6; // edx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int lockCount; // ecx
  int nBroken; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 < this->m_memoryLists.m_MaxElementIndex
    && ((v5 = v4, (v6 = &this->m_memoryLists.m_Memory.m_pMemory[v5])->m_Previous != v3) || v6->m_Next == v3)
    && v6->m_Element.serial == HIWORD(handle)
    && (_WORD)handle != 0
    && v6->m_Element.lockCount != 0 )
  {
    v7 = &this->m_memoryLists.m_Memory.m_pMemory[v5];
    lockCount = v7->m_Element.lockCount;
    v7->m_Element.lockCount = 0;
    nBroken = lockCount;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lockList,
      elem: v3);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      before: 0xFFFFu,
      elem: v3);
    this->Unlock(this);
    return nBroken;
  }
  else
  {
    this->Unlock(this);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277F40
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_3 < 1 )
      {
        ++_executeCount_3;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10278010
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: &destroyList.m_Memory.m_pMemory[v8 + 1],
          src: &destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: &destroyList.m_Memory.m_pMemory[v14 + 1],
          src: &destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x10278230
// Name: public: void CDataManagerBase::DestroyResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::DestroyResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // cx
  int v4; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edi
  int v6; // eax
  bool v7; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax
  unsigned __int16 v9; // di
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v10; // eax
  void *v11; // edi

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (m_pMemory = this->m_memoryLists.m_Memory.m_pMemory,
        v6 = v4,
        v7 = m_pMemory[v6].m_Previous == v3,
        v8 = &m_pMemory[v6],
        v7)
    && v8->m_Next != v3
    || (v9 = (_WORD)handle - 1, v8->m_Element.serial != HIWORD(handle)) )
  {
    v9 = -1;
  }
  if ( v9 < this->m_memoryLists.m_MaxElementIndex
    && ((v10 = &this->m_memoryLists.m_Memory.m_pMemory[v9])->m_Previous != v9 || v10->m_Next == v9) )
  {
    if ( v10->m_Element.lockCount != 0 )
      CDataManagerBase::BreakLock(this, handle);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      elem: v9);
    v11 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v9);
    this->Unlock(this);
    this->DestroyResourceStorage(this, a2: v11);
  }
  else
  {
    this->Unlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102782F0
// Name: protected: unsigned short CDataManagerBase::CreateHandle(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDataManagerBase::CreateHandle(CDataManagerBase *this, bool bCreateLocked)
{
  int m_Head; // ebx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *p_m_memoryLists; // esi
  unsigned __int16 v5; // ax
  int v6; // ebx
  __int16 v7; // ax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax
  unsigned __int16 list; // [esp+Ch] [ebp-4h]

  this->Lock(this);
  m_Head = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_freeList].m_Element.m_Head;
  if ( bCreateLocked )
    list = this->m_lockList;
  else
    list = this->m_lruList;
  p_m_memoryLists = &this->m_memoryLists;
  if ( m_Head == 0xFFFF )
  {
    v5 = CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(this: &this->m_memoryLists);
    v6 = v5;
    if ( v5 == 0xFFFF )
    {
      v7 = -1;
    }
    else
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list,
        before: 0xFFFFu,
        elem: v5);
      v8 = &p_m_memoryLists->m_Memory.m_pMemory[v6];
      if ( v8 != nullptr )
      {
        *(_DWORD *)&v8->m_Element.lockCount = 0x10000;
        v8->m_Element.pStore = nullptr;
      }
      v7 = v6;
    }
    LOWORD(m_Head) = v7;
  }
  else
  {
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      elem: m_Head);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list,
      before: 0xFFFFu,
      elem: m_Head);
  }
  if ( bCreateLocked )
    ++p_m_memoryLists->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Element.lockCount;
  this->Unlock(this);
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x102783C0
// Name: public: unsigned int CDataManagerBase::EnsureCapacity(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::EnsureCapacity(CDataManagerBase *this, unsigned int size)
{
  unsigned int m_memUsed; // ecx
  unsigned int m_targetMemorySize; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  int m_Head; // edi
  void *v7; // edi
  unsigned int nBytesInitial; // [esp+Ch] [ebp-4h]

  nBytesInitial = this->m_memUsed;
  while ( 1 )
  {
    m_memUsed = this->m_memUsed;
    m_targetMemorySize = this->m_targetMemorySize;
    if ( m_memUsed <= m_targetMemorySize && m_targetMemorySize - m_memUsed >= size )
      break;
    this->Lock(this);
    m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
    m_Head = m_pMemory[this->m_lruList].m_Element.m_Head;
    if ( m_Head == 0xFFFF )
    {
      this->Unlock(this);
      return nBytesInitial - this->m_memUsed;
    }
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      elem: m_pMemory[this->m_lruList].m_Element.m_Head);
    v7 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
    this->Unlock(this);
    this->DestroyResourceStorage(this, a2: v7);
  }
  return nBytesInitial - this->m_memUsed;
}

//------------------------------------------------------------------------------
// Address: 0x10278450
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004CC060
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CC110
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CC420
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CC4E0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x004CC630
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CC6B0
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x004CC6C0
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CC790
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x004CC9B0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B3ED0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3F80
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B4290
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B4350
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x102B44A0
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B4520
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x102B4530
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_4 < 1 )
      {
        ++_executeCount_4;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B4600
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x102B4820
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00577B80
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577C30
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577F40
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00578000
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x00578150
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005781D0
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x005781F0
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005782C0
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x005784E0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C5250
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C5300
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C5610
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C56D0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x005C5820
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C58A0
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x005C58B0
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C5980
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x005C5BA0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace mdlcompile

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004B4FE0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5090
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B53A0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5460
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x004B55B0
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5630
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x004B5650
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B5720
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<unsigned long,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<unsigned long,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x004B5940
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00567130
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005671E0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005674F0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005675B0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x00567700
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00567780
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x00567790
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00567860
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x00567A80
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x005779B0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577A60
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577D70
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577E30
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x00577F80
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00578010
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005780E0
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x00578300
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00578476
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005785F4
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00578628
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00578690
// Name: _ceil
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x005786D0
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns_0, (__m128i)_mm_and_pd(v2, *(__m128d *)&S_0));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      a1.m128i_i64[0] = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One_0;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One_0);
      return *(double *)a1.m128i_i64;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005787AD
// Name: __ceil_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _ceil_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v1 = _ctrlfp();
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp();
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xCu, x, savedcw: v1);
    }
    return _except1(a1: (int)&savedregs, flags: 8, opcode: 12, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp();
      return v4;
    }
    else
    {
      return _except1(a1: (int)&savedregs, flags: 16, opcode: 12, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00578890
// Name: _dynamic_initializer_for__g_CDmElementPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *dynamic_initializer_for__g_CDmElementPullInModule__()
{
  g_CDmElementPullInModule = g_CDmElementLinkerHack;
  return g_CDmElementLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005788A0
// Name: _dynamic_initializer_for__g_CDmeTransformPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransform *dynamic_initializer_for__g_CDmeTransformPullInModule__()
{
  g_CDmeTransformPullInModule = g_CDmeTransformLinkerHack;
  return g_CDmeTransformLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005788B0
// Name: _dynamic_initializer_for__g_CDmeTransformListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformList *dynamic_initializer_for__g_CDmeTransformListPullInModule__()
{
  g_CDmeTransformListPullInModule = g_CDmeTransformListLinkerHack;
  return g_CDmeTransformListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005788C0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDataBase *dynamic_initializer_for__g_CDmeVertexDataBasePullInModule__()
{
  g_CDmeVertexDataBasePullInModule = g_CDmeVertexDataBaseLinkerHack;
  return g_CDmeVertexDataBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005788D0
// Name: _dynamic_initializer_for__g_CDmeVertexDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexData *dynamic_initializer_for__g_CDmeVertexDataPullInModule__()
{
  g_CDmeVertexDataPullInModule = g_CDmeVertexDataLinkerHack;
  return g_CDmeVertexDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005788E0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDeltaData *dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__()
{
  g_CDmeVertexDeltaDataPullInModule = g_CDmeVertexDeltaDataLinkerHack;
  return g_CDmeVertexDeltaDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005788F0
// Name: _dynamic_initializer_for__g_CDmeShapePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeShape *dynamic_initializer_for__g_CDmeShapePullInModule__()
{
  g_CDmeShapePullInModule = g_CDmeShapeLinkerHack;
  return g_CDmeShapeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578900
// Name: _dynamic_initializer_for__g_CDmeMeshPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMesh *dynamic_initializer_for__g_CDmeMeshPullInModule__()
{
  g_CDmeMeshPullInModule = g_CDmeMeshLinkerHack;
  return g_CDmeMeshLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578910
// Name: _dynamic_initializer_for__g_CDmeDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *dynamic_initializer_for__g_CDmeDagPullInModule__()
{
  g_CDmeDagPullInModule = g_CDmeDagLinkerHack;
  return g_CDmeDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578920
// Name: _dynamic_initializer_for__g_CDmeFaceSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFaceSet *dynamic_initializer_for__g_CDmeFaceSetPullInModule__()
{
  g_CDmeFaceSetPullInModule = g_CDmeFaceSetLinkerHack;
  return g_CDmeFaceSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578930
// Name: _dynamic_initializer_for__g_CDmeModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeModel *dynamic_initializer_for__g_CDmeModelPullInModule__()
{
  g_CDmeModelPullInModule = g_CDmeModelLinkerHack;
  return g_CDmeModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578940
// Name: _dynamic_initializer_for__g_CDmeJointPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJoint *dynamic_initializer_for__g_CDmeJointPullInModule__()
{
  g_CDmeJointPullInModule = g_CDmeJointLinkerHack;
  return g_CDmeJointLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578950
// Name: _dynamic_initializer_for__g_CDmeAttachmentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAttachment *dynamic_initializer_for__g_CDmeAttachmentPullInModule__()
{
  g_CDmeAttachmentPullInModule = g_CDmeAttachmentLinkerHack;
  return g_CDmeAttachmentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578960
// Name: _dynamic_initializer_for__g_CDmeMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMakefile *dynamic_initializer_for__g_CDmeMakefilePullInModule__()
{
  g_CDmeMakefilePullInModule = g_CDmeMakefileLinkerHack;
  return g_CDmeMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578970
// Name: _dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDLMakefile *dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__()
{
  g_CDmeMDLMakefilePullInModule = g_CDmeMDLMakefileLinkerHack;
  return g_CDmeMDLMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578980
// Name: _dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDCCMakefile *dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__()
{
  g_CDmeDCCMakefilePullInModule = g_CDmeDCCMakefileLinkerHack;
  return g_CDmeDCCMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578990
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaAnimationMakefile *dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__()
{
  g_CDmeMayaAnimationMakefilePullInModule = g_CDmeMayaAnimationMakefileLinkerHack;
  return g_CDmeMayaAnimationMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005789A0
// Name: _dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaCombinationOperator *dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__()
{
  g_CDmeMayaCombinationOperatorPullInModule = g_CDmeMayaCombinationOperatorLinkerHack;
  return g_CDmeMayaCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005789B0
// Name: _dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaMakefile *dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__()
{
  g_CDmeMayaMakefilePullInModule = g_CDmeMayaMakefileLinkerHack;
  return g_CDmeMayaMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005789C0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaModelMakefile *dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__()
{
  g_CDmeMayaModelMakefilePullInModule = g_CDmeMayaModelMakefileLinkerHack;
  return g_CDmeMayaModelMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005789D0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeXSIMakefile *dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__()
{
  g_CDmeXSIMakefilePullInModule = g_CDmeXSIMakefileLinkerHack;
  return g_CDmeXSIMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005789E0
// Name: _dynamic_initializer_for__g_CDmeSourcePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSource *dynamic_initializer_for__g_CDmeSourcePullInModule__()
{
  g_CDmeSourcePullInModule = g_CDmeSourceLinkerHack;
  return g_CDmeSourceLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005789F0
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceDCCFile *dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__()
{
  g_CDmeSourceDCCFilePullInModule = g_CDmeSourceDCCFileLinkerHack;
  return g_CDmeSourceDCCFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578A00
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaFile *dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__()
{
  g_CDmeSourceMayaFilePullInModule = g_CDmeSourceMayaFileLinkerHack;
  return g_CDmeSourceMayaFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578A10
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaModelFile *dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__()
{
  g_CDmeSourceMayaModelFilePullInModule = g_CDmeSourceMayaModelFileLinkerHack;
  return g_CDmeSourceMayaModelFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578A20
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaAnimationFile *dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__()
{
  g_CDmeSourceMayaAnimationFilePullInModule = g_CDmeSourceMayaAnimationFileLinkerHack;
  return g_CDmeSourceMayaAnimationFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578A30
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceXSIFile *dynamic_initializer_for__g_CDmeSourceXSIFilePullInModule__()
{
  g_CDmeSourceXSIFilePullInModule = g_CDmeSourceXSIFileLinkerHack;
  return g_CDmeSourceXSIFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578A40
// Name: _dynamic_initializer_for__g_CDmeAnimationListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationList *dynamic_initializer_for__g_CDmeAnimationListPullInModule__()
{
  g_CDmeAnimationListPullInModule = g_CDmeAnimationListLinkerHack;
  return g_CDmeAnimationListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578A50
// Name: _dynamic_initializer_for__g_CDmeClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *dynamic_initializer_for__g_CDmeClipPullInModule__()
{
  g_CDmeClipPullInModule = g_CDmeClipLinkerHack;
  return g_CDmeClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578A60
// Name: _dynamic_initializer_for__g_CDmeChannelsClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannelsClip *dynamic_initializer_for__g_CDmeChannelsClipPullInModule__()
{
  g_CDmeChannelsClipPullInModule = g_CDmeChannelsClipLinkerHack;
  return g_CDmeChannelsClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578A70
// Name: _dynamic_initializer_for__g_CDmeChannelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannel *dynamic_initializer_for__g_CDmeChannelPullInModule__()
{
  g_CDmeChannelPullInModule = g_CDmeChannelLinkerHack;
  return g_CDmeChannelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578A80
// Name: _dynamic_initializer_for__g_CDmeTimeFramePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeFrame *dynamic_initializer_for__g_CDmeTimeFramePullInModule__()
{
  g_CDmeTimeFramePullInModule = g_CDmeTimeFrameLinkerHack;
  return g_CDmeTimeFrameLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578A90
// Name: _dynamic_initializer_for__g_CDmeTrackGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrackGroup *dynamic_initializer_for__g_CDmeTrackGroupPullInModule__()
{
  g_CDmeTrackGroupPullInModule = g_CDmeTrackGroupLinkerHack;
  return g_CDmeTrackGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578AA0
// Name: _dynamic_initializer_for__g_CDmeTrackPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrack *dynamic_initializer_for__g_CDmeTrackPullInModule__()
{
  g_CDmeTrackPullInModule = g_CDmeTrackLinkerHack;
  return g_CDmeTrackLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578AB0
// Name: _dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationDominationRule *dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__()
{
  g_CDmeCombinationDominationRulePullInModule = g_CDmeCombinationDominationRuleLinkerHack;
  return g_CDmeCombinationDominationRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578AC0
// Name: _dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationInputControl *dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__()
{
  g_CDmeCombinationInputControlPullInModule = g_CDmeCombinationInputControlLinkerHack;
  return g_CDmeCombinationInputControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578AD0
// Name: _dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationOperator *dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__()
{
  g_CDmeCombinationOperatorPullInModule = g_CDmeCombinationOperatorLinkerHack;
  return g_CDmeCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578AE0
// Name: _dynamic_initializer_for__g_CDmeIntLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<int> *dynamic_initializer_for__g_CDmeIntLogPullInModule__()
{
  g_CDmeIntLogPullInModule = g_CDmeIntLogLinkerHack;
  return g_CDmeIntLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578AF0
// Name: _dynamic_initializer_for__g_CDmeFloatLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<float> *dynamic_initializer_for__g_CDmeFloatLogPullInModule__()
{
  g_CDmeFloatLogPullInModule = g_CDmeFloatLogLinkerHack;
  return g_CDmeFloatLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578B00
// Name: _dynamic_initializer_for__g_CDmeBoolLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<bool> *dynamic_initializer_for__g_CDmeBoolLogPullInModule__()
{
  g_CDmeBoolLogPullInModule = g_CDmeBoolLogLinkerHack;
  return g_CDmeBoolLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578B10
// Name: _dynamic_initializer_for__g_CDmeColorLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Color> *dynamic_initializer_for__g_CDmeColorLogPullInModule__()
{
  g_CDmeColorLogPullInModule = g_CDmeColorLogLinkerHack;
  return g_CDmeColorLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578B20
// Name: _dynamic_initializer_for__g_CDmeVector2LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogPullInModule__()
{
  g_CDmeVector2LogPullInModule = g_CDmeVector2LogLinkerHack;
  return g_CDmeVector2LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578B30
// Name: _dynamic_initializer_for__g_CDmeVector3LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector> *dynamic_initializer_for__g_CDmeVector3LogPullInModule__()
{
  g_CDmeVector3LogPullInModule = g_CDmeVector3LogLinkerHack;
  return g_CDmeVector3LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578B40
// Name: _dynamic_initializer_for__g_CDmeVector4LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogPullInModule__()
{
  g_CDmeVector4LogPullInModule = g_CDmeVector4LogLinkerHack;
  return g_CDmeVector4LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578B50
// Name: _dynamic_initializer_for__g_CDmeQAngleLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogPullInModule__()
{
  g_CDmeQAngleLogPullInModule = g_CDmeQAngleLogLinkerHack;
  return g_CDmeQAngleLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578B60
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__()
{
  g_CDmeQuaternionLogPullInModule = g_CDmeQuaternionLogLinkerHack;
  return g_CDmeQuaternionLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578B70
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__()
{
  g_CDmeVMatrixLogPullInModule = g_CDmeVMatrixLogLinkerHack;
  return g_CDmeVMatrixLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578B80
// Name: _dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<int> *dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__()
{
  g_CDmeIntLogLayerPullInModule = g_CDmeIntLogLayerLinkerHack;
  return g_CDmeIntLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578B90
// Name: _dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<float> *dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__()
{
  g_CDmeFloatLogLayerPullInModule = g_CDmeFloatLogLayerLinkerHack;
  return g_CDmeFloatLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578BA0
// Name: _dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<bool> *dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__()
{
  g_CDmeBoolLogLayerPullInModule = g_CDmeBoolLogLayerLinkerHack;
  return g_CDmeBoolLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578BB0
// Name: _dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Color> *dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__()
{
  g_CDmeColorLogLayerPullInModule = g_CDmeColorLogLayerLinkerHack;
  return g_CDmeColorLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578BC0
// Name: _dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__()
{
  g_CDmeVector2LogLayerPullInModule = g_CDmeVector2LogLayerLinkerHack;
  return g_CDmeVector2LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578BD0
// Name: _dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector> *dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__()
{
  g_CDmeVector3LogLayerPullInModule = g_CDmeVector3LogLayerLinkerHack;
  return g_CDmeVector3LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578BE0
// Name: _dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__()
{
  g_CDmeVector4LogLayerPullInModule = g_CDmeVector4LogLayerLinkerHack;
  return g_CDmeVector4LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578BF0
// Name: _dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__()
{
  g_CDmeQAngleLogLayerPullInModule = g_CDmeQAngleLogLayerLinkerHack;
  return g_CDmeQAngleLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578C00
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__()
{
  g_CDmeQuaternionLogLayerPullInModule = g_CDmeQuaternionLogLayerLinkerHack;
  return g_CDmeQuaternionLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578C10
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__()
{
  g_CDmeVMatrixLogLayerPullInModule = g_CDmeVMatrixLogLayerLinkerHack;
  return g_CDmeVMatrixLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578C20
// Name: _dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<int> *dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__()
{
  g_CDmeIntCurveInfoPullInModule = g_CDmeIntCurveInfoLinkerHack;
  return g_CDmeIntCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578C30
// Name: _dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<float> *dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__()
{
  g_CDmeFloatCurveInfoPullInModule = g_CDmeFloatCurveInfoLinkerHack;
  return g_CDmeFloatCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578C40
// Name: _dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<bool> *dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__()
{
  g_CDmeBoolCurveInfoPullInModule = g_CDmeBoolCurveInfoLinkerHack;
  return g_CDmeBoolCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578C50
// Name: _dynamic_initializer_for__g_CDmeColorCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Color> *dynamic_initializer_for__g_CDmeColorCurveInfoPullInModule__()
{
  g_CDmeColorCurveInfoPullInModule = g_CDmeColorCurveInfoLinkerHack;
  return g_CDmeColorCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578C60
// Name: _dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector2D> *dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__()
{
  g_CDmeVector2CurveInfoPullInModule = g_CDmeVector2CurveInfoLinkerHack;
  return g_CDmeVector2CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578C70
// Name: _dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector> *dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__()
{
  g_CDmeVector3CurveInfoPullInModule = g_CDmeVector3CurveInfoLinkerHack;
  return g_CDmeVector3CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578C80
// Name: _dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector4D> *dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__()
{
  g_CDmeVector4CurveInfoPullInModule = g_CDmeVector4CurveInfoLinkerHack;
  return g_CDmeVector4CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578C90
// Name: _dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<QAngle> *dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__()
{
  g_CDmeQAngleCurveInfoPullInModule = g_CDmeQAngleCurveInfoLinkerHack;
  return g_CDmeQAngleCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578CA0
// Name: _dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__()
{
  g_CDmeQuaternionCurveInfoPullInModule = g_CDmeQuaternionCurveInfoLinkerHack;
  return g_CDmeQuaternionCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578CB0
// Name: _dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__()
{
  g_CDmeVMatrixCurveInfoPullInModule = g_CDmeVMatrixCurveInfoLinkerHack;
  return g_CDmeVMatrixCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578CC0
// Name: _dynamic_initializer_for__g_CDmeComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeComponent *dynamic_initializer_for__g_CDmeComponentPullInModule__()
{
  g_CDmeComponentPullInModule = g_CDmeComponentLinkerHack;
  return g_CDmeComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578CD0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSingleIndexedComponent *dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__()
{
  g_CDmeSingleIndexedComponentPullInModule = g_CDmeSingleIndexedComponentLinkerHack;
  return g_CDmeSingleIndexedComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578CE0
// Name: _dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDrawSettings *dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__()
{
  g_CDmeDrawSettingsPullInModule = g_CDmeDrawSettingsLinkerHack;
  return g_CDmeDrawSettingsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578CF0
// Name: _dynamic_initializer_for__g_CDmeCameraPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCamera *dynamic_initializer_for__g_CDmeCameraPullInModule__()
{
  g_CDmeCameraPullInModule = g_CDmeCameraLinkerHack;
  return g_CDmeCameraLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578D00
// Name: _dynamic_initializer_for__g_CDmeSoundClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSoundClip *dynamic_initializer_for__g_CDmeSoundClipPullInModule__()
{
  g_CDmeSoundClipPullInModule = g_CDmeSoundClipLinkerHack;
  return g_CDmeSoundClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578D10
// Name: _dynamic_initializer_for__g_CDmeFilmClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFilmClip *dynamic_initializer_for__g_CDmeFilmClipPullInModule__()
{
  g_CDmeFilmClipPullInModule = g_CDmeFilmClipLinkerHack;
  return g_CDmeFilmClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578D20
// Name: _dynamic_initializer_for__g_CDmeMDLPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDL *dynamic_initializer_for__g_CDmeMDLPullInModule__()
{
  g_CDmeMDLPullInModule = g_CDmeMDLLinkerHack;
  return g_CDmeMDLLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578D30
// Name: _dynamic_initializer_for__g_CDmeMaterialPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMaterial *dynamic_initializer_for__g_CDmeMaterialPullInModule__()
{
  g_CDmeMaterialPullInModule = g_CDmeMaterialLinkerHack;
  return g_CDmeMaterialLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578D40
// Name: _dynamic_initializer_for__g_CDmeLightPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeLight *dynamic_initializer_for__g_CDmeLightPullInModule__()
{
  g_CDmeLightPullInModule = g_CDmeLightLinkerHack;
  return g_CDmeLightLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578D50
// Name: _dynamic_initializer_for__g_CDmeGameModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGameModel *dynamic_initializer_for__g_CDmeGameModelPullInModule__()
{
  g_CDmeGameModelPullInModule = g_CDmeGameModelLinkerHack;
  return g_CDmeGameModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578D60
// Name: _dynamic_initializer_for__g_CDmeSoundPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSound *dynamic_initializer_for__g_CDmeSoundPullInModule__()
{
  g_CDmeSoundPullInModule = g_CDmeSoundLinkerHack;
  return g_CDmeSoundLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578D70
// Name: _dynamic_initializer_for__g_CDmeGameSoundPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGameSound *dynamic_initializer_for__g_CDmeGameSoundPullInModule__()
{
  g_CDmeGameSoundPullInModule = g_CDmeGameSoundLinkerHack;
  return g_CDmeGameSoundLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578D80
// Name: _dynamic_initializer_for__g_CDmeMorphOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMorphOperator *dynamic_initializer_for__g_CDmeMorphOperatorPullInModule__()
{
  g_CDmeMorphOperatorPullInModule = g_CDmeMorphOperatorLinkerHack;
  return g_CDmeMorphOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578D90
// Name: _dynamic_initializer_for__g_CDmeTransformOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformOperator *dynamic_initializer_for__g_CDmeTransformOperatorPullInModule__()
{
  g_CDmeTransformOperatorPullInModule = g_CDmeTransformOperatorLinkerHack;
  return g_CDmeTransformOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578DA0
// Name: _dynamic_initializer_for__g_CDmeExpressionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeExpressionOperator *dynamic_initializer_for__g_CDmeExpressionOperatorPullInModule__()
{
  g_CDmeExpressionOperatorPullInModule = g_CDmeExpressionOperatorLinkerHack;
  return g_CDmeExpressionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578DB0
// Name: _dynamic_initializer_for__g_CDmeConnectionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConnectionOperator *dynamic_initializer_for__g_CDmeConnectionOperatorPullInModule__()
{
  g_CDmeConnectionOperatorPullInModule = g_CDmeConnectionOperatorLinkerHack;
  return g_CDmeConnectionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578DC0
// Name: _dynamic_initializer_for__g_CDmeGamePortalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGamePortal *dynamic_initializer_for__g_CDmeGamePortalPullInModule__()
{
  g_CDmeGamePortalPullInModule = g_CDmeGamePortalLinkerHack;
  return g_CDmeGamePortalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578DD0
// Name: _dynamic_initializer_for__g_CDmeMouseInputPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMouseInput *dynamic_initializer_for__g_CDmeMouseInputPullInModule__()
{
  g_CDmeMouseInputPullInModule = g_CDmeMouseInputLinkerHack;
  return g_CDmeMouseInputLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578DE0
// Name: _dynamic_initializer_for__g_CDmeKeyboardInputPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeKeyboardInput *dynamic_initializer_for__g_CDmeKeyboardInputPullInModule__()
{
  g_CDmeKeyboardInputPullInModule = g_CDmeKeyboardInputLinkerHack;
  return g_CDmeKeyboardInputLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578DF0
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *dynamic_initializer_for__g_CDmeEditorAttributeInfoPullInModule__()
{
  g_CDmeEditorAttributeInfoPullInModule = g_CDmeEditorAttributeInfoLinkerHack;
  return g_CDmeEditorAttributeInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578E00
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *dynamic_initializer_for__g_CDmeEditorChoicesInfoPullInModule__()
{
  g_CDmeEditorChoicesInfoPullInModule = g_CDmeEditorChoicesInfoLinkerHack;
  return g_CDmeEditorChoicesInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578E10
// Name: _dynamic_initializer_for__g_CDmeEditorTypePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorType *dynamic_initializer_for__g_CDmeEditorTypePullInModule__()
{
  g_CDmeEditorTypePullInModule = g_CDmeEditorTypeLinkerHack;
  return g_CDmeEditorTypeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578E20
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionaryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorTypeDictionary *dynamic_initializer_for__g_CDmeEditorTypeDictionaryPullInModule__()
{
  g_CDmeEditorTypeDictionaryPullInModule = g_CDmeEditorTypeDictionaryLinkerHack;
  return g_CDmeEditorTypeDictionaryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578E30
// Name: _dynamic_initializer_for__g_CDmePackColorOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackColorOperator *dynamic_initializer_for__g_CDmePackColorOperatorPullInModule__()
{
  g_CDmePackColorOperatorPullInModule = g_CDmePackColorOperatorLinkerHack;
  return g_CDmePackColorOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578E40
// Name: _dynamic_initializer_for__g_CDmePackVector2OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector2Operator *dynamic_initializer_for__g_CDmePackVector2OperatorPullInModule__()
{
  g_CDmePackVector2OperatorPullInModule = g_CDmePackVector2OperatorLinkerHack;
  return g_CDmePackVector2OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578E50
// Name: _dynamic_initializer_for__g_CDmePackVector3OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector3Operator *dynamic_initializer_for__g_CDmePackVector3OperatorPullInModule__()
{
  g_CDmePackVector3OperatorPullInModule = g_CDmePackVector3OperatorLinkerHack;
  return g_CDmePackVector3OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578E60
// Name: _dynamic_initializer_for__g_CDmePackVector4OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector4Operator *dynamic_initializer_for__g_CDmePackVector4OperatorPullInModule__()
{
  g_CDmePackVector4OperatorPullInModule = g_CDmePackVector4OperatorLinkerHack;
  return g_CDmePackVector4OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578E70
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackQAngleOperator *dynamic_initializer_for__g_CDmePackQAngleOperatorPullInModule__()
{
  g_CDmePackQAngleOperatorPullInModule = g_CDmePackQAngleOperatorLinkerHack;
  return g_CDmePackQAngleOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578E80
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackQuaternionOperator *dynamic_initializer_for__g_CDmePackQuaternionOperatorPullInModule__()
{
  g_CDmePackQuaternionOperatorPullInModule = g_CDmePackQuaternionOperatorLinkerHack;
  return g_CDmePackQuaternionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578E90
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *dynamic_initializer_for__g_CDmePackVMatrixOperatorPullInModule__()
{
  g_CDmePackVMatrixOperatorPullInModule = g_CDmePackVMatrixOperatorLinkerHack;
  return g_CDmePackVMatrixOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578EA0
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackColorOperator *dynamic_initializer_for__g_CDmeUnpackColorOperatorPullInModule__()
{
  g_CDmeUnpackColorOperatorPullInModule = g_CDmeUnpackColorOperatorLinkerHack;
  return g_CDmeUnpackColorOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578EB0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector2Operator *dynamic_initializer_for__g_CDmeUnpackVector2OperatorPullInModule__()
{
  g_CDmeUnpackVector2OperatorPullInModule = g_CDmeUnpackVector2OperatorLinkerHack;
  return g_CDmeUnpackVector2OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578EC0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector3Operator *dynamic_initializer_for__g_CDmeUnpackVector3OperatorPullInModule__()
{
  g_CDmeUnpackVector3OperatorPullInModule = g_CDmeUnpackVector3OperatorLinkerHack;
  return g_CDmeUnpackVector3OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578ED0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector4Operator *dynamic_initializer_for__g_CDmeUnpackVector4OperatorPullInModule__()
{
  g_CDmeUnpackVector4OperatorPullInModule = g_CDmeUnpackVector4OperatorLinkerHack;
  return g_CDmeUnpackVector4OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578EE0
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackQAngleOperator *dynamic_initializer_for__g_CDmeUnpackQAngleOperatorPullInModule__()
{
  g_CDmeUnpackQAngleOperatorPullInModule = g_CDmeUnpackQAngleOperatorLinkerHack;
  return g_CDmeUnpackQAngleOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578EF0
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackQuaternionOperator *dynamic_initializer_for__g_CDmeUnpackQuaternionOperatorPullInModule__()
{
  g_CDmeUnpackQuaternionOperatorPullInModule = g_CDmeUnpackQuaternionOperatorLinkerHack;
  return g_CDmeUnpackQuaternionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578F00
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *dynamic_initializer_for__g_CDmeUnpackVMatrixOperatorPullInModule__()
{
  g_CDmeUnpackVMatrixOperatorPullInModule = g_CDmeUnpackVMatrixOperatorLinkerHack;
  return g_CDmeUnpackVMatrixOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578F10
// Name: _dynamic_initializer_for__g_CDmeAnimationSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationSet *dynamic_initializer_for__g_CDmeAnimationSetPullInModule__()
{
  g_CDmeAnimationSetPullInModule = g_CDmeAnimationSetLinkerHack;
  return g_CDmeAnimationSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578F20
// Name: _dynamic_initializer_for__g_CDmePhonemeMappingPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePhonemeMapping *dynamic_initializer_for__g_CDmePhonemeMappingPullInModule__()
{
  g_CDmePhonemeMappingPullInModule = g_CDmePhonemeMappingLinkerHack;
  return g_CDmePhonemeMappingLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578F30
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGlobalFlexControllerOperator *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperatorPullInModule__()
{
  g_CDmeGlobalFlexControllerOperatorPullInModule = g_CDmeGlobalFlexControllerOperatorLinkerHack;
  return g_CDmeGlobalFlexControllerOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578F40
// Name: _dynamic_initializer_for__g_CDmeTransformControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformControl *dynamic_initializer_for__g_CDmeTransformControlPullInModule__()
{
  g_CDmeTransformControlPullInModule = g_CDmeTransformControlLinkerHack;
  return g_CDmeTransformControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578F50
// Name: _dynamic_initializer_for__g_CDmeControlGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeControlGroup *dynamic_initializer_for__g_CDmeControlGroupPullInModule__()
{
  g_CDmeControlGroupPullInModule = g_CDmeControlGroupLinkerHack;
  return g_CDmeControlGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578F60
// Name: _dynamic_initializer_for__g_CDmeTimeSelectionPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeSelection *dynamic_initializer_for__g_CDmeTimeSelectionPullInModule__()
{
  g_CDmeTimeSelectionPullInModule = g_CDmeTimeSelectionLinkerHack;
  return g_CDmeTimeSelectionLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578F70
// Name: _dynamic_initializer_for__g_CDmeConstraintTargetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConstraintTarget *dynamic_initializer_for__g_CDmeConstraintTargetPullInModule__()
{
  g_CDmeConstraintTargetPullInModule = g_CDmeConstraintTargetLinkerHack;
  return g_CDmeConstraintTargetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578F80
// Name: _dynamic_initializer_for__g_CDmeConstraintSlavePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConstraintSlave *dynamic_initializer_for__g_CDmeConstraintSlavePullInModule__()
{
  g_CDmeConstraintSlavePullInModule = g_CDmeConstraintSlaveLinkerHack;
  return g_CDmeConstraintSlaveLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578F90
// Name: _dynamic_initializer_for__g_CDmeRigPointConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigPointConstraintOperator *dynamic_initializer_for__g_CDmeRigPointConstraintOperatorPullInModule__()
{
  g_CDmeRigPointConstraintOperatorPullInModule = g_CDmeRigPointConstraintOperatorLinkerHack;
  return g_CDmeRigPointConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578FA0
// Name: _dynamic_initializer_for__g_CDmeRigOrientConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigOrientConstraintOperator *dynamic_initializer_for__g_CDmeRigOrientConstraintOperatorPullInModule__()
{
  g_CDmeRigOrientConstraintOperatorPullInModule = g_CDmeRigOrientConstraintOperatorLinkerHack;
  return g_CDmeRigOrientConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578FB0
// Name: _dynamic_initializer_for__g_CDmeRigAimConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigAimConstraintOperator *dynamic_initializer_for__g_CDmeRigAimConstraintOperatorPullInModule__()
{
  g_CDmeRigAimConstraintOperatorPullInModule = g_CDmeRigAimConstraintOperatorLinkerHack;
  return g_CDmeRigAimConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578FC0
// Name: _dynamic_initializer_for__g_CDmeRigIKConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigIKConstraintOperator *dynamic_initializer_for__g_CDmeRigIKConstraintOperatorPullInModule__()
{
  g_CDmeRigIKConstraintOperatorPullInModule = g_CDmeRigIKConstraintOperatorLinkerHack;
  return g_CDmeRigIKConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578FD0
// Name: _dynamic_initializer_for__g_CDmeRigRotationConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigRotationConstraintOperator *dynamic_initializer_for__g_CDmeRigRotationConstraintOperatorPullInModule__()
{
  g_CDmeRigRotationConstraintOperatorPullInModule = g_CDmeRigRotationConstraintOperatorLinkerHack;
  return g_CDmeRigRotationConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578FE0
// Name: _dynamic_initializer_for__g_CDmeRigHandlePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigHandle *dynamic_initializer_for__g_CDmeRigHandlePullInModule__()
{
  g_CDmeRigHandlePullInModule = g_CDmeRigHandleLinkerHack;
  return g_CDmeRigHandleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578FF0
// Name: _dynamic_initializer_for__g_CDmeRigPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRig *dynamic_initializer_for__g_CDmeRigPullInModule__()
{
  g_CDmeRigPullInModule = g_CDmeRigLinkerHack;
  return g_CDmeRigLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00579000
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElementsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigAnimSetElements *dynamic_initializer_for__g_CDmeRigAnimSetElementsPullInModule__()
{
  g_CDmeRigAnimSetElementsPullInModule = g_CDmeRigAnimSetElementsLinkerHack;
  return g_CDmeRigAnimSetElementsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00579010
// Name: _dynamic_initializer_for__g_CDmeRigTwistSlavePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigTwistSlave *dynamic_initializer_for__g_CDmeRigTwistSlavePullInModule__()
{
  g_CDmeRigTwistSlavePullInModule = g_CDmeRigTwistSlaveLinkerHack;
  return g_CDmeRigTwistSlaveLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00579020
// Name: _dynamic_initializer_for__g_CDmeRigTwistConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigTwistConstraintOperator *dynamic_initializer_for__g_CDmeRigTwistConstraintOperatorPullInModule__()
{
  g_CDmeRigTwistConstraintOperatorPullInModule = g_CDmeRigTwistConstraintOperatorLinkerHack;
  return g_CDmeRigTwistConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00579030
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRuleBase *dynamic_initializer_for__g_CDmeFlexRuleBasePullInModule__()
{
  g_CDmeFlexRuleBasePullInModule = g_CDmeFlexRuleBaseLinkerHack;
  return g_CDmeFlexRuleBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00579040
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThroughPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRulePassThrough *dynamic_initializer_for__g_CDmeFlexRulePassThroughPullInModule__()
{
  g_CDmeFlexRulePassThroughPullInModule = g_CDmeFlexRulePassThroughLinkerHack;
  return g_CDmeFlexRulePassThroughLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00579050
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpressionPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *dynamic_initializer_for__g_CDmeFlexRuleExpressionPullInModule__()
{
  g_CDmeFlexRuleExpressionPullInModule = g_CDmeFlexRuleExpressionLinkerHack;
  return g_CDmeFlexRuleExpressionLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00579060
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRuleLocalVar *dynamic_initializer_for__g_CDmeFlexRuleLocalVarPullInModule__()
{
  g_CDmeFlexRuleLocalVarPullInModule = g_CDmeFlexRuleLocalVarLinkerHack;
  return g_CDmeFlexRuleLocalVarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00579070
// Name: _dynamic_initializer_for__g_CDmeFlexRulesPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *dynamic_initializer_for__g_CDmeFlexRulesPullInModule__()
{
  g_CDmeFlexRulesPullInModule = g_CDmeFlexRulesLinkerHack;
  return g_CDmeFlexRulesLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00579080
// Name: _dynamic_initializer_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_ApplicationObject__()
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(
    this: &_s_ApplicationObject,
    pFileSystem: nullptr,
    pAppSystemParent: nullptr);
  _s_ApplicationObject.__vftable = (CPhoGenApp_vtbl *)&CPhoGenApp::`vftable';
  return atexit(func: dynamic_atexit_destructor_for____s_ApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x005790B0
// Name: _dynamic_initializer_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_SteamApplicationObject__()
{
  CSteamApplication::CSteamApplication(this: &_s_SteamApplicationObject, pAppSystemGroup: &_s_ApplicationObject);
  return atexit(func: dynamic_atexit_destructor_for____s_SteamApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x005790D0
// Name: _dynamic_initializer_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &DmAttributeList_t::s_Allocator,
    blockSize: 8u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "DmAttributeList_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006A7DD0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A7E80
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A8190
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A8250
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x006A83A0
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A8420
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x006A8440
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006A8510
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x006A8730
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005799A0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00579A50
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00579D60
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00579E20
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x00579F70
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00579FF0
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x0057A000
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057A0D0
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x0057A2F0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0057A466
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0057A5E4
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057A618
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057A680
// Name: _ceil
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl ceil(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _ceil_default(x: X);
  v1 = _mm_getcsr() & 0x7F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _ceil_pentium4(X);
  else
    return _ceil_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x0057A6C0
// Name: __ceil_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _ceil_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns_0, (__m128i)_mm_and_pd(v2, *(__m128d *)&S_0));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    if ( v3 >= 3071 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 3122 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return -0.0;
  }
  else
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmpnle_pd(v9, v8).m128d_f64[0];
    if ( v3 < 1023 )
    {
      a1.m128i_i64[0] = *(_QWORD *)&_mm_cmpnle_pd(v9, *(__m128d *)&Zero).m128d_f64[0] & One_0;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 1074 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] + COERCE_DOUBLE(*(_QWORD *)&v10 & One_0);
      return *(double *)a1.m128i_i64;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057A79D
// Name: __ceil_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _ceil_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v1 = _ctrlfp();
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp();
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xCu, x, savedcw: v1);
    }
    return _except1(a1: (int)&savedregs, flags: 8, opcode: 12, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp();
      return v4;
    }
    else
    {
      return _except1(a1: (int)&savedregs, flags: 16, opcode: 12, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057A880
// Name: _dynamic_initializer_for__g_CDmElementPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *dynamic_initializer_for__g_CDmElementPullInModule__()
{
  g_CDmElementPullInModule = g_CDmElementLinkerHack;
  return g_CDmElementLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A890
// Name: _dynamic_initializer_for__g_CDmeTransformPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransform *dynamic_initializer_for__g_CDmeTransformPullInModule__()
{
  g_CDmeTransformPullInModule = g_CDmeTransformLinkerHack;
  return g_CDmeTransformLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A8A0
// Name: _dynamic_initializer_for__g_CDmeTransformListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformList *dynamic_initializer_for__g_CDmeTransformListPullInModule__()
{
  g_CDmeTransformListPullInModule = g_CDmeTransformListLinkerHack;
  return g_CDmeTransformListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A8B0
// Name: _dynamic_initializer_for__g_CDmeVertexDataBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDataBase *dynamic_initializer_for__g_CDmeVertexDataBasePullInModule__()
{
  g_CDmeVertexDataBasePullInModule = g_CDmeVertexDataBaseLinkerHack;
  return g_CDmeVertexDataBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A8C0
// Name: _dynamic_initializer_for__g_CDmeVertexDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexData *dynamic_initializer_for__g_CDmeVertexDataPullInModule__()
{
  g_CDmeVertexDataPullInModule = g_CDmeVertexDataLinkerHack;
  return g_CDmeVertexDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A8D0
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDeltaData *dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__()
{
  g_CDmeVertexDeltaDataPullInModule = g_CDmeVertexDeltaDataLinkerHack;
  return g_CDmeVertexDeltaDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A8E0
// Name: _dynamic_initializer_for__g_CDmeShapePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeShape *dynamic_initializer_for__g_CDmeShapePullInModule__()
{
  g_CDmeShapePullInModule = g_CDmeShapeLinkerHack;
  return g_CDmeShapeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A8F0
// Name: _dynamic_initializer_for__g_CDmeMeshPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMesh *dynamic_initializer_for__g_CDmeMeshPullInModule__()
{
  g_CDmeMeshPullInModule = g_CDmeMeshLinkerHack;
  return g_CDmeMeshLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A900
// Name: _dynamic_initializer_for__g_CDmeDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *dynamic_initializer_for__g_CDmeDagPullInModule__()
{
  g_CDmeDagPullInModule = g_CDmeDagLinkerHack;
  return g_CDmeDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A910
// Name: _dynamic_initializer_for__g_CDmeFaceSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFaceSet *dynamic_initializer_for__g_CDmeFaceSetPullInModule__()
{
  g_CDmeFaceSetPullInModule = g_CDmeFaceSetLinkerHack;
  return g_CDmeFaceSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A920
// Name: _dynamic_initializer_for__g_CDmeModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeModel *dynamic_initializer_for__g_CDmeModelPullInModule__()
{
  g_CDmeModelPullInModule = g_CDmeModelLinkerHack;
  return g_CDmeModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A930
// Name: _dynamic_initializer_for__g_CDmeJointPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJoint *dynamic_initializer_for__g_CDmeJointPullInModule__()
{
  g_CDmeJointPullInModule = g_CDmeJointLinkerHack;
  return g_CDmeJointLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A940
// Name: _dynamic_initializer_for__g_CDmeAttachmentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAttachment *dynamic_initializer_for__g_CDmeAttachmentPullInModule__()
{
  g_CDmeAttachmentPullInModule = g_CDmeAttachmentLinkerHack;
  return g_CDmeAttachmentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A950
// Name: _dynamic_initializer_for__g_CDmeMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMakefile *dynamic_initializer_for__g_CDmeMakefilePullInModule__()
{
  g_CDmeMakefilePullInModule = g_CDmeMakefileLinkerHack;
  return g_CDmeMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A960
// Name: _dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDLMakefile *dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__()
{
  g_CDmeMDLMakefilePullInModule = g_CDmeMDLMakefileLinkerHack;
  return g_CDmeMDLMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A970
// Name: _dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDCCMakefile *dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__()
{
  g_CDmeDCCMakefilePullInModule = g_CDmeDCCMakefileLinkerHack;
  return g_CDmeDCCMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A980
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaAnimationMakefile *dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__()
{
  g_CDmeMayaAnimationMakefilePullInModule = g_CDmeMayaAnimationMakefileLinkerHack;
  return g_CDmeMayaAnimationMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A990
// Name: _dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaCombinationOperator *dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__()
{
  g_CDmeMayaCombinationOperatorPullInModule = g_CDmeMayaCombinationOperatorLinkerHack;
  return g_CDmeMayaCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A9A0
// Name: _dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaMakefile *dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__()
{
  g_CDmeMayaMakefilePullInModule = g_CDmeMayaMakefileLinkerHack;
  return g_CDmeMayaMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A9B0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaModelMakefile *dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__()
{
  g_CDmeMayaModelMakefilePullInModule = g_CDmeMayaModelMakefileLinkerHack;
  return g_CDmeMayaModelMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A9C0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeXSIMakefile *dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__()
{
  g_CDmeXSIMakefilePullInModule = g_CDmeXSIMakefileLinkerHack;
  return g_CDmeXSIMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A9D0
// Name: _dynamic_initializer_for__g_CDmeSourcePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSource *dynamic_initializer_for__g_CDmeSourcePullInModule__()
{
  g_CDmeSourcePullInModule = g_CDmeSourceLinkerHack;
  return g_CDmeSourceLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A9E0
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceDCCFile *dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__()
{
  g_CDmeSourceDCCFilePullInModule = g_CDmeSourceDCCFileLinkerHack;
  return g_CDmeSourceDCCFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057A9F0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaFile *dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__()
{
  g_CDmeSourceMayaFilePullInModule = g_CDmeSourceMayaFileLinkerHack;
  return g_CDmeSourceMayaFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA00
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaModelFile *dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__()
{
  g_CDmeSourceMayaModelFilePullInModule = g_CDmeSourceMayaModelFileLinkerHack;
  return g_CDmeSourceMayaModelFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA10
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaAnimationFile *dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__()
{
  g_CDmeSourceMayaAnimationFilePullInModule = g_CDmeSourceMayaAnimationFileLinkerHack;
  return g_CDmeSourceMayaAnimationFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA20
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceXSIFile *dynamic_initializer_for__g_CDmeSourceXSIFilePullInModule__()
{
  g_CDmeSourceXSIFilePullInModule = g_CDmeSourceXSIFileLinkerHack;
  return g_CDmeSourceXSIFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA30
// Name: _dynamic_initializer_for__g_CDmeAnimationListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationList *dynamic_initializer_for__g_CDmeAnimationListPullInModule__()
{
  g_CDmeAnimationListPullInModule = g_CDmeAnimationListLinkerHack;
  return g_CDmeAnimationListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA40
// Name: _dynamic_initializer_for__g_CDmeClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *dynamic_initializer_for__g_CDmeClipPullInModule__()
{
  g_CDmeClipPullInModule = g_CDmeClipLinkerHack;
  return g_CDmeClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA50
// Name: _dynamic_initializer_for__g_CDmeChannelsClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannelsClip *dynamic_initializer_for__g_CDmeChannelsClipPullInModule__()
{
  g_CDmeChannelsClipPullInModule = g_CDmeChannelsClipLinkerHack;
  return g_CDmeChannelsClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA60
// Name: _dynamic_initializer_for__g_CDmeChannelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannel *dynamic_initializer_for__g_CDmeChannelPullInModule__()
{
  g_CDmeChannelPullInModule = g_CDmeChannelLinkerHack;
  return g_CDmeChannelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA70
// Name: _dynamic_initializer_for__g_CDmeTimeFramePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeFrame *dynamic_initializer_for__g_CDmeTimeFramePullInModule__()
{
  g_CDmeTimeFramePullInModule = g_CDmeTimeFrameLinkerHack;
  return g_CDmeTimeFrameLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA80
// Name: _dynamic_initializer_for__g_CDmeTrackGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrackGroup *dynamic_initializer_for__g_CDmeTrackGroupPullInModule__()
{
  g_CDmeTrackGroupPullInModule = g_CDmeTrackGroupLinkerHack;
  return g_CDmeTrackGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AA90
// Name: _dynamic_initializer_for__g_CDmeTrackPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrack *dynamic_initializer_for__g_CDmeTrackPullInModule__()
{
  g_CDmeTrackPullInModule = g_CDmeTrackLinkerHack;
  return g_CDmeTrackLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AAA0
// Name: _dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationDominationRule *dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__()
{
  g_CDmeCombinationDominationRulePullInModule = g_CDmeCombinationDominationRuleLinkerHack;
  return g_CDmeCombinationDominationRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AAB0
// Name: _dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationInputControl *dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__()
{
  g_CDmeCombinationInputControlPullInModule = g_CDmeCombinationInputControlLinkerHack;
  return g_CDmeCombinationInputControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AAC0
// Name: _dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationOperator *dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__()
{
  g_CDmeCombinationOperatorPullInModule = g_CDmeCombinationOperatorLinkerHack;
  return g_CDmeCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AAD0
// Name: _dynamic_initializer_for__g_CDmeIntLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<int> *dynamic_initializer_for__g_CDmeIntLogPullInModule__()
{
  g_CDmeIntLogPullInModule = g_CDmeIntLogLinkerHack;
  return g_CDmeIntLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AAE0
// Name: _dynamic_initializer_for__g_CDmeFloatLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<float> *dynamic_initializer_for__g_CDmeFloatLogPullInModule__()
{
  g_CDmeFloatLogPullInModule = g_CDmeFloatLogLinkerHack;
  return g_CDmeFloatLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AAF0
// Name: _dynamic_initializer_for__g_CDmeBoolLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<bool> *dynamic_initializer_for__g_CDmeBoolLogPullInModule__()
{
  g_CDmeBoolLogPullInModule = g_CDmeBoolLogLinkerHack;
  return g_CDmeBoolLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB00
// Name: _dynamic_initializer_for__g_CDmeColorLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Color> *dynamic_initializer_for__g_CDmeColorLogPullInModule__()
{
  g_CDmeColorLogPullInModule = g_CDmeColorLogLinkerHack;
  return g_CDmeColorLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB10
// Name: _dynamic_initializer_for__g_CDmeVector2LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogPullInModule__()
{
  g_CDmeVector2LogPullInModule = g_CDmeVector2LogLinkerHack;
  return g_CDmeVector2LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB20
// Name: _dynamic_initializer_for__g_CDmeVector3LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector> *dynamic_initializer_for__g_CDmeVector3LogPullInModule__()
{
  g_CDmeVector3LogPullInModule = g_CDmeVector3LogLinkerHack;
  return g_CDmeVector3LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB30
// Name: _dynamic_initializer_for__g_CDmeVector4LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogPullInModule__()
{
  g_CDmeVector4LogPullInModule = g_CDmeVector4LogLinkerHack;
  return g_CDmeVector4LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB40
// Name: _dynamic_initializer_for__g_CDmeQAngleLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogPullInModule__()
{
  g_CDmeQAngleLogPullInModule = g_CDmeQAngleLogLinkerHack;
  return g_CDmeQAngleLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB50
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__()
{
  g_CDmeQuaternionLogPullInModule = g_CDmeQuaternionLogLinkerHack;
  return g_CDmeQuaternionLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB60
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__()
{
  g_CDmeVMatrixLogPullInModule = g_CDmeVMatrixLogLinkerHack;
  return g_CDmeVMatrixLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB70
// Name: _dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<int> *dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__()
{
  g_CDmeIntLogLayerPullInModule = g_CDmeIntLogLayerLinkerHack;
  return g_CDmeIntLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB80
// Name: _dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<float> *dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__()
{
  g_CDmeFloatLogLayerPullInModule = g_CDmeFloatLogLayerLinkerHack;
  return g_CDmeFloatLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB90
// Name: _dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<bool> *dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__()
{
  g_CDmeBoolLogLayerPullInModule = g_CDmeBoolLogLayerLinkerHack;
  return g_CDmeBoolLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ABA0
// Name: _dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Color> *dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__()
{
  g_CDmeColorLogLayerPullInModule = g_CDmeColorLogLayerLinkerHack;
  return g_CDmeColorLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ABB0
// Name: _dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__()
{
  g_CDmeVector2LogLayerPullInModule = g_CDmeVector2LogLayerLinkerHack;
  return g_CDmeVector2LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ABC0
// Name: _dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector> *dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__()
{
  g_CDmeVector3LogLayerPullInModule = g_CDmeVector3LogLayerLinkerHack;
  return g_CDmeVector3LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ABD0
// Name: _dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__()
{
  g_CDmeVector4LogLayerPullInModule = g_CDmeVector4LogLayerLinkerHack;
  return g_CDmeVector4LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ABE0
// Name: _dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__()
{
  g_CDmeQAngleLogLayerPullInModule = g_CDmeQAngleLogLayerLinkerHack;
  return g_CDmeQAngleLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ABF0
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__()
{
  g_CDmeQuaternionLogLayerPullInModule = g_CDmeQuaternionLogLayerLinkerHack;
  return g_CDmeQuaternionLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AC00
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__()
{
  g_CDmeVMatrixLogLayerPullInModule = g_CDmeVMatrixLogLayerLinkerHack;
  return g_CDmeVMatrixLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AC10
// Name: _dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<int> *dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__()
{
  g_CDmeIntCurveInfoPullInModule = g_CDmeIntCurveInfoLinkerHack;
  return g_CDmeIntCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AC20
// Name: _dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<float> *dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__()
{
  g_CDmeFloatCurveInfoPullInModule = g_CDmeFloatCurveInfoLinkerHack;
  return g_CDmeFloatCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AC30
// Name: _dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<bool> *dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__()
{
  g_CDmeBoolCurveInfoPullInModule = g_CDmeBoolCurveInfoLinkerHack;
  return g_CDmeBoolCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AC40
// Name: _dynamic_initializer_for__g_CDmeColorCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Color> *dynamic_initializer_for__g_CDmeColorCurveInfoPullInModule__()
{
  g_CDmeColorCurveInfoPullInModule = g_CDmeColorCurveInfoLinkerHack;
  return g_CDmeColorCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AC50
// Name: _dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector2D> *dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__()
{
  g_CDmeVector2CurveInfoPullInModule = g_CDmeVector2CurveInfoLinkerHack;
  return g_CDmeVector2CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AC60
// Name: _dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector> *dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__()
{
  g_CDmeVector3CurveInfoPullInModule = g_CDmeVector3CurveInfoLinkerHack;
  return g_CDmeVector3CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AC70
// Name: _dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector4D> *dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__()
{
  g_CDmeVector4CurveInfoPullInModule = g_CDmeVector4CurveInfoLinkerHack;
  return g_CDmeVector4CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AC80
// Name: _dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<QAngle> *dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__()
{
  g_CDmeQAngleCurveInfoPullInModule = g_CDmeQAngleCurveInfoLinkerHack;
  return g_CDmeQAngleCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AC90
// Name: _dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__()
{
  g_CDmeQuaternionCurveInfoPullInModule = g_CDmeQuaternionCurveInfoLinkerHack;
  return g_CDmeQuaternionCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ACA0
// Name: _dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__()
{
  g_CDmeVMatrixCurveInfoPullInModule = g_CDmeVMatrixCurveInfoLinkerHack;
  return g_CDmeVMatrixCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ACB0
// Name: _dynamic_initializer_for__g_CDmeComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeComponent *dynamic_initializer_for__g_CDmeComponentPullInModule__()
{
  g_CDmeComponentPullInModule = g_CDmeComponentLinkerHack;
  return g_CDmeComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ACC0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSingleIndexedComponent *dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__()
{
  g_CDmeSingleIndexedComponentPullInModule = g_CDmeSingleIndexedComponentLinkerHack;
  return g_CDmeSingleIndexedComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ACD0
// Name: _dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDrawSettings *dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__()
{
  g_CDmeDrawSettingsPullInModule = g_CDmeDrawSettingsLinkerHack;
  return g_CDmeDrawSettingsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ACE0
// Name: _dynamic_initializer_for__g_CDmeCameraPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCamera *dynamic_initializer_for__g_CDmeCameraPullInModule__()
{
  g_CDmeCameraPullInModule = g_CDmeCameraLinkerHack;
  return g_CDmeCameraLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ACF0
// Name: _dynamic_initializer_for__g_CDmeSoundClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSoundClip *dynamic_initializer_for__g_CDmeSoundClipPullInModule__()
{
  g_CDmeSoundClipPullInModule = g_CDmeSoundClipLinkerHack;
  return g_CDmeSoundClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AD00
// Name: _dynamic_initializer_for__g_CDmeFilmClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFilmClip *dynamic_initializer_for__g_CDmeFilmClipPullInModule__()
{
  g_CDmeFilmClipPullInModule = g_CDmeFilmClipLinkerHack;
  return g_CDmeFilmClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AD10
// Name: _dynamic_initializer_for__g_CDmeMDLPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDL *dynamic_initializer_for__g_CDmeMDLPullInModule__()
{
  g_CDmeMDLPullInModule = g_CDmeMDLLinkerHack;
  return g_CDmeMDLLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AD20
// Name: _dynamic_initializer_for__g_CDmeMaterialPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMaterial *dynamic_initializer_for__g_CDmeMaterialPullInModule__()
{
  g_CDmeMaterialPullInModule = g_CDmeMaterialLinkerHack;
  return g_CDmeMaterialLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AD30
// Name: _dynamic_initializer_for__g_CDmeLightPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeLight *dynamic_initializer_for__g_CDmeLightPullInModule__()
{
  g_CDmeLightPullInModule = g_CDmeLightLinkerHack;
  return g_CDmeLightLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AD40
// Name: _dynamic_initializer_for__g_CDmeGameModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGameModel *dynamic_initializer_for__g_CDmeGameModelPullInModule__()
{
  g_CDmeGameModelPullInModule = g_CDmeGameModelLinkerHack;
  return g_CDmeGameModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AD50
// Name: _dynamic_initializer_for__g_CDmeSoundPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSound *dynamic_initializer_for__g_CDmeSoundPullInModule__()
{
  g_CDmeSoundPullInModule = g_CDmeSoundLinkerHack;
  return g_CDmeSoundLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AD60
// Name: _dynamic_initializer_for__g_CDmeGameSoundPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGameSound *dynamic_initializer_for__g_CDmeGameSoundPullInModule__()
{
  g_CDmeGameSoundPullInModule = g_CDmeGameSoundLinkerHack;
  return g_CDmeGameSoundLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AD70
// Name: _dynamic_initializer_for__g_CDmeMorphOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMorphOperator *dynamic_initializer_for__g_CDmeMorphOperatorPullInModule__()
{
  g_CDmeMorphOperatorPullInModule = g_CDmeMorphOperatorLinkerHack;
  return g_CDmeMorphOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AD80
// Name: _dynamic_initializer_for__g_CDmeTransformOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformOperator *dynamic_initializer_for__g_CDmeTransformOperatorPullInModule__()
{
  g_CDmeTransformOperatorPullInModule = g_CDmeTransformOperatorLinkerHack;
  return g_CDmeTransformOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AD90
// Name: _dynamic_initializer_for__g_CDmeExpressionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeExpressionOperator *dynamic_initializer_for__g_CDmeExpressionOperatorPullInModule__()
{
  g_CDmeExpressionOperatorPullInModule = g_CDmeExpressionOperatorLinkerHack;
  return g_CDmeExpressionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ADA0
// Name: _dynamic_initializer_for__g_CDmeConnectionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConnectionOperator *dynamic_initializer_for__g_CDmeConnectionOperatorPullInModule__()
{
  g_CDmeConnectionOperatorPullInModule = g_CDmeConnectionOperatorLinkerHack;
  return g_CDmeConnectionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ADB0
// Name: _dynamic_initializer_for__g_CDmeGamePortalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGamePortal *dynamic_initializer_for__g_CDmeGamePortalPullInModule__()
{
  g_CDmeGamePortalPullInModule = g_CDmeGamePortalLinkerHack;
  return g_CDmeGamePortalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ADC0
// Name: _dynamic_initializer_for__g_CDmeMouseInputPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMouseInput *dynamic_initializer_for__g_CDmeMouseInputPullInModule__()
{
  g_CDmeMouseInputPullInModule = g_CDmeMouseInputLinkerHack;
  return g_CDmeMouseInputLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ADD0
// Name: _dynamic_initializer_for__g_CDmeKeyboardInputPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeKeyboardInput *dynamic_initializer_for__g_CDmeKeyboardInputPullInModule__()
{
  g_CDmeKeyboardInputPullInModule = g_CDmeKeyboardInputLinkerHack;
  return g_CDmeKeyboardInputLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ADE0
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *dynamic_initializer_for__g_CDmeEditorAttributeInfoPullInModule__()
{
  g_CDmeEditorAttributeInfoPullInModule = g_CDmeEditorAttributeInfoLinkerHack;
  return g_CDmeEditorAttributeInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057ADF0
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *dynamic_initializer_for__g_CDmeEditorChoicesInfoPullInModule__()
{
  g_CDmeEditorChoicesInfoPullInModule = g_CDmeEditorChoicesInfoLinkerHack;
  return g_CDmeEditorChoicesInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE00
// Name: _dynamic_initializer_for__g_CDmeEditorTypePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorType *dynamic_initializer_for__g_CDmeEditorTypePullInModule__()
{
  g_CDmeEditorTypePullInModule = g_CDmeEditorTypeLinkerHack;
  return g_CDmeEditorTypeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE10
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionaryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorTypeDictionary *dynamic_initializer_for__g_CDmeEditorTypeDictionaryPullInModule__()
{
  g_CDmeEditorTypeDictionaryPullInModule = g_CDmeEditorTypeDictionaryLinkerHack;
  return g_CDmeEditorTypeDictionaryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE20
// Name: _dynamic_initializer_for__g_CDmePackColorOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackColorOperator *dynamic_initializer_for__g_CDmePackColorOperatorPullInModule__()
{
  g_CDmePackColorOperatorPullInModule = g_CDmePackColorOperatorLinkerHack;
  return g_CDmePackColorOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE30
// Name: _dynamic_initializer_for__g_CDmePackVector2OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector2Operator *dynamic_initializer_for__g_CDmePackVector2OperatorPullInModule__()
{
  g_CDmePackVector2OperatorPullInModule = g_CDmePackVector2OperatorLinkerHack;
  return g_CDmePackVector2OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE40
// Name: _dynamic_initializer_for__g_CDmePackVector3OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector3Operator *dynamic_initializer_for__g_CDmePackVector3OperatorPullInModule__()
{
  g_CDmePackVector3OperatorPullInModule = g_CDmePackVector3OperatorLinkerHack;
  return g_CDmePackVector3OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE50
// Name: _dynamic_initializer_for__g_CDmePackVector4OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector4Operator *dynamic_initializer_for__g_CDmePackVector4OperatorPullInModule__()
{
  g_CDmePackVector4OperatorPullInModule = g_CDmePackVector4OperatorLinkerHack;
  return g_CDmePackVector4OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE60
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackQAngleOperator *dynamic_initializer_for__g_CDmePackQAngleOperatorPullInModule__()
{
  g_CDmePackQAngleOperatorPullInModule = g_CDmePackQAngleOperatorLinkerHack;
  return g_CDmePackQAngleOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE70
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackQuaternionOperator *dynamic_initializer_for__g_CDmePackQuaternionOperatorPullInModule__()
{
  g_CDmePackQuaternionOperatorPullInModule = g_CDmePackQuaternionOperatorLinkerHack;
  return g_CDmePackQuaternionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE80
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *dynamic_initializer_for__g_CDmePackVMatrixOperatorPullInModule__()
{
  g_CDmePackVMatrixOperatorPullInModule = g_CDmePackVMatrixOperatorLinkerHack;
  return g_CDmePackVMatrixOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE90
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackColorOperator *dynamic_initializer_for__g_CDmeUnpackColorOperatorPullInModule__()
{
  g_CDmeUnpackColorOperatorPullInModule = g_CDmeUnpackColorOperatorLinkerHack;
  return g_CDmeUnpackColorOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AEA0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector2Operator *dynamic_initializer_for__g_CDmeUnpackVector2OperatorPullInModule__()
{
  g_CDmeUnpackVector2OperatorPullInModule = g_CDmeUnpackVector2OperatorLinkerHack;
  return g_CDmeUnpackVector2OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AEB0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector3Operator *dynamic_initializer_for__g_CDmeUnpackVector3OperatorPullInModule__()
{
  g_CDmeUnpackVector3OperatorPullInModule = g_CDmeUnpackVector3OperatorLinkerHack;
  return g_CDmeUnpackVector3OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AEC0
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector4Operator *dynamic_initializer_for__g_CDmeUnpackVector4OperatorPullInModule__()
{
  g_CDmeUnpackVector4OperatorPullInModule = g_CDmeUnpackVector4OperatorLinkerHack;
  return g_CDmeUnpackVector4OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AED0
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackQAngleOperator *dynamic_initializer_for__g_CDmeUnpackQAngleOperatorPullInModule__()
{
  g_CDmeUnpackQAngleOperatorPullInModule = g_CDmeUnpackQAngleOperatorLinkerHack;
  return g_CDmeUnpackQAngleOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AEE0
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackQuaternionOperator *dynamic_initializer_for__g_CDmeUnpackQuaternionOperatorPullInModule__()
{
  g_CDmeUnpackQuaternionOperatorPullInModule = g_CDmeUnpackQuaternionOperatorLinkerHack;
  return g_CDmeUnpackQuaternionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AEF0
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *dynamic_initializer_for__g_CDmeUnpackVMatrixOperatorPullInModule__()
{
  g_CDmeUnpackVMatrixOperatorPullInModule = g_CDmeUnpackVMatrixOperatorLinkerHack;
  return g_CDmeUnpackVMatrixOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AF00
// Name: _dynamic_initializer_for__g_CDmeAnimationSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationSet *dynamic_initializer_for__g_CDmeAnimationSetPullInModule__()
{
  g_CDmeAnimationSetPullInModule = g_CDmeAnimationSetLinkerHack;
  return g_CDmeAnimationSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AF10
// Name: _dynamic_initializer_for__g_CDmePhonemeMappingPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePhonemeMapping *dynamic_initializer_for__g_CDmePhonemeMappingPullInModule__()
{
  g_CDmePhonemeMappingPullInModule = g_CDmePhonemeMappingLinkerHack;
  return g_CDmePhonemeMappingLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AF20
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGlobalFlexControllerOperator *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperatorPullInModule__()
{
  g_CDmeGlobalFlexControllerOperatorPullInModule = g_CDmeGlobalFlexControllerOperatorLinkerHack;
  return g_CDmeGlobalFlexControllerOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AF30
// Name: _dynamic_initializer_for__g_CDmeTransformControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformControl *dynamic_initializer_for__g_CDmeTransformControlPullInModule__()
{
  g_CDmeTransformControlPullInModule = g_CDmeTransformControlLinkerHack;
  return g_CDmeTransformControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AF40
// Name: _dynamic_initializer_for__g_CDmeControlGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeControlGroup *dynamic_initializer_for__g_CDmeControlGroupPullInModule__()
{
  g_CDmeControlGroupPullInModule = g_CDmeControlGroupLinkerHack;
  return g_CDmeControlGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AF50
// Name: _dynamic_initializer_for__g_CDmeTimeSelectionPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeSelection *dynamic_initializer_for__g_CDmeTimeSelectionPullInModule__()
{
  g_CDmeTimeSelectionPullInModule = g_CDmeTimeSelectionLinkerHack;
  return g_CDmeTimeSelectionLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AF60
// Name: _dynamic_initializer_for__g_CDmeConstraintTargetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConstraintTarget *dynamic_initializer_for__g_CDmeConstraintTargetPullInModule__()
{
  g_CDmeConstraintTargetPullInModule = g_CDmeConstraintTargetLinkerHack;
  return g_CDmeConstraintTargetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AF70
// Name: _dynamic_initializer_for__g_CDmeConstraintSlavePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConstraintSlave *dynamic_initializer_for__g_CDmeConstraintSlavePullInModule__()
{
  g_CDmeConstraintSlavePullInModule = g_CDmeConstraintSlaveLinkerHack;
  return g_CDmeConstraintSlaveLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AF80
// Name: _dynamic_initializer_for__g_CDmeRigPointConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigPointConstraintOperator *dynamic_initializer_for__g_CDmeRigPointConstraintOperatorPullInModule__()
{
  g_CDmeRigPointConstraintOperatorPullInModule = g_CDmeRigPointConstraintOperatorLinkerHack;
  return g_CDmeRigPointConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AF90
// Name: _dynamic_initializer_for__g_CDmeRigOrientConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigOrientConstraintOperator *dynamic_initializer_for__g_CDmeRigOrientConstraintOperatorPullInModule__()
{
  g_CDmeRigOrientConstraintOperatorPullInModule = g_CDmeRigOrientConstraintOperatorLinkerHack;
  return g_CDmeRigOrientConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AFA0
// Name: _dynamic_initializer_for__g_CDmeRigAimConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigAimConstraintOperator *dynamic_initializer_for__g_CDmeRigAimConstraintOperatorPullInModule__()
{
  g_CDmeRigAimConstraintOperatorPullInModule = g_CDmeRigAimConstraintOperatorLinkerHack;
  return g_CDmeRigAimConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AFB0
// Name: _dynamic_initializer_for__g_CDmeRigIKConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigIKConstraintOperator *dynamic_initializer_for__g_CDmeRigIKConstraintOperatorPullInModule__()
{
  g_CDmeRigIKConstraintOperatorPullInModule = g_CDmeRigIKConstraintOperatorLinkerHack;
  return g_CDmeRigIKConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AFC0
// Name: _dynamic_initializer_for__g_CDmeRigRotationConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigRotationConstraintOperator *dynamic_initializer_for__g_CDmeRigRotationConstraintOperatorPullInModule__()
{
  g_CDmeRigRotationConstraintOperatorPullInModule = g_CDmeRigRotationConstraintOperatorLinkerHack;
  return g_CDmeRigRotationConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AFD0
// Name: _dynamic_initializer_for__g_CDmeRigHandlePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigHandle *dynamic_initializer_for__g_CDmeRigHandlePullInModule__()
{
  g_CDmeRigHandlePullInModule = g_CDmeRigHandleLinkerHack;
  return g_CDmeRigHandleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AFE0
// Name: _dynamic_initializer_for__g_CDmeRigPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRig *dynamic_initializer_for__g_CDmeRigPullInModule__()
{
  g_CDmeRigPullInModule = g_CDmeRigLinkerHack;
  return g_CDmeRigLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057AFF0
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElementsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigAnimSetElements *dynamic_initializer_for__g_CDmeRigAnimSetElementsPullInModule__()
{
  g_CDmeRigAnimSetElementsPullInModule = g_CDmeRigAnimSetElementsLinkerHack;
  return g_CDmeRigAnimSetElementsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057B000
// Name: _dynamic_initializer_for__g_CDmeRigTwistSlavePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigTwistSlave *dynamic_initializer_for__g_CDmeRigTwistSlavePullInModule__()
{
  g_CDmeRigTwistSlavePullInModule = g_CDmeRigTwistSlaveLinkerHack;
  return g_CDmeRigTwistSlaveLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057B010
// Name: _dynamic_initializer_for__g_CDmeRigTwistConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigTwistConstraintOperator *dynamic_initializer_for__g_CDmeRigTwistConstraintOperatorPullInModule__()
{
  g_CDmeRigTwistConstraintOperatorPullInModule = g_CDmeRigTwistConstraintOperatorLinkerHack;
  return g_CDmeRigTwistConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057B020
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRuleBase *dynamic_initializer_for__g_CDmeFlexRuleBasePullInModule__()
{
  g_CDmeFlexRuleBasePullInModule = g_CDmeFlexRuleBaseLinkerHack;
  return g_CDmeFlexRuleBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057B030
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThroughPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRulePassThrough *dynamic_initializer_for__g_CDmeFlexRulePassThroughPullInModule__()
{
  g_CDmeFlexRulePassThroughPullInModule = g_CDmeFlexRulePassThroughLinkerHack;
  return g_CDmeFlexRulePassThroughLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057B040
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpressionPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *dynamic_initializer_for__g_CDmeFlexRuleExpressionPullInModule__()
{
  g_CDmeFlexRuleExpressionPullInModule = g_CDmeFlexRuleExpressionLinkerHack;
  return g_CDmeFlexRuleExpressionLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057B050
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRuleLocalVar *dynamic_initializer_for__g_CDmeFlexRuleLocalVarPullInModule__()
{
  g_CDmeFlexRuleLocalVarPullInModule = g_CDmeFlexRuleLocalVarLinkerHack;
  return g_CDmeFlexRuleLocalVarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057B060
// Name: _dynamic_initializer_for__g_CDmeFlexRulesPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *dynamic_initializer_for__g_CDmeFlexRulesPullInModule__()
{
  g_CDmeFlexRulesPullInModule = g_CDmeFlexRulesLinkerHack;
  return g_CDmeFlexRulesLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x0057B070
// Name: _dynamic_initializer_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_ApplicationObject__()
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(
    this: &_s_ApplicationObject,
    pFileSystem: nullptr,
    pAppSystemParent: nullptr);
  _s_ApplicationObject.__vftable = (CSFMGenApp_vtbl *)&CSFMGenApp::`vftable';
  return atexit(func: dynamic_atexit_destructor_for____s_ApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B0A0
// Name: _dynamic_initializer_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_SteamApplicationObject__()
{
  CSteamApplication::CSteamApplication(this: &_s_SteamApplicationObject, pAppSystemGroup: &_s_ApplicationObject);
  return atexit(func: dynamic_atexit_destructor_for____s_SteamApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B0C0
// Name: _dynamic_initializer_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &DmAttributeList_t::s_Allocator,
    blockSize: 8u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "DmAttributeList_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005BDE50
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BDF00
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BE210
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BE2D0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x005BE420
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BE4A0
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x005BE4B0
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005BE580
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x005BE7A0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x005772F0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005773A0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005776B0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577770
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x005778C0
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577940
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x00577950
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00577A20
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x00577C40
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00577DB6
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00577F34
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00577F68
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005780D0
// Name: _dynamic_initializer_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_ApplicationObject__()
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(
    this: &_s_ApplicationObject,
    pFileSystem: nullptr,
    pAppSystemParent: nullptr);
  _s_ApplicationObject.__vftable = (CUvLightMap_AppSys_vtbl *)&CUvLightMap_AppSys::`vftable';
  return atexit(func: dynamic_atexit_destructor_for____s_ApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x00578100
// Name: _dynamic_initializer_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_SteamApplicationObject__()
{
  CSteamApplication::CSteamApplication(this: &_s_SteamApplicationObject, pAppSystemGroup: &_s_ApplicationObject);
  return atexit(func: dynamic_atexit_destructor_for____s_SteamApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x00578120
// Name: _dynamic_initializer_for__g_CDmElementPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *dynamic_initializer_for__g_CDmElementPullInModule__()
{
  g_CDmElementPullInModule = g_CDmElementLinkerHack;
  return g_CDmElementLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578130
// Name: _dynamic_initializer_for__g_CDmeTransformPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransform *dynamic_initializer_for__g_CDmeTransformPullInModule__()
{
  g_CDmeTransformPullInModule = g_CDmeTransformLinkerHack;
  return g_CDmeTransformLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578140
// Name: _dynamic_initializer_for__g_CDmeTransformListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformList *dynamic_initializer_for__g_CDmeTransformListPullInModule__()
{
  g_CDmeTransformListPullInModule = g_CDmeTransformListLinkerHack;
  return g_CDmeTransformListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578160
// Name: _dynamic_initializer_for__g_CDmeVertexDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexData *dynamic_initializer_for__g_CDmeVertexDataPullInModule__()
{
  g_CDmeVertexDataPullInModule = g_CDmeVertexDataLinkerHack;
  return g_CDmeVertexDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578170
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDeltaData *dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__()
{
  g_CDmeVertexDeltaDataPullInModule = g_CDmeVertexDeltaDataLinkerHack;
  return g_CDmeVertexDeltaDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578180
// Name: _dynamic_initializer_for__g_CDmeShapePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeShape *dynamic_initializer_for__g_CDmeShapePullInModule__()
{
  g_CDmeShapePullInModule = g_CDmeShapeLinkerHack;
  return g_CDmeShapeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578190
// Name: _dynamic_initializer_for__g_CDmeMeshPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMesh *dynamic_initializer_for__g_CDmeMeshPullInModule__()
{
  g_CDmeMeshPullInModule = g_CDmeMeshLinkerHack;
  return g_CDmeMeshLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005781A0
// Name: _dynamic_initializer_for__g_CDmeDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *dynamic_initializer_for__g_CDmeDagPullInModule__()
{
  g_CDmeDagPullInModule = g_CDmeDagLinkerHack;
  return g_CDmeDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005781B0
// Name: _dynamic_initializer_for__g_CDmeFaceSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFaceSet *dynamic_initializer_for__g_CDmeFaceSetPullInModule__()
{
  g_CDmeFaceSetPullInModule = g_CDmeFaceSetLinkerHack;
  return g_CDmeFaceSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005781C0
// Name: _dynamic_initializer_for__g_CDmeModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeModel *dynamic_initializer_for__g_CDmeModelPullInModule__()
{
  g_CDmeModelPullInModule = g_CDmeModelLinkerHack;
  return g_CDmeModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005781E0
// Name: _dynamic_initializer_for__g_CDmeAttachmentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAttachment *dynamic_initializer_for__g_CDmeAttachmentPullInModule__()
{
  g_CDmeAttachmentPullInModule = g_CDmeAttachmentLinkerHack;
  return g_CDmeAttachmentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578200
// Name: _dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDLMakefile *dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__()
{
  g_CDmeMDLMakefilePullInModule = g_CDmeMDLMakefileLinkerHack;
  return g_CDmeMDLMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578210
// Name: _dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDCCMakefile *dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__()
{
  g_CDmeDCCMakefilePullInModule = g_CDmeDCCMakefileLinkerHack;
  return g_CDmeDCCMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578220
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaAnimationMakefile *dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__()
{
  g_CDmeMayaAnimationMakefilePullInModule = g_CDmeMayaAnimationMakefileLinkerHack;
  return g_CDmeMayaAnimationMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578230
// Name: _dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaCombinationOperator *dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__()
{
  g_CDmeMayaCombinationOperatorPullInModule = g_CDmeMayaCombinationOperatorLinkerHack;
  return g_CDmeMayaCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578240
// Name: _dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaMakefile *dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__()
{
  g_CDmeMayaMakefilePullInModule = g_CDmeMayaMakefileLinkerHack;
  return g_CDmeMayaMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578250
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaModelMakefile *dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__()
{
  g_CDmeMayaModelMakefilePullInModule = g_CDmeMayaModelMakefileLinkerHack;
  return g_CDmeMayaModelMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578260
// Name: _dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeXSIMakefile *dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__()
{
  g_CDmeXSIMakefilePullInModule = g_CDmeXSIMakefileLinkerHack;
  return g_CDmeXSIMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578270
// Name: _dynamic_initializer_for__g_CDmeSourcePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSource *dynamic_initializer_for__g_CDmeSourcePullInModule__()
{
  g_CDmeSourcePullInModule = g_CDmeSourceLinkerHack;
  return g_CDmeSourceLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578280
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceDCCFile *dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__()
{
  g_CDmeSourceDCCFilePullInModule = g_CDmeSourceDCCFileLinkerHack;
  return g_CDmeSourceDCCFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578290
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaFile *dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__()
{
  g_CDmeSourceMayaFilePullInModule = g_CDmeSourceMayaFileLinkerHack;
  return g_CDmeSourceMayaFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005782A0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaModelFile *dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__()
{
  g_CDmeSourceMayaModelFilePullInModule = g_CDmeSourceMayaModelFileLinkerHack;
  return g_CDmeSourceMayaModelFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005782B0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaAnimationFile *dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__()
{
  g_CDmeSourceMayaAnimationFilePullInModule = g_CDmeSourceMayaAnimationFileLinkerHack;
  return g_CDmeSourceMayaAnimationFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005782D0
// Name: _dynamic_initializer_for__g_CDmeAnimationListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationList *dynamic_initializer_for__g_CDmeAnimationListPullInModule__()
{
  g_CDmeAnimationListPullInModule = g_CDmeAnimationListLinkerHack;
  return g_CDmeAnimationListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005782E0
// Name: _dynamic_initializer_for__g_CDmeClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *dynamic_initializer_for__g_CDmeClipPullInModule__()
{
  g_CDmeClipPullInModule = g_CDmeClipLinkerHack;
  return g_CDmeClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005782F0
// Name: _dynamic_initializer_for__g_CDmeChannelsClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannelsClip *dynamic_initializer_for__g_CDmeChannelsClipPullInModule__()
{
  g_CDmeChannelsClipPullInModule = g_CDmeChannelsClipLinkerHack;
  return g_CDmeChannelsClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578310
// Name: _dynamic_initializer_for__g_CDmeTimeFramePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeFrame *dynamic_initializer_for__g_CDmeTimeFramePullInModule__()
{
  g_CDmeTimeFramePullInModule = g_CDmeTimeFrameLinkerHack;
  return g_CDmeTimeFrameLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578320
// Name: _dynamic_initializer_for__g_CDmeTrackGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrackGroup *dynamic_initializer_for__g_CDmeTrackGroupPullInModule__()
{
  g_CDmeTrackGroupPullInModule = g_CDmeTrackGroupLinkerHack;
  return g_CDmeTrackGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578330
// Name: _dynamic_initializer_for__g_CDmeTrackPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrack *dynamic_initializer_for__g_CDmeTrackPullInModule__()
{
  g_CDmeTrackPullInModule = g_CDmeTrackLinkerHack;
  return g_CDmeTrackLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578340
// Name: _dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationDominationRule *dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__()
{
  g_CDmeCombinationDominationRulePullInModule = g_CDmeCombinationDominationRuleLinkerHack;
  return g_CDmeCombinationDominationRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578350
// Name: _dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationInputControl *dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__()
{
  g_CDmeCombinationInputControlPullInModule = g_CDmeCombinationInputControlLinkerHack;
  return g_CDmeCombinationInputControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578360
// Name: _dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationOperator *dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__()
{
  g_CDmeCombinationOperatorPullInModule = g_CDmeCombinationOperatorLinkerHack;
  return g_CDmeCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578370
// Name: _dynamic_initializer_for__g_CDmeIntLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<int> *dynamic_initializer_for__g_CDmeIntLogPullInModule__()
{
  g_CDmeIntLogPullInModule = g_CDmeIntLogLinkerHack;
  return g_CDmeIntLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578380
// Name: _dynamic_initializer_for__g_CDmeFloatLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<float> *dynamic_initializer_for__g_CDmeFloatLogPullInModule__()
{
  g_CDmeFloatLogPullInModule = g_CDmeFloatLogLinkerHack;
  return g_CDmeFloatLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578390
// Name: _dynamic_initializer_for__g_CDmeBoolLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<bool> *dynamic_initializer_for__g_CDmeBoolLogPullInModule__()
{
  g_CDmeBoolLogPullInModule = g_CDmeBoolLogLinkerHack;
  return g_CDmeBoolLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005783A0
// Name: _dynamic_initializer_for__g_CDmeColorLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Color> *dynamic_initializer_for__g_CDmeColorLogPullInModule__()
{
  g_CDmeColorLogPullInModule = g_CDmeColorLogLinkerHack;
  return g_CDmeColorLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005783B0
// Name: _dynamic_initializer_for__g_CDmeVector2LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogPullInModule__()
{
  g_CDmeVector2LogPullInModule = g_CDmeVector2LogLinkerHack;
  return g_CDmeVector2LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005783C0
// Name: _dynamic_initializer_for__g_CDmeVector3LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector> *dynamic_initializer_for__g_CDmeVector3LogPullInModule__()
{
  g_CDmeVector3LogPullInModule = g_CDmeVector3LogLinkerHack;
  return g_CDmeVector3LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005783D0
// Name: _dynamic_initializer_for__g_CDmeVector4LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogPullInModule__()
{
  g_CDmeVector4LogPullInModule = g_CDmeVector4LogLinkerHack;
  return g_CDmeVector4LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005783E0
// Name: _dynamic_initializer_for__g_CDmeQAngleLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogPullInModule__()
{
  g_CDmeQAngleLogPullInModule = g_CDmeQAngleLogLinkerHack;
  return g_CDmeQAngleLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005783F0
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__()
{
  g_CDmeQuaternionLogPullInModule = g_CDmeQuaternionLogLinkerHack;
  return g_CDmeQuaternionLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578400
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__()
{
  g_CDmeVMatrixLogPullInModule = g_CDmeVMatrixLogLinkerHack;
  return g_CDmeVMatrixLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578410
// Name: _dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<int> *dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__()
{
  g_CDmeIntLogLayerPullInModule = g_CDmeIntLogLayerLinkerHack;
  return g_CDmeIntLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578420
// Name: _dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<float> *dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__()
{
  g_CDmeFloatLogLayerPullInModule = g_CDmeFloatLogLayerLinkerHack;
  return g_CDmeFloatLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578430
// Name: _dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<bool> *dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__()
{
  g_CDmeBoolLogLayerPullInModule = g_CDmeBoolLogLayerLinkerHack;
  return g_CDmeBoolLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578440
// Name: _dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Color> *dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__()
{
  g_CDmeColorLogLayerPullInModule = g_CDmeColorLogLayerLinkerHack;
  return g_CDmeColorLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578450
// Name: _dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__()
{
  g_CDmeVector2LogLayerPullInModule = g_CDmeVector2LogLayerLinkerHack;
  return g_CDmeVector2LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578460
// Name: _dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector> *dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__()
{
  g_CDmeVector3LogLayerPullInModule = g_CDmeVector3LogLayerLinkerHack;
  return g_CDmeVector3LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578470
// Name: _dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__()
{
  g_CDmeVector4LogLayerPullInModule = g_CDmeVector4LogLayerLinkerHack;
  return g_CDmeVector4LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578480
// Name: _dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__()
{
  g_CDmeQAngleLogLayerPullInModule = g_CDmeQAngleLogLayerLinkerHack;
  return g_CDmeQAngleLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578490
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__()
{
  g_CDmeQuaternionLogLayerPullInModule = g_CDmeQuaternionLogLayerLinkerHack;
  return g_CDmeQuaternionLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005784A0
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__()
{
  g_CDmeVMatrixLogLayerPullInModule = g_CDmeVMatrixLogLayerLinkerHack;
  return g_CDmeVMatrixLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005784B0
// Name: _dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<int> *dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__()
{
  g_CDmeIntCurveInfoPullInModule = g_CDmeIntCurveInfoLinkerHack;
  return g_CDmeIntCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005784C0
// Name: _dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<float> *dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__()
{
  g_CDmeFloatCurveInfoPullInModule = g_CDmeFloatCurveInfoLinkerHack;
  return g_CDmeFloatCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005784D0
// Name: _dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<bool> *dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__()
{
  g_CDmeBoolCurveInfoPullInModule = g_CDmeBoolCurveInfoLinkerHack;
  return g_CDmeBoolCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005784F0
// Name: _dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector2D> *dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__()
{
  g_CDmeVector2CurveInfoPullInModule = g_CDmeVector2CurveInfoLinkerHack;
  return g_CDmeVector2CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578500
// Name: _dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector> *dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__()
{
  g_CDmeVector3CurveInfoPullInModule = g_CDmeVector3CurveInfoLinkerHack;
  return g_CDmeVector3CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578510
// Name: _dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector4D> *dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__()
{
  g_CDmeVector4CurveInfoPullInModule = g_CDmeVector4CurveInfoLinkerHack;
  return g_CDmeVector4CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578520
// Name: _dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<QAngle> *dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__()
{
  g_CDmeQAngleCurveInfoPullInModule = g_CDmeQAngleCurveInfoLinkerHack;
  return g_CDmeQAngleCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578530
// Name: _dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__()
{
  g_CDmeQuaternionCurveInfoPullInModule = g_CDmeQuaternionCurveInfoLinkerHack;
  return g_CDmeQuaternionCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578540
// Name: _dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__()
{
  g_CDmeVMatrixCurveInfoPullInModule = g_CDmeVMatrixCurveInfoLinkerHack;
  return g_CDmeVMatrixCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578550
// Name: _dynamic_initializer_for__g_CDmeComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeComponent *dynamic_initializer_for__g_CDmeComponentPullInModule__()
{
  g_CDmeComponentPullInModule = g_CDmeComponentLinkerHack;
  return g_CDmeComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578560
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSingleIndexedComponent *dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__()
{
  g_CDmeSingleIndexedComponentPullInModule = g_CDmeSingleIndexedComponentLinkerHack;
  return g_CDmeSingleIndexedComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578570
// Name: _dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDrawSettings *dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__()
{
  g_CDmeDrawSettingsPullInModule = g_CDmeDrawSettingsLinkerHack;
  return g_CDmeDrawSettingsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578580
// Name: _dynamic_initializer_for__g_CDmeCameraPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCamera *dynamic_initializer_for__g_CDmeCameraPullInModule__()
{
  g_CDmeCameraPullInModule = g_CDmeCameraLinkerHack;
  return g_CDmeCameraLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578590
// Name: _dynamic_initializer_for__g_CDmeSoundClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSoundClip *dynamic_initializer_for__g_CDmeSoundClipPullInModule__()
{
  g_CDmeSoundClipPullInModule = g_CDmeSoundClipLinkerHack;
  return g_CDmeSoundClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005785A0
// Name: _dynamic_initializer_for__g_CDmeFilmClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFilmClip *dynamic_initializer_for__g_CDmeFilmClipPullInModule__()
{
  g_CDmeFilmClipPullInModule = g_CDmeFilmClipLinkerHack;
  return g_CDmeFilmClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005785B0
// Name: _dynamic_initializer_for__g_CDmeMDLPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDL *dynamic_initializer_for__g_CDmeMDLPullInModule__()
{
  g_CDmeMDLPullInModule = g_CDmeMDLLinkerHack;
  return g_CDmeMDLLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005785C0
// Name: _dynamic_initializer_for__g_CDmeMaterialPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMaterial *dynamic_initializer_for__g_CDmeMaterialPullInModule__()
{
  g_CDmeMaterialPullInModule = g_CDmeMaterialLinkerHack;
  return g_CDmeMaterialLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005785D0
// Name: _dynamic_initializer_for__g_CDmeLightPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeLight *dynamic_initializer_for__g_CDmeLightPullInModule__()
{
  g_CDmeLightPullInModule = g_CDmeLightLinkerHack;
  return g_CDmeLightLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005785E0
// Name: _dynamic_initializer_for__g_CDmeGameModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGameModel *dynamic_initializer_for__g_CDmeGameModelPullInModule__()
{
  g_CDmeGameModelPullInModule = g_CDmeGameModelLinkerHack;
  return g_CDmeGameModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005785F0
// Name: _dynamic_initializer_for__g_CDmeSoundPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSound *dynamic_initializer_for__g_CDmeSoundPullInModule__()
{
  g_CDmeSoundPullInModule = g_CDmeSoundLinkerHack;
  return g_CDmeSoundLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578600
// Name: _dynamic_initializer_for__g_CDmeGameSoundPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGameSound *dynamic_initializer_for__g_CDmeGameSoundPullInModule__()
{
  g_CDmeGameSoundPullInModule = g_CDmeGameSoundLinkerHack;
  return g_CDmeGameSoundLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578610
// Name: _dynamic_initializer_for__g_CDmeMorphOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMorphOperator *dynamic_initializer_for__g_CDmeMorphOperatorPullInModule__()
{
  g_CDmeMorphOperatorPullInModule = g_CDmeMorphOperatorLinkerHack;
  return g_CDmeMorphOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578620
// Name: _dynamic_initializer_for__g_CDmeTransformOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformOperator *dynamic_initializer_for__g_CDmeTransformOperatorPullInModule__()
{
  g_CDmeTransformOperatorPullInModule = g_CDmeTransformOperatorLinkerHack;
  return g_CDmeTransformOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578630
// Name: _dynamic_initializer_for__g_CDmeExpressionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeExpressionOperator *dynamic_initializer_for__g_CDmeExpressionOperatorPullInModule__()
{
  g_CDmeExpressionOperatorPullInModule = g_CDmeExpressionOperatorLinkerHack;
  return g_CDmeExpressionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578640
// Name: _dynamic_initializer_for__g_CDmeConnectionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConnectionOperator *dynamic_initializer_for__g_CDmeConnectionOperatorPullInModule__()
{
  g_CDmeConnectionOperatorPullInModule = g_CDmeConnectionOperatorLinkerHack;
  return g_CDmeConnectionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578650
// Name: _dynamic_initializer_for__g_CDmeGamePortalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGamePortal *dynamic_initializer_for__g_CDmeGamePortalPullInModule__()
{
  g_CDmeGamePortalPullInModule = g_CDmeGamePortalLinkerHack;
  return g_CDmeGamePortalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578660
// Name: _dynamic_initializer_for__g_CDmeMouseInputPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMouseInput *dynamic_initializer_for__g_CDmeMouseInputPullInModule__()
{
  g_CDmeMouseInputPullInModule = g_CDmeMouseInputLinkerHack;
  return g_CDmeMouseInputLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578670
// Name: _dynamic_initializer_for__g_CDmeKeyboardInputPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeKeyboardInput *dynamic_initializer_for__g_CDmeKeyboardInputPullInModule__()
{
  g_CDmeKeyboardInputPullInModule = g_CDmeKeyboardInputLinkerHack;
  return g_CDmeKeyboardInputLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578680
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *dynamic_initializer_for__g_CDmeEditorAttributeInfoPullInModule__()
{
  g_CDmeEditorAttributeInfoPullInModule = g_CDmeEditorAttributeInfoLinkerHack;
  return g_CDmeEditorAttributeInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005786A0
// Name: _dynamic_initializer_for__g_CDmeEditorTypePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorType *dynamic_initializer_for__g_CDmeEditorTypePullInModule__()
{
  g_CDmeEditorTypePullInModule = g_CDmeEditorTypeLinkerHack;
  return g_CDmeEditorTypeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005786B0
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionaryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorTypeDictionary *dynamic_initializer_for__g_CDmeEditorTypeDictionaryPullInModule__()
{
  g_CDmeEditorTypeDictionaryPullInModule = g_CDmeEditorTypeDictionaryLinkerHack;
  return g_CDmeEditorTypeDictionaryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005786C0
// Name: _dynamic_initializer_for__g_CDmePackColorOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackColorOperator *dynamic_initializer_for__g_CDmePackColorOperatorPullInModule__()
{
  g_CDmePackColorOperatorPullInModule = g_CDmePackColorOperatorLinkerHack;
  return g_CDmePackColorOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005786E0
// Name: _dynamic_initializer_for__g_CDmePackVector3OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector3Operator *dynamic_initializer_for__g_CDmePackVector3OperatorPullInModule__()
{
  g_CDmePackVector3OperatorPullInModule = g_CDmePackVector3OperatorLinkerHack;
  return g_CDmePackVector3OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005786F0
// Name: _dynamic_initializer_for__g_CDmePackVector4OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector4Operator *dynamic_initializer_for__g_CDmePackVector4OperatorPullInModule__()
{
  g_CDmePackVector4OperatorPullInModule = g_CDmePackVector4OperatorLinkerHack;
  return g_CDmePackVector4OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578700
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackQAngleOperator *dynamic_initializer_for__g_CDmePackQAngleOperatorPullInModule__()
{
  g_CDmePackQAngleOperatorPullInModule = g_CDmePackQAngleOperatorLinkerHack;
  return g_CDmePackQAngleOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578710
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackQuaternionOperator *dynamic_initializer_for__g_CDmePackQuaternionOperatorPullInModule__()
{
  g_CDmePackQuaternionOperatorPullInModule = g_CDmePackQuaternionOperatorLinkerHack;
  return g_CDmePackQuaternionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578720
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *dynamic_initializer_for__g_CDmePackVMatrixOperatorPullInModule__()
{
  g_CDmePackVMatrixOperatorPullInModule = g_CDmePackVMatrixOperatorLinkerHack;
  return g_CDmePackVMatrixOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578730
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackColorOperator *dynamic_initializer_for__g_CDmeUnpackColorOperatorPullInModule__()
{
  g_CDmeUnpackColorOperatorPullInModule = g_CDmeUnpackColorOperatorLinkerHack;
  return g_CDmeUnpackColorOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578740
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector2Operator *dynamic_initializer_for__g_CDmeUnpackVector2OperatorPullInModule__()
{
  g_CDmeUnpackVector2OperatorPullInModule = g_CDmeUnpackVector2OperatorLinkerHack;
  return g_CDmeUnpackVector2OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578750
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector3Operator *dynamic_initializer_for__g_CDmeUnpackVector3OperatorPullInModule__()
{
  g_CDmeUnpackVector3OperatorPullInModule = g_CDmeUnpackVector3OperatorLinkerHack;
  return g_CDmeUnpackVector3OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578760
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector4Operator *dynamic_initializer_for__g_CDmeUnpackVector4OperatorPullInModule__()
{
  g_CDmeUnpackVector4OperatorPullInModule = g_CDmeUnpackVector4OperatorLinkerHack;
  return g_CDmeUnpackVector4OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578770
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackQAngleOperator *dynamic_initializer_for__g_CDmeUnpackQAngleOperatorPullInModule__()
{
  g_CDmeUnpackQAngleOperatorPullInModule = g_CDmeUnpackQAngleOperatorLinkerHack;
  return g_CDmeUnpackQAngleOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578780
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackQuaternionOperator *dynamic_initializer_for__g_CDmeUnpackQuaternionOperatorPullInModule__()
{
  g_CDmeUnpackQuaternionOperatorPullInModule = g_CDmeUnpackQuaternionOperatorLinkerHack;
  return g_CDmeUnpackQuaternionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578790
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *dynamic_initializer_for__g_CDmeUnpackVMatrixOperatorPullInModule__()
{
  g_CDmeUnpackVMatrixOperatorPullInModule = g_CDmeUnpackVMatrixOperatorLinkerHack;
  return g_CDmeUnpackVMatrixOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005787A0
// Name: _dynamic_initializer_for__g_CDmeAnimationSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationSet *dynamic_initializer_for__g_CDmeAnimationSetPullInModule__()
{
  g_CDmeAnimationSetPullInModule = g_CDmeAnimationSetLinkerHack;
  return g_CDmeAnimationSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005787B0
// Name: _dynamic_initializer_for__g_CDmePhonemeMappingPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePhonemeMapping *dynamic_initializer_for__g_CDmePhonemeMappingPullInModule__()
{
  g_CDmePhonemeMappingPullInModule = g_CDmePhonemeMappingLinkerHack;
  return g_CDmePhonemeMappingLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005787C0
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGlobalFlexControllerOperator *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperatorPullInModule__()
{
  g_CDmeGlobalFlexControllerOperatorPullInModule = g_CDmeGlobalFlexControllerOperatorLinkerHack;
  return g_CDmeGlobalFlexControllerOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005787D0
// Name: _dynamic_initializer_for__g_CDmeTransformControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformControl *dynamic_initializer_for__g_CDmeTransformControlPullInModule__()
{
  g_CDmeTransformControlPullInModule = g_CDmeTransformControlLinkerHack;
  return g_CDmeTransformControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005787E0
// Name: _dynamic_initializer_for__g_CDmeControlGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeControlGroup *dynamic_initializer_for__g_CDmeControlGroupPullInModule__()
{
  g_CDmeControlGroupPullInModule = g_CDmeControlGroupLinkerHack;
  return g_CDmeControlGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005787F0
// Name: _dynamic_initializer_for__g_CDmeTimeSelectionPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeSelection *dynamic_initializer_for__g_CDmeTimeSelectionPullInModule__()
{
  g_CDmeTimeSelectionPullInModule = g_CDmeTimeSelectionLinkerHack;
  return g_CDmeTimeSelectionLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578800
// Name: _dynamic_initializer_for__g_CDmeConstraintTargetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConstraintTarget *dynamic_initializer_for__g_CDmeConstraintTargetPullInModule__()
{
  g_CDmeConstraintTargetPullInModule = g_CDmeConstraintTargetLinkerHack;
  return g_CDmeConstraintTargetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578810
// Name: _dynamic_initializer_for__g_CDmeConstraintSlavePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConstraintSlave *dynamic_initializer_for__g_CDmeConstraintSlavePullInModule__()
{
  g_CDmeConstraintSlavePullInModule = g_CDmeConstraintSlaveLinkerHack;
  return g_CDmeConstraintSlaveLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578820
// Name: _dynamic_initializer_for__g_CDmeRigPointConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigPointConstraintOperator *dynamic_initializer_for__g_CDmeRigPointConstraintOperatorPullInModule__()
{
  g_CDmeRigPointConstraintOperatorPullInModule = g_CDmeRigPointConstraintOperatorLinkerHack;
  return g_CDmeRigPointConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578830
// Name: _dynamic_initializer_for__g_CDmeRigOrientConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigOrientConstraintOperator *dynamic_initializer_for__g_CDmeRigOrientConstraintOperatorPullInModule__()
{
  g_CDmeRigOrientConstraintOperatorPullInModule = g_CDmeRigOrientConstraintOperatorLinkerHack;
  return g_CDmeRigOrientConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578840
// Name: _dynamic_initializer_for__g_CDmeRigAimConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigAimConstraintOperator *dynamic_initializer_for__g_CDmeRigAimConstraintOperatorPullInModule__()
{
  g_CDmeRigAimConstraintOperatorPullInModule = g_CDmeRigAimConstraintOperatorLinkerHack;
  return g_CDmeRigAimConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578850
// Name: _dynamic_initializer_for__g_CDmeRigIKConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigIKConstraintOperator *dynamic_initializer_for__g_CDmeRigIKConstraintOperatorPullInModule__()
{
  g_CDmeRigIKConstraintOperatorPullInModule = g_CDmeRigIKConstraintOperatorLinkerHack;
  return g_CDmeRigIKConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578860
// Name: _dynamic_initializer_for__g_CDmeRigRotationConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigRotationConstraintOperator *dynamic_initializer_for__g_CDmeRigRotationConstraintOperatorPullInModule__()
{
  g_CDmeRigRotationConstraintOperatorPullInModule = g_CDmeRigRotationConstraintOperatorLinkerHack;
  return g_CDmeRigRotationConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578870
// Name: _dynamic_initializer_for__g_CDmeRigHandlePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigHandle *dynamic_initializer_for__g_CDmeRigHandlePullInModule__()
{
  g_CDmeRigHandlePullInModule = g_CDmeRigHandleLinkerHack;
  return g_CDmeRigHandleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x00578880
// Name: _dynamic_initializer_for__g_CDmeRigPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRig *dynamic_initializer_for__g_CDmeRigPullInModule__()
{
  g_CDmeRigPullInModule = g_CDmeRigLinkerHack;
  return g_CDmeRigLinkerHack;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x0042FC90
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FD40
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FDD0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // edx
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
// Address: 0x0042FE40
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
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
      if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x0042FFC0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // eax
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
// Address: 0x00430050
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430110
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x004301D0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x00430260
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004302E0
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x004302F0
// Name: public: virtual bool CDataManagerBase::TryLock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataManagerBase::TryLock(CP4File_Dummy *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00430300
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_1 < 1 )
      {
        ++_executeCount_1;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004303D0
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x004305F0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00430766
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004308E4
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430918
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( *(_DWORD *)&__locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430980
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x004309B0
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x004309E0
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00430A00
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x00430A50
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x00430A60
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00430A70
// Name: _dynamic_initializer_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_ApplicationObject__()
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(
    this: &_s_ApplicationObject,
    pFileSystem: nullptr,
    pAppSystemParent: nullptr);
  _s_ApplicationObject.__vftable = (CVcdUpdateApp_vtbl *)&CVcdUpdateApp::`vftable';
  return atexit(func: dynamic_atexit_destructor_for____s_ApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x00430AA0
// Name: _dynamic_initializer_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_SteamApplicationObject__()
{
  CSteamApplication::CSteamApplication(this: &_s_SteamApplicationObject, pAppSystemGroup: &_s_ApplicationObject);
  return atexit(func: dynamic_atexit_destructor_for____s_SteamApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x00430AC0
// Name: _dynamic_initializer_for__g_CheckNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckEventNames *dynamic_initializer_for__g_CheckNamesSingleton__()
{
  return CCheckEventNames::CCheckEventNames(this: &g_CheckNamesSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x00430AD0
// Name: _dynamic_initializer_for__g_CheckCCNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckCCNames *dynamic_initializer_for__g_CheckCCNamesSingleton__()
{
  return CCheckCCNames::CCheckCCNames(this: &g_CheckCCNamesSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x00430AE0
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
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
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
// Address: 0x00430B40
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
// Address: 0x00430B70
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00430B80
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x00430BA0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x00430BC0
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
// Address: 0x00430BD0
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00430BE0
// Name: _dynamic_initializer_for__g_TokenProcessor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_TokenProcessor__()
{
  CharacterSetBuild(pSetBuffer: &g_TokenProcessor.m_BreakSetIncludingColons, pszSetString: "{}()':");
}

//------------------------------------------------------------------------------
// Address: 0x00430C00
// Name: _dynamic_initializer_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00430C30
// Name: _dynamic_initializer_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00430C60
// Name: _dynamic_initializer_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00430C90
// Name: _dynamic_initializer_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioBoneCache__()
{
  CDataManagerBase::CDataManagerBase(this: &g_StudioBoneCache, maxSize: 0x20000u);
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  g_StudioBoneCache.m_mutex.m_ownerID = 0;
  g_StudioBoneCache.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioBoneCache__);
}

//------------------------------------------------------------------------------
// Address: 0x00430CD0
// Name: _dynamic_initializer_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_simdbones__()
{
  ConVar::ConVar(
    this: &cl_simdbones,
    pName: "cl_simdbones",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Use SIMD bone setup.");
  return atexit(func: dynamic_atexit_destructor_for__cl_simdbones__);
}

//------------------------------------------------------------------------------
// Address: 0x00430D00
// Name: _dynamic_initializer_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_use_simd_bones__()
{
  ConVar::ConVar(
    this: &cl_use_simd_bones,
    pName: "cl_use_simd_bones",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "1 use SIMD bones 0 use scalar bones.");
  return atexit(func: dynamic_atexit_destructor_for__cl_use_simd_bones__);
}

//------------------------------------------------------------------------------
// Address: 0x00430D30
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}

//------------------------------------------------------------------------------
// Address: 0x00430D60
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x00430D70
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x00430D80
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x00430D90
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00430DA0
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::~CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>(this: &emptyMapping.m_ActToSeqHash.m_Buckets);
}

//------------------------------------------------------------------------------
// Address: 0x00430DE0
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_SteamApplicationObject.m_NonAppSystemFactories);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x00430E20
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_ApplicationObject.m_NonAppSystemFactories);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x00430E60
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00430EA0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00430EF0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x00430F00
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00430F10
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x00430F20
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x00430F30
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x00430F40
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x00430F70
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x00430F80
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x00430F90
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

} // namespace vcdupdate

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x006B3DA0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B3E50
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B4160
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B4220
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x006B4370
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B43F0
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x006B4400
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_2 < 1 )
      {
        ++_executeCount_2;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B44D0
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x006B46F0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006B4866
// Name: xtoa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge xtoa(unsigned int val@<eax>, char *buf@<ecx>, unsigned int radix, int is_neg)
{
  char *v4; // esi
  char v5; // dl
  unsigned int v6; // et2
  char v7; // dl
  char *v8; // ecx
  char v9; // al

  if ( is_neg != 0 )
  {
    *buf++ = 45;
    val = -val;
  }
  v4 = buf;
  do
  {
    v6 = val % radix;
    val /= radix;
    v5 = v6;
    if ( v6 <= 9 )
      v7 = v5 + 48;
    else
      v7 = v5 + 87;
    *buf++ = v7;
  }
  while ( val != 0 );
  *buf = 0;
  v8 = buf - 1;
  do
  {
    v9 = *v8;
    *v8-- = *v4;
    *v4++ = v9;
  }
  while ( v4 < v8 );
}

//------------------------------------------------------------------------------
// Address: 0x006B48A9
// Name: _itoa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl itoa(int val, char *buf, unsigned int radix)
{
  if ( radix == 10 && val < 0 )
    xtoa(val, buf, radix: 0xAu, is_neg: 1);
  else
    xtoa(val, buf, radix, is_neg: 0);
  return buf;
}

//------------------------------------------------------------------------------
// Address: 0x006B48D3
// Name: __getextendedkeycode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const NormKeyVals *__cdecl _getextendedkeycode(_KEY_EVENT_RECORD *pKE)
{
  unsigned int dwControlKeyState; // ebx
  const NormKeyVals *result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  int v5; // ecx
  int wVirtualScanCode; // eax

  dwControlKeyState = pKE->dwControlKeyState;
  if ( (dwControlKeyState & 0x100) != 0 )
  {
    result = nullptr;
    v3 = 0;
    v4 = 0;
    while ( EnhancedKeys[v4].ScanCode != pKE->wVirtualScanCode )
    {
      ++v4;
      ++v3;
      if ( v4 >= 12 )
        return result;
    }
    v5 = v3;
    if ( (dwControlKeyState & 3) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].AltChars;
    if ( (dwControlKeyState & 0xC) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].CtrlChars;
    if ( (dwControlKeyState & 0x10) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].ShiftChars;
    return (const NormKeyVals *)&EnhancedKeys[v5].RegChars;
  }
  else
  {
    wVirtualScanCode = pKE->wVirtualScanCode;
    if ( (dwControlKeyState & 3) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].AltChars;
    }
    else if ( (dwControlKeyState & 0xC) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].CtrlChars;
    }
    else if ( (dwControlKeyState & 0x10) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].ShiftChars;
    }
    else
    {
      result = &NormalKeys[wVirtualScanCode];
    }
    if ( result->RegChars.LeadChar != 0 && result->RegChars.LeadChar != 0xE0 || result->RegChars.SecondChar == 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B4986
// Name: __getch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getch_nolock()
{
  int result; // eax
  int AsciiChar; // edi
  const NormKeyVals *v2; // eax
  unsigned int oldstate; // [esp+4h] [ebp-20h] BYREF
  unsigned int NumRead; // [esp+8h] [ebp-1Ch] BYREF
  _INPUT_RECORD ConInpRec; // [esp+Ch] [ebp-18h] BYREF

  if ( chbuf == -1 )
  {
    if ( _coninpfh == (HANDLE)-2 )
      __initconin();
    if ( _coninpfh == (HANDLE)-1 )
    {
      return -1;
    }
    else
    {
      GetConsoleMode(hConsoleHandle: _coninpfh, lpMode: &oldstate);
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: 0);
      while ( 1 )
      {
        if ( !ReadConsoleInputA(
                hConsoleInput: _coninpfh,
                lpBuffer: &ConInpRec,
                nLength: 1u,
                lpNumberOfEventsRead: &NumRead)
          || NumRead == 0 )
        {
          AsciiChar = -1;
          goto LABEL_15;
        }
        if ( ConInpRec.EventType == 1 && ConInpRec.Event.KeyEvent.bKeyDown != 0 )
        {
          AsciiChar = (unsigned __int8)ConInpRec.Event.KeyEvent.uChar.AsciiChar;
          if ( ConInpRec.Event.KeyEvent.uChar.AsciiChar != 0 )
            goto LABEL_15;
          v2 = _getextendedkeycode(pKE: &ConInpRec.Event.KeyEvent);
          if ( v2 != nullptr )
            break;
        }
      }
      AsciiChar = v2->RegChars.LeadChar;
      chbuf = v2->RegChars.SecondChar;
LABEL_15:
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: oldstate);
      return AsciiChar;
    }
  }
  else
  {
    result = (unsigned __int8)chbuf;
    chbuf = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B4A5F
// Name: _getch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl getch()
{
  int v1; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 3);
  v1 = _getch_nolock();
  _unlock(locknum: 3);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x006B4A9D
// Name: void __ArrayUnwind(void __near *,unsigned int,int,void (*)(void __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __ArrayUnwind(char *ptr, unsigned int size, int count, void (*pDtor)(void))
{
  while ( --count >= 0 )
  {
    ptr -= size;
    pDtor();
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B4BD0
// Name: __CIsqrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x006B4C8A
// Name: __mbscmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbscmp_l(unsigned __int8 *s1, unsigned __int8 *s2, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // esi
  __int16 v5; // cx
  __int16 v6; // ax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = s1;
  if ( s1 != nullptr )
  {
    v4 = s2;
    if ( s2 != nullptr )
    {
      if ( _loc_update.localeinfo.mbcinfo->ismbcodepage != 0 )
      {
        while ( 1 )
        {
          v5 = *v3++;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v5 + 1] & 4) != 0 )
          {
            if ( *v3 != 0 )
              v5 = *v3++ | (unsigned __int16)(v5 << 8);
            else
              v5 = 0;
          }
          v6 = *v4++;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) != 0 )
          {
            if ( *v4 != 0 )
              v6 = *v4++ | (unsigned __int16)(v6 << 8);
            else
              v6 = 0;
          }
          if ( v6 != v5 )
            break;
          if ( v5 == 0 )
          {
            if ( _loc_update.updated )
              _loc_update.ptd->_ownlocale &= ~2u;
            return;
          }
        }
      }
      else
      {
        strcmp(str1: s1, str2: s2);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B4D89
// Name: __mbscmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbscmp(unsigned __int8 *s1, unsigned __int8 *s2)
{
  _mbscmp_l(s1, s2, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x006B4DA0
// Name: ___initconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconin()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONIN$",
             dwDesiredAccess: 0xC0000000,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _coninpfh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B4DBF
// Name: ___termconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconin()
{
  HANDLE result; // eax

  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B4F90
// Name: _dynamic_initializer_for__g_globalTextureDict__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_globalTextureDict__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_globalTextureDict.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_globalTextureDict__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4FB0
// Name: _dynamic_initializer_for__s_DetailObjectDict__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DetailObjectDict__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DetailObjectDict__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4FC0
// Name: _dynamic_initializer_for__s_StaticPropLookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StaticPropLookup__()
{
  s_StaticPropLookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<StaticPropLookup_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                    this: _g_pMemAlloc,
                                                                                                    a2: 384);
  *(_DWORD *)&s_StaticPropLookup.m_Root = 0xFFFF;
  *(_DWORD *)&s_StaticPropLookup.m_FirstFree = -1;
  s_StaticPropLookup.m_pElements = s_StaticPropLookup.m_Elements.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_StaticPropLookup__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5000
// Name: _dynamic_initializer_for__s_DetailObjectDictLump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DetailObjectDictLump__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DetailObjectDictLump__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5010
// Name: _dynamic_initializer_for__s_DetailObjectLump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DetailObjectLump__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DetailObjectLump__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5020
// Name: _dynamic_initializer_for__s_DetailSpriteDictLump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DetailSpriteDictLump__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DetailSpriteDictLump__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5030
// Name: _dynamic_initializer_for__g_TesselateVerts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TesselateVerts__()
{
  g_TesselateVerts[0].m_Index = (CVertIndex)-65535;
  dword_76075A = -65536;
  dword_760760 = -1;
  dword_760766 = 0xFFFF;
  dword_76076C = 0x1FFFF;
  dword_760772 = 0x10000;
  dword_760778 = 65537;
  dword_76077E = 1;
  dword_760784 = -65535;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006B50F0
// Name: _dynamic_initializer_for__g_VertInfo_5x5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_5x5__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_5x5;
  for ( i = 24; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B5110
// Name: _dynamic_initializer_for__g_VertInfo_9x9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_9x9__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_9x9;
  for ( i = 80; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B5130
// Name: _dynamic_initializer_for__g_VertInfo_17x17__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVertInfo *dynamic_initializer_for__g_VertInfo_17x17__()
{
  CVertInfo *v0; // esi
  int i; // edi
  CVertInfo *result; // eax

  v0 = g_VertInfo_17x17;
  for ( i = 288; i >= 0; --i )
    result = CVertInfo::CVertInfo(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B5150
// Name: _dynamic_initializer_for__g_PowerInfoInitializer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_PowerInfoInitializer__()
{
  int i; // esi
  CPowerInfo *v1; // eax

  for ( i = 0; i <= 4; ++i )
  {
    v1 = g_PowerInfos[i];
    if ( v1 != nullptr )
      InitPowerInfo(pInfo: v1, iMaxPower: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B5170
// Name: _dynamic_initializer_for__g_CoreDispInfos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CoreDispInfos__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CoreDispInfos__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5180
// Name: _dynamic_initializer_for__g_CoreDispTexInfos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CoreDispTexInfos__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CoreDispTexInfos__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5190
// Name: _dynamic_initializer_for__g_VertEdgeList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VertEdgeList__()
{
  int v0; // edx
  int *p_m_nGrowSize; // eax

  v0 = 0xFFFF;
  p_m_nGrowSize = &g_VertEdgeList.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v0;
  }
  while ( v0 >= 0 );
  return atexit(func: dynamic_atexit_destructor_for__g_VertEdgeList__);
}

//------------------------------------------------------------------------------
// Address: 0x006B51C0
// Name: _dynamic_initializer_for__LOG_GENERAL__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_GENERAL__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "General",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_19);
  LOG_GENERAL = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B51E0
// Name: _dynamic_initializer_for__brushsides__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__brushsides__()
{
  int v0; // edx
  int *p_m_nGrowSize; // eax

  v0 = 0xFFFF;
  p_m_nGrowSize = &brushsides[0].aOverlayIds.m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize[3] = 0;
    p_m_nGrowSize[4] = 0;
    p_m_nGrowSize[5] = 0;
    p_m_nGrowSize[6] = 0;
    p_m_nGrowSize[7] = 0;
    p_m_nGrowSize += 25;
    --v0;
  }
  while ( v0 >= 0 );
  return atexit(func: dynamic_atexit_destructor_for__brushsides__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5220
// Name: _dynamic_initializer_for__side_brushtextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
float *dynamic_initializer_for__side_brushtextures__()
{
  int v0; // ecx
  float *result; // eax

  v0 = 0xFFFF;
  result = &side_brushtextures[0].VAxis.z;
  do
  {
    *(result - 5) = 0.0;
    *(result - 4) = 0.0;
    *(result - 3) = 0.0;
    *(result - 2) = 0.0;
    *(result - 1) = 0.0;
    *result = 0.0;
    result += 45;
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B5260
// Name: _dynamic_initializer_for__mapplanes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
float *dynamic_initializer_for__mapplanes__()
{
  int v0; // ecx
  float *result; // eax

  v0 = 0xFFFF;
  result = &mapplanes.z;
  do
  {
    *(result - 2) = 0.0;
    *(result - 1) = 0.0;
    *result = 0.0;
    result += 6;
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B5290
// Name: _dynamic_initializer_for__g_NoDynamicShadowSides__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_NoDynamicShadowSides__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_NoDynamicShadowSides__);
}

//------------------------------------------------------------------------------
// Address: 0x006B52A0
// Name: _dynamic_initializer_for__s_SymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_SymbolTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &s_SymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__s_SymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x006B52C0
// Name: _dynamic_initializer_for__s_MapPatchedMatToOriginalMat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_MapPatchedMatToOriginalMat__()
{
  s_MapPatchedMatToOriginalMat.m_Elements.m_pMemory = (UtlRBTreeNode_t<NameTranslationLookup_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 5120);
  s_MapPatchedMatToOriginalMat.m_Root = -1;
  s_MapPatchedMatToOriginalMat.m_NumElements = 0;
  s_MapPatchedMatToOriginalMat.m_FirstFree = -1;
  s_MapPatchedMatToOriginalMat.m_LastAlloc.index = -1;
  s_MapPatchedMatToOriginalMat.m_pElements = s_MapPatchedMatToOriginalMat.m_Elements.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_MapPatchedMatToOriginalMat__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5310
// Name: _dynamic_initializer_for__g_aMapOverlays__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_aMapOverlays__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_aMapOverlays__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5320
// Name: _dynamic_initializer_for__g_aMapWaterOverlays__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_aMapWaterOverlays__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_aMapWaterOverlays__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5330
// Name: _dynamic_initializer_for__g_VisClusters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VisClusters__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VisClusters__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5340
// Name: _dynamic_initializer_for__s_StaticPropBounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StaticPropBounds__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_StaticPropBounds__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5350
// Name: _dynamic_initializer_for__s_StaticPropDictLump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StaticPropDictLump__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_StaticPropDictLump__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5360
// Name: _dynamic_initializer_for__s_StaticPropLump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StaticPropLump__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_StaticPropLump__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5370
// Name: _dynamic_initializer_for__s_StaticPropLeafLump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StaticPropLeafLump__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_StaticPropLeafLump__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5380
// Name: _dynamic_initializer_for__s_ModelCollisionCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ModelCollisionCache__()
{
  s_ModelCollisionCache.m_Elements.m_pMemory = (UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 768);
  *(_DWORD *)&s_ModelCollisionCache.m_Root = 0xFFFF;
  *(_DWORD *)&s_ModelCollisionCache.m_FirstFree = -1;
  s_ModelCollisionCache.m_pElements = s_ModelCollisionCache.m_Elements.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__s_ModelCollisionCache__);
}

//------------------------------------------------------------------------------
// Address: 0x006B53C0
// Name: _dynamic_initializer_for__s_LightingInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_LightingInfo__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_LightingInfo__);
}

//------------------------------------------------------------------------------
// Address: 0x006B53D0
// Name: _dynamic_initializer_for__g_SkyAreas__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SkyAreas__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_SkyAreas__);
}

//------------------------------------------------------------------------------
// Address: 0x006B53E0
// Name: _dynamic_initializer_for__g_MapBlocks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MapBlocks__()
{
  int v0; // eax
  int v1; // edx
  int result; // eax

  _Msg(a1: "Setting block size to %d\n", 1024);
  v0 = 0x8000 / g_MapBlocks.blockSize / 2;
  v1 = v0 - 1;
  result = v0 + 1;
  g_MapBlocks.xStart = 0x8000 / g_MapBlocks.blockSize / -2;
  g_MapBlocks.xEnd = v1;
  g_MapBlocks.yStart = 0x8000 / g_MapBlocks.blockSize / -2;
  g_MapBlocks.yEnd = v1;
  g_MapBlocks.xOffset = result;
  g_MapBlocks.yOffset = result;
  g_MapBlocks.blockMin = 0x8000 / g_MapBlocks.blockSize / -2;
  g_MapBlocks.blockMax = v1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B5450
// Name: _dynamic_initializer_for__g_OccluderInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OccluderInfo__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_OccluderInfo__);
}

} // namespace vmap

// ============================================================
// Overlay from vphysics (Missing functions)
// ============================================================
namespace vphysics {

//------------------------------------------------------------------------------
// Address: 0x100AECC0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AED50
// Name: public: unsigned short CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_FirstFree; // ecx
  int m_MaxElementIndex; // ecx
  int result; // eax
  int v5; // ecx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v6; // esi

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_13:
    v5 = (unsigned __int16)result;
    this->m_Memory.m_pMemory[v5].m_Previous = result;
    this->m_Memory.m_pMemory[v5].m_Next = result;
    ++this->m_TotalElements;
    v6 = &this->m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      *(_DWORD *)&v6->m_Element.lockCount = 0x10000;
      v6->m_Element.pStore = nullptr;
    }
    return result;
  }
  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (unsigned __int16)m_MaxElementIndex != m_MaxElementIndex || (_WORD)m_MaxElementIndex == 0xFFFF )
  {
    if ( `CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`9'::__executeCount < 10 )
    {
      ++`CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`9'::__executeCount;
      _Warning(a1: "CUtlMultiList overflow! (exhausted index range)\n");
    }
    return 0xFFFF;
  }
  if ( m_MaxElementIndex != this->m_Memory.m_nAllocationCount
    || (CUtlMemory<CPredictedPhysicsMotionController::PredictionCommandOffsets_t,int>::Grow(
          this: &this->m_Memory,
          num: 1),
        this->m_pElements = this->m_Memory.m_pMemory,
        (m_MaxElementIndex = this->m_MaxElementIndex) < this->m_Memory.m_nAllocationCount) )
  {
    result = LOWORD(this->m_MaxElementIndex);
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
    goto LABEL_13;
  }
  if ( `CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`19'::__executeCount;
  _Warning(a1: "CUtlMultiList overflow! (exhausted memory allocator)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100AF0B0
// Name: protected: struct memhandle_t__ __near * CDataManagerBase::StoreResourceInHandle(unsigned short,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataManagerBase::StoreResourceInHandle(
        CDataManagerBase *this,
        unsigned __int16 memoryIndex,
        void *pStore,
        unsigned int realSize)
{
  int v5; // eax
  int v6; // edi

  this->Lock(this);
  v5 = memoryIndex;
  this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.pStore = pStore;
  this->m_memUsed += realSize;
  v6 = this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.serial << 16;
  this->Unlock(this);
  return (memhandle_t__ *)(v6 | (unsigned __int16)(memoryIndex + 1));
}

//------------------------------------------------------------------------------
// Address: 0x100AF100
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF1C0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x100AF280
// Name: public: CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF300
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::~CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x100AF310
// Name: protected: void __near * CDataManagerBase::LockResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::LockResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  _WORD *v7; // edx
  int v8; // edi
  memhandle_t__ *handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  v5 = (unsigned int)handle >> 16;
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (v6 = 12 * v4,
        v7 = (unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6),
        handlea = (memhandle_t__ *)v6,
        v7[4] == v3)
    && v7[5] != v3
    || v7[1] != (_WORD)v5
    || v3 == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( *v7 == 0 )
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        elem: v3);
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list: this->m_lockList,
        before: 0xFFFFu,
        elem: v3);
      v6 = (int)handlea;
    }
    ++*(unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6);
    v8 = *(int *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.pStore + v6);
    this->Unlock(this);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF3C0
// Name: public: int CDataManagerBase::UnlockResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::UnlockResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned int v3; // ecx
  int v4; // ebx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // edx
  int lockCount; // esi
  unsigned __int16 handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (unsigned int)handle >> 16;
  handlea = (_WORD)handle - 1;
  if ( handlea >= this->m_memoryLists.m_MaxElementIndex
    || (v4 = handlea, (v5 = &this->m_memoryLists.m_Memory.m_pMemory[v4])->m_Previous == handlea)
    && v5->m_Next != handlea
    || v5->m_Element.serial != (_WORD)v3
    || handlea == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( v5->m_Element.lockCount != 0 )
    {
      --this->m_memoryLists.m_Memory.m_pMemory[handlea].m_Element.lockCount;
      if ( this->m_memoryLists.m_Memory.m_pMemory[v4].m_Element.lockCount == 0 )
      {
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
          this: &this->m_memoryLists,
          list: this->m_lockList,
          elem: handlea);
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
          this: &this->m_memoryLists,
          list: this->m_lruList,
          before: 0xFFFFu,
          elem: handlea);
      }
    }
    lockCount = this->m_memoryLists.m_Memory.m_pMemory[handlea].m_Element.lockCount;
    this->Unlock(this);
    return lockCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF480
// Name: public: int CDataManagerBase::BreakLock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::BreakLock(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  int v5; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v6; // edx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int lockCount; // ecx
  int nBroken; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 < this->m_memoryLists.m_MaxElementIndex
    && ((v5 = v4, (v6 = &this->m_memoryLists.m_Memory.m_pMemory[v5])->m_Previous != v3) || v6->m_Next == v3)
    && v6->m_Element.serial == HIWORD(handle)
    && (_WORD)handle != 0
    && v6->m_Element.lockCount != 0 )
  {
    v7 = &this->m_memoryLists.m_Memory.m_pMemory[v5];
    lockCount = v7->m_Element.lockCount;
    v7->m_Element.lockCount = 0;
    nBroken = lockCount;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lockList,
      elem: v3);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      before: 0xFFFFu,
      elem: v3);
    this->Unlock(this);
    return nBroken;
  }
  else
  {
    this->Unlock(this);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF530
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount < 1 )
      {
        ++_executeCount;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF600
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x100AF820
// Name: public: void CDataManagerBase::DestroyResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::DestroyResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // cx
  int v4; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edi
  int v6; // eax
  bool v7; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax
  unsigned __int16 v9; // di
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v10; // eax
  void *v11; // edi

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (m_pMemory = this->m_memoryLists.m_Memory.m_pMemory,
        v6 = v4,
        v7 = m_pMemory[v6].m_Previous == v3,
        v8 = &m_pMemory[v6],
        v7)
    && v8->m_Next != v3
    || (v9 = (_WORD)handle - 1, v8->m_Element.serial != HIWORD(handle)) )
  {
    v9 = -1;
  }
  if ( v9 < this->m_memoryLists.m_MaxElementIndex
    && ((v10 = &this->m_memoryLists.m_Memory.m_pMemory[v9])->m_Previous != v9 || v10->m_Next == v9) )
  {
    if ( v10->m_Element.lockCount != 0 )
      CDataManagerBase::BreakLock(this, handle);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      elem: v9);
    v11 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v9);
    this->Unlock(this);
    this->DestroyResourceStorage(this, a2: v11);
  }
  else
  {
    this->Unlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF8E0
// Name: protected: unsigned short CDataManagerBase::CreateHandle(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDataManagerBase::CreateHandle(CDataManagerBase *this, bool bCreateLocked)
{
  int m_Head; // ebx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *p_m_memoryLists; // esi
  unsigned __int16 v5; // ax
  int v6; // ebx
  __int16 v7; // ax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax
  unsigned __int16 list; // [esp+Ch] [ebp-4h]

  this->Lock(this);
  m_Head = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_freeList].m_Element.m_Head;
  if ( bCreateLocked )
    list = this->m_lockList;
  else
    list = this->m_lruList;
  p_m_memoryLists = &this->m_memoryLists;
  if ( m_Head == 0xFFFF )
  {
    v5 = CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(this: &this->m_memoryLists);
    v6 = v5;
    if ( v5 == 0xFFFF )
    {
      v7 = -1;
    }
    else
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list,
        before: 0xFFFFu,
        elem: v5);
      v8 = &p_m_memoryLists->m_Memory.m_pMemory[v6];
      if ( v8 != nullptr )
      {
        *(_DWORD *)&v8->m_Element.lockCount = 0x10000;
        v8->m_Element.pStore = nullptr;
      }
      v7 = v6;
    }
    LOWORD(m_Head) = v7;
  }
  else
  {
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      elem: m_Head);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list,
      before: 0xFFFFu,
      elem: m_Head);
  }
  if ( bCreateLocked )
    ++p_m_memoryLists->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Element.lockCount;
  this->Unlock(this);
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x100AF9B0
// Name: public: unsigned int CDataManagerBase::EnsureCapacity(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::EnsureCapacity(CDataManagerBase *this, unsigned int size)
{
  unsigned int m_memUsed; // ecx
  unsigned int m_targetMemorySize; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  int m_Head; // edi
  void *v7; // edi
  unsigned int nBytesInitial; // [esp+Ch] [ebp-4h]

  nBytesInitial = this->m_memUsed;
  while ( 1 )
  {
    m_memUsed = this->m_memUsed;
    m_targetMemorySize = this->m_targetMemorySize;
    if ( m_memUsed <= m_targetMemorySize && m_targetMemorySize - m_memUsed >= size )
      break;
    this->Lock(this);
    m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
    m_Head = m_pMemory[this->m_lruList].m_Element.m_Head;
    if ( m_Head == 0xFFFF )
    {
      this->Unlock(this);
      return nBytesInitial - this->m_memUsed;
    }
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      elem: m_pMemory[this->m_lruList].m_Element.m_Head);
    v7 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
    this->Unlock(this);
    this->DestroyResourceStorage(this, a2: v7);
  }
  return nBytesInitial - this->m_memUsed;
}

//------------------------------------------------------------------------------
// Address: 0x100AFA40
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace vphysics

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10140ED0
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036E510
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x1036E5D0
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<watcher_t,unsigned short>::~CUtlMultiList<watcher_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x1036E5E0
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_6 < 1 )
      {
        ++_executeCount_6;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036E6B0
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14 + 1],
          src: (unsigned __int8 *)&destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x1036E8D0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10436290
// Name: _TheClientNextBots_::_2_::_dynamic_atexit_destructor_for__manager__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl TheClientNextBots_::_2_::_dynamic_atexit_destructor_for__manager__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&stru_1066CD34);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10197B60
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x1037DBA0
// Name: public: unsigned short CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  int m_FirstFree; // ecx
  int m_MaxElementIndex; // ecx
  int result; // eax
  int v5; // ecx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v6; // esi

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_13:
    v5 = (unsigned __int16)result;
    this->m_Memory.m_pMemory[v5].m_Previous = result;
    this->m_Memory.m_pMemory[v5].m_Next = result;
    ++this->m_TotalElements;
    v6 = &this->m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      *(_DWORD *)&v6->m_Element.lockCount = 0x10000;
      v6->m_Element.pStore = nullptr;
    }
    return result;
  }
  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (unsigned __int16)m_MaxElementIndex != m_MaxElementIndex || (_WORD)m_MaxElementIndex == 0xFFFF )
  {
    if ( `CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`9'::__executeCount < 10 )
    {
      ++`CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`9'::__executeCount;
      _Warning(a1: "CUtlMultiList overflow! (exhausted index range)\n");
    }
    return 0xFFFF;
  }
  if ( m_MaxElementIndex != this->m_Memory.m_nAllocationCount
    || (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
          num: 1),
        this->m_pElements = this->m_Memory.m_pMemory,
        (m_MaxElementIndex = this->m_MaxElementIndex) < this->m_Memory.m_nAllocationCount) )
  {
    result = LOWORD(this->m_MaxElementIndex);
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
    goto LABEL_13;
  }
  if ( `CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc'::`19'::__executeCount;
  _Warning(a1: "CUtlMultiList overflow! (exhausted memory allocator)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1037DE00
// Name: protected: struct memhandle_t__ __near * CDataManagerBase::StoreResourceInHandle(unsigned short,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataManagerBase::StoreResourceInHandle(
        CDataManagerBase *this,
        unsigned __int16 memoryIndex,
        void *pStore,
        unsigned int realSize)
{
  int v5; // eax
  int v6; // edi

  this->Lock(this);
  v5 = memoryIndex;
  this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.pStore = pStore;
  this->m_memUsed += realSize;
  v6 = this->m_memoryLists.m_Memory.m_pMemory[v5].m_Element.serial << 16;
  this->Unlock(this);
  return (memhandle_t__ *)(v6 | (unsigned __int16)(memoryIndex + 1));
}

//------------------------------------------------------------------------------
// Address: 0x1037DE50
// Name: public: void CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v10; // esi
  unsigned __int16 v11; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = v4;
    v6 = this->m_Memory.m_pMemory[v5].m_Previous == elem;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( !v6 )
    {
      m_Previous = v7->m_Previous;
      m_Next = v7->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v10 = v7->m_Next;
      v11 = v7->m_Previous;
      if ( (_WORD)v10 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v11;
      else
        this->m_Memory.m_pMemory[v10].m_Previous = v11;
      v7->m_Next = elem;
      v7->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037DFA0
// Name: protected: virtual CDataManagerBase::~CDataManagerBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::~CDataManagerBase(CDataManagerBase *this)
{
  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  CUtlMultiList<watcher_t,unsigned short>::~CUtlMultiList<watcher_t,unsigned short>(this: &this->m_memoryLists);
}

//------------------------------------------------------------------------------
// Address: 0x1037DFB0
// Name: protected: void __near * CDataManagerBase::LockResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::LockResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  _WORD *v7; // edx
  int v8; // edi
  memhandle_t__ *handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  v5 = (unsigned int)handle >> 16;
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (v6 = 12 * v4,
        v7 = (unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6),
        handlea = (memhandle_t__ *)v6,
        v7[4] == v3)
    && v7[5] != v3
    || v7[1] != (_WORD)v5
    || v3 == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( *v7 == 0 )
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        elem: v3);
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list: this->m_lockList,
        before: 0xFFFFu,
        elem: v3);
      v6 = (int)handlea;
    }
    ++*(unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6);
    v8 = *(int *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.pStore + v6);
    this->Unlock(this);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037E060
// Name: public: int CDataManagerBase::BreakLock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::BreakLock(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // bx
  int v4; // eax
  int v5; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v6; // edx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v7; // eax
  int lockCount; // ecx
  int nBroken; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 < this->m_memoryLists.m_MaxElementIndex
    && ((v5 = v4, (v6 = &this->m_memoryLists.m_Memory.m_pMemory[v5])->m_Previous != v3) || v6->m_Next == v3)
    && v6->m_Element.serial == HIWORD(handle)
    && (_WORD)handle != 0
    && v6->m_Element.lockCount != 0 )
  {
    v7 = &this->m_memoryLists.m_Memory.m_pMemory[v5];
    lockCount = v7->m_Element.lockCount;
    v7->m_Element.lockCount = 0;
    nBroken = lockCount;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lockList,
      elem: v3);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      before: 0xFFFFu,
      elem: v3);
    this->Unlock(this);
    return nBroken;
  }
  else
  {
    this->Unlock(this);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037E110
// Name: protected: void __near * CDataManagerBase::GetForFreeByIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataManagerBase::GetForFreeByIndex(CDataManagerBase *this, unsigned __int16 memoryIndex)
{
  void *result; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v4; // edi
  unsigned int v5; // eax
  unsigned int m_memUsed; // ecx
  void *pStore; // eax
  void *p; // [esp+4h] [ebp-4h]

  result = nullptr;
  if ( memoryIndex != 0xFFFF )
  {
    v4 = &this->m_memoryLists.m_Memory.m_pMemory[memoryIndex];
    v5 = this->GetRealSize(this, a2: v4->m_Element.pStore);
    m_memUsed = this->m_memUsed;
    if ( v5 > m_memUsed )
    {
      if ( _executeCount_5 < 1 )
      {
        ++_executeCount_5;
        _Warning(a1: "Data manager 'used' memory incorrect\n");
      }
      m_memUsed = this->m_memUsed;
      v5 = m_memUsed;
    }
    this->m_memUsed = m_memUsed - v5;
    pStore = v4->m_Element.pStore;
    ++v4->m_Element.serial;
    v4->m_Element.pStore = nullptr;
    p = pStore;
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      before: 0xFFFFu,
      elem: memoryIndex);
    return p;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1037E1E0
// Name: public: unsigned int CDataManagerBase::FlushAll(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::FlushAll(CDataManagerBase *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // ebx
  void *v4; // esp
  int m_Head; // ebx
  unsigned int m_memUsed; // ecx
  int m_Size; // edi
  int v8; // ebx
  void **v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  unsigned __int16 v13; // ax
  int v14; // ebx
  void **v15; // ecx
  int *v16; // ebx
  void (__thiscall *Unlock)(CDataManagerBase *); // eax
  int v18; // ebx
  int i; // edi
  unsigned __int16 m_lruList; // [esp-8h] [ebp-38h]
  unsigned __int16 m_lockList; // [esp-8h] [ebp-38h]
  _BYTE v23[12]; // [esp+0h] [ebp-30h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > destroyList; // [esp+Ch] [ebp-24h] BYREF
  int nFlush; // [esp+20h] [ebp-10h]
  unsigned int v26; // [esp+24h] [ebp-Ch]
  int node; // [esp+28h] [ebp-8h]
  int nextNode; // [esp+2Ch] [ebp-4h]

  this->Lock(this);
  m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_lruList];
  nFlush = v3->m_Element.m_Count + m_pMemory[this->m_lockList].m_Element.m_Count;
  v4 = alloca((4 * nFlush + 15) & 0x1FFFF0);
  m_Head = v3->m_Element.m_Head;
  m_memUsed = this->m_memUsed;
  destroyList.m_Memory.m_nAllocationCount = nFlush;
  m_Size = 0;
  destroyList.m_Memory.m_pMemory = (void **)v23;
  destroyList.m_Memory.m_nGrowSize = -1;
  destroyList.m_Size = 0;
  destroyList.m_pElements = (void **)v23;
  v26 = m_memUsed;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_lruList = this->m_lruList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lruList,
        elem: m_Head);
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
      v8 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v9 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: &destroyList.m_Memory.m_pMemory[v8 + 1],
          src: &destroyList.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = destroyList.m_Memory.m_pMemory;
      }
      v10 = (int *)&v9[v8];
      if ( v10 != nullptr )
        *v10 = node;
      LOWORD(m_Head) = nextNode;
    }
    while ( nextNode != 0xFFFF );
  }
  v11 = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_lockList].m_Element.m_Head;
  node = v11;
  if ( v11 != 0xFFFF )
  {
    while ( 1 )
    {
      v12 = (unsigned __int16)v11;
      m_lockList = this->m_lockList;
      nextNode = this->m_memoryLists.m_Memory.m_pMemory[v12].m_Next;
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: m_lockList,
        elem: v11);
      v13 = node;
      this->m_memoryLists.m_Memory.m_pMemory[v12].m_Element.lockCount = 0;
      node = (int)CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v13);
      v14 = m_Size;
      if ( m_Size + 1 > destroyList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&destroyList,
          num: m_Size - destroyList.m_Memory.m_nAllocationCount + 1);
        m_Size = destroyList.m_Size;
      }
      v15 = destroyList.m_Memory.m_pMemory;
      destroyList.m_Size = ++m_Size;
      destroyList.m_pElements = destroyList.m_Memory.m_pMemory;
      if ( m_Size - v14 - 1 > 0 )
      {
        _V_memmove(
          dest: &destroyList.m_Memory.m_pMemory[v14 + 1],
          src: &destroyList.m_Memory.m_pMemory[v14],
          count: 4 * (m_Size - v14 - 1));
        v15 = destroyList.m_Memory.m_pMemory;
      }
      v16 = (int *)&v15[v14];
      if ( v16 != nullptr )
        *v16 = node;
      node = nextNode;
      if ( nextNode == 0xFFFF )
        break;
      LOWORD(v11) = node;
    }
  }
  Unlock = this->Unlock;
  *((_WORD *)this + 37) &= ~1u;
  Unlock(this);
  v18 = nFlush;
  for ( i = 0; i < v18; ++i )
    this->DestroyResourceStorage(this, a2: destroyList.m_Memory.m_pMemory[i]);
  if ( destroyList.m_Memory.m_nGrowSize >= 0 && destroyList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: destroyList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x1037E400
// Name: public: void CDataManagerBase::DestroyResource(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManagerBase::DestroyResource(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // cx
  int v4; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edi
  int v6; // eax
  bool v7; // zf
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax
  unsigned __int16 v9; // di
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v10; // eax
  void *v11; // edi

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (m_pMemory = this->m_memoryLists.m_Memory.m_pMemory,
        v6 = v4,
        v7 = m_pMemory[v6].m_Previous == v3,
        v8 = &m_pMemory[v6],
        v7)
    && v8->m_Next != v3
    || (v9 = (_WORD)handle - 1, v8->m_Element.serial != HIWORD(handle)) )
  {
    v9 = -1;
  }
  if ( v9 < this->m_memoryLists.m_MaxElementIndex
    && ((v10 = &this->m_memoryLists.m_Memory.m_pMemory[v9])->m_Previous != v9 || v10->m_Next == v9) )
  {
    if ( v10->m_Element.lockCount != 0 )
      CDataManagerBase::BreakLock(this, handle);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      elem: v9);
    v11 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: v9);
    this->Unlock(this);
    this->DestroyResourceStorage(this, a2: v11);
  }
  else
  {
    this->Unlock(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037E4C0
// Name: protected: void __near * CDataManagerBase::GetResource_NoLock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::GetResource_NoLock(CDataManagerBase *this, memhandle_t__ *handle)
{
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  _WORD *v7; // edx
  int v8; // edi
  memhandle_t__ *handlea; // [esp+14h] [ebp+8h]

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  v5 = (unsigned int)handle >> 16;
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (v6 = 12 * v4,
        v7 = (unsigned __int16 *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.lockCount + v6),
        handlea = (memhandle_t__ *)v6,
        v7[4] == v3)
    && v7[5] != v3
    || v7[1] != (_WORD)v5
    || v3 == 0xFFFF )
  {
    this->Unlock(this);
    return 0;
  }
  else
  {
    if ( *v7 == 0 )
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        elem: v3);
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list: this->m_lruList,
        before: 0xFFFFu,
        elem: v3);
      v6 = (int)handlea;
    }
    v8 = *(int *)((char *)&this->m_memoryLists.m_Memory.m_pMemory->m_Element.pStore + v6);
    this->Unlock(this);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037E570
// Name: protected: unsigned short CDataManagerBase::CreateHandle(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDataManagerBase::CreateHandle(CDataManagerBase *this, bool bCreateLocked)
{
  int m_Head; // ebx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *p_m_memoryLists; // esi
  unsigned __int16 v5; // ax
  int v6; // ebx
  __int16 v7; // ax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // eax
  unsigned __int16 list; // [esp+Ch] [ebp-4h]

  this->Lock(this);
  m_Head = this->m_memoryLists.m_List.m_Memory.m_pMemory[this->m_freeList].m_Element.m_Head;
  if ( bCreateLocked )
    list = this->m_lockList;
  else
    list = this->m_lruList;
  p_m_memoryLists = &this->m_memoryLists;
  if ( m_Head == 0xFFFF )
  {
    v5 = CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Alloc(this: &this->m_memoryLists);
    v6 = v5;
    if ( v5 == 0xFFFF )
    {
      v7 = -1;
    }
    else
    {
      CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
        this: &this->m_memoryLists,
        list,
        before: 0xFFFFu,
        elem: v5);
      v8 = &p_m_memoryLists->m_Memory.m_pMemory[v6];
      if ( v8 != nullptr )
      {
        *(_DWORD *)&v8->m_Element.lockCount = 0x10000;
        v8->m_Element.pStore = nullptr;
      }
      v7 = v6;
    }
    LOWORD(m_Head) = v7;
  }
  else
  {
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_freeList,
      elem: m_Head);
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
      this: &this->m_memoryLists,
      list,
      before: 0xFFFFu,
      elem: m_Head);
  }
  if ( bCreateLocked )
    ++p_m_memoryLists->m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Element.lockCount;
  this->Unlock(this);
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x1037E640
// Name: public: unsigned int CDataManagerBase::EnsureCapacity(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManagerBase::EnsureCapacity(CDataManagerBase *this, unsigned int size)
{
  unsigned int m_memUsed; // ecx
  unsigned int m_targetMemorySize; // eax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  int m_Head; // edi
  void *v7; // edi
  unsigned int nBytesInitial; // [esp+Ch] [ebp-4h]

  nBytesInitial = this->m_memUsed;
  while ( 1 )
  {
    m_memUsed = this->m_memUsed;
    m_targetMemorySize = this->m_targetMemorySize;
    if ( m_memUsed <= m_targetMemorySize && m_targetMemorySize - m_memUsed >= size )
      break;
    this->Lock(this);
    m_pMemory = this->m_memoryLists.m_List.m_Memory.m_pMemory;
    m_Head = m_pMemory[this->m_lruList].m_Element.m_Head;
    if ( m_Head == 0xFFFF )
    {
      this->Unlock(this);
      return nBytesInitial - this->m_memUsed;
    }
    CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
      this: &this->m_memoryLists,
      list: this->m_lruList,
      elem: m_pMemory[this->m_lruList].m_Element.m_Head);
    v7 = CDataManagerBase::GetForFreeByIndex(this, memoryIndex: m_Head);
    this->Unlock(this);
    this->DestroyResourceStorage(this, a2: v7);
  }
  return nBytesInitial - this->m_memUsed;
}

//------------------------------------------------------------------------------
// Address: 0x1037E6D0
// Name: protected: CDataManagerBase::CDataManagerBase(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDataManagerBase *__thiscall CDataManagerBase::CDataManagerBase(CDataManagerBase *this, unsigned int maxSize)
{
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  unsigned __int16 v6; // cx
  int v7; // eax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // bx
  unsigned __int16 v12; // cx
  int v13; // eax

  this->__vftable = (CDataManagerBase_vtbl *)&CDataManagerBase::`vftable';
  this->m_memoryLists.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_Memory.m_pMemory = nullptr;
  this->m_memoryLists.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_memoryLists.m_List.m_Memory.m_nGrowSize = 0;
  this->m_memoryLists.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_memoryLists.m_List.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_List.m_pElements = this->m_memoryLists.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_memoryLists.m_List.m_Head = -1;
  this->m_memoryLists.m_List.m_NumAlloced = 0;
  m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
  this->m_memoryLists.m_pElementList = nullptr;
  *(_DWORD *)&this->m_memoryLists.m_FirstFree = 0xFFFF;
  this->m_memoryLists.m_MaxElementIndex = 0;
  this->m_memoryLists.m_pElements = m_pMemory;
  this->m_targetMemorySize = maxSize;
  this->m_memUsed = 0;
  v4 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  v5 = v4;
  if ( v4 == 0xFFFF )
  {
    v6 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v4);
    v6 = v5;
  }
  v7 = v6;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v7].m_Element.m_Count = 0;
  this->m_lruList = v6;
  v8 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_memoryLists.m_List,
         multilist: false);
  if ( v8 == 0xFFFF )
  {
    v9 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v8);
    v9 = v8;
  }
  v10 = v9;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
  this->m_memoryLists.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
  this->m_lockList = v9;
  v11 = CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_memoryLists.m_List,
          multilist: false);
  if ( v11 == 0xFFFF )
  {
    v12 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &this->m_memoryLists.m_List,
      before: 0xFFFFu,
      elem: v11);
    v12 = v11;
  }
  v13 = 10 * v12;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Tail + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Head + v13) = -1;
  *(unsigned __int16 *)((char *)&this->m_memoryLists.m_List.m_Memory.m_pMemory->m_Element.m_Count + v13) = 0;
  LOWORD(v13) = *((_WORD *)this + 37);
  this->m_freeList = v12;
  *((_WORD *)this + 37) = v13 & 0xFFFC | 2;
  return this;
}

} // namespace server
