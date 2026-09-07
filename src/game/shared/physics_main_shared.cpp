// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/physics_main_shared.cpp
// Functions: 79
// ============================================================

#include "game\shared\physics_main_shared.h"

//------------------------------------------------------------------------------
// Address: 0x1007AFE0
// Name: public: unsigned short CUtlMultiList<class CPixelVisSet,unsigned short>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<CPixelVisSet,unsigned short>::Alloc(CUtlMultiList<CPixelVisSet,unsigned short> *this)
{
  int m_FirstFree; // ecx
  int m_MaxElementIndex; // ecx
  int result; // eax
  int v5; // ecx
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *v6; // esi

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
      v6->m_Element.serial = 0;
      v6->m_Element.frameIssued = 0;
      v6->m_Element.queryList = -1;
      v6->m_Element.sizeIsScreenSpace = false;
    }
    return result;
  }
  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (unsigned __int16)m_MaxElementIndex != m_MaxElementIndex || (_WORD)m_MaxElementIndex == 0xFFFF )
  {
    if ( `CUtlMultiList<CPixelVisSet,unsigned short>::Alloc'::`9'::__executeCount < 10 )
    {
      ++`CUtlMultiList<CPixelVisSet,unsigned short>::Alloc'::`9'::__executeCount;
      _Warning(a1: "CUtlMultiList overflow! (exhausted index range)\n");
    }
    return 0xFFFF;
  }
  if ( m_MaxElementIndex != this->m_Memory.m_nAllocationCount
    || (CUtlMemory<vgui::AnimationController::AnimSequence_t,int>::Grow(
          (CUtlMemory<vgui::AnimationController::AnimSequence_t,int> *)this,
          num: 1),
        this->m_pElements = this->m_Memory.m_pMemory,
        (m_MaxElementIndex = this->m_MaxElementIndex) < this->m_Memory.m_nAllocationCount) )
  {
    result = LOWORD(this->m_MaxElementIndex);
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
    goto LABEL_13;
  }
  if ( `CUtlMultiList<CPixelVisSet,unsigned short>::Alloc'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlMultiList<CPixelVisSet,unsigned short>::Alloc'::`19'::__executeCount;
  _Warning(a1: "CUtlMultiList overflow! (exhausted memory allocator)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1007B0D0
// Name: public: void CUtlMultiList<class CPixelVisSet,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CPixelVisSet,unsigned short>::RemoveAll(CUtlMultiList<CPixelVisSet,unsigned short> *this)
{
  int m_MaxElementIndex; // edi
  int v2; // edi
  unsigned __int16 i; // bx
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
// Address: 0x1007B970
// Name: public: void CUtlMultiList<class CPixelVisSet,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CPixelVisSet,unsigned short>::Unlink(
        CUtlMultiList<CPixelVisSet,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  bool v5; // zf
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *v6; // eax
  int m_Previous; // esi
  int m_Next; // esi
  unsigned __int16 v9; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = this->m_Memory.m_pMemory[v4].m_Previous == elem;
    v6 = &this->m_Memory.m_pMemory[v4];
    if ( !v5 )
    {
      m_Previous = v6->m_Previous;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = v6->m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = v6->m_Next;
      m_Next = v6->m_Next;
      v9 = v6->m_Previous;
      if ( (_WORD)m_Next == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v9;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = v9;
      v6->m_Next = elem;
      v6->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007BA40
// Name: public: void CUtlMultiList<class CPixelVisibilityQuery,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Unlink(
        CUtlMultiList<CPixelVisibilityQuery,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *v7; // eax
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
// Address: 0x1007BB00
// Name: public: void CUtlMultiList<class CPixelVisSet,unsigned short>::LinkAfter(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CPixelVisSet,unsigned short>::LinkAfter(
        CUtlMultiList<CPixelVisSet,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *v7; // eax
  int m_Next; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CPixelVisSet,unsigned short>::Unlink(this, list, elem);
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
// Address: 0x1007BBD0
// Name: public: void CUtlMultiList<class CPixelVisibilityQuery,unsigned short>::LinkAfter(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CPixelVisibilityQuery,unsigned short>::LinkAfter(
        CUtlMultiList<CPixelVisibilityQuery,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *v7; // eax
  int m_Next; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Unlink(this, list, elem);
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
// Address: 0x1007BF70
// Name: public: CUtlMultiList<class CPixelVisSet,unsigned short>::~CUtlMultiList<class CPixelVisSet,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CPixelVisSet,unsigned short>::~CUtlMultiList<CPixelVisSet,unsigned short>(
        CUtlMultiList<CPixelVisSet,unsigned short> *this)
{
  CUtlMultiList<CPixelVisSet,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List);
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
// Address: 0x1007BFF0
// Name: public: void CUtlMultiList<class CPixelVisSet,unsigned short>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CPixelVisSet,unsigned short>::Purge(CUtlMultiList<CPixelVisSet,unsigned short> *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short> *m_pMemory; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short> *v3; // ecx
  CUtlMultiList<CPixelVisSet,unsigned short>::ListElem_t *v4; // ecx

  CUtlMultiList<CPixelVisSet,unsigned short>::RemoveAll(this);
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  this->m_List.m_FirstFree = -1;
  m_pMemory = this->m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_List.m_NumAlloced = -65536;
  this->m_List.m_pElements = m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  this->m_List.m_FirstFree = -1;
  v3 = this->m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_List.m_NumAlloced = -65536;
  this->m_List.m_pElements = v3;
  v4 = this->m_Memory.m_pMemory;
  this->m_MaxElementIndex = 0;
  *(_DWORD *)&this->m_FirstFree = 0xFFFF;
  this->m_pElements = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1007C0B0
// Name: public: unsigned short CUtlMultiList<class CPixelVisibilityQuery,unsigned short>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Alloc(
        CUtlMultiList<CPixelVisibilityQuery,unsigned short> *this)
{
  int m_FirstFree; // eax
  int m_MaxElementIndex; // eax
  unsigned __int16 v5; // di
  int v6; // eax
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *m_pMemory; // ecx
  CPixelVisibilityQuery *p_m_Element; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    v5 = this->m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
    goto LABEL_13;
  }
  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (unsigned __int16)m_MaxElementIndex != m_MaxElementIndex || (_WORD)m_MaxElementIndex == 0xFFFF )
  {
    if ( `CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Alloc'::`9'::__executeCount < 10 )
    {
      ++`CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Alloc'::`9'::__executeCount;
      _Warning(a1: "CUtlMultiList overflow! (exhausted index range)\n");
    }
    return -1;
  }
  if ( m_MaxElementIndex != this->m_Memory.m_nAllocationCount
    || (CUtlMemory<SaveRestoreBlockHeader_t,int>::Grow((CUtlMemory<C_AnimationLayer,int> *)this, num: 1),
        m_MaxElementIndex = this->m_MaxElementIndex,
        this->m_pElements = this->m_Memory.m_pMemory,
        m_MaxElementIndex < this->m_Memory.m_nAllocationCount) )
  {
    v5 = this->m_MaxElementIndex;
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
LABEL_13:
    v6 = v5;
    this->m_Memory.m_pMemory[v6].m_Previous = v5;
    this->m_Memory.m_pMemory[v6].m_Next = v5;
    m_pMemory = this->m_Memory.m_pMemory;
    ++this->m_TotalElements;
    p_m_Element = &m_pMemory[v6].m_Element;
    if ( p_m_Element != nullptr )
      CPixelVisibilityQuery::CPixelVisibilityQuery(this: p_m_Element);
    return v5;
  }
  if ( `CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Alloc'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Alloc'::`19'::__executeCount;
  _Warning(a1: "CUtlMultiList overflow! (exhausted memory allocator)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1007C310
// Name: public: void CUtlMultiList<class CPixelVisibilityQuery,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CPixelVisibilityQuery,unsigned short>::RemoveAll(
        CUtlMultiList<CPixelVisibilityQuery,unsigned short> *this)
{
  int m_MaxElementIndex; // eax
  int v3; // eax
  unsigned __int16 v4; // bx
  int v5; // edi
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *v6; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // ecx
  bool v9; // sf
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short> *m_pMemory; // ecx
  int v12; // eax
  int i; // [esp+4h] [ebp-10h]
  unsigned __int16 prev; // [esp+8h] [ebp-Ch]
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *v15; // [esp+Ch] [ebp-8h]
  IMatRenderContext *v16; // [esp+10h] [ebp-4h]

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v3 = m_MaxElementIndex - 1;
    prev = -1;
    i = v3;
    if ( v3 >= 0 )
    {
      do
      {
        v4 = v3;
        v5 = (unsigned __int16)v3;
        if ( (unsigned __int16)v3 < this->m_MaxElementIndex )
        {
          v6 = &this->m_Memory.m_pMemory[(unsigned __int16)v3];
          v15 = v6;
          if ( v6->m_Previous != v4 || v6->m_Next == v4 )
          {
            v7 = materials->GetRenderContext(this: materials);
            v8 = v7;
            v16 = v7;
            if ( v7 != nullptr )
            {
              v7->BeginRender(this: v7);
              v8 = v16;
            }
            if ( v15->m_Element.m_queryHandle != nullptr )
            {
              v8->DestroyOcclusionQueryObject(this: v8, a2: v15->m_Element.m_queryHandle);
              v8 = v16;
            }
            if ( v15->m_Element.m_queryHandleCount != nullptr )
            {
              v8->DestroyOcclusionQueryObject(this: v8, a2: v15->m_Element.m_queryHandleCount);
              v8 = v16;
            }
            if ( v8 != nullptr )
            {
              v8->EndRender(this: v8);
              v16->Release(this: v16);
            }
          }
        }
        v3 = 40 * v5;
        *(unsigned __int16 *)((char *)&this->m_Memory.m_pMemory->m_Next + v3) = prev;
        *(unsigned __int16 *)((char *)&this->m_Memory.m_pMemory->m_Previous + v3) = v4;
        LOWORD(v3) = i - 1;
        v9 = i - 1 < 0;
        prev = v4;
        --i;
      }
      while ( !v9 );
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v12 = m_Head;
        m_pMemory[v12].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v12].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v12].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v12].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C620
// Name: public: CUtlMultiList<class CPixelVisibilityQuery,unsigned short>::~CUtlMultiList<class CPixelVisibilityQuery,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CPixelVisibilityQuery,unsigned short>::~CUtlMultiList<CPixelVisibilityQuery,unsigned short>(
        CUtlMultiList<CPixelVisibilityQuery,unsigned short> *this)
{
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List);
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
// Address: 0x1007C6A0
// Name: public: void CUtlMultiList<class CPixelVisibilityQuery,unsigned short>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CPixelVisibilityQuery,unsigned short>::Purge(
        CUtlMultiList<CPixelVisibilityQuery,unsigned short> *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short> *m_pMemory; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short> *v3; // ecx
  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::ListElem_t *v4; // ecx

  CUtlMultiList<CPixelVisibilityQuery,unsigned short>::RemoveAll(this);
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  this->m_List.m_FirstFree = -1;
  m_pMemory = this->m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_List.m_NumAlloced = -65536;
  this->m_List.m_pElements = m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  this->m_List.m_FirstFree = -1;
  v3 = this->m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_List.m_NumAlloced = -65536;
  this->m_List.m_pElements = v3;
  v4 = this->m_Memory.m_pMemory;
  this->m_MaxElementIndex = 0;
  *(_DWORD *)&this->m_FirstFree = 0xFFFF;
  this->m_pElements = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1007C760
// Name: public: unsigned short CUtlMultiList<class CPixelVisibilityQuery,unsigned short>::CreateList(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<CPixelVisibilityQuery,unsigned short>::CreateList(
        CUtlMultiList<CPixelVisibilityQuery,unsigned short> *this)
{
  CUtlLinkedList<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short> > *p_m_List; // esi
  int v2; // edi
  int result; // eax
  int v4; // ecx

  p_m_List = &this->m_List;
  v2 = (unsigned __int16)CUtlLinkedList<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
                           this: &this->m_List,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)p_m_List,
      before: 0xFFFFu,
      elem: v2);
    result = v2;
  }
  v4 = (unsigned __int16)result;
  p_m_List->m_Memory.m_pMemory[v4].m_Element.m_Tail = -1;
  p_m_List->m_Memory.m_pMemory[v4].m_Element.m_Head = -1;
  p_m_List->m_Memory.m_pMemory[v4].m_Element.m_Count = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A6D40
// Name: public: void CUtlMemory<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
        CUtlMemory<vgui::PropertySheet::Page_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::PropertySheet::Page_t *m_pMemory; // edx
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
      this->m_pMemory = (vgui::PropertySheet::Page_t *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v7);
    else
      this->m_pMemory = (vgui::PropertySheet::Page_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FBA0
// Name: public: bool C_BaseEntity::HasDataObjectType(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::HasDataObjectType(C_BaseEntity *this, char type)
{
  return ((1 << type) & this->m_fDataObjectTypes) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013FBC0
// Name: struct touchlink_t __near * AllocTouchLink(void)
// Source: json
//------------------------------------------------------------------------------
touchlink_t *__cdecl AllocTouchLink()
{
  touchlink_t *result; // eax

  result = (touchlink_t *)CUtlMemoryPool::Alloc(this: &g_EdictTouchLinks, amount: 0x14u);
  if ( result != nullptr )
  {
    ++linksallocated;
  }
  else
  {
    DevWarning(a1: "AllocTouchLink: failed to allocate touchlink_t.\n");
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013FBF0
// Name: public: virtual bool C_BaseEntity::IsCurrentlyTouching(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsCurrentlyTouching(C_BaseEntity *this)
{
  return (this->m_fDataObjectTypes & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013FC00
// Name: public: static class CGameTrace const __near & C_BaseEntity::GetTouchTrace(void)
// Source: json
//------------------------------------------------------------------------------
const CGameTrace *__cdecl C_BaseEntity::GetTouchTrace()
{
  return &g_TouchTrace;
}

//------------------------------------------------------------------------------
// Address: 0x1013FC10
// Name: private: static bool CThinkSyncTester::ThinkLessFunc(struct ThinkSync const __near &,struct ThinkSync const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CThinkSyncTester::ThinkLessFunc(const ThinkSync *item1, const ThinkSync *item2)
{
  return item2->thinktime > item1->thinktime;
}

//------------------------------------------------------------------------------
// Address: 0x1013FC40
// Name: public: void C_BaseEntity::DestroyAllDataObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::DestroyAllDataObjects(C_BaseEntity *this)
{
  int v2; // esi
  int v3; // edi
  IEntityDataInstantiator *v4; // ecx

  v2 = 0;
  v3 = 1;
  do
  {
    if ( (v3 & this->m_fDataObjectTypes) != 0 )
    {
      if ( (unsigned int)v2 <= 0x1F )
      {
        v4 = g_DataObjectAccessSystem.m_Accessors[v2];
        if ( v4 != nullptr )
          v4->DestroyDataObject(this: v4, a2: this);
      }
      this->m_fDataObjectTypes &= ~v3;
    }
    ++v2;
    v3 = __ROL4__(v3, 1);
  }
  while ( v2 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x1013FC90
// Name: public: static void C_BaseEntity::PhysicsRemoveToucher(class C_BaseEntity __near *,struct touchlink_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::PhysicsRemoveToucher(C_BaseEntity *otherEntity, touchlink_t *link)
{
  if ( (link->flags & 1) != 0 && link->entityTouched != nullptr && otherEntity != nullptr )
    otherEntity->EndTouch(this: otherEntity, a2: link->entityTouched);
  link->nextLink->prevLink = link->prevLink;
  link->prevLink->nextLink = link->nextLink;
  if ( link == g_pNextLink )
    g_pNextLink = link->nextLink;
  --linksallocated;
  link->nextLink = nullptr;
  link->prevLink = nullptr;
  CUtlMemoryPool::Free(this: &g_EdictTouchLinks, memBlock: link);
}

//------------------------------------------------------------------------------
// Address: 0x1013FD00
// Name: public: void C_BaseEntity::PhysicsTouch(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsTouch(C_BaseEntity *this, C_BaseEntity *pentOther)
{
  if ( pentOther != nullptr && (this->m_iEFlags & 1) == 0 && (pentOther->m_iEFlags & 1) == 0 )
    this->Touch(this, a2: pentOther);
}

//------------------------------------------------------------------------------
// Address: 0x1013FD30
// Name: public: void C_BaseEntity::PhysicsStartTouch(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsStartTouch(C_BaseEntity *this, C_BaseEntity *pentOther)
{
  if ( pentOther != nullptr && (this->m_iEFlags & 1) == 0 && (pentOther->m_iEFlags & 1) == 0 )
  {
    this->StartTouch(this, a2: pentOther);
    this->Touch(this, a2: pentOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FD70
// Name: private: void C_BaseEntity::UpdateWaterState(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BaseEntity::UpdateWaterState(C_BaseEntity *this@<ecx>, int a2@<esi>)
{
  __int16 v3; // ax
  float m_flRadius; // xmm0_4
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  Vector in; // [esp+0h] [ebp-18h] BYREF
  Vector point; // [esp+Ch] [ebp-Ch] BYREF

  in.x = 0.5;
  in.y = 0.5;
  in.z = 0.0;
  CCollisionProperty::NormalizedToWorldSpace(this: &this->m_Collision, &in, pResult: &point);
  this->m_nWaterLevel = 0;
  C_BaseEntity::SetWaterType(this, nType: 0);
  v3 = ((int (__thiscall *)(IEngineTrace *, Vector *, int, int))enginetrace->GetPointContents_WorldOnly)(
         a1: enginetrace,
         a2: &point,
         a3: 16432,
         a4: a2);
  if ( (v3 & 0x4030) != 0 )
  {
    C_BaseEntity::SetWaterType(this, nType: v3);
    m_flRadius = this->m_Collision.m_flRadius;
    this->m_nWaterLevel = 1;
    if ( m_flRadius == 0.0
      || (point.z = this->WorldSpaceCenter(this)->z,
          (enginetrace->GetPointContents_WorldOnly(this: enginetrace, a2: &point, a3: 16432) & 0x4030) != 0)
      && (EyePosition = this->EyePosition,
          this->m_nWaterLevel = 2,
          point.z = EyePosition(this, result: &in)->z,
          (enginetrace->GetPointContents_WorldOnly(this: enginetrace, a2: &point, a3: 16432) & 0x4030) != 0) )
    {
      this->m_nWaterLevel = 3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FE80
// Name: public: bool C_BaseEntity::PhysicsCheckWater(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseEntity::PhysicsCheckWater(C_BaseEntity *this)
{
  return this->m_nWaterLevel > 1u;
}

//------------------------------------------------------------------------------
// Address: 0x1013FE90
// Name: public: void C_BaseEntity::PhysicsCheckVelocity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsCheckVelocity(C_BaseEntity *this)
{
  char v2; // al
  int i; // ebx
  char *Classname; // eax
  char *v5; // eax
  float v6; // xmm1_4
  float m_fValue; // xmm0_4
  Vector origin; // [esp+Ch] [ebp-18h] BYREF
  Vector vecAbsVelocity; // [esp+18h] [ebp-Ch] BYREF

  origin = *this->GetAbsOrigin(this);
  C_BaseEntity::CalcAbsoluteVelocity(this);
  vecAbsVelocity = this->m_vecAbsVelocity;
  v2 = 0;
  for ( i = 0; i < 12; i += 4 )
  {
    if ( (*(_DWORD *)((_BYTE *)&vecAbsVelocity.x + i) & 0x7F800000) == 0x7F800000 )
    {
      Classname = C_BaseEntity::GetClassname(this);
      _Msg(a1: "Got a NaN velocity on %s\n", Classname);
      *(float *)((char *)&vecAbsVelocity.x + i) = 0.0;
      v2 = 1;
    }
    if ( (*(_DWORD *)((_BYTE *)&origin.x + i) & 0x7F800000) == 0x7F800000 )
    {
      v5 = C_BaseEntity::GetClassname(this);
      _Msg(a1: "Got a NaN origin on %s\n", v5);
      *(float *)((char *)&origin.x + i) = 0.0;
      v2 = 1;
    }
    v6 = *(float *)((char *)&vecAbsVelocity.x + i);
    m_fValue = sv_maxvelocity.m_pParent->m_Value.m_fValue;
    if ( v6 <= m_fValue )
    {
      LODWORD(m_fValue) ^= _mask__NegFloat_;
      if ( m_fValue <= v6 )
        continue;
    }
    v2 = 1;
    *(float *)((char *)&vecAbsVelocity.x + i) = m_fValue;
  }
  if ( v2 != 0 )
  {
    C_BaseEntity::SetAbsOrigin(this, absOrigin: &origin);
    C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FFA0
// Name: public: void C_BaseEntity::PhysicsAddGravityMove(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsAddGravityMove(C_BaseEntity *this, Vector *move)
{
  float z; // eax
  unsigned int m_Index; // ecx
  float v5; // xmm0_4
  float m_flGravity; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  Vector vecAbsVelocity; // [esp+10h] [ebp-Ch] BYREF

  C_BaseEntity::CalcAbsoluteVelocity(this);
  z = this->m_vecAbsVelocity.z;
  m_Index = gpGlobals.m_Index;
  *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
  v5 = this->m_vecBaseVelocity.x + vecAbsVelocity.x;
  vecAbsVelocity.z = z;
  move->x = v5 * *(float *)(gpGlobals.m_Index + 16);
  move->y = (float)(this->m_vecBaseVelocity.y + vecAbsVelocity.y) * *(float *)(m_Index + 16);
  if ( (this->m_fFlags & 1) != 0 )
  {
    move->z = this->m_vecBaseVelocity.z * *(float *)(m_Index + 16);
  }
  else
  {
    m_flGravity = this->m_flGravity;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    v7 = *(float *)(m_Index + 16);
    v8 = (float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * v7;
    v9 = vecAbsVelocity.z - v8;
    move->z = (float)((float)((float)(vecAbsVelocity.z + (float)(vecAbsVelocity.z - v8)) * 0.5)
                    + this->m_vecBaseVelocity.z)
            * v7;
    *(_QWORD *)&this->m_vecBaseVelocity.x = *(_QWORD *)&this->m_vecBaseVelocity.x;
    this->m_vecBaseVelocity.z = 0.0;
    vecAbsVelocity.z = v9;
    C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
    C_BaseEntity::PhysicsCheckVelocity(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101400D0
// Name: public: bool C_BaseEntity::PhysicsRunSpecificThink(int,void (C_BaseEntity::*)(void))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::PhysicsRunSpecificThink(C_BaseEntity *this, int nContextIndex, __int128 thinkFunc)
{
  int NextThinkTick; // eax

  NextThinkTick = C_BaseEntity::GetNextThinkTick(this, nContextIndex);
  if ( NextThinkTick <= 0 || NextThinkTick > *(_DWORD *)(gpGlobals.m_Index + 24) )
    return true;
  C_BaseEntity::SetNextThink(this, nContextIndex, thinkTime: -1.0);
  C_BaseEntity::PhysicsDispatchThink(this, a2: (int)this, thinkFunc);
  C_BaseEntity::SetLastThink(this, nContextIndex, thinkTime: *(float *)(gpGlobals.m_Index + 12));
  return (this->m_iEFlags & 1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10140160
// Name: public: class C_BaseEntity __near * C_BaseEntity::GetGroundEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseEntity::GetGroundEntity(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hGroundEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101401C0
// Name: public: virtual void CDataObjectAccessSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataObjectAccessSystem::Shutdown(CDataObjectAccessSystem *this)
{
  IEntityDataInstantiator **m_Accessors; // esi
  int i; // edi

  m_Accessors = this->m_Accessors;
  for ( i = 32; i != 0; --i )
  {
    if ( *m_Accessors != nullptr )
      ((void (__thiscall *)(IEntityDataInstantiator *, int))(*m_Accessors)->dtr_IEntityDataInstantiator)(
        a1: *m_Accessors,
        a2: 1);
    *m_Accessors++ = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101401F0
// Name: private: static bool CEntityDataInstantiator<struct ModelScale>::CompareFunc(struct CEntityDataInstantiator<struct ModelScale>::HashEntry const __near &,struct CEntityDataInstantiator<struct ModelScale>::HashEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CEntityDataInstantiator<ModelScale>::CompareFunc(
        const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *src1,
        const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *src2)
{
  return src1->key == src2->key;
}

//------------------------------------------------------------------------------
// Address: 0x10140210
// Name: private: static unsigned int CEntityDataInstantiator<struct physicspushlist_t>::KeyFunc(struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CEntityDataInstantiator<physicspushlist_t>::KeyFunc(
        const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *src)
{
  return (unsigned int)src->key >> 10;
}

//------------------------------------------------------------------------------
// Address: 0x101402C0
// Name: public: static void C_BaseEntity::PhysicsNotifyOtherOfUntouch(class C_BaseEntity __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::PhysicsNotifyOtherOfUntouch(C_BaseEntity *ent, C_BaseEntity *other)
{
  touchlink_t *v2; // eax
  touchlink_t *v3; // esi
  touchlink_t *nextLink; // eax

  if ( other != nullptr && (other->m_fDataObjectTypes & 2) != 0 && g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
  {
    v2 = (touchlink_t *)g_DataObjectAccessSystem.m_Accessors[1]->GetDataObject(
                          this: g_DataObjectAccessSystem.m_Accessors[1],
                          a2: other);
    v3 = v2;
    if ( v2 != nullptr )
    {
      nextLink = v2->nextLink;
      if ( nextLink != v3 )
      {
        while ( nextLink->entityTouched != ent )
        {
          nextLink = nextLink->nextLink;
          if ( nextLink == v3 )
            return;
        }
        C_BaseEntity::PhysicsRemoveToucher(otherEntity: other, link: nextLink);
        if ( g_bCleanupDatObject && v3->nextLink == v3 && v3->prevLink == v3 && (other->m_fDataObjectTypes & 2) != 0 )
        {
          if ( g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
            g_DataObjectAccessSystem.m_Accessors[1]->DestroyDataObject(
              this: g_DataObjectAccessSystem.m_Accessors[1],
              a2: other);
          other->m_fDataObjectTypes &= ~2u;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140360
// Name: public: static void C_BaseEntity::PhysicsRemoveTouchedList(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::PhysicsRemoveTouchedList(C_BaseEntity *ent)
{
  touchlink_t *v2; // eax
  touchlink_t *nextLink; // esi
  touchlink_t *v4; // edi
  unsigned int v5; // edx
  touchlink_t *v6; // [esp+4h] [ebp-4h]
  bool saveCleanup_3; // [esp+13h] [ebp+Bh]

  if ( (ent->m_fDataObjectTypes & 2) != 0 )
  {
    if ( g_DataObjectAccessSystem.m_Accessors[1] != nullptr
      && (v2 = (touchlink_t *)g_DataObjectAccessSystem.m_Accessors[1]->GetDataObject(
                                this: g_DataObjectAccessSystem.m_Accessors[1],
                                a2: ent),
          v6 = v2,
          v2 != nullptr) )
    {
      nextLink = v2->nextLink;
      saveCleanup_3 = g_bCleanupDatObject;
      g_bCleanupDatObject = false;
      if ( nextLink != nullptr )
      {
        while ( nextLink != v2 )
        {
          v4 = nextLink->nextLink;
          C_BaseEntity::PhysicsNotifyOtherOfUntouch(ent, other: nextLink->entityTouched);
          if ( nextLink == g_pNextLink )
            g_pNextLink = nextLink->nextLink;
          --linksallocated;
          nextLink->nextLink = nullptr;
          nextLink->prevLink = nullptr;
          CUtlMemoryPool::Free(this: &g_EdictTouchLinks, memBlock: nextLink);
          nextLink = v4;
          if ( v4 == nullptr )
            break;
          v2 = v6;
        }
      }
      v5 = (unsigned int)ent->m_fDataObjectTypes >> 1;
      g_bCleanupDatObject = saveCleanup_3;
      if ( (v5 & 1) != 0 )
      {
        if ( g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
          g_DataObjectAccessSystem.m_Accessors[1]->DestroyDataObject(
            this: g_DataObjectAccessSystem.m_Accessors[1],
            a2: ent);
        ent->m_fDataObjectTypes &= ~2u;
      }
      ent->touchStamp = 0;
    }
    else
    {
      ent->touchStamp = 0;
    }
  }
  else
  {
    ent->touchStamp = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140460
// Name: public: static void C_BaseEntity::PhysicsRemoveGround(class C_BaseEntity __near *,struct groundlink_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::PhysicsRemoveGround(C_BaseEntity *other, groundlink_t *link)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  C_BaseEntity **v8; // eax
  C_BaseEntity *v9; // eax

  m_Index = link->entity.m_Index;
  if ( link->entity.m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
      {
        v9 = *v8;
        if ( v9 != nullptr && other != nullptr )
          C_BaseEntity::RemoveFlag(this: v9, flagsToRemove: 1);
      }
    }
  }
  link->nextLink->prevLink = link->prevLink;
  link->prevLink->nextLink = link->nextLink;
  --groundlinksallocated;
  CUtlMemoryPool::Free(this: &g_EntityGroundLinks, memBlock: link);
}

//------------------------------------------------------------------------------
// Address: 0x101404E0
// Name: public: struct touchlink_t __near * C_BaseEntity::PhysicsMarkEntityAsTouched(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
touchlink_t *__thiscall C_BaseEntity::PhysicsMarkEntityAsTouched(C_BaseEntity *this, C_BaseEntity *other)
{
  touchlink_t *result; // eax
  unsigned int m_Index; // eax
  C_BaseEntity *m_pEntity; // ecx
  unsigned int v6; // ecx
  C_BaseEntity *v7; // eax
  touchlink_t *v8; // eax
  touchlink_t *nextLink; // esi
  touchlink_t **p_nextLink; // ebx
  touchlink_t *v11; // eax
  int touchStamp; // eax
  touchlink_t *root; // [esp+8h] [ebp-4h]

  if ( this == other )
    return nullptr;
  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == other )
    return nullptr;
  v6 = other->m_pMoveParent.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  if ( this == v7
    || ((this->m_fFlags | other->m_fFlags) & 0x800000) != 0
    || (this->m_Collision.m_usSolidFlags.m_Value & 8) != 0
    && (other->m_Collision.m_usSolidFlags.m_Value & 8) != 0
    && !C_BaseEntity::IsSolid(this)
    && !C_BaseEntity::IsSolid(this: other)
    || (other->m_iEFlags & 1) != 0
    || (this->m_iEFlags & 1) != 0 )
  {
    return nullptr;
  }
  if ( (this->m_fDataObjectTypes & 2) != 0
    && (g_DataObjectAccessSystem.m_Accessors[1] != nullptr
      ? (v8 = (touchlink_t *)g_DataObjectAccessSystem.m_Accessors[1]->GetDataObject(
                               this: g_DataObjectAccessSystem.m_Accessors[1],
                               a2: this))
      : (v8 = nullptr),
        root = v8,
        v8 != nullptr) )
  {
    nextLink = v8->nextLink;
    p_nextLink = &v8->nextLink;
    if ( nextLink != v8 )
    {
      while ( nextLink->entityTouched != other )
      {
        nextLink = nextLink->nextLink;
        if ( nextLink == v8 )
          goto LABEL_35;
      }
      nextLink->touchStamp = this->touchStamp;
      if ( !C_BaseEntity::sm_bDisableTouchFuncs )
      {
        C_BaseEntity::PhysicsTouch(this, pentOther: other);
        return nextLink;
      }
      return nextLink;
    }
  }
  else
  {
    this->m_fDataObjectTypes |= 2u;
    if ( g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
      v11 = (touchlink_t *)g_DataObjectAccessSystem.m_Accessors[1]->CreateDataObject(
                             this: g_DataObjectAccessSystem.m_Accessors[1],
                             a2: this);
    else
      v11 = nullptr;
    p_nextLink = &v11->nextLink;
    root = v11;
    v11->prevLink = v11;
    v11->nextLink = v11;
  }
LABEL_35:
  result = AllocTouchLink();
  nextLink = result;
  if ( result == nullptr )
    return result;
  touchStamp = this->touchStamp;
  nextLink->entityTouched = other;
  nextLink->touchStamp = touchStamp;
  nextLink->flags = 0;
  nextLink->nextLink = *p_nextLink;
  nextLink->prevLink = root;
  *p_nextLink = nextLink;
  nextLink->nextLink->prevLink = nextLink;
  if ( (C_BaseEntity::IsSolid(this) && (this->m_Collision.m_usSolidFlags.m_Value & 0x20) == 0
     || (this->m_Collision.m_usSolidFlags.m_Value & 8) != 0)
    && (other->m_Collision.m_usSolidFlags.m_Value & 8) == 0 )
  {
    nextLink->flags |= 1u;
    if ( !C_BaseEntity::sm_bDisableTouchFuncs )
      C_BaseEntity::PhysicsStartTouch(this, pentOther: other);
  }
  return nextLink;
}

//------------------------------------------------------------------------------
// Address: 0x101406F0
// Name: public: void C_BaseEntity::PhysicsCheckWaterTransition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsCheckWaterTransition(C_BaseEntity *this)
{
  int WaterType; // edi
  __int16 v3; // ax
  unsigned int m_Index; // ecx
  __int64 v5; // xmm0_8
  Vector vecAbsVelocity; // [esp+10h] [ebp-Ch] BYREF

  WaterType = C_BaseEntity::GetWaterType(this);
  C_BaseEntity::UpdateWaterState(this, a2: (int)this);
  v3 = C_BaseEntity::GetWaterType(this);
  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    if ( (v3 & 0x4030) != 0 )
    {
      if ( WaterType == 0 )
      {
        C_BaseEntity::EmitSound(this, soundname: "BaseEntity.EnterWater", soundtime: 0.0, duration: nullptr);
        if ( (this->m_iEFlags & 0x20000000) == 0 )
        {
          C_BaseEntity::CalcAbsoluteVelocity(this);
          v5 = *(_QWORD *)&this->m_vecAbsVelocity.x;
          vecAbsVelocity.z = this->m_vecAbsVelocity.z;
          *(_QWORD *)&vecAbsVelocity.x = v5;
          vecAbsVelocity.z = vecAbsVelocity.z * 0.5;
          C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
        }
      }
    }
    else if ( WaterType != 0 )
    {
      C_BaseEntity::EmitSound(this, soundname: "BaseEntity.ExitWater", soundtime: 0.0, duration: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101407D0
// Name: public: bool C_BaseEntity::PhysicsRunThink(enum C_BaseEntity::thinkmethods_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::PhysicsRunThink(C_BaseEntity *this, C_BaseEntity::thinkmethods_t thinkMethod)
{
  bool result; // al
  int v4; // edi
  int i; // ebx

  result = true;
  if ( (this->m_iEFlags & 0x400000) == 0 )
  {
    v4 = 0;
    if ( thinkMethod != THINK_FIRE_ALL_BUT_BASE )
    {
      result = C_BaseEntity::PhysicsRunSpecificThink(
                 this,
                 nContextIndex: -1,
                 thinkFunc: (unsigned int) __thiscall C_BaseEntity::`vcall'{528,{flat}});
      if ( !result )
        return false;
    }
    if ( thinkMethod != THINK_FIRE_BASE_ONLY && this->m_aThinkFunctions.m_Size > 0 )
    {
      for ( i = 0; ; ++i )
      {
        result = C_BaseEntity::PhysicsRunSpecificThink(
                   this,
                   nContextIndex: v4,
                   thinkFunc: this->m_aThinkFunctions.m_Memory.m_pMemory[i].m_pfnThink);
        if ( !result )
          break;
        if ( ++v4 >= this->m_aThinkFunctions.m_Size )
          return result;
      }
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101408F0
// Name: public: void C_BaseEntity::PhysicsCheckForEntityUntouch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsCheckForEntityUntouch(C_BaseEntity *this)
{
  touchlink_t *v2; // eax
  touchlink_t *v3; // ebx
  touchlink_t *nextLink; // esi
  int touchStamp; // eax
  C_BaseEntity *entityTouched; // esi
  bool saveCleanup; // [esp+7h] [ebp-1h]

  if ( (this->m_fDataObjectTypes & 2) != 0 && g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
  {
    v2 = (touchlink_t *)g_DataObjectAccessSystem.m_Accessors[1]->GetDataObject(
                          this: g_DataObjectAccessSystem.m_Accessors[1],
                          a2: this);
    v3 = v2;
    if ( v2 != nullptr )
    {
      nextLink = v2->nextLink;
      saveCleanup = g_bCleanupDatObject;
      g_bCleanupDatObject = false;
      if ( nextLink != v2 )
      {
        do
        {
          touchStamp = nextLink->touchStamp;
          g_pNextLink = nextLink->nextLink;
          if ( touchStamp == -1 )
          {
            entityTouched = nextLink->entityTouched;
            if ( entityTouched != nullptr && (this->m_iEFlags & 1) == 0 && (entityTouched->m_iEFlags & 1) == 0 )
              this->Touch(this, a2: entityTouched);
          }
          else if ( touchStamp != this->touchStamp )
          {
            C_BaseEntity::PhysicsNotifyOtherOfUntouch(ent: this, other: nextLink->entityTouched);
            C_BaseEntity::PhysicsRemoveToucher(otherEntity: this, link: nextLink);
          }
          nextLink = g_pNextLink;
        }
        while ( g_pNextLink != v3 );
      }
      g_bCleanupDatObject = saveCleanup;
      if ( v3->nextLink == v3 && v3->prevLink == v3 && (this->m_fDataObjectTypes & 2) != 0 )
      {
        if ( g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
          g_DataObjectAccessSystem.m_Accessors[1]->DestroyDataObject(
            this: g_DataObjectAccessSystem.m_Accessors[1],
            a2: this);
        this->m_fDataObjectTypes &= ~2u;
      }
    }
  }
  g_pNextLink = nullptr;
  C_BaseEntity::SetCheckUntouch(this, check: false);
}

//------------------------------------------------------------------------------
// Address: 0x101409F0
// Name: public: struct groundlink_t __near * C_BaseEntity::AddEntityToGroundList(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
groundlink_t *__thiscall C_BaseEntity::AddEntityToGroundList(C_BaseEntity *this, C_BaseEntity *other)
{
  C_BaseEntity *v2; // ebx
  groundlink_t *result; // eax
  groundlink_t *v4; // esi
  groundlink_t **p_nextLink; // edi
  unsigned int m_Index; // edx
  C_BaseEntity *m_pEntity; // ecx
  groundlink_t *v8; // eax
  unsigned int *v9; // esi
  groundlink_t *root; // [esp+4h] [ebp-8h]

  v2 = this;
  if ( this == other || (other->m_iEFlags & 1) != 0 )
    return nullptr;
  if ( (this->m_fDataObjectTypes & 1) == 0
    || (g_DataObjectAccessSystem.m_Accessors[0] != nullptr
      ? (v4 = (groundlink_t *)g_DataObjectAccessSystem.m_Accessors[0]->GetDataObject(
                                this: g_DataObjectAccessSystem.m_Accessors[0],
                                a2: this))
      : (v4 = nullptr),
        root = v4,
        v4 == nullptr) )
  {
    v2->m_fDataObjectTypes |= 1u;
    if ( g_DataObjectAccessSystem.m_Accessors[0] != nullptr )
      v8 = (groundlink_t *)g_DataObjectAccessSystem.m_Accessors[0]->CreateDataObject(
                             this: g_DataObjectAccessSystem.m_Accessors[0],
                             a2: v2);
    else
      v8 = nullptr;
    p_nextLink = &v8->nextLink;
    root = v8;
    v8->nextLink = v8;
    v8->prevLink = v8;
LABEL_21:
    v9 = (unsigned int *)CUtlMemoryPool::Alloc(this: &g_EntityGroundLinks, amount: 0xCu);
    if ( v9 != nullptr )
    {
      ++groundlinksallocated;
      *v9 = other->GetRefEHandle(this: other)->m_Index;
      v9[1] = (unsigned int)*p_nextLink;
      v9[2] = (unsigned int)root;
      *p_nextLink = (groundlink_t *)v9;
      *(_DWORD *)(v9[1] + 8) = v9;
      if ( (v2->m_iEFlags & 1) == 0 && (other->m_iEFlags & 1) == 0 )
        C_BaseEntity::AddFlag(this: other, flags: 1);
      return (groundlink_t *)v9;
    }
    else
    {
      DevMsg(a1: "AllocGroundLink: failed to allocate groundlink_t.!!!\n");
      return nullptr;
    }
  }
  result = v4->nextLink;
  p_nextLink = &v4->nextLink;
  if ( result == v4 )
    goto LABEL_21;
  while ( 1 )
  {
    m_Index = result->entity.m_Index;
    if ( result->entity.m_Index == -1
      || (v2 = this, g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    if ( m_pEntity == other )
      return result;
    result = result->nextLink;
    if ( result == v4 )
      goto LABEL_21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140B30
// Name: public: static void C_BaseEntity::PhysicsNotifyOtherOfGroundRemoval(class C_BaseEntity __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::PhysicsNotifyOtherOfGroundRemoval(C_BaseEntity *ent, C_BaseEntity *other)
{
  groundlink_t *v2; // eax
  groundlink_t *v3; // esi
  groundlink_t *nextLink; // edx
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax

  if ( other != nullptr && (other->m_fDataObjectTypes & 1) != 0 && g_DataObjectAccessSystem.m_Accessors[0] != nullptr )
  {
    v2 = (groundlink_t *)g_DataObjectAccessSystem.m_Accessors[0]->GetDataObject(
                           this: g_DataObjectAccessSystem.m_Accessors[0],
                           a2: other);
    v3 = v2;
    if ( v2 != nullptr )
    {
      nextLink = v2->nextLink;
      if ( nextLink != v2 )
      {
        while ( 1 )
        {
          m_Index = nextLink->entity.m_Index;
          if ( nextLink->entity.m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          if ( m_pEntity == ent )
            break;
          nextLink = nextLink->nextLink;
          if ( nextLink == v3 )
            return;
        }
        C_BaseEntity::PhysicsRemoveGround(other, link: nextLink);
        if ( v3->nextLink == v3 && v3->prevLink == v3 && (other->m_fDataObjectTypes & 1) != 0 )
        {
          if ( g_DataObjectAccessSystem.m_Accessors[0] != nullptr )
            g_DataObjectAccessSystem.m_Accessors[0]->DestroyDataObject(
              this: g_DataObjectAccessSystem.m_Accessors[0],
              a2: other);
          other->m_fDataObjectTypes &= ~1u;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140BF0
// Name: public: static void C_BaseEntity::PhysicsRemoveGroundList(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::PhysicsRemoveGroundList(C_BaseEntity *ent)
{
  C_BaseEntity *v2; // eax
  IClientRenderable_vtbl *v3; // esi
  IClientUnknown *(__thiscall *GetIClientUnknown)(IClientRenderable *); // ecx
  const Vector *(__thiscall *GetRenderOrigin)(IClientRenderable *); // edi
  C_BaseEntity *m_pEntity; // eax
  C_BaseEntity *enta; // [esp+Ch] [ebp+8h]

  if ( (ent->m_fDataObjectTypes & 1) != 0 && g_DataObjectAccessSystem.m_Accessors[0] != nullptr )
  {
    v2 = (C_BaseEntity *)g_DataObjectAccessSystem.m_Accessors[0]->GetDataObject(
                           this: g_DataObjectAccessSystem.m_Accessors[0],
                           a2: ent);
    enta = v2;
    if ( v2 != nullptr )
    {
      v3 = v2->IClientEntity::IClientRenderable::__vftable;
      if ( v3 != nullptr )
      {
        while ( v3 != (IClientRenderable_vtbl *)v2 )
        {
          GetIClientUnknown = v3->GetIClientUnknown;
          GetRenderOrigin = v3->GetRenderOrigin;
          if ( v3->GetIClientUnknown == (IClientUnknown *(__thiscall *)(IClientRenderable *))-1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)GetIClientUnknown].m_SerialNumber != (unsigned int)GetIClientUnknown >> 16 )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)GetIClientUnknown].m_pEntity;
          }
          C_BaseEntity::PhysicsNotifyOtherOfGroundRemoval(ent, other: m_pEntity);
          --groundlinksallocated;
          CUtlMemoryPool::Free(this: &g_EntityGroundLinks, memBlock: v3);
          v3 = (IClientRenderable_vtbl *)GetRenderOrigin;
          if ( GetRenderOrigin == nullptr )
            break;
          v2 = enta;
        }
      }
      if ( (ent->m_fDataObjectTypes & 1) != 0 )
      {
        if ( g_DataObjectAccessSystem.m_Accessors[0] != nullptr )
          g_DataObjectAccessSystem.m_Accessors[0]->DestroyDataObject(
            this: g_DataObjectAccessSystem.m_Accessors[0],
            a2: ent);
        ent->m_fDataObjectTypes &= ~1u;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140CB0
// Name: public: void C_BaseEntity::PhysicsMarkEntitiesAsTouchingEventDriven(class C_BaseEntity __near *,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsMarkEntitiesAsTouchingEventDriven(
        C_BaseEntity *this,
        C_BaseEntity *other,
        CGameTrace *trace)
{
  touchlink_t *v4; // eax
  touchlink_t *v5; // eax

  CBaseTrace::operator=(this: &g_TouchTrace, __that: trace);
  g_TouchTrace.fractionleftsolid = trace->fractionleftsolid;
  g_TouchTrace.surface = trace->surface;
  g_TouchTrace.hitgroup = trace->hitgroup;
  g_TouchTrace.physicsbone = trace->physicsbone;
  g_TouchTrace.worldSurfaceIndex = trace->worldSurfaceIndex;
  g_TouchTrace.m_pEnt = trace->m_pEnt;
  g_TouchTrace.hitbox = trace->hitbox;
  g_TouchTrace.m_pEnt = (struct CBaseEntity *)other;
  v4 = C_BaseEntity::PhysicsMarkEntityAsTouched(this, other);
  if ( v4 != nullptr )
    v4->touchStamp = -1;
  g_TouchTrace.m_pEnt = (struct CBaseEntity *)this;
  v5 = C_BaseEntity::PhysicsMarkEntityAsTouched(this: other, other: this);
  if ( v5 != nullptr )
    v5->touchStamp = -1;
  UTIL_ClearTrace(trace: &g_TouchTrace);
}

//------------------------------------------------------------------------------
// Address: 0x10140D60
// Name: private: void C_BaseEntity::PhysicsRigidChild(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsRigidChild(C_BaseEntity *this)
{
  int v2; // edi
  int v3; // ebx

  this->GetAbsOrigin(this);
  if ( (this->m_iEFlags & 0x400000) == 0 )
  {
    v2 = 0;
    if ( C_BaseEntity::PhysicsRunSpecificThink(
           this,
           nContextIndex: -1,
           thinkFunc: (unsigned int) __thiscall C_BaseEntity::`vcall'{528,{flat}})
      && this->m_aThinkFunctions.m_Size > 0 )
    {
      v3 = 0;
      do
      {
        if ( !C_BaseEntity::PhysicsRunSpecificThink(
                this,
                nContextIndex: v2,
                thinkFunc: this->m_aThinkFunctions.m_Memory.m_pMemory[v3].m_pfnThink) )
          break;
        ++v2;
        ++v3;
      }
      while ( v2 < this->m_aThinkFunctions.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140E00
// Name: public: void C_BaseEntity::SetGroundEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetGroundEntity(C_BaseEntity *this, C_BaseEntity *ground)
{
  unsigned int m_Index; // eax
  C_BaseEntity *m_pEntity; // ecx
  C_BaseEntity *v5; // ebx

  m_Index = this->m_hGroundEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != ground )
  {
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      v5 = nullptr;
    else
      v5 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( ground != nullptr )
      this->m_hGroundEntity.m_Index = ground->GetRefEHandle(this: ground)->m_Index;
    else
      this->m_hGroundEntity.m_Index = -1;
    if ( v5 != nullptr )
    {
      if ( ground == nullptr )
      {
        C_BaseEntity::PhysicsNotifyOtherOfGroundRemoval(ent: this, other: v5);
LABEL_20:
        C_BaseEntity::RemoveFlag(this, flagsToRemove: 1);
        return;
      }
    }
    else if ( ground != nullptr )
    {
      goto LABEL_16;
    }
    C_BaseEntity::PhysicsNotifyOtherOfGroundRemoval(ent: this, other: v5);
LABEL_16:
    C_BaseEntity::AddEntityToGroundList(this: ground, other: this);
    if ( ground != nullptr )
    {
      C_BaseEntity::AddFlag(this, flags: 1);
      return;
    }
    goto LABEL_20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140F90
// Name: public: void C_BaseEntity::PhysicsMarkEntitiesAsTouching(class C_BaseEntity __near *,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsMarkEntitiesAsTouching(C_BaseEntity *this, C_BaseEntity *other, CGameTrace *trace)
{
  touchlink_t *v4; // ebx
  touchlink_t *v5; // eax

  CBaseTrace::operator=(this: &g_TouchTrace, __that: trace);
  g_TouchTrace.fractionleftsolid = trace->fractionleftsolid;
  g_TouchTrace.surface = trace->surface;
  g_TouchTrace.hitgroup = trace->hitgroup;
  g_TouchTrace.physicsbone = trace->physicsbone;
  g_TouchTrace.worldSurfaceIndex = trace->worldSurfaceIndex;
  g_TouchTrace.m_pEnt = trace->m_pEnt;
  g_TouchTrace.hitbox = trace->hitbox;
  v4 = C_BaseEntity::PhysicsMarkEntityAsTouched(this, other);
  v5 = C_BaseEntity::PhysicsMarkEntityAsTouched(this: other, other: this);
  if ( v4 != nullptr )
  {
    if ( v5 == nullptr )
      C_BaseEntity::PhysicsNotifyOtherOfUntouch(ent: other, other: this);
  }
  else if ( v5 != nullptr )
  {
    C_BaseEntity::PhysicsNotifyOtherOfUntouch(ent: this, other);
  }
  UTIL_ClearTrace(trace: &g_TouchTrace);
}

//------------------------------------------------------------------------------
// Address: 0x10141040
// Name: public: void C_BaseEntity::PhysicsImpact(class C_BaseEntity __near *,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsImpact(C_BaseEntity *this, C_BaseEntity *other, CGameTrace *trace)
{
  if ( other != nullptr && ((this->m_fFlags | other->m_fFlags) & 0x8000000) == 0 )
    C_BaseEntity::PhysicsMarkEntitiesAsTouching(this, other, trace);
}

//------------------------------------------------------------------------------
// Address: 0x10141070
// Name: public: void C_BaseEntity::ResolveFlyCollisionBounce(class CGameTrace __near &,class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ResolveFlyCollisionBounce(
        C_BaseEntity *this,
        CGameTrace *trace,
        Vector *vecVelocity,
        float flMinTotalElasticity)
{
  float v6; // xmm1_4
  float v7; // xmm0_4
  float x; // xmm1_4
  float y; // xmm3_4
  float z; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm4_4
  float m_flGravity; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // edx
  unsigned int m_Index; // eax
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  float v33; // xmm3_4
  float vecDelta; // [esp+Ch] [ebp-28h]
  float vecDelta_4; // [esp+10h] [ebp-24h]
  float vecDelta_8; // [esp+14h] [ebp-20h]
  Vector vecBaseDir; // [esp+18h] [ebp-1Ch] BYREF
  Vector vecAbsVelocity; // [esp+24h] [ebp-10h] BYREF
  float flSurfaceElasticity; // [esp+30h] [ebp-4h] BYREF
  float flSpeedSqr; // [esp+3Ch] [ebp+8h]
  float flSpeedSqra; // [esp+3Ch] [ebp+8h]
  C_BaseEntity *pEntity; // [esp+44h] [ebp+10h]

  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, float *))physprops->GetPhysicsProperties)(
    a1: trace->surface.surfaceProps,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: &flSurfaceElasticity);
  v6 = flMinTotalElasticity;
  v7 = this->m_flElasticity * flSurfaceElasticity;
  if ( flMinTotalElasticity > 0.89999998 )
    v6 = 0.89999998;
  if ( v6 <= v7 )
  {
    if ( v7 <= 0.89999998 )
      flSpeedSqr = this->m_flElasticity * flSurfaceElasticity;
    else
      flSpeedSqr = 0.89999998;
  }
  else
  {
    flSpeedSqr = v6;
  }
  C_BaseEntity::CalcAbsoluteVelocity(this);
  x = this->m_vecAbsVelocity.x;
  y = this->m_vecAbsVelocity.y;
  z = this->m_vecAbsVelocity.z;
  v11 = (float)((float)((float)(trace->plane.normal.x * x) + (float)(trace->plane.normal.y * y))
              + (float)(trace->plane.normal.z * z))
      * 2.0;
  v12 = x - (float)(trace->plane.normal.x * v11);
  if ( v12 > -0.1 && v12 < 0.1 )
    v12 = 0.0;
  v13 = y - (float)(trace->plane.normal.y * v11);
  if ( v13 > -0.1 && v13 < 0.1 )
    v13 = 0.0;
  v14 = z - (float)(trace->plane.normal.z * v11);
  if ( v14 > -0.1 && v14 < 0.1 )
    v14 = 0.0;
  v15 = v13 * flSpeedSqr;
  v16 = v12 * flSpeedSqr;
  vecVelocity->x = (float)(v12 * flSpeedSqr) + this->m_vecBaseVelocity.x;
  vecVelocity->y = this->m_vecBaseVelocity.y + v15;
  v17 = vecVelocity->y;
  v18 = this->m_vecBaseVelocity.z + (float)(flSpeedSqr * v14);
  vecAbsVelocity.z = flSpeedSqr * v14;
  v19 = (float)((float)(vecVelocity->x * vecVelocity->x) + (float)(v17 * v17)) + (float)(v18 * v18);
  vecVelocity->z = v18;
  v20 = trace->plane.normal.z;
  vecAbsVelocity.x = v16;
  vecAbsVelocity.y = v15;
  flSpeedSqra = v19;
  if ( v20 <= 0.69999999 )
  {
    if ( v19 < 900.0 )
    {
LABEL_25:
      C_BaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
      C_BaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
      return;
    }
    C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
  }
  else
  {
    m_flGravity = this->m_flGravity;
    pEntity = (C_BaseEntity *)trace->m_pEnt;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    if ( (float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * *(float *)(gpGlobals.m_Index + 16)) > v18 )
    {
      v22 = v16 + this->m_vecBaseVelocity.x;
      vecVelocity->x = v22;
      v23 = this->m_vecBaseVelocity.y + v15;
      vecVelocity->y = v23;
      v24 = this->m_vecBaseVelocity.z;
      vecVelocity->z = v24;
      vecAbsVelocity.z = 0.0;
      flSpeedSqra = (float)((float)(v22 * v22) + (float)(v23 * v23)) + (float)(v24 * v24);
    }
    C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
    if ( flSpeedSqra < 900.0 )
    {
      if ( C_BaseEntity::IsStandable(this: pEntity) )
        C_BaseEntity::SetGroundEntity(this, ground: pEntity);
      goto LABEL_25;
    }
    v25 = this->m_vecBaseVelocity.z;
    vecDelta = this->m_vecBaseVelocity.x - vecAbsVelocity.x;
    vecDelta_4 = this->m_vecBaseVelocity.y - vecAbsVelocity.y;
    vecDelta_8 = v25 - vecAbsVelocity.z;
    *(_QWORD *)&vecBaseDir.x = *(_QWORD *)&this->m_vecBaseVelocity.x;
    vecBaseDir.z = v25;
    VectorNormalize(vec: &vecBaseDir);
    m_Index = gpGlobals.m_Index;
    v27 = (float)((float)(vecBaseDir.y * vecDelta_4) + (float)(vecDelta * vecBaseDir.x))
        + (float)(vecBaseDir.z * vecDelta_8);
    v28 = (float)(1.0 - trace->fraction) * *(float *)(gpGlobals.m_Index + 16);
    v29 = vecAbsVelocity.y * v28;
    v30 = v28 * vecAbsVelocity.x;
    vecVelocity->z = v28 * vecAbsVelocity.z;
    vecVelocity->x = v30;
    vecVelocity->y = v29;
    v31 = (float)(1.0 - trace->fraction) * *(float *)(m_Index + 16);
    v32 = (float)((float)(this->m_vecBaseVelocity.z * v27) * v31) + vecVelocity->z;
    v33 = (float)((float)(this->m_vecBaseVelocity.y * v27) * v31) + v29;
    vecVelocity->x = (float)((float)(v27 * this->m_vecBaseVelocity.x) * v31) + v30;
    vecVelocity->y = v33;
    vecVelocity->z = v32;
    C_BaseEntity::PhysicsPushEntity(this, push: vecVelocity, pTrace: trace);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141480
// Name: public: void C_BaseEntity::ResolveFlyCollisionSlide(class CGameTrace __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ResolveFlyCollisionSlide(C_BaseEntity *this, CGameTrace *trace, Vector *vecVelocity)
{
  float y; // xmm4_4
  float x; // xmm1_4
  float v7; // xmm3_4
  float z; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float m_flGravity; // xmm2_4
  struct CBaseEntity *m_pEnt; // ebx
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  Vector vecAbsVelocity; // [esp+8h] [ebp-10h] BYREF
  float flSurfaceFriction; // [esp+14h] [ebp-4h] BYREF
  float flSpeedSqr; // [esp+20h] [ebp+8h]

  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, float *, _DWORD))physprops->GetPhysicsProperties)(
    a1: trace->surface.surfaceProps,
    a2: 0,
    a3: 0,
    a4: &flSurfaceFriction,
    a5: 0);
  C_BaseEntity::CalcAbsoluteVelocity(this);
  y = trace->plane.normal.y;
  x = this->m_vecAbsVelocity.x;
  v7 = this->m_vecAbsVelocity.y;
  z = trace->plane.normal.z;
  v9 = this->m_vecAbsVelocity.z;
  v10 = (float)((float)(trace->plane.normal.x * x) + (float)(trace->plane.normal.y * v7))
      + (float)(trace->plane.normal.z * v9);
  v11 = x - (float)(trace->plane.normal.x * v10);
  vecAbsVelocity.x = v11;
  if ( v11 > -0.1 && v11 < 0.1 )
  {
    v11 = 0.0;
    vecAbsVelocity.x = 0.0;
  }
  v12 = v7 - (float)(y * v10);
  vecAbsVelocity.y = v12;
  if ( v12 > -0.1 && v12 < 0.1 )
  {
    v12 = 0.0;
    vecAbsVelocity.y = 0.0;
  }
  v13 = v9 - (float)(z * v10);
  vecAbsVelocity.z = v13;
  if ( v13 > -0.1 && v13 < 0.1 )
  {
    v13 = 0.0;
    vecAbsVelocity.z = 0.0;
  }
  if ( trace->plane.normal.z > 0.7 )
  {
    vecVelocity->x = this->m_vecBaseVelocity.x + v11;
    v14 = vecVelocity->x;
    vecVelocity->y = this->m_vecBaseVelocity.y + v12;
    v15 = this->m_vecBaseVelocity.z + v13;
    v16 = (float)((float)(v14 * v14) + (float)(vecVelocity->y * vecVelocity->y)) + (float)(v15 * v15);
    vecVelocity->z = v15;
    flSpeedSqr = v16;
    m_flGravity = this->m_flGravity;
    m_pEnt = trace->m_pEnt;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    if ( (float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * *(float *)(gpGlobals.m_Index + 16)) > v15 )
    {
      vecVelocity->x = this->m_vecBaseVelocity.x + v11;
      v19 = this->m_vecBaseVelocity.y + v12;
      vecVelocity->y = v19;
      v20 = this->m_vecBaseVelocity.z;
      v21 = v19;
      v22 = vecVelocity->x;
      vecVelocity->z = v20;
      vecAbsVelocity.z = 0.0;
      flSpeedSqr = (float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(v20 * v20);
    }
    C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
    if ( flSpeedSqr >= 900.0 )
    {
      v23 = this->m_vecBaseVelocity.y + vecAbsVelocity.y;
      v24 = this->m_vecBaseVelocity.z + vecAbsVelocity.z;
      v25 = 1.0 - trace->fraction;
      vecAbsVelocity.x = this->m_vecBaseVelocity.x + vecAbsVelocity.x;
      vecAbsVelocity.y = v23;
      vecAbsVelocity.z = v24;
      v26 = (float)(v25 * *(float *)(gpGlobals.m_Index + 16)) * flSurfaceFriction;
      vecAbsVelocity.x = v26 * vecAbsVelocity.x;
      vecAbsVelocity.y = v26 * v23;
      vecAbsVelocity.z = v26 * v24;
      C_BaseEntity::PhysicsPushEntity(this, push: &vecAbsVelocity, pTrace: trace);
    }
    else
    {
      if ( C_BaseEntity::IsStandable(this: (C_BaseEntity *)m_pEnt) )
        C_BaseEntity::SetGroundEntity(this, ground: (C_BaseEntity *)m_pEnt);
      C_BaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
      C_BaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
    }
  }
  else
  {
    C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141790
// Name: public: void C_BaseEntity::ResolveFlyCollisionCustom(class CGameTrace __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ResolveFlyCollisionCustom(C_BaseEntity *this, CGameTrace *trace, Vector *vecVelocity)
{
  float v4; // xmm0_4
  float m_flGravity; // xmm1_4
  struct CBaseEntity *m_pEnt; // edi
  Vector vecAbsVelocity; // [esp+8h] [ebp-Ch] BYREF

  if ( trace->plane.normal.z > 0.7 )
  {
    C_BaseEntity::CalcAbsoluteVelocity(this);
    vecVelocity->x = this->m_vecAbsVelocity.x + this->m_vecBaseVelocity.x;
    vecVelocity->y = this->m_vecAbsVelocity.y + this->m_vecBaseVelocity.y;
    v4 = this->m_vecAbsVelocity.z + this->m_vecBaseVelocity.z;
    vecVelocity->z = v4;
    m_flGravity = this->m_flGravity;
    m_pEnt = trace->m_pEnt;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    if ( (float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * *(float *)(gpGlobals.m_Index + 16)) > v4 )
    {
      C_BaseEntity::CalcAbsoluteVelocity(this);
      *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
      vecAbsVelocity.z = 0.0;
      C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
    }
    if ( C_BaseEntity::IsStandable(this: (C_BaseEntity *)m_pEnt) )
      C_BaseEntity::SetGroundEntity(this, ground: (C_BaseEntity *)m_pEnt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141890
// Name: private: void C_BaseEntity::PhysicsToss(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsToss(C_BaseEntity *this)
{
  int v2; // edi
  int v3; // ebx
  unsigned int m_Index; // ecx
  CBaseEntityList *v5; // ebx
  C_BaseEntity *GroundEntity; // eax
  unsigned int v7; // ecx
  int v8; // eax
  CEntInfo *v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  bool v12; // zf
  C_BaseEntity **v13; // eax
  C_BaseEntity *v14; // eax
  float z; // ecx
  float v16; // xmm3_4
  float v17; // xmm1_4
  float y; // xmm0_4
  float v19; // xmm2_4
  const QAngle *LocalAngles; // eax
  IPhysicsObject *m_pPhysicsObject; // ebx
  IPhysicsObject_vtbl *v22; // edi
  int v23; // eax
  CGameTrace trace; // [esp+20h] [ebp-74h] BYREF
  int (*v25)(); // [esp+74h] [ebp-20h]
  Vector vecAbsVelocity; // [esp+78h] [ebp-1Ch] BYREF
  Vector move; // [esp+84h] [ebp-10h] BYREF
  float v28; // [esp+90h] [ebp-4h]

  if ( (this->m_iEFlags & 0x400000) != 0 )
    goto LABEL_7;
  v2 = 0;
  v25 =  __thiscall C_BaseEntity::`vcall'{528,{flat}};
  memset((void *)&vecAbsVelocity, 0, sizeof(vecAbsVelocity));
  if ( !C_BaseEntity::PhysicsRunSpecificThink(
          this,
          nContextIndex: -1,
          thinkFunc: (unsigned int) __thiscall C_BaseEntity::`vcall'{528,{flat}}) )
    return;
  if ( this->m_aThinkFunctions.m_Size <= 0 )
  {
LABEL_7:
    C_BaseEntity::CalcAbsoluteVelocity(this);
    if ( this->m_vecAbsVelocity.z <= 0.0 )
    {
      m_Index = this->m_hGroundEntity.m_Index;
      if ( m_Index != -1 )
      {
        v5 = g_pEntityList;
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
        {
LABEL_13:
          v7 = this->m_hGroundEntity.m_Index;
          if ( v7 != -1 )
          {
            v8 = (unsigned __int16)v7;
            v9 = &v5->m_EntPtrArray[(unsigned __int16)v7];
            v10 = HIWORD(v7);
            if ( v9->m_SerialNumber == v10 && v9->m_pEntity != nullptr )
            {
              v11 = v8;
              v12 = v5->m_EntPtrArray[v11].m_SerialNumber == v10;
              v13 = (C_BaseEntity **)&v5->m_EntPtrArray[v11];
              if ( v12 )
                v14 = *v13;
              else
                v14 = nullptr;
              this->m_hGroundEntity.m_Index = -1;
              if ( v14 != nullptr )
              {
                C_BaseEntity::PhysicsNotifyOtherOfGroundRemoval(ent: this, other: v14);
              }
              else
              {
                C_BaseEntity::PhysicsNotifyOtherOfGroundRemoval(ent: this, other: nullptr);
                C_BaseEntity::AddEntityToGroundList(this: nullptr, other: this);
              }
              C_BaseEntity::RemoveFlag(this, flagsToRemove: 1);
            }
          }
          goto LABEL_23;
        }
        GroundEntity = C_BaseEntity::GetGroundEntity(this);
        if ( C_BaseEntity::IsStandable(this: GroundEntity) )
        {
LABEL_23:
          if ( (this->m_fFlags & 1) == 0
            || (C_BaseEntity::CalcAbsoluteVelocity(this), vec3_origin.x != this->m_vecAbsVelocity.x)
            || vec3_origin.y != this->m_vecAbsVelocity.y
            || vec3_origin.z != this->m_vecAbsVelocity.z
            || (C_BaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle),
                vec3_origin.x != this->m_vecBaseVelocity.x)
            || vec3_origin.y != this->m_vecBaseVelocity.y
            || vec3_origin.z != this->m_vecBaseVelocity.z )
          {
            C_BaseEntity::PhysicsCheckVelocity(this);
            if ( this->m_MoveType != 5 || (this->m_fFlags & 0x800) != 0 )
            {
              C_BaseEntity::CalcAbsoluteVelocity(this);
              z = this->m_vecAbsVelocity.z;
              v16 = *(float *)(gpGlobals.m_Index + 16);
              v17 = this->m_vecBaseVelocity.z;
              *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
              y = this->m_vecBaseVelocity.y;
              v19 = vecAbsVelocity.x + this->m_vecBaseVelocity.x;
              vecAbsVelocity.z = z;
              move.x = v16 * v19;
              move.y = (float)(y + vecAbsVelocity.y) * v16;
              move.z = (float)(v17 + z) * v16;
              C_BaseEntity::PhysicsCheckVelocity(this);
            }
            else
            {
              C_BaseEntity::PhysicsAddGravityMove(this, &move);
            }
            v28 = *(float *)(gpGlobals.m_Index + 16);
            LocalAngles = C_BaseEntity::GetLocalAngles(this);
            vecAbsVelocity.x = (float)(this->m_vecAngVelocity.x * v28) + LocalAngles->x;
            vecAbsVelocity.y = (float)(this->m_vecAngVelocity.y * v28) + LocalAngles->y;
            vecAbsVelocity.z = (float)(this->m_vecAngVelocity.z * v28) + LocalAngles->z;
            C_BaseEntity::SetLocalAngles(this, angles: (const QAngle *)&vecAbsVelocity);
            C_BaseEntity::PhysicsPushEntity(this, push: &move, pTrace: &trace);
            m_pPhysicsObject = this->m_pPhysicsObject;
            if ( m_pPhysicsObject != nullptr )
            {
              v22 = m_pPhysicsObject->__vftable;
              v23 = ((int (__thiscall *)(C_BaseEntity *, QAngle *, int, _DWORD))this->GetAbsOrigin)(
                      a1: this,
                      a2: &vec3_angle,
                      a3: 1,
                      a4: *(_DWORD *)(gpGlobals.m_Index + 16));
              ((void (__thiscall *)(IPhysicsObject *, int))v22->UpdateShadow)(a1: m_pPhysicsObject, a2: v23);
            }
            C_BaseEntity::PhysicsCheckVelocity(this);
            if ( trace.allsolid )
            {
              C_BaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
              C_BaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
            }
            else if ( trace.fraction == 1.0 )
            {
LABEL_43:
              C_BaseEntity::PhysicsCheckWaterTransition(this);
            }
            else
            {
              switch ( this->m_MoveCollide )
              {
                case 0u:
                case 3u:
                  C_BaseEntity::ResolveFlyCollisionSlide(this, &trace, vecVelocity: &move);
                  goto LABEL_43;
                case 1u:
                  C_BaseEntity::ResolveFlyCollisionBounce(this, &trace, vecVelocity: &move, flMinTotalElasticity: 0.0);
                  C_BaseEntity::PhysicsCheckWaterTransition(this);
                  break;
                case 2u:
                  C_BaseEntity::ResolveFlyCollisionCustom(this, &trace, vecVelocity: &move);
                  C_BaseEntity::PhysicsCheckWaterTransition(this);
                  break;
                default:
                  goto LABEL_43;
              }
            }
          }
          return;
        }
      }
    }
    v5 = g_pEntityList;
    goto LABEL_13;
  }
  v3 = 0;
  while ( C_BaseEntity::PhysicsRunSpecificThink(
            this,
            nContextIndex: v2,
            thinkFunc: this->m_aThinkFunctions.m_Memory.m_pMemory[v3].m_pfnThink) )
  {
    ++v2;
    ++v3;
    if ( v2 >= this->m_aThinkFunctions.m_Size )
      goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141CB0
// Name: public: virtual void C_BaseEntity::PhysicsSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PhysicsSimulate(C_BaseEntity *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // edi
  unsigned __int8 m_MoveType; // al
  unsigned int v5; // ecx
  float v6; // xmm0_4
  char *Classname; // eax
  int v8; // [esp-8h] [ebp-18h]
  Vector vecAbsVelocity; // [esp+4h] [ebp-Ch] BYREF

  if ( this->m_bIsPlayerSimulated || this->m_nSimulationTick != *(_DWORD *)(gpGlobals.m_Index + 24) )
  {
    this->m_nSimulationTick = *(_DWORD *)(gpGlobals.m_Index + 24);
    m_Index = this->m_pMoveParent.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    m_MoveType = this->m_MoveType;
    if ( (m_MoveType != 0 || m_pEntity != nullptr) && m_MoveType != 6 )
    {
      v5 = this->m_hGroundEntity.m_Index;
      if ( v5 == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity == nullptr )
      {
        C_BaseEntity::RemoveFlag(this, flagsToRemove: 1);
      }
      if ( m_pEntity != nullptr )
      {
        m_pEntity->__vftable[47].GetRefEHandle(this: m_pEntity);
      }
      else
      {
        if ( (this->m_fFlags & 0x1000000) == 0
          && (vec3_origin.x != this->m_vecBaseVelocity.x
           || vec3_origin.y != this->m_vecBaseVelocity.y
           || vec3_origin.z != this->m_vecBaseVelocity.z) )
        {
          C_BaseEntity::CalcAbsoluteVelocity(this);
          v6 = (float)(*(float *)(gpGlobals.m_Index + 16) * 0.5) + 1.0;
          vecAbsVelocity.x = (float)(this->m_vecBaseVelocity.x * v6) + this->m_vecAbsVelocity.x;
          vecAbsVelocity.y = (float)(this->m_vecBaseVelocity.y * v6) + this->m_vecAbsVelocity.y;
          vecAbsVelocity.z = (float)(this->m_vecBaseVelocity.z * v6) + this->m_vecAbsVelocity.z;
          C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
          this->m_vecBaseVelocity = vec3_origin;
        }
        C_BaseEntity::RemoveFlag(this, flagsToRemove: 0x1000000);
      }
      switch ( this->m_MoveType )
      {
        case 0u:
          C_BaseEntity::PhysicsRigidChild(this);
          break;
        case 3u:
          C_BaseEntity::PhysicsStep(this);
          break;
        case 4u:
        case 5u:
          C_BaseEntity::PhysicsToss(this);
          break;
        case 6u:
          return;
        case 7u:
        case 8u:
          C_BaseEntity::PhysicsNoclip(this);
          break;
        case 0xBu:
          C_BaseEntity::PhysicsCustom(this);
          break;
        default:
          v8 = this->m_MoveType;
          Classname = C_BaseEntity::GetClassname(this);
          _Warning(a1: "PhysicsSimulate: %s bad movetype %d", Classname, v8);
          break;
      }
    }
    else
    {
      C_BaseEntity::PhysicsNoclip(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141F30
// Name: public: CUtlMultiList<struct watcher_t,unsigned short>::~CUtlMultiList<struct watcher_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<watcher_t,unsigned short>::~CUtlMultiList<watcher_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<watcher_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_List);
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
// Address: 0x10141FB0
// Name: public: void CUtlMultiList<struct watcher_t,unsigned short>::RemoveAll(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<watcher_t,unsigned short>::RemoveAll(
        CUtlMultiList<watcher_t,unsigned short> *this,
        unsigned __int16 list)
{
  unsigned __int16 m_Head; // bx
  int v4; // edi
  CUtlMultiList<watcher_t,unsigned short>::ListElem_t *v5; // edx
  unsigned __int16 m_Next; // cx
  unsigned __int16 next; // [esp+8h] [ebp-4h]

  m_Head = this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      v4 = m_Head;
      v5 = &this->m_Memory.m_pMemory[v4];
      m_Next = v5->m_Next;
      next = m_Next;
      if ( m_Head < this->m_MaxElementIndex && v5->m_Previous != m_Head )
      {
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
          (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *)this,
          list,
          elem: m_Head);
        m_Next = next;
      }
      this->m_Memory.m_pMemory[v4].m_Next = this->m_FirstFree;
      --this->m_TotalElements;
      this->m_FirstFree = m_Head;
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142030
// Name: public: void CUtlHash<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,bool (*)(struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry const __near &,struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry const __near &),unsigned int (*)(struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry const __near &)>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<CEntityDataInstantiator<physicspushlist_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &,CEntityDataInstantiator<physicspushlist_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &)>::Purge(
        CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *this)
{
  int v1; // edi
  int m_Size; // ebx
  CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int> > *v3; // esi
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *v4; // [esp+0h] [ebp-4h]

  v4 = this;
  if ( this->m_Buckets.m_Size > 0 )
  {
    v1 = 0;
    m_Size = this->m_Buckets.m_Size;
    do
    {
      v3 = &this->m_Buckets.m_Memory.m_pMemory[v1];
      v3->m_Size = 0;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v4;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      ++v1;
      --m_Size;
      v3->m_pElements = v3->m_Memory.m_pMemory;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142140
// Name: private: int CWatcherList::GetCallbackObjects(class IWatcherCallback __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWatcherList::GetCallbackObjects(CWatcherList *this, IWatcherCallback **pList, int listMax)
{
  unsigned __int16 m_Head; // di
  int v4; // ebx
  CUtlMultiList<watcher_t,unsigned short>::ListElem_t *m_pMemory; // edx
  int v6; // esi
  unsigned int m_Index; // eax
  unsigned __int16 next; // [esp+Ch] [ebp-Ch]
  int index; // [esp+14h] [ebp-4h]

  m_Head = g_WatcherList.m_List.m_Memory.m_pMemory[this->m_list].m_Element.m_Head;
  v4 = 0;
  index = 0;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_pMemory = g_WatcherList.m_Memory.m_pMemory;
      v6 = m_Head;
      next = g_WatcherList.m_Memory.m_pMemory[v6].m_Next;
      m_Index = g_WatcherList.m_Memory.m_pMemory[v6].m_Element.hWatcher.m_Index;
      if ( m_Index != -1 )
      {
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
        {
          pList[index] = g_WatcherList.m_Memory.m_pMemory[v6].m_Element.pWatcherCallback;
          v4 = index + 1;
          index = v4;
          if ( v4 >= listMax )
            return v4;
          goto LABEL_12;
        }
        v4 = index;
      }
      if ( m_Head < g_WatcherList.m_MaxElementIndex && g_WatcherList.m_Memory.m_pMemory[v6].m_Previous != m_Head )
      {
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
          this: (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *)&g_WatcherList,
          list: this->m_list,
          elem: m_Head);
        m_pMemory = g_WatcherList.m_Memory.m_pMemory;
      }
      m_pMemory[v6].m_Next = g_WatcherList.m_FirstFree;
      --g_WatcherList.m_TotalElements;
      g_WatcherList.m_FirstFree = m_Head;
LABEL_12:
      m_Head = next;
    }
    while ( next != 0xFFFF );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10142240
// Name: public: void CWatcherList::NotifyVPhysicsStateChanged(class IPhysicsObject __near *,class C_BaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWatcherList::NotifyVPhysicsStateChanged(
        CWatcherList *this,
        IPhysicsObject *pPhysics,
        C_BaseEntity *pEntity,
        int bAwake)
{
  int CallbackObjects; // edi
  int i; // esi
  IWatcherCallback *v6; // ecx
  IWatcherCallback *pList[1024]; // [esp+8h] [ebp-1000h] BYREF

  CallbackObjects = CWatcherList::GetCallbackObjects(this, pList, listMax: 1024);
  for ( i = 0; i < CallbackObjects; ++i )
  {
    v6 = pList[i];
    if ( v6 != nullptr )
      ((void (__thiscall *)(IWatcherCallback *, IPhysicsObject *, C_BaseEntity *, int))v6->__vftable[1].dtr_IWatcherCallback)(
        a1: v6,
        a2: pPhysics,
        a3: pEntity,
        a4: bAwake);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101422A0
// Name: void ReportVPhysicsStateChanged(class IPhysicsObject __near *,class C_BaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReportVPhysicsStateChanged(IPhysicsObject *pPhysics, C_BaseEntity *pEntity, bool bAwake)
{
  CWatcherList *v3; // eax

  if ( (pEntity->m_fDataObjectTypes & 0x80) != 0 && g_DataObjectAccessSystem.m_Accessors[7] != nullptr )
  {
    v3 = (CWatcherList *)g_DataObjectAccessSystem.m_Accessors[7]->GetDataObject(
                           this: g_DataObjectAccessSystem.m_Accessors[7],
                           a2: pEntity);
    if ( v3 != nullptr )
      CWatcherList::NotifyVPhysicsStateChanged(this: v3, pPhysics, pEntity, bAwake);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142530
// Name: public: CEntityDataInstantiator<struct touchlink_t>::CEntityDataInstantiator<struct touchlink_t>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<touchlink_t> *__thiscall CEntityDataInstantiator<touchlink_t>::CEntityDataInstantiator<touchlink_t>(
        CEntityDataInstantiator<touchlink_t> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<touchlink_t>_vtbl *)&CEntityDataInstantiator<touchlink_t>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<touchlink_t>::HashEntry *, const CEntityDataInstantiator<touchlink_t>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<touchlink_t>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101425A0
// Name: public: virtual void __near * CEntityDataInstantiator<struct touchlink_t>::CreateDataObject(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<touchlink_t>::CreateDataObject(
        CEntityDataInstantiator<touchlink_t> *this,
        const C_BaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  int v6; // edx
  int v7; // ecx
  CEntityDataInstantiator<touchlink_t>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
             this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const vgui::PropertySheet::Page_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)MemAlloc_Alloc(nSize: 0x14u);
    v6 = HIWORD(v3);
    v7 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data = v5;
    _V_memset(
      dest: (int)p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data,
      fill: nullptr,
      count: 0x14u);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x10142690
// Name: public: CEntityDataInstantiator<struct groundlink_t>::CEntityDataInstantiator<struct groundlink_t>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<groundlink_t> *__thiscall CEntityDataInstantiator<groundlink_t>::CEntityDataInstantiator<groundlink_t>(
        CEntityDataInstantiator<groundlink_t> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<groundlink_t>_vtbl *)&CEntityDataInstantiator<groundlink_t>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<groundlink_t>::HashEntry *, const CEntityDataInstantiator<groundlink_t>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<groundlink_t>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10142700
// Name: public: virtual void __near * CEntityDataInstantiator<struct vphysicsupdateai_t>::GetDataObject(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<vphysicsupdateai_t>::GetDataObject(
        CEntityDataInstantiator<vphysicsupdateai_t> *this,
        const C_BaseEntity *instance)
{
  const C_BaseEntity *v2; // edx
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // esi
  unsigned int v4; // eax
  CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry entry; // [esp+4h] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+Ch] [ebp-4h] BYREF

  v2 = instance;
  entry.data = nullptr;
  instance = nullptr;
  p_m_HashTable = &this->m_HashTable;
  entry.key = v2;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: &this->m_HashTable,
         src: &entry,
         &pBucket,
         pIndex: (int *)&instance) == 0 )
    return nullptr;
  v4 = (unsigned int)instance | (pBucket << 16);
  if ( v4 == -1 )
    return nullptr;
  else
    return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)instance].data;
}

//------------------------------------------------------------------------------
// Address: 0x10142770
// Name: public: virtual void __near * CEntityDataInstantiator<struct groundlink_t>::CreateDataObject(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<groundlink_t>::CreateDataObject(
        CEntityDataInstantiator<groundlink_t> *this,
        const C_BaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  vphysicsupdateai_t *v6; // edx
  int v7; // ecx
  int v8; // eax
  CEntityDataInstantiator<groundlink_t>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
             this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const vgui::PropertySheet::Page_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)MemAlloc_Alloc(nSize: 0xCu);
    if ( v5 != nullptr )
    {
      v5->startUpdateTime = NAN;
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    v7 = HIWORD(v3);
    v8 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v7].m_Memory.m_pMemory[v8].data = v6;
    _V_memset(
      dest: (int)p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v7].m_Memory.m_pMemory[v8].data,
      fill: nullptr,
      count: 0xCu);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x10142870
// Name: public: CEntityDataInstantiator<struct StepSimulationData>::CEntityDataInstantiator<struct StepSimulationData>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<StepSimulationData> *__thiscall CEntityDataInstantiator<StepSimulationData>::CEntityDataInstantiator<StepSimulationData>(
        CEntityDataInstantiator<StepSimulationData> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<StepSimulationData>_vtbl *)&CEntityDataInstantiator<StepSimulationData>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<StepSimulationData>::HashEntry *, const CEntityDataInstantiator<StepSimulationData>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<StepSimulationData>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101428E0
// Name: protected: bool CUtlHash<struct CEntityDataInstantiator<struct vphysicsupdateai_t>::HashEntry,bool (*)(struct CEntityDataInstantiator<struct vphysicsupdateai_t>::HashEntry const __near &,struct CEntityDataInstantiator<struct vphysicsupdateai_t>::HashEntry const __near &),unsigned int (*)(struct CEntityDataInstantiator<struct vphysicsupdateai_t>::HashEntry const __near &)>::DoFind(struct CEntityDataInstantiator<struct vphysicsupdateai_t>::HashEntry const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
        CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *this,
        const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int> > *v7; // ebx
  int m_Size; // eax
  int v9; // esi
  int keyDataCount; // [esp+18h] [ebp+Ch]

  v5 = this->m_KeyFunc(a1: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = &this->m_Buckets.m_Memory.m_pMemory[v6];
  m_Size = v7->m_Size;
  v9 = 0;
  keyDataCount = m_Size;
  if ( m_Size > 0 )
  {
    do
    {
      if ( this->m_CompareFunc(a1: &v7->m_Memory.m_pMemory[v9], a2: src) )
        break;
      ++v9;
    }
    while ( v9 < keyDataCount );
    m_Size = keyDataCount;
  }
  if ( v9 == m_Size )
    return 0;
  *pIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10142960
// Name: public: virtual void __near * CEntityDataInstantiator<struct StepSimulationData>::CreateDataObject(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<StepSimulationData>::CreateDataObject(
        CEntityDataInstantiator<StepSimulationData> *this,
        const C_BaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  int v6; // edx
  int v7; // ecx
  CEntityDataInstantiator<StepSimulationData>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
             this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const vgui::PropertySheet::Page_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)MemAlloc_Alloc(nSize: 0xB8u);
    v6 = HIWORD(v3);
    v7 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data = v5;
    _V_memset(
      dest: (int)p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data,
      fill: nullptr,
      count: 0xB8u);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x10142A50
// Name: public: CEntityDataInstantiator<struct ModelScale>::CEntityDataInstantiator<struct ModelScale>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<ModelScale> *__thiscall CEntityDataInstantiator<ModelScale>::CEntityDataInstantiator<ModelScale>(
        CEntityDataInstantiator<ModelScale> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<ModelScale>_vtbl *)&CEntityDataInstantiator<ModelScale>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<ModelScale>::HashEntry *, const CEntityDataInstantiator<ModelScale>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<ModelScale>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10142AC0
// Name: public: virtual void CEntityDataInstantiator<struct physicspushlist_t>::DestroyDataObject(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityDataInstantiator<physicspushlist_t>::DestroyDataObject(
        CEntityDataInstantiator<vphysicsupdateai_t> *this,
        const C_BaseEntity *instance)
{
  const C_BaseEntity *v2; // edx
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // ebx
  unsigned int v4; // esi
  unsigned int v5; // edi
  CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *m_pMemory; // edx
  int v7; // esi
  CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int> > *v8; // ecx
  int m_Size; // edx
  CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *v10; // eax
  CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry entry; // [esp+4h] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+Ch] [ebp-4h] BYREF

  v2 = instance;
  entry.data = nullptr;
  instance = nullptr;
  p_m_HashTable = &this->m_HashTable;
  entry.key = v2;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: &this->m_HashTable,
         src: &entry,
         &pBucket,
         pIndex: (int *)&instance) != 0 )
  {
    v4 = (unsigned int)instance | (pBucket << 16);
    if ( v4 != -1 )
    {
      v5 = HIWORD(v4);
      m_pMemory = p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory;
      v7 = (unsigned __int16)instance;
      C_BaseEntity::operator delete(pMem: m_pMemory[(unsigned __int16)instance].data);
      v8 = &p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v5];
      if ( v7 < v8->m_Size )
      {
        m_Size = v8->m_Size;
        if ( m_Size > 0 )
        {
          if ( v7 != m_Size - 1 )
          {
            v10 = v8->m_Memory.m_pMemory;
            v10[v7].key = v8->m_Memory.m_pMemory[m_Size - 1].key;
            v10[v7].data = v10[m_Size - 1].data;
          }
          --v8->m_Size;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142B60
// Name: public: virtual void __near * CEntityDataInstantiator<struct ModelScale>::CreateDataObject(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<ModelScale>::CreateDataObject(
        CEntityDataInstantiator<ModelScale> *this,
        const C_BaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  int v6; // edx
  int v7; // ecx
  CEntityDataInstantiator<ModelScale>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
             this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const vgui::PropertySheet::Page_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)MemAlloc_Alloc(nSize: 0x10u);
    v6 = HIWORD(v3);
    v7 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data = v5;
    _V_memset(
      dest: (int)p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data,
      fill: nullptr,
      count: 0x10u);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x10142C50
// Name: public: CEntityDataInstantiator<class CWatcherList>::CEntityDataInstantiator<class CWatcherList>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<CWatcherList> *__thiscall CEntityDataInstantiator<CWatcherList>::CEntityDataInstantiator<CWatcherList>(
        CEntityDataInstantiator<CWatcherList> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<CWatcherList>_vtbl *)&CEntityDataInstantiator<CWatcherList>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<CWatcherList>::HashEntry *, const CEntityDataInstantiator<CWatcherList>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<CWatcherList>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10142CC0
// Name: public: virtual void __near * CEntityDataInstantiator<class CWatcherList>::CreateDataObject(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<CWatcherList>::CreateDataObject(
        CEntityDataInstantiator<CWatcherList> *this,
        const C_BaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  int v6; // edx
  int v7; // ecx
  CEntityDataInstantiator<CWatcherList>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
             this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const vgui::PropertySheet::Page_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)MemAlloc_Alloc(nSize: 2u);
    v6 = HIWORD(v3);
    v7 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data = v5;
    _V_memset(
      dest: (int)p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data,
      fill: nullptr,
      count: 2u);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x10142DB0
// Name: public: virtual void CEntityDataInstantiator<class CWatcherList>::DestroyDataObject(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityDataInstantiator<CWatcherList>::DestroyDataObject(
        CEntityDataInstantiator<CWatcherList> *this,
        const C_BaseEntity *instance)
{
  const C_BaseEntity *v2; // edx
  CUtlHash<CEntityDataInstantiator<CWatcherList>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<CWatcherList>::HashEntry const &,CEntityDataInstantiator<CWatcherList>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<CWatcherList>::HashEntry const &)> *p_m_HashTable; // ebx
  unsigned int v4; // esi
  unsigned int v5; // edi
  CEntityDataInstantiator<CWatcherList>::HashEntry *m_pMemory; // edx
  int v7; // esi
  unsigned __int16 *p_m_list; // ebx
  CUtlVector<CEntityDataInstantiator<CWatcherList>::HashEntry,CUtlMemory<CEntityDataInstantiator<CWatcherList>::HashEntry,int> > *v9; // ecx
  int m_Size; // edx
  CEntityDataInstantiator<CWatcherList>::HashEntry *v11; // eax
  unsigned __int16 v12; // [esp-Ch] [ebp-20h]
  CEntityDataInstantiator<CWatcherList>::HashEntry entry; // [esp+4h] [ebp-10h] BYREF
  CUtlHash<CEntityDataInstantiator<CWatcherList>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<CWatcherList>::HashEntry const &,CEntityDataInstantiator<CWatcherList>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<CWatcherList>::HashEntry const &)> *v14; // [esp+Ch] [ebp-8h]
  unsigned int pBucket; // [esp+10h] [ebp-4h] BYREF

  v2 = instance;
  entry.data = nullptr;
  instance = nullptr;
  p_m_HashTable = &this->m_HashTable;
  entry.key = v2;
  v14 = &this->m_HashTable;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) != 0 )
  {
    v4 = (unsigned int)instance | (pBucket << 16);
    if ( v4 != -1 )
    {
      v5 = HIWORD(v4);
      m_pMemory = p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory;
      v7 = (unsigned __int16)instance;
      p_m_list = &m_pMemory[(unsigned __int16)instance].data->m_list;
      if ( p_m_list != nullptr )
      {
        v12 = *p_m_list;
        instance = (const C_BaseEntity *)*p_m_list;
        CUtlMultiList<watcher_t,unsigned short>::RemoveAll(this: &g_WatcherList, list: v12);
        CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::Unlink(
          this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&g_WatcherList.m_List,
          elem: (unsigned __int16)instance);
        g_WatcherList.m_List.m_Memory.m_pMemory[(unsigned __int16)instance].m_Next = g_WatcherList.m_List.m_FirstFree;
        g_WatcherList.m_List.m_FirstFree = (unsigned __int16)instance;
        C_BaseEntity::operator delete(pMem: p_m_list);
      }
      v9 = &v14->m_Buckets.m_Memory.m_pMemory[v5];
      if ( v7 < v9->m_Size )
      {
        m_Size = v9->m_Size;
        if ( m_Size > 0 )
        {
          if ( v7 != m_Size - 1 )
          {
            v11 = v9->m_Memory.m_pMemory;
            v11[v7].key = v9->m_Memory.m_pMemory[m_Size - 1].key;
            v11[v7].data = v11[m_Size - 1].data;
          }
          --v9->m_Size;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142EA0
// Name: public: CEntityDataInstantiator<struct physicspushlist_t>::CEntityDataInstantiator<struct physicspushlist_t>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<physicspushlist_t> *__thiscall CEntityDataInstantiator<physicspushlist_t>::CEntityDataInstantiator<physicspushlist_t>(
        CEntityDataInstantiator<physicspushlist_t> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<physicspushlist_t>_vtbl *)&CEntityDataInstantiator<physicspushlist_t>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<physicspushlist_t>::HashEntry *, const CEntityDataInstantiator<physicspushlist_t>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<physicspushlist_t>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10142F10
// Name: public: physicspushlist_t::physicspushlist_t(void)
// Source: json
//------------------------------------------------------------------------------
physicspushlist_t *__thiscall physicspushlist_t::physicspushlist_t(physicspushlist_t *this)
{
  this->pushedEnts[0].m_Index = -1;
  this->pushedEnts[1].m_Index = -1;
  this->pushedEnts[2].m_Index = -1;
  this->pushedEnts[3].m_Index = -1;
  this->pushedEnts[4].m_Index = -1;
  this->pushedEnts[5].m_Index = -1;
  this->pushedEnts[6].m_Index = -1;
  this->pushedEnts[7].m_Index = -1;
  this->pushedEnts[8].m_Index = -1;
  this->pushedEnts[9].m_Index = -1;
  this->pushedEnts[10].m_Index = -1;
  this->pushedEnts[11].m_Index = -1;
  this->pushedEnts[12].m_Index = -1;
  this->pushedEnts[13].m_Index = -1;
  this->pushedEnts[14].m_Index = -1;
  this->pushedEnts[15].m_Index = -1;
  this->pushedEnts[16].m_Index = -1;
  this->pushedEnts[17].m_Index = -1;
  this->pushedEnts[18].m_Index = -1;
  this->pushedEnts[19].m_Index = -1;
  this->pushedEnts[20].m_Index = -1;
  this->pushedEnts[21].m_Index = -1;
  this->pushedEnts[22].m_Index = -1;
  this->pushedEnts[23].m_Index = -1;
  this->pushedEnts[24].m_Index = -1;
  this->pushedEnts[25].m_Index = -1;
  this->pushedEnts[26].m_Index = -1;
  this->pushedEnts[27].m_Index = -1;
  this->pushedEnts[28].m_Index = -1;
  this->pushedEnts[29].m_Index = -1;
  this->pushedEnts[30].m_Index = -1;
  this->pushedEnts[31].m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10142F90
// Name: public: virtual void __near * CEntityDataInstantiator<struct physicspushlist_t>::CreateDataObject(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<physicspushlist_t>::CreateDataObject(
        CEntityDataInstantiator<physicspushlist_t> *this,
        const C_BaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  physicspushlist_t *v5; // eax
  physicspushlist_t *v6; // eax
  int v7; // edx
  int v8; // ecx
  CEntityDataInstantiator<physicspushlist_t>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
             this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const vgui::PropertySheet::Page_t *)&entry);
    }
    v5 = (physicspushlist_t *)MemAlloc_Alloc(nSize: 0x220u);
    if ( v5 != nullptr )
      v6 = physicspushlist_t::physicspushlist_t(this: v5);
    else
      v6 = nullptr;
    v7 = HIWORD(v3);
    v8 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v7].m_Memory.m_pMemory[v8].data = (vphysicsupdateai_t *)v6;
    _V_memset(
      dest: (int)p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v7].m_Memory.m_pMemory[v8].data,
      fill: nullptr,
      count: 0x220u);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x101430A0
// Name: public: CEntityDataInstantiator<struct vphysicsupdateai_t>::CEntityDataInstantiator<struct vphysicsupdateai_t>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<vphysicsupdateai_t> *__thiscall CEntityDataInstantiator<vphysicsupdateai_t>::CEntityDataInstantiator<vphysicsupdateai_t>(
        CEntityDataInstantiator<vphysicsupdateai_t> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<vphysicsupdateai_t>_vtbl *)&CEntityDataInstantiator<vphysicsupdateai_t>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *, const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10143110
// Name: public: virtual void __near * CEntityDataInstantiator<struct vphysicsupdateai_t>::CreateDataObject(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<vphysicsupdateai_t>::CreateDataObject(
        CEntityDataInstantiator<vphysicsupdateai_t> *this,
        const C_BaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  int v6; // edx
  int v7; // ecx
  CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = &this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: &this->m_HashTable,
         src: &entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: &entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
             this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const vgui::PropertySheet::Page_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)MemAlloc_Alloc(nSize: 0xCu);
    v6 = HIWORD(v3);
    v7 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data = v5;
    _V_memset(
      dest: (int)p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data,
      fill: nullptr,
      count: 0xCu);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x10143200
// Name: public: virtual bool CDataObjectAccessSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataObjectAccessSystem::Init(CDataObjectAccessSystem *this)
{
  CEntityDataInstantiator<touchlink_t> *v2; // eax
  CEntityDataInstantiator<touchlink_t> *v3; // eax
  CEntityDataInstantiator<groundlink_t> *v4; // eax
  CEntityDataInstantiator<groundlink_t> *v5; // eax
  CEntityDataInstantiator<StepSimulationData> *v6; // eax
  CEntityDataInstantiator<StepSimulationData> *v7; // eax
  CEntityDataInstantiator<ModelScale> *v8; // eax
  CEntityDataInstantiator<ModelScale> *v9; // eax
  CEntityDataInstantiator<CWatcherList> *v10; // eax
  CEntityDataInstantiator<CWatcherList> *v11; // eax
  CEntityDataInstantiator<physicspushlist_t> *v12; // eax
  CEntityDataInstantiator<physicspushlist_t> *v13; // eax
  CEntityDataInstantiator<vphysicsupdateai_t> *v14; // eax
  CEntityDataInstantiator<vphysicsupdateai_t> *v15; // eax
  CEntityDataInstantiator<CWatcherList> *v16; // eax
  CEntityDataInstantiator<CWatcherList> *v17; // eax

  v2 = (CEntityDataInstantiator<touchlink_t> *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v2 != nullptr )
    v3 = CEntityDataInstantiator<touchlink_t>::CEntityDataInstantiator<touchlink_t>(this: v2);
  else
    v3 = nullptr;
  if ( this->m_Accessors[1] == nullptr )
    this->m_Accessors[1] = v3;
  v4 = (CEntityDataInstantiator<groundlink_t> *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v4 != nullptr )
    v5 = CEntityDataInstantiator<groundlink_t>::CEntityDataInstantiator<groundlink_t>(this: v4);
  else
    v5 = nullptr;
  if ( this->m_Accessors[0] == nullptr )
    this->m_Accessors[0] = v5;
  v6 = (CEntityDataInstantiator<StepSimulationData> *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v6 != nullptr )
    v7 = CEntityDataInstantiator<StepSimulationData>::CEntityDataInstantiator<StepSimulationData>(this: v6);
  else
    v7 = nullptr;
  if ( this->m_Accessors[2] == nullptr )
    this->m_Accessors[2] = v7;
  v8 = (CEntityDataInstantiator<ModelScale> *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v8 != nullptr )
    v9 = CEntityDataInstantiator<ModelScale>::CEntityDataInstantiator<ModelScale>(this: v8);
  else
    v9 = nullptr;
  if ( this->m_Accessors[3] == nullptr )
    this->m_Accessors[3] = v9;
  v10 = (CEntityDataInstantiator<CWatcherList> *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v10 != nullptr )
    v11 = CEntityDataInstantiator<CWatcherList>::CEntityDataInstantiator<CWatcherList>(this: v10);
  else
    v11 = nullptr;
  if ( this->m_Accessors[4] == nullptr )
    this->m_Accessors[4] = v11;
  v12 = (CEntityDataInstantiator<physicspushlist_t> *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v12 != nullptr )
    v13 = CEntityDataInstantiator<physicspushlist_t>::CEntityDataInstantiator<physicspushlist_t>(this: v12);
  else
    v13 = nullptr;
  if ( this->m_Accessors[5] == nullptr )
    this->m_Accessors[5] = v13;
  v14 = (CEntityDataInstantiator<vphysicsupdateai_t> *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v14 != nullptr )
    v15 = CEntityDataInstantiator<vphysicsupdateai_t>::CEntityDataInstantiator<vphysicsupdateai_t>(this: v14);
  else
    v15 = nullptr;
  if ( this->m_Accessors[6] == nullptr )
    this->m_Accessors[6] = v15;
  v16 = (CEntityDataInstantiator<CWatcherList> *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v16 != nullptr )
    v17 = CEntityDataInstantiator<CWatcherList>::CEntityDataInstantiator<CWatcherList>(this: v16);
  else
    v17 = nullptr;
  if ( this->m_Accessors[7] == nullptr )
    this->m_Accessors[7] = v17;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1036E300
// Name: public: void CUtlMultiList<struct watcher_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<watcher_t,unsigned short>::RemoveAll(
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

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10195CE0
// Name: public: bool CBaseEntity::HasDataObjectType(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::HasDataObjectType(CBaseEntity *this, char type)
{
  return ((1 << type) & this->m_fDataObjectTypes) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10195D00
// Name: struct touchlink_t __near * AllocTouchLink(void)
// Source: json
//------------------------------------------------------------------------------
touchlink_t *__cdecl AllocTouchLink()
{
  touchlink_t *result; // eax

  result = (touchlink_t *)CUtlMemoryPool::Alloc(this: &g_EdictTouchLinks, amount: 0x14u);
  if ( result != nullptr )
  {
    ++linksallocated;
  }
  else
  {
    DevWarning(a1: "AllocTouchLink: failed to allocate touchlink_t.\n");
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10195D30
// Name: public: bool CBaseEntity::IsCurrentlyTouching(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::IsCurrentlyTouching(CBaseEntity *this)
{
  return (this->m_fDataObjectTypes & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10195D40
// Name: public: static class CGameTrace const __near & CBaseEntity::GetTouchTrace(void)
// Source: json
//------------------------------------------------------------------------------
const CGameTrace *__cdecl CBaseEntity::GetTouchTrace()
{
  return &g_TouchTrace;
}

//------------------------------------------------------------------------------
// Address: 0x10195D50
// Name: private: static bool CThinkSyncTester::ThinkLessFunc(struct ThinkSync const __near &,struct ThinkSync const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CThinkSyncTester::ThinkLessFunc(const AI_NearNode_t *node1, const AI_NearNode_t *node2)
{
  return node2->dist > node1->dist;
}

//------------------------------------------------------------------------------
// Address: 0x10195D70
// Name: public: void CBaseEntity::SetGroundChangeTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetGroundChangeTime(CBaseEntity *this, float flTime)
{
  this->m_flGroundChangeTime = flTime;
}

//------------------------------------------------------------------------------
// Address: 0x10195D90
// Name: public: float CBaseEntity::GetGroundChangeTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseEntity::GetGroundChangeTime(CBaseEntity *this)
{
  return this->m_flGroundChangeTime;
}

//------------------------------------------------------------------------------
// Address: 0x10195DA0
// Name: public: void __near * CBaseEntity::GetDataObject(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseEntity::GetDataObject(CBaseEntity *this, unsigned int type)
{
  IEntityDataInstantiator *v4; // ecx

  if ( ((1 << type) & this->m_fDataObjectTypes) != 0
    && type <= 0x1F
    && (v4 = g_DataObjectAccessSystem.m_Accessors[type]) != nullptr )
  {
    return v4->GetDataObject(this: v4, a2: this);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195DE0
// Name: public: void __near * CBaseEntity::CreateDataObject(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseEntity::CreateDataObject(CBaseEntity *this, unsigned int type)
{
  IEntityDataInstantiator *v3; // ecx

  this->m_fDataObjectTypes |= 1 << type;
  if ( type <= 0x1F && (v3 = g_DataObjectAccessSystem.m_Accessors[type]) != nullptr )
    return v3->CreateDataObject(this: v3, a2: this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10195E20
// Name: public: void CBaseEntity::DestroyDataObject(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DestroyDataObject(CBaseEntity *this, unsigned int type)
{
  IEntityDataInstantiator *v3; // ecx

  if ( ((1 << type) & this->m_fDataObjectTypes) != 0 )
  {
    if ( type <= 0x1F )
    {
      v3 = g_DataObjectAccessSystem.m_Accessors[type];
      if ( v3 != nullptr )
        v3->DestroyDataObject(this: v3, a2: this);
    }
    this->m_fDataObjectTypes &= ~(1 << type);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195E60
// Name: public: void CBaseEntity::DestroyAllDataObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::DestroyAllDataObjects(CBaseEntity *this)
{
  int v2; // esi
  int v3; // edi
  IEntityDataInstantiator *v4; // ecx

  v2 = 0;
  v3 = 1;
  do
  {
    if ( (v3 & this->m_fDataObjectTypes) != 0 )
    {
      if ( (unsigned int)v2 <= 0x1F )
      {
        v4 = g_DataObjectAccessSystem.m_Accessors[v2];
        if ( v4 != nullptr )
          v4->DestroyDataObject(this: v4, a2: this);
      }
      this->m_fDataObjectTypes &= ~v3;
    }
    ++v2;
    v3 = __ROL4__(v3, 1);
  }
  while ( v2 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x10195EB0
// Name: private: void CBaseEntity::PhysicsTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsTouch(CBaseEntity *this, CBaseEntity *pentOther)
{
  if ( pentOther != nullptr && (this->m_iEFlags & 1) == 0 && (pentOther->m_iEFlags & 1) == 0 )
    this->Touch(this, a2: pentOther);
}

//------------------------------------------------------------------------------
// Address: 0x10195EE0
// Name: private: void CBaseEntity::PhysicsStartTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsStartTouch(CBaseEntity *this, CBaseEntity *pentOther)
{
  if ( pentOther != nullptr && (this->m_iEFlags & 1) == 0 && (pentOther->m_iEFlags & 1) == 0 )
  {
    this->StartTouch(this, a2: pentOther);
    this->Touch(this, a2: pentOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195F20
// Name: private: void CBaseEntity::PhysicsCheckVelocity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsCheckVelocity(CBaseEntity *this)
{
  float z; // ecx
  unsigned int v3; // edx
  char v4; // al
  int v5; // ebx
  float *v6; // ebx
  int v7; // edx
  const char *Classname; // eax
  int v9; // ebx
  const char *v10; // eax
  float m_fValue; // xmm0_4
  float v12; // xmm0_4
  Vector vecAbsVelocity; // [esp+4h] [ebp-20h] BYREF
  Vector origin; // [esp+10h] [ebp-14h] BYREF
  int v15; // [esp+1Ch] [ebp-8h]
  float *v16; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_vecAbsOrigin.z;
  v3 = (unsigned int)this->m_iEFlags >> 12;
  *(_QWORD *)&origin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  origin.z = z;
  if ( (v3 & 1) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  vecAbsVelocity = this->m_vecAbsVelocity;
  v4 = 0;
  v5 = 0;
  v15 = 0;
  do
  {
    v6 = (float *)((char *)&vecAbsVelocity.x + v5);
    v7 = *(_DWORD *)v6 & 0x7F800000;
    v16 = v6;
    if ( v7 == 2139095040 )
    {
      Classname = CBaseEntity::GetClassname(this);
      _Msg(a1: "Got a NaN velocity on %s\n", Classname);
      *v6 = 0.0;
      v4 = 1;
    }
    v9 = v15;
    if ( (*(_DWORD *)((_BYTE *)&origin.x + v15) & 0x7F800000) == 0x7F800000 )
    {
      v10 = CBaseEntity::GetClassname(this);
      _Msg(a1: "Got a NaN origin on %s\n", v10);
      *(float *)((char *)&origin.x + v9) = 0.0;
      v4 = 1;
    }
    m_fValue = sv_maxvelocity.m_pParent->m_Value.m_fValue;
    if ( *v16 <= m_fValue )
    {
      LODWORD(v12) = LODWORD(m_fValue) ^ _mask__NegFloat_;
      if ( v12 <= *v16 )
        goto LABEL_15;
      *v16 = v12;
    }
    else
    {
      *v16 = m_fValue;
    }
    v4 = 1;
LABEL_15:
    v5 = v9 + 4;
    v15 = v5;
  }
  while ( v5 < 12 );
  if ( v4 != 0 )
  {
    CBaseEntity::SetAbsOrigin(this, absOrigin: &origin);
    CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196060
// Name: protected: int CBaseEntity::PhysicsClipVelocity(class Vector const __near &,class Vector const __near &,class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::PhysicsClipVelocity(
        CBaseEntity *this,
        const Vector *in,
        const Vector *normal,
        Vector *out,
        float overbounce)
{
  float z; // xmm3_4
  int v6; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  int result; // eax

  z = normal->z;
  v6 = z > 0.0;
  if ( z == 0.0 )
    v6 |= 2u;
  v7 = (float)((float)((float)(in->y * normal->y) + (float)(normal->x * in->x)) + (float)(z * in->z)) * overbounce;
  v8 = in->x - (float)(normal->x * v7);
  out->x = v8;
  if ( v8 > -0.1 && v8 < 0.1 )
    out->x = 0.0;
  v9 = in->y - (float)(normal->y * v7);
  out->y = v9;
  if ( v9 > -0.1 && v9 < 0.1 )
    out->y = 0.0;
  v10 = in->z - (float)(v7 * normal->z);
  out->z = v10;
  result = v6;
  if ( v10 > -0.1 && v10 < 0.1 )
    out->z = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10196230
// Name: public: virtual void CDataObjectAccessSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataObjectAccessSystem::Shutdown(CDataObjectAccessSystem *this)
{
  IEntityDataInstantiator **m_Accessors; // esi
  int i; // edi

  m_Accessors = this->m_Accessors;
  for ( i = 32; i != 0; --i )
  {
    if ( *m_Accessors != nullptr )
      ((void (__thiscall *)(IEntityDataInstantiator *, int))(*m_Accessors)->dtr_IEntityDataInstantiator)(
        a1: *m_Accessors,
        a2: 1);
    *m_Accessors++ = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196260
// Name: private: static bool CEntityDataInstantiator<struct ModelScale>::CompareFunc(struct CEntityDataInstantiator<struct ModelScale>::HashEntry const __near &,struct CEntityDataInstantiator<struct ModelScale>::HashEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CEntityDataInstantiator<ModelScale>::CompareFunc(
        const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *src1,
        const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *src2)
{
  return src1->key == src2->key;
}

//------------------------------------------------------------------------------
// Address: 0x10196280
// Name: private: static unsigned int CEntityDataInstantiator<struct physicspushlist_t>::KeyFunc(struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CEntityDataInstantiator<physicspushlist_t>::KeyFunc(
        const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *src)
{
  return (unsigned int)src->key >> 10;
}

//------------------------------------------------------------------------------
// Address: 0x10196330
// Name: public: void CUtlMemory<struct CEntityDataInstantiator<struct StepSimulationData>::HashEntry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
        CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // edx
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
      this->m_pMemory = (CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: v7);
    else
      this->m_pMemory = (CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101963D0
// Name: public: static void CBaseEntity::PhysicsRemoveToucher(class CBaseEntity __near *,struct touchlink_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::PhysicsRemoveToucher(CBaseEntity *otherEntity, touchlink_t *link)
{
  CBaseEntity *v2; // ebx
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CBaseEntity **v10; // eax
  CBaseEntity *v11; // eax
  edict_t *m_pPev; // eax
  unsigned int v13; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity_vtbl *v15; // ecx
  signed int v16; // edx
  CBaseEntity *v17; // edi
  const char *v18; // eax
  const char *DebugName; // [esp-14h] [ebp-20h]
  signed int v20; // [esp-10h] [ebp-1Ch]
  int v21; // [esp-8h] [ebp-14h]
  int m_PeakAlloc; // [esp-4h] [ebp-10h]
  signed int linka; // [esp+18h] [ebp+Ch]

  v2 = otherEntity;
  if ( (link->flags & 1) != 0 )
  {
    m_Index = link->entityTouched.m_Index;
    if ( link->entityTouched.m_Index != -1 )
    {
      v5 = (unsigned __int16)m_Index;
      v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v7 = HIWORD(m_Index);
      if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr && otherEntity != nullptr )
      {
        v8 = v5;
        v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
        v10 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v8];
        if ( v9 )
          v11 = *v10;
        else
          v11 = nullptr;
        otherEntity->EndTouch(this: otherEntity, a2: v11);
      }
    }
  }
  link->nextLink->prevLink = link->prevLink;
  link->prevLink->nextLink = link->nextLink;
  if ( debug_touchlinks.m_pParent != nullptr && debug_touchlinks.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pPev = otherEntity->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      linka = m_pPev - gpGlobals->pEdicts;
    else
      linka = 0;
    v13 = link->entityTouched.m_Index;
    if ( link->entityTouched.m_Index == -1
      || (v2 = otherEntity, g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13)) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    }
    v15 = m_pEntity[6].__vftable;
    if ( v15 != nullptr )
      v16 = ((char *)v15 - (char *)gpGlobals->pEdicts) >> 4;
    else
      v16 = 0;
    if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
      v17 = nullptr;
    else
      v17 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    m_PeakAlloc = g_EdictTouchLinks.m_PeakAlloc;
    v21 = linksallocated;
    v20 = v16;
    DebugName = CBaseEntity::GetDebugName(this: v2);
    v18 = CBaseEntity::GetDebugName(this: v17);
    _Msg(a1: "remove 0x%x: %s-%s (%d-%d) [%d in play, %d max]\n", link, v18, DebugName, v20, linka, v21, m_PeakAlloc);
  }
  if ( link == g_pNextLink )
    g_pNextLink = link->nextLink;
  --linksallocated;
  link->nextLink = nullptr;
  link->prevLink = nullptr;
  CUtlMemoryPool::Free(this: &g_EdictTouchLinks, memBlock: link);
}

//------------------------------------------------------------------------------
// Address: 0x10196540
// Name: public: struct groundlink_t __near * CBaseEntity::AddEntityToGroundList(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
groundlink_t *__thiscall CBaseEntity::AddEntityToGroundList(CBaseEntity *this, CBaseEntity *other)
{
  CBaseEntity *v2; // ebx
  groundlink_t *result; // eax
  groundlink_t *v4; // esi
  groundlink_t **p_nextLink; // edi
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // edx
  groundlink_t *v8; // eax
  unsigned int *v9; // esi
  groundlink_t *root; // [esp+4h] [ebp-8h]

  v2 = this;
  if ( this == other || (other->m_iEFlags & 1) != 0 )
    return nullptr;
  if ( (this->m_fDataObjectTypes & 1) == 0
    || (g_DataObjectAccessSystem.m_Accessors[0] != nullptr
      ? (v4 = (groundlink_t *)g_DataObjectAccessSystem.m_Accessors[0]->GetDataObject(
                                this: g_DataObjectAccessSystem.m_Accessors[0],
                                a2: this))
      : (v4 = nullptr),
        root = v4,
        v4 == nullptr) )
  {
    v2->m_fDataObjectTypes |= 1u;
    if ( g_DataObjectAccessSystem.m_Accessors[0] != nullptr )
      v8 = (groundlink_t *)g_DataObjectAccessSystem.m_Accessors[0]->CreateDataObject(
                             this: g_DataObjectAccessSystem.m_Accessors[0],
                             a2: v2);
    else
      v8 = nullptr;
    p_nextLink = &v8->nextLink;
    root = v8;
    v8->nextLink = v8;
    v8->prevLink = v8;
LABEL_21:
    v9 = (unsigned int *)CUtlMemoryPool::Alloc(this: &g_EntityGroundLinks, amount: 0xCu);
    if ( v9 != nullptr )
    {
      ++groundlinksallocated;
      *v9 = other->GetRefEHandle(this: other)->m_Index;
      v9[1] = (unsigned int)*p_nextLink;
      v9[2] = (unsigned int)root;
      *p_nextLink = (groundlink_t *)v9;
      *(_DWORD *)(v9[1] + 8) = v9;
      if ( (v2->m_iEFlags & 1) == 0 && (other->m_iEFlags & 1) == 0 )
        CBaseEntity::AddFlag(this: other, flags: 1);
      return (groundlink_t *)v9;
    }
    else
    {
      DevMsg(a1: "AllocGroundLink: failed to allocate groundlink_t.!!!\n");
      return nullptr;
    }
  }
  result = v4->nextLink;
  p_nextLink = &v4->nextLink;
  if ( result == v4 )
    goto LABEL_21;
  while ( 1 )
  {
    m_Index = result->entity.m_Index;
    if ( result->entity.m_Index == -1
      || (v2 = this, g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    if ( m_pEntity == other )
      return result;
    result = result->nextLink;
    if ( result == v4 )
      goto LABEL_21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196680
// Name: public: static void CBaseEntity::PhysicsRemoveGround(class CBaseEntity __near *,struct groundlink_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::PhysicsRemoveGround(CBaseEntity *other, groundlink_t *link)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // eax

  m_Index = link->entity.m_Index;
  if ( link->entity.m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
      {
        v9 = *v8;
        if ( v9 != nullptr && other != nullptr )
          CBaseEntity::RemoveFlag(this: v9, flagsToRemove: 1);
      }
    }
  }
  link->nextLink->prevLink = link->prevLink;
  link->prevLink->nextLink = link->nextLink;
  --groundlinksallocated;
  CUtlMemoryPool::Free(this: &g_EntityGroundLinks, memBlock: link);
}

//------------------------------------------------------------------------------
// Address: 0x10196700
// Name: private: struct touchlink_t __near * CBaseEntity::PhysicsMarkEntityAsTouched(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
touchlink_t *__thiscall CBaseEntity::PhysicsMarkEntityAsTouched(CBaseEntity *this, CBaseEntity *other)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v6; // eax
  CBaseEntity *v7; // ecx
  touchlink_t *v8; // ebx
  touchlink_t *nextLink; // esi
  touchlink_t *v10; // eax
  CBaseEntity *v11; // ebx
  const char *v12; // eax
  const char *DebugName; // [esp-18h] [ebp-28h]
  edict_t *v14; // [esp-14h] [ebp-24h]
  edict_t *v15; // [esp-10h] [ebp-20h]
  int v16; // [esp-Ch] [ebp-1Ch]
  int m_PeakAlloc; // [esp-8h] [ebp-18h]
  touchlink_t *root; // [esp+8h] [ebp-8h]
  touchlink_t **p_nextLink; // [esp+Ch] [ebp-4h]

  if ( this == other )
    return nullptr;
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == other )
    return nullptr;
  v6 = other->m_hMoveParent.m_Value.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  if ( this == v7
    || ((this->m_fFlags.m_Value | other->m_fFlags.m_Value) & 0x800000) != 0
    || (this->m_Collision.m_usSolidFlags.m_Value & 8) != 0
    && (other->m_Collision.m_usSolidFlags.m_Value & 8) != 0
    && !CBaseEntity::IsSolid(this)
    && !CBaseEntity::IsSolid(this: other)
    || (other->m_iEFlags & 1) != 0
    || (this->m_iEFlags & 1) != 0 )
  {
    return nullptr;
  }
  if ( (this->m_fDataObjectTypes & 2) != 0
    && (g_DataObjectAccessSystem.m_Accessors[1] != nullptr
      ? (v8 = (touchlink_t *)g_DataObjectAccessSystem.m_Accessors[1]->GetDataObject(
                               this: g_DataObjectAccessSystem.m_Accessors[1],
                               a2: this))
      : (v8 = nullptr),
        root = v8,
        v8 != nullptr) )
  {
    nextLink = v8->nextLink;
    p_nextLink = &v8->nextLink;
    if ( nextLink != v8 )
    {
      while ( !CHandle<CBaseEntity>::operator==(this: &nextLink->entityTouched, val: other) )
      {
        nextLink = nextLink->nextLink;
        if ( nextLink == v8 )
          goto LABEL_35;
      }
      nextLink->touchStamp = this->touchStamp;
      if ( !CBaseEntity::sm_bDisableTouchFuncs )
      {
        CBaseEntity::PhysicsTouch(this, pentOther: other);
        return nextLink;
      }
      return nextLink;
    }
  }
  else
  {
    this->m_fDataObjectTypes |= 2u;
    if ( g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
      v10 = (touchlink_t *)g_DataObjectAccessSystem.m_Accessors[1]->CreateDataObject(
                             this: g_DataObjectAccessSystem.m_Accessors[1],
                             a2: this);
    else
      v10 = nullptr;
    root = v10;
    v10->prevLink = v10;
    p_nextLink = &v10->nextLink;
    v10->nextLink = v10;
  }
LABEL_35:
  nextLink = AllocTouchLink();
  if ( debug_touchlinks.m_pParent != nullptr && debug_touchlinks.m_pParent->m_Value.m_nValue != 0 )
  {
    v11 = other;
    m_PeakAlloc = g_EdictTouchLinks.m_PeakAlloc;
    v16 = linksallocated;
    v15 = CBaseEntity::entindex(this: other);
    v14 = CBaseEntity::entindex(this);
    DebugName = CBaseEntity::GetDebugName(this: other);
    v12 = CBaseEntity::GetDebugName(this);
    _Msg(a1: "add 0x%x: %s-%s (%d-%d) [%d in play, %d max]\n", nextLink, v12, DebugName, v14, v15, v16, m_PeakAlloc);
  }
  else
  {
    v11 = other;
  }
  if ( nextLink == nullptr )
    return nullptr;
  nextLink->touchStamp = this->touchStamp;
  CHandle<CBaseEntity>::operator=(this: &nextLink->entityTouched, val: v11);
  nextLink->flags = 0;
  nextLink->nextLink = *p_nextLink;
  nextLink->prevLink = root;
  *p_nextLink = nextLink;
  nextLink->nextLink->prevLink = nextLink;
  if ( (CBaseEntity::IsSolid(this) && (this->m_Collision.m_usSolidFlags.m_Value & 0x20) == 0
     || (this->m_Collision.m_usSolidFlags.m_Value & 8) != 0)
    && (v11->m_Collision.m_usSolidFlags.m_Value & 8) == 0 )
  {
    nextLink->flags |= 1u;
    if ( !CBaseEntity::sm_bDisableTouchFuncs )
      CBaseEntity::PhysicsStartTouch(this, pentOther: v11);
  }
  return nextLink;
}

//------------------------------------------------------------------------------
// Address: 0x10196970
// Name: public: bool CBaseEntity::PhysicsCheckWater(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseEntity::PhysicsCheckWater(CBaseEntity *this)
{
  return this->m_nWaterLevel.m_Value > 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10196980
// Name: private: void CBaseEntity::SimulateAngles(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SimulateAngles(CBaseEntity *this, float flFrameTime)
{
  QAngle angles; // [esp+0h] [ebp-Ch] BYREF

  angles.x = (float)(this->m_vecAngVelocity.x * flFrameTime) + this->m_angRotation.m_Value.x;
  angles.y = (float)(this->m_vecAngVelocity.y * flFrameTime) + this->m_angRotation.m_Value.y;
  angles.z = (float)(this->m_vecAngVelocity.z * flFrameTime) + this->m_angRotation.m_Value.z;
  CBaseEntity::SetLocalAngles(this, &angles);
}

//------------------------------------------------------------------------------
// Address: 0x101969F0
// Name: public: class CBaseEntity __near * CBaseEntity::GetGroundEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::GetGroundEntity(CBaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hGroundEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10196A20
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBaseEntity::NetworkVar_m_hGroundEntity>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hGroundEntity>::Set(
        CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hGroundEntity> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    (*(void (__thiscall **)(CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hGroundEntity> *, CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hGroundEntity> *))(*((_DWORD *)this - 86) + 692))(
      a1: this - 86,
      a2: this);
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x10196CD0
// Name: public: unsigned short CUtlMultiList<struct watcher_t,unsigned short>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<watcher_t,unsigned short>::Alloc(CUtlMultiList<watcher_t,unsigned short> *this)
{
  int m_FirstFree; // ecx
  int m_MaxElementIndex; // ecx
  int result; // eax
  int v5; // ecx
  CUtlMultiList<watcher_t,unsigned short>::ListElem_t *v6; // esi

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
      v6->m_Element.hWatcher.m_Index = -1;
    return result;
  }
  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (unsigned __int16)m_MaxElementIndex != m_MaxElementIndex || (_WORD)m_MaxElementIndex == 0xFFFF )
  {
    if ( `CUtlMultiList<watcher_t,unsigned short>::Alloc'::`9'::__executeCount < 10 )
    {
      ++`CUtlMultiList<watcher_t,unsigned short>::Alloc'::`9'::__executeCount;
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
  if ( `CUtlMultiList<watcher_t,unsigned short>::Alloc'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlMultiList<watcher_t,unsigned short>::Alloc'::`19'::__executeCount;
  _Warning(a1: "CUtlMultiList overflow! (exhausted memory allocator)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10197220
// Name: private: unsigned short CWatcherList::Find(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWatcherList::Find(CWatcherList *this, CBaseEntity *pEntity)
{
  int result; // eax
  unsigned __int16 m_Next; // si
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // edx

  result = g_WatcherList.m_List.m_Memory.m_pMemory[this->m_list].m_Element.m_Head;
  if ( (_WORD)result == 0xFFFF )
    return 0xFFFF;
  while ( 1 )
  {
    m_Next = g_WatcherList.m_Memory.m_pMemory[(unsigned __int16)result].m_Next;
    m_Index = g_WatcherList.m_Memory.m_pMemory[(unsigned __int16)result].m_Element.hWatcher.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == pEntity )
      break;
    result = g_WatcherList.m_Memory.m_pMemory[(unsigned __int16)result].m_Next;
    if ( m_Next == 0xFFFF )
      return 0xFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101972A0
// Name: public: static void CBaseEntity::PhysicsNotifyOtherOfUntouch(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::PhysicsNotifyOtherOfUntouch(CBaseEntity *ent, CBaseEntity *other)
{
  touchlink_t *v2; // eax
  touchlink_t *v3; // esi
  touchlink_t *nextLink; // edx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  if ( other != nullptr && (other->m_fDataObjectTypes & 2) != 0 && g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
  {
    v2 = (touchlink_t *)g_DataObjectAccessSystem.m_Accessors[1]->GetDataObject(
                          this: g_DataObjectAccessSystem.m_Accessors[1],
                          a2: other);
    v3 = v2;
    if ( v2 != nullptr )
    {
      nextLink = v2->nextLink;
      if ( nextLink != v2 )
      {
        while ( 1 )
        {
          m_Index = nextLink->entityTouched.m_Index;
          if ( nextLink->entityTouched.m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          if ( m_pEntity == ent )
            break;
          nextLink = nextLink->nextLink;
          if ( nextLink == v3 )
            return;
        }
        CBaseEntity::PhysicsRemoveToucher(otherEntity: other, link: nextLink);
        if ( g_bCleanupDatObject && v3->nextLink == v3 && v3->prevLink == v3 && (other->m_fDataObjectTypes & 2) != 0 )
        {
          if ( g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
            g_DataObjectAccessSystem.m_Accessors[1]->DestroyDataObject(
              this: g_DataObjectAccessSystem.m_Accessors[1],
              a2: other);
          other->m_fDataObjectTypes &= ~2u;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197370
// Name: public: static void CBaseEntity::PhysicsRemoveTouchedList(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::PhysicsRemoveTouchedList(CBaseEntity *ent)
{
  touchlink_t *v2; // eax
  touchlink_t *v3; // esi
  unsigned int m_Index; // eax
  touchlink_t *v5; // edi
  CBaseEntity *m_pEntity; // ecx
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx
  IHandleEntity_vtbl *v9; // ecx
  signed int v10; // edx
  CBaseEntity *v11; // edi
  const char *v12; // eax
  unsigned int v13; // ecx
  const char *DebugName; // [esp-1Ch] [ebp-28h]
  edict_t *v15; // [esp-18h] [ebp-24h]
  signed int v16; // [esp-14h] [ebp-20h]
  int v17; // [esp-10h] [ebp-1Ch]
  int m_PeakAlloc; // [esp-Ch] [ebp-18h]
  touchlink_t *nextLink; // [esp+4h] [ebp-8h]
  touchlink_t *v20; // [esp+8h] [ebp-4h]
  bool saveCleanup_3; // [esp+17h] [ebp+Bh]

  if ( (ent->m_fDataObjectTypes & 2) != 0 )
  {
    if ( g_DataObjectAccessSystem.m_Accessors[1] != nullptr
      && (v2 = (touchlink_t *)g_DataObjectAccessSystem.m_Accessors[1]->GetDataObject(
                                this: g_DataObjectAccessSystem.m_Accessors[1],
                                a2: ent),
          v20 = v2,
          v2 != nullptr) )
    {
      v3 = v2->nextLink;
      saveCleanup_3 = g_bCleanupDatObject;
      g_bCleanupDatObject = false;
      if ( v3 != nullptr )
      {
        while ( v3 != v2 )
        {
          m_Index = v3->entityTouched.m_Index;
          v5 = v3->nextLink;
          nextLink = v5;
          if ( v3->entityTouched.m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          CBaseEntity::PhysicsNotifyOtherOfUntouch(ent, other: m_pEntity);
          if ( debug_touchlinks.m_pParent != nullptr && debug_touchlinks.m_pParent->m_Value.m_nValue != 0 )
          {
            v7 = v3->entityTouched.m_Index;
            if ( v3->entityTouched.m_Index == -1
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
            {
              v8 = nullptr;
            }
            else
            {
              v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
            }
            v9 = v8[6].__vftable;
            if ( v9 != nullptr )
              v10 = ((char *)v9 - (char *)gpGlobals->pEdicts) >> 4;
            else
              v10 = 0;
            if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
              v11 = nullptr;
            else
              v11 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
            m_PeakAlloc = g_EdictTouchLinks.m_PeakAlloc;
            v17 = linksallocated;
            v16 = v10;
            v15 = CBaseEntity::entindex(this: ent);
            DebugName = CBaseEntity::GetDebugName(this: v11);
            v12 = CBaseEntity::GetDebugName(this: ent);
            _Msg(
              a1: "remove 0x%x: %s-%s (%d-%d) [%d in play, %d max]\n",
              v3,
              v12,
              DebugName,
              v15,
              v16,
              v17,
              m_PeakAlloc);
            v5 = nextLink;
          }
          if ( v3 == g_pNextLink )
            g_pNextLink = v3->nextLink;
          --linksallocated;
          v3->nextLink = nullptr;
          v3->prevLink = nullptr;
          CUtlMemoryPool::Free(this: &g_EdictTouchLinks, memBlock: v3);
          v3 = v5;
          if ( v5 == nullptr )
            break;
          v2 = v20;
        }
      }
      v13 = (unsigned int)ent->m_fDataObjectTypes >> 1;
      g_bCleanupDatObject = saveCleanup_3;
      if ( (v13 & 1) != 0 )
      {
        if ( g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
          g_DataObjectAccessSystem.m_Accessors[1]->DestroyDataObject(
            this: g_DataObjectAccessSystem.m_Accessors[1],
            a2: ent);
        ent->m_fDataObjectTypes &= ~2u;
      }
      ent->touchStamp = 0;
    }
    else
    {
      ent->touchStamp = 0;
    }
  }
  else
  {
    ent->touchStamp = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197550
// Name: public: static void CBaseEntity::PhysicsNotifyOtherOfGroundRemoval(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::PhysicsNotifyOtherOfGroundRemoval(CBaseEntity *ent, CBaseEntity *other)
{
  groundlink_t *v2; // eax
  groundlink_t *v3; // esi
  groundlink_t *nextLink; // edx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  if ( other != nullptr && (other->m_fDataObjectTypes & 1) != 0 && g_DataObjectAccessSystem.m_Accessors[0] != nullptr )
  {
    v2 = (groundlink_t *)g_DataObjectAccessSystem.m_Accessors[0]->GetDataObject(
                           this: g_DataObjectAccessSystem.m_Accessors[0],
                           a2: other);
    v3 = v2;
    if ( v2 != nullptr )
    {
      nextLink = v2->nextLink;
      if ( nextLink != v2 )
      {
        while ( 1 )
        {
          m_Index = nextLink->entity.m_Index;
          if ( nextLink->entity.m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          if ( m_pEntity == ent )
            break;
          nextLink = nextLink->nextLink;
          if ( nextLink == v3 )
            return;
        }
        CBaseEntity::PhysicsRemoveGround(other, link: nextLink);
        if ( v3->nextLink == v3 && v3->prevLink == v3 && (other->m_fDataObjectTypes & 1) != 0 )
        {
          if ( g_DataObjectAccessSystem.m_Accessors[0] != nullptr )
            g_DataObjectAccessSystem.m_Accessors[0]->DestroyDataObject(
              this: g_DataObjectAccessSystem.m_Accessors[0],
              a2: other);
          other->m_fDataObjectTypes &= ~1u;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197610
// Name: public: static void CBaseEntity::PhysicsRemoveGroundList(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBaseEntity::PhysicsRemoveGroundList(CBaseEntity *ent)
{
  CBaseEntity *v2; // eax
  void (__thiscall *m_pfnMoveDone)(CBaseEntity *); // esi
  unsigned int v4; // eax
  void (__thiscall *v5)(CBaseEntity *); // edi
  CBaseEntity *m_pEntity; // eax
  CBaseEntity *enta; // [esp+Ch] [ebp+8h]

  if ( (ent->m_fDataObjectTypes & 1) != 0 && g_DataObjectAccessSystem.m_Accessors[0] != nullptr )
  {
    v2 = (CBaseEntity *)g_DataObjectAccessSystem.m_Accessors[0]->GetDataObject(
                          this: g_DataObjectAccessSystem.m_Accessors[0],
                          a2: ent);
    enta = v2;
    if ( v2 != nullptr )
    {
      m_pfnMoveDone = v2->m_pfnMoveDone;
      if ( m_pfnMoveDone != nullptr )
      {
        while ( (char *)m_pfnMoveDone != (char *)v2 )
        {
          v4 = *(_DWORD *)m_pfnMoveDone;
          v5 = *((void (__thiscall **)(CBaseEntity *))m_pfnMoveDone + 1);
          if ( *(_DWORD *)m_pfnMoveDone == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
          }
          CBaseEntity::PhysicsNotifyOtherOfGroundRemoval(ent, other: m_pEntity);
          --groundlinksallocated;
          CUtlMemoryPool::Free(this: &g_EntityGroundLinks, memBlock: m_pfnMoveDone);
          m_pfnMoveDone = v5;
          if ( v5 == nullptr )
            break;
          v2 = enta;
        }
      }
      if ( (ent->m_fDataObjectTypes & 1) != 0 )
      {
        if ( g_DataObjectAccessSystem.m_Accessors[0] != nullptr )
          g_DataObjectAccessSystem.m_Accessors[0]->DestroyDataObject(
            this: g_DataObjectAccessSystem.m_Accessors[0],
            a2: ent);
        ent->m_fDataObjectTypes &= ~1u;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101976D0
// Name: public: void CBaseEntity::PhysicsMarkEntitiesAsTouchingEventDriven(class CBaseEntity __near *,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsMarkEntitiesAsTouchingEventDriven(
        CBaseEntity *this,
        CBaseEntity *other,
        CGameTrace *trace)
{
  touchlink_t *v4; // eax
  touchlink_t *v5; // eax

  CBaseTrace::operator=(this: &g_TouchTrace, __that: trace);
  g_TouchTrace.fractionleftsolid = trace->fractionleftsolid;
  g_TouchTrace.surface = trace->surface;
  g_TouchTrace.hitgroup = trace->hitgroup;
  g_TouchTrace.physicsbone = trace->physicsbone;
  g_TouchTrace.worldSurfaceIndex = trace->worldSurfaceIndex;
  g_TouchTrace.m_pEnt = trace->m_pEnt;
  g_TouchTrace.hitbox = trace->hitbox;
  g_TouchTrace.m_pEnt = other;
  v4 = CBaseEntity::PhysicsMarkEntityAsTouched(this, other);
  if ( v4 != nullptr )
    v4->touchStamp = -1;
  g_TouchTrace.m_pEnt = this;
  v5 = CBaseEntity::PhysicsMarkEntityAsTouched(this: other, other: this);
  if ( v5 != nullptr )
    v5->touchStamp = -1;
  UTIL_ClearTrace(trace: &g_TouchTrace);
}

//------------------------------------------------------------------------------
// Address: 0x10197780
// Name: public: void CBaseEntity::WakeRestingObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::WakeRestingObjects(CBaseEntity *this)
{
  CBaseEntity::PhysicsRemoveGroundList(ent: this);
}

//------------------------------------------------------------------------------
// Address: 0x101981D0
// Name: public: void CBaseEntity::PhysicsCheckForEntityUntouch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsCheckForEntityUntouch(CBaseEntity *this)
{
  touchlink_t *v2; // eax
  touchlink_t *v3; // ebx
  touchlink_t *nextLink; // esi
  int touchStamp; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v8; // eax
  CBaseEntity *v9; // ecx
  bool saveCleanup; // [esp+7h] [ebp-1h]

  if ( (this->m_fDataObjectTypes & 2) != 0 && g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
  {
    v2 = (touchlink_t *)g_DataObjectAccessSystem.m_Accessors[1]->GetDataObject(
                          this: g_DataObjectAccessSystem.m_Accessors[1],
                          a2: this);
    v3 = v2;
    if ( v2 != nullptr )
    {
      nextLink = v2->nextLink;
      saveCleanup = g_bCleanupDatObject;
      g_bCleanupDatObject = false;
      if ( nextLink != v2 )
      {
        do
        {
          touchStamp = nextLink->touchStamp;
          g_pNextLink = nextLink->nextLink;
          if ( touchStamp == -1 )
          {
            m_Index = nextLink->entityTouched.m_Index;
            if ( nextLink->entityTouched.m_Index != -1
              && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
            {
              m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
              if ( m_pEntity != nullptr && (this->m_iEFlags & 1) == 0 && ((int)m_pEntity[49].__vftable & 1) == 0 )
                this->Touch(this, a2: (CBaseEntity *)m_pEntity);
            }
          }
          else if ( touchStamp != this->touchStamp )
          {
            v8 = nextLink->entityTouched.m_Index;
            if ( nextLink->entityTouched.m_Index == -1
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
            {
              v9 = nullptr;
            }
            else
            {
              v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
            }
            CBaseEntity::PhysicsNotifyOtherOfUntouch(ent: this, other: v9);
            CBaseEntity::PhysicsRemoveToucher(otherEntity: this, link: nextLink);
          }
          nextLink = g_pNextLink;
        }
        while ( g_pNextLink != v3 );
      }
      g_bCleanupDatObject = saveCleanup;
      if ( v3->nextLink == v3 && v3->prevLink == v3 && (this->m_fDataObjectTypes & 2) != 0 )
      {
        if ( g_DataObjectAccessSystem.m_Accessors[1] != nullptr )
          g_DataObjectAccessSystem.m_Accessors[1]->DestroyDataObject(
            this: g_DataObjectAccessSystem.m_Accessors[1],
            a2: this);
        this->m_fDataObjectTypes &= ~2u;
      }
    }
  }
  g_pNextLink = nullptr;
  CBaseEntity::SetCheckUntouch(this, check: false);
}

//------------------------------------------------------------------------------
// Address: 0x10198330
// Name: public: void CBaseEntity::PhysicsMarkEntitiesAsTouching(class CBaseEntity __near *,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsMarkEntitiesAsTouching(CBaseEntity *this, CBaseEntity *other, CGameTrace *trace)
{
  touchlink_t *v4; // ebx
  touchlink_t *v5; // eax

  CBaseTrace::operator=(this: &g_TouchTrace, __that: trace);
  g_TouchTrace.fractionleftsolid = trace->fractionleftsolid;
  g_TouchTrace.surface = trace->surface;
  g_TouchTrace.hitgroup = trace->hitgroup;
  g_TouchTrace.physicsbone = trace->physicsbone;
  g_TouchTrace.worldSurfaceIndex = trace->worldSurfaceIndex;
  g_TouchTrace.m_pEnt = trace->m_pEnt;
  g_TouchTrace.hitbox = trace->hitbox;
  v4 = CBaseEntity::PhysicsMarkEntityAsTouched(this, other);
  v5 = CBaseEntity::PhysicsMarkEntityAsTouched(this: other, other: this);
  if ( v4 != nullptr )
  {
    if ( v5 == nullptr )
      CBaseEntity::PhysicsNotifyOtherOfUntouch(ent: other, other: this);
  }
  else if ( v5 != nullptr )
  {
    CBaseEntity::PhysicsNotifyOtherOfUntouch(ent: this, other);
  }
  UTIL_ClearTrace(trace: &g_TouchTrace);
}

//------------------------------------------------------------------------------
// Address: 0x101983E0
// Name: public: void CBaseEntity::PhysicsImpact(class CBaseEntity __near *,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsImpact(CBaseEntity *this, CBaseEntity *other, CGameTrace *trace)
{
  if ( other != nullptr && ((this->m_fFlags.m_Value | other->m_fFlags.m_Value) & 0x8000000) == 0 )
    CBaseEntity::PhysicsMarkEntitiesAsTouching(this, other, trace);
}

//------------------------------------------------------------------------------
// Address: 0x10198410
// Name: public: void CBaseEntity::UpdateWaterState(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseEntity::UpdateWaterState(CBaseEntity *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  CNetworkVarBase<unsigned char,CBaseEntity::NetworkVar_m_nWaterLevel> *p_m_nWaterLevel; // esi
  __int16 v5; // ax
  Vector in; // [esp+0h] [ebp-18h] BYREF
  Vector point; // [esp+Ch] [ebp-Ch] BYREF

  in.x = 0.5;
  in.y = 0.5;
  in.z = 0.0;
  CCollisionProperty::NormalizedToWorldSpace(this: &this->m_Collision, &in, pResult: &point);
  p_m_nWaterLevel = &this->m_nWaterLevel;
  if ( this->m_nWaterLevel.m_Value != 0 )
  {
    this->NetworkStateChanged_m_nWaterLevel(this, a2: &this->m_nWaterLevel);
    p_m_nWaterLevel->m_Value = 0;
  }
  CBaseEntity::SetWaterType(this, nType: 0);
  v5 = ((int (__thiscall *)(IEngineTrace *, Vector *, int, int, int))enginetrace->GetPointContents_WorldOnly)(
         a1: enginetrace,
         a2: &point,
         a3: 16432,
         a4: a2,
         a5: a3);
  if ( (v5 & 0x4030) != 0 )
  {
    CBaseEntity::SetWaterType(this, nType: v5);
    if ( p_m_nWaterLevel->m_Value != 1 )
    {
      this->NetworkStateChanged_m_nWaterLevel(this, a2: &this->m_nWaterLevel);
      p_m_nWaterLevel->m_Value = 1;
    }
    if ( this->m_Collision.m_flRadius == 0.0 )
    {
      if ( p_m_nWaterLevel->m_Value != 3 )
      {
        ((void (__thiscall *)(CBaseEntity *, CNetworkVarBase<unsigned char,CBaseEntity::NetworkVar_m_nWaterLevel> *, _DWORD, _DWORD, _DWORD, _DWORD))this->NetworkStateChanged_m_nWaterLevel)(
          a1: this,
          a2: &this->m_nWaterLevel,
          a3: LODWORD(in.x),
          a4: LODWORD(in.y),
          a5: LODWORD(in.z),
          a6: LODWORD(point.x));
        p_m_nWaterLevel->m_Value = 3;
      }
    }
    else
    {
      point.z = this->WorldSpaceCenter(this)->z;
      if ( (enginetrace->GetPointContents_WorldOnly(this: enginetrace, a2: &point, a3: 16432) & 0x4030) != 0 )
      {
        if ( p_m_nWaterLevel->m_Value != 2 )
        {
          this->NetworkStateChanged_m_nWaterLevel(this, a2: &this->m_nWaterLevel);
          p_m_nWaterLevel->m_Value = 2;
        }
        point.z = this->EyePosition(this, result: &in)->z;
        if ( (enginetrace->GetPointContents_WorldOnly(this: enginetrace, a2: &point, a3: 16432) & 0x4030) != 0
          && p_m_nWaterLevel->m_Value != 3 )
        {
          this->NetworkStateChanged_m_nWaterLevel(this, a2: &this->m_nWaterLevel);
          p_m_nWaterLevel->m_Value = 3;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101985B0
// Name: private: void CBaseEntity::PhysicsAddGravityMove(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsAddGravityMove(CBaseEntity *this, Vector *move)
{
  float z; // ecx
  float v4; // xmm0_4
  CGlobalVars *v5; // ecx
  CNetworkVectorBase<Vector,CBaseEntity::NetworkVar_m_vecBaseVelocity> *p_m_vecBaseVelocity; // edi
  float m_flGravity; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  __int64 vecBaseVelocity; // [esp+8h] [ebp-18h]
  Vector vecAbsVelocity; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  z = this->m_vecAbsVelocity.z;
  *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
  v4 = vecAbsVelocity.x + this->m_vecBaseVelocity.m_Value.x;
  vecAbsVelocity.z = z;
  v5 = gpGlobals;
  p_m_vecBaseVelocity = &this->m_vecBaseVelocity;
  move->x = v4 * gpGlobals->frametime;
  move->y = (float)(this->m_vecBaseVelocity.m_Value.y + vecAbsVelocity.y) * v5->frametime;
  if ( (this->m_fFlags.m_Value & 1) != 0 )
  {
    move->z = this->m_vecBaseVelocity.m_Value.z * v5->frametime;
  }
  else
  {
    m_flGravity = this->m_flGravity;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    v8 = (float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * v5->frametime;
    v9 = vecAbsVelocity.z - v8;
    move->z = (float)((float)((float)(vecAbsVelocity.z + (float)(vecAbsVelocity.z - v8)) * 0.5)
                    + this->m_vecBaseVelocity.m_Value.z)
            * v5->frametime;
    vecBaseVelocity = *(_QWORD *)&p_m_vecBaseVelocity->m_Value.x;
    if ( this->m_vecBaseVelocity.m_Value.z != 0.0 )
    {
      this->NetworkStateChanged_m_vecBaseVelocity(this, a2: &this->m_vecBaseVelocity);
      LODWORD(p_m_vecBaseVelocity->m_Value.x) = vecBaseVelocity;
      this->m_vecBaseVelocity.m_Value.y = *((float *)&vecBaseVelocity + 1);
      this->m_vecBaseVelocity.m_Value.z = 0.0;
    }
    vecAbsVelocity.z = v9;
    CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
    CBaseEntity::PhysicsCheckVelocity(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198730
// Name: public: void CBaseEntity::PhysicsCheckWaterTransition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsCheckWaterTransition(CBaseEntity *this)
{
  int WaterType; // edi
  __int16 v3; // ax
  unsigned int m_Index; // ecx
  int m_iEFlags; // eax
  float z; // edx
  Vector vecAbsVelocity; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  WaterType = CBaseEntity::GetWaterType(this);
  CBaseEntity::UpdateWaterState(this, a2: WaterType, a3: (int)this);
  v3 = CBaseEntity::GetWaterType(this);
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    if ( (v3 & 0x4030) != 0 )
    {
      if ( WaterType == 0 )
      {
        this->Splash(this);
        CBaseEntity::EmitSound(this, soundname: "BaseEntity.EnterWater", soundtime: 0.0, duration: nullptr);
        m_iEFlags = this->m_iEFlags;
        if ( (m_iEFlags & 0x20000000) == 0 )
        {
          if ( (m_iEFlags & 0x1000) != 0 )
            CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
          z = this->m_vecAbsVelocity.z;
          *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
          vecAbsVelocity.z = z * 0.5;
          CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
        }
      }
    }
    else if ( WaterType != 0 )
    {
      CBaseEntity::EmitSound(this, soundname: "BaseEntity.ExitWater", soundtime: 0.0, duration: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198830
// Name: private: void CBaseEntity::UpdateBaseVelocity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::UpdateBaseVelocity(CBaseEntity *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  IHandleEntity *m_pEntity; // ecx
  Vector vecNewBaseVelocity; // [esp+4h] [ebp-Ch] BYREF

  if ( (this->m_fFlags.m_Value & 1) != 0 )
  {
    m_Index = this->m_hGroundEntity.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = v3->m_pEntity;
        if ( v3->m_pEntity != nullptr && ((int)m_pEntity[50].__vftable & 0x2000) != 0 )
        {
          ((void (__thiscall *)(IHandleEntity *, Vector *))m_pEntity->__vftable[48].dtr_IHandleEntity)(
            a1: m_pEntity,
            a2: &vecNewBaseVelocity);
          if ( (this->m_fFlags.m_Value & 0x1000000) != 0 )
          {
            vecNewBaseVelocity.x = this->m_vecBaseVelocity.m_Value.x + vecNewBaseVelocity.x;
            vecNewBaseVelocity.y = this->m_vecBaseVelocity.m_Value.y + vecNewBaseVelocity.y;
            vecNewBaseVelocity.z = this->m_vecBaseVelocity.m_Value.z + vecNewBaseVelocity.z;
          }
          CBaseEntity::AddFlag(this, flags: 0x1000000);
          CBaseEntity::SetBaseVelocity(this, v: &vecNewBaseVelocity);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101988F0
// Name: private: void CThinkSyncTester::Report(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThinkSyncTester::Report(CThinkSyncTester *this)
{
  CThinkSyncTester *v1; // edi
  UtlRBTreeNode_t<ThinkSync,unsigned short> *m_pMemory; // eax
  int p_m_Data; // esi
  int m_Size; // ebx
  int v5; // edi
  unsigned int v6; // eax
  IHandleEntity_vtbl *v7; // ebx
  CEntInfo *v8; // ecx
  unsigned int v9; // edx
  IHandleEntity *m_pEntity; // esi
  IHandleEntity *v11; // ecx
  const char *v12; // edx
  IHandleEntity *v13; // eax
  int ecount; // [esp+18h] [ebp-14h]
  ThinkSync *p; // [esp+1Ch] [ebp-10h]
  int nextthinktick; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  v1 = this;
  if ( this->m_Thinkers.m_NumElements != 0 )
  {
    _Msg(a1: "-----------------\nThink report frame %i\n", gpGlobals->tickcount);
    for ( i = (unsigned __int16)CUtlRBTree<ThinkSync,unsigned short,bool (__cdecl *)(ThinkSync const &,ThinkSync const &),CUtlMemory<UtlRBTreeNode_t<ThinkSync,unsigned short>,unsigned short>>::FirstInorder(this: &v1->m_Thinkers);
          i != 0xFFFF;
          i = (unsigned __int16)CUtlRBTree<ThinkSync,unsigned short,bool (__cdecl *)(ThinkSync const &,ThinkSync const &),CUtlMemory<UtlRBTreeNode_t<ThinkSync,unsigned short>,unsigned short>>::NextInorder(
                                  this: &v1->m_Thinkers,
                                  i) )
    {
      m_pMemory = v1->m_Thinkers.m_Elements.m_pMemory;
      p_m_Data = (int)&m_pMemory[(unsigned __int16)i].m_Data;
      p = (ThinkSync *)p_m_Data;
      if ( &m_pMemory[(unsigned __int16)i] != (UtlRBTreeNode_t<ThinkSync,unsigned short> *)-8 )
      {
        m_Size = m_pMemory[(unsigned __int16)i].m_Data.entities.m_Size;
        ecount = m_Size;
        if ( m_Size != 0 )
        {
          _Msg(a1: "thinktime %f, %i entities\n", *(float *)p_m_Data, m_Size);
          v5 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v6 = *(_DWORD *)(*(_DWORD *)(p_m_Data + 8) + 4 * v5);
              v7 = nullptr;
              nextthinktick = 0;
              if ( v6 == -1 )
                goto LABEL_19;
              v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v6];
              v9 = HIWORD(v6);
              if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
                goto LABEL_19;
              m_pEntity = v8->m_pEntity;
              if ( v8->m_pEntity != nullptr )
              {
                v7 = m_pEntity[27].__vftable;
                nextthinktick = (int)m_pEntity[40].__vftable;
              }
              if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == v9 && v8->m_pEntity != nullptr )
              {
                if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == v9 )
                  v11 = v8->m_pEntity;
                else
                  v11 = nullptr;
                v12 = (const char *)v11[23].__vftable;
                if ( v12 == nullptr )
                  v12 = locale;
              }
              else
              {
LABEL_19:
                v12 = "NULL";
              }
              v13 = v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6)
                  ? nullptr
                  : g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
              _Msg(a1: "  %p : %30s (last %5i/next %5i)\n", v13, v12, v7, nextthinktick);
              if ( ++v5 >= ecount )
                break;
              p_m_Data = (int)p;
            }
          }
          v1 = this;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198A70
// Name: public: void CBaseEntity::SetGroundEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SetGroundEntity(CBaseEntity *this, CBaseEntity *ground)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  CBasePlayer *v5; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  CBasePlayer *v7; // edi
  unsigned int v8; // eax
  CBaseEntity *v9; // edi

  m_Index = this->m_hGroundEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != ground )
  {
    if ( ground != nullptr && this->IsPlayer(this) && ground->m_MoveType.m_Value == 6 )
    {
      v5 = ToBasePlayer(pEntity: this);
      m_pPhysicsObject = ground->m_pPhysicsObject;
      v7 = v5;
      if ( m_pPhysicsObject != nullptr
        && v5 != nullptr
        && (((int (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetGameFlags)(a1: m_pPhysicsObject) & 4) != 0 )
      {
        v7->ForceDropOfCarriedPhysObjects(this: v7, a2: ground);
      }
    }
    v8 = this->m_hGroundEntity.m_Value.m_Index;
    if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
      v9 = nullptr;
    else
      v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
    CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hGroundEntity>::Set(
      this: &this->m_hGroundEntity,
      val: ground);
    if ( v9 != nullptr )
    {
      if ( ground == nullptr )
      {
        CBaseEntity::PhysicsNotifyOtherOfGroundRemoval(ent: this, other: v9);
LABEL_24:
        CBaseEntity::RemoveFlag(this, flagsToRemove: 1);
        return;
      }
    }
    else if ( ground != nullptr )
    {
      goto LABEL_20;
    }
    CBaseEntity::PhysicsNotifyOtherOfGroundRemoval(ent: this, other: v9);
LABEL_20:
    CBaseEntity::AddEntityToGroundList(this: ground, other: this);
    if ( ground != nullptr )
    {
      CBaseEntity::AddFlag(this, flags: 1);
      return;
    }
    goto LABEL_24;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198B90
// Name: public: CUtlMultiList<struct watcher_t,unsigned short>::~CUtlMultiList<struct watcher_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<watcher_t,unsigned short>::~CUtlMultiList<watcher_t,unsigned short>(
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *this)
{
  CUtlMultiList<watcher_t,unsigned short>::RemoveAll(this);
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
// Address: 0x10198C10
// Name: public: void CUtlMultiList<struct watcher_t,unsigned short>::RemoveAll(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<watcher_t,unsigned short>::RemoveAll(
        CUtlMultiList<watcher_t,unsigned short> *this,
        unsigned __int16 list)
{
  unsigned __int16 m_Head; // bx
  int v4; // edi
  CUtlMultiList<watcher_t,unsigned short>::ListElem_t *v5; // edx
  unsigned __int16 m_Next; // cx
  unsigned __int16 next; // [esp+8h] [ebp-4h]

  m_Head = this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      v4 = m_Head;
      v5 = &this->m_Memory.m_pMemory[v4];
      m_Next = v5->m_Next;
      next = m_Next;
      if ( m_Head < this->m_MaxElementIndex && v5->m_Previous != m_Head )
      {
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
          (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *)this,
          list,
          elem: m_Head);
        m_Next = next;
      }
      this->m_Memory.m_pMemory[v4].m_Next = this->m_FirstFree;
      --this->m_TotalElements;
      this->m_FirstFree = m_Head;
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198C90
// Name: public: void CUtlHash<struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry,bool (*)(struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry const __near &,struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry const __near &),unsigned int (*)(struct CEntityDataInstantiator<struct physicspushlist_t>::HashEntry const __near &)>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<CEntityDataInstantiator<physicspushlist_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &,CEntityDataInstantiator<physicspushlist_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &)>::Purge(
        CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *this)
{
  int v1; // edi
  int m_Size; // ebx
  CUtlVector<EntsByStringList_t,CUtlMemory<EntsByStringList_t,int> > *v3; // esi
  CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *v4; // [esp+0h] [ebp-4h]

  v4 = this;
  if ( this->m_Buckets.m_Size > 0 )
  {
    v1 = 0;
    m_Size = this->m_Buckets.m_Size;
    do
    {
      v3 = &this->m_Buckets.m_Memory.m_pMemory[v1];
      v3->m_Size = 0;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v4;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      ++v1;
      --m_Size;
      v3->m_pElements = v3->m_Memory.m_pMemory;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198D70
// Name: private: int CWatcherList::GetCallbackObjects(class IWatcherCallback __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWatcherList::GetCallbackObjects(CWatcherList *this, IWatcherCallback **pList, int listMax)
{
  unsigned __int16 m_Head; // di
  int v4; // ebx
  CUtlMultiList<watcher_t,unsigned short>::ListElem_t *m_pMemory; // edx
  int v6; // esi
  unsigned int m_Index; // eax
  unsigned __int16 next; // [esp+Ch] [ebp-Ch]
  int index; // [esp+14h] [ebp-4h]

  m_Head = g_WatcherList.m_List.m_Memory.m_pMemory[this->m_list].m_Element.m_Head;
  v4 = 0;
  index = 0;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_pMemory = g_WatcherList.m_Memory.m_pMemory;
      v6 = m_Head;
      next = g_WatcherList.m_Memory.m_pMemory[v6].m_Next;
      m_Index = g_WatcherList.m_Memory.m_pMemory[v6].m_Element.hWatcher.m_Index;
      if ( m_Index != -1 )
      {
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
        {
          pList[index] = g_WatcherList.m_Memory.m_pMemory[v6].m_Element.pWatcherCallback;
          v4 = index + 1;
          index = v4;
          if ( v4 >= listMax )
            return v4;
          goto LABEL_12;
        }
        v4 = index;
      }
      if ( m_Head < g_WatcherList.m_MaxElementIndex && g_WatcherList.m_Memory.m_pMemory[v6].m_Previous != m_Head )
      {
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::Unlink(
          this: (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *)&g_WatcherList,
          list: this->m_list,
          elem: m_Head);
        m_pMemory = g_WatcherList.m_Memory.m_pMemory;
      }
      m_pMemory[v6].m_Next = g_WatcherList.m_FirstFree;
      --g_WatcherList.m_TotalElements;
      g_WatcherList.m_FirstFree = m_Head;
LABEL_12:
      m_Head = next;
    }
    while ( next != 0xFFFF );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10198E70
// Name: public: void CWatcherList::NotifyPositionChanged(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWatcherList::NotifyPositionChanged(CWatcherList *this, CBaseEntity *pEntity)
{
  int CallbackObjects; // edi
  int i; // esi
  IWatcherCallback *v4; // ecx
  IWatcherCallback *pList[1024]; // [esp+8h] [ebp-1000h] BYREF

  CallbackObjects = CWatcherList::GetCallbackObjects(this, pList, listMax: 1024);
  for ( i = 0; i < CallbackObjects; ++i )
  {
    v4 = pList[i];
    if ( v4 != nullptr )
      ((void (__thiscall *)(IWatcherCallback *, CBaseEntity *))v4->__vftable[1].dtr_IWatcherCallback)(
        a1: v4,
        a2: pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198ED0
// Name: public: void CWatcherList::NotifyVPhysicsStateChanged(class IPhysicsObject __near *,class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWatcherList::NotifyVPhysicsStateChanged(
        CWatcherList *this,
        IPhysicsObject *pPhysics,
        CBaseEntity *pEntity,
        int bAwake)
{
  int CallbackObjects; // edi
  int i; // esi
  IWatcherCallback *v6; // ecx
  IWatcherCallback *pList[1024]; // [esp+8h] [ebp-1000h] BYREF

  CallbackObjects = CWatcherList::GetCallbackObjects(this, pList, listMax: 1024);
  for ( i = 0; i < CallbackObjects; ++i )
  {
    v6 = pList[i];
    if ( v6 != nullptr )
      ((void (__thiscall *)(IWatcherCallback *, IPhysicsObject *, CBaseEntity *, int))v6->__vftable[1].dtr_IWatcherCallback)(
        a1: v6,
        a2: pPhysics,
        a3: pEntity,
        a4: bAwake);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198F30
// Name: void ReportPositionChanged(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReportPositionChanged(CBaseEntity *pMovedEntity)
{
  CWatcherList *v1; // eax

  if ( (pMovedEntity->m_fDataObjectTypes & 0x10) != 0 && g_DataObjectAccessSystem.m_Accessors[4] != nullptr )
  {
    v1 = (CWatcherList *)g_DataObjectAccessSystem.m_Accessors[4]->GetDataObject(
                           this: g_DataObjectAccessSystem.m_Accessors[4],
                           a2: pMovedEntity);
    if ( v1 != nullptr )
      CWatcherList::NotifyPositionChanged(this: v1, pEntity: pMovedEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198F70
// Name: void ReportVPhysicsStateChanged(class IPhysicsObject __near *,class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReportVPhysicsStateChanged(IPhysicsObject *pPhysics, CBaseEntity *pEntity, int bAwake)
{
  CWatcherList *v3; // eax

  if ( (pEntity->m_fDataObjectTypes & 0x80) != 0 && g_DataObjectAccessSystem.m_Accessors[7] != nullptr )
  {
    v3 = (CWatcherList *)g_DataObjectAccessSystem.m_Accessors[7]->GetDataObject(
                           this: g_DataObjectAccessSystem.m_Accessors[7],
                           a2: pEntity);
    if ( v3 != nullptr )
      CWatcherList::NotifyVPhysicsStateChanged(this: v3, pPhysics, pEntity, bAwake);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198FB0
// Name: protected: void CBaseEntity::ResolveFlyCollisionBounce(class CGameTrace __near &,class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ResolveFlyCollisionBounce(
        CBaseEntity *this,
        CGameTrace *trace,
        Vector *vecVelocity,
        float flMinTotalElasticity)
{
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float x; // xmm2_4
  float y; // xmm5_4
  float v11; // xmm1_4
  float v12; // xmm4_4
  float z; // xmm6_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float m_flGravity; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  CBaseEntity *v30; // ecx
  float v31; // eax
  CGlobalVars *v32; // eax
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm5_4
  float v37; // xmm4_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float vecDelta; // [esp+Ch] [ebp-28h]
  float vecDelta_4; // [esp+10h] [ebp-24h]
  float vecDelta_8; // [esp+14h] [ebp-20h]
  Vector vecBaseDir; // [esp+18h] [ebp-1Ch] BYREF
  Vector vecAbsVelocity; // [esp+24h] [ebp-10h] BYREF
  float flSurfaceElasticity; // [esp+30h] [ebp-4h] BYREF
  int savedregs; // [esp+34h] [ebp+0h] BYREF
  float flSpeedSqr; // [esp+3Ch] [ebp+8h]
  float flSpeedSqra; // [esp+3Ch] [ebp+8h]
  CBaseEntity *pEntity; // [esp+44h] [ebp+10h]

  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, float *))physprops->GetPhysicsProperties)(
    a1: trace->surface.surfaceProps,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: &flSurfaceElasticity);
  v6 = flMinTotalElasticity;
  v7 = 0.89999998;
  v8 = this->m_flElasticity.m_Value * flSurfaceElasticity;
  if ( flMinTotalElasticity > 0.89999998 )
    v6 = 0.89999998;
  if ( v6 <= v8 )
  {
    if ( v8 <= 0.89999998 )
      v7 = this->m_flElasticity.m_Value * flSurfaceElasticity;
  }
  else
  {
    v7 = v6;
  }
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  x = trace->plane.normal.x;
  y = trace->plane.normal.y;
  v11 = this->m_vecAbsVelocity.x;
  v12 = this->m_vecAbsVelocity.y;
  z = this->m_vecAbsVelocity.z;
  flSpeedSqr = trace->plane.normal.z;
  v14 = (float)((float)((float)(x * v11) + (float)(y * v12)) + (float)(flSpeedSqr * z)) * 2.0;
  v15 = v11 - (float)(x * v14);
  if ( v15 > -0.1 && v15 < 0.1 )
    v15 = 0.0;
  v16 = v12 - (float)(y * v14);
  if ( v16 > -0.1 && v16 < 0.1 )
    v16 = 0.0;
  v17 = z - (float)(flSpeedSqr * v14);
  if ( v17 > -0.1 && v17 < 0.1 )
    v17 = 0.0;
  v18 = v15 * v7;
  v19 = v16 * v7;
  vecVelocity->x = this->m_vecBaseVelocity.m_Value.x + (float)(v15 * v7);
  v20 = vecVelocity->x;
  v21 = v7 * v17;
  vecVelocity->y = this->m_vecBaseVelocity.m_Value.y + v19;
  v22 = this->m_vecBaseVelocity.m_Value.z + v21;
  vecAbsVelocity.z = v21;
  v23 = (float)((float)(v20 * v20) + (float)(vecVelocity->y * vecVelocity->y)) + (float)(v22 * v22);
  vecVelocity->z = v22;
  v24 = trace->plane.normal.z;
  vecAbsVelocity.x = v18;
  vecAbsVelocity.y = v19;
  flSpeedSqra = v23;
  if ( v24 > 0.69999999 )
  {
    m_flGravity = this->m_flGravity;
    pEntity = trace->m_pEnt;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    if ( (float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * gpGlobals->frametime) > v22 )
    {
      vecVelocity->x = this->m_vecBaseVelocity.m_Value.x + v18;
      v26 = this->m_vecBaseVelocity.m_Value.y + v19;
      vecVelocity->y = v26;
      v27 = this->m_vecBaseVelocity.m_Value.z;
      v28 = v26;
      v29 = vecVelocity->x;
      vecVelocity->z = v27;
      vecAbsVelocity.z = 0.0;
      flSpeedSqra = (float)((float)(v29 * v29) + (float)(v28 * v28)) + (float)(v27 * v27);
    }
    CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
    if ( flSpeedSqra >= 900.0 )
    {
      v31 = this->m_vecBaseVelocity.m_Value.z;
      vecDelta = this->m_vecBaseVelocity.m_Value.x - vecAbsVelocity.x;
      vecDelta_4 = this->m_vecBaseVelocity.m_Value.y - vecAbsVelocity.y;
      vecDelta_8 = v31 - vecAbsVelocity.z;
      *(_QWORD *)&vecBaseDir.x = *(_QWORD *)&this->m_vecBaseVelocity.m_Value.x;
      vecBaseDir.z = v31;
      VectorNormalize(vec: &vecBaseDir);
      v32 = gpGlobals;
      v33 = (float)((float)(vecBaseDir.y * vecDelta_4) + (float)(vecDelta * vecBaseDir.x))
          + (float)(vecBaseDir.z * vecDelta_8);
      v34 = (float)(1.0 - trace->fraction) * gpGlobals->frametime;
      v35 = vecAbsVelocity.y * v34;
      v36 = v34 * vecAbsVelocity.x;
      vecVelocity->z = v34 * vecAbsVelocity.z;
      vecVelocity->x = v36;
      vecVelocity->y = v35;
      v37 = (float)(1.0 - trace->fraction) * v32->frametime;
      v38 = (float)((float)(this->m_vecBaseVelocity.m_Value.z * v33) * v37) + vecVelocity->z;
      v39 = (float)((float)(this->m_vecBaseVelocity.m_Value.y * v33) * v37) + v35;
      vecVelocity->x = (float)((float)(this->m_vecBaseVelocity.m_Value.x * v33) * v37) + v36;
      vecVelocity->y = v39;
      vecVelocity->z = v38;
      CBaseEntity::PhysicsPushEntity(this, push: vecVelocity, pTrace: trace);
      return;
    }
    if ( CBaseEntity::IsStandable(this: pEntity) )
      CBaseEntity::SetGroundEntity(this, ground: pEntity);
    v30 = this;
    goto LABEL_29;
  }
  v30 = this;
  if ( v23 < 900.0 )
  {
LABEL_29:
    CBaseEntity::SetAbsVelocity(this: v30, vecAbsVelocity: &vec3_origin);
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
    return;
  }
  CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x101993E0
// Name: protected: void CBaseEntity::ResolveFlyCollisionSlide(class CGameTrace __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ResolveFlyCollisionSlide(CBaseEntity *this, CGameTrace *trace, Vector *vecVelocity)
{
  float y; // xmm4_4
  float x; // xmm1_4
  float v7; // xmm3_4
  float z; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float m_flGravity; // xmm2_4
  CBaseEntity *m_pEnt; // ebx
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  Vector vecAbsVelocity; // [esp+8h] [ebp-10h] BYREF
  float flSurfaceFriction; // [esp+14h] [ebp-4h] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  float flSpeedSqr; // [esp+20h] [ebp+8h]

  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, float *, _DWORD))physprops->GetPhysicsProperties)(
    a1: trace->surface.surfaceProps,
    a2: 0,
    a3: 0,
    a4: &flSurfaceFriction,
    a5: 0);
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  y = trace->plane.normal.y;
  x = this->m_vecAbsVelocity.x;
  v7 = this->m_vecAbsVelocity.y;
  z = trace->plane.normal.z;
  v9 = this->m_vecAbsVelocity.z;
  v10 = (float)((float)(trace->plane.normal.x * x) + (float)(y * v7)) + (float)(z * v9);
  v11 = x - (float)(trace->plane.normal.x * v10);
  vecAbsVelocity.x = v11;
  if ( v11 > -0.1 && v11 < 0.1 )
  {
    v11 = 0.0;
    vecAbsVelocity.x = 0.0;
  }
  v12 = v7 - (float)(y * v10);
  vecAbsVelocity.y = v12;
  if ( v12 > -0.1 && v12 < 0.1 )
  {
    v12 = 0.0;
    vecAbsVelocity.y = 0.0;
  }
  v13 = v9 - (float)(z * v10);
  vecAbsVelocity.z = v13;
  if ( v13 > -0.1 && v13 < 0.1 )
  {
    v13 = 0.0;
    vecAbsVelocity.z = 0.0;
  }
  if ( trace->plane.normal.z > 0.7 )
  {
    vecVelocity->x = v11 + this->m_vecBaseVelocity.m_Value.x;
    v14 = vecVelocity->x;
    vecVelocity->y = this->m_vecBaseVelocity.m_Value.y + v12;
    v15 = this->m_vecBaseVelocity.m_Value.z + v13;
    v16 = (float)((float)(v14 * v14) + (float)(vecVelocity->y * vecVelocity->y)) + (float)(v15 * v15);
    vecVelocity->z = v15;
    flSpeedSqr = v16;
    m_flGravity = this->m_flGravity;
    m_pEnt = trace->m_pEnt;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    if ( (float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * gpGlobals->frametime) > v15 )
    {
      vecVelocity->x = v11 + this->m_vecBaseVelocity.m_Value.x;
      v19 = this->m_vecBaseVelocity.m_Value.y + v12;
      vecVelocity->y = v19;
      v20 = this->m_vecBaseVelocity.m_Value.z;
      v21 = v19;
      v22 = vecVelocity->x;
      vecVelocity->z = v20;
      vecAbsVelocity.z = 0.0;
      flSpeedSqr = (float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(v20 * v20);
    }
    CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
    if ( flSpeedSqr >= 900.0 )
    {
      v23 = this->m_vecBaseVelocity.m_Value.y + vecAbsVelocity.y;
      v24 = this->m_vecBaseVelocity.m_Value.z + vecAbsVelocity.z;
      v25 = 1.0 - trace->fraction;
      vecAbsVelocity.x = vecAbsVelocity.x + this->m_vecBaseVelocity.m_Value.x;
      vecAbsVelocity.y = v23;
      vecAbsVelocity.z = v24;
      v26 = (float)(v25 * gpGlobals->frametime) * flSurfaceFriction;
      vecAbsVelocity.x = v26 * vecAbsVelocity.x;
      vecAbsVelocity.y = v26 * v23;
      vecAbsVelocity.z = v26 * v24;
      CBaseEntity::PhysicsPushEntity(this, push: &vecAbsVelocity, pTrace: trace);
    }
    else
    {
      if ( CBaseEntity::IsStandable(this: m_pEnt) )
        CBaseEntity::SetGroundEntity(this, ground: m_pEnt);
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
      CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
    }
  }
  else
  {
    CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101996F0
// Name: protected: virtual void CBaseEntity::ResolveFlyCollisionCustom(class CGameTrace __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::ResolveFlyCollisionCustom(CBaseEntity *this, CGameTrace *trace, Vector *vecVelocity)
{
  float v4; // xmm0_4
  float m_flGravity; // xmm1_4
  CBaseEntity *m_pEnt; // edi
  Vector vecAbsVelocity; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( trace->plane.normal.z > 0.7 )
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    vecVelocity->x = this->m_vecBaseVelocity.m_Value.x + this->m_vecAbsVelocity.x;
    vecVelocity->y = this->m_vecAbsVelocity.y + this->m_vecBaseVelocity.m_Value.y;
    v4 = this->m_vecAbsVelocity.z + this->m_vecBaseVelocity.m_Value.z;
    vecVelocity->z = v4;
    m_flGravity = this->m_flGravity;
    m_pEnt = trace->m_pEnt;
    if ( m_flGravity == 0.0 )
      m_flGravity = 1.0;
    if ( (float)((float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flGravity) * gpGlobals->frametime) > v4 )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
      *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
      vecAbsVelocity.z = 0.0;
      CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
    }
    if ( CBaseEntity::IsStandable(this: m_pEnt) )
      CBaseEntity::SetGroundEntity(this, ground: m_pEnt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199800
// Name: protected: void CBaseEntity::PerformFlyCollisionResolution(class CGameTrace __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PerformFlyCollisionResolution(CBaseEntity *this, CGameTrace *trace, Vector *move)
{
  switch ( this->m_MoveCollide.m_Value )
  {
    case 0u:
    case 3u:
      CBaseEntity::ResolveFlyCollisionSlide(this, trace, vecVelocity: move);
      break;
    case 1u:
      CBaseEntity::ResolveFlyCollisionBounce(this, trace, vecVelocity: move, flMinTotalElasticity: 0.0);
      break;
    case 2u:
      this->ResolveFlyCollisionCustom(this, a2: trace, a3: move);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199860
// Name: public: ThinkSync::ThinkSync(struct ThinkSync const __near &)
// Source: json
//------------------------------------------------------------------------------
ThinkSync *__thiscall ThinkSync::ThinkSync(ThinkSync *this, const ThinkSync *src)
{
  const ThinkSync *v2; // eax
  ThinkSync *v3; // edx
  int v4; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_entities; // esi
  vgui::TreeNode **m_pMemory; // edi
  int v7; // ecx
  int m_nAllocationCount; // eax
  vgui::TreeNode **v9; // ecx
  int v10; // eax
  vgui::TreeNode **v11; // eax
  int c; // [esp+8h] [ebp-Ch]
  vgui::TreeNode **v14; // [esp+Ch] [ebp-8h]

  v2 = src;
  v3 = this;
  v4 = 0;
  this->entities.m_Memory.m_pMemory = nullptr;
  this->entities.m_Memory.m_nAllocationCount = 0;
  this->entities.m_Memory.m_nGrowSize = 0;
  this->entities.m_Size = 0;
  this->entities.m_pElements = nullptr;
  this->thinktime = src->thinktime;
  p_entities = (CUtlMemory<vgui::TreeNode *,int> *)&this->entities;
  this->thinktick = src->thinktick;
  c = src->entities.m_Size;
  if ( c > 0 )
  {
    while ( 1 )
    {
      m_pMemory = p_entities[1].m_pMemory;
      v7 = (int)&v2->entities.m_Memory.m_pMemory[v4];
      m_nAllocationCount = p_entities->m_nAllocationCount;
      v14 = (vgui::TreeNode **)v7;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(this: p_entities, num: (int)m_pMemory - m_nAllocationCount + 1);
        v3 = this;
      }
      ++p_entities[1].m_pMemory;
      v9 = p_entities->m_pMemory;
      v10 = (char *)p_entities[1].m_pMemory - (char *)m_pMemory - 1;
      p_entities[1].m_nAllocationCount = (int)p_entities->m_pMemory;
      if ( v10 > 0 )
      {
        _V_memmove(dest: &v9[(_DWORD)m_pMemory + 1], src: &v9[(_DWORD)m_pMemory], count: 4 * v10);
        v3 = this;
      }
      v11 = &p_entities->m_pMemory[(_DWORD)m_pMemory];
      if ( v11 != nullptr )
        *v11 = *v14;
      if ( ++v4 >= c )
        break;
      v2 = src;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10199A50
// Name: public: void CWatcherList::AddToList(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWatcherList::AddToList(CWatcherList *this, CBaseEntity *pWatcher)
{
  IWatcherCallback *v3; // ebx
  unsigned __int16 m_list; // di
  unsigned __int16 v5; // ax
  int v6; // esi
  CUtlMultiList<watcher_t,unsigned short>::ListElem_t *v7; // eax
  unsigned int watcher; // [esp+8h] [ebp-8h]

  if ( (unsigned __int16)CWatcherList::Find(this, pEntity: pWatcher) == 0xFFFF )
  {
    if ( pWatcher != nullptr )
      watcher = pWatcher->GetRefEHandle(this: pWatcher)->m_Index;
    else
      watcher = -1;
    v3 = (IWatcherCallback *)__RTDynamicCast(
                               inptr: pWatcher,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &IWatcherCallback `RTTI Type Descriptor',
                               isReference: 0);
    if ( v3 != nullptr )
    {
      m_list = this->m_list;
      v5 = CUtlMultiList<watcher_t,unsigned short>::Alloc(this: &g_WatcherList);
      v6 = v5;
      if ( v5 != 0xFFFF )
      {
        CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::LinkBefore(
          this: (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short> *)&g_WatcherList,
          list: m_list,
          before: 0xFFFFu,
          elem: v5);
        v7 = &g_WatcherList.m_Memory.m_pMemory[v6];
        if ( v7 != nullptr )
        {
          v7->m_Element.hWatcher.m_Index = watcher;
          v7->m_Element.pWatcherCallback = v3;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199BD0
// Name: public: void CWatcherList::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWatcherList::Init(CWatcherList *this)
{
  unsigned __int16 v2; // si
  unsigned __int16 v3; // cx
  int v4; // eax

  v2 = CUtlLinkedList<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<watcher_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &g_WatcherList.m_List,
         multilist: false);
  if ( v2 == 0xFFFF )
  {
    v3 = -1;
  }
  else
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&g_WatcherList.m_List,
      before: 0xFFFFu,
      elem: v2);
    v3 = v2;
  }
  v4 = v3;
  g_WatcherList.m_List.m_Memory.m_pMemory[v4].m_Element.m_Tail = -1;
  g_WatcherList.m_List.m_Memory.m_pMemory[v4].m_Element.m_Head = -1;
  g_WatcherList.m_List.m_Memory.m_pMemory[v4].m_Element.m_Count = 0;
  this->m_list = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10199C40
// Name: void WatchPositionChanges(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WatchPositionChanges(CBaseEntity *pWatcher, CBaseEntity *pMovingEntity)
{
  CWatcherList *v2; // eax
  CWatcherList *v3; // edi
  CWatcherList *v4; // eax

  if ( (pMovingEntity->m_fDataObjectTypes & 0x10) == 0
    || (g_DataObjectAccessSystem.m_Accessors[4] != nullptr
      ? (v2 = (CWatcherList *)g_DataObjectAccessSystem.m_Accessors[4]->GetDataObject(
                                this: g_DataObjectAccessSystem.m_Accessors[4],
                                a2: pMovingEntity))
      : (v2 = nullptr),
        v3 = v2,
        v2 == nullptr) )
  {
    pMovingEntity->m_fDataObjectTypes |= 0x10u;
    if ( g_DataObjectAccessSystem.m_Accessors[4] != nullptr )
      v4 = (CWatcherList *)g_DataObjectAccessSystem.m_Accessors[4]->CreateDataObject(
                             this: g_DataObjectAccessSystem.m_Accessors[4],
                             a2: pMovingEntity);
    else
      v4 = nullptr;
    v3 = v4;
    CWatcherList::Init(this: v4);
  }
  CWatcherList::AddToList(this: v3, pWatcher);
}

//------------------------------------------------------------------------------
// Address: 0x10199DF0
// Name: public: void CThinkSyncTester::EntityThinking(int,class CBaseEntity __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThinkSyncTester::EntityThinking(
        CThinkSyncTester *this,
        const char *framecount,
        CBaseEntity *ent,
        float thinktime,
        int thinktick)
{
  int m_nValue; // eax
  unsigned __int16 v7; // ax
  ThinkSync *p_m_Data; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int v12; // eax
  CHandle<CBaseEntity> *v13; // eax
  ThinkSync search; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int h; // [esp+38h] [ebp+10h]

  if ( (const char *)this->m_nLastFrameCount != framecount )
  {
    if ( this->m_bShouldCheck )
    {
      CThinkSyncTester::Report(this);
      CUtlRBTree<ThinkSync,unsigned short,bool (__cdecl *)(ThinkSync const &,ThinkSync const &),CUtlMemory<UtlRBTreeNode_t<ThinkSync,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Thinkers);
      this->m_nLastFrameCount = (int)framecount;
    }
    if ( sv_thinktimecheck.m_pParent != nullptr )
      m_nValue = sv_thinktimecheck.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    this->m_bShouldCheck = m_nValue != 0;
  }
  if ( this->m_bShouldCheck )
  {
    memset(&search.entities, 0, sizeof(search.entities));
    search.thinktime = thinktime;
    v7 = CUtlRBTree<ThinkSync,unsigned short,bool (__cdecl *)(ThinkSync const &,ThinkSync const &),CUtlMemory<UtlRBTreeNode_t<ThinkSync,unsigned short>,unsigned short>>::Find(
           this: &this->m_Thinkers,
           &search);
    if ( v7 == 0xFFFF )
      v7 = CUtlRBTree<ThinkSync,unsigned short,bool (__cdecl *)(ThinkSync const &,ThinkSync const &),CUtlMemory<UtlRBTreeNode_t<ThinkSync,unsigned short>,unsigned short>>::Insert(
             this: &this->m_Thinkers,
             a2: framecount,
             insert: &search);
    p_m_Data = &this->m_Thinkers.m_Elements.m_pMemory[v7].m_Data;
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.entities);
    p_m_Data->thinktime = thinktime;
    p_m_Data->thinktick = thinktick;
    if ( ent != nullptr )
      h = ent->GetRefEHandle(this: ent)->m_Index;
    else
      h = -1;
    m_Size = p_m_Data->entities.m_Size;
    m_nAllocationCount = p_m_Data->entities.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&p_m_Data->entities,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_Data->entities.m_Size;
    m_pMemory = p_m_Data->entities.m_Memory.m_pMemory;
    v12 = p_m_Data->entities.m_Size - m_Size - 1;
    p_m_Data->entities.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = &p_m_Data->entities.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      v13->m_Index = h;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199F20
// Name: public: bool CBaseEntity::PhysicsRunSpecificThink(int,void (CBaseEntity::*)(void))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::PhysicsRunSpecificThink(
        CBaseEntity *this,
        int nContextIndex,
        void (__thiscall *thinkFunc)(CBaseEntity *this))
{
  int NextThinkTick; // eax
  const char *tickcount; // ecx
  float thinktime; // xmm0_4

  NextThinkTick = CBaseEntity::GetNextThinkTick(this, nContextIndex);
  if ( NextThinkTick <= 0 )
    return true;
  tickcount = (const char *)gpGlobals->tickcount;
  if ( NextThinkTick > (int)tickcount )
    return true;
  thinktime = (float)NextThinkTick * gpGlobals->interval_per_tick;
  if ( gpGlobals->curtime > thinktime )
    thinktime = gpGlobals->curtime;
  CThinkSyncTester::EntityThinking(
    this: &g_ThinkChecker,
    framecount: tickcount,
    ent: this,
    thinktime,
    thinktick: this->m_nNextThinkTick.m_Value);
  CBaseEntity::SetNextThink(this, nContextIndex, thinkTime: -1.0);
  CBaseEntity::PhysicsDispatchThink(this, thinkFunc);
  CBaseEntity::SetLastThink(this, nContextIndex, thinkTime: gpGlobals->curtime);
  return (this->m_iEFlags & 1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10199FD0
// Name: public: bool CBaseEntity::PhysicsRunThink(enum CBaseEntity::thinkmethods_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseEntity::PhysicsRunThink(CBaseEntity *this, CBaseEntity::thinkmethods_t thinkMethod)
{
  bool result; // al
  int v4; // edi
  int i; // ebx

  result = true;
  if ( (this->m_iEFlags & 0x400000) == 0
    && (thinkMethod == THINK_FIRE_ALL_BUT_BASE
     || (result = CBaseEntity::PhysicsRunSpecificThink(
                    this,
                    nContextIndex: -1,
                    thinkFunc:  __thiscall CBaseEntity::`vcall'{200,{flat}})))
    && thinkMethod != THINK_FIRE_BASE_ONLY )
  {
    v4 = 0;
    if ( this->m_aThinkFunctions.m_Size > 0 )
    {
      for ( i = 0; ; ++i )
      {
        result = CBaseEntity::PhysicsRunSpecificThink(
                   this,
                   nContextIndex: v4,
                   thinkFunc: this->m_aThinkFunctions.m_Memory.m_pMemory[i].m_pfnThink);
        if ( !result )
          break;
        if ( ++v4 >= this->m_aThinkFunctions.m_Size )
          return result;
      }
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019A050
// Name: public: CEntityDataInstantiator<struct touchlink_t>::CEntityDataInstantiator<struct touchlink_t>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<touchlink_t> *__thiscall CEntityDataInstantiator<touchlink_t>::CEntityDataInstantiator<touchlink_t>(
        CEntityDataInstantiator<touchlink_t> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<touchlink_t>_vtbl *)&CEntityDataInstantiator<touchlink_t>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<touchlink_t>::HashEntry *, const CEntityDataInstantiator<touchlink_t>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<touchlink_t>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019A0C0
// Name: public: virtual void __near * CEntityDataInstantiator<struct StepSimulationData>::GetDataObject(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<StepSimulationData>::GetDataObject(
        CEntityDataInstantiator<vphysicsupdateai_t> *this,
        const CBaseEntity *instance)
{
  const CBaseEntity *v2; // edx
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // esi
  unsigned int v4; // eax
  CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry entry; // [esp+4h] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+Ch] [ebp-4h] BYREF

  v2 = instance;
  entry.data = nullptr;
  instance = nullptr;
  p_m_HashTable = &this->m_HashTable;
  entry.key = v2;
  if ( !CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
          this: &this->m_HashTable,
          src: &entry,
          &pBucket,
          pIndex: (int *)&instance) )
    return nullptr;
  v4 = (unsigned int)instance | (pBucket << 16);
  if ( v4 == -1 )
    return nullptr;
  else
    return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)instance].data;
}

//------------------------------------------------------------------------------
// Address: 0x1019A130
// Name: public: virtual void __near * CEntityDataInstantiator<struct touchlink_t>::CreateDataObject(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<touchlink_t>::CreateDataObject(
        CEntityDataInstantiator<touchlink_t> *this,
        const CBaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  vphysicsupdateai_t *v6; // edx
  int v7; // ecx
  int v8; // eax
  CEntityDataInstantiator<touchlink_t>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( !CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
          this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
          src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
          &pBucket,
          pIndex: (int *)&instance)
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
             this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const AI_NamespaceAddInfo_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)operator new(nSize: 0x14u);
    if ( v5 != nullptr )
    {
      v5->startUpdateTime = NAN;
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    v7 = HIWORD(v3);
    v8 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v7].m_Memory.m_pMemory[v8].data = v6;
    _V_memset(dest: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v7].m_Memory.m_pMemory[v8].data, fill: 0, count: 20);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x1019A230
// Name: public: CEntityDataInstantiator<struct groundlink_t>::CEntityDataInstantiator<struct groundlink_t>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<groundlink_t> *__thiscall CEntityDataInstantiator<groundlink_t>::CEntityDataInstantiator<groundlink_t>(
        CEntityDataInstantiator<groundlink_t> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<groundlink_t>_vtbl *)&CEntityDataInstantiator<groundlink_t>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<groundlink_t>::HashEntry *, const CEntityDataInstantiator<groundlink_t>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<groundlink_t>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019A2A0
// Name: protected: bool CUtlHash<struct CEntityDataInstantiator<struct vphysicsupdateai_t>::HashEntry,bool (*)(struct CEntityDataInstantiator<struct vphysicsupdateai_t>::HashEntry const __near &,struct CEntityDataInstantiator<struct vphysicsupdateai_t>::HashEntry const __near &),unsigned int (*)(struct CEntityDataInstantiator<struct vphysicsupdateai_t>::HashEntry const __near &)>::DoFind(struct CEntityDataInstantiator<struct vphysicsupdateai_t>::HashEntry const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
        CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *this,
        const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int> > *v7; // ebx
  int m_Size; // eax
  int v9; // esi
  int keyDataCount; // [esp+18h] [ebp+Ch]

  v5 = this->m_KeyFunc(a1: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = &this->m_Buckets.m_Memory.m_pMemory[v6];
  m_Size = v7->m_Size;
  v9 = 0;
  keyDataCount = m_Size;
  if ( m_Size > 0 )
  {
    do
    {
      if ( this->m_CompareFunc(a1: &v7->m_Memory.m_pMemory[v9], a2: src) )
        break;
      ++v9;
    }
    while ( v9 < keyDataCount );
    m_Size = keyDataCount;
  }
  if ( v9 == m_Size )
    return 0;
  *pIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019A320
// Name: public: virtual void __near * CEntityDataInstantiator<struct groundlink_t>::CreateDataObject(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<groundlink_t>::CreateDataObject(
        CEntityDataInstantiator<groundlink_t> *this,
        const CBaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  vphysicsupdateai_t *v6; // edx
  int v7; // ecx
  int v8; // eax
  CEntityDataInstantiator<groundlink_t>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
             this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const AI_NamespaceAddInfo_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)operator new(nSize: 0xCu);
    if ( v5 != nullptr )
    {
      v5->startUpdateTime = NAN;
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    v7 = HIWORD(v3);
    v8 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v7].m_Memory.m_pMemory[v8].data = v6;
    _V_memset(dest: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v7].m_Memory.m_pMemory[v8].data, fill: 0, count: 12);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x1019A420
// Name: public: CEntityDataInstantiator<struct StepSimulationData>::CEntityDataInstantiator<struct StepSimulationData>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<StepSimulationData> *__thiscall CEntityDataInstantiator<StepSimulationData>::CEntityDataInstantiator<StepSimulationData>(
        CEntityDataInstantiator<StepSimulationData> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<StepSimulationData>_vtbl *)&CEntityDataInstantiator<StepSimulationData>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<StepSimulationData>::HashEntry *, const CEntityDataInstantiator<StepSimulationData>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<StepSimulationData>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019A490
// Name: public: virtual void __near * CEntityDataInstantiator<struct StepSimulationData>::CreateDataObject(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<StepSimulationData>::CreateDataObject(
        CEntityDataInstantiator<StepSimulationData> *this,
        const CBaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  int v6; // edx
  int v7; // ecx
  CEntityDataInstantiator<StepSimulationData>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
             this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const AI_NamespaceAddInfo_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)operator new(nSize: 0xB8u);
    v6 = HIWORD(v3);
    v7 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data = v5;
    _V_memset(dest: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data, fill: 0, count: 184);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x1019A580
// Name: public: CEntityDataInstantiator<struct ModelScale>::CEntityDataInstantiator<struct ModelScale>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<ModelScale> *__thiscall CEntityDataInstantiator<ModelScale>::CEntityDataInstantiator<ModelScale>(
        CEntityDataInstantiator<ModelScale> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<ModelScale>_vtbl *)&CEntityDataInstantiator<ModelScale>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<ModelScale>::HashEntry *, const CEntityDataInstantiator<ModelScale>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<ModelScale>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019A5F0
// Name: public: virtual void CEntityDataInstantiator<struct physicspushlist_t>::DestroyDataObject(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityDataInstantiator<physicspushlist_t>::DestroyDataObject(
        CEntityDataInstantiator<vphysicsupdateai_t> *this,
        const CBaseEntity *instance)
{
  const CBaseEntity *v2; // edx
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // ebx
  unsigned int v4; // esi
  unsigned int v5; // edi
  CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *m_pMemory; // edx
  int v7; // esi
  CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int> > *v8; // ecx
  int m_Size; // edx
  CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *v10; // eax
  CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry entry; // [esp+4h] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+Ch] [ebp-4h] BYREF

  v2 = instance;
  entry.data = nullptr;
  instance = nullptr;
  p_m_HashTable = &this->m_HashTable;
  entry.key = v2;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: &this->m_HashTable,
         src: &entry,
         &pBucket,
         pIndex: (int *)&instance) != 0 )
  {
    v4 = (unsigned int)instance | (pBucket << 16);
    if ( v4 != -1 )
    {
      v5 = HIWORD(v4);
      m_pMemory = p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory;
      v7 = (unsigned __int16)instance;
      free(pMem: m_pMemory[(unsigned __int16)instance].data);
      v8 = &p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v5];
      if ( v7 < v8->m_Size )
      {
        m_Size = v8->m_Size;
        if ( m_Size > 0 )
        {
          if ( v7 != m_Size - 1 )
          {
            v10 = v8->m_Memory.m_pMemory;
            v10[v7].key = v8->m_Memory.m_pMemory[m_Size - 1].key;
            v10[v7].data = v10[m_Size - 1].data;
          }
          --v8->m_Size;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A690
// Name: public: virtual void __near * CEntityDataInstantiator<struct ModelScale>::CreateDataObject(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<ModelScale>::CreateDataObject(
        CEntityDataInstantiator<ModelScale> *this,
        const CBaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  int v6; // edx
  int v7; // ecx
  CEntityDataInstantiator<ModelScale>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
             this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const AI_NamespaceAddInfo_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)operator new(nSize: 0x10u);
    v6 = HIWORD(v3);
    v7 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data = v5;
    _V_memset(dest: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data, fill: 0, count: 16);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x1019A780
// Name: public: CEntityDataInstantiator<class CWatcherList>::CEntityDataInstantiator<class CWatcherList>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<CWatcherList> *__thiscall CEntityDataInstantiator<CWatcherList>::CEntityDataInstantiator<CWatcherList>(
        CEntityDataInstantiator<CWatcherList> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<CWatcherList>_vtbl *)&CEntityDataInstantiator<CWatcherList>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<CWatcherList>::HashEntry *, const CEntityDataInstantiator<CWatcherList>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<CWatcherList>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019A7F0
// Name: public: virtual void __near * CEntityDataInstantiator<class CWatcherList>::CreateDataObject(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<CWatcherList>::CreateDataObject(
        CEntityDataInstantiator<CWatcherList> *this,
        const CBaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  int v6; // edx
  int v7; // ecx
  CEntityDataInstantiator<CWatcherList>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
             this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const AI_NamespaceAddInfo_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)operator new(nSize: 2u);
    v6 = HIWORD(v3);
    v7 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data = v5;
    _V_memset(dest: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data, fill: 0, count: 2);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x1019A8E0
// Name: public: virtual void CEntityDataInstantiator<class CWatcherList>::DestroyDataObject(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityDataInstantiator<CWatcherList>::DestroyDataObject(
        CEntityDataInstantiator<CWatcherList> *this,
        const CBaseEntity *instance)
{
  const CBaseEntity *v2; // edx
  CUtlHash<CEntityDataInstantiator<CWatcherList>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<CWatcherList>::HashEntry const &,CEntityDataInstantiator<CWatcherList>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<CWatcherList>::HashEntry const &)> *p_m_HashTable; // ebx
  unsigned int v4; // esi
  unsigned int v5; // edi
  CEntityDataInstantiator<CWatcherList>::HashEntry *m_pMemory; // edx
  int v7; // esi
  unsigned __int16 *p_m_list; // ebx
  CUtlVector<CEntityDataInstantiator<CWatcherList>::HashEntry,CUtlMemory<CEntityDataInstantiator<CWatcherList>::HashEntry,int> > *v9; // ecx
  int m_Size; // edx
  CEntityDataInstantiator<CWatcherList>::HashEntry *v11; // eax
  unsigned __int16 v12; // [esp-Ch] [ebp-20h]
  CEntityDataInstantiator<CWatcherList>::HashEntry entry; // [esp+4h] [ebp-10h] BYREF
  CUtlHash<CEntityDataInstantiator<CWatcherList>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<CWatcherList>::HashEntry const &,CEntityDataInstantiator<CWatcherList>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<CWatcherList>::HashEntry const &)> *v14; // [esp+Ch] [ebp-8h]
  unsigned int pBucket; // [esp+10h] [ebp-4h] BYREF

  v2 = instance;
  entry.data = nullptr;
  instance = nullptr;
  p_m_HashTable = &this->m_HashTable;
  entry.key = v2;
  v14 = &this->m_HashTable;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) != 0 )
  {
    v4 = (unsigned int)instance | (pBucket << 16);
    if ( v4 != -1 )
    {
      v5 = HIWORD(v4);
      m_pMemory = p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory;
      v7 = (unsigned __int16)instance;
      p_m_list = &m_pMemory[(unsigned __int16)instance].data->m_list;
      if ( p_m_list != nullptr )
      {
        v12 = *p_m_list;
        instance = (const CBaseEntity *)*p_m_list;
        CUtlMultiList<watcher_t,unsigned short>::RemoveAll(this: &g_WatcherList, list: v12);
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
          this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&g_WatcherList.m_List,
          elem: (unsigned __int16)instance);
        g_WatcherList.m_List.m_Memory.m_pMemory[(unsigned __int16)instance].m_Next = g_WatcherList.m_List.m_FirstFree;
        g_WatcherList.m_List.m_FirstFree = (unsigned __int16)instance;
        free(pMem: p_m_list);
      }
      v9 = &v14->m_Buckets.m_Memory.m_pMemory[v5];
      if ( v7 < v9->m_Size )
      {
        m_Size = v9->m_Size;
        if ( m_Size > 0 )
        {
          if ( v7 != m_Size - 1 )
          {
            v11 = v9->m_Memory.m_pMemory;
            v11[v7].key = v9->m_Memory.m_pMemory[m_Size - 1].key;
            v11[v7].data = v11[m_Size - 1].data;
          }
          --v9->m_Size;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A9D0
// Name: public: CEntityDataInstantiator<struct physicspushlist_t>::CEntityDataInstantiator<struct physicspushlist_t>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<physicspushlist_t> *__thiscall CEntityDataInstantiator<physicspushlist_t>::CEntityDataInstantiator<physicspushlist_t>(
        CEntityDataInstantiator<physicspushlist_t> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<physicspushlist_t>_vtbl *)&CEntityDataInstantiator<physicspushlist_t>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<physicspushlist_t>::HashEntry *, const CEntityDataInstantiator<physicspushlist_t>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = (unsigned int (__cdecl *)(const CEntityDataInstantiator<physicspushlist_t>::HashEntry *))CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019AA40
// Name: public: physicspushlist_t::physicspushlist_t(void)
// Source: json
//------------------------------------------------------------------------------
physicspushlist_t *__thiscall physicspushlist_t::physicspushlist_t(physicspushlist_t *this)
{
  this->pushedEnts[0].m_Index = -1;
  this->pushedEnts[1].m_Index = -1;
  this->pushedEnts[2].m_Index = -1;
  this->pushedEnts[3].m_Index = -1;
  this->pushedEnts[4].m_Index = -1;
  this->pushedEnts[5].m_Index = -1;
  this->pushedEnts[6].m_Index = -1;
  this->pushedEnts[7].m_Index = -1;
  this->pushedEnts[8].m_Index = -1;
  this->pushedEnts[9].m_Index = -1;
  this->pushedEnts[10].m_Index = -1;
  this->pushedEnts[11].m_Index = -1;
  this->pushedEnts[12].m_Index = -1;
  this->pushedEnts[13].m_Index = -1;
  this->pushedEnts[14].m_Index = -1;
  this->pushedEnts[15].m_Index = -1;
  this->pushedEnts[16].m_Index = -1;
  this->pushedEnts[17].m_Index = -1;
  this->pushedEnts[18].m_Index = -1;
  this->pushedEnts[19].m_Index = -1;
  this->pushedEnts[20].m_Index = -1;
  this->pushedEnts[21].m_Index = -1;
  this->pushedEnts[22].m_Index = -1;
  this->pushedEnts[23].m_Index = -1;
  this->pushedEnts[24].m_Index = -1;
  this->pushedEnts[25].m_Index = -1;
  this->pushedEnts[26].m_Index = -1;
  this->pushedEnts[27].m_Index = -1;
  this->pushedEnts[28].m_Index = -1;
  this->pushedEnts[29].m_Index = -1;
  this->pushedEnts[30].m_Index = -1;
  this->pushedEnts[31].m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019AAC0
// Name: public: virtual void __near * CEntityDataInstantiator<struct physicspushlist_t>::CreateDataObject(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<physicspushlist_t>::CreateDataObject(
        CEntityDataInstantiator<physicspushlist_t> *this,
        const CBaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  physicspushlist_t *v5; // eax
  physicspushlist_t *v6; // eax
  int v7; // edx
  int v8; // ecx
  CEntityDataInstantiator<physicspushlist_t>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&this->m_HashTable,
         src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: (const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *)&entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
             this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const AI_NamespaceAddInfo_t *)&entry);
    }
    v5 = (physicspushlist_t *)operator new(nSize: 0x220u);
    if ( v5 != nullptr )
      v6 = physicspushlist_t::physicspushlist_t(this: v5);
    else
      v6 = nullptr;
    v7 = HIWORD(v3);
    v8 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v7].m_Memory.m_pMemory[v8].data = (vphysicsupdateai_t *)v6;
    _V_memset(dest: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v7].m_Memory.m_pMemory[v8].data, fill: 0, count: 544);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x1019ABD0
// Name: public: CEntityDataInstantiator<struct vphysicsupdateai_t>::CEntityDataInstantiator<struct vphysicsupdateai_t>(void)
// Source: json
//------------------------------------------------------------------------------
CEntityDataInstantiator<vphysicsupdateai_t> *__thiscall CEntityDataInstantiator<vphysicsupdateai_t>::CEntityDataInstantiator<vphysicsupdateai_t>(
        CEntityDataInstantiator<vphysicsupdateai_t> *this)
{
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *p_m_HashTable; // ecx
  int i; // eax

  this->__vftable = (CEntityDataInstantiator<vphysicsupdateai_t>_vtbl *)&CEntityDataInstantiator<vphysicsupdateai_t>::`vftable';
  p_m_HashTable = (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable;
  p_m_HashTable->m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Buckets.m_Size = 0;
  this->m_HashTable.m_Buckets.m_pElements = nullptr;
  this->m_HashTable.m_CompareFunc = (bool (__cdecl *)(const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *, const CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry *))CEntityDataInstantiator<ModelScale>::CompareFunc;
  this->m_HashTable.m_KeyFunc = CEntityDataInstantiator<physicspushlist_t>::KeyFunc;
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: p_m_HashTable);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_HashTable,
    elem: this->m_HashTable.m_Buckets.m_Size,
    num: 64);
  for ( i = 0; i < 64; ++i )
  {
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_HashTable.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_HashTable.m_bPowerOfTwo = true;
  this->m_HashTable.m_ModMask = 63;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC40
// Name: public: virtual void __near * CEntityDataInstantiator<struct vphysicsupdateai_t>::CreateDataObject(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
vphysicsupdateai_t *__thiscall CEntityDataInstantiator<vphysicsupdateai_t>::CreateDataObject(
        CEntityDataInstantiator<vphysicsupdateai_t> *this,
        const CBaseEntity *instance)
{
  CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *p_m_HashTable; // edi
  unsigned int v3; // esi
  unsigned int v4; // ebx
  vphysicsupdateai_t *v5; // eax
  int v6; // edx
  int v7; // ecx
  CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry entry; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  p_m_HashTable = &this->m_HashTable;
  entry.key = instance;
  entry.data = nullptr;
  instance = nullptr;
  if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
         this: &this->m_HashTable,
         src: &entry,
         &pBucket,
         pIndex: (int *)&instance) == 0
    || (v3 = (unsigned int)instance | (pBucket << 16)) == -1 )
  {
    instance = nullptr;
    if ( CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)>::DoFind(
           this: p_m_HashTable,
           src: &entry,
           &pBucket,
           pIndex: (int *)&instance) != 0 )
    {
      v3 = (unsigned int)instance | (pBucket << 16);
    }
    else
    {
      v4 = pBucket;
      v3 = (v4 << 16)
         | CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
             this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const AI_NamespaceAddInfo_t *)&entry);
    }
    v5 = (vphysicsupdateai_t *)operator new(nSize: 0xCu);
    v6 = HIWORD(v3);
    v7 = (unsigned __int16)v3;
    p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data = v5;
    _V_memset(dest: p_m_HashTable->m_Buckets.m_Memory.m_pMemory[v6].m_Memory.m_pMemory[v7].data, fill: 0, count: 12);
  }
  return p_m_HashTable->m_Buckets.m_Memory.m_pMemory[HIWORD(v3)].m_Memory.m_pMemory[(unsigned __int16)v3].data;
}

//------------------------------------------------------------------------------
// Address: 0x1019AD30
// Name: public: virtual bool CDataObjectAccessSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataObjectAccessSystem::Init(CDataObjectAccessSystem *this)
{
  CEntityDataInstantiator<touchlink_t> *v2; // eax
  CEntityDataInstantiator<touchlink_t> *v3; // eax
  CEntityDataInstantiator<groundlink_t> *v4; // eax
  CEntityDataInstantiator<groundlink_t> *v5; // eax
  CEntityDataInstantiator<StepSimulationData> *v6; // eax
  CEntityDataInstantiator<StepSimulationData> *v7; // eax
  CEntityDataInstantiator<ModelScale> *v8; // eax
  CEntityDataInstantiator<ModelScale> *v9; // eax
  CEntityDataInstantiator<CWatcherList> *v10; // eax
  CEntityDataInstantiator<CWatcherList> *v11; // eax
  CEntityDataInstantiator<physicspushlist_t> *v12; // eax
  CEntityDataInstantiator<physicspushlist_t> *v13; // eax
  CEntityDataInstantiator<vphysicsupdateai_t> *v14; // eax
  CEntityDataInstantiator<vphysicsupdateai_t> *v15; // eax
  CEntityDataInstantiator<CWatcherList> *v16; // eax
  CEntityDataInstantiator<CWatcherList> *v17; // eax

  v2 = (CEntityDataInstantiator<touchlink_t> *)operator new(nSize: 0x28u);
  if ( v2 != nullptr )
    v3 = CEntityDataInstantiator<touchlink_t>::CEntityDataInstantiator<touchlink_t>(this: v2);
  else
    v3 = nullptr;
  if ( this->m_Accessors[1] == nullptr )
    this->m_Accessors[1] = v3;
  v4 = (CEntityDataInstantiator<groundlink_t> *)operator new(nSize: 0x28u);
  if ( v4 != nullptr )
    v5 = CEntityDataInstantiator<groundlink_t>::CEntityDataInstantiator<groundlink_t>(this: v4);
  else
    v5 = nullptr;
  if ( this->m_Accessors[0] == nullptr )
    this->m_Accessors[0] = v5;
  v6 = (CEntityDataInstantiator<StepSimulationData> *)operator new(nSize: 0x28u);
  if ( v6 != nullptr )
    v7 = CEntityDataInstantiator<StepSimulationData>::CEntityDataInstantiator<StepSimulationData>(this: v6);
  else
    v7 = nullptr;
  if ( this->m_Accessors[2] == nullptr )
    this->m_Accessors[2] = v7;
  v8 = (CEntityDataInstantiator<ModelScale> *)operator new(nSize: 0x28u);
  if ( v8 != nullptr )
    v9 = CEntityDataInstantiator<ModelScale>::CEntityDataInstantiator<ModelScale>(this: v8);
  else
    v9 = nullptr;
  if ( this->m_Accessors[3] == nullptr )
    this->m_Accessors[3] = v9;
  v10 = (CEntityDataInstantiator<CWatcherList> *)operator new(nSize: 0x28u);
  if ( v10 != nullptr )
    v11 = CEntityDataInstantiator<CWatcherList>::CEntityDataInstantiator<CWatcherList>(this: v10);
  else
    v11 = nullptr;
  if ( this->m_Accessors[4] == nullptr )
    this->m_Accessors[4] = v11;
  v12 = (CEntityDataInstantiator<physicspushlist_t> *)operator new(nSize: 0x28u);
  if ( v12 != nullptr )
    v13 = CEntityDataInstantiator<physicspushlist_t>::CEntityDataInstantiator<physicspushlist_t>(this: v12);
  else
    v13 = nullptr;
  if ( this->m_Accessors[5] == nullptr )
    this->m_Accessors[5] = v13;
  v14 = (CEntityDataInstantiator<vphysicsupdateai_t> *)operator new(nSize: 0x28u);
  if ( v14 != nullptr )
    v15 = CEntityDataInstantiator<vphysicsupdateai_t>::CEntityDataInstantiator<vphysicsupdateai_t>(this: v14);
  else
    v15 = nullptr;
  if ( this->m_Accessors[6] == nullptr )
    this->m_Accessors[6] = v15;
  v16 = (CEntityDataInstantiator<CWatcherList> *)operator new(nSize: 0x28u);
  if ( v16 != nullptr )
    v17 = CEntityDataInstantiator<CWatcherList>::CEntityDataInstantiator<CWatcherList>(this: v16);
  else
    v17 = nullptr;
  if ( this->m_Accessors[7] == nullptr )
    this->m_Accessors[7] = v17;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019AE50
// Name: private: void CBaseEntity::PhysicsToss(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsToss(CBaseEntity *this)
{
  int v2; // edi
  int v3; // ebx
  unsigned int m_Index; // eax
  CBaseEntityList *v5; // ebx
  CBaseEntity *GroundEntity; // eax
  unsigned int v7; // edx
  int v8; // eax
  CEntInfo *v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  bool v12; // zf
  CBaseEntity **v13; // eax
  CBaseEntity *v14; // edi
  float z; // ecx
  float frametime; // xmm3_4
  float x; // xmm2_4
  float v18; // xmm1_4
  float y; // xmm0_4
  float v20; // xmm0_4
  IPhysicsObject *m_pPhysicsObject; // edi
  CGameTrace trace; // [esp+10h] [ebp-6Ch] BYREF
  Vector vecAbsVelocity; // [esp+64h] [ebp-18h] BYREF
  Vector move; // [esp+70h] [ebp-Ch] BYREF
  int savedregs; // [esp+7Ch] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x400000) != 0 )
    goto LABEL_7;
  if ( !CBaseEntity::PhysicsRunSpecificThink(
          this,
          nContextIndex: -1,
          thinkFunc:  __thiscall CBaseEntity::`vcall'{200,{flat}}) )
    return;
  v2 = 0;
  if ( this->m_aThinkFunctions.m_Size <= 0 )
  {
LABEL_7:
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    if ( this->m_vecAbsVelocity.z <= 0.0 )
    {
      m_Index = this->m_hGroundEntity.m_Value.m_Index;
      if ( m_Index != -1 )
      {
        v5 = g_pEntityList;
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
        {
LABEL_15:
          v7 = this->m_hGroundEntity.m_Value.m_Index;
          if ( v7 != -1 )
          {
            v8 = (unsigned __int16)v7;
            v9 = &v5->m_EntPtrArray[(unsigned __int16)v7];
            v10 = HIWORD(v7);
            if ( v9->m_SerialNumber == v10 && v9->m_pEntity != nullptr )
            {
              v11 = v8;
              v12 = v5->m_EntPtrArray[v11].m_SerialNumber == v10;
              v13 = (CBaseEntity **)&v5->m_EntPtrArray[v11];
              if ( v12 )
                v14 = *v13;
              else
                v14 = nullptr;
              CNetworkHandleBase<CBaseEntity,CBaseEntity::NetworkVar_m_hGroundEntity>::Set(
                this: &this->m_hGroundEntity,
                val: nullptr);
              if ( v14 != nullptr )
              {
                CBaseEntity::PhysicsNotifyOtherOfGroundRemoval(ent: this, other: v14);
              }
              else
              {
                CBaseEntity::PhysicsNotifyOtherOfGroundRemoval(ent: this, other: nullptr);
                CBaseEntity::AddEntityToGroundList(this: nullptr, other: this);
              }
              CBaseEntity::RemoveFlag(this, flagsToRemove: 1);
            }
          }
          goto LABEL_25;
        }
        GroundEntity = CBaseEntity::GetGroundEntity(this);
        if ( CBaseEntity::IsStandable(this: GroundEntity) )
        {
LABEL_25:
          if ( (this->m_fFlags.m_Value & 1) == 0 )
            goto LABEL_34;
          if ( (this->m_iEFlags & 0x1000) != 0 )
            CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
          if ( vec3_origin.x != this->m_vecAbsVelocity.x
            || vec3_origin.y != this->m_vecAbsVelocity.y
            || vec3_origin.z != this->m_vecAbsVelocity.z
            || (CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle),
                vec3_origin.x != this->m_vecBaseVelocity.m_Value.x)
            || vec3_origin.y != this->m_vecBaseVelocity.m_Value.y
            || vec3_origin.z != this->m_vecBaseVelocity.m_Value.z )
          {
LABEL_34:
            CBaseEntity::PhysicsCheckVelocity(this);
            if ( this->m_MoveType.m_Value != 5 || (this->m_fFlags.m_Value & 0x800) != 0 )
            {
              if ( (this->m_iEFlags & 0x1000) != 0 )
                CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
              z = this->m_vecAbsVelocity.z;
              frametime = gpGlobals->frametime;
              x = this->m_vecBaseVelocity.m_Value.x;
              v18 = this->m_vecBaseVelocity.m_Value.z;
              *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
              y = this->m_vecBaseVelocity.m_Value.y;
              vecAbsVelocity.z = z;
              move.x = frametime * (float)(x + vecAbsVelocity.x);
              move.y = (float)(y + vecAbsVelocity.y) * frametime;
              move.z = (float)(v18 + z) * frametime;
              CBaseEntity::PhysicsCheckVelocity(this);
            }
            else
            {
              CBaseEntity::PhysicsAddGravityMove(this, &move);
            }
            v20 = gpGlobals->frametime;
            vecAbsVelocity.x = (float)(this->m_vecAngVelocity.x * v20) + this->m_angRotation.m_Value.x;
            vecAbsVelocity.y = (float)(this->m_vecAngVelocity.y * v20) + this->m_angRotation.m_Value.y;
            vecAbsVelocity.z = (float)(this->m_vecAngVelocity.z * v20) + this->m_angRotation.m_Value.z;
            CBaseEntity::SetLocalAngles(this, angles: (const QAngle *)&vecAbsVelocity);
            CBaseEntity::PhysicsPushEntity(this, push: &move, pTrace: &trace);
            m_pPhysicsObject = this->m_pPhysicsObject;
            if ( m_pPhysicsObject != nullptr )
            {
              if ( (this->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
              ((void (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, int, _DWORD))m_pPhysicsObject->UpdateShadow)(
                a1: m_pPhysicsObject,
                a2: &this->m_vecAbsOrigin,
                a3: &vec3_angle,
                a4: 1,
                a5: LODWORD(gpGlobals->frametime));
            }
            CBaseEntity::PhysicsCheckVelocity(this);
            if ( trace.allsolid )
            {
              CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
              CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
            }
            else if ( (this->m_Network.m_pPev->m_fStateFlags & 2) == 0 )
            {
              if ( trace.fraction != 1.0 )
                CBaseEntity::PerformFlyCollisionResolution(this, &trace, &move);
              CBaseEntity::PhysicsCheckWaterTransition(this);
            }
          }
          return;
        }
      }
    }
    v5 = g_pEntityList;
    goto LABEL_15;
  }
  v3 = 0;
  while ( CBaseEntity::PhysicsRunSpecificThink(
            this,
            nContextIndex: v2,
            thinkFunc: this->m_aThinkFunctions.m_Memory.m_pMemory[v3].m_pfnThink) )
  {
    ++v2;
    ++v3;
    if ( v2 >= this->m_aThinkFunctions.m_Size )
      goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B210
// Name: private: void CBaseEntity::PhysicsRigidChild(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsRigidChild(CBaseEntity *this)
{
  float z; // ecx
  unsigned int v3; // edx
  int v4; // edi
  int v5; // ebx
  SolidType_t v6; // eax
  QAngle *p_m_angAbsRotation; // ebx
  IPhysicsObject *m_pPhysicsObject; // edi
  Vector vecPrevOrigin; // [esp+10h] [ebp-10h] BYREF
  Vector *p_m_vecAbsOrigin; // [esp+1Ch] [ebp-4h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_vecAbsOrigin.z;
  v3 = (unsigned int)this->m_iEFlags >> 22;
  p_m_vecAbsOrigin = &this->m_vecAbsOrigin;
  *(_QWORD *)&vecPrevOrigin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  vecPrevOrigin.z = z;
  if ( (v3 & 1) != 0 )
    goto LABEL_9;
  if ( !CBaseEntity::PhysicsRunSpecificThink(
          this,
          nContextIndex: -1,
          thinkFunc:  __thiscall CBaseEntity::`vcall'{200,{flat}}) )
    return;
  v4 = 0;
  if ( this->m_aThinkFunctions.m_Size <= 0 )
  {
LABEL_9:
    CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: &vecPrevOrigin);
    if ( this->m_pPhysicsObject != nullptr )
    {
      v6 = this->m_Collision.GetSolid(this: &this->m_Collision);
      if ( v6 != SOLID_BBOX && v6 != SOLID_NONE )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        p_m_angAbsRotation = &this->m_angAbsRotation;
      }
      else
      {
        p_m_angAbsRotation = &vec3_angle;
      }
      m_pPhysicsObject = this->m_pPhysicsObject;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      ((void (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, int, _DWORD))m_pPhysicsObject->UpdateShadow)(
        a1: m_pPhysicsObject,
        a2: p_m_vecAbsOrigin,
        a3: p_m_angAbsRotation,
        a4: 1,
        a5: LODWORD(gpGlobals->frametime));
    }
  }
  else
  {
    v5 = 0;
    while ( CBaseEntity::PhysicsRunSpecificThink(
              this,
              nContextIndex: v4,
              thinkFunc: this->m_aThinkFunctions.m_Memory.m_pMemory[v5].m_pfnThink) )
    {
      ++v4;
      ++v5;
      if ( v4 >= this->m_aThinkFunctions.m_Size )
        goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B340
// Name: public: virtual void CBaseEntity::PhysicsSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsSimulate(CBaseEntity *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // edi
  unsigned __int8 m_Value; // al
  unsigned int v5; // eax
  const Vector *AbsVelocity; // eax
  int v7; // eax
  const char *pszValue; // esi
  Vector vecAbsVelocity; // [esp+4h] [ebp-10h] BYREF
  float v10; // [esp+10h] [ebp-4h]

  if ( this->m_bIsPlayerSimulated.m_Value || this->m_nSimulationTick != gpGlobals->tickcount )
  {
    this->m_nSimulationTick = gpGlobals->tickcount;
    m_Index = this->m_hMoveParent.m_Value.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    m_Value = this->m_MoveType.m_Value;
    if ( (m_Value != 0 || m_pEntity != nullptr) && m_Value != 6 )
    {
      v5 = this->m_hGroundEntity.m_Value.m_Index;
      if ( v5 == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity == nullptr )
      {
        CBaseEntity::RemoveFlag(this, flagsToRemove: 1);
      }
      if ( m_pEntity != nullptr )
      {
        ((void (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[35].SetRefEHandle)(a1: m_pEntity);
      }
      else
      {
        CBaseEntity::UpdateBaseVelocity(this);
        if ( (this->m_fFlags.m_Value & 0x1000000) == 0
          && (vec3_origin.x != this->m_vecBaseVelocity.m_Value.x
           || vec3_origin.y != this->m_vecBaseVelocity.m_Value.y
           || vec3_origin.z != this->m_vecBaseVelocity.m_Value.z) )
        {
          v10 = (float)(gpGlobals->frametime * 0.5) + 1.0;
          AbsVelocity = CBaseEntity::GetAbsVelocity(this);
          vecAbsVelocity.x = (float)(this->m_vecBaseVelocity.m_Value.x * v10) + AbsVelocity->x;
          vecAbsVelocity.y = (float)(this->m_vecBaseVelocity.m_Value.y * v10) + AbsVelocity->y;
          vecAbsVelocity.z = (float)(this->m_vecBaseVelocity.m_Value.z * v10) + AbsVelocity->z;
          CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
          CBaseEntity::SetBaseVelocity(this, v: &vec3_origin);
        }
        CBaseEntity::RemoveFlag(this, flagsToRemove: 0x1000000);
      }
      v7 = this->m_MoveType.m_Value;
      switch ( this->m_MoveType.m_Value )
      {
        case 0u:
          CBaseEntity::PhysicsRigidChild(this);
          break;
        case 3u:
          CBaseEntity::PhysicsStep(this);
          break;
        case 4u:
        case 5u:
          CBaseEntity::PhysicsToss(this);
          break;
        case 6u:
          return;
        case 7u:
          CBaseEntity::PhysicsPusher(this);
          break;
        case 8u:
          CBaseEntity::PhysicsNoclip(this);
          break;
        case 0xBu:
          CBaseEntity::PhysicsCustom(this);
          break;
        default:
          pszValue = this->m_iClassname.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          _Warning(a1: "PhysicsSimulate: %s bad movetype %d", pszValue, v7);
          break;
      }
    }
    else
    {
      CBaseEntity::PhysicsNone(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037DA60
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
// Address: 0x1037DB10
// Name: public: void CUtlMultiList<struct watcher_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<watcher_t,unsigned short>::RemoveAll(
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

} // namespace server
