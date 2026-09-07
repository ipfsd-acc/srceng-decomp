// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/keyvaluessystem.cpp
// Functions: 38
// ============================================================

#include "vstdlib\keyvaluessystem.h"

//------------------------------------------------------------------------------
// Address: 0x100010E0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CCoroutine,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CCoroutine,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CCoroutine,int> *m_pMemory; // edx
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
    v7 = 104 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CCoroutine,int> *)_g_pMemAlloc->Realloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: m_pMemory,
                                                                 a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CCoroutine,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001430
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *,int> > *this)
{
  bool v2; // sf
  CCoroutineMgr **m_pMemory; // eax

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
// Address: 0x10002030
// Name: public: static bool CDefOps<class ConVar __near *>::LessFunc(class ConVar __near * const __near &,class ConVar __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<ConVar *>::LessFunc(ConVar *const *lhs, ConVar *const *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x10002360
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class ConVar __near *,struct CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<ConVar *,CCvar::SplitScreenAddedConVars_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100024A0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class ConCommandBase __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<ConCommandBase *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<ConCommandBase *,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<ConCommandBase *,int> *)_g_pMemAlloc->Realloc_2(
                                                                   this: _g_pMemAlloc,
                                                                   a2: m_pMemory,
                                                                   a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<ConCommandBase *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003A40
// Name: public: bool CUtlVector<class IConsoleDisplayFunc __near *,class CUtlMemory<class IConsoleDisplayFunc __near *,int>>::FindAndRemove(class IConsoleDisplayFunc __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<IConsoleDisplayFunc *,CUtlMemory<IConsoleDisplayFunc *,int>>::FindAndRemove(
        CUtlVector<IConsoleDisplayFunc *,CUtlMemory<IConsoleDisplayFunc *,int> > *this,
        IConsoleDisplayFunc **src)
{
  int m_Size; // edx
  int v4; // eax
  IConsoleDisplayFunc **m_pMemory; // ebx
  IConsoleDisplayFunc **i; // ecx
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
// Address: 0x100041D0
// Name: public: int CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::InsertBefore(int,void (*const __near &)(class IConVar __near *,char const __near *,float))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::InsertBefore(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this,
        int elem,
        void (__cdecl **src)(IConVar *, const char *, float))
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // ecx
  int v7; // eax
  void (__cdecl **v8)(IConVar *, const char *, float); // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow((CUtlMemory<CCoroutineMgr *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100060C0
// Name: public: int CUtlVector<struct CCvar::QueuedConVarSet_t,class CUtlMemory<struct CCvar::QueuedConVarSet_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int>>::InsertBefore(
        CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CCvar::QueuedConVarSet_t *m_pMemory; // ecx
  int v6; // eax
  CCvar::QueuedConVarSet_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CCvar::QueuedConVarSet_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: &v7->m_String);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100063F0
// Name: public: void CUtlVector<struct CCvar::QueuedConVarSet_t,class CUtlMemory<struct CCvar::QueuedConVarSet_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int>>::RemoveAll(
        CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CCvar::QueuedConVarSet_t *v3; // esi
  CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int> > *v4; // [esp+4h] [ebp-4h]

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
      v3->m_String.m_Storage.m_nActualLength = 0;
      if ( v3->m_String.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_String.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_String.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_String.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_String.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006EB0
// Name: public: CUtlVector<struct CCvar::QueuedConVarSet_t,class CUtlMemory<struct CCvar::QueuedConVarSet_t,int>>::~CUtlVector<struct CCvar::QueuedConVarSet_t,class CUtlMemory<struct CCvar::QueuedConVarSet_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int>>::~CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int>>(
        CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int> > *this)
{
  bool v2; // sf
  CCvar::QueuedConVarSet_t *m_pMemory; // eax

  CUtlVector<CCvar::QueuedConVarSet_t,CUtlMemory<CCvar::QueuedConVarSet_t,int>>::RemoveAll(this);
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
// Address: 0x10008BE0
// Name: public: void CUtlMemory<class CJob __near *,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CJob *,int>::ConvertToGrowableMemory(CUtlMemory<CJob *,int> *this, int nGrowSize)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = nGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 4 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (CJob **)v5;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A1E0
// Name: public: void CUtlVector<class CJobThread __near *,class CUtlMemory<class CJobThread __near *,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CJobThread *,CUtlMemory<CJobThread *,int>>::EnsureCapacity(
        CUtlVector<CJobThread *,CUtlMemory<CJobThread *,int> > *this,
        int num)
{
  CJobThread **m_pMemory; // edx
  unsigned int v4; // eax
  CJobThread **v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 4 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CJobThread **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (CJobThread **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A240
// Name: public: int CUtlVector<class CJob __near *,class CUtlMemoryFixedGrowable<class CJob __near *,2048,int>>::InsertBefore(int,class CJob __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CJob *,CUtlMemoryFixedGrowable<CJob *,2048,int>>::InsertBefore(
        CUtlVector<CJob *,CUtlMemoryFixedGrowable<CJob *,2048,int> > *this,
        int elem,
        CJob **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v6; // edi
  CJob **m_pMemory; // ecx
  int v8; // eax
  CJob **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    v6 = m_Size - m_nAllocationCount + 1;
    if ( this->m_Memory.m_nGrowSize < 0 )
      CUtlMemory<CJob *,int>::ConvertToGrowableMemory(
        this: &this->m_Memory,
        nGrowSize: this->m_Memory.m_nMallocGrowSize);
    CUtlMemory<int,int>::Grow((CUtlMemory<CCoroutineMgr *,int> *)this, num: v6);
  }
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000A2D0
// Name: public: int CUtlVector<struct ThreadHandle_t__ __near *,class CUtlMemory<struct ThreadHandle_t__ __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ThreadHandle_t__ *,CUtlMemory<ThreadHandle_t__ *,int>>::InsertMultipleBefore(
        CUtlVector<ThreadHandle_t__ *,CUtlMemory<ThreadHandle_t__ *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ThreadHandle_t__ **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow((CUtlMemory<CCoroutineMgr *,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000A750
// Name: public: CUtlVector<class CJob __near *,class CUtlMemoryFixedGrowable<class CJob __near *,2048,int>>::~CUtlVector<class CJob __near *,class CUtlMemoryFixedGrowable<class CJob __near *,2048,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CJob *,CUtlMemoryFixedGrowable<CJob *,2048,int>>::~CUtlVector<CJob *,CUtlMemoryFixedGrowable<CJob *,2048,int>>(
        CUtlVector<CJob *,CUtlMemoryFixedGrowable<CJob *,2048,int> > *this)
{
  bool v2; // sf
  CJob **m_pMemory; // eax

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
// Address: 0x1000BC40
// Name: private: static bool CKeyValuesSystem::MemoryLeakTrackerLessFunc(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CKeyValuesSystem::MemoryLeakTrackerLessFunc(
        const CKeyValuesSystem::MemoryLeakTracker_t *lhs,
        const CKeyValuesSystem::MemoryLeakTracker_t *rhs)
{
  return lhs->pMem < rhs->pMem;
}

//------------------------------------------------------------------------------
// Address: 0x1000BC60
// Name: _KeyValuesSystem
// Source: json
//------------------------------------------------------------------------------
CKeyValuesSystem *__cdecl KeyValuesSystem()
{
  return &g_KeyValuesSystem;
}

//------------------------------------------------------------------------------
// Address: 0x1000BC70
// Name: public: virtual void CKeyValuesSystem::RegisterSizeofKeyValues(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyValuesSystem::RegisterSizeofKeyValues(CKeyValuesSystem *this, int size)
{
  if ( size > this->m_iMaxKeyValuesSize )
    this->m_iMaxKeyValuesSize = size;
}

//------------------------------------------------------------------------------
// Address: 0x1000BC90
// Name: public: virtual void __near * CKeyValuesSystem::AllocKeyValuesMemory(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CKeyValuesSystem::AllocKeyValuesMemory(CKeyValuesSystem *this, unsigned int size)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size);
}

//------------------------------------------------------------------------------
// Address: 0x1000BCB0
// Name: public: virtual void CKeyValuesSystem::FreeKeyValuesMemory(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyValuesSystem::FreeKeyValuesMemory(CKeyValuesSystem *this, void *pMem)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x1000BCD0
// Name: public: virtual char const __near * CKeyValuesSystem::GetStringForSymbol(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CKeyValuesSystem::GetStringForSymbol(CKeyValuesSystem *this, int symbol)
{
  if ( symbol == -1 )
    return str;
  else
    return (const char *)&this->m_Strings.m_pBase[symbol];
}

//------------------------------------------------------------------------------
// Address: 0x1000BCF0
// Name: public: virtual void CKeyValuesSystem::AddKeyValuesToMemoryLeakList(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyValuesSystem::AddKeyValuesToMemoryLeakList(CKeyValuesSystem *this, void *pMem, void *name)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD00
// Name: private: int CKeyValuesSystem::CaseInsensitiveHash(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CKeyValuesSystem::CaseInsensitiveHash(
        CKeyValuesSystem *this,
        const char *string,
        unsigned int iBounds)
{
  const char *v3; // edx
  char v4; // cl
  unsigned int i; // eax

  v3 = string;
  v4 = *string;
  for ( i = 0; v4 != 0; ++v3 )
  {
    if ( v4 < 65 || v4 > 90 )
      i = v4 + 2 * i;
    else
      i = v4 + 2 * i + 32;
    v4 = v3[1];
  }
  return i % iBounds;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD40
// Name: public: static bool CDefOps<int>::LessFunc(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<int>::LessFunc(const int *lhs, const int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD60
// Name: public: void CUtlMemory<struct CKeyValuesSystem::hash_item_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CKeyValuesSystem::hash_item_t,int>::Grow(
        CUtlMemory<CKeyValuesSystem::hash_item_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CKeyValuesSystem::hash_item_t *m_pMemory; // edx
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
      this->m_pMemory = (CKeyValuesSystem::hash_item_t *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v7);
    else
      this->m_pMemory = (CKeyValuesSystem::hash_item_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BE00
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BF10
// Name: public: virtual int CKeyValuesSystem::GetSymbolForString(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CKeyValuesSystem::GetSymbolForString(CKeyValuesSystem *this, const char *name, bool bCreate)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  CKeyValuesSystem::hash_item_t *v7; // esi
  CKeyValuesSystem::hash_item_t *next; // eax
  bool v9; // zf
  CKeyValuesSystem::hash_item_t *v10; // eax
  unsigned int v11; // eax
  unsigned int m_alignment; // edx
  unsigned int v13; // eax
  CMemoryStack *p_m_Strings; // ecx
  unsigned __int8 *m_pNextAlloc; // edi
  unsigned __int8 *v16; // eax
  int stringIndex; // esi
  unsigned __int8 *v18; // [esp+4h] [ebp-8h]
  int numStringBytes; // [esp+18h] [ebp+Ch]

  if ( name == nullptr )
    return -1;
  p_m_mutex = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  v7 = &this->m_HashTable.m_Memory.m_pMemory[CKeyValuesSystem::CaseInsensitiveHash(
                                               this,
                                               string: name,
                                               iBounds: this->m_HashTable.m_Size)];
  if ( _V_stricmp(s1: name, s2: (const char *)&this->m_Strings.m_pBase[v7->stringIndex]) == 0 )
  {
LABEL_10:
    result = v7->stringIndex;
    v9 = this->m_mutex.m_depth-- == 1;
    if ( !v9 )
      return result;
    goto LABEL_11;
  }
  while ( 1 )
  {
    next = v7->next;
    if ( next == nullptr )
      break;
    v7 = v7->next;
    if ( _V_stricmp(s1: name, s2: (const char *)&this->m_Strings.m_pBase[next->stringIndex]) == 0 )
      goto LABEL_10;
  }
  if ( !bCreate )
    goto LABEL_22;
  if ( v7->stringIndex != 0 )
  {
    v10 = (CKeyValuesSystem::hash_item_t *)CUtlMemoryPool::Alloc(this: &this->m_HashItemMemPool, amount: 8u);
    v7->next = v10;
    v7 = v10;
  }
  v7->next = nullptr;
  v11 = strlen(name);
  m_alignment = this->m_Strings.m_alignment;
  numStringBytes = v11;
  v13 = v11 + 4;
  p_m_Strings = &this->m_Strings;
  m_pNextAlloc = this->m_Strings.m_pNextAlloc;
  if ( v13 <= m_alignment )
    v13 = m_alignment;
  v16 = &m_pNextAlloc[~(m_alignment - 1) & (m_alignment + v13 - 1)];
  v18 = v16;
  if ( v16 <= p_m_Strings->m_pCommitLimit )
    goto LABEL_20;
  if ( CMemoryStack::CommitTo(this: p_m_Strings, pNextAlloc: v16) )
  {
    v16 = v18;
LABEL_20:
    this->m_Strings.m_pNextAlloc = v16;
    if ( m_pNextAlloc != nullptr )
    {
      v7->stringIndex = m_pNextAlloc - this->m_Strings.m_pBase;
      _V_memcpy(dest: m_pNextAlloc, src: name, count: numStringBytes);
      *(_DWORD *)&m_pNextAlloc[numStringBytes] = 0;
      stringIndex = v7->stringIndex;
      v9 = p_m_mutex->m_depth-- == 1;
      if ( v9 )
        _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
      return stringIndex;
    }
  }
  _Error(a1: "Out of keyvalue string space");
LABEL_22:
  result = -1;
  v9 = p_m_mutex->m_depth-- == 1;
  if ( v9 )
LABEL_11:
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C0A0
// Name: public: virtual int CKeyValuesSystem::GetSymbolForStringCaseSensitive(int __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CKeyValuesSystem::GetSymbolForStringCaseSensitive(
        CKeyValuesSystem *this,
        int *hCaseInsensitiveSymbol,
        const char *name,
        bool bCreate)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v8; // eax
  CKeyValuesSystem::hash_item_t *m_pMemory; // edx
  unsigned __int8 *v10; // esi
  int *p_stringIndex; // edi
  int v12; // eax
  bool v13; // cc
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned __int8 *v17; // ebx
  int v18; // esi
  char *v19; // ebx
  unsigned int v20; // esi
  int v21; // edi
  bool v22; // zf
  unsigned int m_alignment; // edx
  unsigned __int8 *m_pNextAlloc; // esi
  unsigned int v25; // ecx
  unsigned __int8 *v26; // ecx
  int *v27; // eax
  unsigned int v28; // eax
  unsigned __int8 *v29; // esi
  unsigned int v30; // edx
  unsigned int v31; // eax
  unsigned __int8 *v32; // eax
  unsigned __int8 *v34; // [esp+4h] [ebp-Ch]
  int numNameStringBytes; // [esp+8h] [ebp-8h]
  CThreadFastMutex *generated_id_16; // [esp+Ch] [ebp-4h]
  int *hCaseInsensitiveSymbola; // [esp+18h] [ebp+8h]
  int numStringBytes; // [esp+20h] [ebp+10h]
  int numStringBytesa; // [esp+20h] [ebp+10h]

  if ( name == nullptr )
    return -1;
  p_m_mutex = &this->m_mutex;
  generated_id_16 = &this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mutex.m_depth;
  }
  v8 = CKeyValuesSystem::CaseInsensitiveHash(this, string: name, iBounds: this->m_HashTable.m_Size);
  m_pMemory = this->m_HashTable.m_Memory.m_pMemory;
  v10 = &this->m_Strings.m_pBase[m_pMemory[v8].stringIndex];
  p_stringIndex = &m_pMemory[v8].stringIndex;
  v12 = _V_stricmp_NegativeForUnequal(s1: name, s2: (const char *)v10);
  v13 = v12 <= 0;
  if ( v12 == 0 )
  {
LABEL_11:
    *hCaseInsensitiveSymbol = *p_stringIndex;
LABEL_47:
    v21 = *p_stringIndex;
    v22 = generated_id_16->m_depth-- == 1;
    if ( v22 )
      _InterlockedExchange((volatile __int32 *)generated_id_16, 0);
    return v21;
  }
  while ( 1 )
  {
    if ( !v13 )
    {
      v16 = _V_strlen(str: (const char *)v10);
      v17 = &v10[v16];
      *hCaseInsensitiveSymbol = *p_stringIndex;
      v18 = *(_DWORD *)&v10[v16] >> 8;
      numNameStringBytes = v16;
      if ( v18 != 0 )
      {
        hCaseInsensitiveSymbola = (int *)this->m_Strings.m_pBase;
        while ( 1 )
        {
          v19 = (char *)hCaseInsensitiveSymbola + v18;
          if ( strcmp(name, (const char *)hCaseInsensitiveSymbola + v18) == 0 )
            break;
          v16 = numNameStringBytes;
          v20 = *(_DWORD *)&v19[numNameStringBytes];
          v17 = (unsigned __int8 *)&v19[numNameStringBytes];
          v18 = v20 >> 8;
          if ( v18 == 0 )
            goto LABEL_16;
        }
        v22 = generated_id_16->m_depth-- == 1;
        if ( v22 )
          _InterlockedExchange((volatile __int32 *)generated_id_16, 0);
        return v18;
      }
LABEL_16:
      if ( !bCreate )
      {
        v21 = *p_stringIndex;
        v22 = generated_id_16->m_depth-- == 1;
        if ( !v22 )
          return v21;
        goto LABEL_18;
      }
      m_alignment = this->m_Strings.m_alignment;
      m_pNextAlloc = this->m_Strings.m_pNextAlloc;
      v25 = v16 + 4;
      if ( v16 + 4 <= m_alignment )
        v25 = this->m_Strings.m_alignment;
      v26 = &m_pNextAlloc[~(m_alignment - 1) & (m_alignment + v25 - 1)];
      numStringBytes = (int)v26;
      if ( v26 > this->m_Strings.m_pCommitLimit )
      {
        if ( !CMemoryStack::CommitTo(this: &this->m_Strings, pNextAlloc: v26) )
          goto LABEL_28;
        v16 = numNameStringBytes;
        v26 = (unsigned __int8 *)numStringBytes;
      }
      this->m_Strings.m_pNextAlloc = v26;
      if ( m_pNextAlloc != nullptr )
      {
        v21 = m_pNextAlloc - this->m_Strings.m_pBase;
        _V_memcpy(dest: m_pNextAlloc, src: name, count: v16);
        *(_DWORD *)&m_pNextAlloc[numNameStringBytes] = 0;
        *(_DWORD *)v17 = v21 << 8;
        v22 = generated_id_16->m_depth-- == 1;
        if ( !v22 )
          return v21;
LABEL_18:
        _InterlockedExchange((volatile __int32 *)generated_id_16, 0);
        return v21;
      }
LABEL_28:
      _Error(a1: "Out of keyvalue string space");
      v22 = generated_id_16->m_depth-- == 1;
      if ( v22 )
        _InterlockedExchange((volatile __int32 *)generated_id_16, 0);
      return -1;
    }
    v14 = (_DWORD *)p_stringIndex[1];
    if ( v14 == nullptr )
      break;
    p_stringIndex = (int *)p_stringIndex[1];
    v10 = &this->m_Strings.m_pBase[*v14];
    v15 = _V_stricmp_NegativeForUnequal(s1: name, s2: (const char *)v10);
    v13 = v15 <= 0;
    if ( v15 == 0 )
      goto LABEL_11;
  }
  if ( !bCreate )
    goto LABEL_43;
  if ( *p_stringIndex != 0 )
  {
    v27 = (int *)CUtlMemoryPool::Alloc(this: &this->m_HashItemMemPool, amount: 8u);
    p_stringIndex[1] = (int)v27;
    p_stringIndex = v27;
  }
  p_stringIndex[1] = 0;
  v28 = strlen(name);
  v29 = this->m_Strings.m_pNextAlloc;
  v30 = this->m_Strings.m_alignment;
  numStringBytesa = v28;
  v31 = v28 + 4;
  if ( v31 <= v30 )
    v31 = this->m_Strings.m_alignment;
  v32 = &v29[~(v30 - 1) & (v30 + v31 - 1)];
  v34 = v32;
  if ( v32 <= this->m_Strings.m_pCommitLimit )
  {
LABEL_41:
    this->m_Strings.m_pNextAlloc = v32;
    if ( v29 == nullptr )
      goto LABEL_42;
    *p_stringIndex = v29 - this->m_Strings.m_pBase;
    _V_memcpy(dest: v29, src: name, count: numStringBytesa);
    *(_DWORD *)&v29[numStringBytesa] = 0;
    *hCaseInsensitiveSymbol = *p_stringIndex;
    goto LABEL_47;
  }
  if ( CMemoryStack::CommitTo(this: &this->m_Strings, pNextAlloc: v32) )
  {
    v32 = v34;
    goto LABEL_41;
  }
LABEL_42:
  _Error(a1: "Out of keyvalue string space");
LABEL_43:
  v22 = generated_id_16->m_depth-- == 1;
  if ( v22 )
    _InterlockedExchange((volatile __int32 *)generated_id_16, 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D110
// Name: public: virtual bool CKeyValuesSystem::GetKeyValuesExpressionSymbol(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CKeyValuesSystem::GetKeyValuesExpressionSymbol(CKeyValuesSystem *this, const char *name)
{
  const char *v2; // edi
  bool result; // al
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // eax
  unsigned __int16 v7; // ax
  bool v8; // zf
  char *m_pszString; // eax
  CUtlMap<int,bool,unsigned short>::Node_t search; // [esp+8h] [ebp-14h] BYREF
  ConVarRef cvRef; // [esp+10h] [ebp-Ch] BYREF
  int hSym; // [esp+18h] [ebp-4h]

  v2 = name;
  if ( name == nullptr )
    return false;
  if ( *name == 36 )
    v2 = name + 1;
  hSym = this->GetSymbolForString(this, a2: v2, a3: false);
  if ( hSym != -1 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    search.key = hSym;
    v7 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_KvConditionalSymbolTable.m_Tree,
           &search);
    if ( v7 != 0xFFFF )
    {
      result = this->m_KvConditionalSymbolTable.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
      v8 = this->m_mutex.m_depth-- == 1;
      if ( v8 )
        _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
      return result;
    }
    v8 = this->m_mutex.m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
  if ( _V_stricmp(s1: v2, s2: "GAMECONSOLESPLITSCREEN") == 0 || _V_stricmp(s1: v2, s2: "GAMECONSOLEGUEST") == 0 )
    return false;
  if ( _V_stricmp(s1: v2, s2: "ENGLISH") != 0
    && _V_stricmp(s1: v2, s2: "JAPANESE") != 0
    && _V_stricmp(s1: v2, s2: "GERMAN") != 0
    && _V_stricmp(s1: v2, s2: "FRENCH") != 0
    && _V_stricmp(s1: v2, s2: "SPANISH") != 0
    && _V_stricmp(s1: v2, s2: "ITALIAN") != 0
    && _V_stricmp(s1: v2, s2: "KOREAN") != 0
    && _V_stricmp(s1: v2, s2: "TCHINESE") != 0
    && _V_stricmp(s1: v2, s2: "PORTUGUESE") != 0
    && _V_stricmp(s1: v2, s2: "SCHINESE") != 0
    && _V_stricmp(s1: v2, s2: "POLISH") != 0
    && _V_stricmp(s1: v2, s2: "RUSSIAN") != 0 )
  {
    if ( V_strnicmp(s1: v2, s2: "CVAR_", n: 5) == 0 )
    {
      ConVarRef::ConVarRef(this: &cvRef, pName: v2 + 5);
      if ( ConVarRef::IsValid(this: &cvRef) )
        return cvRef.m_pConVarState->m_Value.m_nValue != 0;
    }
    _Warning(a1: "KV Conditional: Unknown symbol %s\n", v2);
    return false;
  }
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    ConVarRef::ConVarRef(this: &cl_language, pName: "cl_language");
  }
  m_pszString = cl_language.m_pConVarState->m_Value.m_pszString;
  if ( m_pszString == nullptr || *m_pszString == 0 )
    m_pszString = "english";
  return _V_stricmp(s1: v2, s2: m_pszString) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D4F0
// Name: public: CKeyValuesSystem::CKeyValuesSystem(void)
// Source: json
//------------------------------------------------------------------------------
CKeyValuesSystem *__thiscall CKeyValuesSystem::CKeyValuesSystem(CKeyValuesSystem *this)
{
  UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int m_Size; // ecx
  int m_nAllocationCount; // edx
  CKeyValuesSystem::hash_item_t *v5; // edx
  int v6; // eax
  int i; // eax
  unsigned int m_alignment; // ecx
  unsigned int v9; // eax
  int v10; // eax
  unsigned __int8 *m_pNextAlloc; // ecx
  unsigned __int8 *v12; // eax
  int v14; // [esp+Ch] [ebp-8h]
  unsigned __int8 *v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]
  unsigned __int8 *v17; // [esp+10h] [ebp-4h]

  this->__vftable = (CKeyValuesSystem_vtbl *)&CKeyValuesSystem::`vftable';
  CMemoryStack::CMemoryStack(this: &this->m_Strings);
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_HashItemMemPool,
    blockSize: 8,
    numElements: 64,
    growMode: 1,
    pszAllocOwner: "CKeyValuesSystem::m_HashItemMemPool",
    nAlignment: 0);
  this->m_HashTable.m_Memory.m_pMemory = nullptr;
  this->m_HashTable.m_Memory.m_nAllocationCount = 0;
  this->m_HashTable.m_Memory.m_nGrowSize = 0;
  this->m_HashTable.m_Size = 0;
  this->m_HashTable.m_pElements = nullptr;
  this->m_KeyValuesTrackingList.m_LessFunc = (bool (__cdecl *)(const CKeyValuesSystem::MemoryLeakTracker_t *, const CKeyValuesSystem::MemoryLeakTracker_t *))CKeyValuesSystem::MemoryLeakTrackerLessFunc;
  this->m_KeyValuesTrackingList.m_Elements.m_pMemory = nullptr;
  this->m_KeyValuesTrackingList.m_Elements.m_nAllocationCount = 0;
  this->m_KeyValuesTrackingList.m_Elements.m_nGrowSize = 0;
  this->m_KeyValuesTrackingList.m_NumElements = 0;
  this->m_KeyValuesTrackingList.m_Root = -1;
  this->m_KeyValuesTrackingList.m_FirstFree = -1;
  this->m_KeyValuesTrackingList.m_LastAlloc.index = -1;
  this->m_KeyValuesTrackingList.m_pElements = this->m_KeyValuesTrackingList.m_Elements.m_pMemory;
  this->m_KvConditionalSymbolTable.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<int>::LessFunc;
  this->m_KvConditionalSymbolTable.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_KvConditionalSymbolTable.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_KvConditionalSymbolTable.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_KvConditionalSymbolTable.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_KvConditionalSymbolTable.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_KvConditionalSymbolTable.m_Tree.m_FirstFree = -1;
  this->m_KvConditionalSymbolTable.m_Tree.m_pElements = m_pMemory;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  m_Size = this->m_HashTable.m_Size;
  m_nAllocationCount = this->m_HashTable.m_Memory.m_nAllocationCount;
  v16 = m_Size;
  v14 = m_Size + 2047;
  if ( m_Size + 2047 > m_nAllocationCount )
  {
    CUtlMemory<CKeyValuesSystem::hash_item_t,int>::Grow(
      this: &this->m_HashTable.m_Memory,
      num: m_Size - m_nAllocationCount + 2047);
    m_Size = v16;
  }
  this->m_HashTable.m_Size += 2047;
  v5 = this->m_HashTable.m_Memory.m_pMemory;
  v6 = this->m_HashTable.m_Size - m_Size - 2047;
  this->m_HashTable.m_pElements = v5;
  if ( v6 > 0 )
    _V_memmove(dest: &v5[v14], src: &v5[m_Size], count: 8 * v6);
  for ( i = 0; i < this->m_HashTable.m_Size; ++i )
  {
    this->m_HashTable.m_Memory.m_pMemory[i].stringIndex = 0;
    this->m_HashTable.m_Memory.m_pMemory[i].next = nullptr;
  }
  CMemoryStack::Init(
    this: &this->m_Strings,
    pszAllocOwner: "CKeyValuesSystem::m_Strings",
    maxSize: 0x400000u,
    commitSize: 0x10000u,
    initialCommit: 0,
    alignment: 4u);
  m_alignment = this->m_Strings.m_alignment;
  v9 = 1;
  if ( m_alignment != 0 )
    v9 = this->m_Strings.m_alignment;
  v10 = ~(m_alignment - 1) & (m_alignment + v9 - 1);
  m_pNextAlloc = this->m_Strings.m_pNextAlloc;
  v12 = &m_pNextAlloc[v10];
  v15 = m_pNextAlloc;
  v17 = v12;
  if ( v12 > this->m_Strings.m_pCommitLimit )
  {
    if ( !CMemoryStack::CommitTo(this: &this->m_Strings, pNextAlloc: v12) )
    {
      MEMORY[0] = 0;
      this->m_iMaxKeyValuesSize = 36;
      return this;
    }
    m_pNextAlloc = v15;
    v12 = v17;
  }
  this->m_Strings.m_pNextAlloc = v12;
  *m_pNextAlloc = 0;
  this->m_iMaxKeyValuesSize = 36;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000D6B0
// Name: public: virtual void CKeyValuesSystem::SetKeyValuesExpressionSymbol(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyValuesSystem::SetKeyValuesExpressionSymbol(CKeyValuesSystem *this, const char *name, bool bValue)
{
  const char *v3; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // eax
  unsigned __int16 v7; // ax
  CUtlMap<int,bool,unsigned short>::Node_t search; // [esp+4h] [ebp-10h] BYREF
  CUtlMap<int,bool,unsigned short>::Node_t insert; // [esp+Ch] [ebp-8h] BYREF
  int hSym; // [esp+1Ch] [ebp+8h]

  v3 = name;
  if ( name != nullptr )
  {
    if ( *name == 36 )
      v3 = name + 1;
    hSym = this->GetSymbolForString(this, a2: v3, a3: true);
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    search.key = hSym;
    v7 = CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_KvConditionalSymbolTable.m_Tree,
           &search);
    if ( v7 == 0xFFFF )
    {
      insert.key = hSym;
      insert.elem = bValue;
      CUtlRBTree<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short,CUtlMap<int,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        this: &this->m_KvConditionalSymbolTable.m_Tree,
        &insert);
    }
    else
    {
      this->m_KvConditionalSymbolTable.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem = bValue;
    }
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011200
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
// Address: 0x1000D770
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
// Address: 0x1000D7A0
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x1000D7C0
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
// Address: 0x1000D800
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x1000D820
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000D830
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

// ============================================================
// Overlay from vstdlib_s (Missing functions)
// ============================================================
namespace vstdlib_s {

//------------------------------------------------------------------------------
// Address: 0x3F607230
// Name: sub_3F607230
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall sub_3F607230(_DWORD *this, unsigned int a2)
{
  int result; // eax

  if ( a2 >= 0x7FFFFFFF )
    result = AssertMsgImplementation(
               a1: "Assertion Failed: size < INT_MAX",
               0,
               ".\\keyvaluessystem.cpp",
               189,
               &unk_3F665756,
               0);
  if ( a2 > *(this + 1) )
    *(this + 1) = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60FD70
// Name: private: static bool CKeyValuesSystem::MemoryLeakTrackerLessFunc(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F60FD90
// Name: _KeyValuesSystem
// Source: json
//------------------------------------------------------------------------------
void __thiscall KeyValuesSystem(void *_ECX)
{
  __asm { fsubr   dword ptr [ecx-17A9C09Bh] }
  JUMPOUT(0x3F60FD96);
}

//------------------------------------------------------------------------------
// Address: 0x3F60FDA0
// Name: public: CKeyValuesSystem::CKeyValuesSystem(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CKeyValuesSystem *__usercall CKeyValuesSystem::CKeyValuesSystem@<eax>(
        CKeyValuesSystem *this@<ecx>,
        _DWORD *a2@<eax>,
        char *a3@<edx>,
        char a4@<bl>,
        char *a5@<ebp>,
        const char *a6@<edi>,
        char *a7@<esi>,
        int a8,
        char *a9,
        int a10,
        int a11)
{
  const char *v11; // eax
  char v12; // cl
  const char *v13; // eax
  char v14; // cl
  char *v15; // eax
  size_t v17; // [esp-120h] [ebp-120h] BYREF
  char v18; // [esp-10Ah] [ebp-10Ah]
  char v19; // [esp-109h] [ebp-109h]
  char v20[260]; // [esp-104h] [ebp-104h] BYREF

  *a2 += a2;
  *((_BYTE *)a2 - 115) += (_BYTE)a3;
  strncpy_0(Destination: a3, Source: (const char *)&v17, Count: v17);
  v20[259] = a4;
  *a7 = a4;
  v19 = 1;
  v11 = a6;
  do
    v12 = *v11++;
  while ( v12 != a4 );
  if ( v11 != a6 + 1 && strstr_0(Str: a6, SubStr: "://") == nullptr )
    v18 = 1;
  if ( v19 == a4 )
  {
    v13 = a6;
    do
      v14 = *v13++;
    while ( v14 != a4 );
    if ( v13 != a6 + 1 )
    {
      v15 = "&";
      if ( v18 == a4 )
        v15 = "?";
      Q_strcat(a1: (int)a6, Source: v15, a3: a11);
    }
  }
  Q_strcat(a1: (int)a6, Source: a5, a3: a11);
  Q_strcat(a1: (int)a6, Source: "=", a3: a11);
  Q_strcat(a1: (int)a6, Source: a9, a3: a11);
  return (CKeyValuesSystem *)Q_strcat(a1: (int)a6, Source: v20, a3: a11);
}

//------------------------------------------------------------------------------
// Address: 0x3F610020
// Name: public: IKeyValuesSystem::IKeyValuesSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IKeyValuesSystem::IKeyValuesSystem(IKeyValuesSystem *this)
{
  ++*((_DWORD *)this + 34865);
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  CKeyValuesSystem::~CKeyValuesSystem((CKeyValuesSystem *)this);
}

//------------------------------------------------------------------------------
// Address: 0x3F610030
// Name: public: CKeyValuesSystem::~CKeyValuesSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CKeyValuesSystem::~CKeyValuesSystem(CKeyValuesSystem *this@<ecx>, unsigned int a2@<esi>)
{
  if ( a2 >= 0x10 )
    AssertMsgImplementation(
      a1: "Assertion Failed: nValue >= 0 && nValue <= 15",
      0,
      ".\\strtools.cpp",
      3412,
      &unk_3F6657B2,
      0);
  switch ( (int)a2 % 16 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      return;
    default:
      AssertMsgImplementation(a1: "Assertion Failed: false", 0, ".\\strtools.cpp", 3451, &unk_3F6657B3, 0);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F610120
// Name: public: virtual void CKeyValuesSystem::RegisterSizeofKeyValues(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CKeyValuesSystem::RegisterSizeofKeyValues(CKeyValuesSystem *this@<ecx>, char a2@<al>)
{
  switch ( a2 )
  {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case 'E':
    case 'F':
      return;
    case '7':
      JUMPOUT(0x3F61015E);
    case '8':
      JUMPOUT(0x3F61015F);
    case '9':
      JUMPOUT(0x3F610165);
    case 'A':
      JUMPOUT(0x3F61016B);
    case 'B':
      JUMPOUT(0x3F610171);
    case 'C':
      JUMPOUT(0x3F610177);
    case 'D':
      JUMPOUT(0x3F61017D);
    default:
      JUMPOUT(0x3F61018F);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F610160
// Name: public: virtual void __near * CKeyValuesSystem::AllocKeyValuesMemory(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CKeyValuesSystem::AllocKeyValuesMemory(
        CKeyValuesSystem *this@<ecx>,
        _BYTE *a2@<eax>,
        unsigned int size)
{
  *a2 |= (unsigned __int8)a2;
  JUMPOUT(0x3F610162);
}

//------------------------------------------------------------------------------
// Address: 0x3F610190
// Name: public: virtual void CKeyValuesSystem::FreeKeyValuesMemory(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyValuesSystem::FreeKeyValuesMemory(CKeyValuesSystem *this, void *pMem)
{
  JUMPOUT(0x3F610194);
}

//------------------------------------------------------------------------------
// Address: 0x3F610370
// Name: public: virtual char const __near * CKeyValuesSystem::GetStringForSymbol(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CKeyValuesSystem *__usercall CKeyValuesSystem::GetStringForSymbol@<eax>(
        CKeyValuesSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>)
{
  int v5; // edx
  char v6; // al
  char v7; // bl
  int v8; // ecx
  int v9; // eax
  void *v10; // eax
  char v11; // dl
  int v12; // ecx
  char v14; // [esp-1h] [ebp-1h]
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h]

  do
  {
    v5 = *(_DWORD *)(a3 + 12);
    if ( *(_BYTE *)(a3 + 20) != 0 && *(_BYTE *)(a5 + v5) == 43 )
    {
      *((_BYTE *)&this->__vftable + a4) = 32;
LABEL_12:
      this = (CKeyValuesSystem *)((char *)this + 1);
      goto LABEL_13;
    }
    v6 = *(_BYTE *)(a5 + v5);
    if ( v6 != 37 )
    {
      *((_BYTE *)&this->__vftable + a4) = v6;
      goto LABEL_12;
    }
    if ( a5 < a2 - 2 )
    {
      v7 = *(_BYTE *)(a5 + v5 + 1);
      v14 = *(_BYTE *)(a5 + v5 + 2);
      CKeyValuesSystem::RegisterSizeofKeyValues(this, a2: v7);
      if ( v9 != -1 )
      {
        CKeyValuesSystem::RegisterSizeofKeyValues(this: (CKeyValuesSystem *)v8, a2: v14);
        retaddr = v10;
        if ( v10 != (void *)-1 )
        {
          a2 = *(_DWORD *)(a3 + 16);
          *(_BYTE *)(v8 + a4) = (_BYTE)v10 + 16 * v11;
          this = (CKeyValuesSystem *)(v8 + 1);
          a5 += 2;
          goto LABEL_13;
        }
      }
      *(_BYTE *)(v8 + a4) = 37;
      v12 = v8 + 1;
      *(_BYTE *)(v12 + a4) = v7;
      a2 = *(_DWORD *)(a3 + 16);
      *(_BYTE *)(++v12 + a4) = v14;
      this = (CKeyValuesSystem *)(v12 + 1);
    }
    a5 += 2;
LABEL_13:
    ++a5;
  }
  while ( a5 < a2 );
  if ( (int)this < *(_DWORD *)(a3 + 8) )
    *((_BYTE *)&this->__vftable + a4) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F610430
// Name: public: virtual void CKeyValuesSystem::AddKeyValuesToMemoryLeakList(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyValuesSystem::AddKeyValuesToMemoryLeakList(CKeyValuesSystem *this, void *pMem, int name)
{
  JUMPOUT(0x3F610434);
}

//------------------------------------------------------------------------------
// Address: 0x3F610450
// Name: private: int CKeyValuesSystem::CaseInsensitiveHash(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CKeyValuesSystem::CaseInsensitiveHash(
        const char *string@<edx>,
        int _EAX@<eax>,
        int a3@<ecx>,
        void (__fastcall *a4)(int, const char *)@<ebx>,
        int a5@<ebp>,
        _BYTE *a6@<edi>,
        CKeyValuesSystem *this,
        int iBounds)
{
  *a6 = _EAX;
  __asm { aas }
  a4(a1: a3, a2: string);
  if ( *(_DWORD *)(*(_DWORD *)(a5 + 16) + 24) != 0 )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))a4)(
      a1: "Assertion Failed: parms.Count() == 0",
      a2: 0,
      a3: ".\\strtools.cpp",
      a4: 3654,
      a5: &unk_3F6657B7,
      a6: 0);
  JUMPOUT(0x3F610486);
}

//------------------------------------------------------------------------------
// Address: 0x3F610490
// Name: public: void CKeyValuesSystem::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CKeyValuesSystem::Validate(
        CValidator *validator@<esi>,
        int a2@<ebp>,
        int _EDI@<edi>,
        CKeyValuesSystem *this)
{
  *(_BYTE *)(a2 + 9) = 0;
  __asm { rcr     byte ptr [edi+5Eh], 5Bh }
}

//------------------------------------------------------------------------------
// Address: 0x3F6107D0
// Name: void ValidateKeyValuesGlobal(class CValidator __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F610B00
// Name: public: CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>(int,int,bool (*const __near &)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &))
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *__usercall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>@<eax>(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this@<esi>,
        int a2@<edi>)
{
  AssertMsgImplementation(a1: "Assertion Failed: IsValidIndex(i)");
  return (CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *)(*(_DWORD *)(a2 + 4) + 4 * (_DWORD)this);
}

//------------------------------------------------------------------------------
// Address: 0x3F610B50
// Name: public: CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::~CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F610B90
// Name: public: int CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void *__userpurge CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::FirstInorder@<eax>(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *thisb)
{
  const CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *thisa; // [esp+4h] [ebp+4h]

  thisa = *(const CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> **)(a4 + 4);
  if ( !sub_3F614FF0(a1: a2 + 1, a2: a4) )
    AssertMsgImplementation(
      a1: "Assertion Failed: IsValidIndex(i)",
      0,
      "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
      306,
      &unk_3F6657C3,
      0);
  return memcpy_0(a1: (void *)(*(_DWORD *)(a4 + 4) + 4 * (a2 + 1)), Src: &thisa->m_LessFunc + a2, Size: 4 * a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F610CB0
// Name: public: int CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __usercall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::NextInorder@<eax>(
        int i@<eax>,
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this)
{
  return *(_DWORD *)&output_0[6][4 * (i % 32)];
}

//------------------------------------------------------------------------------
// Address: 0x3F610FA0
// Name: public: void CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Validate(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this@<eax>,
        CValidator *validator@<esi>,
        int a3@<ebx>,
        const char **a4@<edi>,
        char *pchName)
{
  bool v5; // cf
  CValObject *v7; // eax
  const char *v8; // ecx

  _enable();
  v5 = __CFADD__(validator, *(const char **)((char *)a4 + 2 * a3 - 95));
  *(const char **)((char *)a4 + 2 * a3 - 95) = &(*(const char **)((char *)a4 + 2 * a3 - 95))[(_DWORD)validator];
  *(_BYTE *)(a3 + 101) += (_BYTE)this + v5;
  __asm { aas }
  v7 = (CValObject *)(*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)*_EAX + 8))(a1: *_EAX, a2: 4 * a3);
  v8 = *a4;
  validator->m_pValObjects = v7;
  v7->m_pchType = v8;
}

//------------------------------------------------------------------------------
// Address: 0x3F611030
// Name: protected: void CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::ResetDbgInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::ResetDbgInfo(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this@<ecx>,
        const char *a2@<eax>,
        CValidator *a3@<edi>,
        int a4@<esi>)
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  CValidator::Push(this: a3, a2: "CVariableBitStringBase", a3: (void *)a4, a4: a2);
  if ( *(int *)(a4 + 4) > 1 )
    CValidator::ClaimMemory(this: a3, a2: *(void **)(a4 + 12));
  JUMPOUT(0x3F611063);
}

//------------------------------------------------------------------------------
// Address: 0x3F611390
// Name: public: CUtlMemory<char>::CUtlMemory<char>(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlMemory<char>::CUtlMemory<char>(
        CUtlMemory<char> *this@<ecx>,
        bool a2@<zf>,
        char a3@<sf>,
        char a4@<of>,
        unsigned __int8 a5@<al>,
        unsigned __int16 a6@<dx>,
        _DWORD *a7@<ebx>,
        int nGrowSize,
        int nInitAllocationCount)
{
  while ( !(a3 ^ a4 | a2) )
  {
    a4 = 0;
    a2 = (*a7 & 0x7F8FB8F0) == 0;
    a3 = 0;
  }
  __outbyte(a6, a5);
  JUMPOUT(0x3F6113C8);
}

//------------------------------------------------------------------------------
// Address: 0x3F6113D0
// Name: public: void CUtlMemory<char>::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CUtlMemory<char>::Validate(
        CUtlMemory<char> *this@<edi>,
        unsigned int validator@<esi>,
        int a3@<edx>,
        int a4@<ecx>,
        char *pchName)
{
  int v5; // ecx

  v5 = 65521 * (((a3 - a4) >> 15) + ((unsigned int)(a3 - a4) >> 31)) + a4;
  *(_DWORD *)pchName = validator | ((v5 + (v5 < 0 ? 0xFFF1 : 0)) << 16);
}

//------------------------------------------------------------------------------
// Address: 0x3F6115B0
// Name: public: void CUtlMemory<struct CKeyValuesSystem::hash_item_t>::Validate(class CValidator __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CUtlMemory<CKeyValuesSystem::hash_item_t>::Validate(
        CUtlMemory<CKeyValuesSystem::hash_item_t> *this@<edi>,
        CValidator *validator@<esi>,
        _WORD *_EBX@<ebx>,
        char *pchName)
{
  __asm { fiadd   word ptr [ebx] }
  *_EBX = __CS__;
  __asm { bound   esp, ds:0C1C1F61Eh }
  JUMPOUT(0x3F6115DF);
}

//------------------------------------------------------------------------------
// Address: 0x3F6115E0
// Name: public: struct CKeyValuesSystem::MemoryLeakTracker_t __near & CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CKeyValuesSystem::MemoryLeakTracker_t *__usercall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::operator[]@<eax>(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this@<eax>,
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *a2@<ecx>)
{
  int v4; // [esp-4h] [ebp-4h]

  return (CKeyValuesSystem::MemoryLeakTracker_t *)CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Parent(
                                                    this: a2,
                                                    i: (int)a2 + __ROL4__(v4, 14));
}

//------------------------------------------------------------------------------
// Address: 0x3F6115F0
// Name: public: int CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
void CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Parent()
{
  JUMPOUT(0x3F6115FF);
}

//------------------------------------------------------------------------------
// Address: 0x3F611600
// Name: public: int CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::LeftChild(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this@<edx>,
        int i@<esi>)
{
  __asm { iret }
  JUMPOUT(0x3F611601);
}

//------------------------------------------------------------------------------
// Address: 0x3F611610
// Name: public: int CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::RightChild(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this@<edx>,
        char a2@<cf>,
        char a3@<ch>,
        _WORD *a4@<ebx>,
        _BYTE *a5@<edi>)
{
  *a4 = __CS__;
  *a5 += a3 + a2;
  JUMPOUT(0x3F611619);
}

//------------------------------------------------------------------------------
// Address: 0x3F611620
// Name: public: bool CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool __userpurge CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::IsRightChild@<al>(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this@<ebx>,
        int i@<edi>,
        char a3@<cl>,
        int a4@<ebp>,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  char v65; // [esp-4h] [ebp-4h]

  __asm
  {
    fidiv   word ptr [this]
    fild    word ptr [this]
  }
  *(_BYTE *)(a4 + 340988820) -= a3;
  return a3 + v65;
}

//------------------------------------------------------------------------------
// Address: 0x3F611640
// Name: public: bool CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
void __fastcall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::IsValidIndex(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *a1,
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this)
{
  CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::RemoveAll(this: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F611660
// Name: public: void CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::RemoveAll(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this)
{
  JUMPOUT(0x3F61180C);
}

//------------------------------------------------------------------------------
// Address: 0x3F611810
// Name: public: struct CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Node_t __near * CUtlMemory<struct CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Node_t>::Base(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Node_t>::Base(
        CUtlMemory<CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Node_t> *this)
{
  JUMPOUT(0x3F611838);
}

//------------------------------------------------------------------------------
// Address: 0x3F611A10
// Name: void CopyConstruct<char>(char __near *,char const __near &)
// Source: json
//------------------------------------------------------------------------------
void CopyConstruct<char>()
{
  JUMPOUT(0x3F611A19);
}

//------------------------------------------------------------------------------
// Address: 0x3F611C00
// Name: protected: void CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::SetLeftChild(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::SetLeftChild(
        int a1@<esi>,
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this,
        int child)
{
  if ( a1 > 32 )
    AssertMsgImplementation(
      a1: "Assertion Failed: hashlen <= 32",
      0,
      "..\\tier1\\checksum_md5.cpp",
      284,
      &unk_3F6657C9,
      0);
  ((void (__cdecl *)(CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *, int, void *, int))Q_binarytohex)(
    a1: this,
    a2: a1,
    a3: &unk_3F665CC0,
    a4: 64);
  JUMPOUT(0x3F611C40);
}

//------------------------------------------------------------------------------
// Address: 0x3F611C80
// Name: protected: struct CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Links_t const __near & CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Links(int)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Links_t *__usercall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Links@<eax>(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this@<edx>,
        int i@<esi>)
{
  int v3; // [esp-84h] [ebp-84h]
  const void *v4; // [esp-80h] [ebp-80h]
  unsigned int v5; // [esp-7Ch] [ebp-7Ch]
  int v6; // [esp-62h] [ebp-62h]
  _DWORD v7[22]; // [esp-58h] [ebp-58h] BYREF

  __asm { int     0EFh; compiled BASIC - ORIGINAL INT 09 VECTOR }
  v7[2] = -1732584194;
  v7[3] = 271733878;
  v7[4] = i;
  v7[5] = i;
  sub_3F611AB0(a1: v3, a2: v4, a3: v5);
  sub_3F611B70(a1: (int)v7);
  return (const CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Links_t *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x3F611D00
// Name: public: struct CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Node_t __near & CUtlMemory<struct CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Node_t>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Node_t *__userpurge CUtlMemory<CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Node_t>::operator[]@<eax>(
        CUtlMemory<CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Node_t> *this@<esi>,
        _DWORD *a2@<ecx>,
        char a3)
{
  *a2 = &CSHA1::`vftable';
  if ( (a3 & 1) != 0 )
    (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2, a3: 1);
  return (CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Node_t *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F611D60
// Name: public: void CUtlMemory<char>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlMemory<char>::Grow(CUtlMemory<char> *this@<esi>, char num@<al>, char a3@<cf>, int a4@<ecx>)
{
  int v4; // ecx

  v4 = a4 - 1;
  if ( a3 + num == 16 && v4 != 0 )
    JUMPOUT(0x3F611D36);
}

//------------------------------------------------------------------------------
// Address: 0x3F611E20
// Name: public: void CUtlMemory<struct CKeyValuesSystem::hash_item_t>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CUtlMemory<CKeyValuesSystem::hash_item_t>::Grow(
        CUtlMemory<CKeyValuesSystem::hash_item_t> *this@<esi>,
        char num@<al>,
        bool a3@<cf>,
        int a4@<edx>,
        int a5@<ecx>)
{
  int v5; // [esp-4h] [ebp-4h]
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  MEMORY[0x7D03FB03] = 610044676;
  LOBYTE(a5) = a5 + 1 - (a3 + num - 117);
  a3 = __CFADD__(*(_BYTE *)(v5 + 2040085436), (_BYTE)a5);
  LOBYTE(a5) = *(_BYTE *)(v5 + 2040085436) + a5;
  *(_BYTE *)(a4 - 117) -= a3 + 93;
  *(_BYTE *)(a5 - 1961089972) |= a5;
  MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)();
}

//------------------------------------------------------------------------------
// Address: 0x3F611EE0
// Name: protected: struct CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Links_t __near & CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Links(int)
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Links_t *__usercall CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Links@<eax>(
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Links_t *i@<eax>,
        CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)> *this)
{
  ++i->m_Left;
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x3F611F20
// Name: public: struct CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Node_t const __near & CUtlMemory<struct CUtlRBTree<struct CKeyValuesSystem::MemoryLeakTracker_t,int,bool (*)(struct CKeyValuesSystem::MemoryLeakTracker_t const __near &,struct CKeyValuesSystem::MemoryLeakTracker_t const __near &)>::Node_t>::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlMemory<CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl *)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Node_t>::operator[](
        CUtlMemory<CUtlRBTree<CKeyValuesSystem::MemoryLeakTracker_t,int,bool (__cdecl*)(CKeyValuesSystem::MemoryLeakTracker_t const &,CKeyValuesSystem::MemoryLeakTracker_t const &)>::Node_t> *this@<edi>,
        int a2@<ebx>,
        int a3@<ebp>)
{
  *(_DWORD *)(a3 + 20) = __ROL4__(a2, 8) & 0xFF00FF | __ROR4__(a2, 8) & 0xFF00FF00;
  JUMPOUT(0x3F611F56);
}

//------------------------------------------------------------------------------
// Address: 0x3F618520
// Name: public: int CUtlMemory<struct CKeyValuesSystem::hash_item_t>::NumAllocated(void)const
// Source: json
//------------------------------------------------------------------------------
void __usercall CUtlMemory<CKeyValuesSystem::hash_item_t>::NumAllocated(CUtlMemory<char> *this@<ecx>, _DWORD *a2@<eax>)
{
  *a2 += a2;
  JUMPOUT(0x3F618524);
}

//------------------------------------------------------------------------------
// Address: 0x3F607270
// Name: sub_3F607270
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F607270(CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > *a1, int a2, int a3)
{
  CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *>>::ShiftElementsLeft(
    elem: (int)a1,
    a2: a3 - 0x8000 < 0,
    a3: __OFSUB__(a3, 0x8000),
    a4: a1->m_Memory.m_nGrowSize & 0x7FFF,
    a5: a3,
    a6: (unsigned int)a1->m_Memory.m_nGrowSize >> 15,
    this: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F60FE70
// Name: Q_qsort_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void Q_qsort_s()
{
  JUMPOUT(0x3F62B550);
}

//------------------------------------------------------------------------------
// Address: 0x3F60FE80
// Name: Q_ExtractDomainFromURL
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl Q_ExtractDomainFromURL(char *a1, char *Str, size_t Count)
{
  char *v3; // eax
  const char *v4; // esi
  char *v5; // eax
  char v7[20]; // [esp+8h] [ebp-14h] BYREF

  *Str = 0;
  strcpy(v7, "steam://openurl/");
  if ( Q_strnicmp(a1, a2: v7, a3: 16) != 0 )
    Q_strncpy(Destination: Str, Source: a1, Count);
  else
    Q_strncpy(Destination: Str, Source: a1 + 16, Count);
  v3 = strstr_0(Str, SubStr: "//");
  v4 = v3;
  if ( v3 != nullptr )
    v5 = strstr_0(Str: v3 + 2, SubStr: "/");
  else
    v5 = strstr_0(Str, SubStr: "/");
  if ( v5 != nullptr )
    *v5 = 0;
  if ( v4 != nullptr )
    memcpy_0(a1: Str, Src: v4 + 2, Size: strlen(v4) - 1);
  return *Str != 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F60FF50
// Name: Q_URLContainsDomain
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl Q_URLContainsDomain(char *a1, const char *a2)
{
  signed int v2; // kr00_4
  signed int v3; // eax
  bool result; // al
  char Str[2048]; // [esp+4h] [ebp-800h] BYREF

  result = false;
  if ( Q_ExtractDomainFromURL(a1, Str, Count: 0x800u) )
  {
    v2 = strlen(Str);
    v3 = strlen(a2);
    if ( v2 >= v3 && Q_strnicmp(a1: &Str[v2 - v3], a2, a3: 0x7FFFFFFF) == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6101F0
// Name: sub_3F6101F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_3F6101F0(_BYTE *a1, int a2, int a3, int a4, char a5)
{
  int v5; // esi
  const char *v6; // eax
  CKeyValuesSystem *v7; // ecx
  int v8; // edi
  char v9; // al
  unsigned __int8 v10; // al
  int v11; // edi
  char v12; // al
  CKeyValuesSystem *v13; // ecx
  char v14; // al
  char v15; // [esp+Fh] [ebp-109h]
  CKeyValuesSystem *v16; // [esp+10h] [ebp-108h]
  unsigned int v17; // [esp+14h] [ebp-104h]

  v5 = a4;
  if ( a2 >= 3 * a4 )
  {
    v7 = nullptr;
    v8 = 0;
    v16 = nullptr;
    if ( a4 > 0 )
    {
      do
      {
        v9 = *((_BYTE *)&v7->__vftable + a3);
        if ( v9 >= 97 && v9 <= 122 || v9 >= 65 && v9 <= 90 || v9 >= 48 && v9 <= 57 || v9 == 45 || v9 == 95 || v9 == 46 )
        {
          a1[v8] = v9;
        }
        else if ( a5 != 0 && v9 == 32 )
        {
          a1[v8] = 43;
        }
        else
        {
          a1[v8] = 37;
          v10 = *((_BYTE *)&v7->__vftable + a3);
          v11 = v8 + 1;
          if ( v10 != 0 )
          {
            v17 = v10;
            CKeyValuesSystem::~CKeyValuesSystem(this: v7, a2: v10 & 0xF);
            v15 = v12;
            CKeyValuesSystem::~CKeyValuesSystem(this: v13, a2: v17 >> 4);
            v5 = a4;
            a1[v11] = v14;
            v8 = v11 + 1;
            a1[v8] = v15;
            v7 = v16;
          }
          else
          {
            a1[v11] = 48;
            v8 = v11 + 1;
            a1[v8] = 48;
          }
        }
        v7 = (CKeyValuesSystem *)((char *)v7 + 1);
        ++v8;
        v16 = v7;
      }
      while ( (int)v7 < v5 );
    }
    a1[v8] = 0;
  }
  else
  {
    *a1 = 0;
    v6 = (const char *)((int (*)(const char *, ...))loc_3F6027D0)(
                         a1: "Assertion Failed: %s",
                         "Target buffer for Q_URLEncode needs to be 3 times larger than source to gurantee enough space\n");
    AssertMsgImplementation(a1: v6, 0, ".\\strtools.cpp", 3512, &unk_3F6657B4, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F610310
// Name: sub_3F610310
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CKeyValuesSystem *__usercall sub_3F610310@<eax>(int a1@<edi>, int a2, int a3, int a4)
{
  const char *v4; // eax
  int savedregs; // [esp+110h] [ebp+0h] BYREF

  if ( a2 >= a4 )
  {
    if ( a4 <= 0 )
      JUMPOUT(0x3F610402);
    return CKeyValuesSystem::GetStringForSymbol(this: nullptr, a2: a4, a3: (int)&savedregs, a4: a1, a5: 0);
  }
  else
  {
    v4 = (const char *)((int (*)(const char *, ...))loc_3F6027D0)(
                         a1: "Assertion Failed: %s",
                         "Q_URLDecode needs a dest buffer at least as large as the source");
    AssertMsgImplementation(a1: v4, 0, ".\\strtools.cpp", 3568, &unk_3F6657B5, 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F610420
// Name: Q_URLCracker
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Q_URLCracker(CKeyValuesSystem *this, void *a2, int a3)
{
  CKeyValuesSystem::AddKeyValuesToMemoryLeakList(this, pMem: a2, name: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F610660
// Name: Q_URLEncode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl Q_URLEncode(_BYTE *a1, int a2, int a3, int a4)
{
  sub_3F6101F0(a1, a2, a3, a4, a5: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F610680
// Name: Q_URLDecode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CKeyValuesSystem *__cdecl Q_URLDecode(int a1, int a2, int a3, int a4)
{
  return sub_3F610310(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F6106A0
// Name: Q_URLEncodeRaw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl Q_URLEncodeRaw(_BYTE *a1, int a2, int a3, int a4)
{
  sub_3F6101F0(a1, a2, a3, a4, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F6106C0
// Name: Q_URLDecodeRaw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CKeyValuesSystem *__cdecl Q_URLDecodeRaw(int a1, int a2, int a3, int a4)
{
  return sub_3F610310(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F6106E0
// Name: Q_tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl Q_tolower(int a1)
{
  int result; // eax

  result = a1;
  if ( (unsigned int)(a1 - 65) <= 0x19 )
    return a1 + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6106F0
// Name: Q_toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl Q_toupper(int a1)
{
  int result; // eax

  result = a1;
  if ( (unsigned int)(a1 - 97) <= 0x19 )
    return a1 - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F610700
// Name: sub_3F610700
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_3F610700@<eax>(_DWORD *a1@<eax>, int a2@<ecx>, _DWORD *a3)
{
  int result; // eax
  int v6; // edx
  _DWORD v7[2]; // [esp+10h] [ebp-8h] BYREF

  v7[0] = *a1;
  result = ((int (__stdcall *)(_DWORD *))loc_3F610870)(a1: v7);
  if ( result == -1 )
  {
    v6 = *a1;
    v7[1] = *a3;
    v7[0] = v6;
    return ((int (*)(void))loc_3F610800)();
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)(a2 + 44) + 24 * result + 20) = *a3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F610760
// Name: sub_3F610760
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_3F610760(int a1)
{
  return ((int (*)(void))loc_3F610800)();
}

//------------------------------------------------------------------------------
// Address: 0x3F610790
// Name: sub_3F610790
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F610790@<eax>(_DWORD *a1@<eax>)
{
  _DWORD v2[3]; // [esp+0h] [ebp-Ch] BYREF

  v2[0] = *a1;
  return ((int (__stdcall *)(_DWORD *))loc_3F610870)(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x3F611D65
// Name: sub_3F611D65
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F611D65@<eax>(int result@<eax>, int a2@<ecx>)
{
  *(_DWORD *)(result + 24) = a2;
  *(_DWORD *)(result + 28) = a2;
  return result;
}

} // namespace vstdlib_s
