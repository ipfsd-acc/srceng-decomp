// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmf_tweak/vmf_tweak.cpp
// Functions: 50
// ============================================================

#include "utils\vmf_tweak\vmf_tweak.h"

//------------------------------------------------------------------------------
// Address: 0x00401840
// Name: public: void CUtlLinkedList<void (*)(void),unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<void (*)(void),unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<void (__cdecl*)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl*)(void),unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<void (__cdecl*)(void),unsigned short> *v2; // esi
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
// Address: 0x00403D70
// Name: public: static bool CChunkHolder::SortChunkFn(class CChunkHolder const __near &,class CChunkHolder const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CChunkHolder::SortChunkFn(const CChunkHolder *a, const CChunkHolder *b)
{
  return a->m_LoadOrder < b->m_LoadOrder;
}

//------------------------------------------------------------------------------
// Address: 0x00403D90
// Name: public: virtual enum LoggingResponse_t CNonFatalLoggingResponsePolicy::OnLog(struct LoggingContext_t const __near *)
// Source: json
//------------------------------------------------------------------------------
LoggingResponse_t __thiscall CNonFatalLoggingResponsePolicy::OnLog(
        CNonFatalLoggingResponsePolicy *this,
        const LoggingContext_t *pContext)
{
  int v2; // eax
  LoggingResponse_t result; // eax

  result = pContext->m_Severity == LS_ASSERT
        && (v2 = _CommandLine(a1: this),
            (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-noassert") == 0)
        || pContext->m_Severity == LS_ERROR;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403DD0
// Name: public: void CKeyValue::SetKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyValue::SetKey(CKeyValue *this, const char *pStr)
{
  char *v3; // eax

  free(pMem: this->m_pKey);
  v3 = (char *)operator new(nSize: strlen(pStr) + 1);
  strcpy(v3, pStr);
  this->m_pKey = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00403E30
// Name: public: void CKeyValue::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyValue::SetValue(CKeyValue *this, const char *pStr)
{
  char *v3; // eax

  free(pMem: this->m_pValue);
  v3 = (char *)operator new(nSize: strlen(pStr) + 1);
  strcpy(v3, pStr);
  this->m_pValue = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00403E90
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CChunk __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CChunk *,unsigned short> *m_pMemory; // edx
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
      this->m_pMemory = (UtlLinkedListElem_t<CChunk *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                          this: _g_pMemAlloc,
                                                                          a2: m_pMemory,
                                                                          a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CChunk *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                          this: _g_pMemAlloc,
                                                                          a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403F40
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CChunkHolder,int> *m_pMemory; // edx

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
      this->m_pMemory = (UtlRBTreeNode_t<CChunkHolder,int> *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: m_pMemory,
                                                               a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CChunkHolder,int> *)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403FF0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CKeyValue __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CKeyValue *,int> *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CKeyValue *,int> *)_g_pMemAlloc->Realloc_2(
                                                                  this: _g_pMemAlloc,
                                                                  a2: m_pMemory,
                                                                  a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CKeyValue *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404090
// Name: public: int CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Parent(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( i == -1 )
    return dword_42972C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x004040F0
// Name: public: int CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::LeftChild(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00404150
// Name: public: int CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RightChild(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( i == -1 )
    return dword_429728;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004041B0
// Name: public: bool CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::IsRightChild(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CChunkHolder,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( m_Parent == -1 )
    return dword_429728 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00404270
// Name: protected: void CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::FindInsertionPosition(class CChunkHolder const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this,
        const CChunkHolder *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // edi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_429728 = -1;
        dword_42972C = -1;
        dword_429730 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_429728 = -1;
        dword_42972C = -1;
        dword_429730 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404370
// Name: public: void CUtlLinkedList<class CKeyValue __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CKeyValue __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int>>::RemoveAll(
        CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CKeyValue *,int> *v2; // esi
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
// Address: 0x004043D0
// Name: protected: unsigned short CUtlLinkedList<class CKeyValue __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CKeyValue __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CKeyValue *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> *)this,
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
      if ( `CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x00404550
// Name: protected: unsigned short CUtlLinkedList<class CChunk __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CChunk __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CChunk *,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x004046D0
// Name: public: int CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::NewNode(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CChunkHolder,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CChunkHolder,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004047A0
// Name: protected: int CUtlLinkedList<class CKeyValue __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CKeyValue __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int>>::AllocInternal(
        CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CKeyValue *,int> *v8; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int>>::AllocInternal'::`12'::__executeCount;
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
// Address: 0x004048D0
// Name: public: bool CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::IsLeftChild(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CChunkHolder,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00404990
// Name: protected: void CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RotateLeft(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CChunkHolder,int> *v6; // ecx
  int v7; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v8; // ecx
  int v9; // ecx
  int v10; // ecx

  v2 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::LeftChild(
                                 this,
                                 i: m_Right)].m_Parent = elem;
    v7 = elem;
  }
  if ( m_Right != -1 )
  {
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v9 = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Parent(
           this,
           i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v9].m_Left = m_Right;
  }
  else
  {
    v10 = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v10].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00404B40
// Name: protected: void CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RotateRight(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CChunkHolder,int> *v6; // ecx
  int v7; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v8; // ecx
  int v9; // ecx
  int v10; // ecx

  v2 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( m_Left == -1 )
    v8 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Left];
  if ( v8->m_Right != -1 )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
    v7 = elem;
  }
  if ( m_Left != -1 )
  {
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    v9 = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Parent(
           this,
           i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v9].m_Right = m_Left;
  }
  else
  {
    v10 = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v10].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00404CF0
// Name: public: class CKeyValue __near * CChunk::FindKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKeyValue *__thiscall CChunk::FindKey(CChunk *this, const char *pKeyName)
{
  unsigned __int16 m_Head; // ax
  int v4; // esi
  CKeyValue *m_Element; // ebx

  m_Head = this->m_Keys.m_Head;
  if ( m_Head == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    v4 = m_Head;
    m_Element = this->m_Keys.m_Memory.m_pMemory[v4].m_Element;
    if ( _V_stricmp(s1: m_Element->m_pKey, s2: pKeyName) == 0 )
      break;
    m_Head = this->m_Keys.m_Memory.m_pMemory[v4].m_Next;
    if ( m_Head == 0xFFFF )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x00404D50
// Name: public: class CChunk __near * CChunk::FindChunk(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CChunk *__thiscall CChunk::FindChunk(CChunk *this, const char *pChunkName)
{
  unsigned __int16 m_Head; // ax
  int v4; // esi
  CChunk *m_Element; // ebx

  m_Head = this->m_Chunks.m_Head;
  if ( m_Head == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    v4 = m_Head;
    m_Element = this->m_Chunks.m_Memory.m_pMemory[v4].m_Element;
    if ( _V_stricmp(s1: m_Element->m_pChunkName, s2: pChunkName) == 0 )
      break;
    m_Head = this->m_Chunks.m_Memory.m_pMemory[v4].m_Next;
    if ( m_Head == 0xFFFF )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x00404DB0
// Name: public: class CKeyValue __near * CChunk::FindKey(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKeyValue *__thiscall CChunk::FindKey(CChunk *this, const char *pKeyName, const char *pValue)
{
  unsigned __int16 m_Head; // ax
  int v5; // esi
  CKeyValue *m_Element; // edi

  m_Head = this->m_Keys.m_Head;
  if ( m_Head == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    v5 = m_Head;
    m_Element = this->m_Keys.m_Memory.m_pMemory[v5].m_Element;
    if ( _V_stricmp(s1: m_Element->m_pKey, s2: pKeyName) == 0 && _V_stricmp(s1: m_Element->m_pValue, s2: pValue) == 0 )
      break;
    m_Head = this->m_Keys.m_Memory.m_pMemory[v5].m_Next;
    if ( m_Head == 0xFFFF )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x00404E30
// Name: void ScanChunks(class CChunk __near *,void (*)(class CChunk __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScanChunks(CChunk *pChunk, void (__cdecl *fn)(CChunk *))
{
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CChunk *,unsigned short> *m_pMemory; // ecx
  int v4; // esi

  fn(a1: pChunk);
  m_Head = pChunk->m_Chunks.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = pChunk->m_Chunks.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      ScanChunks(pChunk: m_pMemory[v4].m_Element, fn);
      m_pMemory = pChunk->m_Chunks.m_Memory.m_pMemory;
      m_Head = m_pMemory[v4].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404E80
// Name: public: int CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::FirstInorder(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_429728 = -1;
      dword_42972C = -1;
      dword_429730 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_429728 = -1;
      dword_42972C = -1;
      dword_429730 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404F30
// Name: public: int CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::NextInorder(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<CChunkHolder,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_429728 = -1;
    dword_42972C = -1;
    dword_429730 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_429728 = -1;
          dword_42972C = -1;
          dword_429730 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_429728 = -1;
        dword_42972C = -1;
        dword_429730 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_429728 = -1;
        dword_42972C = -1;
        dword_429730 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004050B0
// Name: public: int CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::LastInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::LastInorder(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_429728 = -1;
      dword_42972C = -1;
      dword_429730 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( v3[1] == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_429728 = -1;
      dword_42972C = -1;
      dword_429730 = 1;
    }
    if ( result == -1 )
      result = dword_429728;
    else
      result = this->m_Elements.m_pMemory[result].m_Right;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405160
// Name: public: void CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RemoveAll(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this)
{
  int index; // eax
  BOOL v3; // ecx
  int v4; // esi
  int v5; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = this->m_Elements.m_nAllocationCount > 0;
    v4 = v3 - 1;
    if ( v3 )
    {
      do
      {
        if ( v4 >= 0
          && v4 < this->m_Elements.m_nAllocationCount
          && v4 <= index
          && CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::LeftChild(
               this,
               i: v4) != v4 )
        {
          v5 = v4;
          this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v5].m_Left = v4;
          this->m_FirstFree = v4;
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        if ( ++v4 < 0 || v4 >= this->m_Elements.m_nAllocationCount )
          v4 = -1;
      }
      while ( v4 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004051F0
// Name: public: void CUtlLinkedList<class CKeyValue __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CKeyValue __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CChunk *,unsigned short> *m_pMemory; // eax
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
// Address: 0x00405280
// Name: protected: void CUtlRBTree<class CChunkHolder,int,bool (*)(class CChunkHolder const __near &,class CChunkHolder const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChunkHolder,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::InsertRebalance(
        CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CChunkHolder,int> *v7; // ecx
  UtlRBTreeNode_t<CChunkHolder,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CChunkHolder,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CChunkHolder,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v18; // ecx
  UtlRBTreeNode_t<CChunkHolder,int> *v19; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v20; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v23; // ecx
  UtlRBTreeNode_t<CChunkHolder,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_429728 = -1;
        dword_42972C = -1;
        dword_429730 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_429728 = -1;
        dword_42972C = -1;
        dword_429730 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_429728 = -1;
        dword_42972C = -1;
        dword_429730 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_429728 = -1;
        dword_42972C = -1;
        dword_429730 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_429728 = -1;
          dword_42972C = -1;
          dword_429730 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_429728 = -1;
          dword_42972C = -1;
          dword_429730 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_429728 = -1;
            dword_42972C = -1;
            dword_429730 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_429728 = -1;
            dword_42972C = -1;
            dword_429730 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_429728 = -1;
          dword_42972C = -1;
          dword_429730 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_429728 = -1;
          dword_42972C = -1;
          dword_429730 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_429728 = -1;
            dword_42972C = -1;
            dword_429730 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_429728 = -1;
            dword_42972C = -1;
            dword_429730 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CChunkHolder,int> *)&`CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405750
// Name: public: void CUtlLinkedList<class CKeyValue __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CKeyValue __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int>>::Unlink(
        CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CKeyValue *,int> *v2; // eax
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
// Address: 0x004057D0
// Name: public: CChunk::CChunk(void)
// Source: json
//------------------------------------------------------------------------------
CChunk *__thiscall CChunk::CChunk(CChunk *this)
{
  CChunk *result; // eax
  UtlLinkedListElem_t<CChunk *,unsigned short> *m_pMemory; // ecx

  result = this;
  this->m_Keys.m_Memory.m_pMemory = nullptr;
  this->m_Keys.m_Memory.m_nAllocationCount = 0;
  this->m_Keys.m_Memory.m_nGrowSize = 0;
  this->m_Keys.m_LastAlloc.index = -1;
  this->m_Keys.m_Head = -1;
  this->m_Keys.m_Tail = -1;
  this->m_Keys.m_FirstFree = -1;
  this->m_Keys.m_ElementCount = 0;
  this->m_Keys.m_NumAlloced = 0;
  this->m_Keys.m_pElements = this->m_Keys.m_Memory.m_pMemory;
  this->m_Chunks.m_Memory.m_pMemory = nullptr;
  this->m_Chunks.m_Memory.m_nAllocationCount = 0;
  this->m_Chunks.m_Memory.m_nGrowSize = 0;
  this->m_Chunks.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Chunks.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_Chunks.m_Memory.m_pMemory;
  *(_DWORD *)&result->m_Chunks.m_Head = -1;
  result->m_Chunks.m_NumAlloced = 0;
  result->m_Chunks.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405830
// Name: void FixAINodes(class CChunk __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixAINodes(CChunk *pChunk)
{
  CKeyValue *Key; // eax
  CKeyValue *v2; // eax
  CKeyValue *v3; // esi
  __int16 v4; // ax
  int v5; // ecx
  CKeyValue *v6; // eax
  CKeyValue *v7; // esi
  __int16 v8; // ax
  int v9; // ecx
  char str[256]; // [esp+4h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: pChunk->m_pChunkName, s2: "entity") == 0 )
  {
    Key = CChunk::FindKey(this: pChunk, pKeyName: "classname");
    if ( Key == nullptr || _V_stricmp(s1: Key->m_pValue, s2: "info_node") != 0 )
    {
      v6 = CChunk::FindKey(this: pChunk, pKeyName: "classname");
      if ( v6 != nullptr && _V_stricmp(s1: v6->m_pValue, s2: "info_node_link") == 0 )
      {
        v7 = CChunk::FindKey(this: pChunk, pKeyName: "_distance");
        if ( v7 != nullptr )
        {
          v8 = atoi(nptr: v7->m_pValue);
          v9 = v8 & 0x3FF;
          if ( (v8 & 0x400) != 0 )
            v9 |= 0x800u;
          V_snprintf(pDest: str, maxLen: 256, pFormat: "%d", v9);
          CKeyValue::SetValue(this: v7, pStr: str);
          ++g_nNodeLinksProcessed;
        }
      }
    }
    else
    {
      v2 = CChunk::FindKey(this: pChunk, pKeyName: "spawnflags");
      v3 = v2;
      if ( v2 != nullptr )
      {
        v4 = atoi(nptr: v2->m_pValue);
        v5 = v4 & 0x1FF;
        if ( (v4 & 0x200) != 0 )
          v5 |= 0x400u;
        if ( (v4 & 0x400) != 0 )
          v5 |= 0x1000u;
        if ( (v4 & 0x800) != 0 )
          v5 |= 0x200u;
        V_snprintf(pDest: str, maxLen: 256, pFormat: "%d", v5);
        CKeyValue::SetValue(this: v3, pStr: str);
        ++g_nNodesProcessed;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004059A0
// Name: void FindSpeedrunTimes(class CChunk __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindSpeedrunTimes(CChunk *pChunk)
{
  CKeyValue *v1; // eax
  CKeyValue *v2; // eax
  CKeyValue *Key; // eax
  CKeyValue *v4; // eax
  int v5; // eax

  if ( _V_stricmp(s1: pChunk->m_pChunkName, s2: "world") != 0 )
  {
    if ( _V_stricmp(s1: pChunk->m_pChunkName, s2: "entity") == 0 )
    {
      Key = CChunk::FindKey(this: pChunk, pKeyName: "classname");
      if ( Key != nullptr && _V_stricmp(s1: Key->m_pValue, s2: "asw_gamerules") == 0 )
        g_bFoundGameRules = true;
      v4 = CChunk::FindKey(this: pChunk, pKeyName: "id");
      if ( v4 != nullptr )
      {
        v5 = atoi(nptr: v4->m_pValue);
        if ( v5 > g_iHighestEntityID )
          g_iHighestEntityID = v5;
      }
    }
  }
  else
  {
    v1 = CChunk::FindKey(this: pChunk, pKeyName: "speedruntime");
    if ( v1 != nullptr )
    {
      g_iSpeedrunTime = atoi(nptr: v1->m_pValue);
      g_bFoundSpeedrun = true;
    }
    v2 = CChunk::FindKey(this: pChunk, pKeyName: "speedruntimesp");
    if ( v2 != nullptr )
    {
      g_iSpeedrunTimeSingleplayer = atoi(nptr: v2->m_pValue);
      g_bFoundSpeedrun = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A80
// Name: public: void CUtlLinkedList<class CChunk __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CChunk __near *,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CChunk *,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CChunk *,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CChunk *,unsigned short> *v7; // ebx

  CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x00405B00
// Name: public: unsigned short CUtlLinkedList<class CKeyValue __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CKeyValue __near *,unsigned short>,unsigned short>>::AddToTail(class CKeyValue __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short> > *this,
        CKeyValue **src)
{
  int v3; // esi
  int result; // eax
  UtlLinkedListElem_t<CKeyValue *,unsigned short> *v5; // eax

  v3 = (unsigned __int16)CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::LinkBefore(
      (CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> > *)this,
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
// Address: 0x00405B40
// Name: enum ChunkFileResult_t MyKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl MyKeyHandler(const char *szKey, const char *szValue)
{
  CKeyValue *v2; // eax
  CKeyValue *v3; // ebx
  char *v4; // eax
  char *v5; // eax
  CChunk *v6; // esi
  unsigned __int16 v7; // ax
  int v8; // edi
  UtlLinkedListElem_t<CKeyValue *,unsigned short> *v9; // eax

  v2 = (CKeyValue *)operator new(nSize: 0xCu);
  v3 = nullptr;
  if ( v2 != nullptr )
  {
    v2->m_pValue = nullptr;
    v2->m_pKey = nullptr;
    v3 = v2;
  }
  v3->m_LoadOrder = g_CurLoadOrder++;
  v4 = (char *)operator new(nSize: strlen(szKey) + 1);
  strcpy(v4, szKey);
  v3->m_pKey = v4;
  v5 = (char *)operator new(nSize: strlen(szValue) + 1);
  strcpy(v5, szValue);
  v3->m_pValue = v5;
  v6 = g_pCurChunk;
  v7 = CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal(
         this: &g_pCurChunk->m_Keys,
         multilist: false);
  v8 = v7;
  if ( v7 != 0xFFFF )
  {
    CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> > *)&v6->m_Keys,
      before: 0xFFFFu,
      elem: v7);
    v9 = &v6->m_Keys.m_Memory.m_pMemory[v8];
    if ( v9 != nullptr )
      v9->m_Element = v3;
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00405C10
// Name: class CChunk __near * ParseChunk(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CChunk *__cdecl ParseChunk(const char *pChunkName, bool bOnlyOne)
{
  CChunk *v2; // eax
  CChunk *v3; // edi
  char *v4; // eax
  CChunk *v5; // esi

  v2 = (CChunk *)operator new(nSize: 0x40u);
  if ( v2 != nullptr )
    v3 = CChunk::CChunk(this: v2);
  else
    v3 = nullptr;
  v4 = (char *)operator new(nSize: strlen(pChunkName) + 1);
  strcpy(v4, pChunkName);
  v3->m_pChunkName = v4;
  v3->m_LoadOrder = g_CurLoadOrder;
  v5 = g_pCurChunk;
  ++g_CurLoadOrder;
  g_pCurChunk = v3;
  if ( CChunkFile::ReadChunk(
         this: g_pChunkFile,
         pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))MyKeyHandler,
         pData: nullptr) == ChunkFile_Ok )
  {
    while ( !bOnlyOne
         && CChunkFile::ReadChunk(
              this: g_pChunkFile,
              pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))MyKeyHandler,
              pData: nullptr) == ChunkFile_Ok )
      ;
  }
  g_pCurChunk = v5;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00405CD0
// Name: void WriteChunks_R(class CChunkFile __near *,class CChunk __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteChunks_R(CChunkFile *pFile, CChunk *pChunk, bool bRoot)
{
  CChunkFile *v3; // edi
  unsigned __int16 m_Head; // ax
  int v5; // edi
  int v6; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *m_pMemory; // ecx
  int v8; // edx
  unsigned int v9; // esi
  CChunkHolder *p_m_Data; // esi
  int m_Next; // eax
  int v12; // edi
  int v13; // eax
  UtlRBTreeNode_t<CChunkHolder,int> *v14; // ecx
  int v15; // edx
  unsigned int v16; // esi
  CChunkHolder *v17; // esi
  int v18; // esi
  CUtlRBTree<CChunkHolder,int,bool (__cdecl*)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int> > sortedStuff; // [esp+8h] [ebp-38h] BYREF
  CChunkHolder holder; // [esp+2Ch] [ebp-14h] BYREF
  int parent; // [esp+38h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Fh] [ebp-1h] BYREF

  v3 = pFile;
  if ( !bRoot )
    CChunkFile::BeginChunk(this: pFile, pszChunkName: pChunk->m_pChunkName);
  sortedStuff.m_Root = -1;
  sortedStuff.m_FirstFree = -1;
  sortedStuff.m_LastAlloc.index = -1;
  m_Head = pChunk->m_Keys.m_Head;
  sortedStuff.m_LessFunc = (bool (__cdecl *)(const CChunkHolder *, const CChunkHolder *))CChunkHolder::SortChunkFn;
  memset(&sortedStuff.m_Elements, 0, sizeof(sortedStuff.m_Elements));
  sortedStuff.m_NumElements = 0;
  sortedStuff.m_pElements = nullptr;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      v5 = m_Head;
      holder.m_pKey = pChunk->m_Keys.m_Memory.m_pMemory[v5].m_Element;
      holder.m_LoadOrder = holder.m_pKey->m_LoadOrder;
      holder.m_pChunk = nullptr;
      parent = -1;
      leftchild = false;
      CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::FindInsertionPosition(
        this: &sortedStuff,
        insert: &holder,
        &parent,
        &leftchild);
      v6 = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::NewNode(this: &sortedStuff);
      m_pMemory = sortedStuff.m_Elements.m_pMemory;
      v8 = parent;
      v9 = v6;
      sortedStuff.m_Elements.m_pMemory[v9].m_Parent = parent;
      m_pMemory[v9].m_Right = -1;
      m_pMemory[v9].m_Left = -1;
      m_pMemory[v9].m_Tag = 0;
      if ( v8 == -1 )
      {
        sortedStuff.m_Root = v6;
      }
      else if ( leftchild )
      {
        m_pMemory[v8].m_Left = v6;
      }
      else
      {
        m_pMemory[v8].m_Right = v6;
      }
      CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::InsertRebalance(
        this: &sortedStuff,
        elem: v6);
      ++sortedStuff.m_NumElements;
      p_m_Data = &sortedStuff.m_Elements.m_pMemory[v9].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = holder;
      m_Head = pChunk->m_Keys.m_Memory.m_pMemory[v5].m_Next;
    }
    while ( m_Head != 0xFFFF );
    v3 = pFile;
  }
  m_Next = pChunk->m_Chunks.m_Head;
  if ( m_Next != 0xFFFF )
  {
    do
    {
      v12 = (unsigned __int16)m_Next;
      holder.m_pChunk = pChunk->m_Chunks.m_Memory.m_pMemory[v12].m_Element;
      holder.m_LoadOrder = holder.m_pChunk->m_LoadOrder;
      holder.m_pKey = nullptr;
      parent = -1;
      leftchild = false;
      CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::FindInsertionPosition(
        this: &sortedStuff,
        insert: &holder,
        &parent,
        &leftchild);
      v13 = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::NewNode(this: &sortedStuff);
      v14 = sortedStuff.m_Elements.m_pMemory;
      v15 = parent;
      v16 = v13;
      sortedStuff.m_Elements.m_pMemory[v16].m_Parent = parent;
      v14[v16].m_Right = -1;
      v14[v16].m_Left = -1;
      v14[v16].m_Tag = 0;
      if ( v15 == -1 )
      {
        sortedStuff.m_Root = v13;
      }
      else if ( leftchild )
      {
        v14[v15].m_Left = v13;
      }
      else
      {
        v14[v15].m_Right = v13;
      }
      CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::InsertRebalance(
        this: &sortedStuff,
        elem: v13);
      ++sortedStuff.m_NumElements;
      v17 = &sortedStuff.m_Elements.m_pMemory[v16].m_Data;
      if ( v17 != nullptr )
        *v17 = holder;
      m_Next = pChunk->m_Chunks.m_Memory.m_pMemory[v12].m_Next;
    }
    while ( m_Next != 0xFFFF );
    v3 = pFile;
  }
  v18 = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::FirstInorder(this: &sortedStuff);
  if ( v18 != -1 )
  {
    while ( 1 )
    {
      if ( sortedStuff.m_Elements.m_pMemory[v18].m_Data.m_pKey != nullptr )
        CChunkFile::WriteKeyValue(
          this: v3,
          pszKey: sortedStuff.m_Elements.m_pMemory[v18].m_Data.m_pKey->m_pKey,
          pszValue: sortedStuff.m_Elements.m_pMemory[v18].m_Data.m_pKey->m_pValue);
      else
        WriteChunks_R(pFile: v3, pChunk: sortedStuff.m_Elements.m_pMemory[v18].m_Data.m_pChunk, bRoot: false);
      if ( v18 == CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::LastInorder(this: &sortedStuff) )
        break;
      v18 = CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::NextInorder(
              this: &sortedStuff,
              i: v18);
    }
  }
  if ( !bRoot )
    CChunkFile::EndChunk(this: v3);
  CUtlRBTree<CChunkHolder,int,bool (__cdecl *)(CChunkHolder const &,CChunkHolder const &),CUtlMemory<UtlRBTreeNode_t<CChunkHolder,int>,int>>::RemoveAll(this: &sortedStuff);
  if ( sortedStuff.m_Elements.m_nGrowSize >= 0 && sortedStuff.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedStuff.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00405FA0
// Name: bool WriteChunkFile(char const __near *,class CChunk __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WriteChunkFile(const char *pOutFilename, CChunk *pRoot)
{
  CChunkFile chunkFile; // [esp+4h] [ebp-344h] BYREF

  CChunkFile::CChunkFile(this: &chunkFile);
  if ( CChunkFile::Open(this: &chunkFile, pszFileName: pOutFilename, eMode: ChunkFile_Write) != 0 )
  {
    printf(format: "Error opening chunk file %s for writing.\n", pOutFilename);
    CChunkFile::~CChunkFile(this: &chunkFile);
    return 0;
  }
  else
  {
    printf(format: "Writing..");
    WriteChunks_R(pFile: &chunkFile, pChunk: pRoot, bRoot: true);
    printf(format: "\n\n");
    CChunkFile::~CChunkFile(this: &chunkFile);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406030
// Name: void LogicAuto(class CChunk __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LogicAuto(CChunk *pChunk)
{
  CKeyValue *Key; // eax
  CChunk *Chunk; // eax
  CChunk *v3; // esi
  CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short> > *p_m_Keys; // edi
  CKeyValue *m_Element; // ebx
  signed int m_ElementCount; // edx
  int m_Head; // eax
  int m_Next; // ebx
  int v9; // ebx
  int v10; // esi
  CKeyValue *v11; // eax
  CKeyValue *v12; // ebx
  int v13; // eax
  int v14; // esi
  UtlLinkedListElem_t<CKeyValue *,int> *m_pMemory; // edx
  UtlLinkedListElem_t<CKeyValue *,int> *v16; // eax
  int m_Tail; // ecx
  CKeyValue *v18; // edx
  UtlLinkedListElem_t<CKeyValue *,int> *v19; // ebx
  unsigned __int16 v20; // ax
  int v21; // esi
  UtlLinkedListElem_t<CKeyValue *,unsigned short> *v22; // eax
  int v23; // ecx
  int v24; // edx
  UtlLinkedListElem_t<CKeyValue *,unsigned short> *v25; // eax
  bool v26; // zf
  UtlLinkedListElem_t<CKeyValue *,unsigned short> *v27; // eax
  CKeyValue *v28; // eax
  CKeyValue *v29; // edi
  char *v30; // eax
  const char *v31; // [esp-10h] [ebp-244h]
  const char *m_pValue; // [esp-Ch] [ebp-240h]
  char str[512]; // [esp+4h] [ebp-230h] BYREF
  CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int> > newKeys; // [esp+204h] [ebp-30h] BYREF
  CChunk *pConnections; // [esp+22Ch] [ebp-8h]
  unsigned int curVal; // [esp+230h] [ebp-4h] BYREF

  Key = CChunk::FindKey(this: pChunk, pKeyName: "classname");
  if ( Key != nullptr && _V_stricmp(s1: Key->m_pValue, s2: "logic_auto") == 0 )
  {
    Chunk = CChunk::FindChunk(this: pChunk, pChunkName: "connections");
    v3 = Chunk;
    pConnections = Chunk;
    if ( Chunk != nullptr )
    {
      curVal = 0;
      if ( Chunk->m_Keys.m_ElementCount != 0 )
      {
        p_m_Keys = &Chunk->m_Keys;
        while ( 1 )
        {
          m_Element = p_m_Keys->m_Memory.m_pMemory[(unsigned __int16)curVal].m_Element;
          if ( V_stristr(pStr: m_Element->m_pValue, pSearch: "tonemap") == m_Element->m_pValue )
            break;
          m_ElementCount = v3->m_Keys.m_ElementCount;
          if ( (int)++curVal >= m_ElementCount )
            return;
        }
        ++g_nLogicAutoReplacementsMade;
        memset(&newKeys, 0, 12);
        newKeys.m_ElementCount = 0;
        newKeys.m_NumAlloced = 0;
        newKeys.m_pElements = nullptr;
        m_Head = v3->m_Keys.m_Head;
        m_Next = -1;
        newKeys.m_LastAlloc.index = -1;
        memset(&newKeys.m_Head, 255, 12);
        if ( m_Head != 0xFFFF )
        {
          do
          {
            v9 = 8 * (unsigned __int16)m_Head;
            v10 = *(int *)((char *)&p_m_Keys->m_Memory.m_pMemory->m_Element + v9);
            v31 = *(const char **)(v10 + 4);
            curVal = v9;
            if ( _V_stricmp(s1: v31, s2: "OnMapSpawn") == 0
              && V_stristr(pStr: *(char **)(v10 + 8), pSearch: "tonemap") == *(char **)(v10 + 8) )
            {
              v11 = (CKeyValue *)operator new(nSize: 0xCu);
              v12 = nullptr;
              if ( v11 != nullptr )
              {
                v11->m_pValue = nullptr;
                v11->m_pKey = nullptr;
                v12 = v11;
              }
              CKeyValue::SetKey(this: v12, pStr: "OnMapTransition");
              CKeyValue::SetValue(this: v12, pStr: *(const char **)(v10 + 8));
              v13 = CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int>>::AllocInternal(
                      this: &newKeys,
                      multilist: false);
              v14 = v13;
              if ( v13 != -1 )
              {
                CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int>>::Unlink(
                  this: &newKeys,
                  elem: v13);
                m_pMemory = newKeys.m_Memory.m_pMemory;
                v16 = &newKeys.m_Memory.m_pMemory[v14];
                m_Tail = newKeys.m_Tail;
                v16->m_Next = -1;
                v16->m_Previous = m_Tail;
                newKeys.m_Tail = v14;
                if ( m_Tail == -1 )
                  newKeys.m_Head = v14;
                else
                  m_pMemory[m_Tail].m_Next = v14;
                ++newKeys.m_ElementCount;
                if ( v16 != nullptr )
                  v16->m_Element = v12;
              }
              v9 = curVal;
            }
            m_Head = *(unsigned __int16 *)((char *)&p_m_Keys->m_Memory.m_pMemory->m_Next + v9);
          }
          while ( m_Head != 0xFFFF );
          v3 = pConnections;
          m_Next = newKeys.m_Head;
        }
        for ( ; m_Next != -1; m_Next = v19->m_Next )
        {
          v18 = newKeys.m_Memory.m_pMemory[m_Next].m_Element;
          v19 = &newKeys.m_Memory.m_pMemory[m_Next];
          m_pValue = v18->m_pValue;
          curVal = (unsigned int)v19;
          if ( CChunk::FindKey(this: v3, pKeyName: "OnMapTransition", pValue: m_pValue) == nullptr )
          {
            v20 = CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal(
                    this: p_m_Keys,
                    multilist: false);
            v21 = v20;
            if ( v20 == 0xFFFF )
            {
              v3 = pConnections;
            }
            else
            {
              CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::Unlink(
                this: (CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> > *)p_m_Keys,
                elem: v20);
              v22 = p_m_Keys->m_Memory.m_pMemory;
              v23 = v21;
              v22[v23].m_Next = -1;
              v24 = p_m_Keys->m_Tail;
              v22[v23].m_Previous = v24;
              p_m_Keys->m_Tail = v21;
              if ( (_WORD)v24 == 0xFFFF )
                p_m_Keys->m_Head = v21;
              else
                p_m_Keys->m_Memory.m_pMemory[v24].m_Next = v21;
              v25 = p_m_Keys->m_Memory.m_pMemory;
              ++p_m_Keys->m_ElementCount;
              v26 = &v25[v23] == nullptr;
              v27 = &v25[v23];
              v19 = (UtlLinkedListElem_t<CKeyValue *,int> *)curVal;
              v3 = pConnections;
              if ( !v26 )
                v27->m_Element = *(CKeyValue **)curVal;
            }
          }
        }
        v28 = CChunk::FindKey(this: pChunk, pKeyName: "spawnflags");
        v29 = v28;
        if ( v28 != nullptr )
        {
          sscanf(string: v28->m_pValue, format: "%lu", &curVal);
          if ( (curVal & 1) != 0 )
          {
            sprintf(string: str, format: "%lu", --curVal);
            free(pMem: v29->m_pValue);
            v30 = (char *)operator new(nSize: strlen(str) + 1);
            strcpy(v30, str);
            v29->m_pValue = v30;
          }
        }
        CUtlLinkedList<CKeyValue *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,int>,int>>::RemoveAll(this: &newKeys);
        if ( newKeys.m_Memory.m_nGrowSize >= 0 && newKeys.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: newKeys.m_Memory.m_pMemory);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406350
// Name: void SetPointLightFalloff(class CChunk __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPointLightFalloff(int pChunk)
{
  CChunk *v1; // edi
  CKeyValue *Key; // eax
  CKeyValue *v3; // eax
  CChunk *v4; // esi
  CChunk *v5; // eax
  CChunk *v6; // esi
  CChunk *v7; // eax
  CKeyValue *v8; // eax
  CKeyValue *v9; // esi
  char str[256]; // [esp+14h] [ebp-10Ch] BYREF
  int r; // [esp+114h] [ebp-Ch] BYREF
  int g; // [esp+118h] [ebp-8h] BYREF
  int b; // [esp+11Ch] [ebp-4h] BYREF

  v1 = (CChunk *)pChunk;
  if ( _V_stricmp(s1: *(const char **)(pChunk + 4), s2: "entity") == 0 )
  {
    Key = CChunk::FindKey(this: v1, pKeyName: "classname");
    if ( Key != nullptr && _V_stricmp(s1: Key->m_pValue, s2: "light") == 0 )
    {
      v3 = CChunk::FindKey(this: v1, pKeyName: "_distance");
      if ( v3 != nullptr )
      {
        *(float *)&b = atof(nptr: v3->m_pValue);
        v4 = (CChunk *)CChunk::FindKey(this: v1, pKeyName: "_zero_percent_distance");
        if ( v4 == nullptr )
        {
          v5 = (CChunk *)operator new(nSize: 0xCu);
          if ( v5 != nullptr )
          {
            v5->m_Keys.m_Memory.m_pMemory = nullptr;
            v5->m_pChunkName = nullptr;
            v4 = v5;
          }
          else
          {
            v4 = nullptr;
          }
          pChunk = (int)v4;
          CKeyValue::SetKey(this: (CKeyValue *)v4, pStr: "_zero_percent_distance");
          CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AddToTail(
            this: &v1->m_Keys,
            src: (CKeyValue **)&pChunk);
        }
        V_snprintf(pDest: str, maxLen: 256, pFormat: "%f", *(float *)&b);
        CKeyValue::SetValue(this: (CKeyValue *)v4, pStr: str);
        v6 = (CChunk *)CChunk::FindKey(this: v1, pKeyName: "_fifty_percent_distance");
        if ( v6 == nullptr )
        {
          v7 = (CChunk *)operator new(nSize: 0xCu);
          if ( v7 != nullptr )
          {
            v7->m_Keys.m_Memory.m_pMemory = nullptr;
            v7->m_pChunkName = nullptr;
            v6 = v7;
          }
          else
          {
            v6 = nullptr;
          }
          pChunk = (int)v6;
          CKeyValue::SetKey(this: (CKeyValue *)v6, pStr: "_fifty_percent_distance");
          CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AddToTail(
            this: &v1->m_Keys,
            src: (CKeyValue **)&pChunk);
        }
        V_snprintf(pDest: str, maxLen: 256, pFormat: "%f", (float)(*(float *)&b * 0.89999998));
        CKeyValue::SetValue(this: (CKeyValue *)v6, pStr: str);
        v8 = CChunk::FindKey(this: v1, pKeyName: "_light");
        v9 = v8;
        if ( v8 != nullptr && sscanf(string: v8->m_pValue, format: "%i %i %i %i", &r, &g, &b, &pChunk) == 4 )
        {
          pChunk = (int)(float)((float)pChunk * 2.0);
          V_snprintf(pDest: str, maxLen: 256, pFormat: "%d %d %d %d", r, g, b, pChunk);
          CKeyValue::SetValue(this: v9, pStr: str);
        }
        ++g_nLightsProcessed;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406560
// Name: void ReplaceSpeedrunTimes(class CChunk __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReplaceSpeedrunTimes(CKeyValue *pChunk)
{
  CChunk *v1; // edi
  CKeyValue *Key; // eax
  CChunk *v3; // esi
  CChunk *v4; // eax
  CChunk *v5; // esi
  CChunk *v6; // eax
  char str[256]; // [esp+4h] [ebp-100h] BYREF

  v1 = (CChunk *)pChunk;
  if ( _V_stricmp(s1: pChunk->m_pKey, s2: "entity") == 0 )
  {
    Key = CChunk::FindKey(this: v1, pKeyName: "classname");
    if ( Key != nullptr && _V_stricmp(s1: Key->m_pValue, s2: "asw_gamerules") == 0 )
    {
      v3 = (CChunk *)CChunk::FindKey(this: v1, pKeyName: "speedruntime");
      if ( v3 == nullptr )
      {
        v4 = (CChunk *)operator new(nSize: 0xCu);
        if ( v4 != nullptr )
        {
          v4->m_Keys.m_Memory.m_pMemory = nullptr;
          v4->m_pChunkName = nullptr;
          v3 = v4;
        }
        else
        {
          v3 = nullptr;
        }
        pChunk = (CKeyValue *)v3;
        CKeyValue::SetKey(this: (CKeyValue *)v3, pStr: "speedruntime");
        CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AddToTail(
          this: &v1->m_Keys,
          src: &pChunk);
        _Msg(a1: "Set speedruntime in asw_gamerules entity\n");
      }
      V_snprintf(pDest: str, maxLen: 256, pFormat: "%d", g_iSpeedrunTime);
      CKeyValue::SetValue(this: (CKeyValue *)v3, pStr: str);
      v5 = (CChunk *)CChunk::FindKey(this: v1, pKeyName: "speedruntimesp");
      if ( v5 == nullptr )
      {
        v6 = (CChunk *)operator new(nSize: 0xCu);
        if ( v6 != nullptr )
        {
          v6->m_Keys.m_Memory.m_pMemory = nullptr;
          v6->m_pChunkName = nullptr;
          v5 = v6;
        }
        else
        {
          v5 = nullptr;
        }
        pChunk = (CKeyValue *)v5;
        CKeyValue::SetKey(this: (CKeyValue *)v5, pStr: "speedruntimesp");
        CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AddToTail(
          this: &v1->m_Keys,
          src: &pChunk);
      }
      V_snprintf(pDest: str, maxLen: 256, pFormat: "%d", g_iSpeedrunTimeSingleplayer);
      CKeyValue::SetValue(this: (CKeyValue *)v5, pStr: str);
      _Msg(a1: "Set speedrun times in asw_gamerules entity.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004066D0
// Name: void AddSpeedrunTimes(class CChunk __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSpeedrunTimes(CChunk *pRoot)
{
  CChunk *v1; // eax
  CChunk *v2; // esi
  CKeyValue *v3; // eax
  CKeyValue *v4; // ebx
  CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short> > *p_m_Keys; // esi
  unsigned __int16 v6; // ax
  int v7; // edi
  UtlLinkedListElem_t<CKeyValue *,unsigned short> *v8; // eax
  CKeyValue *v9; // eax
  CKeyValue *v10; // ebx
  unsigned __int16 v11; // ax
  int v12; // edi
  UtlLinkedListElem_t<CKeyValue *,unsigned short> *v13; // eax
  CKeyValue *v14; // eax
  CKeyValue *v15; // ebx
  unsigned __int16 v16; // ax
  int v17; // edi
  UtlLinkedListElem_t<CKeyValue *,unsigned short> *v18; // eax
  CKeyValue *v19; // eax
  CKeyValue *v20; // ebx
  unsigned __int16 v21; // ax
  int v22; // edi
  UtlLinkedListElem_t<CKeyValue *,unsigned short> *v23; // eax
  unsigned __int16 v24; // ax
  int v25; // edi
  UtlLinkedListElem_t<CChunk *,unsigned short> *v26; // eax
  char str[256]; // [esp+8h] [ebp-104h] BYREF
  CChunk *pChunk; // [esp+108h] [ebp-4h]

  v1 = (CChunk *)operator new(nSize: 0x40u);
  if ( v1 != nullptr )
  {
    v2 = CChunk::CChunk(this: v1);
    pChunk = v2;
  }
  else
  {
    pChunk = nullptr;
    v2 = nullptr;
  }
  v2->m_pChunkName = "entity";
  v2->m_LoadOrder = g_CurLoadOrder++;
  v3 = (CKeyValue *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
  {
    v3->m_pValue = nullptr;
    v3->m_pKey = nullptr;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  CKeyValue::SetKey(this: v4, pStr: "classname");
  p_m_Keys = &v2->m_Keys;
  v6 = CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal(
         this: p_m_Keys,
         multilist: false);
  v7 = v6;
  if ( v6 != 0xFFFF )
  {
    CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> > *)p_m_Keys,
      before: 0xFFFFu,
      elem: v6);
    v8 = &p_m_Keys->m_Memory.m_pMemory[v7];
    if ( v8 != nullptr )
      v8->m_Element = v4;
  }
  CKeyValue::SetValue(this: v4, pStr: "asw_gamerules");
  v9 = (CKeyValue *)operator new(nSize: 0xCu);
  v10 = nullptr;
  if ( v9 != nullptr )
  {
    v9->m_pValue = nullptr;
    v9->m_pKey = nullptr;
    v10 = v9;
  }
  CKeyValue::SetKey(this: v10, pStr: "id");
  v11 = CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal(
          this: p_m_Keys,
          multilist: false);
  v12 = v11;
  if ( v11 != 0xFFFF )
  {
    CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> > *)p_m_Keys,
      before: 0xFFFFu,
      elem: v11);
    v13 = &p_m_Keys->m_Memory.m_pMemory[v12];
    if ( v13 != nullptr )
      v13->m_Element = v10;
  }
  V_snprintf(pDest: str, maxLen: 256, pFormat: "%d", g_iHighestEntityID);
  CKeyValue::SetValue(this: v10, pStr: str);
  v14 = (CKeyValue *)operator new(nSize: 0xCu);
  v15 = nullptr;
  if ( v14 != nullptr )
  {
    v14->m_pValue = nullptr;
    v14->m_pKey = nullptr;
    v15 = v14;
  }
  CKeyValue::SetKey(this: v15, pStr: "speedruntime");
  v16 = CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal(
          this: p_m_Keys,
          multilist: false);
  v17 = v16;
  if ( v16 != 0xFFFF )
  {
    CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> > *)p_m_Keys,
      before: 0xFFFFu,
      elem: v16);
    v18 = &p_m_Keys->m_Memory.m_pMemory[v17];
    if ( v18 != nullptr )
      v18->m_Element = v15;
  }
  V_snprintf(pDest: str, maxLen: 256, pFormat: "%d", g_iSpeedrunTime);
  CKeyValue::SetValue(this: v15, pStr: str);
  v19 = (CKeyValue *)operator new(nSize: 0xCu);
  v20 = nullptr;
  if ( v19 != nullptr )
  {
    v19->m_pValue = nullptr;
    v19->m_pKey = nullptr;
    v20 = v19;
  }
  CKeyValue::SetKey(this: v20, pStr: "speedruntimesp");
  v21 = CUtlLinkedList<CKeyValue *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CKeyValue *,unsigned short>,unsigned short>>::AllocInternal(
          this: p_m_Keys,
          multilist: false);
  v22 = v21;
  if ( v21 != 0xFFFF )
  {
    CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short> > *)p_m_Keys,
      before: 0xFFFFu,
      elem: v21);
    v23 = &p_m_Keys->m_Memory.m_pMemory[v22];
    if ( v23 != nullptr )
      v23->m_Element = v20;
  }
  V_snprintf(pDest: str, maxLen: 256, pFormat: "%d", g_iSpeedrunTimeSingleplayer);
  CKeyValue::SetValue(this: v20, pStr: str);
  v24 = CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::AllocInternal(
          this: &pRoot->m_Chunks,
          multilist: false);
  v25 = v24;
  if ( v24 != 0xFFFF )
  {
    CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::LinkBefore(
      this: &pRoot->m_Chunks,
      before: 0xFFFFu,
      elem: v24);
    v26 = &pRoot->m_Chunks.m_Memory.m_pMemory[v25];
    if ( v26 != nullptr )
      v26->m_Element = pChunk;
  }
  _Msg(a1: "Added asw_gamerules entity with speedrun times set.\n");
}

//------------------------------------------------------------------------------
// Address: 0x00406940
// Name: void ApplyInfestedTweaks(class CChunk __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyInfestedTweaks(CChunk *pRoot)
{
  g_bFoundSpeedrun = false;
  g_bFoundGameRules = false;
  g_iSpeedrunTime = 0;
  g_iSpeedrunTimeSingleplayer = 0;
  g_iHighestEntityID = 0;
  ScanChunks(pChunk: pRoot, fn: FindSpeedrunTimes);
  if ( g_bFoundSpeedrun )
  {
    if ( g_bFoundGameRules )
      ScanChunks(pChunk: pRoot, fn: (void (__cdecl *)(CChunk *))ReplaceSpeedrunTimes);
    else
      AddSpeedrunTimes(pRoot);
  }
  else
  {
    _Msg(a1: "Unable to find speedrun times in this vmf.\n");
  }
  ScanChunks(pChunk: pRoot, fn: (void (__cdecl *)(CChunk *))SetPointLightFalloff);
  _Msg(a1: "%s: %d lights processed.\n", g_pInFilename, g_nLightsProcessed);
  ScanChunks(pChunk: pRoot, fn: FixAINodes);
  _Msg(a1: "%s: %d info_nodes processed.\n", g_pInFilename, g_nNodesProcessed);
  _Msg(a1: "%s: %d info_node_links processed.\n", g_pInFilename, g_nNodeLinksProcessed);
}

//------------------------------------------------------------------------------
// Address: 0x00406A10
// Name: enum ChunkFileResult_t MyDefaultHandler(class CChunkFile __near *,void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl MyDefaultHandler(CChunkFile *pFile, void *pData, const char *pChunkName)
{
  CChunk *v3; // eax
  CChunk *v4; // esi
  CChunk *v5; // ebx
  unsigned __int16 v6; // ax
  int v7; // edi
  UtlLinkedListElem_t<CChunk *,unsigned short> *v8; // eax

  v3 = ParseChunk(pChunkName, bOnlyOne: true);
  v4 = g_pCurChunk;
  v5 = v3;
  v6 = CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::AllocInternal(
         this: &g_pCurChunk->m_Chunks,
         multilist: false);
  v7 = v6;
  if ( v6 != 0xFFFF )
  {
    CUtlLinkedList<CChunk *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CChunk *,unsigned short>,unsigned short>>::LinkBefore(
      this: &v4->m_Chunks,
      before: 0xFFFFu,
      elem: v6);
    v8 = &v4->m_Chunks.m_Memory.m_pMemory[v7];
    if ( v8 != nullptr )
      v8->m_Element = v5;
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00406A70
// Name: class CChunk __near * ReadChunkFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CChunk *__cdecl ReadChunkFile(const char *pInFilename)
{
  CChunk *v2; // esi
  CChunkFile chunkFile; // [esp+4h] [ebp-344h] BYREF

  CChunkFile::CChunkFile(this: &chunkFile);
  if ( CChunkFile::Open(this: &chunkFile, pszFileName: pInFilename, eMode: ChunkFile_Read) != 0 )
  {
    printf(format: "Error opening chunk file %s for reading.\n", pInFilename);
    CChunkFile::~CChunkFile(this: &chunkFile);
    return nullptr;
  }
  else
  {
    printf(format: "Reading..");
    CChunkFile::SetDefaultChunkHandler(this: &chunkFile, pHandler: MyDefaultHandler, pData: nullptr);
    g_pChunkFile = &chunkFile;
    v2 = ParseChunk(pChunkName: "***ROOT***", bOnlyOne: false);
    printf(format: "\n\n");
    CChunkFile::~CChunkFile(this: &chunkFile);
    return v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406B20
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  const char *v6; // eax
  CChunk *ChunkFile; // ebx
  char workingdir[256]; // [esp+8h] [ebp-100h] BYREF
  const char *pOutFilename; // [esp+110h] [ebp+8h]

  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  InitDefaultFileSystem();
  _LoggingSystem_SetLoggingResponsePolicy(a1: &s_NonFatalLoggingResponsePolicy);
  if ( argc >= 3 )
  {
    FileSystem_Init(
      pBSPFilename: argv[2],
      maxMemoryUsage: 0,
      initType: FS_INIT_COMPATIBILITY_MODE,
      bOnlyUseFilename: true);
    v6 = argv[2];
    g_pInFilename = v6;
    if ( argc < 4 )
      pOutFilename = setName;
    else
      pOutFilename = argv[3];
    ChunkFile = ReadChunkFile(pInFilename: v6);
    if ( ChunkFile != nullptr )
    {
      workingdir[0] = 0;
      Q_getwd(out: workingdir, outSize: 256);
      CmdLib_InitFileSystem(pFilename: workingdir, maxMemoryUsage: 0);
      if ( _V_stricmp(s1: argv[1], s2: "LogicAuto") != 0 )
      {
        if ( _V_stricmp(s1: argv[1], s2: "InfestedMaps") == 0 )
          ApplyInfestedTweaks(pRoot: ChunkFile);
      }
      else
      {
        ScanChunks(pChunk: ChunkFile, fn: LogicAuto);
        _Msg(a1: "%s: %d logic_auto replacements made.\n", g_pInFilename, g_nLogicAutoReplacementsMade);
      }
      FileSystem_Term();
      if ( argc < 4 || WriteChunkFile(pOutFilename, pRoot: ChunkFile) != 0 )
        return 0;
      else
        return 3;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    printf(format: "vmf_tweak <tweak mode> <input file> [output file]\n");
    printf(format: "   Tweak modes:\n");
    printf(format: "      LogicAuto - fixes logic autos\n");
    printf(format: "      InfestedMaps - fixes old AS:I maps (speedrun times, lights, info_nodes and info_node_links)\n");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408230
// Name: public: void CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
        CUtlMemory<KeyValues *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  KeyValues **m_pMemory; // edx
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
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
