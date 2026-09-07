// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: filesystem/queuedloader.cpp
// Functions: 77
// ============================================================

#include "filesystem\queuedloader.h"

//------------------------------------------------------------------------------
// Address: 0x100032B0
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<class IFileSystem>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IFileSystem>::GetDependencies(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003520
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003840
// Name: public: virtual void CBaseAppSystem<class IFileSystem>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IFileSystem>::Reconnect(
        CBaseAppSystem<IFileSystem> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10008BA0
// Name: public: virtual void CTier2AppSystem<class IQueuedLoader,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IQueuedLoader,0>::Disconnect(CTier2AppSystem<IFileSystem,0> *this)
{
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x1000A760
// Name: public: void CUtlDict<class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::PurgeAndDeleteElements(
        CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int> *this)
{
  int i; // edi
  CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *elem; // esi
  bool v4; // sf
  CStoreIDEntry *m_pMemory; // eax

  for ( i = CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    elem = this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
    {
      v4 = elem->m_Memory.m_nGrowSize < 0;
      elem->m_Size = 0;
      if ( !v4 )
      {
        if ( elem->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_Memory.m_pMemory);
          elem->m_Memory.m_pMemory = nullptr;
        }
        elem->m_Memory.m_nAllocationCount = 0;
      }
      v4 = elem->m_Memory.m_nGrowSize < 0;
      m_pMemory = elem->m_Memory.m_pMemory;
      elem->m_pElements = elem->m_Memory.m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          elem->m_Memory.m_pMemory = nullptr;
        }
        elem->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: elem);
    }
  }
  CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1000B5A0
// Name: public: int CUtlMap<char const __near *,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::Insert(char const __near * const __near &,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Insert(
        CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int> *this,
        const char **key,
        int insert)
{
  CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NewNode(this: &this->m_Tree);
  CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000EB60
// Name: public: int CUtlDict<class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::Insert(char const __near *,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Insert(
        CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int> *this,
        char *pName,
        CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x10011D90
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x10011DA0
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014DA0
// Name: public: virtual void __near * CBaseAppSystem<class IQueuedLoader>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IQueuedLoader>::QueryInterface(CBaseFileSystem *this, bool *pbDLCSearchPathMounted)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015EA0
// Name: private: virtual void CResourcePreloadAnonymous::PrepareForCreate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadAnonymous::PrepareForCreate(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100175E0
// Name: public: virtual enum AppSystemTier_t CTier2AppSystem<class IQueuedLoader,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IQueuedLoader,0>::GetTier(CTier2AppSystem<IFileSystem,0> *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x100175F0
// Name: public: virtual void CTier2AppSystem<class IAsyncFileSystem,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IAsyncFileSystem,0>::Shutdown(CTier2AppSystem<IAsyncFileSystem,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x1001A800
// Name: public: void CUtlDict<class CPathIDFileList __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPathIDFileList *,int>::RemoveAll(CUtlDict<CPathIDFileList *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1001A930
// Name: public: void CUtlDict<class CFileInfo __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CFileInfo *,int>::PurgeAndDeleteElements(CUtlDict<CFileInfo *,int> *this)
{
  int i; // edi
  CFileInfo *elem; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    elem = this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
      free(pMem: elem);
  }
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1001ADB0
// Name: public: int CUtlMap<char const __near *,class CFileInfo __near *,int>::Insert(char const __near * const __near &,class CFileInfo __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CFileInfo *,int>::Insert(
        CUtlMap<char const *,CFileInfo *,int> *this,
        const char **key,
        int insert)
{
  CFileInfo *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CFileInfo *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CFileInfo **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001AE30
// Name: public: int CUtlMap<char const __near *,class CPathIDFileList __near *,int>::Insert(char const __near * const __near &,class CPathIDFileList __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CPathIDFileList *,int>::Insert(
        CUtlMap<char const *,CPathIDFileList *,int> *this,
        const char **key,
        int insert)
{
  CPathIDFileList *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CPathIDFileList *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CPathIDFileList **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001AEB0
// Name: public: int CUtlDict<class CFileInfo __near *,int>::Insert(char const __near *,class CFileInfo __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CFileInfo *,int>::Insert(
        CUtlDict<CFileInfo *,int> *this,
        char *pName,
        CFileInfo *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CFileInfo *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x1001AF10
// Name: public: int CUtlDict<class CPathIDFileList __near *,int>::Insert(char const __near *,class CPathIDFileList __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CPathIDFileList *,int>::Insert(
        CUtlDict<CPathIDFileList *,int> *this,
        char *pName,
        CPathIDFileList *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CPathIDFileList *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x1001AF70
// Name: public: void CUtlDict<class CPathIDFileList __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPathIDFileList *,int>::PurgeAndDeleteElements(CUtlDict<CPathIDFileList *,int> *this)
{
  CUtlDict<CPathIDFileList *,int> *v1; // edi
  int Inorder; // eax
  int v3; // esi
  CPathIDFileList *elem; // edi
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int> > *p_m_Tree; // esi
  int i; // edi
  CPathIDFileList *pMem; // [esp+4h] [ebp-Ch]
  int index; // [esp+Ch] [ebp-4h]

  v1 = this;
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
  index = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      v3 = Inorder;
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)v1->m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key);
      elem = v1->m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
      pMem = elem;
      if ( elem != nullptr )
      {
        p_m_Tree = &elem->m_Files.m_Elements.m_Tree;
        CUtlDict<CFileInfo *,int>::PurgeAndDeleteElements(this: &elem->m_Files);
        CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int>>::RemoveAll(this: &elem->m_UnverifiedCRCFiles);
        if ( elem->m_UnverifiedCRCFiles.m_Memory.m_nGrowSize >= 0 )
        {
          if ( elem->m_UnverifiedCRCFiles.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_UnverifiedCRCFiles.m_Memory.m_pMemory);
            elem->m_UnverifiedCRCFiles.m_Memory.m_pMemory = nullptr;
          }
          elem->m_UnverifiedCRCFiles.m_Memory.m_nAllocationCount = 0;
        }
        for ( i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &elem->m_Files.m_Elements.m_Tree);
              i != -1;
              i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
                    this: p_m_Tree,
                    i) )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_Tree->m_Elements.m_pMemory[i].m_Data.key);
        }
        CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
        CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
        p_m_Tree->m_FirstFree = -1;
        if ( p_m_Tree->m_Elements.m_nGrowSize >= 0 )
        {
          if ( p_m_Tree->m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Tree->m_Elements.m_pMemory);
            p_m_Tree->m_Elements.m_pMemory = nullptr;
          }
          p_m_Tree->m_Elements.m_nAllocationCount = 0;
        }
        p_m_Tree->m_LastAlloc.index = -1;
        if ( p_m_Tree->m_Elements.m_nGrowSize >= 0 )
        {
          if ( p_m_Tree->m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Tree->m_Elements.m_pMemory);
            p_m_Tree->m_Elements.m_pMemory = nullptr;
          }
          p_m_Tree->m_Elements.m_nAllocationCount = 0;
        }
        free(pMem);
      }
      v1 = this;
      index = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
                this: &this->m_Elements.m_Tree,
                i: index);
      if ( index == -1 )
        break;
      Inorder = index;
    }
  }
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::RemoveAll(this: &v1->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1001BC40
// Name: public: bool CQueuedLoader::CResourceNameLessFunc::Less(void __near * const __near &,void __near * const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQueuedLoader::CResourceNameLessFunc::Less(
        CQueuedLoader::CResourceNameLessFunc *this,
        void *const *hFilenameLHS,
        void *const *hFilenameRHS,
        void *pCtx)
{
  char v5; // bl
  char v6; // al
  char szNameLHS[260]; // [esp+0h] [ebp-208h] BYREF
  char szNameRHS[260]; // [esp+104h] [ebp-104h] BYREF

  if ( pCtx != (void *)2 )
    return *hFilenameLHS < *hFilenameRHS;
  hFilenameLHS = (void *const *)*hFilenameLHS;
  CUtlFilenameSymbolTable::String(
    this: &g_QueuedLoader.m_Filenames,
    handle: (void *const *)&hFilenameLHS,
    buf: szNameLHS,
    buflen: 260);
  hFilenameLHS = (void *const *)*hFilenameRHS;
  CUtlFilenameSymbolTable::String(
    this: &g_QueuedLoader.m_Filenames,
    handle: (void *const *)&hFilenameLHS,
    buf: szNameRHS,
    buflen: 260);
  v5 = V_stristr(pStr: szNameLHS, pSearch: "maps\\") != nullptr;
  v6 = V_stristr(pStr: szNameRHS, pSearch: "maps\\") != nullptr;
  if ( v5 == v6 )
    return _V_stricmp(s1: szNameLHS, s2: szNameRHS) < 0;
  return v5 == 1 && v6 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001BD20
// Name: public: virtual void CQueuedLoader::AddMapResource(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedLoader::AddMapResource(CQueuedLoader *this, const char *pFilename)
{
  char szFilename[260]; // [esp+4h] [ebp-104h] BYREF

  if ( pFilename != nullptr && *pFilename != 0 )
  {
    V_strncpy(pDest: szFilename, pSrc: pFilename, maxLen: 260);
    V_FixSlashes(pname: szFilename, separator: 92);
    _V_strlower(start: szFilename);
    if ( CUtlSymbolTable::Find(
           this: &this->m_AdditionalResources,
           result: (CUtlSymbol *)&pFilename + 1,
           pString: szFilename)->m_Id == 0xFFFF )
      CUtlSymbolTable::AddString(
        this: &this->m_AdditionalResources,
        result: (CUtlSymbol *)&pFilename + 1,
        pString: szFilename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BDB0
// Name: public: virtual void CQueuedLoader::InstallLoader(enum ResourcePreload_t,class IResourcePreload __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedLoader::InstallLoader(CQueuedLoader *this, ResourcePreload_t type, IResourcePreload *pLoader)
{
  this->m_pLoaders[type] = pLoader;
}

//------------------------------------------------------------------------------
// Address: 0x1001BDD0
// Name: public: virtual void CQueuedLoader::InstallProgress(class ILoaderProgress __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedLoader::InstallProgress(CQueuedLoader *this, ILoaderProgress *pProgress)
{
  this->m_pProgress = pProgress;
}

//------------------------------------------------------------------------------
// Address: 0x1001BDE0
// Name: public: virtual void CQueuedLoader::PurgeAll(enum ResourcePreload_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedLoader::PurgeAll(CQueuedLoader *this, ResourcePreload_t *pDontPurgeList, int nPurgeListSize)
{
  CQueuedLoader *v3; // ebx
  int v4; // edx
  int i; // eax
  ResourcePreload_t v6; // ecx
  int v7; // esi
  int j; // edi
  ResourcePreload_t v9; // eax
  ResourcePreload_t purgeOrder[8]; // [esp+Ch] [ebp-24h]
  CQueuedLoader *v11; // [esp+2Ch] [ebp-4h]

  v3 = this;
  v4 = -1;
  v11 = this;
  if ( pDontPurgeList != nullptr && nPurgeListSize > 0 )
  {
    for ( i = 0; i < nPurgeListSize; ++i )
    {
      v6 = pDontPurgeList[i];
      v4 &= ~(1 << v6);
    }
    v3 = v11;
  }
  v7 = 0;
  if ( (v4 & 2) != 0 )
  {
    v7 = 1;
    purgeOrder[0] = RESOURCEPRELOAD_SOUND;
  }
  if ( (v4 & 0x20) != 0 )
    purgeOrder[v7++] = RESOURCEPRELOAD_STATICPROPLIGHTING;
  if ( (v4 & 8) != 0 )
    purgeOrder[v7++] = RESOURCEPRELOAD_MODEL;
  if ( (v4 & 0x10) != 0 )
    purgeOrder[v7++] = RESOURCEPRELOAD_CUBEMAP;
  if ( (v4 & 4) != 0 )
    purgeOrder[v7++] = RESOURCEPRELOAD_MATERIAL;
  if ( (v4 & 0x40) != 0 )
    purgeOrder[v7++] = RESOURCEPRELOAD_GPUBUFFERALLOCATOR;
  for ( j = 0; j < v7; ++j )
  {
    v9 = purgeOrder[j];
    if ( v3->m_pLoaders[v9] != nullptr )
      v3->m_pLoaders[v9]->PurgeAll(this: v3->m_pLoaders[v9]);
  }
  v3->m_szMapNameToCompareSame[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001BEB0
// Name: public: virtual bool CQueuedLoader::IsMapLoading(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQueuedLoader::IsMapLoading(CQueuedLoader *this)
{
  return this->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x1001BEC0
// Name: public: virtual bool CQueuedLoader::IsSameMapLoading(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CQueuedLoader::IsSameMapLoading(CQueuedLoader *this)
{
  return this->m_bActive && this->m_bSameMap;
}

//------------------------------------------------------------------------------
// Address: 0x1001BEE0
// Name: public: virtual bool CQueuedLoader::IsBatching(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQueuedLoader::IsBatching(CQueuedLoader *this)
{
  return this->m_bBatching;
}

//------------------------------------------------------------------------------
// Address: 0x1001BEF0
// Name: public: virtual int CQueuedLoader::GetSpewDetail(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CQueuedLoader::GetSpewDetail(CQueuedLoader *this)
{
  int result; // eax

  if ( loader_spew_info.m_pParent == nullptr )
    return 0;
  result = loader_spew_info.m_pParent->m_Value.m_nValue;
  if ( result > 0 )
    return 1 << (result - 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001BF10
// Name: private: virtual void CDummyProgress::UpdateProgress(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyProgress::UpdateProgress(CDummyProgress *this, float progress, bool bForce)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1001BF20
// Name: void AdjustAsyncIOSpeed(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AdjustAsyncIOSpeed()
{
  int m_nValue; // eax
  bool v1; // zf
  int v2; // eax

  if ( g_SuspendIO.m_value != 0 )
  {
    if ( g_SuspendIO.m_value == 1
      && g_nForceSuspendIO.m_value != 1
      && g_nIOMemory.m_value <= g_nLowIOSuspensionMark
      && _InterlockedCompareExchange(&g_SuspendIO.m_value, 0, 1) == 1 )
    {
      if ( CQueuedLoader::GetSpewDetail(this: &g_QueuedLoader) != 0 )
        _Msg(a1: "QueuedLoader: Resuming I/O at %.2f MB\n", (float)((float)g_nIOMemory.m_value * 0.00000095367432));
      g_pFullFileSystem->AsyncResume(this: g_pFullFileSystem);
    }
  }
  else if ( (g_nForceSuspendIO.m_value == 1 || g_nIOMemory.m_value >= g_nHighIOSuspensionMark)
         && g_nActiveJobs.m_value != 0
         && _InterlockedCompareExchange(&g_SuspendIO.m_value, 1, 0) == 0 )
  {
    if ( loader_spew_info.m_pParent != nullptr )
    {
      m_nValue = loader_spew_info.m_pParent->m_Value.m_nValue;
      v1 = m_nValue == 0;
      if ( m_nValue <= 0 )
      {
LABEL_10:
        if ( !v1 )
          _Msg(a1: "QueuedLoader: Suspending I/O at %.2f MB\n", (float)((float)g_nIOMemory.m_value * 0.00000095367432));
        g_pFullFileSystem->AsyncSuspend(this: g_pFullFileSystem);
        return;
      }
      v2 = 1 << (m_nValue - 1);
    }
    else
    {
      v2 = 0;
    }
    v1 = v2 == 0;
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C060
// Name: void IOComputationJob(struct FileJob_t __near *,void __near *,int,enum LoaderError_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall IOComputationJob(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        FileJob_t *pFileJob,
        unsigned __int8 *pData,
        int nSize,
        LoaderError_t loaderError)
{
  int m_nValue; // eax
  int v8; // ebx
  FileJob_t *v9; // esi
  const char *v10; // edi
  DWORD CurrentThreadId; // eax
  LoaderError_t v12; // edi
  void (__cdecl *m_pCallback)(void *, void *, const void *, int, LoaderError_t); // eax
  unsigned __int8 *v14; // edi
  unsigned int ActualSize; // ebx
  unsigned __int8 *v16; // edi
  LoaderPriority_t m_Priority; // esi
  unsigned int m_StartTime; // esi
  int v19; // eax
  unsigned int v20; // esi
  int v21; // eax
  LoaderError_t v22; // [esp-10h] [ebp-21Ch]
  char buf[260]; // [esp+0h] [ebp-20Ch] BYREF
  char szFilename[260]; // [esp+104h] [ebp-108h] BYREF
  int spewDetail; // [esp+208h] [ebp-4h]

  if ( loader_spew_info.m_pParent != nullptr )
  {
    m_nValue = loader_spew_info.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
      m_nValue = 1 << (m_nValue - 1);
    spewDetail = m_nValue;
  }
  else
  {
    LOBYTE(m_nValue) = 0;
    spewDetail = 0;
  }
  v8 = nSize;
  v9 = pFileJob;
  if ( (m_nValue & 6) != 0 )
  {
    v10 = setName;
    if ( !g_QueuedLoader.m_bActive )
      v10 = "(Late) ";
    if ( (m_nValue & 2) != 0 || (m_nValue & 4) != 0 && *v10 != 0 )
    {
      pFileJob = (FileJob_t *)pFileJob->m_hFilename;
      CUtlFilenameSymbolTable::String(
        this: &g_QueuedLoader.m_Filenames,
        handle: (void *const *)&pFileJob,
        buf: szFilename,
        buflen: 260);
      CurrentThreadId = GetCurrentThreadId();
      _Msg(a1: "QueuedLoader: Computation:%8.8x, Size:%7d %s%s\n", CurrentThreadId, v8, v10, szFilename);
    }
  }
  v12 = loaderError;
  if ( loaderError != LOADERERROR_NONE && (*((_BYTE *)v9 + 60) & 4) != 0 )
  {
    loaderError = (LoaderError_t)v9->m_hFilename;
    CUtlFilenameSymbolTable::String(
      this: &g_QueuedLoader.m_Filenames,
      handle: (void *const *)&loaderError,
      buf,
      buflen: 260);
    _Warning(a1: "QueuedLoader:: I/O Error on %s\n", buf);
  }
  m_pCallback = v9->m_pCallback;
  v9->m_nActualBytesRead = v8;
  v9->m_LoaderError = v12;
  if ( m_pCallback != nullptr )
  {
    v22 = v12;
    v16 = pData;
    m_pCallback(a1: v9->m_pContext, a2: v9->m_pContext2, a3: pData, a4: v8, a5: v22);
    if ( (*((_BYTE *)v9 + 60) & 2) != 0 && v16 != nullptr )
      g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: v16);
    _InterlockedExchangeAdd(&g_nIOMemory.m_value, -v8);
  }
  else if ( v9->m_pTargetData == nullptr )
  {
    v14 = pData;
    if ( (*((_BYTE *)v9 + 60) & 0x20) != 0 && CLZMA::IsCompressed(this: (CLZMA *)&nSize + 3, pInput: pData) )
    {
      ActualSize = CLZMA::GetActualSize(this: (CLZMA *)&nSize + 3, pInput: v14);
      pFileJob = (FileJob_t *)g_pFullFileSystem->AllocOptimalReadBuffer(
                                this: g_pFullFileSystem,
                                a2: 0,
                                a3: ActualSize,
                                a4: 0);
      CLZMA::Uncompress(
        this: (CLZMA *)&nSize + 3,
        pInput: v14,
        pOutput: (unsigned __int8 *)pFileJob,
        pCallback: nullptr);
      g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: v14);
      _InterlockedExchangeAdd(&g_nAnonymousIOMemory.m_value, -v9->m_nActualBytesRead);
      v14 = (unsigned __int8 *)pFileJob;
      v9->m_nActualBytesRead = ActualSize;
      _InterlockedExchangeAdd(&g_nAnonymousIOMemory.m_value, ActualSize);
    }
    v9->m_pTargetData = v14;
  }
  *((_DWORD *)v9 + 15) |= 1u;
  v9->m_FinishTime = _Plat_MSTime(a1: a2, a2: a3, a3: a1);
  v9->m_ThreadId = GetCurrentThreadId();
  m_Priority = v9->m_Priority;
  if ( m_Priority == LOADERPRIORITY_DURINGPRELOAD )
  {
    _InterlockedExchangeAdd(&g_nHighPriorityJobs.m_value, 0xFFFFFFFF);
  }
  else if ( m_Priority == LOADERPRIORITY_BEFOREPLAY )
  {
    _InterlockedExchangeAdd(&g_nJobsToFinishBeforePlay.m_value, 0xFFFFFFFF);
  }
  _InterlockedExchangeAdd(&g_nQueuedJobs.m_value, 0xFFFFFFFF);
  if ( g_nQueuedJobs.m_value == 0 && (spewDetail & 1) != 0 )
  {
    m_StartTime = g_QueuedLoader.m_StartTime;
    v19 = _Plat_MSTime(a1: *(_DWORD *)buf, a2: *(_DWORD *)&buf[4], a3: *(_DWORD *)&buf[8]);
    _Warning(a1: "QueuedLoader: Finished I/O of all queued jobs! at: %lu\n", v19 - m_StartTime);
  }
  if ( g_nForceSuspendIO.m_value == -1
    && g_nJobsToFinishBeforePlay.m_value != 0
    && g_nHighPriorityJobs.m_value == 0
    && _InterlockedCompareExchange(&g_nForceSuspendIO.m_value, 1, -1) == -1 )
  {
    v20 = g_QueuedLoader.m_StartTime;
    v21 = _Plat_MSTime(a1: *(_DWORD *)buf, a2: *(_DWORD *)&buf[4], a3: *(_DWORD *)&buf[8]);
    _Warning(a1: "QueuedLoader: Force Suspending I/O at: %lu\n", v21 - v20);
  }
  AdjustAsyncIOSpeed();
}

//------------------------------------------------------------------------------
// Address: 0x1001C2D0
// Name: void FinishAnonymousJob(struct FileJob_t __near *,void (*)(void __near *,void __near *,void const __near *,int,enum LoaderError_t),void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FinishAnonymousJob(
        FileJob_t *pFileJob,
        void (__cdecl *pCallback)(void *, void *, const void *, int, LoaderError_t),
        void *pContext,
        void *pContext2)
{
  int m_nActualBytesRead; // ecx

  pCallback(
    a1: pContext,
    a2: pContext2,
    a3: pFileJob->m_pTargetData,
    a4: pFileJob->m_nActualBytesRead,
    a5: pFileJob->m_LoaderError);
  if ( (*((_BYTE *)pFileJob + 60) & 2) != 0 && pFileJob->m_pTargetData != nullptr )
  {
    g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: pFileJob->m_pTargetData);
    pFileJob->m_pTargetData = nullptr;
  }
  m_nActualBytesRead = pFileJob->m_nActualBytesRead;
  *((_DWORD *)pFileJob + 15) |= 8u;
  _InterlockedExchangeAdd(&g_nAnonymousIOMemory.m_value, -m_nActualBytesRead);
}

//------------------------------------------------------------------------------
// Address: 0x1001C330
// Name: public: virtual bool CQueuedLoader::IsFinished(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CQueuedLoader::IsFinished(CQueuedLoader *this)
{
  return !this->m_bActive && g_nActiveJobs.m_value == 0 && g_nQueuedJobs.m_value == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001C360
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x1001C370
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C3A0
// Name: public: virtual void CFunctor4<void (*)(struct FileJob_t __near *,void __near *,int,enum LoaderError_t),struct FileJob_t __near *,void __near *,int,enum LoaderError_t,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor4<void (__cdecl *)(FileJob_t *,void *,int,enum LoaderError_t),FileJob_t *,void *,int,enum LoaderError_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor4<void (__cdecl*)(FileJob_t *,void (__cdecl*)(void *,void *,void const *,int,enum LoaderError_t),void *,void *),FileJob_t *,void (__cdecl*)(void *,void *,void const *,int,enum LoaderError_t),void *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1, a2: this->m_arg2, a3: this->m_arg3, a4: this->m_arg4);
}

//------------------------------------------------------------------------------
// Address: 0x1001C430
// Name: public: int CQueuedLoader::CFileJobsLessFunc::GetLayoutOrderForFilename(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CQueuedLoader::CFileJobsLessFunc::GetLayoutOrderForFilename(
        CQueuedLoader::CFileJobsLessFunc *this,
        const char *pFilename)
{
  int v2; // edi
  int i; // esi
  const char *v4; // eax

  v2 = 0;
  if ( g_DVDLayout.m_Size <= 0 )
    return 0x7FFFFFFF;
  for ( i = 0; ; ++i )
  {
    v4 = CUtlString::operator char const *(this: &g_DVDLayout.m_Memory.m_pMemory[i]);
    if ( V_stristr(pStr: pFilename, pSearch: v4) != nullptr )
      break;
    if ( ++v2 >= g_DVDLayout.m_Size )
      return 0x7FFFFFFF;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001C490
// Name: public: bool CQueuedLoader::CFileJobsLessFunc::Less(struct FileJob_t __near * const __near &,struct FileJob_t __near * const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQueuedLoader::CFileJobsLessFunc::Less(
        CQueuedLoader::CFileJobsLessFunc *this,
        FileJob_t *const *pFileJobLHS,
        FileJob_t *const ***pFileJobRHS,
        void *pCtx)
{
  int v5; // eax
  double v6; // st7
  void (__thiscall *UpdateProgress)(ILoaderProgress *, float, bool); // eax
  FileJob_t *const **v8; // eax
  FileJob_t *const ***v9; // ebx
  FileJob_t *const **v10; // ecx
  LoaderPriority_t m_Priority; // edx
  LoaderPriority_t v12; // esi
  int LayoutOrderForFilename; // esi
  int v15; // eax
  char szFilenameLHS[260]; // [esp+14h] [ebp-20Ch] BYREF
  char szFilenameRHS[260]; // [esp+118h] [ebp-108h] BYREF
  float flTime; // [esp+21Ch] [ebp-4h]

  v5 = 200 * (++nCalls / 200);
  if ( nCalls == v5 )
  {
    v6 = _Plat_FloatTime(a1: nCalls - v5);
    flTime = v6;
    if ( v6 - flLastUpdateTime > 0.059999999 )
    {
      UpdateProgress = g_QueuedLoader.m_pProgress->UpdateProgress;
      flLastUpdateTime = flTime;
      ((void (__stdcall *)(_DWORD, _DWORD))UpdateProgress)(
        a1: (float)((float)((float)nCalls * 0.000001) * 0.019999996) + 0.23,
        a2: 0);
    }
  }
  v8 = (FileJob_t *const **)*pFileJobLHS;
  v9 = pFileJobRHS;
  v10 = *pFileJobRHS;
  m_Priority = (*pFileJobLHS)->m_Priority;
  v12 = (LoaderPriority_t)(*pFileJobRHS)[8];
  if ( m_Priority != v12 )
    return m_Priority > v12;
  if ( *v8 == *v10 )
    return v8[7] < v10[7];
  pFileJobLHS = *v8;
  CUtlFilenameSymbolTable::String(
    this: &g_QueuedLoader.m_Filenames,
    handle: (void *const *)&pFileJobLHS,
    buf: szFilenameLHS,
    buflen: 260);
  pFileJobLHS = **v9;
  CUtlFilenameSymbolTable::String(
    this: &g_QueuedLoader.m_Filenames,
    handle: (void *const *)&pFileJobLHS,
    buf: szFilenameRHS,
    buflen: 260);
  LayoutOrderForFilename = CQueuedLoader::CFileJobsLessFunc::GetLayoutOrderForFilename(this, pFilename: szFilenameLHS);
  v15 = CQueuedLoader::CFileJobsLessFunc::GetLayoutOrderForFilename(this, pFilename: szFilenameRHS);
  if ( LayoutOrderForFilename == v15 )
    return _V_stricmp(s1: szFilenameLHS, s2: szFilenameRHS) < 0;
  else
    return LayoutOrderForFilename < v15;
}

//------------------------------------------------------------------------------
// Address: 0x1001C600
// Name: public: int CUtlSortVector<void __near *,class CQueuedLoader::CResourceNameLessFunc>::Find(void __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<void *,CQueuedLoader::CResourceNameLessFunc>::Find(
        CUtlSortVector<void *,CQueuedLoader::CResourceNameLessFunc> *this,
        void *const *src)
{
  int v3; // esi
  int v5; // esi
  int start; // [esp+Ch] [ebp-8h]
  int end; // [esp+10h] [ebp-4h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = this->m_Size - 1;
  start = 0;
  end = v3;
  if ( v3 < 0 )
    return -1;
  while ( 1 )
  {
    v5 = (start + v3) >> 1;
    if ( CQueuedLoader::CResourceNameLessFunc::Less(
           this: (CQueuedLoader::CResourceNameLessFunc *)&src + 3,
           hFilenameLHS: &this->m_Memory.m_pMemory[v5],
           hFilenameRHS: src,
           pCtx: this->m_pLessContext) )
    {
      start = v5 + 1;
      goto LABEL_14;
    }
    if ( !CQueuedLoader::CResourceNameLessFunc::Less(
            this: (CQueuedLoader::CResourceNameLessFunc *)&src + 3,
            hFilenameLHS: src,
            hFilenameRHS: &this->m_Memory.m_pMemory[v5],
            pCtx: this->m_pLessContext) )
      return v5;
    end = v5 - 1;
LABEL_14:
    if ( start > end )
      return -1;
    v3 = end;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C700
// Name: protected: static int CUtlSortVector<struct FileJob_t __near *,class CQueuedLoader::CFileJobsLessFunc>::CompareHelper(void __near *,struct FileJob_t __near * const __near *,struct FileJob_t __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<FileJob_t *,CQueuedLoader::CFileJobsLessFunc>::CompareHelper(
        CQueuedLoader::CFileJobsLessFunc **context,
        FileJob_t *const ***lhs,
        FileJob_t **rhs)
{
  if ( CQueuedLoader::CFileJobsLessFunc::Less(
         this: context[1],
         pFileJobLHS: (FileJob_t *const *)lhs,
         pFileJobRHS: (FileJob_t *const ***)rhs,
         pCtx: *context) )
  {
    return -1;
  }
  else
  {
    return CQueuedLoader::CFileJobsLessFunc::Less(this: context[1], pFileJobLHS: rhs, pFileJobRHS: lhs, pCtx: *context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D480
// Name: public: void CQueuedLoader::SpewInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedLoader::SpewInfo(CQueuedLoader *this)
{
  void (*v1)(const char *, ...); // ebx
  int m_Head; // eax
  int v4; // eax
  FileJob_t *m_Element; // esi
  unsigned int m_FinishTime; // eax
  int v7; // eax
  LoaderPriority_t m_Priority; // eax
  __int32 v9; // eax
  char *v10; // ebx
  const char *v11; // eax
  int i; // esi
  int v13; // esi
  int v14; // ebx
  const char *v15; // eax
  unsigned int m_EndTime; // eax
  char szMessage[1024]; // [esp+14h] [ebp-728h] BYREF
  char szFilename[260]; // [esp+414h] [ebp-328h] BYREF
  char szAnonymousString[260]; // [esp+518h] [ebp-224h] BYREF
  char buf[260]; // [esp+61Ch] [ebp-120h] BYREF
  void *handle; // [esp+720h] [ebp-1Ch] BYREF
  int lastPriority; // [esp+724h] [ebp-18h]
  int asyncDuration; // [esp+728h] [ebp-14h]
  int lastLateState; // [esp+72Ch] [ebp-10h]
  void *v25; // [esp+730h] [ebp-Ch] BYREF
  int totalClaimed; // [esp+734h] [ebp-8h]
  int totalUnclaimed; // [esp+738h] [ebp-4h]

  v1 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "Queued Loader:\n\n");
  totalClaimed = 0;
  totalUnclaimed = 0;
  if ( this->IsFinished(this) )
  {
    m_Head = this->m_SubmittedJobs.m_Head;
    lastPriority = -1;
    for ( lastLateState = -1; m_Head != 0xFFFF; v1 = (void (*)(const char *, ...))_Msg )
    {
      v4 = (unsigned __int16)m_Head;
      m_Element = this->m_SubmittedJobs.m_Memory.m_pMemory[v4].m_Element;
      v25 = (void *)(v4 * 8);
      m_FinishTime = m_Element->m_FinishTime;
      asyncDuration = -1;
      if ( m_FinishTime != 0 )
        asyncDuration = m_FinishTime - m_Element->m_SubmitTime;
      v7 = (*((_DWORD *)m_Element + 15) & 0x10) != 0;
      if ( v7 != lastLateState )
      {
        if ( (*((_DWORD *)m_Element + 15) & 0x10) != 0 )
          _Warning(a1: "---- LATE QUEUED JOBS ----\n");
        v7 = (*((_DWORD *)m_Element + 15) & 0x10) != 0;
        lastLateState = v7;
      }
      if ( v7 == 0 )
      {
        m_Priority = m_Element->m_Priority;
        if ( m_Priority != lastPriority )
        {
          if ( m_Priority != LOADERPRIORITY_ANYTIME )
          {
            v9 = m_Priority - 1;
            if ( v9 != 0 )
            {
              if ( v9 == 1 )
                v1(a1: "---- FINISH DURING PRELOAD ( HIGH PRIORITY )----\n");
            }
            else
            {
              v1(a1: "---- FINISH BEFORE GAMEPLAY ( NORMAL PRIORITY )----\n");
            }
          }
          else
          {
            v1(a1: "---- FINISH ANYTIME ( NORMAL PRIORITY )----\n");
          }
          lastPriority = m_Element->m_Priority;
        }
      }
      v10 = (char *)setName;
      if ( m_Element->m_pCallback == nullptr )
      {
        v11 = "Claimed";
        if ( (*((_BYTE *)m_Element + 60) & 8) == 0 )
          v11 = "Unclaimed";
        V_snprintf(pDest: szAnonymousString, maxLen: 260, pFormat: "(%s) ", v11);
        v10 = szAnonymousString;
        if ( (*((_BYTE *)m_Element + 60) & 8) != 0 )
          totalClaimed += m_Element->m_nActualBytesRead;
        else
          totalUnclaimed += m_Element->m_nActualBytesRead;
      }
      handle = m_Element->m_hFilename;
      CUtlFilenameSymbolTable::String(this: &this->m_Filenames, &handle, buf: szFilename, buflen: 260);
      V_snprintf(
        pDest: szMessage,
        maxLen: 1024,
        pFormat: "Submit:%5dms AsyncDuration:%5dms Tag:%d Thread:%8.8x Size:%7d %s%s",
        m_Element->m_SubmitTime - this->m_StartTime,
        asyncDuration,
        m_Element->m_SubmitTag,
        m_Element->m_ThreadId,
        m_Element->m_nActualBytesRead,
        v10,
        szFilename);
      if ( (*((_BYTE *)m_Element + 60) & 0x10) != 0 )
        _Warning(a1: "%s\n", szMessage);
      else
        _Msg(a1: "%s\n", szMessage);
      m_Head = *(unsigned __int16 *)((char *)v25 + (unsigned int)this->m_SubmittedJobs.m_Memory.m_pMemory + 6);
    }
    v1(a1: "%d Total Jobs\n", this->m_SubmittedJobs.m_ElementCount);
  }
  v1(a1: "\nExcludes:\n");
  for ( i = 0; i < this->m_ExcludeResourceNames.m_Size; ++i )
  {
    memset(buf, 0, sizeof(buf));
    v25 = this->m_ExcludeResourceNames.m_Memory.m_pMemory[i];
    CUtlFilenameSymbolTable::String(this: &this->m_Filenames, handle: &v25, buf, buflen: 260);
    v1(a1: "%s\n", buf);
  }
  v1(a1: "\nLayout Order:\n");
  v13 = 0;
  if ( g_DVDLayout.m_Size > 0 )
  {
    v14 = 0;
    do
    {
      v15 = CUtlString::operator char const *(this: &g_DVDLayout.m_Memory.m_pMemory[v14]);
      _Msg(a1: "%s\n", v15);
      ++v13;
      ++v14;
    }
    while ( v13 < g_DVDLayout.m_Size );
    v1 = (void (*)(const char *, ...))_Msg;
  }
  v1(a1: "\n");
  v1(a1: "%d Queued Jobs\n", g_nQueuedJobs.m_value);
  v1(a1: "%d Active Jobs\n", g_nActiveJobs.m_value);
  v1(a1: "Peak IO Memory: %.2f MB\n", (float)((float)g_nIOMemoryPeak * 0.00000095367432));
  v1(a1: "Peak Anonymous IO Memory: %.2f MB\n", (float)((float)g_nAnonymousIOMemoryPeak * 0.00000095367432));
  v1(a1: "  Total Anonymous Claimed: %d\n", totalClaimed);
  v1(a1: "  Total Anonymous Unclaimed: %d\n", totalUnclaimed);
  m_EndTime = this->m_EndTime;
  if ( m_EndTime != 0 )
    v1(a1: "Queuing Duration: %dms\n", m_EndTime - this->m_StartTime);
}

//------------------------------------------------------------------------------
// Address: 0x1001D7E0
// Name: public: virtual enum InitReturnVal_t CTier2AppSystem<class IAsyncFileSystem,0>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IAsyncFileSystem,0>::Init(CTier2AppSystem<IAsyncFileSystem,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001D800
// Name: public: class CJob __near * IThreadPool::QueueCall<void,struct FileJob_t __near *,void (*)(void __near *,void __near *,void const __near *,int,enum LoaderError_t),void __near *,void __near *,struct FileJob_t __near *,void (*)(void __near *,void __near *,void const __near *,int,enum LoaderError_t),void __near *,void __near *>(void (*)(struct FileJob_t __near *,void (*)(void __near *,void __near *,void const __near *,int,enum LoaderError_t),void __near *,void __near *),struct FileJob_t __near * const __near &,void (*const __near &)(void __near *,void __near *,void const __near *,int,enum LoaderError_t),void __near * const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CJob *__thiscall IThreadPool::QueueCall<void,FileJob_t *,void (__cdecl *)(void *,void *,void const *,int,enum LoaderError_t),void *,void *,FileJob_t *,void (__cdecl *)(void *,void *,void const *,int,enum LoaderError_t),void *,void *>(
        IThreadPool *this,
        void (__cdecl *pfnProxied)(FileJob_t *, void (__cdecl *)(void *, void *, const void *, int, LoaderError_t), void *, void *),
        FileJob_t *const *arg1,
        CFunctor_vtbl **arg2,
        void *const *arg3,
        CFunctor_vtbl **arg4)
{
  CFunctor *v7; // eax
  CJob *pJob; // [esp+4h] [ebp-4h] BYREF

  v7 = (CFunctor *)operator new(nSize: 0x24u);
  if ( v7 != nullptr )
  {
    v7[1].m_nUserID = 1;
    v7->__vftable = (CFunctor_vtbl *)&CFunctor4<void (__cdecl *)(FileJob_t *,void (__cdecl *)(void *,void *,void const *,int,enum LoaderError_t),void *,void *),FileJob_t *,void (__cdecl *)(void *,void *,void const *,int,enum LoaderError_t),void *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v7[1].__vftable = (CFunctor_vtbl *)&CFunctor4<void (__cdecl *)(FileJob_t *,void (__cdecl *)(void *,void *,void const *,int,enum LoaderError_t),void *,void *),FileJob_t *,void (__cdecl *)(void *,void *,void const *,int,enum LoaderError_t),void *,void *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v7[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v7[2].m_nUserID = (unsigned int)*arg1;
    v7[3].__vftable = *arg2;
    v7[3].m_nUserID = (unsigned int)*arg3;
    v7[4].__vftable = *arg4;
  }
  else
  {
    v7 = nullptr;
  }
  this->AddFunctorInternal(this, a2: v7, a3: &pJob, a4: nullptr, a5: 8u);
  return pJob;
}

//------------------------------------------------------------------------------
// Address: 0x1001E7D0
// Name: loader_dump_table
// Source: json
//------------------------------------------------------------------------------
void __cdecl loader_dump_table()
{
  CQueuedLoader::SpewInfo(this: &g_QueuedLoader);
}

//------------------------------------------------------------------------------
// Address: 0x1001E7E0
// Name: void IOAsyncCallback(struct FileAsyncRequest_t const __near &,int,enum FSAsyncStatus_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IOAsyncCallback(
        const FileAsyncRequest_t *asyncRequest,
        unsigned int numReadBytes,
        LoaderError_t asyncStatus)
{
  _DWORD *pContext; // edi
  CFunctor *v4; // eax
  int v5; // [esp+Ch] [ebp-4h] BYREF
  LoaderError_t loaderError; // [esp+20h] [ebp+10h]

  pContext = asyncRequest->pContext;
  if ( asyncStatus == LOADERERROR_FILEOPEN )
    loaderError = LOADERERROR_FILEOPEN;
  else
    loaderError = asyncStatus != LOADERERROR_NONE ? 0xFFFFFFFE : LOADERERROR_NONE;
  if ( pContext[1] != 0 )
  {
    _InterlockedExchangeAdd(&g_nIOMemory.m_value, numReadBytes);
    if ( g_nIOMemory.m_value > g_nIOMemoryPeak )
      g_nIOMemoryPeak = g_nIOMemory.m_value;
  }
  else
  {
    _InterlockedExchangeAdd(&g_nAnonymousIOMemory.m_value, numReadBytes);
    if ( g_nAnonymousIOMemory.m_value > g_nAnonymousIOMemoryPeak )
      g_nAnonymousIOMemoryPeak = g_nAnonymousIOMemory.m_value;
  }
  v4 = (CFunctor *)operator new(nSize: 0x24u);
  if ( v4 != nullptr )
  {
    v4[1].m_nUserID = 1;
    v4->__vftable = (CFunctor_vtbl *)&CFunctor4<void (__cdecl *)(FileJob_t *,void *,int,enum LoaderError_t),FileJob_t *,void *,int,enum LoaderError_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CFunctor4<void (__cdecl *)(FileJob_t *,void *,int,enum LoaderError_t),FileJob_t *,void *,int,enum LoaderError_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].__vftable = (CFunctor_vtbl *)IOComputationJob;
    v4[2].m_nUserID = (unsigned int)pContext;
    v4[3].__vftable = (CFunctor_vtbl *)asyncRequest->pData;
    v4[3].m_nUserID = numReadBytes;
    v4[4].__vftable = (CFunctor_vtbl *)loaderError;
  }
  else
  {
    v4 = nullptr;
  }
  _g_pThreadPool->AddFunctorInternal(this: _g_pThreadPool, a2: v4, a3: (CJob **)&v5, a4: nullptr, a5: 8u);
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  CQueuedLoader::SubmitPendingJobs(this: &g_QueuedLoader);
  _InterlockedExchangeAdd(&g_nActiveJobs.m_value, 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x1001EC00
// Name: public: virtual bool CTier2AppSystem<class IQueuedLoader,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier2AppSystem<IQueuedLoader,0>::Connect(
        CTier2AppSystem<IFileSystem,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  pFactoryList = factory;
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001EC30
// Name: public: void CUtlDict<struct FileJob_t __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<FileJob_t *,int>::RemoveAll(CUtlDict<FileJob_t *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1001EC80
// Name: public: void CQueuedLoader::SubmitPendingJobs(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CQueuedLoader::SubmitPendingJobs(CQueuedLoader *this@<ecx>, int a2@<edx>, int p_m_hAsyncControl@<ebx>)
{
  int v4; // edx
  int v5; // ecx
  TSLNodeBase_t *v6; // ebx
  signed int m_Size; // esi
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  FileJob_t **m_pMemory; // edi
  signed int v10; // ebx
  FileJob_t **v11; // ebx
  int v12; // ebx
  FileJob_t *v13; // esi
  CQueuedLoader *v14; // edi
  unsigned __int16 v15; // ax
  int v16; // edi
  UtlLinkedListElem_t<FileJob_t *,unsigned short> *v17; // eax
  LoaderPriority_t m_Priority; // eax
  _DWORD *v19; // eax
  int v21; // [esp+0h] [ebp-170h]
  int v22; // [esp+4h] [ebp-16Ch]
  char szFilename[260]; // [esp+8h] [ebp-168h] BYREF
  FileAsyncRequest_t asyncRequest; // [esp+10Ch] [ebp-64h] BYREF
  _DWORD context[2]; // [esp+138h] [ebp-38h] BYREF
  int v26; // [esp+140h] [ebp-30h] BYREF
  CUtlSortVector<FileJob_t *,CQueuedLoader::CFileJobsLessFunc> sortedFiles; // [esp+144h] [ebp-2Ch] BYREF
  FileJob_t *pFileJob; // [esp+160h] [ebp-10h] BYREF
  char v29; // [esp+167h] [ebp-9h] BYREF
  CQueuedLoader *v30; // [esp+168h] [ebp-8h]
  int i; // [esp+16Ch] [ebp-4h]

  v30 = this;
  if ( ((unsigned __int8)_ThreadInMainThread(a1: this, a2) == 0 || g_nActiveJobs.m_value == 0)
    && ((unsigned __int8)_ThreadInMainThread(a1: v5, a2: v4) != 0 || g_nActiveJobs.m_value == 1) )
  {
    v6 = CTSListBase::Detach(this: &this->m_PendingJobs);
    m_Size = 0;
    i = (int)v6;
    if ( v6 != nullptr )
    {
      ++this->m_nSubmitCount;
      Alloc_2 = _g_pMemAlloc->Alloc_2;
      sortedFiles.m_Memory.m_nAllocationCount = 128;
      sortedFiles.m_Memory.m_nGrowSize = 0;
      m_pMemory = (FileJob_t **)Alloc_2(this: _g_pMemAlloc, a2: 512u);
      sortedFiles.m_Memory.m_pMemory = m_pMemory;
      sortedFiles.m_Size = 0;
      sortedFiles.m_pElements = m_pMemory;
      sortedFiles.m_pLessContext = nullptr;
      while ( 1 )
      {
        pFileJob = *((FileJob_t **)&v6->Next + 1);
        sortedFiles.m_bNeedsSort = true;
        v10 = m_Size;
        if ( m_Size + 1 > sortedFiles.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CPackedStore *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&sortedFiles,
            num: m_Size - sortedFiles.m_Memory.m_nAllocationCount + 1);
          m_Size = sortedFiles.m_Size;
          m_pMemory = sortedFiles.m_Memory.m_pMemory;
        }
        sortedFiles.m_Size = ++m_Size;
        sortedFiles.m_pElements = m_pMemory;
        if ( m_Size - v10 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
        v11 = &m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = pFileJob;
        v12 = *(_DWORD *)i;
        free(pMem: (void *)i);
        i = v12;
        if ( v12 == 0 )
          break;
        v6 = (TSLNodeBase_t *)i;
      }
      if ( sortedFiles.m_bNeedsSort && m_Size > 1 )
      {
        context[0] = sortedFiles.m_pLessContext;
        context[1] = &v29;
        qsort_s(
          base: m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<FileJob_t *,CQueuedLoader::CFileJobsLessFunc>::CompareHelper,
          context);
      }
      memset(dst: (unsigned __int8 *)&asyncRequest, value: 0, count: sizeof(asyncRequest));
      asyncRequest.hSpecificAsyncFile = (FSAsyncFile_t__ *)0xFFFF;
      asyncRequest.pfnCallback = (void (__cdecl *)(const FileAsyncRequest_t *, int, FSAsyncStatus_t))IOAsyncCallback;
      i = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v13 = m_pMemory[i];
          v14 = v30;
          v13->m_SubmitTag = v30->m_nSubmitCount;
          v13->m_SubmitTime = _Plat_MSTime(a1: p_m_hAsyncControl, a2: v21, a3: v22);
          v15 = CUtlLinkedList<FileJob_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<FileJob_t *,unsigned short>,unsigned short>>::AllocInternal(
                  this: &v14->m_SubmittedJobs,
                  multilist: false);
          v16 = v15;
          if ( v15 != 0xFFFF )
          {
            CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::LinkBefore(
              this: (CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short> > *)&v30->m_SubmittedJobs,
              before: 0xFFFFu,
              elem: v15);
            v17 = &v30->m_SubmittedJobs.m_Memory.m_pMemory[v16];
            if ( v17 != nullptr )
              v17->m_Element = v13;
          }
          m_Priority = v13->m_Priority;
          if ( m_Priority == LOADERPRIORITY_DURINGPRELOAD )
          {
            asyncRequest.priority = 1;
            _InterlockedExchangeAdd(&g_nHighPriorityJobs.m_value, 1u);
          }
          else
          {
            asyncRequest.priority = 0;
            if ( m_Priority == LOADERPRIORITY_BEFOREPLAY )
              _InterlockedExchangeAdd(&g_nJobsToFinishBeforePlay.m_value, 1u);
          }
          asyncRequest.pData = v13->m_pTargetData;
          asyncRequest.flags = v13->m_pTargetData == nullptr;
          asyncRequest.nOffset = v13->m_nStartOffset;
          asyncRequest.nBytes = v13->m_nBytesToRead;
          pFileJob = (FileJob_t *)v13->m_hFilename;
          CUtlFilenameSymbolTable::String(
            this: &v30->m_Filenames,
            handle: (void *const *)&pFileJob,
            buf: szFilename,
            buflen: 260);
          asyncRequest.pszFilename = szFilename;
          asyncRequest.pContext = v13;
          while ( g_SuspendIO.m_value != 0 )
            _ThreadSleep(a1: 20);
          if ( (*((_BYTE *)v13 + 60) & 4) != 0 )
          {
            _InterlockedExchangeAdd(&g_nActiveJobs.m_value, 1u);
            p_m_hAsyncControl = (int)&v13->m_hAsyncControl;
            ((void (__thiscall *)(IFileSystem *, FileAsyncRequest_t *, int))g_pFullFileSystem->AsyncReadMultiple)(
              a1: g_pFullFileSystem,
              a2: &asyncRequest,
              a3: 1);
          }
          else
          {
            v19 = operator new(nSize: 0x24u);
            if ( v19 != nullptr )
            {
              v19[3] = 1;
              *v19 = &CFunctor4<void (__cdecl *)(FileJob_t *,void *,int,enum LoaderError_t),FileJob_t *,void *,int,enum LoaderError_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
              v19[2] = &CFunctor4<void (__cdecl *)(FileJob_t *,void *,int,enum LoaderError_t),FileJob_t *,void *,int,enum LoaderError_t,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
              v19[4] = IOComputationJob;
              v19[5] = v13;
              v19[6] = v13->m_pTargetData;
              v19[7] = 0;
              v19[8] = -1;
            }
            else
            {
              v19 = nullptr;
            }
            p_m_hAsyncControl = 8;
            ((void (__thiscall *)(IThreadPool *, _DWORD *, int *, _DWORD))_g_pThreadPool->AddFunctorInternal)(
              a1: _g_pThreadPool,
              a2: v19,
              a3: &v26,
              a4: 0);
            (*(void (__thiscall **)(int))(*(_DWORD *)v26 + 4))(a1: v26);
          }
          m_pMemory = sortedFiles.m_Memory.m_pMemory;
          ++i;
        }
        while ( i < sortedFiles.m_Size );
      }
      if ( sortedFiles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EFA0
// Name: public: int CUtlMap<char const __near *,struct FileJob_t __near *,int>::Insert(char const __near * const __near &,struct FileJob_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,FileJob_t *,int>::Insert(
        CUtlMap<char const *,FileJob_t *,int> *this,
        const char **key,
        int insert)
{
  FileJob_t *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,FileJob_t *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(FileJob_t **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001F020
// Name: public: virtual void CQueuedLoader::EndMapLoading(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CQueuedLoader::EndMapLoading(CQueuedLoader *this@<ecx>, int a2@<edi>, int a3@<esi>, bool bAbort)
{
  int v5; // edx
  IResourcePreload **v6; // esi
  int i; // edi
  int j; // esi
  FileJob_t *elem; // edi

  if ( this->m_bStarted )
  {
    if ( this->m_bActive )
    {
      if ( this->GetSpewDetail(this) != 0 )
        _Msg(a1: "QueuedLoader: Finishing %d Jobs\n", g_nJobsToFinishBeforePlay.m_value);
      this->m_pProgress->PauseNonInteractiveProgress(this: this->m_pProgress, a2: true);
      _InterlockedExchange(&g_nForceSuspendIO.m_value, 0);
      AdjustAsyncIOSpeed();
      CQueuedLoader::SubmitPendingJobs(this, a2: v5, p_m_hAsyncControl: (int)this);
      while ( g_nHighPriorityJobs.m_value != 0 || g_nJobsToFinishBeforePlay.m_value != 0 )
      {
        _g_pThreadPool->Yield(this: _g_pThreadPool, a2: 20u);
        ((void (__stdcall *)(int, int))this->m_pProgress->UpdateProgress)(a1: 1065336439, a2: 1);
      }
      this->m_pProgress->PauseNonInteractiveProgress(this: this->m_pProgress, a2: false);
      this->m_EndTime = _Plat_MSTime(a1: a2, a2: a3);
      this->m_bActive = false;
      v6 = &this->m_pLoaders[1];
      for ( i = 7; i != 0; --i )
      {
        if ( *v6 != nullptr )
          (*v6)->OnEndMapLoading(this: *v6, a2: false);
        ++v6;
      }
      for ( j = CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_AnonymousJobs.m_Elements.m_Tree);
            j != -1;
            j = CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::NextInorder(
                  this: &this->m_AnonymousJobs.m_Elements.m_Tree,
                  i: j) )
      {
        elem = this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.elem;
        if ( (*((_BYTE *)elem + 60) & 2) != 0 && elem->m_pTargetData != nullptr )
        {
          g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: elem->m_pTargetData);
          elem->m_pTargetData = nullptr;
        }
        _InterlockedExchangeAdd(&g_nAnonymousIOMemory.m_value, -elem->m_nActualBytesRead);
      }
      CUtlDict<FileJob_t *,int>::RemoveAll(this: &this->m_AnonymousJobs);
      if ( g_nIOMemory.m_value != 0 || g_nAnonymousIOMemory.m_value != 0 )
      {
        DevWarning(
          a1: "QueuedLoader: Unclaimed I/O memory: total:%d anonymous:%d\n",
          g_nIOMemory.m_value,
          g_nAnonymousIOMemory.m_value);
        _InterlockedExchange(&g_nIOMemory.m_value, 0);
        _InterlockedExchange(&g_nAnonymousIOMemory.m_value, 0);
      }
      CUtlSymbolTable::RemoveAll(this: &this->m_AdditionalResources);
    }
    g_pFullFileSystem->EndMapAccess(this: g_pFullFileSystem);
    this->m_bStarted = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F1F0
// Name: public: int CUtlDict<struct FileJob_t __near *,int>::Insert(char const __near *,struct FileJob_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<FileJob_t *,int>::Insert(
        CUtlDict<FileJob_t *,int> *this,
        char *pName,
        FileJob_t *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,FileJob_t *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x1001F250
// Name: public: CQueuedLoader::CQueuedLoader(void)
// Source: json
//------------------------------------------------------------------------------
CQueuedLoader *__thiscall CQueuedLoader::CQueuedLoader(CQueuedLoader *this)
{
  CUtlSortVector<void *,CQueuedLoader::CResourceNameLessFunc> *m_ResourceNames; // eax
  int i; // ecx

  this->__vftable = (CQueuedLoader_vtbl *)&CQueuedLoader::`vftable';
  CCountedStringPoolBase<unsigned short>::CCountedStringPoolBase<unsigned short>(
    this: &this->m_Filenames.m_PathStringPool,
    caseSensitivity: StringPoolCaseInsensitive);
  CCountedStringPoolBase<unsigned int>::CCountedStringPoolBase<unsigned int>(
    this: &this->m_Filenames.m_FileStringPool,
    caseSensitivity: StringPoolCaseInsensitive);
  this->m_Filenames.m_lock.m_lockInfo.m_i32 = 0;
  this->m_Filenames.m_lock.m_writerId = 0;
  if ( (((_BYTE)this - 112) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  this->m_PendingJobs.m_Head.value.Next = nullptr;
  this->m_PendingJobs.m_Head.value32.DepthAndSequence = 0;
  if ( (((_BYTE)this - 104) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  this->m_BatchedJobs.m_Head.value.Next = nullptr;
  this->m_BatchedJobs.m_Head.value32.DepthAndSequence = 0;
  this->m_SubmittedJobs.m_Memory.m_pMemory = nullptr;
  this->m_SubmittedJobs.m_Memory.m_nAllocationCount = 0;
  this->m_SubmittedJobs.m_Memory.m_nGrowSize = 0;
  this->m_SubmittedJobs.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_SubmittedJobs.m_FirstFree = 0xFFFF;
  this->m_SubmittedJobs.m_pElements = this->m_SubmittedJobs.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_SubmittedJobs.m_Head = -1;
  this->m_SubmittedJobs.m_NumAlloced = 0;
  this->m_AnonymousJobs.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_AnonymousJobs.m_Elements.m_Tree.m_Root = -1;
  this->m_AnonymousJobs.m_Elements.m_Tree.m_NumElements = 0;
  this->m_AnonymousJobs.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_AnonymousJobs.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_AnonymousJobs.m_Elements.m_Tree.m_pElements = this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_AnonymousJobs.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_AnonymousJobs.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_AdditionalResources,
    growSize: 0,
    initSize: 16,
    caseInsensitive: false);
  m_ResourceNames = this->m_ResourceNames;
  for ( i = 7; i >= 0; --i )
  {
    m_ResourceNames->m_Memory.m_pMemory = nullptr;
    m_ResourceNames->m_Memory.m_nAllocationCount = 0;
    m_ResourceNames->m_Memory.m_nGrowSize = 0;
    m_ResourceNames->m_Size = 0;
    m_ResourceNames->m_pElements = nullptr;
    m_ResourceNames->m_pLessContext = nullptr;
    m_ResourceNames->m_bNeedsSort = false;
    ++m_ResourceNames;
  }
  this->m_ExcludeResourceNames.m_Memory.m_pMemory = nullptr;
  this->m_ExcludeResourceNames.m_Memory.m_nAllocationCount = 0;
  this->m_ExcludeResourceNames.m_Memory.m_nGrowSize = 0;
  this->m_ExcludeResourceNames.m_Size = 0;
  this->m_ExcludeResourceNames.m_pElements = nullptr;
  this->m_ExcludeResourceNames.m_pLessContext = nullptr;
  this->m_ExcludeResourceNames.m_bNeedsSort = false;
  this->m_Mutex.m_ownerID = 0;
  this->m_Mutex.m_depth = 0;
  *(_WORD *)&this->m_bStarted = 0;
  this->m_bSameMap = false;
  this->m_szMapNameToCompareSame[0] = 0;
  this->m_pProgress = &s_DummyProgress;
  _V_memset(dest: this->m_pLoaders, fill: 0, count: 32);
  this->m_ExcludeResourceNames.m_pLessContext = nullptr;
  this->m_ResourceNames[0].m_pLessContext = nullptr;
  this->m_ResourceNames[1].m_pLessContext = (void *)1;
  this->m_ResourceNames[2].m_pLessContext = (void *)2;
  this->m_ResourceNames[3].m_pLessContext = (void *)3;
  this->m_ResourceNames[4].m_pLessContext = (void *)4;
  this->m_ResourceNames[5].m_pLessContext = (void *)5;
  this->m_ResourceNames[6].m_pLessContext = (void *)6;
  this->m_ResourceNames[7].m_pLessContext = (void *)7;
  this->m_pLoaders[7] = &s_ResourcePreloadAnonymous;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001F450
// Name: public: virtual CQueuedLoader::~CQueuedLoader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQueuedLoader::~CQueuedLoader(CQueuedLoader *this)
{
  CUtlSortVector<void *,CQueuedLoader::CResourceNameLessFunc> *p_m_ExcludeResourceNames; // esi
  void **m_pMemory; // eax
  TSLNodeBase_t *v4; // eax
  TSLNodeBase_t *Next; // esi
  TSLNodeBase_t *v6; // eax
  TSLNodeBase_t *v7; // esi
  int i; // [esp+10h] [ebp-4h]

  this->__vftable = (CQueuedLoader_vtbl *)&CQueuedLoader::`vftable';
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_ExcludeResourceNames);
  p_m_ExcludeResourceNames = &this->m_ExcludeResourceNames;
  for ( i = 7; i >= 0; --i )
  {
    --p_m_ExcludeResourceNames;
    p_m_ExcludeResourceNames->m_Size = 0;
    if ( p_m_ExcludeResourceNames->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_ExcludeResourceNames->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ExcludeResourceNames->m_Memory.m_pMemory);
        p_m_ExcludeResourceNames->m_Memory.m_pMemory = nullptr;
      }
      p_m_ExcludeResourceNames->m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = p_m_ExcludeResourceNames->m_Memory.m_pMemory;
    p_m_ExcludeResourceNames->m_pElements = p_m_ExcludeResourceNames->m_Memory.m_pMemory;
    if ( p_m_ExcludeResourceNames->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        p_m_ExcludeResourceNames->m_Memory.m_pMemory = nullptr;
      }
      p_m_ExcludeResourceNames->m_Memory.m_nAllocationCount = 0;
    }
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_AdditionalResources);
  CUtlDict<FileJob_t *,int>::RemoveAll(this: &this->m_AnonymousJobs);
  CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>(this: &this->m_AnonymousJobs.m_Elements.m_Tree);
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short> > *)&this->m_SubmittedJobs);
  if ( this->m_SubmittedJobs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SubmittedJobs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SubmittedJobs.m_Memory.m_pMemory);
      this->m_SubmittedJobs.m_Memory.m_pMemory = nullptr;
    }
    this->m_SubmittedJobs.m_Memory.m_nAllocationCount = 0;
  }
  v4 = CTSListBase::Detach(this: &this->m_BatchedJobs);
  if ( v4 != nullptr )
  {
    do
    {
      Next = v4->Next;
      free(pMem: v4);
      v4 = Next;
    }
    while ( Next != nullptr );
  }
  CTSListBase::Detach(this: &this->m_BatchedJobs);
  v6 = CTSListBase::Detach(this: &this->m_PendingJobs);
  if ( v6 != nullptr )
  {
    do
    {
      v7 = v6->Next;
      free(pMem: v6);
      v6 = v7;
    }
    while ( v7 != nullptr );
  }
  CTSListBase::Detach(this: &this->m_PendingJobs);
  this->m_Filenames.m_FileStringPool.__vftable = (CCountedStringPoolBase<unsigned int>_vtbl *)&CCountedStringPoolBase<unsigned int>::`vftable';
  CCountedStringPoolBase<unsigned int>::FreeAll(this: &this->m_Filenames.m_FileStringPool);
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_Filenames.m_FileStringPool.m_Elements);
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_Filenames.m_FileStringPool.m_HashTable);
  this->m_Filenames.m_PathStringPool.__vftable = (CCountedStringPoolBase<unsigned short>_vtbl *)&CCountedStringPoolBase<unsigned short>::`vftable';
  CCountedStringPoolBase<unsigned short>::FreeAll(this: &this->m_Filenames.m_PathStringPool);
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_Filenames.m_PathStringPool.m_Elements);
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_Filenames.m_PathStringPool.m_HashTable);
}

//------------------------------------------------------------------------------
// Address: 0x1001F5E0
// Name: public: virtual bool CQueuedLoader::AddJob(struct LoaderJob_t const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CQueuedLoader::AddJob(CQueuedLoader *this, const LoaderJob_t *pLoaderJob)
{
  bool v3; // zf
  const char *m_pFilename; // ebx
  FileJob_t *v7; // eax
  FileJob_t *v8; // esi
  LoaderPriority_t m_Priority; // eax
  int v10; // ecx
  CQueuedLoader *v11; // ebx
  CThreadFastMutex *p_m_Mutex; // esi
  DWORD CurrentThreadId; // ecx
  TSLNodeBase_t *v14; // eax
  TSLNodeBase_t *v15; // eax
  int v16; // edx
  char szFixedName[260]; // [esp+4h] [ebp-21Ch] BYREF
  char szFullPath[260]; // [esp+108h] [ebp-118h] BYREF
  void *hFilename; // [esp+20Ch] [ebp-14h] BYREF
  unsigned int pathType; // [esp+210h] [ebp-10h] BYREF
  FileJob_t *pFileJob; // [esp+214h] [ebp-Ch] BYREF
  CQueuedLoader *v22; // [esp+218h] [ebp-8h]
  bool bFileIsFromBSP; // [esp+21Eh] [ebp-2h]
  bool bLateQueued; // [esp+21Fh] [ebp-1h]
  bool bExists_3; // [esp+22Bh] [ebp+Bh]

  v3 = !this->m_bActive;
  v22 = this;
  if ( v3 )
    return 0;
  v3 = !this->m_bCanBatch;
  bLateQueued = false;
  if ( !v3 && !this->m_bBatching )
  {
    DevWarning(a1: "QueuedLoader: Late Queued Job: %s\n", pLoaderJob->m_pFilename);
    bLateQueued = true;
  }
  if ( pLoaderJob->m_pCallback == nullptr && pLoaderJob->m_Priority == LOADERPRIORITY_ANYTIME )
  {
    DevWarning(a1: "QueuedLoader: Ignoring Anonymous Job: %s\n", pLoaderJob->m_pFilename);
    return 0;
  }
  hFilename = CUtlFilenameSymbolTable::FindFileName(this: &this->m_Filenames, pFileName: pLoaderJob->m_pFilename);
  if ( hFilename != nullptr
    && CUtlSortVector<void *,CQueuedLoader::CResourceNameLessFunc>::Find(
         this: &this->m_ExcludeResourceNames,
         src: &hFilename) != -1 )
  {
    return 0;
  }
  if ( V_IsAbsolutePath(pStr: pLoaderJob->m_pFilename) )
  {
    m_pFilename = pLoaderJob->m_pFilename;
    bFileIsFromBSP = V_stristr(pStr: (char *)pLoaderJob->m_pFilename, pSearch: ".bsp") != nullptr;
    bExists_3 = true;
  }
  else
  {
    g_pFullFileSystem->RelativePathToFullPath(
      this: g_pFullFileSystem,
      a2: pLoaderJob->m_pFilename,
      a3: pLoaderJob->m_pPathID,
      a4: szFullPath,
      a5: 260,
      a6: FILTER_NONE,
      a7: &pathType);
    bExists_3 = V_IsAbsolutePath(pStr: szFullPath);
    m_pFilename = szFullPath;
    bFileIsFromBSP = (pathType & 2) != 0;
  }
  v7 = (FileJob_t *)operator new(nSize: 0x40u);
  v8 = v7;
  if ( v7 != nullptr )
    _V_memset(dest: v7, fill: 0, count: 64);
  else
    v8 = nullptr;
  pFileJob = v8;
  v8->m_hFilename = CUtlFilenameSymbolTable::FindOrAddFileName(this: &v22->m_Filenames, pFileName: m_pFilename);
  *((_DWORD *)v8 + 15) ^= (*((_DWORD *)v8 + 15) ^ (4 * bExists_3)) & 4;
  v3 = !bFileIsFromBSP;
  v8->m_pCallback = pLoaderJob->m_pCallback;
  v8->m_pContext = pLoaderJob->m_pContext;
  v8->m_pContext2 = pLoaderJob->m_pContext2;
  v8->m_pTargetData = pLoaderJob->m_pTargetData;
  v8->m_nBytesToRead = pLoaderJob->m_nBytesToRead;
  v8->m_nStartOffset = pLoaderJob->m_nStartOffset;
  m_Priority = LOADERPRIORITY_DURINGPRELOAD;
  if ( v3 )
    m_Priority = pLoaderJob->m_Priority;
  v8->m_Priority = m_Priority;
  *((_DWORD *)v8 + 15) ^= (*((_DWORD *)v8 + 15) ^ (16 * bLateQueued)) & 0x10;
  v10 = *((_DWORD *)v8 + 15)
      ^ ((unsigned __int8)*((_DWORD *)v8 + 15)
       ^ (unsigned __int8)(32 * pLoaderJob->m_bAnonymousDecode))
      & 0x20;
  *((_DWORD *)v8 + 15) = v10;
  if ( pLoaderJob->m_pTargetData != nullptr )
    *((_DWORD *)v8 + 15) &= ~2u;
  else
    *((_DWORD *)v8 + 15) ^= ((unsigned __int8)v10 ^ (unsigned __int8)(2 * !pLoaderJob->m_bPersistTargetData)) & 2;
  v11 = v22;
  if ( pLoaderJob->m_pCallback == nullptr )
  {
    p_m_Mutex = &v22->m_Mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_Mutex->m_ownerID )
    {
      if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: p_m_Mutex, a2: CurrentThreadId, a3: 0);
        v11 = v22;
        goto LABEL_29;
      }
      v11 = v22;
    }
    ++p_m_Mutex->m_depth;
LABEL_29:
    V_strncpy(pDest: szFixedName, pSrc: pLoaderJob->m_pFilename, maxLen: 260);
    V_FixSlashes(pname: szFixedName, separator: 92);
    CUtlDict<FileJob_t *,int>::Insert(this: &v11->m_AnonymousJobs, pName: szFixedName, element: &pFileJob);
    v3 = p_m_Mutex->m_depth-- == 1;
    if ( v3 )
      _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
    v8 = pFileJob;
  }
  _InterlockedExchangeAdd(&g_nQueuedJobs.m_value, 1u);
  if ( v11->m_bBatching )
  {
    v14 = (TSLNodeBase_t *)operator new(nSize: 8u);
    if ( v14 != nullptr )
    {
      *((_DWORD *)&v14->Next + 1) = v8;
      CTSListBase::Push(this: &v11->m_BatchedJobs, pNode: v14);
    }
    else
    {
      CTSListBase::Push(this: &v11->m_BatchedJobs, pNode: nullptr);
    }
    return 1;
  }
  else
  {
    v15 = (TSLNodeBase_t *)operator new(nSize: 8u);
    if ( v15 != nullptr )
      *((_DWORD *)&v15->Next + 1) = v8;
    else
      v15 = nullptr;
    CTSListBase::Push(this: &v11->m_PendingJobs, pNode: v15);
    CQueuedLoader::SubmitPendingJobs(this: v11, a2: v16, p_m_hAsyncControl: (int)v11);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F8C0
// Name: public: virtual bool CQueuedLoader::ClaimAnonymousJob(char const __near *,void (*)(void __near *,void __near *,void const __near *,int,enum LoaderError_t),void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CQueuedLoader::ClaimAnonymousJob(
        CQueuedLoader *this,
        FileJob_t *pFilename,
        void (__cdecl *pCallback)(void *, void *, const void *, int, LoaderError_t),
        void *pContext,
        void *pContext2)
{
  int v6; // eax
  int v7; // ebx
  UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int> *m_pMemory; // ecx
  int v10; // edi
  bool v11; // zf
  CJob *v12; // eax
  char szFixedName[260]; // [esp+8h] [ebp-110h] BYREF
  CUtlMap<char const *,FileJob_t *,int>::Node_t search; // [esp+10Ch] [ebp-Ch] BYREF

  V_strncpy(pDest: szFixedName, pSrc: (const char *)pFilename, maxLen: 260);
  V_FixSlashes(pname: szFixedName, separator: 92);
  search.key = szFixedName;
  v6 = CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::Find(
         this: &this->m_AnonymousJobs.m_Elements.m_Tree,
         &search);
  v7 = v6;
  if ( v6 == -1 )
  {
    DevWarning(a1: "QueuedLoader: Anonymous Job '%s' not found\n", szFixedName);
    return 0;
  }
  else
  {
    m_pMemory = this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory;
    v10 = v6;
    v11 = (*((_BYTE *)m_pMemory[v6].m_Data.elem + 60) & 1) == 0;
    pFilename = m_pMemory[v6].m_Data.elem;
    if ( v11 )
    {
      return 0;
    }
    else
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.key);
      CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::Unlink(
        this: &this->m_AnonymousJobs.m_Elements.m_Tree,
        elem: v7);
      this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Left = v7;
      this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Right = this->m_AnonymousJobs.m_Elements.m_Tree.m_FirstFree;
      --this->m_AnonymousJobs.m_Elements.m_Tree.m_NumElements;
      this->m_AnonymousJobs.m_Elements.m_Tree.m_FirstFree = v7;
      v12 = IThreadPool::QueueCall<void,FileJob_t *,void (__cdecl *)(void *,void *,void const *,int,enum LoaderError_t),void *,void *,FileJob_t *,void (__cdecl *)(void *,void *,void const *,int,enum LoaderError_t),void *,void *>(
              this: _g_pThreadPool,
              pfnProxied: FinishAnonymousJob,
              arg1: &pFilename,
              arg2: (CFunctor_vtbl **)&pCallback,
              arg3: &pContext,
              arg4: (CFunctor_vtbl **)&pContext2);
      v12->Release(this: v12);
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F9E0
// Name: public: virtual bool CQueuedLoader::ClaimAnonymousJob(char const __near *,void __near * __near *,int __near *,enum LoaderError_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CQueuedLoader::ClaimAnonymousJob(
        CQueuedLoader *this,
        FileJob_t *pFilename,
        void **pData,
        int *pDataSize,
        LoaderError_t *pError)
{
  int v6; // eax
  int v7; // ebx
  int v9; // edi
  FileJob_t *elem; // ecx
  int v11; // eax
  int m_nActualBytesRead; // ecx
  char szFixedName[260]; // [esp+8h] [ebp-110h] BYREF
  CUtlMap<char const *,FileJob_t *,int>::Node_t search; // [esp+10Ch] [ebp-Ch] BYREF
  FileJob_t *pFileJob; // [esp+120h] [ebp+8h]

  V_strncpy(pDest: szFixedName, pSrc: (const char *)pFilename, maxLen: 260);
  V_FixSlashes(pname: szFixedName, separator: 92);
  search.key = szFixedName;
  v6 = CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::Find(
         this: &this->m_AnonymousJobs.m_Elements.m_Tree,
         &search);
  v7 = v6;
  if ( v6 == -1 )
  {
    DevWarning(a1: "QueuedLoader: Anonymous Job '%s' not found\n", szFixedName);
    return 0;
  }
  else
  {
    v9 = v6;
    elem = this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
    v11 = *((_DWORD *)elem + 15);
    pFileJob = this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
    if ( (v11 & 1) != 0 )
    {
      *((_DWORD *)elem + 15) = v11 | 8;
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Data.key);
      CUtlRBTree<CUtlMap<char const *,FileJob_t *,int>::Node_t,int,CUtlMap<char const *,FileJob_t *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileJob_t *,int>::Node_t,int>,int>>::Unlink(
        this: &this->m_AnonymousJobs.m_Elements.m_Tree,
        elem: v7);
      this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Left = v7;
      this->m_AnonymousJobs.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Right = this->m_AnonymousJobs.m_Elements.m_Tree.m_FirstFree;
      --this->m_AnonymousJobs.m_Elements.m_Tree.m_NumElements;
      this->m_AnonymousJobs.m_Elements.m_Tree.m_FirstFree = v7;
      *pData = pFileJob->m_pTargetData;
      if ( pFileJob->m_LoaderError != LOADERERROR_NONE )
        m_nActualBytesRead = 0;
      else
        m_nActualBytesRead = pFileJob->m_nActualBytesRead;
      *pDataSize = m_nActualBytesRead;
      if ( pError != nullptr )
        *pError = pFileJob->m_LoaderError;
      pFileJob->m_pTargetData = nullptr;
      _InterlockedExchangeAdd(&g_nAnonymousIOMemory.m_value, -pFileJob->m_nActualBytesRead);
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FB20
// Name: private: virtual bool CResourcePreloadAnonymous::CreateResource(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourcePreloadAnonymous::CreateResource(CResourcePreloadAnonymous *this, const char *pName)
{
  LoaderJob_t loaderJob; // [esp+0h] [ebp-28h] BYREF

  *(_DWORD *)&loaderJob.m_bPersistTargetData = 0;
  memset(&loaderJob.m_pCallback, 0, 24);
  loaderJob.m_pFilename = pName;
  loaderJob.m_pPathID = "GAME";
  loaderJob.m_Priority = LOADERPRIORITY_DURINGPRELOAD;
  CQueuedLoader::AddJob(this: &g_QueuedLoader, pLoaderJob: &loaderJob);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100442D0
// Name: _dynamic_initializer_for__loader_spew_info__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__loader_spew_info__()
{
  ConVar::ConVar(
    this: &loader_spew_info,
    pName: "loader_spew_info",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "0:Off, 1:Timing, 2:Completions, 3:Late Completions, 4:Creations/Purges, -1:All");
  return atexit(func: dynamic_atexit_destructor_for__loader_spew_info__);
}

//------------------------------------------------------------------------------
// Address: 0x10044300
// Name: _dynamic_initializer_for__loader_throttle_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__loader_throttle_io__()
{
  ConVar::ConVar(this: &loader_throttle_io, pName: "loader_throttle_io", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__loader_throttle_io__);
}

//------------------------------------------------------------------------------
// Address: 0x10044330
// Name: _dynamic_initializer_for__loader_defer_non_critical_jobs__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__loader_defer_non_critical_jobs__()
{
  ConVar::ConVar(
    this: &loader_defer_non_critical_jobs,
    pName: "loader_defer_non_critical_jobs",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__loader_defer_non_critical_jobs__);
}

//------------------------------------------------------------------------------
// Address: 0x10044360
// Name: _dynamic_initializer_for__loader_dump_table_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__loader_dump_table_command__()
{
  ConCommand::ConCommand(
    this: &loader_dump_table_command,
    pName: "loader_dump_table",
    callback: (void (__cdecl *)(const CCommand *))loader_dump_table,
    pHelpString: setName,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__loader_dump_table_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100447A0
// Name: _dynamic_atexit_destructor_for__loader_spew_info__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__loader_spew_info__()
{
  ConVar::~ConVar(this: &loader_spew_info);
}

//------------------------------------------------------------------------------
// Address: 0x100447B0
// Name: _dynamic_atexit_destructor_for__loader_throttle_io__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__loader_throttle_io__()
{
  ConVar::~ConVar(this: &loader_throttle_io);
}

//------------------------------------------------------------------------------
// Address: 0x100447C0
// Name: _dynamic_atexit_destructor_for__loader_defer_non_critical_jobs__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__loader_defer_non_critical_jobs__()
{
  ConVar::~ConVar(this: &loader_defer_non_critical_jobs);
}

//------------------------------------------------------------------------------
// Address: 0x100447D0
// Name: _dynamic_atexit_destructor_for__loader_dump_table_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__loader_dump_table_command__()
{
  ConCommand::~ConCommand(this: &loader_dump_table_command);
}

//------------------------------------------------------------------------------
// Address: 0x100447E0
// Name: _dynamic_atexit_destructor_for__g_DVDLayout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DVDLayout__()
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &g_DVDLayout);
}

//------------------------------------------------------------------------------
// Address: 0x100447F0
// Name: _dynamic_atexit_destructor_for__g_QueuedLoader__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QueuedLoader__()
{
  CQueuedLoader::~CQueuedLoader(this: &g_QueuedLoader);
}

//------------------------------------------------------------------------------
// Address: 0x10044800
// Name: _DataMapInit_ZIP_EndOfCentralDirRecord__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_EndOfCentralDirRecord__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x10044810
// Name: _DataMapInit_ZIP_FileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_FileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x10044820
// Name: _DataMapInit_ZIP_LocalFileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_LocalFileHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

//------------------------------------------------------------------------------
// Address: 0x10044830
// Name: _DataMapInit_ZIP_PreloadHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_PreloadHeader__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

//------------------------------------------------------------------------------
// Address: 0x10044840
// Name: _DataMapInit_ZIP_PreloadDirectoryEntry__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ZIP_PreloadDirectoryEntry__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x10044850
// Name: _dynamic_atexit_destructor_for__g_ZipUtils__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ZipUtils__()
{
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short> > *)&g_ZipUtils);
  if ( g_ZipUtils.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ZipUtils.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ZipUtils.m_Memory.m_pMemory);
      g_ZipUtils.m_Memory.m_pMemory = nullptr;
    }
    g_ZipUtils.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100448A0
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
    CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100448E0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x100448F0
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
  CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>::~CUtlVector<CZipPackFile::CPackFileEntry,CUtlMemory<CZipPackFile::CPackFileEntry,int>>(this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}
